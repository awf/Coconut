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
typedef struct env_t_739 {
	vector_shape_t one_cam_c;
} env_t_739;
env_t_739 make_env_t_739(vector_shape_t one_cam_c) {
	env_t_739 env;
	env.one_cam_c = one_cam_c;
	return env;
}

value_t lambda739(env_t_739* env722, card_t x_c) {
	vector_shape_t one_cam_c721 = env722->one_cam_c;
	value_t res;
	res.vector_shape_t_value = one_cam_c721;
	return res;
}
typedef struct env_t_740 {
	vector_shape_t one_x_c;
} env_t_740;
env_t_740 make_env_t_740(vector_shape_t one_x_c) {
	env_t_740 env;
	env.one_x_c = one_x_c;
	return env;
}

value_t lambda740(env_t_740* env726, card_t x_c) {
	vector_shape_t one_x_c725 = env726->one_x_c;
	value_t res;
	res.vector_shape_t_value = one_x_c725;
	return res;
}
typedef empty_env_t env_t_741;


value_t lambda741(env_t_741* env729, card_t x_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef struct env_t_742 {
	vector_shape_t one_feat_c;
} env_t_742;
env_t_742 make_env_t_742(vector_shape_t one_feat_c) {
	env_t_742 env;
	env.one_feat_c = one_feat_c;
	return env;
}

value_t lambda742(env_t_742* env733, card_t x_c) {
	vector_shape_t one_feat_c732 = env733->one_feat_c;
	value_t res;
	res.vector_shape_t_value = one_feat_c732;
	return res;
}
typedef empty_env_t env_t_743;


value_t lambda743(env_t_743* env736, card_t x_c) {
	
	value_t res;
	res.vector_shape_t_value = nested_shape_card_t(0, 2);
	return res;
}
matrix_shape_t TOP_LEVEL_usecases_ba_run_ba_from_file_c(card_t fn_c) {
	vector_shape_t nmp_c = TOP_LEVEL_linalg_vectorRead_c(0, 0);
	card_t oneCard_c = 1;
	vector_shape_t one_cam_c = TOP_LEVEL_linalg_vectorRead_c(0, 0);
	env_t_739 env_t_739_value = make_env_t_739(one_cam_c); closure_t closure724 = make_closure(lambda739, &env_t_739_value);
	vector_shape_t one_x_c = TOP_LEVEL_linalg_vectorRead_c(0, 0);
	env_t_740 env_t_740_value = make_env_t_740(one_x_c); closure_t closure728 = make_closure(lambda740, &env_t_740_value);
	card_t one_w_c = 0;
	env_t_741 env_t_741_value = make_empty_env(); closure_t closure731 = make_closure(lambda741, &env_t_741_value);
	vector_shape_t one_feat_c = TOP_LEVEL_linalg_vectorRead_c(0, 0);
	env_t_742 env_t_742_value = make_env_t_742(one_feat_c); closure_t closure735 = make_closure(lambda742, &env_t_742_value);
	env_t_743 env_t_743_value = make_empty_env(); closure_t closure738 = make_closure(lambda743, &env_t_743_value);
	card_t t_c = 0;
	card_t n_c = (int)(nmp_s->arr[0]);
	card_t m_c = (int)(nmp_s->arr[1]);
	card_t p_c = (int)(nmp_s->arr[2]);
	matrix_shape_t cam_c = nested_shape_vector_shape_t(closure724.lam(closure724.env, 0).vector_shape_t_value, n_c);
	matrix_shape_t x_c = nested_shape_vector_shape_t(closure728.lam(closure728.env, 0).vector_shape_t_value, m_c);
	vector_shape_t w_c = TOP_LEVEL_linalg_vectorMap_c(closure731, TOP_LEVEL_linalg_vectorRange_c(oneCard_c, p_c));
	matrix_shape_t feat_c = TOP_LEVEL_linalg_vectorMapToMatrix_c(closure735, TOP_LEVEL_linalg_vectorRange_c(oneCard_c, p_c));
	matrix_shape_t obs_c = nested_shape_vector_shape_t(closure738.lam(closure738.env, 0).vector_shape_t_value, p_c);
	matrix_shape_t res_c = TOP_LEVEL_usecases_ba_reproj_err_c(cam_c, x_c, w_c, obs_c, feat_c);
	return res_c;
}

typedef struct env_t_795 {
	vector_shape_t one_cam_c;
} env_t_795;
env_t_795 make_env_t_795(vector_shape_t one_cam_c) {
	env_t_795 env;
	env.one_cam_c = one_cam_c;
	return env;
}

value_t lambda795(env_t_795* env745, card_t x_c) {
	vector_shape_t one_cam_c744 = env745->one_cam_c;
	value_t res;
	res.vector_shape_t_value = one_cam_c744;
	return res;
}
typedef struct env_t_796 {
	vector_shape_t one_x_c;
} env_t_796;
env_t_796 make_env_t_796(vector_shape_t one_x_c) {
	env_t_796 env;
	env.one_x_c = one_x_c;
	return env;
}

value_t lambda796(env_t_796* env750, card_t x_c) {
	vector_shape_t one_x_c749 = env750->one_x_c;
	value_t res;
	res.vector_shape_t_value = one_x_c749;
	return res;
}
typedef empty_env_t env_t_797;


value_t lambda797(env_t_797* env754, card_t x_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef struct env_t_798 {
	number_t one_w_s;
} env_t_798;
env_t_798 make_env_t_798(number_t one_w_s) {
	env_t_798 env;
	env.one_w_s = one_w_s;
	return env;
}

value_t lambda798(env_t_798* env758, storage_t stgVar698, number_t x_s, card_t x_c) {
	number_t one_w_s757 = env758->one_w_s;
	value_t res;
	res.number_t_value = one_w_s757;
	return res;
}
typedef empty_env_t env_t_799;


value_t lambda799(env_t_799* env761, card_t x_c) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef struct env_t_800 {
	vector_shape_t one_feat_c;
} env_t_800;
env_t_800 make_env_t_800(vector_shape_t one_feat_c) {
	env_t_800 env;
	env.one_feat_c = one_feat_c;
	return env;
}

value_t lambda800(env_t_800* env766, card_t x_c) {
	vector_shape_t one_feat_c765 = env766->one_feat_c;
	value_t res;
	res.vector_shape_t_value = one_feat_c765;
	return res;
}
typedef empty_env_t env_t_801;


value_t lambda801(env_t_801* env778, card_t x_c) {
	
	value_t res;
	res.vector_shape_t_value = nested_shape_card_t(0, 2);
	return res;
}
typedef struct env_t_802 {
	array_number_t one_feat_s;
} env_t_802;
env_t_802 make_env_t_802(array_number_t one_feat_s) {
	env_t_802 env;
	env.one_feat_s = one_feat_s;
	return env;
}

value_t lambda802(env_t_802* env770, storage_t stgVar707, number_t x_s, card_t x_c) {
	array_number_t one_feat_s769 = env770->one_feat_s;
	value_t res;
	res.array_number_t_value = one_feat_s769;
	return res;
}
typedef struct env_t_803 {
	vector_shape_t one_feat_c;
} env_t_803;
env_t_803 make_env_t_803(vector_shape_t one_feat_c) {
	env_t_803 env;
	env.one_feat_c = one_feat_c;
	return env;
}

value_t lambda803(env_t_803* env774, card_t x_c) {
	vector_shape_t one_feat_c773 = env774->one_feat_c;
	value_t res;
	res.vector_shape_t_value = one_feat_c773;
	return res;
}
array_array_number_t TOP_LEVEL_usecases_ba_run_ba_from_file_s(storage_t stgVar674, string_t fn_s, card_t fn_c) {
	vector_shape_t nmp_c = TOP_LEVEL_linalg_vectorRead_c(0, 0);
	array_number_t stgVar675 = malloc(width_vector_shape_t(nmp_c));
	array_array_number_t macroDef793;array_number_t nmp_s = TOP_LEVEL_linalg_vectorRead_s(stgVar675, fn_s, 0, 0, 0);
	card_t oneCard_c = 1;
	card_t oneCard_s = 1;
	vector_shape_t one_cam_c = TOP_LEVEL_linalg_vectorRead_c(0, 0);
	card_t n_c = (int)(nmp_s->arr[0]);
	card_t n_s = (int)(nmp_s->arr[0]);
	card_t m_c = (int)(nmp_s->arr[1]);
	card_t m_s = (int)(nmp_s->arr[1]);
	card_t p_c = (int)(nmp_s->arr[2]);
	card_t p_s = (int)(nmp_s->arr[2]);
	array_number_t stgVar682 = malloc(width_vector_shape_t(one_cam_c));
	array_array_number_t macroDef792;array_number_t one_cam_s = TOP_LEVEL_linalg_vectorRead_s(stgVar682, fn_s, 1, 0, 0);
	env_t_795 env_t_795_value = make_env_t_795(one_cam_c); closure_t closure747 = make_closure(lambda795, &env_t_795_value);
	matrix_shape_t cam_c = nested_shape_vector_shape_t(closure747.lam(closure747.env, 0).vector_shape_t_value, n_c);
	array_number_t stgVar685 = malloc(width_matrix_shape_t(cam_c));
	array_array_number_t macroDef791;vector_shape_t one_x_c = TOP_LEVEL_linalg_vectorRead_c(0, 0);
	array_array_number_t macroDef748 = (array_array_number_t)stgVar685;
		macroDef748->length=n_s;
		macroDef748->arr=(array_number_t*)((char*)macroDef748 + VECTOR_HEADER_BYTES);
		storage_t stgVar686 = ((char*)macroDef748 + MATRIX_HEADER_BYTES(n_s));
		for(int x_s = 0; x_s < macroDef748->length; x_s++){
			
			macroDef748->arr[x_s] = one_cam_s;;
			stgVar686 = (char*)stgVar686 + VECTOR_ALL_BYTES(macroDef748->arr[x_s]->length);
		}
	array_array_number_t cam_s = macroDef748;
	array_number_t stgVar687 = malloc(width_vector_shape_t(one_x_c));
	array_array_number_t macroDef790;array_number_t one_x_s = TOP_LEVEL_linalg_vectorRead_s(stgVar687, fn_s, 2, 0, 0);
	env_t_796 env_t_796_value = make_env_t_796(one_x_c); closure_t closure752 = make_closure(lambda796, &env_t_796_value);
	matrix_shape_t x_c = nested_shape_vector_shape_t(closure752.lam(closure752.env, 0).vector_shape_t_value, m_c);
	array_number_t stgVar690 = malloc(width_matrix_shape_t(x_c));
	array_array_number_t macroDef789;card_t one_w_c = 0;
	array_array_number_t macroDef753 = (array_array_number_t)stgVar690;
		macroDef753->length=m_s;
		macroDef753->arr=(array_number_t*)((char*)macroDef753 + VECTOR_HEADER_BYTES);
		storage_t stgVar691 = ((char*)macroDef753 + MATRIX_HEADER_BYTES(m_s));
		for(int x_s = 0; x_s < macroDef753->length; x_s++){
			
			macroDef753->arr[x_s] = one_x_s;;
			stgVar691 = (char*)stgVar691 + VECTOR_ALL_BYTES(macroDef753->arr[x_s]->length);
		}
	array_array_number_t x_s = macroDef753;
	array_number_t stgVar692 = malloc(one_w_c);
	array_array_number_t macroDef788;number_t one_w_s = TOP_LEVEL_linalg_numberRead_s(stgVar692, fn_s, 3, 0, 0);
	env_t_797 env_t_797_value = make_empty_env(); closure_t closure756 = make_closure(lambda797, &env_t_797_value);
	vector_shape_t w_c = TOP_LEVEL_linalg_vectorMap_c(closure756, TOP_LEVEL_linalg_vectorRange_c(oneCard_c, p_c));
	array_number_t stgVar695 = malloc(width_vector_shape_t(w_c));
	array_array_number_t macroDef787;vector_shape_t one_feat_c = TOP_LEVEL_linalg_vectorRead_c(0, 0);
	array_number_t stgVar697 = malloc(width_vector_shape_t(TOP_LEVEL_linalg_vectorRange_c(oneCard_c, p_c)));
	array_number_t macroDef764;env_t_798 env_t_798_value = make_env_t_798(one_w_s); closure_t closure760 = make_closure(lambda798, &env_t_798_value);
	env_t_799 env_t_799_value = make_empty_env(); closure_t closure763 = make_closure(lambda799, &env_t_799_value);
	macroDef764 = TOP_LEVEL_linalg_vectorMap_s(stgVar695, closure760, TOP_LEVEL_linalg_vectorRange_s(stgVar697, oneCard_s, p_s, oneCard_c, p_c), closure763, TOP_LEVEL_linalg_vectorRange_c(oneCard_c, p_c));;
	free(stgVar697);
	array_number_t w_s = macroDef764;
	array_number_t stgVar701 = malloc(width_vector_shape_t(one_feat_c));
	array_array_number_t macroDef786;array_number_t one_feat_s = TOP_LEVEL_linalg_vectorRead_s(stgVar701, fn_s, 4, 0, 0);
	env_t_800 env_t_800_value = make_env_t_800(one_feat_c); closure_t closure768 = make_closure(lambda800, &env_t_800_value);
	matrix_shape_t feat_c = TOP_LEVEL_linalg_vectorMapToMatrix_c(closure768, TOP_LEVEL_linalg_vectorRange_c(oneCard_c, p_c));
	array_number_t stgVar704 = malloc(width_matrix_shape_t(feat_c));
	array_array_number_t macroDef785;env_t_801 env_t_801_value = make_empty_env(); closure_t closure780 = make_closure(lambda801, &env_t_801_value);
	array_number_t stgVar706 = malloc(width_vector_shape_t(TOP_LEVEL_linalg_vectorRange_c(oneCard_c, p_c)));
	array_array_number_t macroDef777;env_t_802 env_t_802_value = make_env_t_802(one_feat_s); closure_t closure772 = make_closure(lambda802, &env_t_802_value);
	env_t_803 env_t_803_value = make_env_t_803(one_feat_c); closure_t closure776 = make_closure(lambda803, &env_t_803_value);
	macroDef777 = TOP_LEVEL_linalg_vectorMapToMatrix_s(stgVar704, closure772, TOP_LEVEL_linalg_vectorRange_s(stgVar706, oneCard_s, p_s, oneCard_c, p_c), closure776, TOP_LEVEL_linalg_vectorRange_c(oneCard_c, p_c));;
	free(stgVar706);
	array_array_number_t feat_s = macroDef777;
	matrix_shape_t obs_c = nested_shape_vector_shape_t(closure780.lam(closure780.env, 0).vector_shape_t_value, p_c);
	array_number_t stgVar710 = malloc(width_matrix_shape_t(obs_c));
	array_array_number_t macroDef784;card_t t_c = 0;
	timer_t t_s = tic();
	array_array_number_t macroDef782 = (array_array_number_t)stgVar710;
		macroDef782->length=p_s;
		macroDef782->arr=(array_number_t*)((char*)macroDef782 + VECTOR_HEADER_BYTES);
		storage_t stgVar711 = ((char*)macroDef782 + MATRIX_HEADER_BYTES(p_s));
		for(int x_s = 0; x_s < macroDef782->length; x_s++){
			array_number_t macroDef781 = (array_number_t)stgVar711;
	macroDef781->length=2;
	macroDef781->arr=(number_t*)((char*)stgVar711 + VECTOR_HEADER_BYTES);
	macroDef781->arr[0] = (double)(((int)(x_s)) % ((n_s)));
	macroDef781->arr[1] = (double)(((int)(x_s)) % ((m_s)));;
			macroDef782->arr[x_s] = macroDef781;;
			stgVar711 = (char*)stgVar711 + VECTOR_ALL_BYTES(macroDef782->arr[x_s]->length);
		}
	array_array_number_t obs_s = macroDef782;
	matrix_shape_t res_c = TOP_LEVEL_usecases_ba_reproj_err_c(cam_c, x_c, w_c, obs_c, feat_c);
	array_number_t stgVar715 = malloc(width_matrix_shape_t(res_c));
	array_array_number_t macroDef783;array_array_number_t res_s = TOP_LEVEL_usecases_ba_reproj_err_s(stgVar715, cam_s, x_s, w_s, obs_s, feat_s, cam_c, x_c, w_c, obs_c, feat_c);
	toc(t);
	macroDef783 = res_s;;
	free(stgVar715);
	macroDef784 = macroDef783;;
	free(stgVar710);
	macroDef785 = macroDef784;;
	free(stgVar704);
	macroDef786 = macroDef785;;
	free(stgVar701);
	macroDef787 = macroDef786;;
	free(stgVar695);
	macroDef788 = macroDef787;;
	free(stgVar692);
	macroDef789 = macroDef788;;
	free(stgVar690);
	macroDef790 = macroDef789;;
	free(stgVar687);
	macroDef791 = macroDef790;;
	free(stgVar685);
	macroDef792 = macroDef791;;
	free(stgVar682);
	macroDef793 = macroDef792;;
	free(stgVar675);
	return macroDef793;
}

card_t TOP_LEVEL_usecases_ba_test_ba_c(vector_shape_t dum_c) {
	
	return 0;
}


void TOP_LEVEL_usecases_ba_test_ba_s(storage_t stgVar804, array_number_t dum_s, vector_shape_t dum_c) {
	vector_shape_t a_c = nested_shape_card_t(0, 3);
	array_number_t stgVar805 = malloc(width_vector_shape_t(a_c));
	array_number_t macroDef838 = (array_number_t)stgVar805;
	macroDef838->length=3;
	macroDef838->arr=(number_t*)((char*)stgVar805 + VECTOR_HEADER_BYTES);
	macroDef838->arr[0] = 1;
	macroDef838->arr[1] = 2;
	macroDef838->arr[2] = 3;;
	array_number_t a_s = macroDef838;
	vector_shape_t b_c = nested_shape_card_t(0, 3);
	array_number_t stgVar809 = malloc(width_vector_shape_t(b_c));
	array_number_t macroDef839 = (array_number_t)stgVar809;
	macroDef839->length=3;
	macroDef839->arr=(number_t*)((char*)stgVar809 + VECTOR_HEADER_BYTES);
	macroDef839->arr[0] = 5;
	macroDef839->arr[1] = 6;
	macroDef839->arr[2] = 7;;
	array_number_t b_s = macroDef839;
	array_print(a_s);
	array_print(b_s);
	vector_shape_t j_c = TOP_LEVEL_usecases_ba_radial_distort_c(a_c, b_c);
	array_number_t stgVar813 = malloc(width_vector_shape_t(j_c));
	array_number_t j_s = TOP_LEVEL_usecases_ba_radial_distort_s(stgVar813, a_s, b_s, a_c, b_c);
	array_print(j_s);
	vector_shape_t k_c = TOP_LEVEL_usecases_ba_rodrigues_rotate_point_c(a_c, b_c);
	array_number_t stgVar816 = malloc(width_vector_shape_t(k_c));
	array_number_t k_s = TOP_LEVEL_usecases_ba_rodrigues_rotate_point_s(stgVar816, a_s, b_s, a_c, b_c);
	array_print(k_s);
	vector_shape_t l_c = TOP_LEVEL_linalg_vectorSlice_c(2, 0, k_c);
	array_number_t stgVar819 = malloc(width_vector_shape_t(l_c));
	array_number_t l_s = TOP_LEVEL_linalg_vectorSlice_s(stgVar819, 2, 1, k_s, 2, 0, k_c);
	array_print(l_s);
	vector_shape_t cam_c = nested_shape_card_t(0, 11);
	array_number_t stgVar823 = malloc(width_vector_shape_t(cam_c));
	array_number_t macroDef840 = (array_number_t)stgVar823;
	macroDef840->length=11;
	macroDef840->arr=(number_t*)((char*)stgVar823 + VECTOR_HEADER_BYTES);
	macroDef840->arr[0] = 0;
	macroDef840->arr[1] = 2;
	macroDef840->arr[2] = 4;
	macroDef840->arr[3] = 6;
	macroDef840->arr[4] = 8;
	macroDef840->arr[5] = 10;
	macroDef840->arr[6] = 12;
	macroDef840->arr[7] = 14;
	macroDef840->arr[8] = 16;
	macroDef840->arr[9] = 18;
	macroDef840->arr[10] = 20;;
	array_number_t cam_s = macroDef840;
	vector_shape_t m_c = TOP_LEVEL_usecases_ba_project_c(cam_c, j_c);
	array_number_t stgVar835 = malloc(width_vector_shape_t(m_c));
	array_number_t m_s = TOP_LEVEL_usecases_ba_project_s(stgVar835, cam_s, j_s, cam_c, j_c);
	array_print(m_s);
	;
	free(stgVar835);
	;
	free(stgVar823);
	;
	free(stgVar819);
	;
	free(stgVar816);
	;
	free(stgVar813);
	;
	free(stgVar809);
	;
	free(stgVar805);
	return ;
}
#endif
