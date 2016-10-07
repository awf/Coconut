#ifndef __CCODEGENTESTS_H__ 
#define __CCODEGENTESTS_H__ 
#include "runtime/fsharp.h"
#include <stdio.h>
#include <math.h>

array_array_number_t TOP_LEVEL_ccodegentests_closure_bug1(array_array_number_t m1, array_array_number_t m2) {
	array_array_number_t macroDef309 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef309->length=10;
	macroDef309->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * 10);
		for(int i = 0; i < macroDef309->length; i++){
			array_number_t macroDef308 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef308->length=20;
	macroDef308->arr = (number_t*)storage_alloc(sizeof(number_t) * 20);
		for(int j = 0; j < macroDef308->length; j++){
			
			macroDef308->arr[j] = (double)(j);;
		}
			macroDef309->arr[i] = macroDef308;;
		}
	return macroDef309;
}

array_array_number_t TOP_LEVEL_ccodegentests_closure_bug2(array_array_number_t m1, array_array_number_t m2) {
	array_array_number_t macroDef311 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef311->length=10;
	macroDef311->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * 10);
		for(int i = 0; i < macroDef311->length; i++){
			array_number_t macroDef310 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef310->length=20;
	macroDef310->arr = (number_t*)storage_alloc(sizeof(number_t) * 20);
		for(int j = 0; j < macroDef310->length; j++){
			
			macroDef310->arr[j] = (double)((i) + (j));;
		}
			macroDef311->arr[i] = macroDef310;;
		}
	return macroDef311;
}

array_array_number_t TOP_LEVEL_ccodegentests_closure_bug3(array_array_number_t m1, array_array_number_t m2) {
	number_t n = 3;
	array_array_number_t macroDef313 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef313->length=10;
	macroDef313->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * 10);
		for(int i = 0; i < macroDef313->length; i++){
			array_number_t macroDef312 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef312->length=20;
	macroDef312->arr = (number_t*)storage_alloc(sizeof(number_t) * 20);
		for(int j = 0; j < macroDef312->length; j++){
			
			macroDef312->arr[j] = ((double)((i) + (j))) * (n);;
		}
			macroDef313->arr[i] = macroDef312;;
		}
	return macroDef313;
}

void TOP_LEVEL_ccodegentests_valloc_cps_feature1(array_number_t dum) {
	card_t size317 = 10;
	array_number_t s = storage_alloc(size317);
	array_print(dum);
	array_print(dum);
	storage_free(s, size317);
	;
	return ;
}

void TOP_LEVEL_ccodegentests_valloc_cps_feature2(array_number_t dum) {
	card_t size323 = 10;
	array_number_t s = storage_alloc(size323);
	card_t size322 = 10;
	array_number_t s2 = storage_alloc(size322);
	array_print(dum);
	array_print(dum);
	storage_free(s2, size322);
	;
	storage_free(s, size323);
	;
	return ;
}

number_t TOP_LEVEL_ccodegentests_numSum(number_t n) {
	number_t ite324 = 0;
	if((n) == (0)) {
		
		ite324 = 0;;
	} else {
		
		ite324 = (TOP_LEVEL_ccodegentests_numSum((n) - (1))) + (n);;
	}
	return ite324;
}
#endif
