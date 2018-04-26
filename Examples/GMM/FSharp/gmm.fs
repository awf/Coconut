﻿module gmm

open System
open System.Diagnostics
open System.IO
open MathNet.Numerics

#if MODE_AD
open DiffSharp.AD
#else
open DiffSharp.AD.Specialized.Reverse1
#endif

type Wishart = {gamma:Double; m:Int32}

////// IO //////

let read_gmm_instance (fn:string) replicate_point =
    let read_in_elements (fn:string) =
        let string_lines = File.ReadLines(fn)
        let separators = [|' '|]
        [| for line in string_lines do yield line.Split separators |] 
            |> Array.map (Array.filter (fun x -> x.Length > 0))

    let parse_double (arr:string[][]) =
        [|for elem in arr do yield (Array.map Double.Parse elem) |]

    let data = read_in_elements fn

    let d = Int32.Parse data.[0].[0]
    let k = Int32.Parse data.[0].[1]
    let n = Int32.Parse data.[0].[2]
    
    let mutable offset = 1
    let alphas_nested = parse_double data.[offset..(offset+k-1)]
    let alphas = [|for elem in alphas_nested do yield elem.[0]|]

    offset <- offset + k
    let means = parse_double data.[offset..(offset+k-1)]

    offset <- offset + k
    let icf_sz = d*(d + 1) / 2
    let icf = parse_double data.[offset..(offset+k-1)]

    offset <- offset + k
    let x =
        if replicate_point then
            let x_ = parse_double data.[offset..offset]
            [|for i=1 to n do yield x_.[0]|]
        else
            parse_double data.[offset..(offset+n-1)]
          
    offset <- 
        if replicate_point then
            offset + 1
        else
            offset + n
    
    let gamma = Double.Parse data.[offset].[0]
    let m = Int32.Parse data.[offset].[1]
    let wishart = {gamma=gamma; m=m}
   
    alphas, means, icf, x, wishart

#if MODE_AD
let write_grad (fn:string) (gradient:D[]) =
#else
let write_grad (fn:string) (gradient:float[]) =
#endif
    let line1 = sprintf "1 %i\n" gradient.Length
    let mutable line2 = ""
    for elem in gradient do
        line2 <- line2 + (sprintf "%f " (float elem))
    let lines = [|line1; line2|]
    File.WriteAllLines(fn,lines)

////// Objective //////

let inline logsumexp (arr:_[]) =
    let mx = Array.max arr
    let semx = Array.map (fun x -> exp(x-mx)) arr |> Array.sum
    (log semx) + mx

let log_wishart_prior p (wishart:Wishart) (Qdiags:_[][]) (sum_qs:_[]) (icf:_[][]) =
    //let log_gamma_distrib a p =
        //log (Math.Pow(Math.PI,(0.25*(float (p*(p-1)))))) + 
            //([for j = 1 to p do yield SpecialFunctions.GammaLn (a + 0.5*(1. - (float j)))] |> List.sum)
    let square x = x*x
    let n = p + wishart.m + 1
    let k = icf.Length
    //let C = (float (n*p))*((log wishart.gamma) - 0.5*(log 2.)) - (log_gamma_distrib (0.5*(float n)) p)
    let mutable out = 0.
    for ik = 0 to k-1 do
        let frobenius1 = Qdiags.[ik] 
                            |> Array.map square
                            |> Array.sum
        let frobenius2 = icf.[ik].[p..]
                            |> Array.map square
                            |> Array.sum
//        out <- out + 0.5*wishart.gamma*wishart.gamma*(frobenius1+frobenius2) - (float wishart.m)*sum_qs.[ik]
        out <- out + 0.5*(frobenius1+frobenius2)
    out// - (float k)*C
        
let gmm_objective (alphas:float[]) (means:float[][]) (icf:float[][]) (x:float[][]) (wishart:Wishart) =
    let k = alphas.Length
    let d = means.[0].Length
    let n = x.Length

