
#include <cmath>
#include <cassert>
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <functional>

#include "test.h"

#include "flat_view.h"

#include "dot.h"
#include "Vec.h"

#include "rodrigues.h"

// GROUP: shape_clone
// Shape clone: Return a container of the same size with a different content type in place of Real
template <class Replace_t>
Replace_t shape_clone(Real that)
{
  return Replace_t{};
}

// Shape clone: Return a container of the same size with a different content type in place of Real
template <class Replace_t, int Size, typename CT>
Vec<Replace_t, Size, CT> shape_clone(Vec<Real, Size, CT> const& that)
{
  Vec<Replace_t, Size, CT> ret{ that.size() };
  return ret;
}

// Shape clone: Return a container of the same size with a different content type
// The container may be multi-level
template <class Replace_t, int Size, typename CT, class T>
auto shape_clone(Vec<T, Size, CT> const& that) ->
  Vec<decltype(shape_clone<Replace_t>(that[0])), Size, CT>
{
  typedef decltype(shape_clone<Replace_t>(that[0])) new_value_type;
  Vec<new_value_type, Size, CT> ret{ that.size() };
  auto const& p = std::begin(that);
  for (auto& i : ret)
    i = shape_clone<Replace_t>(*p++);
  return ret;
}

//decltype(shape_clone<Vec3<Real>>(Vec3<Vec3<Real>>())) a = 3;
ASSERT_SAME_TYPE(decltype(shape_clone<Vec3<Real>>(Vec3<Vec3<Real>>())), Vec3<Vec3<Vec3<Real>>>);

// ENDGROUP: shape_clone

// Helper to declare the type of the gradient of a function which 
// takes a Container2_of_Real and returns a Container1_of_Real
template <class Container1_of_Real, class Container2_of_Real>
struct gradient_declarations_helper {
  typedef std::function<Container1_of_Real(Container2_of_Real const&)> function_t;

  typedef decltype (shape_clone<Container2_of_Real>(std::declval<Container1_of_Real>())) Container1_of_Container2_of_Real;
  typedef decltype (shape_clone<Container1_of_Real>(std::declval<Container2_of_Real>())) Container2_of_Container1_of_Real;
  //typedef typename Container1_of_Container2_of_Real grad_t;
  //typedef std::function<grad_t(Container2_of_Real const&)> grad_function_t;

  // Compute finite-difference gradients
  Container2_of_Container1_of_Real grad_fd_transpose(function_t f, Container2_of_Real const& x) {
    Container2_of_Container1_of_Real grad_fd_transpose;

    // grad_fd[i,j] = (fx(x+delta*e_j)[i] - f(x)[i])/delta;
    // grad_fd[:,j] = (fx(x+delta*e_j) - f(x) )/delta;

    Container1_of_Real fx = f(x);
    double delta = 1e-6;
    auto xp = x;

    auto flat_x = flat_view<Real>(x);
    auto x_iter = flat_x.begin();

    auto flat_xp = flat_view<Real>(xp);
    auto xp_iter = flat_xp.begin();

    auto flat_out = flat_view<Container1_of_Real>(grad_fd_transpose);
    auto out_iter = flat_out.begin();
    for (; x_iter != flat_x.end(); ++x_iter, ++xp_iter, ++out_iter) {
      auto xi = *x_iter;
      *xp_iter = xi + delta;
      double actual_delta = *xp_iter - xi;
      Container1_of_Real fxp = f(xp);
      *out_iter = (fxp - fx) / actual_delta;
      *xp_iter = xi;
    }
    return grad_fd_transpose;
  }

  //Container1_of_Container2_of_Real grad_fd(function_t f, Container2_of_Real const& x) {
  //  Container2_of_Container1_of_Real gt = grad_fd_transpose(f, x);
  //  Container1_of_Real fx = f(x);
  //  Container1_of_Container2_of_Real out = shape_clone<Container2_of_Real>(fx);
  //  auto flat_out = flat_view<Real>(out);
  //  auto flat_in = flat_view<Real>(gt);
  //  auto out_iter = flat_out.begin();
  //  auto in_iter = flat_in.begin();
  //  for (; in_iter != flat_in.end(); ++in_iter, ++out_iter)
  //    *in_iter = *out_iter;
  //  return out;
  //}
};

