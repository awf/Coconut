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

matrix_shape_t TOP_LEVEL_linalg_matrixSlice_shp(card_t size_shp, card_t offset_shp, matrix_shape_t m_shp) {
	
	return nested_shape_card_t(m_shp.elem, size_shp);
}


array_array_number_t TOP_LEVEL_linalg_matrixSlice_dps(storage_t stgVar24, card_t size_dps, index_t offset_dps, array_array_number_t m_dps, card_t size_shp, card_t offset_shp, matrix_shape_t m_shp) {
	array_array_number_t macroDef27 = (array_array_number_t)stgVar24;
		macroDef27->length=size_dps;
		macroDef27->arr=(array_number_t*)(STG_OFFSET(macroDef27, VECTOR_HEADER_BYTES));
		storage_t stgVar25 = (STG_OFFSET(macroDef27, MATRIX_HEADER_BYTES(size_dps)));
		for(int i_dps = 0; i_dps < macroDef27->length; i_dps++){
			
			macroDef27->arr[i_dps] = m_dps->arr[(i_dps) + (offset_dps)];;
			stgVar25 = STG_OFFSET(stgVar25, VECTOR_ALL_BYTES(macroDef27->arr[i_dps]->length));
		}
	return macroDef27;
}

matrix_shape_t TOP_LEVEL_linalg_matrixMap_shp(closure_t f_shp, matrix_shape_t m_shp) {
	
	return nested_shape_card_t(f_shp.lam(f_shp.env, m_shp.elem).card_t_value, m_shp.card);
}


array_array_number_t TOP_LEVEL_linalg_matrixMap_dps(storage_t stgVar28, closure_t f_dps, array_array_number_t m_dps, closure_t f_shp, matrix_shape_t m_shp) {
	card_t macroDef33 = m_dps->length;
	array_array_number_t macroDef35 = (array_array_number_t)stgVar28;
		macroDef35->length=macroDef33;
		macroDef35->arr=(array_number_t*)(STG_OFFSET(macroDef35, VECTOR_HEADER_BYTES));
		storage_t stgVar30 = (STG_OFFSET(macroDef35, MATRIX_HEADER_BYTES(macroDef33)));
		for(int i_dps = 0; i_dps < macroDef35->length; i_dps++){
			card_t size36 = width_card_t(m_shp.elem);
	array_number_t stgVar31 = storage_alloc(size36);
	array_number_t macroDef34;
	macroDef34 = f_dps.lam(f_dps.env, stgVar30, m_dps->arr[i_dps], m_shp.elem).array_number_t_value;;
	storage_free(stgVar31, size36);
			macroDef35->arr[i_dps] = macroDef34;;
			stgVar30 = STG_OFFSET(stgVar30, VECTOR_ALL_BYTES(macroDef35->arr[i_dps]->length));
		}
	return macroDef35;
}

card_t TOP_LEVEL_linalg_matrixMapToVector_shp(closure_t f_shp, matrix_shape_t m_shp) {
	
	return m_shp.card;
}


array_number_t TOP_LEVEL_linalg_matrixMapToVector_dps(storage_t stgVar37, closure_t f_dps, array_array_number_t m_dps, closure_t f_shp, matrix_shape_t m_shp) {
	card_t macroDef42 = m_dps->length;
	array_number_t macroDef44 = (array_number_t)stgVar37;
		macroDef44->length=macroDef42;
		macroDef44->arr=(number_t*)(STG_OFFSET(macroDef44, VECTOR_HEADER_BYTES));
		storage_t stgVar39 = macroDef44;
		for(int i_dps = 0; i_dps < macroDef44->length; i_dps++){
			card_t size45 = width_card_t(m_shp.elem);
	array_number_t stgVar40 = storage_alloc(size45);
	number_t macroDef43;
	macroDef43 = f_dps.lam(f_dps.env, stgVar39, m_dps->arr[i_dps], m_shp.elem).number_t_value;;
	storage_free(stgVar40, size45);
			macroDef44->arr[i_dps] = macroDef43;;
			stgVar39 = STG_OFFSET(stgVar39, sizeof(number_t));
		}
	return macroDef44;
}

card_t TOP_LEVEL_linalg_vectorMap2_shp(closure_t f_shp, card_t v1_shp, card_t v2_shp) {
	
	return v1_shp;
}


array_number_t TOP_LEVEL_linalg_vectorMap2_dps(storage_t stgVar46, closure_t f_dps, array_number_t v1_dps, array_number_t v2_dps, closure_t f_shp, card_t v1_shp, card_t v2_shp) {
	card_t macroDef53 = v1_dps->length;
	array_number_t macroDef54 = (array_number_t)stgVar46;
		macroDef54->length=macroDef53;
		macroDef54->arr=(number_t*)(STG_OFFSET(macroDef54, VECTOR_HEADER_BYTES));
		storage_t stgVar48 = macroDef54;
		for(int i_dps = 0; i_dps < macroDef54->length; i_dps++){
			
			macroDef54->arr[i_dps] = f_dps.lam(f_dps.env, stgVar48, v1_dps->arr[i_dps], v2_dps->arr[i_dps], 0, 0).number_t_value;;
			stgVar48 = STG_OFFSET(stgVar48, sizeof(number_t));
		}
	return macroDef54;
}

matrix_shape_t TOP_LEVEL_linalg_matrixMap2_shp(closure_t f_shp, matrix_shape_t m1_shp, matrix_shape_t m2_shp) {
	
	return nested_shape_card_t(f_shp.lam(f_shp.env, m1_shp.elem, m2_shp.elem).card_t_value, m1_shp.card);
}


array_array_number_t TOP_LEVEL_linalg_matrixMap2_dps(storage_t stgVar55, closure_t f_dps, array_array_number_t m1_dps, array_array_number_t m2_dps, closure_t f_shp, matrix_shape_t m1_shp, matrix_shape_t m2_shp) {
	card_t macroDef62 = m1_dps->length;
	array_array_number_t macroDef65 = (array_array_number_t)stgVar55;
		macroDef65->length=macroDef62;
		macroDef65->arr=(array_number_t*)(STG_OFFSET(macroDef65, VECTOR_HEADER_BYTES));
		storage_t stgVar57 = (STG_OFFSET(macroDef65, MATRIX_HEADER_BYTES(macroDef62)));
		for(int i_dps = 0; i_dps < macroDef65->length; i_dps++){
			card_t size67 = width_card_t(m2_shp.elem);
	array_number_t stgVar59 = storage_alloc(size67);
	array_number_t macroDef64;card_t size66 = width_card_t(m1_shp.elem);
	array_number_t stgVar58 = storage_alloc(size66);
	array_number_t macroDef63;
	macroDef63 = f_dps.lam(f_dps.env, stgVar57, m1_dps->arr[i_dps], m2_dps->arr[i_dps], m1_shp.elem, m2_shp.elem).array_number_t_value;;
	storage_free(stgVar58, size66);
	macroDef64 = macroDef63;;
	storage_free(stgVar59, size67);
			macroDef65->arr[i_dps] = macroDef64;;
			stgVar57 = STG_OFFSET(stgVar57, VECTOR_ALL_BYTES(macroDef65->arr[i_dps]->length));
		}
	return macroDef65;
}

matrix3d_shape_t TOP_LEVEL_linalg_matrix3DMap2_shp(closure_t f_shp, matrix3d_shape_t m1_shp, matrix3d_shape_t m2_shp) {
	
	return nested_shape_matrix_shape_t(f_shp.lam(f_shp.env, m1_shp.elem, m2_shp.elem).matrix_shape_t_value, m1_shp.card);
}


