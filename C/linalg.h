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

array_array_number_t TOP_LEVEL_linalg_matrixMap(closure_t f, array_array_number_t m) {
	card_t macroDef7 = m->length;
	array_array_number_t macroDef8 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef8->length=macroDef7;
	macroDef8->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * macroDef7);
		for(int i = 0; i < macroDef8->length; i++){
			
			macroDef8->arr[i] = f.lam(f.env, m->arr[i]).array_number_t_value;;
		}
	return macroDef8;
}

array_number_t TOP_LEVEL_linalg_matrixMapToVector(closure_t f, array_array_number_t m) {
	card_t macroDef9 = m->length;
	array_number_t macroDef10 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef10->length=macroDef9;
	macroDef10->arr = (number_t*)storage_alloc(sizeof(number_t) * macroDef9);
		for(int i = 0; i < macroDef10->length; i++){
			
			macroDef10->arr[i] = f.lam(f.env, m->arr[i]).number_t_value;;
		}
	return macroDef10;
}

array_number_t TOP_LEVEL_linalg_vectorMap2(closure_t f, array_number_t v1, array_number_t v2) {
	card_t macroDef11 = v1->length;
	array_number_t macroDef12 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef12->length=macroDef11;
	macroDef12->arr = (number_t*)storage_alloc(sizeof(number_t) * macroDef11);
		for(int i = 0; i < macroDef12->length; i++){
			
			macroDef12->arr[i] = f.lam(f.env, v1->arr[i], v2->arr[i]).number_t_value;;
		}
	return macroDef12;
}

array_array_number_t TOP_LEVEL_linalg_matrixMap2(closure_t f, array_array_number_t m1, array_array_number_t m2) {
	card_t macroDef13 = m1->length;
	array_array_number_t macroDef14 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef14->length=macroDef13;
	macroDef14->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * macroDef13);
		for(int i = 0; i < macroDef14->length; i++){
			
			macroDef14->arr[i] = f.lam(f.env, m1->arr[i], m2->arr[i]).array_number_t_value;;
		}
	return macroDef14;
}

array_array_array_number_t TOP_LEVEL_linalg_matrix3DMap2(closure_t f, array_array_array_number_t m1, array_array_array_number_t m2) {
	card_t macroDef15 = m1->length;
	array_array_array_number_t macroDef16 = (array_array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef16->length=macroDef15;
	macroDef16->arr = (array_array_number_t*)storage_alloc(sizeof(array_array_number_t) * macroDef15);
		for(int i = 0; i < macroDef16->length; i++){
			
			macroDef16->arr[i] = f.lam(f.env, m1->arr[i], m2->arr[i]).array_array_number_t_value;;
		}
	return macroDef16;
}

array_array_number_t TOP_LEVEL_linalg_vectorMapToMatrix(closure_t f, array_number_t arr) {
	card_t macroDef17 = arr->length;
	array_array_number_t macroDef18 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef18->length=macroDef17;
	macroDef18->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * macroDef17);
		for(int i = 0; i < macroDef18->length; i++){
			
			macroDef18->arr[i] = f.lam(f.env, arr->arr[i]).array_number_t_value;;
		}
	return macroDef18;
}

