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

number_t TOP_LEVEL_linalg_iterateNumber(closure_t f, number_t z, card_t s, card_t e) {
	number_t macroDef22 = z;
	for(int cur_idx = 0; cur_idx < TOP_LEVEL_linalg_vectorRange(s, e)->length; cur_idx++){
		number_t cur = TOP_LEVEL_linalg_vectorRange(s, e)->arr[cur_idx];
		
		macroDef22 = f.lam(f.env, macroDef22, (int)(cur)).number_t_value;;
	}
	return macroDef22;
}

array_number_t TOP_LEVEL_linalg_iterateVector(closure_t f, array_number_t z, card_t s, card_t e) {
	array_number_t macroDef23 = z;
	for(int cur_idx = 0; cur_idx < TOP_LEVEL_linalg_vectorRange(s, e)->length; cur_idx++){
		number_t cur = TOP_LEVEL_linalg_vectorRange(s, e)->arr[cur_idx];
		
		macroDef23 = f.lam(f.env, macroDef23, (int)(cur)).array_number_t_value;;
	}
	return macroDef23;
}

array_array_number_t TOP_LEVEL_linalg_iterateMatrix(closure_t f, array_array_number_t z, card_t s, card_t e) {
	array_array_number_t macroDef24 = z;
	for(int cur_idx = 0; cur_idx < TOP_LEVEL_linalg_vectorRange(s, e)->length; cur_idx++){
		number_t cur = TOP_LEVEL_linalg_vectorRange(s, e)->arr[cur_idx];
		
		macroDef24 = f.lam(f.env, macroDef24, (int)(cur)).array_array_number_t_value;;
	}
	return macroDef24;
}

array_array_array_number_t TOP_LEVEL_linalg_iterateMatrix3D(closure_t f, array_array_array_number_t z, card_t s, card_t e) {
	array_array_array_number_t macroDef25 = z;
	for(int cur_idx = 0; cur_idx < TOP_LEVEL_linalg_vectorRange(s, e)->length; cur_idx++){
		number_t cur = TOP_LEVEL_linalg_vectorRange(s, e)->arr[cur_idx];
		
		macroDef25 = f.lam(f.env, macroDef25, (int)(cur)).array_array_array_number_t_value;;
	}
	return macroDef25;
}

number_t TOP_LEVEL_linalg_vectorSum(array_number_t v) {
	number_t macroDef26 = 0;
	for(int cur_idx = 0; cur_idx < v->length; cur_idx++){
		number_t cur = v->arr[cur_idx];
		
		macroDef26 = (macroDef26) + (cur);;
	}
	return macroDef26;
}

number_t TOP_LEVEL_linalg_vectorMax(array_number_t v) {
	number_t macroDef27 = -1000;
	for(int cur_idx = 0; cur_idx < v->length; cur_idx++){
		number_t cur = v->arr[cur_idx];
		number_t ite28 = 0;
	if((macroDef27) > (cur)) {
		
		ite28 = macroDef27;;
	} else {
		
		ite28 = cur;;
	}
		macroDef27 = ite28;;
	}
	return macroDef27;
}
typedef struct env_t_33 {
	number_t y;
} env_t_33;
env_t_33 make_env_t_33(number_t y) {
	env_t_33 env;
	env.y = y;
	return env;
}

value_t lambda33(env_t_33* env30, number_t xi) {
	number_t y29 = env30->y;
	value_t res;
	res.number_t_value = (xi) * (y29);
	return res;
}
array_number_t TOP_LEVEL_linalg_mult_by_scalar(array_number_t x, number_t y) {
	env_t_33 env_t_33_value = make_env_t_33(y); closure_t closure32 = make_closure(lambda33, &env_t_33_value);
	return TOP_LEVEL_linalg_vectorMap(closure32, x);
}
typedef struct env_t_39 {
	number_t y;
	number_t a;
} env_t_39;
env_t_39 make_env_t_39(number_t y,number_t a) {
	env_t_39 env;
	env.y = y;
	env.a = a;
	return env;
}

