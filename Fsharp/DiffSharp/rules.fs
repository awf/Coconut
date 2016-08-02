module rules

open Microsoft.FSharp.Quotations
open ruleengine
open metaVars
open corelang


let divide2Mult_exp = 
  <@ 
    (%a / %b) / %c
    <==> 
    %a / (%b * %c)
  @>

let distrMult_exp = 
  <@
    %a * (%b + %c)
    <==>
    %a * %b + %a * %c
  @>

let constFold0_exp = 
  <@ 
    %a + 0.
    <==>
    %a
  @>

let constFold1_exp = 
  <@ 
    %a * 1.
    <==>
    %a
  @>

let subSame_exp = 
  <@
    %a - %a
    <==>
    0.0
  @>

let multDivide_exp = 
  <@
    %a * (%b / %a)
    <==>
    %b
  @>

let assocAddSub_exp = 
  <@
    (%a + %b) - %c
    <==>
    %a + (%b - %c)
  @>

let assocAddAdd_exp = 
  <@
    (%a + %b) + %c
    <==>
    %a + (%b + %c)
  @>

let assocSubSub_exp = 
  <@
    (%a - %b) - %c
    <==>
    %a - (%b + %c)
  @>

let vectorBuildGet_exp = 
  <@
    (vectorBuild %k %FIN).[%i]
    <==>
    (%FIN) %i
  @>

let comAddIndex_exp = 
  <@
    %i + %j
    <==>
    %j + %i
  @>

let assocAddSubIndex_exp = 
  <@
    (%i + %j) - %k
    <==>
    %i + (%j - %k)
  @>

let subSameIndex_exp = 
  <@
    %i - %i
    <==>
    0
  @>

let constFold0Index_exp = 
  <@ 
    %i + 0
    <==>
    %i
  @>

// FIXME doesn't work
let vectorSliceToBuild_exp = 
  <@
    (%V).[(%i)..(%j)]
    <==>
    vectorBuild (%j - %i + 1) (fun i -> (%V).[i])
  @>

let vectorBuildToStorage_exp = 
  <@
    vectorBuild (%k) (%FIN)
    <==>
    (let s = vectorAlloc (%k) in vectorBuildGivenStorage s (%FIN))
  @>

let vectorAddToStorage_exp = 
  <@
    linalg.add_vec %U %V
    <==>
    (let s2 = vectorAlloc ((%U).Length) in linalg.add_vecGivenStorage s2 %U %V)
  @>

let algebraicRulesScalar_exp = [divide2Mult_exp; distrMult_exp; constFold0_exp; constFold1_exp; subSame_exp; multDivide_exp; assocAddSub_exp; assocAddAdd_exp; assocSubSub_exp]

let algebraicRulesScalar: Rule List = List.map compilePatternToRule algebraicRulesScalar_exp

let algebraicRulesVector_exp = [vectorBuildGet_exp.Raw; vectorSliceToBuild_exp.Raw]

let algebraicRulesVector: Rule List = List.map compilePatternToRule algebraicRulesVector_exp

open transformer

let letInliner (e: Expr): Expr Option = 
  match e with 
  | Patterns.Let(v, e1, e2) -> 
    let inlinedBody = e2.Substitute(fun v2 -> if v = v2 then Some(e1) else None)
    let renamedBody = variableRenaming inlinedBody []
    //let renamedBody = inlinedBody
    Some(renamedBody)
  | _ -> None

let methodDefToLambda (e: Expr): Expr Option = 
  match e with
  | ExistingCompiledMethodWithLambda(methodName, moduleName, args, lam) -> 
      Some(Expr.Applications(lam, List.map (fun x -> [x]) args))
  | _ -> None

let lambdaAppToLet (e: Expr): Expr Option = 
  match e with
  | AppN(LambdaN(inputs, body), args) when (List.length inputs) = (List.length args) -> 
      Some(LetN(List.zip inputs args, body))
  | _ -> None

let constantFold (e: Expr): Expr Option =
  match e with
  | Patterns.Call(None, op, args) ->
    let staticArgs = 
      List.collect (fun arg -> 
        match arg with
        | Patterns.Value(v, vp) -> [v]
        | _ -> []
      ) args
    
    if (List.length staticArgs) = (List.length args) then
      let resultObject = op.Invoke(null, List.toArray staticArgs)
      let resultExpression = Expr.Value(resultObject, e.Type)
      Some(resultExpression)
    else
      None
  | _ -> None

open types

let vectorSliceToBuild (e: Expr): Expr option =
  match e with
  | Patterns.Call (None, op, elist) -> 
    match op.Name with
    | "GetArraySlice" when e.Type = typeof<Vector> -> 
      let args = 
        List.map (fun x -> 
          match x with 
          | Patterns.NewUnionCase(_, [v]) -> v
          | _ -> x) elist
      let vec = Expr.Cast<Vector>(args.[0])
      let s = Expr.Cast<Index>(args.[1])
      let e = Expr.Cast<Index>(args.[2])
      Some(<@ vectorBuild (%e - %s + 1) (fun i -> (%vec).[i + %s]) @>.Raw)
    | _ -> None
  | _ -> None

