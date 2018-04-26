open System
open System.Diagnostics
open System.IO

//open DiffSharp.AD
//let D_seed (x:float) = D x
//let DD (x:double) = D x

#if MODE_AD
open DiffSharp.AD
let D_seed (x:float) = D x
//let DD (x:double) = D x
#else
#if MODE_R
open DiffSharp.AD.Specialized.Reverse1
#else
#if MODE_F
open DiffSharp.AD.Specialized.Forward1
let D = hand_d.D
let D_seed (x:float) = x
#endif
#endif
#endif


let transpose (mtx : _ [,]) = Array2D.init (mtx.GetLength 1) (mtx.GetLength 0) (fun x y -> mtx.[y,x])

let write_times (fn:string) (tf:float) (tJ:float) =
    let line1 = sprintf "%f %f\n" tf tJ
    let line2 = sprintf "tf tJ"
    let lines = [|line1; line2|]
    File.WriteAllLines(fn,lines)

#if (DO_GMM_FULL || DO_GMM_SPLIT)
let test_gmm fn_in fn_out nruns_f nruns_J replicate_point =
    let alphas, means, icf, x, wishart = gmm.read_gmm_instance (fn_in + ".txt") replicate_point
    
    let obj_stop_watch = Stopwatch.StartNew()
    let err = gmm.gmm_objective alphas means icf x wishart
    for i = 1 to nruns_f-1 do
        gmm.gmm_objective alphas means icf x wishart
    obj_stop_watch.Stop()

    let k = alphas.Length
    let d = means.[0].Length
    let n = x.Length
    
#if DO_GMM_FULL
    let gmm_objective_wrapper_ (parameters:_[]) = gmm.gmm_objective_wrapper d k parameters x wishart
    let grad_gmm_objective = grad' gmm_objective_wrapper_
    let grad_func parameters = grad_gmm_objective parameters
  #if MODE_AD
    let name = "DiffSharp"
  #else
    let name = "DiffSharp_R"
  #endif
#endif
#if DO_GMM_SPLIT
    let gmm_objective_2wrapper_ (parameters:_[]) = gmm.gmm_objective_2wrapper d k n parameters wishart
    let grad_gmm_objective2 = grad' gmm_objective_2wrapper_
    let grad_gmm_objective_split (parameters:_[]) =
        let mutable err, grad = grad_gmm_objective2 parameters
        for i = 0 to n-1 do
            let gmm_objective_1wrapper_ (parameters:_[]) = gmm.gmm_objective_1wrapper d k parameters x.[i]
            let grad_gmm_objective1 = grad' gmm_objective_1wrapper_
            let err_curr, grad_curr = grad_gmm_objective1 parameters
            err <- err + err_curr
            grad <- Array.map2 (+) grad grad_curr
        (err, grad)
    let grad_func parameters = grad_gmm_objective_split parameters
  #if MODE_R
    let name = "DiffSharp_R_split"
  #endif
#endif

    let grad_stop_watch = Stopwatch.StartNew()
    if nruns_J>0 then   
        let parameters = (gmm.vectorize alphas means icf) 
#if MODE_AD
                            |> Array.map D
#endif
        let err2, gradient = (grad_func parameters)
        for i = 1 to nruns_J-1 do
            grad_func parameters
        grad_stop_watch.Stop()
    
        gmm.write_grad (fn_out + "_J_" + name + ".txt") gradient   

    let tf = ((float obj_stop_watch.ElapsedMilliseconds) / 1000.) / (float nruns_f)
    let tJ = ((float grad_stop_watch.ElapsedMilliseconds) / 1000.) / (float nruns_J)
    write_times (fn_out + "_times_" + name + ".txt") tf tJ
#endif

#if DO_BA
// let compute_ba_J (cams:_[][]) (X:_[][]) (w:_[]) (obs:int[][]) (feats:float[][]) =
//     let n = cams.Length
//     let m = X.Length
//     let p = w.Length
// 
//     let compute_reproj_err_J_block (cam:_[]) (X:_[]) (w:_) (feat:float[]) =
//         let compute_reproj_err_wrapper_ parameters = 
//             ba.compute_reproj_err_wrapper parameters feat
//         let err_D, J_D = (jacobian' compute_reproj_err_wrapper_ (ba.vectorize cam X w))
//         let err = Array.map (float) err_D
//         let J = Array2D.map (float) J_D
//         err, J
//     let compute_w_err_d = 
//         diff' ba.compute_zach_weight_error_
// 
//     let reproj_err_val_J = 
//         [|for i=0 to p-1 do 
//             yield compute_reproj_err_J_block cams.[obs.[i].[0]] X.[obs.[i].[1]] w.[i] feats.[i]|]
//     let w_err_val_J = Array.map compute_w_err_d w
//     
//     let reproj_err, reproj_err_d = Array.unzip reproj_err_val_J
//     let w_err, w_err_d = Array.unzip w_err_val_J
//     
//     let J = ba.create_sparse_J m n p obs reproj_err_d w_err_d
// 
//     (reproj_err, w_err), J

