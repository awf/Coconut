#ifndef __CCODEGENTESTS_H__ 
#define __CCODEGENTESTS_H__ 
#include "runtime/fsharp.h"
#include <stdio.h>
#include <math.h>
typedef struct env_t_316 {
	value_t dummy_variable;
} env_t_316;
env_t_316* make_env_t_316() {
	env_t_316* env = (env_t_316*)malloc(sizeof(env_t_316));
	
	return env;
}
typedef struct env_t_317 {
	value_t dummy_variable;
} env_t_317;
env_t_317* make_env_t_317() {
	env_t_317* env = (env_t_317*)malloc(sizeof(env_t_317));
	
	return env;
}

value_t lambda317(env_t_317* env310, index_t j) {
	
	value_t res;
	res.number_t_value = (double)(j);
	return res;
}
value_t lambda316(env_t_317* env313, index_t i) {
	closure_t* closure312 = make_closure(lambda317, make_env_t_317());
	value_t res;
	res.array_number_t_value = vector_build(20, closure312);
	return res;
}
array_array_number_t ccodegentests_closure_bug1(array_array_number_t m1, array_array_number_t m2) {
	closure_t* closure315 = make_closure(lambda316, make_env_t_316());
	return matrix_build(10, closure315);
}
typedef struct env_t_325 {
	value_t dummy_variable;
} env_t_325;
env_t_325* make_env_t_325() {
	env_t_325* env = (env_t_325*)malloc(sizeof(env_t_325));
	
	return env;
}
typedef struct env_t_326 {
	index_t i;
} env_t_326;
env_t_326* make_env_t_326(index_t i) {
	env_t_326* env = (env_t_326*)malloc(sizeof(env_t_326));
	env->i = i;
	return env;
}

value_t lambda326(env_t_326* env319, index_t j) {
	index_t i318 = env319->i;
	value_t res;
	res.number_t_value = (double)((i318) + (j));
	return res;
}
value_t lambda325(env_t_326* env322, index_t i) {
	closure_t* closure321 = make_closure(lambda326, make_env_t_326(i));
	value_t res;
	res.array_number_t_value = vector_build(20, closure321);
	return res;
}
array_array_number_t ccodegentests_closure_bug2(array_array_number_t m1, array_array_number_t m2) {
	closure_t* closure324 = make_closure(lambda325, make_env_t_325());
	return matrix_build(10, closure324);
}
typedef struct env_t_336 {
	number_t n;
} env_t_336;
env_t_336* make_env_t_336(number_t n) {
	env_t_336* env = (env_t_336*)malloc(sizeof(env_t_336));
	env->n = n;
	return env;
}
typedef struct env_t_337 {
	number_t n;
	index_t i;
} env_t_337;
env_t_337* make_env_t_337(number_t n,index_t i) {
	env_t_337* env = (env_t_337*)malloc(sizeof(env_t_337));
	env->n = n;
	env->i = i;
	return env;
}

value_t lambda337(env_t_337* env329, index_t j) {
	number_t n328 = env329->n;
	index_t i327 = env329->i;
	value_t res;
	res.number_t_value = ((double)((i327) + (j))) * (n328);
	return res;
}
value_t lambda336(env_t_337* env333, index_t i) {
	number_t n332 = env333->n;
	closure_t* closure331 = make_closure(lambda337, make_env_t_337(n332,i));
	value_t res;
	res.array_number_t_value = vector_build(20, closure331);
	return res;
}
array_array_number_t ccodegentests_closure_bug3(array_array_number_t m1, array_array_number_t m2) {
	number_t n = 3;
	closure_t* closure335 = make_closure(lambda336, make_env_t_336(n));
	return matrix_build(10, closure335);
}
#endif
