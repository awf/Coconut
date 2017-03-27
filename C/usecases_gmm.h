#ifndef __USECASES_GMM_H__ 
#define __USECASES_GMM_H__ 
#include "runtime/fsharp.h"
#include <stdio.h>
#include <math.h>
#include "linalg.h"
typedef struct env_t_278 {
	number_t mx;
} env_t_278;
env_t_278 make_env_t_278(number_t mx) {
	env_t_278 env;
	env.mx = mx;
	return env;
}

value_t lambda278(env_t_278* env275, number_t x) {
	number_t mx274 = env275->mx;
	value_t res;
	res.number_t_value = exp((x) - (mx274));
	return res;
}
number_t TOP_LEVEL_usecases_gmm_logsumexp(array_number_t arr) {
	number_t mx = TOP_LEVEL_linalg_vectorMax(arr);
	env_t_278 env_t_278_value = make_env_t_278(mx); closure_t closure277 = make_closure(lambda278, &env_t_278_value);
	number_t semx = TOP_LEVEL_linalg_vectorSum(TOP_LEVEL_linalg_vectorMap(closure277, arr));
	return (log(semx)) + (mx);
}

index_t TOP_LEVEL_usecases_gmm_tri(index_t n) {
	
	return ((n) * ((n) + (1))) / (2);
}

array_number_t TOP_LEVEL_usecases_gmm_Qtimesv(array_number_t q, array_number_t l, array_number_t v) {
	card_t macroDef279 = v->length;
	array_number_t macroDef282 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef282->length=macroDef279;
	macroDef282->arr = (number_t*)storage_alloc(sizeof(number_t) * macroDef279);
		for(int i = 0; i < macroDef282->length; i++){
			index_t tis = TOP_LEVEL_usecases_gmm_tri((i) - (1));
			card_t macroDef280 = l->length;
			number_t macroDef281 = 0;
	for(int idx = 0; idx <= macroDef280; idx++){
		index_t j = (idx) - (tis);
		bool_t isInRange = 0;
	if((j) >= (0)) {
		
		isInRange = (j) < (i);;
	} else {
		
		isInRange = false;;
	}
		number_t ite283 = 0;
	if(isInRange) {
		
		ite283 = (macroDef281) + ((l->arr[idx]) * (v->arr[j]));;
	} else {
		
		ite283 = macroDef281;;
	}
		macroDef281 = ite283;;
	}
			number_t sum = macroDef281;
			macroDef282->arr[i] = (sum) + ((exp(q->arr[i])) * (v->arr[i]));;
		}
	return macroDef282;
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
typedef empty_env_t env_t_291;


value_t lambda291(env_t_291* env287, number_t value) {
	
	value_t res;
	res.number_t_value = exp(value);
	return res;
}
number_t TOP_LEVEL_usecases_gmm_gmm_objective(array_array_number_t x, array_number_t alphas, array_array_number_t means, array_array_number_t qs, array_array_number_t ls, number_t wishart_gamma, number_t wishart_m) {
	card_t n = TOP_LEVEL_linalg_rows(x);
	card_t d = TOP_LEVEL_linalg_cols(x);
	card_t macroDef284 = alphas->length;
	card_t K = macroDef284;
	array_number_t macroDef286 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef286->length=n;
	macroDef286->arr = (number_t*)storage_alloc(sizeof(number_t) * n);
		for(int i = 0; i < macroDef286->length; i++){
			array_number_t macroDef285 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef285->length=K;
	macroDef285->arr = (number_t*)storage_alloc(sizeof(number_t) * K);
		for(int k = 0; k < macroDef285->length; k++){
			
			macroDef285->arr[k] = ((alphas->arr[k]) + (TOP_LEVEL_linalg_vectorSum(qs->arr[k]))) - ((0.5) * (TOP_LEVEL_linalg_sqnorm(TOP_LEVEL_usecases_gmm_Qtimesv(qs->arr[k], ls->arr[k], TOP_LEVEL_linalg_vectorSub(x->arr[i], means->arr[k])))));;
		}
			macroDef286->arr[i] = TOP_LEVEL_usecases_gmm_logsumexp(macroDef285);;
		}
	array_number_t macroDef290 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef290->length=K;
	macroDef290->arr = (number_t*)storage_alloc(sizeof(number_t) * K);
		for(int k = 0; k < macroDef290->length; k++){
			env_t_291 env_t_291_value = make_empty_env(); closure_t closure289 = make_closure(lambda291, &env_t_291_value);
			macroDef290->arr[k] = (TOP_LEVEL_linalg_sqnorm(TOP_LEVEL_linalg_vectorMap(closure289, qs->arr[k]))) + (TOP_LEVEL_linalg_sqnorm(ls->arr[k]));;
		}
	return ((TOP_LEVEL_linalg_vectorSum(macroDef286)) - (((double)((n))) * (TOP_LEVEL_usecases_gmm_logsumexp(alphas)))) + ((0.5) * (TOP_LEVEL_linalg_vectorSum(macroDef290)));
}

void TOP_LEVEL_usecases_gmm_test_gmm(array_number_t dum) {
	array_number_t a = (array_number_t)storage_alloc(sizeof(int) * 2);
	a->length=3;
	a->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	a->arr[0] = 1;
	a->arr[1] = 2;
	a->arr[2] = 3;;
	array_print(a);
	array_number_t array293 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array293->length=3;
	array293->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array293->arr[0] = 1;
	array293->arr[1] = 2;
	array293->arr[2] = 3;;
	array_number_t array294 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array294->length=3;
	array294->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array294->arr[0] = 4;
	array294->arr[1] = 5;
	array294->arr[2] = 6;;
	array_number_t array295 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array295->length=3;
	array295->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array295->arr[0] = 7;
	array295->arr[1] = 8;
	array295->arr[2] = 9;;
	array_array_number_t mat1 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	mat1->length=3;
	mat1->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * 3);
	mat1->arr[0] = array293;
	mat1->arr[1] = array294;
	mat1->arr[2] = array295;;
	matrix_print(mat1);
	return ;
}
#endif
