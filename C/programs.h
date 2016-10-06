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
	number_t macroDef245 = 0;
	for(int idx = 0; idx <= 9; idx++){
		array_number_t tmp = array_slice(v, idx, (idx) + (9));
		macroDef245 = (macroDef245) + (TOP_LEVEL_linalg_sqnorm(TOP_LEVEL_linalg_vectorAdd(tmp, tmp)));;
	}
	number_t sum = macroDef245;
	number_print(sum);
	return ;
}

void TOP_LEVEL_programs_explicitMallocExample1(array_number_t v) {
	card_t size251 = width_matrix_shape_t(nested_shape_card_t(0, 10));
	array_number_t storage1 = storage_alloc(size251);
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
		macroDef248 = (macroDef248) + (TOP_LEVEL_linalg_sqnorm(TOP_LEVEL_linalg_vectorAdd(tmp, tmp)));;
	}
	number_t sum = macroDef248;
	number_print(sum);
	storage_free(storage1, size251);
	;
	return ;
}

array_number_t TOP_LEVEL_programs_vectorMap2GivenStorage(storage_t storage, closure_t f, array_number_t v1, array_number_t v2) {
	card_t macroDef252 = v1->length;
	card_t macroDef253 = v1->length;
	array_number_t macroDef254 = (array_number_t)storage;
		macroDef254->length=macroDef252;
		macroDef254->arr=(number_t*)(STG_OFFSET(macroDef254, VECTOR_HEADER_BYTES));
		storage_t s = macroDef254;
		for(int i = 0; i < macroDef254->length; i++){
			
			macroDef254->arr[i] = f.lam(f.env, v1->arr[i], v2->arr[i]).number_t_value;;
			s = STG_OFFSET(s, sizeof(number_t));
		}
	return macroDef254;
}
typedef empty_env_t env_t_258;


value_t lambda258(env_t_258* env255, number_t x0, number_t y0) {
	
	value_t res;
	res.number_t_value = (x0) + (y0);
	return res;
}
array_number_t TOP_LEVEL_programs_add_vecGivenStorage(storage_t s, array_number_t x, array_number_t y) {
	env_t_258 env_t_258_value = make_empty_env(); closure_t closure257 = make_closure(lambda258, &env_t_258_value);
	return TOP_LEVEL_programs_vectorMap2GivenStorage(s, closure257, x, y);
}

void TOP_LEVEL_programs_explicitMallocExample2(array_number_t v) {
	card_t size265 = width_matrix_shape_t(nested_shape_card_t(0, 10));
	array_number_t storage1 = storage_alloc(size265);
	card_t size264 = width_matrix_shape_t(nested_shape_card_t(0, 10));
	array_number_t storage2 = storage_alloc(size264);
	number_t macroDef260 = 0;
	for(int idx = 0; idx <= 9; idx++){
		array_number_t macroDef259 = (array_number_t)storage1;
		macroDef259->length=10;
		macroDef259->arr=(number_t*)(STG_OFFSET(macroDef259, VECTOR_HEADER_BYTES));
		storage_t s = macroDef259;
		for(int i = 0; i < macroDef259->length; i++){
			
			macroDef259->arr[i] = v->arr[(i) + (idx)];;
			s = STG_OFFSET(s, sizeof(number_t));
		}
		array_number_t tmp = macroDef259;
		array_number_t tmp2 = TOP_LEVEL_programs_add_vecGivenStorage(storage2, tmp, tmp);
		macroDef260 = (macroDef260) + (TOP_LEVEL_linalg_sqnorm(tmp2));;
	}
	number_t sum = macroDef260;
	number_print(sum);
	storage_free(storage2, size264);
	;
	storage_free(storage1, size265);
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
typedef empty_env_t env_t_273;


value_t lambda273(env_t_273* env270, array_number_t a, array_number_t b) {
	card_t macroDef268 = a->length;
	array_number_t macroDef269 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef269->length=macroDef268;
	macroDef269->arr = (number_t*)storage_alloc(sizeof(number_t) * macroDef268);
		for(int i = 0; i < macroDef269->length; i++){
			
			macroDef269->arr[i] = (a->arr[i]) + (b->arr[i]);;
		}
	value_t res;
	res.array_number_t_value = macroDef269;
	return res;
}
array_number_t TOP_LEVEL_programs_vectorAddExample(number_t dum) {
	env_t_273 env_t_273_value = make_empty_env(); closure_t closure272 = make_closure(lambda273, &env_t_273_value);
	closure_t add = closure272;
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
	number_t a274 = TOP_LEVEL_programs_test1(2);
	number_print(a274);
	number_print(TOP_LEVEL_programs_test2(2, a274));
	array_number_t v2275 = TOP_LEVEL_linalg_vectorRange(0, 99);
	TOP_LEVEL_programs_hoistingExample(v2275);
	TOP_LEVEL_programs_explicitMallocExample1(v2275);
	TOP_LEVEL_programs_explicitMallocExample2(v2275);
	TOP_LEVEL_programs_stackAllocExample(2, 3, 5);
	return ;
}
#endif
