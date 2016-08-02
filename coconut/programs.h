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
typedef struct env_t_312 {
	array_number_t v;
} env_t_312;
env_t_312 make_env_t_312(array_number_t v) {
	env_t_312 env;
	env.v = v;
	return env;
}

value_t lambda312(env_t_312* env308, number_t acc, index_t idx) {
	array_number_t v307 = env308->v;
	array_number_t tmp = array_slice(v307, idx, (idx) + (9));
	value_t res;
	res.number_t_value = (acc) + (linalg_sqnorm(linalg_add_vec(tmp, tmp)));
	return res;
}
void programs_hoistingExample(array_number_t v) {
	env_t_312 env_t_312_value = make_env_t_312(v); closure_t closure310 = make_closure(lambda312, &env_t_312_value);
	number_t sum = linalg_iterateNumber(closure310, 0, 0, 9);
	number_print(sum);
	return ;
}
typedef struct env_t_328 {
	array_number_t v;
} env_t_328;
env_t_328 make_env_t_328(array_number_t v) {
	env_t_328 env;
	env.v = v;
	return env;
}
typedef struct env_t_329 {
	array_number_t v;
	storage_t storage1;
} env_t_329;
env_t_329 make_env_t_329(array_number_t v,storage_t storage1) {
	env_t_329 env;
	env.v = v;
	env.storage1 = storage1;
	return env;
}
typedef struct env_t_330 {
	array_number_t v;
	index_t idx;
} env_t_330;
env_t_330 make_env_t_330(array_number_t v,index_t idx) {
	env_t_330 env;
	env.v = v;
	env.idx = idx;
	return env;
}

value_t lambda330(env_t_330* env315, index_t i) {
	array_number_t v314 = env315->v;
	index_t idx313 = env315->idx;
	value_t res;
	res.number_t_value = v314->arr[(i) + (idx313)];
	return res;
}
value_t lambda329(env_t_329* env320, number_t acc, index_t idx) {
	array_number_t v319 = env320->v;
	storage_t storage1318 = env320->storage1;
	env_t_330 env_t_330_value = make_env_t_330(v319,idx); closure_t closure317 = make_closure(lambda330, &env_t_330_value);
	array_number_t tmp = vector_build_given_storage(storage1318, closure317);
	value_t res;
	res.number_t_value = linalg_sqnorm(linalg_add_vec(tmp, tmp));
	return res;
}
value_t lambda328(env_t_328* env324, storage_t storage1) {
	array_number_t v323 = env324->v;
	env_t_329 env_t_329_value = make_env_t_329(v323,storage1); closure_t closure322 = make_closure(lambda329, &env_t_329_value);
	number_t sum = linalg_iterateNumber(closure322, 0, 0, 9);
	value_t res;
	number_print(sum);
	return res;
}
void programs_explicitMallocExample1(array_number_t v) {
	env_t_328 env_t_328_value = make_env_t_328(v); closure_t closure326 = make_closure(lambda328, &env_t_328_value);
	vector_alloc_cps(10, closure326);
	return ;
}
typedef struct env_t_352 {
	array_number_t v;
} env_t_352;
env_t_352 make_env_t_352(array_number_t v) {
	env_t_352 env;
	env.v = v;
	return env;
}
typedef struct env_t_353 {
	array_number_t v;
	storage_t storage1;
} env_t_353;
env_t_353 make_env_t_353(array_number_t v,storage_t storage1) {
	env_t_353 env;
	env.v = v;
	env.storage1 = storage1;
	return env;
}
typedef struct env_t_354 {
	array_number_t v;
	storage_t storage2;
	storage_t storage1;
} env_t_354;
env_t_354 make_env_t_354(array_number_t v,storage_t storage2,storage_t storage1) {
	env_t_354 env;
	env.v = v;
	env.storage2 = storage2;
	env.storage1 = storage1;
	return env;
}
typedef struct env_t_355 {
	array_number_t v;
	index_t idx;
} env_t_355;
env_t_355 make_env_t_355(array_number_t v,index_t idx) {
	env_t_355 env;
	env.v = v;
	env.idx = idx;
	return env;
}

value_t lambda355(env_t_355* env333, index_t i) {
	array_number_t v332 = env333->v;
	index_t idx331 = env333->idx;
	value_t res;
	res.number_t_value = v332->arr[(i) + (idx331)];
	return res;
}
value_t lambda354(env_t_354* env339, number_t acc, index_t idx) {
	array_number_t v338 = env339->v;
	storage_t storage2337 = env339->storage2;
	storage_t storage1336 = env339->storage1;
	env_t_355 env_t_355_value = make_env_t_355(v338,idx); closure_t closure335 = make_closure(lambda355, &env_t_355_value);
	array_number_t tmp = vector_build_given_storage(storage1336, closure335);
	array_number_t tmp2 = linalg_add_vecGivenStorage(storage2337, tmp, tmp);
	value_t res;
	res.number_t_value = linalg_sqnorm(tmp2);
	return res;
}
value_t lambda353(env_t_353* env344, storage_t storage2) {
	array_number_t v343 = env344->v;
	storage_t storage1342 = env344->storage1;
	env_t_354 env_t_354_value = make_env_t_354(v343,storage2,storage1342); closure_t closure341 = make_closure(lambda354, &env_t_354_value);
	number_t sum = linalg_iterateNumber(closure341, 0, 0, 9);
	value_t res;
	number_print(sum);
	return res;
}
value_t lambda352(env_t_352* env348, storage_t storage1) {
	array_number_t v347 = env348->v;
	env_t_353 env_t_353_value = make_env_t_353(v347,storage1); closure_t closure346 = make_closure(lambda353, &env_t_353_value);
	value_t res;
	vector_alloc_cps(10, closure346);
	return res;
}
void programs_explicitMallocExample2(array_number_t v) {
	env_t_352 env_t_352_value = make_env_t_352(v); closure_t closure350 = make_closure(lambda352, &env_t_352_value);
	vector_alloc_cps(10, closure350);
	return ;
}

void programs_small_tests(number_t dum) {
	number_t a356 = programs_test1(2);
	number_print(a356);
	number_print(programs_test2(2, a356));
	array_number_t v2357 = linalg_vectorRange(0, 99);
	programs_hoistingExample(v2357);
	programs_explicitMallocExample1(v2357);
	programs_explicitMallocExample2(v2357);
	return ;
}
#endif
