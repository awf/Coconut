#ifndef __LINALG_H__ 
#define __LINALG_H__ 
#include "runtime/fsharp.h"
#include <stdio.h>
#include <math.h>
typedef struct env_t_6 {
	array_number_t v;
	closure_t* f;
} env_t_6;
env_t_6* make_env_t_6(array_number_t v,closure_t* f) {
	env_t_6* env = (env_t_6*)malloc(sizeof(env_t_6));
	env->v = v;
	env->f = f;
	return env;
}

value_t lambda6(env_t_6* env3, index_t i) {
	array_number_t v2 = env3->v;
	closure_t* f1 = env3->f;
	value_t res;
	res.number_t_value = f1->lam(f1->env, v2->arr[i]).number_t_value;
	return res;
}
array_number_t linalg_vectorMap(closure_t* f, array_number_t v) {
	closure_t* closure5 = make_closure(lambda6, make_env_t_6(v,f));
	return vector_build(v->length, closure5);
}
typedef struct env_t_11 {
	index_t s;
} env_t_11;
env_t_11* make_env_t_11(index_t s) {
	env_t_11* env = (env_t_11*)malloc(sizeof(env_t_11));
	env->s = s;
	return env;
}

value_t lambda11(env_t_11* env8, index_t i) {
	index_t s7 = env8->s;
	value_t res;
	res.number_t_value = (double)((s7) + (i));
	return res;
}
array_number_t linalg_vectorRange(index_t s, index_t e) {
	closure_t* closure10 = make_closure(lambda11, make_env_t_11(s));
	return vector_build(((e) - (s)) + (1), closure10);
}
typedef struct env_t_17 {
	array_array_number_t m;
	closure_t* f;
} env_t_17;
env_t_17* make_env_t_17(array_array_number_t m,closure_t* f) {
	env_t_17* env = (env_t_17*)malloc(sizeof(env_t_17));
	env->m = m;
	env->f = f;
	return env;
}

value_t lambda17(env_t_17* env14, index_t i) {
	array_array_number_t m13 = env14->m;
	closure_t* f12 = env14->f;
	value_t res;
	res.array_number_t_value = f12->lam(f12->env, m13->arr[i]).array_number_t_value;
	return res;
}
array_array_number_t linalg_matrixMap(closure_t* f, array_array_number_t m) {
	closure_t* closure16 = make_closure(lambda17, make_env_t_17(m,f));
	return matrix_build(m->length, closure16);
}
typedef struct env_t_24 {
	array_number_t v2;
	array_number_t v1;
	closure_t* f;
} env_t_24;
env_t_24* make_env_t_24(array_number_t v2,array_number_t v1,closure_t* f) {
	env_t_24* env = (env_t_24*)malloc(sizeof(env_t_24));
	env->v2 = v2;
	env->v1 = v1;
	env->f = f;
	return env;
}

value_t lambda24(env_t_24* env21, index_t i) {
	array_number_t v220 = env21->v2;
	array_number_t v119 = env21->v1;
	closure_t* f18 = env21->f;
	value_t res;
	res.number_t_value = f18->lam(f18->env, v119->arr[i], v220->arr[i]).number_t_value;
	return res;
}
array_number_t linalg_vectorMap2(closure_t* f, array_number_t v1, array_number_t v2) {
	closure_t* closure23 = make_closure(lambda24, make_env_t_24(v2,v1,f));
	return vector_build(v1->length, closure23);
}
typedef struct env_t_31 {
	array_array_number_t m2;
	array_array_number_t m1;
	closure_t* f;
} env_t_31;
env_t_31* make_env_t_31(array_array_number_t m2,array_array_number_t m1,closure_t* f) {
	env_t_31* env = (env_t_31*)malloc(sizeof(env_t_31));
	env->m2 = m2;
	env->m1 = m1;
	env->f = f;
	return env;
}

