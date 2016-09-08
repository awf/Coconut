#ifndef __USECASES_BA_STORAGED_H__ 
#define __USECASES_BA_STORAGED_H__ 
#include "runtime/fsharp.h"
#include <stdio.h>
#include <math.h>
#include "linalg_storaged.h"

vector_shape_t TOP_LEVEL_usecases_ba_radial_distort_c(vector_shape_t rad_params_c, vector_shape_t proj_c) {
	card_t rsq_c = 0;
	card_t L_c = 0;
	return TOP_LEVEL_linalg_mult_by_scalar_c(proj_c, 0);
}


array_number_t TOP_LEVEL_usecases_ba_radial_distort_s(storage_t stgVar635, array_number_t rad_params_s, array_number_t proj_s, vector_shape_t rad_params_c, vector_shape_t proj_c) {
	card_t rsq_c = 0;
	card_t size644 = rsq_c;
	array_number_t stgVar636 = storage_alloc(size644);
	array_number_t macroDef643;number_t rsq_s = TOP_LEVEL_linalg_sqnorm_s(stgVar636, proj_s, proj_c);
	card_t L_c = 0;
	number_t L_s = ((1) + ((rad_params_s->arr[0]) * (rsq_s))) + (((rad_params_s->arr[1]) * (rsq_s)) * (rsq_s));
	macroDef643 = TOP_LEVEL_linalg_mult_by_scalar_s(stgVar635, proj_s, L_s, proj_c, 0);;
	storage_free(stgVar636, size644);
	return macroDef643;
}

vector_shape_t TOP_LEVEL_usecases_ba_rodrigues_rotate_point_c(vector_shape_t rot_c, vector_shape_t x_c) {
	card_t sqtheta_c = 0;
	card_t theta_c = 0;
	card_t costheta_c = 0;
	card_t sintheta_c = 0;
	card_t theta_inv_c = 0;
	vector_shape_t w_c = TOP_LEVEL_linalg_mult_by_scalar_c(rot_c, 0);
	vector_shape_t w_cross_X_c = TOP_LEVEL_linalg_cross_c(w_c, x_c);
	card_t tmp_c = 0;
	vector_shape_t v1_c = TOP_LEVEL_linalg_mult_by_scalar_c(x_c, 0);
	vector_shape_t v2_c = TOP_LEVEL_linalg_mult_by_scalar_c(w_cross_X_c, 0);
	return TOP_LEVEL_linalg_add_vec_c(TOP_LEVEL_linalg_add_vec_c(v1_c, v2_c), TOP_LEVEL_linalg_mult_by_scalar_c(w_c, 0));
}


array_number_t TOP_LEVEL_usecases_ba_rodrigues_rotate_point_s(storage_t stgVar645, array_number_t rot_s, array_number_t x_s, vector_shape_t rot_c, vector_shape_t x_c) {
	card_t sqtheta_c = 0;
	card_t size693 = sqtheta_c;
	array_number_t stgVar646 = storage_alloc(size693);
	array_number_t macroDef684;number_t sqtheta_s = TOP_LEVEL_linalg_sqnorm_s(stgVar646, rot_s, rot_c);
	array_number_t ite685 = 0;
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
		card_t size691 = width_vector_shape_t(w_c);
	array_number_t stgVar652 = storage_alloc(size691);
	array_number_t macroDef682;array_number_t w_s = TOP_LEVEL_linalg_mult_by_scalar_s(stgVar652, rot_s, theta_inv_s, rot_c, 0);
	vector_shape_t w_cross_X_c = TOP_LEVEL_linalg_cross_c(w_c, x_c);
	card_t size690 = width_vector_shape_t(w_cross_X_c);
	array_number_t stgVar655 = storage_alloc(size690);
	array_number_t macroDef681;array_number_t w_cross_X_s = TOP_LEVEL_linalg_cross_s(stgVar655, w_s, x_s, w_c, x_c);
	card_t tmp_c = 0;
	number_t tmp_s = (TOP_LEVEL_linalg_dot_prod_s(empty_storage, w_s, x_s, w_c, x_c)) * ((1) - (costheta_s));
	vector_shape_t v1_c = TOP_LEVEL_linalg_mult_by_scalar_c(x_c, 0);
	card_t size689 = width_vector_shape_t(v1_c);
	array_number_t stgVar661 = storage_alloc(size689);
	array_number_t macroDef680;array_number_t v1_s = TOP_LEVEL_linalg_mult_by_scalar_s(stgVar661, x_s, costheta_s, x_c, 0);
	vector_shape_t v2_c = TOP_LEVEL_linalg_mult_by_scalar_c(w_cross_X_c, 0);
	card_t size688 = width_vector_shape_t(v2_c);
	array_number_t stgVar664 = storage_alloc(size688);
	array_number_t macroDef679;array_number_t v2_s = TOP_LEVEL_linalg_mult_by_scalar_s(stgVar664, w_cross_X_s, sintheta_s, w_cross_X_c, 0);
	card_t size687 = width_vector_shape_t(TOP_LEVEL_linalg_mult_by_scalar_c(w_c, 0));
	array_number_t stgVar668 = storage_alloc(size687);
	array_number_t macroDef678;card_t size686 = width_vector_shape_t(TOP_LEVEL_linalg_add_vec_c(v1_c, v2_c));
	array_number_t stgVar667 = storage_alloc(size686);
	array_number_t macroDef677;
	macroDef677 = TOP_LEVEL_linalg_add_vec_s(stgVar645, TOP_LEVEL_linalg_add_vec_s(stgVar667, v1_s, v2_s, v1_c, v2_c), TOP_LEVEL_linalg_mult_by_scalar_s(stgVar668, w_s, tmp_s, w_c, 0), TOP_LEVEL_linalg_add_vec_c(v1_c, v2_c), TOP_LEVEL_linalg_mult_by_scalar_c(w_c, 0));;
	storage_free(stgVar667, size686);
	macroDef678 = macroDef677;;
	storage_free(stgVar668, size687);
	macroDef679 = macroDef678;;
	storage_free(stgVar664, size688);
	macroDef680 = macroDef679;;
	storage_free(stgVar661, size689);
	macroDef681 = macroDef680;;
	storage_free(stgVar655, size690);
	macroDef682 = macroDef681;;
	storage_free(stgVar652, size691);
		ite685 = macroDef682;;
	} else {
		card_t size692 = width_vector_shape_t(TOP_LEVEL_linalg_cross_c(rot_c, x_c));
	array_number_t stgVar674 = storage_alloc(size692);
	array_number_t macroDef683;
	macroDef683 = TOP_LEVEL_linalg_add_vec_s(stgVar645, x_s, TOP_LEVEL_linalg_cross_s(stgVar674, rot_s, x_s, rot_c, x_c), x_c, TOP_LEVEL_linalg_cross_c(rot_c, x_c));;
	storage_free(stgVar674, size692);
		ite685 = macroDef683;;
	}
	macroDef684 = ite685;;
	storage_free(stgVar646, size693);
	return macroDef684;
}

