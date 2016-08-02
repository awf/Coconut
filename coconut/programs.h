#ifndef __PROGRAMS_H__ 
#define __PROGRAMS_H__ 
#include "runtime/fsharp.h"
#include <stdio.h>
#include <math.h>
#include "linalg.h"

number_t programs_test1(number_t x) {
	
	return (1) / ((1) + (x));
}

number_t programs_test2(number_t x, number_t b) {
	
	return x;
}

array_number_t programs_vector_add3(array_number_t v1, array_number_t v2, array_number_t v3) {
	
	return linalg_add_vec(v1, linalg_add_vec(v2, v3));
}

array_array_number_t programs_matrix_add3(array_array_number_t m1, array_array_number_t m2, array_array_number_t m3) {
	
	return linalg_matrixAdd(m1, linalg_matrixAdd(m2, m3));
}
typedef struct env_t_787 {
	array_number_t v;
} env_t_787;
env_t_787 make_env_t_787(array_number_t v) {
	env_t_787 env;
	env.v = v;
	return env;
}

value_t lambda787(env_t_787* env781, number_t acc, index_t idx) {
	array_number_t v780 = env781->v;
	array_number_t tmp = array_slice(v780, idx, (idx) + (9));
	value_t res;
	res.number_t_value = (acc) + (linalg_sqnorm(linalg_add_vec(tmp, tmp)));
	return res;
}
void programs_hoistingExample(array_number_t v) {
	env_t_787 env_t_787_value = make_env_t_787(v); closure_t closure783 = make_closure(lambda787, &env_t_787_value);
	number_t sum = linalg_iterateNumber(closure783, 0, 0, 9);
	number_print(sum);
	return ;
}
typedef struct env_t_807 {
	array_number_t v;
	storage_t storage1;
} env_t_807;
env_t_807 make_env_t_807(array_number_t v,storage_t storage1) {
	env_t_807 env;
	env.v = v;
	env.storage1 = storage1;
	return env;
}
typedef struct env_t_808 {
	array_number_t v;
	index_t idx;
} env_t_808;
env_t_808 make_env_t_808(array_number_t v,index_t idx) {
	env_t_808 env;
	env.v = v;
	env.idx = idx;
	return env;
}

value_t lambda808(env_t_808* env792, index_t i) {
	array_number_t v791 = env792->v;
	index_t idx790 = env792->idx;
	value_t res;
	res.number_t_value = v791->arr[(i) + (idx790)];
	return res;
}
value_t lambda807(env_t_807* env800, number_t acc, index_t idx) {
	array_number_t v799 = env800->v;
	storage_t storage1798 = env800->storage1;
	env_t_808 env_t_808_value = make_env_t_808(v799,idx); closure_t closure794 = make_closure(lambda808, &env_t_808_value);
	array_number_t tmp = vector_build_given_storage(storage1798, closure794);
	value_t res;
	res.number_t_value = linalg_sqnorm(linalg_add_vec(tmp, tmp));
	return res;
}
void programs_explicitMallocExample1(array_number_t v) {
	array_number_t storage1 = malloc(2);
	env_t_807 env_t_807_value = make_env_t_807(v,storage1); closure_t closure802 = make_closure(lambda807, &env_t_807_value);
	number_t sum = linalg_iterateNumber(closure802, 0, 0, 9);
	number_print(sum);
	free(storage1);
	;
	return ;
}
typedef struct env_t_830 {
	array_number_t v;
	storage_t storage2;
	storage_t storage1;
} env_t_830;
env_t_830 make_env_t_830(array_number_t v,storage_t storage2,storage_t storage1) {
	env_t_830 env;
	env.v = v;
	env.storage2 = storage2;
	env.storage1 = storage1;
	return env;
}
typedef struct env_t_831 {
	array_number_t v;
	index_t idx;
} env_t_831;
env_t_831 make_env_t_831(array_number_t v,index_t idx) {
	env_t_831 env;
	env.v = v;
	env.idx = idx;
	return env;
}

value_t lambda831(env_t_831* env813, index_t i) {
	array_number_t v812 = env813->v;
	index_t idx811 = env813->idx;
	value_t res;
	res.number_t_value = v812->arr[(i) + (idx811)];
	return res;
}
value_t lambda830(env_t_830* env822, number_t acc, index_t idx) {
	array_number_t v821 = env822->v;
	storage_t storage2820 = env822->storage2;
	storage_t storage1819 = env822->storage1;
	env_t_831 env_t_831_value = make_env_t_831(v821,idx); closure_t closure815 = make_closure(lambda831, &env_t_831_value);
	array_number_t tmp = vector_build_given_storage(storage1819, closure815);
	array_number_t tmp2 = linalg_add_vecGivenStorage(storage2820, tmp, tmp);
	value_t res;
	res.number_t_value = linalg_sqnorm(tmp2);
	return res;
}
void programs_explicitMallocExample2(array_number_t v) {
	array_number_t storage1 = malloc(2);
	array_number_t storage2 = malloc(2);
	env_t_830 env_t_830_value = make_env_t_830(v,storage2,storage1); closure_t closure824 = make_closure(lambda830, &env_t_830_value);
	number_t sum = linalg_iterateNumber(closure824, 0, 0, 9);
	number_print(sum);
	free(storage2);
	;
	free(storage1);
	;
	return ;
}

void programs_small_tests(number_t dum) {
	number_t a832 = programs_test1(2);
	number_print(a832);
	number_print(programs_test2(2, a832));
	array_number_t v2833 = linalg_vectorRange(0, 99);
	programs_hoistingExample(v2833);
	programs_explicitMallocExample1(v2833);
	programs_explicitMallocExample2(v2833);
	return ;
}
#endif
