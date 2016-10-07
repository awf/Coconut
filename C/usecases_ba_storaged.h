#ifndef __USECASES_BA_STORAGED_H__ 
#define __USECASES_BA_STORAGED_H__ 
#include "runtime/fsharp.h"
#include <stdio.h>
#include <math.h>
#include "linalg_storaged.h"

card_t TOP_LEVEL_usecases_ba_radial_distort_shp(card_t rad_params_shp, card_t proj_shp) {
	
	return TOP_LEVEL_linalg_mult_by_scalar_shp(proj_shp, 0);
}


array_number_t TOP_LEVEL_usecases_ba_radial_distort_dps(storage_t stgVar663, array_number_t rad_params_dps, array_number_t proj_dps, card_t rad_params_shp, card_t proj_shp) {
	card_t rsq_shp = 0;
	number_t rsq_dps = TOP_LEVEL_linalg_sqnorm_dps(empty_storage, proj_dps, proj_shp);
	card_t L_shp = 0;
	number_t L_dps = ((1) + ((rad_params_dps->arr[0]) * (rsq_dps))) + (((rad_params_dps->arr[1]) * (rsq_dps)) * (rsq_dps));
	return TOP_LEVEL_linalg_mult_by_scalar_dps(stgVar663, proj_dps, L_dps, proj_shp, 0);
}

card_t TOP_LEVEL_usecases_ba_rodrigues_rotate_point_shp(card_t rot_shp, card_t x_shp) {
	
	return TOP_LEVEL_linalg_vectorAdd_shp(TOP_LEVEL_linalg_vectorAdd_shp(TOP_LEVEL_linalg_mult_by_scalar_shp(x_shp, 0), TOP_LEVEL_linalg_mult_by_scalar_shp(TOP_LEVEL_linalg_cross_shp(TOP_LEVEL_linalg_mult_by_scalar_shp(rot_shp, 0), x_shp), 0)), TOP_LEVEL_linalg_mult_by_scalar_shp(TOP_LEVEL_linalg_mult_by_scalar_shp(rot_shp, 0), 0));
}


array_number_t TOP_LEVEL_usecases_ba_rodrigues_rotate_point_dps(storage_t stgVar673, array_number_t rot_dps, array_number_t x_dps, card_t rot_shp, card_t x_shp) {
	card_t sqtheta_shp = 0;
	number_t sqtheta_dps = TOP_LEVEL_linalg_sqnorm_dps(empty_storage, rot_dps, rot_shp);
	array_number_t ite802 = 0;
	if((sqtheta_dps) != (0)) {
		card_t theta_shp = 0;
		number_t theta_dps = sqrt(sqtheta_dps);
		card_t costheta_shp = 0;
		number_t costheta_dps = cos(theta_dps);
		card_t sintheta_shp = 0;
		number_t sintheta_dps = sin(theta_dps);
		card_t theta_inv_shp = 0;
		number_t theta_inv_dps = (1) / (theta_dps);
		card_t w_shp = TOP_LEVEL_linalg_mult_by_scalar_shp(rot_shp, 0);
		card_t size808 = width_card_t(w_shp);
	array_number_t stgVar680 = storage_alloc(size808);
	array_number_t macroDef800;array_number_t w_dps = TOP_LEVEL_linalg_mult_by_scalar_dps(stgVar680, rot_dps, theta_inv_dps, rot_shp, 0);
	card_t w_cross_X_shp = TOP_LEVEL_linalg_cross_shp(w_shp, x_shp);
	card_t size807 = width_card_t(w_cross_X_shp);
	array_number_t stgVar683 = storage_alloc(size807);
	array_number_t macroDef799;array_number_t w_cross_X_dps = TOP_LEVEL_linalg_cross_dps(stgVar683, w_dps, x_dps, w_shp, x_shp);
	card_t tmp_shp = 0;
	number_t tmp_dps = (TOP_LEVEL_linalg_dot_prod_dps(empty_storage, w_dps, x_dps, w_shp, x_shp)) * ((1) - (costheta_dps));
	card_t v1_shp = TOP_LEVEL_linalg_mult_by_scalar_shp(x_shp, 0);
	card_t size806 = width_card_t(v1_shp);
	array_number_t stgVar689 = storage_alloc(size806);
	array_number_t macroDef798;array_number_t v1_dps = TOP_LEVEL_linalg_mult_by_scalar_dps(stgVar689, x_dps, costheta_dps, x_shp, 0);
	card_t v2_shp = TOP_LEVEL_linalg_mult_by_scalar_shp(w_cross_X_shp, 0);
	card_t size805 = width_card_t(v2_shp);
	array_number_t stgVar692 = storage_alloc(size805);
	array_number_t macroDef797;array_number_t v2_dps = TOP_LEVEL_linalg_mult_by_scalar_dps(stgVar692, w_cross_X_dps, sintheta_dps, w_cross_X_shp, 0);
	card_t size804 = width_card_t(TOP_LEVEL_linalg_mult_by_scalar_shp(w_shp, 0));
	array_number_t stgVar696 = storage_alloc(size804);
	array_number_t macroDef796;card_t size803 = width_card_t(TOP_LEVEL_linalg_vectorAdd_shp(v1_shp, v2_shp));
	array_number_t stgVar695 = storage_alloc(size803);
	array_number_t macroDef795;
	macroDef795 = TOP_LEVEL_linalg_vectorAdd_dps(stgVar673, TOP_LEVEL_linalg_vectorAdd_dps(stgVar695, v1_dps, v2_dps, v1_shp, v2_shp), TOP_LEVEL_linalg_mult_by_scalar_dps(stgVar696, w_dps, tmp_dps, w_shp, 0), TOP_LEVEL_linalg_vectorAdd_shp(v1_shp, v2_shp), TOP_LEVEL_linalg_mult_by_scalar_shp(w_shp, 0));;
	storage_free(stgVar695, size803);
	macroDef796 = macroDef795;;
	storage_free(stgVar696, size804);
	macroDef797 = macroDef796;;
	storage_free(stgVar692, size805);
	macroDef798 = macroDef797;;
	storage_free(stgVar689, size806);
	macroDef799 = macroDef798;;
	storage_free(stgVar683, size807);
	macroDef800 = macroDef799;;
	storage_free(stgVar680, size808);
		ite802 = macroDef800;;
	} else {
		card_t size809 = width_card_t(TOP_LEVEL_linalg_cross_shp(rot_shp, x_shp));
	array_number_t stgVar702 = storage_alloc(size809);
	array_number_t macroDef801;
	macroDef801 = TOP_LEVEL_linalg_vectorAdd_dps(stgVar673, x_dps, TOP_LEVEL_linalg_cross_dps(stgVar702, rot_dps, x_dps, rot_shp, x_shp), x_shp, TOP_LEVEL_linalg_cross_shp(rot_shp, x_shp));;
	storage_free(stgVar702, size809);
		ite802 = macroDef801;;
	}
	return ite802;
}

