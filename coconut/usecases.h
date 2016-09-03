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
	array_number_t ite73 = 0;
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
		ite73 = linalg_add_vec(linalg_add_vec(v1, v2), linalg_mult_by_scalar(w, tmp));
	} else {
		
		ite73 = linalg_add_vec(x, linalg_cross(rot, x));
	}
	return ite73;
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
typedef empty_env_t env_t_77;


value_t lambda77(env_t_77* env74, number_t w) {
	
	value_t res;
	res.number_t_value = usecases_compute_zach_weight_error(w);
	return res;
}
array_number_t usecases_w_err(array_number_t w) {
	env_t_77 env_t_77_value = make_empty_env(); closure_t closure76 = make_closure(lambda77, &env_t_77_value);
	return linalg_vectorMap(closure76, w);
}
typedef struct env_t_88 {
	array_array_number_t x;
	array_number_t w;
	array_array_number_t obs;
	array_array_number_t feat;
	array_array_number_t cams;
} env_t_88;
env_t_88 make_env_t_88(array_array_number_t x,array_number_t w,array_array_number_t obs,array_array_number_t feat,array_array_number_t cams) {
	env_t_88 env;
	env.x = x;
	env.w = w;
	env.obs = obs;
	env.feat = feat;
	env.cams = cams;
	return env;
}

value_t lambda88(env_t_88* env85, number_t i) {
	array_array_number_t x84 = env85->x;
	array_number_t w83 = env85->w;
	array_array_number_t obs82 = env85->obs;
	array_array_number_t feat81 = env85->feat;
	array_array_number_t cams80 = env85->cams;
	value_t res;
	res.array_number_t_value = usecases_compute_reproj_err(cams80->arr[(int)(obs82->arr[(int)(i)]->arr[0])], x84->arr[(int)(obs82->arr[(int)(i)]->arr[1])], w83->arr[(int)(i)], feat81->arr[(int)(i)]);
	return res;
}
array_array_number_t usecases_reproj_err(array_array_number_t cams, array_array_number_t x, array_number_t w, array_array_number_t obs, array_array_number_t feat) {
	card_t macroDef78 = cams->length;
	card_t n = macroDef78;
	card_t macroDef79 = w->length;
	card_t p = macroDef79;
	array_number_t range = linalg_vectorRange(0, (p) - (1));
	env_t_88 env_t_88_value = make_env_t_88(x,w,obs,feat,cams); closure_t closure87 = make_closure(lambda88, &env_t_88_value);
	return linalg_vectorMapToMatrix(closure87, range);
}
typedef struct env_t_112 {
	array_number_t one_cam;
} env_t_112;
env_t_112 make_env_t_112(array_number_t one_cam) {
	env_t_112 env;
	env.one_cam = one_cam;
	return env;
}

value_t lambda112(env_t_112* env90, number_t x) {
	array_number_t one_cam89 = env90->one_cam;
	value_t res;
	res.array_number_t_value = one_cam89;
	return res;
}
typedef struct env_t_113 {
	array_number_t one_x;
} env_t_113;
env_t_113 make_env_t_113(array_number_t one_x) {
	env_t_113 env;
	env.one_x = one_x;
	return env;
}

value_t lambda113(env_t_113* env94, number_t x) {
	array_number_t one_x93 = env94->one_x;
	value_t res;
	res.array_number_t_value = one_x93;
	return res;
}
typedef struct env_t_114 {
	number_t one_w;
} env_t_114;
env_t_114 make_env_t_114(number_t one_w) {
	env_t_114 env;
	env.one_w = one_w;
	return env;
}

value_t lambda114(env_t_114* env98, number_t x) {
	number_t one_w97 = env98->one_w;
	value_t res;
	res.number_t_value = one_w97;
	return res;
}
typedef struct env_t_115 {
	array_number_t one_feat;
} env_t_115;
env_t_115 make_env_t_115(array_number_t one_feat) {
	env_t_115 env;
	env.one_feat = one_feat;
	return env;
}

value_t lambda115(env_t_115* env102, number_t x) {
	array_number_t one_feat101 = env102->one_feat;
	value_t res;
	res.array_number_t_value = one_feat101;
	return res;
}
typedef struct env_t_116 {
	card_t n;
	card_t m;
} env_t_116;
env_t_116 make_env_t_116(card_t n,card_t m) {
	env_t_116 env;
	env.n = n;
	env.m = m;
	return env;
}

