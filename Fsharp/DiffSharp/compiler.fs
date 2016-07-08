module compiler

open Microsoft.FSharp.Quotations
open cruntime

let (|OperatorName|_|) methodName =
  match methodName with
    | "op_Addition" -> Some("+")
    | "op_Multiply" -> Some("*")
    | "op_Subtraction" -> Some("-")
    | "op_Division" -> Some("/")
    | "op_Inequality" -> Some("!=")
    | _ -> None

let (|LambdaN|_|) (e: Expr): (Var List * Expr) Option = 
  (* TODO implement in tail recursive way *)
  let rec lambdaNExtract exp = match exp with
    | Patterns.Lambda(x, body) -> 
      let (inputs, newBody) = lambdaNExtract body
      (x :: inputs, newBody)
    | _ -> ([], exp)
  match lambdaNExtract e with 
  | ([], _) -> None
  | (inputs, body) -> Some(inputs, body)

let (|LetN|_|) (e: Expr): ((Var * Expr) List * Expr) Option = 
  let rec letNExtract exp statements = match exp with 
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
  | Patterns.Call (None, op, [Patterns.Lambda(envVar, body); Patterns.Call (None, opEnv, list)]) when op.Name = "makeClosure" && opEnv.Name = "makeEnv" -> 
    let envList = 
      let rec extractElems l = match l with
        | [ Patterns.NewUnionCase(_, [Patterns.NewTuple([Patterns.Value(v, _);e]); tl]) ] ->
          (e.Type, v.ToString()) :: extractElems([tl])
        | _ -> []
      extractElems list
    Some (envVar, body, envList)
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

let mutable existingMethods: (string * string) List = []

let (|LibraryCall|_|) (e: Expr): (string * Expr List) Option = 
  match e with 
  | Patterns.Call (None, op, argList) -> 
    match (op.Name, op.DeclaringType.Name) with
    | ("Map", "ArrayModule") -> Some("array_map", argList)
    | ("Map2", "ArrayModule") -> Some("array_map2", argList)
    | ("Sum", "ArrayModule") -> Some("array_sum", argList)
    | ("arrayPrint", "utils") -> Some("array_print", argList)
    | ("numberPrint", "utils") -> Some("number_print", argList)
    | ("arrayMapToMatrix", "utils") -> Some("array_map_to_matrix", argList)
    | ("Sqrt", "Operators") -> Some("sqrt", argList)
    | ("Sin", "Operators") -> Some("sin", argList)
    | ("Cos", "Operators") -> Some("cos", argList)
    | ("GetArraySlice", "OperatorIntrinsics") -> 
      Some("array_slice", List.map (fun x -> match x with 
         | Patterns.NewUnionCase(_, [v]) -> v
         | _ -> x) argList)
    | (methodName, moduleName) when (List.exists (fun (x, y) -> x = moduleName && y = methodName) existingMethods) -> Some(sprintf "%s_%s" moduleName methodName, argList)
    | _ -> None 
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

(* Generates a unique variable name *)
let newVar (name: string): string = 
  variable_counter <- variable_counter + 1
  let id = variable_counter
  sprintf "%s%d" name id

(* C code generation for a type *)
let rec ccodegenType (t: System.Type): string = 
  match t with 
  | _ when t = typeof<double[][]> ->
   "array_array_number_t"
  | _ when t = typeof<double[]> ->
   "array_number_t"
  | _ when (t.IsGenericParameter) ->
    failwith "does not know how to generate code for a generic type"
  | _ when (t = typeof<double>) ->
    "number_t"
  | _ when (t = typeof<int>) ->
    "index_t"
  | _ when (t = typeof<Environment>) -> 
    ("env_t_" + variable_counter.ToString() + "*")
  | _ when (t.Name = typeof<Closure<_, _>>.Name) ->
    "closure_t*"
  | _ when (t = typeof<Unit>) ->
    "void"
  | _ ->
    failwith (sprintf "does not know how to generate code for the type `%s` with name `%s`" (t.ToString()) (t.Name))


