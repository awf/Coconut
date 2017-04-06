#pragma once

#include "Vec.h"
#include "Mat.h"

typedef double Real;

Mat3x3<Real> exp2mat(Vec3<Real> w)
{
  double x1 = w[0];
  double x2 = w[1];
  double x3 = w[2];

  double t2 = x2*x2;
  double t3 = x1*x1;
  double t4 = x3*x3;
  double t5 = t2 + t3 + t4;
  double t6 = 1.0 / t5;
  double t7 = std::sqrt(t5);
  double t8 = std::cos(t7);
  double t9 = t8 - 1.0;
  double t10 = std::sin(t7);
  double t11 = 1.0 / t7;
  double t12 = t10*t11*x3;
  double t13 = t4*t6;
  double t14 = t10*t11*x1;
  double t15 = t3*t6;
  double t16 = t2*t6;
  double t17 = t6*t6;
  double t18 = t13 + t16;
  double t19 = t11*t11*t11;
  double t20 = t6*t8*x1*x3;
  double t21 = t3*t10*t19*x2;
  double t22 = t3*t9*t17*x2*2.0;
  double t23 = t4*t17*x1*2.0;
  double t24 = t13 + t15;
  double t25 = t10*t19*x1*x2;
  double t26 = t3*t10*t19*x3;
  double t27 = t3*t9*t17*x3*2.0;
  double t28 = t10*t11;
  double t29 = t3*t6*t8;
  double t30 = t9*t17*x1*x2*x3*2.0;
  double t31 = t10*t19*x1*x2*x3;
  double t32 = t3*t17*x1*2.0;
  double t33 = t2*t17*x1*2.0;
  double t34 = t15 + t16;
  double t35 = t6*t8*x2*x3;

  return vec(
    vec<Real>(t9*t18 + 1.0, t12 - t6*t9*x1*x2, -t10*t11*x2 - t6*t9*x1*x3),
    vec<Real>(-t12 - t6*t9*x1*x2, t9*t24 + 1.0, t14 - t6*t9*x2*x3),
    vec<Real>(t10*t11*x2 - t6*t9*x1*x3, -t14 - t6*t9*x2*x3, t9*t34 + 1.0)
    );
}

Vec3<Mat3x3<Real>> grad_exp2mat(Vec3<Real> w)
{
  double x1 = w[0];
  double x2 = w[1];
  double x3 = w[2];

  double t2 = x2*x2;
  double t3 = x1*x1;
  double t4 = x3*x3;
  double t5 = t2 + t3 + t4;
  double t6 = 1.0 / t5;
  double t7 = std::sqrt(t5);
  double t8 = std::cos(t7);
  double t9 = t8 - 1.0;
  double t10 = std::sin(t7);
  double t11 = 1.0 / t7;
  double t12 = t10*t11*x3;
  double t13 = t4*t6;
  double t14 = t10*t11*x1;
  double t15 = t3*t6;
  double t16 = t2*t6;
  double t17 = t6*t6;
  double t18 = t13 + t16;
  double t19 = t11*t11*t11;
  double t20 = t6*t8*x1*x3;
  double t21 = t3*t10*t19*x2;
  double t22 = t3*t9*t17*x2*2.0;
  double t23 = t4*t17*x1*2.0;
  double t24 = t13 + t15;
  double t25 = t10*t19*x1*x2;
  double t26 = t3*t10*t19*x3;
  double t27 = t3*t9*t17*x3*2.0;
  double t28 = t10*t11;
  double t29 = t3*t6*t8;
  double t30 = t9*t17*x1*x2*x3*2.0;
  double t31 = t10*t19*x1*x2*x3;
  double t32 = t3*t17*x1*2.0;
  double t33 = t2*t17*x1*2.0;
  double t34 = t15 + t16;
  double t35 = t6*t8*x2*x3;
  double t36 = t2*t10*t19*x1;
  double t37 = t2*t9*t17*x1*2.0;
  double t38 = t4*t17*x2*2.0;
  double t39 = t6*t8*x1*x2;
  double t40 = t2*t10*t19;
  double t41 = t2*t10*t19*x3;
  double t42 = t2*t9*t17*x3*2.0;
  double t43 = t2*t17*x2*2.0;
  double t44 = t3*t17*x2*2.0;
  double t45 = t10*t19*x2*x3;
  double t46 = t4*t6*t8;
  double t47 = t4*t17*x3*2.0;
  double t48 = t10*t19*x1*x3;
  double t49 = t4*t10*t19*x1;
  double t50 = t4*t9*t17*x1*2.0;
  double t51 = t4*t10*t19*x2;
  double t52 = t4*t9*t17*x2*2.0;
  double t53 = t3*t17*x3*2.0;
  double t54 = t2*t17*x3*2.0;

  Vec3<Mat3x3<Real>> ret;

  ret[0][0][0] = -t9*(t23 + t33) - t10*t11*t18*x1;
  ret[0][0][1] = t20 + t21 + t22 - t6*t9*x2 - t10*t19*x1*x3;
  ret[0][0][2] = t25 + t26 + t27 - t6*t9*x3 - t6*t8*x1*x2;

  ret[0][1][0] = -t20 + t21 + t22 + t48 - t6*t9*x2;
  ret[0][1][1] = -t9*(t23 + t32 - t6*x1*2.0) - t10*t11*t24*x1;
  ret[0][1][2] = t28 + t29 + t30 + t31 - t3*t10*t19;

  ret[0][2][0] = -t25 + t26 + t27 + t39 - t6*t9*x3;
  ret[0][2][1] = -t28 - t29 + t30 + t31 + t3*t10*t19;
  ret[0][2][2] = -t9*(t32 + t33 - t6*x1*2.0) - t10*t11*t34*x1;

  ret[1][0][0] = -t9*(t38 + t43 - t6*x2*2.0) - t10*t11*t18*x2;
  ret[1][0][1] = t35 + t36 + t37 - t6*t9*x1 - t10*t19*x2*x3;
  ret[1][0][2] = -t28 + t30 + t31 + t40 - t2*t6*t8;

  ret[1][1][0] = -t35 + t36 + t37 + t45 - t6*t9*x1;
  ret[1][1][1] = -t9*(t38 + t44) - t10*t11*t24*x2;
  ret[1][1][2] = -t25 + t39 + t41 + t42 - t6*t9*x3;

  ret[1][2][0] = t28 + t30 + t31 - t40 + t2*t6*t8;
  ret[1][2][1] = t25 - t39 + t41 + t42 - t6*t9*x3;
  ret[1][2][2] = -t9*(t43 + t44 - t6*x2*2.0) - t10*t11*t34*x2;

  ret[2][0][0] = -t9*(t47 + t54 - t6*x3*2.0) - t10*t11*t18*x3;
  ret[2][0][1] = t28 + t30 + t31 + t46 - t4*t10*t19;
  ret[2][0][2] = -t35 + t45 + t49 + t50 - t6*t9*x1;

  ret[2][1][0] = -t28 + t30 + t31 - t46 + t4*t10*t19;
  ret[2][1][1] = -t9*(t47 + t53 - t6*x3*2.0) - t10*t11*t24*x3;
  ret[2][1][2] = t20 - t48 + t51 + t52 - t6*t9*x2;

  ret[2][2][0] = t35 - t45 + t49 + t50 - t6*t9*x1;
  ret[2][2][1] = -t20 + t48 + t51 + t52 - t6*t9*x2;
  ret[2][2][2] = -t9*(t53 + t54) - t10*t11*t34*x3;

  return ret;
}
