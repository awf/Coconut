#ifndef __LINALG_H__ 
#define __LINALG_H__ 
#include "runtime/fsharp.h"
#include <stdio.h>
#include <math.h>

card_t TOP_LEVEL_linalg_rows(array_array_number_t m) {
	card_t macroDef1 = m->length;
	return macroDef1;
}

card_t TOP_LEVEL_linalg_cols(array_array_number_t m) {
	card_t macroDef2 = m->arr[0]->length;
	return macroDef2;
}

array_number_t TOP_LEVEL_linalg_vectorMap(closure_t f, array_number_t v) {
	card_t macroDef3 = v->length;
	array_number_t macroDef4 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef4->length=macroDef3;
	macroDef4->arr = (number_t*)storage_alloc(sizeof(number_t) * macroDef3);
		for(int i = 0; i < macroDef4->length; i++){
			
			macroDef4->arr[i] = f.lam(f.env, v->arr[i]).number_t_value;;
		}
	return macroDef4;
}

array_number_t TOP_LEVEL_linalg_vectorRange(card_t s, card_t e) {
	array_number_t macroDef5 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef5->length=((e) - (s)) + (1);
	macroDef5->arr = (number_t*)storage_alloc(sizeof(number_t) * ((e) - (s)) + (1));
		for(int i = 0; i < macroDef5->length; i++){
			
			macroDef5->arr[i] = (double)(((s)) + (i));;
		}
	return macroDef5;
}

array_number_t TOP_LEVEL_linalg_vectorSlice(card_t size, index_t offset, array_number_t v) {
	array_number_t macroDef6 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef6->length=size;
	macroDef6->arr = (number_t*)storage_alloc(sizeof(number_t) * size);
		for(int i = 0; i < macroDef6->length; i++){
			
			macroDef6->arr[i] = v->arr[(i) + (offset)];;
		}
	return macroDef6;
}

array_array_number_t TOP_LEVEL_linalg_matrixSlice(card_t size, index_t offset, array_array_number_t m) {
	array_array_number_t macroDef7 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef7->length=size;
	macroDef7->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * size);
		for(int i = 0; i < macroDef7->length; i++){
			
			macroDef7->arr[i] = m->arr[(i) + (offset)];;
		}
	return macroDef7;
}

array_array_number_t TOP_LEVEL_linalg_matrixMap(closure_t f, array_array_number_t m) {
	card_t macroDef8 = m->length;
	array_array_number_t macroDef9 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef9->length=macroDef8;
	macroDef9->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * macroDef8);
		for(int i = 0; i < macroDef9->length; i++){
			
			macroDef9->arr[i] = f.lam(f.env, m->arr[i]).array_number_t_value;;
		}
	return macroDef9;
}

array_number_t TOP_LEVEL_linalg_matrixMapToVector(closure_t f, array_array_number_t m) {
	card_t macroDef10 = m->length;
	array_number_t macroDef11 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef11->length=macroDef10;
	macroDef11->arr = (number_t*)storage_alloc(sizeof(number_t) * macroDef10);
		for(int i = 0; i < macroDef11->length; i++){
			
			macroDef11->arr[i] = f.lam(f.env, m->arr[i]).number_t_value;;
		}
	return macroDef11;
}

array_number_t TOP_LEVEL_linalg_vectorMap2(closure_t f, array_number_t v1, array_number_t v2) {
	card_t macroDef12 = v1->length;
	array_number_t macroDef13 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef13->length=macroDef12;
	macroDef13->arr = (number_t*)storage_alloc(sizeof(number_t) * macroDef12);
		for(int i = 0; i < macroDef13->length; i++){
			
			macroDef13->arr[i] = f.lam(f.env, v1->arr[i], v2->arr[i]).number_t_value;;
		}
	return macroDef13;
}

array_array_number_t TOP_LEVEL_linalg_matrixMap2(closure_t f, array_array_number_t m1, array_array_number_t m2) {
	card_t macroDef14 = m1->length;
	array_array_number_t macroDef15 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef15->length=macroDef14;
	macroDef15->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * macroDef14);
		for(int i = 0; i < macroDef15->length; i++){
			
			macroDef15->arr[i] = f.lam(f.env, m1->arr[i], m2->arr[i]).array_number_t_value;;
		}
	return macroDef15;
}

