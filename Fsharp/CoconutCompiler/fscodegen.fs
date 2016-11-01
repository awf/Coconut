module fscodegen

open Microsoft.FSharp.Quotations
open utils
open types
open transformer

(* Generates the corresponding fsharp expression *)
let rec fscodegenExpr (e:Expr): string =
  match e with
  | LambdaN (inputs, body) -> sprintf "fun %s -> %s" (String.concat " " (inputs |> List.map (fun x -> x.Name))) (fscodegenExpr body)
  | Patterns.Let(x, e1, e2) -> sprintf "let %s = %s in \n%s" (x.Name) (fscodegenExpr e1) (fscodegenExpr e2)
  | LibraryCall(name, argList) -> sprintf "%s(%s)" name (String.concat ", " (List.map fscodegenExpr argList))
  | Patterns.Call (None, op, elist) -> 
    match op.Name with
      | OperatorName opname -> 
        if((List.length elist) = 2) then 
          sprintf "(%s %s %s)" (fscodegenExpr elist.[0]) opname (fscodegenExpr elist.[1]) 
        elif ((List.length elist) = 1) then
          sprintf "%s(%s)" opname (fscodegenExpr elist.[0])
        else 
          sprintf "%s(%s)" opname (String.concat ", " (List.map fscodegenExpr elist))
      | "GetArray" -> sprintf "%s.[%s]" (fscodegenExpr elist.[0]) (fscodegenExpr elist.[1])
      | _ -> 
        let argsStr = (String.concat ", " (List.map fscodegenExpr elist))
        sprintf "%s(%s)" op.Name argsStr
  | Patterns.Var(x) -> sprintf "%s" x.Name
  | Patterns.NewArray(tp, elems) -> 
    sprintf "Array[%s](%s)" (tp.ToString()) (String.concat ", " (List.map fscodegenExpr elems))
  | Patterns.Value(v, tp) when tp = typeof<Unit> -> "()"
  | Patterns.Value(v, tp) when tp = typeof<Cardinality> -> 
    let (Card(card)) = unbox<Cardinality>(v)
    sprintf "%d" card
  | Patterns.Value(v, tp) -> v.ToString()
  | Patterns.Sequential(e1, e2) -> sprintf "%s;\n%s" (fscodegenExpr e1) (fscodegenExpr e2)
  | Patterns.NewUnionCase (uci, args) -> 
     sprintf "%s(%s)" uci.Name (String.concat ", " (List.map fscodegenExpr args))
  | Patterns.PropertyGet (Some(var), pi, args) -> 
     sprintf "%s.%s" (fscodegenExpr var) pi.Name
  | AppN(f, args) ->
     sprintf "%s(%s)" (fscodegenExpr f) (String.concat ", " (List.map fscodegenExpr args))
  | Patterns.IfThenElse(cond, e1, e2) -> sprintf "if(%s) then %s else %s" (fscodegenExpr cond) (fscodegenExpr e1) (fscodegenExpr e2)
  | ExprShape.ShapeCombination(op, args) -> 
    failwithf "COMB{%A}(%s)" (op) (String.concat ", " (List.map fscodegenExpr args))
  | _ -> failwithf "ERROR[%A]" e
