module cruntime

open linalg
open types

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

let getMatrix3D (v: AnyNumeric): Matrix3D = 
  match v with 
  | ThreeD n -> n 
  | _ -> failwith (sprintf "Cannot invoke getMatrix3D for %A" v)

let getAnyNumeric<'a> (v: AnyNumeric): 'a = 
  failwith "Not implemented yet!"

let getFun<'a, 'b> (v: AnyNumeric): 'a -> 'b = 
  failwith (sprintf "Cannot invoke getFun for %A" v)

let makeIndex (n: Index): AnyNumeric = 
  Idx n

let makeNumber (n: Number): AnyNumeric = 
  ZeroD n

let makeVector (n: Vector): AnyNumeric = 
  OneD n

let makeMatrix (n: Matrix): AnyNumeric = 
  TwoD n

let makeMatrix3D (n: Matrix3D): AnyNumeric = 
  ThreeD n

let makeAnyNumeric<'a> (v: 'a): AnyNumeric = 
  match typeof<'a> with
  | tp when tp = typeof<Number> -> failwith "Not implemented yet!"

let makeFun<'a, 'b> (* !! *) (f: 'a -> 'b): AnyNumeric = 
  Fun (fun (x: AnyNumeric) -> makeAnyNumeric(f(getAnyNumeric(x))))

let makeEnv (bindings: (string * AnyNumeric) List): Environment = 
  Map.ofList bindings

let makeClosure<'a, 'b> (lambda: Environment -> 'a -> 'b) (env: Environment): Closure<'a, 'b> = 
  {lambda = lambda; env = env}

let applyClosure<'a, 'b> (closure: Closure<'a, 'b>) (lambdaArg: 'a): 'b = 
  closure.lambda closure.env lambdaArg

