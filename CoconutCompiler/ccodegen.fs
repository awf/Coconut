module ccodegen

open Microsoft.FSharp.Quotations
open cruntime
open utils
open types
open transformer
open ctransformer

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
let TUPLE_PREFIX = "tuple_"

let mutable private current_env_number: int = 0

let private withEnvNumber<'a> (id: int) (cont: int -> 'a): 'a = 
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
  | _ when (t = typeof<Matrix3DShape>) -> "matrix3d_shape_t"
  | _ when (t = typeof<Storage>) -> "storage_t"
  | _ when (t = typeof<Timer>) -> "timer_t"
  | _ when (t = typeof<string>) -> "string_t"
  // FIXME buggy
  | _ when (t = typeof<Environment>) -> "env_t_" + current_env_number.ToString() + "*"
  | _ when (t.Name = typeof<Closure<_, _>>.Name) -> "closure_t"
  | _ when (t.Name = typeof<_ -> _>.Name) -> "closure_t"
  | _ when (t.Name = typeof<_ * _>.Name) -> 
    TUPLE_PREFIX + (ccodegenType (t.GenericTypeArguments.[0])) + "_" + (ccodegenType (t.GenericTypeArguments.[1]))
  | _ when (t = typeof<Unit>) -> "void"
  | _ when (t = typeof<bool>) -> "bool_t"
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
    let argsCode = String.concat ", " (List.map ccodegen args)
    match func with
    | Patterns.Var(MethodVariable(methodName, moduleName) as funcVar) ->
      sprintf "%s(%s)" funcVar.Name argsCode
    | _ ->
      let closure = ccodegen func
      let tp = ccodegenType (e.Type)
      sprintf "%s.lam(%s.env, %s).%s_value" closure closure argsCode tp
  | ScalarOperation(name, elist, isInfix) -> 
    if((List.length elist) = 2) then 
      if isInfix then
        sprintf "(%s) %s (%s)" (ccodegen elist.[0]) name (ccodegen elist.[1]) 
      else
        sprintf "%s(%s)" name (String.concat ", " (List.map ccodegen elist))
    elif ((List.length elist) = 1) then
      sprintf "%s(%s)" name (ccodegen elist.[0])
    else 
      failwith (sprintf "The code generator only supports unary and binary operators. The given operator accepts %d operators" 
                  (List.length elist))
  | LibraryCall(name, argList) -> sprintf "%s(%s)" name (String.concat ", " (List.map ccodegen argList))
  | Patterns.PropertyGet(Some(arr), prop, []) when prop.Name = "Length" -> sprintf "%s->length" (ccodegen arr)
  | Patterns.Call (None, op, _) when isMonomorphicMacro op -> 
    ccodegenMonomorphicMacro e
  | Patterns.NewTuple([e1; e2]) ->
    let postfix = 
      match e1.Type with
      | x when x = typeof<Number> -> ""
      | x when x = typeof<Vector> -> "_v_v"
      | x when x = typeof<Matrix> -> "_m_m"
      | x when x = typeof<Cardinality> -> "_c_c"
    sprintf "pair%s(%s, %s)" postfix (ccodegen e1) (ccodegen e2)
  | DerivedPatterns.SpecificCall <@ fst @> (_, _, [e]) ->
    sprintf "%s._1" (ccodegen e)
  | DerivedPatterns.SpecificCall <@ snd @> (_, _, [e]) ->
    sprintf "%s._2" (ccodegen e)
  | Patterns.Call (None, op, elist) -> 
    match op.Name with
    | "GetArray" -> sprintf "%s->arr[%s]" (ccodegen elist.[0]) (ccodegen elist.[1])
    | "Ignore" -> ccodegen elist.[0]
    | _ -> failwith (sprintf "ERROR CALL %s.%s(%s)" op.DeclaringType.Name op.Name (String.concat ", " (List.map ccodegen elist)))
  | Patterns.Var(x) -> sprintf "%s" x.Name
  | Patterns.NewArray(tp, elems) -> 
    failwith (sprintf "ERROR new array should always be the rhs of a let binding.\n`%A`" e)
  | Patterns.Let(x, e1, e2) -> 

    failwith (sprintf "ERROR let bindings should occur ONLY in top level.\n`%A`" e)
  | Patterns.Value(v, tp) when tp = typeof<Unit> -> ""
  | Patterns.Value(value, tp) when tp = typeof<Cardinality> || tp.Name = typeof<NestedShape<_>>.Name -> 
    let printCard (c: Cardinality): string = 
      let (Card(card)) = c
      sprintf "%d" card
    let printMatrixShape (ms: MatrixShape): string = 
      let (NestedShape(elem, Card(card))) = ms
      sprintf "nested_shape_%s(%s, %d)" (ccodegenType typeof<VectorShape>) (printCard elem) card
    let printMatrix3DShape (m3s: Matrix3DShape): string = 
      let (NestedShape(elem, Card(card))) = m3s
      sprintf "nested_shape_%s(%s, %d)" (ccodegenType typeof<MatrixShape>) (printMatrixShape elem) card
    match value.GetType() with
    | t when t = typeof<Cardinality> -> 
      printCard (unbox<Cardinality>(value))
    | t when t = typeof<MatrixShape> ->
      printMatrixShape (unbox<MatrixShape>(value))
    | t when t = typeof<Matrix3DShape> ->
      printMatrix3DShape (unbox<Matrix3DShape>(value))
    | _ ->
      failwithf "Does not know how to generate value of type `%A`" tp
  | Patterns.Value(v, tp) when tp = typeof<string> -> sprintf "\"%s\"" (v.ToString())
  | Patterns.Value(v, tp) when tp = typeof<bool> -> v.ToString().ToLower()
  | Patterns.Value(v, tp) -> sprintf "%s" (v.ToString())
  | CardConstructor c -> 
    (ccodegen c)
  | _ -> sprintf "ERROR[%A]" e

