[<ReflectedDefinition>]
module usecases_ht

open corelang
open linalg
open types
open utils
open cardinality

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
    (vectorRange (Card 0) (n_bones .- (Card 1)))

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
  ) (init) (Card 0) ((length relatives) .- (Card 1))

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
    ) init_positions (Card 0) ((length transforms) .- (Card 1))

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

let test_ht (dum: Vector) =
  let a = [| 1.0; 2.0; 3.0 |]
  vectorPrint a
  let mat1 = 
    [| [| 1.0; 2.0; 3.0; |];
       [| 4.0; 5.0; 6.0; |];
       [| 7.0; 8.0; 9.0; |] |]
  let base_rel = vectorMapToMatrix (fun r -> vectorRange (Card (int r * 4)) (Card (int r * 4 + 3))) (vectorRange (Card 1) (Card 4))
  let q = make_relative a base_rel
  matrixPrint q
  let r = angle_axis_to_rotation_matrix a
  matrixPrint r
  let s = apply_global_transform mat1 mat1
  matrixPrint s
  ()