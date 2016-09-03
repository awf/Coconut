#ifndef __LINALG_H__ 
#define __LINALG_H__ 
#include "runtime/fsharp.h"
#include <stdio.h>
#include <math.h>

array_number_t linalg_vectorMap(closure_t f, array_number_t v) {
	card_t macroDef1 = v->length;
	array_number_t macroDef2 = (array_number_t)malloc(sizeof(int) * 2);
	macroDef2->length=macroDef1;
	macroDef2->arr = (number_t*)malloc(sizeof(number_t) * macroDef1);
		for(int i = 0; i < macroDef2->length; i++){
			
			macroDef2->arr[i] = f.lam(f.env, v->arr[i]).number_t_value;
		}
	return macroDef2;
}

array_number_t linalg_vectorRange(card_t s, card_t e) {
	array_number_t macroDef3 = (array_number_t)malloc(sizeof(int) * 2);
	macroDef3->length=((e) - (s)) + (1);
	macroDef3->arr = (number_t*)malloc(sizeof(number_t) * ((e) - (s)) + (1));
		for(int i = 0; i < macroDef3->length; i++){
			
			macroDef3->arr[i] = (double)(((s)) + (i));
		}
	return macroDef3;
}

array_number_t linalg_vectorSlice(card_t size, index_t offset, array_number_t v) {
	array_number_t macroDef4 = (array_number_t)malloc(sizeof(int) * 2);
	macroDef4->length=size;
	macroDef4->arr = (number_t*)malloc(sizeof(number_t) * size);
		for(int i = 0; i < macroDef4->length; i++){
			
			macroDef4->arr[i] = v->arr[(i) + (offset)];
		}
	return macroDef4;
}

array_array_number_t linalg_matrixMap(closure_t f, array_array_number_t m) {
	card_t macroDef5 = m->length;
	array_array_number_t macroDef6 = (array_array_number_t)malloc(sizeof(int) * 2);
	macroDef6->length=macroDef5;
	macroDef6->arr = (array_number_t*)malloc(sizeof(array_number_t) * macroDef5);
		for(int i = 0; i < macroDef6->length; i++){
			
			macroDef6->arr[i] = f.lam(f.env, m->arr[i]).array_number_t_value;
		}
	return macroDef6;
}

array_number_t linalg_vectorMap2(closure_t f, array_number_t v1, array_number_t v2) {
	card_t macroDef7 = v1->length;
	array_number_t macroDef8 = (array_number_t)malloc(sizeof(int) * 2);
	macroDef8->length=macroDef7;
	macroDef8->arr = (number_t*)malloc(sizeof(number_t) * macroDef7);
		for(int i = 0; i < macroDef8->length; i++){
			
			macroDef8->arr[i] = f.lam(f.env, v1->arr[i], v2->arr[i]).number_t_value;
		}
	return macroDef8;
}

array_array_number_t linalg_matrixMap2(closure_t f, array_array_number_t m1, array_array_number_t m2) {
	card_t macroDef9 = m1->length;
	array_array_number_t macroDef10 = (array_array_number_t)malloc(sizeof(int) * 2);
	macroDef10->length=macroDef9;
	macroDef10->arr = (array_number_t*)malloc(sizeof(array_number_t) * macroDef9);
		for(int i = 0; i < macroDef10->length; i++){
			
			macroDef10->arr[i] = f.lam(f.env, m1->arr[i], m2->arr[i]).array_number_t_value;
		}
	return macroDef10;
}

array_array_array_number_t linalg_matrix3DMap2(closure_t f, array_array_array_number_t m1, array_array_array_number_t m2) {
	card_t macroDef11 = m1->length;
	array_array_array_number_t macroDef12 = (array_array_array_number_t)malloc(sizeof(int) * 2);
	macroDef12->length=macroDef11;
	macroDef12->arr = (array_array_number_t*)malloc(sizeof(array_array_number_t) * macroDef11);
		for(int i = 0; i < macroDef12->length; i++){
			
			macroDef12->arr[i] = f.lam(f.env, m1->arr[i], m2->arr[i]).array_array_number_t_value;
		}
	return macroDef12;
}

array_array_number_t linalg_vectorMapToMatrix(closure_t f, array_number_t arr) {
	card_t macroDef13 = arr->length;
	array_array_number_t macroDef14 = (array_array_number_t)malloc(sizeof(int) * 2);
	macroDef14->length=macroDef13;
	macroDef14->arr = (array_number_t*)malloc(sizeof(array_number_t) * macroDef13);
		for(int i = 0; i < macroDef14->length; i++){
			
			macroDef14->arr[i] = f.lam(f.env, arr->arr[i]).array_number_t_value;
		}
	return macroDef14;
}

