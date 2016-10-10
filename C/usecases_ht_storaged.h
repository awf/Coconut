#ifndef __USECASES_HT_STORAGED_H__ 
#define __USECASES_HT_STORAGED_H__ 
#include "runtime/fsharp.h"
#include <stdio.h>
#include <math.h>
#include "linalg_storaged.h"

matrix3d_shape_t TOP_LEVEL_usecases_ht_matrix3DUpdate_shp(matrix3d_shape_t m_shp, card_t s_shp, card_t e_shp, matrix3d_shape_t nm_shp) {
	
	return nested_shape_matrix_shape_t(nm_shp.elem, m_shp.card);
}


array_array_array_number_t TOP_LEVEL_usecases_ht_matrix3DUpdate_dps(storage_t stgVar1448, array_array_array_number_t m_dps, index_t s_dps, index_t e_dps, array_array_array_number_t nm_dps, matrix3d_shape_t m_shp, card_t s_shp, card_t e_shp, matrix3d_shape_t nm_shp) {
	card_t macroDef1454 = m_dps->length;
	array_array_array_number_t macroDef1455 = (array_array_array_number_t)stgVar1448;
		macroDef1455->length=macroDef1454;
		macroDef1455->arr=(array_array_number_t*)(STG_OFFSET(macroDef1455, VECTOR_HEADER_BYTES));
		storage_t stgVar1450 = (STG_OFFSET(macroDef1455, MATRIX_HEADER_BYTES(macroDef1454)));
		for(int i_dps = 0; i_dps < macroDef1455->length; i_dps++){
			card_t isInRange_shp = 0;
			bool_t isInRange_dps = 0;
	if((i_dps) >= (s_dps)) {
		
		isInRange_dps = (i_dps) < (e_dps);;
	} else {
		
		isInRange_dps = false;;
	}
			array_array_number_t ite1456 = 0;
	if(isInRange_dps) {
		
		ite1456 = nm_dps->arr[(i_dps) - (s_dps)];;
	} else {
		
		ite1456 = m_dps->arr[i_dps];;
	}
			macroDef1455->arr[i_dps] = ite1456;;
			stgVar1450 = STG_OFFSET(stgVar1450, VECTOR_ALL_BYTES(macroDef1455->arr[i_dps]->length));
		}
	return macroDef1455;
}

matrix_shape_t TOP_LEVEL_usecases_ht_to_pose_params_shp(card_t theta_shp, card_t n_bones_shp) {
	
	return TOP_LEVEL_linalg_matrixConcat_shp(nested_shape_card_t(TOP_LEVEL_linalg_vectorSlice_shp(3, 0, theta_shp), 5), TOP_LEVEL_linalg_matrixConcat_shp(nested_shape_card_t(3, 4), TOP_LEVEL_linalg_matrixConcat_shp(nested_shape_card_t(3, 4), TOP_LEVEL_linalg_matrixConcat_shp(nested_shape_card_t(3, 4), TOP_LEVEL_linalg_matrixConcat_shp(nested_shape_card_t(3, 4), nested_shape_card_t(3, 4))))));
}


