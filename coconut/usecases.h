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
	array_number_t ite95 = NULL;
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
		ite95 = linalg_add_vec(linalg_add_vec(v1, v2), linalg_mult_by_scalar(w, tmp));
	} else {
		
		ite95 = linalg_add_vec(x, linalg_cross(rot, x));
	}
	return ite95;
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
typedef struct env_t_99 {
	value_t dummy_variable;
} env_t_99;
env_t_99* make_env_t_99() {
	env_t_99* env = (env_t_99*)malloc(sizeof(env_t_99));
	
	return env;
}

value_t lambda99(env_t_99* env96, number_t w) {
	
	value_t res;
	res.number_t_value = usecases_compute_zach_weight_error(w);
	return res;
}
array_number_t usecases_w_err(array_number_t w) {
	closure_t* closure98 = make_closure(lambda99, make_env_t_99());
	return linalg_vectorMap(closure98, w);
}
typedef struct env_t_108 {
	array_array_number_t x;
	array_number_t w;
	array_array_number_t obs;
	array_array_number_t feat;
	array_array_number_t cams;
} env_t_108;
env_t_108* make_env_t_108(array_array_number_t x,array_number_t w,array_array_number_t obs,array_array_number_t feat,array_array_number_t cams) {
	env_t_108* env = (env_t_108*)malloc(sizeof(env_t_108));
	env->x = x;
	env->w = w;
	env->obs = obs;
	env->feat = feat;
	env->cams = cams;
	return env;
}

value_t lambda108(env_t_108* env105, number_t i) {
	array_array_number_t x104 = env105->x;
	array_number_t w103 = env105->w;
	array_array_number_t obs102 = env105->obs;
	array_array_number_t feat101 = env105->feat;
	array_array_number_t cams100 = env105->cams;
	value_t res;
	res.array_number_t_value = usecases_compute_reproj_err(cams100->arr[(int)(obs102->arr[(int)(i)]->arr[0])], x104->arr[(int)(obs102->arr[(int)(i)]->arr[1])], w103->arr[(int)(i)], feat101->arr[(int)(i)]);
	return res;
}
array_array_number_t usecases_reproj_err(array_array_number_t cams, array_array_number_t x, array_number_t w, array_array_number_t obs, array_array_number_t feat) {
	index_t n = cams->length;
	index_t p = w->length;
	array_number_t range = linalg_vectorRange(0, (p) - (1));
	closure_t* closure107 = make_closure(lambda108, make_env_t_108(x,w,obs,feat,cams));
	return linalg_vectorMapToMatrix(closure107, range);
}
typedef struct env_t_132 {
	array_number_t one_cam;
} env_t_132;
env_t_132* make_env_t_132(array_number_t one_cam) {
	env_t_132* env = (env_t_132*)malloc(sizeof(env_t_132));
	env->one_cam = one_cam;
	return env;
}

value_t lambda132(env_t_132* env110, number_t x) {
	array_number_t one_cam109 = env110->one_cam;
	value_t res;
	res.array_number_t_value = one_cam109;
	return res;
}
typedef struct env_t_133 {
	array_number_t one_x;
} env_t_133;
env_t_133* make_env_t_133(array_number_t one_x) {
	env_t_133* env = (env_t_133*)malloc(sizeof(env_t_133));
	env->one_x = one_x;
	return env;
}

value_t lambda133(env_t_133* env114, number_t x) {
	array_number_t one_x113 = env114->one_x;
	value_t res;
	res.array_number_t_value = one_x113;
	return res;
}
typedef struct env_t_134 {
	number_t one_w;
} env_t_134;
env_t_134* make_env_t_134(number_t one_w) {
	env_t_134* env = (env_t_134*)malloc(sizeof(env_t_134));
	env->one_w = one_w;
	return env;
}

value_t lambda134(env_t_134* env118, number_t x) {
	number_t one_w117 = env118->one_w;
	value_t res;
	res.number_t_value = one_w117;
	return res;
}
typedef struct env_t_135 {
	array_number_t one_feat;
} env_t_135;
env_t_135* make_env_t_135(array_number_t one_feat) {
	env_t_135* env = (env_t_135*)malloc(sizeof(env_t_135));
	env->one_feat = one_feat;
	return env;
}

value_t lambda135(env_t_135* env122, number_t x) {
	array_number_t one_feat121 = env122->one_feat;
	value_t res;
	res.array_number_t_value = one_feat121;
	return res;
}
typedef struct env_t_136 {
	index_t n;
	index_t m;
} env_t_136;
env_t_136* make_env_t_136(index_t n,index_t m) {
	env_t_136* env = (env_t_136*)malloc(sizeof(env_t_136));
	env->n = n;
	env->m = m;
	return env;
}

