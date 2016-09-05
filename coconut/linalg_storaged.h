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
	array_array_number_t macroDef45 = (array_array_number_t)stgVar33;
		for(int i_s = 0; i_s < macroDef45->length; i_s++){
			storage_t stgVar35 = &macroDef45->arr[i_s];
			
			macroDef45->arr[i_s] = f_s.lam(f_s.env, stgVar35, m_s->arr[i_s], m_c.elem).array_number_t_value;
		}
	return macroDef45;
}

array_number_t TOP_LEVEL_linalg_vectorMap2(closure_t f, array_number_t v1, array_number_t v2) {
	card_t macroDef46 = v1->length;
	array_number_t macroDef47 = (array_number_t)malloc(sizeof(int) * 2);
	macroDef47->length=macroDef46;
	macroDef47->arr = (number_t*)malloc(sizeof(number_t) * macroDef46);
		for(int i = 0; i < macroDef47->length; i++){
			
			macroDef47->arr[i] = f.lam(f.env, v1->arr[i], v2->arr[i]).number_t_value;
		}
	return macroDef47;
}typedef empty_env_t env_t_58;


value_t lambda58(env_t_58* env55, card_t i_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
vector_shape_t TOP_LEVEL_linalg_vectorMap2_c(closure_t f_c, vector_shape_t v1_c, vector_shape_t v2_c) {
	env_t_58 env_t_58_value = make_empty_env(); closure_t closure57 = make_closure(lambda58, &env_t_58_value);
	return nested_shape_card_t(closure57.lam(closure57.env, 0).card_t_value, v1_c.card);
}
array_number_t TOP_LEVEL_linalg_vectorMap2_s(storage_t stgVar48, closure_t f_s, array_number_t v1_s, array_number_t v2_s, closure_t f_c, vector_shape_t v1_c, vector_shape_t v2_c) {
	card_t macroDef59 = v1_s->length;
	array_number_t macroDef60 = (array_number_t)stgVar48;
		for(int i_s = 0; i_s < macroDef60->length; i_s++){
			storage_t stgVar50 = &macroDef60->arr[i_s];
			
			macroDef60->arr[i_s] = f_s.lam(f_s.env, stgVar50, v1_s->arr[i_s], v2_s->arr[i_s], 0, 0).number_t_value;
		}
	return macroDef60;
}

array_array_number_t TOP_LEVEL_linalg_matrixMap2(closure_t f, array_array_number_t m1, array_array_number_t m2) {
	card_t macroDef61 = m1->length;
	array_array_number_t macroDef62 = (array_array_number_t)malloc(sizeof(int) * 2);
	macroDef62->length=macroDef61;
	macroDef62->arr = (array_number_t*)malloc(sizeof(array_number_t) * macroDef61);
		for(int i = 0; i < macroDef62->length; i++){
			
			macroDef62->arr[i] = f.lam(f.env, m1->arr[i], m2->arr[i]).array_number_t_value;
		}
	return macroDef62;
}typedef struct env_t_76 {
	matrix_shape_t m2_c;
	matrix_shape_t m1_c;
	closure_t f_c;
} env_t_76;
env_t_76 make_env_t_76(matrix_shape_t m2_c,matrix_shape_t m1_c,closure_t f_c) {
	env_t_76 env;
	env.m2_c = m2_c;
	env.m1_c = m1_c;
	env.f_c = f_c;
	return env;
}

value_t lambda76(env_t_76* env73, card_t i_c) {
	matrix_shape_t m2_c72 = env73->m2_c;
	matrix_shape_t m1_c71 = env73->m1_c;
	closure_t f_c70 = env73->f_c;
	value_t res;
	res.vector_shape_t_value = f_c70.lam(f_c70.env, m1_c71.elem, m2_c72.elem).vector_shape_t_value;
	return res;
}
matrix_shape_t TOP_LEVEL_linalg_matrixMap2_c(closure_t f_c, matrix_shape_t m1_c, matrix_shape_t m2_c) {
	env_t_76 env_t_76_value = make_env_t_76(m2_c,m1_c,f_c); closure_t closure75 = make_closure(lambda76, &env_t_76_value);
	return nested_shape_vector_shape_t(closure75.lam(closure75.env, 0).vector_shape_t_value, m1_c.card);
}
array_array_number_t TOP_LEVEL_linalg_matrixMap2_s(storage_t stgVar63, closure_t f_s, array_array_number_t m1_s, array_array_number_t m2_s, closure_t f_c, matrix_shape_t m1_c, matrix_shape_t m2_c) {
	card_t macroDef77 = m1_s->length;
	array_array_number_t macroDef78 = (array_array_number_t)stgVar63;
		for(int i_s = 0; i_s < macroDef78->length; i_s++){
			storage_t stgVar65 = &macroDef78->arr[i_s];
			
			macroDef78->arr[i_s] = f_s.lam(f_s.env, stgVar65, m1_s->arr[i_s], m2_s->arr[i_s], m1_c.elem, m2_c.elem).array_number_t_value;
		}
	return macroDef78;
}

array_array_array_number_t TOP_LEVEL_linalg_matrix3DMap2(closure_t f, array_array_array_number_t m1, array_array_array_number_t m2) {
	card_t macroDef79 = m1->length;
	array_array_array_number_t macroDef80 = (array_array_array_number_t)malloc(sizeof(int) * 2);
	macroDef80->length=macroDef79;
	macroDef80->arr = (array_array_number_t*)malloc(sizeof(array_array_number_t) * macroDef79);
		for(int i = 0; i < macroDef80->length; i++){
			
			macroDef80->arr[i] = f.lam(f.env, m1->arr[i], m2->arr[i]).array_array_number_t_value;
		}
	return macroDef80;
}typedef struct env_t_94 {
	matrix3d_shape_t m2_c;
	matrix3d_shape_t m1_c;
	closure_t f_c;
} env_t_94;
env_t_94 make_env_t_94(matrix3d_shape_t m2_c,matrix3d_shape_t m1_c,closure_t f_c) {
	env_t_94 env;
	env.m2_c = m2_c;
	env.m1_c = m1_c;
	env.f_c = f_c;
	return env;
}

value_t lambda94(env_t_94* env91, card_t i_c) {
	matrix3d_shape_t m2_c90 = env91->m2_c;
	matrix3d_shape_t m1_c89 = env91->m1_c;
	closure_t f_c88 = env91->f_c;
	value_t res;
	res.matrix_shape_t_value = f_c88.lam(f_c88.env, m1_c89.elem, m2_c90.elem).matrix_shape_t_value;
	return res;
}
matrix3d_shape_t TOP_LEVEL_linalg_matrix3DMap2_c(closure_t f_c, matrix3d_shape_t m1_c, matrix3d_shape_t m2_c) {
	env_t_94 env_t_94_value = make_env_t_94(m2_c,m1_c,f_c); closure_t closure93 = make_closure(lambda94, &env_t_94_value);
	return nested_shape_matrix_shape_t(closure93.lam(closure93.env, 0).matrix_shape_t_value, m1_c.card);
}
array_array_array_number_t TOP_LEVEL_linalg_matrix3DMap2_s(storage_t stgVar81, closure_t f_s, array_array_array_number_t m1_s, array_array_array_number_t m2_s, closure_t f_c, matrix3d_shape_t m1_c, matrix3d_shape_t m2_c) {
	card_t macroDef95 = m1_s->length;
	array_array_array_number_t macroDef96 = (array_array_array_number_t)stgVar81;
		for(int i_s = 0; i_s < macroDef96->length; i_s++){
			storage_t stgVar83 = &macroDef96->arr[i_s];
			
			macroDef96->arr[i_s] = f_s.lam(f_s.env, stgVar83, m1_s->arr[i_s], m2_s->arr[i_s], m1_c.elem, m2_c.elem).array_array_number_t_value;
		}
	return macroDef96;
}

array_array_number_t TOP_LEVEL_linalg_vectorMapToMatrix(closure_t f, array_number_t arr) {
	card_t macroDef97 = arr->length;
	array_array_number_t macroDef98 = (array_array_number_t)malloc(sizeof(int) * 2);
	macroDef98->length=macroDef97;
	macroDef98->arr = (array_number_t*)malloc(sizeof(array_number_t) * macroDef97);
		for(int i = 0; i < macroDef98->length; i++){
			
			macroDef98->arr[i] = f.lam(f.env, arr->arr[i]).array_number_t_value;
		}
	return macroDef98;
}typedef struct env_t_108 {
	closure_t f_c;
} env_t_108;
env_t_108 make_env_t_108(closure_t f_c) {
	env_t_108 env;
	env.f_c = f_c;
	return env;
}

value_t lambda108(env_t_108* env105, card_t i_c) {
	closure_t f_c104 = env105->f_c;
	value_t res;
	res.vector_shape_t_value = f_c104.lam(f_c104.env, 0).vector_shape_t_value;
	return res;
}
matrix_shape_t TOP_LEVEL_linalg_vectorMapToMatrix_c(closure_t f_c, vector_shape_t arr_c) {
	env_t_108 env_t_108_value = make_env_t_108(f_c); closure_t closure107 = make_closure(lambda108, &env_t_108_value);
	return nested_shape_vector_shape_t(closure107.lam(closure107.env, 0).vector_shape_t_value, arr_c.card);
}
array_array_number_t TOP_LEVEL_linalg_vectorMapToMatrix_s(storage_t stgVar99, closure_t f_s, array_number_t arr_s, closure_t f_c, vector_shape_t arr_c) {
	card_t macroDef109 = arr_s->length;
	array_array_number_t macroDef110 = (array_array_number_t)stgVar99;
		for(int i_s = 0; i_s < macroDef110->length; i_s++){
			storage_t stgVar101 = &macroDef110->arr[i_s];
			
			macroDef110->arr[i_s] = f_s.lam(f_s.env, stgVar101, arr_s->arr[i_s], 0).array_number_t_value;
		}
	return macroDef110;
}

array_array_array_number_t TOP_LEVEL_linalg_vectorMapToMatrix3D(closure_t f, array_number_t arr) {
	card_t macroDef111 = arr->length;
	array_array_array_number_t macroDef112 = (array_array_array_number_t)malloc(sizeof(int) * 2);
	macroDef112->length=macroDef111;
	macroDef112->arr = (array_array_number_t*)malloc(sizeof(array_array_number_t) * macroDef111);
		for(int i = 0; i < macroDef112->length; i++){
			
			macroDef112->arr[i] = f.lam(f.env, arr->arr[i]).array_array_number_t_value;
		}
	return macroDef112;
}typedef struct env_t_122 {
	closure_t f_c;
} env_t_122;
env_t_122 make_env_t_122(closure_t f_c) {
	env_t_122 env;
	env.f_c = f_c;
	return env;
}

value_t lambda122(env_t_122* env119, card_t i_c) {
	closure_t f_c118 = env119->f_c;
	value_t res;
	res.matrix_shape_t_value = f_c118.lam(f_c118.env, 0).matrix_shape_t_value;
	return res;
}
matrix3d_shape_t TOP_LEVEL_linalg_vectorMapToMatrix3D_c(closure_t f_c, vector_shape_t arr_c) {
	env_t_122 env_t_122_value = make_env_t_122(f_c); closure_t closure121 = make_closure(lambda122, &env_t_122_value);
	return nested_shape_matrix_shape_t(closure121.lam(closure121.env, 0).matrix_shape_t_value, arr_c.card);
}
array_array_array_number_t TOP_LEVEL_linalg_vectorMapToMatrix3D_s(storage_t stgVar113, closure_t f_s, array_number_t arr_s, closure_t f_c, vector_shape_t arr_c) {
	card_t macroDef123 = arr_s->length;
	array_array_array_number_t macroDef124 = (array_array_array_number_t)stgVar113;
		for(int i_s = 0; i_s < macroDef124->length; i_s++){
			storage_t stgVar115 = &macroDef124->arr[i_s];
			
			macroDef124->arr[i_s] = f_s.lam(f_s.env, stgVar115, arr_s->arr[i_s], 0).array_array_number_t_value;
		}
	return macroDef124;
}

number_t TOP_LEVEL_linalg_iterateNumber(closure_t f, number_t z, card_t s, card_t e) {
	number_t macroDef125 = z;
	for(int cur_idx = 0; cur_idx < TOP_LEVEL_linalg_vectorRange(s, e)->length; cur_idx++){
		number_t cur = TOP_LEVEL_linalg_vectorRange(s, e)->arr[cur_idx];
		
		macroDef125 = f.lam(f.env, macroDef125, (int)(cur)).number_t_value;
	}
	return macroDef125;
}
card_t TOP_LEVEL_linalg_iterateNumber_c(closure_t f_c, card_t z_c, card_t s_c, card_t e_c) {
	
	return 0;
}
number_t TOP_LEVEL_linalg_iterateNumber_s(storage_t stgVar126, closure_t f_s, number_t z_s, card_t s_s, card_t e_s, closure_t f_c, card_t z_c, card_t s_c, card_t e_c) {
	number_t macroDef132 = z_s;
	array_number_t cur_s_range = TOP_LEVEL_linalg_vectorRange_s(empty_storage, s_s, e_s, s_c, e_c);
	storage_t stgVar127 = stgVar126;
	for(int cur_s_idx = 0; cur_s_idx < cur_s_range->length; cur_s_idx++){
		number_t cur_s = cur_s_range->arr[cur_s_idx];
		
		macroDef132 = f_s.lam(f_s.env, stgVar127, macroDef132, (int)(cur_s), 0, 0).number_t_value;
	}
	return macroDef132;
}

array_number_t TOP_LEVEL_linalg_iterateVector(closure_t f, array_number_t z, card_t s, card_t e) {
	array_number_t macroDef133 = z;
	for(int cur_idx = 0; cur_idx < TOP_LEVEL_linalg_vectorRange(s, e)->length; cur_idx++){
		number_t cur = TOP_LEVEL_linalg_vectorRange(s, e)->arr[cur_idx];
		
		macroDef133 = f.lam(f.env, macroDef133, (int)(cur)).array_number_t_value;
	}
	return macroDef133;
}
vector_shape_t TOP_LEVEL_linalg_iterateVector_c(closure_t f_c, vector_shape_t z_c, card_t s_c, card_t e_c) {
	
	return z_c;
}
array_number_t TOP_LEVEL_linalg_iterateVector_s(storage_t stgVar134, closure_t f_s, array_number_t z_s, card_t s_s, card_t e_s, closure_t f_c, vector_shape_t z_c, card_t s_c, card_t e_c) {
	array_number_t macroDef140 = z_s;
	array_number_t cur_s_range = TOP_LEVEL_linalg_vectorRange_s(empty_storage, s_s, e_s, s_c, e_c);
	storage_t stgVar135 = stgVar134;
	for(int cur_s_idx = 0; cur_s_idx < cur_s_range->length; cur_s_idx++){
		number_t cur_s = cur_s_range->arr[cur_s_idx];
		
		macroDef140 = f_s.lam(f_s.env, stgVar135, macroDef140, (int)(cur_s), z_c, 0).array_number_t_value;
	}
	return macroDef140;
}

array_array_number_t TOP_LEVEL_linalg_iterateMatrix(closure_t f, array_array_number_t z, card_t s, card_t e) {
	array_array_number_t macroDef141 = z;
	for(int cur_idx = 0; cur_idx < TOP_LEVEL_linalg_vectorRange(s, e)->length; cur_idx++){
		number_t cur = TOP_LEVEL_linalg_vectorRange(s, e)->arr[cur_idx];
		
		macroDef141 = f.lam(f.env, macroDef141, (int)(cur)).array_array_number_t_value;
	}
	return macroDef141;
}
matrix_shape_t TOP_LEVEL_linalg_iterateMatrix_c(closure_t f_c, matrix_shape_t z_c, card_t s_c, card_t e_c) {
	
	return z_c;
}
array_array_number_t TOP_LEVEL_linalg_iterateMatrix_s(storage_t stgVar142, closure_t f_s, array_array_number_t z_s, card_t s_s, card_t e_s, closure_t f_c, matrix_shape_t z_c, card_t s_c, card_t e_c) {
	array_array_number_t macroDef148 = z_s;
	array_number_t cur_s_range = TOP_LEVEL_linalg_vectorRange_s(empty_storage, s_s, e_s, s_c, e_c);
	storage_t stgVar143 = stgVar142;
	for(int cur_s_idx = 0; cur_s_idx < cur_s_range->length; cur_s_idx++){
		number_t cur_s = cur_s_range->arr[cur_s_idx];
		
		macroDef148 = f_s.lam(f_s.env, stgVar143, macroDef148, (int)(cur_s), z_c, 0).array_array_number_t_value;
	}
	return macroDef148;
}

array_array_array_number_t TOP_LEVEL_linalg_iterateMatrix3D(closure_t f, array_array_array_number_t z, card_t s, card_t e) {
	array_array_array_number_t macroDef149 = z;
	for(int cur_idx = 0; cur_idx < TOP_LEVEL_linalg_vectorRange(s, e)->length; cur_idx++){
		number_t cur = TOP_LEVEL_linalg_vectorRange(s, e)->arr[cur_idx];
		
		macroDef149 = f.lam(f.env, macroDef149, (int)(cur)).array_array_array_number_t_value;
	}
	return macroDef149;
}
matrix3d_shape_t TOP_LEVEL_linalg_iterateMatrix3D_c(closure_t f_c, matrix3d_shape_t z_c, card_t s_c, card_t e_c) {
	
	return z_c;
}
array_array_array_number_t TOP_LEVEL_linalg_iterateMatrix3D_s(storage_t stgVar150, closure_t f_s, array_array_array_number_t z_s, card_t s_s, card_t e_s, closure_t f_c, matrix3d_shape_t z_c, card_t s_c, card_t e_c) {
	array_array_array_number_t macroDef156 = z_s;
	array_number_t cur_s_range = TOP_LEVEL_linalg_vectorRange_s(empty_storage, s_s, e_s, s_c, e_c);
	storage_t stgVar151 = stgVar150;
	for(int cur_s_idx = 0; cur_s_idx < cur_s_range->length; cur_s_idx++){
		number_t cur_s = cur_s_range->arr[cur_s_idx];
		
		macroDef156 = f_s.lam(f_s.env, stgVar151, macroDef156, (int)(cur_s), z_c, 0).array_array_array_number_t_value;
	}
	return macroDef156;
}

number_t TOP_LEVEL_linalg_arraySum(array_number_t arr) {
	number_t macroDef157 = 0;
	for(int cur_idx = 0; cur_idx < arr->length; cur_idx++){
		number_t cur = arr->arr[cur_idx];
		
		macroDef157 = (macroDef157) + (cur);
	}
	return macroDef157;
}
card_t TOP_LEVEL_linalg_arraySum_c(vector_shape_t arr_c) {
	
	return 0;
}
number_t TOP_LEVEL_linalg_arraySum_s(storage_t stgVar158, array_number_t arr_s, vector_shape_t arr_c) {
	number_t macroDef160 = 0;
	array_number_t cur_s_range = arr_s;
	storage_t stgVar159 = stgVar158;
	for(int cur_s_idx = 0; cur_s_idx < cur_s_range->length; cur_s_idx++){
		number_t cur_s = cur_s_range->arr[cur_s_idx];
		
		macroDef160 = (macroDef160) + (cur_s);
	}
	return macroDef160;
}

number_t TOP_LEVEL_linalg_arrayMax(array_number_t arr) {
	number_t macroDef161 = -1000;
	for(int cur_idx = 0; cur_idx < arr->length; cur_idx++){
		number_t cur = arr->arr[cur_idx];
		number_t ite162 = 0;
	if((macroDef161) > (cur)) {
		
		ite162 = macroDef161;
	} else {
		
		ite162 = cur;
	}
		macroDef161 = ite162;
	}
	return macroDef161;
}
card_t TOP_LEVEL_linalg_arrayMax_c(vector_shape_t arr_c) {
	
	return 0;
}
number_t TOP_LEVEL_linalg_arrayMax_s(storage_t stgVar163, array_number_t arr_s, vector_shape_t arr_c) {
	number_t macroDef165 = -1000;
	array_number_t cur_s_range = arr_s;
	storage_t stgVar164 = stgVar163;
	for(int cur_s_idx = 0; cur_s_idx < cur_s_range->length; cur_s_idx++){
		number_t cur_s = cur_s_range->arr[cur_s_idx];
		number_t ite166 = 0;
	if((macroDef165) > (cur_s)) {
		
		ite166 = macroDef165;
	} else {
		
		ite166 = cur_s;
	}
		macroDef165 = ite166;
	}
	return macroDef165;
}
typedef struct env_t_171 {
	number_t y;
} env_t_171;
env_t_171 make_env_t_171(number_t y) {
	env_t_171 env;
	env.y = y;
	return env;
}

value_t lambda171(env_t_171* env168, number_t a) {
	number_t y167 = env168->y;
	value_t res;
	res.number_t_value = (a) * (y167);
	return res;
}
array_number_t TOP_LEVEL_linalg_mult_by_scalar(array_number_t x, number_t y) {
	env_t_171 env_t_171_value = make_env_t_171(y); closure_t closure170 = make_closure(lambda171, &env_t_171_value);
	return TOP_LEVEL_linalg_vectorMap(closure170, x);
}typedef empty_env_t env_t_179;


value_t lambda179(env_t_179* env176, card_t a_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
vector_shape_t TOP_LEVEL_linalg_mult_by_scalar_c(vector_shape_t x_c, card_t y_c) {
	env_t_179 env_t_179_value = make_empty_env(); closure_t closure178 = make_closure(lambda179, &env_t_179_value);
	return TOP_LEVEL_linalg_vectorMap_c(closure178, x_c);
}typedef struct env_t_187 {
	number_t y_s;
} env_t_187;
env_t_187 make_env_t_187(number_t y_s) {
	env_t_187 env;
	env.y_s = y_s;
	return env;
}

value_t lambda187(env_t_187* env181, storage_t stgVar174, number_t a_s, card_t a_c) {
	number_t y_s180 = env181->y_s;
	value_t res;
	res.number_t_value = (a_s) * (y_s180);
	return res;
}
typedef empty_env_t env_t_188;


value_t lambda188(env_t_188* env184, card_t a_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
array_number_t TOP_LEVEL_linalg_mult_by_scalar_s(storage_t stgVar172, array_number_t x_s, number_t y_s, vector_shape_t x_c, card_t y_c) {
	env_t_187 env_t_187_value = make_env_t_187(y_s); closure_t closure183 = make_closure(lambda187, &env_t_187_value);
	env_t_188 env_t_188_value = make_empty_env(); closure_t closure186 = make_closure(lambda188, &env_t_188_value);
	return TOP_LEVEL_linalg_vectorMap_s(stgVar172, closure183, x_s, closure186, x_c);
}

array_number_t TOP_LEVEL_linalg_cross(array_number_t a, array_number_t b) {
	array_number_t array189 = (array_number_t)malloc(sizeof(int) * 2);
	array189->length=3;
	array189->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array189->arr[0] = ((a->arr[1]) * (b->arr[2])) - ((a->arr[2]) * (b->arr[1]));
	array189->arr[1] = ((a->arr[2]) * (b->arr[0])) - ((a->arr[0]) * (b->arr[2]));
	array189->arr[2] = ((a->arr[0]) * (b->arr[1])) - ((a->arr[1]) * (b->arr[0]));;
	return array189;
}
vector_shape_t TOP_LEVEL_linalg_cross_c(vector_shape_t a_c, vector_shape_t b_c) {
	
	return nested_shape_card_t(0, 3);
}
array_number_t TOP_LEVEL_linalg_cross_s(storage_t stgVar190, array_number_t a_s, array_number_t b_s, vector_shape_t a_c, vector_shape_t b_c) {
	array_number_t macroDef206 = (array_number_t)stgVar190;
	macroDef206->length=3;
	macroDef206->arr[0] = ((a_s->arr[1]) * (b_s->arr[2])) - ((a_s->arr[2]) * (b_s->arr[1]));
	macroDef206->arr[1] = ((a_s->arr[2]) * (b_s->arr[0])) - ((a_s->arr[0]) * (b_s->arr[2]));
	macroDef206->arr[2] = ((a_s->arr[0]) * (b_s->arr[1])) - ((a_s->arr[1]) * (b_s->arr[0]));;
	return macroDef206;
}
typedef empty_env_t env_t_210;


value_t lambda210(env_t_210* env207, number_t x, number_t y) {
	
	value_t res;
	res.number_t_value = (x) + (y);
	return res;
}
array_number_t TOP_LEVEL_linalg_add_vec(array_number_t x, array_number_t y) {
	env_t_210 env_t_210_value = make_empty_env(); closure_t closure209 = make_closure(lambda210, &env_t_210_value);
	return TOP_LEVEL_linalg_vectorMap2(closure209, x, y);
}typedef empty_env_t env_t_219;


value_t lambda219(env_t_219* env216, card_t x_c, card_t y_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
vector_shape_t TOP_LEVEL_linalg_add_vec_c(vector_shape_t x_c, vector_shape_t y_c) {
	env_t_219 env_t_219_value = make_empty_env(); closure_t closure218 = make_closure(lambda219, &env_t_219_value);
	return TOP_LEVEL_linalg_vectorMap2_c(closure218, x_c, y_c);
}typedef empty_env_t env_t_226;


value_t lambda226(env_t_226* env220, storage_t stgVar213, number_t x_s, number_t y_s, card_t x_c, card_t y_c) {
	
	value_t res;
	res.number_t_value = (x_s) + (y_s);
	return res;
}
typedef empty_env_t env_t_227;


value_t lambda227(env_t_227* env223, card_t x_c, card_t y_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
array_number_t TOP_LEVEL_linalg_add_vec_s(storage_t stgVar211, array_number_t x_s, array_number_t y_s, vector_shape_t x_c, vector_shape_t y_c) {
	env_t_226 env_t_226_value = make_empty_env(); closure_t closure222 = make_closure(lambda226, &env_t_226_value);
	env_t_227 env_t_227_value = make_empty_env(); closure_t closure225 = make_closure(lambda227, &env_t_227_value);
	return TOP_LEVEL_linalg_vectorMap2_s(stgVar211, closure222, x_s, y_s, closure225, x_c, y_c);
}
typedef empty_env_t env_t_231;


value_t lambda231(env_t_231* env228, number_t x, number_t y) {
	
	value_t res;
	res.number_t_value = (x) * (y);
	return res;
}
array_number_t TOP_LEVEL_linalg_mult_vec_elementwise(array_number_t x, array_number_t y) {
	env_t_231 env_t_231_value = make_empty_env(); closure_t closure230 = make_closure(lambda231, &env_t_231_value);
	return TOP_LEVEL_linalg_vectorMap2(closure230, x, y);
}typedef empty_env_t env_t_240;


value_t lambda240(env_t_240* env237, card_t x_c, card_t y_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
vector_shape_t TOP_LEVEL_linalg_mult_vec_elementwise_c(vector_shape_t x_c, vector_shape_t y_c) {
	env_t_240 env_t_240_value = make_empty_env(); closure_t closure239 = make_closure(lambda240, &env_t_240_value);
	return TOP_LEVEL_linalg_vectorMap2_c(closure239, x_c, y_c);
}typedef empty_env_t env_t_247;


value_t lambda247(env_t_247* env241, storage_t stgVar234, number_t x_s, number_t y_s, card_t x_c, card_t y_c) {
	
	value_t res;
	res.number_t_value = (x_s) * (y_s);
	return res;
}
typedef empty_env_t env_t_248;


value_t lambda248(env_t_248* env244, card_t x_c, card_t y_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
array_number_t TOP_LEVEL_linalg_mult_vec_elementwise_s(storage_t stgVar232, array_number_t x_s, array_number_t y_s, vector_shape_t x_c, vector_shape_t y_c) {
	env_t_247 env_t_247_value = make_empty_env(); closure_t closure243 = make_closure(lambda247, &env_t_247_value);
	env_t_248 env_t_248_value = make_empty_env(); closure_t closure246 = make_closure(lambda248, &env_t_248_value);
	return TOP_LEVEL_linalg_vectorMap2_s(stgVar232, closure243, x_s, y_s, closure246, x_c, y_c);
}

// array_number_t TOP_LEVEL_linalg_add_vec3(array_number_t x, array_number_t y, array_number_t z) {
	
// 	return TOP_LEVEL_linalg_add_vec(TOP_LEVEL_linalg_add_vec(x, y), z);
// }
// vector_shape_t TOP_LEVEL_linalg_add_vec3_c(vector_shape_t x_c, vector_shape_t y_c, vector_shape_t z_c) {
	
// 	return TOP_LEVEL_linalg_add_vec_c(TOP_LEVEL_linalg_add_vec_c(x_c, y_c), z_c);
// }
// array_number_t TOP_LEVEL_linalg_add_vec3_s(storage_t stgVar249, array_number_t x_s, array_number_t y_s, array_number_t z_s, vector_shape_t x_c, vector_shape_t y_c, vector_shape_t z_c) {
	
// 	return TOP_LEVEL_linalg_add_vec_s(stgVar249, TOP_LEVEL_linalg_add_vec_s(stgVar250, x_s, y_s, x_c, y_c), z_s, TOP_LEVEL_linalg_add_vec_c(x_c, y_c), z_c);
// }
// typedef empty_env_t env_t_257;


// value_t lambda257(env_t_257* env254, number_t x, number_t y) {
	
// 	value_t res;
// 	res.number_t_value = (x) - (y);
// 	return res;
// }
// array_number_t TOP_LEVEL_linalg_sub_vec(array_number_t x, array_number_t y) {
// 	env_t_257 env_t_257_value = make_empty_env(); closure_t closure256 = make_closure(lambda257, &env_t_257_value);
// 	return TOP_LEVEL_linalg_vectorMap2(closure256, x, y);
// }typedef empty_env_t env_t_266;


// value_t lambda266(env_t_266* env263, card_t x_c, card_t y_c) {
	
// 	value_t res;
// 	res.card_t_value = 0;
// 	return res;
// }
// vector_shape_t TOP_LEVEL_linalg_sub_vec_c(vector_shape_t x_c, vector_shape_t y_c) {
// 	env_t_266 env_t_266_value = make_empty_env(); closure_t closure265 = make_closure(lambda266, &env_t_266_value);
// 	return TOP_LEVEL_linalg_vectorMap2_c(closure265, x_c, y_c);
// }typedef empty_env_t env_t_273;


// value_t lambda273(env_t_273* env267, storage_t stgVar260, number_t x_s, number_t y_s, card_t x_c, card_t y_c) {
	
// 	value_t res;
// 	res.number_t_value = (x_s) - (y_s);
// 	return res;
// }
// typedef empty_env_t env_t_274;


// value_t lambda274(env_t_274* env270, card_t x_c, card_t y_c) {
	
// 	value_t res;
// 	res.card_t_value = 0;
// 	return res;
// }
// array_number_t TOP_LEVEL_linalg_sub_vec_s(storage_t stgVar258, array_number_t x_s, array_number_t y_s, vector_shape_t x_c, vector_shape_t y_c) {
// 	env_t_273 env_t_273_value = make_empty_env(); closure_t closure269 = make_closure(lambda273, &env_t_273_value);
// 	env_t_274 env_t_274_value = make_empty_env(); closure_t closure272 = make_closure(lambda274, &env_t_274_value);
// 	return TOP_LEVEL_linalg_vectorMap2_s(stgVar258, closure269, x_s, y_s, closure272, x_c, y_c);
// }
// typedef empty_env_t env_t_278;


// value_t lambda278(env_t_278* env275, array_number_t x, array_number_t y) {
	
// 	value_t res;
// 	res.array_number_t_value = TOP_LEVEL_linalg_add_vec(x, y);
// 	return res;
// }
// array_array_number_t TOP_LEVEL_linalg_matrixAdd(array_array_number_t x, array_array_number_t y) {
// 	env_t_278 env_t_278_value = make_empty_env(); closure_t closure277 = make_closure(lambda278, &env_t_278_value);
// 	return TOP_LEVEL_linalg_matrixMap2(closure277, x, y);
// }typedef struct env_t_290 {
// 	closure_t TOP_LEVEL_linalg_add_vec_c;
// } env_t_290;
// env_t_290 make_env_t_290(closure_t TOP_LEVEL_linalg_add_vec_c) {
// 	env_t_290 env;
// 	env.TOP_LEVEL_linalg_add_vec_c = TOP_LEVEL_linalg_add_vec_c;
// 	return env;
// }

// value_t lambda290(env_t_290* env287, vector_shape_t x_c, vector_shape_t y_c) {
// 	closure_t TOP_LEVEL_linalg_add_vec_c286 = env287->TOP_LEVEL_linalg_add_vec_c;
// 	value_t res;
// 	res.vector_shape_t_value = TOP_LEVEL_linalg_add_vec_c286(x_c, y_c);
// 	return res;
// }
// matrix_shape_t TOP_LEVEL_linalg_matrixAdd_c(matrix_shape_t x_c, matrix_shape_t y_c) {
// 	env_t_290 env_t_290_value = make_env_t_290(TOP_LEVEL_linalg_add_vec_c); closure_t closure289 = make_closure(lambda290, &env_t_290_value);
// 	return TOP_LEVEL_linalg_matrixMap2_c(closure289, x_c, y_c);
// }typedef struct env_t_299 {
// 	closure_t TOP_LEVEL_linalg_add_vec_s;
// } env_t_299;
// env_t_299 make_env_t_299(closure_t TOP_LEVEL_linalg_add_vec_s) {
// 	env_t_299 env;
// 	env.TOP_LEVEL_linalg_add_vec_s = TOP_LEVEL_linalg_add_vec_s;
// 	return env;
// }

// value_t lambda299(env_t_299* env292, storage_t stgVar281, array_number_t x_s, array_number_t y_s, vector_shape_t x_c, vector_shape_t y_c) {
// 	closure_t TOP_LEVEL_linalg_add_vec_s291 = env292->TOP_LEVEL_linalg_add_vec_s;
// 	value_t res;
// 	res.array_number_t_value = TOP_LEVEL_linalg_add_vec_s291(stgVar281, x_s, y_s, x_c, y_c);
// 	return res;
// }
// typedef struct env_t_300 {
// 	closure_t TOP_LEVEL_linalg_add_vec_c;
// } env_t_300;
// env_t_300 make_env_t_300(closure_t TOP_LEVEL_linalg_add_vec_c) {
// 	env_t_300 env;
// 	env.TOP_LEVEL_linalg_add_vec_c = TOP_LEVEL_linalg_add_vec_c;
// 	return env;
// }

// value_t lambda300(env_t_300* env296, vector_shape_t x_c, vector_shape_t y_c) {
// 	closure_t TOP_LEVEL_linalg_add_vec_c295 = env296->TOP_LEVEL_linalg_add_vec_c;
// 	value_t res;
// 	res.vector_shape_t_value = TOP_LEVEL_linalg_add_vec_c295(x_c, y_c);
// 	return res;
// }
// array_array_number_t TOP_LEVEL_linalg_matrixAdd_s(storage_t stgVar279, array_array_number_t x_s, array_array_number_t y_s, matrix_shape_t x_c, matrix_shape_t y_c) {
// 	env_t_299 env_t_299_value = make_env_t_299(TOP_LEVEL_linalg_add_vec_s); closure_t closure294 = make_closure(lambda299, &env_t_299_value);
// 	env_t_300 env_t_300_value = make_env_t_300(TOP_LEVEL_linalg_add_vec_c); closure_t closure298 = make_closure(lambda300, &env_t_300_value);
// 	return TOP_LEVEL_linalg_matrixMap2_s(stgVar279, closure294, x_s, y_s, closure298, x_c, y_c);
// }
// typedef empty_env_t env_t_304;


// value_t lambda304(env_t_304* env301, array_number_t x, array_number_t y) {
	
// 	value_t res;
// 	res.array_number_t_value = TOP_LEVEL_linalg_mult_vec_elementwise(x, y);
// 	return res;
// }
// array_array_number_t TOP_LEVEL_linalg_matrixMultElementwise(array_array_number_t x, array_array_number_t y) {
// 	env_t_304 env_t_304_value = make_empty_env(); closure_t closure303 = make_closure(lambda304, &env_t_304_value);
// 	return TOP_LEVEL_linalg_matrixMap2(closure303, x, y);
// }typedef struct env_t_316 {
// 	closure_t TOP_LEVEL_linalg_mult_vec_elementwise_c;
// } env_t_316;
// env_t_316 make_env_t_316(closure_t TOP_LEVEL_linalg_mult_vec_elementwise_c) {
// 	env_t_316 env;
// 	env.TOP_LEVEL_linalg_mult_vec_elementwise_c = TOP_LEVEL_linalg_mult_vec_elementwise_c;
// 	return env;
// }

// value_t lambda316(env_t_316* env313, vector_shape_t x_c, vector_shape_t y_c) {
// 	closure_t TOP_LEVEL_linalg_mult_vec_elementwise_c312 = env313->TOP_LEVEL_linalg_mult_vec_elementwise_c;
// 	value_t res;
// 	res.vector_shape_t_value = TOP_LEVEL_linalg_mult_vec_elementwise_c312(x_c, y_c);
// 	return res;
// }
// matrix_shape_t TOP_LEVEL_linalg_matrixMultElementwise_c(matrix_shape_t x_c, matrix_shape_t y_c) {
// 	env_t_316 env_t_316_value = make_env_t_316(TOP_LEVEL_linalg_mult_vec_elementwise_c); closure_t closure315 = make_closure(lambda316, &env_t_316_value);
// 	return TOP_LEVEL_linalg_matrixMap2_c(closure315, x_c, y_c);
// }typedef struct env_t_325 {
// 	closure_t TOP_LEVEL_linalg_mult_vec_elementwise_s;
// } env_t_325;
// env_t_325 make_env_t_325(closure_t TOP_LEVEL_linalg_mult_vec_elementwise_s) {
// 	env_t_325 env;
// 	env.TOP_LEVEL_linalg_mult_vec_elementwise_s = TOP_LEVEL_linalg_mult_vec_elementwise_s;
// 	return env;
// }

// value_t lambda325(env_t_325* env318, storage_t stgVar307, array_number_t x_s, array_number_t y_s, vector_shape_t x_c, vector_shape_t y_c) {
// 	closure_t TOP_LEVEL_linalg_mult_vec_elementwise_s317 = env318->TOP_LEVEL_linalg_mult_vec_elementwise_s;
// 	value_t res;
// 	res.array_number_t_value = TOP_LEVEL_linalg_mult_vec_elementwise_s317(stgVar307, x_s, y_s, x_c, y_c);
// 	return res;
// }
// typedef struct env_t_326 {
// 	closure_t TOP_LEVEL_linalg_mult_vec_elementwise_c;
// } env_t_326;
// env_t_326 make_env_t_326(closure_t TOP_LEVEL_linalg_mult_vec_elementwise_c) {
// 	env_t_326 env;
// 	env.TOP_LEVEL_linalg_mult_vec_elementwise_c = TOP_LEVEL_linalg_mult_vec_elementwise_c;
// 	return env;
// }

// value_t lambda326(env_t_326* env322, vector_shape_t x_c, vector_shape_t y_c) {
// 	closure_t TOP_LEVEL_linalg_mult_vec_elementwise_c321 = env322->TOP_LEVEL_linalg_mult_vec_elementwise_c;
// 	value_t res;
// 	res.vector_shape_t_value = TOP_LEVEL_linalg_mult_vec_elementwise_c321(x_c, y_c);
// 	return res;
// }
// array_array_number_t TOP_LEVEL_linalg_matrixMultElementwise_s(storage_t stgVar305, array_array_number_t x_s, array_array_number_t y_s, matrix_shape_t x_c, matrix_shape_t y_c) {
// 	env_t_325 env_t_325_value = make_env_t_325(TOP_LEVEL_linalg_mult_vec_elementwise_s); closure_t closure320 = make_closure(lambda325, &env_t_325_value);
// 	env_t_326 env_t_326_value = make_env_t_326(TOP_LEVEL_linalg_mult_vec_elementwise_c); closure_t closure324 = make_closure(lambda326, &env_t_326_value);
// 	return TOP_LEVEL_linalg_matrixMap2_s(stgVar305, closure320, x_s, y_s, closure324, x_c, y_c);
// }
// typedef empty_env_t env_t_330;


// value_t lambda330(env_t_330* env327, number_t x1) {
	
// 	value_t res;
// 	res.number_t_value = (x1) * (x1);
// 	return res;
// }
// number_t TOP_LEVEL_linalg_sqnorm(array_number_t x) {
// 	env_t_330 env_t_330_value = make_empty_env(); closure_t closure329 = make_closure(lambda330, &env_t_330_value);
// 	return TOP_LEVEL_linalg_arraySum(TOP_LEVEL_linalg_vectorMap(closure329, x));
// }
// card_t TOP_LEVEL_linalg_sqnorm_c(vector_shape_t x_c) {
	
// 	return 0;
// }typedef empty_env_t env_t_345;


// value_t lambda345(env_t_345* env336, storage_t stgVar334, number_t x1_s, card_t x1_c) {
	
// 	value_t res;
// 	res.number_t_value = (x1_s) * (x1_s);
// 	return res;
// }
// typedef empty_env_t env_t_346;


// value_t lambda346(env_t_346* env339, card_t x1_c) {
	
// 	value_t res;
// 	res.card_t_value = 0;
// 	return res;
// }
// typedef empty_env_t env_t_347;


// value_t lambda347(env_t_347* env342, card_t x1_c) {
	
// 	value_t res;
// 	res.card_t_value = 0;
// 	return res;
// }
// number_t TOP_LEVEL_linalg_sqnorm_s(storage_t stgVar331, array_number_t x_s, vector_shape_t x_c) {
// 	env_t_345 env_t_345_value = make_empty_env(); closure_t closure338 = make_closure(lambda345, &env_t_345_value);
// 	env_t_346 env_t_346_value = make_empty_env(); closure_t closure341 = make_closure(lambda346, &env_t_346_value);
// 	env_t_347 env_t_347_value = make_empty_env(); closure_t closure344 = make_closure(lambda347, &env_t_347_value);
// 	return TOP_LEVEL_linalg_arraySum_s(stgVar331, TOP_LEVEL_linalg_vectorMap_s(stgVar332, closure338, x_s, closure341, x_c), TOP_LEVEL_linalg_vectorMap_c(closure344, x_c));
// }
// typedef empty_env_t env_t_351;


// value_t lambda351(env_t_351* env348, number_t x, number_t y) {
	
// 	value_t res;
// 	res.number_t_value = (x) * (y);
// 	return res;
// }
// number_t TOP_LEVEL_linalg_dot_prod(array_number_t x, array_number_t y) {
// 	env_t_351 env_t_351_value = make_empty_env(); closure_t closure350 = make_closure(lambda351, &env_t_351_value);
// 	return TOP_LEVEL_linalg_arraySum(TOP_LEVEL_linalg_vectorMap2(closure350, x, y));
// }
// card_t TOP_LEVEL_linalg_dot_prod_c(vector_shape_t x_c, vector_shape_t y_c) {
	
// 	return 0;
// }typedef empty_env_t env_t_367;


// value_t lambda367(env_t_367* env358, storage_t stgVar355, number_t x_s, number_t y_s, card_t x_c, card_t y_c) {
	
// 	value_t res;
// 	res.number_t_value = (x_s) * (y_s);
// 	return res;
// }
// typedef empty_env_t env_t_368;


// value_t lambda368(env_t_368* env361, card_t x_c, card_t y_c) {
	
// 	value_t res;
// 	res.card_t_value = 0;
// 	return res;
// }
// typedef empty_env_t env_t_369;


// value_t lambda369(env_t_369* env364, card_t x_c, card_t y_c) {
	
// 	value_t res;
// 	res.card_t_value = 0;
// 	return res;
// }
// number_t TOP_LEVEL_linalg_dot_prod_s(storage_t stgVar352, array_number_t x_s, array_number_t y_s, vector_shape_t x_c, vector_shape_t y_c) {
// 	env_t_367 env_t_367_value = make_empty_env(); closure_t closure360 = make_closure(lambda367, &env_t_367_value);
// 	env_t_368 env_t_368_value = make_empty_env(); closure_t closure363 = make_closure(lambda368, &env_t_368_value);
// 	env_t_369 env_t_369_value = make_empty_env(); closure_t closure366 = make_closure(lambda369, &env_t_369_value);
// 	return TOP_LEVEL_linalg_arraySum_s(stgVar352, TOP_LEVEL_linalg_vectorMap2_s(stgVar353, closure360, x_s, y_s, closure363, x_c, y_c), TOP_LEVEL_linalg_vectorMap2_c(closure366, x_c, y_c));
// }
// typedef struct env_t_374 {
// 	array_number_t row;
// } env_t_374;
// env_t_374 make_env_t_374(array_number_t row) {
// 	env_t_374 env;
// 	env.row = row;
// 	return env;
// }

// value_t lambda374(env_t_374* env371, number_t r) {
// 	array_number_t row370 = env371->row;
// 	value_t res;
// 	res.array_number_t_value = row370;
// 	return res;
// }
// array_array_number_t TOP_LEVEL_linalg_matrixFillFromVector(card_t rows, array_number_t row) {
// 	env_t_374 env_t_374_value = make_env_t_374(row); closure_t closure373 = make_closure(lambda374, &env_t_374_value);
// 	return TOP_LEVEL_linalg_vectorMapToMatrix(closure373, TOP_LEVEL_linalg_vectorRange(1, rows));
// }typedef struct env_t_385 {
// 	vector_shape_t row_c;
// } env_t_385;
// env_t_385 make_env_t_385(vector_shape_t row_c) {
// 	env_t_385 env;
// 	env.row_c = row_c;
// 	return env;
// }

// value_t lambda385(env_t_385* env382, card_t r_c) {
// 	vector_shape_t row_c381 = env382->row_c;
// 	value_t res;
// 	res.vector_shape_t_value = row_c381;
// 	return res;
// }
// matrix_shape_t TOP_LEVEL_linalg_matrixFillFromVector_c(card_t rows_c, vector_shape_t row_c) {
// 	env_t_385 env_t_385_value = make_env_t_385(row_c); closure_t closure384 = make_closure(lambda385, &env_t_385_value);
// 	return TOP_LEVEL_linalg_vectorMapToMatrix_c(closure384, TOP_LEVEL_linalg_vectorRange_c(1, rows_c));
// }typedef struct env_t_394 {
// 	array_number_t row_s;
// } env_t_394;
// env_t_394 make_env_t_394(array_number_t row_s) {
// 	env_t_394 env;
// 	env.row_s = row_s;
// 	return env;
// }

// value_t lambda394(env_t_394* env387, storage_t stgVar377, number_t r_s, card_t r_c) {
// 	array_number_t row_s386 = env387->row_s;
// 	value_t res;
// 	res.array_number_t_value = row_s386;
// 	return res;
// }
// typedef struct env_t_395 {
// 	vector_shape_t row_c;
// } env_t_395;
// env_t_395 make_env_t_395(vector_shape_t row_c) {
// 	env_t_395 env;
// 	env.row_c = row_c;
// 	return env;
// }

// value_t lambda395(env_t_395* env391, card_t r_c) {
// 	vector_shape_t row_c390 = env391->row_c;
// 	value_t res;
// 	res.vector_shape_t_value = row_c390;
// 	return res;
// }
// array_array_number_t TOP_LEVEL_linalg_matrixFillFromVector_s(storage_t stgVar375, card_t rows_s, array_number_t row_s, card_t rows_c, vector_shape_t row_c) {
// 	env_t_394 env_t_394_value = make_env_t_394(row_s); closure_t closure389 = make_closure(lambda394, &env_t_394_value);
// 	env_t_395 env_t_395_value = make_env_t_395(row_c); closure_t closure393 = make_closure(lambda395, &env_t_395_value);
// 	return TOP_LEVEL_linalg_vectorMapToMatrix_s(stgVar375, closure389, TOP_LEVEL_linalg_vectorRange_s(stgVar378, 1, rows_s, 1, rows_c), closure393, TOP_LEVEL_linalg_vectorRange_c(1, rows_c));
// }
// typedef struct env_t_400 {
// 	number_t value;
// } env_t_400;
// env_t_400 make_env_t_400(number_t value) {
// 	env_t_400 env;
// 	env.value = value;
// 	return env;
// }

// value_t lambda400(env_t_400* env397, number_t c) {
// 	number_t value396 = env397->value;
// 	value_t res;
// 	res.number_t_value = value396;
// 	return res;
// }
// array_array_number_t TOP_LEVEL_linalg_matrixFill(card_t rows, card_t cols, number_t value) {
// 	env_t_400 env_t_400_value = make_env_t_400(value); closure_t closure399 = make_closure(lambda400, &env_t_400_value);
// 	array_number_t row = TOP_LEVEL_linalg_vectorMap(closure399, TOP_LEVEL_linalg_vectorRange(1, cols));
// 	return TOP_LEVEL_linalg_matrixFillFromVector(rows, row);
// }typedef empty_env_t env_t_413;


// value_t lambda413(env_t_413* env410, card_t c_c) {
	
// 	value_t res;
// 	res.card_t_value = 0;
// 	return res;
// }
// matrix_shape_t TOP_LEVEL_linalg_matrixFill_c(card_t rows_c, card_t cols_c, card_t value_c) {
// 	env_t_413 env_t_413_value = make_empty_env(); closure_t closure412 = make_closure(lambda413, &env_t_413_value);
// 	vector_shape_t row_c = TOP_LEVEL_linalg_vectorMap_c(closure412, TOP_LEVEL_linalg_vectorRange_c(1, cols_c));
// 	return TOP_LEVEL_linalg_matrixFillFromVector_c(rows_c, row_c);
// }typedef empty_env_t env_t_425;


// value_t lambda425(env_t_425* env414, card_t c_c) {
	
// 	value_t res;
// 	res.card_t_value = 0;
// 	return res;
// }
// typedef struct env_t_426 {
// 	number_t value_s;
// } env_t_426;
// env_t_426 make_env_t_426(number_t value_s) {
// 	env_t_426 env;
// 	env.value_s = value_s;
// 	return env;
// }

// value_t lambda426(env_t_426* env418, storage_t stgVar404, number_t c_s, card_t c_c) {
// 	number_t value_s417 = env418->value_s;
// 	value_t res;
// 	res.number_t_value = value_s417;
// 	return res;
// }
// typedef empty_env_t env_t_427;


// value_t lambda427(env_t_427* env421, card_t c_c) {
	
// 	value_t res;
// 	res.card_t_value = 0;
// 	return res;
// }
// array_array_number_t TOP_LEVEL_linalg_matrixFill_s(storage_t stgVar401, card_t rows_s, card_t cols_s, number_t value_s, card_t rows_c, card_t cols_c, card_t value_c) {
// 	env_t_425 env_t_425_value = make_empty_env(); closure_t closure416 = make_closure(lambda425, &env_t_425_value);
// 	vector_shape_t row_c = TOP_LEVEL_linalg_vectorMap_c(closure416, TOP_LEVEL_linalg_vectorRange_c(1, cols_c));
// 	array_number_t stgVar402 = vector_alloc(width_vector_shape_t(row_c));
// 	env_t_426 env_t_426_value = make_env_t_426(value_s); closure_t closure420 = make_closure(lambda426, &env_t_426_value);
// 	env_t_427 env_t_427_value = make_empty_env(); closure_t closure423 = make_closure(lambda427, &env_t_427_value);
// 	array_number_t row_s = TOP_LEVEL_linalg_vectorMap_s(stgVar402, closure420, TOP_LEVEL_linalg_vectorRange_s(stgVar405, 1, cols_s, 1, cols_c), closure423, TOP_LEVEL_linalg_vectorRange_c(1, cols_c));
// 	macroDef424 = TOP_LEVEL_linalg_matrixFillFromVector_s(stgVar401, rows_s, row_s, rows_c, row_c);
// 	free(stgVar402);
// 	return macroDef424;
// }

// array_array_number_t TOP_LEVEL_linalg_matrixTranspose(array_array_number_t m) {
// 	card_t macroDef428 = m->length;
// 	card_t rows = macroDef428;
// 	card_t macroDef429 = m->arr[0]->length;
// 	card_t cols = macroDef429;
// 	array_array_number_t macroDef431 = (array_array_number_t)malloc(sizeof(int) * 2);
// 	macroDef431->length=cols;
// 	macroDef431->arr = (array_number_t*)malloc(sizeof(array_number_t) * cols);
// 		for(int i = 0; i < macroDef431->length; i++){
// 			array_number_t macroDef430 = (array_number_t)malloc(sizeof(int) * 2);
// 	macroDef430->length=rows;
// 	macroDef430->arr = (number_t*)malloc(sizeof(number_t) * rows);
// 		for(int j = 0; j < macroDef430->length; j++){
			
// 			macroDef430->arr[j] = m->arr[j]->arr[i];
// 		}
// 			macroDef431->arr[i] = macroDef430;
// 		}
// 	return macroDef431;
// }typedef struct env_t_449 {
// 	card_t rows_c;
// } env_t_449;
// env_t_449 make_env_t_449(card_t rows_c) {
// 	env_t_449 env;
// 	env.rows_c = rows_c;
// 	return env;
// }
// typedef empty_env_t env_t_450;


// value_t lambda450(env_t_450* env442, card_t j_c) {
	
// 	value_t res;
// 	res.card_t_value = 0;
// 	return res;
// }
// value_t lambda449(env_t_449* env446, card_t i_c) {
// 	card_t rows_c445 = env446->rows_c;
// 	env_t_450 env_t_450_value = make_empty_env(); closure_t closure444 = make_closure(lambda450, &env_t_450_value);
// 	value_t res;
// 	res.vector_shape_t_value = nested_shape_card_t(closure444.lam(closure444.env, 0).card_t_value, rows_c445);
// 	return res;
// }
// matrix_shape_t TOP_LEVEL_linalg_matrixTranspose_c(matrix_shape_t m_c) {
// 	card_t rows_c = m_c.card;
// 	card_t cols_c = m_c.elem.card;
// 	env_t_449 env_t_449_value = make_env_t_449(rows_c); closure_t closure448 = make_closure(lambda449, &env_t_449_value);
// 	return nested_shape_vector_shape_t(closure448.lam(closure448.env, 0).vector_shape_t_value, cols_c);
// }
// array_array_number_t TOP_LEVEL_linalg_matrixTranspose_s(storage_t stgVar432, array_array_number_t m_s, matrix_shape_t m_c) {
// 	card_t rows_c = m_c.card;
// 	card_t macroDef451 = m_s->length;
// 	card_t rows_s = macroDef451;
// 	card_t cols_c = m_c.elem.card;
// 	array_number_t stgVar436 = vector_alloc(width_vector_shape_t(m_c.elem));
// 	card_t macroDef452 = m_s->arr[0]->length;
// 	macroDef453 = macroDef452;
// 	free(stgVar436);
// 	card_t cols_s = macroDef453;
// 	array_array_number_t macroDef459 = (array_array_number_t)stgVar432;
// 		for(int i_s = 0; i_s < macroDef459->length; i_s++){
// 			storage_t stgVar438 = &macroDef459->arr[i_s];
// 			array_number_t macroDef455 = (array_number_t)stgVar438;
// 		for(int j_s = 0; j_s < macroDef455->length; j_s++){
// 			storage_t stgVar439 = &macroDef455->arr[j_s];
// 			array_number_t stgVar440 = vector_alloc(width_vector_shape_t(m_c.elem));
	
// 	macroDef454 = m_s->arr[j_s]->arr[i_s];
// 	free(stgVar440);
// 			macroDef455->arr[j_s] = macroDef454;
// 		}
// 			macroDef459->arr[i_s] = macroDef455;
// 		}
// 	return macroDef459;
// }

// array_array_number_t TOP_LEVEL_linalg_matrixMult(array_array_number_t m1, array_array_number_t m2) {
// 	card_t macroDef460 = m1->length;
// 	card_t r1 = macroDef460;
// 	card_t macroDef461 = m2->arr[0]->length;
// 	card_t c2 = macroDef461;
// 	card_t macroDef462 = m1->arr[0]->length;
// 	card_t c1 = macroDef462;
// 	card_t macroDef463 = m2->length;
// 	card_t r2 = macroDef463;
// 	array_array_number_t m2T = TOP_LEVEL_linalg_matrixTranspose(m2);
// 	array_array_number_t macroDef465 = (array_array_number_t)malloc(sizeof(int) * 2);
// 	macroDef465->length=r1;
// 	macroDef465->arr = (array_number_t*)malloc(sizeof(array_number_t) * r1);
// 		for(int r = 0; r < macroDef465->length; r++){
// 			array_number_t macroDef464 = (array_number_t)malloc(sizeof(int) * 2);
// 	macroDef464->length=c2;
// 	macroDef464->arr = (number_t*)malloc(sizeof(number_t) * c2);
// 		for(int c = 0; c < macroDef464->length; c++){
			
// 			macroDef464->arr[c] = TOP_LEVEL_linalg_dot_prod(m1->arr[r], m2T->arr[c]);
// 		}
// 			macroDef465->arr[r] = macroDef464;
// 		}
// 	return macroDef465;
// }typedef struct env_t_492 {
// 	card_t c2_c;
// } env_t_492;
// env_t_492 make_env_t_492(card_t c2_c) {
// 	env_t_492 env;
// 	env.c2_c = c2_c;
// 	return env;
// }
// typedef empty_env_t env_t_493;


// value_t lambda493(env_t_493* env485, card_t c_c) {
	
// 	value_t res;
// 	res.card_t_value = 0;
// 	return res;
// }
// value_t lambda492(env_t_492* env489, card_t r_c) {
// 	card_t c2_c488 = env489->c2_c;
// 	env_t_493 env_t_493_value = make_empty_env(); closure_t closure487 = make_closure(lambda493, &env_t_493_value);
// 	value_t res;
// 	res.vector_shape_t_value = nested_shape_card_t(closure487.lam(closure487.env, 0).card_t_value, c2_c488);
// 	return res;
// }
// matrix_shape_t TOP_LEVEL_linalg_matrixMult_c(matrix_shape_t m1_c, matrix_shape_t m2_c) {
// 	card_t r1_c = m1_c.card;
// 	card_t c2_c = m2_c.elem.card;
// 	card_t c1_c = m1_c.elem.card;
// 	card_t r2_c = m2_c.card;
// 	matrix_shape_t m2T_c = TOP_LEVEL_linalg_matrixTranspose_c(m2_c);
// 	env_t_492 env_t_492_value = make_env_t_492(c2_c); closure_t closure491 = make_closure(lambda492, &env_t_492_value);
// 	return nested_shape_vector_shape_t(closure491.lam(closure491.env, 0).vector_shape_t_value, r1_c);
// }
// array_array_number_t TOP_LEVEL_linalg_matrixMult_s(storage_t stgVar466, array_array_number_t m1_s, array_array_number_t m2_s, matrix_shape_t m1_c, matrix_shape_t m2_c) {
// 	card_t r1_c = m1_c.card;
// 	card_t macroDef494 = m1_s->length;
// 	card_t r1_s = macroDef494;
// 	card_t c2_c = m2_c.elem.card;
// 	array_number_t stgVar470 = vector_alloc(width_vector_shape_t(m2_c.elem));
// 	card_t macroDef495 = m2_s->arr[0]->length;
// 	macroDef496 = macroDef495;
// 	free(stgVar470);
// 	card_t c2_s = macroDef496;
// 	card_t c1_c = m1_c.elem.card;
// 	array_number_t stgVar473 = vector_alloc(width_vector_shape_t(m1_c.elem));
// 	card_t macroDef497 = m1_s->arr[0]->length;
// 	macroDef498 = macroDef497;
// 	free(stgVar473);
// 	card_t c1_s = macroDef498;
// 	card_t r2_c = m2_c.card;
// 	card_t macroDef499 = m2_s->length;
// 	card_t r2_s = macroDef499;
// 	matrix_shape_t m2T_c = TOP_LEVEL_linalg_matrixTranspose_c(m2_c);
// 	array_number_t stgVar477 = vector_alloc(width_matrix_shape_t(m2T_c));
// 	array_array_number_t m2T_s = TOP_LEVEL_linalg_matrixTranspose_s(stgVar477, m2_s, m2_c);
// 	array_array_number_t macroDef504 = (array_array_number_t)stgVar466;
// 		for(int r_s = 0; r_s < macroDef504->length; r_s++){
// 			storage_t stgVar479 = &macroDef504->arr[r_s];
// 			array_number_t macroDef500 = (array_number_t)stgVar479;
// 		for(int c_s = 0; c_s < macroDef500->length; c_s++){
// 			storage_t stgVar480 = &macroDef500->arr[c_s];
			
// 			macroDef500->arr[c_s] = TOP_LEVEL_linalg_dot_prod_s(stgVar480, m1_s->arr[r_s], m2T_s->arr[c_s], m1_c.elem, m2T_c.elem);
// 		}
// 			macroDef504->arr[r_s] = macroDef500;
// 		}
// 	macroDef505 = macroDef504;
// 	free(stgVar477);
// 	return macroDef505;
// }

// array_array_number_t TOP_LEVEL_linalg_matrixConcat(array_array_number_t m1, array_array_number_t m2) {
// 	card_t macroDef506 = m1->length;
// 	card_t macroDef507 = m2->length;
// 	card_t rows = (macroDef506) + (macroDef507);
// 	card_t macroDef508 = m1->length;
// 	index_t m1Rows = (macroDef508);
// 	array_array_number_t macroDef509 = (array_array_number_t)malloc(sizeof(int) * 2);
// 	macroDef509->length=rows;
// 	macroDef509->arr = (array_number_t*)malloc(sizeof(array_number_t) * rows);
// 		for(int r = 0; r < macroDef509->length; r++){
// 			array_number_t ite510 = 0;
// 	if((r) < (m1Rows)) {
		
// 		ite510 = m1->arr[r];
// 	} else {
		
// 		ite510 = m2->arr[(r) - (m1Rows)];
// 	}
// 			macroDef509->arr[r] = ite510;
// 		}
// 	return macroDef509;
// }typedef struct env_t_524 {
// 	matrix_shape_t m1_c;
// } env_t_524;
// env_t_524 make_env_t_524(matrix_shape_t m1_c) {
// 	env_t_524 env;
// 	env.m1_c = m1_c;
// 	return env;
// }

// value_t lambda524(env_t_524* env521, card_t r_c) {
// 	matrix_shape_t m1_c520 = env521->m1_c;
// 	value_t res;
// 	res.vector_shape_t_value = m1_c520.elem;
// 	return res;
// }
// matrix_shape_t TOP_LEVEL_linalg_matrixConcat_c(matrix_shape_t m1_c, matrix_shape_t m2_c) {
// 	card_t rows_c = (m1_c.card) + (m2_c.card);
// 	card_t m1Rows_c = 0;
// 	env_t_524 env_t_524_value = make_env_t_524(m1_c); closure_t closure523 = make_closure(lambda524, &env_t_524_value);
// 	return nested_shape_vector_shape_t(closure523.lam(closure523.env, 0).vector_shape_t_value, rows_c);
// }
// array_array_number_t TOP_LEVEL_linalg_matrixConcat_s(storage_t stgVar511, array_array_number_t m1_s, array_array_number_t m2_s, matrix_shape_t m1_c, matrix_shape_t m2_c) {
// 	card_t rows_c = (m1_c.card) + (m2_c.card);
// 	card_t macroDef525 = m1_s->length;
// 	card_t macroDef526 = m2_s->length;
// 	card_t rows_s = (macroDef525) + (macroDef526);
// 	card_t m1Rows_c = 0;
// 	card_t macroDef527 = m1_s->length;
// 	index_t m1Rows_s = (macroDef527);
// 	array_array_number_t macroDef528 = (array_array_number_t)stgVar511;
// 		for(int r_s = 0; r_s < macroDef528->length; r_s++){
// 			storage_t stgVar517 = &macroDef528->arr[r_s];
// 			array_number_t ite529 = 0;
// 	if((r_s) < (m1Rows_s)) {
		
// 		ite529 = m1_s->arr[r_s];
// 	} else {
		
// 		ite529 = m2_s->arr[(r_s) - (m1Rows_s)];
// 	}
// 			macroDef528->arr[r_s] = ite529;
// 		}
// 	return macroDef528;
// }

// array_array_number_t TOP_LEVEL_linalg_matrixConcatCol(array_array_number_t m1, array_array_number_t m2) {
// 	array_array_number_t m1t = TOP_LEVEL_linalg_matrixTranspose(m1);
// 	array_array_number_t m2t = TOP_LEVEL_linalg_matrixTranspose(m2);
// 	return TOP_LEVEL_linalg_matrixTranspose(TOP_LEVEL_linalg_matrixConcat(m1t, m2t));
// }
// matrix_shape_t TOP_LEVEL_linalg_matrixConcatCol_c(matrix_shape_t m1_c, matrix_shape_t m2_c) {
// 	matrix_shape_t m1t_c = TOP_LEVEL_linalg_matrixTranspose_c(m1_c);
// 	matrix_shape_t m2t_c = TOP_LEVEL_linalg_matrixTranspose_c(m2_c);
// 	return TOP_LEVEL_linalg_matrixTranspose_c(TOP_LEVEL_linalg_matrixConcat_c(m1t_c, m2t_c));
// }
// array_array_number_t TOP_LEVEL_linalg_matrixConcatCol_s(storage_t stgVar530, array_array_number_t m1_s, array_array_number_t m2_s, matrix_shape_t m1_c, matrix_shape_t m2_c) {
// 	matrix_shape_t m1t_c = TOP_LEVEL_linalg_matrixTranspose_c(m1_c);
// 	array_number_t stgVar531 = vector_alloc(width_matrix_shape_t(m1t_c));
// 	array_array_number_t m1t_s = TOP_LEVEL_linalg_matrixTranspose_s(stgVar531, m1_s, m1_c);
// 	matrix_shape_t m2t_c = TOP_LEVEL_linalg_matrixTranspose_c(m2_c);
// 	array_number_t stgVar533 = vector_alloc(width_matrix_shape_t(m2t_c));
// 	array_array_number_t m2t_s = TOP_LEVEL_linalg_matrixTranspose_s(stgVar533, m2_s, m2_c);
// 	macroDef538 = TOP_LEVEL_linalg_matrixTranspose_s(stgVar530, TOP_LEVEL_linalg_matrixConcat_s(stgVar535, m1t_s, m2t_s, m1t_c, m2t_c), TOP_LEVEL_linalg_matrixConcat_c(m1t_c, m2t_c));
// 	free(stgVar533);
// 	macroDef539 = macroDef538;
// 	free(stgVar531);
// 	return macroDef539;
// }

// array_array_array_number_t TOP_LEVEL_linalg_matrix3DConcat(array_array_array_number_t m1, array_array_array_number_t m2) {
// 	card_t macroDef540 = m1->length;
// 	card_t macroDef541 = m2->length;
// 	card_t rows = (macroDef540) + (macroDef541);
// 	card_t macroDef542 = m1->length;
// 	index_t m1Rows = (macroDef542);
// 	array_array_array_number_t macroDef543 = (array_array_array_number_t)malloc(sizeof(int) * 2);
// 	macroDef543->length=rows;
// 	macroDef543->arr = (array_array_number_t*)malloc(sizeof(array_array_number_t) * rows);
// 		for(int r = 0; r < macroDef543->length; r++){
// 			array_array_number_t ite544 = 0;
// 	if((r) < (m1Rows)) {
		
// 		ite544 = m1->arr[r];
// 	} else {
		
// 		ite544 = m2->arr[(r) - (m1Rows)];
// 	}
// 			macroDef543->arr[r] = ite544;
// 		}
// 	return macroDef543;
// }typedef struct env_t_558 {
// 	matrix3d_shape_t m1_c;
// } env_t_558;
// env_t_558 make_env_t_558(matrix3d_shape_t m1_c) {
// 	env_t_558 env;
// 	env.m1_c = m1_c;
// 	return env;
// }

// value_t lambda558(env_t_558* env555, card_t r_c) {
// 	matrix3d_shape_t m1_c554 = env555->m1_c;
// 	value_t res;
// 	res.matrix_shape_t_value = m1_c554.elem;
// 	return res;
// }
// matrix3d_shape_t TOP_LEVEL_linalg_matrix3DConcat_c(matrix3d_shape_t m1_c, matrix3d_shape_t m2_c) {
// 	card_t rows_c = (m1_c.card) + (m2_c.card);
// 	card_t m1Rows_c = 0;
// 	env_t_558 env_t_558_value = make_env_t_558(m1_c); closure_t closure557 = make_closure(lambda558, &env_t_558_value);
// 	return nested_shape_matrix_shape_t(closure557.lam(closure557.env, 0).matrix_shape_t_value, rows_c);
// }
// array_array_array_number_t TOP_LEVEL_linalg_matrix3DConcat_s(storage_t stgVar545, array_array_array_number_t m1_s, array_array_array_number_t m2_s, matrix3d_shape_t m1_c, matrix3d_shape_t m2_c) {
// 	card_t rows_c = (m1_c.card) + (m2_c.card);
// 	card_t macroDef559 = m1_s->length;
// 	card_t macroDef560 = m2_s->length;
// 	card_t rows_s = (macroDef559) + (macroDef560);
// 	card_t m1Rows_c = 0;
// 	card_t macroDef561 = m1_s->length;
// 	index_t m1Rows_s = (macroDef561);
// 	array_array_array_number_t macroDef562 = (array_array_array_number_t)stgVar545;
// 		for(int r_s = 0; r_s < macroDef562->length; r_s++){
// 			storage_t stgVar551 = &macroDef562->arr[r_s];
// 			array_array_number_t ite563 = 0;
// 	if((r_s) < (m1Rows_s)) {
		
// 		ite563 = m1_s->arr[r_s];
// 	} else {
		
// 		ite563 = m2_s->arr[(r_s) - (m1Rows_s)];
// 	}
// 			macroDef562->arr[r_s] = ite563;
// 		}
// 	return macroDef562;
// }

// array_number_t TOP_LEVEL_linalg_vectorRead(string_t fn, index_t startLine) {
// 	array_array_number_t matrix = matrix_read(fn, startLine, 1);
// 	return matrix->arr[0];
// }
// vector_shape_t TOP_LEVEL_linalg_vectorRead_c(card_t fn_c, card_t startLine_c) {
// 	matrix_shape_t matrix_c = nested_shape_vector_shape_t(nested_shape_card_t(0, 10), 1);
// 	return matrix_c.elem;
// }
// array_number_t TOP_LEVEL_linalg_vectorRead_s(storage_t stgVar564, string_t fn_s, index_t startLine_s, card_t fn_c, card_t startLine_c) {
// 	matrix_shape_t matrix_c = nested_shape_vector_shape_t(nested_shape_card_t(0, 10), 1);
// 	array_number_t stgVar565 = vector_alloc(width_matrix_shape_t(matrix_c));
// 	array_array_number_t matrix_s = matrix_read(stgVar565, fn, startLine, 1);
// 	macroDef567 = matrix_s->arr[0];
// 	free(stgVar565);
// 	return macroDef567;
// }

// number_t TOP_LEVEL_linalg_numberRead(string_t fn, index_t startLine) {
// 	array_number_t vector = TOP_LEVEL_linalg_vectorRead(fn, startLine);
// 	return vector->arr[0];
// }
// card_t TOP_LEVEL_linalg_numberRead_c(card_t fn_c, card_t startLine_c) {
	
// 	return 0;
// }
// number_t TOP_LEVEL_linalg_numberRead_s(storage_t stgVar568, string_t fn_s, index_t startLine_s, card_t fn_c, card_t startLine_c) {
// 	vector_shape_t vector_c = TOP_LEVEL_linalg_vectorRead_c(fn_c, 0);
// 	array_number_t stgVar569 = vector_alloc(width_vector_shape_t(vector_c));
// 	array_number_t vector_s = TOP_LEVEL_linalg_vectorRead_s(stgVar569, fn_s, startLine_s, fn_c, 0);
// 	macroDef573 = vector_s->arr[0];
// 	free(stgVar569);
// 	return macroDef573;
// }
#endif
