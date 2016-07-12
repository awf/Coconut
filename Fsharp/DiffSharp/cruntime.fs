module cruntime

open linalg
open types

type Environment = Map<string, AnyNumeric>

type Closure<'a, 'b> = {
  lambda: Environment -> ('a -> 'b);
  env: Environment
}

let envRef (env: Environment) (name: string): AnyNumeric = 
  Map.find name env

let getIndex (v: AnyNumeric): Index = 
  match v with 
  | Idx n -> n 
  | _ -> failwith (sprintf "Cannot invoke getIndex for %A" v)

let getNumber (v: AnyNumeric): Number = 
  match v with 
  | ZeroD n -> n 
  | _ -> failwith (sprintf "Cannot invoke getNumber for %A" v)

let getVector (v: AnyNumeric): Vector = 
  match v with 
  | OneD n -> n 
  | _ -> failwith (sprintf "Cannot invoke getVector for %A" v)

let getMatrix (v: AnyNumeric): Matrix = 
  match v with 
  | TwoD n -> n 
  | _ -> failwith (sprintf "Cannot invoke getMatrix for %A" v)

let makeIndex (n: Index): AnyNumeric = 
  Idx n

let makeNumber (n: Number): AnyNumeric = 
  ZeroD n

let makeVector (n: Vector): AnyNumeric = 
  OneD n

let makeMatrix (n: Matrix): AnyNumeric = 
  TwoD n

let makeEnv (bindings: (string * AnyNumeric) List): Environment = 
  Map.ofList bindings

let makeClosure<'a, 'b> (lambda: Environment -> 'a -> 'b) (env: Environment): Closure<'a, 'b> = 
  {lambda = lambda; env = env}

let applyClosure<'a, 'b> (closure: Closure<'a, 'b>) (lambdaArg: 'a): 'b = 
  closure.lambda closure.env lambdaArg

