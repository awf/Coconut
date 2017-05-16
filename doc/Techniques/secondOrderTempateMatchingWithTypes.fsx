// Examples showing an implementation of the HOL-lite 2nd order matching.  
//
// The specification is roughly 
//   - Just like first order matching
//   - In addition, ``f e1 ... eN`` (where ``f`` is a match variable)
//     matches any term ``e`` with substitution ``f = \v1 ...vN. e[v1/e1]...[vN/eN]``. 
//     That is, occurrences of subterm ``e1`` are replaced by ``v1``, then ``e2`` by ``v2`` 
//     and so on.  This happens left-to-right (unless I've made a mistake on this)
//
// So ``f (x+1) x`` will first abstract syntactic occurrences of ``x+1``, then occurrences of ``x``.
// 
// A final check is made to check that the substitutions have not captured free variables, which allows 
// "independence" checks, giving rewrite rules like
// 
//    FORALL (fun x -> f x OR g)  ==> FORALL (fun x -> f x) OR g
//
// The first example code file has no types but is useful to get the basic idea of the 
// technique. The second example file is where type information is added to terms, and 
// type variables are allowed in the patterns/rules. (Tracking types in the terms is a 
// PITA, and forces you to allow type variables in the patterns/rules.  This creates a 
// lot of incidental complication, but finds bugs earlier)
//
// There may be bugs


/// Types.  For now untyped (i.e. just one type called T)
type Type = 
   | VarTy of string
   | FunTy of Type list * Type 
   | SimpleTy of string

/// Instantiate type variables in an expression (not yet used)
let rec substTyvarsInType (tyslns: Map<string,Type>) ty = 
    match ty with 
    | VarTy v -> if tyslns.ContainsKey v then tyslns.[v] else ty
    | FunTy (dtys,rty) -> FunTy (List.map (substTyvarsInType tyslns) dtys,substTyvarsInType tyslns rty)
    | SimpleTy _ -> ty

/// Record the solution to a type variable 
let recordTypeSolution (key : string, value : Type) (tyslns : Map<string,Type>) = 
    match tyslns.TryFind(key) with
    | Some value2 ->
        if value = value2 then tyslns
        else failwith "recordTypeSolution: different value already present"
    | None ->
        tyslns.Add(key,value)
 

/// Match a term against a pattern, leaving a residue of high-order matches.
//
// env: the alpha-equivalence of variables when procesing this term
// pat: the pattern
// tm: the term being matched
// slns: the solutions to variables so far
// hoMatches: the second order matches accumulated so far
let rec typeMatch (tyslns: Map<string,Type>) pat tm  = 
    match (pat, tm) with
    | VarTy patv, _ -> recordTypeSolution (patv, tm) tyslns
    | FunTy(dtys1,rty1),FunTy(dtys2,rty2) -> (typeMatch tyslns rty1 rty2, dtys1, dtys2) |||> List.fold2 typeMatch
    | SimpleTy nm1, SimpleTy nm2 when nm1 = nm2-> tyslns
    | _ -> failwith "typeMatch: no match"

//--------------------------------------------------
// Variables and Terms

/// Variables.  Note these use structural equality/comparison.
type Var = 
   | V of string * Type
   member v.Type = (let (V(_,ty)) = v in ty)
   member v.Name = (let (V(nm,_)) = v in nm)
   override v.ToString() = v.Name

/// Terms.  No currying nor partial application (App never returns a function).
type Term =  
   | Const of string * Type
   | Var of Var
   | App of Term * Term list
   | Lam of Var list * Term 
   member t.Type = 
       match t with 
       | Const (_,ty) -> ty
       | Var v -> v.Type
       | App (tm,args) -> match tm.Type with FunTy(_,rty) -> rty | _ -> failwith "expected fun type"
       | Lam (vs,b) -> FunTy(vs |> List.map (fun v -> v.Type), b.Type)

//--------------------------------------------------
// Operations on terms

