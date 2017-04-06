#include <cmath>
#include <cassert>
#include <iostream>

#include "test.h"

#include "dot.h"
#include "Vec.h"
#include "Mat.h"

// RELU
template <class Real>
Real relu(Real x)
{
  if (x > 0)
    return x;
  else
    return 0;
}

template <class Real>
Real grad_relu(Real x)
{
  if (x > 0)
    return 1;
  else
    return 0;
}

template <class Real, class Real2, size_t N>
auto elementwise(Real2 f(Real), Vec<Real, N> const& v) -> Vec<Real2, N>
{
  Vec<Real2> ret(v.size());
  for (size_t i = 0; i != v.size(); ++i)
    ret[i] = f(v[i]);
  return ret;
}

template <class R, size_t N>
Vec<R, N> vrelu(Vec<R, N> x)
{
  return elementwise(relu<R>, x);
}

template <class R, size_t N>
Vec<Vec<R,N>,N> grad_vrelu(Vec<R,N> const& x)
{
  return diaginv(elementwise(grad_relu<R>, x));
}

BOOST_AUTO_TEST_CASE(test_vrelu)
{
  Vec3<Real> x = vec(-.5, .2, .3);
  BOOST_CHECK(vrelu(x) == vec(0., .2, .3));
  BOOST_CHECK(grad_vrelu(x) == diaginv(vec(0., 1., 1.)));
}



template <class Real, size_t W, size_t H, size_t N_out, size_t N_in, size_t Filter_W, size_t Filter_H>
auto conv(Vec<Mat<Real, Filter_W, Filter_H>, N_out> const& filters,
          Mat<Vec<Real, N_in>, W, H> const& in) ->
  Mat<Vec<Real, N_out>, W, H>
{
  // .. do convolution, efficiently presumably, ...
}

template <class Real, size_t W, size_t H, size_t N_out, size_t N_in, size_t Filter_W, size_t Filter_H>
auto grad1_conv(Vec<Mat<Real, Filter_W, Filter_H>, N_out> const& filters,
                Mat<Vec<Real, N_in>, W, H> const& in) ->
  Vec<Mat<Mat<Vec<Real, N_out>, W, H>, Filter_W, Filter_H>, N_out>
{
  // .. do convolution, efficiently presumably, ...
}

