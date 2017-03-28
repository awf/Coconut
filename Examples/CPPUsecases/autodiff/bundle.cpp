#if 0

Real sqr(Real a) { return a*a; }

Vec2<Real> pi(Vec3<Real> const& X)
{
  Vec2<Real> ret(2u);
  ret[0] = X[0] / X[2];
  ret[1] = X[1] / X[2];
  return ret;
}

Vec3<Vec3<Real>> grad_pi(Vec3<Real> const& X)
{
  Vec<Vec3<Real>> ret(2);
  Real x = X[0];
  Real y = X[1];
  Real z = X[2];
  Real sz = 1 / z;
  Real szz = sz*sz;

  ret[0] = vec<Real>(sz, 0, -x * szz);
  ret[1] = vec<Real>(0, sz, -y * szz);
  return ret;
}

Vec<Vec<Real>> grad_(Vec<Real> const& x)
{
  Vec<Vec<Real>> ret = numeric_traits<Vec<Vec<Real>>>::zeros_of_shape(x);
  for (size_t i = 0; i < x.size(); ++i)
    ret[i][i] = 1;
  return ret;
}


Vec2<Real> project(Vec3<Real> rotation, Vec3<Real> translation, Vec3<Real> X, Vec5<Real> kappa) {
  Mat3x3<Real> Rot = exp2mat(rotation);
  Real f = kappa[0];
  Real cx = kappa[1];
  Real cy = kappa[2];
  Real k1 = kappa[3];
  Real k2 = kappa[4];
  Mat3x3<Real> K = Mat3x3<Real>(
    vec<Real>(f, 0, cx),
    vec<Real>(0, f, cy),
    vec<Real>(0, 0, 1));
  // ICE:	Mat3x3<Real> K = { { f, 0, cx }, { 0, f, cy }, { 0, 0, 1 } };
  Vec2<Real> p = pi(mmul(K, mmul(Rot, X) + translation));

  return p;
}

tuple < Vec2<Vec3<Real>>, Vec2<Vec3<Real>>, Vec2<Vec3<Real>>, Vec2<Vec<Real>> > grad_project(Vec3<Real> rotation, Vec3<Real> translation, Vec3<Real> X, Vec<Real> kappa) {
  auto grad_rotation = grad_(rotation);
  auto grad_translation = grad_(translation);
  auto grad_X = grad_(X);
  auto grad_kappa = grad_(kappa);

  Mat3x3<Real> Rot = exp2mat(rotation);
  auto grad_Rot = grad_exp2mat(rotation);

  Real f = kappa[0];
  auto grad_f = grad_kappa[0];  // grad_index(kappa,0)
  Real cx = kappa[1];
  auto grad_cx = grad_kappa[1];
  Real cy = kappa[2];
  auto grad_cy = grad_kappa[2];
  Real k1 = kappa[3];
  auto grad_k1 = grad_kappa[3];
  Real k2 = kappa[4];
  auto grad_k2 = grad_kappa[4];
  Vec<Real> e0 = numeric_traits<Vec<Real>>::zeros_of_shape(grad_f);
  Mat3x3<Real> K = Mat3x3<Real>(
    vec<Real>(f, 0, cx),
    vec<Real>(0, f, cy),
    vec<Real>(0, 0, 1));
  Mat3x3<Vec<Real>> grad_K = Mat3x3<Vec<Real>>(
    vec<Vec<Real>>(grad_f, e0, grad_cx),
    vec<Vec<Real>>(e0, grad_f, grad_cy),
    vec<Vec<Real>>(e0, e0, e0));

  Vec3<Real> xcam = mmul(Rot, X) + translation;

  auto grad__Rot_xcam = DOT(grad_₁mmul(Rot, X), grad_Rot);
  auto grad__X_xcam = DOT(grad_₂mmul(Rot, X), grad_X);
  auto grad__translation_xcam = grad_translation;

  Vec3<Real> xhomg = mmul(K, xcam);
  // grad_xhomg = DOT(grad_₁mmul(K, xcam), grad_K) + DOT(grad_₂mmul(K, xcam), grad_xcam);
  auto grad__K_xhomg = DOT(grad_₁mmul(K, xcam), grad_K);
  auto grad__Rot_xhomg = DOT(grad_₂mmul(K, xcam), grad__Rot_xcam);
  auto grad__X_xhomg = DOT(grad_₂mmul(K, xcam), grad__X_xcam);
  auto grad__translation_xhomg = DOT(grad_₂mmul(K, xcam), grad__translation_xcam);

  Vec2<Real> p = pi(xhomg);
  auto grad__K_p = DOT(grad_pi(xhomg), grad__K_xhomg);
  auto grad__Rot_p = DOT(grad_pi(xhomg), grad__Rot_xhomg);
  auto grad__X_p = DOT(grad_pi(xhomg), grad__X_xhomg);
  auto grad__translation_p = DOT(grad_pi(xhomg), grad__translation_xhomg);

  auto g = make_tuple(grad__Rot_p, grad__translation_p, grad__X_p, grad__K_p);

  return g;
}

Vec<Vec2<Real>> residuals(Vec<Vec3<Real>> rotations, Vec<Vec3<Real>> translations, Vec<Vec3<Real>> Xs, Vec<Real> kappas,
  Vec<Vec2<Real>> ms, Vec<int> frames, Vec<int> points)
{
  int nR = ms.size();
  Vec<Vec2<Real>> ret(nR);
  for (size_t i = 0; i < ms.size(); ++i) {
    int f = frames[i];
    int p = points[i];
    ret[i] = project(rotations[f], translations[f], Xs[p], kappas) - ms[i];
  }
  return ret;
}

/*
Vec3<Real> rotation = vec<Real>(1,-2,3);
Vec3<Real> translation = vec<Real>(11, 12, 13);
Vec3<Real> X = vec<Real>(.1, .3, .5);
Vec<Real> kappa = vec<Real>(1.4, 0.01, 0.02, 0, 0);

Vec2<Real> p = project(rotation, translation, X, kappa);

auto grad_p = grad_project(rotation, translation, X, kappa);
*/


#endif
