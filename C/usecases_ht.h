#ifndef __USECASES_HT_H__ 
#define __USECASES_HT_H__ 
#include "runtime/fsharp.h"
#include <stdio.h>
#include <math.h>
#include "linalg.h"

array_array_number_t TOP_LEVEL_usecases_ht_to_pose_params(array_number_t theta, card_t n_bones) {
	array_number_t row1 = array_slice(theta, 0, 2);
	array_number_t row2 = (array_number_t)storage_alloc(sizeof(int) * 2);
	row2->length=3;
	row2->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	row2->arr[0] = 1;
	row2->arr[1] = 1;
	row2->arr[2] = 1;;
	array_number_t row3 = array_slice(theta, 3, 5);
	array_number_t zeroRow = (array_number_t)storage_alloc(sizeof(int) * 2);
	zeroRow->length=3;
	zeroRow->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	zeroRow->arr[0] = 0;
	zeroRow->arr[1] = 0;
	zeroRow->arr[2] = 0;;
	array_array_number_t pose_params = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	pose_params->length=5;
	pose_params->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * 5);
	pose_params->arr[0] = row1;
	pose_params->arr[1] = row2;
	pose_params->arr[2] = row3;
	pose_params->arr[3] = zeroRow;
	pose_params->arr[4] = zeroRow;;
	index_t i1 = 5;
	array_number_t array138 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array138->length=3;
	array138->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array138->arr[0] = theta->arr[i1];
	array138->arr[1] = theta->arr[(i1) + (1)];
	array138->arr[2] = 0;;
	array_number_t array139 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array139->length=3;
	array139->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array139->arr[0] = theta->arr[(i1) + (2)];
	array139->arr[1] = 0;
	array139->arr[2] = 0;;
	array_number_t array140 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array140->length=3;
	array140->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array140->arr[0] = theta->arr[(i1) + (3)];
	array140->arr[1] = 0;
	array140->arr[2] = 0;;
	array_number_t array141 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array141->length=3;
	array141->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array141->arr[0] = 0;
	array141->arr[1] = 0;
	array141->arr[2] = 0;;
	array_array_number_t finger1 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	finger1->length=4;
	finger1->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * 4);
	finger1->arr[0] = array138;
	finger1->arr[1] = array139;
	finger1->arr[2] = array140;
	finger1->arr[3] = array141;;
	index_t i2 = (i1) + (4);
	array_number_t array142 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array142->length=3;
	array142->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array142->arr[0] = theta->arr[i2];
	array142->arr[1] = theta->arr[(i2) + (1)];
	array142->arr[2] = 0;;
	array_number_t array143 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array143->length=3;
	array143->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array143->arr[0] = theta->arr[(i2) + (2)];
	array143->arr[1] = 0;
	array143->arr[2] = 0;;
	array_number_t array144 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array144->length=3;
	array144->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array144->arr[0] = theta->arr[(i2) + (3)];
	array144->arr[1] = 0;
	array144->arr[2] = 0;;
	array_number_t array145 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array145->length=3;
	array145->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array145->arr[0] = 0;
	array145->arr[1] = 0;
	array145->arr[2] = 0;;
	array_array_number_t finger2 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	finger2->length=4;
	finger2->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * 4);
	finger2->arr[0] = array142;
	finger2->arr[1] = array143;
	finger2->arr[2] = array144;
	finger2->arr[3] = array145;;
	index_t i3 = (i2) + (4);
	array_number_t array146 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array146->length=3;
	array146->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array146->arr[0] = theta->arr[i3];
	array146->arr[1] = theta->arr[(i3) + (1)];
	array146->arr[2] = 0;;
	array_number_t array147 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array147->length=3;
	array147->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array147->arr[0] = theta->arr[(i3) + (2)];
	array147->arr[1] = 0;
	array147->arr[2] = 0;;
	array_number_t array148 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array148->length=3;
	array148->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array148->arr[0] = theta->arr[(i3) + (3)];
	array148->arr[1] = 0;
	array148->arr[2] = 0;;
	array_number_t array149 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array149->length=3;
	array149->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array149->arr[0] = 0;
	array149->arr[1] = 0;
	array149->arr[2] = 0;;
	array_array_number_t finger3 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	finger3->length=4;
	finger3->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * 4);
	finger3->arr[0] = array146;
	finger3->arr[1] = array147;
	finger3->arr[2] = array148;
	finger3->arr[3] = array149;;
	index_t i4 = (i3) + (4);
	array_number_t array150 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array150->length=3;
	array150->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array150->arr[0] = theta->arr[i4];
	array150->arr[1] = theta->arr[(i4) + (1)];
	array150->arr[2] = 0;;
	array_number_t array151 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array151->length=3;
	array151->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array151->arr[0] = theta->arr[(i4) + (2)];
	array151->arr[1] = 0;
	array151->arr[2] = 0;;
	array_number_t array152 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array152->length=3;
	array152->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array152->arr[0] = theta->arr[(i4) + (3)];
	array152->arr[1] = 0;
	array152->arr[2] = 0;;
	array_number_t array153 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array153->length=3;
	array153->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array153->arr[0] = 0;
	array153->arr[1] = 0;
	array153->arr[2] = 0;;
	array_array_number_t finger4 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	finger4->length=4;
	finger4->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * 4);
	finger4->arr[0] = array150;
	finger4->arr[1] = array151;
	finger4->arr[2] = array152;
	finger4->arr[3] = array153;;
	index_t i5 = (i4) + (4);
	array_number_t array154 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array154->length=3;
	array154->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array154->arr[0] = theta->arr[i5];
	array154->arr[1] = theta->arr[(i5) + (1)];
	array154->arr[2] = 0;;
	array_number_t array155 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array155->length=3;
	array155->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array155->arr[0] = theta->arr[(i5) + (2)];
	array155->arr[1] = 0;
	array155->arr[2] = 0;;
	array_number_t array156 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array156->length=3;
	array156->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array156->arr[0] = theta->arr[(i5) + (3)];
	array156->arr[1] = 0;
	array156->arr[2] = 0;;
	array_number_t array157 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array157->length=3;
	array157->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array157->arr[0] = 0;
	array157->arr[1] = 0;
	array157->arr[2] = 0;;
	array_array_number_t finger5 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	finger5->length=4;
	finger5->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * 4);
	finger5->arr[0] = array154;
	finger5->arr[1] = array155;
	finger5->arr[2] = array156;
	finger5->arr[3] = array157;;
	return TOP_LEVEL_linalg_matrixConcat(pose_params, TOP_LEVEL_linalg_matrixConcat(finger1, TOP_LEVEL_linalg_matrixConcat(finger2, TOP_LEVEL_linalg_matrixConcat(finger3, TOP_LEVEL_linalg_matrixConcat(finger4, finger5)))));
}