array_array_array_number_t TOP_LEVEL_linalg_matrix3DMap2(closure_t f, array_array_array_number_t m1, array_array_array_number_t m2) {
	card_t macroDef16 = m1->length;
	array_array_array_number_t macroDef17 = (array_array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef17->length=macroDef16;
	macroDef17->arr = (array_array_number_t*)storage_alloc(sizeof(array_array_number_t) * macroDef16);
		for(int i = 0; i < macroDef17->length; i++){
			
			macroDef17->arr[i] = f.lam(f.env, m1->arr[i], m2->arr[i]).array_array_number_t_value;;
		}
	return macroDef17;
}

array_array_number_t TOP_LEVEL_linalg_vectorMapToMatrix(closure_t f, array_number_t arr) {
	card_t macroDef18 = arr->length;
	array_array_number_t macroDef19 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef19->length=macroDef18;
	macroDef19->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * macroDef18);
		for(int i = 0; i < macroDef19->length; i++){
			
			macroDef19->arr[i] = f.lam(f.env, arr->arr[i]).array_number_t_value;;
		}
	return macroDef19;
}

array_array_array_number_t TOP_LEVEL_linalg_vectorMapToMatrix3D(closure_t f, array_number_t arr) {
	card_t macroDef20 = arr->length;
	array_array_array_number_t macroDef21 = (array_array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef21->length=macroDef20;
	macroDef21->arr = (array_array_number_t*)storage_alloc(sizeof(array_array_number_t) * macroDef20);
		for(int i = 0; i < macroDef21->length; i++){
			
			macroDef21->arr[i] = f.lam(f.env, arr->arr[i]).array_array_number_t_value;;
		}
	return macroDef21;
}

number_t TOP_LEVEL_linalg_vectorSum(array_number_t v) {
	number_t macroDef22 = 0;
	for(int cur_idx = 0; cur_idx < v->length; cur_idx++){
		number_t cur = v->arr[cur_idx];
		
		macroDef22 = (macroDef22) + (cur);;
	}
	return macroDef22;
}

number_t TOP_LEVEL_linalg_vectorMax(array_number_t v) {
	number_t macroDef23 = -1000;
	for(int cur_idx = 0; cur_idx < v->length; cur_idx++){
		number_t cur = v->arr[cur_idx];
		number_t ite24 = 0;
	if((macroDef23) > (cur)) {
		
		ite24 = macroDef23;;
	} else {
		
		ite24 = cur;;
	}
		macroDef23 = ite24;;
	}
	return macroDef23;
}
typedef struct env_t_29 {
	number_t y;
} env_t_29;
env_t_29 make_env_t_29(number_t y) {
	env_t_29 env;
	env.y = y;
	return env;
}

value_t lambda29(env_t_29* env26, number_t xi) {
	number_t y25 = env26->y;
	value_t res;
	res.number_t_value = (xi) * (y25);
	return res;
}
array_number_t TOP_LEVEL_linalg_mult_by_scalar(array_number_t x, number_t y) {
	env_t_29 env_t_29_value = make_env_t_29(y); closure_t closure28 = make_closure(lambda29, &env_t_29_value);
	return TOP_LEVEL_linalg_vectorMap(closure28, x);
}
typedef struct env_t_35 {
	number_t y;
	number_t a;
} env_t_35;
env_t_35 make_env_t_35(number_t y,number_t a) {
	env_t_35 env;
	env.y = y;
	env.a = a;
	return env;
}

value_t lambda35(env_t_35* env32, number_t xi) {
	number_t y31 = env32->y;
	number_t a30 = env32->a;
	value_t res;
	res.number_t_value = ((a30) * (xi)) + (y31);
	return res;
}
array_number_t TOP_LEVEL_linalg_gaxpy(number_t a, array_number_t x, number_t y) {
	env_t_35 env_t_35_value = make_env_t_35(y,a); closure_t closure34 = make_closure(lambda35, &env_t_35_value);
	return TOP_LEVEL_linalg_vectorMap(closure34, x);
}

array_number_t TOP_LEVEL_linalg_cross(array_number_t a, array_number_t b) {
	array_number_t array36 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array36->length=3;
	array36->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array36->arr[0] = ((a->arr[1]) * (b->arr[2])) - ((a->arr[2]) * (b->arr[1]));
	array36->arr[1] = ((a->arr[2]) * (b->arr[0])) - ((a->arr[0]) * (b->arr[2]));
	array36->arr[2] = ((a->arr[0]) * (b->arr[1])) - ((a->arr[1]) * (b->arr[0]));;
	return array36;
}
typedef empty_env_t env_t_40;


value_t lambda40(env_t_40* env37, number_t x0, number_t y0) {
	
	value_t res;
	res.number_t_value = (x0) + (y0);
	return res;
}
array_number_t TOP_LEVEL_linalg_vectorAdd(array_number_t x, array_number_t y) {
	env_t_40 env_t_40_value = make_empty_env(); closure_t closure39 = make_closure(lambda40, &env_t_40_value);
	return TOP_LEVEL_linalg_vectorMap2(closure39, x, y);
}
typedef empty_env_t env_t_44;


value_t lambda44(env_t_44* env41, number_t x0, number_t y0) {
	
	value_t res;
	res.number_t_value = (x0) * (y0);
	return res;
}
array_number_t TOP_LEVEL_linalg_mult_vec_elementwise(array_number_t x, array_number_t y) {
	env_t_44 env_t_44_value = make_empty_env(); closure_t closure43 = make_closure(lambda44, &env_t_44_value);
	return TOP_LEVEL_linalg_vectorMap2(closure43, x, y);
}
typedef empty_env_t env_t_48;


value_t lambda48(env_t_48* env45, number_t x0, number_t y0) {
	
	value_t res;
	res.number_t_value = (x0) * (y0);
	return res;
}
array_number_t TOP_LEVEL_linalg_op_DotMultiply(array_number_t x, array_number_t y) {
	env_t_48 env_t_48_value = make_empty_env(); closure_t closure47 = make_closure(lambda48, &env_t_48_value);
	return TOP_LEVEL_linalg_vectorMap2(closure47, x, y);
}

array_number_t TOP_LEVEL_linalg_vectorAdd3(array_number_t x, array_number_t y, array_number_t z) {
	
	return TOP_LEVEL_linalg_vectorAdd(TOP_LEVEL_linalg_vectorAdd(x, y), z);
}
typedef empty_env_t env_t_52;


value_t lambda52(env_t_52* env49, number_t x0, number_t y0) {
	
	value_t res;
	res.number_t_value = (x0) - (y0);
	return res;
}
array_number_t TOP_LEVEL_linalg_vectorSub(array_number_t x, array_number_t y) {
	env_t_52 env_t_52_value = make_empty_env(); closure_t closure51 = make_closure(lambda52, &env_t_52_value);
	return TOP_LEVEL_linalg_vectorMap2(closure51, x, y);
}
typedef empty_env_t env_t_56;


value_t lambda56(env_t_56* env53, array_number_t x0, array_number_t y0) {
	
	value_t res;
	res.array_number_t_value = TOP_LEVEL_linalg_vectorAdd(x0, y0);
	return res;
}
array_array_number_t TOP_LEVEL_linalg_matrixAdd(array_array_number_t x, array_array_number_t y) {
	env_t_56 env_t_56_value = make_empty_env(); closure_t closure55 = make_closure(lambda56, &env_t_56_value);
	return TOP_LEVEL_linalg_matrixMap2(closure55, x, y);
}
typedef empty_env_t env_t_60;


value_t lambda60(env_t_60* env57, array_number_t x0, array_number_t y0) {
	
	value_t res;
	res.array_number_t_value = TOP_LEVEL_linalg_mult_vec_elementwise(x0, y0);
	return res;
}
array_array_number_t TOP_LEVEL_linalg_matrixMultElementwise(array_array_number_t x, array_array_number_t y) {
	env_t_60 env_t_60_value = make_empty_env(); closure_t closure59 = make_closure(lambda60, &env_t_60_value);
	return TOP_LEVEL_linalg_matrixMap2(closure59, x, y);
}
typedef empty_env_t env_t_64;


value_t lambda64(env_t_64* env61, number_t x1) {
	
	value_t res;
	res.number_t_value = (x1) * (x1);
	return res;
}
number_t TOP_LEVEL_linalg_sqnorm(array_number_t x) {
	env_t_64 env_t_64_value = make_empty_env(); closure_t closure63 = make_closure(lambda64, &env_t_64_value);
	return TOP_LEVEL_linalg_vectorSum(TOP_LEVEL_linalg_vectorMap(closure63, x));
}
typedef empty_env_t env_t_68;


value_t lambda68(env_t_68* env65, number_t x0, number_t y0) {
	
	value_t res;
	res.number_t_value = (x0) * (y0);
	return res;
}
number_t TOP_LEVEL_linalg_dot_prod(array_number_t x, array_number_t y) {
	env_t_68 env_t_68_value = make_empty_env(); closure_t closure67 = make_closure(lambda68, &env_t_68_value);
	return TOP_LEVEL_linalg_vectorSum(TOP_LEVEL_linalg_vectorMap2(closure67, x, y));
}
typedef struct env_t_73 {
	array_number_t row;
} env_t_73;
env_t_73 make_env_t_73(array_number_t row) {
	env_t_73 env;
	env.row = row;
	return env;
}

value_t lambda73(env_t_73* env70, number_t r) {
	array_number_t row69 = env70->row;
	value_t res;
	res.array_number_t_value = row69;
	return res;
}
array_array_number_t TOP_LEVEL_linalg_matrixFillFromVector(card_t rows, array_number_t row) {
	env_t_73 env_t_73_value = make_env_t_73(row); closure_t closure72 = make_closure(lambda73, &env_t_73_value);
	return TOP_LEVEL_linalg_vectorMapToMatrix(closure72, TOP_LEVEL_linalg_vectorRange(1, rows));
}

array_array_number_t TOP_LEVEL_linalg_matrixFill(card_t rows, card_t cols, number_t value) {
	array_array_number_t macroDef75 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef75->length=rows;
	macroDef75->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * rows);
		for(int r = 0; r < macroDef75->length; r++){
			array_number_t macroDef74 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef74->length=cols;
	macroDef74->arr = (number_t*)storage_alloc(sizeof(number_t) * cols);
		for(int c = 0; c < macroDef74->length; c++){
			
			macroDef74->arr[c] = value;;
		}
			macroDef75->arr[r] = macroDef74;;
		}
	return macroDef75;
}

