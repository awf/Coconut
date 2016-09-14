#ifndef __USECASES_BA_STORAGED_H__ 
#define __USECASES_BA_STORAGED_H__ 
#include "runtime/fsharp.h"
#include <stdio.h>
#include <math.h>
#include "linalg_storaged.h"

card_t TOP_LEVEL_usecases_ba_radial_distort_c(card_t rad_params_c, card_t proj_c) {
	
	return TOP_LEVEL_linalg_mult_by_scalar_c(proj_c, 0);
}


array_number_t TOP_LEVEL_usecases_ba_radial_distort_s(storage_t stgVar567, array_number_t rad_params_s, array_number_t proj_s, card_t rad_params_c, card_t proj_c) {
	card_t rsq_c = 0;
	number_t rsq_s = TOP_LEVEL_linalg_sqnorm_s(empty_storage, proj_s, proj_c);
	card_t L_c = 0;
	number_t L_s = ((1) + ((rad_params_s->arr[0]) * (rsq_s))) + (((rad_params_s->arr[1]) * (rsq_s)) * (rsq_s));
	return TOP_LEVEL_linalg_mult_by_scalar_s(stgVar567, proj_s, L_s, proj_c, 0);
}

card_t TOP_LEVEL_usecases_ba_rodrigues_rotate_point_c(card_t rot_c, card_t x_c) {
	
	return TOP_LEVEL_linalg_add_vec_c(TOP_LEVEL_linalg_add_vec_c(TOP_LEVEL_linalg_mult_by_scalar_c(x_c, 0), TOP_LEVEL_linalg_mult_by_scalar_c(TOP_LEVEL_linalg_cross_c(TOP_LEVEL_linalg_mult_by_scalar_c(rot_c, 0), x_c), 0)), TOP_LEVEL_linalg_mult_by_scalar_c(TOP_LEVEL_linalg_mult_by_scalar_c(rot_c, 0), 0));
}


array_number_t TOP_LEVEL_usecases_ba_rodrigues_rotate_point_s(storage_t stgVar577, array_number_t rot_s, array_number_t x_s, card_t rot_c, card_t x_c) {
	card_t sqtheta_c = 0;
	number_t sqtheta_s = TOP_LEVEL_linalg_sqnorm_s(empty_storage, rot_s, rot_c);
	array_number_t ite706 = 0;
	if((sqtheta_s) != (0)) {
		card_t theta_c = 0;
		number_t theta_s = sqrt(sqtheta_s);
		card_t costheta_c = 0;
		number_t costheta_s = cos(theta_s);
		card_t sintheta_c = 0;
		number_t sintheta_s = sin(theta_s);
		card_t theta_inv_c = 0;
		number_t theta_inv_s = (1) / (theta_s);
		card_t w_c = TOP_LEVEL_linalg_mult_by_scalar_c(rot_c, 0);
		card_t size712 = width_card_t(w_c);
	array_number_t stgVar584 = storage_alloc(size712);
	array_number_t macroDef704;array_number_t w_s = TOP_LEVEL_linalg_mult_by_scalar_s(stgVar584, rot_s, theta_inv_s, rot_c, 0);
	card_t w_cross_X_c = TOP_LEVEL_linalg_cross_c(w_c, x_c);
	card_t size711 = width_card_t(w_cross_X_c);
	array_number_t stgVar587 = storage_alloc(size711);
	array_number_t macroDef703;array_number_t w_cross_X_s = TOP_LEVEL_linalg_cross_s(stgVar587, w_s, x_s, w_c, x_c);
	card_t tmp_c = 0;
	number_t tmp_s = (TOP_LEVEL_linalg_dot_prod_s(empty_storage, w_s, x_s, w_c, x_c)) * ((1) - (costheta_s));
	card_t v1_c = TOP_LEVEL_linalg_mult_by_scalar_c(x_c, 0);
	card_t size710 = width_card_t(v1_c);
	array_number_t stgVar593 = storage_alloc(size710);
	array_number_t macroDef702;array_number_t v1_s = TOP_LEVEL_linalg_mult_by_scalar_s(stgVar593, x_s, costheta_s, x_c, 0);
	card_t v2_c = TOP_LEVEL_linalg_mult_by_scalar_c(w_cross_X_c, 0);
	card_t size709 = width_card_t(v2_c);
	array_number_t stgVar596 = storage_alloc(size709);
	array_number_t macroDef701;array_number_t v2_s = TOP_LEVEL_linalg_mult_by_scalar_s(stgVar596, w_cross_X_s, sintheta_s, w_cross_X_c, 0);
	card_t size708 = width_card_t(TOP_LEVEL_linalg_mult_by_scalar_c(w_c, 0));
	array_number_t stgVar600 = storage_alloc(size708);
	array_number_t macroDef700;card_t size707 = width_card_t(TOP_LEVEL_linalg_add_vec_c(v1_c, v2_c));
	array_number_t stgVar599 = storage_alloc(size707);
	array_number_t macroDef699;
	macroDef699 = TOP_LEVEL_linalg_add_vec_s(stgVar577, TOP_LEVEL_linalg_add_vec_s(stgVar599, v1_s, v2_s, v1_c, v2_c), TOP_LEVEL_linalg_mult_by_scalar_s(stgVar600, w_s, tmp_s, w_c, 0), TOP_LEVEL_linalg_add_vec_c(v1_c, v2_c), TOP_LEVEL_linalg_mult_by_scalar_c(w_c, 0));;
	storage_free(stgVar599, size707);
	macroDef700 = macroDef699;;
	storage_free(stgVar600, size708);
	macroDef701 = macroDef700;;
	storage_free(stgVar596, size709);
	macroDef702 = macroDef701;;
	storage_free(stgVar593, size710);
	macroDef703 = macroDef702;;
	storage_free(stgVar587, size711);
	macroDef704 = macroDef703;;
	storage_free(stgVar584, size712);
		ite706 = macroDef704;;
	} else {
		card_t size713 = width_card_t(TOP_LEVEL_linalg_cross_c(rot_c, x_c));
	array_number_t stgVar606 = storage_alloc(size713);
	array_number_t macroDef705;
	macroDef705 = TOP_LEVEL_linalg_add_vec_s(stgVar577, x_s, TOP_LEVEL_linalg_cross_s(stgVar606, rot_s, x_s, rot_c, x_c), x_c, TOP_LEVEL_linalg_cross_c(rot_c, x_c));;
	storage_free(stgVar606, size713);
		ite706 = macroDef705;;
	}
	return ite706;
}

