module storagedtransformer

open types
open cardinality
open transformer
open Microsoft.FSharp.Quotations
open System
open cardinfer

let storagedName (name: string): string = sprintf "%s_s" name

type StorageOutput = Var

let EMPTY_STORAGE: StorageOutput = Var.Global("empty_storage", typeof<Storage>)
let O: StorageOutput = EMPTY_STORAGE

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

let rec simplifyStoraged (exp: Expr): Expr =
  match exp with
  | DerivedPatterns.SpecificCall <@ corelang.vectorAllocCPS @> (_, [t], [width; Patterns.Lambda(st, body)]) ->
    if width = ZERO_CARD || not (body.GetFreeVars() |> Seq.exists(fun v -> v = st)) then
      body.Substitute(fun v -> if st = v then Some(Expr.Var(EMPTY_STORAGE)) else None)
    else 
      MakeCall <@@ corelang.vectorAllocCPS @@> [width; Expr.Lambda(st, simplifyStoraged body)] [t]
  | ExprShape.ShapeLambda(x, body)       -> Expr.Lambda(x, simplifyStoraged body)
  | ExprShape.ShapeVar(x)                -> Expr.Var(x)
  | ExprShape.ShapeCombination(op, args) -> ExprShape.RebuildShapeCombination(op, args |> List.map simplifyStoraged)

let rec transformStoraged (exp: Expr) (outputStorage: StorageOutput) (env: Map<Var, Var * Var>): Expr =
  let S e s = transformStoraged e s env
  let SEnv = transformStoraged
  let CVNew = cardTransformVar
  let CV v = 
    match env.TryFind(v) with 
    | Some(vs, vc) -> vc
    | _            -> 
      match v with
      | MethodVariable(mdl, mtd) -> CVNew v
      | _            -> failwithf "There is no cardinality variable associated with `%A`" v
  let CT = cardTransformType
  let cardEnv = (env |> Map.map (fun k (v1, v2) -> v2))
  let C e = inferCardinality e cardEnv
  let CEnv = inferCardinality
  let rec ST (t: Type) = 
    match t with
    | _ when t = typeof<Index> || t = typeof<Cardinality> ||
        t = typeof<bool> || t = typeof<Number> || 
        t = typeof<string>                                  -> t
    | _ when t = typeof<Vector> || t = typeof<Matrix> || 
        t = typeof<Matrix3D>                                -> t
    | FunctionType(inputs, o)                               -> 
      let sinputs = inputs |> List.map ST
      let cinputs = inputs |> List.map CT
      FunctionType (typeof<Storage> :: sinputs @ cinputs) o                  
    | _ -> failwithf "Does not know how to convert the storaged type `%A`" t
  let SVNew (v: Var) = new Var(storagedName v.Name, ST v.Type)
  let SV v = 
    match env.TryFind(v) with 
    | Some(vs, vc) -> vs
    | _            -> 
      match v with
      | MethodVariable(mdl, mtd) -> SVNew v
      | _ -> failwithf "There is no storage variable associated with `%A`" v
  match exp with
  | AllAppN(e0, es)                  ->
    let ses = es |> List.map (fun x -> S x (newStgVar())) |> List.map (fun (StripedAlloc(a, e)) -> a, e)
    let sesParams = ses |> List.map snd
    let sesAllocs = ses |> List.choose fst
    let ces = es |> List.map C
    let body = AppN(S e0 O, Expr.Var(outputStorage) :: sesParams @ ces)
    (body, sesAllocs) ||> List.fold (fun acc (size, stgVar) -> AllocWithVar size stgVar (Expr.Lambda(stgVar, acc)))
  | LambdaN(xs, e)                   -> 
    let s2 = newStgVar()
    let sxs = xs |> List.map SVNew
    let cxs = xs |> List.map CVNew
    let nenv = (env, (xs, sxs, cxs) |||> List.zip3) ||> List.fold (fun acc (v1, vs, vc) -> acc.Add(v1, (vs, vc)))
    LambdaN(s2 :: sxs @ cxs, SEnv e s2 nenv)
  | Patterns.Var(v)                  -> Expr.Var(SV v)
  | Patterns.Let(x, e1, e2)          -> 
    let x_c = CVNew x
    Expr.Let(x_c, C e1,
      Alloc (Width (Expr.Var(x_c))) (fun s2 ->
        let x_s = SVNew x
        Expr.Let(x_s, S e1 s2, SEnv e2 outputStorage (env.Add(x, (x_s, x_c))))
      )
    )
  | Patterns.IfThenElse(e1, e2, e3)  -> Expr.IfThenElse(S e1 O, S e2 outputStorage, S e3 outputStorage)
  | Patterns.NewArray(tp, es)        -> 
    let ses = es |> List.map (fun x -> let s = newStgVar() in Expr.Lambda(s, S x s))
    NewArrayS outputStorage ses
  | ScalarOperation(name, args, _) ->
    let op = getMethodInfo exp
    Expr.Call(op, args |> List.map (fun x -> S x O))
  | DerivedPatterns.SpecificCall <@ corelang.build @> (_, [t], [e0; e1]) ->
    let se0 = S e0 O
    let se1 = S e1 O
    let ce0 = C e0
    let ce1 = C e1
    let s1 = Expr.Var(outputStorage)
    let tc = CT t
    MakeCall <@ corelang.build_s @> [s1; se0; se1; ce0; ce1] [t; tc] 
  | DerivedPatterns.SpecificCall <@ corelang.fold @> (_, [ta; tb], [f; z; r]) ->
    let sf = S f O
    let sz = S z O
    let sr = S r O
    let cf = C f
    let cz = C z
    let cr = C r
    let s1 = Expr.Var(outputStorage)
    let tac = CT ta
    let tbc = CT tb
    MakeCall <@ corelang.fold_s @> [s1; sf; sz; sr; cf; cz; cr] [ta; tb; tac; tbc]
  | ArrayLength(e0) ->
    Alloc (WidthCard e0 cardEnv) (fun s ->
      ArrayLength(S e0 s)
    )
  | ArrayGet(e0, e1) ->
    Alloc (WidthCard e0 cardEnv) (fun s2 ->
      GetS outputStorage (S e0 s2) (S e1 O)
    )
  | DerivedPatterns.SpecificCall <@ corelang.matrixRead @> (_, _, [name; start; rows]) ->
    // TODO requires number of column information in the matrixRead construct
    let s = Expr.Var(outputStorage)
    <@@ corelang.matrixRead_s %%s %%name %%start %%rows @@>
  | Patterns.Value(v, tp) when tp = typeof<Double> || tp = typeof<Index> || tp = typeof<Cardinality> ->
    exp
  | CardConstructor c ->
    exp
  | _ -> failwithf "Does not know how to transform into the storaged version for the expression `%A`" exp

