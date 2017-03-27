#ifndef __USECASES_HT_STORAGED_H__ 
#define __USECASES_HT_STORAGED_H__ 
#include "runtime/fsharp.h"
#include <stdio.h>
#include <math.h>
#include "linalg_storaged.h"

matrix3d_shape_t TOP_LEVEL_usecases_ht_matrix3DUpdate_shp(matrix3d_shape_t m_shp, card_t s_shp, card_t e_shp, matrix3d_shape_t nm_shp) {
	
	return nested_shape_matrix_shape_t(nm_shp.elem, m_shp.card);
}


array_array_array_number_t TOP_LEVEL_usecases_ht_matrix3DUpdate_dps(storage_t stgVar1393, array_array_array_number_t m_dps, index_t s_dps, index_t e_dps, array_array_array_number_t nm_dps, matrix3d_shape_t m_shp, card_t s_shp, card_t e_shp, matrix3d_shape_t nm_shp) {
	card_t macroDef1399 = m_dps->length;
	array_array_array_number_t macroDef1400 = (array_array_array_number_t)stgVar1393;
		macroDef1400->length=macroDef1399;
		macroDef1400->arr=(array_array_number_t*)(STG_OFFSET(macroDef1400, VECTOR_HEADER_BYTES));
		storage_t stgVar1395 = (STG_OFFSET(macroDef1400, MATRIX_HEADER_BYTES(macroDef1399)));
		for(int i_dps = 0; i_dps < macroDef1400->length; i_dps++){
			card_t isInRange_shp = 0;
			bool_t isInRange_dps = 0;
	if((i_dps) >= (s_dps)) {
		
		isInRange_dps = (i_dps) < (e_dps);;
	} else {
		
		isInRange_dps = false;;
	}
			array_array_number_t ite1401 = 0;
	if(isInRange_dps) {
		
		ite1401 = nm_dps->arr[(i_dps) - (s_dps)];;
	} else {
		
		ite1401 = m_dps->arr[i_dps];;
	}
			macroDef1400->arr[i_dps] = ite1401;;
			stgVar1395 = STG_OFFSET(stgVar1395, VECTOR_ALL_BYTES(macroDef1400->arr[i_dps]->length));
		}
	return macroDef1400;
}

matrix_shape_t TOP_LEVEL_usecases_ht_to_pose_params_shp(card_t theta_shp, card_t n_bones_shp) {
	
	return TOP_LEVEL_linalg_matrixConcat_shp(nested_shape_card_t(TOP_LEVEL_linalg_vectorSlice_shp(3, 0, theta_shp), 5), TOP_LEVEL_linalg_matrixConcat_shp(nested_shape_card_t(3, 4), TOP_LEVEL_linalg_matrixConcat_shp(nested_shape_card_t(3, 4), TOP_LEVEL_linalg_matrixConcat_shp(nested_shape_card_t(3, 4), TOP_LEVEL_linalg_matrixConcat_shp(nested_shape_card_t(3, 4), nested_shape_card_t(3, 4))))));
}


