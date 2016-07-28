module corelang

open types
open System
open System.Diagnostics
open System.IO

(** Constructor Methods **)

[<CMirror("vector_build")>]
let vectorBuild (size: Index) (f: Index -> Number): Vector =
  [|for i = 0 to (size - 1) do yield (f i)|]

[<CMirror("matrix_build")>]
let matrixBuild (size: Index) (f: Index -> Vector): Matrix =
  [|for i = 0 to (size - 1) do yield (f i)|]

[<CMirror("matrix3d_build")>]
let matrix3DBuild (size: Index) (f: Index -> Matrix): Matrix3D =
  [|for i = 0 to (size - 1) do yield (f i)|]

// TODO remove from core
[<CMirror("array_range")>]
let arrayRange (s: Index) (e: Index): Vector = 
  vectorBuild (e - s + 1) (fun i -> double (s + i))

(** Transformer Methods **)

[<CMirror("matrix_concat")>]
let matrixConcat (m1: Matrix) (m2: Matrix): Matrix = 
  Array.append m1 m2

[<CMirror("matrix3d_concat")>]
let matrix3DConcat (m1: Matrix[]) (m2: Matrix[]): Matrix[] = 
  Array.append m1 m2

// TODO remove from core
[<CMirror("array_map")>]
let arrayMap (f: Number -> Number) (v: Vector): Vector = 
  vectorBuild (v.Length) (fun i -> f(v.[i]))

// TODO remove from core
[<CMirror("matrix_map")>]
let matrixMap (f: Vector -> Vector) (m: Matrix): Matrix = 
  matrixBuild (m.Length) (fun i -> f(m.[i]))

// TODO remove from core
[<CMirror("array_map2")>]
let arrayMap2 (f: Number -> Number -> Number) (v1: Vector) (v2: Vector): Vector = 
  // Array.map2 f arr1 arr2
  vectorBuild (v1.Length) (fun i -> f(v1.[i])(v2.[i]))

// TODO remove from core
[<CMirror("matrix_map2")>]
let matrixMap2 (f: Vector -> Vector -> Vector) (m1: Matrix) (m2: Matrix): Matrix = 
  //Array.map2 f m1 m2
  matrixBuild (m1.Length) (fun i -> f(m1.[i])(m2.[i]))

// TODO remove from core
[<CMirror("matrix3d_map2")>]
let matrix3DMap2 (f: Matrix -> Matrix -> Matrix) (m1: Matrix[]) (m2: Matrix[]): Matrix[] = 
  //Array.map2 f m1 m2
  matrix3DBuild (m1.Length) (fun i -> f(m1.[i])(m2.[i]))

// TODO remove from core
[<CMirror("array_map_to_matrix")>]
let arrayMapToMatrix (f: Number -> Vector) (arr: Vector): Matrix = 
  //Array.map f arr
  matrixBuild (arr.Length) (fun i -> f(arr.[i]))

// TODO remove from core
[<CMirror("array_map_to_matrix3d")>]
let arrayMapToMatrix3D (f: Number -> Matrix) (arr: Vector): Matrix[] = 
  //Array.map f arr
  matrix3DBuild (arr.Length) (fun i -> f(arr.[i]))

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

[<CMirror("vector_fold_matrix")>]
let vectorFoldMatrix (f: Matrix -> Index -> Matrix) (z: Matrix) (range: Vector): Matrix = 
  Array.fold (fun acc cur -> f acc (int cur)) z range

[<CMirror("vector_fold_matrix3d")>]
let vectorFoldMatrix3D (f: Matrix[] -> Index -> Matrix[]) (z: Matrix[]) (range: Vector): Matrix[] = 
  Array.fold (fun acc cur -> f acc (int cur)) z range

// TODO remove from core
[<CMirror("iterate_matrix")>]
let iterateMatrix (f: Matrix -> Index -> Matrix) (z: Matrix) (s: Index) (e: Index): Matrix = 
  vectorFoldMatrix f z (arrayRange s e)

// TODO remove from core
[<CMirror("iterate_matrix3d")>]
let iterateMatrix3D (f: Matrix[] -> Index -> Matrix[]) (z: Matrix[]) (s: Index) (e: Index): Matrix[] = 
  vectorFoldMatrix3D f z (arrayRange s e)


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