value_t lambda136(env_t_136* env127, number_t x) {
	index_t n126 = env127->n;
	index_t m125 = env127->m;
	array_number_t array130 = (array_number_t)malloc(sizeof(int) * 2);
	array130->length=2;
	array130->arr = (number_t*)malloc(sizeof(number_t) * 2);
	array130->arr[0] = (double)(((int)(x)) % (n126));
	array130->arr[1] = (double)(((int)(x)) % (m125));;
	value_t res;
	res.array_number_t_value = array130;
	return res;
}
array_array_number_t usecases_run_ba_from_file(string_t fn) {
	array_number_t nmp = linalg_vectorRead(fn, 0);
	index_t n = (int)(nmp->arr[0]);
	index_t m = (int)(nmp->arr[1]);
	index_t p = (int)(nmp->arr[2]);
	array_number_t one_cam = linalg_vectorRead(fn, 1);
	closure_t* closure112 = make_closure(lambda132, make_env_t_132(one_cam));
	array_array_number_t cam = linalg_vectorMapToMatrix(closure112, linalg_vectorRange(1, n));
	array_number_t one_x = linalg_vectorRead(fn, 2);
	closure_t* closure116 = make_closure(lambda133, make_env_t_133(one_x));
	array_array_number_t x = linalg_vectorMapToMatrix(closure116, linalg_vectorRange(1, m));
	number_t one_w = linalg_numberRead(fn, 3);
	closure_t* closure120 = make_closure(lambda134, make_env_t_134(one_w));
	array_number_t w = linalg_vectorMap(closure120, linalg_vectorRange(1, p));
	array_number_t one_feat = linalg_vectorRead(fn, 4);
	closure_t* closure124 = make_closure(lambda135, make_env_t_135(one_feat));
	array_array_number_t feat = linalg_vectorMapToMatrix(closure124, linalg_vectorRange(1, p));
	closure_t* closure129 = make_closure(lambda136, make_env_t_136(n,m));
	array_array_number_t obs = linalg_vectorMapToMatrix(closure129, linalg_vectorRange(0, (p) - (1)));
	timer_t t = tic();
	array_array_number_t res = usecases_reproj_err(cam, x, w, obs, feat);
	toc(t);
	return res;
}
typedef struct env_t_141 {
	number_t mx;
} env_t_141;
env_t_141* make_env_t_141(number_t mx) {
	env_t_141* env = (env_t_141*)malloc(sizeof(env_t_141));
	env->mx = mx;
	return env;
}

value_t lambda141(env_t_141* env138, number_t x) {
	number_t mx137 = env138->mx;
	value_t res;
	res.number_t_value = exp((x) - (mx137));
	return res;
}
number_t usecases_logsumexp(array_number_t arr) {
	number_t mx = array_max(arr);
	closure_t* closure140 = make_closure(lambda141, make_env_t_141(mx));
	number_t semx = array_sum(linalg_vectorMap(closure140, arr));
	return (log(semx)) + (mx);
}
typedef struct env_t_146 {
	number_t a;
} env_t_146;
env_t_146* make_env_t_146(number_t a) {
	env_t_146* env = (env_t_146*)malloc(sizeof(env_t_146));
	env->a = a;
	return env;
}

value_t lambda146(env_t_146* env143, number_t j) {
	number_t a142 = env143->a;
	value_t res;
	res.number_t_value = gamma_ln((a142) + ((0.5) * ((1) - ((double)(j)))));
	return res;
}
number_t usecases_log_gamma_distrib(number_t a, number_t p) {
	closure_t* closure145 = make_closure(lambda146, make_env_t_146(a));
	return (log(pow(3.14159265358979, (0.25) * ((p) * ((p) - (1)))))) + (array_sum(linalg_vectorMap(closure145, linalg_vectorRange(1, (int)(p)))));
}

