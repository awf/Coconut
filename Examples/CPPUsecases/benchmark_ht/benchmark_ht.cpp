// benchmark_gmm.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <random>

#include "usecases_ht.h"

// std::mt19937 rng(42);

// template <class T, size_t Size, class DIST>
// void fillrand(Vec<T, Size>* vec, DIST& dist)
// {
//   for (int k = 0; k < vec->size(); ++k)
//     (*vec)[k] = dist(rng);
// }


Real dist01() {
  return ((double)rand()/(double)RAND_MAX);
}

Real dist(double min, double max) {
  return dist01() * (max - min) + min;
}

// template <class T, int Size>
// void fillrand(Vec<T, Size>* vec, double min, double max)
// {
//   for (int k = 0; k < vec->size(); ++k)
//     (*vec)[k] = dist(min, max);
// }

Real rand01() {
  return dist(0, 1);
}


int main()
{
  int rng = 42;
  srand(rng);
  // std::uniform_real_distribution<Real> dist(0, 1);
  // auto rand = [&dist] { return dist(rng); };


  // Vec<Real> theta{ 26 };
  // size_t n_bones = 15;
  // size_t n_verts = 500;

  // fillrand(&theta, -1, 1);

  // Mat<Real, 3, N_VERTS> base_positions{ 3, n_verts };
  // for (int i = 0; i < n_verts; ++i)
  //   fillrand(&base_positions[i], 1, 10);

  // std::vector<Real4x4> base_relatives{ n_bones };
  // for (int i = 0; i < n_bones; ++i) {
  //   Vec<Real, 3> rvec; 
  //   fillrand(&rvec, -2, 2);
  //   Vec<Real, 3> tvec; 
  //   fillrand(&tvec, 1, 2);
  //   base_relatives[i] = Rt_to_transform(angle_axis_to_rotation_matrix(rvec), tvec);
  // }
    
  // std::vector<int> parents{ 
  //   -1,  0,  1, 
  //   -1,  3,  4,
  //   -1,  6,  7,
  //   -1,  9, 10,
  //   -1, 12, 13,
  //   };

  // Mat<Real, N_VERTS, N_BONES> weights{ n_verts, n_bones };
  // for (int i = 0; i < n_verts; ++i) 
  //   for (int j = 0; j < n_bones; ++j) {
  //     if (rand01() < 4.0 / n_bones)
  //       weights[j][i] = rand01();
  //   }


  // boost::timer::auto_cpu_timer t;
  timer_t t = tic();

  // Debug 150s 
  // Release 1s
  double total = 0;
  size_t N = 10000000;
  // std::vector<Vec3<Real>> pose_params = to_pose_params(theta, n_bones);
  // printf("%f-%f-%f:%f\n", pose_params[0][0], pose_params[0][1], pose_params[0][2], sumsq(pose_params[0]));
  // Vec3<Real> angle = pose_params[0];
  Real3 angle;
  for(int i=0; i<3; i++) {
    angle[i] = rand01();
  }
#ifdef _DEBUG
  N = N / 10;  // Debug is roughly this much slower than release -- multiply timings.
#endif
  for (size_t count = 0; count < N; ++count) {
    angle[0] -= 1.0 / N;
    // Mat<Real, 3, N_VERTS> verts = get_skinned_vertex_positions(base_relatives, parents, base_positions, weights, pose_params);
    Real3x3 verts = angle_axis_to_rotation_matrix(angle);
    Real3 verts1 = verts[0];
    total += sumsq(verts1);
    // total += verts[0][0] + verts[1][1] + verts[2][2];
  }

  // std::cout << "total =" << total << ", time per call = " << t.elapsed().wall / double(N) / 1e6 << "ms" << std::endl;
  auto elapsed = toc(t);
  printf("total =%f, time per call = %f ms\n", total, elapsed / double(N));

  return 0;
}