value_t lambda39(env_t_39* env36, number_t xi) {
	number_t y35 = env36->y;
	number_t a34 = env36->a;
	value_t res;
	res.number_t_value = ((a34) * (xi)) + (y35);
	return res;
}
array_number_t TOP_LEVEL_linalg_gaxpy(number_t a, array_number_t x, number_t y) {
	env_t_39 env_t_39_value = make_env_t_39(y,a); closure_t closure38 = make_closure(lambda39, &env_t_39_value);
	return TOP_LEVEL_linalg_vectorMap(closure38, x);
}

array_number_t TOP_LEVEL_linalg_cross(array_number_t a, array_number_t b) {
	array_number_t array40 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array40->length=3;
	array40->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array40->arr[0] = ((a->arr[1]) * (b->arr[2])) - ((a->arr[2]) * (b->arr[1]));
	array40->arr[1] = ((a->arr[2]) * (b->arr[0])) - ((a->arr[0]) * (b->arr[2]));
	array40->arr[2] = ((a->arr[0]) * (b->arr[1])) - ((a->arr[1]) * (b->arr[0]));;
	return array40;
}
typedef empty_env_t env_t_44;


value_t lambda44(env_t_44* env41, number_t x0, number_t y0) {
	
	value_t res;
	res.number_t_value = (x0) + (y0);
	return res;
}
array_number_t TOP_LEVEL_linalg_vectorAdd(array_number_t x, array_number_t y) {
	env_t_44 env_t_44_value = make_empty_env(); closure_t closure43 = make_closure(lambda44, &env_t_44_value);
	return TOP_LEVEL_linalg_vectorMap2(closure43, x, y);
}
typedef empty_env_t env_t_48;


value_t lambda48(env_t_48* env45, number_t x0, number_t y0) {
	
	value_t res;
	res.number_t_value = (x0) * (y0);
	return res;
}
array_number_t TOP_LEVEL_linalg_mult_vec_elementwise(array_number_t x, array_number_t y) {
	env_t_48 env_t_48_value = make_empty_env(); closure_t closure47 = make_closure(lambda48, &env_t_48_value);
	return TOP_LEVEL_linalg_vectorMap2(closure47, x, y);
}
typedef empty_env_t env_t_52;


value_t lambda52(env_t_52* env49, number_t x0, number_t y0) {
	
	value_t res;
	res.number_t_value = (x0) * (y0);
	return res;
}
array_number_t TOP_LEVEL_linalg_op_DotMultiply(array_number_t x, array_number_t y) {
	env_t_52 env_t_52_value = make_empty_env(); closure_t closure51 = make_closure(lambda52, &env_t_52_value);
	return TOP_LEVEL_linalg_vectorMap2(closure51, x, y);
}

array_number_t TOP_LEVEL_linalg_vectorAdd3(array_number_t x, array_number_t y, array_number_t z) {
	
	return TOP_LEVEL_linalg_vectorAdd(TOP_LEVEL_linalg_vectorAdd(x, y), z);
}
typedef empty_env_t env_t_56;


value_t lambda56(env_t_56* env53, number_t x0, number_t y0) {
	
	value_t res;
	res.number_t_value = (x0) - (y0);
	return res;
}
array_number_t TOP_LEVEL_linalg_vectorSub(array_number_t x, array_number_t y) {
	env_t_56 env_t_56_value = make_empty_env(); closure_t closure55 = make_closure(lambda56, &env_t_56_value);
	return TOP_LEVEL_linalg_vectorMap2(closure55, x, y);
}
typedef empty_env_t env_t_60;


value_t lambda60(env_t_60* env57, array_number_t x0, array_number_t y0) {
	
	value_t res;
	res.array_number_t_value = TOP_LEVEL_linalg_vectorAdd(x0, y0);
	return res;
}
array_array_number_t TOP_LEVEL_linalg_matrixAdd(array_array_number_t x, array_array_number_t y) {
	env_t_60 env_t_60_value = make_empty_env(); closure_t closure59 = make_closure(lambda60, &env_t_60_value);
	return TOP_LEVEL_linalg_matrixMap2(closure59, x, y);
}
typedef empty_env_t env_t_64;


