#ifndef __LINALG_STORAGED_H__ 
#define __LINALG_STORAGED_H__ 
#include "runtime/fsharp.h"
#include <stdio.h>
#include <math.h>

card_t TOP_LEVEL_linalg_rows_shp(matrix_shape_t m_shp) {
	
	return m_shp.card;
}


card_t TOP_LEVEL_linalg_rows_dps(storage_t stgVar325, array_array_number_t m_dps, matrix_shape_t m_shp) {
	card_t macroDef327 = m_dps->length;
	return macroDef327;
}

card_t TOP_LEVEL_linalg_cols_shp(matrix_shape_t m_shp) {
	
	return m_shp.elem;
}


card_t TOP_LEVEL_linalg_cols_dps(storage_t stgVar328, array_array_number_t m_dps, matrix_shape_t m_shp) {
	card_t size333 = width_card_t(m_shp.elem);
	array_number_t stgVar329 = storage_alloc(size333);
	card_t macroDef332;card_t macroDef331 = m_dps->arr[0]->length;
	macroDef332 = macroDef331;;
	storage_free(stgVar329, size333);
	return macroDef332;
}

card_t TOP_LEVEL_linalg_vectorMap_shp(closure_t f_shp, card_t v_shp) {
	
	return v_shp;
}


array_number_t TOP_LEVEL_linalg_vectorMap_dps(storage_t stgVar334, closure_t f_dps, array_number_t v_dps, closure_t f_shp, card_t v_shp) {
	card_t macroDef339 = v_dps->length;
	array_number_t macroDef340 = (array_number_t)stgVar334;
		macroDef340->length=macroDef339;
		macroDef340->arr=(number_t*)(STG_OFFSET(macroDef340, VECTOR_HEADER_BYTES));
		storage_t stgVar336 = macroDef340;
		for(int i_dps = 0; i_dps < macroDef340->length; i_dps++){
			
			macroDef340->arr[i_dps] = f_dps.lam(f_dps.env, stgVar336, v_dps->arr[i_dps], 0).number_t_value;;
			stgVar336 = STG_OFFSET(stgVar336, sizeof(number_t));
		}
	return macroDef340;
}

card_t TOP_LEVEL_linalg_vectorRange_shp(card_t s_shp, card_t e_shp) {
	
	return ((e_shp) - (s_shp)) + (1);
}


array_number_t TOP_LEVEL_linalg_vectorRange_dps(storage_t stgVar341, card_t s_dps, card_t e_dps, card_t s_shp, card_t e_shp) {
	array_number_t macroDef343 = (array_number_t)stgVar341;
		macroDef343->length=((e_dps) - (s_dps)) + (1);
		macroDef343->arr=(number_t*)(STG_OFFSET(macroDef343, VECTOR_HEADER_BYTES));
		storage_t stgVar342 = macroDef343;
		for(int i_dps = 0; i_dps < macroDef343->length; i_dps++){
			
			macroDef343->arr[i_dps] = (double)(((s_dps)) + (i_dps));;
			stgVar342 = STG_OFFSET(stgVar342, sizeof(number_t));
		}
	return macroDef343;
}

card_t TOP_LEVEL_linalg_vectorSlice_shp(card_t size_shp, card_t offset_shp, card_t v_shp) {
	
	return size_shp;
}


array_number_t TOP_LEVEL_linalg_vectorSlice_dps(storage_t stgVar344, card_t size_dps, index_t offset_dps, array_number_t v_dps, card_t size_shp, card_t offset_shp, card_t v_shp) {
	array_number_t macroDef347 = (array_number_t)stgVar344;
		macroDef347->length=size_dps;
		macroDef347->arr=(number_t*)(STG_OFFSET(macroDef347, VECTOR_HEADER_BYTES));
		storage_t stgVar345 = macroDef347;
		for(int i_dps = 0; i_dps < macroDef347->length; i_dps++){
			
			macroDef347->arr[i_dps] = v_dps->arr[(i_dps) + (offset_dps)];;
			stgVar345 = STG_OFFSET(stgVar345, sizeof(number_t));
		}
	return macroDef347;
}

matrix_shape_t TOP_LEVEL_linalg_matrixMap_shp(closure_t f_shp, matrix_shape_t m_shp) {
	
	return nested_shape_card_t(f_shp.lam(f_shp.env, m_shp.elem).card_t_value, m_shp.card);
}


array_array_number_t TOP_LEVEL_linalg_matrixMap_dps(storage_t stgVar348, closure_t f_dps, array_array_number_t m_dps, closure_t f_shp, matrix_shape_t m_shp) {
	card_t macroDef353 = m_dps->length;
	array_array_number_t macroDef355 = (array_array_number_t)stgVar348;
		macroDef355->length=macroDef353;
		macroDef355->arr=(array_number_t*)(STG_OFFSET(macroDef355, VECTOR_HEADER_BYTES));
		storage_t stgVar350 = (STG_OFFSET(macroDef355, MATRIX_HEADER_BYTES(macroDef353)));
		for(int i_dps = 0; i_dps < macroDef355->length; i_dps++){
			card_t size356 = width_card_t(m_shp.elem);
	array_number_t stgVar351 = storage_alloc(size356);
	array_number_t macroDef354;
	macroDef354 = f_dps.lam(f_dps.env, stgVar350, m_dps->arr[i_dps], m_shp.elem).array_number_t_value;;
	storage_free(stgVar351, size356);
			macroDef355->arr[i_dps] = macroDef354;;
			stgVar350 = STG_OFFSET(stgVar350, VECTOR_ALL_BYTES(macroDef355->arr[i_dps]->length));
		}
	return macroDef355;
}

card_t TOP_LEVEL_linalg_matrixMapToVector_shp(closure_t f_shp, matrix_shape_t m_shp) {
	
	return m_shp.card;
}


array_number_t TOP_LEVEL_linalg_matrixMapToVector_dps(storage_t stgVar357, closure_t f_dps, array_array_number_t m_dps, closure_t f_shp, matrix_shape_t m_shp) {
	card_t macroDef362 = m_dps->length;
	array_number_t macroDef364 = (array_number_t)stgVar357;
		macroDef364->length=macroDef362;
		macroDef364->arr=(number_t*)(STG_OFFSET(macroDef364, VECTOR_HEADER_BYTES));
		storage_t stgVar359 = macroDef364;
		for(int i_dps = 0; i_dps < macroDef364->length; i_dps++){
			card_t size365 = width_card_t(m_shp.elem);
	array_number_t stgVar360 = storage_alloc(size365);
	number_t macroDef363;
	macroDef363 = f_dps.lam(f_dps.env, stgVar359, m_dps->arr[i_dps], m_shp.elem).number_t_value;;
	storage_free(stgVar360, size365);
			macroDef364->arr[i_dps] = macroDef363;;
			stgVar359 = STG_OFFSET(stgVar359, sizeof(number_t));
		}
	return macroDef364;
}

card_t TOP_LEVEL_linalg_vectorMap2_shp(closure_t f_shp, card_t v1_shp, card_t v2_shp) {
	
	return v1_shp;
}


array_number_t TOP_LEVEL_linalg_vectorMap2_dps(storage_t stgVar366, closure_t f_dps, array_number_t v1_dps, array_number_t v2_dps, closure_t f_shp, card_t v1_shp, card_t v2_shp) {
	card_t macroDef373 = v1_dps->length;
	array_number_t macroDef374 = (array_number_t)stgVar366;
		macroDef374->length=macroDef373;
		macroDef374->arr=(number_t*)(STG_OFFSET(macroDef374, VECTOR_HEADER_BYTES));
		storage_t stgVar368 = macroDef374;
		for(int i_dps = 0; i_dps < macroDef374->length; i_dps++){
			
			macroDef374->arr[i_dps] = f_dps.lam(f_dps.env, stgVar368, v1_dps->arr[i_dps], v2_dps->arr[i_dps], 0, 0).number_t_value;;
			stgVar368 = STG_OFFSET(stgVar368, sizeof(number_t));
		}
	return macroDef374;
}

