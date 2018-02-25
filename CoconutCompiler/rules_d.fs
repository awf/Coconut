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
let rec DT (dt: System.Type) (t: System.Type) = 
    if dt <> typeof<Number> then
      failwithf "Type %A is not supported yet!" dt
    match t with
    | _ when isScalarType t                                 -> t
    | _ when t = typeof<Cardinality>                        -> t
    | _ when t = typeof<Vector> || t = typeof<Matrix> || 
        t = typeof<Matrix3D>                                -> t
    | FunctionType(inputs, o)                               -> 
      let dinputs = inputs |> List.map (DT dt)
      FunctionType (inputs @ dinputs) o                  
    | _ -> failwithf "Does not know how to convert the storaged type `%A`" t
let MakeDVar(v: Var): Var = 
  match env.TryFind(v) with 
  | Some(vd) -> vd
  | _        -> 
    let vd = new Var(diffName v.Name, DT (typeof<Number>) v.Type) // TODO take other types of dx into account
    env <- env.Add(v, vd)
    vd
let IsDVar(v: Var): bool = 
  v.Name.EndsWith(D_POSTFIX)
let Diff e dx = 
  MakeCall <@ diff @> [e; dx] [e.Type; dx.Type; DT dx.Type e.Type]

type N = Number
type V = Vector
type M = Matrix
type M3 = Matrix3D
type C = Cardinality
type I = Index

let add_D        = <@ D (%a + %b)        <==>   (D %a) + (D %b)            @>
let sub_D        = <@ D (%a - %b)        <==>   (D %a) - (D %b)            @>
let mult_D       = <@ D (%a * %b)        <==>   (D %a) * %b + %a * (D %b)  @>
let div_D        = <@ D (%a / %b)        
                                         <==>   
                      ((D %a) * %b - %a * (D %b)) / (%b * %b)                            
                                                                           @>
let add_AD       = <@ AD_N (%a + %b)     <==> 
                      let ada = (AD_N %a)
                      let adb = (AD_N %b)
                      let pa = fst ada 
                      let da = snd ada 
                      let pb = fst adb 
                      let db = snd adb 
                      (pa + pb, da + db)            
                                                                           @>
let sub_AD       = <@ AD_N (%a - %b)     <==>   
                      let ada = (AD_N %a)
                      let adb = (AD_N %b)
                      let pa = fst ada 
                      let da = snd ada 
                      let pb = fst adb 
                      let db = snd adb 
                      (pa - pb, da - db)
                                                                           @>
let mult_AD      = <@ AD_N (%a * %b)     <==>   
                      let ada = (AD_N %a)
                      let adb = (AD_N %b)
                      let pa = fst ada 
                      let da = snd ada 
                      let pb = fst adb 
                      let db = snd adb 
                      (pa * pb, da * pb + pa * db)
                                                                           @>
let div_AD       = <@ AD_N (%a / %b)     <==>   
                      let ada = (AD_N %a)
                      let adb = (AD_N %b)
                      let pa = fst ada 
                      let da = snd ada 
                      let pb = fst adb 
                      let db = snd adb 
                      (pa / pb, (da * pb - pa * db) / (pb * pb))
                                                                           @>
let log_AD       = <@ AD_N (log %a)  
                                     <==>   
                      let ada = (AD_N %a)
                      (log (fst ada), (snd ada) / (fst ada))               @>
let exp_AD       = <@ AD_N (exp %a)  
                                     <==>   
                      let ada = (AD_N %a)
                      let b = exp (fst ada)
                      (b, (snd ada) * b)                                   @>
let sin_AD       = <@ AD_N (sin %a)  
                                     <==>   
                      let ada = (AD_N %a)
                      let pa = fst ada
                      (sin pa, (snd ada) * (cos pa))                       @>
let cos_AD       = <@ AD_N (cos %a)  
                                     <==>   
                      let ada = (AD_N %a)
                      let pa = fst ada
                      (cos pa, (snd ada) * -(sin pa))                      @>
