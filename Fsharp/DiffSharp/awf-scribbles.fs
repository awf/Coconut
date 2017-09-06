module awf_scribbles

open linalg
open corelang
open types
open utils

let add_vec_dp (s: Storage) (x: Vector) (y: Vector) =
    vectorMap2GivenStorage s (+) x y

// User's function: leaky
let rod (r:Vector) (v:Vector) : Vector = 
  add_vec (add_vec r v) v

// First rewrite to create rod_dp
// still leaky
let rod_dp (s:Storage) (r:Vector) (v:Vector) : Vector = 
  add_vec_dp s (add_vec r v) v

// Rewrite using:
//           APPLY %F %args ==> let s = alloc N in APPLY %F_dp s %args   /* For F "returning large object" */
// still leaky
let rod_dp_2 (s:Storage) (r:Vector) (v:Vector) : Vector = 
  add_vec_dp s (let s1 = vectorAlloc 10 in add_vec_dp s1 r v) v

// Rewrite using:
//           (\x. B x) (let %s = alloc %i in %e)   ==> let %s = alloc %i in ((\x. B x) %e)
// worse than leaky... uses freed memory
let rod_dp_2a (s:Storage) (r:Vector) (v:Vector) : Vector = 
  add_vec_dp s (vectorAllocCPS 10 (fun s1 -> add_vec_dp s1 r v) v)

// Rewrite:
//           (\x. B x) (let %s = alloc %i in %e)   ==> let %s = alloc %i in ((\x. B x) %e)
// still leaky
let rod_dp_3 (s:Storage) (r:Vector) (v:Vector) : Vector = 
  let s1 = vectorAlloc 10 in add_vec_dp s (add_vec_dp s1 r v) v

// Rewrite:
//           let %s = alloc %i in %e   ==> vectorAllocCPS %i (fun %s -> %e)
// No leak.  vectorAllocCPS  is returning the reference to s that we expect any _dp 
// to return, and all the local allocs are accounted for.
let rod_dp_4 (s:Storage) (r:Vector) (v:Vector) : Vector = 
  vectorAllocCPS 10 (fun s1 -> add_vec_dp s (add_vec_dp s1 r v) v)

// Need polymorphic vectorAllocCPS, but not polyadic.
// Polymorphism can easily be implemented by renaming over the existing types.
// When vector types are returned, they are returned using exactly the
// semantics of all other vector returners, e.g. build, build_dp
let vectorAllocCPS (size: Index) (cont: Storage -> 'a): 'a =
  let storage = vectorAlloc(size)
  cont(storage)

//----------------------------------------------------
// A marker for leaky functions (or could match %F without trailing _dp)
let leaker x = x

// First rewrite to create rod_dp
// still leaky
let rod_dp (s:Storage) (r:Vector) (v:Vector) : Vector = 
  add_vec_dp s (leaker (add_vec r v)) v

// now (\x. B x) (leaker (APP %f %args))   ==>    vectorAllocCPS N (\s. B (APP %f"_dp" s %args))
let rod_dp (s:Storage) (r:Vector) (v:Vector) : Vector = 
  vectorAllocCPS N (fun s1 -> add_vec_dp s (add_vec_dp s1 r v) v)



// A tail-recursive function with internal calls possibly returning different sized vectors
let rec f (x : Vector) (n : int) : Vector = if n == 1
                                            then build 3 (fun i -> 1.0f) 
                                            elif n == 2
                                            then build 4 (fun i -> 1.0f)
                                            else f x (n / 2) // this either recurses to one or the other, but storage can't change
// Note that with f_sz taking f's original args, the storage computation works fine.

// General recursion
let rec f (x : Vector) (n : int) : Vector = 
    if n == 0
    then x
    else add (f x (n-1)) x

// ->DPS
let rec f_dp (s : Storage) (x : Vector) (n : int) : Vector = 
    if n == 0
    then copy(s, x)
    else add_dp s (f x (n-1)) x
// Which independently will be deleaked to 
let rec f_dp (s : Storage) (x : Vector) (n : int) : Vector = 
    if n == 0
    then copy(s, x)
    else alloc (f_sz x (n-1)) (fun s1 -> add_dp s (f_dp s1 x (n-1)) x)


let rec f_sz (x : Vector) (n : int) : Vector = 
    if n == 0
    then x.size
    else (add (f x (n-1)) x).size
// and without any "optimizing" rewrites, this becomes
let rec f_sz (x : Vector) (n : int) : Vector = 
    if n == 0
    then x.size
    else (add (f x (n-1)) x).size


// after rewrite
let rec f_sz (x : Vector) (n : int) : Vector = 
    if n == 0
    then x.size
    else add.sz (f x (n-1)) x
// after rewrite
let rec f_sz (x : Vector) (n : int) : Vector = 
    if n == 0
    then x.size
    else add.sz (f x (n-1)) (f x (n/2))
// after rewrite
let rec f_sz (x : Vector) (n : int) : Vector = 
    if n == 0
    then x.size
    else add.sz (f x (n-1)) (f x (n/2))

//------------------------------------------------

// General recursion
let rec f x n = 
    let v = build n foo
    if n == 0
    then x
    else add (f x (n-1)) x

//=-----------------------------------
// Accidentally recursive build.
//=-----------------------------------
let copy_dp (s:Storage) (v:Vector) : Vector = build_dp s (fun i -> v.[i])
let copy_sz (v:Vector) = v.size

let g v =
  v
// DPS:
let g_dp s v =
  copy_dp s v
let g_sz v =
  v.size

let rec f n : Vector =
    if n == 0
    then zeros 1
    else push n (letalloc s (f_sz (n-1)) g (f_dp s  (n-1)))



let rec f_sz n = 
    if n == 0
    then 1
    else 1 + (g_sz (f (n-1))) // simplifies, with inlining, to (f (n-1)).size -> (f_sz (n-1))
// or fails to simplify..
// First move f to explicit lets
let rec f n : Vector =
    if n == 0
    then zeros 1
    else 
      let tmp0 = sub n 1
      let tmp1 = f tmp0
      let tmp2 = g tmp1
      push n tmp2
// Now compute sizes
let rec f_sz n : Vector =
    if n == 0
    then zeros_sz 1
    else
      let tmp1 = f (n-1)
      let tmp2 = g tmp1
      push_sz n tmp2
// Now don't do any optimization, but deleak..
let rec f_sz n : Vector =
    if n == 0
    then zeros_sz 1
    else
      let tmp1 = f (n-1)
      letalloc s2 (g_sz tmp1)
      let tmp2 = g_dp s2 tmp1
      push_sz n tmp2
let rec f_sz n : Vector =
    if n == 0
    then zeros_sz 1
    else
      letalloc s1 (f_sz (n-1))
      let tmp1 = f_dp s1 (n-1)
      letalloc s2 (g_sz tmp1)
      let tmp2 = g_dp s2 tmp1
      push_sz n tmp2


// Transform to DPS
let rec f_dp s n = 
    letalloc s1 (f_sz (n-1))  // Safe but possibly conservative
      if n == 0
      then zeros_dp s 1
      else push_dp s n (g (f_dp s1 (n-1)))



// First move f to ANF
let rec f n : Vector =
    letalloc s4 (h_sz n)
    let tmp4 = h_dp s4 n
    let tmp5 = norm tmp4
    if tmp5 == 0
    then zeros 1
    else 
      let tmp0 = sub n 1
      let tmp1 = f tmp0
      let tmp2 = g tmp1
      push n tmp2
