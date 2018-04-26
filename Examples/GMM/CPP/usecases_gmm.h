// GMM: Gaussian Mixture Model
// See eqn 2 of https://github.com/awf/autodiff/blob/master/Documents/AD%202016%20extended.pdf
// alphas
//   vector of logs of mixture weights (unnormalized), so
//   weights = exp(alphas)/sum(exp(alphas))
// means  k x d 
//   Matrix of component means
// qs     k x d 
//   Matrix of logs of diagonals of component inverse covariance matrices
// ls     k x d*(d-1)/2
//   Matrix of vectorized lower triangles of component inverse covariance matrices

#include "stdafx.h"
#include <math.h>

const size_t GMM_K = 5;
const size_t GMM_D = 3;

// #define FIXED_SIZES

// Should/could be faster for fixed K
#ifdef FIXED_SIZES
typedef VecF<Real, GMM_D> VectorD;
typedef Vec<Real> Vector;
#else
typedef Vec<Real> VectorD;
typedef Vec<Real> Vector;
#endif

typedef Vec<Real> Vector;

Real logsumexp(Vector const& arr);
VectorD Qtimesv(VectorD const& q, Vector const& l, VectorD const& v);
Real gmm_objective(std::vector<VectorD> const& x,
Vector const& alphas, std::vector<VectorD> const& means, std::vector<VectorD> const& qs, std::vector<Vector> const& ls, Real wishart_gamma, Real wishart_m);

// void Qtimesv_test();

// nth triangular number (0 1 3 6)
// tri 0 = 0
// tri 1 = 1
// tri 2 = 3
// tri 3 = 6
inline cardinality_t tri(cardinality_t n)
{
  return n * (n + 1) / 2;
}
