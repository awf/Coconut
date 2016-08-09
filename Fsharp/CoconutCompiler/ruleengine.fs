module ruleengine


open Microsoft.FSharp.Quotations
open Quotations.DerivedPatterns
open types
open transformer
open utils

module metaVars =
  let private makeMetaVar<'a> (name: string) = 
    Expr.Cast<'a>(Expr.Var(Var.Global(name, typeof<'a>)))
  let private getExprRaw<'a> (exp: Expr<'a>): Expr = exp.Raw
  let private getExprVar (exp: Expr): Var = match exp with | Patterns.Var(v) -> v | _ -> failwithf "Expected a variable expression, instead given %A" exp
  let i = makeMetaVar<Index>("i")
  let j = makeMetaVar<Index>("j")
  let k = makeMetaVar<Index>("k")
  let a = makeMetaVar<Number>("a")
  let b = makeMetaVar<Number>("b")
  let c = makeMetaVar<Number>("c")
  let T = makeMetaVar<Vector>("T")
  let U = makeMetaVar<Vector>("U")
  let V = makeMetaVar<Vector>("V")
  let M = makeMetaVar<Matrix>("M")
  let N = makeMetaVar<Matrix>("N")
  let O = makeMetaVar<Matrix>("O")
  let F<'a, 'b> = makeMetaVar<'a -> 'b>("F_metavar")
  let G<'a, 'b> = makeMetaVar<'a -> 'b>("G_metavar")
  let E1<'a> = makeMetaVar<'a>("E1_metavar")
  let E2<'a> = makeMetaVar<'a>("E2_metavar")
  let E3<'a> = makeMetaVar<'a>("E3_metavar")
  let B1<'a> = makeMetaVar<'a>("B1_metavar")
  let B2<'a> = makeMetaVar<'a>("B2_metavar")
  let B3<'a> = makeMetaVar<'a>("B3_metavar")
  let private indexMetaVars = List.map getExprRaw [i; j; k]
  let private scalarMetaVars = List.map getExprRaw [a; b; c]
  let private vectorMetaVars = List.map getExprRaw [T; U; V]
  let private matrixMetaVars = List.map getExprRaw [M; N; O]
  let private allMetaVars = indexMetaVars @ scalarMetaVars @ vectorMetaVars @ matrixMetaVars
  let private genericFunctionMetaVars = List.map getExprRaw [F; G]
  let private genericExpressionMetaVars = List.map getExprRaw [E1; E2; E3; B1; B2; B3]
  let private allGenericMetaVars = genericFunctionMetaVars @ genericExpressionMetaVars
  let getMetaVarAmongGivenVarBindings<'a> (var: Var) (givenVarBindings: (Var * 'a) list): (Var * 'a) option = 
    let filterVars(vars: Var list): Var list = vars |> List.filter (fun v -> givenVarBindings |> List.exists (fun gv -> (fst gv).Name = v.Name))
    let allMetaVar = allMetaVars |> List.map getExprVar |> filterVars |> List.tryFind (fun x -> x = var)
    let genericFunctionMetaVar = allGenericMetaVars |> List.map getExprVar |> filterVars |> List.tryFind (fun x -> x.Name = var.Name)
    let resultVar = match allMetaVar with
    | None -> genericFunctionMetaVar
    | _ -> allMetaVar
    resultVar |> Option.map (fun v -> givenVarBindings |> List.find(fun (v2, _) -> v2.Name = v.Name))
  let isAMetaVar (var: Var): bool = 
    getMetaVarAmongGivenVarBindings var (allMetaVars @ allGenericMetaVars |> List.map (fun v -> getExprVar(v), 1)) |> Option.isSome

(*
// Inspired by: https://github.com/jrh13/hol-light/blob/master/nets.ml
module termnet = 
  type TermLabel = Vnet
                 | Cnet of (string * int)
                 | Lnet of int
  type 'a Net = NetNode of (TermLabel * 'a Net) List * 'a List
*)

type Rule = Expr -> Expr Option

let (|ApplicableRule|_|) (rs: Rule List) (e: Expr): (Rule) Option = 
  List.tryFind (fun r -> not(Option.isNone(r e))) rs

let (<==>) (s1: 'a) (s2: 'a):'a = s1

