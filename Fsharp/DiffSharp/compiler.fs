module compiler

open Microsoft.FSharp.Quotations
open cruntime

let (|OperatorName|_|) methodName =
  match methodName with
    | "op_Addition" -> Some("+")
    | "op_Multiply" -> Some("*")
    | "op_Subtraction" -> Some("-")
    | _ -> None

let (|LambdaN|_|) (e: Expr): (Var List * Expr) Option = 
  let rec lambdaNExtract exp = match exp with
    | Patterns.Lambda(x, body) -> 
      let (inputs, newBody) = lambdaNExtract body
      (x :: inputs, newBody)
    | _ -> ([], exp)
  match lambdaNExtract e with 
  | ([], _) -> None
  | (inputs, body) -> Some(inputs, body)

let (|TopLevelFunction|) (e: Expr): (Var List * Expr) = 
  match e with 
  | LambdaN(inputs, body) -> (inputs, body) 
  | _ -> ([], e)

let (|MakeClosure|_|) (e: Expr): (Var * Expr * Expr) Option = 
  match e with 
  | Patterns.Call (None, op, [Patterns.Lambda(envVar, body); makeEnv]) when op.Name = "makeClosure" -> Some (envVar, body, makeEnv)
  | _ -> None

let (|ApplyClosure|_|) (e: Expr): Var Option = 
  match e with 
  | Patterns.Lambda(arg, Patterns.Call (None, op, [Patterns.Var(closure); Patterns.Var(arg2)])) when (op.Name = "applyClosure") && (arg = arg2) ->
     Some (closure)
  | _ -> None

let (|EnvRef|_|) (e: Expr): (Expr * string) Option = 
  match e with 
  | Patterns.Call (None, op, [env; Patterns.Value(s, _)]) when op.Name = "envRef" -> Some (env, s.ToString())
  | _ -> None

let LambdaN (inputs: Var List, body: Expr): Expr =
  List.fold (fun acc cur -> Expr.Lambda(cur,  acc)) body (List.rev inputs)

let LetN (inputs: (Var * Expr) List, body: Expr): Expr =
  List.fold (fun acc (curv, cure) -> Expr.Let(curv,  cure, acc)) body (List.rev inputs)

(* Pretty prints the given expression *)
let rec prettyprint (e:Expr): string =
  match e with
  | Patterns.Lambda (x, body) -> sprintf "\%s. %s" (x.Name) (prettyprint body)
  | Patterns.Let(x, e1, e2) -> sprintf "let %s = %s in \n%s" (x.Name) (prettyprint e1) (prettyprint e2)
  | Patterns.Call (None, op, elist) -> 
    match op.Name with
      | OperatorName opname -> sprintf "%s %s %s" (prettyprint elist.[0]) opname (prettyprint elist.[1]) 
      | "GetArray" -> sprintf "%s[%s]" (prettyprint elist.[0]) (prettyprint elist.[1])
      | _ -> sprintf "ERROR CALL ``\n\t%s(%s)\n``" op.Name (String.concat ", " (List.map prettyprint elist))
  | Patterns.Var(x) -> sprintf "%s" x.Name
  | Patterns.NewArray(tp, elems) -> sprintf "Array[%s](%s)" (tp.ToString()) (String.concat ", " (List.map prettyprint elems))
  | Patterns.Value(v, tp) -> sprintf "%s" (v.ToString())
  | _ -> sprintf "ERROR[%A]" e

let mutable variable_counter = 0

let incrementAndGetVariableCounter: int = 
  variable_counter <- variable_counter + 1
  variable_counter

let getVariableCounter: int = 
  variable_counter

(* Generates a unique variable name *)
let newVar (name: string): string = 
  let id = incrementAndGetVariableCounter
  sprintf "%s%d" name id

(* C code generation for a type *)
let rec ccodegenType (t: System.Type): string = 
  if(t.IsArray) then
   "array_" + (ccodegenType (t.GetElementType())) + "*"
  else if(t.IsGenericParameter) then
    "number_t"
  else if (t = typeof<double>) then
    "number_t"
  else if (t = typeof<Environment>) then 
    ("env_t_" + getVariableCounter.ToString() + "*")
    else if (t = typeof<Closure<double, double>>) then 
    ("closure_t*")
  else
    t.ToString()


