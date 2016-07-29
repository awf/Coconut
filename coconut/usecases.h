#ifndef __USECASES_H__ 
#define __USECASES_H__ 
#include "runtime/fsharp.h"
#include <stdio.h>
#include <math.h>
#include "linalg.h"

array_number_t usecases_radial_distort(array_number_t rad_params, array_number_t proj) {
	number_t rsq = linalg_sqnorm(proj);
	number_t L = ((1) + ((rad_params->arr[0]) * (rsq))) + (((rad_params->arr[1]) * (rsq)) * (rsq));
	return linalg_mult_by_scalar(proj, L);
}

array_number_t usecases_rodrigues_rotate_point(array_number_t rot, array_number_t x) {
	number_t sqtheta = linalg_sqnorm(rot);
	array_number_t ite114 = 0;
	if((sqtheta) != (0)) {
		number_t theta = sqrt(sqtheta);
		number_t costheta = cos(theta);
		number_t sintheta = sin(theta);
		number_t theta_inv = (1) / (theta);
		array_number_t w = linalg_mult_by_scalar(rot, theta_inv);
		array_number_t w_cross_X = linalg_cross(w, x);
		number_t tmp = (linalg_dot_prod(w, x)) * ((1) - (costheta));
		array_number_t v1 = linalg_mult_by_scalar(x, costheta);
		array_number_t v2 = linalg_mult_by_scalar(w_cross_X, sintheta);
		ite114 = linalg_add_vec(linalg_add_vec(v1, v2), linalg_mult_by_scalar(w, tmp));
	} else {
		
		ite114 = linalg_add_vec(x, linalg_cross(rot, x));
	}
	return ite114;
}

array_number_t usecases_project(array_number_t cam, array_number_t x) {
	index_t N_CAM_PARAMS = 11;
	index_t ROT_IDX = 0;
	index_t CENTER_IDX = 3;
	index_t FOCAL_IDX = 6;
	index_t X0_IDX = 7;
	index_t RAD_IDX = 9;
	array_number_t Xcam = usecases_rodrigues_rotate_point(array_slice(cam, ROT_IDX, (ROT_IDX) + (2)), linalg_sub_vec(x, array_slice(cam, CENTER_IDX, (CENTER_IDX) + (2))));
	array_number_t distorted = usecases_radial_distort(array_slice(cam, RAD_IDX, (RAD_IDX) + (1)), linalg_mult_by_scalar(array_slice(Xcam, 0, 1), (1) / (Xcam->arr[2])));
	return linalg_add_vec(array_slice(cam, X0_IDX, (X0_IDX) + (1)), linalg_mult_by_scalar(distorted, cam->arr[FOCAL_IDX]));
}

array_number_t usecases_compute_reproj_err(array_number_t cam, array_number_t x, number_t w, array_number_t feat) {
	
	return linalg_mult_by_scalar(linalg_sub_vec(usecases_project(cam, x), feat), w);
}

number_t usecases_compute_zach_weight_error(number_t w) {
	
	return (1) - ((w) * (w));
}
typedef struct env_t_118 {
	value_t dummy_variable;
} env_t_118;
env_t_118* make_env_t_118() {
	env_t_118* env = (env_t_118*)malloc(sizeof(env_t_118));
	
	return env;
}

value_t lambda118(env_t_118* env115, number_t w) {
	
	value_t res;
	res.number_t_value = usecases_compute_zach_weight_error(w);
	return res;
}
array_number_t usecases_w_err(array_number_t w) {
	closure_t* closure117 = make_closure(lambda118, make_env_t_118());
	return linalg_vectorMap(closure117, w);
}
typedef struct env_t_127 {
	array_array_number_t x;
	array_number_t w;
	array_array_number_t obs;
	array_array_number_t feat;
	array_array_number_t cams;
} env_t_127;
env_t_127* make_env_t_127(array_array_number_t x,array_number_t w,array_array_number_t obs,array_array_number_t feat,array_array_number_t cams) {
	env_t_127* env = (env_t_127*)malloc(sizeof(env_t_127));
	env->x = x;
	env->w = w;
	env->obs = obs;
	env->feat = feat;
	env->cams = cams;
	return env;
}

value_t lambda127(env_t_127* env124, number_t i) {
	array_array_number_t x123 = env124->x;
	array_number_t w122 = env124->w;
	array_array_number_t obs121 = env124->obs;
	array_array_number_t feat120 = env124->feat;
	array_array_number_t cams119 = env124->cams;
	value_t res;
	res.array_number_t_value = usecases_compute_reproj_err(cams119->arr[(int)(obs121->arr[(int)(i)]->arr[0])], x123->arr[(int)(obs121->arr[(int)(i)]->arr[1])], w122->arr[(int)(i)], feat120->arr[(int)(i)]);
	return res;
}
array_array_number_t usecases_reproj_err(array_array_number_t cams, array_array_number_t x, array_number_t w, array_array_number_t obs, array_array_number_t feat) {
	index_t n = cams->length;
	index_t p = w->length;
	array_number_t range = linalg_vectorRange(0, (p) - (1));
	closure_t* closure126 = make_closure(lambda127, make_env_t_127(x,w,obs,feat,cams));
	return linalg_vectorMapToMatrix(closure126, range);
}
typedef struct env_t_151 {
	array_number_t one_cam;
} env_t_151;
env_t_151* make_env_t_151(array_number_t one_cam) {
	env_t_151* env = (env_t_151*)malloc(sizeof(env_t_151));
	env->one_cam = one_cam;
	return env;
}

