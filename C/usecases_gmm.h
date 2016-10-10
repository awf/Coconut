#ifndef __USECASES_GMM_H__ 
#define __USECASES_GMM_H__ 
#include "runtime/fsharp.h"
#include <stdio.h>
#include <math.h>
#include "linalg.h"
typedef struct env_t_292 {
	number_t mx;
} env_t_292;
env_t_292 make_env_t_292(number_t mx) {
	env_t_292 env;
	env.mx = mx;
	return env;
}

value_t lambda292(env_t_292* env289, number_t x) {
	number_t mx288 = env289->mx;
	value_t res;
	res.number_t_value = exp((x) - (mx288));
	return res;
}
number_t TOP_LEVEL_usecases_gmm_logsumexp(array_number_t arr) {
	number_t mx = TOP_LEVEL_linalg_vectorMax(arr);
	env_t_292 env_t_292_value = make_env_t_292(mx); closure_t closure291 = make_closure(lambda292, &env_t_292_value);
	number_t semx = TOP_LEVEL_linalg_vectorSum(TOP_LEVEL_linalg_vectorMap(closure291, arr));
	return (log(semx)) + (mx);
}

index_t TOP_LEVEL_usecases_gmm_tri(index_t n) {
	
	return ((n) * ((n) + (1))) / (2);
}

array_number_t TOP_LEVEL_usecases_gmm_Qtimesv(array_number_t q, array_number_t l, array_number_t v) {
	card_t macroDef293 = v->length;
	array_number_t macroDef296 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef296->length=macroDef293;
	macroDef296->arr = (number_t*)storage_alloc(sizeof(number_t) * macroDef293);
		for(int i = 0; i < macroDef296->length; i++){
			index_t tis = TOP_LEVEL_usecases_gmm_tri((i) - (1));
			card_t macroDef294 = l->length;
			number_t macroDef295 = 0;
	for(int idx = 0; idx <= macroDef294; idx++){
		index_t j = (idx) - (tis);
		bool_t isInRange = 0;
	if((j) >= (0)) {
		
		isInRange = (j) < (i);;
	} else {
		
		isInRange = false;;
	}
		number_t ite297 = 0;
	if(isInRange) {
		
		ite297 = (macroDef295) + ((l->arr[idx]) * (v->arr[j]));;
	} else {
		
		ite297 = macroDef295;;
	}
		macroDef295 = ite297;;
	}
			number_t sum = macroDef295;
			macroDef296->arr[i] = (sum) + ((exp(q->arr[i])) * (v->arr[i]));;
		}
	return macroDef296;
}

void TOP_LEVEL_usecases_gmm_Qtimesv_test(int unitVar0) {
	array_number_t q = TOP_LEVEL_linalg_vec3(0.1, -1, 0.3);
	array_number_t l = TOP_LEVEL_linalg_vec3(5, -2, 7.1);
	array_number_t v = TOP_LEVEL_linalg_vec3(1.4, -7, 3.1);
	number_t ans0 = (exp(q->arr[0])) * (v->arr[0]);
	number_t ans1 = ((l->arr[0]) * (v->arr[0])) + ((exp(q->arr[1])) * (v->arr[1]));
	number_t ans2 = (((l->arr[1]) * (v->arr[0])) + ((l->arr[2]) * (v->arr[1]))) + ((exp(q->arr[2])) * (v->arr[2]));
	array_number_t ans = TOP_LEVEL_linalg_vec3(ans0, ans1, ans2);
	array_number_t qv = TOP_LEVEL_usecases_gmm_Qtimesv(q, l, v);
	number_t nrm = TOP_LEVEL_linalg_sqnorm(TOP_LEVEL_linalg_vectorSub(qv, ans));
	return number_print(nrm);
}
typedef empty_env_t env_t_305;


value_t lambda305(env_t_305* env300, number_t value) {
	
	value_t res;
	res.number_t_value = exp(value);
	return res;
}
number_t TOP_LEVEL_usecases_gmm_gmm_objective(array_array_number_t x, array_number_t alphas, array_array_number_t means, array_array_number_t qs, array_array_number_t ls, number_t wishart_gamma, number_t wishart_m) {
	card_t n = TOP_LEVEL_linalg_rows(x);
	card_t d = TOP_LEVEL_linalg_cols(x);
	card_t macroDef298 = alphas->length;
	card_t K = macroDef298;
	array_number_t macroDef304 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef304->length=n;
	macroDef304->arr = (number_t*)storage_alloc(sizeof(number_t) * n);
		for(int i = 0; i < macroDef304->length; i++){
			array_number_t macroDef299 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef299->length=K;
	macroDef299->arr = (number_t*)storage_alloc(sizeof(number_t) * K);
		for(int k = 0; k < macroDef299->length; k++){
			
			macroDef299->arr[k] = ((alphas->arr[k]) + (TOP_LEVEL_linalg_vectorSum(qs->arr[k]))) - ((0.5) * (TOP_LEVEL_linalg_sqnorm(TOP_LEVEL_usecases_gmm_Qtimesv(qs->arr[k], ls->arr[k], TOP_LEVEL_linalg_vectorSub(x->arr[i], means->arr[k])))));;
		}
			array_number_t macroDef303 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef303->length=K;
	macroDef303->arr = (number_t*)storage_alloc(sizeof(number_t) * K);
		for(int k = 0; k < macroDef303->length; k++){
			env_t_305 env_t_305_value = make_empty_env(); closure_t closure302 = make_closure(lambda305, &env_t_305_value);
			macroDef303->arr[k] = (TOP_LEVEL_linalg_sqnorm(TOP_LEVEL_linalg_vectorMap(closure302, qs->arr[k]))) + (TOP_LEVEL_linalg_sqnorm(ls->arr[k]));;
		}
			macroDef304->arr[i] = ((TOP_LEVEL_usecases_gmm_logsumexp(macroDef299)) - (((double)((n))) * (TOP_LEVEL_usecases_gmm_logsumexp(alphas)))) + ((0.5) * (TOP_LEVEL_linalg_vectorSum(macroDef303)));;
		}
	return TOP_LEVEL_linalg_vectorSum(macroDef304);
}

void TOP_LEVEL_usecases_gmm_test_gmm(array_number_t dum) {
	array_number_t a = (array_number_t)storage_alloc(sizeof(int) * 2);
	a->length=3;
	a->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	a->arr[0] = 1;
	a->arr[1] = 2;
	a->arr[2] = 3;;
	array_print(a);
	array_number_t array307 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array307->length=3;
	array307->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array307->arr[0] = 1;
	array307->arr[1] = 2;
	array307->arr[2] = 3;;
	array_number_t array308 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array308->length=3;
	array308->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array308->arr[0] = 4;
	array308->arr[1] = 5;
	array308->arr[2] = 6;;
	array_number_t array309 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array309->length=3;
	array309->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array309->arr[0] = 7;
	array309->arr[1] = 8;
	array309->arr[2] = 9;;
	array_array_number_t mat1 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	mat1->length=3;
	mat1->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * 3);
	mat1->arr[0] = array307;
	mat1->arr[1] = array308;
	mat1->arr[2] = array309;;
	matrix_print(mat1);
	return ;
}
#endif
