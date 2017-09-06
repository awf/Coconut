module bundle

open NUnit.Framework
open Swensen.Unquote
open VecMat

/// cross: Vector cross product a x b
let cross (a: Vec<float>, b:Vec<float>) = Vec(a.[1]*b.[2] - a.[2]*b.[1],
                                              a.[2]*b.[0] - a.[0]*b.[2],
                                              a.[0]*b.[1] - a.[1]*b.[0])

/// cross': Derivative of cross
// Note that the result is in Vec<Vec>, not Mat, in order to be defined even in the absence of Mat
let cross' (a: Vec<float>, b:Vec<float>):Vec<Vec<float>>*Vec<Vec<float>> = 
    Mat([|0.0, -b.[2], b.[1]; b.[2], 0.0, -b.[0]; -b.[1], b.[0], 0.0|]).v,
    Mat([|0.0, a.[2], -a.[1]; -a.[2], 0.0, a.[0]; a.[1], -a.[0], 0.0|]).v


/// cross_matrix: The matrix [a]_x such that [a]_x * b = cross (a, b)
let cross_matrix (n: Vec<float>) = Mat([|    0.0, -n.[2],    n.[1]; 
                                           n.[2],    0.0,   -n.[0]; 
                                          -n.[1],  n.[0],      0.0 |])

/// cross_matrix': Derivative of cross_matrix
let cross_matrix' (n: Vec<float>) =     Vec(Mat([|  0.0,    0.0,    0.0;  
                                                    0.0,    0.0,   -1.0; 
                                                    0.0,    1.0,    0.0  |]),

                                            Mat([|  0.0,    0.0,    1.0; 
                                                    0.0,    0.0,    0.0; 
                                                   -1.0,    0.0,    0.0  |]), 

                                            Mat([|  0.0,   -1.0,    0.0; 
                                                    1.0,    0.0,    0.0; 
                                                    0.0,    0.0,    0.0  |]) )

                                                    
