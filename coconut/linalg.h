#ifndef __LINALG_H__ 
#define __LINALG_H__ 
#include "runtime/fsharp.h"
#include <stdio.h>
#include <math.h>
typedef struct env_t_7 {
	array_number_t v;
	closure_t f;
} env_t_7;
env_t_7 make_env_t_7(array_number_t v,closure_t f) {
	env_t_7 env;
	env.v = v;
	env.f = f;
	return env;
}

value_t lambda7(env_t_7* env4, index_t i) {
	array_number_t v3 = env4->v;
	closure_t f2 = env4->f;
	value_t res;
	res.number_t_value = f2.lam(f2.env, v3->arr[i]).number_t_value;
	return res;
}
array_number_t linalg_vectorMap(closure_t f, array_number_t v) {
	card_t macroDef1 = v->length;
	env_t_7 env_t_7_value = make_env_t_7(v,f); closure_t closure6 = make_closure(lambda7, &env_t_7_value);
	return vector_build(macroDef1, closure6);
}
typedef struct env_t_12 {
	card_t s;
} env_t_12;
env_t_12 make_env_t_12(card_t s) {
	env_t_12 env;
	env.s = s;
	return env;
}

value_t lambda12(env_t_12* env9, index_t i) {
	card_t s8 = env9->s;
	value_t res;
	res.number_t_value = (double)(((s8)) + (i));
	return res;
}
array_number_t linalg_vectorRange(card_t s, card_t e) {
	env_t_12 env_t_12_value = make_env_t_12(s); closure_t closure11 = make_closure(lambda12, &env_t_12_value);
	return vector_build(((e) - (s)) + (1), closure11);
}
typedef struct env_t_18 {
	array_number_t v;
	index_t offset;
} env_t_18;
env_t_18 make_env_t_18(array_number_t v,index_t offset) {
	env_t_18 env;
	env.v = v;
	env.offset = offset;
	return env;
}

value_t lambda18(env_t_18* env15, index_t i) {
	array_number_t v14 = env15->v;
	index_t offset13 = env15->offset;
	value_t res;
	res.number_t_value = v14->arr[(i) + (offset13)];
	return res;
}
array_number_t linalg_vectorSlice(card_t size, index_t offset, array_number_t v) {
	env_t_18 env_t_18_value = make_env_t_18(v,offset); closure_t closure17 = make_closure(lambda18, &env_t_18_value);
	return vector_build(size, closure17);
}
typedef struct env_t_25 {
	array_array_number_t m;
	closure_t f;
} env_t_25;
env_t_25 make_env_t_25(array_array_number_t m,closure_t f) {
	env_t_25 env;
	env.m = m;
	env.f = f;
	return env;
}

value_t lambda25(env_t_25* env22, index_t i) {
	array_array_number_t m21 = env22->m;
	closure_t f20 = env22->f;
	value_t res;
	res.array_number_t_value = f20.lam(f20.env, m21->arr[i]).array_number_t_value;
	return res;
}
array_array_number_t linalg_matrixMap(closure_t f, array_array_number_t m) {
	card_t macroDef19 = m->length;
	env_t_25 env_t_25_value = make_env_t_25(m,f); closure_t closure24 = make_closure(lambda25, &env_t_25_value);
	return matrix_build(macroDef19, closure24);
}
typedef struct env_t_33 {
	array_number_t v2;
	array_number_t v1;
	closure_t f;
} env_t_33;
env_t_33 make_env_t_33(array_number_t v2,array_number_t v1,closure_t f) {
	env_t_33 env;
	env.v2 = v2;
	env.v1 = v1;
	env.f = f;
	return env;
}

value_t lambda33(env_t_33* env30, index_t i) {
	array_number_t v229 = env30->v2;
	array_number_t v128 = env30->v1;
	closure_t f27 = env30->f;
	value_t res;
	res.number_t_value = f27.lam(f27.env, v128->arr[i], v229->arr[i]).number_t_value;
	return res;
}
array_number_t linalg_vectorMap2(closure_t f, array_number_t v1, array_number_t v2) {
	card_t macroDef26 = v1->length;
	env_t_33 env_t_33_value = make_env_t_33(v2,v1,f); closure_t closure32 = make_closure(lambda33, &env_t_33_value);
	return vector_build(macroDef26, closure32);
}
typedef struct env_t_41 {
	array_array_number_t m2;
	array_array_number_t m1;
	closure_t f;
} env_t_41;
env_t_41 make_env_t_41(array_array_number_t m2,array_array_number_t m1,closure_t f) {
	env_t_41 env;
	env.m2 = m2;
	env.m1 = m1;
	env.f = f;
	return env;
}