array_array_number_t TOP_LEVEL_usecases_ht_to_pose_params_dps(storage_t stgVar1457, array_number_t theta_dps, card_t n_bones_dps, card_t theta_shp, card_t n_bones_shp) {
	card_t row1_shp = TOP_LEVEL_linalg_vectorSlice_shp(3, 0, theta_shp);
	card_t size1865 = width_card_t(row1_shp);
	array_number_t stgVar1458 = storage_alloc(size1865);
	array_array_number_t macroDef1851;array_number_t row1_dps = TOP_LEVEL_linalg_vectorSlice_dps(stgVar1458, 3, 0, theta_dps, 3, 0, theta_shp);
	card_t row2_shp = 3;
	card_t size1864 = width_card_t(row2_shp);
	array_number_t stgVar1462 = storage_alloc(size1864);
	array_array_number_t macroDef1850;array_number_t macroDef1810 = (array_number_t)stgVar1462;
	macroDef1810->length=3;
	macroDef1810->arr=(number_t*)(STG_OFFSET(stgVar1462, VECTOR_HEADER_BYTES));
	macroDef1810->arr[0] = 1;
	macroDef1810->arr[1] = 1;
	macroDef1810->arr[2] = 1;;
	array_number_t row2_dps = macroDef1810;
	card_t row3_shp = TOP_LEVEL_linalg_vectorSlice_shp(3, 0, theta_shp);
	card_t size1863 = width_card_t(row3_shp);
	array_number_t stgVar1466 = storage_alloc(size1863);
	array_array_number_t macroDef1849;array_number_t row3_dps = TOP_LEVEL_linalg_vectorSlice_dps(stgVar1466, 3, 3, theta_dps, 3, 0, theta_shp);
	card_t zeroRow_shp = 3;
	card_t size1862 = width_card_t(zeroRow_shp);
	array_number_t stgVar1470 = storage_alloc(size1862);
	array_array_number_t macroDef1848;array_number_t macroDef1811 = (array_number_t)stgVar1470;
	macroDef1811->length=3;
	macroDef1811->arr=(number_t*)(STG_OFFSET(stgVar1470, VECTOR_HEADER_BYTES));
	macroDef1811->arr[0] = 0;
	macroDef1811->arr[1] = 0;
	macroDef1811->arr[2] = 0;;
	array_number_t zeroRow_dps = macroDef1811;
	matrix_shape_t pose_params_shp = nested_shape_card_t(row1_shp, 5);
	card_t size1861 = width_matrix_shape_t(pose_params_shp);
	array_number_t stgVar1474 = storage_alloc(size1861);
	array_array_number_t macroDef1847;array_array_number_t macroDef1812 = (array_array_number_t)stgVar1474;
	macroDef1812->length=5;
	macroDef1812->arr=(array_number_t*)(STG_OFFSET(stgVar1474, VECTOR_HEADER_BYTES));
	storage_t stgVar1475 = STG_OFFSET(stgVar1474, MATRIX_HEADER_BYTES(5));

	macroDef1812->arr[0] = row1_dps;;storage_t stgVar1476 = STG_OFFSET(stgVar1474, MATRIX_HEADER_BYTES(5));

	macroDef1812->arr[1] = row2_dps;;storage_t stgVar1477 = STG_OFFSET(stgVar1474, MATRIX_HEADER_BYTES(5));

	macroDef1812->arr[2] = row3_dps;;storage_t stgVar1478 = STG_OFFSET(stgVar1474, MATRIX_HEADER_BYTES(5));

	macroDef1812->arr[3] = zeroRow_dps;;storage_t stgVar1479 = STG_OFFSET(stgVar1474, MATRIX_HEADER_BYTES(5));

	macroDef1812->arr[4] = zeroRow_dps;;;
	array_array_number_t pose_params_dps = macroDef1812;
	card_t i1_shp = 0;
	index_t i1_dps = 5;
	matrix_shape_t finger1_shp = nested_shape_card_t(3, 4);
	card_t size1860 = width_matrix_shape_t(finger1_shp);
	array_number_t stgVar1481 = storage_alloc(size1860);
	array_array_number_t macroDef1846;array_array_number_t macroDef1817 = (array_array_number_t)stgVar1481;
	macroDef1817->length=4;
	macroDef1817->arr=(array_number_t*)(STG_OFFSET(stgVar1481, VECTOR_HEADER_BYTES));
	storage_t stgVar1482 = STG_OFFSET(stgVar1481, MATRIX_HEADER_BYTES(4));array_number_t macroDef1813 = (array_number_t)stgVar1482;
	macroDef1813->length=3;
	macroDef1813->arr=(number_t*)(STG_OFFSET(stgVar1482, VECTOR_HEADER_BYTES));
	macroDef1813->arr[0] = theta_dps->arr[i1_dps];
	macroDef1813->arr[1] = theta_dps->arr[(i1_dps) + (1)];
	macroDef1813->arr[2] = 0;;

	macroDef1817->arr[0] = macroDef1813;;storage_t stgVar1488 = STG_OFFSET(stgVar1481, MATRIX_HEADER_BYTES(4));array_number_t macroDef1814 = (array_number_t)stgVar1488;
	macroDef1814->length=3;
	macroDef1814->arr=(number_t*)(STG_OFFSET(stgVar1488, VECTOR_HEADER_BYTES));
	macroDef1814->arr[0] = theta_dps->arr[(i1_dps) + (2)];
	macroDef1814->arr[1] = 0;
	macroDef1814->arr[2] = 0;;

	macroDef1817->arr[1] = macroDef1814;;storage_t stgVar1493 = STG_OFFSET(stgVar1481, MATRIX_HEADER_BYTES(4));array_number_t macroDef1815 = (array_number_t)stgVar1493;
	macroDef1815->length=3;
	macroDef1815->arr=(number_t*)(STG_OFFSET(stgVar1493, VECTOR_HEADER_BYTES));
	macroDef1815->arr[0] = theta_dps->arr[(i1_dps) + (3)];
	macroDef1815->arr[1] = 0;
	macroDef1815->arr[2] = 0;;

	macroDef1817->arr[2] = macroDef1815;;storage_t stgVar1498 = STG_OFFSET(stgVar1481, MATRIX_HEADER_BYTES(4));array_number_t macroDef1816 = (array_number_t)stgVar1498;
	macroDef1816->length=3;
	macroDef1816->arr=(number_t*)(STG_OFFSET(stgVar1498, VECTOR_HEADER_BYTES));
	macroDef1816->arr[0] = 0;
	macroDef1816->arr[1] = 0;
	macroDef1816->arr[2] = 0;;

	macroDef1817->arr[3] = macroDef1816;;;
	array_array_number_t finger1_dps = macroDef1817;
	card_t i2_shp = 0;
	index_t i2_dps = (i1_dps) + (4);
	matrix_shape_t finger2_shp = nested_shape_card_t(3, 4);
	card_t size1859 = width_matrix_shape_t(finger2_shp);
	array_number_t stgVar1503 = storage_alloc(size1859);
	array_array_number_t macroDef1845;array_array_number_t macroDef1822 = (array_array_number_t)stgVar1503;
	macroDef1822->length=4;
	macroDef1822->arr=(array_number_t*)(STG_OFFSET(stgVar1503, VECTOR_HEADER_BYTES));
	storage_t stgVar1504 = STG_OFFSET(stgVar1503, MATRIX_HEADER_BYTES(4));array_number_t macroDef1818 = (array_number_t)stgVar1504;
	macroDef1818->length=3;
	macroDef1818->arr=(number_t*)(STG_OFFSET(stgVar1504, VECTOR_HEADER_BYTES));
	macroDef1818->arr[0] = theta_dps->arr[i2_dps];
	macroDef1818->arr[1] = theta_dps->arr[(i2_dps) + (1)];
	macroDef1818->arr[2] = 0;;

	macroDef1822->arr[0] = macroDef1818;;storage_t stgVar1510 = STG_OFFSET(stgVar1503, MATRIX_HEADER_BYTES(4));array_number_t macroDef1819 = (array_number_t)stgVar1510;
	macroDef1819->length=3;
	macroDef1819->arr=(number_t*)(STG_OFFSET(stgVar1510, VECTOR_HEADER_BYTES));
	macroDef1819->arr[0] = theta_dps->arr[(i2_dps) + (2)];
	macroDef1819->arr[1] = 0;
	macroDef1819->arr[2] = 0;;

	macroDef1822->arr[1] = macroDef1819;;storage_t stgVar1515 = STG_OFFSET(stgVar1503, MATRIX_HEADER_BYTES(4));array_number_t macroDef1820 = (array_number_t)stgVar1515;
	macroDef1820->length=3;
	macroDef1820->arr=(number_t*)(STG_OFFSET(stgVar1515, VECTOR_HEADER_BYTES));
	macroDef1820->arr[0] = theta_dps->arr[(i2_dps) + (3)];
	macroDef1820->arr[1] = 0;
	macroDef1820->arr[2] = 0;;

	macroDef1822->arr[2] = macroDef1820;;storage_t stgVar1520 = STG_OFFSET(stgVar1503, MATRIX_HEADER_BYTES(4));array_number_t macroDef1821 = (array_number_t)stgVar1520;
	macroDef1821->length=3;
	macroDef1821->arr=(number_t*)(STG_OFFSET(stgVar1520, VECTOR_HEADER_BYTES));
	macroDef1821->arr[0] = 0;
	macroDef1821->arr[1] = 0;
	macroDef1821->arr[2] = 0;;

	macroDef1822->arr[3] = macroDef1821;;;
	array_array_number_t finger2_dps = macroDef1822;
	card_t i3_shp = 0;
	index_t i3_dps = (i2_dps) + (4);
	matrix_shape_t finger3_shp = nested_shape_card_t(3, 4);
	card_t size1858 = width_matrix_shape_t(finger3_shp);
	array_number_t stgVar1525 = storage_alloc(size1858);
	array_array_number_t macroDef1844;array_array_number_t macroDef1827 = (array_array_number_t)stgVar1525;
	macroDef1827->length=4;
	macroDef1827->arr=(array_number_t*)(STG_OFFSET(stgVar1525, VECTOR_HEADER_BYTES));
	storage_t stgVar1526 = STG_OFFSET(stgVar1525, MATRIX_HEADER_BYTES(4));array_number_t macroDef1823 = (array_number_t)stgVar1526;
	macroDef1823->length=3;
	macroDef1823->arr=(number_t*)(STG_OFFSET(stgVar1526, VECTOR_HEADER_BYTES));
	macroDef1823->arr[0] = theta_dps->arr[i3_dps];
	macroDef1823->arr[1] = theta_dps->arr[(i3_dps) + (1)];
	macroDef1823->arr[2] = 0;;

	macroDef1827->arr[0] = macroDef1823;;storage_t stgVar1532 = STG_OFFSET(stgVar1525, MATRIX_HEADER_BYTES(4));array_number_t macroDef1824 = (array_number_t)stgVar1532;
	macroDef1824->length=3;
	macroDef1824->arr=(number_t*)(STG_OFFSET(stgVar1532, VECTOR_HEADER_BYTES));
	macroDef1824->arr[0] = theta_dps->arr[(i3_dps) + (2)];
	macroDef1824->arr[1] = 0;
	macroDef1824->arr[2] = 0;;

	macroDef1827->arr[1] = macroDef1824;;storage_t stgVar1537 = STG_OFFSET(stgVar1525, MATRIX_HEADER_BYTES(4));array_number_t macroDef1825 = (array_number_t)stgVar1537;
	macroDef1825->length=3;
	macroDef1825->arr=(number_t*)(STG_OFFSET(stgVar1537, VECTOR_HEADER_BYTES));
	macroDef1825->arr[0] = theta_dps->arr[(i3_dps) + (3)];
	macroDef1825->arr[1] = 0;
	macroDef1825->arr[2] = 0;;

	macroDef1827->arr[2] = macroDef1825;;storage_t stgVar1542 = STG_OFFSET(stgVar1525, MATRIX_HEADER_BYTES(4));array_number_t macroDef1826 = (array_number_t)stgVar1542;
	macroDef1826->length=3;
	macroDef1826->arr=(number_t*)(STG_OFFSET(stgVar1542, VECTOR_HEADER_BYTES));
	macroDef1826->arr[0] = 0;
	macroDef1826->arr[1] = 0;
	macroDef1826->arr[2] = 0;;

	macroDef1827->arr[3] = macroDef1826;;;
	array_array_number_t finger3_dps = macroDef1827;
	card_t i4_shp = 0;
	index_t i4_dps = (i3_dps) + (4);
	matrix_shape_t finger4_shp = nested_shape_card_t(3, 4);
	card_t size1857 = width_matrix_shape_t(finger4_shp);
	array_number_t stgVar1547 = storage_alloc(size1857);
	array_array_number_t macroDef1843;array_array_number_t macroDef1832 = (array_array_number_t)stgVar1547;
	macroDef1832->length=4;
	macroDef1832->arr=(array_number_t*)(STG_OFFSET(stgVar1547, VECTOR_HEADER_BYTES));
	storage_t stgVar1548 = STG_OFFSET(stgVar1547, MATRIX_HEADER_BYTES(4));array_number_t macroDef1828 = (array_number_t)stgVar1548;
	macroDef1828->length=3;
	macroDef1828->arr=(number_t*)(STG_OFFSET(stgVar1548, VECTOR_HEADER_BYTES));
	macroDef1828->arr[0] = theta_dps->arr[i4_dps];
	macroDef1828->arr[1] = theta_dps->arr[(i4_dps) + (1)];
	macroDef1828->arr[2] = 0;;

	macroDef1832->arr[0] = macroDef1828;;storage_t stgVar1554 = STG_OFFSET(stgVar1547, MATRIX_HEADER_BYTES(4));array_number_t macroDef1829 = (array_number_t)stgVar1554;
	macroDef1829->length=3;
	macroDef1829->arr=(number_t*)(STG_OFFSET(stgVar1554, VECTOR_HEADER_BYTES));
	macroDef1829->arr[0] = theta_dps->arr[(i4_dps) + (2)];
	macroDef1829->arr[1] = 0;
	macroDef1829->arr[2] = 0;;

	macroDef1832->arr[1] = macroDef1829;;storage_t stgVar1559 = STG_OFFSET(stgVar1547, MATRIX_HEADER_BYTES(4));array_number_t macroDef1830 = (array_number_t)stgVar1559;
	macroDef1830->length=3;
	macroDef1830->arr=(number_t*)(STG_OFFSET(stgVar1559, VECTOR_HEADER_BYTES));
	macroDef1830->arr[0] = theta_dps->arr[(i4_dps) + (3)];
	macroDef1830->arr[1] = 0;
	macroDef1830->arr[2] = 0;;

	macroDef1832->arr[2] = macroDef1830;;storage_t stgVar1564 = STG_OFFSET(stgVar1547, MATRIX_HEADER_BYTES(4));array_number_t macroDef1831 = (array_number_t)stgVar1564;
	macroDef1831->length=3;
	macroDef1831->arr=(number_t*)(STG_OFFSET(stgVar1564, VECTOR_HEADER_BYTES));
	macroDef1831->arr[0] = 0;
	macroDef1831->arr[1] = 0;
	macroDef1831->arr[2] = 0;;

	macroDef1832->arr[3] = macroDef1831;;;
	array_array_number_t finger4_dps = macroDef1832;
	card_t i5_shp = 0;
	index_t i5_dps = (i4_dps) + (4);
	matrix_shape_t finger5_shp = nested_shape_card_t(3, 4);
	card_t size1856 = width_matrix_shape_t(finger5_shp);
	array_number_t stgVar1569 = storage_alloc(size1856);
	array_array_number_t macroDef1842;array_array_number_t macroDef1837 = (array_array_number_t)stgVar1569;
	macroDef1837->length=4;
	macroDef1837->arr=(array_number_t*)(STG_OFFSET(stgVar1569, VECTOR_HEADER_BYTES));
	storage_t stgVar1570 = STG_OFFSET(stgVar1569, MATRIX_HEADER_BYTES(4));array_number_t macroDef1833 = (array_number_t)stgVar1570;
	macroDef1833->length=3;
	macroDef1833->arr=(number_t*)(STG_OFFSET(stgVar1570, VECTOR_HEADER_BYTES));
	macroDef1833->arr[0] = theta_dps->arr[i5_dps];
	macroDef1833->arr[1] = theta_dps->arr[(i5_dps) + (1)];
	macroDef1833->arr[2] = 0;;

	macroDef1837->arr[0] = macroDef1833;;storage_t stgVar1576 = STG_OFFSET(stgVar1569, MATRIX_HEADER_BYTES(4));array_number_t macroDef1834 = (array_number_t)stgVar1576;
	macroDef1834->length=3;
	macroDef1834->arr=(number_t*)(STG_OFFSET(stgVar1576, VECTOR_HEADER_BYTES));
	macroDef1834->arr[0] = theta_dps->arr[(i5_dps) + (2)];
	macroDef1834->arr[1] = 0;
	macroDef1834->arr[2] = 0;;

	macroDef1837->arr[1] = macroDef1834;;storage_t stgVar1581 = STG_OFFSET(stgVar1569, MATRIX_HEADER_BYTES(4));array_number_t macroDef1835 = (array_number_t)stgVar1581;
	macroDef1835->length=3;
	macroDef1835->arr=(number_t*)(STG_OFFSET(stgVar1581, VECTOR_HEADER_BYTES));
	macroDef1835->arr[0] = theta_dps->arr[(i5_dps) + (3)];
	macroDef1835->arr[1] = 0;
	macroDef1835->arr[2] = 0;;

	macroDef1837->arr[2] = macroDef1835;;storage_t stgVar1586 = STG_OFFSET(stgVar1569, MATRIX_HEADER_BYTES(4));array_number_t macroDef1836 = (array_number_t)stgVar1586;
	macroDef1836->length=3;
	macroDef1836->arr=(number_t*)(STG_OFFSET(stgVar1586, VECTOR_HEADER_BYTES));
	macroDef1836->arr[0] = 0;
	macroDef1836->arr[1] = 0;
	macroDef1836->arr[2] = 0;;

	macroDef1837->arr[3] = macroDef1836;;;
	array_array_number_t finger5_dps = macroDef1837;
	card_t size1855 = width_matrix_shape_t(TOP_LEVEL_linalg_matrixConcat_shp(finger1_shp, TOP_LEVEL_linalg_matrixConcat_shp(finger2_shp, TOP_LEVEL_linalg_matrixConcat_shp(finger3_shp, TOP_LEVEL_linalg_matrixConcat_shp(finger4_shp, finger5_shp)))));
	array_number_t stgVar1591 = storage_alloc(size1855);
	array_array_number_t macroDef1841;card_t size1854 = width_matrix_shape_t(TOP_LEVEL_linalg_matrixConcat_shp(finger2_shp, TOP_LEVEL_linalg_matrixConcat_shp(finger3_shp, TOP_LEVEL_linalg_matrixConcat_shp(finger4_shp, finger5_shp))));
	array_number_t stgVar1593 = storage_alloc(size1854);
	array_array_number_t macroDef1840;card_t size1853 = width_matrix_shape_t(TOP_LEVEL_linalg_matrixConcat_shp(finger3_shp, TOP_LEVEL_linalg_matrixConcat_shp(finger4_shp, finger5_shp)));
	array_number_t stgVar1595 = storage_alloc(size1853);
	array_array_number_t macroDef1839;card_t size1852 = width_matrix_shape_t(TOP_LEVEL_linalg_matrixConcat_shp(finger4_shp, finger5_shp));
	array_number_t stgVar1597 = storage_alloc(size1852);
	array_array_number_t macroDef1838;
	macroDef1838 = TOP_LEVEL_linalg_matrixConcat_dps(stgVar1595, finger3_dps, TOP_LEVEL_linalg_matrixConcat_dps(stgVar1597, finger4_dps, finger5_dps, finger4_shp, finger5_shp), finger3_shp, TOP_LEVEL_linalg_matrixConcat_shp(finger4_shp, finger5_shp));;
	storage_free(stgVar1597, size1852);
	macroDef1839 = TOP_LEVEL_linalg_matrixConcat_dps(stgVar1593, finger2_dps, macroDef1838, finger2_shp, TOP_LEVEL_linalg_matrixConcat_shp(finger3_shp, TOP_LEVEL_linalg_matrixConcat_shp(finger4_shp, finger5_shp)));;
	storage_free(stgVar1595, size1853);
	macroDef1840 = TOP_LEVEL_linalg_matrixConcat_dps(stgVar1591, finger1_dps, macroDef1839, finger1_shp, TOP_LEVEL_linalg_matrixConcat_shp(finger2_shp, TOP_LEVEL_linalg_matrixConcat_shp(finger3_shp, TOP_LEVEL_linalg_matrixConcat_shp(finger4_shp, finger5_shp))));;
	storage_free(stgVar1593, size1854);
	macroDef1841 = TOP_LEVEL_linalg_matrixConcat_dps(stgVar1457, pose_params_dps, macroDef1840, pose_params_shp, TOP_LEVEL_linalg_matrixConcat_shp(finger1_shp, TOP_LEVEL_linalg_matrixConcat_shp(finger2_shp, TOP_LEVEL_linalg_matrixConcat_shp(finger3_shp, TOP_LEVEL_linalg_matrixConcat_shp(finger4_shp, finger5_shp)))));;
	storage_free(stgVar1591, size1855);
	macroDef1842 = macroDef1841;;
	storage_free(stgVar1569, size1856);
	macroDef1843 = macroDef1842;;
	storage_free(stgVar1547, size1857);
	macroDef1844 = macroDef1843;;
	storage_free(stgVar1525, size1858);
	macroDef1845 = macroDef1844;;
	storage_free(stgVar1503, size1859);
	macroDef1846 = macroDef1845;;
	storage_free(stgVar1481, size1860);
	macroDef1847 = macroDef1846;;
	storage_free(stgVar1474, size1861);
	macroDef1848 = macroDef1847;;
	storage_free(stgVar1470, size1862);
	macroDef1849 = macroDef1848;;
	storage_free(stgVar1466, size1863);
	macroDef1850 = macroDef1849;;
	storage_free(stgVar1462, size1864);
	macroDef1851 = macroDef1850;;
	storage_free(stgVar1458, size1865);
	return macroDef1851;
}

matrix_shape_t TOP_LEVEL_usecases_ht_euler_angles_to_rotation_matrix_shp(card_t xzy_shp) {
	
	return TOP_LEVEL_linalg_matrixMult_shp(nested_shape_card_t(3, 3), TOP_LEVEL_linalg_matrixMult_shp(nested_shape_card_t(3, 3), nested_shape_card_t(3, 3)));
}


