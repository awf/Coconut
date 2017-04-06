

#include "Mat.h"

BOOST_AUTO_TEST_CASE(test_matrix)
{
  auto v = vec(1., 2., 3.2);
  BOOST_CHECK_EQUAL(diag(diaginv(v)), v);
  //  BOOST_CHECK_EQUAL(trace(diaginv(v)), sum(v));
}
