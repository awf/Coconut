#pragma once

#include "Vec.h"


#if EIGEN
#include <Eigen/Dense>

template <class T, size_t R, size_t C>
using Mat = Eigen::Matrix<T, R, C>;

template <class T, int M, int N>
VecF<T, M>& getRow(Mat<T, M, N> const& m, int i)                 { 
  return m.row(i); 
}


#else

struct Mat_Identity {};

// Matrix derives from Vec<Vec> which is sometimes plausible, see https://github.com/awf/autodiff2/blob/master/autodiff/Differentiating%20Containers.md
// Typically viewed as a vector of column vectors.  Then gdot<Vec>(Mat, Vec) yields matrix-vector multiply
template <class T, size_t M = 0, size_t N = 0>
struct Mat : public Vec<Vec<T, M>, N> {
  typedef Vec<Vec<T, M>, N> base_t;

  Mat() {}
  Mat(size_t M_, size_t N_) :
    base_t{ N_, Vec<T, M>{M_} }
  {}

  Mat(size_t M_, size_t N_, T const& val) :
    base_t{ N_, Vec<T, N>{M_, val} }
  {}

  template <class U>
  Mat(Vec<Vec<U, M>, N> const& val) :
    base_t{ val }
  {}

  Mat(base_t&& val) :
    base_t{ val }
  {}

  T&       operator()(size_t i, size_t j)       { return (*this)[j][i]; }
  T const& operator()(size_t i, size_t j) const { return (*this)[j][i]; }
  // Vec<T, M>& operator()(size_t i)               { return (*this)[i]; }
  // T const& operator()(size_t i, size_t j) const { return (*this)[j][i]; }

  Vec<T, M>& getRow(size_t i)                 { return (*this)[i]; }
  size_t rows() const { return (*this)[0].size(); }
  size_t cols() const { return (*this).size(); }

  template <size_t Rows, size_t Cols>
  Mat<T, Rows, Cols> block(size_t start_row, size_t start_col) const {
    Mat<T, Rows, Cols> ret;
    for (size_t i = 0; i < Rows; ++i)
      for (size_t j = 0; j < Cols; ++j)
        ret(i, j) = (*this)(i + start_row, j + start_col);
    return ret;
  }
};

template <class T>
using Mat3x3 = Mat<T,3,3>;

template <class T, size_t N>
Vec<T, N, Vec_GE> diag(Mat<T, N, N> const& m)
{
  Vec<T, N, Vec_GE> out;
  for (size_t i = 0; i < m.size(); ++i)
    out[i] = m[i][i];
  return out;
}

template <class T, int N, class CT>
Mat<T, N, N> diaginv(Vec<T, N, CT> const& v)
{
  Mat<T, N, N> out = Mat<Zero, N, N>{ v.size(), v.size() };
  for (size_t i = 0; i < v.size(); ++i)
    out[i][i] = v[i];
  return out;
}

template <class T, size_t N>
Mat<T, N, N> identity() {
  Mat<T, N, N> out(N,N,Zero());
  for (size_t i = 0; i < out.size(); ++i)
    out[i][i] = 1;
  return out;
}

template <class T, size_t N, size_t M>
T trace(Mat<T, N, M> const& m)
{
  return sum(diag(m));
}

template <class T, size_t N, size_t C, size_t M>
Mat<T, N, M> operator*(Mat<T, N, C> const& a, Mat<T, C, M> const& b)
{
  size_t N_ = a.rows();
  size_t M_ = b.cols();
  size_t C_ = a.cols();
  assert(a.cols() == b.rows());
  Mat<T, N, M> ret{ N_, M_ };
  for (int i = 0; i < N_; ++i)
    for (int j = 0; j < M_; ++j) {
      T accum = 0;
      for (int k = 0; k < C_; ++k)
        accum += a[k][i]*b[j][k];
      ret[j][i] = accum;
    }
  return ret;
}


template <class T, size_t M, size_t N>
Vec<T, M> getRow(Mat<T, M, N> const& m, size_t i)                 { 
  return m[i]; 
}


/*
Vec<Vec<float, 3>, 3> a;
Vec<Vec<float, 3>, 7> b;
auto x = a*b;
*/
#endif
