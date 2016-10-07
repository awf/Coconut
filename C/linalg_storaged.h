#ifndef __LINALG_STORAGED_H__ 
#define __LINALG_STORAGED_H__ 
#include "runtime/fsharp.h"
#include <stdio.h>
#include <math.h>

card_t TOP_LEVEL_linalg_rows_shp(matrix_shape_t m_shp) {
	
	return m_shp.card;
}


card_t TOP_LEVEL_linalg_rows_dps(storage_t stgVar1, array_array_number_t m_dps, matrix_shape_t m_shp) {
	card_t macroDef3 = m_dps->length;
	return macroDef3;
}

card_t TOP_LEVEL_linalg_cols_shp(matrix_shape_t m_shp) {
	
	return m_shp.elem;
}


card_t TOP_LEVEL_linalg_cols_dps(storage_t stgVar4, array_array_number_t m_dps, matrix_shape_t m_shp) {
	card_t size9 = width_card_t(m_shp.elem);
	array_number_t stgVar5 = storage_alloc(size9);
	card_t macroDef8;card_t macroDef7 = m_dps->arr[0]->length;
	macroDef8 = macroDef7;;
	storage_free(stgVar5, size9);
	return macroDef8;
}

card_t TOP_LEVEL_linalg_vectorMap_shp(closure_t f_shp, card_t v_shp) {
	
	return v_shp;
}


array_number_t TOP_LEVEL_linalg_vectorMap_dps(storage_t stgVar10, closure_t f_dps, array_number_t v_dps, closure_t f_shp, card_t v_shp) {
	card_t macroDef15 = v_dps->length;
	array_number_t macroDef16 = (array_number_t)stgVar10;
		macroDef16->length=macroDef15;
		macroDef16->arr=(number_t*)(STG_OFFSET(macroDef16, VECTOR_HEADER_BYTES));
		storage_t stgVar12 = macroDef16;
		for(int i_dps = 0; i_dps < macroDef16->length; i_dps++){
			
			macroDef16->arr[i_dps] = f_dps.lam(f_dps.env, stgVar12, v_dps->arr[i_dps], 0).number_t_value;;
			stgVar12 = STG_OFFSET(stgVar12, sizeof(number_t));
		}
	return macroDef16;
}

card_t TOP_LEVEL_linalg_vectorRange_shp(card_t s_shp, card_t e_shp) {
	
	return ((e_shp) - (s_shp)) + (1);
}


array_number_t TOP_LEVEL_linalg_vectorRange_dps(storage_t stgVar17, card_t s_dps, card_t e_dps, card_t s_shp, card_t e_shp) {
	array_number_t macroDef19 = (array_number_t)stgVar17;
		macroDef19->length=((e_dps) - (s_dps)) + (1);
		macroDef19->arr=(number_t*)(STG_OFFSET(macroDef19, VECTOR_HEADER_BYTES));
		storage_t stgVar18 = macroDef19;
		for(int i_dps = 0; i_dps < macroDef19->length; i_dps++){
			
			macroDef19->arr[i_dps] = (double)(((s_dps)) + (i_dps));;
			stgVar18 = STG_OFFSET(stgVar18, sizeof(number_t));
		}
	return macroDef19;
}

card_t TOP_LEVEL_linalg_vectorSlice_shp(card_t size_shp, card_t offset_shp, card_t v_shp) {
	
	return size_shp;
}


array_number_t TOP_LEVEL_linalg_vectorSlice_dps(storage_t stgVar20, card_t size_dps, index_t offset_dps, array_number_t v_dps, card_t size_shp, card_t offset_shp, card_t v_shp) {
	array_number_t macroDef23 = (array_number_t)stgVar20;
		macroDef23->length=size_dps;
		macroDef23->arr=(number_t*)(STG_OFFSET(macroDef23, VECTOR_HEADER_BYTES));
		storage_t stgVar21 = macroDef23;
		for(int i_dps = 0; i_dps < macroDef23->length; i_dps++){
			
			macroDef23->arr[i_dps] = v_dps->arr[(i_dps) + (offset_dps)];;
			stgVar21 = STG_OFFSET(stgVar21, sizeof(number_t));
		}
	return macroDef23;
}

matrix_shape_t TOP_LEVEL_linalg_matrixMap_shp(closure_t f_shp, matrix_shape_t m_shp) {
	
	return nested_shape_card_t(f_shp.lam(f_shp.env, m_shp.elem).card_t_value, m_shp.card);
}


array_array_number_t TOP_LEVEL_linalg_matrixMap_dps(storage_t stgVar24, closure_t f_dps, array_array_number_t m_dps, closure_t f_shp, matrix_shape_t m_shp) {
	card_t macroDef29 = m_dps->length;
	array_array_number_t macroDef31 = (array_array_number_t)stgVar24;
		macroDef31->length=macroDef29;
		macroDef31->arr=(array_number_t*)(STG_OFFSET(macroDef31, VECTOR_HEADER_BYTES));
		storage_t stgVar26 = (STG_OFFSET(macroDef31, MATRIX_HEADER_BYTES(macroDef29)));
		for(int i_dps = 0; i_dps < macroDef31->length; i_dps++){
			card_t size32 = width_card_t(m_shp.elem);
	array_number_t stgVar27 = storage_alloc(size32);
	array_number_t macroDef30;
	macroDef30 = f_dps.lam(f_dps.env, stgVar26, m_dps->arr[i_dps], m_shp.elem).array_number_t_value;;
	storage_free(stgVar27, size32);
			macroDef31->arr[i_dps] = macroDef30;;
			stgVar26 = STG_OFFSET(stgVar26, VECTOR_ALL_BYTES(macroDef31->arr[i_dps]->length));
		}
	return macroDef31;
}

card_t TOP_LEVEL_linalg_matrixMapToVector_shp(closure_t f_shp, matrix_shape_t m_shp) {
	
	return m_shp.card;
}


array_number_t TOP_LEVEL_linalg_matrixMapToVector_dps(storage_t stgVar33, closure_t f_dps, array_array_number_t m_dps, closure_t f_shp, matrix_shape_t m_shp) {
	card_t macroDef38 = m_dps->length;
	array_number_t macroDef40 = (array_number_t)stgVar33;
		macroDef40->length=macroDef38;
		macroDef40->arr=(number_t*)(STG_OFFSET(macroDef40, VECTOR_HEADER_BYTES));
		storage_t stgVar35 = macroDef40;
		for(int i_dps = 0; i_dps < macroDef40->length; i_dps++){
			card_t size41 = width_card_t(m_shp.elem);
	array_number_t stgVar36 = storage_alloc(size41);
	number_t macroDef39;
	macroDef39 = f_dps.lam(f_dps.env, stgVar35, m_dps->arr[i_dps], m_shp.elem).number_t_value;;
	storage_free(stgVar36, size41);
			macroDef40->arr[i_dps] = macroDef39;;
			stgVar35 = STG_OFFSET(stgVar35, sizeof(number_t));
		}
	return macroDef40;
}

card_t TOP_LEVEL_linalg_vectorMap2_shp(closure_t f_shp, card_t v1_shp, card_t v2_shp) {
	
	return v1_shp;
}