card_t TOP_LEVEL_usecases_ba_project_c(card_t cam_c, card_t x_c) {
	
	return TOP_LEVEL_linalg_add_vec_c(TOP_LEVEL_linalg_vectorSlice_c(2, 0, cam_c), TOP_LEVEL_linalg_mult_by_scalar_c(TOP_LEVEL_usecases_ba_radial_distort_c(TOP_LEVEL_linalg_vectorSlice_c(2, 0, cam_c), TOP_LEVEL_linalg_mult_by_scalar_c(TOP_LEVEL_linalg_vectorSlice_c(2, 0, TOP_LEVEL_usecases_ba_rodrigues_rotate_point_c(TOP_LEVEL_linalg_vectorSlice_c(3, 0, cam_c), TOP_LEVEL_linalg_sub_vec_c(x_c, TOP_LEVEL_linalg_vectorSlice_c(3, 0, cam_c)))), 0)), 0));
}


array_number_t TOP_LEVEL_usecases_ba_project_s(storage_t stgVar714, array_number_t cam_s, array_number_t x_s, card_t cam_c, card_t x_c) {
	card_t N_CAM_PARAMS_c = 0;
	index_t N_CAM_PARAMS_s = 11;
	card_t ROT_IDX_c = 0;
	index_t ROT_IDX_s = 0;
	card_t CENTER_IDX_c = 0;
	index_t CENTER_IDX_s = 3;
	card_t FOCAL_IDX_c = 0;
	index_t FOCAL_IDX_s = 6;
	card_t X0_IDX_c = 0;
	index_t X0_IDX_s = 7;
	card_t RAD_IDX_c = 0;
	index_t RAD_IDX_s = 9;
	card_t Xcam_c = TOP_LEVEL_usecases_ba_rodrigues_rotate_point_c(TOP_LEVEL_linalg_vectorSlice_c(3, 0, cam_c), TOP_LEVEL_linalg_sub_vec_c(x_c, TOP_LEVEL_linalg_vectorSlice_c(3, 0, cam_c)));
	card_t size827 = width_card_t(Xcam_c);
	array_number_t stgVar721 = storage_alloc(size827);
	array_number_t macroDef817;card_t size820 = width_card_t(TOP_LEVEL_linalg_sub_vec_c(x_c, TOP_LEVEL_linalg_vectorSlice_c(3, 0, cam_c)));
	array_number_t stgVar723 = storage_alloc(size820);
	array_number_t macroDef810;card_t size819 = width_card_t(TOP_LEVEL_linalg_vectorSlice_c(3, 0, cam_c));
	array_number_t stgVar722 = storage_alloc(size819);
	array_number_t macroDef809;card_t size818 = width_card_t(TOP_LEVEL_linalg_vectorSlice_c(3, 0, cam_c));
	array_number_t stgVar728 = storage_alloc(size818);
	array_number_t macroDef808;
	macroDef808 = TOP_LEVEL_linalg_sub_vec_s(stgVar723, x_s, TOP_LEVEL_linalg_vectorSlice_s(stgVar728, 3, CENTER_IDX_s, cam_s, 3, 0, cam_c), x_c, TOP_LEVEL_linalg_vectorSlice_c(3, 0, cam_c));;
	storage_free(stgVar728, size818);
	macroDef809 = TOP_LEVEL_usecases_ba_rodrigues_rotate_point_s(stgVar721, TOP_LEVEL_linalg_vectorSlice_s(stgVar722, 3, ROT_IDX_s, cam_s, 3, 0, cam_c), macroDef808, TOP_LEVEL_linalg_vectorSlice_c(3, 0, cam_c), TOP_LEVEL_linalg_sub_vec_c(x_c, TOP_LEVEL_linalg_vectorSlice_c(3, 0, cam_c)));;
	storage_free(stgVar722, size819);
	macroDef810 = macroDef809;;
	storage_free(stgVar723, size820);
	array_number_t Xcam_s = macroDef810;
	card_t distorted_c = TOP_LEVEL_usecases_ba_radial_distort_c(TOP_LEVEL_linalg_vectorSlice_c(2, 0, cam_c), TOP_LEVEL_linalg_mult_by_scalar_c(TOP_LEVEL_linalg_vectorSlice_c(2, 0, Xcam_c), 0));
	card_t size826 = width_card_t(distorted_c);
	array_number_t stgVar732 = storage_alloc(size826);
	array_number_t macroDef816;card_t size823 = width_card_t(TOP_LEVEL_linalg_mult_by_scalar_c(TOP_LEVEL_linalg_vectorSlice_c(2, 0, Xcam_c), 0));
	array_number_t stgVar734 = storage_alloc(size823);
	array_number_t macroDef813;card_t size822 = width_card_t(TOP_LEVEL_linalg_vectorSlice_c(2, 0, cam_c));
	array_number_t stgVar733 = storage_alloc(size822);
	array_number_t macroDef812;card_t size821 = width_card_t(TOP_LEVEL_linalg_vectorSlice_c(2, 0, Xcam_c));
	array_number_t stgVar738 = storage_alloc(size821);
	array_number_t macroDef811;
	macroDef811 = TOP_LEVEL_linalg_mult_by_scalar_s(stgVar734, TOP_LEVEL_linalg_vectorSlice_s(stgVar738, 2, 0, Xcam_s, 2, 0, Xcam_c), (1) / (Xcam_s->arr[2]), TOP_LEVEL_linalg_vectorSlice_c(2, 0, Xcam_c), 0);;
	storage_free(stgVar738, size821);
	macroDef812 = TOP_LEVEL_usecases_ba_radial_distort_s(stgVar732, TOP_LEVEL_linalg_vectorSlice_s(stgVar733, 2, RAD_IDX_s, cam_s, 2, 0, cam_c), macroDef811, TOP_LEVEL_linalg_vectorSlice_c(2, 0, cam_c), TOP_LEVEL_linalg_mult_by_scalar_c(TOP_LEVEL_linalg_vectorSlice_c(2, 0, Xcam_c), 0));;
	storage_free(stgVar733, size822);
	macroDef813 = macroDef812;;
	storage_free(stgVar734, size823);
	array_number_t distorted_s = macroDef813;
	card_t size825 = width_card_t(TOP_LEVEL_linalg_mult_by_scalar_c(distorted_c, 0));
	array_number_t stgVar745 = storage_alloc(size825);
	array_number_t macroDef815;card_t size824 = width_card_t(TOP_LEVEL_linalg_vectorSlice_c(2, 0, cam_c));
	array_number_t stgVar744 = storage_alloc(size824);
	array_number_t macroDef814;
	macroDef814 = TOP_LEVEL_linalg_add_vec_s(stgVar714, TOP_LEVEL_linalg_vectorSlice_s(stgVar744, 2, X0_IDX_s, cam_s, 2, 0, cam_c), TOP_LEVEL_linalg_mult_by_scalar_s(stgVar745, distorted_s, cam_s->arr[FOCAL_IDX_s], distorted_c, 0), TOP_LEVEL_linalg_vectorSlice_c(2, 0, cam_c), TOP_LEVEL_linalg_mult_by_scalar_c(distorted_c, 0));;
	storage_free(stgVar744, size824);
	macroDef815 = macroDef814;;
	storage_free(stgVar745, size825);
	macroDef816 = macroDef815;;
	storage_free(stgVar732, size826);
	macroDef817 = macroDef816;;
	storage_free(stgVar721, size827);
	return macroDef817;
}

