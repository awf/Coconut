module transformer

open Microsoft.FSharp.Quotations
open types
open System

let assembly = System.Reflection.Assembly.GetExecutingAssembly()

let mutable currentAssembly = System.Reflection.Assembly.GetExecutingAssembly()

let isScalarType (t: System.Type): bool =
  t = typeof<Index> || 
  t = typeof<bool> || 
  t = typeof<Number> || 
  t = typeof<string> ||
  t = typeof<unit> ||
  t = typeof<Timer>

let (|OperatorName|_|) methodName =
  match methodName with
    | "op_Addition" -> Some("+")
    | "op_Multiply" -> Some("*")
    | "op_Subtraction" -> Some("-")
    | "op_Division" -> Some("/")
    | "op_Modulus" -> Some("%")
    | "op_Inequality" -> Some("!=")
    | "op_Equality" -> Some("==")
    | "op_UnaryNegation" -> Some("-")
    | "op_LessThan" -> Some("<")
    | "op_GreaterThan" -> Some(">")
    | "op_LessThanOrEqual" -> Some("<=")
    | "op_GreaterThanOrEqual" -> Some(">=")
    | "op_DotMinus" -> Some("-")
    | "op_DotPlus" -> Some("+")
    | _ -> None

let (|ScalarOperation|_|) (exp: Expr): (string * Expr list * bool) option =
  match exp with 
  | Patterns.Call(None, op, argList) ->
    match (op.Name, op.DeclaringType.Name) with
    | (OperatorName name, _) -> Some(name, argList, true)
    | ("Sqrt", "Operators") -> Some("sqrt", argList, false)
    | ("Sin", "Operators") -> Some("sin", argList, false)
    | ("Cos", "Operators") -> Some("cos", argList, false)
    | ("Log", "Operators") -> Some("log", argList, false)
    | ("Exp", "Operators") -> Some("exp", argList, false)
    | ("Pow", "Math") -> Some("pow", argList, false)
    | ("GammaLn", "SpecialFunctions") -> Some("gamma_ln", argList, false)
    | ("ToInt", "Operators") -> Some("(int)", argList, false)
    | ("ToDouble", "Operators") -> Some("(double)", argList, false)
    | ("ToDouble", "ExtraTopLevelOperators") -> Some("(double)", argList, false)
    | _                 -> 
      match exp with
      | DerivedPatterns.SpecificCall <@ cardinality.cardToInt @> (_, _, [arg]) ->
        Some("", [arg], false)
      | _ -> None
  | _ -> None

let (|LambdaN|_|) (e: Expr): (Var List * Expr) Option = 
  (* TODO implement in a tail recursive way *)
  let rec lambdaNExtract exp = 
    match exp with
    | Patterns.Lambda(x, body) -> 
      let (inputs, newBody) = lambdaNExtract body
      (x :: inputs, newBody)
    | _ -> ([], exp)
  match lambdaNExtract e with 
  | ([], _) -> None
  | (inputs, body) -> Some(inputs, body)

let (|AppN|_|) (e: Expr): (Expr * Expr list) Option = 
  let rec appNExtract exp args = 
    match exp with 
    | Patterns.Application(f, e) -> appNExtract f (e :: args) 
    | _ -> (exp, args)
  match appNExtract e [] with 
  | (_, []) -> None
  | (func, args) -> Some(func, args)

let (|StripedAppN|) (e: Expr): Expr * Expr list = 
  match e with
  | AppN(e1, args) -> e1, args
  | _              -> e, [] 

let (|LetN|_|) (e: Expr): ((Var * Expr) List * Expr) Option = 
  let rec letNExtract exp statements = 
    match exp with 
    | Patterns.Let(x, e1, e2) -> letNExtract e2 (List.append statements [(x, e1)]) 
    | _ -> (statements, exp)
  match letNExtract e [] with 
  | ([], _) -> None
  | (statements, body) -> Some(statements, body)

let (|TopLevelFunction|) (e: Expr): (Var List * Expr) = 
  match e with 
  | LambdaN(inputs, body) -> (inputs, body) 
  | _ -> ([], e)

