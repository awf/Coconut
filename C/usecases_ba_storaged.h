#ifndef __USECASES_BA_STORAGED_H__ 
#define __USECASES_BA_STORAGED_H__ 
#include "runtime/fsharp.h"
#include <stdio.h>
#include <math.h>
#include "linalg_storaged.h"

card_t $_usecases_ba_radial_distort_shp(card_t rad_params_shp, card_t proj_shp) {
	
	return $_linalg_mult_by_scalar_shp(proj_shp, 0);
}


array_number_t $_usecases_ba_radial_distort_dps(storage_t stgVar616, array_number_t rad_params_dps, array_number_t proj_dps, card_t rad_params_shp, card_t proj_shp) {
	card_t rsq_shp = 0;
	number_t rsq_dps = $_linalg_sqnorm_dps(empty_storage, proj_dps, proj_shp);
	card_t L_shp = 0;
	number_t L_dps = ((1) + ((rad_params_dps->arr[0]) * (rsq_dps))) + (((rad_params_dps->arr[1]) * (rsq_dps)) * (rsq_dps));
	return $_linalg_mult_by_scalar_dps(stgVar616, proj_dps, L_dps, proj_shp, 0);
}

card_t $_usecases_ba_rodrigues_rotate_point_shp(card_t rot_shp, card_t x_shp) {
	
	return $_linalg_vectorAdd_shp($_linalg_vectorAdd_shp($_linalg_mult_by_scalar_shp(x_shp, 0), $_linalg_mult_by_scalar_shp($_linalg_cross_shp($_linalg_mult_by_scalar_shp(rot_shp, 0), x_shp), 0)), $_linalg_mult_by_scalar_shp($_linalg_mult_by_scalar_shp(rot_shp, 0), 0));
}


array_number_t $_usecases_ba_rodrigues_rotate_point_dps(storage_t stgVar626, array_number_t rot_dps, array_number_t x_dps, card_t rot_shp, card_t x_shp) {
	card_t sqtheta_shp = 0;
	number_t sqtheta_dps = $_linalg_sqnorm_dps(empty_storage, rot_dps, rot_shp);
	array_number_t ite755 = 0;
	if((sqtheta_dps) != (0)) {
		card_t theta_shp = 0;
		number_t theta_dps = sqrt(sqtheta_dps);
		card_t costheta_shp = 0;
		number_t costheta_dps = cos(theta_dps);
		card_t sintheta_shp = 0;
		number_t sintheta_dps = sin(theta_dps);
		card_t theta_inv_shp = 0;
		number_t theta_inv_dps = (1) / (theta_dps);
		card_t w_shp = $_linalg_mult_by_scalar_shp(rot_shp, 0);
		card_t size761 = width_card_t(w_shp);
	array_number_t stgVar633 = storage_alloc(size761);
	array_number_t macroDef753;array_number_t w_dps = $_linalg_mult_by_scalar_dps(stgVar633, rot_dps, theta_inv_dps, rot_shp, 0);
	card_t w_cross_X_shp = $_linalg_cross_shp(w_shp, x_shp);
	card_t size760 = width_card_t(w_cross_X_shp);
	array_number_t stgVar636 = storage_alloc(size760);
	array_number_t macroDef752;array_number_t w_cross_X_dps = $_linalg_cross_dps(stgVar636, w_dps, x_dps, w_shp, x_shp);
	card_t tmp_shp = 0;
	number_t tmp_dps = ($_linalg_dot_prod_dps(empty_storage, w_dps, x_dps, w_shp, x_shp)) * ((1) - (costheta_dps));
	card_t v1_shp = $_linalg_mult_by_scalar_shp(x_shp, 0);
	card_t size759 = width_card_t(v1_shp);
	array_number_t stgVar642 = storage_alloc(size759);
	array_number_t macroDef751;array_number_t v1_dps = $_linalg_mult_by_scalar_dps(stgVar642, x_dps, costheta_dps, x_shp, 0);
	card_t v2_shp = $_linalg_mult_by_scalar_shp(w_cross_X_shp, 0);
	card_t size758 = width_card_t(v2_shp);
	array_number_t stgVar645 = storage_alloc(size758);
	array_number_t macroDef750;array_number_t v2_dps = $_linalg_mult_by_scalar_dps(stgVar645, w_cross_X_dps, sintheta_dps, w_cross_X_shp, 0);
	card_t size757 = width_card_t($_linalg_mult_by_scalar_shp(w_shp, 0));
	array_number_t stgVar649 = storage_alloc(size757);
	array_number_t macroDef749;card_t size756 = width_card_t($_linalg_vectorAdd_shp(v1_shp, v2_shp));
	array_number_t stgVar648 = storage_alloc(size756);
	array_number_t macroDef748;
	macroDef748 = $_linalg_vectorAdd_dps(stgVar626, $_linalg_vectorAdd_dps(stgVar648, v1_dps, v2_dps, v1_shp, v2_shp), $_linalg_mult_by_scalar_dps(stgVar649, w_dps, tmp_dps, w_shp, 0), $_linalg_vectorAdd_shp(v1_shp, v2_shp), $_linalg_mult_by_scalar_shp(w_shp, 0));;
	storage_free(stgVar648, size756);
	macroDef749 = macroDef748;;
	storage_free(stgVar649, size757);
	macroDef750 = macroDef749;;
	storage_free(stgVar645, size758);
	macroDef751 = macroDef750;;
	storage_free(stgVar642, size759);
	macroDef752 = macroDef751;;
	storage_free(stgVar636, size760);
	macroDef753 = macroDef752;;
	storage_free(stgVar633, size761);
		ite755 = macroDef753;;
	} else {
		card_t size762 = width_card_t($_linalg_cross_shp(rot_shp, x_shp));
	array_number_t stgVar655 = storage_alloc(size762);
	array_number_t macroDef754;
	macroDef754 = $_linalg_vectorAdd_dps(stgVar626, x_dps, $_linalg_cross_dps(stgVar655, rot_dps, x_dps, rot_shp, x_shp), x_shp, $_linalg_cross_shp(rot_shp, x_shp));;
	storage_free(stgVar655, size762);
		ite755 = macroDef754;;
	}
	return ite755;
}