card_t TOP_LEVEL_usecases_ba_project_shp(card_t cam_shp, card_t x_shp) {
	
	return TOP_LEVEL_linalg_vectorAdd_shp(TOP_LEVEL_linalg_vectorSlice_shp(2, 0, cam_shp), TOP_LEVEL_linalg_mult_by_scalar_shp(TOP_LEVEL_usecases_ba_radial_distort_shp(TOP_LEVEL_linalg_vectorSlice_shp(2, 0, cam_shp), TOP_LEVEL_linalg_mult_by_scalar_shp(TOP_LEVEL_linalg_vectorSlice_shp(2, 0, TOP_LEVEL_usecases_ba_rodrigues_rotate_point_shp(TOP_LEVEL_linalg_vectorSlice_shp(3, 0, cam_shp), TOP_LEVEL_linalg_vectorSub_shp(x_shp, TOP_LEVEL_linalg_vectorSlice_shp(3, 0, cam_shp)))), 0)), 0));
}


array_number_t TOP_LEVEL_usecases_ba_project_dps(storage_t stgVar810, array_number_t cam_dps, array_number_t x_dps, card_t cam_shp, card_t x_shp) {
	card_t N_CAM_PARAMS_shp = 0;
	index_t N_CAM_PARAMS_dps = 11;
	card_t ROT_IDX_shp = 0;
	index_t ROT_IDX_dps = 0;
	card_t CENTER_IDX_shp = 0;
	index_t CENTER_IDX_dps = 3;
	card_t FOCAL_IDX_shp = 0;
	index_t FOCAL_IDX_dps = 6;
	card_t X0_IDX_shp = 0;
	index_t X0_IDX_dps = 7;
	card_t RAD_IDX_shp = 0;
	index_t RAD_IDX_dps = 9;
	card_t Xcam_shp = TOP_LEVEL_usecases_ba_rodrigues_rotate_point_shp(TOP_LEVEL_linalg_vectorSlice_shp(3, 0, cam_shp), TOP_LEVEL_linalg_vectorSub_shp(x_shp, TOP_LEVEL_linalg_vectorSlice_shp(3, 0, cam_shp)));
	card_t size923 = width_card_t(Xcam_shp);
	array_number_t stgVar817 = storage_alloc(size923);
	array_number_t macroDef913;card_t size916 = width_card_t(TOP_LEVEL_linalg_vectorSub_shp(x_shp, TOP_LEVEL_linalg_vectorSlice_shp(3, 0, cam_shp)));
	array_number_t stgVar819 = storage_alloc(size916);
	array_number_t macroDef906;card_t size915 = width_card_t(TOP_LEVEL_linalg_vectorSlice_shp(3, 0, cam_shp));
	array_number_t stgVar818 = storage_alloc(size915);
	array_number_t macroDef905;card_t size914 = width_card_t(TOP_LEVEL_linalg_vectorSlice_shp(3, 0, cam_shp));
	array_number_t stgVar824 = storage_alloc(size914);
	array_number_t macroDef904;
	macroDef904 = TOP_LEVEL_linalg_vectorSub_dps(stgVar819, x_dps, TOP_LEVEL_linalg_vectorSlice_dps(stgVar824, 3, CENTER_IDX_dps, cam_dps, 3, 0, cam_shp), x_shp, TOP_LEVEL_linalg_vectorSlice_shp(3, 0, cam_shp));;
	storage_free(stgVar824, size914);
	macroDef905 = TOP_LEVEL_usecases_ba_rodrigues_rotate_point_dps(stgVar817, TOP_LEVEL_linalg_vectorSlice_dps(stgVar818, 3, ROT_IDX_dps, cam_dps, 3, 0, cam_shp), macroDef904, TOP_LEVEL_linalg_vectorSlice_shp(3, 0, cam_shp), TOP_LEVEL_linalg_vectorSub_shp(x_shp, TOP_LEVEL_linalg_vectorSlice_shp(3, 0, cam_shp)));;
	storage_free(stgVar818, size915);
	macroDef906 = macroDef905;;
	storage_free(stgVar819, size916);
	array_number_t Xcam_dps = macroDef906;
	card_t distorted_shp = TOP_LEVEL_usecases_ba_radial_distort_shp(TOP_LEVEL_linalg_vectorSlice_shp(2, 0, cam_shp), TOP_LEVEL_linalg_mult_by_scalar_shp(TOP_LEVEL_linalg_vectorSlice_shp(2, 0, Xcam_shp), 0));
	card_t size922 = width_card_t(distorted_shp);
	array_number_t stgVar828 = storage_alloc(size922);
	array_number_t macroDef912;card_t size919 = width_card_t(TOP_LEVEL_linalg_mult_by_scalar_shp(TOP_LEVEL_linalg_vectorSlice_shp(2, 0, Xcam_shp), 0));
	array_number_t stgVar830 = storage_alloc(size919);
	array_number_t macroDef909;card_t size918 = width_card_t(TOP_LEVEL_linalg_vectorSlice_shp(2, 0, cam_shp));
	array_number_t stgVar829 = storage_alloc(size918);
	array_number_t macroDef908;card_t size917 = width_card_t(TOP_LEVEL_linalg_vectorSlice_shp(2, 0, Xcam_shp));
	array_number_t stgVar834 = storage_alloc(size917);
	array_number_t macroDef907;
	macroDef907 = TOP_LEVEL_linalg_mult_by_scalar_dps(stgVar830, TOP_LEVEL_linalg_vectorSlice_dps(stgVar834, 2, 0, Xcam_dps, 2, 0, Xcam_shp), (1) / (Xcam_dps->arr[2]), TOP_LEVEL_linalg_vectorSlice_shp(2, 0, Xcam_shp), 0);;
	storage_free(stgVar834, size917);
	macroDef908 = TOP_LEVEL_usecases_ba_radial_distort_dps(stgVar828, TOP_LEVEL_linalg_vectorSlice_dps(stgVar829, 2, RAD_IDX_dps, cam_dps, 2, 0, cam_shp), macroDef907, TOP_LEVEL_linalg_vectorSlice_shp(2, 0, cam_shp), TOP_LEVEL_linalg_mult_by_scalar_shp(TOP_LEVEL_linalg_vectorSlice_shp(2, 0, Xcam_shp), 0));;
	storage_free(stgVar829, size918);
	macroDef909 = macroDef908;;
	storage_free(stgVar830, size919);
	array_number_t distorted_dps = macroDef909;
	card_t size921 = width_card_t(TOP_LEVEL_linalg_mult_by_scalar_shp(distorted_shp, 0));
	array_number_t stgVar841 = storage_alloc(size921);
	array_number_t macroDef911;card_t size920 = width_card_t(TOP_LEVEL_linalg_vectorSlice_shp(2, 0, cam_shp));
	array_number_t stgVar840 = storage_alloc(size920);
	array_number_t macroDef910;
	macroDef910 = TOP_LEVEL_linalg_vectorAdd_dps(stgVar810, TOP_LEVEL_linalg_vectorSlice_dps(stgVar840, 2, X0_IDX_dps, cam_dps, 2, 0, cam_shp), TOP_LEVEL_linalg_mult_by_scalar_dps(stgVar841, distorted_dps, cam_dps->arr[FOCAL_IDX_dps], distorted_shp, 0), TOP_LEVEL_linalg_vectorSlice_shp(2, 0, cam_shp), TOP_LEVEL_linalg_mult_by_scalar_shp(distorted_shp, 0));;
	storage_free(stgVar840, size920);
	macroDef911 = macroDef910;;
	storage_free(stgVar841, size921);
	macroDef912 = macroDef911;;
	storage_free(stgVar828, size922);
	macroDef913 = macroDef912;;
	storage_free(stgVar817, size923);
	return macroDef913;
}