let (|MakeClosure|_|) (e: Expr): (Var * Expr * ((System.Type * string * string) List)) Option = 
  match e with 
  | Patterns.Call (None, op, [Patterns.Lambda(envVar, body); Patterns.Call (None, opEnv, list)]) when 
      op.Name = "makeClosure" && opEnv.Name = "makeEnv" -> 
    let envList = 
      let rec extractElems l = 
        match l with
        (* The pattern `Patterns.Call (_, _, [e])` performs an additional level of specialization.
           This specialization results in not using a union type for the variables in the enviroment 
           of a closure. *)
        | [ Patterns.NewUnionCase(_, 
             [ Patterns.NewTuple([Patterns.Value(v, _); 
                                  Patterns.Call (_, _, [e]) as makeAnyNumericCall]); tl]) ] ->
          let variableName = 
            match makeAnyNumericCall with
            | DerivedPatterns.SpecificCall <@ cruntime.makeAnyNumeric @> (_, _, [Patterns.Var(v)]) -> v.Name
            | _ -> failwithf "Expected makeAnyNumeric but provided %A" e
          (e.Type, v.ToString(), variableName) :: extractElems([tl])
        | _ -> []
      extractElems list
    Some (envVar, body, envList)
  | _ -> None

let (|ApplyClosure|_|) (e: Expr): Var Option = 
  match e with 
  | Patterns.Lambda(arg, Patterns.Call (None, op, [Patterns.Var(closure); Patterns.Var(arg2)])) when 
     (op.Name = "applyClosure") && (arg = arg2) ->
     Some (closure)
  | _ -> None

let (|EnvRef|_|) (e: Expr): (Expr * string) Option = 
  match e with 
  | Patterns.Call(None, getOp, [Patterns.Call (None, op, [env; Patterns.Value(s, _)])]) when 
      getOp.Name.StartsWith("get") && op.Name = "envRef" -> 
      Some (env, s.ToString())
  | _ -> None

let mutable existingMethods: (string * string) List = []

let (|ReflectedMethodCall|_|) (e: Expr): (string * string * Expr * Expr list) Option = 
  match e with
  | Patterns.Call (None, op, args) -> 
    try 
      let moduleName = op.DeclaringType.Name
      let methodName = op.Name
      let moduleInfo = currentAssembly.GetType(moduleName)
      let methodInfo = moduleInfo.GetMethod(methodName)
      let reflDefnOpt = Microsoft.FSharp.Quotations.Expr.TryGetReflectedDefinition(methodInfo)
      reflDefnOpt |> Option.map (fun lam -> methodName, moduleName, lam, args)
    with
      _ -> None
  | _ -> None

let (|ExistingCompiledMethod|_|) (e: Expr): (string * string * Expr List) Option = 
  match e with 
  | Patterns.Call (None, op, argList) -> 
    match (op.Name, op.DeclaringType.Name) with
    | (methodName, moduleName) when 
        (List.exists (fun (x, y) -> x = moduleName && y = methodName) existingMethods) -> 
        Some(methodName, moduleName, argList)
    | _ -> None
  | _ -> None

let (|ExistingCompiledMethodWithLambda|_|) (e: Expr): (string * string * Expr List * Expr) Option = 
  match e with
  | ExistingCompiledMethod(methodName, moduleName, args) -> 
    // TODO rewrite using ReflectedMethodCall
    let moduleInfo = currentAssembly.GetType(moduleName)
    let methodInfo = moduleInfo.GetMethod(methodName)
    let reflDefnOpt = Microsoft.FSharp.Quotations.Expr.TryGetReflectedDefinition(methodInfo)
    let attrs = (methodInfo.GetMethodImplementationFlags())
    match reflDefnOpt with
    | None -> failwith (sprintf "fatal error! Extracting lambda definition from a non-inlinable method: %s.%s!" moduleName methodName)
    | Some(lam) ->
      Some(methodName, moduleName, args, lam)
  | _ -> None

