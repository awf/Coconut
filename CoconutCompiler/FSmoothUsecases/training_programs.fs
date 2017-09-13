[<ReflectedDefinition>]
module training_programs

open linalg
open types
open corelang
open cardinality

//let scalar1 (x: Number): Number = 
//  let a = 1. / x
//  a / (a + 1.)

let scalar1 (x: Number) (b: Number): Number =
  x + (b - b)

let scalar2 (x: Number) (b: Number): Number =
  (x + b) - b

let scalar3 (x: Number): Number = 
  1. / (1. / x)

let scalar4 (x: Number): Number = 
  let a = 1. / x
  1. / a

let scalar5 (x: Number): Number = 
  1. * x + 0.

let scalar6 (x: Number): Number = 
  let a = 1. * x
  a + 0.

let scalar7 (x: Number) (b: Number): Number = 
  ((x / x) / x) / ((b / b) / x)

let vectorAdd0 (v1: Vector): Vector = 
  vectorAdd v1 (build (length v1) (fun i -> 0.))

let vectorMult0 (v1: Vector): Vector = 
  mult_vec_elementwise v1 (build (length v1) (fun i -> 0.))

let vectorMult1 (v1: Vector): Vector = 
  mult_vec_elementwise v1 (build (length v1) (fun i -> 1.))

let vectorSMult0 (v1: Vector): Vector = 
  mult_by_scalar v1 0.

let vectorSMult1 (v1: Vector): Vector = 
  mult_by_scalar v1 1.

//let vectorAdd3 (v1: Vector) (v2: Vector) (v3: Vector): Vector = 
//  vectorAdd v1 (vectorAdd v2 v3)

//let vectorMult3 (v1: Vector) (v2: Vector) (v3: Vector): Vector = 
//  mult_vec_elementwise v1 (mult_vec_elementwise v2 v3)

//let matrixAdd2 (m1: Matrix) (m2: Matrix): Matrix = 
//  matrixAdd m1 m2

//let matrixAdd3 (m1: Matrix) (m2: Matrix) (m3: Matrix): Matrix = 
//  matrixAdd m1 (matrixAdd m2 m3)

//let matrixMult3 (m1: Matrix) (m2: Matrix) (m3: Matrix): Matrix = 
//  matrixMult m1 (matrixMult m2 m3)

let scalarHard1 (a: Number): Number = 
  (1. / a) / (1. + 1. / a)

let scalarHard2 (a: Number): Number =
  (1. / a + 1.) * a