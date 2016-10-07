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
	card_t size662 = width_card_t(a_shp);
	array_number_t stgVar526 = storage_alloc(size662);
	array_number_t macroDef602 = (array_number_t)stgVar526;
	macroDef602->length=3;
	macroDef602->arr=(number_t*)(STG_OFFSET(stgVar526, VECTOR_HEADER_BYTES));
	macroDef602->arr[0] = 1;
	macroDef602->arr[1] = 2;
	macroDef602->arr[2] = 3;;
	array_number_t a_dps = macroDef602;
	card_t b_shp = 3;
	card_t size661 = width_card_t(b_shp);
	array_number_t stgVar530 = storage_alloc(size661);
	array_number_t macroDef603 = (array_number_t)stgVar530;
	macroDef603->length=3;
	macroDef603->arr=(number_t*)(STG_OFFSET(stgVar530, VECTOR_HEADER_BYTES));
	macroDef603->arr[0] = 5;
	macroDef603->arr[1] = 6;
	macroDef603->arr[2] = 7;;
	array_number_t b_dps = macroDef603;
	array_print(a_dps);
	array_print(b_dps);
	card_t c_shp = TOP_LEVEL_linalg_cross_shp(a_shp, b_shp);
	card_t size660 = width_card_t(c_shp);
	array_number_t stgVar534 = storage_alloc(size660);
	array_number_t c_dps = TOP_LEVEL_linalg_cross_dps(stgVar534, a_dps, b_dps, a_shp, b_shp);
	array_print(c_dps);
	card_t d_shp = TOP_LEVEL_linalg_mult_by_scalar_shp(c_shp, 0);
	card_t size659 = width_card_t(d_shp);
	array_number_t stgVar537 = storage_alloc(size659);
	array_number_t d_dps = TOP_LEVEL_linalg_mult_by_scalar_dps(stgVar537, c_dps, 15, c_shp, 0);
	array_print(d_dps);
	card_t e_shp = TOP_LEVEL_linalg_vectorAdd_shp(a_shp, b_shp);
	card_t size658 = width_card_t(e_shp);
	array_number_t stgVar540 = storage_alloc(size658);
	array_number_t e_dps = TOP_LEVEL_linalg_vectorAdd_dps(stgVar540, a_dps, b_dps, a_shp, b_shp);
	array_print(e_dps);
	card_t f_shp = TOP_LEVEL_linalg_vectorSub_shp(a_shp, b_shp);
	card_t size657 = width_card_t(f_shp);
	array_number_t stgVar543 = storage_alloc(size657);
	array_number_t f_dps = TOP_LEVEL_linalg_vectorSub_dps(stgVar543, a_dps, b_dps, a_shp, b_shp);
	array_print(f_dps);
	card_t g_shp = TOP_LEVEL_linalg_vectorAdd3_shp(a_shp, b_shp, c_shp);
	card_t size656 = width_card_t(g_shp);
	array_number_t stgVar546 = storage_alloc(size656);
	array_number_t g_dps = TOP_LEVEL_linalg_vectorAdd3_dps(stgVar546, a_dps, b_dps, c_dps, a_shp, b_shp, c_shp);
	array_print(g_dps);
	card_t h_shp = 0;
	number_t h_dps = TOP_LEVEL_linalg_sqnorm_dps(empty_storage, a_dps, a_shp);
	number_print(h_dps);
	card_t i_shp = 0;
	number_t i_dps = TOP_LEVEL_linalg_dot_prod_dps(empty_storage, a_dps, b_dps, a_shp, b_shp);
	number_print(i_dps);
	card_t r1_shp = 3;
	card_t size655 = width_card_t(r1_shp);
	array_number_t stgVar555 = storage_alloc(size655);
	array_number_t macroDef604 = (array_number_t)stgVar555;
	macroDef604->length=3;
	macroDef604->arr=(number_t*)(STG_OFFSET(stgVar555, VECTOR_HEADER_BYTES));
	macroDef604->arr[0] = 1;
	macroDef604->arr[1] = 2;
	macroDef604->arr[2] = 3;;
	array_number_t r1_dps = macroDef604;
	card_t r2_shp = 3;
	card_t size654 = width_card_t(r2_shp);
	array_number_t stgVar559 = storage_alloc(size654);
	array_number_t macroDef605 = (array_number_t)stgVar559;
	macroDef605->length=3;
	macroDef605->arr=(number_t*)(STG_OFFSET(stgVar559, VECTOR_HEADER_BYTES));
	macroDef605->arr[0] = 4;
	macroDef605->arr[1] = 5;
	macroDef605->arr[2] = 6;;
	array_number_t r2_dps = macroDef605;
	card_t r3_shp = 3;
	card_t size653 = width_card_t(r3_shp);
	array_number_t stgVar563 = storage_alloc(size653);
	array_number_t macroDef606 = (array_number_t)stgVar563;
	macroDef606->length=3;
	macroDef606->arr=(number_t*)(STG_OFFSET(stgVar563, VECTOR_HEADER_BYTES));
	macroDef606->arr[0] = 7;
	macroDef606->arr[1] = 8;
	macroDef606->arr[2] = 9;;
	array_number_t r3_dps = macroDef606;
	matrix_shape_t mat0_shp = nested_shape_card_t(3, 3);
	card_t size652 = width_matrix_shape_t(mat0_shp);
	array_number_t stgVar567 = storage_alloc(size652);
	array_array_number_t macroDef610 = (array_array_number_t)stgVar567;
	macroDef610->length=3;
	macroDef610->arr=(array_number_t*)(STG_OFFSET(stgVar567, VECTOR_HEADER_BYTES));
	storage_t stgVar568 = STG_OFFSET(stgVar567, MATRIX_HEADER_BYTES(3));array_number_t macroDef607 = (array_number_t)stgVar568;
	macroDef607->length=3;
	macroDef607->arr=(number_t*)(STG_OFFSET(stgVar568, VECTOR_HEADER_BYTES));
	macroDef607->arr[0] = 1;
	macroDef607->arr[1] = 2;
	macroDef607->arr[2] = 3;;

	macroDef610->arr[0] = macroDef607;;storage_t stgVar572 = STG_OFFSET(stgVar567, MATRIX_HEADER_BYTES(3));array_number_t macroDef608 = (array_number_t)stgVar572;
	macroDef608->length=3;
	macroDef608->arr=(number_t*)(STG_OFFSET(stgVar572, VECTOR_HEADER_BYTES));
	macroDef608->arr[0] = 4;
	macroDef608->arr[1] = 5;
	macroDef608->arr[2] = 6;;

	macroDef610->arr[1] = macroDef608;;storage_t stgVar576 = STG_OFFSET(stgVar567, MATRIX_HEADER_BYTES(3));array_number_t macroDef609 = (array_number_t)stgVar576;
	macroDef609->length=3;
	macroDef609->arr=(number_t*)(STG_OFFSET(stgVar576, VECTOR_HEADER_BYTES));
	macroDef609->arr[0] = 7;
	macroDef609->arr[1] = 8;
	macroDef609->arr[2] = 9;;

	macroDef610->arr[2] = macroDef609;;;
	array_array_number_t mat0_dps = macroDef610;
	matrix_shape_t mat1_shp = nested_shape_card_t(r1_shp, 3);
	card_t size651 = width_matrix_shape_t(mat1_shp);
	array_number_t stgVar580 = storage_alloc(size651);
	array_array_number_t macroDef611 = (array_array_number_t)stgVar580;
	macroDef611->length=3;
	macroDef611->arr=(array_number_t*)(STG_OFFSET(stgVar580, VECTOR_HEADER_BYTES));
	storage_t stgVar581 = STG_OFFSET(stgVar580, MATRIX_HEADER_BYTES(3));

	macroDef611->arr[0] = r1_dps;;storage_t stgVar582 = STG_OFFSET(stgVar580, MATRIX_HEADER_BYTES(3));

	macroDef611->arr[1] = r2_dps;;storage_t stgVar583 = STG_OFFSET(stgVar580, MATRIX_HEADER_BYTES(3));

	macroDef611->arr[2] = r3_dps;;;
	array_array_number_t mat1_dps = macroDef611;
	matrix_shape_t n_shp = TOP_LEVEL_linalg_matrixMult_shp(mat0_shp, mat1_shp);
	card_t size650 = width_matrix_shape_t(n_shp);
	array_number_t stgVar584 = storage_alloc(size650);
	array_array_number_t n_dps = TOP_LEVEL_linalg_matrixMult_dps(stgVar584, mat0_dps, mat1_dps, mat0_shp, mat1_shp);
	matrix_print(n_dps);
	matrix_shape_t o_shp = TOP_LEVEL_linalg_matrixTranspose_shp(n_shp);
	card_t size649 = width_matrix_shape_t(o_shp);
	array_number_t stgVar587 = storage_alloc(size649);
	array_array_number_t o_dps = TOP_LEVEL_linalg_matrixTranspose_dps(stgVar587, n_dps, n_shp);
	matrix_print(o_dps);
	matrix_shape_t p_shp = TOP_LEVEL_linalg_matrixConcatCol_shp(mat1_shp, mat1_shp);
	card_t size648 = width_matrix_shape_t(p_shp);
	array_number_t stgVar589 = storage_alloc(size648);
	array_array_number_t p_dps = TOP_LEVEL_linalg_matrixConcatCol_dps(stgVar589, mat1_dps, mat1_dps, mat1_shp, mat1_shp);
	matrix_print(p_dps);
	matrix_shape_t t_shp = TOP_LEVEL_linalg_matrixAdd_shp(mat1_shp, mat1_shp);
	card_t size647 = width_matrix_shape_t(t_shp);
	array_number_t stgVar592 = storage_alloc(size647);
	array_array_number_t t_dps = TOP_LEVEL_linalg_matrixAdd_dps(stgVar592, mat1_dps, mat1_dps, mat1_shp, mat1_shp);
	matrix_print(t_dps);
	matrix_shape_t u_shp = TOP_LEVEL_linalg_matrixFillFromVector_shp(5, a_shp);
	card_t size646 = width_matrix_shape_t(u_shp);
	array_number_t stgVar595 = storage_alloc(size646);
	array_array_number_t u_dps = TOP_LEVEL_linalg_matrixFillFromVector_dps(stgVar595, 5, a_dps, 5, a_shp);
	matrix_print(u_dps);
	matrix_shape_t v_shp = TOP_LEVEL_linalg_matrixFill_shp(5, 2, 0);
	card_t size645 = width_matrix_shape_t(v_shp);
	array_number_t stgVar598 = storage_alloc(size645);
	array_array_number_t v_dps = TOP_LEVEL_linalg_matrixFill_dps(stgVar598, 5, 2, 5, 5, 2, 0);
	matrix_print(v_dps);
	;
	storage_free(stgVar598, size645);
	;
	storage_free(stgVar595, size646);
	;
	storage_free(stgVar592, size647);
	;
	storage_free(stgVar589, size648);
	;
	storage_free(stgVar587, size649);
	;
	storage_free(stgVar584, size650);
	;
	storage_free(stgVar580, size651);
	;
	storage_free(stgVar567, size652);
	;
	storage_free(stgVar563, size653);
	;
	storage_free(stgVar559, size654);
	;
	storage_free(stgVar555, size655);
	;
	storage_free(stgVar546, size656);
	;
	storage_free(stgVar543, size657);
	;
	storage_free(stgVar540, size658);
	;
	storage_free(stgVar537, size659);
	;
	storage_free(stgVar534, size660);
	;
	storage_free(stgVar530, size661);
	;
	storage_free(stgVar526, size662);
	return ;
}
#endif
