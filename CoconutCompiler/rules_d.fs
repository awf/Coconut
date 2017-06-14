module rules_d

open Microsoft.FSharp.Quotations
open ruleengine
open metaVars
open corelang
open types
open cardinality
open transformer

let mutable env: Map<Var, Var> = Map.empty<Var, Var>
let D_POSTFIX = "_d"
let diffName (name: string): string = sprintf "%s%s" name D_POSTFIX
let rec DT (t: System.Type) = 
    match t with
    | _ when isScalarType t                                 -> t
    | _ when t = typeof<Cardinality>                        -> t
    | _ when t = typeof<Vector> || t = typeof<Matrix> || 
        t = typeof<Matrix3D>                                -> t
    | FunctionType(inputs, o)                               -> 
      let dinputs = inputs |> List.map DT
      FunctionType (inputs @ dinputs) o                  
    | _ -> failwithf "Does not know how to convert the storaged type `%A`" t
let MakeDVar(v: Var): Var = 
  match env.TryFind(v) with 
  | Some(vd) -> vd
  | _        -> 
    let vd = new Var(diffName v.Name, DT v.Type)
    env <- env.Add(v, vd)
    vd
let IsDVar(v: Var): bool = 
  v.Name.EndsWith(D_POSTFIX)
let Diff e dx = 
  MakeCall <@ diff @> [e; dx] [e.Type; dx.Type]

let add_d        = <@ diff (%a + %b) %dx               <==>   (diff %a %dx) + (diff %b %dx)                @>
let sub_d        = <@ diff (%a - %b) %dx               <==>   (diff %a %dx) - (diff %b %dx)                @>
let mult_d       = <@ diff (%a * %b) %dx               <==>   (diff %a %dx) * %b + %a * (diff %b %dx)      @>
let log_d        = <@ diff (log %a)  %dx               <==>   (diff %a %dx) / %a                           @>
let exp_d        = <@ diff (exp %a)  %dx               <==>   (diff %a %dx) * (exp %a)                     @>
let sin_d        = <@ diff (sin %a)  %dx               <==>   (diff %a %dx) * (cos %a)                     @>
let cos_d        = <@ diff (cos %a)  %dx               <==>   (diff %a %dx) * -(sin %a)                    @>

// I guess this should be the case!
let cast_d       = <@ diff ((double) %i)  %dx          <==>   0.                                           @>

let vget_d       = <@ diff ((%V).[%i]) %dx             <==>   (diff %V %dx).[%i]                           @>
let mget_d       = <@ diff ((%M).[%i]) %dx             <==>   (diff %M %dx).[%i]                           @>
let m3get_d      = <@ diff ((%MM).[%i]) %dx            <==>   (diff %MM %dx).[%i]                          @>
// Has a shortcut! Not sure if it could be even zero!
let vlength_d    = <@ diff (length (%V)) %dx           <==>   length (%V)                                  @>
let mlength_d    = <@ diff (length (%M)) %dx           <==>   length (%M)                                  @>
let m3length_d   = <@ diff (length (%MM)) %dx          <==>   length (%MM)                                 @>

let vbuild_d     = 
                    <@ diff (build<Number> %c1 (fun i -> (%B1) i)) %dx 
                                                       <==>   
                       build<Number> %c1 (fun i -> diff ((%B1) i) %dx)  
                                                                                                           @>

let mbuild_d     = 
                    <@ diff (build<Vector> %c1 (fun i -> (%B1) i)) %dx 
                                                       <==>   
                       build<Vector> %c1 (fun i -> diff ((%B1) i) %dx)  
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
       let tupleTp = typeof<Number * Number>.GetGenericTypeDefinition().MakeGenericType(tp, tp)
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
             //<@@ %%body, diff %%body %%dx @@>
             Expr.NewTuple([body; Diff body dx])
           )
         ) 
       let newF = LambdaN([newAcc; idx], newBody ) 
       let newZ = 
         //<@@ %%z, diff %%z %%dx @@>
         Expr.NewTuple([z; Diff z dx ])
       let foldPart = MakeCall <@ foldOnRange @> [newF; newZ; st; en] [tupleTp]
       let final = MakeCall <@ snd @> [foldPart] [tp; tp]
       [ final ]
    | _ -> []
  ), "fold_d"

