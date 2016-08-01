#ifndef __CCODEGENTESTS_H__ 
#define __CCODEGENTESTS_H__ 
#include "runtime/fsharp.h"
#include <stdio.h>
#include <math.h>
typedef struct env_t_341 {
	value_t dummy_variable;
} env_t_341;
env_t_341* make_env_t_341() {
	env_t_341* env = (env_t_341*)malloc(sizeof(env_t_341));
	
	return env;
}
typedef struct env_t_342 {
	value_t dummy_variable;
} env_t_342;
env_t_342* make_env_t_342() {
	env_t_342* env = (env_t_342*)malloc(sizeof(env_t_342));
	
	return env;
}

value_t lambda342(env_t_342* env335, index_t j) {
	
	value_t res;
	res.number_t_value = (double)(j);
	return res;
}
value_t lambda341(env_t_341* env338, index_t i) {
	closure_t* closure337 = make_closure(lambda342, make_env_t_342());
	value_t res;
	res.array_number_t_value = vector_build(20, closure337);
	return res;
}
array_array_number_t ccodegentests_closure_bug1(array_array_number_t m1, array_array_number_t m2) {
	closure_t* closure340 = make_closure(lambda341, make_env_t_341());
	return matrix_build(10, closure340);
}
typedef struct env_t_350 {
	value_t dummy_variable;
} env_t_350;
env_t_350* make_env_t_350() {
	env_t_350* env = (env_t_350*)malloc(sizeof(env_t_350));
	
	return env;
}
typedef struct env_t_351 {
	index_t i;
} env_t_351;
env_t_351* make_env_t_351(index_t i) {
	env_t_351* env = (env_t_351*)malloc(sizeof(env_t_351));
	env->i = i;
	return env;
}

value_t lambda351(env_t_351* env344, index_t j) {
	index_t i343 = env344->i;
	value_t res;
	res.number_t_value = (double)((i343) + (j));
	return res;
}
value_t lambda350(env_t_350* env347, index_t i) {
	closure_t* closure346 = make_closure(lambda351, make_env_t_351(i));
	value_t res;
	res.array_number_t_value = vector_build(20, closure346);
	return res;
}
array_array_number_t ccodegentests_closure_bug2(array_array_number_t m1, array_array_number_t m2) {
	closure_t* closure349 = make_closure(lambda350, make_env_t_350());
	return matrix_build(10, closure349);
}
typedef struct env_t_361 {
	number_t n;
} env_t_361;
env_t_361* make_env_t_361(number_t n) {
	env_t_361* env = (env_t_361*)malloc(sizeof(env_t_361));
	env->n = n;
	return env;
}
typedef struct env_t_362 {
	number_t n;
	index_t i;
} env_t_362;
env_t_362* make_env_t_362(number_t n,index_t i) {
	env_t_362* env = (env_t_362*)malloc(sizeof(env_t_362));
	env->n = n;
	env->i = i;
	return env;
}

value_t lambda362(env_t_362* env354, index_t j) {
	number_t n353 = env354->n;
	index_t i352 = env354->i;
	value_t res;
	res.number_t_value = ((double)((i352) + (j))) * (n353);
	return res;
}
value_t lambda361(env_t_361* env358, index_t i) {
	number_t n357 = env358->n;
	closure_t* closure356 = make_closure(lambda362, make_env_t_362(n357,i));
	value_t res;
	res.array_number_t_value = vector_build(20, closure356);
	return res;
}
array_array_number_t ccodegentests_closure_bug3(array_array_number_t m1, array_array_number_t m2) {
	number_t n = 3;
	closure_t* closure360 = make_closure(lambda361, make_env_t_361(n));
	return matrix_build(10, closure360);
}
#endif