value_t lambda116(env_t_116* env107, number_t x) {
	card_t n106 = env107->n;
	card_t m105 = env107->m;
	array_number_t array110 = (array_number_t)malloc(sizeof(int) * 2);
	array110->length=2;
	array110->arr = (number_t*)malloc(sizeof(number_t) * 2);
	array110->arr[0] = (double)(((int)(x)) % ((n106)));
	array110->arr[1] = (double)(((int)(x)) % ((m105)));;
	value_t res;
	res.array_number_t_value = array110;
	return res;
}
array_array_number_t usecases_run_ba_from_file(string_t fn) {
	array_number_t nmp = linalg_vectorRead(fn, 0);
	card_t n = (int)(nmp->arr[0]);
	card_t m = (int)(nmp->arr[1]);
	card_t p = (int)(nmp->arr[2]);
	card_t oneCard = 1;
	array_number_t one_cam = linalg_vectorRead(fn, 1);
	env_t_112 env_t_112_value = make_env_t_112(one_cam); closure_t closure92 = make_closure(lambda112, &env_t_112_value);
	array_array_number_t cam = linalg_vectorMapToMatrix(closure92, linalg_vectorRange(oneCard, n));
	array_number_t one_x = linalg_vectorRead(fn, 2);
	env_t_113 env_t_113_value = make_env_t_113(one_x); closure_t closure96 = make_closure(lambda113, &env_t_113_value);
	array_array_number_t x = linalg_vectorMapToMatrix(closure96, linalg_vectorRange(oneCard, m));
	number_t one_w = linalg_numberRead(fn, 3);
	env_t_114 env_t_114_value = make_env_t_114(one_w); closure_t closure100 = make_closure(lambda114, &env_t_114_value);
	array_number_t w = linalg_vectorMap(closure100, linalg_vectorRange(oneCard, p));
	array_number_t one_feat = linalg_vectorRead(fn, 4);
	env_t_115 env_t_115_value = make_env_t_115(one_feat); closure_t closure104 = make_closure(lambda115, &env_t_115_value);
	array_array_number_t feat = linalg_vectorMapToMatrix(closure104, linalg_vectorRange(oneCard, p));
	env_t_116 env_t_116_value = make_env_t_116(n,m); closure_t closure109 = make_closure(lambda116, &env_t_116_value);
	array_array_number_t obs = linalg_vectorMapToMatrix(closure109, linalg_vectorRange(0, (p) - (oneCard)));
	timer_t t = tic();
	array_array_number_t res = usecases_reproj_err(cam, x, w, obs, feat);
	toc(t);
	return res;
}
typedef struct env_t_121 {
	number_t mx;
} env_t_121;
env_t_121 make_env_t_121(number_t mx) {
	env_t_121 env;
	env.mx = mx;
	return env;
}

value_t lambda121(env_t_121* env118, number_t x) {
	number_t mx117 = env118->mx;
	value_t res;
	res.number_t_value = exp((x) - (mx117));
	return res;
}
number_t usecases_logsumexp(array_number_t arr) {
	number_t mx = linalg_arrayMax(arr);
	env_t_121 env_t_121_value = make_env_t_121(mx); closure_t closure120 = make_closure(lambda121, &env_t_121_value);
	number_t semx = linalg_arraySum(linalg_vectorMap(closure120, arr));
	return (log(semx)) + (mx);
}
typedef struct env_t_126 {
	number_t a;
} env_t_126;
env_t_126 make_env_t_126(number_t a) {
	env_t_126 env;
	env.a = a;
	return env;
}

value_t lambda126(env_t_126* env123, number_t j) {
	number_t a122 = env123->a;
	value_t res;
	res.number_t_value = (a122) + ((0.5) * ((1) - ((double)(j))));
	return res;
}
number_t usecases_log_gamma_distrib(number_t a, number_t p) {
	env_t_126 env_t_126_value = make_env_t_126(a); closure_t closure125 = make_closure(lambda126, &env_t_126_value);
	return (log(pow(3.14159265358979, (0.25) * ((p) * ((p) - (1)))))) + (linalg_arraySum(linalg_vectorMap(closure125, linalg_vectorRange(1, (int)(p)))));
}

array_array_number_t usecases_new_matrix_test(array_number_t dum) {
	array_number_t array127 = (array_number_t)malloc(sizeof(int) * 2);
	array127->length=3;
	array127->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array127->arr[0] = 0;
	array127->arr[1] = 0;
	array127->arr[2] = 0;;
	array_array_number_t res = (array_array_number_t)malloc(sizeof(int) * 2);
	res->length=1;
	res->arr = (array_number_t*)malloc(sizeof(array_number_t) * 1);
	res->arr[0] = array127;;
	return res;
}

