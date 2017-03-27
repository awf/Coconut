module cruntime

open types

let envRef (env: Environment) (name: string): AnyNumeric = 
  Map.find name env

let getAnyNumeric<'a> (v: AnyNumeric): 'a = 
  failwith "Not implemented!"

let makeAnyNumeric<'a> (v: 'a): AnyNumeric = 
  failwith "Not implemented!"

let makeEnv (bindings: (string * AnyNumeric) List): Environment = 
  Map.ofList bindings

let makeClosure<'a, 'b> (lambda: Environment -> 'a -> 'b) (env: Environment): Closure<'a, 'b> = 
  {lambda = lambda; env = env}

let applyClosure<'a, 'b> (closure: Closure<'a, 'b>) (lambdaArg: 'a): 'b = 
  closure.lambda closure.env lambdaArg