(* C code generation for an expression *)
let rec ccodegen (e:Expr): string =
  match e with
  | ApplyClosure (closure) -> sprintf "%s->env->y = y" closure.Name
  | Patterns.Lambda (x, body) -> sprintf "ERROR LAMBDA NOT SUPPORTED!"
  | EnvRef(env, name) -> sprintf "%s->%s" (ccodegen env) name
  | Patterns.Call (None, op, elist) -> 
    match op.Name with
      | OperatorName opname -> sprintf "%s %s %s" (ccodegen elist.[0]) opname (ccodegen elist.[1]) 
      | "GetArray" -> sprintf "%s->arr[%s]" (ccodegen elist.[0]) (ccodegen elist.[1])
      | "Map" when op.DeclaringType.Name = "ArrayModule" -> sprintf "array_map(%s)" (String.concat ", " (List.map ccodegen elist))
      | _ -> sprintf "ERROR CALL %s(%s)" op.Name (String.concat ", " (List.map ccodegen elist))
  | Patterns.Var(x) -> sprintf "%s" x.Name
  | Patterns.NewArray(tp, elems) -> 
    failwith (sprintf "ERROR new array should always be the rhs of a let binding\n`%A`" e)
  | Patterns.Let(x, e1, e2) -> 
    failwith (sprintf "ERROR let bindings should occur ONLY in top level\n`%A`" e)
  | Patterns.Value(v, tp) -> sprintf "%s" (v.ToString())
  | _ -> sprintf "ERROR[%A]" e

(* C code generation for a statement in the form of `let var = e` *)
let rec ccodegenStatement (var: Var, e: Expr): string * string List = 
  let (rhs, funs) = 
    match e with 
    | Patterns.NewArray(tp, elems) -> 
      let args = (String.concat "\n\t" (List.mapi (fun index elem -> sprintf "%s->arr[%d] = %s;" var.Name index (ccodegen elem)) elems))
      let arrTp = ("array_" + (ccodegenType tp)) 
      let elemTp = (ccodegenType tp)
      let rhs = sprintf "(%s*)malloc(sizeof(%s));\n\t%s->length=%d;\n\t%s->arr = (%s*)malloc(sizeof(%s) * %d);\n\t%s" arrTp arrTp var.Name (List.length elems)  var.Name elemTp elemTp (List.length elems) args
      (rhs, [])
    | MakeClosure(envVar, lamBody, env) ->
      let lambdaName = newVar "lambda"
      let id = getVariableCounter
      let envName = sprintf "env_t_%d" id
      let fields = ["number_t", "y"]  (* TODO generalize *)
      let fieldsDeclList = List.map (fun (tp, v) -> tp + " " + v) fields
      let fieldsStructDecl = (String.concat "\n\t" (List.map (fun x -> x + ";") fieldsDeclList))
      let envStruct = sprintf "typedef struct %s {\n\t%s\n} %s;" envName fieldsStructDecl envName
      let fieldsDecl = String.concat "," fieldsDeclList
      let fieldsInit = String.concat "\n\t" (List.map (fun (_, v) -> sprintf "env->%s = %s;" v v) fields)
      let makeEnvDef = sprintf "%s* make_%s(%s) {\n\t%s* env = malloc(sizeof(%s));\n\t%s\n\treturn env;\n}" envName envName fieldsDecl envName envName fieldsInit
      let makeEnvInvoke = sprintf "make_%s(%s)" envName (String.concat "," (List.map (fun (_, v) -> v) fields))
      (sprintf "make_closure(%s, %s);" lambdaName makeEnvInvoke, [envStruct; makeEnvDef; ccodegenFunction (Expr.Lambda(envVar, lamBody)) lambdaName])
    | _ -> 
      (ccodegen e, [])
  (sprintf "%s %s = %s;" (ccodegenType var.Type) (var.Name) (rhs), funs)

(* C code generation for a function *)
and ccodegenFunction (e: Expr) (name: string): string =
  let rec extractHeader exp curInputs statements = match exp with 
    | LambdaN (inputs, body) -> extractHeader body (List.append curInputs inputs) statements
    | Patterns.Let(x, e1, e2) -> extractHeader e2 curInputs (List.append statements [(x, e1)])
    | _ -> (exp, curInputs, statements)
  let (result, inputs, statements) = extractHeader e [] []
  let (statementsCodeList, closuresList) = List.unzip (List.map ccodegenStatement statements)
  let statementsCode = (String.concat "\n\t" statementsCodeList)
  let closuresCode = (String.concat "\n" (List.concat closuresList))
  sprintf "%s\n%s %s(%s) {\n\t%s\n\treturn %s;\n}" (closuresCode) (ccodegenType(result.Type)) name (String.concat ", " (List.map (fun (x: Var) -> ccodegenType(x.Type) + " " + x.Name) inputs)) statementsCode (ccodegen result)

(* Performs a simple kind of ANF conversion for specific statements. *)
let rec anfConversion (e: Expr): Expr = 
  match e with 
  | Patterns.Let(x, e1, e2) -> Expr.Let(x, anfConversion e1, anfConversion e2)
  | Patterns.Value(v, tp) -> e
  | Patterns.Lambda (x, body) -> Expr.Lambda(x, anfConversion body)
  | Patterns.NewArray(tp, elems) -> 
    let variable = new Var(newVar "array", tp.MakeArrayType())
    Expr.Let(variable, e, Expr.Var(variable))
  | Patterns.Call (x, op, elist) -> 
    Expr.Call(op, List.map anfConversion elist)
  | _ -> e

