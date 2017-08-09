module cost

open Microsoft.FSharp.Quotations
open Quotations.DerivedPatterns
open transformer
open types

let rec exprBinOpDouble (e1: Expr) (e2: Expr) (bop: double -> double -> double): double option = 
  exprToDouble(e1) |> Option.bind (fun e1val -> exprToDouble(e2) |> Option.map (fun e2val -> bop e1val e2val))
and exprToDouble(e: Expr): double option = 
  match e with
  | Patterns.Value(:? double as v, _) -> Some(v)
  | Patterns.Value(:? int as v, tp) -> Some(double v)
  | DerivedPatterns.SpecificCall <@ (-) @> (_, _, [s; e]) -> 
    exprBinOpDouble s e (-)
  | DerivedPatterns.SpecificCall <@ (+) @> (_, _, [s; e]) -> 
    exprBinOpDouble s e (+)
  | DerivedPatterns.SpecificCall <@ (*) @> (_, _, [s; e]) -> 
    exprBinOpDouble s e (*)
  | DerivedPatterns.SpecificCall <@ (/) @> (_, _, [s; e]) -> 
    exprBinOpDouble s e (/)
  | _ -> None

let rangeExprToDouble (s: Expr) (e: Expr): double option = 
  exprBinOpDouble s e (fun sv ev -> ev - sv + 1.0)

let rec estimateCardinality (exp: Expr): double option = 
  match exp with
  | DerivedPatterns.SpecificCall <@ linalg.vectorRange @> (_, _, [s; e]) -> 
    Option.bind (fun e -> Option.bind(fun s -> Some(e - s + 1.0)) (exprToDouble(s))) (exprToDouble(e))
  | DerivedPatterns.SpecificCall <@ corelang.build @> (_, _, [size; f]) -> 
    exprToDouble(size)
  | _ -> 
      //(printfn "**WARNING!** Does not know how to estimate the cardinality for the operator `%A`." exp)
      None

(* A simple cost model based on the number of floating point operations *)
let rec fopCost(exp: Expr): double = 
  let MALLOC_COST = 10000.0
  let FREE_COST = 10.0
  let MALLOC_FREE_COST = MALLOC_COST / 10.0 + FREE_COST
  let VAR_INIT = 0.1
  let VAR_ACCESS = 0.1
  let VALUE_ACCESS = 0.1
  let SCALAR_OPERATOR = 1.0
  let UNKNOWN_CALL = 10000.0
  let METHOD_DEF_OVERHEAD = 10.0
  let LAMBDA_ACCESS = 5.0
  let CALL_COST = 5.0
  let LENGTH_ACCESS = SCALAR_OPERATOR
  let ARRAY_ACCESS = 3.0
  let ARRAY_SLICE = 30.0
  let ARRAY_DEFAULT_SIZE = 1000.0
  let BUILD_PER_ELEM_COST = CALL_COST + ARRAY_ACCESS
  let NUMBER_PRINT_COST = UNKNOWN_CALL
  let buildCost (size: Expr, f: Expr): double = 
    // (Option.fold (fun _ x -> x) ARRAY_DEFAULT_SIZE (exprToDouble size)) * fopCost(f)
    let card = (Option.fold (fun _ x -> x) ARRAY_DEFAULT_SIZE (exprToDouble size))
    fopCost(f) + fopCost(size) + card * BUILD_PER_ELEM_COST
  match exp with 
  | DerivedPatterns.SpecificCall <@ corelang.foldOnRange @> (_, _, [f; z; s; e]) -> 
    fopCost(z) + fopCost(s) + fopCost(e) + fopCost(f) * (rangeExprToDouble s e |> Option.fold (fun _ s -> s) ARRAY_DEFAULT_SIZE)
  | ExistingCompiledMethodWithLambda(_, _, args, f) ->
    CALL_COST + METHOD_DEF_OVERHEAD + fopCost(f) + List.sum (List.map fopCost args)
  | DerivedPatterns.SpecificCall <@ corelang.build @> (_, _, [size; f]) -> 
    MALLOC_COST + buildCost(size, f)
  | DerivedPatterns.SpecificCall <@ corelang.vectorBuildGivenStorage @> (_, _, [s; f]) -> 
    fopCost(f)
  | DerivedPatterns.SpecificCall <@ corelang.vectorAlloc @> (_, _, [size]) -> 
    MALLOC_COST + fopCost(size)
  | DerivedPatterns.SpecificCall <@ corelang.alloc @> (_, _, [size; cont]) -> 
    MALLOC_FREE_COST + fopCost(size) + fopCost(cont)
  | DerivedPatterns.SpecificCall <@ corelang.numberPrint @> (_, _, args) -> 
    List.sum (List.map fopCost args) + NUMBER_PRINT_COST
  | DerivedPatterns.SpecificCall <@ corelang.vectorPrint @> (_, _, args) -> 
    List.sum (List.map fopCost args) + NUMBER_PRINT_COST
  | DerivedPatterns.SpecificCall <@ corelang.length @> (_, _, args) -> 
    List.sum (List.map fopCost args) + LENGTH_ACCESS
  | DerivedPatterns.SpecificCall <@ cardinality.cardToInt @> (_, _, args) -> 
    List.sum (List.map fopCost args)
  | CardConstructor c ->
    fopCost c
  | ArraySlice(arr, s, e) ->
    let estimatedCardinality = rangeExprToDouble s e
    ARRAY_SLICE + MALLOC_COST + fopCost(arr) + fopCost(s) + fopCost(e) + ARRAY_ACCESS * (estimatedCardinality |> Option.fold (fun _ s -> s) ARRAY_DEFAULT_SIZE)
  | Patterns.Call (None, op, elist) ->
    let argsCost =  List.sum (List.map fopCost elist)
    if elist |> List.forall (fun a -> a.Type = typeof<Index> || a.Type = typeof<Number>) then
      // Is a scalar operator
      argsCost + SCALAR_OPERATOR
    else 
      match op.Name with
      | OperatorName opname -> argsCost + SCALAR_OPERATOR
      | "GetArray" -> ARRAY_ACCESS + argsCost
      | name -> 
        printfn "**WARNING!** Does not know how to cost the operator `%s`. Assumes %f to make progress." name UNKNOWN_CALL
        argsCost + UNKNOWN_CALL
  | Patterns.NewArray(_, args) ->
    MALLOC_COST + List.sum (List.map fopCost args)
  | Patterns.Value(_) -> VALUE_ACCESS
  | Patterns.Let(x, e1, e2) -> fopCost(e1) + fopCost(e2) + VAR_INIT
  | Patterns.Var(_) -> VAR_ACCESS
  | LambdaN(xs, e) -> VAR_INIT * float (List.length xs) + LAMBDA_ACCESS + fopCost(e)
  | AppN(f, args) -> CALL_COST + fopCost(f) + List.sum (List.map fopCost args)
  | Patterns.PropertyGet(Some(e), op, []) when op.Name = "Length" -> fopCost(e) + LENGTH_ACCESS
  | Patterns.Sequential(e1, e2) -> fopCost(e1) + fopCost(e2)
  | Patterns.IfThenElse(cond, e1, e2) ->
    fopCost(cond) + (max (fopCost e1) (fopCost e2))
  | _ -> failwith (sprintf "Does not know how to cost the construct `%A`" exp)
