[<ReflectedDefinition>]
module usecases

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
      add_vec (add_vec v1 v2) (mult_by_scalar w tmp)
    else 
      add_vec x (cross rot x)

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
    vectorMap compute_zach_weight_error w 

let reproj_err (cams:Matrix) (x:Matrix) (w:Vector) (obs:Matrix) (feat:Matrix): Matrix =
    let n = length cams
    let p = length w
    let range = vectorRange (Card 0) (subCard p  (Card 1))
    vectorMapToMatrix (fun i -> compute_reproj_err cams.[int obs.[int i].[0]] x.[int obs.[int i].[1]] w.[int i] feat.[int i]) range

let run_ba_from_file (fn: string) = 
    let nmp = vectorRead fn 0
    let n = Card (int nmp.[0])
    let m = Card (int nmp.[1])
    let p = Card (int nmp.[2])
    let oneCard = Card 1
    let one_cam = vectorRead fn 1
    let cam = vectorMapToMatrix (fun x -> one_cam)  (vectorRange oneCard n)
    let one_x = vectorRead fn 2
    let x = vectorMapToMatrix (fun x -> one_x)  (vectorRange oneCard m)
    let one_w = numberRead fn 3
    let w = vectorMap (fun x -> one_w)  (vectorRange oneCard p)
    let one_feat = vectorRead fn 4
    let feat = vectorMapToMatrix (fun x -> one_feat)  (vectorRange oneCard p)
    let obs = vectorMapToMatrix (fun x -> [| double ((int x) % (cardToInt n)); double ((int x) % (cardToInt m)) |] )  (vectorRange (Card 0) (subCard p oneCard))
    let t = tic()
    let res = reproj_err cam x w obs feat
    toc(t)
    res

let inline logsumexp (arr: Vector) =
    let mx = arrayMax arr
    let semx = arraySum (vectorMap (fun x -> exp(x-mx)) arr)
    (log semx) + mx

let inline log_gamma_distrib (a: Number) (p: Number) =
  log (System.Math.Pow(System.Math.PI,(0.25*(p*(p-1.0))))) + 
    arraySum (vectorMap (fun j -> 
        // TODO use an appropriate GammaLn implementation
        //MathNet.Numerics.SpecialFunctions.GammaLn (a + 0.5*(1. - (float j)))
        a + 0.5*(1. - (float j))
      ) 
      (vectorRange (Card 1) (Card (int p))))

let inline new_matrix_test (dum: Vector): Matrix = 
  let res = [| [| 0.0; 0.0; 0.0 |] |]
  res

(** Hand Tracking **)

let inline to_pose_params (theta: Vector) (n_bones: Cardinality): Matrix =
  let row1 = theta.[0..2]
  let row2 = [| 1.0; 1.0; 1.0|]
  let row3 = theta.[3..5]
  let zeroRow = [| 0.0; 0.0; 0.0 |]
  let pose_params = [| row1; row2; row3; zeroRow; zeroRow |]
  (* TODO rewrite using fold *) 
  let i1 = 5
  let finger1 = 
    [| [| theta.[i1]; theta.[i1+1]; 0.0 |] ; 
       [| theta.[i1+2]; 0.0; 0.0 |] ;
       [| theta.[i1+3]; 0.0; 0.0 |] ;
       [| 0.0; 0.0; 0.0 |] |]
  let i2 = i1 + 4
  let finger2 = 
    [| [| theta.[i2]; theta.[i2+1]; 0.0 |] ; 
       [| theta.[i2+2]; 0.0; 0.0 |] ;
       [| theta.[i2+3]; 0.0; 0.0 |] ;
       [| 0.0; 0.0; 0.0 |] |]
  let i3 = i2 + 4
  let finger3 = 
    [| [| theta.[i3]; theta.[i3+1]; 0.0 |] ; 
       [| theta.[i3+2]; 0.0; 0.0 |] ;
       [| theta.[i3+3]; 0.0; 0.0 |] ;
       [| 0.0; 0.0; 0.0 |] |]
  let i4 = i3 + 4
  let finger4 = 
    [| [| theta.[i4]; theta.[i4+1]; 0.0 |] ; 
       [| theta.[i4+2]; 0.0; 0.0 |] ;
       [| theta.[i4+3]; 0.0; 0.0 |] ;
       [| 0.0; 0.0; 0.0 |] |]
  let i5 = i4 + 4
  let finger5 = 
    [| [| theta.[i5]; theta.[i5+1]; 0.0 |] ; 
       [| theta.[i5+2]; 0.0; 0.0 |] ;
       [| theta.[i5+3]; 0.0; 0.0 |] ;
       [| 0.0; 0.0; 0.0 |] |]

  matrixConcat pose_params 
    (matrixConcat finger1 
      (matrixConcat finger2 
        (matrixConcat finger3 
          (matrixConcat finger4 finger5))))

