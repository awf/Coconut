#ifndef __USECASES_BA_7_H__ 
#define __USECASES_BA_7_H__ 
#include "../../Runtime/C/fsharp.h"
#include <stdio.h>
#include <math.h>
#include "linalg.h"
#include "usecases_ba.h"
typedef empty_env_t env_t_1750;


value_t lambda1750(env_t_1750* env1717, number_t acc0, number_t cur) {
	
	value_t res;
	res.number_t_value = (acc0) + (cur);
	return res;
}
typedef struct env_t_1751 {
	array_number_t cam;
} env_t_1751;
env_t_1751 make_env_t_1751(array_number_t cam) {
	env_t_1751 env;
	env.cam = cam;
	return env;
}

value_t lambda1751(env_t_1751* env1721, index_t i1) {
	array_number_t cam1720 = env1721->cam;
	number_t x1 = cam1720->arr[(i1) + (0)];
	value_t res;
	res.number_t_value = (x1) * (x1);
	return res;
}
typedef empty_env_t env_t_1752;


value_t lambda1752(env_t_1752* env1725, number_t acc0, number_t cur) {
	
	value_t res;
	res.number_t_value = (acc0) + (cur);
	return res;
}
typedef struct env_t_1753 {
	array_number_t x0;
	number_t theta_inv1624;
	array_number_t cam;
} env_t_1753;
env_t_1753 make_env_t_1753(array_number_t x0,number_t theta_inv1624,array_number_t cam) {
	env_t_1753 env;
	env.x0 = x0;
	env.theta_inv1624 = theta_inv1624;
	env.cam = cam;
	return env;
}

value_t lambda1753(env_t_1753* env1731, index_t i1) {
	array_number_t x01730 = env1731->x0;
	number_t theta_inv16241729 = env1731->theta_inv1624;
	array_number_t cam1728 = env1731->cam;
	number_t a1644 = cam1728->arr[(i1) + (0)];
	number_t x1645 = (a1644) * (theta_inv16241729);
	number_t x1646 = x01730->arr[i1];
	number_t y1647 = cam1728->arr[(i1) + (3)];
	number_t y1648 = (x1646) - (y1647);
	value_t res;
	res.number_t_value = (x1645) * (y1648);
	return res;
}
typedef empty_env_t env_t_1754;


value_t lambda1754(env_t_1754* env1739, number_t acc0, number_t cur) {
	
	value_t res;
	res.number_t_value = (acc0) + (cur);
	return res;
}
typedef struct env_t_1755 {
	number_t y1679;
	array_number_t Xcam1678;
} env_t_1755;
env_t_1755 make_env_t_1755(number_t y1679,array_number_t Xcam1678) {
	env_t_1755 env;
	env.y1679 = y1679;
	env.Xcam1678 = Xcam1678;
	return env;
}

