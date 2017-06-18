#ifndef __USECASES_GMM_D_H__ 
#define __USECASES_GMM_D_H__ 
#include "../../Runtime/C/fsharp.h"
#include <stdio.h>
#include <math.h>
#include "usecases_gmm.h"
#include "linalg_d.h"
typedef struct env_t_206 {
	number_t mx;
} env_t_206;
env_t_206 make_env_t_206(number_t mx) {
	env_t_206 env;
	env.mx = mx;
	return env;
}

value_t lambda206(env_t_206* env190, number_t x) {
	number_t mx189 = env190->mx;
	value_t res;
	res.number_t_value = exp((x) - (mx189));
	return res;
}
typedef struct env_t_207 {
	number_t mx;
} env_t_207;
env_t_207 make_env_t_207(number_t mx) {
	env_t_207 env;
	env.mx = mx;
	return env;
}

value_t lambda207(env_t_207* env194, number_t x) {
	number_t mx193 = env194->mx;
	value_t res;
	res.number_t_value = exp((x) - (mx193));
	return res;
}
typedef struct env_t_208 {
	number_t mx;
} env_t_208;
env_t_208 make_env_t_208(number_t mx) {
	env_t_208 env;
	env.mx = mx;
	return env;
}

value_t lambda208(env_t_208* env198, number_t x) {
	number_t mx197 = env198->mx;
	value_t res;
	res.number_t_value = exp((x) - (mx197));
	return res;
}
typedef struct env_t_209 {
	number_t mx_d;
	number_t mx;
} env_t_209;
env_t_209 make_env_t_209(number_t mx_d,number_t mx) {
	env_t_209 env;
	env.mx_d = mx_d;
	env.mx = mx;
	return env;
}

value_t lambda209(env_t_209* env203, number_t x, number_t x_d) {
	number_t mx_d202 = env203->mx_d;
	number_t mx201 = env203->mx;
	value_t res;
	res.number_t_value = ((x_d) - (mx_d202)) * (exp((x) - (mx201)));
	return res;
}
number_t TOP_LEVEL_usecases_gmm_logsumexp_d(array_number_t arr, array_number_t arr_d) {
	number_t mx = TOP_LEVEL_linalg_vectorMax(arr);
	number_t mx_d = TOP_LEVEL_linalg_vectorMax_d(arr, arr_d);
	env_t_206 env_t_206_value = make_env_t_206(mx); closure_t closure192 = make_closure(lambda206, &env_t_206_value);
	number_t semx = TOP_LEVEL_linalg_vectorSum(TOP_LEVEL_linalg_vectorMap(closure192, arr));
	env_t_207 env_t_207_value = make_env_t_207(mx); closure_t closure196 = make_closure(lambda207, &env_t_207_value);
	env_t_208 env_t_208_value = make_env_t_208(mx); closure_t closure200 = make_closure(lambda208, &env_t_208_value);
	env_t_209 env_t_209_value = make_env_t_209(mx_d,mx); closure_t closure205 = make_closure(lambda209, &env_t_209_value);
	number_t semx_d = TOP_LEVEL_linalg_vectorSum_d(TOP_LEVEL_linalg_vectorMap(closure196, arr), TOP_LEVEL_linalg_vectorMap_d(closure200, arr, closure205, arr_d));
	return ((semx_d) / (semx)) + (mx_d);
}

index_t TOP_LEVEL_usecases_gmm_tri_d(index_t n, index_t n_d) {
	
	return 0;
}

