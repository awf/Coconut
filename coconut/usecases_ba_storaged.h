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


array_number_t TOP_LEVEL_usecases_ba_radial_distort_s(storage_t stgVar595, array_number_t rad_params_s, array_number_t proj_s, vector_shape_t rad_params_c, vector_shape_t proj_c) {
	card_t rsq_c = 0;
	array_number_t stgVar596 = malloc(rsq_c);
	array_number_t macroDef603;number_t rsq_s = TOP_LEVEL_linalg_sqnorm_s(stgVar596, proj_s, proj_c);
	card_t L_c = 0;
	number_t L_s = ((1) + ((rad_params_s->arr[0]) * (rsq_s))) + (((rad_params_s->arr[1]) * (rsq_s)) * (rsq_s));
	macroDef603 = TOP_LEVEL_linalg_mult_by_scalar_s(stgVar595, proj_s, L_s, proj_c, 0);;
	free(stgVar596);
	return macroDef603;
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


array_number_t TOP_LEVEL_usecases_ba_rodrigues_rotate_point_s(storage_t stgVar604, array_number_t rot_s, array_number_t x_s, vector_shape_t rot_c, vector_shape_t x_c) {
	card_t sqtheta_c = 0;
	array_number_t stgVar605 = malloc(sqtheta_c);
	array_number_t macroDef643;number_t sqtheta_s = TOP_LEVEL_linalg_sqnorm_s(stgVar605, rot_s, rot_c);
	array_number_t ite644 = 0;
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
		array_number_t stgVar611 = malloc(width_vector_shape_t(w_c));
	array_number_t macroDef641;array_number_t w_s = TOP_LEVEL_linalg_mult_by_scalar_s(stgVar611, rot_s, theta_inv_s, rot_c, 0);
	vector_shape_t w_cross_X_c = TOP_LEVEL_linalg_cross_c(w_c, x_c);
	array_number_t stgVar614 = malloc(width_vector_shape_t(w_cross_X_c));
	array_number_t macroDef640;array_number_t w_cross_X_s = TOP_LEVEL_linalg_cross_s(stgVar614, w_s, x_s, w_c, x_c);
	card_t tmp_c = 0;
	number_t tmp_s = (TOP_LEVEL_linalg_dot_prod_s(empty_storage, w_s, x_s, w_c, x_c)) * ((1) - (costheta_s));
	vector_shape_t v1_c = TOP_LEVEL_linalg_mult_by_scalar_c(x_c, 0);
	array_number_t stgVar620 = malloc(width_vector_shape_t(v1_c));
	array_number_t macroDef639;array_number_t v1_s = TOP_LEVEL_linalg_mult_by_scalar_s(stgVar620, x_s, costheta_s, x_c, 0);
	vector_shape_t v2_c = TOP_LEVEL_linalg_mult_by_scalar_c(w_cross_X_c, 0);
	array_number_t stgVar623 = malloc(width_vector_shape_t(v2_c));
	array_number_t macroDef638;array_number_t v2_s = TOP_LEVEL_linalg_mult_by_scalar_s(stgVar623, w_cross_X_s, sintheta_s, w_cross_X_c, 0);
	array_number_t stgVar627 = malloc(width_vector_shape_t(TOP_LEVEL_linalg_mult_by_scalar_c(w_c, 0)));
	array_number_t macroDef637;array_number_t stgVar626 = malloc(width_vector_shape_t(TOP_LEVEL_linalg_add_vec_c(v1_c, v2_c)));
	array_number_t macroDef636;
	macroDef636 = TOP_LEVEL_linalg_add_vec_s(stgVar604, TOP_LEVEL_linalg_add_vec_s(stgVar626, v1_s, v2_s, v1_c, v2_c), TOP_LEVEL_linalg_mult_by_scalar_s(stgVar627, w_s, tmp_s, w_c, 0), TOP_LEVEL_linalg_add_vec_c(v1_c, v2_c), TOP_LEVEL_linalg_mult_by_scalar_c(w_c, 0));;
	free(stgVar626);
	macroDef637 = macroDef636;;
	free(stgVar627);
	macroDef638 = macroDef637;;
	free(stgVar623);
	macroDef639 = macroDef638;;
	free(stgVar620);
	macroDef640 = macroDef639;;
	free(stgVar614);
	macroDef641 = macroDef640;;
	free(stgVar611);
		ite644 = macroDef641;;
	} else {
		array_number_t stgVar633 = malloc(width_vector_shape_t(TOP_LEVEL_linalg_cross_c(rot_c, x_c)));
	array_number_t macroDef642;
	macroDef642 = TOP_LEVEL_linalg_add_vec_s(stgVar604, x_s, TOP_LEVEL_linalg_cross_s(stgVar633, rot_s, x_s, rot_c, x_c), x_c, TOP_LEVEL_linalg_cross_c(rot_c, x_c));;
	free(stgVar633);
		ite644 = macroDef642;;
	}
	macroDef643 = ite644;;
	free(stgVar605);
	return macroDef643;
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


array_number_t TOP_LEVEL_usecases_ba_project_s(storage_t stgVar645, array_number_t cam_s, array_number_t x_s, vector_shape_t cam_c, vector_shape_t x_c) {
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
	array_number_t stgVar652 = malloc(width_vector_shape_t(Xcam_c));
	array_number_t macroDef692;array_number_t stgVar654 = malloc(width_vector_shape_t(TOP_LEVEL_linalg_sub_vec_c(x_c, TOP_LEVEL_linalg_vectorSlice_c(3, 0, cam_c))));
	array_number_t macroDef685;array_number_t stgVar653 = malloc(width_vector_shape_t(TOP_LEVEL_linalg_vectorSlice_c(3, 0, cam_c)));
	array_number_t macroDef684;array_number_t stgVar659 = malloc(width_vector_shape_t(TOP_LEVEL_linalg_vectorSlice_c(3, 0, cam_c)));
	array_number_t macroDef683;
	macroDef683 = TOP_LEVEL_linalg_sub_vec_s(stgVar654, x_s, TOP_LEVEL_linalg_vectorSlice_s(stgVar659, 3, CENTER_IDX_s, cam_s, 3, 0, cam_c), x_c, TOP_LEVEL_linalg_vectorSlice_c(3, 0, cam_c));;
	free(stgVar659);
	macroDef684 = TOP_LEVEL_usecases_ba_rodrigues_rotate_point_s(stgVar652, TOP_LEVEL_linalg_vectorSlice_s(stgVar653, 3, ROT_IDX_s, cam_s, 3, 0, cam_c), macroDef683, TOP_LEVEL_linalg_vectorSlice_c(3, 0, cam_c), TOP_LEVEL_linalg_sub_vec_c(x_c, TOP_LEVEL_linalg_vectorSlice_c(3, 0, cam_c)));;
	free(stgVar653);
	macroDef685 = macroDef684;;
	free(stgVar654);
	array_number_t Xcam_s = macroDef685;
	vector_shape_t distorted_c = TOP_LEVEL_usecases_ba_radial_distort_c(TOP_LEVEL_linalg_vectorSlice_c(2, 0, cam_c), TOP_LEVEL_linalg_mult_by_scalar_c(TOP_LEVEL_linalg_vectorSlice_c(2, 0, Xcam_c), 0));
	array_number_t stgVar663 = malloc(width_vector_shape_t(distorted_c));
	array_number_t macroDef691;array_number_t stgVar665 = malloc(width_vector_shape_t(TOP_LEVEL_linalg_mult_by_scalar_c(TOP_LEVEL_linalg_vectorSlice_c(2, 0, Xcam_c), 0)));
	array_number_t macroDef688;array_number_t stgVar664 = malloc(width_vector_shape_t(TOP_LEVEL_linalg_vectorSlice_c(2, 0, cam_c)));
	array_number_t macroDef687;array_number_t stgVar669 = malloc(width_vector_shape_t(TOP_LEVEL_linalg_vectorSlice_c(2, 0, Xcam_c)));
	array_number_t macroDef686;
	macroDef686 = TOP_LEVEL_linalg_mult_by_scalar_s(stgVar665, TOP_LEVEL_linalg_vectorSlice_s(stgVar669, 2, 0, Xcam_s, 2, 0, Xcam_c), (1) / (Xcam_s->arr[2]), TOP_LEVEL_linalg_vectorSlice_c(2, 0, Xcam_c), 0);;
	free(stgVar669);
	macroDef687 = TOP_LEVEL_usecases_ba_radial_distort_s(stgVar663, TOP_LEVEL_linalg_vectorSlice_s(stgVar664, 2, RAD_IDX_s, cam_s, 2, 0, cam_c), macroDef686, TOP_LEVEL_linalg_vectorSlice_c(2, 0, cam_c), TOP_LEVEL_linalg_mult_by_scalar_c(TOP_LEVEL_linalg_vectorSlice_c(2, 0, Xcam_c), 0));;
	free(stgVar664);
	macroDef688 = macroDef687;;
	free(stgVar665);
	array_number_t distorted_s = macroDef688;
	array_number_t stgVar676 = malloc(width_vector_shape_t(TOP_LEVEL_linalg_mult_by_scalar_c(distorted_c, 0)));
	array_number_t macroDef690;array_number_t stgVar675 = malloc(width_vector_shape_t(TOP_LEVEL_linalg_vectorSlice_c(2, 0, cam_c)));
	array_number_t macroDef689;
	macroDef689 = TOP_LEVEL_linalg_add_vec_s(stgVar645, TOP_LEVEL_linalg_vectorSlice_s(stgVar675, 2, X0_IDX_s, cam_s, 2, 0, cam_c), TOP_LEVEL_linalg_mult_by_scalar_s(stgVar676, distorted_s, cam_s->arr[FOCAL_IDX_s], distorted_c, 0), TOP_LEVEL_linalg_vectorSlice_c(2, 0, cam_c), TOP_LEVEL_linalg_mult_by_scalar_c(distorted_c, 0));;
	free(stgVar675);
	macroDef690 = macroDef689;;
	free(stgVar676);
	macroDef691 = macroDef690;;
	free(stgVar663);
	macroDef692 = macroDef691;;
	free(stgVar652);
	return macroDef692;
}

vector_shape_t TOP_LEVEL_usecases_ba_compute_reproj_err_c(vector_shape_t cam_c, vector_shape_t x_c, card_t w_c, vector_shape_t feat_c) {
	
	return TOP_LEVEL_linalg_mult_by_scalar_c(TOP_LEVEL_linalg_sub_vec_c(TOP_LEVEL_usecases_ba_project_c(cam_c, x_c), feat_c), 0);
}


array_number_t TOP_LEVEL_usecases_ba_compute_reproj_err_s(storage_t stgVar693, array_number_t cam_s, array_number_t x_s, number_t w_s, array_number_t feat_s, vector_shape_t cam_c, vector_shape_t x_c, card_t w_c, vector_shape_t feat_c) {
	array_number_t stgVar694 = malloc(width_vector_shape_t(TOP_LEVEL_linalg_sub_vec_c(TOP_LEVEL_usecases_ba_project_c(cam_c, x_c), feat_c)));
	array_number_t macroDef701;array_number_t stgVar696 = malloc(width_vector_shape_t(TOP_LEVEL_usecases_ba_project_c(cam_c, x_c)));
	array_number_t macroDef700;
	macroDef700 = TOP_LEVEL_linalg_sub_vec_s(stgVar694, TOP_LEVEL_usecases_ba_project_s(stgVar696, cam_s, x_s, cam_c, x_c), feat_s, TOP_LEVEL_usecases_ba_project_c(cam_c, x_c), feat_c);;
	free(stgVar696);
	macroDef701 = TOP_LEVEL_linalg_mult_by_scalar_s(stgVar693, macroDef700, w_s, TOP_LEVEL_linalg_sub_vec_c(TOP_LEVEL_usecases_ba_project_c(cam_c, x_c), feat_c), 0);;
	free(stgVar694);
	return macroDef701;
}

card_t TOP_LEVEL_usecases_ba_compute_zach_weight_error_c(card_t w_c) {
	
	return 0;
}


number_t TOP_LEVEL_usecases_ba_compute_zach_weight_error_s(storage_t stgVar702, number_t w_s, card_t w_c) {
	
	return (1) - ((w_s) * (w_s));
}
typedef empty_env_t env_t_711;


value_t lambda711(env_t_711* env708, card_t w_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
vector_shape_t TOP_LEVEL_usecases_ba_w_err_c(vector_shape_t w_c) {
	env_t_711 env_t_711_value = make_empty_env(); closure_t closure710 = make_closure(lambda711, &env_t_711_value);
	return TOP_LEVEL_linalg_vectorMap_c(closure710, w_c);
}

typedef empty_env_t env_t_718;


value_t lambda718(env_t_718* env712, storage_t stgVar706, number_t w_s, card_t w_c) {
	
	value_t res;
	res.number_t_value = TOP_LEVEL_usecases_ba_compute_zach_weight_error_s(stgVar706, w_s, 0);
	return res;
}
typedef empty_env_t env_t_719;


value_t lambda719(env_t_719* env715, card_t w_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
array_number_t TOP_LEVEL_usecases_ba_w_err_s(storage_t stgVar703, array_number_t w_s, vector_shape_t w_c) {
	env_t_718 env_t_718_value = make_empty_env(); closure_t closure714 = make_closure(lambda718, &env_t_718_value);
	env_t_719 env_t_719_value = make_empty_env(); closure_t closure717 = make_closure(lambda719, &env_t_719_value);
	return TOP_LEVEL_linalg_vectorMap_s(stgVar703, closure714, w_s, closure717, w_c);
}
typedef struct env_t_749 {
	matrix_shape_t x_c;
	matrix_shape_t feat_c;
	matrix_shape_t cams_c;
} env_t_749;
env_t_749 make_env_t_749(matrix_shape_t x_c,matrix_shape_t feat_c,matrix_shape_t cams_c) {
	env_t_749 env;
	env.x_c = x_c;
	env.feat_c = feat_c;
	env.cams_c = cams_c;
	return env;
}

value_t lambda749(env_t_749* env746, card_t i_c) {
	matrix_shape_t x_c745 = env746->x_c;
	matrix_shape_t feat_c744 = env746->feat_c;
	matrix_shape_t cams_c743 = env746->cams_c;
	value_t res;
	res.vector_shape_t_value = TOP_LEVEL_usecases_ba_compute_reproj_err_c(cams_c743.elem, x_c745.elem, 0, feat_c744.elem);
	return res;
}
matrix_shape_t TOP_LEVEL_usecases_ba_reproj_err_c(matrix_shape_t cams_c, matrix_shape_t x_c, vector_shape_t w_c, matrix_shape_t obs_c, matrix_shape_t feat_c) {
	card_t n_c = cams_c.card;
	card_t p_c = w_c.card;
	vector_shape_t range_c = TOP_LEVEL_linalg_vectorRange_c(0, (p_c) - (1));
	env_t_749 env_t_749_value = make_env_t_749(x_c,feat_c,cams_c); closure_t closure748 = make_closure(lambda749, &env_t_749_value);
	return TOP_LEVEL_linalg_vectorMapToMatrix_c(closure748, range_c);
}

typedef struct env_t_776 {
	array_array_number_t x_s;
	matrix_shape_t x_c;
	array_number_t w_s;
	array_array_number_t obs_s;
	matrix_shape_t obs_c;
	array_array_number_t feat_s;
	matrix_shape_t feat_c;
	array_array_number_t cams_s;
	matrix_shape_t cams_c;
} env_t_776;
env_t_776 make_env_t_776(array_array_number_t x_s,matrix_shape_t x_c,array_number_t w_s,array_array_number_t obs_s,matrix_shape_t obs_c,array_array_number_t feat_s,matrix_shape_t feat_c,array_array_number_t cams_s,matrix_shape_t cams_c) {
	env_t_776 env;
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

value_t lambda776(env_t_776* env766, storage_t stgVar730, number_t i_s, card_t i_c) {
	array_array_number_t x_s765 = env766->x_s;
	matrix_shape_t x_c764 = env766->x_c;
	array_number_t w_s763 = env766->w_s;
	array_array_number_t obs_s762 = env766->obs_s;
	matrix_shape_t obs_c761 = env766->obs_c;
	array_array_number_t feat_s760 = env766->feat_s;
	matrix_shape_t feat_c759 = env766->feat_c;
	array_array_number_t cams_s758 = env766->cams_s;
	matrix_shape_t cams_c757 = env766->cams_c;
	array_number_t stgVar734 = malloc(width_vector_shape_t(feat_c759.elem));
	array_number_t macroDef756;array_number_t stgVar732 = malloc(width_vector_shape_t(x_c764.elem));
	array_number_t macroDef755;array_number_t stgVar731 = malloc(width_vector_shape_t(cams_c757.elem));
	array_number_t macroDef754;array_number_t stgVar736 = malloc(width_vector_shape_t(obs_c761.elem));
	number_t macroDef752;
	macroDef752 = obs_s762->arr[(int)(i_s)]->arr[0];;
	free(stgVar736);
	array_number_t stgVar739 = malloc(width_vector_shape_t(obs_c761.elem));
	number_t macroDef753;
	macroDef753 = obs_s762->arr[(int)(i_s)]->arr[1];;
	free(stgVar739);
	macroDef754 = TOP_LEVEL_usecases_ba_compute_reproj_err_s(stgVar730, cams_s758->arr[(int)(macroDef752)], x_s765->arr[(int)(macroDef753)], w_s763->arr[(int)(i_s)], feat_s760->arr[(int)(i_s)], cams_c757.elem, x_c764.elem, 0, feat_c759.elem);;
	free(stgVar731);
	macroDef755 = macroDef754;;
	free(stgVar732);
	macroDef756 = macroDef755;;
	free(stgVar734);
	value_t res;
	res.array_number_t_value = macroDef756;
	return res;
}
typedef struct env_t_777 {
	matrix_shape_t x_c;
	matrix_shape_t feat_c;
	matrix_shape_t cams_c;
} env_t_777;
env_t_777 make_env_t_777(matrix_shape_t x_c,matrix_shape_t feat_c,matrix_shape_t cams_c) {
	env_t_777 env;
	env.x_c = x_c;
	env.feat_c = feat_c;
	env.cams_c = cams_c;
	return env;
}

value_t lambda777(env_t_777* env772, card_t i_c) {
	matrix_shape_t x_c771 = env772->x_c;
	matrix_shape_t feat_c770 = env772->feat_c;
	matrix_shape_t cams_c769 = env772->cams_c;
	value_t res;
	res.vector_shape_t_value = TOP_LEVEL_usecases_ba_compute_reproj_err_c(cams_c769.elem, x_c771.elem, 0, feat_c770.elem);
	return res;
}
array_array_number_t TOP_LEVEL_usecases_ba_reproj_err_s(storage_t stgVar720, array_array_number_t cams_s, array_array_number_t x_s, array_number_t w_s, array_array_number_t obs_s, array_array_number_t feat_s, matrix_shape_t cams_c, matrix_shape_t x_c, vector_shape_t w_c, matrix_shape_t obs_c, matrix_shape_t feat_c) {
	card_t n_c = cams_c.card;
	card_t macroDef750 = cams_s->length;
	card_t n_s = macroDef750;
	card_t p_c = w_c.card;
	card_t macroDef751 = w_s->length;
	card_t p_s = macroDef751;
	vector_shape_t range_c = TOP_LEVEL_linalg_vectorRange_c(0, (p_c) - (1));
	array_number_t stgVar725 = malloc(width_vector_shape_t(range_c));
	array_array_number_t macroDef775;array_number_t range_s = TOP_LEVEL_linalg_vectorRange_s(stgVar725, 0, (p_s) - (1), 0, (p_c) - (1));
	env_t_776 env_t_776_value = make_env_t_776(x_s,x_c,w_s,obs_s,obs_c,feat_s,feat_c,cams_s,cams_c); closure_t closure768 = make_closure(lambda776, &env_t_776_value);
	env_t_777 env_t_777_value = make_env_t_777(x_c,feat_c,cams_c); closure_t closure774 = make_closure(lambda777, &env_t_777_value);
	macroDef775 = TOP_LEVEL_linalg_vectorMapToMatrix_s(stgVar720, closure768, range_s, closure774, range_c);;
	free(stgVar725);
	return macroDef775;
}
typedef struct env_t_837 {
	vector_shape_t one_cam_c;
} env_t_837;
env_t_837 make_env_t_837(vector_shape_t one_cam_c) {
	env_t_837 env;
	env.one_cam_c = one_cam_c;
	return env;
}

value_t lambda837(env_t_837* env820, card_t x_c) {
	vector_shape_t one_cam_c819 = env820->one_cam_c;
	value_t res;
	res.vector_shape_t_value = one_cam_c819;
	return res;
}
typedef struct env_t_838 {
	vector_shape_t one_x_c;
} env_t_838;
env_t_838 make_env_t_838(vector_shape_t one_x_c) {
	env_t_838 env;
	env.one_x_c = one_x_c;
	return env;
}

value_t lambda838(env_t_838* env824, card_t x_c) {
	vector_shape_t one_x_c823 = env824->one_x_c;
	value_t res;
	res.vector_shape_t_value = one_x_c823;
	return res;
}
typedef empty_env_t env_t_839;


value_t lambda839(env_t_839* env827, card_t x_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef struct env_t_840 {
	vector_shape_t one_feat_c;
} env_t_840;
env_t_840 make_env_t_840(vector_shape_t one_feat_c) {
	env_t_840 env;
	env.one_feat_c = one_feat_c;
	return env;
}

value_t lambda840(env_t_840* env831, card_t x_c) {
	vector_shape_t one_feat_c830 = env831->one_feat_c;
	value_t res;
	res.vector_shape_t_value = one_feat_c830;
	return res;
}
typedef empty_env_t env_t_841;


value_t lambda841(env_t_841* env834, card_t x_c) {
	
	value_t res;
	res.vector_shape_t_value = nested_shape_card_t(0, 2);
	return res;
}
matrix_shape_t TOP_LEVEL_usecases_ba_run_ba_from_file_c(card_t fn_c, card_t n_c, card_t m_c, card_t p_c) {
	card_t oneCard_c = 1;
	vector_shape_t one_cam_c = TOP_LEVEL_linalg_vectorRead_c(0, 0);
	env_t_837 env_t_837_value = make_env_t_837(one_cam_c); closure_t closure822 = make_closure(lambda837, &env_t_837_value);
	matrix_shape_t cam_c = nested_shape_vector_shape_t(closure822.lam(closure822.env, 0).vector_shape_t_value, n_c);
	vector_shape_t one_x_c = TOP_LEVEL_linalg_vectorRead_c(0, 0);
	env_t_838 env_t_838_value = make_env_t_838(one_x_c); closure_t closure826 = make_closure(lambda838, &env_t_838_value);
	matrix_shape_t x_c = nested_shape_vector_shape_t(closure826.lam(closure826.env, 0).vector_shape_t_value, m_c);
	card_t one_w_c = 0;
	env_t_839 env_t_839_value = make_empty_env(); closure_t closure829 = make_closure(lambda839, &env_t_839_value);
	vector_shape_t w_c = TOP_LEVEL_linalg_vectorMap_c(closure829, TOP_LEVEL_linalg_vectorRange_c(oneCard_c, p_c));
	vector_shape_t one_feat_c = TOP_LEVEL_linalg_vectorRead_c(0, 0);
	env_t_840 env_t_840_value = make_env_t_840(one_feat_c); closure_t closure833 = make_closure(lambda840, &env_t_840_value);
	matrix_shape_t feat_c = TOP_LEVEL_linalg_vectorMapToMatrix_c(closure833, TOP_LEVEL_linalg_vectorRange_c(oneCard_c, p_c));
	env_t_841 env_t_841_value = make_empty_env(); closure_t closure836 = make_closure(lambda841, &env_t_841_value);
	matrix_shape_t obs_c = nested_shape_vector_shape_t(closure836.lam(closure836.env, 0).vector_shape_t_value, p_c);
	card_t t_c = 0;
	matrix_shape_t res_c = TOP_LEVEL_usecases_ba_reproj_err_c(cam_c, x_c, w_c, obs_c, feat_c);
	return res_c;
}

typedef struct env_t_892 {
	vector_shape_t one_cam_c;
} env_t_892;
env_t_892 make_env_t_892(vector_shape_t one_cam_c) {
	env_t_892 env;
	env.one_cam_c = one_cam_c;
	return env;
}

value_t lambda892(env_t_892* env843, card_t x_c) {
	vector_shape_t one_cam_c842 = env843->one_cam_c;
	value_t res;
	res.vector_shape_t_value = one_cam_c842;
	return res;
}
typedef struct env_t_893 {
	vector_shape_t one_x_c;
} env_t_893;
env_t_893 make_env_t_893(vector_shape_t one_x_c) {
	env_t_893 env;
	env.one_x_c = one_x_c;
	return env;
}

value_t lambda893(env_t_893* env848, card_t x_c) {
	vector_shape_t one_x_c847 = env848->one_x_c;
	value_t res;
	res.vector_shape_t_value = one_x_c847;
	return res;
}
typedef empty_env_t env_t_894;


value_t lambda894(env_t_894* env852, card_t x_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef struct env_t_895 {
	number_t one_w_s;
} env_t_895;
env_t_895 make_env_t_895(number_t one_w_s) {
	env_t_895 env;
	env.one_w_s = one_w_s;
	return env;
}

value_t lambda895(env_t_895* env856, storage_t stgVar796, number_t x_s, card_t x_c) {
	number_t one_w_s855 = env856->one_w_s;
	value_t res;
	res.number_t_value = one_w_s855;
	return res;
}
typedef empty_env_t env_t_896;


value_t lambda896(env_t_896* env859, card_t x_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef struct env_t_897 {
	vector_shape_t one_feat_c;
} env_t_897;
env_t_897 make_env_t_897(vector_shape_t one_feat_c) {
	env_t_897 env;
	env.one_feat_c = one_feat_c;
	return env;
}

value_t lambda897(env_t_897* env864, card_t x_c) {
	vector_shape_t one_feat_c863 = env864->one_feat_c;
	value_t res;
	res.vector_shape_t_value = one_feat_c863;
	return res;
}
typedef struct env_t_898 {
	array_number_t one_feat_s;
} env_t_898;
env_t_898 make_env_t_898(array_number_t one_feat_s) {
	env_t_898 env;
	env.one_feat_s = one_feat_s;
	return env;
}

value_t lambda898(env_t_898* env868, storage_t stgVar805, number_t x_s, card_t x_c) {
	array_number_t one_feat_s867 = env868->one_feat_s;
	value_t res;
	res.array_number_t_value = one_feat_s867;
	return res;
}
typedef struct env_t_899 {
	vector_shape_t one_feat_c;
} env_t_899;
env_t_899 make_env_t_899(vector_shape_t one_feat_c) {
	env_t_899 env;
	env.one_feat_c = one_feat_c;
	return env;
}

value_t lambda899(env_t_899* env872, card_t x_c) {
	vector_shape_t one_feat_c871 = env872->one_feat_c;
	value_t res;
	res.vector_shape_t_value = one_feat_c871;
	return res;
}
typedef empty_env_t env_t_900;


value_t lambda900(env_t_900* env876, card_t x_c) {
	
	value_t res;
	res.vector_shape_t_value = nested_shape_card_t(0, 2);
	return res;
}
array_array_number_t TOP_LEVEL_usecases_ba_run_ba_from_file_s(storage_t stgVar778, string_t fn_s, card_t n_s, card_t m_s, card_t p_s, card_t fn_c, card_t n_c, card_t m_c, card_t p_c) {
	card_t oneCard_c = 1;
	card_t oneCard_s = 1;
	vector_shape_t one_cam_c = TOP_LEVEL_linalg_vectorRead_c(0, 0);
	array_number_t stgVar780 = malloc(width_vector_shape_t(one_cam_c));
	array_array_number_t macroDef890;array_number_t one_cam_s = TOP_LEVEL_linalg_vectorRead_s(stgVar780, fn_s, 1, 0, 0);
	env_t_892 env_t_892_value = make_env_t_892(one_cam_c); closure_t closure845 = make_closure(lambda892, &env_t_892_value);
	matrix_shape_t cam_c = nested_shape_vector_shape_t(closure845.lam(closure845.env, 0).vector_shape_t_value, n_c);
	array_number_t stgVar783 = malloc(width_matrix_shape_t(cam_c));
	array_array_number_t macroDef889;array_array_number_t macroDef846 = (array_array_number_t)stgVar783;
		macroDef846->length=n_s;
		macroDef846->arr=(array_number_t*)(STG_OFFSET(macroDef846, VECTOR_HEADER_BYTES));
		storage_t stgVar784 = (STG_OFFSET(macroDef846, MATRIX_HEADER_BYTES(n_s)));
		for(int x_s = 0; x_s < macroDef846->length; x_s++){
			
			macroDef846->arr[x_s] = one_cam_s;;
			stgVar784 = STG_OFFSET(stgVar784, VECTOR_ALL_BYTES(macroDef846->arr[x_s]->length));
		}
	array_array_number_t cam_s = macroDef846;
	vector_shape_t one_x_c = TOP_LEVEL_linalg_vectorRead_c(0, 0);
	array_number_t stgVar785 = malloc(width_vector_shape_t(one_x_c));
	array_array_number_t macroDef888;array_number_t one_x_s = TOP_LEVEL_linalg_vectorRead_s(stgVar785, fn_s, 2, 0, 0);
	env_t_893 env_t_893_value = make_env_t_893(one_x_c); closure_t closure850 = make_closure(lambda893, &env_t_893_value);
	matrix_shape_t x_c = nested_shape_vector_shape_t(closure850.lam(closure850.env, 0).vector_shape_t_value, m_c);
	array_number_t stgVar788 = malloc(width_matrix_shape_t(x_c));
	array_array_number_t macroDef887;array_array_number_t macroDef851 = (array_array_number_t)stgVar788;
		macroDef851->length=m_s;
		macroDef851->arr=(array_number_t*)(STG_OFFSET(macroDef851, VECTOR_HEADER_BYTES));
		storage_t stgVar789 = (STG_OFFSET(macroDef851, MATRIX_HEADER_BYTES(m_s)));
		for(int x_s = 0; x_s < macroDef851->length; x_s++){
			
			macroDef851->arr[x_s] = one_x_s;;
			stgVar789 = STG_OFFSET(stgVar789, VECTOR_ALL_BYTES(macroDef851->arr[x_s]->length));
		}
	array_array_number_t x_s = macroDef851;
	card_t one_w_c = 0;
	array_number_t stgVar790 = malloc(one_w_c);
	array_array_number_t macroDef886;number_t one_w_s = TOP_LEVEL_linalg_numberRead_s(stgVar790, fn_s, 3, 0, 0);
	env_t_894 env_t_894_value = make_empty_env(); closure_t closure854 = make_closure(lambda894, &env_t_894_value);
	vector_shape_t w_c = TOP_LEVEL_linalg_vectorMap_c(closure854, TOP_LEVEL_linalg_vectorRange_c(oneCard_c, p_c));
	array_number_t stgVar793 = malloc(width_vector_shape_t(w_c));
	array_array_number_t macroDef885;array_number_t stgVar795 = malloc(width_vector_shape_t(TOP_LEVEL_linalg_vectorRange_c(oneCard_c, p_c)));
	array_number_t macroDef862;env_t_895 env_t_895_value = make_env_t_895(one_w_s); closure_t closure858 = make_closure(lambda895, &env_t_895_value);
	env_t_896 env_t_896_value = make_empty_env(); closure_t closure861 = make_closure(lambda896, &env_t_896_value);
	macroDef862 = TOP_LEVEL_linalg_vectorMap_s(stgVar793, closure858, TOP_LEVEL_linalg_vectorRange_s(stgVar795, oneCard_s, p_s, oneCard_c, p_c), closure861, TOP_LEVEL_linalg_vectorRange_c(oneCard_c, p_c));;
	free(stgVar795);
	array_number_t w_s = macroDef862;
	vector_shape_t one_feat_c = TOP_LEVEL_linalg_vectorRead_c(0, 0);
	array_number_t stgVar799 = malloc(width_vector_shape_t(one_feat_c));
	array_array_number_t macroDef884;array_number_t one_feat_s = TOP_LEVEL_linalg_vectorRead_s(stgVar799, fn_s, 4, 0, 0);
	env_t_897 env_t_897_value = make_env_t_897(one_feat_c); closure_t closure866 = make_closure(lambda897, &env_t_897_value);
	matrix_shape_t feat_c = TOP_LEVEL_linalg_vectorMapToMatrix_c(closure866, TOP_LEVEL_linalg_vectorRange_c(oneCard_c, p_c));
	array_number_t stgVar802 = malloc(width_matrix_shape_t(feat_c));
	array_array_number_t macroDef883;array_number_t stgVar804 = malloc(width_vector_shape_t(TOP_LEVEL_linalg_vectorRange_c(oneCard_c, p_c)));
	array_array_number_t macroDef875;env_t_898 env_t_898_value = make_env_t_898(one_feat_s); closure_t closure870 = make_closure(lambda898, &env_t_898_value);
	env_t_899 env_t_899_value = make_env_t_899(one_feat_c); closure_t closure874 = make_closure(lambda899, &env_t_899_value);
	macroDef875 = TOP_LEVEL_linalg_vectorMapToMatrix_s(stgVar802, closure870, TOP_LEVEL_linalg_vectorRange_s(stgVar804, oneCard_s, p_s, oneCard_c, p_c), closure874, TOP_LEVEL_linalg_vectorRange_c(oneCard_c, p_c));;
	free(stgVar804);
	array_array_number_t feat_s = macroDef875;
	env_t_900 env_t_900_value = make_empty_env(); closure_t closure878 = make_closure(lambda900, &env_t_900_value);
	matrix_shape_t obs_c = nested_shape_vector_shape_t(closure878.lam(closure878.env, 0).vector_shape_t_value, p_c);
	array_number_t stgVar808 = malloc(width_matrix_shape_t(obs_c));
	array_array_number_t macroDef882;array_array_number_t macroDef880 = (array_array_number_t)stgVar808;
		macroDef880->length=p_s;
		macroDef880->arr=(array_number_t*)(STG_OFFSET(macroDef880, VECTOR_HEADER_BYTES));
		storage_t stgVar809 = (STG_OFFSET(macroDef880, MATRIX_HEADER_BYTES(p_s)));
		for(int x_s = 0; x_s < macroDef880->length; x_s++){
			array_number_t macroDef879 = (array_number_t)stgVar809;
	macroDef879->length=2;
	macroDef879->arr=(number_t*)(STG_OFFSET(stgVar809, VECTOR_HEADER_BYTES));
	macroDef879->arr[0] = (double)(((int)(x_s)) % ((n_s)));
	macroDef879->arr[1] = (double)(((int)(x_s)) % ((m_s)));;
			macroDef880->arr[x_s] = macroDef879;;
			stgVar809 = STG_OFFSET(stgVar809, VECTOR_ALL_BYTES(macroDef880->arr[x_s]->length));
		}
	array_array_number_t obs_s = macroDef880;
	card_t t_c = 0;
	timer_t t_s = tic();
	matrix_shape_t res_c = TOP_LEVEL_usecases_ba_reproj_err_c(cam_c, x_c, w_c, obs_c, feat_c);
	array_number_t stgVar813 = malloc(width_matrix_shape_t(res_c));
	array_array_number_t macroDef881;array_array_number_t res_s = TOP_LEVEL_usecases_ba_reproj_err_s(stgVar813, cam_s, x_s, w_s, obs_s, feat_s, cam_c, x_c, w_c, obs_c, feat_c);
	toc(t_s);
	macroDef881 = res_s;;
	free(stgVar813);
	macroDef882 = macroDef881;;
	free(stgVar808);
	macroDef883 = macroDef882;;
	free(stgVar802);
	macroDef884 = macroDef883;;
	free(stgVar799);
	macroDef885 = macroDef884;;
	free(stgVar793);
	macroDef886 = macroDef885;;
	free(stgVar790);
	macroDef887 = macroDef886;;
	free(stgVar788);
	macroDef888 = macroDef887;;
	free(stgVar785);
	macroDef889 = macroDef888;;
	free(stgVar783);
	macroDef890 = macroDef889;;
	free(stgVar780);
	return macroDef890;
}

card_t TOP_LEVEL_usecases_ba_test_ba_c(vector_shape_t dum_c) {
	
	return 0;
}


void TOP_LEVEL_usecases_ba_test_ba_s(storage_t stgVar901, array_number_t dum_s, vector_shape_t dum_c) {
	vector_shape_t a_c = nested_shape_card_t(0, 3);
	array_number_t stgVar902 = malloc(width_vector_shape_t(a_c));
	array_number_t macroDef935 = (array_number_t)stgVar902;
	macroDef935->length=3;
	macroDef935->arr=(number_t*)(STG_OFFSET(stgVar902, VECTOR_HEADER_BYTES));
	macroDef935->arr[0] = 1;
	macroDef935->arr[1] = 2;
	macroDef935->arr[2] = 3;;
	array_number_t a_s = macroDef935;
	vector_shape_t b_c = nested_shape_card_t(0, 3);
	array_number_t stgVar906 = malloc(width_vector_shape_t(b_c));
	array_number_t macroDef936 = (array_number_t)stgVar906;
	macroDef936->length=3;
	macroDef936->arr=(number_t*)(STG_OFFSET(stgVar906, VECTOR_HEADER_BYTES));
	macroDef936->arr[0] = 5;
	macroDef936->arr[1] = 6;
	macroDef936->arr[2] = 7;;
	array_number_t b_s = macroDef936;
	array_print(a_s);
	array_print(b_s);
	vector_shape_t j_c = TOP_LEVEL_usecases_ba_radial_distort_c(a_c, b_c);
	array_number_t stgVar910 = malloc(width_vector_shape_t(j_c));
	array_number_t j_s = TOP_LEVEL_usecases_ba_radial_distort_s(stgVar910, a_s, b_s, a_c, b_c);
	array_print(j_s);
	vector_shape_t k_c = TOP_LEVEL_usecases_ba_rodrigues_rotate_point_c(a_c, b_c);
	array_number_t stgVar913 = malloc(width_vector_shape_t(k_c));
	array_number_t k_s = TOP_LEVEL_usecases_ba_rodrigues_rotate_point_s(stgVar913, a_s, b_s, a_c, b_c);
	array_print(k_s);
	vector_shape_t l_c = TOP_LEVEL_linalg_vectorSlice_c(2, 0, k_c);
	array_number_t stgVar916 = malloc(width_vector_shape_t(l_c));
	array_number_t l_s = TOP_LEVEL_linalg_vectorSlice_s(stgVar916, 2, 1, k_s, 2, 0, k_c);
	array_print(l_s);
	vector_shape_t cam_c = nested_shape_card_t(0, 11);
	array_number_t stgVar920 = malloc(width_vector_shape_t(cam_c));
	array_number_t macroDef937 = (array_number_t)stgVar920;
	macroDef937->length=11;
	macroDef937->arr=(number_t*)(STG_OFFSET(stgVar920, VECTOR_HEADER_BYTES));
	macroDef937->arr[0] = 0;
	macroDef937->arr[1] = 2;
	macroDef937->arr[2] = 4;
	macroDef937->arr[3] = 6;
	macroDef937->arr[4] = 8;
	macroDef937->arr[5] = 10;
	macroDef937->arr[6] = 12;
	macroDef937->arr[7] = 14;
	macroDef937->arr[8] = 16;
	macroDef937->arr[9] = 18;
	macroDef937->arr[10] = 20;;
	array_number_t cam_s = macroDef937;
	vector_shape_t m_c = TOP_LEVEL_usecases_ba_project_c(cam_c, j_c);
	array_number_t stgVar932 = malloc(width_vector_shape_t(m_c));
	array_number_t m_s = TOP_LEVEL_usecases_ba_project_s(stgVar932, cam_s, j_s, cam_c, j_c);
	array_print(m_s);
	;
	free(stgVar932);
	;
	free(stgVar920);
	;
	free(stgVar916);
	;
	free(stgVar913);
	;
	free(stgVar910);
	;
	free(stgVar906);
	;
	free(stgVar902);
	return ;
}
#endif
