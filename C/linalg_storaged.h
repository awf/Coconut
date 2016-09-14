#ifndef __LINALG_STORAGED_H__ 
#define __LINALG_STORAGED_H__ 
#include "runtime/fsharp.h"
#include <stdio.h>
#include <math.h>

card_t TOP_LEVEL_linalg_vectorMap_c(closure_t f_c, card_t v_c) {
	
	return v_c;
}


array_number_t TOP_LEVEL_linalg_vectorMap_s(storage_t stgVar1, closure_t f_s, array_number_t v_s, closure_t f_c, card_t v_c) {
	card_t macroDef6 = v_s->length;
	array_number_t macroDef7 = (array_number_t)stgVar1;
		macroDef7->length=macroDef6;
		macroDef7->arr=(number_t*)(STG_OFFSET(macroDef7, VECTOR_HEADER_BYTES));
		storage_t stgVar3 = macroDef7;
		for(int i_s = 0; i_s < macroDef7->length; i_s++){
			
			macroDef7->arr[i_s] = f_s.lam(f_s.env, stgVar3, v_s->arr[i_s], 0).number_t_value;;
			stgVar3 = STG_OFFSET(stgVar3, sizeof(number_t));
		}
	return macroDef7;
}

card_t TOP_LEVEL_linalg_vectorRange_c(card_t s_c, card_t e_c) {
	
	return ((e_c) - (s_c)) + (1);
}


array_number_t TOP_LEVEL_linalg_vectorRange_s(storage_t stgVar8, card_t s_s, card_t e_s, card_t s_c, card_t e_c) {
	array_number_t macroDef10 = (array_number_t)stgVar8;
		macroDef10->length=((e_s) - (s_s)) + (1);
		macroDef10->arr=(number_t*)(STG_OFFSET(macroDef10, VECTOR_HEADER_BYTES));
		storage_t stgVar9 = macroDef10;
		for(int i_s = 0; i_s < macroDef10->length; i_s++){
			
			macroDef10->arr[i_s] = (double)(((s_s)) + (i_s));;
			stgVar9 = STG_OFFSET(stgVar9, sizeof(number_t));
		}
	return macroDef10;
}

card_t TOP_LEVEL_linalg_vectorSlice_c(card_t size_c, card_t offset_c, card_t v_c) {
	
	return size_c;
}


array_number_t TOP_LEVEL_linalg_vectorSlice_s(storage_t stgVar11, card_t size_s, index_t offset_s, array_number_t v_s, card_t size_c, card_t offset_c, card_t v_c) {
	array_number_t macroDef14 = (array_number_t)stgVar11;
		macroDef14->length=size_s;
		macroDef14->arr=(number_t*)(STG_OFFSET(macroDef14, VECTOR_HEADER_BYTES));
		storage_t stgVar12 = macroDef14;
		for(int i_s = 0; i_s < macroDef14->length; i_s++){
			
			macroDef14->arr[i_s] = v_s->arr[(i_s) + (offset_s)];;
			stgVar12 = STG_OFFSET(stgVar12, sizeof(number_t));
		}
	return macroDef14;
}

matrix_shape_t TOP_LEVEL_linalg_matrixMap_c(closure_t f_c, matrix_shape_t m_c) {
	
	return nested_shape_card_t(f_c.lam(f_c.env, m_c.elem).card_t_value, m_c.card);
}


array_array_number_t TOP_LEVEL_linalg_matrixMap_s(storage_t stgVar15, closure_t f_s, array_array_number_t m_s, closure_t f_c, matrix_shape_t m_c) {
	card_t macroDef20 = m_s->length;
	array_array_number_t macroDef22 = (array_array_number_t)stgVar15;
		macroDef22->length=macroDef20;
		macroDef22->arr=(array_number_t*)(STG_OFFSET(macroDef22, VECTOR_HEADER_BYTES));
		storage_t stgVar17 = (STG_OFFSET(macroDef22, MATRIX_HEADER_BYTES(macroDef20)));
		for(int i_s = 0; i_s < macroDef22->length; i_s++){
			card_t size23 = width_card_t(m_c.elem);
	array_number_t stgVar18 = storage_alloc(size23);
	array_number_t macroDef21;
	macroDef21 = f_s.lam(f_s.env, stgVar17, m_s->arr[i_s], m_c.elem).array_number_t_value;;
	storage_free(stgVar18, size23);
			macroDef22->arr[i_s] = macroDef21;;
			stgVar17 = STG_OFFSET(stgVar17, VECTOR_ALL_BYTES(macroDef22->arr[i_s]->length));
		}
	return macroDef22;
}

card_t TOP_LEVEL_linalg_vectorMap2_c(closure_t f_c, card_t v1_c, card_t v2_c) {
	
	return v1_c;
}


array_number_t TOP_LEVEL_linalg_vectorMap2_s(storage_t stgVar24, closure_t f_s, array_number_t v1_s, array_number_t v2_s, closure_t f_c, card_t v1_c, card_t v2_c) {
	card_t macroDef31 = v1_s->length;
	array_number_t macroDef32 = (array_number_t)stgVar24;
		macroDef32->length=macroDef31;
		macroDef32->arr=(number_t*)(STG_OFFSET(macroDef32, VECTOR_HEADER_BYTES));
		storage_t stgVar26 = macroDef32;
		for(int i_s = 0; i_s < macroDef32->length; i_s++){
			
			macroDef32->arr[i_s] = f_s.lam(f_s.env, stgVar26, v1_s->arr[i_s], v2_s->arr[i_s], 0, 0).number_t_value;;
			stgVar26 = STG_OFFSET(stgVar26, sizeof(number_t));
		}
	return macroDef32;
}

matrix_shape_t TOP_LEVEL_linalg_matrixMap2_c(closure_t f_c, matrix_shape_t m1_c, matrix_shape_t m2_c) {
	
	return nested_shape_card_t(f_c.lam(f_c.env, m1_c.elem, m2_c.elem).card_t_value, m1_c.card);
}