array_number_t TOP_LEVEL_usecases_gmm_Qtimesv_d(array_number_t q, array_number_t l, array_number_t v, array_number_t q_d, array_number_t l_d, array_number_t v_d) {
	card_t macroDef212 = v->length;
	array_number_t macroDef217 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef217->length=macroDef212;
	macroDef217->arr = (number_t*)storage_alloc(sizeof(number_t) * macroDef212);
		for(int i = 0; i < macroDef217->length; i++){
			index_t tis = TOP_LEVEL_usecases_gmm_tri((i) - (1));
			index_t tis_d = 0;
			card_t macroDef213 = l->length;
			number_t macroDef214 = 0;
	for(int idx = 0; idx < macroDef213; idx++){
		index_t j = (idx) - (tis);
		bool_t isInRange = 0;
	if((j) >= (0)) {
		
		isInRange = (j) < (i);;
	} else {
		
		isInRange = false;;
	}
		number_t ite218 = 0;
	if(isInRange) {
		
		ite218 = (macroDef214) + ((l->arr[idx]) * (v->arr[j]));;
	} else {
		
		ite218 = macroDef214;;
	}
		macroDef214 = ite218;;
	}
			number_t sum = macroDef214;
			card_t macroDef215 = l->length;
			tuple_number_t_number_t macroDef216 = pair(0, 0);
	for(int idx = 0; idx < macroDef215; idx++){
		number_t acc = macroDef216._1;
		number_t acc_d = macroDef216._2;
		index_t j = (idx) - (tis);
		bool_t isInRange = 0;
	if((j) >= (0)) {
		
		isInRange = (j) < (i);;
	} else {
		
		isInRange = false;;
	}
		number_t ite219 = 0;
	if(isInRange) {
		
		ite219 = (acc) + ((l->arr[idx]) * (v->arr[j]));;
	} else {
		
		ite219 = acc;;
	}
		index_t j0 = (idx) - (tis);
		index_t j_d = 0;
		bool_t isInRange0 = 0;
	if((j0) >= (0)) {
		
		isInRange0 = (j0) < (i);;
	} else {
		
		isInRange0 = false;;
	}
		bool_t isInRange_d = false;
		number_t ite220 = 0;
	if(isInRange0) {
		
		ite220 = (acc_d) + (((l_d->arr[idx]) * (v->arr[j0])) + ((l->arr[idx]) * (v_d->arr[j0])));;
	} else {
		
		ite220 = acc_d;;
	}
		macroDef216 = pair(ite219, ite220);;
	}
			number_t sum_d = macroDef216._2;
			macroDef217->arr[i] = (sum_d) + ((((q_d->arr[i]) * (exp(q->arr[i]))) * (v->arr[i])) + ((exp(q->arr[i])) * (v_d->arr[i])));;
		}
	return macroDef217;
}

void TOP_LEVEL_usecases_gmm_Qtimesv_test_d(int unitVar0, int unitVar0_d) {
	
	return ;
}
typedef empty_env_t env_t_246;


value_t lambda246(env_t_246* env228, number_t value) {
	
	value_t res;
	res.number_t_value = exp(value);
	return res;
}
typedef empty_env_t env_t_247;


value_t lambda247(env_t_247* env232, number_t value) {
	
	value_t res;
	res.number_t_value = exp(value);
	return res;
}
typedef empty_env_t env_t_248;


value_t lambda248(env_t_248* env236, number_t value) {
	
	value_t res;
	res.number_t_value = exp(value);
	return res;
}
typedef empty_env_t env_t_249;


value_t lambda249(env_t_249* env239, number_t value) {
	
	value_t res;
	res.number_t_value = exp(value);
	return res;
}
typedef empty_env_t env_t_250;


