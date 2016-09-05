module corelang

open types
open cardinality
open System
open System.Diagnostics
open System.IO

(** Constructor Methods **)

[<CMacro()>]
let build<'a> (size: Cardinality) (f: Index -> 'a): array<'a> =
  [|for i = 0 to ((cardToInt size) - 1) do yield (f i)|]

[<CMacro()>]
let length<'a> (v: array<'a>): Cardinality = 
  Card v.Length
(*
let private arrayRange (s: int) (e: int): Vector = 
  build (Card(e - s + 1)) (fun i -> double (s + i))
*)
(** Transformer Methods **)
(*
[<CMirror("matrix_concat")>]
let matrixConcat (m1: Matrix) (m2: Matrix): Matrix = 
  Array.append m1 m2

[<CMirror("matrix3d_concat")>]
let matrix3DConcat (m1: Matrix[]) (m2: Matrix[]): Matrix[] = 
  Array.append m1 m2
*)
(*
[<CMirror("matrix_transpose")>]
let matrixTranspose (m: Matrix): Matrix = 
  Array.map (fun c -> Array.map (fun r -> m.[int r - 1].[int c - 1]) (arrayRange 1 (m.Length))) (arrayRange 1 (m.[0].Length))
*)
(*
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
*)

(** Fold methods **)

[<CMacro()>]
let fold<'a, 'b> (f: 'b -> 'a -> 'b) (z: 'b) (range: array<'a>): 'b = 
  Array.fold (fun acc cur -> f acc cur) z range

(** I/O Methods **)

[<CMirror("number_print")>]
let numberPrint (v: Number): Unit = 
  printfn "%f" v

[<CMirror("array_print")>]
let vectorPrint (v: Vector): Unit = 
  printfn "[%s]" (String.concat ", " (Array.map (sprintf "%f") v))

[<CMirror("matrix_print")>]
let matrixPrint (v: Matrix): Unit = 
  printf "[\n   "
  Array.iteri (fun i x -> (if(i <> 0) then printf " , " else ()); vectorPrint x) v
  printfn "]"

[<CMirror("matrix_read")>]
let matrixRead (fn: string) (startLine: Index) (rows: Cardinality): Matrix = 
  let string_lines = Array.ofSeq (File.ReadLines(fn))
  let intendedLines = string_lines.[startLine..(startLine+(cardToInt rows)-1)]
  let separators = [|' '|]
  Array.map (fun (line: string) -> 
      let words = (line.Trim().Split) separators 
      Array.map (fun word -> 
          System.Double.Parse word) 
        words) 
    intendedLines

(** Memory management methods **)

[<CMirror("vector_alloc")>]
let vectorAlloc (size: Cardinality): Storage =
  let v = [|for i = 0 to (cardToInt size - 1) do yield (0.0)|]
  VS v

[<CMacro()>]
let vectorAllocOnStack (size: Cardinality): Storage =
  let v = [|for i = 0 to (cardToInt size - 1) do yield (0.0)|]
  VS v

[<CMacro()>]
let vectorCopy (storage: Storage) (v: Vector) =
  v

/// Allocates storage needed for a Vector. 
/// This storage is available only in the `cont` scope.
[<CMirror("vector_alloc_cps")>]
[<CMacro()>]
let vectorAllocCPS (size: Cardinality) (cont: Storage -> 'a): 'a =
  let storage = vectorAlloc(size)
  cont(storage)

// TODO needs size parameter
[<CMirror("vector_build_given_storage")>]
[<CMacro()>]
let vectorBuildGivenStorage (storage: Storage) (f: Index -> Number): Vector =
  match storage with
  | VS v -> build (Card v.Length) f
  | _    -> failwithf "Cannot build a vector by the provided storage `%A`" storage

[<CMacro()>]
let build_s<'a, 's> (storage: Storage) 
  (size: Cardinality) (f: Storage -> Index -> Cardinality -> 'a)
  (size_c: Cardinality) (f_c: Cardinality -> 's): array<'a> =
  match storage with
  //| VS v -> vectorBuild size (fun i -> f storage i (Card 0))
  | _    -> failwithf "Cannot build a vector by the provided storage `%A`" storage

[<CMacro()>]
let fold_s<'a, 'b, 'ac, 'bc> (storage: Storage) 
  (f: Storage -> 'b -> 'a -> 'bc -> 'ac -> 'b) (z: 'b) (range: array<'a>)
  (f_c: 'bc -> 'ac -> 'bc) (z_c: 'bc) (range_c: NestedShape<'ac>): 'b = 
  Array.fold (fun acc cur -> f storage acc cur z_c (shapeElem range_c)) z range

[<CMonomorphicMacro()>]
let get_s<'a, 's> (storage: Storage) 
  (arr: array<'a>) (ind: Index)
  (arr_c: 's) (ind_c: Cardinality): 'a =
  arr.[ind]

[<CMacro()>]
let newArray_s<'a> (storage: Storage) ([<ParamArray>] args: (Storage -> 'a) array): 'a array =
  args |> Array.map (fun f -> f storage)

[<CMirror("matrix_read")>]
let matrixRead_s (storage: Storage) 
      (fn: string) (startLine: Index) (rows: Cardinality): Matrix = 
  matrixRead fn startLine rows