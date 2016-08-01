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
typedef struct env_t_306 {
	array_number_t v;
} env_t_306;
env_t_306* make_env_t_306(array_number_t v) {
	env_t_306* env = (env_t_306*)malloc(sizeof(env_t_306));
	env->v = v;
	return env;
}

value_t lambda306(env_t_306* env302, number_t acc296, index_t idx297) {
	array_number_t v301 = env302->v;
	array_number_t tmp298 = array_slice(v301, idx297, (idx297) + (9));
	value_t res;
	res.number_t_value = linalg_sqnorm(linalg_add_vec(tmp298, tmp298));
	return res;
}
void programs_hoistingExample(array_number_t v) {
	closure_t* closure304 = make_closure(lambda306, make_env_t_306(v));
	number_print(linalg_iterateNumber(closure304, 0, 0, 9));
	return ;
}
typedef struct env_t_318 {
	array_number_t v;
	storage_t storage1;
} env_t_318;
env_t_318* make_env_t_318(array_number_t v,storage_t storage1) {
	env_t_318* env = (env_t_318*)malloc(sizeof(env_t_318));
	env->v = v;
	env->storage1 = storage1;
	return env;
}
typedef struct env_t_319 {
	array_number_t v;
	index_t idx;
} env_t_319;
env_t_319* make_env_t_319(array_number_t v,index_t idx) {
	env_t_319* env = (env_t_319*)malloc(sizeof(env_t_319));
	env->v = v;
	env->idx = idx;
	return env;
}

value_t lambda319(env_t_319* env309, index_t i) {
	array_number_t v308 = env309->v;
	index_t idx307 = env309->idx;
	value_t res;
	res.number_t_value = v308->arr[(i) + (idx307)];
	return res;
}
value_t lambda318(env_t_319* env314, number_t acc, index_t idx) {
	array_number_t v313 = env314->v;
	storage_t storage1312 = env314->storage1;
	closure_t* closure311 = make_closure(lambda319, make_env_t_319(v313,idx));
	array_number_t tmp = vector_build_by_storage(storage1312, closure311);
	value_t res;
	res.number_t_value = linalg_sqnorm(linalg_add_vec(tmp, tmp));
	return res;
}
void programs_explicitMallocExample(array_number_t v) {
	storage_t storage1 = vector_alloc(10);
	closure_t* closure316 = make_closure(lambda318, make_env_t_318(v,storage1));
	number_t res = linalg_iterateNumber(closure316, 0, 0, 9);
	number_print(res);
	return ;
}

void programs_small_tests(number_t dum) {
	number_t a320 = programs_test1(2);
	number_print(a320);
	number_print(programs_test2(2, a320));
	array_number_t v2321 = linalg_vectorRange(0, 99);
	programs_hoistingExample(v2321);
	programs_explicitMallocExample(v2321);
	return ;
}
#endif
