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
typedef struct env_t_808 {
	array_number_t v;
	storage_t storage1;
} env_t_808;
env_t_808 make_env_t_808(array_number_t v,storage_t storage1) {
	env_t_808 env;
	env.v = v;
	env.storage1 = storage1;
	return env;
}
typedef struct env_t_809 {
	array_number_t v;
	index_t idx;
} env_t_809;
env_t_809 make_env_t_809(array_number_t v,index_t idx) {
	env_t_809 env;
	env.v = v;
	env.idx = idx;
	return env;
}

value_t lambda809(env_t_809* env792, index_t i) {
	array_number_t v791 = env792->v;
	index_t idx790 = env792->idx;
	value_t res;
	res.number_t_value = v791->arr[(i) + (idx790)];
	return res;
}
value_t lambda808(env_t_808* env801, number_t acc, index_t idx) {
	array_number_t v800 = env801->v;
	storage_t storage1799 = env801->storage1;
	env_t_809 env_t_809_value = make_env_t_809(v800,idx); closure_t closure794 = make_closure(lambda809, &env_t_809_value);
	array_number_t tmp = vector_build_given_storage(storage1799, closure794);
	value_t res;
	res.number_t_value = (acc) + (linalg_sqnorm(linalg_add_vec(tmp, tmp)));
	return res;
}
void programs_explicitMallocExample1(array_number_t v) {
	array_number_t storage1 = vector_alloc(10);
	env_t_808 env_t_808_value = make_env_t_808(v,storage1); closure_t closure803 = make_closure(lambda808, &env_t_808_value);
	number_t sum = linalg_iterateNumber(closure803, 0, 0, 9);
	number_print(sum);
	free(storage1);
	;
	return ;
}
typedef struct env_t_832 {
	array_number_t v;
	storage_t storage2;
	storage_t storage1;
} env_t_832;
env_t_832 make_env_t_832(array_number_t v,storage_t storage2,storage_t storage1) {
	env_t_832 env;
	env.v = v;
	env.storage2 = storage2;
	env.storage1 = storage1;
	return env;
}
typedef struct env_t_833 {
	array_number_t v;
	index_t idx;
} env_t_833;
env_t_833 make_env_t_833(array_number_t v,index_t idx) {
	env_t_833 env;
	env.v = v;
	env.idx = idx;
	return env;
}

value_t lambda833(env_t_833* env814, index_t i) {
	array_number_t v813 = env814->v;
	index_t idx812 = env814->idx;
	value_t res;
	res.number_t_value = v813->arr[(i) + (idx812)];
	return res;
}
value_t lambda832(env_t_832* env824, number_t acc, index_t idx) {
	array_number_t v823 = env824->v;
	storage_t storage2822 = env824->storage2;
	storage_t storage1821 = env824->storage1;
	env_t_833 env_t_833_value = make_env_t_833(v823,idx); closure_t closure816 = make_closure(lambda833, &env_t_833_value);
	array_number_t tmp = vector_build_given_storage(storage1821, closure816);
	array_number_t tmp2 = linalg_add_vecGivenStorage(storage2822, tmp, tmp);
	value_t res;
	res.number_t_value = (acc) + (linalg_sqnorm(tmp2));
	return res;
}
void programs_explicitMallocExample2(array_number_t v) {
	array_number_t storage1 = vector_alloc(10);
	array_number_t storage2 = vector_alloc(10);
	env_t_832 env_t_832_value = make_env_t_832(v,storage2,storage1); closure_t closure826 = make_closure(lambda832, &env_t_832_value);
	number_t sum = linalg_iterateNumber(closure826, 0, 0, 9);
	number_print(sum);
	free(storage2);
	;
	free(storage1);
	;
	return ;
}

void programs_small_tests(number_t dum) {
	number_t a834 = programs_test1(2);
	number_print(a834);
	number_print(programs_test2(2, a834));
	array_number_t v2835 = linalg_vectorRange(0, 99);
	programs_hoistingExample(v2835);
	programs_explicitMallocExample1(v2835);
	programs_explicitMallocExample2(v2835);
	return ;
}
#endif
