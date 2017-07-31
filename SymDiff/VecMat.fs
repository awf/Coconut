module VecMat
open NUnit.Framework
open Swensen.Unquote


/// Test helper: compare floats up to a given tolerance
type Comparer(tol: float) =
    member this.tol = tol
    member this.cf (a:float, b:float):bool = abs(a - b) < this.tol

/// A float wrapper to test generic methods
type TestType(v: float) =
        static member Zero = TestType 0.0

(* 

    SYMBOLIC DIFFERENTIATION
    ------------------------

    NOTES
    =====

    Conventions in this file come largely from the discussion at https://github.com/awf/autodiff2/blob/master/autodiff/Differentiating%20Containers.md.
    At various points below, we compute derivatives of functions as in that document, summarized here:

    Recall derivatives of
         f : Container1<R> -> Container2<R> 
    have type
         f': Container1<R> -> Container1<Container2<R>>
    And note that Container1 may be a container of containers, including tuples

    The type variable R is for Real.

    [1] Sometimes I write "matrix" in quotes because it is defined as Vec<Vec<>>.  
        This is in cases where I want to emphasize that derivatives of a function should be 
        expressible entirely in terms of the function's own types.

    [2] I name certain tuples as (Empty, Single, Duple, Triple, Quadruple) etc.   E.g. Single<R> is just R

*)


(**** Derivatives of basic functions ****)

let sqr (x: float) : float = x * x
let sqr' (x: float) : float = 2.0 * x

// diff_sin: float -> float
let sin' (x: float) : float = cos(x)

// diff_sin: float -> float
let cos' (x: float) : float = -sin(x)

// diff_sqrt: float -> float
//    d/dx x^.5 = .5x^-.5
let sqrt' (x: float) : float = 0.5 / sqrt(x)

// recip: 1/x
let recip (x: float) = 1.0 / x
let recip' (x: float) = -(x ** -2.0)

(**** Finite difference derivative computation ****)

type FiniteDiff(delta: float) =
    member this.delta = delta
    member this.one_over_2delta = 1.0/(2.0*delta)
    
    // diff: Given function f -> C1<R> -> C2<R> return f' : C1<R> -> C1<C2<R>>
    // Uncurried as we want to overload on type of f
    member this.diff (f:float->float) = fun (x:float) -> this.one_over_2delta * ((f (x + this.delta)) - (f (x - this.delta)))

