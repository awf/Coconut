#ifndef __LINALGTESTS_STORAGED_H__ 
#define __LINALGTESTS_STORAGED_H__ 
#include "runtime/fsharp.h"
#include <stdio.h>
#include <math.h>
#include "linalg_storaged.h"

card_t TOP_LEVEL_linalgtests_test1_c(vector_shape_t dum_c) {
	
	return 0;
}


void TOP_LEVEL_linalgtests_test1_s(storage_t stgVar491, array_number_t dum_s, vector_shape_t dum_c) {
	vector_shape_t a_c = nested_shape_card_t(0, 3);
	array_number_t stgVar492 = malloc(width_vector_shape_t(a_c));
	array_number_t macroDef555 = (array_number_t)stgVar492;
	macroDef555->length=3;
	macroDef555->arr=(number_t*)((char*)stgVar492 + VECTOR_HEADER_BYTES);
	macroDef555->arr[0] = 1;
	macroDef555->arr[1] = 2;
	macroDef555->arr[2] = 3;;
	array_number_t a_s = macroDef555;
	vector_shape_t b_c = nested_shape_card_t(0, 3);
	array_number_t stgVar496 = malloc(width_vector_shape_t(b_c));
	array_number_t macroDef556 = (array_number_t)stgVar496;
	macroDef556->length=3;
	macroDef556->arr=(number_t*)((char*)stgVar496 + VECTOR_HEADER_BYTES);
	macroDef556->arr[0] = 5;
	macroDef556->arr[1] = 6;
	macroDef556->arr[2] = 7;;
	array_number_t b_s = macroDef556;
	array_print(a_s);
	array_print(b_s);
	vector_shape_t c_c = TOP_LEVEL_linalg_cross_c(a_c, b_c);
	array_number_t stgVar500 = malloc(width_vector_shape_t(c_c));
	array_number_t c_s = TOP_LEVEL_linalg_cross_s(stgVar500, a_s, b_s, a_c, b_c);
	array_print(c_s);
	vector_shape_t d_c = TOP_LEVEL_linalg_mult_by_scalar_c(c_c, 0);
	array_number_t stgVar503 = malloc(width_vector_shape_t(d_c));
	array_number_t d_s = TOP_LEVEL_linalg_mult_by_scalar_s(stgVar503, c_s, 15, c_c, 0);
	array_print(d_s);
	vector_shape_t e_c = TOP_LEVEL_linalg_add_vec_c(a_c, b_c);
	array_number_t stgVar506 = malloc(width_vector_shape_t(e_c));
	array_number_t e_s = TOP_LEVEL_linalg_add_vec_s(stgVar506, a_s, b_s, a_c, b_c);
	array_print(e_s);
	vector_shape_t f_c = TOP_LEVEL_linalg_sub_vec_c(a_c, b_c);
	array_number_t stgVar509 = malloc(width_vector_shape_t(f_c));
	array_number_t f_s = TOP_LEVEL_linalg_sub_vec_s(stgVar509, a_s, b_s, a_c, b_c);
	array_print(f_s);
	vector_shape_t g_c = TOP_LEVEL_linalg_add_vec3_c(a_c, b_c, c_c);
	array_number_t stgVar512 = malloc(width_vector_shape_t(g_c));
	array_number_t g_s = TOP_LEVEL_linalg_add_vec3_s(stgVar512, a_s, b_s, c_s, a_c, b_c, c_c);
	array_print(g_s);
	card_t h_c = 0;
	array_number_t stgVar516 = malloc(h_c);
	number_t h_s = TOP_LEVEL_linalg_sqnorm_s(stgVar516, a_s, a_c);
	number_print(h_s);
	card_t i_c = 0;
	array_number_t stgVar518 = malloc(i_c);
	number_t i_s = TOP_LEVEL_linalg_dot_prod_s(stgVar518, a_s, b_s, a_c, b_c);
	number_print(i_s);
	vector_shape_t r1_c = nested_shape_card_t(0, 3);
	array_number_t stgVar521 = malloc(width_vector_shape_t(r1_c));
	array_number_t macroDef557 = (array_number_t)stgVar521;
	macroDef557->length=3;
	macroDef557->arr=(number_t*)((char*)stgVar521 + VECTOR_HEADER_BYTES);
	macroDef557->arr[0] = 1;
	macroDef557->arr[1] = 2;
	macroDef557->arr[2] = 3;;
	array_number_t r1_s = macroDef557;
	vector_shape_t r2_c = nested_shape_card_t(0, 3);
	array_number_t stgVar525 = malloc(width_vector_shape_t(r2_c));
	array_number_t macroDef558 = (array_number_t)stgVar525;
	macroDef558->length=3;
	macroDef558->arr=(number_t*)((char*)stgVar525 + VECTOR_HEADER_BYTES);
	macroDef558->arr[0] = 4;
	macroDef558->arr[1] = 5;
	macroDef558->arr[2] = 6;;
	array_number_t r2_s = macroDef558;
	vector_shape_t r3_c = nested_shape_card_t(0, 3);
	array_number_t stgVar529 = malloc(width_vector_shape_t(r3_c));
	array_number_t macroDef559 = (array_number_t)stgVar529;
	macroDef559->length=3;
	macroDef559->arr=(number_t*)((char*)stgVar529 + VECTOR_HEADER_BYTES);
	macroDef559->arr[0] = 7;
	macroDef559->arr[1] = 8;
	macroDef559->arr[2] = 9;;
	array_number_t r3_s = macroDef559;
	matrix_shape_t mat1_c = nested_shape_vector_shape_t(r1_c, 3);
	array_number_t stgVar533 = malloc(width_matrix_shape_t(mat1_c));
	array_array_number_t macroDef560 = (array_array_number_t)stgVar533;
	macroDef560->length=3;
	macroDef560->arr=(array_number_t*)((char*)stgVar533 + VECTOR_HEADER_BYTES);
	macroDef560->arr[0] = r1_s;
	macroDef560->arr[1] = r2_s;
	macroDef560->arr[2] = r3_s;;
	array_array_number_t mat1_s = macroDef560;
	matrix_shape_t n_c = TOP_LEVEL_linalg_matrixMult_c(mat1_c, mat1_c);
	array_number_t stgVar537 = malloc(width_matrix_shape_t(n_c));
	array_array_number_t n_s = TOP_LEVEL_linalg_matrixMult_s(stgVar537, mat1_s, mat1_s, mat1_c, mat1_c);
	matrix_print(n_s);
	matrix_shape_t o_c = TOP_LEVEL_linalg_matrixTranspose_c(n_c);
	array_number_t stgVar540 = malloc(width_matrix_shape_t(o_c));
	array_array_number_t o_s = TOP_LEVEL_linalg_matrixTranspose_s(stgVar540, n_s, n_c);
	matrix_print(o_s);
	matrix_shape_t p_c = TOP_LEVEL_linalg_matrixConcatCol_c(mat1_c, mat1_c);
	array_number_t stgVar542 = malloc(width_matrix_shape_t(p_c));
	array_array_number_t p_s = TOP_LEVEL_linalg_matrixConcatCol_s(stgVar542, mat1_s, mat1_s, mat1_c, mat1_c);
	matrix_print(p_s);
	matrix_shape_t t_c = TOP_LEVEL_linalg_matrixAdd_c(mat1_c, mat1_c);
	array_number_t stgVar545 = malloc(width_matrix_shape_t(t_c));
	array_array_number_t t_s = TOP_LEVEL_linalg_matrixAdd_s(stgVar545, mat1_s, mat1_s, mat1_c, mat1_c);
	matrix_print(t_s);
	matrix_shape_t u_c = TOP_LEVEL_linalg_matrixFillFromVector_c(5, a_c);
	array_number_t stgVar548 = malloc(width_matrix_shape_t(u_c));
	array_array_number_t u_s = TOP_LEVEL_linalg_matrixFillFromVector_s(stgVar548, 5, a_s, 5, a_c);
	matrix_print(u_s);
	matrix_shape_t v_c = TOP_LEVEL_linalg_matrixFill_c(5, 2, 0);
	array_number_t stgVar551 = malloc(width_matrix_shape_t(v_c));
	array_array_number_t v_s = TOP_LEVEL_linalg_matrixFill_s(stgVar551, 5, 2, 5, 5, 2, 0);
	matrix_print(v_s);
	;
	free(stgVar551);
	;
	free(stgVar548);
	;
	free(stgVar545);
	;
	free(stgVar542);
	;
	free(stgVar540);
	;
	free(stgVar537);
	;
	free(stgVar533);
	;
	free(stgVar529);
	;
	free(stgVar525);
	;
	free(stgVar521);
	;
	free(stgVar518);
	;
	free(stgVar516);
	;
	free(stgVar512);
	;
	free(stgVar509);
	;
	free(stgVar506);
	;
	free(stgVar503);
	;
	free(stgVar500);
	;
	free(stgVar496);
	;
	free(stgVar492);
	return ;
}
#endif