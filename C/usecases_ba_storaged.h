#ifndef __USECASES_BA_STORAGED_H__ 
#define __USECASES_BA_STORAGED_H__ 
#include "runtime/fsharp.h"
#include <stdio.h>
#include <math.h>
#include "linalg_storaged.h"

card_t TOP_LEVEL_usecases_ba_radial_distort_shp(card_t rad_params_shp, card_t proj_shp) {
	
	return TOP_LEVEL_linalg_mult_by_scalar_shp(proj_shp, 0);
}


array_number_t TOP_LEVEL_usecases_ba_radial_distort_dps(storage_t stgVar679, array_number_t rad_params_dps, array_number_t proj_dps, card_t rad_params_shp, card_t proj_shp) {
	card_t rsq_shp = 0;
	number_t rsq_dps = TOP_LEVEL_linalg_sqnorm_dps(empty_storage, proj_dps, proj_shp);
	card_t L_shp = 0;
	number_t L_dps = ((1) + ((rad_params_dps->arr[0]) * (rsq_dps))) + (((rad_params_dps->arr[1]) * (rsq_dps)) * (rsq_dps));
	return TOP_LEVEL_linalg_mult_by_scalar_dps(stgVar679, proj_dps, L_dps, proj_shp, 0);
}

card_t TOP_LEVEL_usecases_ba_rodrigues_rotate_point_shp(card_t rot_shp, card_t x_shp) {
	
	return TOP_LEVEL_linalg_vectorAdd_shp(TOP_LEVEL_linalg_vectorAdd_shp(TOP_LEVEL_linalg_mult_by_scalar_shp(x_shp, 0), TOP_LEVEL_linalg_mult_by_scalar_shp(TOP_LEVEL_linalg_cross_shp(TOP_LEVEL_linalg_mult_by_scalar_shp(rot_shp, 0), x_shp), 0)), TOP_LEVEL_linalg_mult_by_scalar_shp(TOP_LEVEL_linalg_mult_by_scalar_shp(rot_shp, 0), 0));
}


array_number_t TOP_LEVEL_usecases_ba_rodrigues_rotate_point_dps(storage_t stgVar689, array_number_t rot_dps, array_number_t x_dps, card_t rot_shp, card_t x_shp) {
	card_t sqtheta_shp = 0;
	number_t sqtheta_dps = TOP_LEVEL_linalg_sqnorm_dps(empty_storage, rot_dps, rot_shp);
	array_number_t ite818 = 0;
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
		card_t size824 = width_card_t(w_shp);
	array_number_t stgVar696 = storage_alloc(size824);
	array_number_t macroDef816;array_number_t w_dps = TOP_LEVEL_linalg_mult_by_scalar_dps(stgVar696, rot_dps, theta_inv_dps, rot_shp, 0);
	card_t w_cross_X_shp = TOP_LEVEL_linalg_cross_shp(w_shp, x_shp);
	card_t size823 = width_card_t(w_cross_X_shp);
	array_number_t stgVar699 = storage_alloc(size823);
	array_number_t macroDef815;array_number_t w_cross_X_dps = TOP_LEVEL_linalg_cross_dps(stgVar699, w_dps, x_dps, w_shp, x_shp);
	card_t tmp_shp = 0;
	number_t tmp_dps = (TOP_LEVEL_linalg_dot_prod_dps(empty_storage, w_dps, x_dps, w_shp, x_shp)) * ((1) - (costheta_dps));
	card_t v1_shp = TOP_LEVEL_linalg_mult_by_scalar_shp(x_shp, 0);
	card_t size822 = width_card_t(v1_shp);
	array_number_t stgVar705 = storage_alloc(size822);
	array_number_t macroDef814;array_number_t v1_dps = TOP_LEVEL_linalg_mult_by_scalar_dps(stgVar705, x_dps, costheta_dps, x_shp, 0);
	card_t v2_shp = TOP_LEVEL_linalg_mult_by_scalar_shp(w_cross_X_shp, 0);
	card_t size821 = width_card_t(v2_shp);
	array_number_t stgVar708 = storage_alloc(size821);
	array_number_t macroDef813;array_number_t v2_dps = TOP_LEVEL_linalg_mult_by_scalar_dps(stgVar708, w_cross_X_dps, sintheta_dps, w_cross_X_shp, 0);
	card_t size820 = width_card_t(TOP_LEVEL_linalg_mult_by_scalar_shp(w_shp, 0));
	array_number_t stgVar712 = storage_alloc(size820);
	array_number_t macroDef812;card_t size819 = width_card_t(TOP_LEVEL_linalg_vectorAdd_shp(v1_shp, v2_shp));
	array_number_t stgVar711 = storage_alloc(size819);
	array_number_t macroDef811;
	macroDef811 = TOP_LEVEL_linalg_vectorAdd_dps(stgVar689, TOP_LEVEL_linalg_vectorAdd_dps(stgVar711, v1_dps, v2_dps, v1_shp, v2_shp), TOP_LEVEL_linalg_mult_by_scalar_dps(stgVar712, w_dps, tmp_dps, w_shp, 0), TOP_LEVEL_linalg_vectorAdd_shp(v1_shp, v2_shp), TOP_LEVEL_linalg_mult_by_scalar_shp(w_shp, 0));;
	storage_free(stgVar711, size819);
	macroDef812 = macroDef811;;
	storage_free(stgVar712, size820);
	macroDef813 = macroDef812;;
	storage_free(stgVar708, size821);
	macroDef814 = macroDef813;;
	storage_free(stgVar705, size822);
	macroDef815 = macroDef814;;
	storage_free(stgVar699, size823);
	macroDef816 = macroDef815;;
	storage_free(stgVar696, size824);
		ite818 = macroDef816;;
	} else {
		card_t size825 = width_card_t(TOP_LEVEL_linalg_cross_shp(rot_shp, x_shp));
	array_number_t stgVar718 = storage_alloc(size825);
	array_number_t macroDef817;
	macroDef817 = TOP_LEVEL_linalg_vectorAdd_dps(stgVar689, x_dps, TOP_LEVEL_linalg_cross_dps(stgVar718, rot_dps, x_dps, rot_shp, x_shp), x_shp, TOP_LEVEL_linalg_cross_shp(rot_shp, x_shp));;
	storage_free(stgVar718, size825);
		ite818 = macroDef817;;
	}
	return ite818;
}

