#ifndef __USECASES_HT_STORAGED_H__ 
#define __USECASES_HT_STORAGED_H__ 
#include "runtime/fsharp.h"
#include <stdio.h>
#include <math.h>
#include "linalg_storaged.h"

matrix3d_shape_t TOP_LEVEL_usecases_ht_matrix3DUpdate_shp(matrix3d_shape_t m_shp, card_t s_shp, card_t e_shp, matrix3d_shape_t nm_shp) {
	
	return nested_shape_matrix_shape_t(nm_shp.elem, m_shp.card);
}


array_array_array_number_t TOP_LEVEL_usecases_ht_matrix3DUpdate_dps(storage_t stgVar1437, array_array_array_number_t m_dps, index_t s_dps, index_t e_dps, array_array_array_number_t nm_dps, matrix3d_shape_t m_shp, card_t s_shp, card_t e_shp, matrix3d_shape_t nm_shp) {
	card_t macroDef1443 = m_dps->length;
	array_array_array_number_t macroDef1444 = (array_array_array_number_t)stgVar1437;
		macroDef1444->length=macroDef1443;
		macroDef1444->arr=(array_array_number_t*)(STG_OFFSET(macroDef1444, VECTOR_HEADER_BYTES));
		storage_t stgVar1439 = (STG_OFFSET(macroDef1444, MATRIX_HEADER_BYTES(macroDef1443)));
		for(int i_dps = 0; i_dps < macroDef1444->length; i_dps++){
			card_t isInRange_shp = 0;
			bool_t isInRange_dps = 0;
	if((i_dps) >= (s_dps)) {
		
		isInRange_dps = (i_dps) < (e_dps);;
	} else {
		
		isInRange_dps = false;;
	}
			array_array_number_t ite1445 = 0;
	if(isInRange_dps) {
		
		ite1445 = nm_dps->arr[(i_dps) - (s_dps)];;
	} else {
		
		ite1445 = m_dps->arr[i_dps];;
	}
			macroDef1444->arr[i_dps] = ite1445;;
			stgVar1439 = STG_OFFSET(stgVar1439, VECTOR_ALL_BYTES(macroDef1444->arr[i_dps]->length));
		}
	return macroDef1444;
}

matrix_shape_t TOP_LEVEL_usecases_ht_to_pose_params_shp(card_t theta_shp, card_t n_bones_shp) {
	
	return TOP_LEVEL_linalg_matrixConcat_shp(nested_shape_card_t(TOP_LEVEL_linalg_vectorSlice_shp(3, 0, theta_shp), 5), TOP_LEVEL_linalg_matrixConcat_shp(nested_shape_card_t(3, 4), TOP_LEVEL_linalg_matrixConcat_shp(nested_shape_card_t(3, 4), TOP_LEVEL_linalg_matrixConcat_shp(nested_shape_card_t(3, 4), TOP_LEVEL_linalg_matrixConcat_shp(nested_shape_card_t(3, 4), nested_shape_card_t(3, 4))))));
}