array_array_array_number_t linalg_vectorMapToMatrix3D(closure_t f, array_number_t arr) {
	card_t macroDef15 = arr->length;
	array_array_array_number_t macroDef16 = (array_array_array_number_t)malloc(sizeof(int) * 2);
	macroDef16->length=macroDef15;
	macroDef16->arr = (array_array_number_t*)malloc(sizeof(array_array_number_t) * macroDef15);
		for(int i = 0; i < macroDef16->length; i++){
			
			macroDef16->arr[i] = f.lam(f.env, arr->arr[i]).array_array_number_t_value;
		}
	return macroDef16;
}

number_t linalg_iterateNumber(closure_t f, number_t z, card_t s, card_t e) {
	number_t macroDef17 = z;
	for(int cur_idx = 0; cur_idx < linalg_vectorRange(s, e)->length; cur_idx++){
		number_t cur = linalg_vectorRange(s, e)->arr[cur_idx];
		
		macroDef17 = f.lam(f.env, macroDef17, (int)(cur)).number_t_value;
	}
	return macroDef17;
}

array_number_t linalg_iterateVector(closure_t f, array_number_t z, card_t s, card_t e) {
	array_number_t macroDef18 = z;
	for(int cur_idx = 0; cur_idx < linalg_vectorRange(s, e)->length; cur_idx++){
		number_t cur = linalg_vectorRange(s, e)->arr[cur_idx];
		
		macroDef18 = f.lam(f.env, macroDef18, (int)(cur)).array_number_t_value;
	}
	return macroDef18;
}

array_array_number_t linalg_iterateMatrix(closure_t f, array_array_number_t z, card_t s, card_t e) {
	array_array_number_t macroDef19 = z;
	for(int cur_idx = 0; cur_idx < linalg_vectorRange(s, e)->length; cur_idx++){
		number_t cur = linalg_vectorRange(s, e)->arr[cur_idx];
		
		macroDef19 = f.lam(f.env, macroDef19, (int)(cur)).array_array_number_t_value;
	}
	return macroDef19;
}

array_array_array_number_t linalg_iterateMatrix3D(closure_t f, array_array_array_number_t z, card_t s, card_t e) {
	array_array_array_number_t macroDef20 = z;
	for(int cur_idx = 0; cur_idx < linalg_vectorRange(s, e)->length; cur_idx++){
		number_t cur = linalg_vectorRange(s, e)->arr[cur_idx];
		
		macroDef20 = f.lam(f.env, macroDef20, (int)(cur)).array_array_array_number_t_value;
	}
	return macroDef20;
}

number_t linalg_arraySum(array_number_t arr) {
	number_t macroDef21 = 0;
	for(int cur_idx = 0; cur_idx < arr->length; cur_idx++){
		number_t cur = arr->arr[cur_idx];
		
		macroDef21 = (macroDef21) + (cur);
	}
	return macroDef21;
}

number_t linalg_arrayMax(array_number_t arr) {
	number_t macroDef22 = -1000;
	for(int cur_idx = 0; cur_idx < arr->length; cur_idx++){
		number_t cur = arr->arr[cur_idx];
		number_t ite23 = 0;
	if((macroDef22) > (cur)) {
		
		ite23 = macroDef22;
	} else {
		
		ite23 = cur;
	}
		macroDef22 = ite23;
	}
	return macroDef22;
}
typedef struct env_t_28 {
	number_t y;
} env_t_28;
env_t_28 make_env_t_28(number_t y) {
	env_t_28 env;
	env.y = y;
	return env;
}

value_t lambda28(env_t_28* env25, number_t a) {
	number_t y24 = env25->y;
	value_t res;
	res.number_t_value = (a) * (y24);
	return res;
}
array_number_t linalg_mult_by_scalar(array_number_t x, number_t y) {
	env_t_28 env_t_28_value = make_env_t_28(y); closure_t closure27 = make_closure(lambda28, &env_t_28_value);
	return linalg_vectorMap(closure27, x);
}

array_number_t linalg_cross(array_number_t a, array_number_t b) {
	array_number_t array29 = (array_number_t)malloc(sizeof(int) * 2);
	array29->length=3;
	array29->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array29->arr[0] = ((a->arr[1]) * (b->arr[2])) - ((a->arr[2]) * (b->arr[1]));
	array29->arr[1] = ((a->arr[2]) * (b->arr[0])) - ((a->arr[0]) * (b->arr[2]));
	array29->arr[2] = ((a->arr[0]) * (b->arr[1])) - ((a->arr[1]) * (b->arr[0]));;
	return array29;
}
typedef empty_env_t env_t_33;


value_t lambda33(env_t_33* env30, number_t x, number_t y) {
	
	value_t res;
	res.number_t_value = (x) + (y);
	return res;
}
array_number_t linalg_add_vec(array_number_t x, array_number_t y) {
	env_t_33 env_t_33_value = make_empty_env(); closure_t closure32 = make_closure(lambda33, &env_t_33_value);
	return linalg_vectorMap2(closure32, x, y);
}
typedef empty_env_t env_t_37;


value_t lambda37(env_t_37* env34, number_t x, number_t y) {
	
	value_t res;
	res.number_t_value = (x) * (y);
	return res;
}
array_number_t linalg_mult_vec_elementwise(array_number_t x, array_number_t y) {
	env_t_37 env_t_37_value = make_empty_env(); closure_t closure36 = make_closure(lambda37, &env_t_37_value);
	return linalg_vectorMap2(closure36, x, y);
}

