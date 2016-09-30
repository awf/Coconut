[<ReflectedDefinition>]
module usecases_gmm

(* 
 * GMM Use Case from https://github.com/awf/autodiff/blob/master/Documents/AD%202016%20extended.pdf
 *)

open MathNet.Numerics

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
let Qtimesv (q : Vector) (l : Vector) (v : Vector) =
    build (length v) (fun i ->
      let li = vectorSlice (Card i) (tri i) l
      let vi = vectorSlice (Card i) 0 v
      vectorSum (li .* vi) + exp(q.[i])*v.[i] 
    )

let Qtimesv_test () =
  let ans = vec3 5.52585459 24.26424112 -14.61600247 
  let qv = Qtimesv (vec3 0.1 -1.0 0.3) (vec3 5.0 -2.0 7.1) (vec3 5.0 -2.0 7.1)
  assert (sqnorm (vectorSub qv ans) < 0.0001)

let gmm_objective (x:Matrix) (alphas:Vector) (means:Matrix) (qs:Matrix) (ls:Matrix) (wishart_gamma:Number) (wishart_m:Number) =
    let n : Cardinality = rows x
    let d : Cardinality = cols x
    let K : Cardinality = length alphas
    assert (K = rows means)
    assert (d = cols means)
    assert (K = rows qs)
    assert (d = cols qs)
    assert (K = rows ls)
    assert (let di = (cardToInt d) in di*(di-1)/2 = cardToInt (cols ls))
    vectorSum ( build n (fun i ->
      logsumexp( build K (fun k -> 
        alphas.[k] + vectorSum(qs.[k]) - 0.5 * (sqnorm (Qtimesv qs.[k] ls.[k] (vectorSub x.[i] means.[k])))
      )) - 
      (float (cardToInt n)) * (logsumexp alphas) +
      0.5 * vectorSum ( build K (fun k -> sqnorm (vectorMap exp qs.[k]) + sqnorm (ls.[k])))
      ))

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