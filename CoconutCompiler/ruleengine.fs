module ruleengine

open System
open Microsoft.FSharp.Quotations
open Quotations.DerivedPatterns
open types
open transformer
open utils

type QVar(var: Var, isTyped: bool) = 

  member v.var = var

  member v.isTyped = isTyped
  
  override qx.Equals(yobj) = 
    match yobj with
    | :? QVar as qy -> 
      let v1 = qx.var
      let v2 = qy.var
      if qx.isTyped && qy.isTyped then
        v1 = v2
      else
        v1.Name = v2.Name
    | _ -> false

  override x.GetHashCode() = 
    (x.var.Name.GetHashCode())

  interface System.IComparable with
    member qx.CompareTo(yobj: obj) = 
      match yobj with
      | :? QVar as qy -> 
        let eq = qx.Equals(yobj)
        if eq then
          0
        else
          let scmp = qx.var.Name.CompareTo(qy.var.Name)
          if scmp = 0 then
            let tcmp = qx.var.Type.ToString().CompareTo(qy.var.Type.ToString())
            if tcmp = 0 then
              let hcmp = qx.var.GetHashCode() - qy.var.GetHashCode()
              if hcmp  = 0 then
                failwithf "Two variables are assumed to be equal, when they are not: %A, %A" qx qy
              else
                hcmp
            else
              tcmp
          else
            scmp
      | _ -> -1

let TypedVar var = new QVar(var, true)
let UntypedVar var = new QVar(var, false)

module metaVars =
  let private makeMetaVar<'a> (name: string) = 
    Expr.Cast<'a>(Expr.Var(Var.Global(name, typeof<'a>)))
  let private getExprRaw<'a> (exp: Expr<'a>): Expr = exp.Raw
  let private getExprVar (exp: Expr): Var = match exp with | Patterns.Var(v) -> v | _ -> failwithf "Expected a variable expression, instead given %A" exp
  type T1 = T
  type T2 = T
  type T3 = T
  let metaTypes = [typeof<T1>; typeof<T2>; typeof<T3>]
  let i = makeMetaVar<Index>("i")
  let j = makeMetaVar<Index>("j")
  let k = makeMetaVar<Index>("k")
  let c1 = makeMetaVar<Cardinality>("c1")
  let c2 = makeMetaVar<Cardinality>("c2")
  let c3 = makeMetaVar<Cardinality>("c3")
  let b1 = makeMetaVar<Boolean>("b1")
  let b2 = makeMetaVar<Boolean>("b2")
  let b3 = makeMetaVar<Boolean>("b3")
  let a = makeMetaVar<Number>("a")
  let b = makeMetaVar<Number>("b")
  let c = makeMetaVar<Number>("c")
  let v1 = makeMetaVar<Vector>("v1")
  let v2 = makeMetaVar<Vector>("v2")
  let v3 = makeMetaVar<Vector>("v3")
  let dx = makeMetaVar<Number>("dx")
  let T = makeMetaVar<Vector>("T")
  let U = makeMetaVar<Vector>("U")
  let V = makeMetaVar<Vector>("V")
  let M = makeMetaVar<Matrix>("M")
  let N = makeMetaVar<Matrix>("N")
  let O = makeMetaVar<Matrix>("O")
  let MM = makeMetaVar<Matrix3D>("MM")
  let NN = makeMetaVar<Matrix3D>("NN")
  let OO = makeMetaVar<Matrix3D>("OO")
  let stg1 = makeMetaVar<Storage>("stg1")
  let stg2 = makeMetaVar<Storage>("stg2")
  let F<'a, 'b> = makeMetaVar<'a -> 'b>("F_metavar")
  let G<'a, 'b> = makeMetaVar<'a -> 'b>("G_metavar")
  let f1<'a, 'b> = makeMetaVar<'a -> 'b>("f1")
  let f2<'a, 'b> = makeMetaVar<'a -> 'b>("f2")
  let E1<'a> = makeMetaVar<'a>("E1_metavar")
  let E2<'a> = makeMetaVar<'a>("E2_metavar")
  let E3<'a> = makeMetaVar<'a>("E3_metavar")
  let B1<'a> = makeMetaVar<'a>("B1_metavar")
  let B2<'a> = makeMetaVar<'a>("B2_metavar")
  let B3<'a> = makeMetaVar<'a>("B3_metavar")
  let private indexMetaVars = List.map getExprRaw [i; j; k]
  let private cardMetaVars = List.map getExprRaw [c1; c2; c3]
  let private scalarMetaVars = List.map getExprRaw [a; b; c; dx]
  let private vectorMetaVars = List.map getExprRaw [T; U; V; v1; v2; v3]
  let private matrixMetaVars = List.map getExprRaw [M; N; O]
  let private matrix3DMetaVars = List.map getExprRaw [MM; NN; OO]
  let private storageMetaVars = List.map getExprRaw [stg1; stg2]
  let private allMetaVars = storageMetaVars @ indexMetaVars @ cardMetaVars @ scalarMetaVars @ vectorMetaVars @ matrixMetaVars @ matrix3DMetaVars
  let private genericFunctionMetaVars = List.map getExprRaw [F; G; f1; f2]
  let private genericExpressionMetaVars = List.map getExprRaw [E1; E2; E3; B1; B2; B3]
  let private allGenericMetaVars = genericFunctionMetaVars @ genericExpressionMetaVars
  let getQMetaVar (var: Var): QVar option =
    let untypedVar = 
      allGenericMetaVars 
      |> List.tryFind (fun e -> (getExprVar e).Name = var.Name)
      |> Option.map (fun e -> UntypedVar (getExprVar e))
    match untypedVar with
    | Some v -> untypedVar
    | None   ->
      allMetaVars 
      |> List.map getExprVar
      |> List.tryFind (fun v -> v = var)
      |> Option.map (fun v -> TypedVar v)

