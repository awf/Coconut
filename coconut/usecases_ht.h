#ifndef __USECASES_HT_H__ 
#define __USECASES_HT_H__ 
#include "runtime/fsharp.h"
#include <stdio.h>
#include <math.h>
#include "linalg.h"
typedef struct env_t_126 {
	number_t mx;
} env_t_126;
env_t_126 make_env_t_126(number_t mx) {
	env_t_126 env;
	env.mx = mx;
	return env;
}

value_t lambda126(env_t_126* env123, number_t x) {
	number_t mx122 = env123->mx;
	value_t res;
	res.number_t_value = exp((x) - (mx122));
	return res;
}
number_t TOP_LEVEL_usecases_ht_logsumexp(array_number_t arr) {
	number_t mx = TOP_LEVEL_linalg_arrayMax(arr);
	env_t_126 env_t_126_value = make_env_t_126(mx); closure_t closure125 = make_closure(lambda126, &env_t_126_value);
	number_t semx = TOP_LEVEL_linalg_arraySum(TOP_LEVEL_linalg_vectorMap(closure125, arr));
	return (log(semx)) + (mx);
}
typedef struct env_t_131 {
	number_t a;
} env_t_131;
env_t_131 make_env_t_131(number_t a) {
	env_t_131 env;
	env.a = a;
	return env;
}

value_t lambda131(env_t_131* env128, number_t j) {
	number_t a127 = env128->a;
	value_t res;
	res.number_t_value = (a127) + ((0.5) * ((1) - ((double)(j))));
	return res;
}
number_t TOP_LEVEL_usecases_ht_log_gamma_distrib(number_t a, number_t p) {
	env_t_131 env_t_131_value = make_env_t_131(a); closure_t closure130 = make_closure(lambda131, &env_t_131_value);
	return (log(pow(3.14159265358979, (0.25) * ((p) * ((p) - (1)))))) + (TOP_LEVEL_linalg_arraySum(TOP_LEVEL_linalg_vectorMap(closure130, TOP_LEVEL_linalg_vectorRange(1, (int)(p)))));
}

array_array_number_t TOP_LEVEL_usecases_ht_new_matrix_test(array_number_t dum) {
	array_number_t array132 = (array_number_t)malloc(sizeof(int) * 2);
	array132->length=3;
	array132->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array132->arr[0] = 0;
	array132->arr[1] = 0;
	array132->arr[2] = 0;;
	array_array_number_t res = (array_array_number_t)malloc(sizeof(int) * 2);
	res->length=1;
	res->arr = (array_number_t*)malloc(sizeof(array_number_t) * 1);
	res->arr[0] = array132;;
	return res;
}

