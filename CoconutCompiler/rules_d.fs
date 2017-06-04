module rules_d

open Microsoft.FSharp.Quotations
open ruleengine
open metaVars
open corelang
open types
open cardinality

let D_POSTFIX = "_d"

let add_d        = <@ diff (%a + %b) %dx               <==>   (diff %a %dx) + (diff %b %dx)                @>
let mult_d       = <@ diff (%a * %b) %dx               <==>   (diff %a %dx) * %b + %a * (diff %b %dx)      @>

let var_d: Rule = 
  (fun (e: Expr) ->
    match e with
    | DerivedPatterns.SpecificCall <@ diff @> (_, _, [Patterns.Var(v1); Patterns.Var(v2)]) ->
      let res = 
          if v1 = v2 then 
            Expr.Value(1.f) 
          else if not(v1.Name.EndsWith(D_POSTFIX)) then 
            Expr.Var(new Var(v1.Name + D_POSTFIX, typeof<Number>)) 
          else 
            failwithf "diff of variables %A and %A" v1 v2
      [ res ]
    | _ -> []
  ), "var_d"

let chain_rule: Rule = 
  (fun (e: Expr) ->
    match e with
    | DerivedPatterns.SpecificCall <@ diff @> (_, _, [Patterns.Let(y, e1 ,e2); Patterns.Var(dx)]) ->
      let dy = new Var(y.Name + D_POSTFIX, typeof<Number>)
      let diffCall1 = transformer.MakeCall <@@ diff @@> [e1; Expr.Var(dx)] [typeof<Number>]
      let diffCall2 = transformer.MakeCall <@@ diff @@> [e2; Expr.Var(dy)] [typeof<Number>]
      [Expr.Let(y, e1, Expr.Let(dy, diffCall1, diffCall2))]
    | _ -> []
  ), "chain_rule"