value_t lambda64(env_t_64* env61, array_number_t x0, array_number_t y0) {
	
	value_t res;
	res.array_number_t_value = TOP_LEVEL_linalg_mult_vec_elementwise(x0, y0);
	return res;
}
array_array_number_t TOP_LEVEL_linalg_matrixMultElementwise(array_array_number_t x, array_array_number_t y) {
	env_t_64 env_t_64_value = make_empty_env(); closure_t closure63 = make_closure(lambda64, &env_t_64_value);
	return TOP_LEVEL_linalg_matrixMap2(closure63, x, y);
}
typedef empty_env_t env_t_68;


value_t lambda68(env_t_68* env65, number_t x1) {
	
	value_t res;
	res.number_t_value = (x1) * (x1);
	return res;
}
number_t TOP_LEVEL_linalg_sqnorm(array_number_t x) {
	env_t_68 env_t_68_value = make_empty_env(); closure_t closure67 = make_closure(lambda68, &env_t_68_value);
	return TOP_LEVEL_linalg_vectorSum(TOP_LEVEL_linalg_vectorMap(closure67, x));
}
typedef empty_env_t env_t_72;


value_t lambda72(env_t_72* env69, number_t x0, number_t y0) {
	
	value_t res;
	res.number_t_value = (x0) * (y0);
	return res;
}
number_t TOP_LEVEL_linalg_dot_prod(array_number_t x, array_number_t y) {
	env_t_72 env_t_72_value = make_empty_env(); closure_t closure71 = make_closure(lambda72, &env_t_72_value);
	return TOP_LEVEL_linalg_vectorSum(TOP_LEVEL_linalg_vectorMap2(closure71, x, y));
}
typedef struct env_t_77 {
	array_number_t row;
} env_t_77;
env_t_77 make_env_t_77(array_number_t row) {
	env_t_77 env;
	env.row = row;
	return env;
}

value_t lambda77(env_t_77* env74, number_t r) {
	array_number_t row73 = env74->row;
	value_t res;
	res.array_number_t_value = row73;
	return res;
}
array_array_number_t TOP_LEVEL_linalg_matrixFillFromVector(card_t rows, array_number_t row) {
	env_t_77 env_t_77_value = make_env_t_77(row); closure_t closure76 = make_closure(lambda77, &env_t_77_value);
	return TOP_LEVEL_linalg_vectorMapToMatrix(closure76, TOP_LEVEL_linalg_vectorRange(1, rows));
}

array_array_number_t TOP_LEVEL_linalg_matrixFill(card_t rows, card_t cols, number_t value) {
	array_array_number_t macroDef79 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef79->length=rows;
	macroDef79->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * rows);
		for(int r = 0; r < macroDef79->length; r++){
			array_number_t macroDef78 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef78->length=cols;
	macroDef78->arr = (number_t*)storage_alloc(sizeof(number_t) * cols);
		for(int c = 0; c < macroDef78->length; c++){
			
			macroDef78->arr[c] = value;;
		}
			macroDef79->arr[r] = macroDef78;;
		}
	return macroDef79;
}

array_array_number_t TOP_LEVEL_linalg_matrixTranspose(array_array_number_t m) {
	card_t macroDef80 = m->length;
	card_t rows = macroDef80;
	card_t macroDef81 = m->arr[0]->length;
	card_t cols = macroDef81;
	array_array_number_t macroDef83 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef83->length=cols;
	macroDef83->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * cols);
		for(int i = 0; i < macroDef83->length; i++){
			array_number_t macroDef82 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef82->length=rows;
	macroDef82->arr = (number_t*)storage_alloc(sizeof(number_t) * rows);
		for(int j = 0; j < macroDef82->length; j++){
			
			macroDef82->arr[j] = m->arr[j]->arr[i];;
		}
			macroDef83->arr[i] = macroDef82;;
		}
	return macroDef83;
}

