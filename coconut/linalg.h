#include "runtime/fsharp.h"
#include <stdio.h>
#include <math.h>

typedef struct env_t_5 {
	number_t y;
} env_t_5;
env_t_5* make_env_t_5(number_t y) {
	env_t_5* env = (env_t_5*)malloc(sizeof(env_t_5));
	env->y = y;
	return env;
}

value_t lambda5(env_t_5* env2, number_t a) {
	number_t y1 = env2->y;
	value_t res;
	res.number_t_value = (a) * (y1);
	return res;
}
array_number_t linalg_mult_by_scalar(array_number_t x, number_t y) {
	closure_t* closure4 = make_closure(lambda5, make_env_t_5(y));
	return array_map(closure4, x);
}

array_number_t linalg_cross(array_number_t a, array_number_t b) {
	array_number_t array6 = (array_number_t)malloc(sizeof(int) * 2);
	array6->length=3;
	array6->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array6->arr[0] = ((a->arr[1]) * (b->arr[2])) - ((a->arr[2]) * (b->arr[1]));
	array6->arr[1] = ((a->arr[2]) * (b->arr[0])) - ((a->arr[0]) * (b->arr[2]));
	array6->arr[2] = ((a->arr[0]) * (b->arr[1])) - ((a->arr[1]) * (b->arr[0]));;
	return array6;
}
typedef struct env_t_10 {
	value_t dummy_variable;
} env_t_10;
env_t_10* make_env_t_10() {
	env_t_10* env = (env_t_10*)malloc(sizeof(env_t_10));
	
	return env;
}

value_t lambda10(env_t_10* env7, number_t x, number_t y) {
	
	value_t res;
	res.number_t_value = (x) + (y);
	return res;
}
array_number_t linalg_add_vec(array_number_t x, array_number_t y) {
	closure_t* closure9 = make_closure(lambda10, make_env_t_10());
	return array_map2(closure9, x, y);
}
typedef struct env_t_14 {
	value_t dummy_variable;
} env_t_14;
env_t_14* make_env_t_14() {
	env_t_14* env = (env_t_14*)malloc(sizeof(env_t_14));
	
	return env;
}

value_t lambda14(env_t_14* env11, number_t x, number_t y) {
	
	value_t res;
	res.number_t_value = (x) * (y);
	return res;
}
array_number_t linalg_mult_vec_elementwise(array_number_t x, array_number_t y) {
	closure_t* closure13 = make_closure(lambda14, make_env_t_14());
	return array_map2(closure13, x, y);
}

array_number_t linalg_add_vec3(array_number_t x, array_number_t y, array_number_t z) {
	
	return linalg_add_vec(linalg_add_vec(x, y), z);
}
typedef struct env_t_18 {
	value_t dummy_variable;
} env_t_18;
env_t_18* make_env_t_18() {
	env_t_18* env = (env_t_18*)malloc(sizeof(env_t_18));
	
	return env;
}

value_t lambda18(env_t_18* env15, number_t x, number_t y) {
	
	value_t res;
	res.number_t_value = (x) - (y);
	return res;
}
array_number_t linalg_sub_vec(array_number_t x, array_number_t y) {
	closure_t* closure17 = make_closure(lambda18, make_env_t_18());
	return array_map2(closure17, x, y);
}
typedef struct env_t_22 {
	value_t dummy_variable;
} env_t_22;
env_t_22* make_env_t_22() {
	env_t_22* env = (env_t_22*)malloc(sizeof(env_t_22));
	
	return env;
}

value_t lambda22(env_t_22* env19, number_t x1) {
	
	value_t res;
	res.number_t_value = (x1) * (x1);
	return res;
}
number_t linalg_sqnorm(array_number_t x) {
	closure_t* closure21 = make_closure(lambda22, make_env_t_22());
	return array_sum(array_map(closure21, x));
}
typedef struct env_t_26 {
	value_t dummy_variable;
} env_t_26;
env_t_26* make_env_t_26() {
	env_t_26* env = (env_t_26*)malloc(sizeof(env_t_26));
	
	return env;
}

value_t lambda26(env_t_26* env23, number_t x, number_t y) {
	
	value_t res;
	res.number_t_value = (x) * (y);
	return res;
}
number_t linalg_dot_prod(array_number_t x, array_number_t y) {
	closure_t* closure25 = make_closure(lambda26, make_env_t_26());
	return array_sum(array_map2(closure25, x, y));
}
typedef struct env_t_35 {
	number_t value;
} env_t_35;
env_t_35* make_env_t_35(number_t value) {
	env_t_35* env = (env_t_35*)malloc(sizeof(env_t_35));
	env->value = value;
	return env;
}

value_t lambda35(env_t_35* env28, number_t c) {
	number_t value27 = env28->value;
	value_t res;
	res.number_t_value = value27;
	return res;
}
typedef struct env_t_36 {
	array_number_t row;
} env_t_36;
env_t_36* make_env_t_36(array_number_t row) {
	env_t_36* env = (env_t_36*)malloc(sizeof(env_t_36));
	env->row = row;
	return env;
}

