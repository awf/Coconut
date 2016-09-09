#ifndef __USECASES_BA_STORAGED_H__ 
#define __USECASES_BA_STORAGED_H__ 
#include "runtime/fsharp.h"
#include <stdio.h>
#include <math.h>
#include "linalg_storaged.h"

vector_shape_t TOP_LEVEL_usecases_ba_radial_distort_c(vector_shape_t rad_params_c, vector_shape_t proj_c) {
	
	return TOP_LEVEL_linalg_mult_by_scalar_c(proj_c, 0);
}


array_number_t TOP_LEVEL_usecases_ba_radial_distort_s(storage_t stgVar580, array_number_t rad_params_s, array_number_t proj_s, vector_shape_t rad_params_c, vector_shape_t proj_c) {
	card_t rsq_c = 0;
	card_t size591 = rsq_c;
	array_number_t stgVar581 = storage_alloc(size591);
	array_number_t macroDef590;number_t rsq_s = TOP_LEVEL_linalg_sqnorm_s(stgVar581, proj_s, proj_c);
	card_t L_c = 0;
	number_t L_s = ((1) + ((rad_params_s->arr[0]) * (rsq_s))) + (((rad_params_s->arr[1]) * (rsq_s)) * (rsq_s));
	macroDef590 = TOP_LEVEL_linalg_mult_by_scalar_s(stgVar580, proj_s, L_s, proj_c, 0);;
	storage_free(stgVar581, size591);
	return macroDef590;
}

vector_shape_t TOP_LEVEL_usecases_ba_rodrigues_rotate_point_c(vector_shape_t rot_c, vector_shape_t x_c) {
	
	return TOP_LEVEL_linalg_add_vec_c(TOP_LEVEL_linalg_add_vec_c(TOP_LEVEL_linalg_mult_by_scalar_c(x_c, 0), TOP_LEVEL_linalg_mult_by_scalar_c(TOP_LEVEL_linalg_cross_c(TOP_LEVEL_linalg_mult_by_scalar_c(rot_c, 0), x_c), 0)), TOP_LEVEL_linalg_mult_by_scalar_c(TOP_LEVEL_linalg_mult_by_scalar_c(rot_c, 0), 0));
}


array_number_t TOP_LEVEL_usecases_ba_rodrigues_rotate_point_s(storage_t stgVar592, array_number_t rot_s, array_number_t x_s, vector_shape_t rot_c, vector_shape_t x_c) {
	card_t sqtheta_c = 0;
	card_t size730 = sqtheta_c;
	array_number_t stgVar593 = storage_alloc(size730);
	array_number_t macroDef721;number_t sqtheta_s = TOP_LEVEL_linalg_sqnorm_s(stgVar593, rot_s, rot_c);
	array_number_t ite722 = 0;
	if((sqtheta_s) != (0)) {
		card_t theta_c = 0;
		number_t theta_s = sqrt(sqtheta_s);
		card_t costheta_c = 0;
		number_t costheta_s = cos(theta_s);
		card_t sintheta_c = 0;
		number_t sintheta_s = sin(theta_s);
		card_t theta_inv_c = 0;
		number_t theta_inv_s = (1) / (theta_s);
		vector_shape_t w_c = TOP_LEVEL_linalg_mult_by_scalar_c(rot_c, 0);
		card_t size728 = width_vector_shape_t(w_c);
	array_number_t stgVar599 = storage_alloc(size728);
	array_number_t macroDef719;array_number_t w_s = TOP_LEVEL_linalg_mult_by_scalar_s(stgVar599, rot_s, theta_inv_s, rot_c, 0);
	vector_shape_t w_cross_X_c = TOP_LEVEL_linalg_cross_c(w_c, x_c);
	card_t size727 = width_vector_shape_t(w_cross_X_c);
	array_number_t stgVar602 = storage_alloc(size727);
	array_number_t macroDef718;array_number_t w_cross_X_s = TOP_LEVEL_linalg_cross_s(stgVar602, w_s, x_s, w_c, x_c);
	card_t tmp_c = 0;
	number_t tmp_s = (TOP_LEVEL_linalg_dot_prod_s(empty_storage, w_s, x_s, w_c, x_c)) * ((1) - (costheta_s));
	vector_shape_t v1_c = TOP_LEVEL_linalg_mult_by_scalar_c(x_c, 0);
	card_t size726 = width_vector_shape_t(v1_c);
	array_number_t stgVar608 = storage_alloc(size726);
	array_number_t macroDef717;array_number_t v1_s = TOP_LEVEL_linalg_mult_by_scalar_s(stgVar608, x_s, costheta_s, x_c, 0);
	vector_shape_t v2_c = TOP_LEVEL_linalg_mult_by_scalar_c(w_cross_X_c, 0);
	card_t size725 = width_vector_shape_t(v2_c);
	array_number_t stgVar611 = storage_alloc(size725);
	array_number_t macroDef716;array_number_t v2_s = TOP_LEVEL_linalg_mult_by_scalar_s(stgVar611, w_cross_X_s, sintheta_s, w_cross_X_c, 0);
	card_t size724 = width_vector_shape_t(TOP_LEVEL_linalg_mult_by_scalar_c(w_c, 0));
	array_number_t stgVar615 = storage_alloc(size724);
	array_number_t macroDef715;card_t size723 = width_vector_shape_t(TOP_LEVEL_linalg_add_vec_c(v1_c, v2_c));
	array_number_t stgVar614 = storage_alloc(size723);
	array_number_t macroDef714;
	macroDef714 = TOP_LEVEL_linalg_add_vec_s(stgVar592, TOP_LEVEL_linalg_add_vec_s(stgVar614, v1_s, v2_s, v1_c, v2_c), TOP_LEVEL_linalg_mult_by_scalar_s(stgVar615, w_s, tmp_s, w_c, 0), TOP_LEVEL_linalg_add_vec_c(v1_c, v2_c), TOP_LEVEL_linalg_mult_by_scalar_c(w_c, 0));;
	storage_free(stgVar614, size723);
	macroDef715 = macroDef714;;
	storage_free(stgVar615, size724);
	macroDef716 = macroDef715;;
	storage_free(stgVar611, size725);
	macroDef717 = macroDef716;;
	storage_free(stgVar608, size726);
	macroDef718 = macroDef717;;
	storage_free(stgVar602, size727);
	macroDef719 = macroDef718;;
	storage_free(stgVar599, size728);
		ite722 = macroDef719;;
	} else {
		card_t size729 = width_vector_shape_t(TOP_LEVEL_linalg_cross_c(rot_c, x_c));
	array_number_t stgVar621 = storage_alloc(size729);
	array_number_t macroDef720;
	macroDef720 = TOP_LEVEL_linalg_add_vec_s(stgVar592, x_s, TOP_LEVEL_linalg_cross_s(stgVar621, rot_s, x_s, rot_c, x_c), x_c, TOP_LEVEL_linalg_cross_c(rot_c, x_c));;
	storage_free(stgVar621, size729);
		ite722 = macroDef720;;
	}
	macroDef721 = ite722;;
	storage_free(stgVar593, size730);
	return macroDef721;
}