array_number_t TOP_LEVEL_linalg_vectorMap2_dps(storage_t stgVar42, closure_t f_dps, array_number_t v1_dps, array_number_t v2_dps, closure_t f_shp, card_t v1_shp, card_t v2_shp) {
	card_t macroDef49 = v1_dps->length;
	array_number_t macroDef50 = (array_number_t)stgVar42;
		macroDef50->length=macroDef49;
		macroDef50->arr=(number_t*)(STG_OFFSET(macroDef50, VECTOR_HEADER_BYTES));
		storage_t stgVar44 = macroDef50;
		for(int i_dps = 0; i_dps < macroDef50->length; i_dps++){
			
			macroDef50->arr[i_dps] = f_dps.lam(f_dps.env, stgVar44, v1_dps->arr[i_dps], v2_dps->arr[i_dps], 0, 0).number_t_value;;
			stgVar44 = STG_OFFSET(stgVar44, sizeof(number_t));
		}
	return macroDef50;
}

matrix_shape_t TOP_LEVEL_linalg_matrixMap2_shp(closure_t f_shp, matrix_shape_t m1_shp, matrix_shape_t m2_shp) {
	
	return nested_shape_card_t(f_shp.lam(f_shp.env, m1_shp.elem, m2_shp.elem).card_t_value, m1_shp.card);
}


array_array_number_t TOP_LEVEL_linalg_matrixMap2_dps(storage_t stgVar51, closure_t f_dps, array_array_number_t m1_dps, array_array_number_t m2_dps, closure_t f_shp, matrix_shape_t m1_shp, matrix_shape_t m2_shp) {
	card_t macroDef58 = m1_dps->length;
	array_array_number_t macroDef61 = (array_array_number_t)stgVar51;
		macroDef61->length=macroDef58;
		macroDef61->arr=(array_number_t*)(STG_OFFSET(macroDef61, VECTOR_HEADER_BYTES));
		storage_t stgVar53 = (STG_OFFSET(macroDef61, MATRIX_HEADER_BYTES(macroDef58)));
		for(int i_dps = 0; i_dps < macroDef61->length; i_dps++){
			card_t size63 = width_card_t(m2_shp.elem);
	array_number_t stgVar55 = storage_alloc(size63);
	array_number_t macroDef60;card_t size62 = width_card_t(m1_shp.elem);
	array_number_t stgVar54 = storage_alloc(size62);
	array_number_t macroDef59;
	macroDef59 = f_dps.lam(f_dps.env, stgVar53, m1_dps->arr[i_dps], m2_dps->arr[i_dps], m1_shp.elem, m2_shp.elem).array_number_t_value;;
	storage_free(stgVar54, size62);
	macroDef60 = macroDef59;;
	storage_free(stgVar55, size63);
			macroDef61->arr[i_dps] = macroDef60;;
			stgVar53 = STG_OFFSET(stgVar53, VECTOR_ALL_BYTES(macroDef61->arr[i_dps]->length));
		}
	return macroDef61;
}

matrix3d_shape_t TOP_LEVEL_linalg_matrix3DMap2_shp(closure_t f_shp, matrix3d_shape_t m1_shp, matrix3d_shape_t m2_shp) {
	
	return nested_shape_matrix_shape_t(f_shp.lam(f_shp.env, m1_shp.elem, m2_shp.elem).matrix_shape_t_value, m1_shp.card);
}


array_array_array_number_t TOP_LEVEL_linalg_matrix3DMap2_dps(storage_t stgVar64, closure_t f_dps, array_array_array_number_t m1_dps, array_array_array_number_t m2_dps, closure_t f_shp, matrix3d_shape_t m1_shp, matrix3d_shape_t m2_shp) {
	card_t macroDef71 = m1_dps->length;
	array_array_array_number_t macroDef74 = (array_array_array_number_t)stgVar64;
		macroDef74->length=macroDef71;
		macroDef74->arr=(array_array_number_t*)(STG_OFFSET(macroDef74, VECTOR_HEADER_BYTES));
		storage_t stgVar66 = (STG_OFFSET(macroDef74, MATRIX_HEADER_BYTES(macroDef71)));
		for(int i_dps = 0; i_dps < macroDef74->length; i_dps++){
			card_t size76 = width_matrix_shape_t(m2_shp.elem);
	array_number_t stgVar68 = storage_alloc(size76);
	array_array_number_t macroDef73;card_t size75 = width_matrix_shape_t(m1_shp.elem);
	array_number_t stgVar67 = storage_alloc(size75);
	array_array_number_t macroDef72;
	macroDef72 = f_dps.lam(f_dps.env, stgVar66, m1_dps->arr[i_dps], m2_dps->arr[i_dps], m1_shp.elem, m2_shp.elem).array_array_number_t_value;;
	storage_free(stgVar67, size75);
	macroDef73 = macroDef72;;
	storage_free(stgVar68, size76);
			macroDef74->arr[i_dps] = macroDef73;;
			stgVar66 = STG_OFFSET(stgVar66, VECTOR_ALL_BYTES(macroDef74->arr[i_dps]->length));
		}
	return macroDef74;
}

matrix_shape_t TOP_LEVEL_linalg_vectorMapToMatrix_shp(closure_t f_shp, card_t arr_shp) {
	
	return nested_shape_card_t(f_shp.lam(f_shp.env, 0).card_t_value, arr_shp);
}


array_array_number_t TOP_LEVEL_linalg_vectorMapToMatrix_dps(storage_t stgVar77, closure_t f_dps, array_number_t arr_dps, closure_t f_shp, card_t arr_shp) {
	card_t macroDef82 = arr_dps->length;
	array_array_number_t macroDef83 = (array_array_number_t)stgVar77;
		macroDef83->length=macroDef82;
		macroDef83->arr=(array_number_t*)(STG_OFFSET(macroDef83, VECTOR_HEADER_BYTES));
		storage_t stgVar79 = (STG_OFFSET(macroDef83, MATRIX_HEADER_BYTES(macroDef82)));
		for(int i_dps = 0; i_dps < macroDef83->length; i_dps++){
			
			macroDef83->arr[i_dps] = f_dps.lam(f_dps.env, stgVar79, arr_dps->arr[i_dps], 0).array_number_t_value;;
			stgVar79 = STG_OFFSET(stgVar79, VECTOR_ALL_BYTES(macroDef83->arr[i_dps]->length));
		}
	return macroDef83;
}

matrix3d_shape_t TOP_LEVEL_linalg_vectorMapToMatrix3D_shp(closure_t f_shp, card_t arr_shp) {
	
	return nested_shape_matrix_shape_t(f_shp.lam(f_shp.env, 0).matrix_shape_t_value, arr_shp);
}


array_array_array_number_t TOP_LEVEL_linalg_vectorMapToMatrix3D_dps(storage_t stgVar84, closure_t f_dps, array_number_t arr_dps, closure_t f_shp, card_t arr_shp) {
	card_t macroDef89 = arr_dps->length;
	array_array_array_number_t macroDef90 = (array_array_array_number_t)stgVar84;
		macroDef90->length=macroDef89;
		macroDef90->arr=(array_array_number_t*)(STG_OFFSET(macroDef90, VECTOR_HEADER_BYTES));
		storage_t stgVar86 = (STG_OFFSET(macroDef90, MATRIX_HEADER_BYTES(macroDef89)));
		for(int i_dps = 0; i_dps < macroDef90->length; i_dps++){
			
			macroDef90->arr[i_dps] = f_dps.lam(f_dps.env, stgVar86, arr_dps->arr[i_dps], 0).array_array_number_t_value;;
			stgVar86 = STG_OFFSET(stgVar86, VECTOR_ALL_BYTES(macroDef90->arr[i_dps]->length));
		}
	return macroDef90;
}

card_t TOP_LEVEL_linalg_iterateNumber_shp(closure_t f_shp, card_t z_shp, card_t s_shp, card_t e_shp) {
	
	return 0;
}