card_t TOP_LEVEL_usecases_ba_compute_reproj_err_c(card_t cam_c, card_t x_c, card_t w_c, card_t feat_c) {
	
	return TOP_LEVEL_linalg_mult_by_scalar_c(TOP_LEVEL_linalg_sub_vec_c(TOP_LEVEL_usecases_ba_project_c(cam_c, x_c), feat_c), 0);
}


array_number_t TOP_LEVEL_usecases_ba_compute_reproj_err_s(storage_t stgVar828, array_number_t cam_s, array_number_t x_s, number_t w_s, array_number_t feat_s, card_t cam_c, card_t x_c, card_t w_c, card_t feat_c) {
	card_t size838 = width_card_t(TOP_LEVEL_linalg_sub_vec_c(TOP_LEVEL_usecases_ba_project_c(cam_c, x_c), feat_c));
	array_number_t stgVar829 = storage_alloc(size838);
	array_number_t macroDef836;card_t size837 = width_card_t(TOP_LEVEL_usecases_ba_project_c(cam_c, x_c));
	array_number_t stgVar831 = storage_alloc(size837);
	array_number_t macroDef835;
	macroDef835 = TOP_LEVEL_linalg_sub_vec_s(stgVar829, TOP_LEVEL_usecases_ba_project_s(stgVar831, cam_s, x_s, cam_c, x_c), feat_s, TOP_LEVEL_usecases_ba_project_c(cam_c, x_c), feat_c);;
	storage_free(stgVar831, size837);
	macroDef836 = TOP_LEVEL_linalg_mult_by_scalar_s(stgVar828, macroDef835, w_s, TOP_LEVEL_linalg_sub_vec_c(TOP_LEVEL_usecases_ba_project_c(cam_c, x_c), feat_c), 0);;
	storage_free(stgVar829, size838);
	return macroDef836;
}

card_t TOP_LEVEL_usecases_ba_compute_zach_weight_error_c(card_t w_c) {
	
	return 0;
}


number_t TOP_LEVEL_usecases_ba_compute_zach_weight_error_s(storage_t stgVar839, number_t w_s, card_t w_c) {
	
	return (1) - ((w_s) * (w_s));
}
typedef empty_env_t env_t_848;


