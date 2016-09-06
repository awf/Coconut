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


array_number_t TOP_LEVEL_usecases_ba_radial_distort_s(storage_t stgVar491, array_number_t rad_params_s, array_number_t proj_s, vector_shape_t rad_params_c, vector_shape_t proj_c) {
	card_t rsq_c = 0;
	array_number_t stgVar492 = malloc(rsq_c);
	array_number_t macroDef499;number_t rsq_s = TOP_LEVEL_linalg_sqnorm_s(stgVar492, proj_s, proj_c);
	card_t L_c = 0;
	number_t L_s = ((1) + ((rad_params_s->arr[0]) * (rsq_s))) + (((rad_params_s->arr[1]) * (rsq_s)) * (rsq_s));
	macroDef499 = TOP_LEVEL_linalg_mult_by_scalar_s(stgVar491, proj_s, L_s, proj_c, 0);;
	free(stgVar492);
	return macroDef499;
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


array_number_t TOP_LEVEL_usecases_ba_rodrigues_rotate_point_s(storage_t stgVar500, array_number_t rot_s, array_number_t x_s, vector_shape_t rot_c, vector_shape_t x_c) {
	card_t sqtheta_c = 0;
	array_number_t stgVar501 = malloc(sqtheta_c);
	array_number_t macroDef539;number_t sqtheta_s = TOP_LEVEL_linalg_sqnorm_s(stgVar501, rot_s, rot_c);
	array_number_t ite540 = 0;
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
		array_number_t stgVar507 = malloc(width_vector_shape_t(w_c));
	array_number_t macroDef537;array_number_t w_s = TOP_LEVEL_linalg_mult_by_scalar_s(stgVar507, rot_s, theta_inv_s, rot_c, 0);
	vector_shape_t w_cross_X_c = TOP_LEVEL_linalg_cross_c(w_c, x_c);
	array_number_t stgVar510 = malloc(width_vector_shape_t(w_cross_X_c));
	array_number_t macroDef536;array_number_t w_cross_X_s = TOP_LEVEL_linalg_cross_s(stgVar510, w_s, x_s, w_c, x_c);
	card_t tmp_c = 0;
	number_t tmp_s = (TOP_LEVEL_linalg_dot_prod_s(empty_storage, w_s, x_s, w_c, x_c)) * ((1) - (costheta_s));
	vector_shape_t v1_c = TOP_LEVEL_linalg_mult_by_scalar_c(x_c, 0);
	array_number_t stgVar516 = malloc(width_vector_shape_t(v1_c));
	array_number_t macroDef535;array_number_t v1_s = TOP_LEVEL_linalg_mult_by_scalar_s(stgVar516, x_s, costheta_s, x_c, 0);
	vector_shape_t v2_c = TOP_LEVEL_linalg_mult_by_scalar_c(w_cross_X_c, 0);
	array_number_t stgVar519 = malloc(width_vector_shape_t(v2_c));
	array_number_t macroDef534;array_number_t v2_s = TOP_LEVEL_linalg_mult_by_scalar_s(stgVar519, w_cross_X_s, sintheta_s, w_cross_X_c, 0);
	array_number_t stgVar523 = malloc(width_vector_shape_t(TOP_LEVEL_linalg_mult_by_scalar_c(w_c, 0)));
	array_number_t macroDef533;array_number_t stgVar522 = malloc(width_vector_shape_t(TOP_LEVEL_linalg_add_vec_c(v1_c, v2_c)));
	array_number_t macroDef532;
	macroDef532 = TOP_LEVEL_linalg_add_vec_s(stgVar500, TOP_LEVEL_linalg_add_vec_s(stgVar522, v1_s, v2_s, v1_c, v2_c), TOP_LEVEL_linalg_mult_by_scalar_s(stgVar523, w_s, tmp_s, w_c, 0), TOP_LEVEL_linalg_add_vec_c(v1_c, v2_c), TOP_LEVEL_linalg_mult_by_scalar_c(w_c, 0));;
	free(stgVar522);
	macroDef533 = macroDef532;;
	free(stgVar523);
	macroDef534 = macroDef533;;
	free(stgVar519);
	macroDef535 = macroDef534;;
	free(stgVar516);
	macroDef536 = macroDef535;;
	free(stgVar510);
	macroDef537 = macroDef536;;
	free(stgVar507);
		ite540 = macroDef537;;
	} else {
		array_number_t stgVar529 = malloc(width_vector_shape_t(TOP_LEVEL_linalg_cross_c(rot_c, x_c)));
	array_number_t macroDef538;
	macroDef538 = TOP_LEVEL_linalg_add_vec_s(stgVar500, x_s, TOP_LEVEL_linalg_cross_s(stgVar529, rot_s, x_s, rot_c, x_c), x_c, TOP_LEVEL_linalg_cross_c(rot_c, x_c));;
	free(stgVar529);
		ite540 = macroDef538;;
	}
	macroDef539 = ite540;;
	free(stgVar501);
	return macroDef539;
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


array_number_t TOP_LEVEL_usecases_ba_project_s(storage_t stgVar541, array_number_t cam_s, array_number_t x_s, vector_shape_t cam_c, vector_shape_t x_c) {
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
	array_number_t stgVar548 = malloc(width_vector_shape_t(Xcam_c));
	array_number_t macroDef588;array_number_t stgVar550 = malloc(width_vector_shape_t(TOP_LEVEL_linalg_sub_vec_c(x_c, TOP_LEVEL_linalg_vectorSlice_c(3, 0, cam_c))));
	array_number_t macroDef581;array_number_t stgVar549 = malloc(width_vector_shape_t(TOP_LEVEL_linalg_vectorSlice_c(3, 0, cam_c)));
	array_number_t macroDef580;array_number_t stgVar555 = malloc(width_vector_shape_t(TOP_LEVEL_linalg_vectorSlice_c(3, 0, cam_c)));
	array_number_t macroDef579;
	macroDef579 = TOP_LEVEL_linalg_sub_vec_s(stgVar550, x_s, TOP_LEVEL_linalg_vectorSlice_s(stgVar555, 3, CENTER_IDX_s, cam_s, 3, 0, cam_c), x_c, TOP_LEVEL_linalg_vectorSlice_c(3, 0, cam_c));;
	free(stgVar555);
	macroDef580 = TOP_LEVEL_usecases_ba_rodrigues_rotate_point_s(stgVar548, TOP_LEVEL_linalg_vectorSlice_s(stgVar549, 3, ROT_IDX_s, cam_s, 3, 0, cam_c), macroDef579, TOP_LEVEL_linalg_vectorSlice_c(3, 0, cam_c), TOP_LEVEL_linalg_sub_vec_c(x_c, TOP_LEVEL_linalg_vectorSlice_c(3, 0, cam_c)));;
	free(stgVar549);
	macroDef581 = macroDef580;;
	free(stgVar550);
	array_number_t Xcam_s = macroDef581;
	vector_shape_t distorted_c = TOP_LEVEL_usecases_ba_radial_distort_c(TOP_LEVEL_linalg_vectorSlice_c(2, 0, cam_c), TOP_LEVEL_linalg_mult_by_scalar_c(TOP_LEVEL_linalg_vectorSlice_c(2, 0, Xcam_c), 0));
	array_number_t stgVar559 = malloc(width_vector_shape_t(distorted_c));
	array_number_t macroDef587;array_number_t stgVar561 = malloc(width_vector_shape_t(TOP_LEVEL_linalg_mult_by_scalar_c(TOP_LEVEL_linalg_vectorSlice_c(2, 0, Xcam_c), 0)));
	array_number_t macroDef584;array_number_t stgVar560 = malloc(width_vector_shape_t(TOP_LEVEL_linalg_vectorSlice_c(2, 0, cam_c)));
	array_number_t macroDef583;array_number_t stgVar565 = malloc(width_vector_shape_t(TOP_LEVEL_linalg_vectorSlice_c(2, 0, Xcam_c)));
	array_number_t macroDef582;
	macroDef582 = TOP_LEVEL_linalg_mult_by_scalar_s(stgVar561, TOP_LEVEL_linalg_vectorSlice_s(stgVar565, 2, 0, Xcam_s, 2, 0, Xcam_c), (1) / (Xcam_s->arr[2]), TOP_LEVEL_linalg_vectorSlice_c(2, 0, Xcam_c), 0);;
	free(stgVar565);
	macroDef583 = TOP_LEVEL_usecases_ba_radial_distort_s(stgVar559, TOP_LEVEL_linalg_vectorSlice_s(stgVar560, 2, RAD_IDX_s, cam_s, 2, 0, cam_c), macroDef582, TOP_LEVEL_linalg_vectorSlice_c(2, 0, cam_c), TOP_LEVEL_linalg_mult_by_scalar_c(TOP_LEVEL_linalg_vectorSlice_c(2, 0, Xcam_c), 0));;
	free(stgVar560);
	macroDef584 = macroDef583;;
	free(stgVar561);
	array_number_t distorted_s = macroDef584;
	array_number_t stgVar572 = malloc(width_vector_shape_t(TOP_LEVEL_linalg_mult_by_scalar_c(distorted_c, 0)));
	array_number_t macroDef586;array_number_t stgVar571 = malloc(width_vector_shape_t(TOP_LEVEL_linalg_vectorSlice_c(2, 0, cam_c)));
	array_number_t macroDef585;
	macroDef585 = TOP_LEVEL_linalg_add_vec_s(stgVar541, TOP_LEVEL_linalg_vectorSlice_s(stgVar571, 2, X0_IDX_s, cam_s, 2, 0, cam_c), TOP_LEVEL_linalg_mult_by_scalar_s(stgVar572, distorted_s, cam_s->arr[FOCAL_IDX_s], distorted_c, 0), TOP_LEVEL_linalg_vectorSlice_c(2, 0, cam_c), TOP_LEVEL_linalg_mult_by_scalar_c(distorted_c, 0));;
	free(stgVar571);
	macroDef586 = macroDef585;;
	free(stgVar572);
	macroDef587 = macroDef586;;
	free(stgVar559);
	macroDef588 = macroDef587;;
	free(stgVar548);
	return macroDef588;
}

vector_shape_t TOP_LEVEL_usecases_ba_compute_reproj_err_c(vector_shape_t cam_c, vector_shape_t x_c, card_t w_c, vector_shape_t feat_c) {
	
	return TOP_LEVEL_linalg_mult_by_scalar_c(TOP_LEVEL_linalg_sub_vec_c(TOP_LEVEL_usecases_ba_project_c(cam_c, x_c), feat_c), 0);
}


array_number_t TOP_LEVEL_usecases_ba_compute_reproj_err_s(storage_t stgVar589, array_number_t cam_s, array_number_t x_s, number_t w_s, array_number_t feat_s, vector_shape_t cam_c, vector_shape_t x_c, card_t w_c, vector_shape_t feat_c) {
	array_number_t stgVar590 = malloc(width_vector_shape_t(TOP_LEVEL_linalg_sub_vec_c(TOP_LEVEL_usecases_ba_project_c(cam_c, x_c), feat_c)));
	array_number_t macroDef597;array_number_t stgVar592 = malloc(width_vector_shape_t(TOP_LEVEL_usecases_ba_project_c(cam_c, x_c)));
	array_number_t macroDef596;
	macroDef596 = TOP_LEVEL_linalg_sub_vec_s(stgVar590, TOP_LEVEL_usecases_ba_project_s(stgVar592, cam_s, x_s, cam_c, x_c), feat_s, TOP_LEVEL_usecases_ba_project_c(cam_c, x_c), feat_c);;
	free(stgVar592);
	macroDef597 = TOP_LEVEL_linalg_mult_by_scalar_s(stgVar589, macroDef596, w_s, TOP_LEVEL_linalg_sub_vec_c(TOP_LEVEL_usecases_ba_project_c(cam_c, x_c), feat_c), 0);;
	free(stgVar590);
	return macroDef597;
}

card_t TOP_LEVEL_usecases_ba_compute_zach_weight_error_c(card_t w_c) {
	
	return 0;
}


number_t TOP_LEVEL_usecases_ba_compute_zach_weight_error_s(storage_t stgVar598, number_t w_s, card_t w_c) {
	
	return (1) - ((w_s) * (w_s));
}
typedef empty_env_t env_t_607;


value_t lambda607(env_t_607* env604, card_t w_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
vector_shape_t TOP_LEVEL_usecases_ba_w_err_c(vector_shape_t w_c) {
	env_t_607 env_t_607_value = make_empty_env(); closure_t closure606 = make_closure(lambda607, &env_t_607_value);
	return TOP_LEVEL_linalg_vectorMap_c(closure606, w_c);
}

typedef empty_env_t env_t_614;


value_t lambda614(env_t_614* env608, storage_t stgVar602, number_t w_s, card_t w_c) {
	
	value_t res;
	res.number_t_value = TOP_LEVEL_usecases_ba_compute_zach_weight_error_s(stgVar602, w_s, 0);
	return res;
}
typedef empty_env_t env_t_615;


value_t lambda615(env_t_615* env611, card_t w_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
array_number_t TOP_LEVEL_usecases_ba_w_err_s(storage_t stgVar599, array_number_t w_s, vector_shape_t w_c) {
	env_t_614 env_t_614_value = make_empty_env(); closure_t closure610 = make_closure(lambda614, &env_t_614_value);
	env_t_615 env_t_615_value = make_empty_env(); closure_t closure613 = make_closure(lambda615, &env_t_615_value);
	return TOP_LEVEL_linalg_vectorMap_s(stgVar599, closure610, w_s, closure613, w_c);
}
typedef struct env_t_645 {
	matrix_shape_t x_c;
	matrix_shape_t feat_c;
	matrix_shape_t cams_c;
} env_t_645;
env_t_645 make_env_t_645(matrix_shape_t x_c,matrix_shape_t feat_c,matrix_shape_t cams_c) {
	env_t_645 env;
	env.x_c = x_c;
	env.feat_c = feat_c;
	env.cams_c = cams_c;
	return env;
}

value_t lambda645(env_t_645* env642, card_t i_c) {
	matrix_shape_t x_c641 = env642->x_c;
	matrix_shape_t feat_c640 = env642->feat_c;
	matrix_shape_t cams_c639 = env642->cams_c;
	value_t res;
	res.vector_shape_t_value = TOP_LEVEL_usecases_ba_compute_reproj_err_c(cams_c639.elem, x_c641.elem, 0, feat_c640.elem);
	return res;
}
matrix_shape_t TOP_LEVEL_usecases_ba_reproj_err_c(matrix_shape_t cams_c, matrix_shape_t x_c, vector_shape_t w_c, matrix_shape_t obs_c, matrix_shape_t feat_c) {
	card_t n_c = cams_c.card;
	card_t p_c = w_c.card;
	vector_shape_t range_c = TOP_LEVEL_linalg_vectorRange_c(0, (p_c) - (1));
	env_t_645 env_t_645_value = make_env_t_645(x_c,feat_c,cams_c); closure_t closure644 = make_closure(lambda645, &env_t_645_value);
	return TOP_LEVEL_linalg_vectorMapToMatrix_c(closure644, range_c);
}

typedef struct env_t_672 {
	array_array_number_t x_s;
	matrix_shape_t x_c;
	array_number_t w_s;
	array_array_number_t obs_s;
	matrix_shape_t obs_c;
	array_array_number_t feat_s;
	matrix_shape_t feat_c;
	array_array_number_t cams_s;
	matrix_shape_t cams_c;
} env_t_672;
env_t_672 make_env_t_672(array_array_number_t x_s,matrix_shape_t x_c,array_number_t w_s,array_array_number_t obs_s,matrix_shape_t obs_c,array_array_number_t feat_s,matrix_shape_t feat_c,array_array_number_t cams_s,matrix_shape_t cams_c) {
	env_t_672 env;
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

value_t lambda672(env_t_672* env662, storage_t stgVar626, number_t i_s, card_t i_c) {
	array_array_number_t x_s661 = env662->x_s;
	matrix_shape_t x_c660 = env662->x_c;
	array_number_t w_s659 = env662->w_s;
	array_array_number_t obs_s658 = env662->obs_s;
	matrix_shape_t obs_c657 = env662->obs_c;
	array_array_number_t feat_s656 = env662->feat_s;
	matrix_shape_t feat_c655 = env662->feat_c;
	array_array_number_t cams_s654 = env662->cams_s;
	matrix_shape_t cams_c653 = env662->cams_c;
	array_number_t stgVar630 = malloc(width_vector_shape_t(feat_c655.elem));
	array_number_t macroDef652;array_number_t stgVar628 = malloc(width_vector_shape_t(x_c660.elem));
	array_number_t macroDef651;array_number_t stgVar627 = malloc(width_vector_shape_t(cams_c653.elem));
	array_number_t macroDef650;array_number_t stgVar632 = malloc(width_vector_shape_t(obs_c657.elem));
	number_t macroDef648;
	macroDef648 = obs_s658->arr[(int)(i_s)]->arr[0];;
	free(stgVar632);
	array_number_t stgVar635 = malloc(width_vector_shape_t(obs_c657.elem));
	number_t macroDef649;
	macroDef649 = obs_s658->arr[(int)(i_s)]->arr[1];;
	free(stgVar635);
	macroDef650 = TOP_LEVEL_usecases_ba_compute_reproj_err_s(stgVar626, cams_s654->arr[(int)(macroDef648)], x_s661->arr[(int)(macroDef649)], w_s659->arr[(int)(i_s)], feat_s656->arr[(int)(i_s)], cams_c653.elem, x_c660.elem, 0, feat_c655.elem);;
	free(stgVar627);
	macroDef651 = macroDef650;;
	free(stgVar628);
	macroDef652 = macroDef651;;
	free(stgVar630);
	value_t res;
	res.array_number_t_value = macroDef652;
	return res;
}
typedef struct env_t_673 {
	matrix_shape_t x_c;
	matrix_shape_t feat_c;
	matrix_shape_t cams_c;
} env_t_673;
env_t_673 make_env_t_673(matrix_shape_t x_c,matrix_shape_t feat_c,matrix_shape_t cams_c) {
	env_t_673 env;
	env.x_c = x_c;
	env.feat_c = feat_c;
	env.cams_c = cams_c;
	return env;
}

value_t lambda673(env_t_673* env668, card_t i_c) {
	matrix_shape_t x_c667 = env668->x_c;
	matrix_shape_t feat_c666 = env668->feat_c;
	matrix_shape_t cams_c665 = env668->cams_c;
	value_t res;
	res.vector_shape_t_value = TOP_LEVEL_usecases_ba_compute_reproj_err_c(cams_c665.elem, x_c667.elem, 0, feat_c666.elem);
	return res;
}
array_array_number_t TOP_LEVEL_usecases_ba_reproj_err_s(storage_t stgVar616, array_array_number_t cams_s, array_array_number_t x_s, array_number_t w_s, array_array_number_t obs_s, array_array_number_t feat_s, matrix_shape_t cams_c, matrix_shape_t x_c, vector_shape_t w_c, matrix_shape_t obs_c, matrix_shape_t feat_c) {
	card_t n_c = cams_c.card;
	card_t macroDef646 = cams_s->length;
	card_t n_s = macroDef646;
	card_t p_c = w_c.card;
	card_t macroDef647 = w_s->length;
	card_t p_s = macroDef647;
	vector_shape_t range_c = TOP_LEVEL_linalg_vectorRange_c(0, (p_c) - (1));
	array_number_t stgVar621 = malloc(width_vector_shape_t(range_c));
	array_array_number_t macroDef671;array_number_t range_s = TOP_LEVEL_linalg_vectorRange_s(stgVar621, 0, (p_s) - (1), 0, (p_c) - (1));
	env_t_672 env_t_672_value = make_env_t_672(x_s,x_c,w_s,obs_s,obs_c,feat_s,feat_c,cams_s,cams_c); closure_t closure664 = make_closure(lambda672, &env_t_672_value);
	env_t_673 env_t_673_value = make_env_t_673(x_c,feat_c,cams_c); closure_t closure670 = make_closure(lambda673, &env_t_673_value);
	macroDef671 = TOP_LEVEL_linalg_vectorMapToMatrix_s(stgVar616, closure664, range_s, closure670, range_c);;
	free(stgVar621);
	return macroDef671;
}
typedef struct env_t_733 {
	vector_shape_t one_cam_c;
} env_t_733;
env_t_733 make_env_t_733(vector_shape_t one_cam_c) {
	env_t_733 env;
	env.one_cam_c = one_cam_c;
	return env;
}

value_t lambda733(env_t_733* env716, card_t x_c) {
	vector_shape_t one_cam_c715 = env716->one_cam_c;
	value_t res;
	res.vector_shape_t_value = one_cam_c715;
	return res;
}
typedef struct env_t_734 {
	vector_shape_t one_x_c;
} env_t_734;
env_t_734 make_env_t_734(vector_shape_t one_x_c) {
	env_t_734 env;
	env.one_x_c = one_x_c;
	return env;
}

value_t lambda734(env_t_734* env720, card_t x_c) {
	vector_shape_t one_x_c719 = env720->one_x_c;
	value_t res;
	res.vector_shape_t_value = one_x_c719;
	return res;
}
typedef empty_env_t env_t_735;


value_t lambda735(env_t_735* env723, card_t x_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef struct env_t_736 {
	vector_shape_t one_feat_c;
} env_t_736;
env_t_736 make_env_t_736(vector_shape_t one_feat_c) {
	env_t_736 env;
	env.one_feat_c = one_feat_c;
	return env;
}

value_t lambda736(env_t_736* env727, card_t x_c) {
	vector_shape_t one_feat_c726 = env727->one_feat_c;
	value_t res;
	res.vector_shape_t_value = one_feat_c726;
	return res;
}
typedef empty_env_t env_t_737;


value_t lambda737(env_t_737* env730, card_t x_c) {
	
	value_t res;
	res.vector_shape_t_value = nested_shape_card_t(0, 2);
	return res;
}
matrix_shape_t TOP_LEVEL_usecases_ba_run_ba_from_file_c(card_t fn_c, card_t n_c, card_t m_c, card_t p_c) {
	card_t oneCard_c = 1;
	vector_shape_t one_cam_c = TOP_LEVEL_linalg_vectorRead_c(0, 0);
	env_t_733 env_t_733_value = make_env_t_733(one_cam_c); closure_t closure718 = make_closure(lambda733, &env_t_733_value);
	matrix_shape_t cam_c = nested_shape_vector_shape_t(closure718.lam(closure718.env, 0).vector_shape_t_value, n_c);
	vector_shape_t one_x_c = TOP_LEVEL_linalg_vectorRead_c(0, 0);
	env_t_734 env_t_734_value = make_env_t_734(one_x_c); closure_t closure722 = make_closure(lambda734, &env_t_734_value);
	matrix_shape_t x_c = nested_shape_vector_shape_t(closure722.lam(closure722.env, 0).vector_shape_t_value, m_c);
	card_t one_w_c = 0;
	env_t_735 env_t_735_value = make_empty_env(); closure_t closure725 = make_closure(lambda735, &env_t_735_value);
	vector_shape_t w_c = TOP_LEVEL_linalg_vectorMap_c(closure725, TOP_LEVEL_linalg_vectorRange_c(oneCard_c, p_c));
	vector_shape_t one_feat_c = TOP_LEVEL_linalg_vectorRead_c(0, 0);
	env_t_736 env_t_736_value = make_env_t_736(one_feat_c); closure_t closure729 = make_closure(lambda736, &env_t_736_value);
	matrix_shape_t feat_c = TOP_LEVEL_linalg_vectorMapToMatrix_c(closure729, TOP_LEVEL_linalg_vectorRange_c(oneCard_c, p_c));
	env_t_737 env_t_737_value = make_empty_env(); closure_t closure732 = make_closure(lambda737, &env_t_737_value);
	matrix_shape_t obs_c = nested_shape_vector_shape_t(closure732.lam(closure732.env, 0).vector_shape_t_value, p_c);
	card_t t_c = 0;
	matrix_shape_t res_c = TOP_LEVEL_usecases_ba_reproj_err_c(cam_c, x_c, w_c, obs_c, feat_c);
	return res_c;
}

typedef struct env_t_788 {
	vector_shape_t one_cam_c;
} env_t_788;
env_t_788 make_env_t_788(vector_shape_t one_cam_c) {
	env_t_788 env;
	env.one_cam_c = one_cam_c;
	return env;
}

value_t lambda788(env_t_788* env739, card_t x_c) {
	vector_shape_t one_cam_c738 = env739->one_cam_c;
	value_t res;
	res.vector_shape_t_value = one_cam_c738;
	return res;
}
typedef struct env_t_789 {
	vector_shape_t one_x_c;
} env_t_789;
env_t_789 make_env_t_789(vector_shape_t one_x_c) {
	env_t_789 env;
	env.one_x_c = one_x_c;
	return env;
}

value_t lambda789(env_t_789* env744, card_t x_c) {
	vector_shape_t one_x_c743 = env744->one_x_c;
	value_t res;
	res.vector_shape_t_value = one_x_c743;
	return res;
}
typedef empty_env_t env_t_790;


value_t lambda790(env_t_790* env748, card_t x_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef struct env_t_791 {
	number_t one_w_s;
} env_t_791;
env_t_791 make_env_t_791(number_t one_w_s) {
	env_t_791 env;
	env.one_w_s = one_w_s;
	return env;
}

value_t lambda791(env_t_791* env752, storage_t stgVar692, number_t x_s, card_t x_c) {
	number_t one_w_s751 = env752->one_w_s;
	value_t res;
	res.number_t_value = one_w_s751;
	return res;
}
typedef empty_env_t env_t_792;


value_t lambda792(env_t_792* env755, card_t x_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef struct env_t_793 {
	vector_shape_t one_feat_c;
} env_t_793;
env_t_793 make_env_t_793(vector_shape_t one_feat_c) {
	env_t_793 env;
	env.one_feat_c = one_feat_c;
	return env;
}

value_t lambda793(env_t_793* env760, card_t x_c) {
	vector_shape_t one_feat_c759 = env760->one_feat_c;
	value_t res;
	res.vector_shape_t_value = one_feat_c759;
	return res;
}
typedef struct env_t_794 {
	array_number_t one_feat_s;
} env_t_794;
env_t_794 make_env_t_794(array_number_t one_feat_s) {
	env_t_794 env;
	env.one_feat_s = one_feat_s;
	return env;
}

value_t lambda794(env_t_794* env764, storage_t stgVar701, number_t x_s, card_t x_c) {
	array_number_t one_feat_s763 = env764->one_feat_s;
	value_t res;
	res.array_number_t_value = one_feat_s763;
	return res;
}
typedef struct env_t_795 {
	vector_shape_t one_feat_c;
} env_t_795;
env_t_795 make_env_t_795(vector_shape_t one_feat_c) {
	env_t_795 env;
	env.one_feat_c = one_feat_c;
	return env;
}

value_t lambda795(env_t_795* env768, card_t x_c) {
	vector_shape_t one_feat_c767 = env768->one_feat_c;
	value_t res;
	res.vector_shape_t_value = one_feat_c767;
	return res;
}
typedef empty_env_t env_t_796;


value_t lambda796(env_t_796* env772, card_t x_c) {
	
	value_t res;
	res.vector_shape_t_value = nested_shape_card_t(0, 2);
	return res;
}
array_array_number_t TOP_LEVEL_usecases_ba_run_ba_from_file_s(storage_t stgVar674, string_t fn_s, card_t n_s, card_t m_s, card_t p_s, card_t fn_c, card_t n_c, card_t m_c, card_t p_c) {
	card_t oneCard_c = 1;
	card_t oneCard_s = 1;
	vector_shape_t one_cam_c = TOP_LEVEL_linalg_vectorRead_c(0, 0);
	array_number_t stgVar676 = malloc(width_vector_shape_t(one_cam_c));
	array_array_number_t macroDef786;array_number_t one_cam_s = TOP_LEVEL_linalg_vectorRead_s(stgVar676, fn_s, 1, 0, 0);
	env_t_788 env_t_788_value = make_env_t_788(one_cam_c); closure_t closure741 = make_closure(lambda788, &env_t_788_value);
	matrix_shape_t cam_c = nested_shape_vector_shape_t(closure741.lam(closure741.env, 0).vector_shape_t_value, n_c);
	array_number_t stgVar679 = malloc(width_matrix_shape_t(cam_c));
	array_array_number_t macroDef785;array_array_number_t macroDef742 = (array_array_number_t)stgVar679;
		macroDef742->length=n_s;
		macroDef742->arr=(array_number_t*)((char*)macroDef742 + VECTOR_HEADER_BYTES);
		storage_t stgVar680 = ((char*)macroDef742 + MATRIX_HEADER_BYTES(n_s));
		for(int x_s = 0; x_s < macroDef742->length; x_s++){
			
			macroDef742->arr[x_s] = one_cam_s;;
			stgVar680 = (char*)stgVar680 + VECTOR_ALL_BYTES(macroDef742->arr[x_s]->length);
		}
	array_array_number_t cam_s = macroDef742;
	vector_shape_t one_x_c = TOP_LEVEL_linalg_vectorRead_c(0, 0);
	array_number_t stgVar681 = malloc(width_vector_shape_t(one_x_c));
	array_array_number_t macroDef784;array_number_t one_x_s = TOP_LEVEL_linalg_vectorRead_s(stgVar681, fn_s, 2, 0, 0);
	env_t_789 env_t_789_value = make_env_t_789(one_x_c); closure_t closure746 = make_closure(lambda789, &env_t_789_value);
	matrix_shape_t x_c = nested_shape_vector_shape_t(closure746.lam(closure746.env, 0).vector_shape_t_value, m_c);
	array_number_t stgVar684 = malloc(width_matrix_shape_t(x_c));
	array_array_number_t macroDef783;array_array_number_t macroDef747 = (array_array_number_t)stgVar684;
		macroDef747->length=m_s;
		macroDef747->arr=(array_number_t*)((char*)macroDef747 + VECTOR_HEADER_BYTES);
		storage_t stgVar685 = ((char*)macroDef747 + MATRIX_HEADER_BYTES(m_s));
		for(int x_s = 0; x_s < macroDef747->length; x_s++){
			
			macroDef747->arr[x_s] = one_x_s;;
			stgVar685 = (char*)stgVar685 + VECTOR_ALL_BYTES(macroDef747->arr[x_s]->length);
		}
	array_array_number_t x_s = macroDef747;
	card_t one_w_c = 0;
	array_number_t stgVar686 = malloc(one_w_c);
	array_array_number_t macroDef782;number_t one_w_s = TOP_LEVEL_linalg_numberRead_s(stgVar686, fn_s, 3, 0, 0);
	env_t_790 env_t_790_value = make_empty_env(); closure_t closure750 = make_closure(lambda790, &env_t_790_value);
	vector_shape_t w_c = TOP_LEVEL_linalg_vectorMap_c(closure750, TOP_LEVEL_linalg_vectorRange_c(oneCard_c, p_c));
	array_number_t stgVar689 = malloc(width_vector_shape_t(w_c));
	array_array_number_t macroDef781;array_number_t stgVar691 = malloc(width_vector_shape_t(TOP_LEVEL_linalg_vectorRange_c(oneCard_c, p_c)));
	array_number_t macroDef758;env_t_791 env_t_791_value = make_env_t_791(one_w_s); closure_t closure754 = make_closure(lambda791, &env_t_791_value);
	env_t_792 env_t_792_value = make_empty_env(); closure_t closure757 = make_closure(lambda792, &env_t_792_value);
	macroDef758 = TOP_LEVEL_linalg_vectorMap_s(stgVar689, closure754, TOP_LEVEL_linalg_vectorRange_s(stgVar691, oneCard_s, p_s, oneCard_c, p_c), closure757, TOP_LEVEL_linalg_vectorRange_c(oneCard_c, p_c));;
	free(stgVar691);
	array_number_t w_s = macroDef758;
	vector_shape_t one_feat_c = TOP_LEVEL_linalg_vectorRead_c(0, 0);
	array_number_t stgVar695 = malloc(width_vector_shape_t(one_feat_c));
	array_array_number_t macroDef780;array_number_t one_feat_s = TOP_LEVEL_linalg_vectorRead_s(stgVar695, fn_s, 4, 0, 0);
	env_t_793 env_t_793_value = make_env_t_793(one_feat_c); closure_t closure762 = make_closure(lambda793, &env_t_793_value);
	matrix_shape_t feat_c = TOP_LEVEL_linalg_vectorMapToMatrix_c(closure762, TOP_LEVEL_linalg_vectorRange_c(oneCard_c, p_c));
	array_number_t stgVar698 = malloc(width_matrix_shape_t(feat_c));
	array_array_number_t macroDef779;array_number_t stgVar700 = malloc(width_vector_shape_t(TOP_LEVEL_linalg_vectorRange_c(oneCard_c, p_c)));
	array_array_number_t macroDef771;env_t_794 env_t_794_value = make_env_t_794(one_feat_s); closure_t closure766 = make_closure(lambda794, &env_t_794_value);
	env_t_795 env_t_795_value = make_env_t_795(one_feat_c); closure_t closure770 = make_closure(lambda795, &env_t_795_value);
	macroDef771 = TOP_LEVEL_linalg_vectorMapToMatrix_s(stgVar698, closure766, TOP_LEVEL_linalg_vectorRange_s(stgVar700, oneCard_s, p_s, oneCard_c, p_c), closure770, TOP_LEVEL_linalg_vectorRange_c(oneCard_c, p_c));;
	free(stgVar700);
	array_array_number_t feat_s = macroDef771;
	env_t_796 env_t_796_value = make_empty_env(); closure_t closure774 = make_closure(lambda796, &env_t_796_value);
	matrix_shape_t obs_c = nested_shape_vector_shape_t(closure774.lam(closure774.env, 0).vector_shape_t_value, p_c);
	array_number_t stgVar704 = malloc(width_matrix_shape_t(obs_c));
	array_array_number_t macroDef778;array_array_number_t macroDef776 = (array_array_number_t)stgVar704;
		macroDef776->length=p_s;
		macroDef776->arr=(array_number_t*)((char*)macroDef776 + VECTOR_HEADER_BYTES);
		storage_t stgVar705 = ((char*)macroDef776 + MATRIX_HEADER_BYTES(p_s));
		for(int x_s = 0; x_s < macroDef776->length; x_s++){
			array_number_t macroDef775 = (array_number_t)stgVar705;
	macroDef775->length=2;
	macroDef775->arr=(number_t*)((char*)stgVar705 + VECTOR_HEADER_BYTES);
	macroDef775->arr[0] = (double)(((int)(x_s)) % ((n_s)));
	macroDef775->arr[1] = (double)(((int)(x_s)) % ((m_s)));;
			macroDef776->arr[x_s] = macroDef775;;
			stgVar705 = (char*)stgVar705 + VECTOR_ALL_BYTES(macroDef776->arr[x_s]->length);
		}
	array_array_number_t obs_s = macroDef776;
	card_t t_c = 0;
	timer_t t_s = tic();
	matrix_shape_t res_c = TOP_LEVEL_usecases_ba_reproj_err_c(cam_c, x_c, w_c, obs_c, feat_c);
	array_number_t stgVar709 = malloc(width_matrix_shape_t(res_c));
	array_array_number_t macroDef777;array_array_number_t res_s = TOP_LEVEL_usecases_ba_reproj_err_s(stgVar709, cam_s, x_s, w_s, obs_s, feat_s, cam_c, x_c, w_c, obs_c, feat_c);
	toc(t_s);
	macroDef777 = res_s;;
	free(stgVar709);
	macroDef778 = macroDef777;;
	free(stgVar704);
	macroDef779 = macroDef778;;
	free(stgVar698);
	macroDef780 = macroDef779;;
	free(stgVar695);
	macroDef781 = macroDef780;;
	free(stgVar689);
	macroDef782 = macroDef781;;
	free(stgVar686);
	macroDef783 = macroDef782;;
	free(stgVar684);
	macroDef784 = macroDef783;;
	free(stgVar681);
	macroDef785 = macroDef784;;
	free(stgVar679);
	macroDef786 = macroDef785;;
	free(stgVar676);
	return macroDef786;
}

card_t TOP_LEVEL_usecases_ba_test_ba_c(vector_shape_t dum_c) {
	
	return 0;
}


void TOP_LEVEL_usecases_ba_test_ba_s(storage_t stgVar797, array_number_t dum_s, vector_shape_t dum_c) {
	vector_shape_t a_c = nested_shape_card_t(0, 3);
	array_number_t stgVar798 = malloc(width_vector_shape_t(a_c));
	array_number_t macroDef831 = (array_number_t)stgVar798;
	macroDef831->length=3;
	macroDef831->arr=(number_t*)((char*)stgVar798 + VECTOR_HEADER_BYTES);
	macroDef831->arr[0] = 1;
	macroDef831->arr[1] = 2;
	macroDef831->arr[2] = 3;;
	array_number_t a_s = macroDef831;
	vector_shape_t b_c = nested_shape_card_t(0, 3);
	array_number_t stgVar802 = malloc(width_vector_shape_t(b_c));
	array_number_t macroDef832 = (array_number_t)stgVar802;
	macroDef832->length=3;
	macroDef832->arr=(number_t*)((char*)stgVar802 + VECTOR_HEADER_BYTES);
	macroDef832->arr[0] = 5;
	macroDef832->arr[1] = 6;
	macroDef832->arr[2] = 7;;
	array_number_t b_s = macroDef832;
	array_print(a_s);
	array_print(b_s);
	vector_shape_t j_c = TOP_LEVEL_usecases_ba_radial_distort_c(a_c, b_c);
	array_number_t stgVar806 = malloc(width_vector_shape_t(j_c));
	array_number_t j_s = TOP_LEVEL_usecases_ba_radial_distort_s(stgVar806, a_s, b_s, a_c, b_c);
	array_print(j_s);
	vector_shape_t k_c = TOP_LEVEL_usecases_ba_rodrigues_rotate_point_c(a_c, b_c);
	array_number_t stgVar809 = malloc(width_vector_shape_t(k_c));
	array_number_t k_s = TOP_LEVEL_usecases_ba_rodrigues_rotate_point_s(stgVar809, a_s, b_s, a_c, b_c);
	array_print(k_s);
	vector_shape_t l_c = TOP_LEVEL_linalg_vectorSlice_c(2, 0, k_c);
	array_number_t stgVar812 = malloc(width_vector_shape_t(l_c));
	array_number_t l_s = TOP_LEVEL_linalg_vectorSlice_s(stgVar812, 2, 1, k_s, 2, 0, k_c);
	array_print(l_s);
	vector_shape_t cam_c = nested_shape_card_t(0, 11);
	array_number_t stgVar816 = malloc(width_vector_shape_t(cam_c));
	array_number_t macroDef833 = (array_number_t)stgVar816;
	macroDef833->length=11;
	macroDef833->arr=(number_t*)((char*)stgVar816 + VECTOR_HEADER_BYTES);
	macroDef833->arr[0] = 0;
	macroDef833->arr[1] = 2;
	macroDef833->arr[2] = 4;
	macroDef833->arr[3] = 6;
	macroDef833->arr[4] = 8;
	macroDef833->arr[5] = 10;
	macroDef833->arr[6] = 12;
	macroDef833->arr[7] = 14;
	macroDef833->arr[8] = 16;
	macroDef833->arr[9] = 18;
	macroDef833->arr[10] = 20;;
	array_number_t cam_s = macroDef833;
	vector_shape_t m_c = TOP_LEVEL_usecases_ba_project_c(cam_c, j_c);
	array_number_t stgVar828 = malloc(width_vector_shape_t(m_c));
	array_number_t m_s = TOP_LEVEL_usecases_ba_project_s(stgVar828, cam_s, j_s, cam_c, j_c);
	array_print(m_s);
	;
	free(stgVar828);
	;
	free(stgVar816);
	;
	free(stgVar812);
	;
	free(stgVar809);
	;
	free(stgVar806);
	;
	free(stgVar802);
	;
	free(stgVar798);
	return ;
}
#endif
