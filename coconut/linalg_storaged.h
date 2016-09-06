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
		macroDef11->arr=(number_t*)((char*)macroDef11 + VECTOR_HEADER_BYTES);
		storage_t stgVar3 = macroDef11;
		for(int i_s = 0; i_s < macroDef11->length; i_s++){
			
			macroDef11->arr[i_s] = f_s.lam(f_s.env, stgVar3, v_s->arr[i_s], 0).number_t_value;;
			stgVar3 = (char*)stgVar3 + sizeof(number_t);
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
		macroDef18->arr=(number_t*)((char*)macroDef18 + VECTOR_HEADER_BYTES);
		storage_t stgVar13 = macroDef18;
		for(int i_s = 0; i_s < macroDef18->length; i_s++){
			
			macroDef18->arr[i_s] = (double)(((s_s)) + (i_s));;
			stgVar13 = (char*)stgVar13 + sizeof(number_t);
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
		macroDef26->arr=(number_t*)((char*)macroDef26 + VECTOR_HEADER_BYTES);
		storage_t stgVar20 = macroDef26;
		for(int i_s = 0; i_s < macroDef26->length; i_s++){
			
			macroDef26->arr[i_s] = v_s->arr[(i_s) + (offset_s)];;
			stgVar20 = (char*)stgVar20 + sizeof(number_t);
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
		macroDef40->arr=(array_number_t*)((char*)macroDef40 + VECTOR_HEADER_BYTES);
		storage_t stgVar29 = ((char*)macroDef40 + MATRIX_HEADER_BYTES(macroDef38));
		for(int i_s = 0; i_s < macroDef40->length; i_s++){
			array_number_t stgVar30 = malloc(width_vector_shape_t(m_c.elem));
	array_number_t macroDef39;
	macroDef39 = f_s.lam(f_s.env, stgVar29, m_s->arr[i_s], m_c.elem).array_number_t_value;;
	free(stgVar30);
			macroDef40->arr[i_s] = macroDef39;;
			stgVar29 = (char*)stgVar29 + VECTOR_ALL_BYTES(macroDef40->arr[i_s]->length);
		}
	return macroDef40;
}
typedef empty_env_t env_t_51;


value_t lambda51(env_t_51* env48, card_t i_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
vector_shape_t TOP_LEVEL_linalg_vectorMap2_c(closure_t f_c, vector_shape_t v1_c, vector_shape_t v2_c) {
	env_t_51 env_t_51_value = make_empty_env(); closure_t closure50 = make_closure(lambda51, &env_t_51_value);
	return nested_shape_card_t(closure50.lam(closure50.env, 0).card_t_value, v1_c.card);
}


array_number_t TOP_LEVEL_linalg_vectorMap2_s(storage_t stgVar41, closure_t f_s, array_number_t v1_s, array_number_t v2_s, closure_t f_c, vector_shape_t v1_c, vector_shape_t v2_c) {
	card_t macroDef52 = v1_s->length;
	array_number_t macroDef53 = (array_number_t)stgVar41;
		macroDef53->length=macroDef52;
		macroDef53->arr=(number_t*)((char*)macroDef53 + VECTOR_HEADER_BYTES);
		storage_t stgVar43 = macroDef53;
		for(int i_s = 0; i_s < macroDef53->length; i_s++){
			
			macroDef53->arr[i_s] = f_s.lam(f_s.env, stgVar43, v1_s->arr[i_s], v2_s->arr[i_s], 0, 0).number_t_value;;
			stgVar43 = (char*)stgVar43 + sizeof(number_t);
		}
	return macroDef53;
}
typedef struct env_t_67 {
	matrix_shape_t m2_c;
	matrix_shape_t m1_c;
	closure_t f_c;
} env_t_67;
env_t_67 make_env_t_67(matrix_shape_t m2_c,matrix_shape_t m1_c,closure_t f_c) {
	env_t_67 env;
	env.m2_c = m2_c;
	env.m1_c = m1_c;
	env.f_c = f_c;
	return env;
}

value_t lambda67(env_t_67* env64, card_t i_c) {
	matrix_shape_t m2_c63 = env64->m2_c;
	matrix_shape_t m1_c62 = env64->m1_c;
	closure_t f_c61 = env64->f_c;
	value_t res;
	res.vector_shape_t_value = f_c61.lam(f_c61.env, m1_c62.elem, m2_c63.elem).vector_shape_t_value;
	return res;
}
matrix_shape_t TOP_LEVEL_linalg_matrixMap2_c(closure_t f_c, matrix_shape_t m1_c, matrix_shape_t m2_c) {
	env_t_67 env_t_67_value = make_env_t_67(m2_c,m1_c,f_c); closure_t closure66 = make_closure(lambda67, &env_t_67_value);
	return nested_shape_vector_shape_t(closure66.lam(closure66.env, 0).vector_shape_t_value, m1_c.card);
}


array_array_number_t TOP_LEVEL_linalg_matrixMap2_s(storage_t stgVar54, closure_t f_s, array_array_number_t m1_s, array_array_number_t m2_s, closure_t f_c, matrix_shape_t m1_c, matrix_shape_t m2_c) {
	card_t macroDef68 = m1_s->length;
	array_array_number_t macroDef71 = (array_array_number_t)stgVar54;
		macroDef71->length=macroDef68;
		macroDef71->arr=(array_number_t*)((char*)macroDef71 + VECTOR_HEADER_BYTES);
		storage_t stgVar56 = ((char*)macroDef71 + MATRIX_HEADER_BYTES(macroDef68));
		for(int i_s = 0; i_s < macroDef71->length; i_s++){
			array_number_t stgVar58 = malloc(width_vector_shape_t(m2_c.elem));
	array_number_t macroDef70;array_number_t stgVar57 = malloc(width_vector_shape_t(m1_c.elem));
	array_number_t macroDef69;
	macroDef69 = f_s.lam(f_s.env, stgVar56, m1_s->arr[i_s], m2_s->arr[i_s], m1_c.elem, m2_c.elem).array_number_t_value;;
	free(stgVar57);
	macroDef70 = macroDef69;;
	free(stgVar58);
			macroDef71->arr[i_s] = macroDef70;;
			stgVar56 = (char*)stgVar56 + VECTOR_ALL_BYTES(macroDef71->arr[i_s]->length);
		}
	return macroDef71;
}
typedef struct env_t_85 {
	matrix3d_shape_t m2_c;
	matrix3d_shape_t m1_c;
	closure_t f_c;
} env_t_85;
env_t_85 make_env_t_85(matrix3d_shape_t m2_c,matrix3d_shape_t m1_c,closure_t f_c) {
	env_t_85 env;
	env.m2_c = m2_c;
	env.m1_c = m1_c;
	env.f_c = f_c;
	return env;
}

value_t lambda85(env_t_85* env82, card_t i_c) {
	matrix3d_shape_t m2_c81 = env82->m2_c;
	matrix3d_shape_t m1_c80 = env82->m1_c;
	closure_t f_c79 = env82->f_c;
	value_t res;
	res.matrix_shape_t_value = f_c79.lam(f_c79.env, m1_c80.elem, m2_c81.elem).matrix_shape_t_value;
	return res;
}
matrix3d_shape_t TOP_LEVEL_linalg_matrix3DMap2_c(closure_t f_c, matrix3d_shape_t m1_c, matrix3d_shape_t m2_c) {
	env_t_85 env_t_85_value = make_env_t_85(m2_c,m1_c,f_c); closure_t closure84 = make_closure(lambda85, &env_t_85_value);
	return nested_shape_matrix_shape_t(closure84.lam(closure84.env, 0).matrix_shape_t_value, m1_c.card);
}


array_array_array_number_t TOP_LEVEL_linalg_matrix3DMap2_s(storage_t stgVar72, closure_t f_s, array_array_array_number_t m1_s, array_array_array_number_t m2_s, closure_t f_c, matrix3d_shape_t m1_c, matrix3d_shape_t m2_c) {
	card_t macroDef86 = m1_s->length;
	array_array_array_number_t macroDef89 = (array_array_array_number_t)stgVar72;
		macroDef89->length=macroDef86;
		macroDef89->arr=(array_array_number_t*)((char*)macroDef89 + VECTOR_HEADER_BYTES);
		storage_t stgVar74 = ((char*)macroDef89 + MATRIX_HEADER_BYTES(macroDef86));
		for(int i_s = 0; i_s < macroDef89->length; i_s++){
			array_number_t stgVar76 = malloc(width_matrix_shape_t(m2_c.elem));
	array_array_number_t macroDef88;array_number_t stgVar75 = malloc(width_matrix_shape_t(m1_c.elem));
	array_array_number_t macroDef87;
	macroDef87 = f_s.lam(f_s.env, stgVar74, m1_s->arr[i_s], m2_s->arr[i_s], m1_c.elem, m2_c.elem).array_array_number_t_value;;
	free(stgVar75);
	macroDef88 = macroDef87;;
	free(stgVar76);
			macroDef89->arr[i_s] = macroDef88;;
			stgVar74 = (char*)stgVar74 + VECTOR_ALL_BYTES(macroDef89->arr[i_s]->length);
		}
	return macroDef89;
}
typedef struct env_t_99 {
	closure_t f_c;
} env_t_99;
env_t_99 make_env_t_99(closure_t f_c) {
	env_t_99 env;
	env.f_c = f_c;
	return env;
}

value_t lambda99(env_t_99* env96, card_t i_c) {
	closure_t f_c95 = env96->f_c;
	value_t res;
	res.vector_shape_t_value = f_c95.lam(f_c95.env, 0).vector_shape_t_value;
	return res;
}
matrix_shape_t TOP_LEVEL_linalg_vectorMapToMatrix_c(closure_t f_c, vector_shape_t arr_c) {
	env_t_99 env_t_99_value = make_env_t_99(f_c); closure_t closure98 = make_closure(lambda99, &env_t_99_value);
	return nested_shape_vector_shape_t(closure98.lam(closure98.env, 0).vector_shape_t_value, arr_c.card);
}


array_array_number_t TOP_LEVEL_linalg_vectorMapToMatrix_s(storage_t stgVar90, closure_t f_s, array_number_t arr_s, closure_t f_c, vector_shape_t arr_c) {
	card_t macroDef100 = arr_s->length;
	array_array_number_t macroDef101 = (array_array_number_t)stgVar90;
		macroDef101->length=macroDef100;
		macroDef101->arr=(array_number_t*)((char*)macroDef101 + VECTOR_HEADER_BYTES);
		storage_t stgVar92 = ((char*)macroDef101 + MATRIX_HEADER_BYTES(macroDef100));
		for(int i_s = 0; i_s < macroDef101->length; i_s++){
			
			macroDef101->arr[i_s] = f_s.lam(f_s.env, stgVar92, arr_s->arr[i_s], 0).array_number_t_value;;
			stgVar92 = (char*)stgVar92 + VECTOR_ALL_BYTES(macroDef101->arr[i_s]->length);
		}
	return macroDef101;
}
typedef struct env_t_111 {
	closure_t f_c;
} env_t_111;
env_t_111 make_env_t_111(closure_t f_c) {
	env_t_111 env;
	env.f_c = f_c;
	return env;
}

value_t lambda111(env_t_111* env108, card_t i_c) {
	closure_t f_c107 = env108->f_c;
	value_t res;
	res.matrix_shape_t_value = f_c107.lam(f_c107.env, 0).matrix_shape_t_value;
	return res;
}
matrix3d_shape_t TOP_LEVEL_linalg_vectorMapToMatrix3D_c(closure_t f_c, vector_shape_t arr_c) {
	env_t_111 env_t_111_value = make_env_t_111(f_c); closure_t closure110 = make_closure(lambda111, &env_t_111_value);
	return nested_shape_matrix_shape_t(closure110.lam(closure110.env, 0).matrix_shape_t_value, arr_c.card);
}


array_array_array_number_t TOP_LEVEL_linalg_vectorMapToMatrix3D_s(storage_t stgVar102, closure_t f_s, array_number_t arr_s, closure_t f_c, vector_shape_t arr_c) {
	card_t macroDef112 = arr_s->length;
	array_array_array_number_t macroDef113 = (array_array_array_number_t)stgVar102;
		macroDef113->length=macroDef112;
		macroDef113->arr=(array_array_number_t*)((char*)macroDef113 + VECTOR_HEADER_BYTES);
		storage_t stgVar104 = ((char*)macroDef113 + MATRIX_HEADER_BYTES(macroDef112));
		for(int i_s = 0; i_s < macroDef113->length; i_s++){
			
			macroDef113->arr[i_s] = f_s.lam(f_s.env, stgVar104, arr_s->arr[i_s], 0).array_array_number_t_value;;
			stgVar104 = (char*)stgVar104 + VECTOR_ALL_BYTES(macroDef113->arr[i_s]->length);
		}
	return macroDef113;
}

card_t TOP_LEVEL_linalg_iterateNumber_c(closure_t f_c, card_t z_c, card_t s_c, card_t e_c) {
	
	return 0;
}


number_t TOP_LEVEL_linalg_iterateNumber_s(storage_t stgVar114, closure_t f_s, number_t z_s, card_t s_s, card_t e_s, closure_t f_c, card_t z_c, card_t s_c, card_t e_c) {
	number_t macroDef120 = z_s;
	array_number_t cur_s_range = TOP_LEVEL_linalg_vectorRange_s(empty_storage, s_s, e_s, s_c, e_c);
	storage_t stgVar115 = stgVar114;
	for(int cur_s_idx = 0; cur_s_idx < cur_s_range->length; cur_s_idx++){
		number_t cur_s = cur_s_range->arr[cur_s_idx];
		
		macroDef120 = f_s.lam(f_s.env, stgVar115, macroDef120, (int)(cur_s), 0, 0).number_t_value;;
	}
	return macroDef120;
}

vector_shape_t TOP_LEVEL_linalg_iterateVector_c(closure_t f_c, vector_shape_t z_c, card_t s_c, card_t e_c) {
	
	return z_c;
}


array_number_t TOP_LEVEL_linalg_iterateVector_s(storage_t stgVar121, closure_t f_s, array_number_t z_s, card_t s_s, card_t e_s, closure_t f_c, vector_shape_t z_c, card_t s_c, card_t e_c) {
	array_number_t macroDef127 = z_s;
	array_number_t cur_s_range = TOP_LEVEL_linalg_vectorRange_s(empty_storage, s_s, e_s, s_c, e_c);
	storage_t stgVar122 = stgVar121;
	for(int cur_s_idx = 0; cur_s_idx < cur_s_range->length; cur_s_idx++){
		number_t cur_s = cur_s_range->arr[cur_s_idx];
		
		macroDef127 = f_s.lam(f_s.env, stgVar122, macroDef127, (int)(cur_s), z_c, 0).array_number_t_value;;
	}
	return macroDef127;
}

matrix_shape_t TOP_LEVEL_linalg_iterateMatrix_c(closure_t f_c, matrix_shape_t z_c, card_t s_c, card_t e_c) {
	
	return z_c;
}


array_array_number_t TOP_LEVEL_linalg_iterateMatrix_s(storage_t stgVar128, closure_t f_s, array_array_number_t z_s, card_t s_s, card_t e_s, closure_t f_c, matrix_shape_t z_c, card_t s_c, card_t e_c) {
	array_array_number_t macroDef134 = z_s;
	array_number_t cur_s_range = TOP_LEVEL_linalg_vectorRange_s(empty_storage, s_s, e_s, s_c, e_c);
	storage_t stgVar129 = stgVar128;
	for(int cur_s_idx = 0; cur_s_idx < cur_s_range->length; cur_s_idx++){
		number_t cur_s = cur_s_range->arr[cur_s_idx];
		
		macroDef134 = f_s.lam(f_s.env, stgVar129, macroDef134, (int)(cur_s), z_c, 0).array_array_number_t_value;;
	}
	return macroDef134;
}

matrix3d_shape_t TOP_LEVEL_linalg_iterateMatrix3D_c(closure_t f_c, matrix3d_shape_t z_c, card_t s_c, card_t e_c) {
	
	return z_c;
}


array_array_array_number_t TOP_LEVEL_linalg_iterateMatrix3D_s(storage_t stgVar135, closure_t f_s, array_array_array_number_t z_s, card_t s_s, card_t e_s, closure_t f_c, matrix3d_shape_t z_c, card_t s_c, card_t e_c) {
	array_array_array_number_t macroDef141 = z_s;
	array_number_t cur_s_range = TOP_LEVEL_linalg_vectorRange_s(empty_storage, s_s, e_s, s_c, e_c);
	storage_t stgVar136 = stgVar135;
	for(int cur_s_idx = 0; cur_s_idx < cur_s_range->length; cur_s_idx++){
		number_t cur_s = cur_s_range->arr[cur_s_idx];
		
		macroDef141 = f_s.lam(f_s.env, stgVar136, macroDef141, (int)(cur_s), z_c, 0).array_array_array_number_t_value;;
	}
	return macroDef141;
}

card_t TOP_LEVEL_linalg_arraySum_c(vector_shape_t arr_c) {
	
	return 0;
}


number_t TOP_LEVEL_linalg_arraySum_s(storage_t stgVar142, array_number_t arr_s, vector_shape_t arr_c) {
	number_t macroDef144 = 0;
	array_number_t cur_s_range = arr_s;
	storage_t stgVar143 = stgVar142;
	for(int cur_s_idx = 0; cur_s_idx < cur_s_range->length; cur_s_idx++){
		number_t cur_s = cur_s_range->arr[cur_s_idx];
		
		macroDef144 = (macroDef144) + (cur_s);;
	}
	return macroDef144;
}

card_t TOP_LEVEL_linalg_arrayMax_c(vector_shape_t arr_c) {
	
	return 0;
}


number_t TOP_LEVEL_linalg_arrayMax_s(storage_t stgVar145, array_number_t arr_s, vector_shape_t arr_c) {
	number_t macroDef147 = -1000;
	array_number_t cur_s_range = arr_s;
	storage_t stgVar146 = stgVar145;
	for(int cur_s_idx = 0; cur_s_idx < cur_s_range->length; cur_s_idx++){
		number_t cur_s = cur_s_range->arr[cur_s_idx];
		number_t ite148 = 0;
	if((macroDef147) > (cur_s)) {
		
		ite148 = macroDef147;;
	} else {
		
		ite148 = cur_s;;
	}
		macroDef147 = ite148;;
	}
	return macroDef147;
}
typedef empty_env_t env_t_156;


value_t lambda156(env_t_156* env153, card_t a_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
vector_shape_t TOP_LEVEL_linalg_mult_by_scalar_c(vector_shape_t x_c, card_t y_c) {
	env_t_156 env_t_156_value = make_empty_env(); closure_t closure155 = make_closure(lambda156, &env_t_156_value);
	return TOP_LEVEL_linalg_vectorMap_c(closure155, x_c);
}

typedef struct env_t_164 {
	number_t y_s;
} env_t_164;
env_t_164 make_env_t_164(number_t y_s) {
	env_t_164 env;
	env.y_s = y_s;
	return env;
}

value_t lambda164(env_t_164* env158, storage_t stgVar152, number_t a_s, card_t a_c) {
	number_t y_s157 = env158->y_s;
	value_t res;
	res.number_t_value = (a_s) * (y_s157);
	return res;
}
typedef empty_env_t env_t_165;


value_t lambda165(env_t_165* env161, card_t a_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
array_number_t TOP_LEVEL_linalg_mult_by_scalar_s(storage_t stgVar149, array_number_t x_s, number_t y_s, vector_shape_t x_c, card_t y_c) {
	env_t_164 env_t_164_value = make_env_t_164(y_s); closure_t closure160 = make_closure(lambda164, &env_t_164_value);
	env_t_165 env_t_165_value = make_empty_env(); closure_t closure163 = make_closure(lambda165, &env_t_165_value);
	return TOP_LEVEL_linalg_vectorMap_s(stgVar149, closure160, x_s, closure163, x_c);
}

vector_shape_t TOP_LEVEL_linalg_cross_c(vector_shape_t a_c, vector_shape_t b_c) {
	
	return nested_shape_card_t(0, 3);
}


array_number_t TOP_LEVEL_linalg_cross_s(storage_t stgVar166, array_number_t a_s, array_number_t b_s, vector_shape_t a_c, vector_shape_t b_c) {
	array_number_t macroDef182 = (array_number_t)stgVar166;
	macroDef182->length=3;
	macroDef182->arr=(number_t*)((char*)stgVar166 + VECTOR_HEADER_BYTES);
	macroDef182->arr[0] = ((a_s->arr[1]) * (b_s->arr[2])) - ((a_s->arr[2]) * (b_s->arr[1]));
	macroDef182->arr[1] = ((a_s->arr[2]) * (b_s->arr[0])) - ((a_s->arr[0]) * (b_s->arr[2]));
	macroDef182->arr[2] = ((a_s->arr[0]) * (b_s->arr[1])) - ((a_s->arr[1]) * (b_s->arr[0]));;
	return macroDef182;
}
typedef empty_env_t env_t_191;


value_t lambda191(env_t_191* env188, card_t x_c, card_t y_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
vector_shape_t TOP_LEVEL_linalg_add_vec_c(vector_shape_t x_c, vector_shape_t y_c) {
	env_t_191 env_t_191_value = make_empty_env(); closure_t closure190 = make_closure(lambda191, &env_t_191_value);
	return TOP_LEVEL_linalg_vectorMap2_c(closure190, x_c, y_c);
}

typedef empty_env_t env_t_198;


value_t lambda198(env_t_198* env192, storage_t stgVar187, number_t x_s, number_t y_s, card_t x_c, card_t y_c) {
	
	value_t res;
	res.number_t_value = (x_s) + (y_s);
	return res;
}
typedef empty_env_t env_t_199;


value_t lambda199(env_t_199* env195, card_t x_c, card_t y_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
array_number_t TOP_LEVEL_linalg_add_vec_s(storage_t stgVar183, array_number_t x_s, array_number_t y_s, vector_shape_t x_c, vector_shape_t y_c) {
	env_t_198 env_t_198_value = make_empty_env(); closure_t closure194 = make_closure(lambda198, &env_t_198_value);
	env_t_199 env_t_199_value = make_empty_env(); closure_t closure197 = make_closure(lambda199, &env_t_199_value);
	return TOP_LEVEL_linalg_vectorMap2_s(stgVar183, closure194, x_s, y_s, closure197, x_c, y_c);
}
typedef empty_env_t env_t_208;


value_t lambda208(env_t_208* env205, card_t x_c, card_t y_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
vector_shape_t TOP_LEVEL_linalg_mult_vec_elementwise_c(vector_shape_t x_c, vector_shape_t y_c) {
	env_t_208 env_t_208_value = make_empty_env(); closure_t closure207 = make_closure(lambda208, &env_t_208_value);
	return TOP_LEVEL_linalg_vectorMap2_c(closure207, x_c, y_c);
}

typedef empty_env_t env_t_215;


value_t lambda215(env_t_215* env209, storage_t stgVar204, number_t x_s, number_t y_s, card_t x_c, card_t y_c) {
	
	value_t res;
	res.number_t_value = (x_s) * (y_s);
	return res;
}
typedef empty_env_t env_t_216;


value_t lambda216(env_t_216* env212, card_t x_c, card_t y_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
array_number_t TOP_LEVEL_linalg_mult_vec_elementwise_s(storage_t stgVar200, array_number_t x_s, array_number_t y_s, vector_shape_t x_c, vector_shape_t y_c) {
	env_t_215 env_t_215_value = make_empty_env(); closure_t closure211 = make_closure(lambda215, &env_t_215_value);
	env_t_216 env_t_216_value = make_empty_env(); closure_t closure214 = make_closure(lambda216, &env_t_216_value);
	return TOP_LEVEL_linalg_vectorMap2_s(stgVar200, closure211, x_s, y_s, closure214, x_c, y_c);
}

vector_shape_t TOP_LEVEL_linalg_add_vec3_c(vector_shape_t x_c, vector_shape_t y_c, vector_shape_t z_c) {
	
	return TOP_LEVEL_linalg_add_vec_c(TOP_LEVEL_linalg_add_vec_c(x_c, y_c), z_c);
}


array_number_t TOP_LEVEL_linalg_add_vec3_s(storage_t stgVar217, array_number_t x_s, array_number_t y_s, array_number_t z_s, vector_shape_t x_c, vector_shape_t y_c, vector_shape_t z_c) {
	array_number_t stgVar218 = malloc(width_vector_shape_t(TOP_LEVEL_linalg_add_vec_c(x_c, y_c)));
	array_number_t macroDef222;
	macroDef222 = TOP_LEVEL_linalg_add_vec_s(stgVar217, TOP_LEVEL_linalg_add_vec_s(stgVar218, x_s, y_s, x_c, y_c), z_s, TOP_LEVEL_linalg_add_vec_c(x_c, y_c), z_c);;
	free(stgVar218);
	return macroDef222;
}
typedef empty_env_t env_t_231;


value_t lambda231(env_t_231* env228, card_t x_c, card_t y_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
vector_shape_t TOP_LEVEL_linalg_sub_vec_c(vector_shape_t x_c, vector_shape_t y_c) {
	env_t_231 env_t_231_value = make_empty_env(); closure_t closure230 = make_closure(lambda231, &env_t_231_value);
	return TOP_LEVEL_linalg_vectorMap2_c(closure230, x_c, y_c);
}

typedef empty_env_t env_t_238;


value_t lambda238(env_t_238* env232, storage_t stgVar227, number_t x_s, number_t y_s, card_t x_c, card_t y_c) {
	
	value_t res;
	res.number_t_value = (x_s) - (y_s);
	return res;
}
typedef empty_env_t env_t_239;


value_t lambda239(env_t_239* env235, card_t x_c, card_t y_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
array_number_t TOP_LEVEL_linalg_sub_vec_s(storage_t stgVar223, array_number_t x_s, array_number_t y_s, vector_shape_t x_c, vector_shape_t y_c) {
	env_t_238 env_t_238_value = make_empty_env(); closure_t closure234 = make_closure(lambda238, &env_t_238_value);
	env_t_239 env_t_239_value = make_empty_env(); closure_t closure237 = make_closure(lambda239, &env_t_239_value);
	return TOP_LEVEL_linalg_vectorMap2_s(stgVar223, closure234, x_s, y_s, closure237, x_c, y_c);
}
typedef empty_env_t env_t_250;


value_t lambda250(env_t_250* env247, vector_shape_t x_c, vector_shape_t y_c) {
	
	value_t res;
	res.vector_shape_t_value = TOP_LEVEL_linalg_add_vec_c(x_c, y_c);
	return res;
}
matrix_shape_t TOP_LEVEL_linalg_matrixAdd_c(matrix_shape_t x_c, matrix_shape_t y_c) {
	env_t_250 env_t_250_value = make_empty_env(); closure_t closure249 = make_closure(lambda250, &env_t_250_value);
	return TOP_LEVEL_linalg_matrixMap2_c(closure249, x_c, y_c);
}

typedef empty_env_t env_t_257;


value_t lambda257(env_t_257* env251, storage_t stgVar244, array_number_t x_s, array_number_t y_s, vector_shape_t x_c, vector_shape_t y_c) {
	
	value_t res;
	res.array_number_t_value = TOP_LEVEL_linalg_add_vec_s(stgVar244, x_s, y_s, x_c, y_c);
	return res;
}
typedef empty_env_t env_t_258;


value_t lambda258(env_t_258* env254, vector_shape_t x_c, vector_shape_t y_c) {
	
	value_t res;
	res.vector_shape_t_value = TOP_LEVEL_linalg_add_vec_c(x_c, y_c);
	return res;
}
array_array_number_t TOP_LEVEL_linalg_matrixAdd_s(storage_t stgVar240, array_array_number_t x_s, array_array_number_t y_s, matrix_shape_t x_c, matrix_shape_t y_c) {
	env_t_257 env_t_257_value = make_empty_env(); closure_t closure253 = make_closure(lambda257, &env_t_257_value);
	env_t_258 env_t_258_value = make_empty_env(); closure_t closure256 = make_closure(lambda258, &env_t_258_value);
	return TOP_LEVEL_linalg_matrixMap2_s(stgVar240, closure253, x_s, y_s, closure256, x_c, y_c);
}
typedef empty_env_t env_t_269;


value_t lambda269(env_t_269* env266, vector_shape_t x_c, vector_shape_t y_c) {
	
	value_t res;
	res.vector_shape_t_value = TOP_LEVEL_linalg_mult_vec_elementwise_c(x_c, y_c);
	return res;
}
matrix_shape_t TOP_LEVEL_linalg_matrixMultElementwise_c(matrix_shape_t x_c, matrix_shape_t y_c) {
	env_t_269 env_t_269_value = make_empty_env(); closure_t closure268 = make_closure(lambda269, &env_t_269_value);
	return TOP_LEVEL_linalg_matrixMap2_c(closure268, x_c, y_c);
}

typedef empty_env_t env_t_276;


value_t lambda276(env_t_276* env270, storage_t stgVar263, array_number_t x_s, array_number_t y_s, vector_shape_t x_c, vector_shape_t y_c) {
	
	value_t res;
	res.array_number_t_value = TOP_LEVEL_linalg_mult_vec_elementwise_s(stgVar263, x_s, y_s, x_c, y_c);
	return res;
}
typedef empty_env_t env_t_277;


value_t lambda277(env_t_277* env273, vector_shape_t x_c, vector_shape_t y_c) {
	
	value_t res;
	res.vector_shape_t_value = TOP_LEVEL_linalg_mult_vec_elementwise_c(x_c, y_c);
	return res;
}
array_array_number_t TOP_LEVEL_linalg_matrixMultElementwise_s(storage_t stgVar259, array_array_number_t x_s, array_array_number_t y_s, matrix_shape_t x_c, matrix_shape_t y_c) {
	env_t_276 env_t_276_value = make_empty_env(); closure_t closure272 = make_closure(lambda276, &env_t_276_value);
	env_t_277 env_t_277_value = make_empty_env(); closure_t closure275 = make_closure(lambda277, &env_t_277_value);
	return TOP_LEVEL_linalg_matrixMap2_s(stgVar259, closure272, x_s, y_s, closure275, x_c, y_c);
}

card_t TOP_LEVEL_linalg_sqnorm_c(vector_shape_t x_c) {
	
	return 0;
}

typedef empty_env_t env_t_296;


value_t lambda296(env_t_296* env283, card_t x1_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef empty_env_t env_t_297;


value_t lambda297(env_t_297* env286, storage_t stgVar282, number_t x1_s, card_t x1_c) {
	
	value_t res;
	res.number_t_value = (x1_s) * (x1_s);
	return res;
}
typedef empty_env_t env_t_298;


value_t lambda298(env_t_298* env289, card_t x1_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef empty_env_t env_t_299;


value_t lambda299(env_t_299* env292, card_t x1_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
number_t TOP_LEVEL_linalg_sqnorm_s(storage_t stgVar278, array_number_t x_s, vector_shape_t x_c) {
	env_t_296 env_t_296_value = make_empty_env(); closure_t closure285 = make_closure(lambda296, &env_t_296_value);
	array_number_t stgVar279 = malloc(width_vector_shape_t(TOP_LEVEL_linalg_vectorMap_c(closure285, x_c)));
	number_t macroDef295;env_t_297 env_t_297_value = make_empty_env(); closure_t closure288 = make_closure(lambda297, &env_t_297_value);
	env_t_298 env_t_298_value = make_empty_env(); closure_t closure291 = make_closure(lambda298, &env_t_298_value);
	env_t_299 env_t_299_value = make_empty_env(); closure_t closure294 = make_closure(lambda299, &env_t_299_value);
	macroDef295 = TOP_LEVEL_linalg_arraySum_s(stgVar278, TOP_LEVEL_linalg_vectorMap_s(stgVar279, closure288, x_s, closure291, x_c), TOP_LEVEL_linalg_vectorMap_c(closure294, x_c));;
	free(stgVar279);
	return macroDef295;
}

card_t TOP_LEVEL_linalg_dot_prod_c(vector_shape_t x_c, vector_shape_t y_c) {
	
	return 0;
}

typedef empty_env_t env_t_319;


value_t lambda319(env_t_319* env306, card_t x_c, card_t y_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef empty_env_t env_t_320;


value_t lambda320(env_t_320* env309, storage_t stgVar305, number_t x_s, number_t y_s, card_t x_c, card_t y_c) {
	
	value_t res;
	res.number_t_value = (x_s) * (y_s);
	return res;
}
typedef empty_env_t env_t_321;


value_t lambda321(env_t_321* env312, card_t x_c, card_t y_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef empty_env_t env_t_322;


value_t lambda322(env_t_322* env315, card_t x_c, card_t y_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
number_t TOP_LEVEL_linalg_dot_prod_s(storage_t stgVar300, array_number_t x_s, array_number_t y_s, vector_shape_t x_c, vector_shape_t y_c) {
	env_t_319 env_t_319_value = make_empty_env(); closure_t closure308 = make_closure(lambda319, &env_t_319_value);
	array_number_t stgVar301 = malloc(width_vector_shape_t(TOP_LEVEL_linalg_vectorMap2_c(closure308, x_c, y_c)));
	number_t macroDef318;env_t_320 env_t_320_value = make_empty_env(); closure_t closure311 = make_closure(lambda320, &env_t_320_value);
	env_t_321 env_t_321_value = make_empty_env(); closure_t closure314 = make_closure(lambda321, &env_t_321_value);
	env_t_322 env_t_322_value = make_empty_env(); closure_t closure317 = make_closure(lambda322, &env_t_322_value);
	macroDef318 = TOP_LEVEL_linalg_arraySum_s(stgVar300, TOP_LEVEL_linalg_vectorMap2_s(stgVar301, closure311, x_s, y_s, closure314, x_c, y_c), TOP_LEVEL_linalg_vectorMap2_c(closure317, x_c, y_c));;
	free(stgVar301);
	return macroDef318;
}
typedef struct env_t_333 {
	vector_shape_t row_c;
} env_t_333;
env_t_333 make_env_t_333(vector_shape_t row_c) {
	env_t_333 env;
	env.row_c = row_c;
	return env;
}

value_t lambda333(env_t_333* env330, card_t r_c) {
	vector_shape_t row_c329 = env330->row_c;
	value_t res;
	res.vector_shape_t_value = row_c329;
	return res;
}
matrix_shape_t TOP_LEVEL_linalg_matrixFillFromVector_c(card_t rows_c, vector_shape_t row_c) {
	env_t_333 env_t_333_value = make_env_t_333(row_c); closure_t closure332 = make_closure(lambda333, &env_t_333_value);
	return TOP_LEVEL_linalg_vectorMapToMatrix_c(closure332, TOP_LEVEL_linalg_vectorRange_c(1, rows_c));
}

typedef struct env_t_343 {
	array_number_t row_s;
} env_t_343;
env_t_343 make_env_t_343(array_number_t row_s) {
	env_t_343 env;
	env.row_s = row_s;
	return env;
}

value_t lambda343(env_t_343* env335, storage_t stgVar326, number_t r_s, card_t r_c) {
	array_number_t row_s334 = env335->row_s;
	value_t res;
	res.array_number_t_value = row_s334;
	return res;
}
typedef struct env_t_344 {
	vector_shape_t row_c;
} env_t_344;
env_t_344 make_env_t_344(vector_shape_t row_c) {
	env_t_344 env;
	env.row_c = row_c;
	return env;
}

value_t lambda344(env_t_344* env339, card_t r_c) {
	vector_shape_t row_c338 = env339->row_c;
	value_t res;
	res.vector_shape_t_value = row_c338;
	return res;
}
array_array_number_t TOP_LEVEL_linalg_matrixFillFromVector_s(storage_t stgVar323, card_t rows_s, array_number_t row_s, card_t rows_c, vector_shape_t row_c) {
	array_number_t stgVar325 = malloc(width_vector_shape_t(TOP_LEVEL_linalg_vectorRange_c(1, rows_c)));
	array_array_number_t macroDef342;env_t_343 env_t_343_value = make_env_t_343(row_s); closure_t closure337 = make_closure(lambda343, &env_t_343_value);
	env_t_344 env_t_344_value = make_env_t_344(row_c); closure_t closure341 = make_closure(lambda344, &env_t_344_value);
	macroDef342 = TOP_LEVEL_linalg_vectorMapToMatrix_s(stgVar323, closure337, TOP_LEVEL_linalg_vectorRange_s(stgVar325, 1, rows_s, 1, rows_c), closure341, TOP_LEVEL_linalg_vectorRange_c(1, rows_c));;
	free(stgVar325);
	return macroDef342;
}
typedef struct env_t_355 {
	card_t cols_c;
} env_t_355;
env_t_355 make_env_t_355(card_t cols_c) {
	env_t_355 env;
	env.cols_c = cols_c;
	return env;
}
typedef empty_env_t env_t_356;


value_t lambda356(env_t_356* env348, card_t c_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
value_t lambda355(env_t_355* env352, card_t r_c) {
	card_t cols_c351 = env352->cols_c;
	env_t_356 env_t_356_value = make_empty_env(); closure_t closure350 = make_closure(lambda356, &env_t_356_value);
	value_t res;
	res.vector_shape_t_value = nested_shape_card_t(closure350.lam(closure350.env, 0).card_t_value, cols_c351);
	return res;
}
matrix_shape_t TOP_LEVEL_linalg_matrixFill_c(card_t rows_c, card_t cols_c, card_t value_c) {
	env_t_355 env_t_355_value = make_env_t_355(cols_c); closure_t closure354 = make_closure(lambda355, &env_t_355_value);
	return nested_shape_vector_shape_t(closure354.lam(closure354.env, 0).vector_shape_t_value, rows_c);
}


array_array_number_t TOP_LEVEL_linalg_matrixFill_s(storage_t stgVar345, card_t rows_s, card_t cols_s, number_t value_s, card_t rows_c, card_t cols_c, card_t value_c) {
	array_array_number_t macroDef361 = (array_array_number_t)stgVar345;
		macroDef361->length=rows_s;
		macroDef361->arr=(array_number_t*)((char*)macroDef361 + VECTOR_HEADER_BYTES);
		storage_t stgVar346 = ((char*)macroDef361 + MATRIX_HEADER_BYTES(rows_s));
		for(int r_s = 0; r_s < macroDef361->length; r_s++){
			array_number_t macroDef357 = (array_number_t)stgVar346;
		macroDef357->length=cols_s;
		macroDef357->arr=(number_t*)((char*)macroDef357 + VECTOR_HEADER_BYTES);
		storage_t stgVar347 = macroDef357;
		for(int c_s = 0; c_s < macroDef357->length; c_s++){
			
			macroDef357->arr[c_s] = value_s;;
			stgVar347 = (char*)stgVar347 + sizeof(number_t);
		}
			macroDef361->arr[r_s] = macroDef357;;
			stgVar346 = (char*)stgVar346 + VECTOR_ALL_BYTES(macroDef361->arr[r_s]->length);
		}
	return macroDef361;
}
typedef struct env_t_379 {
	card_t rows_c;
} env_t_379;
env_t_379 make_env_t_379(card_t rows_c) {
	env_t_379 env;
	env.rows_c = rows_c;
	return env;
}
typedef empty_env_t env_t_380;


value_t lambda380(env_t_380* env372, card_t j_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
value_t lambda379(env_t_379* env376, card_t i_c) {
	card_t rows_c375 = env376->rows_c;
	env_t_380 env_t_380_value = make_empty_env(); closure_t closure374 = make_closure(lambda380, &env_t_380_value);
	value_t res;
	res.vector_shape_t_value = nested_shape_card_t(closure374.lam(closure374.env, 0).card_t_value, rows_c375);
	return res;
}
matrix_shape_t TOP_LEVEL_linalg_matrixTranspose_c(matrix_shape_t m_c) {
	card_t rows_c = m_c.card;
	card_t cols_c = m_c.elem.card;
	env_t_379 env_t_379_value = make_env_t_379(rows_c); closure_t closure378 = make_closure(lambda379, &env_t_379_value);
	return nested_shape_vector_shape_t(closure378.lam(closure378.env, 0).vector_shape_t_value, cols_c);
}


array_array_number_t TOP_LEVEL_linalg_matrixTranspose_s(storage_t stgVar362, array_array_number_t m_s, matrix_shape_t m_c) {
	card_t rows_c = m_c.card;
	card_t macroDef381 = m_s->length;
	card_t rows_s = macroDef381;
	card_t cols_c = m_c.elem.card;
	array_number_t stgVar366 = malloc(width_vector_shape_t(m_c.elem));
	card_t macroDef383;card_t macroDef382 = m_s->arr[0]->length;
	macroDef383 = macroDef382;;
	free(stgVar366);
	card_t cols_s = macroDef383;
	array_array_number_t macroDef389 = (array_array_number_t)stgVar362;
		macroDef389->length=cols_s;
		macroDef389->arr=(array_number_t*)((char*)macroDef389 + VECTOR_HEADER_BYTES);
		storage_t stgVar368 = ((char*)macroDef389 + MATRIX_HEADER_BYTES(cols_s));
		for(int i_s = 0; i_s < macroDef389->length; i_s++){
			array_number_t macroDef385 = (array_number_t)stgVar368;
		macroDef385->length=rows_s;
		macroDef385->arr=(number_t*)((char*)macroDef385 + VECTOR_HEADER_BYTES);
		storage_t stgVar369 = macroDef385;
		for(int j_s = 0; j_s < macroDef385->length; j_s++){
			array_number_t stgVar370 = malloc(width_vector_shape_t(m_c.elem));
	number_t macroDef384;
	macroDef384 = m_s->arr[j_s]->arr[i_s];;
	free(stgVar370);
			macroDef385->arr[j_s] = macroDef384;;
			stgVar369 = (char*)stgVar369 + sizeof(number_t);
		}
			macroDef389->arr[i_s] = macroDef385;;
			stgVar368 = (char*)stgVar368 + VECTOR_ALL_BYTES(macroDef389->arr[i_s]->length);
		}
	return macroDef389;
}
typedef struct env_t_416 {
	card_t c2_c;
} env_t_416;
env_t_416 make_env_t_416(card_t c2_c) {
	env_t_416 env;
	env.c2_c = c2_c;
	return env;
}
typedef empty_env_t env_t_417;


value_t lambda417(env_t_417* env409, card_t c_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
value_t lambda416(env_t_416* env413, card_t r_c) {
	card_t c2_c412 = env413->c2_c;
	env_t_417 env_t_417_value = make_empty_env(); closure_t closure411 = make_closure(lambda417, &env_t_417_value);
	value_t res;
	res.vector_shape_t_value = nested_shape_card_t(closure411.lam(closure411.env, 0).card_t_value, c2_c412);
	return res;
}
matrix_shape_t TOP_LEVEL_linalg_matrixMult_c(matrix_shape_t m1_c, matrix_shape_t m2_c) {
	card_t r1_c = m1_c.card;
	card_t c2_c = m2_c.elem.card;
	card_t c1_c = m1_c.elem.card;
	card_t r2_c = m2_c.card;
	matrix_shape_t m2T_c = TOP_LEVEL_linalg_matrixTranspose_c(m2_c);
	env_t_416 env_t_416_value = make_env_t_416(c2_c); closure_t closure415 = make_closure(lambda416, &env_t_416_value);
	return nested_shape_vector_shape_t(closure415.lam(closure415.env, 0).vector_shape_t_value, r1_c);
}


array_array_number_t TOP_LEVEL_linalg_matrixMult_s(storage_t stgVar390, array_array_number_t m1_s, array_array_number_t m2_s, matrix_shape_t m1_c, matrix_shape_t m2_c) {
	card_t r1_c = m1_c.card;
	card_t macroDef418 = m1_s->length;
	card_t r1_s = macroDef418;
	card_t c2_c = m2_c.elem.card;
	array_number_t stgVar394 = malloc(width_vector_shape_t(m2_c.elem));
	card_t macroDef420;card_t macroDef419 = m2_s->arr[0]->length;
	macroDef420 = macroDef419;;
	free(stgVar394);
	card_t c2_s = macroDef420;
	card_t c1_c = m1_c.elem.card;
	array_number_t stgVar397 = malloc(width_vector_shape_t(m1_c.elem));
	card_t macroDef422;card_t macroDef421 = m1_s->arr[0]->length;
	macroDef422 = macroDef421;;
	free(stgVar397);
	card_t c1_s = macroDef422;
	card_t r2_c = m2_c.card;
	card_t macroDef423 = m2_s->length;
	card_t r2_s = macroDef423;
	matrix_shape_t m2T_c = TOP_LEVEL_linalg_matrixTranspose_c(m2_c);
	array_number_t stgVar401 = malloc(width_matrix_shape_t(m2T_c));
	array_array_number_t macroDef431;array_array_number_t m2T_s = TOP_LEVEL_linalg_matrixTranspose_s(stgVar401, m2_s, m2_c);
	array_array_number_t macroDef430 = (array_array_number_t)stgVar390;
		macroDef430->length=r1_s;
		macroDef430->arr=(array_number_t*)((char*)macroDef430 + VECTOR_HEADER_BYTES);
		storage_t stgVar403 = ((char*)macroDef430 + MATRIX_HEADER_BYTES(r1_s));
		for(int r_s = 0; r_s < macroDef430->length; r_s++){
			array_number_t macroDef426 = (array_number_t)stgVar403;
		macroDef426->length=c2_s;
		macroDef426->arr=(number_t*)((char*)macroDef426 + VECTOR_HEADER_BYTES);
		storage_t stgVar404 = macroDef426;
		for(int c_s = 0; c_s < macroDef426->length; c_s++){
			array_number_t stgVar406 = malloc(width_vector_shape_t(m2T_c.elem));
	number_t macroDef425;array_number_t stgVar405 = malloc(width_vector_shape_t(m1_c.elem));
	number_t macroDef424;
	macroDef424 = TOP_LEVEL_linalg_dot_prod_s(stgVar404, m1_s->arr[r_s], m2T_s->arr[c_s], m1_c.elem, m2T_c.elem);;
	free(stgVar405);
	macroDef425 = macroDef424;;
	free(stgVar406);
			macroDef426->arr[c_s] = macroDef425;;
			stgVar404 = (char*)stgVar404 + sizeof(number_t);
		}
			macroDef430->arr[r_s] = macroDef426;;
			stgVar403 = (char*)stgVar403 + VECTOR_ALL_BYTES(macroDef430->arr[r_s]->length);
		}
	macroDef431 = macroDef430;;
	free(stgVar401);
	return macroDef431;
}
typedef struct env_t_445 {
	matrix_shape_t m1_c;
} env_t_445;
env_t_445 make_env_t_445(matrix_shape_t m1_c) {
	env_t_445 env;
	env.m1_c = m1_c;
	return env;
}

value_t lambda445(env_t_445* env442, card_t r_c) {
	matrix_shape_t m1_c441 = env442->m1_c;
	value_t res;
	res.vector_shape_t_value = m1_c441.elem;
	return res;
}
matrix_shape_t TOP_LEVEL_linalg_matrixConcat_c(matrix_shape_t m1_c, matrix_shape_t m2_c) {
	card_t rows_c = (m1_c.card) + (m2_c.card);
	card_t m1Rows_c = 0;
	env_t_445 env_t_445_value = make_env_t_445(m1_c); closure_t closure444 = make_closure(lambda445, &env_t_445_value);
	return nested_shape_vector_shape_t(closure444.lam(closure444.env, 0).vector_shape_t_value, rows_c);
}


array_array_number_t TOP_LEVEL_linalg_matrixConcat_s(storage_t stgVar432, array_array_number_t m1_s, array_array_number_t m2_s, matrix_shape_t m1_c, matrix_shape_t m2_c) {
	card_t rows_c = (m1_c.card) + (m2_c.card);
	card_t macroDef446 = m1_s->length;
	card_t macroDef447 = m2_s->length;
	card_t rows_s = (macroDef446) + (macroDef447);
	card_t m1Rows_c = 0;
	card_t macroDef448 = m1_s->length;
	index_t m1Rows_s = (macroDef448);
	array_array_number_t macroDef449 = (array_array_number_t)stgVar432;
		macroDef449->length=rows_s;
		macroDef449->arr=(array_number_t*)((char*)macroDef449 + VECTOR_HEADER_BYTES);
		storage_t stgVar438 = ((char*)macroDef449 + MATRIX_HEADER_BYTES(rows_s));
		for(int r_s = 0; r_s < macroDef449->length; r_s++){
			array_number_t ite450 = 0;
	if((r_s) < (m1Rows_s)) {
		
		ite450 = m1_s->arr[r_s];;
	} else {
		
		ite450 = m2_s->arr[(r_s) - (m1Rows_s)];;
	}
			macroDef449->arr[r_s] = ite450;;
			stgVar438 = (char*)stgVar438 + VECTOR_ALL_BYTES(macroDef449->arr[r_s]->length);
		}
	return macroDef449;
}

matrix_shape_t TOP_LEVEL_linalg_matrixConcatCol_c(matrix_shape_t m1_c, matrix_shape_t m2_c) {
	matrix_shape_t m1t_c = TOP_LEVEL_linalg_matrixTranspose_c(m1_c);
	matrix_shape_t m2t_c = TOP_LEVEL_linalg_matrixTranspose_c(m2_c);
	return TOP_LEVEL_linalg_matrixTranspose_c(TOP_LEVEL_linalg_matrixConcat_c(m1t_c, m2t_c));
}


array_array_number_t TOP_LEVEL_linalg_matrixConcatCol_s(storage_t stgVar451, array_array_number_t m1_s, array_array_number_t m2_s, matrix_shape_t m1_c, matrix_shape_t m2_c) {
	matrix_shape_t m1t_c = TOP_LEVEL_linalg_matrixTranspose_c(m1_c);
	array_number_t stgVar452 = malloc(width_matrix_shape_t(m1t_c));
	array_array_number_t macroDef461;array_array_number_t m1t_s = TOP_LEVEL_linalg_matrixTranspose_s(stgVar452, m1_s, m1_c);
	matrix_shape_t m2t_c = TOP_LEVEL_linalg_matrixTranspose_c(m2_c);
	array_number_t stgVar454 = malloc(width_matrix_shape_t(m2t_c));
	array_array_number_t macroDef460;array_array_number_t m2t_s = TOP_LEVEL_linalg_matrixTranspose_s(stgVar454, m2_s, m2_c);
	array_number_t stgVar456 = malloc(width_matrix_shape_t(TOP_LEVEL_linalg_matrixConcat_c(m1t_c, m2t_c)));
	array_array_number_t macroDef459;
	macroDef459 = TOP_LEVEL_linalg_matrixTranspose_s(stgVar451, TOP_LEVEL_linalg_matrixConcat_s(stgVar456, m1t_s, m2t_s, m1t_c, m2t_c), TOP_LEVEL_linalg_matrixConcat_c(m1t_c, m2t_c));;
	free(stgVar456);
	macroDef460 = macroDef459;;
	free(stgVar454);
	macroDef461 = macroDef460;;
	free(stgVar452);
	return macroDef461;
}
typedef struct env_t_475 {
	matrix3d_shape_t m1_c;
} env_t_475;
env_t_475 make_env_t_475(matrix3d_shape_t m1_c) {
	env_t_475 env;
	env.m1_c = m1_c;
	return env;
}

value_t lambda475(env_t_475* env472, card_t r_c) {
	matrix3d_shape_t m1_c471 = env472->m1_c;
	value_t res;
	res.matrix_shape_t_value = m1_c471.elem;
	return res;
}
matrix3d_shape_t TOP_LEVEL_linalg_matrix3DConcat_c(matrix3d_shape_t m1_c, matrix3d_shape_t m2_c) {
	card_t rows_c = (m1_c.card) + (m2_c.card);
	card_t m1Rows_c = 0;
	env_t_475 env_t_475_value = make_env_t_475(m1_c); closure_t closure474 = make_closure(lambda475, &env_t_475_value);
	return nested_shape_matrix_shape_t(closure474.lam(closure474.env, 0).matrix_shape_t_value, rows_c);
}


array_array_array_number_t TOP_LEVEL_linalg_matrix3DConcat_s(storage_t stgVar462, array_array_array_number_t m1_s, array_array_array_number_t m2_s, matrix3d_shape_t m1_c, matrix3d_shape_t m2_c) {
	card_t rows_c = (m1_c.card) + (m2_c.card);
	card_t macroDef476 = m1_s->length;
	card_t macroDef477 = m2_s->length;
	card_t rows_s = (macroDef476) + (macroDef477);
	card_t m1Rows_c = 0;
	card_t macroDef478 = m1_s->length;
	index_t m1Rows_s = (macroDef478);
	array_array_array_number_t macroDef479 = (array_array_array_number_t)stgVar462;
		macroDef479->length=rows_s;
		macroDef479->arr=(array_array_number_t*)((char*)macroDef479 + VECTOR_HEADER_BYTES);
		storage_t stgVar468 = ((char*)macroDef479 + MATRIX_HEADER_BYTES(rows_s));
		for(int r_s = 0; r_s < macroDef479->length; r_s++){
			array_array_number_t ite480 = 0;
	if((r_s) < (m1Rows_s)) {
		
		ite480 = m1_s->arr[r_s];;
	} else {
		
		ite480 = m2_s->arr[(r_s) - (m1Rows_s)];;
	}
			macroDef479->arr[r_s] = ite480;;
			stgVar468 = (char*)stgVar468 + VECTOR_ALL_BYTES(macroDef479->arr[r_s]->length);
		}
	return macroDef479;
}

vector_shape_t TOP_LEVEL_linalg_vectorRead_c(card_t fn_c, card_t startLine_c) {
	matrix_shape_t matrix_c = nested_shape_vector_shape_t(nested_shape_card_t(0, 10), 1);
	return matrix_c.elem;
}


array_number_t TOP_LEVEL_linalg_vectorRead_s(storage_t stgVar481, string_t fn_s, index_t startLine_s, card_t fn_c, card_t startLine_c) {
	matrix_shape_t matrix_c = nested_shape_vector_shape_t(nested_shape_card_t(0, 10), 1);
	array_number_t stgVar482 = malloc(width_matrix_shape_t(matrix_c));
	array_number_t macroDef484;array_array_number_t matrix_s = matrix_read_s(stgVar482, fn_s, startLine_s, 1);
	macroDef484 = matrix_s->arr[0];;
	free(stgVar482);
	return macroDef484;
}

card_t TOP_LEVEL_linalg_numberRead_c(card_t fn_c, card_t startLine_c) {
	
	return 0;
}


number_t TOP_LEVEL_linalg_numberRead_s(storage_t stgVar485, string_t fn_s, index_t startLine_s, card_t fn_c, card_t startLine_c) {
	vector_shape_t vector_c = TOP_LEVEL_linalg_vectorRead_c(0, 0);
	array_number_t stgVar486 = malloc(width_vector_shape_t(vector_c));
	number_t macroDef490;array_number_t vector_s = TOP_LEVEL_linalg_vectorRead_s(stgVar486, fn_s, startLine_s, 0, 0);
	macroDef490 = vector_s->arr[0];;
	free(stgVar486);
	return macroDef490;
}
#endif
