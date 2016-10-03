#ifndef __LINALG_STORAGED_H__ 
#define __LINALG_STORAGED_H__ 
#include "runtime/fsharp.h"
#include <stdio.h>
#include <math.h>

card_t TOP_LEVEL_linalg_vectorMap_shp(closure_t f_shp, card_t v_shp) {
	
	return v_shp;
}


array_number_t TOP_LEVEL_linalg_vectorMap_dps(storage_t stgVar1, closure_t f_dps, array_number_t v_dps, closure_t f_shp, card_t v_shp) {
	card_t macroDef6 = v_dps->length;
	array_number_t macroDef7 = (array_number_t)stgVar1;
		macroDef7->length=macroDef6;
		macroDef7->arr=(number_t*)(STG_OFFSET(macroDef7, VECTOR_HEADER_BYTES));
		storage_t stgVar3 = macroDef7;
		for(int i_dps = 0; i_dps < macroDef7->length; i_dps++){
			
			macroDef7->arr[i_dps] = f_dps.lam(f_dps.env, stgVar3, v_dps->arr[i_dps], 0).number_t_value;;
			stgVar3 = STG_OFFSET(stgVar3, sizeof(number_t));
		}
	return macroDef7;
}

card_t TOP_LEVEL_linalg_vectorRange_shp(card_t s_shp, card_t e_shp) {
	
	return ((e_shp) - (s_shp)) + (1);
}


array_number_t TOP_LEVEL_linalg_vectorRange_dps(storage_t stgVar8, card_t s_dps, card_t e_dps, card_t s_shp, card_t e_shp) {
	array_number_t macroDef10 = (array_number_t)stgVar8;
		macroDef10->length=((e_dps) - (s_dps)) + (1);
		macroDef10->arr=(number_t*)(STG_OFFSET(macroDef10, VECTOR_HEADER_BYTES));
		storage_t stgVar9 = macroDef10;
		for(int i_dps = 0; i_dps < macroDef10->length; i_dps++){
			
			macroDef10->arr[i_dps] = (double)(((s_dps)) + (i_dps));;
			stgVar9 = STG_OFFSET(stgVar9, sizeof(number_t));
		}
	return macroDef10;
}

card_t TOP_LEVEL_linalg_vectorSlice_shp(card_t size_shp, card_t offset_shp, card_t v_shp) {
	
	return size_shp;
}


array_number_t TOP_LEVEL_linalg_vectorSlice_dps(storage_t stgVar11, card_t size_dps, index_t offset_dps, array_number_t v_dps, card_t size_shp, card_t offset_shp, card_t v_shp) {
	array_number_t macroDef14 = (array_number_t)stgVar11;
		macroDef14->length=size_dps;
		macroDef14->arr=(number_t*)(STG_OFFSET(macroDef14, VECTOR_HEADER_BYTES));
		storage_t stgVar12 = macroDef14;
		for(int i_dps = 0; i_dps < macroDef14->length; i_dps++){
			
			macroDef14->arr[i_dps] = v_dps->arr[(i_dps) + (offset_dps)];;
			stgVar12 = STG_OFFSET(stgVar12, sizeof(number_t));
		}
	return macroDef14;
}

matrix_shape_t TOP_LEVEL_linalg_matrixMap_shp(closure_t f_shp, matrix_shape_t m_shp) {
	
	return nested_shape_card_t(f_shp.lam(f_shp.env, m_shp.elem).card_t_value, m_shp.card);
}


array_array_number_t TOP_LEVEL_linalg_matrixMap_dps(storage_t stgVar15, closure_t f_dps, array_array_number_t m_dps, closure_t f_shp, matrix_shape_t m_shp) {
	card_t macroDef20 = m_dps->length;
	array_array_number_t macroDef22 = (array_array_number_t)stgVar15;
		macroDef22->length=macroDef20;
		macroDef22->arr=(array_number_t*)(STG_OFFSET(macroDef22, VECTOR_HEADER_BYTES));
		storage_t stgVar17 = (STG_OFFSET(macroDef22, MATRIX_HEADER_BYTES(macroDef20)));
		for(int i_dps = 0; i_dps < macroDef22->length; i_dps++){
			card_t size23 = width_card_t(m_shp.elem);
	array_number_t stgVar18 = storage_alloc(size23);
	array_number_t macroDef21;
	macroDef21 = f_dps.lam(f_dps.env, stgVar17, m_dps->arr[i_dps], m_shp.elem).array_number_t_value;;
	storage_free(stgVar18, size23);
			macroDef22->arr[i_dps] = macroDef21;;
			stgVar17 = STG_OFFSET(stgVar17, VECTOR_ALL_BYTES(macroDef22->arr[i_dps]->length));
		}
	return macroDef22;
}

card_t TOP_LEVEL_linalg_matrixMapToVector_shp(closure_t f_shp, matrix_shape_t m_shp) {
	
	return m_shp.card;
}


array_number_t TOP_LEVEL_linalg_matrixMapToVector_dps(storage_t stgVar24, closure_t f_dps, array_array_number_t m_dps, closure_t f_shp, matrix_shape_t m_shp) {
	card_t macroDef29 = m_dps->length;
	array_number_t macroDef31 = (array_number_t)stgVar24;
		macroDef31->length=macroDef29;
		macroDef31->arr=(number_t*)(STG_OFFSET(macroDef31, VECTOR_HEADER_BYTES));
		storage_t stgVar26 = macroDef31;
		for(int i_dps = 0; i_dps < macroDef31->length; i_dps++){
			card_t size32 = width_card_t(m_shp.elem);
	array_number_t stgVar27 = storage_alloc(size32);
	number_t macroDef30;
	macroDef30 = f_dps.lam(f_dps.env, stgVar26, m_dps->arr[i_dps], m_shp.elem).number_t_value;;
	storage_free(stgVar27, size32);
			macroDef31->arr[i_dps] = macroDef30;;
			stgVar26 = STG_OFFSET(stgVar26, sizeof(number_t));
		}
	return macroDef31;
}

card_t TOP_LEVEL_linalg_vectorMap2_shp(closure_t f_shp, card_t v1_shp, card_t v2_shp) {
	
	return v1_shp;
}


array_number_t TOP_LEVEL_linalg_vectorMap2_dps(storage_t stgVar33, closure_t f_dps, array_number_t v1_dps, array_number_t v2_dps, closure_t f_shp, card_t v1_shp, card_t v2_shp) {
	card_t macroDef40 = v1_dps->length;
	array_number_t macroDef41 = (array_number_t)stgVar33;
		macroDef41->length=macroDef40;
		macroDef41->arr=(number_t*)(STG_OFFSET(macroDef41, VECTOR_HEADER_BYTES));
		storage_t stgVar35 = macroDef41;
		for(int i_dps = 0; i_dps < macroDef41->length; i_dps++){
			
			macroDef41->arr[i_dps] = f_dps.lam(f_dps.env, stgVar35, v1_dps->arr[i_dps], v2_dps->arr[i_dps], 0, 0).number_t_value;;
			stgVar35 = STG_OFFSET(stgVar35, sizeof(number_t));
		}
	return macroDef41;
}

