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

array_number_t TOP_LEVEL_usecases_ba_project_dps_d(storage_t stgVar2464, array_number_t cam_dps, array_number_t x_dps, array_number_t cam_d_dps, array_number_t x_d_dps, card_t cam_shp, card_t x_shp, card_t cam_d_shp, card_t x_d_shp) {
	number_t _x1540_dps = cam_dps->arr[2];
	number_t _x1542_dps = cam_d_dps->arr[2];
	number_t _x1544_dps = (_x1540_dps) * (_x1540_dps);
	number_t _x1547_dps = (_x1542_dps) * (_x1540_dps);
	number_t _x1548_dps = (_x1540_dps) * (_x1542_dps);
	number_t _x1546_dps = (_x1547_dps) + (_x1548_dps);
	number_t _x1550_dps = cam_dps->arr[1];
	number_t _x1552_dps = cam_d_dps->arr[1];
	number_t _x1554_dps = (_x1550_dps) * (_x1550_dps);
	number_t _x1557_dps = (_x1552_dps) * (_x1550_dps);
	number_t _x1558_dps = (_x1550_dps) * (_x1552_dps);
	number_t _x1556_dps = (_x1557_dps) + (_x1558_dps);
	number_t _x1560_dps = cam_dps->arr[0];
	number_t _x1562_dps = cam_d_dps->arr[0];
	number_t _x1564_dps = (_x1560_dps) * (_x1560_dps);
	number_t _x1567_dps = (_x1562_dps) * (_x1560_dps);
	number_t _x1568_dps = (_x1560_dps) * (_x1562_dps);
	number_t _x1566_dps = (_x1567_dps) + (_x1568_dps);
	number_t _x1570_dps = (0) + (_x1564_dps);
	number_t _x1572_dps = (0) + (_x1566_dps);
	number_t _x1574_dps = (_x1570_dps) + (_x1554_dps);
	number_t _x1576_dps = (_x1572_dps) + (_x1556_dps);
	number_t _x1578_dps = (_x1574_dps) + (_x1544_dps);
	number_t _x1580_dps = (_x1576_dps) + (_x1546_dps);
	bool_t _x1582_dps = (_x1578_dps) != (0);
	tuple_array_number_t_array_number_t _x1584_dps ;
	if(_x1582_dps) {
		number_t _x1587_dps = sqrt(_x1578_dps);
		number_t _x1589_dps = cos(_x1587_dps);
		number_t _x1591_dps = sin(_x1587_dps);
		number_t _x1593_dps = (1) / (_x1587_dps);
		number_t _x1597_dps = (_x1550_dps) * (_x1593_dps);
		number_t _x1599_dps = x_dps->arr[2];
		number_t _x1601_dps = cam_dps->arr[5];
		number_t _x1603_dps = (_x1599_dps) - (_x1601_dps);
		number_t _x1605_dps = (_x1597_dps) * (_x1603_dps);
		number_t _x1609_dps = (_x1540_dps) * (_x1593_dps);
		number_t _x1611_dps = x_dps->arr[1];
		number_t _x1613_dps = cam_dps->arr[4];
		number_t _x1615_dps = (_x1611_dps) - (_x1613_dps);
		number_t _x1617_dps = (_x1609_dps) * (_x1615_dps);
		number_t _x1619_dps = (_x1605_dps) - (_x1617_dps);
		number_t _x1625_dps = x_dps->arr[0];
		number_t _x1627_dps = cam_dps->arr[3];
		number_t _x1629_dps = (_x1625_dps) - (_x1627_dps);
		number_t _x1631_dps = (_x1609_dps) * (_x1629_dps);
		number_t _x1635_dps = (_x1560_dps) * (_x1593_dps);
		number_t _x1643_dps = (_x1635_dps) * (_x1603_dps);
		number_t _x1645_dps = (_x1631_dps) - (_x1643_dps);
		number_t _x1657_dps = (_x1635_dps) * (_x1615_dps);
		number_t _x1669_dps = (_x1597_dps) * (_x1629_dps);
		number_t _x1671_dps = (_x1657_dps) - (_x1669_dps);
		card_t size2877 = width_card_t(3);
	array_number_t stgVar2528 = storage_alloc(size2877);
	tuple_array_number_t_array_number_t macroDef2862;array_number_t macroDef2854 = (array_number_t)stgVar2528;
	macroDef2854->length=3;
	macroDef2854->arr=(number_t*)(STG_OFFSET(stgVar2528, VECTOR_HEADER_BYTES));
	

	macroDef2854->arr[0] = _x1619_dps;;

	macroDef2854->arr[1] = _x1645_dps;;

	macroDef2854->arr[2] = _x1671_dps;;;
	array_number_t _x1673_dps = macroDef2854;
	number_t _x1686_dps = (_x1609_dps) * (_x1603_dps);
	number_t _x1699_dps = (_x1597_dps) * (_x1615_dps);
	number_t _x1712_dps = (_x1635_dps) * (_x1629_dps);
	number_t _x1714_dps = (0) + (_x1712_dps);
	number_t _x1716_dps = (_x1714_dps) + (_x1699_dps);
	number_t _x1718_dps = (_x1716_dps) + (_x1686_dps);
	number_t _x1720_dps = (1) - (_x1589_dps);
	number_t _x1722_dps = (_x1718_dps) * (_x1720_dps);
	card_t macroDef2855 = x_dps->length;
	card_t _x1724_dps = macroDef2855;
	card_t size2876 = width_card_t(x_shp);
	array_number_t stgVar2542 = storage_alloc(size2876);
	tuple_array_number_t_array_number_t macroDef2861;array_number_t macroDef2856 = (array_number_t)stgVar2542;
		macroDef2856->length=_x1724_dps;
		macroDef2856->arr=(number_t*)(STG_OFFSET(macroDef2856, VECTOR_HEADER_BYTES));
		storage_t stgVar2543 = macroDef2856;
		for(int i_dps = 0; i_dps < macroDef2856->length; i_dps++){
			number_t _x1727_dps = x_dps->arr[i_dps];
			index_t _x1729_dps = (i_dps) + (3);
			number_t _x1731_dps = cam_dps->arr[_x1729_dps];
			number_t _x1733_dps = (_x1727_dps) - (_x1731_dps);
			number_t _x1735_dps = (_x1733_dps) * (_x1589_dps);
			number_t _x1737_dps = _x1673_dps->arr[i_dps];
			number_t _x1739_dps = (_x1737_dps) * (_x1591_dps);
			number_t _x1741_dps = (_x1735_dps) + (_x1739_dps);
			number_t _x1743_dps = cam_dps->arr[i_dps];
			number_t _x1745_dps = (_x1743_dps) * (_x1593_dps);
			number_t _x1747_dps = (_x1745_dps) * (_x1722_dps);
			number_t _x1749_dps = (_x1741_dps) + (_x1747_dps);
			macroDef2856->arr[i_dps] = _x1749_dps;;
			stgVar2543 = STG_OFFSET(stgVar2543, sizeof(number_t));
		}
	array_number_t _x1725_dps = macroDef2856;
	number_t _x1754_dps = (2) * (_x1587_dps);
	number_t _x1753_dps = (_x1580_dps) / (_x1754_dps);
	number_t _x1760_dps = -(_x1591_dps);
	number_t _x1759_dps = (_x1753_dps) * (_x1760_dps);
	number_t _x1765_dps = (_x1753_dps) * (_x1589_dps);
	number_t _x1772_dps = (0) * (_x1587_dps);
	number_t _x1773_dps = (1) * (_x1753_dps);
	number_t _x1771_dps = (_x1772_dps) - (_x1773_dps);
	number_t _x1774_dps = (_x1587_dps) * (_x1587_dps);
	number_t _x1770_dps = (_x1771_dps) / (_x1774_dps);
	number_t _x1783_dps = (_x1552_dps) * (_x1593_dps);
	number_t _x1784_dps = (_x1550_dps) * (_x1770_dps);
	number_t _x1782_dps = (_x1783_dps) + (_x1784_dps);
	number_t _x1788_dps = x_d_dps->arr[2];
	number_t _x1792_dps = cam_d_dps->arr[5];
	number_t _x1796_dps = (_x1788_dps) - (_x1792_dps);
	number_t _x1801_dps = (_x1782_dps) * (_x1603_dps);
	number_t _x1802_dps = (_x1597_dps) * (_x1796_dps);
	number_t _x1800_dps = (_x1801_dps) + (_x1802_dps);
	number_t _x1811_dps = (_x1542_dps) * (_x1593_dps);
	number_t _x1812_dps = (_x1540_dps) * (_x1770_dps);
	number_t _x1810_dps = (_x1811_dps) + (_x1812_dps);
	number_t _x1816_dps = x_d_dps->arr[1];
	number_t _x1820_dps = cam_d_dps->arr[4];
	number_t _x1824_dps = (_x1816_dps) - (_x1820_dps);
	number_t _x1829_dps = (_x1810_dps) * (_x1615_dps);
	number_t _x1830_dps = (_x1609_dps) * (_x1824_dps);
	number_t _x1828_dps = (_x1829_dps) + (_x1830_dps);
	number_t _x1834_dps = (_x1800_dps) - (_x1828_dps);
	number_t _x1848_dps = x_d_dps->arr[0];
	number_t _x1852_dps = cam_d_dps->arr[3];
	number_t _x1856_dps = (_x1848_dps) - (_x1852_dps);
	number_t _x1861_dps = (_x1810_dps) * (_x1629_dps);
	number_t _x1862_dps = (_x1609_dps) * (_x1856_dps);
	number_t _x1860_dps = (_x1861_dps) + (_x1862_dps);
	number_t _x1871_dps = (_x1562_dps) * (_x1593_dps);
	number_t _x1872_dps = (_x1560_dps) * (_x1770_dps);
	number_t _x1870_dps = (_x1871_dps) + (_x1872_dps);
	number_t _x1889_dps = (_x1870_dps) * (_x1603_dps);
	number_t _x1890_dps = (_x1635_dps) * (_x1796_dps);
	number_t _x1888_dps = (_x1889_dps) + (_x1890_dps);
	number_t _x1894_dps = (_x1860_dps) - (_x1888_dps);
	number_t _x1921_dps = (_x1870_dps) * (_x1615_dps);
	number_t _x1922_dps = (_x1635_dps) * (_x1824_dps);
	number_t _x1920_dps = (_x1921_dps) + (_x1922_dps);
	number_t _x1949_dps = (_x1782_dps) * (_x1629_dps);
	number_t _x1950_dps = (_x1597_dps) * (_x1856_dps);
	number_t _x1948_dps = (_x1949_dps) + (_x1950_dps);
	number_t _x1954_dps = (_x1920_dps) - (_x1948_dps);
	card_t size2875 = width_card_t(3);
	array_number_t stgVar2615 = storage_alloc(size2875);
	tuple_array_number_t_array_number_t macroDef2860;array_number_t macroDef2857 = (array_number_t)stgVar2615;
	macroDef2857->length=3;
	macroDef2857->arr=(number_t*)(STG_OFFSET(stgVar2615, VECTOR_HEADER_BYTES));
	

	macroDef2857->arr[0] = _x1834_dps;;

	macroDef2857->arr[1] = _x1894_dps;;

	macroDef2857->arr[2] = _x1954_dps;;;
	array_number_t _x1958_dps = macroDef2857;
	number_t _x1986_dps = (_x1810_dps) * (_x1603_dps);
	number_t _x1987_dps = (_x1609_dps) * (_x1796_dps);
	number_t _x1985_dps = (_x1986_dps) + (_x1987_dps);
	number_t _x2015_dps = (_x1782_dps) * (_x1615_dps);
	number_t _x2016_dps = (_x1597_dps) * (_x1824_dps);
	number_t _x2014_dps = (_x2015_dps) + (_x2016_dps);
	number_t _x2044_dps = (_x1870_dps) * (_x1629_dps);
	number_t _x2045_dps = (_x1635_dps) * (_x1856_dps);
	number_t _x2043_dps = (_x2044_dps) + (_x2045_dps);
	number_t _x2049_dps = (0) + (_x2043_dps);
	number_t _x2053_dps = (_x2049_dps) + (_x2014_dps);
	number_t _x2057_dps = (_x2053_dps) + (_x1985_dps);
	number_t _x2061_dps = (0) - (_x1759_dps);
	number_t _x2066_dps = (_x2057_dps) * (_x1720_dps);
	number_t _x2067_dps = (_x1718_dps) * (_x2061_dps);
	number_t _x2065_dps = (_x2066_dps) + (_x2067_dps);
	card_t size2874 = width_card_t(x_shp);
	array_number_t stgVar2635 = storage_alloc(size2874);
	tuple_array_number_t_array_number_t macroDef2859;array_number_t macroDef2858 = (array_number_t)stgVar2635;
		macroDef2858->length=_x1724_dps;
		macroDef2858->arr=(number_t*)(STG_OFFSET(macroDef2858, VECTOR_HEADER_BYTES));
		storage_t stgVar2636 = macroDef2858;
		for(int i_dps = 0; i_dps < macroDef2858->length; i_dps++){
			number_t _x2072_dps = x_dps->arr[i_dps];
			number_t _x2074_dps = x_d_dps->arr[i_dps];
			index_t _x2076_dps = (i_dps) + (3);
			number_t _x2078_dps = cam_dps->arr[_x2076_dps];
			number_t _x2080_dps = cam_d_dps->arr[_x2076_dps];
			number_t _x2082_dps = (_x2072_dps) - (_x2078_dps);
			number_t _x2084_dps = (_x2074_dps) - (_x2080_dps);
			number_t _x2087_dps = (_x2084_dps) * (_x1589_dps);
			number_t _x2088_dps = (_x2082_dps) * (_x1759_dps);
			number_t _x2086_dps = (_x2087_dps) + (_x2088_dps);
			number_t _x2090_dps = _x1673_dps->arr[i_dps];
			number_t _x2092_dps = _x1958_dps->arr[i_dps];
			number_t _x2095_dps = (_x2092_dps) * (_x1591_dps);
			number_t _x2096_dps = (_x2090_dps) * (_x1765_dps);
			number_t _x2094_dps = (_x2095_dps) + (_x2096_dps);
			number_t _x2098_dps = (_x2086_dps) + (_x2094_dps);
			number_t _x2100_dps = cam_dps->arr[i_dps];
			number_t _x2102_dps = cam_d_dps->arr[i_dps];
			number_t _x2104_dps = (_x2100_dps) * (_x1593_dps);
			number_t _x2107_dps = (_x2102_dps) * (_x1593_dps);
			number_t _x2108_dps = (_x2100_dps) * (_x1770_dps);
			number_t _x2106_dps = (_x2107_dps) + (_x2108_dps);
			number_t _x2111_dps = (_x2106_dps) * (_x1722_dps);
			number_t _x2112_dps = (_x2104_dps) * (_x2065_dps);
			number_t _x2110_dps = (_x2111_dps) + (_x2112_dps);
			number_t _x2114_dps = (_x2098_dps) + (_x2110_dps);
			macroDef2858->arr[i_dps] = _x2114_dps;;
			stgVar2636 = STG_OFFSET(stgVar2636, sizeof(number_t));
		}
	array_number_t _x2070_dps = macroDef2858;
	tuple_array_number_t_array_number_t _x1585_dps = pair_v_v(_x1725_dps, _x2070_dps);
	macroDef2859 = _x1585_dps;;
	storage_free(stgVar2635, size2874);
	macroDef2860 = macroDef2859;;
	storage_free(stgVar2615, size2875);
	macroDef2861 = macroDef2860;;
	storage_free(stgVar2542, size2876);
	macroDef2862 = macroDef2861;;
	storage_free(stgVar2528, size2877);
		_x1584_dps = macroDef2862;;
	} else {
		number_t _x2119_dps = x_dps->arr[2];
		number_t _x2121_dps = cam_dps->arr[5];
		number_t _x2123_dps = (_x2119_dps) - (_x2121_dps);
		number_t _x2125_dps = (_x1550_dps) * (_x2123_dps);
		number_t _x2129_dps = x_dps->arr[1];
		number_t _x2131_dps = cam_dps->arr[4];
		number_t _x2133_dps = (_x2129_dps) - (_x2131_dps);
		number_t _x2135_dps = (_x1540_dps) * (_x2133_dps);
		number_t _x2137_dps = (_x2125_dps) - (_x2135_dps);
		number_t _x2141_dps = x_dps->arr[0];
		number_t _x2143_dps = cam_dps->arr[3];
		number_t _x2145_dps = (_x2141_dps) - (_x2143_dps);
		number_t _x2147_dps = (_x1540_dps) * (_x2145_dps);
		number_t _x2157_dps = (_x1560_dps) * (_x2123_dps);
		number_t _x2159_dps = (_x2147_dps) - (_x2157_dps);
		number_t _x2169_dps = (_x1560_dps) * (_x2133_dps);
		number_t _x2179_dps = (_x1550_dps) * (_x2145_dps);
		number_t _x2181_dps = (_x2169_dps) - (_x2179_dps);
		card_t size2881 = width_card_t(3);
	array_number_t stgVar2696 = storage_alloc(size2881);
	tuple_array_number_t_array_number_t macroDef2871;array_number_t macroDef2863 = (array_number_t)stgVar2696;
	macroDef2863->length=3;
	macroDef2863->arr=(number_t*)(STG_OFFSET(stgVar2696, VECTOR_HEADER_BYTES));
	

	macroDef2863->arr[0] = _x2137_dps;;

	macroDef2863->arr[1] = _x2159_dps;;

	macroDef2863->arr[2] = _x2181_dps;;;
	array_number_t _x2183_dps = macroDef2863;
	card_t macroDef2864 = x_dps->length;
	card_t _x2185_dps = macroDef2864;
	card_t size2880 = width_card_t(x_shp);
	array_number_t stgVar2702 = storage_alloc(size2880);
	tuple_array_number_t_array_number_t macroDef2870;array_number_t macroDef2865 = (array_number_t)stgVar2702;
		macroDef2865->length=_x2185_dps;
		macroDef2865->arr=(number_t*)(STG_OFFSET(macroDef2865, VECTOR_HEADER_BYTES));
		storage_t stgVar2703 = macroDef2865;
		for(int i_dps = 0; i_dps < macroDef2865->length; i_dps++){
			number_t _x2188_dps = x_dps->arr[i_dps];
			index_t _x2190_dps = (i_dps) + (3);
			number_t _x2192_dps = cam_dps->arr[_x2190_dps];
			number_t _x2194_dps = (_x2188_dps) - (_x2192_dps);
			number_t _x2196_dps = _x2183_dps->arr[i_dps];
			number_t _x2198_dps = (_x2194_dps) + (_x2196_dps);
			macroDef2865->arr[i_dps] = _x2198_dps;;
			stgVar2703 = STG_OFFSET(stgVar2703, sizeof(number_t));
		}
	array_number_t _x2186_dps = macroDef2865;
	number_t _x2206_dps = x_d_dps->arr[2];
	number_t _x2210_dps = cam_d_dps->arr[5];
	number_t _x2214_dps = (_x2206_dps) - (_x2210_dps);
	number_t _x2217_dps = (_x1552_dps) * (_x2123_dps);
	number_t _x2218_dps = (_x1550_dps) * (_x2214_dps);
	number_t _x2216_dps = (_x2217_dps) + (_x2218_dps);
	number_t _x2226_dps = x_d_dps->arr[1];
	number_t _x2230_dps = cam_d_dps->arr[4];
	number_t _x2234_dps = (_x2226_dps) - (_x2230_dps);
	number_t _x2237_dps = (_x1542_dps) * (_x2133_dps);
	number_t _x2238_dps = (_x1540_dps) * (_x2234_dps);
	number_t _x2236_dps = (_x2237_dps) + (_x2238_dps);
	number_t _x2240_dps = (_x2216_dps) - (_x2236_dps);
	number_t _x2248_dps = x_d_dps->arr[0];
	number_t _x2252_dps = cam_d_dps->arr[3];
	number_t _x2256_dps = (_x2248_dps) - (_x2252_dps);
	number_t _x2259_dps = (_x1542_dps) * (_x2145_dps);
	number_t _x2260_dps = (_x1540_dps) * (_x2256_dps);
	number_t _x2258_dps = (_x2259_dps) + (_x2260_dps);
	number_t _x2279_dps = (_x1562_dps) * (_x2123_dps);
	number_t _x2280_dps = (_x1560_dps) * (_x2214_dps);
	number_t _x2278_dps = (_x2279_dps) + (_x2280_dps);
	number_t _x2282_dps = (_x2258_dps) - (_x2278_dps);
	number_t _x2301_dps = (_x1562_dps) * (_x2133_dps);
	number_t _x2302_dps = (_x1560_dps) * (_x2234_dps);
	number_t _x2300_dps = (_x2301_dps) + (_x2302_dps);
	number_t _x2321_dps = (_x1552_dps) * (_x2145_dps);
	number_t _x2322_dps = (_x1550_dps) * (_x2256_dps);
	number_t _x2320_dps = (_x2321_dps) + (_x2322_dps);
	number_t _x2324_dps = (_x2300_dps) - (_x2320_dps);
	card_t size2879 = width_card_t(3);
	array_number_t stgVar2749 = storage_alloc(size2879);
	tuple_array_number_t_array_number_t macroDef2869;array_number_t macroDef2866 = (array_number_t)stgVar2749;
	macroDef2866->length=3;
	macroDef2866->arr=(number_t*)(STG_OFFSET(stgVar2749, VECTOR_HEADER_BYTES));
	

	macroDef2866->arr[0] = _x2240_dps;;

	macroDef2866->arr[1] = _x2282_dps;;

	macroDef2866->arr[2] = _x2324_dps;;;
	array_number_t _x2326_dps = macroDef2866;
	card_t size2878 = width_card_t(x_shp);
	array_number_t stgVar2753 = storage_alloc(size2878);
	tuple_array_number_t_array_number_t macroDef2868;array_number_t macroDef2867 = (array_number_t)stgVar2753;
		macroDef2867->length=_x2185_dps;
		macroDef2867->arr=(number_t*)(STG_OFFSET(macroDef2867, VECTOR_HEADER_BYTES));
		storage_t stgVar2754 = macroDef2867;
		for(int i_dps = 0; i_dps < macroDef2867->length; i_dps++){
			number_t _x2331_dps = x_d_dps->arr[i_dps];
			index_t _x2333_dps = (i_dps) + (3);
			number_t _x2335_dps = cam_d_dps->arr[_x2333_dps];
			number_t _x2337_dps = (_x2331_dps) - (_x2335_dps);
			number_t _x2339_dps = _x2326_dps->arr[i_dps];
			number_t _x2341_dps = (_x2337_dps) + (_x2339_dps);
			macroDef2867->arr[i_dps] = _x2341_dps;;
			stgVar2754 = STG_OFFSET(stgVar2754, sizeof(number_t));
		}
	array_number_t _x2329_dps = macroDef2867;
	tuple_array_number_t_array_number_t _x2115_dps = pair_v_v(_x2186_dps, _x2329_dps);
	macroDef2868 = _x2115_dps;;
	storage_free(stgVar2753, size2878);
	macroDef2869 = macroDef2868;;
	storage_free(stgVar2749, size2879);
	macroDef2870 = macroDef2869;;
	storage_free(stgVar2702, size2880);
	macroDef2871 = macroDef2870;;
	storage_free(stgVar2696, size2881);
		_x1584_dps = macroDef2871;;
	}
	array_number_t _x2343_dps = _x1584_dps._1;
	array_number_t _x2345_dps = _x1584_dps._2;
	number_t _x2347_dps = _x2343_dps->arr[2];
	number_t _x2349_dps = _x2345_dps->arr[2];
	number_t _x2351_dps = (1) / (_x2347_dps);
	number_t _x2355_dps = (0) * (_x2347_dps);
	number_t _x2356_dps = (1) * (_x2349_dps);
	number_t _x2354_dps = (_x2355_dps) - (_x2356_dps);
	number_t _x2357_dps = (_x2347_dps) * (_x2347_dps);
	number_t _x2353_dps = (_x2354_dps) / (_x2357_dps);
	number_t _x2359_dps = _x2343_dps->arr[1];
	number_t _x2361_dps = _x2345_dps->arr[1];
	number_t _x2363_dps = (_x2359_dps) * (_x2351_dps);
	number_t _x2366_dps = (_x2361_dps) * (_x2351_dps);
	number_t _x2367_dps = (_x2359_dps) * (_x2353_dps);
	number_t _x2365_dps = (_x2366_dps) + (_x2367_dps);
	number_t _x2369_dps = (_x2363_dps) * (_x2363_dps);
	number_t _x2372_dps = (_x2365_dps) * (_x2363_dps);
	number_t _x2373_dps = (_x2363_dps) * (_x2365_dps);
	number_t _x2371_dps = (_x2372_dps) + (_x2373_dps);
	number_t _x2375_dps = _x2343_dps->arr[0];
	number_t _x2377_dps = _x2345_dps->arr[0];
	number_t _x2379_dps = (_x2375_dps) * (_x2351_dps);
	number_t _x2382_dps = (_x2377_dps) * (_x2351_dps);
	number_t _x2383_dps = (_x2375_dps) * (_x2353_dps);
	number_t _x2381_dps = (_x2382_dps) + (_x2383_dps);
	number_t _x2385_dps = (_x2379_dps) * (_x2379_dps);
	number_t _x2388_dps = (_x2381_dps) * (_x2379_dps);
	number_t _x2389_dps = (_x2379_dps) * (_x2381_dps);
	number_t _x2387_dps = (_x2388_dps) + (_x2389_dps);
	number_t _x2391_dps = (0) + (_x2385_dps);
	number_t _x2393_dps = (0) + (_x2387_dps);
	number_t _x2395_dps = (_x2391_dps) + (_x2369_dps);
	number_t _x2397_dps = (_x2393_dps) + (_x2371_dps);
	number_t _x2399_dps = cam_dps->arr[9];
	number_t _x2401_dps = cam_d_dps->arr[9];
	number_t _x2403_dps = (_x2399_dps) * (_x2395_dps);
	number_t _x2406_dps = (_x2401_dps) * (_x2395_dps);
	number_t _x2407_dps = (_x2399_dps) * (_x2397_dps);
	number_t _x2405_dps = (_x2406_dps) + (_x2407_dps);
	number_t _x2409_dps = (1) + (_x2403_dps);
	number_t _x2411_dps = (0) + (_x2405_dps);
	number_t _x2413_dps = cam_dps->arr[10];
	number_t _x2415_dps = cam_d_dps->arr[10];
	number_t _x2417_dps = (_x2413_dps) * (_x2395_dps);
	number_t _x2420_dps = (_x2415_dps) * (_x2395_dps);
	number_t _x2421_dps = (_x2413_dps) * (_x2397_dps);
	number_t _x2419_dps = (_x2420_dps) + (_x2421_dps);
	number_t _x2423_dps = (_x2417_dps) * (_x2395_dps);
	number_t _x2426_dps = (_x2419_dps) * (_x2395_dps);
	number_t _x2427_dps = (_x2417_dps) * (_x2397_dps);
	number_t _x2425_dps = (_x2426_dps) + (_x2427_dps);
	number_t _x2429_dps = (_x2409_dps) + (_x2423_dps);
	number_t _x2431_dps = (_x2411_dps) + (_x2425_dps);
	number_t _x2433_dps = cam_dps->arr[6];
	number_t _x2435_dps = cam_d_dps->arr[6];
	card_t size2882 = width_card_t(2);
	array_number_t stgVar2833 = storage_alloc(size2882);
	array_number_t macroDef2873;array_number_t macroDef2872 = (array_number_t)stgVar2833;
		macroDef2872->length=2;
		macroDef2872->arr=(number_t*)(STG_OFFSET(macroDef2872, VECTOR_HEADER_BYTES));
		storage_t stgVar2834 = macroDef2872;
		for(int i_dps = 0; i_dps < macroDef2872->length; i_dps++){
			index_t _x2439_dps = (i_dps) + (7);
			number_t _x2441_dps = cam_d_dps->arr[_x2439_dps];
			number_t _x2443_dps = _x2343_dps->arr[i_dps];
			number_t _x2445_dps = _x2345_dps->arr[i_dps];
			number_t _x2447_dps = (_x2443_dps) * (_x2351_dps);
			number_t _x2450_dps = (_x2445_dps) * (_x2351_dps);
			number_t _x2451_dps = (_x2443_dps) * (_x2353_dps);
			number_t _x2449_dps = (_x2450_dps) + (_x2451_dps);
			number_t _x2453_dps = (_x2447_dps) * (_x2429_dps);
			number_t _x2456_dps = (_x2449_dps) * (_x2429_dps);
			number_t _x2457_dps = (_x2447_dps) * (_x2431_dps);
			number_t _x2455_dps = (_x2456_dps) + (_x2457_dps);
			number_t _x2460_dps = (_x2455_dps) * (_x2433_dps);
			number_t _x2461_dps = (_x2453_dps) * (_x2435_dps);
			number_t _x2459_dps = (_x2460_dps) + (_x2461_dps);
			number_t _x2463_dps = (_x2441_dps) + (_x2459_dps);
			macroDef2872->arr[i_dps] = _x2463_dps;;
			stgVar2834 = STG_OFFSET(stgVar2834, sizeof(number_t));
		}
	array_number_t _x2436_dps = macroDef2872;
	macroDef2873 = _x2436_dps;;
	storage_free(stgVar2833, size2882);
	return macroDef2873;
}


#endif
