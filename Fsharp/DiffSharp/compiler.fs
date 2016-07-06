module compiler

open Microsoft.FSharp.Quotations

let (|OperatorName|_|) methodName =
  match methodName with
    | "op_Addition" -> Some("+")
    | "op_Multiply" -> Some("*")
    | "op_Subtraction" -> Some("-")
    | _ -> None

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

let newVar (name: string): string = 
  variable_counter <- variable_counter + 1
  sprintf "%s%d" name variable_counter


let rec ccodegenType (t: System.Type): string = 
  if(t.IsArray) then
   "array_" + (ccodegenType (t.GetElementType()))
  else if(t.IsGenericParameter) then
    "number_t"
  else
    t.ToString()

let rec ccodegen (e:Expr): string =
        match e with
        | Patterns.Lambda (x, body) -> sprintf "ERROR LAMBDA NOT SUPPORTED!"
        | Patterns.Call (None, op, elist) -> 
            match op.Name with
             | OperatorName opname -> sprintf "%s %s %s" (prettyprint elist.[0]) opname (prettyprint elist.[1]) 
             | "GetArray" -> sprintf "%s[%s]" (prettyprint elist.[0]) (prettyprint elist.[1])
             | _ -> sprintf "ERROR CALL %s(%s)" op.Name (String.concat ", " (List.map prettyprint elist))
        | Patterns.Var(x) -> sprintf "%s" x.Name
        (*
        | Patterns.Let(x, Patterns.NewArray(tp, elems), e2) -> 
          sprintf "{%s};" (String.concat ", " (List.map prettyprint elems))
        | Patterns.NewArray(tp, elems) -> 
          sprintf "ERROR new array without let binding [%A]" e
        *)
        | Patterns.NewArray(tp, elems) -> 
          sprintf "(%s[%d]) {%s}" (ccodegenType tp) (List.length elems) (String.concat ", " (List.map prettyprint elems))
        | Patterns.Value(v, tp) -> sprintf "%s" (v.ToString())
        | _ -> sprintf "ERROR[%A]" e


let ccodegenTop (e: Expr) (name: string): string =
  let rec extractHeader exp curInputs statements = match exp with 
    | Patterns.Lambda (x, body) -> extractHeader body (List.append curInputs [x]) statements
    | Patterns.Let(x, e1, e2) -> extractHeader e2 curInputs (List.append statements [(x, e1)])
    | _ -> (exp, curInputs, statements)
  let (result, inputs, statements) = extractHeader e [] []
  let statementsCode = (String.concat "\n\t" (List.map (fun (lhs: Var, rhs: Expr) -> sprintf "%s %s = %s;" (ccodegenType lhs.Type) (lhs.Name) (ccodegen rhs)) statements))
  sprintf "%s %s(%s) {\n\t%s\n\treturn %s;\n}" (ccodegenType(result.Type)) name (String.concat ", " (List.map (fun (x: Var) -> ccodegenType(x.Type) + " " + x.Name) inputs)) statementsCode (ccodegen result)

(* Performs a simple kind of ANF conversion for specific statements. *)
let rec cpreprocess (e: Expr): Expr = 
  match e with 
  | Patterns.Let(tp, e1, e2) -> Expr.Let(tp, cpreprocess e1, cpreprocess e2)
  | Patterns.Value(v, tp) -> e
  | Patterns.Lambda (x, body) -> Expr.Lambda(x, cpreprocess body)
  | Patterns.NewArray(tp, elems) -> 
    let variable = new Var("x", tp.MakeArrayType())
    Expr.Let(variable, e, Expr.Var(variable))
  | Patterns.Call (x, op, elist) -> 
    Expr.Call(op, List.map cpreprocess elist)
  | _ -> e

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
     let generated = ccodegenTop preprocessed (moduleName + "_" + methodName)
     printfn "Pretty Printed code for %s.%s:\n\n%s" moduleName methodName generated