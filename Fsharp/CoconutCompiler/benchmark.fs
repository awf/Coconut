module benchmark

open utils

let benchmark_test_algorithms program = 
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
        // <@ rules.vectorFoldBuildToFoldOnRange @>;
        comp <@ rules.letCommutingConversion @>;
        comp <@ rules.letInliner @>;
      ]
  let runSearchAlgorithm algorithm name levels () =
    let logger = 
      let fileName = sprintf "LogFile_%s_%s.txt" name (currentTimeString())
      printfn "%s" fileName
      (search.Logging.fileLogger true fileName)
    try 
      let best = algorithm levels (search.Logging.completeReporter (ccodegen.prettyprint) logger) program (optimizer.examineAllRules uniqueRules) (cost.fopCost)
      printf "best: cost=%f, program: %s" (snd best) (ccodegen.prettyprint (fst best))
    with ex -> printf "Failed because of %A" ex
  for i = 1 to 5 do
    let levels = i * 50
    //runSearchAlgorithm (search.hillClimbing) "HC" levels ()
    for t = 1 to 5 do
      //runSearchAlgorithm (search.randomWalk) "RW" levels ()
      runSearchAlgorithm (search.simulatedAnnealing) "SA" levels ()
  //printfn "best by random walk %A" best