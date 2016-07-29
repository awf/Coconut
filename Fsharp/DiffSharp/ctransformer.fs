module ctransformer

open Microsoft.FSharp.Quotations
open cruntime
open utils
open transformer
open types

(* Performs a simple kind of ANF conversion for specific statements. *)
let rec anfConversion (letRhs: bool) (e: Expr): Expr = 
  match e with 
  | Patterns.Let(x, e1, e2) when not letRhs -> Expr.Let(x, anfConversion true e1, anfConversion false e2)
  | Patterns.Value(v, tp) -> e
  | Patterns.Lambda (x, body) -> Expr.Lambda(x, anfConversion false body)
  | Patterns.NewArray(tp, elems) when not letRhs -> 
    let variable = new Var(newVar "array", e.Type)
    Expr.Let(variable, Expr.NewArray(tp, List.map (anfConversion false) elems), Expr.Var(variable))
  | Patterns.IfThenElse(cond, e1, e2) when not letRhs ->
    let variable = new Var(newVar "ite", e.Type)
    Expr.Let(variable, Expr.IfThenElse(cond, anfConversion false e1, anfConversion false e2), Expr.Var(variable))
  | Patterns.Sequential(e1, e2) when not letRhs ->
    let variable = new Var(newVar "foo", e1.Type)
    Expr.Let(variable, anfConversion true e1, anfConversion false e2)
  | ExprShape.ShapeCombination(o, exprs) ->
    ExprShape.RebuildShapeCombination(o, List.map (anfConversion false) exprs)
  | _ -> e

(* Lifts let bindings to top-level statements *)
let letLifting (e: Expr): Expr = 
  let rec constructTopLevelLets (boundVars: Var List) (exp: Expr): Expr * (Var * Expr) List = 
    match exp with 
    | Patterns.Let(x, e1, e2) ->
      let (te1, liftedLets1) = constructTopLevelLets boundVars e1
      let canBeLifted = List.isEmpty (listDiff (List.ofSeq (e1.GetFreeVars())) boundVars)
      let newBoundVars = if(canBeLifted) then (x :: boundVars) else boundVars
      let (te2, liftedLets2) = constructTopLevelLets newBoundVars e2
      if (canBeLifted) then
        (te2, List.append liftedLets1 ((x, te1) :: liftedLets2))
      else 
        (Expr.Let(x, te1, te2), List.append liftedLets1 liftedLets2)
    | Patterns.Call (None, op, elist) -> 
      let (tes, lls) = List.unzip (List.map (constructTopLevelLets boundVars) elist)
      (Expr.Call(op, tes), List.concat lls)
    | LambdaN (inputs, body) ->
      let (te, ll) = constructTopLevelLets boundVars body
      (LambdaN (inputs, te), ll)
    | Patterns.IfThenElse(cond, e1, e2) ->
      let (te1, liftedLets1) = constructTopLevelLets boundVars e1
      let (te2, liftedLets2) = constructTopLevelLets boundVars e2
      let (tc, liftedLetsc) = constructTopLevelLets boundVars cond
      (Expr.IfThenElse(tc, LetN(liftedLets1, te1), LetN(liftedLets2, te2)), liftedLetsc)
    | ExprShape.ShapeCombination(o, exprs) ->
      let (tes, lls) = List.unzip (List.map (constructTopLevelLets boundVars) exprs)
      (ExprShape.RebuildShapeCombination(o, tes), List.concat lls)
    | _ -> (exp, [])
  let (inputs, body) = match e with TopLevelFunction (i, b) -> (i, b)
  let (te, ll) = constructTopLevelLets inputs body
  (*
  printfn "/* Before Let Lifting code:\n%A\n*/\n" (prettyprint e)
  printfn "/* List of vars:\n%A\n*/\n" (List.map (fun (x, _) -> x) ll)
  printfn "/* After Let Lifting code:\n%A\n*/\n" (prettyprint (LambdaN(inputs, LetN(ll, te))))
  *)
  LambdaN(inputs, LetN(ll, te))
  

