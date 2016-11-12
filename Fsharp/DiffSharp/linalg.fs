module linalg

open corelang

let inline iterateNumber (f: Number -> Index -> Number) (z: Number) (s: Cardinality) (e: Cardinality): Number = 
  let mutable res = z
  for i=(cardToInt s) to (cardToInt e) do
    res <- f res i
  res

(** Extensions to the core language **)

let rows (m: Matrix): Cardinality = 
  length m

let cols (m: Matrix): Cardinality = 
  length m.[0]

let vectorMap (f: Number -> Number) (v: Vector): Vector = 
  build (length v) (fun i -> f v.[i])

let vectorRange (s: Cardinality) (e: Cardinality): Vector = 
  build (e .- s .+ (Card 1)) (fun i -> double (cardToInt s + i))

let vectorSlice (size: Cardinality) (offset: Index) (v: Vector): Vector =
  build size (fun i -> v.[i + offset])

let matrixSlice (size: Cardinality) (offset: Index) (m: Matrix): Matrix =
  build size (fun i -> m.[i + offset])

let matrixMap (f: Vector -> Vector) (m: Matrix): Matrix = 
  build (length m) (fun i -> f m.[i])

let matrixMapToVector (f: Vector -> Number) (m: Matrix): Vector = 
  build (length m) (fun i -> f m.[i])

let vectorMap2 (f: Number -> Number -> Number) (v1: Vector) (v2: Vector): Vector = 
  build (length v1) (fun i -> f v1.[i] v2.[i])

let matrixMap2 (f: Vector -> Vector -> Vector) (m1: Matrix) (m2: Matrix): Matrix = 
  build (length m1) (fun i -> f m1.[i] m2.[i])

let matrix3DMap2 (f: Matrix -> Matrix -> Matrix) (m1: Matrix[]) (m2: Matrix[]): Matrix[] = 
  build (length m1) (fun i -> f m1.[i] m2.[i])

let vectorMapToMatrix (f: Number -> Vector) (arr: Vector): Matrix = 
  build (length arr) (fun i -> f arr.[i])

let vectorMapToMatrix3D (f: Number -> Matrix) (arr: Vector): Matrix[] = 
  build (length arr) (fun i -> f arr.[i])

(*
let iterate (f: Number -> Index -> Number) (z: Number) (s: Index) (e: Index): unit = 
  ignore (vectorFoldNumber (fun acc cur -> f acc (int cur)) z (vectorRange s e))
*)

//[<CMacro()>]
//let iterateNumber (f: Number -> Index -> Number) (z: Number) (s: Cardinality) (e: Cardinality): Number = 
//  fold (fun acc cur -> f acc (int cur)) z (vectorRange s e)
//
//let iterateVector (f: Vector -> Index -> Vector) (z: Vector) (s: Cardinality) (e: Cardinality): Vector = 
//  fold (fun acc cur -> f acc (int cur)) z (vectorRange s e)
//
//let iterateMatrix (f: Matrix -> Index -> Matrix) (z: Matrix) (s: Cardinality) (e: Cardinality): Matrix = 
//  fold (fun acc cur -> f acc (int cur)) z (vectorRange s e)
//
//let iterateMatrix3D (f: Matrix[] -> Index -> Matrix[]) (z: Matrix[]) (s: Cardinality) (e: Cardinality): Matrix[] = 
//  fold (fun acc cur -> f acc (int cur)) z (vectorRange s e)

let vectorSum (v: Vector): Number = 
  iterateNumber (fun acc cur -> acc + v.[cur]) 0.0 (Card 0) (Card(v.Length - 1))

let vectorMax (v: Vector): Number = 
  iterateNumber (fun acc cur -> if(acc > v.[cur]) then acc else v.[cur]) (-1000.) (Card 0) (Card(v.Length - 1))

let mult_by_scalar (x: Vector) (y: Number): Vector =
    vectorMap (fun xi -> xi * y) x

let gaxpy (a:Number) (x: Vector) (y: Number): Vector =
    vectorMap (fun xi -> a * xi + y) x

let cross (a: Vector) (b: Vector) =
    [| 
      a.[1] * b.[2] - a.[2] * b.[1];
      a.[2] * b.[0] - a.[0] * b.[2];
      a.[0] * b.[1] - a.[1] * b.[0];
    |]

let vectorAdd (x: Vector) (y: Vector) =
    vectorMap2 (+) x y

let mult_vec_elementwise (x: Vector) (y: Vector) =
    vectorMap2 (*) x y

let (.*) (x: Vector) (y: Vector) =
    vectorMap2 (*) x y

let vectorAdd3 (x: Vector) (y: Vector) (z: Vector) =
    vectorAdd (vectorAdd x y) z

let vectorSub (x: Vector) (y: Vector) =
    vectorMap2 (-) x y

let matrixAdd (x: Matrix) (y: Matrix) =
    matrixMap2 vectorAdd x y

let matrixMultElementwise (x: Matrix) (y: Matrix) =
    matrixMap2 mult_vec_elementwise x y

let sqnorm (x: Vector) =
    vectorSum (vectorMap (fun x1 -> x1 * x1) x)

let dot_prod (x: Vector) (y: Vector) =
    vectorSum (vectorMap2 (*) x y)

let matrixFillFromVector (rows: Cardinality) (row: Vector): Matrix = 
  vectorMapToMatrix (fun r -> row) (vectorRange (Card 1) rows)

let matrixFill (rows: Cardinality) (cols: Cardinality) (value: Number): Matrix = 
  build rows (fun r ->
    build cols (fun c ->
      value
    )
  )

let matrixTranspose (m: Matrix): Matrix = 
  let rows = length m
  let cols = length (m.[0])
  build cols (fun i ->
    build rows (fun j ->
      m.[j].[i]
    )
  )

let matrixMult (m1: Matrix) (m2: Matrix): Matrix = 
  let r1 = length m1
  let c2 = length m2.[0]
  let c1 = length m1.[0]
  let r2 = length m2
  let m2T = matrixTranspose m2
  build r1 (fun r ->
    build c2 (fun c ->
      dot_prod m1.[r] m2T.[c]
    )
  )

let matrixVectorMult (m: Matrix) (v: Vector): Vector = 
  let r = rows m
  let c = cols m
  //assert (c = length v)
  build r (fun i ->
      dot_prod m.[i] v
  )

let matrixConcat (m1: Matrix) (m2: Matrix): Matrix = 
  let rows = (length m1) .+ (length m2)
  let m1Rows = cardToInt (length m1)
  build rows (fun r ->
    if r < m1Rows then
      m1.[r]
    else
      m2.[r - m1Rows]
  )

let matrixConcatCol (m1: Matrix) (m2: Matrix): Matrix = 
  let m1t = matrixTranspose m1
  let m2t = matrixTranspose m2
  matrixTranspose (matrixConcat m1t m2t)

let matrix3DConcat (m1: Matrix[]) (m2: Matrix[]): Matrix[] = 
  let rows = (length m1) .+ (length m2)
  let m1Rows = cardToInt (length m1)
  build rows (fun r ->
    if r < m1Rows then
      m1.[r]
    else
      m2.[r - m1Rows]
  )

//let vectorRead (fn: string) (startLine: Index) (cols: Cardinality): Vector = 
//    let matrix = matrixRead fn startLine (Card 1) cols
//    matrix.[0]
//
//let numberRead (fn: string) (startLine: Index): Number = 
//    let vector = vectorRead fn startLine (Card 1)
//    vector.[0]

// Fixed-size vector contstructors
let vec3 (a : Number) (b : Number) (c : Number) = [| a;b;c |]
