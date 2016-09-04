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
	number_t macroDef266 = 0;
	for(int idx = 0; idx <= 9; idx++){
		array_number_t tmp = array_slice(v, idx, (idx) + (9));
		macroDef266 = (macroDef266) + (TOP_LEVEL_linalg_sqnorm(TOP_LEVEL_linalg_add_vec(tmp, tmp)));
	}
	number_t sum = macroDef266;
	number_print(sum);
	return ;
}

void TOP_LEVEL_programs_explicitMallocExample1(array_number_t v) {
	array_number_t storage1 = vector_alloc(10);
	number_t macroDef269 = 0;
	for(int idx = 0; idx <= 9; idx++){
		array_number_t macroDef268 = (array_number_t)storage1;
		for(int i = 0; i < macroDef268->length; i++){
			
			macroDef268->arr[i] = v->arr[(i) + (idx)];
		}
		array_number_t tmp = macroDef268;
		macroDef269 = (macroDef269) + (TOP_LEVEL_linalg_sqnorm(TOP_LEVEL_linalg_add_vec(tmp, tmp)));
	}
	number_t sum = macroDef269;
	number_print(sum);
	free(storage1);
	;
	return ;
}

void TOP_LEVEL_programs_explicitMallocExample2(array_number_t v) {
	array_number_t storage1 = vector_alloc(10);
	array_number_t storage2 = vector_alloc(10);
	number_t macroDef273 = 0;
	for(int idx = 0; idx <= 9; idx++){
		array_number_t macroDef272 = (array_number_t)storage1;
		for(int i = 0; i < macroDef272->length; i++){
			
			macroDef272->arr[i] = v->arr[(i) + (idx)];
		}
		array_number_t tmp = macroDef272;
		array_number_t tmp2 = TOP_LEVEL_linalg_add_vecGivenStorage(storage2, tmp, tmp);
		macroDef273 = (macroDef273) + (TOP_LEVEL_linalg_sqnorm(tmp2));
	}
	number_t sum = macroDef273;
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
typedef empty_env_t env_t_284;


value_t lambda284(env_t_284* env281, array_number_t a, array_number_t b) {
	card_t macroDef279 = a->length;
	array_number_t macroDef280 = (array_number_t)malloc(sizeof(int) * 2);
	macroDef280->length=macroDef279;
	macroDef280->arr = (number_t*)malloc(sizeof(number_t) * macroDef279);
		for(int i = 0; i < macroDef280->length; i++){
			
			macroDef280->arr[i] = (a->arr[i]) + (b->arr[i]);
		}
	value_t res;
	res.array_number_t_value = macroDef280;
	return res;
}
array_number_t TOP_LEVEL_programs_vectorAddExample(number_t dum) {
	env_t_284 env_t_284_value = make_empty_env(); closure_t closure283 = make_closure(lambda284, &env_t_284_value);
	closure_t add = closure283;
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
	number_t a285 = TOP_LEVEL_programs_test1(2);
	number_print(a285);
	number_print(TOP_LEVEL_programs_test2(2, a285));
	array_number_t v2286 = TOP_LEVEL_linalg_vectorRange(0, 99);
	TOP_LEVEL_programs_hoistingExample(v2286);
	TOP_LEVEL_programs_explicitMallocExample1(v2286);
	TOP_LEVEL_programs_explicitMallocExample2(v2286);
	TOP_LEVEL_programs_stackAllocExample(2, 3, 5);
	return ;
}
#endif