array_array_number_t usecases_to_pose_params(array_number_t theta, card_t n_bones) {
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
	array_number_t array128 = (array_number_t)malloc(sizeof(int) * 2);
	array128->length=3;
	array128->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array128->arr[0] = theta->arr[i1];
	array128->arr[1] = theta->arr[(i1) + (1)];
	array128->arr[2] = 0;;
	array_number_t array129 = (array_number_t)malloc(sizeof(int) * 2);
	array129->length=3;
	array129->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array129->arr[0] = theta->arr[(i1) + (2)];
	array129->arr[1] = 0;
	array129->arr[2] = 0;;
	array_number_t array130 = (array_number_t)malloc(sizeof(int) * 2);
	array130->length=3;
	array130->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array130->arr[0] = theta->arr[(i1) + (3)];
	array130->arr[1] = 0;
	array130->arr[2] = 0;;
	array_number_t array131 = (array_number_t)malloc(sizeof(int) * 2);
	array131->length=3;
	array131->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array131->arr[0] = 0;
	array131->arr[1] = 0;
	array131->arr[2] = 0;;
	array_array_number_t finger1 = (array_array_number_t)malloc(sizeof(int) * 2);
	finger1->length=4;
	finger1->arr = (array_number_t*)malloc(sizeof(array_number_t) * 4);
	finger1->arr[0] = array128;
	finger1->arr[1] = array129;
	finger1->arr[2] = array130;
	finger1->arr[3] = array131;;
	index_t i2 = (i1) + (4);
	array_number_t array132 = (array_number_t)malloc(sizeof(int) * 2);
	array132->length=3;
	array132->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array132->arr[0] = theta->arr[i2];
	array132->arr[1] = theta->arr[(i2) + (1)];
	array132->arr[2] = 0;;
	array_number_t array133 = (array_number_t)malloc(sizeof(int) * 2);
	array133->length=3;
	array133->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array133->arr[0] = theta->arr[(i2) + (2)];
	array133->arr[1] = 0;
	array133->arr[2] = 0;;
	array_number_t array134 = (array_number_t)malloc(sizeof(int) * 2);
	array134->length=3;
	array134->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array134->arr[0] = theta->arr[(i2) + (3)];
	array134->arr[1] = 0;
	array134->arr[2] = 0;;
	array_number_t array135 = (array_number_t)malloc(sizeof(int) * 2);
	array135->length=3;
	array135->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array135->arr[0] = 0;
	array135->arr[1] = 0;
	array135->arr[2] = 0;;
	array_array_number_t finger2 = (array_array_number_t)malloc(sizeof(int) * 2);
	finger2->length=4;
	finger2->arr = (array_number_t*)malloc(sizeof(array_number_t) * 4);
	finger2->arr[0] = array132;
	finger2->arr[1] = array133;
	finger2->arr[2] = array134;
	finger2->arr[3] = array135;;
	index_t i3 = (i2) + (4);
	array_number_t array136 = (array_number_t)malloc(sizeof(int) * 2);
	array136->length=3;
	array136->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array136->arr[0] = theta->arr[i3];
	array136->arr[1] = theta->arr[(i3) + (1)];
	array136->arr[2] = 0;;
	array_number_t array137 = (array_number_t)malloc(sizeof(int) * 2);
	array137->length=3;
	array137->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array137->arr[0] = theta->arr[(i3) + (2)];
	array137->arr[1] = 0;
	array137->arr[2] = 0;;
	array_number_t array138 = (array_number_t)malloc(sizeof(int) * 2);
	array138->length=3;
	array138->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array138->arr[0] = theta->arr[(i3) + (3)];
	array138->arr[1] = 0;
	array138->arr[2] = 0;;
	array_number_t array139 = (array_number_t)malloc(sizeof(int) * 2);
	array139->length=3;
	array139->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array139->arr[0] = 0;
	array139->arr[1] = 0;
	array139->arr[2] = 0;;
	array_array_number_t finger3 = (array_array_number_t)malloc(sizeof(int) * 2);
	finger3->length=4;
	finger3->arr = (array_number_t*)malloc(sizeof(array_number_t) * 4);
	finger3->arr[0] = array136;
	finger3->arr[1] = array137;
	finger3->arr[2] = array138;
	finger3->arr[3] = array139;;
	index_t i4 = (i3) + (4);
	array_number_t array140 = (array_number_t)malloc(sizeof(int) * 2);
	array140->length=3;
	array140->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array140->arr[0] = theta->arr[i4];
	array140->arr[1] = theta->arr[(i4) + (1)];
	array140->arr[2] = 0;;
	array_number_t array141 = (array_number_t)malloc(sizeof(int) * 2);
	array141->length=3;
	array141->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array141->arr[0] = theta->arr[(i4) + (2)];
	array141->arr[1] = 0;
	array141->arr[2] = 0;;
	array_number_t array142 = (array_number_t)malloc(sizeof(int) * 2);
	array142->length=3;
	array142->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array142->arr[0] = theta->arr[(i4) + (3)];
	array142->arr[1] = 0;
	array142->arr[2] = 0;;
	array_number_t array143 = (array_number_t)malloc(sizeof(int) * 2);
	array143->length=3;
	array143->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array143->arr[0] = 0;
	array143->arr[1] = 0;
	array143->arr[2] = 0;;
	array_array_number_t finger4 = (array_array_number_t)malloc(sizeof(int) * 2);
	finger4->length=4;
	finger4->arr = (array_number_t*)malloc(sizeof(array_number_t) * 4);
	finger4->arr[0] = array140;
	finger4->arr[1] = array141;
	finger4->arr[2] = array142;
	finger4->arr[3] = array143;;
	index_t i5 = (i4) + (4);
	array_number_t array144 = (array_number_t)malloc(sizeof(int) * 2);
	array144->length=3;
	array144->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array144->arr[0] = theta->arr[i5];
	array144->arr[1] = theta->arr[(i5) + (1)];
	array144->arr[2] = 0;;
	array_number_t array145 = (array_number_t)malloc(sizeof(int) * 2);
	array145->length=3;
	array145->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array145->arr[0] = theta->arr[(i5) + (2)];
	array145->arr[1] = 0;
	array145->arr[2] = 0;;
	array_number_t array146 = (array_number_t)malloc(sizeof(int) * 2);
	array146->length=3;
	array146->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array146->arr[0] = theta->arr[(i5) + (3)];
	array146->arr[1] = 0;
	array146->arr[2] = 0;;
	array_number_t array147 = (array_number_t)malloc(sizeof(int) * 2);
	array147->length=3;
	array147->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array147->arr[0] = 0;
	array147->arr[1] = 0;
	array147->arr[2] = 0;;
	array_array_number_t finger5 = (array_array_number_t)malloc(sizeof(int) * 2);
	finger5->length=4;
	finger5->arr = (array_number_t*)malloc(sizeof(array_number_t) * 4);
	finger5->arr[0] = array144;
	finger5->arr[1] = array145;
	finger5->arr[2] = array146;
	finger5->arr[3] = array147;;
	return matrix_concat(pose_params, matrix_concat(finger1, matrix_concat(finger2, matrix_concat(finger3, matrix_concat(finger4, finger5)))));
}

