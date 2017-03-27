module phase_based_optimizer

open FSharp.Quotations

let recTrans rs = optimizer.recursiveTransformer rs |> optimizer.fixPoint 10
let hurTrans rs = optimizer.heuristicOptimizer 1000 (rs |> List.map (fun r -> r, 1.0))
let trans rs exp = 
  // let t = tic()
  let e = recTrans rs exp
  // toc t
  e

let generateCodeForAllPhases (prog: Expr) (phases: ruleengine.Rule list list) (hdr: string) (mtd: string): unit = 
  let generateCodeUpToPhase (subPhases: ruleengine.Rule list list): unit = 
    let numPhases = subPhases |> List.length
    let headerName = sprintf "%s_%d" hdr numPhases
    let methodName = sprintf "%s_%d" mtd numPhases
    let transformed = 
      (prog, subPhases) ||> List.fold (fun acc rules -> trans rules acc)
    let result = transformed // |> fun x -> transformer.variableRenaming x []
    compiler.writeToHeaderFile headerName ["linalg"; "usecases_ba"] ([ccodegen.ccodegenTopLevel result methodName false])
  generateCodeUpToPhase []
  ([], phases) ||> List.fold (fun acc cur -> let nacc = acc @ [cur] in generateCodeUpToPhase nacc; nacc ) |> ignore
  // generateCodeUpToPhase phases
  ()

let fusion_optimize (exp: Expr): Expr = 
  exp
    |> trans [rules.methodDefToLambda; rules.lambdaAppToLet; rules.vectorSliceToBuild] 
    |> trans [rules_old.letCommutingConversion_old; rules_old.letNormalization_old]
    |> trans [rules_old.letVectorBuildLength_old; rules_old.letVectorBuildGet_old]
    // // |> trans [ruleengine.compilePatternToRule <@ rules.letBuild @>]
    // // |> trans [ruleengine.compilePatternToRule <@ rules.vectorBuildGet @>; 
    // //           ruleengine.compilePatternToRule <@ rules.vectorBuildLength @>]
    |> trans [rules.lambdaAppToLet] 
    |> trans [rules_old.letCommutingConversion_old; rules_old.letNormalization_old]
    |> trans [rules_old.dce_old]
    // |> trans [ruleengine.compilePatternToRule <@ rules.letBuild @>]
    // |> trans [ruleengine.compilePatternToRule <@ rules.vectorFoldBuildToFoldOnRange @>]
    |> trans [ruleengine.compilePatternToRule <@ rules.letBuild @>; 
              //ruleengine.compilePatternToRule <@ rules.vectorFoldBuildToFoldOnRange @>
              ]
    |> trans [rules.lambdaAppToLet] 
    |> trans [ruleengine.compilePatternToRule <@ rules.constFoldCardAdd @>;
                 ruleengine.compilePatternToRule <@ rules.constFoldCardSub @>] 
    |> trans [rules.constantFold; ruleengine.compilePatternToRule <@ rules.constFold0Index @>] 
    // |> trans [rules.methodDefToLambda; rules.lambdaAppToLet; rules.vectorSliceToBuild] 
    // |> trans [rules_old.letCommutingConversion_old; rules_old.letNormalization_old]
    // |> trans [ruleengine.compilePatternToRule <@ rules.letBuild @>]
    // |> trans [ruleengine.compilePatternToRule <@ rules.vectorBuildGet @>; 
    //           ruleengine.compilePatternToRule <@ rules.vectorBuildLength @>;
    //           ruleengine.compilePatternToRule <@ rules.vectorFoldBuildToFoldOnRange @>]
    // |> trans [rules.lambdaAppToLet]
    // |> trans [rules_old.letCommutingConversion_old; rules_old.letNormalization_old]
    // |> trans [rules_old.dce_old]
    // |> trans [ruleengine.compilePatternToRule <@ rules.constFoldCardAdd @>;
    //           ruleengine.compilePatternToRule <@ rules.constFoldCardSub @>] 
    // |> trans [rules.constantFold; ruleengine.compilePatternToRule <@ rules.constFold0Index @>]
    |> fun x -> transformer.variableRenaming x []

let fusion_phases = 
  [
    [rules.methodDefToLambda; rules.lambdaAppToLet; rules.vectorSliceToBuild]; 
    [rules_old.letCommutingConversion_old; rules_old.letNormalization_old];
    // [ruleengine.compilePatternToRule <@ rules.letBuild @>];
    // [ruleengine.compilePatternToRule <@ rules.vectorBuildGet @>; 
    //  ruleengine.compilePatternToRule <@ rules.vectorBuildLength @>;
    //  ruleengine.compilePatternToRule <@ rules.vectorFoldBuildToFoldOnRange @>];
    [rules_old.letVectorBuildLength_old; rules_old.letVectorBuildGet_old];
    [rules.lambdaAppToLet];
    [rules_old.letCommutingConversion_old; rules_old.letNormalization_old];
    [rules_old.dce_old];
    [ruleengine.compilePatternToRule <@ rules.letBuild @>; 
     //ruleengine.compilePatternToRule <@ rules.vectorFoldBuildToFoldOnRange @>
     ];
    [rules.lambdaAppToLet];
    [ruleengine.compilePatternToRule <@ rules.constFoldCardAdd @>;
     ruleengine.compilePatternToRule <@ rules.constFoldCardSub @>]; 
    [rules.constantFold; ruleengine.compilePatternToRule <@ rules.constFold0Index @>];
  ]
 
let test_phase_based_optimizer () = 
    compiler.compileModule "linalg" [] false false
//    compiler.compileModule "usecases_gmm" ["linalg"] false false
//    let bundleAdjustmentReprojErr = compiler.getMethodExpr "usecases_ba" "reproj_err"
//    let bundleAdjustmentReprojErr = compiler.getMethodExpr "usecases_ba" "project"
//    compiler.compileModule "usecases_gmm" ["linalg"] false false
//    let bundleAdjustmentReprojErr = compiler.getMethodExpr "usecases_gmm" "gmm_objective"
    let bundleAdjustmentReprojErr = compiler.getMethodExpr "linalg" "vectorAdd3"
      
    // let time = tic()
    let opt = 
      fusion_optimize bundleAdjustmentReprojErr 
     
        |> (fun p -> storagedtransformer.transformStoraged p transformer.EMPTY_STORAGE Map.empty)
        |> storagedtransformer.getAliasSimplify
        |> storagedtransformer.simplifyStoraged 
        |> trans [rules_old.letCommutingConversion_old; rules_old.letNormalization_old]
        |> trans [rules_old.dce_old]
     

    printfn "C code: %s" (ccodegen.ccodegenTopLevel opt "usecases_ba_project_opt" true)
    //printfn "FSharp code: %s" (fscodegen.fscodegenTopLevel opt)