array_array_number_t TOP_LEVEL_usecases_ht_to_pose_params(array_number_t theta, card_t n_bones) {
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
	array_number_t array133 = (array_number_t)malloc(sizeof(int) * 2);
	array133->length=3;
	array133->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array133->arr[0] = theta->arr[i1];
	array133->arr[1] = theta->arr[(i1) + (1)];
	array133->arr[2] = 0;;
	array_number_t array134 = (array_number_t)malloc(sizeof(int) * 2);
	array134->length=3;
	array134->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array134->arr[0] = theta->arr[(i1) + (2)];
	array134->arr[1] = 0;
	array134->arr[2] = 0;;
	array_number_t array135 = (array_number_t)malloc(sizeof(int) * 2);
	array135->length=3;
	array135->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array135->arr[0] = theta->arr[(i1) + (3)];
	array135->arr[1] = 0;
	array135->arr[2] = 0;;
	array_number_t array136 = (array_number_t)malloc(sizeof(int) * 2);
	array136->length=3;
	array136->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array136->arr[0] = 0;
	array136->arr[1] = 0;
	array136->arr[2] = 0;;
	array_array_number_t finger1 = (array_array_number_t)malloc(sizeof(int) * 2);
	finger1->length=4;
	finger1->arr = (array_number_t*)malloc(sizeof(array_number_t) * 4);
	finger1->arr[0] = array133;
	finger1->arr[1] = array134;
	finger1->arr[2] = array135;
	finger1->arr[3] = array136;;
	index_t i2 = (i1) + (4);
	array_number_t array137 = (array_number_t)malloc(sizeof(int) * 2);
	array137->length=3;
	array137->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array137->arr[0] = theta->arr[i2];
	array137->arr[1] = theta->arr[(i2) + (1)];
	array137->arr[2] = 0;;
	array_number_t array138 = (array_number_t)malloc(sizeof(int) * 2);
	array138->length=3;
	array138->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array138->arr[0] = theta->arr[(i2) + (2)];
	array138->arr[1] = 0;
	array138->arr[2] = 0;;
	array_number_t array139 = (array_number_t)malloc(sizeof(int) * 2);
	array139->length=3;
	array139->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array139->arr[0] = theta->arr[(i2) + (3)];
	array139->arr[1] = 0;
	array139->arr[2] = 0;;
	array_number_t array140 = (array_number_t)malloc(sizeof(int) * 2);
	array140->length=3;
	array140->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array140->arr[0] = 0;
	array140->arr[1] = 0;
	array140->arr[2] = 0;;
	array_array_number_t finger2 = (array_array_number_t)malloc(sizeof(int) * 2);
	finger2->length=4;
	finger2->arr = (array_number_t*)malloc(sizeof(array_number_t) * 4);
	finger2->arr[0] = array137;
	finger2->arr[1] = array138;
	finger2->arr[2] = array139;
	finger2->arr[3] = array140;;
	index_t i3 = (i2) + (4);
	array_number_t array141 = (array_number_t)malloc(sizeof(int) * 2);
	array141->length=3;
	array141->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array141->arr[0] = theta->arr[i3];
	array141->arr[1] = theta->arr[(i3) + (1)];
	array141->arr[2] = 0;;
	array_number_t array142 = (array_number_t)malloc(sizeof(int) * 2);
	array142->length=3;
	array142->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array142->arr[0] = theta->arr[(i3) + (2)];
	array142->arr[1] = 0;
	array142->arr[2] = 0;;
	array_number_t array143 = (array_number_t)malloc(sizeof(int) * 2);
	array143->length=3;
	array143->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array143->arr[0] = theta->arr[(i3) + (3)];
	array143->arr[1] = 0;
	array143->arr[2] = 0;;
	array_number_t array144 = (array_number_t)malloc(sizeof(int) * 2);
	array144->length=3;
	array144->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array144->arr[0] = 0;
	array144->arr[1] = 0;
	array144->arr[2] = 0;;
	array_array_number_t finger3 = (array_array_number_t)malloc(sizeof(int) * 2);
	finger3->length=4;
	finger3->arr = (array_number_t*)malloc(sizeof(array_number_t) * 4);
	finger3->arr[0] = array141;
	finger3->arr[1] = array142;
	finger3->arr[2] = array143;
	finger3->arr[3] = array144;;
	index_t i4 = (i3) + (4);
	array_number_t array145 = (array_number_t)malloc(sizeof(int) * 2);
	array145->length=3;
	array145->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array145->arr[0] = theta->arr[i4];
	array145->arr[1] = theta->arr[(i4) + (1)];
	array145->arr[2] = 0;;
	array_number_t array146 = (array_number_t)malloc(sizeof(int) * 2);
	array146->length=3;
	array146->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array146->arr[0] = theta->arr[(i4) + (2)];
	array146->arr[1] = 0;
	array146->arr[2] = 0;;
	array_number_t array147 = (array_number_t)malloc(sizeof(int) * 2);
	array147->length=3;
	array147->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array147->arr[0] = theta->arr[(i4) + (3)];
	array147->arr[1] = 0;
	array147->arr[2] = 0;;
	array_number_t array148 = (array_number_t)malloc(sizeof(int) * 2);
	array148->length=3;
	array148->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array148->arr[0] = 0;
	array148->arr[1] = 0;
	array148->arr[2] = 0;;
	array_array_number_t finger4 = (array_array_number_t)malloc(sizeof(int) * 2);
	finger4->length=4;
	finger4->arr = (array_number_t*)malloc(sizeof(array_number_t) * 4);
	finger4->arr[0] = array145;
	finger4->arr[1] = array146;
	finger4->arr[2] = array147;
	finger4->arr[3] = array148;;
	index_t i5 = (i4) + (4);
	array_number_t array149 = (array_number_t)malloc(sizeof(int) * 2);
	array149->length=3;
	array149->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array149->arr[0] = theta->arr[i5];
	array149->arr[1] = theta->arr[(i5) + (1)];
	array149->arr[2] = 0;;
	array_number_t array150 = (array_number_t)malloc(sizeof(int) * 2);
	array150->length=3;
	array150->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array150->arr[0] = theta->arr[(i5) + (2)];
	array150->arr[1] = 0;
	array150->arr[2] = 0;;
	array_number_t array151 = (array_number_t)malloc(sizeof(int) * 2);
	array151->length=3;
	array151->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array151->arr[0] = theta->arr[(i5) + (3)];
	array151->arr[1] = 0;
	array151->arr[2] = 0;;
	array_number_t array152 = (array_number_t)malloc(sizeof(int) * 2);
	array152->length=3;
	array152->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array152->arr[0] = 0;
	array152->arr[1] = 0;
	array152->arr[2] = 0;;
	array_array_number_t finger5 = (array_array_number_t)malloc(sizeof(int) * 2);
	finger5->length=4;
	finger5->arr = (array_number_t*)malloc(sizeof(array_number_t) * 4);
	finger5->arr[0] = array149;
	finger5->arr[1] = array150;
	finger5->arr[2] = array151;
	finger5->arr[3] = array152;;
	return TOP_LEVEL_linalg_matrixConcat(pose_params, TOP_LEVEL_linalg_matrixConcat(finger1, TOP_LEVEL_linalg_matrixConcat(finger2, TOP_LEVEL_linalg_matrixConcat(finger3, TOP_LEVEL_linalg_matrixConcat(finger4, finger5)))));
}