let LET (e1: 'a) (e2: 'a -> 'b): 'b = e2 e1

let compilePatternWithPreconditionToRule(pat: Expr, precondition: Expr): Rule =
  let rec extractList(pats: Expr List, exprs: Expr List): (Var * Expr) List Option = 
    let vars = List.map2 (fun vp ve -> extract(vp, ve)) pats exprs
    if(List.forall (Option.isSome) vars) then
      Some(List.concat (List.map (Option.get) vars))
    else
      None
  and extract(p: Expr, e: Expr): (Var * Expr) List Option = 
    match (p, e) with
    | (Patterns.Var(v), _) when metaVars.isAMetaVar(v) -> 
      Some([v, e])
    | (Patterns.Call(None, op, pats), Patterns.Call(None, oe, exprs)) when (List.length pats) = (List.length exprs) && op = oe ->
        extractList(pats, exprs)
    | (Patterns.PropertyGet(objp, op, []), Patterns.PropertyGet(obje, oe, [])) when (Option.count objp) = (Option.count obje) && op = oe ->
        extractList(Option.toList objp, Option.toList obje)
    | (ExprShape.ShapeCombination(op, pats), ExprShape.ShapeCombination(oe, exprs)) when (List.length pats) = (List.length exprs) && op = oe ->
        extractList(pats, exprs)
    | (Patterns.Value(v1), Patterns.Value(v2)) when v1 = v2 -> Some([])
    | _ -> None
  let unifiedVars = 
    let rec processPrecondition(pre: Expr): (Var * Var) List =
      match pre with 
      | Patterns.Value(v, _) when v.Equals(true) -> []
      | SpecificCall  <@ (=) @> (None, _, [Patterns.Var(v1) as a; Patterns.Var(v2) as b]) when 
          (metaVars.isAMetaVar v1) && (metaVars.isAMetaVar v2) -> [v1, v2]
      | SpecificCall  <@ (&&) @> (None, _, [a; b]) -> List.append (processPrecondition a) (processPrecondition b)
      | _ -> failwith (sprintf "Cannot parse the precondition %A" pre)
    processPrecondition(precondition)
  let unification(values: (Var * Expr) List, unifiedVars: (Var * Var) List): (Var * Expr) List Option = 
    List.fold (fun accOpt (curv, cure) -> 
        Option.bind (fun acc -> 
            let sameVariables = curv :: List.collect (fun (v1, v2) -> if(v1 = curv) then [v2] elif (v2 = curv) then [v1] else []) unifiedVars
            let expressions = List.collect (fun (v, e) -> List.collect (fun v1 -> if(v1 = v) then [e] else []) sameVariables) acc
            let allAreTheSame = List.forall (fun e -> e = cure) expressions
            if(allAreTheSame) then
              Some(List.append acc [curv, cure])
            else 
              None
        ) accOpt
    ) (Some([])) values
  fun (exp: Expr) ->
    let (boundVarsOpt, rhs) = 
      match pat with 
      | SpecificCall <@ (<==>) @> (None, _, [p; rhs]) -> 
        (*printfn "pattern is %A and rhs is %A" p rhs*)
        extract(p, exp), rhs
      | _ -> failwith "Rewrite patterns should be of the form `lhs <==> rhs`"
    Option.bind (fun boundVarsInit -> 
      let unifiedBoundVars = unification(boundVarsInit, unifiedVars)
      Option.map (fun boundVars ->
        rhs.Substitute(fun v -> 
          metaVars.getMetaVarAmongGivenVarBindings v boundVars |> Option.map snd
        )
      ) unifiedBoundVars
    ) boundVarsOpt

let private alphaEquals (e1: Expr) (e2: Expr) = e1 = e2

type QVar = 
  | QVar of Var

  member v.var = let (QVar(v)) = v in v

type QExpr (expr: Expr) = 

  member v.expr = expr

  override qx.Equals(yobj) = 
    match yobj with
    | :? QExpr as qy -> 
      let y = qy.expr
      let x = qx.expr
      alphaEquals x y & x.Type = y.Type
    | _ -> false
  override x.GetHashCode() = 
    (x.expr.GetHashCode())

  interface System.IComparable with
        member x.CompareTo yobj =
            match yobj with
            | :? QExpr as y -> 
              if x.Equals(y) then 
                0 
              else 
                let strCmp = x.expr.ToString().CompareTo(y.expr.ToString())
                if strCmp = 0 then
                  let hashCmp = x.expr.GetHashCode() - y.expr.GetHashCode()
                  if (hashCmp = 0) then
                    failwithf "Find a better comparison method for expressions %A %A" (x.expr) (y.expr)
                  else
                    hashCmp
                else 
                  strCmp
            | _ -> invalidArg "yobj" "cannot compare value of different types"

type private HoMatch = HoMatch of env: Map<QVar, QVar> * term: Expr * hoVar: QVar * args: Expr list
type private Solution = Map<QVar, Expr>
exception NotMatched of string * Expr list

let private findVariableInList<'a> (key: Var) (col: 'a list) (conv: 'a -> Var): 'a option =
  metaVars.getMetaVarAmongGivenVarBindings key (col |> List.map (fun x -> conv x, x))
    |> Option.map snd

let private variableMapGet<'a> (key: Var) (map: Map<QVar, 'a>): 'a option = 
  let res = findVariableInList key (Map.toList map) (fun (QVar(v), _) -> v) |> Option.map snd
  match res with
  | Some v -> res
  | None   -> map.TryFind (QVar key)

