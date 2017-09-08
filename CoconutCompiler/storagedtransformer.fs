module storagedtransformer

open types
open cardinality
open transformer
open Microsoft.FSharp.Quotations
open System
open cardinfer

let storagedName (name: string): string = sprintf "%s_dps" name

type StorageOutput = Var

let O: StorageOutput = EMPTY_STORAGE

let (|Alloc|_|) (e: Expr): (Expr * Var * Expr) option = 
  match e with
  | DerivedPatterns.SpecificCall <@ corelang.alloc @> (_, _, [size; Patterns.Lambda(stgVar, body)]) ->
    Some(size, stgVar, body)
  | _ -> None

let (|StripedAlloc|) (e: Expr): (Expr * Var) option * Expr = 
  match e with
  | Alloc (size, stgVar, body) -> Some(size, stgVar), body
  | _                          -> None, e

let newStgVar (): Var = new Var(utils.newVar "stgVar", typeof<Storage>)

let AllocWithVar (size: Expr) (stgVar: Var) (funExpr: Expr): Expr = 
  MakeCall (<@@ corelang.alloc @@>)
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
  | DerivedPatterns.SpecificCall <@ corelang.alloc @> (_, [t], [width; Patterns.Lambda(st, body)]) ->
    if width = ZERO_CARD || not (body.GetFreeVars() |> Seq.exists(fun v -> v = st)) then
      simplifyStoraged (body.Substitute(fun v -> if st = v then Some(Expr.Var(EMPTY_STORAGE)) else None))
    else 
      MakeCall <@@ corelang.alloc @@> [width; Expr.Lambda(st, simplifyStoraged body)] [t]
  | ExprShape.ShapeLambda(x, body)       -> Expr.Lambda(x, simplifyStoraged body)
  | ExprShape.ShapeVar(x)                -> Expr.Var(x)
  | ExprShape.ShapeCombination(op, args) -> ExprShape.RebuildShapeCombination(op, args |> List.map simplifyStoraged)

let rec getAliasSimplify (exp: Expr): Expr = 
  match exp with
  | DerivedPatterns.SpecificCall <@ corelang.get_s @> (_, [a; s], args) ->
    let tl = args |> List.tail |> List.map getAliasSimplify
    MakeCall <@@ corelang.get_s @@> (Expr.Var(EMPTY_STORAGE) :: tl) [a; s]
  | ExprShape.ShapeLambda(x, body)       -> Expr.Lambda(x, getAliasSimplify body)
  | ExprShape.ShapeVar(x)                -> Expr.Var(x)
  | ExprShape.ShapeCombination(op, args) -> ExprShape.RebuildShapeCombination(op, args |> List.map getAliasSimplify)

let AllocNWithVar (bindings: (Var * Expr) list, funExpr: Expr): Expr = 
  (funExpr, bindings |> List.rev) ||> List.fold (fun acc (v, s) -> AllocWithVar s v (Expr.Lambda(v, acc)))

(* Lifts memory allocations to top-level statements *)
let allocLifting (e: Expr): Expr = 
  let rec constructTopLevelAllocs (boundVars: Var List) (exp: Expr): Expr * (Var * Expr) List = 
    let isSafeToLift (exp: Expr): bool = 
      let freeVars = getFreeVariables exp
      let freeNotBoundVars = utils.listDiff freeVars boundVars
      List.isEmpty freeNotBoundVars
    match exp with 
    //| Patterns.Let(x, e1, e2) ->
    //  let (te1, liftedLets1) = constructTopLevelAllocs boundVars e1
    //  let canBeLifted = isSafeToLift e1
    //  let newBoundVars = if(canBeLifted) then (x :: boundVars) else boundVars
    //  let (te2, liftedLets2) = constructTopLevelAllocs newBoundVars e2
    //  if (canBeLifted) then
    //    (te2, List.append liftedLets1 ((x, te1) :: liftedLets2))
    //  else 
    //    (Expr.Let(x, te1, te2), List.append liftedLets1 liftedLets2)
    | DerivedPatterns.SpecificCall <@ corelang.alloc @> (_, t, [sz; Patterns.Lambda(st, body)]) ->
      let canBeLifted = isSafeToLift sz
      let (tbody, liftedAllocs) = constructTopLevelAllocs (st :: boundVars) body
      if canBeLifted then
        (tbody, liftedAllocs @ [st, sz])
      else
        (AllocWithVar sz st (Expr.Lambda(st, tbody)), liftedAllocs)
    | LambdaN (inputs, body) ->
      let (te, ll) = constructTopLevelAllocs (inputs @ boundVars) body
      (LambdaN(inputs, AllocNWithVar(ll, te)), [])
    | ExprShape.ShapeCombination(o, exprs) ->
      let (tes, lls) = List.unzip (List.map (constructTopLevelAllocs boundVars) exprs)
      (ExprShape.RebuildShapeCombination(o, tes), List.concat lls)
    | _ -> (exp, [])
  let (inputs, body) = match e with TopLevelFunction (i, b) -> (i, b)
  let (te, ll) = constructTopLevelAllocs inputs body
  LambdaN(inputs, AllocNWithVar(ll, te))