value_t lambda41(env_t_41* env38, index_t i) {
	array_array_number_t m237 = env38->m2;
	array_array_number_t m136 = env38->m1;
	closure_t f35 = env38->f;
	value_t res;
	res.array_number_t_value = f35.lam(f35.env, m136->arr[i], m237->arr[i]).array_number_t_value;
	return res;
}
array_array_number_t linalg_matrixMap2(closure_t f, array_array_number_t m1, array_array_number_t m2) {
	card_t macroDef34 = m1->length;
	env_t_41 env_t_41_value = make_env_t_41(m2,m1,f); closure_t closure40 = make_closure(lambda41, &env_t_41_value);
	return matrix_build(macroDef34, closure40);
}
typedef struct env_t_49 {
	array_array_array_number_t m2;
	array_array_array_number_t m1;
	closure_t f;
} env_t_49;
env_t_49 make_env_t_49(array_array_array_number_t m2,array_array_array_number_t m1,closure_t f) {
	env_t_49 env;
	env.m2 = m2;
	env.m1 = m1;
	env.f = f;
	return env;
}

value_t lambda49(env_t_49* env46, index_t i) {
	array_array_array_number_t m245 = env46->m2;
	array_array_array_number_t m144 = env46->m1;
	closure_t f43 = env46->f;
	value_t res;
	res.array_array_number_t_value = f43.lam(f43.env, m144->arr[i], m245->arr[i]).array_array_number_t_value;
	return res;
}
array_array_array_number_t linalg_matrix3DMap2(closure_t f, array_array_array_number_t m1, array_array_array_number_t m2) {
	card_t macroDef42 = m1->length;
	env_t_49 env_t_49_value = make_env_t_49(m2,m1,f); closure_t closure48 = make_closure(lambda49, &env_t_49_value);
	return matrix3d_build(macroDef42, closure48);
}
typedef struct env_t_56 {
	closure_t f;
	array_number_t arr;
} env_t_56;
env_t_56 make_env_t_56(closure_t f,array_number_t arr) {
	env_t_56 env;
	env.f = f;
	env.arr = arr;
	return env;
}

value_t lambda56(env_t_56* env53, index_t i) {
	closure_t f52 = env53->f;
	array_number_t arr51 = env53->arr;
	value_t res;
	res.array_number_t_value = f52.lam(f52.env, arr51->arr[i]).array_number_t_value;
	return res;
}
array_array_number_t linalg_vectorMapToMatrix(closure_t f, array_number_t arr) {
	card_t macroDef50 = arr->length;
	env_t_56 env_t_56_value = make_env_t_56(f,arr); closure_t closure55 = make_closure(lambda56, &env_t_56_value);
	return matrix_build(macroDef50, closure55);
}
typedef struct env_t_63 {
	closure_t f;
	array_number_t arr;
} env_t_63;
env_t_63 make_env_t_63(closure_t f,array_number_t arr) {
	env_t_63 env;
	env.f = f;
	env.arr = arr;
	return env;
}

value_t lambda63(env_t_63* env60, index_t i) {
	closure_t f59 = env60->f;
	array_number_t arr58 = env60->arr;
	value_t res;
	res.array_array_number_t_value = f59.lam(f59.env, arr58->arr[i]).array_array_number_t_value;
	return res;
}
array_array_array_number_t linalg_vectorMapToMatrix3D(closure_t f, array_number_t arr) {
	card_t macroDef57 = arr->length;
	env_t_63 env_t_63_value = make_env_t_63(f,arr); closure_t closure62 = make_closure(lambda63, &env_t_63_value);
	return matrix3d_build(macroDef57, closure62);
}

number_t linalg_iterateNumber(closure_t f, number_t z, card_t s, card_t e) {
	number_t macroDef64 = z;
	for(int cur_idx = 0; cur_idx < linalg_vectorRange(s, e)->length; cur_idx++){
		number_t cur = linalg_vectorRange(s, e)->arr[cur_idx];
		
		macroDef64 = f.lam(f.env, macroDef64, (int)(cur)).number_t_value;
	}
	return macroDef64;
}

array_number_t linalg_iterateVector(closure_t f, array_number_t z, card_t s, card_t e) {
	array_number_t macroDef65 = z;
	for(int cur_idx = 0; cur_idx < linalg_vectorRange(s, e)->length; cur_idx++){
		number_t cur = linalg_vectorRange(s, e)->arr[cur_idx];
		
		macroDef65 = f.lam(f.env, macroDef65, (int)(cur)).array_number_t_value;
	}
	return macroDef65;
}

