#ifndef __LINALG_D_H__ 
#define __LINALG_D_H__ 
#include "../../Runtime/C/fsharp.h"
#include <stdio.h>
#include <math.h>
#include "linalg.h"

card_t TOP_LEVEL_linalg_rows_d(array_array_number_t m, array_array_number_t m_d) {
	card_t macroDef1001 = m->length;
	return macroDef1001;
}

card_t TOP_LEVEL_linalg_cols_d(array_array_number_t m, array_array_number_t m_d) {
	card_t macroDef1002 = m->arr[0]->length;
	return macroDef1002;
}

array_number_t TOP_LEVEL_linalg_vectorMap_d(closure_t f, array_number_t v, closure_t f_d, array_number_t v_d) {
	card_t macroDef1003 = v->length;
	array_number_t macroDef1004 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1004->length=macroDef1003;
	macroDef1004->arr = (number_t*)storage_alloc(sizeof(number_t) * macroDef1003);
		for(int i = 0; i < macroDef1004->length; i++){
			
			macroDef1004->arr[i] = f_d.lam(f_d.env, v->arr[i], v_d->arr[i]).number_t_value;;
		}
	return macroDef1004;
}

array_number_t TOP_LEVEL_linalg_vectorRange_d(card_t s, card_t e, card_t s_d, card_t e_d) {
	array_number_t macroDef1005 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1005->length=((e) - (s)) + (1);
	macroDef1005->arr = (number_t*)storage_alloc(sizeof(number_t) * ((e) - (s)) + (1));
		for(int i = 0; i < macroDef1005->length; i++){
			
			macroDef1005->arr[i] = 0;;
		}
	return macroDef1005;
}

array_number_t TOP_LEVEL_linalg_vectorSlice_d(card_t size, index_t offset, array_number_t v, card_t size_d, index_t offset_d, array_number_t v_d) {
	array_number_t macroDef1006 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1006->length=size;
	macroDef1006->arr = (number_t*)storage_alloc(sizeof(number_t) * size);
		for(int i = 0; i < macroDef1006->length; i++){
			
			macroDef1006->arr[i] = v_d->arr[(i) + (offset)];;
		}
	return macroDef1006;
}

array_array_number_t TOP_LEVEL_linalg_matrixSlice_d(card_t size, index_t offset, array_array_number_t m, card_t size_d, index_t offset_d, array_array_number_t m_d) {
	array_array_number_t macroDef1007 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1007->length=size;
	macroDef1007->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * size);
		for(int i = 0; i < macroDef1007->length; i++){
			
			macroDef1007->arr[i] = m_d->arr[(i) + (offset)];;
		}
	return macroDef1007;
}

array_array_number_t TOP_LEVEL_linalg_matrixMap_d(closure_t f, array_array_number_t m, closure_t f_d, array_array_number_t m_d) {
	card_t macroDef1008 = m->length;
	array_array_number_t macroDef1009 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1009->length=macroDef1008;
	macroDef1009->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * macroDef1008);
		for(int i = 0; i < macroDef1009->length; i++){
			
			macroDef1009->arr[i] = f_d.lam(f_d.env, m->arr[i], m_d->arr[i]).array_number_t_value;;
		}
	return macroDef1009;
}

array_number_t TOP_LEVEL_linalg_matrixMapToVector_d(closure_t f, array_array_number_t m, closure_t f_d, array_array_number_t m_d) {
	card_t macroDef1010 = m->length;
	array_number_t macroDef1011 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1011->length=macroDef1010;
	macroDef1011->arr = (number_t*)storage_alloc(sizeof(number_t) * macroDef1010);
		for(int i = 0; i < macroDef1011->length; i++){
			
			macroDef1011->arr[i] = f_d.lam(f_d.env, m->arr[i], m_d->arr[i]).number_t_value;;
		}
	return macroDef1011;
}

array_number_t TOP_LEVEL_linalg_vectorMap2_d(closure_t f, array_number_t v1, array_number_t v2, closure_t f_d, array_number_t v1_d, array_number_t v2_d) {
	card_t macroDef1012 = v1->length;
	array_number_t macroDef1013 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1013->length=macroDef1012;
	macroDef1013->arr = (number_t*)storage_alloc(sizeof(number_t) * macroDef1012);
		for(int i = 0; i < macroDef1013->length; i++){
			
			macroDef1013->arr[i] = f_d.lam(f_d.env, v1->arr[i], v2->arr[i], v1_d->arr[i], v2_d->arr[i]).number_t_value;;
		}
	return macroDef1013;
}

