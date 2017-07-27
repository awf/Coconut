[<ReflectedDefinition>]
module ccodegentests

open types
open corelang

let closure_bug1 (m1: Matrix) (m2: Matrix): Matrix = 
  build (Card 10) (fun i -> build (Card 20) (fun j -> double(j)))

let closure_bug2 (m1: Matrix) (m2: Matrix): Matrix = 
  build (Card 10) (fun i -> build (Card 20) (fun j -> double(i + j)))

let closure_bug3 (m1: Matrix) (m2: Matrix): Matrix = 
  let n = 3.0
  build (Card 10) (fun i -> build (Card 20) (fun j -> double(i + j) * n))

let valloc_cps_feature1 (dum: Vector): unit =
  alloc (Card 10) (fun s -> 
    vectorPrint dum
    vectorPrint dum
  )
  ()

let valloc_cps_feature2 (dum: Vector): unit =
  alloc (Card 10) (fun s -> 
    alloc (Card 10) (fun s2 -> 
      vectorPrint dum
      vectorPrint dum
    )
  )
  ()

let rec numSum (n: Number): Number =
  if n = 0. then 
    0.
  else 
    numSum (n - 1.) + n

let liftingBug (n: Number): Vector = 
  let v = (fun i -> n * (double)(i))
  [| 
     v 0 ; 
     v 1
  |]