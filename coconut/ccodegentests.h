#ifndef __CCODEGENTESTS_H__ 
#define __CCODEGENTESTS_H__ 
#include "runtime/fsharp.h"
#include <stdio.h>
#include <math.h>
typedef empty_env_t env_t_844;

typedef empty_env_t env_t_845;


value_t lambda845(env_t_845* env836, index_t j) {
	
	value_t res;
	res.number_t_value = (double)(j);
	return res;
}
value_t lambda844(env_t_844* env840, index_t i) {
	env_t_845 env_t_845_value = make_empty_env(); closure_t closure838 = make_closure(lambda845, &env_t_845_value);
	value_t res;
	res.array_number_t_value = vector_build(20, closure838);
	return res;
}
array_array_number_t ccodegentests_closure_bug1(array_array_number_t m1, array_array_number_t m2) {
	env_t_844 env_t_844_value = make_empty_env(); closure_t closure842 = make_closure(lambda844, &env_t_844_value);
	return matrix_build(10, closure842);
}
typedef empty_env_t env_t_857;

typedef struct env_t_858 {
	index_t i;
} env_t_858;
env_t_858 make_env_t_858(index_t i) {
	env_t_858 env;
	env.i = i;
	return env;
}

value_t lambda858(env_t_858* env849, index_t j) {
	index_t i848 = env849->i;
	value_t res;
	res.number_t_value = (double)((i848) + (j));
	return res;
}
value_t lambda857(env_t_857* env853, index_t i) {
	env_t_858 env_t_858_value = make_env_t_858(i); closure_t closure851 = make_closure(lambda858, &env_t_858_value);
	value_t res;
	res.array_number_t_value = vector_build(20, closure851);
	return res;
}
array_array_number_t ccodegentests_closure_bug2(array_array_number_t m1, array_array_number_t m2) {
	env_t_857 env_t_857_value = make_empty_env(); closure_t closure855 = make_closure(lambda857, &env_t_857_value);
	return matrix_build(10, closure855);
}
typedef struct env_t_873 {
	number_t n;
} env_t_873;
env_t_873 make_env_t_873(number_t n) {
	env_t_873 env;
	env.n = n;
	return env;
}
typedef struct env_t_874 {
	number_t n;
	index_t i;
} env_t_874;
env_t_874 make_env_t_874(number_t n,index_t i) {
	env_t_874 env;
	env.n = n;
	env.i = i;
	return env;
}

value_t lambda874(env_t_874* env864, index_t j) {
	number_t n863 = env864->n;
	index_t i862 = env864->i;
	value_t res;
	res.number_t_value = ((double)((i862) + (j))) * (n863);
	return res;
}
value_t lambda873(env_t_873* env869, index_t i) {
	number_t n868 = env869->n;
	env_t_874 env_t_874_value = make_env_t_874(n868,i); closure_t closure866 = make_closure(lambda874, &env_t_874_value);
	value_t res;
	res.array_number_t_value = vector_build(20, closure866);
	return res;
}
array_array_number_t ccodegentests_closure_bug3(array_array_number_t m1, array_array_number_t m2) {
	number_t n = 3;
	env_t_873 env_t_873_value = make_env_t_873(n); closure_t closure871 = make_closure(lambda873, &env_t_873_value);
	return matrix_build(10, closure871);
}

void ccodegentests_valloc_cps_feature1(array_number_t dum) {
	array_number_t s = vector_alloc(10);
	array_print(dum);
	array_print(dum);
	free(s);
	;
	return ;
}

void ccodegentests_valloc_cps_feature2(array_number_t dum) {
	array_number_t s = vector_alloc(10);
	array_number_t s2 = vector_alloc(10);
	array_print(dum);
	array_print(dum);
	free(s2);
	;
	free(s);
	;
	return ;
}
#endif
