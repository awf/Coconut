#ifndef __CCODEGENTESTS_H__ 
#define __CCODEGENTESTS_H__ 
#include "runtime/fsharp.h"
#include <stdio.h>
#include <math.h>

array_array_number_t TOP_LEVEL_ccodegentests_closure_bug1(array_array_number_t m1, array_array_number_t m2) {
	array_array_number_t macroDef279 = (array_array_number_t)malloc(sizeof(int) * 2);
	macroDef279->length=10;
	macroDef279->arr = (array_number_t*)malloc(sizeof(array_number_t) * 10);
		for(int i = 0; i < macroDef279->length; i++){
			array_number_t macroDef278 = (array_number_t)malloc(sizeof(int) * 2);
	macroDef278->length=20;
	macroDef278->arr = (number_t*)malloc(sizeof(number_t) * 20);
		for(int j = 0; j < macroDef278->length; j++){
			
			macroDef278->arr[j] = (double)(j);;
		}
			macroDef279->arr[i] = macroDef278;;
		}
	return macroDef279;
}

array_array_number_t TOP_LEVEL_ccodegentests_closure_bug2(array_array_number_t m1, array_array_number_t m2) {
	array_array_number_t macroDef281 = (array_array_number_t)malloc(sizeof(int) * 2);
	macroDef281->length=10;
	macroDef281->arr = (array_number_t*)malloc(sizeof(array_number_t) * 10);
		for(int i = 0; i < macroDef281->length; i++){
			array_number_t macroDef280 = (array_number_t)malloc(sizeof(int) * 2);
	macroDef280->length=20;
	macroDef280->arr = (number_t*)malloc(sizeof(number_t) * 20);
		for(int j = 0; j < macroDef280->length; j++){
			
			macroDef280->arr[j] = (double)((i) + (j));;
		}
			macroDef281->arr[i] = macroDef280;;
		}
	return macroDef281;
}

array_array_number_t TOP_LEVEL_ccodegentests_closure_bug3(array_array_number_t m1, array_array_number_t m2) {
	number_t n = 3;
	array_array_number_t macroDef283 = (array_array_number_t)malloc(sizeof(int) * 2);
	macroDef283->length=10;
	macroDef283->arr = (array_number_t*)malloc(sizeof(array_number_t) * 10);
		for(int i = 0; i < macroDef283->length; i++){
			array_number_t macroDef282 = (array_number_t)malloc(sizeof(int) * 2);
	macroDef282->length=20;
	macroDef282->arr = (number_t*)malloc(sizeof(number_t) * 20);
		for(int j = 0; j < macroDef282->length; j++){
			
			macroDef282->arr[j] = ((double)((i) + (j))) * (n);;
		}
			macroDef283->arr[i] = macroDef282;;
		}
	return macroDef283;
}

void TOP_LEVEL_ccodegentests_valloc_cps_feature1(array_number_t dum) {
	array_number_t s = malloc(10);
	array_print(dum);
	array_print(dum);
	free(s);
	;
	return ;
}

void TOP_LEVEL_ccodegentests_valloc_cps_feature2(array_number_t dum) {
	array_number_t s = malloc(10);
	array_number_t s2 = malloc(10);
	array_print(dum);
	array_print(dum);
	free(s2);
	;
	free(s);
	;
	return ;
}
#endif
