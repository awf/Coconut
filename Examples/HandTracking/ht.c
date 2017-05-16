#ifdef DPS
// #ifdef FUSED
// #include "../../outputs/C/usecases_ht_opt_storaged.h"
// #else
#include "../../outputs/C/usecases_ht_storaged.h"
// #endif
#else
// #ifdef FUSED
// #include "../../outputs/C/usecases_ht_opt.h"
// #else
#include "../../outputs/C/usecases_ht.h"
// #endif
#endif

double dist01() {
  return ((double)rand()/(double)RAND_MAX);
}

double dist(double min, double max) {
  return dist01() * (max - min) + min;
}

// template <class T, int Size>
// void fillrand(Vec<T, Size>* vec, double min, double max)
// {
//   for (int k = 0; k < vec->size(); ++k)
//     (*vec)[k] = dist(min, max);
// }

double rand01() {
  return dist(0, 1);
}

number_t vectorNorm(array_number_t v) {
  number_t macroDef26 = 0;
  for(int cur_idx = 0; cur_idx < v->length; cur_idx++){
    number_t cur = v->arr[cur_idx];
    
    macroDef26 = (macroDef26) + (cur * cur);
  }
  return macroDef26;
}

array_array_number_t matrix_fill(card_t rows, card_t cols, number_t value) {
#ifdef DPS
  return TOP_LEVEL_linalg_matrixFill_dps(malloc(MATRIX_ROWS_OFFSET(rows, cols, rows)), rows, cols, value, rows, cols, 0);
#else
  return TOP_LEVEL_linalg_matrixFill(rows, cols, value);
#endif
}

array_number_t vector_fill(card_t rows, number_t value) {
  return matrix_fill(1, rows, value)->arr[0];
}

matrix_shape_t matrix_shape(array_array_number_t mat) {
  matrix_shape_t res;
  res.card = mat->length;
  res.elem = mat->arr[0]->length;
  return res;
}

int vector_shape(array_number_t vec) {
  return vec->length;
}

int main(int argc, char** argv)
{
  int rng = 42;
  srand(rng);

  array_number_t angle = vector_fill(3, 0);
  for (int i = 0; i < 3; ++i)
    angle->arr[i] = dist01();


  timer_t t = tic();
#ifdef HOIST
  storage_t s = storage_alloc(256);
#endif

  double total = 0;
  int N = 10000000;
  for (int count = 0; count < N; ++count) {
    angle->arr[0] -= 1.0 / N;
#ifdef DPS
#ifndef HOIST
    storage_t s = storage_alloc(256);
#endif
    array_array_number_t verts = TOP_LEVEL_usecases_ht_angle_axis_to_rotation_matrix_dps(s, angle, 3);
#else
    array_array_number_t verts = TOP_LEVEL_usecases_ht_angle_axis_to_rotation_matrix(angle);
#endif
    array_number_t verts1 = verts->arr[0];
    total += vectorNorm(verts1);
#ifdef DPS
#ifndef HOIST
    storage_free(s, 256);
#endif
#endif
    // printf("%d--\n", count);
  }

  double elapsed = toc2(t);
  printf("total =%f, time per call = %f ms\n", total, elapsed / (double)(N));

  return 0;
}
