#ifndef __USECASES_BA_D_H__ 
#define __USECASES_BA_D_H__ 
#include "../../Runtime/C/fsharp.h"
#include <stdio.h>
#include <math.h>
#include "usecases_ba.h"
#include "linalg_d.h"

array_number_t TOP_LEVEL_usecases_ba_radial_distort_d(array_number_t rad_params, array_number_t proj, array_number_t rad_params_d, array_number_t proj_d) {
	number_t rsq = TOP_LEVEL_linalg_sqnorm(proj);
	number_t rsq_d = TOP_LEVEL_linalg_sqnorm_d(proj, proj_d);
	number_t L = ((1) + ((rad_params->arr[0]) * (rsq))) + (((rad_params->arr[1]) * (rsq)) * (rsq));
	number_t L_d = ((0) + (((rad_params_d->arr[0]) * (rsq)) + ((rad_params->arr[0]) * (rsq_d)))) + (((((rad_params_d->arr[1]) * (rsq)) + ((rad_params->arr[1]) * (rsq_d))) * (rsq)) + (((rad_params->arr[1]) * (rsq)) * (rsq_d)));
	return TOP_LEVEL_linalg_mult_by_scalar_d(proj, L, proj_d, L_d);
}

array_number_t TOP_LEVEL_usecases_ba_rodrigues_rotate_point_d(array_number_t rot, array_number_t x, array_number_t rot_d, array_number_t x_d) {
	number_t sqtheta = TOP_LEVEL_linalg_sqnorm(rot);
	number_t sqtheta_d = TOP_LEVEL_linalg_sqnorm_d(rot, rot_d);
	array_number_t ite1248 ;
	if((sqtheta) != (0)) {
		number_t theta = sqrt(sqtheta);
		number_t theta_d = (sqtheta_d) / ((2) * (sqrt(sqtheta)));
		number_t costheta = cos(theta);
		number_t costheta_d = (theta_d) * (-(sin(theta)));
		number_t sintheta = sin(theta);
		number_t sintheta_d = (theta_d) * (cos(theta));
		number_t theta_inv = (1) / (theta);
		number_t theta_inv_d = (((0) * (theta)) - ((1) * (theta_d))) / ((theta) * (theta));
		array_number_t w = TOP_LEVEL_linalg_mult_by_scalar(rot, theta_inv);
		array_number_t w_d = TOP_LEVEL_linalg_mult_by_scalar_d(rot, theta_inv, rot_d, theta_inv_d);
		array_number_t w_cross_X = TOP_LEVEL_linalg_cross(w, x);
		array_number_t w_cross_X_d = TOP_LEVEL_linalg_cross_d(w, x, w_d, x_d);
		number_t tmp = (TOP_LEVEL_linalg_dot_prod(w, x)) * ((1) - (costheta));
		number_t tmp_d = ((TOP_LEVEL_linalg_dot_prod_d(w, x, w_d, x_d)) * ((1) - (costheta))) + ((TOP_LEVEL_linalg_dot_prod(w, x)) * ((0) - (costheta_d)));
		array_number_t v1 = TOP_LEVEL_linalg_mult_by_scalar(x, costheta);
		array_number_t v1_d = TOP_LEVEL_linalg_mult_by_scalar_d(x, costheta, x_d, costheta_d);
		array_number_t v2 = TOP_LEVEL_linalg_mult_by_scalar(w_cross_X, sintheta);
		array_number_t v2_d = TOP_LEVEL_linalg_mult_by_scalar_d(w_cross_X, sintheta, w_cross_X_d, sintheta_d);
		ite1248 = TOP_LEVEL_linalg_vectorAdd_d(TOP_LEVEL_linalg_vectorAdd(v1, v2), TOP_LEVEL_linalg_mult_by_scalar(w, tmp), TOP_LEVEL_linalg_vectorAdd_d(v1, v2, v1_d, v2_d), TOP_LEVEL_linalg_mult_by_scalar_d(w, tmp, w_d, tmp_d));;
	} else {
		
		ite1248 = TOP_LEVEL_linalg_vectorAdd_d(x, TOP_LEVEL_linalg_cross(rot, x), x_d, TOP_LEVEL_linalg_cross_d(rot, x, rot_d, x_d));;
	}
	return ite1248;
}