value_t lambda151(env_t_151* env129, number_t x) {
	array_number_t one_cam128 = env129->one_cam;
	value_t res;
	res.array_number_t_value = one_cam128;
	return res;
}
typedef struct env_t_152 {
	array_number_t one_x;
} env_t_152;
env_t_152* make_env_t_152(array_number_t one_x) {
	env_t_152* env = (env_t_152*)malloc(sizeof(env_t_152));
	env->one_x = one_x;
	return env;
}

value_t lambda152(env_t_152* env133, number_t x) {
	array_number_t one_x132 = env133->one_x;
	value_t res;
	res.array_number_t_value = one_x132;
	return res;
}
typedef struct env_t_153 {
	number_t one_w;
} env_t_153;
env_t_153* make_env_t_153(number_t one_w) {
	env_t_153* env = (env_t_153*)malloc(sizeof(env_t_153));
	env->one_w = one_w;
	return env;
}

value_t lambda153(env_t_153* env137, number_t x) {
	number_t one_w136 = env137->one_w;
	value_t res;
	res.number_t_value = one_w136;
	return res;
}
typedef struct env_t_154 {
	array_number_t one_feat;
} env_t_154;
env_t_154* make_env_t_154(array_number_t one_feat) {
	env_t_154* env = (env_t_154*)malloc(sizeof(env_t_154));
	env->one_feat = one_feat;
	return env;
}

value_t lambda154(env_t_154* env141, number_t x) {
	array_number_t one_feat140 = env141->one_feat;
	value_t res;
	res.array_number_t_value = one_feat140;
	return res;
}
typedef struct env_t_155 {
	index_t n;
	index_t m;
} env_t_155;
env_t_155* make_env_t_155(index_t n,index_t m) {
	env_t_155* env = (env_t_155*)malloc(sizeof(env_t_155));
	env->n = n;
	env->m = m;
	return env;
}

value_t lambda155(env_t_155* env146, number_t x) {
	index_t n145 = env146->n;
	index_t m144 = env146->m;
	array_number_t array149 = (array_number_t)malloc(sizeof(int) * 2);
	array149->length=2;
	array149->arr = (number_t*)malloc(sizeof(number_t) * 2);
	array149->arr[0] = (double)(((int)(x)) % (n145));
	array149->arr[1] = (double)(((int)(x)) % (m144));;
	value_t res;
	res.array_number_t_value = array149;
	return res;
}
array_array_number_t usecases_run_ba_from_file(string_t fn) {
	array_number_t nmp = linalg_vectorRead(fn, 0);
	index_t n = (int)(nmp->arr[0]);
	index_t m = (int)(nmp->arr[1]);
	index_t p = (int)(nmp->arr[2]);
	array_number_t one_cam = linalg_vectorRead(fn, 1);
	closure_t* closure131 = make_closure(lambda151, make_env_t_151(one_cam));
	array_array_number_t cam = linalg_vectorMapToMatrix(closure131, linalg_vectorRange(1, n));
	array_number_t one_x = linalg_vectorRead(fn, 2);
	closure_t* closure135 = make_closure(lambda152, make_env_t_152(one_x));
	array_array_number_t x = linalg_vectorMapToMatrix(closure135, linalg_vectorRange(1, m));
	number_t one_w = linalg_numberRead(fn, 3);
	closure_t* closure139 = make_closure(lambda153, make_env_t_153(one_w));
	array_number_t w = linalg_vectorMap(closure139, linalg_vectorRange(1, p));
	array_number_t one_feat = linalg_vectorRead(fn, 4);
	closure_t* closure143 = make_closure(lambda154, make_env_t_154(one_feat));
	array_array_number_t feat = linalg_vectorMapToMatrix(closure143, linalg_vectorRange(1, p));
	closure_t* closure148 = make_closure(lambda155, make_env_t_155(n,m));
	array_array_number_t obs = linalg_vectorMapToMatrix(closure148, linalg_vectorRange(0, (p) - (1)));
	timer_t t = tic();
	array_array_number_t res = usecases_reproj_err(cam, x, w, obs, feat);
	toc(t);
	return res;
}
typedef struct env_t_160 {
	number_t mx;
} env_t_160;
env_t_160* make_env_t_160(number_t mx) {
	env_t_160* env = (env_t_160*)malloc(sizeof(env_t_160));
	env->mx = mx;
	return env;
}

value_t lambda160(env_t_160* env157, number_t x) {
	number_t mx156 = env157->mx;
	value_t res;
	res.number_t_value = exp((x) - (mx156));
	return res;
}
number_t usecases_logsumexp(array_number_t arr) {
	number_t mx = linalg_arrayMax(arr);
	closure_t* closure159 = make_closure(lambda160, make_env_t_160(mx));
	number_t semx = linalg_arraySum(linalg_vectorMap(closure159, arr));
	return (log(semx)) + (mx);
}
typedef struct env_t_165 {
	number_t a;
} env_t_165;
env_t_165* make_env_t_165(number_t a) {
	env_t_165* env = (env_t_165*)malloc(sizeof(env_t_165));
	env->a = a;
	return env;
}

value_t lambda165(env_t_165* env162, number_t j) {
	number_t a161 = env162->a;
	value_t res;
	res.number_t_value = gamma_ln((a161) + ((0.5) * ((1) - ((double)(j)))));
	return res;
}
number_t usecases_log_gamma_distrib(number_t a, number_t p) {
	closure_t* closure164 = make_closure(lambda165, make_env_t_165(a));
	return (log(pow(3.14159265358979, (0.25) * ((p) * ((p) - (1)))))) + (linalg_arraySum(linalg_vectorMap(closure164, linalg_vectorRange(1, (int)(p)))));
}