array_array_number_t usecases_new_matrix_test(array_number_t dum) {
	array_number_t array147 = (array_number_t)malloc(sizeof(int) * 2);
	array147->length=3;
	array147->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array147->arr[0] = 0;
	array147->arr[1] = 0;
	array147->arr[2] = 0;;
	array_array_number_t res = (array_array_number_t)malloc(sizeof(int) * 2);
	res->length=1;
	res->arr = (array_number_t*)malloc(sizeof(array_number_t) * 1);
	res->arr[0] = array147;;
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
	array_number_t array148 = (array_number_t)malloc(sizeof(int) * 2);
	array148->length=3;
	array148->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array148->arr[0] = theta->arr[i1];
	array148->arr[1] = theta->arr[(i1) + (1)];
	array148->arr[2] = 0;;
	array_number_t array149 = (array_number_t)malloc(sizeof(int) * 2);
	array149->length=3;
	array149->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array149->arr[0] = theta->arr[(i1) + (2)];
	array149->arr[1] = 0;
	array149->arr[2] = 0;;
	array_number_t array150 = (array_number_t)malloc(sizeof(int) * 2);
	array150->length=3;
	array150->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array150->arr[0] = theta->arr[(i1) + (3)];
	array150->arr[1] = 0;
	array150->arr[2] = 0;;
	array_number_t array151 = (array_number_t)malloc(sizeof(int) * 2);
	array151->length=3;
	array151->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array151->arr[0] = 0;
	array151->arr[1] = 0;
	array151->arr[2] = 0;;
	array_array_number_t finger1 = (array_array_number_t)malloc(sizeof(int) * 2);
	finger1->length=4;
	finger1->arr = (array_number_t*)malloc(sizeof(array_number_t) * 4);
	finger1->arr[0] = array148;
	finger1->arr[1] = array149;
	finger1->arr[2] = array150;
	finger1->arr[3] = array151;;
	index_t i2 = (i1) + (4);
	array_number_t array152 = (array_number_t)malloc(sizeof(int) * 2);
	array152->length=3;
	array152->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array152->arr[0] = theta->arr[i2];
	array152->arr[1] = theta->arr[(i2) + (1)];
	array152->arr[2] = 0;;
	array_number_t array153 = (array_number_t)malloc(sizeof(int) * 2);
	array153->length=3;
	array153->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array153->arr[0] = theta->arr[(i2) + (2)];
	array153->arr[1] = 0;
	array153->arr[2] = 0;;
	array_number_t array154 = (array_number_t)malloc(sizeof(int) * 2);
	array154->length=3;
	array154->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array154->arr[0] = theta->arr[(i2) + (3)];
	array154->arr[1] = 0;
	array154->arr[2] = 0;;
	array_number_t array155 = (array_number_t)malloc(sizeof(int) * 2);
	array155->length=3;
	array155->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array155->arr[0] = 0;
	array155->arr[1] = 0;
	array155->arr[2] = 0;;
	array_array_number_t finger2 = (array_array_number_t)malloc(sizeof(int) * 2);
	finger2->length=4;
	finger2->arr = (array_number_t*)malloc(sizeof(array_number_t) * 4);
	finger2->arr[0] = array152;
	finger2->arr[1] = array153;
	finger2->arr[2] = array154;
	finger2->arr[3] = array155;;
	index_t i3 = (i2) + (4);
	array_number_t array156 = (array_number_t)malloc(sizeof(int) * 2);
	array156->length=3;
	array156->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array156->arr[0] = theta->arr[i3];
	array156->arr[1] = theta->arr[(i3) + (1)];
	array156->arr[2] = 0;;
	array_number_t array157 = (array_number_t)malloc(sizeof(int) * 2);
	array157->length=3;
	array157->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array157->arr[0] = theta->arr[(i3) + (2)];
	array157->arr[1] = 0;
	array157->arr[2] = 0;;
	array_number_t array158 = (array_number_t)malloc(sizeof(int) * 2);
	array158->length=3;
	array158->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array158->arr[0] = theta->arr[(i3) + (3)];
	array158->arr[1] = 0;
	array158->arr[2] = 0;;
	array_number_t array159 = (array_number_t)malloc(sizeof(int) * 2);
	array159->length=3;
	array159->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array159->arr[0] = 0;
	array159->arr[1] = 0;
	array159->arr[2] = 0;;
	array_array_number_t finger3 = (array_array_number_t)malloc(sizeof(int) * 2);
	finger3->length=4;
	finger3->arr = (array_number_t*)malloc(sizeof(array_number_t) * 4);
	finger3->arr[0] = array156;
	finger3->arr[1] = array157;
	finger3->arr[2] = array158;
	finger3->arr[3] = array159;;
	index_t i4 = (i3) + (4);
	array_number_t array160 = (array_number_t)malloc(sizeof(int) * 2);
	array160->length=3;
	array160->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array160->arr[0] = theta->arr[i4];
	array160->arr[1] = theta->arr[(i4) + (1)];
	array160->arr[2] = 0;;
	array_number_t array161 = (array_number_t)malloc(sizeof(int) * 2);
	array161->length=3;
	array161->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array161->arr[0] = theta->arr[(i4) + (2)];
	array161->arr[1] = 0;
	array161->arr[2] = 0;;
	array_number_t array162 = (array_number_t)malloc(sizeof(int) * 2);
	array162->length=3;
	array162->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array162->arr[0] = theta->arr[(i4) + (3)];
	array162->arr[1] = 0;
	array162->arr[2] = 0;;
	array_number_t array163 = (array_number_t)malloc(sizeof(int) * 2);
	array163->length=3;
	array163->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array163->arr[0] = 0;
	array163->arr[1] = 0;
	array163->arr[2] = 0;;
	array_array_number_t finger4 = (array_array_number_t)malloc(sizeof(int) * 2);
	finger4->length=4;
	finger4->arr = (array_number_t*)malloc(sizeof(array_number_t) * 4);
	finger4->arr[0] = array160;
	finger4->arr[1] = array161;
	finger4->arr[2] = array162;
	finger4->arr[3] = array163;;
	index_t i5 = (i4) + (4);
	array_number_t array164 = (array_number_t)malloc(sizeof(int) * 2);
	array164->length=3;
	array164->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array164->arr[0] = theta->arr[i5];
	array164->arr[1] = theta->arr[(i5) + (1)];
	array164->arr[2] = 0;;
	array_number_t array165 = (array_number_t)malloc(sizeof(int) * 2);
	array165->length=3;
	array165->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array165->arr[0] = theta->arr[(i5) + (2)];
	array165->arr[1] = 0;
	array165->arr[2] = 0;;
	array_number_t array166 = (array_number_t)malloc(sizeof(int) * 2);
	array166->length=3;
	array166->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array166->arr[0] = theta->arr[(i5) + (3)];
	array166->arr[1] = 0;
	array166->arr[2] = 0;;
	array_number_t array167 = (array_number_t)malloc(sizeof(int) * 2);
	array167->length=3;
	array167->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array167->arr[0] = 0;
	array167->arr[1] = 0;
	array167->arr[2] = 0;;
	array_array_number_t finger5 = (array_array_number_t)malloc(sizeof(int) * 2);
	finger5->length=4;
	finger5->arr = (array_number_t*)malloc(sizeof(array_number_t) * 4);
	finger5->arr[0] = array164;
	finger5->arr[1] = array165;
	finger5->arr[2] = array166;
	finger5->arr[3] = array167;;
	return matrix_concat(pose_params, matrix_concat(finger1, matrix_concat(finger2, matrix_concat(finger3, matrix_concat(finger4, finger5)))));
}

