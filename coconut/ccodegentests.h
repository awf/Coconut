#ifndef __CCODEGENTESTS_H__ 
#define __CCODEGENTESTS_H__ 
#include "runtime/fsharp.h"
#include <stdio.h>
#include <math.h>
typedef empty_env_t env_t_862;

typedef empty_env_t env_t_863;


value_t lambda863(env_t_863* env854, index_t j) {
	
	value_t res;
	res.number_t_value = (double)(j);
	return res;
}
value_t lambda862(env_t_862* env858, index_t i) {
	env_t_863 env_t_863_value = make_empty_env(); closure_t closure856 = make_closure(lambda863, &env_t_863_value);
	value_t res;
	res.array_number_t_value = vector_build(20, closure856);
	return res;
}
array_array_number_t ccodegentests_closure_bug1(array_array_number_t m1, array_array_number_t m2) {
	env_t_862 env_t_862_value = make_empty_env(); closure_t closure860 = make_closure(lambda862, &env_t_862_value);
	return matrix_build(10, closure860);
}
typedef empty_env_t env_t_875;

typedef struct env_t_876 {
	index_t i;
} env_t_876;
env_t_876 make_env_t_876(index_t i) {
	env_t_876 env;
	env.i = i;
	return env;
}

value_t lambda876(env_t_876* env867, index_t j) {
	index_t i866 = env867->i;
	value_t res;
	res.number_t_value = (double)((i866) + (j));
	return res;
}
value_t lambda875(env_t_875* env871, index_t i) {
	env_t_876 env_t_876_value = make_env_t_876(i); closure_t closure869 = make_closure(lambda876, &env_t_876_value);
	value_t res;
	res.array_number_t_value = vector_build(20, closure869);
	return res;
}
array_array_number_t ccodegentests_closure_bug2(array_array_number_t m1, array_array_number_t m2) {
	env_t_875 env_t_875_value = make_empty_env(); closure_t closure873 = make_closure(lambda875, &env_t_875_value);
	return matrix_build(10, closure873);
}
typedef struct env_t_891 {
	number_t n;
} env_t_891;
env_t_891 make_env_t_891(number_t n) {
	env_t_891 env;
	env.n = n;
	return env;
}
typedef struct env_t_892 {
	number_t n;
	index_t i;
} env_t_892;
env_t_892 make_env_t_892(number_t n,index_t i) {
	env_t_892 env;
	env.n = n;
	env.i = i;
	return env;
}

value_t lambda892(env_t_892* env882, index_t j) {
	number_t n881 = env882->n;
	index_t i880 = env882->i;
	value_t res;
	res.number_t_value = ((double)((i880) + (j))) * (n881);
	return res;
}
value_t lambda891(env_t_891* env887, index_t i) {
	number_t n886 = env887->n;
	env_t_892 env_t_892_value = make_env_t_892(n886,i); closure_t closure884 = make_closure(lambda892, &env_t_892_value);
	value_t res;
	res.array_number_t_value = vector_build(20, closure884);
	return res;
}
array_array_number_t ccodegentests_closure_bug3(array_array_number_t m1, array_array_number_t m2) {
	number_t n = 3;
	env_t_891 env_t_891_value = make_env_t_891(n); closure_t closure889 = make_closure(lambda891, &env_t_891_value);
	return matrix_build(10, closure889);
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
