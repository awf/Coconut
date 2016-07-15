module corelang

open types
open System
open System.Diagnostics
open System.IO

(** Constructor Methods **)

[<CMirror("array_range")>]
let arrayRange (s: Index) (e: Index): Vector = 
  [|for i = s to e do yield (double i)|]

(** Transformer Methods **)

[<CMirror("matrix_concat")>]
let matrixConcat (m1: Matrix) (m2: Matrix): Matrix = 
  Array.append m1 m2

[<CMirror("matrix3d_concat")>]
let matrix3DConcat (m1: Matrix[]) (m2: Matrix[]): Matrix[] = 
  Array.append m1 m2

[<CMirror("array_map")>]
let arrayMap (f: Number -> Number) (arr: Vector): Vector = 
  Array.map f arr

[<CMirror("matrix_map")>]
let matrixMap (f: Vector -> Vector) (m: Matrix): Matrix = 
  Array.map f m

[<CMirror("array_map2")>]
let arrayMap2 (f: Number -> Number -> Number) (arr1: Vector) (arr2: Vector): Vector = 
  Array.map2 f arr1 arr2

[<CMirror("matrix_map2")>]
let matrixMap2 (f: Vector -> Vector -> Vector) (m1: Matrix) (m2: Matrix): Matrix = 
  Array.map2 f m1 m2

[<CMirror("matrix3d_map2")>]
let matrix3DMap2 (f: Matrix -> Matrix -> Matrix) (m1: Matrix[]) (m2: Matrix[]): Matrix[] = 
  Array.map2 f m1 m2

[<CMirror("array_map_to_matrix")>]
let arrayMapToMatrix (f: Number -> Vector) (arr: Vector): Matrix = 
  Array.map f arr

[<CMirror("array_map_to_matrix3d")>]
let arrayMapToMatrix3D (f: Number -> Matrix) (arr: Vector): Matrix[] = 
  Array.map f arr

[<CMirror("matrix_transpose")>]
let matrixTranspose (m: Matrix): Matrix = 
  Array.map (fun c -> Array.map (fun r -> m.[int r - 1].[int c - 1]) (arrayRange 1 (m.Length))) (arrayRange 1 (m.[0].Length))

[<CMirror("matrix_mult")>]
let matrixMult (m1: Matrix) (m2: Matrix): Matrix = 
  let r1 = m1.Length
  let c2 = m2.[0].Length
  let c1 = m1.[0].Length
  let r2 = m2.Length
  if(c1<>r2) then
    failwith (sprintf "Matrcies have the inconsistent dimensions %dx%d and %dx%d for MMM" r1 c1 r2 c2)
  let m2T = matrixTranspose(m2)
  Array.map (fun r -> 
    Array.map (fun c -> 
      Array.sum 
        (Array.map2 ( * ) (m1.[int r]) (m2T.[int c]))) (arrayRange 0 (c2 - 1)))
    (arrayRange 0 (r1 - 1))

(** Consumer Methods **)

[<CMirror("array_sum")>]
let arraySum (arr: Vector): Number = 
  Array.sum arr

[<CMirror("array_max")>]
let arrayMax (arr: Vector): Number = 
  Array.max arr

(** Fold methods **)

[<CMirror("iterate_matrix")>]
let iterateMatrix (f: Matrix -> Index -> Matrix) (z: Matrix) (s: Index) (e: Index): Matrix = 
  Array.fold (fun acc cur -> f acc (int cur)) z (arrayRange s e)

[<CMirror("iterate_matrix3d")>]
let iterateMatrix3D (f: Matrix[] -> Index -> Matrix[]) (z: Matrix[]) (s: Index) (e: Index): Matrix[] = 
  Array.fold (fun acc cur -> f acc (int cur)) z (arrayRange s e)


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