/// Accumulate the free variables in an expression
let rec accFrees fvs (arg: Term) = 
    match arg with 
    | Const _ -> fvs
    | Var v -> Set.add v fvs
    | App (f,xs) -> (accFrees fvs f,xs) ||> List.fold accFrees 
    | Lam (vs,x) -> 
        let bvfs = (frees x,vs) ||> List.fold (fun fvs v -> Set.remove v fvs)
        Set.union bvfs fvs
    
/// Get the free variables in an expression
and frees x = (Set.empty,x) ||> accFrees

/// Free variables in a list of terms
let freesl (xs: Term list) = (Set.empty,xs) ||> List.fold accFrees


let substTyvarsInVar tyslns (V(nm,ty)) = V(nm,substTyvarsInType tyslns ty)

/// Instantiate type variables in an expression (not yet used)
let rec substTyvars tyslns x = 
    match x with 
    | Const (nm,ty) -> Const(nm, substTyvarsInType tyslns ty)
    | Var v -> Var (substTyvarsInVar tyslns v)
    | App (f,xs) -> App (substTyvars tyslns f, List.map (substTyvars tyslns) xs)
    | Lam (vs,x) -> Lam(vs, substTyvars tyslns x)


/// Substitute variables for terms in an expression. TODO: shoud check capture
let rec substVars (slns: Map<Var,Term>) (x:Term) = 
    match x with 
    | Const _ -> x
    | Var v -> if slns.ContainsKey v then slns.[v] else x
    | App (f,xs) -> App (substVars slns f, List.map (substVars slns) xs)
    | Lam (vs,x) -> Lam(vs, substVars slns x)

/// Substitute variables for terms in an expression and beta reduce the indicated variables
let rec substAndReduce (slns: Map<Var,Term>) (betaVars: Set<Var>) (x:Term) = 
    match x with 
    | App ((Var v), args) when betaVars.Contains v ->
        match slns.[v] with
        | Lam(vs,b) -> substVars (Map.ofList(List.zip vs args)) b
        | t ->  App(t, List.map (substAndReduce slns betaVars) args)
    | _ -> 
    match x with 
    | Const _ -> x
    | Var v -> if slns.ContainsKey v then slns.[v] else x
    | App (f,xs) -> App (substAndReduce slns betaVars f, List.map (substAndReduce slns betaVars ) xs)
    | Lam (vs,x) -> Lam(vs, substAndReduce slns betaVars x)

/// Replace the given expressions by the given variables (generalize the expressions)
let rec generalize (abstractions: Map<Term,Var>) (x:Term) = 
    match abstractions.TryFind x with 
    | Some r -> Var r
    | None -> 
    match x with 
    | Const _ -> x
    | Var _ -> x
    | App (f,xs) -> App (generalize abstractions f, List.map (generalize abstractions) xs)
    | Lam (vs,x) -> Lam(vs, generalize abstractions x)



/// Strip off zero or more arguments
let stripApps x =
   match x with 
   | App(tm,args) -> (tm,args)
   | _ -> (x,[])

/// Check alpha-convertibility (For now just equality, TBD)
let areAlphaEquiv (x:Term) (y:Term) = (x = y)

/// Record the solution to a variable up to alpha-equivalence
let recordSolution (key : Var, value : Term) (slns : Map<Var,Term>) = 
    match slns.TryFind(key) with
    | Some value2 ->
        if areAlphaEquiv value value2 then slns
        else failwith "recordSolution: different value (not alpha-equivalent) already present"
    | None ->
        slns.Add(key,value)

/// Record a dummy solution between dummy variables for two types, to help generate type instaniations
let recordDummySolution (key1 : Type,key2: Type) (slns : Map<Var,Term>) =  
     //recordSolution (genVar vty, Var (genVar cty)) slns
     slns

/// Generate a variable
let genVar =
    let mutable nameGen = 0 
    fun ty ->
        nameGen <- nameGen + 1
        V("v" + string nameGen, ty)


//--------------------------------------------------------------
// Second-order "template" matching


