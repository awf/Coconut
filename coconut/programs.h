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
typedef struct env_t_317 {
	array_number_t v;
} env_t_317;
env_t_317 make_env_t_317(array_number_t v) {
	env_t_317 env;
	env.v = v;
	return env;
}

value_t lambda317(env_t_317* env313, number_t acc307, index_t idx308) {
	array_number_t v312 = env313->v;
	array_number_t tmp309 = array_slice(v312, idx308, (idx308) + (9));
	value_t res;
	res.number_t_value = linalg_sqnorm(linalg_add_vec(tmp309, tmp309));
	return res;
}
void programs_hoistingExample(array_number_t v) {
	env_t_317 env_t_317_value = make_env_t_317(v); closure_t closure315 = make_closure(lambda317, &env_t_317_value);
	number_print(linalg_iterateNumber(closure315, 0, 0, 9));
	return ;
}
typedef struct env_t_333 {
	array_number_t v;
} env_t_333;
env_t_333 make_env_t_333(array_number_t v) {
	env_t_333 env;
	env.v = v;
	return env;
}
typedef struct env_t_334 {
	array_number_t v;
	storage_t storage1;
} env_t_334;
env_t_334 make_env_t_334(array_number_t v,storage_t storage1) {
	env_t_334 env;
	env.v = v;
	env.storage1 = storage1;
	return env;
}
typedef struct env_t_335 {
	array_number_t v;
	index_t idx;
} env_t_335;
env_t_335 make_env_t_335(array_number_t v,index_t idx) {
	env_t_335 env;
	env.v = v;
	env.idx = idx;
	return env;
}

value_t lambda335(env_t_335* env320, index_t i) {
	array_number_t v319 = env320->v;
	index_t idx318 = env320->idx;
	value_t res;
	res.number_t_value = v319->arr[(i) + (idx318)];
	return res;
}
value_t lambda334(env_t_334* env325, number_t acc, index_t idx) {
	array_number_t v324 = env325->v;
	storage_t storage1323 = env325->storage1;
	env_t_335 env_t_335_value = make_env_t_335(v324,idx); closure_t closure322 = make_closure(lambda335, &env_t_335_value);
	array_number_t tmp = vector_build_given_storage(storage1323, closure322);
	value_t res;
	res.number_t_value = linalg_sqnorm(linalg_add_vec(tmp, tmp));
	return res;
}
value_t lambda333(env_t_333* env329, storage_t storage1) {
	array_number_t v328 = env329->v;
	env_t_334 env_t_334_value = make_env_t_334(v328,storage1); closure_t closure327 = make_closure(lambda334, &env_t_334_value);
	number_t sum = linalg_iterateNumber(closure327, 0, 0, 9);
	value_t res;
	number_print(sum);
	return res;
}
void programs_explicitMallocExample1(array_number_t v) {
	env_t_333 env_t_333_value = make_env_t_333(v); closure_t closure331 = make_closure(lambda333, &env_t_333_value);
	vector_alloc_cps(10, closure331);
	return ;
}
typedef struct env_t_351 {
	array_number_t v;
} env_t_351;
env_t_351 make_env_t_351(array_number_t v) {
	env_t_351 env;
	env.v = v;
	return env;
}
typedef struct env_t_352 {
	array_number_t v;
	storage_t storage1;
} env_t_352;
env_t_352 make_env_t_352(array_number_t v,storage_t storage1) {
	env_t_352 env;
	env.v = v;
	env.storage1 = storage1;
	return env;
}
typedef struct env_t_353 {
	array_number_t v;
	index_t idx;
} env_t_353;
env_t_353 make_env_t_353(array_number_t v,index_t idx) {
	env_t_353 env;
	env.v = v;
	env.idx = idx;
	return env;
}

value_t lambda353(env_t_353* env338, index_t i) {
	array_number_t v337 = env338->v;
	index_t idx336 = env338->idx;
	value_t res;
	res.number_t_value = v337->arr[(i) + (idx336)];
	return res;
}
value_t lambda352(env_t_352* env343, number_t acc, index_t idx) {
	array_number_t v342 = env343->v;
	storage_t storage1341 = env343->storage1;
	env_t_353 env_t_353_value = make_env_t_353(v342,idx); closure_t closure340 = make_closure(lambda353, &env_t_353_value);
	array_number_t tmp = vector_build_given_storage(storage1341, closure340);
	value_t res;
	res.number_t_value = linalg_sqnorm(linalg_add_vecGivenStorage(storage1341, tmp, tmp));
	return res;
}
value_t lambda351(env_t_351* env347, storage_t storage1) {
	array_number_t v346 = env347->v;
	env_t_352 env_t_352_value = make_env_t_352(v346,storage1); closure_t closure345 = make_closure(lambda352, &env_t_352_value);
	number_t sum = linalg_iterateNumber(closure345, 0, 0, 9);
	value_t res;
	number_print(sum);
	return res;
}
void programs_explicitMallocExample2(array_number_t v) {
	env_t_351 env_t_351_value = make_env_t_351(v); closure_t closure349 = make_closure(lambda351, &env_t_351_value);
	vector_alloc_cps(10, closure349);
	return ;
}

void programs_small_tests(number_t dum) {
	number_t a354 = programs_test1(2);
	number_print(a354);
	number_print(programs_test2(2, a354));
	array_number_t v2355 = linalg_vectorRange(0, 99);
	programs_hoistingExample(v2355);
	programs_explicitMallocExample1(v2355);
	programs_explicitMallocExample2(v2355);
	return ;
}
#endif
