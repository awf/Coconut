module storagedtransformer

open types
open cardinality
open transformer
open Microsoft.FSharp.Quotations
open System
open cardinfer

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
  Helpers.MakeCall(<@@ corelang.vectorAllocCPS @@>)([size; funExpr])([funExpr.Type.GetGenericArguments() |> Array.rev |> fun x -> x.[0]])

let GetS (stg: Var) (e0: Expr) (e1: Expr): Expr = 
  let t = e0.Type.GetElementType()
  Helpers.MakeCall(<@@ corelang.get_s @@>)([Expr.Var(stg); e0; e1])([t])

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
  | Patterns.Let(x, e1, e2)          -> 
    Alloc (WidthCard e1) (fun s2 ->
      Expr.Let(SV x, S e1 s2, S e2 env))
  | Patterns.IfThenElse(e1, e2, e3)  -> Expr.IfThenElse(S e1 O, S e2 env, S e3 env)
  //| Patterns.NewArray(tp, es)        -> 
  //  let ce1 = C es.[0]
  //  let N = Expr.Value(Card es.Length, typeof<Cardinality>)
  //  <@@ vectorShape (flatShape (%%ce1: Cardinality)) (%%N: Cardinality) @@>
  | DerivedPatterns.SpecificCall <@ corelang.vectorBuild @> (_, _, [e0; e1]) ->
    let ce0 = S e0 O
    let ce1 = S e1 O
    let s1 = Expr.Var(env)
    <@@ corelang.vectorBuild_s %%s1 %%ce0 %%ce1 @@>
  | ArrayLength(e0) ->
    Alloc (WidthCard e0) (fun s ->
      ArrayLength(S e0 s)
    )
  | ArrayGet(e0, e1) ->
    Alloc (WidthCard e0) (fun s2 ->
      GetS s2 (S e0 s2) (S e1 O)
    )
  | _ -> failwithf "Does not know how to transform into the storaged version for the expression `%A`" exp