array_array_number_t TOP_LEVEL_linalg_matrixTranspose(array_array_number_t m) {
	card_t macroDef76 = m->length;
	card_t rows = macroDef76;
	card_t macroDef77 = m->arr[0]->length;
	card_t cols = macroDef77;
	array_array_number_t macroDef79 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef79->length=cols;
	macroDef79->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * cols);
		for(int i = 0; i < macroDef79->length; i++){
			array_number_t macroDef78 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef78->length=rows;
	macroDef78->arr = (number_t*)storage_alloc(sizeof(number_t) * rows);
		for(int j = 0; j < macroDef78->length; j++){
			
			macroDef78->arr[j] = m->arr[j]->arr[i];;
		}
			macroDef79->arr[i] = macroDef78;;
		}
	return macroDef79;
}

array_array_number_t TOP_LEVEL_linalg_matrixMult(array_array_number_t m1, array_array_number_t m2) {
	card_t macroDef80 = m1->length;
	card_t r1 = macroDef80;
	card_t macroDef81 = m2->arr[0]->length;
	card_t c2 = macroDef81;
	card_t macroDef82 = m1->arr[0]->length;
	card_t c1 = macroDef82;
	card_t macroDef83 = m2->length;
	card_t r2 = macroDef83;
	array_array_number_t m2T = TOP_LEVEL_linalg_matrixTranspose(m2);
	array_array_number_t macroDef85 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef85->length=r1;
	macroDef85->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * r1);
		for(int r = 0; r < macroDef85->length; r++){
			array_number_t macroDef84 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef84->length=c2;
	macroDef84->arr = (number_t*)storage_alloc(sizeof(number_t) * c2);
		for(int c = 0; c < macroDef84->length; c++){
			
			macroDef84->arr[c] = TOP_LEVEL_linalg_dot_prod(m1->arr[r], m2T->arr[c]);;
		}
			macroDef85->arr[r] = macroDef84;;
		}
	return macroDef85;
}