array_array_number_t TOP_LEVEL_usecases_ht_to_pose_params_dps(storage_t stgVar1402, array_number_t theta_dps, card_t n_bones_dps, card_t theta_shp, card_t n_bones_shp) {
	card_t row1_shp = TOP_LEVEL_linalg_vectorSlice_shp(3, 0, theta_shp);
	card_t size1810 = width_card_t(row1_shp);
	array_number_t stgVar1403 = storage_alloc(size1810);
	array_array_number_t macroDef1796;array_number_t row1_dps = TOP_LEVEL_linalg_vectorSlice_dps(stgVar1403, 3, 0, theta_dps, 3, 0, theta_shp);
	card_t row2_shp = 3;
	card_t size1809 = width_card_t(row2_shp);
	array_number_t stgVar1407 = storage_alloc(size1809);
	array_array_number_t macroDef1795;array_number_t macroDef1755 = (array_number_t)stgVar1407;
	macroDef1755->length=3;
	macroDef1755->arr=(number_t*)(STG_OFFSET(stgVar1407, VECTOR_HEADER_BYTES));
	

	macroDef1755->arr[0] = 1;;

	macroDef1755->arr[1] = 1;;

	macroDef1755->arr[2] = 1;;;
	array_number_t row2_dps = macroDef1755;
	card_t row3_shp = TOP_LEVEL_linalg_vectorSlice_shp(3, 0, theta_shp);
	card_t size1808 = width_card_t(row3_shp);
	array_number_t stgVar1411 = storage_alloc(size1808);
	array_array_number_t macroDef1794;array_number_t row3_dps = TOP_LEVEL_linalg_vectorSlice_dps(stgVar1411, 3, 3, theta_dps, 3, 0, theta_shp);
	card_t zeroRow_shp = 3;
	card_t size1807 = width_card_t(zeroRow_shp);
	array_number_t stgVar1415 = storage_alloc(size1807);
	array_array_number_t macroDef1793;array_number_t macroDef1756 = (array_number_t)stgVar1415;
	macroDef1756->length=3;
	macroDef1756->arr=(number_t*)(STG_OFFSET(stgVar1415, VECTOR_HEADER_BYTES));
	

	macroDef1756->arr[0] = 0;;

	macroDef1756->arr[1] = 0;;

	macroDef1756->arr[2] = 0;;;
	array_number_t zeroRow_dps = macroDef1756;
	matrix_shape_t pose_params_shp = nested_shape_card_t(row1_shp, 5);
	card_t size1806 = width_matrix_shape_t(pose_params_shp);
	array_number_t stgVar1419 = storage_alloc(size1806);
	array_array_number_t macroDef1792;array_array_number_t macroDef1757 = (array_array_number_t)stgVar1419;
	macroDef1757->length=5;
	macroDef1757->arr=(array_number_t*)(STG_OFFSET(stgVar1419, VECTOR_HEADER_BYTES));
	int stgVar1419_offsetVar = 0;storage_t stgVar1420 = STG_OFFSET(stgVar1419, MATRIX_HEADER_BYTES(5) + stgVar1419_offsetVar);

	macroDef1757->arr[0] = row1_dps;;stgVar1419_offsetVar += VECTOR_ALL_BYTES(macroDef1757->arr[0]->length);storage_t stgVar1421 = STG_OFFSET(stgVar1419, MATRIX_HEADER_BYTES(5) + stgVar1419_offsetVar);

	macroDef1757->arr[1] = row2_dps;;stgVar1419_offsetVar += VECTOR_ALL_BYTES(macroDef1757->arr[1]->length);storage_t stgVar1422 = STG_OFFSET(stgVar1419, MATRIX_HEADER_BYTES(5) + stgVar1419_offsetVar);

	macroDef1757->arr[2] = row3_dps;;stgVar1419_offsetVar += VECTOR_ALL_BYTES(macroDef1757->arr[2]->length);storage_t stgVar1423 = STG_OFFSET(stgVar1419, MATRIX_HEADER_BYTES(5) + stgVar1419_offsetVar);

	macroDef1757->arr[3] = zeroRow_dps;;stgVar1419_offsetVar += VECTOR_ALL_BYTES(macroDef1757->arr[3]->length);storage_t stgVar1424 = STG_OFFSET(stgVar1419, MATRIX_HEADER_BYTES(5) + stgVar1419_offsetVar);

	macroDef1757->arr[4] = zeroRow_dps;;stgVar1419_offsetVar += VECTOR_ALL_BYTES(macroDef1757->arr[4]->length);;
	array_array_number_t pose_params_dps = macroDef1757;
	card_t i1_shp = 0;
	index_t i1_dps = 5;
	matrix_shape_t finger1_shp = nested_shape_card_t(3, 4);
	card_t size1805 = width_matrix_shape_t(finger1_shp);
	array_number_t stgVar1426 = storage_alloc(size1805);
	array_array_number_t macroDef1791;array_array_number_t macroDef1762 = (array_array_number_t)stgVar1426;
	macroDef1762->length=4;
	macroDef1762->arr=(array_number_t*)(STG_OFFSET(stgVar1426, VECTOR_HEADER_BYTES));
	int stgVar1426_offsetVar = 0;storage_t stgVar1427 = STG_OFFSET(stgVar1426, MATRIX_HEADER_BYTES(4) + stgVar1426_offsetVar);array_number_t macroDef1758 = (array_number_t)stgVar1427;
	macroDef1758->length=3;
	macroDef1758->arr=(number_t*)(STG_OFFSET(stgVar1427, VECTOR_HEADER_BYTES));
	

	macroDef1758->arr[0] = theta_dps->arr[i1_dps];;

	macroDef1758->arr[1] = theta_dps->arr[(i1_dps) + (1)];;

	macroDef1758->arr[2] = 0;;;

	macroDef1762->arr[0] = macroDef1758;;stgVar1426_offsetVar += VECTOR_ALL_BYTES(macroDef1762->arr[0]->length);storage_t stgVar1433 = STG_OFFSET(stgVar1426, MATRIX_HEADER_BYTES(4) + stgVar1426_offsetVar);array_number_t macroDef1759 = (array_number_t)stgVar1433;
	macroDef1759->length=3;
	macroDef1759->arr=(number_t*)(STG_OFFSET(stgVar1433, VECTOR_HEADER_BYTES));
	

	macroDef1759->arr[0] = theta_dps->arr[(i1_dps) + (2)];;

	macroDef1759->arr[1] = 0;;

	macroDef1759->arr[2] = 0;;;

	macroDef1762->arr[1] = macroDef1759;;stgVar1426_offsetVar += VECTOR_ALL_BYTES(macroDef1762->arr[1]->length);storage_t stgVar1438 = STG_OFFSET(stgVar1426, MATRIX_HEADER_BYTES(4) + stgVar1426_offsetVar);array_number_t macroDef1760 = (array_number_t)stgVar1438;
	macroDef1760->length=3;
	macroDef1760->arr=(number_t*)(STG_OFFSET(stgVar1438, VECTOR_HEADER_BYTES));
	

	macroDef1760->arr[0] = theta_dps->arr[(i1_dps) + (3)];;

	macroDef1760->arr[1] = 0;;

	macroDef1760->arr[2] = 0;;;

	macroDef1762->arr[2] = macroDef1760;;stgVar1426_offsetVar += VECTOR_ALL_BYTES(macroDef1762->arr[2]->length);storage_t stgVar1443 = STG_OFFSET(stgVar1426, MATRIX_HEADER_BYTES(4) + stgVar1426_offsetVar);array_number_t macroDef1761 = (array_number_t)stgVar1443;
	macroDef1761->length=3;
	macroDef1761->arr=(number_t*)(STG_OFFSET(stgVar1443, VECTOR_HEADER_BYTES));
	

	macroDef1761->arr[0] = 0;;

	macroDef1761->arr[1] = 0;;

	macroDef1761->arr[2] = 0;;;

	macroDef1762->arr[3] = macroDef1761;;stgVar1426_offsetVar += VECTOR_ALL_BYTES(macroDef1762->arr[3]->length);;
	array_array_number_t finger1_dps = macroDef1762;
	card_t i2_shp = 0;
	index_t i2_dps = (i1_dps) + (4);
	matrix_shape_t finger2_shp = nested_shape_card_t(3, 4);
	card_t size1804 = width_matrix_shape_t(finger2_shp);
	array_number_t stgVar1448 = storage_alloc(size1804);
	array_array_number_t macroDef1790;array_array_number_t macroDef1767 = (array_array_number_t)stgVar1448;
	macroDef1767->length=4;
	macroDef1767->arr=(array_number_t*)(STG_OFFSET(stgVar1448, VECTOR_HEADER_BYTES));
	int stgVar1448_offsetVar = 0;storage_t stgVar1449 = STG_OFFSET(stgVar1448, MATRIX_HEADER_BYTES(4) + stgVar1448_offsetVar);array_number_t macroDef1763 = (array_number_t)stgVar1449;
	macroDef1763->length=3;
	macroDef1763->arr=(number_t*)(STG_OFFSET(stgVar1449, VECTOR_HEADER_BYTES));
	

	macroDef1763->arr[0] = theta_dps->arr[i2_dps];;

	macroDef1763->arr[1] = theta_dps->arr[(i2_dps) + (1)];;

	macroDef1763->arr[2] = 0;;;

	macroDef1767->arr[0] = macroDef1763;;stgVar1448_offsetVar += VECTOR_ALL_BYTES(macroDef1767->arr[0]->length);storage_t stgVar1455 = STG_OFFSET(stgVar1448, MATRIX_HEADER_BYTES(4) + stgVar1448_offsetVar);array_number_t macroDef1764 = (array_number_t)stgVar1455;
	macroDef1764->length=3;
	macroDef1764->arr=(number_t*)(STG_OFFSET(stgVar1455, VECTOR_HEADER_BYTES));
	

	macroDef1764->arr[0] = theta_dps->arr[(i2_dps) + (2)];;

	macroDef1764->arr[1] = 0;;

	macroDef1764->arr[2] = 0;;;

	macroDef1767->arr[1] = macroDef1764;;stgVar1448_offsetVar += VECTOR_ALL_BYTES(macroDef1767->arr[1]->length);storage_t stgVar1460 = STG_OFFSET(stgVar1448, MATRIX_HEADER_BYTES(4) + stgVar1448_offsetVar);array_number_t macroDef1765 = (array_number_t)stgVar1460;
	macroDef1765->length=3;
	macroDef1765->arr=(number_t*)(STG_OFFSET(stgVar1460, VECTOR_HEADER_BYTES));
	

	macroDef1765->arr[0] = theta_dps->arr[(i2_dps) + (3)];;

	macroDef1765->arr[1] = 0;;

	macroDef1765->arr[2] = 0;;;

	macroDef1767->arr[2] = macroDef1765;;stgVar1448_offsetVar += VECTOR_ALL_BYTES(macroDef1767->arr[2]->length);storage_t stgVar1465 = STG_OFFSET(stgVar1448, MATRIX_HEADER_BYTES(4) + stgVar1448_offsetVar);array_number_t macroDef1766 = (array_number_t)stgVar1465;
	macroDef1766->length=3;
	macroDef1766->arr=(number_t*)(STG_OFFSET(stgVar1465, VECTOR_HEADER_BYTES));
	

	macroDef1766->arr[0] = 0;;

	macroDef1766->arr[1] = 0;;

	macroDef1766->arr[2] = 0;;;

	macroDef1767->arr[3] = macroDef1766;;stgVar1448_offsetVar += VECTOR_ALL_BYTES(macroDef1767->arr[3]->length);;
	array_array_number_t finger2_dps = macroDef1767;
	card_t i3_shp = 0;
	index_t i3_dps = (i2_dps) + (4);
	matrix_shape_t finger3_shp = nested_shape_card_t(3, 4);
	card_t size1803 = width_matrix_shape_t(finger3_shp);
	array_number_t stgVar1470 = storage_alloc(size1803);
	array_array_number_t macroDef1789;array_array_number_t macroDef1772 = (array_array_number_t)stgVar1470;
	macroDef1772->length=4;
	macroDef1772->arr=(array_number_t*)(STG_OFFSET(stgVar1470, VECTOR_HEADER_BYTES));
	int stgVar1470_offsetVar = 0;storage_t stgVar1471 = STG_OFFSET(stgVar1470, MATRIX_HEADER_BYTES(4) + stgVar1470_offsetVar);array_number_t macroDef1768 = (array_number_t)stgVar1471;
	macroDef1768->length=3;
	macroDef1768->arr=(number_t*)(STG_OFFSET(stgVar1471, VECTOR_HEADER_BYTES));
	

	macroDef1768->arr[0] = theta_dps->arr[i3_dps];;

	macroDef1768->arr[1] = theta_dps->arr[(i3_dps) + (1)];;

	macroDef1768->arr[2] = 0;;;

	macroDef1772->arr[0] = macroDef1768;;stgVar1470_offsetVar += VECTOR_ALL_BYTES(macroDef1772->arr[0]->length);storage_t stgVar1477 = STG_OFFSET(stgVar1470, MATRIX_HEADER_BYTES(4) + stgVar1470_offsetVar);array_number_t macroDef1769 = (array_number_t)stgVar1477;
	macroDef1769->length=3;
	macroDef1769->arr=(number_t*)(STG_OFFSET(stgVar1477, VECTOR_HEADER_BYTES));
	

	macroDef1769->arr[0] = theta_dps->arr[(i3_dps) + (2)];;

	macroDef1769->arr[1] = 0;;

	macroDef1769->arr[2] = 0;;;

	macroDef1772->arr[1] = macroDef1769;;stgVar1470_offsetVar += VECTOR_ALL_BYTES(macroDef1772->arr[1]->length);storage_t stgVar1482 = STG_OFFSET(stgVar1470, MATRIX_HEADER_BYTES(4) + stgVar1470_offsetVar);array_number_t macroDef1770 = (array_number_t)stgVar1482;
	macroDef1770->length=3;
	macroDef1770->arr=(number_t*)(STG_OFFSET(stgVar1482, VECTOR_HEADER_BYTES));
	

	macroDef1770->arr[0] = theta_dps->arr[(i3_dps) + (3)];;

	macroDef1770->arr[1] = 0;;

	macroDef1770->arr[2] = 0;;;

	macroDef1772->arr[2] = macroDef1770;;stgVar1470_offsetVar += VECTOR_ALL_BYTES(macroDef1772->arr[2]->length);storage_t stgVar1487 = STG_OFFSET(stgVar1470, MATRIX_HEADER_BYTES(4) + stgVar1470_offsetVar);array_number_t macroDef1771 = (array_number_t)stgVar1487;
	macroDef1771->length=3;
	macroDef1771->arr=(number_t*)(STG_OFFSET(stgVar1487, VECTOR_HEADER_BYTES));
	

	macroDef1771->arr[0] = 0;;

	macroDef1771->arr[1] = 0;;

	macroDef1771->arr[2] = 0;;;

	macroDef1772->arr[3] = macroDef1771;;stgVar1470_offsetVar += VECTOR_ALL_BYTES(macroDef1772->arr[3]->length);;
	array_array_number_t finger3_dps = macroDef1772;
	card_t i4_shp = 0;
	index_t i4_dps = (i3_dps) + (4);
	matrix_shape_t finger4_shp = nested_shape_card_t(3, 4);
	card_t size1802 = width_matrix_shape_t(finger4_shp);
	array_number_t stgVar1492 = storage_alloc(size1802);
	array_array_number_t macroDef1788;array_array_number_t macroDef1777 = (array_array_number_t)stgVar1492;
	macroDef1777->length=4;
	macroDef1777->arr=(array_number_t*)(STG_OFFSET(stgVar1492, VECTOR_HEADER_BYTES));
	int stgVar1492_offsetVar = 0;storage_t stgVar1493 = STG_OFFSET(stgVar1492, MATRIX_HEADER_BYTES(4) + stgVar1492_offsetVar);array_number_t macroDef1773 = (array_number_t)stgVar1493;
	macroDef1773->length=3;
	macroDef1773->arr=(number_t*)(STG_OFFSET(stgVar1493, VECTOR_HEADER_BYTES));
	

	macroDef1773->arr[0] = theta_dps->arr[i4_dps];;

	macroDef1773->arr[1] = theta_dps->arr[(i4_dps) + (1)];;

	macroDef1773->arr[2] = 0;;;

	macroDef1777->arr[0] = macroDef1773;;stgVar1492_offsetVar += VECTOR_ALL_BYTES(macroDef1777->arr[0]->length);storage_t stgVar1499 = STG_OFFSET(stgVar1492, MATRIX_HEADER_BYTES(4) + stgVar1492_offsetVar);array_number_t macroDef1774 = (array_number_t)stgVar1499;
	macroDef1774->length=3;
	macroDef1774->arr=(number_t*)(STG_OFFSET(stgVar1499, VECTOR_HEADER_BYTES));
	

	macroDef1774->arr[0] = theta_dps->arr[(i4_dps) + (2)];;

	macroDef1774->arr[1] = 0;;

	macroDef1774->arr[2] = 0;;;

	macroDef1777->arr[1] = macroDef1774;;stgVar1492_offsetVar += VECTOR_ALL_BYTES(macroDef1777->arr[1]->length);storage_t stgVar1504 = STG_OFFSET(stgVar1492, MATRIX_HEADER_BYTES(4) + stgVar1492_offsetVar);array_number_t macroDef1775 = (array_number_t)stgVar1504;
	macroDef1775->length=3;
	macroDef1775->arr=(number_t*)(STG_OFFSET(stgVar1504, VECTOR_HEADER_BYTES));
	

	macroDef1775->arr[0] = theta_dps->arr[(i4_dps) + (3)];;

	macroDef1775->arr[1] = 0;;

	macroDef1775->arr[2] = 0;;;

	macroDef1777->arr[2] = macroDef1775;;stgVar1492_offsetVar += VECTOR_ALL_BYTES(macroDef1777->arr[2]->length);storage_t stgVar1509 = STG_OFFSET(stgVar1492, MATRIX_HEADER_BYTES(4) + stgVar1492_offsetVar);array_number_t macroDef1776 = (array_number_t)stgVar1509;
	macroDef1776->length=3;
	macroDef1776->arr=(number_t*)(STG_OFFSET(stgVar1509, VECTOR_HEADER_BYTES));
	

	macroDef1776->arr[0] = 0;;

	macroDef1776->arr[1] = 0;;

	macroDef1776->arr[2] = 0;;;

	macroDef1777->arr[3] = macroDef1776;;stgVar1492_offsetVar += VECTOR_ALL_BYTES(macroDef1777->arr[3]->length);;
	array_array_number_t finger4_dps = macroDef1777;
	card_t i5_shp = 0;
	index_t i5_dps = (i4_dps) + (4);
	matrix_shape_t finger5_shp = nested_shape_card_t(3, 4);
	card_t size1801 = width_matrix_shape_t(finger5_shp);
	array_number_t stgVar1514 = storage_alloc(size1801);
	array_array_number_t macroDef1787;array_array_number_t macroDef1782 = (array_array_number_t)stgVar1514;
	macroDef1782->length=4;
	macroDef1782->arr=(array_number_t*)(STG_OFFSET(stgVar1514, VECTOR_HEADER_BYTES));
	int stgVar1514_offsetVar = 0;storage_t stgVar1515 = STG_OFFSET(stgVar1514, MATRIX_HEADER_BYTES(4) + stgVar1514_offsetVar);array_number_t macroDef1778 = (array_number_t)stgVar1515;
	macroDef1778->length=3;
	macroDef1778->arr=(number_t*)(STG_OFFSET(stgVar1515, VECTOR_HEADER_BYTES));
	

	macroDef1778->arr[0] = theta_dps->arr[i5_dps];;

	macroDef1778->arr[1] = theta_dps->arr[(i5_dps) + (1)];;

	macroDef1778->arr[2] = 0;;;

	macroDef1782->arr[0] = macroDef1778;;stgVar1514_offsetVar += VECTOR_ALL_BYTES(macroDef1782->arr[0]->length);storage_t stgVar1521 = STG_OFFSET(stgVar1514, MATRIX_HEADER_BYTES(4) + stgVar1514_offsetVar);array_number_t macroDef1779 = (array_number_t)stgVar1521;
	macroDef1779->length=3;
	macroDef1779->arr=(number_t*)(STG_OFFSET(stgVar1521, VECTOR_HEADER_BYTES));
	

	macroDef1779->arr[0] = theta_dps->arr[(i5_dps) + (2)];;

	macroDef1779->arr[1] = 0;;

	macroDef1779->arr[2] = 0;;;

	macroDef1782->arr[1] = macroDef1779;;stgVar1514_offsetVar += VECTOR_ALL_BYTES(macroDef1782->arr[1]->length);storage_t stgVar1526 = STG_OFFSET(stgVar1514, MATRIX_HEADER_BYTES(4) + stgVar1514_offsetVar);array_number_t macroDef1780 = (array_number_t)stgVar1526;
	macroDef1780->length=3;
	macroDef1780->arr=(number_t*)(STG_OFFSET(stgVar1526, VECTOR_HEADER_BYTES));
	

	macroDef1780->arr[0] = theta_dps->arr[(i5_dps) + (3)];;

	macroDef1780->arr[1] = 0;;

	macroDef1780->arr[2] = 0;;;

	macroDef1782->arr[2] = macroDef1780;;stgVar1514_offsetVar += VECTOR_ALL_BYTES(macroDef1782->arr[2]->length);storage_t stgVar1531 = STG_OFFSET(stgVar1514, MATRIX_HEADER_BYTES(4) + stgVar1514_offsetVar);array_number_t macroDef1781 = (array_number_t)stgVar1531;
	macroDef1781->length=3;
	macroDef1781->arr=(number_t*)(STG_OFFSET(stgVar1531, VECTOR_HEADER_BYTES));
	

	macroDef1781->arr[0] = 0;;

	macroDef1781->arr[1] = 0;;

	macroDef1781->arr[2] = 0;;;

	macroDef1782->arr[3] = macroDef1781;;stgVar1514_offsetVar += VECTOR_ALL_BYTES(macroDef1782->arr[3]->length);;
	array_array_number_t finger5_dps = macroDef1782;
	card_t size1800 = width_matrix_shape_t(TOP_LEVEL_linalg_matrixConcat_shp(finger1_shp, TOP_LEVEL_linalg_matrixConcat_shp(finger2_shp, TOP_LEVEL_linalg_matrixConcat_shp(finger3_shp, TOP_LEVEL_linalg_matrixConcat_shp(finger4_shp, finger5_shp)))));
	array_number_t stgVar1536 = storage_alloc(size1800);
	array_array_number_t macroDef1786;card_t size1799 = width_matrix_shape_t(TOP_LEVEL_linalg_matrixConcat_shp(finger2_shp, TOP_LEVEL_linalg_matrixConcat_shp(finger3_shp, TOP_LEVEL_linalg_matrixConcat_shp(finger4_shp, finger5_shp))));
	array_number_t stgVar1538 = storage_alloc(size1799);
	array_array_number_t macroDef1785;card_t size1798 = width_matrix_shape_t(TOP_LEVEL_linalg_matrixConcat_shp(finger3_shp, TOP_LEVEL_linalg_matrixConcat_shp(finger4_shp, finger5_shp)));
	array_number_t stgVar1540 = storage_alloc(size1798);
	array_array_number_t macroDef1784;card_t size1797 = width_matrix_shape_t(TOP_LEVEL_linalg_matrixConcat_shp(finger4_shp, finger5_shp));
	array_number_t stgVar1542 = storage_alloc(size1797);
	array_array_number_t macroDef1783;
	macroDef1783 = TOP_LEVEL_linalg_matrixConcat_dps(stgVar1540, finger3_dps, TOP_LEVEL_linalg_matrixConcat_dps(stgVar1542, finger4_dps, finger5_dps, finger4_shp, finger5_shp), finger3_shp, TOP_LEVEL_linalg_matrixConcat_shp(finger4_shp, finger5_shp));;
	storage_free(stgVar1542, size1797);
	macroDef1784 = TOP_LEVEL_linalg_matrixConcat_dps(stgVar1538, finger2_dps, macroDef1783, finger2_shp, TOP_LEVEL_linalg_matrixConcat_shp(finger3_shp, TOP_LEVEL_linalg_matrixConcat_shp(finger4_shp, finger5_shp)));;
	storage_free(stgVar1540, size1798);
	macroDef1785 = TOP_LEVEL_linalg_matrixConcat_dps(stgVar1536, finger1_dps, macroDef1784, finger1_shp, TOP_LEVEL_linalg_matrixConcat_shp(finger2_shp, TOP_LEVEL_linalg_matrixConcat_shp(finger3_shp, TOP_LEVEL_linalg_matrixConcat_shp(finger4_shp, finger5_shp))));;
	storage_free(stgVar1538, size1799);
	macroDef1786 = TOP_LEVEL_linalg_matrixConcat_dps(stgVar1402, pose_params_dps, macroDef1785, pose_params_shp, TOP_LEVEL_linalg_matrixConcat_shp(finger1_shp, TOP_LEVEL_linalg_matrixConcat_shp(finger2_shp, TOP_LEVEL_linalg_matrixConcat_shp(finger3_shp, TOP_LEVEL_linalg_matrixConcat_shp(finger4_shp, finger5_shp)))));;
	storage_free(stgVar1536, size1800);
	macroDef1787 = macroDef1786;;
	storage_free(stgVar1514, size1801);
	macroDef1788 = macroDef1787;;
	storage_free(stgVar1492, size1802);
	macroDef1789 = macroDef1788;;
	storage_free(stgVar1470, size1803);
	macroDef1790 = macroDef1789;;
	storage_free(stgVar1448, size1804);
	macroDef1791 = macroDef1790;;
	storage_free(stgVar1426, size1805);
	macroDef1792 = macroDef1791;;
	storage_free(stgVar1419, size1806);
	macroDef1793 = macroDef1792;;
	storage_free(stgVar1415, size1807);
	macroDef1794 = macroDef1793;;
	storage_free(stgVar1411, size1808);
	macroDef1795 = macroDef1794;;
	storage_free(stgVar1407, size1809);
	macroDef1796 = macroDef1795;;
	storage_free(stgVar1403, size1810);
	return macroDef1796;
}

