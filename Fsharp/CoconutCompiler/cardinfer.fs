﻿module cardinfer

open types
open cardinality
open transformer
open Microsoft.FSharp.Quotations
open System

let cardName (name: string): string = sprintf "%s_c" name

let ZERO_CARD = Expr.Value(Card 0, typeof<Cardinality>)
let rec ZERO_SHAPE (shapeType: Type) = 
  if shapeType = typeof<Cardinality> then 
    ZERO_CARD
  elif shapeType = typeof<VectorShape> then
    <@@ nestedShape<Cardinality> %%ZERO_CARD %%ZERO_CARD @@>
  elif shapeType = typeof<MatrixShape> then
    let elem = ZERO_SHAPE (typeof<VectorShape>)
    <@@ nestedShape<VectorShape> (%%elem) %%ZERO_CARD @@>
  elif shapeType = typeof<Matrix3DShape> then
    let elem = ZERO_SHAPE (typeof<MatrixShape>)
    <@@ nestedShape<MatrixShape> (%%elem) %%ZERO_CARD @@>
  else
    failwithf "Doesn't know how to create ZERO_SHAPE for the shape type `%A`" shapeType

let rec cardTransformType (t: Type) = 
    match t with
    | _ when t = typeof<Index> || t = typeof<Cardinality> ||
        t = typeof<bool> || t = typeof<Number>              -> typeof<Cardinality>
    | _ when t = typeof<Vector>                             -> typeof<VectorShape>
    | _ when t = typeof<Matrix>                             -> typeof<MatrixShape>
    | _ when t = typeof<Matrix3D>                           -> typeof<Matrix3DShape>
    | FunctionType(inputs, output)                          -> 
      FunctionType (inputs |> List.map cardTransformType) (cardTransformType output)
    | _ -> failwithf "Does not know how to convert the cardinality type `%A`" t

let cardTransformVar (v: Var): Var = new Var(cardName v.Name, cardTransformType v.Type)

type CardEnv = Map<Var, Var>

let rec inferCardinality (exp: Expr) (env: CardEnv): Expr =
  let C e = inferCardinality e env
  let CEnv = inferCardinality
  let CT = cardTransformType
  let CVNew = cardTransformVar
  let CV v = 
    match env.TryFind(v) with
    | Some v2 -> v2
    | None    -> failwithf "The environment does not contain mapping for `%A`" v
  match exp with
  | _ when exp.Type = typeof<Number> -> ZERO_CARD
  | _ when exp.Type = typeof<Index>  -> ZERO_CARD
  | _ when exp.Type = typeof<bool>   -> ZERO_CARD
  | AllAppN(e0, es)                  -> AppN(C e0, es |> List.map C)
  | LambdaN(xs, e)                   -> 
    let nxs = xs |> List.map CVNew
    let nenv = (env, (xs, nxs) ||> List.zip) ||> List.fold (fun acc (v1, v2) -> acc.Add(v1, v2))
    LambdaN(nxs, CEnv e nenv)
  | Patterns.Var(v)                  -> Expr.Var(CV v)
  | Patterns.Let(x, e1, e2)          -> 
    let nx = CVNew x
    Expr.Let(nx, C e1, CEnv e2 (env.Add(x, nx)))
  | Patterns.IfThenElse(e1, e2, e3)  -> C e2
  | Patterns.NewArray(tp, es)        -> 
    let ce1 = C es.[0]
    let N = Expr.Value(Card es.Length, typeof<Cardinality>)
    <@@ nestedShape (%%ce1: Cardinality) (%%N: Cardinality) @@>
  | DerivedPatterns.SpecificCall <@ corelang.build @> (_, [t], [e0; e1]) ->
    let ce0 = C e0
    let ce1 = C e1
    match t with
    | t when t = typeof<Number> -> 
      <@@ nestedShape<Cardinality> ((%%ce1: Cardinality -> Cardinality) %%ZERO_CARD) (%%ce0: Cardinality) @@>
    | t when t = typeof<Vector> ->
      <@@ nestedShape<VectorShape> ((%%ce1: Cardinality -> VectorShape) %%ZERO_CARD) (%%ce0: Cardinality) @@>
    | t when t = typeof<Matrix> ->
      <@@ nestedShape<MatrixShape> ((%%ce1: Cardinality -> MatrixShape) %%ZERO_CARD) (%%ce0: Cardinality) @@>
    | _ ->
      failwithf "Does not know how to infer cardinality for type `%A`" t
  | ArrayLength(e0) ->
    let ce0 = C e0
    MakeCall(<@@ shapeCard @@>)([ce0])([ce0.Type.GenericTypeArguments.[0]])
  | ArrayGet(e0, e1) ->
    let ce0 = C e0
    match exp.Type with
    | t when t = typeof<Number> -> <@@ shapeElem<Cardinality> %%ce0 @@>
    | t when t = typeof<Vector> -> <@@ shapeElem<VectorShape> %%ce0 @@>
    | t when t = typeof<Matrix> -> <@@ shapeElem<MatrixShape> %%ce0 @@>
    | t                         -> failwithf "Does not know how to infer cardinality for array get of type `%A`" t
  | Patterns.Value(v, tp) when tp = typeof<Cardinality> -> exp
  | DerivedPatterns.SpecificCall <@ (.+) @> (_, _, [e0; e1]) ->
    let ce0 = Expr.Cast<Cardinality>(C e0)
    let ce1 = Expr.Cast<Cardinality>(C e1)
    <@ %ce0 .+ %ce1 @>.Raw
  | DerivedPatterns.SpecificCall <@ (.-) @> (_, _, [e0; e1]) ->
    let ce0 = Expr.Cast<Cardinality>(C e0)
    let ce1 = Expr.Cast<Cardinality>(C e1)
    <@ %ce0 .- %ce1 @>.Raw
  | CardConstructor c ->
    exp
  | _ -> failwithf "Does not know how to compute cardinality for the expression `%A`" exp

let Width (cardExp: Expr): Expr =
  if (cardExp.Type = typeof<Cardinality>) then
    cardExp
  elif (cardExp.Type.Name = typeof<_ -> _>.Name) then
    ZERO_CARD
  else
    MakeCall(<@@ width @@>)([cardExp])([cardExp.Type])

let WidthCard (exp: Expr) (env: CardEnv): Expr = 
  let t = exp.Type
  if (t = typeof<Number> || t = typeof<Index> || t = typeof<bool>) then
    ZERO_CARD
  else
    let cardExp = inferCardinality exp env
    Width cardExp
    