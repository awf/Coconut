module fscodegen

open Microsoft.FSharp.Quotations
open utils
open types
open transformer

let TABS = "  "

let fspreprocess (e: Expr): Expr = 
  e 
  |> ctransformer.letLifting 
  |> ctransformer.letCommuting 
  |> fun x -> variableRenaming x []

let (|FsOperatorName|_|) methodName =
  match methodName with
  | "op_Inequality" -> Some("<>")
  | "Cos"           -> Some("cos")
  | "Sin"           -> Some("sin")
  | "Sqrt"          -> Some("sqrt")
  | "Log"           -> Some("log")
  | "Exp"           -> Some("exp")
  | "ToDouble"      -> Some("(double)")
  | "ToInt"         -> Some("(int)")
  | "cardToInt"     -> Some("cardToInt")
  | "op_DotMinus"   -> Some(".-")
  | "op_DotPlus"    -> Some(".+")
  | OperatorName op -> Some(op)
  | _               -> None

(* Generates the corresponding fsharp expression *)
let rec fscodegenExpr (e:Expr) (tabsNumber: int): string =
  let rec rcr (e1: Expr): string = fscodegenExpr e1 tabsNumber
  let rec rcrInd (e1: Expr): string = fscodegenExpr e1 (tabsNumber + 1)
  let printTabs times = String.replicate times TABS
  let tabs: string = printTabs tabsNumber
  let tabsInd: string = printTabs (tabsNumber + 1)
  match e with
  | LambdaN (inputs, body) -> sprintf "fun %s -> \n%s%s" (String.concat " " (inputs |> List.map (fun x -> x.Name))) tabsInd (rcrInd body)
  | Patterns.Let(x, e1, e2) -> sprintf "let %s = (\n%s%s) in \n%s%s" (x.Name) tabsInd (rcrInd e1) tabs (rcr e2)
  // | LibraryCall(name, argList) -> sprintf "%s(%s)" name (String.concat ", " (List.map fscodegenExpr argList))
  | Patterns.Call (None, op, elist) -> 
    match op.Name with
      | FsOperatorName opname -> 
        if((List.length elist) = 2) then 
          sprintf "((%s) %s (%s))" (rcr elist.[0]) opname (rcr elist.[1]) 
        elif ((List.length elist) = 1) then
          sprintf "%s(%s)" opname (rcr elist.[0])
        else 
          failwithf "OperatorName: %s %s" opname (elist |> List.map (fun e -> sprintf "(%s)" (rcr e)) |> String.concat " ")
      | "GetArray" -> sprintf "%s.[%s]" (rcr elist.[0]) (rcr elist.[1])
      | _ -> 
        sprintf "%s.%s %s" op.DeclaringType.Name op.Name (elist |> List.map (fun e -> sprintf "(%s)" (rcr e)) |> String.concat " ")
  | Patterns.Var(x) -> sprintf "%s" x.Name
  | Patterns.NewArray(tp, elems) -> 
    sprintf "[| (* Array of type %s *) \n%s%s |]" (tp.ToString()) tabsInd (String.concat (sprintf ";\n%s" tabsInd) (List.map rcrInd elems))
  | Patterns.Value(v, tp) when tp = typeof<Unit> -> "()"
  | Patterns.Value(v, tp) when tp = typeof<Cardinality> -> 
    let (Card(card)) = unbox<Cardinality>(v)
    sprintf "(Card %d)" card
  | Patterns.Value(v, tp) when tp = typeof<double> -> sprintf "%f" (unbox<double>(v))
  | Patterns.Value(v, tp) -> v.ToString()
  | Patterns.Sequential(e1, e2) -> sprintf "%s;\n%s%s" (rcr e1) tabs (rcr e2)
  | Patterns.NewUnionCase (uci, args) -> 
     sprintf "%s(%s)" uci.Name (String.concat ", " (List.map rcr args))
  | Patterns.PropertyGet (Some(var), pi, args) -> 
     sprintf "%s.%s" (rcr var) pi.Name
  | AppN(f, args) ->
     sprintf "%s(%s)" (rcr f) (String.concat ", " (List.map rcr args))
  | Patterns.IfThenElse(cond, e1, e2) -> sprintf "if(%s) then \n%s%s\n%selse \n%s%s" (rcr cond) tabsInd (rcrInd e1) tabs tabsInd (rcrInd e2)
  | Patterns.NewTuple(es) -> sprintf "(%s)" (String.concat ", " (List.map rcr es)) 
  | ExprShape.ShapeCombination(op, args) -> 
    failwithf "COMB{%A}(%s)" (op) (String.concat ", " (List.map rcr args))
  | _ -> failwithf "ERROR[%A]" e

let fscodegenTopLevel (e:Expr): string =
  fscodegenExpr (e |> fspreprocess) 0