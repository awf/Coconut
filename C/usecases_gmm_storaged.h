#ifndef __USECASES_GMM_STORAGED_H__ 
#define __USECASES_GMM_STORAGED_H__ 
#include "runtime/fsharp.h"
#include <stdio.h>
#include <math.h>
#include "linalg_storaged.h"

card_t TOP_LEVEL_usecases_gmm_logsumexp_shp(card_t arr_shp) {
	
	return 0;
}

typedef empty_env_t env_t_1243;


value_t lambda1243(env_t_1243* env1229, card_t x_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef struct env_t_1244 {
	number_t mx_dps;
} env_t_1244;
env_t_1244 make_env_t_1244(number_t mx_dps) {
	env_t_1244 env;
	env.mx_dps = mx_dps;
	return env;
}

value_t lambda1244(env_t_1244* env1233, storage_t stgVar1228, number_t x_dps, card_t x_shp) {
	number_t mx_dps1232 = env1233->mx_dps;
	value_t res;
	res.number_t_value = exp((x_dps) - (mx_dps1232));
	return res;
}
typedef empty_env_t env_t_1245;


value_t lambda1245(env_t_1245* env1236, card_t x_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef empty_env_t env_t_1246;


value_t lambda1246(env_t_1246* env1239, card_t x_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
number_t TOP_LEVEL_usecases_gmm_logsumexp_dps(storage_t stgVar1221, array_number_t arr_dps, card_t arr_shp) {
	card_t mx_shp = 0;
	number_t mx_dps = TOP_LEVEL_linalg_vectorMax_dps(empty_storage, arr_dps, arr_shp);
	card_t semx_shp = 0;
	env_t_1243 env_t_1243_value = make_empty_env(); closure_t closure1231 = make_closure(lambda1243, &env_t_1243_value);
	card_t size1247 = width_card_t(TOP_LEVEL_linalg_vectorMap_shp(closure1231, arr_shp));
	array_number_t stgVar1225 = storage_alloc(size1247);
	number_t macroDef1242;env_t_1244 env_t_1244_value = make_env_t_1244(mx_dps); closure_t closure1235 = make_closure(lambda1244, &env_t_1244_value);
	env_t_1245 env_t_1245_value = make_empty_env(); closure_t closure1238 = make_closure(lambda1245, &env_t_1245_value);
	env_t_1246 env_t_1246_value = make_empty_env(); closure_t closure1241 = make_closure(lambda1246, &env_t_1246_value);
	macroDef1242 = TOP_LEVEL_linalg_vectorSum_dps(empty_storage, TOP_LEVEL_linalg_vectorMap_dps(stgVar1225, closure1235, arr_dps, closure1238, arr_shp), TOP_LEVEL_linalg_vectorMap_shp(closure1241, arr_shp));;
	storage_free(stgVar1225, size1247);
	number_t semx_dps = macroDef1242;
	return (log(semx_dps)) + (mx_dps);
}

card_t TOP_LEVEL_usecases_gmm_tri_shp(card_t n_shp) {
	
	return 0;
}


index_t TOP_LEVEL_usecases_gmm_tri_dps(storage_t stgVar1248, index_t n_dps, card_t n_shp) {
	
	return ((n_dps) * ((n_dps) + (1))) / (2);
}

card_t TOP_LEVEL_usecases_gmm_Qtimesv_shp(card_t q_shp, card_t l_shp, card_t v_shp) {
	
	return v_shp;
}


array_number_t TOP_LEVEL_usecases_gmm_Qtimesv_dps(storage_t stgVar1249, array_number_t q_dps, array_number_t l_dps, array_number_t v_dps, card_t q_shp, card_t l_shp, card_t v_shp) {
	card_t macroDef1267 = v_dps->length;
	array_number_t macroDef1270 = (array_number_t)stgVar1249;
		macroDef1270->length=macroDef1267;
		macroDef1270->arr=(number_t*)(STG_OFFSET(macroDef1270, VECTOR_HEADER_BYTES));
		storage_t stgVar1251 = macroDef1270;
		for(int i_dps = 0; i_dps < macroDef1270->length; i_dps++){
			card_t tis_shp = 0;
			index_t tis_dps = TOP_LEVEL_usecases_gmm_tri_dps(empty_storage, (i_dps) - (1), 0);
			card_t sum_shp = 0;
			card_t macroDef1269 = l_dps->length;
			number_t macroDef1268 = 0;
	for(int idx_dps = 0; idx_dps <= macroDef1269; idx_dps++){
		card_t j_shp = 0;
		index_t j_dps = (idx_dps) - (tis_dps);
		card_t isInRange_shp = 0;
		bool_t isInRange_dps = 0;
	if((j_dps) >= (0)) {
		
		isInRange_dps = (j_dps) < (i_dps);;
	} else {
		
		isInRange_dps = false;;
	}
		number_t ite1271 = 0;
	if(isInRange_dps) {
		
		ite1271 = (macroDef1268) + ((l_dps->arr[idx_dps]) * (v_dps->arr[j_dps]));;
	} else {
		
		ite1271 = macroDef1268;;
	}
		macroDef1268 = ite1271;;
	}
			number_t sum_dps = macroDef1268;
			macroDef1270->arr[i_dps] = (sum_dps) + ((exp(q_dps->arr[i_dps])) * (v_dps->arr[i_dps]));;
			stgVar1251 = STG_OFFSET(stgVar1251, sizeof(number_t));
		}
	return macroDef1270;
}

card_t TOP_LEVEL_usecases_gmm_Qtimesv_test_shp(card_t unitVar0_shp) {
	
	return 0;
}


void TOP_LEVEL_usecases_gmm_Qtimesv_test_dps(storage_t stgVar1272, int unitVar0_dps, card_t unitVar0_shp) {
	card_t q_shp = TOP_LEVEL_linalg_vec3_shp(0, 0, 0);
	card_t size1323 = width_card_t(q_shp);
	array_number_t stgVar1273 = storage_alloc(size1323);
	array_number_t q_dps = TOP_LEVEL_linalg_vec3_dps(stgVar1273, 0.1, -1, 0.3, 0, 0, 0);
	card_t l_shp = TOP_LEVEL_linalg_vec3_shp(0, 0, 0);
	card_t size1322 = width_card_t(l_shp);
	array_number_t stgVar1277 = storage_alloc(size1322);
	array_number_t l_dps = TOP_LEVEL_linalg_vec3_dps(stgVar1277, 5, -2, 7.1, 0, 0, 0);
	card_t v_shp = TOP_LEVEL_linalg_vec3_shp(0, 0, 0);
	card_t size1321 = width_card_t(v_shp);
	array_number_t stgVar1281 = storage_alloc(size1321);
	array_number_t v_dps = TOP_LEVEL_linalg_vec3_dps(stgVar1281, 1.4, -7, 3.1, 0, 0, 0);
	card_t ans0_shp = 0;
	number_t ans0_dps = (exp(q_dps->arr[0])) * (v_dps->arr[0]);
	card_t ans1_shp = 0;
	number_t ans1_dps = ((l_dps->arr[0]) * (v_dps->arr[0])) + ((exp(q_dps->arr[1])) * (v_dps->arr[1]));
	card_t ans2_shp = 0;
	number_t ans2_dps = (((l_dps->arr[1]) * (v_dps->arr[0])) + ((l_dps->arr[2]) * (v_dps->arr[1]))) + ((exp(q_dps->arr[2])) * (v_dps->arr[2]));
	card_t ans_shp = TOP_LEVEL_linalg_vec3_shp(0, 0, 0);
	card_t size1320 = width_card_t(ans_shp);
	array_number_t stgVar1300 = storage_alloc(size1320);
	array_number_t ans_dps = TOP_LEVEL_linalg_vec3_dps(stgVar1300, ans0_dps, ans1_dps, ans2_dps, 0, 0, 0);
	card_t qv_shp = TOP_LEVEL_usecases_gmm_Qtimesv_shp(q_shp, l_shp, v_shp);
	card_t size1319 = width_card_t(qv_shp);
	array_number_t stgVar1304 = storage_alloc(size1319);
	array_number_t qv_dps = TOP_LEVEL_usecases_gmm_Qtimesv_dps(stgVar1304, q_dps, l_dps, v_dps, q_shp, l_shp, v_shp);
	card_t nrm_shp = 0;
	card_t size1318 = width_card_t(TOP_LEVEL_linalg_vectorSub_shp(qv_shp, ans_shp));
	array_number_t stgVar1309 = storage_alloc(size1318);
	number_t macroDef1312;
	macroDef1312 = TOP_LEVEL_linalg_sqnorm_dps(empty_storage, TOP_LEVEL_linalg_vectorSub_dps(stgVar1309, qv_dps, ans_dps, qv_shp, ans_shp), TOP_LEVEL_linalg_vectorSub_shp(qv_shp, ans_shp));;
	storage_free(stgVar1309, size1318);
	number_t nrm_dps = macroDef1312;
	number_print(nrm_dps);
	storage_free(stgVar1304, size1319);
	;
	storage_free(stgVar1300, size1320);
	;
	storage_free(stgVar1281, size1321);
	;
	storage_free(stgVar1277, size1322);
	;
	storage_free(stgVar1273, size1323);
	return ;
}

card_t TOP_LEVEL_usecases_gmm_gmm_objective_shp(matrix_shape_t x_shp, card_t alphas_shp, matrix_shape_t means_shp, matrix_shape_t qs_shp, matrix_shape_t ls_shp, card_t wishart_gamma_shp, card_t wishart_m_shp) {
	
	return 0;
}

typedef empty_env_t env_t_1398;


value_t lambda1398(env_t_1398* env1370, card_t value_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef empty_env_t env_t_1399;


value_t lambda1399(env_t_1399* env1373, storage_t stgVar1354, number_t value_dps, card_t value_shp) {
	
	value_t res;
	res.number_t_value = exp(value_dps);
	return res;
}
typedef empty_env_t env_t_1400;


value_t lambda1400(env_t_1400* env1376, card_t value_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef empty_env_t env_t_1402;


value_t lambda1402(env_t_1402* env1380, card_t value_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
number_t TOP_LEVEL_usecases_gmm_gmm_objective_dps(storage_t stgVar1324, array_array_number_t x_dps, array_number_t alphas_dps, array_array_number_t means_dps, array_array_number_t qs_dps, array_array_number_t ls_dps, number_t wishart_gamma_dps, number_t wishart_m_dps, matrix_shape_t x_shp, card_t alphas_shp, matrix_shape_t means_shp, matrix_shape_t qs_shp, matrix_shape_t ls_shp, card_t wishart_gamma_shp, card_t wishart_m_shp) {
	card_t n_shp = TOP_LEVEL_linalg_rows_shp(x_shp);
	card_t size1407 = width_card_t(n_shp);
	array_number_t stgVar1325 = storage_alloc(size1407);
	number_t macroDef1388;card_t n_dps = TOP_LEVEL_linalg_rows_dps(stgVar1325, x_dps, x_shp);
	card_t d_shp = TOP_LEVEL_linalg_cols_shp(x_shp);
	card_t size1406 = width_card_t(d_shp);
	array_number_t stgVar1327 = storage_alloc(size1406);
	number_t macroDef1387;card_t d_dps = TOP_LEVEL_linalg_cols_dps(stgVar1327, x_dps, x_shp);
	card_t K_shp = alphas_shp;
	card_t macroDef1358 = alphas_dps->length;
	card_t K_dps = macroDef1358;
	card_t size1397 = width_card_t(n_shp);
	array_number_t stgVar1331 = storage_alloc(size1397);
	number_t macroDef1369;array_number_t macroDef1368 = (array_number_t)stgVar1331;
		macroDef1368->length=n_dps;
		macroDef1368->arr=(number_t*)(STG_OFFSET(macroDef1368, VECTOR_HEADER_BYTES));
		storage_t stgVar1332 = macroDef1368;
		for(int i_dps = 0; i_dps < macroDef1368->length; i_dps++){
			card_t size1396 = width_card_t(K_shp);
	array_number_t stgVar1333 = storage_alloc(size1396);
	number_t macroDef1367;array_number_t macroDef1366 = (array_number_t)stgVar1333;
		macroDef1366->length=K_dps;
		macroDef1366->arr=(number_t*)(STG_OFFSET(macroDef1366, VECTOR_HEADER_BYTES));
		storage_t stgVar1334 = macroDef1366;
		for(int k_dps = 0; k_dps < macroDef1366->length; k_dps++){
			card_t size1389 = width_card_t(qs_shp.elem);
	array_number_t stgVar1336 = storage_alloc(size1389);
	number_t macroDef1359;
	macroDef1359 = TOP_LEVEL_linalg_vectorSum_dps(empty_storage, qs_dps->arr[k_dps], qs_shp.elem);;
	storage_free(stgVar1336, size1389);
			card_t size1395 = width_card_t(TOP_LEVEL_usecases_gmm_Qtimesv_shp(qs_shp.elem, ls_shp.elem, TOP_LEVEL_linalg_vectorSub_shp(x_shp.elem, means_shp.elem)));
	array_number_t stgVar1338 = storage_alloc(size1395);
	number_t macroDef1365;card_t size1394 = width_card_t(TOP_LEVEL_linalg_vectorSub_shp(x_shp.elem, means_shp.elem));
	array_number_t stgVar1341 = storage_alloc(size1394);
	array_number_t macroDef1364;card_t size1393 = width_card_t(ls_shp.elem);
	array_number_t stgVar1340 = storage_alloc(size1393);
	array_number_t macroDef1363;card_t size1392 = width_card_t(qs_shp.elem);
	array_number_t stgVar1339 = storage_alloc(size1392);
	array_number_t macroDef1362;card_t size1391 = width_card_t(means_shp.elem);
	array_number_t stgVar1345 = storage_alloc(size1391);
	array_number_t macroDef1361;card_t size1390 = width_card_t(x_shp.elem);
	array_number_t stgVar1344 = storage_alloc(size1390);
	array_number_t macroDef1360;
	macroDef1360 = TOP_LEVEL_linalg_vectorSub_dps(stgVar1341, x_dps->arr[i_dps], means_dps->arr[k_dps], x_shp.elem, means_shp.elem);;
	storage_free(stgVar1344, size1390);
	macroDef1361 = macroDef1360;;
	storage_free(stgVar1345, size1391);
	macroDef1362 = TOP_LEVEL_usecases_gmm_Qtimesv_dps(stgVar1338, qs_dps->arr[k_dps], ls_dps->arr[k_dps], macroDef1361, qs_shp.elem, ls_shp.elem, TOP_LEVEL_linalg_vectorSub_shp(x_shp.elem, means_shp.elem));;
	storage_free(stgVar1339, size1392);
	macroDef1363 = macroDef1362;;
	storage_free(stgVar1340, size1393);
	macroDef1364 = macroDef1363;;
	storage_free(stgVar1341, size1394);
	macroDef1365 = TOP_LEVEL_linalg_sqnorm_dps(empty_storage, macroDef1364, TOP_LEVEL_usecases_gmm_Qtimesv_shp(qs_shp.elem, ls_shp.elem, TOP_LEVEL_linalg_vectorSub_shp(x_shp.elem, means_shp.elem)));;
	storage_free(stgVar1338, size1395);
			macroDef1366->arr[k_dps] = ((alphas_dps->arr[k_dps]) + (macroDef1359)) - ((0.5) * (macroDef1365));;
			stgVar1334 = STG_OFFSET(stgVar1334, sizeof(number_t));
		}
	macroDef1367 = TOP_LEVEL_usecases_gmm_logsumexp_dps(stgVar1332, macroDef1366, K_shp);;
	storage_free(stgVar1333, size1396);
			macroDef1368->arr[i_dps] = macroDef1367;;
			stgVar1332 = STG_OFFSET(stgVar1332, sizeof(number_t));
		}
	macroDef1369 = TOP_LEVEL_linalg_vectorSum_dps(empty_storage, macroDef1368, n_shp);;
	storage_free(stgVar1331, size1397);
	card_t size1405 = width_card_t(K_shp);
	array_number_t stgVar1349 = storage_alloc(size1405);
	number_t macroDef1386;array_number_t macroDef1385 = (array_number_t)stgVar1349;
		macroDef1385->length=K_dps;
		macroDef1385->arr=(number_t*)(STG_OFFSET(macroDef1385, VECTOR_HEADER_BYTES));
		storage_t stgVar1350 = macroDef1385;
		for(int k_dps = 0; k_dps < macroDef1385->length; k_dps++){
			env_t_1398 env_t_1398_value = make_empty_env(); closure_t closure1372 = make_closure(lambda1398, &env_t_1398_value);
			card_t size1403 = width_card_t(TOP_LEVEL_linalg_vectorMap_shp(closure1372, qs_shp.elem));
	array_number_t stgVar1351 = storage_alloc(size1403);
	number_t macroDef1383;card_t size1401 = width_card_t(qs_shp.elem);
	array_number_t stgVar1353 = storage_alloc(size1401);
	array_number_t macroDef1379;env_t_1399 env_t_1399_value = make_empty_env(); closure_t closure1375 = make_closure(lambda1399, &env_t_1399_value);
	env_t_1400 env_t_1400_value = make_empty_env(); closure_t closure1378 = make_closure(lambda1400, &env_t_1400_value);
	macroDef1379 = TOP_LEVEL_linalg_vectorMap_dps(stgVar1351, closure1375, qs_dps->arr[k_dps], closure1378, qs_shp.elem);;
	storage_free(stgVar1353, size1401);
	env_t_1402 env_t_1402_value = make_empty_env(); closure_t closure1382 = make_closure(lambda1402, &env_t_1402_value);
	macroDef1383 = TOP_LEVEL_linalg_sqnorm_dps(empty_storage, macroDef1379, TOP_LEVEL_linalg_vectorMap_shp(closure1382, qs_shp.elem));;
	storage_free(stgVar1351, size1403);
			card_t size1404 = width_card_t(ls_shp.elem);
	array_number_t stgVar1356 = storage_alloc(size1404);
	number_t macroDef1384;
	macroDef1384 = TOP_LEVEL_linalg_sqnorm_dps(empty_storage, ls_dps->arr[k_dps], ls_shp.elem);;
	storage_free(stgVar1356, size1404);
			macroDef1385->arr[k_dps] = (macroDef1383) + (macroDef1384);;
			stgVar1350 = STG_OFFSET(stgVar1350, sizeof(number_t));
		}
	macroDef1386 = TOP_LEVEL_linalg_vectorSum_dps(empty_storage, macroDef1385, K_shp);;
	storage_free(stgVar1349, size1405);
	macroDef1387 = ((macroDef1369) - (((double)((n_dps))) * (TOP_LEVEL_usecases_gmm_logsumexp_dps(empty_storage, alphas_dps, alphas_shp)))) + ((0.5) * (macroDef1386));;
	storage_free(stgVar1327, size1406);
	macroDef1388 = macroDef1387;;
	storage_free(stgVar1325, size1407);
	return macroDef1388;
}

card_t TOP_LEVEL_usecases_gmm_test_gmm_shp(card_t dum_shp) {
	
	return 0;
}


void TOP_LEVEL_usecases_gmm_test_gmm_dps(storage_t stgVar1408, array_number_t dum_dps, card_t dum_shp) {
	card_t a_shp = 3;
	card_t size1436 = width_card_t(a_shp);
	array_number_t stgVar1409 = storage_alloc(size1436);
	array_number_t macroDef1426 = (array_number_t)stgVar1409;
	macroDef1426->length=3;
	macroDef1426->arr=(number_t*)(STG_OFFSET(stgVar1409, VECTOR_HEADER_BYTES));
	

	macroDef1426->arr[0] = 1;;

	macroDef1426->arr[1] = 2;;

	macroDef1426->arr[2] = 3;;;
	array_number_t a_dps = macroDef1426;
	array_print(a_dps);
	matrix_shape_t mat1_shp = nested_shape_card_t(3, 3);
	card_t size1435 = width_matrix_shape_t(mat1_shp);
	array_number_t stgVar1413 = storage_alloc(size1435);
	array_array_number_t macroDef1430 = (array_array_number_t)stgVar1413;
	macroDef1430->length=3;
	macroDef1430->arr=(array_number_t*)(STG_OFFSET(stgVar1413, VECTOR_HEADER_BYTES));
	int stgVar1413_offsetVar = 0;storage_t stgVar1414 = STG_OFFSET(stgVar1413, MATRIX_HEADER_BYTES(3) + stgVar1413_offsetVar);array_number_t macroDef1427 = (array_number_t)stgVar1414;
	macroDef1427->length=3;
	macroDef1427->arr=(number_t*)(STG_OFFSET(stgVar1414, VECTOR_HEADER_BYTES));
	

	macroDef1427->arr[0] = 1;;

	macroDef1427->arr[1] = 2;;

	macroDef1427->arr[2] = 3;;;

	macroDef1430->arr[0] = macroDef1427;;stgVar1413_offsetVar += VECTOR_ALL_BYTES(macroDef1430->arr[0]->length);storage_t stgVar1418 = STG_OFFSET(stgVar1413, MATRIX_HEADER_BYTES(3) + stgVar1413_offsetVar);array_number_t macroDef1428 = (array_number_t)stgVar1418;
	macroDef1428->length=3;
	macroDef1428->arr=(number_t*)(STG_OFFSET(stgVar1418, VECTOR_HEADER_BYTES));
	

	macroDef1428->arr[0] = 4;;

	macroDef1428->arr[1] = 5;;

	macroDef1428->arr[2] = 6;;;

	macroDef1430->arr[1] = macroDef1428;;stgVar1413_offsetVar += VECTOR_ALL_BYTES(macroDef1430->arr[1]->length);storage_t stgVar1422 = STG_OFFSET(stgVar1413, MATRIX_HEADER_BYTES(3) + stgVar1413_offsetVar);array_number_t macroDef1429 = (array_number_t)stgVar1422;
	macroDef1429->length=3;
	macroDef1429->arr=(number_t*)(STG_OFFSET(stgVar1422, VECTOR_HEADER_BYTES));
	

	macroDef1429->arr[0] = 7;;

	macroDef1429->arr[1] = 8;;

	macroDef1429->arr[2] = 9;;;

	macroDef1430->arr[2] = macroDef1429;;stgVar1413_offsetVar += VECTOR_ALL_BYTES(macroDef1430->arr[2]->length);;
	array_array_number_t mat1_dps = macroDef1430;
	matrix_print(mat1_dps);
	;
	storage_free(stgVar1413, size1435);
	;
	storage_free(stgVar1409, size1436);
	return ;
}
#endif
