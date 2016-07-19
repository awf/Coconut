module rules

open Microsoft.FSharp.Quotations
open ruleengine


let divide2Mult_exp = 
  <@ 
    (%s_1 / %s_2) / %s_3
    <==> 
    %s_1 / (%s_2 * %s_3)
  @>

let distrMult_exp = 
  <@
    %s_1 * (%s_2 + %s_3)
    <==>
    %s_1 * %s_2 + %s_1 * %s_3
  @>

let constFold1_exp = 
  <@ 
    (%s_1 * 1.)
    <==>
    (%s_1)
  @>

let multDivide_exp = 
  <@
    %s_1 * (1. / %s_2)
    <==>
    1.
  @>, 
  <@ %s_1 = %s_2 @>

let divide2Mult: Rule = compilePatternToRule divide2Mult_exp
let distrMult: Rule = compilePatternToRule distrMult_exp
let constFold1: Rule = compilePatternToRule constFold1_exp
let multDivide: Rule = compilePatternWithPreconditionToRule multDivide_exp

let letInliner (e: Expr): Expr Option = 
  match e with 
  | Patterns.Let(v, e1, e2) -> Some(e2.Substitute(fun v2 -> if v = v2 then Some(e1) else None))
  | _ -> None