matrix_shape_t TOP_LEVEL_linalg_matrixMap2_shp(closure_t f_shp, matrix_shape_t m1_shp, matrix_shape_t m2_shp) {
	
	return nested_shape_card_t(f_shp.lam(f_shp.env, m1_shp.elem, m2_shp.elem).card_t_value, m1_shp.card);
}


array_array_number_t TOP_LEVEL_linalg_matrixMap2_dps(storage_t stgVar42, closure_t f_dps, array_array_number_t m1_dps, array_array_number_t m2_dps, closure_t f_shp, matrix_shape_t m1_shp, matrix_shape_t m2_shp) {
	card_t macroDef49 = m1_dps->length;
	array_array_number_t macroDef52 = (array_array_number_t)stgVar42;
		macroDef52->length=macroDef49;
		macroDef52->arr=(array_number_t*)(STG_OFFSET(macroDef52, VECTOR_HEADER_BYTES));
		storage_t stgVar44 = (STG_OFFSET(macroDef52, MATRIX_HEADER_BYTES(macroDef49)));
		for(int i_dps = 0; i_dps < macroDef52->length; i_dps++){
			card_t size54 = width_card_t(m2_shp.elem);
	array_number_t stgVar46 = storage_alloc(size54);
	array_number_t macroDef51;card_t size53 = width_card_t(m1_shp.elem);
	array_number_t stgVar45 = storage_alloc(size53);
	array_number_t macroDef50;
	macroDef50 = f_dps.lam(f_dps.env, stgVar44, m1_dps->arr[i_dps], m2_dps->arr[i_dps], m1_shp.elem, m2_shp.elem).array_number_t_value;;
	storage_free(stgVar45, size53);
	macroDef51 = macroDef50;;
	storage_free(stgVar46, size54);
			macroDef52->arr[i_dps] = macroDef51;;
			stgVar44 = STG_OFFSET(stgVar44, VECTOR_ALL_BYTES(macroDef52->arr[i_dps]->length));
		}
	return macroDef52;
}

matrix3d_shape_t TOP_LEVEL_linalg_matrix3DMap2_shp(closure_t f_shp, matrix3d_shape_t m1_shp, matrix3d_shape_t m2_shp) {
	
	return nested_shape_matrix_shape_t(f_shp.lam(f_shp.env, m1_shp.elem, m2_shp.elem).matrix_shape_t_value, m1_shp.card);
}


array_array_array_number_t TOP_LEVEL_linalg_matrix3DMap2_dps(storage_t stgVar55, closure_t f_dps, array_array_array_number_t m1_dps, array_array_array_number_t m2_dps, closure_t f_shp, matrix3d_shape_t m1_shp, matrix3d_shape_t m2_shp) {
	card_t macroDef62 = m1_dps->length;
	array_array_array_number_t macroDef65 = (array_array_array_number_t)stgVar55;
		macroDef65->length=macroDef62;
		macroDef65->arr=(array_array_number_t*)(STG_OFFSET(macroDef65, VECTOR_HEADER_BYTES));
		storage_t stgVar57 = (STG_OFFSET(macroDef65, MATRIX_HEADER_BYTES(macroDef62)));
		for(int i_dps = 0; i_dps < macroDef65->length; i_dps++){
			card_t size67 = width_matrix_shape_t(m2_shp.elem);
	array_number_t stgVar59 = storage_alloc(size67);
	array_array_number_t macroDef64;card_t size66 = width_matrix_shape_t(m1_shp.elem);
	array_number_t stgVar58 = storage_alloc(size66);
	array_array_number_t macroDef63;
	macroDef63 = f_dps.lam(f_dps.env, stgVar57, m1_dps->arr[i_dps], m2_dps->arr[i_dps], m1_shp.elem, m2_shp.elem).array_array_number_t_value;;
	storage_free(stgVar58, size66);
	macroDef64 = macroDef63;;
	storage_free(stgVar59, size67);
			macroDef65->arr[i_dps] = macroDef64;;
			stgVar57 = STG_OFFSET(stgVar57, VECTOR_ALL_BYTES(macroDef65->arr[i_dps]->length));
		}
	return macroDef65;
}

matrix_shape_t TOP_LEVEL_linalg_vectorMapToMatrix_shp(closure_t f_shp, card_t arr_shp) {
	
	return nested_shape_card_t(f_shp.lam(f_shp.env, 0).card_t_value, arr_shp);
}


array_array_number_t TOP_LEVEL_linalg_vectorMapToMatrix_dps(storage_t stgVar68, closure_t f_dps, array_number_t arr_dps, closure_t f_shp, card_t arr_shp) {
	card_t macroDef73 = arr_dps->length;
	array_array_number_t macroDef74 = (array_array_number_t)stgVar68;
		macroDef74->length=macroDef73;
		macroDef74->arr=(array_number_t*)(STG_OFFSET(macroDef74, VECTOR_HEADER_BYTES));
		storage_t stgVar70 = (STG_OFFSET(macroDef74, MATRIX_HEADER_BYTES(macroDef73)));
		for(int i_dps = 0; i_dps < macroDef74->length; i_dps++){
			
			macroDef74->arr[i_dps] = f_dps.lam(f_dps.env, stgVar70, arr_dps->arr[i_dps], 0).array_number_t_value;;
			stgVar70 = STG_OFFSET(stgVar70, VECTOR_ALL_BYTES(macroDef74->arr[i_dps]->length));
		}
	return macroDef74;
}

matrix3d_shape_t TOP_LEVEL_linalg_vectorMapToMatrix3D_shp(closure_t f_shp, card_t arr_shp) {
	
	return nested_shape_matrix_shape_t(f_shp.lam(f_shp.env, 0).matrix_shape_t_value, arr_shp);
}


array_array_array_number_t TOP_LEVEL_linalg_vectorMapToMatrix3D_dps(storage_t stgVar75, closure_t f_dps, array_number_t arr_dps, closure_t f_shp, card_t arr_shp) {
	card_t macroDef80 = arr_dps->length;
	array_array_array_number_t macroDef81 = (array_array_array_number_t)stgVar75;
		macroDef81->length=macroDef80;
		macroDef81->arr=(array_array_number_t*)(STG_OFFSET(macroDef81, VECTOR_HEADER_BYTES));
		storage_t stgVar77 = (STG_OFFSET(macroDef81, MATRIX_HEADER_BYTES(macroDef80)));
		for(int i_dps = 0; i_dps < macroDef81->length; i_dps++){
			
			macroDef81->arr[i_dps] = f_dps.lam(f_dps.env, stgVar77, arr_dps->arr[i_dps], 0).array_array_number_t_value;;
			stgVar77 = STG_OFFSET(stgVar77, VECTOR_ALL_BYTES(macroDef81->arr[i_dps]->length));
		}
	return macroDef81;
}

card_t TOP_LEVEL_linalg_iterateNumber_shp(closure_t f_shp, card_t z_shp, card_t s_shp, card_t e_shp) {
	
	return 0;
}


