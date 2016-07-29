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

void programs_small_tests(number_t dum) {
	number_t a296 = programs_test1(2);
	number_print(a296);
	number_print(programs_test2(2, a296));
	return ;
}
typedef struct env_t_309 {
	array_number_t v;
} env_t_309;
env_t_309* make_env_t_309(array_number_t v) {
	env_t_309* env = (env_t_309*)malloc(sizeof(env_t_309));
	env->v = v;
	return env;
}

value_t lambda309(env_t_309* env305, number_t acc299, index_t idx300) {
	array_number_t v304 = env305->v;
	array_number_t tmp301 = array_slice(v304, idx300, (idx300) + (9));
	value_t res;
	res.number_t_value = linalg_sqnorm(linalg_add_vec(tmp301, tmp301));
	return res;
}
void programs_hoistingExample(array_number_t v) {
	closure_t* closure307 = make_closure(lambda309, make_env_t_309(v));
	number_print(linalg_iterateNumber(closure307, 0, 0, 9));
	return ;
}
#endif