array_array_number_t TOP_LEVEL_usecases_ht_to_pose_params_dps(storage_t stgVar1446, array_number_t theta_dps, card_t n_bones_dps, card_t theta_shp, card_t n_bones_shp) {
	card_t row1_shp = TOP_LEVEL_linalg_vectorSlice_shp(3, 0, theta_shp);
	card_t size1854 = width_card_t(row1_shp);
	array_number_t stgVar1447 = storage_alloc(size1854);
	array_array_number_t macroDef1840;array_number_t row1_dps = TOP_LEVEL_linalg_vectorSlice_dps(stgVar1447, 3, 0, theta_dps, 3, 0, theta_shp);
	card_t row2_shp = 3;
	card_t size1853 = width_card_t(row2_shp);
	array_number_t stgVar1451 = storage_alloc(size1853);
	array_array_number_t macroDef1839;array_number_t macroDef1799 = (array_number_t)stgVar1451;
	macroDef1799->length=3;
	macroDef1799->arr=(number_t*)(STG_OFFSET(stgVar1451, VECTOR_HEADER_BYTES));
	

	macroDef1799->arr[0] = 1;;

	macroDef1799->arr[1] = 1;;

	macroDef1799->arr[2] = 1;;;
	array_number_t row2_dps = macroDef1799;
	card_t row3_shp = TOP_LEVEL_linalg_vectorSlice_shp(3, 0, theta_shp);
	card_t size1852 = width_card_t(row3_shp);
	array_number_t stgVar1455 = storage_alloc(size1852);
	array_array_number_t macroDef1838;array_number_t row3_dps = TOP_LEVEL_linalg_vectorSlice_dps(stgVar1455, 3, 3, theta_dps, 3, 0, theta_shp);
	card_t zeroRow_shp = 3;
	card_t size1851 = width_card_t(zeroRow_shp);
	array_number_t stgVar1459 = storage_alloc(size1851);
	array_array_number_t macroDef1837;array_number_t macroDef1800 = (array_number_t)stgVar1459;
	macroDef1800->length=3;
	macroDef1800->arr=(number_t*)(STG_OFFSET(stgVar1459, VECTOR_HEADER_BYTES));
	

	macroDef1800->arr[0] = 0;;

	macroDef1800->arr[1] = 0;;

	macroDef1800->arr[2] = 0;;;
	array_number_t zeroRow_dps = macroDef1800;
	matrix_shape_t pose_params_shp = nested_shape_card_t(row1_shp, 5);
	card_t size1850 = width_matrix_shape_t(pose_params_shp);
	array_number_t stgVar1463 = storage_alloc(size1850);
	array_array_number_t macroDef1836;array_array_number_t macroDef1801 = (array_array_number_t)stgVar1463;
	macroDef1801->length=5;
	macroDef1801->arr=(array_number_t*)(STG_OFFSET(stgVar1463, VECTOR_HEADER_BYTES));
	int stgVar1463_offsetVar = 0;storage_t stgVar1464 = STG_OFFSET(stgVar1463, MATRIX_HEADER_BYTES(5) + stgVar1463_offsetVar);

	macroDef1801->arr[0] = row1_dps;;stgVar1463_offsetVar += VECTOR_ALL_BYTES(macroDef1801->arr[0]->length);storage_t stgVar1465 = STG_OFFSET(stgVar1463, MATRIX_HEADER_BYTES(5) + stgVar1463_offsetVar);

	macroDef1801->arr[1] = row2_dps;;stgVar1463_offsetVar += VECTOR_ALL_BYTES(macroDef1801->arr[1]->length);storage_t stgVar1466 = STG_OFFSET(stgVar1463, MATRIX_HEADER_BYTES(5) + stgVar1463_offsetVar);

	macroDef1801->arr[2] = row3_dps;;stgVar1463_offsetVar += VECTOR_ALL_BYTES(macroDef1801->arr[2]->length);storage_t stgVar1467 = STG_OFFSET(stgVar1463, MATRIX_HEADER_BYTES(5) + stgVar1463_offsetVar);

	macroDef1801->arr[3] = zeroRow_dps;;stgVar1463_offsetVar += VECTOR_ALL_BYTES(macroDef1801->arr[3]->length);storage_t stgVar1468 = STG_OFFSET(stgVar1463, MATRIX_HEADER_BYTES(5) + stgVar1463_offsetVar);

	macroDef1801->arr[4] = zeroRow_dps;;stgVar1463_offsetVar += VECTOR_ALL_BYTES(macroDef1801->arr[4]->length);;
	array_array_number_t pose_params_dps = macroDef1801;
	card_t i1_shp = 0;
	index_t i1_dps = 5;
	matrix_shape_t finger1_shp = nested_shape_card_t(3, 4);
	card_t size1849 = width_matrix_shape_t(finger1_shp);
	array_number_t stgVar1470 = storage_alloc(size1849);
	array_array_number_t macroDef1835;array_array_number_t macroDef1806 = (array_array_number_t)stgVar1470;
	macroDef1806->length=4;
	macroDef1806->arr=(array_number_t*)(STG_OFFSET(stgVar1470, VECTOR_HEADER_BYTES));
	int stgVar1470_offsetVar = 0;storage_t stgVar1471 = STG_OFFSET(stgVar1470, MATRIX_HEADER_BYTES(4) + stgVar1470_offsetVar);array_number_t macroDef1802 = (array_number_t)stgVar1471;
	macroDef1802->length=3;
	macroDef1802->arr=(number_t*)(STG_OFFSET(stgVar1471, VECTOR_HEADER_BYTES));
	

	macroDef1802->arr[0] = theta_dps->arr[i1_dps];;

	macroDef1802->arr[1] = theta_dps->arr[(i1_dps) + (1)];;

	macroDef1802->arr[2] = 0;;;

	macroDef1806->arr[0] = macroDef1802;;stgVar1470_offsetVar += VECTOR_ALL_BYTES(macroDef1806->arr[0]->length);storage_t stgVar1477 = STG_OFFSET(stgVar1470, MATRIX_HEADER_BYTES(4) + stgVar1470_offsetVar);array_number_t macroDef1803 = (array_number_t)stgVar1477;
	macroDef1803->length=3;
	macroDef1803->arr=(number_t*)(STG_OFFSET(stgVar1477, VECTOR_HEADER_BYTES));
	

	macroDef1803->arr[0] = theta_dps->arr[(i1_dps) + (2)];;

	macroDef1803->arr[1] = 0;;

	macroDef1803->arr[2] = 0;;;

	macroDef1806->arr[1] = macroDef1803;;stgVar1470_offsetVar += VECTOR_ALL_BYTES(macroDef1806->arr[1]->length);storage_t stgVar1482 = STG_OFFSET(stgVar1470, MATRIX_HEADER_BYTES(4) + stgVar1470_offsetVar);array_number_t macroDef1804 = (array_number_t)stgVar1482;
	macroDef1804->length=3;
	macroDef1804->arr=(number_t*)(STG_OFFSET(stgVar1482, VECTOR_HEADER_BYTES));
	

	macroDef1804->arr[0] = theta_dps->arr[(i1_dps) + (3)];;

	macroDef1804->arr[1] = 0;;

	macroDef1804->arr[2] = 0;;;

	macroDef1806->arr[2] = macroDef1804;;stgVar1470_offsetVar += VECTOR_ALL_BYTES(macroDef1806->arr[2]->length);storage_t stgVar1487 = STG_OFFSET(stgVar1470, MATRIX_HEADER_BYTES(4) + stgVar1470_offsetVar);array_number_t macroDef1805 = (array_number_t)stgVar1487;
	macroDef1805->length=3;
	macroDef1805->arr=(number_t*)(STG_OFFSET(stgVar1487, VECTOR_HEADER_BYTES));
	

	macroDef1805->arr[0] = 0;;

	macroDef1805->arr[1] = 0;;

	macroDef1805->arr[2] = 0;;;

	macroDef1806->arr[3] = macroDef1805;;stgVar1470_offsetVar += VECTOR_ALL_BYTES(macroDef1806->arr[3]->length);;
	array_array_number_t finger1_dps = macroDef1806;
	card_t i2_shp = 0;
	index_t i2_dps = (i1_dps) + (4);
	matrix_shape_t finger2_shp = nested_shape_card_t(3, 4);
	card_t size1848 = width_matrix_shape_t(finger2_shp);
	array_number_t stgVar1492 = storage_alloc(size1848);
	array_array_number_t macroDef1834;array_array_number_t macroDef1811 = (array_array_number_t)stgVar1492;
	macroDef1811->length=4;
	macroDef1811->arr=(array_number_t*)(STG_OFFSET(stgVar1492, VECTOR_HEADER_BYTES));
	int stgVar1492_offsetVar = 0;storage_t stgVar1493 = STG_OFFSET(stgVar1492, MATRIX_HEADER_BYTES(4) + stgVar1492_offsetVar);array_number_t macroDef1807 = (array_number_t)stgVar1493;
	macroDef1807->length=3;
	macroDef1807->arr=(number_t*)(STG_OFFSET(stgVar1493, VECTOR_HEADER_BYTES));
	

	macroDef1807->arr[0] = theta_dps->arr[i2_dps];;

	macroDef1807->arr[1] = theta_dps->arr[(i2_dps) + (1)];;

	macroDef1807->arr[2] = 0;;;

	macroDef1811->arr[0] = macroDef1807;;stgVar1492_offsetVar += VECTOR_ALL_BYTES(macroDef1811->arr[0]->length);storage_t stgVar1499 = STG_OFFSET(stgVar1492, MATRIX_HEADER_BYTES(4) + stgVar1492_offsetVar);array_number_t macroDef1808 = (array_number_t)stgVar1499;
	macroDef1808->length=3;
	macroDef1808->arr=(number_t*)(STG_OFFSET(stgVar1499, VECTOR_HEADER_BYTES));
	

	macroDef1808->arr[0] = theta_dps->arr[(i2_dps) + (2)];;

	macroDef1808->arr[1] = 0;;

	macroDef1808->arr[2] = 0;;;

	macroDef1811->arr[1] = macroDef1808;;stgVar1492_offsetVar += VECTOR_ALL_BYTES(macroDef1811->arr[1]->length);storage_t stgVar1504 = STG_OFFSET(stgVar1492, MATRIX_HEADER_BYTES(4) + stgVar1492_offsetVar);array_number_t macroDef1809 = (array_number_t)stgVar1504;
	macroDef1809->length=3;
	macroDef1809->arr=(number_t*)(STG_OFFSET(stgVar1504, VECTOR_HEADER_BYTES));
	

	macroDef1809->arr[0] = theta_dps->arr[(i2_dps) + (3)];;

	macroDef1809->arr[1] = 0;;

	macroDef1809->arr[2] = 0;;;

	macroDef1811->arr[2] = macroDef1809;;stgVar1492_offsetVar += VECTOR_ALL_BYTES(macroDef1811->arr[2]->length);storage_t stgVar1509 = STG_OFFSET(stgVar1492, MATRIX_HEADER_BYTES(4) + stgVar1492_offsetVar);array_number_t macroDef1810 = (array_number_t)stgVar1509;
	macroDef1810->length=3;
	macroDef1810->arr=(number_t*)(STG_OFFSET(stgVar1509, VECTOR_HEADER_BYTES));
	

	macroDef1810->arr[0] = 0;;

	macroDef1810->arr[1] = 0;;

	macroDef1810->arr[2] = 0;;;

	macroDef1811->arr[3] = macroDef1810;;stgVar1492_offsetVar += VECTOR_ALL_BYTES(macroDef1811->arr[3]->length);;
	array_array_number_t finger2_dps = macroDef1811;
	card_t i3_shp = 0;
	index_t i3_dps = (i2_dps) + (4);
	matrix_shape_t finger3_shp = nested_shape_card_t(3, 4);
	card_t size1847 = width_matrix_shape_t(finger3_shp);
	array_number_t stgVar1514 = storage_alloc(size1847);
	array_array_number_t macroDef1833;array_array_number_t macroDef1816 = (array_array_number_t)stgVar1514;
	macroDef1816->length=4;
	macroDef1816->arr=(array_number_t*)(STG_OFFSET(stgVar1514, VECTOR_HEADER_BYTES));
	int stgVar1514_offsetVar = 0;storage_t stgVar1515 = STG_OFFSET(stgVar1514, MATRIX_HEADER_BYTES(4) + stgVar1514_offsetVar);array_number_t macroDef1812 = (array_number_t)stgVar1515;
	macroDef1812->length=3;
	macroDef1812->arr=(number_t*)(STG_OFFSET(stgVar1515, VECTOR_HEADER_BYTES));
	

	macroDef1812->arr[0] = theta_dps->arr[i3_dps];;

	macroDef1812->arr[1] = theta_dps->arr[(i3_dps) + (1)];;

	macroDef1812->arr[2] = 0;;;

	macroDef1816->arr[0] = macroDef1812;;stgVar1514_offsetVar += VECTOR_ALL_BYTES(macroDef1816->arr[0]->length);storage_t stgVar1521 = STG_OFFSET(stgVar1514, MATRIX_HEADER_BYTES(4) + stgVar1514_offsetVar);array_number_t macroDef1813 = (array_number_t)stgVar1521;
	macroDef1813->length=3;
	macroDef1813->arr=(number_t*)(STG_OFFSET(stgVar1521, VECTOR_HEADER_BYTES));
	

	macroDef1813->arr[0] = theta_dps->arr[(i3_dps) + (2)];;

	macroDef1813->arr[1] = 0;;

	macroDef1813->arr[2] = 0;;;

	macroDef1816->arr[1] = macroDef1813;;stgVar1514_offsetVar += VECTOR_ALL_BYTES(macroDef1816->arr[1]->length);storage_t stgVar1526 = STG_OFFSET(stgVar1514, MATRIX_HEADER_BYTES(4) + stgVar1514_offsetVar);array_number_t macroDef1814 = (array_number_t)stgVar1526;
	macroDef1814->length=3;
	macroDef1814->arr=(number_t*)(STG_OFFSET(stgVar1526, VECTOR_HEADER_BYTES));
	

	macroDef1814->arr[0] = theta_dps->arr[(i3_dps) + (3)];;

	macroDef1814->arr[1] = 0;;

	macroDef1814->arr[2] = 0;;;

	macroDef1816->arr[2] = macroDef1814;;stgVar1514_offsetVar += VECTOR_ALL_BYTES(macroDef1816->arr[2]->length);storage_t stgVar1531 = STG_OFFSET(stgVar1514, MATRIX_HEADER_BYTES(4) + stgVar1514_offsetVar);array_number_t macroDef1815 = (array_number_t)stgVar1531;
	macroDef1815->length=3;
	macroDef1815->arr=(number_t*)(STG_OFFSET(stgVar1531, VECTOR_HEADER_BYTES));
	

	macroDef1815->arr[0] = 0;;

	macroDef1815->arr[1] = 0;;

	macroDef1815->arr[2] = 0;;;

	macroDef1816->arr[3] = macroDef1815;;stgVar1514_offsetVar += VECTOR_ALL_BYTES(macroDef1816->arr[3]->length);;
	array_array_number_t finger3_dps = macroDef1816;
	card_t i4_shp = 0;
	index_t i4_dps = (i3_dps) + (4);
	matrix_shape_t finger4_shp = nested_shape_card_t(3, 4);
	card_t size1846 = width_matrix_shape_t(finger4_shp);
	array_number_t stgVar1536 = storage_alloc(size1846);
	array_array_number_t macroDef1832;array_array_number_t macroDef1821 = (array_array_number_t)stgVar1536;
	macroDef1821->length=4;
	macroDef1821->arr=(array_number_t*)(STG_OFFSET(stgVar1536, VECTOR_HEADER_BYTES));
	int stgVar1536_offsetVar = 0;storage_t stgVar1537 = STG_OFFSET(stgVar1536, MATRIX_HEADER_BYTES(4) + stgVar1536_offsetVar);array_number_t macroDef1817 = (array_number_t)stgVar1537;
	macroDef1817->length=3;
	macroDef1817->arr=(number_t*)(STG_OFFSET(stgVar1537, VECTOR_HEADER_BYTES));
	

	macroDef1817->arr[0] = theta_dps->arr[i4_dps];;

	macroDef1817->arr[1] = theta_dps->arr[(i4_dps) + (1)];;

	macroDef1817->arr[2] = 0;;;

	macroDef1821->arr[0] = macroDef1817;;stgVar1536_offsetVar += VECTOR_ALL_BYTES(macroDef1821->arr[0]->length);storage_t stgVar1543 = STG_OFFSET(stgVar1536, MATRIX_HEADER_BYTES(4) + stgVar1536_offsetVar);array_number_t macroDef1818 = (array_number_t)stgVar1543;
	macroDef1818->length=3;
	macroDef1818->arr=(number_t*)(STG_OFFSET(stgVar1543, VECTOR_HEADER_BYTES));
	

	macroDef1818->arr[0] = theta_dps->arr[(i4_dps) + (2)];;

	macroDef1818->arr[1] = 0;;

	macroDef1818->arr[2] = 0;;;

	macroDef1821->arr[1] = macroDef1818;;stgVar1536_offsetVar += VECTOR_ALL_BYTES(macroDef1821->arr[1]->length);storage_t stgVar1548 = STG_OFFSET(stgVar1536, MATRIX_HEADER_BYTES(4) + stgVar1536_offsetVar);array_number_t macroDef1819 = (array_number_t)stgVar1548;
	macroDef1819->length=3;
	macroDef1819->arr=(number_t*)(STG_OFFSET(stgVar1548, VECTOR_HEADER_BYTES));
	

	macroDef1819->arr[0] = theta_dps->arr[(i4_dps) + (3)];;

	macroDef1819->arr[1] = 0;;

	macroDef1819->arr[2] = 0;;;

	macroDef1821->arr[2] = macroDef1819;;stgVar1536_offsetVar += VECTOR_ALL_BYTES(macroDef1821->arr[2]->length);storage_t stgVar1553 = STG_OFFSET(stgVar1536, MATRIX_HEADER_BYTES(4) + stgVar1536_offsetVar);array_number_t macroDef1820 = (array_number_t)stgVar1553;
	macroDef1820->length=3;
	macroDef1820->arr=(number_t*)(STG_OFFSET(stgVar1553, VECTOR_HEADER_BYTES));
	

	macroDef1820->arr[0] = 0;;

	macroDef1820->arr[1] = 0;;

	macroDef1820->arr[2] = 0;;;

	macroDef1821->arr[3] = macroDef1820;;stgVar1536_offsetVar += VECTOR_ALL_BYTES(macroDef1821->arr[3]->length);;
	array_array_number_t finger4_dps = macroDef1821;
	card_t i5_shp = 0;
	index_t i5_dps = (i4_dps) + (4);
	matrix_shape_t finger5_shp = nested_shape_card_t(3, 4);
	card_t size1845 = width_matrix_shape_t(finger5_shp);
	array_number_t stgVar1558 = storage_alloc(size1845);
	array_array_number_t macroDef1831;array_array_number_t macroDef1826 = (array_array_number_t)stgVar1558;
	macroDef1826->length=4;
	macroDef1826->arr=(array_number_t*)(STG_OFFSET(stgVar1558, VECTOR_HEADER_BYTES));
	int stgVar1558_offsetVar = 0;storage_t stgVar1559 = STG_OFFSET(stgVar1558, MATRIX_HEADER_BYTES(4) + stgVar1558_offsetVar);array_number_t macroDef1822 = (array_number_t)stgVar1559;
	macroDef1822->length=3;
	macroDef1822->arr=(number_t*)(STG_OFFSET(stgVar1559, VECTOR_HEADER_BYTES));
	

	macroDef1822->arr[0] = theta_dps->arr[i5_dps];;

	macroDef1822->arr[1] = theta_dps->arr[(i5_dps) + (1)];;

	macroDef1822->arr[2] = 0;;;

	macroDef1826->arr[0] = macroDef1822;;stgVar1558_offsetVar += VECTOR_ALL_BYTES(macroDef1826->arr[0]->length);storage_t stgVar1565 = STG_OFFSET(stgVar1558, MATRIX_HEADER_BYTES(4) + stgVar1558_offsetVar);array_number_t macroDef1823 = (array_number_t)stgVar1565;
	macroDef1823->length=3;
	macroDef1823->arr=(number_t*)(STG_OFFSET(stgVar1565, VECTOR_HEADER_BYTES));
	

	macroDef1823->arr[0] = theta_dps->arr[(i5_dps) + (2)];;

	macroDef1823->arr[1] = 0;;

	macroDef1823->arr[2] = 0;;;

	macroDef1826->arr[1] = macroDef1823;;stgVar1558_offsetVar += VECTOR_ALL_BYTES(macroDef1826->arr[1]->length);storage_t stgVar1570 = STG_OFFSET(stgVar1558, MATRIX_HEADER_BYTES(4) + stgVar1558_offsetVar);array_number_t macroDef1824 = (array_number_t)stgVar1570;
	macroDef1824->length=3;
	macroDef1824->arr=(number_t*)(STG_OFFSET(stgVar1570, VECTOR_HEADER_BYTES));
	

	macroDef1824->arr[0] = theta_dps->arr[(i5_dps) + (3)];;

	macroDef1824->arr[1] = 0;;

	macroDef1824->arr[2] = 0;;;

	macroDef1826->arr[2] = macroDef1824;;stgVar1558_offsetVar += VECTOR_ALL_BYTES(macroDef1826->arr[2]->length);storage_t stgVar1575 = STG_OFFSET(stgVar1558, MATRIX_HEADER_BYTES(4) + stgVar1558_offsetVar);array_number_t macroDef1825 = (array_number_t)stgVar1575;
	macroDef1825->length=3;
	macroDef1825->arr=(number_t*)(STG_OFFSET(stgVar1575, VECTOR_HEADER_BYTES));
	

	macroDef1825->arr[0] = 0;;

	macroDef1825->arr[1] = 0;;

	macroDef1825->arr[2] = 0;;;

	macroDef1826->arr[3] = macroDef1825;;stgVar1558_offsetVar += VECTOR_ALL_BYTES(macroDef1826->arr[3]->length);;
	array_array_number_t finger5_dps = macroDef1826;
	card_t size1844 = width_matrix_shape_t(TOP_LEVEL_linalg_matrixConcat_shp(finger1_shp, TOP_LEVEL_linalg_matrixConcat_shp(finger2_shp, TOP_LEVEL_linalg_matrixConcat_shp(finger3_shp, TOP_LEVEL_linalg_matrixConcat_shp(finger4_shp, finger5_shp)))));
	array_number_t stgVar1580 = storage_alloc(size1844);
	array_array_number_t macroDef1830;card_t size1843 = width_matrix_shape_t(TOP_LEVEL_linalg_matrixConcat_shp(finger2_shp, TOP_LEVEL_linalg_matrixConcat_shp(finger3_shp, TOP_LEVEL_linalg_matrixConcat_shp(finger4_shp, finger5_shp))));
	array_number_t stgVar1582 = storage_alloc(size1843);
	array_array_number_t macroDef1829;card_t size1842 = width_matrix_shape_t(TOP_LEVEL_linalg_matrixConcat_shp(finger3_shp, TOP_LEVEL_linalg_matrixConcat_shp(finger4_shp, finger5_shp)));
	array_number_t stgVar1584 = storage_alloc(size1842);
	array_array_number_t macroDef1828;card_t size1841 = width_matrix_shape_t(TOP_LEVEL_linalg_matrixConcat_shp(finger4_shp, finger5_shp));
	array_number_t stgVar1586 = storage_alloc(size1841);
	array_array_number_t macroDef1827;
	macroDef1827 = TOP_LEVEL_linalg_matrixConcat_dps(stgVar1584, finger3_dps, TOP_LEVEL_linalg_matrixConcat_dps(stgVar1586, finger4_dps, finger5_dps, finger4_shp, finger5_shp), finger3_shp, TOP_LEVEL_linalg_matrixConcat_shp(finger4_shp, finger5_shp));;
	storage_free(stgVar1586, size1841);
	macroDef1828 = TOP_LEVEL_linalg_matrixConcat_dps(stgVar1582, finger2_dps, macroDef1827, finger2_shp, TOP_LEVEL_linalg_matrixConcat_shp(finger3_shp, TOP_LEVEL_linalg_matrixConcat_shp(finger4_shp, finger5_shp)));;
	storage_free(stgVar1584, size1842);
	macroDef1829 = TOP_LEVEL_linalg_matrixConcat_dps(stgVar1580, finger1_dps, macroDef1828, finger1_shp, TOP_LEVEL_linalg_matrixConcat_shp(finger2_shp, TOP_LEVEL_linalg_matrixConcat_shp(finger3_shp, TOP_LEVEL_linalg_matrixConcat_shp(finger4_shp, finger5_shp))));;
	storage_free(stgVar1582, size1843);
	macroDef1830 = TOP_LEVEL_linalg_matrixConcat_dps(stgVar1446, pose_params_dps, macroDef1829, pose_params_shp, TOP_LEVEL_linalg_matrixConcat_shp(finger1_shp, TOP_LEVEL_linalg_matrixConcat_shp(finger2_shp, TOP_LEVEL_linalg_matrixConcat_shp(finger3_shp, TOP_LEVEL_linalg_matrixConcat_shp(finger4_shp, finger5_shp)))));;
	storage_free(stgVar1580, size1844);
	macroDef1831 = macroDef1830;;
	storage_free(stgVar1558, size1845);
	macroDef1832 = macroDef1831;;
	storage_free(stgVar1536, size1846);
	macroDef1833 = macroDef1832;;
	storage_free(stgVar1514, size1847);
	macroDef1834 = macroDef1833;;
	storage_free(stgVar1492, size1848);
	macroDef1835 = macroDef1834;;
	storage_free(stgVar1470, size1849);
	macroDef1836 = macroDef1835;;
	storage_free(stgVar1463, size1850);
	macroDef1837 = macroDef1836;;
	storage_free(stgVar1459, size1851);
	macroDef1838 = macroDef1837;;
	storage_free(stgVar1455, size1852);
	macroDef1839 = macroDef1838;;
	storage_free(stgVar1451, size1853);
	macroDef1840 = macroDef1839;;
	storage_free(stgVar1447, size1854);
	return macroDef1840;
}