vector_shape_t TOP_LEVEL_usecases_ba_project_c(vector_shape_t cam_c, vector_shape_t x_c) {
	
	return TOP_LEVEL_linalg_add_vec_c(TOP_LEVEL_linalg_vectorSlice_c(2, 0, cam_c), TOP_LEVEL_linalg_mult_by_scalar_c(TOP_LEVEL_usecases_ba_radial_distort_c(TOP_LEVEL_linalg_vectorSlice_c(2, 0, cam_c), TOP_LEVEL_linalg_mult_by_scalar_c(TOP_LEVEL_linalg_vectorSlice_c(2, 0, TOP_LEVEL_usecases_ba_rodrigues_rotate_point_c(TOP_LEVEL_linalg_vectorSlice_c(3, 0, cam_c), TOP_LEVEL_linalg_sub_vec_c(x_c, TOP_LEVEL_linalg_vectorSlice_c(3, 0, cam_c)))), 0)), 0));
}


array_number_t TOP_LEVEL_usecases_ba_project_s(storage_t stgVar731, array_number_t cam_s, array_number_t x_s, vector_shape_t cam_c, vector_shape_t x_c) {
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
	vector_shape_t Xcam_c = TOP_LEVEL_usecases_ba_rodrigues_rotate_point_c(TOP_LEVEL_linalg_vectorSlice_c(3, 0, cam_c), TOP_LEVEL_linalg_sub_vec_c(x_c, TOP_LEVEL_linalg_vectorSlice_c(3, 0, cam_c)));
	card_t size844 = width_vector_shape_t(Xcam_c);
	array_number_t stgVar738 = storage_alloc(size844);
	array_number_t macroDef834;card_t size837 = width_vector_shape_t(TOP_LEVEL_linalg_sub_vec_c(x_c, TOP_LEVEL_linalg_vectorSlice_c(3, 0, cam_c)));
	array_number_t stgVar740 = storage_alloc(size837);
	array_number_t macroDef827;card_t size836 = width_vector_shape_t(TOP_LEVEL_linalg_vectorSlice_c(3, 0, cam_c));
	array_number_t stgVar739 = storage_alloc(size836);
	array_number_t macroDef826;card_t size835 = width_vector_shape_t(TOP_LEVEL_linalg_vectorSlice_c(3, 0, cam_c));
	array_number_t stgVar745 = storage_alloc(size835);
	array_number_t macroDef825;
	macroDef825 = TOP_LEVEL_linalg_sub_vec_s(stgVar740, x_s, TOP_LEVEL_linalg_vectorSlice_s(stgVar745, 3, CENTER_IDX_s, cam_s, 3, 0, cam_c), x_c, TOP_LEVEL_linalg_vectorSlice_c(3, 0, cam_c));;
	storage_free(stgVar745, size835);
	macroDef826 = TOP_LEVEL_usecases_ba_rodrigues_rotate_point_s(stgVar738, TOP_LEVEL_linalg_vectorSlice_s(stgVar739, 3, ROT_IDX_s, cam_s, 3, 0, cam_c), macroDef825, TOP_LEVEL_linalg_vectorSlice_c(3, 0, cam_c), TOP_LEVEL_linalg_sub_vec_c(x_c, TOP_LEVEL_linalg_vectorSlice_c(3, 0, cam_c)));;
	storage_free(stgVar739, size836);
	macroDef827 = macroDef826;;
	storage_free(stgVar740, size837);
	array_number_t Xcam_s = macroDef827;
	vector_shape_t distorted_c = TOP_LEVEL_usecases_ba_radial_distort_c(TOP_LEVEL_linalg_vectorSlice_c(2, 0, cam_c), TOP_LEVEL_linalg_mult_by_scalar_c(TOP_LEVEL_linalg_vectorSlice_c(2, 0, Xcam_c), 0));
	card_t size843 = width_vector_shape_t(distorted_c);
	array_number_t stgVar749 = storage_alloc(size843);
	array_number_t macroDef833;card_t size840 = width_vector_shape_t(TOP_LEVEL_linalg_mult_by_scalar_c(TOP_LEVEL_linalg_vectorSlice_c(2, 0, Xcam_c), 0));
	array_number_t stgVar751 = storage_alloc(size840);
	array_number_t macroDef830;card_t size839 = width_vector_shape_t(TOP_LEVEL_linalg_vectorSlice_c(2, 0, cam_c));
	array_number_t stgVar750 = storage_alloc(size839);
	array_number_t macroDef829;card_t size838 = width_vector_shape_t(TOP_LEVEL_linalg_vectorSlice_c(2, 0, Xcam_c));
	array_number_t stgVar755 = storage_alloc(size838);
	array_number_t macroDef828;
	macroDef828 = TOP_LEVEL_linalg_mult_by_scalar_s(stgVar751, TOP_LEVEL_linalg_vectorSlice_s(stgVar755, 2, 0, Xcam_s, 2, 0, Xcam_c), (1) / (Xcam_s->arr[2]), TOP_LEVEL_linalg_vectorSlice_c(2, 0, Xcam_c), 0);;
	storage_free(stgVar755, size838);
	macroDef829 = TOP_LEVEL_usecases_ba_radial_distort_s(stgVar749, TOP_LEVEL_linalg_vectorSlice_s(stgVar750, 2, RAD_IDX_s, cam_s, 2, 0, cam_c), macroDef828, TOP_LEVEL_linalg_vectorSlice_c(2, 0, cam_c), TOP_LEVEL_linalg_mult_by_scalar_c(TOP_LEVEL_linalg_vectorSlice_c(2, 0, Xcam_c), 0));;
	storage_free(stgVar750, size839);
	macroDef830 = macroDef829;;
	storage_free(stgVar751, size840);
	array_number_t distorted_s = macroDef830;
	card_t size842 = width_vector_shape_t(TOP_LEVEL_linalg_mult_by_scalar_c(distorted_c, 0));
	array_number_t stgVar762 = storage_alloc(size842);
	array_number_t macroDef832;card_t size841 = width_vector_shape_t(TOP_LEVEL_linalg_vectorSlice_c(2, 0, cam_c));
	array_number_t stgVar761 = storage_alloc(size841);
	array_number_t macroDef831;
	macroDef831 = TOP_LEVEL_linalg_add_vec_s(stgVar731, TOP_LEVEL_linalg_vectorSlice_s(stgVar761, 2, X0_IDX_s, cam_s, 2, 0, cam_c), TOP_LEVEL_linalg_mult_by_scalar_s(stgVar762, distorted_s, cam_s->arr[FOCAL_IDX_s], distorted_c, 0), TOP_LEVEL_linalg_vectorSlice_c(2, 0, cam_c), TOP_LEVEL_linalg_mult_by_scalar_c(distorted_c, 0));;
	storage_free(stgVar761, size841);
	macroDef832 = macroDef831;;
	storage_free(stgVar762, size842);
	macroDef833 = macroDef832;;
	storage_free(stgVar749, size843);
	macroDef834 = macroDef833;;
	storage_free(stgVar738, size844);
	return macroDef834;
}