array_array_number_t linalg_iterateMatrix(closure_t f, array_array_number_t z, card_t s, card_t e) {
	array_array_number_t macroDef66 = z;
	for(int cur_idx = 0; cur_idx < linalg_vectorRange(s, e)->length; cur_idx++){
		number_t cur = linalg_vectorRange(s, e)->arr[cur_idx];
		
		macroDef66 = f.lam(f.env, macroDef66, (int)(cur)).array_array_number_t_value;
	}
	return macroDef66;
}

array_array_array_number_t linalg_iterateMatrix3D(closure_t f, array_array_array_number_t z, card_t s, card_t e) {
	array_array_array_number_t macroDef67 = z;
	for(int cur_idx = 0; cur_idx < linalg_vectorRange(s, e)->length; cur_idx++){
		number_t cur = linalg_vectorRange(s, e)->arr[cur_idx];
		
		macroDef67 = f.lam(f.env, macroDef67, (int)(cur)).array_array_array_number_t_value;
	}
	return macroDef67;
}

number_t linalg_arraySum(array_number_t arr) {
	number_t macroDef68 = 0;
	for(int cur_idx = 0; cur_idx < arr->length; cur_idx++){
		number_t cur = arr->arr[cur_idx];
		
		macroDef68 = (macroDef68) + (cur);
	}
	return macroDef68;
}

number_t linalg_arrayMax(array_number_t arr) {
	number_t macroDef69 = -1000;
	for(int cur_idx = 0; cur_idx < arr->length; cur_idx++){
		number_t cur = arr->arr[cur_idx];
		number_t ite70 = 0;
	if((macroDef69) > (cur)) {
		
		ite70 = macroDef69;
	} else {
		
		ite70 = cur;
	}
		macroDef69 = ite70;
	}
	return macroDef69;
}
typedef struct env_t_75 {
	number_t y;
} env_t_75;
env_t_75 make_env_t_75(number_t y) {
	env_t_75 env;
	env.y = y;
	return env;
}

value_t lambda75(env_t_75* env72, number_t a) {
	number_t y71 = env72->y;
	value_t res;
	res.number_t_value = (a) * (y71);
	return res;
}
array_number_t linalg_mult_by_scalar(array_number_t x, number_t y) {
	env_t_75 env_t_75_value = make_env_t_75(y); closure_t closure74 = make_closure(lambda75, &env_t_75_value);
	return linalg_vectorMap(closure74, x);
}

array_number_t linalg_cross(array_number_t a, array_number_t b) {
	array_number_t array76 = (array_number_t)malloc(sizeof(int) * 2);
	array76->length=3;
	array76->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array76->arr[0] = ((a->arr[1]) * (b->arr[2])) - ((a->arr[2]) * (b->arr[1]));
	array76->arr[1] = ((a->arr[2]) * (b->arr[0])) - ((a->arr[0]) * (b->arr[2]));
	array76->arr[2] = ((a->arr[0]) * (b->arr[1])) - ((a->arr[1]) * (b->arr[0]));;
	return array76;
}
typedef empty_env_t env_t_80;


value_t lambda80(env_t_80* env77, number_t x, number_t y) {
	
	value_t res;
	res.number_t_value = (x) + (y);
	return res;
}
array_number_t linalg_add_vec(array_number_t x, array_number_t y) {
	env_t_80 env_t_80_value = make_empty_env(); closure_t closure79 = make_closure(lambda80, &env_t_80_value);
	return linalg_vectorMap2(closure79, x, y);
}
typedef empty_env_t env_t_84;


value_t lambda84(env_t_84* env81, number_t x, number_t y) {
	
	value_t res;
	res.number_t_value = (x) * (y);
	return res;
}
array_number_t linalg_mult_vec_elementwise(array_number_t x, array_number_t y) {
	env_t_84 env_t_84_value = make_empty_env(); closure_t closure83 = make_closure(lambda84, &env_t_84_value);
	return linalg_vectorMap2(closure83, x, y);
}

array_number_t linalg_add_vec3(array_number_t x, array_number_t y, array_number_t z) {
	
	return linalg_add_vec(linalg_add_vec(x, y), z);
}
typedef empty_env_t env_t_88;


