// usecases_ba.cpp : Bundle Adjustment

#include "stdafx.h"

#include "usecases_gmm.h"


// GMM Use Case from https ://github.com/awf/autodiff/blob/master/Documents/AD%202016%20extended.pdf


Real logsumexp(Vector const& arr)
{
  Real mx = max(arr);
  Real semx = sum(exp(arr - mx));
  return log(semx) + mx;
}

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

// Assemble lower-triangular matrix from log-diagonal and lower triangle and multiply by vector v
// [ exp(q0)        0        0        0 ]
// [      l0  exp(q2)        0        0 ]
// [      l1       l2  exp(q3)        0 ]
// [      l3       l4       l5  exp(q4) ]
VectorD Qtimesv(VectorD const& q, Vector const& l, VectorD const& v)
{
  VectorD ret(v.size());
  for (size_t i = 0; i < size_t(v.size()); ++i) {
    // let li = vectorSlice (Card i) (tri(i - 1)) l
    // let vi = vectorSlice (Card i) 0 v
    // vectorSum (li.*vi) + exp(q[i])*v[i]
    size_t lstart = tri(i - 1);
    double out = exp(q[i]) * v[i];
    for (size_t k = 0; k < i; ++k)
      out += l[lstart + k] * v[k];
    ret[i] = out;
  }
  return ret;
}

// void Qtimesv_test()
// {
//   auto q = vec(0.1, -1.0, 0.3);
//   auto l = vec(5.0, -2.0, 7.1);
//   auto v = vec(1.4, -7.0, 3.1);
//   auto ans0 = exp(q[0]) * v[0];
//   auto ans1 = l[0] * v[0] + exp(q[1]) * v[1];
//   auto ans2 = l[1] * v[0] + l[2] * v[1] + exp(q[2]) * v[2];
//   auto ans = vec(ans0, ans1, ans2);
//   auto qv = Qtimesv(q, l, v);
//   auto nrm = sumsq(qv - ans);
//   printf("nrm=%f\n", nrm);
//   assert(nrm < 0.0001);
// }

Real gmm_objective(std::vector<VectorD> const& x,
  Vector const& alphas, std::vector<VectorD> const& means, std::vector<VectorD> const& qs, std::vector<Vector> const& ls,
  Real wishart_gamma, Real wishart_m)
{
  size_t n = x.size();
  size_t d = x[0].size();
  cardinality_t K = alphas.size();
  //    assert (K = rows means)
  //    assert (d = cols means)
  //    assert (K = rows qs)
  //    assert (d = cols qs)
  //    assert (K = rows ls)
  //    assert (auto di = (cardToInt d) in di*(di-1)/2 = cardToInt (cols ls))
  double out = 0.0;
  Vector tmp{ K };
  for (size_t i = 0; i < n; ++i) {
    for (size_t k = 0; k < K; ++k)
      tmp[k] = alphas[k] + sum(qs[k]) - 0.5 * sumsq(Qtimesv(qs[k], ls[k], x[i] - means[k]));
    out += logsumexp(tmp);
    // printf("%d-%f\n", i, logsumexp(tmp));
  }
  // printf("--%f\n", out);
  out -= n * logsumexp(alphas);
  // printf("---%f\n", out);
  for (int k = 0; k < K; ++k)
    out += 0.5 * sumsq(exp(qs[k])) + sumsq(ls[k]);
  return out;
}
