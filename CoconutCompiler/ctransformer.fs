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
  | Patterns.NewArray(tp, elems) when not letRhs && not (tp.Name = typeof<_ -> _>.Name)  -> 
    let variable = new Var(newVar "array", e.Type)
    Expr.Let(variable, Expr.NewArray(tp, List.map (anfConversion false) elems), Expr.Var(variable))
  | Patterns.IfThenElse(cond, e1, e2) when not letRhs ->
    let variable = new Var(newVar "ite", e.Type)
    Expr.Let(variable, Expr.IfThenElse(cond, anfConversion false e1, anfConversion false e2), Expr.Var(variable))
  | Patterns.Sequential(e1, e2) when not letRhs ->
    let variable = new Var(newVar "foo", e1.Type)
    Expr.Let(variable, anfConversion true e1, anfConversion false e2)
  | DerivedPatterns.SpecificCall <@ snd @> (_, _, [e1]) when not letRhs ->
    let tp = e.Type
    let variable = new Var(newVar "snd", tp)
    Expr.Let(variable, MakeCall <@ snd @> [anfConversion false e1] [tp; tp], Expr.Var(variable))

  | ExprShape.ShapeCombination(o, exprs) ->
    ExprShape.RebuildShapeCombination(o, List.map (anfConversion false) exprs)
  | _ -> e

(* Lifts let bindings to top-level statements *)
let letLifting (e: Expr): Expr = 
  let rec constructTopLevelLets (boundVars: Var List) (exp: Expr): Expr * (Var * Expr) List = 
    let isSafeToLift (exp: Expr): bool = 
      let freeVars = getFreeVariables exp
      let freeNotBoundVars = listDiff freeVars boundVars
      List.isEmpty freeNotBoundVars
    match exp with 
    | Patterns.Let(x, e1, e2) ->
      let (te1, liftedLets1) = constructTopLevelLets boundVars e1
      let canBeLifted = isSafeToLift e1
      let newBoundVars = x :: boundVars
      let (te2, liftedLets2) = constructTopLevelLets newBoundVars e2
      if (canBeLifted) then
        (te2, List.append liftedLets1 ((x, te1) :: liftedLets2))
      else 
        (Expr.Let(x, te1, te2), List.append liftedLets1 liftedLets2)
    | Patterns.Call (None, op, elist) -> 
      let (tes, lls) = List.unzip (List.map (constructTopLevelLets boundVars) elist)
      (Expr.Call(op, tes), List.concat lls)
    // | AppN (e0, elist) -> 
    //   let (tes, lls) = List.unzip (List.map (constructTopLevelLets boundVars) elist)
    //   (AppN(e0, tes), List.concat lls)
    | LambdaN (inputs, body) ->
      let (te, ll) = constructTopLevelLets (inputs @ boundVars) body
      //(LambdaN (inputs, te), ll)
      (LambdaN(inputs, LetN(ll, te)), [])
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

let isMonomorphicMacro (op: System.Reflection.MethodInfo) = 
  (not(Seq.isEmpty (op.GetCustomAttributes(typeof<CMonomorphicMacro>, true))))

let isMacro (op: System.Reflection.MethodInfo) = 
  (not(Seq.isEmpty (op.GetCustomAttributes(typeof<CMacro>, true))))

let isLetBoundMacro (op: System.Reflection.MethodInfo) =
  if isMacro op then 
    let cMacro = op.GetCustomAttributes(typeof<CMacro>, true).[0] :?> CMacro
    cMacro.ShouldLetBind()
  else
    false
  

type ClosureContext = { isMacro: bool }
(* Performs closure conversion to make the program closer to C code *)
let closureConversion (e: Expr): Expr = 
  let rec lambdaLift (ctx: ClosureContext) (exp: Expr): Expr =
    let rcr (exp2: Expr) = lambdaLift { isMacro = false } exp2
    match exp with 
    | LambdaN (inputs, body) when not (ctx.isMacro) -> 
      let transformedBody = rcr body
      let freeVars = listDiff (getFreeVariables transformedBody) inputs
      let newVars = List.map (fun (x: Var) -> new Var(newVar(x.Name), x.Type)) freeVars
      let freeNewVars = List.zip freeVars newVars
      let convertedBody = transformedBody.Substitute(fun v -> 
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
    | LambdaN (inputs, body) -> 
      LambdaN (inputs, rcr body)
    | Patterns.Let(x, e1, e2) -> Expr.Let(x, rcr e1, rcr e2)
    | Patterns.Value(v, tp) -> exp
    | Patterns.NewArray(tp, elems) -> 
      Expr.NewArray(tp, List.map (lambdaLift ctx) elems)
    | Patterns.Call (None, op, elist) -> 
      let isCMacro = isMacro op
      let telist = List.map (lambdaLift {isMacro = isCMacro}) elist
      let callExpr = Expr.Call(op, telist)
      //let shouldLetBind = cMacro |> Option.exists(fun x -> x.ShouldLetBind())
      let shouldLetBind = isLetBoundMacro op
      if shouldLetBind then
        let macroVar = new Var(newVar "macroDef", exp.Type)
        Expr.Let(macroVar, callExpr, if(exp.Type = typeof<unit>) then Expr.Value(()) else Expr.Var(macroVar))
      else
        callExpr
    | Patterns.Call (Some x, op, elist) -> Expr.Call(x, op, List.map rcr elist)
    | Patterns.Var (x) -> Expr.Var(x)
    | ExprShape.ShapeCombination(o, exprs) ->
        ExprShape.RebuildShapeCombination(o, List.map rcr exprs)
    | _ -> failwith (sprintf "%A not handled yet!" exp)
  let (inputs, body) = match e with TopLevelFunction (i, b) -> (i, b)
  let te = lambdaLift {isMacro = false} body
  LambdaN(inputs, te)

let rec letCommuting (e: Expr): Expr = 
  match e with
  | Patterns.Let(x, Patterns.Let(y, e1, e2), e3) ->
    letCommuting (Expr.Let(y, e1, Expr.Let(x, e2, e3)))
  | ExprShape.ShapeVar(x) -> Expr.Var(x)
  | ExprShape.ShapeLambda(x, e) -> Expr.Lambda(x, letCommuting e)
  | ExprShape.ShapeCombination(op, args) -> ExprShape.RebuildShapeCombination(op, args |> List.map letCommuting)


(* Performs a full ANF conversion. *)
let fullAnfConversion (e: Expr): Expr = 
  let rec introduceLet (e: Expr) = 
    match e with 
    | ExprShape.ShapeLambda(x, body) -> Expr.Lambda(x, introduceLet body)
    | ExprShape.ShapeVar(x) -> e
    | Patterns.Value(v, tp) -> e
    | ExprShape.ShapeCombination(o, exprs) ->
      let variable = new Var(newVar "_x", e.Type)
      Expr.Let(variable, ExprShape.RebuildShapeCombination(o, exprs |> List.map introduceLet), Expr.Var(variable))
  introduceLet e |> letLifting |> letCommuting

(* Prepares the given program for C code generation *)
let cpreprocess (e: Expr): Expr = 
  e 
  (*|> storagedtransformer.allocLifting*) 
  |> fun x -> variableRenaming x []
  |> closureConversion 
  |> anfConversion false 
  |> letLifting 
  |> letCommuting 
  |> fun x -> variableRenaming x []