card_t $_usecases_ba_project_shp(card_t cam_shp, card_t x_shp) {
	
	return $_linalg_vectorAdd_shp($_linalg_vectorSlice_shp(2, 0, cam_shp), $_linalg_mult_by_scalar_shp($_usecases_ba_radial_distort_shp($_linalg_vectorSlice_shp(2, 0, cam_shp), $_linalg_mult_by_scalar_shp($_linalg_vectorSlice_shp(2, 0, $_usecases_ba_rodrigues_rotate_point_shp($_linalg_vectorSlice_shp(3, 0, cam_shp), $_linalg_vectorSub_shp(x_shp, $_linalg_vectorSlice_shp(3, 0, cam_shp)))), 0)), 0));
}


array_number_t $_usecases_ba_project_dps(storage_t stgVar763, array_number_t cam_dps, array_number_t x_dps, card_t cam_shp, card_t x_shp) {
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
	card_t Xcam_shp = $_usecases_ba_rodrigues_rotate_point_shp($_linalg_vectorSlice_shp(3, 0, cam_shp), $_linalg_vectorSub_shp(x_shp, $_linalg_vectorSlice_shp(3, 0, cam_shp)));
	card_t size876 = width_card_t(Xcam_shp);
	array_number_t stgVar770 = storage_alloc(size876);
	array_number_t macroDef866;card_t size869 = width_card_t($_linalg_vectorSub_shp(x_shp, $_linalg_vectorSlice_shp(3, 0, cam_shp)));
	array_number_t stgVar772 = storage_alloc(size869);
	array_number_t macroDef859;card_t size868 = width_card_t($_linalg_vectorSlice_shp(3, 0, cam_shp));
	array_number_t stgVar771 = storage_alloc(size868);
	array_number_t macroDef858;card_t size867 = width_card_t($_linalg_vectorSlice_shp(3, 0, cam_shp));
	array_number_t stgVar777 = storage_alloc(size867);
	array_number_t macroDef857;
	macroDef857 = $_linalg_vectorSub_dps(stgVar772, x_dps, $_linalg_vectorSlice_dps(stgVar777, 3, CENTER_IDX_dps, cam_dps, 3, 0, cam_shp), x_shp, $_linalg_vectorSlice_shp(3, 0, cam_shp));;
	storage_free(stgVar777, size867);
	macroDef858 = $_usecases_ba_rodrigues_rotate_point_dps(stgVar770, $_linalg_vectorSlice_dps(stgVar771, 3, ROT_IDX_dps, cam_dps, 3, 0, cam_shp), macroDef857, $_linalg_vectorSlice_shp(3, 0, cam_shp), $_linalg_vectorSub_shp(x_shp, $_linalg_vectorSlice_shp(3, 0, cam_shp)));;
	storage_free(stgVar771, size868);
	macroDef859 = macroDef858;;
	storage_free(stgVar772, size869);
	array_number_t Xcam_dps = macroDef859;
	card_t distorted_shp = $_usecases_ba_radial_distort_shp($_linalg_vectorSlice_shp(2, 0, cam_shp), $_linalg_mult_by_scalar_shp($_linalg_vectorSlice_shp(2, 0, Xcam_shp), 0));
	card_t size875 = width_card_t(distorted_shp);
	array_number_t stgVar781 = storage_alloc(size875);
	array_number_t macroDef865;card_t size872 = width_card_t($_linalg_mult_by_scalar_shp($_linalg_vectorSlice_shp(2, 0, Xcam_shp), 0));
	array_number_t stgVar783 = storage_alloc(size872);
	array_number_t macroDef862;card_t size871 = width_card_t($_linalg_vectorSlice_shp(2, 0, cam_shp));
	array_number_t stgVar782 = storage_alloc(size871);
	array_number_t macroDef861;card_t size870 = width_card_t($_linalg_vectorSlice_shp(2, 0, Xcam_shp));
	array_number_t stgVar787 = storage_alloc(size870);
	array_number_t macroDef860;
	macroDef860 = $_linalg_mult_by_scalar_dps(stgVar783, $_linalg_vectorSlice_dps(stgVar787, 2, 0, Xcam_dps, 2, 0, Xcam_shp), (1) / (Xcam_dps->arr[2]), $_linalg_vectorSlice_shp(2, 0, Xcam_shp), 0);;
	storage_free(stgVar787, size870);
	macroDef861 = $_usecases_ba_radial_distort_dps(stgVar781, $_linalg_vectorSlice_dps(stgVar782, 2, RAD_IDX_dps, cam_dps, 2, 0, cam_shp), macroDef860, $_linalg_vectorSlice_shp(2, 0, cam_shp), $_linalg_mult_by_scalar_shp($_linalg_vectorSlice_shp(2, 0, Xcam_shp), 0));;
	storage_free(stgVar782, size871);
	macroDef862 = macroDef861;;
	storage_free(stgVar783, size872);
	array_number_t distorted_dps = macroDef862;
	card_t size874 = width_card_t($_linalg_mult_by_scalar_shp(distorted_shp, 0));
	array_number_t stgVar794 = storage_alloc(size874);
	array_number_t macroDef864;card_t size873 = width_card_t($_linalg_vectorSlice_shp(2, 0, cam_shp));
	array_number_t stgVar793 = storage_alloc(size873);
	array_number_t macroDef863;
	macroDef863 = $_linalg_vectorAdd_dps(stgVar763, $_linalg_vectorSlice_dps(stgVar793, 2, X0_IDX_dps, cam_dps, 2, 0, cam_shp), $_linalg_mult_by_scalar_dps(stgVar794, distorted_dps, cam_dps->arr[FOCAL_IDX_dps], distorted_shp, 0), $_linalg_vectorSlice_shp(2, 0, cam_shp), $_linalg_mult_by_scalar_shp(distorted_shp, 0));;
	storage_free(stgVar793, size873);
	macroDef864 = macroDef863;;
	storage_free(stgVar794, size874);
	macroDef865 = macroDef864;;
	storage_free(stgVar781, size875);
	macroDef866 = macroDef865;;
	storage_free(stgVar770, size876);
	return macroDef866;
}