matrix_shape_t TOP_LEVEL_usecases_ht_euler_angles_to_rotation_matrix_shp(card_t xzy_shp) {
	
	return TOP_LEVEL_linalg_matrixMult_shp(nested_shape_card_t(3, 3), TOP_LEVEL_linalg_matrixMult_shp(nested_shape_card_t(3, 3), nested_shape_card_t(3, 3)));
}


array_array_number_t TOP_LEVEL_usecases_ht_euler_angles_to_rotation_matrix_dps(storage_t stgVar1811, array_number_t xzy_dps, card_t xzy_shp) {
	card_t tx_shp = 0;
	number_t tx_dps = xzy_dps->arr[0];
	card_t ty_shp = 0;
	number_t ty_dps = xzy_dps->arr[2];
	card_t tz_shp = 0;
	number_t tz_dps = xzy_dps->arr[1];
	matrix_shape_t Rx_shp = nested_shape_card_t(3, 3);
	card_t size1910 = width_matrix_shape_t(Rx_shp);
	array_number_t stgVar1818 = storage_alloc(size1910);
	array_array_number_t macroDef1906;array_array_number_t macroDef1894 = (array_array_number_t)stgVar1818;
	macroDef1894->length=3;
	macroDef1894->arr=(array_number_t*)(STG_OFFSET(stgVar1818, VECTOR_HEADER_BYTES));
	int stgVar1818_offsetVar = 0;storage_t stgVar1819 = STG_OFFSET(stgVar1818, MATRIX_HEADER_BYTES(3) + stgVar1818_offsetVar);array_number_t macroDef1891 = (array_number_t)stgVar1819;
	macroDef1891->length=3;
	macroDef1891->arr=(number_t*)(STG_OFFSET(stgVar1819, VECTOR_HEADER_BYTES));
	

	macroDef1891->arr[0] = 1;;

	macroDef1891->arr[1] = 0;;

	macroDef1891->arr[2] = 0;;;

	macroDef1894->arr[0] = macroDef1891;;stgVar1818_offsetVar += VECTOR_ALL_BYTES(macroDef1894->arr[0]->length);storage_t stgVar1823 = STG_OFFSET(stgVar1818, MATRIX_HEADER_BYTES(3) + stgVar1818_offsetVar);array_number_t macroDef1892 = (array_number_t)stgVar1823;
	macroDef1892->length=3;
	macroDef1892->arr=(number_t*)(STG_OFFSET(stgVar1823, VECTOR_HEADER_BYTES));
	

	macroDef1892->arr[0] = 0;;

	macroDef1892->arr[1] = cos(tx_dps);;

	macroDef1892->arr[2] = -(sin(tx_dps));;;

	macroDef1894->arr[1] = macroDef1892;;stgVar1818_offsetVar += VECTOR_ALL_BYTES(macroDef1894->arr[1]->length);storage_t stgVar1827 = STG_OFFSET(stgVar1818, MATRIX_HEADER_BYTES(3) + stgVar1818_offsetVar);array_number_t macroDef1893 = (array_number_t)stgVar1827;
	macroDef1893->length=3;
	macroDef1893->arr=(number_t*)(STG_OFFSET(stgVar1827, VECTOR_HEADER_BYTES));
	

	macroDef1893->arr[0] = 0;;

	macroDef1893->arr[1] = sin(tx_dps);;

	macroDef1893->arr[2] = cos(tx_dps);;;

	macroDef1894->arr[2] = macroDef1893;;stgVar1818_offsetVar += VECTOR_ALL_BYTES(macroDef1894->arr[2]->length);;
	array_array_number_t Rx_dps = macroDef1894;
	matrix_shape_t Ry_shp = nested_shape_card_t(3, 3);
	card_t size1909 = width_matrix_shape_t(Ry_shp);
	array_number_t stgVar1831 = storage_alloc(size1909);
	array_array_number_t macroDef1905;array_array_number_t macroDef1898 = (array_array_number_t)stgVar1831;
	macroDef1898->length=3;
	macroDef1898->arr=(array_number_t*)(STG_OFFSET(stgVar1831, VECTOR_HEADER_BYTES));
	int stgVar1831_offsetVar = 0;storage_t stgVar1832 = STG_OFFSET(stgVar1831, MATRIX_HEADER_BYTES(3) + stgVar1831_offsetVar);array_number_t macroDef1895 = (array_number_t)stgVar1832;
	macroDef1895->length=3;
	macroDef1895->arr=(number_t*)(STG_OFFSET(stgVar1832, VECTOR_HEADER_BYTES));
	

	macroDef1895->arr[0] = cos(ty_dps);;

	macroDef1895->arr[1] = 0;;

	macroDef1895->arr[2] = sin(ty_dps);;;

	macroDef1898->arr[0] = macroDef1895;;stgVar1831_offsetVar += VECTOR_ALL_BYTES(macroDef1898->arr[0]->length);storage_t stgVar1836 = STG_OFFSET(stgVar1831, MATRIX_HEADER_BYTES(3) + stgVar1831_offsetVar);array_number_t macroDef1896 = (array_number_t)stgVar1836;
	macroDef1896->length=3;
	macroDef1896->arr=(number_t*)(STG_OFFSET(stgVar1836, VECTOR_HEADER_BYTES));
	

	macroDef1896->arr[0] = 0;;

	macroDef1896->arr[1] = 1;;

	macroDef1896->arr[2] = 0;;;

	macroDef1898->arr[1] = macroDef1896;;stgVar1831_offsetVar += VECTOR_ALL_BYTES(macroDef1898->arr[1]->length);storage_t stgVar1840 = STG_OFFSET(stgVar1831, MATRIX_HEADER_BYTES(3) + stgVar1831_offsetVar);array_number_t macroDef1897 = (array_number_t)stgVar1840;
	macroDef1897->length=3;
	macroDef1897->arr=(number_t*)(STG_OFFSET(stgVar1840, VECTOR_HEADER_BYTES));
	

	macroDef1897->arr[0] = -(sin(ty_dps));;

	macroDef1897->arr[1] = 0;;

	macroDef1897->arr[2] = cos(ty_dps);;;

	macroDef1898->arr[2] = macroDef1897;;stgVar1831_offsetVar += VECTOR_ALL_BYTES(macroDef1898->arr[2]->length);;
	array_array_number_t Ry_dps = macroDef1898;
	matrix_shape_t Rz_shp = nested_shape_card_t(3, 3);
	card_t size1908 = width_matrix_shape_t(Rz_shp);
	array_number_t stgVar1844 = storage_alloc(size1908);
	array_array_number_t macroDef1904;array_array_number_t macroDef1902 = (array_array_number_t)stgVar1844;
	macroDef1902->length=3;
	macroDef1902->arr=(array_number_t*)(STG_OFFSET(stgVar1844, VECTOR_HEADER_BYTES));
	int stgVar1844_offsetVar = 0;storage_t stgVar1845 = STG_OFFSET(stgVar1844, MATRIX_HEADER_BYTES(3) + stgVar1844_offsetVar);array_number_t macroDef1899 = (array_number_t)stgVar1845;
	macroDef1899->length=3;
	macroDef1899->arr=(number_t*)(STG_OFFSET(stgVar1845, VECTOR_HEADER_BYTES));
	

	macroDef1899->arr[0] = cos(tz_dps);;

	macroDef1899->arr[1] = -(sin(tz_dps));;

	macroDef1899->arr[2] = 0;;;

	macroDef1902->arr[0] = macroDef1899;;stgVar1844_offsetVar += VECTOR_ALL_BYTES(macroDef1902->arr[0]->length);storage_t stgVar1849 = STG_OFFSET(stgVar1844, MATRIX_HEADER_BYTES(3) + stgVar1844_offsetVar);array_number_t macroDef1900 = (array_number_t)stgVar1849;
	macroDef1900->length=3;
	macroDef1900->arr=(number_t*)(STG_OFFSET(stgVar1849, VECTOR_HEADER_BYTES));
	

	macroDef1900->arr[0] = sin(tz_dps);;

	macroDef1900->arr[1] = cos(tz_dps);;

	macroDef1900->arr[2] = 0;;;

	macroDef1902->arr[1] = macroDef1900;;stgVar1844_offsetVar += VECTOR_ALL_BYTES(macroDef1902->arr[1]->length);storage_t stgVar1853 = STG_OFFSET(stgVar1844, MATRIX_HEADER_BYTES(3) + stgVar1844_offsetVar);array_number_t macroDef1901 = (array_number_t)stgVar1853;
	macroDef1901->length=3;
	macroDef1901->arr=(number_t*)(STG_OFFSET(stgVar1853, VECTOR_HEADER_BYTES));
	

	macroDef1901->arr[0] = 0;;

	macroDef1901->arr[1] = 0;;

	macroDef1901->arr[2] = 1;;;

	macroDef1902->arr[2] = macroDef1901;;stgVar1844_offsetVar += VECTOR_ALL_BYTES(macroDef1902->arr[2]->length);;
	array_array_number_t Rz_dps = macroDef1902;
	card_t size1907 = width_matrix_shape_t(TOP_LEVEL_linalg_matrixMult_shp(Ry_shp, Rx_shp));
	array_number_t stgVar1858 = storage_alloc(size1907);
	array_array_number_t macroDef1903;
	macroDef1903 = TOP_LEVEL_linalg_matrixMult_dps(stgVar1811, Rz_dps, TOP_LEVEL_linalg_matrixMult_dps(stgVar1858, Ry_dps, Rx_dps, Ry_shp, Rx_shp), Rz_shp, TOP_LEVEL_linalg_matrixMult_shp(Ry_shp, Rx_shp));;
	storage_free(stgVar1858, size1907);
	macroDef1904 = macroDef1903;;
	storage_free(stgVar1844, size1908);
	macroDef1905 = macroDef1904;;
	storage_free(stgVar1831, size1909);
	macroDef1906 = macroDef1905;;
	storage_free(stgVar1818, size1910);
	return macroDef1906;
}

