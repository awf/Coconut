module usecases_lm

(*
  Levenberg-Marquardt implementation.

  Illustrates a common numerical use case: user-supplied function, its derivatives (should be derived algorithmically), and a little matrix algebra.
  The natural implementation is tail-recursive, but could of course be written as an iteration
*)

open corelang
open linalg
open types
open utils
open cardinality

// Dummy implementation -- should call out to LAPACK/etc
let matrixCholeskySolve(m: Matrix) (v: Vector) : Vector =
  build (rows m) (fun i -> v.[0])

// This implementation recomputes the Jacobian too many times -- pass a nullable J to improve
let rec minimize_lm_aux (f: Vector -> Vector) (jacobian: Vector -> Matrix) (x: Vector) (lambda: Number) (max_iter : int) : Vector = 
  let Fx = f x
  let J = jacobian x
  let JtJ = matrixMult (matrixTranspose J) J
  let JtF = matrixVectorMult (matrixTranspose J) Fx
  let delta = matrixCholeskySolve JtJ JtF
  let xpdelta = vectorAdd x delta
  let Fx' = f xpdelta
  let ex = sqnorm Fx
  let ex' = sqnorm Fx'
  if ex < ex' then
      // Good step, accept, and decrease lambda
      minimize_lm_aux f jacobian xpdelta (lambda / 10.0) (max_iter - 1)
  else
      // Bad step, reject and increase lambda, terminate if lambda too high
      if lambda > 1e10 || max_iter <= 1 then
        x
      else
        minimize_lm_aux f jacobian x (lambda * 10.0) (max_iter - 1)

let minimize_lm (f: Vector -> Vector) (jacobian: Vector -> Matrix) (x0: Vector) : Vector = 
  let lambda = 1e-3 in 
  let max_iter = 100 in
  minimize_lm_aux f jacobian x0 lambda max_iter