template <class Container1_of_Real, class Container2_of_Real>
auto grad_finite_difference(std::function<Container1_of_Real(Container2_of_Real const&)> f,
  Container2_of_Real const& x) ->
  typename gradient_declarations_helper<Container1_of_Real, Container2_of_Real>::Container2_of_Container1_of_Real
{
  return gradient_declarations_helper<Container1_of_Real, Container2_of_Real>().grad_fd_transpose(f, x);
}


template <class T>
Mat3x3<T> grad_trace(Mat3x3<T> const& m)
{
  Mat3x3<T> out = Mat<Zero,3,3>();
  for (size_t i = 0; i < m.size(); ++i)
    out[i][i] = 1;
  return out;
}

/*
template <class T>
Identity3x3<T> grad_trace(Mat3x3<T> const& m)
{
  return Identity3x3<T>{};
}
*/

Real f(Vec3<Real> const& x)
{
  return trace(exp2mat(x));
}

Vec3<Real> grad_f(Vec3<Real> const& x)
{
  // f = t(e(x))  ==> ∇f = ∇e(x) "*" ∇t(e(x))    
  //          Vec<Mat<R>>      Mat<R>
  return gdot<decltype(x)>(grad_exp2mat(x), grad_trace(exp2mat(x)));
}





BOOST_AUTO_TEST_CASE(test_chain_rule) 
{
  Vec3<Real> x = vec(-.5, .2, .3);
  Vec3<Real> grad = grad_f(x);
  std::cout << "GRAD_CR = " << grad << "\n";

  // Finite differences
  Vec3<Real> grad_fd = grad_finite_difference<Real, Vec3<Real>>(f, x);
  std::cout << "GRAD_FD = " << grad_fd << "\n";

  BOOST_CHECK_CLOSE(grad, grad_fd, 1e-3);
}

Real grad_sin(Real x)
{
  return cos(x);
}

Real sinc(Real x)
{
  return x == 0 ? 1 : sin(x) / x;
}

Real grad_1overx(Real x)
{
  return -1 / (x * x);
}

Real grad_sinc(Real x)
{
  if (x == 0)
    return 1;   //  I needed to know this.
  else
    // grad_sin(x) / x + sin(x) * grad_1overx(x); // this would be bad
    return (cos(x)*x - sin(x))/(x*x); // slightly more stable numerically, but really need taylor.
}

#if 1

// -------------------  Test gdot with containers
#define DECLARE_CONTAINER(Name)\
template <class T> struct Name : public Vec<T, 3> {\
  Name() {};\
  template <class U>\
  explicit Name(U const& that) : Vec<T, 3>(that) {}\
\
  template <class U>\
  Name& operator=(U const& that) { Vec<T, 3>::operator=(that); return *this; }\
};

DECLARE_CONTAINER(Bee)
DECLARE_CONTAINER(Cee)
DECLARE_CONTAINER(Dee)
DECLARE_CONTAINER(Eee)
DECLARE_CONTAINER(Foo)
DECLARE_CONTAINER(Gar)

#include <boost/range/counting_range.hpp>
auto inds = boost::counting_range<int>(0, 3);

static double fill_value;
template <class Container>
void do_fill_inc(Container* c) {
  for (auto& pc : *c)
    do_fill_inc(&pc);
  fill_value += 1;
}

template <>
void do_fill_inc(Real* c) {
  *c = fill_value;
  fill_value += .1;
}


