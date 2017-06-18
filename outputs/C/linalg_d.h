#ifndef __LINALG_D_H__ 
#define __LINALG_D_H__ 
#include "../../Runtime/C/fsharp.h"
#include <stdio.h>
#include <math.h>
#include "linalg.h"

card_t TOP_LEVEL_linalg_rows_d(array_array_number_t m, array_array_number_t m_d) {
	card_t macroDef1 = m->length;
	return macroDef1;
}

card_t TOP_LEVEL_linalg_cols_d(array_array_number_t m, array_array_number_t m_d) {
	card_t macroDef2 = m->arr[0]->length;
	return macroDef2;
}

array_number_t TOP_LEVEL_linalg_vectorMap_d(closure_t f, array_number_t v, closure_t f_d, array_number_t v_d) {
	card_t macroDef3 = v->length;
	array_number_t macroDef4 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef4->length=macroDef3;
	macroDef4->arr = (number_t*)storage_alloc(sizeof(number_t) * macroDef3);
		for(int i = 0; i < macroDef4->length; i++){
			
			macroDef4->arr[i] = f_d.lam(f_d.env, v->arr[i], v_d->arr[i]).number_t_value;;
		}
	return macroDef4;
}

array_number_t TOP_LEVEL_linalg_vectorRange_d(card_t s, card_t e, card_t s_d, card_t e_d) {
	array_number_t macroDef5 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef5->length=((e) - (s)) + (1);
	macroDef5->arr = (number_t*)storage_alloc(sizeof(number_t) * ((e) - (s)) + (1));
		for(int i = 0; i < macroDef5->length; i++){
			
			macroDef5->arr[i] = 0;;
		}
	return macroDef5;
}

array_number_t TOP_LEVEL_linalg_vectorSlice_d(card_t size, index_t offset, array_number_t v, card_t size_d, index_t offset_d, array_number_t v_d) {
	array_number_t macroDef6 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef6->length=size;
	macroDef6->arr = (number_t*)storage_alloc(sizeof(number_t) * size);
		for(int i = 0; i < macroDef6->length; i++){
			
			macroDef6->arr[i] = v_d->arr[(i) + (offset)];;
		}
	return macroDef6;
}

array_array_number_t TOP_LEVEL_linalg_matrixSlice_d(card_t size, index_t offset, array_array_number_t m, card_t size_d, index_t offset_d, array_array_number_t m_d) {
	array_array_number_t macroDef7 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef7->length=size;
	macroDef7->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * size);
		for(int i = 0; i < macroDef7->length; i++){
			
			macroDef7->arr[i] = m_d->arr[(i) + (offset)];;
		}
	return macroDef7;
}

array_array_number_t TOP_LEVEL_linalg_matrixMap_d(closure_t f, array_array_number_t m, closure_t f_d, array_array_number_t m_d) {
	card_t macroDef8 = m->length;
	array_array_number_t macroDef9 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef9->length=macroDef8;
	macroDef9->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * macroDef8);
		for(int i = 0; i < macroDef9->length; i++){
			
			macroDef9->arr[i] = f_d.lam(f_d.env, m->arr[i], m_d->arr[i]).array_number_t_value;;
		}
	return macroDef9;
}

array_number_t TOP_LEVEL_linalg_matrixMapToVector_d(closure_t f, array_array_number_t m, closure_t f_d, array_array_number_t m_d) {
	card_t macroDef10 = m->length;
	array_number_t macroDef11 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef11->length=macroDef10;
	macroDef11->arr = (number_t*)storage_alloc(sizeof(number_t) * macroDef10);
		for(int i = 0; i < macroDef11->length; i++){
			
			macroDef11->arr[i] = f_d.lam(f_d.env, m->arr[i], m_d->arr[i]).number_t_value;;
		}
	return macroDef11;
}

array_number_t TOP_LEVEL_linalg_vectorMap2_d(closure_t f, array_number_t v1, array_number_t v2, closure_t f_d, array_number_t v1_d, array_number_t v2_d) {
	card_t macroDef12 = v1->length;
	array_number_t macroDef13 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef13->length=macroDef12;
	macroDef13->arr = (number_t*)storage_alloc(sizeof(number_t) * macroDef12);
		for(int i = 0; i < macroDef13->length; i++){
			
			macroDef13->arr[i] = f_d.lam(f_d.env, v1->arr[i], v2->arr[i], v1_d->arr[i], v2_d->arr[i]).number_t_value;;
		}
	return macroDef13;
}