array_array_number_t usecases_euler_angles_to_rotation_matrix(array_number_t xzy) {
	number_t tx = xzy->arr[0];
	number_t ty = xzy->arr[2];
	number_t tz = xzy->arr[1];
	array_number_t array148 = (array_number_t)malloc(sizeof(int) * 2);
	array148->length=3;
	array148->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array148->arr[0] = 1;
	array148->arr[1] = 0;
	array148->arr[2] = 0;;
	array_number_t array149 = (array_number_t)malloc(sizeof(int) * 2);
	array149->length=3;
	array149->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array149->arr[0] = 0;
	array149->arr[1] = cos(tx);
	array149->arr[2] = -(sin(tx));;
	array_number_t array150 = (array_number_t)malloc(sizeof(int) * 2);
	array150->length=3;
	array150->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array150->arr[0] = 0;
	array150->arr[1] = sin(tx);
	array150->arr[2] = cos(tx);;
	array_array_number_t Rx = (array_array_number_t)malloc(sizeof(int) * 2);
	Rx->length=3;
	Rx->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	Rx->arr[0] = array148;
	Rx->arr[1] = array149;
	Rx->arr[2] = array150;;
	array_number_t array151 = (array_number_t)malloc(sizeof(int) * 2);
	array151->length=3;
	array151->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array151->arr[0] = cos(ty);
	array151->arr[1] = 0;
	array151->arr[2] = sin(ty);;
	array_number_t array152 = (array_number_t)malloc(sizeof(int) * 2);
	array152->length=3;
	array152->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array152->arr[0] = 0;
	array152->arr[1] = 1;
	array152->arr[2] = 0;;
	array_number_t array153 = (array_number_t)malloc(sizeof(int) * 2);
	array153->length=3;
	array153->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array153->arr[0] = -(sin(ty));
	array153->arr[1] = 0;
	array153->arr[2] = cos(ty);;
	array_array_number_t Ry = (array_array_number_t)malloc(sizeof(int) * 2);
	Ry->length=3;
	Ry->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	Ry->arr[0] = array151;
	Ry->arr[1] = array152;
	Ry->arr[2] = array153;;
	array_number_t array154 = (array_number_t)malloc(sizeof(int) * 2);
	array154->length=3;
	array154->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array154->arr[0] = cos(tz);
	array154->arr[1] = -(sin(tz));
	array154->arr[2] = 0;;
	array_number_t array155 = (array_number_t)malloc(sizeof(int) * 2);
	array155->length=3;
	array155->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array155->arr[0] = sin(tz);
	array155->arr[1] = cos(tz);
	array155->arr[2] = 0;;
	array_number_t array156 = (array_number_t)malloc(sizeof(int) * 2);
	array156->length=3;
	array156->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array156->arr[0] = 0;
	array156->arr[1] = 0;
	array156->arr[2] = 1;;
	array_array_number_t Rz = (array_array_number_t)malloc(sizeof(int) * 2);
	Rz->length=3;
	Rz->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	Rz->arr[0] = array154;
	Rz->arr[1] = array155;
	Rz->arr[2] = array156;;
	return matrix_mult(Rz, matrix_mult(Ry, Rx));
}

