﻿module cardinfer

open types
open cardinality
open transformer
open Microsoft.FSharp.Quotations
open System

let cardName (name: string): string = sprintf "%s_c" name

let ZERO_CARD = Expr.Value(Card 0, typeof<Cardinality>)
let ZERO_SHAPE (shapeType: Type) = 
  if shapeType = typeof<Cardinality> then 
    ZERO_CARD
  elif shapeType = typeof<VectorShape> then
    <@@ vectorShape<Cardinality> %%ZERO_CARD %%ZERO_CARD @@>
  else
    failwithf "Doesn't know how to create ZERO_SHAPE for the shape type `%A`" shapeType

let rec cardTransformType (t: Type) = 
    match t with
    | _ when t = typeof<Index> || t = typeof<Cardinality> ||
        t = typeof<bool> || t = typeof<Number>              -> typeof<Cardinality>
    | _ when t = typeof<Vector>                             -> typeof<VectorShape>
    | _ when t = typeof<Matrix>                             -> typeof<MatrixShape>
    | FunctionType(inputs, output)                          -> 
      FunctionType (inputs |> List.map cardTransformType) (cardTransformType output)
    | _ -> failwithf "Does not know how to convert the cardinality type `%A`" t

let cardTransformVar (v: Var): Var = new Var(cardName v.Name, cardTransformType v.Type)

let rec inferCardinality (exp: Expr): Expr =
  let C = inferCardinality
  let CT = cardTransformType
  let CV = cardTransformVar
  match exp with
  | _ when exp.Type = typeof<Number> -> ZERO_CARD
  | _ when exp.Type = typeof<Index>  -> ZERO_CARD
  | _ when exp.Type = typeof<bool>   -> ZERO_CARD
  | AllAppN(e0, es)                  -> AppN(C e0, es |> List.map C)
  | LambdaN(xs, e)                   -> LambdaN(xs |> List.map CV, C e)
  | Patterns.Var(v)                  -> Expr.Var(CV v)
  | Patterns.Let(x, e1, e2)          -> Expr.Let(CV x, C e1, C e2)
  | Patterns.IfThenElse(e1, e2, e3)  -> C e2
  | Patterns.NewArray(tp, es)        -> 
    let ce1 = C es.[0]
    let N = Expr.Value(Card es.Length, typeof<Cardinality>)
    <@@ vectorShape (flatShape (%%ce1: Cardinality)) (%%N: Cardinality) @@>
  | DerivedPatterns.SpecificCall <@ corelang.vectorBuild @> (_, _, [e0; e1]) ->
    let ce0 = C e0
    let ce1 = C e1
    <@@ vectorShape (flatShape ((%%ce1: Cardinality -> Cardinality) %%ZERO_CARD)) (%%ce0: Cardinality) @@>
  | ArrayLength(e0) ->
    let ce0 = C e0
    MakeCall(<@@ shapeCard @@>)([ce0])([ce0.Type.GenericTypeArguments.[0]])
  | ArrayGet(e0, e1) ->
    let ce0 = C e0
    if exp.Type = typeof<Number> then
      <@@ flatShapeCard (shapeElem %%ce0) @@>
    else
      <@@ shapeElem %%ce0 @@>
  | Patterns.Value(v, tp) when tp = typeof<Cardinality> -> exp
  | _ -> failwithf "Does not know how to compute cardinality for the expression `%A`" exp

let Width (cardExp: Expr): Expr =
  if (cardExp.Type = typeof<Cardinality>) then
    cardExp
  elif (cardExp.Type.Name = typeof<_ -> _>.Name) then
    ZERO_CARD
  else
    MakeCall(<@@ width @@>)([cardExp])([cardExp.Type])

let WidthCard (exp: Expr): Expr = 
  let t = exp.Type
  if (t = typeof<Number> || t = typeof<Index> || t = typeof<bool>) then
    ZERO_CARD
  else
    let cardExp = inferCardinality exp
    Width cardExp
    