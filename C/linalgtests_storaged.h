#ifndef __LINALGTESTS_STORAGED_H__ 
#define __LINALGTESTS_STORAGED_H__ 
#include "runtime/fsharp.h"
#include <stdio.h>
#include <math.h>
#include "linalg_storaged.h"

card_t TOP_LEVEL_linalgtests_test1_shp(card_t dum_shp) {
	
	return 0;
}


void TOP_LEVEL_linalgtests_test1_dps(storage_t stgVar501, array_number_t dum_dps, card_t dum_shp) {
	card_t a_shp = 3;
	card_t size638 = width_card_t(a_shp);
	array_number_t stgVar502 = storage_alloc(size638);
	array_number_t macroDef578 = (array_number_t)stgVar502;
	macroDef578->length=3;
	macroDef578->arr=(number_t*)(STG_OFFSET(stgVar502, VECTOR_HEADER_BYTES));
	

	macroDef578->arr[0] = 1;;

	macroDef578->arr[1] = 2;;

	macroDef578->arr[2] = 3;;;
	array_number_t a_dps = macroDef578;
	card_t b_shp = 3;
	card_t size637 = width_card_t(b_shp);
	array_number_t stgVar506 = storage_alloc(size637);
	array_number_t macroDef579 = (array_number_t)stgVar506;
	macroDef579->length=3;
	macroDef579->arr=(number_t*)(STG_OFFSET(stgVar506, VECTOR_HEADER_BYTES));
	

	macroDef579->arr[0] = 5;;

	macroDef579->arr[1] = 6;;

	macroDef579->arr[2] = 7;;;
	array_number_t b_dps = macroDef579;
	array_print(a_dps);
	array_print(b_dps);
	card_t c_shp = TOP_LEVEL_linalg_cross_shp(a_shp, b_shp);
	card_t size636 = width_card_t(c_shp);
	array_number_t stgVar510 = storage_alloc(size636);
	array_number_t c_dps = TOP_LEVEL_linalg_cross_dps(stgVar510, a_dps, b_dps, a_shp, b_shp);
	array_print(c_dps);
	card_t d_shp = TOP_LEVEL_linalg_mult_by_scalar_shp(c_shp, 0);
	card_t size635 = width_card_t(d_shp);
	array_number_t stgVar513 = storage_alloc(size635);
	array_number_t d_dps = TOP_LEVEL_linalg_mult_by_scalar_dps(stgVar513, c_dps, 15, c_shp, 0);
	array_print(d_dps);
	card_t e_shp = TOP_LEVEL_linalg_vectorAdd_shp(a_shp, b_shp);
	card_t size634 = width_card_t(e_shp);
	array_number_t stgVar516 = storage_alloc(size634);
	array_number_t e_dps = TOP_LEVEL_linalg_vectorAdd_dps(stgVar516, a_dps, b_dps, a_shp, b_shp);
	array_print(e_dps);
	card_t f_shp = TOP_LEVEL_linalg_vectorSub_shp(a_shp, b_shp);
	card_t size633 = width_card_t(f_shp);
	array_number_t stgVar519 = storage_alloc(size633);
	array_number_t f_dps = TOP_LEVEL_linalg_vectorSub_dps(stgVar519, a_dps, b_dps, a_shp, b_shp);
	array_print(f_dps);
	card_t g_shp = TOP_LEVEL_linalg_vectorAdd3_shp(a_shp, b_shp, c_shp);
	card_t size632 = width_card_t(g_shp);
	array_number_t stgVar522 = storage_alloc(size632);
	array_number_t g_dps = TOP_LEVEL_linalg_vectorAdd3_dps(stgVar522, a_dps, b_dps, c_dps, a_shp, b_shp, c_shp);
	array_print(g_dps);
	card_t h_shp = 0;
	number_t h_dps = TOP_LEVEL_linalg_sqnorm_dps(empty_storage, a_dps, a_shp);
	number_print(h_dps);
	card_t i_shp = 0;
	number_t i_dps = TOP_LEVEL_linalg_dot_prod_dps(empty_storage, a_dps, b_dps, a_shp, b_shp);
	number_print(i_dps);
	card_t r1_shp = 3;
	card_t size631 = width_card_t(r1_shp);
	array_number_t stgVar531 = storage_alloc(size631);
	array_number_t macroDef580 = (array_number_t)stgVar531;
	macroDef580->length=3;
	macroDef580->arr=(number_t*)(STG_OFFSET(stgVar531, VECTOR_HEADER_BYTES));
	

	macroDef580->arr[0] = 1;;

	macroDef580->arr[1] = 2;;

	macroDef580->arr[2] = 3;;;
	array_number_t r1_dps = macroDef580;
	card_t r2_shp = 3;
	card_t size630 = width_card_t(r2_shp);
	array_number_t stgVar535 = storage_alloc(size630);
	array_number_t macroDef581 = (array_number_t)stgVar535;
	macroDef581->length=3;
	macroDef581->arr=(number_t*)(STG_OFFSET(stgVar535, VECTOR_HEADER_BYTES));
	

	macroDef581->arr[0] = 4;;

	macroDef581->arr[1] = 5;;

	macroDef581->arr[2] = 6;;;
	array_number_t r2_dps = macroDef581;
	card_t r3_shp = 3;
	card_t size629 = width_card_t(r3_shp);
	array_number_t stgVar539 = storage_alloc(size629);
	array_number_t macroDef582 = (array_number_t)stgVar539;
	macroDef582->length=3;
	macroDef582->arr=(number_t*)(STG_OFFSET(stgVar539, VECTOR_HEADER_BYTES));
	

	macroDef582->arr[0] = 7;;

	macroDef582->arr[1] = 8;;

	macroDef582->arr[2] = 9;;;
	array_number_t r3_dps = macroDef582;
	matrix_shape_t mat0_shp = nested_shape_card_t(3, 3);
	card_t size628 = width_matrix_shape_t(mat0_shp);
	array_number_t stgVar543 = storage_alloc(size628);
	array_array_number_t macroDef586 = (array_array_number_t)stgVar543;
	macroDef586->length=3;
	macroDef586->arr=(array_number_t*)(STG_OFFSET(stgVar543, VECTOR_HEADER_BYTES));
	int stgVar543_offsetVar = 0;storage_t stgVar544 = STG_OFFSET(stgVar543, MATRIX_HEADER_BYTES(3) + stgVar543_offsetVar);array_number_t macroDef583 = (array_number_t)stgVar544;
	macroDef583->length=3;
	macroDef583->arr=(number_t*)(STG_OFFSET(stgVar544, VECTOR_HEADER_BYTES));
	

	macroDef583->arr[0] = 1;;

	macroDef583->arr[1] = 2;;

	macroDef583->arr[2] = 3;;;

	macroDef586->arr[0] = macroDef583;;stgVar543_offsetVar += VECTOR_ALL_BYTES(macroDef586->arr[0]->length);storage_t stgVar548 = STG_OFFSET(stgVar543, MATRIX_HEADER_BYTES(3) + stgVar543_offsetVar);array_number_t macroDef584 = (array_number_t)stgVar548;
	macroDef584->length=3;
	macroDef584->arr=(number_t*)(STG_OFFSET(stgVar548, VECTOR_HEADER_BYTES));
	

	macroDef584->arr[0] = 4;;

	macroDef584->arr[1] = 5;;

	macroDef584->arr[2] = 6;;;

	macroDef586->arr[1] = macroDef584;;stgVar543_offsetVar += VECTOR_ALL_BYTES(macroDef586->arr[1]->length);storage_t stgVar552 = STG_OFFSET(stgVar543, MATRIX_HEADER_BYTES(3) + stgVar543_offsetVar);array_number_t macroDef585 = (array_number_t)stgVar552;
	macroDef585->length=3;
	macroDef585->arr=(number_t*)(STG_OFFSET(stgVar552, VECTOR_HEADER_BYTES));
	

	macroDef585->arr[0] = 7;;

	macroDef585->arr[1] = 8;;

	macroDef585->arr[2] = 9;;;

	macroDef586->arr[2] = macroDef585;;stgVar543_offsetVar += VECTOR_ALL_BYTES(macroDef586->arr[2]->length);;
	array_array_number_t mat0_dps = macroDef586;
	matrix_shape_t mat1_shp = nested_shape_card_t(r1_shp, 3);
	card_t size627 = width_matrix_shape_t(mat1_shp);
	array_number_t stgVar556 = storage_alloc(size627);
	array_array_number_t macroDef587 = (array_array_number_t)stgVar556;
	macroDef587->length=3;
	macroDef587->arr=(array_number_t*)(STG_OFFSET(stgVar556, VECTOR_HEADER_BYTES));
	int stgVar556_offsetVar = 0;storage_t stgVar557 = STG_OFFSET(stgVar556, MATRIX_HEADER_BYTES(3) + stgVar556_offsetVar);

	macroDef587->arr[0] = r1_dps;;stgVar556_offsetVar += VECTOR_ALL_BYTES(macroDef587->arr[0]->length);storage_t stgVar558 = STG_OFFSET(stgVar556, MATRIX_HEADER_BYTES(3) + stgVar556_offsetVar);

	macroDef587->arr[1] = r2_dps;;stgVar556_offsetVar += VECTOR_ALL_BYTES(macroDef587->arr[1]->length);storage_t stgVar559 = STG_OFFSET(stgVar556, MATRIX_HEADER_BYTES(3) + stgVar556_offsetVar);

	macroDef587->arr[2] = r3_dps;;stgVar556_offsetVar += VECTOR_ALL_BYTES(macroDef587->arr[2]->length);;
	array_array_number_t mat1_dps = macroDef587;
	matrix_shape_t n_shp = TOP_LEVEL_linalg_matrixMult_shp(mat0_shp, mat1_shp);
	card_t size626 = width_matrix_shape_t(n_shp);
	array_number_t stgVar560 = storage_alloc(size626);
	array_array_number_t n_dps = TOP_LEVEL_linalg_matrixMult_dps(stgVar560, mat0_dps, mat1_dps, mat0_shp, mat1_shp);
	matrix_print(n_dps);
	matrix_shape_t o_shp = TOP_LEVEL_linalg_matrixTranspose_shp(n_shp);
	card_t size625 = width_matrix_shape_t(o_shp);
	array_number_t stgVar563 = storage_alloc(size625);
	array_array_number_t o_dps = TOP_LEVEL_linalg_matrixTranspose_dps(stgVar563, n_dps, n_shp);
	matrix_print(o_dps);
	matrix_shape_t p_shp = TOP_LEVEL_linalg_matrixConcatCol_shp(mat1_shp, mat1_shp);
	card_t size624 = width_matrix_shape_t(p_shp);
	array_number_t stgVar565 = storage_alloc(size624);
	array_array_number_t p_dps = TOP_LEVEL_linalg_matrixConcatCol_dps(stgVar565, mat1_dps, mat1_dps, mat1_shp, mat1_shp);
	matrix_print(p_dps);
	matrix_shape_t t_shp = TOP_LEVEL_linalg_matrixAdd_shp(mat1_shp, mat1_shp);
	card_t size623 = width_matrix_shape_t(t_shp);
	array_number_t stgVar568 = storage_alloc(size623);
	array_array_number_t t_dps = TOP_LEVEL_linalg_matrixAdd_dps(stgVar568, mat1_dps, mat1_dps, mat1_shp, mat1_shp);
	matrix_print(t_dps);
	matrix_shape_t u_shp = TOP_LEVEL_linalg_matrixFillFromVector_shp(5, a_shp);
	card_t size622 = width_matrix_shape_t(u_shp);
	array_number_t stgVar571 = storage_alloc(size622);
	array_array_number_t u_dps = TOP_LEVEL_linalg_matrixFillFromVector_dps(stgVar571, 5, a_dps, 5, a_shp);
	matrix_print(u_dps);
	matrix_shape_t v_shp = TOP_LEVEL_linalg_matrixFill_shp(5, 2, 0);
	card_t size621 = width_matrix_shape_t(v_shp);
	array_number_t stgVar574 = storage_alloc(size621);
	array_array_number_t v_dps = TOP_LEVEL_linalg_matrixFill_dps(stgVar574, 5, 2, 5, 5, 2, 0);
	matrix_print(v_dps);
	;
	storage_free(stgVar574, size621);
	;
	storage_free(stgVar571, size622);
	;
	storage_free(stgVar568, size623);
	;
	storage_free(stgVar565, size624);
	;
	storage_free(stgVar563, size625);
	;
	storage_free(stgVar560, size626);
	;
	storage_free(stgVar556, size627);
	;
	storage_free(stgVar543, size628);
	;
	storage_free(stgVar539, size629);
	;
	storage_free(stgVar535, size630);
	;
	storage_free(stgVar531, size631);
	;
	storage_free(stgVar522, size632);
	;
	storage_free(stgVar519, size633);
	;
	storage_free(stgVar516, size634);
	;
	storage_free(stgVar513, size635);
	;
	storage_free(stgVar510, size636);
	;
	storage_free(stgVar506, size637);
	;
	storage_free(stgVar502, size638);
	return ;
}
#endif
