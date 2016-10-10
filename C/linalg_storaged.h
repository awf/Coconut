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
	card_t anfvar92_shp = TOP_LEVEL_linalg_vectorRange_shp(s_shp, e_shp);
	card_t size101 = width_card_t(anfvar92_shp);
	array_number_t stgVar93 = storage_alloc(size101);
	number_t macroDef100;array_number_t anfvar92_dps = TOP_LEVEL_linalg_vectorRange_dps(stgVar93, s_dps, e_dps, s_shp, e_shp);
	number_t macroDef99 = z_dps;
	array_number_t cur_dps_range = anfvar92_dps;
	storage_t stgVar96 = stgVar91;
	for(int cur_dps_idx = 0; cur_dps_idx < cur_dps_range->length; cur_dps_idx++){
		number_t cur_dps = cur_dps_range->arr[cur_dps_idx];
		
		macroDef99 = f_dps.lam(f_dps.env, stgVar96, macroDef99, (int)(cur_dps), 0, 0).number_t_value;;
	}
	macroDef100 = macroDef99;;
	storage_free(stgVar93, size101);
	return macroDef100;
}

card_t TOP_LEVEL_linalg_iterateVector_shp(closure_t f_shp, card_t z_shp, card_t s_shp, card_t e_shp) {
	
	return z_shp;
}


array_number_t TOP_LEVEL_linalg_iterateVector_dps(storage_t stgVar102, closure_t f_dps, array_number_t z_dps, card_t s_dps, card_t e_dps, closure_t f_shp, card_t z_shp, card_t s_shp, card_t e_shp) {
	card_t anfvar103_shp = TOP_LEVEL_linalg_vectorRange_shp(s_shp, e_shp);
	card_t size112 = width_card_t(anfvar103_shp);
	array_number_t stgVar104 = storage_alloc(size112);
	array_number_t macroDef111;array_number_t anfvar103_dps = TOP_LEVEL_linalg_vectorRange_dps(stgVar104, s_dps, e_dps, s_shp, e_shp);
	array_number_t macroDef110 = z_dps;
	array_number_t cur_dps_range = anfvar103_dps;
	storage_t stgVar107 = stgVar102;
	for(int cur_dps_idx = 0; cur_dps_idx < cur_dps_range->length; cur_dps_idx++){
		number_t cur_dps = cur_dps_range->arr[cur_dps_idx];
		
		macroDef110 = f_dps.lam(f_dps.env, stgVar107, macroDef110, (int)(cur_dps), z_shp, 0).array_number_t_value;;
	}
	macroDef111 = macroDef110;;
	storage_free(stgVar104, size112);
	return macroDef111;
}

matrix_shape_t TOP_LEVEL_linalg_iterateMatrix_shp(closure_t f_shp, matrix_shape_t z_shp, card_t s_shp, card_t e_shp) {
	
	return z_shp;
}


array_array_number_t TOP_LEVEL_linalg_iterateMatrix_dps(storage_t stgVar113, closure_t f_dps, array_array_number_t z_dps, card_t s_dps, card_t e_dps, closure_t f_shp, matrix_shape_t z_shp, card_t s_shp, card_t e_shp) {
	card_t anfvar114_shp = TOP_LEVEL_linalg_vectorRange_shp(s_shp, e_shp);
	card_t size123 = width_card_t(anfvar114_shp);
	array_number_t stgVar115 = storage_alloc(size123);
	array_array_number_t macroDef122;array_number_t anfvar114_dps = TOP_LEVEL_linalg_vectorRange_dps(stgVar115, s_dps, e_dps, s_shp, e_shp);
	array_array_number_t macroDef121 = z_dps;
	array_number_t cur_dps_range = anfvar114_dps;
	storage_t stgVar118 = stgVar113;
	for(int cur_dps_idx = 0; cur_dps_idx < cur_dps_range->length; cur_dps_idx++){
		number_t cur_dps = cur_dps_range->arr[cur_dps_idx];
		
		macroDef121 = f_dps.lam(f_dps.env, stgVar118, macroDef121, (int)(cur_dps), z_shp, 0).array_array_number_t_value;;
	}
	macroDef122 = macroDef121;;
	storage_free(stgVar115, size123);
	return macroDef122;
}

matrix3d_shape_t TOP_LEVEL_linalg_iterateMatrix3D_shp(closure_t f_shp, matrix3d_shape_t z_shp, card_t s_shp, card_t e_shp) {
	
	return z_shp;
}


array_array_array_number_t TOP_LEVEL_linalg_iterateMatrix3D_dps(storage_t stgVar124, closure_t f_dps, array_array_array_number_t z_dps, card_t s_dps, card_t e_dps, closure_t f_shp, matrix3d_shape_t z_shp, card_t s_shp, card_t e_shp) {
	card_t anfvar125_shp = TOP_LEVEL_linalg_vectorRange_shp(s_shp, e_shp);
	card_t size134 = width_card_t(anfvar125_shp);
	array_number_t stgVar126 = storage_alloc(size134);
	array_array_array_number_t macroDef133;array_number_t anfvar125_dps = TOP_LEVEL_linalg_vectorRange_dps(stgVar126, s_dps, e_dps, s_shp, e_shp);
	array_array_array_number_t macroDef132 = z_dps;
	array_number_t cur_dps_range = anfvar125_dps;
	storage_t stgVar129 = stgVar124;
	for(int cur_dps_idx = 0; cur_dps_idx < cur_dps_range->length; cur_dps_idx++){
		number_t cur_dps = cur_dps_range->arr[cur_dps_idx];
		
		macroDef132 = f_dps.lam(f_dps.env, stgVar129, macroDef132, (int)(cur_dps), z_shp, 0).array_array_array_number_t_value;;
	}
	macroDef133 = macroDef132;;
	storage_free(stgVar126, size134);
	return macroDef133;
}

card_t TOP_LEVEL_linalg_vectorSum_shp(card_t v_shp) {
	
	return 0;
}