array_array_number_t usecases_make_relative(array_number_t pose_params, array_array_number_t base_relative) {
	array_array_number_t R = usecases_euler_angles_to_rotation_matrix(pose_params);
	array_number_t array157 = (array_number_t)malloc(sizeof(int) * 2);
	array157->length=1;
	array157->arr = (number_t*)malloc(sizeof(number_t) * 1);
	array157->arr[0] = 0;;
	array_number_t array158 = (array_number_t)malloc(sizeof(int) * 2);
	array158->length=1;
	array158->arr = (number_t*)malloc(sizeof(number_t) * 1);
	array158->arr[0] = 0;;
	array_number_t array159 = (array_number_t)malloc(sizeof(int) * 2);
	array159->length=1;
	array159->arr = (number_t*)malloc(sizeof(number_t) * 1);
	array159->arr[0] = 0;;
	array_array_number_t r1 = (array_array_number_t)malloc(sizeof(int) * 2);
	r1->length=3;
	r1->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	r1->arr[0] = array157;
	r1->arr[1] = array158;
	r1->arr[2] = array159;;
	array_number_t array160 = (array_number_t)malloc(sizeof(int) * 2);
	array160->length=4;
	array160->arr = (number_t*)malloc(sizeof(number_t) * 4);
	array160->arr[0] = 0;
	array160->arr[1] = 0;
	array160->arr[2] = 0;
	array160->arr[3] = 1;;
	array_array_number_t r2 = (array_array_number_t)malloc(sizeof(int) * 2);
	r2->length=1;
	r2->arr = (array_number_t*)malloc(sizeof(array_number_t) * 1);
	r2->arr[0] = array160;;
	array_array_number_t T = matrix_concat(linalg_matrixConcatCol(R, r1), r2);
	return matrix_mult(base_relative, T);
}
typedef struct env_t_167 {
	array_array_number_t pose_params;
	index_t offset;
	array_array_array_number_t base_relatives;
} env_t_167;
env_t_167 make_env_t_167(array_array_number_t pose_params,index_t offset,array_array_array_number_t base_relatives) {
	env_t_167 env;
	env.pose_params = pose_params;
	env.offset = offset;
	env.base_relatives = base_relatives;
	return env;
}

value_t lambda167(env_t_167* env164, number_t i_bone) {
	array_array_number_t pose_params163 = env164->pose_params;
	index_t offset162 = env164->offset;
	array_array_array_number_t base_relatives161 = env164->base_relatives;
	value_t res;
	res.array_array_number_t_value = usecases_make_relative(pose_params163->arr[((int)(i_bone)) + (offset162)], base_relatives161->arr[(int)(i_bone)]);
	return res;
}
array_array_array_number_t usecases_get_posed_relatives(card_t n_bones, array_array_number_t pose_params, array_array_array_number_t base_relatives) {
	index_t offset = 3;
	env_t_167 env_t_167_value = make_env_t_167(pose_params,offset,base_relatives); closure_t closure166 = make_closure(lambda167, &env_t_167_value);
	return linalg_vectorMapToMatrix3D(closure166, linalg_vectorRange(0, (n_bones) - (1)));
}