array_array_number_t TOP_LEVEL_usecases_ht_euler_angles_to_rotation_matrix(array_number_t xzy) {
	number_t tx = xzy->arr[0];
	number_t ty = xzy->arr[2];
	number_t tz = xzy->arr[1];
	array_number_t array158 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array158->length=3;
	array158->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array158->arr[0] = 1;
	array158->arr[1] = 0;
	array158->arr[2] = 0;;
	array_number_t array159 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array159->length=3;
	array159->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array159->arr[0] = 0;
	array159->arr[1] = cos(tx);
	array159->arr[2] = -(sin(tx));;
	array_number_t array160 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array160->length=3;
	array160->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array160->arr[0] = 0;
	array160->arr[1] = sin(tx);
	array160->arr[2] = cos(tx);;
	array_array_number_t Rx = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	Rx->length=3;
	Rx->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * 3);
	Rx->arr[0] = array158;
	Rx->arr[1] = array159;
	Rx->arr[2] = array160;;
	array_number_t array161 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array161->length=3;
	array161->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array161->arr[0] = cos(ty);
	array161->arr[1] = 0;
	array161->arr[2] = sin(ty);;
	array_number_t array162 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array162->length=3;
	array162->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array162->arr[0] = 0;
	array162->arr[1] = 1;
	array162->arr[2] = 0;;
	array_number_t array163 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array163->length=3;
	array163->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array163->arr[0] = -(sin(ty));
	array163->arr[1] = 0;
	array163->arr[2] = cos(ty);;
	array_array_number_t Ry = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	Ry->length=3;
	Ry->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * 3);
	Ry->arr[0] = array161;
	Ry->arr[1] = array162;
	Ry->arr[2] = array163;;
	array_number_t array164 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array164->length=3;
	array164->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array164->arr[0] = cos(tz);
	array164->arr[1] = -(sin(tz));
	array164->arr[2] = 0;;
	array_number_t array165 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array165->length=3;
	array165->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array165->arr[0] = sin(tz);
	array165->arr[1] = cos(tz);
	array165->arr[2] = 0;;
	array_number_t array166 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array166->length=3;
	array166->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array166->arr[0] = 0;
	array166->arr[1] = 0;
	array166->arr[2] = 1;;
	array_array_number_t Rz = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	Rz->length=3;
	Rz->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * 3);
	Rz->arr[0] = array164;
	Rz->arr[1] = array165;
	Rz->arr[2] = array166;;
	return TOP_LEVEL_linalg_matrixMult(Rz, TOP_LEVEL_linalg_matrixMult(Ry, Rx));
}