let tan_AD       = <@ AD_N (tan %a)  
                                     <==>   
                      let ada = (AD_N %a)
                      let pa = fst ada
                      (tan pa, (snd ada) * ((cos pa) ** 2.))
                                                                           @>
let sqrt_AD      = <@ AD_N (sqrt %a) 
                                     <==>   
                      let ada = (AD_N %a)
                      let b = sqrt (fst ada)
                      (b, (snd ada) / (2. * b))                            @>
let if_AD        = <@ AD_N (if %b1 then %a else %b )
                                         <==>   
                      if (fst (AD<bool, bool * bool> %b1)) then (AD_N %a) else (AD_N %b)
                                                                           @>
let build_AD     = 
                   <@ AD_V (build<Number> %c1 %f1)
                                         <==>   
                      (build<Number * Number> %c1 (fun i -> (AD<Index -> Number, Index * Index -> Number * Number> %f1) (i, 0)))
                                                                           @>
let fold_AD     = 
                   <@ AD_N (foldOnRange<Number> %f1 %a %c2 %c1)
                                         <==>   
                      (foldOnRange<Number * Number> (fun acc i -> 
                        (AD<Number -> Index -> Number, (Number * Number) -> (Index * Index) -> (Number * Number)> %f1) acc (i, 0)) 
                        (AD_N %a)(fst (AD_C %c2)) (fst (AD_C %c1)))
                                                                           @>
let get_AD       = <@ AD_N ((%v1).[%i])  <==>   (AD_V %v1).[fst (AD_I %i)]            @>
let length_AD    = <@ AD_C (length (%v1))<==>   (length (AD_V %v1), Card 0)@>

let add_d        = <@ diff<N,N,N> (%a + %b) %dx        <==>   (diff<N,N,N> %a %dx) + (diff<N,N,N> %b %dx)            @>
let sub_d        = <@ diff<N,N,N> (%a - %b) %dx        <==>   (diff<N,N,N> %a %dx) - (diff<N,N,N> %b %dx)            @>
let mult_d       = <@ diff<N,N,N> (%a * %b) %dx        <==>   (diff<N,N,N> %a %dx) * %b + %a * (diff<N,N,N> %b %dx)  @>
let log_d        = <@ diff<N,N,N> (log %a)  %dx        <==>   (diff<N,N,N> %a %dx) / %a                              @>
let exp_d        = <@ diff<N,N,N> (exp %a)  %dx        <==>   (diff<N,N,N> %a %dx) * (exp %a)                        @>
let sin_d        = <@ diff<N,N,N> (sin %a)  %dx        <==>   (diff<N,N,N> %a %dx) * (cos %a)                        @>
let cos_d        = <@ diff<N,N,N> (cos %a)  %dx        <==>   (diff<N,N,N> %a %dx) * -(sin %a)                       @>
let tan_d        = <@ diff<N,N,N> (tan %a)  %dx        <==>   (diff<N,N,N> %a %dx) * ((cos %a) ** 2.)                @>
let sqrt_d       = <@ diff<N,N,N> (sqrt %a)  %dx       <==>   (diff<N,N,N> %a %dx) / (2. * sqrt(%a))                 @>
let div_d        = <@ diff<N,N,N> (%a / %b) %dx        
                                                       <==>   
                      ((diff<N,N,N> %a %dx) * %b - %a * (diff<N,N,N> %b %dx)) / (%b * %b)                            
                                                                                                                     @>

// I guess this should be the case!
let cast_in_d    = <@ diff<N,N,N> ((double) %i)  %dx   <==>   0.                                                     @>
let cast_ci_d    = <@ diff<I,N,I> (cardToInt %c1) %dx  <==>   cardToInt %c1                                          @>

let int_d        = <@ diff<I,N,I> %i %dx               <==>   0                                                      @>

