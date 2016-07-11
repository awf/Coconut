module utils

open types
open System

open System.IO

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

let listDiff list1 list2 = 
  List.filter (fun x -> not (List.exists (fun y -> x = y) list2)) list1

[<CMirror("matrix_read")>]
let matrixRead (fn: string) (startLine: Index) (rows: Index): Matrix = 
  let string_lines = Array.ofSeq (File.ReadLines(fn))
  let intendedLines = string_lines.[startLine..(startLine+rows-1)]
  let separators = [|' '|]
  Array.map (fun (line: string) -> 
      let words = (line.Trim().Split) separators 
      Array.map (fun word -> 
          System.Double.Parse word) 
        words) 
    intendedLines