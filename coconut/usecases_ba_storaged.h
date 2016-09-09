#ifndef __USECASES_BA_STORAGED_H__ 
#define __USECASES_BA_STORAGED_H__ 
#include "runtime/fsharp.h"
#include <stdio.h>
#include <math.h>
#include "linalg_storaged.h"

vector_shape_t TOP_LEVEL_usecases_ba_radial_distort_c(vector_shape_t rad_params_c, vector_shape_t proj_c) {
	
	return TOP_LEVEL_linalg_mult_by_scalar_c(proj_c, 0);
}


array_number_t TOP_LEVEL_usecases_ba_radial_distort_s(storage_t stgVar576, array_number_t rad_params_s, array_number_t proj_s, vector_shape_t rad_params_c, vector_shape_t proj_c) {
	card_t rsq_c = 0;
	number_t rsq_s = TOP_LEVEL_linalg_sqnorm_s(empty_storage, proj_s, proj_c);
	card_t L_c = 0;
	number_t L_s = ((1) + ((rad_params_s->arr[0]) * (rsq_s))) + (((rad_params_s->arr[1]) * (rsq_s)) * (rsq_s));
	return TOP_LEVEL_linalg_mult_by_scalar_s(stgVar576, proj_s, L_s, proj_c, 0);
}

vector_shape_t TOP_LEVEL_usecases_ba_rodrigues_rotate_point_c(vector_shape_t rot_c, vector_shape_t x_c) {
	
	return TOP_LEVEL_linalg_add_vec_c(TOP_LEVEL_linalg_add_vec_c(TOP_LEVEL_linalg_mult_by_scalar_c(x_c, 0), TOP_LEVEL_linalg_mult_by_scalar_c(TOP_LEVEL_linalg_cross_c(TOP_LEVEL_linalg_mult_by_scalar_c(rot_c, 0), x_c), 0)), TOP_LEVEL_linalg_mult_by_scalar_c(TOP_LEVEL_linalg_mult_by_scalar_c(rot_c, 0), 0));
}


array_number_t TOP_LEVEL_usecases_ba_rodrigues_rotate_point_s(storage_t stgVar586, array_number_t rot_s, array_number_t x_s, vector_shape_t rot_c, vector_shape_t x_c) {
	card_t sqtheta_c = 0;
	number_t sqtheta_s = TOP_LEVEL_linalg_sqnorm_s(empty_storage, rot_s, rot_c);
	array_number_t ite715 = 0;
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
		card_t size721 = width_vector_shape_t(w_c);
	array_number_t stgVar593 = storage_alloc(size721);
	array_number_t macroDef713;array_number_t w_s = TOP_LEVEL_linalg_mult_by_scalar_s(stgVar593, rot_s, theta_inv_s, rot_c, 0);
	vector_shape_t w_cross_X_c = TOP_LEVEL_linalg_cross_c(w_c, x_c);
	card_t size720 = width_vector_shape_t(w_cross_X_c);
	array_number_t stgVar596 = storage_alloc(size720);
	array_number_t macroDef712;array_number_t w_cross_X_s = TOP_LEVEL_linalg_cross_s(stgVar596, w_s, x_s, w_c, x_c);
	card_t tmp_c = 0;
	number_t tmp_s = (TOP_LEVEL_linalg_dot_prod_s(empty_storage, w_s, x_s, w_c, x_c)) * ((1) - (costheta_s));
	vector_shape_t v1_c = TOP_LEVEL_linalg_mult_by_scalar_c(x_c, 0);
	card_t size719 = width_vector_shape_t(v1_c);
	array_number_t stgVar602 = storage_alloc(size719);
	array_number_t macroDef711;array_number_t v1_s = TOP_LEVEL_linalg_mult_by_scalar_s(stgVar602, x_s, costheta_s, x_c, 0);
	vector_shape_t v2_c = TOP_LEVEL_linalg_mult_by_scalar_c(w_cross_X_c, 0);
	card_t size718 = width_vector_shape_t(v2_c);
	array_number_t stgVar605 = storage_alloc(size718);
	array_number_t macroDef710;array_number_t v2_s = TOP_LEVEL_linalg_mult_by_scalar_s(stgVar605, w_cross_X_s, sintheta_s, w_cross_X_c, 0);
	card_t size717 = width_vector_shape_t(TOP_LEVEL_linalg_mult_by_scalar_c(w_c, 0));
	array_number_t stgVar609 = storage_alloc(size717);
	array_number_t macroDef709;card_t size716 = width_vector_shape_t(TOP_LEVEL_linalg_add_vec_c(v1_c, v2_c));
	array_number_t stgVar608 = storage_alloc(size716);
	array_number_t macroDef708;
	macroDef708 = TOP_LEVEL_linalg_add_vec_s(stgVar586, TOP_LEVEL_linalg_add_vec_s(stgVar608, v1_s, v2_s, v1_c, v2_c), TOP_LEVEL_linalg_mult_by_scalar_s(stgVar609, w_s, tmp_s, w_c, 0), TOP_LEVEL_linalg_add_vec_c(v1_c, v2_c), TOP_LEVEL_linalg_mult_by_scalar_c(w_c, 0));;
	storage_free(stgVar608, size716);
	macroDef709 = macroDef708;;
	storage_free(stgVar609, size717);
	macroDef710 = macroDef709;;
	storage_free(stgVar605, size718);
	macroDef711 = macroDef710;;
	storage_free(stgVar602, size719);
	macroDef712 = macroDef711;;
	storage_free(stgVar596, size720);
	macroDef713 = macroDef712;;
	storage_free(stgVar593, size721);
		ite715 = macroDef713;;
	} else {
		card_t size722 = width_vector_shape_t(TOP_LEVEL_linalg_cross_c(rot_c, x_c));
	array_number_t stgVar615 = storage_alloc(size722);
	array_number_t macroDef714;
	macroDef714 = TOP_LEVEL_linalg_add_vec_s(stgVar586, x_s, TOP_LEVEL_linalg_cross_s(stgVar615, rot_s, x_s, rot_c, x_c), x_c, TOP_LEVEL_linalg_cross_c(rot_c, x_c));;
	storage_free(stgVar615, size722);
		ite715 = macroDef714;;
	}
	return ite715;
}

