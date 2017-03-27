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

card_t TOP_LEVEL_linalg_vectorSum_shp(card_t v_shp) {
	
	return 0;
}


number_t TOP_LEVEL_linalg_vectorSum_dps(storage_t stgVar95, array_number_t v_dps, card_t v_shp) {
	number_t macroDef97 = 0;
	array_number_t cur_dps_range = v_dps;
	storage_t stgVar96 = stgVar95;
	for(int cur_dps_idx = 0; cur_dps_idx < cur_dps_range->length; cur_dps_idx++){
		number_t cur_dps = cur_dps_range->arr[cur_dps_idx];
		
		macroDef97 = (macroDef97) + (cur_dps);;
	}
	return macroDef97;
}

card_t TOP_LEVEL_linalg_vectorMax_shp(card_t v_shp) {
	
	return 0;
}


number_t TOP_LEVEL_linalg_vectorMax_dps(storage_t stgVar98, array_number_t v_dps, card_t v_shp) {
	number_t macroDef100 = -1000;
	array_number_t cur_dps_range = v_dps;
	storage_t stgVar99 = stgVar98;
	for(int cur_dps_idx = 0; cur_dps_idx < cur_dps_range->length; cur_dps_idx++){
		number_t cur_dps = cur_dps_range->arr[cur_dps_idx];
		number_t ite101 = 0;
	if((macroDef100) > (cur_dps)) {
		
		ite101 = macroDef100;;
	} else {
		
		ite101 = cur_dps;;
	}
		macroDef100 = ite101;;
	}
	return macroDef100;
}
typedef empty_env_t env_t_109;