(*
// Inspired by: https://github.com/jrh13/hol-light/blob/master/nets.ml
module termnet = 
  type TermLabel = Vnet
                 | Cnet of (string * int)
                 | Lnet of int
  type 'a Net = NetNode of (TermLabel * 'a Net) List * 'a List
*)

type RuleInfo = string

type Rule = (Expr -> Expr list) * RuleInfo

let applyRule (rule: Rule) (exp: Expr): Expr list =
  (fst rule) exp

let ruleInfo (rule: Rule): RuleInfo =
  snd rule

let (|ApplicableRule|_|) (rs: Rule List) (e: Expr): (Rule) Option = 
  rs |> List.tryFind (fun r -> not (applyRule r e |> List.isEmpty))

let (<==>) (s1: 'a) (s2: 'a):'a = s1

let private alphaEquals (e1: Expr) (e2: Expr) = e1 = e2

type QExpr (expr: Expr) = 

  member v.expr = expr

  override qx.Equals(yobj) = 
    match yobj with
    | :? QExpr as qy -> 
      let y = qy.expr
      let x = qx.expr
      alphaEquals x y && x.Type = y.Type
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

let rec private substVars (solutions: Solution) (e: Expr): Expr =
  e.Substitute(fun v -> solutions.TryFind (TypedVar v))

