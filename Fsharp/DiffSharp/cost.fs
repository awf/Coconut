module cost

open Microsoft.FSharp.Quotations
open Quotations.DerivedPatterns
open transformer

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
      (printfn "**WARNING!** Does not know how to estimate the cardinality for the operator `%A`." exp); None

(* A simple cost model based on the number of floating point operations *)
let rec fopCost(exp: Expr): double = 
  let VAR_INIT = 0.1
  let VAR_ACCESS = 0.1
  let VALUE_ACCESS = 0.1
  let SCALAR_OPERATOR = 1.0
  let UNKNOWN_CALL = 1000.0
  let CALL_COST = 5.0
  let LENGTH_ACCESS = SCALAR_OPERATOR
  let ARRAY_ACCESS = 3.0
  let ARRAY_SLICE = 30.0 // TODO very approximate
  let ARRAY_DEFAULT_SIZE = 1000.0
  let NUMBER_PRINT_COST = UNKNOWN_CALL
  let buildCost (size: Expr, f: Expr): double = 
    (Option.fold (fun _ x -> x) ARRAY_DEFAULT_SIZE (exprToDouble size)) * fopCost(f)
  match exp with 
  | ExistingCompiledMethodWithLambda(_, _, args, f) ->
    CALL_COST + fopCost(f) + List.sum (List.map fopCost args)
  | DerivedPatterns.SpecificCall <@ corelang.vectorBuild @> (_, _, [size; f]) -> 
    buildCost(size, f)
  | DerivedPatterns.SpecificCall <@ corelang.matrixBuild @> (_, _, [size; f]) -> 
    buildCost(size, f)
  | DerivedPatterns.SpecificCall <@ corelang.vectorFoldNumber @> (_, _, [f; z; range]) -> 
    fopCost(z) + fopCost(range) + fopCost(f) * (Option.fold (fun _ s -> s) ARRAY_DEFAULT_SIZE (cardinality(range)))
  | DerivedPatterns.SpecificCall <@ corelang.numberPrint @> (_, _, args) -> 
    List.sum (List.map fopCost args) + NUMBER_PRINT_COST
  | Patterns.Call (None, op, elist) -> 
    match op.Name with
    | OperatorName opname -> List.sum (List.map fopCost elist) + SCALAR_OPERATOR
    | "GetArray" -> ARRAY_ACCESS
    | "GetArraySlice" -> ARRAY_ACCESS
    | name -> 
      printfn "**WARNING!** Does not know how to cost the operator `%s`. Assumes %f to make progress." name UNKNOWN_CALL
      List.sum (List.map fopCost elist) + UNKNOWN_CALL
  | Patterns.Value(_) -> VALUE_ACCESS
  | Patterns.Let(x, e1, e2) -> fopCost(e1) + fopCost(e2) + VAR_INIT
  | Patterns.Var(_) -> VAR_ACCESS
  | LambdaN(xs, e) -> VAR_INIT * float (List.length xs) + fopCost(e)
  | AppN(f, args) -> CALL_COST + fopCost(f) + List.sum (List.map fopCost args)
  | Patterns.PropertyGet(Some(e), op, []) when op.Name = "Length" -> fopCost(e) + LENGTH_ACCESS
  | Patterns.Sequential(e1, e2) -> fopCost(e1) + fopCost(e2)
  | _ -> failwith (sprintf "Does not know how to cost the construct `%A`" exp)
