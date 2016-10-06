#ifndef __LINALG_STORAGED_H__ 
#define __LINALG_STORAGED_H__ 
#include "runtime/fsharp.h"
#include <stdio.h>
#include <math.h>

card_t TOP_LEVEL_linalg_rows_shp(matrix_shape_t m_shp) {
	
	return m->length;
}


card_t TOP_LEVEL_linalg_rows_dps(storage_t stgVar1, array_array_number_t m_dps, matrix_shape_t m_shp) {
	
	return m->length;
}

card_t TOP_LEVEL_linalg_cols_shp(matrix_shape_t m_shp) {
	
	return m->arr[0]->length;
}


card_t TOP_LEVEL_linalg_cols_dps(storage_t stgVar2, array_array_number_t m_dps, matrix_shape_t m_shp) {
	
	return m->arr[0]->length;
}

card_t TOP_LEVEL_linalg_vectorMap_shp(closure_t f_shp, card_t v_shp) {
	
	return v_shp;
}


array_number_t TOP_LEVEL_linalg_vectorMap_dps(storage_t stgVar3, closure_t f_dps, array_number_t v_dps, closure_t f_shp, card_t v_shp) {
	card_t macroDef8 = v_dps->length;
	array_number_t macroDef9 = (array_number_t)stgVar3;
		macroDef9->length=macroDef8;
		macroDef9->arr=(number_t*)(STG_OFFSET(macroDef9, VECTOR_HEADER_BYTES));
		storage_t stgVar5 = macroDef9;
		for(int i_dps = 0; i_dps < macroDef9->length; i_dps++){
			
			macroDef9->arr[i_dps] = f_dps.lam(f_dps.env, stgVar5, v_dps->arr[i_dps], 0).number_t_value;;
			stgVar5 = STG_OFFSET(stgVar5, sizeof(number_t));
		}
	return macroDef9;
}

card_t TOP_LEVEL_linalg_vectorRange_shp(card_t s_shp, card_t e_shp) {
	
	return ((e_shp) - (s_shp)) + (1);
}


array_number_t TOP_LEVEL_linalg_vectorRange_dps(storage_t stgVar10, card_t s_dps, card_t e_dps, card_t s_shp, card_t e_shp) {
	array_number_t macroDef12 = (array_number_t)stgVar10;
		macroDef12->length=((e_dps) - (s_dps)) + (1);
		macroDef12->arr=(number_t*)(STG_OFFSET(macroDef12, VECTOR_HEADER_BYTES));
		storage_t stgVar11 = macroDef12;
		for(int i_dps = 0; i_dps < macroDef12->length; i_dps++){
			
			macroDef12->arr[i_dps] = (double)(((s_dps)) + (i_dps));;
			stgVar11 = STG_OFFSET(stgVar11, sizeof(number_t));
		}
	return macroDef12;
}

card_t TOP_LEVEL_linalg_vectorSlice_shp(card_t size_shp, card_t offset_shp, card_t v_shp) {
	
	return size_shp;
}


array_number_t TOP_LEVEL_linalg_vectorSlice_dps(storage_t stgVar13, card_t size_dps, index_t offset_dps, array_number_t v_dps, card_t size_shp, card_t offset_shp, card_t v_shp) {
	array_number_t macroDef16 = (array_number_t)stgVar13;
		macroDef16->length=size_dps;
		macroDef16->arr=(number_t*)(STG_OFFSET(macroDef16, VECTOR_HEADER_BYTES));
		storage_t stgVar14 = macroDef16;
		for(int i_dps = 0; i_dps < macroDef16->length; i_dps++){
			
			macroDef16->arr[i_dps] = v_dps->arr[(i_dps) + (offset_dps)];;
			stgVar14 = STG_OFFSET(stgVar14, sizeof(number_t));
		}
	return macroDef16;
}

matrix_shape_t TOP_LEVEL_linalg_matrixMap_shp(closure_t f_shp, matrix_shape_t m_shp) {
	
	return nested_shape_card_t(f_shp.lam(f_shp.env, m_shp.elem).card_t_value, m_shp.card);
}


array_array_number_t TOP_LEVEL_linalg_matrixMap_dps(storage_t stgVar17, closure_t f_dps, array_array_number_t m_dps, closure_t f_shp, matrix_shape_t m_shp) {
	card_t macroDef22 = m_dps->length;
	array_array_number_t macroDef24 = (array_array_number_t)stgVar17;
		macroDef24->length=macroDef22;
		macroDef24->arr=(array_number_t*)(STG_OFFSET(macroDef24, VECTOR_HEADER_BYTES));
		storage_t stgVar19 = (STG_OFFSET(macroDef24, MATRIX_HEADER_BYTES(macroDef22)));
		for(int i_dps = 0; i_dps < macroDef24->length; i_dps++){
			card_t size25 = width_card_t(m_shp.elem);
	array_number_t stgVar20 = storage_alloc(size25);
	array_number_t macroDef23;
	macroDef23 = f_dps.lam(f_dps.env, stgVar19, m_dps->arr[i_dps], m_shp.elem).array_number_t_value;;
	storage_free(stgVar20, size25);
			macroDef24->arr[i_dps] = macroDef23;;
			stgVar19 = STG_OFFSET(stgVar19, VECTOR_ALL_BYTES(macroDef24->arr[i_dps]->length));
		}
	return macroDef24;
}

card_t TOP_LEVEL_linalg_matrixMapToVector_shp(closure_t f_shp, matrix_shape_t m_shp) {
	
	return m_shp.card;
}


array_number_t TOP_LEVEL_linalg_matrixMapToVector_dps(storage_t stgVar26, closure_t f_dps, array_array_number_t m_dps, closure_t f_shp, matrix_shape_t m_shp) {
	card_t macroDef31 = m_dps->length;
	array_number_t macroDef33 = (array_number_t)stgVar26;
		macroDef33->length=macroDef31;
		macroDef33->arr=(number_t*)(STG_OFFSET(macroDef33, VECTOR_HEADER_BYTES));
		storage_t stgVar28 = macroDef33;
		for(int i_dps = 0; i_dps < macroDef33->length; i_dps++){
			card_t size34 = width_card_t(m_shp.elem);
	array_number_t stgVar29 = storage_alloc(size34);
	number_t macroDef32;
	macroDef32 = f_dps.lam(f_dps.env, stgVar28, m_dps->arr[i_dps], m_shp.elem).number_t_value;;
	storage_free(stgVar29, size34);
			macroDef33->arr[i_dps] = macroDef32;;
			stgVar28 = STG_OFFSET(stgVar28, sizeof(number_t));
		}
	return macroDef33;
}

card_t TOP_LEVEL_linalg_vectorMap2_shp(closure_t f_shp, card_t v1_shp, card_t v2_shp) {
	
	return v1_shp;
}


array_number_t TOP_LEVEL_linalg_vectorMap2_dps(storage_t stgVar35, closure_t f_dps, array_number_t v1_dps, array_number_t v2_dps, closure_t f_shp, card_t v1_shp, card_t v2_shp) {
	card_t macroDef42 = v1_dps->length;
	array_number_t macroDef43 = (array_number_t)stgVar35;
		macroDef43->length=macroDef42;
		macroDef43->arr=(number_t*)(STG_OFFSET(macroDef43, VECTOR_HEADER_BYTES));
		storage_t stgVar37 = macroDef43;
		for(int i_dps = 0; i_dps < macroDef43->length; i_dps++){
			
			macroDef43->arr[i_dps] = f_dps.lam(f_dps.env, stgVar37, v1_dps->arr[i_dps], v2_dps->arr[i_dps], 0, 0).number_t_value;;
			stgVar37 = STG_OFFSET(stgVar37, sizeof(number_t));
		}
	return macroDef43;
}

