#ifndef __USECASES_BA_STORAGED_H__ 
#define __USECASES_BA_STORAGED_H__ 
#include "runtime/fsharp.h"
#include <stdio.h>
#include <math.h>
#include "linalg_storaged.h"

card_t TOP_LEVEL_usecases_ba_radial_distort_shp(card_t rad_params_shp, card_t proj_shp) {
	
	return TOP_LEVEL_linalg_mult_by_scalar_shp(proj_shp, 0);
}


array_number_t TOP_LEVEL_usecases_ba_radial_distort_dps(storage_t stgVar639, array_number_t rad_params_dps, array_number_t proj_dps, card_t rad_params_shp, card_t proj_shp) {
	card_t rsq_shp = 0;
	number_t rsq_dps = TOP_LEVEL_linalg_sqnorm_dps(empty_storage, proj_dps, proj_shp);
	card_t L_shp = 0;
	number_t L_dps = ((1) + ((rad_params_dps->arr[0]) * (rsq_dps))) + (((rad_params_dps->arr[1]) * (rsq_dps)) * (rsq_dps));
	return TOP_LEVEL_linalg_mult_by_scalar_dps(stgVar639, proj_dps, L_dps, proj_shp, 0);
}

card_t TOP_LEVEL_usecases_ba_rodrigues_rotate_point_shp(card_t rot_shp, card_t x_shp) {
	
	return TOP_LEVEL_linalg_vectorAdd_shp(TOP_LEVEL_linalg_vectorAdd_shp(TOP_LEVEL_linalg_mult_by_scalar_shp(x_shp, 0), TOP_LEVEL_linalg_mult_by_scalar_shp(TOP_LEVEL_linalg_cross_shp(TOP_LEVEL_linalg_mult_by_scalar_shp(rot_shp, 0), x_shp), 0)), TOP_LEVEL_linalg_mult_by_scalar_shp(TOP_LEVEL_linalg_mult_by_scalar_shp(rot_shp, 0), 0));
}


array_number_t TOP_LEVEL_usecases_ba_rodrigues_rotate_point_dps(storage_t stgVar649, array_number_t rot_dps, array_number_t x_dps, card_t rot_shp, card_t x_shp) {
	card_t sqtheta_shp = 0;
	number_t sqtheta_dps = TOP_LEVEL_linalg_sqnorm_dps(empty_storage, rot_dps, rot_shp);
	array_number_t ite778 = 0;
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
		card_t size784 = width_card_t(w_shp);
	array_number_t stgVar656 = storage_alloc(size784);
	array_number_t macroDef776;array_number_t w_dps = TOP_LEVEL_linalg_mult_by_scalar_dps(stgVar656, rot_dps, theta_inv_dps, rot_shp, 0);
	card_t w_cross_X_shp = TOP_LEVEL_linalg_cross_shp(w_shp, x_shp);
	card_t size783 = width_card_t(w_cross_X_shp);
	array_number_t stgVar659 = storage_alloc(size783);
	array_number_t macroDef775;array_number_t w_cross_X_dps = TOP_LEVEL_linalg_cross_dps(stgVar659, w_dps, x_dps, w_shp, x_shp);
	card_t tmp_shp = 0;
	number_t tmp_dps = (TOP_LEVEL_linalg_dot_prod_dps(empty_storage, w_dps, x_dps, w_shp, x_shp)) * ((1) - (costheta_dps));
	card_t v1_shp = TOP_LEVEL_linalg_mult_by_scalar_shp(x_shp, 0);
	card_t size782 = width_card_t(v1_shp);
	array_number_t stgVar665 = storage_alloc(size782);
	array_number_t macroDef774;array_number_t v1_dps = TOP_LEVEL_linalg_mult_by_scalar_dps(stgVar665, x_dps, costheta_dps, x_shp, 0);
	card_t v2_shp = TOP_LEVEL_linalg_mult_by_scalar_shp(w_cross_X_shp, 0);
	card_t size781 = width_card_t(v2_shp);
	array_number_t stgVar668 = storage_alloc(size781);
	array_number_t macroDef773;array_number_t v2_dps = TOP_LEVEL_linalg_mult_by_scalar_dps(stgVar668, w_cross_X_dps, sintheta_dps, w_cross_X_shp, 0);
	card_t size780 = width_card_t(TOP_LEVEL_linalg_mult_by_scalar_shp(w_shp, 0));
	array_number_t stgVar672 = storage_alloc(size780);
	array_number_t macroDef772;card_t size779 = width_card_t(TOP_LEVEL_linalg_vectorAdd_shp(v1_shp, v2_shp));
	array_number_t stgVar671 = storage_alloc(size779);
	array_number_t macroDef771;
	macroDef771 = TOP_LEVEL_linalg_vectorAdd_dps(stgVar649, TOP_LEVEL_linalg_vectorAdd_dps(stgVar671, v1_dps, v2_dps, v1_shp, v2_shp), TOP_LEVEL_linalg_mult_by_scalar_dps(stgVar672, w_dps, tmp_dps, w_shp, 0), TOP_LEVEL_linalg_vectorAdd_shp(v1_shp, v2_shp), TOP_LEVEL_linalg_mult_by_scalar_shp(w_shp, 0));;
	storage_free(stgVar671, size779);
	macroDef772 = macroDef771;;
	storage_free(stgVar672, size780);
	macroDef773 = macroDef772;;
	storage_free(stgVar668, size781);
	macroDef774 = macroDef773;;
	storage_free(stgVar665, size782);
	macroDef775 = macroDef774;;
	storage_free(stgVar659, size783);
	macroDef776 = macroDef775;;
	storage_free(stgVar656, size784);
		ite778 = macroDef776;;
	} else {
		card_t size785 = width_card_t(TOP_LEVEL_linalg_cross_shp(rot_shp, x_shp));
	array_number_t stgVar678 = storage_alloc(size785);
	array_number_t macroDef777;
	macroDef777 = TOP_LEVEL_linalg_vectorAdd_dps(stgVar649, x_dps, TOP_LEVEL_linalg_cross_dps(stgVar678, rot_dps, x_dps, rot_shp, x_shp), x_shp, TOP_LEVEL_linalg_cross_shp(rot_shp, x_shp));;
	storage_free(stgVar678, size785);
		ite778 = macroDef777;;
	}
	return ite778;
}

