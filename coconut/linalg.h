#ifndef __LINALG_H__ 
#define __LINALG_H__ 
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
}

array_number_t TOP_LEVEL_linalg_vectorRange(card_t s, card_t e) {
	array_number_t macroDef3 = (array_number_t)malloc(sizeof(int) * 2);
	macroDef3->length=((e) - (s)) + (1);
	macroDef3->arr = (number_t*)malloc(sizeof(number_t) * ((e) - (s)) + (1));
		for(int i = 0; i < macroDef3->length; i++){
			
			macroDef3->arr[i] = (double)(((s)) + (i));
		}
	return macroDef3;
}

array_number_t TOP_LEVEL_linalg_vectorSlice(card_t size, index_t offset, array_number_t v) {
	array_number_t macroDef4 = (array_number_t)malloc(sizeof(int) * 2);
	macroDef4->length=size;
	macroDef4->arr = (number_t*)malloc(sizeof(number_t) * size);
		for(int i = 0; i < macroDef4->length; i++){
			
			macroDef4->arr[i] = v->arr[(i) + (offset)];
		}
	return macroDef4;
}

array_array_number_t TOP_LEVEL_linalg_matrixMap(closure_t f, array_array_number_t m) {
	card_t macroDef5 = m->length;
	array_array_number_t macroDef6 = (array_array_number_t)malloc(sizeof(int) * 2);
	macroDef6->length=macroDef5;
	macroDef6->arr = (array_number_t*)malloc(sizeof(array_number_t) * macroDef5);
		for(int i = 0; i < macroDef6->length; i++){
			
			macroDef6->arr[i] = f.lam(f.env, m->arr[i]).array_number_t_value;
		}
	return macroDef6;
}

array_number_t TOP_LEVEL_linalg_vectorMap2(closure_t f, array_number_t v1, array_number_t v2) {
	card_t macroDef7 = v1->length;
	array_number_t macroDef8 = (array_number_t)malloc(sizeof(int) * 2);
	macroDef8->length=macroDef7;
	macroDef8->arr = (number_t*)malloc(sizeof(number_t) * macroDef7);
		for(int i = 0; i < macroDef8->length; i++){
			
			macroDef8->arr[i] = f.lam(f.env, v1->arr[i], v2->arr[i]).number_t_value;
		}
	return macroDef8;
}

array_array_number_t TOP_LEVEL_linalg_matrixMap2(closure_t f, array_array_number_t m1, array_array_number_t m2) {
	card_t macroDef9 = m1->length;
	array_array_number_t macroDef10 = (array_array_number_t)malloc(sizeof(int) * 2);
	macroDef10->length=macroDef9;
	macroDef10->arr = (array_number_t*)malloc(sizeof(array_number_t) * macroDef9);
		for(int i = 0; i < macroDef10->length; i++){
			
			macroDef10->arr[i] = f.lam(f.env, m1->arr[i], m2->arr[i]).array_number_t_value;
		}
	return macroDef10;
}

array_array_array_number_t TOP_LEVEL_linalg_matrix3DMap2(closure_t f, array_array_array_number_t m1, array_array_array_number_t m2) {
	card_t macroDef11 = m1->length;
	array_array_array_number_t macroDef12 = (array_array_array_number_t)malloc(sizeof(int) * 2);
	macroDef12->length=macroDef11;
	macroDef12->arr = (array_array_number_t*)malloc(sizeof(array_array_number_t) * macroDef11);
		for(int i = 0; i < macroDef12->length; i++){
			
			macroDef12->arr[i] = f.lam(f.env, m1->arr[i], m2->arr[i]).array_array_number_t_value;
		}
	return macroDef12;
}

array_array_number_t TOP_LEVEL_linalg_vectorMapToMatrix(closure_t f, array_number_t arr) {
	card_t macroDef13 = arr->length;
	array_array_number_t macroDef14 = (array_array_number_t)malloc(sizeof(int) * 2);
	macroDef14->length=macroDef13;
	macroDef14->arr = (array_number_t*)malloc(sizeof(array_number_t) * macroDef13);
		for(int i = 0; i < macroDef14->length; i++){
			
			macroDef14->arr[i] = f.lam(f.env, arr->arr[i]).array_number_t_value;
		}
	return macroDef14;
}

array_array_array_number_t TOP_LEVEL_linalg_vectorMapToMatrix3D(closure_t f, array_number_t arr) {
	card_t macroDef15 = arr->length;
	array_array_array_number_t macroDef16 = (array_array_array_number_t)malloc(sizeof(int) * 2);
	macroDef16->length=macroDef15;
	macroDef16->arr = (array_array_number_t*)malloc(sizeof(array_array_number_t) * macroDef15);
		for(int i = 0; i < macroDef16->length; i++){
			
			macroDef16->arr[i] = f.lam(f.env, arr->arr[i]).array_array_number_t_value;
		}
	return macroDef16;
}

