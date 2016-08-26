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
	number_t macroDef789 = 0;
	for(int idx = 0; idx <= 9; idx++){
		array_number_t tmp = array_slice(v, idx, (idx) + (9));
		macroDef789 = (macroDef789) + (linalg_sqnorm(linalg_add_vec(tmp, tmp)));
	}
	number_t sum = macroDef789;
	number_print(sum);
	return ;
}

void programs_explicitMallocExample1(array_number_t v) {
	array_number_t storage1 = vector_alloc(10);
	number_t macroDef798 = 0;
	for(int idx = 0; idx <= 9; idx++){
		array_number_t macroDef794 = (array_number_t)storage1;
		for(int i = 0; i < macroDef794->length; i++){
			
			macroDef794->arr[i] = v->arr[(i) + (idx)];
		}
		array_number_t tmp = macroDef794;
		macroDef798 = (macroDef798) + (linalg_sqnorm(linalg_add_vec(tmp, tmp)));
	}
	number_t sum = macroDef798;
	number_print(sum);
	free(storage1);
	;
	return ;
}

void programs_explicitMallocExample2(array_number_t v) {
	array_number_t storage1 = vector_alloc(10);
	array_number_t storage2 = vector_alloc(10);
	number_t macroDef808 = 0;
	for(int idx = 0; idx <= 9; idx++){
		array_number_t macroDef804 = (array_number_t)storage1;
		for(int i = 0; i < macroDef804->length; i++){
			
			macroDef804->arr[i] = v->arr[(i) + (idx)];
		}
		array_number_t tmp = macroDef804;
		array_number_t tmp2 = linalg_add_vecGivenStorage(storage2, tmp, tmp);
		macroDef808 = (macroDef808) + (linalg_sqnorm(tmp2));
	}
	number_t sum = macroDef808;
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

void programs_small_tests(number_t dum) {
	number_t a819 = programs_test1(2);
	number_print(a819);
	number_print(programs_test2(2, a819));
	array_number_t v2820 = linalg_vectorRange(0, 99);
	programs_hoistingExample(v2820);
	programs_explicitMallocExample1(v2820);
	programs_explicitMallocExample2(v2820);
	programs_stackAllocExample(2, 3, 5);
	return ;
}
#endif