void test_dotter_1()
{
  // Compare dot to handwritten vector one
  {
    Vec<double, 3> a = vec(7, 2, 3);
    Vec<double, 3> b = vec(5, 11, 13);
    double d1 = Dotter<0, 1, decltype(a), decltype(b)>::dot(a, b);
    std::cout << "VECDOT: " << a << "." << b << "=" << d1;
    assert(d1 == dot(a, b));
    std::cout << ". OK\n";
  }

  // Jagged jonnies
  {
    Vec<Vec<Real, 3>, 2> a = vec( vec(7, 2, 3), vec(17, 23, 31) );
    Vec<Vec<Real, 3>, 2> b = vec( vec(43, 11, 5), vec(19, 29, 37) );
    double d1 = Dotter<0, 2, decltype(a), decltype(b)>::dot(a, b);
    std::cout << "VECDOT1: " << a << "." << b << "=" << d1;

    double d_gt = dot(flatten(a), flatten(b));

    assert(d1 == d_gt);
    std::cout << ". OK\n";

    typedef dot_inferring_helper<Vec<Vec<Real, 3>, 2>, Vec<Vec<Real, 3>, 2>, Real> dih;
    BOOST_STATIC_ASSERT(dih::C1_depth == 0);
    BOOST_STATIC_ASSERT(dih::C2_depth == 2);

    Real d2 = gdot(a, b, b[0][0]);
    std::cout << "VECDOT2: =" << d2;

    assert(d2 == d_gt);
    std::cout << ". OK\n";
  }

  // Dot of
  Dee<Real> x;
  Bee<Cee<Real>> g;
  Bee<Cee< Dee<Real> >> grad_g;

  Foo<Real> f; // f(g)
  Foo< Bee<Cee<Real>> > grad_f;
  // when we know the container over which we must multiply-accumulate is the Bee<Cee>.
  // The output will be a...
  Foo< Dee<Real> > out;
  deep_fill(&out, Real{ 0 });
  // So the dotting will ultimately involve products Real*Dee<Eee<Real>>

  // First fill the containers.
  fill_value = 0;  do_fill_inc(&grad_f);
  fill_value = -20;  do_fill_inc(&grad_g);

  std::cout << "DOT:\n";
  std::cout << "A = " << grad_f << "\n";
  std::cout << "B = " << grad_g << "\n";

  // Declare the dotter.  First arg is depth of C1 in grad_f, second is depth of C2.
  Dotter<1, 2, decltype(grad_f), decltype(grad_g)>::dot3(grad_f, grad_g, &out);

  std::cout << "DOT1 = " << out << std::endl;

  // Inferred dotter.  First arg is depth of C1 in grad_f, second is depth of C2.
  auto out0a = Dotter<1, 2, decltype(grad_f), decltype(grad_g)>::dot(grad_f, grad_g);
  Foo< Dee<Real> > out0 = Foo< Dee<Real> >{ out0a };
  std::cout << "INFER. = " << out0 << std::endl;

  // Compare to hand-coded
  Foo< Dee<Real> > out2; 
  deep_fill(&out2, Real{ 0 });

  for (int i : inds)
    for (int j : inds)
      for (int k : inds)
        out2[i] += grad_f[i][j][k] * grad_g[j][k];

  std::cout << "DOT0 = " << out2 << std::endl;

}


Vec3<Real> mmul(Mat3x3<Real> const& a, Vec3<Real> const& b)
{ 
  return dot(a,b); 
}

BOOST_AUTO_TEST_CASE(test_mmul)
{
  Mat3x3<Real> A{ vec(vec(1.1,1.2,1.3), vec(7.,5.,11.), vec(13.,17.,19.)) };
  Vec3<Real> b = vec(2.1, 3.2, 3.3);
  Vec3<Real> Ab = vec(67.6100, 74.6200, 100.6300);
  BOOST_CHECK_CLOSE(mmul(A, b), Ab, 1e-8);
}

// Define gradients of mmul, with respect to arguments 1 and 2
Mat3x3<Vec3<Real>> grad1_mmul(Mat3x3<Real> const& a, Vec3<Real> const& b)
{
  auto I = identity<Real, 3>();
  return vec(b[0]*I, b[1]*I, b[2]*I);
}

Vec3<Vec3<Real>> grad2_mmul(Mat3x3<Real> const& a, Vec3<Real> const& b)
{
  return a;
}


Vec3<Real> b() { return vec<Real>(11, 22, 33); }
// does this have a clean definition?   Void<Vec3<Zero>>, where void is an empty container ?
// void grad_b() { }
// I think not.  With multi-argument functions, we write grad1_b , grad2_b etc, 
// so here we would be writing grad0_b, which is essentially null
// At any call site, b is clearly constant, as it has no arguments.

// f2: exp2mat(a) * b
Vec3<Real> f2(Vec3<Real> const& a) {
  auto Rot = exp2mat(a);
  return mmul(Rot, b());
}

Vec3<Vec3<Real>> grad_f2(Vec3<Real> const& a) {
  auto Rot = exp2mat(a);
  auto grad_Rot = grad_exp2mat(a);

  Vec3<Real> val_b = b();
  //Vec3<Zero> val_grad_b = grad_b();

  auto f = mmul(Rot, val_b);
  auto d1 = gdot(grad_Rot, grad1_mmul(Rot, val_b), a);
  //auto d2 = gdot(grad2_mmul(Rot, val_b), val_grad_b, void()); // show propagation of zeros
  return d1; //+ d2;
}

