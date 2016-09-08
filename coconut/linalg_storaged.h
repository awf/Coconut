#ifndef __LINALG_STORAGED_H__ 
#define __LINALG_STORAGED_H__ 
#include "runtime/fsharp.h"
#include <stdio.h>
#include <math.h>
typedef empty_env_t env_t_9;


value_t lambda9(env_t_9* env6, card_t i_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
vector_shape_t TOP_LEVEL_linalg_vectorMap_c(closure_t f_c, vector_shape_t v_c) {
	env_t_9 env_t_9_value = make_empty_env(); closure_t closure8 = make_closure(lambda9, &env_t_9_value);
	return nested_shape_card_t(closure8.lam(closure8.env, 0).card_t_value, v_c.card);
}


array_number_t TOP_LEVEL_linalg_vectorMap_s(storage_t stgVar1, closure_t f_s, array_number_t v_s, closure_t f_c, vector_shape_t v_c) {
	card_t macroDef10 = v_s->length;
	array_number_t macroDef11 = (array_number_t)stgVar1;
		macroDef11->length=macroDef10;
		macroDef11->arr=(number_t*)(STG_OFFSET(macroDef11, VECTOR_HEADER_BYTES));
		storage_t stgVar3 = macroDef11;
		for(int i_s = 0; i_s < macroDef11->length; i_s++){
			
			macroDef11->arr[i_s] = f_s.lam(f_s.env, stgVar3, v_s->arr[i_s], 0).number_t_value;;
			stgVar3 = STG_OFFSET(stgVar3, sizeof(number_t));
		}
	return macroDef11;
}
typedef empty_env_t env_t_17;


value_t lambda17(env_t_17* env14, card_t i_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
vector_shape_t TOP_LEVEL_linalg_vectorRange_c(card_t s_c, card_t e_c) {
	env_t_17 env_t_17_value = make_empty_env(); closure_t closure16 = make_closure(lambda17, &env_t_17_value);
	return nested_shape_card_t(closure16.lam(closure16.env, 0).card_t_value, ((e_c) - (s_c)) + (1));
}


array_number_t TOP_LEVEL_linalg_vectorRange_s(storage_t stgVar12, card_t s_s, card_t e_s, card_t s_c, card_t e_c) {
	array_number_t macroDef18 = (array_number_t)stgVar12;
		macroDef18->length=((e_s) - (s_s)) + (1);
		macroDef18->arr=(number_t*)(STG_OFFSET(macroDef18, VECTOR_HEADER_BYTES));
		storage_t stgVar13 = macroDef18;
		for(int i_s = 0; i_s < macroDef18->length; i_s++){
			
			macroDef18->arr[i_s] = (double)(((s_s)) + (i_s));;
			stgVar13 = STG_OFFSET(stgVar13, sizeof(number_t));
		}
	return macroDef18;
}
typedef empty_env_t env_t_25;


value_t lambda25(env_t_25* env22, card_t i_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
vector_shape_t TOP_LEVEL_linalg_vectorSlice_c(card_t size_c, card_t offset_c, vector_shape_t v_c) {
	env_t_25 env_t_25_value = make_empty_env(); closure_t closure24 = make_closure(lambda25, &env_t_25_value);
	return nested_shape_card_t(closure24.lam(closure24.env, 0).card_t_value, size_c);
}


array_number_t TOP_LEVEL_linalg_vectorSlice_s(storage_t stgVar19, card_t size_s, index_t offset_s, array_number_t v_s, card_t size_c, card_t offset_c, vector_shape_t v_c) {
	array_number_t macroDef26 = (array_number_t)stgVar19;
		macroDef26->length=size_s;
		macroDef26->arr=(number_t*)(STG_OFFSET(macroDef26, VECTOR_HEADER_BYTES));
		storage_t stgVar20 = macroDef26;
		for(int i_s = 0; i_s < macroDef26->length; i_s++){
			
			macroDef26->arr[i_s] = v_s->arr[(i_s) + (offset_s)];;
			stgVar20 = STG_OFFSET(stgVar20, sizeof(number_t));
		}
	return macroDef26;
}
typedef struct env_t_37 {
	matrix_shape_t m_c;
	closure_t f_c;
} env_t_37;
env_t_37 make_env_t_37(matrix_shape_t m_c,closure_t f_c) {
	env_t_37 env;
	env.m_c = m_c;
	env.f_c = f_c;
	return env;
}

value_t lambda37(env_t_37* env34, card_t i_c) {
	matrix_shape_t m_c33 = env34->m_c;
	closure_t f_c32 = env34->f_c;
	value_t res;
	res.vector_shape_t_value = f_c32.lam(f_c32.env, m_c33.elem).vector_shape_t_value;
	return res;
}
matrix_shape_t TOP_LEVEL_linalg_matrixMap_c(closure_t f_c, matrix_shape_t m_c) {
	env_t_37 env_t_37_value = make_env_t_37(m_c,f_c); closure_t closure36 = make_closure(lambda37, &env_t_37_value);
	return nested_shape_vector_shape_t(closure36.lam(closure36.env, 0).vector_shape_t_value, m_c.card);
}


array_array_number_t TOP_LEVEL_linalg_matrixMap_s(storage_t stgVar27, closure_t f_s, array_array_number_t m_s, closure_t f_c, matrix_shape_t m_c) {
	card_t macroDef38 = m_s->length;
	array_array_number_t macroDef40 = (array_array_number_t)stgVar27;
		macroDef40->length=macroDef38;
		macroDef40->arr=(array_number_t*)(STG_OFFSET(macroDef40, VECTOR_HEADER_BYTES));
		storage_t stgVar29 = (STG_OFFSET(macroDef40, MATRIX_HEADER_BYTES(macroDef38)));
		for(int i_s = 0; i_s < macroDef40->length; i_s++){
			card_t size41 = width_vector_shape_t(m_c.elem);
	array_number_t stgVar30 = storage_alloc(size41);
	array_number_t macroDef39;
	macroDef39 = f_s.lam(f_s.env, stgVar29, m_s->arr[i_s], m_c.elem).array_number_t_value;;
	storage_free(stgVar30, size41);
			macroDef40->arr[i_s] = macroDef39;;
			stgVar29 = STG_OFFSET(stgVar29, VECTOR_ALL_BYTES(macroDef40->arr[i_s]->length));
		}
	return macroDef40;
}
typedef empty_env_t env_t_52;


value_t lambda52(env_t_52* env49, card_t i_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
vector_shape_t TOP_LEVEL_linalg_vectorMap2_c(closure_t f_c, vector_shape_t v1_c, vector_shape_t v2_c) {
	env_t_52 env_t_52_value = make_empty_env(); closure_t closure51 = make_closure(lambda52, &env_t_52_value);
	return nested_shape_card_t(closure51.lam(closure51.env, 0).card_t_value, v1_c.card);
}


array_number_t TOP_LEVEL_linalg_vectorMap2_s(storage_t stgVar42, closure_t f_s, array_number_t v1_s, array_number_t v2_s, closure_t f_c, vector_shape_t v1_c, vector_shape_t v2_c) {
	card_t macroDef53 = v1_s->length;
	array_number_t macroDef54 = (array_number_t)stgVar42;
		macroDef54->length=macroDef53;
		macroDef54->arr=(number_t*)(STG_OFFSET(macroDef54, VECTOR_HEADER_BYTES));
		storage_t stgVar44 = macroDef54;
		for(int i_s = 0; i_s < macroDef54->length; i_s++){
			
			macroDef54->arr[i_s] = f_s.lam(f_s.env, stgVar44, v1_s->arr[i_s], v2_s->arr[i_s], 0, 0).number_t_value;;
			stgVar44 = STG_OFFSET(stgVar44, sizeof(number_t));
		}
	return macroDef54;
}
typedef struct env_t_68 {
	matrix_shape_t m2_c;
	matrix_shape_t m1_c;
	closure_t f_c;
} env_t_68;
env_t_68 make_env_t_68(matrix_shape_t m2_c,matrix_shape_t m1_c,closure_t f_c) {
	env_t_68 env;
	env.m2_c = m2_c;
	env.m1_c = m1_c;
	env.f_c = f_c;
	return env;
}

value_t lambda68(env_t_68* env65, card_t i_c) {
	matrix_shape_t m2_c64 = env65->m2_c;
	matrix_shape_t m1_c63 = env65->m1_c;
	closure_t f_c62 = env65->f_c;
	value_t res;
	res.vector_shape_t_value = f_c62.lam(f_c62.env, m1_c63.elem, m2_c64.elem).vector_shape_t_value;
	return res;
}
matrix_shape_t TOP_LEVEL_linalg_matrixMap2_c(closure_t f_c, matrix_shape_t m1_c, matrix_shape_t m2_c) {
	env_t_68 env_t_68_value = make_env_t_68(m2_c,m1_c,f_c); closure_t closure67 = make_closure(lambda68, &env_t_68_value);
	return nested_shape_vector_shape_t(closure67.lam(closure67.env, 0).vector_shape_t_value, m1_c.card);
}


array_array_number_t TOP_LEVEL_linalg_matrixMap2_s(storage_t stgVar55, closure_t f_s, array_array_number_t m1_s, array_array_number_t m2_s, closure_t f_c, matrix_shape_t m1_c, matrix_shape_t m2_c) {
	card_t macroDef69 = m1_s->length;
	array_array_number_t macroDef72 = (array_array_number_t)stgVar55;
		macroDef72->length=macroDef69;
		macroDef72->arr=(array_number_t*)(STG_OFFSET(macroDef72, VECTOR_HEADER_BYTES));
		storage_t stgVar57 = (STG_OFFSET(macroDef72, MATRIX_HEADER_BYTES(macroDef69)));
		for(int i_s = 0; i_s < macroDef72->length; i_s++){
			card_t size74 = width_vector_shape_t(m2_c.elem);
	array_number_t stgVar59 = storage_alloc(size74);
	array_number_t macroDef71;card_t size73 = width_vector_shape_t(m1_c.elem);
	array_number_t stgVar58 = storage_alloc(size73);
	array_number_t macroDef70;
	macroDef70 = f_s.lam(f_s.env, stgVar57, m1_s->arr[i_s], m2_s->arr[i_s], m1_c.elem, m2_c.elem).array_number_t_value;;
	storage_free(stgVar58, size73);
	macroDef71 = macroDef70;;
	storage_free(stgVar59, size74);
			macroDef72->arr[i_s] = macroDef71;;
			stgVar57 = STG_OFFSET(stgVar57, VECTOR_ALL_BYTES(macroDef72->arr[i_s]->length));
		}
	return macroDef72;
}
typedef struct env_t_88 {
	matrix3d_shape_t m2_c;
	matrix3d_shape_t m1_c;
	closure_t f_c;
} env_t_88;
env_t_88 make_env_t_88(matrix3d_shape_t m2_c,matrix3d_shape_t m1_c,closure_t f_c) {
	env_t_88 env;
	env.m2_c = m2_c;
	env.m1_c = m1_c;
	env.f_c = f_c;
	return env;
}

value_t lambda88(env_t_88* env85, card_t i_c) {
	matrix3d_shape_t m2_c84 = env85->m2_c;
	matrix3d_shape_t m1_c83 = env85->m1_c;
	closure_t f_c82 = env85->f_c;
	value_t res;
	res.matrix_shape_t_value = f_c82.lam(f_c82.env, m1_c83.elem, m2_c84.elem).matrix_shape_t_value;
	return res;
}
matrix3d_shape_t TOP_LEVEL_linalg_matrix3DMap2_c(closure_t f_c, matrix3d_shape_t m1_c, matrix3d_shape_t m2_c) {
	env_t_88 env_t_88_value = make_env_t_88(m2_c,m1_c,f_c); closure_t closure87 = make_closure(lambda88, &env_t_88_value);
	return nested_shape_matrix_shape_t(closure87.lam(closure87.env, 0).matrix_shape_t_value, m1_c.card);
}


array_array_array_number_t TOP_LEVEL_linalg_matrix3DMap2_s(storage_t stgVar75, closure_t f_s, array_array_array_number_t m1_s, array_array_array_number_t m2_s, closure_t f_c, matrix3d_shape_t m1_c, matrix3d_shape_t m2_c) {
	card_t macroDef89 = m1_s->length;
	array_array_array_number_t macroDef92 = (array_array_array_number_t)stgVar75;
		macroDef92->length=macroDef89;
		macroDef92->arr=(array_array_number_t*)(STG_OFFSET(macroDef92, VECTOR_HEADER_BYTES));
		storage_t stgVar77 = (STG_OFFSET(macroDef92, MATRIX_HEADER_BYTES(macroDef89)));
		for(int i_s = 0; i_s < macroDef92->length; i_s++){
			card_t size94 = width_matrix_shape_t(m2_c.elem);
	array_number_t stgVar79 = storage_alloc(size94);
	array_array_number_t macroDef91;card_t size93 = width_matrix_shape_t(m1_c.elem);
	array_number_t stgVar78 = storage_alloc(size93);
	array_array_number_t macroDef90;
	macroDef90 = f_s.lam(f_s.env, stgVar77, m1_s->arr[i_s], m2_s->arr[i_s], m1_c.elem, m2_c.elem).array_array_number_t_value;;
	storage_free(stgVar78, size93);
	macroDef91 = macroDef90;;
	storage_free(stgVar79, size94);
			macroDef92->arr[i_s] = macroDef91;;
			stgVar77 = STG_OFFSET(stgVar77, VECTOR_ALL_BYTES(macroDef92->arr[i_s]->length));
		}
	return macroDef92;
}
typedef struct env_t_104 {
	closure_t f_c;
} env_t_104;
env_t_104 make_env_t_104(closure_t f_c) {
	env_t_104 env;
	env.f_c = f_c;
	return env;
}

value_t lambda104(env_t_104* env101, card_t i_c) {
	closure_t f_c100 = env101->f_c;
	value_t res;
	res.vector_shape_t_value = f_c100.lam(f_c100.env, 0).vector_shape_t_value;
	return res;
}
matrix_shape_t TOP_LEVEL_linalg_vectorMapToMatrix_c(closure_t f_c, vector_shape_t arr_c) {
	env_t_104 env_t_104_value = make_env_t_104(f_c); closure_t closure103 = make_closure(lambda104, &env_t_104_value);
	return nested_shape_vector_shape_t(closure103.lam(closure103.env, 0).vector_shape_t_value, arr_c.card);
}


array_array_number_t TOP_LEVEL_linalg_vectorMapToMatrix_s(storage_t stgVar95, closure_t f_s, array_number_t arr_s, closure_t f_c, vector_shape_t arr_c) {
	card_t macroDef105 = arr_s->length;
	array_array_number_t macroDef106 = (array_array_number_t)stgVar95;
		macroDef106->length=macroDef105;
		macroDef106->arr=(array_number_t*)(STG_OFFSET(macroDef106, VECTOR_HEADER_BYTES));
		storage_t stgVar97 = (STG_OFFSET(macroDef106, MATRIX_HEADER_BYTES(macroDef105)));
		for(int i_s = 0; i_s < macroDef106->length; i_s++){
			
			macroDef106->arr[i_s] = f_s.lam(f_s.env, stgVar97, arr_s->arr[i_s], 0).array_number_t_value;;
			stgVar97 = STG_OFFSET(stgVar97, VECTOR_ALL_BYTES(macroDef106->arr[i_s]->length));
		}
	return macroDef106;
}
typedef struct env_t_116 {
	closure_t f_c;
} env_t_116;
env_t_116 make_env_t_116(closure_t f_c) {
	env_t_116 env;
	env.f_c = f_c;
	return env;
}

value_t lambda116(env_t_116* env113, card_t i_c) {
	closure_t f_c112 = env113->f_c;
	value_t res;
	res.matrix_shape_t_value = f_c112.lam(f_c112.env, 0).matrix_shape_t_value;
	return res;
}
matrix3d_shape_t TOP_LEVEL_linalg_vectorMapToMatrix3D_c(closure_t f_c, vector_shape_t arr_c) {
	env_t_116 env_t_116_value = make_env_t_116(f_c); closure_t closure115 = make_closure(lambda116, &env_t_116_value);
	return nested_shape_matrix_shape_t(closure115.lam(closure115.env, 0).matrix_shape_t_value, arr_c.card);
}


array_array_array_number_t TOP_LEVEL_linalg_vectorMapToMatrix3D_s(storage_t stgVar107, closure_t f_s, array_number_t arr_s, closure_t f_c, vector_shape_t arr_c) {
	card_t macroDef117 = arr_s->length;
	array_array_array_number_t macroDef118 = (array_array_array_number_t)stgVar107;
		macroDef118->length=macroDef117;
		macroDef118->arr=(array_array_number_t*)(STG_OFFSET(macroDef118, VECTOR_HEADER_BYTES));
		storage_t stgVar109 = (STG_OFFSET(macroDef118, MATRIX_HEADER_BYTES(macroDef117)));
		for(int i_s = 0; i_s < macroDef118->length; i_s++){
			
			macroDef118->arr[i_s] = f_s.lam(f_s.env, stgVar109, arr_s->arr[i_s], 0).array_array_number_t_value;;
			stgVar109 = STG_OFFSET(stgVar109, VECTOR_ALL_BYTES(macroDef118->arr[i_s]->length));
		}
	return macroDef118;
}

card_t TOP_LEVEL_linalg_iterateNumber_c(closure_t f_c, card_t z_c, card_t s_c, card_t e_c) {
	
	return 0;
}


number_t TOP_LEVEL_linalg_iterateNumber_s(storage_t stgVar119, closure_t f_s, number_t z_s, card_t s_s, card_t e_s, closure_t f_c, card_t z_c, card_t s_c, card_t e_c) {
	number_t macroDef125 = z_s;
	array_number_t cur_s_range = TOP_LEVEL_linalg_vectorRange_s(empty_storage, s_s, e_s, s_c, e_c);
	storage_t stgVar120 = stgVar119;
	for(int cur_s_idx = 0; cur_s_idx < cur_s_range->length; cur_s_idx++){
		number_t cur_s = cur_s_range->arr[cur_s_idx];
		
		macroDef125 = f_s.lam(f_s.env, stgVar120, macroDef125, (int)(cur_s), 0, 0).number_t_value;;
	}
	return macroDef125;
}

vector_shape_t TOP_LEVEL_linalg_iterateVector_c(closure_t f_c, vector_shape_t z_c, card_t s_c, card_t e_c) {
	
	return z_c;
}


array_number_t TOP_LEVEL_linalg_iterateVector_s(storage_t stgVar126, closure_t f_s, array_number_t z_s, card_t s_s, card_t e_s, closure_t f_c, vector_shape_t z_c, card_t s_c, card_t e_c) {
	array_number_t macroDef132 = z_s;
	array_number_t cur_s_range = TOP_LEVEL_linalg_vectorRange_s(empty_storage, s_s, e_s, s_c, e_c);
	storage_t stgVar127 = stgVar126;
	for(int cur_s_idx = 0; cur_s_idx < cur_s_range->length; cur_s_idx++){
		number_t cur_s = cur_s_range->arr[cur_s_idx];
		
		macroDef132 = f_s.lam(f_s.env, stgVar127, macroDef132, (int)(cur_s), z_c, 0).array_number_t_value;;
	}
	return macroDef132;
}

matrix_shape_t TOP_LEVEL_linalg_iterateMatrix_c(closure_t f_c, matrix_shape_t z_c, card_t s_c, card_t e_c) {
	
	return z_c;
}


array_array_number_t TOP_LEVEL_linalg_iterateMatrix_s(storage_t stgVar133, closure_t f_s, array_array_number_t z_s, card_t s_s, card_t e_s, closure_t f_c, matrix_shape_t z_c, card_t s_c, card_t e_c) {
	array_array_number_t macroDef139 = z_s;
	array_number_t cur_s_range = TOP_LEVEL_linalg_vectorRange_s(empty_storage, s_s, e_s, s_c, e_c);
	storage_t stgVar134 = stgVar133;
	for(int cur_s_idx = 0; cur_s_idx < cur_s_range->length; cur_s_idx++){
		number_t cur_s = cur_s_range->arr[cur_s_idx];
		
		macroDef139 = f_s.lam(f_s.env, stgVar134, macroDef139, (int)(cur_s), z_c, 0).array_array_number_t_value;;
	}
	return macroDef139;
}

matrix3d_shape_t TOP_LEVEL_linalg_iterateMatrix3D_c(closure_t f_c, matrix3d_shape_t z_c, card_t s_c, card_t e_c) {
	
	return z_c;
}


array_array_array_number_t TOP_LEVEL_linalg_iterateMatrix3D_s(storage_t stgVar140, closure_t f_s, array_array_array_number_t z_s, card_t s_s, card_t e_s, closure_t f_c, matrix3d_shape_t z_c, card_t s_c, card_t e_c) {
	array_array_array_number_t macroDef146 = z_s;
	array_number_t cur_s_range = TOP_LEVEL_linalg_vectorRange_s(empty_storage, s_s, e_s, s_c, e_c);
	storage_t stgVar141 = stgVar140;
	for(int cur_s_idx = 0; cur_s_idx < cur_s_range->length; cur_s_idx++){
		number_t cur_s = cur_s_range->arr[cur_s_idx];
		
		macroDef146 = f_s.lam(f_s.env, stgVar141, macroDef146, (int)(cur_s), z_c, 0).array_array_array_number_t_value;;
	}
	return macroDef146;
}

card_t TOP_LEVEL_linalg_arraySum_c(vector_shape_t arr_c) {
	
	return 0;
}


number_t TOP_LEVEL_linalg_arraySum_s(storage_t stgVar147, array_number_t arr_s, vector_shape_t arr_c) {
	number_t macroDef149 = 0;
	array_number_t cur_s_range = arr_s;
	storage_t stgVar148 = stgVar147;
	for(int cur_s_idx = 0; cur_s_idx < cur_s_range->length; cur_s_idx++){
		number_t cur_s = cur_s_range->arr[cur_s_idx];
		
		macroDef149 = (macroDef149) + (cur_s);;
	}
	return macroDef149;
}

card_t TOP_LEVEL_linalg_arrayMax_c(vector_shape_t arr_c) {
	
	return 0;
}


number_t TOP_LEVEL_linalg_arrayMax_s(storage_t stgVar150, array_number_t arr_s, vector_shape_t arr_c) {
	number_t macroDef152 = -1000;
	array_number_t cur_s_range = arr_s;
	storage_t stgVar151 = stgVar150;
	for(int cur_s_idx = 0; cur_s_idx < cur_s_range->length; cur_s_idx++){
		number_t cur_s = cur_s_range->arr[cur_s_idx];
		number_t ite153 = 0;
	if((macroDef152) > (cur_s)) {
		
		ite153 = macroDef152;;
	} else {
		
		ite153 = cur_s;;
	}
		macroDef152 = ite153;;
	}
	return macroDef152;
}
typedef empty_env_t env_t_161;


value_t lambda161(env_t_161* env158, card_t a_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
vector_shape_t TOP_LEVEL_linalg_mult_by_scalar_c(vector_shape_t x_c, card_t y_c) {
	env_t_161 env_t_161_value = make_empty_env(); closure_t closure160 = make_closure(lambda161, &env_t_161_value);
	return TOP_LEVEL_linalg_vectorMap_c(closure160, x_c);
}

typedef struct env_t_169 {
	number_t y_s;
} env_t_169;
env_t_169 make_env_t_169(number_t y_s) {
	env_t_169 env;
	env.y_s = y_s;
	return env;
}

value_t lambda169(env_t_169* env163, storage_t stgVar157, number_t a_s, card_t a_c) {
	number_t y_s162 = env163->y_s;
	value_t res;
	res.number_t_value = (a_s) * (y_s162);
	return res;
}
typedef empty_env_t env_t_170;


value_t lambda170(env_t_170* env166, card_t a_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
array_number_t TOP_LEVEL_linalg_mult_by_scalar_s(storage_t stgVar154, array_number_t x_s, number_t y_s, vector_shape_t x_c, card_t y_c) {
	env_t_169 env_t_169_value = make_env_t_169(y_s); closure_t closure165 = make_closure(lambda169, &env_t_169_value);
	env_t_170 env_t_170_value = make_empty_env(); closure_t closure168 = make_closure(lambda170, &env_t_170_value);
	return TOP_LEVEL_linalg_vectorMap_s(stgVar154, closure165, x_s, closure168, x_c);
}

vector_shape_t TOP_LEVEL_linalg_cross_c(vector_shape_t a_c, vector_shape_t b_c) {
	
	return nested_shape_card_t(0, 3);
}


array_number_t TOP_LEVEL_linalg_cross_s(storage_t stgVar171, array_number_t a_s, array_number_t b_s, vector_shape_t a_c, vector_shape_t b_c) {
	array_number_t macroDef187 = (array_number_t)stgVar171;
	macroDef187->length=3;
	macroDef187->arr=(number_t*)(STG_OFFSET(stgVar171, VECTOR_HEADER_BYTES));
	macroDef187->arr[0] = ((a_s->arr[1]) * (b_s->arr[2])) - ((a_s->arr[2]) * (b_s->arr[1]));
	macroDef187->arr[1] = ((a_s->arr[2]) * (b_s->arr[0])) - ((a_s->arr[0]) * (b_s->arr[2]));
	macroDef187->arr[2] = ((a_s->arr[0]) * (b_s->arr[1])) - ((a_s->arr[1]) * (b_s->arr[0]));;
	return macroDef187;
}
typedef empty_env_t env_t_196;


value_t lambda196(env_t_196* env193, card_t x_c, card_t y_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
vector_shape_t TOP_LEVEL_linalg_add_vec_c(vector_shape_t x_c, vector_shape_t y_c) {
	env_t_196 env_t_196_value = make_empty_env(); closure_t closure195 = make_closure(lambda196, &env_t_196_value);
	return TOP_LEVEL_linalg_vectorMap2_c(closure195, x_c, y_c);
}

typedef empty_env_t env_t_203;


value_t lambda203(env_t_203* env197, storage_t stgVar192, number_t x_s, number_t y_s, card_t x_c, card_t y_c) {
	
	value_t res;
	res.number_t_value = (x_s) + (y_s);
	return res;
}
typedef empty_env_t env_t_204;


value_t lambda204(env_t_204* env200, card_t x_c, card_t y_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
array_number_t TOP_LEVEL_linalg_add_vec_s(storage_t stgVar188, array_number_t x_s, array_number_t y_s, vector_shape_t x_c, vector_shape_t y_c) {
	env_t_203 env_t_203_value = make_empty_env(); closure_t closure199 = make_closure(lambda203, &env_t_203_value);
	env_t_204 env_t_204_value = make_empty_env(); closure_t closure202 = make_closure(lambda204, &env_t_204_value);
	return TOP_LEVEL_linalg_vectorMap2_s(stgVar188, closure199, x_s, y_s, closure202, x_c, y_c);
}
typedef empty_env_t env_t_213;


value_t lambda213(env_t_213* env210, card_t x_c, card_t y_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
vector_shape_t TOP_LEVEL_linalg_mult_vec_elementwise_c(vector_shape_t x_c, vector_shape_t y_c) {
	env_t_213 env_t_213_value = make_empty_env(); closure_t closure212 = make_closure(lambda213, &env_t_213_value);
	return TOP_LEVEL_linalg_vectorMap2_c(closure212, x_c, y_c);
}

typedef empty_env_t env_t_220;


value_t lambda220(env_t_220* env214, storage_t stgVar209, number_t x_s, number_t y_s, card_t x_c, card_t y_c) {
	
	value_t res;
	res.number_t_value = (x_s) * (y_s);
	return res;
}
typedef empty_env_t env_t_221;


value_t lambda221(env_t_221* env217, card_t x_c, card_t y_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
array_number_t TOP_LEVEL_linalg_mult_vec_elementwise_s(storage_t stgVar205, array_number_t x_s, array_number_t y_s, vector_shape_t x_c, vector_shape_t y_c) {
	env_t_220 env_t_220_value = make_empty_env(); closure_t closure216 = make_closure(lambda220, &env_t_220_value);
	env_t_221 env_t_221_value = make_empty_env(); closure_t closure219 = make_closure(lambda221, &env_t_221_value);
	return TOP_LEVEL_linalg_vectorMap2_s(stgVar205, closure216, x_s, y_s, closure219, x_c, y_c);
}

vector_shape_t TOP_LEVEL_linalg_add_vec3_c(vector_shape_t x_c, vector_shape_t y_c, vector_shape_t z_c) {
	
	return TOP_LEVEL_linalg_add_vec_c(TOP_LEVEL_linalg_add_vec_c(x_c, y_c), z_c);
}


array_number_t TOP_LEVEL_linalg_add_vec3_s(storage_t stgVar222, array_number_t x_s, array_number_t y_s, array_number_t z_s, vector_shape_t x_c, vector_shape_t y_c, vector_shape_t z_c) {
	card_t size228 = width_vector_shape_t(TOP_LEVEL_linalg_add_vec_c(x_c, y_c));
	array_number_t stgVar223 = storage_alloc(size228);
	array_number_t macroDef227;
	macroDef227 = TOP_LEVEL_linalg_add_vec_s(stgVar222, TOP_LEVEL_linalg_add_vec_s(stgVar223, x_s, y_s, x_c, y_c), z_s, TOP_LEVEL_linalg_add_vec_c(x_c, y_c), z_c);;
	storage_free(stgVar223, size228);
	return macroDef227;
}
typedef empty_env_t env_t_237;


value_t lambda237(env_t_237* env234, card_t x_c, card_t y_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
vector_shape_t TOP_LEVEL_linalg_sub_vec_c(vector_shape_t x_c, vector_shape_t y_c) {
	env_t_237 env_t_237_value = make_empty_env(); closure_t closure236 = make_closure(lambda237, &env_t_237_value);
	return TOP_LEVEL_linalg_vectorMap2_c(closure236, x_c, y_c);
}

typedef empty_env_t env_t_244;


value_t lambda244(env_t_244* env238, storage_t stgVar233, number_t x_s, number_t y_s, card_t x_c, card_t y_c) {
	
	value_t res;
	res.number_t_value = (x_s) - (y_s);
	return res;
}
typedef empty_env_t env_t_245;


value_t lambda245(env_t_245* env241, card_t x_c, card_t y_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
array_number_t TOP_LEVEL_linalg_sub_vec_s(storage_t stgVar229, array_number_t x_s, array_number_t y_s, vector_shape_t x_c, vector_shape_t y_c) {
	env_t_244 env_t_244_value = make_empty_env(); closure_t closure240 = make_closure(lambda244, &env_t_244_value);
	env_t_245 env_t_245_value = make_empty_env(); closure_t closure243 = make_closure(lambda245, &env_t_245_value);
	return TOP_LEVEL_linalg_vectorMap2_s(stgVar229, closure240, x_s, y_s, closure243, x_c, y_c);
}
typedef empty_env_t env_t_256;


value_t lambda256(env_t_256* env253, vector_shape_t x_c, vector_shape_t y_c) {
	
	value_t res;
	res.vector_shape_t_value = TOP_LEVEL_linalg_add_vec_c(x_c, y_c);
	return res;
}
matrix_shape_t TOP_LEVEL_linalg_matrixAdd_c(matrix_shape_t x_c, matrix_shape_t y_c) {
	env_t_256 env_t_256_value = make_empty_env(); closure_t closure255 = make_closure(lambda256, &env_t_256_value);
	return TOP_LEVEL_linalg_matrixMap2_c(closure255, x_c, y_c);
}

typedef empty_env_t env_t_263;


value_t lambda263(env_t_263* env257, storage_t stgVar250, array_number_t x_s, array_number_t y_s, vector_shape_t x_c, vector_shape_t y_c) {
	
	value_t res;
	res.array_number_t_value = TOP_LEVEL_linalg_add_vec_s(stgVar250, x_s, y_s, x_c, y_c);
	return res;
}
typedef empty_env_t env_t_264;


value_t lambda264(env_t_264* env260, vector_shape_t x_c, vector_shape_t y_c) {
	
	value_t res;
	res.vector_shape_t_value = TOP_LEVEL_linalg_add_vec_c(x_c, y_c);
	return res;
}
array_array_number_t TOP_LEVEL_linalg_matrixAdd_s(storage_t stgVar246, array_array_number_t x_s, array_array_number_t y_s, matrix_shape_t x_c, matrix_shape_t y_c) {
	env_t_263 env_t_263_value = make_empty_env(); closure_t closure259 = make_closure(lambda263, &env_t_263_value);
	env_t_264 env_t_264_value = make_empty_env(); closure_t closure262 = make_closure(lambda264, &env_t_264_value);
	return TOP_LEVEL_linalg_matrixMap2_s(stgVar246, closure259, x_s, y_s, closure262, x_c, y_c);
}
typedef empty_env_t env_t_275;


value_t lambda275(env_t_275* env272, vector_shape_t x_c, vector_shape_t y_c) {
	
	value_t res;
	res.vector_shape_t_value = TOP_LEVEL_linalg_mult_vec_elementwise_c(x_c, y_c);
	return res;
}
matrix_shape_t TOP_LEVEL_linalg_matrixMultElementwise_c(matrix_shape_t x_c, matrix_shape_t y_c) {
	env_t_275 env_t_275_value = make_empty_env(); closure_t closure274 = make_closure(lambda275, &env_t_275_value);
	return TOP_LEVEL_linalg_matrixMap2_c(closure274, x_c, y_c);
}

typedef empty_env_t env_t_282;


value_t lambda282(env_t_282* env276, storage_t stgVar269, array_number_t x_s, array_number_t y_s, vector_shape_t x_c, vector_shape_t y_c) {
	
	value_t res;
	res.array_number_t_value = TOP_LEVEL_linalg_mult_vec_elementwise_s(stgVar269, x_s, y_s, x_c, y_c);
	return res;
}
typedef empty_env_t env_t_283;


value_t lambda283(env_t_283* env279, vector_shape_t x_c, vector_shape_t y_c) {
	
	value_t res;
	res.vector_shape_t_value = TOP_LEVEL_linalg_mult_vec_elementwise_c(x_c, y_c);
	return res;
}
array_array_number_t TOP_LEVEL_linalg_matrixMultElementwise_s(storage_t stgVar265, array_array_number_t x_s, array_array_number_t y_s, matrix_shape_t x_c, matrix_shape_t y_c) {
	env_t_282 env_t_282_value = make_empty_env(); closure_t closure278 = make_closure(lambda282, &env_t_282_value);
	env_t_283 env_t_283_value = make_empty_env(); closure_t closure281 = make_closure(lambda283, &env_t_283_value);
	return TOP_LEVEL_linalg_matrixMap2_s(stgVar265, closure278, x_s, y_s, closure281, x_c, y_c);
}

card_t TOP_LEVEL_linalg_sqnorm_c(vector_shape_t x_c) {
	
	return 0;
}

typedef empty_env_t env_t_302;


value_t lambda302(env_t_302* env289, card_t x1_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef empty_env_t env_t_303;


value_t lambda303(env_t_303* env292, storage_t stgVar288, number_t x1_s, card_t x1_c) {
	
	value_t res;
	res.number_t_value = (x1_s) * (x1_s);
	return res;
}
typedef empty_env_t env_t_304;


value_t lambda304(env_t_304* env295, card_t x1_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef empty_env_t env_t_305;


value_t lambda305(env_t_305* env298, card_t x1_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
number_t TOP_LEVEL_linalg_sqnorm_s(storage_t stgVar284, array_number_t x_s, vector_shape_t x_c) {
	env_t_302 env_t_302_value = make_empty_env(); closure_t closure291 = make_closure(lambda302, &env_t_302_value);
	card_t size306 = width_vector_shape_t(TOP_LEVEL_linalg_vectorMap_c(closure291, x_c));
	array_number_t stgVar285 = storage_alloc(size306);
	number_t macroDef301;env_t_303 env_t_303_value = make_empty_env(); closure_t closure294 = make_closure(lambda303, &env_t_303_value);
	env_t_304 env_t_304_value = make_empty_env(); closure_t closure297 = make_closure(lambda304, &env_t_304_value);
	env_t_305 env_t_305_value = make_empty_env(); closure_t closure300 = make_closure(lambda305, &env_t_305_value);
	macroDef301 = TOP_LEVEL_linalg_arraySum_s(stgVar284, TOP_LEVEL_linalg_vectorMap_s(stgVar285, closure294, x_s, closure297, x_c), TOP_LEVEL_linalg_vectorMap_c(closure300, x_c));;
	storage_free(stgVar285, size306);
	return macroDef301;
}

card_t TOP_LEVEL_linalg_dot_prod_c(vector_shape_t x_c, vector_shape_t y_c) {
	
	return 0;
}

typedef empty_env_t env_t_326;


value_t lambda326(env_t_326* env313, card_t x_c, card_t y_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef empty_env_t env_t_327;


value_t lambda327(env_t_327* env316, storage_t stgVar312, number_t x_s, number_t y_s, card_t x_c, card_t y_c) {
	
	value_t res;
	res.number_t_value = (x_s) * (y_s);
	return res;
}
typedef empty_env_t env_t_328;


value_t lambda328(env_t_328* env319, card_t x_c, card_t y_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef empty_env_t env_t_329;


value_t lambda329(env_t_329* env322, card_t x_c, card_t y_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
number_t TOP_LEVEL_linalg_dot_prod_s(storage_t stgVar307, array_number_t x_s, array_number_t y_s, vector_shape_t x_c, vector_shape_t y_c) {
	env_t_326 env_t_326_value = make_empty_env(); closure_t closure315 = make_closure(lambda326, &env_t_326_value);
	card_t size330 = width_vector_shape_t(TOP_LEVEL_linalg_vectorMap2_c(closure315, x_c, y_c));
	array_number_t stgVar308 = storage_alloc(size330);
	number_t macroDef325;env_t_327 env_t_327_value = make_empty_env(); closure_t closure318 = make_closure(lambda327, &env_t_327_value);
	env_t_328 env_t_328_value = make_empty_env(); closure_t closure321 = make_closure(lambda328, &env_t_328_value);
	env_t_329 env_t_329_value = make_empty_env(); closure_t closure324 = make_closure(lambda329, &env_t_329_value);
	macroDef325 = TOP_LEVEL_linalg_arraySum_s(stgVar307, TOP_LEVEL_linalg_vectorMap2_s(stgVar308, closure318, x_s, y_s, closure321, x_c, y_c), TOP_LEVEL_linalg_vectorMap2_c(closure324, x_c, y_c));;
	storage_free(stgVar308, size330);
	return macroDef325;
}
typedef struct env_t_341 {
	vector_shape_t row_c;
} env_t_341;
env_t_341 make_env_t_341(vector_shape_t row_c) {
	env_t_341 env;
	env.row_c = row_c;
	return env;
}

value_t lambda341(env_t_341* env338, card_t r_c) {
	vector_shape_t row_c337 = env338->row_c;
	value_t res;
	res.vector_shape_t_value = row_c337;
	return res;
}
matrix_shape_t TOP_LEVEL_linalg_matrixFillFromVector_c(card_t rows_c, vector_shape_t row_c) {
	env_t_341 env_t_341_value = make_env_t_341(row_c); closure_t closure340 = make_closure(lambda341, &env_t_341_value);
	return TOP_LEVEL_linalg_vectorMapToMatrix_c(closure340, TOP_LEVEL_linalg_vectorRange_c(1, rows_c));
}

typedef struct env_t_351 {
	array_number_t row_s;
} env_t_351;
env_t_351 make_env_t_351(array_number_t row_s) {
	env_t_351 env;
	env.row_s = row_s;
	return env;
}

value_t lambda351(env_t_351* env343, storage_t stgVar334, number_t r_s, card_t r_c) {
	array_number_t row_s342 = env343->row_s;
	value_t res;
	res.array_number_t_value = row_s342;
	return res;
}
typedef struct env_t_352 {
	vector_shape_t row_c;
} env_t_352;
env_t_352 make_env_t_352(vector_shape_t row_c) {
	env_t_352 env;
	env.row_c = row_c;
	return env;
}

value_t lambda352(env_t_352* env347, card_t r_c) {
	vector_shape_t row_c346 = env347->row_c;
	value_t res;
	res.vector_shape_t_value = row_c346;
	return res;
}
array_array_number_t TOP_LEVEL_linalg_matrixFillFromVector_s(storage_t stgVar331, card_t rows_s, array_number_t row_s, card_t rows_c, vector_shape_t row_c) {
	card_t size353 = width_vector_shape_t(TOP_LEVEL_linalg_vectorRange_c(1, rows_c));
	array_number_t stgVar333 = storage_alloc(size353);
	array_array_number_t macroDef350;env_t_351 env_t_351_value = make_env_t_351(row_s); closure_t closure345 = make_closure(lambda351, &env_t_351_value);
	env_t_352 env_t_352_value = make_env_t_352(row_c); closure_t closure349 = make_closure(lambda352, &env_t_352_value);
	macroDef350 = TOP_LEVEL_linalg_vectorMapToMatrix_s(stgVar331, closure345, TOP_LEVEL_linalg_vectorRange_s(stgVar333, 1, rows_s, 1, rows_c), closure349, TOP_LEVEL_linalg_vectorRange_c(1, rows_c));;
	storage_free(stgVar333, size353);
	return macroDef350;
}
typedef struct env_t_364 {
	card_t cols_c;
} env_t_364;
env_t_364 make_env_t_364(card_t cols_c) {
	env_t_364 env;
	env.cols_c = cols_c;
	return env;
}
typedef empty_env_t env_t_365;


value_t lambda365(env_t_365* env357, card_t c_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
value_t lambda364(env_t_364* env361, card_t r_c) {
	card_t cols_c360 = env361->cols_c;
	env_t_365 env_t_365_value = make_empty_env(); closure_t closure359 = make_closure(lambda365, &env_t_365_value);
	value_t res;
	res.vector_shape_t_value = nested_shape_card_t(closure359.lam(closure359.env, 0).card_t_value, cols_c360);
	return res;
}
matrix_shape_t TOP_LEVEL_linalg_matrixFill_c(card_t rows_c, card_t cols_c, card_t value_c) {
	env_t_364 env_t_364_value = make_env_t_364(cols_c); closure_t closure363 = make_closure(lambda364, &env_t_364_value);
	return nested_shape_vector_shape_t(closure363.lam(closure363.env, 0).vector_shape_t_value, rows_c);
}


array_array_number_t TOP_LEVEL_linalg_matrixFill_s(storage_t stgVar354, card_t rows_s, card_t cols_s, number_t value_s, card_t rows_c, card_t cols_c, card_t value_c) {
	array_array_number_t macroDef370 = (array_array_number_t)stgVar354;
		macroDef370->length=rows_s;
		macroDef370->arr=(array_number_t*)(STG_OFFSET(macroDef370, VECTOR_HEADER_BYTES));
		storage_t stgVar355 = (STG_OFFSET(macroDef370, MATRIX_HEADER_BYTES(rows_s)));
		for(int r_s = 0; r_s < macroDef370->length; r_s++){
			array_number_t macroDef366 = (array_number_t)stgVar355;
		macroDef366->length=cols_s;
		macroDef366->arr=(number_t*)(STG_OFFSET(macroDef366, VECTOR_HEADER_BYTES));
		storage_t stgVar356 = macroDef366;
		for(int c_s = 0; c_s < macroDef366->length; c_s++){
			
			macroDef366->arr[c_s] = value_s;;
			stgVar356 = STG_OFFSET(stgVar356, sizeof(number_t));
		}
			macroDef370->arr[r_s] = macroDef366;;
			stgVar355 = STG_OFFSET(stgVar355, VECTOR_ALL_BYTES(macroDef370->arr[r_s]->length));
		}
	return macroDef370;
}
typedef struct env_t_388 {
	card_t rows_c;
} env_t_388;
env_t_388 make_env_t_388(card_t rows_c) {
	env_t_388 env;
	env.rows_c = rows_c;
	return env;
}
typedef empty_env_t env_t_389;


value_t lambda389(env_t_389* env381, card_t j_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
value_t lambda388(env_t_388* env385, card_t i_c) {
	card_t rows_c384 = env385->rows_c;
	env_t_389 env_t_389_value = make_empty_env(); closure_t closure383 = make_closure(lambda389, &env_t_389_value);
	value_t res;
	res.vector_shape_t_value = nested_shape_card_t(closure383.lam(closure383.env, 0).card_t_value, rows_c384);
	return res;
}
matrix_shape_t TOP_LEVEL_linalg_matrixTranspose_c(matrix_shape_t m_c) {
	card_t rows_c = m_c.card;
	card_t cols_c = m_c.elem.card;
	env_t_388 env_t_388_value = make_env_t_388(rows_c); closure_t closure387 = make_closure(lambda388, &env_t_388_value);
	return nested_shape_vector_shape_t(closure387.lam(closure387.env, 0).vector_shape_t_value, cols_c);
}


array_array_number_t TOP_LEVEL_linalg_matrixTranspose_s(storage_t stgVar371, array_array_number_t m_s, matrix_shape_t m_c) {
	card_t rows_c = m_c.card;
	card_t macroDef390 = m_s->length;
	card_t rows_s = macroDef390;
	card_t cols_c = m_c.elem.card;
	card_t size399 = width_vector_shape_t(m_c.elem);
	array_number_t stgVar375 = storage_alloc(size399);
	card_t macroDef392;card_t macroDef391 = m_s->arr[0]->length;
	macroDef392 = macroDef391;;
	storage_free(stgVar375, size399);
	card_t cols_s = macroDef392;
	array_array_number_t macroDef398 = (array_array_number_t)stgVar371;
		macroDef398->length=cols_s;
		macroDef398->arr=(array_number_t*)(STG_OFFSET(macroDef398, VECTOR_HEADER_BYTES));
		storage_t stgVar377 = (STG_OFFSET(macroDef398, MATRIX_HEADER_BYTES(cols_s)));
		for(int i_s = 0; i_s < macroDef398->length; i_s++){
			array_number_t macroDef394 = (array_number_t)stgVar377;
		macroDef394->length=rows_s;
		macroDef394->arr=(number_t*)(STG_OFFSET(macroDef394, VECTOR_HEADER_BYTES));
		storage_t stgVar378 = macroDef394;
		for(int j_s = 0; j_s < macroDef394->length; j_s++){
			card_t size400 = width_vector_shape_t(m_c.elem);
	array_number_t stgVar379 = storage_alloc(size400);
	number_t macroDef393;
	macroDef393 = m_s->arr[j_s]->arr[i_s];;
	storage_free(stgVar379, size400);
			macroDef394->arr[j_s] = macroDef393;;
			stgVar378 = STG_OFFSET(stgVar378, sizeof(number_t));
		}
			macroDef398->arr[i_s] = macroDef394;;
			stgVar377 = STG_OFFSET(stgVar377, VECTOR_ALL_BYTES(macroDef398->arr[i_s]->length));
		}
	return macroDef398;
}
typedef struct env_t_427 {
	card_t c2_c;
} env_t_427;
env_t_427 make_env_t_427(card_t c2_c) {
	env_t_427 env;
	env.c2_c = c2_c;
	return env;
}
typedef empty_env_t env_t_428;


value_t lambda428(env_t_428* env420, card_t c_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
value_t lambda427(env_t_427* env424, card_t r_c) {
	card_t c2_c423 = env424->c2_c;
	env_t_428 env_t_428_value = make_empty_env(); closure_t closure422 = make_closure(lambda428, &env_t_428_value);
	value_t res;
	res.vector_shape_t_value = nested_shape_card_t(closure422.lam(closure422.env, 0).card_t_value, c2_c423);
	return res;
}
matrix_shape_t TOP_LEVEL_linalg_matrixMult_c(matrix_shape_t m1_c, matrix_shape_t m2_c) {
	card_t r1_c = m1_c.card;
	card_t c2_c = m2_c.elem.card;
	card_t c1_c = m1_c.elem.card;
	card_t r2_c = m2_c.card;
	matrix_shape_t m2T_c = TOP_LEVEL_linalg_matrixTranspose_c(m2_c);
	env_t_427 env_t_427_value = make_env_t_427(c2_c); closure_t closure426 = make_closure(lambda427, &env_t_427_value);
	return nested_shape_vector_shape_t(closure426.lam(closure426.env, 0).vector_shape_t_value, r1_c);
}


array_array_number_t TOP_LEVEL_linalg_matrixMult_s(storage_t stgVar401, array_array_number_t m1_s, array_array_number_t m2_s, matrix_shape_t m1_c, matrix_shape_t m2_c) {
	card_t r1_c = m1_c.card;
	card_t macroDef429 = m1_s->length;
	card_t r1_s = macroDef429;
	card_t c2_c = m2_c.elem.card;
	card_t size443 = width_vector_shape_t(m2_c.elem);
	array_number_t stgVar405 = storage_alloc(size443);
	card_t macroDef431;card_t macroDef430 = m2_s->arr[0]->length;
	macroDef431 = macroDef430;;
	storage_free(stgVar405, size443);
	card_t c2_s = macroDef431;
	card_t c1_c = m1_c.elem.card;
	card_t size444 = width_vector_shape_t(m1_c.elem);
	array_number_t stgVar408 = storage_alloc(size444);
	card_t macroDef433;card_t macroDef432 = m1_s->arr[0]->length;
	macroDef433 = macroDef432;;
	storage_free(stgVar408, size444);
	card_t c1_s = macroDef433;
	card_t r2_c = m2_c.card;
	card_t macroDef434 = m2_s->length;
	card_t r2_s = macroDef434;
	matrix_shape_t m2T_c = TOP_LEVEL_linalg_matrixTranspose_c(m2_c);
	card_t size447 = width_matrix_shape_t(m2T_c);
	array_number_t stgVar412 = storage_alloc(size447);
	array_array_number_t macroDef442;array_array_number_t m2T_s = TOP_LEVEL_linalg_matrixTranspose_s(stgVar412, m2_s, m2_c);
	array_array_number_t macroDef441 = (array_array_number_t)stgVar401;
		macroDef441->length=r1_s;
		macroDef441->arr=(array_number_t*)(STG_OFFSET(macroDef441, VECTOR_HEADER_BYTES));
		storage_t stgVar414 = (STG_OFFSET(macroDef441, MATRIX_HEADER_BYTES(r1_s)));
		for(int r_s = 0; r_s < macroDef441->length; r_s++){
			array_number_t macroDef437 = (array_number_t)stgVar414;
		macroDef437->length=c2_s;
		macroDef437->arr=(number_t*)(STG_OFFSET(macroDef437, VECTOR_HEADER_BYTES));
		storage_t stgVar415 = macroDef437;
		for(int c_s = 0; c_s < macroDef437->length; c_s++){
			card_t size446 = width_vector_shape_t(m2T_c.elem);
	array_number_t stgVar417 = storage_alloc(size446);
	number_t macroDef436;card_t size445 = width_vector_shape_t(m1_c.elem);
	array_number_t stgVar416 = storage_alloc(size445);
	number_t macroDef435;
	macroDef435 = TOP_LEVEL_linalg_dot_prod_s(stgVar415, m1_s->arr[r_s], m2T_s->arr[c_s], m1_c.elem, m2T_c.elem);;
	storage_free(stgVar416, size445);
	macroDef436 = macroDef435;;
	storage_free(stgVar417, size446);
			macroDef437->arr[c_s] = macroDef436;;
			stgVar415 = STG_OFFSET(stgVar415, sizeof(number_t));
		}
			macroDef441->arr[r_s] = macroDef437;;
			stgVar414 = STG_OFFSET(stgVar414, VECTOR_ALL_BYTES(macroDef441->arr[r_s]->length));
		}
	macroDef442 = macroDef441;;
	storage_free(stgVar412, size447);
	return macroDef442;
}
typedef struct env_t_461 {
	matrix_shape_t m1_c;
} env_t_461;
env_t_461 make_env_t_461(matrix_shape_t m1_c) {
	env_t_461 env;
	env.m1_c = m1_c;
	return env;
}

value_t lambda461(env_t_461* env458, card_t r_c) {
	matrix_shape_t m1_c457 = env458->m1_c;
	value_t res;
	res.vector_shape_t_value = m1_c457.elem;
	return res;
}
matrix_shape_t TOP_LEVEL_linalg_matrixConcat_c(matrix_shape_t m1_c, matrix_shape_t m2_c) {
	card_t rows_c = (m1_c.card) + (m2_c.card);
	card_t m1Rows_c = 0;
	env_t_461 env_t_461_value = make_env_t_461(m1_c); closure_t closure460 = make_closure(lambda461, &env_t_461_value);
	return nested_shape_vector_shape_t(closure460.lam(closure460.env, 0).vector_shape_t_value, rows_c);
}


array_array_number_t TOP_LEVEL_linalg_matrixConcat_s(storage_t stgVar448, array_array_number_t m1_s, array_array_number_t m2_s, matrix_shape_t m1_c, matrix_shape_t m2_c) {
	card_t rows_c = (m1_c.card) + (m2_c.card);
	card_t macroDef462 = m1_s->length;
	card_t macroDef463 = m2_s->length;
	card_t rows_s = (macroDef462) + (macroDef463);
	card_t m1Rows_c = 0;
	card_t macroDef464 = m1_s->length;
	index_t m1Rows_s = (macroDef464);
	array_array_number_t macroDef465 = (array_array_number_t)stgVar448;
		macroDef465->length=rows_s;
		macroDef465->arr=(array_number_t*)(STG_OFFSET(macroDef465, VECTOR_HEADER_BYTES));
		storage_t stgVar454 = (STG_OFFSET(macroDef465, MATRIX_HEADER_BYTES(rows_s)));
		for(int r_s = 0; r_s < macroDef465->length; r_s++){
			array_number_t ite466 = 0;
	if((r_s) < (m1Rows_s)) {
		
		ite466 = m1_s->arr[r_s];;
	} else {
		
		ite466 = m2_s->arr[(r_s) - (m1Rows_s)];;
	}
			macroDef465->arr[r_s] = ite466;;
			stgVar454 = STG_OFFSET(stgVar454, VECTOR_ALL_BYTES(macroDef465->arr[r_s]->length));
		}
	return macroDef465;
}

matrix_shape_t TOP_LEVEL_linalg_matrixConcatCol_c(matrix_shape_t m1_c, matrix_shape_t m2_c) {
	matrix_shape_t m1t_c = TOP_LEVEL_linalg_matrixTranspose_c(m1_c);
	matrix_shape_t m2t_c = TOP_LEVEL_linalg_matrixTranspose_c(m2_c);
	return TOP_LEVEL_linalg_matrixTranspose_c(TOP_LEVEL_linalg_matrixConcat_c(m1t_c, m2t_c));
}


array_array_number_t TOP_LEVEL_linalg_matrixConcatCol_s(storage_t stgVar467, array_array_number_t m1_s, array_array_number_t m2_s, matrix_shape_t m1_c, matrix_shape_t m2_c) {
	matrix_shape_t m1t_c = TOP_LEVEL_linalg_matrixTranspose_c(m1_c);
	card_t size480 = width_matrix_shape_t(m1t_c);
	array_number_t stgVar468 = storage_alloc(size480);
	array_array_number_t macroDef477;array_array_number_t m1t_s = TOP_LEVEL_linalg_matrixTranspose_s(stgVar468, m1_s, m1_c);
	matrix_shape_t m2t_c = TOP_LEVEL_linalg_matrixTranspose_c(m2_c);
	card_t size479 = width_matrix_shape_t(m2t_c);
	array_number_t stgVar470 = storage_alloc(size479);
	array_array_number_t macroDef476;array_array_number_t m2t_s = TOP_LEVEL_linalg_matrixTranspose_s(stgVar470, m2_s, m2_c);
	card_t size478 = width_matrix_shape_t(TOP_LEVEL_linalg_matrixConcat_c(m1t_c, m2t_c));
	array_number_t stgVar472 = storage_alloc(size478);
	array_array_number_t macroDef475;
	macroDef475 = TOP_LEVEL_linalg_matrixTranspose_s(stgVar467, TOP_LEVEL_linalg_matrixConcat_s(stgVar472, m1t_s, m2t_s, m1t_c, m2t_c), TOP_LEVEL_linalg_matrixConcat_c(m1t_c, m2t_c));;
	storage_free(stgVar472, size478);
	macroDef476 = macroDef475;;
	storage_free(stgVar470, size479);
	macroDef477 = macroDef476;;
	storage_free(stgVar468, size480);
	return macroDef477;
}
typedef struct env_t_494 {
	matrix3d_shape_t m1_c;
} env_t_494;
env_t_494 make_env_t_494(matrix3d_shape_t m1_c) {
	env_t_494 env;
	env.m1_c = m1_c;
	return env;
}

value_t lambda494(env_t_494* env491, card_t r_c) {
	matrix3d_shape_t m1_c490 = env491->m1_c;
	value_t res;
	res.matrix_shape_t_value = m1_c490.elem;
	return res;
}
matrix3d_shape_t TOP_LEVEL_linalg_matrix3DConcat_c(matrix3d_shape_t m1_c, matrix3d_shape_t m2_c) {
	card_t rows_c = (m1_c.card) + (m2_c.card);
	card_t m1Rows_c = 0;
	env_t_494 env_t_494_value = make_env_t_494(m1_c); closure_t closure493 = make_closure(lambda494, &env_t_494_value);
	return nested_shape_matrix_shape_t(closure493.lam(closure493.env, 0).matrix_shape_t_value, rows_c);
}


array_array_array_number_t TOP_LEVEL_linalg_matrix3DConcat_s(storage_t stgVar481, array_array_array_number_t m1_s, array_array_array_number_t m2_s, matrix3d_shape_t m1_c, matrix3d_shape_t m2_c) {
	card_t rows_c = (m1_c.card) + (m2_c.card);
	card_t macroDef495 = m1_s->length;
	card_t macroDef496 = m2_s->length;
	card_t rows_s = (macroDef495) + (macroDef496);
	card_t m1Rows_c = 0;
	card_t macroDef497 = m1_s->length;
	index_t m1Rows_s = (macroDef497);
	array_array_array_number_t macroDef498 = (array_array_array_number_t)stgVar481;
		macroDef498->length=rows_s;
		macroDef498->arr=(array_array_number_t*)(STG_OFFSET(macroDef498, VECTOR_HEADER_BYTES));
		storage_t stgVar487 = (STG_OFFSET(macroDef498, MATRIX_HEADER_BYTES(rows_s)));
		for(int r_s = 0; r_s < macroDef498->length; r_s++){
			array_array_number_t ite499 = 0;
	if((r_s) < (m1Rows_s)) {
		
		ite499 = m1_s->arr[r_s];;
	} else {
		
		ite499 = m2_s->arr[(r_s) - (m1Rows_s)];;
	}
			macroDef498->arr[r_s] = ite499;;
			stgVar487 = STG_OFFSET(stgVar487, VECTOR_ALL_BYTES(macroDef498->arr[r_s]->length));
		}
	return macroDef498;
}

vector_shape_t TOP_LEVEL_linalg_vectorRead_c(card_t fn_c, card_t startLine_c) {
	matrix_shape_t matrix_c = nested_shape_vector_shape_t(nested_shape_card_t(0, 10), 1);
	return matrix_c.elem;
}


array_number_t TOP_LEVEL_linalg_vectorRead_s(storage_t stgVar500, string_t fn_s, index_t startLine_s, card_t fn_c, card_t startLine_c) {
	matrix_shape_t matrix_c = nested_shape_vector_shape_t(nested_shape_card_t(0, 10), 1);
	card_t size504 = width_matrix_shape_t(matrix_c);
	array_number_t stgVar501 = storage_alloc(size504);
	array_number_t macroDef503;array_array_number_t matrix_s = matrix_read_s(stgVar501, fn_s, startLine_s, 1);
	macroDef503 = matrix_s->arr[0];;
	storage_free(stgVar501, size504);
	return macroDef503;
}

card_t TOP_LEVEL_linalg_numberRead_c(card_t fn_c, card_t startLine_c) {
	
	return 0;
}


number_t TOP_LEVEL_linalg_numberRead_s(storage_t stgVar505, string_t fn_s, index_t startLine_s, card_t fn_c, card_t startLine_c) {
	vector_shape_t vector_c = TOP_LEVEL_linalg_vectorRead_c(0, 0);
	card_t size511 = width_vector_shape_t(vector_c);
	array_number_t stgVar506 = storage_alloc(size511);
	number_t macroDef510;array_number_t vector_s = TOP_LEVEL_linalg_vectorRead_s(stgVar506, fn_s, startLine_s, 0, 0);
	macroDef510 = vector_s->arr[0];;
	storage_free(stgVar506, size511);
	return macroDef510;
}
#endif
