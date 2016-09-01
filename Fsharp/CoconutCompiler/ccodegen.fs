module ccodegen

open Microsoft.FSharp.Quotations
open cruntime
open utils
open types
open transformer

(* Pretty prints the given expression *)
let rec prettyprint (e:Expr): string =
  match e with
  | LambdaN (inputs, body) -> sprintf "\%s. %s" (String.concat ", " (inputs |> List.map (fun x -> x.Name))) (prettyprint body)
  | Patterns.Let(x, e1, e2) -> sprintf "let %s = %s in \n%s" (x.Name) (prettyprint e1) (prettyprint e2)
  | LibraryCall(name, argList) -> sprintf "%s(%s)" name (String.concat ", " (List.map prettyprint argList))
  | Patterns.Call (None, op, elist) -> 
    match op.Name with
      | OperatorName opname -> 
        if((List.length elist) = 2) then 
          sprintf "(%s %s %s)" (prettyprint elist.[0]) opname (prettyprint elist.[1]) 
        elif ((List.length elist) = 1) then
          sprintf "%s(%s)" opname (prettyprint elist.[0])
        else 
          sprintf "%s(%s)" opname (String.concat ", " (List.map prettyprint elist))
      | "GetArray" -> sprintf "%s[%s]" (prettyprint elist.[0]) (prettyprint elist.[1])
      | _ -> 
        let argsStr = (String.concat ", " (List.map prettyprint elist))
        sprintf "%s(%s)" op.Name argsStr
  | Patterns.Var(x) -> sprintf "%s" x.Name
  | Patterns.NewArray(tp, elems) -> 
    sprintf "Array[%s](%s)" (tp.ToString()) (String.concat ", " (List.map prettyprint elems))
  | Patterns.Value(v, tp) when tp = typeof<Unit> -> "()"
  | Patterns.Value(v, tp) when tp = typeof<Cardinality> -> 
    let (Card(card)) = unbox<Cardinality>(v)
    sprintf "%d" card
  | Patterns.Value(v, tp) -> v.ToString()
  | Patterns.Sequential(e1, e2) -> sprintf "%s;\n%s" (prettyprint e1) (prettyprint e2)
  | Patterns.NewUnionCase (uci, args) -> 
     sprintf "%s(%s)" uci.Name (String.concat ", " (List.map prettyprint args))
  | Patterns.PropertyGet (Some(var), pi, args) -> 
     sprintf "%s.%s" (prettyprint var) pi.Name
  | AppN(f, args) ->
     sprintf "APP{%s}(%s)" (prettyprint f) (String.concat ", " (List.map prettyprint args))
  | Patterns.IfThenElse(cond, e1, e2) -> sprintf "if(%s) {%s} else {%s}" (prettyprint cond) (prettyprint e1) (prettyprint e2)
  | ExprShape.ShapeCombination(op, args) -> 
    sprintf "{%A}(%s)" (op) (String.concat ", " (List.map prettyprint args))
  
  | _ -> sprintf "ERROR[%A]" e

let ARRAY_PREFIX = "array_"

let mutable private current_env_number: int = 0

let private withEnvNumer<'a> (id: int) (cont: int -> 'a): 'a = 
  let prev_number = current_env_number
  current_env_number <- id
  let res = cont(id)
  current_env_number <- prev_number
  res

(* C code generation for a type *)
let rec ccodegenType (t: System.Type): string = 
  match t with 
  | _ when t = typeof<Matrix3D> -> ARRAY_PREFIX + ARRAY_PREFIX + ARRAY_PREFIX + "number_t"
  | _ when t = typeof<Matrix> -> ARRAY_PREFIX + ARRAY_PREFIX + "number_t"
  | _ when t = typeof<Vector> -> ARRAY_PREFIX + "number_t"
  | _ when (t = typeof<Number>) -> "number_t"
  | _ when (t = typeof<AnyNumeric>) -> "value_t"
  | _ when (t = typeof<Index>) -> "index_t"
  | _ when (t = typeof<Cardinality>) -> "card_t"
  | _ when (t = typeof<VectorShape>) -> "vector_shape_t"
  | _ when (t = typeof<MatrixShape>) -> "matrix_shape_t"
  | _ when (t = typeof<Storage>) -> "storage_t"
  | _ when (t = typeof<Timer>) -> "timer_t"
  | _ when (t = typeof<string>) -> "string_t"
  // FIXME buggy
  | _ when (t = typeof<Environment>) -> "env_t_" + current_env_number.ToString() + "*"
  | _ when (t.Name = typeof<Closure<_, _>>.Name) -> "closure_t"
  | _ when (t.Name = typeof<_ -> _>.Name) -> "closure_t"
  | _ when (t = typeof<Unit>) -> "void"
  | _ when (t.IsGenericParameter) ->
    failwith "does not know how to generate code for a generic type"
  | _ ->
    failwith (sprintf "does not know how to generate code for the type `%s` with name `%s`" (t.ToString()) (t.Name))


