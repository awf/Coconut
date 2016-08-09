﻿module ruleengine


open Microsoft.FSharp.Quotations
open Quotations.DerivedPatterns
open types
open transformer

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

type SecondOrderInfo = Var * Var
// In a general case should be `(Var * Expr) list`
type SecondOrderContext = SecondOrderInfo list 

type Binding = FirstOrder of Var * Expr
             | SecondOrder of SecondOrderInfo

let compilePatternToRule2 (pat: Expr): Rule =
  let (|MetaVar|_|) (expr: Expr): Var option = 
    match expr with
    | Patterns.Var(v) when metaVars.isAMetaVar(v) -> 
      Some(v)
    | _ -> None
  let rec extractList(pats: Expr List, exprs: Expr List) (ctx: SecondOrderContext): Binding List Option = 
    let vars = List.map2 (fun vp ve -> extract(vp, ve)(ctx)) pats exprs
    if(List.forall (Option.isSome) vars) then
      Some(List.concat (List.map (Option.get) vars))
    else
      None
  and extract(p: Expr, e: Expr) (ctx: SecondOrderContext): Binding List Option = 
    match (p, e) with
    | (MetaVar(v), _) -> 
      Some([FirstOrder(v, e)])
    | (DerivedPatterns.SpecificCall <@ LET @> (_, _, [pe1; Patterns.Lambda(px, pbody)]), Patterns.Let(ex, ee1, ee2)) -> 
      let re1 = extract (pe1, ee1) ctx
      re1 |>
        Option.bind (fun bindings ->
          extract (pbody, ee2) ((px, ex) :: ctx)
        )
    | (Patterns.Call(None, op, pats), Patterns.Call(None, oe, exprs)) when (List.length pats) = (List.length exprs) && op = oe ->
        extractList(pats, exprs)(ctx)
    | (Patterns.PropertyGet(objp, op, []), Patterns.PropertyGet(obje, oe, [])) when (Option.count objp) = (Option.count obje) && op = oe ->
        extractList(Option.toList objp, Option.toList obje)(ctx)
    | (ExprShape.ShapeCombination(op, pats), ExprShape.ShapeCombination(oe, exprs)) when (List.length pats) = (List.length exprs) && op = oe ->
        extractList(pats, exprs)(ctx)
    | (Patterns.Value(v1), Patterns.Value(v2)) when v1 = v2 -> Some([])
    | _ -> None
  let unification(values: Binding List, unifiedVars: (Var * Var) List): (Var * Expr) List Option = 
    List.fold (fun accOpt (FirstOrder(curv, cure)) -> 
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
        extract (p, exp) [], rhs
      | _ -> failwith "Rewrite patterns should be of the form `lhs <==> rhs`"
    Option.bind (fun boundVarsInit -> 
      let unifiedBoundVars = unification(boundVarsInit, [])
      Option.map (fun boundVars ->
        rhs.Substitute(fun v -> 
          metaVars.getMetaVarAmongGivenVarBindings v boundVars |> Option.map snd
        )
      ) unifiedBoundVars
    ) boundVarsOpt
      

let compilePatternToRule (pat: Expr): Rule =
  compilePatternWithPreconditionToRule(pat, <@ true @>)