vector_shape_t TOP_LEVEL_usecases_ba_compute_reproj_err_c(vector_shape_t cam_c, vector_shape_t x_c, card_t w_c, vector_shape_t feat_c) {
	
	return TOP_LEVEL_linalg_mult_by_scalar_c(TOP_LEVEL_linalg_sub_vec_c(TOP_LEVEL_usecases_ba_project_c(cam_c, x_c), feat_c), 0);
}


array_number_t TOP_LEVEL_usecases_ba_compute_reproj_err_s(storage_t stgVar845, array_number_t cam_s, array_number_t x_s, number_t w_s, array_number_t feat_s, vector_shape_t cam_c, vector_shape_t x_c, card_t w_c, vector_shape_t feat_c) {
	card_t size855 = width_vector_shape_t(TOP_LEVEL_linalg_sub_vec_c(TOP_LEVEL_usecases_ba_project_c(cam_c, x_c), feat_c));
	array_number_t stgVar846 = storage_alloc(size855);
	array_number_t macroDef853;card_t size854 = width_vector_shape_t(TOP_LEVEL_usecases_ba_project_c(cam_c, x_c));
	array_number_t stgVar848 = storage_alloc(size854);
	array_number_t macroDef852;
	macroDef852 = TOP_LEVEL_linalg_sub_vec_s(stgVar846, TOP_LEVEL_usecases_ba_project_s(stgVar848, cam_s, x_s, cam_c, x_c), feat_s, TOP_LEVEL_usecases_ba_project_c(cam_c, x_c), feat_c);;
	storage_free(stgVar848, size854);
	macroDef853 = TOP_LEVEL_linalg_mult_by_scalar_s(stgVar845, macroDef852, w_s, TOP_LEVEL_linalg_sub_vec_c(TOP_LEVEL_usecases_ba_project_c(cam_c, x_c), feat_c), 0);;
	storage_free(stgVar846, size855);
	return macroDef853;
}

card_t TOP_LEVEL_usecases_ba_compute_zach_weight_error_c(card_t w_c) {
	
	return 0;
}


number_t TOP_LEVEL_usecases_ba_compute_zach_weight_error_s(storage_t stgVar856, number_t w_s, card_t w_c) {
	
	return (1) - ((w_s) * (w_s));
}
typedef empty_env_t env_t_865;


