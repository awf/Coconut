#ifndef __USECASES_BA_STORAGED_H__ 
#define __USECASES_BA_STORAGED_H__ 
#include "../../Runtime/C/fsharp.h"
#include <stdio.h>
#include <math.h>
#include "linalg_storaged.h"

card_t TOP_LEVEL_usecases_ba_radial_distort_shp(card_t rad_params_shp, card_t proj_shp) {
	
	return TOP_LEVEL_linalg_mult_by_scalar_shp(proj_shp, 0);
}


array_number_t TOP_LEVEL_usecases_ba_radial_distort_dps(storage_t stgVar670, array_number_t rad_params_dps, array_number_t proj_dps, card_t rad_params_shp, card_t proj_shp) {
	card_t rsq_shp = 0;
	number_t rsq_dps = TOP_LEVEL_linalg_sqnorm_dps(empty_storage, proj_dps, proj_shp);
	card_t L_shp = 0;
	number_t L_dps = ((1) + ((rad_params_dps->arr[0]) * (rsq_dps))) + (((rad_params_dps->arr[1]) * (rsq_dps)) * (rsq_dps));
	return TOP_LEVEL_linalg_mult_by_scalar_dps(stgVar670, proj_dps, L_dps, proj_shp, 0);
}

card_t TOP_LEVEL_usecases_ba_rodrigues_rotate_point_shp(card_t rot_shp, card_t x_shp) {
	
	return TOP_LEVEL_linalg_vectorAdd_shp(TOP_LEVEL_linalg_vectorAdd_shp(TOP_LEVEL_linalg_mult_by_scalar_shp(x_shp, 0), TOP_LEVEL_linalg_mult_by_scalar_shp(TOP_LEVEL_linalg_cross_shp(TOP_LEVEL_linalg_mult_by_scalar_shp(rot_shp, 0), x_shp), 0)), TOP_LEVEL_linalg_mult_by_scalar_shp(TOP_LEVEL_linalg_mult_by_scalar_shp(rot_shp, 0), 0));
}


array_number_t TOP_LEVEL_usecases_ba_rodrigues_rotate_point_dps(storage_t stgVar680, array_number_t rot_dps, array_number_t x_dps, card_t rot_shp, card_t x_shp) {
	card_t sqtheta_shp = 0;
	number_t sqtheta_dps = TOP_LEVEL_linalg_sqnorm_dps(empty_storage, rot_dps, rot_shp);
	array_number_t ite809 = 0;
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
		card_t size815 = width_card_t(w_shp);
	array_number_t stgVar687 = storage_alloc(size815);
	array_number_t macroDef807;array_number_t w_dps = TOP_LEVEL_linalg_mult_by_scalar_dps(stgVar687, rot_dps, theta_inv_dps, rot_shp, 0);
	card_t w_cross_X_shp = TOP_LEVEL_linalg_cross_shp(w_shp, x_shp);
	card_t size814 = width_card_t(w_cross_X_shp);
	array_number_t stgVar690 = storage_alloc(size814);
	array_number_t macroDef806;array_number_t w_cross_X_dps = TOP_LEVEL_linalg_cross_dps(stgVar690, w_dps, x_dps, w_shp, x_shp);
	card_t tmp_shp = 0;
	number_t tmp_dps = (TOP_LEVEL_linalg_dot_prod_dps(empty_storage, w_dps, x_dps, w_shp, x_shp)) * ((1) - (costheta_dps));
	card_t v1_shp = TOP_LEVEL_linalg_mult_by_scalar_shp(x_shp, 0);
	card_t size813 = width_card_t(v1_shp);
	array_number_t stgVar696 = storage_alloc(size813);
	array_number_t macroDef805;array_number_t v1_dps = TOP_LEVEL_linalg_mult_by_scalar_dps(stgVar696, x_dps, costheta_dps, x_shp, 0);
	card_t v2_shp = TOP_LEVEL_linalg_mult_by_scalar_shp(w_cross_X_shp, 0);
	card_t size812 = width_card_t(v2_shp);
	array_number_t stgVar699 = storage_alloc(size812);
	array_number_t macroDef804;array_number_t v2_dps = TOP_LEVEL_linalg_mult_by_scalar_dps(stgVar699, w_cross_X_dps, sintheta_dps, w_cross_X_shp, 0);
	card_t size811 = width_card_t(TOP_LEVEL_linalg_mult_by_scalar_shp(w_shp, 0));
	array_number_t stgVar703 = storage_alloc(size811);
	array_number_t macroDef803;card_t size810 = width_card_t(TOP_LEVEL_linalg_vectorAdd_shp(v1_shp, v2_shp));
	array_number_t stgVar702 = storage_alloc(size810);
	array_number_t macroDef802;
	macroDef802 = TOP_LEVEL_linalg_vectorAdd_dps(stgVar680, TOP_LEVEL_linalg_vectorAdd_dps(stgVar702, v1_dps, v2_dps, v1_shp, v2_shp), TOP_LEVEL_linalg_mult_by_scalar_dps(stgVar703, w_dps, tmp_dps, w_shp, 0), TOP_LEVEL_linalg_vectorAdd_shp(v1_shp, v2_shp), TOP_LEVEL_linalg_mult_by_scalar_shp(w_shp, 0));;
	storage_free(stgVar702, size810);
	macroDef803 = macroDef802;;
	storage_free(stgVar703, size811);
	macroDef804 = macroDef803;;
	storage_free(stgVar699, size812);
	macroDef805 = macroDef804;;
	storage_free(stgVar696, size813);
	macroDef806 = macroDef805;;
	storage_free(stgVar690, size814);
	macroDef807 = macroDef806;;
	storage_free(stgVar687, size815);
		ite809 = macroDef807;;
	} else {
		card_t size816 = width_card_t(TOP_LEVEL_linalg_cross_shp(rot_shp, x_shp));
	array_number_t stgVar709 = storage_alloc(size816);
	array_number_t macroDef808;
	macroDef808 = TOP_LEVEL_linalg_vectorAdd_dps(stgVar680, x_dps, TOP_LEVEL_linalg_cross_dps(stgVar709, rot_dps, x_dps, rot_shp, x_shp), x_shp, TOP_LEVEL_linalg_cross_shp(rot_shp, x_shp));;
	storage_free(stgVar709, size816);
		ite809 = macroDef808;;
	}
	return ite809;
}

