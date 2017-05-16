#ifndef __USECASES_HT_STORAGED_H__ 
#define __USECASES_HT_STORAGED_H__ 
#include "../../Runtime/C/fsharp.h"
#include <stdio.h>
#include <math.h>
#include "linalg_storaged.h"

matrix3d_shape_t TOP_LEVEL_usecases_ht_matrix3DUpdate_shp(matrix3d_shape_t m_shp, card_t s_shp, card_t e_shp, matrix3d_shape_t nm_shp) {
	
	return nested_shape_matrix_shape_t(nm_shp.elem, m_shp.card);
}


array_array_array_number_t TOP_LEVEL_usecases_ht_matrix3DUpdate_dps(storage_t stgVar1444, array_array_array_number_t m_dps, index_t s_dps, index_t e_dps, array_array_array_number_t nm_dps, matrix3d_shape_t m_shp, card_t s_shp, card_t e_shp, matrix3d_shape_t nm_shp) {
	card_t macroDef1450 = m_dps->length;
	array_array_array_number_t macroDef1451 = (array_array_array_number_t)stgVar1444;
		macroDef1451->length=macroDef1450;
		macroDef1451->arr=(array_array_number_t*)(STG_OFFSET(macroDef1451, VECTOR_HEADER_BYTES));
		storage_t stgVar1446 = (STG_OFFSET(macroDef1451, MATRIX_HEADER_BYTES(macroDef1450)));
		for(int i_dps = 0; i_dps < macroDef1451->length; i_dps++){
			card_t isInRange_shp = 0;
			bool_t isInRange_dps = 0;
	if((i_dps) >= (s_dps)) {
		
		isInRange_dps = (i_dps) < (e_dps);;
	} else {
		
		isInRange_dps = false;;
	}
			array_array_number_t ite1452 = 0;
	if(isInRange_dps) {
		
		ite1452 = nm_dps->arr[(i_dps) - (s_dps)];;
	} else {
		
		ite1452 = m_dps->arr[i_dps];;
	}
			macroDef1451->arr[i_dps] = ite1452;;
			stgVar1446 = STG_OFFSET(stgVar1446, VECTOR_ALL_BYTES(macroDef1451->arr[i_dps]->length));
		}
	return macroDef1451;
}

matrix_shape_t TOP_LEVEL_usecases_ht_to_pose_params_shp(card_t theta_shp, card_t n_bones_shp) {
	
	return TOP_LEVEL_linalg_matrixConcat_shp(nested_shape_card_t(TOP_LEVEL_linalg_vectorSlice_shp(3, 0, theta_shp), 5), TOP_LEVEL_linalg_matrixConcat_shp(nested_shape_card_t(3, 4), TOP_LEVEL_linalg_matrixConcat_shp(nested_shape_card_t(3, 4), TOP_LEVEL_linalg_matrixConcat_shp(nested_shape_card_t(3, 4), TOP_LEVEL_linalg_matrixConcat_shp(nested_shape_card_t(3, 4), nested_shape_card_t(3, 4))))));
}


