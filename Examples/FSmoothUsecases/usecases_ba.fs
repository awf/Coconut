[<ReflectedDefinition>]
module usecases_ba

open corelang
open linalg
open types
open utils
open cardinality

(** Bundle Adjustment **)

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
      vectorAdd (vectorAdd v1 v2) (mult_by_scalar w tmp)
    else 
      vectorAdd x (cross rot x)

let project (cam: Vector) (x: Vector) =
    (* Should be changed to global constant variables *)
    let N_CAM_PARAMS = 11
    let ROT_IDX = 0
    let CENTER_IDX = 3
    let FOCAL_IDX = 6
    let X0_IDX = 7
    let RAD_IDX = 9
    let Xcam = rodrigues_rotate_point 
                  cam.[ROT_IDX..(ROT_IDX+2)]  
                  (vectorSub x cam.[CENTER_IDX..(CENTER_IDX+2)])
    let distorted = radial_distort 
                      cam.[RAD_IDX..(RAD_IDX+1)] 
                      (mult_by_scalar Xcam.[0..1] (1./Xcam.[2]))
    vectorAdd 
        cam.[X0_IDX..(X0_IDX+1)] 
        (mult_by_scalar distorted cam.[FOCAL_IDX])

let compute_reproj_err (cam: Vector) (x: Vector) (w: Number) (feat: Vector) =
    mult_by_scalar (vectorSub (project cam x) feat) w

let compute_zach_weight_error w =
    1. - w*w

let w_err (w:Vector) = 
    vectorMap compute_zach_weight_error w 

let reproj_err (cams:Matrix) (x:Matrix) (w:Vector) (obs:Matrix) (feat:Matrix): Matrix =
    let n = length cams
    let p = length w
    let range = vectorRange (Card 0) (p .- (Card 1))
    vectorMapToMatrix (fun i -> compute_reproj_err cams.[int obs.[int i].[0]] x.[int obs.[int i].[1]] w.[int i] feat.[int i]) range

let run_ba_from_file (fn: string) (n: Cardinality) (m: Cardinality) (p: Cardinality)= 
    let oneCard = Card 1
    let one_cam = vectorRead fn 1 (Card 11)
    let cam = build n (fun x -> one_cam)
    let one_x = vectorRead fn 2 (Card 3)
    let x = build m (fun x -> one_x)
    let one_w = numberRead fn 3
    let w = vectorMap (fun x -> one_w)  (vectorRange oneCard p)
    let one_feat = vectorRead fn 4 (Card 2)
    let feat = vectorMapToMatrix (fun x -> one_feat)  (vectorRange oneCard p)
    let obs = build p (fun x -> [| double ((int x) % (cardToInt n)); double ((int x) % (cardToInt m)) |] )
    let t = tic()
    let range = vectorRange (Card 1) (Card 10)
    let tmp = vectorFoldNumber (fun acc cur -> let x = reproj_err cam x w obs feat in acc) 0.0 range
    toc t "BA"
    ()


(** Testing **)

let test_ba (dum: Vector) =
  let a = [| 1.0; 2.0; 3.0 |]
  let b = [| 5.0; 6.0; 7.0 |]
  vectorPrint a
  vectorPrint b
  let j = radial_distort a b
  vectorPrint j
  let k = rodrigues_rotate_point a b
  vectorPrint k
  let l = k.[1..2]
  vectorPrint l
  let cam = [|0.; 2.; 4.; 6.; 8.; 10.; 12.; 14.; 16.; 18.; 20.|]
  let m = project cam j 
  vectorPrint m
  ()
