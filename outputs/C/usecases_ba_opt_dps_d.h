#ifndef __USECASES_BA_H__ 
#define __USECASES_BA_H__ 
#include "../../Runtime/C/fsharp.h"
#include <stdio.h>
#include <math.h>

number_t TOP_LEVEL_linalg_sqnorm_dps(storage_t stgVar311, array_number_t x_dps, card_t x_shp) {
	number_t macroDef141 = 0;
	array_number_t cur_dps_range = x_dps;
	for(int cur_dps_idx = 0; cur_dps_idx < cur_dps_range->length; cur_dps_idx++){
		number_t cur_dps = cur_dps_range->arr[cur_dps_idx];
		
		macroDef141 = (macroDef141) + (cur_dps*cur_dps);;
	}
	return macroDef141;
}

array_number_t TOP_LEVEL_usecases_ba_project_dps_d(storage_t stgVar2364, array_number_t cam_dps, array_number_t x_dps, array_number_t cam_d_dps, array_number_t x_d_dps, card_t cam_shp, card_t x_shp, card_t cam_d_shp, card_t x_d_shp) {
	card_t _x1513_shp = 3;
	card_t _x1513_dps = 3;
	card_t _x1515_shp = 0;
	card_t _x1515_dps = 0;
	tuple_card_t_card_t _x1539_shp = pair_c_c(0, 0);
	tuple_number_t_number_t _x1539_dps = pair(0, 0);
	card_t size2951 = width_tuple_card_t_card_t(_x1539_shp);
	array_number_t stgVar2368 = storage_alloc(size2951);
	array_number_t macroDef2938;tuple_number_t_number_t macroDef2908 = _x1539_dps;
	storage_t stgVar2369 = stgVar2368;
	for(int idx_dps = _x1515_dps; idx_dps < _x1513_dps; idx_dps++){
		number_t _x1519_dps = macroDef2908._1;
		number_t _x1521_dps = macroDef2908._2;
		number_t _x1524_dps = cam_dps->arr[idx_dps];
		number_t _x1526_dps = (_x1524_dps) * (_x1524_dps);
		number_t _x1528_dps = (_x1519_dps) + (_x1526_dps);
		number_t _x1532_dps = cam_d_dps->arr[idx_dps];
		number_t _x1535_dps = (_x1532_dps) * (_x1524_dps);
		number_t _x1536_dps = (_x1524_dps) * (_x1532_dps);
		number_t _x1534_dps = (_x1535_dps) + (_x1536_dps);
		number_t _x1538_dps = (_x1521_dps) + (_x1534_dps);
		tuple_number_t_number_t _x1522_dps = pair(_x1528_dps, _x1538_dps);
		macroDef2908 = _x1522_dps;;
	}
	tuple_number_t_number_t _x1517_dps = macroDef2908;
	number_t _x1541_dps = _x1517_dps._1;
	number_t _x1543_dps = _x1517_dps._2;
	bool_t _x1545_dps = (_x1541_dps) != (0);
	array_number_t _x1547_dps = 0;
	if(_x1545_dps) {
		number_t _x1549_dps = sqrt(_x1541_dps);
		number_t _x1551_dps = cos(_x1549_dps);
		number_t _x1553_dps = sin(_x1549_dps);
		number_t _x1555_dps = (1) / (_x1549_dps);
		number_t _x1557_dps = cam_dps->arr[1];
		number_t _x1559_dps = (_x1557_dps) * (_x1555_dps);
		number_t _x1561_dps = x_dps->arr[2];
		number_t _x1563_dps = cam_dps->arr[5];
		number_t _x1565_dps = (_x1561_dps) - (_x1563_dps);
		number_t _x1567_dps = (_x1559_dps) * (_x1565_dps);
		number_t _x1569_dps = cam_dps->arr[2];
		number_t _x1571_dps = (_x1569_dps) * (_x1555_dps);
		number_t _x1573_dps = x_dps->arr[1];
		number_t _x1575_dps = cam_dps->arr[4];
		number_t _x1577_dps = (_x1573_dps) - (_x1575_dps);
		number_t _x1579_dps = (_x1571_dps) * (_x1577_dps);
		number_t _x1581_dps = (_x1567_dps) - (_x1579_dps);
		number_t _x1587_dps = x_dps->arr[0];
		number_t _x1589_dps = cam_dps->arr[3];
		number_t _x1591_dps = (_x1587_dps) - (_x1589_dps);
		number_t _x1593_dps = (_x1571_dps) * (_x1591_dps);
		number_t _x1595_dps = cam_dps->arr[0];
		number_t _x1597_dps = (_x1595_dps) * (_x1555_dps);
		number_t _x1599_dps = x_dps->arr[2];
		number_t _x1603_dps = (_x1599_dps) - (_x1563_dps);
		number_t _x1605_dps = (_x1597_dps) * (_x1603_dps);
		number_t _x1607_dps = (_x1593_dps) - (_x1605_dps);
		number_t _x1613_dps = x_dps->arr[1];
		number_t _x1617_dps = (_x1613_dps) - (_x1575_dps);
		number_t _x1619_dps = (_x1597_dps) * (_x1617_dps);
		number_t _x1625_dps = x_dps->arr[0];
		number_t _x1629_dps = (_x1625_dps) - (_x1589_dps);
		number_t _x1631_dps = (_x1559_dps) * (_x1629_dps);
		number_t _x1633_dps = (_x1619_dps) - (_x1631_dps);
		card_t size2940 = width_card_t(3);
	array_number_t stgVar2433 = storage_alloc(size2940);
	array_number_t macroDef2914;array_number_t macroDef2909 = (array_number_t)stgVar2433;
	macroDef2909->length=3;
	macroDef2909->arr=(number_t*)(STG_OFFSET(stgVar2433, VECTOR_HEADER_BYTES));
	

	macroDef2909->arr[0] = _x1581_dps;;

	macroDef2909->arr[1] = _x1607_dps;;

	macroDef2909->arr[2] = _x1633_dps;;;
	array_number_t _x1635_dps = macroDef2909;
	number_t macroDef2910 = 0;
	storage_t stgVar2438 = empty_storage;
	for(int idx_dps = _x1515_dps; idx_dps < _x1513_dps; idx_dps++){
		number_t _x1643_dps = cam_dps->arr[idx_dps];
		number_t _x1645_dps = (_x1643_dps) * (_x1555_dps);
		number_t _x1647_dps = x_dps->arr[idx_dps];
		index_t _x1649_dps = (idx_dps) + (3);
		number_t _x1651_dps = cam_dps->arr[_x1649_dps];
		number_t _x1653_dps = (_x1647_dps) - (_x1651_dps);
		number_t _x1655_dps = (_x1645_dps) * (_x1653_dps);
		number_t _x1657_dps = (macroDef2910) + (_x1655_dps);
		macroDef2910 = _x1657_dps;;
	}
	number_t _x1641_dps = macroDef2910;
	number_t _x1659_dps = (1) - (_x1551_dps);
	number_t _x1661_dps = (_x1641_dps) * (_x1659_dps);
	card_t macroDef2911 = x_dps->length;
	card_t _x1663_dps = macroDef2911;
	card_t size2939 = width_card_t(x_shp);
	array_number_t stgVar2454 = storage_alloc(size2939);
	array_number_t macroDef2913;array_number_t macroDef2912 = (array_number_t)stgVar2454;
		macroDef2912->length=_x1663_dps;
		macroDef2912->arr=(number_t*)(STG_OFFSET(macroDef2912, VECTOR_HEADER_BYTES));
		storage_t stgVar2455 = macroDef2912;
		for(int i_dps = 0; i_dps < macroDef2912->length; i_dps++){
			number_t _x1666_dps = x_dps->arr[i_dps];
			index_t _x1668_dps = (i_dps) + (3);
			number_t _x1670_dps = cam_dps->arr[_x1668_dps];
			number_t _x1672_dps = (_x1666_dps) - (_x1670_dps);
			number_t _x1674_dps = (_x1672_dps) * (_x1551_dps);
			number_t _x1676_dps = _x1635_dps->arr[i_dps];
			number_t _x1678_dps = (_x1676_dps) * (_x1553_dps);
			number_t _x1680_dps = (_x1674_dps) + (_x1678_dps);
			number_t _x1682_dps = cam_dps->arr[i_dps];
			number_t _x1684_dps = (_x1682_dps) * (_x1555_dps);
			number_t _x1686_dps = (_x1684_dps) * (_x1661_dps);
			number_t _x1688_dps = (_x1680_dps) + (_x1686_dps);
			macroDef2912->arr[i_dps] = _x1688_dps;;
			stgVar2455 = STG_OFFSET(stgVar2455, sizeof(number_t));
		}
	array_number_t _x1664_dps = macroDef2912;
	macroDef2913 = _x1664_dps;;
	storage_free(stgVar2454, size2939);
	macroDef2914 = macroDef2913;;
	storage_free(stgVar2433, size2940);
		_x1547_dps = macroDef2914;;
	} else {
		number_t _x1690_dps = cam_dps->arr[1];
		number_t _x1692_dps = x_dps->arr[2];
		number_t _x1694_dps = cam_dps->arr[5];
		number_t _x1696_dps = (_x1692_dps) - (_x1694_dps);
		number_t _x1698_dps = (_x1690_dps) * (_x1696_dps);
		number_t _x1700_dps = cam_dps->arr[2];
		number_t _x1702_dps = x_dps->arr[1];
		number_t _x1704_dps = cam_dps->arr[4];
		number_t _x1706_dps = (_x1702_dps) - (_x1704_dps);
		number_t _x1708_dps = (_x1700_dps) * (_x1706_dps);
		number_t _x1710_dps = (_x1698_dps) - (_x1708_dps);
		number_t _x1714_dps = x_dps->arr[0];
		number_t _x1716_dps = cam_dps->arr[3];
		number_t _x1718_dps = (_x1714_dps) - (_x1716_dps);
		number_t _x1720_dps = (_x1700_dps) * (_x1718_dps);
		number_t _x1722_dps = cam_dps->arr[0];
		number_t _x1724_dps = x_dps->arr[2];
		number_t _x1728_dps = (_x1724_dps) - (_x1694_dps);
		number_t _x1730_dps = (_x1722_dps) * (_x1728_dps);
		number_t _x1732_dps = (_x1720_dps) - (_x1730_dps);
		number_t _x1736_dps = x_dps->arr[1];
		number_t _x1740_dps = (_x1736_dps) - (_x1704_dps);
		number_t _x1742_dps = (_x1722_dps) * (_x1740_dps);
		number_t _x1746_dps = x_dps->arr[0];
		number_t _x1750_dps = (_x1746_dps) - (_x1716_dps);
		number_t _x1752_dps = (_x1690_dps) * (_x1750_dps);
		number_t _x1754_dps = (_x1742_dps) - (_x1752_dps);
		card_t size2942 = width_card_t(3);
	array_number_t stgVar2511 = storage_alloc(size2942);
	array_number_t macroDef2919;array_number_t macroDef2915 = (array_number_t)stgVar2511;
	macroDef2915->length=3;
	macroDef2915->arr=(number_t*)(STG_OFFSET(stgVar2511, VECTOR_HEADER_BYTES));
	

	macroDef2915->arr[0] = _x1710_dps;;

	macroDef2915->arr[1] = _x1732_dps;;

	macroDef2915->arr[2] = _x1754_dps;;;
	array_number_t _x1756_dps = macroDef2915;
	card_t macroDef2916 = x_dps->length;
	card_t _x1758_dps = macroDef2916;
	card_t size2941 = width_card_t(x_shp);
	array_number_t stgVar2517 = storage_alloc(size2941);
	array_number_t macroDef2918;array_number_t macroDef2917 = (array_number_t)stgVar2517;
		macroDef2917->length=_x1758_dps;
		macroDef2917->arr=(number_t*)(STG_OFFSET(macroDef2917, VECTOR_HEADER_BYTES));
		storage_t stgVar2518 = macroDef2917;
		for(int i_dps = 0; i_dps < macroDef2917->length; i_dps++){
			number_t _x1761_dps = x_dps->arr[i_dps];
			index_t _x1763_dps = (i_dps) + (3);
			number_t _x1765_dps = cam_dps->arr[_x1763_dps];
			number_t _x1767_dps = (_x1761_dps) - (_x1765_dps);
			number_t _x1769_dps = _x1756_dps->arr[i_dps];
			number_t _x1771_dps = (_x1767_dps) + (_x1769_dps);
			macroDef2917->arr[i_dps] = _x1771_dps;;
			stgVar2518 = STG_OFFSET(stgVar2518, sizeof(number_t));
		}
	array_number_t _x1759_dps = macroDef2917;
	macroDef2918 = _x1759_dps;;
	storage_free(stgVar2517, size2941);
	macroDef2919 = macroDef2918;;
	storage_free(stgVar2511, size2942);
		_x1547_dps = macroDef2919;;
	}
	array_number_t _x1773_dps = 0;
	if(_x1545_dps) {
		number_t _x1775_dps = sqrt(_x1541_dps);
		number_t _x1778_dps = (2) * (_x1775_dps);
		number_t _x1777_dps = (_x1543_dps) / (_x1778_dps);
		number_t _x1781_dps = cos(_x1775_dps);
		number_t _x1785_dps = sin(_x1775_dps);
		number_t _x1784_dps = -(_x1785_dps);
		number_t _x1783_dps = (_x1777_dps) * (_x1784_dps);
		number_t _x1789_dps = (_x1777_dps) * (_x1781_dps);
		number_t _x1792_dps = (1) / (_x1775_dps);
		number_t _x1796_dps = (0) * (_x1775_dps);
		number_t _x1797_dps = (1) * (_x1777_dps);
		number_t _x1795_dps = (_x1796_dps) - (_x1797_dps);
		number_t _x1798_dps = (_x1775_dps) * (_x1775_dps);
		number_t _x1794_dps = (_x1795_dps) / (_x1798_dps);
		number_t _x1800_dps = cam_dps->arr[1];
		number_t _x1802_dps = cam_d_dps->arr[1];
		number_t _x1804_dps = (_x1800_dps) * (_x1792_dps);
		number_t _x1807_dps = (_x1802_dps) * (_x1792_dps);
		number_t _x1808_dps = (_x1800_dps) * (_x1794_dps);
		number_t _x1806_dps = (_x1807_dps) + (_x1808_dps);
		number_t _x1810_dps = x_dps->arr[2];
		number_t _x1812_dps = x_d_dps->arr[2];
		number_t _x1814_dps = cam_dps->arr[5];
		number_t _x1816_dps = cam_d_dps->arr[5];
		number_t _x1818_dps = (_x1810_dps) - (_x1814_dps);
		number_t _x1820_dps = (_x1812_dps) - (_x1816_dps);
		number_t _x1822_dps = (_x1804_dps) * (_x1818_dps);
		number_t _x1825_dps = (_x1806_dps) * (_x1818_dps);
		number_t _x1826_dps = (_x1804_dps) * (_x1820_dps);
		number_t _x1824_dps = (_x1825_dps) + (_x1826_dps);
		number_t _x1828_dps = cam_dps->arr[2];
		number_t _x1830_dps = cam_d_dps->arr[2];
		number_t _x1832_dps = (_x1828_dps) * (_x1792_dps);
		number_t _x1835_dps = (_x1830_dps) * (_x1792_dps);
		number_t _x1836_dps = (_x1828_dps) * (_x1794_dps);
		number_t _x1834_dps = (_x1835_dps) + (_x1836_dps);
		number_t _x1838_dps = x_dps->arr[1];
		number_t _x1840_dps = x_d_dps->arr[1];
		number_t _x1842_dps = cam_dps->arr[4];
		number_t _x1844_dps = cam_d_dps->arr[4];
		number_t _x1846_dps = (_x1838_dps) - (_x1842_dps);
		number_t _x1848_dps = (_x1840_dps) - (_x1844_dps);
		number_t _x1850_dps = (_x1832_dps) * (_x1846_dps);
		number_t _x1853_dps = (_x1834_dps) * (_x1846_dps);
		number_t _x1854_dps = (_x1832_dps) * (_x1848_dps);
		number_t _x1852_dps = (_x1853_dps) + (_x1854_dps);
		number_t _x1856_dps = (_x1822_dps) - (_x1850_dps);
		number_t _x1858_dps = (_x1824_dps) - (_x1852_dps);
		number_t _x1870_dps = x_dps->arr[0];
		number_t _x1872_dps = x_d_dps->arr[0];
		number_t _x1874_dps = cam_dps->arr[3];
		number_t _x1876_dps = cam_d_dps->arr[3];
		number_t _x1878_dps = (_x1870_dps) - (_x1874_dps);
		number_t _x1880_dps = (_x1872_dps) - (_x1876_dps);
		number_t _x1882_dps = (_x1832_dps) * (_x1878_dps);
		number_t _x1885_dps = (_x1834_dps) * (_x1878_dps);
		number_t _x1886_dps = (_x1832_dps) * (_x1880_dps);
		number_t _x1884_dps = (_x1885_dps) + (_x1886_dps);
		number_t _x1888_dps = cam_dps->arr[0];
		number_t _x1890_dps = cam_d_dps->arr[0];
		number_t _x1892_dps = (_x1888_dps) * (_x1792_dps);
		number_t _x1895_dps = (_x1890_dps) * (_x1792_dps);
		number_t _x1896_dps = (_x1888_dps) * (_x1794_dps);
		number_t _x1894_dps = (_x1895_dps) + (_x1896_dps);
		number_t _x1898_dps = x_dps->arr[2];
		number_t _x1900_dps = x_d_dps->arr[2];
		number_t _x1906_dps = (_x1898_dps) - (_x1814_dps);
		number_t _x1908_dps = (_x1900_dps) - (_x1816_dps);
		number_t _x1910_dps = (_x1892_dps) * (_x1906_dps);
		number_t _x1913_dps = (_x1894_dps) * (_x1906_dps);
		number_t _x1914_dps = (_x1892_dps) * (_x1908_dps);
		number_t _x1912_dps = (_x1913_dps) + (_x1914_dps);
		number_t _x1916_dps = (_x1882_dps) - (_x1910_dps);
		number_t _x1918_dps = (_x1884_dps) - (_x1912_dps);
		number_t _x1930_dps = x_dps->arr[1];
		number_t _x1932_dps = x_d_dps->arr[1];
		number_t _x1938_dps = (_x1930_dps) - (_x1842_dps);
		number_t _x1940_dps = (_x1932_dps) - (_x1844_dps);
		number_t _x1942_dps = (_x1892_dps) * (_x1938_dps);
		number_t _x1945_dps = (_x1894_dps) * (_x1938_dps);
		number_t _x1946_dps = (_x1892_dps) * (_x1940_dps);
		number_t _x1944_dps = (_x1945_dps) + (_x1946_dps);
		number_t _x1958_dps = x_dps->arr[0];
		number_t _x1960_dps = x_d_dps->arr[0];
		number_t _x1966_dps = (_x1958_dps) - (_x1874_dps);
		number_t _x1968_dps = (_x1960_dps) - (_x1876_dps);
		number_t _x1970_dps = (_x1804_dps) * (_x1966_dps);
		number_t _x1973_dps = (_x1806_dps) * (_x1966_dps);
		number_t _x1974_dps = (_x1804_dps) * (_x1968_dps);
		number_t _x1972_dps = (_x1973_dps) + (_x1974_dps);
		number_t _x1976_dps = (_x1942_dps) - (_x1970_dps);
		number_t _x1978_dps = (_x1944_dps) - (_x1972_dps);
		card_t size2946 = width_card_t(3);
	array_number_t stgVar2645 = storage_alloc(size2946);
	array_number_t macroDef2928;array_number_t macroDef2920 = (array_number_t)stgVar2645;
	macroDef2920->length=3;
	macroDef2920->arr=(number_t*)(STG_OFFSET(stgVar2645, VECTOR_HEADER_BYTES));
	

	macroDef2920->arr[0] = _x1856_dps;;

	macroDef2920->arr[1] = _x1916_dps;;

	macroDef2920->arr[2] = _x1976_dps;;;
	array_number_t _x1980_dps = macroDef2920;
	card_t size2945 = width_card_t(3);
	array_number_t stgVar2649 = storage_alloc(size2945);
	array_number_t macroDef2927;array_number_t macroDef2921 = (array_number_t)stgVar2649;
	macroDef2921->length=3;
	macroDef2921->arr=(number_t*)(STG_OFFSET(stgVar2649, VECTOR_HEADER_BYTES));
	

	macroDef2921->arr[0] = _x1858_dps;;

	macroDef2921->arr[1] = _x1918_dps;;

	macroDef2921->arr[2] = _x1978_dps;;;
	array_number_t _x1982_dps = macroDef2921;
	card_t size2944 = width_tuple_card_t_card_t(_x1539_shp);
	array_number_t stgVar2653 = storage_alloc(size2944);
	array_number_t macroDef2926;tuple_number_t_number_t macroDef2922 = _x1539_dps;
	storage_t stgVar2654 = stgVar2653;
	for(int idx_dps = _x1515_dps; idx_dps < _x1513_dps; idx_dps++){
		number_t _x1990_dps = macroDef2922._1;
		number_t _x1992_dps = macroDef2922._2;
		number_t _x1995_dps = cam_dps->arr[idx_dps];
		number_t _x1997_dps = (_x1995_dps) * (_x1792_dps);
		number_t _x1999_dps = x_dps->arr[idx_dps];
		index_t _x2001_dps = (idx_dps) + (3);
		number_t _x2003_dps = cam_dps->arr[_x2001_dps];
		number_t _x2005_dps = (_x1999_dps) - (_x2003_dps);
		number_t _x2007_dps = (_x1997_dps) * (_x2005_dps);
		number_t _x2009_dps = (_x1990_dps) + (_x2007_dps);
		number_t _x2013_dps = cam_d_dps->arr[idx_dps];
		number_t _x2018_dps = (_x2013_dps) * (_x1792_dps);
		number_t _x2019_dps = (_x1995_dps) * (_x1794_dps);
		number_t _x2017_dps = (_x2018_dps) + (_x2019_dps);
		number_t _x2023_dps = x_d_dps->arr[idx_dps];
		number_t _x2029_dps = cam_d_dps->arr[_x2001_dps];
		number_t _x2033_dps = (_x2023_dps) - (_x2029_dps);
		number_t _x2036_dps = (_x2017_dps) * (_x2005_dps);
		number_t _x2037_dps = (_x1997_dps) * (_x2033_dps);
		number_t _x2035_dps = (_x2036_dps) + (_x2037_dps);
		number_t _x2039_dps = (_x1992_dps) + (_x2035_dps);
		tuple_number_t_number_t _x1993_dps = pair(_x2009_dps, _x2039_dps);
		macroDef2922 = _x1993_dps;;
	}
	tuple_number_t_number_t _x1988_dps = macroDef2922;
	number_t _x2042_dps = _x1988_dps._1;
	number_t _x2044_dps = _x1988_dps._2;
	number_t _x2046_dps = (1) - (_x1781_dps);
	number_t _x2048_dps = (0) - (_x1783_dps);
	number_t _x2050_dps = (_x2042_dps) * (_x2046_dps);
	number_t _x2053_dps = (_x2044_dps) * (_x2046_dps);
	number_t _x2054_dps = (_x2042_dps) * (_x2048_dps);
	number_t _x2052_dps = (_x2053_dps) + (_x2054_dps);
	card_t macroDef2923 = x_dps->length;
	card_t _x2056_dps = macroDef2923;
	card_t size2943 = width_card_t(x_shp);
	array_number_t stgVar2693 = storage_alloc(size2943);
	array_number_t macroDef2925;array_number_t macroDef2924 = (array_number_t)stgVar2693;
		macroDef2924->length=_x2056_dps;
		macroDef2924->arr=(number_t*)(STG_OFFSET(macroDef2924, VECTOR_HEADER_BYTES));
		storage_t stgVar2694 = macroDef2924;
		for(int i_dps = 0; i_dps < macroDef2924->length; i_dps++){
			number_t _x2059_dps = x_dps->arr[i_dps];
			number_t _x2061_dps = x_d_dps->arr[i_dps];
			index_t _x2063_dps = (i_dps) + (3);
			number_t _x2065_dps = cam_dps->arr[_x2063_dps];
			number_t _x2067_dps = cam_d_dps->arr[_x2063_dps];
			number_t _x2069_dps = (_x2059_dps) - (_x2065_dps);
			number_t _x2071_dps = (_x2061_dps) - (_x2067_dps);
			number_t _x2074_dps = (_x2071_dps) * (_x1781_dps);
			number_t _x2075_dps = (_x2069_dps) * (_x1783_dps);
			number_t _x2073_dps = (_x2074_dps) + (_x2075_dps);
			number_t _x2077_dps = _x1980_dps->arr[i_dps];
			number_t _x2079_dps = _x1982_dps->arr[i_dps];
			number_t _x2082_dps = (_x2079_dps) * (_x1785_dps);
			number_t _x2083_dps = (_x2077_dps) * (_x1789_dps);
			number_t _x2081_dps = (_x2082_dps) + (_x2083_dps);
			number_t _x2085_dps = (_x2073_dps) + (_x2081_dps);
			number_t _x2087_dps = cam_dps->arr[i_dps];
			number_t _x2089_dps = cam_d_dps->arr[i_dps];
			number_t _x2091_dps = (_x2087_dps) * (_x1792_dps);
			number_t _x2094_dps = (_x2089_dps) * (_x1792_dps);
			number_t _x2095_dps = (_x2087_dps) * (_x1794_dps);
			number_t _x2093_dps = (_x2094_dps) + (_x2095_dps);
			number_t _x2098_dps = (_x2093_dps) * (_x2050_dps);
			number_t _x2099_dps = (_x2091_dps) * (_x2052_dps);
			number_t _x2097_dps = (_x2098_dps) + (_x2099_dps);
			number_t _x2101_dps = (_x2085_dps) + (_x2097_dps);
			macroDef2924->arr[i_dps] = _x2101_dps;;
			stgVar2694 = STG_OFFSET(stgVar2694, sizeof(number_t));
		}
	array_number_t _x2057_dps = macroDef2924;
	macroDef2925 = _x2057_dps;;
	storage_free(stgVar2693, size2943);
	macroDef2926 = macroDef2925;;
	storage_free(stgVar2653, size2944);
	macroDef2927 = macroDef2926;;
	storage_free(stgVar2649, size2945);
	macroDef2928 = macroDef2927;;
	storage_free(stgVar2645, size2946);
		_x1773_dps = macroDef2928;;
	} else {
		number_t _x2103_dps = cam_dps->arr[1];
		number_t _x2105_dps = cam_d_dps->arr[1];
		number_t _x2107_dps = x_dps->arr[2];
		number_t _x2109_dps = x_d_dps->arr[2];
		number_t _x2111_dps = cam_dps->arr[5];
		number_t _x2113_dps = cam_d_dps->arr[5];
		number_t _x2115_dps = (_x2107_dps) - (_x2111_dps);
		number_t _x2117_dps = (_x2109_dps) - (_x2113_dps);
		number_t _x2120_dps = (_x2105_dps) * (_x2115_dps);
		number_t _x2121_dps = (_x2103_dps) * (_x2117_dps);
		number_t _x2119_dps = (_x2120_dps) + (_x2121_dps);
		number_t _x2123_dps = cam_dps->arr[2];
		number_t _x2125_dps = cam_d_dps->arr[2];
		number_t _x2127_dps = x_dps->arr[1];
		number_t _x2129_dps = x_d_dps->arr[1];
		number_t _x2131_dps = cam_dps->arr[4];
		number_t _x2133_dps = cam_d_dps->arr[4];
		number_t _x2135_dps = (_x2127_dps) - (_x2131_dps);
		number_t _x2137_dps = (_x2129_dps) - (_x2133_dps);
		number_t _x2140_dps = (_x2125_dps) * (_x2135_dps);
		number_t _x2141_dps = (_x2123_dps) * (_x2137_dps);
		number_t _x2139_dps = (_x2140_dps) + (_x2141_dps);
		number_t _x2143_dps = (_x2119_dps) - (_x2139_dps);
		number_t _x2149_dps = x_dps->arr[0];
		number_t _x2151_dps = x_d_dps->arr[0];
		number_t _x2153_dps = cam_dps->arr[3];
		number_t _x2155_dps = cam_d_dps->arr[3];
		number_t _x2157_dps = (_x2149_dps) - (_x2153_dps);
		number_t _x2159_dps = (_x2151_dps) - (_x2155_dps);
		number_t _x2162_dps = (_x2125_dps) * (_x2157_dps);
		number_t _x2163_dps = (_x2123_dps) * (_x2159_dps);
		number_t _x2161_dps = (_x2162_dps) + (_x2163_dps);
		number_t _x2165_dps = cam_dps->arr[0];
		number_t _x2167_dps = cam_d_dps->arr[0];
		number_t _x2169_dps = x_dps->arr[2];
		number_t _x2171_dps = x_d_dps->arr[2];
		number_t _x2177_dps = (_x2169_dps) - (_x2111_dps);
		number_t _x2179_dps = (_x2171_dps) - (_x2113_dps);
		number_t _x2182_dps = (_x2167_dps) * (_x2177_dps);
		number_t _x2183_dps = (_x2165_dps) * (_x2179_dps);
		number_t _x2181_dps = (_x2182_dps) + (_x2183_dps);
		number_t _x2185_dps = (_x2161_dps) - (_x2181_dps);
		number_t _x2191_dps = x_dps->arr[1];
		number_t _x2193_dps = x_d_dps->arr[1];
		number_t _x2199_dps = (_x2191_dps) - (_x2131_dps);
		number_t _x2201_dps = (_x2193_dps) - (_x2133_dps);
		number_t _x2204_dps = (_x2167_dps) * (_x2199_dps);
		number_t _x2205_dps = (_x2165_dps) * (_x2201_dps);
		number_t _x2203_dps = (_x2204_dps) + (_x2205_dps);
		number_t _x2211_dps = x_dps->arr[0];
		number_t _x2213_dps = x_d_dps->arr[0];
		number_t _x2219_dps = (_x2211_dps) - (_x2153_dps);
		number_t _x2221_dps = (_x2213_dps) - (_x2155_dps);
		number_t _x2224_dps = (_x2105_dps) * (_x2219_dps);
		number_t _x2225_dps = (_x2103_dps) * (_x2221_dps);
		number_t _x2223_dps = (_x2224_dps) + (_x2225_dps);
		number_t _x2227_dps = (_x2203_dps) - (_x2223_dps);
		card_t size2948 = width_card_t(3);
	array_number_t stgVar2810 = storage_alloc(size2948);
	array_number_t macroDef2933;array_number_t macroDef2929 = (array_number_t)stgVar2810;
	macroDef2929->length=3;
	macroDef2929->arr=(number_t*)(STG_OFFSET(stgVar2810, VECTOR_HEADER_BYTES));
	

	macroDef2929->arr[0] = _x2143_dps;;

	macroDef2929->arr[1] = _x2185_dps;;

	macroDef2929->arr[2] = _x2227_dps;;;
	array_number_t _x2229_dps = macroDef2929;
	card_t macroDef2930 = x_dps->length;
	card_t _x2231_dps = macroDef2930;
	card_t size2947 = width_card_t(x_shp);
	array_number_t stgVar2816 = storage_alloc(size2947);
	array_number_t macroDef2932;array_number_t macroDef2931 = (array_number_t)stgVar2816;
		macroDef2931->length=_x2231_dps;
		macroDef2931->arr=(number_t*)(STG_OFFSET(macroDef2931, VECTOR_HEADER_BYTES));
		storage_t stgVar2817 = macroDef2931;
		for(int i_dps = 0; i_dps < macroDef2931->length; i_dps++){
			number_t _x2234_dps = x_d_dps->arr[i_dps];
			index_t _x2236_dps = (i_dps) + (3);
			number_t _x2238_dps = cam_d_dps->arr[_x2236_dps];
			number_t _x2240_dps = (_x2234_dps) - (_x2238_dps);
			number_t _x2242_dps = _x2229_dps->arr[i_dps];
			number_t _x2244_dps = (_x2240_dps) + (_x2242_dps);
			macroDef2931->arr[i_dps] = _x2244_dps;;
			stgVar2817 = STG_OFFSET(stgVar2817, sizeof(number_t));
		}
	array_number_t _x2232_dps = macroDef2931;
	macroDef2932 = _x2232_dps;;
	storage_free(stgVar2816, size2947);
	macroDef2933 = macroDef2932;;
	storage_free(stgVar2810, size2948);
		_x1773_dps = macroDef2933;;
	}
	number_t _x2246_dps = _x1547_dps->arr[2];
	number_t _x2248_dps = _x1773_dps->arr[2];
	number_t _x2250_dps = (1) / (_x2246_dps);
	number_t _x2254_dps = (0) * (_x2246_dps);
	number_t _x2255_dps = (1) * (_x2248_dps);
	number_t _x2253_dps = (_x2254_dps) - (_x2255_dps);
	number_t _x2256_dps = (_x2246_dps) * (_x2246_dps);
	number_t _x2252_dps = (_x2253_dps) / (_x2256_dps);
	card_t _x2258_shp = 2;
	card_t _x2258_dps = 2;
	card_t size2950 = width_tuple_card_t_card_t(_x1539_shp);
	array_number_t stgVar2838 = storage_alloc(size2950);
	array_number_t macroDef2937;tuple_number_t_number_t macroDef2934 = _x1539_dps;
	storage_t stgVar2839 = stgVar2838;
	for(int idx_dps = _x1515_dps; idx_dps < _x2258_dps; idx_dps++){
		number_t _x2264_dps = macroDef2934._1;
		number_t _x2266_dps = macroDef2934._2;
		number_t _x2269_dps = _x1547_dps->arr[idx_dps];
		number_t _x2271_dps = (_x2269_dps) * (_x2250_dps);
		number_t _x2273_dps = (_x2271_dps) * (_x2271_dps);
		number_t _x2275_dps = (_x2264_dps) + (_x2273_dps);
		number_t _x2279_dps = _x1773_dps->arr[idx_dps];
		number_t _x2284_dps = (_x2279_dps) * (_x2250_dps);
		number_t _x2285_dps = (_x2269_dps) * (_x2252_dps);
		number_t _x2283_dps = (_x2284_dps) + (_x2285_dps);
		number_t _x2288_dps = (_x2283_dps) * (_x2271_dps);
		number_t _x2289_dps = (_x2271_dps) * (_x2283_dps);
		number_t _x2287_dps = (_x2288_dps) + (_x2289_dps);
		number_t _x2291_dps = (_x2266_dps) + (_x2287_dps);
		tuple_number_t_number_t _x2267_dps = pair(_x2275_dps, _x2291_dps);
		macroDef2934 = _x2267_dps;;
	}
	tuple_number_t_number_t _x2262_dps = macroDef2934;
	number_t _x2294_dps = _x2262_dps._1;
	number_t _x2296_dps = _x2262_dps._2;
	number_t _x2298_dps = cam_dps->arr[9];
	number_t _x2300_dps = cam_d_dps->arr[9];
	number_t _x2302_dps = (_x2298_dps) * (_x2294_dps);
	number_t _x2305_dps = (_x2300_dps) * (_x2294_dps);
	number_t _x2306_dps = (_x2298_dps) * (_x2296_dps);
	number_t _x2304_dps = (_x2305_dps) + (_x2306_dps);
	number_t _x2308_dps = (1) + (_x2302_dps);
	number_t _x2310_dps = (0) + (_x2304_dps);
	number_t _x2312_dps = cam_dps->arr[10];
	number_t _x2314_dps = cam_d_dps->arr[10];
	number_t _x2316_dps = (_x2312_dps) * (_x2294_dps);
	number_t _x2319_dps = (_x2314_dps) * (_x2294_dps);
	number_t _x2320_dps = (_x2312_dps) * (_x2296_dps);
	number_t _x2318_dps = (_x2319_dps) + (_x2320_dps);
	number_t _x2322_dps = (_x2316_dps) * (_x2294_dps);
	number_t _x2325_dps = (_x2318_dps) * (_x2294_dps);
	number_t _x2326_dps = (_x2316_dps) * (_x2296_dps);
	number_t _x2324_dps = (_x2325_dps) + (_x2326_dps);
	number_t _x2328_dps = (_x2308_dps) + (_x2322_dps);
	number_t _x2330_dps = (_x2310_dps) + (_x2324_dps);
	number_t _x2332_dps = cam_dps->arr[6];
	number_t _x2334_dps = cam_d_dps->arr[6];
	card_t size2949 = width_card_t(_x2258_shp);
	array_number_t stgVar2887 = storage_alloc(size2949);
	array_number_t macroDef2936;array_number_t macroDef2935 = (array_number_t)stgVar2887;
		macroDef2935->length=_x2258_dps;
		macroDef2935->arr=(number_t*)(STG_OFFSET(macroDef2935, VECTOR_HEADER_BYTES));
		storage_t stgVar2888 = macroDef2935;
		for(int i_dps = 0; i_dps < macroDef2935->length; i_dps++){
			index_t _x2339_dps = (i_dps) + (7);
			number_t _x2341_dps = cam_d_dps->arr[_x2339_dps];
			number_t _x2343_dps = _x1547_dps->arr[i_dps];
			number_t _x2345_dps = _x1773_dps->arr[i_dps];
			number_t _x2347_dps = (_x2343_dps) * (_x2250_dps);
			number_t _x2350_dps = (_x2345_dps) * (_x2250_dps);
			number_t _x2351_dps = (_x2343_dps) * (_x2252_dps);
			number_t _x2349_dps = (_x2350_dps) + (_x2351_dps);
			number_t _x2353_dps = (_x2347_dps) * (_x2328_dps);
			number_t _x2356_dps = (_x2349_dps) * (_x2328_dps);
			number_t _x2357_dps = (_x2347_dps) * (_x2330_dps);
			number_t _x2355_dps = (_x2356_dps) + (_x2357_dps);
			number_t _x2360_dps = (_x2355_dps) * (_x2332_dps);
			number_t _x2361_dps = (_x2353_dps) * (_x2334_dps);
			number_t _x2359_dps = (_x2360_dps) + (_x2361_dps);
			number_t _x2363_dps = (_x2341_dps) + (_x2359_dps);
			macroDef2935->arr[i_dps] = _x2363_dps;;
			stgVar2888 = STG_OFFSET(stgVar2888, sizeof(number_t));
		}
	array_number_t _x2337_dps = macroDef2935;
	macroDef2936 = _x2337_dps;;
	storage_free(stgVar2887, size2949);
	macroDef2937 = macroDef2936;;
	storage_free(stgVar2838, size2950);
	macroDef2938 = macroDef2937;;
	storage_free(stgVar2368, size2951);
	return macroDef2938;
}

#endif
