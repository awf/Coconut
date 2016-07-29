#ifndef __CCODEGENTESTS_H__ 
#define __CCODEGENTESTS_H__ 
#include "runtime/fsharp.h"
#include <stdio.h>
#include <math.h>
typedef struct env_t_295 {
	value_t dummy_variable;
} env_t_295;
env_t_295* make_env_t_295() {
	env_t_295* env = (env_t_295*)malloc(sizeof(env_t_295));
	
	return env;
}
typedef struct env_t_296 {
	value_t dummy_variable;
} env_t_296;
env_t_296* make_env_t_296() {
	env_t_296* env = (env_t_296*)malloc(sizeof(env_t_296));
	
	return env;
}

value_t lambda296(env_t_296* env289, index_t j) {
	
	value_t res;
	res.number_t_value = (double)(j);
	return res;
}
value_t lambda295(env_t_296* env292, index_t i) {
	closure_t* closure291 = make_closure(lambda296, make_env_t_296());
	value_t res;
	res.array_number_t_value = vector_build(20, closure291);
	return res;
}
array_array_number_t ccodegentests_closure_bug1(array_array_number_t m1, array_array_number_t m2) {
	closure_t* closure294 = make_closure(lambda295, make_env_t_295());
	return matrix_build(10, closure294);
}
typedef struct env_t_304 {
	value_t dummy_variable;
} env_t_304;
env_t_304* make_env_t_304() {
	env_t_304* env = (env_t_304*)malloc(sizeof(env_t_304));
	
	return env;
}
typedef struct env_t_305 {
	index_t i;
} env_t_305;
env_t_305* make_env_t_305(index_t i) {
	env_t_305* env = (env_t_305*)malloc(sizeof(env_t_305));
	env->i = i;
	return env;
}

value_t lambda305(env_t_305* env298, index_t j) {
	index_t i297 = env298->i;
	value_t res;
	res.number_t_value = (double)((i297) + (j));
	return res;
}
value_t lambda304(env_t_305* env301, index_t i) {
	closure_t* closure300 = make_closure(lambda305, make_env_t_305(i));
	value_t res;
	res.array_number_t_value = vector_build(20, closure300);
	return res;
}
array_array_number_t ccodegentests_closure_bug2(array_array_number_t m1, array_array_number_t m2) {
	closure_t* closure303 = make_closure(lambda304, make_env_t_304());
	return matrix_build(10, closure303);
}
typedef struct env_t_315 {
	number_t n;
} env_t_315;
env_t_315* make_env_t_315(number_t n) {
	env_t_315* env = (env_t_315*)malloc(sizeof(env_t_315));
	env->n = n;
	return env;
}
typedef struct env_t_316 {
	number_t n;
	index_t i;
} env_t_316;
env_t_316* make_env_t_316(number_t n,index_t i) {
	env_t_316* env = (env_t_316*)malloc(sizeof(env_t_316));
	env->n = n;
	env->i = i;
	return env;
}

value_t lambda316(env_t_316* env308, index_t j) {
	number_t n307 = env308->n;
	index_t i306 = env308->i;
	value_t res;
	res.number_t_value = ((double)((i306) + (j))) * (n307);
	return res;
}
value_t lambda315(env_t_316* env312, index_t i) {
	number_t n311 = env312->n;
	closure_t* closure310 = make_closure(lambda316, make_env_t_316(n311,i));
	value_t res;
	res.array_number_t_value = vector_build(20, closure310);
	return res;
}
array_array_number_t ccodegentests_closure_bug3(array_array_number_t m1, array_array_number_t m2) {
	number_t n = 3;
	closure_t* closure314 = make_closure(lambda315, make_env_t_315(n));
	return matrix_build(10, closure314);
}
#endif
