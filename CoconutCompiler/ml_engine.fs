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
  Expr option (* Sub Expression *) * 
  'p (* Position Representation *)
type ProgramState = SubExpr<RulePosition>
type ProgramMoves = SubExpr<Move list>

type ProgramExternalState = 
  (* Set of Applicable Rules to the Current Position *)
  RuleInfo Set * 
  (* Current Depth *)
  int *
  (* Preorder repr of the Subexpr in the Current Position *)
  string

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

let positionToSubexpr (e: Expr) (pos: RulePosition): Expr =
  let rec rcr (exp: Expr) (rootPos: RulePosition): Expr = 
    if rootPos = pos then
      exp
    else
      match exp with 
      | ExprShape.ShapeLambda(i, e) -> rcr e (rootPos + 1)
      | ExprShape.ShapeVar(v)       -> failwithf "shouldn't reach to var %A" exp
      | Patterns.Value(v, tp)       -> failwithf "shouldn't reach to value %A" exp
      | ExprShape.ShapeCombination(o, exprs) ->
          let exprsPos = ([rootPos + 1], exprs) ||> List.fold (fun list cur -> (List.head list) + exprSize cur :: list) |> List.rev
          let idx = exprsPos |> List.findIndex (fun p -> p > pos)
          let childPos = List.nth exprsPos (idx - 1)
          let exp = List.nth exprs (idx - 1)
          rcr exp childPos
  rcr e zeroMetaData

let subexpr ((e, s, pos) as state: ProgramState): Expr = 
  match s with 
  | Some(se) -> se
  | None -> positionToSubexpr e pos

let stateToMoves ((e, s, pos) as state: ProgramState): ProgramMoves = 
  e, s, positionToMoves e pos

let exprPreorderString (exp: Expr): string = 
  let rec rcr e = 
    match e with 
    | ExprShape.ShapeLambda(i, e) -> sprintf "LV%s" (rcr e)
    | ExprShape.ShapeVar(v)       -> "V"
    | Patterns.Value(v, tp)       -> 
      if(tp = typeof<double>) then
        let dv = unbox<double>(v)
        if (dv = 0.) then
          "0"
        elif (dv = 1.) then
          "1"
        elif (dv = 2.) then
          "2"
        else 
          "C"
      else 
        "C"
    | Patterns.Call (None, op, elist) -> 
      let opName = 
        match op.Name with
        | OperatorName opname -> opname.ToCharArray().[0]
        | "GetArray"          -> 'G'
        | _                   -> '_' 
      let exprsStr = elist |> List.map rcr
      sprintf "%c%s" opName (exprsStr |> String.concat "")
    | ExprShape.ShapeCombination(o, exprs) ->
        let exprsStr = exprs |> List.map rcr
        sprintf "U%s" (exprsStr |> String.concat "")
  rcr exp

let stateToExternal (rs: Rule list) (state: ProgramState) : ProgramExternalState = 
  let se = subexpr state
  let rules = examineAllRulesPositioned rs se |> List.filter (fun r -> (fst r) = 0) |> List.map (fun i -> snd (snd i)) |> Set.ofList
  let (_, _, moves) = stateToMoves state
  let currentDepth = moves |> List.length
  let se = subexpr state
  let str = exprPreorderString se
  //let (e, _, _) = state
  //let str = fscodegen.fscodegenTopLevel e
  rules, currentDepth, str

let externalToString (rulesIndexMap: Map<RuleInfo, int>) ((rs, depth, str) as ext: ProgramExternalState): string = 
  let extRulesIndex = rs |> Set.toSeq |> Seq.map (fun r -> rulesIndexMap |> Map.find r) |> Seq.sort |> Seq.map(fun i -> i.ToString())
  sprintf ">> %s %d %s" str depth (String.concat " " extRulesIndex) 

let stepToString (rulesIndexMap: Map<RuleInfo, int>) (step: Step): string = 
  let (tp, desc) = 
    match step with
    | StepRule r -> "R", (rulesIndexMap |> Map.find (snd r)).ToString()
    | StepMove m -> "M", m.ToString()
  sprintf "<< %s %s" tp desc

let movesToState ((e, s, moves): ProgramMoves): ProgramState = 
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
  e, s, rcr e moves 0

let movesUpdate (p: Move list) (nextMove: Move): Move list =
  p |> List.iter (fun m -> assert(m <> Up))
  match nextMove with 
  | Up -> p |> List.rev |> List.tail |> List.rev
  | _  -> p @ [nextMove]