array_array_number_t TOP_LEVEL_usecases_ht_to_pose_params_dps(storage_t stgVar1453, array_number_t theta_dps, card_t n_bones_dps, card_t theta_shp, card_t n_bones_shp) {
	card_t row1_shp = TOP_LEVEL_linalg_vectorSlice_shp(3, 0, theta_shp);
	card_t size1861 = width_card_t(row1_shp);
	array_number_t stgVar1454 = storage_alloc(size1861);
	array_array_number_t macroDef1847;array_number_t row1_dps = TOP_LEVEL_linalg_vectorSlice_dps(stgVar1454, 3, 0, theta_dps, 3, 0, theta_shp);
	card_t row2_shp = 3;
	card_t size1860 = width_card_t(row2_shp);
	array_number_t stgVar1458 = storage_alloc(size1860);
	array_array_number_t macroDef1846;array_number_t macroDef1806 = (array_number_t)stgVar1458;
	macroDef1806->length=3;
	macroDef1806->arr=(number_t*)(STG_OFFSET(stgVar1458, VECTOR_HEADER_BYTES));
	

	macroDef1806->arr[0] = 1;;

	macroDef1806->arr[1] = 1;;

	macroDef1806->arr[2] = 1;;;
	array_number_t row2_dps = macroDef1806;
	card_t row3_shp = TOP_LEVEL_linalg_vectorSlice_shp(3, 0, theta_shp);
	card_t size1859 = width_card_t(row3_shp);
	array_number_t stgVar1462 = storage_alloc(size1859);
	array_array_number_t macroDef1845;array_number_t row3_dps = TOP_LEVEL_linalg_vectorSlice_dps(stgVar1462, 3, 3, theta_dps, 3, 0, theta_shp);
	card_t zeroRow_shp = 3;
	card_t size1858 = width_card_t(zeroRow_shp);
	array_number_t stgVar1466 = storage_alloc(size1858);
	array_array_number_t macroDef1844;array_number_t macroDef1807 = (array_number_t)stgVar1466;
	macroDef1807->length=3;
	macroDef1807->arr=(number_t*)(STG_OFFSET(stgVar1466, VECTOR_HEADER_BYTES));
	

	macroDef1807->arr[0] = 0;;

	macroDef1807->arr[1] = 0;;

	macroDef1807->arr[2] = 0;;;
	array_number_t zeroRow_dps = macroDef1807;
	matrix_shape_t pose_params_shp = nested_shape_card_t(row1_shp, 5);
	card_t size1857 = width_matrix_shape_t(pose_params_shp);
	array_number_t stgVar1470 = storage_alloc(size1857);
	array_array_number_t macroDef1843;array_array_number_t macroDef1808 = (array_array_number_t)stgVar1470;
	macroDef1808->length=5;
	macroDef1808->arr=(array_number_t*)(STG_OFFSET(stgVar1470, VECTOR_HEADER_BYTES));
	int stgVar1470_offsetVar = 0;storage_t stgVar1471 = STG_OFFSET(stgVar1470, MATRIX_HEADER_BYTES(5) + stgVar1470_offsetVar);

	macroDef1808->arr[0] = row1_dps;;stgVar1470_offsetVar += VECTOR_ALL_BYTES(macroDef1808->arr[0]->length);storage_t stgVar1472 = STG_OFFSET(stgVar1470, MATRIX_HEADER_BYTES(5) + stgVar1470_offsetVar);

	macroDef1808->arr[1] = row2_dps;;stgVar1470_offsetVar += VECTOR_ALL_BYTES(macroDef1808->arr[1]->length);storage_t stgVar1473 = STG_OFFSET(stgVar1470, MATRIX_HEADER_BYTES(5) + stgVar1470_offsetVar);

	macroDef1808->arr[2] = row3_dps;;stgVar1470_offsetVar += VECTOR_ALL_BYTES(macroDef1808->arr[2]->length);storage_t stgVar1474 = STG_OFFSET(stgVar1470, MATRIX_HEADER_BYTES(5) + stgVar1470_offsetVar);

	macroDef1808->arr[3] = zeroRow_dps;;stgVar1470_offsetVar += VECTOR_ALL_BYTES(macroDef1808->arr[3]->length);storage_t stgVar1475 = STG_OFFSET(stgVar1470, MATRIX_HEADER_BYTES(5) + stgVar1470_offsetVar);

	macroDef1808->arr[4] = zeroRow_dps;;stgVar1470_offsetVar += VECTOR_ALL_BYTES(macroDef1808->arr[4]->length);;
	array_array_number_t pose_params_dps = macroDef1808;
	card_t i1_shp = 0;
	index_t i1_dps = 5;
	matrix_shape_t finger1_shp = nested_shape_card_t(3, 4);
	card_t size1856 = width_matrix_shape_t(finger1_shp);
	array_number_t stgVar1477 = storage_alloc(size1856);
	array_array_number_t macroDef1842;array_array_number_t macroDef1813 = (array_array_number_t)stgVar1477;
	macroDef1813->length=4;
	macroDef1813->arr=(array_number_t*)(STG_OFFSET(stgVar1477, VECTOR_HEADER_BYTES));
	int stgVar1477_offsetVar = 0;storage_t stgVar1478 = STG_OFFSET(stgVar1477, MATRIX_HEADER_BYTES(4) + stgVar1477_offsetVar);array_number_t macroDef1809 = (array_number_t)stgVar1478;
	macroDef1809->length=3;
	macroDef1809->arr=(number_t*)(STG_OFFSET(stgVar1478, VECTOR_HEADER_BYTES));
	

	macroDef1809->arr[0] = theta_dps->arr[i1_dps];;

	macroDef1809->arr[1] = theta_dps->arr[(i1_dps) + (1)];;

	macroDef1809->arr[2] = 0;;;

	macroDef1813->arr[0] = macroDef1809;;stgVar1477_offsetVar += VECTOR_ALL_BYTES(macroDef1813->arr[0]->length);storage_t stgVar1484 = STG_OFFSET(stgVar1477, MATRIX_HEADER_BYTES(4) + stgVar1477_offsetVar);array_number_t macroDef1810 = (array_number_t)stgVar1484;
	macroDef1810->length=3;
	macroDef1810->arr=(number_t*)(STG_OFFSET(stgVar1484, VECTOR_HEADER_BYTES));
	

	macroDef1810->arr[0] = theta_dps->arr[(i1_dps) + (2)];;

	macroDef1810->arr[1] = 0;;

	macroDef1810->arr[2] = 0;;;

	macroDef1813->arr[1] = macroDef1810;;stgVar1477_offsetVar += VECTOR_ALL_BYTES(macroDef1813->arr[1]->length);storage_t stgVar1489 = STG_OFFSET(stgVar1477, MATRIX_HEADER_BYTES(4) + stgVar1477_offsetVar);array_number_t macroDef1811 = (array_number_t)stgVar1489;
	macroDef1811->length=3;
	macroDef1811->arr=(number_t*)(STG_OFFSET(stgVar1489, VECTOR_HEADER_BYTES));
	

	macroDef1811->arr[0] = theta_dps->arr[(i1_dps) + (3)];;

	macroDef1811->arr[1] = 0;;

	macroDef1811->arr[2] = 0;;;

	macroDef1813->arr[2] = macroDef1811;;stgVar1477_offsetVar += VECTOR_ALL_BYTES(macroDef1813->arr[2]->length);storage_t stgVar1494 = STG_OFFSET(stgVar1477, MATRIX_HEADER_BYTES(4) + stgVar1477_offsetVar);array_number_t macroDef1812 = (array_number_t)stgVar1494;
	macroDef1812->length=3;
	macroDef1812->arr=(number_t*)(STG_OFFSET(stgVar1494, VECTOR_HEADER_BYTES));
	

	macroDef1812->arr[0] = 0;;

	macroDef1812->arr[1] = 0;;

	macroDef1812->arr[2] = 0;;;

	macroDef1813->arr[3] = macroDef1812;;stgVar1477_offsetVar += VECTOR_ALL_BYTES(macroDef1813->arr[3]->length);;
	array_array_number_t finger1_dps = macroDef1813;
	card_t i2_shp = 0;
	index_t i2_dps = (i1_dps) + (4);
	matrix_shape_t finger2_shp = nested_shape_card_t(3, 4);
	card_t size1855 = width_matrix_shape_t(finger2_shp);
	array_number_t stgVar1499 = storage_alloc(size1855);
	array_array_number_t macroDef1841;array_array_number_t macroDef1818 = (array_array_number_t)stgVar1499;
	macroDef1818->length=4;
	macroDef1818->arr=(array_number_t*)(STG_OFFSET(stgVar1499, VECTOR_HEADER_BYTES));
	int stgVar1499_offsetVar = 0;storage_t stgVar1500 = STG_OFFSET(stgVar1499, MATRIX_HEADER_BYTES(4) + stgVar1499_offsetVar);array_number_t macroDef1814 = (array_number_t)stgVar1500;
	macroDef1814->length=3;
	macroDef1814->arr=(number_t*)(STG_OFFSET(stgVar1500, VECTOR_HEADER_BYTES));
	

	macroDef1814->arr[0] = theta_dps->arr[i2_dps];;

	macroDef1814->arr[1] = theta_dps->arr[(i2_dps) + (1)];;

	macroDef1814->arr[2] = 0;;;

	macroDef1818->arr[0] = macroDef1814;;stgVar1499_offsetVar += VECTOR_ALL_BYTES(macroDef1818->arr[0]->length);storage_t stgVar1506 = STG_OFFSET(stgVar1499, MATRIX_HEADER_BYTES(4) + stgVar1499_offsetVar);array_number_t macroDef1815 = (array_number_t)stgVar1506;
	macroDef1815->length=3;
	macroDef1815->arr=(number_t*)(STG_OFFSET(stgVar1506, VECTOR_HEADER_BYTES));
	

	macroDef1815->arr[0] = theta_dps->arr[(i2_dps) + (2)];;

	macroDef1815->arr[1] = 0;;

	macroDef1815->arr[2] = 0;;;

	macroDef1818->arr[1] = macroDef1815;;stgVar1499_offsetVar += VECTOR_ALL_BYTES(macroDef1818->arr[1]->length);storage_t stgVar1511 = STG_OFFSET(stgVar1499, MATRIX_HEADER_BYTES(4) + stgVar1499_offsetVar);array_number_t macroDef1816 = (array_number_t)stgVar1511;
	macroDef1816->length=3;
	macroDef1816->arr=(number_t*)(STG_OFFSET(stgVar1511, VECTOR_HEADER_BYTES));
	

	macroDef1816->arr[0] = theta_dps->arr[(i2_dps) + (3)];;

	macroDef1816->arr[1] = 0;;

	macroDef1816->arr[2] = 0;;;

	macroDef1818->arr[2] = macroDef1816;;stgVar1499_offsetVar += VECTOR_ALL_BYTES(macroDef1818->arr[2]->length);storage_t stgVar1516 = STG_OFFSET(stgVar1499, MATRIX_HEADER_BYTES(4) + stgVar1499_offsetVar);array_number_t macroDef1817 = (array_number_t)stgVar1516;
	macroDef1817->length=3;
	macroDef1817->arr=(number_t*)(STG_OFFSET(stgVar1516, VECTOR_HEADER_BYTES));
	

	macroDef1817->arr[0] = 0;;

	macroDef1817->arr[1] = 0;;

	macroDef1817->arr[2] = 0;;;

	macroDef1818->arr[3] = macroDef1817;;stgVar1499_offsetVar += VECTOR_ALL_BYTES(macroDef1818->arr[3]->length);;
	array_array_number_t finger2_dps = macroDef1818;
	card_t i3_shp = 0;
	index_t i3_dps = (i2_dps) + (4);
	matrix_shape_t finger3_shp = nested_shape_card_t(3, 4);
	card_t size1854 = width_matrix_shape_t(finger3_shp);
	array_number_t stgVar1521 = storage_alloc(size1854);
	array_array_number_t macroDef1840;array_array_number_t macroDef1823 = (array_array_number_t)stgVar1521;
	macroDef1823->length=4;
	macroDef1823->arr=(array_number_t*)(STG_OFFSET(stgVar1521, VECTOR_HEADER_BYTES));
	int stgVar1521_offsetVar = 0;storage_t stgVar1522 = STG_OFFSET(stgVar1521, MATRIX_HEADER_BYTES(4) + stgVar1521_offsetVar);array_number_t macroDef1819 = (array_number_t)stgVar1522;
	macroDef1819->length=3;
	macroDef1819->arr=(number_t*)(STG_OFFSET(stgVar1522, VECTOR_HEADER_BYTES));
	

	macroDef1819->arr[0] = theta_dps->arr[i3_dps];;

	macroDef1819->arr[1] = theta_dps->arr[(i3_dps) + (1)];;

	macroDef1819->arr[2] = 0;;;

	macroDef1823->arr[0] = macroDef1819;;stgVar1521_offsetVar += VECTOR_ALL_BYTES(macroDef1823->arr[0]->length);storage_t stgVar1528 = STG_OFFSET(stgVar1521, MATRIX_HEADER_BYTES(4) + stgVar1521_offsetVar);array_number_t macroDef1820 = (array_number_t)stgVar1528;
	macroDef1820->length=3;
	macroDef1820->arr=(number_t*)(STG_OFFSET(stgVar1528, VECTOR_HEADER_BYTES));
	

	macroDef1820->arr[0] = theta_dps->arr[(i3_dps) + (2)];;

	macroDef1820->arr[1] = 0;;

	macroDef1820->arr[2] = 0;;;

	macroDef1823->arr[1] = macroDef1820;;stgVar1521_offsetVar += VECTOR_ALL_BYTES(macroDef1823->arr[1]->length);storage_t stgVar1533 = STG_OFFSET(stgVar1521, MATRIX_HEADER_BYTES(4) + stgVar1521_offsetVar);array_number_t macroDef1821 = (array_number_t)stgVar1533;
	macroDef1821->length=3;
	macroDef1821->arr=(number_t*)(STG_OFFSET(stgVar1533, VECTOR_HEADER_BYTES));
	

	macroDef1821->arr[0] = theta_dps->arr[(i3_dps) + (3)];;

	macroDef1821->arr[1] = 0;;

	macroDef1821->arr[2] = 0;;;

	macroDef1823->arr[2] = macroDef1821;;stgVar1521_offsetVar += VECTOR_ALL_BYTES(macroDef1823->arr[2]->length);storage_t stgVar1538 = STG_OFFSET(stgVar1521, MATRIX_HEADER_BYTES(4) + stgVar1521_offsetVar);array_number_t macroDef1822 = (array_number_t)stgVar1538;
	macroDef1822->length=3;
	macroDef1822->arr=(number_t*)(STG_OFFSET(stgVar1538, VECTOR_HEADER_BYTES));
	

	macroDef1822->arr[0] = 0;;

	macroDef1822->arr[1] = 0;;

	macroDef1822->arr[2] = 0;;;

	macroDef1823->arr[3] = macroDef1822;;stgVar1521_offsetVar += VECTOR_ALL_BYTES(macroDef1823->arr[3]->length);;
	array_array_number_t finger3_dps = macroDef1823;
	card_t i4_shp = 0;
	index_t i4_dps = (i3_dps) + (4);
	matrix_shape_t finger4_shp = nested_shape_card_t(3, 4);
	card_t size1853 = width_matrix_shape_t(finger4_shp);
	array_number_t stgVar1543 = storage_alloc(size1853);
	array_array_number_t macroDef1839;array_array_number_t macroDef1828 = (array_array_number_t)stgVar1543;
	macroDef1828->length=4;
	macroDef1828->arr=(array_number_t*)(STG_OFFSET(stgVar1543, VECTOR_HEADER_BYTES));
	int stgVar1543_offsetVar = 0;storage_t stgVar1544 = STG_OFFSET(stgVar1543, MATRIX_HEADER_BYTES(4) + stgVar1543_offsetVar);array_number_t macroDef1824 = (array_number_t)stgVar1544;
	macroDef1824->length=3;
	macroDef1824->arr=(number_t*)(STG_OFFSET(stgVar1544, VECTOR_HEADER_BYTES));
	

	macroDef1824->arr[0] = theta_dps->arr[i4_dps];;

	macroDef1824->arr[1] = theta_dps->arr[(i4_dps) + (1)];;

	macroDef1824->arr[2] = 0;;;

	macroDef1828->arr[0] = macroDef1824;;stgVar1543_offsetVar += VECTOR_ALL_BYTES(macroDef1828->arr[0]->length);storage_t stgVar1550 = STG_OFFSET(stgVar1543, MATRIX_HEADER_BYTES(4) + stgVar1543_offsetVar);array_number_t macroDef1825 = (array_number_t)stgVar1550;
	macroDef1825->length=3;
	macroDef1825->arr=(number_t*)(STG_OFFSET(stgVar1550, VECTOR_HEADER_BYTES));
	

	macroDef1825->arr[0] = theta_dps->arr[(i4_dps) + (2)];;

	macroDef1825->arr[1] = 0;;

	macroDef1825->arr[2] = 0;;;

	macroDef1828->arr[1] = macroDef1825;;stgVar1543_offsetVar += VECTOR_ALL_BYTES(macroDef1828->arr[1]->length);storage_t stgVar1555 = STG_OFFSET(stgVar1543, MATRIX_HEADER_BYTES(4) + stgVar1543_offsetVar);array_number_t macroDef1826 = (array_number_t)stgVar1555;
	macroDef1826->length=3;
	macroDef1826->arr=(number_t*)(STG_OFFSET(stgVar1555, VECTOR_HEADER_BYTES));
	

	macroDef1826->arr[0] = theta_dps->arr[(i4_dps) + (3)];;

	macroDef1826->arr[1] = 0;;

	macroDef1826->arr[2] = 0;;;

	macroDef1828->arr[2] = macroDef1826;;stgVar1543_offsetVar += VECTOR_ALL_BYTES(macroDef1828->arr[2]->length);storage_t stgVar1560 = STG_OFFSET(stgVar1543, MATRIX_HEADER_BYTES(4) + stgVar1543_offsetVar);array_number_t macroDef1827 = (array_number_t)stgVar1560;
	macroDef1827->length=3;
	macroDef1827->arr=(number_t*)(STG_OFFSET(stgVar1560, VECTOR_HEADER_BYTES));
	

	macroDef1827->arr[0] = 0;;

	macroDef1827->arr[1] = 0;;

	macroDef1827->arr[2] = 0;;;

	macroDef1828->arr[3] = macroDef1827;;stgVar1543_offsetVar += VECTOR_ALL_BYTES(macroDef1828->arr[3]->length);;
	array_array_number_t finger4_dps = macroDef1828;
	card_t i5_shp = 0;
	index_t i5_dps = (i4_dps) + (4);
	matrix_shape_t finger5_shp = nested_shape_card_t(3, 4);
	card_t size1852 = width_matrix_shape_t(finger5_shp);
	array_number_t stgVar1565 = storage_alloc(size1852);
	array_array_number_t macroDef1838;array_array_number_t macroDef1833 = (array_array_number_t)stgVar1565;
	macroDef1833->length=4;
	macroDef1833->arr=(array_number_t*)(STG_OFFSET(stgVar1565, VECTOR_HEADER_BYTES));
	int stgVar1565_offsetVar = 0;storage_t stgVar1566 = STG_OFFSET(stgVar1565, MATRIX_HEADER_BYTES(4) + stgVar1565_offsetVar);array_number_t macroDef1829 = (array_number_t)stgVar1566;
	macroDef1829->length=3;
	macroDef1829->arr=(number_t*)(STG_OFFSET(stgVar1566, VECTOR_HEADER_BYTES));
	

	macroDef1829->arr[0] = theta_dps->arr[i5_dps];;

	macroDef1829->arr[1] = theta_dps->arr[(i5_dps) + (1)];;

	macroDef1829->arr[2] = 0;;;

	macroDef1833->arr[0] = macroDef1829;;stgVar1565_offsetVar += VECTOR_ALL_BYTES(macroDef1833->arr[0]->length);storage_t stgVar1572 = STG_OFFSET(stgVar1565, MATRIX_HEADER_BYTES(4) + stgVar1565_offsetVar);array_number_t macroDef1830 = (array_number_t)stgVar1572;
	macroDef1830->length=3;
	macroDef1830->arr=(number_t*)(STG_OFFSET(stgVar1572, VECTOR_HEADER_BYTES));
	

	macroDef1830->arr[0] = theta_dps->arr[(i5_dps) + (2)];;

	macroDef1830->arr[1] = 0;;

	macroDef1830->arr[2] = 0;;;

	macroDef1833->arr[1] = macroDef1830;;stgVar1565_offsetVar += VECTOR_ALL_BYTES(macroDef1833->arr[1]->length);storage_t stgVar1577 = STG_OFFSET(stgVar1565, MATRIX_HEADER_BYTES(4) + stgVar1565_offsetVar);array_number_t macroDef1831 = (array_number_t)stgVar1577;
	macroDef1831->length=3;
	macroDef1831->arr=(number_t*)(STG_OFFSET(stgVar1577, VECTOR_HEADER_BYTES));
	

	macroDef1831->arr[0] = theta_dps->arr[(i5_dps) + (3)];;

	macroDef1831->arr[1] = 0;;

	macroDef1831->arr[2] = 0;;;

	macroDef1833->arr[2] = macroDef1831;;stgVar1565_offsetVar += VECTOR_ALL_BYTES(macroDef1833->arr[2]->length);storage_t stgVar1582 = STG_OFFSET(stgVar1565, MATRIX_HEADER_BYTES(4) + stgVar1565_offsetVar);array_number_t macroDef1832 = (array_number_t)stgVar1582;
	macroDef1832->length=3;
	macroDef1832->arr=(number_t*)(STG_OFFSET(stgVar1582, VECTOR_HEADER_BYTES));
	

	macroDef1832->arr[0] = 0;;

	macroDef1832->arr[1] = 0;;

	macroDef1832->arr[2] = 0;;;

	macroDef1833->arr[3] = macroDef1832;;stgVar1565_offsetVar += VECTOR_ALL_BYTES(macroDef1833->arr[3]->length);;
	array_array_number_t finger5_dps = macroDef1833;
	card_t size1851 = width_matrix_shape_t(TOP_LEVEL_linalg_matrixConcat_shp(finger1_shp, TOP_LEVEL_linalg_matrixConcat_shp(finger2_shp, TOP_LEVEL_linalg_matrixConcat_shp(finger3_shp, TOP_LEVEL_linalg_matrixConcat_shp(finger4_shp, finger5_shp)))));
	array_number_t stgVar1587 = storage_alloc(size1851);
	array_array_number_t macroDef1837;card_t size1850 = width_matrix_shape_t(TOP_LEVEL_linalg_matrixConcat_shp(finger2_shp, TOP_LEVEL_linalg_matrixConcat_shp(finger3_shp, TOP_LEVEL_linalg_matrixConcat_shp(finger4_shp, finger5_shp))));
	array_number_t stgVar1589 = storage_alloc(size1850);
	array_array_number_t macroDef1836;card_t size1849 = width_matrix_shape_t(TOP_LEVEL_linalg_matrixConcat_shp(finger3_shp, TOP_LEVEL_linalg_matrixConcat_shp(finger4_shp, finger5_shp)));
	array_number_t stgVar1591 = storage_alloc(size1849);
	array_array_number_t macroDef1835;card_t size1848 = width_matrix_shape_t(TOP_LEVEL_linalg_matrixConcat_shp(finger4_shp, finger5_shp));
	array_number_t stgVar1593 = storage_alloc(size1848);
	array_array_number_t macroDef1834;
	macroDef1834 = TOP_LEVEL_linalg_matrixConcat_dps(stgVar1591, finger3_dps, TOP_LEVEL_linalg_matrixConcat_dps(stgVar1593, finger4_dps, finger5_dps, finger4_shp, finger5_shp), finger3_shp, TOP_LEVEL_linalg_matrixConcat_shp(finger4_shp, finger5_shp));;
	storage_free(stgVar1593, size1848);
	macroDef1835 = TOP_LEVEL_linalg_matrixConcat_dps(stgVar1589, finger2_dps, macroDef1834, finger2_shp, TOP_LEVEL_linalg_matrixConcat_shp(finger3_shp, TOP_LEVEL_linalg_matrixConcat_shp(finger4_shp, finger5_shp)));;
	storage_free(stgVar1591, size1849);
	macroDef1836 = TOP_LEVEL_linalg_matrixConcat_dps(stgVar1587, finger1_dps, macroDef1835, finger1_shp, TOP_LEVEL_linalg_matrixConcat_shp(finger2_shp, TOP_LEVEL_linalg_matrixConcat_shp(finger3_shp, TOP_LEVEL_linalg_matrixConcat_shp(finger4_shp, finger5_shp))));;
	storage_free(stgVar1589, size1850);
	macroDef1837 = TOP_LEVEL_linalg_matrixConcat_dps(stgVar1453, pose_params_dps, macroDef1836, pose_params_shp, TOP_LEVEL_linalg_matrixConcat_shp(finger1_shp, TOP_LEVEL_linalg_matrixConcat_shp(finger2_shp, TOP_LEVEL_linalg_matrixConcat_shp(finger3_shp, TOP_LEVEL_linalg_matrixConcat_shp(finger4_shp, finger5_shp)))));;
	storage_free(stgVar1587, size1851);
	macroDef1838 = macroDef1837;;
	storage_free(stgVar1565, size1852);
	macroDef1839 = macroDef1838;;
	storage_free(stgVar1543, size1853);
	macroDef1840 = macroDef1839;;
	storage_free(stgVar1521, size1854);
	macroDef1841 = macroDef1840;;
	storage_free(stgVar1499, size1855);
	macroDef1842 = macroDef1841;;
	storage_free(stgVar1477, size1856);
	macroDef1843 = macroDef1842;;
	storage_free(stgVar1470, size1857);
	macroDef1844 = macroDef1843;;
	storage_free(stgVar1466, size1858);
	macroDef1845 = macroDef1844;;
	storage_free(stgVar1462, size1859);
	macroDef1846 = macroDef1845;;
	storage_free(stgVar1458, size1860);
	macroDef1847 = macroDef1846;;
	storage_free(stgVar1454, size1861);
	return macroDef1847;
}

