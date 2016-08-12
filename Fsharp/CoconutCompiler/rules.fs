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

let indexToDoubleToInt_exp = 
  <@ 
    int (double %k)
    <==>
    %k
  @>

let vectorBuildGet_exp = 
  <@
    (vectorBuild %k %F).[%i]
    <==>
    (%F) %i
  @>

let vectorBuildLength_exp = 
  <@
    (vectorBuild %k %F).Length
    <==>
    %k
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

let assocSubAddIndex_exp = 
  <@
    (%i - %j) + %k
    <==>
    %i - (%j - %k)
  @>

let assocSubSubIndex_exp = 
  <@
    (%i - %j) - %k
    <==>
    %i - (%j + %k)
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

let constFoldN0Index_exp = 
  <@ 
    %i - 0
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

let vectorFoldBuildToFoldOnRange_exp = 
  <@
    vectorFoldNumber %F %a (vectorBuild %k %G)
    <==>
    linalg.iterateNumber (fun acc idx -> (%F) acc ((%G) idx)) %a 0 (%k - 1)
  @>

let vectorBuildToStorage_exp = 
  <@
    vectorBuild (%k) (%F)
    <==>
    (let s = vectorAlloc (%k) in vectorBuildGivenStorage s (%F))
  @>

let vectorAddToStorage_exp = 
  <@
    linalg.add_vec %U %V
    <==>
    (let s2 = vectorAlloc ((%U).Length) in linalg.add_vecGivenStorage s2 %U %V)
  @>

let letVectorBuildLength_exp =
  <@
    (
      let x = (vectorBuild %k %F)
      ((%B1) x.Length x): T1
    )
    <==>
    (
      let x = (vectorBuild %k %F)
      (%B1) %k x
    )
  @>

let letInliner_exp = 
  <@
    ((let x = %E1 in (%B1) x): T1)
    <==>
    (%B1) %E1
  @>

let letMerging_exp = 
  <@
    (
      let x: T1 = %E1
      let y: T1 = %E1
      ((%B1) x y): T2
    )
    <==>
      let x: T1 = %E1
      (%B1) x x
  @>

let letCommutingConversion_exp = 
  <@
    (
      let x: T1 = 
        let y: T2 = %E1
        (%B1) y
      ((%B2) x): T3
    )
    <==>
      let y: T2 = %E1
      let x: T1 = (%B1) y
      (%B2) x
  @>

let letReorder_exp = 
  <@
    (
      let x: T1 = %E1
      let y: T2 = %E2
      ((%B1) x y): T3
    )
    <==>
      let y: T2 = %E2
      let x: T1 = %E1
      ((%B1) x y): T3
  @>


// TODO does not take into account the preconditions
let allocToCPS_exp =
  <@
    (
      let s = vectorAlloc %k
      ((%B1) s): T1
    )
    <==>
    (
      vectorAllocCPS %k (fun s -> (%B1) s)
    )
  @>

// FIXME does not work
let letFloatOutwards_exp = 
  <@
    (
      //((%B1) (let x: T1 = %E1 in x)): T2
      (%B1) (%E1: T1): T2
    )
    <==>
    (
      let x: T1 = %E1
      (%B1) x
    )
  @>

let letVectorBuildLength: Rule = compilePatternToRule (letVectorBuildLength_exp)

let letInliner: Rule = compilePatternToRule (letInliner_exp)

let letMerging: Rule = compilePatternToRule (letMerging_exp)

let letCommutingConversion: Rule = compilePatternToRule (letCommutingConversion_exp)

let letReorder: Rule = compilePatternToRule (letReorder_exp)

let allocToCPS: Rule = compilePatternToRule (allocToCPS_exp)

let algebraicRulesScalar_exp = [divide2Mult_exp; distrMult_exp; constFold0_exp; constFold1_exp; subSame_exp; multDivide_exp; assocAddSub_exp; assocAddAdd_exp; assocSubSub_exp]

let algebraicRulesScalar: Rule List = List.map compilePatternToRule algebraicRulesScalar_exp

let algebraicRulesVector_exp = [vectorBuildGet_exp.Raw; vectorSliceToBuild_exp.Raw]

let algebraicRulesVector: Rule List = List.map compilePatternToRule algebraicRulesVector_exp

open transformer
open FSharp.Quotations.Evaluator
open types

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

/// This rule is composition of one application of lambdaAppToLet and several applications of letInliner
let betaReduction (e: Expr): Expr Option = 
  match e with
  | AppN(LambdaN(inputs, body), args) when (List.length inputs) = (List.length args) -> 
      let inputsAndArgs = List.zip inputs args
      let renamedBody = captureAvoidingSubstitution body inputsAndArgs
      Some(renamedBody)
  | _ -> None

/// This rule is composition of one application of methodDefToLambda and lambdaAppToLet followed
/// by several applications of letInliner.
let methodDefInliner (e: Expr): Expr Option = 
  match e with
  | ExistingCompiledMethodWithLambda(methodName, moduleName, args, LambdaN(inputs, body)) when (List.length inputs) = (List.length args) -> 
    let inputsAndArgs = List.zip inputs args
    let renamedBody = captureAvoidingSubstitution body inputsAndArgs
    Some(renamedBody)
  | _ -> None

// TODO requires support for unacceptable cases
let letIntroduction (e: Expr): Expr option =
  match e with
  | Patterns.Let(x, e1, e2) -> None
  | Patterns.Lambda(_, _) -> None
  | Patterns.Var(_) -> None
  | Patterns.Value(_, _) -> None
  | _ -> 
    let nv = new Var(utils.newVar "xi_", e.Type)
    Some(Expr.Let(nv, e, Expr.Var(nv)))

// TODO requires meta programming facilities to be expressible in the rewrite engine.
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
      let resultObject = e.EvaluateUntyped()
      let resultExpression = Expr.Value(resultObject, e.Type)
      Some(resultExpression)
    else
      None
  | _ -> None

// TODO quotation syntax requires supproting certain corner cases on pattern matching in quotations
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

// TODO quotation syntax requires supproting handling a list of arguments and accessing their size
///  [| e1; ...; eN |].length --> N
let newArrayLength (e: Expr): Expr option =
  match e with
  | Patterns.PropertyGet(Some(Patterns.NewArray(tp, elems)), prop, []) when prop.Name = "Length"  -> 
    Some(Expr.Value(elems.Length))
  | _ -> None

// TODO quotation syntax requires checking conditions whether something is constant or not
/// vectorAlloc size --> vectorAllocOnStack size (if size is statically known is < 10)
let allocToAllocOnStack (e: Expr): Expr option =
  match e with
  | DerivedPatterns.SpecificCall <@ corelang.vectorAlloc @> (_, _, [Patterns.Value(v, _) as value])  ->
    let lengthValue = unbox<int> v
    if lengthValue < 10 then
      Some(<@@ corelang.vectorAllocOnStack (%%value) @@>)
    else
      None
  | _ -> None

// c.f.  "Let-floating: moving bindings to give faster programs", SPJ et. al., ICFP'96
//  specially section 3.2 (full laziness)
let foldInvariantCodeMotion (e: Expr): Expr option = 
  match e with
  // TODO generalize
  | DerivedPatterns.SpecificCall <@ linalg.iterateNumber @> (_, _, [f; z; st; en]) ->
    match f with
    | LambdaN(inputs, body) ->
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
  | ExprShape.ShapeLambda(x, Patterns.Let(y, e1, e2)) when e1.GetFreeVars() |> Seq.exists (fun fv -> fv = x) |> not ->
    Some(Expr.Let(y, e1, Expr.Lambda(x, e2)))
  | _ -> None
