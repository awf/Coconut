[<ReflectedDefinition>]
module linalg

open corelang
open types
open utils
open cardinality

(** Extensions to the core language **)

[<DontInline>]
let inline vectorMap (f: Number -> Number) (v: Vector): Vector = 
  build (length v) (fun i -> f(v.[i]))

[<DontInline>]
let vectorRange (s: Cardinality) (e: Cardinality): Vector = 
  build (e .- s .+ (Card 1)) (fun i -> double (cardToInt s + i))

let vectorSlice (size: Cardinality) (offset: Index) (v: Vector): Vector =
  build size (fun i -> v.[i + offset])

[<DontInline>]
let matrixMap (f: Vector -> Vector) (m: Matrix): Matrix = 
  build (length m) (fun i -> f(m.[i]))

[<DontInline>]
let vectorMap2 (f: Number -> Number -> Number) (v1: Vector) (v2: Vector): Vector = 
  build (length v1) (fun i -> f(v1.[i])(v2.[i]))

[<DontInline>]
let matrixMap2 (f: Vector -> Vector -> Vector) (m1: Matrix) (m2: Matrix): Matrix = 
  build (length m1) (fun i -> f(m1.[i])(m2.[i]))

[<DontInline>]
let matrix3DMap2 (f: Matrix -> Matrix -> Matrix) (m1: Matrix[]) (m2: Matrix[]): Matrix[] = 
  build (length m1) (fun i -> f(m1.[i])(m2.[i]))

[<DontInline>]
let vectorMapToMatrix (f: Number -> Vector) (arr: Vector): Matrix = 
  build (length arr) (fun i -> f(arr.[i]))

[<DontInline>]
let vectorMapToMatrix3D (f: Number -> Matrix) (arr: Vector): Matrix[] = 
  build (length arr) (fun i -> f(arr.[i]))

(*
[<DontInline>]
let iterate (f: Number -> Index -> Number) (z: Number) (s: Index) (e: Index): unit = 
  ignore (vectorFoldNumber (fun acc cur -> f acc (int cur)) z (vectorRange s e))
*)

[<DontInline>]
[<CMacro()>]
let iterateNumber (f: Number -> Index -> Number) (z: Number) (s: Cardinality) (e: Cardinality): Number = 
  fold (fun acc cur -> f acc (int cur)) z (vectorRange s e)

[<DontInline>]
let iterateVector (f: Vector -> Index -> Vector) (z: Vector) (s: Cardinality) (e: Cardinality): Vector = 
  fold (fun acc cur -> f acc (int cur)) z (vectorRange s e)

[<DontInline>]
let iterateMatrix (f: Matrix -> Index -> Matrix) (z: Matrix) (s: Cardinality) (e: Cardinality): Matrix = 
  fold (fun acc cur -> f acc (int cur)) z (vectorRange s e)

[<DontInline>]
let iterateMatrix3D (f: Matrix[] -> Index -> Matrix[]) (z: Matrix[]) (s: Cardinality) (e: Cardinality): Matrix[] = 
  fold (fun acc cur -> f acc (int cur)) z (vectorRange s e)

[<DontInline>]
let arraySum (arr: Vector): Number = 
  fold (fun acc cur -> acc + cur) 0.0 arr

[<DontInline>]
let arrayMax (arr: Vector): Number = 
  fold (fun acc cur -> if(acc > cur) then acc else cur) (-1000.) arr

let inline mult_by_scalar (x: Vector) (y: Number): Vector =
    vectorMap (fun a -> a*y) x

let inline cross (a: Vector) (b: Vector) =
    [| a.[1]*b.[2] - a.[2]*b.[1]; a.[2]*b.[0] - a.[0]*b.[2]; a.[0]*b.[1] - a.[1]*b.[0]; |]

[<DontInline>]
let inline add_vec (x: Vector) (y: Vector) =
    vectorMap2 (+) x y

[<DontInline>]
let inline mult_vec_elementwise (x: Vector) (y: Vector) =
    vectorMap2 (*) x y

let inline add_vec3 (x: Vector) (y: Vector) (z: Vector) =
    add_vec (add_vec x y) z

let inline sub_vec (x: Vector) (y: Vector) =
    vectorMap2 (-) x y

[<DontInline>]
let inline matrixAdd (x: Matrix) (y: Matrix) =
    matrixMap2 add_vec x y

[<DontInline>]
let inline matrixMultElementwise (x: Matrix) (y: Matrix) =
    matrixMap2 mult_vec_elementwise x y

(*[<DontInline>]*)
let inline sqnorm (x: Vector) =
    arraySum (vectorMap (fun x1 -> x1*x1) x)

let inline dot_prod (x: Vector) (y: Vector) =
    arraySum (vectorMap2 (*) x y)

[<DontInline>]
let inline matrixFillFromVector (rows: Cardinality) (row: Vector): Matrix = 
  vectorMapToMatrix (fun r -> row) (vectorRange (Card 1) rows)

let inline matrixFill (rows: Cardinality) (cols: Cardinality) (value: Number): Matrix = 
  let row = vectorMap (fun c -> value) (vectorRange (Card 1) cols)
  matrixFillFromVector rows row

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
      arraySum ( vectorMap2 ( * ) m1.[r] m2T.[c] )
    )
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

let vectorRead (fn: string) (startLine: Index): Vector = 
    let matrix = matrixRead fn startLine 1
    matrix.[0]

let numberRead (fn: string) (startLine: Index): Number = 
    let vector = vectorRead fn startLine
    vector.[0]

[<DontInline>]
let vectorMap2GivenStorage (storage: Storage) (f: Number -> Number -> Number) (v1: Vector) (v2: Vector): Vector = 
  vectorBuildGivenStorage storage (fun i -> f(v1.[i])(v2.[i]))

[<DontInline>]
let inline add_vecGivenStorage (s: Storage) (x: Vector) (y: Vector) =
    vectorMap2GivenStorage s (+) x y