array_array_number_t usecases_new_matrix_test(array_number_t dum) {
	array_number_t array166 = (array_number_t)malloc(sizeof(int) * 2);
	array166->length=3;
	array166->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array166->arr[0] = 0;
	array166->arr[1] = 0;
	array166->arr[2] = 0;;
	array_array_number_t res = (array_array_number_t)malloc(sizeof(int) * 2);
	res->length=1;
	res->arr = (array_number_t*)malloc(sizeof(array_number_t) * 1);
	res->arr[0] = array166;;
	return res;
}

array_array_number_t usecases_to_pose_params(array_number_t theta, index_t n_bones) {
	array_number_t row1 = array_slice(theta, 0, 2);
	array_number_t row2 = (array_number_t)malloc(sizeof(int) * 2);
	row2->length=3;
	row2->arr = (number_t*)malloc(sizeof(number_t) * 3);
	row2->arr[0] = 1;
	row2->arr[1] = 1;
	row2->arr[2] = 1;;
	array_number_t row3 = array_slice(theta, 3, 5);
	array_number_t zeroRow = (array_number_t)malloc(sizeof(int) * 2);
	zeroRow->length=3;
	zeroRow->arr = (number_t*)malloc(sizeof(number_t) * 3);
	zeroRow->arr[0] = 0;
	zeroRow->arr[1] = 0;
	zeroRow->arr[2] = 0;;
	array_array_number_t pose_params = (array_array_number_t)malloc(sizeof(int) * 2);
	pose_params->length=5;
	pose_params->arr = (array_number_t*)malloc(sizeof(array_number_t) * 5);
	pose_params->arr[0] = row1;
	pose_params->arr[1] = row2;
	pose_params->arr[2] = row3;
	pose_params->arr[3] = zeroRow;
	pose_params->arr[4] = zeroRow;;
	index_t i1 = 5;
	array_number_t array167 = (array_number_t)malloc(sizeof(int) * 2);
	array167->length=3;
	array167->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array167->arr[0] = theta->arr[i1];
	array167->arr[1] = theta->arr[(i1) + (1)];
	array167->arr[2] = 0;;
	array_number_t array168 = (array_number_t)malloc(sizeof(int) * 2);
	array168->length=3;
	array168->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array168->arr[0] = theta->arr[(i1) + (2)];
	array168->arr[1] = 0;
	array168->arr[2] = 0;;
	array_number_t array169 = (array_number_t)malloc(sizeof(int) * 2);
	array169->length=3;
	array169->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array169->arr[0] = theta->arr[(i1) + (3)];
	array169->arr[1] = 0;
	array169->arr[2] = 0;;
	array_number_t array170 = (array_number_t)malloc(sizeof(int) * 2);
	array170->length=3;
	array170->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array170->arr[0] = 0;
	array170->arr[1] = 0;
	array170->arr[2] = 0;;
	array_array_number_t finger1 = (array_array_number_t)malloc(sizeof(int) * 2);
	finger1->length=4;
	finger1->arr = (array_number_t*)malloc(sizeof(array_number_t) * 4);
	finger1->arr[0] = array167;
	finger1->arr[1] = array168;
	finger1->arr[2] = array169;
	finger1->arr[3] = array170;;
	index_t i2 = (i1) + (4);
	array_number_t array171 = (array_number_t)malloc(sizeof(int) * 2);
	array171->length=3;
	array171->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array171->arr[0] = theta->arr[i2];
	array171->arr[1] = theta->arr[(i2) + (1)];
	array171->arr[2] = 0;;
	array_number_t array172 = (array_number_t)malloc(sizeof(int) * 2);
	array172->length=3;
	array172->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array172->arr[0] = theta->arr[(i2) + (2)];
	array172->arr[1] = 0;
	array172->arr[2] = 0;;
	array_number_t array173 = (array_number_t)malloc(sizeof(int) * 2);
	array173->length=3;
	array173->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array173->arr[0] = theta->arr[(i2) + (3)];
	array173->arr[1] = 0;
	array173->arr[2] = 0;;
	array_number_t array174 = (array_number_t)malloc(sizeof(int) * 2);
	array174->length=3;
	array174->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array174->arr[0] = 0;
	array174->arr[1] = 0;
	array174->arr[2] = 0;;
	array_array_number_t finger2 = (array_array_number_t)malloc(sizeof(int) * 2);
	finger2->length=4;
	finger2->arr = (array_number_t*)malloc(sizeof(array_number_t) * 4);
	finger2->arr[0] = array171;
	finger2->arr[1] = array172;
	finger2->arr[2] = array173;
	finger2->arr[3] = array174;;
	index_t i3 = (i2) + (4);
	array_number_t array175 = (array_number_t)malloc(sizeof(int) * 2);
	array175->length=3;
	array175->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array175->arr[0] = theta->arr[i3];
	array175->arr[1] = theta->arr[(i3) + (1)];
	array175->arr[2] = 0;;
	array_number_t array176 = (array_number_t)malloc(sizeof(int) * 2);
	array176->length=3;
	array176->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array176->arr[0] = theta->arr[(i3) + (2)];
	array176->arr[1] = 0;
	array176->arr[2] = 0;;
	array_number_t array177 = (array_number_t)malloc(sizeof(int) * 2);
	array177->length=3;
	array177->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array177->arr[0] = theta->arr[(i3) + (3)];
	array177->arr[1] = 0;
	array177->arr[2] = 0;;
	array_number_t array178 = (array_number_t)malloc(sizeof(int) * 2);
	array178->length=3;
	array178->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array178->arr[0] = 0;
	array178->arr[1] = 0;
	array178->arr[2] = 0;;
	array_array_number_t finger3 = (array_array_number_t)malloc(sizeof(int) * 2);
	finger3->length=4;
	finger3->arr = (array_number_t*)malloc(sizeof(array_number_t) * 4);
	finger3->arr[0] = array175;
	finger3->arr[1] = array176;
	finger3->arr[2] = array177;
	finger3->arr[3] = array178;;
	index_t i4 = (i3) + (4);
	array_number_t array179 = (array_number_t)malloc(sizeof(int) * 2);
	array179->length=3;
	array179->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array179->arr[0] = theta->arr[i4];
	array179->arr[1] = theta->arr[(i4) + (1)];
	array179->arr[2] = 0;;
	array_number_t array180 = (array_number_t)malloc(sizeof(int) * 2);
	array180->length=3;
	array180->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array180->arr[0] = theta->arr[(i4) + (2)];
	array180->arr[1] = 0;
	array180->arr[2] = 0;;
	array_number_t array181 = (array_number_t)malloc(sizeof(int) * 2);
	array181->length=3;
	array181->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array181->arr[0] = theta->arr[(i4) + (3)];
	array181->arr[1] = 0;
	array181->arr[2] = 0;;
	array_number_t array182 = (array_number_t)malloc(sizeof(int) * 2);
	array182->length=3;
	array182->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array182->arr[0] = 0;
	array182->arr[1] = 0;
	array182->arr[2] = 0;;
	array_array_number_t finger4 = (array_array_number_t)malloc(sizeof(int) * 2);
	finger4->length=4;
	finger4->arr = (array_number_t*)malloc(sizeof(array_number_t) * 4);
	finger4->arr[0] = array179;
	finger4->arr[1] = array180;
	finger4->arr[2] = array181;
	finger4->arr[3] = array182;;
	index_t i5 = (i4) + (4);
	array_number_t array183 = (array_number_t)malloc(sizeof(int) * 2);
	array183->length=3;
	array183->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array183->arr[0] = theta->arr[i5];
	array183->arr[1] = theta->arr[(i5) + (1)];
	array183->arr[2] = 0;;
	array_number_t array184 = (array_number_t)malloc(sizeof(int) * 2);
	array184->length=3;
	array184->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array184->arr[0] = theta->arr[(i5) + (2)];
	array184->arr[1] = 0;
	array184->arr[2] = 0;;
	array_number_t array185 = (array_number_t)malloc(sizeof(int) * 2);
	array185->length=3;
	array185->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array185->arr[0] = theta->arr[(i5) + (3)];
	array185->arr[1] = 0;
	array185->arr[2] = 0;;
	array_number_t array186 = (array_number_t)malloc(sizeof(int) * 2);
	array186->length=3;
	array186->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array186->arr[0] = 0;
	array186->arr[1] = 0;
	array186->arr[2] = 0;;
	array_array_number_t finger5 = (array_array_number_t)malloc(sizeof(int) * 2);
	finger5->length=4;
	finger5->arr = (array_number_t*)malloc(sizeof(array_number_t) * 4);
	finger5->arr[0] = array183;
	finger5->arr[1] = array184;
	finger5->arr[2] = array185;
	finger5->arr[3] = array186;;
	return matrix_concat(pose_params, matrix_concat(finger1, matrix_concat(finger2, matrix_concat(finger3, matrix_concat(finger4, finger5)))));
}