matrix_shape_t TOP_LEVEL_usecases_ht_euler_angles_to_rotation_matrix_shp(card_t xzy_shp) {
	
	return TOP_LEVEL_linalg_matrixMult_shp(nested_shape_card_t(3, 3), TOP_LEVEL_linalg_matrixMult_shp(nested_shape_card_t(3, 3), nested_shape_card_t(3, 3)));
}


array_array_number_t TOP_LEVEL_usecases_ht_euler_angles_to_rotation_matrix_dps(storage_t stgVar1862, array_number_t xzy_dps, card_t xzy_shp) {
	card_t tx_shp = 0;
	number_t tx_dps = xzy_dps->arr[0];
	card_t ty_shp = 0;
	number_t ty_dps = xzy_dps->arr[2];
	card_t tz_shp = 0;
	number_t tz_dps = xzy_dps->arr[1];
	matrix_shape_t Rx_shp = nested_shape_card_t(3, 3);
	card_t size1961 = width_matrix_shape_t(Rx_shp);
	array_number_t stgVar1869 = storage_alloc(size1961);
	array_array_number_t macroDef1957;array_array_number_t macroDef1945 = (array_array_number_t)stgVar1869;
	macroDef1945->length=3;
	macroDef1945->arr=(array_number_t*)(STG_OFFSET(stgVar1869, VECTOR_HEADER_BYTES));
	int stgVar1869_offsetVar = 0;storage_t stgVar1870 = STG_OFFSET(stgVar1869, MATRIX_HEADER_BYTES(3) + stgVar1869_offsetVar);array_number_t macroDef1942 = (array_number_t)stgVar1870;
	macroDef1942->length=3;
	macroDef1942->arr=(number_t*)(STG_OFFSET(stgVar1870, VECTOR_HEADER_BYTES));
	

	macroDef1942->arr[0] = 1;;

	macroDef1942->arr[1] = 0;;

	macroDef1942->arr[2] = 0;;;

	macroDef1945->arr[0] = macroDef1942;;stgVar1869_offsetVar += VECTOR_ALL_BYTES(macroDef1945->arr[0]->length);storage_t stgVar1874 = STG_OFFSET(stgVar1869, MATRIX_HEADER_BYTES(3) + stgVar1869_offsetVar);array_number_t macroDef1943 = (array_number_t)stgVar1874;
	macroDef1943->length=3;
	macroDef1943->arr=(number_t*)(STG_OFFSET(stgVar1874, VECTOR_HEADER_BYTES));
	

	macroDef1943->arr[0] = 0;;

	macroDef1943->arr[1] = cos(tx_dps);;

	macroDef1943->arr[2] = -(sin(tx_dps));;;

	macroDef1945->arr[1] = macroDef1943;;stgVar1869_offsetVar += VECTOR_ALL_BYTES(macroDef1945->arr[1]->length);storage_t stgVar1878 = STG_OFFSET(stgVar1869, MATRIX_HEADER_BYTES(3) + stgVar1869_offsetVar);array_number_t macroDef1944 = (array_number_t)stgVar1878;
	macroDef1944->length=3;
	macroDef1944->arr=(number_t*)(STG_OFFSET(stgVar1878, VECTOR_HEADER_BYTES));
	

	macroDef1944->arr[0] = 0;;

	macroDef1944->arr[1] = sin(tx_dps);;

	macroDef1944->arr[2] = cos(tx_dps);;;

	macroDef1945->arr[2] = macroDef1944;;stgVar1869_offsetVar += VECTOR_ALL_BYTES(macroDef1945->arr[2]->length);;
	array_array_number_t Rx_dps = macroDef1945;
	matrix_shape_t Ry_shp = nested_shape_card_t(3, 3);
	card_t size1960 = width_matrix_shape_t(Ry_shp);
	array_number_t stgVar1882 = storage_alloc(size1960);
	array_array_number_t macroDef1956;array_array_number_t macroDef1949 = (array_array_number_t)stgVar1882;
	macroDef1949->length=3;
	macroDef1949->arr=(array_number_t*)(STG_OFFSET(stgVar1882, VECTOR_HEADER_BYTES));
	int stgVar1882_offsetVar = 0;storage_t stgVar1883 = STG_OFFSET(stgVar1882, MATRIX_HEADER_BYTES(3) + stgVar1882_offsetVar);array_number_t macroDef1946 = (array_number_t)stgVar1883;
	macroDef1946->length=3;
	macroDef1946->arr=(number_t*)(STG_OFFSET(stgVar1883, VECTOR_HEADER_BYTES));
	

	macroDef1946->arr[0] = cos(ty_dps);;

	macroDef1946->arr[1] = 0;;

	macroDef1946->arr[2] = sin(ty_dps);;;

	macroDef1949->arr[0] = macroDef1946;;stgVar1882_offsetVar += VECTOR_ALL_BYTES(macroDef1949->arr[0]->length);storage_t stgVar1887 = STG_OFFSET(stgVar1882, MATRIX_HEADER_BYTES(3) + stgVar1882_offsetVar);array_number_t macroDef1947 = (array_number_t)stgVar1887;
	macroDef1947->length=3;
	macroDef1947->arr=(number_t*)(STG_OFFSET(stgVar1887, VECTOR_HEADER_BYTES));
	

	macroDef1947->arr[0] = 0;;

	macroDef1947->arr[1] = 1;;

	macroDef1947->arr[2] = 0;;;

	macroDef1949->arr[1] = macroDef1947;;stgVar1882_offsetVar += VECTOR_ALL_BYTES(macroDef1949->arr[1]->length);storage_t stgVar1891 = STG_OFFSET(stgVar1882, MATRIX_HEADER_BYTES(3) + stgVar1882_offsetVar);array_number_t macroDef1948 = (array_number_t)stgVar1891;
	macroDef1948->length=3;
	macroDef1948->arr=(number_t*)(STG_OFFSET(stgVar1891, VECTOR_HEADER_BYTES));
	

	macroDef1948->arr[0] = -(sin(ty_dps));;

	macroDef1948->arr[1] = 0;;

	macroDef1948->arr[2] = cos(ty_dps);;;

	macroDef1949->arr[2] = macroDef1948;;stgVar1882_offsetVar += VECTOR_ALL_BYTES(macroDef1949->arr[2]->length);;
	array_array_number_t Ry_dps = macroDef1949;
	matrix_shape_t Rz_shp = nested_shape_card_t(3, 3);
	card_t size1959 = width_matrix_shape_t(Rz_shp);
	array_number_t stgVar1895 = storage_alloc(size1959);
	array_array_number_t macroDef1955;array_array_number_t macroDef1953 = (array_array_number_t)stgVar1895;
	macroDef1953->length=3;
	macroDef1953->arr=(array_number_t*)(STG_OFFSET(stgVar1895, VECTOR_HEADER_BYTES));
	int stgVar1895_offsetVar = 0;storage_t stgVar1896 = STG_OFFSET(stgVar1895, MATRIX_HEADER_BYTES(3) + stgVar1895_offsetVar);array_number_t macroDef1950 = (array_number_t)stgVar1896;
	macroDef1950->length=3;
	macroDef1950->arr=(number_t*)(STG_OFFSET(stgVar1896, VECTOR_HEADER_BYTES));
	

	macroDef1950->arr[0] = cos(tz_dps);;

	macroDef1950->arr[1] = -(sin(tz_dps));;

	macroDef1950->arr[2] = 0;;;

	macroDef1953->arr[0] = macroDef1950;;stgVar1895_offsetVar += VECTOR_ALL_BYTES(macroDef1953->arr[0]->length);storage_t stgVar1900 = STG_OFFSET(stgVar1895, MATRIX_HEADER_BYTES(3) + stgVar1895_offsetVar);array_number_t macroDef1951 = (array_number_t)stgVar1900;
	macroDef1951->length=3;
	macroDef1951->arr=(number_t*)(STG_OFFSET(stgVar1900, VECTOR_HEADER_BYTES));
	

	macroDef1951->arr[0] = sin(tz_dps);;

	macroDef1951->arr[1] = cos(tz_dps);;

	macroDef1951->arr[2] = 0;;;

	macroDef1953->arr[1] = macroDef1951;;stgVar1895_offsetVar += VECTOR_ALL_BYTES(macroDef1953->arr[1]->length);storage_t stgVar1904 = STG_OFFSET(stgVar1895, MATRIX_HEADER_BYTES(3) + stgVar1895_offsetVar);array_number_t macroDef1952 = (array_number_t)stgVar1904;
	macroDef1952->length=3;
	macroDef1952->arr=(number_t*)(STG_OFFSET(stgVar1904, VECTOR_HEADER_BYTES));
	

	macroDef1952->arr[0] = 0;;

	macroDef1952->arr[1] = 0;;

	macroDef1952->arr[2] = 1;;;

	macroDef1953->arr[2] = macroDef1952;;stgVar1895_offsetVar += VECTOR_ALL_BYTES(macroDef1953->arr[2]->length);;
	array_array_number_t Rz_dps = macroDef1953;
	card_t size1958 = width_matrix_shape_t(TOP_LEVEL_linalg_matrixMult_shp(Ry_shp, Rx_shp));
	array_number_t stgVar1909 = storage_alloc(size1958);
	array_array_number_t macroDef1954;
	macroDef1954 = TOP_LEVEL_linalg_matrixMult_dps(stgVar1862, Rz_dps, TOP_LEVEL_linalg_matrixMult_dps(stgVar1909, Ry_dps, Rx_dps, Ry_shp, Rx_shp), Rz_shp, TOP_LEVEL_linalg_matrixMult_shp(Ry_shp, Rx_shp));;
	storage_free(stgVar1909, size1958);
	macroDef1955 = macroDef1954;;
	storage_free(stgVar1895, size1959);
	macroDef1956 = macroDef1955;;
	storage_free(stgVar1882, size1960);
	macroDef1957 = macroDef1956;;
	storage_free(stgVar1869, size1961);
	return macroDef1957;
}