value_t lambda250(env_t_250* env242, number_t value, number_t value_d) {
	
	value_t res;
	res.number_t_value = (value_d) * (exp(value));
	return res;
}
number_t TOP_LEVEL_usecases_gmm_gmm_objective_d(array_array_number_t x, array_number_t alphas, array_array_number_t means, array_array_number_t qs, array_array_number_t ls, number_t wishart_gamma, number_t wishart_m, array_array_number_t x_d, array_number_t alphas_d, array_array_number_t means_d, array_array_number_t qs_d, array_array_number_t ls_d, number_t wishart_gamma_d, number_t wishart_m_d) {
	card_t n = TOP_LEVEL_linalg_rows(x);
	card_t n_d = TOP_LEVEL_linalg_rows(x);
	card_t d = TOP_LEVEL_linalg_cols(x);
	card_t d_d = TOP_LEVEL_linalg_cols(x);
	card_t macroDef221 = alphas->length;
	card_t K = macroDef221;
	card_t macroDef222 = alphas->length;
	card_t K_d = macroDef222;
	array_number_t macroDef224 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef224->length=n;
	macroDef224->arr = (number_t*)storage_alloc(sizeof(number_t) * n);
		for(int i = 0; i < macroDef224->length; i++){
			array_number_t macroDef223 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef223->length=K;
	macroDef223->arr = (number_t*)storage_alloc(sizeof(number_t) * K);
		for(int k = 0; k < macroDef223->length; k++){
			
			macroDef223->arr[k] = ((alphas->arr[k]) + (TOP_LEVEL_linalg_vectorSum(qs->arr[k]))) - ((0.5) * (TOP_LEVEL_linalg_sqnorm(TOP_LEVEL_usecases_gmm_Qtimesv(qs->arr[k], ls->arr[k], TOP_LEVEL_linalg_vectorSub(x->arr[i], means->arr[k])))));;
		}
			macroDef224->arr[i] = TOP_LEVEL_usecases_gmm_logsumexp(macroDef223);;
		}
	array_number_t macroDef227 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef227->length=n;
	macroDef227->arr = (number_t*)storage_alloc(sizeof(number_t) * n);
		for(int i = 0; i < macroDef227->length; i++){
			array_number_t macroDef225 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef225->length=K;
	macroDef225->arr = (number_t*)storage_alloc(sizeof(number_t) * K);
		for(int k = 0; k < macroDef225->length; k++){
			
			macroDef225->arr[k] = ((alphas->arr[k]) + (TOP_LEVEL_linalg_vectorSum(qs->arr[k]))) - ((0.5) * (TOP_LEVEL_linalg_sqnorm(TOP_LEVEL_usecases_gmm_Qtimesv(qs->arr[k], ls->arr[k], TOP_LEVEL_linalg_vectorSub(x->arr[i], means->arr[k])))));;
		}
			array_number_t macroDef226 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef226->length=K;
	macroDef226->arr = (number_t*)storage_alloc(sizeof(number_t) * K);
		for(int k = 0; k < macroDef226->length; k++){
			
			macroDef226->arr[k] = ((alphas_d->arr[k]) + (TOP_LEVEL_linalg_vectorSum_d(qs->arr[k], qs_d->arr[k]))) - (((0) * (TOP_LEVEL_linalg_sqnorm(TOP_LEVEL_usecases_gmm_Qtimesv(qs->arr[k], ls->arr[k], TOP_LEVEL_linalg_vectorSub(x->arr[i], means->arr[k]))))) + ((0.5) * (TOP_LEVEL_linalg_sqnorm_d(TOP_LEVEL_usecases_gmm_Qtimesv(qs->arr[k], ls->arr[k], TOP_LEVEL_linalg_vectorSub(x->arr[i], means->arr[k])), TOP_LEVEL_usecases_gmm_Qtimesv_d(qs->arr[k], ls->arr[k], TOP_LEVEL_linalg_vectorSub(x->arr[i], means->arr[k]), qs_d->arr[k], ls_d->arr[k], TOP_LEVEL_linalg_vectorSub_d(x->arr[i], means->arr[k], x_d->arr[i], means_d->arr[k]))))));;
		}
			macroDef227->arr[i] = TOP_LEVEL_usecases_gmm_logsumexp_d(macroDef225, macroDef226);;
		}
	array_number_t macroDef231 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef231->length=K;
	macroDef231->arr = (number_t*)storage_alloc(sizeof(number_t) * K);
		for(int k = 0; k < macroDef231->length; k++){
			env_t_246 env_t_246_value = make_empty_env(); closure_t closure230 = make_closure(lambda246, &env_t_246_value);
			macroDef231->arr[k] = (TOP_LEVEL_linalg_sqnorm(TOP_LEVEL_linalg_vectorMap(closure230, qs->arr[k]))) + (TOP_LEVEL_linalg_sqnorm(ls->arr[k]));;
		}
	array_number_t macroDef235 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef235->length=K;
	macroDef235->arr = (number_t*)storage_alloc(sizeof(number_t) * K);
		for(int k = 0; k < macroDef235->length; k++){
			env_t_247 env_t_247_value = make_empty_env(); closure_t closure234 = make_closure(lambda247, &env_t_247_value);
			macroDef235->arr[k] = (TOP_LEVEL_linalg_sqnorm(TOP_LEVEL_linalg_vectorMap(closure234, qs->arr[k]))) + (TOP_LEVEL_linalg_sqnorm(ls->arr[k]));;
		}
	array_number_t macroDef245 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef245->length=K;
	macroDef245->arr = (number_t*)storage_alloc(sizeof(number_t) * K);
		for(int k = 0; k < macroDef245->length; k++){
			env_t_248 env_t_248_value = make_empty_env(); closure_t closure238 = make_closure(lambda248, &env_t_248_value);
			env_t_249 env_t_249_value = make_empty_env(); closure_t closure241 = make_closure(lambda249, &env_t_249_value);
			env_t_250 env_t_250_value = make_empty_env(); closure_t closure244 = make_closure(lambda250, &env_t_250_value);
			macroDef245->arr[k] = (TOP_LEVEL_linalg_sqnorm_d(TOP_LEVEL_linalg_vectorMap(closure238, qs->arr[k]), TOP_LEVEL_linalg_vectorMap_d(closure241, qs->arr[k], closure244, qs_d->arr[k]))) + (TOP_LEVEL_linalg_sqnorm_d(ls->arr[k], ls_d->arr[k]));;
		}
	return ((TOP_LEVEL_linalg_vectorSum_d(macroDef224, macroDef227)) - (((0) * (TOP_LEVEL_usecases_gmm_logsumexp(alphas))) + (((double)((n))) * (TOP_LEVEL_usecases_gmm_logsumexp_d(alphas, alphas_d))))) + (((0) * (TOP_LEVEL_linalg_vectorSum(macroDef231))) + ((0.5) * (TOP_LEVEL_linalg_vectorSum_d(macroDef235, macroDef245))));
}

void TOP_LEVEL_usecases_gmm_test_gmm_d(array_number_t dum, array_number_t dum_d) {
	
	return ;
}
#endif