array_array_number_t TOP_LEVEL_usecases_ht_euler_angles_to_rotation_matrix(array_number_t xzy) {
	number_t tx = xzy->arr[0];
	number_t ty = xzy->arr[2];
	number_t tz = xzy->arr[1];
	array_number_t array153 = (array_number_t)malloc(sizeof(int) * 2);
	array153->length=3;
	array153->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array153->arr[0] = 1;
	array153->arr[1] = 0;
	array153->arr[2] = 0;;
	array_number_t array154 = (array_number_t)malloc(sizeof(int) * 2);
	array154->length=3;
	array154->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array154->arr[0] = 0;
	array154->arr[1] = cos(tx);
	array154->arr[2] = -(sin(tx));;
	array_number_t array155 = (array_number_t)malloc(sizeof(int) * 2);
	array155->length=3;
	array155->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array155->arr[0] = 0;
	array155->arr[1] = sin(tx);
	array155->arr[2] = cos(tx);;
	array_array_number_t Rx = (array_array_number_t)malloc(sizeof(int) * 2);
	Rx->length=3;
	Rx->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	Rx->arr[0] = array153;
	Rx->arr[1] = array154;
	Rx->arr[2] = array155;;
	array_number_t array156 = (array_number_t)malloc(sizeof(int) * 2);
	array156->length=3;
	array156->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array156->arr[0] = cos(ty);
	array156->arr[1] = 0;
	array156->arr[2] = sin(ty);;
	array_number_t array157 = (array_number_t)malloc(sizeof(int) * 2);
	array157->length=3;
	array157->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array157->arr[0] = 0;
	array157->arr[1] = 1;
	array157->arr[2] = 0;;
	array_number_t array158 = (array_number_t)malloc(sizeof(int) * 2);
	array158->length=3;
	array158->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array158->arr[0] = -(sin(ty));
	array158->arr[1] = 0;
	array158->arr[2] = cos(ty);;
	array_array_number_t Ry = (array_array_number_t)malloc(sizeof(int) * 2);
	Ry->length=3;
	Ry->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	Ry->arr[0] = array156;
	Ry->arr[1] = array157;
	Ry->arr[2] = array158;;
	array_number_t array159 = (array_number_t)malloc(sizeof(int) * 2);
	array159->length=3;
	array159->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array159->arr[0] = cos(tz);
	array159->arr[1] = -(sin(tz));
	array159->arr[2] = 0;;
	array_number_t array160 = (array_number_t)malloc(sizeof(int) * 2);
	array160->length=3;
	array160->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array160->arr[0] = sin(tz);
	array160->arr[1] = cos(tz);
	array160->arr[2] = 0;;
	array_number_t array161 = (array_number_t)malloc(sizeof(int) * 2);
	array161->length=3;
	array161->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array161->arr[0] = 0;
	array161->arr[1] = 0;
	array161->arr[2] = 1;;
	array_array_number_t Rz = (array_array_number_t)malloc(sizeof(int) * 2);
	Rz->length=3;
	Rz->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	Rz->arr[0] = array159;
	Rz->arr[1] = array160;
	Rz->arr[2] = array161;;
	return TOP_LEVEL_linalg_matrixMult(Rz, TOP_LEVEL_linalg_matrixMult(Ry, Rx));
}