matrix_shape_t TOP_LEVEL_usecases_ht_euler_angles_to_rotation_matrix_shp(card_t xzy_shp) {
	
	return TOP_LEVEL_linalg_matrixMult_shp(nested_shape_card_t(3, 3), TOP_LEVEL_linalg_matrixMult_shp(nested_shape_card_t(3, 3), nested_shape_card_t(3, 3)));
}


array_array_number_t TOP_LEVEL_usecases_ht_euler_angles_to_rotation_matrix_dps(storage_t stgVar1855, array_number_t xzy_dps, card_t xzy_shp) {
	card_t tx_shp = 0;
	number_t tx_dps = xzy_dps->arr[0];
	card_t ty_shp = 0;
	number_t ty_dps = xzy_dps->arr[2];
	card_t tz_shp = 0;
	number_t tz_dps = xzy_dps->arr[1];
	matrix_shape_t Rx_shp = nested_shape_card_t(3, 3);
	card_t size1954 = width_matrix_shape_t(Rx_shp);
	array_number_t stgVar1862 = storage_alloc(size1954);
	array_array_number_t macroDef1950;array_array_number_t macroDef1938 = (array_array_number_t)stgVar1862;
	macroDef1938->length=3;
	macroDef1938->arr=(array_number_t*)(STG_OFFSET(stgVar1862, VECTOR_HEADER_BYTES));
	int stgVar1862_offsetVar = 0;storage_t stgVar1863 = STG_OFFSET(stgVar1862, MATRIX_HEADER_BYTES(3) + stgVar1862_offsetVar);array_number_t macroDef1935 = (array_number_t)stgVar1863;
	macroDef1935->length=3;
	macroDef1935->arr=(number_t*)(STG_OFFSET(stgVar1863, VECTOR_HEADER_BYTES));
	

	macroDef1935->arr[0] = 1;;

	macroDef1935->arr[1] = 0;;

	macroDef1935->arr[2] = 0;;;

	macroDef1938->arr[0] = macroDef1935;;stgVar1862_offsetVar += VECTOR_ALL_BYTES(macroDef1938->arr[0]->length);storage_t stgVar1867 = STG_OFFSET(stgVar1862, MATRIX_HEADER_BYTES(3) + stgVar1862_offsetVar);array_number_t macroDef1936 = (array_number_t)stgVar1867;
	macroDef1936->length=3;
	macroDef1936->arr=(number_t*)(STG_OFFSET(stgVar1867, VECTOR_HEADER_BYTES));
	

	macroDef1936->arr[0] = 0;;

	macroDef1936->arr[1] = cos(tx_dps);;

	macroDef1936->arr[2] = -(sin(tx_dps));;;

	macroDef1938->arr[1] = macroDef1936;;stgVar1862_offsetVar += VECTOR_ALL_BYTES(macroDef1938->arr[1]->length);storage_t stgVar1871 = STG_OFFSET(stgVar1862, MATRIX_HEADER_BYTES(3) + stgVar1862_offsetVar);array_number_t macroDef1937 = (array_number_t)stgVar1871;
	macroDef1937->length=3;
	macroDef1937->arr=(number_t*)(STG_OFFSET(stgVar1871, VECTOR_HEADER_BYTES));
	

	macroDef1937->arr[0] = 0;;

	macroDef1937->arr[1] = sin(tx_dps);;

	macroDef1937->arr[2] = cos(tx_dps);;;

	macroDef1938->arr[2] = macroDef1937;;stgVar1862_offsetVar += VECTOR_ALL_BYTES(macroDef1938->arr[2]->length);;
	array_array_number_t Rx_dps = macroDef1938;
	matrix_shape_t Ry_shp = nested_shape_card_t(3, 3);
	card_t size1953 = width_matrix_shape_t(Ry_shp);
	array_number_t stgVar1875 = storage_alloc(size1953);
	array_array_number_t macroDef1949;array_array_number_t macroDef1942 = (array_array_number_t)stgVar1875;
	macroDef1942->length=3;
	macroDef1942->arr=(array_number_t*)(STG_OFFSET(stgVar1875, VECTOR_HEADER_BYTES));
	int stgVar1875_offsetVar = 0;storage_t stgVar1876 = STG_OFFSET(stgVar1875, MATRIX_HEADER_BYTES(3) + stgVar1875_offsetVar);array_number_t macroDef1939 = (array_number_t)stgVar1876;
	macroDef1939->length=3;
	macroDef1939->arr=(number_t*)(STG_OFFSET(stgVar1876, VECTOR_HEADER_BYTES));
	

	macroDef1939->arr[0] = cos(ty_dps);;

	macroDef1939->arr[1] = 0;;

	macroDef1939->arr[2] = sin(ty_dps);;;

	macroDef1942->arr[0] = macroDef1939;;stgVar1875_offsetVar += VECTOR_ALL_BYTES(macroDef1942->arr[0]->length);storage_t stgVar1880 = STG_OFFSET(stgVar1875, MATRIX_HEADER_BYTES(3) + stgVar1875_offsetVar);array_number_t macroDef1940 = (array_number_t)stgVar1880;
	macroDef1940->length=3;
	macroDef1940->arr=(number_t*)(STG_OFFSET(stgVar1880, VECTOR_HEADER_BYTES));
	

	macroDef1940->arr[0] = 0;;

	macroDef1940->arr[1] = 1;;

	macroDef1940->arr[2] = 0;;;

	macroDef1942->arr[1] = macroDef1940;;stgVar1875_offsetVar += VECTOR_ALL_BYTES(macroDef1942->arr[1]->length);storage_t stgVar1884 = STG_OFFSET(stgVar1875, MATRIX_HEADER_BYTES(3) + stgVar1875_offsetVar);array_number_t macroDef1941 = (array_number_t)stgVar1884;
	macroDef1941->length=3;
	macroDef1941->arr=(number_t*)(STG_OFFSET(stgVar1884, VECTOR_HEADER_BYTES));
	

	macroDef1941->arr[0] = -(sin(ty_dps));;

	macroDef1941->arr[1] = 0;;

	macroDef1941->arr[2] = cos(ty_dps);;;

	macroDef1942->arr[2] = macroDef1941;;stgVar1875_offsetVar += VECTOR_ALL_BYTES(macroDef1942->arr[2]->length);;
	array_array_number_t Ry_dps = macroDef1942;
	matrix_shape_t Rz_shp = nested_shape_card_t(3, 3);
	card_t size1952 = width_matrix_shape_t(Rz_shp);
	array_number_t stgVar1888 = storage_alloc(size1952);
	array_array_number_t macroDef1948;array_array_number_t macroDef1946 = (array_array_number_t)stgVar1888;
	macroDef1946->length=3;
	macroDef1946->arr=(array_number_t*)(STG_OFFSET(stgVar1888, VECTOR_HEADER_BYTES));
	int stgVar1888_offsetVar = 0;storage_t stgVar1889 = STG_OFFSET(stgVar1888, MATRIX_HEADER_BYTES(3) + stgVar1888_offsetVar);array_number_t macroDef1943 = (array_number_t)stgVar1889;
	macroDef1943->length=3;
	macroDef1943->arr=(number_t*)(STG_OFFSET(stgVar1889, VECTOR_HEADER_BYTES));
	

	macroDef1943->arr[0] = cos(tz_dps);;

	macroDef1943->arr[1] = -(sin(tz_dps));;

	macroDef1943->arr[2] = 0;;;

	macroDef1946->arr[0] = macroDef1943;;stgVar1888_offsetVar += VECTOR_ALL_BYTES(macroDef1946->arr[0]->length);storage_t stgVar1893 = STG_OFFSET(stgVar1888, MATRIX_HEADER_BYTES(3) + stgVar1888_offsetVar);array_number_t macroDef1944 = (array_number_t)stgVar1893;
	macroDef1944->length=3;
	macroDef1944->arr=(number_t*)(STG_OFFSET(stgVar1893, VECTOR_HEADER_BYTES));
	

	macroDef1944->arr[0] = sin(tz_dps);;

	macroDef1944->arr[1] = cos(tz_dps);;

	macroDef1944->arr[2] = 0;;;

	macroDef1946->arr[1] = macroDef1944;;stgVar1888_offsetVar += VECTOR_ALL_BYTES(macroDef1946->arr[1]->length);storage_t stgVar1897 = STG_OFFSET(stgVar1888, MATRIX_HEADER_BYTES(3) + stgVar1888_offsetVar);array_number_t macroDef1945 = (array_number_t)stgVar1897;
	macroDef1945->length=3;
	macroDef1945->arr=(number_t*)(STG_OFFSET(stgVar1897, VECTOR_HEADER_BYTES));
	

	macroDef1945->arr[0] = 0;;

	macroDef1945->arr[1] = 0;;

	macroDef1945->arr[2] = 1;;;

	macroDef1946->arr[2] = macroDef1945;;stgVar1888_offsetVar += VECTOR_ALL_BYTES(macroDef1946->arr[2]->length);;
	array_array_number_t Rz_dps = macroDef1946;
	card_t size1951 = width_matrix_shape_t(TOP_LEVEL_linalg_matrixMult_shp(Ry_shp, Rx_shp));
	array_number_t stgVar1902 = storage_alloc(size1951);
	array_array_number_t macroDef1947;
	macroDef1947 = TOP_LEVEL_linalg_matrixMult_dps(stgVar1855, Rz_dps, TOP_LEVEL_linalg_matrixMult_dps(stgVar1902, Ry_dps, Rx_dps, Ry_shp, Rx_shp), Rz_shp, TOP_LEVEL_linalg_matrixMult_shp(Ry_shp, Rx_shp));;
	storage_free(stgVar1902, size1951);
	macroDef1948 = macroDef1947;;
	storage_free(stgVar1888, size1952);
	macroDef1949 = macroDef1948;;
	storage_free(stgVar1875, size1953);
	macroDef1950 = macroDef1949;;
	storage_free(stgVar1862, size1954);
	return macroDef1950;
}

matrix_shape_t TOP_LEVEL_usecases_ht_make_relative_shp(card_t pose_params_shp, matrix_shape_t base_relative_shp) {
	
	return TOP_LEVEL_linalg_matrixMult_shp(base_relative_shp, TOP_LEVEL_linalg_matrixConcat_shp(TOP_LEVEL_linalg_matrixConcatCol_shp(TOP_LEVEL_usecases_ht_euler_angles_to_rotation_matrix_shp(pose_params_shp), nested_shape_card_t(1, 3)), nested_shape_card_t(4, 1)));
}


array_array_number_t TOP_LEVEL_usecases_ht_make_relative_dps(storage_t stgVar1955, array_number_t pose_params_dps, array_array_number_t base_relative_dps, card_t pose_params_shp, matrix_shape_t base_relative_shp) {
	matrix_shape_t R_shp = TOP_LEVEL_usecases_ht_euler_angles_to_rotation_matrix_shp(pose_params_shp);
	card_t size2005 = width_matrix_shape_t(R_shp);
	array_number_t stgVar1956 = storage_alloc(size2005);
	array_array_number_t macroDef2000;array_array_number_t R_dps = TOP_LEVEL_usecases_ht_euler_angles_to_rotation_matrix_dps(stgVar1956, pose_params_dps, pose_params_shp);
	matrix_shape_t r1_shp = nested_shape_card_t(1, 3);
	card_t size2004 = width_matrix_shape_t(r1_shp);
	array_number_t stgVar1958 = storage_alloc(size2004);
	array_array_number_t macroDef1999;array_array_number_t macroDef1993 = (array_array_number_t)stgVar1958;
	macroDef1993->length=3;
	macroDef1993->arr=(array_number_t*)(STG_OFFSET(stgVar1958, VECTOR_HEADER_BYTES));
	int stgVar1958_offsetVar = 0;storage_t stgVar1959 = STG_OFFSET(stgVar1958, MATRIX_HEADER_BYTES(3) + stgVar1958_offsetVar);array_number_t macroDef1990 = (array_number_t)stgVar1959;
	macroDef1990->length=1;
	macroDef1990->arr=(number_t*)(STG_OFFSET(stgVar1959, VECTOR_HEADER_BYTES));
	

	macroDef1990->arr[0] = 0;;;

	macroDef1993->arr[0] = macroDef1990;;stgVar1958_offsetVar += VECTOR_ALL_BYTES(macroDef1993->arr[0]->length);storage_t stgVar1961 = STG_OFFSET(stgVar1958, MATRIX_HEADER_BYTES(3) + stgVar1958_offsetVar);array_number_t macroDef1991 = (array_number_t)stgVar1961;
	macroDef1991->length=1;
	macroDef1991->arr=(number_t*)(STG_OFFSET(stgVar1961, VECTOR_HEADER_BYTES));
	

	macroDef1991->arr[0] = 0;;;

	macroDef1993->arr[1] = macroDef1991;;stgVar1958_offsetVar += VECTOR_ALL_BYTES(macroDef1993->arr[1]->length);storage_t stgVar1963 = STG_OFFSET(stgVar1958, MATRIX_HEADER_BYTES(3) + stgVar1958_offsetVar);array_number_t macroDef1992 = (array_number_t)stgVar1963;
	macroDef1992->length=1;
	macroDef1992->arr=(number_t*)(STG_OFFSET(stgVar1963, VECTOR_HEADER_BYTES));
	

	macroDef1992->arr[0] = 0;;;

	macroDef1993->arr[2] = macroDef1992;;stgVar1958_offsetVar += VECTOR_ALL_BYTES(macroDef1993->arr[2]->length);;
	array_array_number_t r1_dps = macroDef1993;
	matrix_shape_t r2_shp = nested_shape_card_t(4, 1);
	card_t size2003 = width_matrix_shape_t(r2_shp);
	array_number_t stgVar1965 = storage_alloc(size2003);
	array_array_number_t macroDef1998;array_array_number_t macroDef1995 = (array_array_number_t)stgVar1965;
	macroDef1995->length=1;
	macroDef1995->arr=(array_number_t*)(STG_OFFSET(stgVar1965, VECTOR_HEADER_BYTES));
	int stgVar1965_offsetVar = 0;storage_t stgVar1966 = STG_OFFSET(stgVar1965, MATRIX_HEADER_BYTES(1) + stgVar1965_offsetVar);array_number_t macroDef1994 = (array_number_t)stgVar1966;
	macroDef1994->length=4;
	macroDef1994->arr=(number_t*)(STG_OFFSET(stgVar1966, VECTOR_HEADER_BYTES));
	

	macroDef1994->arr[0] = 0;;

	macroDef1994->arr[1] = 0;;

	macroDef1994->arr[2] = 0;;

	macroDef1994->arr[3] = 1;;;

	macroDef1995->arr[0] = macroDef1994;;stgVar1965_offsetVar += VECTOR_ALL_BYTES(macroDef1995->arr[0]->length);;
	array_array_number_t r2_dps = macroDef1995;
	matrix_shape_t T_shp = TOP_LEVEL_linalg_matrixConcat_shp(TOP_LEVEL_linalg_matrixConcatCol_shp(R_shp, r1_shp), r2_shp);
	card_t size2002 = width_matrix_shape_t(T_shp);
	array_number_t stgVar1971 = storage_alloc(size2002);
	array_array_number_t macroDef1997;card_t size2001 = width_matrix_shape_t(TOP_LEVEL_linalg_matrixConcatCol_shp(R_shp, r1_shp));
	array_number_t stgVar1972 = storage_alloc(size2001);
	array_array_number_t macroDef1996;
	macroDef1996 = TOP_LEVEL_linalg_matrixConcat_dps(stgVar1971, TOP_LEVEL_linalg_matrixConcatCol_dps(stgVar1972, R_dps, r1_dps, R_shp, r1_shp), r2_dps, TOP_LEVEL_linalg_matrixConcatCol_shp(R_shp, r1_shp), r2_shp);;
	storage_free(stgVar1972, size2001);
	array_array_number_t T_dps = macroDef1996;
	macroDef1997 = TOP_LEVEL_linalg_matrixMult_dps(stgVar1955, base_relative_dps, T_dps, base_relative_shp, T_shp);;
	storage_free(stgVar1971, size2002);
	macroDef1998 = macroDef1997;;
	storage_free(stgVar1965, size2003);
	macroDef1999 = macroDef1998;;
	storage_free(stgVar1958, size2004);
	macroDef2000 = macroDef1999;;
	storage_free(stgVar1956, size2005);
	return macroDef2000;
}
typedef struct env_t_2022 {
	matrix_shape_t pose_params_shp;
	matrix3d_shape_t base_relatives_shp;
} env_t_2022;
env_t_2022 make_env_t_2022(matrix_shape_t pose_params_shp,matrix3d_shape_t base_relatives_shp) {
	env_t_2022 env;
	env.pose_params_shp = pose_params_shp;
	env.base_relatives_shp = base_relatives_shp;
	return env;
}