value_t lambda36(env_t_36* env32, number_t r) {
	array_number_t row31 = env32->row;
	value_t res;
	res.array_number_t_value = row31;
	return res;
}
array_array_number_t linalg_matrixFill(index_t rows, index_t cols, number_t value) {
	closure_t* closure30 = make_closure(lambda35, make_env_t_35(value));
	array_number_t row = array_map(closure30, array_range(1, cols));
	closure_t* closure34 = make_closure(lambda36, make_env_t_36(row));
	return array_map_to_matrix(closure34, array_range(1, rows));
}

array_number_t linalg_radial_distort(array_number_t rad_params, array_number_t proj) {
	number_t rsq = linalg_sqnorm(proj);
	number_t L = ((1) + ((rad_params->arr[0]) * (rsq))) + (((rad_params->arr[1]) * (rsq)) * (rsq));
	return linalg_mult_by_scalar(proj, L);
}

array_number_t linalg_rodrigues_rotate_point(array_number_t rot, array_number_t x) {
	number_t sqtheta = linalg_sqnorm(rot);
	array_number_t ite37 = NULL;
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
		ite37 = linalg_add_vec(linalg_add_vec(v1, v2), linalg_mult_by_scalar(w, tmp));
	} else {
		
		ite37 = linalg_add_vec(x, linalg_cross(rot, x));
	}
	return ite37;
}

array_number_t linalg_project(array_number_t cam, array_number_t x) {
	index_t N_CAM_PARAMS = 11;
	index_t ROT_IDX = 0;
	index_t CENTER_IDX = 3;
	index_t FOCAL_IDX = 6;
	index_t X0_IDX = 7;
	index_t RAD_IDX = 9;
	array_number_t Xcam = linalg_rodrigues_rotate_point(array_slice(cam, ROT_IDX, (ROT_IDX) + (2)), linalg_sub_vec(x, array_slice(cam, CENTER_IDX, (CENTER_IDX) + (2))));
	array_number_t distorted = linalg_radial_distort(array_slice(cam, RAD_IDX, (RAD_IDX) + (1)), linalg_mult_by_scalar(array_slice(Xcam, 0, 1), (1) / (Xcam->arr[2])));
	return linalg_add_vec(array_slice(cam, X0_IDX, (X0_IDX) + (1)), linalg_mult_by_scalar(distorted, cam->arr[FOCAL_IDX]));
}

array_number_t linalg_compute_reproj_err(array_number_t cam, array_number_t x, number_t w, array_number_t feat) {
	
	return linalg_mult_by_scalar(linalg_sub_vec(linalg_project(cam, x), feat), w);
}

number_t linalg_compute_zach_weight_error(number_t w) {
	
	return (1) - ((w) * (w));
}
typedef struct env_t_41 {
	value_t dummy_variable;
} env_t_41;
env_t_41* make_env_t_41() {
	env_t_41* env = (env_t_41*)malloc(sizeof(env_t_41));
	
	return env;
}

value_t lambda41(env_t_41* env38, number_t w) {
	
	value_t res;
	res.number_t_value = linalg_compute_zach_weight_error(w);
	return res;
}
array_number_t linalg_w_err(array_number_t w) {
	closure_t* closure40 = make_closure(lambda41, make_env_t_41());
	return array_map(closure40, w);
}
typedef struct env_t_50 {
	array_array_number_t x;
	array_number_t w;
	array_array_number_t obs;
	array_array_number_t feat;
	array_array_number_t cams;
} env_t_50;
env_t_50* make_env_t_50(array_array_number_t x,array_number_t w,array_array_number_t obs,array_array_number_t feat,array_array_number_t cams) {
	env_t_50* env = (env_t_50*)malloc(sizeof(env_t_50));
	env->x = x;
	env->w = w;
	env->obs = obs;
	env->feat = feat;
	env->cams = cams;
	return env;
}

value_t lambda50(env_t_50* env47, number_t i) {
	array_array_number_t x46 = env47->x;
	array_number_t w45 = env47->w;
	array_array_number_t obs44 = env47->obs;
	array_array_number_t feat43 = env47->feat;
	array_array_number_t cams42 = env47->cams;
	value_t res;
	res.array_number_t_value = linalg_compute_reproj_err(cams42->arr[(int)(obs44->arr[(int)(i)]->arr[0])], x46->arr[(int)(obs44->arr[(int)(i)]->arr[1])], w45->arr[(int)(i)], feat43->arr[(int)(i)]);
	return res;
}
array_array_number_t linalg_reproj_err(array_array_number_t cams, array_array_number_t x, array_number_t w, array_array_number_t obs, array_array_number_t feat) {
	index_t n = cams->length;
	index_t p = w->length;
	array_number_t range = array_range(0, (p) - (1));
	closure_t* closure49 = make_closure(lambda50, make_env_t_50(x,w,obs,feat,cams));
	return array_map_to_matrix(closure49, range);
}

array_number_t linalg_vectorRead(string_t fn, index_t startLine) {
	array_array_number_t matrix = matrix_read(fn, startLine, 1);
	return matrix->arr[0];
}

number_t linalg_numberRead(string_t fn, index_t startLine) {
	array_number_t vector = linalg_vectorRead(fn, startLine);
	return vector->arr[0];
}
typedef struct env_t_74 {
	array_number_t one_cam;
} env_t_74;
env_t_74* make_env_t_74(array_number_t one_cam) {
	env_t_74* env = (env_t_74*)malloc(sizeof(env_t_74));
	env->one_cam = one_cam;
	return env;
}