array_array_number_t usecases_angle_axis_to_rotation_matrix(array_number_t angle_axis) {
	number_t n = sqrt(linalg_sqnorm(angle_axis));
	array_array_number_t ite168 = 0;
	if((n) < (0.0001)) {
		array_number_t array170 = (array_number_t)malloc(sizeof(int) * 2);
	array170->length=3;
	array170->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array170->arr[0] = 1;
	array170->arr[1] = 0;
	array170->arr[2] = 0;;
		array_number_t array171 = (array_number_t)malloc(sizeof(int) * 2);
	array171->length=3;
	array171->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array171->arr[0] = 0;
	array171->arr[1] = 1;
	array171->arr[2] = 0;;
		array_number_t array172 = (array_number_t)malloc(sizeof(int) * 2);
	array172->length=3;
	array172->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array172->arr[0] = 0;
	array172->arr[1] = 0;
	array172->arr[2] = 1;;
		array_array_number_t array169 = (array_array_number_t)malloc(sizeof(int) * 2);
	array169->length=3;
	array169->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	array169->arr[0] = array170;
	array169->arr[1] = array171;
	array169->arr[2] = array172;;
		ite168 = array169;
	} else {
		number_t x = (angle_axis->arr[0]) / (n);
		number_t y = (angle_axis->arr[1]) / (n);
		number_t z = (angle_axis->arr[2]) / (n);
		number_t s = sin(n);
		number_t c = cos(n);
		array_number_t array174 = (array_number_t)malloc(sizeof(int) * 2);
	array174->length=3;
	array174->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array174->arr[0] = ((x) * (x)) + (((1) - ((x) * (x))) * (c));
	array174->arr[1] = (((x) * (y)) * ((1) - (c))) - ((z) * (s));
	array174->arr[2] = (((x) * (z)) * ((1) - (c))) + ((y) * (s));;
		array_number_t array175 = (array_number_t)malloc(sizeof(int) * 2);
	array175->length=3;
	array175->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array175->arr[0] = (((x) * (y)) * ((1) - (c))) + ((z) * (s));
	array175->arr[1] = ((y) * (y)) + (((1) - ((y) * (y))) * (c));
	array175->arr[2] = (((y) * (z)) * ((1) - (c))) - ((x) * (s));;
		array_number_t array176 = (array_number_t)malloc(sizeof(int) * 2);
	array176->length=3;
	array176->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array176->arr[0] = (((x) * (z)) * ((1) - (c))) - ((y) * (s));
	array176->arr[1] = (((z) * (y)) * ((1) - (c))) + ((x) * (s));
	array176->arr[2] = ((z) * (z)) + (((1) - ((z) * (z))) * (c));;
		array_array_number_t array173 = (array_array_number_t)malloc(sizeof(int) * 2);
	array173->length=3;
	array173->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	array173->arr[0] = array174;
	array173->arr[1] = array175;
	array173->arr[2] = array176;;
		ite168 = array173;
	}
	return ite168;
}
typedef struct env_t_186 {
	array_array_array_number_t relatives;
	array_number_t parents;
} env_t_186;
env_t_186 make_env_t_186(array_array_array_number_t relatives,array_number_t parents) {
	env_t_186 env;
	env.relatives = relatives;
	env.parents = parents;
	return env;
}

value_t lambda186(env_t_186* env179, array_array_array_number_t acc, index_t i) {
	array_array_array_number_t relatives178 = env179->relatives;
	array_number_t parents177 = env179->parents;
	array_array_array_number_t ite185 = 0;
	if((parents177->arr[i]) == (-1)) {
		array_array_array_number_t newMatrix = (array_array_array_number_t)malloc(sizeof(int) * 2);
	newMatrix->length=1;
	newMatrix->arr = (array_array_number_t*)malloc(sizeof(array_array_number_t) * 1);
	newMatrix->arr[0] = relatives178->arr[i];;
		ite185 = matrix3d_concat(acc, newMatrix);
	} else {
		array_array_array_number_t newMatrix = (array_array_array_number_t)malloc(sizeof(int) * 2);
	newMatrix->length=1;
	newMatrix->arr = (array_array_number_t*)malloc(sizeof(array_array_number_t) * 1);
	newMatrix->arr[0] = matrix_mult(acc->arr[(int)(parents177->arr[i])], relatives178->arr[i]);;
		ite185 = matrix3d_concat(acc, newMatrix);
	}
	value_t res;
	res.array_array_array_number_t_value = ite185;
	return res;
}
array_array_array_number_t usecases_relatives_to_absolutes(array_array_array_number_t relatives, array_number_t parents) {
	array_number_t array184 = (array_number_t)malloc(sizeof(int) * 2);
	array184->length=0;
	array184->arr = (number_t*)malloc(sizeof(number_t) * 0);
	;
	array_array_number_t array183 = (array_array_number_t)malloc(sizeof(int) * 2);
	array183->length=1;
	array183->arr = (array_number_t*)malloc(sizeof(array_number_t) * 1);
	array183->arr[0] = array184;;
	array_array_array_number_t init = (array_array_array_number_t)malloc(sizeof(int) * 2);
	init->length=1;
	init->arr = (array_array_number_t*)malloc(sizeof(array_array_number_t) * 1);
	init->arr[0] = array183;;
	env_t_186 env_t_186_value = make_env_t_186(relatives,parents); closure_t closure181 = make_closure(lambda186, &env_t_186_value);
	card_t macroDef182 = relatives->length;
	return linalg_iterateMatrix3D(closure181, init, 0, (macroDef182) - (1));
}
typedef struct env_t_197 {
	array_number_t scale;
} env_t_197;
env_t_197 make_env_t_197(array_number_t scale) {
	env_t_197 env;
	env.scale = scale;
	return env;
}

