module optimizer

open Microsoft.FSharp.Quotations
open utils
open types
open transformer

let optimize (e: Expr): Expr = 
  let rec inliner (exp: Expr): Expr = 
    match exp with 
    | ExistingCompiledMethod (methodName, moduleName, argList) ->
      let methodInfo = assembly.GetType(moduleName).GetMethod(methodName)
      let reflDefnOpt = Microsoft.FSharp.Quotations.Expr.TryGetReflectedDefinition(methodInfo)
      let isInlined = Seq.isEmpty (methodInfo.GetCustomAttributes(typeof<DontInline>, true))
      let attrs = (methodInfo.GetMethodImplementationFlags())
      match reflDefnOpt with
      | None -> failwith (sprintf "fatal error! Inlining non-inlinable method: %s.%s!" moduleName methodName)
      | Some(LambdaN(inputs, body)) when isInlined -> 
        let paramVar (p: System.Reflection.ParameterInfo) = 
          (Expr.Var(new Var(p.Name, p.ParameterType)), new Var(newVar p.Name, p.ParameterType))
        (*let paramList = List.zip argList (List.map paramVar (List.ofSeq (methodInfo.GetParameters())))*)
        let paramList = List.zip (List.map inliner argList) (List.map (fun x -> Expr.Var(x), "") inputs)
        printfn "%s: name: %A" methodName (List.zip argList paramList)
        let inlinedBody = body.Substitute(fun v -> Option.map (fun (e1, (e2, v1)) -> e1) (List.tryFind (fun (e1, (e2, v1)) -> e2 = Expr.Var(v)) paramList))
        match inlinedBody with 
        | LetN(inputs, letBoundBody) -> 
          let newInputs = List.map (fun (v: Var, e: Expr) -> (v, e), new Var(newVar (v.Name), v.Type)) inputs
          LetN(List.map (fun ((_, e), v2) -> (v2, e)) newInputs, 
            letBoundBody.Substitute(fun v -> Option.map (fun ((v1, e), v2) -> Expr.Var(v2)) (List.tryFind (fun ((v1, _), _) -> v = v1) newInputs)))
        | _ -> inlinedBody
        
      | _ -> exp
    | ExprShape.ShapeLambda(i, e) -> Expr.Lambda(i, inliner e)
    | ExprShape.ShapeVar(v) -> Expr.Var(v)
    | ExprShape.ShapeCombination(o, exprs) ->
        ExprShape.RebuildShapeCombination(o, List.map inliner exprs)
  (* inliner(e) *)
  e