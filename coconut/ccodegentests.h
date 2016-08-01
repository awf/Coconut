#ifndef __CCODEGENTESTS_H__ 
#define __CCODEGENTESTS_H__ 
#include "runtime/fsharp.h"
#include <stdio.h>
#include <math.h>
typedef struct env_t_336 {
	value_t dummy_variable;
} env_t_336;
env_t_336* make_env_t_336() {
	env_t_336* env = (env_t_336*)malloc(sizeof(env_t_336));
	
	return env;
}
typedef struct env_t_337 {
	value_t dummy_variable;
} env_t_337;
env_t_337* make_env_t_337() {
	env_t_337* env = (env_t_337*)malloc(sizeof(env_t_337));
	
	return env;
}

value_t lambda337(env_t_337* env330, index_t j) {
	
	value_t res;
	res.number_t_value = (double)(j);
	return res;
}
value_t lambda336(env_t_337* env333, index_t i) {
	closure_t* closure332 = make_closure(lambda337, make_env_t_337());
	value_t res;
	res.array_number_t_value = vector_build(20, closure332);
	return res;
}
array_array_number_t ccodegentests_closure_bug1(array_array_number_t m1, array_array_number_t m2) {
	closure_t* closure335 = make_closure(lambda336, make_env_t_336());
	return matrix_build(10, closure335);
}
typedef struct env_t_345 {
	value_t dummy_variable;
} env_t_345;
env_t_345* make_env_t_345() {
	env_t_345* env = (env_t_345*)malloc(sizeof(env_t_345));
	
	return env;
}
typedef struct env_t_346 {
	index_t i;
} env_t_346;
env_t_346* make_env_t_346(index_t i) {
	env_t_346* env = (env_t_346*)malloc(sizeof(env_t_346));
	env->i = i;
	return env;
}

value_t lambda346(env_t_346* env339, index_t j) {
	index_t i338 = env339->i;
	value_t res;
	res.number_t_value = (double)((i338) + (j));
	return res;
}
value_t lambda345(env_t_346* env342, index_t i) {
	closure_t* closure341 = make_closure(lambda346, make_env_t_346(i));
	value_t res;
	res.array_number_t_value = vector_build(20, closure341);
	return res;
}
array_array_number_t ccodegentests_closure_bug2(array_array_number_t m1, array_array_number_t m2) {
	closure_t* closure344 = make_closure(lambda345, make_env_t_345());
	return matrix_build(10, closure344);
}
typedef struct env_t_356 {
	number_t n;
} env_t_356;
env_t_356* make_env_t_356(number_t n) {
	env_t_356* env = (env_t_356*)malloc(sizeof(env_t_356));
	env->n = n;
	return env;
}
typedef struct env_t_357 {
	number_t n;
	index_t i;
} env_t_357;
env_t_357* make_env_t_357(number_t n,index_t i) {
	env_t_357* env = (env_t_357*)malloc(sizeof(env_t_357));
	env->n = n;
	env->i = i;
	return env;
}

value_t lambda357(env_t_357* env349, index_t j) {
	number_t n348 = env349->n;
	index_t i347 = env349->i;
	value_t res;
	res.number_t_value = ((double)((i347) + (j))) * (n348);
	return res;
}
value_t lambda356(env_t_357* env353, index_t i) {
	number_t n352 = env353->n;
	closure_t* closure351 = make_closure(lambda357, make_env_t_357(n352,i));
	value_t res;
	res.array_number_t_value = vector_build(20, closure351);
	return res;
}
array_array_number_t ccodegentests_closure_bug3(array_array_number_t m1, array_array_number_t m2) {
	number_t n = 3;
	closure_t* closure355 = make_closure(lambda356, make_env_t_356(n));
	return matrix_build(10, closure355);
}
#endif