value_t lambda865(env_t_865* env862, card_t w_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
vector_shape_t TOP_LEVEL_usecases_ba_w_err_c(vector_shape_t w_c) {
	env_t_865 env_t_865_value = make_empty_env(); closure_t closure864 = make_closure(lambda865, &env_t_865_value);
	return TOP_LEVEL_linalg_vectorMap_c(closure864, w_c);
}

typedef empty_env_t env_t_872;


value_t lambda872(env_t_872* env866, storage_t stgVar860, number_t w_s, card_t w_c) {
	
	value_t res;
	res.number_t_value = TOP_LEVEL_usecases_ba_compute_zach_weight_error_s(stgVar860, w_s, 0);
	return res;
}
typedef empty_env_t env_t_873;


value_t lambda873(env_t_873* env869, card_t w_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
array_number_t TOP_LEVEL_usecases_ba_w_err_s(storage_t stgVar857, array_number_t w_s, vector_shape_t w_c) {
	env_t_872 env_t_872_value = make_empty_env(); closure_t closure868 = make_closure(lambda872, &env_t_872_value);
	env_t_873 env_t_873_value = make_empty_env(); closure_t closure871 = make_closure(lambda873, &env_t_873_value);
	return TOP_LEVEL_linalg_vectorMap_s(stgVar857, closure868, w_s, closure871, w_c);
}
typedef struct env_t_909 {
	matrix_shape_t x_c;
	matrix_shape_t feat_c;
	matrix_shape_t cams_c;
} env_t_909;
env_t_909 make_env_t_909(matrix_shape_t x_c,matrix_shape_t feat_c,matrix_shape_t cams_c) {
	env_t_909 env;
	env.x_c = x_c;
	env.feat_c = feat_c;
	env.cams_c = cams_c;
	return env;
}

value_t lambda909(env_t_909* env906, card_t i_c) {
	matrix_shape_t x_c905 = env906->x_c;
	matrix_shape_t feat_c904 = env906->feat_c;
	matrix_shape_t cams_c903 = env906->cams_c;
	value_t res;
	res.vector_shape_t_value = TOP_LEVEL_usecases_ba_compute_reproj_err_c(cams_c903.elem, x_c905.elem, 0, feat_c904.elem);
	return res;
}
matrix_shape_t TOP_LEVEL_usecases_ba_reproj_err_c(matrix_shape_t cams_c, matrix_shape_t x_c, vector_shape_t w_c, matrix_shape_t obs_c, matrix_shape_t feat_c) {
	env_t_909 env_t_909_value = make_env_t_909(x_c,feat_c,cams_c); closure_t closure908 = make_closure(lambda909, &env_t_909_value);
	return TOP_LEVEL_linalg_vectorMapToMatrix_c(closure908, TOP_LEVEL_linalg_vectorRange_c(0, (w_c.card) - (1)));
}

typedef struct env_t_936 {
	array_array_number_t x_s;
	matrix_shape_t x_c;
	array_number_t w_s;
	array_array_number_t obs_s;
	matrix_shape_t obs_c;
	array_array_number_t feat_s;
	matrix_shape_t feat_c;
	array_array_number_t cams_s;
	matrix_shape_t cams_c;
} env_t_936;
env_t_936 make_env_t_936(array_array_number_t x_s,matrix_shape_t x_c,array_number_t w_s,array_array_number_t obs_s,matrix_shape_t obs_c,array_array_number_t feat_s,matrix_shape_t feat_c,array_array_number_t cams_s,matrix_shape_t cams_c) {
	env_t_936 env;
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

value_t lambda936(env_t_936* env926, storage_t stgVar884, number_t i_s, card_t i_c) {
	array_array_number_t x_s925 = env926->x_s;
	matrix_shape_t x_c924 = env926->x_c;
	array_number_t w_s923 = env926->w_s;
	array_array_number_t obs_s922 = env926->obs_s;
	matrix_shape_t obs_c921 = env926->obs_c;
	array_array_number_t feat_s920 = env926->feat_s;
	matrix_shape_t feat_c919 = env926->feat_c;
	array_array_number_t cams_s918 = env926->cams_s;
	matrix_shape_t cams_c917 = env926->cams_c;
	card_t size941 = width_vector_shape_t(feat_c919.elem);
	array_number_t stgVar888 = storage_alloc(size941);
	array_number_t macroDef916;card_t size940 = width_vector_shape_t(x_c924.elem);
	array_number_t stgVar886 = storage_alloc(size940);
	array_number_t macroDef915;card_t size939 = width_vector_shape_t(cams_c917.elem);
	array_number_t stgVar885 = storage_alloc(size939);
	array_number_t macroDef914;card_t size937 = width_vector_shape_t(obs_c921.elem);
	array_number_t stgVar890 = storage_alloc(size937);
	number_t macroDef912;
	macroDef912 = obs_s922->arr[(int)(i_s)]->arr[0];;
	storage_free(stgVar890, size937);
	card_t size938 = width_vector_shape_t(obs_c921.elem);
	array_number_t stgVar893 = storage_alloc(size938);
	number_t macroDef913;
	macroDef913 = obs_s922->arr[(int)(i_s)]->arr[1];;
	storage_free(stgVar893, size938);
	macroDef914 = TOP_LEVEL_usecases_ba_compute_reproj_err_s(stgVar884, cams_s918->arr[(int)(macroDef912)], x_s925->arr[(int)(macroDef913)], w_s923->arr[(int)(i_s)], feat_s920->arr[(int)(i_s)], cams_c917.elem, x_c924.elem, 0, feat_c919.elem);;
	storage_free(stgVar885, size939);
	macroDef915 = macroDef914;;
	storage_free(stgVar886, size940);
	macroDef916 = macroDef915;;
	storage_free(stgVar888, size941);
	value_t res;
	res.array_number_t_value = macroDef916;
	return res;
}
typedef struct env_t_942 {
	matrix_shape_t x_c;
	matrix_shape_t feat_c;
	matrix_shape_t cams_c;
} env_t_942;
env_t_942 make_env_t_942(matrix_shape_t x_c,matrix_shape_t feat_c,matrix_shape_t cams_c) {
	env_t_942 env;
	env.x_c = x_c;
	env.feat_c = feat_c;
	env.cams_c = cams_c;
	return env;
}

value_t lambda942(env_t_942* env932, card_t i_c) {
	matrix_shape_t x_c931 = env932->x_c;
	matrix_shape_t feat_c930 = env932->feat_c;
	matrix_shape_t cams_c929 = env932->cams_c;
	value_t res;
	res.vector_shape_t_value = TOP_LEVEL_usecases_ba_compute_reproj_err_c(cams_c929.elem, x_c931.elem, 0, feat_c930.elem);
	return res;
}
array_array_number_t TOP_LEVEL_usecases_ba_reproj_err_s(storage_t stgVar874, array_array_number_t cams_s, array_array_number_t x_s, array_number_t w_s, array_array_number_t obs_s, array_array_number_t feat_s, matrix_shape_t cams_c, matrix_shape_t x_c, vector_shape_t w_c, matrix_shape_t obs_c, matrix_shape_t feat_c) {
	card_t n_c = cams_c.card;
	card_t macroDef910 = cams_s->length;
	card_t n_s = macroDef910;
	card_t p_c = w_c.card;
	card_t macroDef911 = w_s->length;
	card_t p_s = macroDef911;
	vector_shape_t range_c = TOP_LEVEL_linalg_vectorRange_c(0, (p_c) - (1));
	card_t size943 = width_vector_shape_t(range_c);
	array_number_t stgVar879 = storage_alloc(size943);
	array_array_number_t macroDef935;array_number_t range_s = TOP_LEVEL_linalg_vectorRange_s(stgVar879, 0, (p_s) - (1), 0, (p_c) - (1));
	env_t_936 env_t_936_value = make_env_t_936(x_s,x_c,w_s,obs_s,obs_c,feat_s,feat_c,cams_s,cams_c); closure_t closure928 = make_closure(lambda936, &env_t_936_value);
	env_t_942 env_t_942_value = make_env_t_942(x_c,feat_c,cams_c); closure_t closure934 = make_closure(lambda942, &env_t_942_value);
	macroDef935 = TOP_LEVEL_linalg_vectorMapToMatrix_s(stgVar874, closure928, range_s, closure934, range_c);;
	storage_free(stgVar879, size943);
	return macroDef935;
}
typedef empty_env_t env_t_1123;


value_t lambda1123(env_t_1123* env1117, card_t x_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef empty_env_t env_t_1124;


value_t lambda1124(env_t_1124* env1120, card_t x_c) {
	
	value_t res;
	res.vector_shape_t_value = TOP_LEVEL_linalg_vectorRead_c(0, 0);
	return res;
}
matrix_shape_t TOP_LEVEL_usecases_ba_run_ba_from_file_c(card_t fn_c, card_t n_c, card_t m_c, card_t p_c) {
	env_t_1123 env_t_1123_value = make_empty_env(); closure_t closure1119 = make_closure(lambda1123, &env_t_1123_value);
	env_t_1124 env_t_1124_value = make_empty_env(); closure_t closure1122 = make_closure(lambda1124, &env_t_1124_value);
	return TOP_LEVEL_usecases_ba_reproj_err_c(nested_shape_vector_shape_t(TOP_LEVEL_linalg_vectorRead_c(0, 0), n_c), nested_shape_vector_shape_t(TOP_LEVEL_linalg_vectorRead_c(0, 0), m_c), TOP_LEVEL_linalg_vectorMap_c(closure1119, TOP_LEVEL_linalg_vectorRange_c(1, p_c)), nested_shape_vector_shape_t(nested_shape_card_t(0, 2), p_c), TOP_LEVEL_linalg_vectorMapToMatrix_c(closure1122, TOP_LEVEL_linalg_vectorRange_c(1, p_c)));
}

typedef struct env_t_1175 {
	vector_shape_t one_cam_c;
} env_t_1175;
env_t_1175 make_env_t_1175(vector_shape_t one_cam_c) {
	env_t_1175 env;
	env.one_cam_c = one_cam_c;
	return env;
}

value_t lambda1175(env_t_1175* env1126, card_t x_c) {
	vector_shape_t one_cam_c1125 = env1126->one_cam_c;
	value_t res;
	res.vector_shape_t_value = one_cam_c1125;
	return res;
}
typedef struct env_t_1176 {
	vector_shape_t one_x_c;
} env_t_1176;
env_t_1176 make_env_t_1176(vector_shape_t one_x_c) {
	env_t_1176 env;
	env.one_x_c = one_x_c;
	return env;
}

value_t lambda1176(env_t_1176* env1131, card_t x_c) {
	vector_shape_t one_x_c1130 = env1131->one_x_c;
	value_t res;
	res.vector_shape_t_value = one_x_c1130;
	return res;
}
typedef empty_env_t env_t_1177;


value_t lambda1177(env_t_1177* env1135, card_t x_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef struct env_t_1178 {
	number_t one_w_s;
} env_t_1178;
env_t_1178 make_env_t_1178(number_t one_w_s) {
	env_t_1178 env;
	env.one_w_s = one_w_s;
	return env;
}

value_t lambda1178(env_t_1178* env1139, storage_t stgVar962, number_t x_s, card_t x_c) {
	number_t one_w_s1138 = env1139->one_w_s;
	value_t res;
	res.number_t_value = one_w_s1138;
	return res;
}
typedef empty_env_t env_t_1179;


value_t lambda1179(env_t_1179* env1142, card_t x_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef struct env_t_1181 {
	vector_shape_t one_feat_c;
} env_t_1181;
env_t_1181 make_env_t_1181(vector_shape_t one_feat_c) {
	env_t_1181 env;
	env.one_feat_c = one_feat_c;
	return env;
}

value_t lambda1181(env_t_1181* env1147, card_t x_c) {
	vector_shape_t one_feat_c1146 = env1147->one_feat_c;
	value_t res;
	res.vector_shape_t_value = one_feat_c1146;
	return res;
}
typedef struct env_t_1182 {
	array_number_t one_feat_s;
} env_t_1182;
env_t_1182 make_env_t_1182(array_number_t one_feat_s) {
	env_t_1182 env;
	env.one_feat_s = one_feat_s;
	return env;
}

value_t lambda1182(env_t_1182* env1151, storage_t stgVar971, number_t x_s, card_t x_c) {
	array_number_t one_feat_s1150 = env1151->one_feat_s;
	value_t res;
	res.array_number_t_value = one_feat_s1150;
	return res;
}
typedef struct env_t_1183 {
	vector_shape_t one_feat_c;
} env_t_1183;
env_t_1183 make_env_t_1183(vector_shape_t one_feat_c) {
	env_t_1183 env;
	env.one_feat_c = one_feat_c;
	return env;
}

value_t lambda1183(env_t_1183* env1155, card_t x_c) {
	vector_shape_t one_feat_c1154 = env1155->one_feat_c;
	value_t res;
	res.vector_shape_t_value = one_feat_c1154;
	return res;
}
typedef empty_env_t env_t_1185;


value_t lambda1185(env_t_1185* env1159, card_t x_c) {
	
	value_t res;
	res.vector_shape_t_value = nested_shape_card_t(0, 2);
	return res;
}
array_array_number_t TOP_LEVEL_usecases_ba_run_ba_from_file_s(storage_t stgVar944, string_t fn_s, card_t n_s, card_t m_s, card_t p_s, card_t fn_c, card_t n_c, card_t m_c, card_t p_c) {
	card_t oneCard_c = 1;
	card_t oneCard_s = 1;
	vector_shape_t one_cam_c = TOP_LEVEL_linalg_vectorRead_c(0, 0);
	card_t size1195 = width_vector_shape_t(one_cam_c);
	array_number_t stgVar946 = storage_alloc(size1195);
	array_array_number_t macroDef1173;array_number_t one_cam_s = TOP_LEVEL_linalg_vectorRead_s(stgVar946, fn_s, 1, 0, 0);
	env_t_1175 env_t_1175_value = make_env_t_1175(one_cam_c); closure_t closure1128 = make_closure(lambda1175, &env_t_1175_value);
	matrix_shape_t cam_c = nested_shape_vector_shape_t(closure1128.lam(closure1128.env, 0).vector_shape_t_value, n_c);
	card_t size1194 = width_matrix_shape_t(cam_c);
	array_number_t stgVar949 = storage_alloc(size1194);
	array_array_number_t macroDef1172;array_array_number_t macroDef1129 = (array_array_number_t)stgVar949;
		macroDef1129->length=n_s;
		macroDef1129->arr=(array_number_t*)(STG_OFFSET(macroDef1129, VECTOR_HEADER_BYTES));
		storage_t stgVar950 = (STG_OFFSET(macroDef1129, MATRIX_HEADER_BYTES(n_s)));
		for(int x_s = 0; x_s < macroDef1129->length; x_s++){
			
			macroDef1129->arr[x_s] = one_cam_s;;
			stgVar950 = STG_OFFSET(stgVar950, VECTOR_ALL_BYTES(macroDef1129->arr[x_s]->length));
		}
	array_array_number_t cam_s = macroDef1129;
	vector_shape_t one_x_c = TOP_LEVEL_linalg_vectorRead_c(0, 0);
	card_t size1193 = width_vector_shape_t(one_x_c);
	array_number_t stgVar951 = storage_alloc(size1193);
	array_array_number_t macroDef1171;array_number_t one_x_s = TOP_LEVEL_linalg_vectorRead_s(stgVar951, fn_s, 2, 0, 0);
	env_t_1176 env_t_1176_value = make_env_t_1176(one_x_c); closure_t closure1133 = make_closure(lambda1176, &env_t_1176_value);
	matrix_shape_t x_c = nested_shape_vector_shape_t(closure1133.lam(closure1133.env, 0).vector_shape_t_value, m_c);
	card_t size1192 = width_matrix_shape_t(x_c);
	array_number_t stgVar954 = storage_alloc(size1192);
	array_array_number_t macroDef1170;array_array_number_t macroDef1134 = (array_array_number_t)stgVar954;
		macroDef1134->length=m_s;
		macroDef1134->arr=(array_number_t*)(STG_OFFSET(macroDef1134, VECTOR_HEADER_BYTES));
		storage_t stgVar955 = (STG_OFFSET(macroDef1134, MATRIX_HEADER_BYTES(m_s)));
		for(int x_s = 0; x_s < macroDef1134->length; x_s++){
			
			macroDef1134->arr[x_s] = one_x_s;;
			stgVar955 = STG_OFFSET(stgVar955, VECTOR_ALL_BYTES(macroDef1134->arr[x_s]->length));
		}
	array_array_number_t x_s = macroDef1134;
	card_t one_w_c = 0;
	card_t size1191 = one_w_c;
	array_number_t stgVar956 = storage_alloc(size1191);
	array_array_number_t macroDef1169;number_t one_w_s = TOP_LEVEL_linalg_numberRead_s(stgVar956, fn_s, 3, 0, 0);
	env_t_1177 env_t_1177_value = make_empty_env(); closure_t closure1137 = make_closure(lambda1177, &env_t_1177_value);
	vector_shape_t w_c = TOP_LEVEL_linalg_vectorMap_c(closure1137, TOP_LEVEL_linalg_vectorRange_c(oneCard_c, p_c));
	card_t size1190 = width_vector_shape_t(w_c);
	array_number_t stgVar959 = storage_alloc(size1190);
	array_array_number_t macroDef1168;card_t size1180 = width_vector_shape_t(TOP_LEVEL_linalg_vectorRange_c(oneCard_c, p_c));
	array_number_t stgVar961 = storage_alloc(size1180);
	array_number_t macroDef1145;env_t_1178 env_t_1178_value = make_env_t_1178(one_w_s); closure_t closure1141 = make_closure(lambda1178, &env_t_1178_value);
	env_t_1179 env_t_1179_value = make_empty_env(); closure_t closure1144 = make_closure(lambda1179, &env_t_1179_value);
	macroDef1145 = TOP_LEVEL_linalg_vectorMap_s(stgVar959, closure1141, TOP_LEVEL_linalg_vectorRange_s(stgVar961, oneCard_s, p_s, oneCard_c, p_c), closure1144, TOP_LEVEL_linalg_vectorRange_c(oneCard_c, p_c));;
	storage_free(stgVar961, size1180);
	array_number_t w_s = macroDef1145;
	vector_shape_t one_feat_c = TOP_LEVEL_linalg_vectorRead_c(0, 0);
	card_t size1189 = width_vector_shape_t(one_feat_c);
	array_number_t stgVar965 = storage_alloc(size1189);
	array_array_number_t macroDef1167;array_number_t one_feat_s = TOP_LEVEL_linalg_vectorRead_s(stgVar965, fn_s, 4, 0, 0);
	env_t_1181 env_t_1181_value = make_env_t_1181(one_feat_c); closure_t closure1149 = make_closure(lambda1181, &env_t_1181_value);
	matrix_shape_t feat_c = TOP_LEVEL_linalg_vectorMapToMatrix_c(closure1149, TOP_LEVEL_linalg_vectorRange_c(oneCard_c, p_c));
	card_t size1188 = width_matrix_shape_t(feat_c);
	array_number_t stgVar968 = storage_alloc(size1188);
	array_array_number_t macroDef1166;card_t size1184 = width_vector_shape_t(TOP_LEVEL_linalg_vectorRange_c(oneCard_c, p_c));
	array_number_t stgVar970 = storage_alloc(size1184);
	array_array_number_t macroDef1158;env_t_1182 env_t_1182_value = make_env_t_1182(one_feat_s); closure_t closure1153 = make_closure(lambda1182, &env_t_1182_value);
	env_t_1183 env_t_1183_value = make_env_t_1183(one_feat_c); closure_t closure1157 = make_closure(lambda1183, &env_t_1183_value);
	macroDef1158 = TOP_LEVEL_linalg_vectorMapToMatrix_s(stgVar968, closure1153, TOP_LEVEL_linalg_vectorRange_s(stgVar970, oneCard_s, p_s, oneCard_c, p_c), closure1157, TOP_LEVEL_linalg_vectorRange_c(oneCard_c, p_c));;
	storage_free(stgVar970, size1184);
	array_array_number_t feat_s = macroDef1158;
	env_t_1185 env_t_1185_value = make_empty_env(); closure_t closure1161 = make_closure(lambda1185, &env_t_1185_value);
	matrix_shape_t obs_c = nested_shape_vector_shape_t(closure1161.lam(closure1161.env, 0).vector_shape_t_value, p_c);
	card_t size1187 = width_matrix_shape_t(obs_c);
	array_number_t stgVar974 = storage_alloc(size1187);
	array_array_number_t macroDef1165;array_array_number_t macroDef1163 = (array_array_number_t)stgVar974;
		macroDef1163->length=p_s;
		macroDef1163->arr=(array_number_t*)(STG_OFFSET(macroDef1163, VECTOR_HEADER_BYTES));
		storage_t stgVar975 = (STG_OFFSET(macroDef1163, MATRIX_HEADER_BYTES(p_s)));
		for(int x_s = 0; x_s < macroDef1163->length; x_s++){
			array_number_t macroDef1162 = (array_number_t)stgVar975;
	macroDef1162->length=2;
	macroDef1162->arr=(number_t*)(STG_OFFSET(stgVar975, VECTOR_HEADER_BYTES));
	macroDef1162->arr[0] = (double)(((int)(x_s)) % ((n_s)));
	macroDef1162->arr[1] = (double)(((int)(x_s)) % ((m_s)));;
			macroDef1163->arr[x_s] = macroDef1162;;
			stgVar975 = STG_OFFSET(stgVar975, VECTOR_ALL_BYTES(macroDef1163->arr[x_s]->length));
		}
	array_array_number_t obs_s = macroDef1163;
	card_t t_c = 0;
	timer_t t_s = tic();
	matrix_shape_t res_c = TOP_LEVEL_usecases_ba_reproj_err_c(cam_c, x_c, w_c, obs_c, feat_c);
	card_t size1186 = width_matrix_shape_t(res_c);
	array_number_t stgVar979 = storage_alloc(size1186);
	array_array_number_t macroDef1164;array_array_number_t res_s = TOP_LEVEL_usecases_ba_reproj_err_s(stgVar979, cam_s, x_s, w_s, obs_s, feat_s, cam_c, x_c, w_c, obs_c, feat_c);
	toc(t_s);
	macroDef1164 = res_s;;
	storage_free(stgVar979, size1186);
	macroDef1165 = macroDef1164;;
	storage_free(stgVar974, size1187);
	macroDef1166 = macroDef1165;;
	storage_free(stgVar968, size1188);
	macroDef1167 = macroDef1166;;
	storage_free(stgVar965, size1189);
	macroDef1168 = macroDef1167;;
	storage_free(stgVar959, size1190);
	macroDef1169 = macroDef1168;;
	storage_free(stgVar956, size1191);
	macroDef1170 = macroDef1169;;
	storage_free(stgVar954, size1192);
	macroDef1171 = macroDef1170;;
	storage_free(stgVar951, size1193);
	macroDef1172 = macroDef1171;;
	storage_free(stgVar949, size1194);
	macroDef1173 = macroDef1172;;
	storage_free(stgVar946, size1195);
	return macroDef1173;
}

card_t TOP_LEVEL_usecases_ba_test_ba_c(vector_shape_t dum_c) {
	
	return 0;
}


void TOP_LEVEL_usecases_ba_test_ba_s(storage_t stgVar1196, array_number_t dum_s, vector_shape_t dum_c) {
	vector_shape_t a_c = nested_shape_card_t(0, 3);
	card_t size1252 = width_vector_shape_t(a_c);
	array_number_t stgVar1197 = storage_alloc(size1252);
	array_number_t macroDef1230 = (array_number_t)stgVar1197;
	macroDef1230->length=3;
	macroDef1230->arr=(number_t*)(STG_OFFSET(stgVar1197, VECTOR_HEADER_BYTES));
	macroDef1230->arr[0] = 1;
	macroDef1230->arr[1] = 2;
	macroDef1230->arr[2] = 3;;
	array_number_t a_s = macroDef1230;
	vector_shape_t b_c = nested_shape_card_t(0, 3);
	card_t size1251 = width_vector_shape_t(b_c);
	array_number_t stgVar1201 = storage_alloc(size1251);
	array_number_t macroDef1231 = (array_number_t)stgVar1201;
	macroDef1231->length=3;
	macroDef1231->arr=(number_t*)(STG_OFFSET(stgVar1201, VECTOR_HEADER_BYTES));
	macroDef1231->arr[0] = 5;
	macroDef1231->arr[1] = 6;
	macroDef1231->arr[2] = 7;;
	array_number_t b_s = macroDef1231;
	array_print(a_s);
	array_print(b_s);
	vector_shape_t j_c = TOP_LEVEL_usecases_ba_radial_distort_c(a_c, b_c);
	card_t size1250 = width_vector_shape_t(j_c);
	array_number_t stgVar1205 = storage_alloc(size1250);
	array_number_t j_s = TOP_LEVEL_usecases_ba_radial_distort_s(stgVar1205, a_s, b_s, a_c, b_c);
	array_print(j_s);
	vector_shape_t k_c = TOP_LEVEL_usecases_ba_rodrigues_rotate_point_c(a_c, b_c);
	card_t size1249 = width_vector_shape_t(k_c);
	array_number_t stgVar1208 = storage_alloc(size1249);
	array_number_t k_s = TOP_LEVEL_usecases_ba_rodrigues_rotate_point_s(stgVar1208, a_s, b_s, a_c, b_c);
	array_print(k_s);
	vector_shape_t l_c = TOP_LEVEL_linalg_vectorSlice_c(2, 0, k_c);
	card_t size1248 = width_vector_shape_t(l_c);
	array_number_t stgVar1211 = storage_alloc(size1248);
	array_number_t l_s = TOP_LEVEL_linalg_vectorSlice_s(stgVar1211, 2, 1, k_s, 2, 0, k_c);
	array_print(l_s);
	vector_shape_t cam_c = nested_shape_card_t(0, 11);
	card_t size1247 = width_vector_shape_t(cam_c);
	array_number_t stgVar1215 = storage_alloc(size1247);
	array_number_t macroDef1232 = (array_number_t)stgVar1215;
	macroDef1232->length=11;
	macroDef1232->arr=(number_t*)(STG_OFFSET(stgVar1215, VECTOR_HEADER_BYTES));
	macroDef1232->arr[0] = 0;
	macroDef1232->arr[1] = 2;
	macroDef1232->arr[2] = 4;
	macroDef1232->arr[3] = 6;
	macroDef1232->arr[4] = 8;
	macroDef1232->arr[5] = 10;
	macroDef1232->arr[6] = 12;
	macroDef1232->arr[7] = 14;
	macroDef1232->arr[8] = 16;
	macroDef1232->arr[9] = 18;
	macroDef1232->arr[10] = 20;;
	array_number_t cam_s = macroDef1232;
	vector_shape_t m_c = TOP_LEVEL_usecases_ba_project_c(cam_c, j_c);
	card_t size1246 = width_vector_shape_t(m_c);
	array_number_t stgVar1227 = storage_alloc(size1246);
	array_number_t m_s = TOP_LEVEL_usecases_ba_project_s(stgVar1227, cam_s, j_s, cam_c, j_c);
	array_print(m_s);
	;
	storage_free(stgVar1227, size1246);
	;
	storage_free(stgVar1215, size1247);
	;
	storage_free(stgVar1211, size1248);
	;
	storage_free(stgVar1208, size1249);
	;
	storage_free(stgVar1205, size1250);
	;
	storage_free(stgVar1201, size1251);
	;
	storage_free(stgVar1197, size1252);
	return ;
}
#endif