array_array_number_t usecases_euler_angles_to_rotation_matrix(array_number_t xzy) {
	number_t tx = xzy->arr[0];
	number_t ty = xzy->arr[2];
	number_t tz = xzy->arr[1];
	array_number_t array187 = (array_number_t)malloc(sizeof(int) * 2);
	array187->length=3;
	array187->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array187->arr[0] = 1;
	array187->arr[1] = 0;
	array187->arr[2] = 0;;
	array_number_t array188 = (array_number_t)malloc(sizeof(int) * 2);
	array188->length=3;
	array188->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array188->arr[0] = 0;
	array188->arr[1] = cos(tx);
	array188->arr[2] = -(sin(tx));;
	array_number_t array189 = (array_number_t)malloc(sizeof(int) * 2);
	array189->length=3;
	array189->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array189->arr[0] = 0;
	array189->arr[1] = sin(tx);
	array189->arr[2] = cos(tx);;
	array_array_number_t Rx = (array_array_number_t)malloc(sizeof(int) * 2);
	Rx->length=3;
	Rx->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	Rx->arr[0] = array187;
	Rx->arr[1] = array188;
	Rx->arr[2] = array189;;
	array_number_t array190 = (array_number_t)malloc(sizeof(int) * 2);
	array190->length=3;
	array190->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array190->arr[0] = cos(ty);
	array190->arr[1] = 0;
	array190->arr[2] = sin(ty);;
	array_number_t array191 = (array_number_t)malloc(sizeof(int) * 2);
	array191->length=3;
	array191->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array191->arr[0] = 0;
	array191->arr[1] = 1;
	array191->arr[2] = 0;;
	array_number_t array192 = (array_number_t)malloc(sizeof(int) * 2);
	array192->length=3;
	array192->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array192->arr[0] = -(sin(ty));
	array192->arr[1] = 0;
	array192->arr[2] = cos(ty);;
	array_array_number_t Ry = (array_array_number_t)malloc(sizeof(int) * 2);
	Ry->length=3;
	Ry->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	Ry->arr[0] = array190;
	Ry->arr[1] = array191;
	Ry->arr[2] = array192;;
	array_number_t array193 = (array_number_t)malloc(sizeof(int) * 2);
	array193->length=3;
	array193->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array193->arr[0] = cos(tz);
	array193->arr[1] = -(sin(tz));
	array193->arr[2] = 0;;
	array_number_t array194 = (array_number_t)malloc(sizeof(int) * 2);
	array194->length=3;
	array194->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array194->arr[0] = sin(tz);
	array194->arr[1] = cos(tz);
	array194->arr[2] = 0;;
	array_number_t array195 = (array_number_t)malloc(sizeof(int) * 2);
	array195->length=3;
	array195->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array195->arr[0] = 0;
	array195->arr[1] = 0;
	array195->arr[2] = 1;;
	array_array_number_t Rz = (array_array_number_t)malloc(sizeof(int) * 2);
	Rz->length=3;
	Rz->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	Rz->arr[0] = array193;
	Rz->arr[1] = array194;
	Rz->arr[2] = array195;;
	return matrix_mult(Rz, matrix_mult(Ry, Rx));
}