array_array_number_t TOP_LEVEL_linalg_matrixMap2_d(closure_t f, array_array_number_t m1, array_array_number_t m2, closure_t f_d, array_array_number_t m1_d, array_array_number_t m2_d) {
	card_t macroDef14 = m1->length;
	array_array_number_t macroDef15 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef15->length=macroDef14;
	macroDef15->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * macroDef14);
		for(int i = 0; i < macroDef15->length; i++){
			
			macroDef15->arr[i] = f_d.lam(f_d.env, m1->arr[i], m2->arr[i], m1_d->arr[i], m2_d->arr[i]).array_number_t_value;;
		}
	return macroDef15;
}

array_array_array_number_t TOP_LEVEL_linalg_matrix3DMap2_d(closure_t f, array_array_array_number_t m1, array_array_array_number_t m2, closure_t f_d, array_array_array_number_t m1_d, array_array_array_number_t m2_d) {
	card_t macroDef16 = m1->length;
	array_array_array_number_t macroDef17 = (array_array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef17->length=macroDef16;
	macroDef17->arr = (array_array_number_t*)storage_alloc(sizeof(array_array_number_t) * macroDef16);
		for(int i = 0; i < macroDef17->length; i++){
			
			macroDef17->arr[i] = f_d.lam(f_d.env, m1->arr[i], m2->arr[i], m1_d->arr[i], m2_d->arr[i]).array_array_number_t_value;;
		}
	return macroDef17;
}

array_array_number_t TOP_LEVEL_linalg_vectorMapToMatrix_d(closure_t f, array_number_t arr, closure_t f_d, array_number_t arr_d) {
	card_t macroDef18 = arr->length;
	array_array_number_t macroDef19 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef19->length=macroDef18;
	macroDef19->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * macroDef18);
		for(int i = 0; i < macroDef19->length; i++){
			
			macroDef19->arr[i] = f_d.lam(f_d.env, arr->arr[i], arr_d->arr[i]).array_number_t_value;;
		}
	return macroDef19;
}