(* C code generation for an expression *)
let rec ccodegen (e:Expr): string =
  match e with
  | ApplyClosure (closure) -> sprintf "%s" closure.Name
  | Patterns.Lambda (x, body) -> failwith (sprintf "ERROR lambda should always be in the form of closure creation.\n`%A`" e)
  | EnvRef(env, name) -> sprintf "%s->%s" (ccodegen env) name
  | AppN(func, args) -> 
    let closure = ccodegen func
    let tp = ccodegenType (e.Type)
    sprintf "%s.lam(%s.env, %s).%s_value" closure closure (String.concat ", " (List.map ccodegen args)) tp
  | LibraryCall(name, argList) -> sprintf "%s(%s)" name (String.concat ", " (List.map ccodegen argList))
  | Patterns.PropertyGet(Some(arr), prop, []) when prop.Name = "Length" -> sprintf "%s->length" (ccodegen arr)
  | Patterns.Call (None, op, _) when not(Seq.isEmpty (op.GetCustomAttributes(typeof<CMonomorphicMacro>, true))) -> 
    ccodegenMonomorphicMacro e
  | Patterns.Call (None, op, elist) -> 
    match op.Name with
      | OperatorName opname -> 
        if((List.length elist) = 2) then 
          sprintf "(%s) %s (%s)" (ccodegen elist.[0]) opname (ccodegen elist.[1]) 
        elif ((List.length elist) = 1) then
          sprintf "%s(%s)" opname (ccodegen elist.[0])
        else 
          failwith (sprintf "The code generator only supports unary and binary operators. The given operator accepts %d operators" 
                      (List.length elist))
      | "GetArray" -> sprintf "%s->arr[%s]" (ccodegen elist.[0]) (ccodegen elist.[1])
      | _ -> failwith (sprintf "ERROR CALL %s.%s(%s)" op.DeclaringType.Name op.Name (String.concat ", " (List.map ccodegen elist)))
  | Patterns.Var(x) -> sprintf "%s" x.Name
  | Patterns.NewArray(tp, elems) -> 
    failwith (sprintf "ERROR new array should always be the rhs of a let binding.\n`%A`" e)
  | Patterns.Let(x, e1, e2) -> 
    failwith (sprintf "ERROR let bindings should occur ONLY in top level.\n`%A`" e)
  | Patterns.Value(v, tp) when tp = typeof<Unit> -> ""
  | Patterns.Value(v, tp) when tp = typeof<Cardinality> -> 
    let (Card(card)) = unbox<Cardinality>(v)
    sprintf "%d" card
  | Patterns.Value(v, tp) -> sprintf "%s" (v.ToString())
  | Patterns.NewUnionCase(info, args) when info.Name = "Card" -> 
    (ccodegen args.[0])
  | _ -> sprintf "ERROR[%A]" e
and ccodegenMonomorphicMacro (e: Expr): string = 
  match e with
  | DerivedPatterns.SpecificCall <@ cardinality.nestedShape @> (_, [tp], args) ->
    sprintf "nested_shape_%s(%s)" (ccodegenType tp) (String.concat ", " (args |> List.map ccodegen))
  | DerivedPatterns.SpecificCall <@ cardinality.shapeCard @> (_, [tp], args) ->
    sprintf "shape_card_%s(%s)" (ccodegenType tp) (String.concat ", " (args |> List.map ccodegen))
  | _ ->
    failwithf "Does not know how to generate monomorhpic macro call for the expression `%A`" e