array_array_number_t TOP_LEVEL_usecases_ht_euler_angles_to_rotation_matrix_dps(storage_t stgVar1866, array_number_t xzy_dps, card_t xzy_shp) {
	card_t tx_shp = 0;
	number_t tx_dps = xzy_dps->arr[0];
	card_t ty_shp = 0;
	number_t ty_dps = xzy_dps->arr[2];
	card_t tz_shp = 0;
	number_t tz_dps = xzy_dps->arr[1];
	matrix_shape_t Rx_shp = nested_shape_card_t(3, 3);
	card_t size1965 = width_matrix_shape_t(Rx_shp);
	array_number_t stgVar1873 = storage_alloc(size1965);
	array_array_number_t macroDef1961;array_array_number_t macroDef1949 = (array_array_number_t)stgVar1873;
	macroDef1949->length=3;
	macroDef1949->arr=(array_number_t*)(STG_OFFSET(stgVar1873, VECTOR_HEADER_BYTES));
	storage_t stgVar1874 = STG_OFFSET(stgVar1873, MATRIX_HEADER_BYTES(3));array_number_t macroDef1946 = (array_number_t)stgVar1874;
	macroDef1946->length=3;
	macroDef1946->arr=(number_t*)(STG_OFFSET(stgVar1874, VECTOR_HEADER_BYTES));
	macroDef1946->arr[0] = 1;
	macroDef1946->arr[1] = 0;
	macroDef1946->arr[2] = 0;;

	macroDef1949->arr[0] = macroDef1946;;storage_t stgVar1878 = STG_OFFSET(stgVar1873, MATRIX_HEADER_BYTES(3));array_number_t macroDef1947 = (array_number_t)stgVar1878;
	macroDef1947->length=3;
	macroDef1947->arr=(number_t*)(STG_OFFSET(stgVar1878, VECTOR_HEADER_BYTES));
	macroDef1947->arr[0] = 0;
	macroDef1947->arr[1] = cos(tx_dps);
	macroDef1947->arr[2] = -(sin(tx_dps));;

	macroDef1949->arr[1] = macroDef1947;;storage_t stgVar1882 = STG_OFFSET(stgVar1873, MATRIX_HEADER_BYTES(3));array_number_t macroDef1948 = (array_number_t)stgVar1882;
	macroDef1948->length=3;
	macroDef1948->arr=(number_t*)(STG_OFFSET(stgVar1882, VECTOR_HEADER_BYTES));
	macroDef1948->arr[0] = 0;
	macroDef1948->arr[1] = sin(tx_dps);
	macroDef1948->arr[2] = cos(tx_dps);;

	macroDef1949->arr[2] = macroDef1948;;;
	array_array_number_t Rx_dps = macroDef1949;
	matrix_shape_t Ry_shp = nested_shape_card_t(3, 3);
	card_t size1964 = width_matrix_shape_t(Ry_shp);
	array_number_t stgVar1886 = storage_alloc(size1964);
	array_array_number_t macroDef1960;array_array_number_t macroDef1953 = (array_array_number_t)stgVar1886;
	macroDef1953->length=3;
	macroDef1953->arr=(array_number_t*)(STG_OFFSET(stgVar1886, VECTOR_HEADER_BYTES));
	storage_t stgVar1887 = STG_OFFSET(stgVar1886, MATRIX_HEADER_BYTES(3));array_number_t macroDef1950 = (array_number_t)stgVar1887;
	macroDef1950->length=3;
	macroDef1950->arr=(number_t*)(STG_OFFSET(stgVar1887, VECTOR_HEADER_BYTES));
	macroDef1950->arr[0] = cos(ty_dps);
	macroDef1950->arr[1] = 0;
	macroDef1950->arr[2] = sin(ty_dps);;

	macroDef1953->arr[0] = macroDef1950;;storage_t stgVar1891 = STG_OFFSET(stgVar1886, MATRIX_HEADER_BYTES(3));array_number_t macroDef1951 = (array_number_t)stgVar1891;
	macroDef1951->length=3;
	macroDef1951->arr=(number_t*)(STG_OFFSET(stgVar1891, VECTOR_HEADER_BYTES));
	macroDef1951->arr[0] = 0;
	macroDef1951->arr[1] = 1;
	macroDef1951->arr[2] = 0;;

	macroDef1953->arr[1] = macroDef1951;;storage_t stgVar1895 = STG_OFFSET(stgVar1886, MATRIX_HEADER_BYTES(3));array_number_t macroDef1952 = (array_number_t)stgVar1895;
	macroDef1952->length=3;
	macroDef1952->arr=(number_t*)(STG_OFFSET(stgVar1895, VECTOR_HEADER_BYTES));
	macroDef1952->arr[0] = -(sin(ty_dps));
	macroDef1952->arr[1] = 0;
	macroDef1952->arr[2] = cos(ty_dps);;

	macroDef1953->arr[2] = macroDef1952;;;
	array_array_number_t Ry_dps = macroDef1953;
	matrix_shape_t Rz_shp = nested_shape_card_t(3, 3);
	card_t size1963 = width_matrix_shape_t(Rz_shp);
	array_number_t stgVar1899 = storage_alloc(size1963);
	array_array_number_t macroDef1959;array_array_number_t macroDef1957 = (array_array_number_t)stgVar1899;
	macroDef1957->length=3;
	macroDef1957->arr=(array_number_t*)(STG_OFFSET(stgVar1899, VECTOR_HEADER_BYTES));
	storage_t stgVar1900 = STG_OFFSET(stgVar1899, MATRIX_HEADER_BYTES(3));array_number_t macroDef1954 = (array_number_t)stgVar1900;
	macroDef1954->length=3;
	macroDef1954->arr=(number_t*)(STG_OFFSET(stgVar1900, VECTOR_HEADER_BYTES));
	macroDef1954->arr[0] = cos(tz_dps);
	macroDef1954->arr[1] = -(sin(tz_dps));
	macroDef1954->arr[2] = 0;;

	macroDef1957->arr[0] = macroDef1954;;storage_t stgVar1904 = STG_OFFSET(stgVar1899, MATRIX_HEADER_BYTES(3));array_number_t macroDef1955 = (array_number_t)stgVar1904;
	macroDef1955->length=3;
	macroDef1955->arr=(number_t*)(STG_OFFSET(stgVar1904, VECTOR_HEADER_BYTES));
	macroDef1955->arr[0] = sin(tz_dps);
	macroDef1955->arr[1] = cos(tz_dps);
	macroDef1955->arr[2] = 0;;

	macroDef1957->arr[1] = macroDef1955;;storage_t stgVar1908 = STG_OFFSET(stgVar1899, MATRIX_HEADER_BYTES(3));array_number_t macroDef1956 = (array_number_t)stgVar1908;
	macroDef1956->length=3;
	macroDef1956->arr=(number_t*)(STG_OFFSET(stgVar1908, VECTOR_HEADER_BYTES));
	macroDef1956->arr[0] = 0;
	macroDef1956->arr[1] = 0;
	macroDef1956->arr[2] = 1;;

	macroDef1957->arr[2] = macroDef1956;;;
	array_array_number_t Rz_dps = macroDef1957;
	card_t size1962 = width_matrix_shape_t(TOP_LEVEL_linalg_matrixMult_shp(Ry_shp, Rx_shp));
	array_number_t stgVar1913 = storage_alloc(size1962);
	array_array_number_t macroDef1958;
	macroDef1958 = TOP_LEVEL_linalg_matrixMult_dps(stgVar1866, Rz_dps, TOP_LEVEL_linalg_matrixMult_dps(stgVar1913, Ry_dps, Rx_dps, Ry_shp, Rx_shp), Rz_shp, TOP_LEVEL_linalg_matrixMult_shp(Ry_shp, Rx_shp));;
	storage_free(stgVar1913, size1962);
	macroDef1959 = macroDef1958;;
	storage_free(stgVar1899, size1963);
	macroDef1960 = macroDef1959;;
	storage_free(stgVar1886, size1964);
	macroDef1961 = macroDef1960;;
	storage_free(stgVar1873, size1965);
	return macroDef1961;
}

matrix_shape_t TOP_LEVEL_usecases_ht_make_relative_shp(card_t pose_params_shp, matrix_shape_t base_relative_shp) {
	
	return TOP_LEVEL_linalg_matrixMult_shp(base_relative_shp, TOP_LEVEL_linalg_matrixConcat_shp(TOP_LEVEL_linalg_matrixConcatCol_shp(TOP_LEVEL_usecases_ht_euler_angles_to_rotation_matrix_shp(pose_params_shp), nested_shape_card_t(1, 3)), nested_shape_card_t(4, 1)));
}


array_array_number_t TOP_LEVEL_usecases_ht_make_relative_dps(storage_t stgVar1966, array_number_t pose_params_dps, array_array_number_t base_relative_dps, card_t pose_params_shp, matrix_shape_t base_relative_shp) {
	matrix_shape_t R_shp = TOP_LEVEL_usecases_ht_euler_angles_to_rotation_matrix_shp(pose_params_shp);
	card_t size2016 = width_matrix_shape_t(R_shp);
	array_number_t stgVar1967 = storage_alloc(size2016);
	array_array_number_t macroDef2011;array_array_number_t R_dps = TOP_LEVEL_usecases_ht_euler_angles_to_rotation_matrix_dps(stgVar1967, pose_params_dps, pose_params_shp);
	matrix_shape_t r1_shp = nested_shape_card_t(1, 3);
	card_t size2015 = width_matrix_shape_t(r1_shp);
	array_number_t stgVar1969 = storage_alloc(size2015);
	array_array_number_t macroDef2010;array_array_number_t macroDef2004 = (array_array_number_t)stgVar1969;
	macroDef2004->length=3;
	macroDef2004->arr=(array_number_t*)(STG_OFFSET(stgVar1969, VECTOR_HEADER_BYTES));
	storage_t stgVar1970 = STG_OFFSET(stgVar1969, MATRIX_HEADER_BYTES(3));array_number_t macroDef2001 = (array_number_t)stgVar1970;
	macroDef2001->length=1;
	macroDef2001->arr=(number_t*)(STG_OFFSET(stgVar1970, VECTOR_HEADER_BYTES));
	macroDef2001->arr[0] = 0;;

	macroDef2004->arr[0] = macroDef2001;;storage_t stgVar1972 = STG_OFFSET(stgVar1969, MATRIX_HEADER_BYTES(3));array_number_t macroDef2002 = (array_number_t)stgVar1972;
	macroDef2002->length=1;
	macroDef2002->arr=(number_t*)(STG_OFFSET(stgVar1972, VECTOR_HEADER_BYTES));
	macroDef2002->arr[0] = 0;;

	macroDef2004->arr[1] = macroDef2002;;storage_t stgVar1974 = STG_OFFSET(stgVar1969, MATRIX_HEADER_BYTES(3));array_number_t macroDef2003 = (array_number_t)stgVar1974;
	macroDef2003->length=1;
	macroDef2003->arr=(number_t*)(STG_OFFSET(stgVar1974, VECTOR_HEADER_BYTES));
	macroDef2003->arr[0] = 0;;

	macroDef2004->arr[2] = macroDef2003;;;
	array_array_number_t r1_dps = macroDef2004;
	matrix_shape_t r2_shp = nested_shape_card_t(4, 1);
	card_t size2014 = width_matrix_shape_t(r2_shp);
	array_number_t stgVar1976 = storage_alloc(size2014);
	array_array_number_t macroDef2009;array_array_number_t macroDef2006 = (array_array_number_t)stgVar1976;
	macroDef2006->length=1;
	macroDef2006->arr=(array_number_t*)(STG_OFFSET(stgVar1976, VECTOR_HEADER_BYTES));
	storage_t stgVar1977 = STG_OFFSET(stgVar1976, MATRIX_HEADER_BYTES(1));array_number_t macroDef2005 = (array_number_t)stgVar1977;
	macroDef2005->length=4;
	macroDef2005->arr=(number_t*)(STG_OFFSET(stgVar1977, VECTOR_HEADER_BYTES));
	macroDef2005->arr[0] = 0;
	macroDef2005->arr[1] = 0;
	macroDef2005->arr[2] = 0;
	macroDef2005->arr[3] = 1;;

	macroDef2006->arr[0] = macroDef2005;;;
	array_array_number_t r2_dps = macroDef2006;
	matrix_shape_t T_shp = TOP_LEVEL_linalg_matrixConcat_shp(TOP_LEVEL_linalg_matrixConcatCol_shp(R_shp, r1_shp), r2_shp);
	card_t size2013 = width_matrix_shape_t(T_shp);
	array_number_t stgVar1982 = storage_alloc(size2013);
	array_array_number_t macroDef2008;card_t size2012 = width_matrix_shape_t(TOP_LEVEL_linalg_matrixConcatCol_shp(R_shp, r1_shp));
	array_number_t stgVar1983 = storage_alloc(size2012);
	array_array_number_t macroDef2007;
	macroDef2007 = TOP_LEVEL_linalg_matrixConcat_dps(stgVar1982, TOP_LEVEL_linalg_matrixConcatCol_dps(stgVar1983, R_dps, r1_dps, R_shp, r1_shp), r2_dps, TOP_LEVEL_linalg_matrixConcatCol_shp(R_shp, r1_shp), r2_shp);;
	storage_free(stgVar1983, size2012);
	array_array_number_t T_dps = macroDef2007;
	macroDef2008 = TOP_LEVEL_linalg_matrixMult_dps(stgVar1966, base_relative_dps, T_dps, base_relative_shp, T_shp);;
	storage_free(stgVar1982, size2013);
	macroDef2009 = macroDef2008;;
	storage_free(stgVar1976, size2014);
	macroDef2010 = macroDef2009;;
	storage_free(stgVar1969, size2015);
	macroDef2011 = macroDef2010;;
	storage_free(stgVar1967, size2016);
	return macroDef2011;
}
typedef struct env_t_2033 {
	matrix_shape_t pose_params_shp;
	matrix3d_shape_t base_relatives_shp;
} env_t_2033;
env_t_2033 make_env_t_2033(matrix_shape_t pose_params_shp,matrix3d_shape_t base_relatives_shp) {
	env_t_2033 env;
	env.pose_params_shp = pose_params_shp;
	env.base_relatives_shp = base_relatives_shp;
	return env;
}

