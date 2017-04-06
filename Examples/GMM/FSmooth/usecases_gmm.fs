[<ReflectedDefinition>]
module usecases_gmm

(* 
 * GMM Use Case from https://github.com/awf/autodiff/blob/master/Documents/AD%202016%20extended.pdf
 *)

open corelang
open linalg
open types
open utils
open cardinality

let inline logsumexp (arr: Vector) =
    let mx = vectorMax arr
    let semx = vectorSum (vectorMap (fun x -> exp(x-mx)) arr)
    (log semx) + mx

// nth triangular number (0 1 3 6)
// tri 0 = 0
// tri 1 = 1
// tri 2 = 3
// tri 3 = 6
let tri n = n * (n+1) / 2

// GMM: Gaussian Mixture Model
// See eqn 2 of https://github.com/awf/autodiff/blob/master/Documents/AD%202016%20extended.pdf
// alphas
//   vector of logs of mixture weights (unnormalized), so
//   weights = exp(alphas)/sum(exp(alphas))
// means  k x d 
//   Matrix of component means
// qs     k x d 
//   Matrix of logs of diagonals of component inverse covariance matrices
// ls     k x d*(d-1)/2
//   Matrix of vectorized lower triangles of component inverse covariance matrices

// Assemble lower-triangular matrix from log-diagonal and lower triangle and multiply by vector v
// [ exp(q0)        0        0        0 ]
// [      l0  exp(q2)        0        0 ]
// [      l1       l2  exp(q3)        0 ]
// [      l3       l4       l5  exp(q4) ]
let Qtimesv (q : Vector) (l : Vector) (v : Vector) =
    build (length v) (fun i ->
      // Not a valid F~ operation.
      // let li = vectorSlice (Card i) (tri (i-1)) l
      // let vi = vectorSlice (Card i) 0 v
      // vectorSum (li .* vi) + exp(q.[i])*v.[i]
      let tis = tri (i - 1)
      let sum = 
        foldOnRange (fun acc idx -> 
          let j = idx - tis
          let isInRange = j >= 0 && j < i
          if (isInRange) then 
            acc + l.[idx] * v.[j]
          else 
            acc
        ) 0.0 (Card 0) (length l)
      sum + exp(q.[i]) * v.[i]
    )

let Qtimesv_test () =
  let q = vec3 0.1 -1.0 0.3
  let l = vec3 5.0 -2.0 7.1
  let v = vec3 1.4 -7.0 3.1
  let ans0 = exp(q.[0]) * v.[0]
  let ans1 =      l.[0] * v.[0] + exp(q.[1]) * v.[1]
  let ans2 =      l.[1] * v.[0] +      l.[2] * v.[1] + exp(q.[2]) * v.[2]
  let ans = vec3 ans0 ans1 ans2
  let qv = Qtimesv q l v
  let nrm = sqnorm (vectorSub qv ans)
  //assert (nrm < 0.0001)
  numberPrint nrm

let gmm_objective (x:Matrix) (alphas:Vector) (means:Matrix) (qs:Matrix) (ls:Matrix) (wishart_gamma:Number) (wishart_m:Number) =
    let n : Cardinality = rows x
    let d : Cardinality = cols x
    let K : Cardinality = length alphas
//    assert (K = rows means)
//    assert (d = cols means)
//    assert (K = rows qs)
//    assert (d = cols qs)
//    assert (K = rows ls)
//    assert (let di = (cardToInt d) in di*(di-1)/2 = cardToInt (cols ls))
    vectorSum ( build n (fun i ->
      logsumexp( build K (fun k -> 
        alphas.[k] + vectorSum(qs.[k]) - 0.5 * (sqnorm (Qtimesv qs.[k] ls.[k] (vectorSub x.[i] means.[k])))
      )))) - 
      (float (cardToInt n)) * (logsumexp alphas) +
      0.5 * vectorSum ( build K (fun k -> sqnorm (vectorMap exp qs.[k]) + sqnorm (ls.[k])))

(** Testing **)

let test_gmm (dum: Vector) =
  let a = [| 1.0; 2.0; 3.0 |]
  vectorPrint a
  let mat1 = 
    [| [| 1.0; 2.0; 3.0; |];
       [| 4.0; 5.0; 6.0; |];
       [| 7.0; 8.0; 9.0; |] |]
  matrixPrint mat1
  ()