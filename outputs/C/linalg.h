#ifndef __LINALG_H__ 
#define __LINALG_H__ 
#include "../../Runtime/C/fsharp.h"
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

number_t TOP_LEVEL_linalg_vectorFoldNumber(closure_t f, number_t z, array_number_t range) {
	card_t macroDef22 = range->length;
	card_t l = macroDef22;
	number_t macroDef23 = z;
	for(int idx = 0; idx < l; idx++){
		
		macroDef23 = f.lam(f.env, macroDef23, range->arr[idx]).number_t_value;;
	}
	return macroDef23;
}
typedef empty_env_t env_t_27;


value_t lambda27(env_t_27* env24, number_t acc, number_t cur) {
	
	value_t res;
	res.number_t_value = (acc) + (cur);
	return res;
}
number_t TOP_LEVEL_linalg_vectorSum(array_number_t v) {
	env_t_27 env_t_27_value = make_empty_env(); closure_t closure26 = make_closure(lambda27, &env_t_27_value);
	return TOP_LEVEL_linalg_vectorFoldNumber(closure26, 0, v);
}
typedef empty_env_t env_t_32;


value_t lambda32(env_t_32* env28, number_t acc, number_t cur) {
	number_t ite31 = 0;
	if((acc) > (cur)) {
		
		ite31 = acc;;
	} else {
		
		ite31 = cur;;
	}
	value_t res;
	res.number_t_value = ite31;
	return res;
}
number_t TOP_LEVEL_linalg_vectorMax(array_number_t v) {
	env_t_32 env_t_32_value = make_empty_env(); closure_t closure30 = make_closure(lambda32, &env_t_32_value);
	return TOP_LEVEL_linalg_vectorFoldNumber(closure30, -1000, v);
}
typedef struct env_t_37 {
	number_t y;
} env_t_37;
env_t_37 make_env_t_37(number_t y) {
	env_t_37 env;
	env.y = y;
	return env;
}

value_t lambda37(env_t_37* env34, number_t xi) {
	number_t y33 = env34->y;
	value_t res;
	res.number_t_value = (xi) * (y33);
	return res;
}
array_number_t TOP_LEVEL_linalg_mult_by_scalar(array_number_t x, number_t y) {
	env_t_37 env_t_37_value = make_env_t_37(y); closure_t closure36 = make_closure(lambda37, &env_t_37_value);
	return TOP_LEVEL_linalg_vectorMap(closure36, x);
}
typedef struct env_t_43 {
	number_t y;
	number_t a;
} env_t_43;
env_t_43 make_env_t_43(number_t y,number_t a) {
	env_t_43 env;
	env.y = y;
	env.a = a;
	return env;
}

value_t lambda43(env_t_43* env40, number_t xi) {
	number_t y39 = env40->y;
	number_t a38 = env40->a;
	value_t res;
	res.number_t_value = ((a38) * (xi)) + (y39);
	return res;
}
array_number_t TOP_LEVEL_linalg_gaxpy(number_t a, array_number_t x, number_t y) {
	env_t_43 env_t_43_value = make_env_t_43(y,a); closure_t closure42 = make_closure(lambda43, &env_t_43_value);
	return TOP_LEVEL_linalg_vectorMap(closure42, x);
}

array_number_t TOP_LEVEL_linalg_cross(array_number_t a, array_number_t b) {
	array_number_t array44 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array44->length=3;
	array44->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array44->arr[0] = ((a->arr[1]) * (b->arr[2])) - ((a->arr[2]) * (b->arr[1]));
	array44->arr[1] = ((a->arr[2]) * (b->arr[0])) - ((a->arr[0]) * (b->arr[2]));
	array44->arr[2] = ((a->arr[0]) * (b->arr[1])) - ((a->arr[1]) * (b->arr[0]));;
	return array44;
}
typedef empty_env_t env_t_48;


value_t lambda48(env_t_48* env45, number_t x0, number_t y0) {
	
	value_t res;
	res.number_t_value = (x0) + (y0);
	return res;
}
array_number_t TOP_LEVEL_linalg_vectorAdd(array_number_t x, array_number_t y) {
	env_t_48 env_t_48_value = make_empty_env(); closure_t closure47 = make_closure(lambda48, &env_t_48_value);
	return TOP_LEVEL_linalg_vectorMap2(closure47, x, y);
}
typedef empty_env_t env_t_52;


value_t lambda52(env_t_52* env49, number_t x0, number_t y0) {
	
	value_t res;
	res.number_t_value = (x0) * (y0);
	return res;
}
array_number_t TOP_LEVEL_linalg_mult_vec_elementwise(array_number_t x, array_number_t y) {
	env_t_52 env_t_52_value = make_empty_env(); closure_t closure51 = make_closure(lambda52, &env_t_52_value);
	return TOP_LEVEL_linalg_vectorMap2(closure51, x, y);
}
typedef empty_env_t env_t_56;