number_t TOP_LEVEL_linalg_iterateNumber_dps(storage_t stgVar82, closure_t f_dps, number_t z_dps, card_t s_dps, card_t e_dps, closure_t f_shp, card_t z_shp, card_t s_shp, card_t e_shp) {
	number_t macroDef88 = z_dps;
	array_number_t cur_dps_range = TOP_LEVEL_linalg_vectorRange_dps(empty_storage, s_dps, e_dps, s_shp, e_shp);
	storage_t stgVar83 = stgVar82;
	for(int cur_dps_idx = 0; cur_dps_idx < cur_dps_range->length; cur_dps_idx++){
		number_t cur_dps = cur_dps_range->arr[cur_dps_idx];
		
		macroDef88 = f_dps.lam(f_dps.env, stgVar83, macroDef88, (int)(cur_dps), 0, 0).number_t_value;;
	}
	return macroDef88;
}

card_t TOP_LEVEL_linalg_iterateVector_shp(closure_t f_shp, card_t z_shp, card_t s_shp, card_t e_shp) {
	
	return z_shp;
}


array_number_t TOP_LEVEL_linalg_iterateVector_dps(storage_t stgVar89, closure_t f_dps, array_number_t z_dps, card_t s_dps, card_t e_dps, closure_t f_shp, card_t z_shp, card_t s_shp, card_t e_shp) {
	array_number_t macroDef95 = z_dps;
	array_number_t cur_dps_range = TOP_LEVEL_linalg_vectorRange_dps(empty_storage, s_dps, e_dps, s_shp, e_shp);
	storage_t stgVar90 = stgVar89;
	for(int cur_dps_idx = 0; cur_dps_idx < cur_dps_range->length; cur_dps_idx++){
		number_t cur_dps = cur_dps_range->arr[cur_dps_idx];
		
		macroDef95 = f_dps.lam(f_dps.env, stgVar90, macroDef95, (int)(cur_dps), z_shp, 0).array_number_t_value;;
	}
	return macroDef95;
}

matrix_shape_t TOP_LEVEL_linalg_iterateMatrix_shp(closure_t f_shp, matrix_shape_t z_shp, card_t s_shp, card_t e_shp) {
	
	return z_shp;
}


array_array_number_t TOP_LEVEL_linalg_iterateMatrix_dps(storage_t stgVar96, closure_t f_dps, array_array_number_t z_dps, card_t s_dps, card_t e_dps, closure_t f_shp, matrix_shape_t z_shp, card_t s_shp, card_t e_shp) {
	array_array_number_t macroDef102 = z_dps;
	array_number_t cur_dps_range = TOP_LEVEL_linalg_vectorRange_dps(empty_storage, s_dps, e_dps, s_shp, e_shp);
	storage_t stgVar97 = stgVar96;
	for(int cur_dps_idx = 0; cur_dps_idx < cur_dps_range->length; cur_dps_idx++){
		number_t cur_dps = cur_dps_range->arr[cur_dps_idx];
		
		macroDef102 = f_dps.lam(f_dps.env, stgVar97, macroDef102, (int)(cur_dps), z_shp, 0).array_array_number_t_value;;
	}
	return macroDef102;
}

matrix3d_shape_t TOP_LEVEL_linalg_iterateMatrix3D_shp(closure_t f_shp, matrix3d_shape_t z_shp, card_t s_shp, card_t e_shp) {
	
	return z_shp;
}


array_array_array_number_t TOP_LEVEL_linalg_iterateMatrix3D_dps(storage_t stgVar103, closure_t f_dps, array_array_array_number_t z_dps, card_t s_dps, card_t e_dps, closure_t f_shp, matrix3d_shape_t z_shp, card_t s_shp, card_t e_shp) {
	array_array_array_number_t macroDef109 = z_dps;
	array_number_t cur_dps_range = TOP_LEVEL_linalg_vectorRange_dps(empty_storage, s_dps, e_dps, s_shp, e_shp);
	storage_t stgVar104 = stgVar103;
	for(int cur_dps_idx = 0; cur_dps_idx < cur_dps_range->length; cur_dps_idx++){
		number_t cur_dps = cur_dps_range->arr[cur_dps_idx];
		
		macroDef109 = f_dps.lam(f_dps.env, stgVar104, macroDef109, (int)(cur_dps), z_shp, 0).array_array_array_number_t_value;;
	}
	return macroDef109;
}

card_t TOP_LEVEL_linalg_vectorSum_shp(card_t v_shp) {
	
	return 0;
}


number_t TOP_LEVEL_linalg_vectorSum_dps(storage_t stgVar110, array_number_t v_dps, card_t v_shp) {
	number_t macroDef112 = 0;
	array_number_t cur_dps_range = v_dps;
	storage_t stgVar111 = stgVar110;
	for(int cur_dps_idx = 0; cur_dps_idx < cur_dps_range->length; cur_dps_idx++){
		number_t cur_dps = cur_dps_range->arr[cur_dps_idx];
		
		macroDef112 = (macroDef112) + (cur_dps);;
	}
	return macroDef112;
}

card_t TOP_LEVEL_linalg_vectorMax_shp(card_t v_shp) {
	
	return 0;
}


number_t TOP_LEVEL_linalg_vectorMax_dps(storage_t stgVar113, array_number_t v_dps, card_t v_shp) {
	number_t macroDef115 = -1000;
	array_number_t cur_dps_range = v_dps;
	storage_t stgVar114 = stgVar113;
	for(int cur_dps_idx = 0; cur_dps_idx < cur_dps_range->length; cur_dps_idx++){
		number_t cur_dps = cur_dps_range->arr[cur_dps_idx];
		number_t ite116 = 0;
	if((macroDef115) > (cur_dps)) {
		
		ite116 = macroDef115;;
	} else {
		
		ite116 = cur_dps;;
	}
		macroDef115 = ite116;;
	}
	return macroDef115;
}
typedef empty_env_t env_t_124;