array_array_number_t TOP_LEVEL_usecases_ht_make_relative(array_number_t pose_params, array_array_number_t base_relative) {
	array_array_number_t R = TOP_LEVEL_usecases_ht_euler_angles_to_rotation_matrix(pose_params);
	array_number_t array162 = (array_number_t)malloc(sizeof(int) * 2);
	array162->length=1;
	array162->arr = (number_t*)malloc(sizeof(number_t) * 1);
	array162->arr[0] = 0;;
	array_number_t array163 = (array_number_t)malloc(sizeof(int) * 2);
	array163->length=1;
	array163->arr = (number_t*)malloc(sizeof(number_t) * 1);
	array163->arr[0] = 0;;
	array_number_t array164 = (array_number_t)malloc(sizeof(int) * 2);
	array164->length=1;
	array164->arr = (number_t*)malloc(sizeof(number_t) * 1);
	array164->arr[0] = 0;;
	array_array_number_t r1 = (array_array_number_t)malloc(sizeof(int) * 2);
	r1->length=3;
	r1->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	r1->arr[0] = array162;
	r1->arr[1] = array163;
	r1->arr[2] = array164;;
	array_number_t array165 = (array_number_t)malloc(sizeof(int) * 2);
	array165->length=4;
	array165->arr = (number_t*)malloc(sizeof(number_t) * 4);
	array165->arr[0] = 0;
	array165->arr[1] = 0;
	array165->arr[2] = 0;
	array165->arr[3] = 1;;
	array_array_number_t r2 = (array_array_number_t)malloc(sizeof(int) * 2);
	r2->length=1;
	r2->arr = (array_number_t*)malloc(sizeof(array_number_t) * 1);
	r2->arr[0] = array165;;
	array_array_number_t T = TOP_LEVEL_linalg_matrixConcat(TOP_LEVEL_linalg_matrixConcatCol(R, r1), r2);
	return TOP_LEVEL_linalg_matrixMult(base_relative, T);
}
typedef struct env_t_172 {
	array_array_number_t pose_params;
	index_t offset;
	array_array_array_number_t base_relatives;
} env_t_172;
env_t_172 make_env_t_172(array_array_number_t pose_params,index_t offset,array_array_array_number_t base_relatives) {
	env_t_172 env;
	env.pose_params = pose_params;
	env.offset = offset;
	env.base_relatives = base_relatives;
	return env;
}

value_t lambda172(env_t_172* env169, number_t i_bone) {
	array_array_number_t pose_params168 = env169->pose_params;
	index_t offset167 = env169->offset;
	array_array_array_number_t base_relatives166 = env169->base_relatives;
	value_t res;
	res.array_array_number_t_value = TOP_LEVEL_usecases_ht_make_relative(pose_params168->arr[((int)(i_bone)) + (offset167)], base_relatives166->arr[(int)(i_bone)]);
	return res;
}
array_array_array_number_t TOP_LEVEL_usecases_ht_get_posed_relatives(card_t n_bones, array_array_number_t pose_params, array_array_array_number_t base_relatives) {
	index_t offset = 3;
	env_t_172 env_t_172_value = make_env_t_172(pose_params,offset,base_relatives); closure_t closure171 = make_closure(lambda172, &env_t_172_value);
	return TOP_LEVEL_linalg_vectorMapToMatrix3D(closure171, TOP_LEVEL_linalg_vectorRange(0, (n_bones) - (1)));
}