value_t lambda2033(env_t_2033* env2030, card_t i_bone_shp) {
	matrix_shape_t pose_params_shp2029 = env2030->pose_params_shp;
	matrix3d_shape_t base_relatives_shp2028 = env2030->base_relatives_shp;
	value_t res;
	res.matrix_shape_t_value = TOP_LEVEL_usecases_ht_make_relative_shp(pose_params_shp2029.elem, base_relatives_shp2028.elem);
	return res;
}
matrix3d_shape_t TOP_LEVEL_usecases_ht_get_posed_relatives_shp(card_t n_bones_shp, matrix_shape_t pose_params_shp, matrix3d_shape_t base_relatives_shp) {
	env_t_2033 env_t_2033_value = make_env_t_2033(pose_params_shp,base_relatives_shp); closure_t closure2032 = make_closure(lambda2033, &env_t_2033_value);
	return TOP_LEVEL_linalg_vectorMapToMatrix3D_shp(closure2032, TOP_LEVEL_linalg_vectorRange_shp(0, (n_bones_shp) - (1)));
}

typedef struct env_t_2050 {
	matrix_shape_t pose_params_shp;
	array_array_number_t pose_params_dps;
	index_t offset_dps;
	matrix3d_shape_t base_relatives_shp;
	array_array_array_number_t base_relatives_dps;
} env_t_2050;
env_t_2050 make_env_t_2050(matrix_shape_t pose_params_shp,array_array_number_t pose_params_dps,index_t offset_dps,matrix3d_shape_t base_relatives_shp,array_array_array_number_t base_relatives_dps) {
	env_t_2050 env;
	env.pose_params_shp = pose_params_shp;
	env.pose_params_dps = pose_params_dps;
	env.offset_dps = offset_dps;
	env.base_relatives_shp = base_relatives_shp;
	env.base_relatives_dps = base_relatives_dps;
	return env;
}

value_t lambda2050(env_t_2050* env2041, storage_t stgVar2021, number_t i_bone_dps, card_t i_bone_shp) {
	matrix_shape_t pose_params_shp2040 = env2041->pose_params_shp;
	array_array_number_t pose_params_dps2039 = env2041->pose_params_dps;
	index_t offset_dps2038 = env2041->offset_dps;
	matrix3d_shape_t base_relatives_shp2037 = env2041->base_relatives_shp;
	array_array_array_number_t base_relatives_dps2036 = env2041->base_relatives_dps;
	card_t size2052 = width_matrix_shape_t(base_relatives_shp2037.elem);
	array_number_t stgVar2023 = storage_alloc(size2052);
	array_array_number_t macroDef2035;card_t size2051 = width_card_t(pose_params_shp2040.elem);
	array_number_t stgVar2022 = storage_alloc(size2051);
	array_array_number_t macroDef2034;
	macroDef2034 = TOP_LEVEL_usecases_ht_make_relative_dps(stgVar2021, pose_params_dps2039->arr[((int)(i_bone_dps)) + (offset_dps2038)], base_relatives_dps2036->arr[(int)(i_bone_dps)], pose_params_shp2040.elem, base_relatives_shp2037.elem);;
	storage_free(stgVar2022, size2051);
	macroDef2035 = macroDef2034;;
	storage_free(stgVar2023, size2052);
	value_t res;
	res.array_array_number_t_value = macroDef2035;
	return res;
}
typedef struct env_t_2053 {
	matrix_shape_t pose_params_shp;
	matrix3d_shape_t base_relatives_shp;
} env_t_2053;
env_t_2053 make_env_t_2053(matrix_shape_t pose_params_shp,matrix3d_shape_t base_relatives_shp) {
	env_t_2053 env;
	env.pose_params_shp = pose_params_shp;
	env.base_relatives_shp = base_relatives_shp;
	return env;
}

value_t lambda2053(env_t_2053* env2046, card_t i_bone_shp) {
	matrix_shape_t pose_params_shp2045 = env2046->pose_params_shp;
	matrix3d_shape_t base_relatives_shp2044 = env2046->base_relatives_shp;
	value_t res;
	res.matrix_shape_t_value = TOP_LEVEL_usecases_ht_make_relative_shp(pose_params_shp2045.elem, base_relatives_shp2044.elem);
	return res;
}
array_array_array_number_t TOP_LEVEL_usecases_ht_get_posed_relatives_dps(storage_t stgVar2017, card_t n_bones_dps, array_array_number_t pose_params_dps, array_array_array_number_t base_relatives_dps, card_t n_bones_shp, matrix_shape_t pose_params_shp, matrix3d_shape_t base_relatives_shp) {
	card_t offset_shp = 0;
	index_t offset_dps = 3;
	card_t size2054 = width_card_t(TOP_LEVEL_linalg_vectorRange_shp(0, (n_bones_shp) - (1)));
	array_number_t stgVar2020 = storage_alloc(size2054);
	array_array_array_number_t macroDef2049;env_t_2050 env_t_2050_value = make_env_t_2050(pose_params_shp,pose_params_dps,offset_dps,base_relatives_shp,base_relatives_dps); closure_t closure2043 = make_closure(lambda2050, &env_t_2050_value);
	env_t_2053 env_t_2053_value = make_env_t_2053(pose_params_shp,base_relatives_shp); closure_t closure2048 = make_closure(lambda2053, &env_t_2053_value);
	macroDef2049 = TOP_LEVEL_linalg_vectorMapToMatrix3D_dps(stgVar2017, closure2043, TOP_LEVEL_linalg_vectorRange_dps(stgVar2020, 0, (n_bones_dps) - (1), 0, (n_bones_shp) - (1)), closure2048, TOP_LEVEL_linalg_vectorRange_shp(0, (n_bones_shp) - (1)));;
	storage_free(stgVar2020, size2054);
	return macroDef2049;
}

matrix_shape_t TOP_LEVEL_usecases_ht_angle_axis_to_rotation_matrix_shp(card_t angle_axis_shp) {
	
	return nested_shape_card_t(3, 3);
}


array_array_number_t TOP_LEVEL_usecases_ht_angle_axis_to_rotation_matrix_dps(storage_t stgVar2055, array_number_t angle_axis_dps, card_t angle_axis_shp) {
	card_t n_shp = 0;
	number_t n_dps = sqrt(TOP_LEVEL_linalg_sqnorm_dps(empty_storage, angle_axis_dps, angle_axis_shp));
	array_array_number_t ite2098 = 0;
	if((n_dps) < (0.0001)) {
		array_array_number_t macroDef2093 = (array_array_number_t)stgVar2055;
	macroDef2093->length=3;
	macroDef2093->arr=(array_number_t*)(STG_OFFSET(stgVar2055, VECTOR_HEADER_BYTES));
	storage_t stgVar2058 = STG_OFFSET(stgVar2055, MATRIX_HEADER_BYTES(3));array_number_t macroDef2090 = (array_number_t)stgVar2058;
	macroDef2090->length=3;
	macroDef2090->arr=(number_t*)(STG_OFFSET(stgVar2058, VECTOR_HEADER_BYTES));
	macroDef2090->arr[0] = 1;
	macroDef2090->arr[1] = 0;
	macroDef2090->arr[2] = 0;;

	macroDef2093->arr[0] = macroDef2090;;storage_t stgVar2062 = STG_OFFSET(stgVar2055, MATRIX_HEADER_BYTES(3));array_number_t macroDef2091 = (array_number_t)stgVar2062;
	macroDef2091->length=3;
	macroDef2091->arr=(number_t*)(STG_OFFSET(stgVar2062, VECTOR_HEADER_BYTES));
	macroDef2091->arr[0] = 0;
	macroDef2091->arr[1] = 1;
	macroDef2091->arr[2] = 0;;

	macroDef2093->arr[1] = macroDef2091;;storage_t stgVar2066 = STG_OFFSET(stgVar2055, MATRIX_HEADER_BYTES(3));array_number_t macroDef2092 = (array_number_t)stgVar2066;
	macroDef2092->length=3;
	macroDef2092->arr=(number_t*)(STG_OFFSET(stgVar2066, VECTOR_HEADER_BYTES));
	macroDef2092->arr[0] = 0;
	macroDef2092->arr[1] = 0;
	macroDef2092->arr[2] = 1;;

	macroDef2093->arr[2] = macroDef2092;;;
		ite2098 = macroDef2093;;
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
		array_array_number_t macroDef2097 = (array_array_number_t)stgVar2055;
	macroDef2097->length=3;
	macroDef2097->arr=(array_number_t*)(STG_OFFSET(stgVar2055, VECTOR_HEADER_BYTES));
	storage_t stgVar2078 = STG_OFFSET(stgVar2055, MATRIX_HEADER_BYTES(3));array_number_t macroDef2094 = (array_number_t)stgVar2078;
	macroDef2094->length=3;
	macroDef2094->arr=(number_t*)(STG_OFFSET(stgVar2078, VECTOR_HEADER_BYTES));
	macroDef2094->arr[0] = ((x_dps) * (x_dps)) + (((1) - ((x_dps) * (x_dps))) * (c_dps));
	macroDef2094->arr[1] = (((x_dps) * (y_dps)) * ((1) - (c_dps))) - ((z_dps) * (s_dps));
	macroDef2094->arr[2] = (((x_dps) * (z_dps)) * ((1) - (c_dps))) + ((y_dps) * (s_dps));;

	macroDef2097->arr[0] = macroDef2094;;storage_t stgVar2082 = STG_OFFSET(stgVar2055, MATRIX_HEADER_BYTES(3));array_number_t macroDef2095 = (array_number_t)stgVar2082;
	macroDef2095->length=3;
	macroDef2095->arr=(number_t*)(STG_OFFSET(stgVar2082, VECTOR_HEADER_BYTES));
	macroDef2095->arr[0] = (((x_dps) * (y_dps)) * ((1) - (c_dps))) + ((z_dps) * (s_dps));
	macroDef2095->arr[1] = ((y_dps) * (y_dps)) + (((1) - ((y_dps) * (y_dps))) * (c_dps));
	macroDef2095->arr[2] = (((y_dps) * (z_dps)) * ((1) - (c_dps))) - ((x_dps) * (s_dps));;

	macroDef2097->arr[1] = macroDef2095;;storage_t stgVar2086 = STG_OFFSET(stgVar2055, MATRIX_HEADER_BYTES(3));array_number_t macroDef2096 = (array_number_t)stgVar2086;
	macroDef2096->length=3;
	macroDef2096->arr=(number_t*)(STG_OFFSET(stgVar2086, VECTOR_HEADER_BYTES));
	macroDef2096->arr[0] = (((x_dps) * (z_dps)) * ((1) - (c_dps))) - ((y_dps) * (s_dps));
	macroDef2096->arr[1] = (((z_dps) * (y_dps)) * ((1) - (c_dps))) + ((x_dps) * (s_dps));
	macroDef2096->arr[2] = ((z_dps) * (z_dps)) + (((1) - ((z_dps) * (z_dps))) * (c_dps));;

	macroDef2097->arr[2] = macroDef2096;;;
		ite2098 = macroDef2097;;
	}
	return ite2098;
}
typedef struct env_t_2132 {
	matrix3d_shape_t relatives_shp;
} env_t_2132;
env_t_2132 make_env_t_2132(matrix3d_shape_t relatives_shp) {
	env_t_2132 env;
	env.relatives_shp = relatives_shp;
	return env;
}

value_t lambda2132(env_t_2132* env2129, matrix3d_shape_t acc_shp, card_t i_shp) {
	matrix3d_shape_t relatives_shp2128 = env2129->relatives_shp;
	value_t res;
	res.matrix3d_shape_t_value = TOP_LEVEL_usecases_ht_matrix3DUpdate_shp(acc_shp, 0, 0, nested_shape_matrix_shape_t(relatives_shp2128.elem, 1));
	return res;
}
matrix3d_shape_t TOP_LEVEL_usecases_ht_relatives_to_absolutes_shp(matrix3d_shape_t relatives_shp, card_t parents_shp) {
	env_t_2132 env_t_2132_value = make_env_t_2132(relatives_shp); closure_t closure2131 = make_closure(lambda2132, &env_t_2132_value);
	return TOP_LEVEL_linalg_iterateMatrix3D_shp(closure2131, relatives_shp, 0, (relatives_shp.card) - (1));
}

typedef struct env_t_2151 {
	matrix3d_shape_t relatives_shp;
	array_array_array_number_t relatives_dps;
	array_number_t parents_dps;
} env_t_2151;
env_t_2151 make_env_t_2151(matrix3d_shape_t relatives_shp,array_array_array_number_t relatives_dps,array_number_t parents_dps) {
	env_t_2151 env;
	env.relatives_shp = relatives_shp;
	env.relatives_dps = relatives_dps;
	env.parents_dps = parents_dps;
	return env;
}