let euler_angles_to_rotation_matrix (xzy: Vector): Matrix =
  let tx = xzy.[0]
  let ty = xzy.[2]
  let tz = xzy.[1]
  let Rx = [| [|1.; 0.; 0.|]; [|0.; cos(tx); -sin(tx)|]; [|0.; sin(tx); cos(tx)|] |]
  let Ry = [| [|cos(ty); 0.; sin(ty)|]; [|0.; 1.; 0.|]; [|-sin(ty); 0.; cos(ty)|] |]
  let Rz = [| [|cos(tz); -sin(tz); 0.|]; [|sin(tz); cos(tz); 0.|]; [|0.; 0.; 1.|] |]
  matrixMult Rz (matrixMult Ry Rx)

[<DontInline>]
let make_relative (pose_params: Vector) (base_relative: Matrix): Matrix =
  let R = euler_angles_to_rotation_matrix pose_params
  let r1 = [| [| 0. |]; [| 0. |]; [| 0. |] |]
  let r2 = [| [| 0.; 0.; 0.; 1.0|] |]
  let T = 
    matrixConcat (matrixConcatCol R 
                    (r1)) 
                 (r2)
  matrixMult base_relative T

let get_posed_relatives (n_bones: Cardinality) (pose_params: Matrix) (base_relatives: Matrix[]): Matrix[] =
  let offset = 3
  vectorMapToMatrix3D (fun i_bone -> 
     make_relative pose_params.[(int i_bone)+offset] base_relatives.[int i_bone]
    ) 
    (vectorRange (Card 0) (subCard n_bones (Card 1)))

let angle_axis_to_rotation_matrix (angle_axis: Vector): Matrix =
  let n = sqrt(sqnorm angle_axis)
  if n < 0.0001 then
    [| [| 1.; 0.; 0. |];
       [| 0.; 1.; 0. |];
       [| 0.; 0.; 1. |]; |]
  else
    let x = angle_axis.[0] / n
    let y = angle_axis.[1] / n
    let z = angle_axis.[2] / n

    let s = sin n
    let c = cos n
    
    [| [| x*x + (1. - x*x)*c; x*y*(1. - c) - z*s; x*z*(1. - c) + y*s |]; 
       [| x*y*(1. - c) + z*s; y*y + (1. - y*y)*c; y*z*(1. - c) - x*s |];
       [| x*z*(1. - c) - y*s; z*y*(1. - c) + x*s; z*z + (1. - z*z)*c |] |]

let relatives_to_absolutes (relatives: Matrix[]) (parents: Vector): Matrix[] =
  let init = [| [| [| |] |] |]
  iterateMatrix3D (fun acc i ->
    if parents.[i] = -1.0 then 
      (* Revealed a bug in ANF convertor and let lifter. Inlining the next let binding makes the code generator crash. *)
      let newMatrix = [| relatives.[i] |]
      matrix3DConcat acc newMatrix
    else 
      (* Revealed a bug in ANF convertor and let lifter. Inlining the next let binding makes the code generator crash. *)
      let newMatrix = [| matrixMult acc.[int parents.[i]] relatives.[i] |]
      matrix3DConcat acc newMatrix
  ) (init) (Card 0) (subCard (length relatives) (Card 1))

let apply_global_transform (pose_params: Matrix) (positions: Matrix) = 
  let R = angle_axis_to_rotation_matrix pose_params.[0]
  let scale = pose_params.[1] // 1 row vector
  let R1 = matrixMap (fun row -> mult_vec_elementwise row scale) R 
  
  let T = matrixConcatCol R1 (matrixTranspose ([| pose_params.[2] |]))
  let ones = vectorMap (fun x -> 1.) (vectorRange (Card 1) (length positions.[0]))
  let positions_homog = matrixConcat positions ([| ones |])
  matrixMult T positions_homog