array_number_t TOP_LEVEL_linalg_matrixVectorMult(array_array_number_t m, array_number_t v) {
	card_t r = TOP_LEVEL_linalg_rows(m);
	card_t c = TOP_LEVEL_linalg_cols(m);
	array_number_t macroDef86 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef86->length=r;
	macroDef86->arr = (number_t*)storage_alloc(sizeof(number_t) * r);
		for(int i = 0; i < macroDef86->length; i++){
			
			macroDef86->arr[i] = TOP_LEVEL_linalg_dot_prod(m->arr[i], v);;
		}
	return macroDef86;
}

array_array_number_t TOP_LEVEL_linalg_matrixConcat(array_array_number_t m1, array_array_number_t m2) {
	card_t macroDef87 = m1->length;
	card_t macroDef88 = m2->length;
	card_t rows = (macroDef87) + (macroDef88);
	card_t macroDef89 = m1->length;
	index_t m1Rows = (macroDef89);
	array_array_number_t macroDef90 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef90->length=rows;
	macroDef90->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * rows);
		for(int r = 0; r < macroDef90->length; r++){
			array_number_t ite91 = 0;
	if((r) < (m1Rows)) {
		
		ite91 = m1->arr[r];;
	} else {
		
		ite91 = m2->arr[(r) - (m1Rows)];;
	}
			macroDef90->arr[r] = ite91;;
		}
	return macroDef90;
}