array_array_number_t TOP_LEVEL_linalg_matrixMap2_d(closure_t f, array_array_number_t m1, array_array_number_t m2, closure_t f_d, array_array_number_t m1_d, array_array_number_t m2_d) {
	card_t macroDef1014 = m1->length;
	array_array_number_t macroDef1015 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1015->length=macroDef1014;
	macroDef1015->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * macroDef1014);
		for(int i = 0; i < macroDef1015->length; i++){
			
			macroDef1015->arr[i] = f_d.lam(f_d.env, m1->arr[i], m2->arr[i], m1_d->arr[i], m2_d->arr[i]).array_number_t_value;;
		}
	return macroDef1015;
}

array_array_array_number_t TOP_LEVEL_linalg_matrix3DMap2_d(closure_t f, array_array_array_number_t m1, array_array_array_number_t m2, closure_t f_d, array_array_array_number_t m1_d, array_array_array_number_t m2_d) {
	card_t macroDef1016 = m1->length;
	array_array_array_number_t macroDef1017 = (array_array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1017->length=macroDef1016;
	macroDef1017->arr = (array_array_number_t*)storage_alloc(sizeof(array_array_number_t) * macroDef1016);
		for(int i = 0; i < macroDef1017->length; i++){
			
			macroDef1017->arr[i] = f_d.lam(f_d.env, m1->arr[i], m2->arr[i], m1_d->arr[i], m2_d->arr[i]).array_array_number_t_value;;
		}
	return macroDef1017;
}

array_array_number_t TOP_LEVEL_linalg_vectorMapToMatrix_d(closure_t f, array_number_t arr, closure_t f_d, array_number_t arr_d) {
	card_t macroDef1018 = arr->length;
	array_array_number_t macroDef1019 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1019->length=macroDef1018;
	macroDef1019->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * macroDef1018);
		for(int i = 0; i < macroDef1019->length; i++){
			
			macroDef1019->arr[i] = f_d.lam(f_d.env, arr->arr[i], arr_d->arr[i]).array_number_t_value;;
		}
	return macroDef1019;
}

