#ifndef __LINALG_H__ 
#define __LINALG_H__ 
#include "runtime/fsharp.h"
#include <stdio.h>
#include <math.h>
typedef struct env_t_9 {
	array_number_t v;
	closure_t f;
} env_t_9;
env_t_9 make_env_t_9(array_number_t v,closure_t f) {
	env_t_9 env;
	env.v = v;
	env.f = f;
	return env;
}

value_t lambda9(env_t_9* env5, index_t i) {
	array_number_t v4 = env5->v;
	closure_t f3 = env5->f;
	value_t res;
	res.number_t_value = f3.lam(f3.env, v4->arr[i]).number_t_value;
	return res;
}
array_number_t linalg_vectorMap(closure_t f, array_number_t v) {
	card_t macroDef1 = v->length;
	env_t_9 env_t_9_value = make_env_t_9(v,f); closure_t closure7 = make_closure(lambda9, &env_t_9_value);
	return vector_build(macroDef1, closure7);
}
typedef struct env_t_20 {
	card_t s;
} env_t_20;
env_t_20 make_env_t_20(card_t s) {
	env_t_20 env;
	env.s = s;
	return env;
}

value_t lambda20(env_t_20* env16, index_t i) {
	card_t s15 = env16->s;
	value_t res;
	res.number_t_value = (double)(((s15)) + (i));
	return res;
}
array_number_t linalg_vectorRange(card_t s, card_t e) {
	env_t_20 env_t_20_value = make_env_t_20(s); closure_t closure18 = make_closure(lambda20, &env_t_20_value);
	return vector_build(((e) - (s)) + (1), closure18);
}
typedef struct env_t_29 {
	array_array_number_t m;
	closure_t f;
} env_t_29;
env_t_29 make_env_t_29(array_array_number_t m,closure_t f) {
	env_t_29 env;
	env.m = m;
	env.f = f;
	return env;
}

value_t lambda29(env_t_29* env25, index_t i) {
	array_array_number_t m24 = env25->m;
	closure_t f23 = env25->f;
	value_t res;
	res.array_number_t_value = f23.lam(f23.env, m24->arr[i]).array_number_t_value;
	return res;
}
array_array_number_t linalg_matrixMap(closure_t f, array_array_number_t m) {
	card_t macroDef21 = m->length;
	env_t_29 env_t_29_value = make_env_t_29(m,f); closure_t closure27 = make_closure(lambda29, &env_t_29_value);
	return matrix_build(macroDef21, closure27);
}
typedef struct env_t_40 {
	array_number_t v2;
	array_number_t v1;
	closure_t f;
} env_t_40;
env_t_40 make_env_t_40(array_number_t v2,array_number_t v1,closure_t f) {
	env_t_40 env;
	env.v2 = v2;
	env.v1 = v1;
	env.f = f;
	return env;
}

value_t lambda40(env_t_40* env36, index_t i) {
	array_number_t v235 = env36->v2;
	array_number_t v134 = env36->v1;
	closure_t f33 = env36->f;
	value_t res;
	res.number_t_value = f33.lam(f33.env, v134->arr[i], v235->arr[i]).number_t_value;
	return res;
}
array_number_t linalg_vectorMap2(closure_t f, array_number_t v1, array_number_t v2) {
	card_t macroDef30 = v1->length;
	env_t_40 env_t_40_value = make_env_t_40(v2,v1,f); closure_t closure38 = make_closure(lambda40, &env_t_40_value);
	return vector_build(macroDef30, closure38);
}
typedef struct env_t_51 {
	array_array_number_t m2;
	array_array_number_t m1;
	closure_t f;
} env_t_51;
env_t_51 make_env_t_51(array_array_number_t m2,array_array_number_t m1,closure_t f) {
	env_t_51 env;
	env.m2 = m2;
	env.m1 = m1;
	env.f = f;
	return env;
}