array_array_number_t usecases_euler_angles_to_rotation_matrix(array_number_t xzy) {
	number_t tx = xzy->arr[0];
	number_t ty = xzy->arr[2];
	number_t tz = xzy->arr[1];
	array_number_t array168 = (array_number_t)malloc(sizeof(int) * 2);
	array168->length=3;
	array168->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array168->arr[0] = 1;
	array168->arr[1] = 0;
	array168->arr[2] = 0;;
	array_number_t array169 = (array_number_t)malloc(sizeof(int) * 2);
	array169->length=3;
	array169->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array169->arr[0] = 0;
	array169->arr[1] = cos(tx);
	array169->arr[2] = -(sin(tx));;
	array_number_t array170 = (array_number_t)malloc(sizeof(int) * 2);
	array170->length=3;
	array170->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array170->arr[0] = 0;
	array170->arr[1] = sin(tx);
	array170->arr[2] = cos(tx);;
	array_array_number_t Rx = (array_array_number_t)malloc(sizeof(int) * 2);
	Rx->length=3;
	Rx->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	Rx->arr[0] = array168;
	Rx->arr[1] = array169;
	Rx->arr[2] = array170;;
	array_number_t array171 = (array_number_t)malloc(sizeof(int) * 2);
	array171->length=3;
	array171->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array171->arr[0] = cos(ty);
	array171->arr[1] = 0;
	array171->arr[2] = sin(ty);;
	array_number_t array172 = (array_number_t)malloc(sizeof(int) * 2);
	array172->length=3;
	array172->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array172->arr[0] = 0;
	array172->arr[1] = 1;
	array172->arr[2] = 0;;
	array_number_t array173 = (array_number_t)malloc(sizeof(int) * 2);
	array173->length=3;
	array173->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array173->arr[0] = -(sin(ty));
	array173->arr[1] = 0;
	array173->arr[2] = cos(ty);;
	array_array_number_t Ry = (array_array_number_t)malloc(sizeof(int) * 2);
	Ry->length=3;
	Ry->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	Ry->arr[0] = array171;
	Ry->arr[1] = array172;
	Ry->arr[2] = array173;;
	array_number_t array174 = (array_number_t)malloc(sizeof(int) * 2);
	array174->length=3;
	array174->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array174->arr[0] = cos(tz);
	array174->arr[1] = -(sin(tz));
	array174->arr[2] = 0;;
	array_number_t array175 = (array_number_t)malloc(sizeof(int) * 2);
	array175->length=3;
	array175->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array175->arr[0] = sin(tz);
	array175->arr[1] = cos(tz);
	array175->arr[2] = 0;;
	array_number_t array176 = (array_number_t)malloc(sizeof(int) * 2);
	array176->length=3;
	array176->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array176->arr[0] = 0;
	array176->arr[1] = 0;
	array176->arr[2] = 1;;
	array_array_number_t Rz = (array_array_number_t)malloc(sizeof(int) * 2);
	Rz->length=3;
	Rz->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	Rz->arr[0] = array174;
	Rz->arr[1] = array175;
	Rz->arr[2] = array176;;
	return matrix_mult(Rz, matrix_mult(Ry, Rx));
}