let test_ba fn_in fn_out nruns_f nruns_J = 
    let cams_float, X_float, w_float, obs, feat = ba.read_ba_instance fn_in
#if MODE_AD
    let cams = Array.map (Array.map D) cams_float 
    let X = Array.map (Array.map D) X_float 
    let w = Array.map D w_float
#else
    let cams = cams_float
    let X = X_float
    let w = w_float
#endif
    

    let obj_stop_watch = Stopwatch.StartNew()
    let err = ba.ba_objective cams_float X_float w_float obs feat
    for i = 1 to nruns_f do
        ba.ba_objective cams_float X_float w_float obs feat
    obj_stop_watch.Stop()

  #if MODE_AD
    let name = "DiffSharp"
  #else
    let name = "DiffSharp_R"
  #endif

    // let n = cams.Length
    // let m = X.Length
    // let p = obs.Length
    // 
    // printfn "Doing BA"
    // 
    // let jac_stop_watch = Stopwatch.StartNew()
    // if nruns_J>0 then   
    //     let err2, J = compute_ba_J cams X w obs feat
    //     for i = 1 to nruns_J-1 do
    //         compute_ba_J cams X w obs feat
    //     jac_stop_watch.Stop()
    // 
    //     //ba.write_J (fn_out + "_J_" + name + ".txt") gradient   
    //     
    let tf = ((float obj_stop_watch.ElapsedMilliseconds)) / (float nruns_f)
    // let tJ = ((float jac_stop_watch.ElapsedMilliseconds) / 1000.) / (float nruns_J)
    // write_times (fn_out + "_times_" + name + ".txt") tf tJ
    printfn "%d (ms)" (int tf)
#endif

#if DO_HAND
let test_hand model_dir fn_in fn_out nruns_f nruns_J = 
  let param, data, _ = hand.read_hand_instance model_dir (fn_in + ".txt") false
  let param_D, data_D, _ = hand_d.read_hand_instance model_dir (fn_in + ".txt") false
    
#if MODE_AD
  let param_in, data_in = param_D, data_D
#else 
  let param_in, data_in = param, data_D
#endif
    
  let obj_stop_watch = Stopwatch.StartNew()
  let err = hand.hand_objective param data
  for i = 1 to nruns_f-1 do
    hand.hand_objective param data
  obj_stop_watch.Stop()
  
#if MODE_AD
  let name = "DiffSharp"
#else
  let name = "DiffSharp_F"
#endif

  let objective_wrapper (parameters:D[]) = 
    hand_d.hand_objective parameters data_in
  let hand_objective_d = jacobian' objective_wrapper

  let jac_stop_watch = Stopwatch.StartNew()
  if nruns_J>0 then   
    let err2, J = hand_objective_d param_in
    for i = 1 to nruns_J-1 do
      hand_objective_d param_in
    jac_stop_watch.Stop()
    hand_d.write_J (fn_out + "_J_" + name + ".txt") J
        
  let tf = ((float obj_stop_watch.ElapsedMilliseconds) / 1000.) / (float nruns_f)
  let tJ = ((float jac_stop_watch.ElapsedMilliseconds) / 1000.) / (float nruns_J)
  write_times (fn_out + "_times_" + name + ".txt") tf tJ
#endif