value_t lambda74(env_t_74* env52, number_t x) {
	array_number_t one_cam51 = env52->one_cam;
	value_t res;
	res.array_number_t_value = one_cam51;
	return res;
}
typedef struct env_t_75 {
	array_number_t one_x;
} env_t_75;
env_t_75* make_env_t_75(array_number_t one_x) {
	env_t_75* env = (env_t_75*)malloc(sizeof(env_t_75));
	env->one_x = one_x;
	return env;
}

value_t lambda75(env_t_75* env56, number_t x) {
	array_number_t one_x55 = env56->one_x;
	value_t res;
	res.array_number_t_value = one_x55;
	return res;
}
typedef struct env_t_76 {
	number_t one_w;
} env_t_76;
env_t_76* make_env_t_76(number_t one_w) {
	env_t_76* env = (env_t_76*)malloc(sizeof(env_t_76));
	env->one_w = one_w;
	return env;
}

value_t lambda76(env_t_76* env60, number_t x) {
	number_t one_w59 = env60->one_w;
	value_t res;
	res.number_t_value = one_w59;
	return res;
}
typedef struct env_t_77 {
	array_number_t one_feat;
} env_t_77;
env_t_77* make_env_t_77(array_number_t one_feat) {
	env_t_77* env = (env_t_77*)malloc(sizeof(env_t_77));
	env->one_feat = one_feat;
	return env;
}

value_t lambda77(env_t_77* env64, number_t x) {
	array_number_t one_feat63 = env64->one_feat;
	value_t res;
	res.array_number_t_value = one_feat63;
	return res;
}
typedef struct env_t_78 {
	index_t n;
	index_t m;
} env_t_78;
env_t_78* make_env_t_78(index_t n,index_t m) {
	env_t_78* env = (env_t_78*)malloc(sizeof(env_t_78));
	env->n = n;
	env->m = m;
	return env;
}

value_t lambda78(env_t_78* env69, number_t x) {
	index_t n68 = env69->n;
	index_t m67 = env69->m;
	array_number_t array72 = (array_number_t)malloc(sizeof(int) * 2);
	array72->length=2;
	array72->arr = (number_t*)malloc(sizeof(number_t) * 2);
	array72->arr[0] = (double)(((int)(x)) % (n68));
	array72->arr[1] = (double)(((int)(x)) % (m67));;
	value_t res;
	res.array_number_t_value = array72;
	return res;
}
array_array_number_t linalg_run_ba_from_file(string_t fn) {
	array_number_t nmp = linalg_vectorRead(fn, 0);
	index_t n = (int)(nmp->arr[0]);
	index_t m = (int)(nmp->arr[1]);
	index_t p = (int)(nmp->arr[2]);
	array_number_t one_cam = linalg_vectorRead(fn, 1);
	closure_t* closure54 = make_closure(lambda74, make_env_t_74(one_cam));
	array_array_number_t cam = array_map_to_matrix(closure54, array_range(1, n));
	array_number_t one_x = linalg_vectorRead(fn, 2);
	closure_t* closure58 = make_closure(lambda75, make_env_t_75(one_x));
	array_array_number_t x = array_map_to_matrix(closure58, array_range(1, m));
	number_t one_w = linalg_numberRead(fn, 3);
	closure_t* closure62 = make_closure(lambda76, make_env_t_76(one_w));
	array_number_t w = array_map(closure62, array_range(1, p));
	array_number_t one_feat = linalg_vectorRead(fn, 4);
	closure_t* closure66 = make_closure(lambda77, make_env_t_77(one_feat));
	array_array_number_t feat = array_map_to_matrix(closure66, array_range(1, p));
	closure_t* closure71 = make_closure(lambda78, make_env_t_78(n,m));
	array_array_number_t obs = array_map_to_matrix(closure71, array_range(0, (p) - (1)));
	timer_t t = tic();
	array_array_number_t res = linalg_reproj_err(cam, x, w, obs, feat);
	toc(t);
	return res;
}
typedef struct env_t_83 {
	number_t mx;
} env_t_83;
env_t_83* make_env_t_83(number_t mx) {
	env_t_83* env = (env_t_83*)malloc(sizeof(env_t_83));
	env->mx = mx;
	return env;
}

value_t lambda83(env_t_83* env80, number_t x) {
	number_t mx79 = env80->mx;
	value_t res;
	res.number_t_value = exp((x) - (mx79));
	return res;
}
number_t linalg_logsumexp(array_number_t arr) {
	number_t mx = array_max(arr);
	closure_t* closure82 = make_closure(lambda83, make_env_t_83(mx));
	number_t semx = array_sum(array_map(closure82, arr));
	return (log(semx)) + (mx);
}
typedef struct env_t_88 {
	number_t a;
} env_t_88;
env_t_88* make_env_t_88(number_t a) {
	env_t_88* env = (env_t_88*)malloc(sizeof(env_t_88));
	env->a = a;
	return env;
}

value_t lambda88(env_t_88* env85, number_t j) {
	number_t a84 = env85->a;
	value_t res;
	res.number_t_value = gamma_ln((a84) + ((0.5) * ((1) - ((double)(j)))));
	return res;
}
number_t linalg_log_gamma_distrib(number_t a, number_t p) {
	closure_t* closure87 = make_closure(lambda88, make_env_t_88(a));
	return (log(pow(3.14159265358979, (0.25) * ((p) * ((p) - (1)))))) + (array_sum(array_map(closure87, array_range(1, (int)(p)))));
}