number_t TOP_LEVEL_linalg_vectorSum_dps(storage_t stgVar135, array_number_t v_dps, card_t v_shp) {
	number_t macroDef137 = 0;
	array_number_t cur_dps_range = v_dps;
	storage_t stgVar136 = stgVar135;
	for(int cur_dps_idx = 0; cur_dps_idx < cur_dps_range->length; cur_dps_idx++){
		number_t cur_dps = cur_dps_range->arr[cur_dps_idx];
		
		macroDef137 = (macroDef137) + (cur_dps);;
	}
	return macroDef137;
}

card_t TOP_LEVEL_linalg_vectorMax_shp(card_t v_shp) {
	
	return 0;
}


number_t TOP_LEVEL_linalg_vectorMax_dps(storage_t stgVar138, array_number_t v_dps, card_t v_shp) {
	number_t macroDef140 = -1000;
	array_number_t cur_dps_range = v_dps;
	storage_t stgVar139 = stgVar138;
	for(int cur_dps_idx = 0; cur_dps_idx < cur_dps_range->length; cur_dps_idx++){
		number_t cur_dps = cur_dps_range->arr[cur_dps_idx];
		number_t ite141 = 0;
	if((macroDef140) > (cur_dps)) {
		
		ite141 = macroDef140;;
	} else {
		
		ite141 = cur_dps;;
	}
		macroDef140 = ite141;;
	}
	return macroDef140;
}
typedef empty_env_t env_t_149;


