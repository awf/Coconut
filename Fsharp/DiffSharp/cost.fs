module cost

open Microsoft.FSharp.Quotations
open Quotations.DerivedPatterns
open transformer
open types

let exprToDouble(e: Expr): double option = 
  match e with
  | Patterns.Value(:? double as v, _) -> Some(v)
  | Patterns.Value(:? int as v, tp) -> Some(double v)
  | _ -> None

let rec cardinality (exp: Expr): double option = 
  match exp with
  | DerivedPatterns.SpecificCall <@ linalg.vectorRange @> (_, _, [s; e]) -> 
    Option.bind (fun e -> Option.bind(fun s -> Some(e - s + 1.0)) (exprToDouble(s))) (exprToDouble(e))
  | DerivedPatterns.SpecificCall <@ corelang.vectorBuild @> (_, _, [size; f]) -> 
    exprToDouble(size)
  | DerivedPatterns.SpecificCall <@ corelang.matrixBuild @> (_, _, [size; f]) -> 
    exprToDouble(size)
  | _ -> 
      (printfn "**WARNING!** Does not know how to estimate the cardinality for the operator `%A`." exp)
      None

(* A simple cost model based on the number of floating point operations *)
let rec fopCost(exp: Expr): double = 
  let MALLOC_COST = 1000.0
  let FREE_COST = 10.0
  let VAR_INIT = 0.1
  let VAR_ACCESS = 0.1
  let VALUE_ACCESS = 0.1
  let SCALAR_OPERATOR = 1.0
  let UNKNOWN_CALL = 10000.0
  let CALL_COST = 5.0
  let LENGTH_ACCESS = SCALAR_OPERATOR
  let ARRAY_ACCESS = 3.0
  let ARRAY_SLICE = 30.0
  let ARRAY_DEFAULT_SIZE = 1000.0
  let NUMBER_PRINT_COST = UNKNOWN_CALL
  let buildCost (size: Expr, f: Expr): double = 
    (Option.fold (fun _ x -> x) ARRAY_DEFAULT_SIZE (exprToDouble size)) * fopCost(f)
  match exp with 
  | ExistingCompiledMethodWithLambda(_, _, args, f) ->
    CALL_COST + fopCost(f) + List.sum (List.map fopCost args)
  | DerivedPatterns.SpecificCall <@ corelang.vectorBuild @> (_, _, [size; f]) -> 
    MALLOC_COST + buildCost(size, f)
  | DerivedPatterns.SpecificCall <@ corelang.vectorBuildGivenStorage @> (_, _, [s; f]) -> 
    fopCost(f)
  | DerivedPatterns.SpecificCall <@ corelang.vectorAllocCPS @> (_, _, [size; cont]) -> 
    MALLOC_COST + fopCost(size) + fopCost(cont) + FREE_COST
  | DerivedPatterns.SpecificCall <@ corelang.matrixBuild @> (_, _, [size; f]) -> 
    MALLOC_COST + buildCost(size, f)
  | DerivedPatterns.SpecificCall <@ corelang.vectorFoldNumber @> (_, _, [f; z; range]) -> 
    fopCost(z) + fopCost(range) + fopCost(f) * (Option.fold (fun _ s -> s) ARRAY_DEFAULT_SIZE (cardinality(range)))
  | DerivedPatterns.SpecificCall <@ corelang.numberPrint @> (_, _, args) -> 
    List.sum (List.map fopCost args) + NUMBER_PRINT_COST
  | ArraySlice(arr, s, e) ->
    let estimatedCardinality = cardinality(s) |> Option.bind (fun scard -> cardinality(e) |> Option.map (fun ecard -> ecard - scard + 1.0))
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
  | LambdaN(xs, e) -> VAR_INIT * float (List.length xs) + fopCost(e)
  | AppN(f, args) -> CALL_COST + fopCost(f) + List.sum (List.map fopCost args)
  | Patterns.PropertyGet(Some(e), op, []) when op.Name = "Length" -> fopCost(e) + LENGTH_ACCESS
  | Patterns.Sequential(e1, e2) -> fopCost(e1) + fopCost(e2)
  | Patterns.IfThenElse(cond, e1, e2) ->
    fopCost(cond) + (max (fopCost e1) (fopCost e2))
  | _ -> failwith (sprintf "Does not know how to cost the construct `%A`" exp)