(* C code generation for a statement in the form of `let var = e` *)
let rec ccodegenStatement (var: Var, e: Expr): string * string List =
  let ccodegenStatements (tabs: string) (exp: Expr) (resultVar: string option) = 
    let (stmts, res) = 
      match exp with 
      | LetN(stmts, res) -> stmts, res
      | _ -> [], exp
    let (statementsCodeList, closuresList) = List.unzip (List.map ccodegenStatement stmts)
    let statementsCode = (String.concat (sprintf "\n%s" tabs) statementsCodeList)
    let lastStatement = 
      if(res.Type = typeof<unit>) then
        ccodegen res
      else
        let leftVar = Option.fold (fun _ x -> x) (var.Name) resultVar
        sprintf "%s = %s" leftVar (ccodegen res)
    (sprintf "%s\n%s%s;" statementsCode tabs lastStatement, List.concat closuresList) 
    
  let (rhs, funs, includesLhs) = 
    match e with 
    | Patterns.NewArray(tp, elems) -> 
      let args = String.concat "\n\t" (List.mapi (fun index elem -> sprintf "%s->arr[%d] = %s;" var.Name index (ccodegen elem)) elems)
      let arrTp = ccodegenType (tp.MakeArrayType()) 
      let elemTp = (ccodegenType tp)
      let rhs = sprintf "(%s)malloc(sizeof(int) * 2);\n\t%s->length=%d;\n\t%s->arr = (%s*)malloc(sizeof(%s) * %d);\n\t%s" 
                  arrTp var.Name (List.length elems)  var.Name elemTp elemTp (List.length elems) args
      (rhs, [], false)
    | MakeClosure(envVar, lamBody, fields) ->
      let lambdaName = newVar "lambda"
      let id = variable_counter
      let envName = sprintf "env_t_%d" id
      let isEmptyEnvironment = List.isEmpty fields
      let fieldsDeclList = List.map (fun (tp, v, _) -> (ccodegenType tp) + " " + v) fields 
      let envStruct = 
        if isEmptyEnvironment then
          sprintf "typedef empty_env_t %s;" envName
        else
          let fieldsStructDecl = String.concat "\n\t" (List.map (fun x -> x + ";") fieldsDeclList)
          sprintf "typedef struct %s {\n\t%s\n} %s;" envName fieldsStructDecl envName
      let fieldsDecl = String.concat "," fieldsDeclList
      let fieldsInit = String.concat "\n\t" (List.map (fun (_, v, _) -> sprintf "env.%s = %s;" v v) fields)
      let makeEnvDef = 
        if isEmptyEnvironment then
          ""
        else
          sprintf "%s make_%s(%s) {\n\t%s env;\n\t%s\n\treturn env;\n}" 
                         envName envName fieldsDecl envName fieldsInit
      let makeEnvInvoke = 
        if isEmptyEnvironment then
          "make_empty_env()"
        else 
          sprintf "make_%s(%s)" envName (String.concat "," (List.map (fun (_, _, v) -> v) fields))
      let makeEnvVar = sprintf "%s_value" envName
      let makeEnvStatement = sprintf "%s %s = %s" envName makeEnvVar makeEnvInvoke 
      let lambdaCode = withEnvNumer id (fun idx -> ccodegenFunction (Expr.Lambda(envVar, lamBody)) lambdaName true)
      (sprintf "%s; %s %s = make_closure(%s, &%s);" makeEnvStatement (ccodegenType var.Type) (var.Name)  lambdaName makeEnvVar, 
        [envStruct; makeEnvDef; lambdaCode], 
        true)
    | Patterns.IfThenElse(cond, e1, e2) ->
      let (e1code, e1closures) = ccodegenStatements "\t\t" e1 None
      let (e2code, e2closures) = ccodegenStatements "\t\t" e2 None
      (sprintf "%s %s = 0;\n\tif(%s) {\n\t\t%s\n\t} else {\n\t\t%s\n\t}"
        (ccodegenType var.Type) (var.Name) (ccodegen cond) e1code e2code, List.append e1closures e2closures, true)
    | Patterns.Call (None, op, elist) when not(Seq.isEmpty (op.GetCustomAttributes(typeof<CMacro>, true))) -> 
      match op.Name with
      | "vectorAllocCPS" -> 
        let size = 
          match elist.[0] with
          | Patterns.Let(x, _, Patterns.Var(x2)) as sizeExpr when x = x2 -> fst (ccodegenStatements "\t" sizeExpr None)
          | sizeExpr -> ccodegen sizeExpr
        let (Patterns.Lambda(i, body)) = elist.[1]
        let tp = ccodegenType typeof<Vector>
        let storageVar = i.Name 
        let (bodyCode, bodyClosures) = ccodegenStatements "\t" body None
        (sprintf "%s %s = vector_alloc(%s);\n\t%s\n\tfree(%s);" tp storageVar size bodyCode storageVar,
          bodyClosures, true)
      | "iterateNumber" ->
        let (Patterns.Lambda(num, Patterns.Lambda(idx, body))) = elist.[0]
        let idxCode = idx.Name
        let resultType = ccodegenType (var.Type)
        let resultName = var.Name
        let initCode = ccodegen (elist.[1])
        let startCode = ccodegen (elist.[2])
        let endCode = ccodegen (elist.[3])
        let (bodyCode, bodyClosures) = ccodegenStatements "\t\t" (body.Substitute(fun v -> if v = num then Some(Expr.Var(var)) else None)) None
        (sprintf "%s %s = %s;\n\tfor(int %s = %s; %s <= %s; %s++){\n\t\t%s\n\t}"
           resultType resultName initCode 
           idxCode startCode idxCode endCode idxCode
           bodyCode
           , bodyClosures, true)
      | "vectorBuildGivenStorage" ->
        let storage = ccodegen (elist.[0])
        let resultType = ccodegenType (var.Type)
        let resultName = var.Name 
        let (Patterns.Lambda(idx, body)) = elist.[1]
        let idxCode = idx.Name
        let (bodyCode, bodyClosures) = ccodegenStatements "\t\t\t" body (Some(sprintf "%s->arr[%s]" resultName idxCode))
        (sprintf "%s %s = (%s)%s;\n\t\tfor(int %s = 0; %s < %s->length; %s++){\n\t\t\t%s\n\t\t}"
           resultType resultName resultType storage 
           idxCode idxCode resultName idxCode
           bodyCode
           , bodyClosures, true)
      | "vectorBuild_s" ->
        let storage = ccodegen (elist.[0])
        let resultType = ccodegenType (var.Type)
        let resultName = var.Name 
        let (LambdaN([st; idx; crd], body)) = elist.[2]
        let idxCode = idx.Name
        let (bodyCode, bodyClosures) = ccodegenStatements "\t\t\t" body (Some(sprintf "%s->arr[%s]" resultName idxCode))
        (sprintf "%s %s = (%s)%s;\n\t\tfor(int %s = 0; %s < %s->length; %s++){\n\t\t\t%s\n\t\t}"
           resultType resultName resultType storage 
           idxCode idxCode resultName idxCode
           bodyCode
           , bodyClosures, true)
      | "vectorAllocOnStack" -> 
        let size = ccodegen (elist.[0])
        let tp = ccodegenType typeof<Vector>
        let elemTp = ccodegenType typeof<Number>
        let resultTp = ccodegenType typeof<Storage>
        let structTp = sprintf "%s_struct" tp
        let elementsVar = sprintf "%s_elements" var.Name
        let structVar = sprintf "%s_struct" var.Name

        let elementsDef = sprintf "%s %s[%s];" elemTp elementsVar size
        let structDef   = sprintf "%s %s = { .arr = %s, .length = %s };" structTp structVar elementsVar size
        (sprintf "%s\n\t%s\n\t%s %s = &%s;" elementsDef structDef resultTp var.Name structVar,
          [], true)
      | "length" ->
        let arr = ccodegen (elist.[0])
        (sprintf "%s->length" arr, [], false)
      | "width" ->
        let crd = ccodegen (elist.[0])
        (sprintf "width(%s)" crd, [], false)
      | name ->
        match e with
        | DerivedPatterns.SpecificCall <@ cardinality.nestedShape @> (_, [tp], _) ->
          (sprintf "nested_shaped_%s(%s)" (ccodegenType tp) (String.concat ", " (elist |> List.map ccodegen)), [], false)
        | _ ->
          failwithf "Does not know how to generate C macro code for the method `%s`" name
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
  let rec extractHeader exp curInputs statements = 
    match exp with 
    | LambdaN (inputs, body) -> extractHeader body (List.append curInputs inputs) statements
    | Patterns.Let(x, e1, e2) -> extractHeader e2 curInputs (List.append statements [(x, e1)])
    | _ -> (exp, curInputs, statements)
  let (result, inputs, statements) = extractHeader e [] []
  let (statementsCodeList, closuresList) = List.unzip (List.map ccodegenStatement statements)
  let statementsCode = (String.concat "\n\t" statementsCodeList)
  let closuresCode = (String.concat "\n" (List.concat closuresList))
  let resultType = if(isForClosure) then "value_t" else ccodegenType(result.Type)
  let parameters = (String.concat ", " (List.map (fun (x: Var) -> ccodegenType(x.Type) + " " + x.Name) inputs))
  let finalStatement = 
    if(isForClosure) then 
      if(result.Type = typeof<unit>) then
        sprintf "value_t res;\n\t%s;\n\treturn res;" (ccodegen result) 
      else 
        sprintf "value_t res;\n\tres.%s_value = %s;\n\treturn res;" (ccodegenType (result.Type)) (ccodegen result) 
    else 
      sprintf "return %s;" (ccodegen result)
  sprintf "%s\n%s %s(%s) {\n\t%s\n\t%s\n}" closuresCode resultType name parameters statementsCode finalStatement

let ccodegenTopLevel (e: Expr) (name: string) (debug: bool): string = 
  let preprocessed = (ctransformer.cpreprocess) e
  if debug then printfn "/* Preprocessed code:\n%A\n*/\n" (prettyprint preprocessed)
  let generated = ccodegenFunction preprocessed name false
  if debug then printfn "// Generated C code for %s:\n\n%s" name generated
  generated