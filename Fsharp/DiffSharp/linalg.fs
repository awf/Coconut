[<ReflectedDefinition>]
module linalg

open utils

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

let rodrigues_rotate_point (rot: Vector) (x: Vector) =
    let sqtheta = sqnorm rot
    if sqtheta <> 0. then
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
    else 
      add_vec x (cross rot x)

let project (cam: Vector) (x: Vector) =
    (* Should be changed to a global constant variable *)
    let N_CAM_PARAMS = 11
    let ROT_IDX = 0
    let CENTER_IDX = 3
    let FOCAL_IDX = 6
    let X0_IDX = 7
    let RAD_IDX = 9
    let Xcam = rodrigues_rotate_point 
                  cam.[ROT_IDX..(ROT_IDX+2)]  
                  (sub_vec x cam.[CENTER_IDX..(CENTER_IDX+2)])
    let distorted = radial_distort 
                      cam.[RAD_IDX..(RAD_IDX+1)] 
                      (mult_by_scalar Xcam.[0..1] (1./Xcam.[2]))
    add_vec 
        cam.[X0_IDX..(X0_IDX+1)] 
        (mult_by_scalar distorted cam.[FOCAL_IDX])

let compute_reproj_err (cam: Vector) (x: Vector) (w: Number) (feat: Vector) =
    mult_by_scalar (sub_vec (project cam x) feat) w

let compute_zach_weight_error w =
    1. - w*w

let w_err (w:Vector) = 
    Array.map compute_zach_weight_error w 

(*
let reproj_err (cams:Matrix) (X:Matrix) (w:Vector) (obs:Matrix) (feat:Matrix): Matrix =
    let n = cams.Length
    let p = w.Length
    let range = arrayRange 0 (p - 1)
    Array.map (fun i -> compute_reproj_err cams.[int obs.[int i].[0]] X.[int obs.[int i].[1]] w.[int i] feat.[int i]) range
*)

(*
let foo (x: Vector): Vector = 
  Array.map (fun i -> i * 10.0) x
*)

let test1 (dum: Vector) =
  let a = [| 1.0; 2.0; 3.0 |]
  let b = [| 5.0; 6.0; 7.0 |]
  arrayPrint a
  arrayPrint b
(*  arrayPrint (foo b) *)

  let c = cross a b
  arrayPrint c
  let d = mult_by_scalar c 15.0
  arrayPrint d
  let e = add_vec a b
  arrayPrint e
  let f = sub_vec a b
  arrayPrint f
  let g = add_vec3 a b c
  arrayPrint g
  let h = sqnorm a
  numberPrint h
  let i = dot_prod a b
  numberPrint i
  let j = radial_distort a b
  arrayPrint j
  let k = rodrigues_rotate_point a b
  arrayPrint k
  let l = k.[1..2]
  arrayPrint l
  let cam = [|0.; 2.; 4.; 6.; 8.; 10.; 12.; 14.; 16.; 18.; 20.|]
  let m = project cam j 
  arrayPrint m
  ()
