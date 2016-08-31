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
	array_number_t v;
	index_t offset;
} env_t_29;
env_t_29 make_env_t_29(array_number_t v,index_t offset) {
	env_t_29 env;
	env.v = v;
	env.offset = offset;
	return env;
}

value_t lambda29(env_t_29* env25, index_t i) {
	array_number_t v24 = env25->v;
	index_t offset23 = env25->offset;
	value_t res;
	res.number_t_value = v24->arr[(i) + (offset23)];
	return res;
}
array_number_t linalg_vectorSlice(card_t size, index_t offset, array_number_t v) {
	env_t_29 env_t_29_value = make_env_t_29(v,offset); closure_t closure27 = make_closure(lambda29, &env_t_29_value);
	return vector_build(size, closure27);
}
typedef struct env_t_38 {
	array_array_number_t m;
	closure_t f;
} env_t_38;
env_t_38 make_env_t_38(array_array_number_t m,closure_t f) {
	env_t_38 env;
	env.m = m;
	env.f = f;
	return env;
}

value_t lambda38(env_t_38* env34, index_t i) {
	array_array_number_t m33 = env34->m;
	closure_t f32 = env34->f;
	value_t res;
	res.array_number_t_value = f32.lam(f32.env, m33->arr[i]).array_number_t_value;
	return res;
}
array_array_number_t linalg_matrixMap(closure_t f, array_array_number_t m) {
	card_t macroDef30 = m->length;
	env_t_38 env_t_38_value = make_env_t_38(m,f); closure_t closure36 = make_closure(lambda38, &env_t_38_value);
	return matrix_build(macroDef30, closure36);
}
typedef struct env_t_49 {
	array_number_t v2;
	array_number_t v1;
	closure_t f;
} env_t_49;
env_t_49 make_env_t_49(array_number_t v2,array_number_t v1,closure_t f) {
	env_t_49 env;
	env.v2 = v2;
	env.v1 = v1;
	env.f = f;
	return env;
}

value_t lambda49(env_t_49* env45, index_t i) {
	array_number_t v244 = env45->v2;
	array_number_t v143 = env45->v1;
	closure_t f42 = env45->f;
	value_t res;
	res.number_t_value = f42.lam(f42.env, v143->arr[i], v244->arr[i]).number_t_value;
	return res;
}
array_number_t linalg_vectorMap2(closure_t f, array_number_t v1, array_number_t v2) {
	card_t macroDef39 = v1->length;
	env_t_49 env_t_49_value = make_env_t_49(v2,v1,f); closure_t closure47 = make_closure(lambda49, &env_t_49_value);
	return vector_build(macroDef39, closure47);
}
typedef struct env_t_60 {
	array_array_number_t m2;
	array_array_number_t m1;
	closure_t f;
} env_t_60;
env_t_60 make_env_t_60(array_array_number_t m2,array_array_number_t m1,closure_t f) {
	env_t_60 env;
	env.m2 = m2;
	env.m1 = m1;
	env.f = f;
	return env;
}

value_t lambda60(env_t_60* env56, index_t i) {
	array_array_number_t m255 = env56->m2;
	array_array_number_t m154 = env56->m1;
	closure_t f53 = env56->f;
	value_t res;
	res.array_number_t_value = f53.lam(f53.env, m154->arr[i], m255->arr[i]).array_number_t_value;
	return res;
}
array_array_number_t linalg_matrixMap2(closure_t f, array_array_number_t m1, array_array_number_t m2) {
	card_t macroDef50 = m1->length;
	env_t_60 env_t_60_value = make_env_t_60(m2,m1,f); closure_t closure58 = make_closure(lambda60, &env_t_60_value);
	return matrix_build(macroDef50, closure58);
}
typedef struct env_t_71 {
	array_array_array_number_t m2;
	array_array_array_number_t m1;
	closure_t f;
} env_t_71;
env_t_71 make_env_t_71(array_array_array_number_t m2,array_array_array_number_t m1,closure_t f) {
	env_t_71 env;
	env.m2 = m2;
	env.m1 = m1;
	env.f = f;
	return env;
}

