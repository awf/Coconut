#ifndef __PROGRAMS_H__ 
#define __PROGRAMS_H__ 
#include "../../Runtime/C/fsharp.h"
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
	number_t macroDef248 = 0;
	for(int idx = 0; idx < 10; idx++){
		array_number_t tmp = array_slice(v, idx, (idx) + (9));
		macroDef248 = (macroDef248) + (TOP_LEVEL_linalg_sqnorm(TOP_LEVEL_linalg_vectorAdd(tmp, tmp)));;
	}
	number_t sum = macroDef248;
	number_print(sum);
	return ;
}

void TOP_LEVEL_programs_explicitMallocExample1(array_number_t v) {
	card_t size254 = width_matrix_shape_t(nested_shape_card_t(0, 10));
	array_number_t storage1 = storage_alloc(size254);
	number_t macroDef251 = 0;
	for(int idx = 0; idx < 10; idx++){
		array_number_t macroDef250 = (array_number_t)storage1;
		macroDef250->length=10;
		macroDef250->arr=(number_t*)(STG_OFFSET(macroDef250, VECTOR_HEADER_BYTES));
		storage_t s = macroDef250;
		for(int i = 0; i < macroDef250->length; i++){
			
			macroDef250->arr[i] = v->arr[(i) + (idx)];;
			s = STG_OFFSET(s, sizeof(number_t));
		}
		array_number_t tmp = macroDef250;
		macroDef251 = (macroDef251) + (TOP_LEVEL_linalg_sqnorm(TOP_LEVEL_linalg_vectorAdd(tmp, tmp)));;
	}
	number_t sum = macroDef251;
	number_print(sum);
	storage_free(storage1, size254);
	;
	return ;
}

array_number_t TOP_LEVEL_programs_vectorMap2GivenStorage(storage_t storage, closure_t f, array_number_t v1, array_number_t v2) {
	card_t macroDef255 = v1->length;
	card_t macroDef256 = v1->length;
	array_number_t macroDef257 = (array_number_t)storage;
		macroDef257->length=macroDef255;
		macroDef257->arr=(number_t*)(STG_OFFSET(macroDef257, VECTOR_HEADER_BYTES));
		storage_t s = macroDef257;
		for(int i = 0; i < macroDef257->length; i++){
			
			macroDef257->arr[i] = f.lam(f.env, v1->arr[i], v2->arr[i]).number_t_value;;
			s = STG_OFFSET(s, sizeof(number_t));
		}
	return macroDef257;
}
typedef empty_env_t env_t_261;


value_t lambda261(env_t_261* env258, number_t x0, number_t y0) {
	
	value_t res;
	res.number_t_value = (x0) + (y0);
	return res;
}
array_number_t TOP_LEVEL_programs_add_vecGivenStorage(storage_t s, array_number_t x, array_number_t y) {
	env_t_261 env_t_261_value = make_empty_env(); closure_t closure260 = make_closure(lambda261, &env_t_261_value);
	return TOP_LEVEL_programs_vectorMap2GivenStorage(s, closure260, x, y);
}

void TOP_LEVEL_programs_explicitMallocExample2(array_number_t v) {
	card_t size268 = width_matrix_shape_t(nested_shape_card_t(0, 10));
	array_number_t storage1 = storage_alloc(size268);
	card_t size267 = width_matrix_shape_t(nested_shape_card_t(0, 10));
	array_number_t storage2 = storage_alloc(size267);
	number_t macroDef263 = 0;
	for(int idx = 0; idx < 10; idx++){
		array_number_t macroDef262 = (array_number_t)storage1;
		macroDef262->length=10;
		macroDef262->arr=(number_t*)(STG_OFFSET(macroDef262, VECTOR_HEADER_BYTES));
		storage_t s = macroDef262;
		for(int i = 0; i < macroDef262->length; i++){
			
			macroDef262->arr[i] = v->arr[(i) + (idx)];;
			s = STG_OFFSET(s, sizeof(number_t));
		}
		array_number_t tmp = macroDef262;
		array_number_t tmp2 = TOP_LEVEL_programs_add_vecGivenStorage(storage2, tmp, tmp);
		macroDef263 = (macroDef263) + (TOP_LEVEL_linalg_sqnorm(tmp2));;
	}
	number_t sum = macroDef263;
	number_print(sum);
	storage_free(storage2, size267);
	;
	storage_free(storage1, size268);
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
typedef empty_env_t env_t_276;


value_t lambda276(env_t_276* env273, array_number_t a, array_number_t b) {
	card_t macroDef271 = a->length;
	array_number_t macroDef272 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef272->length=macroDef271;
	macroDef272->arr = (number_t*)storage_alloc(sizeof(number_t) * macroDef271);
		for(int i = 0; i < macroDef272->length; i++){
			
			macroDef272->arr[i] = (a->arr[i]) + (b->arr[i]);;
		}
	value_t res;
	res.array_number_t_value = macroDef272;
	return res;
}
array_number_t TOP_LEVEL_programs_vectorAddExample(number_t dum) {
	env_t_276 env_t_276_value = make_empty_env(); closure_t closure275 = make_closure(lambda276, &env_t_276_value);
	closure_t add = closure275;
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
	number_t a277 = TOP_LEVEL_programs_test1(2);
	number_print(a277);
	number_print(TOP_LEVEL_programs_test2(2, a277));
	array_number_t v2278 = TOP_LEVEL_linalg_vectorRange(0, 99);
	TOP_LEVEL_programs_hoistingExample(v2278);
	TOP_LEVEL_programs_explicitMallocExample1(v2278);
	TOP_LEVEL_programs_explicitMallocExample2(v2278);
	TOP_LEVEL_programs_stackAllocExample(2, 3, 5);
	return ;
}
#endif