(* C code generation for an expression *)
let rec ccodegen (e:Expr): string =
  match e with
  | ApplyClosure (closure) -> sprintf "%s" closure.Name
  | Patterns.Lambda (x, body) -> failwith (sprintf "ERROR lambda should always be in the form of closure creation.\n`%A`" e)
  | EnvRef(env, name) -> sprintf "%s->%s" (ccodegen env) name
  | LibraryCall(name, argList) -> sprintf "%s(%s)" name (String.concat ", " (List.map ccodegen argList))
  | Patterns.Call (None, op, elist) -> 
    match op.Name with
      | OperatorName opname -> sprintf "(%s) %s (%s)" (ccodegen elist.[0]) opname (ccodegen elist.[1]) 
      | "GetArray" -> sprintf "%s->arr[%s]" (ccodegen elist.[0]) (ccodegen elist.[1])
      | _ -> sprintf "ERROR CALL %s.%s(%s)" op.DeclaringType.Name op.Name (String.concat ", " (List.map ccodegen elist))
  | Patterns.Var(x) -> sprintf "%s" x.Name
  | Patterns.NewArray(tp, elems) -> 
    failwith (sprintf "ERROR new array should always be the rhs of a let binding.\n`%A`" e)
  | Patterns.Let(x, e1, e2) -> 
    failwith (sprintf "ERROR let bindings should occur ONLY in top level.\n`%A`" e)
  | Patterns.Value(v, tp) when tp = typeof<Unit> -> ""
  | Patterns.Value(v, tp) -> sprintf "%s" (v.ToString())
  | _ -> sprintf "ERROR[%A]" e

(* C code generation for a statement in the form of `let var = e` *)
let rec ccodegenStatement (var: Var, e: Expr): string * string List = 
  let (rhs, funs, includesLhs) = 
    match e with 
    | Patterns.NewArray(tp, elems) -> 
      let args = (String.concat "\n\t" (List.mapi (fun index elem -> sprintf "%s->arr[%d] = %s;" var.Name index (ccodegen elem)) elems))
      let arrTp = ccodegenType (tp.MakeArrayType()) 
      let elemTp = (ccodegenType tp)
      let rhs = sprintf "(%s)malloc(sizeof(int) * 2);\n\t%s->length=%d;\n\t%s->arr = (%s*)malloc(sizeof(%s) * %d);\n\t%s" arrTp var.Name (List.length elems)  var.Name elemTp elemTp (List.length elems) args
      (rhs, [], false)
    | MakeClosure(envVar, lamBody, fields) ->
      let lambdaName = newVar "lambda"
      let id = variable_counter
      let envName = sprintf "env_t_%d" id
      let fieldsDeclList = List.map (fun (tp, v) -> ccodegenType(tp) + " " + v) fields
      let fieldsStructDecl = match fieldsDeclList with 
      | [] -> (ccodegenType (typeof<AnyNumeric>)) + " dummy_variable;" (* This is because C does not accept structs without any member *)
      | _ ->(String.concat "\n\t" (List.map (fun x -> x + ";") fieldsDeclList))
      let envStruct = sprintf "typedef struct %s {\n\t%s\n} %s;" envName fieldsStructDecl envName
      let fieldsDecl = String.concat "," fieldsDeclList
      let fieldsInit = String.concat "\n\t" (List.map (fun (_, v) -> sprintf "env->%s = %s;" v v) fields)
      let makeEnvDef = sprintf "%s* make_%s(%s) {\n\t%s* env = (%s*)malloc(sizeof(%s));\n\t%s\n\treturn env;\n}" envName envName fieldsDecl envName envName envName fieldsInit
      let makeEnvInvoke = sprintf "make_%s(%s)" envName (String.concat "," (List.map (fun (_, v) -> v) fields))
      (sprintf "make_closure(%s, %s)" lambdaName makeEnvInvoke, [envStruct; makeEnvDef; ccodegenFunction (Expr.Lambda(envVar, lamBody)) lambdaName true], false)
    | Patterns.IfThenElse(cond, e1, e2) ->
      let ccodegenStatements exp = 
        let (stmts, res) = match exp with 
        | LetN(stmts, res) -> stmts, res
        | _ -> [], exp
        let (statementsCodeList, closuresList) = List.unzip (List.map ccodegenStatement stmts)
        let statementsCode = (String.concat "\n\t\t" statementsCodeList)
        (sprintf "%s\n\t\t%s = %s;" statementsCode (var.Name) (ccodegen res), List.concat closuresList)
      let (e1code, e1closures) = ccodegenStatements e1
      let (e2code, e2closures) = ccodegenStatements e2
      (sprintf "%s %s = NULL;\n\tif(%s) {\n\t\t%s\n\t} else {\n\t\t%s\n\t}"
        (ccodegenType var.Type) (var.Name) (ccodegen cond) e1code e2code, List.append e1closures e2closures, true)
    | _ -> 
      (ccodegen e, [], false)
  if(includesLhs) then 
    (rhs, funs) 
  else if (e.Type = typeof<Unit>) then
    (sprintf "%s;" rhs, funs)
  else
    (sprintf "%s %s = %s;" (ccodegenType var.Type) (var.Name) rhs, funs)