card_t TOP_LEVEL_usecases_ba_compute_reproj_err_shp(card_t cam_shp, card_t x_shp, card_t w_shp, card_t feat_shp) {
	
	return TOP_LEVEL_linalg_mult_by_scalar_shp(TOP_LEVEL_linalg_vectorSub_shp(TOP_LEVEL_usecases_ba_project_shp(cam_shp, x_shp), feat_shp), 0);
}


array_number_t TOP_LEVEL_usecases_ba_compute_reproj_err_dps(storage_t stgVar924, array_number_t cam_dps, array_number_t x_dps, number_t w_dps, array_number_t feat_dps, card_t cam_shp, card_t x_shp, card_t w_shp, card_t feat_shp) {
	card_t size934 = width_card_t(TOP_LEVEL_linalg_vectorSub_shp(TOP_LEVEL_usecases_ba_project_shp(cam_shp, x_shp), feat_shp));
	array_number_t stgVar925 = storage_alloc(size934);
	array_number_t macroDef932;card_t size933 = width_card_t(TOP_LEVEL_usecases_ba_project_shp(cam_shp, x_shp));
	array_number_t stgVar927 = storage_alloc(size933);
	array_number_t macroDef931;
	macroDef931 = TOP_LEVEL_linalg_vectorSub_dps(stgVar925, TOP_LEVEL_usecases_ba_project_dps(stgVar927, cam_dps, x_dps, cam_shp, x_shp), feat_dps, TOP_LEVEL_usecases_ba_project_shp(cam_shp, x_shp), feat_shp);;
	storage_free(stgVar927, size933);
	macroDef932 = TOP_LEVEL_linalg_mult_by_scalar_dps(stgVar924, macroDef931, w_dps, TOP_LEVEL_linalg_vectorSub_shp(TOP_LEVEL_usecases_ba_project_shp(cam_shp, x_shp), feat_shp), 0);;
	storage_free(stgVar925, size934);
	return macroDef932;
}

card_t TOP_LEVEL_usecases_ba_compute_zach_weight_error_shp(card_t w_shp) {
	
	return 0;
}