matrix_shape_t TOP_LEVEL_linalg_matrixMap2_shp(closure_t f_shp, matrix_shape_t m1_shp, matrix_shape_t m2_shp) {
	
	return nested_shape_card_t(f_shp.lam(f_shp.env, m1_shp.elem, m2_shp.elem).card_t_value, m1_shp.card);
}


array_array_number_t TOP_LEVEL_linalg_matrixMap2_dps(storage_t stgVar375, closure_t f_dps, array_array_number_t m1_dps, array_array_number_t m2_dps, closure_t f_shp, matrix_shape_t m1_shp, matrix_shape_t m2_shp) {
	card_t macroDef382 = m1_dps->length;
	array_array_number_t macroDef385 = (array_array_number_t)stgVar375;
		macroDef385->length=macroDef382;
		macroDef385->arr=(array_number_t*)(STG_OFFSET(macroDef385, VECTOR_HEADER_BYTES));
		storage_t stgVar377 = (STG_OFFSET(macroDef385, MATRIX_HEADER_BYTES(macroDef382)));
		for(int i_dps = 0; i_dps < macroDef385->length; i_dps++){
			card_t size387 = width_card_t(m2_shp.elem);
	array_number_t stgVar379 = storage_alloc(size387);
	array_number_t macroDef384;card_t size386 = width_card_t(m1_shp.elem);
	array_number_t stgVar378 = storage_alloc(size386);
	array_number_t macroDef383;
	macroDef383 = f_dps.lam(f_dps.env, stgVar377, m1_dps->arr[i_dps], m2_dps->arr[i_dps], m1_shp.elem, m2_shp.elem).array_number_t_value;;
	storage_free(stgVar378, size386);
	macroDef384 = macroDef383;;
	storage_free(stgVar379, size387);
			macroDef385->arr[i_dps] = macroDef384;;
			stgVar377 = STG_OFFSET(stgVar377, VECTOR_ALL_BYTES(macroDef385->arr[i_dps]->length));
		}
	return macroDef385;
}

matrix3d_shape_t TOP_LEVEL_linalg_matrix3DMap2_shp(closure_t f_shp, matrix3d_shape_t m1_shp, matrix3d_shape_t m2_shp) {
	
	return nested_shape_matrix_shape_t(f_shp.lam(f_shp.env, m1_shp.elem, m2_shp.elem).matrix_shape_t_value, m1_shp.card);
}


array_array_array_number_t TOP_LEVEL_linalg_matrix3DMap2_dps(storage_t stgVar388, closure_t f_dps, array_array_array_number_t m1_dps, array_array_array_number_t m2_dps, closure_t f_shp, matrix3d_shape_t m1_shp, matrix3d_shape_t m2_shp) {
	card_t macroDef395 = m1_dps->length;
	array_array_array_number_t macroDef398 = (array_array_array_number_t)stgVar388;
		macroDef398->length=macroDef395;
		macroDef398->arr=(array_array_number_t*)(STG_OFFSET(macroDef398, VECTOR_HEADER_BYTES));
		storage_t stgVar390 = (STG_OFFSET(macroDef398, MATRIX_HEADER_BYTES(macroDef395)));
		for(int i_dps = 0; i_dps < macroDef398->length; i_dps++){
			card_t size400 = width_matrix_shape_t(m2_shp.elem);
	array_number_t stgVar392 = storage_alloc(size400);
	array_array_number_t macroDef397;card_t size399 = width_matrix_shape_t(m1_shp.elem);
	array_number_t stgVar391 = storage_alloc(size399);
	array_array_number_t macroDef396;
	macroDef396 = f_dps.lam(f_dps.env, stgVar390, m1_dps->arr[i_dps], m2_dps->arr[i_dps], m1_shp.elem, m2_shp.elem).array_array_number_t_value;;
	storage_free(stgVar391, size399);
	macroDef397 = macroDef396;;
	storage_free(stgVar392, size400);
			macroDef398->arr[i_dps] = macroDef397;;
			stgVar390 = STG_OFFSET(stgVar390, VECTOR_ALL_BYTES(macroDef398->arr[i_dps]->length));
		}
	return macroDef398;
}

matrix_shape_t TOP_LEVEL_linalg_vectorMapToMatrix_shp(closure_t f_shp, card_t arr_shp) {
	
	return nested_shape_card_t(f_shp.lam(f_shp.env, 0).card_t_value, arr_shp);
}


array_array_number_t TOP_LEVEL_linalg_vectorMapToMatrix_dps(storage_t stgVar401, closure_t f_dps, array_number_t arr_dps, closure_t f_shp, card_t arr_shp) {
	card_t macroDef406 = arr_dps->length;
	array_array_number_t macroDef407 = (array_array_number_t)stgVar401;
		macroDef407->length=macroDef406;
		macroDef407->arr=(array_number_t*)(STG_OFFSET(macroDef407, VECTOR_HEADER_BYTES));
		storage_t stgVar403 = (STG_OFFSET(macroDef407, MATRIX_HEADER_BYTES(macroDef406)));
		for(int i_dps = 0; i_dps < macroDef407->length; i_dps++){
			
			macroDef407->arr[i_dps] = f_dps.lam(f_dps.env, stgVar403, arr_dps->arr[i_dps], 0).array_number_t_value;;
			stgVar403 = STG_OFFSET(stgVar403, VECTOR_ALL_BYTES(macroDef407->arr[i_dps]->length));
		}
	return macroDef407;
}

matrix3d_shape_t TOP_LEVEL_linalg_vectorMapToMatrix3D_shp(closure_t f_shp, card_t arr_shp) {
	
	return nested_shape_matrix_shape_t(f_shp.lam(f_shp.env, 0).matrix_shape_t_value, arr_shp);
}


array_array_array_number_t TOP_LEVEL_linalg_vectorMapToMatrix3D_dps(storage_t stgVar408, closure_t f_dps, array_number_t arr_dps, closure_t f_shp, card_t arr_shp) {
	card_t macroDef413 = arr_dps->length;
	array_array_array_number_t macroDef414 = (array_array_array_number_t)stgVar408;
		macroDef414->length=macroDef413;
		macroDef414->arr=(array_array_number_t*)(STG_OFFSET(macroDef414, VECTOR_HEADER_BYTES));
		storage_t stgVar410 = (STG_OFFSET(macroDef414, MATRIX_HEADER_BYTES(macroDef413)));
		for(int i_dps = 0; i_dps < macroDef414->length; i_dps++){
			
			macroDef414->arr[i_dps] = f_dps.lam(f_dps.env, stgVar410, arr_dps->arr[i_dps], 0).array_array_number_t_value;;
			stgVar410 = STG_OFFSET(stgVar410, VECTOR_ALL_BYTES(macroDef414->arr[i_dps]->length));
		}
	return macroDef414;
}

card_t TOP_LEVEL_linalg_iterateNumber_shp(closure_t f_shp, card_t z_shp, card_t s_shp, card_t e_shp) {
	
	return 0;
}