card_t TOP_LEVEL_usecases_ba_project_shp(card_t cam_shp, card_t x_shp) {
	
	return TOP_LEVEL_linalg_vectorAdd_shp(TOP_LEVEL_linalg_vectorSlice_shp(2, 0, cam_shp), TOP_LEVEL_linalg_mult_by_scalar_shp(TOP_LEVEL_usecases_ba_radial_distort_shp(TOP_LEVEL_linalg_vectorSlice_shp(2, 0, cam_shp), TOP_LEVEL_linalg_mult_by_scalar_shp(TOP_LEVEL_linalg_vectorSlice_shp(2, 0, TOP_LEVEL_usecases_ba_rodrigues_rotate_point_shp(TOP_LEVEL_linalg_vectorSlice_shp(3, 0, cam_shp), TOP_LEVEL_linalg_vectorSub_shp(x_shp, TOP_LEVEL_linalg_vectorSlice_shp(3, 0, cam_shp)))), 0)), 0));
}


array_number_t TOP_LEVEL_usecases_ba_project_dps(storage_t stgVar786, array_number_t cam_dps, array_number_t x_dps, card_t cam_shp, card_t x_shp) {
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
	card_t size899 = width_card_t(Xcam_shp);
	array_number_t stgVar793 = storage_alloc(size899);
	array_number_t macroDef889;card_t size892 = width_card_t(TOP_LEVEL_linalg_vectorSub_shp(x_shp, TOP_LEVEL_linalg_vectorSlice_shp(3, 0, cam_shp)));
	array_number_t stgVar795 = storage_alloc(size892);
	array_number_t macroDef882;card_t size891 = width_card_t(TOP_LEVEL_linalg_vectorSlice_shp(3, 0, cam_shp));
	array_number_t stgVar794 = storage_alloc(size891);
	array_number_t macroDef881;card_t size890 = width_card_t(TOP_LEVEL_linalg_vectorSlice_shp(3, 0, cam_shp));
	array_number_t stgVar800 = storage_alloc(size890);
	array_number_t macroDef880;
	macroDef880 = TOP_LEVEL_linalg_vectorSub_dps(stgVar795, x_dps, TOP_LEVEL_linalg_vectorSlice_dps(stgVar800, 3, CENTER_IDX_dps, cam_dps, 3, 0, cam_shp), x_shp, TOP_LEVEL_linalg_vectorSlice_shp(3, 0, cam_shp));;
	storage_free(stgVar800, size890);
	macroDef881 = TOP_LEVEL_usecases_ba_rodrigues_rotate_point_dps(stgVar793, TOP_LEVEL_linalg_vectorSlice_dps(stgVar794, 3, ROT_IDX_dps, cam_dps, 3, 0, cam_shp), macroDef880, TOP_LEVEL_linalg_vectorSlice_shp(3, 0, cam_shp), TOP_LEVEL_linalg_vectorSub_shp(x_shp, TOP_LEVEL_linalg_vectorSlice_shp(3, 0, cam_shp)));;
	storage_free(stgVar794, size891);
	macroDef882 = macroDef881;;
	storage_free(stgVar795, size892);
	array_number_t Xcam_dps = macroDef882;
	card_t distorted_shp = TOP_LEVEL_usecases_ba_radial_distort_shp(TOP_LEVEL_linalg_vectorSlice_shp(2, 0, cam_shp), TOP_LEVEL_linalg_mult_by_scalar_shp(TOP_LEVEL_linalg_vectorSlice_shp(2, 0, Xcam_shp), 0));
	card_t size898 = width_card_t(distorted_shp);
	array_number_t stgVar804 = storage_alloc(size898);
	array_number_t macroDef888;card_t size895 = width_card_t(TOP_LEVEL_linalg_mult_by_scalar_shp(TOP_LEVEL_linalg_vectorSlice_shp(2, 0, Xcam_shp), 0));
	array_number_t stgVar806 = storage_alloc(size895);
	array_number_t macroDef885;card_t size894 = width_card_t(TOP_LEVEL_linalg_vectorSlice_shp(2, 0, cam_shp));
	array_number_t stgVar805 = storage_alloc(size894);
	array_number_t macroDef884;card_t size893 = width_card_t(TOP_LEVEL_linalg_vectorSlice_shp(2, 0, Xcam_shp));
	array_number_t stgVar810 = storage_alloc(size893);
	array_number_t macroDef883;
	macroDef883 = TOP_LEVEL_linalg_mult_by_scalar_dps(stgVar806, TOP_LEVEL_linalg_vectorSlice_dps(stgVar810, 2, 0, Xcam_dps, 2, 0, Xcam_shp), (1) / (Xcam_dps->arr[2]), TOP_LEVEL_linalg_vectorSlice_shp(2, 0, Xcam_shp), 0);;
	storage_free(stgVar810, size893);
	macroDef884 = TOP_LEVEL_usecases_ba_radial_distort_dps(stgVar804, TOP_LEVEL_linalg_vectorSlice_dps(stgVar805, 2, RAD_IDX_dps, cam_dps, 2, 0, cam_shp), macroDef883, TOP_LEVEL_linalg_vectorSlice_shp(2, 0, cam_shp), TOP_LEVEL_linalg_mult_by_scalar_shp(TOP_LEVEL_linalg_vectorSlice_shp(2, 0, Xcam_shp), 0));;
	storage_free(stgVar805, size894);
	macroDef885 = macroDef884;;
	storage_free(stgVar806, size895);
	array_number_t distorted_dps = macroDef885;
	card_t size897 = width_card_t(TOP_LEVEL_linalg_mult_by_scalar_shp(distorted_shp, 0));
	array_number_t stgVar817 = storage_alloc(size897);
	array_number_t macroDef887;card_t size896 = width_card_t(TOP_LEVEL_linalg_vectorSlice_shp(2, 0, cam_shp));
	array_number_t stgVar816 = storage_alloc(size896);
	array_number_t macroDef886;
	macroDef886 = TOP_LEVEL_linalg_vectorAdd_dps(stgVar786, TOP_LEVEL_linalg_vectorSlice_dps(stgVar816, 2, X0_IDX_dps, cam_dps, 2, 0, cam_shp), TOP_LEVEL_linalg_mult_by_scalar_dps(stgVar817, distorted_dps, cam_dps->arr[FOCAL_IDX_dps], distorted_shp, 0), TOP_LEVEL_linalg_vectorSlice_shp(2, 0, cam_shp), TOP_LEVEL_linalg_mult_by_scalar_shp(distorted_shp, 0));;
	storage_free(stgVar816, size896);
	macroDef887 = macroDef886;;
	storage_free(stgVar817, size897);
	macroDef888 = macroDef887;;
	storage_free(stgVar804, size898);
	macroDef889 = macroDef888;;
	storage_free(stgVar793, size899);
	return macroDef889;
}