array_array_number_t usecases_make_relative(array_number_t pose_params, array_array_number_t base_relative) {
	array_array_number_t R = usecases_euler_angles_to_rotation_matrix(pose_params);
	array_number_t array177 = (array_number_t)malloc(sizeof(int) * 2);
	array177->length=1;
	array177->arr = (number_t*)malloc(sizeof(number_t) * 1);
	array177->arr[0] = 0;;
	array_number_t array178 = (array_number_t)malloc(sizeof(int) * 2);
	array178->length=1;
	array178->arr = (number_t*)malloc(sizeof(number_t) * 1);
	array178->arr[0] = 0;;
	array_number_t array179 = (array_number_t)malloc(sizeof(int) * 2);
	array179->length=1;
	array179->arr = (number_t*)malloc(sizeof(number_t) * 1);
	array179->arr[0] = 0;;
	array_array_number_t r1 = (array_array_number_t)malloc(sizeof(int) * 2);
	r1->length=3;
	r1->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	r1->arr[0] = array177;
	r1->arr[1] = array178;
	r1->arr[2] = array179;;
	array_number_t array180 = (array_number_t)malloc(sizeof(int) * 2);
	array180->length=4;
	array180->arr = (number_t*)malloc(sizeof(number_t) * 4);
	array180->arr[0] = 0;
	array180->arr[1] = 0;
	array180->arr[2] = 0;
	array180->arr[3] = 1;;
	array_array_number_t r2 = (array_array_number_t)malloc(sizeof(int) * 2);
	r2->length=1;
	r2->arr = (array_number_t*)malloc(sizeof(array_number_t) * 1);
	r2->arr[0] = array180;;
	array_array_number_t T = matrix_concat(linalg_matrixConcatCol(R, r1), r2);
	return matrix_mult(base_relative, T);
}
typedef struct env_t_187 {
	array_array_number_t pose_params;
	index_t offset;
	array_array_array_number_t base_relatives;
} env_t_187;
env_t_187* make_env_t_187(array_array_number_t pose_params,index_t offset,array_array_array_number_t base_relatives) {
	env_t_187* env = (env_t_187*)malloc(sizeof(env_t_187));
	env->pose_params = pose_params;
	env->offset = offset;
	env->base_relatives = base_relatives;
	return env;
}

value_t lambda187(env_t_187* env184, number_t i_bone) {
	array_array_number_t pose_params183 = env184->pose_params;
	index_t offset182 = env184->offset;
	array_array_array_number_t base_relatives181 = env184->base_relatives;
	value_t res;
	res.array_array_number_t_value = usecases_make_relative(pose_params183->arr[((int)(i_bone)) + (offset182)], base_relatives181->arr[(int)(i_bone)]);
	return res;
}
array_array_array_number_t usecases_get_posed_relatives(index_t n_bones, array_array_number_t pose_params, array_array_array_number_t base_relatives) {
	index_t offset = 3;
	closure_t* closure186 = make_closure(lambda187, make_env_t_187(pose_params,offset,base_relatives));
	return linalg_vectorMapToMatrix3D(closure186, linalg_vectorRange(0, (n_bones) - (1)));
}

