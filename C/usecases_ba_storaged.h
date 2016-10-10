#ifndef __USECASES_BA_STORAGED_H__ 
#define __USECASES_BA_STORAGED_H__ 
#include "runtime/fsharp.h"
#include <stdio.h>
#include <math.h>
#include "linalg_storaged.h"

card_t TOP_LEVEL_usecases_ba_radial_distort_shp(card_t rad_params_shp, card_t proj_shp) {
	
	return TOP_LEVEL_linalg_mult_by_scalar_shp(proj_shp, 0);
}


array_number_t TOP_LEVEL_usecases_ba_radial_distort_dps(storage_t stgVar683, array_number_t rad_params_dps, array_number_t proj_dps, card_t rad_params_shp, card_t proj_shp) {
	card_t rsq_shp = 0;
	number_t rsq_dps = TOP_LEVEL_linalg_sqnorm_dps(empty_storage, proj_dps, proj_shp);
	card_t L_shp = 0;
	number_t L_dps = ((1) + ((rad_params_dps->arr[0]) * (rsq_dps))) + (((rad_params_dps->arr[1]) * (rsq_dps)) * (rsq_dps));
	return TOP_LEVEL_linalg_mult_by_scalar_dps(stgVar683, proj_dps, L_dps, proj_shp, 0);
}

card_t TOP_LEVEL_usecases_ba_rodrigues_rotate_point_shp(card_t rot_shp, card_t x_shp) {
	
	return TOP_LEVEL_linalg_vectorAdd_shp(TOP_LEVEL_linalg_vectorAdd_shp(TOP_LEVEL_linalg_mult_by_scalar_shp(x_shp, 0), TOP_LEVEL_linalg_mult_by_scalar_shp(TOP_LEVEL_linalg_cross_shp(TOP_LEVEL_linalg_mult_by_scalar_shp(rot_shp, 0), x_shp), 0)), TOP_LEVEL_linalg_mult_by_scalar_shp(TOP_LEVEL_linalg_mult_by_scalar_shp(rot_shp, 0), 0));
}


array_number_t TOP_LEVEL_usecases_ba_rodrigues_rotate_point_dps(storage_t stgVar693, array_number_t rot_dps, array_number_t x_dps, card_t rot_shp, card_t x_shp) {
	card_t sqtheta_shp = 0;
	number_t sqtheta_dps = TOP_LEVEL_linalg_sqnorm_dps(empty_storage, rot_dps, rot_shp);
	array_number_t ite822 = 0;
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
		card_t size828 = width_card_t(w_shp);
	array_number_t stgVar700 = storage_alloc(size828);
	array_number_t macroDef820;array_number_t w_dps = TOP_LEVEL_linalg_mult_by_scalar_dps(stgVar700, rot_dps, theta_inv_dps, rot_shp, 0);
	card_t w_cross_X_shp = TOP_LEVEL_linalg_cross_shp(w_shp, x_shp);
	card_t size827 = width_card_t(w_cross_X_shp);
	array_number_t stgVar703 = storage_alloc(size827);
	array_number_t macroDef819;array_number_t w_cross_X_dps = TOP_LEVEL_linalg_cross_dps(stgVar703, w_dps, x_dps, w_shp, x_shp);
	card_t tmp_shp = 0;
	number_t tmp_dps = (TOP_LEVEL_linalg_dot_prod_dps(empty_storage, w_dps, x_dps, w_shp, x_shp)) * ((1) - (costheta_dps));
	card_t v1_shp = TOP_LEVEL_linalg_mult_by_scalar_shp(x_shp, 0);
	card_t size826 = width_card_t(v1_shp);
	array_number_t stgVar709 = storage_alloc(size826);
	array_number_t macroDef818;array_number_t v1_dps = TOP_LEVEL_linalg_mult_by_scalar_dps(stgVar709, x_dps, costheta_dps, x_shp, 0);
	card_t v2_shp = TOP_LEVEL_linalg_mult_by_scalar_shp(w_cross_X_shp, 0);
	card_t size825 = width_card_t(v2_shp);
	array_number_t stgVar712 = storage_alloc(size825);
	array_number_t macroDef817;array_number_t v2_dps = TOP_LEVEL_linalg_mult_by_scalar_dps(stgVar712, w_cross_X_dps, sintheta_dps, w_cross_X_shp, 0);
	card_t size824 = width_card_t(TOP_LEVEL_linalg_mult_by_scalar_shp(w_shp, 0));
	array_number_t stgVar716 = storage_alloc(size824);
	array_number_t macroDef816;card_t size823 = width_card_t(TOP_LEVEL_linalg_vectorAdd_shp(v1_shp, v2_shp));
	array_number_t stgVar715 = storage_alloc(size823);
	array_number_t macroDef815;
	macroDef815 = TOP_LEVEL_linalg_vectorAdd_dps(stgVar693, TOP_LEVEL_linalg_vectorAdd_dps(stgVar715, v1_dps, v2_dps, v1_shp, v2_shp), TOP_LEVEL_linalg_mult_by_scalar_dps(stgVar716, w_dps, tmp_dps, w_shp, 0), TOP_LEVEL_linalg_vectorAdd_shp(v1_shp, v2_shp), TOP_LEVEL_linalg_mult_by_scalar_shp(w_shp, 0));;
	storage_free(stgVar715, size823);
	macroDef816 = macroDef815;;
	storage_free(stgVar716, size824);
	macroDef817 = macroDef816;;
	storage_free(stgVar712, size825);
	macroDef818 = macroDef817;;
	storage_free(stgVar709, size826);
	macroDef819 = macroDef818;;
	storage_free(stgVar703, size827);
	macroDef820 = macroDef819;;
	storage_free(stgVar700, size828);
		ite822 = macroDef820;;
	} else {
		card_t size829 = width_card_t(TOP_LEVEL_linalg_cross_shp(rot_shp, x_shp));
	array_number_t stgVar722 = storage_alloc(size829);
	array_number_t macroDef821;
	macroDef821 = TOP_LEVEL_linalg_vectorAdd_dps(stgVar693, x_dps, TOP_LEVEL_linalg_cross_dps(stgVar722, rot_dps, x_dps, rot_shp, x_shp), x_shp, TOP_LEVEL_linalg_cross_shp(rot_shp, x_shp));;
	storage_free(stgVar722, size829);
		ite822 = macroDef821;;
	}
	return ite822;
}