value_t lambda56(env_t_56* env53, number_t x0, number_t y0) {
	
	value_t res;
	res.number_t_value = (x0) * (y0);
	return res;
}
array_number_t TOP_LEVEL_linalg_op_DotMultiply(array_number_t x, array_number_t y) {
	env_t_56 env_t_56_value = make_empty_env(); closure_t closure55 = make_closure(lambda56, &env_t_56_value);
	return TOP_LEVEL_linalg_vectorMap2(closure55, x, y);
}

array_number_t TOP_LEVEL_linalg_vectorAdd3(array_number_t x, array_number_t y, array_number_t z) {
	
	return TOP_LEVEL_linalg_vectorAdd(TOP_LEVEL_linalg_vectorAdd(x, y), z);
}
typedef empty_env_t env_t_60;


value_t lambda60(env_t_60* env57, number_t x0, number_t y0) {
	
	value_t res;
	res.number_t_value = (x0) - (y0);
	return res;
}
array_number_t TOP_LEVEL_linalg_vectorSub(array_number_t x, array_number_t y) {
	env_t_60 env_t_60_value = make_empty_env(); closure_t closure59 = make_closure(lambda60, &env_t_60_value);
	return TOP_LEVEL_linalg_vectorMap2(closure59, x, y);
}
typedef empty_env_t env_t_64;


value_t lambda64(env_t_64* env61, array_number_t x0, array_number_t y0) {
	
	value_t res;
	res.array_number_t_value = TOP_LEVEL_linalg_vectorAdd(x0, y0);
	return res;
}
array_array_number_t TOP_LEVEL_linalg_matrixAdd(array_array_number_t x, array_array_number_t y) {
	env_t_64 env_t_64_value = make_empty_env(); closure_t closure63 = make_closure(lambda64, &env_t_64_value);
	return TOP_LEVEL_linalg_matrixMap2(closure63, x, y);
}
typedef empty_env_t env_t_68;


value_t lambda68(env_t_68* env65, array_number_t x0, array_number_t y0) {
	
	value_t res;
	res.array_number_t_value = TOP_LEVEL_linalg_mult_vec_elementwise(x0, y0);
	return res;
}
array_array_number_t TOP_LEVEL_linalg_matrixMultElementwise(array_array_number_t x, array_array_number_t y) {
	env_t_68 env_t_68_value = make_empty_env(); closure_t closure67 = make_closure(lambda68, &env_t_68_value);
	return TOP_LEVEL_linalg_matrixMap2(closure67, x, y);
}
typedef empty_env_t env_t_72;


value_t lambda72(env_t_72* env69, number_t x1) {
	
	value_t res;
	res.number_t_value = (x1) * (x1);
	return res;
}
number_t TOP_LEVEL_linalg_sqnorm(array_number_t x) {
	env_t_72 env_t_72_value = make_empty_env(); closure_t closure71 = make_closure(lambda72, &env_t_72_value);
	return TOP_LEVEL_linalg_vectorSum(TOP_LEVEL_linalg_vectorMap(closure71, x));
}
typedef empty_env_t env_t_76;


value_t lambda76(env_t_76* env73, number_t x0, number_t y0) {
	
	value_t res;
	res.number_t_value = (x0) * (y0);
	return res;
}
number_t TOP_LEVEL_linalg_dot_prod(array_number_t x, array_number_t y) {
	env_t_76 env_t_76_value = make_empty_env(); closure_t closure75 = make_closure(lambda76, &env_t_76_value);
	return TOP_LEVEL_linalg_vectorSum(TOP_LEVEL_linalg_vectorMap2(closure75, x, y));
}
typedef struct env_t_81 {
	array_number_t row;
} env_t_81;
env_t_81 make_env_t_81(array_number_t row) {
	env_t_81 env;
	env.row = row;
	return env;
}

value_t lambda81(env_t_81* env78, number_t r) {
	array_number_t row77 = env78->row;
	value_t res;
	res.array_number_t_value = row77;
	return res;
}
array_array_number_t TOP_LEVEL_linalg_matrixFillFromVector(card_t rows, array_number_t row) {
	env_t_81 env_t_81_value = make_env_t_81(row); closure_t closure80 = make_closure(lambda81, &env_t_81_value);
	return TOP_LEVEL_linalg_vectorMapToMatrix(closure80, TOP_LEVEL_linalg_vectorRange(1, rows));
}

array_array_number_t TOP_LEVEL_linalg_matrixFill(card_t rows, card_t cols, number_t value) {
	array_array_number_t macroDef83 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef83->length=rows;
	macroDef83->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * rows);
		for(int r = 0; r < macroDef83->length; r++){
			array_number_t macroDef82 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef82->length=cols;
	macroDef82->arr = (number_t*)storage_alloc(sizeof(number_t) * cols);
		for(int c = 0; c < macroDef82->length; c++){
			
			macroDef82->arr[c] = value;;
		}
			macroDef83->arr[r] = macroDef82;;
		}
	return macroDef83;
}