value_t lambda51(env_t_51* env47, index_t i) {
	array_array_number_t m246 = env47->m2;
	array_array_number_t m145 = env47->m1;
	closure_t f44 = env47->f;
	value_t res;
	res.array_number_t_value = f44.lam(f44.env, m145->arr[i], m246->arr[i]).array_number_t_value;
	return res;
}
array_array_number_t linalg_matrixMap2(closure_t f, array_array_number_t m1, array_array_number_t m2) {
	card_t macroDef41 = m1->length;
	env_t_51 env_t_51_value = make_env_t_51(m2,m1,f); closure_t closure49 = make_closure(lambda51, &env_t_51_value);
	return matrix_build(macroDef41, closure49);
}
typedef struct env_t_62 {
	array_array_array_number_t m2;
	array_array_array_number_t m1;
	closure_t f;
} env_t_62;
env_t_62 make_env_t_62(array_array_array_number_t m2,array_array_array_number_t m1,closure_t f) {
	env_t_62 env;
	env.m2 = m2;
	env.m1 = m1;
	env.f = f;
	return env;
}

value_t lambda62(env_t_62* env58, index_t i) {
	array_array_array_number_t m257 = env58->m2;
	array_array_array_number_t m156 = env58->m1;
	closure_t f55 = env58->f;
	value_t res;
	res.array_array_number_t_value = f55.lam(f55.env, m156->arr[i], m257->arr[i]).array_array_number_t_value;
	return res;
}
array_array_array_number_t linalg_matrix3DMap2(closure_t f, array_array_array_number_t m1, array_array_array_number_t m2) {
	card_t macroDef52 = m1->length;
	env_t_62 env_t_62_value = make_env_t_62(m2,m1,f); closure_t closure60 = make_closure(lambda62, &env_t_62_value);
	return matrix3d_build(macroDef52, closure60);
}
typedef struct env_t_71 {
	closure_t f;
	array_number_t arr;
} env_t_71;
env_t_71 make_env_t_71(closure_t f,array_number_t arr) {
	env_t_71 env;
	env.f = f;
	env.arr = arr;
	return env;
}

value_t lambda71(env_t_71* env67, index_t i) {
	closure_t f66 = env67->f;
	array_number_t arr65 = env67->arr;
	value_t res;
	res.array_number_t_value = f66.lam(f66.env, arr65->arr[i]).array_number_t_value;
	return res;
}
array_array_number_t linalg_vectorMapToMatrix(closure_t f, array_number_t arr) {
	card_t macroDef63 = arr->length;
	env_t_71 env_t_71_value = make_env_t_71(f,arr); closure_t closure69 = make_closure(lambda71, &env_t_71_value);
	return matrix_build(macroDef63, closure69);
}
typedef struct env_t_80 {
	closure_t f;
	array_number_t arr;
} env_t_80;
env_t_80 make_env_t_80(closure_t f,array_number_t arr) {
	env_t_80 env;
	env.f = f;
	env.arr = arr;
	return env;
}

value_t lambda80(env_t_80* env76, index_t i) {
	closure_t f75 = env76->f;
	array_number_t arr74 = env76->arr;
	value_t res;
	res.array_array_number_t_value = f75.lam(f75.env, arr74->arr[i]).array_array_number_t_value;
	return res;
}
array_array_array_number_t linalg_vectorMapToMatrix3D(closure_t f, array_number_t arr) {
	card_t macroDef72 = arr->length;
	env_t_80 env_t_80_value = make_env_t_80(f,arr); closure_t closure78 = make_closure(lambda80, &env_t_80_value);
	return matrix3d_build(macroDef72, closure78);
}
typedef struct env_t_88 {
	closure_t f;
} env_t_88;
env_t_88 make_env_t_88(closure_t f) {
	env_t_88 env;
	env.f = f;
	return env;
}

