#ifndef __CCODEGENTESTS_H__ 
#define __CCODEGENTESTS_H__ 
#include "runtime/fsharp.h"
#include <stdio.h>
#include <math.h>

array_array_number_t TOP_LEVEL_ccodegentests_closure_bug1(array_array_number_t m1, array_array_number_t m2) {
	array_array_number_t macroDef289 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef289->length=10;
	macroDef289->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * 10);
		for(int i = 0; i < macroDef289->length; i++){
			array_number_t macroDef288 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef288->length=20;
	macroDef288->arr = (number_t*)storage_alloc(sizeof(number_t) * 20);
		for(int j = 0; j < macroDef288->length; j++){
			
			macroDef288->arr[j] = (double)(j);;
		}
			macroDef289->arr[i] = macroDef288;;
		}
	return macroDef289;
}

array_array_number_t TOP_LEVEL_ccodegentests_closure_bug2(array_array_number_t m1, array_array_number_t m2) {
	array_array_number_t macroDef291 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef291->length=10;
	macroDef291->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * 10);
		for(int i = 0; i < macroDef291->length; i++){
			array_number_t macroDef290 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef290->length=20;
	macroDef290->arr = (number_t*)storage_alloc(sizeof(number_t) * 20);
		for(int j = 0; j < macroDef290->length; j++){
			
			macroDef290->arr[j] = (double)((i) + (j));;
		}
			macroDef291->arr[i] = macroDef290;;
		}
	return macroDef291;
}

array_array_number_t TOP_LEVEL_ccodegentests_closure_bug3(array_array_number_t m1, array_array_number_t m2) {
	number_t n = 3;
	array_array_number_t macroDef293 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef293->length=10;
	macroDef293->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * 10);
		for(int i = 0; i < macroDef293->length; i++){
			array_number_t macroDef292 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef292->length=20;
	macroDef292->arr = (number_t*)storage_alloc(sizeof(number_t) * 20);
		for(int j = 0; j < macroDef292->length; j++){
			
			macroDef292->arr[j] = ((double)((i) + (j))) * (n);;
		}
			macroDef293->arr[i] = macroDef292;;
		}
	return macroDef293;
}

void TOP_LEVEL_ccodegentests_valloc_cps_feature1(array_number_t dum) {
	card_t size297 = 10;
	array_number_t s = storage_alloc(size297);
	array_print(dum);
	array_print(dum);
	storage_free(s, size297);
	;
	return ;
}

void TOP_LEVEL_ccodegentests_valloc_cps_feature2(array_number_t dum) {
	card_t size303 = 10;
	array_number_t s = storage_alloc(size303);
	card_t size302 = 10;
	array_number_t s2 = storage_alloc(size302);
	array_print(dum);
	array_print(dum);
	storage_free(s2, size302);
	;
	storage_free(s, size303);
	;
	return ;
}

number_t TOP_LEVEL_ccodegentests_numSum(number_t n) {
	number_t ite304 = 0;
	if((n) == (0)) {
		
		ite304 = 0;;
	} else {
		
		ite304 = (TOP_LEVEL_ccodegentests_numSum((n) - (1))) + (n);;
	}
	return ite304;
}
#endif