array_array_array_number_t TOP_LEVEL_linalg_matrix3DMap2_dps(storage_t stgVar68, closure_t f_dps, array_array_array_number_t m1_dps, array_array_array_number_t m2_dps, closure_t f_shp, matrix3d_shape_t m1_shp, matrix3d_shape_t m2_shp) {
	card_t macroDef75 = m1_dps->length;
	array_array_array_number_t macroDef78 = (array_array_array_number_t)stgVar68;
		macroDef78->length=macroDef75;
		macroDef78->arr=(array_array_number_t*)(STG_OFFSET(macroDef78, VECTOR_HEADER_BYTES));
		storage_t stgVar70 = (STG_OFFSET(macroDef78, MATRIX_HEADER_BYTES(macroDef75)));
		for(int i_dps = 0; i_dps < macroDef78->length; i_dps++){
			card_t size80 = width_matrix_shape_t(m2_shp.elem);
	array_number_t stgVar72 = storage_alloc(size80);
	array_array_number_t macroDef77;card_t size79 = width_matrix_shape_t(m1_shp.elem);
	array_number_t stgVar71 = storage_alloc(size79);
	array_array_number_t macroDef76;
	macroDef76 = f_dps.lam(f_dps.env, stgVar70, m1_dps->arr[i_dps], m2_dps->arr[i_dps], m1_shp.elem, m2_shp.elem).array_array_number_t_value;;
	storage_free(stgVar71, size79);
	macroDef77 = macroDef76;;
	storage_free(stgVar72, size80);
			macroDef78->arr[i_dps] = macroDef77;;
			stgVar70 = STG_OFFSET(stgVar70, VECTOR_ALL_BYTES(macroDef78->arr[i_dps]->length));
		}
	return macroDef78;
}

matrix_shape_t TOP_LEVEL_linalg_vectorMapToMatrix_shp(closure_t f_shp, card_t arr_shp) {
	
	return nested_shape_card_t(f_shp.lam(f_shp.env, 0).card_t_value, arr_shp);
}


array_array_number_t TOP_LEVEL_linalg_vectorMapToMatrix_dps(storage_t stgVar81, closure_t f_dps, array_number_t arr_dps, closure_t f_shp, card_t arr_shp) {
	card_t macroDef86 = arr_dps->length;
	array_array_number_t macroDef87 = (array_array_number_t)stgVar81;
		macroDef87->length=macroDef86;
		macroDef87->arr=(array_number_t*)(STG_OFFSET(macroDef87, VECTOR_HEADER_BYTES));
		storage_t stgVar83 = (STG_OFFSET(macroDef87, MATRIX_HEADER_BYTES(macroDef86)));
		for(int i_dps = 0; i_dps < macroDef87->length; i_dps++){
			
			macroDef87->arr[i_dps] = f_dps.lam(f_dps.env, stgVar83, arr_dps->arr[i_dps], 0).array_number_t_value;;
			stgVar83 = STG_OFFSET(stgVar83, VECTOR_ALL_BYTES(macroDef87->arr[i_dps]->length));
		}
	return macroDef87;
}

matrix3d_shape_t TOP_LEVEL_linalg_vectorMapToMatrix3D_shp(closure_t f_shp, card_t arr_shp) {
	
	return nested_shape_matrix_shape_t(f_shp.lam(f_shp.env, 0).matrix_shape_t_value, arr_shp);
}


array_array_array_number_t TOP_LEVEL_linalg_vectorMapToMatrix3D_dps(storage_t stgVar88, closure_t f_dps, array_number_t arr_dps, closure_t f_shp, card_t arr_shp) {
	card_t macroDef93 = arr_dps->length;
	array_array_array_number_t macroDef94 = (array_array_array_number_t)stgVar88;
		macroDef94->length=macroDef93;
		macroDef94->arr=(array_array_number_t*)(STG_OFFSET(macroDef94, VECTOR_HEADER_BYTES));
		storage_t stgVar90 = (STG_OFFSET(macroDef94, MATRIX_HEADER_BYTES(macroDef93)));
		for(int i_dps = 0; i_dps < macroDef94->length; i_dps++){
			
			macroDef94->arr[i_dps] = f_dps.lam(f_dps.env, stgVar90, arr_dps->arr[i_dps], 0).array_array_number_t_value;;
			stgVar90 = STG_OFFSET(stgVar90, VECTOR_ALL_BYTES(macroDef94->arr[i_dps]->length));
		}
	return macroDef94;
}

card_t TOP_LEVEL_linalg_iterateNumber_shp(closure_t f_shp, card_t z_shp, card_t s_shp, card_t e_shp) {
	
	return 0;
}


number_t TOP_LEVEL_linalg_iterateNumber_dps(storage_t stgVar95, closure_t f_dps, number_t z_dps, card_t s_dps, card_t e_dps, closure_t f_shp, card_t z_shp, card_t s_shp, card_t e_shp) {
	card_t anfvar96_shp = TOP_LEVEL_linalg_vectorRange_shp(s_shp, e_shp);
	card_t size105 = width_card_t(anfvar96_shp);
	array_number_t stgVar97 = storage_alloc(size105);
	number_t macroDef104;array_number_t anfvar96_dps = TOP_LEVEL_linalg_vectorRange_dps(stgVar97, s_dps, e_dps, s_shp, e_shp);
	number_t macroDef103 = z_dps;
	array_number_t cur_dps_range = anfvar96_dps;
	storage_t stgVar100 = stgVar95;
	for(int cur_dps_idx = 0; cur_dps_idx < cur_dps_range->length; cur_dps_idx++){
		number_t cur_dps = cur_dps_range->arr[cur_dps_idx];
		
		macroDef103 = f_dps.lam(f_dps.env, stgVar100, macroDef103, (int)(cur_dps), 0, 0).number_t_value;;
	}
	macroDef104 = macroDef103;;
	storage_free(stgVar97, size105);
	return macroDef104;
}

card_t TOP_LEVEL_linalg_iterateVector_shp(closure_t f_shp, card_t z_shp, card_t s_shp, card_t e_shp) {
	
	return z_shp;
}


array_number_t TOP_LEVEL_linalg_iterateVector_dps(storage_t stgVar106, closure_t f_dps, array_number_t z_dps, card_t s_dps, card_t e_dps, closure_t f_shp, card_t z_shp, card_t s_shp, card_t e_shp) {
	card_t anfvar107_shp = TOP_LEVEL_linalg_vectorRange_shp(s_shp, e_shp);
	card_t size116 = width_card_t(anfvar107_shp);
	array_number_t stgVar108 = storage_alloc(size116);
	array_number_t macroDef115;array_number_t anfvar107_dps = TOP_LEVEL_linalg_vectorRange_dps(stgVar108, s_dps, e_dps, s_shp, e_shp);
	array_number_t macroDef114 = z_dps;
	array_number_t cur_dps_range = anfvar107_dps;
	storage_t stgVar111 = stgVar106;
	for(int cur_dps_idx = 0; cur_dps_idx < cur_dps_range->length; cur_dps_idx++){
		number_t cur_dps = cur_dps_range->arr[cur_dps_idx];
		
		macroDef114 = f_dps.lam(f_dps.env, stgVar111, macroDef114, (int)(cur_dps), z_shp, 0).array_number_t_value;;
	}
	macroDef115 = macroDef114;;
	storage_free(stgVar108, size116);
	return macroDef115;
}