array_array_array_number_t TOP_LEVEL_linalg_vectorMapToMatrix3D_d(closure_t f, array_number_t arr, closure_t f_d, array_number_t arr_d) {
	card_t macroDef1020 = arr->length;
	array_array_array_number_t macroDef1021 = (array_array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1021->length=macroDef1020;
	macroDef1021->arr = (array_array_number_t*)storage_alloc(sizeof(array_array_number_t) * macroDef1020);
		for(int i = 0; i < macroDef1021->length; i++){
			
			macroDef1021->arr[i] = f_d.lam(f_d.env, arr->arr[i], arr_d->arr[i]).array_array_number_t_value;;
		}
	return macroDef1021;
}

number_t TOP_LEVEL_linalg_vectorFoldNumber_d(closure_t f, number_t z, array_number_t range, closure_t f_d, number_t z_d, array_number_t range_d) {
	card_t macroDef1024 = range->length;
	card_t l = macroDef1024;
	card_t macroDef1025 = range->length;
	card_t l_d = macroDef1025;
	tuple_number_t_number_t macroDef1026 = pair(z, z_d);
	for(int idx = 0; idx < l; idx++){
		number_t acc = macroDef1026._1;
		number_t acc_d = macroDef1026._2;
		macroDef1026 = pair(f.lam(f.env, acc, range->arr[idx]).number_t_value, f_d.lam(f_d.env, acc, range->arr[idx], acc_d, range_d->arr[idx]).number_t_value);;
	}
	number_t snd1027 = macroDef1026._2;
	return snd1027;
}
typedef empty_env_t env_t_1034;


value_t lambda1034(env_t_1034* env1028, number_t acc, number_t cur) {
	
	value_t res;
	res.number_t_value = (acc) + (cur);
	return res;
}
typedef empty_env_t env_t_1035;


value_t lambda1035(env_t_1035* env1031, number_t acc, number_t cur, number_t acc_d, number_t cur_d) {
	
	value_t res;
	res.number_t_value = (acc_d) + (cur_d);
	return res;
}
number_t TOP_LEVEL_linalg_vectorSum_d(array_number_t v, array_number_t v_d) {
	env_t_1034 env_t_1034_value = make_empty_env(); closure_t closure1030 = make_closure(lambda1034, &env_t_1034_value);
	env_t_1035 env_t_1035_value = make_empty_env(); closure_t closure1033 = make_closure(lambda1035, &env_t_1035_value);
	return TOP_LEVEL_linalg_vectorFoldNumber_d(closure1030, 0, v, closure1033, 0, v_d);
}
typedef empty_env_t env_t_1044;


value_t lambda1044(env_t_1044* env1036, number_t acc, number_t cur) {
	number_t ite1042 = 0;
	if((acc) > (cur)) {
		
		ite1042 = acc;;
	} else {
		
		ite1042 = cur;;
	}
	value_t res;
	res.number_t_value = ite1042;
	return res;
}
typedef empty_env_t env_t_1045;


value_t lambda1045(env_t_1045* env1039, number_t acc, number_t cur, number_t acc_d, number_t cur_d) {
	number_t ite1043 = 0;
	if((acc) > (cur)) {
		
		ite1043 = acc_d;;
	} else {
		
		ite1043 = cur_d;;
	}
	value_t res;
	res.number_t_value = ite1043;
	return res;
}
number_t TOP_LEVEL_linalg_vectorMax_d(array_number_t v, array_number_t v_d) {
	env_t_1044 env_t_1044_value = make_empty_env(); closure_t closure1038 = make_closure(lambda1044, &env_t_1044_value);
	env_t_1045 env_t_1045_value = make_empty_env(); closure_t closure1041 = make_closure(lambda1045, &env_t_1045_value);
	return TOP_LEVEL_linalg_vectorFoldNumber_d(closure1038, -1000, v, closure1041, 0, v_d);
}
typedef struct env_t_1055 {
	number_t y;
} env_t_1055;
env_t_1055 make_env_t_1055(number_t y) {
	env_t_1055 env;
	env.y = y;
	return env;
}

value_t lambda1055(env_t_1055* env1047, number_t xi) {
	number_t y1046 = env1047->y;
	value_t res;
	res.number_t_value = (xi) * (y1046);
	return res;
}
typedef struct env_t_1056 {
	number_t y_d;
	number_t y;
} env_t_1056;
env_t_1056 make_env_t_1056(number_t y_d,number_t y) {
	env_t_1056 env;
	env.y_d = y_d;
	env.y = y;
	return env;
}

value_t lambda1056(env_t_1056* env1052, number_t xi, number_t xi_d) {
	number_t y_d1051 = env1052->y_d;
	number_t y1050 = env1052->y;
	value_t res;
	res.number_t_value = ((xi_d) * (y1050)) + ((xi) * (y_d1051));
	return res;
}
array_number_t TOP_LEVEL_linalg_mult_by_scalar_d(array_number_t x, number_t y, array_number_t x_d, number_t y_d) {
	env_t_1055 env_t_1055_value = make_env_t_1055(y); closure_t closure1049 = make_closure(lambda1055, &env_t_1055_value);
	env_t_1056 env_t_1056_value = make_env_t_1056(y_d,y); closure_t closure1054 = make_closure(lambda1056, &env_t_1056_value);
	return TOP_LEVEL_linalg_vectorMap_d(closure1049, x, closure1054, x_d);
}
typedef struct env_t_1068 {
	number_t y;
	number_t a;
} env_t_1068;
env_t_1068 make_env_t_1068(number_t y,number_t a) {
	env_t_1068 env;
	env.y = y;
	env.a = a;
	return env;
}

value_t lambda1068(env_t_1068* env1059, number_t xi) {
	number_t y1058 = env1059->y;
	number_t a1057 = env1059->a;
	value_t res;
	res.number_t_value = ((a1057) * (xi)) + (y1058);
	return res;
}
typedef struct env_t_1069 {
	number_t y_d;
	number_t a_d;
	number_t a;
} env_t_1069;
env_t_1069 make_env_t_1069(number_t y_d,number_t a_d,number_t a) {
	env_t_1069 env;
	env.y_d = y_d;
	env.a_d = a_d;
	env.a = a;
	return env;
}

value_t lambda1069(env_t_1069* env1065, number_t xi, number_t xi_d) {
	number_t y_d1064 = env1065->y_d;
	number_t a_d1063 = env1065->a_d;
	number_t a1062 = env1065->a;
	value_t res;
	res.number_t_value = (((a_d1063) * (xi)) + ((a1062) * (xi_d))) + (y_d1064);
	return res;
}
array_number_t TOP_LEVEL_linalg_gaxpy_d(number_t a, array_number_t x, number_t y, number_t a_d, array_number_t x_d, number_t y_d) {
	env_t_1068 env_t_1068_value = make_env_t_1068(y,a); closure_t closure1061 = make_closure(lambda1068, &env_t_1068_value);
	env_t_1069 env_t_1069_value = make_env_t_1069(y_d,a_d,a); closure_t closure1067 = make_closure(lambda1069, &env_t_1069_value);
	return TOP_LEVEL_linalg_vectorMap_d(closure1061, x, closure1067, x_d);
}

array_number_t TOP_LEVEL_linalg_cross_d(array_number_t a, array_number_t b, array_number_t a_d, array_number_t b_d) {
	array_number_t array1070 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array1070->length=3;
	array1070->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array1070->arr[0] = (((a_d->arr[1]) * (b->arr[2])) + ((a->arr[1]) * (b_d->arr[2]))) - (((a_d->arr[2]) * (b->arr[1])) + ((a->arr[2]) * (b_d->arr[1])));
	array1070->arr[1] = (((a_d->arr[2]) * (b->arr[0])) + ((a->arr[2]) * (b_d->arr[0]))) - (((a_d->arr[0]) * (b->arr[2])) + ((a->arr[0]) * (b_d->arr[2])));
	array1070->arr[2] = (((a_d->arr[0]) * (b->arr[1])) + ((a->arr[0]) * (b_d->arr[1]))) - (((a_d->arr[1]) * (b->arr[0])) + ((a->arr[1]) * (b_d->arr[0])));;
	return array1070;
}
typedef empty_env_t env_t_1077;


value_t lambda1077(env_t_1077* env1071, number_t x0, number_t y0) {
	
	value_t res;
	res.number_t_value = (x0) + (y0);
	return res;
}
typedef empty_env_t env_t_1078;


value_t lambda1078(env_t_1078* env1074, number_t x0, number_t y0, number_t x_d0, number_t y_d0) {
	
	value_t res;
	res.number_t_value = (x_d0) + (y_d0);
	return res;
}
array_number_t TOP_LEVEL_linalg_vectorAdd_d(array_number_t x, array_number_t y, array_number_t x_d, array_number_t y_d) {
	env_t_1077 env_t_1077_value = make_empty_env(); closure_t closure1073 = make_closure(lambda1077, &env_t_1077_value);
	env_t_1078 env_t_1078_value = make_empty_env(); closure_t closure1076 = make_closure(lambda1078, &env_t_1078_value);
	return TOP_LEVEL_linalg_vectorMap2_d(closure1073, x, y, closure1076, x_d, y_d);
}
typedef empty_env_t env_t_1085;


value_t lambda1085(env_t_1085* env1079, number_t x0, number_t y0) {
	
	value_t res;
	res.number_t_value = (x0) * (y0);
	return res;
}
typedef empty_env_t env_t_1086;


value_t lambda1086(env_t_1086* env1082, number_t x0, number_t y0, number_t x_d0, number_t y_d0) {
	
	value_t res;
	res.number_t_value = ((x_d0) * (y0)) + ((x0) * (y_d0));
	return res;
}
array_number_t TOP_LEVEL_linalg_mult_vec_elementwise_d(array_number_t x, array_number_t y, array_number_t x_d, array_number_t y_d) {
	env_t_1085 env_t_1085_value = make_empty_env(); closure_t closure1081 = make_closure(lambda1085, &env_t_1085_value);
	env_t_1086 env_t_1086_value = make_empty_env(); closure_t closure1084 = make_closure(lambda1086, &env_t_1086_value);
	return TOP_LEVEL_linalg_vectorMap2_d(closure1081, x, y, closure1084, x_d, y_d);
}
typedef empty_env_t env_t_1093;


value_t lambda1093(env_t_1093* env1087, number_t x0, number_t y0) {
	
	value_t res;
	res.number_t_value = (x0) * (y0);
	return res;
}
typedef empty_env_t env_t_1094;


value_t lambda1094(env_t_1094* env1090, number_t x0, number_t y0, number_t x_d0, number_t y_d0) {
	
	value_t res;
	res.number_t_value = ((x_d0) * (y0)) + ((x0) * (y_d0));
	return res;
}
array_number_t TOP_LEVEL_linalg_op_DotMultiply_d(array_number_t x, array_number_t y, array_number_t x_d, array_number_t y_d) {
	env_t_1093 env_t_1093_value = make_empty_env(); closure_t closure1089 = make_closure(lambda1093, &env_t_1093_value);
	env_t_1094 env_t_1094_value = make_empty_env(); closure_t closure1092 = make_closure(lambda1094, &env_t_1094_value);
	return TOP_LEVEL_linalg_vectorMap2_d(closure1089, x, y, closure1092, x_d, y_d);
}

array_number_t TOP_LEVEL_linalg_vectorAdd3_d(array_number_t x, array_number_t y, array_number_t z, array_number_t x_d, array_number_t y_d, array_number_t z_d) {
	
	return TOP_LEVEL_linalg_vectorAdd_d(TOP_LEVEL_linalg_vectorAdd(x, y), z, TOP_LEVEL_linalg_vectorAdd_d(x, y, x_d, y_d), z_d);
}
typedef empty_env_t env_t_1101;


value_t lambda1101(env_t_1101* env1095, number_t x0, number_t y0) {
	
	value_t res;
	res.number_t_value = (x0) - (y0);
	return res;
}
typedef empty_env_t env_t_1102;


value_t lambda1102(env_t_1102* env1098, number_t x0, number_t y0, number_t x_d0, number_t y_d0) {
	
	value_t res;
	res.number_t_value = (x_d0) - (y_d0);
	return res;
}
array_number_t TOP_LEVEL_linalg_vectorSub_d(array_number_t x, array_number_t y, array_number_t x_d, array_number_t y_d) {
	env_t_1101 env_t_1101_value = make_empty_env(); closure_t closure1097 = make_closure(lambda1101, &env_t_1101_value);
	env_t_1102 env_t_1102_value = make_empty_env(); closure_t closure1100 = make_closure(lambda1102, &env_t_1102_value);
	return TOP_LEVEL_linalg_vectorMap2_d(closure1097, x, y, closure1100, x_d, y_d);
}
typedef empty_env_t env_t_1109;


value_t lambda1109(env_t_1109* env1103, array_number_t x0, array_number_t y0) {
	
	value_t res;
	res.array_number_t_value = TOP_LEVEL_linalg_vectorAdd(x0, y0);
	return res;
}
typedef empty_env_t env_t_1110;


value_t lambda1110(env_t_1110* env1106, array_number_t x0, array_number_t y0, array_number_t x_d0, array_number_t y_d0) {
	
	value_t res;
	res.array_number_t_value = TOP_LEVEL_linalg_vectorAdd_d(x0, y0, x_d0, y_d0);
	return res;
}
array_array_number_t TOP_LEVEL_linalg_matrixAdd_d(array_array_number_t x, array_array_number_t y, array_array_number_t x_d, array_array_number_t y_d) {
	env_t_1109 env_t_1109_value = make_empty_env(); closure_t closure1105 = make_closure(lambda1109, &env_t_1109_value);
	env_t_1110 env_t_1110_value = make_empty_env(); closure_t closure1108 = make_closure(lambda1110, &env_t_1110_value);
	return TOP_LEVEL_linalg_matrixMap2_d(closure1105, x, y, closure1108, x_d, y_d);
}
typedef empty_env_t env_t_1117;


value_t lambda1117(env_t_1117* env1111, array_number_t x0, array_number_t y0) {
	
	value_t res;
	res.array_number_t_value = TOP_LEVEL_linalg_mult_vec_elementwise(x0, y0);
	return res;
}
typedef empty_env_t env_t_1118;


value_t lambda1118(env_t_1118* env1114, array_number_t x0, array_number_t y0, array_number_t x_d0, array_number_t y_d0) {
	
	value_t res;
	res.array_number_t_value = TOP_LEVEL_linalg_mult_vec_elementwise_d(x0, y0, x_d0, y_d0);
	return res;
}
array_array_number_t TOP_LEVEL_linalg_matrixMultElementwise_d(array_array_number_t x, array_array_number_t y, array_array_number_t x_d, array_array_number_t y_d) {
	env_t_1117 env_t_1117_value = make_empty_env(); closure_t closure1113 = make_closure(lambda1117, &env_t_1117_value);
	env_t_1118 env_t_1118_value = make_empty_env(); closure_t closure1116 = make_closure(lambda1118, &env_t_1118_value);
	return TOP_LEVEL_linalg_matrixMap2_d(closure1113, x, y, closure1116, x_d, y_d);
}
typedef empty_env_t env_t_1128;


value_t lambda1128(env_t_1128* env1119, number_t x1) {
	
	value_t res;
	res.number_t_value = (x1) * (x1);
	return res;
}
typedef empty_env_t env_t_1129;


value_t lambda1129(env_t_1129* env1122, number_t x1) {
	
	value_t res;
	res.number_t_value = (x1) * (x1);
	return res;
}
typedef empty_env_t env_t_1130;


value_t lambda1130(env_t_1130* env1125, number_t x1, number_t x1_d) {
	
	value_t res;
	res.number_t_value = ((x1_d) * (x1)) + ((x1) * (x1_d));
	return res;
}
number_t TOP_LEVEL_linalg_sqnorm_d(array_number_t x, array_number_t x_d) {
	env_t_1128 env_t_1128_value = make_empty_env(); closure_t closure1121 = make_closure(lambda1128, &env_t_1128_value);
	env_t_1129 env_t_1129_value = make_empty_env(); closure_t closure1124 = make_closure(lambda1129, &env_t_1129_value);
	env_t_1130 env_t_1130_value = make_empty_env(); closure_t closure1127 = make_closure(lambda1130, &env_t_1130_value);
	return TOP_LEVEL_linalg_vectorSum_d(TOP_LEVEL_linalg_vectorMap(closure1121, x), TOP_LEVEL_linalg_vectorMap_d(closure1124, x, closure1127, x_d));
}
typedef empty_env_t env_t_1140;


value_t lambda1140(env_t_1140* env1131, number_t x0, number_t y0) {
	
	value_t res;
	res.number_t_value = (x0) * (y0);
	return res;
}
typedef empty_env_t env_t_1141;


value_t lambda1141(env_t_1141* env1134, number_t x0, number_t y0) {
	
	value_t res;
	res.number_t_value = (x0) * (y0);
	return res;
}
typedef empty_env_t env_t_1142;


value_t lambda1142(env_t_1142* env1137, number_t x0, number_t y0, number_t x_d0, number_t y_d0) {
	
	value_t res;
	res.number_t_value = ((x_d0) * (y0)) + ((x0) * (y_d0));
	return res;
}
number_t TOP_LEVEL_linalg_dot_prod_d(array_number_t x, array_number_t y, array_number_t x_d, array_number_t y_d) {
	env_t_1140 env_t_1140_value = make_empty_env(); closure_t closure1133 = make_closure(lambda1140, &env_t_1140_value);
	env_t_1141 env_t_1141_value = make_empty_env(); closure_t closure1136 = make_closure(lambda1141, &env_t_1141_value);
	env_t_1142 env_t_1142_value = make_empty_env(); closure_t closure1139 = make_closure(lambda1142, &env_t_1142_value);
	return TOP_LEVEL_linalg_vectorSum_d(TOP_LEVEL_linalg_vectorMap2(closure1133, x, y), TOP_LEVEL_linalg_vectorMap2_d(closure1136, x, y, closure1139, x_d, y_d));
}
typedef struct env_t_1151 {
	array_number_t row;
} env_t_1151;
env_t_1151 make_env_t_1151(array_number_t row) {
	env_t_1151 env;
	env.row = row;
	return env;
}

value_t lambda1151(env_t_1151* env1144, number_t r) {
	array_number_t row1143 = env1144->row;
	value_t res;
	res.array_number_t_value = row1143;
	return res;
}
typedef struct env_t_1152 {
	array_number_t row_d;
} env_t_1152;
env_t_1152 make_env_t_1152(array_number_t row_d) {
	env_t_1152 env;
	env.row_d = row_d;
	return env;
}

value_t lambda1152(env_t_1152* env1148, number_t r, number_t r_d) {
	array_number_t row_d1147 = env1148->row_d;
	value_t res;
	res.array_number_t_value = row_d1147;
	return res;
}
array_array_number_t TOP_LEVEL_linalg_matrixFillFromVector_d(card_t rows, array_number_t row, card_t rows_d, array_number_t row_d) {
	env_t_1151 env_t_1151_value = make_env_t_1151(row); closure_t closure1146 = make_closure(lambda1151, &env_t_1151_value);
	env_t_1152 env_t_1152_value = make_env_t_1152(row_d); closure_t closure1150 = make_closure(lambda1152, &env_t_1152_value);
	return TOP_LEVEL_linalg_vectorMapToMatrix_d(closure1146, TOP_LEVEL_linalg_vectorRange(1, rows), closure1150, TOP_LEVEL_linalg_vectorRange_d(1, rows, 1, rows));
}

array_array_number_t TOP_LEVEL_linalg_matrixFill_d(card_t rows, card_t cols, number_t value, card_t rows_d, card_t cols_d, number_t value_d) {
	array_array_number_t macroDef1154 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1154->length=rows;
	macroDef1154->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * rows);
		for(int r = 0; r < macroDef1154->length; r++){
			array_number_t macroDef1153 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1153->length=cols;
	macroDef1153->arr = (number_t*)storage_alloc(sizeof(number_t) * cols);
		for(int c = 0; c < macroDef1153->length; c++){
			
			macroDef1153->arr[c] = value_d;;
		}
			macroDef1154->arr[r] = macroDef1153;;
		}
	return macroDef1154;
}