card_t TOP_LEVEL_usecases_ba_project_shp(card_t cam_shp, card_t x_shp) {
	
	return TOP_LEVEL_linalg_vectorAdd_shp(TOP_LEVEL_linalg_vectorSlice_shp(2, 0, cam_shp), TOP_LEVEL_linalg_mult_by_scalar_shp(TOP_LEVEL_usecases_ba_radial_distort_shp(TOP_LEVEL_linalg_vectorSlice_shp(2, 0, cam_shp), TOP_LEVEL_linalg_mult_by_scalar_shp(TOP_LEVEL_linalg_vectorSlice_shp(2, 0, TOP_LEVEL_usecases_ba_rodrigues_rotate_point_shp(TOP_LEVEL_linalg_vectorSlice_shp(3, 0, cam_shp), TOP_LEVEL_linalg_vectorSub_shp(x_shp, TOP_LEVEL_linalg_vectorSlice_shp(3, 0, cam_shp)))), 0)), 0));
}


array_number_t TOP_LEVEL_usecases_ba_project_dps(storage_t stgVar830, array_number_t cam_dps, array_number_t x_dps, card_t cam_shp, card_t x_shp) {
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
	card_t size943 = width_card_t(Xcam_shp);
	array_number_t stgVar837 = storage_alloc(size943);
	array_number_t macroDef933;card_t size936 = width_card_t(TOP_LEVEL_linalg_vectorSub_shp(x_shp, TOP_LEVEL_linalg_vectorSlice_shp(3, 0, cam_shp)));
	array_number_t stgVar839 = storage_alloc(size936);
	array_number_t macroDef926;card_t size935 = width_card_t(TOP_LEVEL_linalg_vectorSlice_shp(3, 0, cam_shp));
	array_number_t stgVar838 = storage_alloc(size935);
	array_number_t macroDef925;card_t size934 = width_card_t(TOP_LEVEL_linalg_vectorSlice_shp(3, 0, cam_shp));
	array_number_t stgVar844 = storage_alloc(size934);
	array_number_t macroDef924;
	macroDef924 = TOP_LEVEL_linalg_vectorSub_dps(stgVar839, x_dps, TOP_LEVEL_linalg_vectorSlice_dps(stgVar844, 3, CENTER_IDX_dps, cam_dps, 3, 0, cam_shp), x_shp, TOP_LEVEL_linalg_vectorSlice_shp(3, 0, cam_shp));;
	storage_free(stgVar844, size934);
	macroDef925 = TOP_LEVEL_usecases_ba_rodrigues_rotate_point_dps(stgVar837, TOP_LEVEL_linalg_vectorSlice_dps(stgVar838, 3, ROT_IDX_dps, cam_dps, 3, 0, cam_shp), macroDef924, TOP_LEVEL_linalg_vectorSlice_shp(3, 0, cam_shp), TOP_LEVEL_linalg_vectorSub_shp(x_shp, TOP_LEVEL_linalg_vectorSlice_shp(3, 0, cam_shp)));;
	storage_free(stgVar838, size935);
	macroDef926 = macroDef925;;
	storage_free(stgVar839, size936);
	array_number_t Xcam_dps = macroDef926;
	card_t distorted_shp = TOP_LEVEL_usecases_ba_radial_distort_shp(TOP_LEVEL_linalg_vectorSlice_shp(2, 0, cam_shp), TOP_LEVEL_linalg_mult_by_scalar_shp(TOP_LEVEL_linalg_vectorSlice_shp(2, 0, Xcam_shp), 0));
	card_t size942 = width_card_t(distorted_shp);
	array_number_t stgVar848 = storage_alloc(size942);
	array_number_t macroDef932;card_t size939 = width_card_t(TOP_LEVEL_linalg_mult_by_scalar_shp(TOP_LEVEL_linalg_vectorSlice_shp(2, 0, Xcam_shp), 0));
	array_number_t stgVar850 = storage_alloc(size939);
	array_number_t macroDef929;card_t size938 = width_card_t(TOP_LEVEL_linalg_vectorSlice_shp(2, 0, cam_shp));
	array_number_t stgVar849 = storage_alloc(size938);
	array_number_t macroDef928;card_t size937 = width_card_t(TOP_LEVEL_linalg_vectorSlice_shp(2, 0, Xcam_shp));
	array_number_t stgVar854 = storage_alloc(size937);
	array_number_t macroDef927;
	macroDef927 = TOP_LEVEL_linalg_mult_by_scalar_dps(stgVar850, TOP_LEVEL_linalg_vectorSlice_dps(stgVar854, 2, 0, Xcam_dps, 2, 0, Xcam_shp), (1) / (Xcam_dps->arr[2]), TOP_LEVEL_linalg_vectorSlice_shp(2, 0, Xcam_shp), 0);;
	storage_free(stgVar854, size937);
	macroDef928 = TOP_LEVEL_usecases_ba_radial_distort_dps(stgVar848, TOP_LEVEL_linalg_vectorSlice_dps(stgVar849, 2, RAD_IDX_dps, cam_dps, 2, 0, cam_shp), macroDef927, TOP_LEVEL_linalg_vectorSlice_shp(2, 0, cam_shp), TOP_LEVEL_linalg_mult_by_scalar_shp(TOP_LEVEL_linalg_vectorSlice_shp(2, 0, Xcam_shp), 0));;
	storage_free(stgVar849, size938);
	macroDef929 = macroDef928;;
	storage_free(stgVar850, size939);
	array_number_t distorted_dps = macroDef929;
	card_t size941 = width_card_t(TOP_LEVEL_linalg_mult_by_scalar_shp(distorted_shp, 0));
	array_number_t stgVar861 = storage_alloc(size941);
	array_number_t macroDef931;card_t size940 = width_card_t(TOP_LEVEL_linalg_vectorSlice_shp(2, 0, cam_shp));
	array_number_t stgVar860 = storage_alloc(size940);
	array_number_t macroDef930;
	macroDef930 = TOP_LEVEL_linalg_vectorAdd_dps(stgVar830, TOP_LEVEL_linalg_vectorSlice_dps(stgVar860, 2, X0_IDX_dps, cam_dps, 2, 0, cam_shp), TOP_LEVEL_linalg_mult_by_scalar_dps(stgVar861, distorted_dps, cam_dps->arr[FOCAL_IDX_dps], distorted_shp, 0), TOP_LEVEL_linalg_vectorSlice_shp(2, 0, cam_shp), TOP_LEVEL_linalg_mult_by_scalar_shp(distorted_shp, 0));;
	storage_free(stgVar860, size940);
	macroDef931 = macroDef930;;
	storage_free(stgVar861, size941);
	macroDef932 = macroDef931;;
	storage_free(stgVar848, size942);
	macroDef933 = macroDef932;;
	storage_free(stgVar837, size943);
	return macroDef933;
}

