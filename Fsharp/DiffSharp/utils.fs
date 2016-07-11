module utils

open types

let arrayPrint (v: Vector): Unit = 
  printfn "(%s)" (String.concat ", " (Array.map (sprintf "%f") v))

let numberPrint (v: Number): Unit = 
  printfn "%f" v

let arrayRange (s: Index) (e: Index): Vector = 
  [|for i = s to e do yield (double i)|]

let arrayMapToMatrix (f: Number -> Vector) (arr: Vector): Matrix = 
  Array.map f arr

let listDiff list1 list2 = 
  List.filter (fun x -> not (List.exists (fun y -> x = y) list2)) list1