value_t lambda124(env_t_124* env121, card_t a_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
card_t TOP_LEVEL_linalg_mult_by_scalar_shp(card_t x_shp, card_t y_shp) {
	env_t_124 env_t_124_value = make_empty_env(); closure_t closure123 = make_closure(lambda124, &env_t_124_value);
	return TOP_LEVEL_linalg_vectorMap_shp(closure123, x_shp);
}

typedef struct env_t_132 {
	number_t y_dps;
} env_t_132;
env_t_132 make_env_t_132(number_t y_dps) {
	env_t_132 env;
	env.y_dps = y_dps;
	return env;
}

value_t lambda132(env_t_132* env126, storage_t stgVar120, number_t a_dps, card_t a_shp) {
	number_t y_dps125 = env126->y_dps;
	value_t res;
	res.number_t_value = (a_dps) * (y_dps125);
	return res;
}
typedef empty_env_t env_t_133;


value_t lambda133(env_t_133* env129, card_t a_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
array_number_t TOP_LEVEL_linalg_mult_by_scalar_dps(storage_t stgVar117, array_number_t x_dps, number_t y_dps, card_t x_shp, card_t y_shp) {
	env_t_132 env_t_132_value = make_env_t_132(y_dps); closure_t closure128 = make_closure(lambda132, &env_t_132_value);
	env_t_133 env_t_133_value = make_empty_env(); closure_t closure131 = make_closure(lambda133, &env_t_133_value);
	return TOP_LEVEL_linalg_vectorMap_dps(stgVar117, closure128, x_dps, closure131, x_shp);
}
typedef empty_env_t env_t_141;


value_t lambda141(env_t_141* env138, card_t xi_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
card_t TOP_LEVEL_linalg_gaxpy_shp(card_t a_shp, card_t x_shp, card_t y_shp) {
	env_t_141 env_t_141_value = make_empty_env(); closure_t closure140 = make_closure(lambda141, &env_t_141_value);
	return TOP_LEVEL_linalg_vectorMap_shp(closure140, x_shp);
}

typedef struct env_t_150 {
	number_t y_dps;
	number_t a_dps;
} env_t_150;
env_t_150 make_env_t_150(number_t y_dps,number_t a_dps) {
	env_t_150 env;
	env.y_dps = y_dps;
	env.a_dps = a_dps;
	return env;
}

value_t lambda150(env_t_150* env144, storage_t stgVar137, number_t xi_dps, card_t xi_shp) {
	number_t y_dps143 = env144->y_dps;
	number_t a_dps142 = env144->a_dps;
	value_t res;
	res.number_t_value = ((a_dps142) * (xi_dps)) + (y_dps143);
	return res;
}
typedef empty_env_t env_t_151;


value_t lambda151(env_t_151* env147, card_t xi_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
array_number_t TOP_LEVEL_linalg_gaxpy_dps(storage_t stgVar134, number_t a_dps, array_number_t x_dps, number_t y_dps, card_t a_shp, card_t x_shp, card_t y_shp) {
	env_t_150 env_t_150_value = make_env_t_150(y_dps,a_dps); closure_t closure146 = make_closure(lambda150, &env_t_150_value);
	env_t_151 env_t_151_value = make_empty_env(); closure_t closure149 = make_closure(lambda151, &env_t_151_value);
	return TOP_LEVEL_linalg_vectorMap_dps(stgVar134, closure146, x_dps, closure149, x_shp);
}

card_t TOP_LEVEL_linalg_cross_shp(card_t a_shp, card_t b_shp) {
	
	return 3;
}


array_number_t TOP_LEVEL_linalg_cross_dps(storage_t stgVar152, array_number_t a_dps, array_number_t b_dps, card_t a_shp, card_t b_shp) {
	array_number_t macroDef168 = (array_number_t)stgVar152;
	macroDef168->length=3;
	macroDef168->arr=(number_t*)(STG_OFFSET(stgVar152, VECTOR_HEADER_BYTES));
	macroDef168->arr[0] = ((a_dps->arr[1]) * (b_dps->arr[2])) - ((a_dps->arr[2]) * (b_dps->arr[1]));
	macroDef168->arr[1] = ((a_dps->arr[2]) * (b_dps->arr[0])) - ((a_dps->arr[0]) * (b_dps->arr[2]));
	macroDef168->arr[2] = ((a_dps->arr[0]) * (b_dps->arr[1])) - ((a_dps->arr[1]) * (b_dps->arr[0]));;
	return macroDef168;
}
typedef empty_env_t env_t_177;


value_t lambda177(env_t_177* env174, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
card_t TOP_LEVEL_linalg_vectorAdd_shp(card_t x_shp, card_t y_shp) {
	env_t_177 env_t_177_value = make_empty_env(); closure_t closure176 = make_closure(lambda177, &env_t_177_value);
	return TOP_LEVEL_linalg_vectorMap2_shp(closure176, x_shp, y_shp);
}

typedef empty_env_t env_t_184;


value_t lambda184(env_t_184* env178, storage_t stgVar173, number_t x_dps0, number_t y_dps0, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.number_t_value = (x_dps0) + (y_dps0);
	return res;
}
typedef empty_env_t env_t_185;


value_t lambda185(env_t_185* env181, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
array_number_t TOP_LEVEL_linalg_vectorAdd_dps(storage_t stgVar169, array_number_t x_dps, array_number_t y_dps, card_t x_shp, card_t y_shp) {
	env_t_184 env_t_184_value = make_empty_env(); closure_t closure180 = make_closure(lambda184, &env_t_184_value);
	env_t_185 env_t_185_value = make_empty_env(); closure_t closure183 = make_closure(lambda185, &env_t_185_value);
	return TOP_LEVEL_linalg_vectorMap2_dps(stgVar169, closure180, x_dps, y_dps, closure183, x_shp, y_shp);
}
typedef empty_env_t env_t_194;


value_t lambda194(env_t_194* env191, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
card_t TOP_LEVEL_linalg_mult_vec_elementwise_shp(card_t x_shp, card_t y_shp) {
	env_t_194 env_t_194_value = make_empty_env(); closure_t closure193 = make_closure(lambda194, &env_t_194_value);
	return TOP_LEVEL_linalg_vectorMap2_shp(closure193, x_shp, y_shp);
}

typedef empty_env_t env_t_201;


value_t lambda201(env_t_201* env195, storage_t stgVar190, number_t x_dps0, number_t y_dps0, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.number_t_value = (x_dps0) * (y_dps0);
	return res;
}
typedef empty_env_t env_t_202;


value_t lambda202(env_t_202* env198, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
array_number_t TOP_LEVEL_linalg_mult_vec_elementwise_dps(storage_t stgVar186, array_number_t x_dps, array_number_t y_dps, card_t x_shp, card_t y_shp) {
	env_t_201 env_t_201_value = make_empty_env(); closure_t closure197 = make_closure(lambda201, &env_t_201_value);
	env_t_202 env_t_202_value = make_empty_env(); closure_t closure200 = make_closure(lambda202, &env_t_202_value);
	return TOP_LEVEL_linalg_vectorMap2_dps(stgVar186, closure197, x_dps, y_dps, closure200, x_shp, y_shp);
}
typedef empty_env_t env_t_211;


value_t lambda211(env_t_211* env208, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
card_t TOP_LEVEL_linalg_op_DotMultiply_shp(card_t x_shp, card_t y_shp) {
	env_t_211 env_t_211_value = make_empty_env(); closure_t closure210 = make_closure(lambda211, &env_t_211_value);
	return TOP_LEVEL_linalg_vectorMap2_shp(closure210, x_shp, y_shp);
}

typedef empty_env_t env_t_218;


value_t lambda218(env_t_218* env212, storage_t stgVar207, number_t x_dps0, number_t y_dps0, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.number_t_value = (x_dps0) * (y_dps0);
	return res;
}
typedef empty_env_t env_t_219;


value_t lambda219(env_t_219* env215, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
array_number_t TOP_LEVEL_linalg_op_DotMultiply_dps(storage_t stgVar203, array_number_t x_dps, array_number_t y_dps, card_t x_shp, card_t y_shp) {
	env_t_218 env_t_218_value = make_empty_env(); closure_t closure214 = make_closure(lambda218, &env_t_218_value);
	env_t_219 env_t_219_value = make_empty_env(); closure_t closure217 = make_closure(lambda219, &env_t_219_value);
	return TOP_LEVEL_linalg_vectorMap2_dps(stgVar203, closure214, x_dps, y_dps, closure217, x_shp, y_shp);
}

card_t TOP_LEVEL_linalg_vectorAdd3_shp(card_t x_shp, card_t y_shp, card_t z_shp) {
	
	return TOP_LEVEL_linalg_vectorAdd_shp(TOP_LEVEL_linalg_vectorAdd_shp(x_shp, y_shp), z_shp);
}


array_number_t TOP_LEVEL_linalg_vectorAdd3_dps(storage_t stgVar220, array_number_t x_dps, array_number_t y_dps, array_number_t z_dps, card_t x_shp, card_t y_shp, card_t z_shp) {
	card_t size226 = width_card_t(TOP_LEVEL_linalg_vectorAdd_shp(x_shp, y_shp));
	array_number_t stgVar221 = storage_alloc(size226);
	array_number_t macroDef225;
	macroDef225 = TOP_LEVEL_linalg_vectorAdd_dps(stgVar220, TOP_LEVEL_linalg_vectorAdd_dps(stgVar221, x_dps, y_dps, x_shp, y_shp), z_dps, TOP_LEVEL_linalg_vectorAdd_shp(x_shp, y_shp), z_shp);;
	storage_free(stgVar221, size226);
	return macroDef225;
}
typedef empty_env_t env_t_235;


value_t lambda235(env_t_235* env232, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
card_t TOP_LEVEL_linalg_vectorSub_shp(card_t x_shp, card_t y_shp) {
	env_t_235 env_t_235_value = make_empty_env(); closure_t closure234 = make_closure(lambda235, &env_t_235_value);
	return TOP_LEVEL_linalg_vectorMap2_shp(closure234, x_shp, y_shp);
}

typedef empty_env_t env_t_242;


value_t lambda242(env_t_242* env236, storage_t stgVar231, number_t x_dps0, number_t y_dps0, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.number_t_value = (x_dps0) - (y_dps0);
	return res;
}
typedef empty_env_t env_t_243;


value_t lambda243(env_t_243* env239, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
array_number_t TOP_LEVEL_linalg_vectorSub_dps(storage_t stgVar227, array_number_t x_dps, array_number_t y_dps, card_t x_shp, card_t y_shp) {
	env_t_242 env_t_242_value = make_empty_env(); closure_t closure238 = make_closure(lambda242, &env_t_242_value);
	env_t_243 env_t_243_value = make_empty_env(); closure_t closure241 = make_closure(lambda243, &env_t_243_value);
	return TOP_LEVEL_linalg_vectorMap2_dps(stgVar227, closure238, x_dps, y_dps, closure241, x_shp, y_shp);
}
typedef empty_env_t env_t_254;


value_t lambda254(env_t_254* env251, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = TOP_LEVEL_linalg_vectorAdd_shp(x_shp0, y_shp0);
	return res;
}
matrix_shape_t TOP_LEVEL_linalg_matrixAdd_shp(matrix_shape_t x_shp, matrix_shape_t y_shp) {
	env_t_254 env_t_254_value = make_empty_env(); closure_t closure253 = make_closure(lambda254, &env_t_254_value);
	return TOP_LEVEL_linalg_matrixMap2_shp(closure253, x_shp, y_shp);
}

typedef empty_env_t env_t_261;


value_t lambda261(env_t_261* env255, storage_t stgVar248, array_number_t x_dps0, array_number_t y_dps0, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.array_number_t_value = TOP_LEVEL_linalg_vectorAdd_dps(stgVar248, x_dps0, y_dps0, x_shp0, y_shp0);
	return res;
}
typedef empty_env_t env_t_262;


value_t lambda262(env_t_262* env258, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = TOP_LEVEL_linalg_vectorAdd_shp(x_shp0, y_shp0);
	return res;
}
array_array_number_t TOP_LEVEL_linalg_matrixAdd_dps(storage_t stgVar244, array_array_number_t x_dps, array_array_number_t y_dps, matrix_shape_t x_shp, matrix_shape_t y_shp) {
	env_t_261 env_t_261_value = make_empty_env(); closure_t closure257 = make_closure(lambda261, &env_t_261_value);
	env_t_262 env_t_262_value = make_empty_env(); closure_t closure260 = make_closure(lambda262, &env_t_262_value);
	return TOP_LEVEL_linalg_matrixMap2_dps(stgVar244, closure257, x_dps, y_dps, closure260, x_shp, y_shp);
}
typedef empty_env_t env_t_273;


value_t lambda273(env_t_273* env270, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = TOP_LEVEL_linalg_mult_vec_elementwise_shp(x_shp0, y_shp0);
	return res;
}
matrix_shape_t TOP_LEVEL_linalg_matrixMultElementwise_shp(matrix_shape_t x_shp, matrix_shape_t y_shp) {
	env_t_273 env_t_273_value = make_empty_env(); closure_t closure272 = make_closure(lambda273, &env_t_273_value);
	return TOP_LEVEL_linalg_matrixMap2_shp(closure272, x_shp, y_shp);
}

typedef empty_env_t env_t_280;


value_t lambda280(env_t_280* env274, storage_t stgVar267, array_number_t x_dps0, array_number_t y_dps0, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.array_number_t_value = TOP_LEVEL_linalg_mult_vec_elementwise_dps(stgVar267, x_dps0, y_dps0, x_shp0, y_shp0);
	return res;
}
typedef empty_env_t env_t_281;


value_t lambda281(env_t_281* env277, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = TOP_LEVEL_linalg_mult_vec_elementwise_shp(x_shp0, y_shp0);
	return res;
}
array_array_number_t TOP_LEVEL_linalg_matrixMultElementwise_dps(storage_t stgVar263, array_array_number_t x_dps, array_array_number_t y_dps, matrix_shape_t x_shp, matrix_shape_t y_shp) {
	env_t_280 env_t_280_value = make_empty_env(); closure_t closure276 = make_closure(lambda280, &env_t_280_value);
	env_t_281 env_t_281_value = make_empty_env(); closure_t closure279 = make_closure(lambda281, &env_t_281_value);
	return TOP_LEVEL_linalg_matrixMap2_dps(stgVar263, closure276, x_dps, y_dps, closure279, x_shp, y_shp);
}

card_t TOP_LEVEL_linalg_sqnorm_shp(card_t x_shp) {
	
	return 0;
}

typedef empty_env_t env_t_300;


value_t lambda300(env_t_300* env287, card_t x1_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef empty_env_t env_t_301;


value_t lambda301(env_t_301* env290, storage_t stgVar286, number_t x1_dps, card_t x1_shp) {
	
	value_t res;
	res.number_t_value = (x1_dps) * (x1_dps);
	return res;
}
typedef empty_env_t env_t_302;


value_t lambda302(env_t_302* env293, card_t x1_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef empty_env_t env_t_303;


value_t lambda303(env_t_303* env296, card_t x1_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
number_t TOP_LEVEL_linalg_sqnorm_dps(storage_t stgVar282, array_number_t x_dps, card_t x_shp) {
	env_t_300 env_t_300_value = make_empty_env(); closure_t closure289 = make_closure(lambda300, &env_t_300_value);
	card_t size304 = width_card_t(TOP_LEVEL_linalg_vectorMap_shp(closure289, x_shp));
	array_number_t stgVar283 = storage_alloc(size304);
	number_t macroDef299;env_t_301 env_t_301_value = make_empty_env(); closure_t closure292 = make_closure(lambda301, &env_t_301_value);
	env_t_302 env_t_302_value = make_empty_env(); closure_t closure295 = make_closure(lambda302, &env_t_302_value);
	env_t_303 env_t_303_value = make_empty_env(); closure_t closure298 = make_closure(lambda303, &env_t_303_value);
	macroDef299 = TOP_LEVEL_linalg_vectorSum_dps(stgVar282, TOP_LEVEL_linalg_vectorMap_dps(stgVar283, closure292, x_dps, closure295, x_shp), TOP_LEVEL_linalg_vectorMap_shp(closure298, x_shp));;
	storage_free(stgVar283, size304);
	return macroDef299;
}

card_t TOP_LEVEL_linalg_dot_prod_shp(card_t x_shp, card_t y_shp) {
	
	return 0;
}

typedef empty_env_t env_t_324;


value_t lambda324(env_t_324* env311, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef empty_env_t env_t_325;


value_t lambda325(env_t_325* env314, storage_t stgVar310, number_t x_dps0, number_t y_dps0, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.number_t_value = (x_dps0) * (y_dps0);
	return res;
}
typedef empty_env_t env_t_326;


value_t lambda326(env_t_326* env317, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef empty_env_t env_t_327;


value_t lambda327(env_t_327* env320, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
number_t TOP_LEVEL_linalg_dot_prod_dps(storage_t stgVar305, array_number_t x_dps, array_number_t y_dps, card_t x_shp, card_t y_shp) {
	env_t_324 env_t_324_value = make_empty_env(); closure_t closure313 = make_closure(lambda324, &env_t_324_value);
	card_t size328 = width_card_t(TOP_LEVEL_linalg_vectorMap2_shp(closure313, x_shp, y_shp));
	array_number_t stgVar306 = storage_alloc(size328);
	number_t macroDef323;env_t_325 env_t_325_value = make_empty_env(); closure_t closure316 = make_closure(lambda325, &env_t_325_value);
	env_t_326 env_t_326_value = make_empty_env(); closure_t closure319 = make_closure(lambda326, &env_t_326_value);
	env_t_327 env_t_327_value = make_empty_env(); closure_t closure322 = make_closure(lambda327, &env_t_327_value);
	macroDef323 = TOP_LEVEL_linalg_vectorSum_dps(stgVar305, TOP_LEVEL_linalg_vectorMap2_dps(stgVar306, closure316, x_dps, y_dps, closure319, x_shp, y_shp), TOP_LEVEL_linalg_vectorMap2_shp(closure322, x_shp, y_shp));;
	storage_free(stgVar306, size328);
	return macroDef323;
}
typedef struct env_t_339 {
	card_t row_shp;
} env_t_339;
env_t_339 make_env_t_339(card_t row_shp) {
	env_t_339 env;
	env.row_shp = row_shp;
	return env;
}

value_t lambda339(env_t_339* env336, card_t r_shp) {
	card_t row_shp335 = env336->row_shp;
	value_t res;
	res.card_t_value = row_shp335;
	return res;
}
matrix_shape_t TOP_LEVEL_linalg_matrixFillFromVector_shp(card_t rows_shp, card_t row_shp) {
	env_t_339 env_t_339_value = make_env_t_339(row_shp); closure_t closure338 = make_closure(lambda339, &env_t_339_value);
	return TOP_LEVEL_linalg_vectorMapToMatrix_shp(closure338, TOP_LEVEL_linalg_vectorRange_shp(1, rows_shp));
}

typedef struct env_t_349 {
	array_number_t row_dps;
} env_t_349;
env_t_349 make_env_t_349(array_number_t row_dps) {
	env_t_349 env;
	env.row_dps = row_dps;
	return env;
}

value_t lambda349(env_t_349* env341, storage_t stgVar332, number_t r_dps, card_t r_shp) {
	array_number_t row_dps340 = env341->row_dps;
	value_t res;
	res.array_number_t_value = row_dps340;
	return res;
}
typedef struct env_t_350 {
	card_t row_shp;
} env_t_350;
env_t_350 make_env_t_350(card_t row_shp) {
	env_t_350 env;
	env.row_shp = row_shp;
	return env;
}

value_t lambda350(env_t_350* env345, card_t r_shp) {
	card_t row_shp344 = env345->row_shp;
	value_t res;
	res.card_t_value = row_shp344;
	return res;
}
array_array_number_t TOP_LEVEL_linalg_matrixFillFromVector_dps(storage_t stgVar329, card_t rows_dps, array_number_t row_dps, card_t rows_shp, card_t row_shp) {
	card_t size351 = width_card_t(TOP_LEVEL_linalg_vectorRange_shp(1, rows_shp));
	array_number_t stgVar331 = storage_alloc(size351);
	array_array_number_t macroDef348;env_t_349 env_t_349_value = make_env_t_349(row_dps); closure_t closure343 = make_closure(lambda349, &env_t_349_value);
	env_t_350 env_t_350_value = make_env_t_350(row_shp); closure_t closure347 = make_closure(lambda350, &env_t_350_value);
	macroDef348 = TOP_LEVEL_linalg_vectorMapToMatrix_dps(stgVar329, closure343, TOP_LEVEL_linalg_vectorRange_dps(stgVar331, 1, rows_dps, 1, rows_shp), closure347, TOP_LEVEL_linalg_vectorRange_shp(1, rows_shp));;
	storage_free(stgVar331, size351);
	return macroDef348;
}

matrix_shape_t TOP_LEVEL_linalg_matrixFill_shp(card_t rows_shp, card_t cols_shp, card_t value_shp) {
	
	return nested_shape_card_t(cols_shp, rows_shp);
}


array_array_number_t TOP_LEVEL_linalg_matrixFill_dps(storage_t stgVar352, card_t rows_dps, card_t cols_dps, number_t value_dps, card_t rows_shp, card_t cols_shp, card_t value_shp) {
	array_array_number_t macroDef356 = (array_array_number_t)stgVar352;
		macroDef356->length=rows_dps;
		macroDef356->arr=(array_number_t*)(STG_OFFSET(macroDef356, VECTOR_HEADER_BYTES));
		storage_t stgVar353 = (STG_OFFSET(macroDef356, MATRIX_HEADER_BYTES(rows_dps)));
		for(int r_dps = 0; r_dps < macroDef356->length; r_dps++){
			array_number_t macroDef355 = (array_number_t)stgVar353;
		macroDef355->length=cols_dps;
		macroDef355->arr=(number_t*)(STG_OFFSET(macroDef355, VECTOR_HEADER_BYTES));
		storage_t stgVar354 = macroDef355;
		for(int c_dps = 0; c_dps < macroDef355->length; c_dps++){
			
			macroDef355->arr[c_dps] = value_dps;;
			stgVar354 = STG_OFFSET(stgVar354, sizeof(number_t));
		}
			macroDef356->arr[r_dps] = macroDef355;;
			stgVar353 = STG_OFFSET(stgVar353, VECTOR_ALL_BYTES(macroDef356->arr[r_dps]->length));
		}
	return macroDef356;
}

matrix_shape_t TOP_LEVEL_linalg_matrixTranspose_shp(matrix_shape_t m_shp) {
	
	return nested_shape_card_t(m_shp.card, m_shp.elem);
}


array_array_number_t TOP_LEVEL_linalg_matrixTranspose_dps(storage_t stgVar357, array_array_number_t m_dps, matrix_shape_t m_shp) {
	card_t rows_shp = m_shp.card;
	card_t macroDef369 = m_dps->length;
	card_t rows_dps = macroDef369;
	card_t cols_shp = m_shp.elem;
	card_t size375 = width_card_t(m_shp.elem);
	array_number_t stgVar361 = storage_alloc(size375);
	card_t macroDef371;card_t macroDef370 = m_dps->arr[0]->length;
	macroDef371 = macroDef370;;
	storage_free(stgVar361, size375);
	card_t cols_dps = macroDef371;
	array_array_number_t macroDef374 = (array_array_number_t)stgVar357;
		macroDef374->length=cols_dps;
		macroDef374->arr=(array_number_t*)(STG_OFFSET(macroDef374, VECTOR_HEADER_BYTES));
		storage_t stgVar363 = (STG_OFFSET(macroDef374, MATRIX_HEADER_BYTES(cols_dps)));
		for(int i_dps = 0; i_dps < macroDef374->length; i_dps++){
			array_number_t macroDef373 = (array_number_t)stgVar363;
		macroDef373->length=rows_dps;
		macroDef373->arr=(number_t*)(STG_OFFSET(macroDef373, VECTOR_HEADER_BYTES));
		storage_t stgVar364 = macroDef373;
		for(int j_dps = 0; j_dps < macroDef373->length; j_dps++){
			card_t size376 = width_card_t(m_shp.elem);
	array_number_t stgVar365 = storage_alloc(size376);
	number_t macroDef372;
	macroDef372 = m_dps->arr[j_dps]->arr[i_dps];;
	storage_free(stgVar365, size376);
			macroDef373->arr[j_dps] = macroDef372;;
			stgVar364 = STG_OFFSET(stgVar364, sizeof(number_t));
		}
			macroDef374->arr[i_dps] = macroDef373;;
			stgVar363 = STG_OFFSET(stgVar363, VECTOR_ALL_BYTES(macroDef374->arr[i_dps]->length));
		}
	return macroDef374;
}

matrix_shape_t TOP_LEVEL_linalg_matrixMult_shp(matrix_shape_t m1_shp, matrix_shape_t m2_shp) {
	
	return nested_shape_card_t(m2_shp.elem, m1_shp.card);
}


array_array_number_t TOP_LEVEL_linalg_matrixMult_dps(storage_t stgVar377, array_array_number_t m1_dps, array_array_number_t m2_dps, matrix_shape_t m1_shp, matrix_shape_t m2_shp) {
	card_t r1_shp = m1_shp.card;
	card_t macroDef416 = m1_dps->length;
	card_t r1_dps = macroDef416;
	card_t c2_shp = m2_shp.elem;
	card_t size427 = width_card_t(m2_shp.elem);
	array_number_t stgVar381 = storage_alloc(size427);
	card_t macroDef418;card_t macroDef417 = m2_dps->arr[0]->length;
	macroDef418 = macroDef417;;
	storage_free(stgVar381, size427);
	card_t c2_dps = macroDef418;
	card_t c1_shp = m1_shp.elem;
	card_t size428 = width_card_t(m1_shp.elem);
	array_number_t stgVar384 = storage_alloc(size428);
	card_t macroDef420;card_t macroDef419 = m1_dps->arr[0]->length;
	macroDef420 = macroDef419;;
	storage_free(stgVar384, size428);
	card_t c1_dps = macroDef420;
	card_t r2_shp = m2_shp.card;
	card_t macroDef421 = m2_dps->length;
	card_t r2_dps = macroDef421;
	matrix_shape_t m2T_shp = TOP_LEVEL_linalg_matrixTranspose_shp(m2_shp);
	card_t size431 = width_matrix_shape_t(m2T_shp);
	array_number_t stgVar388 = storage_alloc(size431);
	array_array_number_t macroDef426;array_array_number_t m2T_dps = TOP_LEVEL_linalg_matrixTranspose_dps(stgVar388, m2_dps, m2_shp);
	array_array_number_t macroDef425 = (array_array_number_t)stgVar377;
		macroDef425->length=r1_dps;
		macroDef425->arr=(array_number_t*)(STG_OFFSET(macroDef425, VECTOR_HEADER_BYTES));
		storage_t stgVar390 = (STG_OFFSET(macroDef425, MATRIX_HEADER_BYTES(r1_dps)));
		for(int r_dps = 0; r_dps < macroDef425->length; r_dps++){
			array_number_t macroDef424 = (array_number_t)stgVar390;
		macroDef424->length=c2_dps;
		macroDef424->arr=(number_t*)(STG_OFFSET(macroDef424, VECTOR_HEADER_BYTES));
		storage_t stgVar391 = macroDef424;
		for(int c_dps = 0; c_dps < macroDef424->length; c_dps++){
			card_t size430 = width_card_t(m2T_shp.elem);
	array_number_t stgVar393 = storage_alloc(size430);
	number_t macroDef423;card_t size429 = width_card_t(m1_shp.elem);
	array_number_t stgVar392 = storage_alloc(size429);
	number_t macroDef422;
	macroDef422 = TOP_LEVEL_linalg_dot_prod_dps(stgVar391, m1_dps->arr[r_dps], m2T_dps->arr[c_dps], m1_shp.elem, m2T_shp.elem);;
	storage_free(stgVar392, size429);
	macroDef423 = macroDef422;;
	storage_free(stgVar393, size430);
			macroDef424->arr[c_dps] = macroDef423;;
			stgVar391 = STG_OFFSET(stgVar391, sizeof(number_t));
		}
			macroDef425->arr[r_dps] = macroDef424;;
			stgVar390 = STG_OFFSET(stgVar390, VECTOR_ALL_BYTES(macroDef425->arr[r_dps]->length));
		}
	macroDef426 = macroDef425;;
	storage_free(stgVar388, size431);
	return macroDef426;
}

matrix_shape_t TOP_LEVEL_linalg_matrixConcat_shp(matrix_shape_t m1_shp, matrix_shape_t m2_shp) {
	
	return nested_shape_card_t(m1_shp.elem, (m1_shp.card) + (m2_shp.card));
}


array_array_number_t TOP_LEVEL_linalg_matrixConcat_dps(storage_t stgVar432, array_array_number_t m1_dps, array_array_number_t m2_dps, matrix_shape_t m1_shp, matrix_shape_t m2_shp) {
	card_t rows_shp = (m1_shp.card) + (m2_shp.card);
	card_t macroDef443 = m1_dps->length;
	card_t macroDef444 = m2_dps->length;
	card_t rows_dps = (macroDef443) + (macroDef444);
	card_t m1Rows_shp = 0;
	card_t macroDef445 = m1_dps->length;
	index_t m1Rows_dps = (macroDef445);
	array_array_number_t macroDef446 = (array_array_number_t)stgVar432;
		macroDef446->length=rows_dps;
		macroDef446->arr=(array_number_t*)(STG_OFFSET(macroDef446, VECTOR_HEADER_BYTES));
		storage_t stgVar438 = (STG_OFFSET(macroDef446, MATRIX_HEADER_BYTES(rows_dps)));
		for(int r_dps = 0; r_dps < macroDef446->length; r_dps++){
			array_number_t ite447 = 0;
	if((r_dps) < (m1Rows_dps)) {
		
		ite447 = m1_dps->arr[r_dps];;
	} else {
		
		ite447 = m2_dps->arr[(r_dps) - (m1Rows_dps)];;
	}
			macroDef446->arr[r_dps] = ite447;;
			stgVar438 = STG_OFFSET(stgVar438, VECTOR_ALL_BYTES(macroDef446->arr[r_dps]->length));
		}
	return macroDef446;
}

matrix_shape_t TOP_LEVEL_linalg_matrixConcatCol_shp(matrix_shape_t m1_shp, matrix_shape_t m2_shp) {
	
	return TOP_LEVEL_linalg_matrixTranspose_shp(TOP_LEVEL_linalg_matrixConcat_shp(TOP_LEVEL_linalg_matrixTranspose_shp(m1_shp), TOP_LEVEL_linalg_matrixTranspose_shp(m2_shp)));
}


array_array_number_t TOP_LEVEL_linalg_matrixConcatCol_dps(storage_t stgVar448, array_array_number_t m1_dps, array_array_number_t m2_dps, matrix_shape_t m1_shp, matrix_shape_t m2_shp) {
	matrix_shape_t m1t_shp = TOP_LEVEL_linalg_matrixTranspose_shp(m1_shp);
	card_t size463 = width_matrix_shape_t(m1t_shp);
	array_number_t stgVar449 = storage_alloc(size463);
	array_array_number_t macroDef460;array_array_number_t m1t_dps = TOP_LEVEL_linalg_matrixTranspose_dps(stgVar449, m1_dps, m1_shp);
	matrix_shape_t m2t_shp = TOP_LEVEL_linalg_matrixTranspose_shp(m2_shp);
	card_t size462 = width_matrix_shape_t(m2t_shp);
	array_number_t stgVar451 = storage_alloc(size462);
	array_array_number_t macroDef459;array_array_number_t m2t_dps = TOP_LEVEL_linalg_matrixTranspose_dps(stgVar451, m2_dps, m2_shp);
	card_t size461 = width_matrix_shape_t(TOP_LEVEL_linalg_matrixConcat_shp(m1t_shp, m2t_shp));
	array_number_t stgVar453 = storage_alloc(size461);
	array_array_number_t macroDef458;
	macroDef458 = TOP_LEVEL_linalg_matrixTranspose_dps(stgVar448, TOP_LEVEL_linalg_matrixConcat_dps(stgVar453, m1t_dps, m2t_dps, m1t_shp, m2t_shp), TOP_LEVEL_linalg_matrixConcat_shp(m1t_shp, m2t_shp));;
	storage_free(stgVar453, size461);
	macroDef459 = macroDef458;;
	storage_free(stgVar451, size462);
	macroDef460 = macroDef459;;
	storage_free(stgVar449, size463);
	return macroDef460;
}

matrix3d_shape_t TOP_LEVEL_linalg_matrix3DConcat_shp(matrix3d_shape_t m1_shp, matrix3d_shape_t m2_shp) {
	
	return nested_shape_matrix_shape_t(m1_shp.elem, (m1_shp.card) + (m2_shp.card));
}


array_array_array_number_t TOP_LEVEL_linalg_matrix3DConcat_dps(storage_t stgVar464, array_array_array_number_t m1_dps, array_array_array_number_t m2_dps, matrix3d_shape_t m1_shp, matrix3d_shape_t m2_shp) {
	card_t rows_shp = (m1_shp.card) + (m2_shp.card);
	card_t macroDef475 = m1_dps->length;
	card_t macroDef476 = m2_dps->length;
	card_t rows_dps = (macroDef475) + (macroDef476);
	card_t m1Rows_shp = 0;
	card_t macroDef477 = m1_dps->length;
	index_t m1Rows_dps = (macroDef477);
	array_array_array_number_t macroDef478 = (array_array_array_number_t)stgVar464;
		macroDef478->length=rows_dps;
		macroDef478->arr=(array_array_number_t*)(STG_OFFSET(macroDef478, VECTOR_HEADER_BYTES));
		storage_t stgVar470 = (STG_OFFSET(macroDef478, MATRIX_HEADER_BYTES(rows_dps)));
		for(int r_dps = 0; r_dps < macroDef478->length; r_dps++){
			array_array_number_t ite479 = 0;
	if((r_dps) < (m1Rows_dps)) {
		
		ite479 = m1_dps->arr[r_dps];;
	} else {
		
		ite479 = m2_dps->arr[(r_dps) - (m1Rows_dps)];;
	}
			macroDef478->arr[r_dps] = ite479;;
			stgVar470 = STG_OFFSET(stgVar470, VECTOR_ALL_BYTES(macroDef478->arr[r_dps]->length));
		}
	return macroDef478;
}

card_t TOP_LEVEL_linalg_vectorRead_shp(card_t fn_shp, card_t startLine_shp) {
	
	return nested_shape_card_t(10, 1).elem;
}


array_number_t TOP_LEVEL_linalg_vectorRead_dps(storage_t stgVar480, string_t fn_dps, index_t startLine_dps, card_t fn_shp, card_t startLine_shp) {
	matrix_shape_t matrix_shp = nested_shape_card_t(10, 1);
	card_t size484 = width_matrix_shape_t(matrix_shp);
	array_number_t stgVar481 = storage_alloc(size484);
	array_number_t macroDef483;array_array_number_t matrix_dps = matrix_read_s(stgVar481, fn_dps, startLine_dps, 1);
	macroDef483 = matrix_dps->arr[0];;
	storage_free(stgVar481, size484);
	return macroDef483;
}

card_t TOP_LEVEL_linalg_numberRead_shp(card_t fn_shp, card_t startLine_shp) {
	
	return 0;
}


number_t TOP_LEVEL_linalg_numberRead_dps(storage_t stgVar485, string_t fn_dps, index_t startLine_dps, card_t fn_shp, card_t startLine_shp) {
	card_t vector_shp = TOP_LEVEL_linalg_vectorRead_shp(0, 0);
	card_t size491 = width_card_t(vector_shp);
	array_number_t stgVar486 = storage_alloc(size491);
	number_t macroDef490;array_number_t vector_dps = TOP_LEVEL_linalg_vectorRead_dps(stgVar486, fn_dps, startLine_dps, 0, 0);
	macroDef490 = vector_dps->arr[0];;
	storage_free(stgVar486, size491);
	return macroDef490;
}

card_t TOP_LEVEL_linalg_vec3_shp(card_t a_shp, card_t b_shp, card_t c_shp) {
	
	return 3;
}


array_number_t TOP_LEVEL_linalg_vec3_dps(storage_t stgVar492, number_t a_dps, number_t b_dps, number_t c_dps, card_t a_shp, card_t b_shp, card_t c_shp) {
	array_number_t macroDef496 = (array_number_t)stgVar492;
	macroDef496->length=3;
	macroDef496->arr=(number_t*)(STG_OFFSET(stgVar492, VECTOR_HEADER_BYTES));
	macroDef496->arr[0] = a_dps;
	macroDef496->arr[1] = b_dps;
	macroDef496->arr[2] = c_dps;;
	return macroDef496;
}
#endif
