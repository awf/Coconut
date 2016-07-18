﻿module optimizer

open Microsoft.FSharp.Quotations
open utils
open types
open transformer

module rules = 
  open Quotations.DerivedPatterns
  type Rule = Expr -> Expr Option

  let (|ApplicableRule|_|) (rs: Rule List) (e: Expr): (Rule) Option = 
    List.tryFind (fun r -> not(Option.isNone(r e))) rs

  let letInliner (e: Expr): Expr Option = 
    match e with 
    | Patterns.Let(v, e1, e2) -> Some(e2.Substitute(fun v2 -> if v = v2 then Some(e1) else None))
    | _ -> None
  
  let divide2Mult (e: Expr): Expr Option = 
     match e with 
     | SpecificCall  <@ (/) @> (None, _, [SpecificCall  <@ (/) @> (None, _, [a; b]) ; c]) -> 
       Some(<@@ (%%a: Number) / ((%%b: Number) * (%%c: Number)) @@>)
     | _ -> None

  let distrMult (e: Expr): Expr Option = 
     match e with 
     | SpecificCall  <@ (*) @> (None, _, [a; SpecificCall  <@ (+) @> (None, _, [b; c])]) -> 
       Some(<@@ ((%%a: Number) * (%%b: Number)) + ((%%a: Number) * (%%c: Number)) @@>)
     | _ -> None

  let constFold1 (e: Expr): Expr Option = 
     match e with 
     | SpecificCall  <@ (*) @> (None, _, [a; b]) when b = <@@ 1. @@> -> 
       Some(a)
     | _ -> None

  let multDivide (e: Expr): Expr Option = 
     match e with 
     | SpecificCall  <@ (*) @> (None, _, [a; SpecificCall  <@ (/) @> (None, _, [b; c])]) when c = a && b = <@@ 1. @@> -> 
       Some(<@@ 1. @@>)
     | _ -> None

let recursiveTransformer (e: Expr) (rs: rules.Rule List): Expr = 
  let rec rcr(exp: Expr): Expr = 
    match exp with 
    | rules.ApplicableRule rs rule -> rcr(Option.get (rule(exp)))
    | ExprShape.ShapeLambda(i, e) -> Expr.Lambda(i, rcr e)
    | ExprShape.ShapeVar(v) -> Expr.Var(v)
    | ExprShape.ShapeCombination(o, exprs) ->
        ExprShape.RebuildShapeCombination(o, List.map rcr exprs)
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
  recursiveTransformer e [rules.letInliner; rules.divide2Mult; rules.distrMult; rules.constFold1; rules.multDivide]