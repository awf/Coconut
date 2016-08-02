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
	number_t macroDef773 = 0;
	for(int idx = 0; idx <= 9; idx++){
		array_number_t tmp = array_slice(v, idx, (idx) + (9));
		macroDef773 = (macroDef773) + (linalg_sqnorm(linalg_add_vec(tmp, tmp)));
	}
	number_t sum = macroDef773;
	number_print(sum);
	return ;
}

void programs_explicitMallocExample1(array_number_t v) {
	array_number_t storage1 = vector_alloc(10);
	number_t macroDef782 = 0;
	for(int idx = 0; idx <= 9; idx++){
		array_number_t macroDef778 = (array_number_t)storage1;
		for(int i = 0; i < macroDef778->length; i++){
			
			macroDef778->arr[i] = v->arr[(i) + (idx)];
		}
		array_number_t tmp = macroDef778;
		macroDef782 = (macroDef782) + (linalg_sqnorm(linalg_add_vec(tmp, tmp)));
	}
	number_t sum = macroDef782;
	number_print(sum);
	free(storage1);
	;
	return ;
}

void programs_explicitMallocExample2(array_number_t v) {
	array_number_t storage1 = vector_alloc(10);
	array_number_t storage2 = vector_alloc(10);
	number_t macroDef792 = 0;
	for(int idx = 0; idx <= 9; idx++){
		array_number_t macroDef788 = (array_number_t)storage1;
		for(int i = 0; i < macroDef788->length; i++){
			
			macroDef788->arr[i] = v->arr[(i) + (idx)];
		}
		array_number_t tmp = macroDef788;
		array_number_t tmp2 = linalg_add_vecGivenStorage(storage2, tmp, tmp);
		macroDef792 = (macroDef792) + (linalg_sqnorm(tmp2));
	}
	number_t sum = macroDef792;
	number_print(sum);
	free(storage2);
	;
	free(storage1);
	;
	return ;
}

void programs_small_tests(number_t dum) {
	number_t a797 = programs_test1(2);
	number_print(a797);
	number_print(programs_test2(2, a797));
	array_number_t v2798 = linalg_vectorRange(0, 99);
	programs_hoistingExample(v2798);
	programs_explicitMallocExample1(v2798);
	programs_explicitMallocExample2(v2798);
	return ;
}
#endif
