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

let inline sqnorm (x: Vector) =
    Array.sum (Array.map (fun x -> x*x) x)

let inline dot_prod (x: Vector) (y: Vector) =
    Array.sum (Array.map2 (*) x y)

let radial_distort (rad_params: Vector) (proj: Vector) =
    let rsq = sqnorm proj
    let L = 1. + rad_params.[0] * rsq + rad_params.[1] * rsq * rsq
    mult_by_scalar proj L

let rodrigues_rotate_point_mod (rot: Vector) (x: Vector) =
    let sqtheta = sqnorm rot
    let theta = sqrt sqtheta
    let costheta = cos theta
    let sintheta = sin theta
    let theta_inv = 1. / theta
    let w = mult_by_scalar rot theta_inv
    let w_cross_X = cross w x    
    let tmp = (dot_prod w x) * (1. - costheta)
    let v1 = mult_by_scalar x costheta
    let v2 = mult_by_scalar w_cross_X sintheta 
    add_vec (add_vec v1 v2) (mult_by_scalar w tmp)