value_t lambda71(env_t_71* env67, index_t i) {
	array_array_array_number_t m266 = env67->m2;
	array_array_array_number_t m165 = env67->m1;
	closure_t f64 = env67->f;
	value_t res;
	res.array_array_number_t_value = f64.lam(f64.env, m165->arr[i], m266->arr[i]).array_array_number_t_value;
	return res;
}
array_array_array_number_t linalg_matrix3DMap2(closure_t f, array_array_array_number_t m1, array_array_array_number_t m2) {
	card_t macroDef61 = m1->length;
	env_t_71 env_t_71_value = make_env_t_71(m2,m1,f); closure_t closure69 = make_closure(lambda71, &env_t_71_value);
	return matrix3d_build(macroDef61, closure69);
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
	res.array_number_t_value = f75.lam(f75.env, arr74->arr[i]).array_number_t_value;
	return res;
}
array_array_number_t linalg_vectorMapToMatrix(closure_t f, array_number_t arr) {
	card_t macroDef72 = arr->length;
	env_t_80 env_t_80_value = make_env_t_80(f,arr); closure_t closure78 = make_closure(lambda80, &env_t_80_value);
	return matrix_build(macroDef72, closure78);
}
typedef struct env_t_89 {
	closure_t f;
	array_number_t arr;
} env_t_89;
env_t_89 make_env_t_89(closure_t f,array_number_t arr) {
	env_t_89 env;
	env.f = f;
	env.arr = arr;
	return env;
}

value_t lambda89(env_t_89* env85, index_t i) {
	closure_t f84 = env85->f;
	array_number_t arr83 = env85->arr;
	value_t res;
	res.array_array_number_t_value = f84.lam(f84.env, arr83->arr[i]).array_array_number_t_value;
	return res;
}
array_array_array_number_t linalg_vectorMapToMatrix3D(closure_t f, array_number_t arr) {
	card_t macroDef81 = arr->length;
	env_t_89 env_t_89_value = make_env_t_89(f,arr); closure_t closure87 = make_closure(lambda89, &env_t_89_value);
	return matrix3d_build(macroDef81, closure87);
}
typedef struct env_t_97 {
	closure_t f;
} env_t_97;
env_t_97 make_env_t_97(closure_t f) {
	env_t_97 env;
	env.f = f;
	return env;
}

value_t lambda97(env_t_97* env92, number_t acc, number_t cur) {
	closure_t f91 = env92->f;
	value_t res;
	res.number_t_value = f91.lam(f91.env, acc, (int)(cur)).number_t_value;
	return res;
}
number_t linalg_iterateNumber(closure_t f, number_t z, card_t s, card_t e) {
	env_t_97 env_t_97_value = make_env_t_97(f); closure_t closure94 = make_closure(lambda97, &env_t_97_value);
	return vector_fold_number(closure94, z, linalg_vectorRange(s, e));
}
typedef struct env_t_105 {
	closure_t f;
} env_t_105;
env_t_105 make_env_t_105(closure_t f) {
	env_t_105 env;
	env.f = f;
	return env;
}

value_t lambda105(env_t_105* env100, array_number_t acc, number_t cur) {
	closure_t f99 = env100->f;
	value_t res;
	res.array_number_t_value = f99.lam(f99.env, acc, (int)(cur)).array_number_t_value;
	return res;
}
array_number_t linalg_iterateVector(closure_t f, array_number_t z, card_t s, card_t e) {
	env_t_105 env_t_105_value = make_env_t_105(f); closure_t closure102 = make_closure(lambda105, &env_t_105_value);
	return vector_fold_vector(closure102, z, linalg_vectorRange(s, e));
}
typedef struct env_t_113 {
	closure_t f;
} env_t_113;
env_t_113 make_env_t_113(closure_t f) {
	env_t_113 env;
	env.f = f;
	return env;
}

value_t lambda113(env_t_113* env108, array_array_number_t acc, number_t cur) {
	closure_t f107 = env108->f;
	value_t res;
	res.array_array_number_t_value = f107.lam(f107.env, acc, (int)(cur)).array_array_number_t_value;
	return res;
}
array_array_number_t linalg_iterateMatrix(closure_t f, array_array_number_t z, card_t s, card_t e) {
	env_t_113 env_t_113_value = make_env_t_113(f); closure_t closure110 = make_closure(lambda113, &env_t_113_value);
	return vector_fold_matrix(closure110, z, linalg_vectorRange(s, e));
}
typedef struct env_t_121 {
	closure_t f;
} env_t_121;
env_t_121 make_env_t_121(closure_t f) {
	env_t_121 env;
	env.f = f;
	return env;
}

