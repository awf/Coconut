module rules

open Microsoft.FSharp.Quotations
open ruleengine
open metaVars
open corelang
open types
open cardinality


let divide2Mult_exp        = <@ (%a / %b) / %c             <==>   %a / (%b * %c)      @>
let distrMult_exp          = <@ %a * (%b + %c)             <==>   %a * %b + %a * %c   @>
let constFold0_exp         = <@ %a + 0.                    <==>   %a                  @>
let constFold1_exp         = <@ %a * 1.                    <==>   %a                  @>
let subSame_exp            = <@ %a - %a                    <==>   0.0                 @>
let multDivide_exp         = <@ %a * (%b / %a)             <==>   %b                  @>
let assocAddSub_exp        = <@ (%a + %b) - %c             <==>   %a + (%b - %c)      @>
let assocAddAdd_exp        = <@ (%a + %b) + %c             <==>   %a + (%b + %c)      @>
let assocSubSub_exp        = <@ (%a - %b) - %c             <==>   %a - (%b + %c)      @>
let indexToDoubleToInt_exp = <@ int (double %k)            <==>   %k                  @>
let vectorBuildGet_exp     = <@ (vectorBuild %c1 %F).[%i]   <==>   (%F) %i             @>
let vectorBuildLength_exp  = <@ (vectorBuild %c2 %F).Length <==>   %k                  @>
let comAddIndex_exp        = <@ %i + %j                    <==>   %j + %i             @>
let assocAddSubIndex_exp   = <@ (%i + %j) - %k             <==>   %i + (%j - %k)      @>
let assocSubAddIndex_exp   = <@ (%i - %j) + %k             <==>   %i - (%j - %k)      @>
let assocSubSubIndex_exp   = <@ (%i - %j) - %k             <==>   %i - (%j + %k)      @>
let subSameIndex_exp       = <@ %i - %i                    <==>   0                   @>
let constFold0Index_exp    = <@ %i + 0                     <==>   %i                  @>
let constFoldN0Index_exp   = <@ %i - 0                     <==>   %i                  @>
let dce_exp                = <@ ( let x = %E1 in %E2: T1 ) <==>   %E2                 @>
let vectorFoldBuildToFoldOnRange_exp = 
                             <@ fold<Number, Number> %F %a (vectorBuild %c1 %G)
                                                           <==>
                                linalg.iterateNumber (fun acc idx -> (%F) acc ((%G) idx)) %a (Card 0) (%c1 .- (Card 1))
                                                                                      @>
let vectorBuildToStorage_exp = 
                             <@ vectorBuild (%c1) (%F)      
                                                           <==>
                                (let s = vectorAlloc (%c1) in vectorBuildGivenStorage s (%F))
                                                                                      @>

let vectorAddToStorage_exp = <@ linalg.add_vec %U %V       
                                                           <==>
                                (let s2 = vectorAlloc (length %U) in linalg.add_vecGivenStorage s2 %U %V)
                                                                                      @>

let letVectorBuildLength_exp = 
                             <@ ( let x = (vectorBuild %c1 %F) in ((%B1) (length x) x): T1 )
                                                           <==>
                                ( let x = (vectorBuild %c1 %F) in (%B1) %c1 x )
                                                                                      @>

let letInliner_exp         = <@ ((let x = %E1 in (%B1) x): T1)
                                                           <==> (%B1) %E1             @>

let letMerging_exp         = <@ ( let x: T1 = %E1 in let y: T1 = %E1 in ((%B1) x y): T2 )
                                                           <==>
                                let x: T1 = %E1 in (%B1) x x
                                                                                      @>

let letCommutingConversion_exp 
                           = <@ ( let x: T1 = (let y: T2 = %E1 in (%B1) y) in ((%B2) x): T3 )
                                                           <==>
                                let y: T2 = %E1 in let x: T1 = (%B1) y in (%B2) x
                                                                                      @>

let letReorder_exp         = <@ ( let x: T1 = %E1 in let y: T2 = %E2 in ((%B1) x y): T3 )
                                                           <==>
                                let y: T2 = %E2 in let x: T1 = %E1 in ((%B1) x y): T3
                                                                                      @>

let copyLet_exp            = <@ ( vectorCopy %stg1 (let x = %E1 in (%B1) x) )
                                                           <==>
                                ( let x = %E1 in vectorCopy %stg1 ((%B1) x) )
                                                                                      @>

// FIXME doesn't work
(*
let vectorSliceToBuild_exp = <@
    (%V).[(%i)..(%j)]
    <==>
    vectorBuild (%j - %i + 1) (fun i -> (%V).[i])
  @>
*)