value_t lambda2022(env_t_2022* env2019, card_t i_bone_shp) {
	matrix_shape_t pose_params_shp2018 = env2019->pose_params_shp;
	matrix3d_shape_t base_relatives_shp2017 = env2019->base_relatives_shp;
	value_t res;
	res.matrix_shape_t_value = TOP_LEVEL_usecases_ht_make_relative_shp(pose_params_shp2018.elem, base_relatives_shp2017.elem);
	return res;
}
matrix3d_shape_t TOP_LEVEL_usecases_ht_get_posed_relatives_shp(card_t n_bones_shp, matrix_shape_t pose_params_shp, matrix3d_shape_t base_relatives_shp) {
	env_t_2022 env_t_2022_value = make_env_t_2022(pose_params_shp,base_relatives_shp); closure_t closure2021 = make_closure(lambda2022, &env_t_2022_value);
	return TOP_LEVEL_linalg_vectorMapToMatrix3D_shp(closure2021, TOP_LEVEL_linalg_vectorRange_shp(0, (n_bones_shp) - (1)));
}

typedef struct env_t_2039 {
	matrix_shape_t pose_params_shp;
	array_array_number_t pose_params_dps;
	index_t offset_dps;
	matrix3d_shape_t base_relatives_shp;
	array_array_array_number_t base_relatives_dps;
} env_t_2039;
env_t_2039 make_env_t_2039(matrix_shape_t pose_params_shp,array_array_number_t pose_params_dps,index_t offset_dps,matrix3d_shape_t base_relatives_shp,array_array_array_number_t base_relatives_dps) {
	env_t_2039 env;
	env.pose_params_shp = pose_params_shp;
	env.pose_params_dps = pose_params_dps;
	env.offset_dps = offset_dps;
	env.base_relatives_shp = base_relatives_shp;
	env.base_relatives_dps = base_relatives_dps;
	return env;
}

value_t lambda2039(env_t_2039* env2030, storage_t stgVar2010, number_t i_bone_dps, card_t i_bone_shp) {
	matrix_shape_t pose_params_shp2029 = env2030->pose_params_shp;
	array_array_number_t pose_params_dps2028 = env2030->pose_params_dps;
	index_t offset_dps2027 = env2030->offset_dps;
	matrix3d_shape_t base_relatives_shp2026 = env2030->base_relatives_shp;
	array_array_array_number_t base_relatives_dps2025 = env2030->base_relatives_dps;
	card_t size2041 = width_matrix_shape_t(base_relatives_shp2026.elem);
	array_number_t stgVar2012 = storage_alloc(size2041);
	array_array_number_t macroDef2024;card_t size2040 = width_card_t(pose_params_shp2029.elem);
	array_number_t stgVar2011 = storage_alloc(size2040);
	array_array_number_t macroDef2023;
	macroDef2023 = TOP_LEVEL_usecases_ht_make_relative_dps(stgVar2010, pose_params_dps2028->arr[((int)(i_bone_dps)) + (offset_dps2027)], base_relatives_dps2025->arr[(int)(i_bone_dps)], pose_params_shp2029.elem, base_relatives_shp2026.elem);;
	storage_free(stgVar2011, size2040);
	macroDef2024 = macroDef2023;;
	storage_free(stgVar2012, size2041);
	value_t res;
	res.array_array_number_t_value = macroDef2024;
	return res;
}
typedef struct env_t_2042 {
	matrix_shape_t pose_params_shp;
	matrix3d_shape_t base_relatives_shp;
} env_t_2042;
env_t_2042 make_env_t_2042(matrix_shape_t pose_params_shp,matrix3d_shape_t base_relatives_shp) {
	env_t_2042 env;
	env.pose_params_shp = pose_params_shp;
	env.base_relatives_shp = base_relatives_shp;
	return env;
}

value_t lambda2042(env_t_2042* env2035, card_t i_bone_shp) {
	matrix_shape_t pose_params_shp2034 = env2035->pose_params_shp;
	matrix3d_shape_t base_relatives_shp2033 = env2035->base_relatives_shp;
	value_t res;
	res.matrix_shape_t_value = TOP_LEVEL_usecases_ht_make_relative_shp(pose_params_shp2034.elem, base_relatives_shp2033.elem);
	return res;
}
array_array_array_number_t TOP_LEVEL_usecases_ht_get_posed_relatives_dps(storage_t stgVar2006, card_t n_bones_dps, array_array_number_t pose_params_dps, array_array_array_number_t base_relatives_dps, card_t n_bones_shp, matrix_shape_t pose_params_shp, matrix3d_shape_t base_relatives_shp) {
	card_t offset_shp = 0;
	index_t offset_dps = 3;
	card_t size2043 = width_card_t(TOP_LEVEL_linalg_vectorRange_shp(0, (n_bones_shp) - (1)));
	array_number_t stgVar2009 = storage_alloc(size2043);
	array_array_array_number_t macroDef2038;env_t_2039 env_t_2039_value = make_env_t_2039(pose_params_shp,pose_params_dps,offset_dps,base_relatives_shp,base_relatives_dps); closure_t closure2032 = make_closure(lambda2039, &env_t_2039_value);
	env_t_2042 env_t_2042_value = make_env_t_2042(pose_params_shp,base_relatives_shp); closure_t closure2037 = make_closure(lambda2042, &env_t_2042_value);
	macroDef2038 = TOP_LEVEL_linalg_vectorMapToMatrix3D_dps(stgVar2006, closure2032, TOP_LEVEL_linalg_vectorRange_dps(stgVar2009, 0, (n_bones_dps) - (1), 0, (n_bones_shp) - (1)), closure2037, TOP_LEVEL_linalg_vectorRange_shp(0, (n_bones_shp) - (1)));;
	storage_free(stgVar2009, size2043);
	return macroDef2038;
}

matrix_shape_t TOP_LEVEL_usecases_ht_angle_axis_to_rotation_matrix_shp(card_t angle_axis_shp) {
	
	return nested_shape_card_t(3, 3);
}


array_array_number_t TOP_LEVEL_usecases_ht_angle_axis_to_rotation_matrix_dps(storage_t stgVar2044, array_number_t angle_axis_dps, card_t angle_axis_shp) {
	card_t n_shp = 0;
	number_t n_dps = sqrt(TOP_LEVEL_linalg_sqnorm_dps(empty_storage, angle_axis_dps, angle_axis_shp));
	array_array_number_t ite2087 = 0;
	if((n_dps) < (0.0001)) {
		array_array_number_t macroDef2082 = (array_array_number_t)stgVar2044;
	macroDef2082->length=3;
	macroDef2082->arr=(array_number_t*)(STG_OFFSET(stgVar2044, VECTOR_HEADER_BYTES));
	int stgVar2044_offsetVar = 0;storage_t stgVar2047 = STG_OFFSET(stgVar2044, MATRIX_HEADER_BYTES(3) + stgVar2044_offsetVar);array_number_t macroDef2079 = (array_number_t)stgVar2047;
	macroDef2079->length=3;
	macroDef2079->arr=(number_t*)(STG_OFFSET(stgVar2047, VECTOR_HEADER_BYTES));
	

	macroDef2079->arr[0] = 1;;

	macroDef2079->arr[1] = 0;;

	macroDef2079->arr[2] = 0;;;

	macroDef2082->arr[0] = macroDef2079;;stgVar2044_offsetVar += VECTOR_ALL_BYTES(macroDef2082->arr[0]->length);storage_t stgVar2051 = STG_OFFSET(stgVar2044, MATRIX_HEADER_BYTES(3) + stgVar2044_offsetVar);array_number_t macroDef2080 = (array_number_t)stgVar2051;
	macroDef2080->length=3;
	macroDef2080->arr=(number_t*)(STG_OFFSET(stgVar2051, VECTOR_HEADER_BYTES));
	

	macroDef2080->arr[0] = 0;;

	macroDef2080->arr[1] = 1;;

	macroDef2080->arr[2] = 0;;;

	macroDef2082->arr[1] = macroDef2080;;stgVar2044_offsetVar += VECTOR_ALL_BYTES(macroDef2082->arr[1]->length);storage_t stgVar2055 = STG_OFFSET(stgVar2044, MATRIX_HEADER_BYTES(3) + stgVar2044_offsetVar);array_number_t macroDef2081 = (array_number_t)stgVar2055;
	macroDef2081->length=3;
	macroDef2081->arr=(number_t*)(STG_OFFSET(stgVar2055, VECTOR_HEADER_BYTES));
	

	macroDef2081->arr[0] = 0;;

	macroDef2081->arr[1] = 0;;

	macroDef2081->arr[2] = 1;;;

	macroDef2082->arr[2] = macroDef2081;;stgVar2044_offsetVar += VECTOR_ALL_BYTES(macroDef2082->arr[2]->length);;
		ite2087 = macroDef2082;;
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
		array_array_number_t macroDef2086 = (array_array_number_t)stgVar2044;
	macroDef2086->length=3;
	macroDef2086->arr=(array_number_t*)(STG_OFFSET(stgVar2044, VECTOR_HEADER_BYTES));
	int stgVar2044_offsetVar = 0;storage_t stgVar2067 = STG_OFFSET(stgVar2044, MATRIX_HEADER_BYTES(3) + stgVar2044_offsetVar);array_number_t macroDef2083 = (array_number_t)stgVar2067;
	macroDef2083->length=3;
	macroDef2083->arr=(number_t*)(STG_OFFSET(stgVar2067, VECTOR_HEADER_BYTES));
	

	macroDef2083->arr[0] = ((x_dps) * (x_dps)) + (((1) - ((x_dps) * (x_dps))) * (c_dps));;

	macroDef2083->arr[1] = (((x_dps) * (y_dps)) * ((1) - (c_dps))) - ((z_dps) * (s_dps));;

	macroDef2083->arr[2] = (((x_dps) * (z_dps)) * ((1) - (c_dps))) + ((y_dps) * (s_dps));;;

	macroDef2086->arr[0] = macroDef2083;;stgVar2044_offsetVar += VECTOR_ALL_BYTES(macroDef2086->arr[0]->length);storage_t stgVar2071 = STG_OFFSET(stgVar2044, MATRIX_HEADER_BYTES(3) + stgVar2044_offsetVar);array_number_t macroDef2084 = (array_number_t)stgVar2071;
	macroDef2084->length=3;
	macroDef2084->arr=(number_t*)(STG_OFFSET(stgVar2071, VECTOR_HEADER_BYTES));
	

	macroDef2084->arr[0] = (((x_dps) * (y_dps)) * ((1) - (c_dps))) + ((z_dps) * (s_dps));;

	macroDef2084->arr[1] = ((y_dps) * (y_dps)) + (((1) - ((y_dps) * (y_dps))) * (c_dps));;

	macroDef2084->arr[2] = (((y_dps) * (z_dps)) * ((1) - (c_dps))) - ((x_dps) * (s_dps));;;

	macroDef2086->arr[1] = macroDef2084;;stgVar2044_offsetVar += VECTOR_ALL_BYTES(macroDef2086->arr[1]->length);storage_t stgVar2075 = STG_OFFSET(stgVar2044, MATRIX_HEADER_BYTES(3) + stgVar2044_offsetVar);array_number_t macroDef2085 = (array_number_t)stgVar2075;
	macroDef2085->length=3;
	macroDef2085->arr=(number_t*)(STG_OFFSET(stgVar2075, VECTOR_HEADER_BYTES));
	

	macroDef2085->arr[0] = (((x_dps) * (z_dps)) * ((1) - (c_dps))) - ((y_dps) * (s_dps));;

	macroDef2085->arr[1] = (((z_dps) * (y_dps)) * ((1) - (c_dps))) + ((x_dps) * (s_dps));;

	macroDef2085->arr[2] = ((z_dps) * (z_dps)) + (((1) - ((z_dps) * (z_dps))) * (c_dps));;;

	macroDef2086->arr[2] = macroDef2085;;stgVar2044_offsetVar += VECTOR_ALL_BYTES(macroDef2086->arr[2]->length);;
		ite2087 = macroDef2086;;
	}
	return ite2087;
}
typedef struct env_t_2121 {
	matrix3d_shape_t relatives_shp;
} env_t_2121;
env_t_2121 make_env_t_2121(matrix3d_shape_t relatives_shp) {
	env_t_2121 env;
	env.relatives_shp = relatives_shp;
	return env;
}