matrix_shape_t TOP_LEVEL_linalg_matrixMap2_shp(closure_t f_shp, matrix_shape_t m1_shp, matrix_shape_t m2_shp) {
	
	return nested_shape_card_t(f_shp.lam(f_shp.env, m1_shp.elem, m2_shp.elem).card_t_value, m1_shp.card);
}


array_array_number_t TOP_LEVEL_linalg_matrixMap2_dps(storage_t stgVar44, closure_t f_dps, array_array_number_t m1_dps, array_array_number_t m2_dps, closure_t f_shp, matrix_shape_t m1_shp, matrix_shape_t m2_shp) {
	card_t macroDef51 = m1_dps->length;
	array_array_number_t macroDef54 = (array_array_number_t)stgVar44;
		macroDef54->length=macroDef51;
		macroDef54->arr=(array_number_t*)(STG_OFFSET(macroDef54, VECTOR_HEADER_BYTES));
		storage_t stgVar46 = (STG_OFFSET(macroDef54, MATRIX_HEADER_BYTES(macroDef51)));
		for(int i_dps = 0; i_dps < macroDef54->length; i_dps++){
			card_t size56 = width_card_t(m2_shp.elem);
	array_number_t stgVar48 = storage_alloc(size56);
	array_number_t macroDef53;card_t size55 = width_card_t(m1_shp.elem);
	array_number_t stgVar47 = storage_alloc(size55);
	array_number_t macroDef52;
	macroDef52 = f_dps.lam(f_dps.env, stgVar46, m1_dps->arr[i_dps], m2_dps->arr[i_dps], m1_shp.elem, m2_shp.elem).array_number_t_value;;
	storage_free(stgVar47, size55);
	macroDef53 = macroDef52;;
	storage_free(stgVar48, size56);
			macroDef54->arr[i_dps] = macroDef53;;
			stgVar46 = STG_OFFSET(stgVar46, VECTOR_ALL_BYTES(macroDef54->arr[i_dps]->length));
		}
	return macroDef54;
}

matrix3d_shape_t TOP_LEVEL_linalg_matrix3DMap2_shp(closure_t f_shp, matrix3d_shape_t m1_shp, matrix3d_shape_t m2_shp) {
	
	return nested_shape_matrix_shape_t(f_shp.lam(f_shp.env, m1_shp.elem, m2_shp.elem).matrix_shape_t_value, m1_shp.card);
}


array_array_array_number_t TOP_LEVEL_linalg_matrix3DMap2_dps(storage_t stgVar57, closure_t f_dps, array_array_array_number_t m1_dps, array_array_array_number_t m2_dps, closure_t f_shp, matrix3d_shape_t m1_shp, matrix3d_shape_t m2_shp) {
	card_t macroDef64 = m1_dps->length;
	array_array_array_number_t macroDef67 = (array_array_array_number_t)stgVar57;
		macroDef67->length=macroDef64;
		macroDef67->arr=(array_array_number_t*)(STG_OFFSET(macroDef67, VECTOR_HEADER_BYTES));
		storage_t stgVar59 = (STG_OFFSET(macroDef67, MATRIX_HEADER_BYTES(macroDef64)));
		for(int i_dps = 0; i_dps < macroDef67->length; i_dps++){
			card_t size69 = width_matrix_shape_t(m2_shp.elem);
	array_number_t stgVar61 = storage_alloc(size69);
	array_array_number_t macroDef66;card_t size68 = width_matrix_shape_t(m1_shp.elem);
	array_number_t stgVar60 = storage_alloc(size68);
	array_array_number_t macroDef65;
	macroDef65 = f_dps.lam(f_dps.env, stgVar59, m1_dps->arr[i_dps], m2_dps->arr[i_dps], m1_shp.elem, m2_shp.elem).array_array_number_t_value;;
	storage_free(stgVar60, size68);
	macroDef66 = macroDef65;;
	storage_free(stgVar61, size69);
			macroDef67->arr[i_dps] = macroDef66;;
			stgVar59 = STG_OFFSET(stgVar59, VECTOR_ALL_BYTES(macroDef67->arr[i_dps]->length));
		}
	return macroDef67;
}

matrix_shape_t TOP_LEVEL_linalg_vectorMapToMatrix_shp(closure_t f_shp, card_t arr_shp) {
	
	return nested_shape_card_t(f_shp.lam(f_shp.env, 0).card_t_value, arr_shp);
}


array_array_number_t TOP_LEVEL_linalg_vectorMapToMatrix_dps(storage_t stgVar70, closure_t f_dps, array_number_t arr_dps, closure_t f_shp, card_t arr_shp) {
	card_t macroDef75 = arr_dps->length;
	array_array_number_t macroDef76 = (array_array_number_t)stgVar70;
		macroDef76->length=macroDef75;
		macroDef76->arr=(array_number_t*)(STG_OFFSET(macroDef76, VECTOR_HEADER_BYTES));
		storage_t stgVar72 = (STG_OFFSET(macroDef76, MATRIX_HEADER_BYTES(macroDef75)));
		for(int i_dps = 0; i_dps < macroDef76->length; i_dps++){
			
			macroDef76->arr[i_dps] = f_dps.lam(f_dps.env, stgVar72, arr_dps->arr[i_dps], 0).array_number_t_value;;
			stgVar72 = STG_OFFSET(stgVar72, VECTOR_ALL_BYTES(macroDef76->arr[i_dps]->length));
		}
	return macroDef76;
}

matrix3d_shape_t TOP_LEVEL_linalg_vectorMapToMatrix3D_shp(closure_t f_shp, card_t arr_shp) {
	
	return nested_shape_matrix_shape_t(f_shp.lam(f_shp.env, 0).matrix_shape_t_value, arr_shp);
}


array_array_array_number_t TOP_LEVEL_linalg_vectorMapToMatrix3D_dps(storage_t stgVar77, closure_t f_dps, array_number_t arr_dps, closure_t f_shp, card_t arr_shp) {
	card_t macroDef82 = arr_dps->length;
	array_array_array_number_t macroDef83 = (array_array_array_number_t)stgVar77;
		macroDef83->length=macroDef82;
		macroDef83->arr=(array_array_number_t*)(STG_OFFSET(macroDef83, VECTOR_HEADER_BYTES));
		storage_t stgVar79 = (STG_OFFSET(macroDef83, MATRIX_HEADER_BYTES(macroDef82)));
		for(int i_dps = 0; i_dps < macroDef83->length; i_dps++){
			
			macroDef83->arr[i_dps] = f_dps.lam(f_dps.env, stgVar79, arr_dps->arr[i_dps], 0).array_array_number_t_value;;
			stgVar79 = STG_OFFSET(stgVar79, VECTOR_ALL_BYTES(macroDef83->arr[i_dps]->length));
		}
	return macroDef83;
}

card_t TOP_LEVEL_linalg_iterateNumber_shp(closure_t f_shp, card_t z_shp, card_t s_shp, card_t e_shp) {
	
	return 0;
}