and ccodegenMonomorphicMacro (e: Expr): string = 
  let ccodegenArgs (args: Expr list): string = 
    String.concat ", " (args |> List.map ccodegen)
  match e with
  | DerivedPatterns.SpecificCall <@ cardinality.nestedShape @> (_, [tp], args) ->
    sprintf "nested_shape_%s(%s)" (ccodegenType tp) (ccodegenArgs args)
  | DerivedPatterns.SpecificCall <@ cardinality.shapeCard @> (_, [tp], [shape]) ->
    sprintf "%s.card" (ccodegen shape)
  | DerivedPatterns.SpecificCall <@ cardinality.shapeElem @> (_, [tp], [shape]) ->
    sprintf "%s.elem" (ccodegen shape)
  | DerivedPatterns.SpecificCall <@ cardinality.width @> (_, [tp], args) ->
    sprintf "width_%s(%s)" (ccodegenType tp) (ccodegenArgs args)
  | DerivedPatterns.SpecificCall <@ corelang.get_s @> (_, [tp1; tp2], [st; arr; idx; arr_c; idx_c]) ->
    match tp1 with
    | t when t = typeof<Number> ->
      assert (tp2 = typeof<VectorShape>)
      sprintf "%s->arr[%s]" (ccodegen arr) (ccodegen idx)
    | t when t = typeof<Vector> ->
      assert (tp2 = typeof<MatrixShape>)
      // FIXME make it non-leaky
      sprintf "%s->arr[%s]" (ccodegen arr) (ccodegen idx)
    | t when t = typeof<Matrix> ->
      assert (tp2 = typeof<Matrix3DShape>)
      // FIXME make it non-leaky
      sprintf "%s->arr[%s]" (ccodegen arr) (ccodegen idx)
    | _                         ->
      failwithf "Does not know how to generate C code for get_s with type parameters `%A`, `%A`" tp1 tp2
  | _ -> 
    failwithf "Does not know how to generate monomorhpic macro call for the expression `%A`" e

