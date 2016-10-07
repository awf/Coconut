#ifndef __LINALGTESTS_STORAGED_H__ 
#define __LINALGTESTS_STORAGED_H__ 
#include "runtime/fsharp.h"
#include <stdio.h>
#include <math.h>
#include "linalg_storaged.h"

card_t TOP_LEVEL_linalgtests_test1_shp(card_t dum_shp) {
	
	return 0;
}


void TOP_LEVEL_linalgtests_test1_dps(storage_t stgVar525, array_number_t dum_dps, card_t dum_shp) {
	card_t a_shp = 3;
	card_t size643 = width_card_t(a_shp);
	array_number_t stgVar526 = storage_alloc(size643);
	array_number_t macroDef589 = (array_number_t)stgVar526;
	macroDef589->length=3;
	macroDef589->arr=(number_t*)(STG_OFFSET(stgVar526, VECTOR_HEADER_BYTES));
	macroDef589->arr[0] = 1;
	macroDef589->arr[1] = 2;
	macroDef589->arr[2] = 3;;
	array_number_t a_dps = macroDef589;
	card_t b_shp = 3;
	card_t size642 = width_card_t(b_shp);
	array_number_t stgVar530 = storage_alloc(size642);
	array_number_t macroDef590 = (array_number_t)stgVar530;
	macroDef590->length=3;
	macroDef590->arr=(number_t*)(STG_OFFSET(stgVar530, VECTOR_HEADER_BYTES));
	macroDef590->arr[0] = 5;
	macroDef590->arr[1] = 6;
	macroDef590->arr[2] = 7;;
	array_number_t b_dps = macroDef590;
	array_print(a_dps);
	array_print(b_dps);
	card_t c_shp = TOP_LEVEL_linalg_cross_shp(a_shp, b_shp);
	card_t size641 = width_card_t(c_shp);
	array_number_t stgVar534 = storage_alloc(size641);
	array_number_t c_dps = TOP_LEVEL_linalg_cross_dps(stgVar534, a_dps, b_dps, a_shp, b_shp);
	array_print(c_dps);
	card_t d_shp = TOP_LEVEL_linalg_mult_by_scalar_shp(c_shp, 0);
	card_t size640 = width_card_t(d_shp);
	array_number_t stgVar537 = storage_alloc(size640);
	array_number_t d_dps = TOP_LEVEL_linalg_mult_by_scalar_dps(stgVar537, c_dps, 15, c_shp, 0);
	array_print(d_dps);
	card_t e_shp = TOP_LEVEL_linalg_vectorAdd_shp(a_shp, b_shp);
	card_t size639 = width_card_t(e_shp);
	array_number_t stgVar540 = storage_alloc(size639);
	array_number_t e_dps = TOP_LEVEL_linalg_vectorAdd_dps(stgVar540, a_dps, b_dps, a_shp, b_shp);
	array_print(e_dps);
	card_t f_shp = TOP_LEVEL_linalg_vectorSub_shp(a_shp, b_shp);
	card_t size638 = width_card_t(f_shp);
	array_number_t stgVar543 = storage_alloc(size638);
	array_number_t f_dps = TOP_LEVEL_linalg_vectorSub_dps(stgVar543, a_dps, b_dps, a_shp, b_shp);
	array_print(f_dps);
	card_t g_shp = TOP_LEVEL_linalg_vectorAdd3_shp(a_shp, b_shp, c_shp);
	card_t size637 = width_card_t(g_shp);
	array_number_t stgVar546 = storage_alloc(size637);
	array_number_t g_dps = TOP_LEVEL_linalg_vectorAdd3_dps(stgVar546, a_dps, b_dps, c_dps, a_shp, b_shp, c_shp);
	array_print(g_dps);
	card_t h_shp = 0;
	number_t h_dps = TOP_LEVEL_linalg_sqnorm_dps(empty_storage, a_dps, a_shp);
	number_print(h_dps);
	card_t i_shp = 0;
	number_t i_dps = TOP_LEVEL_linalg_dot_prod_dps(empty_storage, a_dps, b_dps, a_shp, b_shp);
	number_print(i_dps);
	card_t r1_shp = 3;
	card_t size636 = width_card_t(r1_shp);
	array_number_t stgVar555 = storage_alloc(size636);
	array_number_t macroDef591 = (array_number_t)stgVar555;
	macroDef591->length=3;
	macroDef591->arr=(number_t*)(STG_OFFSET(stgVar555, VECTOR_HEADER_BYTES));
	macroDef591->arr[0] = 1;
	macroDef591->arr[1] = 2;
	macroDef591->arr[2] = 3;;
	array_number_t r1_dps = macroDef591;
	card_t r2_shp = 3;
	card_t size635 = width_card_t(r2_shp);
	array_number_t stgVar559 = storage_alloc(size635);
	array_number_t macroDef592 = (array_number_t)stgVar559;
	macroDef592->length=3;
	macroDef592->arr=(number_t*)(STG_OFFSET(stgVar559, VECTOR_HEADER_BYTES));
	macroDef592->arr[0] = 4;
	macroDef592->arr[1] = 5;
	macroDef592->arr[2] = 6;;
	array_number_t r2_dps = macroDef592;
	card_t r3_shp = 3;
	card_t size634 = width_card_t(r3_shp);
	array_number_t stgVar563 = storage_alloc(size634);
	array_number_t macroDef593 = (array_number_t)stgVar563;
	macroDef593->length=3;
	macroDef593->arr=(number_t*)(STG_OFFSET(stgVar563, VECTOR_HEADER_BYTES));
	macroDef593->arr[0] = 7;
	macroDef593->arr[1] = 8;
	macroDef593->arr[2] = 9;;
	array_number_t r3_dps = macroDef593;
	matrix_shape_t mat1_shp = nested_shape_card_t(r1_shp, 3);
	card_t size633 = width_matrix_shape_t(mat1_shp);
	array_number_t stgVar567 = storage_alloc(size633);
	array_array_number_t macroDef594 = (array_array_number_t)stgVar567;
	macroDef594->length=3;
	macroDef594->arr=(array_number_t*)(STG_OFFSET(stgVar567, VECTOR_HEADER_BYTES));
	

	macroDef594->arr[0] = r1_dps;;;
	array_array_number_t mat1_dps = macroDef594;
	matrix_shape_t n_shp = TOP_LEVEL_linalg_matrixMult_shp(mat1_shp, mat1_shp);
	card_t size632 = width_matrix_shape_t(n_shp);
	array_number_t stgVar571 = storage_alloc(size632);
	array_array_number_t n_dps = TOP_LEVEL_linalg_matrixMult_dps(stgVar571, mat1_dps, mat1_dps, mat1_shp, mat1_shp);
	matrix_print(n_dps);
	matrix_shape_t o_shp = TOP_LEVEL_linalg_matrixTranspose_shp(n_shp);
	card_t size631 = width_matrix_shape_t(o_shp);
	array_number_t stgVar574 = storage_alloc(size631);
	array_array_number_t o_dps = TOP_LEVEL_linalg_matrixTranspose_dps(stgVar574, n_dps, n_shp);
	matrix_print(o_dps);
	matrix_shape_t p_shp = TOP_LEVEL_linalg_matrixConcatCol_shp(mat1_shp, mat1_shp);
	card_t size630 = width_matrix_shape_t(p_shp);
	array_number_t stgVar576 = storage_alloc(size630);
	array_array_number_t p_dps = TOP_LEVEL_linalg_matrixConcatCol_dps(stgVar576, mat1_dps, mat1_dps, mat1_shp, mat1_shp);
	matrix_print(p_dps);
	matrix_shape_t t_shp = TOP_LEVEL_linalg_matrixAdd_shp(mat1_shp, mat1_shp);
	card_t size629 = width_matrix_shape_t(t_shp);
	array_number_t stgVar579 = storage_alloc(size629);
	array_array_number_t t_dps = TOP_LEVEL_linalg_matrixAdd_dps(stgVar579, mat1_dps, mat1_dps, mat1_shp, mat1_shp);
	matrix_print(t_dps);
	matrix_shape_t u_shp = TOP_LEVEL_linalg_matrixFillFromVector_shp(5, a_shp);
	card_t size628 = width_matrix_shape_t(u_shp);
	array_number_t stgVar582 = storage_alloc(size628);
	array_array_number_t u_dps = TOP_LEVEL_linalg_matrixFillFromVector_dps(stgVar582, 5, a_dps, 5, a_shp);
	matrix_print(u_dps);
	matrix_shape_t v_shp = TOP_LEVEL_linalg_matrixFill_shp(5, 2, 0);
	card_t size627 = width_matrix_shape_t(v_shp);
	array_number_t stgVar585 = storage_alloc(size627);
	array_array_number_t v_dps = TOP_LEVEL_linalg_matrixFill_dps(stgVar585, 5, 2, 5, 5, 2, 0);
	matrix_print(v_dps);
	;
	storage_free(stgVar585, size627);
	;
	storage_free(stgVar582, size628);
	;
	storage_free(stgVar579, size629);
	;
	storage_free(stgVar576, size630);
	;
	storage_free(stgVar574, size631);
	;
	storage_free(stgVar571, size632);
	;
	storage_free(stgVar567, size633);
	;
	storage_free(stgVar563, size634);
	;
	storage_free(stgVar559, size635);
	;
	storage_free(stgVar555, size636);
	;
	storage_free(stgVar546, size637);
	;
	storage_free(stgVar543, size638);
	;
	storage_free(stgVar540, size639);
	;
	storage_free(stgVar537, size640);
	;
	storage_free(stgVar534, size641);
	;
	storage_free(stgVar530, size642);
	;
	storage_free(stgVar526, size643);
	return ;
}
#endif
