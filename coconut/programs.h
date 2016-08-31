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

void programs_hoistingExample(array_number_t v) {
	number_t macroDef798 = 0;
	for(int idx = 0; idx <= 9; idx++){
		array_number_t tmp = array_slice(v, idx, (idx) + (9));
		macroDef798 = (macroDef798) + (linalg_sqnorm(linalg_add_vec(tmp, tmp)));
	}
	number_t sum = macroDef798;
	number_print(sum);
	return ;
}

void programs_explicitMallocExample1(array_number_t v) {
	array_number_t storage1 = vector_alloc(10);
	number_t macroDef807 = 0;
	for(int idx = 0; idx <= 9; idx++){
		array_number_t macroDef803 = (array_number_t)storage1;
		for(int i = 0; i < macroDef803->length; i++){
			
			macroDef803->arr[i] = v->arr[(i) + (idx)];
		}
		array_number_t tmp = macroDef803;
		macroDef807 = (macroDef807) + (linalg_sqnorm(linalg_add_vec(tmp, tmp)));
	}
	number_t sum = macroDef807;
	number_print(sum);
	free(storage1);
	;
	return ;
}

void programs_explicitMallocExample2(array_number_t v) {
	array_number_t storage1 = vector_alloc(10);
	array_number_t storage2 = vector_alloc(10);
	number_t macroDef817 = 0;
	for(int idx = 0; idx <= 9; idx++){
		array_number_t macroDef813 = (array_number_t)storage1;
		for(int i = 0; i < macroDef813->length; i++){
			
			macroDef813->arr[i] = v->arr[(i) + (idx)];
		}
		array_number_t tmp = macroDef813;
		array_number_t tmp2 = linalg_add_vecGivenStorage(storage2, tmp, tmp);
		macroDef817 = (macroDef817) + (linalg_sqnorm(tmp2));
	}
	number_t sum = macroDef817;
	number_print(sum);
	free(storage2);
	;
	free(storage1);
	;
	return ;
}

void programs_stackAllocExample(number_t x, number_t y, number_t z) {
	array_number_t v = (array_number_t)malloc(sizeof(int) * 2);
	v->length=3;
	v->arr = (number_t*)malloc(sizeof(number_t) * 3);
	v->arr[0] = x;
	v->arr[1] = y;
	v->arr[2] = z;;
	array_number_t v2 = linalg_add_vec(v, v);
	array_print(v2);
	return ;
}

void programs_storageConvertorExample(card_t s, card_t e) {
	array_number_t v2 = linalg_vectorRange(s, e);
	array_print(v2);
	return ;
}
typedef empty_env_t env_t_841;

typedef struct env_t_842 {
	array_number_t b;
	array_number_t a;
} env_t_842;
env_t_842 make_env_t_842(array_number_t b,array_number_t a) {
	env_t_842 env;
	env.b = b;
	env.a = a;
	return env;
}

value_t lambda842(env_t_842* env834, index_t i) {
	array_number_t b833 = env834->b;
	array_number_t a832 = env834->a;
	value_t res;
	res.number_t_value = (a832->arr[i]) + (b833->arr[i]);
	return res;
}
value_t lambda841(env_t_841* env838, array_number_t a, array_number_t b) {
	card_t macroDef828 = a->length;
	env_t_842 env_t_842_value = make_env_t_842(b,a); closure_t closure836 = make_closure(lambda842, &env_t_842_value);
	value_t res;
	res.array_number_t_value = vector_build(macroDef828, closure836);
	return res;
}
array_number_t programs_vectorAddExample(number_t dum) {
	env_t_841 env_t_841_value = make_empty_env(); closure_t closure840 = make_closure(lambda841, &env_t_841_value);
	closure_t add = closure840;
	array_number_t vec1 = (array_number_t)malloc(sizeof(int) * 2);
	vec1->length=3;
	vec1->arr = (number_t*)malloc(sizeof(number_t) * 3);
	vec1->arr[0] = 1;
	vec1->arr[1] = 2;
	vec1->arr[2] = 3;;
	array_number_t vec2 = (array_number_t)malloc(sizeof(int) * 2);
	vec2->length=3;
	vec2->arr = (number_t*)malloc(sizeof(number_t) * 3);
	vec2->arr[0] = 4;
	vec2->arr[1] = 5;
	vec2->arr[2] = 6;;
	return add.lam(add.env, vec1, vec2).array_number_t_value;
}

void programs_small_tests(number_t dum) {
	number_t a843 = programs_test1(2);
	number_print(a843);
	number_print(programs_test2(2, a843));
	array_number_t v2844 = linalg_vectorRange(0, 99);
	programs_hoistingExample(v2844);
	programs_explicitMallocExample1(v2844);
	programs_explicitMallocExample2(v2844);
	programs_stackAllocExample(2, 3, 5);
	return ;
}
#endif
