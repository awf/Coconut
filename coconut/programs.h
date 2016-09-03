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
	number_t macroDef252 = 0;
	for(int idx = 0; idx <= 9; idx++){
		array_number_t tmp = array_slice(v, idx, (idx) + (9));
		macroDef252 = (macroDef252) + (linalg_sqnorm(linalg_add_vec(tmp, tmp)));
	}
	number_t sum = macroDef252;
	number_print(sum);
	return ;
}

void programs_explicitMallocExample1(array_number_t v) {
	array_number_t storage1 = vector_alloc(10);
	number_t macroDef255 = 0;
	for(int idx = 0; idx <= 9; idx++){
		array_number_t macroDef254 = (array_number_t)storage1;
		for(int i = 0; i < macroDef254->length; i++){
			
			macroDef254->arr[i] = v->arr[(i) + (idx)];
		}
		array_number_t tmp = macroDef254;
		macroDef255 = (macroDef255) + (linalg_sqnorm(linalg_add_vec(tmp, tmp)));
	}
	number_t sum = macroDef255;
	number_print(sum);
	free(storage1);
	;
	return ;
}

void programs_explicitMallocExample2(array_number_t v) {
	array_number_t storage1 = vector_alloc(10);
	array_number_t storage2 = vector_alloc(10);
	number_t macroDef259 = 0;
	for(int idx = 0; idx <= 9; idx++){
		array_number_t macroDef258 = (array_number_t)storage1;
		for(int i = 0; i < macroDef258->length; i++){
			
			macroDef258->arr[i] = v->arr[(i) + (idx)];
		}
		array_number_t tmp = macroDef258;
		array_number_t tmp2 = linalg_add_vecGivenStorage(storage2, tmp, tmp);
		macroDef259 = (macroDef259) + (linalg_sqnorm(tmp2));
	}
	number_t sum = macroDef259;
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
typedef empty_env_t env_t_270;


value_t lambda270(env_t_270* env267, array_number_t a, array_number_t b) {
	card_t macroDef265 = a->length;
	array_number_t macroDef266 = (array_number_t)malloc(sizeof(int) * 2);
	macroDef266->length=macroDef265;
	macroDef266->arr = (number_t*)malloc(sizeof(number_t) * macroDef265);
		for(int i = 0; i < macroDef266->length; i++){
			
			macroDef266->arr[i] = (a->arr[i]) + (b->arr[i]);
		}
	value_t res;
	res.array_number_t_value = macroDef266;
	return res;
}
array_number_t programs_vectorAddExample(number_t dum) {
	env_t_270 env_t_270_value = make_empty_env(); closure_t closure269 = make_closure(lambda270, &env_t_270_value);
	closure_t add = closure269;
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
	number_t a271 = programs_test1(2);
	number_print(a271);
	number_print(programs_test2(2, a271));
	array_number_t v2272 = linalg_vectorRange(0, 99);
	programs_hoistingExample(v2272);
	programs_explicitMallocExample1(v2272);
	programs_explicitMallocExample2(v2272);
	programs_stackAllocExample(2, 3, 5);
	return ;
}
#endif