number_t TOP_LEVEL_linalg_iterateNumber_dps(storage_t stgVar91, closure_t f_dps, number_t z_dps, card_t s_dps, card_t e_dps, closure_t f_shp, card_t z_shp, card_t s_shp, card_t e_shp) {
	number_t macroDef97 = z_dps;
	array_number_t cur_dps_range = TOP_LEVEL_linalg_vectorRange_dps(empty_storage, s_dps, e_dps, s_shp, e_shp);
	storage_t stgVar92 = stgVar91;
	for(int cur_dps_idx = 0; cur_dps_idx < cur_dps_range->length; cur_dps_idx++){
		number_t cur_dps = cur_dps_range->arr[cur_dps_idx];
		
		macroDef97 = f_dps.lam(f_dps.env, stgVar92, macroDef97, (int)(cur_dps), 0, 0).number_t_value;;
	}
	return macroDef97;
}

card_t TOP_LEVEL_linalg_iterateVector_shp(closure_t f_shp, card_t z_shp, card_t s_shp, card_t e_shp) {
	
	return z_shp;
}


array_number_t TOP_LEVEL_linalg_iterateVector_dps(storage_t stgVar98, closure_t f_dps, array_number_t z_dps, card_t s_dps, card_t e_dps, closure_t f_shp, card_t z_shp, card_t s_shp, card_t e_shp) {
	array_number_t macroDef104 = z_dps;
	array_number_t cur_dps_range = TOP_LEVEL_linalg_vectorRange_dps(empty_storage, s_dps, e_dps, s_shp, e_shp);
	storage_t stgVar99 = stgVar98;
	for(int cur_dps_idx = 0; cur_dps_idx < cur_dps_range->length; cur_dps_idx++){
		number_t cur_dps = cur_dps_range->arr[cur_dps_idx];
		
		macroDef104 = f_dps.lam(f_dps.env, stgVar99, macroDef104, (int)(cur_dps), z_shp, 0).array_number_t_value;;
	}
	return macroDef104;
}

matrix_shape_t TOP_LEVEL_linalg_iterateMatrix_shp(closure_t f_shp, matrix_shape_t z_shp, card_t s_shp, card_t e_shp) {
	
	return z_shp;
}


array_array_number_t TOP_LEVEL_linalg_iterateMatrix_dps(storage_t stgVar105, closure_t f_dps, array_array_number_t z_dps, card_t s_dps, card_t e_dps, closure_t f_shp, matrix_shape_t z_shp, card_t s_shp, card_t e_shp) {
	array_array_number_t macroDef111 = z_dps;
	array_number_t cur_dps_range = TOP_LEVEL_linalg_vectorRange_dps(empty_storage, s_dps, e_dps, s_shp, e_shp);
	storage_t stgVar106 = stgVar105;
	for(int cur_dps_idx = 0; cur_dps_idx < cur_dps_range->length; cur_dps_idx++){
		number_t cur_dps = cur_dps_range->arr[cur_dps_idx];
		
		macroDef111 = f_dps.lam(f_dps.env, stgVar106, macroDef111, (int)(cur_dps), z_shp, 0).array_array_number_t_value;;
	}
	return macroDef111;
}

matrix3d_shape_t TOP_LEVEL_linalg_iterateMatrix3D_shp(closure_t f_shp, matrix3d_shape_t z_shp, card_t s_shp, card_t e_shp) {
	
	return z_shp;
}


array_array_array_number_t TOP_LEVEL_linalg_iterateMatrix3D_dps(storage_t stgVar112, closure_t f_dps, array_array_array_number_t z_dps, card_t s_dps, card_t e_dps, closure_t f_shp, matrix3d_shape_t z_shp, card_t s_shp, card_t e_shp) {
	array_array_array_number_t macroDef118 = z_dps;
	array_number_t cur_dps_range = TOP_LEVEL_linalg_vectorRange_dps(empty_storage, s_dps, e_dps, s_shp, e_shp);
	storage_t stgVar113 = stgVar112;
	for(int cur_dps_idx = 0; cur_dps_idx < cur_dps_range->length; cur_dps_idx++){
		number_t cur_dps = cur_dps_range->arr[cur_dps_idx];
		
		macroDef118 = f_dps.lam(f_dps.env, stgVar113, macroDef118, (int)(cur_dps), z_shp, 0).array_array_array_number_t_value;;
	}
	return macroDef118;
}

card_t TOP_LEVEL_linalg_vectorSum_shp(card_t v_shp) {
	
	return 0;
}


number_t TOP_LEVEL_linalg_vectorSum_dps(storage_t stgVar119, array_number_t v_dps, card_t v_shp) {
	number_t macroDef121 = 0;
	array_number_t cur_dps_range = v_dps;
	storage_t stgVar120 = stgVar119;
	for(int cur_dps_idx = 0; cur_dps_idx < cur_dps_range->length; cur_dps_idx++){
		number_t cur_dps = cur_dps_range->arr[cur_dps_idx];
		
		macroDef121 = (macroDef121) + (cur_dps);;
	}
	return macroDef121;
}

card_t TOP_LEVEL_linalg_vectorMax_shp(card_t v_shp) {
	
	return 0;
}


number_t TOP_LEVEL_linalg_vectorMax_dps(storage_t stgVar122, array_number_t v_dps, card_t v_shp) {
	number_t macroDef124 = -1000;
	array_number_t cur_dps_range = v_dps;
	storage_t stgVar123 = stgVar122;
	for(int cur_dps_idx = 0; cur_dps_idx < cur_dps_range->length; cur_dps_idx++){
		number_t cur_dps = cur_dps_range->arr[cur_dps_idx];
		number_t ite125 = 0;
	if((macroDef124) > (cur_dps)) {
		
		ite125 = macroDef124;;
	} else {
		
		ite125 = cur_dps;;
	}
		macroDef124 = ite125;;
	}
	return macroDef124;
}
typedef empty_env_t env_t_133;