let (|ArraySlice|_|) (e: Expr): (Expr * Expr * Expr) option = 
  match e with 
  | Patterns.Call (None, op, argList) -> 
    match (op.Name, op.DeclaringType.Name) with
    | ("GetArraySlice", "OperatorIntrinsics") -> 
      let args = 
        List.map (fun x -> 
          match x with 
          | Patterns.NewUnionCase(_, [v]) -> v
          | _ -> x) argList
      Some(args.[0], args.[1], args.[2])
    | _ -> None
  | _ -> None

let (|ArrayLength|_|) (e: Expr): (Expr) option = 
  match e with 
  | Patterns.PropertyGet(Some(arr), prop, []) when prop.Name = "Length" -> Some(arr)
  | DerivedPatterns.SpecificCall <@ corelang.length @> (_, _, [e0])     -> Some(e0)
  | _                                                                   -> None

let getMethodInfo (methodExpr: Expr): Reflection.MethodInfo = 
  let body = 
    match methodExpr with
    | TopLevelFunction(_, LetN(_, body)) -> body
    | TopLevelFunction(_, body)          -> body
  match body with
  | Patterns.Call(_, op, _) -> 
    op
  | _ -> failwithf "The expression `%A` is not a method expression." methodExpr

let METHOD_VARIABLE_PREFIX = "TOP_LEVEL_"

let methodVariableName (methodName: string) (moduleName: string): string = 
  sprintf "%s%s_%s" METHOD_VARIABLE_PREFIX moduleName methodName

let isMethodVariable (v: Var): bool =
  v.Name.StartsWith(METHOD_VARIABLE_PREFIX)

let (|MethodVariable|_|) (v: Var): (string * string) option = 
  if isMethodVariable v then
    let methodModuleStr = v.Name.Substring(METHOD_VARIABLE_PREFIX.Length)
    let separatorIndex = methodModuleStr.IndexOf('_')
    let methodName = methodModuleStr.Substring(0, separatorIndex)
    let moduleName = methodModuleStr.Substring(separatorIndex + 1)
    Some(moduleName, methodName)
  else
    None

let methodVariableNameMethodInfo (op: Reflection.MethodInfo): string = 
  methodVariableName op.Name op.DeclaringType.Name

let (|AllAppN|_|) (e: Expr): (Expr * Expr list) Option = 
  match e with
  | AppN(e0, es)                          -> Some(e0, es)
  | ReflectedMethodCall(mtd, mdl, e0, es) -> 
    let v = new Var(methodVariableName mtd mdl, e0.Type)
    Some(Expr.Var(v), es)
  | ArraySlice(e0, st, en) ->
    
    let methodVar = 
      let sliceMethod = 
        if e.Type = typeof<Vector> then
          <@@ linalg.vectorSlice @@>
        else if e.Type = typeof<Matrix> then
          <@@ linalg.matrixSlice @@>
        else
          failwithf "Does not know how to convert array slice to a method for type `%A`" e.Type
      let op = getMethodInfo sliceMethod
      new Var(methodVariableNameMethodInfo op, sliceMethod.Type)
    match (st, en) with
    | Patterns.Value(vs, ts), Patterns.Value(ve, te) when ts = te && ts = typeof<Index> ->
      let vvs = unbox<int>(vs)
      let vve = unbox<int>(ve)
      let cardExp = Expr.Value(Card (vve - vvs + 1), typeof<Cardinality>)      
      Some(Expr.Var(methodVar), [cardExp; st; e0])
    | _, ScalarOperation("+", [e2; Patterns.Value(vsz, tsz)], _) when e2 = st && tsz = typeof<Index> ->
      let cardExp = Expr.Value(Card (unbox<int>(vsz) + 1), typeof<Cardinality>)  
      Some(Expr.Var(methodVar), [cardExp; st; e0])
    | _ ->
      failwithf "Not supported slice operation: `%A`" e
  | _ -> None

let MakeCall (methodExpr: Expr) (args: Expr list) (tps: System.Type list): Expr = 
  let op = getMethodInfo methodExpr
  let methodInfo =
    if tps |> List.isEmpty then
      op
    else 
      op.GetGenericMethodDefinition().MakeGenericMethod(tps |> List.toArray)
  Expr.Call(methodInfo, args)

let ArrayLength (e: Expr): Expr =
  let t = e.Type 
  let t1 = t.GetElementType()
  MakeCall(<@@ corelang.length @@>)([e])([t1])

