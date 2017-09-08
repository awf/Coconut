module cardinfer

open types
open cardinality
open transformer
open Microsoft.FSharp.Quotations
open System

let cardName (name: string): string = sprintf "%s_shp" name

let ZERO_CARD = Expr.Value(Card 0, typeof<Cardinality>)
let rec ZERO_SHAPE (shapeType: Type) = 
  if shapeType = typeof<Cardinality> then 
    ZERO_CARD
  // TODO rewrite using MakeCall
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
    | _ when isScalarType t || t = typeof<Cardinality>      -> typeof<Cardinality>
    | _ when t = typeof<Vector>                             -> typeof<VectorShape>
    | _ when t = typeof<Matrix>                             -> typeof<MatrixShape>
    | _ when t = typeof<Matrix3D>                           -> typeof<Matrix3DShape>
    | Tuple2Type(tp1, tp2)                                  -> 
      Tuple2Type (cardTransformType tp1) (cardTransformType tp2)
    | FunctionType(inputs, output)                          -> 
      FunctionType (inputs |> List.map cardTransformType) (cardTransformType output)
    | _ -> failwithf "Does not know how to convert the cardinality type `%A`" t

let cardTransformVar (v: Var): Var = new Var(cardName v.Name, cardTransformType v.Type)

type CardEnv = Map<Var, Var>

let simplifyCardinality (exp: Expr): Expr =
  let recTrans rs = optimizer.recursiveTransformer rs |> optimizer.fixPoint 10
  exp |> recTrans [ruleengine.compilePatternToRule <@ rules.letInliner @>; rules.betaReduction; rules.constantFold]

let rec inferCardinality (exp: Expr) (env: CardEnv): Expr =
  let C e = inferCardinality e env
  let CEnv = inferCardinality
  let CT = cardTransformType
  let CVNew = cardTransformVar
  let CV v = 
    match env.TryFind(v) with 
    | Some v2 -> v2
    | _            -> 
      match v with
      | MethodVariable(mdl, mtd) -> CVNew v
      | _            -> failwithf "There is no cardinality variable associated with `%A`" v
  match exp with
  | _ when isScalarType exp.Type     -> ZERO_CARD
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
    let N = Expr.Value(Card es.Length, typeof<Cardinality>)
    if tp = typeof<Number> then
      N
    else 
      let ce1 = C es.[0]
      MakeCall <@@ nestedShape @@> ([ce1; N]) ([CT tp])
  | Patterns.NewTuple([e0; e1]) ->
    // TODO
    Expr.NewTuple([C e0; C e1])
  | DerivedPatterns.SpecificCall <@ fst @> (_, tps, [e]) ->
    // TODO
    MakeCall <@ fst @> [C e] (tps |> List.map CT)
  | DerivedPatterns.SpecificCall <@ snd @> (_, tps, [e]) ->
    // TODO
    MakeCall <@ snd @> [C e] (tps |> List.map CT)
  | DerivedPatterns.SpecificCall <@ corelang.build @> (_, [t], [e0; e1]) ->
    let ce0 = C e0
    let ce1 = C e1
    if t = typeof<Number> then
      ce0
    else
      MakeCall <@ nestedShape @> [Expr.Application(ce1, ZERO_CARD); ce0] [CT t]
  | DerivedPatterns.SpecificCall <@ corelang.foldOnRange @> (_, [ta], [f; z; st; en]) ->
    // TODO maybe needs some check to make sure that the program is sound w.r.t. cardinality
    C z
  | ArrayLength(e0) ->
    let ce0 = C e0
    if ce0.Type = typeof<VectorShape> then
      ce0
    else
      MakeCall(<@@ shapeCard @@>)([ce0])([ce0.Type.GenericTypeArguments.[0]])
  | ArrayGet(e0, e1) ->
    let ce0 = C e0
    if ce0.Type = typeof<VectorShape> then
      ZERO_CARD
    else 
      MakeCall <@ shapeElem @> [ce0] [CT exp.Type]
  | DerivedPatterns.SpecificCall <@ corelang.matrixRead @> (_, _, [name; start; rows; cols]) ->
    let cols_c = C cols
    let rows_c = C rows
    <@@ nestedShape<VectorShape> (%%cols_c) (%%rows_c) @@>
  | Patterns.Value(v, tp) when tp = typeof<Cardinality> -> exp
  | Patterns.NewTuple([e0; e1]) ->
    Expr.NewTuple([C e0; C e1])
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
  | Patterns.Sequential(e1, e2) ->
    C e2
  | _ -> failwithf "Does not know how to compute cardinality for the expression `%A`" exp

let Width (cardExp: Expr): Expr =
  (*if (cardExp.Type = typeof<Cardinality>) then
    cardExp
  el*)
  if (cardExp.Type.Name = typeof<_ -> _>.Name) then
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
    