﻿open System
open System.Diagnostics
open System.IO
open cruntime
open utils
open linalg
open corelang
open FSharp.Quotations
open types

let test_ba (argv: string[]) = 
    let fileName = argv.[0]
    let nmp = vectorRead fileName 0
    let n = Card (int nmp.[0])
    let m = Card (int nmp.[1])
    let p = Card (int nmp.[2])
    let res = usecases_ba.run_ba_from_file fileName n m p
    //matrixPrint res
    ()
 
let test_ruleengine () = 
    //let prog = <@ let x = 1 * 3 in x * 3 @>
    //let prog = <@ vectorFoldNumber (fun acc cur -> acc) 0.0 (vectorBuild 10 (fun i -> 2.)) @>
    //let prog' = ruleengine.compilePatternToRule (rules.vectorFoldBuildToFoldOnRange_exp) prog
    //let prog' = prog
    //let prog = <@ let y = 1 * 3 in y * 3 @>
    //let prog' = ruleengine.compilePatternToRule (rules.letInliner_exp ()) prog
    //let prog = <@ 8.0 - 0.0 - 2.0 @>
    //let prog' = ruleengine.compilePatternToRule (rules.assocSubSubIndex_exp) prog
    //let prog = <@ let i = 2 in vectorBuild 10 (fun i -> double i) @>
    //let prog' = rules.letInliner_old prog
    //let prog = <@ let i = 2 in let j = 2 in i / j @>
    //let prog' = rules.letMerging2 prog
    //let prog = <@ let b = vectorBuild 10 (fun i -> double i) in vectorBuild (b.Length) (fun j -> (add_vec b b).[j]) @>
    //let prog' = rules.letVectorBuildLength2 prog
    let prog = <@ let s = vectorAlloc (Card 10) in vectorBuildGivenStorage s (fun i -> 2.0) @>
    let prog' = ruleengine.applyRule rules.allocToCPS prog
    //let prog = <@ let i = 3 in let j = i * 2 in i / j @>
    //let prog' = rules.letReorder2 prog
    //let prog = <@ let i = 3 in let j = 2 in i / j @>
    //let prog' = rules.letReorder2 prog
    printfn "%A" prog'

let compile_modules () = 
    compiler.compileModule "linalg" [] false false
    compiler.compileModule "usecases_ba" ["linalg"] false false
    compiler.compileModule "usecases_ht" ["linalg"] false false
    compiler.compileModule "programs" ["linalg"] true false
    compiler.compileModule "ccodegentests" [] false false

let compile_modules_storaged () = 
    compiler.compileModule "linalg" [] false true
    compiler.compileModule "linalgtests" ["linalg"] false true
    compiler.compileModule "usecases_ba" ["linalg"] false true
    // compiler.compile "usecases" "run_ba_from_file" false true
    ()

let benchmark_search () =
    let bundleAdjustmentProject = compiler.getMethodExpr "usecases_ba" "project"
    benchmark.benchmark_test_algorithms bundleAdjustmentProject