array_array_number_t TOP_LEVEL_usecases_ht_angle_axis_to_rotation_matrix(array_number_t angle_axis) {
	number_t n = sqrt(TOP_LEVEL_linalg_sqnorm(angle_axis));
	array_array_number_t ite173 = 0;
	if((n) < (0.0001)) {
		array_number_t array175 = (array_number_t)malloc(sizeof(int) * 2);
	array175->length=3;
	array175->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array175->arr[0] = 1;
	array175->arr[1] = 0;
	array175->arr[2] = 0;;
		array_number_t array176 = (array_number_t)malloc(sizeof(int) * 2);
	array176->length=3;
	array176->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array176->arr[0] = 0;
	array176->arr[1] = 1;
	array176->arr[2] = 0;;
		array_number_t array177 = (array_number_t)malloc(sizeof(int) * 2);
	array177->length=3;
	array177->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array177->arr[0] = 0;
	array177->arr[1] = 0;
	array177->arr[2] = 1;;
		array_array_number_t array174 = (array_array_number_t)malloc(sizeof(int) * 2);
	array174->length=3;
	array174->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	array174->arr[0] = array175;
	array174->arr[1] = array176;
	array174->arr[2] = array177;;
		ite173 = array174;;
	} else {
		number_t x = (angle_axis->arr[0]) / (n);
		number_t y = (angle_axis->arr[1]) / (n);
		number_t z = (angle_axis->arr[2]) / (n);
		number_t s = sin(n);
		number_t c = cos(n);
		array_number_t array179 = (array_number_t)malloc(sizeof(int) * 2);
	array179->length=3;
	array179->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array179->arr[0] = ((x) * (x)) + (((1) - ((x) * (x))) * (c));
	array179->arr[1] = (((x) * (y)) * ((1) - (c))) - ((z) * (s));
	array179->arr[2] = (((x) * (z)) * ((1) - (c))) + ((y) * (s));;
		array_number_t array180 = (array_number_t)malloc(sizeof(int) * 2);
	array180->length=3;
	array180->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array180->arr[0] = (((x) * (y)) * ((1) - (c))) + ((z) * (s));
	array180->arr[1] = ((y) * (y)) + (((1) - ((y) * (y))) * (c));
	array180->arr[2] = (((y) * (z)) * ((1) - (c))) - ((x) * (s));;
		array_number_t array181 = (array_number_t)malloc(sizeof(int) * 2);
	array181->length=3;
	array181->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array181->arr[0] = (((x) * (z)) * ((1) - (c))) - ((y) * (s));
	array181->arr[1] = (((z) * (y)) * ((1) - (c))) + ((x) * (s));
	array181->arr[2] = ((z) * (z)) + (((1) - ((z) * (z))) * (c));;
		array_array_number_t array178 = (array_array_number_t)malloc(sizeof(int) * 2);
	array178->length=3;
	array178->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	array178->arr[0] = array179;
	array178->arr[1] = array180;
	array178->arr[2] = array181;;
		ite173 = array178;;
	}
	return ite173;
}
typedef struct env_t_191 {
	array_array_array_number_t relatives;
	array_number_t parents;
} env_t_191;
env_t_191 make_env_t_191(array_array_array_number_t relatives,array_number_t parents) {
	env_t_191 env;
	env.relatives = relatives;
	env.parents = parents;
	return env;
}

