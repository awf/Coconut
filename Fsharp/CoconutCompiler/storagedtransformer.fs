module storagedtransformer

open types
open cardinality
open transformer
open Microsoft.FSharp.Quotations
open System

let storagedName (name: string): string = sprintf "%s_s" name

type StorageEnv = Var

let EMPTY_STORAGE: StorageEnv = Var.Global("empty_storage", typeof<Storage>)
let O: StorageEnv = EMPTY_STORAGE

let (|Alloc|_|) (e: Expr): (Expr * Var * Expr) option = 
  match e with
  | DerivedPatterns.SpecificCall <@ corelang.vectorAllocCPS @> (_, _, [size; Patterns.Lambda(stgVar, body)]) ->
    Some(size, stgVar, body)
  | _ -> None

let (|StripedAlloc|) (e: Expr): (Expr * Var) option * Expr = 
  match e with
  | Alloc (size, stgVar, body) -> Some(size, stgVar), body
  | _                          -> None, e

let newStgVar (): Var = new Var(utils.newVar "stgVar", typeof<Storage>)

let Alloc (size: Expr) (body: Var -> Expr): Expr = 
  let stgVar = newStgVar()
  let funExpr = Expr.Lambda(stgVar, body stgVar)
  <@@ corelang.vectorAllocCPS %%size %%funExpr @@>

let WidthCard (exp: Expr): Expr = 
  let cardExp = cardinfer.inferCardinality exp
  <@@ width %%cardExp @@>

let rec transformStoraged (exp: Expr) (env: StorageEnv): Expr =
  let S = transformStoraged
  let rec ST (t: Type) = 
    match t with
    | _ when t = typeof<Index> || t = typeof<Cardinality> ||
        t = typeof<bool> || t = typeof<Number>              -> t
    | _ when t = typeof<Vector> || t = typeof<Matrix>       -> t
    | _ when t.Name = typeof<_ -> _>.Name                   -> 
      let funType = typeof<_ -> _>
      funType.GetGenericTypeDefinition().MakeGenericType(typeof<Storage>, t)                  
    | _ -> failwithf "Does not know how to convert the storaged type `%A`" t
  let SV (v: Var) = new Var(storagedName v.Name, ST v.Type)
  match exp with
  | AppN(e0, es)                     -> // assumes es don't need allocation
    Alloc (WidthCard exp) (fun s2 ->
      AppN(S e0 O, Expr.Var(s2) :: (es |> List.map (fun x -> S x O))))
  | LambdaN(xs, e)                   -> 
    let s2 = newStgVar()
    LambdaN(s2 :: (xs |> List.map SV), S e s2)
  | Patterns.Var(v)                  -> Expr.Var(SV v)
  //| Patterns.Let(x, e1, e2)          -> Expr.Let(CV x, C e1, C e2)
  //| Patterns.IfThenElse(e1, e2, e3)  -> C e2
  //| Patterns.NewArray(tp, es)        -> 
  //  let ce1 = C es.[0]
  //  let N = Expr.Value(Card es.Length, typeof<Cardinality>)
  //  <@@ vectorShape (flatShape (%%ce1: Cardinality)) (%%N: Cardinality) @@>
  //| DerivedPatterns.SpecificCall <@ corelang.vectorBuild @> (_, _, [e0; e1]) ->
  //  let ce0 = C e0
  //  let ce1 = C e1
  //  <@@ vectorShape (flatShape ((%%ce1: Cardinality -> Cardinality) %%ZERO_CARD)) (%%ce0: Cardinality) @@>
  //| ArrayLength(e0) ->
  //  let ce0 = C e0
  //  <@@ shapeCard %%ce0 @@>
  //| ArrayGet(e0, e1) ->
  //  let ce0 = C e0
  //  if exp.Type = typeof<Number> then
  //    <@@ flatShapeCard (shapeElem %%ce0) @@>
  //  else
  //    <@@ shapeElem %%ce0 @@>
  | _ -> failwithf "Does not know how to transform into the storaged version for the expression `%A`" exp

