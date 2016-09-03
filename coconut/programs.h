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
	number_t macroDef299 = 0;
	for(int idx = 0; idx <= 9; idx++){
		array_number_t tmp = array_slice(v, idx, (idx) + (9));
		macroDef299 = (macroDef299) + (linalg_sqnorm(linalg_add_vec(tmp, tmp)));
	}
	number_t sum = macroDef299;
	number_print(sum);
	return ;
}

void programs_explicitMallocExample1(array_number_t v) {
	array_number_t storage1 = vector_alloc(10);
	number_t macroDef302 = 0;
	for(int idx = 0; idx <= 9; idx++){
		array_number_t macroDef301 = (array_number_t)storage1;
		for(int i = 0; i < macroDef301->length; i++){
			
			macroDef301->arr[i] = v->arr[(i) + (idx)];
		}
		array_number_t tmp = macroDef301;
		macroDef302 = (macroDef302) + (linalg_sqnorm(linalg_add_vec(tmp, tmp)));
	}
	number_t sum = macroDef302;
	number_print(sum);
	free(storage1);
	;
	return ;
}

void programs_explicitMallocExample2(array_number_t v) {
	array_number_t storage1 = vector_alloc(10);
	array_number_t storage2 = vector_alloc(10);
	number_t macroDef306 = 0;
	for(int idx = 0; idx <= 9; idx++){
		array_number_t macroDef305 = (array_number_t)storage1;
		for(int i = 0; i < macroDef305->length; i++){
			
			macroDef305->arr[i] = v->arr[(i) + (idx)];
		}
		array_number_t tmp = macroDef305;
		array_number_t tmp2 = linalg_add_vecGivenStorage(storage2, tmp, tmp);
		macroDef306 = (macroDef306) + (linalg_sqnorm(tmp2));
	}
	number_t sum = macroDef306;
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
typedef empty_env_t env_t_321;

typedef struct env_t_322 {
	array_number_t b;
	array_number_t a;
} env_t_322;
env_t_322 make_env_t_322(array_number_t b,array_number_t a) {
	env_t_322 env;
	env.b = b;
	env.a = a;
	return env;
}

value_t lambda322(env_t_322* env315, index_t i) {
	array_number_t b314 = env315->b;
	array_number_t a313 = env315->a;
	value_t res;
	res.number_t_value = (a313->arr[i]) + (b314->arr[i]);
	return res;
}
value_t lambda321(env_t_321* env318, array_number_t a, array_number_t b) {
	card_t macroDef312 = a->length;
	env_t_322 env_t_322_value = make_env_t_322(b,a); closure_t closure317 = make_closure(lambda322, &env_t_322_value);
	value_t res;
	res.array_number_t_value = vector_build(macroDef312, closure317);
	return res;
}
array_number_t programs_vectorAddExample(number_t dum) {
	env_t_321 env_t_321_value = make_empty_env(); closure_t closure320 = make_closure(lambda321, &env_t_321_value);
	closure_t add = closure320;
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
	number_t a323 = programs_test1(2);
	number_print(a323);
	number_print(programs_test2(2, a323));
	array_number_t v2324 = linalg_vectorRange(0, 99);
	programs_hoistingExample(v2324);
	programs_explicitMallocExample1(v2324);
	programs_explicitMallocExample2(v2324);
	programs_stackAllocExample(2, 3, 5);
	return ;
}
#endif
