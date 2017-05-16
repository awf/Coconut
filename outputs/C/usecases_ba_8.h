#ifndef __USECASES_BA_8_H__ 
#define __USECASES_BA_8_H__ 
#include "../../Runtime/C/fsharp.h"
#include <stdio.h>
#include <math.h>
#include "linalg.h"
#include "usecases_ba.h"

array_array_number_t TOP_LEVEL_usecases_ba_reproj_err_8(array_array_number_t cams, array_array_number_t x, array_number_t w, array_array_number_t obs, array_array_number_t feat) {
	card_t macroDef1926 = w->length;
	card_t p = macroDef1926;
	card_t s = 0;
	card_t e = (p) - (1);
	array_array_number_t macroDef1935 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1935->length=((e) - (s)) + (1);
	macroDef1935->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * ((e) - (s)) + (1));
		for(int i = 0; i < macroDef1935->length; i++){
			number_t i0 = (double)(((s)) + (i));
			array_number_t cam = cams->arr[(int)(obs->arr[(int)(i0)]->arr[0])];
			array_number_t x0 = x->arr[(int)(obs->arr[(int)(i0)]->arr[1])];
			number_t w0 = w->arr[(int)(i0)];
			array_number_t feat0 = feat->arr[(int)(i0)];
			number_t macroDef1927 = 0;
	for(int idx = 0; idx <= ((((0) + (2)) - (0)) + (1)) - (1); idx++){
		number_t acc0 = macroDef1927;
		index_t i1 = idx;
		number_t x1 = cam->arr[(i1) + (0)];
		number_t cur = (x1) * (x1);
		macroDef1927 = (acc0) + (cur);;
	}
			number_t sqtheta1830 = macroDef1927;
			array_number_t Xcam1888 = 0;
	if((sqtheta1830) != (0)) {
		number_t theta1831 = sqrt(sqtheta1830);
		number_t costheta1832 = cos(theta1831);
		number_t sintheta1833 = sin(theta1831);
		number_t theta_inv1834 = (1) / (theta1831);
		number_t a1835 = cam->arr[(1) + (0)];
		number_t x1836 = x0->arr[2];
		number_t y1837 = cam->arr[(2) + (3)];
		number_t a1838 = cam->arr[(2) + (0)];
		number_t x1839 = x0->arr[1];
		number_t y1840 = cam->arr[(1) + (3)];
		number_t a1841 = cam->arr[(2) + (0)];
		number_t x1842 = x0->arr[0];
		number_t y1843 = cam->arr[(0) + (3)];
		number_t a1844 = cam->arr[(0) + (0)];
		number_t x1845 = x0->arr[2];
		number_t y1846 = cam->arr[(2) + (3)];
		number_t a1847 = cam->arr[(0) + (0)];
		number_t x1848 = x0->arr[1];
		number_t y1849 = cam->arr[(1) + (3)];
		number_t a1850 = cam->arr[(1) + (0)];
		number_t x1851 = x0->arr[0];
		number_t y1852 = cam->arr[(0) + (3)];
		array_number_t w_cross_X1853 = (array_number_t)storage_alloc(sizeof(int) * 2);
	w_cross_X1853->length=3;
	w_cross_X1853->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	w_cross_X1853->arr[0] = (((a1835) * (theta_inv1834)) * ((x1836) - (y1837))) - (((a1838) * (theta_inv1834)) * ((x1839) - (y1840)));
	w_cross_X1853->arr[1] = (((a1841) * (theta_inv1834)) * ((x1842) - (y1843))) - (((a1844) * (theta_inv1834)) * ((x1845) - (y1846)));
	w_cross_X1853->arr[2] = (((a1847) * (theta_inv1834)) * ((x1848) - (y1849))) - (((a1850) * (theta_inv1834)) * ((x1851) - (y1852)));;
		number_t macroDef1928 = 0;
	for(int idx = 0; idx <= ((((0) + (2)) - (0)) + (1)) - (1); idx++){
		number_t acc0 = macroDef1928;
		index_t i1 = idx;
		number_t a1854 = cam->arr[(i1) + (0)];
		number_t x1855 = (a1854) * (theta_inv1834);
		number_t x1856 = x0->arr[i1];
		number_t y1857 = cam->arr[(i1) + (3)];
		number_t y1858 = (x1856) - (y1857);
		number_t cur = (x1855) * (y1858);
		macroDef1928 = (acc0) + (cur);;
	}
		number_t tmp1860 = (macroDef1928) * ((1) - (costheta1832));
		card_t macroDef1929 = x0->length;
		array_number_t macroDef1930 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1930->length=macroDef1929;
	macroDef1930->arr = (number_t*)storage_alloc(sizeof(number_t) * macroDef1929);
		for(int i1 = 0; i1 < macroDef1930->length; i1++){
			number_t x1861 = x0->arr[i1];
			number_t y1862 = cam->arr[(i1) + (3)];
			number_t a1863 = (x1861) - (y1862);
			number_t x1864 = (a1863) * (costheta1832);
			number_t a1865 = w_cross_X1853->arr[i1];
			number_t y1866 = (a1865) * (sintheta1833);
			number_t x1867 = (x1864) + (y1866);
			number_t a1868 = cam->arr[(i1) + (0)];
			number_t a1869 = (a1868) * (theta_inv1834);
			number_t y1870 = (a1869) * (tmp1860);
			macroDef1930->arr[i1] = (x1867) + (y1870);;
		}
		Xcam1888 = macroDef1930;;
	} else {
		number_t x1871 = x0->arr[2];
		number_t y1872 = cam->arr[(2) + (3)];
		number_t x1873 = x0->arr[1];
		number_t y1874 = cam->arr[(1) + (3)];
		number_t x1875 = x0->arr[0];
		number_t y1876 = cam->arr[(0) + (3)];
		number_t x1877 = x0->arr[2];
		number_t y1878 = cam->arr[(2) + (3)];
		number_t x1879 = x0->arr[1];
		number_t y1880 = cam->arr[(1) + (3)];
		number_t x1881 = x0->arr[0];
		number_t y1882 = cam->arr[(0) + (3)];
		array_number_t y1883 = (array_number_t)storage_alloc(sizeof(int) * 2);
	y1883->length=3;
	y1883->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	y1883->arr[0] = ((cam->arr[(1) + (0)]) * ((x1871) - (y1872))) - ((cam->arr[(2) + (0)]) * ((x1873) - (y1874)));
	y1883->arr[1] = ((cam->arr[(2) + (0)]) * ((x1875) - (y1876))) - ((cam->arr[(0) + (0)]) * ((x1877) - (y1878)));
	y1883->arr[2] = ((cam->arr[(0) + (0)]) * ((x1879) - (y1880))) - ((cam->arr[(1) + (0)]) * ((x1881) - (y1882)));;
		card_t macroDef1931 = x0->length;
		array_number_t macroDef1932 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1932->length=macroDef1931;
	macroDef1932->arr = (number_t*)storage_alloc(sizeof(number_t) * macroDef1931);
		for(int i1 = 0; i1 < macroDef1932->length; i1++){
			number_t x1884 = x0->arr[i1];
			number_t y1885 = cam->arr[(i1) + (3)];
			number_t x1886 = (x1884) - (y1885);
			number_t y1887 = y1883->arr[i1];
			macroDef1932->arr[i1] = (x1886) + (y1887);;
		}
		Xcam1888 = macroDef1932;;
	}
			number_t y1889 = (1) / (Xcam1888->arr[2]);
			number_t macroDef1933 = 0;
	for(int idx = 0; idx <= (((1) - (0)) + (1)) - (1); idx++){
		number_t acc0 = macroDef1933;
		index_t i1 = idx;
		number_t a1890 = Xcam1888->arr[(i1) + (0)];
		number_t x11891 = (a1890) * (y1889);
		number_t cur = (x11891) * (x11891);
		macroDef1933 = (acc0) + (cur);;
	}
			number_t rsq18931915 = macroDef1933;
			number_t L18941916 = ((1) + ((cam->arr[(0) + (9)]) * (rsq18931915))) + (((cam->arr[(1) + (9)]) * (rsq18931915)) * (rsq18931915));
			number_t y18951917 = cam->arr[6];
			array_number_t macroDef1934 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1934->length=(((7) + (1)) - (7)) + (1);
	macroDef1934->arr = (number_t*)storage_alloc(sizeof(number_t) * (((7) + (1)) - (7)) + (1));
		for(int i1 = 0; i1 < macroDef1934->length; i1++){
			number_t x18961918 = cam->arr[(i1) + (7)];
			number_t a18971919 = Xcam1888->arr[(i1) + (0)];
			number_t a18981920 = (a18971919) * (y1889);
			number_t a18991921 = (a18981920) * (L18941916);
			number_t y19001922 = (a18991921) * (y18951917);
			number_t x19011923 = (x18961918) + (y19001922);
			number_t y19021924 = feat0->arr[i1];
			number_t a19031925 = (x19011923) - (y19021924);
			macroDef1934->arr[i1] = (a19031925) * (w0);;
		}
			macroDef1935->arr[i] = macroDef1934;;
		}
	return macroDef1935;
}
#endif