value_t lambda121(env_t_121* env116, array_array_array_number_t acc, number_t cur) {
	closure_t f115 = env116->f;
	value_t res;
	res.array_array_array_number_t_value = f115.lam(f115.env, acc, (int)(cur)).array_array_array_number_t_value;
	return res;
}
array_array_array_number_t linalg_iterateMatrix3D(closure_t f, array_array_array_number_t z, card_t s, card_t e) {
	env_t_121 env_t_121_value = make_env_t_121(f); closure_t closure118 = make_closure(lambda121, &env_t_121_value);
	return vector_fold_matrix3d(closure118, z, linalg_vectorRange(s, e));
}
typedef empty_env_t env_t_127;


value_t lambda127(env_t_127* env123, number_t acc, number_t cur) {
	
	value_t res;
	res.number_t_value = (acc) + (cur);
	return res;
}
number_t linalg_arraySum(array_number_t arr) {
	env_t_127 env_t_127_value = make_empty_env(); closure_t closure125 = make_closure(lambda127, &env_t_127_value);
	return vector_fold_number(closure125, 0, arr);
}
typedef empty_env_t env_t_134;


value_t lambda134(env_t_134* env129, number_t acc, number_t cur) {
	number_t ite133 = 0;
	if((acc) > (cur)) {
		
		ite133 = acc;
	} else {
		
		ite133 = cur;
	}
	value_t res;
	res.number_t_value = ite133;
	return res;
}
number_t linalg_arrayMax(array_number_t arr) {
	env_t_134 env_t_134_value = make_empty_env(); closure_t closure131 = make_closure(lambda134, &env_t_134_value);
	return vector_fold_number(closure131, -1000, arr);
}
typedef struct env_t_141 {
	number_t y;
} env_t_141;
env_t_141 make_env_t_141(number_t y) {
	env_t_141 env;
	env.y = y;
	return env;
}

value_t lambda141(env_t_141* env137, number_t a) {
	number_t y136 = env137->y;
	value_t res;
	res.number_t_value = (a) * (y136);
	return res;
}
array_number_t linalg_mult_by_scalar(array_number_t x, number_t y) {
	env_t_141 env_t_141_value = make_env_t_141(y); closure_t closure139 = make_closure(lambda141, &env_t_141_value);
	return linalg_vectorMap(closure139, x);
}

array_number_t linalg_cross(array_number_t a, array_number_t b) {
	array_number_t array163 = (array_number_t)malloc(sizeof(int) * 2);
	array163->length=3;
	array163->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array163->arr[0] = ((a->arr[1]) * (b->arr[2])) - ((a->arr[2]) * (b->arr[1]));
	array163->arr[1] = ((a->arr[2]) * (b->arr[0])) - ((a->arr[0]) * (b->arr[2]));
	array163->arr[2] = ((a->arr[0]) * (b->arr[1])) - ((a->arr[1]) * (b->arr[0]));;
	return array163;
}
typedef empty_env_t env_t_169;


value_t lambda169(env_t_169* env165, number_t x, number_t y) {
	
	value_t res;
	res.number_t_value = (x) + (y);
	return res;
}
array_number_t linalg_add_vec(array_number_t x, array_number_t y) {
	env_t_169 env_t_169_value = make_empty_env(); closure_t closure167 = make_closure(lambda169, &env_t_169_value);
	return linalg_vectorMap2(closure167, x, y);
}
typedef empty_env_t env_t_175;


value_t lambda175(env_t_175* env171, number_t x, number_t y) {
	
	value_t res;
	res.number_t_value = (x) * (y);
	return res;
}
array_number_t linalg_mult_vec_elementwise(array_number_t x, array_number_t y) {
	env_t_175 env_t_175_value = make_empty_env(); closure_t closure173 = make_closure(lambda175, &env_t_175_value);
	return linalg_vectorMap2(closure173, x, y);
}

array_number_t linalg_add_vec3(array_number_t x, array_number_t y, array_number_t z) {
	
	return linalg_add_vec(linalg_add_vec(x, y), z);
}
typedef empty_env_t env_t_183;


value_t lambda183(env_t_183* env179, number_t x, number_t y) {
	
	value_t res;
	res.number_t_value = (x) - (y);
	return res;
}
array_number_t linalg_sub_vec(array_number_t x, array_number_t y) {
	env_t_183 env_t_183_value = make_empty_env(); closure_t closure181 = make_closure(lambda183, &env_t_183_value);
	return linalg_vectorMap2(closure181, x, y);
}
typedef empty_env_t env_t_189;


