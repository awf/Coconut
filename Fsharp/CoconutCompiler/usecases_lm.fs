module usecases_lm

open corelang
open linalg
open types
open utils
open cardinality

// Dummy implementation -- should call out to LAPACK/etc
let matrixCholeskySolve(m: Matrix) (v: Vector) : Vector =
  build (rows m) (fun i -> v.[0])

(*
  Levenberg-Marquardt implementation
*)

// This implementation recomputes the Jacobian too many times -- pass (Some J) to improve
let rec minimize_lm_aux (f: Vector -> Vector) (jacobian: Vector -> Matrix) (x: Vector) (lambda: Number) : Vector = 
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
      minimize_lm_aux f jacobian xpdelta (lambda / 10.0) 
  else
      // Bad step, reject and increase lambda, terminate if lambda too high
      if lambda > 1e10 then
        x
      else
        minimize_lm_aux f jacobian x (lambda * 10.0)

let minimize_lm (f: Vector -> Vector) (jacobian: Vector -> Matrix) (x0: Vector) : Vector = 
  let lm_lambda = 1e-3 in 
  minimize_lm_aux f jacobian x0 lm_lambda
