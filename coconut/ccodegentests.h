#ifndef __CCODEGENTESTS_H__ 
#define __CCODEGENTESTS_H__ 
#include "runtime/fsharp.h"
#include <stdio.h>
#include <math.h>
typedef struct env_t_306 {
	value_t dummy_variable;
} env_t_306;
env_t_306* make_env_t_306() {
	env_t_306* env = (env_t_306*)malloc(sizeof(env_t_306));
	
	return env;
}
typedef struct env_t_307 {
	value_t dummy_variable;
} env_t_307;
env_t_307* make_env_t_307() {
	env_t_307* env = (env_t_307*)malloc(sizeof(env_t_307));
	
	return env;
}

value_t lambda307(env_t_307* env300, index_t j) {
	
	value_t res;
	res.number_t_value = (double)(j);
	return res;
}
value_t lambda306(env_t_307* env303, index_t i) {
	closure_t* closure302 = make_closure(lambda307, make_env_t_307());
	value_t res;
	res.array_number_t_value = vector_build(20, closure302);
	return res;
}
array_array_number_t ccodegentests_closure_bug1(array_array_number_t m1, array_array_number_t m2) {
	closure_t* closure305 = make_closure(lambda306, make_env_t_306());
	return matrix_build(10, closure305);
}
typedef struct env_t_315 {
	value_t dummy_variable;
} env_t_315;
env_t_315* make_env_t_315() {
	env_t_315* env = (env_t_315*)malloc(sizeof(env_t_315));
	
	return env;
}
typedef struct env_t_316 {
	index_t i;
} env_t_316;
env_t_316* make_env_t_316(index_t i) {
	env_t_316* env = (env_t_316*)malloc(sizeof(env_t_316));
	env->i = i;
	return env;
}

value_t lambda316(env_t_316* env309, index_t j) {
	index_t i308 = env309->i;
	value_t res;
	res.number_t_value = (double)((i308) + (j));
	return res;
}
value_t lambda315(env_t_316* env312, index_t i) {
	closure_t* closure311 = make_closure(lambda316, make_env_t_316(i));
	value_t res;
	res.array_number_t_value = vector_build(20, closure311);
	return res;
}
array_array_number_t ccodegentests_closure_bug2(array_array_number_t m1, array_array_number_t m2) {
	closure_t* closure314 = make_closure(lambda315, make_env_t_315());
	return matrix_build(10, closure314);
}
#endif