vector_shape_t TOP_LEVEL_usecases_ba_project_c(vector_shape_t cam_c, vector_shape_t x_c) {
	card_t N_CAM_PARAMS_c = 0;
	card_t ROT_IDX_c = 0;
	card_t CENTER_IDX_c = 0;
	card_t FOCAL_IDX_c = 0;
	card_t X0_IDX_c = 0;
	card_t RAD_IDX_c = 0;
	vector_shape_t Xcam_c = TOP_LEVEL_usecases_ba_rodrigues_rotate_point_c(TOP_LEVEL_linalg_vectorSlice_c(3, 0, cam_c), TOP_LEVEL_linalg_sub_vec_c(x_c, TOP_LEVEL_linalg_vectorSlice_c(3, 0, cam_c)));
	vector_shape_t distorted_c = TOP_LEVEL_usecases_ba_radial_distort_c(TOP_LEVEL_linalg_vectorSlice_c(2, 0, cam_c), TOP_LEVEL_linalg_mult_by_scalar_c(TOP_LEVEL_linalg_vectorSlice_c(2, 0, Xcam_c), 0));
	return TOP_LEVEL_linalg_add_vec_c(TOP_LEVEL_linalg_vectorSlice_c(2, 0, cam_c), TOP_LEVEL_linalg_mult_by_scalar_c(distorted_c, 0));
}


array_number_t TOP_LEVEL_usecases_ba_project_s(storage_t stgVar694, array_number_t cam_s, array_number_t x_s, vector_shape_t cam_c, vector_shape_t x_c) {
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
	card_t size751 = width_vector_shape_t(Xcam_c);
	array_number_t stgVar701 = storage_alloc(size751);
	array_number_t macroDef741;card_t size744 = width_vector_shape_t(TOP_LEVEL_linalg_sub_vec_c(x_c, TOP_LEVEL_linalg_vectorSlice_c(3, 0, cam_c)));
	array_number_t stgVar703 = storage_alloc(size744);
	array_number_t macroDef734;card_t size743 = width_vector_shape_t(TOP_LEVEL_linalg_vectorSlice_c(3, 0, cam_c));
	array_number_t stgVar702 = storage_alloc(size743);
	array_number_t macroDef733;card_t size742 = width_vector_shape_t(TOP_LEVEL_linalg_vectorSlice_c(3, 0, cam_c));
	array_number_t stgVar708 = storage_alloc(size742);
	array_number_t macroDef732;
	macroDef732 = TOP_LEVEL_linalg_sub_vec_s(stgVar703, x_s, TOP_LEVEL_linalg_vectorSlice_s(stgVar708, 3, CENTER_IDX_s, cam_s, 3, 0, cam_c), x_c, TOP_LEVEL_linalg_vectorSlice_c(3, 0, cam_c));;
	storage_free(stgVar708, size742);
	macroDef733 = TOP_LEVEL_usecases_ba_rodrigues_rotate_point_s(stgVar701, TOP_LEVEL_linalg_vectorSlice_s(stgVar702, 3, ROT_IDX_s, cam_s, 3, 0, cam_c), macroDef732, TOP_LEVEL_linalg_vectorSlice_c(3, 0, cam_c), TOP_LEVEL_linalg_sub_vec_c(x_c, TOP_LEVEL_linalg_vectorSlice_c(3, 0, cam_c)));;
	storage_free(stgVar702, size743);
	macroDef734 = macroDef733;;
	storage_free(stgVar703, size744);
	array_number_t Xcam_s = macroDef734;
	vector_shape_t distorted_c = TOP_LEVEL_usecases_ba_radial_distort_c(TOP_LEVEL_linalg_vectorSlice_c(2, 0, cam_c), TOP_LEVEL_linalg_mult_by_scalar_c(TOP_LEVEL_linalg_vectorSlice_c(2, 0, Xcam_c), 0));
	card_t size750 = width_vector_shape_t(distorted_c);
	array_number_t stgVar712 = storage_alloc(size750);
	array_number_t macroDef740;card_t size747 = width_vector_shape_t(TOP_LEVEL_linalg_mult_by_scalar_c(TOP_LEVEL_linalg_vectorSlice_c(2, 0, Xcam_c), 0));
	array_number_t stgVar714 = storage_alloc(size747);
	array_number_t macroDef737;card_t size746 = width_vector_shape_t(TOP_LEVEL_linalg_vectorSlice_c(2, 0, cam_c));
	array_number_t stgVar713 = storage_alloc(size746);
	array_number_t macroDef736;card_t size745 = width_vector_shape_t(TOP_LEVEL_linalg_vectorSlice_c(2, 0, Xcam_c));
	array_number_t stgVar718 = storage_alloc(size745);
	array_number_t macroDef735;
	macroDef735 = TOP_LEVEL_linalg_mult_by_scalar_s(stgVar714, TOP_LEVEL_linalg_vectorSlice_s(stgVar718, 2, 0, Xcam_s, 2, 0, Xcam_c), (1) / (Xcam_s->arr[2]), TOP_LEVEL_linalg_vectorSlice_c(2, 0, Xcam_c), 0);;
	storage_free(stgVar718, size745);
	macroDef736 = TOP_LEVEL_usecases_ba_radial_distort_s(stgVar712, TOP_LEVEL_linalg_vectorSlice_s(stgVar713, 2, RAD_IDX_s, cam_s, 2, 0, cam_c), macroDef735, TOP_LEVEL_linalg_vectorSlice_c(2, 0, cam_c), TOP_LEVEL_linalg_mult_by_scalar_c(TOP_LEVEL_linalg_vectorSlice_c(2, 0, Xcam_c), 0));;
	storage_free(stgVar713, size746);
	macroDef737 = macroDef736;;
	storage_free(stgVar714, size747);
	array_number_t distorted_s = macroDef737;
	card_t size749 = width_vector_shape_t(TOP_LEVEL_linalg_mult_by_scalar_c(distorted_c, 0));
	array_number_t stgVar725 = storage_alloc(size749);
	array_number_t macroDef739;card_t size748 = width_vector_shape_t(TOP_LEVEL_linalg_vectorSlice_c(2, 0, cam_c));
	array_number_t stgVar724 = storage_alloc(size748);
	array_number_t macroDef738;
	macroDef738 = TOP_LEVEL_linalg_add_vec_s(stgVar694, TOP_LEVEL_linalg_vectorSlice_s(stgVar724, 2, X0_IDX_s, cam_s, 2, 0, cam_c), TOP_LEVEL_linalg_mult_by_scalar_s(stgVar725, distorted_s, cam_s->arr[FOCAL_IDX_s], distorted_c, 0), TOP_LEVEL_linalg_vectorSlice_c(2, 0, cam_c), TOP_LEVEL_linalg_mult_by_scalar_c(distorted_c, 0));;
	storage_free(stgVar724, size748);
	macroDef739 = macroDef738;;
	storage_free(stgVar725, size749);
	macroDef740 = macroDef739;;
	storage_free(stgVar712, size750);
	macroDef741 = macroDef740;;
	storage_free(stgVar701, size751);
	return macroDef741;
}

