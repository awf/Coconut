#ifndef __PROGRAMS_H__ 
#define __PROGRAMS_H__ 
#include "runtime/fsharp.h"
#include <stdio.h>
#include <math.h>
#include "linalg.h"

number_t TOP_LEVEL_programs_test1(number_t x) {
	
	return (1) / ((1) + (x));
}

number_t TOP_LEVEL_programs_test2(number_t x, number_t b) {
	
	return x;
}

array_number_t TOP_LEVEL_programs_vector_add3(array_number_t v1, array_number_t v2, array_number_t v3) {
	
	return TOP_LEVEL_linalg_add_vec(v1, TOP_LEVEL_linalg_add_vec(v2, v3));
}

array_array_number_t TOP_LEVEL_programs_matrix_add3(array_array_number_t m1, array_array_number_t m2, array_array_number_t m3) {
	
	return TOP_LEVEL_linalg_matrixAdd(m1, TOP_LEVEL_linalg_matrixAdd(m2, m3));
}

void TOP_LEVEL_programs_hoistingExample(array_number_t v) {
	number_t macroDef276 = 0;
	for(int idx = 0; idx <= 9; idx++){
		array_number_t tmp = array_slice(v, idx, (idx) + (9));
		macroDef276 = (macroDef276) + (TOP_LEVEL_linalg_sqnorm(TOP_LEVEL_linalg_add_vec(tmp, tmp)));
	}
	number_t sum = macroDef276;
	number_print(sum);
	return ;
}

void TOP_LEVEL_programs_explicitMallocExample1(array_number_t v) {
	array_number_t storage1 = vector_alloc(10);
	number_t macroDef279 = 0;
	for(int idx = 0; idx <= 9; idx++){
		array_number_t macroDef278 = (array_number_t)storage1;
		for(int i = 0; i < macroDef278->length; i++){
			
			macroDef278->arr[i] = v->arr[(i) + (idx)];
		}
		array_number_t tmp = macroDef278;
		macroDef279 = (macroDef279) + (TOP_LEVEL_linalg_sqnorm(TOP_LEVEL_linalg_add_vec(tmp, tmp)));
	}
	number_t sum = macroDef279;
	number_print(sum);
	free(storage1);
	;
	return ;
}

void TOP_LEVEL_programs_explicitMallocExample2(array_number_t v) {
	array_number_t storage1 = vector_alloc(10);
	array_number_t storage2 = vector_alloc(10);
	number_t macroDef283 = 0;
	for(int idx = 0; idx <= 9; idx++){
		array_number_t macroDef282 = (array_number_t)storage1;
		for(int i = 0; i < macroDef282->length; i++){
			
			macroDef282->arr[i] = v->arr[(i) + (idx)];
		}
		array_number_t tmp = macroDef282;
		array_number_t tmp2 = TOP_LEVEL_linalg_add_vecGivenStorage(storage2, tmp, tmp);
		macroDef283 = (macroDef283) + (TOP_LEVEL_linalg_sqnorm(tmp2));
	}
	number_t sum = macroDef283;
	number_print(sum);
	free(storage2);
	;
	free(storage1);
	;
	return ;
}

void TOP_LEVEL_programs_stackAllocExample(number_t x, number_t y, number_t z) {
	array_number_t v = (array_number_t)malloc(sizeof(int) * 2);
	v->length=3;
	v->arr = (number_t*)malloc(sizeof(number_t) * 3);
	v->arr[0] = x;
	v->arr[1] = y;
	v->arr[2] = z;;
	array_number_t v2 = TOP_LEVEL_linalg_add_vec(v, v);
	array_print(v2);
	return ;
}

void TOP_LEVEL_programs_storageConvertorExample(card_t s, card_t e) {
	array_number_t v2 = TOP_LEVEL_linalg_vectorRange(s, e);
	array_print(v2);
	return ;
}
typedef empty_env_t env_t_294;


value_t lambda294(env_t_294* env291, array_number_t a, array_number_t b) {
	card_t macroDef289 = a->length;
	array_number_t macroDef290 = (array_number_t)malloc(sizeof(int) * 2);
	macroDef290->length=macroDef289;
	macroDef290->arr = (number_t*)malloc(sizeof(number_t) * macroDef289);
		for(int i = 0; i < macroDef290->length; i++){
			
			macroDef290->arr[i] = (a->arr[i]) + (b->arr[i]);
		}
	value_t res;
	res.array_number_t_value = macroDef290;
	return res;
}
array_number_t TOP_LEVEL_programs_vectorAddExample(number_t dum) {
	env_t_294 env_t_294_value = make_empty_env(); closure_t closure293 = make_closure(lambda294, &env_t_294_value);
	closure_t add = closure293;
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

void TOP_LEVEL_programs_small_tests(number_t dum) {
	number_t a295 = TOP_LEVEL_programs_test1(2);
	number_print(a295);
	number_print(TOP_LEVEL_programs_test2(2, a295));
	array_number_t v2296 = TOP_LEVEL_linalg_vectorRange(0, 99);
	TOP_LEVEL_programs_hoistingExample(v2296);
	TOP_LEVEL_programs_explicitMallocExample1(v2296);
	TOP_LEVEL_programs_explicitMallocExample2(v2296);
	TOP_LEVEL_programs_stackAllocExample(2, 3, 5);
	return ;
}
#endif
