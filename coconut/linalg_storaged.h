#ifndef __LINALG_STORAGED_H__ 
#define __LINALG_STORAGED_H__ 
#include "runtime/fsharp.h"
#include <stdio.h>
#include <math.h>

array_number_t TOP_LEVEL_linalg_vectorMap(closure_t f, array_number_t v) {
	card_t macroDef1 = v->length;
	array_number_t macroDef2 = (array_number_t)malloc(sizeof(int) * 2);
	macroDef2->length=macroDef1;
	macroDef2->arr = (number_t*)malloc(sizeof(number_t) * macroDef1);
		for(int i = 0; i < macroDef2->length; i++){
			
			macroDef2->arr[i] = f.lam(f.env, v->arr[i]).number_t_value;
		}
	return macroDef2;
}typedef empty_env_t env_t_11;


value_t lambda11(env_t_11* env8, card_t i_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
vector_shape_t TOP_LEVEL_linalg_vectorMap_c(closure_t f_c, vector_shape_t v_c) {
	env_t_11 env_t_11_value = make_empty_env(); closure_t closure10 = make_closure(lambda11, &env_t_11_value);
	return nested_shape_card_t(closure10.lam(closure10.env, 0).card_t_value, v_c.card);
}
array_number_t TOP_LEVEL_linalg_vectorMap_s(storage_t stgVar3, closure_t f_s, array_number_t v_s, closure_t f_c, vector_shape_t v_c) {
	card_t macroDef12 = v_s->length;
	array_number_t macroDef13 = (array_number_t)stgVar3;
		macroDef13->length=macroDef12;
		macroDef13->arr=(number_t*)((char*)macroDef13 + VECTOR_HEADER_BYTES);
		for(int i_s = 0; i_s < macroDef13->length; i_s++){
			storage_t stgVar5 = &macroDef13->arr[i_s];
			
			macroDef13->arr[i_s] = f_s.lam(f_s.env, stgVar5, v_s->arr[i_s], 0).number_t_value;
		}
	return macroDef13;
}

array_number_t TOP_LEVEL_linalg_vectorRange(card_t s, card_t e) {
	array_number_t macroDef14 = (array_number_t)malloc(sizeof(int) * 2);
	macroDef14->length=((e) - (s)) + (1);
	macroDef14->arr = (number_t*)malloc(sizeof(number_t) * ((e) - (s)) + (1));
		for(int i = 0; i < macroDef14->length; i++){
			
			macroDef14->arr[i] = (double)(((s)) + (i));
		}
	return macroDef14;
}typedef empty_env_t env_t_20;


value_t lambda20(env_t_20* env17, card_t i_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
vector_shape_t TOP_LEVEL_linalg_vectorRange_c(card_t s_c, card_t e_c) {
	env_t_20 env_t_20_value = make_empty_env(); closure_t closure19 = make_closure(lambda20, &env_t_20_value);
	return nested_shape_card_t(closure19.lam(closure19.env, 0).card_t_value, ((e_c) - (s_c)) + (1));
}
array_number_t TOP_LEVEL_linalg_vectorRange_s(storage_t stgVar15, card_t s_s, card_t e_s, card_t s_c, card_t e_c) {
	array_number_t macroDef21 = (array_number_t)stgVar15;
		macroDef21->length=((e_s) - (s_s)) + (1);
		macroDef21->arr=(number_t*)((char*)macroDef21 + VECTOR_HEADER_BYTES);
		for(int i_s = 0; i_s < macroDef21->length; i_s++){
			storage_t stgVar16 = &macroDef21->arr[i_s];
			
			macroDef21->arr[i_s] = (double)(((s_s)) + (i_s));
		}
	return macroDef21;
}

array_number_t TOP_LEVEL_linalg_vectorSlice(card_t size, index_t offset, array_number_t v) {
	array_number_t macroDef22 = (array_number_t)malloc(sizeof(int) * 2);
	macroDef22->length=size;
	macroDef22->arr = (number_t*)malloc(sizeof(number_t) * size);
		for(int i = 0; i < macroDef22->length; i++){
			
			macroDef22->arr[i] = v->arr[(i) + (offset)];
		}
	return macroDef22;
}typedef empty_env_t env_t_29;


value_t lambda29(env_t_29* env26, card_t i_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
vector_shape_t TOP_LEVEL_linalg_vectorSlice_c(card_t size_c, card_t offset_c, vector_shape_t v_c) {
	env_t_29 env_t_29_value = make_empty_env(); closure_t closure28 = make_closure(lambda29, &env_t_29_value);
	return nested_shape_card_t(closure28.lam(closure28.env, 0).card_t_value, size_c);
}
array_number_t TOP_LEVEL_linalg_vectorSlice_s(storage_t stgVar23, card_t size_s, index_t offset_s, array_number_t v_s, card_t size_c, card_t offset_c, vector_shape_t v_c) {
	array_number_t macroDef30 = (array_number_t)stgVar23;
		macroDef30->length=size_s;
		macroDef30->arr=(number_t*)((char*)macroDef30 + VECTOR_HEADER_BYTES);
		for(int i_s = 0; i_s < macroDef30->length; i_s++){
			storage_t stgVar24 = &macroDef30->arr[i_s];
			
			macroDef30->arr[i_s] = v_s->arr[(i_s) + (offset_s)];
		}
	return macroDef30;
}

array_array_number_t TOP_LEVEL_linalg_matrixMap(closure_t f, array_array_number_t m) {
	card_t macroDef31 = m->length;
	array_array_number_t macroDef32 = (array_array_number_t)malloc(sizeof(int) * 2);
	macroDef32->length=macroDef31;
	macroDef32->arr = (array_number_t*)malloc(sizeof(array_number_t) * macroDef31);
		for(int i = 0; i < macroDef32->length; i++){
			
			macroDef32->arr[i] = f.lam(f.env, m->arr[i]).array_number_t_value;
		}
	return macroDef32;
}typedef struct env_t_43 {
	matrix_shape_t m_c;
	closure_t f_c;
} env_t_43;
env_t_43 make_env_t_43(matrix_shape_t m_c,closure_t f_c) {
	env_t_43 env;
	env.m_c = m_c;
	env.f_c = f_c;
	return env;
}

value_t lambda43(env_t_43* env40, card_t i_c) {
	matrix_shape_t m_c39 = env40->m_c;
	closure_t f_c38 = env40->f_c;
	value_t res;
	res.vector_shape_t_value = f_c38.lam(f_c38.env, m_c39.elem).vector_shape_t_value;
	return res;
}
matrix_shape_t TOP_LEVEL_linalg_matrixMap_c(closure_t f_c, matrix_shape_t m_c) {
	env_t_43 env_t_43_value = make_env_t_43(m_c,f_c); closure_t closure42 = make_closure(lambda43, &env_t_43_value);
	return nested_shape_vector_shape_t(closure42.lam(closure42.env, 0).vector_shape_t_value, m_c.card);
}
array_array_number_t TOP_LEVEL_linalg_matrixMap_s(storage_t stgVar33, closure_t f_s, array_array_number_t m_s, closure_t f_c, matrix_shape_t m_c) {
	card_t macroDef44 = m_s->length;
	array_array_number_t macroDef46 = (array_array_number_t)stgVar33;
		macroDef46->length=macroDef44;
		macroDef46->arr=(array_number_t*)((char*)macroDef46 + VECTOR_HEADER_BYTES);
		for(int i_s = 0; i_s < macroDef46->length; i_s++){
			storage_t stgVar35 = &macroDef46->arr[i_s];
			array_number_t stgVar36 = malloc(width_vector_shape_t(m_c.elem));
	array_number_t macroDef45;
	macroDef45 = f_s.lam(f_s.env, stgVar35, m_s->arr[i_s], m_c.elem).array_number_t_value;
	free(stgVar36);
			macroDef46->arr[i_s] = macroDef45;
		}
	return macroDef46;
}

array_number_t TOP_LEVEL_linalg_vectorMap2(closure_t f, array_number_t v1, array_number_t v2) {
	card_t macroDef47 = v1->length;
	array_number_t macroDef48 = (array_number_t)malloc(sizeof(int) * 2);
	macroDef48->length=macroDef47;
	macroDef48->arr = (number_t*)malloc(sizeof(number_t) * macroDef47);
		for(int i = 0; i < macroDef48->length; i++){
			
			macroDef48->arr[i] = f.lam(f.env, v1->arr[i], v2->arr[i]).number_t_value;
		}
	return macroDef48;
}typedef empty_env_t env_t_59;


value_t lambda59(env_t_59* env56, card_t i_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
vector_shape_t TOP_LEVEL_linalg_vectorMap2_c(closure_t f_c, vector_shape_t v1_c, vector_shape_t v2_c) {
	env_t_59 env_t_59_value = make_empty_env(); closure_t closure58 = make_closure(lambda59, &env_t_59_value);
	return nested_shape_card_t(closure58.lam(closure58.env, 0).card_t_value, v1_c.card);
}
array_number_t TOP_LEVEL_linalg_vectorMap2_s(storage_t stgVar49, closure_t f_s, array_number_t v1_s, array_number_t v2_s, closure_t f_c, vector_shape_t v1_c, vector_shape_t v2_c) {
	card_t macroDef60 = v1_s->length;
	array_number_t macroDef61 = (array_number_t)stgVar49;
		macroDef61->length=macroDef60;
		macroDef61->arr=(number_t*)((char*)macroDef61 + VECTOR_HEADER_BYTES);
		for(int i_s = 0; i_s < macroDef61->length; i_s++){
			storage_t stgVar51 = &macroDef61->arr[i_s];
			
			macroDef61->arr[i_s] = f_s.lam(f_s.env, stgVar51, v1_s->arr[i_s], v2_s->arr[i_s], 0, 0).number_t_value;
		}
	return macroDef61;
}

array_array_number_t TOP_LEVEL_linalg_matrixMap2(closure_t f, array_array_number_t m1, array_array_number_t m2) {
	card_t macroDef62 = m1->length;
	array_array_number_t macroDef63 = (array_array_number_t)malloc(sizeof(int) * 2);
	macroDef63->length=macroDef62;
	macroDef63->arr = (array_number_t*)malloc(sizeof(array_number_t) * macroDef62);
		for(int i = 0; i < macroDef63->length; i++){
			
			macroDef63->arr[i] = f.lam(f.env, m1->arr[i], m2->arr[i]).array_number_t_value;
		}
	return macroDef63;
}typedef struct env_t_77 {
	matrix_shape_t m2_c;
	matrix_shape_t m1_c;
	closure_t f_c;
} env_t_77;
env_t_77 make_env_t_77(matrix_shape_t m2_c,matrix_shape_t m1_c,closure_t f_c) {
	env_t_77 env;
	env.m2_c = m2_c;
	env.m1_c = m1_c;
	env.f_c = f_c;
	return env;
}

value_t lambda77(env_t_77* env74, card_t i_c) {
	matrix_shape_t m2_c73 = env74->m2_c;
	matrix_shape_t m1_c72 = env74->m1_c;
	closure_t f_c71 = env74->f_c;
	value_t res;
	res.vector_shape_t_value = f_c71.lam(f_c71.env, m1_c72.elem, m2_c73.elem).vector_shape_t_value;
	return res;
}
matrix_shape_t TOP_LEVEL_linalg_matrixMap2_c(closure_t f_c, matrix_shape_t m1_c, matrix_shape_t m2_c) {
	env_t_77 env_t_77_value = make_env_t_77(m2_c,m1_c,f_c); closure_t closure76 = make_closure(lambda77, &env_t_77_value);
	return nested_shape_vector_shape_t(closure76.lam(closure76.env, 0).vector_shape_t_value, m1_c.card);
}
array_array_number_t TOP_LEVEL_linalg_matrixMap2_s(storage_t stgVar64, closure_t f_s, array_array_number_t m1_s, array_array_number_t m2_s, closure_t f_c, matrix_shape_t m1_c, matrix_shape_t m2_c) {
	card_t macroDef78 = m1_s->length;
	array_array_number_t macroDef81 = (array_array_number_t)stgVar64;
		macroDef81->length=macroDef78;
		macroDef81->arr=(array_number_t*)((char*)macroDef81 + VECTOR_HEADER_BYTES);
		for(int i_s = 0; i_s < macroDef81->length; i_s++){
			storage_t stgVar66 = &macroDef81->arr[i_s];
			array_number_t stgVar68 = malloc(width_vector_shape_t(m2_c.elem));
	array_number_t macroDef80;array_number_t stgVar67 = malloc(width_vector_shape_t(m1_c.elem));
	array_number_t macroDef79;
	macroDef79 = f_s.lam(f_s.env, stgVar66, m1_s->arr[i_s], m2_s->arr[i_s], m1_c.elem, m2_c.elem).array_number_t_value;
	free(stgVar67);
	macroDef80 = macroDef79;
	free(stgVar68);
			macroDef81->arr[i_s] = macroDef80;
		}
	return macroDef81;
}

array_array_array_number_t TOP_LEVEL_linalg_matrix3DMap2(closure_t f, array_array_array_number_t m1, array_array_array_number_t m2) {
	card_t macroDef82 = m1->length;
	array_array_array_number_t macroDef83 = (array_array_array_number_t)malloc(sizeof(int) * 2);
	macroDef83->length=macroDef82;
	macroDef83->arr = (array_array_number_t*)malloc(sizeof(array_array_number_t) * macroDef82);
		for(int i = 0; i < macroDef83->length; i++){
			
			macroDef83->arr[i] = f.lam(f.env, m1->arr[i], m2->arr[i]).array_array_number_t_value;
		}
	return macroDef83;
}typedef struct env_t_97 {
	matrix3d_shape_t m2_c;
	matrix3d_shape_t m1_c;
	closure_t f_c;
} env_t_97;
env_t_97 make_env_t_97(matrix3d_shape_t m2_c,matrix3d_shape_t m1_c,closure_t f_c) {
	env_t_97 env;
	env.m2_c = m2_c;
	env.m1_c = m1_c;
	env.f_c = f_c;
	return env;
}

value_t lambda97(env_t_97* env94, card_t i_c) {
	matrix3d_shape_t m2_c93 = env94->m2_c;
	matrix3d_shape_t m1_c92 = env94->m1_c;
	closure_t f_c91 = env94->f_c;
	value_t res;
	res.matrix_shape_t_value = f_c91.lam(f_c91.env, m1_c92.elem, m2_c93.elem).matrix_shape_t_value;
	return res;
}
matrix3d_shape_t TOP_LEVEL_linalg_matrix3DMap2_c(closure_t f_c, matrix3d_shape_t m1_c, matrix3d_shape_t m2_c) {
	env_t_97 env_t_97_value = make_env_t_97(m2_c,m1_c,f_c); closure_t closure96 = make_closure(lambda97, &env_t_97_value);
	return nested_shape_matrix_shape_t(closure96.lam(closure96.env, 0).matrix_shape_t_value, m1_c.card);
}
array_array_array_number_t TOP_LEVEL_linalg_matrix3DMap2_s(storage_t stgVar84, closure_t f_s, array_array_array_number_t m1_s, array_array_array_number_t m2_s, closure_t f_c, matrix3d_shape_t m1_c, matrix3d_shape_t m2_c) {
	card_t macroDef98 = m1_s->length;
	array_array_array_number_t macroDef101 = (array_array_array_number_t)stgVar84;
		macroDef101->length=macroDef98;
		macroDef101->arr=(array_array_number_t*)((char*)macroDef101 + VECTOR_HEADER_BYTES);
		for(int i_s = 0; i_s < macroDef101->length; i_s++){
			storage_t stgVar86 = &macroDef101->arr[i_s];
			array_number_t stgVar88 = malloc(width_matrix_shape_t(m2_c.elem));
	array_array_number_t macroDef100;array_number_t stgVar87 = malloc(width_matrix_shape_t(m1_c.elem));
	array_array_number_t macroDef99;
	macroDef99 = f_s.lam(f_s.env, stgVar86, m1_s->arr[i_s], m2_s->arr[i_s], m1_c.elem, m2_c.elem).array_array_number_t_value;
	free(stgVar87);
	macroDef100 = macroDef99;
	free(stgVar88);
			macroDef101->arr[i_s] = macroDef100;
		}
	return macroDef101;
}

array_array_number_t TOP_LEVEL_linalg_vectorMapToMatrix(closure_t f, array_number_t arr) {
	card_t macroDef102 = arr->length;
	array_array_number_t macroDef103 = (array_array_number_t)malloc(sizeof(int) * 2);
	macroDef103->length=macroDef102;
	macroDef103->arr = (array_number_t*)malloc(sizeof(array_number_t) * macroDef102);
		for(int i = 0; i < macroDef103->length; i++){
			
			macroDef103->arr[i] = f.lam(f.env, arr->arr[i]).array_number_t_value;
		}
	return macroDef103;
}typedef struct env_t_113 {
	closure_t f_c;
} env_t_113;
env_t_113 make_env_t_113(closure_t f_c) {
	env_t_113 env;
	env.f_c = f_c;
	return env;
}

value_t lambda113(env_t_113* env110, card_t i_c) {
	closure_t f_c109 = env110->f_c;
	value_t res;
	res.vector_shape_t_value = f_c109.lam(f_c109.env, 0).vector_shape_t_value;
	return res;
}
matrix_shape_t TOP_LEVEL_linalg_vectorMapToMatrix_c(closure_t f_c, vector_shape_t arr_c) {
	env_t_113 env_t_113_value = make_env_t_113(f_c); closure_t closure112 = make_closure(lambda113, &env_t_113_value);
	return nested_shape_vector_shape_t(closure112.lam(closure112.env, 0).vector_shape_t_value, arr_c.card);
}
array_array_number_t TOP_LEVEL_linalg_vectorMapToMatrix_s(storage_t stgVar104, closure_t f_s, array_number_t arr_s, closure_t f_c, vector_shape_t arr_c) {
	card_t macroDef114 = arr_s->length;
	array_array_number_t macroDef115 = (array_array_number_t)stgVar104;
		macroDef115->length=macroDef114;
		macroDef115->arr=(array_number_t*)((char*)macroDef115 + VECTOR_HEADER_BYTES);
		for(int i_s = 0; i_s < macroDef115->length; i_s++){
			storage_t stgVar106 = &macroDef115->arr[i_s];
			
			macroDef115->arr[i_s] = f_s.lam(f_s.env, stgVar106, arr_s->arr[i_s], 0).array_number_t_value;
		}
	return macroDef115;
}

array_array_array_number_t TOP_LEVEL_linalg_vectorMapToMatrix3D(closure_t f, array_number_t arr) {
	card_t macroDef116 = arr->length;
	array_array_array_number_t macroDef117 = (array_array_array_number_t)malloc(sizeof(int) * 2);
	macroDef117->length=macroDef116;
	macroDef117->arr = (array_array_number_t*)malloc(sizeof(array_array_number_t) * macroDef116);
		for(int i = 0; i < macroDef117->length; i++){
			
			macroDef117->arr[i] = f.lam(f.env, arr->arr[i]).array_array_number_t_value;
		}
	return macroDef117;
}typedef struct env_t_127 {
	closure_t f_c;
} env_t_127;
env_t_127 make_env_t_127(closure_t f_c) {
	env_t_127 env;
	env.f_c = f_c;
	return env;
}

value_t lambda127(env_t_127* env124, card_t i_c) {
	closure_t f_c123 = env124->f_c;
	value_t res;
	res.matrix_shape_t_value = f_c123.lam(f_c123.env, 0).matrix_shape_t_value;
	return res;
}
matrix3d_shape_t TOP_LEVEL_linalg_vectorMapToMatrix3D_c(closure_t f_c, vector_shape_t arr_c) {
	env_t_127 env_t_127_value = make_env_t_127(f_c); closure_t closure126 = make_closure(lambda127, &env_t_127_value);
	return nested_shape_matrix_shape_t(closure126.lam(closure126.env, 0).matrix_shape_t_value, arr_c.card);
}
array_array_array_number_t TOP_LEVEL_linalg_vectorMapToMatrix3D_s(storage_t stgVar118, closure_t f_s, array_number_t arr_s, closure_t f_c, vector_shape_t arr_c) {
	card_t macroDef128 = arr_s->length;
	array_array_array_number_t macroDef129 = (array_array_array_number_t)stgVar118;
		macroDef129->length=macroDef128;
		macroDef129->arr=(array_array_number_t*)((char*)macroDef129 + VECTOR_HEADER_BYTES);
		for(int i_s = 0; i_s < macroDef129->length; i_s++){
			storage_t stgVar120 = &macroDef129->arr[i_s];
			
			macroDef129->arr[i_s] = f_s.lam(f_s.env, stgVar120, arr_s->arr[i_s], 0).array_array_number_t_value;
		}
	return macroDef129;
}

number_t TOP_LEVEL_linalg_iterateNumber(closure_t f, number_t z, card_t s, card_t e) {
	number_t macroDef130 = z;
	for(int cur_idx = 0; cur_idx < TOP_LEVEL_linalg_vectorRange(s, e)->length; cur_idx++){
		number_t cur = TOP_LEVEL_linalg_vectorRange(s, e)->arr[cur_idx];
		
		macroDef130 = f.lam(f.env, macroDef130, (int)(cur)).number_t_value;
	}
	return macroDef130;
}
card_t TOP_LEVEL_linalg_iterateNumber_c(closure_t f_c, card_t z_c, card_t s_c, card_t e_c) {
	
	return 0;
}
number_t TOP_LEVEL_linalg_iterateNumber_s(storage_t stgVar131, closure_t f_s, number_t z_s, card_t s_s, card_t e_s, closure_t f_c, card_t z_c, card_t s_c, card_t e_c) {
	number_t macroDef137 = z_s;
	array_number_t cur_s_range = TOP_LEVEL_linalg_vectorRange_s(empty_storage, s_s, e_s, s_c, e_c);
	storage_t stgVar132 = stgVar131;
	for(int cur_s_idx = 0; cur_s_idx < cur_s_range->length; cur_s_idx++){
		number_t cur_s = cur_s_range->arr[cur_s_idx];
		
		macroDef137 = f_s.lam(f_s.env, stgVar132, macroDef137, (int)(cur_s), 0, 0).number_t_value;
	}
	return macroDef137;
}

array_number_t TOP_LEVEL_linalg_iterateVector(closure_t f, array_number_t z, card_t s, card_t e) {
	array_number_t macroDef138 = z;
	for(int cur_idx = 0; cur_idx < TOP_LEVEL_linalg_vectorRange(s, e)->length; cur_idx++){
		number_t cur = TOP_LEVEL_linalg_vectorRange(s, e)->arr[cur_idx];
		
		macroDef138 = f.lam(f.env, macroDef138, (int)(cur)).array_number_t_value;
	}
	return macroDef138;
}
vector_shape_t TOP_LEVEL_linalg_iterateVector_c(closure_t f_c, vector_shape_t z_c, card_t s_c, card_t e_c) {
	
	return z_c;
}
array_number_t TOP_LEVEL_linalg_iterateVector_s(storage_t stgVar139, closure_t f_s, array_number_t z_s, card_t s_s, card_t e_s, closure_t f_c, vector_shape_t z_c, card_t s_c, card_t e_c) {
	array_number_t macroDef145 = z_s;
	array_number_t cur_s_range = TOP_LEVEL_linalg_vectorRange_s(empty_storage, s_s, e_s, s_c, e_c);
	storage_t stgVar140 = stgVar139;
	for(int cur_s_idx = 0; cur_s_idx < cur_s_range->length; cur_s_idx++){
		number_t cur_s = cur_s_range->arr[cur_s_idx];
		
		macroDef145 = f_s.lam(f_s.env, stgVar140, macroDef145, (int)(cur_s), z_c, 0).array_number_t_value;
	}
	return macroDef145;
}

array_array_number_t TOP_LEVEL_linalg_iterateMatrix(closure_t f, array_array_number_t z, card_t s, card_t e) {
	array_array_number_t macroDef146 = z;
	for(int cur_idx = 0; cur_idx < TOP_LEVEL_linalg_vectorRange(s, e)->length; cur_idx++){
		number_t cur = TOP_LEVEL_linalg_vectorRange(s, e)->arr[cur_idx];
		
		macroDef146 = f.lam(f.env, macroDef146, (int)(cur)).array_array_number_t_value;
	}
	return macroDef146;
}
matrix_shape_t TOP_LEVEL_linalg_iterateMatrix_c(closure_t f_c, matrix_shape_t z_c, card_t s_c, card_t e_c) {
	
	return z_c;
}
array_array_number_t TOP_LEVEL_linalg_iterateMatrix_s(storage_t stgVar147, closure_t f_s, array_array_number_t z_s, card_t s_s, card_t e_s, closure_t f_c, matrix_shape_t z_c, card_t s_c, card_t e_c) {
	array_array_number_t macroDef153 = z_s;
	array_number_t cur_s_range = TOP_LEVEL_linalg_vectorRange_s(empty_storage, s_s, e_s, s_c, e_c);
	storage_t stgVar148 = stgVar147;
	for(int cur_s_idx = 0; cur_s_idx < cur_s_range->length; cur_s_idx++){
		number_t cur_s = cur_s_range->arr[cur_s_idx];
		
		macroDef153 = f_s.lam(f_s.env, stgVar148, macroDef153, (int)(cur_s), z_c, 0).array_array_number_t_value;
	}
	return macroDef153;
}

array_array_array_number_t TOP_LEVEL_linalg_iterateMatrix3D(closure_t f, array_array_array_number_t z, card_t s, card_t e) {
	array_array_array_number_t macroDef154 = z;
	for(int cur_idx = 0; cur_idx < TOP_LEVEL_linalg_vectorRange(s, e)->length; cur_idx++){
		number_t cur = TOP_LEVEL_linalg_vectorRange(s, e)->arr[cur_idx];
		
		macroDef154 = f.lam(f.env, macroDef154, (int)(cur)).array_array_array_number_t_value;
	}
	return macroDef154;
}
matrix3d_shape_t TOP_LEVEL_linalg_iterateMatrix3D_c(closure_t f_c, matrix3d_shape_t z_c, card_t s_c, card_t e_c) {
	
	return z_c;
}
array_array_array_number_t TOP_LEVEL_linalg_iterateMatrix3D_s(storage_t stgVar155, closure_t f_s, array_array_array_number_t z_s, card_t s_s, card_t e_s, closure_t f_c, matrix3d_shape_t z_c, card_t s_c, card_t e_c) {
	array_array_array_number_t macroDef161 = z_s;
	array_number_t cur_s_range = TOP_LEVEL_linalg_vectorRange_s(empty_storage, s_s, e_s, s_c, e_c);
	storage_t stgVar156 = stgVar155;
	for(int cur_s_idx = 0; cur_s_idx < cur_s_range->length; cur_s_idx++){
		number_t cur_s = cur_s_range->arr[cur_s_idx];
		
		macroDef161 = f_s.lam(f_s.env, stgVar156, macroDef161, (int)(cur_s), z_c, 0).array_array_array_number_t_value;
	}
	return macroDef161;
}

number_t TOP_LEVEL_linalg_arraySum(array_number_t arr) {
	number_t macroDef162 = 0;
	for(int cur_idx = 0; cur_idx < arr->length; cur_idx++){
		number_t cur = arr->arr[cur_idx];
		
		macroDef162 = (macroDef162) + (cur);
	}
	return macroDef162;
}
card_t TOP_LEVEL_linalg_arraySum_c(vector_shape_t arr_c) {
	
	return 0;
}
number_t TOP_LEVEL_linalg_arraySum_s(storage_t stgVar163, array_number_t arr_s, vector_shape_t arr_c) {
	number_t macroDef165 = 0;
	array_number_t cur_s_range = arr_s;
	storage_t stgVar164 = stgVar163;
	for(int cur_s_idx = 0; cur_s_idx < cur_s_range->length; cur_s_idx++){
		number_t cur_s = cur_s_range->arr[cur_s_idx];
		
		macroDef165 = (macroDef165) + (cur_s);
	}
	return macroDef165;
}

number_t TOP_LEVEL_linalg_arrayMax(array_number_t arr) {
	number_t macroDef166 = -1000;
	for(int cur_idx = 0; cur_idx < arr->length; cur_idx++){
		number_t cur = arr->arr[cur_idx];
		number_t ite167 = 0;
	if((macroDef166) > (cur)) {
		
		ite167 = macroDef166;
	} else {
		
		ite167 = cur;
	}
		macroDef166 = ite167;
	}
	return macroDef166;
}
card_t TOP_LEVEL_linalg_arrayMax_c(vector_shape_t arr_c) {
	
	return 0;
}
number_t TOP_LEVEL_linalg_arrayMax_s(storage_t stgVar168, array_number_t arr_s, vector_shape_t arr_c) {
	number_t macroDef170 = -1000;
	array_number_t cur_s_range = arr_s;
	storage_t stgVar169 = stgVar168;
	for(int cur_s_idx = 0; cur_s_idx < cur_s_range->length; cur_s_idx++){
		number_t cur_s = cur_s_range->arr[cur_s_idx];
		number_t ite171 = 0;
	if((macroDef170) > (cur_s)) {
		
		ite171 = macroDef170;
	} else {
		
		ite171 = cur_s;
	}
		macroDef170 = ite171;
	}
	return macroDef170;
}
typedef struct env_t_176 {
	number_t y;
} env_t_176;
env_t_176 make_env_t_176(number_t y) {
	env_t_176 env;
	env.y = y;
	return env;
}

value_t lambda176(env_t_176* env173, number_t a) {
	number_t y172 = env173->y;
	value_t res;
	res.number_t_value = (a) * (y172);
	return res;
}
array_number_t TOP_LEVEL_linalg_mult_by_scalar(array_number_t x, number_t y) {
	env_t_176 env_t_176_value = make_env_t_176(y); closure_t closure175 = make_closure(lambda176, &env_t_176_value);
	return TOP_LEVEL_linalg_vectorMap(closure175, x);
}typedef empty_env_t env_t_184;


value_t lambda184(env_t_184* env181, card_t a_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
vector_shape_t TOP_LEVEL_linalg_mult_by_scalar_c(vector_shape_t x_c, card_t y_c) {
	env_t_184 env_t_184_value = make_empty_env(); closure_t closure183 = make_closure(lambda184, &env_t_184_value);
	return TOP_LEVEL_linalg_vectorMap_c(closure183, x_c);
}typedef struct env_t_192 {
	number_t y_s;
} env_t_192;
env_t_192 make_env_t_192(number_t y_s) {
	env_t_192 env;
	env.y_s = y_s;
	return env;
}

value_t lambda192(env_t_192* env186, storage_t stgVar180, number_t a_s, card_t a_c) {
	number_t y_s185 = env186->y_s;
	value_t res;
	res.number_t_value = (a_s) * (y_s185);
	return res;
}
typedef empty_env_t env_t_193;


value_t lambda193(env_t_193* env189, card_t a_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
array_number_t TOP_LEVEL_linalg_mult_by_scalar_s(storage_t stgVar177, array_number_t x_s, number_t y_s, vector_shape_t x_c, card_t y_c) {
	env_t_192 env_t_192_value = make_env_t_192(y_s); closure_t closure188 = make_closure(lambda192, &env_t_192_value);
	env_t_193 env_t_193_value = make_empty_env(); closure_t closure191 = make_closure(lambda193, &env_t_193_value);
	return TOP_LEVEL_linalg_vectorMap_s(stgVar177, closure188, x_s, closure191, x_c);
}

array_number_t TOP_LEVEL_linalg_cross(array_number_t a, array_number_t b) {
	array_number_t array194 = (array_number_t)malloc(sizeof(int) * 2);
	array194->length=3;
	array194->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array194->arr[0] = ((a->arr[1]) * (b->arr[2])) - ((a->arr[2]) * (b->arr[1]));
	array194->arr[1] = ((a->arr[2]) * (b->arr[0])) - ((a->arr[0]) * (b->arr[2]));
	array194->arr[2] = ((a->arr[0]) * (b->arr[1])) - ((a->arr[1]) * (b->arr[0]));;
	return array194;
}
vector_shape_t TOP_LEVEL_linalg_cross_c(vector_shape_t a_c, vector_shape_t b_c) {
	
	return nested_shape_card_t(0, 3);
}
array_number_t TOP_LEVEL_linalg_cross_s(storage_t stgVar195, array_number_t a_s, array_number_t b_s, vector_shape_t a_c, vector_shape_t b_c) {
	array_number_t macroDef211 = (array_number_t)stgVar195;
	macroDef211->length=3;
	macroDef211->arr=(number_t*)((char*)stgVar195 + VECTOR_HEADER_BYTES);
	macroDef211->arr[0] = ((a_s->arr[1]) * (b_s->arr[2])) - ((a_s->arr[2]) * (b_s->arr[1]));
	macroDef211->arr[1] = ((a_s->arr[2]) * (b_s->arr[0])) - ((a_s->arr[0]) * (b_s->arr[2]));
	macroDef211->arr[2] = ((a_s->arr[0]) * (b_s->arr[1])) - ((a_s->arr[1]) * (b_s->arr[0]));;
	return macroDef211;
}
typedef empty_env_t env_t_215;


value_t lambda215(env_t_215* env212, number_t x, number_t y) {
	
	value_t res;
	res.number_t_value = (x) + (y);
	return res;
}
array_number_t TOP_LEVEL_linalg_add_vec(array_number_t x, array_number_t y) {
	env_t_215 env_t_215_value = make_empty_env(); closure_t closure214 = make_closure(lambda215, &env_t_215_value);
	return TOP_LEVEL_linalg_vectorMap2(closure214, x, y);
}typedef empty_env_t env_t_224;


value_t lambda224(env_t_224* env221, card_t x_c, card_t y_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
vector_shape_t TOP_LEVEL_linalg_add_vec_c(vector_shape_t x_c, vector_shape_t y_c) {
	env_t_224 env_t_224_value = make_empty_env(); closure_t closure223 = make_closure(lambda224, &env_t_224_value);
	return TOP_LEVEL_linalg_vectorMap2_c(closure223, x_c, y_c);
}typedef empty_env_t env_t_231;


value_t lambda231(env_t_231* env225, storage_t stgVar220, number_t x_s, number_t y_s, card_t x_c, card_t y_c) {
	
	value_t res;
	res.number_t_value = (x_s) + (y_s);
	return res;
}
typedef empty_env_t env_t_232;


value_t lambda232(env_t_232* env228, card_t x_c, card_t y_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
array_number_t TOP_LEVEL_linalg_add_vec_s(storage_t stgVar216, array_number_t x_s, array_number_t y_s, vector_shape_t x_c, vector_shape_t y_c) {
	env_t_231 env_t_231_value = make_empty_env(); closure_t closure227 = make_closure(lambda231, &env_t_231_value);
	env_t_232 env_t_232_value = make_empty_env(); closure_t closure230 = make_closure(lambda232, &env_t_232_value);
	return TOP_LEVEL_linalg_vectorMap2_s(stgVar216, closure227, x_s, y_s, closure230, x_c, y_c);
}
typedef empty_env_t env_t_236;


value_t lambda236(env_t_236* env233, number_t x, number_t y) {
	
	value_t res;
	res.number_t_value = (x) * (y);
	return res;
}
array_number_t TOP_LEVEL_linalg_mult_vec_elementwise(array_number_t x, array_number_t y) {
	env_t_236 env_t_236_value = make_empty_env(); closure_t closure235 = make_closure(lambda236, &env_t_236_value);
	return TOP_LEVEL_linalg_vectorMap2(closure235, x, y);
}typedef empty_env_t env_t_245;


value_t lambda245(env_t_245* env242, card_t x_c, card_t y_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
vector_shape_t TOP_LEVEL_linalg_mult_vec_elementwise_c(vector_shape_t x_c, vector_shape_t y_c) {
	env_t_245 env_t_245_value = make_empty_env(); closure_t closure244 = make_closure(lambda245, &env_t_245_value);
	return TOP_LEVEL_linalg_vectorMap2_c(closure244, x_c, y_c);
}typedef empty_env_t env_t_252;


value_t lambda252(env_t_252* env246, storage_t stgVar241, number_t x_s, number_t y_s, card_t x_c, card_t y_c) {
	
	value_t res;
	res.number_t_value = (x_s) * (y_s);
	return res;
}
typedef empty_env_t env_t_253;


value_t lambda253(env_t_253* env249, card_t x_c, card_t y_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
array_number_t TOP_LEVEL_linalg_mult_vec_elementwise_s(storage_t stgVar237, array_number_t x_s, array_number_t y_s, vector_shape_t x_c, vector_shape_t y_c) {
	env_t_252 env_t_252_value = make_empty_env(); closure_t closure248 = make_closure(lambda252, &env_t_252_value);
	env_t_253 env_t_253_value = make_empty_env(); closure_t closure251 = make_closure(lambda253, &env_t_253_value);
	return TOP_LEVEL_linalg_vectorMap2_s(stgVar237, closure248, x_s, y_s, closure251, x_c, y_c);
}

array_number_t TOP_LEVEL_linalg_add_vec3(array_number_t x, array_number_t y, array_number_t z) {
	
	return TOP_LEVEL_linalg_add_vec(TOP_LEVEL_linalg_add_vec(x, y), z);
}
vector_shape_t TOP_LEVEL_linalg_add_vec3_c(vector_shape_t x_c, vector_shape_t y_c, vector_shape_t z_c) {
	
	return TOP_LEVEL_linalg_add_vec_c(TOP_LEVEL_linalg_add_vec_c(x_c, y_c), z_c);
}
array_number_t TOP_LEVEL_linalg_add_vec3_s(storage_t stgVar254, array_number_t x_s, array_number_t y_s, array_number_t z_s, vector_shape_t x_c, vector_shape_t y_c, vector_shape_t z_c) {
	array_number_t stgVar255 = malloc(width_vector_shape_t(TOP_LEVEL_linalg_add_vec_c(x_c, y_c)));
	array_number_t macroDef259;
	macroDef259 = TOP_LEVEL_linalg_add_vec_s(stgVar254, TOP_LEVEL_linalg_add_vec_s(stgVar255, x_s, y_s, x_c, y_c), z_s, TOP_LEVEL_linalg_add_vec_c(x_c, y_c), z_c);
	free(stgVar255);
	return macroDef259;
}
typedef empty_env_t env_t_263;


value_t lambda263(env_t_263* env260, number_t x, number_t y) {
	
	value_t res;
	res.number_t_value = (x) - (y);
	return res;
}
array_number_t TOP_LEVEL_linalg_sub_vec(array_number_t x, array_number_t y) {
	env_t_263 env_t_263_value = make_empty_env(); closure_t closure262 = make_closure(lambda263, &env_t_263_value);
	return TOP_LEVEL_linalg_vectorMap2(closure262, x, y);
}typedef empty_env_t env_t_272;


value_t lambda272(env_t_272* env269, card_t x_c, card_t y_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
vector_shape_t TOP_LEVEL_linalg_sub_vec_c(vector_shape_t x_c, vector_shape_t y_c) {
	env_t_272 env_t_272_value = make_empty_env(); closure_t closure271 = make_closure(lambda272, &env_t_272_value);
	return TOP_LEVEL_linalg_vectorMap2_c(closure271, x_c, y_c);
}typedef empty_env_t env_t_279;


value_t lambda279(env_t_279* env273, storage_t stgVar268, number_t x_s, number_t y_s, card_t x_c, card_t y_c) {
	
	value_t res;
	res.number_t_value = (x_s) - (y_s);
	return res;
}
typedef empty_env_t env_t_280;


value_t lambda280(env_t_280* env276, card_t x_c, card_t y_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
array_number_t TOP_LEVEL_linalg_sub_vec_s(storage_t stgVar264, array_number_t x_s, array_number_t y_s, vector_shape_t x_c, vector_shape_t y_c) {
	env_t_279 env_t_279_value = make_empty_env(); closure_t closure275 = make_closure(lambda279, &env_t_279_value);
	env_t_280 env_t_280_value = make_empty_env(); closure_t closure278 = make_closure(lambda280, &env_t_280_value);
	return TOP_LEVEL_linalg_vectorMap2_s(stgVar264, closure275, x_s, y_s, closure278, x_c, y_c);
}
typedef empty_env_t env_t_284;


value_t lambda284(env_t_284* env281, array_number_t x, array_number_t y) {
	
	value_t res;
	res.array_number_t_value = TOP_LEVEL_linalg_add_vec(x, y);
	return res;
}
array_array_number_t TOP_LEVEL_linalg_matrixAdd(array_array_number_t x, array_array_number_t y) {
	env_t_284 env_t_284_value = make_empty_env(); closure_t closure283 = make_closure(lambda284, &env_t_284_value);
	return TOP_LEVEL_linalg_matrixMap2(closure283, x, y);
}typedef empty_env_t env_t_295;


value_t lambda295(env_t_295* env292, vector_shape_t x_c, vector_shape_t y_c) {
	
	value_t res;
	res.vector_shape_t_value = TOP_LEVEL_linalg_add_vec_c(x_c, y_c);
	return res;
}
matrix_shape_t TOP_LEVEL_linalg_matrixAdd_c(matrix_shape_t x_c, matrix_shape_t y_c) {
	env_t_295 env_t_295_value = make_empty_env(); closure_t closure294 = make_closure(lambda295, &env_t_295_value);
	return TOP_LEVEL_linalg_matrixMap2_c(closure294, x_c, y_c);
}typedef empty_env_t env_t_302;


value_t lambda302(env_t_302* env296, storage_t stgVar289, array_number_t x_s, array_number_t y_s, vector_shape_t x_c, vector_shape_t y_c) {
	
	value_t res;
	res.array_number_t_value = TOP_LEVEL_linalg_add_vec_s(stgVar289, x_s, y_s, x_c, y_c);
	return res;
}
typedef empty_env_t env_t_303;


value_t lambda303(env_t_303* env299, vector_shape_t x_c, vector_shape_t y_c) {
	
	value_t res;
	res.vector_shape_t_value = TOP_LEVEL_linalg_add_vec_c(x_c, y_c);
	return res;
}
array_array_number_t TOP_LEVEL_linalg_matrixAdd_s(storage_t stgVar285, array_array_number_t x_s, array_array_number_t y_s, matrix_shape_t x_c, matrix_shape_t y_c) {
	env_t_302 env_t_302_value = make_empty_env(); closure_t closure298 = make_closure(lambda302, &env_t_302_value);
	env_t_303 env_t_303_value = make_empty_env(); closure_t closure301 = make_closure(lambda303, &env_t_303_value);
	return TOP_LEVEL_linalg_matrixMap2_s(stgVar285, closure298, x_s, y_s, closure301, x_c, y_c);
}
typedef empty_env_t env_t_307;


value_t lambda307(env_t_307* env304, array_number_t x, array_number_t y) {
	
	value_t res;
	res.array_number_t_value = TOP_LEVEL_linalg_mult_vec_elementwise(x, y);
	return res;
}
array_array_number_t TOP_LEVEL_linalg_matrixMultElementwise(array_array_number_t x, array_array_number_t y) {
	env_t_307 env_t_307_value = make_empty_env(); closure_t closure306 = make_closure(lambda307, &env_t_307_value);
	return TOP_LEVEL_linalg_matrixMap2(closure306, x, y);
}typedef empty_env_t env_t_318;


value_t lambda318(env_t_318* env315, vector_shape_t x_c, vector_shape_t y_c) {
	
	value_t res;
	res.vector_shape_t_value = TOP_LEVEL_linalg_mult_vec_elementwise_c(x_c, y_c);
	return res;
}
matrix_shape_t TOP_LEVEL_linalg_matrixMultElementwise_c(matrix_shape_t x_c, matrix_shape_t y_c) {
	env_t_318 env_t_318_value = make_empty_env(); closure_t closure317 = make_closure(lambda318, &env_t_318_value);
	return TOP_LEVEL_linalg_matrixMap2_c(closure317, x_c, y_c);
}typedef empty_env_t env_t_325;


value_t lambda325(env_t_325* env319, storage_t stgVar312, array_number_t x_s, array_number_t y_s, vector_shape_t x_c, vector_shape_t y_c) {
	
	value_t res;
	res.array_number_t_value = TOP_LEVEL_linalg_mult_vec_elementwise_s(stgVar312, x_s, y_s, x_c, y_c);
	return res;
}
typedef empty_env_t env_t_326;


value_t lambda326(env_t_326* env322, vector_shape_t x_c, vector_shape_t y_c) {
	
	value_t res;
	res.vector_shape_t_value = TOP_LEVEL_linalg_mult_vec_elementwise_c(x_c, y_c);
	return res;
}
array_array_number_t TOP_LEVEL_linalg_matrixMultElementwise_s(storage_t stgVar308, array_array_number_t x_s, array_array_number_t y_s, matrix_shape_t x_c, matrix_shape_t y_c) {
	env_t_325 env_t_325_value = make_empty_env(); closure_t closure321 = make_closure(lambda325, &env_t_325_value);
	env_t_326 env_t_326_value = make_empty_env(); closure_t closure324 = make_closure(lambda326, &env_t_326_value);
	return TOP_LEVEL_linalg_matrixMap2_s(stgVar308, closure321, x_s, y_s, closure324, x_c, y_c);
}
typedef empty_env_t env_t_330;


value_t lambda330(env_t_330* env327, number_t x1) {
	
	value_t res;
	res.number_t_value = (x1) * (x1);
	return res;
}
number_t TOP_LEVEL_linalg_sqnorm(array_number_t x) {
	env_t_330 env_t_330_value = make_empty_env(); closure_t closure329 = make_closure(lambda330, &env_t_330_value);
	return TOP_LEVEL_linalg_arraySum(TOP_LEVEL_linalg_vectorMap(closure329, x));
}
card_t TOP_LEVEL_linalg_sqnorm_c(vector_shape_t x_c) {
	
	return 0;
}typedef empty_env_t env_t_349;


value_t lambda349(env_t_349* env336, card_t x1_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef empty_env_t env_t_350;


value_t lambda350(env_t_350* env339, storage_t stgVar335, number_t x1_s, card_t x1_c) {
	
	value_t res;
	res.number_t_value = (x1_s) * (x1_s);
	return res;
}
typedef empty_env_t env_t_351;


value_t lambda351(env_t_351* env342, card_t x1_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef empty_env_t env_t_352;


value_t lambda352(env_t_352* env345, card_t x1_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
number_t TOP_LEVEL_linalg_sqnorm_s(storage_t stgVar331, array_number_t x_s, vector_shape_t x_c) {
	env_t_349 env_t_349_value = make_empty_env(); closure_t closure338 = make_closure(lambda349, &env_t_349_value);
	array_number_t stgVar332 = malloc(width_vector_shape_t(TOP_LEVEL_linalg_vectorMap_c(closure338, x_c)));
	number_t macroDef348;env_t_350 env_t_350_value = make_empty_env(); closure_t closure341 = make_closure(lambda350, &env_t_350_value);
	env_t_351 env_t_351_value = make_empty_env(); closure_t closure344 = make_closure(lambda351, &env_t_351_value);
	env_t_352 env_t_352_value = make_empty_env(); closure_t closure347 = make_closure(lambda352, &env_t_352_value);
	macroDef348 = TOP_LEVEL_linalg_arraySum_s(stgVar331, TOP_LEVEL_linalg_vectorMap_s(stgVar332, closure341, x_s, closure344, x_c), TOP_LEVEL_linalg_vectorMap_c(closure347, x_c));
	free(stgVar332);
	return macroDef348;
}
typedef empty_env_t env_t_356;


value_t lambda356(env_t_356* env353, number_t x, number_t y) {
	
	value_t res;
	res.number_t_value = (x) * (y);
	return res;
}
number_t TOP_LEVEL_linalg_dot_prod(array_number_t x, array_number_t y) {
	env_t_356 env_t_356_value = make_empty_env(); closure_t closure355 = make_closure(lambda356, &env_t_356_value);
	return TOP_LEVEL_linalg_arraySum(TOP_LEVEL_linalg_vectorMap2(closure355, x, y));
}
card_t TOP_LEVEL_linalg_dot_prod_c(vector_shape_t x_c, vector_shape_t y_c) {
	
	return 0;
}typedef empty_env_t env_t_376;


value_t lambda376(env_t_376* env363, card_t x_c, card_t y_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef empty_env_t env_t_377;


value_t lambda377(env_t_377* env366, storage_t stgVar362, number_t x_s, number_t y_s, card_t x_c, card_t y_c) {
	
	value_t res;
	res.number_t_value = (x_s) * (y_s);
	return res;
}
typedef empty_env_t env_t_378;


value_t lambda378(env_t_378* env369, card_t x_c, card_t y_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef empty_env_t env_t_379;


value_t lambda379(env_t_379* env372, card_t x_c, card_t y_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
number_t TOP_LEVEL_linalg_dot_prod_s(storage_t stgVar357, array_number_t x_s, array_number_t y_s, vector_shape_t x_c, vector_shape_t y_c) {
	env_t_376 env_t_376_value = make_empty_env(); closure_t closure365 = make_closure(lambda376, &env_t_376_value);
	array_number_t stgVar358 = malloc(width_vector_shape_t(TOP_LEVEL_linalg_vectorMap2_c(closure365, x_c, y_c)));
	number_t macroDef375;env_t_377 env_t_377_value = make_empty_env(); closure_t closure368 = make_closure(lambda377, &env_t_377_value);
	env_t_378 env_t_378_value = make_empty_env(); closure_t closure371 = make_closure(lambda378, &env_t_378_value);
	env_t_379 env_t_379_value = make_empty_env(); closure_t closure374 = make_closure(lambda379, &env_t_379_value);
	macroDef375 = TOP_LEVEL_linalg_arraySum_s(stgVar357, TOP_LEVEL_linalg_vectorMap2_s(stgVar358, closure368, x_s, y_s, closure371, x_c, y_c), TOP_LEVEL_linalg_vectorMap2_c(closure374, x_c, y_c));
	free(stgVar358);
	return macroDef375;
}
typedef struct env_t_384 {
	array_number_t row;
} env_t_384;
env_t_384 make_env_t_384(array_number_t row) {
	env_t_384 env;
	env.row = row;
	return env;
}

value_t lambda384(env_t_384* env381, number_t r) {
	array_number_t row380 = env381->row;
	value_t res;
	res.array_number_t_value = row380;
	return res;
}
array_array_number_t TOP_LEVEL_linalg_matrixFillFromVector(card_t rows, array_number_t row) {
	env_t_384 env_t_384_value = make_env_t_384(row); closure_t closure383 = make_closure(lambda384, &env_t_384_value);
	return TOP_LEVEL_linalg_vectorMapToMatrix(closure383, TOP_LEVEL_linalg_vectorRange(1, rows));
}typedef struct env_t_395 {
	vector_shape_t row_c;
} env_t_395;
env_t_395 make_env_t_395(vector_shape_t row_c) {
	env_t_395 env;
	env.row_c = row_c;
	return env;
}

value_t lambda395(env_t_395* env392, card_t r_c) {
	vector_shape_t row_c391 = env392->row_c;
	value_t res;
	res.vector_shape_t_value = row_c391;
	return res;
}
matrix_shape_t TOP_LEVEL_linalg_matrixFillFromVector_c(card_t rows_c, vector_shape_t row_c) {
	env_t_395 env_t_395_value = make_env_t_395(row_c); closure_t closure394 = make_closure(lambda395, &env_t_395_value);
	return TOP_LEVEL_linalg_vectorMapToMatrix_c(closure394, TOP_LEVEL_linalg_vectorRange_c(1, rows_c));
}typedef struct env_t_405 {
	array_number_t row_s;
} env_t_405;
env_t_405 make_env_t_405(array_number_t row_s) {
	env_t_405 env;
	env.row_s = row_s;
	return env;
}

value_t lambda405(env_t_405* env397, storage_t stgVar388, number_t r_s, card_t r_c) {
	array_number_t row_s396 = env397->row_s;
	value_t res;
	res.array_number_t_value = row_s396;
	return res;
}
typedef struct env_t_406 {
	vector_shape_t row_c;
} env_t_406;
env_t_406 make_env_t_406(vector_shape_t row_c) {
	env_t_406 env;
	env.row_c = row_c;
	return env;
}

value_t lambda406(env_t_406* env401, card_t r_c) {
	vector_shape_t row_c400 = env401->row_c;
	value_t res;
	res.vector_shape_t_value = row_c400;
	return res;
}
array_array_number_t TOP_LEVEL_linalg_matrixFillFromVector_s(storage_t stgVar385, card_t rows_s, array_number_t row_s, card_t rows_c, vector_shape_t row_c) {
	array_number_t stgVar387 = malloc(width_vector_shape_t(TOP_LEVEL_linalg_vectorRange_c(1, rows_c)));
	array_array_number_t macroDef404;env_t_405 env_t_405_value = make_env_t_405(row_s); closure_t closure399 = make_closure(lambda405, &env_t_405_value);
	env_t_406 env_t_406_value = make_env_t_406(row_c); closure_t closure403 = make_closure(lambda406, &env_t_406_value);
	macroDef404 = TOP_LEVEL_linalg_vectorMapToMatrix_s(stgVar385, closure399, TOP_LEVEL_linalg_vectorRange_s(stgVar387, 1, rows_s, 1, rows_c), closure403, TOP_LEVEL_linalg_vectorRange_c(1, rows_c));
	free(stgVar387);
	return macroDef404;
}
typedef struct env_t_411 {
	number_t value;
} env_t_411;
env_t_411 make_env_t_411(number_t value) {
	env_t_411 env;
	env.value = value;
	return env;
}

value_t lambda411(env_t_411* env408, number_t c) {
	number_t value407 = env408->value;
	value_t res;
	res.number_t_value = value407;
	return res;
}
array_array_number_t TOP_LEVEL_linalg_matrixFill(card_t rows, card_t cols, number_t value) {
	env_t_411 env_t_411_value = make_env_t_411(value); closure_t closure410 = make_closure(lambda411, &env_t_411_value);
	array_number_t row = TOP_LEVEL_linalg_vectorMap(closure410, TOP_LEVEL_linalg_vectorRange(1, cols));
	return TOP_LEVEL_linalg_matrixFillFromVector(rows, row);
}typedef empty_env_t env_t_424;


value_t lambda424(env_t_424* env421, card_t c_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
matrix_shape_t TOP_LEVEL_linalg_matrixFill_c(card_t rows_c, card_t cols_c, card_t value_c) {
	env_t_424 env_t_424_value = make_empty_env(); closure_t closure423 = make_closure(lambda424, &env_t_424_value);
	vector_shape_t row_c = TOP_LEVEL_linalg_vectorMap_c(closure423, TOP_LEVEL_linalg_vectorRange_c(1, cols_c));
	return TOP_LEVEL_linalg_matrixFillFromVector_c(rows_c, row_c);
}typedef empty_env_t env_t_437;


value_t lambda437(env_t_437* env425, card_t c_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef struct env_t_438 {
	number_t value_s;
} env_t_438;
env_t_438 make_env_t_438(number_t value_s) {
	env_t_438 env;
	env.value_s = value_s;
	return env;
}

value_t lambda438(env_t_438* env429, storage_t stgVar416, number_t c_s, card_t c_c) {
	number_t value_s428 = env429->value_s;
	value_t res;
	res.number_t_value = value_s428;
	return res;
}
typedef empty_env_t env_t_439;


value_t lambda439(env_t_439* env432, card_t c_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
array_array_number_t TOP_LEVEL_linalg_matrixFill_s(storage_t stgVar412, card_t rows_s, card_t cols_s, number_t value_s, card_t rows_c, card_t cols_c, card_t value_c) {
	env_t_437 env_t_437_value = make_empty_env(); closure_t closure427 = make_closure(lambda437, &env_t_437_value);
	vector_shape_t row_c = TOP_LEVEL_linalg_vectorMap_c(closure427, TOP_LEVEL_linalg_vectorRange_c(1, cols_c));
	array_number_t stgVar413 = malloc(width_vector_shape_t(row_c));
	array_array_number_t macroDef436;array_number_t stgVar415 = malloc(width_vector_shape_t(TOP_LEVEL_linalg_vectorRange_c(1, cols_c)));
	array_number_t macroDef435;env_t_438 env_t_438_value = make_env_t_438(value_s); closure_t closure431 = make_closure(lambda438, &env_t_438_value);
	env_t_439 env_t_439_value = make_empty_env(); closure_t closure434 = make_closure(lambda439, &env_t_439_value);
	macroDef435 = TOP_LEVEL_linalg_vectorMap_s(stgVar413, closure431, TOP_LEVEL_linalg_vectorRange_s(stgVar415, 1, cols_s, 1, cols_c), closure434, TOP_LEVEL_linalg_vectorRange_c(1, cols_c));
	free(stgVar415);
	array_number_t row_s = macroDef435;
	macroDef436 = TOP_LEVEL_linalg_matrixFillFromVector_s(stgVar412, rows_s, row_s, rows_c, row_c);
	free(stgVar413);
	return macroDef436;
}

array_array_number_t TOP_LEVEL_linalg_matrixTranspose(array_array_number_t m) {
	card_t macroDef440 = m->length;
	card_t rows = macroDef440;
	card_t macroDef441 = m->arr[0]->length;
	card_t cols = macroDef441;
	array_array_number_t macroDef443 = (array_array_number_t)malloc(sizeof(int) * 2);
	macroDef443->length=cols;
	macroDef443->arr = (array_number_t*)malloc(sizeof(array_number_t) * cols);
		for(int i = 0; i < macroDef443->length; i++){
			array_number_t macroDef442 = (array_number_t)malloc(sizeof(int) * 2);
	macroDef442->length=rows;
	macroDef442->arr = (number_t*)malloc(sizeof(number_t) * rows);
		for(int j = 0; j < macroDef442->length; j++){
			
			macroDef442->arr[j] = m->arr[j]->arr[i];
		}
			macroDef443->arr[i] = macroDef442;
		}
	return macroDef443;
}typedef struct env_t_461 {
	card_t rows_c;
} env_t_461;
env_t_461 make_env_t_461(card_t rows_c) {
	env_t_461 env;
	env.rows_c = rows_c;
	return env;
}
typedef empty_env_t env_t_462;


value_t lambda462(env_t_462* env454, card_t j_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
value_t lambda461(env_t_461* env458, card_t i_c) {
	card_t rows_c457 = env458->rows_c;
	env_t_462 env_t_462_value = make_empty_env(); closure_t closure456 = make_closure(lambda462, &env_t_462_value);
	value_t res;
	res.vector_shape_t_value = nested_shape_card_t(closure456.lam(closure456.env, 0).card_t_value, rows_c457);
	return res;
}
matrix_shape_t TOP_LEVEL_linalg_matrixTranspose_c(matrix_shape_t m_c) {
	card_t rows_c = m_c.card;
	card_t cols_c = m_c.elem.card;
	env_t_461 env_t_461_value = make_env_t_461(rows_c); closure_t closure460 = make_closure(lambda461, &env_t_461_value);
	return nested_shape_vector_shape_t(closure460.lam(closure460.env, 0).vector_shape_t_value, cols_c);
}
array_array_number_t TOP_LEVEL_linalg_matrixTranspose_s(storage_t stgVar444, array_array_number_t m_s, matrix_shape_t m_c) {
	card_t rows_c = m_c.card;
	card_t macroDef463 = m_s->length;
	card_t rows_s = macroDef463;
	card_t cols_c = m_c.elem.card;
	array_number_t stgVar448 = malloc(width_vector_shape_t(m_c.elem));
	card_t macroDef465;card_t macroDef464 = m_s->arr[0]->length;
	macroDef465 = macroDef464;
	free(stgVar448);
	card_t cols_s = macroDef465;
	array_array_number_t macroDef471 = (array_array_number_t)stgVar444;
		macroDef471->length=cols_s;
		macroDef471->arr=(array_number_t*)((char*)macroDef471 + VECTOR_HEADER_BYTES);
		for(int i_s = 0; i_s < macroDef471->length; i_s++){
			storage_t stgVar450 = &macroDef471->arr[i_s];
			array_number_t macroDef467 = (array_number_t)stgVar450;
		macroDef467->length=rows_s;
		macroDef467->arr=(number_t*)((char*)macroDef467 + VECTOR_HEADER_BYTES);
		for(int j_s = 0; j_s < macroDef467->length; j_s++){
			storage_t stgVar451 = &macroDef467->arr[j_s];
			array_number_t stgVar452 = malloc(width_vector_shape_t(m_c.elem));
	number_t macroDef466;
	macroDef466 = m_s->arr[j_s]->arr[i_s];
	free(stgVar452);
			macroDef467->arr[j_s] = macroDef466;
		}
			macroDef471->arr[i_s] = macroDef467;
		}
	return macroDef471;
}

array_array_number_t TOP_LEVEL_linalg_matrixMult(array_array_number_t m1, array_array_number_t m2) {
	card_t macroDef472 = m1->length;
	card_t r1 = macroDef472;
	card_t macroDef473 = m2->arr[0]->length;
	card_t c2 = macroDef473;
	card_t macroDef474 = m1->arr[0]->length;
	card_t c1 = macroDef474;
	card_t macroDef475 = m2->length;
	card_t r2 = macroDef475;
	array_array_number_t m2T = TOP_LEVEL_linalg_matrixTranspose(m2);
	array_array_number_t macroDef477 = (array_array_number_t)malloc(sizeof(int) * 2);
	macroDef477->length=r1;
	macroDef477->arr = (array_number_t*)malloc(sizeof(array_number_t) * r1);
		for(int r = 0; r < macroDef477->length; r++){
			array_number_t macroDef476 = (array_number_t)malloc(sizeof(int) * 2);
	macroDef476->length=c2;
	macroDef476->arr = (number_t*)malloc(sizeof(number_t) * c2);
		for(int c = 0; c < macroDef476->length; c++){
			
			macroDef476->arr[c] = TOP_LEVEL_linalg_dot_prod(m1->arr[r], m2T->arr[c]);
		}
			macroDef477->arr[r] = macroDef476;
		}
	return macroDef477;
}typedef struct env_t_504 {
	card_t c2_c;
} env_t_504;
env_t_504 make_env_t_504(card_t c2_c) {
	env_t_504 env;
	env.c2_c = c2_c;
	return env;
}
typedef empty_env_t env_t_505;


value_t lambda505(env_t_505* env497, card_t c_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
value_t lambda504(env_t_504* env501, card_t r_c) {
	card_t c2_c500 = env501->c2_c;
	env_t_505 env_t_505_value = make_empty_env(); closure_t closure499 = make_closure(lambda505, &env_t_505_value);
	value_t res;
	res.vector_shape_t_value = nested_shape_card_t(closure499.lam(closure499.env, 0).card_t_value, c2_c500);
	return res;
}
matrix_shape_t TOP_LEVEL_linalg_matrixMult_c(matrix_shape_t m1_c, matrix_shape_t m2_c) {
	card_t r1_c = m1_c.card;
	card_t c2_c = m2_c.elem.card;
	card_t c1_c = m1_c.elem.card;
	card_t r2_c = m2_c.card;
	matrix_shape_t m2T_c = TOP_LEVEL_linalg_matrixTranspose_c(m2_c);
	env_t_504 env_t_504_value = make_env_t_504(c2_c); closure_t closure503 = make_closure(lambda504, &env_t_504_value);
	return nested_shape_vector_shape_t(closure503.lam(closure503.env, 0).vector_shape_t_value, r1_c);
}
array_array_number_t TOP_LEVEL_linalg_matrixMult_s(storage_t stgVar478, array_array_number_t m1_s, array_array_number_t m2_s, matrix_shape_t m1_c, matrix_shape_t m2_c) {
	card_t r1_c = m1_c.card;
	card_t macroDef506 = m1_s->length;
	card_t r1_s = macroDef506;
	card_t c2_c = m2_c.elem.card;
	array_number_t stgVar482 = malloc(width_vector_shape_t(m2_c.elem));
	card_t macroDef508;card_t macroDef507 = m2_s->arr[0]->length;
	macroDef508 = macroDef507;
	free(stgVar482);
	card_t c2_s = macroDef508;
	card_t c1_c = m1_c.elem.card;
	array_number_t stgVar485 = malloc(width_vector_shape_t(m1_c.elem));
	card_t macroDef510;card_t macroDef509 = m1_s->arr[0]->length;
	macroDef510 = macroDef509;
	free(stgVar485);
	card_t c1_s = macroDef510;
	card_t r2_c = m2_c.card;
	card_t macroDef511 = m2_s->length;
	card_t r2_s = macroDef511;
	matrix_shape_t m2T_c = TOP_LEVEL_linalg_matrixTranspose_c(m2_c);
	array_number_t stgVar489 = malloc(width_matrix_shape_t(m2T_c));
	array_array_number_t macroDef519;array_array_number_t m2T_s = TOP_LEVEL_linalg_matrixTranspose_s(stgVar489, m2_s, m2_c);
	array_array_number_t macroDef518 = (array_array_number_t)stgVar478;
		macroDef518->length=r1_s;
		macroDef518->arr=(array_number_t*)((char*)macroDef518 + VECTOR_HEADER_BYTES);
		for(int r_s = 0; r_s < macroDef518->length; r_s++){
			storage_t stgVar491 = &macroDef518->arr[r_s];
			array_number_t macroDef514 = (array_number_t)stgVar491;
		macroDef514->length=c2_s;
		macroDef514->arr=(number_t*)((char*)macroDef514 + VECTOR_HEADER_BYTES);
		for(int c_s = 0; c_s < macroDef514->length; c_s++){
			storage_t stgVar492 = &macroDef514->arr[c_s];
			array_number_t stgVar494 = malloc(width_vector_shape_t(m2T_c.elem));
	number_t macroDef513;array_number_t stgVar493 = malloc(width_vector_shape_t(m1_c.elem));
	number_t macroDef512;
	macroDef512 = TOP_LEVEL_linalg_dot_prod_s(stgVar492, m1_s->arr[r_s], m2T_s->arr[c_s], m1_c.elem, m2T_c.elem);
	free(stgVar493);
	macroDef513 = macroDef512;
	free(stgVar494);
			macroDef514->arr[c_s] = macroDef513;
		}
			macroDef518->arr[r_s] = macroDef514;
		}
	macroDef519 = macroDef518;
	free(stgVar489);
	return macroDef519;
}

array_array_number_t TOP_LEVEL_linalg_matrixConcat(array_array_number_t m1, array_array_number_t m2) {
	card_t macroDef520 = m1->length;
	card_t macroDef521 = m2->length;
	card_t rows = (macroDef520) + (macroDef521);
	card_t macroDef522 = m1->length;
	index_t m1Rows = (macroDef522);
	array_array_number_t macroDef523 = (array_array_number_t)malloc(sizeof(int) * 2);
	macroDef523->length=rows;
	macroDef523->arr = (array_number_t*)malloc(sizeof(array_number_t) * rows);
		for(int r = 0; r < macroDef523->length; r++){
			array_number_t ite524 = 0;
	if((r) < (m1Rows)) {
		
		ite524 = m1->arr[r];
	} else {
		
		ite524 = m2->arr[(r) - (m1Rows)];
	}
			macroDef523->arr[r] = ite524;
		}
	return macroDef523;
}typedef struct env_t_538 {
	matrix_shape_t m1_c;
} env_t_538;
env_t_538 make_env_t_538(matrix_shape_t m1_c) {
	env_t_538 env;
	env.m1_c = m1_c;
	return env;
}

value_t lambda538(env_t_538* env535, card_t r_c) {
	matrix_shape_t m1_c534 = env535->m1_c;
	value_t res;
	res.vector_shape_t_value = m1_c534.elem;
	return res;
}
matrix_shape_t TOP_LEVEL_linalg_matrixConcat_c(matrix_shape_t m1_c, matrix_shape_t m2_c) {
	card_t rows_c = (m1_c.card) + (m2_c.card);
	card_t m1Rows_c = 0;
	env_t_538 env_t_538_value = make_env_t_538(m1_c); closure_t closure537 = make_closure(lambda538, &env_t_538_value);
	return nested_shape_vector_shape_t(closure537.lam(closure537.env, 0).vector_shape_t_value, rows_c);
}
array_array_number_t TOP_LEVEL_linalg_matrixConcat_s(storage_t stgVar525, array_array_number_t m1_s, array_array_number_t m2_s, matrix_shape_t m1_c, matrix_shape_t m2_c) {
	card_t rows_c = (m1_c.card) + (m2_c.card);
	card_t macroDef539 = m1_s->length;
	card_t macroDef540 = m2_s->length;
	card_t rows_s = (macroDef539) + (macroDef540);
	card_t m1Rows_c = 0;
	card_t macroDef541 = m1_s->length;
	index_t m1Rows_s = (macroDef541);
	array_array_number_t macroDef542 = (array_array_number_t)stgVar525;
		macroDef542->length=rows_s;
		macroDef542->arr=(array_number_t*)((char*)macroDef542 + VECTOR_HEADER_BYTES);
		for(int r_s = 0; r_s < macroDef542->length; r_s++){
			storage_t stgVar531 = &macroDef542->arr[r_s];
			array_number_t ite543 = 0;
	if((r_s) < (m1Rows_s)) {
		
		ite543 = m1_s->arr[r_s];
	} else {
		
		ite543 = m2_s->arr[(r_s) - (m1Rows_s)];
	}
			macroDef542->arr[r_s] = ite543;
		}
	return macroDef542;
}

array_array_number_t TOP_LEVEL_linalg_matrixConcatCol(array_array_number_t m1, array_array_number_t m2) {
	array_array_number_t m1t = TOP_LEVEL_linalg_matrixTranspose(m1);
	array_array_number_t m2t = TOP_LEVEL_linalg_matrixTranspose(m2);
	return TOP_LEVEL_linalg_matrixTranspose(TOP_LEVEL_linalg_matrixConcat(m1t, m2t));
}
matrix_shape_t TOP_LEVEL_linalg_matrixConcatCol_c(matrix_shape_t m1_c, matrix_shape_t m2_c) {
	matrix_shape_t m1t_c = TOP_LEVEL_linalg_matrixTranspose_c(m1_c);
	matrix_shape_t m2t_c = TOP_LEVEL_linalg_matrixTranspose_c(m2_c);
	return TOP_LEVEL_linalg_matrixTranspose_c(TOP_LEVEL_linalg_matrixConcat_c(m1t_c, m2t_c));
}
array_array_number_t TOP_LEVEL_linalg_matrixConcatCol_s(storage_t stgVar544, array_array_number_t m1_s, array_array_number_t m2_s, matrix_shape_t m1_c, matrix_shape_t m2_c) {
	matrix_shape_t m1t_c = TOP_LEVEL_linalg_matrixTranspose_c(m1_c);
	array_number_t stgVar545 = malloc(width_matrix_shape_t(m1t_c));
	array_array_number_t macroDef554;array_array_number_t m1t_s = TOP_LEVEL_linalg_matrixTranspose_s(stgVar545, m1_s, m1_c);
	matrix_shape_t m2t_c = TOP_LEVEL_linalg_matrixTranspose_c(m2_c);
	array_number_t stgVar547 = malloc(width_matrix_shape_t(m2t_c));
	array_array_number_t macroDef553;array_array_number_t m2t_s = TOP_LEVEL_linalg_matrixTranspose_s(stgVar547, m2_s, m2_c);
	array_number_t stgVar549 = malloc(width_matrix_shape_t(TOP_LEVEL_linalg_matrixConcat_c(m1t_c, m2t_c)));
	array_array_number_t macroDef552;
	macroDef552 = TOP_LEVEL_linalg_matrixTranspose_s(stgVar544, TOP_LEVEL_linalg_matrixConcat_s(stgVar549, m1t_s, m2t_s, m1t_c, m2t_c), TOP_LEVEL_linalg_matrixConcat_c(m1t_c, m2t_c));
	free(stgVar549);
	macroDef553 = macroDef552;
	free(stgVar547);
	macroDef554 = macroDef553;
	free(stgVar545);
	return macroDef554;
}

array_array_array_number_t TOP_LEVEL_linalg_matrix3DConcat(array_array_array_number_t m1, array_array_array_number_t m2) {
	card_t macroDef555 = m1->length;
	card_t macroDef556 = m2->length;
	card_t rows = (macroDef555) + (macroDef556);
	card_t macroDef557 = m1->length;
	index_t m1Rows = (macroDef557);
	array_array_array_number_t macroDef558 = (array_array_array_number_t)malloc(sizeof(int) * 2);
	macroDef558->length=rows;
	macroDef558->arr = (array_array_number_t*)malloc(sizeof(array_array_number_t) * rows);
		for(int r = 0; r < macroDef558->length; r++){
			array_array_number_t ite559 = 0;
	if((r) < (m1Rows)) {
		
		ite559 = m1->arr[r];
	} else {
		
		ite559 = m2->arr[(r) - (m1Rows)];
	}
			macroDef558->arr[r] = ite559;
		}
	return macroDef558;
}typedef struct env_t_573 {
	matrix3d_shape_t m1_c;
} env_t_573;
env_t_573 make_env_t_573(matrix3d_shape_t m1_c) {
	env_t_573 env;
	env.m1_c = m1_c;
	return env;
}

value_t lambda573(env_t_573* env570, card_t r_c) {
	matrix3d_shape_t m1_c569 = env570->m1_c;
	value_t res;
	res.matrix_shape_t_value = m1_c569.elem;
	return res;
}
matrix3d_shape_t TOP_LEVEL_linalg_matrix3DConcat_c(matrix3d_shape_t m1_c, matrix3d_shape_t m2_c) {
	card_t rows_c = (m1_c.card) + (m2_c.card);
	card_t m1Rows_c = 0;
	env_t_573 env_t_573_value = make_env_t_573(m1_c); closure_t closure572 = make_closure(lambda573, &env_t_573_value);
	return nested_shape_matrix_shape_t(closure572.lam(closure572.env, 0).matrix_shape_t_value, rows_c);
}
array_array_array_number_t TOP_LEVEL_linalg_matrix3DConcat_s(storage_t stgVar560, array_array_array_number_t m1_s, array_array_array_number_t m2_s, matrix3d_shape_t m1_c, matrix3d_shape_t m2_c) {
	card_t rows_c = (m1_c.card) + (m2_c.card);
	card_t macroDef574 = m1_s->length;
	card_t macroDef575 = m2_s->length;
	card_t rows_s = (macroDef574) + (macroDef575);
	card_t m1Rows_c = 0;
	card_t macroDef576 = m1_s->length;
	index_t m1Rows_s = (macroDef576);
	array_array_array_number_t macroDef577 = (array_array_array_number_t)stgVar560;
		macroDef577->length=rows_s;
		macroDef577->arr=(array_array_number_t*)((char*)macroDef577 + VECTOR_HEADER_BYTES);
		for(int r_s = 0; r_s < macroDef577->length; r_s++){
			storage_t stgVar566 = &macroDef577->arr[r_s];
			array_array_number_t ite578 = 0;
	if((r_s) < (m1Rows_s)) {
		
		ite578 = m1_s->arr[r_s];
	} else {
		
		ite578 = m2_s->arr[(r_s) - (m1Rows_s)];
	}
			macroDef577->arr[r_s] = ite578;
		}
	return macroDef577;
}

array_number_t TOP_LEVEL_linalg_vectorRead(string_t fn, index_t startLine) {
	array_array_number_t matrix = matrix_read(fn, startLine, 1);
	return matrix->arr[0];
}
vector_shape_t TOP_LEVEL_linalg_vectorRead_c(card_t fn_c, card_t startLine_c) {
	matrix_shape_t matrix_c = nested_shape_vector_shape_t(nested_shape_card_t(0, 10), 1);
	return matrix_c.elem;
}
array_number_t TOP_LEVEL_linalg_vectorRead_s(storage_t stgVar579, string_t fn_s, index_t startLine_s, card_t fn_c, card_t startLine_c) {
	matrix_shape_t matrix_c = nested_shape_vector_shape_t(nested_shape_card_t(0, 10), 1);
	array_number_t stgVar580 = malloc(width_matrix_shape_t(matrix_c));
	array_number_t macroDef582;array_array_number_t matrix_s = matrix_read_s(stgVar580, fn_s, startLine_s, 1);
	macroDef582 = matrix_s->arr[0];
	free(stgVar580);
	return macroDef582;
}

number_t TOP_LEVEL_linalg_numberRead(string_t fn, index_t startLine) {
	array_number_t vector = TOP_LEVEL_linalg_vectorRead(fn, startLine);
	return vector->arr[0];
}
card_t TOP_LEVEL_linalg_numberRead_c(card_t fn_c, card_t startLine_c) {
	
	return 0;
}
number_t TOP_LEVEL_linalg_numberRead_s(storage_t stgVar583, string_t fn_s, index_t startLine_s, card_t fn_c, card_t startLine_c) {
	vector_shape_t vector_c = TOP_LEVEL_linalg_vectorRead_c(fn_c, 0);
	array_number_t stgVar584 = malloc(width_vector_shape_t(vector_c));
	number_t macroDef588;array_number_t vector_s = TOP_LEVEL_linalg_vectorRead_s(stgVar584, fn_s, startLine_s, fn_c, 0);
	macroDef588 = vector_s->arr[0];
	free(stgVar584);
	return macroDef588;
}
#endif