number_t TOP_LEVEL_usecases_ba_compute_zach_weight_error_dps(storage_t stgVar935, number_t w_dps, card_t w_shp) {
	
	return (1) - ((w_dps) * (w_dps));
}
typedef empty_env_t env_t_944;


value_t lambda944(env_t_944* env941, card_t w_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
card_t TOP_LEVEL_usecases_ba_w_err_shp(card_t w_shp) {
	env_t_944 env_t_944_value = make_empty_env(); closure_t closure943 = make_closure(lambda944, &env_t_944_value);
	return TOP_LEVEL_linalg_vectorMap_shp(closure943, w_shp);
}

typedef empty_env_t env_t_951;


value_t lambda951(env_t_951* env945, storage_t stgVar939, number_t w_dps0, card_t w_shp0) {
	
	value_t res;
	res.number_t_value = TOP_LEVEL_usecases_ba_compute_zach_weight_error_dps(stgVar939, w_dps0, 0);
	return res;
}
typedef empty_env_t env_t_952;


value_t lambda952(env_t_952* env948, card_t w_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
array_number_t TOP_LEVEL_usecases_ba_w_err_dps(storage_t stgVar936, array_number_t w_dps, card_t w_shp) {
	env_t_951 env_t_951_value = make_empty_env(); closure_t closure947 = make_closure(lambda951, &env_t_951_value);
	env_t_952 env_t_952_value = make_empty_env(); closure_t closure950 = make_closure(lambda952, &env_t_952_value);
	return TOP_LEVEL_linalg_vectorMap_dps(stgVar936, closure947, w_dps, closure950, w_shp);
}
typedef struct env_t_988 {
	matrix_shape_t x_shp;
	matrix_shape_t feat_shp;
	matrix_shape_t cams_shp;
} env_t_988;
env_t_988 make_env_t_988(matrix_shape_t x_shp,matrix_shape_t feat_shp,matrix_shape_t cams_shp) {
	env_t_988 env;
	env.x_shp = x_shp;
	env.feat_shp = feat_shp;
	env.cams_shp = cams_shp;
	return env;
}

value_t lambda988(env_t_988* env985, card_t i_shp) {
	matrix_shape_t x_shp984 = env985->x_shp;
	matrix_shape_t feat_shp983 = env985->feat_shp;
	matrix_shape_t cams_shp982 = env985->cams_shp;
	value_t res;
	res.card_t_value = TOP_LEVEL_usecases_ba_compute_reproj_err_shp(cams_shp982.elem, x_shp984.elem, 0, feat_shp983.elem);
	return res;
}
matrix_shape_t TOP_LEVEL_usecases_ba_reproj_err_shp(matrix_shape_t cams_shp, matrix_shape_t x_shp, card_t w_shp, matrix_shape_t obs_shp, matrix_shape_t feat_shp) {
	env_t_988 env_t_988_value = make_env_t_988(x_shp,feat_shp,cams_shp); closure_t closure987 = make_closure(lambda988, &env_t_988_value);
	return TOP_LEVEL_linalg_vectorMapToMatrix_shp(closure987, TOP_LEVEL_linalg_vectorRange_shp(0, (w_shp) - (1)));
}

typedef struct env_t_1015 {
	matrix_shape_t x_shp;
	array_array_number_t x_dps;
	array_number_t w_dps;
	matrix_shape_t obs_shp;
	array_array_number_t obs_dps;
	matrix_shape_t feat_shp;
	array_array_number_t feat_dps;
	matrix_shape_t cams_shp;
	array_array_number_t cams_dps;
} env_t_1015;
env_t_1015 make_env_t_1015(matrix_shape_t x_shp,array_array_number_t x_dps,array_number_t w_dps,matrix_shape_t obs_shp,array_array_number_t obs_dps,matrix_shape_t feat_shp,array_array_number_t feat_dps,matrix_shape_t cams_shp,array_array_number_t cams_dps) {
	env_t_1015 env;
	env.x_shp = x_shp;
	env.x_dps = x_dps;
	env.w_dps = w_dps;
	env.obs_shp = obs_shp;
	env.obs_dps = obs_dps;
	env.feat_shp = feat_shp;
	env.feat_dps = feat_dps;
	env.cams_shp = cams_shp;
	env.cams_dps = cams_dps;
	return env;
}

value_t lambda1015(env_t_1015* env1005, storage_t stgVar963, number_t i_dps, card_t i_shp) {
	matrix_shape_t x_shp1004 = env1005->x_shp;
	array_array_number_t x_dps1003 = env1005->x_dps;
	array_number_t w_dps1002 = env1005->w_dps;
	matrix_shape_t obs_shp1001 = env1005->obs_shp;
	array_array_number_t obs_dps1000 = env1005->obs_dps;
	matrix_shape_t feat_shp999 = env1005->feat_shp;
	array_array_number_t feat_dps998 = env1005->feat_dps;
	matrix_shape_t cams_shp997 = env1005->cams_shp;
	array_array_number_t cams_dps996 = env1005->cams_dps;
	card_t size1020 = width_card_t(feat_shp999.elem);
	array_number_t stgVar967 = storage_alloc(size1020);
	array_number_t macroDef995;card_t size1019 = width_card_t(x_shp1004.elem);
	array_number_t stgVar965 = storage_alloc(size1019);
	array_number_t macroDef994;card_t size1018 = width_card_t(cams_shp997.elem);
	array_number_t stgVar964 = storage_alloc(size1018);
	array_number_t macroDef993;card_t size1016 = width_card_t(obs_shp1001.elem);
	array_number_t stgVar969 = storage_alloc(size1016);
	number_t macroDef991;
	macroDef991 = obs_dps1000->arr[(int)(i_dps)]->arr[0];;
	storage_free(stgVar969, size1016);
	card_t size1017 = width_card_t(obs_shp1001.elem);
	array_number_t stgVar972 = storage_alloc(size1017);
	number_t macroDef992;
	macroDef992 = obs_dps1000->arr[(int)(i_dps)]->arr[1];;
	storage_free(stgVar972, size1017);
	macroDef993 = TOP_LEVEL_usecases_ba_compute_reproj_err_dps(stgVar963, cams_dps996->arr[(int)(macroDef991)], x_dps1003->arr[(int)(macroDef992)], w_dps1002->arr[(int)(i_dps)], feat_dps998->arr[(int)(i_dps)], cams_shp997.elem, x_shp1004.elem, 0, feat_shp999.elem);;
	storage_free(stgVar964, size1018);
	macroDef994 = macroDef993;;
	storage_free(stgVar965, size1019);
	macroDef995 = macroDef994;;
	storage_free(stgVar967, size1020);
	value_t res;
	res.array_number_t_value = macroDef995;
	return res;
}
typedef struct env_t_1021 {
	matrix_shape_t x_shp;
	matrix_shape_t feat_shp;
	matrix_shape_t cams_shp;
} env_t_1021;
env_t_1021 make_env_t_1021(matrix_shape_t x_shp,matrix_shape_t feat_shp,matrix_shape_t cams_shp) {
	env_t_1021 env;
	env.x_shp = x_shp;
	env.feat_shp = feat_shp;
	env.cams_shp = cams_shp;
	return env;
}

value_t lambda1021(env_t_1021* env1011, card_t i_shp) {
	matrix_shape_t x_shp1010 = env1011->x_shp;
	matrix_shape_t feat_shp1009 = env1011->feat_shp;
	matrix_shape_t cams_shp1008 = env1011->cams_shp;
	value_t res;
	res.card_t_value = TOP_LEVEL_usecases_ba_compute_reproj_err_shp(cams_shp1008.elem, x_shp1010.elem, 0, feat_shp1009.elem);
	return res;
}
array_array_number_t TOP_LEVEL_usecases_ba_reproj_err_dps(storage_t stgVar953, array_array_number_t cams_dps, array_array_number_t x_dps, array_number_t w_dps, array_array_number_t obs_dps, array_array_number_t feat_dps, matrix_shape_t cams_shp, matrix_shape_t x_shp, card_t w_shp, matrix_shape_t obs_shp, matrix_shape_t feat_shp) {
	card_t n_shp = cams_shp.card;
	card_t macroDef989 = cams_dps->length;
	card_t n_dps = macroDef989;
	card_t p_shp = w_shp;
	card_t macroDef990 = w_dps->length;
	card_t p_dps = macroDef990;
	card_t range_shp = TOP_LEVEL_linalg_vectorRange_shp(0, (p_shp) - (1));
	card_t size1022 = width_card_t(range_shp);
	array_number_t stgVar958 = storage_alloc(size1022);
	array_array_number_t macroDef1014;array_number_t range_dps = TOP_LEVEL_linalg_vectorRange_dps(stgVar958, 0, (p_dps) - (1), 0, (p_shp) - (1));
	env_t_1015 env_t_1015_value = make_env_t_1015(x_shp,x_dps,w_dps,obs_shp,obs_dps,feat_shp,feat_dps,cams_shp,cams_dps); closure_t closure1007 = make_closure(lambda1015, &env_t_1015_value);
	env_t_1021 env_t_1021_value = make_env_t_1021(x_shp,feat_shp,cams_shp); closure_t closure1013 = make_closure(lambda1021, &env_t_1021_value);
	macroDef1014 = TOP_LEVEL_linalg_vectorMapToMatrix_dps(stgVar953, closure1007, range_dps, closure1013, range_shp);;
	storage_free(stgVar958, size1022);
	return macroDef1014;
}

card_t TOP_LEVEL_usecases_ba_run_ba_from_file_shp(card_t fn_shp, card_t n_shp, card_t m_shp, card_t p_shp) {
	
	return 0;
}

typedef struct env_t_1123 {
	card_t one_cam_shp;
} env_t_1123;
env_t_1123 make_env_t_1123(card_t one_cam_shp) {
	env_t_1123 env;
	env.one_cam_shp = one_cam_shp;
	return env;
}

value_t lambda1123(env_t_1123* env1072, card_t x_shp) {
	card_t one_cam_shp1071 = env1072->one_cam_shp;
	value_t res;
	res.card_t_value = one_cam_shp1071;
	return res;
}
typedef struct env_t_1124 {
	card_t one_x_shp;
} env_t_1124;
env_t_1124 make_env_t_1124(card_t one_x_shp) {
	env_t_1124 env;
	env.one_x_shp = one_x_shp;
	return env;
}

value_t lambda1124(env_t_1124* env1077, card_t x_shp) {
	card_t one_x_shp1076 = env1077->one_x_shp;
	value_t res;
	res.card_t_value = one_x_shp1076;
	return res;
}
typedef empty_env_t env_t_1125;


value_t lambda1125(env_t_1125* env1081, card_t x_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef struct env_t_1126 {
	number_t one_w_dps;
} env_t_1126;
env_t_1126 make_env_t_1126(number_t one_w_dps) {
	env_t_1126 env;
	env.one_w_dps = one_w_dps;
	return env;
}

value_t lambda1126(env_t_1126* env1085, storage_t stgVar1043, number_t x_dps0, card_t x_shp0) {
	number_t one_w_dps1084 = env1085->one_w_dps;
	value_t res;
	res.number_t_value = one_w_dps1084;
	return res;
}
typedef empty_env_t env_t_1127;


value_t lambda1127(env_t_1127* env1088, card_t x_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef struct env_t_1129 {
	card_t one_feat_shp;
} env_t_1129;
env_t_1129 make_env_t_1129(card_t one_feat_shp) {
	env_t_1129 env;
	env.one_feat_shp = one_feat_shp;
	return env;
}

value_t lambda1129(env_t_1129* env1093, card_t x_shp0) {
	card_t one_feat_shp1092 = env1093->one_feat_shp;
	value_t res;
	res.card_t_value = one_feat_shp1092;
	return res;
}
typedef struct env_t_1130 {
	array_number_t one_feat_dps;
} env_t_1130;
env_t_1130 make_env_t_1130(array_number_t one_feat_dps) {
	env_t_1130 env;
	env.one_feat_dps = one_feat_dps;
	return env;
}

value_t lambda1130(env_t_1130* env1097, storage_t stgVar1053, number_t x_dps0, card_t x_shp0) {
	array_number_t one_feat_dps1096 = env1097->one_feat_dps;
	value_t res;
	res.array_number_t_value = one_feat_dps1096;
	return res;
}
typedef struct env_t_1131 {
	card_t one_feat_shp;
} env_t_1131;
env_t_1131 make_env_t_1131(card_t one_feat_shp) {
	env_t_1131 env;
	env.one_feat_shp = one_feat_shp;
	return env;
}

value_t lambda1131(env_t_1131* env1101, card_t x_shp0) {
	card_t one_feat_shp1100 = env1101->one_feat_shp;
	value_t res;
	res.card_t_value = one_feat_shp1100;
	return res;
}
typedef empty_env_t env_t_1133;


value_t lambda1133(env_t_1133* env1105, card_t x_shp0) {
	
	value_t res;
	res.card_t_value = 2;
	return res;
}
void TOP_LEVEL_usecases_ba_run_ba_from_file_dps(storage_t stgVar1023, string_t fn_dps, card_t n_dps, card_t m_dps, card_t p_dps, card_t fn_shp, card_t n_shp, card_t m_shp, card_t p_shp) {
	card_t oneCard_shp = 1;
	card_t oneCard_dps = 1;
	card_t one_cam_shp = TOP_LEVEL_linalg_vectorRead_shp(0, 0, 11);
	card_t size1143 = width_card_t(one_cam_shp);
	array_number_t stgVar1025 = storage_alloc(size1143);
	array_number_t one_cam_dps = TOP_LEVEL_linalg_vectorRead_dps(stgVar1025, fn_dps, 1, 11, 0, 0, 11);
	env_t_1123 env_t_1123_value = make_env_t_1123(one_cam_shp); closure_t closure1074 = make_closure(lambda1123, &env_t_1123_value);
	matrix_shape_t cam_shp = nested_shape_card_t(closure1074.lam(closure1074.env, 0).card_t_value, n_shp);
	card_t size1142 = width_matrix_shape_t(cam_shp);
	array_number_t stgVar1029 = storage_alloc(size1142);
	array_array_number_t macroDef1075 = (array_array_number_t)stgVar1029;
		macroDef1075->length=n_dps;
		macroDef1075->arr=(array_number_t*)(STG_OFFSET(macroDef1075, VECTOR_HEADER_BYTES));
		storage_t stgVar1030 = (STG_OFFSET(macroDef1075, MATRIX_HEADER_BYTES(n_dps)));
		for(int x_dps = 0; x_dps < macroDef1075->length; x_dps++){
			
			macroDef1075->arr[x_dps] = one_cam_dps;;
			stgVar1030 = STG_OFFSET(stgVar1030, VECTOR_ALL_BYTES(macroDef1075->arr[x_dps]->length));
		}
	array_array_number_t cam_dps = macroDef1075;
	card_t one_x_shp = TOP_LEVEL_linalg_vectorRead_shp(0, 0, 3);
	card_t size1141 = width_card_t(one_x_shp);
	array_number_t stgVar1031 = storage_alloc(size1141);
	array_number_t one_x_dps = TOP_LEVEL_linalg_vectorRead_dps(stgVar1031, fn_dps, 2, 3, 0, 0, 3);
	env_t_1124 env_t_1124_value = make_env_t_1124(one_x_shp); closure_t closure1079 = make_closure(lambda1124, &env_t_1124_value);
	matrix_shape_t x_shp = nested_shape_card_t(closure1079.lam(closure1079.env, 0).card_t_value, m_shp);
	card_t size1140 = width_matrix_shape_t(x_shp);
	array_number_t stgVar1035 = storage_alloc(size1140);
	array_array_number_t macroDef1080 = (array_array_number_t)stgVar1035;
		macroDef1080->length=m_dps;
		macroDef1080->arr=(array_number_t*)(STG_OFFSET(macroDef1080, VECTOR_HEADER_BYTES));
		storage_t stgVar1036 = (STG_OFFSET(macroDef1080, MATRIX_HEADER_BYTES(m_dps)));
		for(int x_dps = 0; x_dps < macroDef1080->length; x_dps++){
			
			macroDef1080->arr[x_dps] = one_x_dps;;
			stgVar1036 = STG_OFFSET(stgVar1036, VECTOR_ALL_BYTES(macroDef1080->arr[x_dps]->length));
		}
	array_array_number_t x_dps = macroDef1080;
	card_t one_w_shp = 0;
	number_t one_w_dps = TOP_LEVEL_linalg_numberRead_dps(empty_storage, fn_dps, 3, 0, 0);
	env_t_1125 env_t_1125_value = make_empty_env(); closure_t closure1083 = make_closure(lambda1125, &env_t_1125_value);
	card_t w_shp = TOP_LEVEL_linalg_vectorMap_shp(closure1083, TOP_LEVEL_linalg_vectorRange_shp(oneCard_shp, p_shp));
	card_t size1139 = width_card_t(w_shp);
	array_number_t stgVar1040 = storage_alloc(size1139);
	card_t size1128 = width_card_t(TOP_LEVEL_linalg_vectorRange_shp(oneCard_shp, p_shp));
	array_number_t stgVar1042 = storage_alloc(size1128);
	array_number_t macroDef1091;env_t_1126 env_t_1126_value = make_env_t_1126(one_w_dps); closure_t closure1087 = make_closure(lambda1126, &env_t_1126_value);
	env_t_1127 env_t_1127_value = make_empty_env(); closure_t closure1090 = make_closure(lambda1127, &env_t_1127_value);
	macroDef1091 = TOP_LEVEL_linalg_vectorMap_dps(stgVar1040, closure1087, TOP_LEVEL_linalg_vectorRange_dps(stgVar1042, oneCard_dps, p_dps, oneCard_shp, p_shp), closure1090, TOP_LEVEL_linalg_vectorRange_shp(oneCard_shp, p_shp));;
	storage_free(stgVar1042, size1128);
	array_number_t w_dps = macroDef1091;
	card_t one_feat_shp = TOP_LEVEL_linalg_vectorRead_shp(0, 0, 2);
	card_t size1138 = width_card_t(one_feat_shp);
	array_number_t stgVar1046 = storage_alloc(size1138);
	array_number_t one_feat_dps = TOP_LEVEL_linalg_vectorRead_dps(stgVar1046, fn_dps, 4, 2, 0, 0, 2);
	env_t_1129 env_t_1129_value = make_env_t_1129(one_feat_shp); closure_t closure1095 = make_closure(lambda1129, &env_t_1129_value);
	matrix_shape_t feat_shp = TOP_LEVEL_linalg_vectorMapToMatrix_shp(closure1095, TOP_LEVEL_linalg_vectorRange_shp(oneCard_shp, p_shp));
	card_t size1137 = width_matrix_shape_t(feat_shp);
	array_number_t stgVar1050 = storage_alloc(size1137);
	card_t size1132 = width_card_t(TOP_LEVEL_linalg_vectorRange_shp(oneCard_shp, p_shp));
	array_number_t stgVar1052 = storage_alloc(size1132);
	array_array_number_t macroDef1104;env_t_1130 env_t_1130_value = make_env_t_1130(one_feat_dps); closure_t closure1099 = make_closure(lambda1130, &env_t_1130_value);
	env_t_1131 env_t_1131_value = make_env_t_1131(one_feat_shp); closure_t closure1103 = make_closure(lambda1131, &env_t_1131_value);
	macroDef1104 = TOP_LEVEL_linalg_vectorMapToMatrix_dps(stgVar1050, closure1099, TOP_LEVEL_linalg_vectorRange_dps(stgVar1052, oneCard_dps, p_dps, oneCard_shp, p_shp), closure1103, TOP_LEVEL_linalg_vectorRange_shp(oneCard_shp, p_shp));;
	storage_free(stgVar1052, size1132);
	array_array_number_t feat_dps = macroDef1104;
	env_t_1133 env_t_1133_value = make_empty_env(); closure_t closure1107 = make_closure(lambda1133, &env_t_1133_value);
	matrix_shape_t obs_shp = nested_shape_card_t(closure1107.lam(closure1107.env, 0).card_t_value, p_shp);
	card_t size1136 = width_matrix_shape_t(obs_shp);
	array_number_t stgVar1056 = storage_alloc(size1136);
	array_array_number_t macroDef1109 = (array_array_number_t)stgVar1056;
		macroDef1109->length=p_dps;
		macroDef1109->arr=(array_number_t*)(STG_OFFSET(macroDef1109, VECTOR_HEADER_BYTES));
		storage_t stgVar1057 = (STG_OFFSET(macroDef1109, MATRIX_HEADER_BYTES(p_dps)));
		for(int x_dps0 = 0; x_dps0 < macroDef1109->length; x_dps0++){
			array_number_t macroDef1108 = (array_number_t)stgVar1057;
	macroDef1108->length=2;
	macroDef1108->arr=(number_t*)(STG_OFFSET(stgVar1057, VECTOR_HEADER_BYTES));
	macroDef1108->arr[0] = (double)(((int)(x_dps0)) % ((n_dps)));
	macroDef1108->arr[1] = (double)(((int)(x_dps0)) % ((m_dps)));;
			macroDef1109->arr[x_dps0] = macroDef1108;;
			stgVar1057 = STG_OFFSET(stgVar1057, VECTOR_ALL_BYTES(macroDef1109->arr[x_dps0]->length));
		}
	array_array_number_t obs_dps = macroDef1109;
	card_t t_shp = 0;
	timer_t t_dps = tic();
	card_t range_shp = TOP_LEVEL_linalg_vectorRange_shp(1, 10);
	card_t size1135 = width_card_t(range_shp);
	array_number_t stgVar1061 = storage_alloc(size1135);
	array_number_t range_dps = TOP_LEVEL_linalg_vectorRange_dps(stgVar1061, 1, 10, 1, 10);
	
	array_number_t cur_dps_range = range_dps;
	storage_t stgVar1064 = empty_storage;
	for(int cur_dps_idx = 0; cur_dps_idx < cur_dps_range->length; cur_dps_idx++){
		number_t cur_dps = cur_dps_range->arr[cur_dps_idx];
		matrix_shape_t x_shp0 = TOP_LEVEL_usecases_ba_reproj_err_shp(cam_shp, x_shp, w_shp, obs_shp, feat_shp);
		card_t size1134 = width_matrix_shape_t(x_shp0);
	array_number_t stgVar1065 = storage_alloc(size1134);
	array_array_number_t x_dps0 = TOP_LEVEL_usecases_ba_reproj_err_dps(stgVar1065, cam_dps, x_dps, w_dps, obs_dps, feat_dps, cam_shp, x_shp, w_shp, obs_shp, feat_shp);
	;
	storage_free(stgVar1065, size1134);
		;
	}
	;
	toc(t_dps, "BA");
	;
	storage_free(stgVar1061, size1135);
	;
	storage_free(stgVar1056, size1136);
	;
	storage_free(stgVar1050, size1137);
	;
	storage_free(stgVar1046, size1138);
	;
	storage_free(stgVar1040, size1139);
	;
	storage_free(stgVar1035, size1140);
	;
	storage_free(stgVar1031, size1141);
	;
	storage_free(stgVar1029, size1142);
	;
	storage_free(stgVar1025, size1143);
	return ;
}

card_t TOP_LEVEL_usecases_ba_test_ba_shp(card_t dum_shp) {
	
	return 0;
}


void TOP_LEVEL_usecases_ba_test_ba_dps(storage_t stgVar1144, array_number_t dum_dps, card_t dum_shp) {
	card_t a_shp = 3;
	card_t size1200 = width_card_t(a_shp);
	array_number_t stgVar1145 = storage_alloc(size1200);
	array_number_t macroDef1178 = (array_number_t)stgVar1145;
	macroDef1178->length=3;
	macroDef1178->arr=(number_t*)(STG_OFFSET(stgVar1145, VECTOR_HEADER_BYTES));
	macroDef1178->arr[0] = 1;
	macroDef1178->arr[1] = 2;
	macroDef1178->arr[2] = 3;;
	array_number_t a_dps = macroDef1178;
	card_t b_shp = 3;
	card_t size1199 = width_card_t(b_shp);
	array_number_t stgVar1149 = storage_alloc(size1199);
	array_number_t macroDef1179 = (array_number_t)stgVar1149;
	macroDef1179->length=3;
	macroDef1179->arr=(number_t*)(STG_OFFSET(stgVar1149, VECTOR_HEADER_BYTES));
	macroDef1179->arr[0] = 5;
	macroDef1179->arr[1] = 6;
	macroDef1179->arr[2] = 7;;
	array_number_t b_dps = macroDef1179;
	array_print(a_dps);
	array_print(b_dps);
	card_t j_shp = TOP_LEVEL_usecases_ba_radial_distort_shp(a_shp, b_shp);
	card_t size1198 = width_card_t(j_shp);
	array_number_t stgVar1153 = storage_alloc(size1198);
	array_number_t j_dps = TOP_LEVEL_usecases_ba_radial_distort_dps(stgVar1153, a_dps, b_dps, a_shp, b_shp);
	array_print(j_dps);
	card_t k_shp = TOP_LEVEL_usecases_ba_rodrigues_rotate_point_shp(a_shp, b_shp);
	card_t size1197 = width_card_t(k_shp);
	array_number_t stgVar1156 = storage_alloc(size1197);
	array_number_t k_dps = TOP_LEVEL_usecases_ba_rodrigues_rotate_point_dps(stgVar1156, a_dps, b_dps, a_shp, b_shp);
	array_print(k_dps);
	card_t l_shp = TOP_LEVEL_linalg_vectorSlice_shp(2, 0, k_shp);
	card_t size1196 = width_card_t(l_shp);
	array_number_t stgVar1159 = storage_alloc(size1196);
	array_number_t l_dps = TOP_LEVEL_linalg_vectorSlice_dps(stgVar1159, 2, 1, k_dps, 2, 0, k_shp);
	array_print(l_dps);
	card_t cam_shp = 11;
	card_t size1195 = width_card_t(cam_shp);
	array_number_t stgVar1163 = storage_alloc(size1195);
	array_number_t macroDef1180 = (array_number_t)stgVar1163;
	macroDef1180->length=11;
	macroDef1180->arr=(number_t*)(STG_OFFSET(stgVar1163, VECTOR_HEADER_BYTES));
	macroDef1180->arr[0] = 0;
	macroDef1180->arr[1] = 2;
	macroDef1180->arr[2] = 4;
	macroDef1180->arr[3] = 6;
	macroDef1180->arr[4] = 8;
	macroDef1180->arr[5] = 10;
	macroDef1180->arr[6] = 12;
	macroDef1180->arr[7] = 14;
	macroDef1180->arr[8] = 16;
	macroDef1180->arr[9] = 18;
	macroDef1180->arr[10] = 20;;
	array_number_t cam_dps = macroDef1180;
	card_t m_shp = TOP_LEVEL_usecases_ba_project_shp(cam_shp, j_shp);
	card_t size1194 = width_card_t(m_shp);
	array_number_t stgVar1175 = storage_alloc(size1194);
	array_number_t m_dps = TOP_LEVEL_usecases_ba_project_dps(stgVar1175, cam_dps, j_dps, cam_shp, j_shp);
	array_print(m_dps);
	;
	storage_free(stgVar1175, size1194);
	;
	storage_free(stgVar1163, size1195);
	;
	storage_free(stgVar1159, size1196);
	;
	storage_free(stgVar1156, size1197);
	;
	storage_free(stgVar1153, size1198);
	;
	storage_free(stgVar1149, size1199);
	;
	storage_free(stgVar1145, size1200);
	return ;
}
#endif
