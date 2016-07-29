[<ReflectedDefinition>]
module linalg

open corelang
open types
open utils

(** Extensions to the core language **)

[<DontInline>]
let inline vectorMap (f: Number -> Number) (v: Vector): Vector = 
    vectorBuild (v.Length) (fun i -> f(v.[i]))

[<DontInline>]
let vectorRange (s: Index) (e: Index): Vector = 
  vectorBuild (e - s + 1) (fun i -> double (s + i))

[<DontInline>]
let matrixMap (f: Vector -> Vector) (m: Matrix): Matrix = 
  matrixBuild (m.Length) (fun i -> f(m.[i]))

[<DontInline>]
let vectorMap2 (f: Number -> Number -> Number) (v1: Vector) (v2: Vector): Vector = 
  vectorBuild (v1.Length) (fun i -> f(v1.[i])(v2.[i]))

[<DontInline>]
let matrixMap2 (f: Vector -> Vector -> Vector) (m1: Matrix) (m2: Matrix): Matrix = 
  matrixBuild (m1.Length) (fun i -> f(m1.[i])(m2.[i]))

[<DontInline>]
let matrix3DMap2 (f: Matrix -> Matrix -> Matrix) (m1: Matrix[]) (m2: Matrix[]): Matrix[] = 
  matrix3DBuild (m1.Length) (fun i -> f(m1.[i])(m2.[i]))

[<DontInline>]
let vectorMapToMatrix (f: Number -> Vector) (arr: Vector): Matrix = 
  matrixBuild (arr.Length) (fun i -> f(arr.[i]))

[<DontInline>]
let vectorMapToMatrix3D (f: Number -> Matrix) (arr: Vector): Matrix[] = 
  matrix3DBuild (arr.Length) (fun i -> f(arr.[i]))

[<DontInline>]
let iterateMatrix (f: Matrix -> Index -> Matrix) (z: Matrix) (s: Index) (e: Index): Matrix = 
  vectorFoldMatrix (fun acc cur -> f acc (int cur)) z (vectorRange s e)

[<DontInline>]
let iterateMatrix3D (f: Matrix[] -> Index -> Matrix[]) (z: Matrix[]) (s: Index) (e: Index): Matrix[] = 
  vectorFoldMatrix3D (fun acc cur -> f acc (int cur)) z (vectorRange s e)

[<DontInline>]
let arraySum (arr: Vector): Number = 
  vectorFoldNumber (fun acc cur -> acc + cur) 0.0 arr

[<DontInline>]
let arrayMax (arr: Vector): Number = 
  vectorFoldNumber (fun acc cur -> if(acc > cur) then acc else cur) (-1000.) arr

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
let inline matrixFillFromVector (rows: Index) (row: Vector): Matrix = 
  vectorMapToMatrix (fun r -> row) (vectorRange 1 rows)

let inline matrixFill (rows: Index) (cols: Index) (value: Number): Matrix = 
  let row = vectorMap (fun c -> value) (vectorRange 1 cols)
  matrixFillFromVector rows row

let matrixConcatCol (m1: Matrix) (m2: Matrix): Matrix = 
  let m1t = matrixTranspose m1
  let m2t = matrixTranspose m2
  matrixTranspose (matrixConcat m1t m2t)

let vectorRead (fn: string) (startLine: Index): Vector = 
    let matrix = matrixRead fn startLine 1
    matrix.[0]

let numberRead (fn: string) (startLine: Index): Number = 
    let vector = vectorRead fn startLine
    vector.[0]