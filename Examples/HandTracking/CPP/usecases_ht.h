#pragma once

#include "stdafx.h"

typedef VecF<Real, 3> Real3;
typedef Mat<Real, 3, 3> Real3x3;
// typedef Mat<Real, 4, 4> Real4x4;

// const size_t N_VERTS = 0;  // 0 => determined at runtime
// const size_t N_BONES = 0;  // 0 => determined at runtime
// const size_t N_PARAMS = 0; // 0 => determined at runtime

Real3x3 angle_axis_to_rotation_matrix(Real3 const& angle_axis);
// std::vector<Vec3<Real>> to_pose_params(Vec<Real> const& theta, size_t n_bones);
// Real4x4 Rt_to_transform(Real3x3 const& R, Real3 const& t);

// Mat<Real, 3, N_VERTS> get_skinned_vertex_positions(std::vector<Real4x4> const& base_relatives,
//                                                    std::vector<int> const& parents,
//                                                    Mat<Real, 3, N_VERTS> const& base_positions,
//                                                    Mat<Real, N_VERTS, N_BONES> const& weights,
//                                                    std::vector<Vec3<Real>> const& pose_params);
