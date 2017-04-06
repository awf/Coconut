
#include "test.h"

#include "Vec.h"
#include "Mat.h"

template <class Container_U, class Container_V>
auto dot_too_generic(Container_U const& u, Container_V const& v) ->
decltype(*std::begin(u) * *std::begin(v))
{
  typedef decltype(*std::begin(u) * *std::begin(v)) ret_t;
  ret_t accum{ 0 };
  for (auto pu = std::begin(u), pv = std::begin(u); pu != std::end(u); ++pu, ++pv)
    accum += *pu * *pv;
  return accum;
}

void f()
{
  Vec<double, 3> a;
  Vec<double, 3> b;
  double d = dot_too_generic(a, b);
}


BOOST_AUTO_TEST_CASE(test_vec)
{
  typedef double Real;

  auto a = vec(1, 2, 3); // make vec of 3 ints

  Vec<Real> b = a;
  Vec<Real, 3> c = Vec<Zero, 0>(3);
  Vec<Real, 3> d = Vec<Zero, 3>();

  std::cout << pr(a) << std::endl;
  std::cout << pr(b) << std::endl;
  std::cout << pr(c) << std::endl;
  std::cout << pr(d) << std::endl;

  Vec<Real> e = a + a;

  std::cout << pr(e) << std::endl;

  std::cout << dot_too_generic(a, a) << std::endl;

  Mat3x3<Real> m { vec(vec(1.,2.,3.), vec(4.,5.,6.), vec(7.,8.,9.)) };

  assert(transpose(m)[1][0] == m[0][1]);

}