value_t lambda31(env_t_31* env28, index_t i) {
	array_array_number_t m227 = env28->m2;
	array_array_number_t m126 = env28->m1;
	closure_t* f25 = env28->f;
	value_t res;
	res.array_number_t_value = f25->lam(f25->env, m126->arr[i], m227->arr[i]).array_number_t_value;
	return res;
}
array_array_number_t linalg_matrixMap2(closure_t* f, array_array_number_t m1, array_array_number_t m2) {
	closure_t* closure30 = make_closure(lambda31, make_env_t_31(m2,m1,f));
	return matrix_build(m1->length, closure30);
}
typedef struct env_t_38 {
	array_array_array_number_t m2;
	array_array_array_number_t m1;
	closure_t* f;
} env_t_38;
env_t_38* make_env_t_38(array_array_array_number_t m2,array_array_array_number_t m1,closure_t* f) {
	env_t_38* env = (env_t_38*)malloc(sizeof(env_t_38));
	env->m2 = m2;
	env->m1 = m1;
	env->f = f;
	return env;
}

value_t lambda38(env_t_38* env35, index_t i) {
	array_array_array_number_t m234 = env35->m2;
	array_array_array_number_t m133 = env35->m1;
	closure_t* f32 = env35->f;
	value_t res;
	res.array_array_number_t_value = f32->lam(f32->env, m133->arr[i], m234->arr[i]).array_array_number_t_value;
	return res;
}
array_array_array_number_t linalg_matrix3DMap2(closure_t* f, array_array_array_number_t m1, array_array_array_number_t m2) {
	closure_t* closure37 = make_closure(lambda38, make_env_t_38(m2,m1,f));
	return matrix3d_build(m1->length, closure37);
}
typedef struct env_t_44 {
	closure_t* f;
	array_number_t arr;
} env_t_44;
env_t_44* make_env_t_44(closure_t* f,array_number_t arr) {
	env_t_44* env = (env_t_44*)malloc(sizeof(env_t_44));
	env->f = f;
	env->arr = arr;
	return env;
}

value_t lambda44(env_t_44* env41, index_t i) {
	closure_t* f40 = env41->f;
	array_number_t arr39 = env41->arr;
	value_t res;
	res.array_number_t_value = f40->lam(f40->env, arr39->arr[i]).array_number_t_value;
	return res;
}
array_array_number_t linalg_vectorMapToMatrix(closure_t* f, array_number_t arr) {
	closure_t* closure43 = make_closure(lambda44, make_env_t_44(f,arr));
	return matrix_build(arr->length, closure43);
}
typedef struct env_t_50 {
	closure_t* f;
	array_number_t arr;
} env_t_50;
env_t_50* make_env_t_50(closure_t* f,array_number_t arr) {
	env_t_50* env = (env_t_50*)malloc(sizeof(env_t_50));
	env->f = f;
	env->arr = arr;
	return env;
}

value_t lambda50(env_t_50* env47, index_t i) {
	closure_t* f46 = env47->f;
	array_number_t arr45 = env47->arr;
	value_t res;
	res.array_array_number_t_value = f46->lam(f46->env, arr45->arr[i]).array_array_number_t_value;
	return res;
}
array_array_array_number_t linalg_vectorMapToMatrix3D(closure_t* f, array_number_t arr) {
	closure_t* closure49 = make_closure(lambda50, make_env_t_50(f,arr));
	return matrix3d_build(arr->length, closure49);
}
typedef struct env_t_55 {
	closure_t* f;
} env_t_55;
env_t_55* make_env_t_55(closure_t* f) {
	env_t_55* env = (env_t_55*)malloc(sizeof(env_t_55));
	env->f = f;
	return env;
}

value_t lambda55(env_t_55* env52, array_array_number_t acc, number_t cur) {
	closure_t* f51 = env52->f;
	value_t res;
	res.array_array_number_t_value = f51->lam(f51->env, acc, (int)(cur)).array_array_number_t_value;
	return res;
}
array_array_number_t linalg_iterateMatrix(closure_t* f, array_array_number_t z, index_t s, index_t e) {
	closure_t* closure54 = make_closure(lambda55, make_env_t_55(f));
	return vector_fold_matrix(closure54, z, linalg_vectorRange(s, e));
}
typedef struct env_t_60 {
	closure_t* f;
} env_t_60;
env_t_60* make_env_t_60(closure_t* f) {
	env_t_60* env = (env_t_60*)malloc(sizeof(env_t_60));
	env->f = f;
	return env;
}

