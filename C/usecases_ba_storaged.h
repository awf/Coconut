#ifndef __USECASES_BA_STORAGED_H__ 
#define __USECASES_BA_STORAGED_H__ 
#include "runtime/fsharp.h"
#include <stdio.h>
#include <math.h>
#include "linalg_storaged.h"

card_t TOP_LEVEL_usecases_ba_radial_distort_shp(card_t rad_params_shp, card_t proj_shp) {
	
	return TOP_LEVEL_linalg_mult_by_scalar_shp(proj_shp, 0);
}


array_number_t TOP_LEVEL_usecases_ba_radial_distort_dps(storage_t stgVar644, array_number_t rad_params_dps, array_number_t proj_dps, card_t rad_params_shp, card_t proj_shp) {
	card_t rsq_shp = 0;
	number_t rsq_dps = TOP_LEVEL_linalg_sqnorm_dps(empty_storage, proj_dps, proj_shp);
	card_t L_shp = 0;
	number_t L_dps = ((1) + ((rad_params_dps->arr[0]) * (rsq_dps))) + (((rad_params_dps->arr[1]) * (rsq_dps)) * (rsq_dps));
	return TOP_LEVEL_linalg_mult_by_scalar_dps(stgVar644, proj_dps, L_dps, proj_shp, 0);
}

card_t TOP_LEVEL_usecases_ba_rodrigues_rotate_point_shp(card_t rot_shp, card_t x_shp) {
	
	return TOP_LEVEL_linalg_vectorAdd_shp(TOP_LEVEL_linalg_vectorAdd_shp(TOP_LEVEL_linalg_mult_by_scalar_shp(x_shp, 0), TOP_LEVEL_linalg_mult_by_scalar_shp(TOP_LEVEL_linalg_cross_shp(TOP_LEVEL_linalg_mult_by_scalar_shp(rot_shp, 0), x_shp), 0)), TOP_LEVEL_linalg_mult_by_scalar_shp(TOP_LEVEL_linalg_mult_by_scalar_shp(rot_shp, 0), 0));
}


array_number_t TOP_LEVEL_usecases_ba_rodrigues_rotate_point_dps(storage_t stgVar654, array_number_t rot_dps, array_number_t x_dps, card_t rot_shp, card_t x_shp) {
	card_t sqtheta_shp = 0;
	number_t sqtheta_dps = TOP_LEVEL_linalg_sqnorm_dps(empty_storage, rot_dps, rot_shp);
	array_number_t ite783 = 0;
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
		card_t size789 = width_card_t(w_shp);
	array_number_t stgVar661 = storage_alloc(size789);
	array_number_t macroDef781;array_number_t w_dps = TOP_LEVEL_linalg_mult_by_scalar_dps(stgVar661, rot_dps, theta_inv_dps, rot_shp, 0);
	card_t w_cross_X_shp = TOP_LEVEL_linalg_cross_shp(w_shp, x_shp);
	card_t size788 = width_card_t(w_cross_X_shp);
	array_number_t stgVar664 = storage_alloc(size788);
	array_number_t macroDef780;array_number_t w_cross_X_dps = TOP_LEVEL_linalg_cross_dps(stgVar664, w_dps, x_dps, w_shp, x_shp);
	card_t tmp_shp = 0;
	number_t tmp_dps = (TOP_LEVEL_linalg_dot_prod_dps(empty_storage, w_dps, x_dps, w_shp, x_shp)) * ((1) - (costheta_dps));
	card_t v1_shp = TOP_LEVEL_linalg_mult_by_scalar_shp(x_shp, 0);
	card_t size787 = width_card_t(v1_shp);
	array_number_t stgVar670 = storage_alloc(size787);
	array_number_t macroDef779;array_number_t v1_dps = TOP_LEVEL_linalg_mult_by_scalar_dps(stgVar670, x_dps, costheta_dps, x_shp, 0);
	card_t v2_shp = TOP_LEVEL_linalg_mult_by_scalar_shp(w_cross_X_shp, 0);
	card_t size786 = width_card_t(v2_shp);
	array_number_t stgVar673 = storage_alloc(size786);
	array_number_t macroDef778;array_number_t v2_dps = TOP_LEVEL_linalg_mult_by_scalar_dps(stgVar673, w_cross_X_dps, sintheta_dps, w_cross_X_shp, 0);
	card_t size785 = width_card_t(TOP_LEVEL_linalg_mult_by_scalar_shp(w_shp, 0));
	array_number_t stgVar677 = storage_alloc(size785);
	array_number_t macroDef777;card_t size784 = width_card_t(TOP_LEVEL_linalg_vectorAdd_shp(v1_shp, v2_shp));
	array_number_t stgVar676 = storage_alloc(size784);
	array_number_t macroDef776;
	macroDef776 = TOP_LEVEL_linalg_vectorAdd_dps(stgVar654, TOP_LEVEL_linalg_vectorAdd_dps(stgVar676, v1_dps, v2_dps, v1_shp, v2_shp), TOP_LEVEL_linalg_mult_by_scalar_dps(stgVar677, w_dps, tmp_dps, w_shp, 0), TOP_LEVEL_linalg_vectorAdd_shp(v1_shp, v2_shp), TOP_LEVEL_linalg_mult_by_scalar_shp(w_shp, 0));;
	storage_free(stgVar676, size784);
	macroDef777 = macroDef776;;
	storage_free(stgVar677, size785);
	macroDef778 = macroDef777;;
	storage_free(stgVar673, size786);
	macroDef779 = macroDef778;;
	storage_free(stgVar670, size787);
	macroDef780 = macroDef779;;
	storage_free(stgVar664, size788);
	macroDef781 = macroDef780;;
	storage_free(stgVar661, size789);
		ite783 = macroDef781;;
	} else {
		card_t size790 = width_card_t(TOP_LEVEL_linalg_cross_shp(rot_shp, x_shp));
	array_number_t stgVar683 = storage_alloc(size790);
	array_number_t macroDef782;
	macroDef782 = TOP_LEVEL_linalg_vectorAdd_dps(stgVar654, x_dps, TOP_LEVEL_linalg_cross_dps(stgVar683, rot_dps, x_dps, rot_shp, x_shp), x_shp, TOP_LEVEL_linalg_cross_shp(rot_shp, x_shp));;
	storage_free(stgVar683, size790);
		ite783 = macroDef782;;
	}
	return ite783;
}