number_t TOP_LEVEL_linalg_iterateNumber_dps(storage_t stgVar84, closure_t f_dps, number_t z_dps, card_t s_dps, card_t e_dps, closure_t f_shp, card_t z_shp, card_t s_shp, card_t e_shp) {
	number_t macroDef90 = z_dps;
	array_number_t cur_dps_range = TOP_LEVEL_linalg_vectorRange_dps(empty_storage, s_dps, e_dps, s_shp, e_shp);
	storage_t stgVar85 = stgVar84;
	for(int cur_dps_idx = 0; cur_dps_idx < cur_dps_range->length; cur_dps_idx++){
		number_t cur_dps = cur_dps_range->arr[cur_dps_idx];
		
		macroDef90 = f_dps.lam(f_dps.env, stgVar85, macroDef90, (int)(cur_dps), 0, 0).number_t_value;;
	}
	return macroDef90;
}

card_t TOP_LEVEL_linalg_iterateVector_shp(closure_t f_shp, card_t z_shp, card_t s_shp, card_t e_shp) {
	
	return z_shp;
}


array_number_t TOP_LEVEL_linalg_iterateVector_dps(storage_t stgVar91, closure_t f_dps, array_number_t z_dps, card_t s_dps, card_t e_dps, closure_t f_shp, card_t z_shp, card_t s_shp, card_t e_shp) {
	array_number_t macroDef97 = z_dps;
	array_number_t cur_dps_range = TOP_LEVEL_linalg_vectorRange_dps(empty_storage, s_dps, e_dps, s_shp, e_shp);
	storage_t stgVar92 = stgVar91;
	for(int cur_dps_idx = 0; cur_dps_idx < cur_dps_range->length; cur_dps_idx++){
		number_t cur_dps = cur_dps_range->arr[cur_dps_idx];
		
		macroDef97 = f_dps.lam(f_dps.env, stgVar92, macroDef97, (int)(cur_dps), z_shp, 0).array_number_t_value;;
	}
	return macroDef97;
}

matrix_shape_t TOP_LEVEL_linalg_iterateMatrix_shp(closure_t f_shp, matrix_shape_t z_shp, card_t s_shp, card_t e_shp) {
	
	return z_shp;
}


array_array_number_t TOP_LEVEL_linalg_iterateMatrix_dps(storage_t stgVar98, closure_t f_dps, array_array_number_t z_dps, card_t s_dps, card_t e_dps, closure_t f_shp, matrix_shape_t z_shp, card_t s_shp, card_t e_shp) {
	array_array_number_t macroDef104 = z_dps;
	array_number_t cur_dps_range = TOP_LEVEL_linalg_vectorRange_dps(empty_storage, s_dps, e_dps, s_shp, e_shp);
	storage_t stgVar99 = stgVar98;
	for(int cur_dps_idx = 0; cur_dps_idx < cur_dps_range->length; cur_dps_idx++){
		number_t cur_dps = cur_dps_range->arr[cur_dps_idx];
		
		macroDef104 = f_dps.lam(f_dps.env, stgVar99, macroDef104, (int)(cur_dps), z_shp, 0).array_array_number_t_value;;
	}
	return macroDef104;
}

matrix3d_shape_t TOP_LEVEL_linalg_iterateMatrix3D_shp(closure_t f_shp, matrix3d_shape_t z_shp, card_t s_shp, card_t e_shp) {
	
	return z_shp;
}


array_array_array_number_t TOP_LEVEL_linalg_iterateMatrix3D_dps(storage_t stgVar105, closure_t f_dps, array_array_array_number_t z_dps, card_t s_dps, card_t e_dps, closure_t f_shp, matrix3d_shape_t z_shp, card_t s_shp, card_t e_shp) {
	array_array_array_number_t macroDef111 = z_dps;
	array_number_t cur_dps_range = TOP_LEVEL_linalg_vectorRange_dps(empty_storage, s_dps, e_dps, s_shp, e_shp);
	storage_t stgVar106 = stgVar105;
	for(int cur_dps_idx = 0; cur_dps_idx < cur_dps_range->length; cur_dps_idx++){
		number_t cur_dps = cur_dps_range->arr[cur_dps_idx];
		
		macroDef111 = f_dps.lam(f_dps.env, stgVar106, macroDef111, (int)(cur_dps), z_shp, 0).array_array_array_number_t_value;;
	}
	return macroDef111;
}

card_t TOP_LEVEL_linalg_vectorSum_shp(card_t v_shp) {
	
	return 0;
}


number_t TOP_LEVEL_linalg_vectorSum_dps(storage_t stgVar112, array_number_t v_dps, card_t v_shp) {
	number_t macroDef114 = 0;
	array_number_t cur_dps_range = v_dps;
	storage_t stgVar113 = stgVar112;
	for(int cur_dps_idx = 0; cur_dps_idx < cur_dps_range->length; cur_dps_idx++){
		number_t cur_dps = cur_dps_range->arr[cur_dps_idx];
		
		macroDef114 = (macroDef114) + (cur_dps);;
	}
	return macroDef114;
}

card_t TOP_LEVEL_linalg_vectorMax_shp(card_t v_shp) {
	
	return 0;
}


number_t TOP_LEVEL_linalg_vectorMax_dps(storage_t stgVar115, array_number_t v_dps, card_t v_shp) {
	number_t macroDef117 = -1000;
	array_number_t cur_dps_range = v_dps;
	storage_t stgVar116 = stgVar115;
	for(int cur_dps_idx = 0; cur_dps_idx < cur_dps_range->length; cur_dps_idx++){
		number_t cur_dps = cur_dps_range->arr[cur_dps_idx];
		number_t ite118 = 0;
	if((macroDef117) > (cur_dps)) {
		
		ite118 = macroDef117;;
	} else {
		
		ite118 = cur_dps;;
	}
		macroDef117 = ite118;;
	}
	return macroDef117;
}
typedef empty_env_t env_t_126;


