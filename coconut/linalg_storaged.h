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
		for(int i_s = 0; i_s < macroDef46->length; i_s++){
			storage_t stgVar35 = &macroDef46->arr[i_s];
			array_number_t stgVar36 = vector_alloc(width_vector_shape_t(m_c.elem));
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
		for(int i_s = 0; i_s < macroDef81->length; i_s++){
			storage_t stgVar66 = &macroDef81->arr[i_s];
			array_number_t stgVar68 = vector_alloc(width_vector_shape_t(m2_c.elem));
	array_number_t macroDef80;array_number_t stgVar67 = vector_alloc(width_vector_shape_t(m1_c.elem));
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
		for(int i_s = 0; i_s < macroDef101->length; i_s++){
			storage_t stgVar86 = &macroDef101->arr[i_s];
			array_number_t stgVar88 = vector_alloc(width_matrix_shape_t(m2_c.elem));
	array_array_number_t macroDef100;array_number_t stgVar87 = vector_alloc(width_matrix_shape_t(m1_c.elem));
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
	array_number_t stgVar255 = vector_alloc(width_vector_shape_t(TOP_LEVEL_linalg_add_vec_c(x_c, y_c)));
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
}typedef struct env_t_296 {
	closure_t TOP_LEVEL_linalg_add_vec_c;
} env_t_296;
env_t_296 make_env_t_296(closure_t TOP_LEVEL_linalg_add_vec_c) {
	env_t_296 env;
	env.TOP_LEVEL_linalg_add_vec_c = TOP_LEVEL_linalg_add_vec_c;
	return env;
}

value_t lambda296(env_t_296* env293, vector_shape_t x_c, vector_shape_t y_c) {
	closure_t TOP_LEVEL_linalg_add_vec_c292 = env293->TOP_LEVEL_linalg_add_vec_c;
	value_t res;
	res.vector_shape_t_value = TOP_LEVEL_linalg_add_vec_c292(x_c, y_c);
	return res;
}
matrix_shape_t TOP_LEVEL_linalg_matrixAdd_c(matrix_shape_t x_c, matrix_shape_t y_c) {
	env_t_296 env_t_296_value = make_env_t_296(TOP_LEVEL_linalg_add_vec_c); closure_t closure295 = make_closure(lambda296, &env_t_296_value);
	return TOP_LEVEL_linalg_matrixMap2_c(closure295, x_c, y_c);
}typedef struct env_t_305 {
	closure_t TOP_LEVEL_linalg_add_vec_s;
} env_t_305;
env_t_305 make_env_t_305(closure_t TOP_LEVEL_linalg_add_vec_s) {
	env_t_305 env;
	env.TOP_LEVEL_linalg_add_vec_s = TOP_LEVEL_linalg_add_vec_s;
	return env;
}

value_t lambda305(env_t_305* env298, storage_t stgVar289, array_number_t x_s, array_number_t y_s, vector_shape_t x_c, vector_shape_t y_c) {
	closure_t TOP_LEVEL_linalg_add_vec_s297 = env298->TOP_LEVEL_linalg_add_vec_s;
	value_t res;
	res.array_number_t_value = TOP_LEVEL_linalg_add_vec_s297(stgVar289, x_s, y_s, x_c, y_c);
	return res;
}
typedef struct env_t_306 {
	closure_t TOP_LEVEL_linalg_add_vec_c;
} env_t_306;
env_t_306 make_env_t_306(closure_t TOP_LEVEL_linalg_add_vec_c) {
	env_t_306 env;
	env.TOP_LEVEL_linalg_add_vec_c = TOP_LEVEL_linalg_add_vec_c;
	return env;
}

value_t lambda306(env_t_306* env302, vector_shape_t x_c, vector_shape_t y_c) {
	closure_t TOP_LEVEL_linalg_add_vec_c301 = env302->TOP_LEVEL_linalg_add_vec_c;
	value_t res;
	res.vector_shape_t_value = TOP_LEVEL_linalg_add_vec_c301(x_c, y_c);
	return res;
}
array_array_number_t TOP_LEVEL_linalg_matrixAdd_s(storage_t stgVar285, array_array_number_t x_s, array_array_number_t y_s, matrix_shape_t x_c, matrix_shape_t y_c) {
	env_t_305 env_t_305_value = make_env_t_305(TOP_LEVEL_linalg_add_vec_s); closure_t closure300 = make_closure(lambda305, &env_t_305_value);
	env_t_306 env_t_306_value = make_env_t_306(TOP_LEVEL_linalg_add_vec_c); closure_t closure304 = make_closure(lambda306, &env_t_306_value);
	return TOP_LEVEL_linalg_matrixMap2_s(stgVar285, closure300, x_s, y_s, closure304, x_c, y_c);
}
typedef empty_env_t env_t_310;


value_t lambda310(env_t_310* env307, array_number_t x, array_number_t y) {
	
	value_t res;
	res.array_number_t_value = TOP_LEVEL_linalg_mult_vec_elementwise(x, y);
	return res;
}
array_array_number_t TOP_LEVEL_linalg_matrixMultElementwise(array_array_number_t x, array_array_number_t y) {
	env_t_310 env_t_310_value = make_empty_env(); closure_t closure309 = make_closure(lambda310, &env_t_310_value);
	return TOP_LEVEL_linalg_matrixMap2(closure309, x, y);
}typedef struct env_t_322 {
	closure_t TOP_LEVEL_linalg_mult_vec_elementwise_c;
} env_t_322;
env_t_322 make_env_t_322(closure_t TOP_LEVEL_linalg_mult_vec_elementwise_c) {
	env_t_322 env;
	env.TOP_LEVEL_linalg_mult_vec_elementwise_c = TOP_LEVEL_linalg_mult_vec_elementwise_c;
	return env;
}

value_t lambda322(env_t_322* env319, vector_shape_t x_c, vector_shape_t y_c) {
	closure_t TOP_LEVEL_linalg_mult_vec_elementwise_c318 = env319->TOP_LEVEL_linalg_mult_vec_elementwise_c;
	value_t res;
	res.vector_shape_t_value = TOP_LEVEL_linalg_mult_vec_elementwise_c318(x_c, y_c);
	return res;
}
matrix_shape_t TOP_LEVEL_linalg_matrixMultElementwise_c(matrix_shape_t x_c, matrix_shape_t y_c) {
	env_t_322 env_t_322_value = make_env_t_322(TOP_LEVEL_linalg_mult_vec_elementwise_c); closure_t closure321 = make_closure(lambda322, &env_t_322_value);
	return TOP_LEVEL_linalg_matrixMap2_c(closure321, x_c, y_c);
}typedef struct env_t_331 {
	closure_t TOP_LEVEL_linalg_mult_vec_elementwise_s;
} env_t_331;
env_t_331 make_env_t_331(closure_t TOP_LEVEL_linalg_mult_vec_elementwise_s) {
	env_t_331 env;
	env.TOP_LEVEL_linalg_mult_vec_elementwise_s = TOP_LEVEL_linalg_mult_vec_elementwise_s;
	return env;
}

value_t lambda331(env_t_331* env324, storage_t stgVar315, array_number_t x_s, array_number_t y_s, vector_shape_t x_c, vector_shape_t y_c) {
	closure_t TOP_LEVEL_linalg_mult_vec_elementwise_s323 = env324->TOP_LEVEL_linalg_mult_vec_elementwise_s;
	value_t res;
	res.array_number_t_value = TOP_LEVEL_linalg_mult_vec_elementwise_s323(stgVar315, x_s, y_s, x_c, y_c);
	return res;
}
typedef struct env_t_332 {
	closure_t TOP_LEVEL_linalg_mult_vec_elementwise_c;
} env_t_332;
env_t_332 make_env_t_332(closure_t TOP_LEVEL_linalg_mult_vec_elementwise_c) {
	env_t_332 env;
	env.TOP_LEVEL_linalg_mult_vec_elementwise_c = TOP_LEVEL_linalg_mult_vec_elementwise_c;
	return env;
}

value_t lambda332(env_t_332* env328, vector_shape_t x_c, vector_shape_t y_c) {
	closure_t TOP_LEVEL_linalg_mult_vec_elementwise_c327 = env328->TOP_LEVEL_linalg_mult_vec_elementwise_c;
	value_t res;
	res.vector_shape_t_value = TOP_LEVEL_linalg_mult_vec_elementwise_c327(x_c, y_c);
	return res;
}
array_array_number_t TOP_LEVEL_linalg_matrixMultElementwise_s(storage_t stgVar311, array_array_number_t x_s, array_array_number_t y_s, matrix_shape_t x_c, matrix_shape_t y_c) {
	env_t_331 env_t_331_value = make_env_t_331(TOP_LEVEL_linalg_mult_vec_elementwise_s); closure_t closure326 = make_closure(lambda331, &env_t_331_value);
	env_t_332 env_t_332_value = make_env_t_332(TOP_LEVEL_linalg_mult_vec_elementwise_c); closure_t closure330 = make_closure(lambda332, &env_t_332_value);
	return TOP_LEVEL_linalg_matrixMap2_s(stgVar311, closure326, x_s, y_s, closure330, x_c, y_c);
}
typedef empty_env_t env_t_336;


value_t lambda336(env_t_336* env333, number_t x1) {
	
	value_t res;
	res.number_t_value = (x1) * (x1);
	return res;
}
number_t TOP_LEVEL_linalg_sqnorm(array_number_t x) {
	env_t_336 env_t_336_value = make_empty_env(); closure_t closure335 = make_closure(lambda336, &env_t_336_value);
	return TOP_LEVEL_linalg_arraySum(TOP_LEVEL_linalg_vectorMap(closure335, x));
}
card_t TOP_LEVEL_linalg_sqnorm_c(vector_shape_t x_c) {
	
	return 0;
}typedef empty_env_t env_t_355;


value_t lambda355(env_t_355* env342, card_t x1_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef empty_env_t env_t_356;


value_t lambda356(env_t_356* env345, storage_t stgVar341, number_t x1_s, card_t x1_c) {
	
	value_t res;
	res.number_t_value = (x1_s) * (x1_s);
	return res;
}
typedef empty_env_t env_t_357;


value_t lambda357(env_t_357* env348, card_t x1_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef empty_env_t env_t_358;


value_t lambda358(env_t_358* env351, card_t x1_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
number_t TOP_LEVEL_linalg_sqnorm_s(storage_t stgVar337, array_number_t x_s, vector_shape_t x_c) {
	env_t_355 env_t_355_value = make_empty_env(); closure_t closure344 = make_closure(lambda355, &env_t_355_value);
	array_number_t stgVar338 = vector_alloc(width_vector_shape_t(TOP_LEVEL_linalg_vectorMap_c(closure344, x_c)));
	number_t macroDef354;env_t_356 env_t_356_value = make_empty_env(); closure_t closure347 = make_closure(lambda356, &env_t_356_value);
	env_t_357 env_t_357_value = make_empty_env(); closure_t closure350 = make_closure(lambda357, &env_t_357_value);
	env_t_358 env_t_358_value = make_empty_env(); closure_t closure353 = make_closure(lambda358, &env_t_358_value);
	macroDef354 = TOP_LEVEL_linalg_arraySum_s(stgVar337, TOP_LEVEL_linalg_vectorMap_s(stgVar338, closure347, x_s, closure350, x_c), TOP_LEVEL_linalg_vectorMap_c(closure353, x_c));
	free(stgVar338);
	return macroDef354;
}
typedef empty_env_t env_t_362;


value_t lambda362(env_t_362* env359, number_t x, number_t y) {
	
	value_t res;
	res.number_t_value = (x) * (y);
	return res;
}
number_t TOP_LEVEL_linalg_dot_prod(array_number_t x, array_number_t y) {
	env_t_362 env_t_362_value = make_empty_env(); closure_t closure361 = make_closure(lambda362, &env_t_362_value);
	return TOP_LEVEL_linalg_arraySum(TOP_LEVEL_linalg_vectorMap2(closure361, x, y));
}
card_t TOP_LEVEL_linalg_dot_prod_c(vector_shape_t x_c, vector_shape_t y_c) {
	
	return 0;
}typedef empty_env_t env_t_382;


value_t lambda382(env_t_382* env369, card_t x_c, card_t y_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef empty_env_t env_t_383;


value_t lambda383(env_t_383* env372, storage_t stgVar368, number_t x_s, number_t y_s, card_t x_c, card_t y_c) {
	
	value_t res;
	res.number_t_value = (x_s) * (y_s);
	return res;
}
typedef empty_env_t env_t_384;


value_t lambda384(env_t_384* env375, card_t x_c, card_t y_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef empty_env_t env_t_385;


value_t lambda385(env_t_385* env378, card_t x_c, card_t y_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
number_t TOP_LEVEL_linalg_dot_prod_s(storage_t stgVar363, array_number_t x_s, array_number_t y_s, vector_shape_t x_c, vector_shape_t y_c) {
	env_t_382 env_t_382_value = make_empty_env(); closure_t closure371 = make_closure(lambda382, &env_t_382_value);
	array_number_t stgVar364 = vector_alloc(width_vector_shape_t(TOP_LEVEL_linalg_vectorMap2_c(closure371, x_c, y_c)));
	number_t macroDef381;env_t_383 env_t_383_value = make_empty_env(); closure_t closure374 = make_closure(lambda383, &env_t_383_value);
	env_t_384 env_t_384_value = make_empty_env(); closure_t closure377 = make_closure(lambda384, &env_t_384_value);
	env_t_385 env_t_385_value = make_empty_env(); closure_t closure380 = make_closure(lambda385, &env_t_385_value);
	macroDef381 = TOP_LEVEL_linalg_arraySum_s(stgVar363, TOP_LEVEL_linalg_vectorMap2_s(stgVar364, closure374, x_s, y_s, closure377, x_c, y_c), TOP_LEVEL_linalg_vectorMap2_c(closure380, x_c, y_c));
	free(stgVar364);
	return macroDef381;
}
typedef struct env_t_390 {
	array_number_t row;
} env_t_390;
env_t_390 make_env_t_390(array_number_t row) {
	env_t_390 env;
	env.row = row;
	return env;
}

value_t lambda390(env_t_390* env387, number_t r) {
	array_number_t row386 = env387->row;
	value_t res;
	res.array_number_t_value = row386;
	return res;
}
array_array_number_t TOP_LEVEL_linalg_matrixFillFromVector(card_t rows, array_number_t row) {
	env_t_390 env_t_390_value = make_env_t_390(row); closure_t closure389 = make_closure(lambda390, &env_t_390_value);
	return TOP_LEVEL_linalg_vectorMapToMatrix(closure389, TOP_LEVEL_linalg_vectorRange(1, rows));
}typedef struct env_t_401 {
	vector_shape_t row_c;
} env_t_401;
env_t_401 make_env_t_401(vector_shape_t row_c) {
	env_t_401 env;
	env.row_c = row_c;
	return env;
}

value_t lambda401(env_t_401* env398, card_t r_c) {
	vector_shape_t row_c397 = env398->row_c;
	value_t res;
	res.vector_shape_t_value = row_c397;
	return res;
}
matrix_shape_t TOP_LEVEL_linalg_matrixFillFromVector_c(card_t rows_c, vector_shape_t row_c) {
	env_t_401 env_t_401_value = make_env_t_401(row_c); closure_t closure400 = make_closure(lambda401, &env_t_401_value);
	return TOP_LEVEL_linalg_vectorMapToMatrix_c(closure400, TOP_LEVEL_linalg_vectorRange_c(1, rows_c));
}typedef struct env_t_411 {
	array_number_t row_s;
} env_t_411;
env_t_411 make_env_t_411(array_number_t row_s) {
	env_t_411 env;
	env.row_s = row_s;
	return env;
}

value_t lambda411(env_t_411* env403, storage_t stgVar394, number_t r_s, card_t r_c) {
	array_number_t row_s402 = env403->row_s;
	value_t res;
	res.array_number_t_value = row_s402;
	return res;
}
typedef struct env_t_412 {
	vector_shape_t row_c;
} env_t_412;
env_t_412 make_env_t_412(vector_shape_t row_c) {
	env_t_412 env;
	env.row_c = row_c;
	return env;
}

value_t lambda412(env_t_412* env407, card_t r_c) {
	vector_shape_t row_c406 = env407->row_c;
	value_t res;
	res.vector_shape_t_value = row_c406;
	return res;
}
array_array_number_t TOP_LEVEL_linalg_matrixFillFromVector_s(storage_t stgVar391, card_t rows_s, array_number_t row_s, card_t rows_c, vector_shape_t row_c) {
	array_number_t stgVar393 = vector_alloc(width_vector_shape_t(TOP_LEVEL_linalg_vectorRange_c(1, rows_c)));
	array_array_number_t macroDef410;env_t_411 env_t_411_value = make_env_t_411(row_s); closure_t closure405 = make_closure(lambda411, &env_t_411_value);
	env_t_412 env_t_412_value = make_env_t_412(row_c); closure_t closure409 = make_closure(lambda412, &env_t_412_value);
	macroDef410 = TOP_LEVEL_linalg_vectorMapToMatrix_s(stgVar391, closure405, TOP_LEVEL_linalg_vectorRange_s(stgVar393, 1, rows_s, 1, rows_c), closure409, TOP_LEVEL_linalg_vectorRange_c(1, rows_c));
	free(stgVar393);
	return macroDef410;
}
typedef struct env_t_417 {
	number_t value;
} env_t_417;
env_t_417 make_env_t_417(number_t value) {
	env_t_417 env;
	env.value = value;
	return env;
}

value_t lambda417(env_t_417* env414, number_t c) {
	number_t value413 = env414->value;
	value_t res;
	res.number_t_value = value413;
	return res;
}
array_array_number_t TOP_LEVEL_linalg_matrixFill(card_t rows, card_t cols, number_t value) {
	env_t_417 env_t_417_value = make_env_t_417(value); closure_t closure416 = make_closure(lambda417, &env_t_417_value);
	array_number_t row = TOP_LEVEL_linalg_vectorMap(closure416, TOP_LEVEL_linalg_vectorRange(1, cols));
	return TOP_LEVEL_linalg_matrixFillFromVector(rows, row);
}typedef empty_env_t env_t_430;


value_t lambda430(env_t_430* env427, card_t c_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
matrix_shape_t TOP_LEVEL_linalg_matrixFill_c(card_t rows_c, card_t cols_c, card_t value_c) {
	env_t_430 env_t_430_value = make_empty_env(); closure_t closure429 = make_closure(lambda430, &env_t_430_value);
	vector_shape_t row_c = TOP_LEVEL_linalg_vectorMap_c(closure429, TOP_LEVEL_linalg_vectorRange_c(1, cols_c));
	return TOP_LEVEL_linalg_matrixFillFromVector_c(rows_c, row_c);
}typedef empty_env_t env_t_443;


value_t lambda443(env_t_443* env431, card_t c_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef struct env_t_444 {
	number_t value_s;
} env_t_444;
env_t_444 make_env_t_444(number_t value_s) {
	env_t_444 env;
	env.value_s = value_s;
	return env;
}

value_t lambda444(env_t_444* env435, storage_t stgVar422, number_t c_s, card_t c_c) {
	number_t value_s434 = env435->value_s;
	value_t res;
	res.number_t_value = value_s434;
	return res;
}
typedef empty_env_t env_t_445;


value_t lambda445(env_t_445* env438, card_t c_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
array_array_number_t TOP_LEVEL_linalg_matrixFill_s(storage_t stgVar418, card_t rows_s, card_t cols_s, number_t value_s, card_t rows_c, card_t cols_c, card_t value_c) {
	env_t_443 env_t_443_value = make_empty_env(); closure_t closure433 = make_closure(lambda443, &env_t_443_value);
	vector_shape_t row_c = TOP_LEVEL_linalg_vectorMap_c(closure433, TOP_LEVEL_linalg_vectorRange_c(1, cols_c));
	array_number_t stgVar419 = vector_alloc(width_vector_shape_t(row_c));
	array_array_number_t macroDef442;array_number_t stgVar421 = vector_alloc(width_vector_shape_t(TOP_LEVEL_linalg_vectorRange_c(1, cols_c)));
	array_number_t macroDef441;env_t_444 env_t_444_value = make_env_t_444(value_s); closure_t closure437 = make_closure(lambda444, &env_t_444_value);
	env_t_445 env_t_445_value = make_empty_env(); closure_t closure440 = make_closure(lambda445, &env_t_445_value);
	macroDef441 = TOP_LEVEL_linalg_vectorMap_s(stgVar419, closure437, TOP_LEVEL_linalg_vectorRange_s(stgVar421, 1, cols_s, 1, cols_c), closure440, TOP_LEVEL_linalg_vectorRange_c(1, cols_c));
	free(stgVar421);
	array_number_t row_s = macroDef441;
	macroDef442 = TOP_LEVEL_linalg_matrixFillFromVector_s(stgVar418, rows_s, row_s, rows_c, row_c);
	free(stgVar419);
	return macroDef442;
}

array_array_number_t TOP_LEVEL_linalg_matrixTranspose(array_array_number_t m) {
	card_t macroDef446 = m->length;
	card_t rows = macroDef446;
	card_t macroDef447 = m->arr[0]->length;
	card_t cols = macroDef447;
	array_array_number_t macroDef449 = (array_array_number_t)malloc(sizeof(int) * 2);
	macroDef449->length=cols;
	macroDef449->arr = (array_number_t*)malloc(sizeof(array_number_t) * cols);
		for(int i = 0; i < macroDef449->length; i++){
			array_number_t macroDef448 = (array_number_t)malloc(sizeof(int) * 2);
	macroDef448->length=rows;
	macroDef448->arr = (number_t*)malloc(sizeof(number_t) * rows);
		for(int j = 0; j < macroDef448->length; j++){
			
			macroDef448->arr[j] = m->arr[j]->arr[i];
		}
			macroDef449->arr[i] = macroDef448;
		}
	return macroDef449;
}typedef struct env_t_467 {
	card_t rows_c;
} env_t_467;
env_t_467 make_env_t_467(card_t rows_c) {
	env_t_467 env;
	env.rows_c = rows_c;
	return env;
}
typedef empty_env_t env_t_468;


value_t lambda468(env_t_468* env460, card_t j_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
value_t lambda467(env_t_467* env464, card_t i_c) {
	card_t rows_c463 = env464->rows_c;
	env_t_468 env_t_468_value = make_empty_env(); closure_t closure462 = make_closure(lambda468, &env_t_468_value);
	value_t res;
	res.vector_shape_t_value = nested_shape_card_t(closure462.lam(closure462.env, 0).card_t_value, rows_c463);
	return res;
}
matrix_shape_t TOP_LEVEL_linalg_matrixTranspose_c(matrix_shape_t m_c) {
	card_t rows_c = m_c.card;
	card_t cols_c = m_c.elem.card;
	env_t_467 env_t_467_value = make_env_t_467(rows_c); closure_t closure466 = make_closure(lambda467, &env_t_467_value);
	return nested_shape_vector_shape_t(closure466.lam(closure466.env, 0).vector_shape_t_value, cols_c);
}
array_array_number_t TOP_LEVEL_linalg_matrixTranspose_s(storage_t stgVar450, array_array_number_t m_s, matrix_shape_t m_c) {
	card_t rows_c = m_c.card;
	card_t macroDef469 = m_s->length;
	card_t rows_s = macroDef469;
	card_t cols_c = m_c.elem.card;
	array_number_t stgVar454 = vector_alloc(width_vector_shape_t(m_c.elem));
	card_t macroDef471;card_t macroDef470 = m_s->arr[0]->length;
	macroDef471 = macroDef470;
	free(stgVar454);
	card_t cols_s = macroDef471;
	array_array_number_t macroDef477 = (array_array_number_t)stgVar450;
		for(int i_s = 0; i_s < macroDef477->length; i_s++){
			storage_t stgVar456 = &macroDef477->arr[i_s];
			array_number_t macroDef473 = (array_number_t)stgVar456;
		for(int j_s = 0; j_s < macroDef473->length; j_s++){
			storage_t stgVar457 = &macroDef473->arr[j_s];
			array_number_t stgVar458 = vector_alloc(width_vector_shape_t(m_c.elem));
	number_t macroDef472;
	macroDef472 = m_s->arr[j_s]->arr[i_s];
	free(stgVar458);
			macroDef473->arr[j_s] = macroDef472;
		}
			macroDef477->arr[i_s] = macroDef473;
		}
	return macroDef477;
}

array_array_number_t TOP_LEVEL_linalg_matrixMult(array_array_number_t m1, array_array_number_t m2) {
	card_t macroDef478 = m1->length;
	card_t r1 = macroDef478;
	card_t macroDef479 = m2->arr[0]->length;
	card_t c2 = macroDef479;
	card_t macroDef480 = m1->arr[0]->length;
	card_t c1 = macroDef480;
	card_t macroDef481 = m2->length;
	card_t r2 = macroDef481;
	array_array_number_t m2T = TOP_LEVEL_linalg_matrixTranspose(m2);
	array_array_number_t macroDef483 = (array_array_number_t)malloc(sizeof(int) * 2);
	macroDef483->length=r1;
	macroDef483->arr = (array_number_t*)malloc(sizeof(array_number_t) * r1);
		for(int r = 0; r < macroDef483->length; r++){
			array_number_t macroDef482 = (array_number_t)malloc(sizeof(int) * 2);
	macroDef482->length=c2;
	macroDef482->arr = (number_t*)malloc(sizeof(number_t) * c2);
		for(int c = 0; c < macroDef482->length; c++){
			
			macroDef482->arr[c] = TOP_LEVEL_linalg_dot_prod(m1->arr[r], m2T->arr[c]);
		}
			macroDef483->arr[r] = macroDef482;
		}
	return macroDef483;
}typedef struct env_t_510 {
	card_t c2_c;
} env_t_510;
env_t_510 make_env_t_510(card_t c2_c) {
	env_t_510 env;
	env.c2_c = c2_c;
	return env;
}
typedef empty_env_t env_t_511;


value_t lambda511(env_t_511* env503, card_t c_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
value_t lambda510(env_t_510* env507, card_t r_c) {
	card_t c2_c506 = env507->c2_c;
	env_t_511 env_t_511_value = make_empty_env(); closure_t closure505 = make_closure(lambda511, &env_t_511_value);
	value_t res;
	res.vector_shape_t_value = nested_shape_card_t(closure505.lam(closure505.env, 0).card_t_value, c2_c506);
	return res;
}
matrix_shape_t TOP_LEVEL_linalg_matrixMult_c(matrix_shape_t m1_c, matrix_shape_t m2_c) {
	card_t r1_c = m1_c.card;
	card_t c2_c = m2_c.elem.card;
	card_t c1_c = m1_c.elem.card;
	card_t r2_c = m2_c.card;
	matrix_shape_t m2T_c = TOP_LEVEL_linalg_matrixTranspose_c(m2_c);
	env_t_510 env_t_510_value = make_env_t_510(c2_c); closure_t closure509 = make_closure(lambda510, &env_t_510_value);
	return nested_shape_vector_shape_t(closure509.lam(closure509.env, 0).vector_shape_t_value, r1_c);
}
array_array_number_t TOP_LEVEL_linalg_matrixMult_s(storage_t stgVar484, array_array_number_t m1_s, array_array_number_t m2_s, matrix_shape_t m1_c, matrix_shape_t m2_c) {
	card_t r1_c = m1_c.card;
	card_t macroDef512 = m1_s->length;
	card_t r1_s = macroDef512;
	card_t c2_c = m2_c.elem.card;
	array_number_t stgVar488 = vector_alloc(width_vector_shape_t(m2_c.elem));
	card_t macroDef514;card_t macroDef513 = m2_s->arr[0]->length;
	macroDef514 = macroDef513;
	free(stgVar488);
	card_t c2_s = macroDef514;
	card_t c1_c = m1_c.elem.card;
	array_number_t stgVar491 = vector_alloc(width_vector_shape_t(m1_c.elem));
	card_t macroDef516;card_t macroDef515 = m1_s->arr[0]->length;
	macroDef516 = macroDef515;
	free(stgVar491);
	card_t c1_s = macroDef516;
	card_t r2_c = m2_c.card;
	card_t macroDef517 = m2_s->length;
	card_t r2_s = macroDef517;
	matrix_shape_t m2T_c = TOP_LEVEL_linalg_matrixTranspose_c(m2_c);
	array_number_t stgVar495 = vector_alloc(width_matrix_shape_t(m2T_c));
	array_array_number_t macroDef525;array_array_number_t m2T_s = TOP_LEVEL_linalg_matrixTranspose_s(stgVar495, m2_s, m2_c);
	array_array_number_t macroDef524 = (array_array_number_t)stgVar484;
		for(int r_s = 0; r_s < macroDef524->length; r_s++){
			storage_t stgVar497 = &macroDef524->arr[r_s];
			array_number_t macroDef520 = (array_number_t)stgVar497;
		for(int c_s = 0; c_s < macroDef520->length; c_s++){
			storage_t stgVar498 = &macroDef520->arr[c_s];
			array_number_t stgVar500 = vector_alloc(width_vector_shape_t(m2T_c.elem));
	number_t macroDef519;array_number_t stgVar499 = vector_alloc(width_vector_shape_t(m1_c.elem));
	number_t macroDef518;
	macroDef518 = TOP_LEVEL_linalg_dot_prod_s(stgVar498, m1_s->arr[r_s], m2T_s->arr[c_s], m1_c.elem, m2T_c.elem);
	free(stgVar499);
	macroDef519 = macroDef518;
	free(stgVar500);
			macroDef520->arr[c_s] = macroDef519;
		}
			macroDef524->arr[r_s] = macroDef520;
		}
	macroDef525 = macroDef524;
	free(stgVar495);
	return macroDef525;
}

array_array_number_t TOP_LEVEL_linalg_matrixConcat(array_array_number_t m1, array_array_number_t m2) {
	card_t macroDef526 = m1->length;
	card_t macroDef527 = m2->length;
	card_t rows = (macroDef526) + (macroDef527);
	card_t macroDef528 = m1->length;
	index_t m1Rows = (macroDef528);
	array_array_number_t macroDef529 = (array_array_number_t)malloc(sizeof(int) * 2);
	macroDef529->length=rows;
	macroDef529->arr = (array_number_t*)malloc(sizeof(array_number_t) * rows);
		for(int r = 0; r < macroDef529->length; r++){
			array_number_t ite530 = 0;
	if((r) < (m1Rows)) {
		
		ite530 = m1->arr[r];
	} else {
		
		ite530 = m2->arr[(r) - (m1Rows)];
	}
			macroDef529->arr[r] = ite530;
		}
	return macroDef529;
}typedef struct env_t_544 {
	matrix_shape_t m1_c;
} env_t_544;
env_t_544 make_env_t_544(matrix_shape_t m1_c) {
	env_t_544 env;
	env.m1_c = m1_c;
	return env;
}

value_t lambda544(env_t_544* env541, card_t r_c) {
	matrix_shape_t m1_c540 = env541->m1_c;
	value_t res;
	res.vector_shape_t_value = m1_c540.elem;
	return res;
}
matrix_shape_t TOP_LEVEL_linalg_matrixConcat_c(matrix_shape_t m1_c, matrix_shape_t m2_c) {
	card_t rows_c = (m1_c.card) + (m2_c.card);
	card_t m1Rows_c = 0;
	env_t_544 env_t_544_value = make_env_t_544(m1_c); closure_t closure543 = make_closure(lambda544, &env_t_544_value);
	return nested_shape_vector_shape_t(closure543.lam(closure543.env, 0).vector_shape_t_value, rows_c);
}
array_array_number_t TOP_LEVEL_linalg_matrixConcat_s(storage_t stgVar531, array_array_number_t m1_s, array_array_number_t m2_s, matrix_shape_t m1_c, matrix_shape_t m2_c) {
	card_t rows_c = (m1_c.card) + (m2_c.card);
	card_t macroDef545 = m1_s->length;
	card_t macroDef546 = m2_s->length;
	card_t rows_s = (macroDef545) + (macroDef546);
	card_t m1Rows_c = 0;
	card_t macroDef547 = m1_s->length;
	index_t m1Rows_s = (macroDef547);
	array_array_number_t macroDef548 = (array_array_number_t)stgVar531;
		for(int r_s = 0; r_s < macroDef548->length; r_s++){
			storage_t stgVar537 = &macroDef548->arr[r_s];
			array_number_t ite549 = 0;
	if((r_s) < (m1Rows_s)) {
		
		ite549 = m1_s->arr[r_s];
	} else {
		
		ite549 = m2_s->arr[(r_s) - (m1Rows_s)];
	}
			macroDef548->arr[r_s] = ite549;
		}
	return macroDef548;
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
array_array_number_t TOP_LEVEL_linalg_matrixConcatCol_s(storage_t stgVar550, array_array_number_t m1_s, array_array_number_t m2_s, matrix_shape_t m1_c, matrix_shape_t m2_c) {
	matrix_shape_t m1t_c = TOP_LEVEL_linalg_matrixTranspose_c(m1_c);
	array_number_t stgVar551 = vector_alloc(width_matrix_shape_t(m1t_c));
	array_array_number_t macroDef560;array_array_number_t m1t_s = TOP_LEVEL_linalg_matrixTranspose_s(stgVar551, m1_s, m1_c);
	matrix_shape_t m2t_c = TOP_LEVEL_linalg_matrixTranspose_c(m2_c);
	array_number_t stgVar553 = vector_alloc(width_matrix_shape_t(m2t_c));
	array_array_number_t macroDef559;array_array_number_t m2t_s = TOP_LEVEL_linalg_matrixTranspose_s(stgVar553, m2_s, m2_c);
	array_number_t stgVar555 = vector_alloc(width_matrix_shape_t(TOP_LEVEL_linalg_matrixConcat_c(m1t_c, m2t_c)));
	array_array_number_t macroDef558;
	macroDef558 = TOP_LEVEL_linalg_matrixTranspose_s(stgVar550, TOP_LEVEL_linalg_matrixConcat_s(stgVar555, m1t_s, m2t_s, m1t_c, m2t_c), TOP_LEVEL_linalg_matrixConcat_c(m1t_c, m2t_c));
	free(stgVar555);
	macroDef559 = macroDef558;
	free(stgVar553);
	macroDef560 = macroDef559;
	free(stgVar551);
	return macroDef560;
}

array_array_array_number_t TOP_LEVEL_linalg_matrix3DConcat(array_array_array_number_t m1, array_array_array_number_t m2) {
	card_t macroDef561 = m1->length;
	card_t macroDef562 = m2->length;
	card_t rows = (macroDef561) + (macroDef562);
	card_t macroDef563 = m1->length;
	index_t m1Rows = (macroDef563);
	array_array_array_number_t macroDef564 = (array_array_array_number_t)malloc(sizeof(int) * 2);
	macroDef564->length=rows;
	macroDef564->arr = (array_array_number_t*)malloc(sizeof(array_array_number_t) * rows);
		for(int r = 0; r < macroDef564->length; r++){
			array_array_number_t ite565 = 0;
	if((r) < (m1Rows)) {
		
		ite565 = m1->arr[r];
	} else {
		
		ite565 = m2->arr[(r) - (m1Rows)];
	}
			macroDef564->arr[r] = ite565;
		}
	return macroDef564;
}typedef struct env_t_579 {
	matrix3d_shape_t m1_c;
} env_t_579;
env_t_579 make_env_t_579(matrix3d_shape_t m1_c) {
	env_t_579 env;
	env.m1_c = m1_c;
	return env;
}

value_t lambda579(env_t_579* env576, card_t r_c) {
	matrix3d_shape_t m1_c575 = env576->m1_c;
	value_t res;
	res.matrix_shape_t_value = m1_c575.elem;
	return res;
}
matrix3d_shape_t TOP_LEVEL_linalg_matrix3DConcat_c(matrix3d_shape_t m1_c, matrix3d_shape_t m2_c) {
	card_t rows_c = (m1_c.card) + (m2_c.card);
	card_t m1Rows_c = 0;
	env_t_579 env_t_579_value = make_env_t_579(m1_c); closure_t closure578 = make_closure(lambda579, &env_t_579_value);
	return nested_shape_matrix_shape_t(closure578.lam(closure578.env, 0).matrix_shape_t_value, rows_c);
}
array_array_array_number_t TOP_LEVEL_linalg_matrix3DConcat_s(storage_t stgVar566, array_array_array_number_t m1_s, array_array_array_number_t m2_s, matrix3d_shape_t m1_c, matrix3d_shape_t m2_c) {
	card_t rows_c = (m1_c.card) + (m2_c.card);
	card_t macroDef580 = m1_s->length;
	card_t macroDef581 = m2_s->length;
	card_t rows_s = (macroDef580) + (macroDef581);
	card_t m1Rows_c = 0;
	card_t macroDef582 = m1_s->length;
	index_t m1Rows_s = (macroDef582);
	array_array_array_number_t macroDef583 = (array_array_array_number_t)stgVar566;
		for(int r_s = 0; r_s < macroDef583->length; r_s++){
			storage_t stgVar572 = &macroDef583->arr[r_s];
			array_array_number_t ite584 = 0;
	if((r_s) < (m1Rows_s)) {
		
		ite584 = m1_s->arr[r_s];
	} else {
		
		ite584 = m2_s->arr[(r_s) - (m1Rows_s)];
	}
			macroDef583->arr[r_s] = ite584;
		}
	return macroDef583;
}

array_number_t TOP_LEVEL_linalg_vectorRead(string_t fn, index_t startLine) {
	array_array_number_t matrix = matrix_read(fn, startLine, 1);
	return matrix->arr[0];
}
vector_shape_t TOP_LEVEL_linalg_vectorRead_c(card_t fn_c, card_t startLine_c) {
	matrix_shape_t matrix_c = nested_shape_vector_shape_t(nested_shape_card_t(0, 10), 1);
	return matrix_c.elem;
}
array_number_t TOP_LEVEL_linalg_vectorRead_s(storage_t stgVar585, string_t fn_s, index_t startLine_s, card_t fn_c, card_t startLine_c) {
	matrix_shape_t matrix_c = nested_shape_vector_shape_t(nested_shape_card_t(0, 10), 1);
	array_number_t stgVar586 = vector_alloc(width_matrix_shape_t(matrix_c));
	array_number_t macroDef588;array_array_number_t matrix_s = matrix_read(stgVar586, fn, startLine, 1);
	macroDef588 = matrix_s->arr[0];
	free(stgVar586);
	return macroDef588;
}

number_t TOP_LEVEL_linalg_numberRead(string_t fn, index_t startLine) {
	array_number_t vector = TOP_LEVEL_linalg_vectorRead(fn, startLine);
	return vector->arr[0];
}
card_t TOP_LEVEL_linalg_numberRead_c(card_t fn_c, card_t startLine_c) {
	
	return 0;
}
number_t TOP_LEVEL_linalg_numberRead_s(storage_t stgVar589, string_t fn_s, index_t startLine_s, card_t fn_c, card_t startLine_c) {
	vector_shape_t vector_c = TOP_LEVEL_linalg_vectorRead_c(fn_c, 0);
	array_number_t stgVar590 = vector_alloc(width_vector_shape_t(vector_c));
	number_t macroDef594;array_number_t vector_s = TOP_LEVEL_linalg_vectorRead_s(stgVar590, fn_s, startLine_s, fn_c, 0);
	macroDef594 = vector_s->arr[0];
	free(stgVar590);
	return macroDef594;
}
#endif
