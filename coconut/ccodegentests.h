#ifndef __CCODEGENTESTS_H__ 
#define __CCODEGENTESTS_H__ 
#include "runtime/fsharp.h"
#include <stdio.h>
#include <math.h>
typedef empty_env_t env_t_849;

typedef empty_env_t env_t_850;


value_t lambda850(env_t_850* env841, index_t j) {
	
	value_t res;
	res.number_t_value = (double)(j);
	return res;
}
value_t lambda849(env_t_849* env845, index_t i) {
	env_t_850 env_t_850_value = make_empty_env(); closure_t closure843 = make_closure(lambda850, &env_t_850_value);
	value_t res;
	res.array_number_t_value = vector_build(20, closure843);
	return res;
}
array_array_number_t ccodegentests_closure_bug1(array_array_number_t m1, array_array_number_t m2) {
	env_t_849 env_t_849_value = make_empty_env(); closure_t closure847 = make_closure(lambda849, &env_t_849_value);
	return matrix_build(10, closure847);
}
typedef empty_env_t env_t_862;

typedef struct env_t_863 {
	index_t i;
} env_t_863;
env_t_863 make_env_t_863(index_t i) {
	env_t_863 env;
	env.i = i;
	return env;
}

value_t lambda863(env_t_863* env854, index_t j) {
	index_t i853 = env854->i;
	value_t res;
	res.number_t_value = (double)((i853) + (j));
	return res;
}
value_t lambda862(env_t_862* env858, index_t i) {
	env_t_863 env_t_863_value = make_env_t_863(i); closure_t closure856 = make_closure(lambda863, &env_t_863_value);
	value_t res;
	res.array_number_t_value = vector_build(20, closure856);
	return res;
}
array_array_number_t ccodegentests_closure_bug2(array_array_number_t m1, array_array_number_t m2) {
	env_t_862 env_t_862_value = make_empty_env(); closure_t closure860 = make_closure(lambda862, &env_t_862_value);
	return matrix_build(10, closure860);
}
typedef struct env_t_878 {
	number_t n;
} env_t_878;
env_t_878 make_env_t_878(number_t n) {
	env_t_878 env;
	env.n = n;
	return env;
}
typedef struct env_t_879 {
	number_t n;
	index_t i;
} env_t_879;
env_t_879 make_env_t_879(number_t n,index_t i) {
	env_t_879 env;
	env.n = n;
	env.i = i;
	return env;
}

value_t lambda879(env_t_879* env869, index_t j) {
	number_t n868 = env869->n;
	index_t i867 = env869->i;
	value_t res;
	res.number_t_value = ((double)((i867) + (j))) * (n868);
	return res;
}
value_t lambda878(env_t_878* env874, index_t i) {
	number_t n873 = env874->n;
	env_t_879 env_t_879_value = make_env_t_879(n873,i); closure_t closure871 = make_closure(lambda879, &env_t_879_value);
	value_t res;
	res.array_number_t_value = vector_build(20, closure871);
	return res;
}
array_array_number_t ccodegentests_closure_bug3(array_array_number_t m1, array_array_number_t m2) {
	number_t n = 3;
	env_t_878 env_t_878_value = make_env_t_878(n); closure_t closure876 = make_closure(lambda878, &env_t_878_value);
	return matrix_build(10, closure876);
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
