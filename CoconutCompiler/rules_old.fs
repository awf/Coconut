module rules_old

open Microsoft.FSharp.Quotations
open corelang
open transformer

let letInlinerOnce_old = 
  (fun (e: Expr) ->
    match e with 
    | Patterns.Let(v, e1, e2) -> 
      let rec count exp: int = 
        match exp with 
        | ExprShape.ShapeCombination(op, args) -> args |> List.map count |> List.fold (+) 0
        | ExprShape.ShapeVar(v2) -> if v2 = v then 1 else 0
        | ExprShape.ShapeLambda(x, body) -> count body
      if (count e2) = 1 then 
        let renamedBody = captureAvoidingSubstitution e2 [v, e1]
        [renamedBody]
      else
        []
    | _ -> []
  ), "letInlinerOnce_old"

let letInliner_old = 
  (fun (e: Expr) ->
    match e with 
    | Patterns.Let(v, e1, e2) -> 
      let renamedBody = captureAvoidingSubstitution e2 [v, e1]
      [renamedBody]
    | _ -> []
  ), "letInliner_old"

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
    | Patterns.Let(v, ((Patterns.Value(_, _) | CardConstructor(_)) as vExpr), e1) -> 
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

let letExtractAnyRule ((|PatRhs|_|): Expr -> Expr option) 
   ((|PatInside|_|): Expr -> (Expr list) option) (factoryInside: Expr list -> Expr) (e: Expr): Expr list = 
  match e with
  | Patterns.Let (x, (PatRhs(insideExpr) as rhsExpr), e2) -> 
    let rec findInsideTerm(exp: Expr): (Expr * (Expr -> Expr)) option = 
      match exp with
      | PatInside(args) when (args |> List.head) = Expr.Var(x) -> 
        Some(factoryInside (insideExpr :: (args |> List.tail)), fun i -> i)
      | ExprShape.ShapeLambda(input, body) ->
        findInsideTerm body
        |> Option.map (fun (l, f) -> l, fun i -> Expr.Lambda(input, f(i)))
      | ExprShape.ShapeVar(v) -> None
      | ExprShape.ShapeCombination(op, args) ->
        let transformedArg = 
          args 
          |> List.mapi (fun idx arg ->
               findInsideTerm arg
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
    findInsideTerm e2
    |> Option.map (fun (te, tf) ->
         Expr.Let (x, rhsExpr, tf te)
       ) |> Option.toList
  | _ -> []

let letVectorBuildLength_old = 
  (fun (e: Expr) ->
    letExtractAnyRule (fun exp -> 
        DerivedPatterns.(|SpecificCall|_|) <@ build @> exp
          |> Option.map (fun (_, _, args) -> args |> List.head)
      ) (
        (|ArrayLength|_|) >> Option.map (fun arr -> [arr])
      ) (fun args -> args |> List.head) e
  ), "letBuildLength"

let letVectorBuildGet_old = 
  (fun e ->
    letExtractAnyRule (fun exp -> 
        DerivedPatterns.(|SpecificCall|_|) <@ build @> exp
          |> Option.map (fun (_, _, [_; f]) -> f)
      ) ((|ArrayGet|_|) >> Option.map (fun (a, b) -> [a; b]))
        (fun [f; idx] -> Expr.Application(f, idx)) e
  ), "letBuildGet"

let letCSE = 
  (fun e ->
    match e with 
    | Patterns.Let(x, e1, e2) ->
      let rec findInsideTerm(exp: Expr): (Expr) option = 
        match exp with 
        | Patterns.Let(y, e3, e4) when alphaEquals e1 e3 Map.empty -> 
          Some(e4.Substitute(fun z -> if z = y then Some(Expr.Var(x)) else None))
        | exp when alphaEquals e1 exp Map.empty -> 
          Some(Expr.Var(x))
        | ExprShape.ShapeLambda(input, body) ->
          findInsideTerm body
          |> Option.map (fun b -> Expr.Lambda(input, b))
        | ExprShape.ShapeVar(v) -> None
        | ExprShape.ShapeCombination(op, args) ->
          let transformedArg = 
            args 
            |> List.mapi (fun idx arg ->
                 findInsideTerm arg
                 |> Option.map (fun e -> idx, e)
               )
            |> List.tryPick id
          transformedArg 
          |> Option.map (fun (idx, e) ->         
                    let transformedArgs = 
                      args
                      |> List.mapi (fun idx2 arg ->
                           if(idx2 = idx) then
                             e
                           else
                             arg
                         )
                    ExprShape.RebuildShapeCombination(op, transformedArgs)
                  )
      findInsideTerm e2 |> Option.map (fun e2' -> Expr.Let(x, e1, e2')) |> Option.toList
    | _ -> []
  ), "letCSE"

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