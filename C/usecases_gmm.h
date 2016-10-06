#ifndef __USECASES_GMM_H__ 
#define __USECASES_GMM_H__ 
#include "runtime/fsharp.h"
#include <stdio.h>
#include <math.h>
#include "linalg.h"
typedef struct env_t_312 {
	number_t mx;
} env_t_312;
env_t_312 make_env_t_312(number_t mx) {
	env_t_312 env;
	env.mx = mx;
	return env;
}

value_t lambda312(env_t_312* env309, number_t x) {
	number_t mx308 = env309->mx;
	value_t res;
	res.number_t_value = exp((x) - (mx308));
	return res;
}
number_t TOP_LEVEL_usecases_gmm_logsumexp(array_number_t arr) {
	number_t mx = TOP_LEVEL_linalg_vectorMax(arr);
	env_t_312 env_t_312_value = make_env_t_312(mx); closure_t closure311 = make_closure(lambda312, &env_t_312_value);
	number_t semx = TOP_LEVEL_linalg_vectorSum(TOP_LEVEL_linalg_vectorMap(closure311, arr));
	return (log(semx)) + (mx);
}

index_t TOP_LEVEL_usecases_gmm_tri(index_t n) {
	
	return ((n) * ((n) + (1))) / (2);
}

array_number_t TOP_LEVEL_usecases_gmm_Qtimesv(array_number_t q, array_number_t l, array_number_t v) {
	card_t macroDef313 = v->length;
	array_number_t macroDef314 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef314->length=macroDef313;
	macroDef314->arr = (number_t*)storage_alloc(sizeof(number_t) * macroDef313);
		for(int i = 0; i < macroDef314->length; i++){
			array_number_t li = TOP_LEVEL_linalg_vectorSlice(i, TOP_LEVEL_usecases_gmm_tri((i) - (1)), l);
			array_number_t vi = TOP_LEVEL_linalg_vectorSlice(i, 0, v);
			macroDef314->arr[i] = (TOP_LEVEL_linalg_vectorSum(TOP_LEVEL_linalg_op_DotMultiply(li, vi))) + ((exp(q->arr[i])) * (v->arr[i]));;
		}
	return macroDef314;
}

void TOP_LEVEL_usecases_gmm_Qtimesv_test(void unitVar0) {
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
typedef empty_env_t env_t_322;


value_t lambda322(env_t_322* env317, number_t value) {
	
	value_t res;
	res.number_t_value = exp(value);
	return res;
}
number_t TOP_LEVEL_usecases_gmm_gmm_objective(array_array_number_t x, array_number_t alphas, array_array_number_t means, array_array_number_t qs, array_array_number_t ls, number_t wishart_gamma, number_t wishart_m) {
	card_t n = TOP_LEVEL_linalg_rows(x);
	card_t d = TOP_LEVEL_linalg_cols(x);
	card_t macroDef315 = alphas->length;
	card_t K = macroDef315;
	array_number_t macroDef321 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef321->length=n;
	macroDef321->arr = (number_t*)storage_alloc(sizeof(number_t) * n);
		for(int i = 0; i < macroDef321->length; i++){
			array_number_t macroDef316 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef316->length=K;
	macroDef316->arr = (number_t*)storage_alloc(sizeof(number_t) * K);
		for(int k = 0; k < macroDef316->length; k++){
			
			macroDef316->arr[k] = ((alphas->arr[k]) + (TOP_LEVEL_linalg_vectorSum(qs->arr[k]))) - ((0.5) * (TOP_LEVEL_linalg_sqnorm(TOP_LEVEL_usecases_gmm_Qtimesv(qs->arr[k], ls->arr[k], TOP_LEVEL_linalg_vectorSub(x->arr[i], means->arr[k])))));;
		}
			array_number_t macroDef320 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef320->length=K;
	macroDef320->arr = (number_t*)storage_alloc(sizeof(number_t) * K);
		for(int k = 0; k < macroDef320->length; k++){
			env_t_322 env_t_322_value = make_empty_env(); closure_t closure319 = make_closure(lambda322, &env_t_322_value);
			macroDef320->arr[k] = (TOP_LEVEL_linalg_sqnorm(TOP_LEVEL_linalg_vectorMap(closure319, qs->arr[k]))) + (TOP_LEVEL_linalg_sqnorm(ls->arr[k]));;
		}
			macroDef321->arr[i] = ((TOP_LEVEL_usecases_gmm_logsumexp(macroDef316)) - (((double)((n))) * (TOP_LEVEL_usecases_gmm_logsumexp(alphas)))) + ((0.5) * (TOP_LEVEL_linalg_vectorSum(macroDef320)));;
		}
	return TOP_LEVEL_linalg_vectorSum(macroDef321);
}

void TOP_LEVEL_usecases_gmm_test_gmm(array_number_t dum) {
	array_number_t a = (array_number_t)storage_alloc(sizeof(int) * 2);
	a->length=3;
	a->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	a->arr[0] = 1;
	a->arr[1] = 2;
	a->arr[2] = 3;;
	array_print(a);
	array_number_t array324 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array324->length=3;
	array324->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array324->arr[0] = 1;
	array324->arr[1] = 2;
	array324->arr[2] = 3;;
	array_number_t array325 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array325->length=3;
	array325->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array325->arr[0] = 4;
	array325->arr[1] = 5;
	array325->arr[2] = 6;;
	array_number_t array326 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array326->length=3;
	array326->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array326->arr[0] = 7;
	array326->arr[1] = 8;
	array326->arr[2] = 9;;
	array_array_number_t mat1 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	mat1->length=3;
	mat1->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * 3);
	mat1->arr[0] = array324;
	mat1->arr[1] = array325;
	mat1->arr[2] = array326;;
	matrix_print(mat1);
	return ;
}
#endif