let build_d: Rule = 
  (fun (e: Expr) ->
    match e with
    | DerivedPatterns.SpecificCall <@ diff @> 
        (_, _, [DerivedPatterns.SpecificCall <@ build @> 
          (_, _, [c; Patterns.Lambda(idx, body)]); Patterns.Var(dx)]) ->
       let tp = body.Type
       let newF = LambdaN([idx], Diff body (Expr.Var(dx)))
       [ MakeCall <@ build @> [c; newF] [tp] ]
    | _ -> []
  ), "build_d"

let const_d: Rule = 
  (fun (e: Expr) ->
    match e with
    | DerivedPatterns.SpecificCall <@ diff @> (_, _, [Patterns.Value(v1, tp); Patterns.Var(v2)]) ->
      let res =
        if(tp = typeof<Number>) then
          Expr.Value(0.)
        else if (tp = typeof<bool>) then
          Expr.Value(false)
        else
          failwithf "No diff rule for value %A" v1
      [ res ]
    | _ -> []
  ), "const_d"

let var_d: Rule = 
  (fun (e: Expr) ->
    match e with
    | DerivedPatterns.SpecificCall <@ diff @> (_, _, [Patterns.Var(v1); Patterns.Var(v2)]) ->
      let res = 
          if v1 = v2 then 
            Expr.Value(1.) 
          else if not(IsDVar(v1)) then 
            Expr.Var(MakeDVar(v1)) 
          else 
            failwithf "diff of variables %A and %A" v1 v2
      [ res ]
    | _ -> []
  ), "var_d"

let if_d: Rule = 
  (fun (e: Expr) ->
    match e with
    | DerivedPatterns.SpecificCall <@ diff @> (_, _, [Patterns.IfThenElse(c, e1, e2); dx]) ->
      let res = 
        Expr.IfThenElse(c, Diff e1 dx, Diff e2 dx)
      [ res ]
    | _ -> []
  ), "if_d"

let chain_rule: Rule = 
  (fun (e: Expr) ->
    match e with
    | DerivedPatterns.SpecificCall <@ diff @> (_, _, [Patterns.Let(y, e1 ,e2); Patterns.Var(dx)]) ->
      let dy = MakeDVar(y)
      let diffCall1 = MakeCall <@@ diff @@> [e1; Expr.Var(dx)] [e1.Type; dx.Type]
      let diffCall2 = MakeCall <@@ diff @@> [e2; Expr.Var(dx)] [e2.Type; dx.Type]
      [Expr.Let(y, e1, Expr.Let(dy, diffCall1, diffCall2))]
    //| DerivedPatterns.SpecificCall <@ diff @> (_, _, [AppN(LambdaN(inputs, body), args); Patterns.Var(dx)]) when (List.length inputs) = (List.length args) ->
    //  let dinputs = inputs |> List.map (MakeDVar)
    //  let diffCalls = args |> List.map (fun e1 -> MakeCall <@@ diff @@> [e1; Expr.Var(dx)] [e1.Type; dx.Type])
    //  let diffCallBody = MakeCall <@@ diff @@> [body; Expr.Var(dx)] [body.Type; dx.Type]
    //  [AppN(LambdaN(List.append inputs dinputs, diffCallBody), List.append args diffCalls)]
    | DerivedPatterns.SpecificCall <@ diff @> (_, _, [AllAppN(Patterns.Var(f), args); Patterns.Var(dx)]) ->
      let diffCalls = args |> List.map (fun e1 -> Diff e1 (Expr.Var(dx)))
      let nf = Expr.Var(MakeDVar f)
      [AppN(nf, List.append args diffCalls)]
    | _ -> []
  ), "chain_rule"