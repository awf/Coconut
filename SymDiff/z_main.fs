open Microsoft.FSharp.Quotations 
open Microsoft.FSharp.Quotations.Patterns
open System.Text.RegularExpressions
                
open NUnit.Framework
open Swensen.Unquote

let floatstr (v:float) = let s = sprintf "%g" v in if s.Contains(".") then s else (s + ".")

type Tree =
 | LeafS of string
 | LeafV of float
 | Node of Tree[]
 | Hole // We could write the zipper less intrusively, e.g. using an Empty node, but this program is doing a particular thing
        // and we shouldn't be afraid to do that thing, nor should we design for generality we won't use
 override x.ToString() = match x with
                         | LeafS(s) -> if Regex.IsMatch(s, "^[a-zA-Z0-9._+*/-]+$") then s else "\"" + s + "\""
                         | LeafV(v) -> floatstr v
                         | Node(ts) -> "("  + (Array.fold (fun s t -> s + " " + t.ToString()) ""  ts) + ")"
                         | Hole ->  "<_>"

// (+ 1 (* 2 3))                         
let t1 = Node [| LeafS "+"; LeafV 1.0; Node [|LeafS "*"; LeafV 2.0; LeafV 3.0|] |]

printf "TREE[%s]\n" (t1.ToString())
 
let rec totree (expr:Expr) =
        match expr with
        | Value(v,typ) when (v :? string) -> LeafS (unbox<string> v)
        | Value(v,typ) when (v :? float) -> LeafV (unbox<float> v)
        | Var(var) -> LeafS var.Name
        | Application(expr1, expr2) -> Node [|LeafS "Apply"; totree expr1; totree expr2|]
        | Call(exprOpt, methodInfo, exprList) ->
            // Method or module function call.
            let name = match exprOpt with
                            | Some sexpr -> methodInfo.Name
                            | None -> methodInfo.DeclaringType.Name + "." + methodInfo.Name

            let firstarg = match exprOpt with
                            | Some sexpr -> [totree sexpr]
                            | None -> []
            Node (Seq.toArray (List.append [LeafS "call"; LeafS name] (List.append firstarg (List.map totree exprList))))
        | Lambda(param, body) -> Node [|LeafS "lambda"; LeafS param.Name; totree body|]
        | Let(var, expr1, expr2) -> Node [|LeafS "let"; LeafS var.Name; totree expr1; totree expr2|]
        | PropertyGet(Some expr1, propOrValInfo, _) -> Node [|LeafS "property-get"; LeafS propOrValInfo.Name; totree expr1|] 
        | _ -> Node [| LeafS (sprintf "**\n**MATCHFAIL[%s]**" (expr.ToString())) |]
              
let q1 = <@ fun x -> sin (1.0 + 2.0 * x) + float "fred".Length @>;;
let q = <@ fun (x:float) (y:float) -> let v = 3.0 in sin (1.0 + 2.0 * v / y) @>;;

printf "Q %s\n" (q.ToString())

printf "-> %s\n" ((totree q).ToString())

printf "Q1 %s\n" (q1.ToString())

printf "-> %s\n" ((totree q1).ToString())

let replace_nth (a:'T[]) (n:int) (v:'T) = let a' = Array.copy a in 
                                          let _ = Array.set a' n v in
                                          a'

[<Test>]
let test_replace_nth () =
    test <@ replace_nth [|1; 2; 3|] 0 11 = [|11;  2;  3|] @>
    test <@ replace_nth [|1; 2; 3|] 1 11 = [| 1; 11;  3|] @>
    test <@ replace_nth [|1; 2; 3|] 2 11 = [| 1;  2; 11|] @>


// Define the tree zipper
type TreeZipper(focus:Tree, context:List<Tree * int>) = 
    new(t:Tree) = TreeZipper(t, [])
    member this.Focus = focus
    member this.Context = context
    member this.Child(n:int) = 
            match focus with 
            | Node ts -> TreeZipper(ts.[n], (Node (replace_nth ts n Hole), n) :: context)
            | _ -> failwith "Child on a leaf"
    member this.Parent = 
            match context with 
            | (Node ts, n) :: grandparents -> TreeZipper(Node (replace_nth ts n focus), grandparents)
            | _ -> failwith "Parent on the root, or parent isn't a Node"
    override this.ToString() = sprintf "ZIPPER[%s%s]" (focus.ToString()) (context |> List.fold (fun s (t,n) -> s + " WITHIN " + t.ToString()) "")
    override this.GetHashCode() = hash (this.Focus, this.Context)
    override this.Equals(yobj) =
            match yobj with
            | :? TreeZipper as y  -> focus = y.Focus && context = y.Context
            | _ -> false

             

let z = TreeZipper(t1)
let z1 = TreeZipper(totree q1)

printf "\n\ntree: %A\n" z    
printf "\n D2: %A\n" (z.Child(2))
printf "\n D1: %A\n" (z.Child(2).Child(1))
printf "\n UP: %A\n" (z.Child(2).Child(1).Parent)
printf "\n UP: %A\n" (z.Child(2).Child(1).Parent.Parent)
printf "\n D1: %A\n" (z.Child(1))
printf "\n UP: %A\n" (z.Child(2).Child(1).Parent.Parent)
printf "  z: %A\n" z
printf "child.par.par = z: %A\n" (z.Child(2).Child(1).Parent.Parent = z)

[<Test>]
let test_zipper () =
    let z = TreeZipper(totree q1)
    let z1 = TreeZipper(t1)
    test <@ replace_nth [|1; 2; 3|] 0 11 = [|11;  2;  3|] @>
    test <@ z1.Child(2).Parent = z1 @>
    test <@ z.Child(2).Child(1).Parent.Parent = z @>

let rules = 
    let x = 0.0 in
    [
    <@  x + 0. = x @>    
    ] |> List.map totree

let expr = totree <@ let a = 1.0 in (1./a) /(1./a + 1.) @>

[<EntryPoint>]
let main args =
    printfn "Run tests"
    0
