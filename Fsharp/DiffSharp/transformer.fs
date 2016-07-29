module transformer

open Microsoft.FSharp.Quotations
open types

let assembly = System.Reflection.Assembly.GetExecutingAssembly()

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

let (|MakeClosure|_|) (e: Expr): (Var * Expr * ((System.Type * string) List)) Option = 
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
                                  Patterns.Call (_, _, [e])]); tl]) ] ->
          (e.Type, v.ToString()) :: extractElems([tl])
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
    let moduleInfo = assembly.GetType(moduleName)
    let methodInfo = moduleInfo.GetMethod(methodName)
    let reflDefnOpt = Microsoft.FSharp.Quotations.Expr.TryGetReflectedDefinition(methodInfo)
    let attrs = (methodInfo.GetMethodImplementationFlags())
    match reflDefnOpt with
    | None -> failwith (sprintf "fatal error! Extracting lambda definition from a non-inlinable method: %s.%s!" moduleName methodName)
    | Some(lam) ->
      Some(methodName, moduleName, args, lam)
  | _ -> None

let (|LibraryCall|_|) (e: Expr): (string * Expr List) Option = 
  match e with 
  | ExistingCompiledMethod (methodName, moduleName, argList) ->
      Some(sprintf "%s_%s" moduleName methodName, argList)
  | Patterns.Call (None, op, argList) -> 
    match (op.Name, op.DeclaringType.Name) with
    | (methodName, "ArrayModule") -> 
      failwith (sprintf "The generic version of the method Array.%s is not supported!" methodName)
    | ("Sqrt", "Operators") -> Some("sqrt", argList)
    | ("Sin", "Operators") -> Some("sin", argList)
    | ("Cos", "Operators") -> Some("cos", argList)
    | ("Log", "Operators") -> Some("log", argList)
    | ("Exp", "Operators") -> Some("exp", argList)
    | ("Pow", "Math") -> Some("pow", argList)
    | ("GammaLn", "SpecialFunctions") -> Some("gamma_ln", argList)
    | ("ToInt", "Operators") -> Some("(int)", argList)
    | ("ToDouble", "Operators") -> Some("(double)", argList)
    | ("ToDouble", "ExtraTopLevelOperators") -> Some("(double)", argList)
    | ("GetArraySlice", "OperatorIntrinsics") -> 
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
    | _ when not(Seq.isEmpty (op.GetCustomAttributes(typeof<CMirror>, true))) -> 
        let attr = Seq.head (op.GetCustomAttributes(typeof<CMirror>, true)) :?> CMirror
        Some(attr.Method, argList)
    | _ -> None 
  | _ -> None

let LambdaN (inputs: Var List, body: Expr): Expr =
  List.fold (fun acc cur -> Expr.Lambda(cur,  acc)) body (List.rev inputs)

let LetN (inputs: (Var * Expr) List, body: Expr): Expr =
  List.fold (fun acc (curv, cure) -> Expr.Let(curv,  cure, acc)) body (List.rev inputs)