array_array_array_number_t TOP_LEVEL_linalg_vectorMapToMatrix3D_d(closure_t f, array_number_t arr, closure_t f_d, array_number_t arr_d) {
	card_t macroDef20 = arr->length;
	array_array_array_number_t macroDef21 = (array_array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef21->length=macroDef20;
	macroDef21->arr = (array_array_number_t*)storage_alloc(sizeof(array_array_number_t) * macroDef20);
		for(int i = 0; i < macroDef21->length; i++){
			
			macroDef21->arr[i] = f_d.lam(f_d.env, arr->arr[i], arr_d->arr[i]).array_array_number_t_value;;
		}
	return macroDef21;
}

number_t TOP_LEVEL_linalg_vectorFoldNumber_d(closure_t f, number_t z, array_number_t range, closure_t f_d, number_t z_d, array_number_t range_d) {
	card_t macroDef24 = range->length;
	card_t l = macroDef24;
	card_t macroDef25 = range->length;
	card_t l_d = macroDef25;
	tuple_number_t_number_t macroDef26 = pair(z, z_d);
	for(int idx = 0; idx < l; idx++){
		number_t acc = macroDef26._1;
		number_t acc_d = macroDef26._2;
		macroDef26 = pair(f.lam(f.env, acc, range->arr[idx]).number_t_value, f_d.lam(f_d.env, acc, range->arr[idx], acc_d, range_d->arr[idx]).number_t_value);;
	}
	number_t snd27 = macroDef26._2;
	return snd27;
}
typedef empty_env_t env_t_34;


value_t lambda34(env_t_34* env28, number_t acc, number_t cur) {
	
	value_t res;
	res.number_t_value = (acc) + (cur);
	return res;
}
typedef empty_env_t env_t_35;


value_t lambda35(env_t_35* env31, number_t acc, number_t cur, number_t acc_d, number_t cur_d) {
	
	value_t res;
	res.number_t_value = (acc_d) + (cur_d);
	return res;
}
number_t TOP_LEVEL_linalg_vectorSum_d(array_number_t v, array_number_t v_d) {
	env_t_34 env_t_34_value = make_empty_env(); closure_t closure30 = make_closure(lambda34, &env_t_34_value);
	env_t_35 env_t_35_value = make_empty_env(); closure_t closure33 = make_closure(lambda35, &env_t_35_value);
	return TOP_LEVEL_linalg_vectorFoldNumber_d(closure30, 0, v, closure33, 0, v_d);
}
typedef empty_env_t env_t_44;


value_t lambda44(env_t_44* env36, number_t acc, number_t cur) {
	number_t ite42 = 0;
	if((acc) > (cur)) {
		
		ite42 = acc;;
	} else {
		
		ite42 = cur;;
	}
	value_t res;
	res.number_t_value = ite42;
	return res;
}
typedef empty_env_t env_t_45;


value_t lambda45(env_t_45* env39, number_t acc, number_t cur, number_t acc_d, number_t cur_d) {
	number_t ite43 = 0;
	if((acc) > (cur)) {
		
		ite43 = acc_d;;
	} else {
		
		ite43 = cur_d;;
	}
	value_t res;
	res.number_t_value = ite43;
	return res;
}
number_t TOP_LEVEL_linalg_vectorMax_d(array_number_t v, array_number_t v_d) {
	env_t_44 env_t_44_value = make_empty_env(); closure_t closure38 = make_closure(lambda44, &env_t_44_value);
	env_t_45 env_t_45_value = make_empty_env(); closure_t closure41 = make_closure(lambda45, &env_t_45_value);
	return TOP_LEVEL_linalg_vectorFoldNumber_d(closure38, -1000, v, closure41, 0, v_d);
}
typedef struct env_t_55 {
	number_t y;
} env_t_55;
env_t_55 make_env_t_55(number_t y) {
	env_t_55 env;
	env.y = y;
	return env;
}

value_t lambda55(env_t_55* env47, number_t xi) {
	number_t y46 = env47->y;
	value_t res;
	res.number_t_value = (xi) * (y46);
	return res;
}
typedef struct env_t_56 {
	number_t y_d;
	number_t y;
} env_t_56;
env_t_56 make_env_t_56(number_t y_d,number_t y) {
	env_t_56 env;
	env.y_d = y_d;
	env.y = y;
	return env;
}

value_t lambda56(env_t_56* env52, number_t xi, number_t xi_d) {
	number_t y_d51 = env52->y_d;
	number_t y50 = env52->y;
	value_t res;
	res.number_t_value = ((xi_d) * (y50)) + ((xi) * (y_d51));
	return res;
}
array_number_t TOP_LEVEL_linalg_mult_by_scalar_d(array_number_t x, number_t y, array_number_t x_d, number_t y_d) {
	env_t_55 env_t_55_value = make_env_t_55(y); closure_t closure49 = make_closure(lambda55, &env_t_55_value);
	env_t_56 env_t_56_value = make_env_t_56(y_d,y); closure_t closure54 = make_closure(lambda56, &env_t_56_value);
	return TOP_LEVEL_linalg_vectorMap_d(closure49, x, closure54, x_d);
}
typedef struct env_t_68 {
	number_t y;
	number_t a;
} env_t_68;
env_t_68 make_env_t_68(number_t y,number_t a) {
	env_t_68 env;
	env.y = y;
	env.a = a;
	return env;
}

value_t lambda68(env_t_68* env59, number_t xi) {
	number_t y58 = env59->y;
	number_t a57 = env59->a;
	value_t res;
	res.number_t_value = ((a57) * (xi)) + (y58);
	return res;
}
typedef struct env_t_69 {
	number_t y_d;
	number_t a_d;
	number_t a;
} env_t_69;
env_t_69 make_env_t_69(number_t y_d,number_t a_d,number_t a) {
	env_t_69 env;
	env.y_d = y_d;
	env.a_d = a_d;
	env.a = a;
	return env;
}

value_t lambda69(env_t_69* env65, number_t xi, number_t xi_d) {
	number_t y_d64 = env65->y_d;
	number_t a_d63 = env65->a_d;
	number_t a62 = env65->a;
	value_t res;
	res.number_t_value = (((a_d63) * (xi)) + ((a62) * (xi_d))) + (y_d64);
	return res;
}
array_number_t TOP_LEVEL_linalg_gaxpy_d(number_t a, array_number_t x, number_t y, number_t a_d, array_number_t x_d, number_t y_d) {
	env_t_68 env_t_68_value = make_env_t_68(y,a); closure_t closure61 = make_closure(lambda68, &env_t_68_value);
	env_t_69 env_t_69_value = make_env_t_69(y_d,a_d,a); closure_t closure67 = make_closure(lambda69, &env_t_69_value);
	return TOP_LEVEL_linalg_vectorMap_d(closure61, x, closure67, x_d);
}

array_number_t TOP_LEVEL_linalg_cross_d(array_number_t a, array_number_t b, array_number_t a_d, array_number_t b_d) {
	array_number_t array70 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array70->length=3;
	array70->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array70->arr[0] = (((a_d->arr[1]) * (b->arr[2])) + ((a->arr[1]) * (b_d->arr[2]))) - (((a_d->arr[2]) * (b->arr[1])) + ((a->arr[2]) * (b_d->arr[1])));
	array70->arr[1] = (((a_d->arr[2]) * (b->arr[0])) + ((a->arr[2]) * (b_d->arr[0]))) - (((a_d->arr[0]) * (b->arr[2])) + ((a->arr[0]) * (b_d->arr[2])));
	array70->arr[2] = (((a_d->arr[0]) * (b->arr[1])) + ((a->arr[0]) * (b_d->arr[1]))) - (((a_d->arr[1]) * (b->arr[0])) + ((a->arr[1]) * (b_d->arr[0])));;
	return array70;
}
typedef empty_env_t env_t_77;


value_t lambda77(env_t_77* env71, number_t x0, number_t y0) {
	
	value_t res;
	res.number_t_value = (x0) + (y0);
	return res;
}
typedef empty_env_t env_t_78;


value_t lambda78(env_t_78* env74, number_t x0, number_t y0, number_t x_d0, number_t y_d0) {
	
	value_t res;
	res.number_t_value = (x_d0) + (y_d0);
	return res;
}
array_number_t TOP_LEVEL_linalg_vectorAdd_d(array_number_t x, array_number_t y, array_number_t x_d, array_number_t y_d) {
	env_t_77 env_t_77_value = make_empty_env(); closure_t closure73 = make_closure(lambda77, &env_t_77_value);
	env_t_78 env_t_78_value = make_empty_env(); closure_t closure76 = make_closure(lambda78, &env_t_78_value);
	return TOP_LEVEL_linalg_vectorMap2_d(closure73, x, y, closure76, x_d, y_d);
}
typedef empty_env_t env_t_85;


value_t lambda85(env_t_85* env79, number_t x0, number_t y0) {
	
	value_t res;
	res.number_t_value = (x0) * (y0);
	return res;
}
typedef empty_env_t env_t_86;


value_t lambda86(env_t_86* env82, number_t x0, number_t y0, number_t x_d0, number_t y_d0) {
	
	value_t res;
	res.number_t_value = ((x_d0) * (y0)) + ((x0) * (y_d0));
	return res;
}
array_number_t TOP_LEVEL_linalg_mult_vec_elementwise_d(array_number_t x, array_number_t y, array_number_t x_d, array_number_t y_d) {
	env_t_85 env_t_85_value = make_empty_env(); closure_t closure81 = make_closure(lambda85, &env_t_85_value);
	env_t_86 env_t_86_value = make_empty_env(); closure_t closure84 = make_closure(lambda86, &env_t_86_value);
	return TOP_LEVEL_linalg_vectorMap2_d(closure81, x, y, closure84, x_d, y_d);
}
typedef empty_env_t env_t_93;


value_t lambda93(env_t_93* env87, number_t x0, number_t y0) {
	
	value_t res;
	res.number_t_value = (x0) * (y0);
	return res;
}
typedef empty_env_t env_t_94;


value_t lambda94(env_t_94* env90, number_t x0, number_t y0, number_t x_d0, number_t y_d0) {
	
	value_t res;
	res.number_t_value = ((x_d0) * (y0)) + ((x0) * (y_d0));
	return res;
}
array_number_t TOP_LEVEL_linalg_op_DotMultiply_d(array_number_t x, array_number_t y, array_number_t x_d, array_number_t y_d) {
	env_t_93 env_t_93_value = make_empty_env(); closure_t closure89 = make_closure(lambda93, &env_t_93_value);
	env_t_94 env_t_94_value = make_empty_env(); closure_t closure92 = make_closure(lambda94, &env_t_94_value);
	return TOP_LEVEL_linalg_vectorMap2_d(closure89, x, y, closure92, x_d, y_d);
}

array_number_t TOP_LEVEL_linalg_vectorAdd3_d(array_number_t x, array_number_t y, array_number_t z, array_number_t x_d, array_number_t y_d, array_number_t z_d) {
	
	return TOP_LEVEL_linalg_vectorAdd_d(TOP_LEVEL_linalg_vectorAdd(x, y), z, TOP_LEVEL_linalg_vectorAdd_d(x, y, x_d, y_d), z_d);
}
typedef empty_env_t env_t_101;


value_t lambda101(env_t_101* env95, number_t x0, number_t y0) {
	
	value_t res;
	res.number_t_value = (x0) - (y0);
	return res;
}
typedef empty_env_t env_t_102;


value_t lambda102(env_t_102* env98, number_t x0, number_t y0, number_t x_d0, number_t y_d0) {
	
	value_t res;
	res.number_t_value = (x_d0) - (y_d0);
	return res;
}
array_number_t TOP_LEVEL_linalg_vectorSub_d(array_number_t x, array_number_t y, array_number_t x_d, array_number_t y_d) {
	env_t_101 env_t_101_value = make_empty_env(); closure_t closure97 = make_closure(lambda101, &env_t_101_value);
	env_t_102 env_t_102_value = make_empty_env(); closure_t closure100 = make_closure(lambda102, &env_t_102_value);
	return TOP_LEVEL_linalg_vectorMap2_d(closure97, x, y, closure100, x_d, y_d);
}
typedef empty_env_t env_t_109;


value_t lambda109(env_t_109* env103, array_number_t x0, array_number_t y0) {
	
	value_t res;
	res.array_number_t_value = TOP_LEVEL_linalg_vectorAdd(x0, y0);
	return res;
}
typedef empty_env_t env_t_110;


value_t lambda110(env_t_110* env106, array_number_t x0, array_number_t y0, array_number_t x_d0, array_number_t y_d0) {
	
	value_t res;
	res.array_number_t_value = TOP_LEVEL_linalg_vectorAdd_d(x0, y0, x_d0, y_d0);
	return res;
}
array_array_number_t TOP_LEVEL_linalg_matrixAdd_d(array_array_number_t x, array_array_number_t y, array_array_number_t x_d, array_array_number_t y_d) {
	env_t_109 env_t_109_value = make_empty_env(); closure_t closure105 = make_closure(lambda109, &env_t_109_value);
	env_t_110 env_t_110_value = make_empty_env(); closure_t closure108 = make_closure(lambda110, &env_t_110_value);
	return TOP_LEVEL_linalg_matrixMap2_d(closure105, x, y, closure108, x_d, y_d);
}
typedef empty_env_t env_t_117;


value_t lambda117(env_t_117* env111, array_number_t x0, array_number_t y0) {
	
	value_t res;
	res.array_number_t_value = TOP_LEVEL_linalg_mult_vec_elementwise(x0, y0);
	return res;
}
typedef empty_env_t env_t_118;


value_t lambda118(env_t_118* env114, array_number_t x0, array_number_t y0, array_number_t x_d0, array_number_t y_d0) {
	
	value_t res;
	res.array_number_t_value = TOP_LEVEL_linalg_mult_vec_elementwise_d(x0, y0, x_d0, y_d0);
	return res;
}
array_array_number_t TOP_LEVEL_linalg_matrixMultElementwise_d(array_array_number_t x, array_array_number_t y, array_array_number_t x_d, array_array_number_t y_d) {
	env_t_117 env_t_117_value = make_empty_env(); closure_t closure113 = make_closure(lambda117, &env_t_117_value);
	env_t_118 env_t_118_value = make_empty_env(); closure_t closure116 = make_closure(lambda118, &env_t_118_value);
	return TOP_LEVEL_linalg_matrixMap2_d(closure113, x, y, closure116, x_d, y_d);
}
typedef empty_env_t env_t_128;


value_t lambda128(env_t_128* env119, number_t x1) {
	
	value_t res;
	res.number_t_value = (x1) * (x1);
	return res;
}
typedef empty_env_t env_t_129;


value_t lambda129(env_t_129* env122, number_t x1) {
	
	value_t res;
	res.number_t_value = (x1) * (x1);
	return res;
}
typedef empty_env_t env_t_130;


value_t lambda130(env_t_130* env125, number_t x1, number_t x1_d) {
	
	value_t res;
	res.number_t_value = ((x1_d) * (x1)) + ((x1) * (x1_d));
	return res;
}
number_t TOP_LEVEL_linalg_sqnorm_d(array_number_t x, array_number_t x_d) {
	env_t_128 env_t_128_value = make_empty_env(); closure_t closure121 = make_closure(lambda128, &env_t_128_value);
	env_t_129 env_t_129_value = make_empty_env(); closure_t closure124 = make_closure(lambda129, &env_t_129_value);
	env_t_130 env_t_130_value = make_empty_env(); closure_t closure127 = make_closure(lambda130, &env_t_130_value);
	return TOP_LEVEL_linalg_vectorSum_d(TOP_LEVEL_linalg_vectorMap(closure121, x), TOP_LEVEL_linalg_vectorMap_d(closure124, x, closure127, x_d));
}
typedef empty_env_t env_t_140;


value_t lambda140(env_t_140* env131, number_t x0, number_t y0) {
	
	value_t res;
	res.number_t_value = (x0) * (y0);
	return res;
}
typedef empty_env_t env_t_141;


value_t lambda141(env_t_141* env134, number_t x0, number_t y0) {
	
	value_t res;
	res.number_t_value = (x0) * (y0);
	return res;
}
typedef empty_env_t env_t_142;


value_t lambda142(env_t_142* env137, number_t x0, number_t y0, number_t x_d0, number_t y_d0) {
	
	value_t res;
	res.number_t_value = ((x_d0) * (y0)) + ((x0) * (y_d0));
	return res;
}
number_t TOP_LEVEL_linalg_dot_prod_d(array_number_t x, array_number_t y, array_number_t x_d, array_number_t y_d) {
	env_t_140 env_t_140_value = make_empty_env(); closure_t closure133 = make_closure(lambda140, &env_t_140_value);
	env_t_141 env_t_141_value = make_empty_env(); closure_t closure136 = make_closure(lambda141, &env_t_141_value);
	env_t_142 env_t_142_value = make_empty_env(); closure_t closure139 = make_closure(lambda142, &env_t_142_value);
	return TOP_LEVEL_linalg_vectorSum_d(TOP_LEVEL_linalg_vectorMap2(closure133, x, y), TOP_LEVEL_linalg_vectorMap2_d(closure136, x, y, closure139, x_d, y_d));
}
typedef struct env_t_151 {
	array_number_t row;
} env_t_151;
env_t_151 make_env_t_151(array_number_t row) {
	env_t_151 env;
	env.row = row;
	return env;
}

value_t lambda151(env_t_151* env144, number_t r) {
	array_number_t row143 = env144->row;
	value_t res;
	res.array_number_t_value = row143;
	return res;
}
typedef struct env_t_152 {
	array_number_t row_d;
} env_t_152;
env_t_152 make_env_t_152(array_number_t row_d) {
	env_t_152 env;
	env.row_d = row_d;
	return env;
}

value_t lambda152(env_t_152* env148, number_t r, number_t r_d) {
	array_number_t row_d147 = env148->row_d;
	value_t res;
	res.array_number_t_value = row_d147;
	return res;
}
array_array_number_t TOP_LEVEL_linalg_matrixFillFromVector_d(card_t rows, array_number_t row, card_t rows_d, array_number_t row_d) {
	env_t_151 env_t_151_value = make_env_t_151(row); closure_t closure146 = make_closure(lambda151, &env_t_151_value);
	env_t_152 env_t_152_value = make_env_t_152(row_d); closure_t closure150 = make_closure(lambda152, &env_t_152_value);
	return TOP_LEVEL_linalg_vectorMapToMatrix_d(closure146, TOP_LEVEL_linalg_vectorRange(1, rows), closure150, TOP_LEVEL_linalg_vectorRange_d(1, rows, 1, rows));
}

array_array_number_t TOP_LEVEL_linalg_matrixFill_d(card_t rows, card_t cols, number_t value, card_t rows_d, card_t cols_d, number_t value_d) {
	array_array_number_t macroDef154 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef154->length=rows;
	macroDef154->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * rows);
		for(int r = 0; r < macroDef154->length; r++){
			array_number_t macroDef153 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef153->length=cols;
	macroDef153->arr = (number_t*)storage_alloc(sizeof(number_t) * cols);
		for(int c = 0; c < macroDef153->length; c++){
			
			macroDef153->arr[c] = value_d;;
		}
			macroDef154->arr[r] = macroDef153;;
		}
	return macroDef154;
}