value_t lambda2151(env_t_2151* env2142, storage_t stgVar2105, array_array_array_number_t acc_dps, index_t i_dps, matrix3d_shape_t acc_shp, card_t i_shp) {
	matrix3d_shape_t relatives_shp2141 = env2142->relatives_shp;
	array_array_array_number_t relatives_dps2140 = env2142->relatives_dps;
	array_number_t parents_dps2139 = env2142->parents_dps;
	array_array_array_number_t ite2150 = 0;
	if((parents_dps2139->arr[i_dps]) == (-1)) {
		matrix3d_shape_t newMatrix_shp = nested_shape_matrix_shape_t(relatives_shp2141.elem, 1);
		card_t size2152 = width_matrix3d_shape_t(newMatrix_shp);
	array_number_t stgVar2107 = storage_alloc(size2152);
	array_array_array_number_t macroDef2134;array_array_array_number_t macroDef2133 = (array_array_array_number_t)stgVar2107;
	macroDef2133->length=1;
	macroDef2133->arr=(array_array_number_t*)(STG_OFFSET(stgVar2107, VECTOR_HEADER_BYTES));
	storage_t stgVar2108 = STG_OFFSET(stgVar2107, MATRIX_HEADER_BYTES(1));

	macroDef2133->arr[0] = relatives_dps2140->arr[i_dps];;;
	array_array_array_number_t newMatrix_dps = macroDef2133;
	macroDef2134 = TOP_LEVEL_usecases_ht_matrix3DUpdate_dps(stgVar2105, acc_dps, i_dps, (i_dps) + (1), newMatrix_dps, acc_shp, 0, 0, newMatrix_shp);;
	storage_free(stgVar2107, size2152);
		ite2150 = macroDef2134;;
	} else {
		matrix3d_shape_t newMatrix_shp = nested_shape_matrix_shape_t(TOP_LEVEL_linalg_matrixMult_shp(acc_shp.elem, relatives_shp2141.elem), 1);
		card_t size2155 = width_matrix3d_shape_t(newMatrix_shp);
	array_number_t stgVar2114 = storage_alloc(size2155);
	array_array_array_number_t macroDef2138;array_array_array_number_t macroDef2137 = (array_array_array_number_t)stgVar2114;
	macroDef2137->length=1;
	macroDef2137->arr=(array_array_number_t*)(STG_OFFSET(stgVar2114, VECTOR_HEADER_BYTES));
	storage_t stgVar2115 = STG_OFFSET(stgVar2114, MATRIX_HEADER_BYTES(1));card_t size2154 = width_matrix_shape_t(relatives_shp2141.elem);
	array_number_t stgVar2117 = storage_alloc(size2154);
	array_array_number_t macroDef2136;card_t size2153 = width_matrix_shape_t(acc_shp.elem);
	array_number_t stgVar2116 = storage_alloc(size2153);
	array_array_number_t macroDef2135;
	macroDef2135 = TOP_LEVEL_linalg_matrixMult_dps(stgVar2115, acc_dps->arr[(int)(parents_dps2139->arr[i_dps])], relatives_dps2140->arr[i_dps], acc_shp.elem, relatives_shp2141.elem);;
	storage_free(stgVar2116, size2153);
	macroDef2136 = macroDef2135;;
	storage_free(stgVar2117, size2154);

	macroDef2137->arr[0] = macroDef2136;;;
	array_array_array_number_t newMatrix_dps = macroDef2137;
	macroDef2138 = TOP_LEVEL_usecases_ht_matrix3DUpdate_dps(stgVar2105, acc_dps, i_dps, (i_dps) + (1), newMatrix_dps, acc_shp, 0, 0, newMatrix_shp);;
	storage_free(stgVar2114, size2155);
		ite2150 = macroDef2138;;
	}
	value_t res;
	res.array_array_array_number_t_value = ite2150;
	return res;
}
typedef struct env_t_2156 {
	matrix3d_shape_t relatives_shp;
} env_t_2156;
env_t_2156 make_env_t_2156(matrix3d_shape_t relatives_shp) {
	env_t_2156 env;
	env.relatives_shp = relatives_shp;
	return env;
}

value_t lambda2156(env_t_2156* env2147, matrix3d_shape_t acc_shp, card_t i_shp) {
	matrix3d_shape_t relatives_shp2146 = env2147->relatives_shp;
	matrix3d_shape_t newMatrix_shp = nested_shape_matrix_shape_t(relatives_shp2146.elem, 1);
	value_t res;
	res.matrix3d_shape_t_value = TOP_LEVEL_usecases_ht_matrix3DUpdate_shp(acc_shp, 0, 0, newMatrix_shp);
	return res;
}
array_array_array_number_t TOP_LEVEL_usecases_ht_relatives_to_absolutes_dps(storage_t stgVar2099, array_array_array_number_t relatives_dps, array_number_t parents_dps, matrix3d_shape_t relatives_shp, card_t parents_shp) {
	matrix3d_shape_t init_shp = relatives_shp;
	array_array_array_number_t init_dps = relatives_dps;
	env_t_2151 env_t_2151_value = make_env_t_2151(relatives_shp,relatives_dps,parents_dps); closure_t closure2144 = make_closure(lambda2151, &env_t_2151_value);
	card_t macroDef2145 = relatives_dps->length;
	env_t_2156 env_t_2156_value = make_env_t_2156(relatives_shp); closure_t closure2149 = make_closure(lambda2156, &env_t_2156_value);
	return TOP_LEVEL_linalg_iterateMatrix3D_dps(stgVar2099, closure2144, init_dps, 0, (macroDef2145) - (1), closure2149, init_shp, 0, (relatives_shp.card) - (1));
}
typedef struct env_t_2226 {
	matrix_shape_t pose_params_shp;
} env_t_2226;
env_t_2226 make_env_t_2226(matrix_shape_t pose_params_shp) {
	env_t_2226 env;
	env.pose_params_shp = pose_params_shp;
	return env;
}

value_t lambda2226(env_t_2226* env2220, card_t row_shp) {
	matrix_shape_t pose_params_shp2219 = env2220->pose_params_shp;
	value_t res;
	res.card_t_value = TOP_LEVEL_linalg_mult_vec_elementwise_shp(row_shp, pose_params_shp2219.elem);
	return res;
}
typedef empty_env_t env_t_2227;