let letVectorBuildLength (e: Expr): Expr option =
  match e with
  | Patterns.Let (x, (DerivedPatterns.SpecificCall <@ vectorBuild @> (_, _, [size; f]) as buildExpr), e2) -> 
    let rec findLength(exp: Expr): (Expr * (Expr -> Expr)) option = 
      match exp with
      | Patterns.PropertyGet(Some(arr), prop, []) when prop.Name = "Length" && arr = Expr.Var(x) -> 
        Some(size, fun i -> i)
      | ExprShape.ShapeLambda(input, body) ->
        findLength body
        |> Option.map (fun (l, f) -> l, fun i -> Expr.Lambda(input, f(i)))
      | ExprShape.ShapeVar(v) -> None
      | ExprShape.ShapeCombination(op, args) ->
        let transformedArg = 
          args 
          |> List.mapi (fun idx arg ->
               findLength(arg)
               |> Option.map (fun (e, f) -> idx, e, f)
             )
          |> List.tryPick id
        transformedArg 
        |> Option.map (fun (idx, e, f) ->         
             e, (fun i -> 
                  let transformedArgs = 
                    args
                    |> List.mapi (fun idx2 arg ->
                         if(idx2 = idx) then
                           f(i)
                         else
                           arg
                       )
                  ExprShape.RebuildShapeCombination(op, transformedArgs)
                )
           )
    findLength(e2)
    |> Option.map (fun (te, tf) ->
         Expr.Let (x, buildExpr, tf(te))
       )
  | _ -> None

// c.f. "Compiling with Continuations, Continued", Andrew Kennedy, ICFP'07
let letCommutingConversion (e: Expr): Expr Option = 
  match e with 
  | Patterns.Let(v, Patterns.Let(v2, e1, e2), e3) -> 
    Some(Expr.Let(v2, e1, Expr.Let(v, e2, e3)))
  | _ -> None

let letReorder (e: Expr): Expr Option = 
  match e with 
  | Patterns.Let(v, e1, Patterns.Let(v2, e2, e3)) when not (Seq.exists (fun x -> x = v) (e2.GetFreeVars())) -> 
    Some(Expr.Let(v2, e2, Expr.Let(v, e1, e3)))
  | _ -> None

// c.f.  "Let-floating: moving bindings to give faster programs", SPJ et. al., ICFP'96
//  specially section 3.2 (full laziness)
let foldInvariantCodeMotion (e: Expr): Expr option = 
  match e with
  // TODO generalize
  | DerivedPatterns.SpecificCall <@ linalg.iterateNumber @> (_, _, [f; z; st; en]) ->
    match f with
    | LambdaN(inputs, body) ->
      (*
      let rec findInvariant (exp: Expr) (boundVars: Var list): (Var * Expr) option = 
        match exp with
        | Patterns.Let(x, e1, e2) ->
          if(not (List.exists (fun e -> List.exists (fun e2 -> e = e2) boundVars) (List.ofSeq (e1.GetFreeVars())))) then
            Some(x, e1)
          else
            match findInvariant e1 boundVars with
            | Some(v) -> Some(v)
            | None    -> findInvariant e2 (x::boundVars)
        | LambdaN(inputs, body) ->
          findInvariant body (inputs @ boundVars)
        | ExprShape.ShapeVar(v) -> None
        | ExprShape.ShapeCombination(_, args) ->
          match List.choose(fun x -> findInvariant x boundVars) args with
          | hd :: tl -> Some(hd)
          | _        -> None
      Option.map (snd) (findInvariant body inputs)
      *)
      match body with
      | Patterns.Let(x, e1, e2) ->
        if(not (List.exists (fun e -> List.exists (fun y -> e = y) inputs) (List.ofSeq (e1.GetFreeVars())))) then
          let (Patterns.Call(_, mi, _)) = e
          Some(Expr.Let(x, e1, Expr.Call(mi, [LambdaN(inputs, e2); z; st; en])))
        else
          None
      | _ -> None
    | _ -> failwithf "The first argument of a fold function should be a lambda expression, but is `%A` instead." f
  | _ -> None

// TODO this one and the previous can be merged
// c.f.  "Let-floating: moving bindings to give faster programs", SPJ et. al., ICFP'96
//  specially section 3.2 (full laziness)
let letFloatOutwards (e: Expr): Expr option = 
  match e with
  | ExprShape.ShapeCombination(op, args) ->
    let transformedArg = 
      args 
      |>  List.mapi (fun idx a -> 
            match a with
            | Patterns.Let(x, e1, e2) ->
              Some(idx, x, e1, e2)
            | _ ->
              None
          )
      |>  List.tryPick id
    transformedArg
      |>  Option.map (fun (idx, x, e1, e2) ->
            let transformedArgs = 
              args
              |>  List.mapi (fun idx2 arg ->
                    if idx = idx2 then
                      e2
                    else
                      arg
                  )
            Expr.Let(x, e1, ExprShape.RebuildShapeCombination(op, transformedArgs))
          )
  | _ -> None
              
let allocToCPS (e: Expr): Expr option = 
  match e with
  | Patterns.Let(x, (DerivedPatterns.SpecificCall <@ corelang.vectorAlloc @> (_, _, [s]) as e1), e2) when (e2.Type = typeof<unit>) ->
    let cpsCall = <@ corelang.vectorAllocCPS @>
    let (LambdaN(_, Patterns.Call(None, op, _))) = cpsCall
    Some(Expr.Call(op, [s; Expr.Lambda(x, e2)]))
  | _ -> None