array_array_array_number_t TOP_LEVEL_linalg_vectorMapToMatrix3D(closure_t f, array_number_t arr) {
	card_t macroDef19 = arr->length;
	array_array_array_number_t macroDef20 = (array_array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef20->length=macroDef19;
	macroDef20->arr = (array_array_number_t*)storage_alloc(sizeof(array_array_number_t) * macroDef19);
		for(int i = 0; i < macroDef20->length; i++){
			
			macroDef20->arr[i] = f.lam(f.env, arr->arr[i]).array_array_number_t_value;;
		}
	return macroDef20;
}

number_t TOP_LEVEL_linalg_iterateNumber(closure_t f, number_t z, card_t s, card_t e) {
	number_t macroDef21 = z;
	for(int cur_idx = 0; cur_idx < TOP_LEVEL_linalg_vectorRange(s, e)->length; cur_idx++){
		number_t cur = TOP_LEVEL_linalg_vectorRange(s, e)->arr[cur_idx];
		
		macroDef21 = f.lam(f.env, macroDef21, (int)(cur)).number_t_value;;
	}
	return macroDef21;
}

array_number_t TOP_LEVEL_linalg_iterateVector(closure_t f, array_number_t z, card_t s, card_t e) {
	array_number_t macroDef22 = z;
	for(int cur_idx = 0; cur_idx < TOP_LEVEL_linalg_vectorRange(s, e)->length; cur_idx++){
		number_t cur = TOP_LEVEL_linalg_vectorRange(s, e)->arr[cur_idx];
		
		macroDef22 = f.lam(f.env, macroDef22, (int)(cur)).array_number_t_value;;
	}
	return macroDef22;
}

array_array_number_t TOP_LEVEL_linalg_iterateMatrix(closure_t f, array_array_number_t z, card_t s, card_t e) {
	array_array_number_t macroDef23 = z;
	for(int cur_idx = 0; cur_idx < TOP_LEVEL_linalg_vectorRange(s, e)->length; cur_idx++){
		number_t cur = TOP_LEVEL_linalg_vectorRange(s, e)->arr[cur_idx];
		
		macroDef23 = f.lam(f.env, macroDef23, (int)(cur)).array_array_number_t_value;;
	}
	return macroDef23;
}

array_array_array_number_t TOP_LEVEL_linalg_iterateMatrix3D(closure_t f, array_array_array_number_t z, card_t s, card_t e) {
	array_array_array_number_t macroDef24 = z;
	for(int cur_idx = 0; cur_idx < TOP_LEVEL_linalg_vectorRange(s, e)->length; cur_idx++){
		number_t cur = TOP_LEVEL_linalg_vectorRange(s, e)->arr[cur_idx];
		
		macroDef24 = f.lam(f.env, macroDef24, (int)(cur)).array_array_array_number_t_value;;
	}
	return macroDef24;
}

number_t TOP_LEVEL_linalg_vectorSum(array_number_t v) {
	number_t macroDef25 = 0;
	for(int cur_idx = 0; cur_idx < v->length; cur_idx++){
		number_t cur = v->arr[cur_idx];
		
		macroDef25 = (macroDef25) + (cur);;
	}
	return macroDef25;
}

number_t TOP_LEVEL_linalg_vectorMax(array_number_t v) {
	number_t macroDef26 = -1000;
	for(int cur_idx = 0; cur_idx < v->length; cur_idx++){
		number_t cur = v->arr[cur_idx];
		number_t ite27 = 0;
	if((macroDef26) > (cur)) {
		
		ite27 = macroDef26;;
	} else {
		
		ite27 = cur;;
	}
		macroDef26 = ite27;;
	}
	return macroDef26;
}
typedef struct env_t_32 {
	number_t y;
} env_t_32;
env_t_32 make_env_t_32(number_t y) {
	env_t_32 env;
	env.y = y;
	return env;
}

value_t lambda32(env_t_32* env29, number_t xi) {
	number_t y28 = env29->y;
	value_t res;
	res.number_t_value = (xi) * (y28);
	return res;
}
array_number_t TOP_LEVEL_linalg_mult_by_scalar(array_number_t x, number_t y) {
	env_t_32 env_t_32_value = make_env_t_32(y); closure_t closure31 = make_closure(lambda32, &env_t_32_value);
	return TOP_LEVEL_linalg_vectorMap(closure31, x);
}
typedef struct env_t_38 {
	number_t y;
	number_t a;
} env_t_38;
env_t_38 make_env_t_38(number_t y,number_t a) {
	env_t_38 env;
	env.y = y;
	env.a = a;
	return env;
}

value_t lambda38(env_t_38* env35, number_t xi) {
	number_t y34 = env35->y;
	number_t a33 = env35->a;
	value_t res;
	res.number_t_value = ((a33) * (xi)) + (y34);
	return res;
}
array_number_t TOP_LEVEL_linalg_gaxpy(number_t a, array_number_t x, number_t y) {
	env_t_38 env_t_38_value = make_env_t_38(y,a); closure_t closure37 = make_closure(lambda38, &env_t_38_value);
	return TOP_LEVEL_linalg_vectorMap(closure37, x);
}

array_number_t TOP_LEVEL_linalg_cross(array_number_t a, array_number_t b) {
	array_number_t array39 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array39->length=3;
	array39->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array39->arr[0] = ((a->arr[1]) * (b->arr[2])) - ((a->arr[2]) * (b->arr[1]));
	array39->arr[1] = ((a->arr[2]) * (b->arr[0])) - ((a->arr[0]) * (b->arr[2]));
	array39->arr[2] = ((a->arr[0]) * (b->arr[1])) - ((a->arr[1]) * (b->arr[0]));;
	return array39;
}
typedef empty_env_t env_t_43;


value_t lambda43(env_t_43* env40, number_t x0, number_t y0) {
	
	value_t res;
	res.number_t_value = (x0) + (y0);
	return res;
}
array_number_t TOP_LEVEL_linalg_vectorAdd(array_number_t x, array_number_t y) {
	env_t_43 env_t_43_value = make_empty_env(); closure_t closure42 = make_closure(lambda43, &env_t_43_value);
	return TOP_LEVEL_linalg_vectorMap2(closure42, x, y);
}
typedef empty_env_t env_t_47;


value_t lambda47(env_t_47* env44, number_t x0, number_t y0) {
	
	value_t res;
	res.number_t_value = (x0) * (y0);
	return res;
}
array_number_t TOP_LEVEL_linalg_mult_vec_elementwise(array_number_t x, array_number_t y) {
	env_t_47 env_t_47_value = make_empty_env(); closure_t closure46 = make_closure(lambda47, &env_t_47_value);
	return TOP_LEVEL_linalg_vectorMap2(closure46, x, y);
}
typedef empty_env_t env_t_51;


value_t lambda51(env_t_51* env48, number_t x0, number_t y0) {
	
	value_t res;
	res.number_t_value = (x0) * (y0);
	return res;
}
array_number_t TOP_LEVEL_linalg_op_DotMultiply(array_number_t x, array_number_t y) {
	env_t_51 env_t_51_value = make_empty_env(); closure_t closure50 = make_closure(lambda51, &env_t_51_value);
	return TOP_LEVEL_linalg_vectorMap2(closure50, x, y);
}

array_number_t TOP_LEVEL_linalg_vectorAdd3(array_number_t x, array_number_t y, array_number_t z) {
	
	return TOP_LEVEL_linalg_vectorAdd(TOP_LEVEL_linalg_vectorAdd(x, y), z);
}
typedef empty_env_t env_t_55;


value_t lambda55(env_t_55* env52, number_t x0, number_t y0) {
	
	value_t res;
	res.number_t_value = (x0) - (y0);
	return res;
}
array_number_t TOP_LEVEL_linalg_vectorSub(array_number_t x, array_number_t y) {
	env_t_55 env_t_55_value = make_empty_env(); closure_t closure54 = make_closure(lambda55, &env_t_55_value);
	return TOP_LEVEL_linalg_vectorMap2(closure54, x, y);
}
typedef empty_env_t env_t_59;


value_t lambda59(env_t_59* env56, array_number_t x0, array_number_t y0) {
	
	value_t res;
	res.array_number_t_value = TOP_LEVEL_linalg_vectorAdd(x0, y0);
	return res;
}
array_array_number_t TOP_LEVEL_linalg_matrixAdd(array_array_number_t x, array_array_number_t y) {
	env_t_59 env_t_59_value = make_empty_env(); closure_t closure58 = make_closure(lambda59, &env_t_59_value);
	return TOP_LEVEL_linalg_matrixMap2(closure58, x, y);
}
typedef empty_env_t env_t_63;


value_t lambda63(env_t_63* env60, array_number_t x0, array_number_t y0) {
	
	value_t res;
	res.array_number_t_value = TOP_LEVEL_linalg_mult_vec_elementwise(x0, y0);
	return res;
}
array_array_number_t TOP_LEVEL_linalg_matrixMultElementwise(array_array_number_t x, array_array_number_t y) {
	env_t_63 env_t_63_value = make_empty_env(); closure_t closure62 = make_closure(lambda63, &env_t_63_value);
	return TOP_LEVEL_linalg_matrixMap2(closure62, x, y);
}
typedef empty_env_t env_t_67;


value_t lambda67(env_t_67* env64, number_t x1) {
	
	value_t res;
	res.number_t_value = (x1) * (x1);
	return res;
}
number_t TOP_LEVEL_linalg_sqnorm(array_number_t x) {
	env_t_67 env_t_67_value = make_empty_env(); closure_t closure66 = make_closure(lambda67, &env_t_67_value);
	return TOP_LEVEL_linalg_vectorSum(TOP_LEVEL_linalg_vectorMap(closure66, x));
}
typedef empty_env_t env_t_71;


value_t lambda71(env_t_71* env68, number_t x0, number_t y0) {
	
	value_t res;
	res.number_t_value = (x0) * (y0);
	return res;
}
number_t TOP_LEVEL_linalg_dot_prod(array_number_t x, array_number_t y) {
	env_t_71 env_t_71_value = make_empty_env(); closure_t closure70 = make_closure(lambda71, &env_t_71_value);
	return TOP_LEVEL_linalg_vectorSum(TOP_LEVEL_linalg_vectorMap2(closure70, x, y));
}
typedef struct env_t_76 {
	array_number_t row;
} env_t_76;
env_t_76 make_env_t_76(array_number_t row) {
	env_t_76 env;
	env.row = row;
	return env;
}

value_t lambda76(env_t_76* env73, number_t r) {
	array_number_t row72 = env73->row;
	value_t res;
	res.array_number_t_value = row72;
	return res;
}
array_array_number_t TOP_LEVEL_linalg_matrixFillFromVector(card_t rows, array_number_t row) {
	env_t_76 env_t_76_value = make_env_t_76(row); closure_t closure75 = make_closure(lambda76, &env_t_76_value);
	return TOP_LEVEL_linalg_vectorMapToMatrix(closure75, TOP_LEVEL_linalg_vectorRange(1, rows));
}

array_array_number_t TOP_LEVEL_linalg_matrixFill(card_t rows, card_t cols, number_t value) {
	array_array_number_t macroDef78 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef78->length=rows;
	macroDef78->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * rows);
		for(int r = 0; r < macroDef78->length; r++){
			array_number_t macroDef77 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef77->length=cols;
	macroDef77->arr = (number_t*)storage_alloc(sizeof(number_t) * cols);
		for(int c = 0; c < macroDef77->length; c++){
			
			macroDef77->arr[c] = value;;
		}
			macroDef78->arr[r] = macroDef77;;
		}
	return macroDef78;
}

