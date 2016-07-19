module rules

open Microsoft.FSharp.Quotations
open ruleengine
open metaVars


let divide2Mult_exp = 
  <@ 
    (%a / %b) / %c
    <==> 
    %a / (%b * %c)
  @>

let distrMult_exp = 
  <@
    %a * (%b + %c)
    <==>
    %a * %b + %a * %c
  @>

let constFold0_exp = 
  <@ 
    %a + 0.
    <==>
    %a
  @>

let constFold1_exp = 
  <@ 
    %a * 1.
    <==>
    %a
  @>

let subSame_exp = 
  <@
    %a - %a
    <==>
    0.0
  @>

let multDivide_exp = 
  <@
    %a * (1. / %a)
    <==>
    1.
  @>

let assocAddSub_exp = 
  <@
    (%a + %b) - %c
    <==>
    %a + (%b - %c)
  @>

let assocAddAdd_exp = 
  <@
    (%a + %b) + %c
    <==>
    %a + (%b + %c)
  @>

let divide2Mult: Rule = compilePatternToRule divide2Mult_exp
let distrMult: Rule = compilePatternToRule distrMult_exp
let constFold0: Rule = compilePatternToRule constFold0_exp
let constFold1: Rule = compilePatternToRule constFold1_exp
let subSame: Rule = compilePatternToRule subSame_exp
let multDivide: Rule = compilePatternToRule multDivide_exp
let assocAddSub: Rule = compilePatternToRule assocAddSub_exp
let assocAddAdd: Rule = compilePatternToRule assocAddAdd_exp

let letInliner (e: Expr): Expr Option = 
  match e with 
  | Patterns.Let(v, e1, e2) -> Some(e2.Substitute(fun v2 -> if v = v2 then Some(e1) else None))
  | _ -> None