array_array_number_t usecases_make_relative(array_number_t pose_params, array_array_number_t base_relative) {
	array_array_number_t R = usecases_euler_angles_to_rotation_matrix(pose_params);
	array_number_t array196 = (array_number_t)malloc(sizeof(int) * 2);
	array196->length=1;
	array196->arr = (number_t*)malloc(sizeof(number_t) * 1);
	array196->arr[0] = 0;;
	array_number_t array197 = (array_number_t)malloc(sizeof(int) * 2);
	array197->length=1;
	array197->arr = (number_t*)malloc(sizeof(number_t) * 1);
	array197->arr[0] = 0;;
	array_number_t array198 = (array_number_t)malloc(sizeof(int) * 2);
	array198->length=1;
	array198->arr = (number_t*)malloc(sizeof(number_t) * 1);
	array198->arr[0] = 0;;
	array_array_number_t r1 = (array_array_number_t)malloc(sizeof(int) * 2);
	r1->length=3;
	r1->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	r1->arr[0] = array196;
	r1->arr[1] = array197;
	r1->arr[2] = array198;;
	array_number_t array199 = (array_number_t)malloc(sizeof(int) * 2);
	array199->length=4;
	array199->arr = (number_t*)malloc(sizeof(number_t) * 4);
	array199->arr[0] = 0;
	array199->arr[1] = 0;
	array199->arr[2] = 0;
	array199->arr[3] = 1;;
	array_array_number_t r2 = (array_array_number_t)malloc(sizeof(int) * 2);
	r2->length=1;
	r2->arr = (array_number_t*)malloc(sizeof(array_number_t) * 1);
	r2->arr[0] = array199;;
	array_array_number_t T = matrix_concat(linalg_matrixConcatCol(R, r1), r2);
	return matrix_mult(base_relative, T);
}
typedef struct env_t_206 {
	array_array_number_t pose_params;
	index_t offset;
	array_array_array_number_t base_relatives;
} env_t_206;
env_t_206* make_env_t_206(array_array_number_t pose_params,index_t offset,array_array_array_number_t base_relatives) {
	env_t_206* env = (env_t_206*)malloc(sizeof(env_t_206));
	env->pose_params = pose_params;
	env->offset = offset;
	env->base_relatives = base_relatives;
	return env;
}

value_t lambda206(env_t_206* env203, number_t i_bone) {
	array_array_number_t pose_params202 = env203->pose_params;
	index_t offset201 = env203->offset;
	array_array_array_number_t base_relatives200 = env203->base_relatives;
	value_t res;
	res.array_array_number_t_value = usecases_make_relative(pose_params202->arr[((int)(i_bone)) + (offset201)], base_relatives200->arr[(int)(i_bone)]);
	return res;
}
array_array_array_number_t usecases_get_posed_relatives(index_t n_bones, array_array_number_t pose_params, array_array_array_number_t base_relatives) {
	index_t offset = 3;
	closure_t* closure205 = make_closure(lambda206, make_env_t_206(pose_params,offset,base_relatives));
	return linalg_vectorMapToMatrix3D(closure205, linalg_vectorRange(0, (n_bones) - (1)));
}