matrix_shape_t TOP_LEVEL_usecases_ht_make_relative_shp(card_t pose_params_shp, matrix_shape_t base_relative_shp) {
	
	return TOP_LEVEL_linalg_matrixMult_shp(base_relative_shp, TOP_LEVEL_linalg_matrixConcat_shp(TOP_LEVEL_linalg_matrixConcatCol_shp(TOP_LEVEL_usecases_ht_euler_angles_to_rotation_matrix_shp(pose_params_shp), nested_shape_card_t(1, 3)), nested_shape_card_t(4, 1)));
}


array_array_number_t TOP_LEVEL_usecases_ht_make_relative_dps(storage_t stgVar1962, array_number_t pose_params_dps, array_array_number_t base_relative_dps, card_t pose_params_shp, matrix_shape_t base_relative_shp) {
	matrix_shape_t R_shp = TOP_LEVEL_usecases_ht_euler_angles_to_rotation_matrix_shp(pose_params_shp);
	card_t size2012 = width_matrix_shape_t(R_shp);
	array_number_t stgVar1963 = storage_alloc(size2012);
	array_array_number_t macroDef2007;array_array_number_t R_dps = TOP_LEVEL_usecases_ht_euler_angles_to_rotation_matrix_dps(stgVar1963, pose_params_dps, pose_params_shp);
	matrix_shape_t r1_shp = nested_shape_card_t(1, 3);
	card_t size2011 = width_matrix_shape_t(r1_shp);
	array_number_t stgVar1965 = storage_alloc(size2011);
	array_array_number_t macroDef2006;array_array_number_t macroDef2000 = (array_array_number_t)stgVar1965;
	macroDef2000->length=3;
	macroDef2000->arr=(array_number_t*)(STG_OFFSET(stgVar1965, VECTOR_HEADER_BYTES));
	int stgVar1965_offsetVar = 0;storage_t stgVar1966 = STG_OFFSET(stgVar1965, MATRIX_HEADER_BYTES(3) + stgVar1965_offsetVar);array_number_t macroDef1997 = (array_number_t)stgVar1966;
	macroDef1997->length=1;
	macroDef1997->arr=(number_t*)(STG_OFFSET(stgVar1966, VECTOR_HEADER_BYTES));
	

	macroDef1997->arr[0] = 0;;;

	macroDef2000->arr[0] = macroDef1997;;stgVar1965_offsetVar += VECTOR_ALL_BYTES(macroDef2000->arr[0]->length);storage_t stgVar1968 = STG_OFFSET(stgVar1965, MATRIX_HEADER_BYTES(3) + stgVar1965_offsetVar);array_number_t macroDef1998 = (array_number_t)stgVar1968;
	macroDef1998->length=1;
	macroDef1998->arr=(number_t*)(STG_OFFSET(stgVar1968, VECTOR_HEADER_BYTES));
	

	macroDef1998->arr[0] = 0;;;

	macroDef2000->arr[1] = macroDef1998;;stgVar1965_offsetVar += VECTOR_ALL_BYTES(macroDef2000->arr[1]->length);storage_t stgVar1970 = STG_OFFSET(stgVar1965, MATRIX_HEADER_BYTES(3) + stgVar1965_offsetVar);array_number_t macroDef1999 = (array_number_t)stgVar1970;
	macroDef1999->length=1;
	macroDef1999->arr=(number_t*)(STG_OFFSET(stgVar1970, VECTOR_HEADER_BYTES));
	

	macroDef1999->arr[0] = 0;;;

	macroDef2000->arr[2] = macroDef1999;;stgVar1965_offsetVar += VECTOR_ALL_BYTES(macroDef2000->arr[2]->length);;
	array_array_number_t r1_dps = macroDef2000;
	matrix_shape_t r2_shp = nested_shape_card_t(4, 1);
	card_t size2010 = width_matrix_shape_t(r2_shp);
	array_number_t stgVar1972 = storage_alloc(size2010);
	array_array_number_t macroDef2005;array_array_number_t macroDef2002 = (array_array_number_t)stgVar1972;
	macroDef2002->length=1;
	macroDef2002->arr=(array_number_t*)(STG_OFFSET(stgVar1972, VECTOR_HEADER_BYTES));
	int stgVar1972_offsetVar = 0;storage_t stgVar1973 = STG_OFFSET(stgVar1972, MATRIX_HEADER_BYTES(1) + stgVar1972_offsetVar);array_number_t macroDef2001 = (array_number_t)stgVar1973;
	macroDef2001->length=4;
	macroDef2001->arr=(number_t*)(STG_OFFSET(stgVar1973, VECTOR_HEADER_BYTES));
	

	macroDef2001->arr[0] = 0;;

	macroDef2001->arr[1] = 0;;

	macroDef2001->arr[2] = 0;;

	macroDef2001->arr[3] = 1;;;

	macroDef2002->arr[0] = macroDef2001;;stgVar1972_offsetVar += VECTOR_ALL_BYTES(macroDef2002->arr[0]->length);;
	array_array_number_t r2_dps = macroDef2002;
	matrix_shape_t T_shp = TOP_LEVEL_linalg_matrixConcat_shp(TOP_LEVEL_linalg_matrixConcatCol_shp(R_shp, r1_shp), r2_shp);
	card_t size2009 = width_matrix_shape_t(T_shp);
	array_number_t stgVar1978 = storage_alloc(size2009);
	array_array_number_t macroDef2004;card_t size2008 = width_matrix_shape_t(TOP_LEVEL_linalg_matrixConcatCol_shp(R_shp, r1_shp));
	array_number_t stgVar1979 = storage_alloc(size2008);
	array_array_number_t macroDef2003;
	macroDef2003 = TOP_LEVEL_linalg_matrixConcat_dps(stgVar1978, TOP_LEVEL_linalg_matrixConcatCol_dps(stgVar1979, R_dps, r1_dps, R_shp, r1_shp), r2_dps, TOP_LEVEL_linalg_matrixConcatCol_shp(R_shp, r1_shp), r2_shp);;
	storage_free(stgVar1979, size2008);
	array_array_number_t T_dps = macroDef2003;
	macroDef2004 = TOP_LEVEL_linalg_matrixMult_dps(stgVar1962, base_relative_dps, T_dps, base_relative_shp, T_shp);;
	storage_free(stgVar1978, size2009);
	macroDef2005 = macroDef2004;;
	storage_free(stgVar1972, size2010);
	macroDef2006 = macroDef2005;;
	storage_free(stgVar1965, size2011);
	macroDef2007 = macroDef2006;;
	storage_free(stgVar1963, size2012);
	return macroDef2007;
}
typedef struct env_t_2029 {
	matrix_shape_t pose_params_shp;
	matrix3d_shape_t base_relatives_shp;
} env_t_2029;
env_t_2029 make_env_t_2029(matrix_shape_t pose_params_shp,matrix3d_shape_t base_relatives_shp) {
	env_t_2029 env;
	env.pose_params_shp = pose_params_shp;
	env.base_relatives_shp = base_relatives_shp;
	return env;
}

value_t lambda2029(env_t_2029* env2026, card_t i_bone_shp) {
	matrix_shape_t pose_params_shp2025 = env2026->pose_params_shp;
	matrix3d_shape_t base_relatives_shp2024 = env2026->base_relatives_shp;
	value_t res;
	res.matrix_shape_t_value = TOP_LEVEL_usecases_ht_make_relative_shp(pose_params_shp2025.elem, base_relatives_shp2024.elem);
	return res;
}
matrix3d_shape_t TOP_LEVEL_usecases_ht_get_posed_relatives_shp(card_t n_bones_shp, matrix_shape_t pose_params_shp, matrix3d_shape_t base_relatives_shp) {
	env_t_2029 env_t_2029_value = make_env_t_2029(pose_params_shp,base_relatives_shp); closure_t closure2028 = make_closure(lambda2029, &env_t_2029_value);
	return TOP_LEVEL_linalg_vectorMapToMatrix3D_shp(closure2028, TOP_LEVEL_linalg_vectorRange_shp(0, (n_bones_shp) - (1)));
}

typedef struct env_t_2046 {
	matrix_shape_t pose_params_shp;
	array_array_number_t pose_params_dps;
	index_t offset_dps;
	matrix3d_shape_t base_relatives_shp;
	array_array_array_number_t base_relatives_dps;
} env_t_2046;
env_t_2046 make_env_t_2046(matrix_shape_t pose_params_shp,array_array_number_t pose_params_dps,index_t offset_dps,matrix3d_shape_t base_relatives_shp,array_array_array_number_t base_relatives_dps) {
	env_t_2046 env;
	env.pose_params_shp = pose_params_shp;
	env.pose_params_dps = pose_params_dps;
	env.offset_dps = offset_dps;
	env.base_relatives_shp = base_relatives_shp;
	env.base_relatives_dps = base_relatives_dps;
	return env;
}

value_t lambda2046(env_t_2046* env2037, storage_t stgVar2017, number_t i_bone_dps, card_t i_bone_shp) {
	matrix_shape_t pose_params_shp2036 = env2037->pose_params_shp;
	array_array_number_t pose_params_dps2035 = env2037->pose_params_dps;
	index_t offset_dps2034 = env2037->offset_dps;
	matrix3d_shape_t base_relatives_shp2033 = env2037->base_relatives_shp;
	array_array_array_number_t base_relatives_dps2032 = env2037->base_relatives_dps;
	card_t size2048 = width_matrix_shape_t(base_relatives_shp2033.elem);
	array_number_t stgVar2019 = storage_alloc(size2048);
	array_array_number_t macroDef2031;card_t size2047 = width_card_t(pose_params_shp2036.elem);
	array_number_t stgVar2018 = storage_alloc(size2047);
	array_array_number_t macroDef2030;
	macroDef2030 = TOP_LEVEL_usecases_ht_make_relative_dps(stgVar2017, pose_params_dps2035->arr[((int)(i_bone_dps)) + (offset_dps2034)], base_relatives_dps2032->arr[(int)(i_bone_dps)], pose_params_shp2036.elem, base_relatives_shp2033.elem);;
	storage_free(stgVar2018, size2047);
	macroDef2031 = macroDef2030;;
	storage_free(stgVar2019, size2048);
	value_t res;
	res.array_array_number_t_value = macroDef2031;
	return res;
}
typedef struct env_t_2049 {
	matrix_shape_t pose_params_shp;
	matrix3d_shape_t base_relatives_shp;
} env_t_2049;
env_t_2049 make_env_t_2049(matrix_shape_t pose_params_shp,matrix3d_shape_t base_relatives_shp) {
	env_t_2049 env;
	env.pose_params_shp = pose_params_shp;
	env.base_relatives_shp = base_relatives_shp;
	return env;
}

value_t lambda2049(env_t_2049* env2042, card_t i_bone_shp) {
	matrix_shape_t pose_params_shp2041 = env2042->pose_params_shp;
	matrix3d_shape_t base_relatives_shp2040 = env2042->base_relatives_shp;
	value_t res;
	res.matrix_shape_t_value = TOP_LEVEL_usecases_ht_make_relative_shp(pose_params_shp2041.elem, base_relatives_shp2040.elem);
	return res;
}
array_array_array_number_t TOP_LEVEL_usecases_ht_get_posed_relatives_dps(storage_t stgVar2013, card_t n_bones_dps, array_array_number_t pose_params_dps, array_array_array_number_t base_relatives_dps, card_t n_bones_shp, matrix_shape_t pose_params_shp, matrix3d_shape_t base_relatives_shp) {
	card_t offset_shp = 0;
	index_t offset_dps = 3;
	card_t size2050 = width_card_t(TOP_LEVEL_linalg_vectorRange_shp(0, (n_bones_shp) - (1)));
	array_number_t stgVar2016 = storage_alloc(size2050);
	array_array_array_number_t macroDef2045;env_t_2046 env_t_2046_value = make_env_t_2046(pose_params_shp,pose_params_dps,offset_dps,base_relatives_shp,base_relatives_dps); closure_t closure2039 = make_closure(lambda2046, &env_t_2046_value);
	env_t_2049 env_t_2049_value = make_env_t_2049(pose_params_shp,base_relatives_shp); closure_t closure2044 = make_closure(lambda2049, &env_t_2049_value);
	macroDef2045 = TOP_LEVEL_linalg_vectorMapToMatrix3D_dps(stgVar2013, closure2039, TOP_LEVEL_linalg_vectorRange_dps(stgVar2016, 0, (n_bones_dps) - (1), 0, (n_bones_shp) - (1)), closure2044, TOP_LEVEL_linalg_vectorRange_shp(0, (n_bones_shp) - (1)));;
	storage_free(stgVar2016, size2050);
	return macroDef2045;
}

matrix_shape_t TOP_LEVEL_usecases_ht_angle_axis_to_rotation_matrix_shp(card_t angle_axis_shp) {
	
	return nested_shape_card_t(3, 3);
}