card_t TOP_LEVEL_usecases_ba_compute_reproj_err_shp(card_t cam_shp, card_t x_shp, card_t w_shp, card_t feat_shp) {
	
	return TOP_LEVEL_linalg_mult_by_scalar_shp(TOP_LEVEL_linalg_vectorSub_shp(TOP_LEVEL_usecases_ba_project_shp(cam_shp, x_shp), feat_shp), 0);
}


array_number_t TOP_LEVEL_usecases_ba_compute_reproj_err_dps(storage_t stgVar944, array_number_t cam_dps, array_number_t x_dps, number_t w_dps, array_number_t feat_dps, card_t cam_shp, card_t x_shp, card_t w_shp, card_t feat_shp) {
	card_t size954 = width_card_t(TOP_LEVEL_linalg_vectorSub_shp(TOP_LEVEL_usecases_ba_project_shp(cam_shp, x_shp), feat_shp));
	array_number_t stgVar945 = storage_alloc(size954);
	array_number_t macroDef952;card_t size953 = width_card_t(TOP_LEVEL_usecases_ba_project_shp(cam_shp, x_shp));
	array_number_t stgVar947 = storage_alloc(size953);
	array_number_t macroDef951;
	macroDef951 = TOP_LEVEL_linalg_vectorSub_dps(stgVar945, TOP_LEVEL_usecases_ba_project_dps(stgVar947, cam_dps, x_dps, cam_shp, x_shp), feat_dps, TOP_LEVEL_usecases_ba_project_shp(cam_shp, x_shp), feat_shp);;
	storage_free(stgVar947, size953);
	macroDef952 = TOP_LEVEL_linalg_mult_by_scalar_dps(stgVar944, macroDef951, w_dps, TOP_LEVEL_linalg_vectorSub_shp(TOP_LEVEL_usecases_ba_project_shp(cam_shp, x_shp), feat_shp), 0);;
	storage_free(stgVar945, size954);
	return macroDef952;
}

card_t TOP_LEVEL_usecases_ba_compute_zach_weight_error_shp(card_t w_shp) {
	
	return 0;
}


number_t TOP_LEVEL_usecases_ba_compute_zach_weight_error_dps(storage_t stgVar955, number_t w_dps, card_t w_shp) {
	
	return (1) - ((w_dps) * (w_dps));
}
typedef empty_env_t env_t_964;