//    let CONSTANT = 1. / (pown (sqrt (2. * Math.PI)) d)
    let CONSTANT = 1.
    let Qdiags = [|for curr_icf in icf do yield (Array.map exp curr_icf.[..(d-1)])|]
    let sum_qs = [|for curr_icf in icf do yield (Array.sum curr_icf.[..(d-1)])|]
    
    let Q_times_x (Qdiag:float[]) (curr_icf:float[]) (curr_x:float[]) =
        let mutable res = Array.map2 (*) Qdiag curr_x
        let mutable curr_icf_idx = d
        for i = 0 to d-1 do
            for j = i+1 to d-1 do
                res.[j] <- res.[j] + curr_icf.[curr_icf_idx] * curr_x.[i]
                curr_icf_idx <- curr_icf_idx + 1
        res

    let main_term (curr_x:float[]) ik =
        let xcentered = Array.map2 (-) curr_x means.[ik]
        let sqsum_mahal = (Q_times_x Qdiags.[ik] icf.[ik] xcentered)
                            |> Array.map (fun x -> x*x)
                            |> Array.sum
        -0.5*sqsum_mahal
    
    let mutable slse = 0. 
    for curr_x in x do
        let tmp = Array.map2 (+) (Array.map2 (+) alphas sum_qs) [| for i = 0 to k-1 do yield (main_term curr_x i)|]
        slse <- slse + (logsumexp tmp)

    slse + (float n) * ((log CONSTANT) - (logsumexp alphas)) + (log_wishart_prior d wishart Qdiags sum_qs icf)
    
/////// Derivative extras ////////
let log_wishart_prior_ p (wishart:Wishart) (Qdiags:D[][]) (sum_qs:D[]) (icf:D[][]) =
    let log_gamma_distrib a p =
        log (Math.Pow(Math.PI,(0.25*(float (p*(p-1)))))) + 
            ([for j = 1 to p do yield SpecialFunctions.GammaLn (a + 0.5*(1. - (float j)))] |> List.sum)
    let square x = x*x
    let n = p + wishart.m + 1
    let k = icf.Length
    let C = (float (n*p))*((log wishart.gamma) - 0.5*(log 2.)) - (log_gamma_distrib (0.5*(float n)) p)

    let main_term ik =
        let frobenius1 = Qdiags.[ik] 
                            |> Array.map square
                            |> Array.sum
        let frobenius2 = icf.[ik].[p..]
                            |> Array.map square
                            |> Array.sum
        0.5*wishart.gamma*wishart.gamma*(frobenius1+frobenius2) - (float wishart.m)*sum_qs.[ik]

    let out = [for ik = 0 to k-1 do yield (main_term ik)] |> List.sum
    out - (float k)*C

let vectorize alphas means icf =
    Array.append (Array.append alphas [|for mean in means do for elem in mean do yield elem|])
            [|for curr_icf in icf do for elem in curr_icf do yield elem|]

let reshape inner_dim outer_dim (arr:_[]) =
    [|for i = 0 to outer_dim-1 do yield arr.[(i*inner_dim)..((i+1)*inner_dim-1)]|]

#if DO_GMM_FULL
let gmm_objective_ (alphas:D[]) (means:D[][]) (icf:D[][]) (x:float[][]) (wishart:Wishart)  =
    let k = alphas.Length
    let d = means.[0].Length
    let n = x.Length

    let CONSTANT = 1. / (pown (sqrt (2. * Math.PI)) d)
    let Qdiags = [|for curr_icf in icf do yield (Array.map exp curr_icf.[..(d-1)])|]
    let sum_qs = [|for curr_icf in icf do yield (Array.sum curr_icf.[..(d-1)])|]
    
    let Q_times_x (Qdiag:D[]) (curr_icf:D[]) (curr_x:D[]) =
        let mutable res = Array.map2 (*) Qdiag curr_x
        let mutable curr_icf_idx = d
        for i = 0 to d-1 do
            for j = i+1 to d-1 do
                res.[j] <- res.[j] + curr_icf.[curr_icf_idx] * curr_x.[i]
                curr_icf_idx <- curr_icf_idx + 1
        res

    let main_term (curr_x:float[]) ik =
        let xcentered = Array.map2 (-) curr_x means.[ik]
        let sqsum_mahal = (Q_times_x Qdiags.[ik] icf.[ik] xcentered)
                            |> Array.map (fun x -> x*x)
                            |> Array.sum
        -0.5*sqsum_mahal
        
    let slse = [for curr_x in x do 
                    yield (logsumexp 
                            (Array.map3 (fun x y z -> x+y+z) 
                                alphas sum_qs [| for i = 0 to k-1 do yield (main_term curr_x i)|]))
                    ] 
                    |> List.sum

    slse + (float n) * ((log CONSTANT) - (logsumexp alphas)) + (log_wishart_prior_ d wishart Qdiags sum_qs icf)