card_t TOP_LEVEL_usecases_ba_project_shp(card_t cam_shp, card_t x_shp) {
	
	return TOP_LEVEL_linalg_vectorAdd_shp(TOP_LEVEL_linalg_vectorSlice_shp(2, 0, cam_shp), TOP_LEVEL_linalg_mult_by_scalar_shp(TOP_LEVEL_usecases_ba_radial_distort_shp(TOP_LEVEL_linalg_vectorSlice_shp(2, 0, cam_shp), TOP_LEVEL_linalg_mult_by_scalar_shp(TOP_LEVEL_linalg_vectorSlice_shp(2, 0, TOP_LEVEL_usecases_ba_rodrigues_rotate_point_shp(TOP_LEVEL_linalg_vectorSlice_shp(3, 0, cam_shp), TOP_LEVEL_linalg_vectorSub_shp(x_shp, TOP_LEVEL_linalg_vectorSlice_shp(3, 0, cam_shp)))), 0)), 0));
}


array_number_t TOP_LEVEL_usecases_ba_project_dps(storage_t stgVar791, array_number_t cam_dps, array_number_t x_dps, card_t cam_shp, card_t x_shp) {
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
	card_t size904 = width_card_t(Xcam_shp);
	array_number_t stgVar798 = storage_alloc(size904);
	array_number_t macroDef894;card_t size897 = width_card_t(TOP_LEVEL_linalg_vectorSub_shp(x_shp, TOP_LEVEL_linalg_vectorSlice_shp(3, 0, cam_shp)));
	array_number_t stgVar800 = storage_alloc(size897);
	array_number_t macroDef887;card_t size896 = width_card_t(TOP_LEVEL_linalg_vectorSlice_shp(3, 0, cam_shp));
	array_number_t stgVar799 = storage_alloc(size896);
	array_number_t macroDef886;card_t size895 = width_card_t(TOP_LEVEL_linalg_vectorSlice_shp(3, 0, cam_shp));
	array_number_t stgVar805 = storage_alloc(size895);
	array_number_t macroDef885;
	macroDef885 = TOP_LEVEL_linalg_vectorSub_dps(stgVar800, x_dps, TOP_LEVEL_linalg_vectorSlice_dps(stgVar805, 3, CENTER_IDX_dps, cam_dps, 3, 0, cam_shp), x_shp, TOP_LEVEL_linalg_vectorSlice_shp(3, 0, cam_shp));;
	storage_free(stgVar805, size895);
	macroDef886 = TOP_LEVEL_usecases_ba_rodrigues_rotate_point_dps(stgVar798, TOP_LEVEL_linalg_vectorSlice_dps(stgVar799, 3, ROT_IDX_dps, cam_dps, 3, 0, cam_shp), macroDef885, TOP_LEVEL_linalg_vectorSlice_shp(3, 0, cam_shp), TOP_LEVEL_linalg_vectorSub_shp(x_shp, TOP_LEVEL_linalg_vectorSlice_shp(3, 0, cam_shp)));;
	storage_free(stgVar799, size896);
	macroDef887 = macroDef886;;
	storage_free(stgVar800, size897);
	array_number_t Xcam_dps = macroDef887;
	card_t distorted_shp = TOP_LEVEL_usecases_ba_radial_distort_shp(TOP_LEVEL_linalg_vectorSlice_shp(2, 0, cam_shp), TOP_LEVEL_linalg_mult_by_scalar_shp(TOP_LEVEL_linalg_vectorSlice_shp(2, 0, Xcam_shp), 0));
	card_t size903 = width_card_t(distorted_shp);
	array_number_t stgVar809 = storage_alloc(size903);
	array_number_t macroDef893;card_t size900 = width_card_t(TOP_LEVEL_linalg_mult_by_scalar_shp(TOP_LEVEL_linalg_vectorSlice_shp(2, 0, Xcam_shp), 0));
	array_number_t stgVar811 = storage_alloc(size900);
	array_number_t macroDef890;card_t size899 = width_card_t(TOP_LEVEL_linalg_vectorSlice_shp(2, 0, cam_shp));
	array_number_t stgVar810 = storage_alloc(size899);
	array_number_t macroDef889;card_t size898 = width_card_t(TOP_LEVEL_linalg_vectorSlice_shp(2, 0, Xcam_shp));
	array_number_t stgVar815 = storage_alloc(size898);
	array_number_t macroDef888;
	macroDef888 = TOP_LEVEL_linalg_mult_by_scalar_dps(stgVar811, TOP_LEVEL_linalg_vectorSlice_dps(stgVar815, 2, 0, Xcam_dps, 2, 0, Xcam_shp), (1) / (Xcam_dps->arr[2]), TOP_LEVEL_linalg_vectorSlice_shp(2, 0, Xcam_shp), 0);;
	storage_free(stgVar815, size898);
	macroDef889 = TOP_LEVEL_usecases_ba_radial_distort_dps(stgVar809, TOP_LEVEL_linalg_vectorSlice_dps(stgVar810, 2, RAD_IDX_dps, cam_dps, 2, 0, cam_shp), macroDef888, TOP_LEVEL_linalg_vectorSlice_shp(2, 0, cam_shp), TOP_LEVEL_linalg_mult_by_scalar_shp(TOP_LEVEL_linalg_vectorSlice_shp(2, 0, Xcam_shp), 0));;
	storage_free(stgVar810, size899);
	macroDef890 = macroDef889;;
	storage_free(stgVar811, size900);
	array_number_t distorted_dps = macroDef890;
	card_t size902 = width_card_t(TOP_LEVEL_linalg_mult_by_scalar_shp(distorted_shp, 0));
	array_number_t stgVar822 = storage_alloc(size902);
	array_number_t macroDef892;card_t size901 = width_card_t(TOP_LEVEL_linalg_vectorSlice_shp(2, 0, cam_shp));
	array_number_t stgVar821 = storage_alloc(size901);
	array_number_t macroDef891;
	macroDef891 = TOP_LEVEL_linalg_vectorAdd_dps(stgVar791, TOP_LEVEL_linalg_vectorSlice_dps(stgVar821, 2, X0_IDX_dps, cam_dps, 2, 0, cam_shp), TOP_LEVEL_linalg_mult_by_scalar_dps(stgVar822, distorted_dps, cam_dps->arr[FOCAL_IDX_dps], distorted_shp, 0), TOP_LEVEL_linalg_vectorSlice_shp(2, 0, cam_shp), TOP_LEVEL_linalg_mult_by_scalar_shp(distorted_shp, 0));;
	storage_free(stgVar821, size901);
	macroDef892 = macroDef891;;
	storage_free(stgVar822, size902);
	macroDef893 = macroDef892;;
	storage_free(stgVar809, size903);
	macroDef894 = macroDef893;;
	storage_free(stgVar798, size904);
	return macroDef894;
}

