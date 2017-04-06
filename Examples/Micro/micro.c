#ifdef DPS
#ifdef FUSED
#include "../../C/Outputs/linalg_opt_storaged.h"
#else
#include "../../C/Outputs/linalg_storaged.h"
#endif
#else
#ifdef FUSED
#include "../../C/Outputs/linalg_opt.h"
#else
#include "../../C/Outputs/linalg.h"
#endif
#endif

#ifdef ADD3
    const size_t DIM = 25;
#elif DOT
    const size_t DIM = 100;
#elif CROSS
    const size_t DIM = 3;
#endif


array_array_number_t matrix_fill(card_t rows, card_t cols, number_t value) {
#ifdef DPS
  return TOP_LEVEL_linalg_matrixFill_dps(storage_alloc(MATRIX_ROWS_OFFSET(rows, cols, rows)), rows, cols, value, rows, cols, 0);
#else
  return TOP_LEVEL_linalg_matrixFill(rows, cols, value);
#endif
}

array_number_t vector_fill(card_t rows, number_t value) {
  return matrix_fill(1, rows, value)->arr[0];
}

double dist(int seed) {
  return ((double)rand()/(double)RAND_MAX);
}

number_t vectorSum(array_number_t v) {
	number_t macroDef26 = 0;
	for(int cur_idx = 0; cur_idx < v->length; cur_idx++){
		number_t cur = v->arr[cur_idx];
		
		macroDef26 = (macroDef26) + (cur);
	}
	return macroDef26;
}

int main(int argc, char** argv)
{
	if(argc != 2) {
		printf("You should use the following format for running this program: %s <Number of Iterations>\n", argv[0]);
		exit(1);
	}
	int N = atoi(argv[1]);
	int rng = 42;
    srand(rng);

	array_number_t vec1 = vector_fill(DIM, 0.0);
	array_number_t vec2 = vector_fill(DIM, 0.0);
	array_number_t vec3 = vector_fill(DIM, 0.0);
	for(int i=0; i<DIM; i++) {
		vec1->arr[i] = dist(rng);
		vec2->arr[i] = dist(rng);
		vec3->arr[i] = dist(rng);
	}

#ifdef HOIST
	storage_t s = storage_alloc(VECTOR_ALL_BYTES(DIM));
#endif
	
    timer_t t = tic();

    double total = 0;
    for (int count = 0; count < N; ++count) {
        vec1->arr[0] += 1.0 / (2.0 + vec1->arr[0]);
        vec2->arr[10] += 1.0 / (2.0 + vec2->arr[10]);
#ifdef DPS
#ifndef HOIST
	storage_t s = storage_alloc(VECTOR_ALL_BYTES(DIM));
#endif
#endif
#ifdef ADD3
    #ifdef DPS
        total += vectorSum(TOP_LEVEL_linalg_vectorAdd3_dps(s, vec1, vec2, vec3, DIM, DIM, DIM));
	#else
        total += vectorSum(TOP_LEVEL_linalg_vectorAdd3(vec1, vec2, vec3));
	#endif
#elif DOT
	#ifdef DPS
        total += TOP_LEVEL_linalg_dot_prod_dps(s, vec1, vec2, DIM, DIM);
	#else
        total += TOP_LEVEL_linalg_dot_prod(vec1, vec2);
	#endif
#elif CROSS
    #ifdef DPS
        total += vectorSum(TOP_LEVEL_linalg_cross_dps(s, vec1, vec2, DIM, DIM));
	#else
        total += vectorSum(TOP_LEVEL_linalg_cross(vec1, vec2));
	#endif
#endif
#ifdef DPS
#ifndef HOIST
	storage_free(s, VECTOR_ALL_BYTES(DIM));
#endif
#endif
    }
    float elapsed = toc2(t);
    printf("total =%f, time per call = %f ms\n", total, elapsed / (double)(N));
	return 0;
}