(* C code generation for a function *)
and ccodegenFunction (e: Expr) (name: string) (isForClosure: bool): string =
  let rec extractHeader exp curInputs statements = match exp with 
    | LambdaN (inputs, body) -> extractHeader body (List.append curInputs inputs) statements
    | Patterns.Let(x, e1, e2) -> extractHeader e2 curInputs (List.append statements [(x, e1)])
    | _ -> (exp, curInputs, statements)
  let (result, inputs, statements) = extractHeader e [] []
  let (statementsCodeList, closuresList) = List.unzip (List.map ccodegenStatement statements)
  let statementsCode = (String.concat "\n\t" statementsCodeList)
  let closuresCode = (String.concat "\n" (List.concat closuresList))
  let resultType = if(isForClosure) then "value_t" else ccodegenType(result.Type)
  let parameters = (String.concat ", " (List.map (fun (x: Var) -> ccodegenType(x.Type) + " " + x.Name) inputs))
  let finalStatement = if(isForClosure) then sprintf "value_t res;\n\tres.%s_value = %s;\n\treturn res;" (ccodegenType(result.Type)) (ccodegen result) else sprintf "return %s;" (ccodegen result)
  sprintf "%s\n%s %s(%s) {\n\t%s\n\t%s\n}" closuresCode resultType name parameters statementsCode finalStatement

(* Performs a simple kind of ANF conversion for specific statements. *)
let rec anfConversion (letRhs: bool) (e: Expr): Expr = 
  match e with 
  | Patterns.Let(x, e1, e2) -> Expr.Let(x, anfConversion true e1, anfConversion false e2)
  | Patterns.Value(v, tp) -> e
  | Patterns.Lambda (x, body) -> Expr.Lambda(x, anfConversion false body)
  | Patterns.NewArray(tp, elems) when not letRhs -> 
    let variable = new Var(newVar "array", e.Type)
    (* TODO generalize *)
    Expr.Let(variable, e, Expr.Var(variable))
  | Patterns.IfThenElse(cond, e1, e2) when not letRhs ->
    let variable = new Var(newVar "ite", e.Type)
    Expr.Let(variable, Expr.IfThenElse(cond, anfConversion false e1, anfConversion false e2), Expr.Var(variable))
  | Patterns.Sequential(e1, e2) when not letRhs ->
    let variable = new Var(newVar "foo", e1.Type)
    Expr.Let(variable, anfConversion true e1, anfConversion false e2)
  | ExprShape.ShapeCombination(o, exprs) ->
    ExprShape.RebuildShapeCombination(o, List.map (anfConversion false) exprs)
  | _ -> e

(* Lifts let bindings to top-level statements *)
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
  