matrix_shape_t TOP_LEVEL_usecases_ht_make_relative_shp(card_t pose_params_shp, matrix_shape_t base_relative_shp) {
	
	return TOP_LEVEL_linalg_matrixMult_shp(base_relative_shp, TOP_LEVEL_linalg_matrixConcat_shp(TOP_LEVEL_linalg_matrixConcatCol_shp(TOP_LEVEL_usecases_ht_euler_angles_to_rotation_matrix_shp(pose_params_shp), nested_shape_card_t(1, 3)), nested_shape_card_t(4, 1)));
}


array_array_number_t TOP_LEVEL_usecases_ht_make_relative_dps(storage_t stgVar1911, array_number_t pose_params_dps, array_array_number_t base_relative_dps, card_t pose_params_shp, matrix_shape_t base_relative_shp) {
	matrix_shape_t R_shp = TOP_LEVEL_usecases_ht_euler_angles_to_rotation_matrix_shp(pose_params_shp);
	card_t size1961 = width_matrix_shape_t(R_shp);
	array_number_t stgVar1912 = storage_alloc(size1961);
	array_array_number_t macroDef1956;array_array_number_t R_dps = TOP_LEVEL_usecases_ht_euler_angles_to_rotation_matrix_dps(stgVar1912, pose_params_dps, pose_params_shp);
	matrix_shape_t r1_shp = nested_shape_card_t(1, 3);
	card_t size1960 = width_matrix_shape_t(r1_shp);
	array_number_t stgVar1914 = storage_alloc(size1960);
	array_array_number_t macroDef1955;array_array_number_t macroDef1949 = (array_array_number_t)stgVar1914;
	macroDef1949->length=3;
	macroDef1949->arr=(array_number_t*)(STG_OFFSET(stgVar1914, VECTOR_HEADER_BYTES));
	int stgVar1914_offsetVar = 0;storage_t stgVar1915 = STG_OFFSET(stgVar1914, MATRIX_HEADER_BYTES(3) + stgVar1914_offsetVar);array_number_t macroDef1946 = (array_number_t)stgVar1915;
	macroDef1946->length=1;
	macroDef1946->arr=(number_t*)(STG_OFFSET(stgVar1915, VECTOR_HEADER_BYTES));
	

	macroDef1946->arr[0] = 0;;;

	macroDef1949->arr[0] = macroDef1946;;stgVar1914_offsetVar += VECTOR_ALL_BYTES(macroDef1949->arr[0]->length);storage_t stgVar1917 = STG_OFFSET(stgVar1914, MATRIX_HEADER_BYTES(3) + stgVar1914_offsetVar);array_number_t macroDef1947 = (array_number_t)stgVar1917;
	macroDef1947->length=1;
	macroDef1947->arr=(number_t*)(STG_OFFSET(stgVar1917, VECTOR_HEADER_BYTES));
	

	macroDef1947->arr[0] = 0;;;

	macroDef1949->arr[1] = macroDef1947;;stgVar1914_offsetVar += VECTOR_ALL_BYTES(macroDef1949->arr[1]->length);storage_t stgVar1919 = STG_OFFSET(stgVar1914, MATRIX_HEADER_BYTES(3) + stgVar1914_offsetVar);array_number_t macroDef1948 = (array_number_t)stgVar1919;
	macroDef1948->length=1;
	macroDef1948->arr=(number_t*)(STG_OFFSET(stgVar1919, VECTOR_HEADER_BYTES));
	

	macroDef1948->arr[0] = 0;;;

	macroDef1949->arr[2] = macroDef1948;;stgVar1914_offsetVar += VECTOR_ALL_BYTES(macroDef1949->arr[2]->length);;
	array_array_number_t r1_dps = macroDef1949;
	matrix_shape_t r2_shp = nested_shape_card_t(4, 1);
	card_t size1959 = width_matrix_shape_t(r2_shp);
	array_number_t stgVar1921 = storage_alloc(size1959);
	array_array_number_t macroDef1954;array_array_number_t macroDef1951 = (array_array_number_t)stgVar1921;
	macroDef1951->length=1;
	macroDef1951->arr=(array_number_t*)(STG_OFFSET(stgVar1921, VECTOR_HEADER_BYTES));
	int stgVar1921_offsetVar = 0;storage_t stgVar1922 = STG_OFFSET(stgVar1921, MATRIX_HEADER_BYTES(1) + stgVar1921_offsetVar);array_number_t macroDef1950 = (array_number_t)stgVar1922;
	macroDef1950->length=4;
	macroDef1950->arr=(number_t*)(STG_OFFSET(stgVar1922, VECTOR_HEADER_BYTES));
	

	macroDef1950->arr[0] = 0;;

	macroDef1950->arr[1] = 0;;

	macroDef1950->arr[2] = 0;;

	macroDef1950->arr[3] = 1;;;

	macroDef1951->arr[0] = macroDef1950;;stgVar1921_offsetVar += VECTOR_ALL_BYTES(macroDef1951->arr[0]->length);;
	array_array_number_t r2_dps = macroDef1951;
	matrix_shape_t T_shp = TOP_LEVEL_linalg_matrixConcat_shp(TOP_LEVEL_linalg_matrixConcatCol_shp(R_shp, r1_shp), r2_shp);
	card_t size1958 = width_matrix_shape_t(T_shp);
	array_number_t stgVar1927 = storage_alloc(size1958);
	array_array_number_t macroDef1953;card_t size1957 = width_matrix_shape_t(TOP_LEVEL_linalg_matrixConcatCol_shp(R_shp, r1_shp));
	array_number_t stgVar1928 = storage_alloc(size1957);
	array_array_number_t macroDef1952;
	macroDef1952 = TOP_LEVEL_linalg_matrixConcat_dps(stgVar1927, TOP_LEVEL_linalg_matrixConcatCol_dps(stgVar1928, R_dps, r1_dps, R_shp, r1_shp), r2_dps, TOP_LEVEL_linalg_matrixConcatCol_shp(R_shp, r1_shp), r2_shp);;
	storage_free(stgVar1928, size1957);
	array_array_number_t T_dps = macroDef1952;
	macroDef1953 = TOP_LEVEL_linalg_matrixMult_dps(stgVar1911, base_relative_dps, T_dps, base_relative_shp, T_shp);;
	storage_free(stgVar1927, size1958);
	macroDef1954 = macroDef1953;;
	storage_free(stgVar1921, size1959);
	macroDef1955 = macroDef1954;;
	storage_free(stgVar1914, size1960);
	macroDef1956 = macroDef1955;;
	storage_free(stgVar1912, size1961);
	return macroDef1956;
}
typedef struct env_t_1978 {
	matrix_shape_t pose_params_shp;
	matrix3d_shape_t base_relatives_shp;
} env_t_1978;
env_t_1978 make_env_t_1978(matrix_shape_t pose_params_shp,matrix3d_shape_t base_relatives_shp) {
	env_t_1978 env;
	env.pose_params_shp = pose_params_shp;
	env.base_relatives_shp = base_relatives_shp;
	return env;
}

value_t lambda1978(env_t_1978* env1975, card_t i_bone_shp) {
	matrix_shape_t pose_params_shp1974 = env1975->pose_params_shp;
	matrix3d_shape_t base_relatives_shp1973 = env1975->base_relatives_shp;
	value_t res;
	res.matrix_shape_t_value = TOP_LEVEL_usecases_ht_make_relative_shp(pose_params_shp1974.elem, base_relatives_shp1973.elem);
	return res;
}
matrix3d_shape_t TOP_LEVEL_usecases_ht_get_posed_relatives_shp(card_t n_bones_shp, matrix_shape_t pose_params_shp, matrix3d_shape_t base_relatives_shp) {
	env_t_1978 env_t_1978_value = make_env_t_1978(pose_params_shp,base_relatives_shp); closure_t closure1977 = make_closure(lambda1978, &env_t_1978_value);
	return TOP_LEVEL_linalg_vectorMapToMatrix3D_shp(closure1977, TOP_LEVEL_linalg_vectorRange_shp(0, (n_bones_shp) - (1)));
}

typedef struct env_t_1995 {
	matrix_shape_t pose_params_shp;
	array_array_number_t pose_params_dps;
	index_t offset_dps;
	matrix3d_shape_t base_relatives_shp;
	array_array_array_number_t base_relatives_dps;
} env_t_1995;
env_t_1995 make_env_t_1995(matrix_shape_t pose_params_shp,array_array_number_t pose_params_dps,index_t offset_dps,matrix3d_shape_t base_relatives_shp,array_array_array_number_t base_relatives_dps) {
	env_t_1995 env;
	env.pose_params_shp = pose_params_shp;
	env.pose_params_dps = pose_params_dps;
	env.offset_dps = offset_dps;
	env.base_relatives_shp = base_relatives_shp;
	env.base_relatives_dps = base_relatives_dps;
	return env;
}

value_t lambda1995(env_t_1995* env1986, storage_t stgVar1966, number_t i_bone_dps, card_t i_bone_shp) {
	matrix_shape_t pose_params_shp1985 = env1986->pose_params_shp;
	array_array_number_t pose_params_dps1984 = env1986->pose_params_dps;
	index_t offset_dps1983 = env1986->offset_dps;
	matrix3d_shape_t base_relatives_shp1982 = env1986->base_relatives_shp;
	array_array_array_number_t base_relatives_dps1981 = env1986->base_relatives_dps;
	card_t size1997 = width_matrix_shape_t(base_relatives_shp1982.elem);
	array_number_t stgVar1968 = storage_alloc(size1997);
	array_array_number_t macroDef1980;card_t size1996 = width_card_t(pose_params_shp1985.elem);
	array_number_t stgVar1967 = storage_alloc(size1996);
	array_array_number_t macroDef1979;
	macroDef1979 = TOP_LEVEL_usecases_ht_make_relative_dps(stgVar1966, pose_params_dps1984->arr[((int)(i_bone_dps)) + (offset_dps1983)], base_relatives_dps1981->arr[(int)(i_bone_dps)], pose_params_shp1985.elem, base_relatives_shp1982.elem);;
	storage_free(stgVar1967, size1996);
	macroDef1980 = macroDef1979;;
	storage_free(stgVar1968, size1997);
	value_t res;
	res.array_array_number_t_value = macroDef1980;
	return res;
}
typedef struct env_t_1998 {
	matrix_shape_t pose_params_shp;
	matrix3d_shape_t base_relatives_shp;
} env_t_1998;
env_t_1998 make_env_t_1998(matrix_shape_t pose_params_shp,matrix3d_shape_t base_relatives_shp) {
	env_t_1998 env;
	env.pose_params_shp = pose_params_shp;
	env.base_relatives_shp = base_relatives_shp;
	return env;
}

value_t lambda1998(env_t_1998* env1991, card_t i_bone_shp) {
	matrix_shape_t pose_params_shp1990 = env1991->pose_params_shp;
	matrix3d_shape_t base_relatives_shp1989 = env1991->base_relatives_shp;
	value_t res;
	res.matrix_shape_t_value = TOP_LEVEL_usecases_ht_make_relative_shp(pose_params_shp1990.elem, base_relatives_shp1989.elem);
	return res;
}
array_array_array_number_t TOP_LEVEL_usecases_ht_get_posed_relatives_dps(storage_t stgVar1962, card_t n_bones_dps, array_array_number_t pose_params_dps, array_array_array_number_t base_relatives_dps, card_t n_bones_shp, matrix_shape_t pose_params_shp, matrix3d_shape_t base_relatives_shp) {
	card_t offset_shp = 0;
	index_t offset_dps = 3;
	card_t size1999 = width_card_t(TOP_LEVEL_linalg_vectorRange_shp(0, (n_bones_shp) - (1)));
	array_number_t stgVar1965 = storage_alloc(size1999);
	array_array_array_number_t macroDef1994;env_t_1995 env_t_1995_value = make_env_t_1995(pose_params_shp,pose_params_dps,offset_dps,base_relatives_shp,base_relatives_dps); closure_t closure1988 = make_closure(lambda1995, &env_t_1995_value);
	env_t_1998 env_t_1998_value = make_env_t_1998(pose_params_shp,base_relatives_shp); closure_t closure1993 = make_closure(lambda1998, &env_t_1998_value);
	macroDef1994 = TOP_LEVEL_linalg_vectorMapToMatrix3D_dps(stgVar1962, closure1988, TOP_LEVEL_linalg_vectorRange_dps(stgVar1965, 0, (n_bones_dps) - (1), 0, (n_bones_shp) - (1)), closure1993, TOP_LEVEL_linalg_vectorRange_shp(0, (n_bones_shp) - (1)));;
	storage_free(stgVar1965, size1999);
	return macroDef1994;
}

matrix_shape_t TOP_LEVEL_usecases_ht_angle_axis_to_rotation_matrix_shp(card_t angle_axis_shp) {
	
	return nested_shape_card_t(3, 3);
}