array_number_t linalg_add_vec3(array_number_t x, array_number_t y, array_number_t z) {
	
	return linalg_add_vec(linalg_add_vec(x, y), z);
}
typedef empty_env_t env_t_41;


value_t lambda41(env_t_41* env38, number_t x, number_t y) {
	
	value_t res;
	res.number_t_value = (x) - (y);
	return res;
}
array_number_t linalg_sub_vec(array_number_t x, array_number_t y) {
	env_t_41 env_t_41_value = make_empty_env(); closure_t closure40 = make_closure(lambda41, &env_t_41_value);
	return linalg_vectorMap2(closure40, x, y);
}
typedef empty_env_t env_t_45;


value_t lambda45(env_t_45* env42, array_number_t x, array_number_t y) {
	
	value_t res;
	res.array_number_t_value = linalg_add_vec(x, y);
	return res;
}
array_array_number_t linalg_matrixAdd(array_array_number_t x, array_array_number_t y) {
	env_t_45 env_t_45_value = make_empty_env(); closure_t closure44 = make_closure(lambda45, &env_t_45_value);
	return linalg_matrixMap2(closure44, x, y);
}
typedef empty_env_t env_t_49;


value_t lambda49(env_t_49* env46, array_number_t x, array_number_t y) {
	
	value_t res;
	res.array_number_t_value = linalg_mult_vec_elementwise(x, y);
	return res;
}
array_array_number_t linalg_matrixMultElementwise(array_array_number_t x, array_array_number_t y) {
	env_t_49 env_t_49_value = make_empty_env(); closure_t closure48 = make_closure(lambda49, &env_t_49_value);
	return linalg_matrixMap2(closure48, x, y);
}
typedef empty_env_t env_t_53;


value_t lambda53(env_t_53* env50, number_t x1) {
	
	value_t res;
	res.number_t_value = (x1) * (x1);
	return res;
}
number_t linalg_sqnorm(array_number_t x) {
	env_t_53 env_t_53_value = make_empty_env(); closure_t closure52 = make_closure(lambda53, &env_t_53_value);
	return linalg_arraySum(linalg_vectorMap(closure52, x));
}
typedef empty_env_t env_t_57;


value_t lambda57(env_t_57* env54, number_t x, number_t y) {
	
	value_t res;
	res.number_t_value = (x) * (y);
	return res;
}
number_t linalg_dot_prod(array_number_t x, array_number_t y) {
	env_t_57 env_t_57_value = make_empty_env(); closure_t closure56 = make_closure(lambda57, &env_t_57_value);
	return linalg_arraySum(linalg_vectorMap2(closure56, x, y));
}
typedef struct env_t_62 {
	array_number_t row;
} env_t_62;
env_t_62 make_env_t_62(array_number_t row) {
	env_t_62 env;
	env.row = row;
	return env;
}

value_t lambda62(env_t_62* env59, number_t r) {
	array_number_t row58 = env59->row;
	value_t res;
	res.array_number_t_value = row58;
	return res;
}
array_array_number_t linalg_matrixFillFromVector(card_t rows, array_number_t row) {
	env_t_62 env_t_62_value = make_env_t_62(row); closure_t closure61 = make_closure(lambda62, &env_t_62_value);
	return linalg_vectorMapToMatrix(closure61, linalg_vectorRange(1, rows));
}
typedef struct env_t_67 {
	number_t value;
} env_t_67;
env_t_67 make_env_t_67(number_t value) {
	env_t_67 env;
	env.value = value;
	return env;
}

value_t lambda67(env_t_67* env64, number_t c) {
	number_t value63 = env64->value;
	value_t res;
	res.number_t_value = value63;
	return res;
}
array_array_number_t linalg_matrixFill(card_t rows, card_t cols, number_t value) {
	env_t_67 env_t_67_value = make_env_t_67(value); closure_t closure66 = make_closure(lambda67, &env_t_67_value);
	array_number_t row = linalg_vectorMap(closure66, linalg_vectorRange(1, cols));
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
	array_number_t macroDef68 = (array_number_t)storage;
		for(int i = 0; i < macroDef68->length; i++){
			
			macroDef68->arr[i] = f.lam(f.env, v1->arr[i], v2->arr[i]).number_t_value;
		}
	return macroDef68;
}
typedef empty_env_t env_t_72;


value_t lambda72(env_t_72* env69, number_t x, number_t y) {
	
	value_t res;
	res.number_t_value = (x) + (y);
	return res;
}
array_number_t linalg_add_vecGivenStorage(storage_t s, array_number_t x, array_number_t y) {
	env_t_72 env_t_72_value = make_empty_env(); closure_t closure71 = make_closure(lambda72, &env_t_72_value);
	return linalg_vectorMap2GivenStorage(s, closure71, x, y);
}
#endif