array_array_number_t TOP_LEVEL_linalg_matrixTranspose_d(array_array_number_t m, array_array_number_t m_d) {
	card_t macroDef155 = m->length;
	card_t rows = macroDef155;
	card_t macroDef156 = m->length;
	card_t rows_d = macroDef156;
	card_t macroDef157 = m->arr[0]->length;
	card_t cols = macroDef157;
	card_t macroDef158 = m->arr[0]->length;
	card_t cols_d = macroDef158;
	array_array_number_t macroDef160 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef160->length=cols;
	macroDef160->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * cols);
		for(int i = 0; i < macroDef160->length; i++){
			array_number_t macroDef159 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef159->length=rows;
	macroDef159->arr = (number_t*)storage_alloc(sizeof(number_t) * rows);
		for(int j = 0; j < macroDef159->length; j++){
			
			macroDef159->arr[j] = m_d->arr[j]->arr[i];;
		}
			macroDef160->arr[i] = macroDef159;;
		}
	return macroDef160;
}

array_array_number_t TOP_LEVEL_linalg_matrixMult_d(array_array_number_t m1, array_array_number_t m2, array_array_number_t m1_d, array_array_number_t m2_d) {
	card_t macroDef161 = m1->length;
	card_t r1 = macroDef161;
	card_t macroDef162 = m1->length;
	card_t r1_d = macroDef162;
	card_t macroDef163 = m2->arr[0]->length;
	card_t c2 = macroDef163;
	card_t macroDef164 = m2->arr[0]->length;
	card_t c2_d = macroDef164;
	card_t macroDef165 = m1->arr[0]->length;
	card_t c1 = macroDef165;
	card_t macroDef166 = m1->arr[0]->length;
	card_t c1_d = macroDef166;
	card_t macroDef167 = m2->length;
	card_t r2 = macroDef167;
	card_t macroDef168 = m2->length;
	card_t r2_d = macroDef168;
	array_array_number_t m2T = TOP_LEVEL_linalg_matrixTranspose(m2);
	array_array_number_t m2T_d = TOP_LEVEL_linalg_matrixTranspose_d(m2, m2_d);
	array_array_number_t macroDef170 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef170->length=r1;
	macroDef170->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * r1);
		for(int r = 0; r < macroDef170->length; r++){
			array_number_t macroDef169 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef169->length=c2;
	macroDef169->arr = (number_t*)storage_alloc(sizeof(number_t) * c2);
		for(int c = 0; c < macroDef169->length; c++){
			
			macroDef169->arr[c] = TOP_LEVEL_linalg_dot_prod_d(m1->arr[r], m2T->arr[c], m1_d->arr[r], m2T_d->arr[c]);;
		}
			macroDef170->arr[r] = macroDef169;;
		}
	return macroDef170;
}