let get_skinned_vertex_positions (is_mirrored: Index) (n_bones: Cardinality) (pose_params: Matrix) (base_relatives: Matrix[]) (parents: Vector)
     (inverse_base_absolutes: Matrix[]) (base_positions: Matrix) (weights: Matrix) =
  let relatives = get_posed_relatives n_bones pose_params base_relatives
  let absolutes = relatives_to_absolutes relatives parents
  
  let transforms = matrix3DMap2 (matrixMult) absolutes inverse_base_absolutes
  
  let n_verts = length base_positions.[0]
  let init_positions = matrixFill (Card 3) n_verts 0.

  let positions = 
    iterateMatrix (fun acc i_transform ->
      let curr_positions = matrixMult transforms.[i_transform].[0..2] base_positions
      let w = matrixFillFromVector (length base_positions) weights.[i_transform]
      matrixAdd acc (matrixMultElementwise curr_positions w)
    ) init_positions (Card 0) (subCard (length transforms) (Card 1))

  let mirrored_positions =
    if(is_mirrored = 1) then 
      let mirror_matrix = 
        [| [| -1.; 0.; 0. |];
           [| 0.; 1.; 0.  |];
           [| 0.; 0.; 1.  |] |]
      matrixMult mirror_matrix positions
    else 
      positions

  apply_global_transform pose_params mirrored_positions

let hand_objective (is_mirrored: Index) (param: Vector) (correspondences: Vector) (points: Matrix)
      (n_bones: Cardinality) (base_relatives: Matrix[]) (parents: Vector)
      (inverse_base_absolutes: Matrix[]) (base_positions: Matrix) (weights: Matrix): Vector =
  let pose_params = to_pose_params param n_bones
  
  let vertex_positions = 
    get_skinned_vertex_positions is_mirrored n_bones pose_params base_relatives parents
      inverse_base_absolutes base_positions weights
  
  let n_corr = correspondences.Length
  let dims = 3
  let err = 
    vectorMap (fun i ->
      let ind = int i
      let r = ind / n_corr
      let c = ind % n_corr
      points.[r].[c] - vertex_positions.[r].[int correspondences.[c]]
    ) (vectorRange (Card 0) (Card (dims * n_corr - 1))) // TODO violates fixed size behaviour of cardinalities
  err

(** Testing **)

let test1 (dum: Vector) =
  let a = [| 1.0; 2.0; 3.0 |]
  let b = [| 5.0; 6.0; 7.0 |]
  vectorPrint a
  vectorPrint b
(*  vectorPrint (foo b) *)

  let c = cross a b
  vectorPrint c
  let d = mult_by_scalar c 15.0
  vectorPrint d
  let e = add_vec a b
  vectorPrint e
  let f = sub_vec a b
  vectorPrint f
  let g = add_vec3 a b c
  vectorPrint g
  let h = sqnorm a
  numberPrint h
  let i = dot_prod a b
  numberPrint i
  let j = radial_distort a b
  vectorPrint j
  let k = rodrigues_rotate_point a b
  vectorPrint k
  let l = k.[1..2]
  vectorPrint l
  let cam = [|0.; 2.; 4.; 6.; 8.; 10.; 12.; 14.; 16.; 18.; 20.|]
  let m = project cam j 
  vectorPrint m

  let mat1 = 
    [| [| 1.0; 2.0; 3.0; |];
       [| 4.0; 5.0; 6.0; |];
       [| 7.0; 8.0; 9.0; |] |]
  let n = matrixMult mat1 mat1
  matrixPrint n
  let o = matrixTranspose n
  matrixPrint o
  let p = matrixConcatCol mat1 mat1
  matrixPrint p
  let base_rel = vectorMapToMatrix (fun r -> vectorRange (Card (int r * 4)) (Card (int r * 4 + 3))) (vectorRange (Card 1) (Card 4))
  let q = make_relative a base_rel
  matrixPrint q
  let r = angle_axis_to_rotation_matrix a
  matrixPrint r
  let s = apply_global_transform mat1 mat1
  matrixPrint s
  let t = matrixAdd mat1 mat1
  matrixPrint t
  let u = matrixFillFromVector (Card 5) a
  matrixPrint u
  ()