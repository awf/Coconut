[<ReflectedDefinition>]
module linalg

type Number = double
type Vector = double array
type Matrix = Vector array

let inline mult_by_scalar (x: Vector) (y: Number): Vector =
    Array.map (fun a -> a*y) x
