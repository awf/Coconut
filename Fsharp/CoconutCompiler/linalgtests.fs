[<ReflectedDefinition>]
module linalgtests

open corelang
open linalg
open types
open utils
open cardinality

let test1 (dum: Vector) =
  let a = [| 1.0; 2.0; 3.0 |]
  let b = [| 5.0; 6.0; 7.0 |]
  vectorPrint a
  vectorPrint b
(*  vectorPrint (foo b) *)

  let c = cross a b
  vectorPrint c
  let d = mult_by_scalar c 15.0
  vectorPrint d
  let e = vectorAdd a b
  vectorPrint e
  let f = vectorSub a b
  vectorPrint f
  let g = vectorAdd3 a b c
  vectorPrint g
  let h = sqnorm a
  numberPrint h
  let i = dot_prod a b
  numberPrint i
  let r1 = [| 1.0; 2.0; 3.0; |]
  let r2 = [| 4.0; 5.0; 6.0; |]
  let r3 = [| 7.0; 8.0; 9.0; |]
  let mat0 = 
    [| 
       [| 1.0; 2.0; 3.0; |];
       [| 4.0; 5.0; 6.0; |];
       [| 7.0; 8.0; 9.0; |]
    |]
  let mat1 = 
    [| r1; r2; r3 |]
  let n = matrixMult mat0 mat1
  matrixPrint n
  let o = matrixTranspose n
  matrixPrint o
  let p = matrixConcatCol mat1 mat1
  matrixPrint p
  let t = matrixAdd mat1 mat1
  matrixPrint t
  let u = matrixFillFromVector (Card 5) a
  matrixPrint u
  let v = matrixFill (Card 5) (Card 2) 5.0
  matrixPrint v
  ()