array_array_number_t TOP_LEVEL_usecases_ht_angle_axis_to_rotation_matrix_dps(storage_t stgVar2051, array_number_t angle_axis_dps, card_t angle_axis_shp) {
	card_t n_shp = 0;
	number_t n_dps = sqrt(TOP_LEVEL_linalg_sqnorm_dps(empty_storage, angle_axis_dps, angle_axis_shp));
	array_array_number_t ite2094 = 0;
	if((n_dps) < (0.0001)) {
		array_array_number_t macroDef2089 = (array_array_number_t)stgVar2051;
	macroDef2089->length=3;
	macroDef2089->arr=(array_number_t*)(STG_OFFSET(stgVar2051, VECTOR_HEADER_BYTES));
	int stgVar2051_offsetVar = 0;storage_t stgVar2054 = STG_OFFSET(stgVar2051, MATRIX_HEADER_BYTES(3) + stgVar2051_offsetVar);array_number_t macroDef2086 = (array_number_t)stgVar2054;
	macroDef2086->length=3;
	macroDef2086->arr=(number_t*)(STG_OFFSET(stgVar2054, VECTOR_HEADER_BYTES));
	

	macroDef2086->arr[0] = 1;;

	macroDef2086->arr[1] = 0;;

	macroDef2086->arr[2] = 0;;;

	macroDef2089->arr[0] = macroDef2086;;stgVar2051_offsetVar += VECTOR_ALL_BYTES(macroDef2089->arr[0]->length);storage_t stgVar2058 = STG_OFFSET(stgVar2051, MATRIX_HEADER_BYTES(3) + stgVar2051_offsetVar);array_number_t macroDef2087 = (array_number_t)stgVar2058;
	macroDef2087->length=3;
	macroDef2087->arr=(number_t*)(STG_OFFSET(stgVar2058, VECTOR_HEADER_BYTES));
	

	macroDef2087->arr[0] = 0;;

	macroDef2087->arr[1] = 1;;

	macroDef2087->arr[2] = 0;;;

	macroDef2089->arr[1] = macroDef2087;;stgVar2051_offsetVar += VECTOR_ALL_BYTES(macroDef2089->arr[1]->length);storage_t stgVar2062 = STG_OFFSET(stgVar2051, MATRIX_HEADER_BYTES(3) + stgVar2051_offsetVar);array_number_t macroDef2088 = (array_number_t)stgVar2062;
	macroDef2088->length=3;
	macroDef2088->arr=(number_t*)(STG_OFFSET(stgVar2062, VECTOR_HEADER_BYTES));
	

	macroDef2088->arr[0] = 0;;

	macroDef2088->arr[1] = 0;;

	macroDef2088->arr[2] = 1;;;

	macroDef2089->arr[2] = macroDef2088;;stgVar2051_offsetVar += VECTOR_ALL_BYTES(macroDef2089->arr[2]->length);;
		ite2094 = macroDef2089;;
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
		array_array_number_t macroDef2093 = (array_array_number_t)stgVar2051;
	macroDef2093->length=3;
	macroDef2093->arr=(array_number_t*)(STG_OFFSET(stgVar2051, VECTOR_HEADER_BYTES));
	int stgVar2051_offsetVar = 0;storage_t stgVar2074 = STG_OFFSET(stgVar2051, MATRIX_HEADER_BYTES(3) + stgVar2051_offsetVar);array_number_t macroDef2090 = (array_number_t)stgVar2074;
	macroDef2090->length=3;
	macroDef2090->arr=(number_t*)(STG_OFFSET(stgVar2074, VECTOR_HEADER_BYTES));
	

	macroDef2090->arr[0] = ((x_dps) * (x_dps)) + (((1) - ((x_dps) * (x_dps))) * (c_dps));;

	macroDef2090->arr[1] = (((x_dps) * (y_dps)) * ((1) - (c_dps))) - ((z_dps) * (s_dps));;

	macroDef2090->arr[2] = (((x_dps) * (z_dps)) * ((1) - (c_dps))) + ((y_dps) * (s_dps));;;

	macroDef2093->arr[0] = macroDef2090;;stgVar2051_offsetVar += VECTOR_ALL_BYTES(macroDef2093->arr[0]->length);storage_t stgVar2078 = STG_OFFSET(stgVar2051, MATRIX_HEADER_BYTES(3) + stgVar2051_offsetVar);array_number_t macroDef2091 = (array_number_t)stgVar2078;
	macroDef2091->length=3;
	macroDef2091->arr=(number_t*)(STG_OFFSET(stgVar2078, VECTOR_HEADER_BYTES));
	

	macroDef2091->arr[0] = (((x_dps) * (y_dps)) * ((1) - (c_dps))) + ((z_dps) * (s_dps));;

	macroDef2091->arr[1] = ((y_dps) * (y_dps)) + (((1) - ((y_dps) * (y_dps))) * (c_dps));;

	macroDef2091->arr[2] = (((y_dps) * (z_dps)) * ((1) - (c_dps))) - ((x_dps) * (s_dps));;;

	macroDef2093->arr[1] = macroDef2091;;stgVar2051_offsetVar += VECTOR_ALL_BYTES(macroDef2093->arr[1]->length);storage_t stgVar2082 = STG_OFFSET(stgVar2051, MATRIX_HEADER_BYTES(3) + stgVar2051_offsetVar);array_number_t macroDef2092 = (array_number_t)stgVar2082;
	macroDef2092->length=3;
	macroDef2092->arr=(number_t*)(STG_OFFSET(stgVar2082, VECTOR_HEADER_BYTES));
	

	macroDef2092->arr[0] = (((x_dps) * (z_dps)) * ((1) - (c_dps))) - ((y_dps) * (s_dps));;

	macroDef2092->arr[1] = (((z_dps) * (y_dps)) * ((1) - (c_dps))) + ((x_dps) * (s_dps));;

	macroDef2092->arr[2] = ((z_dps) * (z_dps)) + (((1) - ((z_dps) * (z_dps))) * (c_dps));;;

	macroDef2093->arr[2] = macroDef2092;;stgVar2051_offsetVar += VECTOR_ALL_BYTES(macroDef2093->arr[2]->length);;
		ite2094 = macroDef2093;;
	}
	return ite2094;
}

matrix3d_shape_t TOP_LEVEL_usecases_ht_relatives_to_absolutes_shp(matrix3d_shape_t relatives_shp, card_t parents_shp) {
	
	return relatives_shp;
}


array_array_array_number_t TOP_LEVEL_usecases_ht_relatives_to_absolutes_dps(storage_t stgVar2095, array_array_array_number_t relatives_dps, array_number_t parents_dps, matrix3d_shape_t relatives_shp, card_t parents_shp) {
	matrix3d_shape_t init_shp = relatives_shp;
	array_array_array_number_t init_dps = relatives_dps;
	card_t anfvar2097_shp = (relatives_shp.card) - (1);
	card_t macroDef2122 = relatives_dps->length;
	card_t anfvar2097_dps = (macroDef2122) - (1);
	card_t anfvar2098_shp = 0;
	card_t anfvar2098_dps = 0;
	array_array_array_number_t macroDef2129 = init_dps;
	storage_t stgVar2102 = stgVar2095;
	for(int i_dps = anfvar2098_dps; i_dps <= anfvar2097_dps; i_dps++){
		array_array_array_number_t ite2130 = 0;
	if((parents_dps->arr[i_dps]) == (-1)) {
		matrix3d_shape_t newMatrix_shp = nested_shape_matrix_shape_t(relatives_shp.elem, 1);
		card_t size2131 = width_matrix3d_shape_t(newMatrix_shp);
	array_number_t stgVar2104 = storage_alloc(size2131);
	array_array_array_number_t macroDef2124;array_array_array_number_t macroDef2123 = (array_array_array_number_t)stgVar2104;
	macroDef2123->length=1;
	macroDef2123->arr=(array_array_number_t*)(STG_OFFSET(stgVar2104, VECTOR_HEADER_BYTES));
	int stgVar2104_offsetVar = 0;storage_t stgVar2105 = STG_OFFSET(stgVar2104, MATRIX_HEADER_BYTES(1) + stgVar2104_offsetVar);

	macroDef2123->arr[0] = relatives_dps->arr[i_dps];;stgVar2104_offsetVar += VECTOR_ALL_BYTES(macroDef2123->arr[0]->length);;
	array_array_array_number_t newMatrix_dps = macroDef2123;
	macroDef2124 = TOP_LEVEL_usecases_ht_matrix3DUpdate_dps(stgVar2102, macroDef2129, i_dps, (i_dps) + (1), newMatrix_dps, init_shp, 0, 0, newMatrix_shp);;
	storage_free(stgVar2104, size2131);
		ite2130 = macroDef2124;;
	} else {
		matrix3d_shape_t newMatrix_shp = nested_shape_matrix_shape_t(TOP_LEVEL_linalg_matrixMult_shp(init_shp.elem, relatives_shp.elem), 1);
		card_t size2134 = width_matrix3d_shape_t(newMatrix_shp);
	array_number_t stgVar2111 = storage_alloc(size2134);
	array_array_array_number_t macroDef2128;array_array_array_number_t macroDef2127 = (array_array_array_number_t)stgVar2111;
	macroDef2127->length=1;
	macroDef2127->arr=(array_array_number_t*)(STG_OFFSET(stgVar2111, VECTOR_HEADER_BYTES));
	int stgVar2111_offsetVar = 0;storage_t stgVar2112 = STG_OFFSET(stgVar2111, MATRIX_HEADER_BYTES(1) + stgVar2111_offsetVar);card_t size2133 = width_matrix_shape_t(relatives_shp.elem);
	array_number_t stgVar2114 = storage_alloc(size2133);
	array_array_number_t macroDef2126;card_t size2132 = width_matrix_shape_t(init_shp.elem);
	array_number_t stgVar2113 = storage_alloc(size2132);
	array_array_number_t macroDef2125;
	macroDef2125 = TOP_LEVEL_linalg_matrixMult_dps(stgVar2112, macroDef2129->arr[(int)(parents_dps->arr[i_dps])], relatives_dps->arr[i_dps], init_shp.elem, relatives_shp.elem);;
	storage_free(stgVar2113, size2132);
	macroDef2126 = macroDef2125;;
	storage_free(stgVar2114, size2133);

	macroDef2127->arr[0] = macroDef2126;;stgVar2111_offsetVar += VECTOR_ALL_BYTES(macroDef2127->arr[0]->length);;
	array_array_array_number_t newMatrix_dps = macroDef2127;
	macroDef2128 = TOP_LEVEL_usecases_ht_matrix3DUpdate_dps(stgVar2102, macroDef2129, i_dps, (i_dps) + (1), newMatrix_dps, init_shp, 0, 0, newMatrix_shp);;
	storage_free(stgVar2111, size2134);
		ite2130 = macroDef2128;;
	}
		macroDef2129 = ite2130;;
	}
	return macroDef2129;
}
typedef struct env_t_2204 {
	matrix_shape_t pose_params_shp;
} env_t_2204;
env_t_2204 make_env_t_2204(matrix_shape_t pose_params_shp) {
	env_t_2204 env;
	env.pose_params_shp = pose_params_shp;
	return env;
}

value_t lambda2204(env_t_2204* env2198, card_t row_shp) {
	matrix_shape_t pose_params_shp2197 = env2198->pose_params_shp;
	value_t res;
	res.card_t_value = TOP_LEVEL_linalg_mult_vec_elementwise_shp(row_shp, pose_params_shp2197.elem);
	return res;
}
typedef empty_env_t env_t_2205;


