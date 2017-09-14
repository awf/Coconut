[<ReflectedDefinition>]
module training_hard_base

open types
open corelang
open cardinality

//let scalarHard1 (a: Number): Number = 
  //(1. / a) / (1. + 1. / a)

let scalarSimple1 (a: Number): Number =
  1. / a

let scalarSimple2 (a: Number): Number =
  1. * a

let scalarSimple3 (a: Number): Number =
  a / 1.

let scalarSimple4 (a: Number): Number =
  a + 42.

let scalarSimple5 (a: Number): Number =
  a + 0.

let scalarSimple6 (a: Number): Number =
  a - 0.

let scalarHard2 (a: Number): Number =
  (1. / a + 1.) * a

let scalar0 (a: Number) (b: Number): Number =
  a + b

let scalar1 (a: Number) (b: Number): Number =
  a - b

let scalar2 (a: Number) (b: Number): Number =
  a * b

//let scalar3 (a: Number) (b: Number): Number =
//  a / b