value_t lambda149(env_t_149* env146, card_t xi_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
card_t TOP_LEVEL_linalg_mult_by_scalar_shp(card_t x_shp, card_t y_shp) {
	env_t_149 env_t_149_value = make_empty_env(); closure_t closure148 = make_closure(lambda149, &env_t_149_value);
	return TOP_LEVEL_linalg_vectorMap_shp(closure148, x_shp);
}

typedef struct env_t_157 {
	number_t y_dps;
} env_t_157;
env_t_157 make_env_t_157(number_t y_dps) {
	env_t_157 env;
	env.y_dps = y_dps;
	return env;
}

value_t lambda157(env_t_157* env151, storage_t stgVar145, number_t xi_dps, card_t xi_shp) {
	number_t y_dps150 = env151->y_dps;
	value_t res;
	res.number_t_value = (xi_dps) * (y_dps150);
	return res;
}
typedef empty_env_t env_t_158;


value_t lambda158(env_t_158* env154, card_t xi_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
array_number_t TOP_LEVEL_linalg_mult_by_scalar_dps(storage_t stgVar142, array_number_t x_dps, number_t y_dps, card_t x_shp, card_t y_shp) {
	env_t_157 env_t_157_value = make_env_t_157(y_dps); closure_t closure153 = make_closure(lambda157, &env_t_157_value);
	env_t_158 env_t_158_value = make_empty_env(); closure_t closure156 = make_closure(lambda158, &env_t_158_value);
	return TOP_LEVEL_linalg_vectorMap_dps(stgVar142, closure153, x_dps, closure156, x_shp);
}
typedef empty_env_t env_t_166;


value_t lambda166(env_t_166* env163, card_t xi_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
card_t TOP_LEVEL_linalg_gaxpy_shp(card_t a_shp, card_t x_shp, card_t y_shp) {
	env_t_166 env_t_166_value = make_empty_env(); closure_t closure165 = make_closure(lambda166, &env_t_166_value);
	return TOP_LEVEL_linalg_vectorMap_shp(closure165, x_shp);
}

typedef struct env_t_175 {
	number_t y_dps;
	number_t a_dps;
} env_t_175;
env_t_175 make_env_t_175(number_t y_dps,number_t a_dps) {
	env_t_175 env;
	env.y_dps = y_dps;
	env.a_dps = a_dps;
	return env;
}

value_t lambda175(env_t_175* env169, storage_t stgVar162, number_t xi_dps, card_t xi_shp) {
	number_t y_dps168 = env169->y_dps;
	number_t a_dps167 = env169->a_dps;
	value_t res;
	res.number_t_value = ((a_dps167) * (xi_dps)) + (y_dps168);
	return res;
}
typedef empty_env_t env_t_176;


value_t lambda176(env_t_176* env172, card_t xi_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
array_number_t TOP_LEVEL_linalg_gaxpy_dps(storage_t stgVar159, number_t a_dps, array_number_t x_dps, number_t y_dps, card_t a_shp, card_t x_shp, card_t y_shp) {
	env_t_175 env_t_175_value = make_env_t_175(y_dps,a_dps); closure_t closure171 = make_closure(lambda175, &env_t_175_value);
	env_t_176 env_t_176_value = make_empty_env(); closure_t closure174 = make_closure(lambda176, &env_t_176_value);
	return TOP_LEVEL_linalg_vectorMap_dps(stgVar159, closure171, x_dps, closure174, x_shp);
}

card_t TOP_LEVEL_linalg_cross_shp(card_t a_shp, card_t b_shp) {
	
	return 3;
}


array_number_t TOP_LEVEL_linalg_cross_dps(storage_t stgVar177, array_number_t a_dps, array_number_t b_dps, card_t a_shp, card_t b_shp) {
	array_number_t macroDef193 = (array_number_t)stgVar177;
	macroDef193->length=3;
	macroDef193->arr=(number_t*)(STG_OFFSET(stgVar177, VECTOR_HEADER_BYTES));
	macroDef193->arr[0] = ((a_dps->arr[1]) * (b_dps->arr[2])) - ((a_dps->arr[2]) * (b_dps->arr[1]));
	macroDef193->arr[1] = ((a_dps->arr[2]) * (b_dps->arr[0])) - ((a_dps->arr[0]) * (b_dps->arr[2]));
	macroDef193->arr[2] = ((a_dps->arr[0]) * (b_dps->arr[1])) - ((a_dps->arr[1]) * (b_dps->arr[0]));;
	return macroDef193;
}
typedef empty_env_t env_t_202;


value_t lambda202(env_t_202* env199, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
card_t TOP_LEVEL_linalg_vectorAdd_shp(card_t x_shp, card_t y_shp) {
	env_t_202 env_t_202_value = make_empty_env(); closure_t closure201 = make_closure(lambda202, &env_t_202_value);
	return TOP_LEVEL_linalg_vectorMap2_shp(closure201, x_shp, y_shp);
}

typedef empty_env_t env_t_209;


value_t lambda209(env_t_209* env203, storage_t stgVar198, number_t x_dps0, number_t y_dps0, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.number_t_value = (x_dps0) + (y_dps0);
	return res;
}
typedef empty_env_t env_t_210;


value_t lambda210(env_t_210* env206, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
array_number_t TOP_LEVEL_linalg_vectorAdd_dps(storage_t stgVar194, array_number_t x_dps, array_number_t y_dps, card_t x_shp, card_t y_shp) {
	env_t_209 env_t_209_value = make_empty_env(); closure_t closure205 = make_closure(lambda209, &env_t_209_value);
	env_t_210 env_t_210_value = make_empty_env(); closure_t closure208 = make_closure(lambda210, &env_t_210_value);
	return TOP_LEVEL_linalg_vectorMap2_dps(stgVar194, closure205, x_dps, y_dps, closure208, x_shp, y_shp);
}
typedef empty_env_t env_t_219;


value_t lambda219(env_t_219* env216, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
card_t TOP_LEVEL_linalg_mult_vec_elementwise_shp(card_t x_shp, card_t y_shp) {
	env_t_219 env_t_219_value = make_empty_env(); closure_t closure218 = make_closure(lambda219, &env_t_219_value);
	return TOP_LEVEL_linalg_vectorMap2_shp(closure218, x_shp, y_shp);
}

typedef empty_env_t env_t_226;


value_t lambda226(env_t_226* env220, storage_t stgVar215, number_t x_dps0, number_t y_dps0, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.number_t_value = (x_dps0) * (y_dps0);
	return res;
}
typedef empty_env_t env_t_227;


value_t lambda227(env_t_227* env223, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
array_number_t TOP_LEVEL_linalg_mult_vec_elementwise_dps(storage_t stgVar211, array_number_t x_dps, array_number_t y_dps, card_t x_shp, card_t y_shp) {
	env_t_226 env_t_226_value = make_empty_env(); closure_t closure222 = make_closure(lambda226, &env_t_226_value);
	env_t_227 env_t_227_value = make_empty_env(); closure_t closure225 = make_closure(lambda227, &env_t_227_value);
	return TOP_LEVEL_linalg_vectorMap2_dps(stgVar211, closure222, x_dps, y_dps, closure225, x_shp, y_shp);
}
typedef empty_env_t env_t_236;


value_t lambda236(env_t_236* env233, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
card_t TOP_LEVEL_linalg_op_DotMultiply_shp(card_t x_shp, card_t y_shp) {
	env_t_236 env_t_236_value = make_empty_env(); closure_t closure235 = make_closure(lambda236, &env_t_236_value);
	return TOP_LEVEL_linalg_vectorMap2_shp(closure235, x_shp, y_shp);
}

typedef empty_env_t env_t_243;


value_t lambda243(env_t_243* env237, storage_t stgVar232, number_t x_dps0, number_t y_dps0, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.number_t_value = (x_dps0) * (y_dps0);
	return res;
}
typedef empty_env_t env_t_244;


value_t lambda244(env_t_244* env240, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
array_number_t TOP_LEVEL_linalg_op_DotMultiply_dps(storage_t stgVar228, array_number_t x_dps, array_number_t y_dps, card_t x_shp, card_t y_shp) {
	env_t_243 env_t_243_value = make_empty_env(); closure_t closure239 = make_closure(lambda243, &env_t_243_value);
	env_t_244 env_t_244_value = make_empty_env(); closure_t closure242 = make_closure(lambda244, &env_t_244_value);
	return TOP_LEVEL_linalg_vectorMap2_dps(stgVar228, closure239, x_dps, y_dps, closure242, x_shp, y_shp);
}

card_t TOP_LEVEL_linalg_vectorAdd3_shp(card_t x_shp, card_t y_shp, card_t z_shp) {
	
	return TOP_LEVEL_linalg_vectorAdd_shp(TOP_LEVEL_linalg_vectorAdd_shp(x_shp, y_shp), z_shp);
}


array_number_t TOP_LEVEL_linalg_vectorAdd3_dps(storage_t stgVar245, array_number_t x_dps, array_number_t y_dps, array_number_t z_dps, card_t x_shp, card_t y_shp, card_t z_shp) {
	card_t size251 = width_card_t(TOP_LEVEL_linalg_vectorAdd_shp(x_shp, y_shp));
	array_number_t stgVar246 = storage_alloc(size251);
	array_number_t macroDef250;
	macroDef250 = TOP_LEVEL_linalg_vectorAdd_dps(stgVar245, TOP_LEVEL_linalg_vectorAdd_dps(stgVar246, x_dps, y_dps, x_shp, y_shp), z_dps, TOP_LEVEL_linalg_vectorAdd_shp(x_shp, y_shp), z_shp);;
	storage_free(stgVar246, size251);
	return macroDef250;
}
typedef empty_env_t env_t_260;


value_t lambda260(env_t_260* env257, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
card_t TOP_LEVEL_linalg_vectorSub_shp(card_t x_shp, card_t y_shp) {
	env_t_260 env_t_260_value = make_empty_env(); closure_t closure259 = make_closure(lambda260, &env_t_260_value);
	return TOP_LEVEL_linalg_vectorMap2_shp(closure259, x_shp, y_shp);
}

typedef empty_env_t env_t_267;


value_t lambda267(env_t_267* env261, storage_t stgVar256, number_t x_dps0, number_t y_dps0, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.number_t_value = (x_dps0) - (y_dps0);
	return res;
}
typedef empty_env_t env_t_268;


value_t lambda268(env_t_268* env264, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
array_number_t TOP_LEVEL_linalg_vectorSub_dps(storage_t stgVar252, array_number_t x_dps, array_number_t y_dps, card_t x_shp, card_t y_shp) {
	env_t_267 env_t_267_value = make_empty_env(); closure_t closure263 = make_closure(lambda267, &env_t_267_value);
	env_t_268 env_t_268_value = make_empty_env(); closure_t closure266 = make_closure(lambda268, &env_t_268_value);
	return TOP_LEVEL_linalg_vectorMap2_dps(stgVar252, closure263, x_dps, y_dps, closure266, x_shp, y_shp);
}
typedef empty_env_t env_t_279;


value_t lambda279(env_t_279* env276, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = TOP_LEVEL_linalg_vectorAdd_shp(x_shp0, y_shp0);
	return res;
}
matrix_shape_t TOP_LEVEL_linalg_matrixAdd_shp(matrix_shape_t x_shp, matrix_shape_t y_shp) {
	env_t_279 env_t_279_value = make_empty_env(); closure_t closure278 = make_closure(lambda279, &env_t_279_value);
	return TOP_LEVEL_linalg_matrixMap2_shp(closure278, x_shp, y_shp);
}

typedef empty_env_t env_t_286;


value_t lambda286(env_t_286* env280, storage_t stgVar273, array_number_t x_dps0, array_number_t y_dps0, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.array_number_t_value = TOP_LEVEL_linalg_vectorAdd_dps(stgVar273, x_dps0, y_dps0, x_shp0, y_shp0);
	return res;
}
typedef empty_env_t env_t_287;


value_t lambda287(env_t_287* env283, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = TOP_LEVEL_linalg_vectorAdd_shp(x_shp0, y_shp0);
	return res;
}
array_array_number_t TOP_LEVEL_linalg_matrixAdd_dps(storage_t stgVar269, array_array_number_t x_dps, array_array_number_t y_dps, matrix_shape_t x_shp, matrix_shape_t y_shp) {
	env_t_286 env_t_286_value = make_empty_env(); closure_t closure282 = make_closure(lambda286, &env_t_286_value);
	env_t_287 env_t_287_value = make_empty_env(); closure_t closure285 = make_closure(lambda287, &env_t_287_value);
	return TOP_LEVEL_linalg_matrixMap2_dps(stgVar269, closure282, x_dps, y_dps, closure285, x_shp, y_shp);
}
typedef empty_env_t env_t_298;


value_t lambda298(env_t_298* env295, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = TOP_LEVEL_linalg_mult_vec_elementwise_shp(x_shp0, y_shp0);
	return res;
}
matrix_shape_t TOP_LEVEL_linalg_matrixMultElementwise_shp(matrix_shape_t x_shp, matrix_shape_t y_shp) {
	env_t_298 env_t_298_value = make_empty_env(); closure_t closure297 = make_closure(lambda298, &env_t_298_value);
	return TOP_LEVEL_linalg_matrixMap2_shp(closure297, x_shp, y_shp);
}

typedef empty_env_t env_t_305;


value_t lambda305(env_t_305* env299, storage_t stgVar292, array_number_t x_dps0, array_number_t y_dps0, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.array_number_t_value = TOP_LEVEL_linalg_mult_vec_elementwise_dps(stgVar292, x_dps0, y_dps0, x_shp0, y_shp0);
	return res;
}
typedef empty_env_t env_t_306;


value_t lambda306(env_t_306* env302, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = TOP_LEVEL_linalg_mult_vec_elementwise_shp(x_shp0, y_shp0);
	return res;
}
array_array_number_t TOP_LEVEL_linalg_matrixMultElementwise_dps(storage_t stgVar288, array_array_number_t x_dps, array_array_number_t y_dps, matrix_shape_t x_shp, matrix_shape_t y_shp) {
	env_t_305 env_t_305_value = make_empty_env(); closure_t closure301 = make_closure(lambda305, &env_t_305_value);
	env_t_306 env_t_306_value = make_empty_env(); closure_t closure304 = make_closure(lambda306, &env_t_306_value);
	return TOP_LEVEL_linalg_matrixMap2_dps(stgVar288, closure301, x_dps, y_dps, closure304, x_shp, y_shp);
}

card_t TOP_LEVEL_linalg_sqnorm_shp(card_t x_shp) {
	
	return 0;
}

typedef empty_env_t env_t_325;


value_t lambda325(env_t_325* env312, card_t x1_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef empty_env_t env_t_326;


value_t lambda326(env_t_326* env315, storage_t stgVar311, number_t x1_dps, card_t x1_shp) {
	
	value_t res;
	res.number_t_value = (x1_dps) * (x1_dps);
	return res;
}
typedef empty_env_t env_t_327;


value_t lambda327(env_t_327* env318, card_t x1_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef empty_env_t env_t_328;


value_t lambda328(env_t_328* env321, card_t x1_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
number_t TOP_LEVEL_linalg_sqnorm_dps(storage_t stgVar307, array_number_t x_dps, card_t x_shp) {
	env_t_325 env_t_325_value = make_empty_env(); closure_t closure314 = make_closure(lambda325, &env_t_325_value);
	card_t size329 = width_card_t(TOP_LEVEL_linalg_vectorMap_shp(closure314, x_shp));
	array_number_t stgVar308 = storage_alloc(size329);
	number_t macroDef324;env_t_326 env_t_326_value = make_empty_env(); closure_t closure317 = make_closure(lambda326, &env_t_326_value);
	env_t_327 env_t_327_value = make_empty_env(); closure_t closure320 = make_closure(lambda327, &env_t_327_value);
	env_t_328 env_t_328_value = make_empty_env(); closure_t closure323 = make_closure(lambda328, &env_t_328_value);
	macroDef324 = TOP_LEVEL_linalg_vectorSum_dps(stgVar307, TOP_LEVEL_linalg_vectorMap_dps(stgVar308, closure317, x_dps, closure320, x_shp), TOP_LEVEL_linalg_vectorMap_shp(closure323, x_shp));;
	storage_free(stgVar308, size329);
	return macroDef324;
}

card_t TOP_LEVEL_linalg_dot_prod_shp(card_t x_shp, card_t y_shp) {
	
	return 0;
}

typedef empty_env_t env_t_349;


value_t lambda349(env_t_349* env336, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef empty_env_t env_t_350;


value_t lambda350(env_t_350* env339, storage_t stgVar335, number_t x_dps0, number_t y_dps0, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.number_t_value = (x_dps0) * (y_dps0);
	return res;
}
typedef empty_env_t env_t_351;


value_t lambda351(env_t_351* env342, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef empty_env_t env_t_352;


value_t lambda352(env_t_352* env345, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
number_t TOP_LEVEL_linalg_dot_prod_dps(storage_t stgVar330, array_number_t x_dps, array_number_t y_dps, card_t x_shp, card_t y_shp) {
	env_t_349 env_t_349_value = make_empty_env(); closure_t closure338 = make_closure(lambda349, &env_t_349_value);
	card_t size353 = width_card_t(TOP_LEVEL_linalg_vectorMap2_shp(closure338, x_shp, y_shp));
	array_number_t stgVar331 = storage_alloc(size353);
	number_t macroDef348;env_t_350 env_t_350_value = make_empty_env(); closure_t closure341 = make_closure(lambda350, &env_t_350_value);
	env_t_351 env_t_351_value = make_empty_env(); closure_t closure344 = make_closure(lambda351, &env_t_351_value);
	env_t_352 env_t_352_value = make_empty_env(); closure_t closure347 = make_closure(lambda352, &env_t_352_value);
	macroDef348 = TOP_LEVEL_linalg_vectorSum_dps(stgVar330, TOP_LEVEL_linalg_vectorMap2_dps(stgVar331, closure341, x_dps, y_dps, closure344, x_shp, y_shp), TOP_LEVEL_linalg_vectorMap2_shp(closure347, x_shp, y_shp));;
	storage_free(stgVar331, size353);
	return macroDef348;
}
typedef struct env_t_364 {
	card_t row_shp;
} env_t_364;
env_t_364 make_env_t_364(card_t row_shp) {
	env_t_364 env;
	env.row_shp = row_shp;
	return env;
}

value_t lambda364(env_t_364* env361, card_t r_shp) {
	card_t row_shp360 = env361->row_shp;
	value_t res;
	res.card_t_value = row_shp360;
	return res;
}
matrix_shape_t TOP_LEVEL_linalg_matrixFillFromVector_shp(card_t rows_shp, card_t row_shp) {
	env_t_364 env_t_364_value = make_env_t_364(row_shp); closure_t closure363 = make_closure(lambda364, &env_t_364_value);
	return TOP_LEVEL_linalg_vectorMapToMatrix_shp(closure363, TOP_LEVEL_linalg_vectorRange_shp(1, rows_shp));
}

typedef struct env_t_374 {
	array_number_t row_dps;
} env_t_374;
env_t_374 make_env_t_374(array_number_t row_dps) {
	env_t_374 env;
	env.row_dps = row_dps;
	return env;
}

value_t lambda374(env_t_374* env366, storage_t stgVar357, number_t r_dps, card_t r_shp) {
	array_number_t row_dps365 = env366->row_dps;
	value_t res;
	res.array_number_t_value = row_dps365;
	return res;
}
typedef struct env_t_375 {
	card_t row_shp;
} env_t_375;
env_t_375 make_env_t_375(card_t row_shp) {
	env_t_375 env;
	env.row_shp = row_shp;
	return env;
}

value_t lambda375(env_t_375* env370, card_t r_shp) {
	card_t row_shp369 = env370->row_shp;
	value_t res;
	res.card_t_value = row_shp369;
	return res;
}
array_array_number_t TOP_LEVEL_linalg_matrixFillFromVector_dps(storage_t stgVar354, card_t rows_dps, array_number_t row_dps, card_t rows_shp, card_t row_shp) {
	card_t size376 = width_card_t(TOP_LEVEL_linalg_vectorRange_shp(1, rows_shp));
	array_number_t stgVar356 = storage_alloc(size376);
	array_array_number_t macroDef373;env_t_374 env_t_374_value = make_env_t_374(row_dps); closure_t closure368 = make_closure(lambda374, &env_t_374_value);
	env_t_375 env_t_375_value = make_env_t_375(row_shp); closure_t closure372 = make_closure(lambda375, &env_t_375_value);
	macroDef373 = TOP_LEVEL_linalg_vectorMapToMatrix_dps(stgVar354, closure368, TOP_LEVEL_linalg_vectorRange_dps(stgVar356, 1, rows_dps, 1, rows_shp), closure372, TOP_LEVEL_linalg_vectorRange_shp(1, rows_shp));;
	storage_free(stgVar356, size376);
	return macroDef373;
}

matrix_shape_t TOP_LEVEL_linalg_matrixFill_shp(card_t rows_shp, card_t cols_shp, card_t value_shp) {
	
	return nested_shape_card_t(cols_shp, rows_shp);
}


array_array_number_t TOP_LEVEL_linalg_matrixFill_dps(storage_t stgVar377, card_t rows_dps, card_t cols_dps, number_t value_dps, card_t rows_shp, card_t cols_shp, card_t value_shp) {
	array_array_number_t macroDef381 = (array_array_number_t)stgVar377;
		macroDef381->length=rows_dps;
		macroDef381->arr=(array_number_t*)(STG_OFFSET(macroDef381, VECTOR_HEADER_BYTES));
		storage_t stgVar378 = (STG_OFFSET(macroDef381, MATRIX_HEADER_BYTES(rows_dps)));
		for(int r_dps = 0; r_dps < macroDef381->length; r_dps++){
			array_number_t macroDef380 = (array_number_t)stgVar378;
		macroDef380->length=cols_dps;
		macroDef380->arr=(number_t*)(STG_OFFSET(macroDef380, VECTOR_HEADER_BYTES));
		storage_t stgVar379 = macroDef380;
		for(int c_dps = 0; c_dps < macroDef380->length; c_dps++){
			
			macroDef380->arr[c_dps] = value_dps;;
			stgVar379 = STG_OFFSET(stgVar379, sizeof(number_t));
		}
			macroDef381->arr[r_dps] = macroDef380;;
			stgVar378 = STG_OFFSET(stgVar378, VECTOR_ALL_BYTES(macroDef381->arr[r_dps]->length));
		}
	return macroDef381;
}

matrix_shape_t TOP_LEVEL_linalg_matrixTranspose_shp(matrix_shape_t m_shp) {
	
	return nested_shape_card_t(m_shp.card, m_shp.elem);
}


array_array_number_t TOP_LEVEL_linalg_matrixTranspose_dps(storage_t stgVar382, array_array_number_t m_dps, matrix_shape_t m_shp) {
	card_t rows_shp = m_shp.card;
	card_t macroDef394 = m_dps->length;
	card_t rows_dps = macroDef394;
	card_t cols_shp = m_shp.elem;
	card_t size400 = width_card_t(m_shp.elem);
	array_number_t stgVar386 = storage_alloc(size400);
	card_t macroDef396;card_t macroDef395 = m_dps->arr[0]->length;
	macroDef396 = macroDef395;;
	storage_free(stgVar386, size400);
	card_t cols_dps = macroDef396;
	array_array_number_t macroDef399 = (array_array_number_t)stgVar382;
		macroDef399->length=cols_dps;
		macroDef399->arr=(array_number_t*)(STG_OFFSET(macroDef399, VECTOR_HEADER_BYTES));
		storage_t stgVar388 = (STG_OFFSET(macroDef399, MATRIX_HEADER_BYTES(cols_dps)));
		for(int i_dps = 0; i_dps < macroDef399->length; i_dps++){
			array_number_t macroDef398 = (array_number_t)stgVar388;
		macroDef398->length=rows_dps;
		macroDef398->arr=(number_t*)(STG_OFFSET(macroDef398, VECTOR_HEADER_BYTES));
		storage_t stgVar389 = macroDef398;
		for(int j_dps = 0; j_dps < macroDef398->length; j_dps++){
			card_t size401 = width_card_t(m_shp.elem);
	array_number_t stgVar390 = storage_alloc(size401);
	number_t macroDef397;
	macroDef397 = m_dps->arr[j_dps]->arr[i_dps];;
	storage_free(stgVar390, size401);
			macroDef398->arr[j_dps] = macroDef397;;
			stgVar389 = STG_OFFSET(stgVar389, sizeof(number_t));
		}
			macroDef399->arr[i_dps] = macroDef398;;
			stgVar388 = STG_OFFSET(stgVar388, VECTOR_ALL_BYTES(macroDef399->arr[i_dps]->length));
		}
	return macroDef399;
}

matrix_shape_t TOP_LEVEL_linalg_matrixMult_shp(matrix_shape_t m1_shp, matrix_shape_t m2_shp) {
	
	return nested_shape_card_t(m2_shp.elem, m1_shp.card);
}


array_array_number_t TOP_LEVEL_linalg_matrixMult_dps(storage_t stgVar402, array_array_number_t m1_dps, array_array_number_t m2_dps, matrix_shape_t m1_shp, matrix_shape_t m2_shp) {
	card_t r1_shp = m1_shp.card;
	card_t macroDef441 = m1_dps->length;
	card_t r1_dps = macroDef441;
	card_t c2_shp = m2_shp.elem;
	card_t size452 = width_card_t(m2_shp.elem);
	array_number_t stgVar406 = storage_alloc(size452);
	card_t macroDef443;card_t macroDef442 = m2_dps->arr[0]->length;
	macroDef443 = macroDef442;;
	storage_free(stgVar406, size452);
	card_t c2_dps = macroDef443;
	card_t c1_shp = m1_shp.elem;
	card_t size453 = width_card_t(m1_shp.elem);
	array_number_t stgVar409 = storage_alloc(size453);
	card_t macroDef445;card_t macroDef444 = m1_dps->arr[0]->length;
	macroDef445 = macroDef444;;
	storage_free(stgVar409, size453);
	card_t c1_dps = macroDef445;
	card_t r2_shp = m2_shp.card;
	card_t macroDef446 = m2_dps->length;
	card_t r2_dps = macroDef446;
	matrix_shape_t m2T_shp = TOP_LEVEL_linalg_matrixTranspose_shp(m2_shp);
	card_t size456 = width_matrix_shape_t(m2T_shp);
	array_number_t stgVar413 = storage_alloc(size456);
	array_array_number_t macroDef451;array_array_number_t m2T_dps = TOP_LEVEL_linalg_matrixTranspose_dps(stgVar413, m2_dps, m2_shp);
	array_array_number_t macroDef450 = (array_array_number_t)stgVar402;
		macroDef450->length=r1_dps;
		macroDef450->arr=(array_number_t*)(STG_OFFSET(macroDef450, VECTOR_HEADER_BYTES));
		storage_t stgVar415 = (STG_OFFSET(macroDef450, MATRIX_HEADER_BYTES(r1_dps)));
		for(int r_dps = 0; r_dps < macroDef450->length; r_dps++){
			array_number_t macroDef449 = (array_number_t)stgVar415;
		macroDef449->length=c2_dps;
		macroDef449->arr=(number_t*)(STG_OFFSET(macroDef449, VECTOR_HEADER_BYTES));
		storage_t stgVar416 = macroDef449;
		for(int c_dps = 0; c_dps < macroDef449->length; c_dps++){
			card_t size455 = width_card_t(m2T_shp.elem);
	array_number_t stgVar418 = storage_alloc(size455);
	number_t macroDef448;card_t size454 = width_card_t(m1_shp.elem);
	array_number_t stgVar417 = storage_alloc(size454);
	number_t macroDef447;
	macroDef447 = TOP_LEVEL_linalg_dot_prod_dps(stgVar416, m1_dps->arr[r_dps], m2T_dps->arr[c_dps], m1_shp.elem, m2T_shp.elem);;
	storage_free(stgVar417, size454);
	macroDef448 = macroDef447;;
	storage_free(stgVar418, size455);
			macroDef449->arr[c_dps] = macroDef448;;
			stgVar416 = STG_OFFSET(stgVar416, sizeof(number_t));
		}
			macroDef450->arr[r_dps] = macroDef449;;
			stgVar415 = STG_OFFSET(stgVar415, VECTOR_ALL_BYTES(macroDef450->arr[r_dps]->length));
		}
	macroDef451 = macroDef450;;
	storage_free(stgVar413, size456);
	return macroDef451;
}

card_t TOP_LEVEL_linalg_matrixVectorMult_shp(matrix_shape_t m_shp, card_t v_shp) {
	
	return TOP_LEVEL_linalg_rows_shp(m_shp);
}


array_number_t TOP_LEVEL_linalg_matrixVectorMult_dps(storage_t stgVar457, array_array_number_t m_dps, array_number_t v_dps, matrix_shape_t m_shp, card_t v_shp) {
	card_t r_shp = TOP_LEVEL_linalg_rows_shp(m_shp);
	card_t size474 = width_card_t(r_shp);
	array_number_t stgVar458 = storage_alloc(size474);
	array_number_t macroDef471;card_t r_dps = TOP_LEVEL_linalg_rows_dps(stgVar458, m_dps, m_shp);
	card_t c_shp = TOP_LEVEL_linalg_cols_shp(m_shp);
	card_t size473 = width_card_t(c_shp);
	array_number_t stgVar460 = storage_alloc(size473);
	array_number_t macroDef470;card_t c_dps = TOP_LEVEL_linalg_cols_dps(stgVar460, m_dps, m_shp);
	array_number_t macroDef469 = (array_number_t)stgVar457;
		macroDef469->length=r_dps;
		macroDef469->arr=(number_t*)(STG_OFFSET(macroDef469, VECTOR_HEADER_BYTES));
		storage_t stgVar462 = macroDef469;
		for(int i_dps = 0; i_dps < macroDef469->length; i_dps++){
			card_t size472 = width_card_t(m_shp.elem);
	array_number_t stgVar463 = storage_alloc(size472);
	number_t macroDef468;
	macroDef468 = TOP_LEVEL_linalg_dot_prod_dps(stgVar462, m_dps->arr[i_dps], v_dps, m_shp.elem, v_shp);;
	storage_free(stgVar463, size472);
			macroDef469->arr[i_dps] = macroDef468;;
			stgVar462 = STG_OFFSET(stgVar462, sizeof(number_t));
		}
	macroDef470 = macroDef469;;
	storage_free(stgVar460, size473);
	macroDef471 = macroDef470;;
	storage_free(stgVar458, size474);
	return macroDef471;
}

matrix_shape_t TOP_LEVEL_linalg_matrixConcat_shp(matrix_shape_t m1_shp, matrix_shape_t m2_shp) {
	
	return nested_shape_card_t(m1_shp.elem, (m1_shp.card) + (m2_shp.card));
}


array_array_number_t TOP_LEVEL_linalg_matrixConcat_dps(storage_t stgVar475, array_array_number_t m1_dps, array_array_number_t m2_dps, matrix_shape_t m1_shp, matrix_shape_t m2_shp) {
	card_t rows_shp = (m1_shp.card) + (m2_shp.card);
	card_t macroDef486 = m1_dps->length;
	card_t macroDef487 = m2_dps->length;
	card_t rows_dps = (macroDef486) + (macroDef487);
	card_t m1Rows_shp = 0;
	card_t macroDef488 = m1_dps->length;
	index_t m1Rows_dps = (macroDef488);
	array_array_number_t macroDef489 = (array_array_number_t)stgVar475;
		macroDef489->length=rows_dps;
		macroDef489->arr=(array_number_t*)(STG_OFFSET(macroDef489, VECTOR_HEADER_BYTES));
		storage_t stgVar481 = (STG_OFFSET(macroDef489, MATRIX_HEADER_BYTES(rows_dps)));
		for(int r_dps = 0; r_dps < macroDef489->length; r_dps++){
			array_number_t ite490 = 0;
	if((r_dps) < (m1Rows_dps)) {
		
		ite490 = m1_dps->arr[r_dps];;
	} else {
		
		ite490 = m2_dps->arr[(r_dps) - (m1Rows_dps)];;
	}
			macroDef489->arr[r_dps] = ite490;;
			stgVar481 = STG_OFFSET(stgVar481, VECTOR_ALL_BYTES(macroDef489->arr[r_dps]->length));
		}
	return macroDef489;
}

matrix_shape_t TOP_LEVEL_linalg_matrixConcatCol_shp(matrix_shape_t m1_shp, matrix_shape_t m2_shp) {
	
	return TOP_LEVEL_linalg_matrixTranspose_shp(TOP_LEVEL_linalg_matrixConcat_shp(TOP_LEVEL_linalg_matrixTranspose_shp(m1_shp), TOP_LEVEL_linalg_matrixTranspose_shp(m2_shp)));
}


array_array_number_t TOP_LEVEL_linalg_matrixConcatCol_dps(storage_t stgVar491, array_array_number_t m1_dps, array_array_number_t m2_dps, matrix_shape_t m1_shp, matrix_shape_t m2_shp) {
	matrix_shape_t m1t_shp = TOP_LEVEL_linalg_matrixTranspose_shp(m1_shp);
	card_t size506 = width_matrix_shape_t(m1t_shp);
	array_number_t stgVar492 = storage_alloc(size506);
	array_array_number_t macroDef503;array_array_number_t m1t_dps = TOP_LEVEL_linalg_matrixTranspose_dps(stgVar492, m1_dps, m1_shp);
	matrix_shape_t m2t_shp = TOP_LEVEL_linalg_matrixTranspose_shp(m2_shp);
	card_t size505 = width_matrix_shape_t(m2t_shp);
	array_number_t stgVar494 = storage_alloc(size505);
	array_array_number_t macroDef502;array_array_number_t m2t_dps = TOP_LEVEL_linalg_matrixTranspose_dps(stgVar494, m2_dps, m2_shp);
	card_t size504 = width_matrix_shape_t(TOP_LEVEL_linalg_matrixConcat_shp(m1t_shp, m2t_shp));
	array_number_t stgVar496 = storage_alloc(size504);
	array_array_number_t macroDef501;
	macroDef501 = TOP_LEVEL_linalg_matrixTranspose_dps(stgVar491, TOP_LEVEL_linalg_matrixConcat_dps(stgVar496, m1t_dps, m2t_dps, m1t_shp, m2t_shp), TOP_LEVEL_linalg_matrixConcat_shp(m1t_shp, m2t_shp));;
	storage_free(stgVar496, size504);
	macroDef502 = macroDef501;;
	storage_free(stgVar494, size505);
	macroDef503 = macroDef502;;
	storage_free(stgVar492, size506);
	return macroDef503;
}

matrix3d_shape_t TOP_LEVEL_linalg_matrix3DConcat_shp(matrix3d_shape_t m1_shp, matrix3d_shape_t m2_shp) {
	
	return nested_shape_matrix_shape_t(m1_shp.elem, (m1_shp.card) + (m2_shp.card));
}


array_array_array_number_t TOP_LEVEL_linalg_matrix3DConcat_dps(storage_t stgVar507, array_array_array_number_t m1_dps, array_array_array_number_t m2_dps, matrix3d_shape_t m1_shp, matrix3d_shape_t m2_shp) {
	card_t rows_shp = (m1_shp.card) + (m2_shp.card);
	card_t macroDef518 = m1_dps->length;
	card_t macroDef519 = m2_dps->length;
	card_t rows_dps = (macroDef518) + (macroDef519);
	card_t m1Rows_shp = 0;
	card_t macroDef520 = m1_dps->length;
	index_t m1Rows_dps = (macroDef520);
	array_array_array_number_t macroDef521 = (array_array_array_number_t)stgVar507;
		macroDef521->length=rows_dps;
		macroDef521->arr=(array_array_number_t*)(STG_OFFSET(macroDef521, VECTOR_HEADER_BYTES));
		storage_t stgVar513 = (STG_OFFSET(macroDef521, MATRIX_HEADER_BYTES(rows_dps)));
		for(int r_dps = 0; r_dps < macroDef521->length; r_dps++){
			array_array_number_t ite522 = 0;
	if((r_dps) < (m1Rows_dps)) {
		
		ite522 = m1_dps->arr[r_dps];;
	} else {
		
		ite522 = m2_dps->arr[(r_dps) - (m1Rows_dps)];;
	}
			macroDef521->arr[r_dps] = ite522;;
			stgVar513 = STG_OFFSET(stgVar513, VECTOR_ALL_BYTES(macroDef521->arr[r_dps]->length));
		}
	return macroDef521;
}

card_t TOP_LEVEL_linalg_vectorRead_shp(card_t fn_shp, card_t startLine_shp, card_t cols_shp) {
	
	return nested_shape_card_t(cols_shp, 1).elem;
}


array_number_t TOP_LEVEL_linalg_vectorRead_dps(storage_t stgVar523, string_t fn_dps, index_t startLine_dps, card_t cols_dps, card_t fn_shp, card_t startLine_shp, card_t cols_shp) {
	matrix_shape_t matrix_shp = nested_shape_card_t(cols_shp, 1);
	card_t size527 = width_matrix_shape_t(matrix_shp);
	array_number_t stgVar524 = storage_alloc(size527);
	array_number_t macroDef526;array_array_number_t matrix_dps = matrix_read_s(stgVar524, fn_dps, startLine_dps, 1, cols_dps);
	macroDef526 = matrix_dps->arr[0];;
	storage_free(stgVar524, size527);
	return macroDef526;
}

card_t TOP_LEVEL_linalg_numberRead_shp(card_t fn_shp, card_t startLine_shp) {
	
	return 0;
}


number_t TOP_LEVEL_linalg_numberRead_dps(storage_t stgVar528, string_t fn_dps, index_t startLine_dps, card_t fn_shp, card_t startLine_shp) {
	card_t vector_shp = TOP_LEVEL_linalg_vectorRead_shp(0, 0, 1);
	card_t size535 = width_card_t(vector_shp);
	array_number_t stgVar529 = storage_alloc(size535);
	number_t macroDef534;array_number_t vector_dps = TOP_LEVEL_linalg_vectorRead_dps(stgVar529, fn_dps, startLine_dps, 1, 0, 0, 1);
	macroDef534 = vector_dps->arr[0];;
	storage_free(stgVar529, size535);
	return macroDef534;
}

card_t TOP_LEVEL_linalg_vec3_shp(card_t a_shp, card_t b_shp, card_t c_shp) {
	
	return 3;
}


array_number_t TOP_LEVEL_linalg_vec3_dps(storage_t stgVar536, number_t a_dps, number_t b_dps, number_t c_dps, card_t a_shp, card_t b_shp, card_t c_shp) {
	array_number_t macroDef540 = (array_number_t)stgVar536;
	macroDef540->length=3;
	macroDef540->arr=(number_t*)(STG_OFFSET(stgVar536, VECTOR_HEADER_BYTES));
	macroDef540->arr[0] = a_dps;
	macroDef540->arr[1] = b_dps;
	macroDef540->arr[2] = c_dps;;
	return macroDef540;
}
#endif
