#pragma once

#include <iterator>
#include <cassert>
#include <array>
#include <vector>
#include <iostream>
#include <math.h>

// #include <boost/static_assert.hpp>

// TODO better inference of scalars vs containers..
typedef double Real;

#if EIGEN
#include <Eigen/Dense>

typedef long cardinality_t; 


template <class T>
using Vec = Eigen::Matrix<T, Eigen::Dynamic, 1>;

template <class T, size_t Size>
using VecF = Eigen::Matrix<T, Size, 1>;

template <class T>
using Vec2 = VecF<T, 2>;

template <class T>
using Vec3 = VecF<T, 3>;

template <class Derived>
inline auto max(Eigen::DenseBase<Derived> const& v)
{
  return v.maxCoeff();
}

template <class Derived>
inline auto sum(Eigen::DenseBase<Derived> const& v)
{
  return v.sum();
}

template <class Derived>
inline auto sumsq(Eigen::MatrixBase<Derived> const& v)
{
  return v.squaredNorm();
}

template <class Derived1, class Derived2>
inline auto cross(Eigen::MatrixBase<Derived1> const& u, Eigen::MatrixBase<Derived2> const& v)
{
  return u.cross(v);
}

template <class Derived1, class Derived2>
inline auto dot(Eigen::MatrixBase<Derived1> const& u, Eigen::MatrixBase<Derived2> const& v)
{
  return u.dot(v);
}

template <class Derived>
inline auto operator-(Eigen::MatrixBase<Derived> const& v, Real u)
{
  return (v.array() - u).matrix();
}

template <class Derived>
inline auto exp(Eigen::MatrixBase<Derived> const& v)
{
  return exp(v.array()).matrix();
}


template <typename Iter, typename T>
void vcopy(Iter p, T t)
{
  *p = t;
}

template <typename Iter, typename T, typename... Ts>
void vcopy(Iter p, T t, Ts... ts)
{
  *p++ = t;
  vcopy(p, ts...);
}


// FUNCTION: vec
// Create vector from argument list
template <typename T, typename... Ts>
auto vec(T t, Ts ... ts) -> VecF<T, 1 + sizeof...(Ts)> {
  VecF<T, 1 + sizeof...(Ts)> v;
  vcopy(v.data(), t, ts...);
  return v;
}

#else
#include "copy.h"
#include "counting_iterator.h"

#include "Zero.h"

typedef size_t cardinality_t; 

///////////////---------------------------

template <typename T>
struct numeric_traits {
  static T zero() {
    return T{ 0 };
  }
  static T zeros_of_shape(T const& that) {
    return T{ 0 };
  }
};

template <typename U, typename V>
struct numeric_traits_binary {
  typedef U result_of_add;
  typedef U result_of_mul;
};

struct numeric_traits_binary_double {
  typedef double result_of_add;
  typedef double result_of_mul;
};

template <>
struct numeric_traits_binary<double, int> : public numeric_traits_binary_double { };

template <>
struct numeric_traits_binary<int, double> : public numeric_traits_binary_double { };

template <>
struct numeric_traits_binary<double, double> : public numeric_traits_binary_double { };

///////////////---------------------------

// ContentsTag

// Vector contents tag: general
struct Vec_GE {}; 

// Vector contents tag: Nth basis vector, i.e. the vector v[N] = 1, otherwise 0;
template <int N>
struct Vec_BV {};

template <class Vec_U, class Vec_V>
struct CT_traits {
  typedef Vec_GE result_of_add;
  typedef Vec_GE result_of_mul;
};

///////////////---------------------------


// Vector: possibly variable size, possibly special contents
template <class T, int Size = 0, class ContentsTag = Vec_GE>
struct Vec;

// Fixed-size vector, general contents
template <class T, int Size>
struct Vec<T, Size, Vec_GE> {
  typedef T value_type;

  // Vec()
  Vec() {}

  // Vec(size_t)
  explicit Vec(size_t size) { assert(size == Size); }

  // Vec(size_t)
  Vec(size_t size, T const& val) 
  {
    assert(size == Size); 
    std::fill(storage.begin(), storage.end(), val);
  }