value_t lambda133(env_t_133* env130, card_t xi_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
card_t TOP_LEVEL_linalg_mult_by_scalar_shp(card_t x_shp, card_t y_shp) {
	env_t_133 env_t_133_value = make_empty_env(); closure_t closure132 = make_closure(lambda133, &env_t_133_value);
	return TOP_LEVEL_linalg_vectorMap_shp(closure132, x_shp);
}

typedef struct env_t_141 {
	number_t y_dps;
} env_t_141;
env_t_141 make_env_t_141(number_t y_dps) {
	env_t_141 env;
	env.y_dps = y_dps;
	return env;
}

value_t lambda141(env_t_141* env135, storage_t stgVar129, number_t xi_dps, card_t xi_shp) {
	number_t y_dps134 = env135->y_dps;
	value_t res;
	res.number_t_value = (xi_dps) * (y_dps134);
	return res;
}
typedef empty_env_t env_t_142;


value_t lambda142(env_t_142* env138, card_t xi_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
array_number_t TOP_LEVEL_linalg_mult_by_scalar_dps(storage_t stgVar126, array_number_t x_dps, number_t y_dps, card_t x_shp, card_t y_shp) {
	env_t_141 env_t_141_value = make_env_t_141(y_dps); closure_t closure137 = make_closure(lambda141, &env_t_141_value);
	env_t_142 env_t_142_value = make_empty_env(); closure_t closure140 = make_closure(lambda142, &env_t_142_value);
	return TOP_LEVEL_linalg_vectorMap_dps(stgVar126, closure137, x_dps, closure140, x_shp);
}
typedef empty_env_t env_t_150;


value_t lambda150(env_t_150* env147, card_t xi_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
card_t TOP_LEVEL_linalg_gaxpy_shp(card_t a_shp, card_t x_shp, card_t y_shp) {
	env_t_150 env_t_150_value = make_empty_env(); closure_t closure149 = make_closure(lambda150, &env_t_150_value);
	return TOP_LEVEL_linalg_vectorMap_shp(closure149, x_shp);
}

typedef struct env_t_159 {
	number_t y_dps;
	number_t a_dps;
} env_t_159;
env_t_159 make_env_t_159(number_t y_dps,number_t a_dps) {
	env_t_159 env;
	env.y_dps = y_dps;
	env.a_dps = a_dps;
	return env;
}

value_t lambda159(env_t_159* env153, storage_t stgVar146, number_t xi_dps, card_t xi_shp) {
	number_t y_dps152 = env153->y_dps;
	number_t a_dps151 = env153->a_dps;
	value_t res;
	res.number_t_value = ((a_dps151) * (xi_dps)) + (y_dps152);
	return res;
}
typedef empty_env_t env_t_160;


value_t lambda160(env_t_160* env156, card_t xi_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
array_number_t TOP_LEVEL_linalg_gaxpy_dps(storage_t stgVar143, number_t a_dps, array_number_t x_dps, number_t y_dps, card_t a_shp, card_t x_shp, card_t y_shp) {
	env_t_159 env_t_159_value = make_env_t_159(y_dps,a_dps); closure_t closure155 = make_closure(lambda159, &env_t_159_value);
	env_t_160 env_t_160_value = make_empty_env(); closure_t closure158 = make_closure(lambda160, &env_t_160_value);
	return TOP_LEVEL_linalg_vectorMap_dps(stgVar143, closure155, x_dps, closure158, x_shp);
}

card_t TOP_LEVEL_linalg_cross_shp(card_t a_shp, card_t b_shp) {
	
	return 3;
}


array_number_t TOP_LEVEL_linalg_cross_dps(storage_t stgVar161, array_number_t a_dps, array_number_t b_dps, card_t a_shp, card_t b_shp) {
	array_number_t macroDef177 = (array_number_t)stgVar161;
	macroDef177->length=3;
	macroDef177->arr=(number_t*)(STG_OFFSET(stgVar161, VECTOR_HEADER_BYTES));
	macroDef177->arr[0] = ((a_dps->arr[1]) * (b_dps->arr[2])) - ((a_dps->arr[2]) * (b_dps->arr[1]));
	macroDef177->arr[1] = ((a_dps->arr[2]) * (b_dps->arr[0])) - ((a_dps->arr[0]) * (b_dps->arr[2]));
	macroDef177->arr[2] = ((a_dps->arr[0]) * (b_dps->arr[1])) - ((a_dps->arr[1]) * (b_dps->arr[0]));;
	return macroDef177;
}
typedef empty_env_t env_t_186;


value_t lambda186(env_t_186* env183, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
card_t TOP_LEVEL_linalg_vectorAdd_shp(card_t x_shp, card_t y_shp) {
	env_t_186 env_t_186_value = make_empty_env(); closure_t closure185 = make_closure(lambda186, &env_t_186_value);
	return TOP_LEVEL_linalg_vectorMap2_shp(closure185, x_shp, y_shp);
}

typedef empty_env_t env_t_193;


value_t lambda193(env_t_193* env187, storage_t stgVar182, number_t x_dps0, number_t y_dps0, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.number_t_value = (x_dps0) + (y_dps0);
	return res;
}
typedef empty_env_t env_t_194;


value_t lambda194(env_t_194* env190, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
array_number_t TOP_LEVEL_linalg_vectorAdd_dps(storage_t stgVar178, array_number_t x_dps, array_number_t y_dps, card_t x_shp, card_t y_shp) {
	env_t_193 env_t_193_value = make_empty_env(); closure_t closure189 = make_closure(lambda193, &env_t_193_value);
	env_t_194 env_t_194_value = make_empty_env(); closure_t closure192 = make_closure(lambda194, &env_t_194_value);
	return TOP_LEVEL_linalg_vectorMap2_dps(stgVar178, closure189, x_dps, y_dps, closure192, x_shp, y_shp);
}
typedef empty_env_t env_t_203;


value_t lambda203(env_t_203* env200, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
card_t TOP_LEVEL_linalg_mult_vec_elementwise_shp(card_t x_shp, card_t y_shp) {
	env_t_203 env_t_203_value = make_empty_env(); closure_t closure202 = make_closure(lambda203, &env_t_203_value);
	return TOP_LEVEL_linalg_vectorMap2_shp(closure202, x_shp, y_shp);
}

typedef empty_env_t env_t_210;


value_t lambda210(env_t_210* env204, storage_t stgVar199, number_t x_dps0, number_t y_dps0, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.number_t_value = (x_dps0) * (y_dps0);
	return res;
}
typedef empty_env_t env_t_211;


value_t lambda211(env_t_211* env207, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
array_number_t TOP_LEVEL_linalg_mult_vec_elementwise_dps(storage_t stgVar195, array_number_t x_dps, array_number_t y_dps, card_t x_shp, card_t y_shp) {
	env_t_210 env_t_210_value = make_empty_env(); closure_t closure206 = make_closure(lambda210, &env_t_210_value);
	env_t_211 env_t_211_value = make_empty_env(); closure_t closure209 = make_closure(lambda211, &env_t_211_value);
	return TOP_LEVEL_linalg_vectorMap2_dps(stgVar195, closure206, x_dps, y_dps, closure209, x_shp, y_shp);
}
typedef empty_env_t env_t_220;


value_t lambda220(env_t_220* env217, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
card_t TOP_LEVEL_linalg_op_DotMultiply_shp(card_t x_shp, card_t y_shp) {
	env_t_220 env_t_220_value = make_empty_env(); closure_t closure219 = make_closure(lambda220, &env_t_220_value);
	return TOP_LEVEL_linalg_vectorMap2_shp(closure219, x_shp, y_shp);
}

typedef empty_env_t env_t_227;


value_t lambda227(env_t_227* env221, storage_t stgVar216, number_t x_dps0, number_t y_dps0, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.number_t_value = (x_dps0) * (y_dps0);
	return res;
}
typedef empty_env_t env_t_228;


value_t lambda228(env_t_228* env224, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
array_number_t TOP_LEVEL_linalg_op_DotMultiply_dps(storage_t stgVar212, array_number_t x_dps, array_number_t y_dps, card_t x_shp, card_t y_shp) {
	env_t_227 env_t_227_value = make_empty_env(); closure_t closure223 = make_closure(lambda227, &env_t_227_value);
	env_t_228 env_t_228_value = make_empty_env(); closure_t closure226 = make_closure(lambda228, &env_t_228_value);
	return TOP_LEVEL_linalg_vectorMap2_dps(stgVar212, closure223, x_dps, y_dps, closure226, x_shp, y_shp);
}

card_t TOP_LEVEL_linalg_vectorAdd3_shp(card_t x_shp, card_t y_shp, card_t z_shp) {
	
	return TOP_LEVEL_linalg_vectorAdd_shp(TOP_LEVEL_linalg_vectorAdd_shp(x_shp, y_shp), z_shp);
}


array_number_t TOP_LEVEL_linalg_vectorAdd3_dps(storage_t stgVar229, array_number_t x_dps, array_number_t y_dps, array_number_t z_dps, card_t x_shp, card_t y_shp, card_t z_shp) {
	card_t size235 = width_card_t(TOP_LEVEL_linalg_vectorAdd_shp(x_shp, y_shp));
	array_number_t stgVar230 = storage_alloc(size235);
	array_number_t macroDef234;
	macroDef234 = TOP_LEVEL_linalg_vectorAdd_dps(stgVar229, TOP_LEVEL_linalg_vectorAdd_dps(stgVar230, x_dps, y_dps, x_shp, y_shp), z_dps, TOP_LEVEL_linalg_vectorAdd_shp(x_shp, y_shp), z_shp);;
	storage_free(stgVar230, size235);
	return macroDef234;
}
typedef empty_env_t env_t_244;


value_t lambda244(env_t_244* env241, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
card_t TOP_LEVEL_linalg_vectorSub_shp(card_t x_shp, card_t y_shp) {
	env_t_244 env_t_244_value = make_empty_env(); closure_t closure243 = make_closure(lambda244, &env_t_244_value);
	return TOP_LEVEL_linalg_vectorMap2_shp(closure243, x_shp, y_shp);
}

typedef empty_env_t env_t_251;


value_t lambda251(env_t_251* env245, storage_t stgVar240, number_t x_dps0, number_t y_dps0, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.number_t_value = (x_dps0) - (y_dps0);
	return res;
}
typedef empty_env_t env_t_252;


value_t lambda252(env_t_252* env248, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
array_number_t TOP_LEVEL_linalg_vectorSub_dps(storage_t stgVar236, array_number_t x_dps, array_number_t y_dps, card_t x_shp, card_t y_shp) {
	env_t_251 env_t_251_value = make_empty_env(); closure_t closure247 = make_closure(lambda251, &env_t_251_value);
	env_t_252 env_t_252_value = make_empty_env(); closure_t closure250 = make_closure(lambda252, &env_t_252_value);
	return TOP_LEVEL_linalg_vectorMap2_dps(stgVar236, closure247, x_dps, y_dps, closure250, x_shp, y_shp);
}
typedef empty_env_t env_t_263;


value_t lambda263(env_t_263* env260, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = TOP_LEVEL_linalg_vectorAdd_shp(x_shp0, y_shp0);
	return res;
}
matrix_shape_t TOP_LEVEL_linalg_matrixAdd_shp(matrix_shape_t x_shp, matrix_shape_t y_shp) {
	env_t_263 env_t_263_value = make_empty_env(); closure_t closure262 = make_closure(lambda263, &env_t_263_value);
	return TOP_LEVEL_linalg_matrixMap2_shp(closure262, x_shp, y_shp);
}

typedef empty_env_t env_t_270;


value_t lambda270(env_t_270* env264, storage_t stgVar257, array_number_t x_dps0, array_number_t y_dps0, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.array_number_t_value = TOP_LEVEL_linalg_vectorAdd_dps(stgVar257, x_dps0, y_dps0, x_shp0, y_shp0);
	return res;
}
typedef empty_env_t env_t_271;


value_t lambda271(env_t_271* env267, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = TOP_LEVEL_linalg_vectorAdd_shp(x_shp0, y_shp0);
	return res;
}
array_array_number_t TOP_LEVEL_linalg_matrixAdd_dps(storage_t stgVar253, array_array_number_t x_dps, array_array_number_t y_dps, matrix_shape_t x_shp, matrix_shape_t y_shp) {
	env_t_270 env_t_270_value = make_empty_env(); closure_t closure266 = make_closure(lambda270, &env_t_270_value);
	env_t_271 env_t_271_value = make_empty_env(); closure_t closure269 = make_closure(lambda271, &env_t_271_value);
	return TOP_LEVEL_linalg_matrixMap2_dps(stgVar253, closure266, x_dps, y_dps, closure269, x_shp, y_shp);
}
typedef empty_env_t env_t_282;


value_t lambda282(env_t_282* env279, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = TOP_LEVEL_linalg_mult_vec_elementwise_shp(x_shp0, y_shp0);
	return res;
}
matrix_shape_t TOP_LEVEL_linalg_matrixMultElementwise_shp(matrix_shape_t x_shp, matrix_shape_t y_shp) {
	env_t_282 env_t_282_value = make_empty_env(); closure_t closure281 = make_closure(lambda282, &env_t_282_value);
	return TOP_LEVEL_linalg_matrixMap2_shp(closure281, x_shp, y_shp);
}

typedef empty_env_t env_t_289;


value_t lambda289(env_t_289* env283, storage_t stgVar276, array_number_t x_dps0, array_number_t y_dps0, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.array_number_t_value = TOP_LEVEL_linalg_mult_vec_elementwise_dps(stgVar276, x_dps0, y_dps0, x_shp0, y_shp0);
	return res;
}
typedef empty_env_t env_t_290;


value_t lambda290(env_t_290* env286, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = TOP_LEVEL_linalg_mult_vec_elementwise_shp(x_shp0, y_shp0);
	return res;
}
array_array_number_t TOP_LEVEL_linalg_matrixMultElementwise_dps(storage_t stgVar272, array_array_number_t x_dps, array_array_number_t y_dps, matrix_shape_t x_shp, matrix_shape_t y_shp) {
	env_t_289 env_t_289_value = make_empty_env(); closure_t closure285 = make_closure(lambda289, &env_t_289_value);
	env_t_290 env_t_290_value = make_empty_env(); closure_t closure288 = make_closure(lambda290, &env_t_290_value);
	return TOP_LEVEL_linalg_matrixMap2_dps(stgVar272, closure285, x_dps, y_dps, closure288, x_shp, y_shp);
}

card_t TOP_LEVEL_linalg_sqnorm_shp(card_t x_shp) {
	
	return 0;
}

typedef empty_env_t env_t_309;


value_t lambda309(env_t_309* env296, card_t x1_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef empty_env_t env_t_310;


value_t lambda310(env_t_310* env299, storage_t stgVar295, number_t x1_dps, card_t x1_shp) {
	
	value_t res;
	res.number_t_value = (x1_dps) * (x1_dps);
	return res;
}
typedef empty_env_t env_t_311;


value_t lambda311(env_t_311* env302, card_t x1_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef empty_env_t env_t_312;


value_t lambda312(env_t_312* env305, card_t x1_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
number_t TOP_LEVEL_linalg_sqnorm_dps(storage_t stgVar291, array_number_t x_dps, card_t x_shp) {
	env_t_309 env_t_309_value = make_empty_env(); closure_t closure298 = make_closure(lambda309, &env_t_309_value);
	card_t size313 = width_card_t(TOP_LEVEL_linalg_vectorMap_shp(closure298, x_shp));
	array_number_t stgVar292 = storage_alloc(size313);
	number_t macroDef308;env_t_310 env_t_310_value = make_empty_env(); closure_t closure301 = make_closure(lambda310, &env_t_310_value);
	env_t_311 env_t_311_value = make_empty_env(); closure_t closure304 = make_closure(lambda311, &env_t_311_value);
	env_t_312 env_t_312_value = make_empty_env(); closure_t closure307 = make_closure(lambda312, &env_t_312_value);
	macroDef308 = TOP_LEVEL_linalg_vectorSum_dps(stgVar291, TOP_LEVEL_linalg_vectorMap_dps(stgVar292, closure301, x_dps, closure304, x_shp), TOP_LEVEL_linalg_vectorMap_shp(closure307, x_shp));;
	storage_free(stgVar292, size313);
	return macroDef308;
}

card_t TOP_LEVEL_linalg_dot_prod_shp(card_t x_shp, card_t y_shp) {
	
	return 0;
}

typedef empty_env_t env_t_333;


value_t lambda333(env_t_333* env320, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef empty_env_t env_t_334;


value_t lambda334(env_t_334* env323, storage_t stgVar319, number_t x_dps0, number_t y_dps0, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.number_t_value = (x_dps0) * (y_dps0);
	return res;
}
typedef empty_env_t env_t_335;


value_t lambda335(env_t_335* env326, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef empty_env_t env_t_336;


value_t lambda336(env_t_336* env329, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
number_t TOP_LEVEL_linalg_dot_prod_dps(storage_t stgVar314, array_number_t x_dps, array_number_t y_dps, card_t x_shp, card_t y_shp) {
	env_t_333 env_t_333_value = make_empty_env(); closure_t closure322 = make_closure(lambda333, &env_t_333_value);
	card_t size337 = width_card_t(TOP_LEVEL_linalg_vectorMap2_shp(closure322, x_shp, y_shp));
	array_number_t stgVar315 = storage_alloc(size337);
	number_t macroDef332;env_t_334 env_t_334_value = make_empty_env(); closure_t closure325 = make_closure(lambda334, &env_t_334_value);
	env_t_335 env_t_335_value = make_empty_env(); closure_t closure328 = make_closure(lambda335, &env_t_335_value);
	env_t_336 env_t_336_value = make_empty_env(); closure_t closure331 = make_closure(lambda336, &env_t_336_value);
	macroDef332 = TOP_LEVEL_linalg_vectorSum_dps(stgVar314, TOP_LEVEL_linalg_vectorMap2_dps(stgVar315, closure325, x_dps, y_dps, closure328, x_shp, y_shp), TOP_LEVEL_linalg_vectorMap2_shp(closure331, x_shp, y_shp));;
	storage_free(stgVar315, size337);
	return macroDef332;
}
typedef struct env_t_348 {
	card_t row_shp;
} env_t_348;
env_t_348 make_env_t_348(card_t row_shp) {
	env_t_348 env;
	env.row_shp = row_shp;
	return env;
}

value_t lambda348(env_t_348* env345, card_t r_shp) {
	card_t row_shp344 = env345->row_shp;
	value_t res;
	res.card_t_value = row_shp344;
	return res;
}
matrix_shape_t TOP_LEVEL_linalg_matrixFillFromVector_shp(card_t rows_shp, card_t row_shp) {
	env_t_348 env_t_348_value = make_env_t_348(row_shp); closure_t closure347 = make_closure(lambda348, &env_t_348_value);
	return TOP_LEVEL_linalg_vectorMapToMatrix_shp(closure347, TOP_LEVEL_linalg_vectorRange_shp(1, rows_shp));
}

typedef struct env_t_358 {
	array_number_t row_dps;
} env_t_358;
env_t_358 make_env_t_358(array_number_t row_dps) {
	env_t_358 env;
	env.row_dps = row_dps;
	return env;
}

value_t lambda358(env_t_358* env350, storage_t stgVar341, number_t r_dps, card_t r_shp) {
	array_number_t row_dps349 = env350->row_dps;
	value_t res;
	res.array_number_t_value = row_dps349;
	return res;
}
typedef struct env_t_359 {
	card_t row_shp;
} env_t_359;
env_t_359 make_env_t_359(card_t row_shp) {
	env_t_359 env;
	env.row_shp = row_shp;
	return env;
}

value_t lambda359(env_t_359* env354, card_t r_shp) {
	card_t row_shp353 = env354->row_shp;
	value_t res;
	res.card_t_value = row_shp353;
	return res;
}
array_array_number_t TOP_LEVEL_linalg_matrixFillFromVector_dps(storage_t stgVar338, card_t rows_dps, array_number_t row_dps, card_t rows_shp, card_t row_shp) {
	card_t size360 = width_card_t(TOP_LEVEL_linalg_vectorRange_shp(1, rows_shp));
	array_number_t stgVar340 = storage_alloc(size360);
	array_array_number_t macroDef357;env_t_358 env_t_358_value = make_env_t_358(row_dps); closure_t closure352 = make_closure(lambda358, &env_t_358_value);
	env_t_359 env_t_359_value = make_env_t_359(row_shp); closure_t closure356 = make_closure(lambda359, &env_t_359_value);
	macroDef357 = TOP_LEVEL_linalg_vectorMapToMatrix_dps(stgVar338, closure352, TOP_LEVEL_linalg_vectorRange_dps(stgVar340, 1, rows_dps, 1, rows_shp), closure356, TOP_LEVEL_linalg_vectorRange_shp(1, rows_shp));;
	storage_free(stgVar340, size360);
	return macroDef357;
}

matrix_shape_t TOP_LEVEL_linalg_matrixFill_shp(card_t rows_shp, card_t cols_shp, card_t value_shp) {
	
	return nested_shape_card_t(cols_shp, rows_shp);
}


array_array_number_t TOP_LEVEL_linalg_matrixFill_dps(storage_t stgVar361, card_t rows_dps, card_t cols_dps, number_t value_dps, card_t rows_shp, card_t cols_shp, card_t value_shp) {
	array_array_number_t macroDef365 = (array_array_number_t)stgVar361;
		macroDef365->length=rows_dps;
		macroDef365->arr=(array_number_t*)(STG_OFFSET(macroDef365, VECTOR_HEADER_BYTES));
		storage_t stgVar362 = (STG_OFFSET(macroDef365, MATRIX_HEADER_BYTES(rows_dps)));
		for(int r_dps = 0; r_dps < macroDef365->length; r_dps++){
			array_number_t macroDef364 = (array_number_t)stgVar362;
		macroDef364->length=cols_dps;
		macroDef364->arr=(number_t*)(STG_OFFSET(macroDef364, VECTOR_HEADER_BYTES));
		storage_t stgVar363 = macroDef364;
		for(int c_dps = 0; c_dps < macroDef364->length; c_dps++){
			
			macroDef364->arr[c_dps] = value_dps;;
			stgVar363 = STG_OFFSET(stgVar363, sizeof(number_t));
		}
			macroDef365->arr[r_dps] = macroDef364;;
			stgVar362 = STG_OFFSET(stgVar362, VECTOR_ALL_BYTES(macroDef365->arr[r_dps]->length));
		}
	return macroDef365;
}

matrix_shape_t TOP_LEVEL_linalg_matrixTranspose_shp(matrix_shape_t m_shp) {
	
	return nested_shape_card_t(m_shp.card, m_shp.elem);
}


array_array_number_t TOP_LEVEL_linalg_matrixTranspose_dps(storage_t stgVar366, array_array_number_t m_dps, matrix_shape_t m_shp) {
	card_t rows_shp = m_shp.card;
	card_t macroDef378 = m_dps->length;
	card_t rows_dps = macroDef378;
	card_t cols_shp = m_shp.elem;
	card_t size384 = width_card_t(m_shp.elem);
	array_number_t stgVar370 = storage_alloc(size384);
	card_t macroDef380;card_t macroDef379 = m_dps->arr[0]->length;
	macroDef380 = macroDef379;;
	storage_free(stgVar370, size384);
	card_t cols_dps = macroDef380;
	array_array_number_t macroDef383 = (array_array_number_t)stgVar366;
		macroDef383->length=cols_dps;
		macroDef383->arr=(array_number_t*)(STG_OFFSET(macroDef383, VECTOR_HEADER_BYTES));
		storage_t stgVar372 = (STG_OFFSET(macroDef383, MATRIX_HEADER_BYTES(cols_dps)));
		for(int i_dps = 0; i_dps < macroDef383->length; i_dps++){
			array_number_t macroDef382 = (array_number_t)stgVar372;
		macroDef382->length=rows_dps;
		macroDef382->arr=(number_t*)(STG_OFFSET(macroDef382, VECTOR_HEADER_BYTES));
		storage_t stgVar373 = macroDef382;
		for(int j_dps = 0; j_dps < macroDef382->length; j_dps++){
			card_t size385 = width_card_t(m_shp.elem);
	array_number_t stgVar374 = storage_alloc(size385);
	number_t macroDef381;
	macroDef381 = m_dps->arr[j_dps]->arr[i_dps];;
	storage_free(stgVar374, size385);
			macroDef382->arr[j_dps] = macroDef381;;
			stgVar373 = STG_OFFSET(stgVar373, sizeof(number_t));
		}
			macroDef383->arr[i_dps] = macroDef382;;
			stgVar372 = STG_OFFSET(stgVar372, VECTOR_ALL_BYTES(macroDef383->arr[i_dps]->length));
		}
	return macroDef383;
}

matrix_shape_t TOP_LEVEL_linalg_matrixMult_shp(matrix_shape_t m1_shp, matrix_shape_t m2_shp) {
	
	return nested_shape_card_t(m2_shp.elem, m1_shp.card);
}


array_array_number_t TOP_LEVEL_linalg_matrixMult_dps(storage_t stgVar386, array_array_number_t m1_dps, array_array_number_t m2_dps, matrix_shape_t m1_shp, matrix_shape_t m2_shp) {
	card_t r1_shp = m1_shp.card;
	card_t macroDef425 = m1_dps->length;
	card_t r1_dps = macroDef425;
	card_t c2_shp = m2_shp.elem;
	card_t size436 = width_card_t(m2_shp.elem);
	array_number_t stgVar390 = storage_alloc(size436);
	card_t macroDef427;card_t macroDef426 = m2_dps->arr[0]->length;
	macroDef427 = macroDef426;;
	storage_free(stgVar390, size436);
	card_t c2_dps = macroDef427;
	card_t c1_shp = m1_shp.elem;
	card_t size437 = width_card_t(m1_shp.elem);
	array_number_t stgVar393 = storage_alloc(size437);
	card_t macroDef429;card_t macroDef428 = m1_dps->arr[0]->length;
	macroDef429 = macroDef428;;
	storage_free(stgVar393, size437);
	card_t c1_dps = macroDef429;
	card_t r2_shp = m2_shp.card;
	card_t macroDef430 = m2_dps->length;
	card_t r2_dps = macroDef430;
	matrix_shape_t m2T_shp = TOP_LEVEL_linalg_matrixTranspose_shp(m2_shp);
	card_t size440 = width_matrix_shape_t(m2T_shp);
	array_number_t stgVar397 = storage_alloc(size440);
	array_array_number_t macroDef435;array_array_number_t m2T_dps = TOP_LEVEL_linalg_matrixTranspose_dps(stgVar397, m2_dps, m2_shp);
	array_array_number_t macroDef434 = (array_array_number_t)stgVar386;
		macroDef434->length=r1_dps;
		macroDef434->arr=(array_number_t*)(STG_OFFSET(macroDef434, VECTOR_HEADER_BYTES));
		storage_t stgVar399 = (STG_OFFSET(macroDef434, MATRIX_HEADER_BYTES(r1_dps)));
		for(int r_dps = 0; r_dps < macroDef434->length; r_dps++){
			array_number_t macroDef433 = (array_number_t)stgVar399;
		macroDef433->length=c2_dps;
		macroDef433->arr=(number_t*)(STG_OFFSET(macroDef433, VECTOR_HEADER_BYTES));
		storage_t stgVar400 = macroDef433;
		for(int c_dps = 0; c_dps < macroDef433->length; c_dps++){
			card_t size439 = width_card_t(m2T_shp.elem);
	array_number_t stgVar402 = storage_alloc(size439);
	number_t macroDef432;card_t size438 = width_card_t(m1_shp.elem);
	array_number_t stgVar401 = storage_alloc(size438);
	number_t macroDef431;
	macroDef431 = TOP_LEVEL_linalg_dot_prod_dps(stgVar400, m1_dps->arr[r_dps], m2T_dps->arr[c_dps], m1_shp.elem, m2T_shp.elem);;
	storage_free(stgVar401, size438);
	macroDef432 = macroDef431;;
	storage_free(stgVar402, size439);
			macroDef433->arr[c_dps] = macroDef432;;
			stgVar400 = STG_OFFSET(stgVar400, sizeof(number_t));
		}
			macroDef434->arr[r_dps] = macroDef433;;
			stgVar399 = STG_OFFSET(stgVar399, VECTOR_ALL_BYTES(macroDef434->arr[r_dps]->length));
		}
	macroDef435 = macroDef434;;
	storage_free(stgVar397, size440);
	return macroDef435;
}

card_t TOP_LEVEL_linalg_matrixVectorMult_shp(matrix_shape_t m_shp, card_t v_shp) {
	
	return TOP_LEVEL_linalg_rows_shp(m_shp);
}


array_number_t TOP_LEVEL_linalg_matrixVectorMult_dps(storage_t stgVar441, array_array_number_t m_dps, array_number_t v_dps, matrix_shape_t m_shp, card_t v_shp) {
	card_t r_shp = TOP_LEVEL_linalg_rows_shp(m_shp);
	card_t size458 = width_card_t(r_shp);
	array_number_t stgVar442 = storage_alloc(size458);
	array_number_t macroDef455;card_t r_dps = TOP_LEVEL_linalg_rows_dps(stgVar442, m_dps, m_shp);
	card_t c_shp = TOP_LEVEL_linalg_cols_shp(m_shp);
	card_t size457 = width_card_t(c_shp);
	array_number_t stgVar444 = storage_alloc(size457);
	array_number_t macroDef454;card_t c_dps = TOP_LEVEL_linalg_cols_dps(stgVar444, m_dps, m_shp);
	array_number_t macroDef453 = (array_number_t)stgVar441;
		macroDef453->length=r_dps;
		macroDef453->arr=(number_t*)(STG_OFFSET(macroDef453, VECTOR_HEADER_BYTES));
		storage_t stgVar446 = macroDef453;
		for(int i_dps = 0; i_dps < macroDef453->length; i_dps++){
			card_t size456 = width_card_t(m_shp.elem);
	array_number_t stgVar447 = storage_alloc(size456);
	number_t macroDef452;
	macroDef452 = TOP_LEVEL_linalg_dot_prod_dps(stgVar446, m_dps->arr[i_dps], v_dps, m_shp.elem, v_shp);;
	storage_free(stgVar447, size456);
			macroDef453->arr[i_dps] = macroDef452;;
			stgVar446 = STG_OFFSET(stgVar446, sizeof(number_t));
		}
	macroDef454 = macroDef453;;
	storage_free(stgVar444, size457);
	macroDef455 = macroDef454;;
	storage_free(stgVar442, size458);
	return macroDef455;
}

matrix_shape_t TOP_LEVEL_linalg_matrixConcat_shp(matrix_shape_t m1_shp, matrix_shape_t m2_shp) {
	
	return nested_shape_card_t(m1_shp.elem, (m1_shp.card) + (m2_shp.card));
}


array_array_number_t TOP_LEVEL_linalg_matrixConcat_dps(storage_t stgVar459, array_array_number_t m1_dps, array_array_number_t m2_dps, matrix_shape_t m1_shp, matrix_shape_t m2_shp) {
	card_t rows_shp = (m1_shp.card) + (m2_shp.card);
	card_t macroDef470 = m1_dps->length;
	card_t macroDef471 = m2_dps->length;
	card_t rows_dps = (macroDef470) + (macroDef471);
	card_t m1Rows_shp = 0;
	card_t macroDef472 = m1_dps->length;
	index_t m1Rows_dps = (macroDef472);
	array_array_number_t macroDef473 = (array_array_number_t)stgVar459;
		macroDef473->length=rows_dps;
		macroDef473->arr=(array_number_t*)(STG_OFFSET(macroDef473, VECTOR_HEADER_BYTES));
		storage_t stgVar465 = (STG_OFFSET(macroDef473, MATRIX_HEADER_BYTES(rows_dps)));
		for(int r_dps = 0; r_dps < macroDef473->length; r_dps++){
			array_number_t ite474 = 0;
	if((r_dps) < (m1Rows_dps)) {
		
		ite474 = m1_dps->arr[r_dps];;
	} else {
		
		ite474 = m2_dps->arr[(r_dps) - (m1Rows_dps)];;
	}
			macroDef473->arr[r_dps] = ite474;;
			stgVar465 = STG_OFFSET(stgVar465, VECTOR_ALL_BYTES(macroDef473->arr[r_dps]->length));
		}
	return macroDef473;
}

matrix_shape_t TOP_LEVEL_linalg_matrixConcatCol_shp(matrix_shape_t m1_shp, matrix_shape_t m2_shp) {
	
	return TOP_LEVEL_linalg_matrixTranspose_shp(TOP_LEVEL_linalg_matrixConcat_shp(TOP_LEVEL_linalg_matrixTranspose_shp(m1_shp), TOP_LEVEL_linalg_matrixTranspose_shp(m2_shp)));
}


array_array_number_t TOP_LEVEL_linalg_matrixConcatCol_dps(storage_t stgVar475, array_array_number_t m1_dps, array_array_number_t m2_dps, matrix_shape_t m1_shp, matrix_shape_t m2_shp) {
	matrix_shape_t m1t_shp = TOP_LEVEL_linalg_matrixTranspose_shp(m1_shp);
	card_t size490 = width_matrix_shape_t(m1t_shp);
	array_number_t stgVar476 = storage_alloc(size490);
	array_array_number_t macroDef487;array_array_number_t m1t_dps = TOP_LEVEL_linalg_matrixTranspose_dps(stgVar476, m1_dps, m1_shp);
	matrix_shape_t m2t_shp = TOP_LEVEL_linalg_matrixTranspose_shp(m2_shp);
	card_t size489 = width_matrix_shape_t(m2t_shp);
	array_number_t stgVar478 = storage_alloc(size489);
	array_array_number_t macroDef486;array_array_number_t m2t_dps = TOP_LEVEL_linalg_matrixTranspose_dps(stgVar478, m2_dps, m2_shp);
	card_t size488 = width_matrix_shape_t(TOP_LEVEL_linalg_matrixConcat_shp(m1t_shp, m2t_shp));
	array_number_t stgVar480 = storage_alloc(size488);
	array_array_number_t macroDef485;
	macroDef485 = TOP_LEVEL_linalg_matrixTranspose_dps(stgVar475, TOP_LEVEL_linalg_matrixConcat_dps(stgVar480, m1t_dps, m2t_dps, m1t_shp, m2t_shp), TOP_LEVEL_linalg_matrixConcat_shp(m1t_shp, m2t_shp));;
	storage_free(stgVar480, size488);
	macroDef486 = macroDef485;;
	storage_free(stgVar478, size489);
	macroDef487 = macroDef486;;
	storage_free(stgVar476, size490);
	return macroDef487;
}

matrix3d_shape_t TOP_LEVEL_linalg_matrix3DConcat_shp(matrix3d_shape_t m1_shp, matrix3d_shape_t m2_shp) {
	
	return nested_shape_matrix_shape_t(m1_shp.elem, (m1_shp.card) + (m2_shp.card));
}


array_array_array_number_t TOP_LEVEL_linalg_matrix3DConcat_dps(storage_t stgVar491, array_array_array_number_t m1_dps, array_array_array_number_t m2_dps, matrix3d_shape_t m1_shp, matrix3d_shape_t m2_shp) {
	card_t rows_shp = (m1_shp.card) + (m2_shp.card);
	card_t macroDef502 = m1_dps->length;
	card_t macroDef503 = m2_dps->length;
	card_t rows_dps = (macroDef502) + (macroDef503);
	card_t m1Rows_shp = 0;
	card_t macroDef504 = m1_dps->length;
	index_t m1Rows_dps = (macroDef504);
	array_array_array_number_t macroDef505 = (array_array_array_number_t)stgVar491;
		macroDef505->length=rows_dps;
		macroDef505->arr=(array_array_number_t*)(STG_OFFSET(macroDef505, VECTOR_HEADER_BYTES));
		storage_t stgVar497 = (STG_OFFSET(macroDef505, MATRIX_HEADER_BYTES(rows_dps)));
		for(int r_dps = 0; r_dps < macroDef505->length; r_dps++){
			array_array_number_t ite506 = 0;
	if((r_dps) < (m1Rows_dps)) {
		
		ite506 = m1_dps->arr[r_dps];;
	} else {
		
		ite506 = m2_dps->arr[(r_dps) - (m1Rows_dps)];;
	}
			macroDef505->arr[r_dps] = ite506;;
			stgVar497 = STG_OFFSET(stgVar497, VECTOR_ALL_BYTES(macroDef505->arr[r_dps]->length));
		}
	return macroDef505;
}

card_t TOP_LEVEL_linalg_vectorRead_shp(card_t fn_shp, card_t startLine_shp, card_t cols_shp) {
	
	return nested_shape_card_t(cols_shp, 1).elem;
}


array_number_t TOP_LEVEL_linalg_vectorRead_dps(storage_t stgVar507, string_t fn_dps, index_t startLine_dps, card_t cols_dps, card_t fn_shp, card_t startLine_shp, card_t cols_shp) {
	matrix_shape_t matrix_shp = nested_shape_card_t(cols_shp, 1);
	card_t size511 = width_matrix_shape_t(matrix_shp);
	array_number_t stgVar508 = storage_alloc(size511);
	array_number_t macroDef510;array_array_number_t matrix_dps = matrix_read_s(stgVar508, fn_dps, startLine_dps, 1, cols_dps);
	macroDef510 = matrix_dps->arr[0];;
	storage_free(stgVar508, size511);
	return macroDef510;
}

card_t TOP_LEVEL_linalg_numberRead_shp(card_t fn_shp, card_t startLine_shp) {
	
	return 0;
}


number_t TOP_LEVEL_linalg_numberRead_dps(storage_t stgVar512, string_t fn_dps, index_t startLine_dps, card_t fn_shp, card_t startLine_shp) {
	card_t vector_shp = TOP_LEVEL_linalg_vectorRead_shp(0, 0, 1);
	card_t size519 = width_card_t(vector_shp);
	array_number_t stgVar513 = storage_alloc(size519);
	number_t macroDef518;array_number_t vector_dps = TOP_LEVEL_linalg_vectorRead_dps(stgVar513, fn_dps, startLine_dps, 1, 0, 0, 1);
	macroDef518 = vector_dps->arr[0];;
	storage_free(stgVar513, size519);
	return macroDef518;
}

card_t TOP_LEVEL_linalg_vec3_shp(card_t a_shp, card_t b_shp, card_t c_shp) {
	
	return 3;
}


array_number_t TOP_LEVEL_linalg_vec3_dps(storage_t stgVar520, number_t a_dps, number_t b_dps, number_t c_dps, card_t a_shp, card_t b_shp, card_t c_shp) {
	array_number_t macroDef524 = (array_number_t)stgVar520;
	macroDef524->length=3;
	macroDef524->arr=(number_t*)(STG_OFFSET(stgVar520, VECTOR_HEADER_BYTES));
	macroDef524->arr[0] = a_dps;
	macroDef524->arr[1] = b_dps;
	macroDef524->arr[2] = c_dps;;
	return macroDef524;
}
#endif