(* Performs closure conversion to make the program closer to C code *)
let closureConversion (e: Expr): Expr = 
  let rec lambdaLift (exp: Expr): Expr =
    match exp with 
    | LambdaN (inputs, body) -> 
      let freeVars = listDiff (List.ofSeq (body.GetFreeVars())) inputs
      let newVars = List.map (fun (x: Var) -> new Var(newVar(x.Name), x.Type)) freeVars
      let freeNewVars = List.zip freeVars newVars
      let convertedBody = (lambdaLift body).Substitute(fun v -> 
          Option.map (fun (x, y) -> Expr.Var(y)) (List.tryFind (fun (x, y) -> x = v) freeNewVars))
      let result = 
        let envVar = new Var(newVar "env", typeof<Environment>)
        let env = Expr.Var(envVar)
        let closuredBody = List.fold (fun acc (fcur: Var, ncur: Var) -> 
          let variableName = Expr.Value(fcur.Name)
          let envRefValue = <@@ envRef %%env %%variableName @@>
          let rhs = 
            let getAnyNumericInfo = assembly.GetType("cruntime").GetMethod("getAnyNumeric").MakeGenericMethod(ncur.Type)
            Expr.Call(getAnyNumericInfo, [envRefValue])
          Expr.Let(ncur, rhs, acc)) convertedBody freeNewVars
        let closureFun = LambdaN(envVar :: inputs, closuredBody)
        let assembly = System.Reflection.Assembly.GetExecutingAssembly()
        let makeClosureInfoGeneric = assembly.GetType("cruntime").GetMethod("makeClosure")
        let (inType, outType) = 
          let args = exp.Type.GetGenericArguments()
          (args.[0], args.[1])
        let makeEnvInfo = assembly.GetType("cruntime").GetMethod("makeEnv")
        let makeEnvArg = 
          [List.fold (fun acc (cur: Var) -> 
            let vstr = Expr.Value(cur.Name.ToString())
            let vexp = 
              let v = Expr.Var(cur)
              let makeAnyNumericInfo = assembly.GetType("cruntime").GetMethod("makeAnyNumeric").MakeGenericMethod(v.Type)
              Expr.Call(makeAnyNumericInfo, [v])
            <@@ (((%%vstr: string), (%%vexp: AnyNumeric) ): string * AnyNumeric) :: 
                  (%%acc: (string * AnyNumeric) List) @@> ) <@@ []: (string * AnyNumeric) List @@>  freeVars]
        let createdEnv = Expr.Call(makeEnvInfo, makeEnvArg)
        let makeClosureInfo = makeClosureInfoGeneric.MakeGenericMethod(inType, outType)
        let createdClosure = Expr.Call(makeClosureInfo, [closureFun; createdEnv])
        let applyClosureInfoGeneric = assembly.GetType("cruntime").GetMethod("applyClosure")
        let applyClosureInfo = applyClosureInfoGeneric.MakeGenericMethod(inType, outType)
        let argVar = new Var(newVar "arg", inType)
        let closureVar = new Var(newVar "closure", createdClosure.Type)
        let call = Expr.Lambda(argVar, Expr.Call(applyClosureInfo, [Expr.Var(closureVar); Expr.Var(argVar)]))
        Expr.Let(closureVar, createdClosure, call)
      result
    | Patterns.Let(x, e1, e2) -> Expr.Let(x, lambdaLift e1, lambdaLift e2)
    | Patterns.Value(v, tp) -> exp
    | Patterns.NewArray(tp, elems) -> 
      Expr.NewArray(tp, List.map lambdaLift elems)
    | Patterns.Call (None, op, elist) -> 
      let telist = List.map lambdaLift elist
      Expr.Call(op, telist)
    | Patterns.Call (Some x, op, elist) -> Expr.Call(x, op, List.map lambdaLift elist)
    | Patterns.Var (x) -> Expr.Var(x)
    | ExprShape.ShapeCombination(o, exprs) ->
        ExprShape.RebuildShapeCombination(o, List.map lambdaLift exprs)
    | _ -> failwith (sprintf "%A not handled yet!" exp)
  let (inputs, body) = match e with TopLevelFunction (i, b) -> (i, b)
  let te = lambdaLift(body)
  LambdaN(inputs, te)

(* Prepares the given program for C code generation *)
let cpreprocess (e: Expr): Expr = 
  letLifting (anfConversion false (closureConversion e))