value_t lambda2121(env_t_2121* env2118, matrix3d_shape_t acc_shp, card_t i_shp) {
	matrix3d_shape_t relatives_shp2117 = env2118->relatives_shp;
	value_t res;
	res.matrix3d_shape_t_value = TOP_LEVEL_usecases_ht_matrix3DUpdate_shp(acc_shp, 0, 0, nested_shape_matrix_shape_t(relatives_shp2117.elem, 1));
	return res;
}
matrix3d_shape_t TOP_LEVEL_usecases_ht_relatives_to_absolutes_shp(matrix3d_shape_t relatives_shp, card_t parents_shp) {
	env_t_2121 env_t_2121_value = make_env_t_2121(relatives_shp); closure_t closure2120 = make_closure(lambda2121, &env_t_2121_value);
	return TOP_LEVEL_linalg_iterateMatrix3D_shp(closure2120, relatives_shp, 0, (relatives_shp.card) - (1));
}

typedef struct env_t_2140 {
	matrix3d_shape_t relatives_shp;
	array_array_array_number_t relatives_dps;
	array_number_t parents_dps;
} env_t_2140;
env_t_2140 make_env_t_2140(matrix3d_shape_t relatives_shp,array_array_array_number_t relatives_dps,array_number_t parents_dps) {
	env_t_2140 env;
	env.relatives_shp = relatives_shp;
	env.relatives_dps = relatives_dps;
	env.parents_dps = parents_dps;
	return env;
}

value_t lambda2140(env_t_2140* env2131, storage_t stgVar2094, array_array_array_number_t acc_dps, index_t i_dps, matrix3d_shape_t acc_shp, card_t i_shp) {
	matrix3d_shape_t relatives_shp2130 = env2131->relatives_shp;
	array_array_array_number_t relatives_dps2129 = env2131->relatives_dps;
	array_number_t parents_dps2128 = env2131->parents_dps;
	array_array_array_number_t ite2139 = 0;
	if((parents_dps2128->arr[i_dps]) == (-1)) {
		matrix3d_shape_t newMatrix_shp = nested_shape_matrix_shape_t(relatives_shp2130.elem, 1);
		card_t size2141 = width_matrix3d_shape_t(newMatrix_shp);
	array_number_t stgVar2096 = storage_alloc(size2141);
	array_array_array_number_t macroDef2123;array_array_array_number_t macroDef2122 = (array_array_array_number_t)stgVar2096;
	macroDef2122->length=1;
	macroDef2122->arr=(array_array_number_t*)(STG_OFFSET(stgVar2096, VECTOR_HEADER_BYTES));
	int stgVar2096_offsetVar = 0;storage_t stgVar2097 = STG_OFFSET(stgVar2096, MATRIX_HEADER_BYTES(1) + stgVar2096_offsetVar);

	macroDef2122->arr[0] = relatives_dps2129->arr[i_dps];;stgVar2096_offsetVar += VECTOR_ALL_BYTES(macroDef2122->arr[0]->length);;
	array_array_array_number_t newMatrix_dps = macroDef2122;
	macroDef2123 = TOP_LEVEL_usecases_ht_matrix3DUpdate_dps(stgVar2094, acc_dps, i_dps, (i_dps) + (1), newMatrix_dps, acc_shp, 0, 0, newMatrix_shp);;
	storage_free(stgVar2096, size2141);
		ite2139 = macroDef2123;;
	} else {
		matrix3d_shape_t newMatrix_shp = nested_shape_matrix_shape_t(TOP_LEVEL_linalg_matrixMult_shp(acc_shp.elem, relatives_shp2130.elem), 1);
		card_t size2144 = width_matrix3d_shape_t(newMatrix_shp);
	array_number_t stgVar2103 = storage_alloc(size2144);
	array_array_array_number_t macroDef2127;array_array_array_number_t macroDef2126 = (array_array_array_number_t)stgVar2103;
	macroDef2126->length=1;
	macroDef2126->arr=(array_array_number_t*)(STG_OFFSET(stgVar2103, VECTOR_HEADER_BYTES));
	int stgVar2103_offsetVar = 0;storage_t stgVar2104 = STG_OFFSET(stgVar2103, MATRIX_HEADER_BYTES(1) + stgVar2103_offsetVar);card_t size2143 = width_matrix_shape_t(relatives_shp2130.elem);
	array_number_t stgVar2106 = storage_alloc(size2143);
	array_array_number_t macroDef2125;card_t size2142 = width_matrix_shape_t(acc_shp.elem);
	array_number_t stgVar2105 = storage_alloc(size2142);
	array_array_number_t macroDef2124;
	macroDef2124 = TOP_LEVEL_linalg_matrixMult_dps(stgVar2104, acc_dps->arr[(int)(parents_dps2128->arr[i_dps])], relatives_dps2129->arr[i_dps], acc_shp.elem, relatives_shp2130.elem);;
	storage_free(stgVar2105, size2142);
	macroDef2125 = macroDef2124;;
	storage_free(stgVar2106, size2143);

	macroDef2126->arr[0] = macroDef2125;;stgVar2103_offsetVar += VECTOR_ALL_BYTES(macroDef2126->arr[0]->length);;
	array_array_array_number_t newMatrix_dps = macroDef2126;
	macroDef2127 = TOP_LEVEL_usecases_ht_matrix3DUpdate_dps(stgVar2094, acc_dps, i_dps, (i_dps) + (1), newMatrix_dps, acc_shp, 0, 0, newMatrix_shp);;
	storage_free(stgVar2103, size2144);
		ite2139 = macroDef2127;;
	}
	value_t res;
	res.array_array_array_number_t_value = ite2139;
	return res;
}
typedef struct env_t_2145 {
	matrix3d_shape_t relatives_shp;
} env_t_2145;
env_t_2145 make_env_t_2145(matrix3d_shape_t relatives_shp) {
	env_t_2145 env;
	env.relatives_shp = relatives_shp;
	return env;
}

value_t lambda2145(env_t_2145* env2136, matrix3d_shape_t acc_shp, card_t i_shp) {
	matrix3d_shape_t relatives_shp2135 = env2136->relatives_shp;
	matrix3d_shape_t newMatrix_shp = nested_shape_matrix_shape_t(relatives_shp2135.elem, 1);
	value_t res;
	res.matrix3d_shape_t_value = TOP_LEVEL_usecases_ht_matrix3DUpdate_shp(acc_shp, 0, 0, newMatrix_shp);
	return res;
}
array_array_array_number_t TOP_LEVEL_usecases_ht_relatives_to_absolutes_dps(storage_t stgVar2088, array_array_array_number_t relatives_dps, array_number_t parents_dps, matrix3d_shape_t relatives_shp, card_t parents_shp) {
	matrix3d_shape_t init_shp = relatives_shp;
	array_array_array_number_t init_dps = relatives_dps;
	env_t_2140 env_t_2140_value = make_env_t_2140(relatives_shp,relatives_dps,parents_dps); closure_t closure2133 = make_closure(lambda2140, &env_t_2140_value);
	card_t macroDef2134 = relatives_dps->length;
	env_t_2145 env_t_2145_value = make_env_t_2145(relatives_shp); closure_t closure2138 = make_closure(lambda2145, &env_t_2145_value);
	return TOP_LEVEL_linalg_iterateMatrix3D_dps(stgVar2088, closure2133, init_dps, 0, (macroDef2134) - (1), closure2138, init_shp, 0, (relatives_shp.card) - (1));
}
typedef struct env_t_2215 {
	matrix_shape_t pose_params_shp;
} env_t_2215;
env_t_2215 make_env_t_2215(matrix_shape_t pose_params_shp) {
	env_t_2215 env;
	env.pose_params_shp = pose_params_shp;
	return env;
}

value_t lambda2215(env_t_2215* env2209, card_t row_shp) {
	matrix_shape_t pose_params_shp2208 = env2209->pose_params_shp;
	value_t res;
	res.card_t_value = TOP_LEVEL_linalg_mult_vec_elementwise_shp(row_shp, pose_params_shp2208.elem);
	return res;
}
typedef empty_env_t env_t_2216;


