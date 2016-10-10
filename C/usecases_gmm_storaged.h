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

typedef struct env_t_1281 {
	array_number_t v_dps;
	index_t tis_dps;
	array_number_t l_dps;
	index_t i_dps;
} env_t_1281;
env_t_1281 make_env_t_1281(array_number_t v_dps,index_t tis_dps,array_number_t l_dps,index_t i_dps) {
	env_t_1281 env;
	env.v_dps = v_dps;
	env.tis_dps = tis_dps;
	env.l_dps = l_dps;
	env.i_dps = i_dps;
	return env;
}

value_t lambda1281(env_t_1281* env1272, storage_t stgVar1259, number_t acc_dps, index_t idx_dps, card_t acc_shp, card_t idx_shp) {
	array_number_t v_dps1271 = env1272->v_dps;
	index_t tis_dps1270 = env1272->tis_dps;
	array_number_t l_dps1269 = env1272->l_dps;
	index_t i_dps1268 = env1272->i_dps;
	card_t j_shp = 0;
	index_t j_dps = (idx_dps) - (tis_dps1270);
	card_t isInRange_shp = 0;
	bool_t isInRange_dps = 0;
	if((j_dps) >= (0)) {
		
		isInRange_dps = (j_dps) < (i_dps1268);;
	} else {
		
		isInRange_dps = false;;
	}
	number_t ite1280 = 0;
	if(isInRange_dps) {
		
		ite1280 = (acc_dps) + ((l_dps1269->arr[idx_dps]) * (v_dps1271->arr[j_dps]));;
	} else {
		
		ite1280 = acc_dps;;
	}
	value_t res;
	res.number_t_value = ite1280;
	return res;
}
typedef empty_env_t env_t_1282;