number_t TOP_LEVEL_linalg_iterateNumber(closure_t f, number_t z, card_t s, card_t e) {
	number_t macroDef17 = z;
	for(int cur_idx = 0; cur_idx < TOP_LEVEL_linalg_vectorRange(s, e)->length; cur_idx++){
		number_t cur = TOP_LEVEL_linalg_vectorRange(s, e)->arr[cur_idx];
		
		macroDef17 = f.lam(f.env, macroDef17, (int)(cur)).number_t_value;
	}
	return macroDef17;
}

array_number_t TOP_LEVEL_linalg_iterateVector(closure_t f, array_number_t z, card_t s, card_t e) {
	array_number_t macroDef18 = z;
	for(int cur_idx = 0; cur_idx < TOP_LEVEL_linalg_vectorRange(s, e)->length; cur_idx++){
		number_t cur = TOP_LEVEL_linalg_vectorRange(s, e)->arr[cur_idx];
		
		macroDef18 = f.lam(f.env, macroDef18, (int)(cur)).array_number_t_value;
	}
	return macroDef18;
}

array_array_number_t TOP_LEVEL_linalg_iterateMatrix(closure_t f, array_array_number_t z, card_t s, card_t e) {
	array_array_number_t macroDef19 = z;
	for(int cur_idx = 0; cur_idx < TOP_LEVEL_linalg_vectorRange(s, e)->length; cur_idx++){
		number_t cur = TOP_LEVEL_linalg_vectorRange(s, e)->arr[cur_idx];
		
		macroDef19 = f.lam(f.env, macroDef19, (int)(cur)).array_array_number_t_value;
	}
	return macroDef19;
}

array_array_array_number_t TOP_LEVEL_linalg_iterateMatrix3D(closure_t f, array_array_array_number_t z, card_t s, card_t e) {
	array_array_array_number_t macroDef20 = z;
	for(int cur_idx = 0; cur_idx < TOP_LEVEL_linalg_vectorRange(s, e)->length; cur_idx++){
		number_t cur = TOP_LEVEL_linalg_vectorRange(s, e)->arr[cur_idx];
		
		macroDef20 = f.lam(f.env, macroDef20, (int)(cur)).array_array_array_number_t_value;
	}
	return macroDef20;
}

number_t TOP_LEVEL_linalg_arraySum(array_number_t arr) {
	number_t macroDef21 = 0;
	for(int cur_idx = 0; cur_idx < arr->length; cur_idx++){
		number_t cur = arr->arr[cur_idx];
		
		macroDef21 = (macroDef21) + (cur);
	}
	return macroDef21;
}