value_t lambda88(env_t_88* env85, number_t x, number_t y) {
	
	value_t res;
	res.number_t_value = (x) - (y);
	return res;
}
array_number_t linalg_sub_vec(array_number_t x, array_number_t y) {
	env_t_88 env_t_88_value = make_empty_env(); closure_t closure87 = make_closure(lambda88, &env_t_88_value);
	return linalg_vectorMap2(closure87, x, y);
}
typedef empty_env_t env_t_92;


value_t lambda92(env_t_92* env89, array_number_t x, array_number_t y) {
	
	value_t res;
	res.array_number_t_value = linalg_add_vec(x, y);
	return res;
}
array_array_number_t linalg_matrixAdd(array_array_number_t x, array_array_number_t y) {
	env_t_92 env_t_92_value = make_empty_env(); closure_t closure91 = make_closure(lambda92, &env_t_92_value);
	return linalg_matrixMap2(closure91, x, y);
}
typedef empty_env_t env_t_96;


value_t lambda96(env_t_96* env93, array_number_t x, array_number_t y) {
	
	value_t res;
	res.array_number_t_value = linalg_mult_vec_elementwise(x, y);
	return res;
}
array_array_number_t linalg_matrixMultElementwise(array_array_number_t x, array_array_number_t y) {
	env_t_96 env_t_96_value = make_empty_env(); closure_t closure95 = make_closure(lambda96, &env_t_96_value);
	return linalg_matrixMap2(closure95, x, y);
}
typedef empty_env_t env_t_100;


value_t lambda100(env_t_100* env97, number_t x1) {
	
	value_t res;
	res.number_t_value = (x1) * (x1);
	return res;
}
number_t linalg_sqnorm(array_number_t x) {
	env_t_100 env_t_100_value = make_empty_env(); closure_t closure99 = make_closure(lambda100, &env_t_100_value);
	return linalg_arraySum(linalg_vectorMap(closure99, x));
}
typedef empty_env_t env_t_104;


value_t lambda104(env_t_104* env101, number_t x, number_t y) {
	
	value_t res;
	res.number_t_value = (x) * (y);
	return res;
}
number_t linalg_dot_prod(array_number_t x, array_number_t y) {
	env_t_104 env_t_104_value = make_empty_env(); closure_t closure103 = make_closure(lambda104, &env_t_104_value);
	return linalg_arraySum(linalg_vectorMap2(closure103, x, y));
}
typedef struct env_t_109 {
	array_number_t row;
} env_t_109;
env_t_109 make_env_t_109(array_number_t row) {
	env_t_109 env;
	env.row = row;
	return env;
}

value_t lambda109(env_t_109* env106, number_t r) {
	array_number_t row105 = env106->row;
	value_t res;
	res.array_number_t_value = row105;
	return res;
}
array_array_number_t linalg_matrixFillFromVector(card_t rows, array_number_t row) {
	env_t_109 env_t_109_value = make_env_t_109(row); closure_t closure108 = make_closure(lambda109, &env_t_109_value);
	return linalg_vectorMapToMatrix(closure108, linalg_vectorRange(1, rows));
}
typedef struct env_t_114 {
	number_t value;
} env_t_114;
env_t_114 make_env_t_114(number_t value) {
	env_t_114 env;
	env.value = value;
	return env;
}

value_t lambda114(env_t_114* env111, number_t c) {
	number_t value110 = env111->value;
	value_t res;
	res.number_t_value = value110;
	return res;
}
array_array_number_t linalg_matrixFill(card_t rows, card_t cols, number_t value) {
	env_t_114 env_t_114_value = make_env_t_114(value); closure_t closure113 = make_closure(lambda114, &env_t_114_value);
	array_number_t row = linalg_vectorMap(closure113, linalg_vectorRange(1, cols));
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
	array_number_t macroDef115 = (array_number_t)storage;
		for(int i = 0; i < macroDef115->length; i++){
			
			macroDef115->arr[i] = f.lam(f.env, v1->arr[i], v2->arr[i]).number_t_value;
		}
	return macroDef115;
}
typedef empty_env_t env_t_119;


value_t lambda119(env_t_119* env116, number_t x, number_t y) {
	
	value_t res;
	res.number_t_value = (x) + (y);
	return res;
}
array_number_t linalg_add_vecGivenStorage(storage_t s, array_number_t x, array_number_t y) {
	env_t_119 env_t_119_value = make_empty_env(); closure_t closure118 = make_closure(lambda119, &env_t_119_value);
	return linalg_vectorMap2GivenStorage(s, closure118, x, y);
}
#endif