#if DO_HAND_COMPLICATED
let compute_J_transposed (param:_[]) (us:_[]) data =
  let objective_wrapper (parameters:D[]) =
    let param = parameters.[0..25]
    let us = parameters.[26..]
    hand_d.hand_objective_complicated param us data
  
  let parameters = (Array.append param us)

  let npts = us.Length / 2
  let Jcols = param.Length + 2
  let seed = [|for i=0 to Jcols-1 do yield Array.create (param.Length+us.Length) (D_seed 0.)|]

  for i=0 to npts-1 do
    seed.[0].[param.Length + 2*i] <- (D_seed 1.)
    seed.[1].[param.Length + 2*i+1] <- (D_seed 1.)

  for i=0 to param.Length-1 do
    seed.[i+2].[i] <- (D_seed 1.)
    
  let err,J0 = jacobianv' objective_wrapper parameters seed.[0]
  let J = array2D [|yield J0; for i=1 to Jcols-1 do yield jacobianv objective_wrapper parameters seed.[i]|]
  
  err, J

let test_hand model_dir fn_in fn_out nruns_f nruns_J = 
  let param, data, us = hand.read_hand_instance model_dir (fn_in + ".txt") true
  let param_D, data_D, us_D = hand_d.read_hand_instance model_dir (fn_in + ".txt") true
    
#if MODE_AD
  let param_in, data_in, us_in = param_D, data_D, us_D
#else 
  let param_in, data_in, us_in = param, data_D, us
#endif
    
  let obj_stop_watch = Stopwatch.StartNew()
  let err = hand.hand_objective_complicated param us data
  for i = 1 to nruns_f-1 do
    hand.hand_objective_complicated param us data
  obj_stop_watch.Stop()
  
#if MODE_AD
  let name = "DiffSharp"
#else
  let name = "DiffSharp_F"
#endif

  let jac_stop_watch = Stopwatch.StartNew()
  if nruns_J>0 then   
    let err2, J_transposed = compute_J_transposed param_in us_in data_in
    for i = 1 to nruns_J-1 do
      compute_J_transposed param_in us_in data_in
    jac_stop_watch.Stop()
    hand_d.write_J (fn_out + "_J_" + name + ".txt") (transpose J_transposed)
        
  let tf = ((float obj_stop_watch.ElapsedMilliseconds) / 1000.) / (float nruns_f)
  let tJ = ((float jac_stop_watch.ElapsedMilliseconds) / 1000.) / (float nruns_J)
  write_times (fn_out + "_times_" + name + ".txt") tf tJ
#endif

let matrix_fill (rows: int) (cols: int) (value: double): double[][] =
    [| for i=1 to rows do 
       yield (
         [| for j=1 to cols do 
            yield value |]
       )
    |]

let vector_fill (rows: int) (value: double): double[] =
    (matrix_fill 1 rows value).[0];

let benchmark_ba () = 
    let cam = [| 0.1; 0.1; 0.1; 0.2; 0.1; 0.3; 1.2; 0.01; 0.03; 0.009; 1.2e-4 |] 
    let X = [| 0.03; 0.11; -0.7 |]
    let N = 1000 * 1000 * 10
    let mutable total = 0.0
    let t = Stopwatch.StartNew()
    for i = 0 to N-1 do
      X.[0] <- 1.0 / (2.0 + (double)i);
      cam.[5] <- 1.0 + (double)i * 1e-6;
      total <- total + ba.sqnorm (ba.project cam X)
    t.Stop()
    printfn "total =%f, time per call = %f ms" total (float t.ElapsedMilliseconds / (float)N)

#if MODE_AD
let benchmark_ba_d () = 
    let cam = [| 0.1; 0.1; 0.1; 0.2; 0.1; 0.3; 1.2; 0.01; 0.03; 0.009; 1.2e-4 |] |> Array.map (D)
    let X = [| 0.03; 0.11; -0.7 |] |> Array.map (D)
    let N = 1000 * 1000 * 10
    let mutable total = 0.0
    let t = Stopwatch.StartNew()
    for i = 0 to N-1 do
      X.[0] <- D (1.0 / (2.0 + (double)i));
      cam.[5] <- D (1.0 + (double)i * 1e-6);
      let res = (ba.sqnorm (ba.project_ cam X))
      total <- total + (float res.T)
    t.Stop()
    printfn "total =%f, time per call = %f ms" total (float t.ElapsedMilliseconds / (float)N)
#endif