array_array_number_t TOP_LEVEL_linalg_matrixMap2_s(storage_t stgVar33, closure_t f_s, array_array_number_t m1_s, array_array_number_t m2_s, closure_t f_c, matrix_shape_t m1_c, matrix_shape_t m2_c) {
	card_t macroDef40 = m1_s->length;
	array_array_number_t macroDef43 = (array_array_number_t)stgVar33;
		macroDef43->length=macroDef40;
		macroDef43->arr=(array_number_t*)(STG_OFFSET(macroDef43, VECTOR_HEADER_BYTES));
		storage_t stgVar35 = (STG_OFFSET(macroDef43, MATRIX_HEADER_BYTES(macroDef40)));
		for(int i_s = 0; i_s < macroDef43->length; i_s++){
			card_t size45 = width_card_t(m2_c.elem);
	array_number_t stgVar37 = storage_alloc(size45);
	array_number_t macroDef42;card_t size44 = width_card_t(m1_c.elem);
	array_number_t stgVar36 = storage_alloc(size44);
	array_number_t macroDef41;
	macroDef41 = f_s.lam(f_s.env, stgVar35, m1_s->arr[i_s], m2_s->arr[i_s], m1_c.elem, m2_c.elem).array_number_t_value;;
	storage_free(stgVar36, size44);
	macroDef42 = macroDef41;;
	storage_free(stgVar37, size45);
			macroDef43->arr[i_s] = macroDef42;;
			stgVar35 = STG_OFFSET(stgVar35, VECTOR_ALL_BYTES(macroDef43->arr[i_s]->length));
		}
	return macroDef43;
}

matrix3d_shape_t TOP_LEVEL_linalg_matrix3DMap2_c(closure_t f_c, matrix3d_shape_t m1_c, matrix3d_shape_t m2_c) {
	
	return nested_shape_matrix_shape_t(f_c.lam(f_c.env, m1_c.elem, m2_c.elem).matrix_shape_t_value, m1_c.card);
}


array_array_array_number_t TOP_LEVEL_linalg_matrix3DMap2_s(storage_t stgVar46, closure_t f_s, array_array_array_number_t m1_s, array_array_array_number_t m2_s, closure_t f_c, matrix3d_shape_t m1_c, matrix3d_shape_t m2_c) {
	card_t macroDef53 = m1_s->length;
	array_array_array_number_t macroDef56 = (array_array_array_number_t)stgVar46;
		macroDef56->length=macroDef53;
		macroDef56->arr=(array_array_number_t*)(STG_OFFSET(macroDef56, VECTOR_HEADER_BYTES));
		storage_t stgVar48 = (STG_OFFSET(macroDef56, MATRIX_HEADER_BYTES(macroDef53)));
		for(int i_s = 0; i_s < macroDef56->length; i_s++){
			card_t size58 = width_matrix_shape_t(m2_c.elem);
	array_number_t stgVar50 = storage_alloc(size58);
	array_array_number_t macroDef55;card_t size57 = width_matrix_shape_t(m1_c.elem);
	array_number_t stgVar49 = storage_alloc(size57);
	array_array_number_t macroDef54;
	macroDef54 = f_s.lam(f_s.env, stgVar48, m1_s->arr[i_s], m2_s->arr[i_s], m1_c.elem, m2_c.elem).array_array_number_t_value;;
	storage_free(stgVar49, size57);
	macroDef55 = macroDef54;;
	storage_free(stgVar50, size58);
			macroDef56->arr[i_s] = macroDef55;;
			stgVar48 = STG_OFFSET(stgVar48, VECTOR_ALL_BYTES(macroDef56->arr[i_s]->length));
		}
	return macroDef56;
}

matrix_shape_t TOP_LEVEL_linalg_vectorMapToMatrix_c(closure_t f_c, card_t arr_c) {
	
	return nested_shape_card_t(f_c.lam(f_c.env, 0).card_t_value, arr_c);
}


array_array_number_t TOP_LEVEL_linalg_vectorMapToMatrix_s(storage_t stgVar59, closure_t f_s, array_number_t arr_s, closure_t f_c, card_t arr_c) {
	card_t macroDef64 = arr_s->length;
	array_array_number_t macroDef65 = (array_array_number_t)stgVar59;
		macroDef65->length=macroDef64;
		macroDef65->arr=(array_number_t*)(STG_OFFSET(macroDef65, VECTOR_HEADER_BYTES));
		storage_t stgVar61 = (STG_OFFSET(macroDef65, MATRIX_HEADER_BYTES(macroDef64)));
		for(int i_s = 0; i_s < macroDef65->length; i_s++){
			
			macroDef65->arr[i_s] = f_s.lam(f_s.env, stgVar61, arr_s->arr[i_s], 0).array_number_t_value;;
			stgVar61 = STG_OFFSET(stgVar61, VECTOR_ALL_BYTES(macroDef65->arr[i_s]->length));
		}
	return macroDef65;
}

matrix3d_shape_t TOP_LEVEL_linalg_vectorMapToMatrix3D_c(closure_t f_c, card_t arr_c) {
	
	return nested_shape_matrix_shape_t(f_c.lam(f_c.env, 0).matrix_shape_t_value, arr_c);
}


array_array_array_number_t TOP_LEVEL_linalg_vectorMapToMatrix3D_s(storage_t stgVar66, closure_t f_s, array_number_t arr_s, closure_t f_c, card_t arr_c) {
	card_t macroDef71 = arr_s->length;
	array_array_array_number_t macroDef72 = (array_array_array_number_t)stgVar66;
		macroDef72->length=macroDef71;
		macroDef72->arr=(array_array_number_t*)(STG_OFFSET(macroDef72, VECTOR_HEADER_BYTES));
		storage_t stgVar68 = (STG_OFFSET(macroDef72, MATRIX_HEADER_BYTES(macroDef71)));
		for(int i_s = 0; i_s < macroDef72->length; i_s++){
			
			macroDef72->arr[i_s] = f_s.lam(f_s.env, stgVar68, arr_s->arr[i_s], 0).array_array_number_t_value;;
			stgVar68 = STG_OFFSET(stgVar68, VECTOR_ALL_BYTES(macroDef72->arr[i_s]->length));
		}
	return macroDef72;
}

card_t TOP_LEVEL_linalg_iterateNumber_c(closure_t f_c, card_t z_c, card_t s_c, card_t e_c) {
	
	return 0;
}


number_t TOP_LEVEL_linalg_iterateNumber_s(storage_t stgVar73, closure_t f_s, number_t z_s, card_t s_s, card_t e_s, closure_t f_c, card_t z_c, card_t s_c, card_t e_c) {
	number_t macroDef79 = z_s;
	array_number_t cur_s_range = TOP_LEVEL_linalg_vectorRange_s(empty_storage, s_s, e_s, s_c, e_c);
	storage_t stgVar74 = stgVar73;
	for(int cur_s_idx = 0; cur_s_idx < cur_s_range->length; cur_s_idx++){
		number_t cur_s = cur_s_range->arr[cur_s_idx];
		
		macroDef79 = f_s.lam(f_s.env, stgVar74, macroDef79, (int)(cur_s), 0, 0).number_t_value;;
	}
	return macroDef79;
}

