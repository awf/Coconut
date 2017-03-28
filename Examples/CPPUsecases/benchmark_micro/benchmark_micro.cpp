#include <random>

#include "stdafx.h"

typedef Vec<Real> Vector;


Real dist(int seed) {
  return ((double)rand()/(double)RAND_MAX);
}


int main(int argc, char** argv)
{
  if(argc != 2) {
    printf("You should use the following format for running this program: %s <Number of Iterations>\n", argv[0]);
    exit(1);
  }
  cardinality_t N = atoi(argv[1]);
  int rng = 42;
  srand(rng);

#ifdef ADD3
    cardinality_t DIM = 100;
    Vector vec1{ DIM };
    Vector vec2{ DIM };
    Vector vec3{ DIM };
    // VecF<Real, 100> vec1;
    // VecF<Real, 100> vec2;
    // VecF<Real, 100> vec3;
#elif DOT
    cardinality_t DIM = 100;
    Vector vec1{ DIM };
    Vector vec2{ DIM };
#elif CROSS
    cardinality_t DIM = 3;
    Vec3<Real> vec1;
    Vec3<Real> vec2;
#endif

  for (cardinality_t k = 0; k < DIM; ++k) {
    vec1[k] = dist(rng);
    vec2[k] = dist(rng);
#ifdef ADD3
    vec3[k] = dist(rng);
#endif
  }

  timer_t t = tic();

  double total = 0;

  for (cardinality_t count = 0; count < N; ++count) {
    vec1[0] += 1.0 / (2.0 + vec1[0]);
    vec2[1] += 1.0 / (2.0 + vec2[1]);
#ifdef ADD3
  #ifdef EIGEN
    total += sum((vec1 + vec2 + vec3).eval());
  #else
    total += sum((vec1 + vec2 + vec3));
  #endif
#elif DOT
    total += dot(vec1, vec2);
#elif CROSS
    total += sum(cross(vec1, vec2));
#endif
  }

  auto elapsed = toc(t);
  printf("total =%f, time per call = %f ms\n", total, elapsed / double(N));

  return 0;
}