let vget_d       = <@ diff<N,N,N> ((%V).[%i]) %dx      <==>   (diff<V,N,V> %V %dx).[%i]                              @>
let mget_d       = <@ diff<V,N,V> ((%M).[%i]) %dx      <==>   (diff<M,N,M> %M %dx).[%i]                              @>
let m3get_d      = <@ diff<M,N,M> ((%MM).[%i]) %dx     <==>   (diff<M3,N,M3> %MM %dx).[%i]                           @>
// Has a shortcut! Not sure if it could be even zero!
let vlength_d    = <@ diff<C,N,C> (length (%V)) %dx    <==>   length (%V)                                            @>
let mlength_d    = <@ diff<C,N,C> (length (%M)) %dx    <==>   length (%M)                                            @>
let m3length_d   = <@ diff<C,N,C> (length (%MM)) %dx   <==>   length (%MM)                                           @>

let vbuild_d     = 
                    <@ diff<V,N,V> (build<Number> %c1 (fun i -> (%B1) i)) %dx 
                                                       <==>   
                       build<Number> %c1 (fun i -> diff<N,N,N> ((%B1) i) %dx)  
                                                                                                                     @>

let mbuild_d     = 
                    <@ diff<M,N,M> (build<Vector> %c1 (fun i -> (%B1) i)) %dx 
                                                       <==>   
                       build<Vector> %c1 (fun i -> diff<V,N,V> ((%B1) i) %dx)  
                                                                                                                     @>

//let sfold_d      = 
//                    <@ diff (foldOnRange<Number> (fun s i -> (%B1) s i) %a %c1 %c2) %dx 
//                                                       <==>   
//                       snd (foldOnRange<Number * Number> (fun (s, s_d) i -> (%B1) (s) i, let ns = s in let ns_d = s_d in diff ((%B1) s i) %dx) (%a, diff %a %dx) %c1 %c2)
//                       //snd (foldOnRange<Number * Number> (fun s i -> fst s, snd s) (%a, diff %a %dx) %c1 %c2)
//                                                                                                           @>

let tupleType tp1 tp2 = 
    typeof<Number * Number>.GetGenericTypeDefinition().MakeGenericType(tp1, tp2)

let foldDiffTransform (acc: Var) idx body z st en v2 = 
    let tp = acc.Type
    let tupleTp = tupleType tp tp
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
    MakeCall <@ foldOnRange @> [newF; newZ; st; en] [tupleTp]

let fold_d: Rule = 
  (fun (e: Expr) ->
    match e with
    | DerivedPatterns.SpecificCall <@ diff @> 
        (_, _, [DerivedPatterns.SpecificCall <@ foldOnRange @> 
          (_, _, [LambdaN([acc; idx], body); z; st; en]); Patterns.Var(v2)]) ->
       let tp = acc.Type
       let foldPart = foldDiffTransform acc idx body z st en v2
       let final = MakeCall <@ snd @> [foldPart] [tp; tp]
       [ final ]
    | _ -> []
  ), "fold_d"

let letFold_d: Rule = 
  (fun (e: Expr) ->
    match e with
    | DerivedPatterns.SpecificCall <@ diff @> 
        (_, _, [Patterns.Let(x, 
          DerivedPatterns.SpecificCall <@ foldOnRange @> 
              (_, _, [LambdaN([acc; idx], body); z; st; en]), letBody); Patterns.Var(v2)]) ->
       let tp = acc.Type
       let foldPart = foldDiffTransform acc idx body z st en v2
       let tupleX = new Var("tup" + x.Name, tupleType tp tp)
       let dx = MakeDVar(x)
       let diffLetBody = Diff letBody (Expr.Var(v2))
       let final = 
         LetN([tupleX, foldPart; 
               x, MakeCall <@ fst @> [Expr.Var(tupleX)] [tp; tp];
               dx, MakeCall <@ snd @> [Expr.Var(tupleX)] [tp; tp] ],
             diffLetBody)
       [ final ]
    | _ -> []
  ), "letFold_d"

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