vector_shape_t TOP_LEVEL_usecases_ba_project_c(vector_shape_t cam_c, vector_shape_t x_c) {
	
	return TOP_LEVEL_linalg_add_vec_c(TOP_LEVEL_linalg_vectorSlice_c(2, 0, cam_c), TOP_LEVEL_linalg_mult_by_scalar_c(TOP_LEVEL_usecases_ba_radial_distort_c(TOP_LEVEL_linalg_vectorSlice_c(2, 0, cam_c), TOP_LEVEL_linalg_mult_by_scalar_c(TOP_LEVEL_linalg_vectorSlice_c(2, 0, TOP_LEVEL_usecases_ba_rodrigues_rotate_point_c(TOP_LEVEL_linalg_vectorSlice_c(3, 0, cam_c), TOP_LEVEL_linalg_sub_vec_c(x_c, TOP_LEVEL_linalg_vectorSlice_c(3, 0, cam_c)))), 0)), 0));
}


array_number_t TOP_LEVEL_usecases_ba_project_s(storage_t stgVar723, array_number_t cam_s, array_number_t x_s, vector_shape_t cam_c, vector_shape_t x_c) {
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
	card_t size836 = width_vector_shape_t(Xcam_c);
	array_number_t stgVar730 = storage_alloc(size836);
	array_number_t macroDef826;card_t size829 = width_vector_shape_t(TOP_LEVEL_linalg_sub_vec_c(x_c, TOP_LEVEL_linalg_vectorSlice_c(3, 0, cam_c)));
	array_number_t stgVar732 = storage_alloc(size829);
	array_number_t macroDef819;card_t size828 = width_vector_shape_t(TOP_LEVEL_linalg_vectorSlice_c(3, 0, cam_c));
	array_number_t stgVar731 = storage_alloc(size828);
	array_number_t macroDef818;card_t size827 = width_vector_shape_t(TOP_LEVEL_linalg_vectorSlice_c(3, 0, cam_c));
	array_number_t stgVar737 = storage_alloc(size827);
	array_number_t macroDef817;
	macroDef817 = TOP_LEVEL_linalg_sub_vec_s(stgVar732, x_s, TOP_LEVEL_linalg_vectorSlice_s(stgVar737, 3, CENTER_IDX_s, cam_s, 3, 0, cam_c), x_c, TOP_LEVEL_linalg_vectorSlice_c(3, 0, cam_c));;
	storage_free(stgVar737, size827);
	macroDef818 = TOP_LEVEL_usecases_ba_rodrigues_rotate_point_s(stgVar730, TOP_LEVEL_linalg_vectorSlice_s(stgVar731, 3, ROT_IDX_s, cam_s, 3, 0, cam_c), macroDef817, TOP_LEVEL_linalg_vectorSlice_c(3, 0, cam_c), TOP_LEVEL_linalg_sub_vec_c(x_c, TOP_LEVEL_linalg_vectorSlice_c(3, 0, cam_c)));;
	storage_free(stgVar731, size828);
	macroDef819 = macroDef818;;
	storage_free(stgVar732, size829);
	array_number_t Xcam_s = macroDef819;
	vector_shape_t distorted_c = TOP_LEVEL_usecases_ba_radial_distort_c(TOP_LEVEL_linalg_vectorSlice_c(2, 0, cam_c), TOP_LEVEL_linalg_mult_by_scalar_c(TOP_LEVEL_linalg_vectorSlice_c(2, 0, Xcam_c), 0));
	card_t size835 = width_vector_shape_t(distorted_c);
	array_number_t stgVar741 = storage_alloc(size835);
	array_number_t macroDef825;card_t size832 = width_vector_shape_t(TOP_LEVEL_linalg_mult_by_scalar_c(TOP_LEVEL_linalg_vectorSlice_c(2, 0, Xcam_c), 0));
	array_number_t stgVar743 = storage_alloc(size832);
	array_number_t macroDef822;card_t size831 = width_vector_shape_t(TOP_LEVEL_linalg_vectorSlice_c(2, 0, cam_c));
	array_number_t stgVar742 = storage_alloc(size831);
	array_number_t macroDef821;card_t size830 = width_vector_shape_t(TOP_LEVEL_linalg_vectorSlice_c(2, 0, Xcam_c));
	array_number_t stgVar747 = storage_alloc(size830);
	array_number_t macroDef820;
	macroDef820 = TOP_LEVEL_linalg_mult_by_scalar_s(stgVar743, TOP_LEVEL_linalg_vectorSlice_s(stgVar747, 2, 0, Xcam_s, 2, 0, Xcam_c), (1) / (Xcam_s->arr[2]), TOP_LEVEL_linalg_vectorSlice_c(2, 0, Xcam_c), 0);;
	storage_free(stgVar747, size830);
	macroDef821 = TOP_LEVEL_usecases_ba_radial_distort_s(stgVar741, TOP_LEVEL_linalg_vectorSlice_s(stgVar742, 2, RAD_IDX_s, cam_s, 2, 0, cam_c), macroDef820, TOP_LEVEL_linalg_vectorSlice_c(2, 0, cam_c), TOP_LEVEL_linalg_mult_by_scalar_c(TOP_LEVEL_linalg_vectorSlice_c(2, 0, Xcam_c), 0));;
	storage_free(stgVar742, size831);
	macroDef822 = macroDef821;;
	storage_free(stgVar743, size832);
	array_number_t distorted_s = macroDef822;
	card_t size834 = width_vector_shape_t(TOP_LEVEL_linalg_mult_by_scalar_c(distorted_c, 0));
	array_number_t stgVar754 = storage_alloc(size834);
	array_number_t macroDef824;card_t size833 = width_vector_shape_t(TOP_LEVEL_linalg_vectorSlice_c(2, 0, cam_c));
	array_number_t stgVar753 = storage_alloc(size833);
	array_number_t macroDef823;
	macroDef823 = TOP_LEVEL_linalg_add_vec_s(stgVar723, TOP_LEVEL_linalg_vectorSlice_s(stgVar753, 2, X0_IDX_s, cam_s, 2, 0, cam_c), TOP_LEVEL_linalg_mult_by_scalar_s(stgVar754, distorted_s, cam_s->arr[FOCAL_IDX_s], distorted_c, 0), TOP_LEVEL_linalg_vectorSlice_c(2, 0, cam_c), TOP_LEVEL_linalg_mult_by_scalar_c(distorted_c, 0));;
	storage_free(stgVar753, size833);
	macroDef824 = macroDef823;;
	storage_free(stgVar754, size834);
	macroDef825 = macroDef824;;
	storage_free(stgVar741, size835);
	macroDef826 = macroDef825;;
	storage_free(stgVar730, size836);
	return macroDef826;
}

