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

/// Variables.  Note these use structural equality/comparison.
type Var = string

/// Terms.  No currying nor partial application (App never returns a function).
type Term =  
   | Const of string 
   | Var of Var
   | App of Term * Term list
   | Lam of Var list * Term 

//-------------------------------------------------------------------------------
// Operations on terms


/// Strip off zero or more arguments
let stripApps x =
   match x with 
   | App(tm,args) -> (tm,args)
   | _ -> (x,[])

/// Check alpha-convertibility (For now just equality, TBD)
let areAlphaEquiv (x:Term) (y:Term) = (x = y)
 

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

/// Substitute variables for terms in an expression.  TODO: shoud check capture
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

/// Generate a variable
let genVar =
    let mutable nameGen = 0 
    fun () ->
        nameGen <- nameGen + 1
        "v" + string nameGen

/// Record the solution to a variable up to alpha-equivalence
let recordSolution (key : Var, value : Term) (slns : Map<Var,Term>) = 
    match slns.TryFind(key) with
    | Some value2 ->
        if areAlphaEquiv value value2 then slns
        else failwith "recordSolution: different value (not alpha-equivalent) already present"
    | None ->
        slns.Add(key,value)

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

    | Const(vname), Const(cname) ->  if vname = cname then acc else failwith "no match"

    | Lam(vv, vbod), Lam(cv, cbod) -> 
        let env = (env,vv,cv) |||> List.fold2 (fun env vv cv -> env.Add(vv, cv))
        termPartialMatch env (slns, hoMatches) vbod cbod 

    // Is this a higher-order variable
    | App((Var hoVar),args), _ when not (env.ContainsKey hoVar)  -> 
        let newHoMatches = HoMatch (env, tm, hoVar, args) :: hoMatches
        slns, newHoMatches

    | App(lv,rv), _ -> 
        let lc,rc = stripApps tm
        // match the functions
        let newSlns = termPartialMatch env acc lv lc 
        // match the arguments
        (newSlns,rv,rc) |||> List.fold2 (termPartialMatch env)

    | _ -> failwith "no match"