array_array_number_t usecases_angle_axis_to_rotation_matrix(array_number_t angle_axis) {
	number_t n = sqrt(linalg_sqnorm(angle_axis));
	array_array_number_t ite207 = 0;
	if((n) < (0.0001)) {
		array_number_t array209 = (array_number_t)malloc(sizeof(int) * 2);
	array209->length=3;
	array209->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array209->arr[0] = 1;
	array209->arr[1] = 0;
	array209->arr[2] = 0;;
		array_number_t array210 = (array_number_t)malloc(sizeof(int) * 2);
	array210->length=3;
	array210->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array210->arr[0] = 0;
	array210->arr[1] = 1;
	array210->arr[2] = 0;;
		array_number_t array211 = (array_number_t)malloc(sizeof(int) * 2);
	array211->length=3;
	array211->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array211->arr[0] = 0;
	array211->arr[1] = 0;
	array211->arr[2] = 1;;
		array_array_number_t array208 = (array_array_number_t)malloc(sizeof(int) * 2);
	array208->length=3;
	array208->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	array208->arr[0] = array209;
	array208->arr[1] = array210;
	array208->arr[2] = array211;;
		ite207 = array208;
	} else {
		number_t x = (angle_axis->arr[0]) / (n);
		number_t y = (angle_axis->arr[1]) / (n);
		number_t z = (angle_axis->arr[2]) / (n);
		number_t s = sin(n);
		number_t c = cos(n);
		array_number_t array213 = (array_number_t)malloc(sizeof(int) * 2);
	array213->length=3;
	array213->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array213->arr[0] = ((x) * (x)) + (((1) - ((x) * (x))) * (c));
	array213->arr[1] = (((x) * (y)) * ((1) - (c))) - ((z) * (s));
	array213->arr[2] = (((x) * (z)) * ((1) - (c))) + ((y) * (s));;
		array_number_t array214 = (array_number_t)malloc(sizeof(int) * 2);
	array214->length=3;
	array214->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array214->arr[0] = (((x) * (y)) * ((1) - (c))) + ((z) * (s));
	array214->arr[1] = ((y) * (y)) + (((1) - ((y) * (y))) * (c));
	array214->arr[2] = (((y) * (z)) * ((1) - (c))) - ((x) * (s));;
		array_number_t array215 = (array_number_t)malloc(sizeof(int) * 2);
	array215->length=3;
	array215->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array215->arr[0] = (((x) * (z)) * ((1) - (c))) - ((y) * (s));
	array215->arr[1] = (((z) * (y)) * ((1) - (c))) + ((x) * (s));
	array215->arr[2] = ((z) * (z)) + (((1) - ((z) * (z))) * (c));;
		array_array_number_t array212 = (array_array_number_t)malloc(sizeof(int) * 2);
	array212->length=3;
	array212->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	array212->arr[0] = array213;
	array212->arr[1] = array214;
	array212->arr[2] = array215;;
		ite207 = array212;
	}
	return ite207;
}
typedef struct env_t_224 {
	array_array_array_number_t relatives;
	array_number_t parents;
} env_t_224;
env_t_224* make_env_t_224(array_array_array_number_t relatives,array_number_t parents) {
	env_t_224* env = (env_t_224*)malloc(sizeof(env_t_224));
	env->relatives = relatives;
	env->parents = parents;
	return env;
}

value_t lambda224(env_t_224* env218, array_array_array_number_t acc, index_t i) {
	array_array_array_number_t relatives217 = env218->relatives;
	array_number_t parents216 = env218->parents;
	array_array_array_number_t ite223 = 0;
	if((parents216->arr[i]) == (-1)) {
		array_array_array_number_t newMatrix = (array_array_array_number_t)malloc(sizeof(int) * 2);
	newMatrix->length=1;
	newMatrix->arr = (array_array_number_t*)malloc(sizeof(array_array_number_t) * 1);
	newMatrix->arr[0] = relatives217->arr[i];;
		ite223 = matrix3d_concat(acc, newMatrix);
	} else {
		array_array_array_number_t newMatrix = (array_array_array_number_t)malloc(sizeof(int) * 2);
	newMatrix->length=1;
	newMatrix->arr = (array_array_number_t*)malloc(sizeof(array_array_number_t) * 1);
	newMatrix->arr[0] = matrix_mult(acc->arr[(int)(parents216->arr[i])], relatives217->arr[i]);;
		ite223 = matrix3d_concat(acc, newMatrix);
	}
	value_t res;
	res.array_array_array_number_t_value = ite223;
	return res;
}
array_array_array_number_t usecases_relatives_to_absolutes(array_array_array_number_t relatives, array_number_t parents) {
	array_number_t array222 = (array_number_t)malloc(sizeof(int) * 2);
	array222->length=0;
	array222->arr = (number_t*)malloc(sizeof(number_t) * 0);
	;
	array_array_number_t array221 = (array_array_number_t)malloc(sizeof(int) * 2);
	array221->length=1;
	array221->arr = (array_number_t*)malloc(sizeof(array_number_t) * 1);
	array221->arr[0] = array222;;
	array_array_array_number_t init = (array_array_array_number_t)malloc(sizeof(int) * 2);
	init->length=1;
	init->arr = (array_array_number_t*)malloc(sizeof(array_array_number_t) * 1);
	init->arr[0] = array221;;
	closure_t* closure220 = make_closure(lambda224, make_env_t_224(relatives,parents));
	return linalg_iterateMatrix3D(closure220, init, 0, (relatives->length) - (1));
}
typedef struct env_t_234 {
	array_number_t scale;
} env_t_234;
env_t_234* make_env_t_234(array_number_t scale) {
	env_t_234* env = (env_t_234*)malloc(sizeof(env_t_234));
	env->scale = scale;
	return env;
}

value_t lambda234(env_t_234* env226, array_number_t row) {
	array_number_t scale225 = env226->scale;
	value_t res;
	res.array_number_t_value = linalg_mult_vec_elementwise(row, scale225);
	return res;
}
typedef struct env_t_235 {
	value_t dummy_variable;
} env_t_235;
env_t_235* make_env_t_235() {
	env_t_235* env = (env_t_235*)malloc(sizeof(env_t_235));
	
	return env;
}