card_t $_usecases_ba_compute_reproj_err_shp(card_t cam_shp, card_t x_shp, card_t w_shp, card_t feat_shp) {
	
	return $_linalg_mult_by_scalar_shp($_linalg_vectorSub_shp($_usecases_ba_project_shp(cam_shp, x_shp), feat_shp), 0);
}


array_number_t $_usecases_ba_compute_reproj_err_dps(storage_t stgVar877, array_number_t cam_dps, array_number_t x_dps, number_t w_dps, array_number_t feat_dps, card_t cam_shp, card_t x_shp, card_t w_shp, card_t feat_shp) {
	card_t size887 = width_card_t($_linalg_vectorSub_shp($_usecases_ba_project_shp(cam_shp, x_shp), feat_shp));
	array_number_t stgVar878 = storage_alloc(size887);
	array_number_t macroDef885;card_t size886 = width_card_t($_usecases_ba_project_shp(cam_shp, x_shp));
	array_number_t stgVar880 = storage_alloc(size886);
	array_number_t macroDef884;
	macroDef884 = $_linalg_vectorSub_dps(stgVar878, $_usecases_ba_project_dps(stgVar880, cam_dps, x_dps, cam_shp, x_shp), feat_dps, $_usecases_ba_project_shp(cam_shp, x_shp), feat_shp);;
	storage_free(stgVar880, size886);
	macroDef885 = $_linalg_mult_by_scalar_dps(stgVar877, macroDef884, w_dps, $_linalg_vectorSub_shp($_usecases_ba_project_shp(cam_shp, x_shp), feat_shp), 0);;
	storage_free(stgVar878, size887);
	return macroDef885;
}

card_t $_usecases_ba_compute_zach_weight_error_shp(card_t w_shp) {
	
	return 0;
}


number_t $_usecases_ba_compute_zach_weight_error_dps(storage_t stgVar888, number_t w_dps, card_t w_shp) {
	
	return (1) - ((w_dps) * (w_dps));
}
typedef empty_env_t env_t_897;