vector_shape_t TOP_LEVEL_usecases_ba_compute_reproj_err_c(vector_shape_t cam_c, vector_shape_t x_c, card_t w_c, vector_shape_t feat_c) {
	
	return TOP_LEVEL_linalg_mult_by_scalar_c(TOP_LEVEL_linalg_sub_vec_c(TOP_LEVEL_usecases_ba_project_c(cam_c, x_c), feat_c), 0);
}


array_number_t TOP_LEVEL_usecases_ba_compute_reproj_err_s(storage_t stgVar837, array_number_t cam_s, array_number_t x_s, number_t w_s, array_number_t feat_s, vector_shape_t cam_c, vector_shape_t x_c, card_t w_c, vector_shape_t feat_c) {
	card_t size847 = width_vector_shape_t(TOP_LEVEL_linalg_sub_vec_c(TOP_LEVEL_usecases_ba_project_c(cam_c, x_c), feat_c));
	array_number_t stgVar838 = storage_alloc(size847);
	array_number_t macroDef845;card_t size846 = width_vector_shape_t(TOP_LEVEL_usecases_ba_project_c(cam_c, x_c));
	array_number_t stgVar840 = storage_alloc(size846);
	array_number_t macroDef844;
	macroDef844 = TOP_LEVEL_linalg_sub_vec_s(stgVar838, TOP_LEVEL_usecases_ba_project_s(stgVar840, cam_s, x_s, cam_c, x_c), feat_s, TOP_LEVEL_usecases_ba_project_c(cam_c, x_c), feat_c);;
	storage_free(stgVar840, size846);
	macroDef845 = TOP_LEVEL_linalg_mult_by_scalar_s(stgVar837, macroDef844, w_s, TOP_LEVEL_linalg_sub_vec_c(TOP_LEVEL_usecases_ba_project_c(cam_c, x_c), feat_c), 0);;
	storage_free(stgVar838, size847);
	return macroDef845;
}

card_t TOP_LEVEL_usecases_ba_compute_zach_weight_error_c(card_t w_c) {
	
	return 0;
}


number_t TOP_LEVEL_usecases_ba_compute_zach_weight_error_s(storage_t stgVar848, number_t w_s, card_t w_c) {
	
	return (1) - ((w_s) * (w_s));
}
typedef empty_env_t env_t_857;


