module ruleengine


open Microsoft.FSharp.Quotations
open Quotations.DerivedPatterns
open types

module metaVars =
  let a = Expr.Cast<Number>(Expr.Var(Var.Global("a", typeof<Number>)))
  let b = Expr.Cast<Number>(Expr.Var(Var.Global("b", typeof<Number>)))
  let c = Expr.Cast<Number>(Expr.Var(Var.Global("c", typeof<Number>)))
  let T = Expr.Cast<Vector>(Expr.Var(Var.Global("T", typeof<Vector>)))
  let U = Expr.Cast<Vector>(Expr.Var(Var.Global("U", typeof<Vector>)))
  let V = Expr.Cast<Vector>(Expr.Var(Var.Global("V", typeof<Vector>)))
  let M = Expr.Cast<Matrix>(Expr.Var(Var.Global("M", typeof<Matrix>)))
  let N = Expr.Cast<Matrix>(Expr.Var(Var.Global("N", typeof<Matrix>)))
  let O = Expr.Cast<Matrix>(Expr.Var(Var.Global("O", typeof<Matrix>)))
  let scalarMetaVars = List.map (fun (x: Expr<Number>) -> x.Raw) [a; b; c]
  let vectorMetaVars = List.map (fun (x: Expr<Vector>) -> x.Raw) [T; U; V]
  let matrixMetaVars = List.map (fun (x: Expr<Matrix>) -> x.Raw) [M; N; O]
  let allMetaVars = List.append scalarMetaVars (List.append vectorMetaVars matrixMetaVars)

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

let compilePatternWithPreconditionToRule(pat: Expr, precondition: Expr): Rule =
  let rec extractList(pats: Expr List, exprs: Expr List): (Var * Expr) List Option = 
    let vars = List.map2 (fun vp ve -> extract(vp, ve)) pats exprs
    if(List.forall (Option.isSome) vars) then
      Some(List.concat (List.map (Option.get) vars))
    else
      None
  and extract(p: Expr, e: Expr): (Var * Expr) List Option = 
    match (p, e) with
    | (Patterns.Var(v), _) when List.exists (fun x -> x = p) (metaVars.allMetaVars) -> 
      Some([v, e])
    | (Patterns.Call(None, op, pats), Patterns.Call(None, oe, exprs)) when (List.length pats) = (List.length exprs) && op = oe ->
        extractList(pats, exprs)
    | (ExprShape.ShapeCombination(op, pats), ExprShape.ShapeCombination(oe, exprs)) when (List.length pats) = (List.length exprs) && op = oe ->
        extractList(pats, exprs)
    | (Patterns.Value(v1), Patterns.Value(v2)) when v1 = v2 -> Some([])
    | _ -> None
  let unifiedVars = 
    let rec processPrecondition(pre: Expr): (Var * Var) List =
      match pre with 
      | Patterns.Value(v, _) when v.Equals(true) -> []
      | SpecificCall  <@ (=) @> (None, _, [Patterns.Var(v1) as a; Patterns.Var(v2) as b]) when 
          (List.exists ((=) a) (metaVars.allMetaVars)) && (List.exists ((=) b) (metaVars.allMetaVars)) -> [v1, v2]
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
          Option.map (fun (_, e) -> e) 
            (List.tryFind (fun (v1, _) -> v = v1) boundVars))
      ) unifiedBoundVars
    ) boundVarsOpt
      

let compilePatternToRule (pat: Expr): Rule =
  compilePatternWithPreconditionToRule(pat, <@ true @>)