value_t lambda848(env_t_848* env845, card_t w_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
card_t TOP_LEVEL_usecases_ba_w_err_c(card_t w_c) {
	env_t_848 env_t_848_value = make_empty_env(); closure_t closure847 = make_closure(lambda848, &env_t_848_value);
	return TOP_LEVEL_linalg_vectorMap_c(closure847, w_c);
}

typedef empty_env_t env_t_855;


value_t lambda855(env_t_855* env849, storage_t stgVar843, number_t w_s, card_t w_c) {
	
	value_t res;
	res.number_t_value = TOP_LEVEL_usecases_ba_compute_zach_weight_error_s(stgVar843, w_s, 0);
	return res;
}
typedef empty_env_t env_t_856;


value_t lambda856(env_t_856* env852, card_t w_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
array_number_t TOP_LEVEL_usecases_ba_w_err_s(storage_t stgVar840, array_number_t w_s, card_t w_c) {
	env_t_855 env_t_855_value = make_empty_env(); closure_t closure851 = make_closure(lambda855, &env_t_855_value);
	env_t_856 env_t_856_value = make_empty_env(); closure_t closure854 = make_closure(lambda856, &env_t_856_value);
	return TOP_LEVEL_linalg_vectorMap_s(stgVar840, closure851, w_s, closure854, w_c);
}
typedef struct env_t_892 {
	matrix_shape_t x_c;
	matrix_shape_t feat_c;
	matrix_shape_t cams_c;
} env_t_892;
env_t_892 make_env_t_892(matrix_shape_t x_c,matrix_shape_t feat_c,matrix_shape_t cams_c) {
	env_t_892 env;
	env.x_c = x_c;
	env.feat_c = feat_c;
	env.cams_c = cams_c;
	return env;
}

value_t lambda892(env_t_892* env889, card_t i_c) {
	matrix_shape_t x_c888 = env889->x_c;
	matrix_shape_t feat_c887 = env889->feat_c;
	matrix_shape_t cams_c886 = env889->cams_c;
	value_t res;
	res.card_t_value = TOP_LEVEL_usecases_ba_compute_reproj_err_c(cams_c886.elem, x_c888.elem, 0, feat_c887.elem);
	return res;
}
matrix_shape_t TOP_LEVEL_usecases_ba_reproj_err_c(matrix_shape_t cams_c, matrix_shape_t x_c, card_t w_c, matrix_shape_t obs_c, matrix_shape_t feat_c) {
	env_t_892 env_t_892_value = make_env_t_892(x_c,feat_c,cams_c); closure_t closure891 = make_closure(lambda892, &env_t_892_value);
	return TOP_LEVEL_linalg_vectorMapToMatrix_c(closure891, TOP_LEVEL_linalg_vectorRange_c(0, (w_c) - (1)));
}

typedef struct env_t_919 {
	array_array_number_t x_s;
	matrix_shape_t x_c;
	array_number_t w_s;
	array_array_number_t obs_s;
	matrix_shape_t obs_c;
	array_array_number_t feat_s;
	matrix_shape_t feat_c;
	array_array_number_t cams_s;
	matrix_shape_t cams_c;
} env_t_919;
env_t_919 make_env_t_919(array_array_number_t x_s,matrix_shape_t x_c,array_number_t w_s,array_array_number_t obs_s,matrix_shape_t obs_c,array_array_number_t feat_s,matrix_shape_t feat_c,array_array_number_t cams_s,matrix_shape_t cams_c) {
	env_t_919 env;
	env.x_s = x_s;
	env.x_c = x_c;
	env.w_s = w_s;
	env.obs_s = obs_s;
	env.obs_c = obs_c;
	env.feat_s = feat_s;
	env.feat_c = feat_c;
	env.cams_s = cams_s;
	env.cams_c = cams_c;
	return env;
}

value_t lambda919(env_t_919* env909, storage_t stgVar867, number_t i_s, card_t i_c) {
	array_array_number_t x_s908 = env909->x_s;
	matrix_shape_t x_c907 = env909->x_c;
	array_number_t w_s906 = env909->w_s;
	array_array_number_t obs_s905 = env909->obs_s;
	matrix_shape_t obs_c904 = env909->obs_c;
	array_array_number_t feat_s903 = env909->feat_s;
	matrix_shape_t feat_c902 = env909->feat_c;
	array_array_number_t cams_s901 = env909->cams_s;
	matrix_shape_t cams_c900 = env909->cams_c;
	card_t size924 = width_card_t(feat_c902.elem);
	array_number_t stgVar871 = storage_alloc(size924);
	array_number_t macroDef899;card_t size923 = width_card_t(x_c907.elem);
	array_number_t stgVar869 = storage_alloc(size923);
	array_number_t macroDef898;card_t size922 = width_card_t(cams_c900.elem);
	array_number_t stgVar868 = storage_alloc(size922);
	array_number_t macroDef897;card_t size920 = width_card_t(obs_c904.elem);
	array_number_t stgVar873 = storage_alloc(size920);
	number_t macroDef895;
	macroDef895 = obs_s905->arr[(int)(i_s)]->arr[0];;
	storage_free(stgVar873, size920);
	card_t size921 = width_card_t(obs_c904.elem);
	array_number_t stgVar876 = storage_alloc(size921);
	number_t macroDef896;
	macroDef896 = obs_s905->arr[(int)(i_s)]->arr[1];;
	storage_free(stgVar876, size921);
	macroDef897 = TOP_LEVEL_usecases_ba_compute_reproj_err_s(stgVar867, cams_s901->arr[(int)(macroDef895)], x_s908->arr[(int)(macroDef896)], w_s906->arr[(int)(i_s)], feat_s903->arr[(int)(i_s)], cams_c900.elem, x_c907.elem, 0, feat_c902.elem);;
	storage_free(stgVar868, size922);
	macroDef898 = macroDef897;;
	storage_free(stgVar869, size923);
	macroDef899 = macroDef898;;
	storage_free(stgVar871, size924);
	value_t res;
	res.array_number_t_value = macroDef899;
	return res;
}
typedef struct env_t_925 {
	matrix_shape_t x_c;
	matrix_shape_t feat_c;
	matrix_shape_t cams_c;
} env_t_925;
env_t_925 make_env_t_925(matrix_shape_t x_c,matrix_shape_t feat_c,matrix_shape_t cams_c) {
	env_t_925 env;
	env.x_c = x_c;
	env.feat_c = feat_c;
	env.cams_c = cams_c;
	return env;
}

value_t lambda925(env_t_925* env915, card_t i_c) {
	matrix_shape_t x_c914 = env915->x_c;
	matrix_shape_t feat_c913 = env915->feat_c;
	matrix_shape_t cams_c912 = env915->cams_c;
	value_t res;
	res.card_t_value = TOP_LEVEL_usecases_ba_compute_reproj_err_c(cams_c912.elem, x_c914.elem, 0, feat_c913.elem);
	return res;
}
array_array_number_t TOP_LEVEL_usecases_ba_reproj_err_s(storage_t stgVar857, array_array_number_t cams_s, array_array_number_t x_s, array_number_t w_s, array_array_number_t obs_s, array_array_number_t feat_s, matrix_shape_t cams_c, matrix_shape_t x_c, card_t w_c, matrix_shape_t obs_c, matrix_shape_t feat_c) {
	card_t n_c = cams_c.card;
	card_t macroDef893 = cams_s->length;
	card_t n_s = macroDef893;
	card_t p_c = w_c;
	card_t macroDef894 = w_s->length;
	card_t p_s = macroDef894;
	card_t range_c = TOP_LEVEL_linalg_vectorRange_c(0, (p_c) - (1));
	card_t size926 = width_card_t(range_c);
	array_number_t stgVar862 = storage_alloc(size926);
	array_array_number_t macroDef918;array_number_t range_s = TOP_LEVEL_linalg_vectorRange_s(stgVar862, 0, (p_s) - (1), 0, (p_c) - (1));
	env_t_919 env_t_919_value = make_env_t_919(x_s,x_c,w_s,obs_s,obs_c,feat_s,feat_c,cams_s,cams_c); closure_t closure911 = make_closure(lambda919, &env_t_919_value);
	env_t_925 env_t_925_value = make_env_t_925(x_c,feat_c,cams_c); closure_t closure917 = make_closure(lambda925, &env_t_925_value);
	macroDef918 = TOP_LEVEL_linalg_vectorMapToMatrix_s(stgVar857, closure911, range_s, closure917, range_c);;
	storage_free(stgVar862, size926);
	return macroDef918;
}
typedef empty_env_t env_t_1106;


value_t lambda1106(env_t_1106* env1100, card_t x_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef empty_env_t env_t_1107;


value_t lambda1107(env_t_1107* env1103, card_t x_c) {
	
	value_t res;
	res.card_t_value = TOP_LEVEL_linalg_vectorRead_c(0, 0);
	return res;
}
matrix_shape_t TOP_LEVEL_usecases_ba_run_ba_from_file_c(card_t fn_c, card_t n_c, card_t m_c, card_t p_c) {
	env_t_1106 env_t_1106_value = make_empty_env(); closure_t closure1102 = make_closure(lambda1106, &env_t_1106_value);
	env_t_1107 env_t_1107_value = make_empty_env(); closure_t closure1105 = make_closure(lambda1107, &env_t_1107_value);
	return TOP_LEVEL_usecases_ba_reproj_err_c(nested_shape_card_t(TOP_LEVEL_linalg_vectorRead_c(0, 0), n_c), nested_shape_card_t(TOP_LEVEL_linalg_vectorRead_c(0, 0), m_c), TOP_LEVEL_linalg_vectorMap_c(closure1102, TOP_LEVEL_linalg_vectorRange_c(1, p_c)), nested_shape_card_t(2, p_c), TOP_LEVEL_linalg_vectorMapToMatrix_c(closure1105, TOP_LEVEL_linalg_vectorRange_c(1, p_c)));
}

typedef struct env_t_1157 {
	card_t one_cam_c;
} env_t_1157;
env_t_1157 make_env_t_1157(card_t one_cam_c) {
	env_t_1157 env;
	env.one_cam_c = one_cam_c;
	return env;
}

value_t lambda1157(env_t_1157* env1109, card_t x_c) {
	card_t one_cam_c1108 = env1109->one_cam_c;
	value_t res;
	res.card_t_value = one_cam_c1108;
	return res;
}
typedef struct env_t_1158 {
	card_t one_x_c;
} env_t_1158;
env_t_1158 make_env_t_1158(card_t one_x_c) {
	env_t_1158 env;
	env.one_x_c = one_x_c;
	return env;
}

value_t lambda1158(env_t_1158* env1114, card_t x_c) {
	card_t one_x_c1113 = env1114->one_x_c;
	value_t res;
	res.card_t_value = one_x_c1113;
	return res;
}
typedef empty_env_t env_t_1159;


value_t lambda1159(env_t_1159* env1118, card_t x_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef struct env_t_1160 {
	number_t one_w_s;
} env_t_1160;
env_t_1160 make_env_t_1160(number_t one_w_s) {
	env_t_1160 env;
	env.one_w_s = one_w_s;
	return env;
}

value_t lambda1160(env_t_1160* env1122, storage_t stgVar945, number_t x_s, card_t x_c) {
	number_t one_w_s1121 = env1122->one_w_s;
	value_t res;
	res.number_t_value = one_w_s1121;
	return res;
}
typedef empty_env_t env_t_1161;


value_t lambda1161(env_t_1161* env1125, card_t x_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef struct env_t_1163 {
	card_t one_feat_c;
} env_t_1163;
env_t_1163 make_env_t_1163(card_t one_feat_c) {
	env_t_1163 env;
	env.one_feat_c = one_feat_c;
	return env;
}

value_t lambda1163(env_t_1163* env1130, card_t x_c) {
	card_t one_feat_c1129 = env1130->one_feat_c;
	value_t res;
	res.card_t_value = one_feat_c1129;
	return res;
}
typedef struct env_t_1164 {
	array_number_t one_feat_s;
} env_t_1164;
env_t_1164 make_env_t_1164(array_number_t one_feat_s) {
	env_t_1164 env;
	env.one_feat_s = one_feat_s;
	return env;
}

value_t lambda1164(env_t_1164* env1134, storage_t stgVar954, number_t x_s, card_t x_c) {
	array_number_t one_feat_s1133 = env1134->one_feat_s;
	value_t res;
	res.array_number_t_value = one_feat_s1133;
	return res;
}
typedef struct env_t_1165 {
	card_t one_feat_c;
} env_t_1165;
env_t_1165 make_env_t_1165(card_t one_feat_c) {
	env_t_1165 env;
	env.one_feat_c = one_feat_c;
	return env;
}

value_t lambda1165(env_t_1165* env1138, card_t x_c) {
	card_t one_feat_c1137 = env1138->one_feat_c;
	value_t res;
	res.card_t_value = one_feat_c1137;
	return res;
}
typedef empty_env_t env_t_1167;


value_t lambda1167(env_t_1167* env1142, card_t x_c) {
	
	value_t res;
	res.card_t_value = 2;
	return res;
}
array_array_number_t TOP_LEVEL_usecases_ba_run_ba_from_file_s(storage_t stgVar927, string_t fn_s, card_t n_s, card_t m_s, card_t p_s, card_t fn_c, card_t n_c, card_t m_c, card_t p_c) {
	card_t oneCard_c = 1;
	card_t oneCard_s = 1;
	card_t one_cam_c = TOP_LEVEL_linalg_vectorRead_c(0, 0);
	card_t size1176 = width_card_t(one_cam_c);
	array_number_t stgVar929 = storage_alloc(size1176);
	array_array_number_t macroDef1155;array_number_t one_cam_s = TOP_LEVEL_linalg_vectorRead_s(stgVar929, fn_s, 1, 0, 0);
	env_t_1157 env_t_1157_value = make_env_t_1157(one_cam_c); closure_t closure1111 = make_closure(lambda1157, &env_t_1157_value);
	matrix_shape_t cam_c = nested_shape_card_t(closure1111.lam(closure1111.env, 0).card_t_value, n_c);
	card_t size1175 = width_matrix_shape_t(cam_c);
	array_number_t stgVar932 = storage_alloc(size1175);
	array_array_number_t macroDef1154;array_array_number_t macroDef1112 = (array_array_number_t)stgVar932;
		macroDef1112->length=n_s;
		macroDef1112->arr=(array_number_t*)(STG_OFFSET(macroDef1112, VECTOR_HEADER_BYTES));
		storage_t stgVar933 = (STG_OFFSET(macroDef1112, MATRIX_HEADER_BYTES(n_s)));
		for(int x_s = 0; x_s < macroDef1112->length; x_s++){
			
			macroDef1112->arr[x_s] = one_cam_s;;
			stgVar933 = STG_OFFSET(stgVar933, VECTOR_ALL_BYTES(macroDef1112->arr[x_s]->length));
		}
	array_array_number_t cam_s = macroDef1112;
	card_t one_x_c = TOP_LEVEL_linalg_vectorRead_c(0, 0);
	card_t size1174 = width_card_t(one_x_c);
	array_number_t stgVar934 = storage_alloc(size1174);
	array_array_number_t macroDef1153;array_number_t one_x_s = TOP_LEVEL_linalg_vectorRead_s(stgVar934, fn_s, 2, 0, 0);
	env_t_1158 env_t_1158_value = make_env_t_1158(one_x_c); closure_t closure1116 = make_closure(lambda1158, &env_t_1158_value);
	matrix_shape_t x_c = nested_shape_card_t(closure1116.lam(closure1116.env, 0).card_t_value, m_c);
	card_t size1173 = width_matrix_shape_t(x_c);
	array_number_t stgVar937 = storage_alloc(size1173);
	array_array_number_t macroDef1152;array_array_number_t macroDef1117 = (array_array_number_t)stgVar937;
		macroDef1117->length=m_s;
		macroDef1117->arr=(array_number_t*)(STG_OFFSET(macroDef1117, VECTOR_HEADER_BYTES));
		storage_t stgVar938 = (STG_OFFSET(macroDef1117, MATRIX_HEADER_BYTES(m_s)));
		for(int x_s = 0; x_s < macroDef1117->length; x_s++){
			
			macroDef1117->arr[x_s] = one_x_s;;
			stgVar938 = STG_OFFSET(stgVar938, VECTOR_ALL_BYTES(macroDef1117->arr[x_s]->length));
		}
	array_array_number_t x_s = macroDef1117;
	card_t one_w_c = 0;
	number_t one_w_s = TOP_LEVEL_linalg_numberRead_s(empty_storage, fn_s, 3, 0, 0);
	env_t_1159 env_t_1159_value = make_empty_env(); closure_t closure1120 = make_closure(lambda1159, &env_t_1159_value);
	card_t w_c = TOP_LEVEL_linalg_vectorMap_c(closure1120, TOP_LEVEL_linalg_vectorRange_c(oneCard_c, p_c));
	card_t size1172 = width_card_t(w_c);
	array_number_t stgVar942 = storage_alloc(size1172);
	array_array_number_t macroDef1151;card_t size1162 = width_card_t(TOP_LEVEL_linalg_vectorRange_c(oneCard_c, p_c));
	array_number_t stgVar944 = storage_alloc(size1162);
	array_number_t macroDef1128;env_t_1160 env_t_1160_value = make_env_t_1160(one_w_s); closure_t closure1124 = make_closure(lambda1160, &env_t_1160_value);
	env_t_1161 env_t_1161_value = make_empty_env(); closure_t closure1127 = make_closure(lambda1161, &env_t_1161_value);
	macroDef1128 = TOP_LEVEL_linalg_vectorMap_s(stgVar942, closure1124, TOP_LEVEL_linalg_vectorRange_s(stgVar944, oneCard_s, p_s, oneCard_c, p_c), closure1127, TOP_LEVEL_linalg_vectorRange_c(oneCard_c, p_c));;
	storage_free(stgVar944, size1162);
	array_number_t w_s = macroDef1128;
	card_t one_feat_c = TOP_LEVEL_linalg_vectorRead_c(0, 0);
	card_t size1171 = width_card_t(one_feat_c);
	array_number_t stgVar948 = storage_alloc(size1171);
	array_array_number_t macroDef1150;array_number_t one_feat_s = TOP_LEVEL_linalg_vectorRead_s(stgVar948, fn_s, 4, 0, 0);
	env_t_1163 env_t_1163_value = make_env_t_1163(one_feat_c); closure_t closure1132 = make_closure(lambda1163, &env_t_1163_value);
	matrix_shape_t feat_c = TOP_LEVEL_linalg_vectorMapToMatrix_c(closure1132, TOP_LEVEL_linalg_vectorRange_c(oneCard_c, p_c));
	card_t size1170 = width_matrix_shape_t(feat_c);
	array_number_t stgVar951 = storage_alloc(size1170);
	array_array_number_t macroDef1149;card_t size1166 = width_card_t(TOP_LEVEL_linalg_vectorRange_c(oneCard_c, p_c));
	array_number_t stgVar953 = storage_alloc(size1166);
	array_array_number_t macroDef1141;env_t_1164 env_t_1164_value = make_env_t_1164(one_feat_s); closure_t closure1136 = make_closure(lambda1164, &env_t_1164_value);
	env_t_1165 env_t_1165_value = make_env_t_1165(one_feat_c); closure_t closure1140 = make_closure(lambda1165, &env_t_1165_value);
	macroDef1141 = TOP_LEVEL_linalg_vectorMapToMatrix_s(stgVar951, closure1136, TOP_LEVEL_linalg_vectorRange_s(stgVar953, oneCard_s, p_s, oneCard_c, p_c), closure1140, TOP_LEVEL_linalg_vectorRange_c(oneCard_c, p_c));;
	storage_free(stgVar953, size1166);
	array_array_number_t feat_s = macroDef1141;
	env_t_1167 env_t_1167_value = make_empty_env(); closure_t closure1144 = make_closure(lambda1167, &env_t_1167_value);
	matrix_shape_t obs_c = nested_shape_card_t(closure1144.lam(closure1144.env, 0).card_t_value, p_c);
	card_t size1169 = width_matrix_shape_t(obs_c);
	array_number_t stgVar957 = storage_alloc(size1169);
	array_array_number_t macroDef1148;array_array_number_t macroDef1146 = (array_array_number_t)stgVar957;
		macroDef1146->length=p_s;
		macroDef1146->arr=(array_number_t*)(STG_OFFSET(macroDef1146, VECTOR_HEADER_BYTES));
		storage_t stgVar958 = (STG_OFFSET(macroDef1146, MATRIX_HEADER_BYTES(p_s)));
		for(int x_s = 0; x_s < macroDef1146->length; x_s++){
			array_number_t macroDef1145 = (array_number_t)stgVar958;
	macroDef1145->length=2;
	macroDef1145->arr=(number_t*)(STG_OFFSET(stgVar958, VECTOR_HEADER_BYTES));
	macroDef1145->arr[0] = (double)(((int)(x_s)) % ((n_s)));
	macroDef1145->arr[1] = (double)(((int)(x_s)) % ((m_s)));;
			macroDef1146->arr[x_s] = macroDef1145;;
			stgVar958 = STG_OFFSET(stgVar958, VECTOR_ALL_BYTES(macroDef1146->arr[x_s]->length));
		}
	array_array_number_t obs_s = macroDef1146;
	card_t t_c = 0;
	timer_t t_s = tic();
	matrix_shape_t res_c = TOP_LEVEL_usecases_ba_reproj_err_c(cam_c, x_c, w_c, obs_c, feat_c);
	card_t size1168 = width_matrix_shape_t(res_c);
	array_number_t stgVar962 = storage_alloc(size1168);
	array_array_number_t macroDef1147;array_array_number_t res_s = TOP_LEVEL_usecases_ba_reproj_err_s(stgVar962, cam_s, x_s, w_s, obs_s, feat_s, cam_c, x_c, w_c, obs_c, feat_c);
	toc(t_s);
	macroDef1147 = res_s;;
	storage_free(stgVar962, size1168);
	macroDef1148 = macroDef1147;;
	storage_free(stgVar957, size1169);
	macroDef1149 = macroDef1148;;
	storage_free(stgVar951, size1170);
	macroDef1150 = macroDef1149;;
	storage_free(stgVar948, size1171);
	macroDef1151 = macroDef1150;;
	storage_free(stgVar942, size1172);
	macroDef1152 = macroDef1151;;
	storage_free(stgVar937, size1173);
	macroDef1153 = macroDef1152;;
	storage_free(stgVar934, size1174);
	macroDef1154 = macroDef1153;;
	storage_free(stgVar932, size1175);
	macroDef1155 = macroDef1154;;
	storage_free(stgVar929, size1176);
	return macroDef1155;
}

card_t TOP_LEVEL_usecases_ba_test_ba_c(card_t dum_c) {
	
	return 0;
}


void TOP_LEVEL_usecases_ba_test_ba_s(storage_t stgVar1177, array_number_t dum_s, card_t dum_c) {
	card_t a_c = 3;
	card_t size1233 = width_card_t(a_c);
	array_number_t stgVar1178 = storage_alloc(size1233);
	array_number_t macroDef1211 = (array_number_t)stgVar1178;
	macroDef1211->length=3;
	macroDef1211->arr=(number_t*)(STG_OFFSET(stgVar1178, VECTOR_HEADER_BYTES));
	macroDef1211->arr[0] = 1;
	macroDef1211->arr[1] = 2;
	macroDef1211->arr[2] = 3;;
	array_number_t a_s = macroDef1211;
	card_t b_c = 3;
	card_t size1232 = width_card_t(b_c);
	array_number_t stgVar1182 = storage_alloc(size1232);
	array_number_t macroDef1212 = (array_number_t)stgVar1182;
	macroDef1212->length=3;
	macroDef1212->arr=(number_t*)(STG_OFFSET(stgVar1182, VECTOR_HEADER_BYTES));
	macroDef1212->arr[0] = 5;
	macroDef1212->arr[1] = 6;
	macroDef1212->arr[2] = 7;;
	array_number_t b_s = macroDef1212;
	array_print(a_s);
	array_print(b_s);
	card_t j_c = TOP_LEVEL_usecases_ba_radial_distort_c(a_c, b_c);
	card_t size1231 = width_card_t(j_c);
	array_number_t stgVar1186 = storage_alloc(size1231);
	array_number_t j_s = TOP_LEVEL_usecases_ba_radial_distort_s(stgVar1186, a_s, b_s, a_c, b_c);
	array_print(j_s);
	card_t k_c = TOP_LEVEL_usecases_ba_rodrigues_rotate_point_c(a_c, b_c);
	card_t size1230 = width_card_t(k_c);
	array_number_t stgVar1189 = storage_alloc(size1230);
	array_number_t k_s = TOP_LEVEL_usecases_ba_rodrigues_rotate_point_s(stgVar1189, a_s, b_s, a_c, b_c);
	array_print(k_s);
	card_t l_c = TOP_LEVEL_linalg_vectorSlice_c(2, 0, k_c);
	card_t size1229 = width_card_t(l_c);
	array_number_t stgVar1192 = storage_alloc(size1229);
	array_number_t l_s = TOP_LEVEL_linalg_vectorSlice_s(stgVar1192, 2, 1, k_s, 2, 0, k_c);
	array_print(l_s);
	card_t cam_c = 11;
	card_t size1228 = width_card_t(cam_c);
	array_number_t stgVar1196 = storage_alloc(size1228);
	array_number_t macroDef1213 = (array_number_t)stgVar1196;
	macroDef1213->length=11;
	macroDef1213->arr=(number_t*)(STG_OFFSET(stgVar1196, VECTOR_HEADER_BYTES));
	macroDef1213->arr[0] = 0;
	macroDef1213->arr[1] = 2;
	macroDef1213->arr[2] = 4;
	macroDef1213->arr[3] = 6;
	macroDef1213->arr[4] = 8;
	macroDef1213->arr[5] = 10;
	macroDef1213->arr[6] = 12;
	macroDef1213->arr[7] = 14;
	macroDef1213->arr[8] = 16;
	macroDef1213->arr[9] = 18;
	macroDef1213->arr[10] = 20;;
	array_number_t cam_s = macroDef1213;
	card_t m_c = TOP_LEVEL_usecases_ba_project_c(cam_c, j_c);
	card_t size1227 = width_card_t(m_c);
	array_number_t stgVar1208 = storage_alloc(size1227);
	array_number_t m_s = TOP_LEVEL_usecases_ba_project_s(stgVar1208, cam_s, j_s, cam_c, j_c);
	array_print(m_s);
	;
	storage_free(stgVar1208, size1227);
	;
	storage_free(stgVar1196, size1228);
	;
	storage_free(stgVar1192, size1229);
	;
	storage_free(stgVar1189, size1230);
	;
	storage_free(stgVar1186, size1231);
	;
	storage_free(stgVar1182, size1232);
	;
	storage_free(stgVar1178, size1233);
	return ;
}
#endif