array_array_number_t TOP_LEVEL_linalg_matrixTranspose(array_array_number_t m) {
	card_t macroDef79 = m->length;
	card_t rows = macroDef79;
	card_t macroDef80 = m->arr[0]->length;
	card_t cols = macroDef80;
	array_array_number_t macroDef82 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef82->length=cols;
	macroDef82->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * cols);
		for(int i = 0; i < macroDef82->length; i++){
			array_number_t macroDef81 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef81->length=rows;
	macroDef81->arr = (number_t*)storage_alloc(sizeof(number_t) * rows);
		for(int j = 0; j < macroDef81->length; j++){
			
			macroDef81->arr[j] = m->arr[j]->arr[i];;
		}
			macroDef82->arr[i] = macroDef81;;
		}
	return macroDef82;
}

array_array_number_t TOP_LEVEL_linalg_matrixMult(array_array_number_t m1, array_array_number_t m2) {
	card_t macroDef83 = m1->length;
	card_t r1 = macroDef83;
	card_t macroDef84 = m2->arr[0]->length;
	card_t c2 = macroDef84;
	card_t macroDef85 = m1->arr[0]->length;
	card_t c1 = macroDef85;
	card_t macroDef86 = m2->length;
	card_t r2 = macroDef86;
	array_array_number_t m2T = TOP_LEVEL_linalg_matrixTranspose(m2);
	array_array_number_t macroDef88 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef88->length=r1;
	macroDef88->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * r1);
		for(int r = 0; r < macroDef88->length; r++){
			array_number_t macroDef87 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef87->length=c2;
	macroDef87->arr = (number_t*)storage_alloc(sizeof(number_t) * c2);
		for(int c = 0; c < macroDef87->length; c++){
			
			macroDef87->arr[c] = TOP_LEVEL_linalg_dot_prod(m1->arr[r], m2T->arr[c]);;
		}
			macroDef88->arr[r] = macroDef87;;
		}
	return macroDef88;
}