card_t TOP_LEVEL_usecases_ba_compute_reproj_err_shp(card_t cam_shp, card_t x_shp, card_t w_shp, card_t feat_shp) {
	
	return TOP_LEVEL_linalg_mult_by_scalar_shp(TOP_LEVEL_linalg_vectorSub_shp(TOP_LEVEL_usecases_ba_project_shp(cam_shp, x_shp), feat_shp), 0);
}


array_number_t TOP_LEVEL_usecases_ba_compute_reproj_err_dps(storage_t stgVar905, array_number_t cam_dps, array_number_t x_dps, number_t w_dps, array_number_t feat_dps, card_t cam_shp, card_t x_shp, card_t w_shp, card_t feat_shp) {
	card_t size915 = width_card_t(TOP_LEVEL_linalg_vectorSub_shp(TOP_LEVEL_usecases_ba_project_shp(cam_shp, x_shp), feat_shp));
	array_number_t stgVar906 = storage_alloc(size915);
	array_number_t macroDef913;card_t size914 = width_card_t(TOP_LEVEL_usecases_ba_project_shp(cam_shp, x_shp));
	array_number_t stgVar908 = storage_alloc(size914);
	array_number_t macroDef912;
	macroDef912 = TOP_LEVEL_linalg_vectorSub_dps(stgVar906, TOP_LEVEL_usecases_ba_project_dps(stgVar908, cam_dps, x_dps, cam_shp, x_shp), feat_dps, TOP_LEVEL_usecases_ba_project_shp(cam_shp, x_shp), feat_shp);;
	storage_free(stgVar908, size914);
	macroDef913 = TOP_LEVEL_linalg_mult_by_scalar_dps(stgVar905, macroDef912, w_dps, TOP_LEVEL_linalg_vectorSub_shp(TOP_LEVEL_usecases_ba_project_shp(cam_shp, x_shp), feat_shp), 0);;
	storage_free(stgVar906, size915);
	return macroDef913;
}

card_t TOP_LEVEL_usecases_ba_compute_zach_weight_error_shp(card_t w_shp) {
	
	return 0;
}


number_t TOP_LEVEL_usecases_ba_compute_zach_weight_error_dps(storage_t stgVar916, number_t w_dps, card_t w_shp) {
	
	return (1) - ((w_dps) * (w_dps));
}
typedef empty_env_t env_t_925;