array_array_number_t TOP_LEVEL_linalg_matrixMult(array_array_number_t m1, array_array_number_t m2) {
	card_t macroDef84 = m1->length;
	card_t r1 = macroDef84;
	card_t macroDef85 = m2->arr[0]->length;
	card_t c2 = macroDef85;
	card_t macroDef86 = m1->arr[0]->length;
	card_t c1 = macroDef86;
	card_t macroDef87 = m2->length;
	card_t r2 = macroDef87;
	array_array_number_t m2T = TOP_LEVEL_linalg_matrixTranspose(m2);
	array_array_number_t macroDef89 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef89->length=r1;
	macroDef89->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * r1);
		for(int r = 0; r < macroDef89->length; r++){
			array_number_t macroDef88 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef88->length=c2;
	macroDef88->arr = (number_t*)storage_alloc(sizeof(number_t) * c2);
		for(int c = 0; c < macroDef88->length; c++){
			
			macroDef88->arr[c] = TOP_LEVEL_linalg_dot_prod(m1->arr[r], m2T->arr[c]);;
		}
			macroDef89->arr[r] = macroDef88;;
		}
	return macroDef89;
}

array_number_t TOP_LEVEL_linalg_matrixVectorMult(array_array_number_t m, array_number_t v) {
	card_t r = TOP_LEVEL_linalg_rows(m);
	card_t c = TOP_LEVEL_linalg_cols(m);
	array_number_t macroDef90 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef90->length=r;
	macroDef90->arr = (number_t*)storage_alloc(sizeof(number_t) * r);
		for(int i = 0; i < macroDef90->length; i++){
			
			macroDef90->arr[i] = TOP_LEVEL_linalg_dot_prod(m->arr[i], v);;
		}
	return macroDef90;
}

array_array_number_t TOP_LEVEL_linalg_matrixConcat(array_array_number_t m1, array_array_number_t m2) {
	card_t macroDef91 = m1->length;
	card_t macroDef92 = m2->length;
	card_t rows = (macroDef91) + (macroDef92);
	card_t macroDef93 = m1->length;
	index_t m1Rows = (macroDef93);
	array_array_number_t macroDef94 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef94->length=rows;
	macroDef94->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * rows);
		for(int r = 0; r < macroDef94->length; r++){
			array_number_t ite95 = 0;
	if((r) < (m1Rows)) {
		
		ite95 = m1->arr[r];;
	} else {
		
		ite95 = m2->arr[(r) - (m1Rows)];;
	}
			macroDef94->arr[r] = ite95;;
		}
	return macroDef94;
}

array_array_number_t TOP_LEVEL_linalg_matrixConcatCol(array_array_number_t m1, array_array_number_t m2) {
	array_array_number_t m1t = TOP_LEVEL_linalg_matrixTranspose(m1);
	array_array_number_t m2t = TOP_LEVEL_linalg_matrixTranspose(m2);
	return TOP_LEVEL_linalg_matrixTranspose(TOP_LEVEL_linalg_matrixConcat(m1t, m2t));
}

array_array_array_number_t TOP_LEVEL_linalg_matrix3DConcat(array_array_array_number_t m1, array_array_array_number_t m2) {
	card_t macroDef96 = m1->length;
	card_t macroDef97 = m2->length;
	card_t rows = (macroDef96) + (macroDef97);
	card_t macroDef98 = m1->length;
	index_t m1Rows = (macroDef98);
	array_array_array_number_t macroDef99 = (array_array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef99->length=rows;
	macroDef99->arr = (array_array_number_t*)storage_alloc(sizeof(array_array_number_t) * rows);
		for(int r = 0; r < macroDef99->length; r++){
			array_array_number_t ite100 = 0;
	if((r) < (m1Rows)) {
		
		ite100 = m1->arr[r];;
	} else {
		
		ite100 = m2->arr[(r) - (m1Rows)];;
	}
			macroDef99->arr[r] = ite100;;
		}
	return macroDef99;
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
	array_number_t array101 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array101->length=3;
	array101->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array101->arr[0] = a;
	array101->arr[1] = b;
	array101->arr[2] = c;;
	return array101;
}
#endif
