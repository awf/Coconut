
#include "stdafx.h"

#include "usecases_ht.h"

// std::vector<Vec3<Real>> to_pose_params(Vec<Real> const& theta, size_t n_bones)
// {
//   size_t n = 3 + n_bones;
//   std::vector<Vec3<Real>> pose_params{n, vec(0.0,0.0,0.0) };
//   pose_params[0] = theta.segment<3>(0);
//   pose_params[1] = vec(1.0, 1.0, 1.0);
//   pose_params[2] = theta.segment<3>(3);

//   size_t i_theta = 6;
//   int n_fingers = 5;
//   for (int i = 0; i < n_fingers; ++i) {
//     pose_params[3 + i * 3 + 0][0] = theta[i_theta++];
//     pose_params[3 + i * 3 + 0][1] = theta[i_theta++];
//     pose_params[3 + i * 3 + 1][0] = theta[i_theta++];
//     pose_params[3 + i * 3 + 2][0] = theta[i_theta++];

//   }
//   return pose_params;
// }


// Real3x3 euler_angles_to_rotation_matrix(Vec3<Real> xzy)
// {
//   auto tx = xzy[0];
//   auto tz = xzy[1];
//   auto ty = xzy[2];

//   Real3x3 Rx = vec(
//     vec(1., 0., 0.),
//     vec(0., cos(tx), -sin(tx)),
//     vec(0., sin(tx), cos(tx)));

//   Real3x3 Ry = vec(
//     vec(cos(ty), 0., sin(ty)),
//     vec(0., 1., 0.),
//     vec(-sin(ty), 0., cos(ty)));

//   Real3x3 Rz = vec(
//     vec(cos(tz), -sin(tz), 0.),
//     vec(sin(tz), cos(tz), 0.),
//     vec(0., 0., 1.));

//   return Rz*Ry*Rx;
// }

// Real4x4 Rt_to_transform(Real3x3 const& R, Real3 const& t)
// {
//   Mat<Real, 4, 4> T;
//   for (int i = 0; i < 3; ++i) {
//     for (int j = 0; j < 3; ++j)
//       T(i, j) = R(i, j);
//     T(i, 3) = T(3, i) = 0.0;
//   }
//   T(3, 3) = 1.0;
//   return T;
// }

// auto make_relative(Vec3<Real> const& xzy, Real4x4 const& base_relative)
// {
//   auto R = euler_angles_to_rotation_matrix(xzy);
//   Mat<Real, 4, 4> T;
//   for (int i = 0; i < 3; ++i) {
//     for (int j = 0; j < 3; ++j)
//       T(i, j) = R(i, j);
//     T(i, 3) = T(3, i) = 0.0;
//   }
//   T(3, 3) = 1.0;
//   return base_relative * T;
// }


// auto get_posed_relatives(std::vector<Real4x4> const& base_relatives, std::vector<Vec3<Real>> pose_params)
// {
//   size_t offset = 3;
//   size_t n_bones = base_relatives.size();

//   std::vector<Real4x4> ret{ n_bones };
//   for (size_t i_bone = 0; i_bone < n_bones; ++i_bone)
//     ret[i_bone] = make_relative(pose_params[i_bone + offset], base_relatives[i_bone]);

//   return ret;
// }

// auto relatives_to_absolutes(std::vector<Real4x4> const& relatives, std::vector<int> const& parents)
// {
//   std::vector<Real4x4> absolutes{ relatives.size(), identity<Real,4>() };
//   for (size_t i = 0; i < parents.size(); ++i)
//     if (parents[i] == -1)
//       absolutes[i] = relatives[i];
//     else
//       absolutes[i] = absolutes[parents[i]] * relatives[i];
//   return absolutes;
// }

Real3x3 angle_axis_to_rotation_matrix(Real3 const& angle_axis)
{
  auto n = sqrt(sumsq(angle_axis));
  if (n < 0.0001)
    return vec(
      vec(1., 0., 0.),
      vec(0., 1., 0.),
      vec(0., 0., 1.)
      );

  Real x = angle_axis[0] / n;
  Real y = angle_axis[1] / n;
  Real z = angle_axis[2] / n;

  Real s = sin(n);
  Real c = cos(n);

  return vec(
    vec(x*x + (1. - x*x)*c, x*y*(1. - c) - z*s, x*z*(1. - c) + y*s),
    vec(x*y*(1. - c) + z*s, y*y + (1. - y*y)*c, y*z*(1. - c) - x*s),
    vec(x*z*(1. - c) - y*s, z*y*(1. - c) + x*s, z*z + (1. - z*z)*c));
}

// auto apply_global_transform(std::vector<Vec3<Real>> const& pose_params, Mat<Real, 3, 0> const& positions)
// {
//   auto R = angle_axis_to_rotation_matrix(pose_params[0]);
//   Real3x3 scale = diaginv(pose_params[1]);
//   R = scale * R;
//   auto ret = R * positions;
//   for (size_t i = 0; i < positions.size(); ++i)
//     ret[i] = positions[i] + pose_params[2];
//   return ret;
// }

// Mat<Real, 3, N_VERTS> 
// get_skinned_vertex_positions(std::vector<Real4x4> const& base_relatives,
//   std::vector<int> const& parents,
//   Mat<Real, 3, N_VERTS> const& base_positions,
//   Mat<Real, N_VERTS, N_BONES> const& weights,
//   std::vector<Vec3<Real>> const& pose_params)
// {
//   auto relatives = get_posed_relatives(base_relatives, pose_params);
//   auto absolutes = relatives_to_absolutes(relatives, parents);

//   auto transforms = absolutes; //  Array.map2 (*) absolutes model.inverse_base_absolutes

//   size_t n_verts = base_positions.cols();

//   Mat<Real, 4, N_VERTS> base_positions_homg{ 4, n_verts, 0.0 };
//   for (size_t i = 0; i < n_verts; ++i)
//     base_positions_homg[i] = vec(base_positions[i][0], base_positions[i][1], base_positions[i][2], 1.0);

//   Mat<Real, 3, 0> positions{ 3, n_verts, 0.0 };

//   for (size_t i_transform = 0; i_transform < transforms.size(); ++i_transform) {
//     Mat<Real, 3, N_VERTS> curr_positions = transforms[i_transform].block<3,4>(0,0) * base_positions_homg;
//     for (int j = 0; j < n_verts; ++j)
//       positions[j] = positions[j] + curr_positions[j].segment<3>(0) * weights(j, i_transform);
//   }

//   return apply_global_transform(pose_params, positions);
// }