array_array_number_t TOP_LEVEL_linalg_matrixTranspose_d(array_array_number_t m, array_array_number_t m_d) {
	card_t macroDef1155 = m->length;
	card_t rows = macroDef1155;
	card_t macroDef1156 = m->length;
	card_t rows_d = macroDef1156;
	card_t macroDef1157 = m->arr[0]->length;
	card_t cols = macroDef1157;
	card_t macroDef1158 = m->arr[0]->length;
	card_t cols_d = macroDef1158;
	array_array_number_t macroDef1160 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1160->length=cols;
	macroDef1160->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * cols);
		for(int i = 0; i < macroDef1160->length; i++){
			array_number_t macroDef1159 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1159->length=rows;
	macroDef1159->arr = (number_t*)storage_alloc(sizeof(number_t) * rows);
		for(int j = 0; j < macroDef1159->length; j++){
			
			macroDef1159->arr[j] = m_d->arr[j]->arr[i];;
		}
			macroDef1160->arr[i] = macroDef1159;;
		}
	return macroDef1160;
}

array_array_number_t TOP_LEVEL_linalg_matrixMult_d(array_array_number_t m1, array_array_number_t m2, array_array_number_t m1_d, array_array_number_t m2_d) {
	card_t macroDef1161 = m1->length;
	card_t r1 = macroDef1161;
	card_t macroDef1162 = m1->length;
	card_t r1_d = macroDef1162;
	card_t macroDef1163 = m2->arr[0]->length;
	card_t c2 = macroDef1163;
	card_t macroDef1164 = m2->arr[0]->length;
	card_t c2_d = macroDef1164;
	card_t macroDef1165 = m1->arr[0]->length;
	card_t c1 = macroDef1165;
	card_t macroDef1166 = m1->arr[0]->length;
	card_t c1_d = macroDef1166;
	card_t macroDef1167 = m2->length;
	card_t r2 = macroDef1167;
	card_t macroDef1168 = m2->length;
	card_t r2_d = macroDef1168;
	array_array_number_t m2T = TOP_LEVEL_linalg_matrixTranspose(m2);
	array_array_number_t m2T_d = TOP_LEVEL_linalg_matrixTranspose_d(m2, m2_d);
	array_array_number_t macroDef1170 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1170->length=r1;
	macroDef1170->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * r1);
		for(int r = 0; r < macroDef1170->length; r++){
			array_number_t macroDef1169 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1169->length=c2;
	macroDef1169->arr = (number_t*)storage_alloc(sizeof(number_t) * c2);
		for(int c = 0; c < macroDef1169->length; c++){
			
			macroDef1169->arr[c] = TOP_LEVEL_linalg_dot_prod_d(m1->arr[r], m2T->arr[c], m1_d->arr[r], m2T_d->arr[c]);;
		}
			macroDef1170->arr[r] = macroDef1169;;
		}
	return macroDef1170;
}