let (|ArrayGet|_|) (e: Expr): (Expr * Expr) option = 
  match e with 
  | Patterns.Call (None, op, [e0; e1]) when op.Name = "GetArray" -> Some(e0, e1)
  | _                                                            -> None

let ArrayGet (e0: Expr) (e1: Expr): Expr =
  <@@ (%%e0: _[]).[%%e1: int] @@>

let (|CardConstructor|_|) (e: Expr): Expr option =
  match e with
  | Patterns.NewUnionCase(info, args) when info.Name = "Card" -> 
    Some(args.[0])
  | _ -> None

let (|LibraryCall|_|) (e: Expr): (string * Expr List) Option = 
  match e with 
  | ExistingCompiledMethod (methodName, moduleName, argList) ->
      Some(methodVariableName methodName moduleName, argList)
  | Patterns.Call (None, op, argList) -> 
    match (op.Name, op.DeclaringType.Name) with
    | (methodName, "ArrayModule") -> 
      failwith (sprintf "The generic version of the method Array.%s is not supported!" methodName)
    // | ("Sqrt", "Operators") -> Some("sqrt", argList)
    // | ("Sin", "Operators") -> Some("sin", argList)
    // | ("Cos", "Operators") -> Some("cos", argList)
    // | ("Log", "Operators") -> Some("log", argList)
    // | ("Exp", "Operators") -> Some("exp", argList)
    // | ("Pow", "Math") -> Some("pow", argList)
    // | ("GammaLn", "SpecialFunctions") -> Some("gamma_ln", argList)
    // | ("ToInt", "Operators") -> Some("(int)", argList)
    // | ("ToDouble", "Operators") -> Some("(double)", argList)
    // | ("ToDouble", "ExtraTopLevelOperators") -> Some("(double)", argList)
    | ("GetArraySlice", "OperatorIntrinsics") -> // TODO rewrite using the `ArraySlice` active pattern
      let args = 
        List.map (fun x -> 
          match x with 
          | Patterns.NewUnionCase(_, [v]) -> v
          | _ -> x) argList
      let prefix = 
        match (List.head args).Type with 
        | tp when tp = typeof<Vector> -> "array"
        | tp when tp = typeof<Matrix> -> "matrix"
        | tp when tp = typeof<Matrix3D> -> "matrix3d"
        | tp -> failwith (sprintf "Array slice not supported for the type %s" (tp.Name))
      Some(prefix + "_slice", args)
    // | ("cardToInt", "cardinality") -> Some("", argList)
    | _ when not(Seq.isEmpty (op.GetCustomAttributes(typeof<CMirror>, true))) -> 
        let attr = Seq.head (op.GetCustomAttributes(typeof<CMirror>, true)) :?> CMirror
        Some(attr.Method, argList)
    | _ -> None
  | _ -> None

let LambdaN (inputs: Var List, body: Expr): Expr =
  List.fold (fun acc cur -> Expr.Lambda(cur,  acc)) body (List.rev inputs)

let AppN (e1: Expr, args: Expr list): Expr =
  Expr.Applications(e1, List.map (fun x -> [x]) args)

let LetN (inputs: (Var * Expr) List, body: Expr): Expr =
  List.fold (fun acc (curv, cure) -> Expr.Let(curv,  cure, acc)) body (List.rev inputs)

let rec (|FunctionType|_|) (t: Type): (Type list * Type) option =
  match t with 
  | _ when t.Name = typeof<_ -> _>.Name ->
    let args = t.GenericTypeArguments
    let (inputs, output) = 
      match args.[1] with
      | FunctionType(is, o) -> is, o
      | o                   -> [], o
    Some(args.[0] :: inputs, output)
  | _ -> None

let rec FunctionType (inputs: Type list) (output: Type): Type =
  match inputs with 
  | [] ->
    output
  | x :: xs -> 
    typeof<_ -> _>.GetGenericTypeDefinition().MakeGenericType(x, FunctionType xs output)

