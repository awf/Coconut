#ifndef __PROGRAMS_H__ 
#define __PROGRAMS_H__ 
#include "runtime/fsharp.h"
#include <stdio.h>
#include <math.h>
#include "linalg.h"

number_t programs_test1(number_t x) {
	
	return (1) / ((1) + (x));
}

number_t programs_test2(number_t x, number_t b) {
	
	return x;
}

array_number_t programs_vector_add3(array_number_t v1, array_number_t v2, array_number_t v3) {
	
	return linalg_add_vec(v1, linalg_add_vec(v2, v3));
}

array_array_number_t programs_matrix_add3(array_array_number_t m1, array_array_number_t m2, array_array_number_t m3) {
	
	return linalg_matrixAdd(m1, linalg_matrixAdd(m2, m3));
}

void programs_hoistingExample(array_number_t v) {
	number_t macroDef780 = 0;
	for(int idx = 0; idx <= 9; idx++){
		array_number_t tmp = array_slice(v, idx, (idx) + (9));
		macroDef780 = (macroDef780) + (linalg_sqnorm(linalg_add_vec(tmp, tmp)));
	}
	number_t sum = macroDef780;
	number_print(sum);
	return ;
}
typedef struct env_t_798 {
	array_number_t v;
	index_t idx;
} env_t_798;
env_t_798 make_env_t_798(array_number_t v,index_t idx) {
	env_t_798 env;
	env.v = v;
	env.idx = idx;
	return env;
}

value_t lambda798(env_t_798* env787, index_t i) {
	array_number_t v786 = env787->v;
	index_t idx785 = env787->idx;
	value_t res;
	res.number_t_value = v786->arr[(i) + (idx785)];
	return res;
}
void programs_explicitMallocExample1(array_number_t v) {
	array_number_t storage1 = vector_alloc(10);
	number_t macroDef794 = 0;
	for(int idx = 0; idx <= 9; idx++){
		env_t_798 env_t_798_value = make_env_t_798(v,idx); closure_t closure789 = make_closure(lambda798, &env_t_798_value);
		array_number_t tmp = vector_build_given_storage(storage1, closure789);
		macroDef794 = (macroDef794) + (linalg_sqnorm(linalg_add_vec(tmp, tmp)));
	}
	number_t sum = macroDef794;
	number_print(sum);
	free(storage1);
	;
	return ;
}
typedef struct env_t_815 {
	array_number_t v;
	index_t idx;
} env_t_815;
env_t_815 make_env_t_815(array_number_t v,index_t idx) {
	env_t_815 env;
	env.v = v;
	env.idx = idx;
	return env;
}

value_t lambda815(env_t_815* env803, index_t i) {
	array_number_t v802 = env803->v;
	index_t idx801 = env803->idx;
	value_t res;
	res.number_t_value = v802->arr[(i) + (idx801)];
	return res;
}
void programs_explicitMallocExample2(array_number_t v) {
	array_number_t storage1 = vector_alloc(10);
	array_number_t storage2 = vector_alloc(10);
	number_t macroDef810 = 0;
	for(int idx = 0; idx <= 9; idx++){
		env_t_815 env_t_815_value = make_env_t_815(v,idx); closure_t closure805 = make_closure(lambda815, &env_t_815_value);
		array_number_t tmp = vector_build_given_storage(storage1, closure805);
		array_number_t tmp2 = linalg_add_vecGivenStorage(storage2, tmp, tmp);
		macroDef810 = (macroDef810) + (linalg_sqnorm(tmp2));
	}
	number_t sum = macroDef810;
	number_print(sum);
	free(storage2);
	;
	free(storage1);
	;
	return ;
}

void programs_small_tests(number_t dum) {
	number_t a816 = programs_test1(2);
	number_print(a816);
	number_print(programs_test2(2, a816));
	array_number_t v2817 = linalg_vectorRange(0, 99);
	programs_hoistingExample(v2817);
	programs_explicitMallocExample1(v2817);
	programs_explicitMallocExample2(v2817);
	return ;
}
#endif