value_t lambda197(env_t_197* env188, array_number_t row) {
	array_number_t scale187 = env188->scale;
	value_t res;
	res.array_number_t_value = linalg_mult_vec_elementwise(row, scale187);
	return res;
}
typedef empty_env_t env_t_198;


value_t lambda198(env_t_198* env191, number_t x) {
	
	value_t res;
	res.number_t_value = 1;
	return res;
}
array_array_number_t usecases_apply_global_transform(array_array_number_t pose_params, array_array_number_t positions) {
	array_array_number_t R = usecases_angle_axis_to_rotation_matrix(pose_params->arr[0]);
	array_number_t scale = pose_params->arr[1];
	env_t_197 env_t_197_value = make_env_t_197(scale); closure_t closure190 = make_closure(lambda197, &env_t_197_value);
	array_array_number_t R1 = linalg_matrixMap(closure190, R);
	array_array_number_t array195 = (array_array_number_t)malloc(sizeof(int) * 2);
	array195->length=1;
	array195->arr = (array_number_t*)malloc(sizeof(array_number_t) * 1);
	array195->arr[0] = pose_params->arr[2];;
	array_array_number_t T = linalg_matrixConcatCol(R1, matrix_transpose(array195));
	env_t_198 env_t_198_value = make_empty_env(); closure_t closure193 = make_closure(lambda198, &env_t_198_value);
	card_t macroDef194 = positions->arr[0]->length;
	array_number_t ones = linalg_vectorMap(closure193, linalg_vectorRange(1, macroDef194));
	array_array_number_t array196 = (array_array_number_t)malloc(sizeof(int) * 2);
	array196->length=1;
	array196->arr = (array_number_t*)malloc(sizeof(array_number_t) * 1);
	array196->arr[0] = ones;;
	array_array_number_t positions_homog = matrix_concat(positions, array196);
	return matrix_mult(T, positions_homog);
}
typedef empty_env_t env_t_214;


value_t lambda214(env_t_214* env199, array_array_number_t m1, array_array_number_t m2) {
	
	value_t res;
	res.array_array_number_t_value = matrix_mult(m1, m2);
	return res;
}
typedef struct env_t_215 {
	array_array_number_t weights;
	array_array_array_number_t transforms;
	array_array_number_t base_positions;
} env_t_215;
env_t_215 make_env_t_215(array_array_number_t weights,array_array_array_number_t transforms,array_array_number_t base_positions) {
	env_t_215 env;
	env.weights = weights;
	env.transforms = transforms;
	env.base_positions = base_positions;
	return env;
}

value_t lambda215(env_t_215* env207, array_array_number_t acc, index_t i_transform) {
	array_array_number_t weights206 = env207->weights;
	array_array_array_number_t transforms205 = env207->transforms;
	array_array_number_t base_positions204 = env207->base_positions;
	array_array_number_t curr_positions = matrix_mult(matrix_slice(transforms205->arr[i_transform], 0, 2), base_positions204);
	card_t macroDef203 = base_positions204->length;
	array_array_number_t w = linalg_matrixFillFromVector(macroDef203, weights206->arr[i_transform]);
	value_t res;
	res.array_array_number_t_value = linalg_matrixAdd(acc, linalg_matrixMultElementwise(curr_positions, w));
	return res;
}
array_array_number_t usecases_get_skinned_vertex_positions(index_t is_mirrored, card_t n_bones, array_array_number_t pose_params, array_array_array_number_t base_relatives, array_number_t parents, array_array_array_number_t inverse_base_absolutes, array_array_number_t base_positions, array_array_number_t weights) {
	array_array_array_number_t relatives = usecases_get_posed_relatives(n_bones, pose_params, base_relatives);
	array_array_array_number_t absolutes = usecases_relatives_to_absolutes(relatives, parents);
	env_t_214 env_t_214_value = make_empty_env(); closure_t closure201 = make_closure(lambda214, &env_t_214_value);
	array_array_array_number_t transforms = linalg_matrix3DMap2(closure201, absolutes, inverse_base_absolutes);
	card_t macroDef202 = base_positions->arr[0]->length;
	card_t n_verts = macroDef202;
	array_array_number_t init_positions = linalg_matrixFill(3, n_verts, 0);
	env_t_215 env_t_215_value = make_env_t_215(weights,transforms,base_positions); closure_t closure209 = make_closure(lambda215, &env_t_215_value);
	card_t macroDef210 = transforms->length;
	array_array_number_t positions = linalg_iterateMatrix(closure209, init_positions, 0, (macroDef210) - (1));
	array_array_number_t mirrored_positions = 0;
	if((is_mirrored) == (1)) {
		array_number_t array211 = (array_number_t)malloc(sizeof(int) * 2);
	array211->length=3;
	array211->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array211->arr[0] = -1;
	array211->arr[1] = 0;
	array211->arr[2] = 0;;
		array_number_t array212 = (array_number_t)malloc(sizeof(int) * 2);
	array212->length=3;
	array212->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array212->arr[0] = 0;
	array212->arr[1] = 1;
	array212->arr[2] = 0;;
		array_number_t array213 = (array_number_t)malloc(sizeof(int) * 2);
	array213->length=3;
	array213->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array213->arr[0] = 0;
	array213->arr[1] = 0;
	array213->arr[2] = 1;;
		array_array_number_t mirror_matrix = (array_array_number_t)malloc(sizeof(int) * 2);
	mirror_matrix->length=3;
	mirror_matrix->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	mirror_matrix->arr[0] = array211;
	mirror_matrix->arr[1] = array212;
	mirror_matrix->arr[2] = array213;;
		mirrored_positions = matrix_mult(mirror_matrix, positions);
	} else {
		
		mirrored_positions = positions;
	}
	return usecases_apply_global_transform(pose_params, mirrored_positions);
}
typedef struct env_t_223 {
	array_array_number_t vertex_positions;
	array_array_number_t points;
	index_t n_corr;
	array_number_t correspondences;
} env_t_223;
env_t_223 make_env_t_223(array_array_number_t vertex_positions,array_array_number_t points,index_t n_corr,array_number_t correspondences) {
	env_t_223 env;
	env.vertex_positions = vertex_positions;
	env.points = points;
	env.n_corr = n_corr;
	env.correspondences = correspondences;
	return env;
}

