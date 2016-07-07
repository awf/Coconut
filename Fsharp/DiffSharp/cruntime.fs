module cruntime

open linalg

type AnyNumeric = 
(*  | ZeroD of Number
  | OneD of Vector
  | TwoD of Matrix
*)
  Number

type Environment = Map<string, AnyNumeric>

type Closure<'a, 'b> = {
  lambda: Environment -> ('a -> 'b);
  env: Environment
}

let envRef (env: Environment) (name: string): AnyNumeric = 
  Map.find name env

let makeEnv (bindings: (string * AnyNumeric) List): Environment = 
  Map.ofList bindings

let makeClosure<'a, 'b> (lambda: Environment -> 'a -> 'b) (env: Environment): Closure<'a, 'b> = 
  {lambda = lambda; env = env}

let applyClosure<'a, 'b> (closure: Closure<'a, 'b>) (lambdaArg: 'a): 'b = 
  closure.lambda closure.env lambdaArg

