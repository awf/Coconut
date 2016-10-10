#ifndef __CCODEGENTESTS_H__ 
#define __CCODEGENTESTS_H__ 
#include "runtime/fsharp.h"
#include <stdio.h>
#include <math.h>

array_array_number_t TOP_LEVEL_ccodegentests_closure_bug1(array_array_number_t m1, array_array_number_t m2) {
	array_array_number_t macroDef312 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef312->length=10;
	macroDef312->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * 10);
		for(int i = 0; i < macroDef312->length; i++){
			array_number_t macroDef311 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef311->length=20;
	macroDef311->arr = (number_t*)storage_alloc(sizeof(number_t) * 20);
		for(int j = 0; j < macroDef311->length; j++){
			
			macroDef311->arr[j] = (double)(j);;
		}
			macroDef312->arr[i] = macroDef311;;
		}
	return macroDef312;
}

array_array_number_t TOP_LEVEL_ccodegentests_closure_bug2(array_array_number_t m1, array_array_number_t m2) {
	array_array_number_t macroDef314 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef314->length=10;
	macroDef314->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * 10);
		for(int i = 0; i < macroDef314->length; i++){
			array_number_t macroDef313 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef313->length=20;
	macroDef313->arr = (number_t*)storage_alloc(sizeof(number_t) * 20);
		for(int j = 0; j < macroDef313->length; j++){
			
			macroDef313->arr[j] = (double)((i) + (j));;
		}
			macroDef314->arr[i] = macroDef313;;
		}
	return macroDef314;
}

array_array_number_t TOP_LEVEL_ccodegentests_closure_bug3(array_array_number_t m1, array_array_number_t m2) {
	number_t n = 3;
	array_array_number_t macroDef316 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef316->length=10;
	macroDef316->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * 10);
		for(int i = 0; i < macroDef316->length; i++){
			array_number_t macroDef315 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef315->length=20;
	macroDef315->arr = (number_t*)storage_alloc(sizeof(number_t) * 20);
		for(int j = 0; j < macroDef315->length; j++){
			
			macroDef315->arr[j] = ((double)((i) + (j))) * (n);;
		}
			macroDef316->arr[i] = macroDef315;;
		}
	return macroDef316;
}

void TOP_LEVEL_ccodegentests_valloc_cps_feature1(array_number_t dum) {
	card_t size320 = 10;
	array_number_t s = storage_alloc(size320);
	array_print(dum);
	array_print(dum);
	storage_free(s, size320);
	;
	return ;
}

void TOP_LEVEL_ccodegentests_valloc_cps_feature2(array_number_t dum) {
	card_t size326 = 10;
	array_number_t s = storage_alloc(size326);
	card_t size325 = 10;
	array_number_t s2 = storage_alloc(size325);
	array_print(dum);
	array_print(dum);
	storage_free(s2, size325);
	;
	storage_free(s, size326);
	;
	return ;
}

number_t TOP_LEVEL_ccodegentests_numSum(number_t n) {
	number_t ite327 = 0;
	if((n) == (0)) {
		
		ite327 = 0;;
	} else {
		
		ite327 = (TOP_LEVEL_ccodegentests_numSum((n) - (1))) + (n);;
	}
	return ite327;
}
#endif
