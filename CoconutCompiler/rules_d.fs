module rules_d

open Microsoft.FSharp.Quotations
open ruleengine
open metaVars
open corelang
open types
open cardinality
open transformer

let D_POSTFIX = "_d"
let MakeDVar(v: Var): Var = 
  new Var(v.Name + D_POSTFIX, v.Type)

let add_d        = <@ diff (%a + %b) %dx               <==>   (diff %a %dx) + (diff %b %dx)                @>
let mult_d       = <@ diff (%a * %b) %dx               <==>   (diff %a %dx) * %b + %a * (diff %b %dx)      @>
let log_d        = <@ diff (log %a)  %dx               <==>   (diff %a %dx) / %a                           @>
let exp_d        = <@ diff (exp %a)  %dx               <==>   (diff %a %dx) * (exp %a)                     @>
let sin_d        = <@ diff (sin %a)  %dx               <==>   (diff %a %dx) * (cos %a)                     @>
let cos_d        = <@ diff (cos %a)  %dx               <==>   (diff %a %dx) * -(sin %a)                    @>
//let vbuild_d     = <@ diff (build<Number> %c1 %F) %dx  <==>   build<Number> %c1 (fun i->diff ((%F)i) %dx)  @>

let get_d        = <@ diff ((%V).[%i]) %dx             <==>   (diff %V %dx).[%i]                           @>
// Has a shortcut! Not sure if it could be even zero!
let length_d     = <@ diff ((%V).Length) %dx           <==>   (%V).Length                                  @>

let vbuild_d     = 
                    <@ diff (build<Number> %c1 (fun i -> (%B1) i)) %dx 
                                                       <==>   
                       build<Number> %c1 (fun i -> diff ((%B1) i) %dx)  
                                                                                                           @>

//let sfold_d      = 
//                    <@ diff (foldOnRange<Number> (fun s i -> (%B1) s i) %a %c1 %c2) %dx 
//                                                       <==>   
//                       snd (foldOnRange<Number * Number> (fun (s, s_d) i -> (%B1) (s) i, let ns = s in let ns_d = s_d in diff ((%B1) s i) %dx) (%a, diff %a %dx) %c1 %c2)
//                       //snd (foldOnRange<Number * Number> (fun s i -> fst s, snd s) (%a, diff %a %dx) %c1 %c2)
//                                                                                                           @>

let fold_d: Rule = 
  (fun (e: Expr) ->
    match e with
    | DerivedPatterns.SpecificCall <@ diff @> 
        (_, _, [DerivedPatterns.SpecificCall <@ foldOnRange @> 
          (_, _, [LambdaN([acc; idx], body); z; st; en]); Patterns.Var(v2)]) ->
       let tp = acc.Type
       let tupleTp = typeof<Number * Number> // TODO generalize
       let newAcc = new Var(utils.newVar acc.Name, tupleTp) 
       let newAccExpr = Expr.Var(newAcc)
       //let newAccNormal = <@@ fst (%%newAccExpr) @@>
       let newAccNormal = MakeCall <@ fst @> [newAccExpr] [tp; tp]
       //let newAccDiff = <@@ snd (%%newAccExpr) @@>
       let newAccDiff = MakeCall <@ snd @> [newAccExpr] [tp; tp]
       let accd = MakeDVar(acc)
       let dx = Expr.Var(v2)
       let newBody = 
         Expr.Let(acc, newAccNormal, 
           Expr.Let(accd, newAccDiff, 
             <@@ (%%body: Number), (diff (%%body: Number) (%%dx: Number)) @@> // TODO generalize
           )
         ) 
       let newF = LambdaN([newAcc; idx], newBody ) 
       let newZ = <@@ ((%%z: Number), diff (%%z: Number) (%%dx: Number)) @@> // TODO generalize
       let foldPart = MakeCall <@ foldOnRange @> [newF; newZ; c1; c2] [tupleTp]
       let final = MakeCall <@ snd @> [foldPart] [tp; tp]
       [ final ]
    | _ -> []
  ), "fold_d"

let const_d: Rule = 
  (fun (e: Expr) ->
    match e with
    | DerivedPatterns.SpecificCall <@ diff @> (_, _, [Patterns.Value(v1); Patterns.Var(v2)]) ->
      [ Expr.Value(0.)  ]
    | _ -> []
  ), "const_d"

let var_d: Rule = 
  (fun (e: Expr) ->
    match e with
    | DerivedPatterns.SpecificCall <@ diff @> (_, _, [Patterns.Var(v1); Patterns.Var(v2)]) ->
      let res = 
          if v1 = v2 then 
            Expr.Value(1.) 
          else if not(v1.Name.EndsWith(D_POSTFIX)) then 
            Expr.Var(MakeDVar(v1)) 
          else 
            failwithf "diff of variables %A and %A" v1 v2
      [ res ]
    | _ -> []
  ), "var_d"

let chain_rule: Rule = 
  (fun (e: Expr) ->
    match e with
    | DerivedPatterns.SpecificCall <@ diff @> (_, _, [Patterns.Let(y, e1 ,e2); Patterns.Var(dx)]) ->
      let dy = MakeDVar(y)
      let diffCall1 = MakeCall <@@ diff @@> [e1; Expr.Var(dx)] [e1.Type; dx.Type]
      let diffCall2 = MakeCall <@@ diff @@> [e2; Expr.Var(dx)] [e2.Type; dx.Type]
      [Expr.Let(y, e1, Expr.Let(dy, diffCall1, diffCall2))]
    //| DerivedPatterns.SpecificCall <@ diff @> (_, _, [AppN(LambdaN(inputs, body), args); Patterns.Var(dx)]) when (List.length inputs) = (List.length args) ->
    //  let dinputs = inputs |> List.map (fun y -> new Var(y.Name + D_POSTFIX, y.Type))
    //  let diffCalls = args |> List.map (fun e1 -> MakeCall <@@ diff @@> [e1; Expr.Var(dx)] [e1.Type; dx.Type])
    //  let diffCallBody = MakeCall <@@ diff @@> [body; Expr.Var(dx)] [body.Type; dx.Type]
    //  [AppN(LambdaN(List.append inputs dinputs, diffCallBody), List.append args diffCalls)]
    | _ -> []
  ), "chain_rule"