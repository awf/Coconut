[<ReflectedDefinition>]
module programs

open linalg
open types
open corelang

let test1 (x: Number): Number = 
  let a = 1. / x
  a / (a + 1.)

let small_tests(dum: Number) = 
  let num = 2.
  let a = test1(num)
  numberPrint a