value_t lambda191(env_t_191* env184, array_array_array_number_t acc, index_t i) {
	array_array_array_number_t relatives183 = env184->relatives;
	array_number_t parents182 = env184->parents;
	array_array_array_number_t ite190 = 0;
	if((parents182->arr[i]) == (-1)) {
		array_array_array_number_t newMatrix = (array_array_array_number_t)malloc(sizeof(int) * 2);
	newMatrix->length=1;
	newMatrix->arr = (array_array_number_t*)malloc(sizeof(array_array_number_t) * 1);
	newMatrix->arr[0] = relatives183->arr[i];;
		ite190 = TOP_LEVEL_linalg_matrix3DConcat(acc, newMatrix);;
	} else {
		array_array_array_number_t newMatrix = (array_array_array_number_t)malloc(sizeof(int) * 2);
	newMatrix->length=1;
	newMatrix->arr = (array_array_number_t*)malloc(sizeof(array_array_number_t) * 1);
	newMatrix->arr[0] = TOP_LEVEL_linalg_matrixMult(acc->arr[(int)(parents182->arr[i])], relatives183->arr[i]);;
		ite190 = TOP_LEVEL_linalg_matrix3DConcat(acc, newMatrix);;
	}
	value_t res;
	res.array_array_array_number_t_value = ite190;
	return res;
}
array_array_array_number_t TOP_LEVEL_usecases_ht_relatives_to_absolutes(array_array_array_number_t relatives, array_number_t parents) {
	array_number_t array189 = (array_number_t)malloc(sizeof(int) * 2);
	array189->length=0;
	array189->arr = (number_t*)malloc(sizeof(number_t) * 0);
	;
	array_array_number_t array188 = (array_array_number_t)malloc(sizeof(int) * 2);
	array188->length=1;
	array188->arr = (array_number_t*)malloc(sizeof(array_number_t) * 1);
	array188->arr[0] = array189;;
	array_array_array_number_t init = (array_array_array_number_t)malloc(sizeof(int) * 2);
	init->length=1;
	init->arr = (array_array_number_t*)malloc(sizeof(array_array_number_t) * 1);
	init->arr[0] = array188;;
	env_t_191 env_t_191_value = make_env_t_191(relatives,parents); closure_t closure186 = make_closure(lambda191, &env_t_191_value);
	card_t macroDef187 = relatives->length;
	return TOP_LEVEL_linalg_iterateMatrix3D(closure186, init, 0, (macroDef187) - (1));
}
typedef struct env_t_202 {
	array_number_t scale;
} env_t_202;
env_t_202 make_env_t_202(array_number_t scale) {
	env_t_202 env;
	env.scale = scale;
	return env;
}

value_t lambda202(env_t_202* env193, array_number_t row) {
	array_number_t scale192 = env193->scale;
	value_t res;
	res.array_number_t_value = TOP_LEVEL_linalg_mult_vec_elementwise(row, scale192);
	return res;
}
typedef empty_env_t env_t_203;


value_t lambda203(env_t_203* env196, number_t x) {
	
	value_t res;
	res.number_t_value = 1;
	return res;
}
array_array_number_t TOP_LEVEL_usecases_ht_apply_global_transform(array_array_number_t pose_params, array_array_number_t positions) {
	array_array_number_t R = TOP_LEVEL_usecases_ht_angle_axis_to_rotation_matrix(pose_params->arr[0]);
	array_number_t scale = pose_params->arr[1];
	env_t_202 env_t_202_value = make_env_t_202(scale); closure_t closure195 = make_closure(lambda202, &env_t_202_value);
	array_array_number_t R1 = TOP_LEVEL_linalg_matrixMap(closure195, R);
	array_array_number_t array200 = (array_array_number_t)malloc(sizeof(int) * 2);
	array200->length=1;
	array200->arr = (array_number_t*)malloc(sizeof(array_number_t) * 1);
	array200->arr[0] = pose_params->arr[2];;
	array_array_number_t T = TOP_LEVEL_linalg_matrixConcatCol(R1, TOP_LEVEL_linalg_matrixTranspose(array200));
	env_t_203 env_t_203_value = make_empty_env(); closure_t closure198 = make_closure(lambda203, &env_t_203_value);
	card_t macroDef199 = positions->arr[0]->length;
	array_number_t ones = TOP_LEVEL_linalg_vectorMap(closure198, TOP_LEVEL_linalg_vectorRange(1, macroDef199));
	array_array_number_t array201 = (array_array_number_t)malloc(sizeof(int) * 2);
	array201->length=1;
	array201->arr = (array_number_t*)malloc(sizeof(array_number_t) * 1);
	array201->arr[0] = ones;;
	array_array_number_t positions_homog = TOP_LEVEL_linalg_matrixConcat(positions, array201);
	return TOP_LEVEL_linalg_matrixMult(T, positions_homog);
}
typedef empty_env_t env_t_219;


value_t lambda219(env_t_219* env204, array_array_number_t m1, array_array_number_t m2) {
	
	value_t res;
	res.array_array_number_t_value = TOP_LEVEL_linalg_matrixMult(m1, m2);
	return res;
}
typedef struct env_t_220 {
	array_array_number_t weights;
	array_array_array_number_t transforms;
	array_array_number_t base_positions;
} env_t_220;
env_t_220 make_env_t_220(array_array_number_t weights,array_array_array_number_t transforms,array_array_number_t base_positions) {
	env_t_220 env;
	env.weights = weights;
	env.transforms = transforms;
	env.base_positions = base_positions;
	return env;
}