array_number_t TOP_LEVEL_linalg_matrixVectorMult_d(array_array_number_t m, array_number_t v, array_array_number_t m_d, array_number_t v_d) {
	card_t r = TOP_LEVEL_linalg_rows(m);
	card_t r_d = TOP_LEVEL_linalg_rows(m);
	card_t c = TOP_LEVEL_linalg_cols(m);
	card_t c_d = TOP_LEVEL_linalg_cols(m);
	array_number_t macroDef171 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef171->length=r;
	macroDef171->arr = (number_t*)storage_alloc(sizeof(number_t) * r);
		for(int i = 0; i < macroDef171->length; i++){
			
			macroDef171->arr[i] = TOP_LEVEL_linalg_dot_prod_d(m->arr[i], v, m_d->arr[i], v_d);;
		}
	return macroDef171;
}

array_array_number_t TOP_LEVEL_linalg_matrixConcat_d(array_array_number_t m1, array_array_number_t m2, array_array_number_t m1_d, array_array_number_t m2_d) {
	card_t macroDef172 = m1->length;
	card_t macroDef173 = m2->length;
	card_t rows = (macroDef172) + (macroDef173);
	card_t macroDef174 = m1->length;
	card_t macroDef175 = m2->length;
	card_t rows_d = (macroDef174) + (macroDef175);
	card_t macroDef176 = m1->length;
	index_t m1Rows = (macroDef176);
	card_t macroDef177 = m1->length;
	index_t m1Rows_d = (macroDef177);
	array_array_number_t macroDef178 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef178->length=rows;
	macroDef178->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * rows);
		for(int r = 0; r < macroDef178->length; r++){
			array_number_t ite179 = 0;
	if((r) < (m1Rows)) {
		
		ite179 = m1_d->arr[r];;
	} else {
		
		ite179 = m2_d->arr[(r) - (m1Rows)];;
	}
			macroDef178->arr[r] = ite179;;
		}
	return macroDef178;
}