array_array_number_t linalg_new_matrix_test(array_number_t dum) {
	array_number_t array89 = (array_number_t)malloc(sizeof(int) * 2);
	array89->length=3;
	array89->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array89->arr[0] = 0;
	array89->arr[1] = 0;
	array89->arr[2] = 0;;
	array_array_number_t res = (array_array_number_t)malloc(sizeof(int) * 2);
	res->length=1;
	res->arr = (array_number_t*)malloc(sizeof(array_number_t) * 1);
	res->arr[0] = array89;;
	return res;
}

array_array_number_t linalg_to_pose_params(array_number_t theta, index_t n_bones) {
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
	array_number_t array90 = (array_number_t)malloc(sizeof(int) * 2);
	array90->length=3;
	array90->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array90->arr[0] = theta->arr[i1];
	array90->arr[1] = theta->arr[(i1) + (1)];
	array90->arr[2] = 0;;
	array_number_t array91 = (array_number_t)malloc(sizeof(int) * 2);
	array91->length=3;
	array91->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array91->arr[0] = theta->arr[(i1) + (2)];
	array91->arr[1] = 0;
	array91->arr[2] = 0;;
	array_number_t array92 = (array_number_t)malloc(sizeof(int) * 2);
	array92->length=3;
	array92->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array92->arr[0] = theta->arr[(i1) + (3)];
	array92->arr[1] = 0;
	array92->arr[2] = 0;;
	array_number_t array93 = (array_number_t)malloc(sizeof(int) * 2);
	array93->length=3;
	array93->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array93->arr[0] = 0;
	array93->arr[1] = 0;
	array93->arr[2] = 0;;
	array_array_number_t finger1 = (array_array_number_t)malloc(sizeof(int) * 2);
	finger1->length=4;
	finger1->arr = (array_number_t*)malloc(sizeof(array_number_t) * 4);
	finger1->arr[0] = array90;
	finger1->arr[1] = array91;
	finger1->arr[2] = array92;
	finger1->arr[3] = array93;;
	index_t i2 = (i1) + (4);
	array_number_t array94 = (array_number_t)malloc(sizeof(int) * 2);
	array94->length=3;
	array94->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array94->arr[0] = theta->arr[i2];
	array94->arr[1] = theta->arr[(i2) + (1)];
	array94->arr[2] = 0;;
	array_number_t array95 = (array_number_t)malloc(sizeof(int) * 2);
	array95->length=3;
	array95->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array95->arr[0] = theta->arr[(i2) + (2)];
	array95->arr[1] = 0;
	array95->arr[2] = 0;;
	array_number_t array96 = (array_number_t)malloc(sizeof(int) * 2);
	array96->length=3;
	array96->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array96->arr[0] = theta->arr[(i2) + (3)];
	array96->arr[1] = 0;
	array96->arr[2] = 0;;
	array_number_t array97 = (array_number_t)malloc(sizeof(int) * 2);
	array97->length=3;
	array97->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array97->arr[0] = 0;
	array97->arr[1] = 0;
	array97->arr[2] = 0;;
	array_array_number_t finger2 = (array_array_number_t)malloc(sizeof(int) * 2);
	finger2->length=4;
	finger2->arr = (array_number_t*)malloc(sizeof(array_number_t) * 4);
	finger2->arr[0] = array94;
	finger2->arr[1] = array95;
	finger2->arr[2] = array96;
	finger2->arr[3] = array97;;
	index_t i3 = (i2) + (4);
	array_number_t array98 = (array_number_t)malloc(sizeof(int) * 2);
	array98->length=3;
	array98->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array98->arr[0] = theta->arr[i3];
	array98->arr[1] = theta->arr[(i3) + (1)];
	array98->arr[2] = 0;;
	array_number_t array99 = (array_number_t)malloc(sizeof(int) * 2);
	array99->length=3;
	array99->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array99->arr[0] = theta->arr[(i3) + (2)];
	array99->arr[1] = 0;
	array99->arr[2] = 0;;
	array_number_t array100 = (array_number_t)malloc(sizeof(int) * 2);
	array100->length=3;
	array100->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array100->arr[0] = theta->arr[(i3) + (3)];
	array100->arr[1] = 0;
	array100->arr[2] = 0;;
	array_number_t array101 = (array_number_t)malloc(sizeof(int) * 2);
	array101->length=3;
	array101->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array101->arr[0] = 0;
	array101->arr[1] = 0;
	array101->arr[2] = 0;;
	array_array_number_t finger3 = (array_array_number_t)malloc(sizeof(int) * 2);
	finger3->length=4;
	finger3->arr = (array_number_t*)malloc(sizeof(array_number_t) * 4);
	finger3->arr[0] = array98;
	finger3->arr[1] = array99;
	finger3->arr[2] = array100;
	finger3->arr[3] = array101;;
	index_t i4 = (i3) + (4);
	array_number_t array102 = (array_number_t)malloc(sizeof(int) * 2);
	array102->length=3;
	array102->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array102->arr[0] = theta->arr[i4];
	array102->arr[1] = theta->arr[(i4) + (1)];
	array102->arr[2] = 0;;
	array_number_t array103 = (array_number_t)malloc(sizeof(int) * 2);
	array103->length=3;
	array103->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array103->arr[0] = theta->arr[(i4) + (2)];
	array103->arr[1] = 0;
	array103->arr[2] = 0;;
	array_number_t array104 = (array_number_t)malloc(sizeof(int) * 2);
	array104->length=3;
	array104->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array104->arr[0] = theta->arr[(i4) + (3)];
	array104->arr[1] = 0;
	array104->arr[2] = 0;;
	array_number_t array105 = (array_number_t)malloc(sizeof(int) * 2);
	array105->length=3;
	array105->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array105->arr[0] = 0;
	array105->arr[1] = 0;
	array105->arr[2] = 0;;
	array_array_number_t finger4 = (array_array_number_t)malloc(sizeof(int) * 2);
	finger4->length=4;
	finger4->arr = (array_number_t*)malloc(sizeof(array_number_t) * 4);
	finger4->arr[0] = array102;
	finger4->arr[1] = array103;
	finger4->arr[2] = array104;
	finger4->arr[3] = array105;;
	index_t i5 = (i4) + (4);
	array_number_t array106 = (array_number_t)malloc(sizeof(int) * 2);
	array106->length=3;
	array106->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array106->arr[0] = theta->arr[i5];
	array106->arr[1] = theta->arr[(i5) + (1)];
	array106->arr[2] = 0;;
	array_number_t array107 = (array_number_t)malloc(sizeof(int) * 2);
	array107->length=3;
	array107->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array107->arr[0] = theta->arr[(i5) + (2)];
	array107->arr[1] = 0;
	array107->arr[2] = 0;;
	array_number_t array108 = (array_number_t)malloc(sizeof(int) * 2);
	array108->length=3;
	array108->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array108->arr[0] = theta->arr[(i5) + (3)];
	array108->arr[1] = 0;
	array108->arr[2] = 0;;
	array_number_t array109 = (array_number_t)malloc(sizeof(int) * 2);
	array109->length=3;
	array109->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array109->arr[0] = 0;
	array109->arr[1] = 0;
	array109->arr[2] = 0;;
	array_array_number_t finger5 = (array_array_number_t)malloc(sizeof(int) * 2);
	finger5->length=4;
	finger5->arr = (array_number_t*)malloc(sizeof(array_number_t) * 4);
	finger5->arr[0] = array106;
	finger5->arr[1] = array107;
	finger5->arr[2] = array108;
	finger5->arr[3] = array109;;
	return matrix_concat(pose_params, matrix_concat(finger1, matrix_concat(finger2, matrix_concat(finger3, matrix_concat(finger4, finger5)))));
}