value_t lambda235(env_t_235* env229, number_t x) {
	
	value_t res;
	res.number_t_value = 1;
	return res;
}
array_array_number_t usecases_apply_global_transform(array_array_number_t pose_params, array_array_number_t positions) {
	array_array_number_t R = usecases_angle_axis_to_rotation_matrix(pose_params->arr[0]);
	array_number_t scale = pose_params->arr[1];
	closure_t* closure228 = make_closure(lambda234, make_env_t_234(scale));
	array_array_number_t R1 = linalg_matrixMap(closure228, R);
	array_array_number_t array232 = (array_array_number_t)malloc(sizeof(int) * 2);
	array232->length=1;
	array232->arr = (array_number_t*)malloc(sizeof(array_number_t) * 1);
	array232->arr[0] = pose_params->arr[2];;
	array_array_number_t T = linalg_matrixConcatCol(R1, matrix_transpose(array232));
	closure_t* closure231 = make_closure(lambda235, make_env_t_235());
	array_number_t ones = linalg_vectorMap(closure231, linalg_vectorRange(1, positions->arr[0]->length));
	array_array_number_t array233 = (array_array_number_t)malloc(sizeof(int) * 2);
	array233->length=1;
	array233->arr = (array_number_t*)malloc(sizeof(array_number_t) * 1);
	array233->arr[0] = ones;;
	array_array_number_t positions_homog = matrix_concat(positions, array233);
	return matrix_mult(T, positions_homog);
}
typedef struct env_t_248 {
	value_t dummy_variable;
} env_t_248;
env_t_248* make_env_t_248() {
	env_t_248* env = (env_t_248*)malloc(sizeof(env_t_248));
	
	return env;
}

value_t lambda248(env_t_248* env236, array_array_number_t m1, array_array_number_t m2) {
	
	value_t res;
	res.array_array_number_t_value = matrix_mult(m1, m2);
	return res;
}
typedef struct env_t_249 {
	array_array_number_t weights;
	array_array_array_number_t transforms;
	array_array_number_t base_positions;
} env_t_249;
env_t_249* make_env_t_249(array_array_number_t weights,array_array_array_number_t transforms,array_array_number_t base_positions) {
	env_t_249* env = (env_t_249*)malloc(sizeof(env_t_249));
	env->weights = weights;
	env->transforms = transforms;
	env->base_positions = base_positions;
	return env;
}

value_t lambda249(env_t_249* env242, array_array_number_t acc, index_t i_transform) {
	array_array_number_t weights241 = env242->weights;
	array_array_array_number_t transforms240 = env242->transforms;
	array_array_number_t base_positions239 = env242->base_positions;
	array_array_number_t curr_positions = matrix_mult(matrix_slice(transforms240->arr[i_transform], 0, 2), base_positions239);
	array_array_number_t w = linalg_matrixFillFromVector(base_positions239->length, weights241->arr[i_transform]);
	value_t res;
	res.array_array_number_t_value = linalg_matrixAdd(acc, linalg_matrixMultElementwise(curr_positions, w));
	return res;
}
array_array_number_t usecases_get_skinned_vertex_positions(index_t is_mirrored, index_t n_bones, array_array_number_t pose_params, array_array_array_number_t base_relatives, array_number_t parents, array_array_array_number_t inverse_base_absolutes, array_array_number_t base_positions, array_array_number_t weights) {
	array_array_array_number_t relatives = usecases_get_posed_relatives(n_bones, pose_params, base_relatives);
	array_array_array_number_t absolutes = usecases_relatives_to_absolutes(relatives, parents);
	closure_t* closure238 = make_closure(lambda248, make_env_t_248());
	array_array_array_number_t transforms = linalg_matrix3DMap2(closure238, absolutes, inverse_base_absolutes);
	index_t n_verts = base_positions->arr[0]->length;
	array_array_number_t init_positions = linalg_matrixFill(3, n_verts, 0);
	closure_t* closure244 = make_closure(lambda249, make_env_t_249(weights,transforms,base_positions));
	array_array_number_t positions = linalg_iterateMatrix(closure244, init_positions, 0, (transforms->length) - (1));
	array_array_number_t mirrored_positions = 0;
	if((is_mirrored) == (1)) {
		array_number_t array245 = (array_number_t)malloc(sizeof(int) * 2);
	array245->length=3;
	array245->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array245->arr[0] = -1;
	array245->arr[1] = 0;
	array245->arr[2] = 0;;
		array_number_t array246 = (array_number_t)malloc(sizeof(int) * 2);
	array246->length=3;
	array246->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array246->arr[0] = 0;
	array246->arr[1] = 1;
	array246->arr[2] = 0;;
		array_number_t array247 = (array_number_t)malloc(sizeof(int) * 2);
	array247->length=3;
	array247->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array247->arr[0] = 0;
	array247->arr[1] = 0;
	array247->arr[2] = 1;;
		array_array_number_t mirror_matrix = (array_array_number_t)malloc(sizeof(int) * 2);
	mirror_matrix->length=3;
	mirror_matrix->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	mirror_matrix->arr[0] = array245;
	mirror_matrix->arr[1] = array246;
	mirror_matrix->arr[2] = array247;;
		mirrored_positions = matrix_mult(mirror_matrix, positions);
	} else {
		
		mirrored_positions = positions;
	}
	return usecases_apply_global_transform(pose_params, mirrored_positions);
}
typedef struct env_t_257 {
	array_array_number_t vertex_positions;
	array_array_number_t points;
	index_t n_corr;
	array_number_t correspondences;
} env_t_257;
env_t_257* make_env_t_257(array_array_number_t vertex_positions,array_array_number_t points,index_t n_corr,array_number_t correspondences) {
	env_t_257* env = (env_t_257*)malloc(sizeof(env_t_257));
	env->vertex_positions = vertex_positions;
	env->points = points;
	env->n_corr = n_corr;
	env->correspondences = correspondences;
	return env;
}