  // Vec(Vec)
  template <class U, int S, class C>
  Vec(Vec<U, S, C> const& that) {
    assert(that.size() == size());
    std::copy(that.begin(), that.end(), storage.begin());
  }

  // Vec =(Vec)
  template <class U, int S, class C>
  Vec& operator=(Vec<U, S, C> const& that) {
    assert(Size == that.size());
    std::copy(that.begin(), that.end(), storage.begin());
    return *this;
  }

  // Vec +=(Vec)
  template <class U, int ZU, class CU>
  Vec<T, Size, Vec_GE>& operator+=(Vec<U, ZU, CU> const& that) {
    assert(size() == that.size());
    for (size_t i = 0; i < size(); ++i)
      (*this)[i] += that[i];
    return *this;
  }

  // Vec +=(T)
  Vec<T, Size, Vec_GE>& operator+=(T const& that) {
    assert(size() == that.size());
    for (size_t i = 0; i < size(); ++i)
      (*this)[i] += that;
    return *this;
  }

  template <size_t start_index, size_t end_index>
  auto segment_start_end() const {
    // BOOST_STATIC_ASSERT(end_index < Size);
    Vec<T, end_index - start_index + 1, Vec_GE> out;
    for (size_t i = 0; i < out.size(); ++i)
      out[i] = (*this)[start_index + i];
    return out;
  }

  template <size_t n>
  auto segment(size_t start_index) const {
    assert(start_index + n <= Size);
    Vec<T, n, Vec_GE> out;
    for (size_t i = 0; i < n; ++i)
      out[i] = (*this)[start_index + i];
    return out;
  }

  template <size_t sz>
  auto head() const {
      return segment<sz>(0);
  }

  // size()
  size_t size() const { return Size; }

  // Vec [size_t]
  T& operator[](size_t i) { return storage[i]; }
  T const& operator[](size_t i) const { return storage[i]; }

  // Vec shape_clone()
  // A vector of the same size, elements uninitialized
  template <class S>
  Vec<S, Size, Vec_GE> shape_clone() const { return Vec<S, Size, Vec_GE>(); }

  // A vector of the same size, elements initialized to zero
  Vec<Zero, Size> zeroed_clone() const { return Vec<Zero, Size>(Size); }

  typedef typename std::array<T, Size>::const_iterator const_iterator;
  typedef typename std::array<T, Size>::iterator iterator;

  iterator begin() { return storage.begin(); }
  iterator end() { return storage.end(); }
  const_iterator begin() const { return storage.begin(); }
  const_iterator end() const { return storage.end(); }

  //private:
  //template <class U1, size_t Size1, class CT1> friend struct Vec<U1,Size1,CT1>;

  std::array<T, Size> storage;
};

// Variable-size vector, general contents
template <class T>
struct Vec<T, 0, Vec_GE> {
  typedef T value_type;

  // Vec(size_t)
  explicit Vec(size_t n) : storage(n) {}

  // Vec(size_t)
  Vec(size_t n, T const& val) : storage(n, val) {}

  // Vec(Vec&&)
  Vec(Vec<T, 0, Vec_GE>&& that) : storage(that.storage) {}
  // Vec(Vec const&)
  Vec(Vec<T, 0, Vec_GE> const& that) : storage(that.storage) {}

  // Vec(Vec)
  template <class U, int S, class C>
  Vec(Vec<U, S, C> const& that): storage(that.size()) {
    std::copy(that.begin(), that.end(), storage.begin());
  }

  // Vec =(Vec)
  template <class U, int S, class C>
  Vec& operator=(Vec<U, S, C> const& that) {
    assert(size() == 0 || size() == that.size());
    storage.resize(that.size());
    std::copy(that.begin(), that.end(), storage.begin());
    return *this;
  }

  Vec& operator=(Vec<T, 0, Vec_GE>&& that) {
    storage = that.storage;
    return *this;
  }

  // size_t size()
  size_t size() const { return storage.size(); }

  // Vec[size_t]
  T& operator[](size_t i) { return storage[i]; }
  T const& operator[](size_t i) const { return storage[i]; }