card_t TOP_LEVEL_usecases_ba_project_shp(card_t cam_shp, card_t x_shp) {
	
	return TOP_LEVEL_linalg_vectorAdd_shp(TOP_LEVEL_linalg_vectorSlice_shp(2, 0, cam_shp), TOP_LEVEL_linalg_mult_by_scalar_shp(TOP_LEVEL_usecases_ba_radial_distort_shp(TOP_LEVEL_linalg_vectorSlice_shp(2, 0, cam_shp), TOP_LEVEL_linalg_mult_by_scalar_shp(TOP_LEVEL_linalg_vectorSlice_shp(2, 0, TOP_LEVEL_usecases_ba_rodrigues_rotate_point_shp(TOP_LEVEL_linalg_vectorSlice_shp(3, 0, cam_shp), TOP_LEVEL_linalg_vectorSub_shp(x_shp, TOP_LEVEL_linalg_vectorSlice_shp(3, 0, cam_shp)))), 0)), 0));
}


array_number_t TOP_LEVEL_usecases_ba_project_dps(storage_t stgVar817, array_number_t cam_dps, array_number_t x_dps, card_t cam_shp, card_t x_shp) {
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
	card_t size930 = width_card_t(Xcam_shp);
	array_number_t stgVar824 = storage_alloc(size930);
	array_number_t macroDef920;card_t size923 = width_card_t(TOP_LEVEL_linalg_vectorSub_shp(x_shp, TOP_LEVEL_linalg_vectorSlice_shp(3, 0, cam_shp)));
	array_number_t stgVar826 = storage_alloc(size923);
	array_number_t macroDef913;card_t size922 = width_card_t(TOP_LEVEL_linalg_vectorSlice_shp(3, 0, cam_shp));
	array_number_t stgVar825 = storage_alloc(size922);
	array_number_t macroDef912;card_t size921 = width_card_t(TOP_LEVEL_linalg_vectorSlice_shp(3, 0, cam_shp));
	array_number_t stgVar831 = storage_alloc(size921);
	array_number_t macroDef911;
	macroDef911 = TOP_LEVEL_linalg_vectorSub_dps(stgVar826, x_dps, TOP_LEVEL_linalg_vectorSlice_dps(stgVar831, 3, CENTER_IDX_dps, cam_dps, 3, 0, cam_shp), x_shp, TOP_LEVEL_linalg_vectorSlice_shp(3, 0, cam_shp));;
	storage_free(stgVar831, size921);
	macroDef912 = TOP_LEVEL_usecases_ba_rodrigues_rotate_point_dps(stgVar824, TOP_LEVEL_linalg_vectorSlice_dps(stgVar825, 3, ROT_IDX_dps, cam_dps, 3, 0, cam_shp), macroDef911, TOP_LEVEL_linalg_vectorSlice_shp(3, 0, cam_shp), TOP_LEVEL_linalg_vectorSub_shp(x_shp, TOP_LEVEL_linalg_vectorSlice_shp(3, 0, cam_shp)));;
	storage_free(stgVar825, size922);
	macroDef913 = macroDef912;;
	storage_free(stgVar826, size923);
	array_number_t Xcam_dps = macroDef913;
	card_t distorted_shp = TOP_LEVEL_usecases_ba_radial_distort_shp(TOP_LEVEL_linalg_vectorSlice_shp(2, 0, cam_shp), TOP_LEVEL_linalg_mult_by_scalar_shp(TOP_LEVEL_linalg_vectorSlice_shp(2, 0, Xcam_shp), 0));
	card_t size929 = width_card_t(distorted_shp);
	array_number_t stgVar835 = storage_alloc(size929);
	array_number_t macroDef919;card_t size926 = width_card_t(TOP_LEVEL_linalg_mult_by_scalar_shp(TOP_LEVEL_linalg_vectorSlice_shp(2, 0, Xcam_shp), 0));
	array_number_t stgVar837 = storage_alloc(size926);
	array_number_t macroDef916;card_t size925 = width_card_t(TOP_LEVEL_linalg_vectorSlice_shp(2, 0, cam_shp));
	array_number_t stgVar836 = storage_alloc(size925);
	array_number_t macroDef915;card_t size924 = width_card_t(TOP_LEVEL_linalg_vectorSlice_shp(2, 0, Xcam_shp));
	array_number_t stgVar841 = storage_alloc(size924);
	array_number_t macroDef914;
	macroDef914 = TOP_LEVEL_linalg_mult_by_scalar_dps(stgVar837, TOP_LEVEL_linalg_vectorSlice_dps(stgVar841, 2, 0, Xcam_dps, 2, 0, Xcam_shp), (1) / (Xcam_dps->arr[2]), TOP_LEVEL_linalg_vectorSlice_shp(2, 0, Xcam_shp), 0);;
	storage_free(stgVar841, size924);
	macroDef915 = TOP_LEVEL_usecases_ba_radial_distort_dps(stgVar835, TOP_LEVEL_linalg_vectorSlice_dps(stgVar836, 2, RAD_IDX_dps, cam_dps, 2, 0, cam_shp), macroDef914, TOP_LEVEL_linalg_vectorSlice_shp(2, 0, cam_shp), TOP_LEVEL_linalg_mult_by_scalar_shp(TOP_LEVEL_linalg_vectorSlice_shp(2, 0, Xcam_shp), 0));;
	storage_free(stgVar836, size925);
	macroDef916 = macroDef915;;
	storage_free(stgVar837, size926);
	array_number_t distorted_dps = macroDef916;
	card_t size928 = width_card_t(TOP_LEVEL_linalg_mult_by_scalar_shp(distorted_shp, 0));
	array_number_t stgVar848 = storage_alloc(size928);
	array_number_t macroDef918;card_t size927 = width_card_t(TOP_LEVEL_linalg_vectorSlice_shp(2, 0, cam_shp));
	array_number_t stgVar847 = storage_alloc(size927);
	array_number_t macroDef917;
	macroDef917 = TOP_LEVEL_linalg_vectorAdd_dps(stgVar817, TOP_LEVEL_linalg_vectorSlice_dps(stgVar847, 2, X0_IDX_dps, cam_dps, 2, 0, cam_shp), TOP_LEVEL_linalg_mult_by_scalar_dps(stgVar848, distorted_dps, cam_dps->arr[FOCAL_IDX_dps], distorted_shp, 0), TOP_LEVEL_linalg_vectorSlice_shp(2, 0, cam_shp), TOP_LEVEL_linalg_mult_by_scalar_shp(distorted_shp, 0));;
	storage_free(stgVar847, size927);
	macroDef918 = macroDef917;;
	storage_free(stgVar848, size928);
	macroDef919 = macroDef918;;
	storage_free(stgVar835, size929);
	macroDef920 = macroDef919;;
	storage_free(stgVar824, size930);
	return macroDef920;
}