array_array_number_t usecases_angle_axis_to_rotation_matrix(array_number_t angle_axis) {
	number_t n = sqrt(linalg_sqnorm(angle_axis));
	array_array_number_t ite188 = NULL;
	if((n) < (0.0001)) {
		array_number_t array190 = (array_number_t)malloc(sizeof(int) * 2);
	array190->length=3;
	array190->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array190->arr[0] = 1;
	array190->arr[1] = 0;
	array190->arr[2] = 0;;
		array_number_t array191 = (array_number_t)malloc(sizeof(int) * 2);
	array191->length=3;
	array191->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array191->arr[0] = 0;
	array191->arr[1] = 1;
	array191->arr[2] = 0;;
		array_number_t array192 = (array_number_t)malloc(sizeof(int) * 2);
	array192->length=3;
	array192->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array192->arr[0] = 0;
	array192->arr[1] = 0;
	array192->arr[2] = 1;;
		array_array_number_t array189 = (array_array_number_t)malloc(sizeof(int) * 2);
	array189->length=3;
	array189->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	array189->arr[0] = array190;
	array189->arr[1] = array191;
	array189->arr[2] = array192;;
		ite188 = array189;
	} else {
		number_t x = (angle_axis->arr[0]) / (n);
		number_t y = (angle_axis->arr[1]) / (n);
		number_t z = (angle_axis->arr[2]) / (n);
		number_t s = sin(n);
		number_t c = cos(n);
		array_number_t array194 = (array_number_t)malloc(sizeof(int) * 2);
	array194->length=3;
	array194->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array194->arr[0] = ((x) * (x)) + (((1) - ((x) * (x))) * (c));
	array194->arr[1] = (((x) * (y)) * ((1) - (c))) - ((z) * (s));
	array194->arr[2] = (((x) * (z)) * ((1) - (c))) + ((y) * (s));;
		array_number_t array195 = (array_number_t)malloc(sizeof(int) * 2);
	array195->length=3;
	array195->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array195->arr[0] = (((x) * (y)) * ((1) - (c))) + ((z) * (s));
	array195->arr[1] = ((y) * (y)) + (((1) - ((y) * (y))) * (c));
	array195->arr[2] = (((y) * (z)) * ((1) - (c))) - ((x) * (s));;
		array_number_t array196 = (array_number_t)malloc(sizeof(int) * 2);
	array196->length=3;
	array196->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array196->arr[0] = (((x) * (z)) * ((1) - (c))) - ((y) * (s));
	array196->arr[1] = (((z) * (y)) * ((1) - (c))) + ((x) * (s));
	array196->arr[2] = ((z) * (z)) + (((1) - ((z) * (z))) * (c));;
		array_array_number_t array193 = (array_array_number_t)malloc(sizeof(int) * 2);
	array193->length=3;
	array193->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	array193->arr[0] = array194;
	array193->arr[1] = array195;
	array193->arr[2] = array196;;
		ite188 = array193;
	}
	return ite188;
}
typedef struct env_t_205 {
	array_array_array_number_t relatives;
	array_number_t parents;
} env_t_205;
env_t_205* make_env_t_205(array_array_array_number_t relatives,array_number_t parents) {
	env_t_205* env = (env_t_205*)malloc(sizeof(env_t_205));
	env->relatives = relatives;
	env->parents = parents;
	return env;
}

value_t lambda205(env_t_205* env199, array_array_array_number_t acc, index_t i) {
	array_array_array_number_t relatives198 = env199->relatives;
	array_number_t parents197 = env199->parents;
	array_array_array_number_t ite204 = NULL;
	if((parents197->arr[i]) == (-1)) {
		array_array_array_number_t newMatrix = (array_array_array_number_t)malloc(sizeof(int) * 2);
	newMatrix->length=1;
	newMatrix->arr = (array_array_number_t*)malloc(sizeof(array_array_number_t) * 1);
	newMatrix->arr[0] = relatives198->arr[i];;
		ite204 = matrix3d_concat(acc, newMatrix);
	} else {
		array_array_array_number_t newMatrix = (array_array_array_number_t)malloc(sizeof(int) * 2);
	newMatrix->length=1;
	newMatrix->arr = (array_array_number_t*)malloc(sizeof(array_array_number_t) * 1);
	newMatrix->arr[0] = matrix_mult(acc->arr[(int)(parents197->arr[i])], relatives198->arr[i]);;
		ite204 = matrix3d_concat(acc, newMatrix);
	}
	value_t res;
	res.array_array_array_number_t_value = ite204;
	return res;
}
array_array_array_number_t usecases_relatives_to_absolutes(array_array_array_number_t relatives, array_number_t parents) {
	array_number_t array203 = (array_number_t)malloc(sizeof(int) * 2);
	array203->length=0;
	array203->arr = (number_t*)malloc(sizeof(number_t) * 0);
	;
	array_array_number_t array202 = (array_array_number_t)malloc(sizeof(int) * 2);
	array202->length=1;
	array202->arr = (array_number_t*)malloc(sizeof(array_number_t) * 1);
	array202->arr[0] = array203;;
	array_array_array_number_t init = (array_array_array_number_t)malloc(sizeof(int) * 2);
	init->length=1;
	init->arr = (array_array_number_t*)malloc(sizeof(array_array_number_t) * 1);
	init->arr[0] = array202;;
	closure_t* closure201 = make_closure(lambda205, make_env_t_205(relatives,parents));
	return linalg_iterateMatrix3D(closure201, init, 0, (relatives->length) - (1));
}
typedef struct env_t_215 {
	array_number_t scale;
} env_t_215;
env_t_215* make_env_t_215(array_number_t scale) {
	env_t_215* env = (env_t_215*)malloc(sizeof(env_t_215));
	env->scale = scale;
	return env;
}