let rec (|Tuple2Type|_|) (t: Type): (Type * Type) option =
  match t with 
  | _ when t.Name = typeof<_ * _>.Name ->
    let args = t.GenericTypeArguments
    Some(args.[0], args.[1])
  | _ -> None

let rec Tuple2Type (tp1: Type) (tp2: Type): Type =
  typeof<_ * _>.GetGenericTypeDefinition().MakeGenericType(tp1, tp2)

open utils

let EMPTY_STORAGE: Var = Var.Global("empty_storage", typeof<Storage>)

let getFreeVariables (e: Expr): Var list = 
  e.GetFreeVars() |> Seq.filter (isMethodVariable >> not) |> Seq.filter (fun x -> not (x = EMPTY_STORAGE)) |> List.ofSeq

let rec variableRenaming (e: Expr) (renamings: (Var * Var) list): Expr =
  let allNames = renamings |> List.collect (fun (v1, v2) -> [v1.Name; v2.Name]) |> Set.ofList
  let alreadyExistingVariableName (name: string) = 
    allNames |> Set.contains name
  let getOrRenameVar(v: Var) = 
    if alreadyExistingVariableName v.Name then
      let rec findAppendId (id: int): int = 
        let newName = sprintf "%s%d" v.Name id
        if alreadyExistingVariableName newName then
          findAppendId (id + 1)
        else
          id
      let newId = findAppendId 0
      let newName = sprintf "%s%d" v.Name newId
      new Var(newName, v.Type)
    else
      v
  match e with 
  | Patterns.Let(v, e1, e2) ->
    let ne1 = variableRenaming e1 renamings
    let (nv, newRenamings) = 
      let nv = getOrRenameVar v
      nv, (v, nv) :: renamings
    let ne2 = variableRenaming e2 newRenamings
    Expr.Let(nv, ne1, ne2)
  | ExprShape.ShapeLambda(x, e) ->
    let (nx, newRenamings) = 
      let nx = getOrRenameVar x
      nx, (x, nx) :: renamings
    let ne = variableRenaming e newRenamings
    Expr.Lambda(nx, ne)
  | ExprShape.ShapeVar(x) ->
    let nx = Option.fold (fun s (v, nv) -> nv) x (List.tryFind (fun (v, nv) -> v = x) renamings)
    Expr.Var(nx)
  | ExprShape.ShapeCombination(op, args) ->
    ExprShape.RebuildShapeCombination(op, List.map (fun arg -> variableRenaming arg renamings) args)

let captureAvoidingSubstitution (e: Expr) (mapping: (Var * Expr) list): Expr = 
  let substitutedE = e.Substitute(fun v2 -> mapping |> List.tryFind (fun (v, a) -> v = v2) |> Option.map snd)
  variableRenaming substitutedE []
  // let renamedE = mapping |> List.map (fun (v, _) -> v, v) |> variableRenaming e
  // renamedE.Substitute(fun v2 -> mapping |> List.tryFind (fun (v, a) -> v = v2) |> Option.map snd)

let rec alphaEquals (e1: Expr) (e2: Expr) (renamings: Map<Var, Var>): bool =
  let rcr e1' e2' = alphaEquals e1' e2' renamings
  match (e1, e2) with
  | (ExprShape.ShapeLambda(x1, b1), ExprShape.ShapeLambda(x2, b2)) ->
      alphaEquals b1 b2 (renamings.Add(x1, x2))
  | (ExprShape.ShapeVar(x1), ExprShape.ShapeVar(x2)) ->
    x1 = x2 || renamings.TryFind(x1) |> Option.exists (fun v2 -> v2 = x2)
  | Patterns.Application(e1, e1'), Patterns.Application(e2, e2') -> 
    (rcr e1 e2) && (rcr e1' e2')
  | Patterns.Call(None, m1, es1), Patterns.Call(None, m2, es2) -> 
    m1 = m2 && ((es1, es2) ||> List.map2 rcr |> List.forall id)
  | Patterns.Value(v1), Patterns.Value(v2) -> v1 = v2
  | (ExprShape.ShapeCombination(op1, args1), ExprShape.ShapeCombination(op2, args2)) ->
    op1 = op2 && (args1, args2) ||> List.map2 rcr |> List.forall id
  | _ -> false