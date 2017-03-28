// usecases_ba.h: Bundle Adjustment

#include "stdafx.h"
#include <math.h>

static const int N_CAM_PARAMS = 11;
static const int ROT_IDX = 0;
static const int CENTER_IDX = 3;
static const int FOCAL_IDX = 6;
static const int X0_IDX = 7;
static const int RAD_IDX = 9;

Vec2<Real> radial_distort(Vec2<Real> rad_params, Vec2<Real> proj);
Vec3<Real> rodrigues_rotate_point(Vec3<Real> rot, Vec3<Real> x);
Vec2<Real> project(VecF<Real, N_CAM_PARAMS> cam, Vec3<Real> x);
Vec2<Real> compute_reproj_err(VecF<Real, N_CAM_PARAMS> cam, Vec3<Real> x, Real w, Vec2<Real> feat);
