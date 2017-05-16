#ifndef __CCODEGENTESTS_H__ 
#define __CCODEGENTESTS_H__ 
#include "../../Runtime/C/fsharp.h"
#include <stdio.h>
#include <math.h>

array_array_number_t TOP_LEVEL_ccodegentests_closure_bug1(array_array_number_t m1, array_array_number_t m2) {
	array_array_number_t macroDef313 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef313->length=10;
	macroDef313->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * 10);
		for(int i = 0; i < macroDef313->length; i++){
			array_number_t macroDef312 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef312->length=20;
	macroDef312->arr = (number_t*)storage_alloc(sizeof(number_t) * 20);
		for(int j = 0; j < macroDef312->length; j++){
			
			macroDef312->arr[j] = (double)(j);;
		}
			macroDef313->arr[i] = macroDef312;;
		}
	return macroDef313;
}

array_array_number_t TOP_LEVEL_ccodegentests_closure_bug2(array_array_number_t m1, array_array_number_t m2) {
	array_array_number_t macroDef315 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef315->length=10;
	macroDef315->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * 10);
		for(int i = 0; i < macroDef315->length; i++){
			array_number_t macroDef314 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef314->length=20;
	macroDef314->arr = (number_t*)storage_alloc(sizeof(number_t) * 20);
		for(int j = 0; j < macroDef314->length; j++){
			
			macroDef314->arr[j] = (double)((i) + (j));;
		}
			macroDef315->arr[i] = macroDef314;;
		}
	return macroDef315;
}

array_array_number_t TOP_LEVEL_ccodegentests_closure_bug3(array_array_number_t m1, array_array_number_t m2) {
	number_t n = 3;
	array_array_number_t macroDef317 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef317->length=10;
	macroDef317->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * 10);
		for(int i = 0; i < macroDef317->length; i++){
			array_number_t macroDef316 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef316->length=20;
	macroDef316->arr = (number_t*)storage_alloc(sizeof(number_t) * 20);
		for(int j = 0; j < macroDef316->length; j++){
			
			macroDef316->arr[j] = ((double)((i) + (j))) * (n);;
		}
			macroDef317->arr[i] = macroDef316;;
		}
	return macroDef317;
}

void TOP_LEVEL_ccodegentests_valloc_cps_feature1(array_number_t dum) {
	card_t size321 = 10;
	array_number_t s = storage_alloc(size321);
	array_print(dum);
	array_print(dum);
	storage_free(s, size321);
	;
	return ;
}

void TOP_LEVEL_ccodegentests_valloc_cps_feature2(array_number_t dum) {
	card_t size327 = 10;
	array_number_t s = storage_alloc(size327);
	card_t size326 = 10;
	array_number_t s2 = storage_alloc(size326);
	array_print(dum);
	array_print(dum);
	storage_free(s2, size326);
	;
	storage_free(s, size327);
	;
	return ;
}

number_t TOP_LEVEL_ccodegentests_numSum(number_t n) {
	number_t ite328 = 0;
	if((n) == (0)) {
		
		ite328 = 0;;
	} else {
		
		ite328 = (TOP_LEVEL_ccodegentests_numSum((n) - (1))) + (n);;
	}
	return ite328;
}
#endif
