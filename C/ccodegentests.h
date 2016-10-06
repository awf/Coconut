#ifndef __CCODEGENTESTS_H__ 
#define __CCODEGENTESTS_H__ 
#include "runtime/fsharp.h"
#include <stdio.h>
#include <math.h>

array_array_number_t TOP_LEVEL_ccodegentests_closure_bug1(array_array_number_t m1, array_array_number_t m2) {
	array_array_number_t macroDef287 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef287->length=10;
	macroDef287->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * 10);
		for(int i = 0; i < macroDef287->length; i++){
			array_number_t macroDef286 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef286->length=20;
	macroDef286->arr = (number_t*)storage_alloc(sizeof(number_t) * 20);
		for(int j = 0; j < macroDef286->length; j++){
			
			macroDef286->arr[j] = (double)(j);;
		}
			macroDef287->arr[i] = macroDef286;;
		}
	return macroDef287;
}

array_array_number_t TOP_LEVEL_ccodegentests_closure_bug2(array_array_number_t m1, array_array_number_t m2) {
	array_array_number_t macroDef289 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef289->length=10;
	macroDef289->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * 10);
		for(int i = 0; i < macroDef289->length; i++){
			array_number_t macroDef288 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef288->length=20;
	macroDef288->arr = (number_t*)storage_alloc(sizeof(number_t) * 20);
		for(int j = 0; j < macroDef288->length; j++){
			
			macroDef288->arr[j] = (double)((i) + (j));;
		}
			macroDef289->arr[i] = macroDef288;;
		}
	return macroDef289;
}

array_array_number_t TOP_LEVEL_ccodegentests_closure_bug3(array_array_number_t m1, array_array_number_t m2) {
	number_t n = 3;
	array_array_number_t macroDef291 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef291->length=10;
	macroDef291->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * 10);
		for(int i = 0; i < macroDef291->length; i++){
			array_number_t macroDef290 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef290->length=20;
	macroDef290->arr = (number_t*)storage_alloc(sizeof(number_t) * 20);
		for(int j = 0; j < macroDef290->length; j++){
			
			macroDef290->arr[j] = ((double)((i) + (j))) * (n);;
		}
			macroDef291->arr[i] = macroDef290;;
		}
	return macroDef291;
}

void TOP_LEVEL_ccodegentests_valloc_cps_feature1(array_number_t dum) {
	card_t size295 = 10;
	array_number_t s = storage_alloc(size295);
	array_print(dum);
	array_print(dum);
	storage_free(s, size295);
	;
	return ;
}

void TOP_LEVEL_ccodegentests_valloc_cps_feature2(array_number_t dum) {
	card_t size301 = 10;
	array_number_t s = storage_alloc(size301);
	card_t size300 = 10;
	array_number_t s2 = storage_alloc(size300);
	array_print(dum);
	array_print(dum);
	storage_free(s2, size300);
	;
	storage_free(s, size301);
	;
	return ;
}

number_t TOP_LEVEL_ccodegentests_numSum(number_t n) {
	number_t ite302 = 0;
	if((n) == (0)) {
		
		ite302 = 0;;
	} else {
		
		ite302 = (TOP_LEVEL_ccodegentests_numSum((n) - (1))) + (n);;
	}
	return ite302;
}

array_number_t TOP_LEVEL_ccodegentests_letLiftingBug(number_t n, array_number_t v) {
	array_number_t macroDef305 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef305->length=10;
	macroDef305->arr = (number_t*)storage_alloc(sizeof(number_t) * 10);
		for(int i = 0; i < macroDef305->length; i++){
			card_t size306 = 10;
	array_number_t s = storage_alloc(size306);
	number_t macroDef303;
	macroDef303 = v->arr[i];;
	storage_free(s, size306);
			number_t l = macroDef303;
			card_t size307 = 10;
	array_number_t s = storage_alloc(size307);
	number_t macroDef304;
	macroDef304 = l;;
	storage_free(s, size307);
			macroDef305->arr[i] = (macroDef304) + (2);;
		}
	return macroDef305;
}
#endif