let isNormalForm (e: Expr): bool = 
  match e with
  | Patterns.Value(_, _) -> true
  | Patterns.Var(_)      -> true
  | _                    -> false

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
  let toCardEnv stEnv = (stEnv |> Map.map (fun k (v1, v2) -> v2))
  let cardEnv = env |> toCardEnv
  let C e = inferCardinality e cardEnv
  let CEnv = inferCardinality
  let rec ST (t: Type) = 
    match t with
    | _ when isScalarType t                                 -> t
    | _ when t = typeof<Cardinality>                        -> t
    | _ when t = typeof<Vector> || t = typeof<Matrix> || 
        t = typeof<Matrix3D>                                -> t
    | Tuple2Type(tp1, tp2)                                  -> t
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
    let sevars = es |> List.map (fun _ -> newStgVar())
    let ces = es |> List.map C
    let ses = 
      // let sesvars = (es, sevars) ||> List.map (fun x s -> S x s, s)
      // //List.map (fun (StripedAlloc(a, e)) -> a, e)
      // (sesvars, ces) ||> List.map2 (fun (e, s) s -> 
      //   if isScalarType e.Type then
      //     None
      //   else
      //     Some(C e)
      // , e)
      (es, sevars, ces) |||> List.map3 (fun e s c ->
        let (passingStorage, allocPart) = 
          if isScalarType e.Type then
            EMPTY_STORAGE, None
          else
            s, Some(Width c, s)
        let se = S e passingStorage
        allocPart, se
      )

    let sesParams = ses |> List.map snd
    let sesAllocs = ses |> List.choose fst
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
    let x_s = SVNew x
    let newEnv = env.Add(x, (x_s, x_c))
    let newEnvCard = newEnv |> toCardEnv
    Expr.Let(x_c, C e1,
      Alloc (WidthCard (Expr.Var(x)) newEnvCard) (fun s2 ->
        Expr.Let(x_s, S e1 s2, SEnv e2 outputStorage newEnv)
      )
    )
  | Patterns.IfThenElse(e1, e2, e3)  -> Expr.IfThenElse(S e1 O, S e2 outputStorage, S e3 outputStorage)
  | Patterns.NewArray(tp, es)        -> 
    let ses = es |> List.map (fun x -> let s = newStgVar() in Expr.Lambda(s, S x s))
    NewArrayS outputStorage ses
  | Patterns.NewTuple([e0; e1]) ->
    // TODO
    Expr.NewTuple([S e0 O; S e1 O])
  | DerivedPatterns.SpecificCall <@ fst @> (_, tps, [e]) ->
    // TODO
    MakeCall <@ fst @> [S e O] tps
  | DerivedPatterns.SpecificCall <@ snd @> (_, tps, [e]) ->
    // TODO
    MakeCall <@ snd @> [S e O] tps
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
  | DerivedPatterns.SpecificCall <@ corelang.foldOnRange @> (_, [ta], [f; z; st; en]) when isNormalForm z && isNormalForm st && isNormalForm en ->
    let sf = S f O
    let sz = S z O
    let sst = S st O
    let sen = S en O
    let cf = C f
    let cz = C z
    let cst = C st
    let cen = C en
    let s1 = Expr.Var(outputStorage)
    let tac = CT ta
    MakeCall <@ corelang.foldOnRange_dps @> [s1; sf; sz; sst; sen; cf; cz; cst; cen] [ta; tac]
  | DerivedPatterns.SpecificCall <@ corelang.foldOnRange @> (_, [ta], [f; z; st; en]) ->
    let anify (e: Expr) = 
      if isNormalForm e then 
        fun k -> k(e) 
      else 
        let evar = new Var(utils.newVar("anfvar"), e.Type)
        fun k ->
          Expr.Let(evar, e, k(Expr.Var(evar)))
    let anfFold = anify z (fun zv -> anify en (fun env -> anify st (fun stv -> MakeCall <@ corelang.foldOnRange @> [f; zv; stv; env] [ta])))
    S anfFold outputStorage
  | ArrayLength(e0) ->
    Alloc (WidthCard e0 cardEnv) (fun s ->
      ArrayLength(S e0 s)
    )
  | ArrayGet(e0, e1) ->
    Alloc (WidthCard e0 cardEnv) (fun s2 ->
      GetS outputStorage (S e0 s2) (S e1 O)
    )
  | DerivedPatterns.SpecificCall <@ corelang.matrixRead @> (_, _, [name; start; rows; cols]) ->
    // TODO requires number of column information in the matrixRead construct
    let s = Expr.Var(outputStorage)
    let name_s = S name O
    let start_s = S start O
    let rows_s = S rows O
    let cols_s = S cols O
    <@@ corelang.matrixRead_s %%s %%name_s %%start_s %%rows_s %%cols_s @@>
  | DerivedPatterns.SpecificCall <@ corelang.numberPrint @> (_, _, args) ->
    // TODO
    MakeCall <@@ corelang.numberPrint @@> (args |> List.map (fun x -> S x O)) []
  | DerivedPatterns.SpecificCall <@ corelang.vectorPrint @> (_, _, args) ->
    // TODO
    MakeCall <@@ corelang.vectorPrint @@> (args |> List.map (fun x -> S x O)) []
  | DerivedPatterns.SpecificCall <@ corelang.matrixPrint @> (_, _, args) ->
    // TODO
    MakeCall <@@ corelang.matrixPrint @@> (args |> List.map (fun x -> S x O)) []
  | Patterns.Value(v, tp) when tp = typeof<Double> || 
      tp = typeof<Index> || tp = typeof<Cardinality> || tp = typeof<Unit> || 
      tp = typeof<string> || tp = typeof<bool> ->
    exp
  | CardConstructor c ->
    exp
  | Patterns.Sequential(e1, e2) ->
    Expr.Sequential(S e1 O, S e2 outputStorage)
  | DerivedPatterns.SpecificCall <@ utils.tic @> (_, _, _)   -> exp
  | DerivedPatterns.SpecificCall <@ utils.toc @> (_, _, [t; n]) -> MakeCall <@@ utils.toc @@> [S t O; S n O] []
  | _ -> failwithf "Does not know how to transform into the storaged version for the expression `%A`" exp

