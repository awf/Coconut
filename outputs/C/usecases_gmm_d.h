#ifndef __USECASES_GMM_D_H__ 
#define __USECASES_GMM_D_H__ 
#include "../../Runtime/C/fsharp.h"
#include <stdio.h>
#include <math.h>
#include "usecases_gmm.h"
#include "linalg_d.h"
typedef struct env_t_1206 {
	number_t mx;
} env_t_1206;
env_t_1206 make_env_t_1206(number_t mx) {
	env_t_1206 env;
	env.mx = mx;
	return env;
}

value_t lambda1206(env_t_1206* env1190, number_t x) {
	number_t mx1189 = env1190->mx;
	value_t res;
	res.number_t_value = exp((x) - (mx1189));
	return res;
}
typedef struct env_t_1207 {
	number_t mx;
} env_t_1207;
env_t_1207 make_env_t_1207(number_t mx) {
	env_t_1207 env;
	env.mx = mx;
	return env;
}

value_t lambda1207(env_t_1207* env1194, number_t x) {
	number_t mx1193 = env1194->mx;
	value_t res;
	res.number_t_value = exp((x) - (mx1193));
	return res;
}
typedef struct env_t_1208 {
	number_t mx;
} env_t_1208;
env_t_1208 make_env_t_1208(number_t mx) {
	env_t_1208 env;
	env.mx = mx;
	return env;
}

value_t lambda1208(env_t_1208* env1198, number_t x) {
	number_t mx1197 = env1198->mx;
	value_t res;
	res.number_t_value = exp((x) - (mx1197));
	return res;
}
typedef struct env_t_1209 {
	number_t mx_d;
	number_t mx;
} env_t_1209;
env_t_1209 make_env_t_1209(number_t mx_d,number_t mx) {
	env_t_1209 env;
	env.mx_d = mx_d;
	env.mx = mx;
	return env;
}

value_t lambda1209(env_t_1209* env1203, number_t x, number_t x_d) {
	number_t mx_d1202 = env1203->mx_d;
	number_t mx1201 = env1203->mx;
	value_t res;
	res.number_t_value = ((x_d) - (mx_d1202)) * (exp((x) - (mx1201)));
	return res;
}
number_t TOP_LEVEL_usecases_gmm_logsumexp_d(array_number_t arr, array_number_t arr_d) {
	number_t mx = TOP_LEVEL_linalg_vectorMax(arr);
	number_t mx_d = TOP_LEVEL_linalg_vectorMax_d(arr, arr_d);
	env_t_1206 env_t_1206_value = make_env_t_1206(mx); closure_t closure1192 = make_closure(lambda1206, &env_t_1206_value);
	number_t semx = TOP_LEVEL_linalg_vectorSum(TOP_LEVEL_linalg_vectorMap(closure1192, arr));
	env_t_1207 env_t_1207_value = make_env_t_1207(mx); closure_t closure1196 = make_closure(lambda1207, &env_t_1207_value);
	env_t_1208 env_t_1208_value = make_env_t_1208(mx); closure_t closure1200 = make_closure(lambda1208, &env_t_1208_value);
	env_t_1209 env_t_1209_value = make_env_t_1209(mx_d,mx); closure_t closure1205 = make_closure(lambda1209, &env_t_1209_value);
	number_t semx_d = TOP_LEVEL_linalg_vectorSum_d(TOP_LEVEL_linalg_vectorMap(closure1196, arr), TOP_LEVEL_linalg_vectorMap_d(closure1200, arr, closure1205, arr_d));
	return ((semx_d) / (semx)) + (mx_d);
}

index_t TOP_LEVEL_usecases_gmm_tri_d(index_t n, index_t n_d) {
	
	return 0;
}