card_t TOP_LEVEL_usecases_ba_project_shp(card_t cam_shp, card_t x_shp) {
	
	return TOP_LEVEL_linalg_vectorAdd_shp(TOP_LEVEL_linalg_vectorSlice_shp(2, 0, cam_shp), TOP_LEVEL_linalg_mult_by_scalar_shp(TOP_LEVEL_usecases_ba_radial_distort_shp(TOP_LEVEL_linalg_vectorSlice_shp(2, 0, cam_shp), TOP_LEVEL_linalg_mult_by_scalar_shp(TOP_LEVEL_linalg_vectorSlice_shp(2, 0, TOP_LEVEL_usecases_ba_rodrigues_rotate_point_shp(TOP_LEVEL_linalg_vectorSlice_shp(3, 0, cam_shp), TOP_LEVEL_linalg_vectorSub_shp(x_shp, TOP_LEVEL_linalg_vectorSlice_shp(3, 0, cam_shp)))), 0)), 0));
}


array_number_t TOP_LEVEL_usecases_ba_project_dps(storage_t stgVar826, array_number_t cam_dps, array_number_t x_dps, card_t cam_shp, card_t x_shp) {
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
	card_t size939 = width_card_t(Xcam_shp);
	array_number_t stgVar833 = storage_alloc(size939);
	array_number_t macroDef929;card_t size932 = width_card_t(TOP_LEVEL_linalg_vectorSub_shp(x_shp, TOP_LEVEL_linalg_vectorSlice_shp(3, 0, cam_shp)));
	array_number_t stgVar835 = storage_alloc(size932);
	array_number_t macroDef922;card_t size931 = width_card_t(TOP_LEVEL_linalg_vectorSlice_shp(3, 0, cam_shp));
	array_number_t stgVar834 = storage_alloc(size931);
	array_number_t macroDef921;card_t size930 = width_card_t(TOP_LEVEL_linalg_vectorSlice_shp(3, 0, cam_shp));
	array_number_t stgVar840 = storage_alloc(size930);
	array_number_t macroDef920;
	macroDef920 = TOP_LEVEL_linalg_vectorSub_dps(stgVar835, x_dps, TOP_LEVEL_linalg_vectorSlice_dps(stgVar840, 3, CENTER_IDX_dps, cam_dps, 3, 0, cam_shp), x_shp, TOP_LEVEL_linalg_vectorSlice_shp(3, 0, cam_shp));;
	storage_free(stgVar840, size930);
	macroDef921 = TOP_LEVEL_usecases_ba_rodrigues_rotate_point_dps(stgVar833, TOP_LEVEL_linalg_vectorSlice_dps(stgVar834, 3, ROT_IDX_dps, cam_dps, 3, 0, cam_shp), macroDef920, TOP_LEVEL_linalg_vectorSlice_shp(3, 0, cam_shp), TOP_LEVEL_linalg_vectorSub_shp(x_shp, TOP_LEVEL_linalg_vectorSlice_shp(3, 0, cam_shp)));;
	storage_free(stgVar834, size931);
	macroDef922 = macroDef921;;
	storage_free(stgVar835, size932);
	array_number_t Xcam_dps = macroDef922;
	card_t distorted_shp = TOP_LEVEL_usecases_ba_radial_distort_shp(TOP_LEVEL_linalg_vectorSlice_shp(2, 0, cam_shp), TOP_LEVEL_linalg_mult_by_scalar_shp(TOP_LEVEL_linalg_vectorSlice_shp(2, 0, Xcam_shp), 0));
	card_t size938 = width_card_t(distorted_shp);
	array_number_t stgVar844 = storage_alloc(size938);
	array_number_t macroDef928;card_t size935 = width_card_t(TOP_LEVEL_linalg_mult_by_scalar_shp(TOP_LEVEL_linalg_vectorSlice_shp(2, 0, Xcam_shp), 0));
	array_number_t stgVar846 = storage_alloc(size935);
	array_number_t macroDef925;card_t size934 = width_card_t(TOP_LEVEL_linalg_vectorSlice_shp(2, 0, cam_shp));
	array_number_t stgVar845 = storage_alloc(size934);
	array_number_t macroDef924;card_t size933 = width_card_t(TOP_LEVEL_linalg_vectorSlice_shp(2, 0, Xcam_shp));
	array_number_t stgVar850 = storage_alloc(size933);
	array_number_t macroDef923;
	macroDef923 = TOP_LEVEL_linalg_mult_by_scalar_dps(stgVar846, TOP_LEVEL_linalg_vectorSlice_dps(stgVar850, 2, 0, Xcam_dps, 2, 0, Xcam_shp), (1) / (Xcam_dps->arr[2]), TOP_LEVEL_linalg_vectorSlice_shp(2, 0, Xcam_shp), 0);;
	storage_free(stgVar850, size933);
	macroDef924 = TOP_LEVEL_usecases_ba_radial_distort_dps(stgVar844, TOP_LEVEL_linalg_vectorSlice_dps(stgVar845, 2, RAD_IDX_dps, cam_dps, 2, 0, cam_shp), macroDef923, TOP_LEVEL_linalg_vectorSlice_shp(2, 0, cam_shp), TOP_LEVEL_linalg_mult_by_scalar_shp(TOP_LEVEL_linalg_vectorSlice_shp(2, 0, Xcam_shp), 0));;
	storage_free(stgVar845, size934);
	macroDef925 = macroDef924;;
	storage_free(stgVar846, size935);
	array_number_t distorted_dps = macroDef925;
	card_t size937 = width_card_t(TOP_LEVEL_linalg_mult_by_scalar_shp(distorted_shp, 0));
	array_number_t stgVar857 = storage_alloc(size937);
	array_number_t macroDef927;card_t size936 = width_card_t(TOP_LEVEL_linalg_vectorSlice_shp(2, 0, cam_shp));
	array_number_t stgVar856 = storage_alloc(size936);
	array_number_t macroDef926;
	macroDef926 = TOP_LEVEL_linalg_vectorAdd_dps(stgVar826, TOP_LEVEL_linalg_vectorSlice_dps(stgVar856, 2, X0_IDX_dps, cam_dps, 2, 0, cam_shp), TOP_LEVEL_linalg_mult_by_scalar_dps(stgVar857, distorted_dps, cam_dps->arr[FOCAL_IDX_dps], distorted_shp, 0), TOP_LEVEL_linalg_vectorSlice_shp(2, 0, cam_shp), TOP_LEVEL_linalg_mult_by_scalar_shp(distorted_shp, 0));;
	storage_free(stgVar856, size936);
	macroDef927 = macroDef926;;
	storage_free(stgVar857, size937);
	macroDef928 = macroDef927;;
	storage_free(stgVar844, size938);
	macroDef929 = macroDef928;;
	storage_free(stgVar833, size939);
	return macroDef929;
}