card_t TOP_LEVEL_usecases_ba_compute_reproj_err_shp(card_t cam_shp, card_t x_shp, card_t w_shp, card_t feat_shp) {
	
	return TOP_LEVEL_linalg_mult_by_scalar_shp(TOP_LEVEL_linalg_vectorSub_shp(TOP_LEVEL_usecases_ba_project_shp(cam_shp, x_shp), feat_shp), 0);
}


array_number_t TOP_LEVEL_usecases_ba_compute_reproj_err_dps(storage_t stgVar931, array_number_t cam_dps, array_number_t x_dps, number_t w_dps, array_number_t feat_dps, card_t cam_shp, card_t x_shp, card_t w_shp, card_t feat_shp) {
	card_t size941 = width_card_t(TOP_LEVEL_linalg_vectorSub_shp(TOP_LEVEL_usecases_ba_project_shp(cam_shp, x_shp), feat_shp));
	array_number_t stgVar932 = storage_alloc(size941);
	array_number_t macroDef939;card_t size940 = width_card_t(TOP_LEVEL_usecases_ba_project_shp(cam_shp, x_shp));
	array_number_t stgVar934 = storage_alloc(size940);
	array_number_t macroDef938;
	macroDef938 = TOP_LEVEL_linalg_vectorSub_dps(stgVar932, TOP_LEVEL_usecases_ba_project_dps(stgVar934, cam_dps, x_dps, cam_shp, x_shp), feat_dps, TOP_LEVEL_usecases_ba_project_shp(cam_shp, x_shp), feat_shp);;
	storage_free(stgVar934, size940);
	macroDef939 = TOP_LEVEL_linalg_mult_by_scalar_dps(stgVar931, macroDef938, w_dps, TOP_LEVEL_linalg_vectorSub_shp(TOP_LEVEL_usecases_ba_project_shp(cam_shp, x_shp), feat_shp), 0);;
	storage_free(stgVar932, size941);
	return macroDef939;
}

card_t TOP_LEVEL_usecases_ba_compute_zach_weight_error_shp(card_t w_shp) {
	
	return 0;
}


number_t TOP_LEVEL_usecases_ba_compute_zach_weight_error_dps(storage_t stgVar942, number_t w_dps, card_t w_shp) {
	
	return (1) - ((w_dps) * (w_dps));
}
typedef empty_env_t env_t_951;