/// Represents a residue of the first round of matching
type HoMatch = HoMatch of env:Map<Var,Var> * tm:Term * hoVar: Var * args:Term list

/// Match a term against a pattern, leaving a residue of high-order matches.
//
// env: the alpha-equivalence of variables when procesing this term
// pat: the pattern
// tm: the term being matched
// slns: the solutions to variables so far
// hoMatches: the second order matches accumulated so far
let rec termPartialMatch (env: Map<Var,Var>) ((slns, hoMatches) as acc) pat tm  = 
    match (pat, tm) with
    | Var patv, _ ->
        match env.TryFind patv with
        | Some v2 ->
            if tm = Var v2 then // note, exact term equality needed here
                acc
            else 
                failwith "no match"
        | None ->
            let newSlns = recordSolution (patv, tm) slns
            newSlns, hoMatches

    | Const(vname, vty), Const(cname, cty) -> 
        if vname = cname then 
            if vty = cty then // Note, exact equality needed here
                acc
            else 
                // Make dummies to force the types to match
                let newSlns = recordDummySolution (vty, cty) slns
                newSlns, hoMatches
        else
            failwith "no match"

    | Lam(vv, vbod), Lam(cv, cbod) -> 
        // Make dummies to force the types to match
        let newSlns = (slns,vv,cv) |||> List.fold2 (fun acc vv cv -> recordDummySolution (vv.Type, cv.Type) acc) 
        let env = (env,vv,cv) |||> List.fold2 (fun env vv cv -> env.Add(vv, cv))
        termPartialMatch env (newSlns, hoMatches) vbod cbod 

    // Is this a higher-order variable
    | App((Var hoVar),args), _ when not (env.ContainsKey hoVar)  -> 
        // Make dummies to force the types to match
        let newSlns = 
            if pat.Type = tm.Type then slns
            else recordDummySolution (pat.Type, tm.Type) slns
        let newHoMatches = HoMatch (env, tm, hoVar, args) :: hoMatches
        newSlns, newHoMatches

    | App(lv,rv), _ -> 
        let lc,rc = stripApps tm
        // match the functions
        let newSlns = termPartialMatch env acc lv lc 
        // match the arguments
        (newSlns,rv,rc) |||> List.fold2 (termPartialMatch env)

    | _ -> failwith "no match"