array_array_number_t linalg_euler_angles_to_rotation_matrix(array_number_t xzy) {
	number_t tx = xzy->arr[0];
	number_t ty = xzy->arr[2];
	number_t tz = xzy->arr[1];
	array_number_t array110 = (array_number_t)malloc(sizeof(int) * 2);
	array110->length=3;
	array110->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array110->arr[0] = 1;
	array110->arr[1] = 0;
	array110->arr[2] = 0;;
	array_number_t array111 = (array_number_t)malloc(sizeof(int) * 2);
	array111->length=3;
	array111->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array111->arr[0] = 0;
	array111->arr[1] = cos(tx);
	array111->arr[2] = -(sin(tx));;
	array_number_t array112 = (array_number_t)malloc(sizeof(int) * 2);
	array112->length=3;
	array112->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array112->arr[0] = 0;
	array112->arr[1] = sin(tx);
	array112->arr[2] = cos(tx);;
	array_array_number_t Rx = (array_array_number_t)malloc(sizeof(int) * 2);
	Rx->length=3;
	Rx->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	Rx->arr[0] = array110;
	Rx->arr[1] = array111;
	Rx->arr[2] = array112;;
	array_number_t array113 = (array_number_t)malloc(sizeof(int) * 2);
	array113->length=3;
	array113->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array113->arr[0] = cos(ty);
	array113->arr[1] = 0;
	array113->arr[2] = sin(ty);;
	array_number_t array114 = (array_number_t)malloc(sizeof(int) * 2);
	array114->length=3;
	array114->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array114->arr[0] = 0;
	array114->arr[1] = 1;
	array114->arr[2] = 0;;
	array_number_t array115 = (array_number_t)malloc(sizeof(int) * 2);
	array115->length=3;
	array115->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array115->arr[0] = -(sin(ty));
	array115->arr[1] = 0;
	array115->arr[2] = cos(ty);;
	array_array_number_t Ry = (array_array_number_t)malloc(sizeof(int) * 2);
	Ry->length=3;
	Ry->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	Ry->arr[0] = array113;
	Ry->arr[1] = array114;
	Ry->arr[2] = array115;;
	array_number_t array116 = (array_number_t)malloc(sizeof(int) * 2);
	array116->length=3;
	array116->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array116->arr[0] = cos(tz);
	array116->arr[1] = -(sin(tz));
	array116->arr[2] = 0;;
	array_number_t array117 = (array_number_t)malloc(sizeof(int) * 2);
	array117->length=3;
	array117->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array117->arr[0] = sin(tz);
	array117->arr[1] = cos(tz);
	array117->arr[2] = 0;;
	array_number_t array118 = (array_number_t)malloc(sizeof(int) * 2);
	array118->length=3;
	array118->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array118->arr[0] = 0;
	array118->arr[1] = 0;
	array118->arr[2] = 1;;
	array_array_number_t Rz = (array_array_number_t)malloc(sizeof(int) * 2);
	Rz->length=3;
	Rz->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	Rz->arr[0] = array116;
	Rz->arr[1] = array117;
	Rz->arr[2] = array118;;
	return matrix_mult(Rz, matrix_mult(Ry, Rx));
}