array_array_number_t TOP_LEVEL_usecases_ht_make_relative(array_number_t pose_params, array_array_number_t base_relative) {
	array_array_number_t R = TOP_LEVEL_usecases_ht_euler_angles_to_rotation_matrix(pose_params);
	array_number_t array167 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array167->length=1;
	array167->arr = (number_t*)storage_alloc(sizeof(number_t) * 1);
	array167->arr[0] = 0;;
	array_number_t array168 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array168->length=1;
	array168->arr = (number_t*)storage_alloc(sizeof(number_t) * 1);
	array168->arr[0] = 0;;
	array_number_t array169 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array169->length=1;
	array169->arr = (number_t*)storage_alloc(sizeof(number_t) * 1);
	array169->arr[0] = 0;;
	array_array_number_t r1 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	r1->length=3;
	r1->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * 3);
	r1->arr[0] = array167;
	r1->arr[1] = array168;
	r1->arr[2] = array169;;
	array_number_t array170 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array170->length=4;
	array170->arr = (number_t*)storage_alloc(sizeof(number_t) * 4);
	array170->arr[0] = 0;
	array170->arr[1] = 0;
	array170->arr[2] = 0;
	array170->arr[3] = 1;;
	array_array_number_t r2 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	r2->length=1;
	r2->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * 1);
	r2->arr[0] = array170;;
	array_array_number_t T = TOP_LEVEL_linalg_matrixConcat(TOP_LEVEL_linalg_matrixConcatCol(R, r1), r2);
	return TOP_LEVEL_linalg_matrixMult(base_relative, T);
}
typedef struct env_t_177 {
	array_array_number_t pose_params;
	index_t offset;
	array_array_array_number_t base_relatives;
} env_t_177;
env_t_177 make_env_t_177(array_array_number_t pose_params,index_t offset,array_array_array_number_t base_relatives) {
	env_t_177 env;
	env.pose_params = pose_params;
	env.offset = offset;
	env.base_relatives = base_relatives;
	return env;
}

value_t lambda177(env_t_177* env174, number_t i_bone) {
	array_array_number_t pose_params173 = env174->pose_params;
	index_t offset172 = env174->offset;
	array_array_array_number_t base_relatives171 = env174->base_relatives;
	value_t res;
	res.array_array_number_t_value = TOP_LEVEL_usecases_ht_make_relative(pose_params173->arr[((int)(i_bone)) + (offset172)], base_relatives171->arr[(int)(i_bone)]);
	return res;
}
array_array_array_number_t TOP_LEVEL_usecases_ht_get_posed_relatives(card_t n_bones, array_array_number_t pose_params, array_array_array_number_t base_relatives) {
	index_t offset = 3;
	env_t_177 env_t_177_value = make_env_t_177(pose_params,offset,base_relatives); closure_t closure176 = make_closure(lambda177, &env_t_177_value);
	return TOP_LEVEL_linalg_vectorMapToMatrix3D(closure176, TOP_LEVEL_linalg_vectorRange(0, (n_bones) - (1)));
}