value_t lambda88(env_t_88* env83, number_t acc, number_t cur) {
	closure_t f82 = env83->f;
	value_t res;
	res.number_t_value = f82.lam(f82.env, acc, (int)(cur)).number_t_value;
	return res;
}
number_t linalg_iterateNumber(closure_t f, number_t z, card_t s, card_t e) {
	env_t_88 env_t_88_value = make_env_t_88(f); closure_t closure85 = make_closure(lambda88, &env_t_88_value);
	return vector_fold_number(closure85, z, linalg_vectorRange(s, e));
}
typedef struct env_t_96 {
	closure_t f;
} env_t_96;
env_t_96 make_env_t_96(closure_t f) {
	env_t_96 env;
	env.f = f;
	return env;
}

value_t lambda96(env_t_96* env91, array_number_t acc, number_t cur) {
	closure_t f90 = env91->f;
	value_t res;
	res.array_number_t_value = f90.lam(f90.env, acc, (int)(cur)).array_number_t_value;
	return res;
}
array_number_t linalg_iterateVector(closure_t f, array_number_t z, card_t s, card_t e) {
	env_t_96 env_t_96_value = make_env_t_96(f); closure_t closure93 = make_closure(lambda96, &env_t_96_value);
	return vector_fold_vector(closure93, z, linalg_vectorRange(s, e));
}
typedef struct env_t_104 {
	closure_t f;
} env_t_104;
env_t_104 make_env_t_104(closure_t f) {
	env_t_104 env;
	env.f = f;
	return env;
}

value_t lambda104(env_t_104* env99, array_array_number_t acc, number_t cur) {
	closure_t f98 = env99->f;
	value_t res;
	res.array_array_number_t_value = f98.lam(f98.env, acc, (int)(cur)).array_array_number_t_value;
	return res;
}
array_array_number_t linalg_iterateMatrix(closure_t f, array_array_number_t z, card_t s, card_t e) {
	env_t_104 env_t_104_value = make_env_t_104(f); closure_t closure101 = make_closure(lambda104, &env_t_104_value);
	return vector_fold_matrix(closure101, z, linalg_vectorRange(s, e));
}
typedef struct env_t_112 {
	closure_t f;
} env_t_112;
env_t_112 make_env_t_112(closure_t f) {
	env_t_112 env;
	env.f = f;
	return env;
}

value_t lambda112(env_t_112* env107, array_array_array_number_t acc, number_t cur) {
	closure_t f106 = env107->f;
	value_t res;
	res.array_array_array_number_t_value = f106.lam(f106.env, acc, (int)(cur)).array_array_array_number_t_value;
	return res;
}
array_array_array_number_t linalg_iterateMatrix3D(closure_t f, array_array_array_number_t z, card_t s, card_t e) {
	env_t_112 env_t_112_value = make_env_t_112(f); closure_t closure109 = make_closure(lambda112, &env_t_112_value);
	return vector_fold_matrix3d(closure109, z, linalg_vectorRange(s, e));
}
typedef empty_env_t env_t_118;


value_t lambda118(env_t_118* env114, number_t acc, number_t cur) {
	
	value_t res;
	res.number_t_value = (acc) + (cur);
	return res;
}
number_t linalg_arraySum(array_number_t arr) {
	env_t_118 env_t_118_value = make_empty_env(); closure_t closure116 = make_closure(lambda118, &env_t_118_value);
	return vector_fold_number(closure116, 0, arr);
}
typedef empty_env_t env_t_125;


value_t lambda125(env_t_125* env120, number_t acc, number_t cur) {
	number_t ite124 = 0;
	if((acc) > (cur)) {
		
		ite124 = acc;
	} else {
		
		ite124 = cur;
	}
	value_t res;
	res.number_t_value = ite124;
	return res;
}
number_t linalg_arrayMax(array_number_t arr) {
	env_t_125 env_t_125_value = make_empty_env(); closure_t closure122 = make_closure(lambda125, &env_t_125_value);
	return vector_fold_number(closure122, -1000, arr);
}
typedef struct env_t_132 {
	number_t y;
} env_t_132;
env_t_132 make_env_t_132(number_t y) {
	env_t_132 env;
	env.y = y;
	return env;
}