(* Performs closure conversion to make the program closer to C code *)
let closureConversion (e: Expr): Expr = 
  let listDiff list1 list2 = 
    List.filter (fun x -> not (List.exists (fun y -> x = y) list2)) list1
  let rec lambdaLift (exp: Expr): Expr =
    match exp with 
    | LambdaN (inputs, body) -> 
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
        let assembly = System.Reflection.Assembly.GetExecutingAssembly()
        let makeClosureInfoGeneric = assembly.GetType("cruntime").GetMethod("makeClosure")
        let (inType, outType) = 
          let args = exp.Type.GetGenericArguments()
          (args.[0], args.[1])
        let makeEnvInfo = assembly.GetType("cruntime").GetMethod("makeEnv")
        let makeEnvArg = 
          [List.fold (fun acc (cur: Var) -> 
            let (vstr, vexp) = (Expr.Value(cur.Name.ToString()), Expr.Var(cur))
            (* 
               The next line uses the same number everytime for the associated value. 
               This is because the code generator handles an appropriate variable assigment whenever it is needed 
            *)
            <@@ (((%%vstr: string), 42. ): string * double) :: (%%acc: (string * double) List) @@> ) <@@ []: (string * double) List @@>  freeVars]
        let createdEnv = Expr.Call(makeEnvInfo, makeEnvArg)
        let makeClosureInfo = makeClosureInfoGeneric.MakeGenericMethod(inType, outType)
        let createdClosure = Expr.Call(makeClosureInfo, [closureFun; createdEnv])
        let applyClosureInfoGeneric = assembly.GetType("cruntime").GetMethod("applyClosure")
        let applyClosureInfo = applyClosureInfoGeneric.MakeGenericMethod(inType, outType)
        let argVar = new Var(newVar "arg", inType)
        let closureVar = new Var(newVar "closure", createdClosure.Type)
        let call = Expr.Lambda(argVar, Expr.Call(applyClosureInfo, [Expr.Var(closureVar); Expr.Var(argVar)]))
        Expr.Let(closureVar, createdClosure, call)
      result
    | Patterns.Let(x, e1, e2) -> Expr.Let(x, lambdaLift e1, lambdaLift e2)
    | Patterns.Value(v, tp) -> exp
    | Patterns.NewArray(tp, elems) -> 
      Expr.NewArray(tp, List.map lambdaLift elems)
    | Patterns.Call (None, op, elist) -> 
      let telist = List.map lambdaLift elist
      Expr.Call(op, telist)
    | Patterns.Call (Some x, op, elist) -> Expr.Call(x, op, List.map lambdaLift elist)
    | Patterns.Var (x) -> Expr.Var(x)
    | ExprShape.ShapeCombination(o, exprs) ->
        ExprShape.RebuildShapeCombination(o, List.map lambdaLift exprs)
    | _ -> failwith (sprintf "%A not handled yet!" exp)
  let (inputs, body) = match e with TopLevelFunction (i, b) -> (i, b)
  let te = lambdaLift(body)
  LambdaN(inputs, te)

(* Prepares the given program for C code generation *)
let cpreprocess (e: Expr): Expr = 
  anfConversion false (letLifting (closureConversion e))

let assembly = System.Reflection.Assembly.GetExecutingAssembly()

(* The entry point for the compiler which invokes different phases and code generators *)
let compile (moduleName: string) (methodName: string): string = 
  
  let methodInfo = assembly.GetType(moduleName).GetMethod(methodName)
  let reflDefnOpt = Microsoft.FSharp.Quotations.Expr.TryGetReflectedDefinition(methodInfo)
  match reflDefnOpt with
   | None -> failwith (sprintf "%s failed" methodName)
   | Some(e) -> 
     (* printfn "/* Oringinal code:\n%A\n*/\n" (e) *)
     let preprocessed = cpreprocess e
     (* printfn "/* Preprocessed code:\n%A\n*/\n" (preprocessed) *)
     let generated = ccodegenFunction preprocessed (moduleName + "_" + methodName) false
     (* printfn "// Generated C code for %s.%s:\n\n%s" moduleName methodName generated *)
     generated

let compileSeveral (moduleName: string) (methodNames: string List) =
  List.map (fun m -> 
    existingMethods <- (moduleName, m) :: existingMethods
    compile moduleName m
  ) methodNames


let compileModule (moduleName: string) = 
  let methods = List.map (fun (x: System.Reflection.MethodInfo) -> x.Name) (List.filter (fun (x: System.Reflection.MethodInfo) -> 
      x.DeclaringType.Name = moduleName) (List.ofArray (assembly.GetType(moduleName).GetMethods())))
  let generatedMethods = compileSeveral moduleName methods
  let header = """#include "runtime/fsharp.h"
#include <stdio.h>
#include <math.h>
"""
  System.IO.File.WriteAllLines("../../coconut/" + moduleName + ".h", header :: generatedMethods)
  ()