array_array_number_t TOP_LEVEL_usecases_ht_angle_axis_to_rotation_matrix(array_number_t angle_axis) {
	number_t n = sqrt(TOP_LEVEL_linalg_sqnorm(angle_axis));
	array_array_number_t ite178 = 0;
	if((n) < (0.0001)) {
		array_number_t array180 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array180->length=3;
	array180->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array180->arr[0] = 1;
	array180->arr[1] = 0;
	array180->arr[2] = 0;;
		array_number_t array181 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array181->length=3;
	array181->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array181->arr[0] = 0;
	array181->arr[1] = 1;
	array181->arr[2] = 0;;
		array_number_t array182 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array182->length=3;
	array182->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array182->arr[0] = 0;
	array182->arr[1] = 0;
	array182->arr[2] = 1;;
		array_array_number_t array179 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	array179->length=3;
	array179->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * 3);
	array179->arr[0] = array180;
	array179->arr[1] = array181;
	array179->arr[2] = array182;;
		ite178 = array179;;
	} else {
		number_t x = (angle_axis->arr[0]) / (n);
		number_t y = (angle_axis->arr[1]) / (n);
		number_t z = (angle_axis->arr[2]) / (n);
		number_t s = sin(n);
		number_t c = cos(n);
		array_number_t array184 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array184->length=3;
	array184->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array184->arr[0] = ((x) * (x)) + (((1) - ((x) * (x))) * (c));
	array184->arr[1] = (((x) * (y)) * ((1) - (c))) - ((z) * (s));
	array184->arr[2] = (((x) * (z)) * ((1) - (c))) + ((y) * (s));;
		array_number_t array185 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array185->length=3;
	array185->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array185->arr[0] = (((x) * (y)) * ((1) - (c))) + ((z) * (s));
	array185->arr[1] = ((y) * (y)) + (((1) - ((y) * (y))) * (c));
	array185->arr[2] = (((y) * (z)) * ((1) - (c))) - ((x) * (s));;
		array_number_t array186 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array186->length=3;
	array186->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array186->arr[0] = (((x) * (z)) * ((1) - (c))) - ((y) * (s));
	array186->arr[1] = (((z) * (y)) * ((1) - (c))) + ((x) * (s));
	array186->arr[2] = ((z) * (z)) + (((1) - ((z) * (z))) * (c));;
		array_array_number_t array183 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	array183->length=3;
	array183->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * 3);
	array183->arr[0] = array184;
	array183->arr[1] = array185;
	array183->arr[2] = array186;;
		ite178 = array183;;
	}
	return ite178;
}
typedef struct env_t_196 {
	array_array_array_number_t relatives;
	array_number_t parents;
} env_t_196;
env_t_196 make_env_t_196(array_array_array_number_t relatives,array_number_t parents) {
	env_t_196 env;
	env.relatives = relatives;
	env.parents = parents;
	return env;
}

