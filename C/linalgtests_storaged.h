#ifndef __LINALGTESTS_STORAGED_H__ 
#define __LINALGTESTS_STORAGED_H__ 
#include "runtime/fsharp.h"
#include <stdio.h>
#include <math.h>
#include "linalg_storaged.h"

card_t TOP_LEVEL_linalgtests_test1_shp(card_t dum_shp) {
	
	return 0;
}


void TOP_LEVEL_linalgtests_test1_dps(storage_t stgVar541, array_number_t dum_dps, card_t dum_shp) {
	card_t a_shp = 3;
	card_t size678 = width_card_t(a_shp);
	array_number_t stgVar542 = storage_alloc(size678);
	array_number_t macroDef618 = (array_number_t)stgVar542;
	macroDef618->length=3;
	macroDef618->arr=(number_t*)(STG_OFFSET(stgVar542, VECTOR_HEADER_BYTES));
	macroDef618->arr[0] = 1;
	macroDef618->arr[1] = 2;
	macroDef618->arr[2] = 3;;
	array_number_t a_dps = macroDef618;
	card_t b_shp = 3;
	card_t size677 = width_card_t(b_shp);
	array_number_t stgVar546 = storage_alloc(size677);
	array_number_t macroDef619 = (array_number_t)stgVar546;
	macroDef619->length=3;
	macroDef619->arr=(number_t*)(STG_OFFSET(stgVar546, VECTOR_HEADER_BYTES));
	macroDef619->arr[0] = 5;
	macroDef619->arr[1] = 6;
	macroDef619->arr[2] = 7;;
	array_number_t b_dps = macroDef619;
	array_print(a_dps);
	array_print(b_dps);
	card_t c_shp = TOP_LEVEL_linalg_cross_shp(a_shp, b_shp);
	card_t size676 = width_card_t(c_shp);
	array_number_t stgVar550 = storage_alloc(size676);
	array_number_t c_dps = TOP_LEVEL_linalg_cross_dps(stgVar550, a_dps, b_dps, a_shp, b_shp);
	array_print(c_dps);
	card_t d_shp = TOP_LEVEL_linalg_mult_by_scalar_shp(c_shp, 0);
	card_t size675 = width_card_t(d_shp);
	array_number_t stgVar553 = storage_alloc(size675);
	array_number_t d_dps = TOP_LEVEL_linalg_mult_by_scalar_dps(stgVar553, c_dps, 15, c_shp, 0);
	array_print(d_dps);
	card_t e_shp = TOP_LEVEL_linalg_vectorAdd_shp(a_shp, b_shp);
	card_t size674 = width_card_t(e_shp);
	array_number_t stgVar556 = storage_alloc(size674);
	array_number_t e_dps = TOP_LEVEL_linalg_vectorAdd_dps(stgVar556, a_dps, b_dps, a_shp, b_shp);
	array_print(e_dps);
	card_t f_shp = TOP_LEVEL_linalg_vectorSub_shp(a_shp, b_shp);
	card_t size673 = width_card_t(f_shp);
	array_number_t stgVar559 = storage_alloc(size673);
	array_number_t f_dps = TOP_LEVEL_linalg_vectorSub_dps(stgVar559, a_dps, b_dps, a_shp, b_shp);
	array_print(f_dps);
	card_t g_shp = TOP_LEVEL_linalg_vectorAdd3_shp(a_shp, b_shp, c_shp);
	card_t size672 = width_card_t(g_shp);
	array_number_t stgVar562 = storage_alloc(size672);
	array_number_t g_dps = TOP_LEVEL_linalg_vectorAdd3_dps(stgVar562, a_dps, b_dps, c_dps, a_shp, b_shp, c_shp);
	array_print(g_dps);
	card_t h_shp = 0;
	number_t h_dps = TOP_LEVEL_linalg_sqnorm_dps(empty_storage, a_dps, a_shp);
	number_print(h_dps);
	card_t i_shp = 0;
	number_t i_dps = TOP_LEVEL_linalg_dot_prod_dps(empty_storage, a_dps, b_dps, a_shp, b_shp);
	number_print(i_dps);
	card_t r1_shp = 3;
	card_t size671 = width_card_t(r1_shp);
	array_number_t stgVar571 = storage_alloc(size671);
	array_number_t macroDef620 = (array_number_t)stgVar571;
	macroDef620->length=3;
	macroDef620->arr=(number_t*)(STG_OFFSET(stgVar571, VECTOR_HEADER_BYTES));
	macroDef620->arr[0] = 1;
	macroDef620->arr[1] = 2;
	macroDef620->arr[2] = 3;;
	array_number_t r1_dps = macroDef620;
	card_t r2_shp = 3;
	card_t size670 = width_card_t(r2_shp);
	array_number_t stgVar575 = storage_alloc(size670);
	array_number_t macroDef621 = (array_number_t)stgVar575;
	macroDef621->length=3;
	macroDef621->arr=(number_t*)(STG_OFFSET(stgVar575, VECTOR_HEADER_BYTES));
	macroDef621->arr[0] = 4;
	macroDef621->arr[1] = 5;
	macroDef621->arr[2] = 6;;
	array_number_t r2_dps = macroDef621;
	card_t r3_shp = 3;
	card_t size669 = width_card_t(r3_shp);
	array_number_t stgVar579 = storage_alloc(size669);
	array_number_t macroDef622 = (array_number_t)stgVar579;
	macroDef622->length=3;
	macroDef622->arr=(number_t*)(STG_OFFSET(stgVar579, VECTOR_HEADER_BYTES));
	macroDef622->arr[0] = 7;
	macroDef622->arr[1] = 8;
	macroDef622->arr[2] = 9;;
	array_number_t r3_dps = macroDef622;
	matrix_shape_t mat0_shp = nested_shape_card_t(3, 3);
	card_t size668 = width_matrix_shape_t(mat0_shp);
	array_number_t stgVar583 = storage_alloc(size668);
	array_array_number_t macroDef626 = (array_array_number_t)stgVar583;
	macroDef626->length=3;
	macroDef626->arr=(array_number_t*)(STG_OFFSET(stgVar583, VECTOR_HEADER_BYTES));
	storage_t stgVar584 = STG_OFFSET(stgVar583, MATRIX_HEADER_BYTES(3));array_number_t macroDef623 = (array_number_t)stgVar584;
	macroDef623->length=3;
	macroDef623->arr=(number_t*)(STG_OFFSET(stgVar584, VECTOR_HEADER_BYTES));
	macroDef623->arr[0] = 1;
	macroDef623->arr[1] = 2;
	macroDef623->arr[2] = 3;;

	macroDef626->arr[0] = macroDef623;;storage_t stgVar588 = STG_OFFSET(stgVar583, MATRIX_HEADER_BYTES(3));array_number_t macroDef624 = (array_number_t)stgVar588;
	macroDef624->length=3;
	macroDef624->arr=(number_t*)(STG_OFFSET(stgVar588, VECTOR_HEADER_BYTES));
	macroDef624->arr[0] = 4;
	macroDef624->arr[1] = 5;
	macroDef624->arr[2] = 6;;

	macroDef626->arr[1] = macroDef624;;storage_t stgVar592 = STG_OFFSET(stgVar583, MATRIX_HEADER_BYTES(3));array_number_t macroDef625 = (array_number_t)stgVar592;
	macroDef625->length=3;
	macroDef625->arr=(number_t*)(STG_OFFSET(stgVar592, VECTOR_HEADER_BYTES));
	macroDef625->arr[0] = 7;
	macroDef625->arr[1] = 8;
	macroDef625->arr[2] = 9;;

	macroDef626->arr[2] = macroDef625;;;
	array_array_number_t mat0_dps = macroDef626;
	matrix_shape_t mat1_shp = nested_shape_card_t(r1_shp, 3);
	card_t size667 = width_matrix_shape_t(mat1_shp);
	array_number_t stgVar596 = storage_alloc(size667);
	array_array_number_t macroDef627 = (array_array_number_t)stgVar596;
	macroDef627->length=3;
	macroDef627->arr=(array_number_t*)(STG_OFFSET(stgVar596, VECTOR_HEADER_BYTES));
	storage_t stgVar597 = STG_OFFSET(stgVar596, MATRIX_HEADER_BYTES(3));

	macroDef627->arr[0] = r1_dps;;storage_t stgVar598 = STG_OFFSET(stgVar596, MATRIX_HEADER_BYTES(3));

	macroDef627->arr[1] = r2_dps;;storage_t stgVar599 = STG_OFFSET(stgVar596, MATRIX_HEADER_BYTES(3));

	macroDef627->arr[2] = r3_dps;;;
	array_array_number_t mat1_dps = macroDef627;
	matrix_shape_t n_shp = TOP_LEVEL_linalg_matrixMult_shp(mat0_shp, mat1_shp);
	card_t size666 = width_matrix_shape_t(n_shp);
	array_number_t stgVar600 = storage_alloc(size666);
	array_array_number_t n_dps = TOP_LEVEL_linalg_matrixMult_dps(stgVar600, mat0_dps, mat1_dps, mat0_shp, mat1_shp);
	matrix_print(n_dps);
	matrix_shape_t o_shp = TOP_LEVEL_linalg_matrixTranspose_shp(n_shp);
	card_t size665 = width_matrix_shape_t(o_shp);
	array_number_t stgVar603 = storage_alloc(size665);
	array_array_number_t o_dps = TOP_LEVEL_linalg_matrixTranspose_dps(stgVar603, n_dps, n_shp);
	matrix_print(o_dps);
	matrix_shape_t p_shp = TOP_LEVEL_linalg_matrixConcatCol_shp(mat1_shp, mat1_shp);
	card_t size664 = width_matrix_shape_t(p_shp);
	array_number_t stgVar605 = storage_alloc(size664);
	array_array_number_t p_dps = TOP_LEVEL_linalg_matrixConcatCol_dps(stgVar605, mat1_dps, mat1_dps, mat1_shp, mat1_shp);
	matrix_print(p_dps);
	matrix_shape_t t_shp = TOP_LEVEL_linalg_matrixAdd_shp(mat1_shp, mat1_shp);
	card_t size663 = width_matrix_shape_t(t_shp);
	array_number_t stgVar608 = storage_alloc(size663);
	array_array_number_t t_dps = TOP_LEVEL_linalg_matrixAdd_dps(stgVar608, mat1_dps, mat1_dps, mat1_shp, mat1_shp);
	matrix_print(t_dps);
	matrix_shape_t u_shp = TOP_LEVEL_linalg_matrixFillFromVector_shp(5, a_shp);
	card_t size662 = width_matrix_shape_t(u_shp);
	array_number_t stgVar611 = storage_alloc(size662);
	array_array_number_t u_dps = TOP_LEVEL_linalg_matrixFillFromVector_dps(stgVar611, 5, a_dps, 5, a_shp);
	matrix_print(u_dps);
	matrix_shape_t v_shp = TOP_LEVEL_linalg_matrixFill_shp(5, 2, 0);
	card_t size661 = width_matrix_shape_t(v_shp);
	array_number_t stgVar614 = storage_alloc(size661);
	array_array_number_t v_dps = TOP_LEVEL_linalg_matrixFill_dps(stgVar614, 5, 2, 5, 5, 2, 0);
	matrix_print(v_dps);
	;
	storage_free(stgVar614, size661);
	;
	storage_free(stgVar611, size662);
	;
	storage_free(stgVar608, size663);
	;
	storage_free(stgVar605, size664);
	;
	storage_free(stgVar603, size665);
	;
	storage_free(stgVar600, size666);
	;
	storage_free(stgVar596, size667);
	;
	storage_free(stgVar583, size668);
	;
	storage_free(stgVar579, size669);
	;
	storage_free(stgVar575, size670);
	;
	storage_free(stgVar571, size671);
	;
	storage_free(stgVar562, size672);
	;
	storage_free(stgVar559, size673);
	;
	storage_free(stgVar556, size674);
	;
	storage_free(stgVar553, size675);
	;
	storage_free(stgVar550, size676);
	;
	storage_free(stgVar546, size677);
	;
	storage_free(stgVar542, size678);
	return ;
}
#endif