(* C code generation for a statement in the form of `let var = e` *)
let rec ccodegenStatement (withTypeDef: bool) (var: Var, e: Expr): string * string List =
  let ccodegenStatements (tabs: string) (exp: Expr) (resultVar: string option) = 
    let (stmts, res) = 
      match exp with 
      | LetN(stmts, res) -> stmts, res
      | _ -> [], exp
    let (statementsCodeList, closuresList) = List.unzip (List.map (ccodegenStatement true) stmts)
    let statementsCode = (String.concat (sprintf "\n%s" tabs) statementsCodeList)
    let lastStatement = 
      if(res.Type = typeof<unit>) then
        ccodegen res
      else
        let leftVar = (var, resultVar) ||> Option.fold (fun _ c -> new Var(c, res.Type))
        fst (ccodegenStatement false (leftVar, res))
    (sprintf "%s\n%s%s;" statementsCode tabs lastStatement, List.concat closuresList) 
  let ccodegenMacro (e: Expr): string * string list * bool = 
    match e with
    | Patterns.Call (None, op, elist) -> 
      match op.Name with
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
      | name ->
        match e with
        | DerivedPatterns.SpecificCall <@ corelang.build @> (_, [ta], _) ->
          let resultType = ccodegenType (var.Type)
          let resultName = var.Name 
          let (Patterns.Lambda(idx, body)) = elist.[1]
          let idxCode = idx.Name
          let lengthCode = ccodegen elist.[0]
          let arrTp = ccodegenType (ta.MakeArrayType()) 
          let elemTp = (ccodegenType ta)
          let arrayInit = 
            sprintf "%s %s = (%s)storage_alloc(sizeof(int) * 2);\n\t%s->length=%s;\n\t%s->arr = (%s*)storage_alloc(sizeof(%s) * %s)" 
                  arrTp resultName arrTp resultName lengthCode resultName elemTp elemTp lengthCode
          let (bodyCode, bodyClosures) = ccodegenStatements "\t\t\t" body (Some(sprintf "%s->arr[%s]" resultName idxCode))
          (sprintf "%s;\n\t\tfor(int %s = 0; %s < %s->length; %s++){\n\t\t\t%s\n\t\t}"
             arrayInit
             idxCode idxCode resultName idxCode
             bodyCode
             , bodyClosures, true)
        | DerivedPatterns.SpecificCall <@ corelang.build_s @> (_, [ta; ts], _) ->
          let storage = ccodegen (elist.[0])
          let resultType = ccodegenType (var.Type)
          let resultName = var.Name 
          let (LambdaN([st; idx; crd], body)) = elist.[2]
          let idxCode = idx.Name
          let stCode = st.Name
          let stType = ccodegenType st.Type
          let elemType = ccodegenType body.Type
          let lengthCode = ccodegen elist.[1]
          let stLocation = 
            if ta = typeof<Number> then
              sprintf "%s" resultName
            elif ta = typeof<Vector> || ta = typeof<Matrix> then
              sprintf "(STG_OFFSET(%s, MATRIX_HEADER_BYTES(%s)))" resultName lengthCode
            else
              failwithf "Does not know how to generate build_s for the type `%A`" ta
          let stOffset = 
            if ta = typeof<Number> then
              sprintf "sizeof(%s)" (ccodegenType ta)
            elif ta = typeof<Vector> || ta = typeof<Matrix> then
              sprintf "VECTOR_ALL_BYTES(%s->arr[%s]->length)" resultName idxCode
            else
              failwithf "Does not know how to generate build_s for the type `%A`" ta
          let (bodyCode, bodyClosures) = ccodegenStatements "\t\t\t" body (Some(sprintf "%s->arr[%s]" resultName idxCode))
          (sprintf "%s %s = (%s)%s;\n\t\t%s->length=%s;\n\t\t%s->arr=(%s*)(STG_OFFSET(%s, VECTOR_HEADER_BYTES));\n\t\t%s %s = %s;\n\t\tfor(int %s = 0; %s < %s->length; %s++){\n\t\t\t%s\n\t\t\t%s = STG_OFFSET(%s, %s);\n\t\t}"
             resultType resultName resultType storage 
             resultName lengthCode
             resultName elemType resultName
             stType stCode stLocation
             idxCode idxCode resultName idxCode
             bodyCode
             stCode stCode stOffset
             , bodyClosures, true)
        | DerivedPatterns.SpecificCall <@ corelang.foldOnRange @> (_, [ta], _) ->
          let (Patterns.Lambda(num, Patterns.Lambda(idx, body))) = elist.[0]
          let idxCode = idx.Name
          let resultType = ccodegenType ta
          let resultName = var.Name
          let initCode = ccodegen (elist.[1])
          let startCode = ccodegen (elist.[2])
          let endCode = ccodegen (elist.[3])
          let (bodyCode, bodyClosures) = ccodegenStatements "\t\t" (body.Substitute(fun v -> if v = num then Some(Expr.Var(var)) else None)) None
          (sprintf "%s %s = %s;\n\tfor(int %s = %s; %s < %s; %s++){\n\t\t%s\n\t}"
             resultType resultName initCode 
             idxCode startCode idxCode endCode idxCode
             bodyCode
             , bodyClosures, true)
        | DerivedPatterns.SpecificCall <@ corelang.foldOnRange_dps @> (_, [ta; tac], _) ->
              // TODO not memory safe yet
              let storage = ccodegen (elist.[0])
              let (LambdaN(inputs, body)) = elist.[1]
              let st = inputs.[0]
              let num = inputs.[1]
              let idx = inputs.[2]
              let numShp = inputs.[3]
              let idxCode = idx.Name
              let resultType = ccodegenType (var.Type)
              let resultName = var.Name
              let initCode = ccodegen (elist.[2])
              let startCode = ccodegen (elist.[3])
              let endCode = ccodegen (elist.[4])
              let stCode = st.Name
              let stType = ccodegenType st.Type
              let (bodyCode, bodyClosures) = 
                ccodegenStatements "\t\t" (body.Substitute(fun v -> if v = num then Some(Expr.Var(var)) else if v = numShp then Some(elist.[6]) else  None)) None
              (sprintf "%s %s = %s;\n\t%s %s = %s;\n\tfor(int %s = %s; %s < %s; %s++){\n\t\t%s\n\t}"
                 resultType resultName initCode 
                 stType stCode storage
                 idxCode startCode idxCode endCode idxCode
                 bodyCode
                 , bodyClosures, true)
        | DerivedPatterns.SpecificCall <@ corelang.newArray_s @> (_, [tp], [stg; arr]) ->
          // TODO use the provided storage of each element
          let elems = 
            match arr with 
            | Patterns.Let(x1, Patterns.NewArray(_, elems), Patterns.Var(x2)) when x1 = x2 -> elems
            | Patterns.NewArray(_, elems) -> elems
            | _ -> failwithf "Cannot generate C code for newArray_s with elems `%A`" arr
          // TODO handle the case of newArray_s of newArray_s
          let stgCode = ccodegen stg
          let elemsNoStg = elems |> List.map (fun (Patterns.Lambda(s, body)) -> body)
          let offsetVar = sprintf "%s_offsetVar" stgCode
          let (elementsInitCode, closures) = 
            if tp = typeof<Number> then
              //let code = String.concat "\n\t" (elems |> List.mapi (fun index (Patterns.Lambda(s, elem)) -> sprintf "%s->arr[%d] = %s;" var.Name index (ccodegen elem)))
              //(code, [])
              elems |> List.mapi (fun index (Patterns.Lambda(s, elem)) ->
                ccodegenStatements "\n\t" elem (Some(sprintf "%s->arr[%d]" var.Name index))
              ) |> List.fold (fun (accCode, accClosure) (code, closure) -> 
                   accCode + code, List.append accClosure closure
              ) ("", [])
            else 
              elems |> List.mapi (fun index (Patterns.Lambda(s, elem)) ->
                let (bodyCode, bodyClosures) = ccodegenStatements "\n\t" elem (Some(sprintf "%s->arr[%d]" var.Name index))
                let stInit = sprintf "%s %s = STG_OFFSET(%s, MATRIX_HEADER_BYTES(%d) + %s);" (ccodegenType s.Type) s.Name stgCode elems.Length offsetVar
                let offsetUpdate = sprintf "%s += VECTOR_ALL_BYTES(%s->arr[%d]->length);" offsetVar var.Name index 
                (stInit + bodyCode + offsetUpdate, bodyClosures)
              ) |> List.fold (fun (accCode, accClosure) (code, closure) -> 
                accCode + code, List.append accClosure closure
              ) (sprintf "int %s = 0;" offsetVar, [])
          let arrTp = ccodegenType (tp.MakeArrayType()) 
          let elemTp = ccodegenType tp
          let rhs = sprintf "(%s)%s;\n\t%s->length=%d;\n\t%s->arr=(%s*)(STG_OFFSET(%s, VECTOR_HEADER_BYTES));\n\t%s" 
                      arrTp stgCode 
                      var.Name elems.Length
                      var.Name elemTp stgCode
                      elementsInitCode
          (rhs, closures, false)
        | DerivedPatterns.SpecificCall <@ corelang.alloc @> (_, [tres], [sizeExpr; cont]) ->
          let size = 
            match sizeExpr with
            | Patterns.Let(x, _, Patterns.Var(x2)) as sizeExpr when x = x2 -> fst (ccodegenStatements "\t" sizeExpr None)
            | sizeExpr -> ccodegen sizeExpr
          let (Patterns.Lambda(i, body)) = cont
          let tp = ccodegenType typeof<Vector>
          let storageVar = i.Name 
          let (bodyCode, bodyClosures) = ccodegenStatements "\t" body None
          let resultCode = 
            let bodyAssignment =
              if tres = typeof<unit> then
                bodyCode
              else 
                sprintf "%s %s;%s" (ccodegenType tres) var.Name bodyCode
            let sizeVar = newVar "size"
            let sizeTp = ccodegenType typeof<Cardinality>
            sprintf "%s %s = %s;\n\t%s %s = storage_alloc(%s);\n\t%s\n\tstorage_free(%s, %s);" 
              sizeTp sizeVar size
              tp storageVar sizeVar 
              bodyAssignment storageVar sizeVar
          (resultCode,
            bodyClosures, true)
        | _ ->
          failwithf "Does not know how to generate C macro code for the method `%s`" name
      | _ ->
        failwithf "Does not know how to generate C macro code for the expression `%A`" e
  let (rhs, funs, includesLhs) = 
    match e with 
    | Patterns.NewArray(tp, elems) -> 
      let args = String.concat "\n\t" (List.mapi (fun index elem -> sprintf "%s->arr[%d] = %s;" var.Name index (ccodegen elem)) elems)
      let arrTp = ccodegenType (tp.MakeArrayType()) 
      let elemTp = (ccodegenType tp)
      let rhs = sprintf "(%s)storage_alloc(sizeof(int) * 2);\n\t%s->length=%d;\n\t%s->arr = (%s*)storage_alloc(sizeof(%s) * %d);\n\t%s" 
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
      let lambdaCode = withEnvNumber id (fun idx -> ccodegenFunction (Expr.Lambda(envVar, lamBody)) lambdaName true)
      (sprintf "%s; %s %s = make_closure(%s, &%s);" makeEnvStatement (ccodegenType var.Type) (var.Name)  lambdaName makeEnvVar, 
        [envStruct; makeEnvDef; lambdaCode], 
        true)
    | Patterns.IfThenElse(cond, e1, e2) ->
      let (e1code, e1closures) = ccodegenStatements "\t\t" e1 None
      let (e2code, e2closures) = ccodegenStatements "\t\t" e2 None
      let initValue = if(isScalarType (var.Type)) then "= 0" else ""
      (sprintf "%s %s %s;\n\tif(%s) {\n\t\t%s\n\t} else {\n\t\t%s\n\t}"
        (ccodegenType var.Type) (var.Name) initValue (ccodegen cond) e1code e2code, List.append e1closures e2closures, true)
    (*
    | IterateNumberDPS(f, elist) ->
        //let (Patterns.Lambda(num, Patterns.Lambda(idx, body))) = elist.[1]
        let (LambdaN(inputs, body)) = elist.[1]
        let num = inputs.[1]
        let idx = inputs.[2]
        let idxCode = idx.Name
        let resultType = ccodegenType (var.Type)
        let resultName = var.Name
        let initCode = ccodegen (elist.[2])
        let startCode = ccodegen (elist.[3])
        let endCode = ccodegen (elist.[4])
        let (bodyCode, bodyClosures) = ccodegenStatements "\t\t" (body.Substitute(fun v -> if v = num then Some(Expr.Var(var)) else None)) None
        (sprintf "%s %s = %s;\n\tfor(int %s = %s; %s <= %s; %s++){\n\t\t%s\n\t}"
           resultType resultName initCode 
           idxCode startCode idxCode endCode idxCode
           bodyCode
           , bodyClosures, true)
           *)
    | Patterns.Call (None, op, elist) when isMacro op -> 
      if isLetBoundMacro op then
        ccodegenMacro e
      else
        (ccodegenMonomorphicMacro e, [], false)
    | _ -> 
      (ccodegen e, [], false)
  if(includesLhs) then 
    (rhs, funs) 
  else if (e.Type = typeof<Unit>) then
    (sprintf "%s;" rhs, funs)
  else
    let typeAnnotation = if withTypeDef then sprintf "%s " (ccodegenType var.Type) else ""
    (sprintf "%s%s = %s;" typeAnnotation var.Name rhs, funs)