// f3: b' * f2(x)
Real f3(Vec3<Real> const& x) {
  return dot(b(), f2(x));
}

Vec3<Real> grad1_dot(Vec3<Real> const& a, Vec3<Real> const& x)
{
  return x;
}

Vec3<Real> grad2_dot(Vec3<Real> const& a, Vec3<Real> const& x)
{
  return a;
}

Vec3<Real> grad_f3(Vec3<Real> const& x) {
  auto val_f2 = f2(x);
  auto val_grad_f2 = grad_f2(x);

  return gdot(val_grad_f2, grad2_dot(b(), val_f2), x);
}

// f4: X * b
Vec3<Real> f4(Mat3x3<Real> const& X)
{
  return mmul(X, b());
}

Vec3<Mat3x3<Real>> grad_f4(Mat3x3<Real> const& X)
{
  return grad1_mmul(X, b());
}

// f5: dot(f2(x), x)
Real f5(Vec3<Real> const& x)
{
  auto fx = f2(x);
  return dot(fx, x);
}

Vec3<Real> grad_f5(Vec3<Real> const& x)
{
  auto fx = f2(x);
  auto grad_fx = grad_f2(x);
  auto result = dot(fx, x);
  return gdot(grad_fx, grad1_dot(fx, x), x) + grad2_dot(fx, x);
}

// f6: dot(f2(x), f2(x))
Real f6(Vec3<Real> const& x)
{
  auto fx = f2(x);
  return dot(fx, fx);
}


Vec3<Real> grad_f6(Vec3<Real> const& x)
{
  auto fx = f2(x);
  auto grad_fx = grad_f2(x);
  auto result = dot(fx, fx);
  auto gres = gdot(grad_fx, grad1_dot(fx, fx), x) + gdot(grad_fx, grad1_dot(fx, fx), x);
  BOOST_CHECK_CLOSE(gres, gdot(grad_fx, grad_sumsq(fx), fx), 1e-4);
  return gres;
}

template <class In, class Out, class OutGrad>
void test_fd(std::string const& tag, Out f(In const&  x), OutGrad grad_f(In const& x), In const& x)
{
  auto hand = grad_f(x);
  auto fd = grad_finite_difference<Out, In>(f, x);
  double tol = std::max(1.0, sqrt(sumsq(fd))) * 1e-4;
  BOOST_CHECK_CLOSE(hand, fd, tol);
}

BOOST_AUTO_TEST_CASE(test_mmul2)
{
    Mat3x3<Real> A { vec(vec(1.1,1.2,1.3), vec(7.,5.,11.), vec(13.,17.,19.)) };
    test_fd("mmul", f4, grad_f4, A);
}

BOOST_AUTO_TEST_CASE(test_f2)
{
    test_fd("f2", f2, grad_f2, vec(1., 2., 5.));
}

BOOST_AUTO_TEST_CASE(test_f3)
{
    Vec3<Real> a = vec(1., 2., 6.5);
    test_fd("f3", f3, grad_f3, a);
  }

BOOST_AUTO_TEST_CASE(test_f5)
{
    Vec3<Real> a = vec(1.1, 2.2, 5.5);
    test_fd("f5", f5, grad_f5, a);
  }

BOOST_AUTO_TEST_CASE(test_f6)
  {
    Vec3<Real> a = vec(1.1, 2.2, 5.5);
    test_fd("f6", f6, grad_f6, a);
  }


int xmain(int argc, char* argv[])
{
  test_deep_iterator();

  auto v123 = vec(1., 2., 3.);
  auto v357 = vec(3., 5., 7.);
  auto v713 = vec(7., 11., 13.);

  Vec<Vec<Real, 3>, 3> a = vec(v123, v713, v357);
  Vec<Vec<Real, 3>, 3> b = vec(v123, v713, v123);

  std::cout << pr(a) << std::endl;
 
  //test_f2();

  test_dotter_1();

  test_chain_rule();

  Real c = 0;
  Vec<Vec<Real, 3>, 3> vvc = Vec3<Vec3<Zero>>();

  return 0;
}

#endif
