#ifndef __LINALG_H__ 
#define __LINALG_H__ 
#include "runtime/fsharp.h"
#include <stdio.h>
#include <math.h>
typedef struct env_t_8 {
	array_number_t v;
	closure_t f;
} env_t_8;
env_t_8 make_env_t_8(array_number_t v,closure_t f) {
	env_t_8 env;
	env.v = v;
	env.f = f;
	return env;
}

value_t lambda8(env_t_8* env4, index_t i) {
	array_number_t v3 = env4->v;
	closure_t f2 = env4->f;
	value_t res;
	res.number_t_value = f2.lam(f2.env, v3->arr[i]).number_t_value;
	return res;
}
array_number_t linalg_vectorMap(closure_t f, array_number_t v) {
	env_t_8 env_t_8_value = make_env_t_8(v,f); closure_t closure6 = make_closure(lambda8, &env_t_8_value);
	return vector_build(v->length, closure6);
}
typedef struct env_t_18 {
	index_t s;
} env_t_18;
env_t_18 make_env_t_18(index_t s) {
	env_t_18 env;
	env.s = s;
	return env;
}

value_t lambda18(env_t_18* env14, index_t i) {
	index_t s13 = env14->s;
	value_t res;
	res.number_t_value = (double)((s13) + (i));
	return res;
}
array_number_t linalg_vectorRange(index_t s, index_t e) {
	env_t_18 env_t_18_value = make_env_t_18(s); closure_t closure16 = make_closure(lambda18, &env_t_18_value);
	return vector_build(((e) - (s)) + (1), closure16);
}
typedef struct env_t_26 {
	array_array_number_t m;
	closure_t f;
} env_t_26;
env_t_26 make_env_t_26(array_array_number_t m,closure_t f) {
	env_t_26 env;
	env.m = m;
	env.f = f;
	return env;
}

value_t lambda26(env_t_26* env22, index_t i) {
	array_array_number_t m21 = env22->m;
	closure_t f20 = env22->f;
	value_t res;
	res.array_number_t_value = f20.lam(f20.env, m21->arr[i]).array_number_t_value;
	return res;
}
array_array_number_t linalg_matrixMap(closure_t f, array_array_number_t m) {
	env_t_26 env_t_26_value = make_env_t_26(m,f); closure_t closure24 = make_closure(lambda26, &env_t_26_value);
	return matrix_build(m->length, closure24);
}
typedef struct env_t_36 {
	array_number_t v2;
	array_number_t v1;
	closure_t f;
} env_t_36;
env_t_36 make_env_t_36(array_number_t v2,array_number_t v1,closure_t f) {
	env_t_36 env;
	env.v2 = v2;
	env.v1 = v1;
	env.f = f;
	return env;
}

value_t lambda36(env_t_36* env32, index_t i) {
	array_number_t v231 = env32->v2;
	array_number_t v130 = env32->v1;
	closure_t f29 = env32->f;
	value_t res;
	res.number_t_value = f29.lam(f29.env, v130->arr[i], v231->arr[i]).number_t_value;
	return res;
}
array_number_t linalg_vectorMap2(closure_t f, array_number_t v1, array_number_t v2) {
	env_t_36 env_t_36_value = make_env_t_36(v2,v1,f); closure_t closure34 = make_closure(lambda36, &env_t_36_value);
	return vector_build(v1->length, closure34);
}
typedef struct env_t_46 {
	array_array_number_t m2;
	array_array_number_t m1;
	closure_t f;
} env_t_46;
env_t_46 make_env_t_46(array_array_number_t m2,array_array_number_t m1,closure_t f) {
	env_t_46 env;
	env.m2 = m2;
	env.m1 = m1;
	env.f = f;
	return env;
}

value_t lambda46(env_t_46* env42, index_t i) {
	array_array_number_t m241 = env42->m2;
	array_array_number_t m140 = env42->m1;
	closure_t f39 = env42->f;
	value_t res;
	res.array_number_t_value = f39.lam(f39.env, m140->arr[i], m241->arr[i]).array_number_t_value;
	return res;
}
array_array_number_t linalg_matrixMap2(closure_t f, array_array_number_t m1, array_array_number_t m2) {
	env_t_46 env_t_46_value = make_env_t_46(m2,m1,f); closure_t closure44 = make_closure(lambda46, &env_t_46_value);
	return matrix_build(m1->length, closure44);
}
typedef struct env_t_56 {
	array_array_array_number_t m2;
	array_array_array_number_t m1;
	closure_t f;
} env_t_56;
env_t_56 make_env_t_56(array_array_array_number_t m2,array_array_array_number_t m1,closure_t f) {
	env_t_56 env;
	env.m2 = m2;
	env.m1 = m1;
	env.f = f;
	return env;
}