card_t TOP_LEVEL_linalg_iterateVector_c(closure_t f_c, card_t z_c, card_t s_c, card_t e_c) {
	
	return z_c;
}


array_number_t TOP_LEVEL_linalg_iterateVector_s(storage_t stgVar80, closure_t f_s, array_number_t z_s, card_t s_s, card_t e_s, closure_t f_c, card_t z_c, card_t s_c, card_t e_c) {
	array_number_t macroDef86 = z_s;
	array_number_t cur_s_range = TOP_LEVEL_linalg_vectorRange_s(empty_storage, s_s, e_s, s_c, e_c);
	storage_t stgVar81 = stgVar80;
	for(int cur_s_idx = 0; cur_s_idx < cur_s_range->length; cur_s_idx++){
		number_t cur_s = cur_s_range->arr[cur_s_idx];
		
		macroDef86 = f_s.lam(f_s.env, stgVar81, macroDef86, (int)(cur_s), z_c, 0).array_number_t_value;;
	}
	return macroDef86;
}

matrix_shape_t TOP_LEVEL_linalg_iterateMatrix_c(closure_t f_c, matrix_shape_t z_c, card_t s_c, card_t e_c) {
	
	return z_c;
}


array_array_number_t TOP_LEVEL_linalg_iterateMatrix_s(storage_t stgVar87, closure_t f_s, array_array_number_t z_s, card_t s_s, card_t e_s, closure_t f_c, matrix_shape_t z_c, card_t s_c, card_t e_c) {
	array_array_number_t macroDef93 = z_s;
	array_number_t cur_s_range = TOP_LEVEL_linalg_vectorRange_s(empty_storage, s_s, e_s, s_c, e_c);
	storage_t stgVar88 = stgVar87;
	for(int cur_s_idx = 0; cur_s_idx < cur_s_range->length; cur_s_idx++){
		number_t cur_s = cur_s_range->arr[cur_s_idx];
		
		macroDef93 = f_s.lam(f_s.env, stgVar88, macroDef93, (int)(cur_s), z_c, 0).array_array_number_t_value;;
	}
	return macroDef93;
}

matrix3d_shape_t TOP_LEVEL_linalg_iterateMatrix3D_c(closure_t f_c, matrix3d_shape_t z_c, card_t s_c, card_t e_c) {
	
	return z_c;
}


array_array_array_number_t TOP_LEVEL_linalg_iterateMatrix3D_s(storage_t stgVar94, closure_t f_s, array_array_array_number_t z_s, card_t s_s, card_t e_s, closure_t f_c, matrix3d_shape_t z_c, card_t s_c, card_t e_c) {
	array_array_array_number_t macroDef100 = z_s;
	array_number_t cur_s_range = TOP_LEVEL_linalg_vectorRange_s(empty_storage, s_s, e_s, s_c, e_c);
	storage_t stgVar95 = stgVar94;
	for(int cur_s_idx = 0; cur_s_idx < cur_s_range->length; cur_s_idx++){
		number_t cur_s = cur_s_range->arr[cur_s_idx];
		
		macroDef100 = f_s.lam(f_s.env, stgVar95, macroDef100, (int)(cur_s), z_c, 0).array_array_array_number_t_value;;
	}
	return macroDef100;
}

card_t TOP_LEVEL_linalg_arraySum_c(card_t arr_c) {
	
	return 0;
}


number_t TOP_LEVEL_linalg_arraySum_s(storage_t stgVar101, array_number_t arr_s, card_t arr_c) {
	number_t macroDef103 = 0;
	array_number_t cur_s_range = arr_s;
	storage_t stgVar102 = stgVar101;
	for(int cur_s_idx = 0; cur_s_idx < cur_s_range->length; cur_s_idx++){
		number_t cur_s = cur_s_range->arr[cur_s_idx];
		
		macroDef103 = (macroDef103) + (cur_s);;
	}
	return macroDef103;
}

card_t TOP_LEVEL_linalg_arrayMax_c(card_t arr_c) {
	
	return 0;
}


number_t TOP_LEVEL_linalg_arrayMax_s(storage_t stgVar104, array_number_t arr_s, card_t arr_c) {
	number_t macroDef106 = -1000;
	array_number_t cur_s_range = arr_s;
	storage_t stgVar105 = stgVar104;
	for(int cur_s_idx = 0; cur_s_idx < cur_s_range->length; cur_s_idx++){
		number_t cur_s = cur_s_range->arr[cur_s_idx];
		number_t ite107 = 0;
	if((macroDef106) > (cur_s)) {
		
		ite107 = macroDef106;;
	} else {
		
		ite107 = cur_s;;
	}
		macroDef106 = ite107;;
	}
	return macroDef106;
}
typedef empty_env_t env_t_115;