array_number_t TOP_LEVEL_linalg_matrixVectorMult(array_array_number_t m, array_number_t v) {
	card_t r = TOP_LEVEL_linalg_rows(m);
	card_t c = TOP_LEVEL_linalg_cols(m);
	array_number_t macroDef89 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef89->length=r;
	macroDef89->arr = (number_t*)storage_alloc(sizeof(number_t) * r);
		for(int i = 0; i < macroDef89->length; i++){
			
			macroDef89->arr[i] = TOP_LEVEL_linalg_dot_prod(m->arr[i], v);;
		}
	return macroDef89;
}

array_array_number_t TOP_LEVEL_linalg_matrixConcat(array_array_number_t m1, array_array_number_t m2) {
	card_t macroDef90 = m1->length;
	card_t macroDef91 = m2->length;
	card_t rows = (macroDef90) + (macroDef91);
	card_t macroDef92 = m1->length;
	index_t m1Rows = (macroDef92);
	array_array_number_t macroDef93 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef93->length=rows;
	macroDef93->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * rows);
		for(int r = 0; r < macroDef93->length; r++){
			array_number_t ite94 = 0;
	if((r) < (m1Rows)) {
		
		ite94 = m1->arr[r];;
	} else {
		
		ite94 = m2->arr[(r) - (m1Rows)];;
	}
			macroDef93->arr[r] = ite94;;
		}
	return macroDef93;
}