value_t lambda56(env_t_56* env52, index_t i) {
	array_array_array_number_t m251 = env52->m2;
	array_array_array_number_t m150 = env52->m1;
	closure_t f49 = env52->f;
	value_t res;
	res.array_array_number_t_value = f49.lam(f49.env, m150->arr[i], m251->arr[i]).array_array_number_t_value;
	return res;
}
array_array_array_number_t linalg_matrix3DMap2(closure_t f, array_array_array_number_t m1, array_array_array_number_t m2) {
	env_t_56 env_t_56_value = make_env_t_56(m2,m1,f); closure_t closure54 = make_closure(lambda56, &env_t_56_value);
	return matrix3d_build(m1->length, closure54);
}
typedef struct env_t_64 {
	closure_t f;
	array_number_t arr;
} env_t_64;
env_t_64 make_env_t_64(closure_t f,array_number_t arr) {
	env_t_64 env;
	env.f = f;
	env.arr = arr;
	return env;
}

value_t lambda64(env_t_64* env60, index_t i) {
	closure_t f59 = env60->f;
	array_number_t arr58 = env60->arr;
	value_t res;
	res.array_number_t_value = f59.lam(f59.env, arr58->arr[i]).array_number_t_value;
	return res;
}
array_array_number_t linalg_vectorMapToMatrix(closure_t f, array_number_t arr) {
	env_t_64 env_t_64_value = make_env_t_64(f,arr); closure_t closure62 = make_closure(lambda64, &env_t_64_value);
	return matrix_build(arr->length, closure62);
}
typedef struct env_t_72 {
	closure_t f;
	array_number_t arr;
} env_t_72;
env_t_72 make_env_t_72(closure_t f,array_number_t arr) {
	env_t_72 env;
	env.f = f;
	env.arr = arr;
	return env;
}

value_t lambda72(env_t_72* env68, index_t i) {
	closure_t f67 = env68->f;
	array_number_t arr66 = env68->arr;
	value_t res;
	res.array_array_number_t_value = f67.lam(f67.env, arr66->arr[i]).array_array_number_t_value;
	return res;
}
array_array_array_number_t linalg_vectorMapToMatrix3D(closure_t f, array_number_t arr) {
	env_t_72 env_t_72_value = make_env_t_72(f,arr); closure_t closure70 = make_closure(lambda72, &env_t_72_value);
	return matrix3d_build(arr->length, closure70);
}
typedef struct env_t_80 {
	closure_t f;
} env_t_80;
env_t_80 make_env_t_80(closure_t f) {
	env_t_80 env;
	env.f = f;
	return env;
}

value_t lambda80(env_t_80* env75, number_t acc, number_t cur) {
	closure_t f74 = env75->f;
	value_t res;
	res.number_t_value = f74.lam(f74.env, acc, (int)(cur)).number_t_value;
	return res;
}
number_t linalg_iterateNumber(closure_t f, number_t z, index_t s, index_t e) {
	env_t_80 env_t_80_value = make_env_t_80(f); closure_t closure77 = make_closure(lambda80, &env_t_80_value);
	return vector_fold_number(closure77, z, linalg_vectorRange(s, e));
}
typedef struct env_t_88 {
	closure_t f;
} env_t_88;
env_t_88 make_env_t_88(closure_t f) {
	env_t_88 env;
	env.f = f;
	return env;
}

value_t lambda88(env_t_88* env83, array_number_t acc, number_t cur) {
	closure_t f82 = env83->f;
	value_t res;
	res.array_number_t_value = f82.lam(f82.env, acc, (int)(cur)).array_number_t_value;
	return res;
}
array_number_t linalg_iterateVector(closure_t f, array_number_t z, index_t s, index_t e) {
	env_t_88 env_t_88_value = make_env_t_88(f); closure_t closure85 = make_closure(lambda88, &env_t_88_value);
	return vector_fold_vector(closure85, z, linalg_vectorRange(s, e));
}
typedef struct env_t_96 {
	closure_t f;
} env_t_96;
env_t_96 make_env_t_96(closure_t f) {
	env_t_96 env;
	env.f = f;
	return env;
}

value_t lambda96(env_t_96* env91, array_array_number_t acc, number_t cur) {
	closure_t f90 = env91->f;
	value_t res;
	res.array_array_number_t_value = f90.lam(f90.env, acc, (int)(cur)).array_array_number_t_value;
	return res;
}
array_array_number_t linalg_iterateMatrix(closure_t f, array_array_number_t z, index_t s, index_t e) {
	env_t_96 env_t_96_value = make_env_t_96(f); closure_t closure93 = make_closure(lambda96, &env_t_96_value);
	return vector_fold_matrix(closure93, z, linalg_vectorRange(s, e));
}
typedef struct env_t_104 {
	closure_t f;
} env_t_104;
env_t_104 make_env_t_104(closure_t f) {
	env_t_104 env;
	env.f = f;
	return env;
}