value_t lambda220(env_t_220* env212, array_array_number_t acc, index_t i_transform) {
	array_array_number_t weights211 = env212->weights;
	array_array_array_number_t transforms210 = env212->transforms;
	array_array_number_t base_positions209 = env212->base_positions;
	array_array_number_t curr_positions = TOP_LEVEL_linalg_matrixMult(matrix_slice(transforms210->arr[i_transform], 0, 2), base_positions209);
	card_t macroDef208 = base_positions209->length;
	array_array_number_t w = TOP_LEVEL_linalg_matrixFillFromVector(macroDef208, weights211->arr[i_transform]);
	value_t res;
	res.array_array_number_t_value = TOP_LEVEL_linalg_matrixAdd(acc, TOP_LEVEL_linalg_matrixMultElementwise(curr_positions, w));
	return res;
}
array_array_number_t TOP_LEVEL_usecases_ht_get_skinned_vertex_positions(index_t is_mirrored, card_t n_bones, array_array_number_t pose_params, array_array_array_number_t base_relatives, array_number_t parents, array_array_array_number_t inverse_base_absolutes, array_array_number_t base_positions, array_array_number_t weights) {
	array_array_array_number_t relatives = TOP_LEVEL_usecases_ht_get_posed_relatives(n_bones, pose_params, base_relatives);
	array_array_array_number_t absolutes = TOP_LEVEL_usecases_ht_relatives_to_absolutes(relatives, parents);
	env_t_219 env_t_219_value = make_empty_env(); closure_t closure206 = make_closure(lambda219, &env_t_219_value);
	array_array_array_number_t transforms = TOP_LEVEL_linalg_matrix3DMap2(closure206, absolutes, inverse_base_absolutes);
	card_t macroDef207 = base_positions->arr[0]->length;
	card_t n_verts = macroDef207;
	array_array_number_t init_positions = TOP_LEVEL_linalg_matrixFill(3, n_verts, 0);
	env_t_220 env_t_220_value = make_env_t_220(weights,transforms,base_positions); closure_t closure214 = make_closure(lambda220, &env_t_220_value);
	card_t macroDef215 = transforms->length;
	array_array_number_t positions = TOP_LEVEL_linalg_iterateMatrix(closure214, init_positions, 0, (macroDef215) - (1));
	array_array_number_t mirrored_positions = 0;
	if((is_mirrored) == (1)) {
		array_number_t array216 = (array_number_t)malloc(sizeof(int) * 2);
	array216->length=3;
	array216->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array216->arr[0] = -1;
	array216->arr[1] = 0;
	array216->arr[2] = 0;;
		array_number_t array217 = (array_number_t)malloc(sizeof(int) * 2);
	array217->length=3;
	array217->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array217->arr[0] = 0;
	array217->arr[1] = 1;
	array217->arr[2] = 0;;
		array_number_t array218 = (array_number_t)malloc(sizeof(int) * 2);
	array218->length=3;
	array218->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array218->arr[0] = 0;
	array218->arr[1] = 0;
	array218->arr[2] = 1;;
		array_array_number_t mirror_matrix = (array_array_number_t)malloc(sizeof(int) * 2);
	mirror_matrix->length=3;
	mirror_matrix->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	mirror_matrix->arr[0] = array216;
	mirror_matrix->arr[1] = array217;
	mirror_matrix->arr[2] = array218;;
		mirrored_positions = TOP_LEVEL_linalg_matrixMult(mirror_matrix, positions);;
	} else {
		
		mirrored_positions = positions;;
	}
	return TOP_LEVEL_usecases_ht_apply_global_transform(pose_params, mirrored_positions);
}
typedef struct env_t_228 {
	array_array_number_t vertex_positions;
	array_array_number_t points;
	index_t n_corr;
	array_number_t correspondences;
} env_t_228;
env_t_228 make_env_t_228(array_array_number_t vertex_positions,array_array_number_t points,index_t n_corr,array_number_t correspondences) {
	env_t_228 env;
	env.vertex_positions = vertex_positions;
	env.points = points;
	env.n_corr = n_corr;
	env.correspondences = correspondences;
	return env;
}