array_array_number_t TOP_LEVEL_linalg_matrixConcatCol_d(array_array_number_t m1, array_array_number_t m2, array_array_number_t m1_d, array_array_number_t m2_d) {
	array_array_number_t m1t = TOP_LEVEL_linalg_matrixTranspose(m1);
	array_array_number_t m1t_d = TOP_LEVEL_linalg_matrixTranspose_d(m1, m1_d);
	array_array_number_t m2t = TOP_LEVEL_linalg_matrixTranspose(m2);
	array_array_number_t m2t_d = TOP_LEVEL_linalg_matrixTranspose_d(m2, m2_d);
	return TOP_LEVEL_linalg_matrixTranspose_d(TOP_LEVEL_linalg_matrixConcat(m1t, m2t), TOP_LEVEL_linalg_matrixConcat_d(m1t, m2t, m1t_d, m2t_d));
}

array_array_array_number_t TOP_LEVEL_linalg_matrix3DConcat_d(array_array_array_number_t m1, array_array_array_number_t m2, array_array_array_number_t m1_d, array_array_array_number_t m2_d) {
	card_t macroDef180 = m1->length;
	card_t macroDef181 = m2->length;
	card_t rows = (macroDef180) + (macroDef181);
	card_t macroDef182 = m1->length;
	card_t macroDef183 = m2->length;
	card_t rows_d = (macroDef182) + (macroDef183);
	card_t macroDef184 = m1->length;
	index_t m1Rows = (macroDef184);
	card_t macroDef185 = m1->length;
	index_t m1Rows_d = (macroDef185);
	array_array_array_number_t macroDef186 = (array_array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef186->length=rows;
	macroDef186->arr = (array_array_number_t*)storage_alloc(sizeof(array_array_number_t) * rows);
		for(int r = 0; r < macroDef186->length; r++){
			array_array_number_t ite187 = 0;
	if((r) < (m1Rows)) {
		
		ite187 = m1_d->arr[r];;
	} else {
		
		ite187 = m2_d->arr[(r) - (m1Rows)];;
	}
			macroDef186->arr[r] = ite187;;
		}
	return macroDef186;
}

array_number_t TOP_LEVEL_linalg_vectorRead_d(string_t fn, index_t startLine, card_t cols, string_t fn_d, index_t startLine_d, card_t cols_d) {
	array_array_number_t matrix = matrix_read(fn, startLine, 1, cols);
	array_array_number_t matrix_d = matrix_read(fn, startLine, 1, cols);
	return matrix_d->arr[0];
}

number_t TOP_LEVEL_linalg_numberRead_d(string_t fn, index_t startLine, string_t fn_d, index_t startLine_d) {
	array_number_t vector = TOP_LEVEL_linalg_vectorRead(fn, startLine, 1);
	array_number_t vector_d = TOP_LEVEL_linalg_vectorRead_d(fn, startLine, 1, "", 0, 1);
	return vector_d->arr[0];
}

array_number_t TOP_LEVEL_linalg_vec3_d(number_t a, number_t b, number_t c, number_t a_d, number_t b_d, number_t c_d) {
	array_number_t array188 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array188->length=3;
	array188->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array188->arr[0] = a_d;
	array188->arr[1] = b_d;
	array188->arr[2] = c_d;;
	return array188;
}
#endif
