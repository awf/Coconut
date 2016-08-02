#ifndef __CCODEGENTESTS_H__ 
#define __CCODEGENTESTS_H__ 
#include "runtime/fsharp.h"
#include <stdio.h>
#include <math.h>
typedef empty_env_t env_t_860;

typedef empty_env_t env_t_861;


value_t lambda861(env_t_861* env852, index_t j) {
	
	value_t res;
	res.number_t_value = (double)(j);
	return res;
}
value_t lambda860(env_t_860* env856, index_t i) {
	env_t_861 env_t_861_value = make_empty_env(); closure_t closure854 = make_closure(lambda861, &env_t_861_value);
	value_t res;
	res.array_number_t_value = vector_build(20, closure854);
	return res;
}
array_array_number_t ccodegentests_closure_bug1(array_array_number_t m1, array_array_number_t m2) {
	env_t_860 env_t_860_value = make_empty_env(); closure_t closure858 = make_closure(lambda860, &env_t_860_value);
	return matrix_build(10, closure858);
}
typedef empty_env_t env_t_873;

typedef struct env_t_874 {
	index_t i;
} env_t_874;
env_t_874 make_env_t_874(index_t i) {
	env_t_874 env;
	env.i = i;
	return env;
}

value_t lambda874(env_t_874* env865, index_t j) {
	index_t i864 = env865->i;
	value_t res;
	res.number_t_value = (double)((i864) + (j));
	return res;
}
value_t lambda873(env_t_873* env869, index_t i) {
	env_t_874 env_t_874_value = make_env_t_874(i); closure_t closure867 = make_closure(lambda874, &env_t_874_value);
	value_t res;
	res.array_number_t_value = vector_build(20, closure867);
	return res;
}
array_array_number_t ccodegentests_closure_bug2(array_array_number_t m1, array_array_number_t m2) {
	env_t_873 env_t_873_value = make_empty_env(); closure_t closure871 = make_closure(lambda873, &env_t_873_value);
	return matrix_build(10, closure871);
}
typedef struct env_t_889 {
	number_t n;
} env_t_889;
env_t_889 make_env_t_889(number_t n) {
	env_t_889 env;
	env.n = n;
	return env;
}
typedef struct env_t_890 {
	number_t n;
	index_t i;
} env_t_890;
env_t_890 make_env_t_890(number_t n,index_t i) {
	env_t_890 env;
	env.n = n;
	env.i = i;
	return env;
}

value_t lambda890(env_t_890* env880, index_t j) {
	number_t n879 = env880->n;
	index_t i878 = env880->i;
	value_t res;
	res.number_t_value = ((double)((i878) + (j))) * (n879);
	return res;
}
value_t lambda889(env_t_889* env885, index_t i) {
	number_t n884 = env885->n;
	env_t_890 env_t_890_value = make_env_t_890(n884,i); closure_t closure882 = make_closure(lambda890, &env_t_890_value);
	value_t res;
	res.array_number_t_value = vector_build(20, closure882);
	return res;
}
array_array_number_t ccodegentests_closure_bug3(array_array_number_t m1, array_array_number_t m2) {
	number_t n = 3;
	env_t_889 env_t_889_value = make_env_t_889(n); closure_t closure887 = make_closure(lambda889, &env_t_889_value);
	return matrix_build(10, closure887);
}

void ccodegentests_valloc_cps_feature1(array_number_t dum) {
	array_number_t s = malloc(2);
	array_print(dum);
	array_print(dum);
	free(s);
	;
	return ;
}

void ccodegentests_valloc_cps_feature2(array_number_t dum) {
	array_number_t s = malloc(2);
	array_number_t s2 = malloc(2);
	array_print(dum);
	array_print(dum);
	free(s2);
	;
	free(s);
	;
	return ;
}
#endif