[<Test>]
let test_cross_matrix () =
    let fd = FiniteDiff(1e-5)
    let cf = Comparer(1e-7)
    let a = Vec (1.0,2.0,3.0)
    let b = Vec (-0.3,7.1,5.9)
    test <@ cf.cf (fd.diff cross_matrix a, cross_matrix' a) @>
    test <@ cf.cf (fd.diff (fun x -> cross (a,x)) b, snd (cross' (a,b))) @>
    test <@ cf.cf (fd.diff (fun x -> cross (x,b)) a, fst (cross' (a,b))) @>


/// rodrigues_rotate_point: Multiply rotation defined by exponential map of ROT by point X
let rodrigues_rotate_point (rot: Vec<float>, x: Vec<float>) =
    let sqtheta = Vec_sumsq rot
    if abs(sqtheta) < 1e-5 then
      let theta = sqrt sqtheta                 
      let costheta = cos theta                 
      let sintheta = sin theta                 
      let theta_inv = recip theta              
      let w = Vec_smul (theta_inv, rot)        
      let w_cross_X = cross (w, x)             
      let wx = Vec_dot (w,x)                   
      let tmp = wx * (1. - costheta)           
      let v1 = Vec_smul (costheta, x)          
      let v2 = Vec_smul (sintheta, w_cross_X)  
      let v1plusv2 = Vec_add (v1,v2)           
      let wtmp = Vec_smul (tmp, w)             
      let ret = Vec_add (v1plusv2, wtmp)
      ret         
    else 
      Vec_add (x, cross (rot, x))

/// rodrigues_rotate_point': Derivative of rodrigues_rotate_point
let rodrigues_rotate_point' (rot: Vec<float>, x: Vec<float>) : Vec<Vec<float>> * Vec<Vec<float>> =
    let rot' = Vec_eye 3, Vec_seye 3 0.0
    let x' = Vec_seye 3 0.0, Vec_eye 3
    let sqtheta = Vec_sumsq rot                 in let sqtheta'     = Vec_sumsq' rot, Vec_zeros 3
    if abs(sqtheta) < 1e-5 then
      let theta = sqrt sqtheta                  in let theta'       = GDot.dot(sqtheta, sqrt' sqtheta, sqtheta')
      let costheta = cos theta                  in let costheta'    = GDot.dot(theta, cos' theta, theta')
      let sintheta = sin theta                  in let sintheta'    = GDot.dot(theta, sin' theta, theta')
      let theta_inv = recip theta               in let theta_inv'   = GDot.dot(theta, recip' theta, theta')
      let w = Vec_smul (theta_inv, rot)         in let w'           = GDot.dot((theta_inv, rot), Vec_smul' (theta_inv, rot), (theta_inv', rot'))
      let w_cross_X = cross (w, x)              in let w_cross_X'   = GDot.dot((w, x), cross' (w, x), (w', x'))
      let wx = Vec_dot (w,x)                    in let wx'          = GDot.dot((w,x), Vec_dot' (w,x), (w',x'))
      let lmc = 1.0 - costheta                  in let lmc'         = Vec_smul (-1.0, fst costheta'), snd costheta'
      let tmp = wx * lmc                        in let tmp'         = GDot.dot((wx,lmc), Arith.mul' (wx,lmc), (wx',lmc'))
      let v1 = Vec_smul (costheta, x)           in let v1'          = GDot.dot((costheta, x), Vec_smul' (costheta, x), (costheta', x'))
      let v2 = Vec_smul (sintheta, w_cross_X)   in let v2'          = GDot.dot((sintheta, w_cross_X), Vec_smul' (sintheta, w_cross_X), (sintheta', w_cross_X'))
      let v1plusv2 = Vec_add (v1,v2)            in let v1plusv2'    = GDot.dot((v1,v2), Vec_add' (v1,v2), (v1', v2'))
      let wtmp = Vec_smul (tmp, w)              in let wtmp'        = GDot.dot((tmp,w), Vec_smul' (tmp,w), (tmp', w'))
      let ret = Vec_add (v1plusv2, wtmp)        in let ret'         = GDot.dot((v1plusv2, wtmp), Vec_add' (v1plusv2, wtmp), (v1plusv2', wtmp'))
      ret'
    else 
      let rx = cross (rot, x)  in let rx' =  GDot.dot((rot,x), cross' (rot,x), (rot', x'))
      GDot.dot((x,rx), Vec_add' (x,rx), (x', rx'))

                                 
[<Test>]
let test_rodrigues () =
    let fd = FiniteDiff(1e-5)
    let cf = Comparer(1e-7)
    let a = Vec (1.0,2.0,3.0)
    let atiny = Vec_smul (1e-6, Vec (1.0,2.0,3.0))
    let b = Vec (-0.3,7.1,5.9)
    test <@ cf.cf (fd.diff cross_matrix a, cross_matrix' a) @>
    test <@ cf.cf (fd.diff (fun x -> cross (a,x)) b, snd (cross' (a,b))) @>
    test <@ cf.cf (fd.diff (fun x -> cross (x,b)) a, fst (cross' (a,b))) @>
    test <@ cf.cf (fd.diff (fun x -> rodrigues_rotate_point (x,b)) a, fst (rodrigues_rotate_point' (a,b))) @>
    test <@ cf.cf (fd.diff (fun x -> rodrigues_rotate_point (a,x)) b, snd (rodrigues_rotate_point' (a,b))) @>
    test <@ cf.cf (fd.diff (fun x -> rodrigues_rotate_point (x,b)) atiny, fst (rodrigues_rotate_point' (atiny,b))) @>

/// radial_distort: Distort 2d point using 2-parameter radial distortion model
let radial_distort (rad_params: Vec<R>, proj: Vec<R>):Vec<R> =
    let rsq = Vec_sumsq proj
    let L = 1. + rad_params.[0] * rsq + rad_params.[1] * rsq * rsq
    Vec_smul (L, proj)

/// radial_distort': Derivative of radial_distort
let radial_distort' (k: Vec<R>, proj: Vec<R>):Vec<Vec<R>> * Vec<Vec<R>> =
    let rsq = Vec_sumsq proj            in let rsq' = Vec_sumsq' proj
    let rsqsq = sqr rsq                 in let rsqsq' = GDot.dot(rsq, sqr' rsq, rsq')
    let k0 = k.[0]                      in let k0' =  get' k 0
    let k1 = k.[1]                      in let k1' =  get' k 1
    let L = 1. + k0 * rsq + k1 * rsqsq  in let L' =  Arith.add(Arith.mul (rsq, k0'), Arith.mul (rsqsq, k1')), 
                                                     Arith.add(Arith.mul (k0, rsq'), Arith.mul (k1, rsqsq'))
    let ret = Vec_smul (L, proj) in
    GDot.dot((L, proj), Vec_smul' (L, proj), (L', (Vec_seye k.size 0.0, Vec_seye proj.size 1.0)))

[<Test>]
let test_radial_distort' () =
    let fd = FiniteDiff(1e-5)
    let cf = Comparer(1e-7)
    let k = Vec (0.1,-0.02)
    let b = Vec (-0.3,7.1)
    test <@ cf.cf (fd.diff (fun x -> radial_distort (x,b)) k, fst (radial_distort' (k,b))) @>
    test <@ cf.cf (fd.diff (fun x -> radial_distort (k,x)) b, snd (radial_distort' (k,b))) @>

 (*
type Camera<'T> = {
    rot: Vec<'T>
    origin: Vec<'T>
    radial: Vec<'T>
    focal_length: 'T
    center: Vec<'T>
}
*)

let getfrom  (v:Vec<float>) lo n = Vec(v.v.[lo..lo+n-1])
let getfrom' (v:Vec<float>) lo n = Vec((Vec_eye v.size).v.[lo..lo+n-1])

let get (v:Vec<float>) i = v.[i]
let get' (v:Vec<float>) i = (Vec_eye v.size).[i]

let proj (x:Vec<float>) : Vec<float> =
    assert (x.size = 3)
    let r = recip x.[2]
    Vec([| r * x.[0]; r * x.[1] |])

let proj' (x:Vec<float>) : Vec<Vec<float>> =
    let r = recip x.[2]
    Vec([|Vec([|          r;        0.0 |]);
          Vec([|        0.0;          r |]);
          Vec([| -r*r*x.[0]; -r*r*x.[1] |]) |])

[<Test>]
let test_proj() =
    let fd = FiniteDiff(1e-5)
    let cf = Comparer(1e-7)
    let x = Vec (0.1,-0.02,1.3)
    test <@ cf.cf (fd.diff proj x, proj' x) @>

let project (cam: Vec<float>, x: Vec<float>):Vec<float> =
    (* Should be changed to global constant variables *)
    let N_CAM_PARAMS = 11
    let ROT_IDX = 0
    let CENTER_IDX = 3
    let FOCAL_IDX = 6
    let X0_IDX = 7
    let RAD_IDX = 9
    let rot = getfrom cam ROT_IDX 3           
    let center = getfrom cam CENTER_IDX 3 
    let kappa = getfrom cam RAD_IDX 2 
    let x0 = getfrom cam X0_IDX 2 
    let focal = cam.[FOCAL_IDX] 

    let xc = Vec_sub (x, center)
    let Xcam = rodrigues_rotate_point (rot, xc)
    let distorted = radial_distort (kappa, proj Xcam)
    Vec_add (x0, Vec_smul (focal, distorted))


let project' (cam: Vec<float>, x: Vec<float>):Vec<Vec<float>> * Vec<Vec<float>> =
    (* Should be changed to global constant variables *)
    let N_CAM_PARAMS = 11
    assert (cam.size = N_CAM_PARAMS)
    assert (x.size = 3)
    let ROT_IDX = 0
    let CENTER_IDX = 3
    let FOCAL_IDX = 6
    let X0_IDX = 7
    let RAD_IDX = 9
    
    let x' = ((Mat_zeros 3 11).v, Vec_eye 3)
    let cam' = (Vec_eye 11, (Mat_zeros 11 3).v)
    
    let rot = getfrom cam ROT_IDX 3                          in let rot' = getfrom' cam ROT_IDX 3           
    let center = getfrom cam CENTER_IDX 3                    in let center' = getfrom' cam CENTER_IDX 3 
    let kappa = getfrom cam RAD_IDX 2                        in let kappa' = getfrom' cam RAD_IDX 2 
    let x0 = getfrom cam X0_IDX 2                            in let x0' = getfrom' cam X0_IDX 2 
    let focal = cam.[FOCAL_IDX]                              in let focal' = (fst cam').[FOCAL_IDX] 
    failwith "unimp"
    (*
    let xc = Vec_sub (x, center)                             in let xc = GDot.dot((x, center), Vec_sub' (x, center), (x'cam, center') * (Vec_eye )                          
    let Xcam = rodrigues_rotate_point (rot, xc)              in let Xcam = rodrigues_rotate_point (rot, xc)          
    let distorted = radial_distort (kappa, proj Xcam)        in let distorted = radial_distort (kappa, proj Xcam)    
    Vec_add (x0, Vec_smul (focal, distorted))
      *)

    (*
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
      *)