value_t lambda228(env_t_228* env225, number_t i) {
	array_array_number_t vertex_positions224 = env225->vertex_positions;
	array_array_number_t points223 = env225->points;
	index_t n_corr222 = env225->n_corr;
	array_number_t correspondences221 = env225->correspondences;
	index_t ind = (int)(i);
	index_t r = (ind) / (n_corr222);
	index_t c = (ind) % (n_corr222);
	value_t res;
	res.number_t_value = (points223->arr[r]->arr[c]) - (vertex_positions224->arr[r]->arr[(int)(correspondences221->arr[c])]);
	return res;
}
array_number_t TOP_LEVEL_usecases_ht_hand_objective(index_t is_mirrored, array_number_t param, array_number_t correspondences, array_array_number_t points, card_t n_bones, array_array_array_number_t base_relatives, array_number_t parents, array_array_array_number_t inverse_base_absolutes, array_array_number_t base_positions, array_array_number_t weights) {
	array_array_number_t pose_params = TOP_LEVEL_usecases_ht_to_pose_params(param, n_bones);
	array_array_number_t vertex_positions = TOP_LEVEL_usecases_ht_get_skinned_vertex_positions(is_mirrored, n_bones, pose_params, base_relatives, parents, inverse_base_absolutes, base_positions, weights);
	index_t n_corr = correspondences->length;
	index_t dims = 3;
	env_t_228 env_t_228_value = make_env_t_228(vertex_positions,points,n_corr,correspondences); closure_t closure227 = make_closure(lambda228, &env_t_228_value);
	array_number_t err = TOP_LEVEL_linalg_vectorMap(closure227, TOP_LEVEL_linalg_vectorRange(0, ((dims) * (n_corr)) - (1)));
	return err;
}
typedef empty_env_t env_t_239;


value_t lambda239(env_t_239* env229, number_t r) {
	
	value_t res;
	res.array_number_t_value = TOP_LEVEL_linalg_vectorRange(((int)(r)) * (4), (((int)(r)) * (4)) + (3));
	return res;
}
void TOP_LEVEL_usecases_ht_test_ht(array_number_t dum) {
	array_number_t a = (array_number_t)malloc(sizeof(int) * 2);
	a->length=3;
	a->arr = (number_t*)malloc(sizeof(number_t) * 3);
	a->arr[0] = 1;
	a->arr[1] = 2;
	a->arr[2] = 3;;
	array_print(a);
	array_number_t array233 = (array_number_t)malloc(sizeof(int) * 2);
	array233->length=3;
	array233->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array233->arr[0] = 1;
	array233->arr[1] = 2;
	array233->arr[2] = 3;;
	array_number_t array234 = (array_number_t)malloc(sizeof(int) * 2);
	array234->length=3;
	array234->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array234->arr[0] = 4;
	array234->arr[1] = 5;
	array234->arr[2] = 6;;
	array_number_t array235 = (array_number_t)malloc(sizeof(int) * 2);
	array235->length=3;
	array235->arr = (number_t*)malloc(sizeof(number_t) * 3);
	array235->arr[0] = 7;
	array235->arr[1] = 8;
	array235->arr[2] = 9;;
	array_array_number_t mat1 = (array_array_number_t)malloc(sizeof(int) * 2);
	mat1->length=3;
	mat1->arr = (array_number_t*)malloc(sizeof(array_number_t) * 3);
	mat1->arr[0] = array233;
	mat1->arr[1] = array234;
	mat1->arr[2] = array235;;
	env_t_239 env_t_239_value = make_empty_env(); closure_t closure231 = make_closure(lambda239, &env_t_239_value);
	array_array_number_t base_rel = TOP_LEVEL_linalg_vectorMapToMatrix(closure231, TOP_LEVEL_linalg_vectorRange(1, 4));
	array_array_number_t q = TOP_LEVEL_usecases_ht_make_relative(a, base_rel);
	matrix_print(q);
	array_array_number_t r = TOP_LEVEL_usecases_ht_angle_axis_to_rotation_matrix(a);
	matrix_print(r);
	array_array_number_t s = TOP_LEVEL_usecases_ht_apply_global_transform(mat1, mat1);
	matrix_print(s);
	return ;
}
#endif