array_array_number_t TOP_LEVEL_linalg_matrixTranspose(array_array_number_t m) {
	card_t macroDef84 = m->length;
	card_t rows = macroDef84;
	card_t macroDef85 = m->arr[0]->length;
	card_t cols = macroDef85;
	array_array_number_t macroDef87 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef87->length=cols;
	macroDef87->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * cols);
		for(int i = 0; i < macroDef87->length; i++){
			array_number_t macroDef86 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef86->length=rows;
	macroDef86->arr = (number_t*)storage_alloc(sizeof(number_t) * rows);
		for(int j = 0; j < macroDef86->length; j++){
			
			macroDef86->arr[j] = m->arr[j]->arr[i];;
		}
			macroDef87->arr[i] = macroDef86;;
		}
	return macroDef87;
}

array_array_number_t TOP_LEVEL_linalg_matrixMult(array_array_number_t m1, array_array_number_t m2) {
	card_t macroDef88 = m1->length;
	card_t r1 = macroDef88;
	card_t macroDef89 = m2->arr[0]->length;
	card_t c2 = macroDef89;
	card_t macroDef90 = m1->arr[0]->length;
	card_t c1 = macroDef90;
	card_t macroDef91 = m2->length;
	card_t r2 = macroDef91;
	array_array_number_t m2T = TOP_LEVEL_linalg_matrixTranspose(m2);
	array_array_number_t macroDef93 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef93->length=r1;
	macroDef93->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * r1);
		for(int r = 0; r < macroDef93->length; r++){
			array_number_t macroDef92 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef92->length=c2;
	macroDef92->arr = (number_t*)storage_alloc(sizeof(number_t) * c2);
		for(int c = 0; c < macroDef92->length; c++){
			
			macroDef92->arr[c] = TOP_LEVEL_linalg_dot_prod(m1->arr[r], m2T->arr[c]);;
		}
			macroDef93->arr[r] = macroDef92;;
		}
	return macroDef93;
}

array_number_t TOP_LEVEL_linalg_matrixVectorMult(array_array_number_t m, array_number_t v) {
	card_t r = TOP_LEVEL_linalg_rows(m);
	card_t c = TOP_LEVEL_linalg_cols(m);
	array_number_t macroDef94 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef94->length=r;
	macroDef94->arr = (number_t*)storage_alloc(sizeof(number_t) * r);
		for(int i = 0; i < macroDef94->length; i++){
			
			macroDef94->arr[i] = TOP_LEVEL_linalg_dot_prod(m->arr[i], v);;
		}
	return macroDef94;
}

array_array_number_t TOP_LEVEL_linalg_matrixConcat(array_array_number_t m1, array_array_number_t m2) {
	card_t macroDef95 = m1->length;
	card_t macroDef96 = m2->length;
	card_t rows = (macroDef95) + (macroDef96);
	card_t macroDef97 = m1->length;
	index_t m1Rows = (macroDef97);
	array_array_number_t macroDef98 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef98->length=rows;
	macroDef98->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * rows);
		for(int r = 0; r < macroDef98->length; r++){
			array_number_t ite99 = 0;
	if((r) < (m1Rows)) {
		
		ite99 = m1->arr[r];;
	} else {
		
		ite99 = m2->arr[(r) - (m1Rows)];;
	}
			macroDef98->arr[r] = ite99;;
		}
	return macroDef98;
}

array_array_number_t TOP_LEVEL_linalg_matrixConcatCol(array_array_number_t m1, array_array_number_t m2) {
	array_array_number_t m1t = TOP_LEVEL_linalg_matrixTranspose(m1);
	array_array_number_t m2t = TOP_LEVEL_linalg_matrixTranspose(m2);
	return TOP_LEVEL_linalg_matrixTranspose(TOP_LEVEL_linalg_matrixConcat(m1t, m2t));
}

array_array_array_number_t TOP_LEVEL_linalg_matrix3DConcat(array_array_array_number_t m1, array_array_array_number_t m2) {
	card_t macroDef100 = m1->length;
	card_t macroDef101 = m2->length;
	card_t rows = (macroDef100) + (macroDef101);
	card_t macroDef102 = m1->length;
	index_t m1Rows = (macroDef102);
	array_array_array_number_t macroDef103 = (array_array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef103->length=rows;
	macroDef103->arr = (array_array_number_t*)storage_alloc(sizeof(array_array_number_t) * rows);
		for(int r = 0; r < macroDef103->length; r++){
			array_array_number_t ite104 = 0;
	if((r) < (m1Rows)) {
		
		ite104 = m1->arr[r];;
	} else {
		
		ite104 = m2->arr[(r) - (m1Rows)];;
	}
			macroDef103->arr[r] = ite104;;
		}
	return macroDef103;
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
	array_number_t array105 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array105->length=3;
	array105->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array105->arr[0] = a;
	array105->arr[1] = b;
	array105->arr[2] = c;;
	return array105;
}
#endif