array_array_number_t TOP_LEVEL_usecases_ht_angle_axis_to_rotation_matrix_dps(storage_t stgVar2000, array_number_t angle_axis_dps, card_t angle_axis_shp) {
	card_t n_shp = 0;
	number_t n_dps = sqrt(TOP_LEVEL_linalg_sqnorm_dps(empty_storage, angle_axis_dps, angle_axis_shp));
	array_array_number_t ite2043 = 0;
	if((n_dps) < (0.0001)) {
		array_array_number_t macroDef2038 = (array_array_number_t)stgVar2000;
	macroDef2038->length=3;
	macroDef2038->arr=(array_number_t*)(STG_OFFSET(stgVar2000, VECTOR_HEADER_BYTES));
	int stgVar2000_offsetVar = 0;storage_t stgVar2003 = STG_OFFSET(stgVar2000, MATRIX_HEADER_BYTES(3) + stgVar2000_offsetVar);array_number_t macroDef2035 = (array_number_t)stgVar2003;
	macroDef2035->length=3;
	macroDef2035->arr=(number_t*)(STG_OFFSET(stgVar2003, VECTOR_HEADER_BYTES));
	

	macroDef2035->arr[0] = 1;;

	macroDef2035->arr[1] = 0;;

	macroDef2035->arr[2] = 0;;;

	macroDef2038->arr[0] = macroDef2035;;stgVar2000_offsetVar += VECTOR_ALL_BYTES(macroDef2038->arr[0]->length);storage_t stgVar2007 = STG_OFFSET(stgVar2000, MATRIX_HEADER_BYTES(3) + stgVar2000_offsetVar);array_number_t macroDef2036 = (array_number_t)stgVar2007;
	macroDef2036->length=3;
	macroDef2036->arr=(number_t*)(STG_OFFSET(stgVar2007, VECTOR_HEADER_BYTES));
	

	macroDef2036->arr[0] = 0;;

	macroDef2036->arr[1] = 1;;

	macroDef2036->arr[2] = 0;;;

	macroDef2038->arr[1] = macroDef2036;;stgVar2000_offsetVar += VECTOR_ALL_BYTES(macroDef2038->arr[1]->length);storage_t stgVar2011 = STG_OFFSET(stgVar2000, MATRIX_HEADER_BYTES(3) + stgVar2000_offsetVar);array_number_t macroDef2037 = (array_number_t)stgVar2011;
	macroDef2037->length=3;
	macroDef2037->arr=(number_t*)(STG_OFFSET(stgVar2011, VECTOR_HEADER_BYTES));
	

	macroDef2037->arr[0] = 0;;

	macroDef2037->arr[1] = 0;;

	macroDef2037->arr[2] = 1;;;

	macroDef2038->arr[2] = macroDef2037;;stgVar2000_offsetVar += VECTOR_ALL_BYTES(macroDef2038->arr[2]->length);;
		ite2043 = macroDef2038;;
	} else {
		card_t x_shp = 0;
		number_t x_dps = (angle_axis_dps->arr[0]) / (n_dps);
		card_t y_shp = 0;
		number_t y_dps = (angle_axis_dps->arr[1]) / (n_dps);
		card_t z_shp = 0;
		number_t z_dps = (angle_axis_dps->arr[2]) / (n_dps);
		card_t s_shp = 0;
		number_t s_dps = sin(n_dps);
		card_t c_shp = 0;
		number_t c_dps = cos(n_dps);
		array_array_number_t macroDef2042 = (array_array_number_t)stgVar2000;
	macroDef2042->length=3;
	macroDef2042->arr=(array_number_t*)(STG_OFFSET(stgVar2000, VECTOR_HEADER_BYTES));
	int stgVar2000_offsetVar = 0;storage_t stgVar2023 = STG_OFFSET(stgVar2000, MATRIX_HEADER_BYTES(3) + stgVar2000_offsetVar);array_number_t macroDef2039 = (array_number_t)stgVar2023;
	macroDef2039->length=3;
	macroDef2039->arr=(number_t*)(STG_OFFSET(stgVar2023, VECTOR_HEADER_BYTES));
	

	macroDef2039->arr[0] = ((x_dps) * (x_dps)) + (((1) - ((x_dps) * (x_dps))) * (c_dps));;

	macroDef2039->arr[1] = (((x_dps) * (y_dps)) * ((1) - (c_dps))) - ((z_dps) * (s_dps));;

	macroDef2039->arr[2] = (((x_dps) * (z_dps)) * ((1) - (c_dps))) + ((y_dps) * (s_dps));;;

	macroDef2042->arr[0] = macroDef2039;;stgVar2000_offsetVar += VECTOR_ALL_BYTES(macroDef2042->arr[0]->length);storage_t stgVar2027 = STG_OFFSET(stgVar2000, MATRIX_HEADER_BYTES(3) + stgVar2000_offsetVar);array_number_t macroDef2040 = (array_number_t)stgVar2027;
	macroDef2040->length=3;
	macroDef2040->arr=(number_t*)(STG_OFFSET(stgVar2027, VECTOR_HEADER_BYTES));
	

	macroDef2040->arr[0] = (((x_dps) * (y_dps)) * ((1) - (c_dps))) + ((z_dps) * (s_dps));;

	macroDef2040->arr[1] = ((y_dps) * (y_dps)) + (((1) - ((y_dps) * (y_dps))) * (c_dps));;

	macroDef2040->arr[2] = (((y_dps) * (z_dps)) * ((1) - (c_dps))) - ((x_dps) * (s_dps));;;

	macroDef2042->arr[1] = macroDef2040;;stgVar2000_offsetVar += VECTOR_ALL_BYTES(macroDef2042->arr[1]->length);storage_t stgVar2031 = STG_OFFSET(stgVar2000, MATRIX_HEADER_BYTES(3) + stgVar2000_offsetVar);array_number_t macroDef2041 = (array_number_t)stgVar2031;
	macroDef2041->length=3;
	macroDef2041->arr=(number_t*)(STG_OFFSET(stgVar2031, VECTOR_HEADER_BYTES));
	

	macroDef2041->arr[0] = (((x_dps) * (z_dps)) * ((1) - (c_dps))) - ((y_dps) * (s_dps));;

	macroDef2041->arr[1] = (((z_dps) * (y_dps)) * ((1) - (c_dps))) + ((x_dps) * (s_dps));;

	macroDef2041->arr[2] = ((z_dps) * (z_dps)) + (((1) - ((z_dps) * (z_dps))) * (c_dps));;;

	macroDef2042->arr[2] = macroDef2041;;stgVar2000_offsetVar += VECTOR_ALL_BYTES(macroDef2042->arr[2]->length);;
		ite2043 = macroDef2042;;
	}
	return ite2043;
}

matrix3d_shape_t TOP_LEVEL_usecases_ht_relatives_to_absolutes_shp(matrix3d_shape_t relatives_shp, card_t parents_shp) {
	
	return relatives_shp;
}


array_array_array_number_t TOP_LEVEL_usecases_ht_relatives_to_absolutes_dps(storage_t stgVar2044, array_array_array_number_t relatives_dps, array_number_t parents_dps, matrix3d_shape_t relatives_shp, card_t parents_shp) {
	matrix3d_shape_t init_shp = relatives_shp;
	array_array_array_number_t init_dps = relatives_dps;
	card_t anfvar2046_shp = (relatives_shp.card) - (1);
	card_t macroDef2071 = relatives_dps->length;
	card_t anfvar2046_dps = (macroDef2071) - (1);
	card_t anfvar2047_shp = 0;
	card_t anfvar2047_dps = 0;
	array_array_array_number_t macroDef2078 = init_dps;
	storage_t stgVar2051 = stgVar2044;
	for(int i_dps = anfvar2047_dps; i_dps <= anfvar2046_dps; i_dps++){
		array_array_array_number_t ite2079 = 0;
	if((parents_dps->arr[i_dps]) == (-1)) {
		matrix3d_shape_t newMatrix_shp = nested_shape_matrix_shape_t(relatives_shp.elem, 1);
		card_t size2080 = width_matrix3d_shape_t(newMatrix_shp);
	array_number_t stgVar2053 = storage_alloc(size2080);
	array_array_array_number_t macroDef2073;array_array_array_number_t macroDef2072 = (array_array_array_number_t)stgVar2053;
	macroDef2072->length=1;
	macroDef2072->arr=(array_array_number_t*)(STG_OFFSET(stgVar2053, VECTOR_HEADER_BYTES));
	int stgVar2053_offsetVar = 0;storage_t stgVar2054 = STG_OFFSET(stgVar2053, MATRIX_HEADER_BYTES(1) + stgVar2053_offsetVar);

	macroDef2072->arr[0] = relatives_dps->arr[i_dps];;stgVar2053_offsetVar += VECTOR_ALL_BYTES(macroDef2072->arr[0]->length);;
	array_array_array_number_t newMatrix_dps = macroDef2072;
	macroDef2073 = TOP_LEVEL_usecases_ht_matrix3DUpdate_dps(stgVar2051, macroDef2078, i_dps, (i_dps) + (1), newMatrix_dps, init_shp, 0, 0, newMatrix_shp);;
	storage_free(stgVar2053, size2080);
		ite2079 = macroDef2073;;
	} else {
		matrix3d_shape_t newMatrix_shp = nested_shape_matrix_shape_t(TOP_LEVEL_linalg_matrixMult_shp(init_shp.elem, relatives_shp.elem), 1);
		card_t size2083 = width_matrix3d_shape_t(newMatrix_shp);
	array_number_t stgVar2060 = storage_alloc(size2083);
	array_array_array_number_t macroDef2077;array_array_array_number_t macroDef2076 = (array_array_array_number_t)stgVar2060;
	macroDef2076->length=1;
	macroDef2076->arr=(array_array_number_t*)(STG_OFFSET(stgVar2060, VECTOR_HEADER_BYTES));
	int stgVar2060_offsetVar = 0;storage_t stgVar2061 = STG_OFFSET(stgVar2060, MATRIX_HEADER_BYTES(1) + stgVar2060_offsetVar);card_t size2082 = width_matrix_shape_t(relatives_shp.elem);
	array_number_t stgVar2063 = storage_alloc(size2082);
	array_array_number_t macroDef2075;card_t size2081 = width_matrix_shape_t(init_shp.elem);
	array_number_t stgVar2062 = storage_alloc(size2081);
	array_array_number_t macroDef2074;
	macroDef2074 = TOP_LEVEL_linalg_matrixMult_dps(stgVar2061, macroDef2078->arr[(int)(parents_dps->arr[i_dps])], relatives_dps->arr[i_dps], init_shp.elem, relatives_shp.elem);;
	storage_free(stgVar2062, size2081);
	macroDef2075 = macroDef2074;;
	storage_free(stgVar2063, size2082);

	macroDef2076->arr[0] = macroDef2075;;stgVar2060_offsetVar += VECTOR_ALL_BYTES(macroDef2076->arr[0]->length);;
	array_array_array_number_t newMatrix_dps = macroDef2076;
	macroDef2077 = TOP_LEVEL_usecases_ht_matrix3DUpdate_dps(stgVar2051, macroDef2078, i_dps, (i_dps) + (1), newMatrix_dps, init_shp, 0, 0, newMatrix_shp);;
	storage_free(stgVar2060, size2083);
		ite2079 = macroDef2077;;
	}
		macroDef2078 = ite2079;;
	}
	return macroDef2078;
}
typedef struct env_t_2153 {
	matrix_shape_t pose_params_shp;
} env_t_2153;
env_t_2153 make_env_t_2153(matrix_shape_t pose_params_shp) {
	env_t_2153 env;
	env.pose_params_shp = pose_params_shp;
	return env;
}

value_t lambda2153(env_t_2153* env2147, card_t row_shp) {
	matrix_shape_t pose_params_shp2146 = env2147->pose_params_shp;
	value_t res;
	res.card_t_value = TOP_LEVEL_linalg_mult_vec_elementwise_shp(row_shp, pose_params_shp2146.elem);
	return res;
}
typedef empty_env_t env_t_2154;