array_array_number_t linalg_matrixConcatCol(array_array_number_t m1, array_array_number_t m2) {
	array_array_number_t m1t = matrix_transpose(m1);
	array_array_number_t m2t = matrix_transpose(m2);
	return matrix_transpose(matrix_concat(m1t, m2t));
}

array_array_number_t linalg_make_relative(array_number_t pose_params, array_array_number_t base_relative) {
	array_array_number_t R = linalg_euler_angles_to_rotation_matrix(pose_params);
	array_number_t array120 = (array_number_t)malloc(sizeof(int) * 2);
	array120->length=1;
	array120->arr = (number_t*)malloc(sizeof(number_t) * 1);
	array120->arr[0] = 0;;
	array_number_t array121 = (array_number_t)malloc(sizeof(int) * 2);
	array121->length=1;
	array121->arr = (number_t*)malloc(sizeof(number_t) * 1);
	array121->arr[0] = 0;;
	array_number_t array122 = (array_number_t)malloc(sizeof(int) * 2);
	array122->length=1;
	array122->arr = (number_t*)malloc(sizeof(number_t) * 1);
	array122->arr[0] = 0;;
	array_array_number_t array119 = (array_array_number_t)malloc(sizeof(int) * 2);
	array119->length=3;
	array119->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	array119->arr[0] = array120;
	array119->arr[1] = array121;
	array119->arr[2] = array122;;
	array_number_t array124 = (array_number_t)malloc(sizeof(int) * 2);
	array124->length=4;
	array124->arr = (number_t*)malloc(sizeof(number_t) * 4);
	array124->arr[0] = 0;
	array124->arr[1] = 0;
	array124->arr[2] = 0;
	array124->arr[3] = 1;;
	array_array_number_t array123 = (array_array_number_t)malloc(sizeof(int) * 2);
	array123->length=1;
	array123->arr = (array_number_t*)malloc(sizeof(array_number_t) * 1);
	array123->arr[0] = array124;;
	array_array_number_t T = matrix_concat(linalg_matrixConcatCol(R, array119), array123);
	return matrix_mult(base_relative, T);
}
typedef struct env_t_131 {
	array_array_number_t pose_params;
	index_t offset;
	array_array_array_number_t base_relatives;
} env_t_131;
env_t_131* make_env_t_131(array_array_number_t pose_params,index_t offset,array_array_array_number_t base_relatives) {
	env_t_131* env = (env_t_131*)malloc(sizeof(env_t_131));
	env->pose_params = pose_params;
	env->offset = offset;
	env->base_relatives = base_relatives;
	return env;
}

value_t lambda131(env_t_131* env128, number_t i_bone) {
	array_array_number_t pose_params127 = env128->pose_params;
	index_t offset126 = env128->offset;
	array_array_array_number_t base_relatives125 = env128->base_relatives;
	value_t res;
	res.array_array_number_t_value = linalg_make_relative(pose_params127->arr[((int)(i_bone)) + (offset126)], base_relatives125->arr[(int)(i_bone)]);
	return res;
}
array_array_array_number_t linalg_get_posed_relatives(index_t n_bones, array_array_number_t pose_params, array_array_array_number_t base_relatives) {
	index_t offset = 3;
	closure_t* closure130 = make_closure(lambda131, make_env_t_131(pose_params,offset,base_relatives));
	return array_map_to_matrix3d(closure130, array_range(0, (n_bones) - (1)));
}

