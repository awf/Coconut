
### Destination-passing Style

This is a brief overview of our paper Shaikhha et al, "Destination-passing style for efficient memory management", SIGPLAN FHPC 2017.
[ACM](https://dl.acm.org/citation.cfm?id=3122949), 
[PDF](https://www.microsoft.com/en-us/research/wp-content/uploads/2016/11/dps-submitted.pdf).

Lots of work exists on compilation of high-level functional languages such as Haskell or F# to native code, and in some cases, benchmarks show competitive efficiency with handwritten low-level code.   However there remain cases where the compiled code has significant overhead due to dependence on garbage collection and heap memory management.  These include important real-world scenarios with numerical workloads, such as computer vision, VR/AR, and AI/machine learning. 
Such workloads may do lots of matrix/vector math, with lots of temporary array variables.  Of course some temporaries can be eliminated by loop fusion, but many must remain (e.g. a temporary is used multiple times, so it would be expensive to recompute it) and they incur the costs of heap allocation.

The goal of DPS is to minimize dependency of the executable code on garbage collection (GC) or heap allocation.  The key idea is that when a function returns a large object, such as an array, the space for the returned value is allocated by the _caller_ rather than the called function.   This opens many opportunities for stack allocation, leading to much more efficient code.  But there's a but: in general we can't compute the space needed for the result without computing the result.  We will handle that problem below, but first let's look at a concrete example.

Let's see an example function `main`, which takes vectors a,b,c and computes ‖(a+b)+c‖.

```julia
function vadd(a::Vector,b::Vector)::Vector;
function norm(a::Vector)::Real;

function main(a::Vector,b::Vector, c::Vector)::Real
    norm(vadd(vadd(a, b), c))
end
```

The function `vadd` implements vector addition, and for the purposes of our example has a peculiar implementation where if the vectors have different sizes, it pads the shorter one with zeros.    Its C++ code looks something like this.  (Ignore the trivial optimization opportunities.)

```c++
struct Vector { size_t size; double* data }; // Small fixed struct, can return in registers/on stack

Vector vadd(Vector a, Vector b)
{
    double* out = gcnew double[max(a.size, b.size)];   // Allocate space for the return value on the GC heap
    vadd_blas(min(a.size,b.size), a.data, b.data, out);  // vadd_blas is some efficient implementation
    std::fill(out + min(a.size, b.size), out + max(a.size, b.size), 0.0);
    return Vector {max(a.size,b.size), out};
}
```

Therefore calling main above involves two calls to gcnew, and incurs garbage collector overhead to clean up the memory.   One can use region allocators and lifetime analysis to turn this into simpler heap allocation or bump allocation, but this simply localizes the memory management overhead.  Instead DPS is a simple transformation that cleanly yields efficient memory management.

Imagine that the writer of `vadd` had kindly supplied a function which computed the size of `vadd`'s result:

```c++
size_t vadd_size(Vector a, Vector b)
{
   return max(a.size, b.size);
}
```

And another version `vadd_dps` which takes a pre-sized result buffer

```c++
Vector vadd_dps(void* buf, Vector a, Vector b)
{
    double* out = (double*)buf; // Function body exactly as before, but no alloc in vadd.
    vadd_blas(min(a.size,b.size), a.data, b.data, out);  
    std::fill(out + min(a.size, b.size), out + max(a.size, b.size), 0.0);
    return Vector {max(a.size,b.size), out};
}
```


Then we could eliminate all heap allocations in main using alloca:

```c++
double main(Vector a, Vector b)
{
    Vector tmp1 = vadd_dps(alloca<double>(vadd_size(a,b)), a, b);
    Vector tmp2 = vadd_dps(alloca<double>(vadd_size(tmp1,c)), tmp1, c);
    vadd_dps(&tmp1, tmp2, c);
    return norm(tmp2);
}
```

Even if we can't use alloca, maybe because stack space is limited, we can eliminate GC in main using explicit heap allocation:

```c++
double main(Vector a, Vector b)
{
    Vector tmp1 = vadd_dps(new double[vadd_size(a,b)], a, b);
    Vector tmp2 = vadd_dps(new double[vadd_size(tmp1,c)], tmp1, c);
    double ret = norm(tmp2);
    delete [] tmp2.data;
    delete [] tmp1.data;
    return ret;
}
```

Now, there  are perennial arguments of the form "GC is faster than "new/delete", but notice here that the allocator can be a bump allocator, so the arguments for GC/regions do not apply.

So, what a lovely story.  There's one problem though.  The writer of the `vadd` function *didn't* give us `vadd_size`, just `vadd`.  And in general it's impossible to determine the result size for an arbitrary block of 3rd party code.  OK, but we can still write `vadd_size`, just inefficiently:

```c++
size_t vadd_size(Vector a, Vector b)
{
    Vector tmp = vadd(a,b);  // Call vadd
    size_t ret = tmp.size;
    gcdelete tmp.data; // We know we don't need it, so it could have been bump-allocated
    return ret;
}
```

And of course, we could use new/delete, or a bump allocator.  What's more, when the compiler tries to inline `vadd` in `vadd_size`, the fact that tmp.data is never accessed allows dead code elimination to remove the call to `vadd_blas` (remember we're compiling *to* C++, so the semantics are defined by the source language, which has referential transparency, i.e. can make assumptions about side effects).   Similarly `vadd_dps` has an inefficient implementation

```c++
void vadd_dps(Vector* out, Vector a, Vector b)
{
   Vector tmp = vadd(a,b);
   std::copy(tmp.data, tmp.data+tmp.size, out->data);
   gcdelete tmp.data;
}
```

Again, the copy and allocations can be removed by DCE.  So, what's the point?   We seem to have just made `vadd` less efficient, and any gains we talk about could have been made by inlining `vadd` in main.

The point is this: when compiling `vadd`, we can easily compile and optimize `vadd_size` and `vadd_dps`, without cross-module inlining.   When a caller sees `vadd`, it can observe the existence of the `_size` and `_dps` variants, and know that stack-discipline allocation will yield more efficient code.  This will mean less stuff on the GC heap, and less GC overhead.  With careful subsetting of the source language (and with the introduction of an explicit `gcnew` or `new/delete` in the source), we can compile many sensible programs from a functional language such as F# to non-garbage-collected C.

### Examples.   

[Here](https://github.com/awf/Coconut/blob/master/Examples/GMM/FSmooth/usecases_gmm.fs) is a piece of F# to compute the log-likelihood of a Gaussian Mixture model, which is a canonical machine learning model.  Slightly more old fashioned than a deep neural network, but with arguably more interesting code complexity.  And this compiles to non-GC C (see [here](https://github.com/awf/Coconut/blob/master/outputs/C/usecases_gmm_opt.h)), so can be directly incorporated into projects with no runtime, so we get the joy of functional programming while being another step closer to optimal performance.

### Related work

We didn't invent DPS, we just used it for F#.  It is a technique with a long history. From an Aaron Turon blog post: In a 1998 paper, Yasuhiko Minamide studied an idea that has come to be known as "destination-passing style".  There, a common special case of continuation-passing was noticed, where the continuation's only job was to allocated a cons cell.
It was also common in the early windows APIs to have a call `foo_size` which would report the buffer size needed for `foo`. 

### Limitations, future work

In the paper linked above, we didn't talk about F#, but a simpler language F~ (pronounced "F smooth").  That was so we could prove that `foo_size` would compile to an O(1) operation.   However, this isn't necessary in general.  Even if the function is complicatedly recursive (e.g. an array of Ackerman size), we can indeed compute the size first, and then fill the array.  It may cost twice as much, but look at the alternatives: build a list or tree, then convert to an array?    In some cases that will be the better way to go, in some cases the 2x cost of precomputing the size will be better.

Also, as written F~ doesn't allow for _any_ heap allocation, so you can't create a linked list.  This is easily overcome by adding a `new` operator to the language which makes explicit when heap allocation occurs.  This can be paired with manual memory management, smart pointers, or full GC, just as C++ programmers choose today.  The point is that the numerical parts of the program can be fast, while the remainder is no slower than today.

