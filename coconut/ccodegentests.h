#ifndef __CCODEGENTESTS_H__ 
#define __CCODEGENTESTS_H__ 
#include "runtime/fsharp.h"
#include <stdio.h>
#include <math.h>
typedef empty_env_t env_t_825;

typedef empty_env_t env_t_826;


value_t lambda826(env_t_826* env817, index_t j) {
	
	value_t res;
	res.number_t_value = (double)(j);
	return res;
}
value_t lambda825(env_t_825* env821, index_t i) {
	env_t_826 env_t_826_value = make_empty_env(); closure_t closure819 = make_closure(lambda826, &env_t_826_value);
	value_t res;
	res.array_number_t_value = vector_build(20, closure819);
	return res;
}
array_array_number_t ccodegentests_closure_bug1(array_array_number_t m1, array_array_number_t m2) {
	env_t_825 env_t_825_value = make_empty_env(); closure_t closure823 = make_closure(lambda825, &env_t_825_value);
	return matrix_build(10, closure823);
}
typedef empty_env_t env_t_838;

typedef struct env_t_839 {
	index_t i;
} env_t_839;
env_t_839 make_env_t_839(index_t i) {
	env_t_839 env;
	env.i = i;
	return env;
}

value_t lambda839(env_t_839* env830, index_t j) {
	index_t i829 = env830->i;
	value_t res;
	res.number_t_value = (double)((i829) + (j));
	return res;
}
value_t lambda838(env_t_838* env834, index_t i) {
	env_t_839 env_t_839_value = make_env_t_839(i); closure_t closure832 = make_closure(lambda839, &env_t_839_value);
	value_t res;
	res.array_number_t_value = vector_build(20, closure832);
	return res;
}
array_array_number_t ccodegentests_closure_bug2(array_array_number_t m1, array_array_number_t m2) {
	env_t_838 env_t_838_value = make_empty_env(); closure_t closure836 = make_closure(lambda838, &env_t_838_value);
	return matrix_build(10, closure836);
}
typedef struct env_t_854 {
	number_t n;
} env_t_854;
env_t_854 make_env_t_854(number_t n) {
	env_t_854 env;
	env.n = n;
	return env;
}
typedef struct env_t_855 {
	number_t n;
	index_t i;
} env_t_855;
env_t_855 make_env_t_855(number_t n,index_t i) {
	env_t_855 env;
	env.n = n;
	env.i = i;
	return env;
}

value_t lambda855(env_t_855* env845, index_t j) {
	number_t n844 = env845->n;
	index_t i843 = env845->i;
	value_t res;
	res.number_t_value = ((double)((i843) + (j))) * (n844);
	return res;
}
value_t lambda854(env_t_854* env850, index_t i) {
	number_t n849 = env850->n;
	env_t_855 env_t_855_value = make_env_t_855(n849,i); closure_t closure847 = make_closure(lambda855, &env_t_855_value);
	value_t res;
	res.array_number_t_value = vector_build(20, closure847);
	return res;
}
array_array_number_t ccodegentests_closure_bug3(array_array_number_t m1, array_array_number_t m2) {
	number_t n = 3;
	env_t_854 env_t_854_value = make_env_t_854(n); closure_t closure852 = make_closure(lambda854, &env_t_854_value);
	return matrix_build(10, closure852);
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