let private solutionsGet (key: Var) (solutions: Solution): Expr option = 
  variableMapGet key solutions

let rec private substVars (solutions: Solution) (e: Expr): Expr =
  e.Substitute(fun v -> solutions |> solutionsGet v)

let rec private substAndReduce (solutions: Solution) (betaVars: Set<QVar>) (e: Expr) = 
  match e with
  | AppN(Patterns.Var(v), args) when findVariableInList v (Set.toList betaVars) (fun x -> x.var) |> Option.isSome ->
    match solutionsGet v solutions with
    | Some(LambdaN(inputs, body)) -> 
      let inlinedBody = substVars (List.zip (inputs |> List.map QVar) args |> Map.ofList) body
      substAndReduce solutions betaVars inlinedBody
    | Some(e2) -> Expr.Applications(e2, List.map (fun x -> [substAndReduce solutions betaVars x]) args)
    | None -> failwithf "There is no corresponding value in the solutions %A for the hoVar %A" solutions v
  | _ ->
    match e with
    | Patterns.Var(v) -> solutions |> solutionsGet v |> Option.fold (fun _ x -> x) e
    | LambdaN(inputs, body) -> LambdaN(inputs, substAndReduce solutions betaVars body)
    | ExprShape.ShapeCombination(op, args) -> ExprShape.RebuildShapeCombination(op, args |> List.map (substAndReduce solutions betaVars))
    | _ -> failwithf "substAndReduce doesn't handle %A" e

let private recordSolution (key: Var, value: Expr) (solutions: Solution): Solution = 
  match solutionsGet key solutions with
  | Some value2 ->
    if alphaEquals value value2 then 
      solutions
    else
      raise ( NotMatched("recordSolution: different value (not alpha-equivalent) already present", [value; value2]) )
  | None ->
    solutions.Add(QVar key, value)

let private addVariableSet (vs: Set<QVar>) (v: Var): Set<QVar> = 
  let alreadyContains = 
    metaVars.getMetaVarAmongGivenVarBindings v (Set.toList vs |> List.map(fun (QVar(k)) -> k, k))
    |> Option.isSome
  if alreadyContains then
    vs
  else
    vs.Add(QVar v)

let private accFreeVars (fvs: Set<QVar>) (exp: Expr): Set<QVar> = 
  let newFvs = exp.GetFreeVars()
  (fvs, newFvs) ||> Seq.fold addVariableSet

let private freeVars (exp: Expr) = (Set.empty, exp) ||> accFreeVars

let private freeVarsList (exps: Expr list) = (Set.empty, exps) ||> List.fold accFreeVars

/// Replace the given expressions by the given variables (generalize the expressions)  
let rec generalize (abstractions: Map<QExpr,Var>) (x:Expr): Expr =   
    match abstractions.TryFind (QExpr x) with   
    | Some r -> Expr.Var r  
    | None ->   
      match x with   
      | ExprShape.ShapeVar(v) -> x
      | ExprShape.ShapeLambda(input, body) -> Expr.Lambda(input, generalize abstractions body)
      | ExprShape.ShapeCombination(op, args) -> ExprShape.RebuildShapeCombination(op, args |> List.map (generalize abstractions))