let test_phase_based_optimizer () = 
    compiler.compileModule "linalg" [] false false
    compiler.compileModule "usecases_ba" ["linalg"] false false
    let bundleAdjustmentReprojErr = compiler.getMethodExpr "usecases_ba" "reproj_err"
    let recTrans rs = optimizer.recursiveTransformer rs |> optimizer.fixPoint 10
    let hurTrans rs = optimizer.heuristicOptimizer 1000 (rs |> List.map (fun r -> r, 1.0))
    let trans rs exp = 
      // let t = tic()
      let e = recTrans rs exp
      // toc t
      e
    let generateCodeForAllPhases (prog: Expr) (phases: ruleengine.Rule list list): unit = 
      let generateCodeUpToPhase (subPhases: ruleengine.Rule list list): unit = 
        let numPhases = subPhases |> List.length
        let headerName = sprintf "usecases_ba_%d" numPhases
        let methodName = sprintf "TOP_LEVEL_usecases_ba_reproj_err_%d" numPhases
        let transformed = 
          (prog, subPhases) ||> List.fold (fun acc rules -> trans rules acc)
        let result = transformed // |> fun x -> transformer.variableRenaming x []
        compiler.compileToHeaderFile headerName ["linalg"; "usecases_ba"] ([ccodegen.ccodegenTopLevel result methodName false])
      generateCodeUpToPhase []
      ([], phases) ||> List.fold (fun acc cur -> let nacc = acc @ [cur] in generateCodeUpToPhase nacc; nacc )
      // generateCodeUpToPhase phases
      ()
      
    // let time = tic()
    let opt = 
      bundleAdjustmentReprojErr 
        // |> trans [rules.methodDefToLambda; rules.lambdaAppToLet] 
        // |> trans [rules.vectorSliceToBuild] 
        |> trans [rules.methodDefToLambda; rules.lambdaAppToLet; rules.vectorSliceToBuild] 
        |> trans [rules_old.letCommutingConversion_old; rules_old.letNormalization_old]
        |> trans [rules_old.letVectorBuildLength_old; rules_old.letVectorBuildGet_old]
        // // |> trans [ruleengine.compilePatternToRule <@ rules.letBuild_exp @>]
        // // |> trans [ruleengine.compilePatternToRule <@ rules.vectorBuildGet_exp @>; 
        // //           ruleengine.compilePatternToRule <@ rules.vectorBuildLength_exp @>]
        |> trans [rules.lambdaAppToLet] 
        |> trans [rules_old.letCommutingConversion_old; rules_old.letNormalization_old]
        |> trans [rules_old.dce_old]
        // |> trans [ruleengine.compilePatternToRule <@ rules.letBuild_exp @>]
        // |> trans [ruleengine.compilePatternToRule <@ rules.vectorFoldBuildToFoldOnRange_exp @>]
        |> trans [ruleengine.compilePatternToRule <@ rules.letBuild_exp @>; 
                  ruleengine.compilePatternToRule <@ rules.vectorFoldBuildToFoldOnRange_exp @>]
        |> trans [rules.lambdaAppToLet] 
        |> trans [ruleengine.compilePatternToRule <@ rules.constFoldCardAdd_exp @>;
                     ruleengine.compilePatternToRule <@ rules.constFoldCardSub_exp @>] 
        |> trans [rules.constantFold; ruleengine.compilePatternToRule <@ rules.constFold0Index_exp @>] 
        // |> trans [rules.methodDefToLambda; rules.lambdaAppToLet; rules.vectorSliceToBuild] 
        // |> trans [rules_old.letCommutingConversion_old; rules_old.letNormalization_old]
        // |> trans [ruleengine.compilePatternToRule <@ rules.letBuild_exp @>]
        // |> trans [ruleengine.compilePatternToRule <@ rules.vectorBuildGet_exp @>; 
        //           ruleengine.compilePatternToRule <@ rules.vectorBuildLength_exp @>;
        //           ruleengine.compilePatternToRule <@ rules.vectorFoldBuildToFoldOnRange_exp @>]
        // |> trans [rules.lambdaAppToLet]
        // |> trans [rules_old.letCommutingConversion_old; rules_old.letNormalization_old]
        // |> trans [rules_old.dce_old]
        // |> trans [ruleengine.compilePatternToRule <@ rules.constFoldCardAdd_exp @>;
        //           ruleengine.compilePatternToRule <@ rules.constFoldCardSub_exp @>] 
        // |> trans [rules.constantFold; ruleengine.compilePatternToRule <@ rules.constFold0Index_exp @>]
        |> fun x -> transformer.variableRenaming x []
    let phases = 
      [
        [rules.methodDefToLambda; rules.lambdaAppToLet; rules.vectorSliceToBuild]; 
        [rules_old.letCommutingConversion_old; rules_old.letNormalization_old];
        // [ruleengine.compilePatternToRule <@ rules.letBuild_exp @>];
        // [ruleengine.compilePatternToRule <@ rules.vectorBuildGet_exp @>; 
        //  ruleengine.compilePatternToRule <@ rules.vectorBuildLength_exp @>;
        //  ruleengine.compilePatternToRule <@ rules.vectorFoldBuildToFoldOnRange_exp @>];
        [rules_old.letVectorBuildLength_old; rules_old.letVectorBuildGet_old];
        [rules.lambdaAppToLet];
        [rules_old.letCommutingConversion_old; rules_old.letNormalization_old];
        [rules_old.dce_old];
        [ruleengine.compilePatternToRule <@ rules.letBuild_exp @>; 
         ruleengine.compilePatternToRule <@ rules.vectorFoldBuildToFoldOnRange_exp @>];
        [rules.lambdaAppToLet];
        [ruleengine.compilePatternToRule <@ rules.constFoldCardAdd_exp @>;
         ruleengine.compilePatternToRule <@ rules.constFoldCardSub_exp @>]; 
        [rules.constantFold; ruleengine.compilePatternToRule <@ rules.constFold0Index_exp @>];
      ]
    generateCodeForAllPhases bundleAdjustmentReprojErr phases
    // // toc time
    // printfn "pretty code: %s" (ccodegen.prettyprint opt)
    printfn "C code: %s" (ccodegen.ccodegenTopLevel opt "usecases_ba_reproj_err_opt" false)