matrix_shape_t TOP_LEVEL_linalg_iterateMatrix_shp(closure_t f_shp, matrix_shape_t z_shp, card_t s_shp, card_t e_shp) {
	
	return z_shp;
}


array_array_number_t TOP_LEVEL_linalg_iterateMatrix_dps(storage_t stgVar117, closure_t f_dps, array_array_number_t z_dps, card_t s_dps, card_t e_dps, closure_t f_shp, matrix_shape_t z_shp, card_t s_shp, card_t e_shp) {
	card_t anfvar118_shp = TOP_LEVEL_linalg_vectorRange_shp(s_shp, e_shp);
	card_t size127 = width_card_t(anfvar118_shp);
	array_number_t stgVar119 = storage_alloc(size127);
	array_array_number_t macroDef126;array_number_t anfvar118_dps = TOP_LEVEL_linalg_vectorRange_dps(stgVar119, s_dps, e_dps, s_shp, e_shp);
	array_array_number_t macroDef125 = z_dps;
	array_number_t cur_dps_range = anfvar118_dps;
	storage_t stgVar122 = stgVar117;
	for(int cur_dps_idx = 0; cur_dps_idx < cur_dps_range->length; cur_dps_idx++){
		number_t cur_dps = cur_dps_range->arr[cur_dps_idx];
		
		macroDef125 = f_dps.lam(f_dps.env, stgVar122, macroDef125, (int)(cur_dps), z_shp, 0).array_array_number_t_value;;
	}
	macroDef126 = macroDef125;;
	storage_free(stgVar119, size127);
	return macroDef126;
}

matrix3d_shape_t TOP_LEVEL_linalg_iterateMatrix3D_shp(closure_t f_shp, matrix3d_shape_t z_shp, card_t s_shp, card_t e_shp) {
	
	return z_shp;
}


array_array_array_number_t TOP_LEVEL_linalg_iterateMatrix3D_dps(storage_t stgVar128, closure_t f_dps, array_array_array_number_t z_dps, card_t s_dps, card_t e_dps, closure_t f_shp, matrix3d_shape_t z_shp, card_t s_shp, card_t e_shp) {
	card_t anfvar129_shp = TOP_LEVEL_linalg_vectorRange_shp(s_shp, e_shp);
	card_t size138 = width_card_t(anfvar129_shp);
	array_number_t stgVar130 = storage_alloc(size138);
	array_array_array_number_t macroDef137;array_number_t anfvar129_dps = TOP_LEVEL_linalg_vectorRange_dps(stgVar130, s_dps, e_dps, s_shp, e_shp);
	array_array_array_number_t macroDef136 = z_dps;
	array_number_t cur_dps_range = anfvar129_dps;
	storage_t stgVar133 = stgVar128;
	for(int cur_dps_idx = 0; cur_dps_idx < cur_dps_range->length; cur_dps_idx++){
		number_t cur_dps = cur_dps_range->arr[cur_dps_idx];
		
		macroDef136 = f_dps.lam(f_dps.env, stgVar133, macroDef136, (int)(cur_dps), z_shp, 0).array_array_array_number_t_value;;
	}
	macroDef137 = macroDef136;;
	storage_free(stgVar130, size138);
	return macroDef137;
}

card_t TOP_LEVEL_linalg_vectorSum_shp(card_t v_shp) {
	
	return 0;
}


number_t TOP_LEVEL_linalg_vectorSum_dps(storage_t stgVar139, array_number_t v_dps, card_t v_shp) {
	number_t macroDef141 = 0;
	array_number_t cur_dps_range = v_dps;
	storage_t stgVar140 = stgVar139;
	for(int cur_dps_idx = 0; cur_dps_idx < cur_dps_range->length; cur_dps_idx++){
		number_t cur_dps = cur_dps_range->arr[cur_dps_idx];
		
		macroDef141 = (macroDef141) + (cur_dps);;
	}
	return macroDef141;
}

card_t TOP_LEVEL_linalg_vectorMax_shp(card_t v_shp) {
	
	return 0;
}


number_t TOP_LEVEL_linalg_vectorMax_dps(storage_t stgVar142, array_number_t v_dps, card_t v_shp) {
	number_t macroDef144 = -1000;
	array_number_t cur_dps_range = v_dps;
	storage_t stgVar143 = stgVar142;
	for(int cur_dps_idx = 0; cur_dps_idx < cur_dps_range->length; cur_dps_idx++){
		number_t cur_dps = cur_dps_range->arr[cur_dps_idx];
		number_t ite145 = 0;
	if((macroDef144) > (cur_dps)) {
		
		ite145 = macroDef144;;
	} else {
		
		ite145 = cur_dps;;
	}
		macroDef144 = ite145;;
	}
	return macroDef144;
}
typedef empty_env_t env_t_153;


