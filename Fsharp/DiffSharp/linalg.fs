[<ReflectedDefinition>]
module linalg

type Number = double
type Vector = double array
type Matrix = Vector array

let inline mult_by_scalar (x: Vector) (y: Number): Vector =
    Array.map (fun a -> a*y) x

let inline cross (a: Vector) (b: Vector) =
    [| a.[1]*b.[2] - a.[2]*b.[1]; a.[2]*b.[0] - a.[0]*b.[2]; a.[0]*b.[1] - a.[1]*b.[0]; |]

let inline add_vec (x: Vector) (y: Vector) =
    Array.map2 (+) x y

let inline add_vec3 (x: Vector) (y: Vector) (z: Vector) =
  add_vec (add_vec x y) z

let inline sub_vec (x: Vector) (y: Vector) =
    Array.map2 (-) x y