array_array_number_t linalg_angle_axis_to_rotation_matrix(array_number_t angle_axis) {
	number_t n = sqrt(linalg_sqnorm(angle_axis));
	array_array_number_t ite132 = NULL;
	if((n) < (0.0001)) {
		array_number_t array134 = (array_number_t)malloc(sizeof(int) * 2);
	array134->length=3;
	array134->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array134->arr[0] = 1;
	array134->arr[1] = 0;
	array134->arr[2] = 0;;
		array_number_t array135 = (array_number_t)malloc(sizeof(int) * 2);
	array135->length=3;
	array135->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array135->arr[0] = 0;
	array135->arr[1] = 1;
	array135->arr[2] = 0;;
		array_number_t array136 = (array_number_t)malloc(sizeof(int) * 2);
	array136->length=3;
	array136->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array136->arr[0] = 0;
	array136->arr[1] = 0;
	array136->arr[2] = 1;;
		array_array_number_t array133 = (array_array_number_t)malloc(sizeof(int) * 2);
	array133->length=3;
	array133->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	array133->arr[0] = array134;
	array133->arr[1] = array135;
	array133->arr[2] = array136;;
		ite132 = array133;
	} else {
		number_t x = (angle_axis->arr[0]) / (n);
		number_t y = (angle_axis->arr[1]) / (n);
		number_t z = (angle_axis->arr[2]) / (n);
		number_t s = sin(n);
		number_t c = cos(n);
		array_number_t array138 = (array_number_t)malloc(sizeof(int) * 2);
	array138->length=3;
	array138->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array138->arr[0] = ((x) * (x)) + (((1) - ((x) * (x))) * (c));
	array138->arr[1] = (((x) * (y)) * ((1) - (c))) - ((z) * (s));
	array138->arr[2] = (((x) * (z)) * ((1) - (c))) + ((y) * (s));;
		array_number_t array139 = (array_number_t)malloc(sizeof(int) * 2);
	array139->length=3;
	array139->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array139->arr[0] = (((x) * (y)) * ((1) - (c))) + ((z) * (s));
	array139->arr[1] = ((y) * (y)) + (((1) - ((y) * (y))) * (c));
	array139->arr[2] = (((y) * (z)) * ((1) - (c))) - ((x) * (s));;
		array_number_t array140 = (array_number_t)malloc(sizeof(int) * 2);
	array140->length=3;
	array140->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array140->arr[0] = (((x) * (z)) * ((1) - (c))) - ((y) * (s));
	array140->arr[1] = (((z) * (y)) * ((1) - (c))) + ((x) * (s));
	array140->arr[2] = ((z) * (z)) + (((1) - ((z) * (z))) * (c));;
		array_array_number_t array137 = (array_array_number_t)malloc(sizeof(int) * 2);
	array137->length=3;
	array137->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	array137->arr[0] = array138;
	array137->arr[1] = array139;
	array137->arr[2] = array140;;
		ite132 = array137;
	}
	return ite132;
}
typedef struct env_t_147 {
	array_array_array_number_t relatives;
	array_number_t parents;
} env_t_147;
env_t_147* make_env_t_147(array_array_array_number_t relatives,array_number_t parents) {
	env_t_147* env = (env_t_147*)malloc(sizeof(env_t_147));
	env->relatives = relatives;
	env->parents = parents;
	return env;
}

value_t lambda147(env_t_147* env143, number_t ind) {
	array_array_array_number_t relatives142 = env143->relatives;
	array_number_t parents141 = env143->parents;
	index_t i = (int)(ind);
	array_array_number_t ite146 = NULL;
	if((parents141->arr[i]) == (-1)) {
		
		ite146 = relatives142->arr[i];
	} else {
		
		ite146 = relatives142->arr[i];
	}
	value_t res;
	res.array_array_number_t_value = ite146;
	return res;
}
array_array_array_number_t linalg_relatives_to_absolutes(array_array_array_number_t relatives, array_number_t parents) {
	closure_t* closure145 = make_closure(lambda147, make_env_t_147(relatives,parents));
	return array_map_to_matrix3d(closure145, array_range(0, (relatives->length) - (1)));
}
typedef struct env_t_157 {
	array_number_t scale;
} env_t_157;
env_t_157* make_env_t_157(array_number_t scale) {
	env_t_157* env = (env_t_157*)malloc(sizeof(env_t_157));
	env->scale = scale;
	return env;
}

value_t lambda157(env_t_157* env149, array_number_t row) {
	array_number_t scale148 = env149->scale;
	value_t res;
	res.array_number_t_value = linalg_mult_vec_elementwise(row, scale148);
	return res;
}
typedef struct env_t_158 {
	value_t dummy_variable;
} env_t_158;
env_t_158* make_env_t_158() {
	env_t_158* env = (env_t_158*)malloc(sizeof(env_t_158));
	
	return env;
}

value_t lambda158(env_t_158* env152, number_t x) {
	
	value_t res;
	res.number_t_value = 1;
	return res;
}
array_array_number_t linalg_apply_global_transform(array_array_number_t pose_params, array_array_number_t positions) {
	array_array_number_t R = linalg_angle_axis_to_rotation_matrix(pose_params->arr[0]);
	array_number_t scale = pose_params->arr[1];
	closure_t* closure151 = make_closure(lambda157, make_env_t_157(scale));
	array_array_number_t R1 = matrix_map(closure151, R);
	array_array_number_t array155 = (array_array_number_t)malloc(sizeof(int) * 2);
	array155->length=1;
	array155->arr = (array_number_t*)malloc(sizeof(array_number_t) * 1);
	array155->arr[0] = pose_params->arr[2];;
	array_array_number_t T = linalg_matrixConcatCol(R1, matrix_transpose(array155));
	closure_t* closure154 = make_closure(lambda158, make_env_t_158());
	array_number_t ones = array_map(closure154, array_range(1, positions->arr[0]->length));
	array_array_number_t array156 = (array_array_number_t)malloc(sizeof(int) * 2);
	array156->length=1;
	array156->arr = (array_number_t*)malloc(sizeof(array_number_t) * 1);
	array156->arr[0] = ones;;
	array_array_number_t positions_homog = matrix_concat(positions, array156);
	return matrix_mult(T, positions_homog);
}
typedef struct env_t_162 {
	value_t dummy_variable;
} env_t_162;
env_t_162* make_env_t_162() {
	env_t_162* env = (env_t_162*)malloc(sizeof(env_t_162));
	
	return env;
}

