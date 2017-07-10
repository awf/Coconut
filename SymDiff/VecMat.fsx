// SymDif examples

/// Vec: Vector given size and builder.
[<StructuredFormatDisplay("{Display}")>]
type Vec<'T>(size: int, builder:int->'T) = 
    // Fields:
    member this.v = Array.init size builder
    member this.size = size

    // Additional constructors:
    new(size:int, value:'T) = Vec<'T> (size, fun _->value)
    new(size:int, values:'T[]) = Vec<'T> (size, fun i -> values.[i])
    new(values:'T[]) = Vec<'T> (values.Length, fun i -> values.[i])

    // Methods:
    member this.Item i = this.v.[i]
    member this.Display = "Vec[" + (Array.fold (fun s v -> s + " " + v.ToString()) "" this.v) + " ]"

// Mat: Matrix expressed as vector of rows.
[<StructuredFormatDisplay("{Display}")>]
type Mat<'T>(rows: int, cols: int, builder: int->int->'T) = 
    new(rows:int, cols:int, value:'T) = Mat<'T> (rows, cols, fun i j -> value)
    new(rows:int, cols:int, values:'T[]) = Mat<'T> (rows, cols, fun i j -> values.[i * cols + j])
    new(v: Vec<Vec<'T>>) = Mat<'T> (v.size, v.[0].size, fun i j -> v.[i].[j])

    member this.rows = rows
    member this.cols = cols
    member this.v = Vec<Vec<'T>> (rows, fun i -> Vec<'T> (cols, builder i))

    member this.Item i = this.v.[i / cols].[i % cols]
    member this.Item (i:int, j:int) = this.v.[i].[j]
    member this.Display = "Mat[" + (Array.fold (fun s (v:Vec<'T>) -> s + "; " + v.Display) "" this.v.v) + "]"

let fold (f:'Accum->'T->'Accum) (a:'Accum) (v:Vec<'T>) : 'Accum = Array.fold f a v.v

//let fold0 (f:'Accum->T->'Accum) (v:Vec<T>) = Array.fold f LanguagePrimitives.GenericZero<'Accum> v.v
let fold0 (f:float->float->float) (v:Vec<float>) = Array.fold f 0.0 v.v

let eye (n:int) = Mat<float>(n,n, fun i j -> if i = j then 1.0 else 0.0)
let diff_eye (n: int) = () // essentially undefined: shape changes as a fn of n 

// f      : Container1<float> -> Container2<float>
// diff_f : Container1<float> -> Container1<Container2<float>>

// No function overloading in F#
let VSmul (a:Vec<float>, b:float) = Vec<float>(a.size, fun i -> a.[i] * b)
let SVmul (a:float, b:Vec<float>) = Vec<float>(b.size, fun i -> a * b.[i])
let VVouter (a:Vec<float>, b:Vec<float>) = Mat<float>(a.size, b.size, fun i j -> a.[i] * b.[j])

let MSmul (a:Mat<float>, b:float) = Mat<float>(a.rows, a.cols, fun i j -> a.[i,j] * b)
let SMmul (a:float, b:Mat<float>) = Mat<float>(b.rows, b.cols, fun i j -> a * b.[i,j])

let diff_VSmul (a:Vec<float>, b:float) : (Vec<Vec<float>> * Vec<float>) = ((MSmul (eye(a.size), b)).v, a)
let diff_SVmul (a:float, b:Vec<float>) : (Vec<float> * Vec<Vec<float>>) = (b, (SMmul (a, eye(b.size))).v)

// [m11 m12] = [a11*b a12*b] = [a11 a12] * b
// [m21 m22]   [a21*b a22*b]   [a21 a22]
// dm21/dA = [0 0]
//           [b 0]

let diff_MSmul (a:Mat<float>, b:float) : (Mat<Mat<float>> * Mat<float>) = 
    (Mat<Mat<float>>(a.rows, a.cols, fun i j -> Mat<float>(a.rows, a.cols, fun k l -> if i = k && j = l then b else 0.0)),
     a)
let diff_SMmul (a:float, b:Mat<float>) : (Mat<float> * Mat<Mat<float>>) = 
    (b,
     Mat<Mat<float>>(b.rows, b.cols, fun i j -> Mat<float>(b.rows, b.cols, fun k l -> if i = k && j = l then a else 0.0)))

// Uncurried version ... I can see a few ways to do it, but all require a function to be packaged with its derivative, and then what about higher derivatives?
//let cmul (a:Vec<'T>) = fun (b:'T) -> Vec<'T>(a.size, fun i -> a.[i] * b)
//let diff_cmul (a:Vec<'T>) = 

//let f v = 
//    let v0 = Vec<float> (3, 0.0)
//    let u = Vec<float> (3, [|1.0; 2.0; 3.0|])
//    let t1 = mul u 2.0
//    t1

/// add: works for matrices with a recursive call
let VVadd (a:Vec<float>, b:Vec<float>) = Vec<float>(a.size, fun i -> a.[i] + b.[i])
let diff_VVadd (a:Vec<float>, b:Vec<float>) : Vec<Vec<float>> * Vec<Vec<float>> = (eye(b.size).v, eye(a.size).v)

// MMadd: add matrices
let MMadd (a:Mat<float>, b:Mat<float>) = Mat<float>(a.rows, a.cols, fun i j -> a.[i,j] + b.[i,j])
let diff_MMadd (a:Mat<float>, b:Mat<float>) : Mat<Mat<float>> * Mat<Mat<float>> = 
    (Mat<Mat<float>>(a.rows, a.cols, fun i j -> Mat<float>(a.rows, a.cols, fun k l -> if i = k && j = l then 1.0 else 0.0)),
     Mat<Mat<float>>(a.rows, a.cols, fun i j -> Mat<float>(a.rows, a.cols, fun k l -> if i = k && j = l then 1.0 else 0.0)))


let VVdot (a:Vec<float>) (b:Vec<float>) : float = Array.fold2 (fun accum ax bx -> accum + ax*bx) 0.0 a.v b.v
let diff_VVdot (a:Vec<float>, b:Vec<float>) : Vec<float> * Vec<float> = (b, a)

// d/dx x^.5 = .5x^-.5
let diff_sqrt (x: float) : float = 0.5 / sqrt(x)

// sumsq: sum of squared entries, norm squared
let sumsq (v:Vec<float>) : float = 
    fold (fun accum value -> accum + value * value) 0.0 v
let diff_sumsq (v:Vec<float>) : Vec<float> = VSmul (v, 2.0)

// norm: 2-norm of vector
let norm (v:Vec<float>) : float = 
    sqrt (sumsq v)

// diff_norm = v/norm(v)
let diff_norm (v:Vec<float>) : Vec<float> = 
    SVmul (diff_sqrt (sumsq v), diff_sumsq v)

let recip (x: float) = 1.0 / x
let diff_recip (x:float) = -(x ** -2.0)

// normalized = v / norm(v)
let normalized (v:Vec<float>) : Vec<float> = VSmul (v, recip (norm v))

// (v1 / sqrt(v1^2 + v2^2), v2 / sqrt(v1^2 + v2^2))
// d/dv1 = 1/n^2 * (v1 * n^-1 * v1 - n * 1, v2 * n^-1 * v1)
// d/dv2 = 1/n^2 * (v1 * n^-1 * v2        , v2 * n^-1 * v2 - n * 1)
// d/dv1 = 1/n^3 * (v1 * v1 - n^2 * 1, v2 * v1)
// d/dv2 = 1/n^3 * (v1 * v2        , v2 * v2 - n^2 * 1)
// d/dv = v v' / n^3 - I / n
// d/dv = (vhat vhat' - I) / n

// diff_normalized = (I*norm(v)^2 - v v')/norm(v)^3
let diff_normalized (v:Vec<float>) : Vec<Vec<float>> = 
    let s = recip (norm v)  // 1/n
    let diff_s = SVmul (diff_recip (norm v), diff_norm v) // -1/n^2 * v/n = -v/n^3
    let ret = VSmul (v, s)  // v/n
    let diff_ret = diff_VSmul (v, s) in
    // diff_ret = (s * I, v)
    (MMadd (Mat<float>(fst diff_ret), VVouter (snd diff_ret, diff_s))).v


let cross_matrix (n: Vec<float>) = Mat<float>(3,3, [|    0.0; -n.[2];    n.[1]; 
                                                       n.[2];    0.0;   -n.[0]; 
                                                      -n.[1];  n.[0];      0.0 |])

let diff_cross_matrix (n: Vec<float>) = Vec<Mat<float>>([|
                                                            Mat<float>(3,3, [|    0.0;    0.0;    0.0; 
                                                                                  0.0;    0.0;   -1.0; 
                                                                                  0.0;    1.0;    0.0   |]); 
                                                            Mat<float>(3,3, [|    0.0;    0.0;    1.0; 
                                                                                  0.0;    0.0;    0.0; 
                                                                                 -1.0;    0.0;    0.0   |]); 
                                                            Mat<float>(3,3, [|    0.0;   -1.0;    0.0; 
                                                                                  1.0;    0.0;    0.0; 
                                                                                  0.0;    0.0;    0.0   |])
                                                         |])
let basis_vector (n:int) (i:int) = Vec<float>(n, fun i' -> if i' = i then 1.0 else 0.0)
let diff (f:Vec<float> -> float) (x0:Vec<float>) = 
    let delta = 1e-5 in 
    let e = basis_vector x0.size in
    Vec<float>(x0.size, fun i -> (f (VVadd (x0, VSmul (e i, delta))) - f x0) * (1.0 / delta))

// reminder: toby says windows used dps