let array_d: Rule = 
  (fun (e: Expr) ->
    match e with
    | DerivedPatterns.SpecificCall <@ diff @> 
        (_, _, [Patterns.NewArray(tp, es); Patterns.Var(dx)]) ->
       let des = es |> List.map (fun e -> Diff e (Expr.Var(dx)))  
       [ Expr.NewArray(DT (dx.Type) tp, des) ]
    | _ -> []
  ), "array_d"

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

let card_d: Rule = 
  (fun (e: Expr) ->
    match e with
    | DerivedPatterns.SpecificCall <@ diff @> (_, _, [e1; Patterns.Var(v2)]) when e1.Type = typeof<Cardinality> ->
      [e1]
    | _ -> []
  ), "card_d"

let nondouble_d: Rule = 
  (fun (e: Expr) ->
    match e with
    | DerivedPatterns.SpecificCall <@ diff @> (_, _, [e1; Patterns.Var(v2)]) when 
        isScalarType e1.Type && e1.Type <> typeof<Number> ->
      let res = 
        if e1.Type = typeof<Index> then
          Expr.Value(0)
        else if e1.Type = typeof<bool> then
          Expr.Value(false)
        else if e1.Type = typeof<Cardinality> then
          Expr.Value(Card(0))
        else if e1.Type = typeof<unit> then
          Expr.Value(())
        else if e1.Type = typeof<string> then
          Expr.Value("")
        else 
          failwithf "Type %A not supported yet!" e1.Type
      [res]
    | _ -> []
  ), "nondouble_d"

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

let letIf_d: Rule = 
  (fun (e: Expr) ->
    match e with
    | DerivedPatterns.SpecificCall <@ diff @> 
        (_, _, [Patterns.Let(y, Patterns.IfThenElse(c, e1, e2), body); dx]) ->
      let tp = e1.Type
      let tupleX = new Var("tup" + y.Name, tupleType tp tp)
      let dy = MakeDVar(y)
      let ifPart = 
          Expr.IfThenElse(c, 
            Expr.NewTuple([e1; Diff e1 dx]),
            Expr.NewTuple([e2; Diff e2 dx])
          )
      let res = 
        LetN([tupleX, ifPart; 
              y, MakeCall <@ fst @> [Expr.Var(tupleX)] [tp; tp];
              dy, MakeCall <@ snd @> [Expr.Var(tupleX)] [tp; tp] ],
            Diff body dx)
      [ res ]
    | _ -> []
  ), "letIf_d"

let lambda_d: Rule = 
  (fun (e: Expr) ->
    match e with
    | DerivedPatterns.SpecificCall <@ diff @> (_, _, [LambdaN(inputs, body); Patterns.Var(dx)]) ->
      let dinputs = inputs |> List.map (MakeDVar)
      [LambdaN(inputs @ dinputs, Diff body (Expr.Var(dx)))]
    | _ -> []
  ), "lambda_d"

let chain_rule: Rule = 
  (fun (e: Expr) ->
    match e with
    | DerivedPatterns.SpecificCall <@ diff @> (_, _, [Patterns.Let(y, e1 ,e2); Patterns.Var(dx)]) ->
      let dy = MakeDVar(y)
      let diffCall1 = Diff e1 (Expr.Var(dx))
      let diffCall2 = Diff e2 (Expr.Var(dx))
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

let mio_d = 
  (fun (e: Expr) ->
    match e with
    | DerivedPatterns.SpecificCall <@ diff @> 
        (_, _, [
            DerivedPatterns.SpecificCall <@ matrixRead @> (_, _, _) | 
              DerivedPatterns.SpecificCall <@ numberPrint @> (_, _, _) |
              DerivedPatterns.SpecificCall <@ vectorPrint @> (_, _, _) |
              DerivedPatterns.SpecificCall <@ matrixPrint @> (_, _, _) as e1;
            Patterns.Var(dx)]) ->
       [ e1 ]
    | _ -> []
  ), "mio_d"