/// Resolve the residue second-order matches, adding to the set of solutions
let resolveHoMatch tyslns (slns:Map<Var,Term>, hoVars:Set<Var>) (HoMatch(env, tm, hoVar, argPats)) = 

    // Collect the known alpha-equivalences and solutions 
    let tmins = 
        freesl argPats 
        |> Set.toList
        |> List.map (fun a ->
            match env.TryFind a with
            | Some x -> substTyvarsInVar tyslns a, Var x
            | None ->
                match slns.TryFind a with
                | Some x ->  substTyvarsInVar tyslns a, x
                | None -> failwith "second order pattern has spillover variable?")
        |> Map.ofList

    // Apply the known solutions
    let argPats = List.map (substTyvars tyslns >> substVars tmins) argPats
    let hoVar = substTyvarsInVar tyslns hoVar

    // Generalize 
    let (hop, args) = stripApps tm 

    // If patterns are syntactically identical then don't record the solution, or just record "hoVar = hop"
    if args = argPats then 
        if hop = Var hoVar then 
            slns, hoVars
        else 
            recordSolution (hoVar, hop) slns, hoVars
    else 
        // Generate variables for the lambdas
        let ginsts = argPats |> List.map (fun p -> match p with Var v -> p, v | _ -> p, genVar p.Type) 
                
        // Abstract the term, replacing the patterns by variables
        let tm' = generalize (Map.ofList ginsts) tm

        // Make the lambda
        let gvs = List.map snd ginsts
        let lambdaTerm = Lam(gvs, tm')

        // Record the solution of hoVar
        let vinsts = recordSolution (hoVar, lambdaTerm) slns

        vinsts, hoVars.Add hoVar


let getTypeSolutions (slns: (Var * Term) list) = 
    (Map.empty, slns) ||> List.fold (fun acc (x, t) -> typeMatch acc x.Type t.Type)

/// Match one term against another.
let termMatch pat tm =
    // Collect the basic matches, with a set of residue 2nd-order match problems
    let slns, hoMatches = termPartialMatch Map.empty (Map.empty, []) pat tm 
    let slnList = Map.toList slns
    let tyslns = getTypeSolutions slnList
    let slns,hoVars = ((slns,Set.empty),hoMatches) ||> List.fold (resolveHoMatch tyslns)
    if not (freesl (List.map snd slnList)  - frees tm).IsEmpty then failwith "no match: capture"
    tyslns, slns, hoVars


/// Match one term against another.
let eqnMatch pat res tm =
    let tyslns,slns,hoVars = termMatch pat tm
    substAndReduce slns hoVars (substTyvars tyslns res)


//---------------------------------------------
// Convert from F# quotations

open FSharp.Quotations
open FSharp.Quotations.Patterns
open FSharp.Quotations.DerivedPatterns

let rec convType (x: System.Type) = 
    if x.Name.Length = 1 then VarTy x.Name
    elif Reflection.FSharpType.IsFunction x then 
        convFunType [] x
    else SimpleTy x.Name 

and convFunType dtys ty = 
    if Reflection.FSharpType.IsFunction ty then 
        let dty,rty = Reflection.FSharpType.GetFunctionElements ty 
        convFunType  (dty::dtys) rty
    else FunTy(List.rev (List.map convType dtys), convType ty)

let rec conv env (x: Expr) = 
   match x with 
   | Var v -> Term.Var (Var.V (v.Name, convType v.Type))
   | Lambda(v,b) -> Term.Lam ([Var.V (v.Name, convType v.Type)], conv env b)
   | Applications(v,bs) -> Term.App (conv env v, List.map (conv env) (List.concat bs))
   | Call(objOpt,m,bs) -> 
       let args = (Option.toList objOpt @ bs) 
       let ty = FunTy(args |> List.map (fun arg -> convType arg.Type), convType x.Type)
       let k = Term.Const(m.Name, ty)
       Term.App (k, List.map (conv env) args)
   | PropertyGet(objOpt,m,bs) -> 
       let args = (Option.toList objOpt @ bs) 
       let ty = FunTy(args |> List.map (fun arg -> convType arg.Type), convType x.Type)
       let k = Term.Const(m.Name, ty)
       Term.App (k, List.map (conv env) args)
   | Int32(n) -> Term.Const(string n, SimpleTy "Int32")
   | Bool(n) -> Term.Const(string n, SimpleTy "Boolean")
   | String(n) -> Term.Const("\"" + string n + "\"", SimpleTy "String")
   | _ -> failwith (sprintf "couldn't convert %A" x)

let q x = conv Map.empty x

q <@ 1 + 1 @>

let eqnMatch2 q1 q2 q3 = eqnMatch (q q1) (q q2) (q q3)
let termMatch2 q1 q2 = termMatch (q q1) (q q2)
let termPartialMatch2 q1 q2 = termPartialMatch Map.empty (Map.empty, []) (q q1) (q q2)

//---------------------------------------------
// Test it out


let LET (x: int) (f: int -> int) = Unchecked.defaultof<int>
let ISEVEN (x:int) = Unchecked.defaultof<bool>
let ISODD (x:int) = Unchecked.defaultof<bool>
let FORALL (f: int -> bool) = Unchecked.defaultof<bool>
let EXISTS (f: int -> bool) = Unchecked.defaultof<bool>
let AND (x:bool) (y:bool) = Unchecked.defaultof<bool>
let OR (x:bool) (y:bool) = Unchecked.defaultof<bool>

type A = UNDEFINED // used as a marker for type variables in rewrite variables
type B = UNDEFINED // used as a marker for type variables in rewrite variables
let F = Expr.GlobalVar<int -> int>("F")
let F2 = Expr.GlobalVar<int -> int -> int>("F2")
let P = Expr.GlobalVar<int -> bool>("P")
let Q = Expr.GlobalVar<bool>("Q")
let x = Expr.GlobalVar<int>("x")
let y = Expr.GlobalVar<int>("y")

let G = Expr.GlobalVar<A>("G")

convType F.Type
convType F2.Type

q <@ (%F) 1 @>

(q <@ %x @>).Type

(q <@ 1 @>).Type

termMatch2 <@ %x @>  <@ 1 @>
termMatch2 <@ %x + %y @>  <@ 1  + 2 @>
// termMatch2 <@ %x + %x @>  <@ 1  + 2 @> // expect error
//termMatch2 <@ %x + %y @>  <@ 1  * 2 @> // expect error

termMatch2 <@ %G @>  <@ 1 @>

termMatch2 <@ (%F) 1 @>  <@ 1 + 2 @>
termMatch2 <@ (%F) 2 @>  <@ 1 + 2 @>
termMatch2 <@ (%F) 3 @>  <@ 1 + 2 @>
termMatch2 <@ LET (%x) (fun c -> (%F) c) @>  <@ LET 3 (fun v -> v + v) @>
termMatch2 <@ LET (%x) (%F) @>  <@ LET 3 (fun v -> v + v) @>

termMatch2 <@ LET (%x) (fun c -> (%F2) 1 c) @>  <@ LET 3 (fun v -> v + 1 + 1) @>

termMatch2 <@ FORALL (fun x -> AND ((%P) x) (%Q)) @>  <@ FORALL (fun x -> AND (ISEVEN x) false) @>
termMatch2 <@ FORALL (fun x -> AND ((%P) x) (%Q)) @>  <@ FORALL (fun x -> AND (AND (ISEVEN x) (ISODD x) ) false) @>

eqnMatch2 <@ FORALL (fun x -> OR ((%P) x) (%Q)) @>  <@ OR (FORALL (fun x -> (%P) x)) (%Q) @>   <@ FORALL (fun x -> OR (AND (ISEVEN x) (ISODD x) ) false) @>

let tyslns,slns,hoVars = termMatch2 <@ FORALL (fun x -> OR ((%P) x) (%Q)) @>  <@ FORALL (fun x -> OR (AND (ISEVEN x) (ISODD x) ) false) @>

substAndReduce slns hoVars (q <@ OR (FORALL (fun x -> (%P) x)) (%Q) @>   )
substAndReduce slns hoVars (q <@ (%P) 1 @>   )

let orRewrite t = eqnMatch2 <@ FORALL (fun x -> OR ((%P) x) (%Q)) @>  <@ OR (FORALL (fun x -> (%P) x)) (%Q) @>  t

orRewrite <@ FORALL (fun x -> OR (AND (ISEVEN x) (ISODD x) ) true) @>
orRewrite <@ FORALL (fun x -> OR (AND (ISODD x) (ISEVEN x) ) false) @>

let orRewrite2 t = eqnMatch2 <@ FORALL (fun x -> OR ((%P) x) (%Q)) @>  <@ OR (FORALL (%P)) (%Q) @>  t

orRewrite2 <@ FORALL (fun x -> OR (AND (ISEVEN x) (ISODD x) ) true) @>
orRewrite2 <@ FORALL (fun x -> OR (AND (ISODD x) (ISEVEN x) ) false) @>

// termMatch2 <@ FORALL (fun x -> AND ((%P) x) (%Q)) @>  <@ FORALL (fun x -> AND false (ISEVEN x)) @> // expect failure due to capture

//  This was a fallback in the original code. Not sure if it's needed.
(*
            | Failure _ -> 
                    let lc, rc = dest_comb tm
                    let lv, rv = dest_comb pat
                    let homs' = 
                        termPartialMatch env rv rc 
                            (slns, (env, lc, lv) :: (tl hoMatches))
                    let tyslns' = getTypeSolutions (fst homs') []
                    resolveHoMatch tyslns' homs'
*)