number_t TOP_LEVEL_linalg_iterateNumber_dps(storage_t stgVar415, closure_t f_dps, number_t z_dps, card_t s_dps, card_t e_dps, closure_t f_shp, card_t z_shp, card_t s_shp, card_t e_shp) {
	number_t macroDef421 = z_dps;
	array_number_t cur_dps_range = TOP_LEVEL_linalg_vectorRange_dps(empty_storage, s_dps, e_dps, s_shp, e_shp);
	storage_t stgVar416 = stgVar415;
	for(int cur_dps_idx = 0; cur_dps_idx < cur_dps_range->length; cur_dps_idx++){
		number_t cur_dps = cur_dps_range->arr[cur_dps_idx];
		
		macroDef421 = f_dps.lam(f_dps.env, stgVar416, macroDef421, (int)(cur_dps), 0, 0).number_t_value;;
	}
	return macroDef421;
}

card_t TOP_LEVEL_linalg_iterateVector_shp(closure_t f_shp, card_t z_shp, card_t s_shp, card_t e_shp) {
	
	return z_shp;
}


array_number_t TOP_LEVEL_linalg_iterateVector_dps(storage_t stgVar422, closure_t f_dps, array_number_t z_dps, card_t s_dps, card_t e_dps, closure_t f_shp, card_t z_shp, card_t s_shp, card_t e_shp) {
	array_number_t macroDef428 = z_dps;
	array_number_t cur_dps_range = TOP_LEVEL_linalg_vectorRange_dps(empty_storage, s_dps, e_dps, s_shp, e_shp);
	storage_t stgVar423 = stgVar422;
	for(int cur_dps_idx = 0; cur_dps_idx < cur_dps_range->length; cur_dps_idx++){
		number_t cur_dps = cur_dps_range->arr[cur_dps_idx];
		
		macroDef428 = f_dps.lam(f_dps.env, stgVar423, macroDef428, (int)(cur_dps), z_shp, 0).array_number_t_value;;
	}
	return macroDef428;
}

matrix_shape_t TOP_LEVEL_linalg_iterateMatrix_shp(closure_t f_shp, matrix_shape_t z_shp, card_t s_shp, card_t e_shp) {
	
	return z_shp;
}


array_array_number_t TOP_LEVEL_linalg_iterateMatrix_dps(storage_t stgVar429, closure_t f_dps, array_array_number_t z_dps, card_t s_dps, card_t e_dps, closure_t f_shp, matrix_shape_t z_shp, card_t s_shp, card_t e_shp) {
	array_array_number_t macroDef435 = z_dps;
	array_number_t cur_dps_range = TOP_LEVEL_linalg_vectorRange_dps(empty_storage, s_dps, e_dps, s_shp, e_shp);
	storage_t stgVar430 = stgVar429;
	for(int cur_dps_idx = 0; cur_dps_idx < cur_dps_range->length; cur_dps_idx++){
		number_t cur_dps = cur_dps_range->arr[cur_dps_idx];
		
		macroDef435 = f_dps.lam(f_dps.env, stgVar430, macroDef435, (int)(cur_dps), z_shp, 0).array_array_number_t_value;;
	}
	return macroDef435;
}

matrix3d_shape_t TOP_LEVEL_linalg_iterateMatrix3D_shp(closure_t f_shp, matrix3d_shape_t z_shp, card_t s_shp, card_t e_shp) {
	
	return z_shp;
}


array_array_array_number_t TOP_LEVEL_linalg_iterateMatrix3D_dps(storage_t stgVar436, closure_t f_dps, array_array_array_number_t z_dps, card_t s_dps, card_t e_dps, closure_t f_shp, matrix3d_shape_t z_shp, card_t s_shp, card_t e_shp) {
	array_array_array_number_t macroDef442 = z_dps;
	array_number_t cur_dps_range = TOP_LEVEL_linalg_vectorRange_dps(empty_storage, s_dps, e_dps, s_shp, e_shp);
	storage_t stgVar437 = stgVar436;
	for(int cur_dps_idx = 0; cur_dps_idx < cur_dps_range->length; cur_dps_idx++){
		number_t cur_dps = cur_dps_range->arr[cur_dps_idx];
		
		macroDef442 = f_dps.lam(f_dps.env, stgVar437, macroDef442, (int)(cur_dps), z_shp, 0).array_array_array_number_t_value;;
	}
	return macroDef442;
}

card_t TOP_LEVEL_linalg_vectorSum_shp(card_t v_shp) {
	
	return 0;
}


number_t TOP_LEVEL_linalg_vectorSum_dps(storage_t stgVar443, array_number_t v_dps, card_t v_shp) {
	number_t macroDef445 = 0;
	array_number_t cur_dps_range = v_dps;
	storage_t stgVar444 = stgVar443;
	for(int cur_dps_idx = 0; cur_dps_idx < cur_dps_range->length; cur_dps_idx++){
		number_t cur_dps = cur_dps_range->arr[cur_dps_idx];
		
		macroDef445 = (macroDef445) + (cur_dps);;
	}
	return macroDef445;
}

card_t TOP_LEVEL_linalg_vectorMax_shp(card_t v_shp) {
	
	return 0;
}


number_t TOP_LEVEL_linalg_vectorMax_dps(storage_t stgVar446, array_number_t v_dps, card_t v_shp) {
	number_t macroDef448 = -1000;
	array_number_t cur_dps_range = v_dps;
	storage_t stgVar447 = stgVar446;
	for(int cur_dps_idx = 0; cur_dps_idx < cur_dps_range->length; cur_dps_idx++){
		number_t cur_dps = cur_dps_range->arr[cur_dps_idx];
		number_t ite449 = 0;
	if((macroDef448) > (cur_dps)) {
		
		ite449 = macroDef448;;
	} else {
		
		ite449 = cur_dps;;
	}
		macroDef448 = ite449;;
	}
	return macroDef448;
}
typedef empty_env_t env_t_457;