// TODO does not take into account the preconditions
let allocToCPS_exp =
  <@
    (
      let s = vectorAlloc %c1
      ((%B1) s): T1
    )
    <==>
    (
      vectorAllocCPS %c1 (fun s -> (%B1) s)
    )
  @>

// FIXME does not work
let letFloatOutwards_exp = <@
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



let letVectorBuildLength: Rule = compilePatternWithNameToRule letVectorBuildLength_exp "letVectorBuildLength"

let letInliner: Rule = compilePatternWithNameToRule letInliner_exp "letInliner"

let letMerging: Rule = compilePatternWithNameToRule letMerging_exp "letMerging"

let letCommutingConversion: Rule = compilePatternWithNameToRule letCommutingConversion_exp "letCommutingConversion"

let letReorder: Rule = compilePatternWithNameToRule letReorder_exp "letReorder"

let allocToCPS: Rule = compilePatternWithNameToRule allocToCPS_exp "allocToCPS"

let dce: Rule = compilePatternWithNameToRule dce_exp "dce"

let algebraicRulesScalar_exp = 
  [ <@ divide2Mult_exp @>; <@ distrMult_exp @>; <@ constFold0_exp @>; <@ constFold1_exp @>; <@subSame_exp@> ; 
    <@ multDivide_exp @>; <@ assocAddSub_exp @>; <@ assocAddAdd_exp @>; <@ assocSubSub_exp @> ]

let algebraicRulesScalar: Rule List = List.map compilePatternToRule algebraicRulesScalar_exp

//let algebraicRulesVector_exp = [ <@ vectorBuildGet_exp @>; <@ vectorSliceToBuild_exp @>]

//let algebraicRulesVector: Rule List = List.map compilePatternToRule algebraicRulesVector_exp

open transformer
open FSharp.Quotations.Evaluator
open types

let methodDefToLambda: Rule = 
  (fun (e: Expr) ->
    match e with
    | ExistingCompiledMethodWithLambda(methodName, moduleName, args, lam) -> 
        [Expr.Applications(lam, List.map (fun x -> [x]) args)]
    | _ -> []
  ), "methodDefToLambda"

let lambdaAppToLet: Rule = 
  (fun (e: Expr) ->
    match e with
    | AppN(LambdaN(inputs, body), args) when (List.length inputs) = (List.length args) -> 
        [LetN(List.zip inputs args, body)]
    | _ -> []
  ), "lambdaAppToLet"

/// This rule is composition of one application of lambdaAppToLet and several applications of letInliner
let betaReduction: Rule = 
  (fun (e: Expr) ->
    match e with
    | AppN(LambdaN(inputs, body), args) when (List.length inputs) = (List.length args) -> 
        let inputsAndArgs = List.zip inputs args
        let renamedBody = captureAvoidingSubstitution body inputsAndArgs
        [renamedBody]
    | _ -> []
  ), "betaReduction"

/// This rule is composition of one application of methodDefToLambda and lambdaAppToLet followed
/// by several applications of letInliner.
let methodDefInliner: Rule = 
  (fun (e: Expr) ->
    match e with
    | ExistingCompiledMethodWithLambda(methodName, moduleName, args, LambdaN(inputs, body)) when (List.length inputs) = (List.length args) -> 
      let inputsAndArgs = List.zip inputs args
      let renamedBody = captureAvoidingSubstitution body inputsAndArgs
      [renamedBody]
    | _ -> []
  ), "methodDefInliner"

// TODO requires support for unacceptable cases
let letIntroduction: Rule =
  (fun (e: Expr) ->
    match e with
    | Patterns.Let(x, e1, e2) -> []
    | Patterns.Lambda(_, _) -> []
    | Patterns.Var(_) -> []
    | Patterns.Value(_, _) -> []
    | _ -> 
      let nv = new Var(utils.newVar "xi_", e.Type)
      [Expr.Let(nv, e, Expr.Var(nv))]
  ), "letIntroduction"

// TODO requires meta programming facilities to be expressible in the rewrite engine.
let constantFold: Rule = 
  (fun (e: Expr) ->
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
        [resultExpression]
      else
        []
    | _ -> []
  ), "constantFold"

// TODO quotation syntax requires supproting certain corner cases on pattern matching in quotations
let vectorSliceToBuild: Rule = 
  (fun (e: Expr) ->
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
        [ <@ vectorBuild (((Card %e) .- (Card %s)) .+ (Card 1)) (fun i -> (%vec).[i + %s]) @>.Raw]
      | _ -> []
    | _ -> []
  ), "vectorSliceToBuild"