value_t lambda257(env_t_257* env254, number_t i) {
	array_array_number_t vertex_positions253 = env254->vertex_positions;
	array_array_number_t points252 = env254->points;
	index_t n_corr251 = env254->n_corr;
	array_number_t correspondences250 = env254->correspondences;
	index_t ind = (int)(i);
	index_t r = (ind) / (n_corr251);
	index_t c = (ind) % (n_corr251);
	value_t res;
	res.number_t_value = (points252->arr[r]->arr[c]) - (vertex_positions253->arr[r]->arr[(int)(correspondences250->arr[c])]);
	return res;
}
array_number_t usecases_hand_objective(index_t is_mirrored, array_number_t param, array_number_t correspondences, array_array_number_t points, index_t n_bones, array_array_array_number_t base_relatives, array_number_t parents, array_array_array_number_t inverse_base_absolutes, array_array_number_t base_positions, array_array_number_t weights) {
	array_array_number_t pose_params = usecases_to_pose_params(param, n_bones);
	array_array_number_t vertex_positions = usecases_get_skinned_vertex_positions(is_mirrored, n_bones, pose_params, base_relatives, parents, inverse_base_absolutes, base_positions, weights);
	index_t n_corr = correspondences->length;
	index_t dims = 3;
	closure_t* closure256 = make_closure(lambda257, make_env_t_257(vertex_positions,points,n_corr,correspondences));
	array_number_t err = linalg_vectorMap(closure256, linalg_vectorRange(0, ((dims) * (n_corr)) - (1)));
	return err;
}
typedef struct env_t_285 {
	value_t dummy_variable;
} env_t_285;
env_t_285* make_env_t_285() {
	env_t_285* env = (env_t_285*)malloc(sizeof(env_t_285));
	
	return env;
}

value_t lambda285(env_t_285* env258, number_t r) {
	
	value_t res;
	res.array_number_t_value = linalg_vectorRange(((int)(r)) * (4), (((int)(r)) * (4)) + (3));
	return res;
}
void usecases_test1(array_number_t dum) {
	array_number_t a = (array_number_t)malloc(sizeof(int) * 2);
	a->length=3;
	a->arr = (number_t*)malloc(sizeof(number_t) * 3);
	a->arr[0] = 1;
	a->arr[1] = 2;
	a->arr[2] = 3;;
	array_number_t b = (array_number_t)malloc(sizeof(int) * 2);
	b->length=3;
	b->arr = (number_t*)malloc(sizeof(number_t) * 3);
	b->arr[0] = 5;
	b->arr[1] = 6;
	b->arr[2] = 7;;
	array_print(a);
	array_print(b);
	array_number_t c = linalg_cross(a, b);
	array_print(c);
	array_number_t d = linalg_mult_by_scalar(c, 15);
	array_print(d);
	array_number_t e = linalg_add_vec(a, b);
	array_print(e);
	array_number_t f = linalg_sub_vec(a, b);
	array_print(f);
	array_number_t g = linalg_add_vec3(a, b, c);
	array_print(g);
	number_t h = linalg_sqnorm(a);
	number_print(h);
	number_t i = linalg_dot_prod(a, b);
	number_print(i);
	array_number_t j = usecases_radial_distort(a, b);
	array_print(j);
	array_number_t k = usecases_rodrigues_rotate_point(a, b);
	array_print(k);
	array_number_t l = array_slice(k, 1, 2);
	array_print(l);
	array_number_t cam = (array_number_t)malloc(sizeof(int) * 2);
	cam->length=11;
	cam->arr = (number_t*)malloc(sizeof(number_t) * 11);
	cam->arr[0] = 0;
	cam->arr[1] = 2;
	cam->arr[2] = 4;
	cam->arr[3] = 6;
	cam->arr[4] = 8;
	cam->arr[5] = 10;
	cam->arr[6] = 12;
	cam->arr[7] = 14;
	cam->arr[8] = 16;
	cam->arr[9] = 18;
	cam->arr[10] = 20;;
	array_number_t m = usecases_project(cam, j);
	array_print(m);
	array_number_t array274 = (array_number_t)malloc(sizeof(int) * 2);
	array274->length=3;
	array274->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array274->arr[0] = 1;
	array274->arr[1] = 2;
	array274->arr[2] = 3;;
	array_number_t array275 = (array_number_t)malloc(sizeof(int) * 2);
	array275->length=3;
	array275->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array275->arr[0] = 4;
	array275->arr[1] = 5;
	array275->arr[2] = 6;;
	array_number_t array276 = (array_number_t)malloc(sizeof(int) * 2);
	array276->length=3;
	array276->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array276->arr[0] = 7;
	array276->arr[1] = 8;
	array276->arr[2] = 9;;
	array_array_number_t mat1 = (array_array_number_t)malloc(sizeof(int) * 2);
	mat1->length=3;
	mat1->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	mat1->arr[0] = array274;
	mat1->arr[1] = array275;
	mat1->arr[2] = array276;;
	array_array_number_t n = matrix_mult(mat1, mat1);
	matrix_print(n);
	array_array_number_t o = matrix_transpose(n);
	matrix_print(o);
	array_array_number_t p = linalg_matrixConcatCol(mat1, mat1);
	matrix_print(p);
	closure_t* closure260 = make_closure(lambda285, make_env_t_285());
	array_array_number_t base_rel = linalg_vectorMapToMatrix(closure260, linalg_vectorRange(1, 4));
	array_array_number_t q = usecases_make_relative(a, base_rel);
	matrix_print(q);
	array_array_number_t r = usecases_angle_axis_to_rotation_matrix(a);
	matrix_print(r);
	array_array_number_t s = usecases_apply_global_transform(mat1, mat1);
	matrix_print(s);
	array_array_number_t t = linalg_matrixAdd(mat1, mat1);
	matrix_print(t);
	array_array_number_t u = linalg_matrixFillFromVector(5, a);
	matrix_print(u);
	return ;
}
#endif