array_array_number_t TOP_LEVEL_linalg_matrixConcatCol(array_array_number_t m1, array_array_number_t m2) {
	array_array_number_t m1t = TOP_LEVEL_linalg_matrixTranspose(m1);
	array_array_number_t m2t = TOP_LEVEL_linalg_matrixTranspose(m2);
	return TOP_LEVEL_linalg_matrixTranspose(TOP_LEVEL_linalg_matrixConcat(m1t, m2t));
}

array_array_array_number_t TOP_LEVEL_linalg_matrix3DConcat(array_array_array_number_t m1, array_array_array_number_t m2) {
	card_t macroDef95 = m1->length;
	card_t macroDef96 = m2->length;
	card_t rows = (macroDef95) + (macroDef96);
	card_t macroDef97 = m1->length;
	index_t m1Rows = (macroDef97);
	array_array_array_number_t macroDef98 = (array_array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef98->length=rows;
	macroDef98->arr = (array_array_number_t*)storage_alloc(sizeof(array_array_number_t) * rows);
		for(int r = 0; r < macroDef98->length; r++){
			array_array_number_t ite99 = 0;
	if((r) < (m1Rows)) {
		
		ite99 = m1->arr[r];;
	} else {
		
		ite99 = m2->arr[(r) - (m1Rows)];;
	}
			macroDef98->arr[r] = ite99;;
		}
	return macroDef98;
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
	array_number_t array100 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array100->length=3;
	array100->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array100->arr[0] = a;
	array100->arr[1] = b;
	array100->arr[2] = c;;
	return array100;
}
#endif
