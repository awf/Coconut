#ifndef __LINALGTESTS_STORAGED_H__ 
#define __LINALGTESTS_STORAGED_H__ 
#include "runtime/fsharp.h"
#include <stdio.h>
#include <math.h>
#include "linalg_storaged.h"

card_t TOP_LEVEL_linalgtests_test1_shp(card_t dum_shp) {
	
	return 0;
}


void TOP_LEVEL_linalgtests_test1_dps(storage_t stgVar545, array_number_t dum_dps, card_t dum_shp) {
	card_t a_shp = 3;
	card_t size682 = width_card_t(a_shp);
	array_number_t stgVar546 = storage_alloc(size682);
	array_number_t macroDef622 = (array_number_t)stgVar546;
	macroDef622->length=3;
	macroDef622->arr=(number_t*)(STG_OFFSET(stgVar546, VECTOR_HEADER_BYTES));
	macroDef622->arr[0] = 1;
	macroDef622->arr[1] = 2;
	macroDef622->arr[2] = 3;;
	array_number_t a_dps = macroDef622;
	card_t b_shp = 3;
	card_t size681 = width_card_t(b_shp);
	array_number_t stgVar550 = storage_alloc(size681);
	array_number_t macroDef623 = (array_number_t)stgVar550;
	macroDef623->length=3;
	macroDef623->arr=(number_t*)(STG_OFFSET(stgVar550, VECTOR_HEADER_BYTES));
	macroDef623->arr[0] = 5;
	macroDef623->arr[1] = 6;
	macroDef623->arr[2] = 7;;
	array_number_t b_dps = macroDef623;
	array_print(a_dps);
	array_print(b_dps);
	card_t c_shp = TOP_LEVEL_linalg_cross_shp(a_shp, b_shp);
	card_t size680 = width_card_t(c_shp);
	array_number_t stgVar554 = storage_alloc(size680);
	array_number_t c_dps = TOP_LEVEL_linalg_cross_dps(stgVar554, a_dps, b_dps, a_shp, b_shp);
	array_print(c_dps);
	card_t d_shp = TOP_LEVEL_linalg_mult_by_scalar_shp(c_shp, 0);
	card_t size679 = width_card_t(d_shp);
	array_number_t stgVar557 = storage_alloc(size679);
	array_number_t d_dps = TOP_LEVEL_linalg_mult_by_scalar_dps(stgVar557, c_dps, 15, c_shp, 0);
	array_print(d_dps);
	card_t e_shp = TOP_LEVEL_linalg_vectorAdd_shp(a_shp, b_shp);
	card_t size678 = width_card_t(e_shp);
	array_number_t stgVar560 = storage_alloc(size678);
	array_number_t e_dps = TOP_LEVEL_linalg_vectorAdd_dps(stgVar560, a_dps, b_dps, a_shp, b_shp);
	array_print(e_dps);
	card_t f_shp = TOP_LEVEL_linalg_vectorSub_shp(a_shp, b_shp);
	card_t size677 = width_card_t(f_shp);
	array_number_t stgVar563 = storage_alloc(size677);
	array_number_t f_dps = TOP_LEVEL_linalg_vectorSub_dps(stgVar563, a_dps, b_dps, a_shp, b_shp);
	array_print(f_dps);
	card_t g_shp = TOP_LEVEL_linalg_vectorAdd3_shp(a_shp, b_shp, c_shp);
	card_t size676 = width_card_t(g_shp);
	array_number_t stgVar566 = storage_alloc(size676);
	array_number_t g_dps = TOP_LEVEL_linalg_vectorAdd3_dps(stgVar566, a_dps, b_dps, c_dps, a_shp, b_shp, c_shp);
	array_print(g_dps);
	card_t h_shp = 0;
	number_t h_dps = TOP_LEVEL_linalg_sqnorm_dps(empty_storage, a_dps, a_shp);
	number_print(h_dps);
	card_t i_shp = 0;
	number_t i_dps = TOP_LEVEL_linalg_dot_prod_dps(empty_storage, a_dps, b_dps, a_shp, b_shp);
	number_print(i_dps);
	card_t r1_shp = 3;
	card_t size675 = width_card_t(r1_shp);
	array_number_t stgVar575 = storage_alloc(size675);
	array_number_t macroDef624 = (array_number_t)stgVar575;
	macroDef624->length=3;
	macroDef624->arr=(number_t*)(STG_OFFSET(stgVar575, VECTOR_HEADER_BYTES));
	macroDef624->arr[0] = 1;
	macroDef624->arr[1] = 2;
	macroDef624->arr[2] = 3;;
	array_number_t r1_dps = macroDef624;
	card_t r2_shp = 3;
	card_t size674 = width_card_t(r2_shp);
	array_number_t stgVar579 = storage_alloc(size674);
	array_number_t macroDef625 = (array_number_t)stgVar579;
	macroDef625->length=3;
	macroDef625->arr=(number_t*)(STG_OFFSET(stgVar579, VECTOR_HEADER_BYTES));
	macroDef625->arr[0] = 4;
	macroDef625->arr[1] = 5;
	macroDef625->arr[2] = 6;;
	array_number_t r2_dps = macroDef625;
	card_t r3_shp = 3;
	card_t size673 = width_card_t(r3_shp);
	array_number_t stgVar583 = storage_alloc(size673);
	array_number_t macroDef626 = (array_number_t)stgVar583;
	macroDef626->length=3;
	macroDef626->arr=(number_t*)(STG_OFFSET(stgVar583, VECTOR_HEADER_BYTES));
	macroDef626->arr[0] = 7;
	macroDef626->arr[1] = 8;
	macroDef626->arr[2] = 9;;
	array_number_t r3_dps = macroDef626;
	matrix_shape_t mat0_shp = nested_shape_card_t(3, 3);
	card_t size672 = width_matrix_shape_t(mat0_shp);
	array_number_t stgVar587 = storage_alloc(size672);
	array_array_number_t macroDef630 = (array_array_number_t)stgVar587;
	macroDef630->length=3;
	macroDef630->arr=(array_number_t*)(STG_OFFSET(stgVar587, VECTOR_HEADER_BYTES));
	int stgVar587_offsetVar = 0;storage_t stgVar588 = STG_OFFSET(stgVar587, MATRIX_HEADER_BYTES(3) + stgVar587_offsetVar);array_number_t macroDef627 = (array_number_t)stgVar588;
	macroDef627->length=3;
	macroDef627->arr=(number_t*)(STG_OFFSET(stgVar588, VECTOR_HEADER_BYTES));
	macroDef627->arr[0] = 1;
	macroDef627->arr[1] = 2;
	macroDef627->arr[2] = 3;;

	macroDef630->arr[0] = macroDef627;;stgVar587_offsetVar += VECTOR_ALL_BYTES(macroDef630->arr[0]->length);storage_t stgVar592 = STG_OFFSET(stgVar587, MATRIX_HEADER_BYTES(3) + stgVar587_offsetVar);array_number_t macroDef628 = (array_number_t)stgVar592;
	macroDef628->length=3;
	macroDef628->arr=(number_t*)(STG_OFFSET(stgVar592, VECTOR_HEADER_BYTES));
	macroDef628->arr[0] = 4;
	macroDef628->arr[1] = 5;
	macroDef628->arr[2] = 6;;

	macroDef630->arr[1] = macroDef628;;stgVar587_offsetVar += VECTOR_ALL_BYTES(macroDef630->arr[1]->length);storage_t stgVar596 = STG_OFFSET(stgVar587, MATRIX_HEADER_BYTES(3) + stgVar587_offsetVar);array_number_t macroDef629 = (array_number_t)stgVar596;
	macroDef629->length=3;
	macroDef629->arr=(number_t*)(STG_OFFSET(stgVar596, VECTOR_HEADER_BYTES));
	macroDef629->arr[0] = 7;
	macroDef629->arr[1] = 8;
	macroDef629->arr[2] = 9;;

	macroDef630->arr[2] = macroDef629;;stgVar587_offsetVar += VECTOR_ALL_BYTES(macroDef630->arr[2]->length);;
	array_array_number_t mat0_dps = macroDef630;
	matrix_shape_t mat1_shp = nested_shape_card_t(r1_shp, 3);
	card_t size671 = width_matrix_shape_t(mat1_shp);
	array_number_t stgVar600 = storage_alloc(size671);
	array_array_number_t macroDef631 = (array_array_number_t)stgVar600;
	macroDef631->length=3;
	macroDef631->arr=(array_number_t*)(STG_OFFSET(stgVar600, VECTOR_HEADER_BYTES));
	int stgVar600_offsetVar = 0;storage_t stgVar601 = STG_OFFSET(stgVar600, MATRIX_HEADER_BYTES(3) + stgVar600_offsetVar);

	macroDef631->arr[0] = r1_dps;;stgVar600_offsetVar += VECTOR_ALL_BYTES(macroDef631->arr[0]->length);storage_t stgVar602 = STG_OFFSET(stgVar600, MATRIX_HEADER_BYTES(3) + stgVar600_offsetVar);

	macroDef631->arr[1] = r2_dps;;stgVar600_offsetVar += VECTOR_ALL_BYTES(macroDef631->arr[1]->length);storage_t stgVar603 = STG_OFFSET(stgVar600, MATRIX_HEADER_BYTES(3) + stgVar600_offsetVar);

	macroDef631->arr[2] = r3_dps;;stgVar600_offsetVar += VECTOR_ALL_BYTES(macroDef631->arr[2]->length);;
	array_array_number_t mat1_dps = macroDef631;
	matrix_shape_t n_shp = TOP_LEVEL_linalg_matrixMult_shp(mat0_shp, mat1_shp);
	card_t size670 = width_matrix_shape_t(n_shp);
	array_number_t stgVar604 = storage_alloc(size670);
	array_array_number_t n_dps = TOP_LEVEL_linalg_matrixMult_dps(stgVar604, mat0_dps, mat1_dps, mat0_shp, mat1_shp);
	matrix_print(n_dps);
	matrix_shape_t o_shp = TOP_LEVEL_linalg_matrixTranspose_shp(n_shp);
	card_t size669 = width_matrix_shape_t(o_shp);
	array_number_t stgVar607 = storage_alloc(size669);
	array_array_number_t o_dps = TOP_LEVEL_linalg_matrixTranspose_dps(stgVar607, n_dps, n_shp);
	matrix_print(o_dps);
	matrix_shape_t p_shp = TOP_LEVEL_linalg_matrixConcatCol_shp(mat1_shp, mat1_shp);
	card_t size668 = width_matrix_shape_t(p_shp);
	array_number_t stgVar609 = storage_alloc(size668);
	array_array_number_t p_dps = TOP_LEVEL_linalg_matrixConcatCol_dps(stgVar609, mat1_dps, mat1_dps, mat1_shp, mat1_shp);
	matrix_print(p_dps);
	matrix_shape_t t_shp = TOP_LEVEL_linalg_matrixAdd_shp(mat1_shp, mat1_shp);
	card_t size667 = width_matrix_shape_t(t_shp);
	array_number_t stgVar612 = storage_alloc(size667);
	array_array_number_t t_dps = TOP_LEVEL_linalg_matrixAdd_dps(stgVar612, mat1_dps, mat1_dps, mat1_shp, mat1_shp);
	matrix_print(t_dps);
	matrix_shape_t u_shp = TOP_LEVEL_linalg_matrixFillFromVector_shp(5, a_shp);
	card_t size666 = width_matrix_shape_t(u_shp);
	array_number_t stgVar615 = storage_alloc(size666);
	array_array_number_t u_dps = TOP_LEVEL_linalg_matrixFillFromVector_dps(stgVar615, 5, a_dps, 5, a_shp);
	matrix_print(u_dps);
	matrix_shape_t v_shp = TOP_LEVEL_linalg_matrixFill_shp(5, 2, 0);
	card_t size665 = width_matrix_shape_t(v_shp);
	array_number_t stgVar618 = storage_alloc(size665);
	array_array_number_t v_dps = TOP_LEVEL_linalg_matrixFill_dps(stgVar618, 5, 2, 5, 5, 2, 0);
	matrix_print(v_dps);
	;
	storage_free(stgVar618, size665);
	;
	storage_free(stgVar615, size666);
	;
	storage_free(stgVar612, size667);
	;
	storage_free(stgVar609, size668);
	;
	storage_free(stgVar607, size669);
	;
	storage_free(stgVar604, size670);
	;
	storage_free(stgVar600, size671);
	;
	storage_free(stgVar587, size672);
	;
	storage_free(stgVar583, size673);
	;
	storage_free(stgVar579, size674);
	;
	storage_free(stgVar575, size675);
	;
	storage_free(stgVar566, size676);
	;
	storage_free(stgVar563, size677);
	;
	storage_free(stgVar560, size678);
	;
	storage_free(stgVar557, size679);
	;
	storage_free(stgVar554, size680);
	;
	storage_free(stgVar550, size681);
	;
	storage_free(stgVar546, size682);
	return ;
}
#endif
