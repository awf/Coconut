module optimizer

open Microsoft.FSharp.Quotations
open utils
open types
open transformer
open ruleengine
open rules
open cost
open search

let rec fixPoint (times: int) (f: Expr -> Expr): Expr -> Expr = fun e ->
  let ne = f e
  if times <= 0 || ne = e then
    printf "[Fp %d]" times
    ne
  else
    fixPoint (times - 1) f ne

let recursiveTransformer (rs: Rule List) (e: Expr): Expr = 
  let rec rcr(exp: Expr): Expr = 
    match exp with 
    | ApplicableRule rs rule -> rcr(applyRule rule exp |> List.head)
    | ExprShape.ShapeLambda(i, e) -> Expr.Lambda(i, rcr e)
    | ExprShape.ShapeVar(v) -> Expr.Var(v)
    | ExprShape.ShapeCombination(o, exprs) ->
        ExprShape.RebuildShapeCombination(o, List.map rcr exprs)
  rcr(e)

let examineAllRules (rs: Rule List) (e: Expr): Expr List = 
  let rec rcr(exp: Expr): Expr List = 
    let immediatelyConstructedExpressions =
      rs |> List.collect (fun r -> applyRule r exp) 
    let constructedExpressionsByChildren =
      match exp with 
      | ExprShape.ShapeLambda(i, e) -> List.map (fun x -> Expr.Lambda(i, x)) (rcr e)
      //| LambdaN(is, e) -> List.map (fun x -> LambdaN(is, x)) (rcr e)
      | ExprShape.ShapeVar(v) -> []
      | Patterns.Value(v, tp) -> []
      | ExprShape.ShapeCombination(o, exprs) ->
          let exprsExpressions = List.map (fun e -> rcr e) exprs
          let allChildrenExpressions = 
            List.concat (List.mapi (fun index ec -> 
                  let (pre, post) = List.partition (fun (i, x) -> i < index) (List.mapi (fun i x -> i, x) exprs)
                  List.map (fun cur -> List.append (List.map snd pre) (cur :: (List.tail (List.map snd post))))  ec
            ) exprsExpressions)
          List.map (fun es -> ExprShape.RebuildShapeCombination(o, es)) (allChildrenExpressions)
    List.append immediatelyConstructedExpressions constructedExpressionsByChildren
  rcr(e)

type RulePosition = int

type InputMetaData = RulePosition

type Positioned<'r> = InputMetaData * 'r
type MetaData = Positioned<Rule>

let zeroMetaData: InputMetaData = 0

let rec exprSize (exp: Expr): int =
  match exp with
  | ExprShape.ShapeLambda(i, e)          -> 1 + 1 + exprSize(e)
  | ExprShape.ShapeVar(v)                -> 1 + 1
  | ExprShape.ShapeCombination(o, exprs) -> 1 + (exprs |> List.map exprSize |> List.sum)

let examineAllRulesPositionedImmediately (rs: Rule List) (exp: Expr) (meta: InputMetaData): MetaData List = 
  rs |> List.collect (fun r -> applyRule r exp |> List.map (fun _ -> meta, r)) 

let examineAllRulesPositioned (rs: Rule List) (e: Expr): MetaData List = 
  let rec rcr (exp: Expr) (meta: InputMetaData): MetaData List = 
    let immediatelyConstructedExpressions = examineAllRulesPositionedImmediately rs exp meta
    let constructedExpressionsByChildren =
      match exp with 
      | ExprShape.ShapeLambda(i, e) -> rcr e (meta + 1)
      | ExprShape.ShapeVar(v) -> []
      | Patterns.Value(v, tp) -> []
      | ExprShape.ShapeCombination(o, exprs) ->
          let exprsExpressions = (([], meta + 1), exprs) ||> List.fold (fun (ms, idx) e  -> (rcr e idx) :: ms, idx + exprSize e)
          List.concat (fst exprsExpressions)
    List.append immediatelyConstructedExpressions constructedExpressionsByChildren
  rcr e zeroMetaData

let applyRuleAtParticularPosition (e: Expr) (rule: MetaData): Expr =
  let matchesPosition (meta: InputMetaData): bool = (fst rule) = meta
  let rec rcr (exp: Expr) (meta: InputMetaData): Expr = 
    if matchesPosition meta then
      applyRule (snd rule) exp |> List.head
    else
      match exp with 
      | ExprShape.ShapeLambda(i, e) -> Expr.Lambda(i, rcr e (meta + 1))
      | ExprShape.ShapeVar(v)       -> Expr.Var(v)
      | Patterns.Value(v, tp)       -> Expr.Value(v, tp)
      | ExprShape.ShapeCombination(o, exprs) ->
          let exprsExpressions = (([], meta + 1), exprs) ||> List.fold (fun (ms, idx) e  -> (rcr e idx) :: ms, idx + exprSize e)
          ExprShape.RebuildShapeCombination(o, fst exprsExpressions |> List.rev)
  rcr e zeroMetaData

