module cardinfer

open types
open cardinality
open transformer
open Microsoft.FSharp.Quotations
open System

let cardName (name: string): string = sprintf "%s_c" name

let ZERO_CARD = Expr.Value(Card 0, typeof<Cardinality>)

let rec inferCardinality (exp: Expr): Expr =
  let C = inferCardinality
  let rec CT (t: Type) = 
    match t with
    | _ when t = typeof<Index> || t = typeof<Cardinality> ||
        t = typeof<bool> || t = typeof<Number>              -> typeof<Cardinality>
    | _ when t = typeof<Vector> || t = typeof<Matrix>       -> typeof<Shape>
    | _ when t.Name = typeof<_ -> _>.Name                   -> t.GetGenericTypeDefinition().MakeGenericType(t.GetGenericArguments() |> Array.map CT)                  
    | _ -> failwithf "Does not know how to convert the cardinality type `%A`" t
  let CV (v: Var) = new Var(cardName v.Name, CT v.Type)
  match exp with
  | _ when exp.Type = typeof<Number> -> ZERO_CARD
  | AppN(e0, es)                     -> AppN(C e0, es |> List.map C)
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
    <@@ shapeCard %%ce0 @@>
  | ArrayGet(e0, e1) ->
    let ce0 = C e0
    if exp.Type = typeof<Number> then
      <@@ flatShapeCard (shapeElem %%ce0) @@>
    else
      <@@ shapeElem %%ce0 @@>
  | _ -> failwithf "Does not know how to compute cardinality for the expression `%A`" exp


let WidthCard (exp: Expr): Expr = 
  let t = exp.Type
  if (t = typeof<Number> || t = typeof<Index> || t = typeof<bool>) then
    ZERO_CARD
  else
    let cardExp = inferCardinality exp
    if (t = typeof<Cardinality>) then
      <@@ width (flatShape %%cardExp) @@>
    else
      <@@ width %%cardExp @@>