array_number_t TOP_LEVEL_linalg_matrixVectorMult_d(array_array_number_t m, array_number_t v, array_array_number_t m_d, array_number_t v_d) {
	card_t r = TOP_LEVEL_linalg_rows(m);
	card_t r_d = TOP_LEVEL_linalg_rows(m);
	card_t c = TOP_LEVEL_linalg_cols(m);
	card_t c_d = TOP_LEVEL_linalg_cols(m);
	array_number_t macroDef1171 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1171->length=r;
	macroDef1171->arr = (number_t*)storage_alloc(sizeof(number_t) * r);
		for(int i = 0; i < macroDef1171->length; i++){
			
			macroDef1171->arr[i] = TOP_LEVEL_linalg_dot_prod_d(m->arr[i], v, m_d->arr[i], v_d);;
		}
	return macroDef1171;
}

array_array_number_t TOP_LEVEL_linalg_matrixConcat_d(array_array_number_t m1, array_array_number_t m2, array_array_number_t m1_d, array_array_number_t m2_d) {
	card_t macroDef1172 = m1->length;
	card_t macroDef1173 = m2->length;
	card_t rows = (macroDef1172) + (macroDef1173);
	card_t macroDef1174 = m1->length;
	card_t macroDef1175 = m2->length;
	card_t rows_d = (macroDef1174) + (macroDef1175);
	card_t macroDef1176 = m1->length;
	index_t m1Rows = (macroDef1176);
	card_t macroDef1177 = m1->length;
	index_t m1Rows_d = (macroDef1177);
	array_array_number_t macroDef1178 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1178->length=rows;
	macroDef1178->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * rows);
		for(int r = 0; r < macroDef1178->length; r++){
			array_number_t ite1179 ;
	if((r) < (m1Rows)) {
		
		ite1179 = m1_d->arr[r];;
	} else {
		
		ite1179 = m2_d->arr[(r) - (m1Rows)];;
	}
			macroDef1178->arr[r] = ite1179;;
		}
	return macroDef1178;
}