value_t lambda951(env_t_951* env948, card_t w_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
card_t TOP_LEVEL_usecases_ba_w_err_shp(card_t w_shp) {
	env_t_951 env_t_951_value = make_empty_env(); closure_t closure950 = make_closure(lambda951, &env_t_951_value);
	return TOP_LEVEL_linalg_vectorMap_shp(closure950, w_shp);
}

typedef empty_env_t env_t_958;


value_t lambda958(env_t_958* env952, storage_t stgVar946, number_t w_dps0, card_t w_shp0) {
	
	value_t res;
	res.number_t_value = TOP_LEVEL_usecases_ba_compute_zach_weight_error_dps(stgVar946, w_dps0, 0);
	return res;
}
typedef empty_env_t env_t_959;


value_t lambda959(env_t_959* env955, card_t w_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
array_number_t TOP_LEVEL_usecases_ba_w_err_dps(storage_t stgVar943, array_number_t w_dps, card_t w_shp) {
	env_t_958 env_t_958_value = make_empty_env(); closure_t closure954 = make_closure(lambda958, &env_t_958_value);
	env_t_959 env_t_959_value = make_empty_env(); closure_t closure957 = make_closure(lambda959, &env_t_959_value);
	return TOP_LEVEL_linalg_vectorMap_dps(stgVar943, closure954, w_dps, closure957, w_shp);
}
typedef struct env_t_995 {
	matrix_shape_t x_shp;
	matrix_shape_t feat_shp;
	matrix_shape_t cams_shp;
} env_t_995;
env_t_995 make_env_t_995(matrix_shape_t x_shp,matrix_shape_t feat_shp,matrix_shape_t cams_shp) {
	env_t_995 env;
	env.x_shp = x_shp;
	env.feat_shp = feat_shp;
	env.cams_shp = cams_shp;
	return env;
}

value_t lambda995(env_t_995* env992, card_t i_shp) {
	matrix_shape_t x_shp991 = env992->x_shp;
	matrix_shape_t feat_shp990 = env992->feat_shp;
	matrix_shape_t cams_shp989 = env992->cams_shp;
	value_t res;
	res.card_t_value = TOP_LEVEL_usecases_ba_compute_reproj_err_shp(cams_shp989.elem, x_shp991.elem, 0, feat_shp990.elem);
	return res;
}
matrix_shape_t TOP_LEVEL_usecases_ba_reproj_err_shp(matrix_shape_t cams_shp, matrix_shape_t x_shp, card_t w_shp, matrix_shape_t obs_shp, matrix_shape_t feat_shp) {
	env_t_995 env_t_995_value = make_env_t_995(x_shp,feat_shp,cams_shp); closure_t closure994 = make_closure(lambda995, &env_t_995_value);
	return TOP_LEVEL_linalg_vectorMapToMatrix_shp(closure994, TOP_LEVEL_linalg_vectorRange_shp(0, (w_shp) - (1)));
}

typedef struct env_t_1022 {
	matrix_shape_t x_shp;
	array_array_number_t x_dps;
	array_number_t w_dps;
	matrix_shape_t obs_shp;
	array_array_number_t obs_dps;
	matrix_shape_t feat_shp;
	array_array_number_t feat_dps;
	matrix_shape_t cams_shp;
	array_array_number_t cams_dps;
} env_t_1022;
env_t_1022 make_env_t_1022(matrix_shape_t x_shp,array_array_number_t x_dps,array_number_t w_dps,matrix_shape_t obs_shp,array_array_number_t obs_dps,matrix_shape_t feat_shp,array_array_number_t feat_dps,matrix_shape_t cams_shp,array_array_number_t cams_dps) {
	env_t_1022 env;
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

value_t lambda1022(env_t_1022* env1012, storage_t stgVar970, number_t i_dps, card_t i_shp) {
	matrix_shape_t x_shp1011 = env1012->x_shp;
	array_array_number_t x_dps1010 = env1012->x_dps;
	array_number_t w_dps1009 = env1012->w_dps;
	matrix_shape_t obs_shp1008 = env1012->obs_shp;
	array_array_number_t obs_dps1007 = env1012->obs_dps;
	matrix_shape_t feat_shp1006 = env1012->feat_shp;
	array_array_number_t feat_dps1005 = env1012->feat_dps;
	matrix_shape_t cams_shp1004 = env1012->cams_shp;
	array_array_number_t cams_dps1003 = env1012->cams_dps;
	card_t size1027 = width_card_t(feat_shp1006.elem);
	array_number_t stgVar974 = storage_alloc(size1027);
	array_number_t macroDef1002;card_t size1026 = width_card_t(x_shp1011.elem);
	array_number_t stgVar972 = storage_alloc(size1026);
	array_number_t macroDef1001;card_t size1025 = width_card_t(cams_shp1004.elem);
	array_number_t stgVar971 = storage_alloc(size1025);
	array_number_t macroDef1000;card_t size1023 = width_card_t(obs_shp1008.elem);
	array_number_t stgVar976 = storage_alloc(size1023);
	number_t macroDef998;
	macroDef998 = obs_dps1007->arr[(int)(i_dps)]->arr[0];;
	storage_free(stgVar976, size1023);
	card_t size1024 = width_card_t(obs_shp1008.elem);
	array_number_t stgVar979 = storage_alloc(size1024);
	number_t macroDef999;
	macroDef999 = obs_dps1007->arr[(int)(i_dps)]->arr[1];;
	storage_free(stgVar979, size1024);
	macroDef1000 = TOP_LEVEL_usecases_ba_compute_reproj_err_dps(stgVar970, cams_dps1003->arr[(int)(macroDef998)], x_dps1010->arr[(int)(macroDef999)], w_dps1009->arr[(int)(i_dps)], feat_dps1005->arr[(int)(i_dps)], cams_shp1004.elem, x_shp1011.elem, 0, feat_shp1006.elem);;
	storage_free(stgVar971, size1025);
	macroDef1001 = macroDef1000;;
	storage_free(stgVar972, size1026);
	macroDef1002 = macroDef1001;;
	storage_free(stgVar974, size1027);
	value_t res;
	res.array_number_t_value = macroDef1002;
	return res;
}
typedef struct env_t_1028 {
	matrix_shape_t x_shp;
	matrix_shape_t feat_shp;
	matrix_shape_t cams_shp;
} env_t_1028;
env_t_1028 make_env_t_1028(matrix_shape_t x_shp,matrix_shape_t feat_shp,matrix_shape_t cams_shp) {
	env_t_1028 env;
	env.x_shp = x_shp;
	env.feat_shp = feat_shp;
	env.cams_shp = cams_shp;
	return env;
}

value_t lambda1028(env_t_1028* env1018, card_t i_shp) {
	matrix_shape_t x_shp1017 = env1018->x_shp;
	matrix_shape_t feat_shp1016 = env1018->feat_shp;
	matrix_shape_t cams_shp1015 = env1018->cams_shp;
	value_t res;
	res.card_t_value = TOP_LEVEL_usecases_ba_compute_reproj_err_shp(cams_shp1015.elem, x_shp1017.elem, 0, feat_shp1016.elem);
	return res;
}
array_array_number_t TOP_LEVEL_usecases_ba_reproj_err_dps(storage_t stgVar960, array_array_number_t cams_dps, array_array_number_t x_dps, array_number_t w_dps, array_array_number_t obs_dps, array_array_number_t feat_dps, matrix_shape_t cams_shp, matrix_shape_t x_shp, card_t w_shp, matrix_shape_t obs_shp, matrix_shape_t feat_shp) {
	card_t n_shp = cams_shp.card;
	card_t macroDef996 = cams_dps->length;
	card_t n_dps = macroDef996;
	card_t p_shp = w_shp;
	card_t macroDef997 = w_dps->length;
	card_t p_dps = macroDef997;
	card_t range_shp = TOP_LEVEL_linalg_vectorRange_shp(0, (p_shp) - (1));
	card_t size1029 = width_card_t(range_shp);
	array_number_t stgVar965 = storage_alloc(size1029);
	array_array_number_t macroDef1021;array_number_t range_dps = TOP_LEVEL_linalg_vectorRange_dps(stgVar965, 0, (p_dps) - (1), 0, (p_shp) - (1));
	env_t_1022 env_t_1022_value = make_env_t_1022(x_shp,x_dps,w_dps,obs_shp,obs_dps,feat_shp,feat_dps,cams_shp,cams_dps); closure_t closure1014 = make_closure(lambda1022, &env_t_1022_value);
	env_t_1028 env_t_1028_value = make_env_t_1028(x_shp,feat_shp,cams_shp); closure_t closure1020 = make_closure(lambda1028, &env_t_1028_value);
	macroDef1021 = TOP_LEVEL_linalg_vectorMapToMatrix_dps(stgVar960, closure1014, range_dps, closure1020, range_shp);;
	storage_free(stgVar965, size1029);
	return macroDef1021;
}

card_t TOP_LEVEL_usecases_ba_run_ba_from_file_shp(card_t fn_shp, card_t n_shp, card_t m_shp, card_t p_shp) {
	
	return 0;
}

typedef struct env_t_1148 {
	card_t one_cam_shp;
} env_t_1148;
env_t_1148 make_env_t_1148(card_t one_cam_shp) {
	env_t_1148 env;
	env.one_cam_shp = one_cam_shp;
	return env;
}

value_t lambda1148(env_t_1148* env1083, card_t x_shp) {
	card_t one_cam_shp1082 = env1083->one_cam_shp;
	value_t res;
	res.card_t_value = one_cam_shp1082;
	return res;
}
typedef struct env_t_1149 {
	card_t one_x_shp;
} env_t_1149;
env_t_1149 make_env_t_1149(card_t one_x_shp) {
	env_t_1149 env;
	env.one_x_shp = one_x_shp;
	return env;
}

value_t lambda1149(env_t_1149* env1088, card_t x_shp) {
	card_t one_x_shp1087 = env1088->one_x_shp;
	value_t res;
	res.card_t_value = one_x_shp1087;
	return res;
}
typedef empty_env_t env_t_1150;


value_t lambda1150(env_t_1150* env1092, card_t x_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef struct env_t_1151 {
	number_t one_w_dps;
} env_t_1151;
env_t_1151 make_env_t_1151(number_t one_w_dps) {
	env_t_1151 env;
	env.one_w_dps = one_w_dps;
	return env;
}

value_t lambda1151(env_t_1151* env1096, storage_t stgVar1050, number_t x_dps0, card_t x_shp0) {
	number_t one_w_dps1095 = env1096->one_w_dps;
	value_t res;
	res.number_t_value = one_w_dps1095;
	return res;
}
typedef empty_env_t env_t_1152;


value_t lambda1152(env_t_1152* env1099, card_t x_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef struct env_t_1154 {
	card_t one_feat_shp;
} env_t_1154;
env_t_1154 make_env_t_1154(card_t one_feat_shp) {
	env_t_1154 env;
	env.one_feat_shp = one_feat_shp;
	return env;
}

value_t lambda1154(env_t_1154* env1104, card_t x_shp0) {
	card_t one_feat_shp1103 = env1104->one_feat_shp;
	value_t res;
	res.card_t_value = one_feat_shp1103;
	return res;
}
typedef struct env_t_1155 {
	array_number_t one_feat_dps;
} env_t_1155;
env_t_1155 make_env_t_1155(array_number_t one_feat_dps) {
	env_t_1155 env;
	env.one_feat_dps = one_feat_dps;
	return env;
}

value_t lambda1155(env_t_1155* env1108, storage_t stgVar1060, number_t x_dps0, card_t x_shp0) {
	array_number_t one_feat_dps1107 = env1108->one_feat_dps;
	value_t res;
	res.array_number_t_value = one_feat_dps1107;
	return res;
}
typedef struct env_t_1156 {
	card_t one_feat_shp;
} env_t_1156;
env_t_1156 make_env_t_1156(card_t one_feat_shp) {
	env_t_1156 env;
	env.one_feat_shp = one_feat_shp;
	return env;
}

value_t lambda1156(env_t_1156* env1112, card_t x_shp0) {
	card_t one_feat_shp1111 = env1112->one_feat_shp;
	value_t res;
	res.card_t_value = one_feat_shp1111;
	return res;
}
typedef empty_env_t env_t_1158;


value_t lambda1158(env_t_1158* env1116, card_t x_shp0) {
	
	value_t res;
	res.card_t_value = 2;
	return res;
}
typedef struct env_t_1159 {
	matrix_shape_t x_shp;
	array_array_number_t x_dps;
	card_t w_shp;
	array_number_t w_dps;
	matrix_shape_t obs_shp;
	array_array_number_t obs_dps;
	matrix_shape_t feat_shp;
	array_array_number_t feat_dps;
	matrix_shape_t cam_shp;
	array_array_number_t cam_dps;
} env_t_1159;
env_t_1159 make_env_t_1159(matrix_shape_t x_shp,array_array_number_t x_dps,card_t w_shp,array_number_t w_dps,matrix_shape_t obs_shp,array_array_number_t obs_dps,matrix_shape_t feat_shp,array_array_number_t feat_dps,matrix_shape_t cam_shp,array_array_number_t cam_dps) {
	env_t_1159 env;
	env.x_shp = x_shp;
	env.x_dps = x_dps;
	env.w_shp = w_shp;
	env.w_dps = w_dps;
	env.obs_shp = obs_shp;
	env.obs_dps = obs_dps;
	env.feat_shp = feat_shp;
	env.feat_dps = feat_dps;
	env.cam_shp = cam_shp;
	env.cam_dps = cam_dps;
	return env;
}

value_t lambda1159(env_t_1159* env1132, storage_t stgVar1075, number_t acc_dps, number_t cur_dps, card_t acc_shp, card_t cur_shp) {
	matrix_shape_t x_shp1131 = env1132->x_shp;
	array_array_number_t x_dps1130 = env1132->x_dps;
	card_t w_shp1129 = env1132->w_shp;
	array_number_t w_dps1128 = env1132->w_dps;
	matrix_shape_t obs_shp1127 = env1132->obs_shp;
	array_array_number_t obs_dps1126 = env1132->obs_dps;
	matrix_shape_t feat_shp1125 = env1132->feat_shp;
	array_array_number_t feat_dps1124 = env1132->feat_dps;
	matrix_shape_t cam_shp1123 = env1132->cam_shp;
	array_array_number_t cam_dps1122 = env1132->cam_dps;
	matrix_shape_t x_shp0 = TOP_LEVEL_usecases_ba_reproj_err_shp(cam_shp1123, x_shp1131, w_shp1129, obs_shp1127, feat_shp1125);
	card_t size1160 = width_matrix_shape_t(x_shp0);
	array_number_t stgVar1076 = storage_alloc(size1160);
	number_t macroDef1121;array_array_number_t x_dps0 = TOP_LEVEL_usecases_ba_reproj_err_dps(stgVar1076, cam_dps1122, x_dps1130, w_dps1128, obs_dps1126, feat_dps1124, cam_shp1123, x_shp1131, w_shp1129, obs_shp1127, feat_shp1125);
	macroDef1121 = acc_dps;;
	storage_free(stgVar1076, size1160);
	value_t res;
	res.number_t_value = macroDef1121;
	return res;
}
typedef empty_env_t env_t_1161;


value_t lambda1161(env_t_1161* env1135, card_t acc_shp, card_t cur_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
void TOP_LEVEL_usecases_ba_run_ba_from_file_dps(storage_t stgVar1030, string_t fn_dps, card_t n_dps, card_t m_dps, card_t p_dps, card_t fn_shp, card_t n_shp, card_t m_shp, card_t p_shp) {
	card_t oneCard_shp = 1;
	card_t oneCard_dps = 1;
	card_t one_cam_shp = TOP_LEVEL_linalg_vectorRead_shp(0, 0, 11);
	card_t size1170 = width_card_t(one_cam_shp);
	array_number_t stgVar1032 = storage_alloc(size1170);
	array_number_t one_cam_dps = TOP_LEVEL_linalg_vectorRead_dps(stgVar1032, fn_dps, 1, 11, 0, 0, 11);
	env_t_1148 env_t_1148_value = make_env_t_1148(one_cam_shp); closure_t closure1085 = make_closure(lambda1148, &env_t_1148_value);
	matrix_shape_t cam_shp = nested_shape_card_t(closure1085.lam(closure1085.env, 0).card_t_value, n_shp);
	card_t size1169 = width_matrix_shape_t(cam_shp);
	array_number_t stgVar1036 = storage_alloc(size1169);
	array_array_number_t macroDef1086 = (array_array_number_t)stgVar1036;
		macroDef1086->length=n_dps;
		macroDef1086->arr=(array_number_t*)(STG_OFFSET(macroDef1086, VECTOR_HEADER_BYTES));
		storage_t stgVar1037 = (STG_OFFSET(macroDef1086, MATRIX_HEADER_BYTES(n_dps)));
		for(int x_dps = 0; x_dps < macroDef1086->length; x_dps++){
			
			macroDef1086->arr[x_dps] = one_cam_dps;;
			stgVar1037 = STG_OFFSET(stgVar1037, VECTOR_ALL_BYTES(macroDef1086->arr[x_dps]->length));
		}
	array_array_number_t cam_dps = macroDef1086;
	card_t one_x_shp = TOP_LEVEL_linalg_vectorRead_shp(0, 0, 3);
	card_t size1168 = width_card_t(one_x_shp);
	array_number_t stgVar1038 = storage_alloc(size1168);
	array_number_t one_x_dps = TOP_LEVEL_linalg_vectorRead_dps(stgVar1038, fn_dps, 2, 3, 0, 0, 3);
	env_t_1149 env_t_1149_value = make_env_t_1149(one_x_shp); closure_t closure1090 = make_closure(lambda1149, &env_t_1149_value);
	matrix_shape_t x_shp = nested_shape_card_t(closure1090.lam(closure1090.env, 0).card_t_value, m_shp);
	card_t size1167 = width_matrix_shape_t(x_shp);
	array_number_t stgVar1042 = storage_alloc(size1167);
	array_array_number_t macroDef1091 = (array_array_number_t)stgVar1042;
		macroDef1091->length=m_dps;
		macroDef1091->arr=(array_number_t*)(STG_OFFSET(macroDef1091, VECTOR_HEADER_BYTES));
		storage_t stgVar1043 = (STG_OFFSET(macroDef1091, MATRIX_HEADER_BYTES(m_dps)));
		for(int x_dps = 0; x_dps < macroDef1091->length; x_dps++){
			
			macroDef1091->arr[x_dps] = one_x_dps;;
			stgVar1043 = STG_OFFSET(stgVar1043, VECTOR_ALL_BYTES(macroDef1091->arr[x_dps]->length));
		}
	array_array_number_t x_dps = macroDef1091;
	card_t one_w_shp = 0;
	number_t one_w_dps = TOP_LEVEL_linalg_numberRead_dps(empty_storage, fn_dps, 3, 0, 0);
	env_t_1150 env_t_1150_value = make_empty_env(); closure_t closure1094 = make_closure(lambda1150, &env_t_1150_value);
	card_t w_shp = TOP_LEVEL_linalg_vectorMap_shp(closure1094, TOP_LEVEL_linalg_vectorRange_shp(oneCard_shp, p_shp));
	card_t size1166 = width_card_t(w_shp);
	array_number_t stgVar1047 = storage_alloc(size1166);
	card_t size1153 = width_card_t(TOP_LEVEL_linalg_vectorRange_shp(oneCard_shp, p_shp));
	array_number_t stgVar1049 = storage_alloc(size1153);
	array_number_t macroDef1102;env_t_1151 env_t_1151_value = make_env_t_1151(one_w_dps); closure_t closure1098 = make_closure(lambda1151, &env_t_1151_value);
	env_t_1152 env_t_1152_value = make_empty_env(); closure_t closure1101 = make_closure(lambda1152, &env_t_1152_value);
	macroDef1102 = TOP_LEVEL_linalg_vectorMap_dps(stgVar1047, closure1098, TOP_LEVEL_linalg_vectorRange_dps(stgVar1049, oneCard_dps, p_dps, oneCard_shp, p_shp), closure1101, TOP_LEVEL_linalg_vectorRange_shp(oneCard_shp, p_shp));;
	storage_free(stgVar1049, size1153);
	array_number_t w_dps = macroDef1102;
	card_t one_feat_shp = TOP_LEVEL_linalg_vectorRead_shp(0, 0, 2);
	card_t size1165 = width_card_t(one_feat_shp);
	array_number_t stgVar1053 = storage_alloc(size1165);
	array_number_t one_feat_dps = TOP_LEVEL_linalg_vectorRead_dps(stgVar1053, fn_dps, 4, 2, 0, 0, 2);
	env_t_1154 env_t_1154_value = make_env_t_1154(one_feat_shp); closure_t closure1106 = make_closure(lambda1154, &env_t_1154_value);
	matrix_shape_t feat_shp = TOP_LEVEL_linalg_vectorMapToMatrix_shp(closure1106, TOP_LEVEL_linalg_vectorRange_shp(oneCard_shp, p_shp));
	card_t size1164 = width_matrix_shape_t(feat_shp);
	array_number_t stgVar1057 = storage_alloc(size1164);
	card_t size1157 = width_card_t(TOP_LEVEL_linalg_vectorRange_shp(oneCard_shp, p_shp));
	array_number_t stgVar1059 = storage_alloc(size1157);
	array_array_number_t macroDef1115;env_t_1155 env_t_1155_value = make_env_t_1155(one_feat_dps); closure_t closure1110 = make_closure(lambda1155, &env_t_1155_value);
	env_t_1156 env_t_1156_value = make_env_t_1156(one_feat_shp); closure_t closure1114 = make_closure(lambda1156, &env_t_1156_value);
	macroDef1115 = TOP_LEVEL_linalg_vectorMapToMatrix_dps(stgVar1057, closure1110, TOP_LEVEL_linalg_vectorRange_dps(stgVar1059, oneCard_dps, p_dps, oneCard_shp, p_shp), closure1114, TOP_LEVEL_linalg_vectorRange_shp(oneCard_shp, p_shp));;
	storage_free(stgVar1059, size1157);
	array_array_number_t feat_dps = macroDef1115;
	env_t_1158 env_t_1158_value = make_empty_env(); closure_t closure1118 = make_closure(lambda1158, &env_t_1158_value);
	matrix_shape_t obs_shp = nested_shape_card_t(closure1118.lam(closure1118.env, 0).card_t_value, p_shp);
	card_t size1163 = width_matrix_shape_t(obs_shp);
	array_number_t stgVar1063 = storage_alloc(size1163);
	array_array_number_t macroDef1120 = (array_array_number_t)stgVar1063;
		macroDef1120->length=p_dps;
		macroDef1120->arr=(array_number_t*)(STG_OFFSET(macroDef1120, VECTOR_HEADER_BYTES));
		storage_t stgVar1064 = (STG_OFFSET(macroDef1120, MATRIX_HEADER_BYTES(p_dps)));
		for(int x_dps0 = 0; x_dps0 < macroDef1120->length; x_dps0++){
			array_number_t macroDef1119 = (array_number_t)stgVar1064;
	macroDef1119->length=2;
	macroDef1119->arr=(number_t*)(STG_OFFSET(stgVar1064, VECTOR_HEADER_BYTES));
	

	macroDef1119->arr[0] = (double)(((int)(x_dps0)) % ((n_dps)));;

	macroDef1119->arr[1] = (double)(((int)(x_dps0)) % ((m_dps)));;;
			macroDef1120->arr[x_dps0] = macroDef1119;;
			stgVar1064 = STG_OFFSET(stgVar1064, VECTOR_ALL_BYTES(macroDef1120->arr[x_dps0]->length));
		}
	array_array_number_t obs_dps = macroDef1120;
	card_t t_shp = 0;
	timer_t t_dps = tic();
	card_t range_shp = TOP_LEVEL_linalg_vectorRange_shp(1, 10);
	card_t size1162 = width_card_t(range_shp);
	array_number_t stgVar1068 = storage_alloc(size1162);
	array_number_t range_dps = TOP_LEVEL_linalg_vectorRange_dps(stgVar1068, 1, 10, 1, 10);
	card_t tmp_shp = 0;
	env_t_1159 env_t_1159_value = make_env_t_1159(x_shp,x_dps,w_shp,w_dps,obs_shp,obs_dps,feat_shp,feat_dps,cam_shp,cam_dps); closure_t closure1134 = make_closure(lambda1159, &env_t_1159_value);
	env_t_1161 env_t_1161_value = make_empty_env(); closure_t closure1137 = make_closure(lambda1161, &env_t_1161_value);
	number_t tmp_dps = TOP_LEVEL_linalg_vectorFoldNumber_dps(empty_storage, closure1134, 0, range_dps, closure1137, 0, range_shp);
	toc(t_dps, "BA");
	;
	storage_free(stgVar1068, size1162);
	;
	storage_free(stgVar1063, size1163);
	;
	storage_free(stgVar1057, size1164);
	;
	storage_free(stgVar1053, size1165);
	;
	storage_free(stgVar1047, size1166);
	;
	storage_free(stgVar1042, size1167);
	;
	storage_free(stgVar1038, size1168);
	;
	storage_free(stgVar1036, size1169);
	;
	storage_free(stgVar1032, size1170);
	return ;
}

card_t TOP_LEVEL_usecases_ba_test_ba_shp(card_t dum_shp) {
	
	return 0;
}


void TOP_LEVEL_usecases_ba_test_ba_dps(storage_t stgVar1171, array_number_t dum_dps, card_t dum_shp) {
	card_t a_shp = 3;
	card_t size1227 = width_card_t(a_shp);
	array_number_t stgVar1172 = storage_alloc(size1227);
	array_number_t macroDef1205 = (array_number_t)stgVar1172;
	macroDef1205->length=3;
	macroDef1205->arr=(number_t*)(STG_OFFSET(stgVar1172, VECTOR_HEADER_BYTES));
	

	macroDef1205->arr[0] = 1;;

	macroDef1205->arr[1] = 2;;

	macroDef1205->arr[2] = 3;;;
	array_number_t a_dps = macroDef1205;
	card_t b_shp = 3;
	card_t size1226 = width_card_t(b_shp);
	array_number_t stgVar1176 = storage_alloc(size1226);
	array_number_t macroDef1206 = (array_number_t)stgVar1176;
	macroDef1206->length=3;
	macroDef1206->arr=(number_t*)(STG_OFFSET(stgVar1176, VECTOR_HEADER_BYTES));
	

	macroDef1206->arr[0] = 5;;

	macroDef1206->arr[1] = 6;;

	macroDef1206->arr[2] = 7;;;
	array_number_t b_dps = macroDef1206;
	array_print(a_dps);
	array_print(b_dps);
	card_t j_shp = TOP_LEVEL_usecases_ba_radial_distort_shp(a_shp, b_shp);
	card_t size1225 = width_card_t(j_shp);
	array_number_t stgVar1180 = storage_alloc(size1225);
	array_number_t j_dps = TOP_LEVEL_usecases_ba_radial_distort_dps(stgVar1180, a_dps, b_dps, a_shp, b_shp);
	array_print(j_dps);
	card_t k_shp = TOP_LEVEL_usecases_ba_rodrigues_rotate_point_shp(a_shp, b_shp);
	card_t size1224 = width_card_t(k_shp);
	array_number_t stgVar1183 = storage_alloc(size1224);
	array_number_t k_dps = TOP_LEVEL_usecases_ba_rodrigues_rotate_point_dps(stgVar1183, a_dps, b_dps, a_shp, b_shp);
	array_print(k_dps);
	card_t l_shp = TOP_LEVEL_linalg_vectorSlice_shp(2, 0, k_shp);
	card_t size1223 = width_card_t(l_shp);
	array_number_t stgVar1186 = storage_alloc(size1223);
	array_number_t l_dps = TOP_LEVEL_linalg_vectorSlice_dps(stgVar1186, 2, 1, k_dps, 2, 0, k_shp);
	array_print(l_dps);
	card_t cam_shp = 11;
	card_t size1222 = width_card_t(cam_shp);
	array_number_t stgVar1190 = storage_alloc(size1222);
	array_number_t macroDef1207 = (array_number_t)stgVar1190;
	macroDef1207->length=11;
	macroDef1207->arr=(number_t*)(STG_OFFSET(stgVar1190, VECTOR_HEADER_BYTES));
	

	macroDef1207->arr[0] = 0;;

	macroDef1207->arr[1] = 2;;

	macroDef1207->arr[2] = 4;;

	macroDef1207->arr[3] = 6;;

	macroDef1207->arr[4] = 8;;

	macroDef1207->arr[5] = 10;;

	macroDef1207->arr[6] = 12;;

	macroDef1207->arr[7] = 14;;

	macroDef1207->arr[8] = 16;;

	macroDef1207->arr[9] = 18;;

	macroDef1207->arr[10] = 20;;;
	array_number_t cam_dps = macroDef1207;
	card_t m_shp = TOP_LEVEL_usecases_ba_project_shp(cam_shp, j_shp);
	card_t size1221 = width_card_t(m_shp);
	array_number_t stgVar1202 = storage_alloc(size1221);
	array_number_t m_dps = TOP_LEVEL_usecases_ba_project_dps(stgVar1202, cam_dps, j_dps, cam_shp, j_shp);
	array_print(m_dps);
	;
	storage_free(stgVar1202, size1221);
	;
	storage_free(stgVar1190, size1222);
	;
	storage_free(stgVar1186, size1223);
	;
	storage_free(stgVar1183, size1224);
	;
	storage_free(stgVar1180, size1225);
	;
	storage_free(stgVar1176, size1226);
	;
	storage_free(stgVar1172, size1227);
	return ;
}
#endif