value_t lambda115(env_t_115* env112, card_t a_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
card_t TOP_LEVEL_linalg_mult_by_scalar_c(card_t x_c, card_t y_c) {
	env_t_115 env_t_115_value = make_empty_env(); closure_t closure114 = make_closure(lambda115, &env_t_115_value);
	return TOP_LEVEL_linalg_vectorMap_c(closure114, x_c);
}

typedef struct env_t_123 {
	number_t y_s;
} env_t_123;
env_t_123 make_env_t_123(number_t y_s) {
	env_t_123 env;
	env.y_s = y_s;
	return env;
}

value_t lambda123(env_t_123* env117, storage_t stgVar111, number_t a_s, card_t a_c) {
	number_t y_s116 = env117->y_s;
	value_t res;
	res.number_t_value = (a_s) * (y_s116);
	return res;
}
typedef empty_env_t env_t_124;


value_t lambda124(env_t_124* env120, card_t a_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
array_number_t TOP_LEVEL_linalg_mult_by_scalar_s(storage_t stgVar108, array_number_t x_s, number_t y_s, card_t x_c, card_t y_c) {
	env_t_123 env_t_123_value = make_env_t_123(y_s); closure_t closure119 = make_closure(lambda123, &env_t_123_value);
	env_t_124 env_t_124_value = make_empty_env(); closure_t closure122 = make_closure(lambda124, &env_t_124_value);
	return TOP_LEVEL_linalg_vectorMap_s(stgVar108, closure119, x_s, closure122, x_c);
}

card_t TOP_LEVEL_linalg_cross_c(card_t a_c, card_t b_c) {
	
	return 3;
}


array_number_t TOP_LEVEL_linalg_cross_s(storage_t stgVar125, array_number_t a_s, array_number_t b_s, card_t a_c, card_t b_c) {
	array_number_t macroDef141 = (array_number_t)stgVar125;
	macroDef141->length=3;
	macroDef141->arr=(number_t*)(STG_OFFSET(stgVar125, VECTOR_HEADER_BYTES));
	macroDef141->arr[0] = ((a_s->arr[1]) * (b_s->arr[2])) - ((a_s->arr[2]) * (b_s->arr[1]));
	macroDef141->arr[1] = ((a_s->arr[2]) * (b_s->arr[0])) - ((a_s->arr[0]) * (b_s->arr[2]));
	macroDef141->arr[2] = ((a_s->arr[0]) * (b_s->arr[1])) - ((a_s->arr[1]) * (b_s->arr[0]));;
	return macroDef141;
}
typedef empty_env_t env_t_150;


value_t lambda150(env_t_150* env147, card_t x_c, card_t y_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
card_t TOP_LEVEL_linalg_add_vec_c(card_t x_c, card_t y_c) {
	env_t_150 env_t_150_value = make_empty_env(); closure_t closure149 = make_closure(lambda150, &env_t_150_value);
	return TOP_LEVEL_linalg_vectorMap2_c(closure149, x_c, y_c);
}

typedef empty_env_t env_t_157;


value_t lambda157(env_t_157* env151, storage_t stgVar146, number_t x_s, number_t y_s, card_t x_c, card_t y_c) {
	
	value_t res;
	res.number_t_value = (x_s) + (y_s);
	return res;
}
typedef empty_env_t env_t_158;


value_t lambda158(env_t_158* env154, card_t x_c, card_t y_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
array_number_t TOP_LEVEL_linalg_add_vec_s(storage_t stgVar142, array_number_t x_s, array_number_t y_s, card_t x_c, card_t y_c) {
	env_t_157 env_t_157_value = make_empty_env(); closure_t closure153 = make_closure(lambda157, &env_t_157_value);
	env_t_158 env_t_158_value = make_empty_env(); closure_t closure156 = make_closure(lambda158, &env_t_158_value);
	return TOP_LEVEL_linalg_vectorMap2_s(stgVar142, closure153, x_s, y_s, closure156, x_c, y_c);
}
typedef empty_env_t env_t_167;


value_t lambda167(env_t_167* env164, card_t x_c, card_t y_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
card_t TOP_LEVEL_linalg_mult_vec_elementwise_c(card_t x_c, card_t y_c) {
	env_t_167 env_t_167_value = make_empty_env(); closure_t closure166 = make_closure(lambda167, &env_t_167_value);
	return TOP_LEVEL_linalg_vectorMap2_c(closure166, x_c, y_c);
}

typedef empty_env_t env_t_174;


value_t lambda174(env_t_174* env168, storage_t stgVar163, number_t x_s, number_t y_s, card_t x_c, card_t y_c) {
	
	value_t res;
	res.number_t_value = (x_s) * (y_s);
	return res;
}
typedef empty_env_t env_t_175;


value_t lambda175(env_t_175* env171, card_t x_c, card_t y_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
array_number_t TOP_LEVEL_linalg_mult_vec_elementwise_s(storage_t stgVar159, array_number_t x_s, array_number_t y_s, card_t x_c, card_t y_c) {
	env_t_174 env_t_174_value = make_empty_env(); closure_t closure170 = make_closure(lambda174, &env_t_174_value);
	env_t_175 env_t_175_value = make_empty_env(); closure_t closure173 = make_closure(lambda175, &env_t_175_value);
	return TOP_LEVEL_linalg_vectorMap2_s(stgVar159, closure170, x_s, y_s, closure173, x_c, y_c);
}

card_t TOP_LEVEL_linalg_add_vec3_c(card_t x_c, card_t y_c, card_t z_c) {
	
	return TOP_LEVEL_linalg_add_vec_c(TOP_LEVEL_linalg_add_vec_c(x_c, y_c), z_c);
}


array_number_t TOP_LEVEL_linalg_add_vec3_s(storage_t stgVar176, array_number_t x_s, array_number_t y_s, array_number_t z_s, card_t x_c, card_t y_c, card_t z_c) {
	card_t size182 = width_card_t(TOP_LEVEL_linalg_add_vec_c(x_c, y_c));
	array_number_t stgVar177 = storage_alloc(size182);
	array_number_t macroDef181;
	macroDef181 = TOP_LEVEL_linalg_add_vec_s(stgVar176, TOP_LEVEL_linalg_add_vec_s(stgVar177, x_s, y_s, x_c, y_c), z_s, TOP_LEVEL_linalg_add_vec_c(x_c, y_c), z_c);;
	storage_free(stgVar177, size182);
	return macroDef181;
}
typedef empty_env_t env_t_191;


value_t lambda191(env_t_191* env188, card_t x_c, card_t y_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
card_t TOP_LEVEL_linalg_sub_vec_c(card_t x_c, card_t y_c) {
	env_t_191 env_t_191_value = make_empty_env(); closure_t closure190 = make_closure(lambda191, &env_t_191_value);
	return TOP_LEVEL_linalg_vectorMap2_c(closure190, x_c, y_c);
}

typedef empty_env_t env_t_198;


value_t lambda198(env_t_198* env192, storage_t stgVar187, number_t x_s, number_t y_s, card_t x_c, card_t y_c) {
	
	value_t res;
	res.number_t_value = (x_s) - (y_s);
	return res;
}
typedef empty_env_t env_t_199;


value_t lambda199(env_t_199* env195, card_t x_c, card_t y_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
array_number_t TOP_LEVEL_linalg_sub_vec_s(storage_t stgVar183, array_number_t x_s, array_number_t y_s, card_t x_c, card_t y_c) {
	env_t_198 env_t_198_value = make_empty_env(); closure_t closure194 = make_closure(lambda198, &env_t_198_value);
	env_t_199 env_t_199_value = make_empty_env(); closure_t closure197 = make_closure(lambda199, &env_t_199_value);
	return TOP_LEVEL_linalg_vectorMap2_s(stgVar183, closure194, x_s, y_s, closure197, x_c, y_c);
}
typedef empty_env_t env_t_210;


value_t lambda210(env_t_210* env207, card_t x_c, card_t y_c) {
	
	value_t res;
	res.card_t_value = TOP_LEVEL_linalg_add_vec_c(x_c, y_c);
	return res;
}
matrix_shape_t TOP_LEVEL_linalg_matrixAdd_c(matrix_shape_t x_c, matrix_shape_t y_c) {
	env_t_210 env_t_210_value = make_empty_env(); closure_t closure209 = make_closure(lambda210, &env_t_210_value);
	return TOP_LEVEL_linalg_matrixMap2_c(closure209, x_c, y_c);
}

typedef empty_env_t env_t_217;


value_t lambda217(env_t_217* env211, storage_t stgVar204, array_number_t x_s, array_number_t y_s, card_t x_c, card_t y_c) {
	
	value_t res;
	res.array_number_t_value = TOP_LEVEL_linalg_add_vec_s(stgVar204, x_s, y_s, x_c, y_c);
	return res;
}
typedef empty_env_t env_t_218;


value_t lambda218(env_t_218* env214, card_t x_c, card_t y_c) {
	
	value_t res;
	res.card_t_value = TOP_LEVEL_linalg_add_vec_c(x_c, y_c);
	return res;
}
array_array_number_t TOP_LEVEL_linalg_matrixAdd_s(storage_t stgVar200, array_array_number_t x_s, array_array_number_t y_s, matrix_shape_t x_c, matrix_shape_t y_c) {
	env_t_217 env_t_217_value = make_empty_env(); closure_t closure213 = make_closure(lambda217, &env_t_217_value);
	env_t_218 env_t_218_value = make_empty_env(); closure_t closure216 = make_closure(lambda218, &env_t_218_value);
	return TOP_LEVEL_linalg_matrixMap2_s(stgVar200, closure213, x_s, y_s, closure216, x_c, y_c);
}
typedef empty_env_t env_t_229;


value_t lambda229(env_t_229* env226, card_t x_c, card_t y_c) {
	
	value_t res;
	res.card_t_value = TOP_LEVEL_linalg_mult_vec_elementwise_c(x_c, y_c);
	return res;
}
matrix_shape_t TOP_LEVEL_linalg_matrixMultElementwise_c(matrix_shape_t x_c, matrix_shape_t y_c) {
	env_t_229 env_t_229_value = make_empty_env(); closure_t closure228 = make_closure(lambda229, &env_t_229_value);
	return TOP_LEVEL_linalg_matrixMap2_c(closure228, x_c, y_c);
}

typedef empty_env_t env_t_236;


value_t lambda236(env_t_236* env230, storage_t stgVar223, array_number_t x_s, array_number_t y_s, card_t x_c, card_t y_c) {
	
	value_t res;
	res.array_number_t_value = TOP_LEVEL_linalg_mult_vec_elementwise_s(stgVar223, x_s, y_s, x_c, y_c);
	return res;
}
typedef empty_env_t env_t_237;


value_t lambda237(env_t_237* env233, card_t x_c, card_t y_c) {
	
	value_t res;
	res.card_t_value = TOP_LEVEL_linalg_mult_vec_elementwise_c(x_c, y_c);
	return res;
}
array_array_number_t TOP_LEVEL_linalg_matrixMultElementwise_s(storage_t stgVar219, array_array_number_t x_s, array_array_number_t y_s, matrix_shape_t x_c, matrix_shape_t y_c) {
	env_t_236 env_t_236_value = make_empty_env(); closure_t closure232 = make_closure(lambda236, &env_t_236_value);
	env_t_237 env_t_237_value = make_empty_env(); closure_t closure235 = make_closure(lambda237, &env_t_237_value);
	return TOP_LEVEL_linalg_matrixMap2_s(stgVar219, closure232, x_s, y_s, closure235, x_c, y_c);
}

card_t TOP_LEVEL_linalg_sqnorm_c(card_t x_c) {
	
	return 0;
}

typedef empty_env_t env_t_256;


value_t lambda256(env_t_256* env243, card_t x1_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef empty_env_t env_t_257;


value_t lambda257(env_t_257* env246, storage_t stgVar242, number_t x1_s, card_t x1_c) {
	
	value_t res;
	res.number_t_value = (x1_s) * (x1_s);
	return res;
}
typedef empty_env_t env_t_258;


value_t lambda258(env_t_258* env249, card_t x1_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef empty_env_t env_t_259;


value_t lambda259(env_t_259* env252, card_t x1_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
number_t TOP_LEVEL_linalg_sqnorm_s(storage_t stgVar238, array_number_t x_s, card_t x_c) {
	env_t_256 env_t_256_value = make_empty_env(); closure_t closure245 = make_closure(lambda256, &env_t_256_value);
	card_t size260 = width_card_t(TOP_LEVEL_linalg_vectorMap_c(closure245, x_c));
	array_number_t stgVar239 = storage_alloc(size260);
	number_t macroDef255;env_t_257 env_t_257_value = make_empty_env(); closure_t closure248 = make_closure(lambda257, &env_t_257_value);
	env_t_258 env_t_258_value = make_empty_env(); closure_t closure251 = make_closure(lambda258, &env_t_258_value);
	env_t_259 env_t_259_value = make_empty_env(); closure_t closure254 = make_closure(lambda259, &env_t_259_value);
	macroDef255 = TOP_LEVEL_linalg_arraySum_s(stgVar238, TOP_LEVEL_linalg_vectorMap_s(stgVar239, closure248, x_s, closure251, x_c), TOP_LEVEL_linalg_vectorMap_c(closure254, x_c));;
	storage_free(stgVar239, size260);
	return macroDef255;
}

card_t TOP_LEVEL_linalg_dot_prod_c(card_t x_c, card_t y_c) {
	
	return 0;
}

typedef empty_env_t env_t_280;


value_t lambda280(env_t_280* env267, card_t x_c, card_t y_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef empty_env_t env_t_281;


value_t lambda281(env_t_281* env270, storage_t stgVar266, number_t x_s, number_t y_s, card_t x_c, card_t y_c) {
	
	value_t res;
	res.number_t_value = (x_s) * (y_s);
	return res;
}
typedef empty_env_t env_t_282;


value_t lambda282(env_t_282* env273, card_t x_c, card_t y_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef empty_env_t env_t_283;


value_t lambda283(env_t_283* env276, card_t x_c, card_t y_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
number_t TOP_LEVEL_linalg_dot_prod_s(storage_t stgVar261, array_number_t x_s, array_number_t y_s, card_t x_c, card_t y_c) {
	env_t_280 env_t_280_value = make_empty_env(); closure_t closure269 = make_closure(lambda280, &env_t_280_value);
	card_t size284 = width_card_t(TOP_LEVEL_linalg_vectorMap2_c(closure269, x_c, y_c));
	array_number_t stgVar262 = storage_alloc(size284);
	number_t macroDef279;env_t_281 env_t_281_value = make_empty_env(); closure_t closure272 = make_closure(lambda281, &env_t_281_value);
	env_t_282 env_t_282_value = make_empty_env(); closure_t closure275 = make_closure(lambda282, &env_t_282_value);
	env_t_283 env_t_283_value = make_empty_env(); closure_t closure278 = make_closure(lambda283, &env_t_283_value);
	macroDef279 = TOP_LEVEL_linalg_arraySum_s(stgVar261, TOP_LEVEL_linalg_vectorMap2_s(stgVar262, closure272, x_s, y_s, closure275, x_c, y_c), TOP_LEVEL_linalg_vectorMap2_c(closure278, x_c, y_c));;
	storage_free(stgVar262, size284);
	return macroDef279;
}
typedef struct env_t_295 {
	card_t row_c;
} env_t_295;
env_t_295 make_env_t_295(card_t row_c) {
	env_t_295 env;
	env.row_c = row_c;
	return env;
}

value_t lambda295(env_t_295* env292, card_t r_c) {
	card_t row_c291 = env292->row_c;
	value_t res;
	res.card_t_value = row_c291;
	return res;
}
matrix_shape_t TOP_LEVEL_linalg_matrixFillFromVector_c(card_t rows_c, card_t row_c) {
	env_t_295 env_t_295_value = make_env_t_295(row_c); closure_t closure294 = make_closure(lambda295, &env_t_295_value);
	return TOP_LEVEL_linalg_vectorMapToMatrix_c(closure294, TOP_LEVEL_linalg_vectorRange_c(1, rows_c));
}

typedef struct env_t_305 {
	array_number_t row_s;
} env_t_305;
env_t_305 make_env_t_305(array_number_t row_s) {
	env_t_305 env;
	env.row_s = row_s;
	return env;
}

value_t lambda305(env_t_305* env297, storage_t stgVar288, number_t r_s, card_t r_c) {
	array_number_t row_s296 = env297->row_s;
	value_t res;
	res.array_number_t_value = row_s296;
	return res;
}
typedef struct env_t_306 {
	card_t row_c;
} env_t_306;
env_t_306 make_env_t_306(card_t row_c) {
	env_t_306 env;
	env.row_c = row_c;
	return env;
}

value_t lambda306(env_t_306* env301, card_t r_c) {
	card_t row_c300 = env301->row_c;
	value_t res;
	res.card_t_value = row_c300;
	return res;
}
array_array_number_t TOP_LEVEL_linalg_matrixFillFromVector_s(storage_t stgVar285, card_t rows_s, array_number_t row_s, card_t rows_c, card_t row_c) {
	card_t size307 = width_card_t(TOP_LEVEL_linalg_vectorRange_c(1, rows_c));
	array_number_t stgVar287 = storage_alloc(size307);
	array_array_number_t macroDef304;env_t_305 env_t_305_value = make_env_t_305(row_s); closure_t closure299 = make_closure(lambda305, &env_t_305_value);
	env_t_306 env_t_306_value = make_env_t_306(row_c); closure_t closure303 = make_closure(lambda306, &env_t_306_value);
	macroDef304 = TOP_LEVEL_linalg_vectorMapToMatrix_s(stgVar285, closure299, TOP_LEVEL_linalg_vectorRange_s(stgVar287, 1, rows_s, 1, rows_c), closure303, TOP_LEVEL_linalg_vectorRange_c(1, rows_c));;
	storage_free(stgVar287, size307);
	return macroDef304;
}

matrix_shape_t TOP_LEVEL_linalg_matrixFill_c(card_t rows_c, card_t cols_c, card_t value_c) {
	
	return nested_shape_card_t(cols_c, rows_c);
}


array_array_number_t TOP_LEVEL_linalg_matrixFill_s(storage_t stgVar308, card_t rows_s, card_t cols_s, number_t value_s, card_t rows_c, card_t cols_c, card_t value_c) {
	array_array_number_t macroDef312 = (array_array_number_t)stgVar308;
		macroDef312->length=rows_s;
		macroDef312->arr=(array_number_t*)(STG_OFFSET(macroDef312, VECTOR_HEADER_BYTES));
		storage_t stgVar309 = (STG_OFFSET(macroDef312, MATRIX_HEADER_BYTES(rows_s)));
		for(int r_s = 0; r_s < macroDef312->length; r_s++){
			array_number_t macroDef311 = (array_number_t)stgVar309;
		macroDef311->length=cols_s;
		macroDef311->arr=(number_t*)(STG_OFFSET(macroDef311, VECTOR_HEADER_BYTES));
		storage_t stgVar310 = macroDef311;
		for(int c_s = 0; c_s < macroDef311->length; c_s++){
			
			macroDef311->arr[c_s] = value_s;;
			stgVar310 = STG_OFFSET(stgVar310, sizeof(number_t));
		}
			macroDef312->arr[r_s] = macroDef311;;
			stgVar309 = STG_OFFSET(stgVar309, VECTOR_ALL_BYTES(macroDef312->arr[r_s]->length));
		}
	return macroDef312;
}

matrix_shape_t TOP_LEVEL_linalg_matrixTranspose_c(matrix_shape_t m_c) {
	
	return nested_shape_card_t(m_c.card, m_c.elem);
}


array_array_number_t TOP_LEVEL_linalg_matrixTranspose_s(storage_t stgVar313, array_array_number_t m_s, matrix_shape_t m_c) {
	card_t rows_c = m_c.card;
	card_t macroDef325 = m_s->length;
	card_t rows_s = macroDef325;
	card_t cols_c = m_c.elem;
	card_t size331 = width_card_t(m_c.elem);
	array_number_t stgVar317 = storage_alloc(size331);
	card_t macroDef327;card_t macroDef326 = m_s->arr[0]->length;
	macroDef327 = macroDef326;;
	storage_free(stgVar317, size331);
	card_t cols_s = macroDef327;
	array_array_number_t macroDef330 = (array_array_number_t)stgVar313;
		macroDef330->length=cols_s;
		macroDef330->arr=(array_number_t*)(STG_OFFSET(macroDef330, VECTOR_HEADER_BYTES));
		storage_t stgVar319 = (STG_OFFSET(macroDef330, MATRIX_HEADER_BYTES(cols_s)));
		for(int i_s = 0; i_s < macroDef330->length; i_s++){
			array_number_t macroDef329 = (array_number_t)stgVar319;
		macroDef329->length=rows_s;
		macroDef329->arr=(number_t*)(STG_OFFSET(macroDef329, VECTOR_HEADER_BYTES));
		storage_t stgVar320 = macroDef329;
		for(int j_s = 0; j_s < macroDef329->length; j_s++){
			card_t size332 = width_card_t(m_c.elem);
	array_number_t stgVar321 = storage_alloc(size332);
	number_t macroDef328;
	macroDef328 = m_s->arr[j_s]->arr[i_s];;
	storage_free(stgVar321, size332);
			macroDef329->arr[j_s] = macroDef328;;
			stgVar320 = STG_OFFSET(stgVar320, sizeof(number_t));
		}
			macroDef330->arr[i_s] = macroDef329;;
			stgVar319 = STG_OFFSET(stgVar319, VECTOR_ALL_BYTES(macroDef330->arr[i_s]->length));
		}
	return macroDef330;
}

matrix_shape_t TOP_LEVEL_linalg_matrixMult_c(matrix_shape_t m1_c, matrix_shape_t m2_c) {
	
	return nested_shape_card_t(m2_c.elem, m1_c.card);
}


array_array_number_t TOP_LEVEL_linalg_matrixMult_s(storage_t stgVar333, array_array_number_t m1_s, array_array_number_t m2_s, matrix_shape_t m1_c, matrix_shape_t m2_c) {
	card_t r1_c = m1_c.card;
	card_t macroDef372 = m1_s->length;
	card_t r1_s = macroDef372;
	card_t c2_c = m2_c.elem;
	card_t size383 = width_card_t(m2_c.elem);
	array_number_t stgVar337 = storage_alloc(size383);
	card_t macroDef374;card_t macroDef373 = m2_s->arr[0]->length;
	macroDef374 = macroDef373;;
	storage_free(stgVar337, size383);
	card_t c2_s = macroDef374;
	card_t c1_c = m1_c.elem;
	card_t size384 = width_card_t(m1_c.elem);
	array_number_t stgVar340 = storage_alloc(size384);
	card_t macroDef376;card_t macroDef375 = m1_s->arr[0]->length;
	macroDef376 = macroDef375;;
	storage_free(stgVar340, size384);
	card_t c1_s = macroDef376;
	card_t r2_c = m2_c.card;
	card_t macroDef377 = m2_s->length;
	card_t r2_s = macroDef377;
	matrix_shape_t m2T_c = TOP_LEVEL_linalg_matrixTranspose_c(m2_c);
	card_t size387 = width_matrix_shape_t(m2T_c);
	array_number_t stgVar344 = storage_alloc(size387);
	array_array_number_t macroDef382;array_array_number_t m2T_s = TOP_LEVEL_linalg_matrixTranspose_s(stgVar344, m2_s, m2_c);
	array_array_number_t macroDef381 = (array_array_number_t)stgVar333;
		macroDef381->length=r1_s;
		macroDef381->arr=(array_number_t*)(STG_OFFSET(macroDef381, VECTOR_HEADER_BYTES));
		storage_t stgVar346 = (STG_OFFSET(macroDef381, MATRIX_HEADER_BYTES(r1_s)));
		for(int r_s = 0; r_s < macroDef381->length; r_s++){
			array_number_t macroDef380 = (array_number_t)stgVar346;
		macroDef380->length=c2_s;
		macroDef380->arr=(number_t*)(STG_OFFSET(macroDef380, VECTOR_HEADER_BYTES));
		storage_t stgVar347 = macroDef380;
		for(int c_s = 0; c_s < macroDef380->length; c_s++){
			card_t size386 = width_card_t(m2T_c.elem);
	array_number_t stgVar349 = storage_alloc(size386);
	number_t macroDef379;card_t size385 = width_card_t(m1_c.elem);
	array_number_t stgVar348 = storage_alloc(size385);
	number_t macroDef378;
	macroDef378 = TOP_LEVEL_linalg_dot_prod_s(stgVar347, m1_s->arr[r_s], m2T_s->arr[c_s], m1_c.elem, m2T_c.elem);;
	storage_free(stgVar348, size385);
	macroDef379 = macroDef378;;
	storage_free(stgVar349, size386);
			macroDef380->arr[c_s] = macroDef379;;
			stgVar347 = STG_OFFSET(stgVar347, sizeof(number_t));
		}
			macroDef381->arr[r_s] = macroDef380;;
			stgVar346 = STG_OFFSET(stgVar346, VECTOR_ALL_BYTES(macroDef381->arr[r_s]->length));
		}
	macroDef382 = macroDef381;;
	storage_free(stgVar344, size387);
	return macroDef382;
}

matrix_shape_t TOP_LEVEL_linalg_matrixConcat_c(matrix_shape_t m1_c, matrix_shape_t m2_c) {
	
	return nested_shape_card_t(m1_c.elem, (m1_c.card) + (m2_c.card));
}


array_array_number_t TOP_LEVEL_linalg_matrixConcat_s(storage_t stgVar388, array_array_number_t m1_s, array_array_number_t m2_s, matrix_shape_t m1_c, matrix_shape_t m2_c) {
	card_t rows_c = (m1_c.card) + (m2_c.card);
	card_t macroDef399 = m1_s->length;
	card_t macroDef400 = m2_s->length;
	card_t rows_s = (macroDef399) + (macroDef400);
	card_t m1Rows_c = 0;
	card_t macroDef401 = m1_s->length;
	index_t m1Rows_s = (macroDef401);
	array_array_number_t macroDef402 = (array_array_number_t)stgVar388;
		macroDef402->length=rows_s;
		macroDef402->arr=(array_number_t*)(STG_OFFSET(macroDef402, VECTOR_HEADER_BYTES));
		storage_t stgVar394 = (STG_OFFSET(macroDef402, MATRIX_HEADER_BYTES(rows_s)));
		for(int r_s = 0; r_s < macroDef402->length; r_s++){
			array_number_t ite403 = 0;
	if((r_s) < (m1Rows_s)) {
		
		ite403 = m1_s->arr[r_s];;
	} else {
		
		ite403 = m2_s->arr[(r_s) - (m1Rows_s)];;
	}
			macroDef402->arr[r_s] = ite403;;
			stgVar394 = STG_OFFSET(stgVar394, VECTOR_ALL_BYTES(macroDef402->arr[r_s]->length));
		}
	return macroDef402;
}

matrix_shape_t TOP_LEVEL_linalg_matrixConcatCol_c(matrix_shape_t m1_c, matrix_shape_t m2_c) {
	
	return TOP_LEVEL_linalg_matrixTranspose_c(TOP_LEVEL_linalg_matrixConcat_c(TOP_LEVEL_linalg_matrixTranspose_c(m1_c), TOP_LEVEL_linalg_matrixTranspose_c(m2_c)));
}


array_array_number_t TOP_LEVEL_linalg_matrixConcatCol_s(storage_t stgVar404, array_array_number_t m1_s, array_array_number_t m2_s, matrix_shape_t m1_c, matrix_shape_t m2_c) {
	matrix_shape_t m1t_c = TOP_LEVEL_linalg_matrixTranspose_c(m1_c);
	card_t size419 = width_matrix_shape_t(m1t_c);
	array_number_t stgVar405 = storage_alloc(size419);
	array_array_number_t macroDef416;array_array_number_t m1t_s = TOP_LEVEL_linalg_matrixTranspose_s(stgVar405, m1_s, m1_c);
	matrix_shape_t m2t_c = TOP_LEVEL_linalg_matrixTranspose_c(m2_c);
	card_t size418 = width_matrix_shape_t(m2t_c);
	array_number_t stgVar407 = storage_alloc(size418);
	array_array_number_t macroDef415;array_array_number_t m2t_s = TOP_LEVEL_linalg_matrixTranspose_s(stgVar407, m2_s, m2_c);
	card_t size417 = width_matrix_shape_t(TOP_LEVEL_linalg_matrixConcat_c(m1t_c, m2t_c));
	array_number_t stgVar409 = storage_alloc(size417);
	array_array_number_t macroDef414;
	macroDef414 = TOP_LEVEL_linalg_matrixTranspose_s(stgVar404, TOP_LEVEL_linalg_matrixConcat_s(stgVar409, m1t_s, m2t_s, m1t_c, m2t_c), TOP_LEVEL_linalg_matrixConcat_c(m1t_c, m2t_c));;
	storage_free(stgVar409, size417);
	macroDef415 = macroDef414;;
	storage_free(stgVar407, size418);
	macroDef416 = macroDef415;;
	storage_free(stgVar405, size419);
	return macroDef416;
}

matrix3d_shape_t TOP_LEVEL_linalg_matrix3DConcat_c(matrix3d_shape_t m1_c, matrix3d_shape_t m2_c) {
	
	return nested_shape_matrix_shape_t(m1_c.elem, (m1_c.card) + (m2_c.card));
}


array_array_array_number_t TOP_LEVEL_linalg_matrix3DConcat_s(storage_t stgVar420, array_array_array_number_t m1_s, array_array_array_number_t m2_s, matrix3d_shape_t m1_c, matrix3d_shape_t m2_c) {
	card_t rows_c = (m1_c.card) + (m2_c.card);
	card_t macroDef431 = m1_s->length;
	card_t macroDef432 = m2_s->length;
	card_t rows_s = (macroDef431) + (macroDef432);
	card_t m1Rows_c = 0;
	card_t macroDef433 = m1_s->length;
	index_t m1Rows_s = (macroDef433);
	array_array_array_number_t macroDef434 = (array_array_array_number_t)stgVar420;
		macroDef434->length=rows_s;
		macroDef434->arr=(array_array_number_t*)(STG_OFFSET(macroDef434, VECTOR_HEADER_BYTES));
		storage_t stgVar426 = (STG_OFFSET(macroDef434, MATRIX_HEADER_BYTES(rows_s)));
		for(int r_s = 0; r_s < macroDef434->length; r_s++){
			array_array_number_t ite435 = 0;
	if((r_s) < (m1Rows_s)) {
		
		ite435 = m1_s->arr[r_s];;
	} else {
		
		ite435 = m2_s->arr[(r_s) - (m1Rows_s)];;
	}
			macroDef434->arr[r_s] = ite435;;
			stgVar426 = STG_OFFSET(stgVar426, VECTOR_ALL_BYTES(macroDef434->arr[r_s]->length));
		}
	return macroDef434;
}

card_t TOP_LEVEL_linalg_vectorRead_c(card_t fn_c, card_t startLine_c) {
	
	return nested_shape_card_t(10, 1).elem;
}


array_number_t TOP_LEVEL_linalg_vectorRead_s(storage_t stgVar436, string_t fn_s, index_t startLine_s, card_t fn_c, card_t startLine_c) {
	matrix_shape_t matrix_c = nested_shape_card_t(10, 1);
	card_t size440 = width_matrix_shape_t(matrix_c);
	array_number_t stgVar437 = storage_alloc(size440);
	array_number_t macroDef439;array_array_number_t matrix_s = matrix_read_s(stgVar437, fn_s, startLine_s, 1);
	macroDef439 = matrix_s->arr[0];;
	storage_free(stgVar437, size440);
	return macroDef439;
}

card_t TOP_LEVEL_linalg_numberRead_c(card_t fn_c, card_t startLine_c) {
	
	return 0;
}


number_t TOP_LEVEL_linalg_numberRead_s(storage_t stgVar441, string_t fn_s, index_t startLine_s, card_t fn_c, card_t startLine_c) {
	card_t vector_c = TOP_LEVEL_linalg_vectorRead_c(0, 0);
	card_t size447 = width_card_t(vector_c);
	array_number_t stgVar442 = storage_alloc(size447);
	number_t macroDef446;array_number_t vector_s = TOP_LEVEL_linalg_vectorRead_s(stgVar442, fn_s, startLine_s, 0, 0);
	macroDef446 = vector_s->arr[0];;
	storage_free(stgVar442, size447);
	return macroDef446;
}
#endif
