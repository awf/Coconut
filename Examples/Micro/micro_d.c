#ifdef FUSED
#include "../../outputs/C/linalg_opt_d.h"
#else
#include "../../outputs/C/linalg_d.h"
#endif

#ifdef ADD3
    const size_t DIM = 100;
#elif DOT
    const size_t DIM = 100;
#elif CROSS
    const size_t DIM = 3;
#endif


array_array_number_t matrix_fill(card_t rows, card_t cols, number_t value) {
  return TOP_LEVEL_linalg_matrixFill(rows, cols, value);
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
	
    timer_t t = tic();

    double total = 0;
    for (int count = 0; count < N; ++count) {
        vec1->arr[0] += 1.0 / (2.0 + vec1->arr[0]);
        vec2->arr[1] += 1.0 / (2.0 + vec2->arr[1]);
#ifdef ADD3
        total += vectorSum(TOP_LEVEL_linalg_vectorAdd3_d(vec1, vec2, vec3, vec1, vec2, vec3));
#elif DOT
        total += TOP_LEVEL_linalg_dot_prod_d(vec1, vec2, vec1, vec2);
#elif CROSS
        total += vectorSum(TOP_LEVEL_linalg_cross_d(vec1, vec2, vec1, vec2));
#endif
    }
    float elapsed = toc2(t);
    printf("total =%f, time per call = %f ms\n", total, elapsed / (double)(N));
	return 0;
}
