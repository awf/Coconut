module utils

open types
open System

open System.IO

(** I/O Methods **)

[<CMirror("number_print")>]
let numberPrint (v: Number): Unit = 
  printfn "%f" v

[<CMirror("array_print")>]
let arrayPrint (v: Vector): Unit = 
  printfn "[%s]" (String.concat ", " (Array.map (sprintf "%f") v))

[<CMirror("matrix_print")>]
let matrixPrint (v: Matrix): Unit = 
  printf "[\n   "
  Array.iteri (fun i x -> (if(i <> 0) then printf " , " else ()); arrayPrint x) v
  printfn "]"

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

(** Constructor Methods **)

[<CMirror("array_range")>]
let arrayRange (s: Index) (e: Index): Vector = 
  [|for i = s to e do yield (double i)|]

(** Transformer Methods **)

[<CMirror("array_map")>]
let arrayMap (f: Number -> Number) (arr: Vector): Vector = 
  Array.map f arr

[<CMirror("array_map2")>]
let arrayMap2 (f: Number -> Number -> Number) (arr1: Vector) (arr2: Vector): Vector = 
  Array.map2 f arr1 arr2

(** Consumer Methods **)

[<CMirror("array_sum")>]
let arraySum (arr: Vector): Number = 
  Array.sum arr

[<CMirror("array_map_to_matrix")>]
let arrayMapToMatrix (f: Number -> Vector) (arr: Vector): Matrix = 
  Array.map f arr

(** Utility Methods (Which are only used in the meta language) **)

let listDiff list1 list2 = 
  List.filter (fun x -> not (List.exists (fun y -> x = y) list2)) list1