value_t lambda857(env_t_857* env854, card_t w_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
vector_shape_t TOP_LEVEL_usecases_ba_w_err_c(vector_shape_t w_c) {
	env_t_857 env_t_857_value = make_empty_env(); closure_t closure856 = make_closure(lambda857, &env_t_857_value);
	return TOP_LEVEL_linalg_vectorMap_c(closure856, w_c);
}

typedef empty_env_t env_t_864;


value_t lambda864(env_t_864* env858, storage_t stgVar852, number_t w_s, card_t w_c) {
	
	value_t res;
	res.number_t_value = TOP_LEVEL_usecases_ba_compute_zach_weight_error_s(stgVar852, w_s, 0);
	return res;
}
typedef empty_env_t env_t_865;


value_t lambda865(env_t_865* env861, card_t w_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
array_number_t TOP_LEVEL_usecases_ba_w_err_s(storage_t stgVar849, array_number_t w_s, vector_shape_t w_c) {
	env_t_864 env_t_864_value = make_empty_env(); closure_t closure860 = make_closure(lambda864, &env_t_864_value);
	env_t_865 env_t_865_value = make_empty_env(); closure_t closure863 = make_closure(lambda865, &env_t_865_value);
	return TOP_LEVEL_linalg_vectorMap_s(stgVar849, closure860, w_s, closure863, w_c);
}
typedef struct env_t_901 {
	matrix_shape_t x_c;
	matrix_shape_t feat_c;
	matrix_shape_t cams_c;
} env_t_901;
env_t_901 make_env_t_901(matrix_shape_t x_c,matrix_shape_t feat_c,matrix_shape_t cams_c) {
	env_t_901 env;
	env.x_c = x_c;
	env.feat_c = feat_c;
	env.cams_c = cams_c;
	return env;
}

value_t lambda901(env_t_901* env898, card_t i_c) {
	matrix_shape_t x_c897 = env898->x_c;
	matrix_shape_t feat_c896 = env898->feat_c;
	matrix_shape_t cams_c895 = env898->cams_c;
	value_t res;
	res.vector_shape_t_value = TOP_LEVEL_usecases_ba_compute_reproj_err_c(cams_c895.elem, x_c897.elem, 0, feat_c896.elem);
	return res;
}
matrix_shape_t TOP_LEVEL_usecases_ba_reproj_err_c(matrix_shape_t cams_c, matrix_shape_t x_c, vector_shape_t w_c, matrix_shape_t obs_c, matrix_shape_t feat_c) {
	env_t_901 env_t_901_value = make_env_t_901(x_c,feat_c,cams_c); closure_t closure900 = make_closure(lambda901, &env_t_901_value);
	return TOP_LEVEL_linalg_vectorMapToMatrix_c(closure900, TOP_LEVEL_linalg_vectorRange_c(0, (w_c.card) - (1)));
}

typedef struct env_t_928 {
	array_array_number_t x_s;
	matrix_shape_t x_c;
	array_number_t w_s;
	array_array_number_t obs_s;
	matrix_shape_t obs_c;
	array_array_number_t feat_s;
	matrix_shape_t feat_c;
	array_array_number_t cams_s;
	matrix_shape_t cams_c;
} env_t_928;
env_t_928 make_env_t_928(array_array_number_t x_s,matrix_shape_t x_c,array_number_t w_s,array_array_number_t obs_s,matrix_shape_t obs_c,array_array_number_t feat_s,matrix_shape_t feat_c,array_array_number_t cams_s,matrix_shape_t cams_c) {
	env_t_928 env;
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

value_t lambda928(env_t_928* env918, storage_t stgVar876, number_t i_s, card_t i_c) {
	array_array_number_t x_s917 = env918->x_s;
	matrix_shape_t x_c916 = env918->x_c;
	array_number_t w_s915 = env918->w_s;
	array_array_number_t obs_s914 = env918->obs_s;
	matrix_shape_t obs_c913 = env918->obs_c;
	array_array_number_t feat_s912 = env918->feat_s;
	matrix_shape_t feat_c911 = env918->feat_c;
	array_array_number_t cams_s910 = env918->cams_s;
	matrix_shape_t cams_c909 = env918->cams_c;
	card_t size933 = width_vector_shape_t(feat_c911.elem);
	array_number_t stgVar880 = storage_alloc(size933);
	array_number_t macroDef908;card_t size932 = width_vector_shape_t(x_c916.elem);
	array_number_t stgVar878 = storage_alloc(size932);
	array_number_t macroDef907;card_t size931 = width_vector_shape_t(cams_c909.elem);
	array_number_t stgVar877 = storage_alloc(size931);
	array_number_t macroDef906;card_t size929 = width_vector_shape_t(obs_c913.elem);
	array_number_t stgVar882 = storage_alloc(size929);
	number_t macroDef904;
	macroDef904 = obs_s914->arr[(int)(i_s)]->arr[0];;
	storage_free(stgVar882, size929);
	card_t size930 = width_vector_shape_t(obs_c913.elem);
	array_number_t stgVar885 = storage_alloc(size930);
	number_t macroDef905;
	macroDef905 = obs_s914->arr[(int)(i_s)]->arr[1];;
	storage_free(stgVar885, size930);
	macroDef906 = TOP_LEVEL_usecases_ba_compute_reproj_err_s(stgVar876, cams_s910->arr[(int)(macroDef904)], x_s917->arr[(int)(macroDef905)], w_s915->arr[(int)(i_s)], feat_s912->arr[(int)(i_s)], cams_c909.elem, x_c916.elem, 0, feat_c911.elem);;
	storage_free(stgVar877, size931);
	macroDef907 = macroDef906;;
	storage_free(stgVar878, size932);
	macroDef908 = macroDef907;;
	storage_free(stgVar880, size933);
	value_t res;
	res.array_number_t_value = macroDef908;
	return res;
}
typedef struct env_t_934 {
	matrix_shape_t x_c;
	matrix_shape_t feat_c;
	matrix_shape_t cams_c;
} env_t_934;
env_t_934 make_env_t_934(matrix_shape_t x_c,matrix_shape_t feat_c,matrix_shape_t cams_c) {
	env_t_934 env;
	env.x_c = x_c;
	env.feat_c = feat_c;
	env.cams_c = cams_c;
	return env;
}

value_t lambda934(env_t_934* env924, card_t i_c) {
	matrix_shape_t x_c923 = env924->x_c;
	matrix_shape_t feat_c922 = env924->feat_c;
	matrix_shape_t cams_c921 = env924->cams_c;
	value_t res;
	res.vector_shape_t_value = TOP_LEVEL_usecases_ba_compute_reproj_err_c(cams_c921.elem, x_c923.elem, 0, feat_c922.elem);
	return res;
}
array_array_number_t TOP_LEVEL_usecases_ba_reproj_err_s(storage_t stgVar866, array_array_number_t cams_s, array_array_number_t x_s, array_number_t w_s, array_array_number_t obs_s, array_array_number_t feat_s, matrix_shape_t cams_c, matrix_shape_t x_c, vector_shape_t w_c, matrix_shape_t obs_c, matrix_shape_t feat_c) {
	card_t n_c = cams_c.card;
	card_t macroDef902 = cams_s->length;
	card_t n_s = macroDef902;
	card_t p_c = w_c.card;
	card_t macroDef903 = w_s->length;
	card_t p_s = macroDef903;
	vector_shape_t range_c = TOP_LEVEL_linalg_vectorRange_c(0, (p_c) - (1));
	card_t size935 = width_vector_shape_t(range_c);
	array_number_t stgVar871 = storage_alloc(size935);
	array_array_number_t macroDef927;array_number_t range_s = TOP_LEVEL_linalg_vectorRange_s(stgVar871, 0, (p_s) - (1), 0, (p_c) - (1));
	env_t_928 env_t_928_value = make_env_t_928(x_s,x_c,w_s,obs_s,obs_c,feat_s,feat_c,cams_s,cams_c); closure_t closure920 = make_closure(lambda928, &env_t_928_value);
	env_t_934 env_t_934_value = make_env_t_934(x_c,feat_c,cams_c); closure_t closure926 = make_closure(lambda934, &env_t_934_value);
	macroDef927 = TOP_LEVEL_linalg_vectorMapToMatrix_s(stgVar866, closure920, range_s, closure926, range_c);;
	storage_free(stgVar871, size935);
	return macroDef927;
}
typedef empty_env_t env_t_1115;


value_t lambda1115(env_t_1115* env1109, card_t x_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef empty_env_t env_t_1116;


value_t lambda1116(env_t_1116* env1112, card_t x_c) {
	
	value_t res;
	res.vector_shape_t_value = TOP_LEVEL_linalg_vectorRead_c(0, 0);
	return res;
}
matrix_shape_t TOP_LEVEL_usecases_ba_run_ba_from_file_c(card_t fn_c, card_t n_c, card_t m_c, card_t p_c) {
	env_t_1115 env_t_1115_value = make_empty_env(); closure_t closure1111 = make_closure(lambda1115, &env_t_1115_value);
	env_t_1116 env_t_1116_value = make_empty_env(); closure_t closure1114 = make_closure(lambda1116, &env_t_1116_value);
	return TOP_LEVEL_usecases_ba_reproj_err_c(nested_shape_vector_shape_t(TOP_LEVEL_linalg_vectorRead_c(0, 0), n_c), nested_shape_vector_shape_t(TOP_LEVEL_linalg_vectorRead_c(0, 0), m_c), TOP_LEVEL_linalg_vectorMap_c(closure1111, TOP_LEVEL_linalg_vectorRange_c(1, p_c)), nested_shape_vector_shape_t(nested_shape_card_t(0, 2), p_c), TOP_LEVEL_linalg_vectorMapToMatrix_c(closure1114, TOP_LEVEL_linalg_vectorRange_c(1, p_c)));
}

typedef struct env_t_1166 {
	vector_shape_t one_cam_c;
} env_t_1166;
env_t_1166 make_env_t_1166(vector_shape_t one_cam_c) {
	env_t_1166 env;
	env.one_cam_c = one_cam_c;
	return env;
}

value_t lambda1166(env_t_1166* env1118, card_t x_c) {
	vector_shape_t one_cam_c1117 = env1118->one_cam_c;
	value_t res;
	res.vector_shape_t_value = one_cam_c1117;
	return res;
}
typedef struct env_t_1167 {
	vector_shape_t one_x_c;
} env_t_1167;
env_t_1167 make_env_t_1167(vector_shape_t one_x_c) {
	env_t_1167 env;
	env.one_x_c = one_x_c;
	return env;
}

value_t lambda1167(env_t_1167* env1123, card_t x_c) {
	vector_shape_t one_x_c1122 = env1123->one_x_c;
	value_t res;
	res.vector_shape_t_value = one_x_c1122;
	return res;
}
typedef empty_env_t env_t_1168;


value_t lambda1168(env_t_1168* env1127, card_t x_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef struct env_t_1169 {
	number_t one_w_s;
} env_t_1169;
env_t_1169 make_env_t_1169(number_t one_w_s) {
	env_t_1169 env;
	env.one_w_s = one_w_s;
	return env;
}

value_t lambda1169(env_t_1169* env1131, storage_t stgVar954, number_t x_s, card_t x_c) {
	number_t one_w_s1130 = env1131->one_w_s;
	value_t res;
	res.number_t_value = one_w_s1130;
	return res;
}
typedef empty_env_t env_t_1170;


value_t lambda1170(env_t_1170* env1134, card_t x_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef struct env_t_1172 {
	vector_shape_t one_feat_c;
} env_t_1172;
env_t_1172 make_env_t_1172(vector_shape_t one_feat_c) {
	env_t_1172 env;
	env.one_feat_c = one_feat_c;
	return env;
}

value_t lambda1172(env_t_1172* env1139, card_t x_c) {
	vector_shape_t one_feat_c1138 = env1139->one_feat_c;
	value_t res;
	res.vector_shape_t_value = one_feat_c1138;
	return res;
}
typedef struct env_t_1173 {
	array_number_t one_feat_s;
} env_t_1173;
env_t_1173 make_env_t_1173(array_number_t one_feat_s) {
	env_t_1173 env;
	env.one_feat_s = one_feat_s;
	return env;
}

value_t lambda1173(env_t_1173* env1143, storage_t stgVar963, number_t x_s, card_t x_c) {
	array_number_t one_feat_s1142 = env1143->one_feat_s;
	value_t res;
	res.array_number_t_value = one_feat_s1142;
	return res;
}
typedef struct env_t_1174 {
	vector_shape_t one_feat_c;
} env_t_1174;
env_t_1174 make_env_t_1174(vector_shape_t one_feat_c) {
	env_t_1174 env;
	env.one_feat_c = one_feat_c;
	return env;
}

value_t lambda1174(env_t_1174* env1147, card_t x_c) {
	vector_shape_t one_feat_c1146 = env1147->one_feat_c;
	value_t res;
	res.vector_shape_t_value = one_feat_c1146;
	return res;
}
typedef empty_env_t env_t_1176;


value_t lambda1176(env_t_1176* env1151, card_t x_c) {
	
	value_t res;
	res.vector_shape_t_value = nested_shape_card_t(0, 2);
	return res;
}
array_array_number_t TOP_LEVEL_usecases_ba_run_ba_from_file_s(storage_t stgVar936, string_t fn_s, card_t n_s, card_t m_s, card_t p_s, card_t fn_c, card_t n_c, card_t m_c, card_t p_c) {
	card_t oneCard_c = 1;
	card_t oneCard_s = 1;
	vector_shape_t one_cam_c = TOP_LEVEL_linalg_vectorRead_c(0, 0);
	card_t size1185 = width_vector_shape_t(one_cam_c);
	array_number_t stgVar938 = storage_alloc(size1185);
	array_array_number_t macroDef1164;array_number_t one_cam_s = TOP_LEVEL_linalg_vectorRead_s(stgVar938, fn_s, 1, 0, 0);
	env_t_1166 env_t_1166_value = make_env_t_1166(one_cam_c); closure_t closure1120 = make_closure(lambda1166, &env_t_1166_value);
	matrix_shape_t cam_c = nested_shape_vector_shape_t(closure1120.lam(closure1120.env, 0).vector_shape_t_value, n_c);
	card_t size1184 = width_matrix_shape_t(cam_c);
	array_number_t stgVar941 = storage_alloc(size1184);
	array_array_number_t macroDef1163;array_array_number_t macroDef1121 = (array_array_number_t)stgVar941;
		macroDef1121->length=n_s;
		macroDef1121->arr=(array_number_t*)(STG_OFFSET(macroDef1121, VECTOR_HEADER_BYTES));
		storage_t stgVar942 = (STG_OFFSET(macroDef1121, MATRIX_HEADER_BYTES(n_s)));
		for(int x_s = 0; x_s < macroDef1121->length; x_s++){
			
			macroDef1121->arr[x_s] = one_cam_s;;
			stgVar942 = STG_OFFSET(stgVar942, VECTOR_ALL_BYTES(macroDef1121->arr[x_s]->length));
		}
	array_array_number_t cam_s = macroDef1121;
	vector_shape_t one_x_c = TOP_LEVEL_linalg_vectorRead_c(0, 0);
	card_t size1183 = width_vector_shape_t(one_x_c);
	array_number_t stgVar943 = storage_alloc(size1183);
	array_array_number_t macroDef1162;array_number_t one_x_s = TOP_LEVEL_linalg_vectorRead_s(stgVar943, fn_s, 2, 0, 0);
	env_t_1167 env_t_1167_value = make_env_t_1167(one_x_c); closure_t closure1125 = make_closure(lambda1167, &env_t_1167_value);
	matrix_shape_t x_c = nested_shape_vector_shape_t(closure1125.lam(closure1125.env, 0).vector_shape_t_value, m_c);
	card_t size1182 = width_matrix_shape_t(x_c);
	array_number_t stgVar946 = storage_alloc(size1182);
	array_array_number_t macroDef1161;array_array_number_t macroDef1126 = (array_array_number_t)stgVar946;
		macroDef1126->length=m_s;
		macroDef1126->arr=(array_number_t*)(STG_OFFSET(macroDef1126, VECTOR_HEADER_BYTES));
		storage_t stgVar947 = (STG_OFFSET(macroDef1126, MATRIX_HEADER_BYTES(m_s)));
		for(int x_s = 0; x_s < macroDef1126->length; x_s++){
			
			macroDef1126->arr[x_s] = one_x_s;;
			stgVar947 = STG_OFFSET(stgVar947, VECTOR_ALL_BYTES(macroDef1126->arr[x_s]->length));
		}
	array_array_number_t x_s = macroDef1126;
	card_t one_w_c = 0;
	number_t one_w_s = TOP_LEVEL_linalg_numberRead_s(empty_storage, fn_s, 3, 0, 0);
	env_t_1168 env_t_1168_value = make_empty_env(); closure_t closure1129 = make_closure(lambda1168, &env_t_1168_value);
	vector_shape_t w_c = TOP_LEVEL_linalg_vectorMap_c(closure1129, TOP_LEVEL_linalg_vectorRange_c(oneCard_c, p_c));
	card_t size1181 = width_vector_shape_t(w_c);
	array_number_t stgVar951 = storage_alloc(size1181);
	array_array_number_t macroDef1160;card_t size1171 = width_vector_shape_t(TOP_LEVEL_linalg_vectorRange_c(oneCard_c, p_c));
	array_number_t stgVar953 = storage_alloc(size1171);
	array_number_t macroDef1137;env_t_1169 env_t_1169_value = make_env_t_1169(one_w_s); closure_t closure1133 = make_closure(lambda1169, &env_t_1169_value);
	env_t_1170 env_t_1170_value = make_empty_env(); closure_t closure1136 = make_closure(lambda1170, &env_t_1170_value);
	macroDef1137 = TOP_LEVEL_linalg_vectorMap_s(stgVar951, closure1133, TOP_LEVEL_linalg_vectorRange_s(stgVar953, oneCard_s, p_s, oneCard_c, p_c), closure1136, TOP_LEVEL_linalg_vectorRange_c(oneCard_c, p_c));;
	storage_free(stgVar953, size1171);
	array_number_t w_s = macroDef1137;
	vector_shape_t one_feat_c = TOP_LEVEL_linalg_vectorRead_c(0, 0);
	card_t size1180 = width_vector_shape_t(one_feat_c);
	array_number_t stgVar957 = storage_alloc(size1180);
	array_array_number_t macroDef1159;array_number_t one_feat_s = TOP_LEVEL_linalg_vectorRead_s(stgVar957, fn_s, 4, 0, 0);
	env_t_1172 env_t_1172_value = make_env_t_1172(one_feat_c); closure_t closure1141 = make_closure(lambda1172, &env_t_1172_value);
	matrix_shape_t feat_c = TOP_LEVEL_linalg_vectorMapToMatrix_c(closure1141, TOP_LEVEL_linalg_vectorRange_c(oneCard_c, p_c));
	card_t size1179 = width_matrix_shape_t(feat_c);
	array_number_t stgVar960 = storage_alloc(size1179);
	array_array_number_t macroDef1158;card_t size1175 = width_vector_shape_t(TOP_LEVEL_linalg_vectorRange_c(oneCard_c, p_c));
	array_number_t stgVar962 = storage_alloc(size1175);
	array_array_number_t macroDef1150;env_t_1173 env_t_1173_value = make_env_t_1173(one_feat_s); closure_t closure1145 = make_closure(lambda1173, &env_t_1173_value);
	env_t_1174 env_t_1174_value = make_env_t_1174(one_feat_c); closure_t closure1149 = make_closure(lambda1174, &env_t_1174_value);
	macroDef1150 = TOP_LEVEL_linalg_vectorMapToMatrix_s(stgVar960, closure1145, TOP_LEVEL_linalg_vectorRange_s(stgVar962, oneCard_s, p_s, oneCard_c, p_c), closure1149, TOP_LEVEL_linalg_vectorRange_c(oneCard_c, p_c));;
	storage_free(stgVar962, size1175);
	array_array_number_t feat_s = macroDef1150;
	env_t_1176 env_t_1176_value = make_empty_env(); closure_t closure1153 = make_closure(lambda1176, &env_t_1176_value);
	matrix_shape_t obs_c = nested_shape_vector_shape_t(closure1153.lam(closure1153.env, 0).vector_shape_t_value, p_c);
	card_t size1178 = width_matrix_shape_t(obs_c);
	array_number_t stgVar966 = storage_alloc(size1178);
	array_array_number_t macroDef1157;array_array_number_t macroDef1155 = (array_array_number_t)stgVar966;
		macroDef1155->length=p_s;
		macroDef1155->arr=(array_number_t*)(STG_OFFSET(macroDef1155, VECTOR_HEADER_BYTES));
		storage_t stgVar967 = (STG_OFFSET(macroDef1155, MATRIX_HEADER_BYTES(p_s)));
		for(int x_s = 0; x_s < macroDef1155->length; x_s++){
			array_number_t macroDef1154 = (array_number_t)stgVar967;
	macroDef1154->length=2;
	macroDef1154->arr=(number_t*)(STG_OFFSET(stgVar967, VECTOR_HEADER_BYTES));
	macroDef1154->arr[0] = (double)(((int)(x_s)) % ((n_s)));
	macroDef1154->arr[1] = (double)(((int)(x_s)) % ((m_s)));;
			macroDef1155->arr[x_s] = macroDef1154;;
			stgVar967 = STG_OFFSET(stgVar967, VECTOR_ALL_BYTES(macroDef1155->arr[x_s]->length));
		}
	array_array_number_t obs_s = macroDef1155;
	card_t t_c = 0;
	timer_t t_s = tic();
	matrix_shape_t res_c = TOP_LEVEL_usecases_ba_reproj_err_c(cam_c, x_c, w_c, obs_c, feat_c);
	card_t size1177 = width_matrix_shape_t(res_c);
	array_number_t stgVar971 = storage_alloc(size1177);
	array_array_number_t macroDef1156;array_array_number_t res_s = TOP_LEVEL_usecases_ba_reproj_err_s(stgVar971, cam_s, x_s, w_s, obs_s, feat_s, cam_c, x_c, w_c, obs_c, feat_c);
	toc(t_s);
	macroDef1156 = res_s;;
	storage_free(stgVar971, size1177);
	macroDef1157 = macroDef1156;;
	storage_free(stgVar966, size1178);
	macroDef1158 = macroDef1157;;
	storage_free(stgVar960, size1179);
	macroDef1159 = macroDef1158;;
	storage_free(stgVar957, size1180);
	macroDef1160 = macroDef1159;;
	storage_free(stgVar951, size1181);
	macroDef1161 = macroDef1160;;
	storage_free(stgVar946, size1182);
	macroDef1162 = macroDef1161;;
	storage_free(stgVar943, size1183);
	macroDef1163 = macroDef1162;;
	storage_free(stgVar941, size1184);
	macroDef1164 = macroDef1163;;
	storage_free(stgVar938, size1185);
	return macroDef1164;
}

card_t TOP_LEVEL_usecases_ba_test_ba_c(vector_shape_t dum_c) {
	
	return 0;
}


void TOP_LEVEL_usecases_ba_test_ba_s(storage_t stgVar1186, array_number_t dum_s, vector_shape_t dum_c) {
	vector_shape_t a_c = nested_shape_card_t(0, 3);
	card_t size1242 = width_vector_shape_t(a_c);
	array_number_t stgVar1187 = storage_alloc(size1242);
	array_number_t macroDef1220 = (array_number_t)stgVar1187;
	macroDef1220->length=3;
	macroDef1220->arr=(number_t*)(STG_OFFSET(stgVar1187, VECTOR_HEADER_BYTES));
	macroDef1220->arr[0] = 1;
	macroDef1220->arr[1] = 2;
	macroDef1220->arr[2] = 3;;
	array_number_t a_s = macroDef1220;
	vector_shape_t b_c = nested_shape_card_t(0, 3);
	card_t size1241 = width_vector_shape_t(b_c);
	array_number_t stgVar1191 = storage_alloc(size1241);
	array_number_t macroDef1221 = (array_number_t)stgVar1191;
	macroDef1221->length=3;
	macroDef1221->arr=(number_t*)(STG_OFFSET(stgVar1191, VECTOR_HEADER_BYTES));
	macroDef1221->arr[0] = 5;
	macroDef1221->arr[1] = 6;
	macroDef1221->arr[2] = 7;;
	array_number_t b_s = macroDef1221;
	array_print(a_s);
	array_print(b_s);
	vector_shape_t j_c = TOP_LEVEL_usecases_ba_radial_distort_c(a_c, b_c);
	card_t size1240 = width_vector_shape_t(j_c);
	array_number_t stgVar1195 = storage_alloc(size1240);
	array_number_t j_s = TOP_LEVEL_usecases_ba_radial_distort_s(stgVar1195, a_s, b_s, a_c, b_c);
	array_print(j_s);
	vector_shape_t k_c = TOP_LEVEL_usecases_ba_rodrigues_rotate_point_c(a_c, b_c);
	card_t size1239 = width_vector_shape_t(k_c);
	array_number_t stgVar1198 = storage_alloc(size1239);
	array_number_t k_s = TOP_LEVEL_usecases_ba_rodrigues_rotate_point_s(stgVar1198, a_s, b_s, a_c, b_c);
	array_print(k_s);
	vector_shape_t l_c = TOP_LEVEL_linalg_vectorSlice_c(2, 0, k_c);
	card_t size1238 = width_vector_shape_t(l_c);
	array_number_t stgVar1201 = storage_alloc(size1238);
	array_number_t l_s = TOP_LEVEL_linalg_vectorSlice_s(stgVar1201, 2, 1, k_s, 2, 0, k_c);
	array_print(l_s);
	vector_shape_t cam_c = nested_shape_card_t(0, 11);
	card_t size1237 = width_vector_shape_t(cam_c);
	array_number_t stgVar1205 = storage_alloc(size1237);
	array_number_t macroDef1222 = (array_number_t)stgVar1205;
	macroDef1222->length=11;
	macroDef1222->arr=(number_t*)(STG_OFFSET(stgVar1205, VECTOR_HEADER_BYTES));
	macroDef1222->arr[0] = 0;
	macroDef1222->arr[1] = 2;
	macroDef1222->arr[2] = 4;
	macroDef1222->arr[3] = 6;
	macroDef1222->arr[4] = 8;
	macroDef1222->arr[5] = 10;
	macroDef1222->arr[6] = 12;
	macroDef1222->arr[7] = 14;
	macroDef1222->arr[8] = 16;
	macroDef1222->arr[9] = 18;
	macroDef1222->arr[10] = 20;;
	array_number_t cam_s = macroDef1222;
	vector_shape_t m_c = TOP_LEVEL_usecases_ba_project_c(cam_c, j_c);
	card_t size1236 = width_vector_shape_t(m_c);
	array_number_t stgVar1217 = storage_alloc(size1236);
	array_number_t m_s = TOP_LEVEL_usecases_ba_project_s(stgVar1217, cam_s, j_s, cam_c, j_c);
	array_print(m_s);
	;
	storage_free(stgVar1217, size1236);
	;
	storage_free(stgVar1205, size1237);
	;
	storage_free(stgVar1201, size1238);
	;
	storage_free(stgVar1198, size1239);
	;
	storage_free(stgVar1195, size1240);
	;
	storage_free(stgVar1191, size1241);
	;
	storage_free(stgVar1187, size1242);
	return ;
}
#endif
