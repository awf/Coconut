#ifndef __CCODEGENTESTS_H__ 
#define __CCODEGENTESTS_H__ 
#include "runtime/fsharp.h"
#include <stdio.h>
#include <math.h>
typedef empty_env_t env_t_873;

typedef empty_env_t env_t_874;


value_t lambda874(env_t_874* env865, index_t j) {
	
	value_t res;
	res.number_t_value = (double)(j);
	return res;
}
value_t lambda873(env_t_873* env869, index_t i) {
	env_t_874 env_t_874_value = make_empty_env(); closure_t closure867 = make_closure(lambda874, &env_t_874_value);
	value_t res;
	res.array_number_t_value = vector_build(20, closure867);
	return res;
}
array_array_number_t ccodegentests_closure_bug1(array_array_number_t m1, array_array_number_t m2) {
	env_t_873 env_t_873_value = make_empty_env(); closure_t closure871 = make_closure(lambda873, &env_t_873_value);
	return matrix_build(10, closure871);
}
typedef empty_env_t env_t_886;

typedef struct env_t_887 {
	index_t i;
} env_t_887;
env_t_887 make_env_t_887(index_t i) {
	env_t_887 env;
	env.i = i;
	return env;
}

value_t lambda887(env_t_887* env878, index_t j) {
	index_t i877 = env878->i;
	value_t res;
	res.number_t_value = (double)((i877) + (j));
	return res;
}
value_t lambda886(env_t_886* env882, index_t i) {
	env_t_887 env_t_887_value = make_env_t_887(i); closure_t closure880 = make_closure(lambda887, &env_t_887_value);
	value_t res;
	res.array_number_t_value = vector_build(20, closure880);
	return res;
}
array_array_number_t ccodegentests_closure_bug2(array_array_number_t m1, array_array_number_t m2) {
	env_t_886 env_t_886_value = make_empty_env(); closure_t closure884 = make_closure(lambda886, &env_t_886_value);
	return matrix_build(10, closure884);
}
typedef struct env_t_902 {
	number_t n;
} env_t_902;
env_t_902 make_env_t_902(number_t n) {
	env_t_902 env;
	env.n = n;
	return env;
}
typedef struct env_t_903 {
	number_t n;
	index_t i;
} env_t_903;
env_t_903 make_env_t_903(number_t n,index_t i) {
	env_t_903 env;
	env.n = n;
	env.i = i;
	return env;
}

value_t lambda903(env_t_903* env893, index_t j) {
	number_t n892 = env893->n;
	index_t i891 = env893->i;
	value_t res;
	res.number_t_value = ((double)((i891) + (j))) * (n892);
	return res;
}
value_t lambda902(env_t_902* env898, index_t i) {
	number_t n897 = env898->n;
	env_t_903 env_t_903_value = make_env_t_903(n897,i); closure_t closure895 = make_closure(lambda903, &env_t_903_value);
	value_t res;
	res.array_number_t_value = vector_build(20, closure895);
	return res;
}
array_array_number_t ccodegentests_closure_bug3(array_array_number_t m1, array_array_number_t m2) {
	number_t n = 3;
	env_t_902 env_t_902_value = make_env_t_902(n); closure_t closure900 = make_closure(lambda902, &env_t_902_value);
	return matrix_build(10, closure900);
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