value_t lambda196(env_t_196* env189, array_array_array_number_t acc, index_t i) {
	array_array_array_number_t relatives188 = env189->relatives;
	array_number_t parents187 = env189->parents;
	array_array_array_number_t ite195 = 0;
	if((parents187->arr[i]) == (-1)) {
		array_array_array_number_t newMatrix = (array_array_array_number_t)storage_alloc(sizeof(int) * 2);
	newMatrix->length=1;
	newMatrix->arr = (array_array_number_t*)storage_alloc(sizeof(array_array_number_t) * 1);
	newMatrix->arr[0] = relatives188->arr[i];;
		ite195 = TOP_LEVEL_linalg_matrix3DConcat(acc, newMatrix);;
	} else {
		array_array_array_number_t newMatrix = (array_array_array_number_t)storage_alloc(sizeof(int) * 2);
	newMatrix->length=1;
	newMatrix->arr = (array_array_number_t*)storage_alloc(sizeof(array_array_number_t) * 1);
	newMatrix->arr[0] = TOP_LEVEL_linalg_matrixMult(acc->arr[(int)(parents187->arr[i])], relatives188->arr[i]);;
		ite195 = TOP_LEVEL_linalg_matrix3DConcat(acc, newMatrix);;
	}
	value_t res;
	res.array_array_array_number_t_value = ite195;
	return res;
}
array_array_array_number_t TOP_LEVEL_usecases_ht_relatives_to_absolutes(array_array_array_number_t relatives, array_number_t parents) {
	array_number_t array194 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array194->length=0;
	array194->arr = (number_t*)storage_alloc(sizeof(number_t) * 0);
	;
	array_array_number_t array193 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	array193->length=1;
	array193->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * 1);
	array193->arr[0] = array194;;
	array_array_array_number_t init = (array_array_array_number_t)storage_alloc(sizeof(int) * 2);
	init->length=1;
	init->arr = (array_array_number_t*)storage_alloc(sizeof(array_array_number_t) * 1);
	init->arr[0] = array193;;
	env_t_196 env_t_196_value = make_env_t_196(relatives,parents); closure_t closure191 = make_closure(lambda196, &env_t_196_value);
	card_t macroDef192 = relatives->length;
	return TOP_LEVEL_linalg_iterateMatrix3D(closure191, init, 0, (macroDef192) - (1));
}
typedef struct env_t_207 {
	array_number_t scale;
} env_t_207;
env_t_207 make_env_t_207(array_number_t scale) {
	env_t_207 env;
	env.scale = scale;
	return env;
}

value_t lambda207(env_t_207* env198, array_number_t row) {
	array_number_t scale197 = env198->scale;
	value_t res;
	res.array_number_t_value = TOP_LEVEL_linalg_mult_vec_elementwise(row, scale197);
	return res;
}
typedef empty_env_t env_t_208;


value_t lambda208(env_t_208* env201, number_t x) {
	
	value_t res;
	res.number_t_value = 1;
	return res;
}
array_array_number_t TOP_LEVEL_usecases_ht_apply_global_transform(array_array_number_t pose_params, array_array_number_t positions) {
	array_array_number_t R = TOP_LEVEL_usecases_ht_angle_axis_to_rotation_matrix(pose_params->arr[0]);
	array_number_t scale = pose_params->arr[1];
	env_t_207 env_t_207_value = make_env_t_207(scale); closure_t closure200 = make_closure(lambda207, &env_t_207_value);
	array_array_number_t R1 = TOP_LEVEL_linalg_matrixMap(closure200, R);
	array_array_number_t array205 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	array205->length=1;
	array205->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * 1);
	array205->arr[0] = pose_params->arr[2];;
	array_array_number_t T = TOP_LEVEL_linalg_matrixConcatCol(R1, TOP_LEVEL_linalg_matrixTranspose(array205));
	env_t_208 env_t_208_value = make_empty_env(); closure_t closure203 = make_closure(lambda208, &env_t_208_value);
	card_t macroDef204 = positions->arr[0]->length;
	array_number_t ones = TOP_LEVEL_linalg_vectorMap(closure203, TOP_LEVEL_linalg_vectorRange(1, macroDef204));
	array_array_number_t array206 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	array206->length=1;
	array206->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * 1);
	array206->arr[0] = ones;;
	array_array_number_t positions_homog = TOP_LEVEL_linalg_matrixConcat(positions, array206);
	return TOP_LEVEL_linalg_matrixMult(T, positions_homog);
}
typedef empty_env_t env_t_224;