  template <size_t start_index, size_t end_index>
  auto segment_start_end() const {
    // BOOST_STATIC_ASSERT(end_index < Size);
    Vec<T, end_index - start_index + 1, Vec_GE> out;
    for (size_t i = 0; i < out.size(); ++i)
      out[i] = (*this)[start_index + i];
    return out;
  }

  template <size_t n>
  auto segment(size_t start_index) const {
    assert(start_index + n <= size());
    Vec<T, n, Vec_GE> out;
    for (size_t i = 0; i < n; ++i)
      out[i] = (*this)[start_index + i];
    return out;
  }



  Vec<T>& operator+=(Vec<T> const&);

  template <class S>
  Vec<S, 0, Vec_GE> shape_clone() const { return Vec<S, 0, Vec_GE>(size()); }
 
  /**
  template <class S>
  Vec<S, 0, Vec_GE> zeroed_clone() const { }
  */

  typedef typename std::vector<T>::const_iterator const_iterator;
  typedef typename std::vector<T>::iterator iterator;

  iterator begin() { return storage.begin(); }
  iterator end() { return storage.end(); }
  const_iterator begin() const { return storage.begin(); }
  const_iterator end() const { return storage.end(); }

//private:
  //template <class U1, size_t Size1, class CT1> friend struct Vec<U1,Size1,CT1>;
  std::vector<T> storage;
};

// Variable-size vector, all zeros
template <>
struct Vec<Zero, 0> {
  typedef Zero value_type;

  explicit Vec(size_t n) : n(n) {}
  size_t size() const { return n; }
  Zero operator[](size_t i) const { return Zero(); }

  template <class S>
  Vec<S, 0> shape_clone() const { return Vec<S, 0>(n); }

  template <class S>
  Vec<Zero, 0> zeroed_clone() const { return Vec<Zero, 0>(n); }

  typedef counting_iterator < Zero > iter_t;
  iter_t begin() const { return iter_t(0, Zero()); }
  iter_t end() const { return iter_t(n, Zero()); }

private:
  size_t n;
};

// Fixed-size vector, all zeros
template <int Size>
struct Vec<Zero, Size> {
  typedef Zero value_type;

  explicit Vec() {}
  explicit Vec(size_t size) { assert(size == Size); }

  size_t size() const { return Size; }
  Zero operator[](size_t i) const { return Zero(); }

  Vec<Zero, Size> shape_clone() const { return Vec<Zero, Size>(); }

  Vec<Zero, Size> zeroed_clone() const { return Vec<Zero, Size>(); }

  typedef counting_iterator < Zero > iter_t;
  iter_t begin() const { return iter_t{ 0, Zero() }; }
  iter_t end() const { return iter_t{ Size, Zero() }; }
};

// FUNCTION: vec
// Create vector from argument list
template <typename T, typename... Ts>
auto vec(T t, Ts ... ts) -> Vec<T, 1 + sizeof...(Ts)> {
  Vec<T, 1 + sizeof...(Ts)> v;
  vcopy(v.begin(), t, ts...);
  return v;
}

// -------------------------- OPERATORS -----------------------------------
// OPERATOR: double * Vec, Vec * double, Vec / double
// TODO generalize to args not just double
template <class T, int N, class CT>
Vec<T, N, CT> operator*(double a, Vec<T, N, CT> const& b)
{
    Vec<T, N, CT> out(b.size());
    for (size_t i = 0; i < b.size(); ++i)
        out[i] = a * b[i];
    return out;
}

template <class T, int N, class CT>
Vec<T, N, CT> operator*(Vec<T, N, CT> const& a, double b)
{
  Vec<T, N, CT> out(a.size());
  for (size_t i = 0; i < a.size(); ++i)
    out[i] = a[i] * b;
  return out;
}

// ENDOPERATOR: *

template <class T, int N, class CT>
Vec<T, N, CT> operator/(Vec<T, N, CT> const& a, double b)
{
  Vec<T, N, CT> out(a.size());
  for (size_t i = 0; i < a.size(); ++i)
    out[i] = a[i] / b;
  return out;
}

template <class T, int N, class CT>
Vec<T, N, CT> operator-(Vec<T, N, CT> const& a, double b)
{
  Vec<T, N, CT> out(a.size());
  for (size_t i = 0; i < a.size(); ++i)
    out[i] = a[i] - b;
  return out;
}