[<Test>]
let test_basic_diffs () =
    let fd = FiniteDiff(1e-5)
    let cf = Comparer(1e-4)
    test <@ cf.cf (fd.diff sin 1.1, sin' 1.1) @>
    test <@ cf.cf (fd.diff cos 1.1, cos' 1.1) @>
    test <@ cf.cf (fd.diff sqrt 1.1, sqrt' 1.1) @>
    test <@ cf.cf (fd.diff recip 1.1, recip' 1.1) @>

/// Kronecker delta, float
// delta i j = 1.0 if i = j
let delta i j = if i = j then 1.0 else 0.0

/// Scaled Kronecker delta, generic
// sdelta i j s = if i = j then s else 0
let inline sdelta i j (s:'T) = if i=j then s else LanguagePrimitives.GenericZero<'T>

[<Test>]
let test_delta () =
    let c = TestType(1.1)
    test <@ delta 1 1 = 1.0 @>
    test <@ delta 1 2 = 0.0 @>
    test <@ sdelta 1 1 222 = 222 @>
    test <@ sdelta 1 2 222 = 0 @>
    test <@ delta 1 1 = sdelta 1 1 1.0 @>
    test <@ sdelta 1 1 c = c @>
    test <@ sdelta 1 0 2 = 0 @>
    test <@ sdelta (1,1) (1,1) 2.2 = 2.2 @>
    test <@ sdelta (1,1) (1,2) 2.2 = 0.0 @>

/// GDot: Generalized dot
//  Consider the function composition 
//     h(x) = g(f(x))
//  for example
//     h(x) = sin(sqr(x))
//     h'(x) = sqr'(x) * sin'(sqr(x))
//  when the functions have types
//     f : C1<R> -> C2<R>
//     g : C2<R> -> C3<R>
//  so h goes from C1 to C3:
//     h : C1<R> -> C3<R>
//  And then the derivatives must be
//     f' : C1<R> -> C1<C2<R>>
//     g' : C2<R> -> C2<C3<R>>
//     h' : C1<R> -> C1<C3<R>>
//  Let's look at code for the derivative.   If all the containers are singletons,
//  then it's normal scalar chain rule:
//     let h' x = (f' x) (g' f(x))
// So in the simple example above, f = sqr = \x.x^2, and g = sin, then
//     let h' x = 2*x * (sin' x)
//  For general containers, we just need a form of multiplication that zips over C2, let's call it DOT
//     let h' x = DOT (g' f(x)) (f' x)
//  It's hard to tell DOT about C2, so we just pass a parameter of that type and let overloading work it out.
//     let h' x = 
//        let fx = f x
//        DOT fx (g' fx) (f' x)

type GDot =
    static member dot (c2: float, c2c3: float, c1c2: float) = c2c3 * c1c2
    static member dot (c2: float[], c2c3: float[], c1c2: float[]) = Array.fold2 (fun s a b -> s + a * b) 0.0 c2c3 c1c2

type Tuple =
    static member get(tup:'T*'T, ind:int) = 
        match ind, tup with
        | 0, (a,_) -> a
        | 1, (_,b) -> b
        | _, _ -> failwith "unpack"
    static member get(tup:'T*'T*'T, ind:int) = 
        match ind, tup with
        | 0, (a,_,_) -> a
        | 1, (_,b,_) -> b
        | 2, (_,_,c) -> c
        | _, _ -> failwith "unpack"
    static member get(tup:'T*'T*'T*'T, ind:int) = 
        match ind, tup with
        | 0, (a,_,_,_) -> a
        | 1, (_,b,_,_) -> b
        | 2, (_,_,c,_) -> c
        | 3, (_,_,_,d) -> d
        | _, _ -> failwith "unpack"
    static member get(tup:'T*'T*'T*'T*'T, ind:int) = 
        match ind, tup with
        | 0, (a,_,_,_,_) -> a
        | 1, (_,b,_,_,_) -> b
        | 2, (_,_,c,_,_) -> c
        | 3, (_,_,_,d,_) -> d
        | 4, (_,_,_,_,e) -> e
        | _, _ -> failwith "unpack"
    static member get(tup:'T*'T*'T*'T*'T*'T, ind:int) = 
        match ind, tup with
        | 0, (a,_,_,_,_,_) -> a
        | 1, (_,b,_,_,_,_) -> b
        | 2, (_,_,c,_,_,_) -> c
        | 3, (_,_,_,d,_,_) -> d
        | 4, (_,_,_,_,e,_) -> e
        | 5, (_,_,_,_,_,f) -> f
        | _, _ -> failwith "unpack"
    static member get(tup:'T*'T*'T*'T*'T*'T*'T, ind:int) = 
        match ind, tup with
        | 0, (a,_,_,_,_,_,_) -> a
        | 1, (_,b,_,_,_,_,_) -> b
        | 2, (_,_,c,_,_,_,_) -> c
        | 3, (_,_,_,d,_,_,_) -> d
        | 4, (_,_,_,_,e,_,_) -> e
        | 5, (_,_,_,_,_,f,_) -> f
        | 6, (_,_,_,_,_,_,g) -> g
        | _, _ -> failwith "unpack"

/// Vec: Vector given size and builder.
[<StructuredFormatDisplay("{Display}")>]
type Vec<'T>(values:'T[]) = 
    // Fields:
    member this.v = values
    member this.size = values.Length

    // Constructor from builder
    new(size:int, builder: int -> 'T) = Vec<'T> (Array.init size builder)
    // Constructor from tuples makes for a little less visual noise when making literals
    new(v1:'T,v2:'T) = Vec<'T> ([| v1;v2 |])
    new(v1:'T,v2:'T,v3:'T) = Vec<'T> ([| v1;v2;v3 |])
    new(v1:'T,v2:'T,v3:'T,v4:'T) = Vec<'T> ([| v1;v2;v3;v4 |])
    new(v1:'T,v2:'T,v3:'T,v4:'T,v5:'T) = Vec<'T> ([| v1;v2;v3;v4;v5 |])
    new(v1:'T,v2:'T,v3:'T,v4:'T,v5:'T,v6:'T) = Vec<'T> ([| v1;v2;v3;v4;v5;v6 |])
    new(tup:'T*'T) = Vec<'T> (2, fun i -> Tuple.get(tup,i))
    new(tup:'T*'T*'T) = Vec<'T> (3, fun i -> Tuple.get(tup,i))
    new(tup:'T*'T*'T*'T) = Vec<'T> (4, fun i -> Tuple.get(tup,i))
    new(tup:'T*'T*'T*'T*'T) = Vec<'T> (5, fun i -> Tuple.get(tup,i))
    new(tup:'T*'T*'T*'T*'T*'T) = Vec<'T> (6, fun i -> Tuple.get(tup,i))

    static member str(x: 'T) = let bx = box x in if ( bx :? float ) then sprintf "%.4f" (unbox bx) else x.ToString()

    // Methods:
    member this.Item (i:int) = this.v.[i]
    member this.Display = "Vec[" + (Array.fold (fun s (v:'T) -> s + " " + (Vec<'T>.str v)) "" this.v) + " ]"
    override this.ToString() = this.Display

 
(**** Fold/Map etc ****)

/// Fold over a vector
let fold (f:'Accum->'T->'Accum) (a:'Accum) (v:Vec<'T>) : 'Accum = Array.fold f a v.v

//let fold0 (f:'Accum->T->'Accum) (v:Vec<T>) = Array.fold f LanguagePrimitives.GenericZero<'Accum> v.v
let fold0 (f:float->float->float) (v:Vec<float>) = Array.fold f 0.0 v.v

let fold2 (a:Vec<'T1>) (b:Vec<'T2>) (acc0:'Accum) (f:'T1*'T2->'Accum->'Accum):'Accum = Array.fold2 (fun (acc:'Accum) (ai:'T1) (bi:'T2) -> f (ai,bi) acc) acc0 a.v b.v

// This version of map has the function at the end to aid type inference
let map2 (a:Vec<'T1>) (b:Vec<'T2>) (f:'T1*'T2 -> 'T3) = Vec<'T3>(Array.map2 (fun ai bi -> f (ai,bi)) a.v b.v)

let inline Vec_map (f:'T1 -> 'T2) (v:Vec<'T1>) = Vec<'T2>(Array.map f v.v)

let inline Vec_map2 (f:'T->'S->'R) (a:Vec<'T>) (b:Vec<'S>) = Vec<'R>(a.size, fun i->f a.[i] b.[i])

// to_vec_of_tuples: Vec<T>*Vec<S> -> Vec<T*S>
let to_vec_of_tuples (v:Vec<'T> * Vec<'S>):Vec<'T * 'S> = Vec_map2 (fun ai bi -> ai,bi) (fst v) (snd v)

(**** Constructors / Getters ****)

// It's sometimes handy to quickly create a little-vector
let vec2 (x:float) (y:float) = Vec<float>([| x;y |])

// It's sometimes handy to quickly create a little-vector
let vec3 (x:float) (y:float) (z:float) = Vec<float>([| x;y;z|])

// Vector of float zeros
let Vec_zeros (n:int) = Vec<float>(n, fun j -> 0.0)

/// Vector of float ones
let Vec_ones (n:int) = Vec<float>(n, fun j -> 1.0)

// Scaled basis vector a * e_i = [0 ... 0, a, 0 ... 0]
let inline Vec_ae (n:int) (i:int) (a:'T) = Vec<'T>(n, fun j -> sdelta i j a)

// Derivative of Ea wrt a
// Ea: float -> Vec<float>
// Ea': float -> Vec<float>
let inline Vec_ae' (n:int) (i:int) (a:'T) = Vec_ae n i LanguagePrimitives.GenericOne<'T>

// Basis vector e_i = [0 ... 0, 1.0, 0 ... 0]
let Vec_e (n:int) (i:int) = Vec_ae n i 1.0

// Scaled identity "matrix" of type T
// See notes above [1].
let inline Vec_seye (n:int) (s:'T) = Vec<Vec<'T>>(n, fun i -> Vec_ae n i s)

// Derivative of seye wrt s
let inline Vec_seye' (n:int) (s:'T) = Vec<Vec<'T>>(n, fun i -> Vec_ae' n i s)

// Identity "matrix" of float
let inline Vec_eye (n:int) = Vec_seye n 1.0

// Construct a Vec<Vec<>> easily
let inline VecVec (rows:int) (cols:int) (builder:int -> int -> 'T) = Vec<Vec<'T>>(rows, fun i-> Vec<'T>(cols, builder i))

// Get at index, and derivative
let get (v:Vec<float>) (i:int) = v.[i]

let get' (v:Vec<float>) (i:int) = Vec_e v.size i

(**** Arithmetic ****)
// add: Duple<Vec<R>> -> Vec<R> (=RHS)
let Vec_add (a:Vec<float>, b:Vec<float>) = Vec<float>(a.size, fun i-> a.[i] + b.[i])

// Derivative add': Duple<Vec<R>> -> Duple<Vec<Vec<R>>> (= Duple<Vec<RHS>>)
let Vec_add' (a:Vec<float>, b:Vec<float>): Vec<Vec<float>> * Vec<Vec<float>> = (Vec_eye b.size, Vec_eye a.size)

// sub: Duple<Vec<R>> -> Vec<R> (=RHS)
let Vec_sub (a:Vec<float>, b:Vec<float>) = Vec<float>(a.size, fun i-> a.[i] - b.[i])

// Derivative sub': Duple<Vec<R>> -> Duple<Vec<Vec<R>>> (= Duple<Vec<RHS>>)
let Vec_sub' (a:Vec<float>, b:Vec<float>): Vec<Vec<float>> * Vec<Vec<float>> = (Vec_eye b.size, Vec_seye a.size -1.0)

// dot: Vec<R> * Vec<R> -> R
let Vec_dot (a:Vec<float>, b:Vec<float>):float = Array.fold2 (fun accum ai bi -> accum + ai * bi) 0.0 a.v b.v

// dot': Vec<R> * Vec<R> -> Vec<R> * Vec<R>
let Vec_dot' (a:Vec<float>, b:Vec<float>): Vec<float> * Vec<float> = (b, a)

// mul: R * Vec<R> -> Vec<R>
let Vec_smul (a:float, b:Vec<float>)=Vec<float>(b.size, fun i-> a * b.[i])

// dot': R * Vec<R> -> Vec<R> * Vec<Vec<R>>
let Vec_smul' (a:float, b:Vec<float>): Vec<float> * Vec<Vec<float>> = (b, Vec_seye b.size a)

// outer: Vec<R> * Vec<R> -> Vec<Vec<R>>
let Vec_outer (a:Vec<float>, b:Vec<float>) = Vec<Vec<float>>(a.size, fun i -> Vec<float>(b.size, fun j -> a.[i]*b.[j]))

// outer': Vec<R> * Vec<R> -> Vec<Vec<Vec<R>>> * Vec<Vec<Vec<R>>>
let Vec_outer' (a:Vec<float>, b:Vec<float>): Vec<Vec<Vec<float>>> * Vec<Vec<Vec<float>>> = 
        Vec<Vec<Vec<float>>>(a.size, fun i -> VecVec a.size b.size (fun i' j' -> sdelta i i' b.[j'])),
        Vec<Vec<Vec<float>>>(b.size, fun j -> VecVec a.size b.size (fun i' j' -> sdelta j j' a.[i']))

(**** Finite difference gradients/jacobians ****)
type FiniteDiff with

    // diff: (R->Vec<R>) -> (R->Vec<R>)
    // Tangent
    member this.diff (f:float->Vec<float>) = fun (x:float) -> Vec_smul (this.one_over_2delta, Vec_sub (f (x + this.delta), f (x - this.delta)))

    // diff: (Vec<R>->R) -> (Vec<R>->Vec<R>)
    // Gradient
    member this.diff (f:Vec<float>->float) = 
        fun (x:Vec<float>) -> Vec<float>(x.size, fun i -> (this.diff (fun (h: float) -> f (Vec_add (x, Vec_ae x.size i h))) 0.0))

    // diff: (Vec<R>->Vec<R>) -> (Vec<R>->Vec<Vec<R>>)
    // Jacobian
    member this.diff (f:Vec<float>->Vec<float>) = 
        fun (x:Vec<float>) -> Vec<Vec<float>>(x.size, fun i -> (this.diff (fun (h: float) -> f (Vec_add (x, Vec_ae x.size i h))) 0.0))
 
let foldi0 n f = Array.fold (fun a i -> a + f i) 0.0 [|0..n-1|]

(**** GDot ****)
type GDot with
    // C1: Single, C2:Vec, C3:Single
    static member dot (c2: Vec<float>, c2c3: Vec<float>, c1c2: Vec<float>): float = Vec_dot (c2c3, c1c2)

    // C1: VecN, C2:Single, C3:VecM -> VecN<VecM>
    static member dot (c2: float, c2c3: Vec<float>, c1c2: Vec<float>) = 
            Vec<Vec<float>>(c1c2.size, fun i -> Vec<float>(c2c3.size, fun j -> c1c2.[i] * c2c3.[j]))

    // C1: Single, C2:Single, C3:Vec
    static member dot (c2: float, c2c3: Vec<float>, c1c2: float) = Vec<float>(c2c3.size, fun i -> c2c3.[i] * c1c2)

    // C1: Vec, C2:Single, C3:Single
    static member dot (c2: float, c2c3: float, c1c2: Vec<float>) = Vec<float>(c1c2.size, fun i -> c2c3 * c1c2.[i])

    // C1: VecM, C2: VecK, C3:Single -> VecM
    static member dot (c2: Vec<float>, c2c3: Vec<float>, c1c2: Vec<Vec<float>>) = Vec<float>(c1c2.size, fun i -> foldi0 (c2c3.size) (fun k -> c2c3.[k] * c1c2.[i].[k]))

    // C1: VecM<VecP>, C2:VecP, C3:VecP<VecN>  -> VecM<VecN>
    static member dot (c2: Vec<float>, c2c3: Vec<Vec<float>>, c1c2: Vec<Vec<float>>):Vec<Vec<float>> =
         Vec<Vec<float>>(c1c2.size, fun i -> Vec<float>(c2c3.[0].size, fun j -> foldi0 (c2c3.size) (fun k -> c2c3.[k].[j] * c1c2.[i].[k])))

    // C1: Single<VEC<VEC>>, C2:VEC<VEC>, C3:Single<VEC<VEC>>
    //static member dot (c2: Vec<Vec<float>>, c2c3: Vec<Vec<float>>, c1c2: Vec<Vec<float>>):float =
    //     Vec<Vec<float>>(c1c2.size, fun i -> Vec<float>(c2c3.size, fun j -> Vec_dot(c2c3.[i], c1c2.[j])))

    // C1: Vec<Tuple>, C2: Tuple, C3: Tuple<Vec>
    static member dot(c2:float * Vec<float>, c2c3:Vec<float> * Vec<Vec<float>>, c1c2: Vec<float * Vec<float>>):Vec<Vec<float>> =
        Vec_map2 (fun a b -> Vec_add (a,b)) (GDot.dot(fst c1c2.[0], fst c2c3, Vec_map fst c1c2)) (GDot.dot(snd c1c2.[0], snd c2c3, Vec_map snd c1c2))

    // C1: Vec<Tuple>, C2: Tuple, C3: Tuple<Vec>
    static member dot(c2:Vec<float> * Vec<float>, c2c3:Vec<Vec<float>> * Vec<Vec<float>>, c1c2: Vec<Vec<float> * Vec<float>>):Vec<Vec<float>> =
        Vec_map2 (fun a b -> Vec_add (a,b)) (GDot.dot(fst c1c2.[0], fst c2c3, Vec_map fst c1c2)) (GDot.dot(snd c1c2.[0], snd c2c3, Vec_map snd c1c2))

    // C1: Single<Tuple>, C2: Tuple, C3: Tuple<Single>
    static member dot(c2:Vec<float> * Vec<float>, c2c3:Vec<float> * Vec<float>, c1c2: Vec<float> * Vec<float>):float =
        GDot.dot(fst c1c2, fst c2c3, fst c1c2) + GDot.dot(snd c1c2, snd c2c3, snd c1c2)

    // C1: Vec<Tuple>, C2: Tuple<Vec>, C3: Single
    static member dot(c2:Vec<float> * Vec<float>, c2c3:Vec<float> * Vec<float>, c1c2: Vec<Vec<float> * Vec<float>>):Vec<float> =
        Vec<float>(c1c2.size, fun i -> GDot.dot(c2, c2c3, c1c2.[i]))
    



(****** norm etc ******)

// sumsq: sum of squared entries, norm squared
let Vec_sumsq (v:Vec<float>) : float = Vec_dot (v,v)

// sumsq': 2v
let Vec_sumsq' (v:Vec<float>) : Vec<float> = Vec_add (v,v)

// norm: 2-norm of vector
let Vec_norm (v:Vec<float>) : float = 
    let sumsqv = Vec_sumsq v
    sqrt sumsqv

// norm' = v/norm(v)
let Vec_norm' (v:Vec<float>) : Vec<float> = 
    let sumsqv = Vec_sumsq v
    let sumsqv' = Vec_sumsq' v
    GDot.dot (sumsqv, sqrt' sumsqv, sumsqv')

// normalized : Vec<R> -> Vec<R> = v / norm(v)
let normalized (v:Vec<float>) : Vec<float> = 
    let n = Vec_norm v
    let s = recip n  
    Vec_smul (s,v) 

// normalized': Vec<R> -> Vec<Vec<R>> = (I*norm(v)^2 - v v')/norm(v)^3
let normalized' (v:Vec<float>) : Vec<Vec<float>> = 
    let n = Vec_norm v
    let n' = Vec_norm' v
    let s = recip n
    let s' = GDot.dot (s, recip' n, n')
    let v' = Vec_eye v.size
    // returned was Vec_smul (s,v)
    // Chain rule: h(x) = g(f(x)), so h'(x) = GDot(fx, g'(fx), f'x)
    GDot.dot((s,v), Vec_smul' (s,v), to_vec_of_tuples (s',v'))

    // Note:
    // (v1 / sqrt(v1^2 + v2^2), v2 / sqrt(v1^2 + v2^2))
    // d/dv1 = 1/n^2 * (v1 * n^-1 * v1 - n * 1, v2 * n^-1 * v1)
    // d/dv2 = 1/n^2 * (v1 * n^-1 * v2        , v2 * n^-1 * v2 - n * 1)
    // d/dv1 = 1/n^3 * (v1 * v1 - n^2 * 1, v2 * v1)
    // d/dv2 = 1/n^3 * (v1 * v2        , v2 * v2 - n^2 * 1)
    // d/dv = v v' / n^3 - I / n
    // d/dv = (vhat vhat' - I) / n

(**** Testing ****)
// Check that infinity norm of difference of two vectors is less than a tolerance
let Vec_near (tol:float) (a:Vec<float>) (b:Vec<float>) = Array.fold2 (fun (isnear:bool) ai bi -> isnear && abs(ai - bi) < tol) true a.v b.v

/// all: Is predicate f true for all entries of a
let inline Vec_all f (a:Vec<'T1>): bool = Array.fold (fun (state:bool) ai -> state && f ai) true a.v

/// all2: Is predicate f true for all entries of zip(a,b)
let inline Vec_all2 f (a:Vec<'T1>) (b:Vec<'T2>): bool = Array.fold2 (fun (state:bool) ai bi -> state && f ai bi) true a.v b.v

/// Floating-point comparison helper
type Comparer with
    member this.cf (a:Vec<float>, b:Vec<float>):bool = Vec_all2 (fun (ai:float) bi -> this.cf (ai, bi)) a b      // FIXME: Would love to make this generic on Vec<'T>...
    member this.cf (a:Vec<Vec<float>>, b:Vec<Vec<float>>):bool = Vec_all2 (fun (ai:Vec<float>) bi -> this.cf (ai, bi)) a b
    member this.cf (a:Vec<Vec<float>>*Vec<Vec<float>>, b:Vec<Vec<float>>*Vec<Vec<float>>) = this.cf(fst a, fst b) && this.cf(snd a, snd b)

[<Test>]
let test_vec_basics () = 
    let near = Comparer(1e-8)
    let a = vec3 1.1 2.2 3.3
    let s = 2.3
    let sa = vec3 (s*1.1) (s*2.2) (s*3.3)
    let b = vec3 3.1 -1.2 -5.7
    let ones3 = Vec_ones 3
    let eye3 = Vec_seye 3 1.0
    test <@ near.cf (a, (Vec<float>(3, fun i -> (float i + 1.0) * 1.1))) @>
    test <@ near.cf (Vec_ones 4, Vec<float>(4, fun i->1.0)) @>
    test <@ near.cf (Vec_zeros 1, Vec<float>(1, fun i->0.0)) @>
    test <@ near.cf (Vec_zeros 3, Vec<float>(3, fun i->0.0)) @>
    test <@ near.cf (Vec_add (a,b), vec3 4.2 1.0 -2.4) @>
    test <@ near.cf (Vec_add' (a,b), (Vec_eye 3, Vec_eye 3)) @>
    test <@ near.cf (Vec_smul (s,a), sa) @>
    let o = Vec_outer (vec2 1.1 2.2, vec3 1.3 1.4 1.5)
    test <@ near.cf (o.[0].[2], 1.1 * 1.5) @>
    test <@ near.cf (o.[1].[1], 2.2 * 1.4) @>
    test <@ Vec_all (fun x -> x > 0.0) (vec3 0.1 0.1 0.1) @>

[<Test>]
let test_vec_diffs () =
    let fd = FiniteDiff(1e-5)
    let cf = Comparer(1e-4)
    let a = vec3 1.1 -2.2 3.1
    let b = vec2 0.1 0.2
    let s = -5.8
    test <@ cf.cf (fd.diff Vec_norm a, Vec_norm' a) @>
    test <@ cf.cf (fd.diff normalized a, normalized' a) @>
    test <@ cf.cf (fd.diff (fun x-> Vec_smul (s, x)) b, snd (Vec_smul' (s, b))) @>
    test <@ cf.cf (fd.diff (fun x-> Vec_smul (x, b)) s, fst (Vec_smul' (s, b))) @>

// Mat: Matrix expressed as vector of rows.
[<StructuredFormatDisplay("{Display}")>]
type Mat<'T>(v: Vec<Vec<'T>>) = 
    new(rows:int, cols:int, builder: int->int->'T) = Mat<'T>(Vec<Vec<'T>>(rows, fun i -> Vec<'T>(cols, builder i)))
    new(rows:int, cols:int, value:'T) = Mat<'T>(Vec<Vec<'T>>(rows, fun _->Vec<'T>(cols, fun _ -> value)))
    new(rows:int, cols:int, values:'T[]) = Mat<'T> (rows, cols, fun i j -> values.[i * cols + j])

    // Construct from array of tuples minimizes visual noise for literals.
    new(values:('T*'T)[]) = Mat<'T> (Vec<Vec<'T>>(values.Length, fun i -> new Vec<'T>(values.[i])))
    new(values:('T*'T*'T)[]) = Mat<'T> (Vec<Vec<'T>>(values.Length, fun i -> new Vec<'T>(values.[i])))
    new(values:('T*'T*'T*'T)[]) = Mat<'T> (Vec<Vec<'T>>(values.Length, fun i -> new Vec<'T>(values.[i])))
    new(values:('T*'T*'T*'T*'T)[]) = Mat<'T> (Vec<Vec<'T>>(values.Length, fun i -> new Vec<'T>(values.[i])))
    new(values:('T*'T*'T*'T*'T*'T)[]) = Mat<'T> (Vec<Vec<'T>>(values.Length, fun i -> new Vec<'T>(values.[i])))

    member this.v = v
    member this.rows = v.size
    member this.cols = v.[0].size

    member this.Item i = this.v.[i / this.cols].[i % this.cols]
    member this.Item (i:int, j:int) = this.v.[i].[j]
    member this.Display = "Mat[" + (Array.fold (fun s (v:Vec<'T>) -> s + "; " + v.ToString()) "" this.v.v) + "]"
    override this.ToString() = this.Display

/// Floating-point comparison helper
type Comparer with
    member this.cf (a:Mat<float>, b:Mat<float>):bool = this.cf (a.v,b.v)
    member this.cf (a:Vec<Mat<float>>, b:Vec<Mat<float>>):bool = Vec_all2 (fun (a:Mat<float>) (b:Mat<float>) -> this.cf (a,b)) a b

let mat (vv: Vec<Vec<'T>>) = Mat<'T>(vv)

let Mat_eye n = mat (Vec_eye n)

let Mat_zeros (rows:int) (cols:int) = Mat<float>(rows, cols, 0.0)

type R = float

type Arith = 
    // add: R * R -> R
    static member add (a:float, b:float): float = a + b
    // add': R * R -> R * R
    static member add' (a:float, b:float): float * float = (1.0, 1.0)

    // add: T * T -> T
    //static member add (a:'T*'S, b:'T*'S): 'T*'S = (Arith.add(fst a, fst b), Arith.add(snd a, snd b))
    static member add (a:R*R, b:R*R): R*R = (Arith.add(fst a, fst b), Arith.add(snd a, snd b))
    static member add (a:Vec<R>*Vec<R>, b:Vec<R>*Vec<R>): Vec<R>*Vec<R> = (Arith.add(fst a, fst b), Arith.add(snd a, snd b))
    static member add (a:Vec<Vec<R>>*Vec<Vec<R>>, b:Vec<Vec<R>>*Vec<Vec<R>>): Vec<Vec<R>>*Vec<Vec<R>> = (Arith.add(fst a, fst b), Arith.add(snd a, snd b))
    // add': R * R -> R * R
    //static member add' (a:'T*'S, b:'T*'S): 'T*'S = (Arith.add(fst a, fst b), Arith.add(snd a, snd b))
    
    
    // add Vec<R> Vec<R>
    static member add (a:Vec<float>, b:Vec<float>): Vec<float> = Vec_add (a,b)
    // Derivative add' (Vec<R> * Vec<R>) -> 
    static member add' (a:Vec<float>, b:Vec<float>): Vec<Vec<float>> * Vec<Vec<float>> = Vec_add' (a,b)
    
    // add Vec<R> Vec<R>
    static member add (a:Vec<Vec<float>>, b:Vec<Vec<float>>):Vec<Vec<float>> = map2 a b Arith.add
    // Derivative add' (Vec<R> * Vec<R>) -> 
    //static member add' (a:Vec<Vec<float>>, b:Vec<Vec<float>>):Vec<Vec<Vec<Vec<float>>>> * Vec<Vec<Vec<Vec<float>>>> = 
    
    // add: Mat<R> * Mat<R> -> Mat<R>
    static member add (a:Mat<float>, b:Mat<float>)= Mat<float>(map2 a.v b.v Arith.add)
    // add': Mat<R> * Mat<R> -> Mat<Mat<R>> * Mat<Mat<R>> 
    static member add' (a:Mat<float>, b:Mat<float>): Mat<Mat<float>> * Mat<Mat<float>> = 
        let m,n = a.rows, a.cols
        Mat<Mat<float>>(m, n, fun i j -> Mat<float>(m, n, fun i' j' -> sdelta (i,j) (i',j') 1.0)),
        Mat<Mat<float>>(m, n, fun i j -> Mat<float>(m, n, fun i' j' -> sdelta (i,j) (i',j') 1.0))

    // add: R * R -> R
    static member sub (a:float, b:float): float = a - b
    // add': R * R -> R * R
    static member sub' (a:float, b:float): float * float = (1.0, -1.0)
    
    // add Vec<R> Vec<R>
    static member sub (a:Vec<float>, b:Vec<float>): Vec<float> = Vec_sub (a,b)
    // Derivative add' (Vec<R> * Vec<R>) -> 
    static member sub' (a:Vec<float>, b:Vec<float>): Vec<Vec<float>> * Vec<Vec<float>> = Vec_sub' (a,b)
    
    // add: Mat<R> * Mat<R> -> Mat<R>
    static member sub (a:Mat<float>, b:Mat<float>)= Mat<float>(map2 a.v b.v Arith.sub)
    // add': Mat<R> * Mat<R> -> Mat<Mat<R>> * Mat<Mat<R>> 
    static member sub' (a:Mat<float>, b:Mat<float>): Mat<Mat<float>> * Mat<Mat<float>> = 
        let m,n = a.rows, a.cols
        Mat<Mat<float>>(m, n, fun i j -> Mat<float>(m, n, fun i' j' -> sdelta (i,j) (i',j') 1.0)),
        Mat<Mat<float>>(m, n, fun i j -> Mat<float>(m, n, fun i' j' -> sdelta (i,j) (i',j') -1.0))
 
    // mul: R * R -> R
    static member mul (a:float, b:float): float = a * b
    // mul': R * R -> R * R
    static member mul' (a:float, b:float): float * float = (b,a)
    
    // mul: R * Vec<R> -> Vec<R>
    static member mul (a:float, b:Vec<float>) = Vec_smul (a,b)
    // mul': R * Vec<R> -> Vec<R> * Vec<Vec<R>>
    static member mul' (a:float, b:Vec<float>) = Vec_smul' (a,b)
    
    // mul: R * Vec<R> -> Vec<R>
    static member mul (a:float, b:Vec<Vec<float>>) = Vec_map (fun (x:Vec<float>) -> Arith.mul (a,x)) b 
    // mul': R * Vec<R> -> Vec<R> * Vec<Vec<R>>
    //static member mul' (a:float, b:Vec<'T>) = Vec_smul' (a,b)

    // mul: R * Vec<R> -> Vec<R>
    static member mul (a:float, b:Mat<float>) = Mat(Arith.mul(a,b.v))
    // mul': R * Vec<R> -> Vec<R> * Vec<Vec<R>>
    //static member mul' (a:float, b:Vec<'T>) = Vec_smul' (a,b)

    // mul: R * Tuple<Vec<R>> -> Tuple<Vec<R>>
    static member mul (a:float, b:Vec<float> * Vec<float>) = Arith.mul (a, fst b), Arith.mul (a, snd b)
    static member mul (a:float, b:Vec<Vec<float>> * Vec<Vec<float>>) = Arith.mul (a, fst b), Arith.mul (a, snd b)
    
    // dot: Vec<R> * Vec<R> -> R
    static member dot (a:Vec<float>, b:Vec<float>) = Vec_dot (a,b)
    // dot': Vec<R> * Vec<R> -> Vec<R> * Vec<R>
    static member dot' (a:Vec<float>, b:Vec<float>) = Vec_dot' (a,b)

type FiniteDiff with

    // diff: (R->Vec<R>) -> (R->Vec<R>)
    // Tangent
    member this.diff (f:float->Mat<float>) = fun (x:float) -> Arith.mul (this.one_over_2delta, Arith.sub (f (x + this.delta), f (x - this.delta)))

    // diff: (Vec<R>->Vec<R>) -> (Vec<R>->Vec<Vec<R>>)
    // Jacobian
    member this.diff (f:Vec<float>->Mat<float>) = 
        fun (x:Vec<float>) -> Vec<Mat<float>>(x.size, fun i -> (this.diff (fun (h: float) -> f (Vec_add (x, Vec_ae x.size i h))) 0.0))

    
// No function overloading in F#
let VSmul (a:Vec<float>, b:float) = Vec<float>(a.size, fun i -> a.[i] * b)
let SVmul (a:float, b:Vec<float>) = Vec<float>(b.size, fun i -> a * b.[i])
let VVouter (a:Vec<float>, b:Vec<float>) = Mat<float>(a.size, b.size, fun i j -> a.[i] * b.[j])

let MSmul (a:Mat<float>, b:float) = Mat<float>(a.rows, a.cols, fun i j -> a.[i,j] * b)
let SMmul (a:float, b:Mat<float>) = Mat<float>(b.rows, b.cols, fun i j -> a * b.[i,j])

let diff_VSmul (a:Vec<float>, b:float) : (Vec<Vec<float>> * Vec<float>) = ((MSmul (Mat_eye(a.size), b)).v, a)
let diff_SVmul (a:float, b:Vec<float>) : (Vec<float> * Vec<Vec<float>>) = (b, (SMmul (a, Mat_eye(b.size))).v)

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

type GDot with
    // C2: Tv, C2C3: Tv<Vec>, C1C2: Tv<Vec>
    // C3: Vec, C1:  
    static member dot(c2:float * Vec<float>, c2c3:Vec<float> * Vec<Vec<float>>, c1c2: Vec<float> * Vec<Vec<float>>):Vec<Vec<float>> =
           Arith.add(GDot.dot(fst c2, fst c2c3, fst c1c2), GDot.dot(snd c2, snd c2c3, snd c1c2))

    // C2: S, C2C3: S, C1C2: D<V>
    static member dot(c2:float, c2c3:float, c1c2: Vec<float> * Vec<float>):Vec<float> * Vec<float> =
           GDot.dot(c2, c2c3, fst c1c2), GDot.dot(c2, c2c3, snd c1c2)

    // C2: Tv, C2C3: Tv<V>, C1C2: D<D<V,V>,D<VV,VV>>
    // transform to_vec_of_tuples, giving
    // C2: Tv, C2C3: Tv<V>, C1C2: D<D<V,V>,D<VV,VV>>
    static member dot(c2:float * Vec<float>, c2c3:Vec<float> * Vec<Vec<float>>, c1c2: (Vec<float> * Vec<float>) * (Vec<Vec<float>> * Vec<Vec<float>>)) =
           GDot.dot(c2, c2c3, (fst (fst c1c2), fst (snd c1c2))), GDot.dot(c2, c2c3, (snd (fst c1c2), snd (snd c1c2)))

    static member dot(c2:Vec<float>, c2c3:Vec<Vec<float>>, c1c2: Vec<Vec<float>> * Vec<Vec<float>>) =
           let d1 = GDot.dot(c2, c2c3, fst c1c2)
           let d2 = GDot.dot(c2, c2c3, snd c1c2)
           (d1, d2) 
           
    static member dot(c2:Vec<float> * Vec<float>, c2c3:Vec<Vec<float>> * Vec<Vec<float>>, c1c2: (Vec<Vec<float>> * Vec<Vec<float>>) * (Vec<Vec<float>> * Vec<Vec<float>>)) =
           let d1 = GDot.dot(fst c2, fst c2c3, fst c1c2)
           let d2 = GDot.dot(snd c2, snd c2c3, snd c1c2)
           Arith.add(d1, d2) 

    static member dot(c2:Vec<float> * Vec<float>, c2c3:Vec<float> * Vec<float>, c1c2: (Vec<Vec<float>> * Vec<Vec<float>>) * (Vec<Vec<float>> * Vec<Vec<float>>)) =
           GDot.dot(c2, c2c3, to_vec_of_tuples (fst c1c2)), GDot.dot(c2, c2c3, to_vec_of_tuples (snd c1c2)) 

    static member dot(c2:float * float, c2c3:float * float, c1c2: Vec<Vec<float>> * Vec<Vec<float>>) =
           let d1 = Arith.mul(fst c2c3, fst c1c2)
           let d2 = Arith.mul(snd c2c3, snd c1c2)
           Arith.add(d1, d2) 

    // C2: DV, C2C3: DVV => C3 = V; C1C2: DVV
    static member dot(c2:Vec<float> * Vec<float>, c2c3:Vec<Vec<float>> * Vec<Vec<float>>, c1c2: Vec<Vec<float>> * Vec<Vec<float>>) =
           GDot.dot(c2, c2c3, to_vec_of_tuples c1c2) 

    static member dot(c2:float * float, c2c3:float * float, c1c2: Vec<float> * Vec<float>) =
           let d1 = Arith.mul(fst c2c3, fst c1c2)
           let d2 = Arith.mul(snd c2c3, snd c1c2)
           Arith.add(d1, d2) 

    static member dot(c2:float * float, c2c3:float * float, c1c2: (Vec<Vec<float>> * Vec<Vec<float>>) * (Vec<Vec<float>> * Vec<Vec<float>>)) =
           let d1 = GDot.dot(c2, c2c3, fst c1c2)
           let d2 = GDot.dot(c2, c2c3, snd c1c2)
           Arith.add(d1, d2) 

    static member dot(c2:float * float, c2c3:float * float, c1c2: (Vec<float> * Vec<float>) * (Vec<float> * Vec<float>)) =
           let d1 = Arith.mul(fst c2c3, fst c1c2)
           let d2 = Arith.mul(snd c2c3, snd c1c2)
           Arith.add(d1, d2) 
                                            










                                                      
// Uncurried version ... I can see a few ways to do it, but all require a function to be packaged with its derivative, and then what about higher derivatives?
//let cmul (a:Vec<'T>) = fun (b:'T) -> Vec<'T>(a.size, fun i -> a.[i] * b)
//let diff_cmul (a:Vec<'T>) = 

//let f v = 
//    let v0 = Vec<float> (3, 0.0)
//    let u = Vec<float> (3, [|1.0; 2.0; 3.0|])
//    let t1 = mul u 2.0
//    t1



// reminder: toby says windows used dps