array_number_t TOP_LEVEL_usecases_ba_project_d(array_number_t cam, array_number_t x, array_number_t cam_d, array_number_t x_d) {
	index_t N_CAM_PARAMS = 11;
	index_t N_CAM_PARAMS_d = 0;
	index_t ROT_IDX = 0;
	index_t ROT_IDX_d = 0;
	index_t CENTER_IDX = 3;
	index_t CENTER_IDX_d = 0;
	index_t FOCAL_IDX = 6;
	index_t FOCAL_IDX_d = 0;
	index_t X0_IDX = 7;
	index_t X0_IDX_d = 0;
	index_t RAD_IDX = 9;
	index_t RAD_IDX_d = 0;
	array_number_t Xcam = TOP_LEVEL_usecases_ba_rodrigues_rotate_point(array_slice(cam, ROT_IDX, (ROT_IDX) + (2)), TOP_LEVEL_linalg_vectorSub(x, array_slice(cam, CENTER_IDX, (CENTER_IDX) + (2))));
	array_number_t Xcam_d = TOP_LEVEL_usecases_ba_rodrigues_rotate_point_d(array_slice(cam, ROT_IDX, (ROT_IDX) + (2)), TOP_LEVEL_linalg_vectorSub(x, array_slice(cam, CENTER_IDX, (CENTER_IDX) + (2))), TOP_LEVEL_linalg_vectorSlice_d(3, ROT_IDX, cam, 3, 0, cam_d), TOP_LEVEL_linalg_vectorSub_d(x, array_slice(cam, CENTER_IDX, (CENTER_IDX) + (2)), x_d, TOP_LEVEL_linalg_vectorSlice_d(3, CENTER_IDX, cam, 3, 0, cam_d)));
	array_number_t distorted = TOP_LEVEL_usecases_ba_radial_distort(array_slice(cam, RAD_IDX, (RAD_IDX) + (1)), TOP_LEVEL_linalg_mult_by_scalar(array_slice(Xcam, 0, 1), (1) / (Xcam->arr[2])));
	array_number_t distorted_d = TOP_LEVEL_usecases_ba_radial_distort_d(array_slice(cam, RAD_IDX, (RAD_IDX) + (1)), TOP_LEVEL_linalg_mult_by_scalar(array_slice(Xcam, 0, 1), (1) / (Xcam->arr[2])), TOP_LEVEL_linalg_vectorSlice_d(2, RAD_IDX, cam, 2, 0, cam_d), TOP_LEVEL_linalg_mult_by_scalar_d(array_slice(Xcam, 0, 1), (1) / (Xcam->arr[2]), TOP_LEVEL_linalg_vectorSlice_d(2, 0, Xcam, 2, 0, Xcam_d), (((0) * (Xcam->arr[2])) - ((1) * (Xcam_d->arr[2]))) / ((Xcam->arr[2]) * (Xcam->arr[2]))));
	return TOP_LEVEL_linalg_vectorAdd_d(array_slice(cam, X0_IDX, (X0_IDX) + (1)), TOP_LEVEL_linalg_mult_by_scalar(distorted, cam->arr[FOCAL_IDX]), TOP_LEVEL_linalg_vectorSlice_d(2, X0_IDX, cam, 2, 0, cam_d), TOP_LEVEL_linalg_mult_by_scalar_d(distorted, cam->arr[FOCAL_IDX], distorted_d, cam_d->arr[FOCAL_IDX]));
}

array_number_t TOP_LEVEL_usecases_ba_compute_reproj_err_d(array_number_t cam, array_number_t x, number_t w, array_number_t feat, array_number_t cam_d, array_number_t x_d, number_t w_d, array_number_t feat_d) {
	
	return TOP_LEVEL_linalg_mult_by_scalar_d(TOP_LEVEL_linalg_vectorSub(TOP_LEVEL_usecases_ba_project(cam, x), feat), w, TOP_LEVEL_linalg_vectorSub_d(TOP_LEVEL_usecases_ba_project(cam, x), feat, TOP_LEVEL_usecases_ba_project_d(cam, x, cam_d, x_d), feat_d), w_d);
}

number_t TOP_LEVEL_usecases_ba_compute_zach_weight_error_d(number_t w, number_t w_d) {
	
	return (0) - (((w_d) * (w)) + ((w) * (w_d)));
}
typedef empty_env_t env_t_1255;


value_t lambda1255(env_t_1255* env1249, number_t w0) {
	
	value_t res;
	res.number_t_value = TOP_LEVEL_usecases_ba_compute_zach_weight_error(w0);
	return res;
}
typedef empty_env_t env_t_1256;


value_t lambda1256(env_t_1256* env1252, number_t w0, number_t w_d0) {
	
	value_t res;
	res.number_t_value = TOP_LEVEL_usecases_ba_compute_zach_weight_error_d(w0, w_d0);
	return res;
}
array_number_t TOP_LEVEL_usecases_ba_w_err_d(array_number_t w, array_number_t w_d) {
	env_t_1255 env_t_1255_value = make_empty_env(); closure_t closure1251 = make_closure(lambda1255, &env_t_1255_value);
	env_t_1256 env_t_1256_value = make_empty_env(); closure_t closure1254 = make_closure(lambda1256, &env_t_1256_value);
	return TOP_LEVEL_linalg_vectorMap_d(closure1251, w, closure1254, w_d);
}
typedef struct env_t_1281 {
	array_array_number_t x;
	array_number_t w;
	array_array_number_t obs;
	array_array_number_t feat;
	array_array_number_t cams;
} env_t_1281;
env_t_1281 make_env_t_1281(array_array_number_t x,array_number_t w,array_array_number_t obs,array_array_number_t feat,array_array_number_t cams) {
	env_t_1281 env;
	env.x = x;
	env.w = w;
	env.obs = obs;
	env.feat = feat;
	env.cams = cams;
	return env;
}