value_t lambda215(env_t_215* env207, array_number_t row) {
	array_number_t scale206 = env207->scale;
	value_t res;
	res.array_number_t_value = linalg_mult_vec_elementwise(row, scale206);
	return res;
}
typedef struct env_t_216 {
	value_t dummy_variable;
} env_t_216;
env_t_216* make_env_t_216() {
	env_t_216* env = (env_t_216*)malloc(sizeof(env_t_216));
	
	return env;
}

value_t lambda216(env_t_216* env210, number_t x) {
	
	value_t res;
	res.number_t_value = 1;
	return res;
}
array_array_number_t usecases_apply_global_transform(array_array_number_t pose_params, array_array_number_t positions) {
	array_array_number_t R = usecases_angle_axis_to_rotation_matrix(pose_params->arr[0]);
	array_number_t scale = pose_params->arr[1];
	closure_t* closure209 = make_closure(lambda215, make_env_t_215(scale));
	array_array_number_t R1 = linalg_matrixMap(closure209, R);
	array_array_number_t array213 = (array_array_number_t)malloc(sizeof(int) * 2);
	array213->length=1;
	array213->arr = (array_number_t*)malloc(sizeof(array_number_t) * 1);
	array213->arr[0] = pose_params->arr[2];;
	array_array_number_t T = linalg_matrixConcatCol(R1, matrix_transpose(array213));
	closure_t* closure212 = make_closure(lambda216, make_env_t_216());
	array_number_t ones = linalg_vectorMap(closure212, linalg_vectorRange(1, positions->arr[0]->length));
	array_array_number_t array214 = (array_array_number_t)malloc(sizeof(int) * 2);
	array214->length=1;
	array214->arr = (array_number_t*)malloc(sizeof(array_number_t) * 1);
	array214->arr[0] = ones;;
	array_array_number_t positions_homog = matrix_concat(positions, array214);
	return matrix_mult(T, positions_homog);
}
typedef struct env_t_229 {
	value_t dummy_variable;
} env_t_229;
env_t_229* make_env_t_229() {
	env_t_229* env = (env_t_229*)malloc(sizeof(env_t_229));
	
	return env;
}

value_t lambda229(env_t_229* env217, array_array_number_t m1, array_array_number_t m2) {
	
	value_t res;
	res.array_array_number_t_value = matrix_mult(m1, m2);
	return res;
}
typedef struct env_t_230 {
	array_array_number_t weights;
	array_array_array_number_t transforms;
	array_array_number_t base_positions;
} env_t_230;
env_t_230* make_env_t_230(array_array_number_t weights,array_array_array_number_t transforms,array_array_number_t base_positions) {
	env_t_230* env = (env_t_230*)malloc(sizeof(env_t_230));
	env->weights = weights;
	env->transforms = transforms;
	env->base_positions = base_positions;
	return env;
}

value_t lambda230(env_t_230* env223, array_array_number_t acc, index_t i_transform) {
	array_array_number_t weights222 = env223->weights;
	array_array_array_number_t transforms221 = env223->transforms;
	array_array_number_t base_positions220 = env223->base_positions;
	array_array_number_t curr_positions = matrix_mult(matrix_slice(transforms221->arr[i_transform], 0, 2), base_positions220);
	array_array_number_t w = linalg_matrixFillFromVector(base_positions220->length, weights222->arr[i_transform]);
	value_t res;
	res.array_array_number_t_value = linalg_matrixAdd(acc, linalg_matrixMultElementwise(curr_positions, w));
	return res;
}
array_array_number_t usecases_get_skinned_vertex_positions(index_t is_mirrored, index_t n_bones, array_array_number_t pose_params, array_array_array_number_t base_relatives, array_number_t parents, array_array_array_number_t inverse_base_absolutes, array_array_number_t base_positions, array_array_number_t weights) {
	array_array_array_number_t relatives = usecases_get_posed_relatives(n_bones, pose_params, base_relatives);
	array_array_array_number_t absolutes = usecases_relatives_to_absolutes(relatives, parents);
	closure_t* closure219 = make_closure(lambda229, make_env_t_229());
	array_array_array_number_t transforms = linalg_matrix3DMap2(closure219, absolutes, inverse_base_absolutes);
	index_t n_verts = base_positions->arr[0]->length;
	array_array_number_t init_positions = linalg_matrixFill(3, n_verts, 0);
	closure_t* closure225 = make_closure(lambda230, make_env_t_230(weights,transforms,base_positions));
	array_array_number_t positions = linalg_iterateMatrix(closure225, init_positions, 0, (transforms->length) - (1));
	array_array_number_t mirrored_positions = NULL;
	if((is_mirrored) == (1)) {
		array_number_t array226 = (array_number_t)malloc(sizeof(int) * 2);
	array226->length=3;
	array226->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array226->arr[0] = -1;
	array226->arr[1] = 0;
	array226->arr[2] = 0;;
		array_number_t array227 = (array_number_t)malloc(sizeof(int) * 2);
	array227->length=3;
	array227->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array227->arr[0] = 0;
	array227->arr[1] = 1;
	array227->arr[2] = 0;;
		array_number_t array228 = (array_number_t)malloc(sizeof(int) * 2);
	array228->length=3;
	array228->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array228->arr[0] = 0;
	array228->arr[1] = 0;
	array228->arr[2] = 1;;
		array_array_number_t mirror_matrix = (array_array_number_t)malloc(sizeof(int) * 2);
	mirror_matrix->length=3;
	mirror_matrix->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	mirror_matrix->arr[0] = array226;
	mirror_matrix->arr[1] = array227;
	mirror_matrix->arr[2] = array228;;
		mirrored_positions = matrix_mult(mirror_matrix, positions);
	} else {
		
		mirrored_positions = positions;
	}
	return usecases_apply_global_transform(pose_params, mirrored_positions);
}
typedef struct env_t_238 {
	array_array_number_t vertex_positions;
	array_array_number_t points;
	index_t n_corr;
	array_number_t correspondences;
} env_t_238;
env_t_238* make_env_t_238(array_array_number_t vertex_positions,array_array_number_t points,index_t n_corr,array_number_t correspondences) {
	env_t_238* env = (env_t_238*)malloc(sizeof(env_t_238));
	env->vertex_positions = vertex_positions;
	env->points = points;
	env->n_corr = n_corr;
	env->correspondences = correspondences;
	return env;
}

