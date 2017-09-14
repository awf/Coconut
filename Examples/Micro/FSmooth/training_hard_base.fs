[<ReflectedDefinition>]
module training_base

open types
open corelang
open cardinality

let scalar0 (x: Number): Number =
  x + 42.

let scalar1 (x: Number): Number =
  x - 42.

let scalar2 (x: Number): Number =
  x + 0.

let scalar3 (x: Number): Number =
  x - 0.

let scalar4 (x: Number): Number =
  x + x

let scalar5 (x: Number): Number =
  x - x

let scalar6 (x: Number): Number =
  x * 0.

let scalar7 (x: Number): Number =
  x * 1.

let scalar8 (x: Number): Number =
  x * 2.

let scalar9 (x: Number): Number =
  x * 42.

let scalar10 (x: Number): Number =
  x / 42.

let scalar11 (x: Number): Number =
  x * x

let scalar12 (x: Number): Number =
  x / x

let scalar13 (x: Number): Number =
  1. / x

let scalar14 (x: Number): Number =
  0. / x

let scalar15 (x: Number): Number =
  2. / x

let scalar16 (x: Number): Number =
  x / 2.

let scalar17 (x: Number): Number =
  x / 1.

let scalar18 (a: Number) (b: Number): Number =
  a + b

let scalar19 (a: Number) (b: Number): Number =
  a - b

let scalar20 (a: Number) (b: Number): Number =
  a * b

let scalar21 (a: Number) (b: Number): Number =
  a / b

