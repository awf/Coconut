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

let LambdaN (inputs: Var List, body: Expr): Expr =
  List.fold (fun acc cur -> Expr.Lambda(cur,  acc)) body (List.rev inputs)

(* Pretty prints the given expression *)
let rec prettyprint (e:Expr): string =
  match e with
  | Patterns.Lambda (x, body) -> sprintf "\%s. %s" (x.Name) (prettyprint body)
  | Patterns.Let(x, e1, e2) -> sprintf "let %s = %s in \n%s" (x.Name) (prettyprint e1) (prettyprint e2)
  | Patterns.Call (None, op, elist) -> 
    match op.Name with
      | OperatorName opname -> sprintf "%s %s %s" (prettyprint elist.[0]) opname (prettyprint elist.[1]) 
      | "GetArray" -> sprintf "%s[%s]" (prettyprint elist.[0]) (prettyprint elist.[1])
      | _ -> sprintf "ERROR CALL %s(%s)" op.Name (String.concat ", " (List.map prettyprint elist))
  | Patterns.Var(x) -> sprintf "%s" x.Name
  | Patterns.NewArray(tp, elems) -> sprintf "Array[%s](%s)" (tp.ToString()) (String.concat ", " (List.map prettyprint elems))
  | Patterns.Value(v, tp) -> sprintf "%s" (v.ToString())
  | _ -> sprintf "ERROR[%A]" e

let mutable variable_counter = 0

(* Generates a unique variable name *)
let newVar (name: string): string = 
  variable_counter <- variable_counter + 1
  sprintf "%s%d" name variable_counter

(* C code generation for a type *)
let rec ccodegenType (t: System.Type): string = 
  if(t.IsArray) then
   "array_" + (ccodegenType (t.GetElementType()))
  else if(t.IsGenericParameter) then
    "number_t"
  else if (t = typeof<double>) then
    "number_t"
  else 
    t.ToString()


(* C code generation for an expression *)
let rec ccodegen (e:Expr): string =
  match e with
  | Patterns.Lambda (x, body) -> sprintf "ERROR LAMBDA NOT SUPPORTED!"
  | Patterns.Call (None, op, elist) -> 
    match op.Name with
      | OperatorName opname -> sprintf "%s %s %s" (prettyprint elist.[0]) opname (ccodegen elist.[1]) 
      | "GetArray" -> sprintf "%s[%s]" (ccodegen elist.[0]) (ccodegen elist.[1])
      | _ -> sprintf "ERROR CALL %s(%s)" op.Name (String.concat ", " (List.map ccodegen elist))
  | Patterns.Var(x) -> sprintf "%s" x.Name
  | Patterns.NewArray(tp, elems) -> 
    sprintf "ERROR new array without let binding [%A]" e
  | Patterns.Value(v, tp) -> sprintf "%s" (v.ToString())
  | _ -> sprintf "ERROR[%A]" e

(* C code generation for a statement in the form of `let var = e` *)
let ccodegenStatement (var: Var, e: Expr): string = 
  match e with 
  | Patterns.NewArray(tp, elems) -> 
    sprintf "%s %s = malloc(sizeof(%s) * %d);\n\t%s" (ccodegenType var.Type) (var.Name) (ccodegenType tp) (List.length elems) 
      (String.concat "\n\t" (List.mapi (fun index elem -> sprintf "%s[%d] = %s;" var.Name index (ccodegen elem)) elems))
  | _ -> 
    sprintf "%s %s = %s;" (ccodegenType var.Type) (var.Name) (ccodegen e)

(* C code generation for a function *)
let ccodegenFunction (e: Expr) (name: string): string =
  let rec extractHeader exp curInputs statements = match exp with 
    | LambdaN (inputs, body) -> extractHeader body (List.append curInputs inputs) statements
    | Patterns.Let(x, e1, e2) -> extractHeader e2 curInputs (List.append statements [(x, e1)])
    | _ -> (exp, curInputs, statements)
  let (result, inputs, statements) = extractHeader e [] []
  let statementsCode = (String.concat "\n\t" (List.map ccodegenStatement statements))
  sprintf "%s %s(%s) {\n\t%s\n\treturn %s;\n}" (ccodegenType(result.Type)) name (String.concat ", " (List.map (fun (x: Var) -> ccodegenType(x.Type) + " " + x.Name) inputs)) statementsCode (ccodegen result)

(* Performs a simple kind of ANF conversion for specific statements. *)
let rec anfConversion (e: Expr): Expr = 
  match e with 
  | Patterns.Let(tp, e1, e2) -> Expr.Let(tp, anfConversion e1, anfConversion e2)
  | Patterns.Value(v, tp) -> e
  | Patterns.Lambda (x, body) -> Expr.Lambda(x, anfConversion body)
  | Patterns.NewArray(tp, elems) -> 
    let variable = new Var(newVar "array", tp.MakeArrayType())
    Expr.Let(variable, e, Expr.Var(variable))
  | Patterns.Call (x, op, elist) -> 
    Expr.Call(op, List.map anfConversion elist)
  | _ -> e

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
      let closureVar = new Var(newVar "closure", typeof<Closure<double, double>>)
      let assembly = System.Reflection.Assembly.GetExecutingAssembly()
      let makeClosureInfo = assembly.GetType("cruntime").GetMethod("makeClosure").MakeGenericMethod(typeof<double>, typeof<double>)
      let createdEnv = <@@ makeEnv ["y", 2.] @@>
      let closureFun2 = <@@ (fun env x -> x * (envRef env "y")) @@>
      let createdClosure = Expr.Call(makeClosureInfo, [closureFun2; createdEnv])
      (*let createdClosure2 = <@@ makeClosure (fun env x -> x * (envRef env "y")) %%createdEnv @@>*)
      let closureVarExpr = Expr.Var(closureVar)
      Expr.Let(closureVar, createdClosure, <@@ applyClosure (%%closureVarExpr: Closure<double, double>) @@>)
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
  lambdaLift (anfConversion e)

(* The entry point for the compiler which invokes different phases and code generators *)
let compile (moduleName: string) (methodName: string) = 
  let a = System.Reflection.Assembly.GetExecutingAssembly()
  let methodInfo = a.GetType(moduleName).GetMethod(methodName)
  let reflDefnOpt = Microsoft.FSharp.Quotations.Expr.TryGetReflectedDefinition(methodInfo)
  match reflDefnOpt with
   | None -> printfn "%s failed" methodName
   | Some(e) -> 
     let preprocessed = cpreprocess e
     printfn "preprocessed code:\n%s\n" (prettyprint preprocessed)
     let generated = ccodegenFunction preprocessed (moduleName + "_" + methodName)
     printfn "Pretty Printed code for %s.%s:\n\n%s" moduleName methodName generated