// GROUP: cross
template <class T, int N, class CT>
Vec<T, N, CT> cross(Vec<T, N, CT> const& a, Vec<T, N, CT> const& b)
{
    return vec(
        a[1] * b[2] - a[2] * b[1],
        a[2] * b[0] - a[0] * b[2],
        a[0] * b[1] - a[1] * b[0]
        );
}

// ENDGROUP: cross

template <class R>
struct run_elementwise_binary {
  template <class U, class V, class Functor>
  R operator()(U const& a, V const& b, Functor f)
  {
    // assert on sizes
    assert(a.size() == b.size());
    R ret{ a.size() };
    for (size_t i = 0; i < a.size(); ++i)
      ret[i] = f(a[i], b[i]);  // TODO proper functor
    return ret;
  }
};

// #define DECLARE_BINOP_2(OPERATOR, AT, AN, ACT, BT, BN, BCT, Ret_T, Ret_N, Ret_CT) \
// auto operator OPERATOR(Vec<AT, AN, ACT> const& a, Vec<BT, BN, BCT> const& b) -> Vec<Ret_T, Ret_N, Ret_CT> \
// {\
//   auto f = [](AT aa, BT bb) { return aa OPERATOR bb; };\
//   return run_elementwise_binary<decltype(a OPERATOR b)>()(a, b, f);\
// }

// #define DECLARE_BINOP(OPERATOR, AT, AN, ACT, BT, BN, BCT, Ret_N, Ret_CT) \
//   DECLARE_BINOP_2(OPERATOR, AT,AN,ACT,BT,BN,BCT,decltype(a[0] OPERATOR b[0]),Ret_N,Ret_CT)

#define DECLARE_BINOP(OPERATOR, AT, AN, ACT, BT, BN, BCT, Ret_N) \
auto operator OPERATOR(Vec<AT, AN, ACT> const& a, Vec<BT, BN, BCT> const& b) -> Vec<decltype(a[0] OPERATOR b[0]), Ret_N, ADD_CT(CTa, CTb)> \
{\
  auto f = [](AT aa, BT bb) { return aa OPERATOR bb; };\
  return run_elementwise_binary<decltype(a OPERATOR b)>()(a, b, f);\
}

#define ADD_CT(CTa, CTb) typename CT_traits<CTa, CTb>::result_of_add

// Add: Fixedsize, Anysize -> Fixedsize
template <class T, int N, class CTa, class U, class CTb>
DECLARE_BINOP(+, T, N, CTa, U, 0, CTb, N)
// template <class AT, int AN, class ACT, class BT, class BCT>
// auto operator +(Vec<AT, AN, ACT> const& a, Vec<BT, 0, BCT> const& b) -> Vec<decltype(a[0] + b[0]), AN, ADD_CT(ACT, BCT)>
// {
//   auto f = [](AT aa, BT bb) { return aa + bb; };
//   return run_elementwise_binary<decltype(a + b)>()(a, b, f);
// }

// compilation errors related to C macro expansion!

// Add: Anysize, Fixedsize -> Fixedsize
template <class T, int N, class CTa, class U, class CTb>
DECLARE_BINOP(+, T, 0, CTa, U, N, CTb, N)

// Add: Anysize, Anysize -> Anysize
template <class T, class CTa, class U, class CTb>
DECLARE_BINOP(+, T, 0, CTa, U, 0, CTb, 0)

// Add: Fixedsize, Fixedsize -> Fixedsize
template <class T, int N, class CTa, class U, int M, class CTb>
DECLARE_BINOP(+, T, N, CTa, U, M, CTb, N)

// Sub: Fixedsize, Anysize -> Fixedsize
template <class T, int N, class CTa, class U, class CTb>
DECLARE_BINOP(-, T, N, CTa, U, 0, CTb, N)

// Sub: Anysize, Fixedsize -> Fixedsize
template <class T, int N, class CTa, class U, class CTb>
DECLARE_BINOP(-, T, 0, CTa, U, N, CTb, N)