let test_guided_optimizer () = 
    compiler.compileModule "linalg" [] false false
    compiler.compileModule "usecases_ba" ["linalg"] false false
    let comp = ruleengine.compilePatternToRule
      //ruleengine.compilePatternToRule2
    let vecAdd3 = compiler.getMethodExpr "programs" "vector_add3"
    let chains = 
      optimizer.guidedOptimize vecAdd3 
        [ rules.methodDefToLambda, 0; 
          rules.lambdaAppToLet, 0;
          rules.letInliner, 0;
          rules.letInliner, 0;
          rules.methodDefToLambda, 0; 
          rules.lambdaAppToLet, 0;
          rules.letInliner, 0;
          rules.letInliner, 0;
          rules.letInliner, 0;
          rules.methodDefToLambda, 0; 
          rules.lambdaAppToLet, 0;
          rules.letInliner, 0;
          rules.letInliner, 0;
          rules.methodDefToLambda, 0; 
          rules.lambdaAppToLet, 0;
          rules.letInliner, 0;
          rules.letInliner, 0;
          rules.lambdaAppToLet, 0;
          rules.letInliner, 0;
          rules.letInliner, 0;
          rules.letInliner, 0;
          rules.lambdaAppToLet, 0;
          rules.letInliner, 0;
          rules.letInliner, 0;
          comp <@ rules.vectorBuildGet_exp @>, 0;
          rules.lambdaAppToLet, 0;
          rules.letInliner, 0;
          ]
    // printfn "vecAdd3 chains: %A" (String.concat "\n*****\n" (List.map ccodegen.prettyprint chains))
    let hoistingExample = compiler.getMethodExpr "programs" "hoistingExample"
    let chains = 
      optimizer.guidedOptimize hoistingExample 
        [ rules.vectorSliceToBuild, 0;
          comp <@ rules.comAddIndex_exp @>, 1;
          comp <@ rules.assocAddSubIndex_exp @>, 0;
          comp <@ rules.subSameIndex_exp @>, 0;
          comp <@ rules.constFold0Index_exp @>, 0;
          rules.constantFold, 0;
          comp <@ rules.vectorAddToStorage_exp @>, 0;
          rules.letVectorBuildLength, 0;
          rules.letFloatOutwards, 0;
          comp <@ rules.vectorBuildToStorage_exp @>, 0;
          rules.letCommutingConversion, 0;
          rules.foldInvariantCodeMotion, 0;
          rules.letCommutingConversion, 0;
          rules.allocToCPS, 0;
          rules.letFloatOutwards, 0;
          rules.letReorder, 0;
          rules.foldInvariantCodeMotion, 0;
          rules.letCommutingConversion, 0;
          rules.allocToCPS, 0;
        ]
    // printfn "hoistingExample chains: %A" (String.concat "\n*****\n" (List.map ccodegen.prettyprint chains))
    // printfn "hoistingExample costs: %A" (String.concat "\n" (List.map (fun x -> cost.fopCost(x).ToString()) chains))
    // printfn "code: %s" (ccodegen.ccodegenTopLevel (List.head (List.rev chains)) "hoistingExample" false)
    let stackExample = compiler.getMethodExpr "programs" "stackAllocExample"
    let chains = 
      optimizer.guidedOptimize stackExample 
        [ comp <@ rules.vectorAddToStorage_exp @>, 0;
          rules.letFloatOutwards, 0;
          rules.letInliner, 0;
          rules.newArrayLength, 0;
          rules.letIntroduction, 2;
          rules.letFloatOutwards, 1;
          rules.letIntroduction, 3;
          rules.letFloatOutwards, 2;
          rules.letMerging, 0;
          rules.letFloatOutwards, 1;
          rules.allocToAllocOnStack, 0;
        ]
    // printfn "stackExample chains: %A" (String.concat "\n*****\n" (List.map ccodegen.prettyprint chains))
    // printfn "stackExample costs: %A" (String.concat "\n" (List.map (fun x -> cost.fopCost(x).ToString()) chains))
    // printfn "code: %s" (ccodegen.ccodegenTopLevel (List.head (List.rev chains)) "stackExample" false)
    let storageConvertorExample = compiler.getMethodExpr "programs" "storageConvertorExample"
    let chains = 
      optimizer.guidedOptimize storageConvertorExample 
        [ rules.methodDefToLambda, 0;
          comp <@ rules.vectorBuildToStorage_exp @>, 0;
          rules.lambdaAppStoraged, 0;
          comp <@ rules.copyLet_exp @>, 0;
          rules.copyStoragedElimination, 0;
          rules.dce, 0;
        ]
    printfn "storageConvertorExample chains: %A" (String.concat "\n*****\n" (List.map ccodegen.prettyprint chains))
    // printfn "storageConvertorExample costs: %A" (String.concat "\n" (List.map (fun x -> cost.fopCost(x).ToString()) chains))
    printfn "code: %s" (ccodegen.ccodegenTopLevel (List.head (List.rev chains)) "storageConvertorExample" false)
    let bundleAdjustmentProject = compiler.getMethodExpr "usecases_ba" "project"
    let baProjectRules = 
        [ rules.vectorSliceToBuild, 0;
          comp <@ rules.comAddIndex_exp @>, 1;
          comp <@ rules.assocAddSubIndex_exp @>, 0;
          comp <@ rules.subSameIndex_exp @>, 0;
          comp <@ rules.constFold0Index_exp @>, 0;
          rules.constantFold, 0;
          rules.vectorSliceToBuild, 0;
          comp <@ rules.comAddIndex_exp @>, 2;
          comp <@ rules.assocAddSubIndex_exp @>, 0;
          comp <@ rules.subSameIndex_exp @>, 0;
          comp <@ rules.constFold0Index_exp @>, 0;
          rules.constantFold, 0;
          rules.vectorSliceToBuild, 0;
          comp <@ rules.comAddIndex_exp @>, 3;
          comp <@ rules.assocAddSubIndex_exp @>, 0;
          comp <@ rules.subSameIndex_exp @>, 0;
          comp <@ rules.constFold0Index_exp @>, 0;
          rules.constantFold, 0;
          rules.vectorSliceToBuild, 0;
          rules.constantFold, 0;
          rules.constantFold, 0;
          comp <@ rules.constFold0Index_exp @>, 0;
          rules.vectorSliceToBuild, 0;
          comp <@ rules.comAddIndex_exp @>, 4;
          comp <@ rules.assocAddSubIndex_exp @>, 0;
          comp <@ rules.subSameIndex_exp @>, 0;
          comp <@ rules.constFold0Index_exp @>, 0;
          rules.constantFold, 0;
          rules.methodDefInliner, 2;
          rules.methodDefInliner, 3;
          rules.methodDefInliner, 3;
          rules.betaReduction, 0;
          comp <@ rules.vectorBuildLength_exp @>, 0;
          comp <@ rules.vectorBuildGet_exp @>, 0;
          rules.betaReduction, 0;
          comp <@ rules.vectorBuildGet_exp @>, 0;
          rules.betaReduction, 0;
          comp <@ rules.vectorBuildGet_exp @>, 0;
          rules.betaReduction, 0;
          rules.methodDefInliner, 2;
          rules.methodDefInliner, 2;
          rules.methodDefInliner, 2;
          rules.betaReduction, 0;
          comp <@ rules.vectorBuildLength_exp @>, 0;
          comp <@ rules.vectorBuildGet_exp @>, 0;
          rules.betaReduction, 0;
          comp <@ rules.vectorBuildGet_exp @>, 0;
          rules.betaReduction, 0;
          comp <@ rules.vectorFoldBuildToFoldOnRange_exp @>, 0;
          rules.betaReduction, 0;
          rules.betaReduction, 0;
          rules.methodDefInliner, 4;
          rules.methodDefInliner, 4;
          rules.betaReduction, 0;
          comp <@ rules.vectorBuildLength_exp @>, 0;
          comp <@ rules.vectorBuildGet_exp @>, 0;
          rules.betaReduction, 0;
          rules.methodDefInliner, 3;
          rules.methodDefInliner, 3;
          rules.betaReduction, 0;
          comp <@ rules.vectorBuildLength_exp @>, 0;
          comp <@ rules.vectorBuildGet_exp @>, 0;
          rules.betaReduction, 0;
          rules.methodDefInliner, 3;
          rules.methodDefInliner, 3;
          rules.betaReduction, 0;
          comp <@ rules.vectorBuildLength_exp @>, 0;
          comp <@ rules.vectorBuildGet_exp @>, 0;
          rules.betaReduction, 0;
          rules.methodDefInliner, 3;
          rules.methodDefInliner, 3;
          rules.betaReduction, 0;
          comp <@ rules.vectorBuildGet_exp @>, 0;
          rules.betaReduction, 0;
          rules.letCommutingConversion, 0;
          rules.letCommutingConversion, 0;
          rules.letInliner, 9;
          comp <@ rules.vectorBuildGet_exp @>, 0;
          rules.betaReduction, 0;
        ]
    let chains = 
      optimizer.guidedOptimize bundleAdjustmentProject baProjectRules
    //printfn "usecases_project chains: %A" (String.concat "\n*****\n" (List.map ccodegen.prettyprint chains))
    //printfn "usecases_project costs: %A" (String.concat "\n" (List.map (fun x -> cost.fopCost(x).ToString()) chains))
    //printfn "usecases_project code: %s" (ccodegen.ccodegenTopLevel (List.head (List.rev chains)) "usecases_project" false)
    let bundleAdjustmentReproj_err = compiler.getMethodExpr "usecases_ba" "reproj_err"
    let chains = 
      optimizer.guidedOptimize bundleAdjustmentReproj_err 
        [ 
          rules.letInliner, 0;
          rules.letInliner, 0;
          rules.letInliner, 0;
          rules.methodDefInliner, 1;
          rules.methodDefInliner, 0;
          rules.methodDefInliner, 0;
          comp <@ rules.vectorBuildLength_exp @>, 0;
          rules.lambdaAppToLet, 0;
          rules.letInliner, 0;
          rules.methodDefInliner, 3;
          comp <@ rules.vectorBuildGet_exp @>, 0;
          rules.lambdaAppToLet, 0;
          rules.letInliner, 0;
          comp <@ rules.indexToDoubleToInt_exp @>, 0;
          comp <@ rules.comAddIndex_exp @>, 1;
          comp <@ rules.constFold0Index_exp @>, 0;
          comp <@ rules.assocSubSubIndex_exp @>, 0;
          comp <@ rules.constFold0Index_exp @>, 0;
          comp <@ rules.assocSubAddIndex_exp @>, 0;
          rules.constantFold, 0;
          comp <@ rules.constFoldN0Index_exp @>, 0;
          rules.methodDefInliner, 3;
          comp <@ rules.vectorBuildGet_exp @>, 0;
          rules.lambdaAppToLet, 0;
          rules.letInliner, 0;
          comp <@ rules.indexToDoubleToInt_exp @>, 0;
          comp <@ rules.comAddIndex_exp @>, 0;
          comp <@ rules.constFold0Index_exp @>, 0;
          rules.methodDefInliner, 3;
          comp <@ rules.vectorBuildGet_exp @>, 0;
          rules.lambdaAppToLet, 0;
          rules.letInliner, 0;
          comp <@ rules.indexToDoubleToInt_exp @>, 0;
          comp <@ rules.comAddIndex_exp @>, 0;
          comp <@ rules.constFold0Index_exp @>, 0;
          rules.methodDefInliner, 3;
          comp <@ rules.vectorBuildGet_exp @>, 0;
          rules.lambdaAppToLet, 0;
          rules.letInliner, 0;
          comp <@ rules.indexToDoubleToInt_exp @>, 0;
          comp <@ rules.comAddIndex_exp @>, 0;
          comp <@ rules.constFold0Index_exp @>, 0;
          rules.methodDefInliner, 0;
          rules.methodDefInliner, 1;
          rules.methodDefInliner, 1;
          rules.lambdaAppToLet, 0;
          rules.letInliner, 0;
          rules.letInliner, 0;
          rules.methodDefInliner, 0;
          rules.lambdaAppToLet, 0;
          rules.letInliner, 0;
          comp <@ rules.vectorBuildGet_exp @>, 0;
          rules.lambdaAppToLet, 0;
          rules.letInliner, 0;
          comp <@ rules.vectorBuildLength_exp @>, 0;
          rules.letIntroduction, 4;
          rules.letFloatOutwards, 0;
          rules.letFloatOutwards, 0;
          rules.letIntroduction, 16;
          rules.letFloatOutwards, 0;
          rules.letFloatOutwards, 0;
          rules.letFloatOutwards, 0;
          rules.letFloatOutwards, 0;
          rules.letFloatOutwards, 0;
          rules.letMerging, 0;
        ]
    //printfn "ba_reproj_err chains: %A" (String.concat "\n*****\n" (List.map ccodegen.prettyprint chains))
    //printfn "final one: %s" (chains |> List.rev |> List.head |> fun x -> transformer.variableRenaming x [] |> ccodegen.prettyprint)
    //printfn "ba_reproj_err code: %s" (ccodegen.ccodegenTopLevel (List.head (List.rev chains)) "usecases_reproj_err" false)
    let bundleAdjustmentRodrigues_rotate_point = compiler.getMethodExpr "usecases_ba" "rodrigues_rotate_point"
    let chains = 
      optimizer.guidedOptimize bundleAdjustmentRodrigues_rotate_point 
        [ 
          rules.methodDefInliner, 1;
          rules.methodDefInliner, 1;
          rules.lambdaAppToLet, 0;
          rules.letInliner, 6;
          rules.letInliner, 5;
          rules.methodDefInliner, 1;
          comp <@ rules.vectorBuildGet_exp @>, 0;
          rules.lambdaAppToLet, 0;
          rules.letInliner, 6;
          comp <@ rules.vectorBuildGet_exp @>, 0;
          rules.lambdaAppToLet, 0;
          rules.letInliner, 6;
          comp <@ rules.vectorBuildGet_exp @>, 0;
          rules.lambdaAppToLet, 0;
          rules.letInliner, 6;
          comp <@ rules.vectorBuildGet_exp @>, 0;
          rules.lambdaAppToLet, 0;
          rules.letInliner, 6;
          comp <@ rules.vectorBuildGet_exp @>, 0;
          rules.lambdaAppToLet, 0;
          rules.letInliner, 6;
          comp <@ rules.vectorBuildGet_exp @>, 0;
          rules.lambdaAppToLet, 0;
          rules.letInliner, 6;
          rules.methodDefInliner, 1;
          rules.methodDefInliner, 2;
          comp <@ rules.vectorBuildLength_exp @>, 0;
          rules.lambdaAppToLet, 0;
          rules.letInliner, 7;
          rules.letInliner, 7;
          comp <@ rules.vectorBuildGet_exp @>, 0;
          rules.lambdaAppToLet, 0;
          rules.letInliner, 7;
          rules.methodDefInliner, 1;
          comp <@ rules.vectorFoldBuildToFoldOnRange_exp @>, 0;
          rules.lambdaAppToLet, 0;
          rules.letInliner, 7;
          rules.lambdaAppToLet, 0;
          rules.letInliner, 7;
          rules.letInliner, 7;
          rules.methodDefInliner, 2;
          rules.methodDefInliner, 2;
          rules.betaReduction, 0;
          rules.methodDefInliner, 2;
          rules.methodDefInliner, 2;
          rules.betaReduction, 0;
          rules.methodDefInliner, 3;
          rules.methodDefInliner, 3;
          rules.betaReduction, 0;
          rules.letInliner, 7;
          comp <@ rules.vectorBuildGet_exp @>, 0;
          rules.betaReduction, 0;
          comp <@ rules.vectorBuildLength_exp @>, 0;
          rules.letInliner, 7;
          comp <@ rules.vectorBuildGet_exp @>, 0;
          rules.betaReduction, 0;
          rules.methodDefInliner, 3;
          rules.methodDefInliner, 3;
          rules.betaReduction, 0;
          comp <@ rules.vectorBuildGet_exp @>, 0;
          rules.betaReduction, 0;
          comp <@ rules.vectorBuildLength_exp @>, 0;
          rules.methodDefInliner, 2;
          rules.methodDefInliner, 2;
          rules.betaReduction, 0;
          comp <@ rules.vectorBuildGet_exp @>, 0;
          rules.betaReduction, 0;
          comp <@ rules.vectorBuildGet_exp @>, 0;
          rules.betaReduction, 0;
          comp <@ rules.vectorBuildLength_exp @>, 0;
        ]
    //printfn "ba_rodrigues_rotate_point chains: %A" (String.concat "\n*****\n" (List.map ccodegen.prettyprint chains))
    //printfn "usecases_rodrigues_rotate_point costs: %A" (String.concat "\n" (List.map (fun x -> cost.fopCost(x).ToString()) chains))
    //printfn "ba_rodrigues_rotate_point code: %s" (ccodegen.ccodegenTopLevel (List.head (List.rev chains)) "usecases_rodrigues_rotate_point" false)
    //printfn "code: %s" (compiler.compile "ccodegentests" "valloc_cps_feature1" false)
    ()

