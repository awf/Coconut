module ml_engine

open Microsoft.FSharp.Quotations
open utils
open types
open transformer
open ruleengine
open rules
open cost
open search
open optimizer



let log_optimize (e: Expr): Expr = 
  let debug = true
  let comp = ruleengine.compilePatternToRule
  let rs = 
    [//comp <@ letInliner @> ; 
     rules_old.letCommutingConversion_old; rules_old.letNormalization_old;
     rules_old.letInlinerOnce_old; rules_old.dce_old;
     methodDefToLambda ; lambdaAppToLet;
     comp <@ vectorBuildGet @>; comp <@ vectorBuildLength @>;
     rules_old.letVectorBuildLength_old; rules_old.letVectorBuildGet_old] @
     algebraicRulesScalar
  (*recursiveTransformer rs e*)
  let debugger = Logging.consoleLogger debug
  let reporter = Logging.completeReporter (ccodegen.prettyprint) debugger
  let t = tic()
  //let (best, _) = bfs 5 reporter e (examineAllRules rs) fopCost 
  (*let (best, _) = randomWalk 5 reporter e (examineAllRules rs) fopCost *)
  let (best, _) = beamSearch 30 1 reporter e (examineAllRules rs) fopCost 
  toc(t)
  
  best


let main_ml_engine(): unit = 
  compiler.compileModule "linalg" [] false false
  let trainingModule = "training_programs"
  let methods = compiler.getMethodsOfModule "training_programs"
  let opts = methods |> List.map (fun m -> log_optimize (compiler.getMethodExpr trainingModule m))
  ()