value_t lambda60(env_t_60* env57, array_array_array_number_t acc, number_t cur) {
	closure_t* f56 = env57->f;
	value_t res;
	res.array_array_array_number_t_value = f56->lam(f56->env, acc, (int)(cur)).array_array_array_number_t_value;
	return res;
}
array_array_array_number_t linalg_iterateMatrix3D(closure_t* f, array_array_array_number_t z, index_t s, index_t e) {
	closure_t* closure59 = make_closure(lambda60, make_env_t_60(f));
	return vector_fold_matrix3d(closure59, z, linalg_vectorRange(s, e));
}
typedef struct env_t_64 {
	value_t dummy_variable;
} env_t_64;
env_t_64* make_env_t_64() {
	env_t_64* env = (env_t_64*)malloc(sizeof(env_t_64));
	
	return env;
}

value_t lambda64(env_t_64* env61, number_t acc, number_t cur) {
	
	value_t res;
	res.number_t_value = (acc) + (cur);
	return res;
}
number_t linalg_arraySum(array_number_t arr) {
	closure_t* closure63 = make_closure(lambda64, make_env_t_64());
	return vector_fold_number(closure63, 0, arr);
}
typedef struct env_t_69 {
	value_t dummy_variable;
} env_t_69;
env_t_69* make_env_t_69() {
	env_t_69* env = (env_t_69*)malloc(sizeof(env_t_69));
	
	return env;
}

value_t lambda69(env_t_69* env65, number_t acc, number_t cur) {
	number_t ite68 = 0;
	if((acc) > (cur)) {
		
		ite68 = acc;
	} else {
		
		ite68 = cur;
	}
	value_t res;
	res.number_t_value = ite68;
	return res;
}
number_t linalg_arrayMax(array_number_t arr) {
	closure_t* closure67 = make_closure(lambda69, make_env_t_69());
	return vector_fold_number(closure67, -1000, arr);
}
typedef struct env_t_74 {
	number_t y;
} env_t_74;
env_t_74* make_env_t_74(number_t y) {
	env_t_74* env = (env_t_74*)malloc(sizeof(env_t_74));
	env->y = y;
	return env;
}

value_t lambda74(env_t_74* env71, number_t a) {
	number_t y70 = env71->y;
	value_t res;
	res.number_t_value = (a) * (y70);
	return res;
}
array_number_t linalg_mult_by_scalar(array_number_t x, number_t y) {
	closure_t* closure73 = make_closure(lambda74, make_env_t_74(y));
	return linalg_vectorMap(closure73, x);
}

array_number_t linalg_cross(array_number_t a, array_number_t b) {
	array_number_t array75 = (array_number_t)malloc(sizeof(int) * 2);
	array75->length=3;
	array75->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array75->arr[0] = ((a->arr[1]) * (b->arr[2])) - ((a->arr[2]) * (b->arr[1]));
	array75->arr[1] = ((a->arr[2]) * (b->arr[0])) - ((a->arr[0]) * (b->arr[2]));
	array75->arr[2] = ((a->arr[0]) * (b->arr[1])) - ((a->arr[1]) * (b->arr[0]));;
	return array75;
}
typedef struct env_t_79 {
	value_t dummy_variable;
} env_t_79;
env_t_79* make_env_t_79() {
	env_t_79* env = (env_t_79*)malloc(sizeof(env_t_79));
	
	return env;
}

value_t lambda79(env_t_79* env76, number_t x, number_t y) {
	
	value_t res;
	res.number_t_value = (x) + (y);
	return res;
}
array_number_t linalg_add_vec(array_number_t x, array_number_t y) {
	closure_t* closure78 = make_closure(lambda79, make_env_t_79());
	return linalg_vectorMap2(closure78, x, y);
}
typedef struct env_t_83 {
	value_t dummy_variable;
} env_t_83;
env_t_83* make_env_t_83() {
	env_t_83* env = (env_t_83*)malloc(sizeof(env_t_83));
	
	return env;
}

value_t lambda83(env_t_83* env80, number_t x, number_t y) {
	
	value_t res;
	res.number_t_value = (x) * (y);
	return res;
}
array_number_t linalg_mult_vec_elementwise(array_number_t x, array_number_t y) {
	closure_t* closure82 = make_closure(lambda83, make_env_t_83());
	return linalg_vectorMap2(closure82, x, y);
}

array_number_t linalg_add_vec3(array_number_t x, array_number_t y, array_number_t z) {
	
	return linalg_add_vec(linalg_add_vec(x, y), z);
}
typedef struct env_t_87 {
	value_t dummy_variable;
} env_t_87;
env_t_87* make_env_t_87() {
	env_t_87* env = (env_t_87*)malloc(sizeof(env_t_87));
	
	return env;
}

