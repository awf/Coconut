module rules_old

open Microsoft.FSharp.Quotations
open corelang
open transformer

let letInliner_old (e: Expr): Expr Option = 
  match e with 
  | Patterns.Let(v, e1, e2) -> 
    let renamedBody = captureAvoidingSubstitution e2 [v, e1]
    Some(renamedBody)
  | _ -> None

// c.f. "Compiling with Continuations, Continued", Andrew Kennedy, ICFP'07
let letCommutingConversion_old = 
  let f = (fun (e: Expr) ->
    match e with 
    | Patterns.Let(v, Patterns.Let(v2, e1, e2), e3) -> 
      [Expr.Let(v2, e1, Expr.Let(v, e2, e3))]
    | _ -> [])
  f, "lcc_old"

let letNormalization_old = 
  let f = (fun (e: Expr) ->
    match e with 
    | Patterns.Let(v, Patterns.Var(x), e1) -> 
      [e1.Substitute(fun v2 -> if v2 = v then Some(Expr.Var(x)) else None)]
    | Patterns.Let(v, (Patterns.Value(_, tp) as vExpr), e1) -> 
      [e1.Substitute(fun v2 -> if v2 = v then Some(vExpr) else None)]
    | Patterns.Let(v, (Patterns.Lambda(_, _) as vExpr), e1) -> 
      [e1.Substitute(fun v2 -> if v2 = v then Some(vExpr) else None)]
    | _ -> [])
  f, "ln_old"

let letReorder_old (e: Expr): Expr Option = 
  match e with 
  | Patterns.Let(v, e1, Patterns.Let(v2, e2, e3)) when not (Seq.exists (fun x -> x = v) (e2.GetFreeVars())) -> 
    Some(Expr.Let(v2, e2, Expr.Let(v, e1, e3)))
  | _ -> None

/// The composition of this rule, let introduction, and letFloatOutwards results in 
/// common-subexpression elimination (CSE).
let letMerging_old (e: Expr): Expr option =
  match e with
  | Patterns.Let(x, e1, Patterns.Let(y, e2, e3)) when e1 = e2 -> 
    Some(Expr.Let(x, e1, e3.Substitute(fun v -> if v = y then Some(Expr.Var(x)) else None)))
  | _ -> None

let letVectorBuildLength_old = 
  (fun e ->
    match e with
    | Patterns.Let (x, (DerivedPatterns.SpecificCall <@ build @> (_, _, [size; f]) as buildExpr), e2) -> 
      let rec findLength(exp: Expr): (Expr * (Expr -> Expr)) option = 
        match exp with
        | ArrayLength(arr) when arr = Expr.Var(x) -> 
          Some(size, fun i -> i)
        | ExprShape.ShapeLambda(input, body) ->
          findLength body
          |> Option.map (fun (l, f) -> l, fun i -> Expr.Lambda(input, f(i)))
        | ExprShape.ShapeVar(v) -> None
        | ExprShape.ShapeCombination(op, args) ->
          let transformedArg = 
            args 
            |> List.mapi (fun idx arg ->
                 findLength(arg)
                 |> Option.map (fun (e, f) -> idx, e, f)
               )
            |> List.tryPick id
          transformedArg 
          |> Option.map (fun (idx, e, f) ->         
               e, (fun i -> 
                    let transformedArgs = 
                      args
                      |> List.mapi (fun idx2 arg ->
                           if(idx2 = idx) then
                             f(i)
                           else
                             arg
                         )
                    ExprShape.RebuildShapeCombination(op, transformedArgs)
                  )
             )
      findLength(e2)
      |> Option.map (fun (te, tf) ->
           Expr.Let (x, buildExpr, tf(te))
         ) |> Option.toList
    | _ -> []), "letBuildLength"

let letVectorBuildGet_old = 
  (fun e ->
    match e with
    | Patterns.Let (x, (DerivedPatterns.SpecificCall <@ build @> (_, _, [size; f]) as buildExpr), e2) -> 
      let rec findGet(exp: Expr): (Expr * (Expr -> Expr)) option = 
        match exp with
        | ArrayGet(arr, idx) when arr = Expr.Var(x) -> 
          Some(Expr.Application(f, idx), fun i -> i)
        | ExprShape.ShapeLambda(input, body) ->
          findGet body
          |> Option.map (fun (l, f) -> l, fun i -> Expr.Lambda(input, f(i)))
        | ExprShape.ShapeVar(v) -> None
        | ExprShape.ShapeCombination(op, args) ->
          let transformedArg = 
            args 
            |> List.mapi (fun idx arg ->
                 findGet arg
                 |> Option.map (fun (e, f) -> idx, e, f)
               )
            |> List.tryPick id
          transformedArg 
          |> Option.map (fun (idx, e, f) ->         
               e, (fun i -> 
                    let transformedArgs = 
                      args
                      |> List.mapi (fun idx2 arg ->
                           if(idx2 = idx) then
                             f(i)
                           else
                             arg
                         )
                    ExprShape.RebuildShapeCombination(op, transformedArgs)
                  )
             )
      findGet e2
      |> Option.map (fun (te, tf) ->
           Expr.Let (x, buildExpr, tf(te))
         ) |> Option.toList
    | _ -> []), "letBuildGet"

let allocToCPS_old (e: Expr): Expr option = 
  match e with
  | Patterns.Let(x, (DerivedPatterns.SpecificCall <@ corelang.vectorAlloc @> (_, _, [s]) as e1), e2) when (e2.Type = typeof<unit>) ->
    let op = assembly.GetType("corelang").GetMethod("vectorAllocCPS").MakeGenericMethod(e2.Type)
    Some(Expr.Call(op, [s; Expr.Lambda(x, e2)]))
  | _ -> None

let dce_old = 
  (fun e ->
    match e with
    | Patterns.Let(x, e1, e2) when not (e2.GetFreeVars() |> Seq.exists (fun x2 -> x2 = x)) ->
      [e2]
    | _ -> []
  ), "dce_old"