value_t lambda1282(env_t_1282* env1276, card_t acc_shp, card_t idx_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
array_number_t TOP_LEVEL_usecases_gmm_Qtimesv_dps(storage_t stgVar1249, array_number_t q_dps, array_number_t l_dps, array_number_t v_dps, card_t q_shp, card_t l_shp, card_t v_shp) {
	card_t macroDef1267 = v_dps->length;
	array_number_t macroDef1279 = (array_number_t)stgVar1249;
		macroDef1279->length=macroDef1267;
		macroDef1279->arr=(number_t*)(STG_OFFSET(macroDef1279, VECTOR_HEADER_BYTES));
		storage_t stgVar1251 = macroDef1279;
		for(int i_dps = 0; i_dps < macroDef1279->length; i_dps++){
			card_t tis_shp = 0;
			index_t tis_dps = TOP_LEVEL_usecases_gmm_tri_dps(empty_storage, (i_dps) - (1), 0);
			card_t sum_shp = 0;
			env_t_1281 env_t_1281_value = make_env_t_1281(v_dps,tis_dps,l_dps,i_dps); closure_t closure1274 = make_closure(lambda1281, &env_t_1281_value);
			card_t macroDef1275 = l_dps->length;
			env_t_1282 env_t_1282_value = make_empty_env(); closure_t closure1278 = make_closure(lambda1282, &env_t_1282_value);
			number_t sum_dps = TOP_LEVEL_linalg_iterateNumber_dps(empty_storage, closure1274, 0, 0, macroDef1275, closure1278, 0, 0, l_shp);
			macroDef1279->arr[i_dps] = (sum_dps) + ((exp(q_dps->arr[i_dps])) * (v_dps->arr[i_dps]));;
			stgVar1251 = STG_OFFSET(stgVar1251, sizeof(number_t));
		}
	return macroDef1279;
}

card_t TOP_LEVEL_usecases_gmm_Qtimesv_test_shp(card_t unitVar0_shp) {
	
	return 0;
}


void TOP_LEVEL_usecases_gmm_Qtimesv_test_dps(storage_t stgVar1283, int unitVar0_dps, card_t unitVar0_shp) {
	card_t q_shp = TOP_LEVEL_linalg_vec3_shp(0, 0, 0);
	card_t size1334 = width_card_t(q_shp);
	array_number_t stgVar1284 = storage_alloc(size1334);
	array_number_t q_dps = TOP_LEVEL_linalg_vec3_dps(stgVar1284, 0.1, -1, 0.3, 0, 0, 0);
	card_t l_shp = TOP_LEVEL_linalg_vec3_shp(0, 0, 0);
	card_t size1333 = width_card_t(l_shp);
	array_number_t stgVar1288 = storage_alloc(size1333);
	array_number_t l_dps = TOP_LEVEL_linalg_vec3_dps(stgVar1288, 5, -2, 7.1, 0, 0, 0);
	card_t v_shp = TOP_LEVEL_linalg_vec3_shp(0, 0, 0);
	card_t size1332 = width_card_t(v_shp);
	array_number_t stgVar1292 = storage_alloc(size1332);
	array_number_t v_dps = TOP_LEVEL_linalg_vec3_dps(stgVar1292, 1.4, -7, 3.1, 0, 0, 0);
	card_t ans0_shp = 0;
	number_t ans0_dps = (exp(q_dps->arr[0])) * (v_dps->arr[0]);
	card_t ans1_shp = 0;
	number_t ans1_dps = ((l_dps->arr[0]) * (v_dps->arr[0])) + ((exp(q_dps->arr[1])) * (v_dps->arr[1]));
	card_t ans2_shp = 0;
	number_t ans2_dps = (((l_dps->arr[1]) * (v_dps->arr[0])) + ((l_dps->arr[2]) * (v_dps->arr[1]))) + ((exp(q_dps->arr[2])) * (v_dps->arr[2]));
	card_t ans_shp = TOP_LEVEL_linalg_vec3_shp(0, 0, 0);
	card_t size1331 = width_card_t(ans_shp);
	array_number_t stgVar1311 = storage_alloc(size1331);
	array_number_t ans_dps = TOP_LEVEL_linalg_vec3_dps(stgVar1311, ans0_dps, ans1_dps, ans2_dps, 0, 0, 0);
	card_t qv_shp = TOP_LEVEL_usecases_gmm_Qtimesv_shp(q_shp, l_shp, v_shp);
	card_t size1330 = width_card_t(qv_shp);
	array_number_t stgVar1315 = storage_alloc(size1330);
	array_number_t qv_dps = TOP_LEVEL_usecases_gmm_Qtimesv_dps(stgVar1315, q_dps, l_dps, v_dps, q_shp, l_shp, v_shp);
	card_t nrm_shp = 0;
	card_t size1329 = width_card_t(TOP_LEVEL_linalg_vectorSub_shp(qv_shp, ans_shp));
	array_number_t stgVar1320 = storage_alloc(size1329);
	number_t macroDef1323;
	macroDef1323 = TOP_LEVEL_linalg_sqnorm_dps(empty_storage, TOP_LEVEL_linalg_vectorSub_dps(stgVar1320, qv_dps, ans_dps, qv_shp, ans_shp), TOP_LEVEL_linalg_vectorSub_shp(qv_shp, ans_shp));;
	storage_free(stgVar1320, size1329);
	number_t nrm_dps = macroDef1323;
	number_print(nrm_dps);
	storage_free(stgVar1315, size1330);
	;
	storage_free(stgVar1311, size1331);
	;
	storage_free(stgVar1292, size1332);
	;
	storage_free(stgVar1288, size1333);
	;
	storage_free(stgVar1284, size1334);
	return ;
}

card_t TOP_LEVEL_usecases_gmm_gmm_objective_shp(matrix_shape_t x_shp, card_t alphas_shp, matrix_shape_t means_shp, matrix_shape_t qs_shp, matrix_shape_t ls_shp, card_t wishart_gamma_shp, card_t wishart_m_shp) {
	
	return 0;
}

typedef empty_env_t env_t_1408;


value_t lambda1408(env_t_1408* env1379, card_t value_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef empty_env_t env_t_1409;


value_t lambda1409(env_t_1409* env1382, storage_t stgVar1365, number_t value_dps, card_t value_shp) {
	
	value_t res;
	res.number_t_value = exp(value_dps);
	return res;
}
typedef empty_env_t env_t_1410;


value_t lambda1410(env_t_1410* env1385, card_t value_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef empty_env_t env_t_1412;


value_t lambda1412(env_t_1412* env1389, card_t value_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
number_t TOP_LEVEL_usecases_gmm_gmm_objective_dps(storage_t stgVar1335, array_array_number_t x_dps, array_number_t alphas_dps, array_array_number_t means_dps, array_array_number_t qs_dps, array_array_number_t ls_dps, number_t wishart_gamma_dps, number_t wishart_m_dps, matrix_shape_t x_shp, card_t alphas_shp, matrix_shape_t means_shp, matrix_shape_t qs_shp, matrix_shape_t ls_shp, card_t wishart_gamma_shp, card_t wishart_m_shp) {
	card_t n_shp = TOP_LEVEL_linalg_rows_shp(x_shp);
	card_t size1418 = width_card_t(n_shp);
	array_number_t stgVar1336 = storage_alloc(size1418);
	number_t macroDef1399;card_t n_dps = TOP_LEVEL_linalg_rows_dps(stgVar1336, x_dps, x_shp);
	card_t d_shp = TOP_LEVEL_linalg_cols_shp(x_shp);
	card_t size1417 = width_card_t(d_shp);
	array_number_t stgVar1338 = storage_alloc(size1417);
	number_t macroDef1398;card_t d_dps = TOP_LEVEL_linalg_cols_dps(stgVar1338, x_dps, x_shp);
	card_t K_shp = alphas_shp;
	card_t macroDef1369 = alphas_dps->length;
	card_t K_dps = macroDef1369;
	card_t size1416 = width_card_t(n_shp);
	array_number_t stgVar1342 = storage_alloc(size1416);
	number_t macroDef1397;array_number_t macroDef1396 = (array_number_t)stgVar1342;
		macroDef1396->length=n_dps;
		macroDef1396->arr=(number_t*)(STG_OFFSET(macroDef1396, VECTOR_HEADER_BYTES));
		storage_t stgVar1343 = macroDef1396;
		for(int i_dps = 0; i_dps < macroDef1396->length; i_dps++){
			card_t size1407 = width_card_t(K_shp);
	array_number_t stgVar1344 = storage_alloc(size1407);
	number_t macroDef1378;array_number_t macroDef1377 = (array_number_t)stgVar1344;
		macroDef1377->length=K_dps;
		macroDef1377->arr=(number_t*)(STG_OFFSET(macroDef1377, VECTOR_HEADER_BYTES));
		storage_t stgVar1345 = macroDef1377;
		for(int k_dps = 0; k_dps < macroDef1377->length; k_dps++){
			card_t size1400 = width_card_t(qs_shp.elem);
	array_number_t stgVar1347 = storage_alloc(size1400);
	number_t macroDef1370;
	macroDef1370 = TOP_LEVEL_linalg_vectorSum_dps(empty_storage, qs_dps->arr[k_dps], qs_shp.elem);;
	storage_free(stgVar1347, size1400);
			card_t size1406 = width_card_t(TOP_LEVEL_usecases_gmm_Qtimesv_shp(qs_shp.elem, ls_shp.elem, TOP_LEVEL_linalg_vectorSub_shp(x_shp.elem, means_shp.elem)));
	array_number_t stgVar1349 = storage_alloc(size1406);
	number_t macroDef1376;card_t size1405 = width_card_t(TOP_LEVEL_linalg_vectorSub_shp(x_shp.elem, means_shp.elem));
	array_number_t stgVar1352 = storage_alloc(size1405);
	array_number_t macroDef1375;card_t size1404 = width_card_t(ls_shp.elem);
	array_number_t stgVar1351 = storage_alloc(size1404);
	array_number_t macroDef1374;card_t size1403 = width_card_t(qs_shp.elem);
	array_number_t stgVar1350 = storage_alloc(size1403);
	array_number_t macroDef1373;card_t size1402 = width_card_t(means_shp.elem);
	array_number_t stgVar1356 = storage_alloc(size1402);
	array_number_t macroDef1372;card_t size1401 = width_card_t(x_shp.elem);
	array_number_t stgVar1355 = storage_alloc(size1401);
	array_number_t macroDef1371;
	macroDef1371 = TOP_LEVEL_linalg_vectorSub_dps(stgVar1352, x_dps->arr[i_dps], means_dps->arr[k_dps], x_shp.elem, means_shp.elem);;
	storage_free(stgVar1355, size1401);
	macroDef1372 = macroDef1371;;
	storage_free(stgVar1356, size1402);
	macroDef1373 = TOP_LEVEL_usecases_gmm_Qtimesv_dps(stgVar1349, qs_dps->arr[k_dps], ls_dps->arr[k_dps], macroDef1372, qs_shp.elem, ls_shp.elem, TOP_LEVEL_linalg_vectorSub_shp(x_shp.elem, means_shp.elem));;
	storage_free(stgVar1350, size1403);
	macroDef1374 = macroDef1373;;
	storage_free(stgVar1351, size1404);
	macroDef1375 = macroDef1374;;
	storage_free(stgVar1352, size1405);
	macroDef1376 = TOP_LEVEL_linalg_sqnorm_dps(empty_storage, macroDef1375, TOP_LEVEL_usecases_gmm_Qtimesv_shp(qs_shp.elem, ls_shp.elem, TOP_LEVEL_linalg_vectorSub_shp(x_shp.elem, means_shp.elem)));;
	storage_free(stgVar1349, size1406);
			macroDef1377->arr[k_dps] = ((alphas_dps->arr[k_dps]) + (macroDef1370)) - ((0.5) * (macroDef1376));;
			stgVar1345 = STG_OFFSET(stgVar1345, sizeof(number_t));
		}
	macroDef1378 = TOP_LEVEL_usecases_gmm_logsumexp_dps(empty_storage, macroDef1377, K_shp);;
	storage_free(stgVar1344, size1407);
			card_t size1415 = width_card_t(K_shp);
	array_number_t stgVar1360 = storage_alloc(size1415);
	number_t macroDef1395;array_number_t macroDef1394 = (array_number_t)stgVar1360;
		macroDef1394->length=K_dps;
		macroDef1394->arr=(number_t*)(STG_OFFSET(macroDef1394, VECTOR_HEADER_BYTES));
		storage_t stgVar1361 = macroDef1394;
		for(int k_dps = 0; k_dps < macroDef1394->length; k_dps++){
			env_t_1408 env_t_1408_value = make_empty_env(); closure_t closure1381 = make_closure(lambda1408, &env_t_1408_value);
			card_t size1413 = width_card_t(TOP_LEVEL_linalg_vectorMap_shp(closure1381, qs_shp.elem));
	array_number_t stgVar1362 = storage_alloc(size1413);
	number_t macroDef1392;card_t size1411 = width_card_t(qs_shp.elem);
	array_number_t stgVar1364 = storage_alloc(size1411);
	array_number_t macroDef1388;env_t_1409 env_t_1409_value = make_empty_env(); closure_t closure1384 = make_closure(lambda1409, &env_t_1409_value);
	env_t_1410 env_t_1410_value = make_empty_env(); closure_t closure1387 = make_closure(lambda1410, &env_t_1410_value);
	macroDef1388 = TOP_LEVEL_linalg_vectorMap_dps(stgVar1362, closure1384, qs_dps->arr[k_dps], closure1387, qs_shp.elem);;
	storage_free(stgVar1364, size1411);
	env_t_1412 env_t_1412_value = make_empty_env(); closure_t closure1391 = make_closure(lambda1412, &env_t_1412_value);
	macroDef1392 = TOP_LEVEL_linalg_sqnorm_dps(empty_storage, macroDef1388, TOP_LEVEL_linalg_vectorMap_shp(closure1391, qs_shp.elem));;
	storage_free(stgVar1362, size1413);
			card_t size1414 = width_card_t(ls_shp.elem);
	array_number_t stgVar1367 = storage_alloc(size1414);
	number_t macroDef1393;
	macroDef1393 = TOP_LEVEL_linalg_sqnorm_dps(empty_storage, ls_dps->arr[k_dps], ls_shp.elem);;
	storage_free(stgVar1367, size1414);
			macroDef1394->arr[k_dps] = (macroDef1392) + (macroDef1393);;
			stgVar1361 = STG_OFFSET(stgVar1361, sizeof(number_t));
		}
	macroDef1395 = TOP_LEVEL_linalg_vectorSum_dps(empty_storage, macroDef1394, K_shp);;
	storage_free(stgVar1360, size1415);
			macroDef1396->arr[i_dps] = ((macroDef1378) - (((double)((n_dps))) * (TOP_LEVEL_usecases_gmm_logsumexp_dps(empty_storage, alphas_dps, alphas_shp)))) + ((0.5) * (macroDef1395));;
			stgVar1343 = STG_OFFSET(stgVar1343, sizeof(number_t));
		}
	macroDef1397 = TOP_LEVEL_linalg_vectorSum_dps(stgVar1335, macroDef1396, n_shp);;
	storage_free(stgVar1342, size1416);
	macroDef1398 = macroDef1397;;
	storage_free(stgVar1338, size1417);
	macroDef1399 = macroDef1398;;
	storage_free(stgVar1336, size1418);
	return macroDef1399;
}

card_t TOP_LEVEL_usecases_gmm_test_gmm_shp(card_t dum_shp) {
	
	return 0;
}


void TOP_LEVEL_usecases_gmm_test_gmm_dps(storage_t stgVar1419, array_number_t dum_dps, card_t dum_shp) {
	card_t a_shp = 3;
	card_t size1447 = width_card_t(a_shp);
	array_number_t stgVar1420 = storage_alloc(size1447);
	array_number_t macroDef1437 = (array_number_t)stgVar1420;
	macroDef1437->length=3;
	macroDef1437->arr=(number_t*)(STG_OFFSET(stgVar1420, VECTOR_HEADER_BYTES));
	macroDef1437->arr[0] = 1;
	macroDef1437->arr[1] = 2;
	macroDef1437->arr[2] = 3;;
	array_number_t a_dps = macroDef1437;
	array_print(a_dps);
	matrix_shape_t mat1_shp = nested_shape_card_t(3, 3);
	card_t size1446 = width_matrix_shape_t(mat1_shp);
	array_number_t stgVar1424 = storage_alloc(size1446);
	array_array_number_t macroDef1441 = (array_array_number_t)stgVar1424;
	macroDef1441->length=3;
	macroDef1441->arr=(array_number_t*)(STG_OFFSET(stgVar1424, VECTOR_HEADER_BYTES));
	int stgVar1424_offsetVar = 0;storage_t stgVar1425 = STG_OFFSET(stgVar1424, MATRIX_HEADER_BYTES(3) + stgVar1424_offsetVar);array_number_t macroDef1438 = (array_number_t)stgVar1425;
	macroDef1438->length=3;
	macroDef1438->arr=(number_t*)(STG_OFFSET(stgVar1425, VECTOR_HEADER_BYTES));
	macroDef1438->arr[0] = 1;
	macroDef1438->arr[1] = 2;
	macroDef1438->arr[2] = 3;;

	macroDef1441->arr[0] = macroDef1438;;stgVar1424_offsetVar += VECTOR_ALL_BYTES(macroDef1441->arr[0]->length);storage_t stgVar1429 = STG_OFFSET(stgVar1424, MATRIX_HEADER_BYTES(3) + stgVar1424_offsetVar);array_number_t macroDef1439 = (array_number_t)stgVar1429;
	macroDef1439->length=3;
	macroDef1439->arr=(number_t*)(STG_OFFSET(stgVar1429, VECTOR_HEADER_BYTES));
	macroDef1439->arr[0] = 4;
	macroDef1439->arr[1] = 5;
	macroDef1439->arr[2] = 6;;

	macroDef1441->arr[1] = macroDef1439;;stgVar1424_offsetVar += VECTOR_ALL_BYTES(macroDef1441->arr[1]->length);storage_t stgVar1433 = STG_OFFSET(stgVar1424, MATRIX_HEADER_BYTES(3) + stgVar1424_offsetVar);array_number_t macroDef1440 = (array_number_t)stgVar1433;
	macroDef1440->length=3;
	macroDef1440->arr=(number_t*)(STG_OFFSET(stgVar1433, VECTOR_HEADER_BYTES));
	macroDef1440->arr[0] = 7;
	macroDef1440->arr[1] = 8;
	macroDef1440->arr[2] = 9;;

	macroDef1441->arr[2] = macroDef1440;;stgVar1424_offsetVar += VECTOR_ALL_BYTES(macroDef1441->arr[2]->length);;
	array_array_number_t mat1_dps = macroDef1441;
	matrix_print(mat1_dps);
	;
	storage_free(stgVar1424, size1446);
	;
	storage_free(stgVar1420, size1447);
	return ;
}
#endif