// TODO quotation syntax requires supproting handling a list of arguments and accessing their size
///  [| e1; ...; eN |].length --> N
let newArrayLength: Rule = 
  (fun (e: Expr) ->
    match e with
    | Patterns.PropertyGet(Some(Patterns.NewArray(tp, elems)), prop, []) when prop.Name = "Length"  -> 
      [Expr.Value(elems.Length)]
    | _ -> []
  ), "newArrayLength"

// TODO quotation syntax requires checking conditions whether something is constant or not
/// vectorAlloc size --> vectorAllocOnStack size (if size is statically known is < 10)
let allocToAllocOnStack: Rule = 
  (fun (e: Expr) ->
    match e with
    | DerivedPatterns.SpecificCall <@ corelang.vectorAlloc @> (_, _, [Patterns.Value(v, _) as value])  ->
      let lengthValue = unbox<int> v
      if lengthValue < 10 then
        [ <@@ corelang.vectorAllocOnStack (%%value) @@> ]
      else
        []
    | _ -> []
  ), "allocToAllocOnStack"

// TODO quotation syntax requires supporting conditionals rewrite rules
/// (\x1...xN e0) e1 ... eN ---> (\s0 x1...xN copy s0 e0) e1 ... eN (let s1 = e0.length in s1))
let lambdaAppStoraged: Rule = 
  (fun (e: Expr) ->
    match e with
    // TODO add support for matrix
    | AppN(LambdaN(inputs, body), args) when (List.length inputs) = (List.length args) && (List.head inputs).Type <> typeof<Storage> && 
       (e.Type = typeof<Vector> || e.Type = typeof<Matrix>) -> 
      let storageVarForLambda = new Var(utils.newVar "stg_input", typeof<Storage>)
      let storageVarForLambdaExp = Expr.Var(storageVarForLambda)
      let storageVarForApply = new Var(utils.newVar "stg", typeof<Storage>)
      let storageVarForApplyExp = Expr.Var(storageVarForApply)
      // TODO fix
      let sizeExpr = 
        // <@@ (%%e: Vector).Length @@>
        <@@ 1000 @@> 
      [AppN(LambdaN(storageVarForLambda :: inputs, <@@ vectorCopy %%storageVarForLambdaExp %%body @@>), (Expr.Let(storageVarForApply, <@@ vectorAlloc %%sizeExpr @@>, storageVarForApplyExp)) :: args) ]
    | _ -> []
  ), "lambdaAppStoraged"

let copyStoragedElimination: Rule = 
  (fun (e: Expr) ->
    let STORAGE_POSTFIX = "GivenStorage"
    match e with
    | DerivedPatterns.SpecificCall <@ corelang.vectorCopy @> (_, _, [s1; Patterns.Call(None, op, s2 :: args)]) when op.Name.EndsWith(STORAGE_POSTFIX) ->
      [Expr.Call(op, s1 :: args)]
    | _ -> []
  ), "copyStoragedElimination"

// c.f.  "Let-floating: moving bindings to give faster programs", SPJ et. al., ICFP'96
//  specially section 3.2 (full laziness)
let foldInvariantCodeMotion: Rule = 
  (fun (e: Expr) ->
    match e with
    // TODO generalize
    | DerivedPatterns.SpecificCall <@ linalg.iterateNumber @> (_, _, [f; z; st; en]) ->
      match f with
      | LambdaN(inputs, body) ->
        match body with
        | Patterns.Let(x, e1, e2) ->
          if(not (List.exists (fun e -> List.exists (fun y -> e = y) inputs) (List.ofSeq (e1.GetFreeVars())))) then
            let (Patterns.Call(_, mi, _)) = e
            [ Expr.Let(x, e1, Expr.Call(mi, [LambdaN(inputs, e2); z; st; en])) ]
          else
            []
        | _ -> []
      | _ -> failwithf "The first argument of a fold function should be a lambda expression, but is `%A` instead." f
    | _ -> []
  ), "foldInvariantCodeMotion"

// TODO this one and the previous can be merged
// c.f.  "Let-floating: moving bindings to give faster programs", SPJ et. al., ICFP'96
//  specially section 3.2 (full laziness)
let letFloatOutwards: Rule = 
  (fun (e: Expr) ->
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
          |> Option.toList
    | ExprShape.ShapeLambda(x, Patterns.Let(y, e1, e2)) when e1.GetFreeVars() |> Seq.exists (fun fv -> fv = x) |> not ->
      [ Expr.Let(y, e1, Expr.Lambda(x, e2)) ]
    | _ -> []
  ), "letFloatOutwards"
