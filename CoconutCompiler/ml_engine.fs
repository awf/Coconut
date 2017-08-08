module ml_engine

open Microsoft.FSharp.Quotations
open NUnit.Framework
open utils
open types
open transformer
open ruleengine
open rules
open cost
open search
open optimizer

type Move =
  | Up
  | Down
  | Down2
  | Down3
  | Down4

  override this.ToString() = 
      match this with 
      | Up    -> "U"
      | Down  -> "D1"
      | Down2 -> "D2"
      | Down3 -> "D3"
      | Down4 -> "D4"
  member this.AsString = this.ToString()

let positionToMoves (e: Expr) (pos: RulePosition): Move list =
  let rec rcr (exp: Expr) (rootPos: InputMetaData): Move list = 
    if rootPos = pos then
      []
    else
      match exp with 
      | ExprShape.ShapeLambda(i, e) -> Down2 :: (rcr e (rootPos + 1))
      | ExprShape.ShapeVar(v)       -> if rootPos + 1 = pos then [] else failwithf "shouldn't reach to var %A" exp
      | Patterns.Value(v, tp)       -> if rootPos + 1 = pos then [] else failwithf "shouldn't reach to value %A" exp
      | ExprShape.ShapeCombination(o, exprs) ->
          //let exprsExpressions = (([], rootPos + 1), exprs) ||> List.fold (fun (ms, idx) e  -> (rcr e idx) :: ms, idx + exprSize e)
          //ExprShape.RebuildShapeCombination(o, fst exprsExpressions |> List.rev)
          let exprsPos = ([rootPos + 1], exprs) ||> List.fold (fun list cur -> (List.head list) + exprSize cur :: list) |> List.rev
          let idx = exprsPos |> List.findIndex (fun p -> p > pos)
          let childPos = List.nth exprsPos (idx - 1)
          let exp = List.nth exprs (idx - 1)
          let move = 
             match idx with 
             | 1 -> Down
             | 2 -> Down2
             | 3 -> Down3
             | 4 -> Down4
          move :: (rcr exp childPos)
  rcr e zeroMetaData

let log_optimize (e: Expr) = 
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
  let debugger = Logging.consoleLogger debug
  let reporter = Logging.completeReporter (fun (e, _) -> ccodegen.prettyprint e) debugger
  let t = tic()
  let ((best, appliedRules), _) = 
    beamSearch<Expr * MetaData list> 30 1 reporter (e, []) (
      fun (e, historyRules) -> 
        let applicableRules = examineAllRulesPositioned rs e
        applicableRules |> List.map (fun r -> applyRuleAtParticularPosition e r, r :: historyRules)
      ) (fun (e, _) -> fopCost e)
  toc t "beam searching"
  //printfn "rules %A" appliedRules
  let allProgs = 
    let rs = appliedRules |> List.rev
    ([e], rs) ||> List.fold (fun acc cur -> applyRuleAtParticularPosition (List.head acc) cur :: acc) |> List.rev
  //printf "rep prog: %s" (ccodegen.prettyprint (repeatRules |> List.head))
  let allProgsButLast = allProgs |> List.rev |> List.tail |> List.rev
  (appliedRules |> List.rev, allProgsButLast) ||> List.zip 
    |> List.iter (fun ((pos, rule), e) ->
         printfn "rule: %A, moves: %A" (snd rule) (positionToMoves e pos)
       )
  best

[<Test>]
let testPositionToMoves () =
  let trainingModule = "training_programs"
  let methods = compiler.getMethodsOfModule trainingModule
  let exp1 = 
    <@ 
      fun a -> 
        a + a
    @>
  let posListsEqual l1 l2 =
    Assert.AreEqual(l1, l2, sprintf "Expected: %A\nActual: %A" l2 l1)
  posListsEqual (positionToMoves exp1 0) []
  // TODO think more about indexing lambdas and variables
  posListsEqual (positionToMoves exp1 1) [Down2]
  posListsEqual (positionToMoves exp1 3) [Down2; Down]
  posListsEqual (positionToMoves exp1 4) [Down2; Down2]
  let exp2 = 
    <@ 
      fun a b -> 
        let x = a + b
        if x = 0 then
          a
        else
          b
    @>
  Assert.AreEqual(positionToMoves exp2 0, [])
  

let main_ml_engine(): unit = 
  compiler.compileModule "linalg" [] false false
  let trainingModule = "training_programs"
  let methods = compiler.getMethodsOfModule trainingModule
  let opts = methods |> List.map (fun m -> log_optimize (compiler.getMethodExpr trainingModule m))
  ()