let rec private substAndReduce (solutions: Solution) (betaVars: Set<QVar>) (typeMapping: (Type * Type) list) (e: Expr) = 
  match e with
  | AppN(Patterns.Var(v), args) when betaVars |> Set.contains (UntypedVar v) ->
    match solutions.TryFind (UntypedVar v)  with
    | Some(LambdaN(inputs, body)) -> 
      let inlinedBody = substVars (List.zip (inputs |> List.map TypedVar) args |> Map.ofList) body
      substAndReduce solutions betaVars typeMapping inlinedBody
    | Some(e2) -> Expr.Applications(e2, List.map (fun x -> [substAndReduce solutions betaVars typeMapping x]) args)
    | None -> failwithf "There is no corresponding value in the solutions %A for the hoVar %A" solutions v
  | Patterns.Let(x, e1, e2) -> // Be default in the RHS, the type of `x` is assumed to be the most generic type.
    let te1 = substAndReduce solutions betaVars typeMapping e1
    let nx = new Var(newVar(x.Name), te1.Type)
    let e2' = substVars (Map.empty.Add(TypedVar x, Expr.Var(nx))) e2
    let te2 = substAndReduce solutions betaVars typeMapping e2'
    Expr.Let(nx, te1, te2)
  | _ ->
    match e with
    | Patterns.Var(v) -> 
       solutions.TryFind (TypedVar v) |> Option.fold (fun _ x -> x) e
    | LambdaN(inputs, body) -> LambdaN(inputs, substAndReduce solutions betaVars typeMapping body)
    | Patterns.Call(None, op, args) when op.IsGenericMethod -> 
      let tps' = op.GetGenericArguments() |> Array.map(fun x -> typeMapping |> List.tryFind(fun (y1, y2) -> y1 = x) |> Option.fold (fun _ x -> snd x) x)
      let op' = op.GetGenericMethodDefinition().MakeGenericMethod(tps')
      Expr.Call(op', args |> List.map (substAndReduce solutions betaVars typeMapping))
    | ExprShape.ShapeCombination(op, args) -> ExprShape.RebuildShapeCombination(op, args |> List.map (substAndReduce solutions betaVars typeMapping))
    | _ -> failwithf "substAndReduce doesn't handle %A" e

let private recordSolution (key: QVar, value: Expr) (solutions: Solution): Solution = 
  match solutions.TryFind key with
  | Some value2 ->
    if alphaEquals value value2 then 
      solutions
    else
      raise ( NotMatched("recordSolution: different value (not alpha-equivalent) already present", [value; value2]) )
  | None ->
    solutions.Add(key, value)

let private addVariableSet (vs: Set<QVar>) (v: Var): Set<QVar> = 
  vs.Add(TypedVar v)


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


let private resolveHoMatch ((solutions: Solution, hoVars:Set<QVar>) as acc) (HoMatch(env, term, hoVar, argPats)): Solution * Set<QVar> =  
  // Collect the known alpha-equivalences and solutions 
  let termInstantiations =   
    freeVarsList argPats   
    |> Set.toList  
    //|> List.map (fun x -> printf "%A" x; x)
    |> List.map (fun qa  -> 
        let a = qa.var 
        match env.TryFind qa with  
        | Some x -> qa, Expr.Var (x.var)
        | None ->  
            match solutions.TryFind (TypedVar a)  with  
            | Some x ->  qa, x  
            | None -> failwith "second order pattern has spillover variable?")  
    |> Map.ofList  

  // Apply the known solutions  
  let argPats = List.map (substVars termInstantiations) argPats  
  
  // Generalize  
  let (StripedAppN(hop, args)) = term

  // If patterns are syntactically identical then don't record the solution, or just record "hoVar = hop"  
  if args = argPats then   
      if hop = Expr.Var (hoVar.var) then   
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
  
      vinsts, hoVars.Add hoVar  

let rec private termPartialMatch (env: Map<QVar,QVar>) ((solutions: Solution, hoMatches: HoMatch list) as acc) (pat: Expr) (term: Expr): Solution * HoMatch list =  
  match (pat, term) with
  | Patterns.Var patv, _ ->
    let qpatv = 
      match metaVars.getQMetaVar patv with
      | Some v -> v
      | None   -> raise ( NotMatched("The variable is not a meta variable", [pat]))
    if qpatv.isTyped && qpatv.var.Type <> term.Type then
      raise ( NotMatched("The meta variable is typed, but the term has a different type", [pat; term]))
    match env.TryFind qpatv with
    | Some v2 ->
      if term = Expr.Var(v2.var) then
        acc
      else 
        raise ( NotMatched("Unification problem", [pat; term; Expr.Var(v2.var)]) )
    | None ->
      let newSolutions = recordSolution (qpatv, term) solutions
      newSolutions, hoMatches
  | AppN(Patterns.Var(hoVar), args), _ when env.TryFind (UntypedVar hoVar)  |> Option.isNone ->
    let newHoMatches = HoMatch (env, term, UntypedVar hoVar, args) :: hoMatches
    solutions, newHoMatches 
  | (Patterns.Call(None, op, pats), Patterns.Call(None, oe, exprs)) when (List.length pats) = (List.length exprs) && op.Name = oe.Name && op.Module.Name = oe.Module.Name ->
    (acc,pats,exprs) |||> List.fold2 (termPartialMatch env)
  | (Patterns.PropertyGet(objp, op, []), Patterns.PropertyGet(obje, oe, [])) when (Option.count objp) = (Option.count obje) && op = oe ->
    (acc,Option.toList objp,Option.toList obje) |||> List.fold2 (termPartialMatch env)
  | (ExprShape.ShapeCombination(op, pats), ExprShape.ShapeCombination(oe, exprs)) when (List.length pats) = (List.length exprs) && op = oe ->
    (acc,pats,exprs) |||> List.fold2 (termPartialMatch env)
  | (Patterns.Value(v1), Patterns.Value(v2)) when v1 = v2 -> 
    acc
  | (Patterns.Lambda(pv, pbody), Patterns.Lambda(ev, ebody)) ->
    let env' = env.Add(UntypedVar pv, UntypedVar ev)
    termPartialMatch env' (solutions, hoMatches) pbody ebody
  | AppN(lv, rv), StripedAppN(lc, rc) ->
    let newSolutions = termPartialMatch env acc lv lc
    (newSolutions,rv,rc) |||> List.fold2 (termPartialMatch env) 
  | (Patterns.Let(px, pe1, pe2), Patterns.Let(ex, ee1, ee2)) ->
    let (solutions', hoMatches') = termPartialMatch env (solutions, hoMatches) pe1 ee1
    let env' = env.Add(UntypedVar px, UntypedVar ex)
    termPartialMatch env' (solutions', hoMatches') pe2 ee2
  | _ -> 
    raise ( NotMatched("No matched", [pat; term]))

let private termMatch (pat: Expr) (term: Expr): Solution * Set<QVar> = 
  let solutions, hoMatches = termPartialMatch Map.empty (Map.empty, []) pat term
  let solutions, hoVars = ((solutions, Set.empty), hoMatches) ||> List.fold resolveHoMatch
  if not (freeVarsList (List.map snd (Map.toList solutions))  - freeVars term).IsEmpty then raise ( NotMatched("Captured variables", [pat; term]))
  solutions, hoVars

let compilePatternWithNameToRule (ruleExpr: Expr) (name: string): Rule =
  let ruleFunction = 
   fun (term: Expr) ->
    let (pat, rhs) =
      match ruleExpr with 
      | SpecificCall <@ (<==>) @> (None, _, [p; rhs]) -> 
        (*printfn "pattern is %A and rhs is %A" p rhs*)
        p, rhs
      | _ -> failwith "Rewrite patterns should be of the form `lhs <==> rhs`"
    try
      let solutions, hoVars = termMatch pat term
      let rec typeContains (tp2: Type) (tp1: Type): bool =
        tp1 = tp2 ||
          tp1.GenericTypeArguments |> Seq.exists (typeContains tp2)
      let rec findInType (tpSrc: Type) (tpDest: Type) (tpToFind: Type): Type option = 
        if tpSrc = tpToFind then
          Some(tpDest)
        else
          (tpSrc.GenericTypeArguments, tpDest.GenericTypeArguments) ||> Seq.zip |> Seq.choose (fun (x, y) -> findInType x y tpToFind) |> Seq.tryFind (fun x -> true)
      let typeMapping = 
        solutions |> Map.toList 
        |> List.choose (fun (v, e) -> 
            if (metaVars.metaTypes |> List.exists (fun x -> typeContains x v.var.Type)) then
              let metaType = metaVars.metaTypes |> List.find (fun x -> typeContains x v.var.Type)
              let convertedType = findInType v.var.Type e.Type metaType |> Option.get
              Some(metaType, convertedType)
            else
              None
           )
      let unifiedRhs = substAndReduce solutions hoVars typeMapping rhs
      [unifiedRhs]
    with
      | NotMatched _ -> []
  ruleFunction, name

let compilePatternToRuleGeneric<'a, 'b> (compiler: Expr -> string -> 'b) (ruleExprWithName: Expr): 'b =
  match ruleExprWithName with
  | Patterns.PropertyGet(None, op, []) -> 
    let expr = op.GetMethod.Invoke(assembly.GetModule("rules"), [| |]) :?> Expr
    compiler expr op.Name
  | exp             -> failwithf "compileNamedPatternToRule should receive a property from the rules module, but received `%A` instead" exp

let compilePatternToRule<'a> (ruleExprWithName: Expr): Rule =
  compilePatternToRuleGeneric compilePatternWithNameToRule ruleExprWithName 

let compilePatternWithNameToScalaCode (ruleExpr: Expr) (name: string): string =
  let (pat, rhs) =
    match ruleExpr with 
    | SpecificCall <@ (<==>) @> (None, _, [p; rhs]) -> 
      (*printfn "pattern is %A and rhs is %A" p rhs*)
      p, rhs
    | _ -> failwith "Rewrite patterns should be of the form `lhs <==> rhs`"
  let rec extractVars(e: Expr): Var list = 
    match e with
    | Patterns.Var(v) -> [v]
    | ExprShape.ShapeCombination(op, es) -> es |> List.map extractVars |> List.concat
    | Patterns.Lambda(x, body) -> x :: (extractVars body)
    | _ -> failwithf "Patterns do not support %A" e

  let operatorName (op: Reflection.MethodInfo) = 
    match op.Name with
    | "op_UnaryNegation"  -> "_"
    | OperatorName opname -> opname
    | "D"                 -> "D"
    | "AD" | "AD_N" | "AD_V"
    | "AD_C" | "AD_I"     -> "AD"
    | "GetArray"          -> "G"
    | "length"            -> "S"
    | "build"             -> "B"
    | "foldOnRange"       -> "F"
    | "Fst"               -> "_1"
    | "Snd"               -> "_2"
    | "Log"               -> "log"
    | "Sin"               -> "sin"
    | "Cos"               -> "cos"
    | "Tan"               -> "tan"
    | "Exp"               -> "exp"
    | "Sqrt"              -> "sqrt"
    | "op_Exponentiation" -> "pow"
    | n -> failwithf "Operator %s not supported!" n
  let compileSubs (s: Expr): string = 
    let rec rcr (e: Expr): string = 
      let rcrArgs es opName = 
        let ss = es |> List.map rcr
        sprintf "Comb(Seq(Var('%s), %s))" opName (ss |> String.concat ", ")
      match e with
      | Patterns.Var(v) -> v.ToString()
      | Patterns.Call(None, op, es) ->
        let opName = operatorName op
        let args = if(opName = "F") then [ es.[0]; es.[1]; es.[3] ] else es 
        rcrArgs args opName
      | Patterns.Value(v, _) -> sprintf "Value(%s)" (v.ToString())
      | Patterns.IfThenElse(e1, e2, e3) ->
        rcrArgs [e1; e2; e3] "I"
      | Patterns.NewTuple([e1; e2]) ->
        rcrArgs [e1; e2] "P"
      | CardConstructor c -> 
        rcr c
      | Patterns.Lambda(x, body) ->
        rcrArgs [Expr.Var(x); body] "L"
      | Patterns.Application(e1, e2) ->
        rcrArgs [e1; e2] "A"
      | Patterns.Let(x, e1, e2) ->
        rcr(Expr.Application(Expr.Lambda(x, e2), e1))
      | _ ->
        failwithf "Substitution %A not supported!" e
    rcr s
  let compilePattern (patternVarsCount: Map<Var, int>) (p: Expr) : string = 
    let rec rcr (varsCount: Map<Var, int>) (e: Expr): (string * Map<Var, int>) = 
      let rcrArgs es opName = 
        let (ss, m') = 
          (([], varsCount), es) ||> 
          List.fold (fun (l, m) e -> 
            let (s, m') = rcr m e
            (s :: l, m')
          )
        sprintf "Comb(Seq(Var('%s), %s))" opName (ss |> List.rev |> String.concat ", "), m'
      match e with
      | Patterns.Var(v) -> 
        if(patternVarsCount.[v] > 1) then
          match varsCount |> Map.tryFind v with
          | Some c -> sprintf "%s%d" (v.ToString()) c, varsCount |> Map.add v (c + 1)
          | None -> v.ToString(), varsCount |> Map.add v 2
        else
          v.ToString(), varsCount
      | Patterns.Call(None, op, es) ->
        let opName = operatorName op
        let args = if(opName = "F") then [ es.[0]; es.[1]; es.[3] ] else es 
        rcrArgs args opName
      | Patterns.Value(v, _) -> sprintf "Value(%s)" (v.ToString()), varsCount
      | Patterns.IfThenElse(e1, e2, e3) ->
        rcrArgs [e1; e2; e3] "I"
      | Patterns.NewTuple([e1; e2]) ->
        rcrArgs [e1; e2] "P"
      | CardConstructor c -> 
        rcr varsCount c
      | Patterns.Lambda(x, body) ->
        rcrArgs [Expr.Var(x); body] "L"
      | Patterns.Application(e1, e2) ->
        rcrArgs [e1; e2] "A"
      | Patterns.Let(x, e1, e2) ->
        rcr varsCount (Expr.Application(Expr.Lambda(x, e2), e1))
      | _ ->
        failwithf "Pattern %A not supported!" e
    rcr Map.empty p |> fst
  let generateScalaPatMat name pat rhs = 
    let patternVars: Var list = extractVars pat
    let subsVars: Var list = extractVars rhs
    //printfn "patternVars: %A" patternVars
    let patternVarsCount = patternVars |> Seq.countBy (id) |> Map.ofSeq
    //printfn "patternVarsCount: %A" patternVarsCount
    let gaurd = 
      if patternVarsCount |> Map.exists (fun k c -> c > 1) then
        let vs = patternVarsCount |> Map.filter (fun k c -> c > 1)
        let conds = 
          vs |> Map.toSeq 
          |> Seq.collect (fun (k,c) -> 
               [
                 for i = 2 to c do 
                   yield sprintf "%s == %s%d" (k.ToString()) (k.ToString()) i
               ])
        sprintf " if %s" (conds |> String.concat " && ")
      else
        ""
    let introducedVars = (subsVars |> Set.ofList, patternVars |> Set.ofList) ||> Set.difference |> Set.toList
    let someCase = 
      match introducedVars with
      | []   -> sprintf "Some(%s)" (rhs |> compileSubs)
      | vars -> sprintf "{%s; Some(%s)}" (vars |> List.map (fun v -> sprintf "val %s = randTerm()" (v.ToString())) |> String.concat ";") (rhs |> compileSubs)
    let noneCase = 
      match pat with
      | Patterns.Var(_) -> "" // in order to not generate a warning by the scala compiler for an unreachable pattern.
      | _ -> "  case _ => None\n"
    sprintf "def %s(t: Term): Option[Term] = t match {\n  case %s%s => %s\n%s}"
      name (pat |> (compilePattern patternVarsCount)) gaurd someCase noneCase
  let ruleStr = generateScalaPatMat name pat rhs
  let invName = sprintf "%s_inv" name
  let invRuleStr = 
      generateScalaPatMat invName rhs pat
  let ruleInfo = 
    sprintf "val %s_info = BidirectionalRule(\"%s\", %s, %s, %s _, %s _)"
      name name (pat |> compileSubs) (rhs |> compileSubs) name invName
  sprintf "%s\n%s\n%s" ruleInfo ruleStr invRuleStr