type RuleWeight = double // should be normalized between 0 and 1
type RuleFeature = RuleWeight

let ZERO_FEATURE = 0.

let heuristicOptimizer (threshold: int) (rs: (Rule * RuleFeature) list) (initProgram: Expr): Expr = 
  let rand = new System.Random()
  let ruleFeaturesMap = rs |> List.map (fun (r, f) -> snd r, f) |> Map.ofList
  let filteredRules = rs |> List.filter (fun (r, f) -> f <> ZERO_FEATURE) |> List.map fst
  let mutable total_progs = 0
  // let tapp = tic()
  // tapp.Stop()
  // let tmatch = tic()
  // tmatch.Stop()
  let mainLoop (currentProgram: Expr) (rule: MetaData): Expr = 
    // tapp.Start()
    let result = applyRuleAtParticularPosition currentProgram rule
    // tapp.Stop()
    result
  let chooseRule (currentProgram: Expr): MetaData option = 
    // tmatch.Start()
    let allApplicablePositionedRules = examineAllRulesPositioned filteredRules currentProgram 
    let rulesCount = allApplicablePositionedRules |> List.length
    total_progs <- total_progs + rulesCount
    // tmatch.Stop()
    // TODO use weigths to make it weighted random selection, however the prefiltering based on
    // zero weights seems to be sufficient for the moment.
    if rulesCount = 0 then
      None
    else
      let randomIndex = rand.Next(rulesCount)
      Some (allApplicablePositionedRules.[randomIndex])
  let result = 
    fixPoint threshold (fun currentProgram -> 
      match chooseRule currentProgram with
      | Some(rule) -> mainLoop currentProgram rule
      | None       -> currentProgram
    ) initProgram
  printfn "%d" total_progs
  // toc tapp
  // toc tmatch
  result

let rec inliner (exp: Expr): Expr = 
  match exp with 
  | ExistingCompiledMethod (methodName, moduleName, argList) ->
    let methodInfo = currentAssembly.GetType(moduleName).GetMethod(methodName)
    let reflDefnOpt = Microsoft.FSharp.Quotations.Expr.TryGetReflectedDefinition(methodInfo)
    let isInlined = Seq.isEmpty (methodInfo.GetCustomAttributes(typeof<DontInline>, true))
    let attrs = (methodInfo.GetMethodImplementationFlags())
    match reflDefnOpt with
    | None -> failwith (sprintf "fatal error! Inlining non-inlinable method: %s.%s!" moduleName methodName)
    | Some(LambdaN(inputs, body)) when isInlined -> 
      let paramVar (p: System.Reflection.ParameterInfo) = 
        (Expr.Var(new Var(p.Name, p.ParameterType)), new Var(newVar p.Name, p.ParameterType))
      let paramList = List.zip inputs (List.map inliner argList)
      captureAvoidingSubstitution body paramList
    | _ -> exp
  | ExprShape.ShapeLambda(i, e) -> Expr.Lambda(i, inliner e)
  | ExprShape.ShapeVar(v) -> Expr.Var(v)
  | ExprShape.ShapeCombination(o, exprs) ->
      ExprShape.RebuildShapeCombination(o, List.map inliner exprs)

let guidedOptimize (e: Expr) (indexedRules: (Rule*int) list): Expr list = 
  let reversedResults = 
    ([e], List.mapi (fun i x -> i, x) indexedRules) ||> List.fold (fun acc (ruleIdx, (rule, idx)) -> 
        let allApplicableSubterms = (examineAllRules [rule] (List.head acc))
        if(idx >= allApplicableSubterms.Length) then 
          failwithf "Error in Rule#%d: There are only %d applicable subterms, however the subterm with index %d was chosen" ruleIdx (allApplicableSubterms.Length) idx
        allApplicableSubterms.[idx] :: acc
      )
  List.rev reversedResults

let optimize (e: Expr): Expr = 
  // let best = inliner(e)
  let debug = false
  let rs = ruleengine.compilePatternToRule <@ letInliner @> (*:: methodDefToLambda :: lambdaAppToLet*) :: algebraicRulesScalar
  (*recursiveTransformer rs e*)
  let debugger = Logging.consoleLogger debug
  let reporter = Logging.completeReporter (ccodegen.prettyprint) debugger
  let t = tic()
  let (best, _) = bfs 5 reporter e (examineAllRules rs) fopCost 
  (*let (best, _) = randomWalk 5 reporter e (examineAllRules rs) fopCost *)
  toc(t)
  
  best