value_t lambda238(env_t_238* env235, number_t i) {
	array_array_number_t vertex_positions234 = env235->vertex_positions;
	array_array_number_t points233 = env235->points;
	index_t n_corr232 = env235->n_corr;
	array_number_t correspondences231 = env235->correspondences;
	index_t ind = (int)(i);
	index_t r = (ind) / (n_corr232);
	index_t c = (ind) % (n_corr232);
	value_t res;
	res.number_t_value = (points233->arr[r]->arr[c]) - (vertex_positions234->arr[r]->arr[(int)(correspondences231->arr[c])]);
	return res;
}
array_number_t usecases_hand_objective(index_t is_mirrored, array_number_t param, array_number_t correspondences, array_array_number_t points, index_t n_bones, array_array_array_number_t base_relatives, array_number_t parents, array_array_array_number_t inverse_base_absolutes, array_array_number_t base_positions, array_array_number_t weights) {
	array_array_number_t pose_params = usecases_to_pose_params(param, n_bones);
	array_array_number_t vertex_positions = usecases_get_skinned_vertex_positions(is_mirrored, n_bones, pose_params, base_relatives, parents, inverse_base_absolutes, base_positions, weights);
	index_t n_corr = correspondences->length;
	index_t dims = 3;
	closure_t* closure237 = make_closure(lambda238, make_env_t_238(vertex_positions,points,n_corr,correspondences));
	array_number_t err = linalg_vectorMap(closure237, linalg_vectorRange(0, ((dims) * (n_corr)) - (1)));
	return err;
}
typedef struct env_t_266 {
	value_t dummy_variable;
} env_t_266;
env_t_266* make_env_t_266() {
	env_t_266* env = (env_t_266*)malloc(sizeof(env_t_266));
	
	return env;
}

value_t lambda266(env_t_266* env239, number_t r) {
	
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
	array_number_t array255 = (array_number_t)malloc(sizeof(int) * 2);
	array255->length=3;
	array255->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array255->arr[0] = 1;
	array255->arr[1] = 2;
	array255->arr[2] = 3;;
	array_number_t array256 = (array_number_t)malloc(sizeof(int) * 2);
	array256->length=3;
	array256->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array256->arr[0] = 4;
	array256->arr[1] = 5;
	array256->arr[2] = 6;;
	array_number_t array257 = (array_number_t)malloc(sizeof(int) * 2);
	array257->length=3;
	array257->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array257->arr[0] = 7;
	array257->arr[1] = 8;
	array257->arr[2] = 9;;
	array_array_number_t mat1 = (array_array_number_t)malloc(sizeof(int) * 2);
	mat1->length=3;
	mat1->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	mat1->arr[0] = array255;
	mat1->arr[1] = array256;
	mat1->arr[2] = array257;;
	array_array_number_t n = matrix_mult(mat1, mat1);
	matrix_print(n);
	array_array_number_t o = matrix_transpose(n);
	matrix_print(o);
	array_array_number_t p = linalg_matrixConcatCol(mat1, mat1);
	matrix_print(p);
	closure_t* closure241 = make_closure(lambda266, make_env_t_266());
	array_array_number_t base_rel = linalg_vectorMapToMatrix(closure241, linalg_vectorRange(1, 4));
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