value_t lambda2227(env_t_2227* env2223, card_t x_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
matrix_shape_t TOP_LEVEL_usecases_ht_apply_global_transform_shp(matrix_shape_t pose_params_shp, matrix_shape_t positions_shp) {
	env_t_2226 env_t_2226_value = make_env_t_2226(pose_params_shp); closure_t closure2222 = make_closure(lambda2226, &env_t_2226_value);
	env_t_2227 env_t_2227_value = make_empty_env(); closure_t closure2225 = make_closure(lambda2227, &env_t_2227_value);
	return TOP_LEVEL_linalg_matrixMult_shp(TOP_LEVEL_linalg_matrixConcatCol_shp(TOP_LEVEL_linalg_matrixMap_shp(closure2222, TOP_LEVEL_usecases_ht_angle_axis_to_rotation_matrix_shp(pose_params_shp.elem)), TOP_LEVEL_linalg_matrixTranspose_shp(nested_shape_card_t(pose_params_shp.elem, 1))), TOP_LEVEL_linalg_matrixConcat_shp(positions_shp, nested_shape_card_t(TOP_LEVEL_linalg_vectorMap_shp(closure2225, TOP_LEVEL_linalg_vectorRange_shp(1, positions_shp.elem)), 1)));
}

typedef struct env_t_2266 {
	card_t scale_shp;
} env_t_2266;
env_t_2266 make_env_t_2266(card_t scale_shp) {
	env_t_2266 env;
	env.scale_shp = scale_shp;
	return env;
}

value_t lambda2266(env_t_2266* env2230, card_t row_shp) {
	card_t scale_shp2229 = env2230->scale_shp;
	value_t res;
	res.card_t_value = TOP_LEVEL_linalg_mult_vec_elementwise_shp(row_shp, scale_shp2229);
	return res;
}
typedef struct env_t_2267 {
	card_t scale_shp;
	array_number_t scale_dps;
} env_t_2267;
env_t_2267 make_env_t_2267(card_t scale_shp,array_number_t scale_dps) {
	env_t_2267 env;
	env.scale_shp = scale_shp;
	env.scale_dps = scale_dps;
	return env;
}

value_t lambda2267(env_t_2267* env2235, storage_t stgVar2166, array_number_t row_dps, card_t row_shp) {
	card_t scale_shp2234 = env2235->scale_shp;
	array_number_t scale_dps2233 = env2235->scale_dps;
	value_t res;
	res.array_number_t_value = TOP_LEVEL_linalg_mult_vec_elementwise_dps(stgVar2166, row_dps, scale_dps2233, row_shp, scale_shp2234);
	return res;
}
typedef struct env_t_2268 {
	card_t scale_shp;
} env_t_2268;
env_t_2268 make_env_t_2268(card_t scale_shp) {
	env_t_2268 env;
	env.scale_shp = scale_shp;
	return env;
}

value_t lambda2268(env_t_2268* env2239, card_t row_shp) {
	card_t scale_shp2238 = env2239->scale_shp;
	value_t res;
	res.card_t_value = TOP_LEVEL_linalg_mult_vec_elementwise_shp(row_shp, scale_shp2238);
	return res;
}
typedef empty_env_t env_t_2271;


value_t lambda2271(env_t_2271* env2245, card_t x_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef empty_env_t env_t_2272;


value_t lambda2272(env_t_2272* env2248, storage_t stgVar2178, number_t x_dps, card_t x_shp) {
	
	value_t res;
	res.number_t_value = 1;
	return res;
}
typedef empty_env_t env_t_2274;


value_t lambda2274(env_t_2274* env2253, card_t x_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
array_array_number_t TOP_LEVEL_usecases_ht_apply_global_transform_dps(storage_t stgVar2157, array_array_number_t pose_params_dps, array_array_number_t positions_dps, matrix_shape_t pose_params_shp, matrix_shape_t positions_shp) {
	matrix_shape_t R_shp = TOP_LEVEL_usecases_ht_angle_axis_to_rotation_matrix_shp(pose_params_shp.elem);
	card_t size2282 = width_matrix_shape_t(R_shp);
	array_number_t stgVar2158 = storage_alloc(size2282);
	array_array_number_t macroDef2264;card_t size2265 = width_card_t(pose_params_shp.elem);
	array_number_t stgVar2159 = storage_alloc(size2265);
	array_array_number_t macroDef2228;
	macroDef2228 = TOP_LEVEL_usecases_ht_angle_axis_to_rotation_matrix_dps(stgVar2158, pose_params_dps->arr[0], pose_params_shp.elem);;
	storage_free(stgVar2159, size2265);
	array_array_number_t R_dps = macroDef2228;
	card_t scale_shp = pose_params_shp.elem;
	card_t size2281 = width_card_t(scale_shp);
	array_number_t stgVar2161 = storage_alloc(size2281);
	array_array_number_t macroDef2263;array_number_t scale_dps = pose_params_dps->arr[1];
	env_t_2266 env_t_2266_value = make_env_t_2266(scale_shp); closure_t closure2232 = make_closure(lambda2266, &env_t_2266_value);
	matrix_shape_t R1_shp = TOP_LEVEL_linalg_matrixMap_shp(closure2232, R_shp);
	card_t size2280 = width_matrix_shape_t(R1_shp);
	array_number_t stgVar2163 = storage_alloc(size2280);
	array_array_number_t macroDef2262;env_t_2267 env_t_2267_value = make_env_t_2267(scale_shp,scale_dps); closure_t closure2237 = make_closure(lambda2267, &env_t_2267_value);
	env_t_2268 env_t_2268_value = make_env_t_2268(scale_shp); closure_t closure2241 = make_closure(lambda2268, &env_t_2268_value);
	array_array_number_t R1_dps = TOP_LEVEL_linalg_matrixMap_dps(stgVar2163, closure2237, R_dps, closure2241, R_shp);
	matrix_shape_t T_shp = TOP_LEVEL_linalg_matrixConcatCol_shp(R1_shp, TOP_LEVEL_linalg_matrixTranspose_shp(nested_shape_card_t(pose_params_shp.elem, 1)));
	card_t size2279 = width_matrix_shape_t(T_shp);
	array_number_t stgVar2169 = storage_alloc(size2279);
	array_array_number_t macroDef2261;card_t size2270 = width_matrix_shape_t(TOP_LEVEL_linalg_matrixTranspose_shp(nested_shape_card_t(pose_params_shp.elem, 1)));
	array_number_t stgVar2171 = storage_alloc(size2270);
	array_array_number_t macroDef2244;card_t size2269 = width_matrix_shape_t(nested_shape_card_t(pose_params_shp.elem, 1));
	array_number_t stgVar2172 = storage_alloc(size2269);
	array_array_number_t macroDef2243;array_array_number_t macroDef2242 = (array_array_number_t)stgVar2172;
	macroDef2242->length=1;
	macroDef2242->arr=(array_number_t*)(STG_OFFSET(stgVar2172, VECTOR_HEADER_BYTES));
	storage_t stgVar2173 = STG_OFFSET(stgVar2172, MATRIX_HEADER_BYTES(1));

	macroDef2242->arr[0] = pose_params_dps->arr[2];;;
	macroDef2243 = TOP_LEVEL_linalg_matrixTranspose_dps(stgVar2171, macroDef2242, nested_shape_card_t(pose_params_shp.elem, 1));;
	storage_free(stgVar2172, size2269);
	macroDef2244 = TOP_LEVEL_linalg_matrixConcatCol_dps(stgVar2169, R1_dps, macroDef2243, R1_shp, TOP_LEVEL_linalg_matrixTranspose_shp(nested_shape_card_t(pose_params_shp.elem, 1)));;
	storage_free(stgVar2171, size2270);
	array_array_number_t T_dps = macroDef2244;
	env_t_2271 env_t_2271_value = make_empty_env(); closure_t closure2247 = make_closure(lambda2271, &env_t_2271_value);
	card_t ones_shp = TOP_LEVEL_linalg_vectorMap_shp(closure2247, TOP_LEVEL_linalg_vectorRange_shp(1, positions_shp.elem));
	card_t size2278 = width_card_t(ones_shp);
	array_number_t stgVar2175 = storage_alloc(size2278);
	array_array_number_t macroDef2260;card_t size2275 = width_card_t(TOP_LEVEL_linalg_vectorRange_shp(1, positions_shp.elem));
	array_number_t stgVar2177 = storage_alloc(size2275);
	array_number_t macroDef2256;env_t_2272 env_t_2272_value = make_empty_env(); closure_t closure2250 = make_closure(lambda2272, &env_t_2272_value);
	card_t size2273 = width_card_t(positions_shp.elem);
	array_number_t stgVar2181 = storage_alloc(size2273);
	card_t macroDef2252;card_t macroDef2251 = positions_dps->arr[0]->length;
	macroDef2252 = macroDef2251;;
	storage_free(stgVar2181, size2273);
	env_t_2274 env_t_2274_value = make_empty_env(); closure_t closure2255 = make_closure(lambda2274, &env_t_2274_value);
	macroDef2256 = TOP_LEVEL_linalg_vectorMap_dps(stgVar2175, closure2250, TOP_LEVEL_linalg_vectorRange_dps(stgVar2177, 1, macroDef2252, 1, positions_shp.elem), closure2255, TOP_LEVEL_linalg_vectorRange_shp(1, positions_shp.elem));;
	storage_free(stgVar2177, size2275);
	array_number_t ones_dps = macroDef2256;
	matrix_shape_t positions_homog_shp = TOP_LEVEL_linalg_matrixConcat_shp(positions_shp, nested_shape_card_t(ones_shp, 1));
	card_t size2277 = width_matrix_shape_t(positions_homog_shp);
	array_number_t stgVar2183 = storage_alloc(size2277);
	array_array_number_t macroDef2259;card_t size2276 = width_matrix_shape_t(nested_shape_card_t(ones_shp, 1));
	array_number_t stgVar2185 = storage_alloc(size2276);
	array_array_number_t macroDef2258;array_array_number_t macroDef2257 = (array_array_number_t)stgVar2185;
	macroDef2257->length=1;
	macroDef2257->arr=(array_number_t*)(STG_OFFSET(stgVar2185, VECTOR_HEADER_BYTES));
	storage_t stgVar2186 = STG_OFFSET(stgVar2185, MATRIX_HEADER_BYTES(1));

	macroDef2257->arr[0] = ones_dps;;;
	macroDef2258 = TOP_LEVEL_linalg_matrixConcat_dps(stgVar2183, positions_dps, macroDef2257, positions_shp, nested_shape_card_t(ones_shp, 1));;
	storage_free(stgVar2185, size2276);
	array_array_number_t positions_homog_dps = macroDef2258;
	macroDef2259 = TOP_LEVEL_linalg_matrixMult_dps(stgVar2157, T_dps, positions_homog_dps, T_shp, positions_homog_shp);;
	storage_free(stgVar2183, size2277);
	macroDef2260 = macroDef2259;;
	storage_free(stgVar2175, size2278);
	macroDef2261 = macroDef2260;;
	storage_free(stgVar2169, size2279);
	macroDef2262 = macroDef2261;;
	storage_free(stgVar2163, size2280);
	macroDef2263 = macroDef2262;;
	storage_free(stgVar2161, size2281);
	macroDef2264 = macroDef2263;;
	storage_free(stgVar2158, size2282);
	return macroDef2264;
}
typedef struct env_t_2442 {
	matrix_shape_t weights_shp;
	matrix_shape_t pose_params_shp;
	card_t parents_shp;
	card_t n_bones_shp;
	matrix3d_shape_t inverse_base_absolutes_shp;
	matrix3d_shape_t base_relatives_shp;
	matrix_shape_t base_positions_shp;
} env_t_2442;
env_t_2442 make_env_t_2442(matrix_shape_t weights_shp,matrix_shape_t pose_params_shp,card_t parents_shp,card_t n_bones_shp,matrix3d_shape_t inverse_base_absolutes_shp,matrix3d_shape_t base_relatives_shp,matrix_shape_t base_positions_shp) {
	env_t_2442 env;
	env.weights_shp = weights_shp;
	env.pose_params_shp = pose_params_shp;
	env.parents_shp = parents_shp;
	env.n_bones_shp = n_bones_shp;
	env.inverse_base_absolutes_shp = inverse_base_absolutes_shp;
	env.base_relatives_shp = base_relatives_shp;
	env.base_positions_shp = base_positions_shp;
	return env;
}
typedef empty_env_t env_t_2443;


value_t lambda2443(env_t_2443* env2426, matrix_shape_t m1_shp, matrix_shape_t m2_shp) {
	
	value_t res;
	res.matrix_shape_t_value = TOP_LEVEL_linalg_matrixMult_shp(m1_shp, m2_shp);
	return res;
}
value_t lambda2442(env_t_2442* env2436, matrix_shape_t acc_shp, card_t i_transform_shp) {
	matrix_shape_t weights_shp2435 = env2436->weights_shp;
	matrix_shape_t pose_params_shp2434 = env2436->pose_params_shp;
	card_t parents_shp2433 = env2436->parents_shp;
	card_t n_bones_shp2432 = env2436->n_bones_shp;
	matrix3d_shape_t inverse_base_absolutes_shp2431 = env2436->inverse_base_absolutes_shp;
	matrix3d_shape_t base_relatives_shp2430 = env2436->base_relatives_shp;
	matrix_shape_t base_positions_shp2429 = env2436->base_positions_shp;
	env_t_2443 env_t_2443_value = make_empty_env(); closure_t closure2428 = make_closure(lambda2443, &env_t_2443_value);
	value_t res;
	res.matrix_shape_t_value = TOP_LEVEL_linalg_matrixAdd_shp(acc_shp, TOP_LEVEL_linalg_matrixMultElementwise_shp(TOP_LEVEL_linalg_matrixMult_shp(TOP_LEVEL_linalg_matrixSlice_shp(3, 0, TOP_LEVEL_linalg_matrix3DMap2_shp(closure2428, TOP_LEVEL_usecases_ht_relatives_to_absolutes_shp(TOP_LEVEL_usecases_ht_get_posed_relatives_shp(n_bones_shp2432, pose_params_shp2434, base_relatives_shp2430), parents_shp2433), inverse_base_absolutes_shp2431).elem), base_positions_shp2429), TOP_LEVEL_linalg_matrixFillFromVector_shp(base_positions_shp2429.card, weights_shp2435.elem)));
	return res;
}
typedef empty_env_t env_t_2444;


value_t lambda2444(env_t_2444* env2439, matrix_shape_t m1_shp, matrix_shape_t m2_shp) {
	
	value_t res;
	res.matrix_shape_t_value = TOP_LEVEL_linalg_matrixMult_shp(m1_shp, m2_shp);
	return res;
}
matrix_shape_t TOP_LEVEL_usecases_ht_get_skinned_vertex_positions_shp(card_t is_mirrored_shp, card_t n_bones_shp, matrix_shape_t pose_params_shp, matrix3d_shape_t base_relatives_shp, card_t parents_shp, matrix3d_shape_t inverse_base_absolutes_shp, matrix_shape_t base_positions_shp, matrix_shape_t weights_shp) {
	env_t_2442 env_t_2442_value = make_env_t_2442(weights_shp,pose_params_shp,parents_shp,n_bones_shp,inverse_base_absolutes_shp,base_relatives_shp,base_positions_shp); closure_t closure2438 = make_closure(lambda2442, &env_t_2442_value);
	env_t_2444 env_t_2444_value = make_empty_env(); closure_t closure2441 = make_closure(lambda2444, &env_t_2444_value);
	return TOP_LEVEL_usecases_ht_apply_global_transform_shp(pose_params_shp, TOP_LEVEL_linalg_matrixMult_shp(nested_shape_card_t(3, 3), TOP_LEVEL_linalg_iterateMatrix_shp(closure2438, TOP_LEVEL_linalg_matrixFill_shp(3, base_positions_shp.elem, 0), 0, (TOP_LEVEL_linalg_matrix3DMap2_shp(closure2441, TOP_LEVEL_usecases_ht_relatives_to_absolutes_shp(TOP_LEVEL_usecases_ht_get_posed_relatives_shp(n_bones_shp, pose_params_shp, base_relatives_shp), parents_shp), inverse_base_absolutes_shp).card) - (1))));
}

typedef empty_env_t env_t_2496;


value_t lambda2496(env_t_2496* env2445, matrix_shape_t m1_shp, matrix_shape_t m2_shp) {
	
	value_t res;
	res.matrix_shape_t_value = TOP_LEVEL_linalg_matrixMult_shp(m1_shp, m2_shp);
	return res;
}
typedef empty_env_t env_t_2497;


value_t lambda2497(env_t_2497* env2448, storage_t stgVar2295, array_array_number_t m1_dps, array_array_number_t m2_dps, matrix_shape_t m1_shp, matrix_shape_t m2_shp) {
	
	value_t res;
	res.array_array_number_t_value = TOP_LEVEL_linalg_matrixMult_dps(stgVar2295, m1_dps, m2_dps, m1_shp, m2_shp);
	return res;
}
typedef empty_env_t env_t_2498;


value_t lambda2498(env_t_2498* env2451, matrix_shape_t m1_shp, matrix_shape_t m2_shp) {
	
	value_t res;
	res.matrix_shape_t_value = TOP_LEVEL_linalg_matrixMult_shp(m1_shp, m2_shp);
	return res;
}
typedef struct env_t_2500 {
	matrix_shape_t weights_shp;
	matrix3d_shape_t transforms_shp;
	matrix_shape_t base_positions_shp;
} env_t_2500;
env_t_2500 make_env_t_2500(matrix_shape_t weights_shp,matrix3d_shape_t transforms_shp,matrix_shape_t base_positions_shp) {
	env_t_2500 env;
	env.weights_shp = weights_shp;
	env.transforms_shp = transforms_shp;
	env.base_positions_shp = base_positions_shp;
	return env;
}

value_t lambda2500(env_t_2500* env2459, matrix_shape_t acc_shp, card_t i_transform_shp) {
	matrix_shape_t weights_shp2458 = env2459->weights_shp;
	matrix3d_shape_t transforms_shp2457 = env2459->transforms_shp;
	matrix_shape_t base_positions_shp2456 = env2459->base_positions_shp;
	matrix_shape_t curr_positions_shp = TOP_LEVEL_linalg_matrixMult_shp(TOP_LEVEL_linalg_matrixSlice_shp(3, 0, transforms_shp2457.elem), base_positions_shp2456);
	matrix_shape_t w_shp = TOP_LEVEL_linalg_matrixFillFromVector_shp(base_positions_shp2456.card, weights_shp2458.elem);
	value_t res;
	res.matrix_shape_t_value = TOP_LEVEL_linalg_matrixAdd_shp(acc_shp, TOP_LEVEL_linalg_matrixMultElementwise_shp(curr_positions_shp, w_shp));
	return res;
}
typedef struct env_t_2501 {
	matrix_shape_t weights_shp;
	array_array_number_t weights_dps;
	matrix3d_shape_t transforms_shp;
	array_array_array_number_t transforms_dps;
	matrix_shape_t base_positions_shp;
	array_array_number_t base_positions_dps;
} env_t_2501;
env_t_2501 make_env_t_2501(matrix_shape_t weights_shp,array_array_number_t weights_dps,matrix3d_shape_t transforms_shp,array_array_array_number_t transforms_dps,matrix_shape_t base_positions_shp,array_array_number_t base_positions_dps) {
	env_t_2501 env;
	env.weights_shp = weights_shp;
	env.weights_dps = weights_dps;
	env.transforms_shp = transforms_shp;
	env.transforms_dps = transforms_dps;
	env.base_positions_shp = base_positions_shp;
	env.base_positions_dps = base_positions_dps;
	return env;
}

value_t lambda2501(env_t_2501* env2475, storage_t stgVar2310, array_array_number_t acc_dps, index_t i_transform_dps, matrix_shape_t acc_shp, card_t i_transform_shp) {
	matrix_shape_t weights_shp2474 = env2475->weights_shp;
	array_array_number_t weights_dps2473 = env2475->weights_dps;
	matrix3d_shape_t transforms_shp2472 = env2475->transforms_shp;
	array_array_array_number_t transforms_dps2471 = env2475->transforms_dps;
	matrix_shape_t base_positions_shp2470 = env2475->base_positions_shp;
	array_array_number_t base_positions_dps2469 = env2475->base_positions_dps;
	matrix_shape_t curr_positions_shp = TOP_LEVEL_linalg_matrixMult_shp(TOP_LEVEL_linalg_matrixSlice_shp(3, 0, transforms_shp2472.elem), base_positions_shp2470);
	card_t size2507 = width_matrix_shape_t(curr_positions_shp);
	array_number_t stgVar2311 = storage_alloc(size2507);
	array_array_number_t macroDef2468;card_t size2503 = width_matrix_shape_t(TOP_LEVEL_linalg_matrixSlice_shp(3, 0, transforms_shp2472.elem));
	array_number_t stgVar2312 = storage_alloc(size2503);
	array_array_number_t macroDef2463;card_t size2502 = width_matrix_shape_t(transforms_shp2472.elem);
	array_number_t stgVar2316 = storage_alloc(size2502);
	array_array_number_t macroDef2462;
	macroDef2462 = TOP_LEVEL_linalg_matrixSlice_dps(stgVar2312, 3, 0, transforms_dps2471->arr[i_transform_dps], 3, 0, transforms_shp2472.elem);;
	storage_free(stgVar2316, size2502);
	macroDef2463 = TOP_LEVEL_linalg_matrixMult_dps(stgVar2311, macroDef2462, base_positions_dps2469, TOP_LEVEL_linalg_matrixSlice_shp(3, 0, transforms_shp2472.elem), base_positions_shp2470);;
	storage_free(stgVar2312, size2503);
	array_array_number_t curr_positions_dps = macroDef2463;
	matrix_shape_t w_shp = TOP_LEVEL_linalg_matrixFillFromVector_shp(base_positions_shp2470.card, weights_shp2474.elem);
	card_t size2506 = width_matrix_shape_t(w_shp);
	array_number_t stgVar2318 = storage_alloc(size2506);
	array_array_number_t macroDef2467;card_t size2504 = width_card_t(weights_shp2474.elem);
	array_number_t stgVar2320 = storage_alloc(size2504);
	array_array_number_t macroDef2465;card_t macroDef2464 = base_positions_dps2469->length;
	macroDef2465 = TOP_LEVEL_linalg_matrixFillFromVector_dps(stgVar2318, macroDef2464, weights_dps2473->arr[i_transform_dps], base_positions_shp2470.card, weights_shp2474.elem);;
	storage_free(stgVar2320, size2504);
	array_array_number_t w_dps = macroDef2465;
	card_t size2505 = width_matrix_shape_t(TOP_LEVEL_linalg_matrixMultElementwise_shp(curr_positions_shp, w_shp));
	array_number_t stgVar2324 = storage_alloc(size2505);
	array_array_number_t macroDef2466;
	macroDef2466 = TOP_LEVEL_linalg_matrixAdd_dps(stgVar2310, acc_dps, TOP_LEVEL_linalg_matrixMultElementwise_dps(stgVar2324, curr_positions_dps, w_dps, curr_positions_shp, w_shp), acc_shp, TOP_LEVEL_linalg_matrixMultElementwise_shp(curr_positions_shp, w_shp));;
	storage_free(stgVar2324, size2505);
	macroDef2467 = macroDef2466;;
	storage_free(stgVar2318, size2506);
	macroDef2468 = macroDef2467;;
	storage_free(stgVar2311, size2507);
	value_t res;
	res.array_array_number_t_value = macroDef2468;
	return res;
}
typedef struct env_t_2508 {
	matrix_shape_t weights_shp;
	matrix3d_shape_t transforms_shp;
	matrix_shape_t base_positions_shp;
} env_t_2508;
env_t_2508 make_env_t_2508(matrix_shape_t weights_shp,matrix3d_shape_t transforms_shp,matrix_shape_t base_positions_shp) {
	env_t_2508 env;
	env.weights_shp = weights_shp;
	env.transforms_shp = transforms_shp;
	env.base_positions_shp = base_positions_shp;
	return env;
}

value_t lambda2508(env_t_2508* env2482, matrix_shape_t acc_shp, card_t i_transform_shp) {
	matrix_shape_t weights_shp2481 = env2482->weights_shp;
	matrix3d_shape_t transforms_shp2480 = env2482->transforms_shp;
	matrix_shape_t base_positions_shp2479 = env2482->base_positions_shp;
	matrix_shape_t curr_positions_shp = TOP_LEVEL_linalg_matrixMult_shp(TOP_LEVEL_linalg_matrixSlice_shp(3, 0, transforms_shp2480.elem), base_positions_shp2479);
	matrix_shape_t w_shp = TOP_LEVEL_linalg_matrixFillFromVector_shp(base_positions_shp2479.card, weights_shp2481.elem);
	value_t res;
	res.matrix_shape_t_value = TOP_LEVEL_linalg_matrixAdd_shp(acc_shp, TOP_LEVEL_linalg_matrixMultElementwise_shp(curr_positions_shp, w_shp));
	return res;
}
array_array_number_t TOP_LEVEL_usecases_ht_get_skinned_vertex_positions_dps(storage_t stgVar2283, index_t is_mirrored_dps, card_t n_bones_dps, array_array_number_t pose_params_dps, array_array_array_number_t base_relatives_dps, array_number_t parents_dps, array_array_array_number_t inverse_base_absolutes_dps, array_array_number_t base_positions_dps, array_array_number_t weights_dps, card_t is_mirrored_shp, card_t n_bones_shp, matrix_shape_t pose_params_shp, matrix3d_shape_t base_relatives_shp, card_t parents_shp, matrix3d_shape_t inverse_base_absolutes_shp, matrix_shape_t base_positions_shp, matrix_shape_t weights_shp) {
	matrix3d_shape_t relatives_shp = TOP_LEVEL_usecases_ht_get_posed_relatives_shp(n_bones_shp, pose_params_shp, base_relatives_shp);
	card_t size2515 = width_matrix3d_shape_t(relatives_shp);
	array_number_t stgVar2284 = storage_alloc(size2515);
	array_array_number_t macroDef2495;array_array_array_number_t relatives_dps = TOP_LEVEL_usecases_ht_get_posed_relatives_dps(stgVar2284, n_bones_dps, pose_params_dps, base_relatives_dps, n_bones_shp, pose_params_shp, base_relatives_shp);
	matrix3d_shape_t absolutes_shp = TOP_LEVEL_usecases_ht_relatives_to_absolutes_shp(relatives_shp, parents_shp);
	card_t size2514 = width_matrix3d_shape_t(absolutes_shp);
	array_number_t stgVar2288 = storage_alloc(size2514);
	array_array_number_t macroDef2494;array_array_array_number_t absolutes_dps = TOP_LEVEL_usecases_ht_relatives_to_absolutes_dps(stgVar2288, relatives_dps, parents_dps, relatives_shp, parents_shp);
	env_t_2496 env_t_2496_value = make_empty_env(); closure_t closure2447 = make_closure(lambda2496, &env_t_2496_value);
	matrix3d_shape_t transforms_shp = TOP_LEVEL_linalg_matrix3DMap2_shp(closure2447, absolutes_shp, inverse_base_absolutes_shp);
	card_t size2513 = width_matrix3d_shape_t(transforms_shp);
	array_number_t stgVar2291 = storage_alloc(size2513);
	array_array_number_t macroDef2493;env_t_2497 env_t_2497_value = make_empty_env(); closure_t closure2450 = make_closure(lambda2497, &env_t_2497_value);
	env_t_2498 env_t_2498_value = make_empty_env(); closure_t closure2453 = make_closure(lambda2498, &env_t_2498_value);
	array_array_array_number_t transforms_dps = TOP_LEVEL_linalg_matrix3DMap2_dps(stgVar2291, closure2450, absolutes_dps, inverse_base_absolutes_dps, closure2453, absolutes_shp, inverse_base_absolutes_shp);
	card_t n_verts_shp = base_positions_shp.elem;
	card_t size2499 = width_card_t(base_positions_shp.elem);
	array_number_t stgVar2299 = storage_alloc(size2499);
	card_t macroDef2455;card_t macroDef2454 = base_positions_dps->arr[0]->length;
	macroDef2455 = macroDef2454;;
	storage_free(stgVar2299, size2499);
	card_t n_verts_dps = macroDef2455;
	matrix_shape_t init_positions_shp = TOP_LEVEL_linalg_matrixFill_shp(3, n_verts_shp, 0);
	card_t size2512 = width_matrix_shape_t(init_positions_shp);
	array_number_t stgVar2301 = storage_alloc(size2512);
	array_array_number_t macroDef2492;array_array_number_t init_positions_dps = TOP_LEVEL_linalg_matrixFill_dps(stgVar2301, 3, n_verts_dps, 0, 3, n_verts_shp, 0);
	env_t_2500 env_t_2500_value = make_env_t_2500(weights_shp,transforms_shp,base_positions_shp); closure_t closure2461 = make_closure(lambda2500, &env_t_2500_value);
	matrix_shape_t positions_shp = TOP_LEVEL_linalg_iterateMatrix_shp(closure2461, init_positions_shp, 0, (transforms_shp.card) - (1));
	card_t size2511 = width_matrix_shape_t(positions_shp);
	array_number_t stgVar2305 = storage_alloc(size2511);
	array_array_number_t macroDef2491;env_t_2501 env_t_2501_value = make_env_t_2501(weights_shp,weights_dps,transforms_shp,transforms_dps,base_positions_shp,base_positions_dps); closure_t closure2477 = make_closure(lambda2501, &env_t_2501_value);
	card_t macroDef2478 = transforms_dps->length;
	env_t_2508 env_t_2508_value = make_env_t_2508(weights_shp,transforms_shp,base_positions_shp); closure_t closure2484 = make_closure(lambda2508, &env_t_2508_value);
	array_array_number_t positions_dps = TOP_LEVEL_linalg_iterateMatrix_dps(stgVar2305, closure2477, init_positions_dps, 0, (macroDef2478) - (1), closure2484, init_positions_shp, 0, (transforms_shp.card) - (1));
	matrix_shape_t mirror_matrix_shp = nested_shape_card_t(3, 3);
	matrix_shape_t mirrored_positions_shp = TOP_LEVEL_linalg_matrixMult_shp(mirror_matrix_shp, positions_shp);
	card_t size2510 = width_matrix_shape_t(mirrored_positions_shp);
	array_number_t stgVar2328 = storage_alloc(size2510);
	array_array_number_t macroDef2490;array_array_number_t mirrored_positions_dps = 0;
	if((is_mirrored_dps) == (1)) {
		matrix_shape_t mirror_matrix_shp0 = nested_shape_card_t(3, 3);
		card_t size2509 = width_matrix_shape_t(mirror_matrix_shp0);
	array_number_t stgVar2329 = storage_alloc(size2509);
	array_array_number_t macroDef2489;array_array_number_t macroDef2488 = (array_array_number_t)stgVar2329;
	macroDef2488->length=3;
	macroDef2488->arr=(array_number_t*)(STG_OFFSET(stgVar2329, VECTOR_HEADER_BYTES));
	storage_t stgVar2330 = STG_OFFSET(stgVar2329, MATRIX_HEADER_BYTES(3));array_number_t macroDef2485 = (array_number_t)stgVar2330;
	macroDef2485->length=3;
	macroDef2485->arr=(number_t*)(STG_OFFSET(stgVar2330, VECTOR_HEADER_BYTES));
	macroDef2485->arr[0] = -1;
	macroDef2485->arr[1] = 0;
	macroDef2485->arr[2] = 0;;

	macroDef2488->arr[0] = macroDef2485;;storage_t stgVar2334 = STG_OFFSET(stgVar2329, MATRIX_HEADER_BYTES(3));array_number_t macroDef2486 = (array_number_t)stgVar2334;
	macroDef2486->length=3;
	macroDef2486->arr=(number_t*)(STG_OFFSET(stgVar2334, VECTOR_HEADER_BYTES));
	macroDef2486->arr[0] = 0;
	macroDef2486->arr[1] = 1;
	macroDef2486->arr[2] = 0;;

	macroDef2488->arr[1] = macroDef2486;;storage_t stgVar2338 = STG_OFFSET(stgVar2329, MATRIX_HEADER_BYTES(3));array_number_t macroDef2487 = (array_number_t)stgVar2338;
	macroDef2487->length=3;
	macroDef2487->arr=(number_t*)(STG_OFFSET(stgVar2338, VECTOR_HEADER_BYTES));
	macroDef2487->arr[0] = 0;
	macroDef2487->arr[1] = 0;
	macroDef2487->arr[2] = 1;;

	macroDef2488->arr[2] = macroDef2487;;;
	array_array_number_t mirror_matrix_dps = macroDef2488;
	macroDef2489 = TOP_LEVEL_linalg_matrixMult_dps(stgVar2328, mirror_matrix_dps, positions_dps, mirror_matrix_shp0, positions_shp);;
	storage_free(stgVar2329, size2509);
		mirrored_positions_dps = macroDef2489;;
	} else {
		
		mirrored_positions_dps = positions_dps;;
	}
	macroDef2490 = TOP_LEVEL_usecases_ht_apply_global_transform_dps(stgVar2283, pose_params_dps, mirrored_positions_dps, pose_params_shp, mirrored_positions_shp);;
	storage_free(stgVar2328, size2510);
	macroDef2491 = macroDef2490;;
	storage_free(stgVar2305, size2511);
	macroDef2492 = macroDef2491;;
	storage_free(stgVar2301, size2512);
	macroDef2493 = macroDef2492;;
	storage_free(stgVar2291, size2513);
	macroDef2494 = macroDef2493;;
	storage_free(stgVar2288, size2514);
	macroDef2495 = macroDef2494;;
	storage_free(stgVar2284, size2515);
	return macroDef2495;
}
typedef empty_env_t env_t_2569;


value_t lambda2569(env_t_2569* env2566, card_t i_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
card_t TOP_LEVEL_usecases_ht_hand_objective_shp(card_t is_mirrored_shp, card_t param_shp, card_t correspondences_shp, matrix_shape_t points_shp, card_t n_bones_shp, matrix3d_shape_t base_relatives_shp, card_t parents_shp, matrix3d_shape_t inverse_base_absolutes_shp, matrix_shape_t base_positions_shp, matrix_shape_t weights_shp) {
	env_t_2569 env_t_2569_value = make_empty_env(); closure_t closure2568 = make_closure(lambda2569, &env_t_2569_value);
	return TOP_LEVEL_linalg_vectorMap_shp(closure2568, TOP_LEVEL_linalg_vectorRange_shp(0, (((correspondences_shp) + (correspondences_shp)) + (correspondences_shp)) - (1)));
}

typedef empty_env_t env_t_2592;


value_t lambda2592(env_t_2592* env2571, card_t i_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef struct env_t_2593 {
	matrix_shape_t vertex_positions_shp;
	array_array_number_t vertex_positions_dps;
	matrix_shape_t points_shp;
	array_array_number_t points_dps;
	index_t n_corr_dps;
	array_number_t correspondences_dps;
} env_t_2593;
env_t_2593 make_env_t_2593(matrix_shape_t vertex_positions_shp,array_array_number_t vertex_positions_dps,matrix_shape_t points_shp,array_array_number_t points_dps,index_t n_corr_dps,array_number_t correspondences_dps) {
	env_t_2593 env;
	env.vertex_positions_shp = vertex_positions_shp;
	env.vertex_positions_dps = vertex_positions_dps;
	env.points_shp = points_shp;
	env.points_dps = points_dps;
	env.n_corr_dps = n_corr_dps;
	env.correspondences_dps = correspondences_dps;
	return env;
}

value_t lambda2593(env_t_2593* env2582, storage_t stgVar2535, number_t i_dps, card_t i_shp) {
	matrix_shape_t vertex_positions_shp2581 = env2582->vertex_positions_shp;
	array_array_number_t vertex_positions_dps2580 = env2582->vertex_positions_dps;
	matrix_shape_t points_shp2579 = env2582->points_shp;
	array_array_number_t points_dps2578 = env2582->points_dps;
	index_t n_corr_dps2577 = env2582->n_corr_dps;
	array_number_t correspondences_dps2576 = env2582->correspondences_dps;
	card_t ind_shp = 0;
	index_t ind_dps = (int)(i_dps);
	card_t r_shp = 0;
	index_t r_dps = (ind_dps) / (n_corr_dps2577);
	card_t c_shp = 0;
	index_t c_dps = (ind_dps) % (n_corr_dps2577);
	card_t size2594 = width_card_t(points_shp2579.elem);
	array_number_t stgVar2539 = storage_alloc(size2594);
	number_t macroDef2574;
	macroDef2574 = points_dps2578->arr[r_dps]->arr[c_dps];;
	storage_free(stgVar2539, size2594);
	card_t size2595 = width_card_t(vertex_positions_shp2581.elem);
	array_number_t stgVar2541 = storage_alloc(size2595);
	number_t macroDef2575;
	macroDef2575 = vertex_positions_dps2580->arr[r_dps]->arr[(int)(correspondences_dps2576->arr[c_dps])];;
	storage_free(stgVar2541, size2595);
	value_t res;
	res.number_t_value = (macroDef2574) - (macroDef2575);
	return res;
}
typedef empty_env_t env_t_2596;


value_t lambda2596(env_t_2596* env2585, card_t i_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
array_number_t TOP_LEVEL_usecases_ht_hand_objective_dps(storage_t stgVar2516, index_t is_mirrored_dps, array_number_t param_dps, array_number_t correspondences_dps, array_array_number_t points_dps, card_t n_bones_dps, array_array_array_number_t base_relatives_dps, array_number_t parents_dps, array_array_array_number_t inverse_base_absolutes_dps, array_array_number_t base_positions_dps, array_array_number_t weights_dps, card_t is_mirrored_shp, card_t param_shp, card_t correspondences_shp, matrix_shape_t points_shp, card_t n_bones_shp, matrix3d_shape_t base_relatives_shp, card_t parents_shp, matrix3d_shape_t inverse_base_absolutes_shp, matrix_shape_t base_positions_shp, matrix_shape_t weights_shp) {
	matrix_shape_t pose_params_shp = TOP_LEVEL_usecases_ht_to_pose_params_shp(param_shp, n_bones_shp);
	card_t size2600 = width_matrix_shape_t(pose_params_shp);
	array_number_t stgVar2517 = storage_alloc(size2600);
	array_number_t macroDef2591;array_array_number_t pose_params_dps = TOP_LEVEL_usecases_ht_to_pose_params_dps(stgVar2517, param_dps, n_bones_dps, param_shp, n_bones_shp);
	matrix_shape_t vertex_positions_shp = TOP_LEVEL_usecases_ht_get_skinned_vertex_positions_shp(0, n_bones_shp, pose_params_shp, base_relatives_shp, parents_shp, inverse_base_absolutes_shp, base_positions_shp, weights_shp);
	card_t size2599 = width_matrix_shape_t(vertex_positions_shp);
	array_number_t stgVar2520 = storage_alloc(size2599);
	array_number_t macroDef2590;array_array_number_t vertex_positions_dps = TOP_LEVEL_usecases_ht_get_skinned_vertex_positions_dps(stgVar2520, is_mirrored_dps, n_bones_dps, pose_params_dps, base_relatives_dps, parents_dps, inverse_base_absolutes_dps, base_positions_dps, weights_dps, 0, n_bones_shp, pose_params_shp, base_relatives_shp, parents_shp, inverse_base_absolutes_shp, base_positions_shp, weights_shp);
	card_t n_corr_card_shp = correspondences_shp;
	card_t macroDef2570 = correspondences_dps->length;
	card_t n_corr_card_dps = macroDef2570;
	card_t n_corr_shp = 0;
	index_t n_corr_dps = (n_corr_card_dps);
	env_t_2592 env_t_2592_value = make_empty_env(); closure_t closure2573 = make_closure(lambda2592, &env_t_2592_value);
	card_t err_shp = TOP_LEVEL_linalg_vectorMap_shp(closure2573, TOP_LEVEL_linalg_vectorRange_shp(0, (((n_corr_card_shp) + (n_corr_card_shp)) + (n_corr_card_shp)) - (1)));
	card_t size2598 = width_card_t(err_shp);
	array_number_t stgVar2532 = storage_alloc(size2598);
	array_number_t macroDef2589;card_t size2597 = width_card_t(TOP_LEVEL_linalg_vectorRange_shp(0, (((n_corr_card_shp) + (n_corr_card_shp)) + (n_corr_card_shp)) - (1)));
	array_number_t stgVar2534 = storage_alloc(size2597);
	array_number_t macroDef2588;env_t_2593 env_t_2593_value = make_env_t_2593(vertex_positions_shp,vertex_positions_dps,points_shp,points_dps,n_corr_dps,correspondences_dps); closure_t closure2584 = make_closure(lambda2593, &env_t_2593_value);
	env_t_2596 env_t_2596_value = make_empty_env(); closure_t closure2587 = make_closure(lambda2596, &env_t_2596_value);
	macroDef2588 = TOP_LEVEL_linalg_vectorMap_dps(stgVar2532, closure2584, TOP_LEVEL_linalg_vectorRange_dps(stgVar2534, 0, (((n_corr_card_dps) + (n_corr_card_dps)) + (n_corr_card_dps)) - (1), 0, (((n_corr_card_shp) + (n_corr_card_shp)) + (n_corr_card_shp)) - (1)), closure2587, TOP_LEVEL_linalg_vectorRange_shp(0, (((n_corr_card_shp) + (n_corr_card_shp)) + (n_corr_card_shp)) - (1)));;
	storage_free(stgVar2534, size2597);
	array_number_t err_dps = macroDef2588;
	macroDef2589 = err_dps;;
	storage_free(stgVar2532, size2598);
	macroDef2590 = macroDef2589;;
	storage_free(stgVar2520, size2599);
	macroDef2591 = macroDef2590;;
	storage_free(stgVar2517, size2600);
	return macroDef2591;
}

card_t TOP_LEVEL_usecases_ht_test_ht_shp(card_t unitVar0_shp) {
	
	return 0;
}

typedef empty_env_t env_t_2650;


value_t lambda2650(env_t_2650* env2635, card_t i_shp) {
	
	value_t res;
	res.card_t_value = 4;
	return res;
}
void TOP_LEVEL_usecases_ht_test_ht_dps(storage_t stgVar2601, int unitVar0_dps, card_t unitVar0_shp) {
	card_t a_shp = 3;
	card_t size2656 = width_card_t(a_shp);
	array_number_t stgVar2602 = storage_alloc(size2656);
	array_number_t macroDef2630 = (array_number_t)stgVar2602;
	macroDef2630->length=3;
	macroDef2630->arr=(number_t*)(STG_OFFSET(stgVar2602, VECTOR_HEADER_BYTES));
	macroDef2630->arr[0] = 1;
	macroDef2630->arr[1] = 2;
	macroDef2630->arr[2] = 3;;
	array_number_t a_dps = macroDef2630;
	array_print(a_dps);
	matrix_shape_t mat1_shp = nested_shape_card_t(3, 3);
	card_t size2655 = width_matrix_shape_t(mat1_shp);
	array_number_t stgVar2606 = storage_alloc(size2655);
	array_array_number_t macroDef2634 = (array_array_number_t)stgVar2606;
	macroDef2634->length=3;
	macroDef2634->arr=(array_number_t*)(STG_OFFSET(stgVar2606, VECTOR_HEADER_BYTES));
	storage_t stgVar2607 = STG_OFFSET(stgVar2606, MATRIX_HEADER_BYTES(3));array_number_t macroDef2631 = (array_number_t)stgVar2607;
	macroDef2631->length=3;
	macroDef2631->arr=(number_t*)(STG_OFFSET(stgVar2607, VECTOR_HEADER_BYTES));
	macroDef2631->arr[0] = 1;
	macroDef2631->arr[1] = 2;
	macroDef2631->arr[2] = 3;;

	macroDef2634->arr[0] = macroDef2631;;storage_t stgVar2611 = STG_OFFSET(stgVar2606, MATRIX_HEADER_BYTES(3));array_number_t macroDef2632 = (array_number_t)stgVar2611;
	macroDef2632->length=3;
	macroDef2632->arr=(number_t*)(STG_OFFSET(stgVar2611, VECTOR_HEADER_BYTES));
	macroDef2632->arr[0] = 4;
	macroDef2632->arr[1] = 5;
	macroDef2632->arr[2] = 6;;

	macroDef2634->arr[1] = macroDef2632;;storage_t stgVar2615 = STG_OFFSET(stgVar2606, MATRIX_HEADER_BYTES(3));array_number_t macroDef2633 = (array_number_t)stgVar2615;
	macroDef2633->length=3;
	macroDef2633->arr=(number_t*)(STG_OFFSET(stgVar2615, VECTOR_HEADER_BYTES));
	macroDef2633->arr[0] = 7;
	macroDef2633->arr[1] = 8;
	macroDef2633->arr[2] = 9;;

	macroDef2634->arr[2] = macroDef2633;;;
	array_array_number_t mat1_dps = macroDef2634;
	env_t_2650 env_t_2650_value = make_empty_env(); closure_t closure2637 = make_closure(lambda2650, &env_t_2650_value);
	matrix_shape_t base_rel_shp = nested_shape_card_t(closure2637.lam(closure2637.env, 0).card_t_value, 4);
	card_t size2654 = width_matrix_shape_t(base_rel_shp);
	array_number_t stgVar2619 = storage_alloc(size2654);
	array_array_number_t macroDef2639 = (array_array_number_t)stgVar2619;
		macroDef2639->length=4;
		macroDef2639->arr=(array_number_t*)(STG_OFFSET(macroDef2639, VECTOR_HEADER_BYTES));
		storage_t stgVar2620 = (STG_OFFSET(macroDef2639, MATRIX_HEADER_BYTES(4)));
		for(int i_dps = 0; i_dps < macroDef2639->length; i_dps++){
			array_number_t macroDef2638 = (array_number_t)stgVar2620;
		macroDef2638->length=4;
		macroDef2638->arr=(number_t*)(STG_OFFSET(macroDef2638, VECTOR_HEADER_BYTES));
		storage_t stgVar2621 = macroDef2638;
		for(int j_dps = 0; j_dps < macroDef2638->length; j_dps++){
			
			macroDef2638->arr[j_dps] = (double)((((i_dps) + (1)) * (4)) + (j_dps));;
			stgVar2621 = STG_OFFSET(stgVar2621, sizeof(number_t));
		}
			macroDef2639->arr[i_dps] = macroDef2638;;
			stgVar2620 = STG_OFFSET(stgVar2620, VECTOR_ALL_BYTES(macroDef2639->arr[i_dps]->length));
		}
	array_array_number_t base_rel_dps = macroDef2639;
	matrix_shape_t q_shp = TOP_LEVEL_usecases_ht_make_relative_shp(a_shp, base_rel_shp);
	card_t size2653 = width_matrix_shape_t(q_shp);
	array_number_t stgVar2622 = storage_alloc(size2653);
	array_array_number_t q_dps = TOP_LEVEL_usecases_ht_make_relative_dps(stgVar2622, a_dps, base_rel_dps, a_shp, base_rel_shp);
	matrix_print(q_dps);
	matrix_shape_t r_shp = TOP_LEVEL_usecases_ht_angle_axis_to_rotation_matrix_shp(a_shp);
	card_t size2652 = width_matrix_shape_t(r_shp);
	array_number_t stgVar2625 = storage_alloc(size2652);
	array_array_number_t r_dps = TOP_LEVEL_usecases_ht_angle_axis_to_rotation_matrix_dps(stgVar2625, a_dps, a_shp);
	matrix_print(r_dps);
	matrix_shape_t s_shp = TOP_LEVEL_usecases_ht_apply_global_transform_shp(mat1_shp, mat1_shp);
	card_t size2651 = width_matrix_shape_t(s_shp);
	array_number_t stgVar2627 = storage_alloc(size2651);
	array_array_number_t s_dps = TOP_LEVEL_usecases_ht_apply_global_transform_dps(stgVar2627, mat1_dps, mat1_dps, mat1_shp, mat1_shp);
	matrix_print(s_dps);
	;
	storage_free(stgVar2627, size2651);
	;
	storage_free(stgVar2625, size2652);
	;
	storage_free(stgVar2622, size2653);
	;
	storage_free(stgVar2619, size2654);
	;
	storage_free(stgVar2606, size2655);
	;
	storage_free(stgVar2602, size2656);
	return ;
}
#endif