value_t lambda104(env_t_104* env99, array_array_array_number_t acc, number_t cur) {
	closure_t f98 = env99->f;
	value_t res;
	res.array_array_array_number_t_value = f98.lam(f98.env, acc, (int)(cur)).array_array_array_number_t_value;
	return res;
}
array_array_array_number_t linalg_iterateMatrix3D(closure_t f, array_array_array_number_t z, index_t s, index_t e) {
	env_t_104 env_t_104_value = make_env_t_104(f); closure_t closure101 = make_closure(lambda104, &env_t_104_value);
	return vector_fold_matrix3d(closure101, z, linalg_vectorRange(s, e));
}
typedef empty_env_t env_t_110;


value_t lambda110(env_t_110* env106, number_t acc, number_t cur) {
	
	value_t res;
	res.number_t_value = (acc) + (cur);
	return res;
}
number_t linalg_arraySum(array_number_t arr) {
	env_t_110 env_t_110_value = make_empty_env(); closure_t closure108 = make_closure(lambda110, &env_t_110_value);
	return vector_fold_number(closure108, 0, arr);
}
typedef empty_env_t env_t_117;


value_t lambda117(env_t_117* env112, number_t acc, number_t cur) {
	number_t ite116 = 0;
	if((acc) > (cur)) {
		
		ite116 = acc;
	} else {
		
		ite116 = cur;
	}
	value_t res;
	res.number_t_value = ite116;
	return res;
}
number_t linalg_arrayMax(array_number_t arr) {
	env_t_117 env_t_117_value = make_empty_env(); closure_t closure114 = make_closure(lambda117, &env_t_117_value);
	return vector_fold_number(closure114, -1000, arr);
}
typedef struct env_t_124 {
	number_t y;
} env_t_124;
env_t_124 make_env_t_124(number_t y) {
	env_t_124 env;
	env.y = y;
	return env;
}

value_t lambda124(env_t_124* env120, number_t a) {
	number_t y119 = env120->y;
	value_t res;
	res.number_t_value = (a) * (y119);
	return res;
}
array_number_t linalg_mult_by_scalar(array_number_t x, number_t y) {
	env_t_124 env_t_124_value = make_env_t_124(y); closure_t closure122 = make_closure(lambda124, &env_t_124_value);
	return linalg_vectorMap(closure122, x);
}

array_number_t linalg_cross(array_number_t a, array_number_t b) {
	array_number_t array146 = (array_number_t)malloc(sizeof(int) * 2);
	array146->length=3;
	array146->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array146->arr[0] = ((a->arr[1]) * (b->arr[2])) - ((a->arr[2]) * (b->arr[1]));
	array146->arr[1] = ((a->arr[2]) * (b->arr[0])) - ((a->arr[0]) * (b->arr[2]));
	array146->arr[2] = ((a->arr[0]) * (b->arr[1])) - ((a->arr[1]) * (b->arr[0]));;
	return array146;
}
typedef empty_env_t env_t_152;


value_t lambda152(env_t_152* env148, number_t x, number_t y) {
	
	value_t res;
	res.number_t_value = (x) + (y);
	return res;
}
array_number_t linalg_add_vec(array_number_t x, array_number_t y) {
	env_t_152 env_t_152_value = make_empty_env(); closure_t closure150 = make_closure(lambda152, &env_t_152_value);
	return linalg_vectorMap2(closure150, x, y);
}
typedef empty_env_t env_t_158;


value_t lambda158(env_t_158* env154, number_t x, number_t y) {
	
	value_t res;
	res.number_t_value = (x) * (y);
	return res;
}
array_number_t linalg_mult_vec_elementwise(array_number_t x, array_number_t y) {
	env_t_158 env_t_158_value = make_empty_env(); closure_t closure156 = make_closure(lambda158, &env_t_158_value);
	return linalg_vectorMap2(closure156, x, y);
}

array_number_t linalg_add_vec3(array_number_t x, array_number_t y, array_number_t z) {
	
	return linalg_add_vec(linalg_add_vec(x, y), z);
}
typedef empty_env_t env_t_166;


value_t lambda166(env_t_166* env162, number_t x, number_t y) {
	
	value_t res;
	res.number_t_value = (x) - (y);
	return res;
}
array_number_t linalg_sub_vec(array_number_t x, array_number_t y) {
	env_t_166 env_t_166_value = make_empty_env(); closure_t closure164 = make_closure(lambda166, &env_t_166_value);
	return linalg_vectorMap2(closure164, x, y);
}
typedef empty_env_t env_t_172;


