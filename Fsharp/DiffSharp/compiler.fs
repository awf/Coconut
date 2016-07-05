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
        | Patterns.Call (None, op, elist) -> 
            match op.Name with
             | OperatorName opname -> sprintf "%s %s %s" (prettyprint elist.[0]) opname (prettyprint elist.[1]) 
             | "GetArray" -> sprintf "%s[%s]" (prettyprint elist.[0]) (prettyprint elist.[1])
             | _ -> sprintf "ERROR CALL %s(%s)" op.Name (String.concat ", " (List.map prettyprint elist))
        | Patterns.Var(x) -> sprintf "%s" x.Name
        | Patterns.NewArray(tp, elems) -> sprintf "Array[%s](%s)" (tp.ToString()) (String.concat ", " (List.map prettyprint elems))
        | Patterns.Value(v, tp) -> sprintf "%s" (v.ToString())
        | _ -> sprintf "ERROR[%A]" e

let rec ccodegen (e:Expr): string =
        match e with
        | Patterns.Lambda (x, body) -> sprintf "ERROR LAMBDA NOT SUPPORTED!"
        | Patterns.Call (None, op, elist) -> 
            match op.Name with
             | OperatorName opname -> sprintf "%s %s %s" (prettyprint elist.[0]) opname (prettyprint elist.[1]) 
             | "GetArray" -> sprintf "%s[%s]" (prettyprint elist.[0]) (prettyprint elist.[1])
             | _ -> sprintf "ERROR CALL %s(%s)" op.Name (String.concat ", " (List.map prettyprint elist))
        | Patterns.Var(x) -> sprintf "%s" x.Name
        | Patterns.NewArray(tp, elems) -> sprintf "{%s}" (String.concat ", " (List.map prettyprint elems))
        | Patterns.Value(v, tp) -> sprintf "%s" (v.ToString())
        | _ -> sprintf "ERROR[%A]" e

let rec ccodegenType (t: System.Type): string = 
  if(t.IsArray) then
   (ccodegenType (t.GetElementType()))  + "*"
  else if(t.IsGenericParameter) then
    "number_t"
  else
    t.ToString()

let ccodegenTop (e: Expr) (name: string): string =
  let rec extractLambda exp curInputs = match exp with 
    | Patterns.Lambda (x, body) -> extractLambda body (List.append curInputs [x])
    | _ -> (exp, curInputs)
  let (body, inputs) = extractLambda e []
  
  sprintf "%s %s(%s) {\n\treturn %s;\n}" (ccodegenType(body.Type)) name (String.concat ", " (List.map (fun (x: Var) -> ccodegenType(x.Type) + " " + x.Name) inputs)) (ccodegen body)

let compile (moduleName: string) (methodName: string) = 
  let a = System.Reflection.Assembly.GetExecutingAssembly()
  let methodInfo = a.GetType(moduleName).GetMethod(methodName)
  let reflDefnOpt = Microsoft.FSharp.Quotations.Expr.TryGetReflectedDefinition(methodInfo)
  match reflDefnOpt with
   | None -> printfn "%s failed" methodName
   | Some(e) -> printfn "Pretty Printed code for %s.%s:\n\n%s" moduleName methodName  (ccodegenTop e (moduleName + "_" + methodName))