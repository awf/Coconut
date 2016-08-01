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
typedef struct env_t_322 {
	array_number_t v;
} env_t_322;
env_t_322* make_env_t_322(array_number_t v) {
	env_t_322* env = (env_t_322*)malloc(sizeof(env_t_322));
	env->v = v;
	return env;
}
typedef struct env_t_323 {
	array_number_t v;
	storage_t storage1;
} env_t_323;
env_t_323* make_env_t_323(array_number_t v,storage_t storage1) {
	env_t_323* env = (env_t_323*)malloc(sizeof(env_t_323));
	env->v = v;
	env->storage1 = storage1;
	return env;
}
typedef struct env_t_324 {
	array_number_t v;
	index_t idx;
} env_t_324;
env_t_324* make_env_t_324(array_number_t v,index_t idx) {
	env_t_324* env = (env_t_324*)malloc(sizeof(env_t_324));
	env->v = v;
	env->idx = idx;
	return env;
}

value_t lambda324(env_t_324* env309, index_t i) {
	array_number_t v308 = env309->v;
	index_t idx307 = env309->idx;
	value_t res;
	res.number_t_value = v308->arr[(i) + (idx307)];
	return res;
}
value_t lambda323(env_t_323* env314, number_t acc, index_t idx) {
	array_number_t v313 = env314->v;
	storage_t storage1312 = env314->storage1;
	closure_t* closure311 = make_closure(lambda324, make_env_t_324(v313,idx));
	array_number_t tmp = vector_build_by_storage(storage1312, closure311);
	value_t res;
	res.number_t_value = linalg_sqnorm(linalg_add_vec(tmp, tmp));
	return res;
}
value_t lambda322(env_t_322* env318, storage_t storage1) {
	array_number_t v317 = env318->v;
	closure_t* closure316 = make_closure(lambda323, make_env_t_323(v317,storage1));
	number_t sum = linalg_iterateNumber(closure316, 0, 0, 9);
	value_t res;
	number_print(sum);
	return res;
}
void programs_explicitMallocExample(array_number_t v) {
	closure_t* closure320 = make_closure(lambda322, make_env_t_322(v));
	vector_alloc_cps(10, closure320);
	return ;
}

void programs_small_tests(number_t dum) {
	number_t a325 = programs_test1(2);
	number_print(a325);
	number_print(programs_test2(2, a325));
	array_number_t v2326 = linalg_vectorRange(0, 99);
	programs_hoistingExample(v2326);
	programs_explicitMallocExample(v2326);
	return ;
}
#endif