value_t lambda964(env_t_964* env961, card_t w_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
card_t TOP_LEVEL_usecases_ba_w_err_shp(card_t w_shp) {
	env_t_964 env_t_964_value = make_empty_env(); closure_t closure963 = make_closure(lambda964, &env_t_964_value);
	return TOP_LEVEL_linalg_vectorMap_shp(closure963, w_shp);
}

typedef empty_env_t env_t_971;


value_t lambda971(env_t_971* env965, storage_t stgVar959, number_t w_dps0, card_t w_shp0) {
	
	value_t res;
	res.number_t_value = TOP_LEVEL_usecases_ba_compute_zach_weight_error_dps(stgVar959, w_dps0, 0);
	return res;
}
typedef empty_env_t env_t_972;


value_t lambda972(env_t_972* env968, card_t w_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
array_number_t TOP_LEVEL_usecases_ba_w_err_dps(storage_t stgVar956, array_number_t w_dps, card_t w_shp) {
	env_t_971 env_t_971_value = make_empty_env(); closure_t closure967 = make_closure(lambda971, &env_t_971_value);
	env_t_972 env_t_972_value = make_empty_env(); closure_t closure970 = make_closure(lambda972, &env_t_972_value);
	return TOP_LEVEL_linalg_vectorMap_dps(stgVar956, closure967, w_dps, closure970, w_shp);
}
typedef struct env_t_1008 {
	matrix_shape_t x_shp;
	matrix_shape_t feat_shp;
	matrix_shape_t cams_shp;
} env_t_1008;
env_t_1008 make_env_t_1008(matrix_shape_t x_shp,matrix_shape_t feat_shp,matrix_shape_t cams_shp) {
	env_t_1008 env;
	env.x_shp = x_shp;
	env.feat_shp = feat_shp;
	env.cams_shp = cams_shp;
	return env;
}

value_t lambda1008(env_t_1008* env1005, card_t i_shp) {
	matrix_shape_t x_shp1004 = env1005->x_shp;
	matrix_shape_t feat_shp1003 = env1005->feat_shp;
	matrix_shape_t cams_shp1002 = env1005->cams_shp;
	value_t res;
	res.card_t_value = TOP_LEVEL_usecases_ba_compute_reproj_err_shp(cams_shp1002.elem, x_shp1004.elem, 0, feat_shp1003.elem);
	return res;
}
matrix_shape_t TOP_LEVEL_usecases_ba_reproj_err_shp(matrix_shape_t cams_shp, matrix_shape_t x_shp, card_t w_shp, matrix_shape_t obs_shp, matrix_shape_t feat_shp) {
	env_t_1008 env_t_1008_value = make_env_t_1008(x_shp,feat_shp,cams_shp); closure_t closure1007 = make_closure(lambda1008, &env_t_1008_value);
	return TOP_LEVEL_linalg_vectorMapToMatrix_shp(closure1007, TOP_LEVEL_linalg_vectorRange_shp(0, (w_shp) - (1)));
}

typedef struct env_t_1035 {
	matrix_shape_t x_shp;
	array_array_number_t x_dps;
	array_number_t w_dps;
	matrix_shape_t obs_shp;
	array_array_number_t obs_dps;
	matrix_shape_t feat_shp;
	array_array_number_t feat_dps;
	matrix_shape_t cams_shp;
	array_array_number_t cams_dps;
} env_t_1035;
env_t_1035 make_env_t_1035(matrix_shape_t x_shp,array_array_number_t x_dps,array_number_t w_dps,matrix_shape_t obs_shp,array_array_number_t obs_dps,matrix_shape_t feat_shp,array_array_number_t feat_dps,matrix_shape_t cams_shp,array_array_number_t cams_dps) {
	env_t_1035 env;
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

value_t lambda1035(env_t_1035* env1025, storage_t stgVar983, number_t i_dps, card_t i_shp) {
	matrix_shape_t x_shp1024 = env1025->x_shp;
	array_array_number_t x_dps1023 = env1025->x_dps;
	array_number_t w_dps1022 = env1025->w_dps;
	matrix_shape_t obs_shp1021 = env1025->obs_shp;
	array_array_number_t obs_dps1020 = env1025->obs_dps;
	matrix_shape_t feat_shp1019 = env1025->feat_shp;
	array_array_number_t feat_dps1018 = env1025->feat_dps;
	matrix_shape_t cams_shp1017 = env1025->cams_shp;
	array_array_number_t cams_dps1016 = env1025->cams_dps;
	card_t size1040 = width_card_t(feat_shp1019.elem);
	array_number_t stgVar987 = storage_alloc(size1040);
	array_number_t macroDef1015;card_t size1039 = width_card_t(x_shp1024.elem);
	array_number_t stgVar985 = storage_alloc(size1039);
	array_number_t macroDef1014;card_t size1038 = width_card_t(cams_shp1017.elem);
	array_number_t stgVar984 = storage_alloc(size1038);
	array_number_t macroDef1013;card_t size1036 = width_card_t(obs_shp1021.elem);
	array_number_t stgVar989 = storage_alloc(size1036);
	number_t macroDef1011;
	macroDef1011 = obs_dps1020->arr[(int)(i_dps)]->arr[0];;
	storage_free(stgVar989, size1036);
	card_t size1037 = width_card_t(obs_shp1021.elem);
	array_number_t stgVar992 = storage_alloc(size1037);
	number_t macroDef1012;
	macroDef1012 = obs_dps1020->arr[(int)(i_dps)]->arr[1];;
	storage_free(stgVar992, size1037);
	macroDef1013 = TOP_LEVEL_usecases_ba_compute_reproj_err_dps(stgVar983, cams_dps1016->arr[(int)(macroDef1011)], x_dps1023->arr[(int)(macroDef1012)], w_dps1022->arr[(int)(i_dps)], feat_dps1018->arr[(int)(i_dps)], cams_shp1017.elem, x_shp1024.elem, 0, feat_shp1019.elem);;
	storage_free(stgVar984, size1038);
	macroDef1014 = macroDef1013;;
	storage_free(stgVar985, size1039);
	macroDef1015 = macroDef1014;;
	storage_free(stgVar987, size1040);
	value_t res;
	res.array_number_t_value = macroDef1015;
	return res;
}
typedef struct env_t_1041 {
	matrix_shape_t x_shp;
	matrix_shape_t feat_shp;
	matrix_shape_t cams_shp;
} env_t_1041;
env_t_1041 make_env_t_1041(matrix_shape_t x_shp,matrix_shape_t feat_shp,matrix_shape_t cams_shp) {
	env_t_1041 env;
	env.x_shp = x_shp;
	env.feat_shp = feat_shp;
	env.cams_shp = cams_shp;
	return env;
}

value_t lambda1041(env_t_1041* env1031, card_t i_shp) {
	matrix_shape_t x_shp1030 = env1031->x_shp;
	matrix_shape_t feat_shp1029 = env1031->feat_shp;
	matrix_shape_t cams_shp1028 = env1031->cams_shp;
	value_t res;
	res.card_t_value = TOP_LEVEL_usecases_ba_compute_reproj_err_shp(cams_shp1028.elem, x_shp1030.elem, 0, feat_shp1029.elem);
	return res;
}
array_array_number_t TOP_LEVEL_usecases_ba_reproj_err_dps(storage_t stgVar973, array_array_number_t cams_dps, array_array_number_t x_dps, array_number_t w_dps, array_array_number_t obs_dps, array_array_number_t feat_dps, matrix_shape_t cams_shp, matrix_shape_t x_shp, card_t w_shp, matrix_shape_t obs_shp, matrix_shape_t feat_shp) {
	card_t n_shp = cams_shp.card;
	card_t macroDef1009 = cams_dps->length;
	card_t n_dps = macroDef1009;
	card_t p_shp = w_shp;
	card_t macroDef1010 = w_dps->length;
	card_t p_dps = macroDef1010;
	card_t range_shp = TOP_LEVEL_linalg_vectorRange_shp(0, (p_shp) - (1));
	card_t size1042 = width_card_t(range_shp);
	array_number_t stgVar978 = storage_alloc(size1042);
	array_array_number_t macroDef1034;array_number_t range_dps = TOP_LEVEL_linalg_vectorRange_dps(stgVar978, 0, (p_dps) - (1), 0, (p_shp) - (1));
	env_t_1035 env_t_1035_value = make_env_t_1035(x_shp,x_dps,w_dps,obs_shp,obs_dps,feat_shp,feat_dps,cams_shp,cams_dps); closure_t closure1027 = make_closure(lambda1035, &env_t_1035_value);
	env_t_1041 env_t_1041_value = make_env_t_1041(x_shp,feat_shp,cams_shp); closure_t closure1033 = make_closure(lambda1041, &env_t_1041_value);
	macroDef1034 = TOP_LEVEL_linalg_vectorMapToMatrix_dps(stgVar973, closure1027, range_dps, closure1033, range_shp);;
	storage_free(stgVar978, size1042);
	return macroDef1034;
}

card_t TOP_LEVEL_usecases_ba_run_ba_from_file_shp(card_t fn_shp, card_t n_shp, card_t m_shp, card_t p_shp) {
	
	return 0;
}

typedef struct env_t_1143 {
	card_t one_cam_shp;
} env_t_1143;
env_t_1143 make_env_t_1143(card_t one_cam_shp) {
	env_t_1143 env;
	env.one_cam_shp = one_cam_shp;
	return env;
}

value_t lambda1143(env_t_1143* env1092, card_t x_shp) {
	card_t one_cam_shp1091 = env1092->one_cam_shp;
	value_t res;
	res.card_t_value = one_cam_shp1091;
	return res;
}
typedef struct env_t_1144 {
	card_t one_x_shp;
} env_t_1144;
env_t_1144 make_env_t_1144(card_t one_x_shp) {
	env_t_1144 env;
	env.one_x_shp = one_x_shp;
	return env;
}

value_t lambda1144(env_t_1144* env1097, card_t x_shp) {
	card_t one_x_shp1096 = env1097->one_x_shp;
	value_t res;
	res.card_t_value = one_x_shp1096;
	return res;
}
typedef empty_env_t env_t_1145;


value_t lambda1145(env_t_1145* env1101, card_t x_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef struct env_t_1146 {
	number_t one_w_dps;
} env_t_1146;
env_t_1146 make_env_t_1146(number_t one_w_dps) {
	env_t_1146 env;
	env.one_w_dps = one_w_dps;
	return env;
}

value_t lambda1146(env_t_1146* env1105, storage_t stgVar1063, number_t x_dps0, card_t x_shp0) {
	number_t one_w_dps1104 = env1105->one_w_dps;
	value_t res;
	res.number_t_value = one_w_dps1104;
	return res;
}
typedef empty_env_t env_t_1147;


value_t lambda1147(env_t_1147* env1108, card_t x_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef struct env_t_1149 {
	card_t one_feat_shp;
} env_t_1149;
env_t_1149 make_env_t_1149(card_t one_feat_shp) {
	env_t_1149 env;
	env.one_feat_shp = one_feat_shp;
	return env;
}

value_t lambda1149(env_t_1149* env1113, card_t x_shp0) {
	card_t one_feat_shp1112 = env1113->one_feat_shp;
	value_t res;
	res.card_t_value = one_feat_shp1112;
	return res;
}
typedef struct env_t_1150 {
	array_number_t one_feat_dps;
} env_t_1150;
env_t_1150 make_env_t_1150(array_number_t one_feat_dps) {
	env_t_1150 env;
	env.one_feat_dps = one_feat_dps;
	return env;
}

value_t lambda1150(env_t_1150* env1117, storage_t stgVar1073, number_t x_dps0, card_t x_shp0) {
	array_number_t one_feat_dps1116 = env1117->one_feat_dps;
	value_t res;
	res.array_number_t_value = one_feat_dps1116;
	return res;
}
typedef struct env_t_1151 {
	card_t one_feat_shp;
} env_t_1151;
env_t_1151 make_env_t_1151(card_t one_feat_shp) {
	env_t_1151 env;
	env.one_feat_shp = one_feat_shp;
	return env;
}

value_t lambda1151(env_t_1151* env1121, card_t x_shp0) {
	card_t one_feat_shp1120 = env1121->one_feat_shp;
	value_t res;
	res.card_t_value = one_feat_shp1120;
	return res;
}
typedef empty_env_t env_t_1153;


value_t lambda1153(env_t_1153* env1125, card_t x_shp0) {
	
	value_t res;
	res.card_t_value = 2;
	return res;
}
void TOP_LEVEL_usecases_ba_run_ba_from_file_dps(storage_t stgVar1043, string_t fn_dps, card_t n_dps, card_t m_dps, card_t p_dps, card_t fn_shp, card_t n_shp, card_t m_shp, card_t p_shp) {
	card_t oneCard_shp = 1;
	card_t oneCard_dps = 1;
	card_t one_cam_shp = TOP_LEVEL_linalg_vectorRead_shp(0, 0, 11);
	card_t size1163 = width_card_t(one_cam_shp);
	array_number_t stgVar1045 = storage_alloc(size1163);
	array_number_t one_cam_dps = TOP_LEVEL_linalg_vectorRead_dps(stgVar1045, fn_dps, 1, 11, 0, 0, 11);
	env_t_1143 env_t_1143_value = make_env_t_1143(one_cam_shp); closure_t closure1094 = make_closure(lambda1143, &env_t_1143_value);
	matrix_shape_t cam_shp = nested_shape_card_t(closure1094.lam(closure1094.env, 0).card_t_value, n_shp);
	card_t size1162 = width_matrix_shape_t(cam_shp);
	array_number_t stgVar1049 = storage_alloc(size1162);
	array_array_number_t macroDef1095 = (array_array_number_t)stgVar1049;
		macroDef1095->length=n_dps;
		macroDef1095->arr=(array_number_t*)(STG_OFFSET(macroDef1095, VECTOR_HEADER_BYTES));
		storage_t stgVar1050 = (STG_OFFSET(macroDef1095, MATRIX_HEADER_BYTES(n_dps)));
		for(int x_dps = 0; x_dps < macroDef1095->length; x_dps++){
			
			macroDef1095->arr[x_dps] = one_cam_dps;;
			stgVar1050 = STG_OFFSET(stgVar1050, VECTOR_ALL_BYTES(macroDef1095->arr[x_dps]->length));
		}
	array_array_number_t cam_dps = macroDef1095;
	card_t one_x_shp = TOP_LEVEL_linalg_vectorRead_shp(0, 0, 3);
	card_t size1161 = width_card_t(one_x_shp);
	array_number_t stgVar1051 = storage_alloc(size1161);
	array_number_t one_x_dps = TOP_LEVEL_linalg_vectorRead_dps(stgVar1051, fn_dps, 2, 3, 0, 0, 3);
	env_t_1144 env_t_1144_value = make_env_t_1144(one_x_shp); closure_t closure1099 = make_closure(lambda1144, &env_t_1144_value);
	matrix_shape_t x_shp = nested_shape_card_t(closure1099.lam(closure1099.env, 0).card_t_value, m_shp);
	card_t size1160 = width_matrix_shape_t(x_shp);
	array_number_t stgVar1055 = storage_alloc(size1160);
	array_array_number_t macroDef1100 = (array_array_number_t)stgVar1055;
		macroDef1100->length=m_dps;
		macroDef1100->arr=(array_number_t*)(STG_OFFSET(macroDef1100, VECTOR_HEADER_BYTES));
		storage_t stgVar1056 = (STG_OFFSET(macroDef1100, MATRIX_HEADER_BYTES(m_dps)));
		for(int x_dps = 0; x_dps < macroDef1100->length; x_dps++){
			
			macroDef1100->arr[x_dps] = one_x_dps;;
			stgVar1056 = STG_OFFSET(stgVar1056, VECTOR_ALL_BYTES(macroDef1100->arr[x_dps]->length));
		}
	array_array_number_t x_dps = macroDef1100;
	card_t one_w_shp = 0;
	number_t one_w_dps = TOP_LEVEL_linalg_numberRead_dps(empty_storage, fn_dps, 3, 0, 0);
	env_t_1145 env_t_1145_value = make_empty_env(); closure_t closure1103 = make_closure(lambda1145, &env_t_1145_value);
	card_t w_shp = TOP_LEVEL_linalg_vectorMap_shp(closure1103, TOP_LEVEL_linalg_vectorRange_shp(oneCard_shp, p_shp));
	card_t size1159 = width_card_t(w_shp);
	array_number_t stgVar1060 = storage_alloc(size1159);
	card_t size1148 = width_card_t(TOP_LEVEL_linalg_vectorRange_shp(oneCard_shp, p_shp));
	array_number_t stgVar1062 = storage_alloc(size1148);
	array_number_t macroDef1111;env_t_1146 env_t_1146_value = make_env_t_1146(one_w_dps); closure_t closure1107 = make_closure(lambda1146, &env_t_1146_value);
	env_t_1147 env_t_1147_value = make_empty_env(); closure_t closure1110 = make_closure(lambda1147, &env_t_1147_value);
	macroDef1111 = TOP_LEVEL_linalg_vectorMap_dps(stgVar1060, closure1107, TOP_LEVEL_linalg_vectorRange_dps(stgVar1062, oneCard_dps, p_dps, oneCard_shp, p_shp), closure1110, TOP_LEVEL_linalg_vectorRange_shp(oneCard_shp, p_shp));;
	storage_free(stgVar1062, size1148);
	array_number_t w_dps = macroDef1111;
	card_t one_feat_shp = TOP_LEVEL_linalg_vectorRead_shp(0, 0, 2);
	card_t size1158 = width_card_t(one_feat_shp);
	array_number_t stgVar1066 = storage_alloc(size1158);
	array_number_t one_feat_dps = TOP_LEVEL_linalg_vectorRead_dps(stgVar1066, fn_dps, 4, 2, 0, 0, 2);
	env_t_1149 env_t_1149_value = make_env_t_1149(one_feat_shp); closure_t closure1115 = make_closure(lambda1149, &env_t_1149_value);
	matrix_shape_t feat_shp = TOP_LEVEL_linalg_vectorMapToMatrix_shp(closure1115, TOP_LEVEL_linalg_vectorRange_shp(oneCard_shp, p_shp));
	card_t size1157 = width_matrix_shape_t(feat_shp);
	array_number_t stgVar1070 = storage_alloc(size1157);
	card_t size1152 = width_card_t(TOP_LEVEL_linalg_vectorRange_shp(oneCard_shp, p_shp));
	array_number_t stgVar1072 = storage_alloc(size1152);
	array_array_number_t macroDef1124;env_t_1150 env_t_1150_value = make_env_t_1150(one_feat_dps); closure_t closure1119 = make_closure(lambda1150, &env_t_1150_value);
	env_t_1151 env_t_1151_value = make_env_t_1151(one_feat_shp); closure_t closure1123 = make_closure(lambda1151, &env_t_1151_value);
	macroDef1124 = TOP_LEVEL_linalg_vectorMapToMatrix_dps(stgVar1070, closure1119, TOP_LEVEL_linalg_vectorRange_dps(stgVar1072, oneCard_dps, p_dps, oneCard_shp, p_shp), closure1123, TOP_LEVEL_linalg_vectorRange_shp(oneCard_shp, p_shp));;
	storage_free(stgVar1072, size1152);
	array_array_number_t feat_dps = macroDef1124;
	env_t_1153 env_t_1153_value = make_empty_env(); closure_t closure1127 = make_closure(lambda1153, &env_t_1153_value);
	matrix_shape_t obs_shp = nested_shape_card_t(closure1127.lam(closure1127.env, 0).card_t_value, p_shp);
	card_t size1156 = width_matrix_shape_t(obs_shp);
	array_number_t stgVar1076 = storage_alloc(size1156);
	array_array_number_t macroDef1129 = (array_array_number_t)stgVar1076;
		macroDef1129->length=p_dps;
		macroDef1129->arr=(array_number_t*)(STG_OFFSET(macroDef1129, VECTOR_HEADER_BYTES));
		storage_t stgVar1077 = (STG_OFFSET(macroDef1129, MATRIX_HEADER_BYTES(p_dps)));
		for(int x_dps0 = 0; x_dps0 < macroDef1129->length; x_dps0++){
			array_number_t macroDef1128 = (array_number_t)stgVar1077;
	macroDef1128->length=2;
	macroDef1128->arr=(number_t*)(STG_OFFSET(stgVar1077, VECTOR_HEADER_BYTES));
	macroDef1128->arr[0] = (double)(((int)(x_dps0)) % ((n_dps)));
	macroDef1128->arr[1] = (double)(((int)(x_dps0)) % ((m_dps)));;
			macroDef1129->arr[x_dps0] = macroDef1128;;
			stgVar1077 = STG_OFFSET(stgVar1077, VECTOR_ALL_BYTES(macroDef1129->arr[x_dps0]->length));
		}
	array_array_number_t obs_dps = macroDef1129;
	card_t t_shp = 0;
	timer_t t_dps = tic();
	card_t range_shp = TOP_LEVEL_linalg_vectorRange_shp(1, 10);
	card_t size1155 = width_card_t(range_shp);
	array_number_t stgVar1081 = storage_alloc(size1155);
	array_number_t range_dps = TOP_LEVEL_linalg_vectorRange_dps(stgVar1081, 1, 10, 1, 10);
	
	array_number_t cur_dps_range = range_dps;
	storage_t stgVar1084 = empty_storage;
	for(int cur_dps_idx = 0; cur_dps_idx < cur_dps_range->length; cur_dps_idx++){
		number_t cur_dps = cur_dps_range->arr[cur_dps_idx];
		matrix_shape_t x_shp0 = TOP_LEVEL_usecases_ba_reproj_err_shp(cam_shp, x_shp, w_shp, obs_shp, feat_shp);
		card_t size1154 = width_matrix_shape_t(x_shp0);
	array_number_t stgVar1085 = storage_alloc(size1154);
	array_array_number_t x_dps0 = TOP_LEVEL_usecases_ba_reproj_err_dps(stgVar1085, cam_dps, x_dps, w_dps, obs_dps, feat_dps, cam_shp, x_shp, w_shp, obs_shp, feat_shp);
	;
	storage_free(stgVar1085, size1154);
		;
	}
	;
	toc(t_dps, "BA");
	;
	storage_free(stgVar1081, size1155);
	;
	storage_free(stgVar1076, size1156);
	;
	storage_free(stgVar1070, size1157);
	;
	storage_free(stgVar1066, size1158);
	;
	storage_free(stgVar1060, size1159);
	;
	storage_free(stgVar1055, size1160);
	;
	storage_free(stgVar1051, size1161);
	;
	storage_free(stgVar1049, size1162);
	;
	storage_free(stgVar1045, size1163);
	return ;
}

card_t TOP_LEVEL_usecases_ba_test_ba_shp(card_t dum_shp) {
	
	return 0;
}


void TOP_LEVEL_usecases_ba_test_ba_dps(storage_t stgVar1164, array_number_t dum_dps, card_t dum_shp) {
	card_t a_shp = 3;
	card_t size1220 = width_card_t(a_shp);
	array_number_t stgVar1165 = storage_alloc(size1220);
	array_number_t macroDef1198 = (array_number_t)stgVar1165;
	macroDef1198->length=3;
	macroDef1198->arr=(number_t*)(STG_OFFSET(stgVar1165, VECTOR_HEADER_BYTES));
	macroDef1198->arr[0] = 1;
	macroDef1198->arr[1] = 2;
	macroDef1198->arr[2] = 3;;
	array_number_t a_dps = macroDef1198;
	card_t b_shp = 3;
	card_t size1219 = width_card_t(b_shp);
	array_number_t stgVar1169 = storage_alloc(size1219);
	array_number_t macroDef1199 = (array_number_t)stgVar1169;
	macroDef1199->length=3;
	macroDef1199->arr=(number_t*)(STG_OFFSET(stgVar1169, VECTOR_HEADER_BYTES));
	macroDef1199->arr[0] = 5;
	macroDef1199->arr[1] = 6;
	macroDef1199->arr[2] = 7;;
	array_number_t b_dps = macroDef1199;
	array_print(a_dps);
	array_print(b_dps);
	card_t j_shp = TOP_LEVEL_usecases_ba_radial_distort_shp(a_shp, b_shp);
	card_t size1218 = width_card_t(j_shp);
	array_number_t stgVar1173 = storage_alloc(size1218);
	array_number_t j_dps = TOP_LEVEL_usecases_ba_radial_distort_dps(stgVar1173, a_dps, b_dps, a_shp, b_shp);
	array_print(j_dps);
	card_t k_shp = TOP_LEVEL_usecases_ba_rodrigues_rotate_point_shp(a_shp, b_shp);
	card_t size1217 = width_card_t(k_shp);
	array_number_t stgVar1176 = storage_alloc(size1217);
	array_number_t k_dps = TOP_LEVEL_usecases_ba_rodrigues_rotate_point_dps(stgVar1176, a_dps, b_dps, a_shp, b_shp);
	array_print(k_dps);
	card_t l_shp = TOP_LEVEL_linalg_vectorSlice_shp(2, 0, k_shp);
	card_t size1216 = width_card_t(l_shp);
	array_number_t stgVar1179 = storage_alloc(size1216);
	array_number_t l_dps = TOP_LEVEL_linalg_vectorSlice_dps(stgVar1179, 2, 1, k_dps, 2, 0, k_shp);
	array_print(l_dps);
	card_t cam_shp = 11;
	card_t size1215 = width_card_t(cam_shp);
	array_number_t stgVar1183 = storage_alloc(size1215);
	array_number_t macroDef1200 = (array_number_t)stgVar1183;
	macroDef1200->length=11;
	macroDef1200->arr=(number_t*)(STG_OFFSET(stgVar1183, VECTOR_HEADER_BYTES));
	macroDef1200->arr[0] = 0;
	macroDef1200->arr[1] = 2;
	macroDef1200->arr[2] = 4;
	macroDef1200->arr[3] = 6;
	macroDef1200->arr[4] = 8;
	macroDef1200->arr[5] = 10;
	macroDef1200->arr[6] = 12;
	macroDef1200->arr[7] = 14;
	macroDef1200->arr[8] = 16;
	macroDef1200->arr[9] = 18;
	macroDef1200->arr[10] = 20;;
	array_number_t cam_dps = macroDef1200;
	card_t m_shp = TOP_LEVEL_usecases_ba_project_shp(cam_shp, j_shp);
	card_t size1214 = width_card_t(m_shp);
	array_number_t stgVar1195 = storage_alloc(size1214);
	array_number_t m_dps = TOP_LEVEL_usecases_ba_project_dps(stgVar1195, cam_dps, j_dps, cam_shp, j_shp);
	array_print(m_dps);
	;
	storage_free(stgVar1195, size1214);
	;
	storage_free(stgVar1183, size1215);
	;
	storage_free(stgVar1179, size1216);
	;
	storage_free(stgVar1176, size1217);
	;
	storage_free(stgVar1173, size1218);
	;
	storage_free(stgVar1169, size1219);
	;
	storage_free(stgVar1165, size1220);
	return ;
}
#endif