let gmm_objective_wrapper d k (parameters:_[]) (x:float[][]) (wishart:Wishart) =
    let means_off = k
    let icf_sz = d*(d + 1) / 2
    let icf_off = means_off + d*k
    let means = (reshape d k parameters.[means_off..(means_off+d*k-1)])
    let icf = (reshape icf_sz k parameters.[icf_off..(icf_off+icf_sz*k-1)])
    gmm_objective_ parameters.[..(k-1)] means icf x wishart
#endif

#if DO_GMM_SPLIT
/////// Derivative extras extras - fixing stack overflow ////////
let gmm_objective_1 (alphas:D[]) (means:D[][]) (icf:D[][]) (x:float[])  =
    let k = alphas.Length
    let d = means.[0].Length
    let n = x.Length
    
    let Q_times_x (curr_icf:_[]) (curr_x:_[]) =
        let mutable res = [|for i = 0 to d-1 do yield (exp(curr_icf.[i]) * curr_x.[i]) |]
        let mutable curr_icf_idx = d
        for i = 0 to d-1 do
            for j = i+1 to d-1 do
                res.[j] <- res.[j] + curr_icf.[curr_icf_idx] * curr_x.[i]
                curr_icf_idx <- curr_icf_idx + 1
        res

    let main_term (curr_x:float[]) ik =
        let xcentered = Array.map2 (-) curr_x means.[ik]
        let mahal = Q_times_x icf.[ik] xcentered
        let sqsum_mahal = Array.sum (Array.map (fun x -> x*x) mahal)
        let sumlog_Ldiag = Array.sum icf.[ik].[..(d-1)]
        alphas.[ik]  + sumlog_Ldiag - 0.5*sqsum_mahal

    logsumexp [| for i = 0 to k-1 do yield (main_term x i)|]
    
let gmm_objective_2 d n (alphas:D[]) (icf:D[][]) (wishart:Wishart)  =
    let CONSTANT = 1. / (pown (sqrt (2. * Math.PI)) d)
    let Qdiags = [|for curr_icf in icf do yield (Array.map exp curr_icf.[..(d-1)])|]
    let sum_qs = [|for curr_icf in icf do yield (Array.sum curr_icf.[..(d-1)])|]
    (float n) * ((log CONSTANT) - (logsumexp alphas)) + (log_wishart_prior_ d wishart Qdiags sum_qs icf)
    
let gmm_objective_1wrapper d k (parameters:_[]) (x:float[]) =
    let means_off = k
    let icf_sz = d*(d + 1) / 2
    let icf_off = means_off + d*k
    gmm_objective_1 parameters.[..(k-1)] (reshape d k parameters.[means_off..(means_off+d*k-1)])
                    (reshape icf_sz k parameters.[icf_off..(icf_off+icf_sz*k-1)]) x

let gmm_objective_2wrapper d k n (parameters:_[]) (wishart:Wishart) =
    let means_off = k
    let icf_sz = d*(d + 1) / 2
    let icf_off = means_off + d*k
    gmm_objective_2 d n parameters.[..(k-1)] (reshape icf_sz k parameters.[icf_off..(icf_off+icf_sz*k-1)]) wishart
#endif

open corelang

let inline gmm_objective2 (x:Matrix) (alphas:Vector) (means:Matrix) (qs:Matrix) (ls:Matrix) (wishart_gamma:Number) (wishart_m:Number) =
    let wishart = {gamma = wishart_gamma; m = (int)wishart_m}
    gmm_objective alphas means ls x wishart