value_t lambda925(env_t_925* env922, card_t w_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
card_t TOP_LEVEL_usecases_ba_w_err_shp(card_t w_shp) {
	env_t_925 env_t_925_value = make_empty_env(); closure_t closure924 = make_closure(lambda925, &env_t_925_value);
	return TOP_LEVEL_linalg_vectorMap_shp(closure924, w_shp);
}

typedef empty_env_t env_t_932;


value_t lambda932(env_t_932* env926, storage_t stgVar920, number_t w_dps0, card_t w_shp0) {
	
	value_t res;
	res.number_t_value = TOP_LEVEL_usecases_ba_compute_zach_weight_error_dps(stgVar920, w_dps0, 0);
	return res;
}
typedef empty_env_t env_t_933;


value_t lambda933(env_t_933* env929, card_t w_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
array_number_t TOP_LEVEL_usecases_ba_w_err_dps(storage_t stgVar917, array_number_t w_dps, card_t w_shp) {
	env_t_932 env_t_932_value = make_empty_env(); closure_t closure928 = make_closure(lambda932, &env_t_932_value);
	env_t_933 env_t_933_value = make_empty_env(); closure_t closure931 = make_closure(lambda933, &env_t_933_value);
	return TOP_LEVEL_linalg_vectorMap_dps(stgVar917, closure928, w_dps, closure931, w_shp);
}
typedef struct env_t_969 {
	matrix_shape_t x_shp;
	matrix_shape_t feat_shp;
	matrix_shape_t cams_shp;
} env_t_969;
env_t_969 make_env_t_969(matrix_shape_t x_shp,matrix_shape_t feat_shp,matrix_shape_t cams_shp) {
	env_t_969 env;
	env.x_shp = x_shp;
	env.feat_shp = feat_shp;
	env.cams_shp = cams_shp;
	return env;
}

value_t lambda969(env_t_969* env966, card_t i_shp) {
	matrix_shape_t x_shp965 = env966->x_shp;
	matrix_shape_t feat_shp964 = env966->feat_shp;
	matrix_shape_t cams_shp963 = env966->cams_shp;
	value_t res;
	res.card_t_value = TOP_LEVEL_usecases_ba_compute_reproj_err_shp(cams_shp963.elem, x_shp965.elem, 0, feat_shp964.elem);
	return res;
}
matrix_shape_t TOP_LEVEL_usecases_ba_reproj_err_shp(matrix_shape_t cams_shp, matrix_shape_t x_shp, card_t w_shp, matrix_shape_t obs_shp, matrix_shape_t feat_shp) {
	env_t_969 env_t_969_value = make_env_t_969(x_shp,feat_shp,cams_shp); closure_t closure968 = make_closure(lambda969, &env_t_969_value);
	return TOP_LEVEL_linalg_vectorMapToMatrix_shp(closure968, TOP_LEVEL_linalg_vectorRange_shp(0, (w_shp) - (1)));
}

typedef struct env_t_996 {
	matrix_shape_t x_shp;
	array_array_number_t x_dps;
	array_number_t w_dps;
	matrix_shape_t obs_shp;
	array_array_number_t obs_dps;
	matrix_shape_t feat_shp;
	array_array_number_t feat_dps;
	matrix_shape_t cams_shp;
	array_array_number_t cams_dps;
} env_t_996;
env_t_996 make_env_t_996(matrix_shape_t x_shp,array_array_number_t x_dps,array_number_t w_dps,matrix_shape_t obs_shp,array_array_number_t obs_dps,matrix_shape_t feat_shp,array_array_number_t feat_dps,matrix_shape_t cams_shp,array_array_number_t cams_dps) {
	env_t_996 env;
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

value_t lambda996(env_t_996* env986, storage_t stgVar944, number_t i_dps, card_t i_shp) {
	matrix_shape_t x_shp985 = env986->x_shp;
	array_array_number_t x_dps984 = env986->x_dps;
	array_number_t w_dps983 = env986->w_dps;
	matrix_shape_t obs_shp982 = env986->obs_shp;
	array_array_number_t obs_dps981 = env986->obs_dps;
	matrix_shape_t feat_shp980 = env986->feat_shp;
	array_array_number_t feat_dps979 = env986->feat_dps;
	matrix_shape_t cams_shp978 = env986->cams_shp;
	array_array_number_t cams_dps977 = env986->cams_dps;
	card_t size1001 = width_card_t(feat_shp980.elem);
	array_number_t stgVar948 = storage_alloc(size1001);
	array_number_t macroDef976;card_t size1000 = width_card_t(x_shp985.elem);
	array_number_t stgVar946 = storage_alloc(size1000);
	array_number_t macroDef975;card_t size999 = width_card_t(cams_shp978.elem);
	array_number_t stgVar945 = storage_alloc(size999);
	array_number_t macroDef974;card_t size997 = width_card_t(obs_shp982.elem);
	array_number_t stgVar950 = storage_alloc(size997);
	number_t macroDef972;
	macroDef972 = obs_dps981->arr[(int)(i_dps)]->arr[0];;
	storage_free(stgVar950, size997);
	card_t size998 = width_card_t(obs_shp982.elem);
	array_number_t stgVar953 = storage_alloc(size998);
	number_t macroDef973;
	macroDef973 = obs_dps981->arr[(int)(i_dps)]->arr[1];;
	storage_free(stgVar953, size998);
	macroDef974 = TOP_LEVEL_usecases_ba_compute_reproj_err_dps(stgVar944, cams_dps977->arr[(int)(macroDef972)], x_dps984->arr[(int)(macroDef973)], w_dps983->arr[(int)(i_dps)], feat_dps979->arr[(int)(i_dps)], cams_shp978.elem, x_shp985.elem, 0, feat_shp980.elem);;
	storage_free(stgVar945, size999);
	macroDef975 = macroDef974;;
	storage_free(stgVar946, size1000);
	macroDef976 = macroDef975;;
	storage_free(stgVar948, size1001);
	value_t res;
	res.array_number_t_value = macroDef976;
	return res;
}
typedef struct env_t_1002 {
	matrix_shape_t x_shp;
	matrix_shape_t feat_shp;
	matrix_shape_t cams_shp;
} env_t_1002;
env_t_1002 make_env_t_1002(matrix_shape_t x_shp,matrix_shape_t feat_shp,matrix_shape_t cams_shp) {
	env_t_1002 env;
	env.x_shp = x_shp;
	env.feat_shp = feat_shp;
	env.cams_shp = cams_shp;
	return env;
}

value_t lambda1002(env_t_1002* env992, card_t i_shp) {
	matrix_shape_t x_shp991 = env992->x_shp;
	matrix_shape_t feat_shp990 = env992->feat_shp;
	matrix_shape_t cams_shp989 = env992->cams_shp;
	value_t res;
	res.card_t_value = TOP_LEVEL_usecases_ba_compute_reproj_err_shp(cams_shp989.elem, x_shp991.elem, 0, feat_shp990.elem);
	return res;
}
array_array_number_t TOP_LEVEL_usecases_ba_reproj_err_dps(storage_t stgVar934, array_array_number_t cams_dps, array_array_number_t x_dps, array_number_t w_dps, array_array_number_t obs_dps, array_array_number_t feat_dps, matrix_shape_t cams_shp, matrix_shape_t x_shp, card_t w_shp, matrix_shape_t obs_shp, matrix_shape_t feat_shp) {
	card_t n_shp = cams_shp.card;
	card_t macroDef970 = cams_dps->length;
	card_t n_dps = macroDef970;
	card_t p_shp = w_shp;
	card_t macroDef971 = w_dps->length;
	card_t p_dps = macroDef971;
	card_t range_shp = TOP_LEVEL_linalg_vectorRange_shp(0, (p_shp) - (1));
	card_t size1003 = width_card_t(range_shp);
	array_number_t stgVar939 = storage_alloc(size1003);
	array_array_number_t macroDef995;array_number_t range_dps = TOP_LEVEL_linalg_vectorRange_dps(stgVar939, 0, (p_dps) - (1), 0, (p_shp) - (1));
	env_t_996 env_t_996_value = make_env_t_996(x_shp,x_dps,w_dps,obs_shp,obs_dps,feat_shp,feat_dps,cams_shp,cams_dps); closure_t closure988 = make_closure(lambda996, &env_t_996_value);
	env_t_1002 env_t_1002_value = make_env_t_1002(x_shp,feat_shp,cams_shp); closure_t closure994 = make_closure(lambda1002, &env_t_1002_value);
	macroDef995 = TOP_LEVEL_linalg_vectorMapToMatrix_dps(stgVar934, closure988, range_dps, closure994, range_shp);;
	storage_free(stgVar939, size1003);
	return macroDef995;
}

card_t TOP_LEVEL_usecases_ba_run_ba_from_file_shp(card_t fn_shp, card_t n_shp, card_t m_shp, card_t p_shp) {
	
	return 0;
}

typedef struct env_t_1104 {
	card_t one_cam_shp;
} env_t_1104;
env_t_1104 make_env_t_1104(card_t one_cam_shp) {
	env_t_1104 env;
	env.one_cam_shp = one_cam_shp;
	return env;
}

value_t lambda1104(env_t_1104* env1053, card_t x_shp) {
	card_t one_cam_shp1052 = env1053->one_cam_shp;
	value_t res;
	res.card_t_value = one_cam_shp1052;
	return res;
}
typedef struct env_t_1105 {
	card_t one_x_shp;
} env_t_1105;
env_t_1105 make_env_t_1105(card_t one_x_shp) {
	env_t_1105 env;
	env.one_x_shp = one_x_shp;
	return env;
}

value_t lambda1105(env_t_1105* env1058, card_t x_shp) {
	card_t one_x_shp1057 = env1058->one_x_shp;
	value_t res;
	res.card_t_value = one_x_shp1057;
	return res;
}
typedef empty_env_t env_t_1106;


value_t lambda1106(env_t_1106* env1062, card_t x_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef struct env_t_1107 {
	number_t one_w_dps;
} env_t_1107;
env_t_1107 make_env_t_1107(number_t one_w_dps) {
	env_t_1107 env;
	env.one_w_dps = one_w_dps;
	return env;
}

value_t lambda1107(env_t_1107* env1066, storage_t stgVar1024, number_t x_dps0, card_t x_shp0) {
	number_t one_w_dps1065 = env1066->one_w_dps;
	value_t res;
	res.number_t_value = one_w_dps1065;
	return res;
}
typedef empty_env_t env_t_1108;


value_t lambda1108(env_t_1108* env1069, card_t x_shp0) {
	
	value_t res;
	res.card_t_value = 0;
	return res;
}
typedef struct env_t_1110 {
	card_t one_feat_shp;
} env_t_1110;
env_t_1110 make_env_t_1110(card_t one_feat_shp) {
	env_t_1110 env;
	env.one_feat_shp = one_feat_shp;
	return env;
}

value_t lambda1110(env_t_1110* env1074, card_t x_shp0) {
	card_t one_feat_shp1073 = env1074->one_feat_shp;
	value_t res;
	res.card_t_value = one_feat_shp1073;
	return res;
}
typedef struct env_t_1111 {
	array_number_t one_feat_dps;
} env_t_1111;
env_t_1111 make_env_t_1111(array_number_t one_feat_dps) {
	env_t_1111 env;
	env.one_feat_dps = one_feat_dps;
	return env;
}

value_t lambda1111(env_t_1111* env1078, storage_t stgVar1034, number_t x_dps0, card_t x_shp0) {
	array_number_t one_feat_dps1077 = env1078->one_feat_dps;
	value_t res;
	res.array_number_t_value = one_feat_dps1077;
	return res;
}
typedef struct env_t_1112 {
	card_t one_feat_shp;
} env_t_1112;
env_t_1112 make_env_t_1112(card_t one_feat_shp) {
	env_t_1112 env;
	env.one_feat_shp = one_feat_shp;
	return env;
}

value_t lambda1112(env_t_1112* env1082, card_t x_shp0) {
	card_t one_feat_shp1081 = env1082->one_feat_shp;
	value_t res;
	res.card_t_value = one_feat_shp1081;
	return res;
}
typedef empty_env_t env_t_1114;


value_t lambda1114(env_t_1114* env1086, card_t x_shp0) {
	
	value_t res;
	res.card_t_value = 2;
	return res;
}
void TOP_LEVEL_usecases_ba_run_ba_from_file_dps(storage_t stgVar1004, string_t fn_dps, card_t n_dps, card_t m_dps, card_t p_dps, card_t fn_shp, card_t n_shp, card_t m_shp, card_t p_shp) {
	card_t oneCard_shp = 1;
	card_t oneCard_dps = 1;
	card_t one_cam_shp = TOP_LEVEL_linalg_vectorRead_shp(0, 0, 11);
	card_t size1124 = width_card_t(one_cam_shp);
	array_number_t stgVar1006 = storage_alloc(size1124);
	array_number_t one_cam_dps = TOP_LEVEL_linalg_vectorRead_dps(stgVar1006, fn_dps, 1, 11, 0, 0, 11);
	env_t_1104 env_t_1104_value = make_env_t_1104(one_cam_shp); closure_t closure1055 = make_closure(lambda1104, &env_t_1104_value);
	matrix_shape_t cam_shp = nested_shape_card_t(closure1055.lam(closure1055.env, 0).card_t_value, n_shp);
	card_t size1123 = width_matrix_shape_t(cam_shp);
	array_number_t stgVar1010 = storage_alloc(size1123);
	array_array_number_t macroDef1056 = (array_array_number_t)stgVar1010;
		macroDef1056->length=n_dps;
		macroDef1056->arr=(array_number_t*)(STG_OFFSET(macroDef1056, VECTOR_HEADER_BYTES));
		storage_t stgVar1011 = (STG_OFFSET(macroDef1056, MATRIX_HEADER_BYTES(n_dps)));
		for(int x_dps = 0; x_dps < macroDef1056->length; x_dps++){
			
			macroDef1056->arr[x_dps] = one_cam_dps;;
			stgVar1011 = STG_OFFSET(stgVar1011, VECTOR_ALL_BYTES(macroDef1056->arr[x_dps]->length));
		}
	array_array_number_t cam_dps = macroDef1056;
	card_t one_x_shp = TOP_LEVEL_linalg_vectorRead_shp(0, 0, 3);
	card_t size1122 = width_card_t(one_x_shp);
	array_number_t stgVar1012 = storage_alloc(size1122);
	array_number_t one_x_dps = TOP_LEVEL_linalg_vectorRead_dps(stgVar1012, fn_dps, 2, 3, 0, 0, 3);
	env_t_1105 env_t_1105_value = make_env_t_1105(one_x_shp); closure_t closure1060 = make_closure(lambda1105, &env_t_1105_value);
	matrix_shape_t x_shp = nested_shape_card_t(closure1060.lam(closure1060.env, 0).card_t_value, m_shp);
	card_t size1121 = width_matrix_shape_t(x_shp);
	array_number_t stgVar1016 = storage_alloc(size1121);
	array_array_number_t macroDef1061 = (array_array_number_t)stgVar1016;
		macroDef1061->length=m_dps;
		macroDef1061->arr=(array_number_t*)(STG_OFFSET(macroDef1061, VECTOR_HEADER_BYTES));
		storage_t stgVar1017 = (STG_OFFSET(macroDef1061, MATRIX_HEADER_BYTES(m_dps)));
		for(int x_dps = 0; x_dps < macroDef1061->length; x_dps++){
			
			macroDef1061->arr[x_dps] = one_x_dps;;
			stgVar1017 = STG_OFFSET(stgVar1017, VECTOR_ALL_BYTES(macroDef1061->arr[x_dps]->length));
		}
	array_array_number_t x_dps = macroDef1061;
	card_t one_w_shp = 0;
	number_t one_w_dps = TOP_LEVEL_linalg_numberRead_dps(empty_storage, fn_dps, 3, 0, 0);
	env_t_1106 env_t_1106_value = make_empty_env(); closure_t closure1064 = make_closure(lambda1106, &env_t_1106_value);
	card_t w_shp = TOP_LEVEL_linalg_vectorMap_shp(closure1064, TOP_LEVEL_linalg_vectorRange_shp(oneCard_shp, p_shp));
	card_t size1120 = width_card_t(w_shp);
	array_number_t stgVar1021 = storage_alloc(size1120);
	card_t size1109 = width_card_t(TOP_LEVEL_linalg_vectorRange_shp(oneCard_shp, p_shp));
	array_number_t stgVar1023 = storage_alloc(size1109);
	array_number_t macroDef1072;env_t_1107 env_t_1107_value = make_env_t_1107(one_w_dps); closure_t closure1068 = make_closure(lambda1107, &env_t_1107_value);
	env_t_1108 env_t_1108_value = make_empty_env(); closure_t closure1071 = make_closure(lambda1108, &env_t_1108_value);
	macroDef1072 = TOP_LEVEL_linalg_vectorMap_dps(stgVar1021, closure1068, TOP_LEVEL_linalg_vectorRange_dps(stgVar1023, oneCard_dps, p_dps, oneCard_shp, p_shp), closure1071, TOP_LEVEL_linalg_vectorRange_shp(oneCard_shp, p_shp));;
	storage_free(stgVar1023, size1109);
	array_number_t w_dps = macroDef1072;
	card_t one_feat_shp = TOP_LEVEL_linalg_vectorRead_shp(0, 0, 2);
	card_t size1119 = width_card_t(one_feat_shp);
	array_number_t stgVar1027 = storage_alloc(size1119);
	array_number_t one_feat_dps = TOP_LEVEL_linalg_vectorRead_dps(stgVar1027, fn_dps, 4, 2, 0, 0, 2);
	env_t_1110 env_t_1110_value = make_env_t_1110(one_feat_shp); closure_t closure1076 = make_closure(lambda1110, &env_t_1110_value);
	matrix_shape_t feat_shp = TOP_LEVEL_linalg_vectorMapToMatrix_shp(closure1076, TOP_LEVEL_linalg_vectorRange_shp(oneCard_shp, p_shp));
	card_t size1118 = width_matrix_shape_t(feat_shp);
	array_number_t stgVar1031 = storage_alloc(size1118);
	card_t size1113 = width_card_t(TOP_LEVEL_linalg_vectorRange_shp(oneCard_shp, p_shp));
	array_number_t stgVar1033 = storage_alloc(size1113);
	array_array_number_t macroDef1085;env_t_1111 env_t_1111_value = make_env_t_1111(one_feat_dps); closure_t closure1080 = make_closure(lambda1111, &env_t_1111_value);
	env_t_1112 env_t_1112_value = make_env_t_1112(one_feat_shp); closure_t closure1084 = make_closure(lambda1112, &env_t_1112_value);
	macroDef1085 = TOP_LEVEL_linalg_vectorMapToMatrix_dps(stgVar1031, closure1080, TOP_LEVEL_linalg_vectorRange_dps(stgVar1033, oneCard_dps, p_dps, oneCard_shp, p_shp), closure1084, TOP_LEVEL_linalg_vectorRange_shp(oneCard_shp, p_shp));;
	storage_free(stgVar1033, size1113);
	array_array_number_t feat_dps = macroDef1085;
	env_t_1114 env_t_1114_value = make_empty_env(); closure_t closure1088 = make_closure(lambda1114, &env_t_1114_value);
	matrix_shape_t obs_shp = nested_shape_card_t(closure1088.lam(closure1088.env, 0).card_t_value, p_shp);
	card_t size1117 = width_matrix_shape_t(obs_shp);
	array_number_t stgVar1037 = storage_alloc(size1117);
	array_array_number_t macroDef1090 = (array_array_number_t)stgVar1037;
		macroDef1090->length=p_dps;
		macroDef1090->arr=(array_number_t*)(STG_OFFSET(macroDef1090, VECTOR_HEADER_BYTES));
		storage_t stgVar1038 = (STG_OFFSET(macroDef1090, MATRIX_HEADER_BYTES(p_dps)));
		for(int x_dps0 = 0; x_dps0 < macroDef1090->length; x_dps0++){
			array_number_t macroDef1089 = (array_number_t)stgVar1038;
	macroDef1089->length=2;
	macroDef1089->arr=(number_t*)(STG_OFFSET(stgVar1038, VECTOR_HEADER_BYTES));
	macroDef1089->arr[0] = (double)(((int)(x_dps0)) % ((n_dps)));
	macroDef1089->arr[1] = (double)(((int)(x_dps0)) % ((m_dps)));;
			macroDef1090->arr[x_dps0] = macroDef1089;;
			stgVar1038 = STG_OFFSET(stgVar1038, VECTOR_ALL_BYTES(macroDef1090->arr[x_dps0]->length));
		}
	array_array_number_t obs_dps = macroDef1090;
	card_t t_shp = 0;
	timer_t t_dps = tic();
	card_t range_shp = TOP_LEVEL_linalg_vectorRange_shp(1, 10);
	card_t size1116 = width_card_t(range_shp);
	array_number_t stgVar1042 = storage_alloc(size1116);
	array_number_t range_dps = TOP_LEVEL_linalg_vectorRange_dps(stgVar1042, 1, 10, 1, 10);
	
	array_number_t cur_dps_range = range_dps;
	storage_t stgVar1045 = empty_storage;
	for(int cur_dps_idx = 0; cur_dps_idx < cur_dps_range->length; cur_dps_idx++){
		number_t cur_dps = cur_dps_range->arr[cur_dps_idx];
		matrix_shape_t x_shp0 = TOP_LEVEL_usecases_ba_reproj_err_shp(cam_shp, x_shp, w_shp, obs_shp, feat_shp);
		card_t size1115 = width_matrix_shape_t(x_shp0);
	array_number_t stgVar1046 = storage_alloc(size1115);
	array_array_number_t x_dps0 = TOP_LEVEL_usecases_ba_reproj_err_dps(stgVar1046, cam_dps, x_dps, w_dps, obs_dps, feat_dps, cam_shp, x_shp, w_shp, obs_shp, feat_shp);
	;
	storage_free(stgVar1046, size1115);
		;
	}
	;
	toc(t_dps, "BA");
	;
	storage_free(stgVar1042, size1116);
	;
	storage_free(stgVar1037, size1117);
	;
	storage_free(stgVar1031, size1118);
	;
	storage_free(stgVar1027, size1119);
	;
	storage_free(stgVar1021, size1120);
	;
	storage_free(stgVar1016, size1121);
	;
	storage_free(stgVar1012, size1122);
	;
	storage_free(stgVar1010, size1123);
	;
	storage_free(stgVar1006, size1124);
	return ;
}

card_t TOP_LEVEL_usecases_ba_test_ba_shp(card_t dum_shp) {
	
	return 0;
}


void TOP_LEVEL_usecases_ba_test_ba_dps(storage_t stgVar1125, array_number_t dum_dps, card_t dum_shp) {
	card_t a_shp = 3;
	card_t size1181 = width_card_t(a_shp);
	array_number_t stgVar1126 = storage_alloc(size1181);
	array_number_t macroDef1159 = (array_number_t)stgVar1126;
	macroDef1159->length=3;
	macroDef1159->arr=(number_t*)(STG_OFFSET(stgVar1126, VECTOR_HEADER_BYTES));
	macroDef1159->arr[0] = 1;
	macroDef1159->arr[1] = 2;
	macroDef1159->arr[2] = 3;;
	array_number_t a_dps = macroDef1159;
	card_t b_shp = 3;
	card_t size1180 = width_card_t(b_shp);
	array_number_t stgVar1130 = storage_alloc(size1180);
	array_number_t macroDef1160 = (array_number_t)stgVar1130;
	macroDef1160->length=3;
	macroDef1160->arr=(number_t*)(STG_OFFSET(stgVar1130, VECTOR_HEADER_BYTES));
	macroDef1160->arr[0] = 5;
	macroDef1160->arr[1] = 6;
	macroDef1160->arr[2] = 7;;
	array_number_t b_dps = macroDef1160;
	array_print(a_dps);
	array_print(b_dps);
	card_t j_shp = TOP_LEVEL_usecases_ba_radial_distort_shp(a_shp, b_shp);
	card_t size1179 = width_card_t(j_shp);
	array_number_t stgVar1134 = storage_alloc(size1179);
	array_number_t j_dps = TOP_LEVEL_usecases_ba_radial_distort_dps(stgVar1134, a_dps, b_dps, a_shp, b_shp);
	array_print(j_dps);
	card_t k_shp = TOP_LEVEL_usecases_ba_rodrigues_rotate_point_shp(a_shp, b_shp);
	card_t size1178 = width_card_t(k_shp);
	array_number_t stgVar1137 = storage_alloc(size1178);
	array_number_t k_dps = TOP_LEVEL_usecases_ba_rodrigues_rotate_point_dps(stgVar1137, a_dps, b_dps, a_shp, b_shp);
	array_print(k_dps);
	card_t l_shp = TOP_LEVEL_linalg_vectorSlice_shp(2, 0, k_shp);
	card_t size1177 = width_card_t(l_shp);
	array_number_t stgVar1140 = storage_alloc(size1177);
	array_number_t l_dps = TOP_LEVEL_linalg_vectorSlice_dps(stgVar1140, 2, 1, k_dps, 2, 0, k_shp);
	array_print(l_dps);
	card_t cam_shp = 11;
	card_t size1176 = width_card_t(cam_shp);
	array_number_t stgVar1144 = storage_alloc(size1176);
	array_number_t macroDef1161 = (array_number_t)stgVar1144;
	macroDef1161->length=11;
	macroDef1161->arr=(number_t*)(STG_OFFSET(stgVar1144, VECTOR_HEADER_BYTES));
	macroDef1161->arr[0] = 0;
	macroDef1161->arr[1] = 2;
	macroDef1161->arr[2] = 4;
	macroDef1161->arr[3] = 6;
	macroDef1161->arr[4] = 8;
	macroDef1161->arr[5] = 10;
	macroDef1161->arr[6] = 12;
	macroDef1161->arr[7] = 14;
	macroDef1161->arr[8] = 16;
	macroDef1161->arr[9] = 18;
	macroDef1161->arr[10] = 20;;
	array_number_t cam_dps = macroDef1161;
	card_t m_shp = TOP_LEVEL_usecases_ba_project_shp(cam_shp, j_shp);
	card_t size1175 = width_card_t(m_shp);
	array_number_t stgVar1156 = storage_alloc(size1175);
	array_number_t m_dps = TOP_LEVEL_usecases_ba_project_dps(stgVar1156, cam_dps, j_dps, cam_shp, j_shp);
	array_print(m_dps);
	;
	storage_free(stgVar1156, size1175);
	;
	storage_free(stgVar1144, size1176);
	;
	storage_free(stgVar1140, size1177);
	;
	storage_free(stgVar1137, size1178);
	;
	storage_free(stgVar1134, size1179);
	;
	storage_free(stgVar1130, size1180);
	;
	storage_free(stgVar1126, size1181);
	return ;
}
#endif