let private resolveHoMatch ((solutions: Solution, hoVars:Set<QVar>) as acc) (HoMatch(env, term, (QVar(hoVar) as qhoVar), argPats)): Solution * Set<QVar> =  
  // Collect the known alpha-equivalences and solutions 
  let termInstantiations =   
    freeVarsList argPats   
    |> Set.toList  
    //|> List.map (fun x -> printf "%A" x; x)
    |> List.map (fun qa  -> 
        let a = qa.var 
        match env.TryFind qa with  
        | Some (QVar x) -> qa, Expr.Var x  
        | None ->  
            match solutionsGet a solutions with  
            | Some x ->  qa, x  
            | None -> failwith "second order pattern has spillover variable?")  
    |> Map.ofList  

  // Apply the known solutions  
  let argPats = List.map (substVars termInstantiations) argPats  
  
  // Generalize  
  let (StripedAppN(hop, args)) = term

  // If patterns are syntactically identical then don't record the solution, or just record "hoVar = hop"  
  if args = argPats then   
      if hop = Expr.Var hoVar then   
          solutions, hoVars  
      else   
          recordSolution (hoVar, hop) solutions, hoVars  
  else   
      // Generate variables for the lambdas  
      let ginsts = argPats |> List.map (fun p -> match p with Patterns.Var v -> QExpr p, v | _ -> QExpr p, new Var(newVar "foo", p.Type))   
                
      // Abstract the term, replacing the patterns by variables  
      let term' = generalize (Map.ofList ginsts) term  
  
      // Make the lambda  
      let gvs = List.map snd ginsts  
      let lambdaTerm = LambdaN(gvs, term')  
  
      // Record the solution of hoVar  
      let vinsts = recordSolution (hoVar, lambdaTerm) solutions  
  
      vinsts, hoVars.Add qhoVar  

let rec private termPartialMatch (env: Map<QVar,QVar>) ((solutions: Solution, hoMatches: HoMatch list) as acc) (pat: Expr) (term: Expr): Solution * HoMatch list =  
  match (pat, term) with
  | Patterns.Var patv, _ ->
    match variableMapGet patv env with
    | Some v2 ->
      if term = Expr.Var(v2.var) then
        acc
      else 
        raise ( NotMatched("Unification problem", [pat; term; Expr.Var(v2.var)]) )
    | None ->
      let newSolutions = recordSolution (patv, term) solutions
      newSolutions, hoMatches
  | (Patterns.Call(None, op, pats), Patterns.Call(None, oe, exprs)) when (List.length pats) = (List.length exprs) && op.Name = oe.Name && op.Module.Name = oe.Module.Name ->
    (acc,pats,exprs) |||> List.fold2 (termPartialMatch env)
  | (Patterns.PropertyGet(objp, op, []), Patterns.PropertyGet(obje, oe, [])) when (Option.count objp) = (Option.count obje) && op = oe ->
    (acc,Option.toList objp,Option.toList obje) |||> List.fold2 (termPartialMatch env)
  | (ExprShape.ShapeCombination(op, pats), ExprShape.ShapeCombination(oe, exprs)) when (List.length pats) = (List.length exprs) && op = oe ->
    (acc,pats,exprs) |||> List.fold2 (termPartialMatch env)
  | (Patterns.Value(v1), Patterns.Value(v2)) when v1 = v2 -> 
    acc
  | (Patterns.Lambda(pv, pbody), Patterns.Lambda(ev, ebody)) ->
    let env' = env.Add(QVar pv, QVar ev)
    termPartialMatch env' (solutions, hoMatches) pbody ebody
  | AppN(Patterns.Var(hoVar), args), _ when variableMapGet hoVar env |> Option.isNone ->
    let newHoMatches = HoMatch (env, term, QVar hoVar, args) :: hoMatches 
    solutions, newHoMatches 

  | AppN(lv, rv), StripedAppN(lc, rc) ->
    let newSolutions = termPartialMatch env acc lv lc
    (newSolutions,rv,rc) |||> List.fold2 (termPartialMatch env) 
  | (DerivedPatterns.SpecificCall <@ LET @> (_, _, [pe1; Patterns.Lambda(px, pe2)]), Patterns.Let(ex, ee1, ee2)) ->
    let (solutions', hoMatches') = termPartialMatch env (solutions, hoMatches) pe1 ee1
    let env' = env.Add(QVar px, QVar ex)
    termPartialMatch env' (solutions', hoMatches') pe2 ee2
  | _ -> 
    raise ( NotMatched("No matched", [pat; term]))

let private termMatch (pat: Expr) (term: Expr): Solution * Set<QVar> = 
  let solutions, hoMatches = termPartialMatch Map.empty (Map.empty, []) pat term
  let solutions, hoVars = ((solutions, Set.empty), hoMatches) ||> List.fold resolveHoMatch
  // TODO capture
  solutions, hoVars

let compilePatternToRule (ruleExpr: Expr): Rule =
  fun (term: Expr) ->
    let (pat, rhs) =
      match ruleExpr with 
      | SpecificCall <@ (<==>) @> (None, _, [p; rhs]) -> 
        (*printfn "pattern is %A and rhs is %A" p rhs*)
        p, rhs
      | _ -> failwith "Rewrite patterns should be of the form `lhs <==> rhs`"
    try
      let solutions, hoVars = termMatch pat term
      let unifiedRhs = substAndReduce solutions hoVars rhs
      Some(unifiedRhs)
    with
      | NotMatched _ -> None
      

let compilePatternToRule2 (pat: Expr): Rule =
  compilePatternWithPreconditionToRule(pat, <@ true @>)