value_t lambda132(env_t_132* env128, number_t a) {
	number_t y127 = env128->y;
	value_t res;
	res.number_t_value = (a) * (y127);
	return res;
}
array_number_t linalg_mult_by_scalar(array_number_t x, number_t y) {
	env_t_132 env_t_132_value = make_env_t_132(y); closure_t closure130 = make_closure(lambda132, &env_t_132_value);
	return linalg_vectorMap(closure130, x);
}

array_number_t linalg_cross(array_number_t a, array_number_t b) {
	array_number_t array154 = (array_number_t)malloc(sizeof(int) * 2);
	array154->length=3;
	array154->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array154->arr[0] = ((a->arr[1]) * (b->arr[2])) - ((a->arr[2]) * (b->arr[1]));
	array154->arr[1] = ((a->arr[2]) * (b->arr[0])) - ((a->arr[0]) * (b->arr[2]));
	array154->arr[2] = ((a->arr[0]) * (b->arr[1])) - ((a->arr[1]) * (b->arr[0]));;
	return array154;
}
typedef empty_env_t env_t_160;


value_t lambda160(env_t_160* env156, number_t x, number_t y) {
	
	value_t res;
	res.number_t_value = (x) + (y);
	return res;
}
array_number_t linalg_add_vec(array_number_t x, array_number_t y) {
	env_t_160 env_t_160_value = make_empty_env(); closure_t closure158 = make_closure(lambda160, &env_t_160_value);
	return linalg_vectorMap2(closure158, x, y);
}
typedef empty_env_t env_t_166;


value_t lambda166(env_t_166* env162, number_t x, number_t y) {
	
	value_t res;
	res.number_t_value = (x) * (y);
	return res;
}
array_number_t linalg_mult_vec_elementwise(array_number_t x, array_number_t y) {
	env_t_166 env_t_166_value = make_empty_env(); closure_t closure164 = make_closure(lambda166, &env_t_166_value);
	return linalg_vectorMap2(closure164, x, y);
}

array_number_t linalg_add_vec3(array_number_t x, array_number_t y, array_number_t z) {
	
	return linalg_add_vec(linalg_add_vec(x, y), z);
}
typedef empty_env_t env_t_174;


value_t lambda174(env_t_174* env170, number_t x, number_t y) {
	
	value_t res;
	res.number_t_value = (x) - (y);
	return res;
}
array_number_t linalg_sub_vec(array_number_t x, array_number_t y) {
	env_t_174 env_t_174_value = make_empty_env(); closure_t closure172 = make_closure(lambda174, &env_t_174_value);
	return linalg_vectorMap2(closure172, x, y);
}
typedef empty_env_t env_t_180;


value_t lambda180(env_t_180* env176, array_number_t x, array_number_t y) {
	
	value_t res;
	res.array_number_t_value = linalg_add_vec(x, y);
	return res;
}
array_array_number_t linalg_matrixAdd(array_array_number_t x, array_array_number_t y) {
	env_t_180 env_t_180_value = make_empty_env(); closure_t closure178 = make_closure(lambda180, &env_t_180_value);
	return linalg_matrixMap2(closure178, x, y);
}
typedef empty_env_t env_t_186;


value_t lambda186(env_t_186* env182, array_number_t x, array_number_t y) {
	
	value_t res;
	res.array_number_t_value = linalg_mult_vec_elementwise(x, y);
	return res;
}
array_array_number_t linalg_matrixMultElementwise(array_array_number_t x, array_array_number_t y) {
	env_t_186 env_t_186_value = make_empty_env(); closure_t closure184 = make_closure(lambda186, &env_t_186_value);
	return linalg_matrixMap2(closure184, x, y);
}
typedef empty_env_t env_t_193;