value_t lambda153(env_t_153* env150, card_t xi_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
card_t TOP_LEVEL_linalg_mult_by_scalar_shp(card_t x_shp, card_t y_shp) {
	env_t_153 env_t_153_value = make_empty_env(); closure_t closure152 = make_closure(lambda153, &env_t_153_value);
	return TOP_LEVEL_linalg_vectorMap_shp(closure152, x_shp);
}

typedef struct env_t_161 {
	number_t y_dps;
} env_t_161;
env_t_161 make_env_t_161(number_t y_dps) {
	env_t_161 env;
	env.y_dps = y_dps;
	return env;
}

value_t lambda161(env_t_161* env155, storage_t stgVar149, number_t xi_dps, card_t xi_shp) {
	number_t y_dps154 = env155->y_dps;
	value_t res;
	res.number_t_value = (xi_dps) * (y_dps154);
	return res;
}
typedef empty_env_t env_t_162;


value_t lambda162(env_t_162* env158, card_t xi_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
array_number_t TOP_LEVEL_linalg_mult_by_scalar_dps(storage_t stgVar146, array_number_t x_dps, number_t y_dps, card_t x_shp, card_t y_shp) {
	env_t_161 env_t_161_value = make_env_t_161(y_dps); closure_t closure157 = make_closure(lambda161, &env_t_161_value);
	env_t_162 env_t_162_value = make_empty_env(); closure_t closure160 = make_closure(lambda162, &env_t_162_value);
	return TOP_LEVEL_linalg_vectorMap_dps(stgVar146, closure157, x_dps, closure160, x_shp);
}
typedef empty_env_t env_t_170;


value_t lambda170(env_t_170* env167, card_t xi_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
card_t TOP_LEVEL_linalg_gaxpy_shp(card_t a_shp, card_t x_shp, card_t y_shp) {
	env_t_170 env_t_170_value = make_empty_env(); closure_t closure169 = make_closure(lambda170, &env_t_170_value);
	return TOP_LEVEL_linalg_vectorMap_shp(closure169, x_shp);
}

typedef struct env_t_179 {
	number_t y_dps;
	number_t a_dps;
} env_t_179;
env_t_179 make_env_t_179(number_t y_dps,number_t a_dps) {
	env_t_179 env;
	env.y_dps = y_dps;
	env.a_dps = a_dps;
	return env;
}

value_t lambda179(env_t_179* env173, storage_t stgVar166, number_t xi_dps, card_t xi_shp) {
	number_t y_dps172 = env173->y_dps;
	number_t a_dps171 = env173->a_dps;
	value_t res;
	res.number_t_value = ((a_dps171) * (xi_dps)) + (y_dps172);
	return res;
}
typedef empty_env_t env_t_180;


value_t lambda180(env_t_180* env176, card_t xi_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
array_number_t TOP_LEVEL_linalg_gaxpy_dps(storage_t stgVar163, number_t a_dps, array_number_t x_dps, number_t y_dps, card_t a_shp, card_t x_shp, card_t y_shp) {
	env_t_179 env_t_179_value = make_env_t_179(y_dps,a_dps); closure_t closure175 = make_closure(lambda179, &env_t_179_value);
	env_t_180 env_t_180_value = make_empty_env(); closure_t closure178 = make_closure(lambda180, &env_t_180_value);
	return TOP_LEVEL_linalg_vectorMap_dps(stgVar163, closure175, x_dps, closure178, x_shp);
}

card_t TOP_LEVEL_linalg_cross_shp(card_t a_shp, card_t b_shp) {
	
	return 3;
}


array_number_t TOP_LEVEL_linalg_cross_dps(storage_t stgVar181, array_number_t a_dps, array_number_t b_dps, card_t a_shp, card_t b_shp) {
	array_number_t macroDef197 = (array_number_t)stgVar181;
	macroDef197->length=3;
	macroDef197->arr=(number_t*)(STG_OFFSET(stgVar181, VECTOR_HEADER_BYTES));
	macroDef197->arr[0] = ((a_dps->arr[1]) * (b_dps->arr[2])) - ((a_dps->arr[2]) * (b_dps->arr[1]));
	macroDef197->arr[1] = ((a_dps->arr[2]) * (b_dps->arr[0])) - ((a_dps->arr[0]) * (b_dps->arr[2]));
	macroDef197->arr[2] = ((a_dps->arr[0]) * (b_dps->arr[1])) - ((a_dps->arr[1]) * (b_dps->arr[0]));;
	return macroDef197;
}
typedef empty_env_t env_t_206;


value_t lambda206(env_t_206* env203, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
card_t TOP_LEVEL_linalg_vectorAdd_shp(card_t x_shp, card_t y_shp) {
	env_t_206 env_t_206_value = make_empty_env(); closure_t closure205 = make_closure(lambda206, &env_t_206_value);
	return TOP_LEVEL_linalg_vectorMap2_shp(closure205, x_shp, y_shp);
}

typedef empty_env_t env_t_213;


value_t lambda213(env_t_213* env207, storage_t stgVar202, number_t x_dps0, number_t y_dps0, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.number_t_value = (x_dps0) + (y_dps0);
	return res;
}
typedef empty_env_t env_t_214;


value_t lambda214(env_t_214* env210, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
array_number_t TOP_LEVEL_linalg_vectorAdd_dps(storage_t stgVar198, array_number_t x_dps, array_number_t y_dps, card_t x_shp, card_t y_shp) {
	env_t_213 env_t_213_value = make_empty_env(); closure_t closure209 = make_closure(lambda213, &env_t_213_value);
	env_t_214 env_t_214_value = make_empty_env(); closure_t closure212 = make_closure(lambda214, &env_t_214_value);
	return TOP_LEVEL_linalg_vectorMap2_dps(stgVar198, closure209, x_dps, y_dps, closure212, x_shp, y_shp);
}
typedef empty_env_t env_t_223;


value_t lambda223(env_t_223* env220, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
card_t TOP_LEVEL_linalg_mult_vec_elementwise_shp(card_t x_shp, card_t y_shp) {
	env_t_223 env_t_223_value = make_empty_env(); closure_t closure222 = make_closure(lambda223, &env_t_223_value);
	return TOP_LEVEL_linalg_vectorMap2_shp(closure222, x_shp, y_shp);
}

typedef empty_env_t env_t_230;


value_t lambda230(env_t_230* env224, storage_t stgVar219, number_t x_dps0, number_t y_dps0, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.number_t_value = (x_dps0) * (y_dps0);
	return res;
}
typedef empty_env_t env_t_231;


value_t lambda231(env_t_231* env227, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
array_number_t TOP_LEVEL_linalg_mult_vec_elementwise_dps(storage_t stgVar215, array_number_t x_dps, array_number_t y_dps, card_t x_shp, card_t y_shp) {
	env_t_230 env_t_230_value = make_empty_env(); closure_t closure226 = make_closure(lambda230, &env_t_230_value);
	env_t_231 env_t_231_value = make_empty_env(); closure_t closure229 = make_closure(lambda231, &env_t_231_value);
	return TOP_LEVEL_linalg_vectorMap2_dps(stgVar215, closure226, x_dps, y_dps, closure229, x_shp, y_shp);
}
typedef empty_env_t env_t_240;


value_t lambda240(env_t_240* env237, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
card_t TOP_LEVEL_linalg_op_DotMultiply_shp(card_t x_shp, card_t y_shp) {
	env_t_240 env_t_240_value = make_empty_env(); closure_t closure239 = make_closure(lambda240, &env_t_240_value);
	return TOP_LEVEL_linalg_vectorMap2_shp(closure239, x_shp, y_shp);
}

typedef empty_env_t env_t_247;


value_t lambda247(env_t_247* env241, storage_t stgVar236, number_t x_dps0, number_t y_dps0, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.number_t_value = (x_dps0) * (y_dps0);
	return res;
}
typedef empty_env_t env_t_248;


value_t lambda248(env_t_248* env244, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
array_number_t TOP_LEVEL_linalg_op_DotMultiply_dps(storage_t stgVar232, array_number_t x_dps, array_number_t y_dps, card_t x_shp, card_t y_shp) {
	env_t_247 env_t_247_value = make_empty_env(); closure_t closure243 = make_closure(lambda247, &env_t_247_value);
	env_t_248 env_t_248_value = make_empty_env(); closure_t closure246 = make_closure(lambda248, &env_t_248_value);
	return TOP_LEVEL_linalg_vectorMap2_dps(stgVar232, closure243, x_dps, y_dps, closure246, x_shp, y_shp);
}

card_t TOP_LEVEL_linalg_vectorAdd3_shp(card_t x_shp, card_t y_shp, card_t z_shp) {
	
	return TOP_LEVEL_linalg_vectorAdd_shp(TOP_LEVEL_linalg_vectorAdd_shp(x_shp, y_shp), z_shp);
}


array_number_t TOP_LEVEL_linalg_vectorAdd3_dps(storage_t stgVar249, array_number_t x_dps, array_number_t y_dps, array_number_t z_dps, card_t x_shp, card_t y_shp, card_t z_shp) {
	card_t size255 = width_card_t(TOP_LEVEL_linalg_vectorAdd_shp(x_shp, y_shp));
	array_number_t stgVar250 = storage_alloc(size255);
	array_number_t macroDef254;
	macroDef254 = TOP_LEVEL_linalg_vectorAdd_dps(stgVar249, TOP_LEVEL_linalg_vectorAdd_dps(stgVar250, x_dps, y_dps, x_shp, y_shp), z_dps, TOP_LEVEL_linalg_vectorAdd_shp(x_shp, y_shp), z_shp);;
	storage_free(stgVar250, size255);
	return macroDef254;
}
typedef empty_env_t env_t_264;


value_t lambda264(env_t_264* env261, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
card_t TOP_LEVEL_linalg_vectorSub_shp(card_t x_shp, card_t y_shp) {
	env_t_264 env_t_264_value = make_empty_env(); closure_t closure263 = make_closure(lambda264, &env_t_264_value);
	return TOP_LEVEL_linalg_vectorMap2_shp(closure263, x_shp, y_shp);
}

typedef empty_env_t env_t_271;


value_t lambda271(env_t_271* env265, storage_t stgVar260, number_t x_dps0, number_t y_dps0, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.number_t_value = (x_dps0) - (y_dps0);
	return res;
}
typedef empty_env_t env_t_272;


value_t lambda272(env_t_272* env268, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
array_number_t TOP_LEVEL_linalg_vectorSub_dps(storage_t stgVar256, array_number_t x_dps, array_number_t y_dps, card_t x_shp, card_t y_shp) {
	env_t_271 env_t_271_value = make_empty_env(); closure_t closure267 = make_closure(lambda271, &env_t_271_value);
	env_t_272 env_t_272_value = make_empty_env(); closure_t closure270 = make_closure(lambda272, &env_t_272_value);
	return TOP_LEVEL_linalg_vectorMap2_dps(stgVar256, closure267, x_dps, y_dps, closure270, x_shp, y_shp);
}
typedef empty_env_t env_t_283;


value_t lambda283(env_t_283* env280, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = TOP_LEVEL_linalg_vectorAdd_shp(x_shp0, y_shp0);
	return res;
}
matrix_shape_t TOP_LEVEL_linalg_matrixAdd_shp(matrix_shape_t x_shp, matrix_shape_t y_shp) {
	env_t_283 env_t_283_value = make_empty_env(); closure_t closure282 = make_closure(lambda283, &env_t_283_value);
	return TOP_LEVEL_linalg_matrixMap2_shp(closure282, x_shp, y_shp);
}

typedef empty_env_t env_t_290;


value_t lambda290(env_t_290* env284, storage_t stgVar277, array_number_t x_dps0, array_number_t y_dps0, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.array_number_t_value = TOP_LEVEL_linalg_vectorAdd_dps(stgVar277, x_dps0, y_dps0, x_shp0, y_shp0);
	return res;
}
typedef empty_env_t env_t_291;


value_t lambda291(env_t_291* env287, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = TOP_LEVEL_linalg_vectorAdd_shp(x_shp0, y_shp0);
	return res;
}
array_array_number_t TOP_LEVEL_linalg_matrixAdd_dps(storage_t stgVar273, array_array_number_t x_dps, array_array_number_t y_dps, matrix_shape_t x_shp, matrix_shape_t y_shp) {
	env_t_290 env_t_290_value = make_empty_env(); closure_t closure286 = make_closure(lambda290, &env_t_290_value);
	env_t_291 env_t_291_value = make_empty_env(); closure_t closure289 = make_closure(lambda291, &env_t_291_value);
	return TOP_LEVEL_linalg_matrixMap2_dps(stgVar273, closure286, x_dps, y_dps, closure289, x_shp, y_shp);
}
typedef empty_env_t env_t_302;


value_t lambda302(env_t_302* env299, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = TOP_LEVEL_linalg_mult_vec_elementwise_shp(x_shp0, y_shp0);
	return res;
}
matrix_shape_t TOP_LEVEL_linalg_matrixMultElementwise_shp(matrix_shape_t x_shp, matrix_shape_t y_shp) {
	env_t_302 env_t_302_value = make_empty_env(); closure_t closure301 = make_closure(lambda302, &env_t_302_value);
	return TOP_LEVEL_linalg_matrixMap2_shp(closure301, x_shp, y_shp);
}

typedef empty_env_t env_t_309;


value_t lambda309(env_t_309* env303, storage_t stgVar296, array_number_t x_dps0, array_number_t y_dps0, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.array_number_t_value = TOP_LEVEL_linalg_mult_vec_elementwise_dps(stgVar296, x_dps0, y_dps0, x_shp0, y_shp0);
	return res;
}
typedef empty_env_t env_t_310;


value_t lambda310(env_t_310* env306, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = TOP_LEVEL_linalg_mult_vec_elementwise_shp(x_shp0, y_shp0);
	return res;
}
array_array_number_t TOP_LEVEL_linalg_matrixMultElementwise_dps(storage_t stgVar292, array_array_number_t x_dps, array_array_number_t y_dps, matrix_shape_t x_shp, matrix_shape_t y_shp) {
	env_t_309 env_t_309_value = make_empty_env(); closure_t closure305 = make_closure(lambda309, &env_t_309_value);
	env_t_310 env_t_310_value = make_empty_env(); closure_t closure308 = make_closure(lambda310, &env_t_310_value);
	return TOP_LEVEL_linalg_matrixMap2_dps(stgVar292, closure305, x_dps, y_dps, closure308, x_shp, y_shp);
}

card_t TOP_LEVEL_linalg_sqnorm_shp(card_t x_shp) {
	
	return 0;
}

typedef empty_env_t env_t_329;


value_t lambda329(env_t_329* env316, card_t x1_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef empty_env_t env_t_330;


value_t lambda330(env_t_330* env319, storage_t stgVar315, number_t x1_dps, card_t x1_shp) {
	
	value_t res;
	res.number_t_value = (x1_dps) * (x1_dps);
	return res;
}
typedef empty_env_t env_t_331;


value_t lambda331(env_t_331* env322, card_t x1_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef empty_env_t env_t_332;


value_t lambda332(env_t_332* env325, card_t x1_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
number_t TOP_LEVEL_linalg_sqnorm_dps(storage_t stgVar311, array_number_t x_dps, card_t x_shp) {
	env_t_329 env_t_329_value = make_empty_env(); closure_t closure318 = make_closure(lambda329, &env_t_329_value);
	card_t size333 = width_card_t(TOP_LEVEL_linalg_vectorMap_shp(closure318, x_shp));
	array_number_t stgVar312 = storage_alloc(size333);
	number_t macroDef328;env_t_330 env_t_330_value = make_empty_env(); closure_t closure321 = make_closure(lambda330, &env_t_330_value);
	env_t_331 env_t_331_value = make_empty_env(); closure_t closure324 = make_closure(lambda331, &env_t_331_value);
	env_t_332 env_t_332_value = make_empty_env(); closure_t closure327 = make_closure(lambda332, &env_t_332_value);
	macroDef328 = TOP_LEVEL_linalg_vectorSum_dps(stgVar311, TOP_LEVEL_linalg_vectorMap_dps(stgVar312, closure321, x_dps, closure324, x_shp), TOP_LEVEL_linalg_vectorMap_shp(closure327, x_shp));;
	storage_free(stgVar312, size333);
	return macroDef328;
}

card_t TOP_LEVEL_linalg_dot_prod_shp(card_t x_shp, card_t y_shp) {
	
	return 0;
}

typedef empty_env_t env_t_353;


value_t lambda353(env_t_353* env340, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef empty_env_t env_t_354;


value_t lambda354(env_t_354* env343, storage_t stgVar339, number_t x_dps0, number_t y_dps0, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.number_t_value = (x_dps0) * (y_dps0);
	return res;
}
typedef empty_env_t env_t_355;


value_t lambda355(env_t_355* env346, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef empty_env_t env_t_356;


value_t lambda356(env_t_356* env349, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
number_t TOP_LEVEL_linalg_dot_prod_dps(storage_t stgVar334, array_number_t x_dps, array_number_t y_dps, card_t x_shp, card_t y_shp) {
	env_t_353 env_t_353_value = make_empty_env(); closure_t closure342 = make_closure(lambda353, &env_t_353_value);
	card_t size357 = width_card_t(TOP_LEVEL_linalg_vectorMap2_shp(closure342, x_shp, y_shp));
	array_number_t stgVar335 = storage_alloc(size357);
	number_t macroDef352;env_t_354 env_t_354_value = make_empty_env(); closure_t closure345 = make_closure(lambda354, &env_t_354_value);
	env_t_355 env_t_355_value = make_empty_env(); closure_t closure348 = make_closure(lambda355, &env_t_355_value);
	env_t_356 env_t_356_value = make_empty_env(); closure_t closure351 = make_closure(lambda356, &env_t_356_value);
	macroDef352 = TOP_LEVEL_linalg_vectorSum_dps(stgVar334, TOP_LEVEL_linalg_vectorMap2_dps(stgVar335, closure345, x_dps, y_dps, closure348, x_shp, y_shp), TOP_LEVEL_linalg_vectorMap2_shp(closure351, x_shp, y_shp));;
	storage_free(stgVar335, size357);
	return macroDef352;
}
typedef struct env_t_368 {
	card_t row_shp;
} env_t_368;
env_t_368 make_env_t_368(card_t row_shp) {
	env_t_368 env;
	env.row_shp = row_shp;
	return env;
}

value_t lambda368(env_t_368* env365, card_t r_shp) {
	card_t row_shp364 = env365->row_shp;
	value_t res;
	res.card_t_value = row_shp364;
	return res;
}
matrix_shape_t TOP_LEVEL_linalg_matrixFillFromVector_shp(card_t rows_shp, card_t row_shp) {
	env_t_368 env_t_368_value = make_env_t_368(row_shp); closure_t closure367 = make_closure(lambda368, &env_t_368_value);
	return TOP_LEVEL_linalg_vectorMapToMatrix_shp(closure367, TOP_LEVEL_linalg_vectorRange_shp(1, rows_shp));
}

typedef struct env_t_378 {
	array_number_t row_dps;
} env_t_378;
env_t_378 make_env_t_378(array_number_t row_dps) {
	env_t_378 env;
	env.row_dps = row_dps;
	return env;
}

value_t lambda378(env_t_378* env370, storage_t stgVar361, number_t r_dps, card_t r_shp) {
	array_number_t row_dps369 = env370->row_dps;
	value_t res;
	res.array_number_t_value = row_dps369;
	return res;
}
typedef struct env_t_379 {
	card_t row_shp;
} env_t_379;
env_t_379 make_env_t_379(card_t row_shp) {
	env_t_379 env;
	env.row_shp = row_shp;
	return env;
}

value_t lambda379(env_t_379* env374, card_t r_shp) {
	card_t row_shp373 = env374->row_shp;
	value_t res;
	res.card_t_value = row_shp373;
	return res;
}
array_array_number_t TOP_LEVEL_linalg_matrixFillFromVector_dps(storage_t stgVar358, card_t rows_dps, array_number_t row_dps, card_t rows_shp, card_t row_shp) {
	card_t size380 = width_card_t(TOP_LEVEL_linalg_vectorRange_shp(1, rows_shp));
	array_number_t stgVar360 = storage_alloc(size380);
	array_array_number_t macroDef377;env_t_378 env_t_378_value = make_env_t_378(row_dps); closure_t closure372 = make_closure(lambda378, &env_t_378_value);
	env_t_379 env_t_379_value = make_env_t_379(row_shp); closure_t closure376 = make_closure(lambda379, &env_t_379_value);
	macroDef377 = TOP_LEVEL_linalg_vectorMapToMatrix_dps(stgVar358, closure372, TOP_LEVEL_linalg_vectorRange_dps(stgVar360, 1, rows_dps, 1, rows_shp), closure376, TOP_LEVEL_linalg_vectorRange_shp(1, rows_shp));;
	storage_free(stgVar360, size380);
	return macroDef377;
}

matrix_shape_t TOP_LEVEL_linalg_matrixFill_shp(card_t rows_shp, card_t cols_shp, card_t value_shp) {
	
	return nested_shape_card_t(cols_shp, rows_shp);
}


array_array_number_t TOP_LEVEL_linalg_matrixFill_dps(storage_t stgVar381, card_t rows_dps, card_t cols_dps, number_t value_dps, card_t rows_shp, card_t cols_shp, card_t value_shp) {
	array_array_number_t macroDef385 = (array_array_number_t)stgVar381;
		macroDef385->length=rows_dps;
		macroDef385->arr=(array_number_t*)(STG_OFFSET(macroDef385, VECTOR_HEADER_BYTES));
		storage_t stgVar382 = (STG_OFFSET(macroDef385, MATRIX_HEADER_BYTES(rows_dps)));
		for(int r_dps = 0; r_dps < macroDef385->length; r_dps++){
			array_number_t macroDef384 = (array_number_t)stgVar382;
		macroDef384->length=cols_dps;
		macroDef384->arr=(number_t*)(STG_OFFSET(macroDef384, VECTOR_HEADER_BYTES));
		storage_t stgVar383 = macroDef384;
		for(int c_dps = 0; c_dps < macroDef384->length; c_dps++){
			
			macroDef384->arr[c_dps] = value_dps;;
			stgVar383 = STG_OFFSET(stgVar383, sizeof(number_t));
		}
			macroDef385->arr[r_dps] = macroDef384;;
			stgVar382 = STG_OFFSET(stgVar382, VECTOR_ALL_BYTES(macroDef385->arr[r_dps]->length));
		}
	return macroDef385;
}

matrix_shape_t TOP_LEVEL_linalg_matrixTranspose_shp(matrix_shape_t m_shp) {
	
	return nested_shape_card_t(m_shp.card, m_shp.elem);
}


array_array_number_t TOP_LEVEL_linalg_matrixTranspose_dps(storage_t stgVar386, array_array_number_t m_dps, matrix_shape_t m_shp) {
	card_t rows_shp = m_shp.card;
	card_t macroDef398 = m_dps->length;
	card_t rows_dps = macroDef398;
	card_t cols_shp = m_shp.elem;
	card_t size404 = width_card_t(m_shp.elem);
	array_number_t stgVar390 = storage_alloc(size404);
	card_t macroDef400;card_t macroDef399 = m_dps->arr[0]->length;
	macroDef400 = macroDef399;;
	storage_free(stgVar390, size404);
	card_t cols_dps = macroDef400;
	array_array_number_t macroDef403 = (array_array_number_t)stgVar386;
		macroDef403->length=cols_dps;
		macroDef403->arr=(array_number_t*)(STG_OFFSET(macroDef403, VECTOR_HEADER_BYTES));
		storage_t stgVar392 = (STG_OFFSET(macroDef403, MATRIX_HEADER_BYTES(cols_dps)));
		for(int i_dps = 0; i_dps < macroDef403->length; i_dps++){
			array_number_t macroDef402 = (array_number_t)stgVar392;
		macroDef402->length=rows_dps;
		macroDef402->arr=(number_t*)(STG_OFFSET(macroDef402, VECTOR_HEADER_BYTES));
		storage_t stgVar393 = macroDef402;
		for(int j_dps = 0; j_dps < macroDef402->length; j_dps++){
			card_t size405 = width_card_t(m_shp.elem);
	array_number_t stgVar394 = storage_alloc(size405);
	number_t macroDef401;
	macroDef401 = m_dps->arr[j_dps]->arr[i_dps];;
	storage_free(stgVar394, size405);
			macroDef402->arr[j_dps] = macroDef401;;
			stgVar393 = STG_OFFSET(stgVar393, sizeof(number_t));
		}
			macroDef403->arr[i_dps] = macroDef402;;
			stgVar392 = STG_OFFSET(stgVar392, VECTOR_ALL_BYTES(macroDef403->arr[i_dps]->length));
		}
	return macroDef403;
}

matrix_shape_t TOP_LEVEL_linalg_matrixMult_shp(matrix_shape_t m1_shp, matrix_shape_t m2_shp) {
	
	return nested_shape_card_t(m2_shp.elem, m1_shp.card);
}


array_array_number_t TOP_LEVEL_linalg_matrixMult_dps(storage_t stgVar406, array_array_number_t m1_dps, array_array_number_t m2_dps, matrix_shape_t m1_shp, matrix_shape_t m2_shp) {
	card_t r1_shp = m1_shp.card;
	card_t macroDef445 = m1_dps->length;
	card_t r1_dps = macroDef445;
	card_t c2_shp = m2_shp.elem;
	card_t size456 = width_card_t(m2_shp.elem);
	array_number_t stgVar410 = storage_alloc(size456);
	card_t macroDef447;card_t macroDef446 = m2_dps->arr[0]->length;
	macroDef447 = macroDef446;;
	storage_free(stgVar410, size456);
	card_t c2_dps = macroDef447;
	card_t c1_shp = m1_shp.elem;
	card_t size457 = width_card_t(m1_shp.elem);
	array_number_t stgVar413 = storage_alloc(size457);
	card_t macroDef449;card_t macroDef448 = m1_dps->arr[0]->length;
	macroDef449 = macroDef448;;
	storage_free(stgVar413, size457);
	card_t c1_dps = macroDef449;
	card_t r2_shp = m2_shp.card;
	card_t macroDef450 = m2_dps->length;
	card_t r2_dps = macroDef450;
	matrix_shape_t m2T_shp = TOP_LEVEL_linalg_matrixTranspose_shp(m2_shp);
	card_t size460 = width_matrix_shape_t(m2T_shp);
	array_number_t stgVar417 = storage_alloc(size460);
	array_array_number_t macroDef455;array_array_number_t m2T_dps = TOP_LEVEL_linalg_matrixTranspose_dps(stgVar417, m2_dps, m2_shp);
	array_array_number_t macroDef454 = (array_array_number_t)stgVar406;
		macroDef454->length=r1_dps;
		macroDef454->arr=(array_number_t*)(STG_OFFSET(macroDef454, VECTOR_HEADER_BYTES));
		storage_t stgVar419 = (STG_OFFSET(macroDef454, MATRIX_HEADER_BYTES(r1_dps)));
		for(int r_dps = 0; r_dps < macroDef454->length; r_dps++){
			array_number_t macroDef453 = (array_number_t)stgVar419;
		macroDef453->length=c2_dps;
		macroDef453->arr=(number_t*)(STG_OFFSET(macroDef453, VECTOR_HEADER_BYTES));
		storage_t stgVar420 = macroDef453;
		for(int c_dps = 0; c_dps < macroDef453->length; c_dps++){
			card_t size459 = width_card_t(m2T_shp.elem);
	array_number_t stgVar422 = storage_alloc(size459);
	number_t macroDef452;card_t size458 = width_card_t(m1_shp.elem);
	array_number_t stgVar421 = storage_alloc(size458);
	number_t macroDef451;
	macroDef451 = TOP_LEVEL_linalg_dot_prod_dps(stgVar420, m1_dps->arr[r_dps], m2T_dps->arr[c_dps], m1_shp.elem, m2T_shp.elem);;
	storage_free(stgVar421, size458);
	macroDef452 = macroDef451;;
	storage_free(stgVar422, size459);
			macroDef453->arr[c_dps] = macroDef452;;
			stgVar420 = STG_OFFSET(stgVar420, sizeof(number_t));
		}
			macroDef454->arr[r_dps] = macroDef453;;
			stgVar419 = STG_OFFSET(stgVar419, VECTOR_ALL_BYTES(macroDef454->arr[r_dps]->length));
		}
	macroDef455 = macroDef454;;
	storage_free(stgVar417, size460);
	return macroDef455;
}

card_t TOP_LEVEL_linalg_matrixVectorMult_shp(matrix_shape_t m_shp, card_t v_shp) {
	
	return TOP_LEVEL_linalg_rows_shp(m_shp);
}


array_number_t TOP_LEVEL_linalg_matrixVectorMult_dps(storage_t stgVar461, array_array_number_t m_dps, array_number_t v_dps, matrix_shape_t m_shp, card_t v_shp) {
	card_t r_shp = TOP_LEVEL_linalg_rows_shp(m_shp);
	card_t size478 = width_card_t(r_shp);
	array_number_t stgVar462 = storage_alloc(size478);
	array_number_t macroDef475;card_t r_dps = TOP_LEVEL_linalg_rows_dps(stgVar462, m_dps, m_shp);
	card_t c_shp = TOP_LEVEL_linalg_cols_shp(m_shp);
	card_t size477 = width_card_t(c_shp);
	array_number_t stgVar464 = storage_alloc(size477);
	array_number_t macroDef474;card_t c_dps = TOP_LEVEL_linalg_cols_dps(stgVar464, m_dps, m_shp);
	array_number_t macroDef473 = (array_number_t)stgVar461;
		macroDef473->length=r_dps;
		macroDef473->arr=(number_t*)(STG_OFFSET(macroDef473, VECTOR_HEADER_BYTES));
		storage_t stgVar466 = macroDef473;
		for(int i_dps = 0; i_dps < macroDef473->length; i_dps++){
			card_t size476 = width_card_t(m_shp.elem);
	array_number_t stgVar467 = storage_alloc(size476);
	number_t macroDef472;
	macroDef472 = TOP_LEVEL_linalg_dot_prod_dps(stgVar466, m_dps->arr[i_dps], v_dps, m_shp.elem, v_shp);;
	storage_free(stgVar467, size476);
			macroDef473->arr[i_dps] = macroDef472;;
			stgVar466 = STG_OFFSET(stgVar466, sizeof(number_t));
		}
	macroDef474 = macroDef473;;
	storage_free(stgVar464, size477);
	macroDef475 = macroDef474;;
	storage_free(stgVar462, size478);
	return macroDef475;
}

matrix_shape_t TOP_LEVEL_linalg_matrixConcat_shp(matrix_shape_t m1_shp, matrix_shape_t m2_shp) {
	
	return nested_shape_card_t(m1_shp.elem, (m1_shp.card) + (m2_shp.card));
}


array_array_number_t TOP_LEVEL_linalg_matrixConcat_dps(storage_t stgVar479, array_array_number_t m1_dps, array_array_number_t m2_dps, matrix_shape_t m1_shp, matrix_shape_t m2_shp) {
	card_t rows_shp = (m1_shp.card) + (m2_shp.card);
	card_t macroDef490 = m1_dps->length;
	card_t macroDef491 = m2_dps->length;
	card_t rows_dps = (macroDef490) + (macroDef491);
	card_t m1Rows_shp = 0;
	card_t macroDef492 = m1_dps->length;
	index_t m1Rows_dps = (macroDef492);
	array_array_number_t macroDef493 = (array_array_number_t)stgVar479;
		macroDef493->length=rows_dps;
		macroDef493->arr=(array_number_t*)(STG_OFFSET(macroDef493, VECTOR_HEADER_BYTES));
		storage_t stgVar485 = (STG_OFFSET(macroDef493, MATRIX_HEADER_BYTES(rows_dps)));
		for(int r_dps = 0; r_dps < macroDef493->length; r_dps++){
			array_number_t ite494 = 0;
	if((r_dps) < (m1Rows_dps)) {
		
		ite494 = m1_dps->arr[r_dps];;
	} else {
		
		ite494 = m2_dps->arr[(r_dps) - (m1Rows_dps)];;
	}
			macroDef493->arr[r_dps] = ite494;;
			stgVar485 = STG_OFFSET(stgVar485, VECTOR_ALL_BYTES(macroDef493->arr[r_dps]->length));
		}
	return macroDef493;
}

matrix_shape_t TOP_LEVEL_linalg_matrixConcatCol_shp(matrix_shape_t m1_shp, matrix_shape_t m2_shp) {
	
	return TOP_LEVEL_linalg_matrixTranspose_shp(TOP_LEVEL_linalg_matrixConcat_shp(TOP_LEVEL_linalg_matrixTranspose_shp(m1_shp), TOP_LEVEL_linalg_matrixTranspose_shp(m2_shp)));
}


array_array_number_t TOP_LEVEL_linalg_matrixConcatCol_dps(storage_t stgVar495, array_array_number_t m1_dps, array_array_number_t m2_dps, matrix_shape_t m1_shp, matrix_shape_t m2_shp) {
	matrix_shape_t m1t_shp = TOP_LEVEL_linalg_matrixTranspose_shp(m1_shp);
	card_t size510 = width_matrix_shape_t(m1t_shp);
	array_number_t stgVar496 = storage_alloc(size510);
	array_array_number_t macroDef507;array_array_number_t m1t_dps = TOP_LEVEL_linalg_matrixTranspose_dps(stgVar496, m1_dps, m1_shp);
	matrix_shape_t m2t_shp = TOP_LEVEL_linalg_matrixTranspose_shp(m2_shp);
	card_t size509 = width_matrix_shape_t(m2t_shp);
	array_number_t stgVar498 = storage_alloc(size509);
	array_array_number_t macroDef506;array_array_number_t m2t_dps = TOP_LEVEL_linalg_matrixTranspose_dps(stgVar498, m2_dps, m2_shp);
	card_t size508 = width_matrix_shape_t(TOP_LEVEL_linalg_matrixConcat_shp(m1t_shp, m2t_shp));
	array_number_t stgVar500 = storage_alloc(size508);
	array_array_number_t macroDef505;
	macroDef505 = TOP_LEVEL_linalg_matrixTranspose_dps(stgVar495, TOP_LEVEL_linalg_matrixConcat_dps(stgVar500, m1t_dps, m2t_dps, m1t_shp, m2t_shp), TOP_LEVEL_linalg_matrixConcat_shp(m1t_shp, m2t_shp));;
	storage_free(stgVar500, size508);
	macroDef506 = macroDef505;;
	storage_free(stgVar498, size509);
	macroDef507 = macroDef506;;
	storage_free(stgVar496, size510);
	return macroDef507;
}

matrix3d_shape_t TOP_LEVEL_linalg_matrix3DConcat_shp(matrix3d_shape_t m1_shp, matrix3d_shape_t m2_shp) {
	
	return nested_shape_matrix_shape_t(m1_shp.elem, (m1_shp.card) + (m2_shp.card));
}


array_array_array_number_t TOP_LEVEL_linalg_matrix3DConcat_dps(storage_t stgVar511, array_array_array_number_t m1_dps, array_array_array_number_t m2_dps, matrix3d_shape_t m1_shp, matrix3d_shape_t m2_shp) {
	card_t rows_shp = (m1_shp.card) + (m2_shp.card);
	card_t macroDef522 = m1_dps->length;
	card_t macroDef523 = m2_dps->length;
	card_t rows_dps = (macroDef522) + (macroDef523);
	card_t m1Rows_shp = 0;
	card_t macroDef524 = m1_dps->length;
	index_t m1Rows_dps = (macroDef524);
	array_array_array_number_t macroDef525 = (array_array_array_number_t)stgVar511;
		macroDef525->length=rows_dps;
		macroDef525->arr=(array_array_number_t*)(STG_OFFSET(macroDef525, VECTOR_HEADER_BYTES));
		storage_t stgVar517 = (STG_OFFSET(macroDef525, MATRIX_HEADER_BYTES(rows_dps)));
		for(int r_dps = 0; r_dps < macroDef525->length; r_dps++){
			array_array_number_t ite526 = 0;
	if((r_dps) < (m1Rows_dps)) {
		
		ite526 = m1_dps->arr[r_dps];;
	} else {
		
		ite526 = m2_dps->arr[(r_dps) - (m1Rows_dps)];;
	}
			macroDef525->arr[r_dps] = ite526;;
			stgVar517 = STG_OFFSET(stgVar517, VECTOR_ALL_BYTES(macroDef525->arr[r_dps]->length));
		}
	return macroDef525;
}

card_t TOP_LEVEL_linalg_vectorRead_shp(card_t fn_shp, card_t startLine_shp, card_t cols_shp) {
	
	return nested_shape_card_t(cols_shp, 1).elem;
}


array_number_t TOP_LEVEL_linalg_vectorRead_dps(storage_t stgVar527, string_t fn_dps, index_t startLine_dps, card_t cols_dps, card_t fn_shp, card_t startLine_shp, card_t cols_shp) {
	matrix_shape_t matrix_shp = nested_shape_card_t(cols_shp, 1);
	card_t size531 = width_matrix_shape_t(matrix_shp);
	array_number_t stgVar528 = storage_alloc(size531);
	array_number_t macroDef530;array_array_number_t matrix_dps = matrix_read_s(stgVar528, fn_dps, startLine_dps, 1, cols_dps);
	macroDef530 = matrix_dps->arr[0];;
	storage_free(stgVar528, size531);
	return macroDef530;
}

card_t TOP_LEVEL_linalg_numberRead_shp(card_t fn_shp, card_t startLine_shp) {
	
	return 0;
}


number_t TOP_LEVEL_linalg_numberRead_dps(storage_t stgVar532, string_t fn_dps, index_t startLine_dps, card_t fn_shp, card_t startLine_shp) {
	card_t vector_shp = TOP_LEVEL_linalg_vectorRead_shp(0, 0, 1);
	card_t size539 = width_card_t(vector_shp);
	array_number_t stgVar533 = storage_alloc(size539);
	number_t macroDef538;array_number_t vector_dps = TOP_LEVEL_linalg_vectorRead_dps(stgVar533, fn_dps, startLine_dps, 1, 0, 0, 1);
	macroDef538 = vector_dps->arr[0];;
	storage_free(stgVar533, size539);
	return macroDef538;
}

card_t TOP_LEVEL_linalg_vec3_shp(card_t a_shp, card_t b_shp, card_t c_shp) {
	
	return 3;
}


array_number_t TOP_LEVEL_linalg_vec3_dps(storage_t stgVar540, number_t a_dps, number_t b_dps, number_t c_dps, card_t a_shp, card_t b_shp, card_t c_shp) {
	array_number_t macroDef544 = (array_number_t)stgVar540;
	macroDef544->length=3;
	macroDef544->arr=(number_t*)(STG_OFFSET(stgVar540, VECTOR_HEADER_BYTES));
	macroDef544->arr[0] = a_dps;
	macroDef544->arr[1] = b_dps;
	macroDef544->arr[2] = c_dps;;
	return macroDef544;
}
#endif
