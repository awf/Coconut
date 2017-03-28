#pragma once

#include "template_utils.h"
#include "container_depth.h"

// FILE: dot.h
//
// Implement generalized dot product over containers of containers.
// The general form of dot or contraction over container C2 is:
//
//     C1<C3<Real>> gdot(C1<C2<Real>>, C2<C3<Real>>)
//
// where each entry of the return value is an accumulation of
//     Real * C3<Real> (assumed to return a C3<Real>)
// over all elements of the C2s.
//
// Implementation is somewhat hairy as we must deal with cases where any
// of the Cs could be nested containers, e.g. 
//    gdot(list<bag< pack<vec<Real>> >>, pack<vec< mat<bundle<Real>> >>)
// where:
//    C1 is a list<bag<.>>
//    C2 is a pack<vec<.>>
//    C3 is a mat<bundle<.>>
//
// Further complexity arises because we can't automatically infer which
// container is C2 (imagine the case when all are vec<vec<.>>, so C2 could
// be vec<.>, vec<vec<.>>, or vec<vec<vec<.>>> by simple pattern matching,
// so the caller must indicate it.
//
// There are a few ways to indicate this: you can pass the depths of the 
// containers, as done in the auxiliary Dotter class below, or, sometimes
// more conveniently, you can pass a third argument of type C1<Real>. 
// As our primary usage is for mplementing the chain rule on containers, 
// you will probably have an instance of C1<Real> anyway, arising from a call 
// sequence like this:
//   C1<Real> x;
//   C2<Real> fx = f(x);
//   C3<Real> hx = h(fx);
//
//   C1<C2<Real>> grad_fx = grad_f(x);
//   C2<C3<Real>> grad_hfx = grad_h(fx);
//   C1<C3<Real>> grad_hx = gdot(grad_fx, grad_hfx, x); // Third arg specifies C1.

// Implementing dot product between a
//    Foo<Gar<Bee<Cee<Real>>>> f
// and a 
//    Bee<Cee<Dee<Eee<Real>>>> g
// when we know the container over which we must multiply-accumulate is the Bee<Cee>
// because we have
//    Bee<Cee<Real>> g_val;
//
// The output will be a 
//    Foo<Gar<.>> of Dee<Eee<Real>>
// So the dotting will ultimately involve products Real*Dee<Eee<Real>>
// The dotter needs information like:
//   N    the depth of the Foo<Gar<.>> up as far as the Bee<Cee<.>>
//   M    the depth of Bee<Cee<.>> 
//
//  The out parameter is appropriately sized and zero-filled before the call.
//
//  OPERATION:
//  Simple recursion down N first, to strip the Foo<Gar<.>> container
//  Then down M to accumulate the dot products.
//
//  Thus the sequence of calls in our FGBC example should be:
//
//   <2,2>(FGBC, BCDE, FGDE*) ... (*out)[i] = GDE() = dot<1,2>:
//   <1,2>(GBC, BCDE, GDE*)   ... (*out)[i] = DE()
//   <0,2>(BC, BCDE, DE*)     ... (*out) += dot(C, CDE)
//   <0,1>(C, CDE, DE*)       ... (*out) += Real*DE = dot<0,0>
//   <0,0>(Real, DE, DE*)       ... (*out) = Real*DE
//
//  Other examples:
//   <1,0>(Vec<Real>, Real, V<R>*)  (*out)[i] += a[i]*b

// Notes:
// 1. Has general form 
//     dot(C1<C2<Real>>, C2<C3<Real>>) -> C1<C3<Real>>
//    and by stripping C1s, get to 
//     dot(C2<Real>, C2<C3<Real>>) -> C3<Real>
//    and by dotting through C2s, get to 
//     dot(Real, C3<Real>) -> C3<Real>
// 2. Can't use template templates because number of template parameters need to match,
//    i.e. a Vec<typename, size_t, typename> can't match a "template Container<typename>".
//    There are so many ways on might need to use those that we just can't....
// 3. For safety (i.e. decent error messages), maybe make user define dot00?

// Unspecialized template: N > 0
template <int N, int M, class C1_of_C2, class C2_of_C3>
struct Dotter {

  // Type of RestOfC1_of_C2_of_Real
  // This assumes 
  typedef typename get_value_type<C1_of_C2>::type RestOfC1_of_C2_of_Real;

  // Type of dot(a[0], b), RestOfC1_of_C3_Real
  typedef typename Dotter<N - 1, M, RestOfC1_of_C2_of_Real, C2_of_C3>::dot_t RestOfC1_of_C3_Real;

  // Type of dot(a, b)
  typedef decltype(std::declval<C1_of_C2>().shape_clone<RestOfC1_of_C3_Real>()) dot_t;

  // Function dot: Third arg is already-constructed output type
  static void dot3(C1_of_C2 const& a, C2_of_C3 const& b, dot_t* out)
  {
    auto ia = std::begin(a);
    auto iout = std::begin(*out);
    for (; ia != std::end(a); ++ia, ++iout)
      Dotter<N - 1, M, RestOfC1_of_C2_of_Real, C2_of_C3>::dot3(*ia, b, &*iout);
  }

