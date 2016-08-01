#ifndef __CCODEGENTESTS_H__ 
#define __CCODEGENTESTS_H__ 
#include "runtime/fsharp.h"
#include <stdio.h>
#include <math.h>
typedef struct env_t_325 {
	value_t dummy_variable;
} env_t_325;
env_t_325* make_env_t_325() {
	env_t_325* env = (env_t_325*)malloc(sizeof(env_t_325));
	
	return env;
}
typedef struct env_t_326 {
	value_t dummy_variable;
} env_t_326;
env_t_326* make_env_t_326() {
	env_t_326* env = (env_t_326*)malloc(sizeof(env_t_326));
	
	return env;
}

value_t lambda326(env_t_326* env319, index_t j) {
	
	value_t res;
	res.number_t_value = (double)(j);
	return res;
}
value_t lambda325(env_t_326* env322, index_t i) {
	closure_t* closure321 = make_closure(lambda326, make_env_t_326());
	value_t res;
	res.array_number_t_value = vector_build(20, closure321);
	return res;
}
array_array_number_t ccodegentests_closure_bug1(array_array_number_t m1, array_array_number_t m2) {
	closure_t* closure324 = make_closure(lambda325, make_env_t_325());
	return matrix_build(10, closure324);
}
typedef struct env_t_334 {
	value_t dummy_variable;
} env_t_334;
env_t_334* make_env_t_334() {
	env_t_334* env = (env_t_334*)malloc(sizeof(env_t_334));
	
	return env;
}
typedef struct env_t_335 {
	index_t i;
} env_t_335;
env_t_335* make_env_t_335(index_t i) {
	env_t_335* env = (env_t_335*)malloc(sizeof(env_t_335));
	env->i = i;
	return env;
}

value_t lambda335(env_t_335* env328, index_t j) {
	index_t i327 = env328->i;
	value_t res;
	res.number_t_value = (double)((i327) + (j));
	return res;
}
value_t lambda334(env_t_335* env331, index_t i) {
	closure_t* closure330 = make_closure(lambda335, make_env_t_335(i));
	value_t res;
	res.array_number_t_value = vector_build(20, closure330);
	return res;
}
array_array_number_t ccodegentests_closure_bug2(array_array_number_t m1, array_array_number_t m2) {
	closure_t* closure333 = make_closure(lambda334, make_env_t_334());
	return matrix_build(10, closure333);
}
typedef struct env_t_345 {
	number_t n;
} env_t_345;
env_t_345* make_env_t_345(number_t n) {
	env_t_345* env = (env_t_345*)malloc(sizeof(env_t_345));
	env->n = n;
	return env;
}
typedef struct env_t_346 {
	number_t n;
	index_t i;
} env_t_346;
env_t_346* make_env_t_346(number_t n,index_t i) {
	env_t_346* env = (env_t_346*)malloc(sizeof(env_t_346));
	env->n = n;
	env->i = i;
	return env;
}

value_t lambda346(env_t_346* env338, index_t j) {
	number_t n337 = env338->n;
	index_t i336 = env338->i;
	value_t res;
	res.number_t_value = ((double)((i336) + (j))) * (n337);
	return res;
}
value_t lambda345(env_t_346* env342, index_t i) {
	number_t n341 = env342->n;
	closure_t* closure340 = make_closure(lambda346, make_env_t_346(n341,i));
	value_t res;
	res.array_number_t_value = vector_build(20, closure340);
	return res;
}
array_array_number_t ccodegentests_closure_bug3(array_array_number_t m1, array_array_number_t m2) {
	number_t n = 3;
	closure_t* closure344 = make_closure(lambda345, make_env_t_345(n));
	return matrix_build(10, closure344);
}
#endif