array_array_number_t TOP_LEVEL_linalg_matrixConcatCol(array_array_number_t m1, array_array_number_t m2) {
	array_array_number_t m1t = TOP_LEVEL_linalg_matrixTranspose(m1);
	array_array_number_t m2t = TOP_LEVEL_linalg_matrixTranspose(m2);
	return TOP_LEVEL_linalg_matrixTranspose(TOP_LEVEL_linalg_matrixConcat(m1t, m2t));
}

array_array_array_number_t TOP_LEVEL_linalg_matrix3DConcat(array_array_array_number_t m1, array_array_array_number_t m2) {
	card_t macroDef92 = m1->length;
	card_t macroDef93 = m2->length;
	card_t rows = (macroDef92) + (macroDef93);
	card_t macroDef94 = m1->length;
	index_t m1Rows = (macroDef94);
	array_array_array_number_t macroDef95 = (array_array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef95->length=rows;
	macroDef95->arr = (array_array_number_t*)storage_alloc(sizeof(array_array_number_t) * rows);
		for(int r = 0; r < macroDef95->length; r++){
			array_array_number_t ite96 = 0;
	if((r) < (m1Rows)) {
		
		ite96 = m1->arr[r];;
	} else {
		
		ite96 = m2->arr[(r) - (m1Rows)];;
	}
			macroDef95->arr[r] = ite96;;
		}
	return macroDef95;
}

array_number_t TOP_LEVEL_linalg_vectorRead(string_t fn, index_t startLine, card_t cols) {
	array_array_number_t matrix = matrix_read(fn, startLine, 1, cols);
	return matrix->arr[0];
}

number_t TOP_LEVEL_linalg_numberRead(string_t fn, index_t startLine) {
	array_number_t vector = TOP_LEVEL_linalg_vectorRead(fn, startLine, 1);
	return vector->arr[0];
}

array_number_t TOP_LEVEL_linalg_vec3(number_t a, number_t b, number_t c) {
	array_number_t array97 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array97->length=3;
	array97->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array97->arr[0] = a;
	array97->arr[1] = b;
	array97->arr[2] = c;;
	return array97;
}
#endif