let stepProg (prog: ProgramState) (step: Step): ProgramState = 
  let (e, s, pos) = prog
  match step with 
  | StepMove(m) -> 
    let (_, _, moves) = stateToMoves prog
    let moves' = movesUpdate moves m
    movesToState (e, None, moves')
  | StepRule(r) ->
    applyRuleAtParticularPosition e (pos, r), None, pos

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


let log_optimize (e: Expr) (rs: List<Rule>) = 
  let debug = false
  let debugger = Logging.consoleLogger debug
  let reporter = Logging.completeReporter (fun (e, _) -> ccodegen.prettyprint e) debugger
  //let t = tic()
  let ((best, appliedRules), _) = 
    beamSearch<Expr * MetaData list> 30 1 (fun x y -> alphaEquals (fst x) (fst y) (Map.empty)) reporter (e, []) (
      fun (e, historyRules) -> 
        let applicableRules = examineAllRulesPositioned rs e
        applicableRules |> List.map (fun r -> applyRuleAtParticularPosition e r, r :: historyRules)
      ) (fun (e, _) -> fopCost e)
  //toc t "beam searching"

  let steps = 
    appliedRulesToSteps e (appliedRules |> List.rev)
 
  let rulesIndexMap = rs |> List.mapi (fun x y -> snd y, x) |> Map.ofList
  //printfn ">> %A" (stateToExternal rs (e, 0))
  printfn "%s" (externalToString rulesIndexMap (stateToExternal rs (e, Some(e), 0)))
  let finalProg = 
    ((e, Some(e), 0), steps)
      ||> List.fold (fun (exp, sexp, pos) step ->
            let newState = stepProg (exp, sexp, pos) step
            let ext = stateToExternal rs newState
            //printfn "<< %A" step
            //printfn ">> %A" ext
            printfn "%s" (stepToString rulesIndexMap step)
            printfn "%s" (externalToString rulesIndexMap ext)
            newState
          )  
  //let (finalProgRoot, _, _) = finalProg
  //printfn "final exp: %s" (ccodegen.prettyprint finalProgRoot)
  printfn "****"
  best

[<Test>]
let testPositionToMoves () =
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

[<Test>]
let testPositionToSubexpr () =
  let exp1 = 
    <@ 
      fun a -> 
        42. + 43.
    @>
  let areEqual e1 e2 =
    Assert.AreEqual(e1, e2, sprintf "Expected: %A\nActual: %A" e2 e1)
  areEqual (positionToSubexpr exp1 0) exp1
  areEqual (positionToSubexpr exp1 1) <@ 42. + 43. @>
  areEqual (positionToSubexpr exp1 2) <@ 42. @>
  areEqual (positionToSubexpr exp1 3) <@ 43. @>

let training_generator(): unit = 
  let outputFile = "../../../outputs/training/training_generated.fs"
  let trainingBase = "training_base"
  let methodsName = compiler.getMethodsOfModule trainingBase
  let methods = methodsName |> List.map (compiler.getMethodExpr trainingBase)
  let numberOfInputs exp = 
      let (TopLevelFunction(ins, body)) = exp
      ins |> List.length
  let methodsScalarOne = methods |> List.filter(fun m -> (numberOfInputs m) = 1)
  let methodsScalarTwo = methods |> List.filter(fun m -> (numberOfInputs m) = 2)
  let methodsScalarOne' = 
    methodsScalarOne |> 
    List.collect (fun m1 ->
      methodsScalarOne 
        |> List.map (fun m2 ->
           match (m1, m2) with
           | Patterns.Lambda(x1, body1), Patterns.Lambda(x2, body2) -> Expr.Lambda(x1, captureAvoidingSubstitution body2 [x2, body1])
           | _ -> failwithf ""
        )
    )
  System.IO.File.WriteAllText(outputFile, """[<ReflectedDefinition>]
module training_generated

open types
open corelang
open cardinality
""")
  methodsScalarOne' |>
    List.iteri (fun i m ->
      let str = sprintf "let scalar_1_%d: Number -> Number = \n %s\n" i (fscodegen.fscodegenTopLevel m)
      printfn "%s" str
      System.IO.File.AppendAllText(outputFile, str)
    )
  let methodsScalaOneAll = (methodsScalarOne, methodsScalarOne') ||> List.append
  let methodsScalarTwo' = 
    methodsScalarTwo |>
    List.collect (fun met ->
      methodsScalaOneAll |>
      List.collect (fun m1 ->
        methodsScalaOneAll |>
        List.map (fun m2 ->
          match (met, m1, m2) with
          | LambdaN([xt1; xt2], bodyt), Patterns.Lambda(x1, body1), Patterns.Lambda(x2, body2) -> 
            let body1' = captureAvoidingSubstitution body1 [x1, Expr.Var(xt1)]
            let body2' = captureAvoidingSubstitution body2 [x2, Expr.Var(xt2)]
            LambdaN([xt1; xt2], captureAvoidingSubstitution bodyt [xt1, body1'; xt2, body2'])
          | _ -> failwithf ""
        )
      )
    )
  methodsScalarTwo' |>
    List.iteri (fun i m ->
      let str = sprintf "let scalar_2_%d: Number -> Number -> Number = \n %s\n" i (fscodegen.fscodegenTopLevel m)
      System.IO.File.AppendAllText(outputFile, str)
    )
  

let main_ml_engine(): unit = 
  //compiler.compileModule "linalg" [] false false
  //let trainingModule = "training_programs"
  //let trainingModule = "training_base"
  let trainingModule = "training_generated"
  let methods = compiler.getMethodsOfModule trainingModule
  let comp = ruleengine.compilePatternToRule
  let rs = 
    [//comp <@ letInliner @> ; 
     rules_old.letCommutingConversion_old; rules_old.letNormalization_old;
     rules_old.letInlinerOnce_old; rules_old.dce_old;
     methodDefToLambda ; lambdaAppToLet;
     constantFold;
     comp <@ vectorBuildGet @>; comp <@ vectorBuildLength @>;
     rules_old.letVectorBuildLength_old; rules_old.letVectorBuildGet_old] @
     algebraicRulesScalar
  let rulesIndexMap = rs |> List.mapi (fun x y -> sprintf "%i -> %s" x (snd y))
  printfn "rule index:\n %s" (rulesIndexMap |> String.concat "\n ")
  let opts = 
    methods 
      //|> Seq.take 3 |> List.ofSeq 
      |> List.map (fun m -> log_optimize (compiler.getMethodExpr trainingModule m) rs)
  //training_generator()
  ()