card_t TOP_LEVEL_usecases_ba_compute_reproj_err_shp(card_t cam_shp, card_t x_shp, card_t w_shp, card_t feat_shp) {
	
	return TOP_LEVEL_linalg_mult_by_scalar_shp(TOP_LEVEL_linalg_vectorSub_shp(TOP_LEVEL_usecases_ba_project_shp(cam_shp, x_shp), feat_shp), 0);
}


array_number_t TOP_LEVEL_usecases_ba_compute_reproj_err_dps(storage_t stgVar940, array_number_t cam_dps, array_number_t x_dps, number_t w_dps, array_number_t feat_dps, card_t cam_shp, card_t x_shp, card_t w_shp, card_t feat_shp) {
	card_t size950 = width_card_t(TOP_LEVEL_linalg_vectorSub_shp(TOP_LEVEL_usecases_ba_project_shp(cam_shp, x_shp), feat_shp));
	array_number_t stgVar941 = storage_alloc(size950);
	array_number_t macroDef948;card_t size949 = width_card_t(TOP_LEVEL_usecases_ba_project_shp(cam_shp, x_shp));
	array_number_t stgVar943 = storage_alloc(size949);
	array_number_t macroDef947;
	macroDef947 = TOP_LEVEL_linalg_vectorSub_dps(stgVar941, TOP_LEVEL_usecases_ba_project_dps(stgVar943, cam_dps, x_dps, cam_shp, x_shp), feat_dps, TOP_LEVEL_usecases_ba_project_shp(cam_shp, x_shp), feat_shp);;
	storage_free(stgVar943, size949);
	macroDef948 = TOP_LEVEL_linalg_mult_by_scalar_dps(stgVar940, macroDef947, w_dps, TOP_LEVEL_linalg_vectorSub_shp(TOP_LEVEL_usecases_ba_project_shp(cam_shp, x_shp), feat_shp), 0);;
	storage_free(stgVar941, size950);
	return macroDef948;
}

card_t TOP_LEVEL_usecases_ba_compute_zach_weight_error_shp(card_t w_shp) {
	
	return 0;
}


number_t TOP_LEVEL_usecases_ba_compute_zach_weight_error_dps(storage_t stgVar951, number_t w_dps, card_t w_shp) {
	
	return (1) - ((w_dps) * (w_dps));
}
typedef empty_env_t env_t_960;