value_t lambda224(env_t_224* env209, array_array_number_t m1, array_array_number_t m2) {
	
	value_t res;
	res.array_array_number_t_value = TOP_LEVEL_linalg_matrixMult(m1, m2);
	return res;
}
typedef struct env_t_225 {
	array_array_number_t weights;
	array_array_array_number_t transforms;
	array_array_number_t base_positions;
} env_t_225;
env_t_225 make_env_t_225(array_array_number_t weights,array_array_array_number_t transforms,array_array_number_t base_positions) {
	env_t_225 env;
	env.weights = weights;
	env.transforms = transforms;
	env.base_positions = base_positions;
	return env;
}

value_t lambda225(env_t_225* env217, array_array_number_t acc, index_t i_transform) {
	array_array_number_t weights216 = env217->weights;
	array_array_array_number_t transforms215 = env217->transforms;
	array_array_number_t base_positions214 = env217->base_positions;
	array_array_number_t curr_positions = TOP_LEVEL_linalg_matrixMult(matrix_slice(transforms215->arr[i_transform], 0, 2), base_positions214);
	card_t macroDef213 = base_positions214->length;
	array_array_number_t w = TOP_LEVEL_linalg_matrixFillFromVector(macroDef213, weights216->arr[i_transform]);
	value_t res;
	res.array_array_number_t_value = TOP_LEVEL_linalg_matrixAdd(acc, TOP_LEVEL_linalg_matrixMultElementwise(curr_positions, w));
	return res;
}
array_array_number_t TOP_LEVEL_usecases_ht_get_skinned_vertex_positions(index_t is_mirrored, card_t n_bones, array_array_number_t pose_params, array_array_array_number_t base_relatives, array_number_t parents, array_array_array_number_t inverse_base_absolutes, array_array_number_t base_positions, array_array_number_t weights) {
	array_array_array_number_t relatives = TOP_LEVEL_usecases_ht_get_posed_relatives(n_bones, pose_params, base_relatives);
	array_array_array_number_t absolutes = TOP_LEVEL_usecases_ht_relatives_to_absolutes(relatives, parents);
	env_t_224 env_t_224_value = make_empty_env(); closure_t closure211 = make_closure(lambda224, &env_t_224_value);
	array_array_array_number_t transforms = TOP_LEVEL_linalg_matrix3DMap2(closure211, absolutes, inverse_base_absolutes);
	card_t macroDef212 = base_positions->arr[0]->length;
	card_t n_verts = macroDef212;
	array_array_number_t init_positions = TOP_LEVEL_linalg_matrixFill(3, n_verts, 0);
	env_t_225 env_t_225_value = make_env_t_225(weights,transforms,base_positions); closure_t closure219 = make_closure(lambda225, &env_t_225_value);
	card_t macroDef220 = transforms->length;
	array_array_number_t positions = TOP_LEVEL_linalg_iterateMatrix(closure219, init_positions, 0, (macroDef220) - (1));
	array_array_number_t mirrored_positions = 0;
	if((is_mirrored) == (1)) {
		array_number_t array221 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array221->length=3;
	array221->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array221->arr[0] = -1;
	array221->arr[1] = 0;
	array221->arr[2] = 0;;
		array_number_t array222 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array222->length=3;
	array222->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array222->arr[0] = 0;
	array222->arr[1] = 1;
	array222->arr[2] = 0;;
		array_number_t array223 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array223->length=3;
	array223->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array223->arr[0] = 0;
	array223->arr[1] = 0;
	array223->arr[2] = 1;;
		array_array_number_t mirror_matrix = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	mirror_matrix->length=3;
	mirror_matrix->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * 3);
	mirror_matrix->arr[0] = array221;
	mirror_matrix->arr[1] = array222;
	mirror_matrix->arr[2] = array223;;
		mirrored_positions = TOP_LEVEL_linalg_matrixMult(mirror_matrix, positions);;
	} else {
		
		mirrored_positions = positions;;
	}
	return TOP_LEVEL_usecases_ht_apply_global_transform(pose_params, mirrored_positions);
}
typedef struct env_t_233 {
	array_array_number_t vertex_positions;
	array_array_number_t points;
	index_t n_corr;
	array_number_t correspondences;
} env_t_233;
env_t_233 make_env_t_233(array_array_number_t vertex_positions,array_array_number_t points,index_t n_corr,array_number_t correspondences) {
	env_t_233 env;
	env.vertex_positions = vertex_positions;
	env.points = points;
	env.n_corr = n_corr;
	env.correspondences = correspondences;
	return env;
}

