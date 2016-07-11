module utils

open types
open System

[<CMirror("array_print")>]
let arrayPrint (v: Vector): Unit = 
  printfn "(%s)" (String.concat ", " (Array.map (sprintf "%f") v))

[<CMirror("number_print")>]
let numberPrint (v: Number): Unit = 
  printfn "%f" v

[<CMirror("array_range")>]
let arrayRange (s: Index) (e: Index): Vector = 
  [|for i = s to e do yield (double i)|]

[<CMirror("array_map_to_matrix")>]
let arrayMapToMatrix (f: Number -> Vector) (arr: Vector): Matrix = 
  Array.map f arr

[<CMirror("list_diff")>]
let listDiff list1 list2 = 
  List.filter (fun x -> not (List.exists (fun y -> x = y) list2)) list1