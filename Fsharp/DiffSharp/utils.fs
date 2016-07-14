module utils

open types
open System
open System.Diagnostics
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

[<CMirror("matrix_concat")>]
let matrixConcat (m1: Matrix) (m2: Matrix): Matrix = 
  Array.append m1 m2

[<CMirror("array_map")>]
let arrayMap (f: Number -> Number) (arr: Vector): Vector = 
  Array.map f arr

[<CMirror("array_map2")>]
let arrayMap2 (f: Number -> Number -> Number) (arr1: Vector) (arr2: Vector): Vector = 
  Array.map2 f arr1 arr2

[<CMirror("array_map_to_matrix")>]
let arrayMapToMatrix (f: Number -> Vector) (arr: Vector): Matrix = 
  Array.map f arr

[<CMirror("matrix_transpose")>]
let matrixTranspose (m: Matrix): Matrix = 
  Array.map (fun c -> Array.map (fun r -> m.[int r - 1].[int c - 1]) (arrayRange 1 (m.Length))) (arrayRange 1 (m.[0].Length))

[<CMirror("matrix_mult")>]
let matrixMult (m1: Matrix) (m2: Matrix): Matrix = 
  let r1 = m1.Length
  let c2 = m2.[0].Length
  let c1 = m1.[0].Length
  let m2T = matrixTranspose(m2)
  Array.map (fun r -> 
    Array.map (fun c -> 
      Array.sum 
        (Array.map2 ( * ) (m1.[int r]) (m2.[int c]))) (arrayRange 0 (c2 - 1)))
    (arrayRange 0 (r1 - 1))

(** Consumer Methods **)

[<CMirror("array_sum")>]
let arraySum (arr: Vector): Number = 
  Array.sum arr

[<CMirror("array_max")>]
let arrayMax (arr: Vector): Number = 
  Array.max arr

(** Timing **)

[<CMirror("tic")>]
let tic(): Timer = 
  Stopwatch.StartNew()

[<CMirror("toc")>]
let toc(t: Timer) = 
  t.Stop()
  printfn "Time: %d ms" t.ElapsedMilliseconds

(** Utility Methods (Which are only used in the meta language) **)

let listDiff list1 list2 = 
  List.filter (fun x -> not (List.exists (fun y -> x = y) list2)) list1