value_t lambda2154(env_t_2154* env2150, card_t x_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
matrix_shape_t TOP_LEVEL_usecases_ht_apply_global_transform_shp(matrix_shape_t pose_params_shp, matrix_shape_t positions_shp) {
	env_t_2153 env_t_2153_value = make_env_t_2153(pose_params_shp); closure_t closure2149 = make_closure(lambda2153, &env_t_2153_value);
	env_t_2154 env_t_2154_value = make_empty_env(); closure_t closure2152 = make_closure(lambda2154, &env_t_2154_value);
	return TOP_LEVEL_linalg_matrixMult_shp(TOP_LEVEL_linalg_matrixConcatCol_shp(TOP_LEVEL_linalg_matrixMap_shp(closure2149, TOP_LEVEL_usecases_ht_angle_axis_to_rotation_matrix_shp(pose_params_shp.elem)), TOP_LEVEL_linalg_matrixTranspose_shp(nested_shape_card_t(pose_params_shp.elem, 1))), TOP_LEVEL_linalg_matrixConcat_shp(positions_shp, nested_shape_card_t(TOP_LEVEL_linalg_vectorMap_shp(closure2152, TOP_LEVEL_linalg_vectorRange_shp(1, positions_shp.elem)), 1)));
}

typedef struct env_t_2193 {
	card_t scale_shp;
} env_t_2193;
env_t_2193 make_env_t_2193(card_t scale_shp) {
	env_t_2193 env;
	env.scale_shp = scale_shp;
	return env;
}

value_t lambda2193(env_t_2193* env2157, card_t row_shp) {
	card_t scale_shp2156 = env2157->scale_shp;
	value_t res;
	res.card_t_value = TOP_LEVEL_linalg_mult_vec_elementwise_shp(row_shp, scale_shp2156);
	return res;
}
typedef struct env_t_2194 {
	card_t scale_shp;
	array_number_t scale_dps;
} env_t_2194;
env_t_2194 make_env_t_2194(card_t scale_shp,array_number_t scale_dps) {
	env_t_2194 env;
	env.scale_shp = scale_shp;
	env.scale_dps = scale_dps;
	return env;
}

value_t lambda2194(env_t_2194* env2162, storage_t stgVar2093, array_number_t row_dps, card_t row_shp) {
	card_t scale_shp2161 = env2162->scale_shp;
	array_number_t scale_dps2160 = env2162->scale_dps;
	value_t res;
	res.array_number_t_value = TOP_LEVEL_linalg_mult_vec_elementwise_dps(stgVar2093, row_dps, scale_dps2160, row_shp, scale_shp2161);
	return res;
}
typedef struct env_t_2195 {
	card_t scale_shp;
} env_t_2195;
env_t_2195 make_env_t_2195(card_t scale_shp) {
	env_t_2195 env;
	env.scale_shp = scale_shp;
	return env;
}

value_t lambda2195(env_t_2195* env2166, card_t row_shp) {
	card_t scale_shp2165 = env2166->scale_shp;
	value_t res;
	res.card_t_value = TOP_LEVEL_linalg_mult_vec_elementwise_shp(row_shp, scale_shp2165);
	return res;
}
typedef empty_env_t env_t_2198;


value_t lambda2198(env_t_2198* env2172, card_t x_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef empty_env_t env_t_2199;


value_t lambda2199(env_t_2199* env2175, storage_t stgVar2105, number_t x_dps, card_t x_shp) {
	
	value_t res;
	res.number_t_value = 1;
	return res;
}
typedef empty_env_t env_t_2201;


value_t lambda2201(env_t_2201* env2180, card_t x_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
array_array_number_t TOP_LEVEL_usecases_ht_apply_global_transform_dps(storage_t stgVar2084, array_array_number_t pose_params_dps, array_array_number_t positions_dps, matrix_shape_t pose_params_shp, matrix_shape_t positions_shp) {
	matrix_shape_t R_shp = TOP_LEVEL_usecases_ht_angle_axis_to_rotation_matrix_shp(pose_params_shp.elem);
	card_t size2209 = width_matrix_shape_t(R_shp);
	array_number_t stgVar2085 = storage_alloc(size2209);
	array_array_number_t macroDef2191;card_t size2192 = width_card_t(pose_params_shp.elem);
	array_number_t stgVar2086 = storage_alloc(size2192);
	array_array_number_t macroDef2155;
	macroDef2155 = TOP_LEVEL_usecases_ht_angle_axis_to_rotation_matrix_dps(stgVar2085, pose_params_dps->arr[0], pose_params_shp.elem);;
	storage_free(stgVar2086, size2192);
	array_array_number_t R_dps = macroDef2155;
	card_t scale_shp = pose_params_shp.elem;
	card_t size2208 = width_card_t(scale_shp);
	array_number_t stgVar2088 = storage_alloc(size2208);
	array_array_number_t macroDef2190;array_number_t scale_dps = pose_params_dps->arr[1];
	env_t_2193 env_t_2193_value = make_env_t_2193(scale_shp); closure_t closure2159 = make_closure(lambda2193, &env_t_2193_value);
	matrix_shape_t R1_shp = TOP_LEVEL_linalg_matrixMap_shp(closure2159, R_shp);
	card_t size2207 = width_matrix_shape_t(R1_shp);
	array_number_t stgVar2090 = storage_alloc(size2207);
	array_array_number_t macroDef2189;env_t_2194 env_t_2194_value = make_env_t_2194(scale_shp,scale_dps); closure_t closure2164 = make_closure(lambda2194, &env_t_2194_value);
	env_t_2195 env_t_2195_value = make_env_t_2195(scale_shp); closure_t closure2168 = make_closure(lambda2195, &env_t_2195_value);
	array_array_number_t R1_dps = TOP_LEVEL_linalg_matrixMap_dps(stgVar2090, closure2164, R_dps, closure2168, R_shp);
	matrix_shape_t T_shp = TOP_LEVEL_linalg_matrixConcatCol_shp(R1_shp, TOP_LEVEL_linalg_matrixTranspose_shp(nested_shape_card_t(pose_params_shp.elem, 1)));
	card_t size2206 = width_matrix_shape_t(T_shp);
	array_number_t stgVar2096 = storage_alloc(size2206);
	array_array_number_t macroDef2188;card_t size2197 = width_matrix_shape_t(TOP_LEVEL_linalg_matrixTranspose_shp(nested_shape_card_t(pose_params_shp.elem, 1)));
	array_number_t stgVar2098 = storage_alloc(size2197);
	array_array_number_t macroDef2171;card_t size2196 = width_matrix_shape_t(nested_shape_card_t(pose_params_shp.elem, 1));
	array_number_t stgVar2099 = storage_alloc(size2196);
	array_array_number_t macroDef2170;array_array_number_t macroDef2169 = (array_array_number_t)stgVar2099;
	macroDef2169->length=1;
	macroDef2169->arr=(array_number_t*)(STG_OFFSET(stgVar2099, VECTOR_HEADER_BYTES));
	int stgVar2099_offsetVar = 0;storage_t stgVar2100 = STG_OFFSET(stgVar2099, MATRIX_HEADER_BYTES(1) + stgVar2099_offsetVar);

	macroDef2169->arr[0] = pose_params_dps->arr[2];;stgVar2099_offsetVar += VECTOR_ALL_BYTES(macroDef2169->arr[0]->length);;
	macroDef2170 = TOP_LEVEL_linalg_matrixTranspose_dps(stgVar2098, macroDef2169, nested_shape_card_t(pose_params_shp.elem, 1));;
	storage_free(stgVar2099, size2196);
	macroDef2171 = TOP_LEVEL_linalg_matrixConcatCol_dps(stgVar2096, R1_dps, macroDef2170, R1_shp, TOP_LEVEL_linalg_matrixTranspose_shp(nested_shape_card_t(pose_params_shp.elem, 1)));;
	storage_free(stgVar2098, size2197);
	array_array_number_t T_dps = macroDef2171;
	env_t_2198 env_t_2198_value = make_empty_env(); closure_t closure2174 = make_closure(lambda2198, &env_t_2198_value);
	card_t ones_shp = TOP_LEVEL_linalg_vectorMap_shp(closure2174, TOP_LEVEL_linalg_vectorRange_shp(1, positions_shp.elem));
	card_t size2205 = width_card_t(ones_shp);
	array_number_t stgVar2102 = storage_alloc(size2205);
	array_array_number_t macroDef2187;card_t size2202 = width_card_t(TOP_LEVEL_linalg_vectorRange_shp(1, positions_shp.elem));
	array_number_t stgVar2104 = storage_alloc(size2202);
	array_number_t macroDef2183;env_t_2199 env_t_2199_value = make_empty_env(); closure_t closure2177 = make_closure(lambda2199, &env_t_2199_value);
	card_t size2200 = width_card_t(positions_shp.elem);
	array_number_t stgVar2108 = storage_alloc(size2200);
	card_t macroDef2179;card_t macroDef2178 = positions_dps->arr[0]->length;
	macroDef2179 = macroDef2178;;
	storage_free(stgVar2108, size2200);
	env_t_2201 env_t_2201_value = make_empty_env(); closure_t closure2182 = make_closure(lambda2201, &env_t_2201_value);
	macroDef2183 = TOP_LEVEL_linalg_vectorMap_dps(stgVar2102, closure2177, TOP_LEVEL_linalg_vectorRange_dps(stgVar2104, 1, macroDef2179, 1, positions_shp.elem), closure2182, TOP_LEVEL_linalg_vectorRange_shp(1, positions_shp.elem));;
	storage_free(stgVar2104, size2202);
	array_number_t ones_dps = macroDef2183;
	matrix_shape_t positions_homog_shp = TOP_LEVEL_linalg_matrixConcat_shp(positions_shp, nested_shape_card_t(ones_shp, 1));
	card_t size2204 = width_matrix_shape_t(positions_homog_shp);
	array_number_t stgVar2110 = storage_alloc(size2204);
	array_array_number_t macroDef2186;card_t size2203 = width_matrix_shape_t(nested_shape_card_t(ones_shp, 1));
	array_number_t stgVar2112 = storage_alloc(size2203);
	array_array_number_t macroDef2185;array_array_number_t macroDef2184 = (array_array_number_t)stgVar2112;
	macroDef2184->length=1;
	macroDef2184->arr=(array_number_t*)(STG_OFFSET(stgVar2112, VECTOR_HEADER_BYTES));
	int stgVar2112_offsetVar = 0;storage_t stgVar2113 = STG_OFFSET(stgVar2112, MATRIX_HEADER_BYTES(1) + stgVar2112_offsetVar);

	macroDef2184->arr[0] = ones_dps;;stgVar2112_offsetVar += VECTOR_ALL_BYTES(macroDef2184->arr[0]->length);;
	macroDef2185 = TOP_LEVEL_linalg_matrixConcat_dps(stgVar2110, positions_dps, macroDef2184, positions_shp, nested_shape_card_t(ones_shp, 1));;
	storage_free(stgVar2112, size2203);
	array_array_number_t positions_homog_dps = macroDef2185;
	macroDef2186 = TOP_LEVEL_linalg_matrixMult_dps(stgVar2084, T_dps, positions_homog_dps, T_shp, positions_homog_shp);;
	storage_free(stgVar2110, size2204);
	macroDef2187 = macroDef2186;;
	storage_free(stgVar2102, size2205);
	macroDef2188 = macroDef2187;;
	storage_free(stgVar2096, size2206);
	macroDef2189 = macroDef2188;;
	storage_free(stgVar2090, size2207);
	macroDef2190 = macroDef2189;;
	storage_free(stgVar2088, size2208);
	macroDef2191 = macroDef2190;;
	storage_free(stgVar2085, size2209);
	return macroDef2191;
}

matrix_shape_t TOP_LEVEL_usecases_ht_get_skinned_vertex_positions_shp(card_t is_mirrored_shp, card_t n_bones_shp, matrix_shape_t pose_params_shp, matrix3d_shape_t base_relatives_shp, card_t parents_shp, matrix3d_shape_t inverse_base_absolutes_shp, matrix_shape_t base_positions_shp, matrix_shape_t weights_shp) {
	
	return TOP_LEVEL_usecases_ht_apply_global_transform_shp(pose_params_shp, TOP_LEVEL_linalg_matrixMult_shp(nested_shape_card_t(3, 3), TOP_LEVEL_linalg_matrixFill_shp(3, base_positions_shp.elem, 0)));
}

typedef empty_env_t env_t_2358;


value_t lambda2358(env_t_2358* env2327, matrix_shape_t m1_shp, matrix_shape_t m2_shp) {
	
	value_t res;
	res.matrix_shape_t_value = TOP_LEVEL_linalg_matrixMult_shp(m1_shp, m2_shp);
	return res;
}
typedef empty_env_t env_t_2359;


value_t lambda2359(env_t_2359* env2330, storage_t stgVar2222, array_array_number_t m1_dps, array_array_number_t m2_dps, matrix_shape_t m1_shp, matrix_shape_t m2_shp) {
	
	value_t res;
	res.array_array_number_t_value = TOP_LEVEL_linalg_matrixMult_dps(stgVar2222, m1_dps, m2_dps, m1_shp, m2_shp);
	return res;
}
typedef empty_env_t env_t_2360;


value_t lambda2360(env_t_2360* env2333, matrix_shape_t m1_shp, matrix_shape_t m2_shp) {
	
	value_t res;
	res.matrix_shape_t_value = TOP_LEVEL_linalg_matrixMult_shp(m1_shp, m2_shp);
	return res;
}
array_array_number_t TOP_LEVEL_usecases_ht_get_skinned_vertex_positions_dps(storage_t stgVar2210, index_t is_mirrored_dps, card_t n_bones_dps, array_array_number_t pose_params_dps, array_array_array_number_t base_relatives_dps, array_number_t parents_dps, array_array_array_number_t inverse_base_absolutes_dps, array_array_number_t base_positions_dps, array_array_number_t weights_dps, card_t is_mirrored_shp, card_t n_bones_shp, matrix_shape_t pose_params_shp, matrix3d_shape_t base_relatives_shp, card_t parents_shp, matrix3d_shape_t inverse_base_absolutes_shp, matrix_shape_t base_positions_shp, matrix_shape_t weights_shp) {
	matrix3d_shape_t relatives_shp = TOP_LEVEL_usecases_ht_get_posed_relatives_shp(n_bones_shp, pose_params_shp, base_relatives_shp);
	card_t size2374 = width_matrix3d_shape_t(relatives_shp);
	array_number_t stgVar2211 = storage_alloc(size2374);
	array_array_number_t macroDef2357;array_array_array_number_t relatives_dps = TOP_LEVEL_usecases_ht_get_posed_relatives_dps(stgVar2211, n_bones_dps, pose_params_dps, base_relatives_dps, n_bones_shp, pose_params_shp, base_relatives_shp);
	matrix3d_shape_t absolutes_shp = TOP_LEVEL_usecases_ht_relatives_to_absolutes_shp(relatives_shp, parents_shp);
	card_t size2373 = width_matrix3d_shape_t(absolutes_shp);
	array_number_t stgVar2215 = storage_alloc(size2373);
	array_array_number_t macroDef2356;array_array_array_number_t absolutes_dps = TOP_LEVEL_usecases_ht_relatives_to_absolutes_dps(stgVar2215, relatives_dps, parents_dps, relatives_shp, parents_shp);
	env_t_2358 env_t_2358_value = make_empty_env(); closure_t closure2329 = make_closure(lambda2358, &env_t_2358_value);
	matrix3d_shape_t transforms_shp = TOP_LEVEL_linalg_matrix3DMap2_shp(closure2329, absolutes_shp, inverse_base_absolutes_shp);
	card_t size2372 = width_matrix3d_shape_t(transforms_shp);
	array_number_t stgVar2218 = storage_alloc(size2372);
	array_array_number_t macroDef2355;env_t_2359 env_t_2359_value = make_empty_env(); closure_t closure2332 = make_closure(lambda2359, &env_t_2359_value);
	env_t_2360 env_t_2360_value = make_empty_env(); closure_t closure2335 = make_closure(lambda2360, &env_t_2360_value);
	array_array_array_number_t transforms_dps = TOP_LEVEL_linalg_matrix3DMap2_dps(stgVar2218, closure2332, absolutes_dps, inverse_base_absolutes_dps, closure2335, absolutes_shp, inverse_base_absolutes_shp);
	card_t n_verts_shp = base_positions_shp.elem;
	card_t size2361 = width_card_t(base_positions_shp.elem);
	array_number_t stgVar2226 = storage_alloc(size2361);
	card_t macroDef2337;card_t macroDef2336 = base_positions_dps->arr[0]->length;
	macroDef2337 = macroDef2336;;
	storage_free(stgVar2226, size2361);
	card_t n_verts_dps = macroDef2337;
	matrix_shape_t init_positions_shp = TOP_LEVEL_linalg_matrixFill_shp(3, n_verts_shp, 0);
	card_t size2371 = width_matrix_shape_t(init_positions_shp);
	array_number_t stgVar2228 = storage_alloc(size2371);
	array_array_number_t macroDef2354;array_array_number_t init_positions_dps = TOP_LEVEL_linalg_matrixFill_dps(stgVar2228, 3, n_verts_dps, 0, 3, n_verts_shp, 0);
	matrix_shape_t positions_shp = init_positions_shp;
	card_t size2370 = width_matrix_shape_t(positions_shp);
	array_number_t stgVar2232 = storage_alloc(size2370);
	array_array_number_t macroDef2353;card_t anfvar2233_shp = (transforms_shp.card) - (1);
	card_t macroDef2338 = transforms_dps->length;
	card_t anfvar2233_dps = (macroDef2338) - (1);
	card_t anfvar2234_shp = 0;
	card_t anfvar2234_dps = 0;
	array_array_number_t macroDef2346 = init_positions_dps;
	storage_t stgVar2238 = stgVar2232;
	for(int i_transform_dps = anfvar2234_dps; i_transform_dps <= anfvar2233_dps; i_transform_dps++){
		matrix_shape_t curr_positions_shp = TOP_LEVEL_linalg_matrixMult_shp(TOP_LEVEL_linalg_matrixSlice_shp(3, 0, transforms_shp.elem), base_positions_shp);
		card_t size2367 = width_matrix_shape_t(curr_positions_shp);
	array_number_t stgVar2239 = storage_alloc(size2367);
	array_array_number_t macroDef2345;card_t size2363 = width_matrix_shape_t(TOP_LEVEL_linalg_matrixSlice_shp(3, 0, transforms_shp.elem));
	array_number_t stgVar2240 = storage_alloc(size2363);
	array_array_number_t macroDef2340;card_t size2362 = width_matrix_shape_t(transforms_shp.elem);
	array_number_t stgVar2244 = storage_alloc(size2362);
	array_array_number_t macroDef2339;
	macroDef2339 = TOP_LEVEL_linalg_matrixSlice_dps(stgVar2240, 3, 0, transforms_dps->arr[i_transform_dps], 3, 0, transforms_shp.elem);;
	storage_free(stgVar2244, size2362);
	macroDef2340 = TOP_LEVEL_linalg_matrixMult_dps(stgVar2239, macroDef2339, base_positions_dps, TOP_LEVEL_linalg_matrixSlice_shp(3, 0, transforms_shp.elem), base_positions_shp);;
	storage_free(stgVar2240, size2363);
	array_array_number_t curr_positions_dps = macroDef2340;
	matrix_shape_t w_shp = TOP_LEVEL_linalg_matrixFillFromVector_shp(base_positions_shp.card, weights_shp.elem);
	card_t size2366 = width_matrix_shape_t(w_shp);
	array_number_t stgVar2246 = storage_alloc(size2366);
	array_array_number_t macroDef2344;card_t size2364 = width_card_t(weights_shp.elem);
	array_number_t stgVar2248 = storage_alloc(size2364);
	array_array_number_t macroDef2342;card_t macroDef2341 = base_positions_dps->length;
	macroDef2342 = TOP_LEVEL_linalg_matrixFillFromVector_dps(stgVar2246, macroDef2341, weights_dps->arr[i_transform_dps], base_positions_shp.card, weights_shp.elem);;
	storage_free(stgVar2248, size2364);
	array_array_number_t w_dps = macroDef2342;
	card_t size2365 = width_matrix_shape_t(TOP_LEVEL_linalg_matrixMultElementwise_shp(curr_positions_shp, w_shp));
	array_number_t stgVar2252 = storage_alloc(size2365);
	array_array_number_t macroDef2343;
	macroDef2343 = TOP_LEVEL_linalg_matrixAdd_dps(stgVar2238, macroDef2346, TOP_LEVEL_linalg_matrixMultElementwise_dps(stgVar2252, curr_positions_dps, w_dps, curr_positions_shp, w_shp), init_positions_shp, TOP_LEVEL_linalg_matrixMultElementwise_shp(curr_positions_shp, w_shp));;
	storage_free(stgVar2252, size2365);
	macroDef2344 = macroDef2343;;
	storage_free(stgVar2246, size2366);
	macroDef2345 = macroDef2344;;
	storage_free(stgVar2239, size2367);
		macroDef2346 = macroDef2345;;
	}
	array_array_number_t positions_dps = macroDef2346;
	matrix_shape_t mirror_matrix_shp = nested_shape_card_t(3, 3);
	matrix_shape_t mirrored_positions_shp = TOP_LEVEL_linalg_matrixMult_shp(mirror_matrix_shp, positions_shp);
	card_t size2369 = width_matrix_shape_t(mirrored_positions_shp);
	array_number_t stgVar2255 = storage_alloc(size2369);
	array_array_number_t macroDef2352;array_array_number_t mirrored_positions_dps = 0;
	if((is_mirrored_dps) == (1)) {
		matrix_shape_t mirror_matrix_shp0 = nested_shape_card_t(3, 3);
		card_t size2368 = width_matrix_shape_t(mirror_matrix_shp0);
	array_number_t stgVar2256 = storage_alloc(size2368);
	array_array_number_t macroDef2351;array_array_number_t macroDef2350 = (array_array_number_t)stgVar2256;
	macroDef2350->length=3;
	macroDef2350->arr=(array_number_t*)(STG_OFFSET(stgVar2256, VECTOR_HEADER_BYTES));
	int stgVar2256_offsetVar = 0;storage_t stgVar2257 = STG_OFFSET(stgVar2256, MATRIX_HEADER_BYTES(3) + stgVar2256_offsetVar);array_number_t macroDef2347 = (array_number_t)stgVar2257;
	macroDef2347->length=3;
	macroDef2347->arr=(number_t*)(STG_OFFSET(stgVar2257, VECTOR_HEADER_BYTES));
	

	macroDef2347->arr[0] = -1;;

	macroDef2347->arr[1] = 0;;

	macroDef2347->arr[2] = 0;;;

	macroDef2350->arr[0] = macroDef2347;;stgVar2256_offsetVar += VECTOR_ALL_BYTES(macroDef2350->arr[0]->length);storage_t stgVar2261 = STG_OFFSET(stgVar2256, MATRIX_HEADER_BYTES(3) + stgVar2256_offsetVar);array_number_t macroDef2348 = (array_number_t)stgVar2261;
	macroDef2348->length=3;
	macroDef2348->arr=(number_t*)(STG_OFFSET(stgVar2261, VECTOR_HEADER_BYTES));
	

	macroDef2348->arr[0] = 0;;

	macroDef2348->arr[1] = 1;;

	macroDef2348->arr[2] = 0;;;

	macroDef2350->arr[1] = macroDef2348;;stgVar2256_offsetVar += VECTOR_ALL_BYTES(macroDef2350->arr[1]->length);storage_t stgVar2265 = STG_OFFSET(stgVar2256, MATRIX_HEADER_BYTES(3) + stgVar2256_offsetVar);array_number_t macroDef2349 = (array_number_t)stgVar2265;
	macroDef2349->length=3;
	macroDef2349->arr=(number_t*)(STG_OFFSET(stgVar2265, VECTOR_HEADER_BYTES));
	

	macroDef2349->arr[0] = 0;;

	macroDef2349->arr[1] = 0;;

	macroDef2349->arr[2] = 1;;;

	macroDef2350->arr[2] = macroDef2349;;stgVar2256_offsetVar += VECTOR_ALL_BYTES(macroDef2350->arr[2]->length);;
	array_array_number_t mirror_matrix_dps = macroDef2350;
	macroDef2351 = TOP_LEVEL_linalg_matrixMult_dps(stgVar2255, mirror_matrix_dps, positions_dps, mirror_matrix_shp0, positions_shp);;
	storage_free(stgVar2256, size2368);
		mirrored_positions_dps = macroDef2351;;
	} else {
		
		mirrored_positions_dps = positions_dps;;
	}
	macroDef2352 = TOP_LEVEL_usecases_ht_apply_global_transform_dps(stgVar2210, pose_params_dps, mirrored_positions_dps, pose_params_shp, mirrored_positions_shp);;
	storage_free(stgVar2255, size2369);
	macroDef2353 = macroDef2352;;
	storage_free(stgVar2232, size2370);
	macroDef2354 = macroDef2353;;
	storage_free(stgVar2228, size2371);
	macroDef2355 = macroDef2354;;
	storage_free(stgVar2218, size2372);
	macroDef2356 = macroDef2355;;
	storage_free(stgVar2215, size2373);
	macroDef2357 = macroDef2356;;
	storage_free(stgVar2211, size2374);
	return macroDef2357;
}
typedef empty_env_t env_t_2428;


value_t lambda2428(env_t_2428* env2425, card_t i_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
card_t TOP_LEVEL_usecases_ht_hand_objective_shp(card_t is_mirrored_shp, card_t param_shp, card_t correspondences_shp, matrix_shape_t points_shp, card_t n_bones_shp, matrix3d_shape_t base_relatives_shp, card_t parents_shp, matrix3d_shape_t inverse_base_absolutes_shp, matrix_shape_t base_positions_shp, matrix_shape_t weights_shp) {
	env_t_2428 env_t_2428_value = make_empty_env(); closure_t closure2427 = make_closure(lambda2428, &env_t_2428_value);
	return TOP_LEVEL_linalg_vectorMap_shp(closure2427, TOP_LEVEL_linalg_vectorRange_shp(0, (((correspondences_shp) + (correspondences_shp)) + (correspondences_shp)) - (1)));
}

typedef empty_env_t env_t_2451;


value_t lambda2451(env_t_2451* env2430, card_t i_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef struct env_t_2452 {
	matrix_shape_t vertex_positions_shp;
	array_array_number_t vertex_positions_dps;
	matrix_shape_t points_shp;
	array_array_number_t points_dps;
	index_t n_corr_dps;
	array_number_t correspondences_dps;
} env_t_2452;
env_t_2452 make_env_t_2452(matrix_shape_t vertex_positions_shp,array_array_number_t vertex_positions_dps,matrix_shape_t points_shp,array_array_number_t points_dps,index_t n_corr_dps,array_number_t correspondences_dps) {
	env_t_2452 env;
	env.vertex_positions_shp = vertex_positions_shp;
	env.vertex_positions_dps = vertex_positions_dps;
	env.points_shp = points_shp;
	env.points_dps = points_dps;
	env.n_corr_dps = n_corr_dps;
	env.correspondences_dps = correspondences_dps;
	return env;
}

value_t lambda2452(env_t_2452* env2441, storage_t stgVar2394, number_t i_dps, card_t i_shp) {
	matrix_shape_t vertex_positions_shp2440 = env2441->vertex_positions_shp;
	array_array_number_t vertex_positions_dps2439 = env2441->vertex_positions_dps;
	matrix_shape_t points_shp2438 = env2441->points_shp;
	array_array_number_t points_dps2437 = env2441->points_dps;
	index_t n_corr_dps2436 = env2441->n_corr_dps;
	array_number_t correspondences_dps2435 = env2441->correspondences_dps;
	card_t ind_shp = 0;
	index_t ind_dps = (int)(i_dps);
	card_t r_shp = 0;
	index_t r_dps = (ind_dps) / (n_corr_dps2436);
	card_t c_shp = 0;
	index_t c_dps = (ind_dps) % (n_corr_dps2436);
	card_t size2453 = width_card_t(points_shp2438.elem);
	array_number_t stgVar2398 = storage_alloc(size2453);
	number_t macroDef2433;
	macroDef2433 = points_dps2437->arr[r_dps]->arr[c_dps];;
	storage_free(stgVar2398, size2453);
	card_t size2454 = width_card_t(vertex_positions_shp2440.elem);
	array_number_t stgVar2400 = storage_alloc(size2454);
	number_t macroDef2434;
	macroDef2434 = vertex_positions_dps2439->arr[r_dps]->arr[(int)(correspondences_dps2435->arr[c_dps])];;
	storage_free(stgVar2400, size2454);
	value_t res;
	res.number_t_value = (macroDef2433) - (macroDef2434);
	return res;
}
typedef empty_env_t env_t_2455;


value_t lambda2455(env_t_2455* env2444, card_t i_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
array_number_t TOP_LEVEL_usecases_ht_hand_objective_dps(storage_t stgVar2375, index_t is_mirrored_dps, array_number_t param_dps, array_number_t correspondences_dps, array_array_number_t points_dps, card_t n_bones_dps, array_array_array_number_t base_relatives_dps, array_number_t parents_dps, array_array_array_number_t inverse_base_absolutes_dps, array_array_number_t base_positions_dps, array_array_number_t weights_dps, card_t is_mirrored_shp, card_t param_shp, card_t correspondences_shp, matrix_shape_t points_shp, card_t n_bones_shp, matrix3d_shape_t base_relatives_shp, card_t parents_shp, matrix3d_shape_t inverse_base_absolutes_shp, matrix_shape_t base_positions_shp, matrix_shape_t weights_shp) {
	matrix_shape_t pose_params_shp = TOP_LEVEL_usecases_ht_to_pose_params_shp(param_shp, n_bones_shp);
	card_t size2459 = width_matrix_shape_t(pose_params_shp);
	array_number_t stgVar2376 = storage_alloc(size2459);
	array_number_t macroDef2450;array_array_number_t pose_params_dps = TOP_LEVEL_usecases_ht_to_pose_params_dps(stgVar2376, param_dps, n_bones_dps, param_shp, n_bones_shp);
	matrix_shape_t vertex_positions_shp = TOP_LEVEL_usecases_ht_get_skinned_vertex_positions_shp(0, n_bones_shp, pose_params_shp, base_relatives_shp, parents_shp, inverse_base_absolutes_shp, base_positions_shp, weights_shp);
	card_t size2458 = width_matrix_shape_t(vertex_positions_shp);
	array_number_t stgVar2379 = storage_alloc(size2458);
	array_number_t macroDef2449;array_array_number_t vertex_positions_dps = TOP_LEVEL_usecases_ht_get_skinned_vertex_positions_dps(stgVar2379, is_mirrored_dps, n_bones_dps, pose_params_dps, base_relatives_dps, parents_dps, inverse_base_absolutes_dps, base_positions_dps, weights_dps, 0, n_bones_shp, pose_params_shp, base_relatives_shp, parents_shp, inverse_base_absolutes_shp, base_positions_shp, weights_shp);
	card_t n_corr_card_shp = correspondences_shp;
	card_t macroDef2429 = correspondences_dps->length;
	card_t n_corr_card_dps = macroDef2429;
	card_t n_corr_shp = 0;
	index_t n_corr_dps = (n_corr_card_dps);
	env_t_2451 env_t_2451_value = make_empty_env(); closure_t closure2432 = make_closure(lambda2451, &env_t_2451_value);
	card_t err_shp = TOP_LEVEL_linalg_vectorMap_shp(closure2432, TOP_LEVEL_linalg_vectorRange_shp(0, (((n_corr_card_shp) + (n_corr_card_shp)) + (n_corr_card_shp)) - (1)));
	card_t size2457 = width_card_t(err_shp);
	array_number_t stgVar2391 = storage_alloc(size2457);
	array_number_t macroDef2448;card_t size2456 = width_card_t(TOP_LEVEL_linalg_vectorRange_shp(0, (((n_corr_card_shp) + (n_corr_card_shp)) + (n_corr_card_shp)) - (1)));
	array_number_t stgVar2393 = storage_alloc(size2456);
	array_number_t macroDef2447;env_t_2452 env_t_2452_value = make_env_t_2452(vertex_positions_shp,vertex_positions_dps,points_shp,points_dps,n_corr_dps,correspondences_dps); closure_t closure2443 = make_closure(lambda2452, &env_t_2452_value);
	env_t_2455 env_t_2455_value = make_empty_env(); closure_t closure2446 = make_closure(lambda2455, &env_t_2455_value);
	macroDef2447 = TOP_LEVEL_linalg_vectorMap_dps(stgVar2391, closure2443, TOP_LEVEL_linalg_vectorRange_dps(stgVar2393, 0, (((n_corr_card_dps) + (n_corr_card_dps)) + (n_corr_card_dps)) - (1), 0, (((n_corr_card_shp) + (n_corr_card_shp)) + (n_corr_card_shp)) - (1)), closure2446, TOP_LEVEL_linalg_vectorRange_shp(0, (((n_corr_card_shp) + (n_corr_card_shp)) + (n_corr_card_shp)) - (1)));;
	storage_free(stgVar2393, size2456);
	array_number_t err_dps = macroDef2447;
	macroDef2448 = err_dps;;
	storage_free(stgVar2391, size2457);
	macroDef2449 = macroDef2448;;
	storage_free(stgVar2379, size2458);
	macroDef2450 = macroDef2449;;
	storage_free(stgVar2376, size2459);
	return macroDef2450;
}

card_t TOP_LEVEL_usecases_ht_test_ht_shp(card_t unitVar0_shp) {
	
	return 0;
}

typedef empty_env_t env_t_2509;


value_t lambda2509(env_t_2509* env2494, card_t i_shp) {
	
	value_t res;
	res.card_t_value = 4;
	return res;
}
void TOP_LEVEL_usecases_ht_test_ht_dps(storage_t stgVar2460, int unitVar0_dps, card_t unitVar0_shp) {
	card_t a_shp = 3;
	card_t size2515 = width_card_t(a_shp);
	array_number_t stgVar2461 = storage_alloc(size2515);
	array_number_t macroDef2489 = (array_number_t)stgVar2461;
	macroDef2489->length=3;
	macroDef2489->arr=(number_t*)(STG_OFFSET(stgVar2461, VECTOR_HEADER_BYTES));
	

	macroDef2489->arr[0] = 1;;

	macroDef2489->arr[1] = 2;;

	macroDef2489->arr[2] = 3;;;
	array_number_t a_dps = macroDef2489;
	array_print(a_dps);
	matrix_shape_t mat1_shp = nested_shape_card_t(3, 3);
	card_t size2514 = width_matrix_shape_t(mat1_shp);
	array_number_t stgVar2465 = storage_alloc(size2514);
	array_array_number_t macroDef2493 = (array_array_number_t)stgVar2465;
	macroDef2493->length=3;
	macroDef2493->arr=(array_number_t*)(STG_OFFSET(stgVar2465, VECTOR_HEADER_BYTES));
	int stgVar2465_offsetVar = 0;storage_t stgVar2466 = STG_OFFSET(stgVar2465, MATRIX_HEADER_BYTES(3) + stgVar2465_offsetVar);array_number_t macroDef2490 = (array_number_t)stgVar2466;
	macroDef2490->length=3;
	macroDef2490->arr=(number_t*)(STG_OFFSET(stgVar2466, VECTOR_HEADER_BYTES));
	

	macroDef2490->arr[0] = 1;;

	macroDef2490->arr[1] = 2;;

	macroDef2490->arr[2] = 3;;;

	macroDef2493->arr[0] = macroDef2490;;stgVar2465_offsetVar += VECTOR_ALL_BYTES(macroDef2493->arr[0]->length);storage_t stgVar2470 = STG_OFFSET(stgVar2465, MATRIX_HEADER_BYTES(3) + stgVar2465_offsetVar);array_number_t macroDef2491 = (array_number_t)stgVar2470;
	macroDef2491->length=3;
	macroDef2491->arr=(number_t*)(STG_OFFSET(stgVar2470, VECTOR_HEADER_BYTES));
	

	macroDef2491->arr[0] = 4;;

	macroDef2491->arr[1] = 5;;

	macroDef2491->arr[2] = 6;;;

	macroDef2493->arr[1] = macroDef2491;;stgVar2465_offsetVar += VECTOR_ALL_BYTES(macroDef2493->arr[1]->length);storage_t stgVar2474 = STG_OFFSET(stgVar2465, MATRIX_HEADER_BYTES(3) + stgVar2465_offsetVar);array_number_t macroDef2492 = (array_number_t)stgVar2474;
	macroDef2492->length=3;
	macroDef2492->arr=(number_t*)(STG_OFFSET(stgVar2474, VECTOR_HEADER_BYTES));
	

	macroDef2492->arr[0] = 7;;

	macroDef2492->arr[1] = 8;;

	macroDef2492->arr[2] = 9;;;

	macroDef2493->arr[2] = macroDef2492;;stgVar2465_offsetVar += VECTOR_ALL_BYTES(macroDef2493->arr[2]->length);;
	array_array_number_t mat1_dps = macroDef2493;
	env_t_2509 env_t_2509_value = make_empty_env(); closure_t closure2496 = make_closure(lambda2509, &env_t_2509_value);
	matrix_shape_t base_rel_shp = nested_shape_card_t(closure2496.lam(closure2496.env, 0).card_t_value, 4);
	card_t size2513 = width_matrix_shape_t(base_rel_shp);
	array_number_t stgVar2478 = storage_alloc(size2513);
	array_array_number_t macroDef2498 = (array_array_number_t)stgVar2478;
		macroDef2498->length=4;
		macroDef2498->arr=(array_number_t*)(STG_OFFSET(macroDef2498, VECTOR_HEADER_BYTES));
		storage_t stgVar2479 = (STG_OFFSET(macroDef2498, MATRIX_HEADER_BYTES(4)));
		for(int i_dps = 0; i_dps < macroDef2498->length; i_dps++){
			array_number_t macroDef2497 = (array_number_t)stgVar2479;
		macroDef2497->length=4;
		macroDef2497->arr=(number_t*)(STG_OFFSET(macroDef2497, VECTOR_HEADER_BYTES));
		storage_t stgVar2480 = macroDef2497;
		for(int j_dps = 0; j_dps < macroDef2497->length; j_dps++){
			
			macroDef2497->arr[j_dps] = (double)((((i_dps) + (1)) * (4)) + (j_dps));;
			stgVar2480 = STG_OFFSET(stgVar2480, sizeof(number_t));
		}
			macroDef2498->arr[i_dps] = macroDef2497;;
			stgVar2479 = STG_OFFSET(stgVar2479, VECTOR_ALL_BYTES(macroDef2498->arr[i_dps]->length));
		}
	array_array_number_t base_rel_dps = macroDef2498;
	matrix_shape_t q_shp = TOP_LEVEL_usecases_ht_make_relative_shp(a_shp, base_rel_shp);
	card_t size2512 = width_matrix_shape_t(q_shp);
	array_number_t stgVar2481 = storage_alloc(size2512);
	array_array_number_t q_dps = TOP_LEVEL_usecases_ht_make_relative_dps(stgVar2481, a_dps, base_rel_dps, a_shp, base_rel_shp);
	matrix_print(q_dps);
	matrix_shape_t r_shp = TOP_LEVEL_usecases_ht_angle_axis_to_rotation_matrix_shp(a_shp);
	card_t size2511 = width_matrix_shape_t(r_shp);
	array_number_t stgVar2484 = storage_alloc(size2511);
	array_array_number_t r_dps = TOP_LEVEL_usecases_ht_angle_axis_to_rotation_matrix_dps(stgVar2484, a_dps, a_shp);
	matrix_print(r_dps);
	matrix_shape_t s_shp = TOP_LEVEL_usecases_ht_apply_global_transform_shp(mat1_shp, mat1_shp);
	card_t size2510 = width_matrix_shape_t(s_shp);
	array_number_t stgVar2486 = storage_alloc(size2510);
	array_array_number_t s_dps = TOP_LEVEL_usecases_ht_apply_global_transform_dps(stgVar2486, mat1_dps, mat1_dps, mat1_shp, mat1_shp);
	matrix_print(s_dps);
	;
	storage_free(stgVar2486, size2510);
	;
	storage_free(stgVar2484, size2511);
	;
	storage_free(stgVar2481, size2512);
	;
	storage_free(stgVar2478, size2513);
	;
	storage_free(stgVar2465, size2514);
	;
	storage_free(stgVar2461, size2515);
	return ;
}
#endif
