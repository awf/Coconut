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

let AllocWithVar (size: Expr) (stgVar: Var) (funExpr: Expr): Expr = 
  MakeCall (<@@ corelang.vectorAllocCPS @@>)
    ([size; funExpr])
    ([funExpr.Type.GetGenericArguments() |> Array.rev |> fun x -> x.[0]])

let Alloc (size: Expr) (body: Var -> Expr): Expr = 
  let stgVar = newStgVar()
  let funExpr = Expr.Lambda(stgVar, body stgVar)
  AllocWithVar size stgVar funExpr

let GetS (stg: Var) (e0: Expr) (e1: Expr): Expr = 
  let t = e0.Type.GetElementType()
  let ce0t = cardTransformType e0.Type
  MakeCall(<@@ corelang.get_s @@>)([Expr.Var(stg); e0; e1; ZERO_SHAPE ce0t; ZERO_CARD])([t; ce0t])

let NewArrayS (stg: Var) (es: Expr list): Expr = 
  let t = 
    match es.[0].Type with
    | FunctionType(_, o) -> o
    | t -> failwithf "The type of arguments of NewArrayS should be a function, but is `%A` instead!" t
  MakeCall(<@@ corelang.newArray_s @@>)(Expr.Var(stg) :: [Expr.NewArray(es.[0].Type, es)])([t])

let rec transformStoraged (exp: Expr) (env: StorageEnv): Expr =
  let S = transformStoraged
  let CV = cardTransformVar
  let CT = cardTransformType
  let C = inferCardinality
  let rec ST (t: Type) = 
    match t with
    | _ when t = typeof<Index> || t = typeof<Cardinality> ||
        t = typeof<bool> || t = typeof<Number>              -> t
    | _ when t = typeof<Vector> || t = typeof<Matrix>       -> t
    | FunctionType(inputs, o)                               -> 
      let sinputs = inputs |> List.map ST
      let cinputs = inputs |> List.map CT
      FunctionType (typeof<Storage> :: sinputs @ cinputs) o                  
    | _ -> failwithf "Does not know how to convert the storaged type `%A`" t
  let SV (v: Var) = new Var(storagedName v.Name, ST v.Type)
  match exp with
  | AllAppN(e0, es)                  ->
    let ses = es |> List.map (fun x -> S x (newStgVar())) |> List.map (fun (StripedAlloc(a, e)) -> a, e)
    let sesParams = ses |> List.map snd
    let sesAllocs = ses |> List.choose fst
    let ces = es |> List.map C
    let body = AppN(S e0 O, Expr.Var(env) :: sesParams @ ces)
    (body, sesAllocs) ||> List.fold (fun acc (size, stgVar) -> AllocWithVar size stgVar (Expr.Lambda(stgVar, acc)))
  | LambdaN(xs, e)                   -> 
    let s2 = newStgVar()
    LambdaN(s2 :: (xs |> List.map SV) @ (xs |> List.map CV), S e s2)
  | Patterns.Var(v)                  -> Expr.Var(SV v)
  | Patterns.Let(x, e1, e2)          -> 
    let x_c = CV x
    Expr.Let(x_c, C e1,
      Alloc (Width (Expr.Var(x_c))) (fun s2 ->
        Expr.Let(SV x, S e1 s2, S e2 env)
      )
    )
  | Patterns.IfThenElse(e1, e2, e3)  -> Expr.IfThenElse(S e1 O, S e2 env, S e3 env)
  | Patterns.NewArray(tp, es)        -> 
    let ses = es |> List.map (fun x -> let s = newStgVar() in Expr.Lambda(s, S x s))
    NewArrayS env ses
  | ScalarOperation(name, args) ->
    let op = getMethodInfo exp
    Expr.Call(op, args |> List.map (fun x -> S x O))
  | DerivedPatterns.SpecificCall <@ corelang.vectorBuild @> (_, _, [e0; e1]) ->
    let se0 = S e0 O
    let se1 = S e1 O
    let ce0 = C e0
    let ce1 = C e1
    let s1 = Expr.Var(env)
    <@@ corelang.vectorBuild_s %%s1 %%se0 %%se1 %%ce0 %%ce1 @@>
  | ArrayLength(e0) ->
    Alloc (WidthCard e0) (fun s ->
      ArrayLength(S e0 s)
    )
  | ArrayGet(e0, e1) ->
    Alloc (WidthCard e0) (fun s2 ->
      GetS env (S e0 s2) (S e1 O)
    )
  | Patterns.Value(v, tp) when tp = typeof<Double> || tp = typeof<Index> || tp = typeof<Cardinality> ->
    exp
  | _ -> failwithf "Does not know how to transform into the storaged version for the expression `%A`" exp

