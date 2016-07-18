module rules

open Microsoft.FSharp.Quotations
open Quotations.DerivedPatterns
open types

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

let letInliner (e: Expr): Expr Option = 
  match e with 
  | Patterns.Let(v, e1, e2) -> Some(e2.Substitute(fun v2 -> if v = v2 then Some(e1) else None))
  | _ -> None

let divide2Mult (e: Expr): Expr Option = 
   match e with 
   | SpecificCall  <@ (/) @> (None, _, [SpecificCall  <@ (/) @> (None, _, [a; b]) ; c]) -> 
     Some(<@@ (%%a: Number) / ((%%b: Number) * (%%c: Number)) @@>)
   | _ -> None
(*
let awfdivide2Mult (e: Expr): Expr Option = 
   Rule <@ (a: Number) / (b: Number) @> (<@@ (%%a: Number) / ((%%b: Number) * (%%c: Number)) @@>)
*)
   

let distrMult (e: Expr): Expr Option = 
   match e with 
   | SpecificCall  <@ (*) @> (None, _, [a; SpecificCall  <@ (+) @> (None, _, [b; c])]) -> 
     Some(<@@ ((%%a: Number) * (%%b: Number)) + ((%%a: Number) * (%%c: Number)) @@>)
   | _ -> None

let constFold1 (e: Expr): Expr Option = 
   match e with 
   | SpecificCall  <@ (*) @> (None, _, [a; b]) when b = <@@ 1. @@> -> 
     Some(a)
   | _ -> None
(*
let awfx (e:Expr) = 
   let (a : Number) = Number 0 in (<@ a * 1. === a @>)
*)

let multDivide (e: Expr): Expr Option = 
   match e with 
   | SpecificCall  <@ (*) @> (None, _, [a; SpecificCall  <@ (/) @> (None, _, [b; c])]) when c = a && b = <@@ 1. @@> -> 
     Some(<@@ 1. @@>)
   | _ -> None

let s_1: Number = 1.0
let s_2: Number = 2.0
let s_3: Number = 3.0
let v_1: Vector = [| s_1 |]
let v_2: Vector = [| s_1 |]
let m_1: Matrix = [| v_1 |]
let m_2: Matrix = [| v_1 |]
let (<==>) (s1: 'a) (s2: 'a):'a = s1

let divide2Mult_2 = <@ ((s_1 / s_2) / s_3) <==> (s_1 / (s_2 * s_3)) @>

let compilePatternToRule(pat: Expr): Rule =
  fun (exp: Expr) ->
    let rec extract(p: Expr, e: Expr): (Var * Expr) List Option = 
      match (p, e) with
      | (Patterns.Var(v), _) when List.exists (fun x -> x = p) [ <@@ s_1 @@>; <@@ s_2 @@>; <@@ s_3 @@> ] -> Some([v, e])
      (*| (ExprShape.ShapeCombination(opraw, pats), ExprShape.ShapeCombination(oeraw, exprs)) when (List.length pats) = (List.length exprs)->
        (*printf "%s" ((op :?> ExprConstInfo).ToString())*)
        let foo = match opraw with 
        | :? (_ * Expr List) as goo ->
          printf "hi"
        let ((op, _), (oe, _)) = unbox<_ * _>(opraw), unbox<_ * _>(oeraw)
        if(op = oe) then 
          let vars = List.map2 (fun vp ve -> extract(vp, ve)) pats exprs
          if(List.forall (Option.isSome) vars) then
            Some(List.concat (List.map (Option.get) vars))
          else
            None
        else
          None
      *)
      | (Patterns.Call(None, op, pats), Patterns.Call(None, oe, exprs)) when (List.length pats) = (List.length exprs)->
        if(op = oe) then 
          let vars = List.map2 (fun vp ve -> extract(vp, ve)) pats exprs
          if(List.forall (Option.isSome) vars) then
            Some(List.concat (List.map (Option.get) vars))
          else
            None
        else
          None
      | _ -> None
    let (boundVarsOpt, rhs) = match pat with 
    | SpecificCall <@ (<==>) @> (None, _, [p; rhs]) -> 
      printfn "pattern is %A and rhs is %A" p rhs
      extract(p, exp), rhs
    | _ -> failwith "Rewrite patterns should be form `lhs <==> rhs`"
    Option.map (fun boundVars -> rhs.Substitute(fun v -> Option.map (fun (_, e) -> e) (List.tryFind (fun (v1, _) -> v = v1) boundVars))) boundVarsOpt


let divide2Mult_3: Rule = compilePatternToRule divide2Mult_2