card_t TOP_LEVEL_usecases_ba_compute_reproj_err_shp(card_t cam_shp, card_t x_shp, card_t w_shp, card_t feat_shp) {
	
	return TOP_LEVEL_linalg_mult_by_scalar_shp(TOP_LEVEL_linalg_vectorSub_shp(TOP_LEVEL_usecases_ba_project_shp(cam_shp, x_shp), feat_shp), 0);
}


array_number_t TOP_LEVEL_usecases_ba_compute_reproj_err_dps(storage_t stgVar900, array_number_t cam_dps, array_number_t x_dps, number_t w_dps, array_number_t feat_dps, card_t cam_shp, card_t x_shp, card_t w_shp, card_t feat_shp) {
	card_t size910 = width_card_t(TOP_LEVEL_linalg_vectorSub_shp(TOP_LEVEL_usecases_ba_project_shp(cam_shp, x_shp), feat_shp));
	array_number_t stgVar901 = storage_alloc(size910);
	array_number_t macroDef908;card_t size909 = width_card_t(TOP_LEVEL_usecases_ba_project_shp(cam_shp, x_shp));
	array_number_t stgVar903 = storage_alloc(size909);
	array_number_t macroDef907;
	macroDef907 = TOP_LEVEL_linalg_vectorSub_dps(stgVar901, TOP_LEVEL_usecases_ba_project_dps(stgVar903, cam_dps, x_dps, cam_shp, x_shp), feat_dps, TOP_LEVEL_usecases_ba_project_shp(cam_shp, x_shp), feat_shp);;
	storage_free(stgVar903, size909);
	macroDef908 = TOP_LEVEL_linalg_mult_by_scalar_dps(stgVar900, macroDef907, w_dps, TOP_LEVEL_linalg_vectorSub_shp(TOP_LEVEL_usecases_ba_project_shp(cam_shp, x_shp), feat_shp), 0);;
	storage_free(stgVar901, size910);
	return macroDef908;
}

card_t TOP_LEVEL_usecases_ba_compute_zach_weight_error_shp(card_t w_shp) {
	
	return 0;
}


number_t TOP_LEVEL_usecases_ba_compute_zach_weight_error_dps(storage_t stgVar911, number_t w_dps, card_t w_shp) {
	
	return (1) - ((w_dps) * (w_dps));
}
typedef empty_env_t env_t_920;