  // dot(Foo<RestOfC1<C2<Real>>, C2<C3<Real>>) -> Foo<RestOfC1<C3<Real>>
  //    calls dot(RestOfC1<C2<Real>>, C2<C3<Real>>) -> RestOfC1<C3<Real>
  static dot_t dot(C1_of_C2 const& a, C2_of_C3 const& b)
  {
    // Create output container, Foo<RestOfC1_of_C3_of_Real> 
    // same shape as Foo<RestOfC1_of_C2_of_Real> but containing RestOfC1_of_C3_of_Real
    dot_t out = a.shape_clone<RestOfC1_of_C3_Real>();
    deep_fill(&out, Real{ 0 });
    dot3(a, b, &out);
    return out;
  }
};

// Specialization for N==0, so we have
//     dot(C2<Real>, C2<C3<Real>>) -> C3<Real>
template <int M, class C2_of_Real, class C2_of_C3_of_Real>
struct Dotter<0, M, C2_of_Real, C2_of_C3_of_Real>
{
  // INFERRING
  //     dot(Head2_RestOfC2<Real>>, Head2_RestOfC2<C3<Real>>) -> C3<Real>
  //   calls
  //        dot(RestOfC2<Real>>, RestOfC2<C3<Real>>) -> C3<Real>
  //     

  // Type of RestOfC2_of_Real
  typedef typename get_value_type<C2_of_Real>::type RestOfC2_of_Real;

  // Type of RestOfC2_of_C3_of_Real
  typedef typename get_value_type<C2_of_C3_of_Real>::type RestOfC2_of_C3_of_Real;

  // Return type of inner dotter call
  typedef typename Dotter<0, M - 1, RestOfC2_of_Real, RestOfC2_of_C3_of_Real>::dot_t InnerDotter_t;

  // Return type of our dot()
  typedef InnerDotter_t dot_t;

  static void dot3(C2_of_Real const& a, C2_of_C3_of_Real const& b, dot_t* out)
  {
    // Don't zero "out" here, it was created as zero.
    // This way we can continually accumulate into it until we exhaust C2.
    auto ia = std::begin(a);
    auto ib = std::begin(b);
    for (; ia != std::end(a); ++ia, ++ib)
      Dotter<0, M - 1, RestOfC2_of_Real, RestOfC2_of_C3_of_Real>::dot3(*ia, *ib, out);
  }

  // Declare dot itself
  static dot_t dot(C2_of_Real const& a, C2_of_C3_of_Real const& b)
  {
    dot_t out = numeric_traits<dot_t>::zeros_of_shape(dot_t());
    dot3(a, b, &out);
    return out;
  }
};

// Base case: M=N=0
//     dot(Real, C3<Real>) -> C3<Real>
template <class Real, class C3_of_Real>
struct Dotter<0, 0, Real, C3_of_Real>
{
  typedef C3_of_Real dot_t;

  static void dot3(Real const& a, C3_of_Real const& b, C3_of_Real* out)
  {
    *out += a * b;
  }

  static C3_of_Real dot(Real const& a, C3_of_Real const& b)
  {
    return a * b;
  }
};

template <class C1_of_C2_of_Real, class C2_of_C3_of_Real, class C1_of_Real>
struct dot_inferring_helper {
  static constexpr size_t C1_depth = CONTAINER_DEPTH(C1_of_Real, Real);
  static constexpr size_t C1_C2_depth = CONTAINER_DEPTH(C1_of_C2_of_Real, Real);
  static constexpr size_t C2_depth = C1_C2_depth - C1_depth;
  static constexpr size_t C2_C3_depth = CONTAINER_DEPTH(C2_of_C3_of_Real, Real);
  static constexpr size_t C3_depth = C2_C3_depth - C2_depth;

  static_assert(C2_C3_depth >= 0, "C2_C3_depth > 0");
  static_assert(C1_C2_depth >= 0, "C2_depth > 0");
  static_assert(C1_depth >= 0, "C1_depth > 0");

  typedef Dotter<C1_depth, C2_depth, C1_of_C2_of_Real, C2_of_C3_of_Real> dotter_t;

  typedef typename dotter_t::dot_t dot_t;

  static dot_t dot(C1_of_C2_of_Real const& a, C2_of_C3_of_Real const& b) {
    return dotter_t::dot(a, b);
  }
};

// FUNCTION: gdot
// Dot over (Container1<Container<Real>>, Container<Container3<Real>> using a tag of type Container1<Real> to show the depths.
template <class A, class B, class C>
static auto gdot(A const& a, B const& b, C const& c) ->
typename dot_inferring_helper<A, B, C>::dot_t
{
  return dot_inferring_helper<A, B, C>::dot(a, b);
}

// FUNCTION: gdot
// Dot over (Container1<Container<Real>>, Container<Container3<Real>> using type Container1<Real> 
template <class Container1_of_Real, class A, class B>
static auto gdot(A const& a, B const& b) ->
typename dot_inferring_helper<A, B, Container1_of_Real>::dot_t
{
  return dot_inferring_helper<A, B, Container1_of_Real>::dot(a, b);
}
