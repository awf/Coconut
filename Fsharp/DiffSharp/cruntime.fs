module cruntime

open linalg
open types

let envRef (env: Environment) (name: string): AnyNumeric = 
  Map.find name env

let private getIndex (v: AnyNumeric): Index = 
  match v with 
  | Idx n -> n 
  | _ -> failwith (sprintf "Cannot invoke getIndex for %A" v)

let private getNumber (v: AnyNumeric): Number = 
  match v with 
  | ZeroD n -> n 
  | _ -> failwith (sprintf "Cannot invoke getNumber for %A" v)

let private getVector (v: AnyNumeric): Vector = 
  match v with 
  | OneD n -> n 
  | _ -> failwith (sprintf "Cannot invoke getVector for %A" v)

let private getMatrix (v: AnyNumeric): Matrix = 
  match v with 
  | TwoD n -> n 
  | _ -> failwith (sprintf "Cannot invoke getMatrix for %A" v)

let private getMatrix3D (v: AnyNumeric): Matrix3D = 
  match v with 
  | ThreeD n -> n 
  | _ -> failwith (sprintf "Cannot invoke getMatrix3D for %A" v)

let rec getAnyNumeric<'a> (v: AnyNumeric): 'a = 
  failwith "Not implemented yet!"

and private getFun<'a, 'b> (v: AnyNumeric): 'a -> 'b = 
  failwith (sprintf "Cannot invoke getFun for %A" v)

let private makeIndex (n: Index): AnyNumeric = 
  Idx n

let private makeNumber (n: Number): AnyNumeric = 
  ZeroD n

let private makeVector (n: Vector): AnyNumeric = 
  OneD n

let private makeMatrix (n: Matrix): AnyNumeric = 
  TwoD n

let private makeMatrix3D (n: Matrix3D): AnyNumeric = 
  ThreeD n

let rec makeAnyNumeric<'a> (v: 'a): AnyNumeric = 
  match v with
  | _ -> failwith "Not implemented yet!"

and private makeFun<'a, 'b> (* !! *) (f: 'a -> 'b): AnyNumeric = 
  Fun (fun (x: AnyNumeric) -> makeAnyNumeric(f(getAnyNumeric(x))))

let makeEnv (bindings: (string * AnyNumeric) List): Environment = 
  Map.ofList bindings

let makeClosure<'a, 'b> (lambda: Environment -> 'a -> 'b) (env: Environment): Closure<'a, 'b> = 
  {lambda = lambda; env = env}

let applyClosure<'a, 'b> (closure: Closure<'a, 'b>) (lambdaArg: 'a): 'b = 
  closure.lambda closure.env lambdaArg