value_t lambda920(env_t_920* env917, card_t w_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
card_t TOP_LEVEL_usecases_ba_w_err_shp(card_t w_shp) {
	env_t_920 env_t_920_value = make_empty_env(); closure_t closure919 = make_closure(lambda920, &env_t_920_value);
	return TOP_LEVEL_linalg_vectorMap_shp(closure919, w_shp);
}

typedef empty_env_t env_t_927;


value_t lambda927(env_t_927* env921, storage_t stgVar915, number_t w_dps0, card_t w_shp0) {
	
	value_t res;
	res.number_t_value = TOP_LEVEL_usecases_ba_compute_zach_weight_error_dps(stgVar915, w_dps0, 0);
	return res;
}
typedef empty_env_t env_t_928;


value_t lambda928(env_t_928* env924, card_t w_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
array_number_t TOP_LEVEL_usecases_ba_w_err_dps(storage_t stgVar912, array_number_t w_dps, card_t w_shp) {
	env_t_927 env_t_927_value = make_empty_env(); closure_t closure923 = make_closure(lambda927, &env_t_927_value);
	env_t_928 env_t_928_value = make_empty_env(); closure_t closure926 = make_closure(lambda928, &env_t_928_value);
	return TOP_LEVEL_linalg_vectorMap_dps(stgVar912, closure923, w_dps, closure926, w_shp);
}
typedef struct env_t_964 {
	matrix_shape_t x_shp;
	matrix_shape_t feat_shp;
	matrix_shape_t cams_shp;
} env_t_964;
env_t_964 make_env_t_964(matrix_shape_t x_shp,matrix_shape_t feat_shp,matrix_shape_t cams_shp) {
	env_t_964 env;
	env.x_shp = x_shp;
	env.feat_shp = feat_shp;
	env.cams_shp = cams_shp;
	return env;
}

value_t lambda964(env_t_964* env961, card_t i_shp) {
	matrix_shape_t x_shp960 = env961->x_shp;
	matrix_shape_t feat_shp959 = env961->feat_shp;
	matrix_shape_t cams_shp958 = env961->cams_shp;
	value_t res;
	res.card_t_value = TOP_LEVEL_usecases_ba_compute_reproj_err_shp(cams_shp958.elem, x_shp960.elem, 0, feat_shp959.elem);
	return res;
}
matrix_shape_t TOP_LEVEL_usecases_ba_reproj_err_shp(matrix_shape_t cams_shp, matrix_shape_t x_shp, card_t w_shp, matrix_shape_t obs_shp, matrix_shape_t feat_shp) {
	env_t_964 env_t_964_value = make_env_t_964(x_shp,feat_shp,cams_shp); closure_t closure963 = make_closure(lambda964, &env_t_964_value);
	return TOP_LEVEL_linalg_vectorMapToMatrix_shp(closure963, TOP_LEVEL_linalg_vectorRange_shp(0, (w_shp) - (1)));
}

typedef struct env_t_991 {
	matrix_shape_t x_shp;
	array_array_number_t x_dps;
	array_number_t w_dps;
	matrix_shape_t obs_shp;
	array_array_number_t obs_dps;
	matrix_shape_t feat_shp;
	array_array_number_t feat_dps;
	matrix_shape_t cams_shp;
	array_array_number_t cams_dps;
} env_t_991;
env_t_991 make_env_t_991(matrix_shape_t x_shp,array_array_number_t x_dps,array_number_t w_dps,matrix_shape_t obs_shp,array_array_number_t obs_dps,matrix_shape_t feat_shp,array_array_number_t feat_dps,matrix_shape_t cams_shp,array_array_number_t cams_dps) {
	env_t_991 env;
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

value_t lambda991(env_t_991* env981, storage_t stgVar939, number_t i_dps, card_t i_shp) {
	matrix_shape_t x_shp980 = env981->x_shp;
	array_array_number_t x_dps979 = env981->x_dps;
	array_number_t w_dps978 = env981->w_dps;
	matrix_shape_t obs_shp977 = env981->obs_shp;
	array_array_number_t obs_dps976 = env981->obs_dps;
	matrix_shape_t feat_shp975 = env981->feat_shp;
	array_array_number_t feat_dps974 = env981->feat_dps;
	matrix_shape_t cams_shp973 = env981->cams_shp;
	array_array_number_t cams_dps972 = env981->cams_dps;
	card_t size996 = width_card_t(feat_shp975.elem);
	array_number_t stgVar943 = storage_alloc(size996);
	array_number_t macroDef971;card_t size995 = width_card_t(x_shp980.elem);
	array_number_t stgVar941 = storage_alloc(size995);
	array_number_t macroDef970;card_t size994 = width_card_t(cams_shp973.elem);
	array_number_t stgVar940 = storage_alloc(size994);
	array_number_t macroDef969;card_t size992 = width_card_t(obs_shp977.elem);
	array_number_t stgVar945 = storage_alloc(size992);
	number_t macroDef967;
	macroDef967 = obs_dps976->arr[(int)(i_dps)]->arr[0];;
	storage_free(stgVar945, size992);
	card_t size993 = width_card_t(obs_shp977.elem);
	array_number_t stgVar948 = storage_alloc(size993);
	number_t macroDef968;
	macroDef968 = obs_dps976->arr[(int)(i_dps)]->arr[1];;
	storage_free(stgVar948, size993);
	macroDef969 = TOP_LEVEL_usecases_ba_compute_reproj_err_dps(stgVar939, cams_dps972->arr[(int)(macroDef967)], x_dps979->arr[(int)(macroDef968)], w_dps978->arr[(int)(i_dps)], feat_dps974->arr[(int)(i_dps)], cams_shp973.elem, x_shp980.elem, 0, feat_shp975.elem);;
	storage_free(stgVar940, size994);
	macroDef970 = macroDef969;;
	storage_free(stgVar941, size995);
	macroDef971 = macroDef970;;
	storage_free(stgVar943, size996);
	value_t res;
	res.array_number_t_value = macroDef971;
	return res;
}
typedef struct env_t_997 {
	matrix_shape_t x_shp;
	matrix_shape_t feat_shp;
	matrix_shape_t cams_shp;
} env_t_997;
env_t_997 make_env_t_997(matrix_shape_t x_shp,matrix_shape_t feat_shp,matrix_shape_t cams_shp) {
	env_t_997 env;
	env.x_shp = x_shp;
	env.feat_shp = feat_shp;
	env.cams_shp = cams_shp;
	return env;
}

value_t lambda997(env_t_997* env987, card_t i_shp) {
	matrix_shape_t x_shp986 = env987->x_shp;
	matrix_shape_t feat_shp985 = env987->feat_shp;
	matrix_shape_t cams_shp984 = env987->cams_shp;
	value_t res;
	res.card_t_value = TOP_LEVEL_usecases_ba_compute_reproj_err_shp(cams_shp984.elem, x_shp986.elem, 0, feat_shp985.elem);
	return res;
}
array_array_number_t TOP_LEVEL_usecases_ba_reproj_err_dps(storage_t stgVar929, array_array_number_t cams_dps, array_array_number_t x_dps, array_number_t w_dps, array_array_number_t obs_dps, array_array_number_t feat_dps, matrix_shape_t cams_shp, matrix_shape_t x_shp, card_t w_shp, matrix_shape_t obs_shp, matrix_shape_t feat_shp) {
	card_t n_shp = cams_shp.card;
	card_t macroDef965 = cams_dps->length;
	card_t n_dps = macroDef965;
	card_t p_shp = w_shp;
	card_t macroDef966 = w_dps->length;
	card_t p_dps = macroDef966;
	card_t range_shp = TOP_LEVEL_linalg_vectorRange_shp(0, (p_shp) - (1));
	card_t size998 = width_card_t(range_shp);
	array_number_t stgVar934 = storage_alloc(size998);
	array_array_number_t macroDef990;array_number_t range_dps = TOP_LEVEL_linalg_vectorRange_dps(stgVar934, 0, (p_dps) - (1), 0, (p_shp) - (1));
	env_t_991 env_t_991_value = make_env_t_991(x_shp,x_dps,w_dps,obs_shp,obs_dps,feat_shp,feat_dps,cams_shp,cams_dps); closure_t closure983 = make_closure(lambda991, &env_t_991_value);
	env_t_997 env_t_997_value = make_env_t_997(x_shp,feat_shp,cams_shp); closure_t closure989 = make_closure(lambda997, &env_t_997_value);
	macroDef990 = TOP_LEVEL_linalg_vectorMapToMatrix_dps(stgVar929, closure983, range_dps, closure989, range_shp);;
	storage_free(stgVar934, size998);
	return macroDef990;
}

card_t TOP_LEVEL_usecases_ba_run_ba_from_file_shp(card_t fn_shp, card_t n_shp, card_t m_shp, card_t p_shp) {
	
	return 0;
}

typedef struct env_t_1099 {
	card_t one_cam_shp;
} env_t_1099;
env_t_1099 make_env_t_1099(card_t one_cam_shp) {
	env_t_1099 env;
	env.one_cam_shp = one_cam_shp;
	return env;
}

value_t lambda1099(env_t_1099* env1048, card_t x_shp) {
	card_t one_cam_shp1047 = env1048->one_cam_shp;
	value_t res;
	res.card_t_value = one_cam_shp1047;
	return res;
}
typedef struct env_t_1100 {
	card_t one_x_shp;
} env_t_1100;
env_t_1100 make_env_t_1100(card_t one_x_shp) {
	env_t_1100 env;
	env.one_x_shp = one_x_shp;
	return env;
}

value_t lambda1100(env_t_1100* env1053, card_t x_shp) {
	card_t one_x_shp1052 = env1053->one_x_shp;
	value_t res;
	res.card_t_value = one_x_shp1052;
	return res;
}
typedef empty_env_t env_t_1101;


value_t lambda1101(env_t_1101* env1057, card_t x_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef struct env_t_1102 {
	number_t one_w_dps;
} env_t_1102;
env_t_1102 make_env_t_1102(number_t one_w_dps) {
	env_t_1102 env;
	env.one_w_dps = one_w_dps;
	return env;
}

value_t lambda1102(env_t_1102* env1061, storage_t stgVar1019, number_t x_dps0, card_t x_shp0) {
	number_t one_w_dps1060 = env1061->one_w_dps;
	value_t res;
	res.number_t_value = one_w_dps1060;
	return res;
}
typedef empty_env_t env_t_1103;


value_t lambda1103(env_t_1103* env1064, card_t x_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef struct env_t_1105 {
	card_t one_feat_shp;
} env_t_1105;
env_t_1105 make_env_t_1105(card_t one_feat_shp) {
	env_t_1105 env;
	env.one_feat_shp = one_feat_shp;
	return env;
}

value_t lambda1105(env_t_1105* env1069, card_t x_shp0) {
	card_t one_feat_shp1068 = env1069->one_feat_shp;
	value_t res;
	res.card_t_value = one_feat_shp1068;
	return res;
}
typedef struct env_t_1106 {
	array_number_t one_feat_dps;
} env_t_1106;
env_t_1106 make_env_t_1106(array_number_t one_feat_dps) {
	env_t_1106 env;
	env.one_feat_dps = one_feat_dps;
	return env;
}

value_t lambda1106(env_t_1106* env1073, storage_t stgVar1029, number_t x_dps0, card_t x_shp0) {
	array_number_t one_feat_dps1072 = env1073->one_feat_dps;
	value_t res;
	res.array_number_t_value = one_feat_dps1072;
	return res;
}
typedef struct env_t_1107 {
	card_t one_feat_shp;
} env_t_1107;
env_t_1107 make_env_t_1107(card_t one_feat_shp) {
	env_t_1107 env;
	env.one_feat_shp = one_feat_shp;
	return env;
}

value_t lambda1107(env_t_1107* env1077, card_t x_shp0) {
	card_t one_feat_shp1076 = env1077->one_feat_shp;
	value_t res;
	res.card_t_value = one_feat_shp1076;
	return res;
}
typedef empty_env_t env_t_1109;


value_t lambda1109(env_t_1109* env1081, card_t x_shp0) {
	
	value_t res;
	res.card_t_value = 2;
	return res;
}
void TOP_LEVEL_usecases_ba_run_ba_from_file_dps(storage_t stgVar999, string_t fn_dps, card_t n_dps, card_t m_dps, card_t p_dps, card_t fn_shp, card_t n_shp, card_t m_shp, card_t p_shp) {
	card_t oneCard_shp = 1;
	card_t oneCard_dps = 1;
	card_t one_cam_shp = TOP_LEVEL_linalg_vectorRead_shp(0, 0, 11);
	card_t size1119 = width_card_t(one_cam_shp);
	array_number_t stgVar1001 = storage_alloc(size1119);
	array_number_t one_cam_dps = TOP_LEVEL_linalg_vectorRead_dps(stgVar1001, fn_dps, 1, 11, 0, 0, 11);
	env_t_1099 env_t_1099_value = make_env_t_1099(one_cam_shp); closure_t closure1050 = make_closure(lambda1099, &env_t_1099_value);
	matrix_shape_t cam_shp = nested_shape_card_t(closure1050.lam(closure1050.env, 0).card_t_value, n_shp);
	card_t size1118 = width_matrix_shape_t(cam_shp);
	array_number_t stgVar1005 = storage_alloc(size1118);
	array_array_number_t macroDef1051 = (array_array_number_t)stgVar1005;
		macroDef1051->length=n_dps;
		macroDef1051->arr=(array_number_t*)(STG_OFFSET(macroDef1051, VECTOR_HEADER_BYTES));
		storage_t stgVar1006 = (STG_OFFSET(macroDef1051, MATRIX_HEADER_BYTES(n_dps)));
		for(int x_dps = 0; x_dps < macroDef1051->length; x_dps++){
			
			macroDef1051->arr[x_dps] = one_cam_dps;;
			stgVar1006 = STG_OFFSET(stgVar1006, VECTOR_ALL_BYTES(macroDef1051->arr[x_dps]->length));
		}
	array_array_number_t cam_dps = macroDef1051;
	card_t one_x_shp = TOP_LEVEL_linalg_vectorRead_shp(0, 0, 3);
	card_t size1117 = width_card_t(one_x_shp);
	array_number_t stgVar1007 = storage_alloc(size1117);
	array_number_t one_x_dps = TOP_LEVEL_linalg_vectorRead_dps(stgVar1007, fn_dps, 2, 3, 0, 0, 3);
	env_t_1100 env_t_1100_value = make_env_t_1100(one_x_shp); closure_t closure1055 = make_closure(lambda1100, &env_t_1100_value);
	matrix_shape_t x_shp = nested_shape_card_t(closure1055.lam(closure1055.env, 0).card_t_value, m_shp);
	card_t size1116 = width_matrix_shape_t(x_shp);
	array_number_t stgVar1011 = storage_alloc(size1116);
	array_array_number_t macroDef1056 = (array_array_number_t)stgVar1011;
		macroDef1056->length=m_dps;
		macroDef1056->arr=(array_number_t*)(STG_OFFSET(macroDef1056, VECTOR_HEADER_BYTES));
		storage_t stgVar1012 = (STG_OFFSET(macroDef1056, MATRIX_HEADER_BYTES(m_dps)));
		for(int x_dps = 0; x_dps < macroDef1056->length; x_dps++){
			
			macroDef1056->arr[x_dps] = one_x_dps;;
			stgVar1012 = STG_OFFSET(stgVar1012, VECTOR_ALL_BYTES(macroDef1056->arr[x_dps]->length));
		}
	array_array_number_t x_dps = macroDef1056;
	card_t one_w_shp = 0;
	number_t one_w_dps = TOP_LEVEL_linalg_numberRead_dps(empty_storage, fn_dps, 3, 0, 0);
	env_t_1101 env_t_1101_value = make_empty_env(); closure_t closure1059 = make_closure(lambda1101, &env_t_1101_value);
	card_t w_shp = TOP_LEVEL_linalg_vectorMap_shp(closure1059, TOP_LEVEL_linalg_vectorRange_shp(oneCard_shp, p_shp));
	card_t size1115 = width_card_t(w_shp);
	array_number_t stgVar1016 = storage_alloc(size1115);
	card_t size1104 = width_card_t(TOP_LEVEL_linalg_vectorRange_shp(oneCard_shp, p_shp));
	array_number_t stgVar1018 = storage_alloc(size1104);
	array_number_t macroDef1067;env_t_1102 env_t_1102_value = make_env_t_1102(one_w_dps); closure_t closure1063 = make_closure(lambda1102, &env_t_1102_value);
	env_t_1103 env_t_1103_value = make_empty_env(); closure_t closure1066 = make_closure(lambda1103, &env_t_1103_value);
	macroDef1067 = TOP_LEVEL_linalg_vectorMap_dps(stgVar1016, closure1063, TOP_LEVEL_linalg_vectorRange_dps(stgVar1018, oneCard_dps, p_dps, oneCard_shp, p_shp), closure1066, TOP_LEVEL_linalg_vectorRange_shp(oneCard_shp, p_shp));;
	storage_free(stgVar1018, size1104);
	array_number_t w_dps = macroDef1067;
	card_t one_feat_shp = TOP_LEVEL_linalg_vectorRead_shp(0, 0, 2);
	card_t size1114 = width_card_t(one_feat_shp);
	array_number_t stgVar1022 = storage_alloc(size1114);
	array_number_t one_feat_dps = TOP_LEVEL_linalg_vectorRead_dps(stgVar1022, fn_dps, 4, 2, 0, 0, 2);
	env_t_1105 env_t_1105_value = make_env_t_1105(one_feat_shp); closure_t closure1071 = make_closure(lambda1105, &env_t_1105_value);
	matrix_shape_t feat_shp = TOP_LEVEL_linalg_vectorMapToMatrix_shp(closure1071, TOP_LEVEL_linalg_vectorRange_shp(oneCard_shp, p_shp));
	card_t size1113 = width_matrix_shape_t(feat_shp);
	array_number_t stgVar1026 = storage_alloc(size1113);
	card_t size1108 = width_card_t(TOP_LEVEL_linalg_vectorRange_shp(oneCard_shp, p_shp));
	array_number_t stgVar1028 = storage_alloc(size1108);
	array_array_number_t macroDef1080;env_t_1106 env_t_1106_value = make_env_t_1106(one_feat_dps); closure_t closure1075 = make_closure(lambda1106, &env_t_1106_value);
	env_t_1107 env_t_1107_value = make_env_t_1107(one_feat_shp); closure_t closure1079 = make_closure(lambda1107, &env_t_1107_value);
	macroDef1080 = TOP_LEVEL_linalg_vectorMapToMatrix_dps(stgVar1026, closure1075, TOP_LEVEL_linalg_vectorRange_dps(stgVar1028, oneCard_dps, p_dps, oneCard_shp, p_shp), closure1079, TOP_LEVEL_linalg_vectorRange_shp(oneCard_shp, p_shp));;
	storage_free(stgVar1028, size1108);
	array_array_number_t feat_dps = macroDef1080;
	env_t_1109 env_t_1109_value = make_empty_env(); closure_t closure1083 = make_closure(lambda1109, &env_t_1109_value);
	matrix_shape_t obs_shp = nested_shape_card_t(closure1083.lam(closure1083.env, 0).card_t_value, p_shp);
	card_t size1112 = width_matrix_shape_t(obs_shp);
	array_number_t stgVar1032 = storage_alloc(size1112);
	array_array_number_t macroDef1085 = (array_array_number_t)stgVar1032;
		macroDef1085->length=p_dps;
		macroDef1085->arr=(array_number_t*)(STG_OFFSET(macroDef1085, VECTOR_HEADER_BYTES));
		storage_t stgVar1033 = (STG_OFFSET(macroDef1085, MATRIX_HEADER_BYTES(p_dps)));
		for(int x_dps0 = 0; x_dps0 < macroDef1085->length; x_dps0++){
			array_number_t macroDef1084 = (array_number_t)stgVar1033;
	macroDef1084->length=2;
	macroDef1084->arr=(number_t*)(STG_OFFSET(stgVar1033, VECTOR_HEADER_BYTES));
	

	macroDef1084->arr[0] = (double)(((int)(x_dps0)) % ((n_dps)));;

	macroDef1084->arr[1] = (double)(((int)(x_dps0)) % ((m_dps)));;;
			macroDef1085->arr[x_dps0] = macroDef1084;;
			stgVar1033 = STG_OFFSET(stgVar1033, VECTOR_ALL_BYTES(macroDef1085->arr[x_dps0]->length));
		}
	array_array_number_t obs_dps = macroDef1085;
	card_t t_shp = 0;
	timer_t t_dps = tic();
	card_t range_shp = TOP_LEVEL_linalg_vectorRange_shp(1, 10);
	card_t size1111 = width_card_t(range_shp);
	array_number_t stgVar1037 = storage_alloc(size1111);
	array_number_t range_dps = TOP_LEVEL_linalg_vectorRange_dps(stgVar1037, 1, 10, 1, 10);
	
	array_number_t cur_dps_range = range_dps;
	storage_t stgVar1040 = empty_storage;
	for(int cur_dps_idx = 0; cur_dps_idx < cur_dps_range->length; cur_dps_idx++){
		number_t cur_dps = cur_dps_range->arr[cur_dps_idx];
		matrix_shape_t x_shp0 = TOP_LEVEL_usecases_ba_reproj_err_shp(cam_shp, x_shp, w_shp, obs_shp, feat_shp);
		card_t size1110 = width_matrix_shape_t(x_shp0);
	array_number_t stgVar1041 = storage_alloc(size1110);
	array_array_number_t x_dps0 = TOP_LEVEL_usecases_ba_reproj_err_dps(stgVar1041, cam_dps, x_dps, w_dps, obs_dps, feat_dps, cam_shp, x_shp, w_shp, obs_shp, feat_shp);
	;
	storage_free(stgVar1041, size1110);
		;
	}
	;
	toc(t_dps, "BA");
	;
	storage_free(stgVar1037, size1111);
	;
	storage_free(stgVar1032, size1112);
	;
	storage_free(stgVar1026, size1113);
	;
	storage_free(stgVar1022, size1114);
	;
	storage_free(stgVar1016, size1115);
	;
	storage_free(stgVar1011, size1116);
	;
	storage_free(stgVar1007, size1117);
	;
	storage_free(stgVar1005, size1118);
	;
	storage_free(stgVar1001, size1119);
	return ;
}

card_t TOP_LEVEL_usecases_ba_test_ba_shp(card_t dum_shp) {
	
	return 0;
}


void TOP_LEVEL_usecases_ba_test_ba_dps(storage_t stgVar1120, array_number_t dum_dps, card_t dum_shp) {
	card_t a_shp = 3;
	card_t size1176 = width_card_t(a_shp);
	array_number_t stgVar1121 = storage_alloc(size1176);
	array_number_t macroDef1154 = (array_number_t)stgVar1121;
	macroDef1154->length=3;
	macroDef1154->arr=(number_t*)(STG_OFFSET(stgVar1121, VECTOR_HEADER_BYTES));
	

	macroDef1154->arr[0] = 1;;

	macroDef1154->arr[1] = 2;;

	macroDef1154->arr[2] = 3;;;
	array_number_t a_dps = macroDef1154;
	card_t b_shp = 3;
	card_t size1175 = width_card_t(b_shp);
	array_number_t stgVar1125 = storage_alloc(size1175);
	array_number_t macroDef1155 = (array_number_t)stgVar1125;
	macroDef1155->length=3;
	macroDef1155->arr=(number_t*)(STG_OFFSET(stgVar1125, VECTOR_HEADER_BYTES));
	

	macroDef1155->arr[0] = 5;;

	macroDef1155->arr[1] = 6;;

	macroDef1155->arr[2] = 7;;;
	array_number_t b_dps = macroDef1155;
	array_print(a_dps);
	array_print(b_dps);
	card_t j_shp = TOP_LEVEL_usecases_ba_radial_distort_shp(a_shp, b_shp);
	card_t size1174 = width_card_t(j_shp);
	array_number_t stgVar1129 = storage_alloc(size1174);
	array_number_t j_dps = TOP_LEVEL_usecases_ba_radial_distort_dps(stgVar1129, a_dps, b_dps, a_shp, b_shp);
	array_print(j_dps);
	card_t k_shp = TOP_LEVEL_usecases_ba_rodrigues_rotate_point_shp(a_shp, b_shp);
	card_t size1173 = width_card_t(k_shp);
	array_number_t stgVar1132 = storage_alloc(size1173);
	array_number_t k_dps = TOP_LEVEL_usecases_ba_rodrigues_rotate_point_dps(stgVar1132, a_dps, b_dps, a_shp, b_shp);
	array_print(k_dps);
	card_t l_shp = TOP_LEVEL_linalg_vectorSlice_shp(2, 0, k_shp);
	card_t size1172 = width_card_t(l_shp);
	array_number_t stgVar1135 = storage_alloc(size1172);
	array_number_t l_dps = TOP_LEVEL_linalg_vectorSlice_dps(stgVar1135, 2, 1, k_dps, 2, 0, k_shp);
	array_print(l_dps);
	card_t cam_shp = 11;
	card_t size1171 = width_card_t(cam_shp);
	array_number_t stgVar1139 = storage_alloc(size1171);
	array_number_t macroDef1156 = (array_number_t)stgVar1139;
	macroDef1156->length=11;
	macroDef1156->arr=(number_t*)(STG_OFFSET(stgVar1139, VECTOR_HEADER_BYTES));
	

	macroDef1156->arr[0] = 0;;

	macroDef1156->arr[1] = 2;;

	macroDef1156->arr[2] = 4;;

	macroDef1156->arr[3] = 6;;

	macroDef1156->arr[4] = 8;;

	macroDef1156->arr[5] = 10;;

	macroDef1156->arr[6] = 12;;

	macroDef1156->arr[7] = 14;;

	macroDef1156->arr[8] = 16;;

	macroDef1156->arr[9] = 18;;

	macroDef1156->arr[10] = 20;;;
	array_number_t cam_dps = macroDef1156;
	card_t m_shp = TOP_LEVEL_usecases_ba_project_shp(cam_shp, j_shp);
	card_t size1170 = width_card_t(m_shp);
	array_number_t stgVar1151 = storage_alloc(size1170);
	array_number_t m_dps = TOP_LEVEL_usecases_ba_project_dps(stgVar1151, cam_dps, j_dps, cam_shp, j_shp);
	array_print(m_dps);
	;
	storage_free(stgVar1151, size1170);
	;
	storage_free(stgVar1139, size1171);
	;
	storage_free(stgVar1135, size1172);
	;
	storage_free(stgVar1132, size1173);
	;
	storage_free(stgVar1129, size1174);
	;
	storage_free(stgVar1125, size1175);
	;
	storage_free(stgVar1121, size1176);
	return ;
}
#endif