/// Resolve the residue second-order matches, adding to the set of solutions
let resolveHoMatch (slns:Map<Var,Term>, hoVars:Set<Var>) (HoMatch(env, tm, hoVar, argPats)) = 

    // Collect the known alpha-equivalences and solutions 
    let tmins = 
        freesl argPats 
        |> Set.toList
        |> List.map (fun a ->
            match env.TryFind a with
            | Some x -> a, Var x
            | None ->
                match slns.TryFind a with
                | Some x ->  a, x
                | None -> failwith "second order pattern has spillover variable?")
        |> Map.ofList

    // Apply the known solutions
    let argPats = List.map (substVars tmins) argPats

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
        let ginsts = argPats |> List.map (fun p -> match p with Var v -> p, v | _ -> p, genVar()) 
                
        // Abstract the term, replacing the patterns by variables
        let tm' = generalize (Map.ofList ginsts) tm

        // Make the lambda
        let gvs = List.map snd ginsts
        let lambdaTerm = Lam(gvs, tm')

        // Record the solution of hoVar
        let vinsts = recordSolution (hoVar, lambdaTerm) slns

        vinsts, hoVars.Add hoVar

/// Match one term against another.
let termMatch pat tm =
    // Collect the basic matches, with a set of residue 2nd-order match problems
    let slns, hoMatches = termPartialMatch Map.empty (Map.empty, []) pat tm 
    let slns,hoVars = ((slns,Set.empty),hoMatches) ||> List.fold resolveHoMatch
    if not (freesl (List.map snd (Map.toList slns))  - frees tm).IsEmpty then failwith "no match: capture"
    slns,hoVars


/// Match one term against another and apply the generated substitution to another term (normally the r.h.s. of an equation)
let eqnMatch pat res tm =
    let slns,hoVars = termMatch pat tm
    substAndReduce slns hoVars  res


//--------------------------------------------------------------
// Convert from F# quotations

open FSharp.Quotations
open FSharp.Quotations.Patterns
open FSharp.Quotations.DerivedPatterns
let rec conv env (x: Expr) = 
   match x with 
   | Var v -> Term.Var v.Name
   | Lambda(v,b) -> Term.Lam ([v.Name], conv env b)
   | Applications(v,bs) -> Term.App (conv env v, List.map (conv env) (List.concat bs))
   | Call(objOpt,m,bs) -> Term.App (Term.Const(m.Name), List.map (conv env) (Option.toList objOpt @ bs))
   | PropertyGet(objOpt,m,bs) -> Term.App (Term.Const(m.Name), List.map (conv env) (Option.toList objOpt @ bs))
   | Int32 n -> Term.Const(string n)
   | Bool n -> Term.Const(string n)
   | String n -> Term.Const("\"" + string n + "\"")
   | _ -> failwith (sprintf "couldn't convert %A" x)

let q x = conv Map.empty x

let eqnMatch2 q1 q2 q3 = eqnMatch (q q1) (q q2) (q q3)
let termMatch2 q1 q2 = termMatch (q q1) (q q2)
let termPartialMatch2 q1 q2 = termPartialMatch Map.empty (Map.empty, []) (q q1) (q q2)

//--------------------------------------------------------------
// Test it out


let LET (x: int) (f: int -> int) = Unchecked.defaultof<int>
let ISEVEN (x:int) = Unchecked.defaultof<bool>
let ISODD (x:int) = Unchecked.defaultof<bool>
let FORALL (f: int -> bool) = Unchecked.defaultof<bool>
let EXISTS (f: int -> bool) = Unchecked.defaultof<bool>
let AND (x:bool) (y:bool) = Unchecked.defaultof<bool>
let OR (x:bool) (y:bool) = Unchecked.defaultof<bool>
let F = Expr.GlobalVar<int -> int>("F")
let F2 = Expr.GlobalVar<int -> int -> int>("F2")
let P = Expr.GlobalVar<int -> bool>("P")
let Q = Expr.GlobalVar<bool>("Q")
let x = Expr.GlobalVar<int>("x")
let y = Expr.GlobalVar<int>("y")

q <@ 1 + 1 @>
q <@ (%F) 1 @>

termMatch2 <@ %x @>  <@ 1 @>
termMatch2 <@ %x + %y @>  <@ 1  + 2 @>
//termMatch2 <@ %x + %x @>  <@ 1  + 2 @> // expect error
//termMatch2 <@ %x + %y @>  <@ 1  * 2 @> // expect error

termMatch2 <@ (%F) 1 @>  <@ 1 + 2 @>
termMatch2 <@ (%F) 2 @>  <@ 1 + 2 @>
termMatch2 <@ (%F) 3 @>  <@ 1 + 2 @>
termMatch2 <@ LET (%x) (fun c -> (%F) c) @>  <@ LET 3 (fun v -> v + v) @>
termMatch2 <@ LET (%x) (%F) @>  <@ LET 3 (fun v -> v + v) @>

termMatch2 <@ LET (%x) (fun c -> (%F2) 1 c) @>  <@ LET 3 (fun v -> v + 1 + 1) @>

termMatch2 <@ FORALL (fun x -> AND ((%P) x) (%Q)) @>  <@ FORALL (fun x -> AND (ISEVEN x) false) @>
termMatch2 <@ FORALL (fun x -> AND ((%P) x) (%Q)) @>  <@ FORALL (fun x -> AND (AND (ISEVEN x) (ISODD x) ) false) @>

eqnMatch2 <@ FORALL (fun x -> OR ((%P) x) (%Q)) @>  <@ OR (FORALL (fun x -> (%P) x)) (%Q) @>   <@ FORALL (fun x -> OR (AND (ISEVEN x) (ISODD x) ) false) @>



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