value_t lambda87(env_t_87* env84, number_t x, number_t y) {
	
	value_t res;
	res.number_t_value = (x) - (y);
	return res;
}
array_number_t linalg_sub_vec(array_number_t x, array_number_t y) {
	closure_t* closure86 = make_closure(lambda87, make_env_t_87());
	return linalg_vectorMap2(closure86, x, y);
}
typedef struct env_t_91 {
	value_t dummy_variable;
} env_t_91;
env_t_91* make_env_t_91() {
	env_t_91* env = (env_t_91*)malloc(sizeof(env_t_91));
	
	return env;
}

value_t lambda91(env_t_91* env88, array_number_t x, array_number_t y) {
	
	value_t res;
	res.array_number_t_value = linalg_add_vec(x, y);
	return res;
}
array_array_number_t linalg_matrixAdd(array_array_number_t x, array_array_number_t y) {
	closure_t* closure90 = make_closure(lambda91, make_env_t_91());
	return linalg_matrixMap2(closure90, x, y);
}
typedef struct env_t_95 {
	value_t dummy_variable;
} env_t_95;
env_t_95* make_env_t_95() {
	env_t_95* env = (env_t_95*)malloc(sizeof(env_t_95));
	
	return env;
}

value_t lambda95(env_t_95* env92, array_number_t x, array_number_t y) {
	
	value_t res;
	res.array_number_t_value = linalg_mult_vec_elementwise(x, y);
	return res;
}
array_array_number_t linalg_matrixMultElementwise(array_array_number_t x, array_array_number_t y) {
	closure_t* closure94 = make_closure(lambda95, make_env_t_95());
	return linalg_matrixMap2(closure94, x, y);
}
typedef struct env_t_99 {
	value_t dummy_variable;
} env_t_99;
env_t_99* make_env_t_99() {
	env_t_99* env = (env_t_99*)malloc(sizeof(env_t_99));
	
	return env;
}

value_t lambda99(env_t_99* env96, number_t x1) {
	
	value_t res;
	res.number_t_value = (x1) * (x1);
	return res;
}
number_t linalg_sqnorm(array_number_t x) {
	closure_t* closure98 = make_closure(lambda99, make_env_t_99());
	return linalg_arraySum(linalg_vectorMap(closure98, x));
}
typedef struct env_t_103 {
	value_t dummy_variable;
} env_t_103;
env_t_103* make_env_t_103() {
	env_t_103* env = (env_t_103*)malloc(sizeof(env_t_103));
	
	return env;
}

value_t lambda103(env_t_103* env100, number_t x, number_t y) {
	
	value_t res;
	res.number_t_value = (x) * (y);
	return res;
}
number_t linalg_dot_prod(array_number_t x, array_number_t y) {
	closure_t* closure102 = make_closure(lambda103, make_env_t_103());
	return linalg_arraySum(linalg_vectorMap2(closure102, x, y));
}
typedef struct env_t_108 {
	array_number_t row;
} env_t_108;
env_t_108* make_env_t_108(array_number_t row) {
	env_t_108* env = (env_t_108*)malloc(sizeof(env_t_108));
	env->row = row;
	return env;
}

value_t lambda108(env_t_108* env105, number_t r) {
	array_number_t row104 = env105->row;
	value_t res;
	res.array_number_t_value = row104;
	return res;
}
array_array_number_t linalg_matrixFillFromVector(index_t rows, array_number_t row) {
	closure_t* closure107 = make_closure(lambda108, make_env_t_108(row));
	return linalg_vectorMapToMatrix(closure107, linalg_vectorRange(1, rows));
}
typedef struct env_t_113 {
	number_t value;
} env_t_113;
env_t_113* make_env_t_113(number_t value) {
	env_t_113* env = (env_t_113*)malloc(sizeof(env_t_113));
	env->value = value;
	return env;
}

value_t lambda113(env_t_113* env110, number_t c) {
	number_t value109 = env110->value;
	value_t res;
	res.number_t_value = value109;
	return res;
}
array_array_number_t linalg_matrixFill(index_t rows, index_t cols, number_t value) {
	closure_t* closure112 = make_closure(lambda113, make_env_t_113(value));
	array_number_t row = linalg_vectorMap(closure112, linalg_vectorRange(1, cols));
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
#endif
