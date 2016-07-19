module cost

open Microsoft.FSharp.Quotations
open Quotations.DerivedPatterns
open transformer

(* A simple cost model based on the number of floating point operations *)
let rec fopCost(exp: Expr): double = 
  let VAR_INIT = 0.1
  let VAR_ACCESS = 0.1
  let VALUE_ACCESS = 0.1
  let SCALAR_OPERATOR = 1.0
  let UNKNOWN_CALL = 1000.0
  match exp with 
  | Patterns.Call (None, op, elist) -> 
    match op.Name with
    | OperatorName opname -> List.sum (List.map fopCost elist) + SCALAR_OPERATOR
    | name -> 
      printfn "**WARNING!** Does not know how to cost the operator `%s`. Assumes %f to make progress." name UNKNOWN_CALL
      List.sum (List.map fopCost elist) + UNKNOWN_CALL
  | Patterns.Value(_) -> VALUE_ACCESS
  | Patterns.Let(x, e1, e2) -> fopCost(e1) + fopCost(e2) + VAR_INIT
  | Patterns.Var(_) -> VAR_ACCESS
  | Patterns.Lambda(x, e) -> VAR_INIT + fopCost(e)
  | _ -> failwith (sprintf "Does not know how to cost the construct `%A`" exp)
