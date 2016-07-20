module optimizer

open Microsoft.FSharp.Quotations
open utils
open types
open transformer
open ruleengine
open rules
open cost
open search

let recursiveTransformer (e: Expr) (rs: Rule List): Expr = 
  let rec rcr(exp: Expr): Expr = 
    match exp with 
    | ApplicableRule rs rule -> rcr(Option.get (rule(exp)))
    | ExprShape.ShapeLambda(i, e) -> Expr.Lambda(i, rcr e)
    | ExprShape.ShapeVar(v) -> Expr.Var(v)
    | ExprShape.ShapeCombination(o, exprs) ->
        ExprShape.RebuildShapeCombination(o, List.map rcr exprs)
  rcr(e)

let examineAllRules (rs: Rule List) (e: Expr): Expr List = 
  let rec rcr(exp: Expr): Expr List = 
    let immediatelyConstructedExpressions = List.collect (fun r -> Option.toList (r exp)) rs
    let constructedExpressionsByChildren =
      match exp with 
      | ExprShape.ShapeLambda(i, e) -> List.map (fun x -> Expr.Lambda(i, x)) (rcr e)
      | ExprShape.ShapeVar(v) -> []
      | Patterns.Value(v, tp) -> []
      | ExprShape.ShapeCombination(o, exprs) ->
          let exprsExpressions = List.map (fun e -> rcr e) exprs
          let allChildrenExpressions = 
            List.concat (List.mapi (fun index ec -> 
                  let (pre, post) = List.partition (fun (i, x) -> i < index) (List.mapi (fun i x -> i, x) exprs)
                  List.map (fun cur -> List.append (List.map snd pre) (cur :: (List.tail (List.map snd post))))  ec
            ) exprsExpressions)
          List.map (fun es -> ExprShape.RebuildShapeCombination(o, es)) (allChildrenExpressions)
    List.append immediatelyConstructedExpressions constructedExpressionsByChildren
  rcr(e)

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
      let inlinedBody = 
        body.Substitute (fun v -> 
          Option.map (fun (e1, _) -> e1) 
            (List.tryFind (fun (_, (e2, _)) -> e2 = Expr.Var(v)) paramList))
      match inlinedBody with 
      | LetN(inputs, letBoundBody) -> 
        let newInputs = List.map (fun (v: Var, e: Expr) -> (v, e), new Var(newVar (v.Name), v.Type)) inputs
        LetN(List.map (fun ((_, e), v2) -> (v2, e)) newInputs, 
          letBoundBody.Substitute (fun v -> 
            Option.map (fun (_, v2) -> Expr.Var(v2))
              (List.tryFind (fun ((v1, _), _) -> v = v1) newInputs)))
      | _ -> inlinedBody
      
    | _ -> exp
  | ExprShape.ShapeLambda(i, e) -> Expr.Lambda(i, inliner e)
  | ExprShape.ShapeVar(v) -> Expr.Var(v)
  | ExprShape.ShapeCombination(o, exprs) ->
      ExprShape.RebuildShapeCombination(o, List.map inliner exprs)

let optimize (e: Expr): Expr = 
  (* inliner(e) *)
  let debug = true
  let rs = letInliner :: algebraicRulesScalar
  (*recursiveTransformer e rs*)
  let (best, _) = bfs e 7 (examineAllRules rs) fopCost debug (ccodegen.prettyprint)
  (*let (best, _) = randomWalk e 7 (examineAllRules rs) fopCost debug (ccodegen.prettyprint)*)
  
  best