// Sub: Anysize, Anysize -> Anysize
template <class T, class CTa, class U, class CTb>
DECLARE_BINOP(-, T, 0, CTa, U, 0, CTb, 0)

// Sub: Fixedsize, Fixedsize -> Fixedsize
template <class T, int N, class CTa, class U, int M, class CTb>
DECLARE_BINOP(-, T, N, CTa, U, M, CTb, N)


// // Add: Anysize, Fixedsize -> Fixedsize
// template <class T, int N, class CTa, class U, class CTb>
// auto operator +(Vec<T, 0, CTa> const& a, Vec<U, N, CTb> const& b) -> Vec<decltype(a[0] + b[0]), N, ADD_CT(CTa, CTb)> { auto f = [](T aa, U bb) { return aa + bb; }; return run_elementwise_binary<decltype(a + b)>()(a, b, f);}

// // Add: Anysize, Anysize -> Anysize
// template <class T, class CTa, class U, class CTb>
// auto operator +(Vec<T, 0, CTa> const& a, Vec<U, 0, CTb> const& b) -> Vec<decltype(a[0] + b[0]), 0, ADD_CT(CTa, CTb)> { auto f = [](T aa, U bb) { return aa + bb; }; return run_elementwise_binary<decltype(a + b)>()(a, b, f);}

// // Add: Fixedsize, Fixedsize -> Fixedsize
// template <class T, int N, class CTa, class U, int M, class CTb>
// auto operator +(Vec<T, N, CTa> const& a, Vec<U, M, CTb> const& b) -> Vec<decltype(a[0] + b[0]), N, ADD_CT(CTa, CTb)> { auto f = [](T aa, U bb) { return aa + bb; }; return run_elementwise_binary<decltype(a + b)>()(a, b, f);}


// template <class T, int N, class CTa, class U, class CTb>
// auto operator -(Vec<T, N, CTa> const& a, Vec<U, 0, CTb> const& b) -> Vec<decltype(a[0] - b[0]), N, ADD_CT(CTa, CTb)> { auto f = [](T aa, U bb) { return aa - bb; }; return run_elementwise_binary<decltype(a - b)>()(a, b, f);}


// template <class T, int N, class CTa, class U, class CTb>
// auto operator -(Vec<T, 0, CTa> const& a, Vec<U, N, CTb> const& b) -> Vec<decltype(a[0] - b[0]), N, ADD_CT(CTa, CTb)> { auto f = [](T aa, U bb) { return aa - bb; }; return run_elementwise_binary<decltype(a - b)>()(a, b, f);}


// template <class T, class CTa, class U, class CTb>
// auto operator -(Vec<T, 0, CTa> const& a, Vec<U, 0, CTb> const& b) -> Vec<decltype(a[0] - b[0]), 0, ADD_CT(CTa, CTb)> { auto f = [](T aa, U bb) { return aa - bb; }; return run_elementwise_binary<decltype(a - b)>()(a, b, f);}


// template <class T, int N, class CTa, class U, int M, class CTb>
// auto operator -(Vec<T, N, CTa> const& a, Vec<U, M, CTb> const& b) -> Vec<decltype(a[0] - b[0]), N, ADD_CT(CTa, CTb)> { auto f = [](T aa, U bb) { return aa - bb; }; return run_elementwise_binary<decltype(a - b)>()(a, b, f);}



// FUN: transpose
template <class A, int SizeM, int SizeN, class CT1, class CT2>
Vec<Vec<A, SizeM, CT2>, SizeN, CT2> transpose(Vec<Vec<A, SizeN, CT2>, SizeM, CT1> const & v)
{
  Vec<Vec<A, SizeM, CT2>, SizeN, CT2> ret{ v[0].size() }; // TODO forward ctor args
  for (size_t i = 0; i != ret.size(); ++i)
    for (size_t j = 0; j != ret[i].size(); ++j)
      ret[i][j] = v[j][i];
  return ret;
}

// GROUP: STREAMS
template <class T>
struct vector_printer {
  const T& t;
  vector_printer(const T& t) :t(t) {}
};

template <class T>
vector_printer<T> pr(const T& t) {
  return vector_printer<T>(t);
}

