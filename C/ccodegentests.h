#ifndef __CCODEGENTESTS_H__ 
#define __CCODEGENTESTS_H__ 
#include "runtime/fsharp.h"
#include <stdio.h>
#include <math.h>

array_array_number_t TOP_LEVEL_ccodegentests_closure_bug1(array_array_number_t m1, array_array_number_t m2) {
	array_array_number_t macroDef298 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef298->length=10;
	macroDef298->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * 10);
		for(int i = 0; i < macroDef298->length; i++){
			array_number_t macroDef297 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef297->length=20;
	macroDef297->arr = (number_t*)storage_alloc(sizeof(number_t) * 20);
		for(int j = 0; j < macroDef297->length; j++){
			
			macroDef297->arr[j] = (double)(j);;
		}
			macroDef298->arr[i] = macroDef297;;
		}
	return macroDef298;
}

array_array_number_t TOP_LEVEL_ccodegentests_closure_bug2(array_array_number_t m1, array_array_number_t m2) {
	array_array_number_t macroDef300 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef300->length=10;
	macroDef300->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * 10);
		for(int i = 0; i < macroDef300->length; i++){
			array_number_t macroDef299 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef299->length=20;
	macroDef299->arr = (number_t*)storage_alloc(sizeof(number_t) * 20);
		for(int j = 0; j < macroDef299->length; j++){
			
			macroDef299->arr[j] = (double)((i) + (j));;
		}
			macroDef300->arr[i] = macroDef299;;
		}
	return macroDef300;
}

array_array_number_t TOP_LEVEL_ccodegentests_closure_bug3(array_array_number_t m1, array_array_number_t m2) {
	number_t n = 3;
	array_array_number_t macroDef302 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef302->length=10;
	macroDef302->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * 10);
		for(int i = 0; i < macroDef302->length; i++){
			array_number_t macroDef301 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef301->length=20;
	macroDef301->arr = (number_t*)storage_alloc(sizeof(number_t) * 20);
		for(int j = 0; j < macroDef301->length; j++){
			
			macroDef301->arr[j] = ((double)((i) + (j))) * (n);;
		}
			macroDef302->arr[i] = macroDef301;;
		}
	return macroDef302;
}

void TOP_LEVEL_ccodegentests_valloc_cps_feature1(array_number_t dum) {
	card_t size306 = 10;
	array_number_t s = storage_alloc(size306);
	array_print(dum);
	array_print(dum);
	storage_free(s, size306);
	;
	return ;
}

void TOP_LEVEL_ccodegentests_valloc_cps_feature2(array_number_t dum) {
	card_t size312 = 10;
	array_number_t s = storage_alloc(size312);
	card_t size311 = 10;
	array_number_t s2 = storage_alloc(size311);
	array_print(dum);
	array_print(dum);
	storage_free(s2, size311);
	;
	storage_free(s, size312);
	;
	return ;
}

number_t TOP_LEVEL_ccodegentests_numSum(number_t n) {
	number_t ite313 = 0;
	if((n) == (0)) {
		
		ite313 = 0;;
	} else {
		
		ite313 = (TOP_LEVEL_ccodegentests_numSum((n) - (1))) + (n);;
	}
	return ite313;
}
#endif