array_number_t TOP_LEVEL_usecases_gmm_Qtimesv_d(array_number_t q, array_number_t l, array_number_t v, array_number_t q_d, array_number_t l_d, array_number_t v_d) {
	card_t macroDef1212 = v->length;
	array_number_t macroDef1217 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1217->length=macroDef1212;
	macroDef1217->arr = (number_t*)storage_alloc(sizeof(number_t) * macroDef1212);
		for(int i = 0; i < macroDef1217->length; i++){
			index_t tis = TOP_LEVEL_usecases_gmm_tri((i) - (1));
			index_t tis_d = 0;
			card_t macroDef1213 = l->length;
			number_t macroDef1214 = 0;
	for(int idx = 0; idx < macroDef1213; idx++){
		index_t j = (idx) - (tis);
		bool_t isInRange = 0;
	if((j) >= (0)) {
		
		isInRange = (j) < (i);;
	} else {
		
		isInRange = false;;
	}
		number_t ite1218 = 0;
	if(isInRange) {
		
		ite1218 = (macroDef1214) + ((l->arr[idx]) * (v->arr[j]));;
	} else {
		
		ite1218 = macroDef1214;;
	}
		macroDef1214 = ite1218;;
	}
			number_t sum = macroDef1214;
			card_t macroDef1215 = l->length;
			tuple_number_t_number_t macroDef1216 = pair(0, 0);
	for(int idx = 0; idx < macroDef1215; idx++){
		number_t acc = macroDef1216._1;
		number_t acc_d = macroDef1216._2;
		index_t j = (idx) - (tis);
		bool_t isInRange = 0;
	if((j) >= (0)) {
		
		isInRange = (j) < (i);;
	} else {
		
		isInRange = false;;
	}
		number_t ite1219 = 0;
	if(isInRange) {
		
		ite1219 = (acc) + ((l->arr[idx]) * (v->arr[j]));;
	} else {
		
		ite1219 = acc;;
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
		number_t ite1220 = 0;
	if(isInRange0) {
		
		ite1220 = (acc_d) + (((l_d->arr[idx]) * (v->arr[j0])) + ((l->arr[idx]) * (v_d->arr[j0])));;
	} else {
		
		ite1220 = acc_d;;
	}
		macroDef1216 = pair(ite1219, ite1220);;
	}
			number_t sum_d = macroDef1216._2;
			macroDef1217->arr[i] = (sum_d) + ((((q_d->arr[i]) * (exp(q->arr[i]))) * (v->arr[i])) + ((exp(q->arr[i])) * (v_d->arr[i])));;
		}
	return macroDef1217;
}

void TOP_LEVEL_usecases_gmm_Qtimesv_test_d(int unitVar0, int unitVar0_d) {
	
	return ;
}
typedef empty_env_t env_t_1246;


value_t lambda1246(env_t_1246* env1228, number_t value) {
	
	value_t res;
	res.number_t_value = exp(value);
	return res;
}
typedef empty_env_t env_t_1247;


value_t lambda1247(env_t_1247* env1232, number_t value) {
	
	value_t res;
	res.number_t_value = exp(value);
	return res;
}
typedef empty_env_t env_t_1248;


value_t lambda1248(env_t_1248* env1236, number_t value) {
	
	value_t res;
	res.number_t_value = exp(value);
	return res;
}
typedef empty_env_t env_t_1249;


value_t lambda1249(env_t_1249* env1239, number_t value) {
	
	value_t res;
	res.number_t_value = exp(value);
	return res;
}
typedef empty_env_t env_t_1250;


value_t lambda1250(env_t_1250* env1242, number_t value, number_t value_d) {
	
	value_t res;
	res.number_t_value = (value_d) * (exp(value));
	return res;
}
number_t TOP_LEVEL_usecases_gmm_gmm_objective_d(array_array_number_t x, array_number_t alphas, array_array_number_t means, array_array_number_t qs, array_array_number_t ls, number_t wishart_gamma, number_t wishart_m, array_array_number_t x_d, array_number_t alphas_d, array_array_number_t means_d, array_array_number_t qs_d, array_array_number_t ls_d, number_t wishart_gamma_d, number_t wishart_m_d) {
	card_t n = TOP_LEVEL_linalg_rows(x);
	card_t n_d = TOP_LEVEL_linalg_rows(x);
	card_t d = TOP_LEVEL_linalg_cols(x);
	card_t d_d = TOP_LEVEL_linalg_cols(x);
	card_t macroDef1221 = alphas->length;
	card_t K = macroDef1221;
	card_t macroDef1222 = alphas->length;
	card_t K_d = macroDef1222;
	array_number_t macroDef1224 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1224->length=n;
	macroDef1224->arr = (number_t*)storage_alloc(sizeof(number_t) * n);
		for(int i = 0; i < macroDef1224->length; i++){
			array_number_t macroDef1223 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1223->length=K;
	macroDef1223->arr = (number_t*)storage_alloc(sizeof(number_t) * K);
		for(int k = 0; k < macroDef1223->length; k++){
			
			macroDef1223->arr[k] = ((alphas->arr[k]) + (TOP_LEVEL_linalg_vectorSum(qs->arr[k]))) - ((0.5) * (TOP_LEVEL_linalg_sqnorm(TOP_LEVEL_usecases_gmm_Qtimesv(qs->arr[k], ls->arr[k], TOP_LEVEL_linalg_vectorSub(x->arr[i], means->arr[k])))));;
		}
			macroDef1224->arr[i] = TOP_LEVEL_usecases_gmm_logsumexp(macroDef1223);;
		}
	array_number_t macroDef1227 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1227->length=n;
	macroDef1227->arr = (number_t*)storage_alloc(sizeof(number_t) * n);
		for(int i = 0; i < macroDef1227->length; i++){
			array_number_t macroDef1225 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1225->length=K;
	macroDef1225->arr = (number_t*)storage_alloc(sizeof(number_t) * K);
		for(int k = 0; k < macroDef1225->length; k++){
			
			macroDef1225->arr[k] = ((alphas->arr[k]) + (TOP_LEVEL_linalg_vectorSum(qs->arr[k]))) - ((0.5) * (TOP_LEVEL_linalg_sqnorm(TOP_LEVEL_usecases_gmm_Qtimesv(qs->arr[k], ls->arr[k], TOP_LEVEL_linalg_vectorSub(x->arr[i], means->arr[k])))));;
		}
			array_number_t macroDef1226 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1226->length=K;
	macroDef1226->arr = (number_t*)storage_alloc(sizeof(number_t) * K);
		for(int k = 0; k < macroDef1226->length; k++){
			
			macroDef1226->arr[k] = ((alphas_d->arr[k]) + (TOP_LEVEL_linalg_vectorSum_d(qs->arr[k], qs_d->arr[k]))) - (((0) * (TOP_LEVEL_linalg_sqnorm(TOP_LEVEL_usecases_gmm_Qtimesv(qs->arr[k], ls->arr[k], TOP_LEVEL_linalg_vectorSub(x->arr[i], means->arr[k]))))) + ((0.5) * (TOP_LEVEL_linalg_sqnorm_d(TOP_LEVEL_usecases_gmm_Qtimesv(qs->arr[k], ls->arr[k], TOP_LEVEL_linalg_vectorSub(x->arr[i], means->arr[k])), TOP_LEVEL_usecases_gmm_Qtimesv_d(qs->arr[k], ls->arr[k], TOP_LEVEL_linalg_vectorSub(x->arr[i], means->arr[k]), qs_d->arr[k], ls_d->arr[k], TOP_LEVEL_linalg_vectorSub_d(x->arr[i], means->arr[k], x_d->arr[i], means_d->arr[k]))))));;
		}
			macroDef1227->arr[i] = TOP_LEVEL_usecases_gmm_logsumexp_d(macroDef1225, macroDef1226);;
		}
	array_number_t macroDef1231 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1231->length=K;
	macroDef1231->arr = (number_t*)storage_alloc(sizeof(number_t) * K);
		for(int k = 0; k < macroDef1231->length; k++){
			env_t_1246 env_t_1246_value = make_empty_env(); closure_t closure1230 = make_closure(lambda1246, &env_t_1246_value);
			macroDef1231->arr[k] = (TOP_LEVEL_linalg_sqnorm(TOP_LEVEL_linalg_vectorMap(closure1230, qs->arr[k]))) + (TOP_LEVEL_linalg_sqnorm(ls->arr[k]));;
		}
	array_number_t macroDef1235 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1235->length=K;
	macroDef1235->arr = (number_t*)storage_alloc(sizeof(number_t) * K);
		for(int k = 0; k < macroDef1235->length; k++){
			env_t_1247 env_t_1247_value = make_empty_env(); closure_t closure1234 = make_closure(lambda1247, &env_t_1247_value);
			macroDef1235->arr[k] = (TOP_LEVEL_linalg_sqnorm(TOP_LEVEL_linalg_vectorMap(closure1234, qs->arr[k]))) + (TOP_LEVEL_linalg_sqnorm(ls->arr[k]));;
		}
	array_number_t macroDef1245 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1245->length=K;
	macroDef1245->arr = (number_t*)storage_alloc(sizeof(number_t) * K);
		for(int k = 0; k < macroDef1245->length; k++){
			env_t_1248 env_t_1248_value = make_empty_env(); closure_t closure1238 = make_closure(lambda1248, &env_t_1248_value);
			env_t_1249 env_t_1249_value = make_empty_env(); closure_t closure1241 = make_closure(lambda1249, &env_t_1249_value);
			env_t_1250 env_t_1250_value = make_empty_env(); closure_t closure1244 = make_closure(lambda1250, &env_t_1250_value);
			macroDef1245->arr[k] = (TOP_LEVEL_linalg_sqnorm_d(TOP_LEVEL_linalg_vectorMap(closure1238, qs->arr[k]), TOP_LEVEL_linalg_vectorMap_d(closure1241, qs->arr[k], closure1244, qs_d->arr[k]))) + (TOP_LEVEL_linalg_sqnorm_d(ls->arr[k], ls_d->arr[k]));;
		}
	return ((TOP_LEVEL_linalg_vectorSum_d(macroDef1224, macroDef1227)) - (((0) * (TOP_LEVEL_usecases_gmm_logsumexp(alphas))) + (((double)((n))) * (TOP_LEVEL_usecases_gmm_logsumexp_d(alphas, alphas_d))))) + (((0) * (TOP_LEVEL_linalg_vectorSum(macroDef1231))) + ((0.5) * (TOP_LEVEL_linalg_vectorSum_d(macroDef1235, macroDef1245))));
}

void TOP_LEVEL_usecases_gmm_test_gmm_d(array_number_t dum, array_number_t dum_d) {
	
	return ;
}
#endif