value_t lambda233(env_t_233* env230, number_t i) {
	array_array_number_t vertex_positions229 = env230->vertex_positions;
	array_array_number_t points228 = env230->points;
	index_t n_corr227 = env230->n_corr;
	array_number_t correspondences226 = env230->correspondences;
	index_t ind = (int)(i);
	index_t r = (ind) / (n_corr227);
	index_t c = (ind) % (n_corr227);
	value_t res;
	res.number_t_value = (points228->arr[r]->arr[c]) - (vertex_positions229->arr[r]->arr[(int)(correspondences226->arr[c])]);
	return res;
}
array_number_t TOP_LEVEL_usecases_ht_hand_objective(index_t is_mirrored, array_number_t param, array_number_t correspondences, array_array_number_t points, card_t n_bones, array_array_array_number_t base_relatives, array_number_t parents, array_array_array_number_t inverse_base_absolutes, array_array_number_t base_positions, array_array_number_t weights) {
	array_array_number_t pose_params = TOP_LEVEL_usecases_ht_to_pose_params(param, n_bones);
	array_array_number_t vertex_positions = TOP_LEVEL_usecases_ht_get_skinned_vertex_positions(is_mirrored, n_bones, pose_params, base_relatives, parents, inverse_base_absolutes, base_positions, weights);
	index_t n_corr = correspondences->length;
	index_t dims = 3;
	env_t_233 env_t_233_value = make_env_t_233(vertex_positions,points,n_corr,correspondences); closure_t closure232 = make_closure(lambda233, &env_t_233_value);
	array_number_t err = TOP_LEVEL_linalg_vectorMap(closure232, TOP_LEVEL_linalg_vectorRange(0, ((dims) * (n_corr)) - (1)));
	return err;
}
typedef empty_env_t env_t_244;


value_t lambda244(env_t_244* env234, number_t r) {
	
	value_t res;
	res.array_number_t_value = TOP_LEVEL_linalg_vectorRange(((int)(r)) * (4), (((int)(r)) * (4)) + (3));
	return res;
}
void TOP_LEVEL_usecases_ht_test_ht(array_number_t dum) {
	array_number_t a = (array_number_t)storage_alloc(sizeof(int) * 2);
	a->length=3;
	a->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	a->arr[0] = 1;
	a->arr[1] = 2;
	a->arr[2] = 3;;
	array_print(a);
	array_number_t array238 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array238->length=3;
	array238->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array238->arr[0] = 1;
	array238->arr[1] = 2;
	array238->arr[2] = 3;;
	array_number_t array239 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array239->length=3;
	array239->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array239->arr[0] = 4;
	array239->arr[1] = 5;
	array239->arr[2] = 6;;
	array_number_t array240 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array240->length=3;
	array240->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array240->arr[0] = 7;
	array240->arr[1] = 8;
	array240->arr[2] = 9;;
	array_array_number_t mat1 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	mat1->length=3;
	mat1->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * 3);
	mat1->arr[0] = array238;
	mat1->arr[1] = array239;
	mat1->arr[2] = array240;;
	env_t_244 env_t_244_value = make_empty_env(); closure_t closure236 = make_closure(lambda244, &env_t_244_value);
	array_array_number_t base_rel = TOP_LEVEL_linalg_vectorMapToMatrix(closure236, TOP_LEVEL_linalg_vectorRange(1, 4));
	array_array_number_t q = TOP_LEVEL_usecases_ht_make_relative(a, base_rel);
	matrix_print(q);
	array_array_number_t r = TOP_LEVEL_usecases_ht_angle_axis_to_rotation_matrix(a);
	matrix_print(r);
	array_array_number_t s = TOP_LEVEL_usecases_ht_apply_global_transform(mat1, mat1);
	matrix_print(s);
	return ;
}
#endif