value_t lambda2205(env_t_2205* env2201, card_t x_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
matrix_shape_t TOP_LEVEL_usecases_ht_apply_global_transform_shp(matrix_shape_t pose_params_shp, matrix_shape_t positions_shp) {
	env_t_2204 env_t_2204_value = make_env_t_2204(pose_params_shp); closure_t closure2200 = make_closure(lambda2204, &env_t_2204_value);
	env_t_2205 env_t_2205_value = make_empty_env(); closure_t closure2203 = make_closure(lambda2205, &env_t_2205_value);
	return TOP_LEVEL_linalg_matrixMult_shp(TOP_LEVEL_linalg_matrixConcatCol_shp(TOP_LEVEL_linalg_matrixMap_shp(closure2200, TOP_LEVEL_usecases_ht_angle_axis_to_rotation_matrix_shp(pose_params_shp.elem)), TOP_LEVEL_linalg_matrixTranspose_shp(nested_shape_card_t(pose_params_shp.elem, 1))), TOP_LEVEL_linalg_matrixConcat_shp(positions_shp, nested_shape_card_t(TOP_LEVEL_linalg_vectorMap_shp(closure2203, TOP_LEVEL_linalg_vectorRange_shp(1, positions_shp.elem)), 1)));
}

typedef struct env_t_2244 {
	card_t scale_shp;
} env_t_2244;
env_t_2244 make_env_t_2244(card_t scale_shp) {
	env_t_2244 env;
	env.scale_shp = scale_shp;
	return env;
}

value_t lambda2244(env_t_2244* env2208, card_t row_shp) {
	card_t scale_shp2207 = env2208->scale_shp;
	value_t res;
	res.card_t_value = TOP_LEVEL_linalg_mult_vec_elementwise_shp(row_shp, scale_shp2207);
	return res;
}
typedef struct env_t_2245 {
	card_t scale_shp;
	array_number_t scale_dps;
} env_t_2245;
env_t_2245 make_env_t_2245(card_t scale_shp,array_number_t scale_dps) {
	env_t_2245 env;
	env.scale_shp = scale_shp;
	env.scale_dps = scale_dps;
	return env;
}

value_t lambda2245(env_t_2245* env2213, storage_t stgVar2144, array_number_t row_dps, card_t row_shp) {
	card_t scale_shp2212 = env2213->scale_shp;
	array_number_t scale_dps2211 = env2213->scale_dps;
	value_t res;
	res.array_number_t_value = TOP_LEVEL_linalg_mult_vec_elementwise_dps(stgVar2144, row_dps, scale_dps2211, row_shp, scale_shp2212);
	return res;
}
typedef struct env_t_2246 {
	card_t scale_shp;
} env_t_2246;
env_t_2246 make_env_t_2246(card_t scale_shp) {
	env_t_2246 env;
	env.scale_shp = scale_shp;
	return env;
}

value_t lambda2246(env_t_2246* env2217, card_t row_shp) {
	card_t scale_shp2216 = env2217->scale_shp;
	value_t res;
	res.card_t_value = TOP_LEVEL_linalg_mult_vec_elementwise_shp(row_shp, scale_shp2216);
	return res;
}
typedef empty_env_t env_t_2249;


value_t lambda2249(env_t_2249* env2223, card_t x_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef empty_env_t env_t_2250;


value_t lambda2250(env_t_2250* env2226, storage_t stgVar2156, number_t x_dps, card_t x_shp) {
	
	value_t res;
	res.number_t_value = 1;
	return res;
}
typedef empty_env_t env_t_2252;


value_t lambda2252(env_t_2252* env2231, card_t x_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
array_array_number_t TOP_LEVEL_usecases_ht_apply_global_transform_dps(storage_t stgVar2135, array_array_number_t pose_params_dps, array_array_number_t positions_dps, matrix_shape_t pose_params_shp, matrix_shape_t positions_shp) {
	matrix_shape_t R_shp = TOP_LEVEL_usecases_ht_angle_axis_to_rotation_matrix_shp(pose_params_shp.elem);
	card_t size2260 = width_matrix_shape_t(R_shp);
	array_number_t stgVar2136 = storage_alloc(size2260);
	array_array_number_t macroDef2242;card_t size2243 = width_card_t(pose_params_shp.elem);
	array_number_t stgVar2137 = storage_alloc(size2243);
	array_array_number_t macroDef2206;
	macroDef2206 = TOP_LEVEL_usecases_ht_angle_axis_to_rotation_matrix_dps(stgVar2136, pose_params_dps->arr[0], pose_params_shp.elem);;
	storage_free(stgVar2137, size2243);
	array_array_number_t R_dps = macroDef2206;
	card_t scale_shp = pose_params_shp.elem;
	card_t size2259 = width_card_t(scale_shp);
	array_number_t stgVar2139 = storage_alloc(size2259);
	array_array_number_t macroDef2241;array_number_t scale_dps = pose_params_dps->arr[1];
	env_t_2244 env_t_2244_value = make_env_t_2244(scale_shp); closure_t closure2210 = make_closure(lambda2244, &env_t_2244_value);
	matrix_shape_t R1_shp = TOP_LEVEL_linalg_matrixMap_shp(closure2210, R_shp);
	card_t size2258 = width_matrix_shape_t(R1_shp);
	array_number_t stgVar2141 = storage_alloc(size2258);
	array_array_number_t macroDef2240;env_t_2245 env_t_2245_value = make_env_t_2245(scale_shp,scale_dps); closure_t closure2215 = make_closure(lambda2245, &env_t_2245_value);
	env_t_2246 env_t_2246_value = make_env_t_2246(scale_shp); closure_t closure2219 = make_closure(lambda2246, &env_t_2246_value);
	array_array_number_t R1_dps = TOP_LEVEL_linalg_matrixMap_dps(stgVar2141, closure2215, R_dps, closure2219, R_shp);
	matrix_shape_t T_shp = TOP_LEVEL_linalg_matrixConcatCol_shp(R1_shp, TOP_LEVEL_linalg_matrixTranspose_shp(nested_shape_card_t(pose_params_shp.elem, 1)));
	card_t size2257 = width_matrix_shape_t(T_shp);
	array_number_t stgVar2147 = storage_alloc(size2257);
	array_array_number_t macroDef2239;card_t size2248 = width_matrix_shape_t(TOP_LEVEL_linalg_matrixTranspose_shp(nested_shape_card_t(pose_params_shp.elem, 1)));
	array_number_t stgVar2149 = storage_alloc(size2248);
	array_array_number_t macroDef2222;card_t size2247 = width_matrix_shape_t(nested_shape_card_t(pose_params_shp.elem, 1));
	array_number_t stgVar2150 = storage_alloc(size2247);
	array_array_number_t macroDef2221;array_array_number_t macroDef2220 = (array_array_number_t)stgVar2150;
	macroDef2220->length=1;
	macroDef2220->arr=(array_number_t*)(STG_OFFSET(stgVar2150, VECTOR_HEADER_BYTES));
	int stgVar2150_offsetVar = 0;storage_t stgVar2151 = STG_OFFSET(stgVar2150, MATRIX_HEADER_BYTES(1) + stgVar2150_offsetVar);

	macroDef2220->arr[0] = pose_params_dps->arr[2];;stgVar2150_offsetVar += VECTOR_ALL_BYTES(macroDef2220->arr[0]->length);;
	macroDef2221 = TOP_LEVEL_linalg_matrixTranspose_dps(stgVar2149, macroDef2220, nested_shape_card_t(pose_params_shp.elem, 1));;
	storage_free(stgVar2150, size2247);
	macroDef2222 = TOP_LEVEL_linalg_matrixConcatCol_dps(stgVar2147, R1_dps, macroDef2221, R1_shp, TOP_LEVEL_linalg_matrixTranspose_shp(nested_shape_card_t(pose_params_shp.elem, 1)));;
	storage_free(stgVar2149, size2248);
	array_array_number_t T_dps = macroDef2222;
	env_t_2249 env_t_2249_value = make_empty_env(); closure_t closure2225 = make_closure(lambda2249, &env_t_2249_value);
	card_t ones_shp = TOP_LEVEL_linalg_vectorMap_shp(closure2225, TOP_LEVEL_linalg_vectorRange_shp(1, positions_shp.elem));
	card_t size2256 = width_card_t(ones_shp);
	array_number_t stgVar2153 = storage_alloc(size2256);
	array_array_number_t macroDef2238;card_t size2253 = width_card_t(TOP_LEVEL_linalg_vectorRange_shp(1, positions_shp.elem));
	array_number_t stgVar2155 = storage_alloc(size2253);
	array_number_t macroDef2234;env_t_2250 env_t_2250_value = make_empty_env(); closure_t closure2228 = make_closure(lambda2250, &env_t_2250_value);
	card_t size2251 = width_card_t(positions_shp.elem);
	array_number_t stgVar2159 = storage_alloc(size2251);
	card_t macroDef2230;card_t macroDef2229 = positions_dps->arr[0]->length;
	macroDef2230 = macroDef2229;;
	storage_free(stgVar2159, size2251);
	env_t_2252 env_t_2252_value = make_empty_env(); closure_t closure2233 = make_closure(lambda2252, &env_t_2252_value);
	macroDef2234 = TOP_LEVEL_linalg_vectorMap_dps(stgVar2153, closure2228, TOP_LEVEL_linalg_vectorRange_dps(stgVar2155, 1, macroDef2230, 1, positions_shp.elem), closure2233, TOP_LEVEL_linalg_vectorRange_shp(1, positions_shp.elem));;
	storage_free(stgVar2155, size2253);
	array_number_t ones_dps = macroDef2234;
	matrix_shape_t positions_homog_shp = TOP_LEVEL_linalg_matrixConcat_shp(positions_shp, nested_shape_card_t(ones_shp, 1));
	card_t size2255 = width_matrix_shape_t(positions_homog_shp);
	array_number_t stgVar2161 = storage_alloc(size2255);
	array_array_number_t macroDef2237;card_t size2254 = width_matrix_shape_t(nested_shape_card_t(ones_shp, 1));
	array_number_t stgVar2163 = storage_alloc(size2254);
	array_array_number_t macroDef2236;array_array_number_t macroDef2235 = (array_array_number_t)stgVar2163;
	macroDef2235->length=1;
	macroDef2235->arr=(array_number_t*)(STG_OFFSET(stgVar2163, VECTOR_HEADER_BYTES));
	int stgVar2163_offsetVar = 0;storage_t stgVar2164 = STG_OFFSET(stgVar2163, MATRIX_HEADER_BYTES(1) + stgVar2163_offsetVar);

	macroDef2235->arr[0] = ones_dps;;stgVar2163_offsetVar += VECTOR_ALL_BYTES(macroDef2235->arr[0]->length);;
	macroDef2236 = TOP_LEVEL_linalg_matrixConcat_dps(stgVar2161, positions_dps, macroDef2235, positions_shp, nested_shape_card_t(ones_shp, 1));;
	storage_free(stgVar2163, size2254);
	array_array_number_t positions_homog_dps = macroDef2236;
	macroDef2237 = TOP_LEVEL_linalg_matrixMult_dps(stgVar2135, T_dps, positions_homog_dps, T_shp, positions_homog_shp);;
	storage_free(stgVar2161, size2255);
	macroDef2238 = macroDef2237;;
	storage_free(stgVar2153, size2256);
	macroDef2239 = macroDef2238;;
	storage_free(stgVar2147, size2257);
	macroDef2240 = macroDef2239;;
	storage_free(stgVar2141, size2258);
	macroDef2241 = macroDef2240;;
	storage_free(stgVar2139, size2259);
	macroDef2242 = macroDef2241;;
	storage_free(stgVar2136, size2260);
	return macroDef2242;
}

matrix_shape_t TOP_LEVEL_usecases_ht_get_skinned_vertex_positions_shp(card_t is_mirrored_shp, card_t n_bones_shp, matrix_shape_t pose_params_shp, matrix3d_shape_t base_relatives_shp, card_t parents_shp, matrix3d_shape_t inverse_base_absolutes_shp, matrix_shape_t base_positions_shp, matrix_shape_t weights_shp) {
	
	return TOP_LEVEL_usecases_ht_apply_global_transform_shp(pose_params_shp, TOP_LEVEL_linalg_matrixMult_shp(nested_shape_card_t(3, 3), TOP_LEVEL_linalg_matrixFill_shp(3, base_positions_shp.elem, 0)));
}

typedef empty_env_t env_t_2409;


value_t lambda2409(env_t_2409* env2378, matrix_shape_t m1_shp, matrix_shape_t m2_shp) {
	
	value_t res;
	res.matrix_shape_t_value = TOP_LEVEL_linalg_matrixMult_shp(m1_shp, m2_shp);
	return res;
}
typedef empty_env_t env_t_2410;


value_t lambda2410(env_t_2410* env2381, storage_t stgVar2273, array_array_number_t m1_dps, array_array_number_t m2_dps, matrix_shape_t m1_shp, matrix_shape_t m2_shp) {
	
	value_t res;
	res.array_array_number_t_value = TOP_LEVEL_linalg_matrixMult_dps(stgVar2273, m1_dps, m2_dps, m1_shp, m2_shp);
	return res;
}
typedef empty_env_t env_t_2411;


value_t lambda2411(env_t_2411* env2384, matrix_shape_t m1_shp, matrix_shape_t m2_shp) {
	
	value_t res;
	res.matrix_shape_t_value = TOP_LEVEL_linalg_matrixMult_shp(m1_shp, m2_shp);
	return res;
}
array_array_number_t TOP_LEVEL_usecases_ht_get_skinned_vertex_positions_dps(storage_t stgVar2261, index_t is_mirrored_dps, card_t n_bones_dps, array_array_number_t pose_params_dps, array_array_array_number_t base_relatives_dps, array_number_t parents_dps, array_array_array_number_t inverse_base_absolutes_dps, array_array_number_t base_positions_dps, array_array_number_t weights_dps, card_t is_mirrored_shp, card_t n_bones_shp, matrix_shape_t pose_params_shp, matrix3d_shape_t base_relatives_shp, card_t parents_shp, matrix3d_shape_t inverse_base_absolutes_shp, matrix_shape_t base_positions_shp, matrix_shape_t weights_shp) {
	matrix3d_shape_t relatives_shp = TOP_LEVEL_usecases_ht_get_posed_relatives_shp(n_bones_shp, pose_params_shp, base_relatives_shp);
	card_t size2425 = width_matrix3d_shape_t(relatives_shp);
	array_number_t stgVar2262 = storage_alloc(size2425);
	array_array_number_t macroDef2408;array_array_array_number_t relatives_dps = TOP_LEVEL_usecases_ht_get_posed_relatives_dps(stgVar2262, n_bones_dps, pose_params_dps, base_relatives_dps, n_bones_shp, pose_params_shp, base_relatives_shp);
	matrix3d_shape_t absolutes_shp = TOP_LEVEL_usecases_ht_relatives_to_absolutes_shp(relatives_shp, parents_shp);
	card_t size2424 = width_matrix3d_shape_t(absolutes_shp);
	array_number_t stgVar2266 = storage_alloc(size2424);
	array_array_number_t macroDef2407;array_array_array_number_t absolutes_dps = TOP_LEVEL_usecases_ht_relatives_to_absolutes_dps(stgVar2266, relatives_dps, parents_dps, relatives_shp, parents_shp);
	env_t_2409 env_t_2409_value = make_empty_env(); closure_t closure2380 = make_closure(lambda2409, &env_t_2409_value);
	matrix3d_shape_t transforms_shp = TOP_LEVEL_linalg_matrix3DMap2_shp(closure2380, absolutes_shp, inverse_base_absolutes_shp);
	card_t size2423 = width_matrix3d_shape_t(transforms_shp);
	array_number_t stgVar2269 = storage_alloc(size2423);
	array_array_number_t macroDef2406;env_t_2410 env_t_2410_value = make_empty_env(); closure_t closure2383 = make_closure(lambda2410, &env_t_2410_value);
	env_t_2411 env_t_2411_value = make_empty_env(); closure_t closure2386 = make_closure(lambda2411, &env_t_2411_value);
	array_array_array_number_t transforms_dps = TOP_LEVEL_linalg_matrix3DMap2_dps(stgVar2269, closure2383, absolutes_dps, inverse_base_absolutes_dps, closure2386, absolutes_shp, inverse_base_absolutes_shp);
	card_t n_verts_shp = base_positions_shp.elem;
	card_t size2412 = width_card_t(base_positions_shp.elem);
	array_number_t stgVar2277 = storage_alloc(size2412);
	card_t macroDef2388;card_t macroDef2387 = base_positions_dps->arr[0]->length;
	macroDef2388 = macroDef2387;;
	storage_free(stgVar2277, size2412);
	card_t n_verts_dps = macroDef2388;
	matrix_shape_t init_positions_shp = TOP_LEVEL_linalg_matrixFill_shp(3, n_verts_shp, 0);
	card_t size2422 = width_matrix_shape_t(init_positions_shp);
	array_number_t stgVar2279 = storage_alloc(size2422);
	array_array_number_t macroDef2405;array_array_number_t init_positions_dps = TOP_LEVEL_linalg_matrixFill_dps(stgVar2279, 3, n_verts_dps, 0, 3, n_verts_shp, 0);
	matrix_shape_t positions_shp = init_positions_shp;
	card_t size2421 = width_matrix_shape_t(positions_shp);
	array_number_t stgVar2283 = storage_alloc(size2421);
	array_array_number_t macroDef2404;card_t anfvar2284_shp = (transforms_shp.card) - (1);
	card_t macroDef2389 = transforms_dps->length;
	card_t anfvar2284_dps = (macroDef2389) - (1);
	card_t anfvar2285_shp = 0;
	card_t anfvar2285_dps = 0;
	array_array_number_t macroDef2397 = init_positions_dps;
	storage_t stgVar2289 = stgVar2283;
	for(int i_transform_dps = anfvar2285_dps; i_transform_dps <= anfvar2284_dps; i_transform_dps++){
		matrix_shape_t curr_positions_shp = TOP_LEVEL_linalg_matrixMult_shp(TOP_LEVEL_linalg_matrixSlice_shp(3, 0, transforms_shp.elem), base_positions_shp);
		card_t size2418 = width_matrix_shape_t(curr_positions_shp);
	array_number_t stgVar2290 = storage_alloc(size2418);
	array_array_number_t macroDef2396;card_t size2414 = width_matrix_shape_t(TOP_LEVEL_linalg_matrixSlice_shp(3, 0, transforms_shp.elem));
	array_number_t stgVar2291 = storage_alloc(size2414);
	array_array_number_t macroDef2391;card_t size2413 = width_matrix_shape_t(transforms_shp.elem);
	array_number_t stgVar2295 = storage_alloc(size2413);
	array_array_number_t macroDef2390;
	macroDef2390 = TOP_LEVEL_linalg_matrixSlice_dps(stgVar2291, 3, 0, transforms_dps->arr[i_transform_dps], 3, 0, transforms_shp.elem);;
	storage_free(stgVar2295, size2413);
	macroDef2391 = TOP_LEVEL_linalg_matrixMult_dps(stgVar2290, macroDef2390, base_positions_dps, TOP_LEVEL_linalg_matrixSlice_shp(3, 0, transforms_shp.elem), base_positions_shp);;
	storage_free(stgVar2291, size2414);
	array_array_number_t curr_positions_dps = macroDef2391;
	matrix_shape_t w_shp = TOP_LEVEL_linalg_matrixFillFromVector_shp(base_positions_shp.card, weights_shp.elem);
	card_t size2417 = width_matrix_shape_t(w_shp);
	array_number_t stgVar2297 = storage_alloc(size2417);
	array_array_number_t macroDef2395;card_t size2415 = width_card_t(weights_shp.elem);
	array_number_t stgVar2299 = storage_alloc(size2415);
	array_array_number_t macroDef2393;card_t macroDef2392 = base_positions_dps->length;
	macroDef2393 = TOP_LEVEL_linalg_matrixFillFromVector_dps(stgVar2297, macroDef2392, weights_dps->arr[i_transform_dps], base_positions_shp.card, weights_shp.elem);;
	storage_free(stgVar2299, size2415);
	array_array_number_t w_dps = macroDef2393;
	card_t size2416 = width_matrix_shape_t(TOP_LEVEL_linalg_matrixMultElementwise_shp(curr_positions_shp, w_shp));
	array_number_t stgVar2303 = storage_alloc(size2416);
	array_array_number_t macroDef2394;
	macroDef2394 = TOP_LEVEL_linalg_matrixAdd_dps(stgVar2289, macroDef2397, TOP_LEVEL_linalg_matrixMultElementwise_dps(stgVar2303, curr_positions_dps, w_dps, curr_positions_shp, w_shp), init_positions_shp, TOP_LEVEL_linalg_matrixMultElementwise_shp(curr_positions_shp, w_shp));;
	storage_free(stgVar2303, size2416);
	macroDef2395 = macroDef2394;;
	storage_free(stgVar2297, size2417);
	macroDef2396 = macroDef2395;;
	storage_free(stgVar2290, size2418);
		macroDef2397 = macroDef2396;;
	}
	array_array_number_t positions_dps = macroDef2397;
	matrix_shape_t mirror_matrix_shp = nested_shape_card_t(3, 3);
	matrix_shape_t mirrored_positions_shp = TOP_LEVEL_linalg_matrixMult_shp(mirror_matrix_shp, positions_shp);
	card_t size2420 = width_matrix_shape_t(mirrored_positions_shp);
	array_number_t stgVar2306 = storage_alloc(size2420);
	array_array_number_t macroDef2403;array_array_number_t mirrored_positions_dps = 0;
	if((is_mirrored_dps) == (1)) {
		matrix_shape_t mirror_matrix_shp0 = nested_shape_card_t(3, 3);
		card_t size2419 = width_matrix_shape_t(mirror_matrix_shp0);
	array_number_t stgVar2307 = storage_alloc(size2419);
	array_array_number_t macroDef2402;array_array_number_t macroDef2401 = (array_array_number_t)stgVar2307;
	macroDef2401->length=3;
	macroDef2401->arr=(array_number_t*)(STG_OFFSET(stgVar2307, VECTOR_HEADER_BYTES));
	int stgVar2307_offsetVar = 0;storage_t stgVar2308 = STG_OFFSET(stgVar2307, MATRIX_HEADER_BYTES(3) + stgVar2307_offsetVar);array_number_t macroDef2398 = (array_number_t)stgVar2308;
	macroDef2398->length=3;
	macroDef2398->arr=(number_t*)(STG_OFFSET(stgVar2308, VECTOR_HEADER_BYTES));
	

	macroDef2398->arr[0] = -1;;

	macroDef2398->arr[1] = 0;;

	macroDef2398->arr[2] = 0;;;

	macroDef2401->arr[0] = macroDef2398;;stgVar2307_offsetVar += VECTOR_ALL_BYTES(macroDef2401->arr[0]->length);storage_t stgVar2312 = STG_OFFSET(stgVar2307, MATRIX_HEADER_BYTES(3) + stgVar2307_offsetVar);array_number_t macroDef2399 = (array_number_t)stgVar2312;
	macroDef2399->length=3;
	macroDef2399->arr=(number_t*)(STG_OFFSET(stgVar2312, VECTOR_HEADER_BYTES));
	

	macroDef2399->arr[0] = 0;;

	macroDef2399->arr[1] = 1;;

	macroDef2399->arr[2] = 0;;;

	macroDef2401->arr[1] = macroDef2399;;stgVar2307_offsetVar += VECTOR_ALL_BYTES(macroDef2401->arr[1]->length);storage_t stgVar2316 = STG_OFFSET(stgVar2307, MATRIX_HEADER_BYTES(3) + stgVar2307_offsetVar);array_number_t macroDef2400 = (array_number_t)stgVar2316;
	macroDef2400->length=3;
	macroDef2400->arr=(number_t*)(STG_OFFSET(stgVar2316, VECTOR_HEADER_BYTES));
	

	macroDef2400->arr[0] = 0;;

	macroDef2400->arr[1] = 0;;

	macroDef2400->arr[2] = 1;;;

	macroDef2401->arr[2] = macroDef2400;;stgVar2307_offsetVar += VECTOR_ALL_BYTES(macroDef2401->arr[2]->length);;
	array_array_number_t mirror_matrix_dps = macroDef2401;
	macroDef2402 = TOP_LEVEL_linalg_matrixMult_dps(stgVar2306, mirror_matrix_dps, positions_dps, mirror_matrix_shp0, positions_shp);;
	storage_free(stgVar2307, size2419);
		mirrored_positions_dps = macroDef2402;;
	} else {
		
		mirrored_positions_dps = positions_dps;;
	}
	macroDef2403 = TOP_LEVEL_usecases_ht_apply_global_transform_dps(stgVar2261, pose_params_dps, mirrored_positions_dps, pose_params_shp, mirrored_positions_shp);;
	storage_free(stgVar2306, size2420);
	macroDef2404 = macroDef2403;;
	storage_free(stgVar2283, size2421);
	macroDef2405 = macroDef2404;;
	storage_free(stgVar2279, size2422);
	macroDef2406 = macroDef2405;;
	storage_free(stgVar2269, size2423);
	macroDef2407 = macroDef2406;;
	storage_free(stgVar2266, size2424);
	macroDef2408 = macroDef2407;;
	storage_free(stgVar2262, size2425);
	return macroDef2408;
}
typedef empty_env_t env_t_2479;


value_t lambda2479(env_t_2479* env2476, card_t i_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
card_t TOP_LEVEL_usecases_ht_hand_objective_shp(card_t is_mirrored_shp, card_t param_shp, card_t correspondences_shp, matrix_shape_t points_shp, card_t n_bones_shp, matrix3d_shape_t base_relatives_shp, card_t parents_shp, matrix3d_shape_t inverse_base_absolutes_shp, matrix_shape_t base_positions_shp, matrix_shape_t weights_shp) {
	env_t_2479 env_t_2479_value = make_empty_env(); closure_t closure2478 = make_closure(lambda2479, &env_t_2479_value);
	return TOP_LEVEL_linalg_vectorMap_shp(closure2478, TOP_LEVEL_linalg_vectorRange_shp(0, (((correspondences_shp) + (correspondences_shp)) + (correspondences_shp)) - (1)));
}

typedef empty_env_t env_t_2502;


value_t lambda2502(env_t_2502* env2481, card_t i_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef struct env_t_2503 {
	matrix_shape_t vertex_positions_shp;
	array_array_number_t vertex_positions_dps;
	matrix_shape_t points_shp;
	array_array_number_t points_dps;
	index_t n_corr_dps;
	array_number_t correspondences_dps;
} env_t_2503;
env_t_2503 make_env_t_2503(matrix_shape_t vertex_positions_shp,array_array_number_t vertex_positions_dps,matrix_shape_t points_shp,array_array_number_t points_dps,index_t n_corr_dps,array_number_t correspondences_dps) {
	env_t_2503 env;
	env.vertex_positions_shp = vertex_positions_shp;
	env.vertex_positions_dps = vertex_positions_dps;
	env.points_shp = points_shp;
	env.points_dps = points_dps;
	env.n_corr_dps = n_corr_dps;
	env.correspondences_dps = correspondences_dps;
	return env;
}

value_t lambda2503(env_t_2503* env2492, storage_t stgVar2445, number_t i_dps, card_t i_shp) {
	matrix_shape_t vertex_positions_shp2491 = env2492->vertex_positions_shp;
	array_array_number_t vertex_positions_dps2490 = env2492->vertex_positions_dps;
	matrix_shape_t points_shp2489 = env2492->points_shp;
	array_array_number_t points_dps2488 = env2492->points_dps;
	index_t n_corr_dps2487 = env2492->n_corr_dps;
	array_number_t correspondences_dps2486 = env2492->correspondences_dps;
	card_t ind_shp = 0;
	index_t ind_dps = (int)(i_dps);
	card_t r_shp = 0;
	index_t r_dps = (ind_dps) / (n_corr_dps2487);
	card_t c_shp = 0;
	index_t c_dps = (ind_dps) % (n_corr_dps2487);
	card_t size2504 = width_card_t(points_shp2489.elem);
	array_number_t stgVar2449 = storage_alloc(size2504);
	number_t macroDef2484;
	macroDef2484 = points_dps2488->arr[r_dps]->arr[c_dps];;
	storage_free(stgVar2449, size2504);
	card_t size2505 = width_card_t(vertex_positions_shp2491.elem);
	array_number_t stgVar2451 = storage_alloc(size2505);
	number_t macroDef2485;
	macroDef2485 = vertex_positions_dps2490->arr[r_dps]->arr[(int)(correspondences_dps2486->arr[c_dps])];;
	storage_free(stgVar2451, size2505);
	value_t res;
	res.number_t_value = (macroDef2484) - (macroDef2485);
	return res;
}
typedef empty_env_t env_t_2506;


value_t lambda2506(env_t_2506* env2495, card_t i_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
array_number_t TOP_LEVEL_usecases_ht_hand_objective_dps(storage_t stgVar2426, index_t is_mirrored_dps, array_number_t param_dps, array_number_t correspondences_dps, array_array_number_t points_dps, card_t n_bones_dps, array_array_array_number_t base_relatives_dps, array_number_t parents_dps, array_array_array_number_t inverse_base_absolutes_dps, array_array_number_t base_positions_dps, array_array_number_t weights_dps, card_t is_mirrored_shp, card_t param_shp, card_t correspondences_shp, matrix_shape_t points_shp, card_t n_bones_shp, matrix3d_shape_t base_relatives_shp, card_t parents_shp, matrix3d_shape_t inverse_base_absolutes_shp, matrix_shape_t base_positions_shp, matrix_shape_t weights_shp) {
	matrix_shape_t pose_params_shp = TOP_LEVEL_usecases_ht_to_pose_params_shp(param_shp, n_bones_shp);
	card_t size2510 = width_matrix_shape_t(pose_params_shp);
	array_number_t stgVar2427 = storage_alloc(size2510);
	array_number_t macroDef2501;array_array_number_t pose_params_dps = TOP_LEVEL_usecases_ht_to_pose_params_dps(stgVar2427, param_dps, n_bones_dps, param_shp, n_bones_shp);
	matrix_shape_t vertex_positions_shp = TOP_LEVEL_usecases_ht_get_skinned_vertex_positions_shp(0, n_bones_shp, pose_params_shp, base_relatives_shp, parents_shp, inverse_base_absolutes_shp, base_positions_shp, weights_shp);
	card_t size2509 = width_matrix_shape_t(vertex_positions_shp);
	array_number_t stgVar2430 = storage_alloc(size2509);
	array_number_t macroDef2500;array_array_number_t vertex_positions_dps = TOP_LEVEL_usecases_ht_get_skinned_vertex_positions_dps(stgVar2430, is_mirrored_dps, n_bones_dps, pose_params_dps, base_relatives_dps, parents_dps, inverse_base_absolutes_dps, base_positions_dps, weights_dps, 0, n_bones_shp, pose_params_shp, base_relatives_shp, parents_shp, inverse_base_absolutes_shp, base_positions_shp, weights_shp);
	card_t n_corr_card_shp = correspondences_shp;
	card_t macroDef2480 = correspondences_dps->length;
	card_t n_corr_card_dps = macroDef2480;
	card_t n_corr_shp = 0;
	index_t n_corr_dps = (n_corr_card_dps);
	env_t_2502 env_t_2502_value = make_empty_env(); closure_t closure2483 = make_closure(lambda2502, &env_t_2502_value);
	card_t err_shp = TOP_LEVEL_linalg_vectorMap_shp(closure2483, TOP_LEVEL_linalg_vectorRange_shp(0, (((n_corr_card_shp) + (n_corr_card_shp)) + (n_corr_card_shp)) - (1)));
	card_t size2508 = width_card_t(err_shp);
	array_number_t stgVar2442 = storage_alloc(size2508);
	array_number_t macroDef2499;card_t size2507 = width_card_t(TOP_LEVEL_linalg_vectorRange_shp(0, (((n_corr_card_shp) + (n_corr_card_shp)) + (n_corr_card_shp)) - (1)));
	array_number_t stgVar2444 = storage_alloc(size2507);
	array_number_t macroDef2498;env_t_2503 env_t_2503_value = make_env_t_2503(vertex_positions_shp,vertex_positions_dps,points_shp,points_dps,n_corr_dps,correspondences_dps); closure_t closure2494 = make_closure(lambda2503, &env_t_2503_value);
	env_t_2506 env_t_2506_value = make_empty_env(); closure_t closure2497 = make_closure(lambda2506, &env_t_2506_value);
	macroDef2498 = TOP_LEVEL_linalg_vectorMap_dps(stgVar2442, closure2494, TOP_LEVEL_linalg_vectorRange_dps(stgVar2444, 0, (((n_corr_card_dps) + (n_corr_card_dps)) + (n_corr_card_dps)) - (1), 0, (((n_corr_card_shp) + (n_corr_card_shp)) + (n_corr_card_shp)) - (1)), closure2497, TOP_LEVEL_linalg_vectorRange_shp(0, (((n_corr_card_shp) + (n_corr_card_shp)) + (n_corr_card_shp)) - (1)));;
	storage_free(stgVar2444, size2507);
	array_number_t err_dps = macroDef2498;
	macroDef2499 = err_dps;;
	storage_free(stgVar2442, size2508);
	macroDef2500 = macroDef2499;;
	storage_free(stgVar2430, size2509);
	macroDef2501 = macroDef2500;;
	storage_free(stgVar2427, size2510);
	return macroDef2501;
}

card_t TOP_LEVEL_usecases_ht_test_ht_shp(card_t unitVar0_shp) {
	
	return 0;
}

typedef empty_env_t env_t_2560;


value_t lambda2560(env_t_2560* env2545, card_t i_shp) {
	
	value_t res;
	res.card_t_value = 4;
	return res;
}
void TOP_LEVEL_usecases_ht_test_ht_dps(storage_t stgVar2511, int unitVar0_dps, card_t unitVar0_shp) {
	card_t a_shp = 3;
	card_t size2566 = width_card_t(a_shp);
	array_number_t stgVar2512 = storage_alloc(size2566);
	array_number_t macroDef2540 = (array_number_t)stgVar2512;
	macroDef2540->length=3;
	macroDef2540->arr=(number_t*)(STG_OFFSET(stgVar2512, VECTOR_HEADER_BYTES));
	

	macroDef2540->arr[0] = 1;;

	macroDef2540->arr[1] = 2;;

	macroDef2540->arr[2] = 3;;;
	array_number_t a_dps = macroDef2540;
	array_print(a_dps);
	matrix_shape_t mat1_shp = nested_shape_card_t(3, 3);
	card_t size2565 = width_matrix_shape_t(mat1_shp);
	array_number_t stgVar2516 = storage_alloc(size2565);
	array_array_number_t macroDef2544 = (array_array_number_t)stgVar2516;
	macroDef2544->length=3;
	macroDef2544->arr=(array_number_t*)(STG_OFFSET(stgVar2516, VECTOR_HEADER_BYTES));
	int stgVar2516_offsetVar = 0;storage_t stgVar2517 = STG_OFFSET(stgVar2516, MATRIX_HEADER_BYTES(3) + stgVar2516_offsetVar);array_number_t macroDef2541 = (array_number_t)stgVar2517;
	macroDef2541->length=3;
	macroDef2541->arr=(number_t*)(STG_OFFSET(stgVar2517, VECTOR_HEADER_BYTES));
	

	macroDef2541->arr[0] = 1;;

	macroDef2541->arr[1] = 2;;

	macroDef2541->arr[2] = 3;;;

	macroDef2544->arr[0] = macroDef2541;;stgVar2516_offsetVar += VECTOR_ALL_BYTES(macroDef2544->arr[0]->length);storage_t stgVar2521 = STG_OFFSET(stgVar2516, MATRIX_HEADER_BYTES(3) + stgVar2516_offsetVar);array_number_t macroDef2542 = (array_number_t)stgVar2521;
	macroDef2542->length=3;
	macroDef2542->arr=(number_t*)(STG_OFFSET(stgVar2521, VECTOR_HEADER_BYTES));
	

	macroDef2542->arr[0] = 4;;

	macroDef2542->arr[1] = 5;;

	macroDef2542->arr[2] = 6;;;

	macroDef2544->arr[1] = macroDef2542;;stgVar2516_offsetVar += VECTOR_ALL_BYTES(macroDef2544->arr[1]->length);storage_t stgVar2525 = STG_OFFSET(stgVar2516, MATRIX_HEADER_BYTES(3) + stgVar2516_offsetVar);array_number_t macroDef2543 = (array_number_t)stgVar2525;
	macroDef2543->length=3;
	macroDef2543->arr=(number_t*)(STG_OFFSET(stgVar2525, VECTOR_HEADER_BYTES));
	

	macroDef2543->arr[0] = 7;;

	macroDef2543->arr[1] = 8;;

	macroDef2543->arr[2] = 9;;;

	macroDef2544->arr[2] = macroDef2543;;stgVar2516_offsetVar += VECTOR_ALL_BYTES(macroDef2544->arr[2]->length);;
	array_array_number_t mat1_dps = macroDef2544;
	env_t_2560 env_t_2560_value = make_empty_env(); closure_t closure2547 = make_closure(lambda2560, &env_t_2560_value);
	matrix_shape_t base_rel_shp = nested_shape_card_t(closure2547.lam(closure2547.env, 0).card_t_value, 4);
	card_t size2564 = width_matrix_shape_t(base_rel_shp);
	array_number_t stgVar2529 = storage_alloc(size2564);
	array_array_number_t macroDef2549 = (array_array_number_t)stgVar2529;
		macroDef2549->length=4;
		macroDef2549->arr=(array_number_t*)(STG_OFFSET(macroDef2549, VECTOR_HEADER_BYTES));
		storage_t stgVar2530 = (STG_OFFSET(macroDef2549, MATRIX_HEADER_BYTES(4)));
		for(int i_dps = 0; i_dps < macroDef2549->length; i_dps++){
			array_number_t macroDef2548 = (array_number_t)stgVar2530;
		macroDef2548->length=4;
		macroDef2548->arr=(number_t*)(STG_OFFSET(macroDef2548, VECTOR_HEADER_BYTES));
		storage_t stgVar2531 = macroDef2548;
		for(int j_dps = 0; j_dps < macroDef2548->length; j_dps++){
			
			macroDef2548->arr[j_dps] = (double)((((i_dps) + (1)) * (4)) + (j_dps));;
			stgVar2531 = STG_OFFSET(stgVar2531, sizeof(number_t));
		}
			macroDef2549->arr[i_dps] = macroDef2548;;
			stgVar2530 = STG_OFFSET(stgVar2530, VECTOR_ALL_BYTES(macroDef2549->arr[i_dps]->length));
		}
	array_array_number_t base_rel_dps = macroDef2549;
	matrix_shape_t q_shp = TOP_LEVEL_usecases_ht_make_relative_shp(a_shp, base_rel_shp);
	card_t size2563 = width_matrix_shape_t(q_shp);
	array_number_t stgVar2532 = storage_alloc(size2563);
	array_array_number_t q_dps = TOP_LEVEL_usecases_ht_make_relative_dps(stgVar2532, a_dps, base_rel_dps, a_shp, base_rel_shp);
	matrix_print(q_dps);
	matrix_shape_t r_shp = TOP_LEVEL_usecases_ht_angle_axis_to_rotation_matrix_shp(a_shp);
	card_t size2562 = width_matrix_shape_t(r_shp);
	array_number_t stgVar2535 = storage_alloc(size2562);
	array_array_number_t r_dps = TOP_LEVEL_usecases_ht_angle_axis_to_rotation_matrix_dps(stgVar2535, a_dps, a_shp);
	matrix_print(r_dps);
	matrix_shape_t s_shp = TOP_LEVEL_usecases_ht_apply_global_transform_shp(mat1_shp, mat1_shp);
	card_t size2561 = width_matrix_shape_t(s_shp);
	array_number_t stgVar2537 = storage_alloc(size2561);
	array_array_number_t s_dps = TOP_LEVEL_usecases_ht_apply_global_transform_dps(stgVar2537, mat1_dps, mat1_dps, mat1_shp, mat1_shp);
	matrix_print(s_dps);
	;
	storage_free(stgVar2537, size2561);
	;
	storage_free(stgVar2535, size2562);
	;
	storage_free(stgVar2532, size2563);
	;
	storage_free(stgVar2529, size2564);
	;
	storage_free(stgVar2516, size2565);
	;
	storage_free(stgVar2512, size2566);
	return ;
}
#endif