let benchmark_gmm () = 
    let tri n = n * (n+1) / 2
    let rng = 42
    let rand = System.Random(rng)
    let dist (f: int) = rand.NextDouble()
    let n = 100;
    let d = 2;
    let K = 5;
    let td = tri d
    let alphas = vector_fill K 0.
    let means = matrix_fill K d 0.
    let qs = matrix_fill K d 0.
    let ls = matrix_fill K td 0.
    for k = 0 to K - 1 do 
      alphas.[k] <- dist(rng)
      for j = 0 to d - 1 do
        means.[k].[j] <- dist(rng) - 0.5
        qs.[k].[j] <- 10.0*dist(rng) - 5.0
      for j = 0 to ls.[k].Length - 1 do
        ls.[k].[j] <- dist(rng) - 0.5
    let xs = matrix_fill n d 0.0
    for i = 0 to n - 1 do 
      for j = 0 to d - 1 do
        xs.[i].[j] <- dist(rng)
    let N = 10000
    let mutable total = 0.0
    let t = Stopwatch.StartNew()
    let wishart_m = 2.0
    for i = 0 to N - 1 do
      alphas.[0] <- alphas.[0] + 1.
      let wishart_gamma = 1.0 / (1.0 + (double)i)
      total <- total + gmm.gmm_objective2 xs alphas means qs ls wishart_gamma wishart_m
//      total <- total + gmm_opt.gmm_objective xs alphas means qs ls wishart_gamma wishart_m
      //total <- total + usecases_gmm.gmm_objective xs alphas means qs ls wishart_gamma wishart_m
    t.Stop()
    printfn "total =%f, time per call = %f ms" total (float t.ElapsedMilliseconds / (float)N)

let benchmark_ht () = 
    let rng = 42
    let rand = System.Random(rng)
    let dist (f: int) = rand.NextDouble()
    let angles = vector_fill 3 0.
    for i = 0 to 2 do
        angles.[i] <- dist rng
    let X = [| 0.03; 0.11; -0.7 |]
    let N = 1000 * 1000 * 10
    let mutable total = 0.0
    let t = Stopwatch.StartNew()
    for i = 0 to N-1 do
      angles.[0] <- angles.[0] - (double)N;
      let verts = hand.angle_axis_to_rotation_matrix2 angles
      total <- total + ba.sqnorm (verts.[0]) 
    t.Stop()
    printfn "total =%f, time per call = %f ms" total (float t.ElapsedMilliseconds / (float)N)

let benchmark_micro (N: int) = 
    let rng = 42
    let rand = System.Random(rng)
    let dist (f: int) = rand.NextDouble()
    let DIM = 
#if ADD3
      100
#else
#if CROSS
      3
#else 
      1
#endif 
#endif 
    let vec1 = vector_fill DIM 0.
    let vec2 = vector_fill DIM 0.
    let vec3 = vector_fill DIM 0.

    for k = 0 to DIM - 1 do 
      vec1.[k] <- dist(rng)
      vec2.[k] <- dist(rng)
      vec3.[k] <- dist(rng)

    let mutable total = 0.0
    let t = Stopwatch.StartNew()
    for i = 0 to N - 1 do
      vec1.[0] <- 1.0 / (2.0 + vec1.[0])
      vec2.[1] <- 1.0 / (2.0 + vec2.[1])
#if ADD3
      total <- total + Array.sum (Array.map2 (+) (Array.map2 (+) vec1 vec2) vec3)
#else
#if CROSS
      total <- total + Array.sum (linalg.cross vec1 vec2)
#else 
      
#endif
#endif
    t.Stop()
    printfn "total =%f, time per call = %f ms" total (float t.ElapsedMilliseconds / (float)N)

[<EntryPoint>]
let main argv = 
    // let dir_in = argv.[0]
    // let dir_out = argv.[1]
    // let fn = argv.[2]
    // let nruns_f = (Int32.Parse argv.[3])
    // let nruns_J = (Int32.Parse argv.[4])
    // let replicate_point = 
    //     (argv.Length >= 6) && (argv.[5].CompareTo("-rep") = 0)
    //benchmark_ba ()
    benchmark_gmm ()
    //benchmark_micro (Int32.Parse argv.[0])
    //benchmark_ht ()
    //benchmark_ba_d ()
#if DO_GMM_FULL || DO_GMM_SPLIT
    test_gmm (dir_in + fn) (dir_out + fn) nruns_f nruns_J replicate_point
#endif
#if DO_BA
    // test_ba (dir_in + fn) (dir_out + fn) nruns_f nruns_J
    test_ba (argv.[0]) "" 1 0
#endif
#if DO_HAND || DO_HAND_COMPLICATED
    test_hand (dir_in + "hand_instances\\simple_big\\model\\") (dir_in + fn) (dir_out + fn) nruns_f nruns_J
#endif
    0