template <class T>
std::ostream& operator<<(std::ostream& s, vector_printer<T> const& t)
{
  s << "{ ";
  auto b = std::begin(t.t);
  auto pe = std::end(t.t);
  --pe;
  std::copy(b, pe, std::ostream_iterator<decltype(*b)>(s, ", "));
  return s << *pe << " }";
}

template <class T, int N, class CT>
std::ostream& operator<<(std::ostream& s, Vec<T, N, CT> const& t)
{
  return s << pr(t);
}

// ENDGROUP: streams

template <typename T, int Size, typename CT>
struct numeric_traits<Vec<T,Size,CT>> {
  static Vec<Zero, Size> zero() {
    return Vec<Zero, Size>();
  }

  static Vec<Zero, Size> zeros_of_shape(Vec<T, Size, CT> const & that) {
    return Vec<Zero, Size>{that.size()};
  }
};

// FUNGROUP deep_fill
// Fill every Scalar in a recursive container of Scalar with a given value
template <class Container, class Scalar>
void deep_fill(Container* c, Scalar const& val) {
  for (auto& pc : *c)
    deep_fill(&pc, val);
}

template <class Scalar>
void deep_fill(Scalar* c, Scalar const& val) {
  *c = val;
}
// END deep_fill

// DOT PRODUCT.
// If everything works as intended, this code is now fast for all combinations of
// Fixedness and ContentType
template <class T1, int Size1, class CT1, class T2, int Size2, class CT2>
auto dot(Vec<T1, Size1, CT1> const& a, Vec<T2, Size2, CT2> const& b) -> decltype(a[0] * b[0] + a[0] * b[0])
{
  typedef decltype(a[0] * b[0] + a[0] * b[0]) ret_t;

  assert(a.size() == b.size());
  if (a.size() == 0)
    return numeric_traits<ret_t>::zero();

  ret_t out = a[0] * b[0];
  for (size_t i = 1; i < a.size(); ++i)
    out += a[i] * b[i];
  return out;
}

// NORMSQ, normsq -- see sumsq

// FLATTEN
template <class CT1, int Size>
Real* flatten(Vec<Real, Size, CT1> const& a, Real* out)
{
  Real* p = out;
  for (auto val : a)
    *out++ = val;
  return out;
}

template <class T, int Size, class CT1>
Real* flatten(Vec<T, Size, CT1> const& a, Real* out)
{
  for (auto val : a)
    out = flatten(val, out);
  return out;
}

template <int Size, class CT1>
Vec<Real, Size, CT1>  flatten(Vec<Real, Size, CT1> const& a)
{
  return a;
}

// TODO speed up for fixed size inputs
template <class T1, int Size, class CT1>
Vec<Real, 0, CT1>  flatten(Vec<T1, Size, CT1> const& a)
{
  size_t out_size = 0;
  for (auto val : a)
    out_size += flatten(val).size();

  Vec<Real, 0, CT1> out{ out_size };
  flatten(a, &out[0]);
  return out;
}

inline void test_flatten()
{
  auto a = vec(1., 2.);
  auto b = vec(3., 5.);
  auto c = vec(a, b);
  assert(flatten(c).size() == 4);
  assert(flatten(c)[3] == 5);
}

// ENDGROUP flatten

// FUN sum
// If everything works as intended, this code is now fast for all combinations of
// Fixedness and ContentType
template <class T, int Size, class CT>
auto sum(Vec<T, Size, CT> const& a) -> decltype(a[0] + a[0])
{
  typedef decltype(a[0] + a[0]) ret_t;

  if (a.size() == 0)
    return numeric_traits<ret_t>::zero();

  ret_t out = a[0];
  for (size_t i = 1; i < a.size(); ++i)
    out += a[i];
  return out;
}

// ENDFUN sum

// FUN sumsq
template <class T>
double sumsq(const T& x)
{
  return x*x;
}

template <class T, int Size, class CT>
auto sumsq(Vec<T, Size, CT> const& a) -> decltype(sumsq(a[0]) + sumsq(a[0]))
{
  typedef decltype(sumsq(a[0]) + sumsq(a[0])) ret_t;

  if (a.size() == 0)
    return numeric_traits<ret_t>::zero();

  ret_t out = sumsq(a[0]);
  for (size_t i = 1; i < a.size(); ++i)
    out += sumsq(a[i]);
  return out;
}

