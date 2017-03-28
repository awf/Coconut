module guided_optimizer

let test_guided_optimizer () = 
    compiler.compileModule "linalg" [] false false
    compiler.compileModule "usecases_ba" ["linalg"] false false
    let comp = ruleengine.compilePatternToRule
      //ruleengine.compilePatternToRule2
    let vecAdd3 = compiler.getMethodExpr "programs" "vector_add3"
    let letInliner = comp <@ rules.letInliner @>
    let chains = 
      optimizer.guidedOptimize vecAdd3 
        [ rules.methodDefToLambda, 0; 
          rules.lambdaAppToLet, 0;
          letInliner, 0;
          letInliner, 0;
          rules.methodDefToLambda, 0; 
          rules.lambdaAppToLet, 0;
          letInliner, 0;
          letInliner, 0;
          letInliner, 0;
          rules.methodDefToLambda, 0; 
          rules.lambdaAppToLet, 0;
          letInliner, 0;
          letInliner, 0;
          rules.methodDefToLambda, 0; 
          rules.lambdaAppToLet, 0;
          letInliner, 0;
          letInliner, 0;
          rules.lambdaAppToLet, 0;
          letInliner, 0;
          letInliner, 0;
          letInliner, 0;
          rules.lambdaAppToLet, 0;
          letInliner, 0;
          letInliner, 0;
          comp <@ rules.vectorBuildGet @>, 0;
          rules.lambdaAppToLet, 0;
          letInliner, 0;
          ]
    // printfn "vecAdd3 chains: %A" (String.concat "\n*****\n" (List.map ccodegen.prettyprint chains))
    let hoistingExample = compiler.getMethodExpr "programs" "hoistingExample"
    let chains = 
      optimizer.guidedOptimize hoistingExample 
        [ rules.vectorSliceToBuild, 0;
          comp <@ rules.comAddIndex @>, 1;
          comp <@ rules.assocAddSubIndex @>, 0;
          comp <@ rules.subSameIndex @>, 0;
          comp <@ rules.constFold0Index @>, 0;
          rules.constantFold, 0;
          //comp <@ rules.vectorAddToStorage @>, 0;
          comp <@ rules.letVectorBuildLength @>, 0;
          rules.letFloatOutwards, 0;
          comp <@ rules.vectorBuildToStorage @>, 0;
          comp <@ rules.letCommutingConversion @>, 0;
          rules.foldInvariantCodeMotion, 0;
          comp <@ rules.letCommutingConversion @>, 0;
          rules.allocToCPS, 0;
          rules.letFloatOutwards, 0;
          comp <@ rules.letReorder @>, 0;
          rules.foldInvariantCodeMotion, 0;
          comp <@ rules.letCommutingConversion @>, 0;
          rules.allocToCPS, 0;
        ]
    // printfn "hoistingExample chains: %A" (String.concat "\n*****\n" (List.map ccodegen.prettyprint chains))
    // printfn "hoistingExample costs: %A" (String.concat "\n" (List.map (fun x -> cost.fopCost(x).ToString()) chains))
    // printfn "code: %s" (ccodegen.ccodegenTopLevel (List.head (List.rev chains)) "hoistingExample" false)
    let stackExample = compiler.getMethodExpr "programs" "stackAllocExample"
    let chains = 
      optimizer.guidedOptimize stackExample 
        [ //comp <@ rules.vectorAddToStorage @>, 0;
          rules.letFloatOutwards, 0;
          comp <@ rules.letInliner @>, 0;
          rules.newArrayLength, 0;
          rules.letIntroduction, 2;
          rules.letFloatOutwards, 1;
          rules.letIntroduction, 3;
          rules.letFloatOutwards, 2;
          comp <@ rules.letMerging @>, 0;
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
          comp <@ rules.vectorBuildToStorage @>, 0;
          rules.lambdaAppStoraged, 0;
          comp <@ rules.copyLet @>, 0;
          rules.copyStoragedElimination, 0;
          comp <@ rules.dce @>, 0;
        ]
    printfn "storageConvertorExample chains: %A" (String.concat "\n*****\n" (List.map ccodegen.prettyprint chains))
    // printfn "storageConvertorExample costs: %A" (String.concat "\n" (List.map (fun x -> cost.fopCost(x).ToString()) chains))
    printfn "code: %s" (ccodegen.ccodegenTopLevel (List.head (List.rev chains)) "storageConvertorExample" false)
    let bundleAdjustmentProject = compiler.getMethodExpr "usecases_ba" "project"
    let baProjectRules = 
        [ rules.vectorSliceToBuild, 0;
          comp <@ rules.comAddIndex @>, 1;
          comp <@ rules.assocAddSubIndex @>, 0;
          comp <@ rules.subSameIndex @>, 0;
          comp <@ rules.constFold0Index @>, 0;
          rules.constantFold, 0;
          rules.vectorSliceToBuild, 0;
          comp <@ rules.comAddIndex @>, 2;
          comp <@ rules.assocAddSubIndex @>, 0;
          comp <@ rules.subSameIndex @>, 0;
          comp <@ rules.constFold0Index @>, 0;
          rules.constantFold, 0;
          rules.vectorSliceToBuild, 0;
          comp <@ rules.comAddIndex @>, 3;
          comp <@ rules.assocAddSubIndex @>, 0;
          comp <@ rules.subSameIndex @>, 0;
          comp <@ rules.constFold0Index @>, 0;
          rules.constantFold, 0;
          rules.vectorSliceToBuild, 0;
          rules.constantFold, 0;
          rules.constantFold, 0;
          comp <@ rules.constFold0Index @>, 0;
          rules.vectorSliceToBuild, 0;
          comp <@ rules.comAddIndex @>, 4;
          comp <@ rules.assocAddSubIndex @>, 0;
          comp <@ rules.subSameIndex @>, 0;
          comp <@ rules.constFold0Index @>, 0;
          rules.constantFold, 0;
          rules.methodDefInliner, 2;
          rules.methodDefInliner, 3;
          rules.methodDefInliner, 3;
          rules.betaReduction, 0;
          comp <@ rules.vectorBuildLength @>, 0;
          comp <@ rules.vectorBuildGet @>, 0;
          rules.betaReduction, 0;
          comp <@ rules.vectorBuildGet @>, 0;
          rules.betaReduction, 0;
          comp <@ rules.vectorBuildGet @>, 0;
          rules.betaReduction, 0;
          rules.methodDefInliner, 2;
          rules.methodDefInliner, 2;
          rules.methodDefInliner, 2;
          rules.betaReduction, 0;
          comp <@ rules.vectorBuildLength @>, 0;
          comp <@ rules.vectorBuildGet @>, 0;
          rules.betaReduction, 0;
          comp <@ rules.vectorBuildGet @>, 0;
          rules.betaReduction, 0;
          //comp <@ rules.vectorFoldBuildToFoldOnRange @>, 0;
          rules.betaReduction, 0;
          rules.betaReduction, 0;
          rules.methodDefInliner, 4;
          rules.methodDefInliner, 4;
          rules.betaReduction, 0;
          comp <@ rules.vectorBuildLength @>, 0;
          comp <@ rules.vectorBuildGet @>, 0;
          rules.betaReduction, 0;
          rules.methodDefInliner, 3;
          rules.methodDefInliner, 3;
          rules.betaReduction, 0;
          comp <@ rules.vectorBuildLength @>, 0;
          comp <@ rules.vectorBuildGet @>, 0;
          rules.betaReduction, 0;
          rules.methodDefInliner, 3;
          rules.methodDefInliner, 3;
          rules.betaReduction, 0;
          comp <@ rules.vectorBuildLength @>, 0;
          comp <@ rules.vectorBuildGet @>, 0;
          rules.betaReduction, 0;
          rules.methodDefInliner, 3;
          rules.methodDefInliner, 3;
          rules.betaReduction, 0;
          comp <@ rules.vectorBuildGet @>, 0;
          rules.betaReduction, 0;
          comp <@ rules.letCommutingConversion @>, 0;
          comp <@ rules.letCommutingConversion @>, 0;
          comp <@ rules.letInliner @>, 9;
          comp <@ rules.vectorBuildGet @>, 0;
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
          letInliner, 0;
          letInliner, 0;
          letInliner, 0;
          rules.methodDefInliner, 1;
          rules.methodDefInliner, 0;
          rules.methodDefInliner, 0;
          comp <@ rules.vectorBuildLength @>, 0;
          rules.lambdaAppToLet, 0;
          letInliner, 0;
          rules.methodDefInliner, 3;
          comp <@ rules.vectorBuildGet @>, 0;
          rules.lambdaAppToLet, 0;
          letInliner, 0;
          comp <@ rules.indexToDoubleToInt @>, 0;
          comp <@ rules.comAddIndex @>, 1;
          comp <@ rules.constFold0Index @>, 0;
          comp <@ rules.assocSubSubIndex @>, 0;
          comp <@ rules.constFold0Index @>, 0;
          comp <@ rules.assocSubAddIndex @>, 0;
          rules.constantFold, 0;
          comp <@ rules.constFoldN0Index @>, 0;
          rules.methodDefInliner, 3;
          comp <@ rules.vectorBuildGet @>, 0;
          rules.lambdaAppToLet, 0;
          letInliner, 0;
          comp <@ rules.indexToDoubleToInt @>, 0;
          comp <@ rules.comAddIndex @>, 0;
          comp <@ rules.constFold0Index @>, 0;
          rules.methodDefInliner, 3;
          comp <@ rules.vectorBuildGet @>, 0;
          rules.lambdaAppToLet, 0;
          letInliner, 0;
          comp <@ rules.indexToDoubleToInt @>, 0;
          comp <@ rules.comAddIndex @>, 0;
          comp <@ rules.constFold0Index @>, 0;
          rules.methodDefInliner, 3;
          comp <@ rules.vectorBuildGet @>, 0;
          rules.lambdaAppToLet, 0;
          letInliner, 0;
          comp <@ rules.indexToDoubleToInt @>, 0;
          comp <@ rules.comAddIndex @>, 0;
          comp <@ rules.constFold0Index @>, 0;
          rules.methodDefInliner, 0;
          rules.methodDefInliner, 1;
          rules.methodDefInliner, 1;
          rules.lambdaAppToLet, 0;
          letInliner, 0;
          letInliner, 0;
          rules.methodDefInliner, 0;
          rules.lambdaAppToLet, 0;
          letInliner, 0;
          comp <@ rules.vectorBuildGet @>, 0;
          rules.lambdaAppToLet, 0;
          letInliner, 0;
          comp <@ rules.vectorBuildLength @>, 0;
          rules.letIntroduction, 4;
          rules.letFloatOutwards, 0;
          rules.letFloatOutwards, 0;
          rules.letIntroduction, 16;
          rules.letFloatOutwards, 0;
          rules.letFloatOutwards, 0;
          rules.letFloatOutwards, 0;
          rules.letFloatOutwards, 0;
          rules.letFloatOutwards, 0;
          comp <@ rules.letMerging @>, 0;
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
          letInliner, 6;
          letInliner, 5;
          rules.methodDefInliner, 1;
          comp <@ rules.vectorBuildGet @>, 0;
          rules.lambdaAppToLet, 0;
          letInliner, 6;
          comp <@ rules.vectorBuildGet @>, 0;
          rules.lambdaAppToLet, 0;
          letInliner, 6;
          comp <@ rules.vectorBuildGet @>, 0;
          rules.lambdaAppToLet, 0;
          letInliner, 6;
          comp <@ rules.vectorBuildGet @>, 0;
          rules.lambdaAppToLet, 0;
          letInliner, 6;
          comp <@ rules.vectorBuildGet @>, 0;
          rules.lambdaAppToLet, 0;
          letInliner, 6;
          comp <@ rules.vectorBuildGet @>, 0;
          rules.lambdaAppToLet, 0;
          letInliner, 6;
          rules.methodDefInliner, 1;
          rules.methodDefInliner, 2;
          comp <@ rules.vectorBuildLength @>, 0;
          rules.lambdaAppToLet, 0;
          letInliner, 7;
          letInliner, 7;
          comp <@ rules.vectorBuildGet @>, 0;
          rules.lambdaAppToLet, 0;
          letInliner, 7;
          rules.methodDefInliner, 1;
          //comp <@ rules.vectorFoldBuildToFoldOnRange @>, 0;
          rules.lambdaAppToLet, 0;
          letInliner, 7;
          rules.lambdaAppToLet, 0;
          letInliner, 7;
          letInliner, 7;
          rules.methodDefInliner, 2;
          rules.betaReduction, 0;
          rules.methodDefInliner, 2;
          rules.methodDefInliner, 2;
          rules.betaReduction, 0;
          rules.methodDefInliner, 3;
          rules.methodDefInliner, 3;
          rules.betaReduction, 0;
          letInliner, 7;
          comp <@ rules.vectorBuildGet @>, 0;
          rules.betaReduction, 0;
          comp <@ rules.vectorBuildLength @>, 0;
          letInliner, 7;
          comp <@ rules.vectorBuildGet @>, 0;
          rules.betaReduction, 0;
          rules.methodDefInliner, 3;
          rules.methodDefInliner, 3;
          rules.betaReduction, 0;
          comp <@ rules.vectorBuildGet @>, 0;
          rules.betaReduction, 0;
          comp <@ rules.vectorBuildLength @>, 0;
          rules.methodDefInliner, 2;
          rules.methodDefInliner, 2;
          rules.betaReduction, 0;
          comp <@ rules.vectorBuildGet @>, 0;
          rules.betaReduction, 0;
          comp <@ rules.vectorBuildGet @>, 0;
          rules.betaReduction, 0;
          comp <@ rules.vectorBuildLength @>, 0;
        ]
    //printfn "ba_rodrigues_rotate_point chains: %A" (String.concat "\n*****\n" (List.map ccodegen.prettyprint chains))
    //printfn "usecases_rodrigues_rotate_point costs: %A" (String.concat "\n" (List.map (fun x -> cost.fopCost(x).ToString()) chains))
    //printfn "ba_rodrigues_rotate_point code: %s" (ccodegen.ccodegenTopLevel (List.head (List.rev chains)) "usecases_rodrigues_rotate_point" false)
    //printfn "code: %s" (compiler.compile "ccodegentests" "valloc_cps_feature1" false)
    ()
