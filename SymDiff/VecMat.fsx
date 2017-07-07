// SymDif examples

/// Vec: Vector given size and builder.
type Vec<'T>(size: int, builder:int->'T) = 
    // Fields:
    member this.v = Array.init size builder
    member this.size = size

    // Additional constructors:
    new(size:int, value:'T) = Vec<'T> (size, fun _->value)
    new(size:int, values:'T[]) = Vec<'T> (size, fun i -> values.[i])

    // Methods:
    member this.Item i = this.v.[i]

// Mat: Matrix expressed as vector of rows.
type Mat<'T>(rows: int, cols: int, builder: int->int->'T) = 
    member this.v = Vec<Vec<'T>> (rows, fun i -> Vec<'T> (cols, builder i))
    new(rows:int, cols:int, value:'T) = Mat<'T> (rows, cols, fun i j -> value)
    new(rows:int, cols:int, values:'T[]) = Mat<'T> (rows, cols, fun i j -> values.[i * cols + j])
    member this.Item i = this.v.[i / cols].[i % cols]

let fold (f:'Accum->'T->'Accum) (a:'Accum) (v:Vec<'T>) = Array.fold f a v.v
//let fold0 (f:'Accum->'T->'Accum) (v:Vec<'T>) = Array.fold f LanguagePrimitives.GenericZero<'Accum> v.v

let eye (n:int) = Mat<float>(n,n, fun i j -> if i = j then 1.0 else 0.0)
let grad_eye (n: int) = () // essentially undefined: shape changes as a fn of n 

let VSmul (a:Vec<'U>, b:'T) = Vec<'U>(a.size, fun i -> a.[i] * b)
let SVmul (b:'T, a:Vec<'U>) = Vec<'U>(a.size, fun i -> b * a.[i])

let grad_VSmul (a:Vec<'U>, b:'T) : Vec<Vec<'T>> = eye(a.size) * b


// Uncurried version ... I can see a few ways to do it, but all require a function to be packaged with its derivative, and then what about higher derivatives?
//let cmul (a:Vec<'T>) = fun (b:'T) -> Vec<'T>(a.size, fun i -> a.[i] * b)
// let grad_cmul (a:Vec<'T>) = 

//let f v = 
//    let v0 = Vec<float> (3, 0.0)
//    let u = Vec<float> (3, [|1.0; 2.0; 3.0|])
//    let t1 = mul u 2.0
//    t1

/// add: works for matrices with a recursive call
let add (a:Vec<'T>) (b:Vec<'T>) = Vec<'T>(a.size, fun i -> a.[i] + b.[i])
let grad1_add (a:Vec<'T>) (b:Vec<'T>) = eye(a.size)
let grad2_add (a:Vec<'T>) (b:Vec<'T>) = eye(a.size)
let dot (a:Vec<'T>) (b:Vec<'T>) = Vec<'T>(a.size, fun i -> a.[i] + b.[i])

let sumsq (v:Vec<'T>) : 'T = 
    Array.fold (fun accum value -> accum + value * value) v.[0] (Array.init (v.size-1) (fun i -> v.[i+1]))

let sumsq' (v:Vec<'T>) : Vec<'T> = add v v
    
let norm (v:Vec<'T>) : 'T = 
    sqrt (sumsq v)


let normalized (v:Vec<'T>) : Vec<'T> = mul v (1.0/(norm v))

let cross_matrix (n: Vec<float>) = Mat<float>(3,3, [|    0.0; -n.[2];    n.[1]; 
                                                       n.[2];    0.0;   -n.[0]; 
                                                      -n.[1];  n.[0];      0.0 |])

let cross_matrix' (n: Vec<float>) = Mat<float>(3,3, [|    0.0; -n.[2];    n.[1]; 
                                                       n.[2];    0.0;   -n.[0]; 
                                                      -n.[1];  n.[0];      0.0 |])




// reminder: toby says windows used dps
