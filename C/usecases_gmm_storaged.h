#ifndef __USECASES_GMM_STORAGED_H__ 
#define __USECASES_GMM_STORAGED_H__ 
#include "runtime/fsharp.h"
#include <stdio.h>
#include <math.h>
#include "linalg_storaged.h"

card_t TOP_LEVEL_usecases_gmm_logsumexp_shp(card_t arr_shp) {
	
	return 0;
}

typedef empty_env_t env_t_1199;


value_t lambda1199(env_t_1199* env1185, card_t x_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef struct env_t_1200 {
	number_t mx_dps;
} env_t_1200;
env_t_1200 make_env_t_1200(number_t mx_dps) {
	env_t_1200 env;
	env.mx_dps = mx_dps;
	return env;
}

value_t lambda1200(env_t_1200* env1189, storage_t stgVar1184, number_t x_dps, card_t x_shp) {
	number_t mx_dps1188 = env1189->mx_dps;
	value_t res;
	res.number_t_value = exp((x_dps) - (mx_dps1188));
	return res;
}
typedef empty_env_t env_t_1201;


value_t lambda1201(env_t_1201* env1192, card_t x_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef empty_env_t env_t_1202;


value_t lambda1202(env_t_1202* env1195, card_t x_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
number_t TOP_LEVEL_usecases_gmm_logsumexp_dps(storage_t stgVar1177, array_number_t arr_dps, card_t arr_shp) {
	card_t mx_shp = 0;
	number_t mx_dps = TOP_LEVEL_linalg_vectorMax_dps(empty_storage, arr_dps, arr_shp);
	card_t semx_shp = 0;
	env_t_1199 env_t_1199_value = make_empty_env(); closure_t closure1187 = make_closure(lambda1199, &env_t_1199_value);
	card_t size1203 = width_card_t(TOP_LEVEL_linalg_vectorMap_shp(closure1187, arr_shp));
	array_number_t stgVar1181 = storage_alloc(size1203);
	number_t macroDef1198;env_t_1200 env_t_1200_value = make_env_t_1200(mx_dps); closure_t closure1191 = make_closure(lambda1200, &env_t_1200_value);
	env_t_1201 env_t_1201_value = make_empty_env(); closure_t closure1194 = make_closure(lambda1201, &env_t_1201_value);
	env_t_1202 env_t_1202_value = make_empty_env(); closure_t closure1197 = make_closure(lambda1202, &env_t_1202_value);
	macroDef1198 = TOP_LEVEL_linalg_vectorSum_dps(empty_storage, TOP_LEVEL_linalg_vectorMap_dps(stgVar1181, closure1191, arr_dps, closure1194, arr_shp), TOP_LEVEL_linalg_vectorMap_shp(closure1197, arr_shp));;
	storage_free(stgVar1181, size1203);
	number_t semx_dps = macroDef1198;
	return (log(semx_dps)) + (mx_dps);
}

card_t TOP_LEVEL_usecases_gmm_tri_shp(card_t n_shp) {
	
	return 0;
}


index_t TOP_LEVEL_usecases_gmm_tri_dps(storage_t stgVar1204, index_t n_dps, card_t n_shp) {
	
	return ((n_dps) * ((n_dps) + (1))) / (2);
}

card_t TOP_LEVEL_usecases_gmm_Qtimesv_shp(card_t q_shp, card_t l_shp, card_t v_shp) {
	
	return v_shp;
}


array_number_t TOP_LEVEL_usecases_gmm_Qtimesv_dps(storage_t stgVar1205, array_number_t q_dps, array_number_t l_dps, array_number_t v_dps, card_t q_shp, card_t l_shp, card_t v_shp) {
	card_t macroDef1223 = v_dps->length;
	array_number_t macroDef1226 = (array_number_t)stgVar1205;
		macroDef1226->length=macroDef1223;
		macroDef1226->arr=(number_t*)(STG_OFFSET(macroDef1226, VECTOR_HEADER_BYTES));
		storage_t stgVar1207 = macroDef1226;
		for(int i_dps = 0; i_dps < macroDef1226->length; i_dps++){
			card_t tis_shp = 0;
			index_t tis_dps = TOP_LEVEL_usecases_gmm_tri_dps(empty_storage, (i_dps) - (1), 0);
			card_t sum_shp = 0;
			card_t anfvar1211_shp = l_shp;
			card_t macroDef1224 = l_dps->length;
			card_t anfvar1211_dps = macroDef1224;
			card_t anfvar1212_shp = 0;
			card_t anfvar1212_dps = 0;
			number_t macroDef1225 = 0;
	storage_t stgVar1216 = empty_storage;
	for(int idx_dps = anfvar1212_dps; idx_dps <= anfvar1211_dps; idx_dps++){
		card_t j_shp = 0;
		index_t j_dps = (idx_dps) - (tis_dps);
		card_t isInRange_shp = 0;
		bool_t isInRange_dps = 0;
	if((j_dps) >= (0)) {
		
		isInRange_dps = (j_dps) < (i_dps);;
	} else {
		
		isInRange_dps = false;;
	}
		number_t ite1227 = 0;
	if(isInRange_dps) {
		
		ite1227 = (macroDef1225) + ((l_dps->arr[idx_dps]) * (v_dps->arr[j_dps]));;
	} else {
		
		ite1227 = macroDef1225;;
	}
		macroDef1225 = ite1227;;
	}
			number_t sum_dps = macroDef1225;
			macroDef1226->arr[i_dps] = (sum_dps) + ((exp(q_dps->arr[i_dps])) * (v_dps->arr[i_dps]));;
			stgVar1207 = STG_OFFSET(stgVar1207, sizeof(number_t));
		}
	return macroDef1226;
}

card_t TOP_LEVEL_usecases_gmm_Qtimesv_test_shp(card_t unitVar0_shp) {
	
	return 0;
}


void TOP_LEVEL_usecases_gmm_Qtimesv_test_dps(storage_t stgVar1228, int unitVar0_dps, card_t unitVar0_shp) {
	card_t q_shp = TOP_LEVEL_linalg_vec3_shp(0, 0, 0);
	card_t size1279 = width_card_t(q_shp);
	array_number_t stgVar1229 = storage_alloc(size1279);
	array_number_t q_dps = TOP_LEVEL_linalg_vec3_dps(stgVar1229, 0.1, -1, 0.3, 0, 0, 0);
	card_t l_shp = TOP_LEVEL_linalg_vec3_shp(0, 0, 0);
	card_t size1278 = width_card_t(l_shp);
	array_number_t stgVar1233 = storage_alloc(size1278);
	array_number_t l_dps = TOP_LEVEL_linalg_vec3_dps(stgVar1233, 5, -2, 7.1, 0, 0, 0);
	card_t v_shp = TOP_LEVEL_linalg_vec3_shp(0, 0, 0);
	card_t size1277 = width_card_t(v_shp);
	array_number_t stgVar1237 = storage_alloc(size1277);
	array_number_t v_dps = TOP_LEVEL_linalg_vec3_dps(stgVar1237, 1.4, -7, 3.1, 0, 0, 0);
	card_t ans0_shp = 0;
	number_t ans0_dps = (exp(q_dps->arr[0])) * (v_dps->arr[0]);
	card_t ans1_shp = 0;
	number_t ans1_dps = ((l_dps->arr[0]) * (v_dps->arr[0])) + ((exp(q_dps->arr[1])) * (v_dps->arr[1]));
	card_t ans2_shp = 0;
	number_t ans2_dps = (((l_dps->arr[1]) * (v_dps->arr[0])) + ((l_dps->arr[2]) * (v_dps->arr[1]))) + ((exp(q_dps->arr[2])) * (v_dps->arr[2]));
	card_t ans_shp = TOP_LEVEL_linalg_vec3_shp(0, 0, 0);
	card_t size1276 = width_card_t(ans_shp);
	array_number_t stgVar1256 = storage_alloc(size1276);
	array_number_t ans_dps = TOP_LEVEL_linalg_vec3_dps(stgVar1256, ans0_dps, ans1_dps, ans2_dps, 0, 0, 0);
	card_t qv_shp = TOP_LEVEL_usecases_gmm_Qtimesv_shp(q_shp, l_shp, v_shp);
	card_t size1275 = width_card_t(qv_shp);
	array_number_t stgVar1260 = storage_alloc(size1275);
	array_number_t qv_dps = TOP_LEVEL_usecases_gmm_Qtimesv_dps(stgVar1260, q_dps, l_dps, v_dps, q_shp, l_shp, v_shp);
	card_t nrm_shp = 0;
	card_t size1274 = width_card_t(TOP_LEVEL_linalg_vectorSub_shp(qv_shp, ans_shp));
	array_number_t stgVar1265 = storage_alloc(size1274);
	number_t macroDef1268;
	macroDef1268 = TOP_LEVEL_linalg_sqnorm_dps(empty_storage, TOP_LEVEL_linalg_vectorSub_dps(stgVar1265, qv_dps, ans_dps, qv_shp, ans_shp), TOP_LEVEL_linalg_vectorSub_shp(qv_shp, ans_shp));;
	storage_free(stgVar1265, size1274);
	number_t nrm_dps = macroDef1268;
	number_print(nrm_dps);
	storage_free(stgVar1260, size1275);
	;
	storage_free(stgVar1256, size1276);
	;
	storage_free(stgVar1237, size1277);
	;
	storage_free(stgVar1233, size1278);
	;
	storage_free(stgVar1229, size1279);
	return ;
}

card_t TOP_LEVEL_usecases_gmm_gmm_objective_shp(matrix_shape_t x_shp, card_t alphas_shp, matrix_shape_t means_shp, matrix_shape_t qs_shp, matrix_shape_t ls_shp, card_t wishart_gamma_shp, card_t wishart_m_shp) {
	
	return 0;
}

typedef empty_env_t env_t_1354;


value_t lambda1354(env_t_1354* env1326, card_t value_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef empty_env_t env_t_1355;


value_t lambda1355(env_t_1355* env1329, storage_t stgVar1310, number_t value_dps, card_t value_shp) {
	
	value_t res;
	res.number_t_value = exp(value_dps);
	return res;
}
typedef empty_env_t env_t_1356;


value_t lambda1356(env_t_1356* env1332, card_t value_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef empty_env_t env_t_1358;


value_t lambda1358(env_t_1358* env1336, card_t value_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
number_t TOP_LEVEL_usecases_gmm_gmm_objective_dps(storage_t stgVar1280, array_array_number_t x_dps, array_number_t alphas_dps, array_array_number_t means_dps, array_array_number_t qs_dps, array_array_number_t ls_dps, number_t wishart_gamma_dps, number_t wishart_m_dps, matrix_shape_t x_shp, card_t alphas_shp, matrix_shape_t means_shp, matrix_shape_t qs_shp, matrix_shape_t ls_shp, card_t wishart_gamma_shp, card_t wishart_m_shp) {
	card_t n_shp = TOP_LEVEL_linalg_rows_shp(x_shp);
	card_t size1363 = width_card_t(n_shp);
	array_number_t stgVar1281 = storage_alloc(size1363);
	number_t macroDef1344;card_t n_dps = TOP_LEVEL_linalg_rows_dps(stgVar1281, x_dps, x_shp);
	card_t d_shp = TOP_LEVEL_linalg_cols_shp(x_shp);
	card_t size1362 = width_card_t(d_shp);
	array_number_t stgVar1283 = storage_alloc(size1362);
	number_t macroDef1343;card_t d_dps = TOP_LEVEL_linalg_cols_dps(stgVar1283, x_dps, x_shp);
	card_t K_shp = alphas_shp;
	card_t macroDef1314 = alphas_dps->length;
	card_t K_dps = macroDef1314;
	card_t size1353 = width_card_t(n_shp);
	array_number_t stgVar1287 = storage_alloc(size1353);
	number_t macroDef1325;array_number_t macroDef1324 = (array_number_t)stgVar1287;
		macroDef1324->length=n_dps;
		macroDef1324->arr=(number_t*)(STG_OFFSET(macroDef1324, VECTOR_HEADER_BYTES));
		storage_t stgVar1288 = macroDef1324;
		for(int i_dps = 0; i_dps < macroDef1324->length; i_dps++){
			card_t size1352 = width_card_t(K_shp);
	array_number_t stgVar1289 = storage_alloc(size1352);
	number_t macroDef1323;array_number_t macroDef1322 = (array_number_t)stgVar1289;
		macroDef1322->length=K_dps;
		macroDef1322->arr=(number_t*)(STG_OFFSET(macroDef1322, VECTOR_HEADER_BYTES));
		storage_t stgVar1290 = macroDef1322;
		for(int k_dps = 0; k_dps < macroDef1322->length; k_dps++){
			card_t size1345 = width_card_t(qs_shp.elem);
	array_number_t stgVar1292 = storage_alloc(size1345);
	number_t macroDef1315;
	macroDef1315 = TOP_LEVEL_linalg_vectorSum_dps(empty_storage, qs_dps->arr[k_dps], qs_shp.elem);;
	storage_free(stgVar1292, size1345);
			card_t size1351 = width_card_t(TOP_LEVEL_usecases_gmm_Qtimesv_shp(qs_shp.elem, ls_shp.elem, TOP_LEVEL_linalg_vectorSub_shp(x_shp.elem, means_shp.elem)));
	array_number_t stgVar1294 = storage_alloc(size1351);
	number_t macroDef1321;card_t size1350 = width_card_t(TOP_LEVEL_linalg_vectorSub_shp(x_shp.elem, means_shp.elem));
	array_number_t stgVar1297 = storage_alloc(size1350);
	array_number_t macroDef1320;card_t size1349 = width_card_t(ls_shp.elem);
	array_number_t stgVar1296 = storage_alloc(size1349);
	array_number_t macroDef1319;card_t size1348 = width_card_t(qs_shp.elem);
	array_number_t stgVar1295 = storage_alloc(size1348);
	array_number_t macroDef1318;card_t size1347 = width_card_t(means_shp.elem);
	array_number_t stgVar1301 = storage_alloc(size1347);
	array_number_t macroDef1317;card_t size1346 = width_card_t(x_shp.elem);
	array_number_t stgVar1300 = storage_alloc(size1346);
	array_number_t macroDef1316;
	macroDef1316 = TOP_LEVEL_linalg_vectorSub_dps(stgVar1297, x_dps->arr[i_dps], means_dps->arr[k_dps], x_shp.elem, means_shp.elem);;
	storage_free(stgVar1300, size1346);
	macroDef1317 = macroDef1316;;
	storage_free(stgVar1301, size1347);
	macroDef1318 = TOP_LEVEL_usecases_gmm_Qtimesv_dps(stgVar1294, qs_dps->arr[k_dps], ls_dps->arr[k_dps], macroDef1317, qs_shp.elem, ls_shp.elem, TOP_LEVEL_linalg_vectorSub_shp(x_shp.elem, means_shp.elem));;
	storage_free(stgVar1295, size1348);
	macroDef1319 = macroDef1318;;
	storage_free(stgVar1296, size1349);
	macroDef1320 = macroDef1319;;
	storage_free(stgVar1297, size1350);
	macroDef1321 = TOP_LEVEL_linalg_sqnorm_dps(empty_storage, macroDef1320, TOP_LEVEL_usecases_gmm_Qtimesv_shp(qs_shp.elem, ls_shp.elem, TOP_LEVEL_linalg_vectorSub_shp(x_shp.elem, means_shp.elem)));;
	storage_free(stgVar1294, size1351);
			macroDef1322->arr[k_dps] = ((alphas_dps->arr[k_dps]) + (macroDef1315)) - ((0.5) * (macroDef1321));;
			stgVar1290 = STG_OFFSET(stgVar1290, sizeof(number_t));
		}
	macroDef1323 = TOP_LEVEL_usecases_gmm_logsumexp_dps(stgVar1288, macroDef1322, K_shp);;
	storage_free(stgVar1289, size1352);
			macroDef1324->arr[i_dps] = macroDef1323;;
			stgVar1288 = STG_OFFSET(stgVar1288, sizeof(number_t));
		}
	macroDef1325 = TOP_LEVEL_linalg_vectorSum_dps(empty_storage, macroDef1324, n_shp);;
	storage_free(stgVar1287, size1353);
	card_t size1361 = width_card_t(K_shp);
	array_number_t stgVar1305 = storage_alloc(size1361);
	number_t macroDef1342;array_number_t macroDef1341 = (array_number_t)stgVar1305;
		macroDef1341->length=K_dps;
		macroDef1341->arr=(number_t*)(STG_OFFSET(macroDef1341, VECTOR_HEADER_BYTES));
		storage_t stgVar1306 = macroDef1341;
		for(int k_dps = 0; k_dps < macroDef1341->length; k_dps++){
			env_t_1354 env_t_1354_value = make_empty_env(); closure_t closure1328 = make_closure(lambda1354, &env_t_1354_value);
			card_t size1359 = width_card_t(TOP_LEVEL_linalg_vectorMap_shp(closure1328, qs_shp.elem));
	array_number_t stgVar1307 = storage_alloc(size1359);
	number_t macroDef1339;card_t size1357 = width_card_t(qs_shp.elem);
	array_number_t stgVar1309 = storage_alloc(size1357);
	array_number_t macroDef1335;env_t_1355 env_t_1355_value = make_empty_env(); closure_t closure1331 = make_closure(lambda1355, &env_t_1355_value);
	env_t_1356 env_t_1356_value = make_empty_env(); closure_t closure1334 = make_closure(lambda1356, &env_t_1356_value);
	macroDef1335 = TOP_LEVEL_linalg_vectorMap_dps(stgVar1307, closure1331, qs_dps->arr[k_dps], closure1334, qs_shp.elem);;
	storage_free(stgVar1309, size1357);
	env_t_1358 env_t_1358_value = make_empty_env(); closure_t closure1338 = make_closure(lambda1358, &env_t_1358_value);
	macroDef1339 = TOP_LEVEL_linalg_sqnorm_dps(empty_storage, macroDef1335, TOP_LEVEL_linalg_vectorMap_shp(closure1338, qs_shp.elem));;
	storage_free(stgVar1307, size1359);
			card_t size1360 = width_card_t(ls_shp.elem);
	array_number_t stgVar1312 = storage_alloc(size1360);
	number_t macroDef1340;
	macroDef1340 = TOP_LEVEL_linalg_sqnorm_dps(empty_storage, ls_dps->arr[k_dps], ls_shp.elem);;
	storage_free(stgVar1312, size1360);
			macroDef1341->arr[k_dps] = (macroDef1339) + (macroDef1340);;
			stgVar1306 = STG_OFFSET(stgVar1306, sizeof(number_t));
		}
	macroDef1342 = TOP_LEVEL_linalg_vectorSum_dps(empty_storage, macroDef1341, K_shp);;
	storage_free(stgVar1305, size1361);
	macroDef1343 = ((macroDef1325) - (((double)((n_dps))) * (TOP_LEVEL_usecases_gmm_logsumexp_dps(empty_storage, alphas_dps, alphas_shp)))) + ((0.5) * (macroDef1342));;
	storage_free(stgVar1283, size1362);
	macroDef1344 = macroDef1343;;
	storage_free(stgVar1281, size1363);
	return macroDef1344;
}

card_t TOP_LEVEL_usecases_gmm_test_gmm_shp(card_t dum_shp) {
	
	return 0;
}


void TOP_LEVEL_usecases_gmm_test_gmm_dps(storage_t stgVar1364, array_number_t dum_dps, card_t dum_shp) {
	card_t a_shp = 3;
	card_t size1392 = width_card_t(a_shp);
	array_number_t stgVar1365 = storage_alloc(size1392);
	array_number_t macroDef1382 = (array_number_t)stgVar1365;
	macroDef1382->length=3;
	macroDef1382->arr=(number_t*)(STG_OFFSET(stgVar1365, VECTOR_HEADER_BYTES));
	

	macroDef1382->arr[0] = 1;;

	macroDef1382->arr[1] = 2;;

	macroDef1382->arr[2] = 3;;;
	array_number_t a_dps = macroDef1382;
	array_print(a_dps);
	matrix_shape_t mat1_shp = nested_shape_card_t(3, 3);
	card_t size1391 = width_matrix_shape_t(mat1_shp);
	array_number_t stgVar1369 = storage_alloc(size1391);
	array_array_number_t macroDef1386 = (array_array_number_t)stgVar1369;
	macroDef1386->length=3;
	macroDef1386->arr=(array_number_t*)(STG_OFFSET(stgVar1369, VECTOR_HEADER_BYTES));
	int stgVar1369_offsetVar = 0;storage_t stgVar1370 = STG_OFFSET(stgVar1369, MATRIX_HEADER_BYTES(3) + stgVar1369_offsetVar);array_number_t macroDef1383 = (array_number_t)stgVar1370;
	macroDef1383->length=3;
	macroDef1383->arr=(number_t*)(STG_OFFSET(stgVar1370, VECTOR_HEADER_BYTES));
	

	macroDef1383->arr[0] = 1;;

	macroDef1383->arr[1] = 2;;

	macroDef1383->arr[2] = 3;;;

	macroDef1386->arr[0] = macroDef1383;;stgVar1369_offsetVar += VECTOR_ALL_BYTES(macroDef1386->arr[0]->length);storage_t stgVar1374 = STG_OFFSET(stgVar1369, MATRIX_HEADER_BYTES(3) + stgVar1369_offsetVar);array_number_t macroDef1384 = (array_number_t)stgVar1374;
	macroDef1384->length=3;
	macroDef1384->arr=(number_t*)(STG_OFFSET(stgVar1374, VECTOR_HEADER_BYTES));
	

	macroDef1384->arr[0] = 4;;

	macroDef1384->arr[1] = 5;;

	macroDef1384->arr[2] = 6;;;

	macroDef1386->arr[1] = macroDef1384;;stgVar1369_offsetVar += VECTOR_ALL_BYTES(macroDef1386->arr[1]->length);storage_t stgVar1378 = STG_OFFSET(stgVar1369, MATRIX_HEADER_BYTES(3) + stgVar1369_offsetVar);array_number_t macroDef1385 = (array_number_t)stgVar1378;
	macroDef1385->length=3;
	macroDef1385->arr=(number_t*)(STG_OFFSET(stgVar1378, VECTOR_HEADER_BYTES));
	

	macroDef1385->arr[0] = 7;;

	macroDef1385->arr[1] = 8;;

	macroDef1385->arr[2] = 9;;;

	macroDef1386->arr[2] = macroDef1385;;stgVar1369_offsetVar += VECTOR_ALL_BYTES(macroDef1386->arr[2]->length);;
	array_array_number_t mat1_dps = macroDef1386;
	matrix_print(mat1_dps);
	;
	storage_free(stgVar1369, size1391);
	;
	storage_free(stgVar1365, size1392);
	return ;
}
#endif