vector_shape_t TOP_LEVEL_usecases_ba_compute_reproj_err_c(vector_shape_t cam_c, vector_shape_t x_c, card_t w_c, vector_shape_t feat_c) {
	
	return TOP_LEVEL_linalg_mult_by_scalar_c(TOP_LEVEL_linalg_sub_vec_c(TOP_LEVEL_usecases_ba_project_c(cam_c, x_c), feat_c), 0);
}


array_number_t TOP_LEVEL_usecases_ba_compute_reproj_err_s(storage_t stgVar752, array_number_t cam_s, array_number_t x_s, number_t w_s, array_number_t feat_s, vector_shape_t cam_c, vector_shape_t x_c, card_t w_c, vector_shape_t feat_c) {
	card_t size762 = width_vector_shape_t(TOP_LEVEL_linalg_sub_vec_c(TOP_LEVEL_usecases_ba_project_c(cam_c, x_c), feat_c));
	array_number_t stgVar753 = storage_alloc(size762);
	array_number_t macroDef760;card_t size761 = width_vector_shape_t(TOP_LEVEL_usecases_ba_project_c(cam_c, x_c));
	array_number_t stgVar755 = storage_alloc(size761);
	array_number_t macroDef759;
	macroDef759 = TOP_LEVEL_linalg_sub_vec_s(stgVar753, TOP_LEVEL_usecases_ba_project_s(stgVar755, cam_s, x_s, cam_c, x_c), feat_s, TOP_LEVEL_usecases_ba_project_c(cam_c, x_c), feat_c);;
	storage_free(stgVar755, size761);
	macroDef760 = TOP_LEVEL_linalg_mult_by_scalar_s(stgVar752, macroDef759, w_s, TOP_LEVEL_linalg_sub_vec_c(TOP_LEVEL_usecases_ba_project_c(cam_c, x_c), feat_c), 0);;
	storage_free(stgVar753, size762);
	return macroDef760;
}

card_t TOP_LEVEL_usecases_ba_compute_zach_weight_error_c(card_t w_c) {
	
	return 0;
}


number_t TOP_LEVEL_usecases_ba_compute_zach_weight_error_s(storage_t stgVar763, number_t w_s, card_t w_c) {
	
	return (1) - ((w_s) * (w_s));
}
typedef empty_env_t env_t_772;


