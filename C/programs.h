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
	
	return TOP_LEVEL_linalg_vectorAdd(v1, TOP_LEVEL_linalg_vectorAdd(v2, v3));
}

array_array_number_t TOP_LEVEL_programs_matrix_add3(array_array_number_t m1, array_array_number_t m2, array_array_number_t m3) {
	
	return TOP_LEVEL_linalg_matrixAdd(m1, TOP_LEVEL_linalg_matrixAdd(m2, m3));
}

void TOP_LEVEL_programs_hoistingExample(array_number_t v) {
	number_t macroDef233 = 0;
	for(int idx = 0; idx <= 9; idx++){
		array_number_t tmp = array_slice(v, idx, (idx) + (9));
		macroDef233 = (macroDef233) + (TOP_LEVEL_linalg_sqnorm(TOP_LEVEL_linalg_vectorAdd(tmp, tmp)));;
	}
	number_t sum = macroDef233;
	number_print(sum);
	return ;
}

void TOP_LEVEL_programs_explicitMallocExample1(array_number_t v) {
	card_t size239 = width_matrix_shape_t(nested_shape_card_t(0, 10));
	array_number_t storage1 = storage_alloc(size239);
	number_t macroDef236 = 0;
	for(int idx = 0; idx <= 9; idx++){
		array_number_t macroDef235 = (array_number_t)storage1;
		macroDef235->length=10;
		macroDef235->arr=(number_t*)(STG_OFFSET(macroDef235, VECTOR_HEADER_BYTES));
		storage_t s = macroDef235;
		for(int i = 0; i < macroDef235->length; i++){
			
			macroDef235->arr[i] = v->arr[(i) + (idx)];;
			s = STG_OFFSET(s, sizeof(number_t));
		}
		array_number_t tmp = macroDef235;
		macroDef236 = (macroDef236) + (TOP_LEVEL_linalg_sqnorm(TOP_LEVEL_linalg_vectorAdd(tmp, tmp)));;
	}
	number_t sum = macroDef236;
	number_print(sum);
	storage_free(storage1, size239);
	;
	return ;
}

array_number_t TOP_LEVEL_programs_vectorMap2GivenStorage(storage_t storage, closure_t f, array_number_t v1, array_number_t v2) {
	card_t macroDef240 = v1->length;
	card_t macroDef241 = v1->length;
	array_number_t macroDef242 = (array_number_t)storage;
		macroDef242->length=macroDef240;
		macroDef242->arr=(number_t*)(STG_OFFSET(macroDef242, VECTOR_HEADER_BYTES));
		storage_t s = macroDef242;
		for(int i = 0; i < macroDef242->length; i++){
			
			macroDef242->arr[i] = f.lam(f.env, v1->arr[i], v2->arr[i]).number_t_value;;
			s = STG_OFFSET(s, sizeof(number_t));
		}
	return macroDef242;
}
typedef empty_env_t env_t_246;


value_t lambda246(env_t_246* env243, number_t x0, number_t y0) {
	
	value_t res;
	res.number_t_value = (x0) + (y0);
	return res;
}
array_number_t TOP_LEVEL_programs_add_vecGivenStorage(storage_t s, array_number_t x, array_number_t y) {
	env_t_246 env_t_246_value = make_empty_env(); closure_t closure245 = make_closure(lambda246, &env_t_246_value);
	return TOP_LEVEL_programs_vectorMap2GivenStorage(s, closure245, x, y);
}

void TOP_LEVEL_programs_explicitMallocExample2(array_number_t v) {
	card_t size253 = width_matrix_shape_t(nested_shape_card_t(0, 10));
	array_number_t storage1 = storage_alloc(size253);
	card_t size252 = width_matrix_shape_t(nested_shape_card_t(0, 10));
	array_number_t storage2 = storage_alloc(size252);
	number_t macroDef248 = 0;
	for(int idx = 0; idx <= 9; idx++){
		array_number_t macroDef247 = (array_number_t)storage1;
		macroDef247->length=10;
		macroDef247->arr=(number_t*)(STG_OFFSET(macroDef247, VECTOR_HEADER_BYTES));
		storage_t s = macroDef247;
		for(int i = 0; i < macroDef247->length; i++){
			
			macroDef247->arr[i] = v->arr[(i) + (idx)];;
			s = STG_OFFSET(s, sizeof(number_t));
		}
		array_number_t tmp = macroDef247;
		array_number_t tmp2 = TOP_LEVEL_programs_add_vecGivenStorage(storage2, tmp, tmp);
		macroDef248 = (macroDef248) + (TOP_LEVEL_linalg_sqnorm(tmp2));;
	}
	number_t sum = macroDef248;
	number_print(sum);
	storage_free(storage2, size252);
	;
	storage_free(storage1, size253);
	;
	return ;
}

void TOP_LEVEL_programs_stackAllocExample(number_t x, number_t y, number_t z) {
	array_number_t v = (array_number_t)storage_alloc(sizeof(int) * 2);
	v->length=3;
	v->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	v->arr[0] = x;
	v->arr[1] = y;
	v->arr[2] = z;;
	array_number_t v2 = TOP_LEVEL_linalg_vectorAdd(v, v);
	array_print(v2);
	return ;
}

void TOP_LEVEL_programs_storageConvertorExample(card_t s, card_t e) {
	array_number_t v2 = TOP_LEVEL_linalg_vectorRange(s, e);
	array_print(v2);
	return ;
}
typedef empty_env_t env_t_261;


value_t lambda261(env_t_261* env258, array_number_t a, array_number_t b) {
	card_t macroDef256 = a->length;
	array_number_t macroDef257 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef257->length=macroDef256;
	macroDef257->arr = (number_t*)storage_alloc(sizeof(number_t) * macroDef256);
		for(int i = 0; i < macroDef257->length; i++){
			
			macroDef257->arr[i] = (a->arr[i]) + (b->arr[i]);;
		}
	value_t res;
	res.array_number_t_value = macroDef257;
	return res;
}
array_number_t TOP_LEVEL_programs_vectorAddExample(number_t dum) {
	env_t_261 env_t_261_value = make_empty_env(); closure_t closure260 = make_closure(lambda261, &env_t_261_value);
	closure_t add = closure260;
	array_number_t vec1 = (array_number_t)storage_alloc(sizeof(int) * 2);
	vec1->length=3;
	vec1->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	vec1->arr[0] = 1;
	vec1->arr[1] = 2;
	vec1->arr[2] = 3;;
	array_number_t vec2 = (array_number_t)storage_alloc(sizeof(int) * 2);
	vec2->length=3;
	vec2->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	vec2->arr[0] = 4;
	vec2->arr[1] = 5;
	vec2->arr[2] = 6;;
	return add.lam(add.env, vec1, vec2).array_number_t_value;
}

void TOP_LEVEL_programs_small_tests(number_t dum) {
	number_t a262 = TOP_LEVEL_programs_test1(2);
	number_print(a262);
	number_print(TOP_LEVEL_programs_test2(2, a262));
	array_number_t v2263 = TOP_LEVEL_linalg_vectorRange(0, 99);
	TOP_LEVEL_programs_hoistingExample(v2263);
	TOP_LEVEL_programs_explicitMallocExample1(v2263);
	TOP_LEVEL_programs_explicitMallocExample2(v2263);
	TOP_LEVEL_programs_stackAllocExample(2, 3, 5);
	return ;
}
#endif