value_t lambda109(env_t_109* env106, card_t xi_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
card_t TOP_LEVEL_linalg_mult_by_scalar_shp(card_t x_shp, card_t y_shp) {
	env_t_109 env_t_109_value = make_empty_env(); closure_t closure108 = make_closure(lambda109, &env_t_109_value);
	return TOP_LEVEL_linalg_vectorMap_shp(closure108, x_shp);
}

typedef struct env_t_117 {
	number_t y_dps;
} env_t_117;
env_t_117 make_env_t_117(number_t y_dps) {
	env_t_117 env;
	env.y_dps = y_dps;
	return env;
}

value_t lambda117(env_t_117* env111, storage_t stgVar105, number_t xi_dps, card_t xi_shp) {
	number_t y_dps110 = env111->y_dps;
	value_t res;
	res.number_t_value = (xi_dps) * (y_dps110);
	return res;
}
typedef empty_env_t env_t_118;


value_t lambda118(env_t_118* env114, card_t xi_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
array_number_t TOP_LEVEL_linalg_mult_by_scalar_dps(storage_t stgVar102, array_number_t x_dps, number_t y_dps, card_t x_shp, card_t y_shp) {
	env_t_117 env_t_117_value = make_env_t_117(y_dps); closure_t closure113 = make_closure(lambda117, &env_t_117_value);
	env_t_118 env_t_118_value = make_empty_env(); closure_t closure116 = make_closure(lambda118, &env_t_118_value);
	return TOP_LEVEL_linalg_vectorMap_dps(stgVar102, closure113, x_dps, closure116, x_shp);
}
typedef empty_env_t env_t_126;


value_t lambda126(env_t_126* env123, card_t xi_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
card_t TOP_LEVEL_linalg_gaxpy_shp(card_t a_shp, card_t x_shp, card_t y_shp) {
	env_t_126 env_t_126_value = make_empty_env(); closure_t closure125 = make_closure(lambda126, &env_t_126_value);
	return TOP_LEVEL_linalg_vectorMap_shp(closure125, x_shp);
}

typedef struct env_t_135 {
	number_t y_dps;
	number_t a_dps;
} env_t_135;
env_t_135 make_env_t_135(number_t y_dps,number_t a_dps) {
	env_t_135 env;
	env.y_dps = y_dps;
	env.a_dps = a_dps;
	return env;
}

value_t lambda135(env_t_135* env129, storage_t stgVar122, number_t xi_dps, card_t xi_shp) {
	number_t y_dps128 = env129->y_dps;
	number_t a_dps127 = env129->a_dps;
	value_t res;
	res.number_t_value = ((a_dps127) * (xi_dps)) + (y_dps128);
	return res;
}
typedef empty_env_t env_t_136;


value_t lambda136(env_t_136* env132, card_t xi_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
array_number_t TOP_LEVEL_linalg_gaxpy_dps(storage_t stgVar119, number_t a_dps, array_number_t x_dps, number_t y_dps, card_t a_shp, card_t x_shp, card_t y_shp) {
	env_t_135 env_t_135_value = make_env_t_135(y_dps,a_dps); closure_t closure131 = make_closure(lambda135, &env_t_135_value);
	env_t_136 env_t_136_value = make_empty_env(); closure_t closure134 = make_closure(lambda136, &env_t_136_value);
	return TOP_LEVEL_linalg_vectorMap_dps(stgVar119, closure131, x_dps, closure134, x_shp);
}

card_t TOP_LEVEL_linalg_cross_shp(card_t a_shp, card_t b_shp) {
	
	return 3;
}


array_number_t TOP_LEVEL_linalg_cross_dps(storage_t stgVar137, array_number_t a_dps, array_number_t b_dps, card_t a_shp, card_t b_shp) {
	array_number_t macroDef153 = (array_number_t)stgVar137;
	macroDef153->length=3;
	macroDef153->arr=(number_t*)(STG_OFFSET(stgVar137, VECTOR_HEADER_BYTES));
	

	macroDef153->arr[0] = ((a_dps->arr[1]) * (b_dps->arr[2])) - ((a_dps->arr[2]) * (b_dps->arr[1]));;

	macroDef153->arr[1] = ((a_dps->arr[2]) * (b_dps->arr[0])) - ((a_dps->arr[0]) * (b_dps->arr[2]));;

	macroDef153->arr[2] = ((a_dps->arr[0]) * (b_dps->arr[1])) - ((a_dps->arr[1]) * (b_dps->arr[0]));;;
	return macroDef153;
}
typedef empty_env_t env_t_162;


value_t lambda162(env_t_162* env159, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
card_t TOP_LEVEL_linalg_vectorAdd_shp(card_t x_shp, card_t y_shp) {
	env_t_162 env_t_162_value = make_empty_env(); closure_t closure161 = make_closure(lambda162, &env_t_162_value);
	return TOP_LEVEL_linalg_vectorMap2_shp(closure161, x_shp, y_shp);
}

typedef empty_env_t env_t_169;


value_t lambda169(env_t_169* env163, storage_t stgVar158, number_t x_dps0, number_t y_dps0, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.number_t_value = (x_dps0) + (y_dps0);
	return res;
}
typedef empty_env_t env_t_170;


value_t lambda170(env_t_170* env166, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
array_number_t TOP_LEVEL_linalg_vectorAdd_dps(storage_t stgVar154, array_number_t x_dps, array_number_t y_dps, card_t x_shp, card_t y_shp) {
	env_t_169 env_t_169_value = make_empty_env(); closure_t closure165 = make_closure(lambda169, &env_t_169_value);
	env_t_170 env_t_170_value = make_empty_env(); closure_t closure168 = make_closure(lambda170, &env_t_170_value);
	return TOP_LEVEL_linalg_vectorMap2_dps(stgVar154, closure165, x_dps, y_dps, closure168, x_shp, y_shp);
}
typedef empty_env_t env_t_179;


value_t lambda179(env_t_179* env176, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
card_t TOP_LEVEL_linalg_mult_vec_elementwise_shp(card_t x_shp, card_t y_shp) {
	env_t_179 env_t_179_value = make_empty_env(); closure_t closure178 = make_closure(lambda179, &env_t_179_value);
	return TOP_LEVEL_linalg_vectorMap2_shp(closure178, x_shp, y_shp);
}

typedef empty_env_t env_t_186;


value_t lambda186(env_t_186* env180, storage_t stgVar175, number_t x_dps0, number_t y_dps0, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.number_t_value = (x_dps0) * (y_dps0);
	return res;
}
typedef empty_env_t env_t_187;


value_t lambda187(env_t_187* env183, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
array_number_t TOP_LEVEL_linalg_mult_vec_elementwise_dps(storage_t stgVar171, array_number_t x_dps, array_number_t y_dps, card_t x_shp, card_t y_shp) {
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
card_t TOP_LEVEL_linalg_op_DotMultiply_shp(card_t x_shp, card_t y_shp) {
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
array_number_t TOP_LEVEL_linalg_op_DotMultiply_dps(storage_t stgVar188, array_number_t x_dps, array_number_t y_dps, card_t x_shp, card_t y_shp) {
	env_t_203 env_t_203_value = make_empty_env(); closure_t closure199 = make_closure(lambda203, &env_t_203_value);
	env_t_204 env_t_204_value = make_empty_env(); closure_t closure202 = make_closure(lambda204, &env_t_204_value);
	return TOP_LEVEL_linalg_vectorMap2_dps(stgVar188, closure199, x_dps, y_dps, closure202, x_shp, y_shp);
}

card_t TOP_LEVEL_linalg_vectorAdd3_shp(card_t x_shp, card_t y_shp, card_t z_shp) {
	
	return TOP_LEVEL_linalg_vectorAdd_shp(TOP_LEVEL_linalg_vectorAdd_shp(x_shp, y_shp), z_shp);
}


array_number_t TOP_LEVEL_linalg_vectorAdd3_dps(storage_t stgVar205, array_number_t x_dps, array_number_t y_dps, array_number_t z_dps, card_t x_shp, card_t y_shp, card_t z_shp) {
	card_t size211 = width_card_t(TOP_LEVEL_linalg_vectorAdd_shp(x_shp, y_shp));
	array_number_t stgVar206 = storage_alloc(size211);
	array_number_t macroDef210;
	macroDef210 = TOP_LEVEL_linalg_vectorAdd_dps(stgVar205, TOP_LEVEL_linalg_vectorAdd_dps(stgVar206, x_dps, y_dps, x_shp, y_shp), z_dps, TOP_LEVEL_linalg_vectorAdd_shp(x_shp, y_shp), z_shp);;
	storage_free(stgVar206, size211);
	return macroDef210;
}
typedef empty_env_t env_t_220;


value_t lambda220(env_t_220* env217, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
card_t TOP_LEVEL_linalg_vectorSub_shp(card_t x_shp, card_t y_shp) {
	env_t_220 env_t_220_value = make_empty_env(); closure_t closure219 = make_closure(lambda220, &env_t_220_value);
	return TOP_LEVEL_linalg_vectorMap2_shp(closure219, x_shp, y_shp);
}

typedef empty_env_t env_t_227;


value_t lambda227(env_t_227* env221, storage_t stgVar216, number_t x_dps0, number_t y_dps0, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.number_t_value = (x_dps0) - (y_dps0);
	return res;
}
typedef empty_env_t env_t_228;


value_t lambda228(env_t_228* env224, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
array_number_t TOP_LEVEL_linalg_vectorSub_dps(storage_t stgVar212, array_number_t x_dps, array_number_t y_dps, card_t x_shp, card_t y_shp) {
	env_t_227 env_t_227_value = make_empty_env(); closure_t closure223 = make_closure(lambda227, &env_t_227_value);
	env_t_228 env_t_228_value = make_empty_env(); closure_t closure226 = make_closure(lambda228, &env_t_228_value);
	return TOP_LEVEL_linalg_vectorMap2_dps(stgVar212, closure223, x_dps, y_dps, closure226, x_shp, y_shp);
}
typedef empty_env_t env_t_239;


value_t lambda239(env_t_239* env236, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = TOP_LEVEL_linalg_vectorAdd_shp(x_shp0, y_shp0);
	return res;
}
matrix_shape_t TOP_LEVEL_linalg_matrixAdd_shp(matrix_shape_t x_shp, matrix_shape_t y_shp) {
	env_t_239 env_t_239_value = make_empty_env(); closure_t closure238 = make_closure(lambda239, &env_t_239_value);
	return TOP_LEVEL_linalg_matrixMap2_shp(closure238, x_shp, y_shp);
}

typedef empty_env_t env_t_246;


value_t lambda246(env_t_246* env240, storage_t stgVar233, array_number_t x_dps0, array_number_t y_dps0, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.array_number_t_value = TOP_LEVEL_linalg_vectorAdd_dps(stgVar233, x_dps0, y_dps0, x_shp0, y_shp0);
	return res;
}
typedef empty_env_t env_t_247;


value_t lambda247(env_t_247* env243, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = TOP_LEVEL_linalg_vectorAdd_shp(x_shp0, y_shp0);
	return res;
}
array_array_number_t TOP_LEVEL_linalg_matrixAdd_dps(storage_t stgVar229, array_array_number_t x_dps, array_array_number_t y_dps, matrix_shape_t x_shp, matrix_shape_t y_shp) {
	env_t_246 env_t_246_value = make_empty_env(); closure_t closure242 = make_closure(lambda246, &env_t_246_value);
	env_t_247 env_t_247_value = make_empty_env(); closure_t closure245 = make_closure(lambda247, &env_t_247_value);
	return TOP_LEVEL_linalg_matrixMap2_dps(stgVar229, closure242, x_dps, y_dps, closure245, x_shp, y_shp);
}
typedef empty_env_t env_t_258;


value_t lambda258(env_t_258* env255, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = TOP_LEVEL_linalg_mult_vec_elementwise_shp(x_shp0, y_shp0);
	return res;
}
matrix_shape_t TOP_LEVEL_linalg_matrixMultElementwise_shp(matrix_shape_t x_shp, matrix_shape_t y_shp) {
	env_t_258 env_t_258_value = make_empty_env(); closure_t closure257 = make_closure(lambda258, &env_t_258_value);
	return TOP_LEVEL_linalg_matrixMap2_shp(closure257, x_shp, y_shp);
}

typedef empty_env_t env_t_265;


value_t lambda265(env_t_265* env259, storage_t stgVar252, array_number_t x_dps0, array_number_t y_dps0, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.array_number_t_value = TOP_LEVEL_linalg_mult_vec_elementwise_dps(stgVar252, x_dps0, y_dps0, x_shp0, y_shp0);
	return res;
}
typedef empty_env_t env_t_266;


value_t lambda266(env_t_266* env262, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = TOP_LEVEL_linalg_mult_vec_elementwise_shp(x_shp0, y_shp0);
	return res;
}
array_array_number_t TOP_LEVEL_linalg_matrixMultElementwise_dps(storage_t stgVar248, array_array_number_t x_dps, array_array_number_t y_dps, matrix_shape_t x_shp, matrix_shape_t y_shp) {
	env_t_265 env_t_265_value = make_empty_env(); closure_t closure261 = make_closure(lambda265, &env_t_265_value);
	env_t_266 env_t_266_value = make_empty_env(); closure_t closure264 = make_closure(lambda266, &env_t_266_value);
	return TOP_LEVEL_linalg_matrixMap2_dps(stgVar248, closure261, x_dps, y_dps, closure264, x_shp, y_shp);
}

card_t TOP_LEVEL_linalg_sqnorm_shp(card_t x_shp) {
	
	return 0;
}

typedef empty_env_t env_t_285;


value_t lambda285(env_t_285* env272, card_t x1_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef empty_env_t env_t_286;


value_t lambda286(env_t_286* env275, storage_t stgVar271, number_t x1_dps, card_t x1_shp) {
	
	value_t res;
	res.number_t_value = (x1_dps) * (x1_dps);
	return res;
}
typedef empty_env_t env_t_287;


value_t lambda287(env_t_287* env278, card_t x1_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef empty_env_t env_t_288;


value_t lambda288(env_t_288* env281, card_t x1_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
number_t TOP_LEVEL_linalg_sqnorm_dps(storage_t stgVar267, array_number_t x_dps, card_t x_shp) {
	env_t_285 env_t_285_value = make_empty_env(); closure_t closure274 = make_closure(lambda285, &env_t_285_value);
	card_t size289 = width_card_t(TOP_LEVEL_linalg_vectorMap_shp(closure274, x_shp));
	array_number_t stgVar268 = storage_alloc(size289);
	number_t macroDef284;env_t_286 env_t_286_value = make_empty_env(); closure_t closure277 = make_closure(lambda286, &env_t_286_value);
	env_t_287 env_t_287_value = make_empty_env(); closure_t closure280 = make_closure(lambda287, &env_t_287_value);
	env_t_288 env_t_288_value = make_empty_env(); closure_t closure283 = make_closure(lambda288, &env_t_288_value);
	macroDef284 = TOP_LEVEL_linalg_vectorSum_dps(stgVar267, TOP_LEVEL_linalg_vectorMap_dps(stgVar268, closure277, x_dps, closure280, x_shp), TOP_LEVEL_linalg_vectorMap_shp(closure283, x_shp));;
	storage_free(stgVar268, size289);
	return macroDef284;
}

card_t TOP_LEVEL_linalg_dot_prod_shp(card_t x_shp, card_t y_shp) {
	
	return 0;
}

typedef empty_env_t env_t_309;


value_t lambda309(env_t_309* env296, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef empty_env_t env_t_310;


value_t lambda310(env_t_310* env299, storage_t stgVar295, number_t x_dps0, number_t y_dps0, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.number_t_value = (x_dps0) * (y_dps0);
	return res;
}
typedef empty_env_t env_t_311;


value_t lambda311(env_t_311* env302, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef empty_env_t env_t_312;


value_t lambda312(env_t_312* env305, card_t x_shp0, card_t y_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
number_t TOP_LEVEL_linalg_dot_prod_dps(storage_t stgVar290, array_number_t x_dps, array_number_t y_dps, card_t x_shp, card_t y_shp) {
	env_t_309 env_t_309_value = make_empty_env(); closure_t closure298 = make_closure(lambda309, &env_t_309_value);
	card_t size313 = width_card_t(TOP_LEVEL_linalg_vectorMap2_shp(closure298, x_shp, y_shp));
	array_number_t stgVar291 = storage_alloc(size313);
	number_t macroDef308;env_t_310 env_t_310_value = make_empty_env(); closure_t closure301 = make_closure(lambda310, &env_t_310_value);
	env_t_311 env_t_311_value = make_empty_env(); closure_t closure304 = make_closure(lambda311, &env_t_311_value);
	env_t_312 env_t_312_value = make_empty_env(); closure_t closure307 = make_closure(lambda312, &env_t_312_value);
	macroDef308 = TOP_LEVEL_linalg_vectorSum_dps(stgVar290, TOP_LEVEL_linalg_vectorMap2_dps(stgVar291, closure301, x_dps, y_dps, closure304, x_shp, y_shp), TOP_LEVEL_linalg_vectorMap2_shp(closure307, x_shp, y_shp));;
	storage_free(stgVar291, size313);
	return macroDef308;
}
typedef struct env_t_324 {
	card_t row_shp;
} env_t_324;
env_t_324 make_env_t_324(card_t row_shp) {
	env_t_324 env;
	env.row_shp = row_shp;
	return env;
}

value_t lambda324(env_t_324* env321, card_t r_shp) {
	card_t row_shp320 = env321->row_shp;
	value_t res;
	res.card_t_value = row_shp320;
	return res;
}
matrix_shape_t TOP_LEVEL_linalg_matrixFillFromVector_shp(card_t rows_shp, card_t row_shp) {
	env_t_324 env_t_324_value = make_env_t_324(row_shp); closure_t closure323 = make_closure(lambda324, &env_t_324_value);
	return TOP_LEVEL_linalg_vectorMapToMatrix_shp(closure323, TOP_LEVEL_linalg_vectorRange_shp(1, rows_shp));
}

typedef struct env_t_334 {
	array_number_t row_dps;
} env_t_334;
env_t_334 make_env_t_334(array_number_t row_dps) {
	env_t_334 env;
	env.row_dps = row_dps;
	return env;
}

value_t lambda334(env_t_334* env326, storage_t stgVar317, number_t r_dps, card_t r_shp) {
	array_number_t row_dps325 = env326->row_dps;
	value_t res;
	res.array_number_t_value = row_dps325;
	return res;
}
typedef struct env_t_335 {
	card_t row_shp;
} env_t_335;
env_t_335 make_env_t_335(card_t row_shp) {
	env_t_335 env;
	env.row_shp = row_shp;
	return env;
}

value_t lambda335(env_t_335* env330, card_t r_shp) {
	card_t row_shp329 = env330->row_shp;
	value_t res;
	res.card_t_value = row_shp329;
	return res;
}
array_array_number_t TOP_LEVEL_linalg_matrixFillFromVector_dps(storage_t stgVar314, card_t rows_dps, array_number_t row_dps, card_t rows_shp, card_t row_shp) {
	card_t size336 = width_card_t(TOP_LEVEL_linalg_vectorRange_shp(1, rows_shp));
	array_number_t stgVar316 = storage_alloc(size336);
	array_array_number_t macroDef333;env_t_334 env_t_334_value = make_env_t_334(row_dps); closure_t closure328 = make_closure(lambda334, &env_t_334_value);
	env_t_335 env_t_335_value = make_env_t_335(row_shp); closure_t closure332 = make_closure(lambda335, &env_t_335_value);
	macroDef333 = TOP_LEVEL_linalg_vectorMapToMatrix_dps(stgVar314, closure328, TOP_LEVEL_linalg_vectorRange_dps(stgVar316, 1, rows_dps, 1, rows_shp), closure332, TOP_LEVEL_linalg_vectorRange_shp(1, rows_shp));;
	storage_free(stgVar316, size336);
	return macroDef333;
}

matrix_shape_t TOP_LEVEL_linalg_matrixFill_shp(card_t rows_shp, card_t cols_shp, card_t value_shp) {
	
	return nested_shape_card_t(cols_shp, rows_shp);
}


array_array_number_t TOP_LEVEL_linalg_matrixFill_dps(storage_t stgVar337, card_t rows_dps, card_t cols_dps, number_t value_dps, card_t rows_shp, card_t cols_shp, card_t value_shp) {
	array_array_number_t macroDef341 = (array_array_number_t)stgVar337;
		macroDef341->length=rows_dps;
		macroDef341->arr=(array_number_t*)(STG_OFFSET(macroDef341, VECTOR_HEADER_BYTES));
		storage_t stgVar338 = (STG_OFFSET(macroDef341, MATRIX_HEADER_BYTES(rows_dps)));
		for(int r_dps = 0; r_dps < macroDef341->length; r_dps++){
			array_number_t macroDef340 = (array_number_t)stgVar338;
		macroDef340->length=cols_dps;
		macroDef340->arr=(number_t*)(STG_OFFSET(macroDef340, VECTOR_HEADER_BYTES));
		storage_t stgVar339 = macroDef340;
		for(int c_dps = 0; c_dps < macroDef340->length; c_dps++){
			
			macroDef340->arr[c_dps] = value_dps;;
			stgVar339 = STG_OFFSET(stgVar339, sizeof(number_t));
		}
			macroDef341->arr[r_dps] = macroDef340;;
			stgVar338 = STG_OFFSET(stgVar338, VECTOR_ALL_BYTES(macroDef341->arr[r_dps]->length));
		}
	return macroDef341;
}

matrix_shape_t TOP_LEVEL_linalg_matrixTranspose_shp(matrix_shape_t m_shp) {
	
	return nested_shape_card_t(m_shp.card, m_shp.elem);
}


array_array_number_t TOP_LEVEL_linalg_matrixTranspose_dps(storage_t stgVar342, array_array_number_t m_dps, matrix_shape_t m_shp) {
	card_t rows_shp = m_shp.card;
	card_t macroDef354 = m_dps->length;
	card_t rows_dps = macroDef354;
	card_t cols_shp = m_shp.elem;
	card_t size360 = width_card_t(m_shp.elem);
	array_number_t stgVar346 = storage_alloc(size360);
	card_t macroDef356;card_t macroDef355 = m_dps->arr[0]->length;
	macroDef356 = macroDef355;;
	storage_free(stgVar346, size360);
	card_t cols_dps = macroDef356;
	array_array_number_t macroDef359 = (array_array_number_t)stgVar342;
		macroDef359->length=cols_dps;
		macroDef359->arr=(array_number_t*)(STG_OFFSET(macroDef359, VECTOR_HEADER_BYTES));
		storage_t stgVar348 = (STG_OFFSET(macroDef359, MATRIX_HEADER_BYTES(cols_dps)));
		for(int i_dps = 0; i_dps < macroDef359->length; i_dps++){
			array_number_t macroDef358 = (array_number_t)stgVar348;
		macroDef358->length=rows_dps;
		macroDef358->arr=(number_t*)(STG_OFFSET(macroDef358, VECTOR_HEADER_BYTES));
		storage_t stgVar349 = macroDef358;
		for(int j_dps = 0; j_dps < macroDef358->length; j_dps++){
			card_t size361 = width_card_t(m_shp.elem);
	array_number_t stgVar350 = storage_alloc(size361);
	number_t macroDef357;
	macroDef357 = m_dps->arr[j_dps]->arr[i_dps];;
	storage_free(stgVar350, size361);
			macroDef358->arr[j_dps] = macroDef357;;
			stgVar349 = STG_OFFSET(stgVar349, sizeof(number_t));
		}
			macroDef359->arr[i_dps] = macroDef358;;
			stgVar348 = STG_OFFSET(stgVar348, VECTOR_ALL_BYTES(macroDef359->arr[i_dps]->length));
		}
	return macroDef359;
}

matrix_shape_t TOP_LEVEL_linalg_matrixMult_shp(matrix_shape_t m1_shp, matrix_shape_t m2_shp) {
	
	return nested_shape_card_t(m2_shp.elem, m1_shp.card);
}


array_array_number_t TOP_LEVEL_linalg_matrixMult_dps(storage_t stgVar362, array_array_number_t m1_dps, array_array_number_t m2_dps, matrix_shape_t m1_shp, matrix_shape_t m2_shp) {
	card_t r1_shp = m1_shp.card;
	card_t macroDef401 = m1_dps->length;
	card_t r1_dps = macroDef401;
	card_t c2_shp = m2_shp.elem;
	card_t size412 = width_card_t(m2_shp.elem);
	array_number_t stgVar366 = storage_alloc(size412);
	card_t macroDef403;card_t macroDef402 = m2_dps->arr[0]->length;
	macroDef403 = macroDef402;;
	storage_free(stgVar366, size412);
	card_t c2_dps = macroDef403;
	card_t c1_shp = m1_shp.elem;
	card_t size413 = width_card_t(m1_shp.elem);
	array_number_t stgVar369 = storage_alloc(size413);
	card_t macroDef405;card_t macroDef404 = m1_dps->arr[0]->length;
	macroDef405 = macroDef404;;
	storage_free(stgVar369, size413);
	card_t c1_dps = macroDef405;
	card_t r2_shp = m2_shp.card;
	card_t macroDef406 = m2_dps->length;
	card_t r2_dps = macroDef406;
	matrix_shape_t m2T_shp = TOP_LEVEL_linalg_matrixTranspose_shp(m2_shp);
	card_t size416 = width_matrix_shape_t(m2T_shp);
	array_number_t stgVar373 = storage_alloc(size416);
	array_array_number_t macroDef411;array_array_number_t m2T_dps = TOP_LEVEL_linalg_matrixTranspose_dps(stgVar373, m2_dps, m2_shp);
	array_array_number_t macroDef410 = (array_array_number_t)stgVar362;
		macroDef410->length=r1_dps;
		macroDef410->arr=(array_number_t*)(STG_OFFSET(macroDef410, VECTOR_HEADER_BYTES));
		storage_t stgVar375 = (STG_OFFSET(macroDef410, MATRIX_HEADER_BYTES(r1_dps)));
		for(int r_dps = 0; r_dps < macroDef410->length; r_dps++){
			array_number_t macroDef409 = (array_number_t)stgVar375;
		macroDef409->length=c2_dps;
		macroDef409->arr=(number_t*)(STG_OFFSET(macroDef409, VECTOR_HEADER_BYTES));
		storage_t stgVar376 = macroDef409;
		for(int c_dps = 0; c_dps < macroDef409->length; c_dps++){
			card_t size415 = width_card_t(m2T_shp.elem);
	array_number_t stgVar378 = storage_alloc(size415);
	number_t macroDef408;card_t size414 = width_card_t(m1_shp.elem);
	array_number_t stgVar377 = storage_alloc(size414);
	number_t macroDef407;
	macroDef407 = TOP_LEVEL_linalg_dot_prod_dps(stgVar376, m1_dps->arr[r_dps], m2T_dps->arr[c_dps], m1_shp.elem, m2T_shp.elem);;
	storage_free(stgVar377, size414);
	macroDef408 = macroDef407;;
	storage_free(stgVar378, size415);
			macroDef409->arr[c_dps] = macroDef408;;
			stgVar376 = STG_OFFSET(stgVar376, sizeof(number_t));
		}
			macroDef410->arr[r_dps] = macroDef409;;
			stgVar375 = STG_OFFSET(stgVar375, VECTOR_ALL_BYTES(macroDef410->arr[r_dps]->length));
		}
	macroDef411 = macroDef410;;
	storage_free(stgVar373, size416);
	return macroDef411;
}

card_t TOP_LEVEL_linalg_matrixVectorMult_shp(matrix_shape_t m_shp, card_t v_shp) {
	
	return TOP_LEVEL_linalg_rows_shp(m_shp);
}


array_number_t TOP_LEVEL_linalg_matrixVectorMult_dps(storage_t stgVar417, array_array_number_t m_dps, array_number_t v_dps, matrix_shape_t m_shp, card_t v_shp) {
	card_t r_shp = TOP_LEVEL_linalg_rows_shp(m_shp);
	card_t size434 = width_card_t(r_shp);
	array_number_t stgVar418 = storage_alloc(size434);
	array_number_t macroDef431;card_t r_dps = TOP_LEVEL_linalg_rows_dps(stgVar418, m_dps, m_shp);
	card_t c_shp = TOP_LEVEL_linalg_cols_shp(m_shp);
	card_t size433 = width_card_t(c_shp);
	array_number_t stgVar420 = storage_alloc(size433);
	array_number_t macroDef430;card_t c_dps = TOP_LEVEL_linalg_cols_dps(stgVar420, m_dps, m_shp);
	array_number_t macroDef429 = (array_number_t)stgVar417;
		macroDef429->length=r_dps;
		macroDef429->arr=(number_t*)(STG_OFFSET(macroDef429, VECTOR_HEADER_BYTES));
		storage_t stgVar422 = macroDef429;
		for(int i_dps = 0; i_dps < macroDef429->length; i_dps++){
			card_t size432 = width_card_t(m_shp.elem);
	array_number_t stgVar423 = storage_alloc(size432);
	number_t macroDef428;
	macroDef428 = TOP_LEVEL_linalg_dot_prod_dps(stgVar422, m_dps->arr[i_dps], v_dps, m_shp.elem, v_shp);;
	storage_free(stgVar423, size432);
			macroDef429->arr[i_dps] = macroDef428;;
			stgVar422 = STG_OFFSET(stgVar422, sizeof(number_t));
		}
	macroDef430 = macroDef429;;
	storage_free(stgVar420, size433);
	macroDef431 = macroDef430;;
	storage_free(stgVar418, size434);
	return macroDef431;
}

matrix_shape_t TOP_LEVEL_linalg_matrixConcat_shp(matrix_shape_t m1_shp, matrix_shape_t m2_shp) {
	
	return nested_shape_card_t(m1_shp.elem, (m1_shp.card) + (m2_shp.card));
}


array_array_number_t TOP_LEVEL_linalg_matrixConcat_dps(storage_t stgVar435, array_array_number_t m1_dps, array_array_number_t m2_dps, matrix_shape_t m1_shp, matrix_shape_t m2_shp) {
	card_t rows_shp = (m1_shp.card) + (m2_shp.card);
	card_t macroDef446 = m1_dps->length;
	card_t macroDef447 = m2_dps->length;
	card_t rows_dps = (macroDef446) + (macroDef447);
	card_t m1Rows_shp = 0;
	card_t macroDef448 = m1_dps->length;
	index_t m1Rows_dps = (macroDef448);
	array_array_number_t macroDef449 = (array_array_number_t)stgVar435;
		macroDef449->length=rows_dps;
		macroDef449->arr=(array_number_t*)(STG_OFFSET(macroDef449, VECTOR_HEADER_BYTES));
		storage_t stgVar441 = (STG_OFFSET(macroDef449, MATRIX_HEADER_BYTES(rows_dps)));
		for(int r_dps = 0; r_dps < macroDef449->length; r_dps++){
			array_number_t ite450 = 0;
	if((r_dps) < (m1Rows_dps)) {
		
		ite450 = m1_dps->arr[r_dps];;
	} else {
		
		ite450 = m2_dps->arr[(r_dps) - (m1Rows_dps)];;
	}
			macroDef449->arr[r_dps] = ite450;;
			stgVar441 = STG_OFFSET(stgVar441, VECTOR_ALL_BYTES(macroDef449->arr[r_dps]->length));
		}
	return macroDef449;
}

matrix_shape_t TOP_LEVEL_linalg_matrixConcatCol_shp(matrix_shape_t m1_shp, matrix_shape_t m2_shp) {
	
	return TOP_LEVEL_linalg_matrixTranspose_shp(TOP_LEVEL_linalg_matrixConcat_shp(TOP_LEVEL_linalg_matrixTranspose_shp(m1_shp), TOP_LEVEL_linalg_matrixTranspose_shp(m2_shp)));
}


array_array_number_t TOP_LEVEL_linalg_matrixConcatCol_dps(storage_t stgVar451, array_array_number_t m1_dps, array_array_number_t m2_dps, matrix_shape_t m1_shp, matrix_shape_t m2_shp) {
	matrix_shape_t m1t_shp = TOP_LEVEL_linalg_matrixTranspose_shp(m1_shp);
	card_t size466 = width_matrix_shape_t(m1t_shp);
	array_number_t stgVar452 = storage_alloc(size466);
	array_array_number_t macroDef463;array_array_number_t m1t_dps = TOP_LEVEL_linalg_matrixTranspose_dps(stgVar452, m1_dps, m1_shp);
	matrix_shape_t m2t_shp = TOP_LEVEL_linalg_matrixTranspose_shp(m2_shp);
	card_t size465 = width_matrix_shape_t(m2t_shp);
	array_number_t stgVar454 = storage_alloc(size465);
	array_array_number_t macroDef462;array_array_number_t m2t_dps = TOP_LEVEL_linalg_matrixTranspose_dps(stgVar454, m2_dps, m2_shp);
	card_t size464 = width_matrix_shape_t(TOP_LEVEL_linalg_matrixConcat_shp(m1t_shp, m2t_shp));
	array_number_t stgVar456 = storage_alloc(size464);
	array_array_number_t macroDef461;
	macroDef461 = TOP_LEVEL_linalg_matrixTranspose_dps(stgVar451, TOP_LEVEL_linalg_matrixConcat_dps(stgVar456, m1t_dps, m2t_dps, m1t_shp, m2t_shp), TOP_LEVEL_linalg_matrixConcat_shp(m1t_shp, m2t_shp));;
	storage_free(stgVar456, size464);
	macroDef462 = macroDef461;;
	storage_free(stgVar454, size465);
	macroDef463 = macroDef462;;
	storage_free(stgVar452, size466);
	return macroDef463;
}

matrix3d_shape_t TOP_LEVEL_linalg_matrix3DConcat_shp(matrix3d_shape_t m1_shp, matrix3d_shape_t m2_shp) {
	
	return nested_shape_matrix_shape_t(m1_shp.elem, (m1_shp.card) + (m2_shp.card));
}


array_array_array_number_t TOP_LEVEL_linalg_matrix3DConcat_dps(storage_t stgVar467, array_array_array_number_t m1_dps, array_array_array_number_t m2_dps, matrix3d_shape_t m1_shp, matrix3d_shape_t m2_shp) {
	card_t rows_shp = (m1_shp.card) + (m2_shp.card);
	card_t macroDef478 = m1_dps->length;
	card_t macroDef479 = m2_dps->length;
	card_t rows_dps = (macroDef478) + (macroDef479);
	card_t m1Rows_shp = 0;
	card_t macroDef480 = m1_dps->length;
	index_t m1Rows_dps = (macroDef480);
	array_array_array_number_t macroDef481 = (array_array_array_number_t)stgVar467;
		macroDef481->length=rows_dps;
		macroDef481->arr=(array_array_number_t*)(STG_OFFSET(macroDef481, VECTOR_HEADER_BYTES));
		storage_t stgVar473 = (STG_OFFSET(macroDef481, MATRIX_HEADER_BYTES(rows_dps)));
		for(int r_dps = 0; r_dps < macroDef481->length; r_dps++){
			array_array_number_t ite482 = 0;
	if((r_dps) < (m1Rows_dps)) {
		
		ite482 = m1_dps->arr[r_dps];;
	} else {
		
		ite482 = m2_dps->arr[(r_dps) - (m1Rows_dps)];;
	}
			macroDef481->arr[r_dps] = ite482;;
			stgVar473 = STG_OFFSET(stgVar473, VECTOR_ALL_BYTES(macroDef481->arr[r_dps]->length));
		}
	return macroDef481;
}

card_t TOP_LEVEL_linalg_vectorRead_shp(card_t fn_shp, card_t startLine_shp, card_t cols_shp) {
	
	return nested_shape_card_t(cols_shp, 1).elem;
}


array_number_t TOP_LEVEL_linalg_vectorRead_dps(storage_t stgVar483, string_t fn_dps, index_t startLine_dps, card_t cols_dps, card_t fn_shp, card_t startLine_shp, card_t cols_shp) {
	matrix_shape_t matrix_shp = nested_shape_card_t(cols_shp, 1);
	card_t size487 = width_matrix_shape_t(matrix_shp);
	array_number_t stgVar484 = storage_alloc(size487);
	array_number_t macroDef486;array_array_number_t matrix_dps = matrix_read_s(stgVar484, fn_dps, startLine_dps, 1, cols_dps);
	macroDef486 = matrix_dps->arr[0];;
	storage_free(stgVar484, size487);
	return macroDef486;
}

card_t TOP_LEVEL_linalg_numberRead_shp(card_t fn_shp, card_t startLine_shp) {
	
	return 0;
}


number_t TOP_LEVEL_linalg_numberRead_dps(storage_t stgVar488, string_t fn_dps, index_t startLine_dps, card_t fn_shp, card_t startLine_shp) {
	card_t vector_shp = TOP_LEVEL_linalg_vectorRead_shp(0, 0, 1);
	card_t size495 = width_card_t(vector_shp);
	array_number_t stgVar489 = storage_alloc(size495);
	number_t macroDef494;array_number_t vector_dps = TOP_LEVEL_linalg_vectorRead_dps(stgVar489, fn_dps, startLine_dps, 1, 0, 0, 1);
	macroDef494 = vector_dps->arr[0];;
	storage_free(stgVar489, size495);
	return macroDef494;
}

card_t TOP_LEVEL_linalg_vec3_shp(card_t a_shp, card_t b_shp, card_t c_shp) {
	
	return 3;
}


array_number_t TOP_LEVEL_linalg_vec3_dps(storage_t stgVar496, number_t a_dps, number_t b_dps, number_t c_dps, card_t a_shp, card_t b_shp, card_t c_shp) {
	array_number_t macroDef500 = (array_number_t)stgVar496;
	macroDef500->length=3;
	macroDef500->arr=(number_t*)(STG_OFFSET(stgVar496, VECTOR_HEADER_BYTES));
	

	macroDef500->arr[0] = a_dps;;

	macroDef500->arr[1] = b_dps;;

	macroDef500->arr[2] = c_dps;;;
	return macroDef500;
}
#endif
