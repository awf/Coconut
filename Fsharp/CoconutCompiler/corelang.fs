﻿(** 
  The core language supported by the compiler.

  Notice that for every construct defined here, there should be
  either a corresponding definition in the target runtime (e.g. 
  a C function if the target language is C), or the code generator
  should know how to generate code for it.
**)
module corelang

open types
open cardinality
open System
open System.Diagnostics
open System.IO

(** Constructor Methods **)

[<CMacro()>]
let inline build<'a> (size: Cardinality) (f: Index -> 'a): array<'a> =
  [|for i = 0 to ((cardToInt size) - 1) do yield (f i)|]
  // let inputLength = cardToInt size
  // let result = Microsoft.FSharp.Collections.Array.zeroCreate inputLength
  // System.Threading.Tasks.Parallel.For(0, inputLength, fun i -> 
  //     result.[i] <- f i) |> ignore 
  // result 

[<CMacro()>]
let length<'a> (v: array<'a>): Cardinality = 
  Card v.Length


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
let matrixRead (fn: string) (startLine: Index) (rows: Cardinality) (cols: Cardinality): Matrix = 
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

/// Allocates storage needed for a Vector or Matrix. 
/// This storage is available only in the `cont` scope.
[<CMacro()>]
let alloc (size: Cardinality) (cont: Storage -> 'a): 'a =
  let storage = vectorAlloc size
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
let fold_s<'a, 'b, 'ac, 'nac, 'bc> (storage: Storage) 
  (f: Storage -> 'b -> 'a -> 'bc -> 'ac -> 'b) (z: 'b) (range: array<'a>)
  (f_c: 'bc -> 'ac -> 'bc) (z_c: 'bc) (range_c: 'nac): 'b = 
  failwith "fold_s is not implemented"

[<CMonomorphicMacro()>]
let get_s<'a, 's> (storage: Storage) 
  (arr: array<'a>) (ind: Index)
  (arr_c: 's) (ind_c: Cardinality): 'a =
  arr.[ind]

[<CMacro()>]
let newArray_s<'a> (storage: Storage) ([<ParamArray>] args: (Storage -> 'a) array): 'a array =
  args |> Array.map (fun f -> f storage)

[<CMirror("matrix_read_s")>]
let matrixRead_s (storage: Storage) 
      (fn: string) (startLine: Index) (rows: Cardinality) (cols: Cardinality): Matrix = 
  matrixRead fn startLine rows cols
