#ifndef __CCODEGENTESTS_H__ 
#define __CCODEGENTESTS_H__ 
#include "runtime/fsharp.h"
#include <stdio.h>
#include <math.h>

array_array_number_t TOP_LEVEL_ccodegentests_closure_bug1(array_array_number_t m1, array_array_number_t m2) {
	array_array_number_t macroDef308 = (array_array_number_t)malloc(sizeof(int) * 2);
	macroDef308->length=10;
	macroDef308->arr = (array_number_t*)malloc(sizeof(array_number_t) * 10);
		for(int i = 0; i < macroDef308->length; i++){
			array_number_t macroDef307 = (array_number_t)malloc(sizeof(int) * 2);
	macroDef307->length=20;
	macroDef307->arr = (number_t*)malloc(sizeof(number_t) * 20);
		for(int j = 0; j < macroDef307->length; j++){
			
			macroDef307->arr[j] = (double)(j);
		}
			macroDef308->arr[i] = macroDef307;
		}
	return macroDef308;
}

array_array_number_t TOP_LEVEL_ccodegentests_closure_bug2(array_array_number_t m1, array_array_number_t m2) {
	array_array_number_t macroDef310 = (array_array_number_t)malloc(sizeof(int) * 2);
	macroDef310->length=10;
	macroDef310->arr = (array_number_t*)malloc(sizeof(array_number_t) * 10);
		for(int i = 0; i < macroDef310->length; i++){
			array_number_t macroDef309 = (array_number_t)malloc(sizeof(int) * 2);
	macroDef309->length=20;
	macroDef309->arr = (number_t*)malloc(sizeof(number_t) * 20);
		for(int j = 0; j < macroDef309->length; j++){
			
			macroDef309->arr[j] = (double)((i) + (j));
		}
			macroDef310->arr[i] = macroDef309;
		}
	return macroDef310;
}

array_array_number_t TOP_LEVEL_ccodegentests_closure_bug3(array_array_number_t m1, array_array_number_t m2) {
	number_t n = 3;
	array_array_number_t macroDef312 = (array_array_number_t)malloc(sizeof(int) * 2);
	macroDef312->length=10;
	macroDef312->arr = (array_number_t*)malloc(sizeof(array_number_t) * 10);
		for(int i = 0; i < macroDef312->length; i++){
			array_number_t macroDef311 = (array_number_t)malloc(sizeof(int) * 2);
	macroDef311->length=20;
	macroDef311->arr = (number_t*)malloc(sizeof(number_t) * 20);
		for(int j = 0; j < macroDef311->length; j++){
			
			macroDef311->arr[j] = ((double)((i) + (j))) * (n);
		}
			macroDef312->arr[i] = macroDef311;
		}
	return macroDef312;
}

void TOP_LEVEL_ccodegentests_valloc_cps_feature1(array_number_t dum) {
	array_number_t s = vector_alloc(10);
	array_print(dum);
	array_print(dum);
	free(s);
	;
	return ;
}

void TOP_LEVEL_ccodegentests_valloc_cps_feature2(array_number_t dum) {
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