value_t lambda126(env_t_126* env123, card_t xi_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
card_t TOP_LEVEL_linalg_mult_by_scalar_shp(card_t x_shp, card_t y_shp) {
	env_t_126 env_t_126_value = make_empty_env(); closure_t closure125 = make_closure(lambda126, &env_t_126_value);
	return TOP_LEVEL_linalg_vectorMap_shp(closure125, x_shp);
}

typedef struct env_t_134 {
	number_t y_dps;
} env_t_134;
env_t_134 make_env_t_134(number_t y_dps) {
	env_t_134 env;
	env.y_dps = y_dps;
	return env;
}

value_t lambda134(env_t_134* env128, storage_t stgVar122, number_t xi_dps, card_t xi_shp) {
	number_t y_dps127 = env128->y_dps;
	value_t res;
	res.number_t_value = (xi_dps) * (y_dps127);
	return res;
}
typedef empty_env_t env_t_135;


value_t lambda135(env_t_135* env131, card_t xi_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
array_number_t TOP_LEVEL_linalg_mult_by_scalar_dps(storage_t stgVar119, array_number_t x_dps, number_t y_dps, card_t x_shp, card_t y_shp) {
	env_t_134 env_t_134_value = make_env_t_134(y_dps); closure_t closure130 = make_closure(lambda134, &env_t_134_value);
	env_t_135 env_t_135_value = make_empty_env(); closure_t closure133 = make_closure(lambda135, &env_t_135_value);
	return TOP_LEVEL_linalg_vectorMap_dps(stgVar119, closure130, x_dps, closure133, x_shp);
}
typedef empty_env_t env_t_143;


value_t lambda143(env_t_143* env140, card_t xi_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
card_t TOP_LEVEL_linalg_gaxpy_shp(card_t a_shp, card_t x_shp, card_t y_shp) {
	env_t_143 env_t_143_value = make_empty_env(); closure_t closure142 = make_closure(lambda143, &env_t_143_value);
	return TOP_LEVEL_linalg_vectorMap_shp(closure142, x_shp);
}

typedef struct env_t_152 {
	number_t y_dps;
	number_t a_dps;
} env_t_152;
env_t_152 make_env_t_152(number_t y_dps,number_t a_dps) {
	env_t_152 env;
	env.y_dps = y_dps;
	env.a_dps = a_dps;
	return env;
}

value_t lambda152(env_t_152* env146, storage_t stgVar139, number_t xi_dps, card_t xi_shp) {
	number_t y_dps145 = env146->y_dps;
	number_t a_dps144 = env146->a_dps;
	value_t res;
	res.number_t_value = ((a_dps144) * (xi_dps)) + (y_dps145);
	return res;
}
typedef empty_env_t env_t_153;


value_t lambda153(env_t_153* env149, card_t xi_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
array_number_t TOP_LEVEL_linalg_gaxpy_dps(storage_t stgVar136, number_t a_dps, array_number_t x_dps, number_t y_dps, card_t a_shp, card_t x_shp, card_t y_shp) {
	env_t_152 env_t_152_value = make_env_t_152(y_dps,a_dps); closure_t closure148 = make_closure(lambda152, &env_t_152_value);
	env_t_153 env_t_153_value = make_empty_env(); closure_t closure151 = make_closure(lambda153, &env_t_153_value);
	return TOP_LEVEL_linalg_vectorMap_dps(stgVar136, closure148, x_dps, closure151, x_shp);
}

card_t TOP_LEVEL_linalg_cross_shp(card_t a_shp, card_t b_shp) {
	
	return 3;
}


array_number_t TOP_LEVEL_linalg_cross_dps(storage_t stgVar154, array_number_t a_dps, array_number_t b_dps, card_t a_shp, card_t b_shp) {
	array_number_t macroDef170 = (array_number_t)stgVar154;
	macroDef170->length=3;
	macroDef170->arr=(number_t*)(STG_OFFSET(stgVar154, VECTOR_HEADER_BYTES));
	macroDef170->arr[0] = ((a_dps->arr[1]) * (b_dps->arr[2])) - ((a_dps->arr[2]) * (b_dps->arr[1]));
	macroDef170->arr[1] = ((a_dps->arr[2]) * (b_dps->arr[0])) - ((a_dps->arr[0]) * (b_dps->arr[2]));
	macroDef170->arr[2] = ((a_dps->arr[0]) * (b_dps->arr[1])) - ((a_dps->arr[1]) * (b_dps->arr[0]));;
	return macroDef170;
}
typedef empty_env_t env_t_179;


value_t lambda179(env_t_179* env176, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
card_t TOP_LEVEL_linalg_vectorAdd_shp(card_t x_shp, card_t y_shp) {
	env_t_179 env_t_179_value = make_empty_env(); closure_t closure178 = make_closure(lambda179, &env_t_179_value);
	return TOP_LEVEL_linalg_vectorMap2_shp(closure178, x_shp, y_shp);
}

typedef empty_env_t env_t_186;


value_t lambda186(env_t_186* env180, storage_t stgVar175, number_t x_dps0, number_t y_dps0, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.number_t_value = (x_dps0) + (y_dps0);
	return res;
}
typedef empty_env_t env_t_187;


value_t lambda187(env_t_187* env183, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
array_number_t TOP_LEVEL_linalg_vectorAdd_dps(storage_t stgVar171, array_number_t x_dps, array_number_t y_dps, card_t x_shp, card_t y_shp) {
	env_t_186 env_t_186_value = make_empty_env(); closure_t closure182 = make_closure(lambda186, &env_t_186_value);
	env_t_187 env_t_187_value = make_empty_env(); closure_t closure185 = make_closure(lambda187, &env_t_187_value);
	return TOP_LEVEL_linalg_vectorMap2_dps(stgVar171, closure182, x_dps, y_dps, closure185, x_shp, y_shp);
}
typedef empty_env_t env_t_196;


value_t lambda196(env_t_196* env193, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
card_t TOP_LEVEL_linalg_mult_vec_elementwise_shp(card_t x_shp, card_t y_shp) {
	env_t_196 env_t_196_value = make_empty_env(); closure_t closure195 = make_closure(lambda196, &env_t_196_value);
	return TOP_LEVEL_linalg_vectorMap2_shp(closure195, x_shp, y_shp);
}

typedef empty_env_t env_t_203;


value_t lambda203(env_t_203* env197, storage_t stgVar192, number_t x_dps0, number_t y_dps0, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.number_t_value = (x_dps0) * (y_dps0);
	return res;
}
typedef empty_env_t env_t_204;


value_t lambda204(env_t_204* env200, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
array_number_t TOP_LEVEL_linalg_mult_vec_elementwise_dps(storage_t stgVar188, array_number_t x_dps, array_number_t y_dps, card_t x_shp, card_t y_shp) {
	env_t_203 env_t_203_value = make_empty_env(); closure_t closure199 = make_closure(lambda203, &env_t_203_value);
	env_t_204 env_t_204_value = make_empty_env(); closure_t closure202 = make_closure(lambda204, &env_t_204_value);
	return TOP_LEVEL_linalg_vectorMap2_dps(stgVar188, closure199, x_dps, y_dps, closure202, x_shp, y_shp);
}
typedef empty_env_t env_t_213;


value_t lambda213(env_t_213* env210, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
card_t TOP_LEVEL_linalg_op_DotMultiply_shp(card_t x_shp, card_t y_shp) {
	env_t_213 env_t_213_value = make_empty_env(); closure_t closure212 = make_closure(lambda213, &env_t_213_value);
	return TOP_LEVEL_linalg_vectorMap2_shp(closure212, x_shp, y_shp);
}

typedef empty_env_t env_t_220;


value_t lambda220(env_t_220* env214, storage_t stgVar209, number_t x_dps0, number_t y_dps0, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.number_t_value = (x_dps0) * (y_dps0);
	return res;
}
typedef empty_env_t env_t_221;


value_t lambda221(env_t_221* env217, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
array_number_t TOP_LEVEL_linalg_op_DotMultiply_dps(storage_t stgVar205, array_number_t x_dps, array_number_t y_dps, card_t x_shp, card_t y_shp) {
	env_t_220 env_t_220_value = make_empty_env(); closure_t closure216 = make_closure(lambda220, &env_t_220_value);
	env_t_221 env_t_221_value = make_empty_env(); closure_t closure219 = make_closure(lambda221, &env_t_221_value);
	return TOP_LEVEL_linalg_vectorMap2_dps(stgVar205, closure216, x_dps, y_dps, closure219, x_shp, y_shp);
}

card_t TOP_LEVEL_linalg_vectorAdd3_shp(card_t x_shp, card_t y_shp, card_t z_shp) {
	
	return TOP_LEVEL_linalg_vectorAdd_shp(TOP_LEVEL_linalg_vectorAdd_shp(x_shp, y_shp), z_shp);
}


array_number_t TOP_LEVEL_linalg_vectorAdd3_dps(storage_t stgVar222, array_number_t x_dps, array_number_t y_dps, array_number_t z_dps, card_t x_shp, card_t y_shp, card_t z_shp) {
	card_t size228 = width_card_t(TOP_LEVEL_linalg_vectorAdd_shp(x_shp, y_shp));
	array_number_t stgVar223 = storage_alloc(size228);
	array_number_t macroDef227;
	macroDef227 = TOP_LEVEL_linalg_vectorAdd_dps(stgVar222, TOP_LEVEL_linalg_vectorAdd_dps(stgVar223, x_dps, y_dps, x_shp, y_shp), z_dps, TOP_LEVEL_linalg_vectorAdd_shp(x_shp, y_shp), z_shp);;
	storage_free(stgVar223, size228);
	return macroDef227;
}
typedef empty_env_t env_t_237;


value_t lambda237(env_t_237* env234, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
card_t TOP_LEVEL_linalg_vectorSub_shp(card_t x_shp, card_t y_shp) {
	env_t_237 env_t_237_value = make_empty_env(); closure_t closure236 = make_closure(lambda237, &env_t_237_value);
	return TOP_LEVEL_linalg_vectorMap2_shp(closure236, x_shp, y_shp);
}

typedef empty_env_t env_t_244;


value_t lambda244(env_t_244* env238, storage_t stgVar233, number_t x_dps0, number_t y_dps0, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.number_t_value = (x_dps0) - (y_dps0);
	return res;
}
typedef empty_env_t env_t_245;


value_t lambda245(env_t_245* env241, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
array_number_t TOP_LEVEL_linalg_vectorSub_dps(storage_t stgVar229, array_number_t x_dps, array_number_t y_dps, card_t x_shp, card_t y_shp) {
	env_t_244 env_t_244_value = make_empty_env(); closure_t closure240 = make_closure(lambda244, &env_t_244_value);
	env_t_245 env_t_245_value = make_empty_env(); closure_t closure243 = make_closure(lambda245, &env_t_245_value);
	return TOP_LEVEL_linalg_vectorMap2_dps(stgVar229, closure240, x_dps, y_dps, closure243, x_shp, y_shp);
}
typedef empty_env_t env_t_256;


value_t lambda256(env_t_256* env253, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = TOP_LEVEL_linalg_vectorAdd_shp(x_shp0, y_shp0);
	return res;
}
matrix_shape_t TOP_LEVEL_linalg_matrixAdd_shp(matrix_shape_t x_shp, matrix_shape_t y_shp) {
	env_t_256 env_t_256_value = make_empty_env(); closure_t closure255 = make_closure(lambda256, &env_t_256_value);
	return TOP_LEVEL_linalg_matrixMap2_shp(closure255, x_shp, y_shp);
}

typedef empty_env_t env_t_263;


value_t lambda263(env_t_263* env257, storage_t stgVar250, array_number_t x_dps0, array_number_t y_dps0, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.array_number_t_value = TOP_LEVEL_linalg_vectorAdd_dps(stgVar250, x_dps0, y_dps0, x_shp0, y_shp0);
	return res;
}
typedef empty_env_t env_t_264;


value_t lambda264(env_t_264* env260, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = TOP_LEVEL_linalg_vectorAdd_shp(x_shp0, y_shp0);
	return res;
}
array_array_number_t TOP_LEVEL_linalg_matrixAdd_dps(storage_t stgVar246, array_array_number_t x_dps, array_array_number_t y_dps, matrix_shape_t x_shp, matrix_shape_t y_shp) {
	env_t_263 env_t_263_value = make_empty_env(); closure_t closure259 = make_closure(lambda263, &env_t_263_value);
	env_t_264 env_t_264_value = make_empty_env(); closure_t closure262 = make_closure(lambda264, &env_t_264_value);
	return TOP_LEVEL_linalg_matrixMap2_dps(stgVar246, closure259, x_dps, y_dps, closure262, x_shp, y_shp);
}
typedef empty_env_t env_t_275;


value_t lambda275(env_t_275* env272, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = TOP_LEVEL_linalg_mult_vec_elementwise_shp(x_shp0, y_shp0);
	return res;
}
matrix_shape_t TOP_LEVEL_linalg_matrixMultElementwise_shp(matrix_shape_t x_shp, matrix_shape_t y_shp) {
	env_t_275 env_t_275_value = make_empty_env(); closure_t closure274 = make_closure(lambda275, &env_t_275_value);
	return TOP_LEVEL_linalg_matrixMap2_shp(closure274, x_shp, y_shp);
}

typedef empty_env_t env_t_282;


value_t lambda282(env_t_282* env276, storage_t stgVar269, array_number_t x_dps0, array_number_t y_dps0, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.array_number_t_value = TOP_LEVEL_linalg_mult_vec_elementwise_dps(stgVar269, x_dps0, y_dps0, x_shp0, y_shp0);
	return res;
}
typedef empty_env_t env_t_283;


value_t lambda283(env_t_283* env279, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = TOP_LEVEL_linalg_mult_vec_elementwise_shp(x_shp0, y_shp0);
	return res;
}
array_array_number_t TOP_LEVEL_linalg_matrixMultElementwise_dps(storage_t stgVar265, array_array_number_t x_dps, array_array_number_t y_dps, matrix_shape_t x_shp, matrix_shape_t y_shp) {
	env_t_282 env_t_282_value = make_empty_env(); closure_t closure278 = make_closure(lambda282, &env_t_282_value);
	env_t_283 env_t_283_value = make_empty_env(); closure_t closure281 = make_closure(lambda283, &env_t_283_value);
	return TOP_LEVEL_linalg_matrixMap2_dps(stgVar265, closure278, x_dps, y_dps, closure281, x_shp, y_shp);
}

card_t TOP_LEVEL_linalg_sqnorm_shp(card_t x_shp) {
	
	return 0;
}

typedef empty_env_t env_t_302;


value_t lambda302(env_t_302* env289, card_t x1_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef empty_env_t env_t_303;


value_t lambda303(env_t_303* env292, storage_t stgVar288, number_t x1_dps, card_t x1_shp) {
	
	value_t res;
	res.number_t_value = (x1_dps) * (x1_dps);
	return res;
}
typedef empty_env_t env_t_304;


value_t lambda304(env_t_304* env295, card_t x1_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef empty_env_t env_t_305;


value_t lambda305(env_t_305* env298, card_t x1_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
number_t TOP_LEVEL_linalg_sqnorm_dps(storage_t stgVar284, array_number_t x_dps, card_t x_shp) {
	env_t_302 env_t_302_value = make_empty_env(); closure_t closure291 = make_closure(lambda302, &env_t_302_value);
	card_t size306 = width_card_t(TOP_LEVEL_linalg_vectorMap_shp(closure291, x_shp));
	array_number_t stgVar285 = storage_alloc(size306);
	number_t macroDef301;env_t_303 env_t_303_value = make_empty_env(); closure_t closure294 = make_closure(lambda303, &env_t_303_value);
	env_t_304 env_t_304_value = make_empty_env(); closure_t closure297 = make_closure(lambda304, &env_t_304_value);
	env_t_305 env_t_305_value = make_empty_env(); closure_t closure300 = make_closure(lambda305, &env_t_305_value);
	macroDef301 = TOP_LEVEL_linalg_vectorSum_dps(stgVar284, TOP_LEVEL_linalg_vectorMap_dps(stgVar285, closure294, x_dps, closure297, x_shp), TOP_LEVEL_linalg_vectorMap_shp(closure300, x_shp));;
	storage_free(stgVar285, size306);
	return macroDef301;
}

card_t TOP_LEVEL_linalg_dot_prod_shp(card_t x_shp, card_t y_shp) {
	
	return 0;
}

typedef empty_env_t env_t_326;


value_t lambda326(env_t_326* env313, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef empty_env_t env_t_327;


value_t lambda327(env_t_327* env316, storage_t stgVar312, number_t x_dps0, number_t y_dps0, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.number_t_value = (x_dps0) * (y_dps0);
	return res;
}
typedef empty_env_t env_t_328;


value_t lambda328(env_t_328* env319, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef empty_env_t env_t_329;


value_t lambda329(env_t_329* env322, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
number_t TOP_LEVEL_linalg_dot_prod_dps(storage_t stgVar307, array_number_t x_dps, array_number_t y_dps, card_t x_shp, card_t y_shp) {
	env_t_326 env_t_326_value = make_empty_env(); closure_t closure315 = make_closure(lambda326, &env_t_326_value);
	card_t size330 = width_card_t(TOP_LEVEL_linalg_vectorMap2_shp(closure315, x_shp, y_shp));
	array_number_t stgVar308 = storage_alloc(size330);
	number_t macroDef325;env_t_327 env_t_327_value = make_empty_env(); closure_t closure318 = make_closure(lambda327, &env_t_327_value);
	env_t_328 env_t_328_value = make_empty_env(); closure_t closure321 = make_closure(lambda328, &env_t_328_value);
	env_t_329 env_t_329_value = make_empty_env(); closure_t closure324 = make_closure(lambda329, &env_t_329_value);
	macroDef325 = TOP_LEVEL_linalg_vectorSum_dps(stgVar307, TOP_LEVEL_linalg_vectorMap2_dps(stgVar308, closure318, x_dps, y_dps, closure321, x_shp, y_shp), TOP_LEVEL_linalg_vectorMap2_shp(closure324, x_shp, y_shp));;
	storage_free(stgVar308, size330);
	return macroDef325;
}
typedef struct env_t_341 {
	card_t row_shp;
} env_t_341;
env_t_341 make_env_t_341(card_t row_shp) {
	env_t_341 env;
	env.row_shp = row_shp;
	return env;
}

value_t lambda341(env_t_341* env338, card_t r_shp) {
	card_t row_shp337 = env338->row_shp;
	value_t res;
	res.card_t_value = row_shp337;
	return res;
}
matrix_shape_t TOP_LEVEL_linalg_matrixFillFromVector_shp(card_t rows_shp, card_t row_shp) {
	env_t_341 env_t_341_value = make_env_t_341(row_shp); closure_t closure340 = make_closure(lambda341, &env_t_341_value);
	return TOP_LEVEL_linalg_vectorMapToMatrix_shp(closure340, TOP_LEVEL_linalg_vectorRange_shp(1, rows_shp));
}

typedef struct env_t_351 {
	array_number_t row_dps;
} env_t_351;
env_t_351 make_env_t_351(array_number_t row_dps) {
	env_t_351 env;
	env.row_dps = row_dps;
	return env;
}

value_t lambda351(env_t_351* env343, storage_t stgVar334, number_t r_dps, card_t r_shp) {
	array_number_t row_dps342 = env343->row_dps;
	value_t res;
	res.array_number_t_value = row_dps342;
	return res;
}
typedef struct env_t_352 {
	card_t row_shp;
} env_t_352;
env_t_352 make_env_t_352(card_t row_shp) {
	env_t_352 env;
	env.row_shp = row_shp;
	return env;
}

value_t lambda352(env_t_352* env347, card_t r_shp) {
	card_t row_shp346 = env347->row_shp;
	value_t res;
	res.card_t_value = row_shp346;
	return res;
}
array_array_number_t TOP_LEVEL_linalg_matrixFillFromVector_dps(storage_t stgVar331, card_t rows_dps, array_number_t row_dps, card_t rows_shp, card_t row_shp) {
	card_t size353 = width_card_t(TOP_LEVEL_linalg_vectorRange_shp(1, rows_shp));
	array_number_t stgVar333 = storage_alloc(size353);
	array_array_number_t macroDef350;env_t_351 env_t_351_value = make_env_t_351(row_dps); closure_t closure345 = make_closure(lambda351, &env_t_351_value);
	env_t_352 env_t_352_value = make_env_t_352(row_shp); closure_t closure349 = make_closure(lambda352, &env_t_352_value);
	macroDef350 = TOP_LEVEL_linalg_vectorMapToMatrix_dps(stgVar331, closure345, TOP_LEVEL_linalg_vectorRange_dps(stgVar333, 1, rows_dps, 1, rows_shp), closure349, TOP_LEVEL_linalg_vectorRange_shp(1, rows_shp));;
	storage_free(stgVar333, size353);
	return macroDef350;
}

matrix_shape_t TOP_LEVEL_linalg_matrixFill_shp(card_t rows_shp, card_t cols_shp, card_t value_shp) {
	
	return nested_shape_card_t(cols_shp, rows_shp);
}


array_array_number_t TOP_LEVEL_linalg_matrixFill_dps(storage_t stgVar354, card_t rows_dps, card_t cols_dps, number_t value_dps, card_t rows_shp, card_t cols_shp, card_t value_shp) {
	array_array_number_t macroDef358 = (array_array_number_t)stgVar354;
		macroDef358->length=rows_dps;
		macroDef358->arr=(array_number_t*)(STG_OFFSET(macroDef358, VECTOR_HEADER_BYTES));
		storage_t stgVar355 = (STG_OFFSET(macroDef358, MATRIX_HEADER_BYTES(rows_dps)));
		for(int r_dps = 0; r_dps < macroDef358->length; r_dps++){
			array_number_t macroDef357 = (array_number_t)stgVar355;
		macroDef357->length=cols_dps;
		macroDef357->arr=(number_t*)(STG_OFFSET(macroDef357, VECTOR_HEADER_BYTES));
		storage_t stgVar356 = macroDef357;
		for(int c_dps = 0; c_dps < macroDef357->length; c_dps++){
			
			macroDef357->arr[c_dps] = value_dps;;
			stgVar356 = STG_OFFSET(stgVar356, sizeof(number_t));
		}
			macroDef358->arr[r_dps] = macroDef357;;
			stgVar355 = STG_OFFSET(stgVar355, VECTOR_ALL_BYTES(macroDef358->arr[r_dps]->length));
		}
	return macroDef358;
}

matrix_shape_t TOP_LEVEL_linalg_matrixTranspose_shp(matrix_shape_t m_shp) {
	
	return nested_shape_card_t(m_shp.card, m_shp.elem);
}


array_array_number_t TOP_LEVEL_linalg_matrixTranspose_dps(storage_t stgVar359, array_array_number_t m_dps, matrix_shape_t m_shp) {
	card_t rows_shp = m_shp.card;
	card_t macroDef371 = m_dps->length;
	card_t rows_dps = macroDef371;
	card_t cols_shp = m_shp.elem;
	card_t size377 = width_card_t(m_shp.elem);
	array_number_t stgVar363 = storage_alloc(size377);
	card_t macroDef373;card_t macroDef372 = m_dps->arr[0]->length;
	macroDef373 = macroDef372;;
	storage_free(stgVar363, size377);
	card_t cols_dps = macroDef373;
	array_array_number_t macroDef376 = (array_array_number_t)stgVar359;
		macroDef376->length=cols_dps;
		macroDef376->arr=(array_number_t*)(STG_OFFSET(macroDef376, VECTOR_HEADER_BYTES));
		storage_t stgVar365 = (STG_OFFSET(macroDef376, MATRIX_HEADER_BYTES(cols_dps)));
		for(int i_dps = 0; i_dps < macroDef376->length; i_dps++){
			array_number_t macroDef375 = (array_number_t)stgVar365;
		macroDef375->length=rows_dps;
		macroDef375->arr=(number_t*)(STG_OFFSET(macroDef375, VECTOR_HEADER_BYTES));
		storage_t stgVar366 = macroDef375;
		for(int j_dps = 0; j_dps < macroDef375->length; j_dps++){
			card_t size378 = width_card_t(m_shp.elem);
	array_number_t stgVar367 = storage_alloc(size378);
	number_t macroDef374;
	macroDef374 = m_dps->arr[j_dps]->arr[i_dps];;
	storage_free(stgVar367, size378);
			macroDef375->arr[j_dps] = macroDef374;;
			stgVar366 = STG_OFFSET(stgVar366, sizeof(number_t));
		}
			macroDef376->arr[i_dps] = macroDef375;;
			stgVar365 = STG_OFFSET(stgVar365, VECTOR_ALL_BYTES(macroDef376->arr[i_dps]->length));
		}
	return macroDef376;
}

matrix_shape_t TOP_LEVEL_linalg_matrixMult_shp(matrix_shape_t m1_shp, matrix_shape_t m2_shp) {
	
	return nested_shape_card_t(m2_shp.elem, m1_shp.card);
}


array_array_number_t TOP_LEVEL_linalg_matrixMult_dps(storage_t stgVar379, array_array_number_t m1_dps, array_array_number_t m2_dps, matrix_shape_t m1_shp, matrix_shape_t m2_shp) {
	card_t r1_shp = m1_shp.card;
	card_t macroDef418 = m1_dps->length;
	card_t r1_dps = macroDef418;
	card_t c2_shp = m2_shp.elem;
	card_t size429 = width_card_t(m2_shp.elem);
	array_number_t stgVar383 = storage_alloc(size429);
	card_t macroDef420;card_t macroDef419 = m2_dps->arr[0]->length;
	macroDef420 = macroDef419;;
	storage_free(stgVar383, size429);
	card_t c2_dps = macroDef420;
	card_t c1_shp = m1_shp.elem;
	card_t size430 = width_card_t(m1_shp.elem);
	array_number_t stgVar386 = storage_alloc(size430);
	card_t macroDef422;card_t macroDef421 = m1_dps->arr[0]->length;
	macroDef422 = macroDef421;;
	storage_free(stgVar386, size430);
	card_t c1_dps = macroDef422;
	card_t r2_shp = m2_shp.card;
	card_t macroDef423 = m2_dps->length;
	card_t r2_dps = macroDef423;
	matrix_shape_t m2T_shp = TOP_LEVEL_linalg_matrixTranspose_shp(m2_shp);
	card_t size433 = width_matrix_shape_t(m2T_shp);
	array_number_t stgVar390 = storage_alloc(size433);
	array_array_number_t macroDef428;array_array_number_t m2T_dps = TOP_LEVEL_linalg_matrixTranspose_dps(stgVar390, m2_dps, m2_shp);
	array_array_number_t macroDef427 = (array_array_number_t)stgVar379;
		macroDef427->length=r1_dps;
		macroDef427->arr=(array_number_t*)(STG_OFFSET(macroDef427, VECTOR_HEADER_BYTES));
		storage_t stgVar392 = (STG_OFFSET(macroDef427, MATRIX_HEADER_BYTES(r1_dps)));
		for(int r_dps = 0; r_dps < macroDef427->length; r_dps++){
			array_number_t macroDef426 = (array_number_t)stgVar392;
		macroDef426->length=c2_dps;
		macroDef426->arr=(number_t*)(STG_OFFSET(macroDef426, VECTOR_HEADER_BYTES));
		storage_t stgVar393 = macroDef426;
		for(int c_dps = 0; c_dps < macroDef426->length; c_dps++){
			card_t size432 = width_card_t(m2T_shp.elem);
	array_number_t stgVar395 = storage_alloc(size432);
	number_t macroDef425;card_t size431 = width_card_t(m1_shp.elem);
	array_number_t stgVar394 = storage_alloc(size431);
	number_t macroDef424;
	macroDef424 = TOP_LEVEL_linalg_dot_prod_dps(stgVar393, m1_dps->arr[r_dps], m2T_dps->arr[c_dps], m1_shp.elem, m2T_shp.elem);;
	storage_free(stgVar394, size431);
	macroDef425 = macroDef424;;
	storage_free(stgVar395, size432);
			macroDef426->arr[c_dps] = macroDef425;;
			stgVar393 = STG_OFFSET(stgVar393, sizeof(number_t));
		}
			macroDef427->arr[r_dps] = macroDef426;;
			stgVar392 = STG_OFFSET(stgVar392, VECTOR_ALL_BYTES(macroDef427->arr[r_dps]->length));
		}
	macroDef428 = macroDef427;;
	storage_free(stgVar390, size433);
	return macroDef428;
}

card_t TOP_LEVEL_linalg_matrixVectorMult_shp(matrix_shape_t m_shp, card_t v_shp) {
	
	return TOP_LEVEL_linalg_rows_shp(m_shp);
}


array_number_t TOP_LEVEL_linalg_matrixVectorMult_dps(storage_t stgVar434, array_array_number_t m_dps, array_number_t v_dps, matrix_shape_t m_shp, card_t v_shp) {
	card_t r_shp = TOP_LEVEL_linalg_rows_shp(m_shp);
	card_t size451 = width_card_t(r_shp);
	array_number_t stgVar435 = storage_alloc(size451);
	array_number_t macroDef448;card_t r_dps = TOP_LEVEL_linalg_rows_dps(stgVar435, m_dps, m_shp);
	card_t c_shp = TOP_LEVEL_linalg_cols_shp(m_shp);
	card_t size450 = width_card_t(c_shp);
	array_number_t stgVar437 = storage_alloc(size450);
	array_number_t macroDef447;card_t c_dps = TOP_LEVEL_linalg_cols_dps(stgVar437, m_dps, m_shp);
	array_number_t macroDef446 = (array_number_t)stgVar434;
		macroDef446->length=r_dps;
		macroDef446->arr=(number_t*)(STG_OFFSET(macroDef446, VECTOR_HEADER_BYTES));
		storage_t stgVar439 = macroDef446;
		for(int i_dps = 0; i_dps < macroDef446->length; i_dps++){
			card_t size449 = width_card_t(m_shp.elem);
	array_number_t stgVar440 = storage_alloc(size449);
	number_t macroDef445;
	macroDef445 = TOP_LEVEL_linalg_dot_prod_dps(stgVar439, m_dps->arr[i_dps], v_dps, m_shp.elem, v_shp);;
	storage_free(stgVar440, size449);
			macroDef446->arr[i_dps] = macroDef445;;
			stgVar439 = STG_OFFSET(stgVar439, sizeof(number_t));
		}
	macroDef447 = macroDef446;;
	storage_free(stgVar437, size450);
	macroDef448 = macroDef447;;
	storage_free(stgVar435, size451);
	return macroDef448;
}

matrix_shape_t TOP_LEVEL_linalg_matrixConcat_shp(matrix_shape_t m1_shp, matrix_shape_t m2_shp) {
	
	return nested_shape_card_t(m1_shp.elem, (m1_shp.card) + (m2_shp.card));
}


array_array_number_t TOP_LEVEL_linalg_matrixConcat_dps(storage_t stgVar452, array_array_number_t m1_dps, array_array_number_t m2_dps, matrix_shape_t m1_shp, matrix_shape_t m2_shp) {
	card_t rows_shp = (m1_shp.card) + (m2_shp.card);
	card_t macroDef463 = m1_dps->length;
	card_t macroDef464 = m2_dps->length;
	card_t rows_dps = (macroDef463) + (macroDef464);
	card_t m1Rows_shp = 0;
	card_t macroDef465 = m1_dps->length;
	index_t m1Rows_dps = (macroDef465);
	array_array_number_t macroDef466 = (array_array_number_t)stgVar452;
		macroDef466->length=rows_dps;
		macroDef466->arr=(array_number_t*)(STG_OFFSET(macroDef466, VECTOR_HEADER_BYTES));
		storage_t stgVar458 = (STG_OFFSET(macroDef466, MATRIX_HEADER_BYTES(rows_dps)));
		for(int r_dps = 0; r_dps < macroDef466->length; r_dps++){
			array_number_t ite467 = 0;
	if((r_dps) < (m1Rows_dps)) {
		
		ite467 = m1_dps->arr[r_dps];;
	} else {
		
		ite467 = m2_dps->arr[(r_dps) - (m1Rows_dps)];;
	}
			macroDef466->arr[r_dps] = ite467;;
			stgVar458 = STG_OFFSET(stgVar458, VECTOR_ALL_BYTES(macroDef466->arr[r_dps]->length));
		}
	return macroDef466;
}

matrix_shape_t TOP_LEVEL_linalg_matrixConcatCol_shp(matrix_shape_t m1_shp, matrix_shape_t m2_shp) {
	
	return TOP_LEVEL_linalg_matrixTranspose_shp(TOP_LEVEL_linalg_matrixConcat_shp(TOP_LEVEL_linalg_matrixTranspose_shp(m1_shp), TOP_LEVEL_linalg_matrixTranspose_shp(m2_shp)));
}


array_array_number_t TOP_LEVEL_linalg_matrixConcatCol_dps(storage_t stgVar468, array_array_number_t m1_dps, array_array_number_t m2_dps, matrix_shape_t m1_shp, matrix_shape_t m2_shp) {
	matrix_shape_t m1t_shp = TOP_LEVEL_linalg_matrixTranspose_shp(m1_shp);
	card_t size483 = width_matrix_shape_t(m1t_shp);
	array_number_t stgVar469 = storage_alloc(size483);
	array_array_number_t macroDef480;array_array_number_t m1t_dps = TOP_LEVEL_linalg_matrixTranspose_dps(stgVar469, m1_dps, m1_shp);
	matrix_shape_t m2t_shp = TOP_LEVEL_linalg_matrixTranspose_shp(m2_shp);
	card_t size482 = width_matrix_shape_t(m2t_shp);
	array_number_t stgVar471 = storage_alloc(size482);
	array_array_number_t macroDef479;array_array_number_t m2t_dps = TOP_LEVEL_linalg_matrixTranspose_dps(stgVar471, m2_dps, m2_shp);
	card_t size481 = width_matrix_shape_t(TOP_LEVEL_linalg_matrixConcat_shp(m1t_shp, m2t_shp));
	array_number_t stgVar473 = storage_alloc(size481);
	array_array_number_t macroDef478;
	macroDef478 = TOP_LEVEL_linalg_matrixTranspose_dps(stgVar468, TOP_LEVEL_linalg_matrixConcat_dps(stgVar473, m1t_dps, m2t_dps, m1t_shp, m2t_shp), TOP_LEVEL_linalg_matrixConcat_shp(m1t_shp, m2t_shp));;
	storage_free(stgVar473, size481);
	macroDef479 = macroDef478;;
	storage_free(stgVar471, size482);
	macroDef480 = macroDef479;;
	storage_free(stgVar469, size483);
	return macroDef480;
}

matrix3d_shape_t TOP_LEVEL_linalg_matrix3DConcat_shp(matrix3d_shape_t m1_shp, matrix3d_shape_t m2_shp) {
	
	return nested_shape_matrix_shape_t(m1_shp.elem, (m1_shp.card) + (m2_shp.card));
}


array_array_array_number_t TOP_LEVEL_linalg_matrix3DConcat_dps(storage_t stgVar484, array_array_array_number_t m1_dps, array_array_array_number_t m2_dps, matrix3d_shape_t m1_shp, matrix3d_shape_t m2_shp) {
	card_t rows_shp = (m1_shp.card) + (m2_shp.card);
	card_t macroDef495 = m1_dps->length;
	card_t macroDef496 = m2_dps->length;
	card_t rows_dps = (macroDef495) + (macroDef496);
	card_t m1Rows_shp = 0;
	card_t macroDef497 = m1_dps->length;
	index_t m1Rows_dps = (macroDef497);
	array_array_array_number_t macroDef498 = (array_array_array_number_t)stgVar484;
		macroDef498->length=rows_dps;
		macroDef498->arr=(array_array_number_t*)(STG_OFFSET(macroDef498, VECTOR_HEADER_BYTES));
		storage_t stgVar490 = (STG_OFFSET(macroDef498, MATRIX_HEADER_BYTES(rows_dps)));
		for(int r_dps = 0; r_dps < macroDef498->length; r_dps++){
			array_array_number_t ite499 = 0;
	if((r_dps) < (m1Rows_dps)) {
		
		ite499 = m1_dps->arr[r_dps];;
	} else {
		
		ite499 = m2_dps->arr[(r_dps) - (m1Rows_dps)];;
	}
			macroDef498->arr[r_dps] = ite499;;
			stgVar490 = STG_OFFSET(stgVar490, VECTOR_ALL_BYTES(macroDef498->arr[r_dps]->length));
		}
	return macroDef498;
}

card_t TOP_LEVEL_linalg_vectorRead_shp(card_t fn_shp, card_t startLine_shp) {
	
	return nested_shape_card_t(10, 1).elem;
}


array_number_t TOP_LEVEL_linalg_vectorRead_dps(storage_t stgVar500, string_t fn_dps, index_t startLine_dps, card_t fn_shp, card_t startLine_shp) {
	matrix_shape_t matrix_shp = nested_shape_card_t(10, 1);
	card_t size504 = width_matrix_shape_t(matrix_shp);
	array_number_t stgVar501 = storage_alloc(size504);
	array_number_t macroDef503;array_array_number_t matrix_dps = matrix_read_s(stgVar501, fn_dps, startLine_dps, 1);
	macroDef503 = matrix_dps->arr[0];;
	storage_free(stgVar501, size504);
	return macroDef503;
}

card_t TOP_LEVEL_linalg_numberRead_shp(card_t fn_shp, card_t startLine_shp) {
	
	return 0;
}


number_t TOP_LEVEL_linalg_numberRead_dps(storage_t stgVar505, string_t fn_dps, index_t startLine_dps, card_t fn_shp, card_t startLine_shp) {
	card_t vector_shp = TOP_LEVEL_linalg_vectorRead_shp(0, 0);
	card_t size511 = width_card_t(vector_shp);
	array_number_t stgVar506 = storage_alloc(size511);
	number_t macroDef510;array_number_t vector_dps = TOP_LEVEL_linalg_vectorRead_dps(stgVar506, fn_dps, startLine_dps, 0, 0);
	macroDef510 = vector_dps->arr[0];;
	storage_free(stgVar506, size511);
	return macroDef510;
}

card_t TOP_LEVEL_linalg_vec3_shp(card_t a_shp, card_t b_shp, card_t c_shp) {
	
	return 3;
}


array_number_t TOP_LEVEL_linalg_vec3_dps(storage_t stgVar512, number_t a_dps, number_t b_dps, number_t c_dps, card_t a_shp, card_t b_shp, card_t c_shp) {
	array_number_t macroDef516 = (array_number_t)stgVar512;
	macroDef516->length=3;
	macroDef516->arr=(number_t*)(STG_OFFSET(stgVar512, VECTOR_HEADER_BYTES));
	macroDef516->arr[0] = a_dps;
	macroDef516->arr[1] = b_dps;
	macroDef516->arr[2] = c_dps;;
	return macroDef516;
}
#endif