array_array_number_t TOP_LEVEL_linalg_matrixConcatCol_d(array_array_number_t m1, array_array_number_t m2, array_array_number_t m1_d, array_array_number_t m2_d) {
	array_array_number_t m1t = TOP_LEVEL_linalg_matrixTranspose(m1);
	array_array_number_t m1t_d = TOP_LEVEL_linalg_matrixTranspose_d(m1, m1_d);
	array_array_number_t m2t = TOP_LEVEL_linalg_matrixTranspose(m2);
	array_array_number_t m2t_d = TOP_LEVEL_linalg_matrixTranspose_d(m2, m2_d);
	return TOP_LEVEL_linalg_matrixTranspose_d(TOP_LEVEL_linalg_matrixConcat(m1t, m2t), TOP_LEVEL_linalg_matrixConcat_d(m1t, m2t, m1t_d, m2t_d));
}

array_array_array_number_t TOP_LEVEL_linalg_matrix3DConcat_d(array_array_array_number_t m1, array_array_array_number_t m2, array_array_array_number_t m1_d, array_array_array_number_t m2_d) {
	card_t macroDef1180 = m1->length;
	card_t macroDef1181 = m2->length;
	card_t rows = (macroDef1180) + (macroDef1181);
	card_t macroDef1182 = m1->length;
	card_t macroDef1183 = m2->length;
	card_t rows_d = (macroDef1182) + (macroDef1183);
	card_t macroDef1184 = m1->length;
	index_t m1Rows = (macroDef1184);
	card_t macroDef1185 = m1->length;
	index_t m1Rows_d = (macroDef1185);
	array_array_array_number_t macroDef1186 = (array_array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1186->length=rows;
	macroDef1186->arr = (array_array_number_t*)storage_alloc(sizeof(array_array_number_t) * rows);
		for(int r = 0; r < macroDef1186->length; r++){
			array_array_number_t ite1187 ;
	if((r) < (m1Rows)) {
		
		ite1187 = m1_d->arr[r];;
	} else {
		
		ite1187 = m2_d->arr[(r) - (m1Rows)];;
	}
			macroDef1186->arr[r] = ite1187;;
		}
	return macroDef1186;
}

array_number_t TOP_LEVEL_linalg_vectorRead_d(string_t fn, index_t startLine, card_t cols, string_t fn_d, index_t startLine_d, card_t cols_d) {
	array_array_number_t matrix = matrix_read(fn, startLine, 1, cols);
	array_array_number_t matrix_d = matrix_read(fn, startLine, 1, cols);
	return matrix_d->arr[0];
}

number_t TOP_LEVEL_linalg_numberRead_d(string_t fn, index_t startLine, string_t fn_d, index_t startLine_d) {
	array_number_t vector = TOP_LEVEL_linalg_vectorRead(fn, startLine, 1);
	array_number_t vector_d = TOP_LEVEL_linalg_vectorRead_d(fn, startLine, 1, "", 0, 1);
	return vector_d->arr[0];
}

array_number_t TOP_LEVEL_linalg_vec3_d(number_t a, number_t b, number_t c, number_t a_d, number_t b_d, number_t c_d) {
	array_number_t array1188 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array1188->length=3;
	array1188->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array1188->arr[0] = a_d;
	array1188->arr[1] = b_d;
	array1188->arr[2] = c_d;;
	return array1188;
}
#endif