value_t lambda897(env_t_897* env894, card_t w_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
card_t $_usecases_ba_w_err_shp(card_t w_shp) {
	env_t_897 env_t_897_value = make_empty_env(); closure_t closure896 = make_closure(lambda897, &env_t_897_value);
	return $_linalg_vectorMap_shp(closure896, w_shp);
}

typedef empty_env_t env_t_904;


value_t lambda904(env_t_904* env898, storage_t stgVar892, number_t w_dps0, card_t w_shp0) {
	
	value_t res;
	res.number_t_value = $_usecases_ba_compute_zach_weight_error_dps(stgVar892, w_dps0, 0);
	return res;
}
typedef empty_env_t env_t_905;


value_t lambda905(env_t_905* env901, card_t w_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
array_number_t $_usecases_ba_w_err_dps(storage_t stgVar889, array_number_t w_dps, card_t w_shp) {
	env_t_904 env_t_904_value = make_empty_env(); closure_t closure900 = make_closure(lambda904, &env_t_904_value);
	env_t_905 env_t_905_value = make_empty_env(); closure_t closure903 = make_closure(lambda905, &env_t_905_value);
	return $_linalg_vectorMap_dps(stgVar889, closure900, w_dps, closure903, w_shp);
}
typedef struct env_t_941 {
	matrix_shape_t x_shp;
	matrix_shape_t feat_shp;
	matrix_shape_t cams_shp;
} env_t_941;
env_t_941 make_env_t_941(matrix_shape_t x_shp,matrix_shape_t feat_shp,matrix_shape_t cams_shp) {
	env_t_941 env;
	env.x_shp = x_shp;
	env.feat_shp = feat_shp;
	env.cams_shp = cams_shp;
	return env;
}

value_t lambda941(env_t_941* env938, card_t i_shp) {
	matrix_shape_t x_shp937 = env938->x_shp;
	matrix_shape_t feat_shp936 = env938->feat_shp;
	matrix_shape_t cams_shp935 = env938->cams_shp;
	value_t res;
	res.card_t_value = $_usecases_ba_compute_reproj_err_shp(cams_shp935.elem, x_shp937.elem, 0, feat_shp936.elem);
	return res;
}
matrix_shape_t $_usecases_ba_reproj_err_shp(matrix_shape_t cams_shp, matrix_shape_t x_shp, card_t w_shp, matrix_shape_t obs_shp, matrix_shape_t feat_shp) {
	env_t_941 env_t_941_value = make_env_t_941(x_shp,feat_shp,cams_shp); closure_t closure940 = make_closure(lambda941, &env_t_941_value);
	return $_linalg_vectorMapToMatrix_shp(closure940, $_linalg_vectorRange_shp(0, (w_shp) - (1)));
}

typedef struct env_t_968 {
	matrix_shape_t x_shp;
	array_array_number_t x_dps;
	array_number_t w_dps;
	matrix_shape_t obs_shp;
	array_array_number_t obs_dps;
	matrix_shape_t feat_shp;
	array_array_number_t feat_dps;
	matrix_shape_t cams_shp;
	array_array_number_t cams_dps;
} env_t_968;
env_t_968 make_env_t_968(matrix_shape_t x_shp,array_array_number_t x_dps,array_number_t w_dps,matrix_shape_t obs_shp,array_array_number_t obs_dps,matrix_shape_t feat_shp,array_array_number_t feat_dps,matrix_shape_t cams_shp,array_array_number_t cams_dps) {
	env_t_968 env;
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

value_t lambda968(env_t_968* env958, storage_t stgVar916, number_t i_dps, card_t i_shp) {
	matrix_shape_t x_shp957 = env958->x_shp;
	array_array_number_t x_dps956 = env958->x_dps;
	array_number_t w_dps955 = env958->w_dps;
	matrix_shape_t obs_shp954 = env958->obs_shp;
	array_array_number_t obs_dps953 = env958->obs_dps;
	matrix_shape_t feat_shp952 = env958->feat_shp;
	array_array_number_t feat_dps951 = env958->feat_dps;
	matrix_shape_t cams_shp950 = env958->cams_shp;
	array_array_number_t cams_dps949 = env958->cams_dps;
	card_t size973 = width_card_t(feat_shp952.elem);
	array_number_t stgVar920 = storage_alloc(size973);
	array_number_t macroDef948;card_t size972 = width_card_t(x_shp957.elem);
	array_number_t stgVar918 = storage_alloc(size972);
	array_number_t macroDef947;card_t size971 = width_card_t(cams_shp950.elem);
	array_number_t stgVar917 = storage_alloc(size971);
	array_number_t macroDef946;card_t size969 = width_card_t(obs_shp954.elem);
	array_number_t stgVar922 = storage_alloc(size969);
	number_t macroDef944;
	macroDef944 = obs_dps953->arr[(int)(i_dps)]->arr[0];;
	storage_free(stgVar922, size969);
	card_t size970 = width_card_t(obs_shp954.elem);
	array_number_t stgVar925 = storage_alloc(size970);
	number_t macroDef945;
	macroDef945 = obs_dps953->arr[(int)(i_dps)]->arr[1];;
	storage_free(stgVar925, size970);
	macroDef946 = $_usecases_ba_compute_reproj_err_dps(stgVar916, cams_dps949->arr[(int)(macroDef944)], x_dps956->arr[(int)(macroDef945)], w_dps955->arr[(int)(i_dps)], feat_dps951->arr[(int)(i_dps)], cams_shp950.elem, x_shp957.elem, 0, feat_shp952.elem);;
	storage_free(stgVar917, size971);
	macroDef947 = macroDef946;;
	storage_free(stgVar918, size972);
	macroDef948 = macroDef947;;
	storage_free(stgVar920, size973);
	value_t res;
	res.array_number_t_value = macroDef948;
	return res;
}
typedef struct env_t_974 {
	matrix_shape_t x_shp;
	matrix_shape_t feat_shp;
	matrix_shape_t cams_shp;
} env_t_974;
env_t_974 make_env_t_974(matrix_shape_t x_shp,matrix_shape_t feat_shp,matrix_shape_t cams_shp) {
	env_t_974 env;
	env.x_shp = x_shp;
	env.feat_shp = feat_shp;
	env.cams_shp = cams_shp;
	return env;
}

value_t lambda974(env_t_974* env964, card_t i_shp) {
	matrix_shape_t x_shp963 = env964->x_shp;
	matrix_shape_t feat_shp962 = env964->feat_shp;
	matrix_shape_t cams_shp961 = env964->cams_shp;
	value_t res;
	res.card_t_value = $_usecases_ba_compute_reproj_err_shp(cams_shp961.elem, x_shp963.elem, 0, feat_shp962.elem);
	return res;
}
array_array_number_t $_usecases_ba_reproj_err_dps(storage_t stgVar906, array_array_number_t cams_dps, array_array_number_t x_dps, array_number_t w_dps, array_array_number_t obs_dps, array_array_number_t feat_dps, matrix_shape_t cams_shp, matrix_shape_t x_shp, card_t w_shp, matrix_shape_t obs_shp, matrix_shape_t feat_shp) {
	card_t n_shp = cams_shp.card;
	card_t macroDef942 = cams_dps->length;
	card_t n_dps = macroDef942;
	card_t p_shp = w_shp;
	card_t macroDef943 = w_dps->length;
	card_t p_dps = macroDef943;
	card_t range_shp = $_linalg_vectorRange_shp(0, (p_shp) - (1));
	card_t size975 = width_card_t(range_shp);
	array_number_t stgVar911 = storage_alloc(size975);
	array_array_number_t macroDef967;array_number_t range_dps = $_linalg_vectorRange_dps(stgVar911, 0, (p_dps) - (1), 0, (p_shp) - (1));
	env_t_968 env_t_968_value = make_env_t_968(x_shp,x_dps,w_dps,obs_shp,obs_dps,feat_shp,feat_dps,cams_shp,cams_dps); closure_t closure960 = make_closure(lambda968, &env_t_968_value);
	env_t_974 env_t_974_value = make_env_t_974(x_shp,feat_shp,cams_shp); closure_t closure966 = make_closure(lambda974, &env_t_974_value);
	macroDef967 = $_linalg_vectorMapToMatrix_dps(stgVar906, closure960, range_dps, closure966, range_shp);;
	storage_free(stgVar911, size975);
	return macroDef967;
}
typedef empty_env_t env_t_1155;


value_t lambda1155(env_t_1155* env1149, card_t x_shp) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef empty_env_t env_t_1156;


value_t lambda1156(env_t_1156* env1152, card_t x_shp) {
	
	value_t res;
	res.card_t_value = $_linalg_vectorRead_shp(0, 0);
	return res;
}
matrix_shape_t $_usecases_ba_run_ba_from_file_shp(card_t fn_shp, card_t n_shp, card_t m_shp, card_t p_shp) {
	env_t_1155 env_t_1155_value = make_empty_env(); closure_t closure1151 = make_closure(lambda1155, &env_t_1155_value);
	env_t_1156 env_t_1156_value = make_empty_env(); closure_t closure1154 = make_closure(lambda1156, &env_t_1156_value);
	return $_usecases_ba_reproj_err_shp(nested_shape_card_t($_linalg_vectorRead_shp(0, 0), n_shp), nested_shape_card_t($_linalg_vectorRead_shp(0, 0), m_shp), $_linalg_vectorMap_shp(closure1151, $_linalg_vectorRange_shp(1, p_shp)), nested_shape_card_t(2, p_shp), $_linalg_vectorMapToMatrix_shp(closure1154, $_linalg_vectorRange_shp(1, p_shp)));
}

typedef struct env_t_1206 {
	card_t one_cam_shp;
} env_t_1206;
env_t_1206 make_env_t_1206(card_t one_cam_shp) {
	env_t_1206 env;
	env.one_cam_shp = one_cam_shp;
	return env;
}

value_t lambda1206(env_t_1206* env1158, card_t x_shp) {
	card_t one_cam_shp1157 = env1158->one_cam_shp;
	value_t res;
	res.card_t_value = one_cam_shp1157;
	return res;
}
typedef struct env_t_1207 {
	card_t one_x_shp;
} env_t_1207;
env_t_1207 make_env_t_1207(card_t one_x_shp) {
	env_t_1207 env;
	env.one_x_shp = one_x_shp;
	return env;
}

value_t lambda1207(env_t_1207* env1163, card_t x_shp) {
	card_t one_x_shp1162 = env1163->one_x_shp;
	value_t res;
	res.card_t_value = one_x_shp1162;
	return res;
}
typedef empty_env_t env_t_1208;


value_t lambda1208(env_t_1208* env1167, card_t x_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef struct env_t_1209 {
	number_t one_w_dps;
} env_t_1209;
env_t_1209 make_env_t_1209(number_t one_w_dps) {
	env_t_1209 env;
	env.one_w_dps = one_w_dps;
	return env;
}

value_t lambda1209(env_t_1209* env1171, storage_t stgVar994, number_t x_dps0, card_t x_shp0) {
	number_t one_w_dps1170 = env1171->one_w_dps;
	value_t res;
	res.number_t_value = one_w_dps1170;
	return res;
}
typedef empty_env_t env_t_1210;


value_t lambda1210(env_t_1210* env1174, card_t x_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef struct env_t_1212 {
	card_t one_feat_shp;
} env_t_1212;
env_t_1212 make_env_t_1212(card_t one_feat_shp) {
	env_t_1212 env;
	env.one_feat_shp = one_feat_shp;
	return env;
}

value_t lambda1212(env_t_1212* env1179, card_t x_shp0) {
	card_t one_feat_shp1178 = env1179->one_feat_shp;
	value_t res;
	res.card_t_value = one_feat_shp1178;
	return res;
}
typedef struct env_t_1213 {
	array_number_t one_feat_dps;
} env_t_1213;
env_t_1213 make_env_t_1213(array_number_t one_feat_dps) {
	env_t_1213 env;
	env.one_feat_dps = one_feat_dps;
	return env;
}

value_t lambda1213(env_t_1213* env1183, storage_t stgVar1003, number_t x_dps0, card_t x_shp0) {
	array_number_t one_feat_dps1182 = env1183->one_feat_dps;
	value_t res;
	res.array_number_t_value = one_feat_dps1182;
	return res;
}
typedef struct env_t_1214 {
	card_t one_feat_shp;
} env_t_1214;
env_t_1214 make_env_t_1214(card_t one_feat_shp) {
	env_t_1214 env;
	env.one_feat_shp = one_feat_shp;
	return env;
}

value_t lambda1214(env_t_1214* env1187, card_t x_shp0) {
	card_t one_feat_shp1186 = env1187->one_feat_shp;
	value_t res;
	res.card_t_value = one_feat_shp1186;
	return res;
}
typedef empty_env_t env_t_1216;


value_t lambda1216(env_t_1216* env1191, card_t x_shp0) {
	
	value_t res;
	res.card_t_value = 2;
	return res;
}
array_array_number_t $_usecases_ba_run_ba_from_file_dps(storage_t stgVar976, string_t fn_dps, card_t n_dps, card_t m_dps, card_t p_dps, card_t fn_shp, card_t n_shp, card_t m_shp, card_t p_shp) {
	card_t oneCard_shp = 1;
	card_t oneCard_dps = 1;
	card_t one_cam_shp = $_linalg_vectorRead_shp(0, 0);
	card_t size1225 = width_card_t(one_cam_shp);
	array_number_t stgVar978 = storage_alloc(size1225);
	array_array_number_t macroDef1204;array_number_t one_cam_dps = $_linalg_vectorRead_dps(stgVar978, fn_dps, 1, 0, 0);
	env_t_1206 env_t_1206_value = make_env_t_1206(one_cam_shp); closure_t closure1160 = make_closure(lambda1206, &env_t_1206_value);
	matrix_shape_t cam_shp = nested_shape_card_t(closure1160.lam(closure1160.env, 0).card_t_value, n_shp);
	card_t size1224 = width_matrix_shape_t(cam_shp);
	array_number_t stgVar981 = storage_alloc(size1224);
	array_array_number_t macroDef1203;array_array_number_t macroDef1161 = (array_array_number_t)stgVar981;
		macroDef1161->length=n_dps;
		macroDef1161->arr=(array_number_t*)(STG_OFFSET(macroDef1161, VECTOR_HEADER_BYTES));
		storage_t stgVar982 = (STG_OFFSET(macroDef1161, MATRIX_HEADER_BYTES(n_dps)));
		for(int x_dps = 0; x_dps < macroDef1161->length; x_dps++){
			
			macroDef1161->arr[x_dps] = one_cam_dps;;
			stgVar982 = STG_OFFSET(stgVar982, VECTOR_ALL_BYTES(macroDef1161->arr[x_dps]->length));
		}
	array_array_number_t cam_dps = macroDef1161;
	card_t one_x_shp = $_linalg_vectorRead_shp(0, 0);
	card_t size1223 = width_card_t(one_x_shp);
	array_number_t stgVar983 = storage_alloc(size1223);
	array_array_number_t macroDef1202;array_number_t one_x_dps = $_linalg_vectorRead_dps(stgVar983, fn_dps, 2, 0, 0);
	env_t_1207 env_t_1207_value = make_env_t_1207(one_x_shp); closure_t closure1165 = make_closure(lambda1207, &env_t_1207_value);
	matrix_shape_t x_shp = nested_shape_card_t(closure1165.lam(closure1165.env, 0).card_t_value, m_shp);
	card_t size1222 = width_matrix_shape_t(x_shp);
	array_number_t stgVar986 = storage_alloc(size1222);
	array_array_number_t macroDef1201;array_array_number_t macroDef1166 = (array_array_number_t)stgVar986;
		macroDef1166->length=m_dps;
		macroDef1166->arr=(array_number_t*)(STG_OFFSET(macroDef1166, VECTOR_HEADER_BYTES));
		storage_t stgVar987 = (STG_OFFSET(macroDef1166, MATRIX_HEADER_BYTES(m_dps)));
		for(int x_dps = 0; x_dps < macroDef1166->length; x_dps++){
			
			macroDef1166->arr[x_dps] = one_x_dps;;
			stgVar987 = STG_OFFSET(stgVar987, VECTOR_ALL_BYTES(macroDef1166->arr[x_dps]->length));
		}
	array_array_number_t x_dps = macroDef1166;
	card_t one_w_shp = 0;
	number_t one_w_dps = $_linalg_numberRead_dps(empty_storage, fn_dps, 3, 0, 0);
	env_t_1208 env_t_1208_value = make_empty_env(); closure_t closure1169 = make_closure(lambda1208, &env_t_1208_value);
	card_t w_shp = $_linalg_vectorMap_shp(closure1169, $_linalg_vectorRange_shp(oneCard_shp, p_shp));
	card_t size1221 = width_card_t(w_shp);
	array_number_t stgVar991 = storage_alloc(size1221);
	array_array_number_t macroDef1200;card_t size1211 = width_card_t($_linalg_vectorRange_shp(oneCard_shp, p_shp));
	array_number_t stgVar993 = storage_alloc(size1211);
	array_number_t macroDef1177;env_t_1209 env_t_1209_value = make_env_t_1209(one_w_dps); closure_t closure1173 = make_closure(lambda1209, &env_t_1209_value);
	env_t_1210 env_t_1210_value = make_empty_env(); closure_t closure1176 = make_closure(lambda1210, &env_t_1210_value);
	macroDef1177 = $_linalg_vectorMap_dps(stgVar991, closure1173, $_linalg_vectorRange_dps(stgVar993, oneCard_dps, p_dps, oneCard_shp, p_shp), closure1176, $_linalg_vectorRange_shp(oneCard_shp, p_shp));;
	storage_free(stgVar993, size1211);
	array_number_t w_dps = macroDef1177;
	card_t one_feat_shp = $_linalg_vectorRead_shp(0, 0);
	card_t size1220 = width_card_t(one_feat_shp);
	array_number_t stgVar997 = storage_alloc(size1220);
	array_array_number_t macroDef1199;array_number_t one_feat_dps = $_linalg_vectorRead_dps(stgVar997, fn_dps, 4, 0, 0);
	env_t_1212 env_t_1212_value = make_env_t_1212(one_feat_shp); closure_t closure1181 = make_closure(lambda1212, &env_t_1212_value);
	matrix_shape_t feat_shp = $_linalg_vectorMapToMatrix_shp(closure1181, $_linalg_vectorRange_shp(oneCard_shp, p_shp));
	card_t size1219 = width_matrix_shape_t(feat_shp);
	array_number_t stgVar1000 = storage_alloc(size1219);
	array_array_number_t macroDef1198;card_t size1215 = width_card_t($_linalg_vectorRange_shp(oneCard_shp, p_shp));
	array_number_t stgVar1002 = storage_alloc(size1215);
	array_array_number_t macroDef1190;env_t_1213 env_t_1213_value = make_env_t_1213(one_feat_dps); closure_t closure1185 = make_closure(lambda1213, &env_t_1213_value);
	env_t_1214 env_t_1214_value = make_env_t_1214(one_feat_shp); closure_t closure1189 = make_closure(lambda1214, &env_t_1214_value);
	macroDef1190 = $_linalg_vectorMapToMatrix_dps(stgVar1000, closure1185, $_linalg_vectorRange_dps(stgVar1002, oneCard_dps, p_dps, oneCard_shp, p_shp), closure1189, $_linalg_vectorRange_shp(oneCard_shp, p_shp));;
	storage_free(stgVar1002, size1215);
	array_array_number_t feat_dps = macroDef1190;
	env_t_1216 env_t_1216_value = make_empty_env(); closure_t closure1193 = make_closure(lambda1216, &env_t_1216_value);
	matrix_shape_t obs_shp = nested_shape_card_t(closure1193.lam(closure1193.env, 0).card_t_value, p_shp);
	card_t size1218 = width_matrix_shape_t(obs_shp);
	array_number_t stgVar1006 = storage_alloc(size1218);
	array_array_number_t macroDef1197;array_array_number_t macroDef1195 = (array_array_number_t)stgVar1006;
		macroDef1195->length=p_dps;
		macroDef1195->arr=(array_number_t*)(STG_OFFSET(macroDef1195, VECTOR_HEADER_BYTES));
		storage_t stgVar1007 = (STG_OFFSET(macroDef1195, MATRIX_HEADER_BYTES(p_dps)));
		for(int x_dps0 = 0; x_dps0 < macroDef1195->length; x_dps0++){
			array_number_t macroDef1194 = (array_number_t)stgVar1007;
	macroDef1194->length=2;
	macroDef1194->arr=(number_t*)(STG_OFFSET(stgVar1007, VECTOR_HEADER_BYTES));
	macroDef1194->arr[0] = (double)(((int)(x_dps0)) % ((n_dps)));
	macroDef1194->arr[1] = (double)(((int)(x_dps0)) % ((m_dps)));;
			macroDef1195->arr[x_dps0] = macroDef1194;;
			stgVar1007 = STG_OFFSET(stgVar1007, VECTOR_ALL_BYTES(macroDef1195->arr[x_dps0]->length));
		}
	array_array_number_t obs_dps = macroDef1195;
	card_t t_shp = 0;
	timer_t t_dps = tic();
	matrix_shape_t res_shp = $_usecases_ba_reproj_err_shp(cam_shp, x_shp, w_shp, obs_shp, feat_shp);
	card_t size1217 = width_matrix_shape_t(res_shp);
	array_number_t stgVar1011 = storage_alloc(size1217);
	array_array_number_t macroDef1196;array_array_number_t res_dps = $_usecases_ba_reproj_err_dps(stgVar1011, cam_dps, x_dps, w_dps, obs_dps, feat_dps, cam_shp, x_shp, w_shp, obs_shp, feat_shp);
	toc(t_dps);
	macroDef1196 = res_dps;;
	storage_free(stgVar1011, size1217);
	macroDef1197 = macroDef1196;;
	storage_free(stgVar1006, size1218);
	macroDef1198 = macroDef1197;;
	storage_free(stgVar1000, size1219);
	macroDef1199 = macroDef1198;;
	storage_free(stgVar997, size1220);
	macroDef1200 = macroDef1199;;
	storage_free(stgVar991, size1221);
	macroDef1201 = macroDef1200;;
	storage_free(stgVar986, size1222);
	macroDef1202 = macroDef1201;;
	storage_free(stgVar983, size1223);
	macroDef1203 = macroDef1202;;
	storage_free(stgVar981, size1224);
	macroDef1204 = macroDef1203;;
	storage_free(stgVar978, size1225);
	return macroDef1204;
}

card_t $_usecases_ba_test_ba_shp(card_t dum_shp) {
	
	return 0;
}


void $_usecases_ba_test_ba_dps(storage_t stgVar1226, array_number_t dum_dps, card_t dum_shp) {
	card_t a_shp = 3;
	card_t size1282 = width_card_t(a_shp);
	array_number_t stgVar1227 = storage_alloc(size1282);
	array_number_t macroDef1260 = (array_number_t)stgVar1227;
	macroDef1260->length=3;
	macroDef1260->arr=(number_t*)(STG_OFFSET(stgVar1227, VECTOR_HEADER_BYTES));
	macroDef1260->arr[0] = 1;
	macroDef1260->arr[1] = 2;
	macroDef1260->arr[2] = 3;;
	array_number_t a_dps = macroDef1260;
	card_t b_shp = 3;
	card_t size1281 = width_card_t(b_shp);
	array_number_t stgVar1231 = storage_alloc(size1281);
	array_number_t macroDef1261 = (array_number_t)stgVar1231;
	macroDef1261->length=3;
	macroDef1261->arr=(number_t*)(STG_OFFSET(stgVar1231, VECTOR_HEADER_BYTES));
	macroDef1261->arr[0] = 5;
	macroDef1261->arr[1] = 6;
	macroDef1261->arr[2] = 7;;
	array_number_t b_dps = macroDef1261;
	array_print(a_dps);
	array_print(b_dps);
	card_t j_shp = $_usecases_ba_radial_distort_shp(a_shp, b_shp);
	card_t size1280 = width_card_t(j_shp);
	array_number_t stgVar1235 = storage_alloc(size1280);
	array_number_t j_dps = $_usecases_ba_radial_distort_dps(stgVar1235, a_dps, b_dps, a_shp, b_shp);
	array_print(j_dps);
	card_t k_shp = $_usecases_ba_rodrigues_rotate_point_shp(a_shp, b_shp);
	card_t size1279 = width_card_t(k_shp);
	array_number_t stgVar1238 = storage_alloc(size1279);
	array_number_t k_dps = $_usecases_ba_rodrigues_rotate_point_dps(stgVar1238, a_dps, b_dps, a_shp, b_shp);
	array_print(k_dps);
	card_t l_shp = $_linalg_vectorSlice_shp(2, 0, k_shp);
	card_t size1278 = width_card_t(l_shp);
	array_number_t stgVar1241 = storage_alloc(size1278);
	array_number_t l_dps = $_linalg_vectorSlice_dps(stgVar1241, 2, 1, k_dps, 2, 0, k_shp);
	array_print(l_dps);
	card_t cam_shp = 11;
	card_t size1277 = width_card_t(cam_shp);
	array_number_t stgVar1245 = storage_alloc(size1277);
	array_number_t macroDef1262 = (array_number_t)stgVar1245;
	macroDef1262->length=11;
	macroDef1262->arr=(number_t*)(STG_OFFSET(stgVar1245, VECTOR_HEADER_BYTES));
	macroDef1262->arr[0] = 0;
	macroDef1262->arr[1] = 2;
	macroDef1262->arr[2] = 4;
	macroDef1262->arr[3] = 6;
	macroDef1262->arr[4] = 8;
	macroDef1262->arr[5] = 10;
	macroDef1262->arr[6] = 12;
	macroDef1262->arr[7] = 14;
	macroDef1262->arr[8] = 16;
	macroDef1262->arr[9] = 18;
	macroDef1262->arr[10] = 20;;
	array_number_t cam_dps = macroDef1262;
	card_t m_shp = $_usecases_ba_project_shp(cam_shp, j_shp);
	card_t size1276 = width_card_t(m_shp);
	array_number_t stgVar1257 = storage_alloc(size1276);
	array_number_t m_dps = $_usecases_ba_project_dps(stgVar1257, cam_dps, j_dps, cam_shp, j_shp);
	array_print(m_dps);
	;
	storage_free(stgVar1257, size1276);
	;
	storage_free(stgVar1245, size1277);
	;
	storage_free(stgVar1241, size1278);
	;
	storage_free(stgVar1238, size1279);
	;
	storage_free(stgVar1235, size1280);
	;
	storage_free(stgVar1231, size1281);
	;
	storage_free(stgVar1227, size1282);
	return ;
}
#endif