value_t lambda189(env_t_189* env185, array_number_t x, array_number_t y) {
	
	value_t res;
	res.array_number_t_value = linalg_add_vec(x, y);
	return res;
}
array_array_number_t linalg_matrixAdd(array_array_number_t x, array_array_number_t y) {
	env_t_189 env_t_189_value = make_empty_env(); closure_t closure187 = make_closure(lambda189, &env_t_189_value);
	return linalg_matrixMap2(closure187, x, y);
}
typedef empty_env_t env_t_195;


value_t lambda195(env_t_195* env191, array_number_t x, array_number_t y) {
	
	value_t res;
	res.array_number_t_value = linalg_mult_vec_elementwise(x, y);
	return res;
}
array_array_number_t linalg_matrixMultElementwise(array_array_number_t x, array_array_number_t y) {
	env_t_195 env_t_195_value = make_empty_env(); closure_t closure193 = make_closure(lambda195, &env_t_195_value);
	return linalg_matrixMap2(closure193, x, y);
}
typedef empty_env_t env_t_202;


value_t lambda202(env_t_202* env197, number_t x1) {
	
	value_t res;
	res.number_t_value = (x1) * (x1);
	return res;
}
number_t linalg_sqnorm(array_number_t x) {
	env_t_202 env_t_202_value = make_empty_env(); closure_t closure199 = make_closure(lambda202, &env_t_202_value);
	return linalg_arraySum(linalg_vectorMap(closure199, x));
}
typedef empty_env_t env_t_209;


value_t lambda209(env_t_209* env204, number_t x, number_t y) {
	
	value_t res;
	res.number_t_value = (x) * (y);
	return res;
}
number_t linalg_dot_prod(array_number_t x, array_number_t y) {
	env_t_209 env_t_209_value = make_empty_env(); closure_t closure206 = make_closure(lambda209, &env_t_209_value);
	return linalg_arraySum(linalg_vectorMap2(closure206, x, y));
}
typedef struct env_t_216 {
	array_number_t row;
} env_t_216;
env_t_216 make_env_t_216(array_number_t row) {
	env_t_216 env;
	env.row = row;
	return env;
}

value_t lambda216(env_t_216* env211, number_t r) {
	array_number_t row210 = env211->row;
	value_t res;
	res.array_number_t_value = row210;
	return res;
}
array_array_number_t linalg_matrixFillFromVector(card_t rows, array_number_t row) {
	env_t_216 env_t_216_value = make_env_t_216(row); closure_t closure213 = make_closure(lambda216, &env_t_216_value);
	return linalg_vectorMapToMatrix(closure213, linalg_vectorRange(1, rows));
}
typedef struct env_t_224 {
	number_t value;
} env_t_224;
env_t_224 make_env_t_224(number_t value) {
	env_t_224 env;
	env.value = value;
	return env;
}

value_t lambda224(env_t_224* env218, number_t c) {
	number_t value217 = env218->value;
	value_t res;
	res.number_t_value = value217;
	return res;
}
array_array_number_t linalg_matrixFill(card_t rows, card_t cols, number_t value) {
	env_t_224 env_t_224_value = make_env_t_224(value); closure_t closure220 = make_closure(lambda224, &env_t_224_value);
	array_number_t row = linalg_vectorMap(closure220, linalg_vectorRange(1, cols));
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
	array_number_t macroDef235 = (array_number_t)storage;
		for(int i = 0; i < macroDef235->length; i++){
			
			macroDef235->arr[i] = f.lam(f.env, v1->arr[i], v2->arr[i]).number_t_value;
		}
	return macroDef235;
}
typedef empty_env_t env_t_241;


value_t lambda241(env_t_241* env237, number_t x, number_t y) {
	
	value_t res;
	res.number_t_value = (x) + (y);
	return res;
}
array_number_t linalg_add_vecGivenStorage(storage_t s, array_number_t x, array_number_t y) {
	env_t_241 env_t_241_value = make_empty_env(); closure_t closure239 = make_closure(lambda241, &env_t_241_value);
	return linalg_vectorMap2GivenStorage(s, closure239, x, y);
}
#endif