let letLifting (e: Expr): Expr = 
  let rec constructTopLevelLets(exp: Expr): Expr * (Var * Expr) List = 
    match exp with 
    | Patterns.Let(x, e1, e2) ->
      let (te1, liftedLets1) = constructTopLevelLets e1
      let (te2, liftedLets2) = constructTopLevelLets e2
      if(not (Seq.exists (fun y -> not(y = x)) (te1.GetFreeVars()))) then
        (te2, (x, te1) :: (List.append liftedLets1 liftedLets2))
      else 
        (Expr.Let(x, te1, te2), List.append liftedLets1 liftedLets2)
    | Patterns.Call (None, op, elist) -> 
      let (tes, lls) = List.unzip (List.map constructTopLevelLets elist)
      (Expr.Call(op, tes), List.concat lls)
    | LambdaN (inputs, body) ->
      let (te, ll) = constructTopLevelLets body
      (LambdaN (inputs, te), ll)
    | _ -> (exp, [])
  let (inputs, body) = match e with TopLevelFunction (i, b) -> (i, b)
  let (te, ll) = constructTopLevelLets(body)
  LambdaN(inputs, LetN(ll, te))
  

(* Performs lambda lifting to make the program closer to C code *)
let rec lambdaLift (e: Expr): Expr = 
  let listDiff list1 list2 = 
    List.filter (fun x -> not (List.exists (fun y -> x = y) list2)) list1
  match e with 
  | LambdaN (inputs, body) when Seq.exists (fun x -> not (Seq.exists (fun y -> x = y) inputs)) (body.GetFreeVars()) -> 
    let freeVars = listDiff (List.ofSeq (body.GetFreeVars())) inputs
    let newVars = List.map (fun (x: Var) -> new Var(newVar(x.Name), x.Type)) freeVars
    let freeNewVars = List.zip freeVars newVars
    let convertedBody = (lambdaLift body).Substitute(fun v -> Option.map (fun (x, y) -> Expr.Var(y)) (List.tryFind (fun (x, y) -> x = v) freeNewVars))
    let result = 
      let envVar = new Var(newVar "env", typeof<Environment>)
      let env = Expr.Var(envVar)
      let closuredBody = List.fold (fun acc (fcur: Var, ncur) -> 
        let variableName = Expr.Value(fcur.Name)
        Expr.Let(ncur, <@@ envRef %%env %%variableName @@>, acc)) convertedBody freeNewVars
      let closureFun = LambdaN(envVar :: inputs, closuredBody)
      (*let closureVar = new Var(newVar "closure", typeof<Closure<double, double>>)*)
      let assembly = System.Reflection.Assembly.GetExecutingAssembly()
      let makeClosureInfo = assembly.GetType("cruntime").GetMethod("makeClosure").MakeGenericMethod(typeof<double>, typeof<double>)
      let createdEnv = <@@ makeEnv ["y", 2.] @@>
      let closureFun2 = <@@ (fun env x -> x * (envRef env "y")) @@>
      let createdClosure = Expr.Call(makeClosureInfo, [closureFun2; createdEnv])
      (*let createdClosure2 = <@@ makeClosure (fun env x -> x * (envRef env "y")) %%createdEnv @@>*)
      (*let closureVarExpr = Expr.Var(closureVar)
      Expr.Let(closureVar, createdClosure, <@@ applyClosure (%%closureVarExpr: Closure<double, double>) @@>)
      *)
      <@@ applyClosure (%%createdClosure: Closure<double, double>) @@>
    result
  | LambdaN (inputs, body) ->
    LambdaN (inputs, lambdaLift body)
  | Patterns.Let(x, e1, e2) -> Expr.Let(x, lambdaLift e1, lambdaLift e2)
  | Patterns.Value(v, tp) -> e
  | Patterns.NewArray(tp, elems) -> 
    Expr.NewArray(tp, List.map lambdaLift elems)
  | Patterns.Call (None, op, elist) -> Expr.Call(op, List.map lambdaLift elist)
  | Patterns.Call (Some x, op, elist) -> Expr.Call(x, op, List.map lambdaLift elist)
  | Patterns.Var (x) -> Expr.Var(x)
  | _ -> failwith (sprintf "%A not handled yet!" e)

let cpreprocess (e: Expr): Expr = 
  anfConversion (letLifting (lambdaLift e))

(* The entry point for the compiler which invokes different phases and code generators *)
let compile (moduleName: string) (methodName: string) = 
  let a = System.Reflection.Assembly.GetExecutingAssembly()
  let methodInfo = a.GetType(moduleName).GetMethod(methodName)
  let reflDefnOpt = Microsoft.FSharp.Quotations.Expr.TryGetReflectedDefinition(methodInfo)
  match reflDefnOpt with
   | None -> printfn "%s failed" methodName
   | Some(e) -> 
     let preprocessed = cpreprocess e
     printfn "preprocessed code:\n%A\n" (preprocessed)
     let generated = ccodegenFunction preprocessed (moduleName + "_" + methodName)
     printfn "Generated C code for %s.%s:\n\n%s" moduleName methodName generated