#ifndef __CCODEGENTESTS_H__ 
#define __CCODEGENTESTS_H__ 
#include "runtime/fsharp.h"
#include <stdio.h>
#include <math.h>

array_array_number_t ccodegentests_closure_bug1(array_array_number_t m1, array_array_number_t m2) {
	array_array_number_t macroDef284 = (array_array_number_t)malloc(sizeof(int) * 2);
	macroDef284->length=10;
	macroDef284->arr = (array_number_t*)malloc(sizeof(array_number_t) * 10);
		for(int i = 0; i < macroDef284->length; i++){
			array_number_t macroDef283 = (array_number_t)malloc(sizeof(int) * 2);
	macroDef283->length=20;
	macroDef283->arr = (number_t*)malloc(sizeof(number_t) * 20);
		for(int j = 0; j < macroDef283->length; j++){
			
			macroDef283->arr[j] = (double)(j);
		}
			macroDef284->arr[i] = macroDef283;
		}
	return macroDef284;
}

array_array_number_t ccodegentests_closure_bug2(array_array_number_t m1, array_array_number_t m2) {
	array_array_number_t macroDef286 = (array_array_number_t)malloc(sizeof(int) * 2);
	macroDef286->length=10;
	macroDef286->arr = (array_number_t*)malloc(sizeof(array_number_t) * 10);
		for(int i = 0; i < macroDef286->length; i++){
			array_number_t macroDef285 = (array_number_t)malloc(sizeof(int) * 2);
	macroDef285->length=20;
	macroDef285->arr = (number_t*)malloc(sizeof(number_t) * 20);
		for(int j = 0; j < macroDef285->length; j++){
			
			macroDef285->arr[j] = (double)((i) + (j));
		}
			macroDef286->arr[i] = macroDef285;
		}
	return macroDef286;
}

array_array_number_t ccodegentests_closure_bug3(array_array_number_t m1, array_array_number_t m2) {
	number_t n = 3;
	array_array_number_t macroDef288 = (array_array_number_t)malloc(sizeof(int) * 2);
	macroDef288->length=10;
	macroDef288->arr = (array_number_t*)malloc(sizeof(array_number_t) * 10);
		for(int i = 0; i < macroDef288->length; i++){
			array_number_t macroDef287 = (array_number_t)malloc(sizeof(int) * 2);
	macroDef287->length=20;
	macroDef287->arr = (number_t*)malloc(sizeof(number_t) * 20);
		for(int j = 0; j < macroDef287->length; j++){
			
			macroDef287->arr[j] = ((double)((i) + (j))) * (n);
		}
			macroDef288->arr[i] = macroDef287;
		}
	return macroDef288;
}

void ccodegentests_valloc_cps_feature1(array_number_t dum) {
	array_number_t s = vector_alloc(10);
	array_print(dum);
	array_print(dum);
	free(s);
	;
	return ;
}

void ccodegentests_valloc_cps_feature2(array_number_t dum) {
	array_number_t s = vector_alloc(10);
	array_number_t s2 = vector_alloc(10);
	array_print(dum);
	array_print(dum);
	free(s2);
	;
	free(s);
	;
	return ;
}
#endif
