open System
open System.Diagnostics
open System.IO
open cruntime
open utils
open linalg
open corelang
open FSharp.Quotations
open types
//open usecases_gmm
(*
let test_ba (argv: string[]) = 
    let fileName = 
      if argv.Length < 1 then 
        "../../data/ba_instances/ba1.txt" // Much clearer to have the default here rather than in the .fsproj file
      else 
        argv.[0]
    let nmp = vectorRead fileName 0 (Card 3)
    let n = Card (int nmp.[0])
    let m = Card (int nmp.[1])
    let p = Card (int nmp.[2])
    let res = usecases_ba.run_ba_from_file fileName n m p
    //matrixPrint res
    ()
*)
 
let test_ruleengine () = 
    //let prog = <@ let x = 1 * 3 in x * 3 @>
    //let prog = <@ vectorFoldNumber (fun acc cur -> acc) 0.0 (vectorBuild 10 (fun i -> 2.)) @>
    //let prog' = ruleengine.compilePatternToRule (rules.vectorFoldBuildToFoldOnRange) prog
    //let prog' = prog
    //let prog = <@ let y = 1 * 3 in y * 3 @>
    //let prog' = ruleengine.compilePatternToRule (rules.letInliner ()) prog
    //let prog = <@ 8.0 - 0.0 - 2.0 @>
    //let prog' = ruleengine.compilePatternToRule (rules.assocSubSubIndex) prog
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
    compiler.compileModule "usecases_gmm" ["linalg"] false false
    compiler.compileModule "ccodegentests" [] false false

let compile_modules_storaged () = 
    compiler.compileModule "linalg" [] false true
    compiler.compileModule "linalgtests" ["linalg"] false true
    compiler.compileModule "usecases_ba" ["linalg"] false true
    compiler.compileModule "usecases_gmm" ["linalg"] false true
    compiler.compileModule "usecases_ht" ["linalg"] false true
    // compiler.compile "usecases" "run_ba_from_file" false true
    ()

let benchmark_search () =
    let bundleAdjustmentProject = compiler.getMethodExpr "usecases_ba" "project"
    benchmark.benchmark_test_algorithms bundleAdjustmentProject

let test_feature () =
  let bundleAdjustmentProject = compiler.getMethodExpr "usecases_ba" "project"
  let comp = ruleengine.compilePatternToRule
  let uniqueRules = 
      [
        rules.vectorSliceToBuild;
        comp <@ rules.comAddIndex @>;
        comp <@ rules.assocAddSubIndex @>;
        comp <@ rules.subSameIndex @>;
        comp <@ rules.constFold0Index @>;
        rules.constantFold;
        rules.methodDefInliner;
        rules.betaReduction;
        comp <@ rules.vectorBuildLength @>;
        comp <@ rules.vectorBuildGet @>;
        //comp <@ rules.vectorFoldBuildToFoldOnRange @>;
        comp <@ rules.letCommutingConversion @>;
        comp <@ rules.letInliner @>;
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
    //usecases_ht.test_ht ()
    //test_ba argv
    //Qtimesv_test ()
    //compiler.compileModuleFromSource "linalg" [] false false
    //compiler.compileModuleFromSource "simple_tests" [] "Examples/FSmoothUsecases" false false
    //compiler.compileModuleFromSource "linalg" [] "FSmoothRuntime" false false
    //compiler.compileModuleFromSource "usecases_ba" ["linalg"] "Examples/FSmoothUsecases" false false
    //compile_modules ()
    // phase_based_optimizer.test_phase_based_optimizer ()
    //compile_modules_storaged ()
    // usecases.test1 [||]
    // guided_optimizer.test_guided_optimizer()
    // benchmark_search ()
    // test_ruleengine ()
    // test_feature ()
    // test_card()
    symbolicdiff.test_symdiff()
    //ml_engine.main_ml_engine()
    //compiler.compileModuleToLisp "linalg"
    //compiler.compileModuleToLisp "usecases_ba"
    //compiler.compileModuleToLisp "usecases_gmm"
    0
