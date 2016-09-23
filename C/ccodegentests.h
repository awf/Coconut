#ifndef __CCODEGENTESTS_H__ 
#define __CCODEGENTESTS_H__ 
#include "runtime/fsharp.h"
#include <stdio.h>
#include <math.h>

array_array_number_t TOP_LEVEL_ccodegentests_closure_bug1(array_array_number_t m1, array_array_number_t m2) {
	array_array_number_t macroDef282 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef282->length=10;
	macroDef282->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * 10);
		for(int i = 0; i < macroDef282->length; i++){
			array_number_t macroDef281 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef281->length=20;
	macroDef281->arr = (number_t*)storage_alloc(sizeof(number_t) * 20);
		for(int j = 0; j < macroDef281->length; j++){
			
			macroDef281->arr[j] = (double)(j);;
		}
			macroDef282->arr[i] = macroDef281;;
		}
	return macroDef282;
}

array_array_number_t TOP_LEVEL_ccodegentests_closure_bug2(array_array_number_t m1, array_array_number_t m2) {
	array_array_number_t macroDef284 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef284->length=10;
	macroDef284->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * 10);
		for(int i = 0; i < macroDef284->length; i++){
			array_number_t macroDef283 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef283->length=20;
	macroDef283->arr = (number_t*)storage_alloc(sizeof(number_t) * 20);
		for(int j = 0; j < macroDef283->length; j++){
			
			macroDef283->arr[j] = (double)((i) + (j));;
		}
			macroDef284->arr[i] = macroDef283;;
		}
	return macroDef284;
}

array_array_number_t TOP_LEVEL_ccodegentests_closure_bug3(array_array_number_t m1, array_array_number_t m2) {
	number_t n = 3;
	array_array_number_t macroDef286 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef286->length=10;
	macroDef286->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * 10);
		for(int i = 0; i < macroDef286->length; i++){
			array_number_t macroDef285 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef285->length=20;
	macroDef285->arr = (number_t*)storage_alloc(sizeof(number_t) * 20);
		for(int j = 0; j < macroDef285->length; j++){
			
			macroDef285->arr[j] = ((double)((i) + (j))) * (n);;
		}
			macroDef286->arr[i] = macroDef285;;
		}
	return macroDef286;
}

void TOP_LEVEL_ccodegentests_valloc_cps_feature1(array_number_t dum) {
	card_t size290 = 10;
	array_number_t s = storage_alloc(size290);
	array_print(dum);
	array_print(dum);
	storage_free(s, size290);
	;
	return ;
}

void TOP_LEVEL_ccodegentests_valloc_cps_feature2(array_number_t dum) {
	card_t size296 = 10;
	array_number_t s = storage_alloc(size296);
	card_t size295 = 10;
	array_number_t s2 = storage_alloc(size295);
	array_print(dum);
	array_print(dum);
	storage_free(s2, size295);
	;
	storage_free(s, size296);
	;
	return ;
}

number_t TOP_LEVEL_ccodegentests_numSum(number_t n) {
	number_t ite297 = 0;
	if((n) == (0)) {
		
		ite297 = 0;;
	} else {
		
		ite297 = (TOP_LEVEL_ccodegentests_numSum((n) - (1))) + (n);;
	}
	return ite297;
}
#endif