value_t lambda162(env_t_162* env159, array_array_number_t m1, array_array_number_t m2) {
	
	value_t res;
	res.array_array_number_t_value = matrix_mult(m1, m2);
	return res;
}
array_array_number_t linalg_get_skinned_vertex_positions(index_t n_bones, array_array_number_t pose_params, array_array_array_number_t base_relatives, array_number_t parents, array_array_array_number_t inverse_base_absolutes, array_array_number_t base_positions, array_array_number_t weights) {
	array_array_array_number_t relatives = linalg_get_posed_relatives(n_bones, pose_params, base_relatives);
	array_array_array_number_t absolutes = linalg_relatives_to_absolutes(relatives, parents);
	closure_t* closure161 = make_closure(lambda162, make_env_t_162());
	array_array_array_number_t transforms = matrix3d_map2(closure161, absolutes, inverse_base_absolutes);
	index_t n_verts = base_positions->arr[0]->length;
	array_array_number_t positions = linalg_matrixFill(3, n_verts, 0);
	return linalg_apply_global_transform(pose_params, positions);
}
typedef struct env_t_170 {
	array_array_number_t vertex_positions;
	array_array_number_t points;
	index_t n_corr;
	array_number_t correspondences;
} env_t_170;
env_t_170* make_env_t_170(array_array_number_t vertex_positions,array_array_number_t points,index_t n_corr,array_number_t correspondences) {
	env_t_170* env = (env_t_170*)malloc(sizeof(env_t_170));
	env->vertex_positions = vertex_positions;
	env->points = points;
	env->n_corr = n_corr;
	env->correspondences = correspondences;
	return env;
}

value_t lambda170(env_t_170* env167, number_t i) {
	array_array_number_t vertex_positions166 = env167->vertex_positions;
	array_array_number_t points165 = env167->points;
	index_t n_corr164 = env167->n_corr;
	array_number_t correspondences163 = env167->correspondences;
	index_t ind = (int)(i);
	index_t r = (ind) / (n_corr164);
	index_t c = (ind) % (n_corr164);
	value_t res;
	res.number_t_value = (points165->arr[r]->arr[c]) - (vertex_positions166->arr[r]->arr[(int)(correspondences163->arr[c])]);
	return res;
}
array_number_t linalg_hand_objective(array_number_t param, array_number_t correspondences, array_array_number_t points, index_t n_bones, array_array_array_number_t base_relatives, array_number_t parents, array_array_array_number_t inverse_base_absolutes, array_array_number_t base_positions, array_array_number_t weights) {
	array_array_number_t pose_params = linalg_to_pose_params(param, n_bones);
	array_array_number_t vertex_positions = linalg_get_skinned_vertex_positions(n_bones, pose_params, base_relatives, parents, inverse_base_absolutes, base_positions, weights);
	index_t n_corr = correspondences->length;
	index_t dims = 3;
	closure_t* closure169 = make_closure(lambda170, make_env_t_170(vertex_positions,points,n_corr,correspondences));
	array_number_t err = array_map(closure169, array_range(0, ((dims) * (n_corr)) - (1)));
	return err;
}
typedef struct env_t_196 {
	value_t dummy_variable;
} env_t_196;
env_t_196* make_env_t_196() {
	env_t_196* env = (env_t_196*)malloc(sizeof(env_t_196));
	
	return env;
}

value_t lambda196(env_t_196* env171, number_t r) {
	
	value_t res;
	res.array_number_t_value = array_range(((int)(r)) * (4), (((int)(r)) * (4)) + (3));
	return res;
}
void linalg_test1(array_number_t dum) {
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
	array_number_t j = linalg_radial_distort(a, b);
	array_print(j);
	array_number_t k = linalg_rodrigues_rotate_point(a, b);
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
	array_number_t m = linalg_project(cam, j);
	array_print(m);
	array_number_t array187 = (array_number_t)malloc(sizeof(int) * 2);
	array187->length=3;
	array187->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array187->arr[0] = 1;
	array187->arr[1] = 2;
	array187->arr[2] = 3;;
	array_number_t array188 = (array_number_t)malloc(sizeof(int) * 2);
	array188->length=3;
	array188->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array188->arr[0] = 4;
	array188->arr[1] = 5;
	array188->arr[2] = 6;;
	array_number_t array189 = (array_number_t)malloc(sizeof(int) * 2);
	array189->length=3;
	array189->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array189->arr[0] = 7;
	array189->arr[1] = 8;
	array189->arr[2] = 9;;
	array_array_number_t mat1 = (array_array_number_t)malloc(sizeof(int) * 2);
	mat1->length=3;
	mat1->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	mat1->arr[0] = array187;
	mat1->arr[1] = array188;
	mat1->arr[2] = array189;;
	array_array_number_t n = matrix_mult(mat1, mat1);
	matrix_print(n);
	array_array_number_t o = matrix_transpose(n);
	matrix_print(o);
	array_array_number_t p = linalg_matrixConcatCol(mat1, mat1);
	matrix_print(p);
	closure_t* closure173 = make_closure(lambda196, make_env_t_196());
	array_array_number_t base_rel = array_map_to_matrix(closure173, array_range(1, 4));
	array_array_number_t q = linalg_make_relative(a, base_rel);
	matrix_print(q);
	array_array_number_t r = linalg_angle_axis_to_rotation_matrix(a);
	matrix_print(r);
	array_array_number_t s = linalg_apply_global_transform(mat1, mat1);
	matrix_print(s);
	return ;
}