value_t lambda1281(env_t_1281* env1266, number_t i) {
	array_array_number_t x1265 = env1266->x;
	array_number_t w1264 = env1266->w;
	array_array_number_t obs1263 = env1266->obs;
	array_array_number_t feat1262 = env1266->feat;
	array_array_number_t cams1261 = env1266->cams;
	value_t res;
	res.array_number_t_value = TOP_LEVEL_usecases_ba_compute_reproj_err(cams1261->arr[(int)(obs1263->arr[(int)(i)]->arr[0])], x1265->arr[(int)(obs1263->arr[(int)(i)]->arr[1])], w1264->arr[(int)(i)], feat1262->arr[(int)(i)]);
	return res;
}
typedef struct env_t_1282 {
	array_array_number_t x_d;
	array_array_number_t x;
	array_number_t w_d;
	array_number_t w;
	array_array_number_t obs;
	array_array_number_t feat_d;
	array_array_number_t feat;
	array_array_number_t cams_d;
	array_array_number_t cams;
} env_t_1282;
env_t_1282 make_env_t_1282(array_array_number_t x_d,array_array_number_t x,array_number_t w_d,array_number_t w,array_array_number_t obs,array_array_number_t feat_d,array_array_number_t feat,array_array_number_t cams_d,array_array_number_t cams) {
	env_t_1282 env;
	env.x_d = x_d;
	env.x = x;
	env.w_d = w_d;
	env.w = w;
	env.obs = obs;
	env.feat_d = feat_d;
	env.feat = feat;
	env.cams_d = cams_d;
	env.cams = cams;
	return env;
}

value_t lambda1282(env_t_1282* env1278, number_t i, number_t i_d) {
	array_array_number_t x_d1277 = env1278->x_d;
	array_array_number_t x1276 = env1278->x;
	array_number_t w_d1275 = env1278->w_d;
	array_number_t w1274 = env1278->w;
	array_array_number_t obs1273 = env1278->obs;
	array_array_number_t feat_d1272 = env1278->feat_d;
	array_array_number_t feat1271 = env1278->feat;
	array_array_number_t cams_d1270 = env1278->cams_d;
	array_array_number_t cams1269 = env1278->cams;
	value_t res;
	res.array_number_t_value = TOP_LEVEL_usecases_ba_compute_reproj_err_d(cams1269->arr[(int)(obs1273->arr[(int)(i)]->arr[0])], x1276->arr[(int)(obs1273->arr[(int)(i)]->arr[1])], w1274->arr[(int)(i)], feat1271->arr[(int)(i)], cams_d1270->arr[(int)(obs1273->arr[(int)(i)]->arr[0])], x_d1277->arr[(int)(obs1273->arr[(int)(i)]->arr[1])], w_d1275->arr[(int)(i)], feat_d1272->arr[(int)(i)]);
	return res;
}
array_array_number_t TOP_LEVEL_usecases_ba_reproj_err_d(array_array_number_t cams, array_array_number_t x, array_number_t w, array_array_number_t obs, array_array_number_t feat, array_array_number_t cams_d, array_array_number_t x_d, array_number_t w_d, array_array_number_t obs_d, array_array_number_t feat_d) {
	card_t macroDef1257 = cams->length;
	card_t n = macroDef1257;
	card_t macroDef1258 = cams->length;
	card_t n_d = macroDef1258;
	card_t macroDef1259 = w->length;
	card_t p = macroDef1259;
	card_t macroDef1260 = w->length;
	card_t p_d = macroDef1260;
	array_number_t range = TOP_LEVEL_linalg_vectorRange(0, (p) - (1));
	array_number_t range_d = TOP_LEVEL_linalg_vectorRange_d(0, (p) - (1), 0, (p) - (1));
	env_t_1281 env_t_1281_value = make_env_t_1281(x,w,obs,feat,cams); closure_t closure1268 = make_closure(lambda1281, &env_t_1281_value);
	env_t_1282 env_t_1282_value = make_env_t_1282(x_d,x,w_d,w,obs,feat_d,feat,cams_d,cams); closure_t closure1280 = make_closure(lambda1282, &env_t_1282_value);
	return TOP_LEVEL_linalg_vectorMapToMatrix_d(closure1268, range, closure1280, range_d);
}

void TOP_LEVEL_usecases_ba_run_ba_from_file_d(string_t fn, card_t n, card_t m, card_t p, string_t fn_d, card_t n_d, card_t m_d, card_t p_d) {
	
	return ;
}

void TOP_LEVEL_usecases_ba_test_ba_d(array_number_t dum, array_number_t dum_d) {
	
	return ;
}
#endif