value_t lambda457(env_t_457* env454, card_t xi_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
card_t TOP_LEVEL_linalg_mult_by_scalar_shp(card_t x_shp, card_t y_shp) {
	env_t_457 env_t_457_value = make_empty_env(); closure_t closure456 = make_closure(lambda457, &env_t_457_value);
	return TOP_LEVEL_linalg_vectorMap_shp(closure456, x_shp);
}

typedef struct env_t_465 {
	number_t y_dps;
} env_t_465;
env_t_465 make_env_t_465(number_t y_dps) {
	env_t_465 env;
	env.y_dps = y_dps;
	return env;
}

value_t lambda465(env_t_465* env459, storage_t stgVar453, number_t xi_dps, card_t xi_shp) {
	number_t y_dps458 = env459->y_dps;
	value_t res;
	res.number_t_value = (xi_dps) * (y_dps458);
	return res;
}
typedef empty_env_t env_t_466;


value_t lambda466(env_t_466* env462, card_t xi_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
array_number_t TOP_LEVEL_linalg_mult_by_scalar_dps(storage_t stgVar450, array_number_t x_dps, number_t y_dps, card_t x_shp, card_t y_shp) {
	env_t_465 env_t_465_value = make_env_t_465(y_dps); closure_t closure461 = make_closure(lambda465, &env_t_465_value);
	env_t_466 env_t_466_value = make_empty_env(); closure_t closure464 = make_closure(lambda466, &env_t_466_value);
	return TOP_LEVEL_linalg_vectorMap_dps(stgVar450, closure461, x_dps, closure464, x_shp);
}
typedef empty_env_t env_t_474;


value_t lambda474(env_t_474* env471, card_t xi_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
card_t TOP_LEVEL_linalg_gaxpy_shp(card_t a_shp, card_t x_shp, card_t y_shp) {
	env_t_474 env_t_474_value = make_empty_env(); closure_t closure473 = make_closure(lambda474, &env_t_474_value);
	return TOP_LEVEL_linalg_vectorMap_shp(closure473, x_shp);
}

typedef struct env_t_483 {
	number_t y_dps;
	number_t a_dps;
} env_t_483;
env_t_483 make_env_t_483(number_t y_dps,number_t a_dps) {
	env_t_483 env;
	env.y_dps = y_dps;
	env.a_dps = a_dps;
	return env;
}

value_t lambda483(env_t_483* env477, storage_t stgVar470, number_t xi_dps, card_t xi_shp) {
	number_t y_dps476 = env477->y_dps;
	number_t a_dps475 = env477->a_dps;
	value_t res;
	res.number_t_value = ((a_dps475) * (xi_dps)) + (y_dps476);
	return res;
}
typedef empty_env_t env_t_484;


value_t lambda484(env_t_484* env480, card_t xi_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
array_number_t TOP_LEVEL_linalg_gaxpy_dps(storage_t stgVar467, number_t a_dps, array_number_t x_dps, number_t y_dps, card_t a_shp, card_t x_shp, card_t y_shp) {
	env_t_483 env_t_483_value = make_env_t_483(y_dps,a_dps); closure_t closure479 = make_closure(lambda483, &env_t_483_value);
	env_t_484 env_t_484_value = make_empty_env(); closure_t closure482 = make_closure(lambda484, &env_t_484_value);
	return TOP_LEVEL_linalg_vectorMap_dps(stgVar467, closure479, x_dps, closure482, x_shp);
}

card_t TOP_LEVEL_linalg_cross_shp(card_t a_shp, card_t b_shp) {
	
	return 3;
}


array_number_t TOP_LEVEL_linalg_cross_dps(storage_t stgVar485, array_number_t a_dps, array_number_t b_dps, card_t a_shp, card_t b_shp) {
	array_number_t macroDef501 = (array_number_t)stgVar485;
	macroDef501->length=3;
	macroDef501->arr=(number_t*)(STG_OFFSET(stgVar485, VECTOR_HEADER_BYTES));
	macroDef501->arr[0] = ((a_dps->arr[1]) * (b_dps->arr[2])) - ((a_dps->arr[2]) * (b_dps->arr[1]));
	macroDef501->arr[1] = ((a_dps->arr[2]) * (b_dps->arr[0])) - ((a_dps->arr[0]) * (b_dps->arr[2]));
	macroDef501->arr[2] = ((a_dps->arr[0]) * (b_dps->arr[1])) - ((a_dps->arr[1]) * (b_dps->arr[0]));;
	return macroDef501;
}
typedef empty_env_t env_t_510;


value_t lambda510(env_t_510* env507, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
card_t TOP_LEVEL_linalg_vectorAdd_shp(card_t x_shp, card_t y_shp) {
	env_t_510 env_t_510_value = make_empty_env(); closure_t closure509 = make_closure(lambda510, &env_t_510_value);
	return TOP_LEVEL_linalg_vectorMap2_shp(closure509, x_shp, y_shp);
}

typedef empty_env_t env_t_517;


value_t lambda517(env_t_517* env511, storage_t stgVar506, number_t x_dps0, number_t y_dps0, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.number_t_value = (x_dps0) + (y_dps0);
	return res;
}
typedef empty_env_t env_t_518;


value_t lambda518(env_t_518* env514, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
array_number_t TOP_LEVEL_linalg_vectorAdd_dps(storage_t stgVar502, array_number_t x_dps, array_number_t y_dps, card_t x_shp, card_t y_shp) {
	env_t_517 env_t_517_value = make_empty_env(); closure_t closure513 = make_closure(lambda517, &env_t_517_value);
	env_t_518 env_t_518_value = make_empty_env(); closure_t closure516 = make_closure(lambda518, &env_t_518_value);
	return TOP_LEVEL_linalg_vectorMap2_dps(stgVar502, closure513, x_dps, y_dps, closure516, x_shp, y_shp);
}
typedef empty_env_t env_t_527;


value_t lambda527(env_t_527* env524, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
card_t TOP_LEVEL_linalg_mult_vec_elementwise_shp(card_t x_shp, card_t y_shp) {
	env_t_527 env_t_527_value = make_empty_env(); closure_t closure526 = make_closure(lambda527, &env_t_527_value);
	return TOP_LEVEL_linalg_vectorMap2_shp(closure526, x_shp, y_shp);
}

typedef empty_env_t env_t_534;


value_t lambda534(env_t_534* env528, storage_t stgVar523, number_t x_dps0, number_t y_dps0, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.number_t_value = (x_dps0) * (y_dps0);
	return res;
}
typedef empty_env_t env_t_535;


value_t lambda535(env_t_535* env531, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
array_number_t TOP_LEVEL_linalg_mult_vec_elementwise_dps(storage_t stgVar519, array_number_t x_dps, array_number_t y_dps, card_t x_shp, card_t y_shp) {
	env_t_534 env_t_534_value = make_empty_env(); closure_t closure530 = make_closure(lambda534, &env_t_534_value);
	env_t_535 env_t_535_value = make_empty_env(); closure_t closure533 = make_closure(lambda535, &env_t_535_value);
	return TOP_LEVEL_linalg_vectorMap2_dps(stgVar519, closure530, x_dps, y_dps, closure533, x_shp, y_shp);
}
typedef empty_env_t env_t_544;


value_t lambda544(env_t_544* env541, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
card_t TOP_LEVEL_linalg_op_DotMultiply_shp(card_t x_shp, card_t y_shp) {
	env_t_544 env_t_544_value = make_empty_env(); closure_t closure543 = make_closure(lambda544, &env_t_544_value);
	return TOP_LEVEL_linalg_vectorMap2_shp(closure543, x_shp, y_shp);
}

typedef empty_env_t env_t_551;


value_t lambda551(env_t_551* env545, storage_t stgVar540, number_t x_dps0, number_t y_dps0, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.number_t_value = (x_dps0) * (y_dps0);
	return res;
}
typedef empty_env_t env_t_552;


value_t lambda552(env_t_552* env548, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
array_number_t TOP_LEVEL_linalg_op_DotMultiply_dps(storage_t stgVar536, array_number_t x_dps, array_number_t y_dps, card_t x_shp, card_t y_shp) {
	env_t_551 env_t_551_value = make_empty_env(); closure_t closure547 = make_closure(lambda551, &env_t_551_value);
	env_t_552 env_t_552_value = make_empty_env(); closure_t closure550 = make_closure(lambda552, &env_t_552_value);
	return TOP_LEVEL_linalg_vectorMap2_dps(stgVar536, closure547, x_dps, y_dps, closure550, x_shp, y_shp);
}

card_t TOP_LEVEL_linalg_vectorAdd3_shp(card_t x_shp, card_t y_shp, card_t z_shp) {
	
	return TOP_LEVEL_linalg_vectorAdd_shp(TOP_LEVEL_linalg_vectorAdd_shp(x_shp, y_shp), z_shp);
}


array_number_t TOP_LEVEL_linalg_vectorAdd3_dps(storage_t stgVar553, array_number_t x_dps, array_number_t y_dps, array_number_t z_dps, card_t x_shp, card_t y_shp, card_t z_shp) {
	card_t size559 = width_card_t(TOP_LEVEL_linalg_vectorAdd_shp(x_shp, y_shp));
	array_number_t stgVar554 = storage_alloc(size559);
	array_number_t macroDef558;
	macroDef558 = TOP_LEVEL_linalg_vectorAdd_dps(stgVar553, TOP_LEVEL_linalg_vectorAdd_dps(stgVar554, x_dps, y_dps, x_shp, y_shp), z_dps, TOP_LEVEL_linalg_vectorAdd_shp(x_shp, y_shp), z_shp);;
	storage_free(stgVar554, size559);
	return macroDef558;
}
typedef empty_env_t env_t_568;


value_t lambda568(env_t_568* env565, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
card_t TOP_LEVEL_linalg_vectorSub_shp(card_t x_shp, card_t y_shp) {
	env_t_568 env_t_568_value = make_empty_env(); closure_t closure567 = make_closure(lambda568, &env_t_568_value);
	return TOP_LEVEL_linalg_vectorMap2_shp(closure567, x_shp, y_shp);
}

typedef empty_env_t env_t_575;


value_t lambda575(env_t_575* env569, storage_t stgVar564, number_t x_dps0, number_t y_dps0, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.number_t_value = (x_dps0) - (y_dps0);
	return res;
}
typedef empty_env_t env_t_576;


value_t lambda576(env_t_576* env572, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
array_number_t TOP_LEVEL_linalg_vectorSub_dps(storage_t stgVar560, array_number_t x_dps, array_number_t y_dps, card_t x_shp, card_t y_shp) {
	env_t_575 env_t_575_value = make_empty_env(); closure_t closure571 = make_closure(lambda575, &env_t_575_value);
	env_t_576 env_t_576_value = make_empty_env(); closure_t closure574 = make_closure(lambda576, &env_t_576_value);
	return TOP_LEVEL_linalg_vectorMap2_dps(stgVar560, closure571, x_dps, y_dps, closure574, x_shp, y_shp);
}
typedef empty_env_t env_t_587;


value_t lambda587(env_t_587* env584, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = TOP_LEVEL_linalg_vectorAdd_shp(x_shp0, y_shp0);
	return res;
}
matrix_shape_t TOP_LEVEL_linalg_matrixAdd_shp(matrix_shape_t x_shp, matrix_shape_t y_shp) {
	env_t_587 env_t_587_value = make_empty_env(); closure_t closure586 = make_closure(lambda587, &env_t_587_value);
	return TOP_LEVEL_linalg_matrixMap2_shp(closure586, x_shp, y_shp);
}

typedef empty_env_t env_t_594;


value_t lambda594(env_t_594* env588, storage_t stgVar581, array_number_t x_dps0, array_number_t y_dps0, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.array_number_t_value = TOP_LEVEL_linalg_vectorAdd_dps(stgVar581, x_dps0, y_dps0, x_shp0, y_shp0);
	return res;
}
typedef empty_env_t env_t_595;


value_t lambda595(env_t_595* env591, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = TOP_LEVEL_linalg_vectorAdd_shp(x_shp0, y_shp0);
	return res;
}
array_array_number_t TOP_LEVEL_linalg_matrixAdd_dps(storage_t stgVar577, array_array_number_t x_dps, array_array_number_t y_dps, matrix_shape_t x_shp, matrix_shape_t y_shp) {
	env_t_594 env_t_594_value = make_empty_env(); closure_t closure590 = make_closure(lambda594, &env_t_594_value);
	env_t_595 env_t_595_value = make_empty_env(); closure_t closure593 = make_closure(lambda595, &env_t_595_value);
	return TOP_LEVEL_linalg_matrixMap2_dps(stgVar577, closure590, x_dps, y_dps, closure593, x_shp, y_shp);
}
typedef empty_env_t env_t_606;


value_t lambda606(env_t_606* env603, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = TOP_LEVEL_linalg_mult_vec_elementwise_shp(x_shp0, y_shp0);
	return res;
}
matrix_shape_t TOP_LEVEL_linalg_matrixMultElementwise_shp(matrix_shape_t x_shp, matrix_shape_t y_shp) {
	env_t_606 env_t_606_value = make_empty_env(); closure_t closure605 = make_closure(lambda606, &env_t_606_value);
	return TOP_LEVEL_linalg_matrixMap2_shp(closure605, x_shp, y_shp);
}

typedef empty_env_t env_t_613;


value_t lambda613(env_t_613* env607, storage_t stgVar600, array_number_t x_dps0, array_number_t y_dps0, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.array_number_t_value = TOP_LEVEL_linalg_mult_vec_elementwise_dps(stgVar600, x_dps0, y_dps0, x_shp0, y_shp0);
	return res;
}
typedef empty_env_t env_t_614;


value_t lambda614(env_t_614* env610, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = TOP_LEVEL_linalg_mult_vec_elementwise_shp(x_shp0, y_shp0);
	return res;
}
array_array_number_t TOP_LEVEL_linalg_matrixMultElementwise_dps(storage_t stgVar596, array_array_number_t x_dps, array_array_number_t y_dps, matrix_shape_t x_shp, matrix_shape_t y_shp) {
	env_t_613 env_t_613_value = make_empty_env(); closure_t closure609 = make_closure(lambda613, &env_t_613_value);
	env_t_614 env_t_614_value = make_empty_env(); closure_t closure612 = make_closure(lambda614, &env_t_614_value);
	return TOP_LEVEL_linalg_matrixMap2_dps(stgVar596, closure609, x_dps, y_dps, closure612, x_shp, y_shp);
}

card_t TOP_LEVEL_linalg_sqnorm_shp(card_t x_shp) {
	
	return 0;
}

typedef empty_env_t env_t_633;


value_t lambda633(env_t_633* env620, card_t x1_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef empty_env_t env_t_634;


value_t lambda634(env_t_634* env623, storage_t stgVar619, number_t x1_dps, card_t x1_shp) {
	
	value_t res;
	res.number_t_value = (x1_dps) * (x1_dps);
	return res;
}
typedef empty_env_t env_t_635;


value_t lambda635(env_t_635* env626, card_t x1_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef empty_env_t env_t_636;


value_t lambda636(env_t_636* env629, card_t x1_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
number_t TOP_LEVEL_linalg_sqnorm_dps(storage_t stgVar615, array_number_t x_dps, card_t x_shp) {
	env_t_633 env_t_633_value = make_empty_env(); closure_t closure622 = make_closure(lambda633, &env_t_633_value);
	card_t size637 = width_card_t(TOP_LEVEL_linalg_vectorMap_shp(closure622, x_shp));
	array_number_t stgVar616 = storage_alloc(size637);
	number_t macroDef632;env_t_634 env_t_634_value = make_empty_env(); closure_t closure625 = make_closure(lambda634, &env_t_634_value);
	env_t_635 env_t_635_value = make_empty_env(); closure_t closure628 = make_closure(lambda635, &env_t_635_value);
	env_t_636 env_t_636_value = make_empty_env(); closure_t closure631 = make_closure(lambda636, &env_t_636_value);
	macroDef632 = TOP_LEVEL_linalg_vectorSum_dps(stgVar615, TOP_LEVEL_linalg_vectorMap_dps(stgVar616, closure625, x_dps, closure628, x_shp), TOP_LEVEL_linalg_vectorMap_shp(closure631, x_shp));;
	storage_free(stgVar616, size637);
	return macroDef632;
}

card_t TOP_LEVEL_linalg_dot_prod_shp(card_t x_shp, card_t y_shp) {
	
	return 0;
}

typedef empty_env_t env_t_657;


value_t lambda657(env_t_657* env644, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef empty_env_t env_t_658;


value_t lambda658(env_t_658* env647, storage_t stgVar643, number_t x_dps0, number_t y_dps0, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.number_t_value = (x_dps0) * (y_dps0);
	return res;
}
typedef empty_env_t env_t_659;


value_t lambda659(env_t_659* env650, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef empty_env_t env_t_660;


value_t lambda660(env_t_660* env653, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
number_t TOP_LEVEL_linalg_dot_prod_dps(storage_t stgVar638, array_number_t x_dps, array_number_t y_dps, card_t x_shp, card_t y_shp) {
	env_t_657 env_t_657_value = make_empty_env(); closure_t closure646 = make_closure(lambda657, &env_t_657_value);
	card_t size661 = width_card_t(TOP_LEVEL_linalg_vectorMap2_shp(closure646, x_shp, y_shp));
	array_number_t stgVar639 = storage_alloc(size661);
	number_t macroDef656;env_t_658 env_t_658_value = make_empty_env(); closure_t closure649 = make_closure(lambda658, &env_t_658_value);
	env_t_659 env_t_659_value = make_empty_env(); closure_t closure652 = make_closure(lambda659, &env_t_659_value);
	env_t_660 env_t_660_value = make_empty_env(); closure_t closure655 = make_closure(lambda660, &env_t_660_value);
	macroDef656 = TOP_LEVEL_linalg_vectorSum_dps(stgVar638, TOP_LEVEL_linalg_vectorMap2_dps(stgVar639, closure649, x_dps, y_dps, closure652, x_shp, y_shp), TOP_LEVEL_linalg_vectorMap2_shp(closure655, x_shp, y_shp));;
	storage_free(stgVar639, size661);
	return macroDef656;
}
typedef struct env_t_672 {
	card_t row_shp;
} env_t_672;
env_t_672 make_env_t_672(card_t row_shp) {
	env_t_672 env;
	env.row_shp = row_shp;
	return env;
}

value_t lambda672(env_t_672* env669, card_t r_shp) {
	card_t row_shp668 = env669->row_shp;
	value_t res;
	res.card_t_value = row_shp668;
	return res;
}
matrix_shape_t TOP_LEVEL_linalg_matrixFillFromVector_shp(card_t rows_shp, card_t row_shp) {
	env_t_672 env_t_672_value = make_env_t_672(row_shp); closure_t closure671 = make_closure(lambda672, &env_t_672_value);
	return TOP_LEVEL_linalg_vectorMapToMatrix_shp(closure671, TOP_LEVEL_linalg_vectorRange_shp(1, rows_shp));
}

typedef struct env_t_682 {
	array_number_t row_dps;
} env_t_682;
env_t_682 make_env_t_682(array_number_t row_dps) {
	env_t_682 env;
	env.row_dps = row_dps;
	return env;
}

value_t lambda682(env_t_682* env674, storage_t stgVar665, number_t r_dps, card_t r_shp) {
	array_number_t row_dps673 = env674->row_dps;
	value_t res;
	res.array_number_t_value = row_dps673;
	return res;
}
typedef struct env_t_683 {
	card_t row_shp;
} env_t_683;
env_t_683 make_env_t_683(card_t row_shp) {
	env_t_683 env;
	env.row_shp = row_shp;
	return env;
}

value_t lambda683(env_t_683* env678, card_t r_shp) {
	card_t row_shp677 = env678->row_shp;
	value_t res;
	res.card_t_value = row_shp677;
	return res;
}
array_array_number_t TOP_LEVEL_linalg_matrixFillFromVector_dps(storage_t stgVar662, card_t rows_dps, array_number_t row_dps, card_t rows_shp, card_t row_shp) {
	card_t size684 = width_card_t(TOP_LEVEL_linalg_vectorRange_shp(1, rows_shp));
	array_number_t stgVar664 = storage_alloc(size684);
	array_array_number_t macroDef681;env_t_682 env_t_682_value = make_env_t_682(row_dps); closure_t closure676 = make_closure(lambda682, &env_t_682_value);
	env_t_683 env_t_683_value = make_env_t_683(row_shp); closure_t closure680 = make_closure(lambda683, &env_t_683_value);
	macroDef681 = TOP_LEVEL_linalg_vectorMapToMatrix_dps(stgVar662, closure676, TOP_LEVEL_linalg_vectorRange_dps(stgVar664, 1, rows_dps, 1, rows_shp), closure680, TOP_LEVEL_linalg_vectorRange_shp(1, rows_shp));;
	storage_free(stgVar664, size684);
	return macroDef681;
}

matrix_shape_t TOP_LEVEL_linalg_matrixFill_shp(card_t rows_shp, card_t cols_shp, card_t value_shp) {
	
	return nested_shape_card_t(cols_shp, rows_shp);
}


array_array_number_t TOP_LEVEL_linalg_matrixFill_dps(storage_t stgVar685, card_t rows_dps, card_t cols_dps, number_t value_dps, card_t rows_shp, card_t cols_shp, card_t value_shp) {
	array_array_number_t macroDef689 = (array_array_number_t)stgVar685;
		macroDef689->length=rows_dps;
		macroDef689->arr=(array_number_t*)(STG_OFFSET(macroDef689, VECTOR_HEADER_BYTES));
		storage_t stgVar686 = (STG_OFFSET(macroDef689, MATRIX_HEADER_BYTES(rows_dps)));
		for(int r_dps = 0; r_dps < macroDef689->length; r_dps++){
			array_number_t macroDef688 = (array_number_t)stgVar686;
		macroDef688->length=cols_dps;
		macroDef688->arr=(number_t*)(STG_OFFSET(macroDef688, VECTOR_HEADER_BYTES));
		storage_t stgVar687 = macroDef688;
		for(int c_dps = 0; c_dps < macroDef688->length; c_dps++){
			
			macroDef688->arr[c_dps] = value_dps;;
			stgVar687 = STG_OFFSET(stgVar687, sizeof(number_t));
		}
			macroDef689->arr[r_dps] = macroDef688;;
			stgVar686 = STG_OFFSET(stgVar686, VECTOR_ALL_BYTES(macroDef689->arr[r_dps]->length));
		}
	return macroDef689;
}

matrix_shape_t TOP_LEVEL_linalg_matrixTranspose_shp(matrix_shape_t m_shp) {
	
	return nested_shape_card_t(m_shp.card, m_shp.elem);
}


array_array_number_t TOP_LEVEL_linalg_matrixTranspose_dps(storage_t stgVar690, array_array_number_t m_dps, matrix_shape_t m_shp) {
	card_t rows_shp = m_shp.card;
	card_t macroDef702 = m_dps->length;
	card_t rows_dps = macroDef702;
	card_t cols_shp = m_shp.elem;
	card_t size708 = width_card_t(m_shp.elem);
	array_number_t stgVar694 = storage_alloc(size708);
	card_t macroDef704;card_t macroDef703 = m_dps->arr[0]->length;
	macroDef704 = macroDef703;;
	storage_free(stgVar694, size708);
	card_t cols_dps = macroDef704;
	array_array_number_t macroDef707 = (array_array_number_t)stgVar690;
		macroDef707->length=cols_dps;
		macroDef707->arr=(array_number_t*)(STG_OFFSET(macroDef707, VECTOR_HEADER_BYTES));
		storage_t stgVar696 = (STG_OFFSET(macroDef707, MATRIX_HEADER_BYTES(cols_dps)));
		for(int i_dps = 0; i_dps < macroDef707->length; i_dps++){
			array_number_t macroDef706 = (array_number_t)stgVar696;
		macroDef706->length=rows_dps;
		macroDef706->arr=(number_t*)(STG_OFFSET(macroDef706, VECTOR_HEADER_BYTES));
		storage_t stgVar697 = macroDef706;
		for(int j_dps = 0; j_dps < macroDef706->length; j_dps++){
			card_t size709 = width_card_t(m_shp.elem);
	array_number_t stgVar698 = storage_alloc(size709);
	number_t macroDef705;
	macroDef705 = m_dps->arr[j_dps]->arr[i_dps];;
	storage_free(stgVar698, size709);
			macroDef706->arr[j_dps] = macroDef705;;
			stgVar697 = STG_OFFSET(stgVar697, sizeof(number_t));
		}
			macroDef707->arr[i_dps] = macroDef706;;
			stgVar696 = STG_OFFSET(stgVar696, VECTOR_ALL_BYTES(macroDef707->arr[i_dps]->length));
		}
	return macroDef707;
}

matrix_shape_t TOP_LEVEL_linalg_matrixMult_shp(matrix_shape_t m1_shp, matrix_shape_t m2_shp) {
	
	return nested_shape_card_t(m2_shp.elem, m1_shp.card);
}


array_array_number_t TOP_LEVEL_linalg_matrixMult_dps(storage_t stgVar710, array_array_number_t m1_dps, array_array_number_t m2_dps, matrix_shape_t m1_shp, matrix_shape_t m2_shp) {
	card_t r1_shp = m1_shp.card;
	card_t macroDef749 = m1_dps->length;
	card_t r1_dps = macroDef749;
	card_t c2_shp = m2_shp.elem;
	card_t size760 = width_card_t(m2_shp.elem);
	array_number_t stgVar714 = storage_alloc(size760);
	card_t macroDef751;card_t macroDef750 = m2_dps->arr[0]->length;
	macroDef751 = macroDef750;;
	storage_free(stgVar714, size760);
	card_t c2_dps = macroDef751;
	card_t c1_shp = m1_shp.elem;
	card_t size761 = width_card_t(m1_shp.elem);
	array_number_t stgVar717 = storage_alloc(size761);
	card_t macroDef753;card_t macroDef752 = m1_dps->arr[0]->length;
	macroDef753 = macroDef752;;
	storage_free(stgVar717, size761);
	card_t c1_dps = macroDef753;
	card_t r2_shp = m2_shp.card;
	card_t macroDef754 = m2_dps->length;
	card_t r2_dps = macroDef754;
	matrix_shape_t m2T_shp = TOP_LEVEL_linalg_matrixTranspose_shp(m2_shp);
	card_t size764 = width_matrix_shape_t(m2T_shp);
	array_number_t stgVar721 = storage_alloc(size764);
	array_array_number_t macroDef759;array_array_number_t m2T_dps = TOP_LEVEL_linalg_matrixTranspose_dps(stgVar721, m2_dps, m2_shp);
	array_array_number_t macroDef758 = (array_array_number_t)stgVar710;
		macroDef758->length=r1_dps;
		macroDef758->arr=(array_number_t*)(STG_OFFSET(macroDef758, VECTOR_HEADER_BYTES));
		storage_t stgVar723 = (STG_OFFSET(macroDef758, MATRIX_HEADER_BYTES(r1_dps)));
		for(int r_dps = 0; r_dps < macroDef758->length; r_dps++){
			array_number_t macroDef757 = (array_number_t)stgVar723;
		macroDef757->length=c2_dps;
		macroDef757->arr=(number_t*)(STG_OFFSET(macroDef757, VECTOR_HEADER_BYTES));
		storage_t stgVar724 = macroDef757;
		for(int c_dps = 0; c_dps < macroDef757->length; c_dps++){
			card_t size763 = width_card_t(m2T_shp.elem);
	array_number_t stgVar726 = storage_alloc(size763);
	number_t macroDef756;card_t size762 = width_card_t(m1_shp.elem);
	array_number_t stgVar725 = storage_alloc(size762);
	number_t macroDef755;
	macroDef755 = TOP_LEVEL_linalg_dot_prod_dps(stgVar724, m1_dps->arr[r_dps], m2T_dps->arr[c_dps], m1_shp.elem, m2T_shp.elem);;
	storage_free(stgVar725, size762);
	macroDef756 = macroDef755;;
	storage_free(stgVar726, size763);
			macroDef757->arr[c_dps] = macroDef756;;
			stgVar724 = STG_OFFSET(stgVar724, sizeof(number_t));
		}
			macroDef758->arr[r_dps] = macroDef757;;
			stgVar723 = STG_OFFSET(stgVar723, VECTOR_ALL_BYTES(macroDef758->arr[r_dps]->length));
		}
	macroDef759 = macroDef758;;
	storage_free(stgVar721, size764);
	return macroDef759;
}

card_t TOP_LEVEL_linalg_matrixVectorMult_shp(matrix_shape_t m_shp, card_t v_shp) {
	
	return TOP_LEVEL_linalg_rows_shp(m_shp);
}


array_number_t TOP_LEVEL_linalg_matrixVectorMult_dps(storage_t stgVar765, array_array_number_t m_dps, array_number_t v_dps, matrix_shape_t m_shp, card_t v_shp) {
	card_t r_shp = TOP_LEVEL_linalg_rows_shp(m_shp);
	card_t size782 = width_card_t(r_shp);
	array_number_t stgVar766 = storage_alloc(size782);
	array_number_t macroDef779;card_t r_dps = TOP_LEVEL_linalg_rows_dps(stgVar766, m_dps, m_shp);
	card_t c_shp = TOP_LEVEL_linalg_cols_shp(m_shp);
	card_t size781 = width_card_t(c_shp);
	array_number_t stgVar768 = storage_alloc(size781);
	array_number_t macroDef778;card_t c_dps = TOP_LEVEL_linalg_cols_dps(stgVar768, m_dps, m_shp);
	array_number_t macroDef777 = (array_number_t)stgVar765;
		macroDef777->length=r_dps;
		macroDef777->arr=(number_t*)(STG_OFFSET(macroDef777, VECTOR_HEADER_BYTES));
		storage_t stgVar770 = macroDef777;
		for(int i_dps = 0; i_dps < macroDef777->length; i_dps++){
			card_t size780 = width_card_t(m_shp.elem);
	array_number_t stgVar771 = storage_alloc(size780);
	number_t macroDef776;
	macroDef776 = TOP_LEVEL_linalg_dot_prod_dps(stgVar770, m_dps->arr[i_dps], v_dps, m_shp.elem, v_shp);;
	storage_free(stgVar771, size780);
			macroDef777->arr[i_dps] = macroDef776;;
			stgVar770 = STG_OFFSET(stgVar770, sizeof(number_t));
		}
	macroDef778 = macroDef777;;
	storage_free(stgVar768, size781);
	macroDef779 = macroDef778;;
	storage_free(stgVar766, size782);
	return macroDef779;
}

matrix_shape_t TOP_LEVEL_linalg_matrixConcat_shp(matrix_shape_t m1_shp, matrix_shape_t m2_shp) {
	
	return nested_shape_card_t(m1_shp.elem, (m1_shp.card) + (m2_shp.card));
}


array_array_number_t TOP_LEVEL_linalg_matrixConcat_dps(storage_t stgVar783, array_array_number_t m1_dps, array_array_number_t m2_dps, matrix_shape_t m1_shp, matrix_shape_t m2_shp) {
	card_t rows_shp = (m1_shp.card) + (m2_shp.card);
	card_t macroDef794 = m1_dps->length;
	card_t macroDef795 = m2_dps->length;
	card_t rows_dps = (macroDef794) + (macroDef795);
	card_t m1Rows_shp = 0;
	card_t macroDef796 = m1_dps->length;
	index_t m1Rows_dps = (macroDef796);
	array_array_number_t macroDef797 = (array_array_number_t)stgVar783;
		macroDef797->length=rows_dps;
		macroDef797->arr=(array_number_t*)(STG_OFFSET(macroDef797, VECTOR_HEADER_BYTES));
		storage_t stgVar789 = (STG_OFFSET(macroDef797, MATRIX_HEADER_BYTES(rows_dps)));
		for(int r_dps = 0; r_dps < macroDef797->length; r_dps++){
			array_number_t ite798 = 0;
	if((r_dps) < (m1Rows_dps)) {
		
		ite798 = m1_dps->arr[r_dps];;
	} else {
		
		ite798 = m2_dps->arr[(r_dps) - (m1Rows_dps)];;
	}
			macroDef797->arr[r_dps] = ite798;;
			stgVar789 = STG_OFFSET(stgVar789, VECTOR_ALL_BYTES(macroDef797->arr[r_dps]->length));
		}
	return macroDef797;
}

matrix_shape_t TOP_LEVEL_linalg_matrixConcatCol_shp(matrix_shape_t m1_shp, matrix_shape_t m2_shp) {
	
	return TOP_LEVEL_linalg_matrixTranspose_shp(TOP_LEVEL_linalg_matrixConcat_shp(TOP_LEVEL_linalg_matrixTranspose_shp(m1_shp), TOP_LEVEL_linalg_matrixTranspose_shp(m2_shp)));
}


array_array_number_t TOP_LEVEL_linalg_matrixConcatCol_dps(storage_t stgVar799, array_array_number_t m1_dps, array_array_number_t m2_dps, matrix_shape_t m1_shp, matrix_shape_t m2_shp) {
	matrix_shape_t m1t_shp = TOP_LEVEL_linalg_matrixTranspose_shp(m1_shp);
	card_t size814 = width_matrix_shape_t(m1t_shp);
	array_number_t stgVar800 = storage_alloc(size814);
	array_array_number_t macroDef811;array_array_number_t m1t_dps = TOP_LEVEL_linalg_matrixTranspose_dps(stgVar800, m1_dps, m1_shp);
	matrix_shape_t m2t_shp = TOP_LEVEL_linalg_matrixTranspose_shp(m2_shp);
	card_t size813 = width_matrix_shape_t(m2t_shp);
	array_number_t stgVar802 = storage_alloc(size813);
	array_array_number_t macroDef810;array_array_number_t m2t_dps = TOP_LEVEL_linalg_matrixTranspose_dps(stgVar802, m2_dps, m2_shp);
	card_t size812 = width_matrix_shape_t(TOP_LEVEL_linalg_matrixConcat_shp(m1t_shp, m2t_shp));
	array_number_t stgVar804 = storage_alloc(size812);
	array_array_number_t macroDef809;
	macroDef809 = TOP_LEVEL_linalg_matrixTranspose_dps(stgVar799, TOP_LEVEL_linalg_matrixConcat_dps(stgVar804, m1t_dps, m2t_dps, m1t_shp, m2t_shp), TOP_LEVEL_linalg_matrixConcat_shp(m1t_shp, m2t_shp));;
	storage_free(stgVar804, size812);
	macroDef810 = macroDef809;;
	storage_free(stgVar802, size813);
	macroDef811 = macroDef810;;
	storage_free(stgVar800, size814);
	return macroDef811;
}

matrix3d_shape_t TOP_LEVEL_linalg_matrix3DConcat_shp(matrix3d_shape_t m1_shp, matrix3d_shape_t m2_shp) {
	
	return nested_shape_matrix_shape_t(m1_shp.elem, (m1_shp.card) + (m2_shp.card));
}


array_array_array_number_t TOP_LEVEL_linalg_matrix3DConcat_dps(storage_t stgVar815, array_array_array_number_t m1_dps, array_array_array_number_t m2_dps, matrix3d_shape_t m1_shp, matrix3d_shape_t m2_shp) {
	card_t rows_shp = (m1_shp.card) + (m2_shp.card);
	card_t macroDef826 = m1_dps->length;
	card_t macroDef827 = m2_dps->length;
	card_t rows_dps = (macroDef826) + (macroDef827);
	card_t m1Rows_shp = 0;
	card_t macroDef828 = m1_dps->length;
	index_t m1Rows_dps = (macroDef828);
	array_array_array_number_t macroDef829 = (array_array_array_number_t)stgVar815;
		macroDef829->length=rows_dps;
		macroDef829->arr=(array_array_number_t*)(STG_OFFSET(macroDef829, VECTOR_HEADER_BYTES));
		storage_t stgVar821 = (STG_OFFSET(macroDef829, MATRIX_HEADER_BYTES(rows_dps)));
		for(int r_dps = 0; r_dps < macroDef829->length; r_dps++){
			array_array_number_t ite830 = 0;
	if((r_dps) < (m1Rows_dps)) {
		
		ite830 = m1_dps->arr[r_dps];;
	} else {
		
		ite830 = m2_dps->arr[(r_dps) - (m1Rows_dps)];;
	}
			macroDef829->arr[r_dps] = ite830;;
			stgVar821 = STG_OFFSET(stgVar821, VECTOR_ALL_BYTES(macroDef829->arr[r_dps]->length));
		}
	return macroDef829;
}

card_t TOP_LEVEL_linalg_vectorRead_shp(card_t fn_shp, card_t startLine_shp) {
	
	return nested_shape_card_t(10, 1).elem;
}


array_number_t TOP_LEVEL_linalg_vectorRead_dps(storage_t stgVar831, string_t fn_dps, index_t startLine_dps, card_t fn_shp, card_t startLine_shp) {
	matrix_shape_t matrix_shp = nested_shape_card_t(10, 1);
	card_t size835 = width_matrix_shape_t(matrix_shp);
	array_number_t stgVar832 = storage_alloc(size835);
	array_number_t macroDef834;array_array_number_t matrix_dps = matrix_read_s(stgVar832, fn_dps, startLine_dps, 1);
	macroDef834 = matrix_dps->arr[0];;
	storage_free(stgVar832, size835);
	return macroDef834;
}

card_t TOP_LEVEL_linalg_numberRead_shp(card_t fn_shp, card_t startLine_shp) {
	
	return 0;
}


number_t TOP_LEVEL_linalg_numberRead_dps(storage_t stgVar836, string_t fn_dps, index_t startLine_dps, card_t fn_shp, card_t startLine_shp) {
	card_t vector_shp = TOP_LEVEL_linalg_vectorRead_shp(0, 0);
	card_t size842 = width_card_t(vector_shp);
	array_number_t stgVar837 = storage_alloc(size842);
	number_t macroDef841;array_number_t vector_dps = TOP_LEVEL_linalg_vectorRead_dps(stgVar837, fn_dps, startLine_dps, 0, 0);
	macroDef841 = vector_dps->arr[0];;
	storage_free(stgVar837, size842);
	return macroDef841;
}

card_t TOP_LEVEL_linalg_vec3_shp(card_t a_shp, card_t b_shp, card_t c_shp) {
	
	return 3;
}


array_number_t TOP_LEVEL_linalg_vec3_dps(storage_t stgVar843, number_t a_dps, number_t b_dps, number_t c_dps, card_t a_shp, card_t b_shp, card_t c_shp) {
	array_number_t macroDef847 = (array_number_t)stgVar843;
	macroDef847->length=3;
	macroDef847->arr=(number_t*)(STG_OFFSET(stgVar843, VECTOR_HEADER_BYTES));
	macroDef847->arr[0] = a_dps;
	macroDef847->arr[1] = b_dps;
	macroDef847->arr[2] = c_dps;;
	return macroDef847;
}
#endif
