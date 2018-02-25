module lispcodegen

open Microsoft.FSharp.Quotations
open utils
open types
open transformer
open cardinality

let TABS = "  "

let (|FsOperatorName|_|) methodName =
  match methodName with
  | "op_Inequality" -> Some("<>")
  | "Cos"           -> Some("cos")
  | "Sin"           -> Some("sin")
  | "Sqrt"          -> Some("sqrt")
  | "Log"           -> Some("log")
  | "Exp"           -> Some("exp")
  | "ToDouble"      -> Some("double")
  | "ToInt"         -> Some("int")
  | "cardToInt"     -> Some("cardToInt")
  | "op_DotMinus"   -> Some(".-")
  | "op_DotPlus"    -> Some(".+")
  | OperatorName op -> Some(op)
  | _               -> None

(* Generates the corresponding lisp expression *)
let rec lispcodegenExpr (e:Expr) (tabsNumber: int): string =
  let rec rcr (e1: Expr): string = lispcodegenExpr e1 tabsNumber
  let rec rcrInd (e1: Expr): string = lispcodegenExpr e1 (tabsNumber + 1)
  let printTabs times = String.replicate times TABS
  let tabs: string = printTabs tabsNumber
  let tabsInd: string = printTabs (tabsNumber + 1)
  match e with
  | Patterns.Lambda(i, body) -> sprintf "(lambda %s \n%s%s)" i.Name tabsInd (rcrInd body)
  | Patterns.Let(x, e1, e2) -> sprintf "(apply (lambda %s\n%s%s)\n%s%s)" (x.Name) tabsInd (rcrInd e2) tabs (rcr e1)
  // | LibraryCall(name, argList) -> sprintf "%s(%s)" name (String.concat ", " (List.map fscodegenExpr argList))
  | ArraySlice(e1, e2, e3) ->
      let vec = Expr.Cast<Vector>(e1)
      let s = Expr.Cast<Index>(e2)
      let e = Expr.Cast<Index>(e3)
      rcr (<@ corelang.build<Number> (((Card %e) .- (Card %s)) .+ (Card 1)) (fun i -> (%vec).[i + %s]) @>.Raw)
      //sprintf "(apply (apply (apply linalg_vectorSlice (.- (Card %s) )) %s) %s)" (rcr e3) (rcr e2) (rcr e3)
  | Patterns.Call (None, op, elist) -> 
    match op.Name with
      | FsOperatorName opname -> 
        if((List.length elist) = 2) then 
          sprintf "(%s %s %s)" opname (rcr elist.[0]) (rcr elist.[1]) 
        elif ((List.length elist) = 1) then
          sprintf "(%s %s)" opname (rcr elist.[0])
        else 
          failwithf "OperatorName: %s %s" opname (elist |> List.map (fun e -> sprintf "(%s)" (rcr e)) |> String.concat " ")
      | "GetArray" -> sprintf "(get %s %s)" (rcr elist.[0]) (rcr elist.[1])
      | _ -> 
        if(op.DeclaringType.Name = "corelang") then
          let args = 
            if(op.Name = "foldOnRange") then
              [ elist.[0]; elist.[1]; elist.[3] ]
            else
              elist
          sprintf "(%s %s)" op.Name (args |> List.map (rcr) |> String.concat " ")
        else
          let (md, mt) = (op.DeclaringType.Name, op.Name)
          (sprintf "%s_%s" md mt, elist) ||> List.fold (fun acc cur -> sprintf "(apply %s %s)" acc (rcr cur))
  | Patterns.Var(x) -> sprintf "%s" x.Name
  | Patterns.NewArray(tp, elems) -> 
    sprintf "(array \n%s%s)" tabsInd (String.concat (sprintf "\n%s" tabsInd) (List.map rcrInd elems))
  | Patterns.Value(v, tp) when tp = typeof<Unit> -> "()"
  | Patterns.Value(v, tp) when tp = typeof<Cardinality> -> 
    let (Card(card)) = unbox<Cardinality>(v)
    sprintf "%d" card
  | Patterns.Value(v, tp) when tp = typeof<double> -> sprintf "%f" (unbox<double>(v))
  | Patterns.Value(v, tp) -> v.ToString()
  | Patterns.Sequential(e1, e2) -> sprintf "%s;\n%s%s" (rcr e1) tabs (rcr e2)
  | Patterns.NewUnionCase (uci, args) when uci.Name = "Card" -> 
     sprintf "(%s %s)" uci.Name (String.concat ", " (List.map rcr args))
  | Patterns.PropertyGet (Some(var), pi, args) -> 
     sprintf "%s.%s" (rcr var) pi.Name
  | Patterns.Application(e1, e2) ->
     sprintf "(apply %s %s)" (rcr e1) (rcr e2)
  | Patterns.IfThenElse(cond, e1, e2) -> sprintf "(if %s \n%s%s\n%s \n%s%s)" (rcr cond) tabsInd (rcrInd e1) tabs tabsInd (rcrInd e2)
  | Patterns.NewTuple(es) -> sprintf "(pair %s)" (String.concat " " (List.map rcr es)) 
  | ExprShape.ShapeCombination(op, args) -> 
    failwithf "COMB{%A}(%s)" (op) (String.concat ", " (List.map rcr args))
  | _ -> failwithf "ERROR[%A]" e

let lispcodegenTopLevel (e:Expr): string =
  lispcodegenExpr (e |> fscodegen.fspreprocess) 0