value_t lambda1755(env_t_1755* env1744, index_t i1) {
	number_t y16791743 = env1744->y1679;
	array_number_t Xcam16781742 = env1744->Xcam1678;
	number_t a1680 = Xcam16781742->arr[(i1) + (0)];
	number_t x11681 = (a1680) * (y16791743);
	value_t res;
	res.number_t_value = (x11681) * (x11681);
	return res;
}
array_array_number_t TOP_LEVEL_usecases_ba_reproj_err_7(array_array_number_t cams, array_array_number_t x, array_number_t w, array_array_number_t obs, array_array_number_t feat) {
	card_t macroDef1716 = w->length;
	card_t p = macroDef1716;
	card_t s = 0;
	card_t e = (p) - (1);
	array_array_number_t macroDef1749 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1749->length=((e) - (s)) + (1);
	macroDef1749->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * ((e) - (s)) + (1));
		for(int i = 0; i < macroDef1749->length; i++){
			number_t i0 = (double)(((s)) + (i));
			array_number_t cam = cams->arr[(int)(obs->arr[(int)(i0)]->arr[0])];
			array_number_t x0 = x->arr[(int)(obs->arr[(int)(i0)]->arr[1])];
			number_t w0 = w->arr[(int)(i0)];
			array_number_t feat0 = feat->arr[(int)(i0)];
			number_t macroDef1724 = 0;
	for(int idx = 0; idx <= ((((0) + (2)) - (0)) + (1)) - (1); idx++){
		env_t_1750 env_t_1750_value = make_empty_env(); closure_t closure1719 = make_closure(lambda1750, &env_t_1750_value);
		env_t_1751 env_t_1751_value = make_env_t_1751(cam); closure_t closure1723 = make_closure(lambda1751, &env_t_1751_value);
		macroDef1724 = closure1719.lam(closure1719.env, macroDef1724, closure1723.lam(closure1723.env, idx).number_t_value).number_t_value;;
	}
			number_t sqtheta1620 = macroDef1724;
			array_number_t Xcam1678 = 0;
	if((sqtheta1620) != (0)) {
		number_t theta1621 = sqrt(sqtheta1620);
		number_t costheta1622 = cos(theta1621);
		number_t sintheta1623 = sin(theta1621);
		number_t theta_inv1624 = (1) / (theta1621);
		number_t a1625 = cam->arr[(1) + (0)];
		number_t x1626 = x0->arr[2];
		number_t y1627 = cam->arr[(2) + (3)];
		number_t a1628 = cam->arr[(2) + (0)];
		number_t x1629 = x0->arr[1];
		number_t y1630 = cam->arr[(1) + (3)];
		number_t a1631 = cam->arr[(2) + (0)];
		number_t x1632 = x0->arr[0];
		number_t y1633 = cam->arr[(0) + (3)];
		number_t a1634 = cam->arr[(0) + (0)];
		number_t x1635 = x0->arr[2];
		number_t y1636 = cam->arr[(2) + (3)];
		number_t a1637 = cam->arr[(0) + (0)];
		number_t x1638 = x0->arr[1];
		number_t y1639 = cam->arr[(1) + (3)];
		number_t a1640 = cam->arr[(1) + (0)];
		number_t x1641 = x0->arr[0];
		number_t y1642 = cam->arr[(0) + (3)];
		array_number_t w_cross_X1643 = (array_number_t)storage_alloc(sizeof(int) * 2);
	w_cross_X1643->length=3;
	w_cross_X1643->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	w_cross_X1643->arr[0] = (((a1625) * (theta_inv1624)) * ((x1626) - (y1627))) - (((a1628) * (theta_inv1624)) * ((x1629) - (y1630)));
	w_cross_X1643->arr[1] = (((a1631) * (theta_inv1624)) * ((x1632) - (y1633))) - (((a1634) * (theta_inv1624)) * ((x1635) - (y1636)));
	w_cross_X1643->arr[2] = (((a1637) * (theta_inv1624)) * ((x1638) - (y1639))) - (((a1640) * (theta_inv1624)) * ((x1641) - (y1642)));;
		number_t macroDef1734 = 0;
	for(int idx = 0; idx <= ((((0) + (2)) - (0)) + (1)) - (1); idx++){
		env_t_1752 env_t_1752_value = make_empty_env(); closure_t closure1727 = make_closure(lambda1752, &env_t_1752_value);
		env_t_1753 env_t_1753_value = make_env_t_1753(x0,theta_inv1624,cam); closure_t closure1733 = make_closure(lambda1753, &env_t_1753_value);
		macroDef1734 = closure1727.lam(closure1727.env, macroDef1734, closure1733.lam(closure1733.env, idx).number_t_value).number_t_value;;
	}
		number_t tmp1650 = (macroDef1734) * ((1) - (costheta1622));
		card_t macroDef1735 = x0->length;
		array_number_t macroDef1736 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1736->length=macroDef1735;
	macroDef1736->arr = (number_t*)storage_alloc(sizeof(number_t) * macroDef1735);
		for(int i1 = 0; i1 < macroDef1736->length; i1++){
			number_t x1651 = x0->arr[i1];
			number_t y1652 = cam->arr[(i1) + (3)];
			number_t a1653 = (x1651) - (y1652);
			number_t x1654 = (a1653) * (costheta1622);
			number_t a1655 = w_cross_X1643->arr[i1];
			number_t y1656 = (a1655) * (sintheta1623);
			number_t x1657 = (x1654) + (y1656);
			number_t a1658 = cam->arr[(i1) + (0)];
			number_t a1659 = (a1658) * (theta_inv1624);
			number_t y1660 = (a1659) * (tmp1650);
			macroDef1736->arr[i1] = (x1657) + (y1660);;
		}
		Xcam1678 = macroDef1736;;
	} else {
		number_t x1661 = x0->arr[2];
		number_t y1662 = cam->arr[(2) + (3)];
		number_t x1663 = x0->arr[1];
		number_t y1664 = cam->arr[(1) + (3)];
		number_t x1665 = x0->arr[0];
		number_t y1666 = cam->arr[(0) + (3)];
		number_t x1667 = x0->arr[2];
		number_t y1668 = cam->arr[(2) + (3)];
		number_t x1669 = x0->arr[1];
		number_t y1670 = cam->arr[(1) + (3)];
		number_t x1671 = x0->arr[0];
		number_t y1672 = cam->arr[(0) + (3)];
		array_number_t y1673 = (array_number_t)storage_alloc(sizeof(int) * 2);
	y1673->length=3;
	y1673->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	y1673->arr[0] = ((cam->arr[(1) + (0)]) * ((x1661) - (y1662))) - ((cam->arr[(2) + (0)]) * ((x1663) - (y1664)));
	y1673->arr[1] = ((cam->arr[(2) + (0)]) * ((x1665) - (y1666))) - ((cam->arr[(0) + (0)]) * ((x1667) - (y1668)));
	y1673->arr[2] = ((cam->arr[(0) + (0)]) * ((x1669) - (y1670))) - ((cam->arr[(1) + (0)]) * ((x1671) - (y1672)));;
		card_t macroDef1737 = x0->length;
		array_number_t macroDef1738 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1738->length=macroDef1737;
	macroDef1738->arr = (number_t*)storage_alloc(sizeof(number_t) * macroDef1737);
		for(int i1 = 0; i1 < macroDef1738->length; i1++){
			number_t x1674 = x0->arr[i1];
			number_t y1675 = cam->arr[(i1) + (3)];
			number_t x1676 = (x1674) - (y1675);
			number_t y1677 = y1673->arr[i1];
			macroDef1738->arr[i1] = (x1676) + (y1677);;
		}
		Xcam1678 = macroDef1738;;
	}
			number_t y1679 = (1) / (Xcam1678->arr[2]);
			number_t macroDef1747 = 0;
	for(int idx = 0; idx <= (((1) - (0)) + (1)) - (1); idx++){
		env_t_1754 env_t_1754_value = make_empty_env(); closure_t closure1741 = make_closure(lambda1754, &env_t_1754_value);
		env_t_1755 env_t_1755_value = make_env_t_1755(y1679,Xcam1678); closure_t closure1746 = make_closure(lambda1755, &env_t_1755_value);
		macroDef1747 = closure1741.lam(closure1741.env, macroDef1747, closure1746.lam(closure1746.env, idx).number_t_value).number_t_value;;
	}
			number_t rsq16831705 = macroDef1747;
			number_t L16841706 = ((1) + ((cam->arr[(0) + (9)]) * (rsq16831705))) + (((cam->arr[(1) + (9)]) * (rsq16831705)) * (rsq16831705));
			number_t y16851707 = cam->arr[6];
			array_number_t macroDef1748 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1748->length=(((7) + (1)) - (7)) + (1);
	macroDef1748->arr = (number_t*)storage_alloc(sizeof(number_t) * (((7) + (1)) - (7)) + (1));
		for(int i1 = 0; i1 < macroDef1748->length; i1++){
			number_t x16861708 = cam->arr[(i1) + (7)];
			number_t a16871709 = Xcam1678->arr[(i1) + (0)];
			number_t a16881710 = (a16871709) * (y1679);
			number_t a16891711 = (a16881710) * (L16841706);
			number_t y16901712 = (a16891711) * (y16851707);
			number_t x16911713 = (x16861708) + (y16901712);
			number_t y16921714 = feat0->arr[i1];
			number_t a16931715 = (x16911713) - (y16921714);
			macroDef1748->arr[i1] = (a16931715) * (w0);;
		}
			macroDef1749->arr[i] = macroDef1748;;
		}
	return macroDef1749;
}
#endif