// Grad: compute gradient
template <class T, int Size, class CT>
auto grad_sumsq(Vec<T, Size, CT> const& v) -> decltype(2 * v)
{
  return 2 * v;
}

// ENDFUN sumsq

// FUN max
template <class T, int Size, class CT>
T max(Vec<T, Size, CT> const& a)
{
  assert(a.size() > 0);
  T out = a[0];
  for (size_t i = 1; i < a.size(); ++i)
    if (a[i] > out)
      out = a[i];
  return out;
}

// FUN exp
template <class T, int Size, class CT>
Vec<T, Size, CT> exp(Vec<T, Size, CT> const& a)
{
  Vec<T, Size, CT> out{ a.size() };
  for (size_t i = 0; i < a.size(); ++i)
    out[i] = exp(a[i]);
  return out;
}



// FUN ==
template <class T, int Size, class CT, class T2, int Size2, class CT2>
bool operator==(Vec<T, Size, CT> const& a, Vec<T2, Size2, CT2> const& b)
{
  if (a.size() != b.size())
    return false;

  for (size_t i = 0; i < a.size(); ++i)
    if (a[i] != b[i])
      return false;

  return true;
}

template <class T, int Size, class CT, class T2, int Size2, class CT2>
bool operator!=(Vec<T, Size, CT> const& a, Vec<T2, Size2, CT2> const& b)
{
  return !(a == b);
}

// ENDFUN ==

// #include <boost/test/tools/floating_point_comparison.hpp>

// // Declare boost::math::fpc::close_at_tolerance for vectors
// template<typename T, size_t Size, class ContentsTag>
// class boost::math::fpc::close_at_tolerance<Vec<T, Size, ContentsTag>> {
//   typedef Vec<T, Size, ContentsTag> FPT;
//   typedef decltype(sumsq(FPT())) Real;

// public:
//   // Public typedefs
//   typedef bool result_type;

//   // Constructor
//   template<typename ToleranceType>
//   explicit    close_at_tolerance(ToleranceType tolerance, fpc::strength fpc_strength = FPC_STRONG)
//     : m_fraction_tolerance(fpc_detail::fraction_tolerance<Real>(tolerance))
//     , m_strength(fpc_strength)
//     , m_tested_rel_diff(0)
//   {
//     // BOOST_ASSERT_MSG(m_fraction_tolerance >= Real(0), "tolerance must not be negative!"); // no reason for tolerance to be negative
//   }

//   // Access methods
//   //! Returns the tolerance
//   Real                 fraction_tolerance() const { return m_fraction_tolerance; }

//   //! Returns the comparison method
//   fpc::strength       strength() const { return m_strength; }

//   //! Returns the failing fraction
//   Real                tested_rel_diff() const { return m_tested_rel_diff; }

//   /*! Compares two floating point numbers a and b such that their "left" relative difference |a-b|/a and/or
//   * "right" relative difference |a-b|/b does not exceed specified relative (fraction) tolerance.
//   *
//   *  @param[in] left first floating point number to be compared
//   *  @param[in] right second floating point number to be compared
//   *
//   * What is reported by @c tested_rel_diff in case of failure depends on the comparison method:
//   * - for @c FPC_STRONG: the max of the two fractions
//   * - for @c FPC_WEAK: the min of the two fractions
//   * The rationale behind is to report the tolerance to set in order to make a test pass.
//   */
//   bool                operator()(FPT left, FPT right) const
//   {
//     if (left.size() != right.size())
//       return false;

//     Real diff = sqrt(sumsq(left - right));

//     m_tested_rel_diff = diff;

//     return m_tested_rel_diff <= m_fraction_tolerance;
//   }

// private:
//   // Data members
//   Real m_fraction_tolerance;
//   fpc::strength       m_strength;
//   mutable Real         m_tested_rel_diff;
// };

template <class T, size_t Size>
using VecF = Vec<T, Size>;


template <class T>
using Vec3 = Vec<T, 3>;

template <class T>
using Vec2 = Vec<T, 2>;
#endif
