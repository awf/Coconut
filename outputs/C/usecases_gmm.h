#ifndef __USECASES_GMM_H__ 
#define __USECASES_GMM_H__ 
#include "../../Runtime/C/fsharp.h"
#include <stdio.h>
#include <math.h>
#include "linalg.h"
typedef struct env_t_293 {
	number_t mx;
} env_t_293;
env_t_293 make_env_t_293(number_t mx) {
	env_t_293 env;
	env.mx = mx;
	return env;
}

value_t lambda293(env_t_293* env290, number_t x) {
	number_t mx289 = env290->mx;
	value_t res;
	res.number_t_value = exp((x) - (mx289));
	return res;
}
number_t TOP_LEVEL_usecases_gmm_logsumexp(array_number_t arr) {
	number_t mx = TOP_LEVEL_linalg_vectorMax(arr);
	env_t_293 env_t_293_value = make_env_t_293(mx); closure_t closure292 = make_closure(lambda293, &env_t_293_value);
	number_t semx = TOP_LEVEL_linalg_vectorSum(TOP_LEVEL_linalg_vectorMap(closure292, arr));
	return (log(semx)) + (mx);
}

index_t TOP_LEVEL_usecases_gmm_tri(index_t n) {
	
	return ((n) * ((n) + (1))) / (2);
}

array_number_t TOP_LEVEL_usecases_gmm_Qtimesv(array_number_t q, array_number_t l, array_number_t v) {
	card_t macroDef294 = v->length;
	array_number_t macroDef297 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef297->length=macroDef294;
	macroDef297->arr = (number_t*)storage_alloc(sizeof(number_t) * macroDef294);
		for(int i = 0; i < macroDef297->length; i++){
			index_t tis = TOP_LEVEL_usecases_gmm_tri((i) - (1));
			card_t macroDef295 = l->length;
			number_t macroDef296 = 0;
	for(int idx = 0; idx < macroDef295; idx++){
		index_t j = (idx) - (tis);
		bool_t isInRange = 0;
	if((j) >= (0)) {
		
		isInRange = (j) < (i);;
	} else {
		
		isInRange = false;;
	}
		number_t ite298 = 0;
	if(isInRange) {
		
		ite298 = (macroDef296) + ((l->arr[idx]) * (v->arr[j]));;
	} else {
		
		ite298 = macroDef296;;
	}
		macroDef296 = ite298;;
	}
			number_t sum = macroDef296;
			macroDef297->arr[i] = (sum) + ((exp(q->arr[i])) * (v->arr[i]));;
		}
	return macroDef297;
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
typedef empty_env_t env_t_306;


value_t lambda306(env_t_306* env302, number_t value) {
	
	value_t res;
	res.number_t_value = exp(value);
	return res;
}
number_t TOP_LEVEL_usecases_gmm_gmm_objective(array_array_number_t x, array_number_t alphas, array_array_number_t means, array_array_number_t qs, array_array_number_t ls, number_t wishart_gamma, number_t wishart_m) {
	card_t n = TOP_LEVEL_linalg_rows(x);
	card_t d = TOP_LEVEL_linalg_cols(x);
	card_t macroDef299 = alphas->length;
	card_t K = macroDef299;
	array_number_t macroDef301 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef301->length=n;
	macroDef301->arr = (number_t*)storage_alloc(sizeof(number_t) * n);
		for(int i = 0; i < macroDef301->length; i++){
			array_number_t macroDef300 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef300->length=K;
	macroDef300->arr = (number_t*)storage_alloc(sizeof(number_t) * K);
		for(int k = 0; k < macroDef300->length; k++){
			
			macroDef300->arr[k] = ((alphas->arr[k]) + (TOP_LEVEL_linalg_vectorSum(qs->arr[k]))) - ((0.5) * (TOP_LEVEL_linalg_sqnorm(TOP_LEVEL_usecases_gmm_Qtimesv(qs->arr[k], ls->arr[k], TOP_LEVEL_linalg_vectorSub(x->arr[i], means->arr[k])))));;
		}
			macroDef301->arr[i] = TOP_LEVEL_usecases_gmm_logsumexp(macroDef300);;
		}
	array_number_t macroDef305 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef305->length=K;
	macroDef305->arr = (number_t*)storage_alloc(sizeof(number_t) * K);
		for(int k = 0; k < macroDef305->length; k++){
			env_t_306 env_t_306_value = make_empty_env(); closure_t closure304 = make_closure(lambda306, &env_t_306_value);
			macroDef305->arr[k] = (TOP_LEVEL_linalg_sqnorm(TOP_LEVEL_linalg_vectorMap(closure304, qs->arr[k]))) + (TOP_LEVEL_linalg_sqnorm(ls->arr[k]));;
		}
	return ((TOP_LEVEL_linalg_vectorSum(macroDef301)) - (((double)((n))) * (TOP_LEVEL_usecases_gmm_logsumexp(alphas)))) + ((0.5) * (TOP_LEVEL_linalg_vectorSum(macroDef305)));
}

void TOP_LEVEL_usecases_gmm_test_gmm(array_number_t dum) {
	array_number_t a = (array_number_t)storage_alloc(sizeof(int) * 2);
	a->length=3;
	a->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	a->arr[0] = 1;
	a->arr[1] = 2;
	a->arr[2] = 3;;
	array_print(a);
	array_number_t array308 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array308->length=3;
	array308->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array308->arr[0] = 1;
	array308->arr[1] = 2;
	array308->arr[2] = 3;;
	array_number_t array309 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array309->length=3;
	array309->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array309->arr[0] = 4;
	array309->arr[1] = 5;
	array309->arr[2] = 6;;
	array_number_t array310 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array310->length=3;
	array310->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array310->arr[0] = 7;
	array310->arr[1] = 8;
	array310->arr[2] = 9;;
	array_array_number_t mat1 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	mat1->length=3;
	mat1->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * 3);
	mat1->arr[0] = array308;
	mat1->arr[1] = array309;
	mat1->arr[2] = array310;;
	matrix_print(mat1);
	return ;
}
#endif