value_t lambda772(env_t_772* env769, card_t w_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
vector_shape_t TOP_LEVEL_usecases_ba_w_err_c(vector_shape_t w_c) {
	env_t_772 env_t_772_value = make_empty_env(); closure_t closure771 = make_closure(lambda772, &env_t_772_value);
	return TOP_LEVEL_linalg_vectorMap_c(closure771, w_c);
}

typedef empty_env_t env_t_779;


value_t lambda779(env_t_779* env773, storage_t stgVar767, number_t w_s, card_t w_c) {
	
	value_t res;
	res.number_t_value = TOP_LEVEL_usecases_ba_compute_zach_weight_error_s(stgVar767, w_s, 0);
	return res;
}
typedef empty_env_t env_t_780;


value_t lambda780(env_t_780* env776, card_t w_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
array_number_t TOP_LEVEL_usecases_ba_w_err_s(storage_t stgVar764, array_number_t w_s, vector_shape_t w_c) {
	env_t_779 env_t_779_value = make_empty_env(); closure_t closure775 = make_closure(lambda779, &env_t_779_value);
	env_t_780 env_t_780_value = make_empty_env(); closure_t closure778 = make_closure(lambda780, &env_t_780_value);
	return TOP_LEVEL_linalg_vectorMap_s(stgVar764, closure775, w_s, closure778, w_c);
}
typedef struct env_t_810 {
	matrix_shape_t x_c;
	matrix_shape_t feat_c;
	matrix_shape_t cams_c;
} env_t_810;
env_t_810 make_env_t_810(matrix_shape_t x_c,matrix_shape_t feat_c,matrix_shape_t cams_c) {
	env_t_810 env;
	env.x_c = x_c;
	env.feat_c = feat_c;
	env.cams_c = cams_c;
	return env;
}

value_t lambda810(env_t_810* env807, card_t i_c) {
	matrix_shape_t x_c806 = env807->x_c;
	matrix_shape_t feat_c805 = env807->feat_c;
	matrix_shape_t cams_c804 = env807->cams_c;
	value_t res;
	res.vector_shape_t_value = TOP_LEVEL_usecases_ba_compute_reproj_err_c(cams_c804.elem, x_c806.elem, 0, feat_c805.elem);
	return res;
}
matrix_shape_t TOP_LEVEL_usecases_ba_reproj_err_c(matrix_shape_t cams_c, matrix_shape_t x_c, vector_shape_t w_c, matrix_shape_t obs_c, matrix_shape_t feat_c) {
	card_t n_c = cams_c.card;
	card_t p_c = w_c.card;
	vector_shape_t range_c = TOP_LEVEL_linalg_vectorRange_c(0, (p_c) - (1));
	env_t_810 env_t_810_value = make_env_t_810(x_c,feat_c,cams_c); closure_t closure809 = make_closure(lambda810, &env_t_810_value);
	return TOP_LEVEL_linalg_vectorMapToMatrix_c(closure809, range_c);
}

typedef struct env_t_837 {
	array_array_number_t x_s;
	matrix_shape_t x_c;
	array_number_t w_s;
	array_array_number_t obs_s;
	matrix_shape_t obs_c;
	array_array_number_t feat_s;
	matrix_shape_t feat_c;
	array_array_number_t cams_s;
	matrix_shape_t cams_c;
} env_t_837;
env_t_837 make_env_t_837(array_array_number_t x_s,matrix_shape_t x_c,array_number_t w_s,array_array_number_t obs_s,matrix_shape_t obs_c,array_array_number_t feat_s,matrix_shape_t feat_c,array_array_number_t cams_s,matrix_shape_t cams_c) {
	env_t_837 env;
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

value_t lambda837(env_t_837* env827, storage_t stgVar791, number_t i_s, card_t i_c) {
	array_array_number_t x_s826 = env827->x_s;
	matrix_shape_t x_c825 = env827->x_c;
	array_number_t w_s824 = env827->w_s;
	array_array_number_t obs_s823 = env827->obs_s;
	matrix_shape_t obs_c822 = env827->obs_c;
	array_array_number_t feat_s821 = env827->feat_s;
	matrix_shape_t feat_c820 = env827->feat_c;
	array_array_number_t cams_s819 = env827->cams_s;
	matrix_shape_t cams_c818 = env827->cams_c;
	card_t size842 = width_vector_shape_t(feat_c820.elem);
	array_number_t stgVar795 = storage_alloc(size842);
	array_number_t macroDef817;card_t size841 = width_vector_shape_t(x_c825.elem);
	array_number_t stgVar793 = storage_alloc(size841);
	array_number_t macroDef816;card_t size840 = width_vector_shape_t(cams_c818.elem);
	array_number_t stgVar792 = storage_alloc(size840);
	array_number_t macroDef815;card_t size838 = width_vector_shape_t(obs_c822.elem);
	array_number_t stgVar797 = storage_alloc(size838);
	number_t macroDef813;
	macroDef813 = obs_s823->arr[(int)(i_s)]->arr[0];;
	storage_free(stgVar797, size838);
	card_t size839 = width_vector_shape_t(obs_c822.elem);
	array_number_t stgVar800 = storage_alloc(size839);
	number_t macroDef814;
	macroDef814 = obs_s823->arr[(int)(i_s)]->arr[1];;
	storage_free(stgVar800, size839);
	macroDef815 = TOP_LEVEL_usecases_ba_compute_reproj_err_s(stgVar791, cams_s819->arr[(int)(macroDef813)], x_s826->arr[(int)(macroDef814)], w_s824->arr[(int)(i_s)], feat_s821->arr[(int)(i_s)], cams_c818.elem, x_c825.elem, 0, feat_c820.elem);;
	storage_free(stgVar792, size840);
	macroDef816 = macroDef815;;
	storage_free(stgVar793, size841);
	macroDef817 = macroDef816;;
	storage_free(stgVar795, size842);
	value_t res;
	res.array_number_t_value = macroDef817;
	return res;
}
typedef struct env_t_843 {
	matrix_shape_t x_c;
	matrix_shape_t feat_c;
	matrix_shape_t cams_c;
} env_t_843;
env_t_843 make_env_t_843(matrix_shape_t x_c,matrix_shape_t feat_c,matrix_shape_t cams_c) {
	env_t_843 env;
	env.x_c = x_c;
	env.feat_c = feat_c;
	env.cams_c = cams_c;
	return env;
}

value_t lambda843(env_t_843* env833, card_t i_c) {
	matrix_shape_t x_c832 = env833->x_c;
	matrix_shape_t feat_c831 = env833->feat_c;
	matrix_shape_t cams_c830 = env833->cams_c;
	value_t res;
	res.vector_shape_t_value = TOP_LEVEL_usecases_ba_compute_reproj_err_c(cams_c830.elem, x_c832.elem, 0, feat_c831.elem);
	return res;
}
array_array_number_t TOP_LEVEL_usecases_ba_reproj_err_s(storage_t stgVar781, array_array_number_t cams_s, array_array_number_t x_s, array_number_t w_s, array_array_number_t obs_s, array_array_number_t feat_s, matrix_shape_t cams_c, matrix_shape_t x_c, vector_shape_t w_c, matrix_shape_t obs_c, matrix_shape_t feat_c) {
	card_t n_c = cams_c.card;
	card_t macroDef811 = cams_s->length;
	card_t n_s = macroDef811;
	card_t p_c = w_c.card;
	card_t macroDef812 = w_s->length;
	card_t p_s = macroDef812;
	vector_shape_t range_c = TOP_LEVEL_linalg_vectorRange_c(0, (p_c) - (1));
	card_t size844 = width_vector_shape_t(range_c);
	array_number_t stgVar786 = storage_alloc(size844);
	array_array_number_t macroDef836;array_number_t range_s = TOP_LEVEL_linalg_vectorRange_s(stgVar786, 0, (p_s) - (1), 0, (p_c) - (1));
	env_t_837 env_t_837_value = make_env_t_837(x_s,x_c,w_s,obs_s,obs_c,feat_s,feat_c,cams_s,cams_c); closure_t closure829 = make_closure(lambda837, &env_t_837_value);
	env_t_843 env_t_843_value = make_env_t_843(x_c,feat_c,cams_c); closure_t closure835 = make_closure(lambda843, &env_t_843_value);
	macroDef836 = TOP_LEVEL_linalg_vectorMapToMatrix_s(stgVar781, closure829, range_s, closure835, range_c);;
	storage_free(stgVar786, size844);
	return macroDef836;
}
typedef struct env_t_904 {
	vector_shape_t one_cam_c;
} env_t_904;
env_t_904 make_env_t_904(vector_shape_t one_cam_c) {
	env_t_904 env;
	env.one_cam_c = one_cam_c;
	return env;
}

value_t lambda904(env_t_904* env887, card_t x_c) {
	vector_shape_t one_cam_c886 = env887->one_cam_c;
	value_t res;
	res.vector_shape_t_value = one_cam_c886;
	return res;
}
typedef struct env_t_905 {
	vector_shape_t one_x_c;
} env_t_905;
env_t_905 make_env_t_905(vector_shape_t one_x_c) {
	env_t_905 env;
	env.one_x_c = one_x_c;
	return env;
}

value_t lambda905(env_t_905* env891, card_t x_c) {
	vector_shape_t one_x_c890 = env891->one_x_c;
	value_t res;
	res.vector_shape_t_value = one_x_c890;
	return res;
}
typedef empty_env_t env_t_906;


value_t lambda906(env_t_906* env894, card_t x_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef struct env_t_907 {
	vector_shape_t one_feat_c;
} env_t_907;
env_t_907 make_env_t_907(vector_shape_t one_feat_c) {
	env_t_907 env;
	env.one_feat_c = one_feat_c;
	return env;
}

value_t lambda907(env_t_907* env898, card_t x_c) {
	vector_shape_t one_feat_c897 = env898->one_feat_c;
	value_t res;
	res.vector_shape_t_value = one_feat_c897;
	return res;
}
typedef empty_env_t env_t_908;


value_t lambda908(env_t_908* env901, card_t x_c) {
	
	value_t res;
	res.vector_shape_t_value = nested_shape_card_t(0, 2);
	return res;
}
matrix_shape_t TOP_LEVEL_usecases_ba_run_ba_from_file_c(card_t fn_c, card_t n_c, card_t m_c, card_t p_c) {
	card_t oneCard_c = 1;
	vector_shape_t one_cam_c = TOP_LEVEL_linalg_vectorRead_c(0, 0);
	env_t_904 env_t_904_value = make_env_t_904(one_cam_c); closure_t closure889 = make_closure(lambda904, &env_t_904_value);
	matrix_shape_t cam_c = nested_shape_vector_shape_t(closure889.lam(closure889.env, 0).vector_shape_t_value, n_c);
	vector_shape_t one_x_c = TOP_LEVEL_linalg_vectorRead_c(0, 0);
	env_t_905 env_t_905_value = make_env_t_905(one_x_c); closure_t closure893 = make_closure(lambda905, &env_t_905_value);
	matrix_shape_t x_c = nested_shape_vector_shape_t(closure893.lam(closure893.env, 0).vector_shape_t_value, m_c);
	card_t one_w_c = 0;
	env_t_906 env_t_906_value = make_empty_env(); closure_t closure896 = make_closure(lambda906, &env_t_906_value);
	vector_shape_t w_c = TOP_LEVEL_linalg_vectorMap_c(closure896, TOP_LEVEL_linalg_vectorRange_c(oneCard_c, p_c));
	vector_shape_t one_feat_c = TOP_LEVEL_linalg_vectorRead_c(0, 0);
	env_t_907 env_t_907_value = make_env_t_907(one_feat_c); closure_t closure900 = make_closure(lambda907, &env_t_907_value);
	matrix_shape_t feat_c = TOP_LEVEL_linalg_vectorMapToMatrix_c(closure900, TOP_LEVEL_linalg_vectorRange_c(oneCard_c, p_c));
	env_t_908 env_t_908_value = make_empty_env(); closure_t closure903 = make_closure(lambda908, &env_t_908_value);
	matrix_shape_t obs_c = nested_shape_vector_shape_t(closure903.lam(closure903.env, 0).vector_shape_t_value, p_c);
	card_t t_c = 0;
	matrix_shape_t res_c = TOP_LEVEL_usecases_ba_reproj_err_c(cam_c, x_c, w_c, obs_c, feat_c);
	return res_c;
}

typedef struct env_t_959 {
	vector_shape_t one_cam_c;
} env_t_959;
env_t_959 make_env_t_959(vector_shape_t one_cam_c) {
	env_t_959 env;
	env.one_cam_c = one_cam_c;
	return env;
}

value_t lambda959(env_t_959* env910, card_t x_c) {
	vector_shape_t one_cam_c909 = env910->one_cam_c;
	value_t res;
	res.vector_shape_t_value = one_cam_c909;
	return res;
}
typedef struct env_t_960 {
	vector_shape_t one_x_c;
} env_t_960;
env_t_960 make_env_t_960(vector_shape_t one_x_c) {
	env_t_960 env;
	env.one_x_c = one_x_c;
	return env;
}

value_t lambda960(env_t_960* env915, card_t x_c) {
	vector_shape_t one_x_c914 = env915->one_x_c;
	value_t res;
	res.vector_shape_t_value = one_x_c914;
	return res;
}
typedef empty_env_t env_t_961;


value_t lambda961(env_t_961* env919, card_t x_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef struct env_t_962 {
	number_t one_w_s;
} env_t_962;
env_t_962 make_env_t_962(number_t one_w_s) {
	env_t_962 env;
	env.one_w_s = one_w_s;
	return env;
}

value_t lambda962(env_t_962* env923, storage_t stgVar863, number_t x_s, card_t x_c) {
	number_t one_w_s922 = env923->one_w_s;
	value_t res;
	res.number_t_value = one_w_s922;
	return res;
}
typedef empty_env_t env_t_963;


value_t lambda963(env_t_963* env926, card_t x_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef struct env_t_965 {
	vector_shape_t one_feat_c;
} env_t_965;
env_t_965 make_env_t_965(vector_shape_t one_feat_c) {
	env_t_965 env;
	env.one_feat_c = one_feat_c;
	return env;
}

value_t lambda965(env_t_965* env931, card_t x_c) {
	vector_shape_t one_feat_c930 = env931->one_feat_c;
	value_t res;
	res.vector_shape_t_value = one_feat_c930;
	return res;
}
typedef struct env_t_966 {
	array_number_t one_feat_s;
} env_t_966;
env_t_966 make_env_t_966(array_number_t one_feat_s) {
	env_t_966 env;
	env.one_feat_s = one_feat_s;
	return env;
}

value_t lambda966(env_t_966* env935, storage_t stgVar872, number_t x_s, card_t x_c) {
	array_number_t one_feat_s934 = env935->one_feat_s;
	value_t res;
	res.array_number_t_value = one_feat_s934;
	return res;
}
typedef struct env_t_967 {
	vector_shape_t one_feat_c;
} env_t_967;
env_t_967 make_env_t_967(vector_shape_t one_feat_c) {
	env_t_967 env;
	env.one_feat_c = one_feat_c;
	return env;
}

value_t lambda967(env_t_967* env939, card_t x_c) {
	vector_shape_t one_feat_c938 = env939->one_feat_c;
	value_t res;
	res.vector_shape_t_value = one_feat_c938;
	return res;
}
typedef empty_env_t env_t_969;


value_t lambda969(env_t_969* env943, card_t x_c) {
	
	value_t res;
	res.vector_shape_t_value = nested_shape_card_t(0, 2);
	return res;
}
array_array_number_t TOP_LEVEL_usecases_ba_run_ba_from_file_s(storage_t stgVar845, string_t fn_s, card_t n_s, card_t m_s, card_t p_s, card_t fn_c, card_t n_c, card_t m_c, card_t p_c) {
	card_t oneCard_c = 1;
	card_t oneCard_s = 1;
	vector_shape_t one_cam_c = TOP_LEVEL_linalg_vectorRead_c(0, 0);
	card_t size979 = width_vector_shape_t(one_cam_c);
	array_number_t stgVar847 = storage_alloc(size979);
	array_array_number_t macroDef957;array_number_t one_cam_s = TOP_LEVEL_linalg_vectorRead_s(stgVar847, fn_s, 1, 0, 0);
	env_t_959 env_t_959_value = make_env_t_959(one_cam_c); closure_t closure912 = make_closure(lambda959, &env_t_959_value);
	matrix_shape_t cam_c = nested_shape_vector_shape_t(closure912.lam(closure912.env, 0).vector_shape_t_value, n_c);
	card_t size978 = width_matrix_shape_t(cam_c);
	array_number_t stgVar850 = storage_alloc(size978);
	array_array_number_t macroDef956;array_array_number_t macroDef913 = (array_array_number_t)stgVar850;
		macroDef913->length=n_s;
		macroDef913->arr=(array_number_t*)(STG_OFFSET(macroDef913, VECTOR_HEADER_BYTES));
		storage_t stgVar851 = (STG_OFFSET(macroDef913, MATRIX_HEADER_BYTES(n_s)));
		for(int x_s = 0; x_s < macroDef913->length; x_s++){
			
			macroDef913->arr[x_s] = one_cam_s;;
			stgVar851 = STG_OFFSET(stgVar851, VECTOR_ALL_BYTES(macroDef913->arr[x_s]->length));
		}
	array_array_number_t cam_s = macroDef913;
	vector_shape_t one_x_c = TOP_LEVEL_linalg_vectorRead_c(0, 0);
	card_t size977 = width_vector_shape_t(one_x_c);
	array_number_t stgVar852 = storage_alloc(size977);
	array_array_number_t macroDef955;array_number_t one_x_s = TOP_LEVEL_linalg_vectorRead_s(stgVar852, fn_s, 2, 0, 0);
	env_t_960 env_t_960_value = make_env_t_960(one_x_c); closure_t closure917 = make_closure(lambda960, &env_t_960_value);
	matrix_shape_t x_c = nested_shape_vector_shape_t(closure917.lam(closure917.env, 0).vector_shape_t_value, m_c);
	card_t size976 = width_matrix_shape_t(x_c);
	array_number_t stgVar855 = storage_alloc(size976);
	array_array_number_t macroDef954;array_array_number_t macroDef918 = (array_array_number_t)stgVar855;
		macroDef918->length=m_s;
		macroDef918->arr=(array_number_t*)(STG_OFFSET(macroDef918, VECTOR_HEADER_BYTES));
		storage_t stgVar856 = (STG_OFFSET(macroDef918, MATRIX_HEADER_BYTES(m_s)));
		for(int x_s = 0; x_s < macroDef918->length; x_s++){
			
			macroDef918->arr[x_s] = one_x_s;;
			stgVar856 = STG_OFFSET(stgVar856, VECTOR_ALL_BYTES(macroDef918->arr[x_s]->length));
		}
	array_array_number_t x_s = macroDef918;
	card_t one_w_c = 0;
	card_t size975 = one_w_c;
	array_number_t stgVar857 = storage_alloc(size975);
	array_array_number_t macroDef953;number_t one_w_s = TOP_LEVEL_linalg_numberRead_s(stgVar857, fn_s, 3, 0, 0);
	env_t_961 env_t_961_value = make_empty_env(); closure_t closure921 = make_closure(lambda961, &env_t_961_value);
	vector_shape_t w_c = TOP_LEVEL_linalg_vectorMap_c(closure921, TOP_LEVEL_linalg_vectorRange_c(oneCard_c, p_c));
	card_t size974 = width_vector_shape_t(w_c);
	array_number_t stgVar860 = storage_alloc(size974);
	array_array_number_t macroDef952;card_t size964 = width_vector_shape_t(TOP_LEVEL_linalg_vectorRange_c(oneCard_c, p_c));
	array_number_t stgVar862 = storage_alloc(size964);
	array_number_t macroDef929;env_t_962 env_t_962_value = make_env_t_962(one_w_s); closure_t closure925 = make_closure(lambda962, &env_t_962_value);
	env_t_963 env_t_963_value = make_empty_env(); closure_t closure928 = make_closure(lambda963, &env_t_963_value);
	macroDef929 = TOP_LEVEL_linalg_vectorMap_s(stgVar860, closure925, TOP_LEVEL_linalg_vectorRange_s(stgVar862, oneCard_s, p_s, oneCard_c, p_c), closure928, TOP_LEVEL_linalg_vectorRange_c(oneCard_c, p_c));;
	storage_free(stgVar862, size964);
	array_number_t w_s = macroDef929;
	vector_shape_t one_feat_c = TOP_LEVEL_linalg_vectorRead_c(0, 0);
	card_t size973 = width_vector_shape_t(one_feat_c);
	array_number_t stgVar866 = storage_alloc(size973);
	array_array_number_t macroDef951;array_number_t one_feat_s = TOP_LEVEL_linalg_vectorRead_s(stgVar866, fn_s, 4, 0, 0);
	env_t_965 env_t_965_value = make_env_t_965(one_feat_c); closure_t closure933 = make_closure(lambda965, &env_t_965_value);
	matrix_shape_t feat_c = TOP_LEVEL_linalg_vectorMapToMatrix_c(closure933, TOP_LEVEL_linalg_vectorRange_c(oneCard_c, p_c));
	card_t size972 = width_matrix_shape_t(feat_c);
	array_number_t stgVar869 = storage_alloc(size972);
	array_array_number_t macroDef950;card_t size968 = width_vector_shape_t(TOP_LEVEL_linalg_vectorRange_c(oneCard_c, p_c));
	array_number_t stgVar871 = storage_alloc(size968);
	array_array_number_t macroDef942;env_t_966 env_t_966_value = make_env_t_966(one_feat_s); closure_t closure937 = make_closure(lambda966, &env_t_966_value);
	env_t_967 env_t_967_value = make_env_t_967(one_feat_c); closure_t closure941 = make_closure(lambda967, &env_t_967_value);
	macroDef942 = TOP_LEVEL_linalg_vectorMapToMatrix_s(stgVar869, closure937, TOP_LEVEL_linalg_vectorRange_s(stgVar871, oneCard_s, p_s, oneCard_c, p_c), closure941, TOP_LEVEL_linalg_vectorRange_c(oneCard_c, p_c));;
	storage_free(stgVar871, size968);
	array_array_number_t feat_s = macroDef942;
	env_t_969 env_t_969_value = make_empty_env(); closure_t closure945 = make_closure(lambda969, &env_t_969_value);
	matrix_shape_t obs_c = nested_shape_vector_shape_t(closure945.lam(closure945.env, 0).vector_shape_t_value, p_c);
	card_t size971 = width_matrix_shape_t(obs_c);
	array_number_t stgVar875 = storage_alloc(size971);
	array_array_number_t macroDef949;array_array_number_t macroDef947 = (array_array_number_t)stgVar875;
		macroDef947->length=p_s;
		macroDef947->arr=(array_number_t*)(STG_OFFSET(macroDef947, VECTOR_HEADER_BYTES));
		storage_t stgVar876 = (STG_OFFSET(macroDef947, MATRIX_HEADER_BYTES(p_s)));
		for(int x_s = 0; x_s < macroDef947->length; x_s++){
			array_number_t macroDef946 = (array_number_t)stgVar876;
	macroDef946->length=2;
	macroDef946->arr=(number_t*)(STG_OFFSET(stgVar876, VECTOR_HEADER_BYTES));
	macroDef946->arr[0] = (double)(((int)(x_s)) % ((n_s)));
	macroDef946->arr[1] = (double)(((int)(x_s)) % ((m_s)));;
			macroDef947->arr[x_s] = macroDef946;;
			stgVar876 = STG_OFFSET(stgVar876, VECTOR_ALL_BYTES(macroDef947->arr[x_s]->length));
		}
	array_array_number_t obs_s = macroDef947;
	card_t t_c = 0;
	timer_t t_s = tic();
	matrix_shape_t res_c = TOP_LEVEL_usecases_ba_reproj_err_c(cam_c, x_c, w_c, obs_c, feat_c);
	card_t size970 = width_matrix_shape_t(res_c);
	array_number_t stgVar880 = storage_alloc(size970);
	array_array_number_t macroDef948;array_array_number_t res_s = TOP_LEVEL_usecases_ba_reproj_err_s(stgVar880, cam_s, x_s, w_s, obs_s, feat_s, cam_c, x_c, w_c, obs_c, feat_c);
	toc(t_s);
	macroDef948 = res_s;;
	storage_free(stgVar880, size970);
	macroDef949 = macroDef948;;
	storage_free(stgVar875, size971);
	macroDef950 = macroDef949;;
	storage_free(stgVar869, size972);
	macroDef951 = macroDef950;;
	storage_free(stgVar866, size973);
	macroDef952 = macroDef951;;
	storage_free(stgVar860, size974);
	macroDef953 = macroDef952;;
	storage_free(stgVar857, size975);
	macroDef954 = macroDef953;;
	storage_free(stgVar855, size976);
	macroDef955 = macroDef954;;
	storage_free(stgVar852, size977);
	macroDef956 = macroDef955;;
	storage_free(stgVar850, size978);
	macroDef957 = macroDef956;;
	storage_free(stgVar847, size979);
	return macroDef957;
}

card_t TOP_LEVEL_usecases_ba_test_ba_c(vector_shape_t dum_c) {
	
	return 0;
}


void TOP_LEVEL_usecases_ba_test_ba_s(storage_t stgVar980, array_number_t dum_s, vector_shape_t dum_c) {
	vector_shape_t a_c = nested_shape_card_t(0, 3);
	card_t size1036 = width_vector_shape_t(a_c);
	array_number_t stgVar981 = storage_alloc(size1036);
	array_number_t macroDef1014 = (array_number_t)stgVar981;
	macroDef1014->length=3;
	macroDef1014->arr=(number_t*)(STG_OFFSET(stgVar981, VECTOR_HEADER_BYTES));
	macroDef1014->arr[0] = 1;
	macroDef1014->arr[1] = 2;
	macroDef1014->arr[2] = 3;;
	array_number_t a_s = macroDef1014;
	vector_shape_t b_c = nested_shape_card_t(0, 3);
	card_t size1035 = width_vector_shape_t(b_c);
	array_number_t stgVar985 = storage_alloc(size1035);
	array_number_t macroDef1015 = (array_number_t)stgVar985;
	macroDef1015->length=3;
	macroDef1015->arr=(number_t*)(STG_OFFSET(stgVar985, VECTOR_HEADER_BYTES));
	macroDef1015->arr[0] = 5;
	macroDef1015->arr[1] = 6;
	macroDef1015->arr[2] = 7;;
	array_number_t b_s = macroDef1015;
	array_print(a_s);
	array_print(b_s);
	vector_shape_t j_c = TOP_LEVEL_usecases_ba_radial_distort_c(a_c, b_c);
	card_t size1034 = width_vector_shape_t(j_c);
	array_number_t stgVar989 = storage_alloc(size1034);
	array_number_t j_s = TOP_LEVEL_usecases_ba_radial_distort_s(stgVar989, a_s, b_s, a_c, b_c);
	array_print(j_s);
	vector_shape_t k_c = TOP_LEVEL_usecases_ba_rodrigues_rotate_point_c(a_c, b_c);
	card_t size1033 = width_vector_shape_t(k_c);
	array_number_t stgVar992 = storage_alloc(size1033);
	array_number_t k_s = TOP_LEVEL_usecases_ba_rodrigues_rotate_point_s(stgVar992, a_s, b_s, a_c, b_c);
	array_print(k_s);
	vector_shape_t l_c = TOP_LEVEL_linalg_vectorSlice_c(2, 0, k_c);
	card_t size1032 = width_vector_shape_t(l_c);
	array_number_t stgVar995 = storage_alloc(size1032);
	array_number_t l_s = TOP_LEVEL_linalg_vectorSlice_s(stgVar995, 2, 1, k_s, 2, 0, k_c);
	array_print(l_s);
	vector_shape_t cam_c = nested_shape_card_t(0, 11);
	card_t size1031 = width_vector_shape_t(cam_c);
	array_number_t stgVar999 = storage_alloc(size1031);
	array_number_t macroDef1016 = (array_number_t)stgVar999;
	macroDef1016->length=11;
	macroDef1016->arr=(number_t*)(STG_OFFSET(stgVar999, VECTOR_HEADER_BYTES));
	macroDef1016->arr[0] = 0;
	macroDef1016->arr[1] = 2;
	macroDef1016->arr[2] = 4;
	macroDef1016->arr[3] = 6;
	macroDef1016->arr[4] = 8;
	macroDef1016->arr[5] = 10;
	macroDef1016->arr[6] = 12;
	macroDef1016->arr[7] = 14;
	macroDef1016->arr[8] = 16;
	macroDef1016->arr[9] = 18;
	macroDef1016->arr[10] = 20;;
	array_number_t cam_s = macroDef1016;
	vector_shape_t m_c = TOP_LEVEL_usecases_ba_project_c(cam_c, j_c);
	card_t size1030 = width_vector_shape_t(m_c);
	array_number_t stgVar1011 = storage_alloc(size1030);
	array_number_t m_s = TOP_LEVEL_usecases_ba_project_s(stgVar1011, cam_s, j_s, cam_c, j_c);
	array_print(m_s);
	;
	storage_free(stgVar1011, size1030);
	;
	storage_free(stgVar999, size1031);
	;
	storage_free(stgVar995, size1032);
	;
	storage_free(stgVar992, size1033);
	;
	storage_free(stgVar989, size1034);
	;
	storage_free(stgVar985, size1035);
	;
	storage_free(stgVar981, size1036);
	return ;
}
#endif
