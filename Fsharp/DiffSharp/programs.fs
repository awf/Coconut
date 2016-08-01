[<ReflectedDefinition>]
module programs

open linalg
open types
open corelang

let test1 (x: Number): Number = 
  let a = 1. / x
  a / (a + 1.)

let test2 (x: Number) (b: Number): Number =
  (x + b) - b

let vector_add3 (v1: Vector) (v2: Vector) (v3: Vector): Vector = 
  add_vec v1 (add_vec v2 v3)

let matrix_add3 (m1: Matrix) (m2: Matrix) (m3: Matrix): Matrix = 
  matrixAdd m1 (matrixAdd m2 m3)

let hoistingExample (v: Vector) = 
  let sum = 
    iterateNumber (fun acc idx ->
        let tmp = v.[idx..(idx+9)]
        sqnorm(add_vec tmp tmp)
      ) (0.) 0 9
  numberPrint sum
  ()

[<DontOptimize>]
let explicitMallocExample (v: Vector) = 
  //let storage1 = vectorAlloc 10 
  vectorAllocCPS 10 (fun storage1 ->
    let sum = 
      iterateNumber (fun acc idx ->
          let tmp = vectorBuildByStorage storage1 (fun i -> v.[i + idx])
          sqnorm(add_vec tmp tmp)
        ) 0. 0 9
    numberPrint sum
  )
  ()

let small_tests (dum: Number) = 
  let num = 2.
  let a = test1(num)
  numberPrint a
  numberPrint (test2 num a)
  let v2 = vectorRange(0)(99)
  hoistingExample(v2)
  explicitMallocExample(v2)
  ()