#ifndef __CCODEGENTESTS_H__ 
#define __CCODEGENTESTS_H__ 
#include "runtime/fsharp.h"
#include <stdio.h>
#include <math.h>
typedef struct env_t_276 {
	value_t dummy_variable;
} env_t_276;
env_t_276* make_env_t_276() {
	env_t_276* env = (env_t_276*)malloc(sizeof(env_t_276));
	
	return env;
}
typedef struct env_t_277 {
	value_t dummy_variable;
} env_t_277;
env_t_277* make_env_t_277() {
	env_t_277* env = (env_t_277*)malloc(sizeof(env_t_277));
	
	return env;
}

value_t lambda277(env_t_277* env270, index_t j) {
	
	value_t res;
	res.number_t_value = (double)(j);
	return res;
}
value_t lambda276(env_t_277* env273, index_t i) {
	closure_t* closure272 = make_closure(lambda277, make_env_t_277());
	value_t res;
	res.array_number_t_value = vector_build(20, closure272);
	return res;
}
array_array_number_t ccodegentests_closure_bug1(array_array_number_t m1, array_array_number_t m2) {
	closure_t* closure275 = make_closure(lambda276, make_env_t_276());
	return matrix_build(10, closure275);
}
typedef struct env_t_285 {
	value_t dummy_variable;
} env_t_285;
env_t_285* make_env_t_285() {
	env_t_285* env = (env_t_285*)malloc(sizeof(env_t_285));
	
	return env;
}
typedef struct env_t_286 {
	index_t i;
} env_t_286;
env_t_286* make_env_t_286(index_t i) {
	env_t_286* env = (env_t_286*)malloc(sizeof(env_t_286));
	env->i = i;
	return env;
}

value_t lambda286(env_t_286* env279, index_t j) {
	index_t i278 = env279->i;
	value_t res;
	res.number_t_value = (double)((i278) + (j));
	return res;
}
value_t lambda285(env_t_286* env282, index_t i) {
	closure_t* closure281 = make_closure(lambda286, make_env_t_286(i));
	value_t res;
	res.array_number_t_value = vector_build(20, closure281);
	return res;
}
array_array_number_t ccodegentests_closure_bug2(array_array_number_t m1, array_array_number_t m2) {
	closure_t* closure284 = make_closure(lambda285, make_env_t_285());
	return matrix_build(10, closure284);
}
typedef struct env_t_296 {
	number_t n;
} env_t_296;
env_t_296* make_env_t_296(number_t n) {
	env_t_296* env = (env_t_296*)malloc(sizeof(env_t_296));
	env->n = n;
	return env;
}
typedef struct env_t_297 {
	number_t n;
	index_t i;
} env_t_297;
env_t_297* make_env_t_297(number_t n,index_t i) {
	env_t_297* env = (env_t_297*)malloc(sizeof(env_t_297));
	env->n = n;
	env->i = i;
	return env;
}

value_t lambda297(env_t_297* env289, index_t j) {
	number_t n288 = env289->n;
	index_t i287 = env289->i;
	value_t res;
	res.number_t_value = ((double)((i287) + (j))) * (n288);
	return res;
}
value_t lambda296(env_t_297* env293, index_t i) {
	number_t n292 = env293->n;
	closure_t* closure291 = make_closure(lambda297, make_env_t_297(n292,i));
	value_t res;
	res.array_number_t_value = vector_build(20, closure291);
	return res;
}
array_array_number_t ccodegentests_closure_bug3(array_array_number_t m1, array_array_number_t m2) {
	number_t n = 3;
	closure_t* closure295 = make_closure(lambda296, make_env_t_296(n));
	return matrix_build(10, closure295);
}
#endif
