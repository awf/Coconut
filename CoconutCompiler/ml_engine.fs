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

let downNth idx = 
  match idx with 
  | 0 -> Down
  | 1 -> Down2
  | 2 -> Down3
  | 3 -> Down4
  | _ -> failwithf "%d th down not available" idx

let downIndex m = 
  match m with
  | Down -> 0
  | Down2 -> 1
  | Down3 -> 2
  | Down4 -> 3
  | _ -> failwithf "%A is not a down move" m

type Step = 
  | StepMove of Move
  | StepRule of Rule

// In essence similar to a zipper data structure
type SubExpr<'p> = 
  Expr (* Root *) * 
  //Expr (* Sub Expression *) * 
  'p (* Position Representation *)
type ProgramState = SubExpr<RulePosition>
type ProgramMoves = SubExpr<Move list>

type ProgramExternalState = 
  (* Set of Applicable Rules *)
  RuleInfo Set * 
  (* Current Depth *)
  int 

let positionToMoves (e: Expr) (pos: RulePosition): Move list =
  let rec rcr (exp: Expr) (rootPos: RulePosition): Move list = 
    if rootPos = pos then
      []
    else
      match exp with 
      | ExprShape.ShapeLambda(i, e) -> Down2 :: (rcr e (rootPos + 1))
      | ExprShape.ShapeVar(v)       -> if rootPos + 1 = pos then [] else failwithf "shouldn't reach to var %A" exp
      | Patterns.Value(v, tp)       -> if rootPos + 1 = pos then [] else failwithf "shouldn't reach to value %A" exp
      | ExprShape.ShapeCombination(o, exprs) ->
          let exprsPos = ([rootPos + 1], exprs) ||> List.fold (fun list cur -> (List.head list) + exprSize cur :: list) |> List.rev
          let idx = exprsPos |> List.findIndex (fun p -> p > pos)
          let childPos = List.nth exprsPos (idx - 1)
          let exp = List.nth exprs (idx - 1)
          let move = downNth (idx - 1)
          move :: (rcr exp childPos)
  rcr e zeroMetaData

let stateToMoves ((e, pos): ProgramState): ProgramMoves = 
  e, positionToMoves e pos

let stateToExternal (rs: Rule list) ((e, pos) as state: ProgramState) : ProgramExternalState = 
  let rules = examineAllRulesPositioned rs e |> List.map (fun i -> snd (snd i)) |> Set.ofList
  let currentDepth = snd (stateToMoves state) |> List.length
  rules, currentDepth

let movesToState ((e, moves): ProgramMoves): ProgramState = 
  let rec rcr exp moves rootPos: int = 
    match moves with
    | [] -> rootPos
    | hd :: tl ->
      match exp with 
      | ExprShape.ShapeLambda(i, e) -> 
        if hd = Down2 then rcr e tl (rootPos + 1) else failwithf "shouldn't move %A in lambda %A" hd exp
      | ExprShape.ShapeVar(v)       -> 
        failwithf "shouldn't move in var %A" exp
      | Patterns.Value(v, tp)       -> 
        failwithf "shouldn't move in value %A" exp
      | ExprShape.ShapeCombination(o, exprs) ->
        let idx = downIndex hd
        let sizes = (rootPos + 1, exprs) ||> List.scan (fun acc cur -> acc + (exprSize cur))
        let childPos = List.nth sizes idx
        let childExp = List.nth exprs idx
        rcr childExp tl childPos
  e, rcr e moves 0

let movesUpdate (p: Move list) (nextMove: Move): Move list =
  p |> List.iter (fun m -> assert(m <> Up))
  match nextMove with 
  | Up -> p |> List.rev |> List.tail |> List.rev
  | _  -> p @ [nextMove]

let stepProg (prog: ProgramState) (step: Step): ProgramState = 
  let (e, pos) = prog
  match step with 
  | StepMove(m) -> 
    let (_, moves) = stateToMoves prog
    let moves' = movesUpdate moves m
    movesToState (e, moves')
  | StepRule(r) ->
    applyRuleAtParticularPosition e (pos, r), pos

let deltaPos (p1: Move list) (p2: Move list): Move list = 
  let rec commonPrefix l1 l2 = 
      match (l1, l2) with
      | (hd1 :: tl1, hd2 :: tl2) ->
        if hd1 = hd2 then 
           hd1 :: (commonPrefix tl1 tl2)
        else
           []
      | _ -> []
  let cmn = commonPrefix p1 p2
  let cmnSize = List.length cmn
  let p1UpSize = (List.length p1) - cmnSize
  let p1Up = [for i = 1 to p1UpSize do yield Up]
  let p2Down = p2 |> Seq.skip cmnSize |> List.ofSeq
  p1Up @ p2Down

let appliedRulesToSteps (e: Expr) (appliedRules: MetaData list): Step list = 
  //printfn "rules %A" appliedRules
  let allProgs = 
    (e, appliedRules) ||> List.scan applyRuleAtParticularPosition
  //printf "rep prog: %s" (ccodegen.prettyprint (repeatRules |> List.head))
  let allProgsButLast = allProgs |> Seq.skip 1 |> List.ofSeq
  let ruleMoves = 
    (appliedRules, allProgsButLast) ||> List.map2 (fun (pos, rule) e ->
         (positionToMoves e pos, rule)
       )
  
  //ruleMoves 
  //  |> List.iter (fun (pos, rule) ->
  //      printfn "moves: %A, rule: %s" pos (snd rule)
  //     )
  let compressedMoves = 
    (([], []), ruleMoves) 
      ||> List.scan (fun (prevDeltaPos, prevPos) (pos, rule) -> 
            deltaPos prevPos pos, pos
          ) 
      |> List.map fst |> List.tail

  //compressedMoves 
  //    |> List.iter (fun pos ->
  //        printfn "cmpr moves: %A" pos
  //       )  

  let steps = 
     (ruleMoves, compressedMoves) 
       ||> List.map2 (fun (_, rule) pos -> (pos |> List.map StepMove) @ [StepRule rule])
       |> List.concat
  //steps 
  //    |> List.iter (fun step ->
  //        printfn "step: %A" step
  //       )  
  steps


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

  let steps = 
    appliedRulesToSteps e (appliedRules |> List.rev)
 
  printfn ">> %A" (stateToExternal rs (e, 0))
  let finalProg = 
    ((e, 0), steps)
      ||> List.fold (fun (exp, pos) step ->
            let newState = stepProg (exp, pos) step
            let ext = stateToExternal rs newState
            printfn "<< %A" step
            printfn ">> %A" ext
            newState
          )  

  printfn "final exp: %s" (ccodegen.prettyprint (fst finalProg))

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
  posListsEqual (deltaPos [Down2; Down] [Down2; Down2]) [Up; Down2]
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