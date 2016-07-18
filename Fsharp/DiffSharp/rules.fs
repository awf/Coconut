module rules

open Microsoft.FSharp.Quotations
open Quotations.DerivedPatterns
open types
  
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