#ifndef __LINALGTESTS_STORAGED_H__ 
#define __LINALGTESTS_STORAGED_H__ 
#include "../../Runtime/C/fsharp.h"
#include <stdio.h>
#include <math.h>
#include "linalg_storaged.h"

card_t TOP_LEVEL_linalgtests_test1_shp(card_t dum_shp) {
	
	return 0;
}


void TOP_LEVEL_linalgtests_test1_dps(storage_t stgVar532, array_number_t dum_dps, card_t dum_shp) {
	card_t a_shp = 3;
	card_t size669 = width_card_t(a_shp);
	array_number_t stgVar533 = storage_alloc(size669);
	array_number_t macroDef609 = (array_number_t)stgVar533;
	macroDef609->length=3;
	macroDef609->arr=(number_t*)(STG_OFFSET(stgVar533, VECTOR_HEADER_BYTES));
	

	macroDef609->arr[0] = 1;;

	macroDef609->arr[1] = 2;;

	macroDef609->arr[2] = 3;;;
	array_number_t a_dps = macroDef609;
	card_t b_shp = 3;
	card_t size668 = width_card_t(b_shp);
	array_number_t stgVar537 = storage_alloc(size668);
	array_number_t macroDef610 = (array_number_t)stgVar537;
	macroDef610->length=3;
	macroDef610->arr=(number_t*)(STG_OFFSET(stgVar537, VECTOR_HEADER_BYTES));
	

	macroDef610->arr[0] = 5;;

	macroDef610->arr[1] = 6;;

	macroDef610->arr[2] = 7;;;
	array_number_t b_dps = macroDef610;
	array_print(a_dps);
	array_print(b_dps);
	card_t c_shp = TOP_LEVEL_linalg_cross_shp(a_shp, b_shp);
	card_t size667 = width_card_t(c_shp);
	array_number_t stgVar541 = storage_alloc(size667);
	array_number_t c_dps = TOP_LEVEL_linalg_cross_dps(stgVar541, a_dps, b_dps, a_shp, b_shp);
	array_print(c_dps);
	card_t d_shp = TOP_LEVEL_linalg_mult_by_scalar_shp(c_shp, 0);
	card_t size666 = width_card_t(d_shp);
	array_number_t stgVar544 = storage_alloc(size666);
	array_number_t d_dps = TOP_LEVEL_linalg_mult_by_scalar_dps(stgVar544, c_dps, 15, c_shp, 0);
	array_print(d_dps);
	card_t e_shp = TOP_LEVEL_linalg_vectorAdd_shp(a_shp, b_shp);
	card_t size665 = width_card_t(e_shp);
	array_number_t stgVar547 = storage_alloc(size665);
	array_number_t e_dps = TOP_LEVEL_linalg_vectorAdd_dps(stgVar547, a_dps, b_dps, a_shp, b_shp);
	array_print(e_dps);
	card_t f_shp = TOP_LEVEL_linalg_vectorSub_shp(a_shp, b_shp);
	card_t size664 = width_card_t(f_shp);
	array_number_t stgVar550 = storage_alloc(size664);
	array_number_t f_dps = TOP_LEVEL_linalg_vectorSub_dps(stgVar550, a_dps, b_dps, a_shp, b_shp);
	array_print(f_dps);
	card_t g_shp = TOP_LEVEL_linalg_vectorAdd3_shp(a_shp, b_shp, c_shp);
	card_t size663 = width_card_t(g_shp);
	array_number_t stgVar553 = storage_alloc(size663);
	array_number_t g_dps = TOP_LEVEL_linalg_vectorAdd3_dps(stgVar553, a_dps, b_dps, c_dps, a_shp, b_shp, c_shp);
	array_print(g_dps);
	card_t h_shp = 0;
	number_t h_dps = TOP_LEVEL_linalg_sqnorm_dps(empty_storage, a_dps, a_shp);
	number_print(h_dps);
	card_t i_shp = 0;
	number_t i_dps = TOP_LEVEL_linalg_dot_prod_dps(empty_storage, a_dps, b_dps, a_shp, b_shp);
	number_print(i_dps);
	card_t r1_shp = 3;
	card_t size662 = width_card_t(r1_shp);
	array_number_t stgVar562 = storage_alloc(size662);
	array_number_t macroDef611 = (array_number_t)stgVar562;
	macroDef611->length=3;
	macroDef611->arr=(number_t*)(STG_OFFSET(stgVar562, VECTOR_HEADER_BYTES));
	

	macroDef611->arr[0] = 1;;

	macroDef611->arr[1] = 2;;

	macroDef611->arr[2] = 3;;;
	array_number_t r1_dps = macroDef611;
	card_t r2_shp = 3;
	card_t size661 = width_card_t(r2_shp);
	array_number_t stgVar566 = storage_alloc(size661);
	array_number_t macroDef612 = (array_number_t)stgVar566;
	macroDef612->length=3;
	macroDef612->arr=(number_t*)(STG_OFFSET(stgVar566, VECTOR_HEADER_BYTES));
	

	macroDef612->arr[0] = 4;;

	macroDef612->arr[1] = 5;;

	macroDef612->arr[2] = 6;;;
	array_number_t r2_dps = macroDef612;
	card_t r3_shp = 3;
	card_t size660 = width_card_t(r3_shp);
	array_number_t stgVar570 = storage_alloc(size660);
	array_number_t macroDef613 = (array_number_t)stgVar570;
	macroDef613->length=3;
	macroDef613->arr=(number_t*)(STG_OFFSET(stgVar570, VECTOR_HEADER_BYTES));
	

	macroDef613->arr[0] = 7;;

	macroDef613->arr[1] = 8;;

	macroDef613->arr[2] = 9;;;
	array_number_t r3_dps = macroDef613;
	matrix_shape_t mat0_shp = nested_shape_card_t(3, 3);
	card_t size659 = width_matrix_shape_t(mat0_shp);
	array_number_t stgVar574 = storage_alloc(size659);
	array_array_number_t macroDef617 = (array_array_number_t)stgVar574;
	macroDef617->length=3;
	macroDef617->arr=(array_number_t*)(STG_OFFSET(stgVar574, VECTOR_HEADER_BYTES));
	int stgVar574_offsetVar = 0;storage_t stgVar575 = STG_OFFSET(stgVar574, MATRIX_HEADER_BYTES(3) + stgVar574_offsetVar);array_number_t macroDef614 = (array_number_t)stgVar575;
	macroDef614->length=3;
	macroDef614->arr=(number_t*)(STG_OFFSET(stgVar575, VECTOR_HEADER_BYTES));
	

	macroDef614->arr[0] = 1;;

	macroDef614->arr[1] = 2;;

	macroDef614->arr[2] = 3;;;

	macroDef617->arr[0] = macroDef614;;stgVar574_offsetVar += VECTOR_ALL_BYTES(macroDef617->arr[0]->length);storage_t stgVar579 = STG_OFFSET(stgVar574, MATRIX_HEADER_BYTES(3) + stgVar574_offsetVar);array_number_t macroDef615 = (array_number_t)stgVar579;
	macroDef615->length=3;
	macroDef615->arr=(number_t*)(STG_OFFSET(stgVar579, VECTOR_HEADER_BYTES));
	

	macroDef615->arr[0] = 4;;

	macroDef615->arr[1] = 5;;

	macroDef615->arr[2] = 6;;;

	macroDef617->arr[1] = macroDef615;;stgVar574_offsetVar += VECTOR_ALL_BYTES(macroDef617->arr[1]->length);storage_t stgVar583 = STG_OFFSET(stgVar574, MATRIX_HEADER_BYTES(3) + stgVar574_offsetVar);array_number_t macroDef616 = (array_number_t)stgVar583;
	macroDef616->length=3;
	macroDef616->arr=(number_t*)(STG_OFFSET(stgVar583, VECTOR_HEADER_BYTES));
	

	macroDef616->arr[0] = 7;;

	macroDef616->arr[1] = 8;;

	macroDef616->arr[2] = 9;;;

	macroDef617->arr[2] = macroDef616;;stgVar574_offsetVar += VECTOR_ALL_BYTES(macroDef617->arr[2]->length);;
	array_array_number_t mat0_dps = macroDef617;
	matrix_shape_t mat1_shp = nested_shape_card_t(r1_shp, 3);
	card_t size658 = width_matrix_shape_t(mat1_shp);
	array_number_t stgVar587 = storage_alloc(size658);
	array_array_number_t macroDef618 = (array_array_number_t)stgVar587;
	macroDef618->length=3;
	macroDef618->arr=(array_number_t*)(STG_OFFSET(stgVar587, VECTOR_HEADER_BYTES));
	int stgVar587_offsetVar = 0;storage_t stgVar588 = STG_OFFSET(stgVar587, MATRIX_HEADER_BYTES(3) + stgVar587_offsetVar);

	macroDef618->arr[0] = r1_dps;;stgVar587_offsetVar += VECTOR_ALL_BYTES(macroDef618->arr[0]->length);storage_t stgVar589 = STG_OFFSET(stgVar587, MATRIX_HEADER_BYTES(3) + stgVar587_offsetVar);

	macroDef618->arr[1] = r2_dps;;stgVar587_offsetVar += VECTOR_ALL_BYTES(macroDef618->arr[1]->length);storage_t stgVar590 = STG_OFFSET(stgVar587, MATRIX_HEADER_BYTES(3) + stgVar587_offsetVar);

	macroDef618->arr[2] = r3_dps;;stgVar587_offsetVar += VECTOR_ALL_BYTES(macroDef618->arr[2]->length);;
	array_array_number_t mat1_dps = macroDef618;
	matrix_shape_t n_shp = TOP_LEVEL_linalg_matrixMult_shp(mat0_shp, mat1_shp);
	card_t size657 = width_matrix_shape_t(n_shp);
	array_number_t stgVar591 = storage_alloc(size657);
	array_array_number_t n_dps = TOP_LEVEL_linalg_matrixMult_dps(stgVar591, mat0_dps, mat1_dps, mat0_shp, mat1_shp);
	matrix_print(n_dps);
	matrix_shape_t o_shp = TOP_LEVEL_linalg_matrixTranspose_shp(n_shp);
	card_t size656 = width_matrix_shape_t(o_shp);
	array_number_t stgVar594 = storage_alloc(size656);
	array_array_number_t o_dps = TOP_LEVEL_linalg_matrixTranspose_dps(stgVar594, n_dps, n_shp);
	matrix_print(o_dps);
	matrix_shape_t p_shp = TOP_LEVEL_linalg_matrixConcatCol_shp(mat1_shp, mat1_shp);
	card_t size655 = width_matrix_shape_t(p_shp);
	array_number_t stgVar596 = storage_alloc(size655);
	array_array_number_t p_dps = TOP_LEVEL_linalg_matrixConcatCol_dps(stgVar596, mat1_dps, mat1_dps, mat1_shp, mat1_shp);
	matrix_print(p_dps);
	matrix_shape_t t_shp = TOP_LEVEL_linalg_matrixAdd_shp(mat1_shp, mat1_shp);
	card_t size654 = width_matrix_shape_t(t_shp);
	array_number_t stgVar599 = storage_alloc(size654);
	array_array_number_t t_dps = TOP_LEVEL_linalg_matrixAdd_dps(stgVar599, mat1_dps, mat1_dps, mat1_shp, mat1_shp);
	matrix_print(t_dps);
	matrix_shape_t u_shp = TOP_LEVEL_linalg_matrixFillFromVector_shp(5, a_shp);
	card_t size653 = width_matrix_shape_t(u_shp);
	array_number_t stgVar602 = storage_alloc(size653);
	array_array_number_t u_dps = TOP_LEVEL_linalg_matrixFillFromVector_dps(stgVar602, 5, a_dps, 5, a_shp);
	matrix_print(u_dps);
	matrix_shape_t v_shp = TOP_LEVEL_linalg_matrixFill_shp(5, 2, 0);
	card_t size652 = width_matrix_shape_t(v_shp);
	array_number_t stgVar605 = storage_alloc(size652);
	array_array_number_t v_dps = TOP_LEVEL_linalg_matrixFill_dps(stgVar605, 5, 2, 5, 5, 2, 0);
	matrix_print(v_dps);
	;
	storage_free(stgVar605, size652);
	;
	storage_free(stgVar602, size653);
	;
	storage_free(stgVar599, size654);
	;
	storage_free(stgVar596, size655);
	;
	storage_free(stgVar594, size656);
	;
	storage_free(stgVar591, size657);
	;
	storage_free(stgVar587, size658);
	;
	storage_free(stgVar574, size659);
	;
	storage_free(stgVar570, size660);
	;
	storage_free(stgVar566, size661);
	;
	storage_free(stgVar562, size662);
	;
	storage_free(stgVar553, size663);
	;
	storage_free(stgVar550, size664);
	;
	storage_free(stgVar547, size665);
	;
	storage_free(stgVar544, size666);
	;
	storage_free(stgVar541, size667);
	;
	storage_free(stgVar537, size668);
	;
	storage_free(stgVar533, size669);
	return ;
}
#endif
