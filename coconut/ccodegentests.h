#ifndef __CCODEGENTESTS_H__ 
#define __CCODEGENTESTS_H__ 
#include "runtime/fsharp.h"
#include <stdio.h>
#include <math.h>
typedef empty_env_t env_t_829;

typedef empty_env_t env_t_830;


value_t lambda830(env_t_830* env821, index_t j) {
	
	value_t res;
	res.number_t_value = (double)(j);
	return res;
}
value_t lambda829(env_t_829* env825, index_t i) {
	env_t_830 env_t_830_value = make_empty_env(); closure_t closure823 = make_closure(lambda830, &env_t_830_value);
	value_t res;
	res.array_number_t_value = vector_build(20, closure823);
	return res;
}
array_array_number_t ccodegentests_closure_bug1(array_array_number_t m1, array_array_number_t m2) {
	env_t_829 env_t_829_value = make_empty_env(); closure_t closure827 = make_closure(lambda829, &env_t_829_value);
	return matrix_build(10, closure827);
}
typedef empty_env_t env_t_842;

typedef struct env_t_843 {
	index_t i;
} env_t_843;
env_t_843 make_env_t_843(index_t i) {
	env_t_843 env;
	env.i = i;
	return env;
}

value_t lambda843(env_t_843* env834, index_t j) {
	index_t i833 = env834->i;
	value_t res;
	res.number_t_value = (double)((i833) + (j));
	return res;
}
value_t lambda842(env_t_842* env838, index_t i) {
	env_t_843 env_t_843_value = make_env_t_843(i); closure_t closure836 = make_closure(lambda843, &env_t_843_value);
	value_t res;
	res.array_number_t_value = vector_build(20, closure836);
	return res;
}
array_array_number_t ccodegentests_closure_bug2(array_array_number_t m1, array_array_number_t m2) {
	env_t_842 env_t_842_value = make_empty_env(); closure_t closure840 = make_closure(lambda842, &env_t_842_value);
	return matrix_build(10, closure840);
}
typedef struct env_t_858 {
	number_t n;
} env_t_858;
env_t_858 make_env_t_858(number_t n) {
	env_t_858 env;
	env.n = n;
	return env;
}
typedef struct env_t_859 {
	number_t n;
	index_t i;
} env_t_859;
env_t_859 make_env_t_859(number_t n,index_t i) {
	env_t_859 env;
	env.n = n;
	env.i = i;
	return env;
}

value_t lambda859(env_t_859* env849, index_t j) {
	number_t n848 = env849->n;
	index_t i847 = env849->i;
	value_t res;
	res.number_t_value = ((double)((i847) + (j))) * (n848);
	return res;
}
value_t lambda858(env_t_858* env854, index_t i) {
	number_t n853 = env854->n;
	env_t_859 env_t_859_value = make_env_t_859(n853,i); closure_t closure851 = make_closure(lambda859, &env_t_859_value);
	value_t res;
	res.array_number_t_value = vector_build(20, closure851);
	return res;
}
array_array_number_t ccodegentests_closure_bug3(array_array_number_t m1, array_array_number_t m2) {
	number_t n = 3;
	env_t_858 env_t_858_value = make_env_t_858(n); closure_t closure856 = make_closure(lambda858, &env_t_858_value);
	return matrix_build(10, closure856);
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