value_t lambda223(env_t_223* env220, number_t i) {
	array_array_number_t vertex_positions219 = env220->vertex_positions;
	array_array_number_t points218 = env220->points;
	index_t n_corr217 = env220->n_corr;
	array_number_t correspondences216 = env220->correspondences;
	index_t ind = (int)(i);
	index_t r = (ind) / (n_corr217);
	index_t c = (ind) % (n_corr217);
	value_t res;
	res.number_t_value = (points218->arr[r]->arr[c]) - (vertex_positions219->arr[r]->arr[(int)(correspondences216->arr[c])]);
	return res;
}
array_number_t usecases_hand_objective(index_t is_mirrored, array_number_t param, array_number_t correspondences, array_array_number_t points, card_t n_bones, array_array_array_number_t base_relatives, array_number_t parents, array_array_array_number_t inverse_base_absolutes, array_array_number_t base_positions, array_array_number_t weights) {
	array_array_number_t pose_params = usecases_to_pose_params(param, n_bones);
	array_array_number_t vertex_positions = usecases_get_skinned_vertex_positions(is_mirrored, n_bones, pose_params, base_relatives, parents, inverse_base_absolutes, base_positions, weights);
	index_t n_corr = correspondences->length;
	index_t dims = 3;
	env_t_223 env_t_223_value = make_env_t_223(vertex_positions,points,n_corr,correspondences); closure_t closure222 = make_closure(lambda223, &env_t_223_value);
	array_number_t err = linalg_vectorMap(closure222, linalg_vectorRange(0, ((dims) * (n_corr)) - (1)));
	return err;
}
typedef empty_env_t env_t_251;


value_t lambda251(env_t_251* env224, number_t r) {
	
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
	array_number_t array240 = (array_number_t)malloc(sizeof(int) * 2);
	array240->length=3;
	array240->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array240->arr[0] = 1;
	array240->arr[1] = 2;
	array240->arr[2] = 3;;
	array_number_t array241 = (array_number_t)malloc(sizeof(int) * 2);
	array241->length=3;
	array241->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array241->arr[0] = 4;
	array241->arr[1] = 5;
	array241->arr[2] = 6;;
	array_number_t array242 = (array_number_t)malloc(sizeof(int) * 2);
	array242->length=3;
	array242->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array242->arr[0] = 7;
	array242->arr[1] = 8;
	array242->arr[2] = 9;;
	array_array_number_t mat1 = (array_array_number_t)malloc(sizeof(int) * 2);
	mat1->length=3;
	mat1->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	mat1->arr[0] = array240;
	mat1->arr[1] = array241;
	mat1->arr[2] = array242;;
	array_array_number_t n = matrix_mult(mat1, mat1);
	matrix_print(n);
	array_array_number_t o = matrix_transpose(n);
	matrix_print(o);
	array_array_number_t p = linalg_matrixConcatCol(mat1, mat1);
	matrix_print(p);
	env_t_251 env_t_251_value = make_empty_env(); closure_t closure226 = make_closure(lambda251, &env_t_251_value);
	array_array_number_t base_rel = linalg_vectorMapToMatrix(closure226, linalg_vectorRange(1, 4));
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