value_t lambda172(env_t_172* env168, array_number_t x, array_number_t y) {
	
	value_t res;
	res.array_number_t_value = linalg_add_vec(x, y);
	return res;
}
array_array_number_t linalg_matrixAdd(array_array_number_t x, array_array_number_t y) {
	env_t_172 env_t_172_value = make_empty_env(); closure_t closure170 = make_closure(lambda172, &env_t_172_value);
	return linalg_matrixMap2(closure170, x, y);
}
typedef empty_env_t env_t_178;


value_t lambda178(env_t_178* env174, array_number_t x, array_number_t y) {
	
	value_t res;
	res.array_number_t_value = linalg_mult_vec_elementwise(x, y);
	return res;
}
array_array_number_t linalg_matrixMultElementwise(array_array_number_t x, array_array_number_t y) {
	env_t_178 env_t_178_value = make_empty_env(); closure_t closure176 = make_closure(lambda178, &env_t_178_value);
	return linalg_matrixMap2(closure176, x, y);
}
typedef empty_env_t env_t_185;


value_t lambda185(env_t_185* env180, number_t x1) {
	
	value_t res;
	res.number_t_value = (x1) * (x1);
	return res;
}
number_t linalg_sqnorm(array_number_t x) {
	env_t_185 env_t_185_value = make_empty_env(); closure_t closure182 = make_closure(lambda185, &env_t_185_value);
	return linalg_arraySum(linalg_vectorMap(closure182, x));
}
typedef empty_env_t env_t_192;


value_t lambda192(env_t_192* env187, number_t x, number_t y) {
	
	value_t res;
	res.number_t_value = (x) * (y);
	return res;
}
number_t linalg_dot_prod(array_number_t x, array_number_t y) {
	env_t_192 env_t_192_value = make_empty_env(); closure_t closure189 = make_closure(lambda192, &env_t_192_value);
	return linalg_arraySum(linalg_vectorMap2(closure189, x, y));
}
typedef struct env_t_199 {
	array_number_t row;
} env_t_199;
env_t_199 make_env_t_199(array_number_t row) {
	env_t_199 env;
	env.row = row;
	return env;
}

value_t lambda199(env_t_199* env194, number_t r) {
	array_number_t row193 = env194->row;
	value_t res;
	res.array_number_t_value = row193;
	return res;
}
array_array_number_t linalg_matrixFillFromVector(index_t rows, array_number_t row) {
	env_t_199 env_t_199_value = make_env_t_199(row); closure_t closure196 = make_closure(lambda199, &env_t_199_value);
	return linalg_vectorMapToMatrix(closure196, linalg_vectorRange(1, rows));
}
typedef struct env_t_207 {
	number_t value;
} env_t_207;
env_t_207 make_env_t_207(number_t value) {
	env_t_207 env;
	env.value = value;
	return env;
}

value_t lambda207(env_t_207* env201, number_t c) {
	number_t value200 = env201->value;
	value_t res;
	res.number_t_value = value200;
	return res;
}
array_array_number_t linalg_matrixFill(index_t rows, index_t cols, number_t value) {
	env_t_207 env_t_207_value = make_env_t_207(value); closure_t closure203 = make_closure(lambda207, &env_t_207_value);
	array_number_t row = linalg_vectorMap(closure203, linalg_vectorRange(1, cols));
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
typedef struct env_t_225 {
	array_number_t v2;
	array_number_t v1;
	closure_t f;
} env_t_225;
env_t_225 make_env_t_225(array_number_t v2,array_number_t v1,closure_t f) {
	env_t_225 env;
	env.v2 = v2;
	env.v1 = v1;
	env.f = f;
	return env;
}

value_t lambda225(env_t_225* env221, index_t i) {
	array_number_t v2220 = env221->v2;
	array_number_t v1219 = env221->v1;
	closure_t f218 = env221->f;
	value_t res;
	res.number_t_value = f218.lam(f218.env, v1219->arr[i], v2220->arr[i]).number_t_value;
	return res;
}
array_number_t linalg_vectorMap2GivenStorage(storage_t storage, closure_t f, array_number_t v1, array_number_t v2) {
	env_t_225 env_t_225_value = make_env_t_225(v2,v1,f); closure_t closure223 = make_closure(lambda225, &env_t_225_value);
	return vector_build_given_storage(storage, closure223);
}
typedef empty_env_t env_t_231;


value_t lambda231(env_t_231* env227, number_t x, number_t y) {
	
	value_t res;
	res.number_t_value = (x) + (y);
	return res;
}
array_number_t linalg_add_vecGivenStorage(storage_t s, array_number_t x, array_number_t y) {
	env_t_231 env_t_231_value = make_empty_env(); closure_t closure229 = make_closure(lambda231, &env_t_231_value);
	return linalg_vectorMap2GivenStorage(s, closure229, x, y);
}
#endif