value_t lambda193(env_t_193* env188, number_t x1) {
	
	value_t res;
	res.number_t_value = (x1) * (x1);
	return res;
}
number_t linalg_sqnorm(array_number_t x) {
	env_t_193 env_t_193_value = make_empty_env(); closure_t closure190 = make_closure(lambda193, &env_t_193_value);
	return linalg_arraySum(linalg_vectorMap(closure190, x));
}
typedef empty_env_t env_t_200;


value_t lambda200(env_t_200* env195, number_t x, number_t y) {
	
	value_t res;
	res.number_t_value = (x) * (y);
	return res;
}
number_t linalg_dot_prod(array_number_t x, array_number_t y) {
	env_t_200 env_t_200_value = make_empty_env(); closure_t closure197 = make_closure(lambda200, &env_t_200_value);
	return linalg_arraySum(linalg_vectorMap2(closure197, x, y));
}
typedef struct env_t_207 {
	array_number_t row;
} env_t_207;
env_t_207 make_env_t_207(array_number_t row) {
	env_t_207 env;
	env.row = row;
	return env;
}

value_t lambda207(env_t_207* env202, number_t r) {
	array_number_t row201 = env202->row;
	value_t res;
	res.array_number_t_value = row201;
	return res;
}
array_array_number_t linalg_matrixFillFromVector(card_t rows, array_number_t row) {
	env_t_207 env_t_207_value = make_env_t_207(row); closure_t closure204 = make_closure(lambda207, &env_t_207_value);
	return linalg_vectorMapToMatrix(closure204, linalg_vectorRange(1, rows));
}
typedef struct env_t_215 {
	number_t value;
} env_t_215;
env_t_215 make_env_t_215(number_t value) {
	env_t_215 env;
	env.value = value;
	return env;
}

value_t lambda215(env_t_215* env209, number_t c) {
	number_t value208 = env209->value;
	value_t res;
	res.number_t_value = value208;
	return res;
}
array_array_number_t linalg_matrixFill(card_t rows, card_t cols, number_t value) {
	env_t_215 env_t_215_value = make_env_t_215(value); closure_t closure211 = make_closure(lambda215, &env_t_215_value);
	array_number_t row = linalg_vectorMap(closure211, linalg_vectorRange(1, cols));
	return linalg_matrixFillFromVector(rows, row);
}

array_array_number_t linalg_matrixConcatCol(array_array_number_t m1, array_array_number_t m2) {
	array_array_number_t m1t = matrix_transpose(m1);
	array_array_number_t m2t = matrix_transpose(m2);
	return matrix_transpose(matrix_concat(m1t, m2t));
}

array_number_t linalg_vectorRead(string_t fn, index_t startLine) {
	array_array_number_t matrix = matrix_read(fn, startLine, 1);
	return matrix->arr[0];
}

number_t linalg_numberRead(string_t fn, index_t startLine) {
	array_number_t vector = linalg_vectorRead(fn, startLine);
	return vector->arr[0];
}

array_number_t linalg_vectorMap2GivenStorage(storage_t storage, closure_t f, array_number_t v1, array_number_t v2) {
	array_number_t macroDef226 = (array_number_t)storage;
		for(int i = 0; i < macroDef226->length; i++){
			
			macroDef226->arr[i] = f.lam(f.env, v1->arr[i], v2->arr[i]).number_t_value;
		}
	return macroDef226;
}
typedef empty_env_t env_t_232;


value_t lambda232(env_t_232* env228, number_t x, number_t y) {
	
	value_t res;
	res.number_t_value = (x) + (y);
	return res;
}
array_number_t linalg_add_vecGivenStorage(storage_t s, array_number_t x, array_number_t y) {
	env_t_232 env_t_232_value = make_empty_env(); closure_t closure230 = make_closure(lambda232, &env_t_232_value);
	return linalg_vectorMap2GivenStorage(s, closure230, x, y);
}
#endif
