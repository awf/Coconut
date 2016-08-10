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

let private arrayRange (s: Index) (e: Index): Vector = 
  vectorBuild (e - s + 1) (fun i -> double (s + i))

(** Transformer Methods **)

[<CMirror("matrix_concat")>]
let matrixConcat (m1: Matrix) (m2: Matrix): Matrix = 
  Array.append m1 m2

[<CMirror("matrix3d_concat")>]
let matrix3DConcat (m1: Matrix[]) (m2: Matrix[]): Matrix[] = 
  Array.append m1 m2

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

(** Fold methods **)

[<CMirror("vector_fold_number")>]
let vectorFoldNumber (f: Number -> Number -> Number) (z: Number) (range: Vector): Number = 
  Array.fold (fun acc cur -> f acc cur) z range

[<CMirror("vector_fold_vector")>]
let vectorFoldVector (f: Vector -> Number -> Vector) (z: Vector) (range: Vector): Vector = 
  Array.fold (fun acc cur -> f acc cur) z range

[<CMirror("vector_fold_matrix")>]
let vectorFoldMatrix (f: Matrix -> Number -> Matrix) (z: Matrix) (range: Vector): Matrix = 
  Array.fold (fun acc cur -> f acc cur) z range

[<CMirror("vector_fold_matrix3d")>]
let vectorFoldMatrix3D (f: Matrix[] -> Number -> Matrix[]) (z: Matrix[]) (range: Vector): Matrix[] = 
  Array.fold (fun acc cur -> f acc cur) z range

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

(** Memory management methods **)

[<CMirror("vector_alloc")>]
let vectorAlloc (size: Index): Storage =
  let v = [|for i = 0 to (size - 1) do yield (0.0)|]
  VS v

/// Allocates storage needed for a Vector. 
/// This storage is available only in the `cont` scope.
[<CMirror("vector_alloc_cps")>]
[<CMacro()>]
let vectorAllocCPS (size: Index) (cont: Storage -> 'a): 'a =
  let storage = vectorAlloc(size)
  cont(storage)

[<CMirror("vector_build_given_storage")>]
[<CMacro()>]
let vectorBuildGivenStorage (storage: Storage) (f: Index -> Number): Vector =
  match storage with
  | VS v -> vectorBuild(v.Length)(f)
  | _    -> failwithf "Cannot build a vector by the provided storage `%A`" storage