let test_feature () =
  let bundleAdjustmentProject = compiler.getMethodExpr "usecases_ba" "project"
  let comp = ruleengine.compilePatternToRule
  let uniqueRules = 
      [
        rules.vectorSliceToBuild;
        comp <@ rules.comAddIndex_exp @>;
        comp <@ rules.assocAddSubIndex_exp @>;
        comp <@ rules.subSameIndex_exp @>;
        comp <@ rules.constFold0Index_exp @>;
        rules.constantFold;
        rules.methodDefInliner;
        rules.betaReduction;
        comp <@ rules.vectorBuildLength_exp @>;
        comp <@ rules.vectorBuildGet_exp @>;
        comp <@ rules.vectorFoldBuildToFoldOnRange_exp @>;
        rules.letCommutingConversion;
        rules.letInliner;
      ]
  let firstLevelApplicableRules = optimizer.examineAllRulesPositioned uniqueRules bundleAdjustmentProject
  let lastRule = firstLevelApplicableRules |> List.rev |> List.head
  printfn "%A" (firstLevelApplicableRules |> List.map (optimizer.applyRuleAtParticularPosition bundleAdjustmentProject) |> List.map ccodegen.prettyprint )
  ()

let test_card () = 
  let cardAndStg (moduleName: string) (methodName: string) = 
    let exp = compiler.getMethodExpr moduleName methodName
    let expCard = cardinfer.inferCardinality exp
    printfn "card: `%A`" expCard
    let expStg = storagedtransformer.transformStoraged exp (storagedtransformer.newStgVar()) Map.empty
    printfn "stg: `%A`" (ccodegen.prettyprint expStg)
  cardAndStg "linalg" "vectorMap"
  cardAndStg "programs" "vectorAddExample"
  cardAndStg "linalg" "add_vec"
  cardAndStg "usecases_ba" "project"

[<EntryPoint>]
let main argv = 
    test_ba argv
    // compile_modules ()
    // test_phase_based_optimizer ()
    // compile_modules_storaged ()
    // usecases.test1 [||]
    // test_guided_optimizer ()
    // benchmark_search ()
    // test_ruleengine ()
    // test_feature ()
    // test_card()
    0