value_t lambda2216(env_t_2216* env2212, card_t x_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
matrix_shape_t TOP_LEVEL_usecases_ht_apply_global_transform_shp(matrix_shape_t pose_params_shp, matrix_shape_t positions_shp) {
	env_t_2215 env_t_2215_value = make_env_t_2215(pose_params_shp); closure_t closure2211 = make_closure(lambda2215, &env_t_2215_value);
	env_t_2216 env_t_2216_value = make_empty_env(); closure_t closure2214 = make_closure(lambda2216, &env_t_2216_value);
	return TOP_LEVEL_linalg_matrixMult_shp(TOP_LEVEL_linalg_matrixConcatCol_shp(TOP_LEVEL_linalg_matrixMap_shp(closure2211, TOP_LEVEL_usecases_ht_angle_axis_to_rotation_matrix_shp(pose_params_shp.elem)), TOP_LEVEL_linalg_matrixTranspose_shp(nested_shape_card_t(pose_params_shp.elem, 1))), TOP_LEVEL_linalg_matrixConcat_shp(positions_shp, nested_shape_card_t(TOP_LEVEL_linalg_vectorMap_shp(closure2214, TOP_LEVEL_linalg_vectorRange_shp(1, positions_shp.elem)), 1)));
}

typedef struct env_t_2255 {
	card_t scale_shp;
} env_t_2255;
env_t_2255 make_env_t_2255(card_t scale_shp) {
	env_t_2255 env;
	env.scale_shp = scale_shp;
	return env;
}

value_t lambda2255(env_t_2255* env2219, card_t row_shp) {
	card_t scale_shp2218 = env2219->scale_shp;
	value_t res;
	res.card_t_value = TOP_LEVEL_linalg_mult_vec_elementwise_shp(row_shp, scale_shp2218);
	return res;
}
typedef struct env_t_2256 {
	card_t scale_shp;
	array_number_t scale_dps;
} env_t_2256;
env_t_2256 make_env_t_2256(card_t scale_shp,array_number_t scale_dps) {
	env_t_2256 env;
	env.scale_shp = scale_shp;
	env.scale_dps = scale_dps;
	return env;
}

value_t lambda2256(env_t_2256* env2224, storage_t stgVar2155, array_number_t row_dps, card_t row_shp) {
	card_t scale_shp2223 = env2224->scale_shp;
	array_number_t scale_dps2222 = env2224->scale_dps;
	value_t res;
	res.array_number_t_value = TOP_LEVEL_linalg_mult_vec_elementwise_dps(stgVar2155, row_dps, scale_dps2222, row_shp, scale_shp2223);
	return res;
}
typedef struct env_t_2257 {
	card_t scale_shp;
} env_t_2257;
env_t_2257 make_env_t_2257(card_t scale_shp) {
	env_t_2257 env;
	env.scale_shp = scale_shp;
	return env;
}

value_t lambda2257(env_t_2257* env2228, card_t row_shp) {
	card_t scale_shp2227 = env2228->scale_shp;
	value_t res;
	res.card_t_value = TOP_LEVEL_linalg_mult_vec_elementwise_shp(row_shp, scale_shp2227);
	return res;
}
typedef empty_env_t env_t_2260;


value_t lambda2260(env_t_2260* env2234, card_t x_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef empty_env_t env_t_2261;


value_t lambda2261(env_t_2261* env2237, storage_t stgVar2167, number_t x_dps, card_t x_shp) {
	
	value_t res;
	res.number_t_value = 1;
	return res;
}
typedef empty_env_t env_t_2263;


value_t lambda2263(env_t_2263* env2242, card_t x_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
array_array_number_t TOP_LEVEL_usecases_ht_apply_global_transform_dps(storage_t stgVar2146, array_array_number_t pose_params_dps, array_array_number_t positions_dps, matrix_shape_t pose_params_shp, matrix_shape_t positions_shp) {
	matrix_shape_t R_shp = TOP_LEVEL_usecases_ht_angle_axis_to_rotation_matrix_shp(pose_params_shp.elem);
	card_t size2271 = width_matrix_shape_t(R_shp);
	array_number_t stgVar2147 = storage_alloc(size2271);
	array_array_number_t macroDef2253;card_t size2254 = width_card_t(pose_params_shp.elem);
	array_number_t stgVar2148 = storage_alloc(size2254);
	array_array_number_t macroDef2217;
	macroDef2217 = TOP_LEVEL_usecases_ht_angle_axis_to_rotation_matrix_dps(stgVar2147, pose_params_dps->arr[0], pose_params_shp.elem);;
	storage_free(stgVar2148, size2254);
	array_array_number_t R_dps = macroDef2217;
	card_t scale_shp = pose_params_shp.elem;
	card_t size2270 = width_card_t(scale_shp);
	array_number_t stgVar2150 = storage_alloc(size2270);
	array_array_number_t macroDef2252;array_number_t scale_dps = pose_params_dps->arr[1];
	env_t_2255 env_t_2255_value = make_env_t_2255(scale_shp); closure_t closure2221 = make_closure(lambda2255, &env_t_2255_value);
	matrix_shape_t R1_shp = TOP_LEVEL_linalg_matrixMap_shp(closure2221, R_shp);
	card_t size2269 = width_matrix_shape_t(R1_shp);
	array_number_t stgVar2152 = storage_alloc(size2269);
	array_array_number_t macroDef2251;env_t_2256 env_t_2256_value = make_env_t_2256(scale_shp,scale_dps); closure_t closure2226 = make_closure(lambda2256, &env_t_2256_value);
	env_t_2257 env_t_2257_value = make_env_t_2257(scale_shp); closure_t closure2230 = make_closure(lambda2257, &env_t_2257_value);
	array_array_number_t R1_dps = TOP_LEVEL_linalg_matrixMap_dps(stgVar2152, closure2226, R_dps, closure2230, R_shp);
	matrix_shape_t T_shp = TOP_LEVEL_linalg_matrixConcatCol_shp(R1_shp, TOP_LEVEL_linalg_matrixTranspose_shp(nested_shape_card_t(pose_params_shp.elem, 1)));
	card_t size2268 = width_matrix_shape_t(T_shp);
	array_number_t stgVar2158 = storage_alloc(size2268);
	array_array_number_t macroDef2250;card_t size2259 = width_matrix_shape_t(TOP_LEVEL_linalg_matrixTranspose_shp(nested_shape_card_t(pose_params_shp.elem, 1)));
	array_number_t stgVar2160 = storage_alloc(size2259);
	array_array_number_t macroDef2233;card_t size2258 = width_matrix_shape_t(nested_shape_card_t(pose_params_shp.elem, 1));
	array_number_t stgVar2161 = storage_alloc(size2258);
	array_array_number_t macroDef2232;array_array_number_t macroDef2231 = (array_array_number_t)stgVar2161;
	macroDef2231->length=1;
	macroDef2231->arr=(array_number_t*)(STG_OFFSET(stgVar2161, VECTOR_HEADER_BYTES));
	int stgVar2161_offsetVar = 0;storage_t stgVar2162 = STG_OFFSET(stgVar2161, MATRIX_HEADER_BYTES(1) + stgVar2161_offsetVar);

	macroDef2231->arr[0] = pose_params_dps->arr[2];;stgVar2161_offsetVar += VECTOR_ALL_BYTES(macroDef2231->arr[0]->length);;
	macroDef2232 = TOP_LEVEL_linalg_matrixTranspose_dps(stgVar2160, macroDef2231, nested_shape_card_t(pose_params_shp.elem, 1));;
	storage_free(stgVar2161, size2258);
	macroDef2233 = TOP_LEVEL_linalg_matrixConcatCol_dps(stgVar2158, R1_dps, macroDef2232, R1_shp, TOP_LEVEL_linalg_matrixTranspose_shp(nested_shape_card_t(pose_params_shp.elem, 1)));;
	storage_free(stgVar2160, size2259);
	array_array_number_t T_dps = macroDef2233;
	env_t_2260 env_t_2260_value = make_empty_env(); closure_t closure2236 = make_closure(lambda2260, &env_t_2260_value);
	card_t ones_shp = TOP_LEVEL_linalg_vectorMap_shp(closure2236, TOP_LEVEL_linalg_vectorRange_shp(1, positions_shp.elem));
	card_t size2267 = width_card_t(ones_shp);
	array_number_t stgVar2164 = storage_alloc(size2267);
	array_array_number_t macroDef2249;card_t size2264 = width_card_t(TOP_LEVEL_linalg_vectorRange_shp(1, positions_shp.elem));
	array_number_t stgVar2166 = storage_alloc(size2264);
	array_number_t macroDef2245;env_t_2261 env_t_2261_value = make_empty_env(); closure_t closure2239 = make_closure(lambda2261, &env_t_2261_value);
	card_t size2262 = width_card_t(positions_shp.elem);
	array_number_t stgVar2170 = storage_alloc(size2262);
	card_t macroDef2241;card_t macroDef2240 = positions_dps->arr[0]->length;
	macroDef2241 = macroDef2240;;
	storage_free(stgVar2170, size2262);
	env_t_2263 env_t_2263_value = make_empty_env(); closure_t closure2244 = make_closure(lambda2263, &env_t_2263_value);
	macroDef2245 = TOP_LEVEL_linalg_vectorMap_dps(stgVar2164, closure2239, TOP_LEVEL_linalg_vectorRange_dps(stgVar2166, 1, macroDef2241, 1, positions_shp.elem), closure2244, TOP_LEVEL_linalg_vectorRange_shp(1, positions_shp.elem));;
	storage_free(stgVar2166, size2264);
	array_number_t ones_dps = macroDef2245;
	matrix_shape_t positions_homog_shp = TOP_LEVEL_linalg_matrixConcat_shp(positions_shp, nested_shape_card_t(ones_shp, 1));
	card_t size2266 = width_matrix_shape_t(positions_homog_shp);
	array_number_t stgVar2172 = storage_alloc(size2266);
	array_array_number_t macroDef2248;card_t size2265 = width_matrix_shape_t(nested_shape_card_t(ones_shp, 1));
	array_number_t stgVar2174 = storage_alloc(size2265);
	array_array_number_t macroDef2247;array_array_number_t macroDef2246 = (array_array_number_t)stgVar2174;
	macroDef2246->length=1;
	macroDef2246->arr=(array_number_t*)(STG_OFFSET(stgVar2174, VECTOR_HEADER_BYTES));
	int stgVar2174_offsetVar = 0;storage_t stgVar2175 = STG_OFFSET(stgVar2174, MATRIX_HEADER_BYTES(1) + stgVar2174_offsetVar);

	macroDef2246->arr[0] = ones_dps;;stgVar2174_offsetVar += VECTOR_ALL_BYTES(macroDef2246->arr[0]->length);;
	macroDef2247 = TOP_LEVEL_linalg_matrixConcat_dps(stgVar2172, positions_dps, macroDef2246, positions_shp, nested_shape_card_t(ones_shp, 1));;
	storage_free(stgVar2174, size2265);
	array_array_number_t positions_homog_dps = macroDef2247;
	macroDef2248 = TOP_LEVEL_linalg_matrixMult_dps(stgVar2146, T_dps, positions_homog_dps, T_shp, positions_homog_shp);;
	storage_free(stgVar2172, size2266);
	macroDef2249 = macroDef2248;;
	storage_free(stgVar2164, size2267);
	macroDef2250 = macroDef2249;;
	storage_free(stgVar2158, size2268);
	macroDef2251 = macroDef2250;;
	storage_free(stgVar2152, size2269);
	macroDef2252 = macroDef2251;;
	storage_free(stgVar2150, size2270);
	macroDef2253 = macroDef2252;;
	storage_free(stgVar2147, size2271);
	return macroDef2253;
}
typedef struct env_t_2431 {
	matrix_shape_t weights_shp;
	matrix_shape_t pose_params_shp;
	card_t parents_shp;
	card_t n_bones_shp;
	matrix3d_shape_t inverse_base_absolutes_shp;
	matrix3d_shape_t base_relatives_shp;
	matrix_shape_t base_positions_shp;
} env_t_2431;
env_t_2431 make_env_t_2431(matrix_shape_t weights_shp,matrix_shape_t pose_params_shp,card_t parents_shp,card_t n_bones_shp,matrix3d_shape_t inverse_base_absolutes_shp,matrix3d_shape_t base_relatives_shp,matrix_shape_t base_positions_shp) {
	env_t_2431 env;
	env.weights_shp = weights_shp;
	env.pose_params_shp = pose_params_shp;
	env.parents_shp = parents_shp;
	env.n_bones_shp = n_bones_shp;
	env.inverse_base_absolutes_shp = inverse_base_absolutes_shp;
	env.base_relatives_shp = base_relatives_shp;
	env.base_positions_shp = base_positions_shp;
	return env;
}
typedef empty_env_t env_t_2432;


value_t lambda2432(env_t_2432* env2415, matrix_shape_t m1_shp, matrix_shape_t m2_shp) {
	
	value_t res;
	res.matrix_shape_t_value = TOP_LEVEL_linalg_matrixMult_shp(m1_shp, m2_shp);
	return res;
}
value_t lambda2431(env_t_2431* env2425, matrix_shape_t acc_shp, card_t i_transform_shp) {
	matrix_shape_t weights_shp2424 = env2425->weights_shp;
	matrix_shape_t pose_params_shp2423 = env2425->pose_params_shp;
	card_t parents_shp2422 = env2425->parents_shp;
	card_t n_bones_shp2421 = env2425->n_bones_shp;
	matrix3d_shape_t inverse_base_absolutes_shp2420 = env2425->inverse_base_absolutes_shp;
	matrix3d_shape_t base_relatives_shp2419 = env2425->base_relatives_shp;
	matrix_shape_t base_positions_shp2418 = env2425->base_positions_shp;
	env_t_2432 env_t_2432_value = make_empty_env(); closure_t closure2417 = make_closure(lambda2432, &env_t_2432_value);
	value_t res;
	res.matrix_shape_t_value = TOP_LEVEL_linalg_matrixAdd_shp(acc_shp, TOP_LEVEL_linalg_matrixMultElementwise_shp(TOP_LEVEL_linalg_matrixMult_shp(TOP_LEVEL_linalg_matrixSlice_shp(3, 0, TOP_LEVEL_linalg_matrix3DMap2_shp(closure2417, TOP_LEVEL_usecases_ht_relatives_to_absolutes_shp(TOP_LEVEL_usecases_ht_get_posed_relatives_shp(n_bones_shp2421, pose_params_shp2423, base_relatives_shp2419), parents_shp2422), inverse_base_absolutes_shp2420).elem), base_positions_shp2418), TOP_LEVEL_linalg_matrixFillFromVector_shp(base_positions_shp2418.card, weights_shp2424.elem)));
	return res;
}
typedef empty_env_t env_t_2433;


value_t lambda2433(env_t_2433* env2428, matrix_shape_t m1_shp, matrix_shape_t m2_shp) {
	
	value_t res;
	res.matrix_shape_t_value = TOP_LEVEL_linalg_matrixMult_shp(m1_shp, m2_shp);
	return res;
}
matrix_shape_t TOP_LEVEL_usecases_ht_get_skinned_vertex_positions_shp(card_t is_mirrored_shp, card_t n_bones_shp, matrix_shape_t pose_params_shp, matrix3d_shape_t base_relatives_shp, card_t parents_shp, matrix3d_shape_t inverse_base_absolutes_shp, matrix_shape_t base_positions_shp, matrix_shape_t weights_shp) {
	env_t_2431 env_t_2431_value = make_env_t_2431(weights_shp,pose_params_shp,parents_shp,n_bones_shp,inverse_base_absolutes_shp,base_relatives_shp,base_positions_shp); closure_t closure2427 = make_closure(lambda2431, &env_t_2431_value);
	env_t_2433 env_t_2433_value = make_empty_env(); closure_t closure2430 = make_closure(lambda2433, &env_t_2433_value);
	return TOP_LEVEL_usecases_ht_apply_global_transform_shp(pose_params_shp, TOP_LEVEL_linalg_matrixMult_shp(nested_shape_card_t(3, 3), TOP_LEVEL_linalg_iterateMatrix_shp(closure2427, TOP_LEVEL_linalg_matrixFill_shp(3, base_positions_shp.elem, 0), 0, (TOP_LEVEL_linalg_matrix3DMap2_shp(closure2430, TOP_LEVEL_usecases_ht_relatives_to_absolutes_shp(TOP_LEVEL_usecases_ht_get_posed_relatives_shp(n_bones_shp, pose_params_shp, base_relatives_shp), parents_shp), inverse_base_absolutes_shp).card) - (1))));
}

typedef empty_env_t env_t_2485;


value_t lambda2485(env_t_2485* env2434, matrix_shape_t m1_shp, matrix_shape_t m2_shp) {
	
	value_t res;
	res.matrix_shape_t_value = TOP_LEVEL_linalg_matrixMult_shp(m1_shp, m2_shp);
	return res;
}
typedef empty_env_t env_t_2486;


value_t lambda2486(env_t_2486* env2437, storage_t stgVar2284, array_array_number_t m1_dps, array_array_number_t m2_dps, matrix_shape_t m1_shp, matrix_shape_t m2_shp) {
	
	value_t res;
	res.array_array_number_t_value = TOP_LEVEL_linalg_matrixMult_dps(stgVar2284, m1_dps, m2_dps, m1_shp, m2_shp);
	return res;
}
typedef empty_env_t env_t_2487;


value_t lambda2487(env_t_2487* env2440, matrix_shape_t m1_shp, matrix_shape_t m2_shp) {
	
	value_t res;
	res.matrix_shape_t_value = TOP_LEVEL_linalg_matrixMult_shp(m1_shp, m2_shp);
	return res;
}
typedef struct env_t_2489 {
	matrix_shape_t weights_shp;
	matrix3d_shape_t transforms_shp;
	matrix_shape_t base_positions_shp;
} env_t_2489;
env_t_2489 make_env_t_2489(matrix_shape_t weights_shp,matrix3d_shape_t transforms_shp,matrix_shape_t base_positions_shp) {
	env_t_2489 env;
	env.weights_shp = weights_shp;
	env.transforms_shp = transforms_shp;
	env.base_positions_shp = base_positions_shp;
	return env;
}

value_t lambda2489(env_t_2489* env2448, matrix_shape_t acc_shp, card_t i_transform_shp) {
	matrix_shape_t weights_shp2447 = env2448->weights_shp;
	matrix3d_shape_t transforms_shp2446 = env2448->transforms_shp;
	matrix_shape_t base_positions_shp2445 = env2448->base_positions_shp;
	matrix_shape_t curr_positions_shp = TOP_LEVEL_linalg_matrixMult_shp(TOP_LEVEL_linalg_matrixSlice_shp(3, 0, transforms_shp2446.elem), base_positions_shp2445);
	matrix_shape_t w_shp = TOP_LEVEL_linalg_matrixFillFromVector_shp(base_positions_shp2445.card, weights_shp2447.elem);
	value_t res;
	res.matrix_shape_t_value = TOP_LEVEL_linalg_matrixAdd_shp(acc_shp, TOP_LEVEL_linalg_matrixMultElementwise_shp(curr_positions_shp, w_shp));
	return res;
}
typedef struct env_t_2490 {
	matrix_shape_t weights_shp;
	array_array_number_t weights_dps;
	matrix3d_shape_t transforms_shp;
	array_array_array_number_t transforms_dps;
	matrix_shape_t base_positions_shp;
	array_array_number_t base_positions_dps;
} env_t_2490;
env_t_2490 make_env_t_2490(matrix_shape_t weights_shp,array_array_number_t weights_dps,matrix3d_shape_t transforms_shp,array_array_array_number_t transforms_dps,matrix_shape_t base_positions_shp,array_array_number_t base_positions_dps) {
	env_t_2490 env;
	env.weights_shp = weights_shp;
	env.weights_dps = weights_dps;
	env.transforms_shp = transforms_shp;
	env.transforms_dps = transforms_dps;
	env.base_positions_shp = base_positions_shp;
	env.base_positions_dps = base_positions_dps;
	return env;
}

value_t lambda2490(env_t_2490* env2464, storage_t stgVar2299, array_array_number_t acc_dps, index_t i_transform_dps, matrix_shape_t acc_shp, card_t i_transform_shp) {
	matrix_shape_t weights_shp2463 = env2464->weights_shp;
	array_array_number_t weights_dps2462 = env2464->weights_dps;
	matrix3d_shape_t transforms_shp2461 = env2464->transforms_shp;
	array_array_array_number_t transforms_dps2460 = env2464->transforms_dps;
	matrix_shape_t base_positions_shp2459 = env2464->base_positions_shp;
	array_array_number_t base_positions_dps2458 = env2464->base_positions_dps;
	matrix_shape_t curr_positions_shp = TOP_LEVEL_linalg_matrixMult_shp(TOP_LEVEL_linalg_matrixSlice_shp(3, 0, transforms_shp2461.elem), base_positions_shp2459);
	card_t size2496 = width_matrix_shape_t(curr_positions_shp);
	array_number_t stgVar2300 = storage_alloc(size2496);
	array_array_number_t macroDef2457;card_t size2492 = width_matrix_shape_t(TOP_LEVEL_linalg_matrixSlice_shp(3, 0, transforms_shp2461.elem));
	array_number_t stgVar2301 = storage_alloc(size2492);
	array_array_number_t macroDef2452;card_t size2491 = width_matrix_shape_t(transforms_shp2461.elem);
	array_number_t stgVar2305 = storage_alloc(size2491);
	array_array_number_t macroDef2451;
	macroDef2451 = TOP_LEVEL_linalg_matrixSlice_dps(stgVar2301, 3, 0, transforms_dps2460->arr[i_transform_dps], 3, 0, transforms_shp2461.elem);;
	storage_free(stgVar2305, size2491);
	macroDef2452 = TOP_LEVEL_linalg_matrixMult_dps(stgVar2300, macroDef2451, base_positions_dps2458, TOP_LEVEL_linalg_matrixSlice_shp(3, 0, transforms_shp2461.elem), base_positions_shp2459);;
	storage_free(stgVar2301, size2492);
	array_array_number_t curr_positions_dps = macroDef2452;
	matrix_shape_t w_shp = TOP_LEVEL_linalg_matrixFillFromVector_shp(base_positions_shp2459.card, weights_shp2463.elem);
	card_t size2495 = width_matrix_shape_t(w_shp);
	array_number_t stgVar2307 = storage_alloc(size2495);
	array_array_number_t macroDef2456;card_t size2493 = width_card_t(weights_shp2463.elem);
	array_number_t stgVar2309 = storage_alloc(size2493);
	array_array_number_t macroDef2454;card_t macroDef2453 = base_positions_dps2458->length;
	macroDef2454 = TOP_LEVEL_linalg_matrixFillFromVector_dps(stgVar2307, macroDef2453, weights_dps2462->arr[i_transform_dps], base_positions_shp2459.card, weights_shp2463.elem);;
	storage_free(stgVar2309, size2493);
	array_array_number_t w_dps = macroDef2454;
	card_t size2494 = width_matrix_shape_t(TOP_LEVEL_linalg_matrixMultElementwise_shp(curr_positions_shp, w_shp));
	array_number_t stgVar2313 = storage_alloc(size2494);
	array_array_number_t macroDef2455;
	macroDef2455 = TOP_LEVEL_linalg_matrixAdd_dps(stgVar2299, acc_dps, TOP_LEVEL_linalg_matrixMultElementwise_dps(stgVar2313, curr_positions_dps, w_dps, curr_positions_shp, w_shp), acc_shp, TOP_LEVEL_linalg_matrixMultElementwise_shp(curr_positions_shp, w_shp));;
	storage_free(stgVar2313, size2494);
	macroDef2456 = macroDef2455;;
	storage_free(stgVar2307, size2495);
	macroDef2457 = macroDef2456;;
	storage_free(stgVar2300, size2496);
	value_t res;
	res.array_array_number_t_value = macroDef2457;
	return res;
}
typedef struct env_t_2497 {
	matrix_shape_t weights_shp;
	matrix3d_shape_t transforms_shp;
	matrix_shape_t base_positions_shp;
} env_t_2497;
env_t_2497 make_env_t_2497(matrix_shape_t weights_shp,matrix3d_shape_t transforms_shp,matrix_shape_t base_positions_shp) {
	env_t_2497 env;
	env.weights_shp = weights_shp;
	env.transforms_shp = transforms_shp;
	env.base_positions_shp = base_positions_shp;
	return env;
}

value_t lambda2497(env_t_2497* env2471, matrix_shape_t acc_shp, card_t i_transform_shp) {
	matrix_shape_t weights_shp2470 = env2471->weights_shp;
	matrix3d_shape_t transforms_shp2469 = env2471->transforms_shp;
	matrix_shape_t base_positions_shp2468 = env2471->base_positions_shp;
	matrix_shape_t curr_positions_shp = TOP_LEVEL_linalg_matrixMult_shp(TOP_LEVEL_linalg_matrixSlice_shp(3, 0, transforms_shp2469.elem), base_positions_shp2468);
	matrix_shape_t w_shp = TOP_LEVEL_linalg_matrixFillFromVector_shp(base_positions_shp2468.card, weights_shp2470.elem);
	value_t res;
	res.matrix_shape_t_value = TOP_LEVEL_linalg_matrixAdd_shp(acc_shp, TOP_LEVEL_linalg_matrixMultElementwise_shp(curr_positions_shp, w_shp));
	return res;
}
array_array_number_t TOP_LEVEL_usecases_ht_get_skinned_vertex_positions_dps(storage_t stgVar2272, index_t is_mirrored_dps, card_t n_bones_dps, array_array_number_t pose_params_dps, array_array_array_number_t base_relatives_dps, array_number_t parents_dps, array_array_array_number_t inverse_base_absolutes_dps, array_array_number_t base_positions_dps, array_array_number_t weights_dps, card_t is_mirrored_shp, card_t n_bones_shp, matrix_shape_t pose_params_shp, matrix3d_shape_t base_relatives_shp, card_t parents_shp, matrix3d_shape_t inverse_base_absolutes_shp, matrix_shape_t base_positions_shp, matrix_shape_t weights_shp) {
	matrix3d_shape_t relatives_shp = TOP_LEVEL_usecases_ht_get_posed_relatives_shp(n_bones_shp, pose_params_shp, base_relatives_shp);
	card_t size2504 = width_matrix3d_shape_t(relatives_shp);
	array_number_t stgVar2273 = storage_alloc(size2504);
	array_array_number_t macroDef2484;array_array_array_number_t relatives_dps = TOP_LEVEL_usecases_ht_get_posed_relatives_dps(stgVar2273, n_bones_dps, pose_params_dps, base_relatives_dps, n_bones_shp, pose_params_shp, base_relatives_shp);
	matrix3d_shape_t absolutes_shp = TOP_LEVEL_usecases_ht_relatives_to_absolutes_shp(relatives_shp, parents_shp);
	card_t size2503 = width_matrix3d_shape_t(absolutes_shp);
	array_number_t stgVar2277 = storage_alloc(size2503);
	array_array_number_t macroDef2483;array_array_array_number_t absolutes_dps = TOP_LEVEL_usecases_ht_relatives_to_absolutes_dps(stgVar2277, relatives_dps, parents_dps, relatives_shp, parents_shp);
	env_t_2485 env_t_2485_value = make_empty_env(); closure_t closure2436 = make_closure(lambda2485, &env_t_2485_value);
	matrix3d_shape_t transforms_shp = TOP_LEVEL_linalg_matrix3DMap2_shp(closure2436, absolutes_shp, inverse_base_absolutes_shp);
	card_t size2502 = width_matrix3d_shape_t(transforms_shp);
	array_number_t stgVar2280 = storage_alloc(size2502);
	array_array_number_t macroDef2482;env_t_2486 env_t_2486_value = make_empty_env(); closure_t closure2439 = make_closure(lambda2486, &env_t_2486_value);
	env_t_2487 env_t_2487_value = make_empty_env(); closure_t closure2442 = make_closure(lambda2487, &env_t_2487_value);
	array_array_array_number_t transforms_dps = TOP_LEVEL_linalg_matrix3DMap2_dps(stgVar2280, closure2439, absolutes_dps, inverse_base_absolutes_dps, closure2442, absolutes_shp, inverse_base_absolutes_shp);
	card_t n_verts_shp = base_positions_shp.elem;
	card_t size2488 = width_card_t(base_positions_shp.elem);
	array_number_t stgVar2288 = storage_alloc(size2488);
	card_t macroDef2444;card_t macroDef2443 = base_positions_dps->arr[0]->length;
	macroDef2444 = macroDef2443;;
	storage_free(stgVar2288, size2488);
	card_t n_verts_dps = macroDef2444;
	matrix_shape_t init_positions_shp = TOP_LEVEL_linalg_matrixFill_shp(3, n_verts_shp, 0);
	card_t size2501 = width_matrix_shape_t(init_positions_shp);
	array_number_t stgVar2290 = storage_alloc(size2501);
	array_array_number_t macroDef2481;array_array_number_t init_positions_dps = TOP_LEVEL_linalg_matrixFill_dps(stgVar2290, 3, n_verts_dps, 0, 3, n_verts_shp, 0);
	env_t_2489 env_t_2489_value = make_env_t_2489(weights_shp,transforms_shp,base_positions_shp); closure_t closure2450 = make_closure(lambda2489, &env_t_2489_value);
	matrix_shape_t positions_shp = TOP_LEVEL_linalg_iterateMatrix_shp(closure2450, init_positions_shp, 0, (transforms_shp.card) - (1));
	card_t size2500 = width_matrix_shape_t(positions_shp);
	array_number_t stgVar2294 = storage_alloc(size2500);
	array_array_number_t macroDef2480;env_t_2490 env_t_2490_value = make_env_t_2490(weights_shp,weights_dps,transforms_shp,transforms_dps,base_positions_shp,base_positions_dps); closure_t closure2466 = make_closure(lambda2490, &env_t_2490_value);
	card_t macroDef2467 = transforms_dps->length;
	env_t_2497 env_t_2497_value = make_env_t_2497(weights_shp,transforms_shp,base_positions_shp); closure_t closure2473 = make_closure(lambda2497, &env_t_2497_value);
	array_array_number_t positions_dps = TOP_LEVEL_linalg_iterateMatrix_dps(stgVar2294, closure2466, init_positions_dps, 0, (macroDef2467) - (1), closure2473, init_positions_shp, 0, (transforms_shp.card) - (1));
	matrix_shape_t mirror_matrix_shp = nested_shape_card_t(3, 3);
	matrix_shape_t mirrored_positions_shp = TOP_LEVEL_linalg_matrixMult_shp(mirror_matrix_shp, positions_shp);
	card_t size2499 = width_matrix_shape_t(mirrored_positions_shp);
	array_number_t stgVar2317 = storage_alloc(size2499);
	array_array_number_t macroDef2479;array_array_number_t mirrored_positions_dps = 0;
	if((is_mirrored_dps) == (1)) {
		matrix_shape_t mirror_matrix_shp0 = nested_shape_card_t(3, 3);
		card_t size2498 = width_matrix_shape_t(mirror_matrix_shp0);
	array_number_t stgVar2318 = storage_alloc(size2498);
	array_array_number_t macroDef2478;array_array_number_t macroDef2477 = (array_array_number_t)stgVar2318;
	macroDef2477->length=3;
	macroDef2477->arr=(array_number_t*)(STG_OFFSET(stgVar2318, VECTOR_HEADER_BYTES));
	int stgVar2318_offsetVar = 0;storage_t stgVar2319 = STG_OFFSET(stgVar2318, MATRIX_HEADER_BYTES(3) + stgVar2318_offsetVar);array_number_t macroDef2474 = (array_number_t)stgVar2319;
	macroDef2474->length=3;
	macroDef2474->arr=(number_t*)(STG_OFFSET(stgVar2319, VECTOR_HEADER_BYTES));
	

	macroDef2474->arr[0] = -1;;

	macroDef2474->arr[1] = 0;;

	macroDef2474->arr[2] = 0;;;

	macroDef2477->arr[0] = macroDef2474;;stgVar2318_offsetVar += VECTOR_ALL_BYTES(macroDef2477->arr[0]->length);storage_t stgVar2323 = STG_OFFSET(stgVar2318, MATRIX_HEADER_BYTES(3) + stgVar2318_offsetVar);array_number_t macroDef2475 = (array_number_t)stgVar2323;
	macroDef2475->length=3;
	macroDef2475->arr=(number_t*)(STG_OFFSET(stgVar2323, VECTOR_HEADER_BYTES));
	

	macroDef2475->arr[0] = 0;;

	macroDef2475->arr[1] = 1;;

	macroDef2475->arr[2] = 0;;;

	macroDef2477->arr[1] = macroDef2475;;stgVar2318_offsetVar += VECTOR_ALL_BYTES(macroDef2477->arr[1]->length);storage_t stgVar2327 = STG_OFFSET(stgVar2318, MATRIX_HEADER_BYTES(3) + stgVar2318_offsetVar);array_number_t macroDef2476 = (array_number_t)stgVar2327;
	macroDef2476->length=3;
	macroDef2476->arr=(number_t*)(STG_OFFSET(stgVar2327, VECTOR_HEADER_BYTES));
	

	macroDef2476->arr[0] = 0;;

	macroDef2476->arr[1] = 0;;

	macroDef2476->arr[2] = 1;;;

	macroDef2477->arr[2] = macroDef2476;;stgVar2318_offsetVar += VECTOR_ALL_BYTES(macroDef2477->arr[2]->length);;
	array_array_number_t mirror_matrix_dps = macroDef2477;
	macroDef2478 = TOP_LEVEL_linalg_matrixMult_dps(stgVar2317, mirror_matrix_dps, positions_dps, mirror_matrix_shp0, positions_shp);;
	storage_free(stgVar2318, size2498);
		mirrored_positions_dps = macroDef2478;;
	} else {
		
		mirrored_positions_dps = positions_dps;;
	}
	macroDef2479 = TOP_LEVEL_usecases_ht_apply_global_transform_dps(stgVar2272, pose_params_dps, mirrored_positions_dps, pose_params_shp, mirrored_positions_shp);;
	storage_free(stgVar2317, size2499);
	macroDef2480 = macroDef2479;;
	storage_free(stgVar2294, size2500);
	macroDef2481 = macroDef2480;;
	storage_free(stgVar2290, size2501);
	macroDef2482 = macroDef2481;;
	storage_free(stgVar2280, size2502);
	macroDef2483 = macroDef2482;;
	storage_free(stgVar2277, size2503);
	macroDef2484 = macroDef2483;;
	storage_free(stgVar2273, size2504);
	return macroDef2484;
}
typedef empty_env_t env_t_2558;


value_t lambda2558(env_t_2558* env2555, card_t i_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
card_t TOP_LEVEL_usecases_ht_hand_objective_shp(card_t is_mirrored_shp, card_t param_shp, card_t correspondences_shp, matrix_shape_t points_shp, card_t n_bones_shp, matrix3d_shape_t base_relatives_shp, card_t parents_shp, matrix3d_shape_t inverse_base_absolutes_shp, matrix_shape_t base_positions_shp, matrix_shape_t weights_shp) {
	env_t_2558 env_t_2558_value = make_empty_env(); closure_t closure2557 = make_closure(lambda2558, &env_t_2558_value);
	return TOP_LEVEL_linalg_vectorMap_shp(closure2557, TOP_LEVEL_linalg_vectorRange_shp(0, (((correspondences_shp) + (correspondences_shp)) + (correspondences_shp)) - (1)));
}

typedef empty_env_t env_t_2581;


value_t lambda2581(env_t_2581* env2560, card_t i_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef struct env_t_2582 {
	matrix_shape_t vertex_positions_shp;
	array_array_number_t vertex_positions_dps;
	matrix_shape_t points_shp;
	array_array_number_t points_dps;
	index_t n_corr_dps;
	array_number_t correspondences_dps;
} env_t_2582;
env_t_2582 make_env_t_2582(matrix_shape_t vertex_positions_shp,array_array_number_t vertex_positions_dps,matrix_shape_t points_shp,array_array_number_t points_dps,index_t n_corr_dps,array_number_t correspondences_dps) {
	env_t_2582 env;
	env.vertex_positions_shp = vertex_positions_shp;
	env.vertex_positions_dps = vertex_positions_dps;
	env.points_shp = points_shp;
	env.points_dps = points_dps;
	env.n_corr_dps = n_corr_dps;
	env.correspondences_dps = correspondences_dps;
	return env;
}

value_t lambda2582(env_t_2582* env2571, storage_t stgVar2524, number_t i_dps, card_t i_shp) {
	matrix_shape_t vertex_positions_shp2570 = env2571->vertex_positions_shp;
	array_array_number_t vertex_positions_dps2569 = env2571->vertex_positions_dps;
	matrix_shape_t points_shp2568 = env2571->points_shp;
	array_array_number_t points_dps2567 = env2571->points_dps;
	index_t n_corr_dps2566 = env2571->n_corr_dps;
	array_number_t correspondences_dps2565 = env2571->correspondences_dps;
	card_t ind_shp = 0;
	index_t ind_dps = (int)(i_dps);
	card_t r_shp = 0;
	index_t r_dps = (ind_dps) / (n_corr_dps2566);
	card_t c_shp = 0;
	index_t c_dps = (ind_dps) % (n_corr_dps2566);
	card_t size2583 = width_card_t(points_shp2568.elem);
	array_number_t stgVar2528 = storage_alloc(size2583);
	number_t macroDef2563;
	macroDef2563 = points_dps2567->arr[r_dps]->arr[c_dps];;
	storage_free(stgVar2528, size2583);
	card_t size2584 = width_card_t(vertex_positions_shp2570.elem);
	array_number_t stgVar2530 = storage_alloc(size2584);
	number_t macroDef2564;
	macroDef2564 = vertex_positions_dps2569->arr[r_dps]->arr[(int)(correspondences_dps2565->arr[c_dps])];;
	storage_free(stgVar2530, size2584);
	value_t res;
	res.number_t_value = (macroDef2563) - (macroDef2564);
	return res;
}
typedef empty_env_t env_t_2585;


value_t lambda2585(env_t_2585* env2574, card_t i_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
array_number_t TOP_LEVEL_usecases_ht_hand_objective_dps(storage_t stgVar2505, index_t is_mirrored_dps, array_number_t param_dps, array_number_t correspondences_dps, array_array_number_t points_dps, card_t n_bones_dps, array_array_array_number_t base_relatives_dps, array_number_t parents_dps, array_array_array_number_t inverse_base_absolutes_dps, array_array_number_t base_positions_dps, array_array_number_t weights_dps, card_t is_mirrored_shp, card_t param_shp, card_t correspondences_shp, matrix_shape_t points_shp, card_t n_bones_shp, matrix3d_shape_t base_relatives_shp, card_t parents_shp, matrix3d_shape_t inverse_base_absolutes_shp, matrix_shape_t base_positions_shp, matrix_shape_t weights_shp) {
	matrix_shape_t pose_params_shp = TOP_LEVEL_usecases_ht_to_pose_params_shp(param_shp, n_bones_shp);
	card_t size2589 = width_matrix_shape_t(pose_params_shp);
	array_number_t stgVar2506 = storage_alloc(size2589);
	array_number_t macroDef2580;array_array_number_t pose_params_dps = TOP_LEVEL_usecases_ht_to_pose_params_dps(stgVar2506, param_dps, n_bones_dps, param_shp, n_bones_shp);
	matrix_shape_t vertex_positions_shp = TOP_LEVEL_usecases_ht_get_skinned_vertex_positions_shp(0, n_bones_shp, pose_params_shp, base_relatives_shp, parents_shp, inverse_base_absolutes_shp, base_positions_shp, weights_shp);
	card_t size2588 = width_matrix_shape_t(vertex_positions_shp);
	array_number_t stgVar2509 = storage_alloc(size2588);
	array_number_t macroDef2579;array_array_number_t vertex_positions_dps = TOP_LEVEL_usecases_ht_get_skinned_vertex_positions_dps(stgVar2509, is_mirrored_dps, n_bones_dps, pose_params_dps, base_relatives_dps, parents_dps, inverse_base_absolutes_dps, base_positions_dps, weights_dps, 0, n_bones_shp, pose_params_shp, base_relatives_shp, parents_shp, inverse_base_absolutes_shp, base_positions_shp, weights_shp);
	card_t n_corr_card_shp = correspondences_shp;
	card_t macroDef2559 = correspondences_dps->length;
	card_t n_corr_card_dps = macroDef2559;
	card_t n_corr_shp = 0;
	index_t n_corr_dps = (n_corr_card_dps);
	env_t_2581 env_t_2581_value = make_empty_env(); closure_t closure2562 = make_closure(lambda2581, &env_t_2581_value);
	card_t err_shp = TOP_LEVEL_linalg_vectorMap_shp(closure2562, TOP_LEVEL_linalg_vectorRange_shp(0, (((n_corr_card_shp) + (n_corr_card_shp)) + (n_corr_card_shp)) - (1)));
	card_t size2587 = width_card_t(err_shp);
	array_number_t stgVar2521 = storage_alloc(size2587);
	array_number_t macroDef2578;card_t size2586 = width_card_t(TOP_LEVEL_linalg_vectorRange_shp(0, (((n_corr_card_shp) + (n_corr_card_shp)) + (n_corr_card_shp)) - (1)));
	array_number_t stgVar2523 = storage_alloc(size2586);
	array_number_t macroDef2577;env_t_2582 env_t_2582_value = make_env_t_2582(vertex_positions_shp,vertex_positions_dps,points_shp,points_dps,n_corr_dps,correspondences_dps); closure_t closure2573 = make_closure(lambda2582, &env_t_2582_value);
	env_t_2585 env_t_2585_value = make_empty_env(); closure_t closure2576 = make_closure(lambda2585, &env_t_2585_value);
	macroDef2577 = TOP_LEVEL_linalg_vectorMap_dps(stgVar2521, closure2573, TOP_LEVEL_linalg_vectorRange_dps(stgVar2523, 0, (((n_corr_card_dps) + (n_corr_card_dps)) + (n_corr_card_dps)) - (1), 0, (((n_corr_card_shp) + (n_corr_card_shp)) + (n_corr_card_shp)) - (1)), closure2576, TOP_LEVEL_linalg_vectorRange_shp(0, (((n_corr_card_shp) + (n_corr_card_shp)) + (n_corr_card_shp)) - (1)));;
	storage_free(stgVar2523, size2586);
	array_number_t err_dps = macroDef2577;
	macroDef2578 = err_dps;;
	storage_free(stgVar2521, size2587);
	macroDef2579 = macroDef2578;;
	storage_free(stgVar2509, size2588);
	macroDef2580 = macroDef2579;;
	storage_free(stgVar2506, size2589);
	return macroDef2580;
}

card_t TOP_LEVEL_usecases_ht_test_ht_shp(card_t unitVar0_shp) {
	
	return 0;
}

typedef empty_env_t env_t_2639;


value_t lambda2639(env_t_2639* env2624, card_t i_shp) {
	
	value_t res;
	res.card_t_value = 4;
	return res;
}
void TOP_LEVEL_usecases_ht_test_ht_dps(storage_t stgVar2590, int unitVar0_dps, card_t unitVar0_shp) {
	card_t a_shp = 3;
	card_t size2645 = width_card_t(a_shp);
	array_number_t stgVar2591 = storage_alloc(size2645);
	array_number_t macroDef2619 = (array_number_t)stgVar2591;
	macroDef2619->length=3;
	macroDef2619->arr=(number_t*)(STG_OFFSET(stgVar2591, VECTOR_HEADER_BYTES));
	

	macroDef2619->arr[0] = 1;;

	macroDef2619->arr[1] = 2;;

	macroDef2619->arr[2] = 3;;;
	array_number_t a_dps = macroDef2619;
	array_print(a_dps);
	matrix_shape_t mat1_shp = nested_shape_card_t(3, 3);
	card_t size2644 = width_matrix_shape_t(mat1_shp);
	array_number_t stgVar2595 = storage_alloc(size2644);
	array_array_number_t macroDef2623 = (array_array_number_t)stgVar2595;
	macroDef2623->length=3;
	macroDef2623->arr=(array_number_t*)(STG_OFFSET(stgVar2595, VECTOR_HEADER_BYTES));
	int stgVar2595_offsetVar = 0;storage_t stgVar2596 = STG_OFFSET(stgVar2595, MATRIX_HEADER_BYTES(3) + stgVar2595_offsetVar);array_number_t macroDef2620 = (array_number_t)stgVar2596;
	macroDef2620->length=3;
	macroDef2620->arr=(number_t*)(STG_OFFSET(stgVar2596, VECTOR_HEADER_BYTES));
	

	macroDef2620->arr[0] = 1;;

	macroDef2620->arr[1] = 2;;

	macroDef2620->arr[2] = 3;;;

	macroDef2623->arr[0] = macroDef2620;;stgVar2595_offsetVar += VECTOR_ALL_BYTES(macroDef2623->arr[0]->length);storage_t stgVar2600 = STG_OFFSET(stgVar2595, MATRIX_HEADER_BYTES(3) + stgVar2595_offsetVar);array_number_t macroDef2621 = (array_number_t)stgVar2600;
	macroDef2621->length=3;
	macroDef2621->arr=(number_t*)(STG_OFFSET(stgVar2600, VECTOR_HEADER_BYTES));
	

	macroDef2621->arr[0] = 4;;

	macroDef2621->arr[1] = 5;;

	macroDef2621->arr[2] = 6;;;

	macroDef2623->arr[1] = macroDef2621;;stgVar2595_offsetVar += VECTOR_ALL_BYTES(macroDef2623->arr[1]->length);storage_t stgVar2604 = STG_OFFSET(stgVar2595, MATRIX_HEADER_BYTES(3) + stgVar2595_offsetVar);array_number_t macroDef2622 = (array_number_t)stgVar2604;
	macroDef2622->length=3;
	macroDef2622->arr=(number_t*)(STG_OFFSET(stgVar2604, VECTOR_HEADER_BYTES));
	

	macroDef2622->arr[0] = 7;;

	macroDef2622->arr[1] = 8;;

	macroDef2622->arr[2] = 9;;;

	macroDef2623->arr[2] = macroDef2622;;stgVar2595_offsetVar += VECTOR_ALL_BYTES(macroDef2623->arr[2]->length);;
	array_array_number_t mat1_dps = macroDef2623;
	env_t_2639 env_t_2639_value = make_empty_env(); closure_t closure2626 = make_closure(lambda2639, &env_t_2639_value);
	matrix_shape_t base_rel_shp = nested_shape_card_t(closure2626.lam(closure2626.env, 0).card_t_value, 4);
	card_t size2643 = width_matrix_shape_t(base_rel_shp);
	array_number_t stgVar2608 = storage_alloc(size2643);
	array_array_number_t macroDef2628 = (array_array_number_t)stgVar2608;
		macroDef2628->length=4;
		macroDef2628->arr=(array_number_t*)(STG_OFFSET(macroDef2628, VECTOR_HEADER_BYTES));
		storage_t stgVar2609 = (STG_OFFSET(macroDef2628, MATRIX_HEADER_BYTES(4)));
		for(int i_dps = 0; i_dps < macroDef2628->length; i_dps++){
			array_number_t macroDef2627 = (array_number_t)stgVar2609;
		macroDef2627->length=4;
		macroDef2627->arr=(number_t*)(STG_OFFSET(macroDef2627, VECTOR_HEADER_BYTES));
		storage_t stgVar2610 = macroDef2627;
		for(int j_dps = 0; j_dps < macroDef2627->length; j_dps++){
			
			macroDef2627->arr[j_dps] = (double)((((i_dps) + (1)) * (4)) + (j_dps));;
			stgVar2610 = STG_OFFSET(stgVar2610, sizeof(number_t));
		}
			macroDef2628->arr[i_dps] = macroDef2627;;
			stgVar2609 = STG_OFFSET(stgVar2609, VECTOR_ALL_BYTES(macroDef2628->arr[i_dps]->length));
		}
	array_array_number_t base_rel_dps = macroDef2628;
	matrix_shape_t q_shp = TOP_LEVEL_usecases_ht_make_relative_shp(a_shp, base_rel_shp);
	card_t size2642 = width_matrix_shape_t(q_shp);
	array_number_t stgVar2611 = storage_alloc(size2642);
	array_array_number_t q_dps = TOP_LEVEL_usecases_ht_make_relative_dps(stgVar2611, a_dps, base_rel_dps, a_shp, base_rel_shp);
	matrix_print(q_dps);
	matrix_shape_t r_shp = TOP_LEVEL_usecases_ht_angle_axis_to_rotation_matrix_shp(a_shp);
	card_t size2641 = width_matrix_shape_t(r_shp);
	array_number_t stgVar2614 = storage_alloc(size2641);
	array_array_number_t r_dps = TOP_LEVEL_usecases_ht_angle_axis_to_rotation_matrix_dps(stgVar2614, a_dps, a_shp);
	matrix_print(r_dps);
	matrix_shape_t s_shp = TOP_LEVEL_usecases_ht_apply_global_transform_shp(mat1_shp, mat1_shp);
	card_t size2640 = width_matrix_shape_t(s_shp);
	array_number_t stgVar2616 = storage_alloc(size2640);
	array_array_number_t s_dps = TOP_LEVEL_usecases_ht_apply_global_transform_dps(stgVar2616, mat1_dps, mat1_dps, mat1_shp, mat1_shp);
	matrix_print(s_dps);
	;
	storage_free(stgVar2616, size2640);
	;
	storage_free(stgVar2614, size2641);
	;
	storage_free(stgVar2611, size2642);
	;
	storage_free(stgVar2608, size2643);
	;
	storage_free(stgVar2595, size2644);
	;
	storage_free(stgVar2591, size2645);
	return ;
}
#endif