value_t lambda960(env_t_960* env957, card_t w_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
card_t TOP_LEVEL_usecases_ba_w_err_shp(card_t w_shp) {
	env_t_960 env_t_960_value = make_empty_env(); closure_t closure959 = make_closure(lambda960, &env_t_960_value);
	return TOP_LEVEL_linalg_vectorMap_shp(closure959, w_shp);
}

typedef empty_env_t env_t_967;


value_t lambda967(env_t_967* env961, storage_t stgVar955, number_t w_dps0, card_t w_shp0) {
	
	value_t res;
	res.number_t_value = TOP_LEVEL_usecases_ba_compute_zach_weight_error_dps(stgVar955, w_dps0, 0);
	return res;
}
typedef empty_env_t env_t_968;


value_t lambda968(env_t_968* env964, card_t w_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
array_number_t TOP_LEVEL_usecases_ba_w_err_dps(storage_t stgVar952, array_number_t w_dps, card_t w_shp) {
	env_t_967 env_t_967_value = make_empty_env(); closure_t closure963 = make_closure(lambda967, &env_t_967_value);
	env_t_968 env_t_968_value = make_empty_env(); closure_t closure966 = make_closure(lambda968, &env_t_968_value);
	return TOP_LEVEL_linalg_vectorMap_dps(stgVar952, closure963, w_dps, closure966, w_shp);
}
typedef struct env_t_1004 {
	matrix_shape_t x_shp;
	matrix_shape_t feat_shp;
	matrix_shape_t cams_shp;
} env_t_1004;
env_t_1004 make_env_t_1004(matrix_shape_t x_shp,matrix_shape_t feat_shp,matrix_shape_t cams_shp) {
	env_t_1004 env;
	env.x_shp = x_shp;
	env.feat_shp = feat_shp;
	env.cams_shp = cams_shp;
	return env;
}

value_t lambda1004(env_t_1004* env1001, card_t i_shp) {
	matrix_shape_t x_shp1000 = env1001->x_shp;
	matrix_shape_t feat_shp999 = env1001->feat_shp;
	matrix_shape_t cams_shp998 = env1001->cams_shp;
	value_t res;
	res.card_t_value = TOP_LEVEL_usecases_ba_compute_reproj_err_shp(cams_shp998.elem, x_shp1000.elem, 0, feat_shp999.elem);
	return res;
}
matrix_shape_t TOP_LEVEL_usecases_ba_reproj_err_shp(matrix_shape_t cams_shp, matrix_shape_t x_shp, card_t w_shp, matrix_shape_t obs_shp, matrix_shape_t feat_shp) {
	env_t_1004 env_t_1004_value = make_env_t_1004(x_shp,feat_shp,cams_shp); closure_t closure1003 = make_closure(lambda1004, &env_t_1004_value);
	return TOP_LEVEL_linalg_vectorMapToMatrix_shp(closure1003, TOP_LEVEL_linalg_vectorRange_shp(0, (w_shp) - (1)));
}

typedef struct env_t_1031 {
	matrix_shape_t x_shp;
	array_array_number_t x_dps;
	array_number_t w_dps;
	matrix_shape_t obs_shp;
	array_array_number_t obs_dps;
	matrix_shape_t feat_shp;
	array_array_number_t feat_dps;
	matrix_shape_t cams_shp;
	array_array_number_t cams_dps;
} env_t_1031;
env_t_1031 make_env_t_1031(matrix_shape_t x_shp,array_array_number_t x_dps,array_number_t w_dps,matrix_shape_t obs_shp,array_array_number_t obs_dps,matrix_shape_t feat_shp,array_array_number_t feat_dps,matrix_shape_t cams_shp,array_array_number_t cams_dps) {
	env_t_1031 env;
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

value_t lambda1031(env_t_1031* env1021, storage_t stgVar979, number_t i_dps, card_t i_shp) {
	matrix_shape_t x_shp1020 = env1021->x_shp;
	array_array_number_t x_dps1019 = env1021->x_dps;
	array_number_t w_dps1018 = env1021->w_dps;
	matrix_shape_t obs_shp1017 = env1021->obs_shp;
	array_array_number_t obs_dps1016 = env1021->obs_dps;
	matrix_shape_t feat_shp1015 = env1021->feat_shp;
	array_array_number_t feat_dps1014 = env1021->feat_dps;
	matrix_shape_t cams_shp1013 = env1021->cams_shp;
	array_array_number_t cams_dps1012 = env1021->cams_dps;
	card_t size1036 = width_card_t(feat_shp1015.elem);
	array_number_t stgVar983 = storage_alloc(size1036);
	array_number_t macroDef1011;card_t size1035 = width_card_t(x_shp1020.elem);
	array_number_t stgVar981 = storage_alloc(size1035);
	array_number_t macroDef1010;card_t size1034 = width_card_t(cams_shp1013.elem);
	array_number_t stgVar980 = storage_alloc(size1034);
	array_number_t macroDef1009;card_t size1032 = width_card_t(obs_shp1017.elem);
	array_number_t stgVar985 = storage_alloc(size1032);
	number_t macroDef1007;
	macroDef1007 = obs_dps1016->arr[(int)(i_dps)]->arr[0];;
	storage_free(stgVar985, size1032);
	card_t size1033 = width_card_t(obs_shp1017.elem);
	array_number_t stgVar988 = storage_alloc(size1033);
	number_t macroDef1008;
	macroDef1008 = obs_dps1016->arr[(int)(i_dps)]->arr[1];;
	storage_free(stgVar988, size1033);
	macroDef1009 = TOP_LEVEL_usecases_ba_compute_reproj_err_dps(stgVar979, cams_dps1012->arr[(int)(macroDef1007)], x_dps1019->arr[(int)(macroDef1008)], w_dps1018->arr[(int)(i_dps)], feat_dps1014->arr[(int)(i_dps)], cams_shp1013.elem, x_shp1020.elem, 0, feat_shp1015.elem);;
	storage_free(stgVar980, size1034);
	macroDef1010 = macroDef1009;;
	storage_free(stgVar981, size1035);
	macroDef1011 = macroDef1010;;
	storage_free(stgVar983, size1036);
	value_t res;
	res.array_number_t_value = macroDef1011;
	return res;
}
typedef struct env_t_1037 {
	matrix_shape_t x_shp;
	matrix_shape_t feat_shp;
	matrix_shape_t cams_shp;
} env_t_1037;
env_t_1037 make_env_t_1037(matrix_shape_t x_shp,matrix_shape_t feat_shp,matrix_shape_t cams_shp) {
	env_t_1037 env;
	env.x_shp = x_shp;
	env.feat_shp = feat_shp;
	env.cams_shp = cams_shp;
	return env;
}

value_t lambda1037(env_t_1037* env1027, card_t i_shp) {
	matrix_shape_t x_shp1026 = env1027->x_shp;
	matrix_shape_t feat_shp1025 = env1027->feat_shp;
	matrix_shape_t cams_shp1024 = env1027->cams_shp;
	value_t res;
	res.card_t_value = TOP_LEVEL_usecases_ba_compute_reproj_err_shp(cams_shp1024.elem, x_shp1026.elem, 0, feat_shp1025.elem);
	return res;
}
array_array_number_t TOP_LEVEL_usecases_ba_reproj_err_dps(storage_t stgVar969, array_array_number_t cams_dps, array_array_number_t x_dps, array_number_t w_dps, array_array_number_t obs_dps, array_array_number_t feat_dps, matrix_shape_t cams_shp, matrix_shape_t x_shp, card_t w_shp, matrix_shape_t obs_shp, matrix_shape_t feat_shp) {
	card_t n_shp = cams_shp.card;
	card_t macroDef1005 = cams_dps->length;
	card_t n_dps = macroDef1005;
	card_t p_shp = w_shp;
	card_t macroDef1006 = w_dps->length;
	card_t p_dps = macroDef1006;
	card_t range_shp = TOP_LEVEL_linalg_vectorRange_shp(0, (p_shp) - (1));
	card_t size1038 = width_card_t(range_shp);
	array_number_t stgVar974 = storage_alloc(size1038);
	array_array_number_t macroDef1030;array_number_t range_dps = TOP_LEVEL_linalg_vectorRange_dps(stgVar974, 0, (p_dps) - (1), 0, (p_shp) - (1));
	env_t_1031 env_t_1031_value = make_env_t_1031(x_shp,x_dps,w_dps,obs_shp,obs_dps,feat_shp,feat_dps,cams_shp,cams_dps); closure_t closure1023 = make_closure(lambda1031, &env_t_1031_value);
	env_t_1037 env_t_1037_value = make_env_t_1037(x_shp,feat_shp,cams_shp); closure_t closure1029 = make_closure(lambda1037, &env_t_1037_value);
	macroDef1030 = TOP_LEVEL_linalg_vectorMapToMatrix_dps(stgVar969, closure1023, range_dps, closure1029, range_shp);;
	storage_free(stgVar974, size1038);
	return macroDef1030;
}

card_t TOP_LEVEL_usecases_ba_run_ba_from_file_shp(card_t fn_shp, card_t n_shp, card_t m_shp, card_t p_shp) {
	
	return 0;
}

typedef struct env_t_1139 {
	card_t one_cam_shp;
} env_t_1139;
env_t_1139 make_env_t_1139(card_t one_cam_shp) {
	env_t_1139 env;
	env.one_cam_shp = one_cam_shp;
	return env;
}

value_t lambda1139(env_t_1139* env1088, card_t x_shp) {
	card_t one_cam_shp1087 = env1088->one_cam_shp;
	value_t res;
	res.card_t_value = one_cam_shp1087;
	return res;
}
typedef struct env_t_1140 {
	card_t one_x_shp;
} env_t_1140;
env_t_1140 make_env_t_1140(card_t one_x_shp) {
	env_t_1140 env;
	env.one_x_shp = one_x_shp;
	return env;
}

value_t lambda1140(env_t_1140* env1093, card_t x_shp) {
	card_t one_x_shp1092 = env1093->one_x_shp;
	value_t res;
	res.card_t_value = one_x_shp1092;
	return res;
}
typedef empty_env_t env_t_1141;


value_t lambda1141(env_t_1141* env1097, card_t x_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef struct env_t_1142 {
	number_t one_w_dps;
} env_t_1142;
env_t_1142 make_env_t_1142(number_t one_w_dps) {
	env_t_1142 env;
	env.one_w_dps = one_w_dps;
	return env;
}

value_t lambda1142(env_t_1142* env1101, storage_t stgVar1059, number_t x_dps0, card_t x_shp0) {
	number_t one_w_dps1100 = env1101->one_w_dps;
	value_t res;
	res.number_t_value = one_w_dps1100;
	return res;
}
typedef empty_env_t env_t_1143;


value_t lambda1143(env_t_1143* env1104, card_t x_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef struct env_t_1145 {
	card_t one_feat_shp;
} env_t_1145;
env_t_1145 make_env_t_1145(card_t one_feat_shp) {
	env_t_1145 env;
	env.one_feat_shp = one_feat_shp;
	return env;
}

value_t lambda1145(env_t_1145* env1109, card_t x_shp0) {
	card_t one_feat_shp1108 = env1109->one_feat_shp;
	value_t res;
	res.card_t_value = one_feat_shp1108;
	return res;
}
typedef struct env_t_1146 {
	array_number_t one_feat_dps;
} env_t_1146;
env_t_1146 make_env_t_1146(array_number_t one_feat_dps) {
	env_t_1146 env;
	env.one_feat_dps = one_feat_dps;
	return env;
}

value_t lambda1146(env_t_1146* env1113, storage_t stgVar1069, number_t x_dps0, card_t x_shp0) {
	array_number_t one_feat_dps1112 = env1113->one_feat_dps;
	value_t res;
	res.array_number_t_value = one_feat_dps1112;
	return res;
}
typedef struct env_t_1147 {
	card_t one_feat_shp;
} env_t_1147;
env_t_1147 make_env_t_1147(card_t one_feat_shp) {
	env_t_1147 env;
	env.one_feat_shp = one_feat_shp;
	return env;
}

value_t lambda1147(env_t_1147* env1117, card_t x_shp0) {
	card_t one_feat_shp1116 = env1117->one_feat_shp;
	value_t res;
	res.card_t_value = one_feat_shp1116;
	return res;
}
typedef empty_env_t env_t_1149;


value_t lambda1149(env_t_1149* env1121, card_t x_shp0) {
	
	value_t res;
	res.card_t_value = 2;
	return res;
}
void TOP_LEVEL_usecases_ba_run_ba_from_file_dps(storage_t stgVar1039, string_t fn_dps, card_t n_dps, card_t m_dps, card_t p_dps, card_t fn_shp, card_t n_shp, card_t m_shp, card_t p_shp) {
	card_t oneCard_shp = 1;
	card_t oneCard_dps = 1;
	card_t one_cam_shp = TOP_LEVEL_linalg_vectorRead_shp(0, 0, 11);
	card_t size1159 = width_card_t(one_cam_shp);
	array_number_t stgVar1041 = storage_alloc(size1159);
	array_number_t one_cam_dps = TOP_LEVEL_linalg_vectorRead_dps(stgVar1041, fn_dps, 1, 11, 0, 0, 11);
	env_t_1139 env_t_1139_value = make_env_t_1139(one_cam_shp); closure_t closure1090 = make_closure(lambda1139, &env_t_1139_value);
	matrix_shape_t cam_shp = nested_shape_card_t(closure1090.lam(closure1090.env, 0).card_t_value, n_shp);
	card_t size1158 = width_matrix_shape_t(cam_shp);
	array_number_t stgVar1045 = storage_alloc(size1158);
	array_array_number_t macroDef1091 = (array_array_number_t)stgVar1045;
		macroDef1091->length=n_dps;
		macroDef1091->arr=(array_number_t*)(STG_OFFSET(macroDef1091, VECTOR_HEADER_BYTES));
		storage_t stgVar1046 = (STG_OFFSET(macroDef1091, MATRIX_HEADER_BYTES(n_dps)));
		for(int x_dps = 0; x_dps < macroDef1091->length; x_dps++){
			
			macroDef1091->arr[x_dps] = one_cam_dps;;
			stgVar1046 = STG_OFFSET(stgVar1046, VECTOR_ALL_BYTES(macroDef1091->arr[x_dps]->length));
		}
	array_array_number_t cam_dps = macroDef1091;
	card_t one_x_shp = TOP_LEVEL_linalg_vectorRead_shp(0, 0, 3);
	card_t size1157 = width_card_t(one_x_shp);
	array_number_t stgVar1047 = storage_alloc(size1157);
	array_number_t one_x_dps = TOP_LEVEL_linalg_vectorRead_dps(stgVar1047, fn_dps, 2, 3, 0, 0, 3);
	env_t_1140 env_t_1140_value = make_env_t_1140(one_x_shp); closure_t closure1095 = make_closure(lambda1140, &env_t_1140_value);
	matrix_shape_t x_shp = nested_shape_card_t(closure1095.lam(closure1095.env, 0).card_t_value, m_shp);
	card_t size1156 = width_matrix_shape_t(x_shp);
	array_number_t stgVar1051 = storage_alloc(size1156);
	array_array_number_t macroDef1096 = (array_array_number_t)stgVar1051;
		macroDef1096->length=m_dps;
		macroDef1096->arr=(array_number_t*)(STG_OFFSET(macroDef1096, VECTOR_HEADER_BYTES));
		storage_t stgVar1052 = (STG_OFFSET(macroDef1096, MATRIX_HEADER_BYTES(m_dps)));
		for(int x_dps = 0; x_dps < macroDef1096->length; x_dps++){
			
			macroDef1096->arr[x_dps] = one_x_dps;;
			stgVar1052 = STG_OFFSET(stgVar1052, VECTOR_ALL_BYTES(macroDef1096->arr[x_dps]->length));
		}
	array_array_number_t x_dps = macroDef1096;
	card_t one_w_shp = 0;
	number_t one_w_dps = TOP_LEVEL_linalg_numberRead_dps(empty_storage, fn_dps, 3, 0, 0);
	env_t_1141 env_t_1141_value = make_empty_env(); closure_t closure1099 = make_closure(lambda1141, &env_t_1141_value);
	card_t w_shp = TOP_LEVEL_linalg_vectorMap_shp(closure1099, TOP_LEVEL_linalg_vectorRange_shp(oneCard_shp, p_shp));
	card_t size1155 = width_card_t(w_shp);
	array_number_t stgVar1056 = storage_alloc(size1155);
	card_t size1144 = width_card_t(TOP_LEVEL_linalg_vectorRange_shp(oneCard_shp, p_shp));
	array_number_t stgVar1058 = storage_alloc(size1144);
	array_number_t macroDef1107;env_t_1142 env_t_1142_value = make_env_t_1142(one_w_dps); closure_t closure1103 = make_closure(lambda1142, &env_t_1142_value);
	env_t_1143 env_t_1143_value = make_empty_env(); closure_t closure1106 = make_closure(lambda1143, &env_t_1143_value);
	macroDef1107 = TOP_LEVEL_linalg_vectorMap_dps(stgVar1056, closure1103, TOP_LEVEL_linalg_vectorRange_dps(stgVar1058, oneCard_dps, p_dps, oneCard_shp, p_shp), closure1106, TOP_LEVEL_linalg_vectorRange_shp(oneCard_shp, p_shp));;
	storage_free(stgVar1058, size1144);
	array_number_t w_dps = macroDef1107;
	card_t one_feat_shp = TOP_LEVEL_linalg_vectorRead_shp(0, 0, 2);
	card_t size1154 = width_card_t(one_feat_shp);
	array_number_t stgVar1062 = storage_alloc(size1154);
	array_number_t one_feat_dps = TOP_LEVEL_linalg_vectorRead_dps(stgVar1062, fn_dps, 4, 2, 0, 0, 2);
	env_t_1145 env_t_1145_value = make_env_t_1145(one_feat_shp); closure_t closure1111 = make_closure(lambda1145, &env_t_1145_value);
	matrix_shape_t feat_shp = TOP_LEVEL_linalg_vectorMapToMatrix_shp(closure1111, TOP_LEVEL_linalg_vectorRange_shp(oneCard_shp, p_shp));
	card_t size1153 = width_matrix_shape_t(feat_shp);
	array_number_t stgVar1066 = storage_alloc(size1153);
	card_t size1148 = width_card_t(TOP_LEVEL_linalg_vectorRange_shp(oneCard_shp, p_shp));
	array_number_t stgVar1068 = storage_alloc(size1148);
	array_array_number_t macroDef1120;env_t_1146 env_t_1146_value = make_env_t_1146(one_feat_dps); closure_t closure1115 = make_closure(lambda1146, &env_t_1146_value);
	env_t_1147 env_t_1147_value = make_env_t_1147(one_feat_shp); closure_t closure1119 = make_closure(lambda1147, &env_t_1147_value);
	macroDef1120 = TOP_LEVEL_linalg_vectorMapToMatrix_dps(stgVar1066, closure1115, TOP_LEVEL_linalg_vectorRange_dps(stgVar1068, oneCard_dps, p_dps, oneCard_shp, p_shp), closure1119, TOP_LEVEL_linalg_vectorRange_shp(oneCard_shp, p_shp));;
	storage_free(stgVar1068, size1148);
	array_array_number_t feat_dps = macroDef1120;
	env_t_1149 env_t_1149_value = make_empty_env(); closure_t closure1123 = make_closure(lambda1149, &env_t_1149_value);
	matrix_shape_t obs_shp = nested_shape_card_t(closure1123.lam(closure1123.env, 0).card_t_value, p_shp);
	card_t size1152 = width_matrix_shape_t(obs_shp);
	array_number_t stgVar1072 = storage_alloc(size1152);
	array_array_number_t macroDef1125 = (array_array_number_t)stgVar1072;
		macroDef1125->length=p_dps;
		macroDef1125->arr=(array_number_t*)(STG_OFFSET(macroDef1125, VECTOR_HEADER_BYTES));
		storage_t stgVar1073 = (STG_OFFSET(macroDef1125, MATRIX_HEADER_BYTES(p_dps)));
		for(int x_dps0 = 0; x_dps0 < macroDef1125->length; x_dps0++){
			array_number_t macroDef1124 = (array_number_t)stgVar1073;
	macroDef1124->length=2;
	macroDef1124->arr=(number_t*)(STG_OFFSET(stgVar1073, VECTOR_HEADER_BYTES));
	macroDef1124->arr[0] = (double)(((int)(x_dps0)) % ((n_dps)));
	macroDef1124->arr[1] = (double)(((int)(x_dps0)) % ((m_dps)));;
			macroDef1125->arr[x_dps0] = macroDef1124;;
			stgVar1073 = STG_OFFSET(stgVar1073, VECTOR_ALL_BYTES(macroDef1125->arr[x_dps0]->length));
		}
	array_array_number_t obs_dps = macroDef1125;
	card_t t_shp = 0;
	timer_t t_dps = tic();
	card_t range_shp = TOP_LEVEL_linalg_vectorRange_shp(1, 10);
	card_t size1151 = width_card_t(range_shp);
	array_number_t stgVar1077 = storage_alloc(size1151);
	array_number_t range_dps = TOP_LEVEL_linalg_vectorRange_dps(stgVar1077, 1, 10, 1, 10);
	
	array_number_t cur_dps_range = range_dps;
	storage_t stgVar1080 = empty_storage;
	for(int cur_dps_idx = 0; cur_dps_idx < cur_dps_range->length; cur_dps_idx++){
		number_t cur_dps = cur_dps_range->arr[cur_dps_idx];
		matrix_shape_t x_shp0 = TOP_LEVEL_usecases_ba_reproj_err_shp(cam_shp, x_shp, w_shp, obs_shp, feat_shp);
		card_t size1150 = width_matrix_shape_t(x_shp0);
	array_number_t stgVar1081 = storage_alloc(size1150);
	array_array_number_t x_dps0 = TOP_LEVEL_usecases_ba_reproj_err_dps(stgVar1081, cam_dps, x_dps, w_dps, obs_dps, feat_dps, cam_shp, x_shp, w_shp, obs_shp, feat_shp);
	;
	storage_free(stgVar1081, size1150);
		;
	}
	;
	toc(t_dps, "BA");
	;
	storage_free(stgVar1077, size1151);
	;
	storage_free(stgVar1072, size1152);
	;
	storage_free(stgVar1066, size1153);
	;
	storage_free(stgVar1062, size1154);
	;
	storage_free(stgVar1056, size1155);
	;
	storage_free(stgVar1051, size1156);
	;
	storage_free(stgVar1047, size1157);
	;
	storage_free(stgVar1045, size1158);
	;
	storage_free(stgVar1041, size1159);
	return ;
}

card_t TOP_LEVEL_usecases_ba_test_ba_shp(card_t dum_shp) {
	
	return 0;
}


void TOP_LEVEL_usecases_ba_test_ba_dps(storage_t stgVar1160, array_number_t dum_dps, card_t dum_shp) {
	card_t a_shp = 3;
	card_t size1216 = width_card_t(a_shp);
	array_number_t stgVar1161 = storage_alloc(size1216);
	array_number_t macroDef1194 = (array_number_t)stgVar1161;
	macroDef1194->length=3;
	macroDef1194->arr=(number_t*)(STG_OFFSET(stgVar1161, VECTOR_HEADER_BYTES));
	macroDef1194->arr[0] = 1;
	macroDef1194->arr[1] = 2;
	macroDef1194->arr[2] = 3;;
	array_number_t a_dps = macroDef1194;
	card_t b_shp = 3;
	card_t size1215 = width_card_t(b_shp);
	array_number_t stgVar1165 = storage_alloc(size1215);
	array_number_t macroDef1195 = (array_number_t)stgVar1165;
	macroDef1195->length=3;
	macroDef1195->arr=(number_t*)(STG_OFFSET(stgVar1165, VECTOR_HEADER_BYTES));
	macroDef1195->arr[0] = 5;
	macroDef1195->arr[1] = 6;
	macroDef1195->arr[2] = 7;;
	array_number_t b_dps = macroDef1195;
	array_print(a_dps);
	array_print(b_dps);
	card_t j_shp = TOP_LEVEL_usecases_ba_radial_distort_shp(a_shp, b_shp);
	card_t size1214 = width_card_t(j_shp);
	array_number_t stgVar1169 = storage_alloc(size1214);
	array_number_t j_dps = TOP_LEVEL_usecases_ba_radial_distort_dps(stgVar1169, a_dps, b_dps, a_shp, b_shp);
	array_print(j_dps);
	card_t k_shp = TOP_LEVEL_usecases_ba_rodrigues_rotate_point_shp(a_shp, b_shp);
	card_t size1213 = width_card_t(k_shp);
	array_number_t stgVar1172 = storage_alloc(size1213);
	array_number_t k_dps = TOP_LEVEL_usecases_ba_rodrigues_rotate_point_dps(stgVar1172, a_dps, b_dps, a_shp, b_shp);
	array_print(k_dps);
	card_t l_shp = TOP_LEVEL_linalg_vectorSlice_shp(2, 0, k_shp);
	card_t size1212 = width_card_t(l_shp);
	array_number_t stgVar1175 = storage_alloc(size1212);
	array_number_t l_dps = TOP_LEVEL_linalg_vectorSlice_dps(stgVar1175, 2, 1, k_dps, 2, 0, k_shp);
	array_print(l_dps);
	card_t cam_shp = 11;
	card_t size1211 = width_card_t(cam_shp);
	array_number_t stgVar1179 = storage_alloc(size1211);
	array_number_t macroDef1196 = (array_number_t)stgVar1179;
	macroDef1196->length=11;
	macroDef1196->arr=(number_t*)(STG_OFFSET(stgVar1179, VECTOR_HEADER_BYTES));
	macroDef1196->arr[0] = 0;
	macroDef1196->arr[1] = 2;
	macroDef1196->arr[2] = 4;
	macroDef1196->arr[3] = 6;
	macroDef1196->arr[4] = 8;
	macroDef1196->arr[5] = 10;
	macroDef1196->arr[6] = 12;
	macroDef1196->arr[7] = 14;
	macroDef1196->arr[8] = 16;
	macroDef1196->arr[9] = 18;
	macroDef1196->arr[10] = 20;;
	array_number_t cam_dps = macroDef1196;
	card_t m_shp = TOP_LEVEL_usecases_ba_project_shp(cam_shp, j_shp);
	card_t size1210 = width_card_t(m_shp);
	array_number_t stgVar1191 = storage_alloc(size1210);
	array_number_t m_dps = TOP_LEVEL_usecases_ba_project_dps(stgVar1191, cam_dps, j_dps, cam_shp, j_shp);
	array_print(m_dps);
	;
	storage_free(stgVar1191, size1210);
	;
	storage_free(stgVar1179, size1211);
	;
	storage_free(stgVar1175, size1212);
	;
	storage_free(stgVar1172, size1213);
	;
	storage_free(stgVar1169, size1214);
	;
	storage_free(stgVar1165, size1215);
	;
	storage_free(stgVar1161, size1216);
	return ;
}
#endif