number_t TOP_LEVEL_linalg_arrayMax(array_number_t arr) {
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
array_number_t TOP_LEVEL_linalg_mult_by_scalar(array_number_t x, number_t y) {
	env_t_28 env_t_28_value = make_env_t_28(y); closure_t closure27 = make_closure(lambda28, &env_t_28_value);
	return TOP_LEVEL_linalg_vectorMap(closure27, x);
}

array_number_t TOP_LEVEL_linalg_cross(array_number_t a, array_number_t b) {
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
array_number_t TOP_LEVEL_linalg_add_vec(array_number_t x, array_number_t y) {
	env_t_33 env_t_33_value = make_empty_env(); closure_t closure32 = make_closure(lambda33, &env_t_33_value);
	return TOP_LEVEL_linalg_vectorMap2(closure32, x, y);
}
typedef empty_env_t env_t_37;


value_t lambda37(env_t_37* env34, number_t x, number_t y) {
	
	value_t res;
	res.number_t_value = (x) * (y);
	return res;
}
array_number_t TOP_LEVEL_linalg_mult_vec_elementwise(array_number_t x, array_number_t y) {
	env_t_37 env_t_37_value = make_empty_env(); closure_t closure36 = make_closure(lambda37, &env_t_37_value);
	return TOP_LEVEL_linalg_vectorMap2(closure36, x, y);
}

array_number_t TOP_LEVEL_linalg_add_vec3(array_number_t x, array_number_t y, array_number_t z) {
	
	return TOP_LEVEL_linalg_add_vec(TOP_LEVEL_linalg_add_vec(x, y), z);
}
typedef empty_env_t env_t_41;


value_t lambda41(env_t_41* env38, number_t x, number_t y) {
	
	value_t res;
	res.number_t_value = (x) - (y);
	return res;
}
array_number_t TOP_LEVEL_linalg_sub_vec(array_number_t x, array_number_t y) {
	env_t_41 env_t_41_value = make_empty_env(); closure_t closure40 = make_closure(lambda41, &env_t_41_value);
	return TOP_LEVEL_linalg_vectorMap2(closure40, x, y);
}
typedef empty_env_t env_t_45;


value_t lambda45(env_t_45* env42, array_number_t x, array_number_t y) {
	
	value_t res;
	res.array_number_t_value = TOP_LEVEL_linalg_add_vec(x, y);
	return res;
}
array_array_number_t TOP_LEVEL_linalg_matrixAdd(array_array_number_t x, array_array_number_t y) {
	env_t_45 env_t_45_value = make_empty_env(); closure_t closure44 = make_closure(lambda45, &env_t_45_value);
	return TOP_LEVEL_linalg_matrixMap2(closure44, x, y);
}
typedef empty_env_t env_t_49;


value_t lambda49(env_t_49* env46, array_number_t x, array_number_t y) {
	
	value_t res;
	res.array_number_t_value = TOP_LEVEL_linalg_mult_vec_elementwise(x, y);
	return res;
}
array_array_number_t TOP_LEVEL_linalg_matrixMultElementwise(array_array_number_t x, array_array_number_t y) {
	env_t_49 env_t_49_value = make_empty_env(); closure_t closure48 = make_closure(lambda49, &env_t_49_value);
	return TOP_LEVEL_linalg_matrixMap2(closure48, x, y);
}
typedef empty_env_t env_t_53;


value_t lambda53(env_t_53* env50, number_t x1) {
	
	value_t res;
	res.number_t_value = (x1) * (x1);
	return res;
}
number_t TOP_LEVEL_linalg_sqnorm(array_number_t x) {
	env_t_53 env_t_53_value = make_empty_env(); closure_t closure52 = make_closure(lambda53, &env_t_53_value);
	return TOP_LEVEL_linalg_arraySum(TOP_LEVEL_linalg_vectorMap(closure52, x));
}
typedef empty_env_t env_t_57;


value_t lambda57(env_t_57* env54, number_t x, number_t y) {
	
	value_t res;
	res.number_t_value = (x) * (y);
	return res;
}
number_t TOP_LEVEL_linalg_dot_prod(array_number_t x, array_number_t y) {
	env_t_57 env_t_57_value = make_empty_env(); closure_t closure56 = make_closure(lambda57, &env_t_57_value);
	return TOP_LEVEL_linalg_arraySum(TOP_LEVEL_linalg_vectorMap2(closure56, x, y));
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
array_array_number_t TOP_LEVEL_linalg_matrixFillFromVector(card_t rows, array_number_t row) {
	env_t_62 env_t_62_value = make_env_t_62(row); closure_t closure61 = make_closure(lambda62, &env_t_62_value);
	return TOP_LEVEL_linalg_vectorMapToMatrix(closure61, TOP_LEVEL_linalg_vectorRange(1, rows));
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
array_array_number_t TOP_LEVEL_linalg_matrixFill(card_t rows, card_t cols, number_t value) {
	env_t_67 env_t_67_value = make_env_t_67(value); closure_t closure66 = make_closure(lambda67, &env_t_67_value);
	array_number_t row = TOP_LEVEL_linalg_vectorMap(closure66, TOP_LEVEL_linalg_vectorRange(1, cols));
	return TOP_LEVEL_linalg_matrixFillFromVector(rows, row);
}

array_array_number_t TOP_LEVEL_linalg_matrixTranspose(array_array_number_t m) {
	card_t macroDef68 = m->length;
	card_t rows = macroDef68;
	card_t macroDef69 = m->arr[0]->length;
	card_t cols = macroDef69;
	array_array_number_t macroDef71 = (array_array_number_t)malloc(sizeof(int) * 2);
	macroDef71->length=cols;
	macroDef71->arr = (array_number_t*)malloc(sizeof(array_number_t) * cols);
		for(int i = 0; i < macroDef71->length; i++){
			array_number_t macroDef70 = (array_number_t)malloc(sizeof(int) * 2);
	macroDef70->length=rows;
	macroDef70->arr = (number_t*)malloc(sizeof(number_t) * rows);
		for(int j = 0; j < macroDef70->length; j++){
			
			macroDef70->arr[j] = m->arr[j]->arr[i];
		}
			macroDef71->arr[i] = macroDef70;
		}
	return macroDef71;
}
typedef empty_env_t env_t_81;


value_t lambda81(env_t_81* env76, number_t x, number_t y) {
	
	value_t res;
	res.number_t_value = (x) * (y);
	return res;
}
array_array_number_t TOP_LEVEL_linalg_matrixMult(array_array_number_t m1, array_array_number_t m2) {
	card_t macroDef72 = m1->length;
	card_t r1 = macroDef72;
	card_t macroDef73 = m2->arr[0]->length;
	card_t c2 = macroDef73;
	card_t macroDef74 = m1->arr[0]->length;
	card_t c1 = macroDef74;
	card_t macroDef75 = m2->length;
	card_t r2 = macroDef75;
	array_array_number_t m2T = TOP_LEVEL_linalg_matrixTranspose(m2);
	array_array_number_t macroDef80 = (array_array_number_t)malloc(sizeof(int) * 2);
	macroDef80->length=r1;
	macroDef80->arr = (array_number_t*)malloc(sizeof(array_number_t) * r1);
		for(int r = 0; r < macroDef80->length; r++){
			array_number_t macroDef79 = (array_number_t)malloc(sizeof(int) * 2);
	macroDef79->length=c2;
	macroDef79->arr = (number_t*)malloc(sizeof(number_t) * c2);
		for(int c = 0; c < macroDef79->length; c++){
			env_t_81 env_t_81_value = make_empty_env(); closure_t closure78 = make_closure(lambda81, &env_t_81_value);
			macroDef79->arr[c] = TOP_LEVEL_linalg_arraySum(TOP_LEVEL_linalg_vectorMap2(closure78, m1->arr[r], m2T->arr[c]));
		}
			macroDef80->arr[r] = macroDef79;
		}
	return macroDef80;
}

array_array_number_t TOP_LEVEL_linalg_matrixConcat(array_array_number_t m1, array_array_number_t m2) {
	card_t macroDef82 = m1->length;
	card_t macroDef83 = m2->length;
	card_t rows = (macroDef82) + (macroDef83);
	card_t macroDef84 = m1->length;
	index_t m1Rows = (macroDef84);
	array_array_number_t macroDef85 = (array_array_number_t)malloc(sizeof(int) * 2);
	macroDef85->length=rows;
	macroDef85->arr = (array_number_t*)malloc(sizeof(array_number_t) * rows);
		for(int r = 0; r < macroDef85->length; r++){
			array_number_t ite86 = 0;
	if((r) < (m1Rows)) {
		
		ite86 = m1->arr[r];
	} else {
		
		ite86 = m2->arr[(r) - (m1Rows)];
	}
			macroDef85->arr[r] = ite86;
		}
	return macroDef85;
}

array_array_number_t TOP_LEVEL_linalg_matrixConcatCol(array_array_number_t m1, array_array_number_t m2) {
	array_array_number_t m1t = TOP_LEVEL_linalg_matrixTranspose(m1);
	array_array_number_t m2t = TOP_LEVEL_linalg_matrixTranspose(m2);
	return TOP_LEVEL_linalg_matrixTranspose(TOP_LEVEL_linalg_matrixConcat(m1t, m2t));
}

array_array_array_number_t TOP_LEVEL_linalg_matrix3DConcat(array_array_array_number_t m1, array_array_array_number_t m2) {
	card_t macroDef87 = m1->length;
	card_t macroDef88 = m2->length;
	card_t rows = (macroDef87) + (macroDef88);
	card_t macroDef89 = m1->length;
	index_t m1Rows = (macroDef89);
	array_array_array_number_t macroDef90 = (array_array_array_number_t)malloc(sizeof(int) * 2);
	macroDef90->length=rows;
	macroDef90->arr = (array_array_number_t*)malloc(sizeof(array_array_number_t) * rows);
		for(int r = 0; r < macroDef90->length; r++){
			array_array_number_t ite91 = 0;
	if((r) < (m1Rows)) {
		
		ite91 = m1->arr[r];
	} else {
		
		ite91 = m2->arr[(r) - (m1Rows)];
	}
			macroDef90->arr[r] = ite91;
		}
	return macroDef90;
}

array_number_t TOP_LEVEL_linalg_vectorRead(string_t fn, index_t startLine) {
	array_array_number_t matrix = matrix_read(fn, startLine, 1);
	return matrix->arr[0];
}

number_t TOP_LEVEL_linalg_numberRead(string_t fn, index_t startLine) {
	array_number_t vector = TOP_LEVEL_linalg_vectorRead(fn, startLine);
	return vector->arr[0];
}

array_number_t TOP_LEVEL_linalg_vectorMap2GivenStorage(storage_t storage, closure_t f, array_number_t v1, array_number_t v2) {
	array_number_t macroDef92 = (array_number_t)storage;
		for(int i = 0; i < macroDef92->length; i++){
			
			macroDef92->arr[i] = f.lam(f.env, v1->arr[i], v2->arr[i]).number_t_value;
		}
	return macroDef92;
}
typedef empty_env_t env_t_96;


value_t lambda96(env_t_96* env93, number_t x, number_t y) {
	
	value_t res;
	res.number_t_value = (x) + (y);
	return res;
}
array_number_t TOP_LEVEL_linalg_add_vecGivenStorage(storage_t s, array_number_t x, array_number_t y) {
	env_t_96 env_t_96_value = make_empty_env(); closure_t closure95 = make_closure(lambda96, &env_t_96_value);
	return TOP_LEVEL_linalg_vectorMap2GivenStorage(s, closure95, x, y);
}
#endif