(* C code generation for a function *)
and ccodegenFunction (e: Expr) (name: string) (isForClosure: bool): string =
  let rec extractHeader exp curInputs statements = 
    match exp with 
    | LambdaN (inputs, body) -> extractHeader body (List.append curInputs inputs) statements
    | Patterns.Let(x, e1, e2) -> extractHeader e2 curInputs (List.append statements [(x, e1)])
    | _ -> (exp, curInputs, statements)
  let (result, inputs, statements) = extractHeader e [] []
  let (statementsCodeList, closuresList) = List.unzip (List.map (ccodegenStatement true) statements)
  let statementsCode = (String.concat "\n\t" statementsCodeList)
  let closuresCode = (String.concat "\n" (List.concat closuresList))
  let resultType = if(isForClosure) then "value_t" else ccodegenType(result.Type)
  let parameters = 
    inputs |> List.map (fun (x: Var) -> 
      (
        if (x.Type = typeof<unit>) then 
          "int" 
        else 
          ccodegenType(x.Type)
      ) + " " + x.Name
    ) |> String.concat ", " 
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
  let preprocessed = ctransformer.cpreprocess e
  if debug then printfn "/* Preprocessed code:\n%A\n*/\n" (prettyprint preprocessed)
  let generated = ccodegenFunction preprocessed name false
  if debug then printfn "// Generated C code for %s:\n\n%s" name generated
  generated