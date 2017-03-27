#ifndef __USECASES_HT_H__ 
#define __USECASES_HT_H__ 
#include "runtime/fsharp.h"
#include <stdio.h>
#include <math.h>
#include "linalg.h"

array_array_array_number_t TOP_LEVEL_usecases_ht_matrix3DUpdate(array_array_array_number_t m, index_t s, index_t e, array_array_array_number_t nm) {
	card_t macroDef137 = m->length;
	array_array_array_number_t macroDef138 = (array_array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef138->length=macroDef137;
	macroDef138->arr = (array_array_number_t*)storage_alloc(sizeof(array_array_number_t) * macroDef137);
		for(int i = 0; i < macroDef138->length; i++){
			bool_t isInRange = 0;
	if((i) >= (s)) {
		
		isInRange = (i) < (e);;
	} else {
		
		isInRange = false;;
	}
			array_array_number_t ite139 = 0;
	if(isInRange) {
		
		ite139 = nm->arr[(i) - (s)];;
	} else {
		
		ite139 = m->arr[i];;
	}
			macroDef138->arr[i] = ite139;;
		}
	return macroDef138;
}

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
	array_number_t array140 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array140->length=3;
	array140->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array140->arr[0] = theta->arr[i1];
	array140->arr[1] = theta->arr[(i1) + (1)];
	array140->arr[2] = 0;;
	array_number_t array141 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array141->length=3;
	array141->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array141->arr[0] = theta->arr[(i1) + (2)];
	array141->arr[1] = 0;
	array141->arr[2] = 0;;
	array_number_t array142 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array142->length=3;
	array142->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array142->arr[0] = theta->arr[(i1) + (3)];
	array142->arr[1] = 0;
	array142->arr[2] = 0;;
	array_number_t array143 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array143->length=3;
	array143->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array143->arr[0] = 0;
	array143->arr[1] = 0;
	array143->arr[2] = 0;;
	array_array_number_t finger1 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	finger1->length=4;
	finger1->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * 4);
	finger1->arr[0] = array140;
	finger1->arr[1] = array141;
	finger1->arr[2] = array142;
	finger1->arr[3] = array143;;
	index_t i2 = (i1) + (4);
	array_number_t array144 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array144->length=3;
	array144->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array144->arr[0] = theta->arr[i2];
	array144->arr[1] = theta->arr[(i2) + (1)];
	array144->arr[2] = 0;;
	array_number_t array145 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array145->length=3;
	array145->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array145->arr[0] = theta->arr[(i2) + (2)];
	array145->arr[1] = 0;
	array145->arr[2] = 0;;
	array_number_t array146 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array146->length=3;
	array146->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array146->arr[0] = theta->arr[(i2) + (3)];
	array146->arr[1] = 0;
	array146->arr[2] = 0;;
	array_number_t array147 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array147->length=3;
	array147->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array147->arr[0] = 0;
	array147->arr[1] = 0;
	array147->arr[2] = 0;;
	array_array_number_t finger2 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	finger2->length=4;
	finger2->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * 4);
	finger2->arr[0] = array144;
	finger2->arr[1] = array145;
	finger2->arr[2] = array146;
	finger2->arr[3] = array147;;
	index_t i3 = (i2) + (4);
	array_number_t array148 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array148->length=3;
	array148->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array148->arr[0] = theta->arr[i3];
	array148->arr[1] = theta->arr[(i3) + (1)];
	array148->arr[2] = 0;;
	array_number_t array149 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array149->length=3;
	array149->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array149->arr[0] = theta->arr[(i3) + (2)];
	array149->arr[1] = 0;
	array149->arr[2] = 0;;
	array_number_t array150 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array150->length=3;
	array150->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array150->arr[0] = theta->arr[(i3) + (3)];
	array150->arr[1] = 0;
	array150->arr[2] = 0;;
	array_number_t array151 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array151->length=3;
	array151->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array151->arr[0] = 0;
	array151->arr[1] = 0;
	array151->arr[2] = 0;;
	array_array_number_t finger3 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	finger3->length=4;
	finger3->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * 4);
	finger3->arr[0] = array148;
	finger3->arr[1] = array149;
	finger3->arr[2] = array150;
	finger3->arr[3] = array151;;
	index_t i4 = (i3) + (4);
	array_number_t array152 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array152->length=3;
	array152->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array152->arr[0] = theta->arr[i4];
	array152->arr[1] = theta->arr[(i4) + (1)];
	array152->arr[2] = 0;;
	array_number_t array153 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array153->length=3;
	array153->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array153->arr[0] = theta->arr[(i4) + (2)];
	array153->arr[1] = 0;
	array153->arr[2] = 0;;
	array_number_t array154 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array154->length=3;
	array154->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array154->arr[0] = theta->arr[(i4) + (3)];
	array154->arr[1] = 0;
	array154->arr[2] = 0;;
	array_number_t array155 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array155->length=3;
	array155->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array155->arr[0] = 0;
	array155->arr[1] = 0;
	array155->arr[2] = 0;;
	array_array_number_t finger4 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	finger4->length=4;
	finger4->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * 4);
	finger4->arr[0] = array152;
	finger4->arr[1] = array153;
	finger4->arr[2] = array154;
	finger4->arr[3] = array155;;
	index_t i5 = (i4) + (4);
	array_number_t array156 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array156->length=3;
	array156->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array156->arr[0] = theta->arr[i5];
	array156->arr[1] = theta->arr[(i5) + (1)];
	array156->arr[2] = 0;;
	array_number_t array157 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array157->length=3;
	array157->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array157->arr[0] = theta->arr[(i5) + (2)];
	array157->arr[1] = 0;
	array157->arr[2] = 0;;
	array_number_t array158 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array158->length=3;
	array158->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array158->arr[0] = theta->arr[(i5) + (3)];
	array158->arr[1] = 0;
	array158->arr[2] = 0;;
	array_number_t array159 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array159->length=3;
	array159->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array159->arr[0] = 0;
	array159->arr[1] = 0;
	array159->arr[2] = 0;;
	array_array_number_t finger5 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	finger5->length=4;
	finger5->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * 4);
	finger5->arr[0] = array156;
	finger5->arr[1] = array157;
	finger5->arr[2] = array158;
	finger5->arr[3] = array159;;
	return TOP_LEVEL_linalg_matrixConcat(pose_params, TOP_LEVEL_linalg_matrixConcat(finger1, TOP_LEVEL_linalg_matrixConcat(finger2, TOP_LEVEL_linalg_matrixConcat(finger3, TOP_LEVEL_linalg_matrixConcat(finger4, finger5)))));
}

array_array_number_t TOP_LEVEL_usecases_ht_euler_angles_to_rotation_matrix(array_number_t xzy) {
	number_t tx = xzy->arr[0];
	number_t ty = xzy->arr[2];
	number_t tz = xzy->arr[1];
	array_number_t array160 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array160->length=3;
	array160->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array160->arr[0] = 1;
	array160->arr[1] = 0;
	array160->arr[2] = 0;;
	array_number_t array161 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array161->length=3;
	array161->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array161->arr[0] = 0;
	array161->arr[1] = cos(tx);
	array161->arr[2] = -(sin(tx));;
	array_number_t array162 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array162->length=3;
	array162->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array162->arr[0] = 0;
	array162->arr[1] = sin(tx);
	array162->arr[2] = cos(tx);;
	array_array_number_t Rx = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	Rx->length=3;
	Rx->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * 3);
	Rx->arr[0] = array160;
	Rx->arr[1] = array161;
	Rx->arr[2] = array162;;
	array_number_t array163 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array163->length=3;
	array163->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array163->arr[0] = cos(ty);
	array163->arr[1] = 0;
	array163->arr[2] = sin(ty);;
	array_number_t array164 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array164->length=3;
	array164->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array164->arr[0] = 0;
	array164->arr[1] = 1;
	array164->arr[2] = 0;;
	array_number_t array165 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array165->length=3;
	array165->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array165->arr[0] = -(sin(ty));
	array165->arr[1] = 0;
	array165->arr[2] = cos(ty);;
	array_array_number_t Ry = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	Ry->length=3;
	Ry->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * 3);
	Ry->arr[0] = array163;
	Ry->arr[1] = array164;
	Ry->arr[2] = array165;;
	array_number_t array166 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array166->length=3;
	array166->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array166->arr[0] = cos(tz);
	array166->arr[1] = -(sin(tz));
	array166->arr[2] = 0;;
	array_number_t array167 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array167->length=3;
	array167->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array167->arr[0] = sin(tz);
	array167->arr[1] = cos(tz);
	array167->arr[2] = 0;;
	array_number_t array168 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array168->length=3;
	array168->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array168->arr[0] = 0;
	array168->arr[1] = 0;
	array168->arr[2] = 1;;
	array_array_number_t Rz = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	Rz->length=3;
	Rz->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * 3);
	Rz->arr[0] = array166;
	Rz->arr[1] = array167;
	Rz->arr[2] = array168;;
	return TOP_LEVEL_linalg_matrixMult(Rz, TOP_LEVEL_linalg_matrixMult(Ry, Rx));
}

array_array_number_t TOP_LEVEL_usecases_ht_make_relative(array_number_t pose_params, array_array_number_t base_relative) {
	array_array_number_t R = TOP_LEVEL_usecases_ht_euler_angles_to_rotation_matrix(pose_params);
	array_number_t array169 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array169->length=1;
	array169->arr = (number_t*)storage_alloc(sizeof(number_t) * 1);
	array169->arr[0] = 0;;
	array_number_t array170 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array170->length=1;
	array170->arr = (number_t*)storage_alloc(sizeof(number_t) * 1);
	array170->arr[0] = 0;;
	array_number_t array171 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array171->length=1;
	array171->arr = (number_t*)storage_alloc(sizeof(number_t) * 1);
	array171->arr[0] = 0;;
	array_array_number_t r1 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	r1->length=3;
	r1->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * 3);
	r1->arr[0] = array169;
	r1->arr[1] = array170;
	r1->arr[2] = array171;;
	array_number_t array172 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array172->length=4;
	array172->arr = (number_t*)storage_alloc(sizeof(number_t) * 4);
	array172->arr[0] = 0;
	array172->arr[1] = 0;
	array172->arr[2] = 0;
	array172->arr[3] = 1;;
	array_array_number_t r2 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	r2->length=1;
	r2->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * 1);
	r2->arr[0] = array172;;
	array_array_number_t T = TOP_LEVEL_linalg_matrixConcat(TOP_LEVEL_linalg_matrixConcatCol(R, r1), r2);
	return TOP_LEVEL_linalg_matrixMult(base_relative, T);
}
typedef struct env_t_179 {
	array_array_number_t pose_params;
	index_t offset;
	array_array_array_number_t base_relatives;
} env_t_179;
env_t_179 make_env_t_179(array_array_number_t pose_params,index_t offset,array_array_array_number_t base_relatives) {
	env_t_179 env;
	env.pose_params = pose_params;
	env.offset = offset;
	env.base_relatives = base_relatives;
	return env;
}

value_t lambda179(env_t_179* env176, number_t i_bone) {
	array_array_number_t pose_params175 = env176->pose_params;
	index_t offset174 = env176->offset;
	array_array_array_number_t base_relatives173 = env176->base_relatives;
	value_t res;
	res.array_array_number_t_value = TOP_LEVEL_usecases_ht_make_relative(pose_params175->arr[((int)(i_bone)) + (offset174)], base_relatives173->arr[(int)(i_bone)]);
	return res;
}
array_array_array_number_t TOP_LEVEL_usecases_ht_get_posed_relatives(card_t n_bones, array_array_number_t pose_params, array_array_array_number_t base_relatives) {
	index_t offset = 3;
	env_t_179 env_t_179_value = make_env_t_179(pose_params,offset,base_relatives); closure_t closure178 = make_closure(lambda179, &env_t_179_value);
	return TOP_LEVEL_linalg_vectorMapToMatrix3D(closure178, TOP_LEVEL_linalg_vectorRange(0, (n_bones) - (1)));
}

array_array_number_t TOP_LEVEL_usecases_ht_angle_axis_to_rotation_matrix(array_number_t angle_axis) {
	number_t n = sqrt(TOP_LEVEL_linalg_sqnorm(angle_axis));
	array_array_number_t ite180 = 0;
	if((n) < (0.0001)) {
		array_number_t array182 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array182->length=3;
	array182->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array182->arr[0] = 1;
	array182->arr[1] = 0;
	array182->arr[2] = 0;;
		array_number_t array183 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array183->length=3;
	array183->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array183->arr[0] = 0;
	array183->arr[1] = 1;
	array183->arr[2] = 0;;
		array_number_t array184 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array184->length=3;
	array184->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array184->arr[0] = 0;
	array184->arr[1] = 0;
	array184->arr[2] = 1;;
		array_array_number_t array181 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	array181->length=3;
	array181->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * 3);
	array181->arr[0] = array182;
	array181->arr[1] = array183;
	array181->arr[2] = array184;;
		ite180 = array181;;
	} else {
		number_t x = (angle_axis->arr[0]) / (n);
		number_t y = (angle_axis->arr[1]) / (n);
		number_t z = (angle_axis->arr[2]) / (n);
		number_t s = sin(n);
		number_t c = cos(n);
		array_number_t array186 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array186->length=3;
	array186->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array186->arr[0] = ((x) * (x)) + (((1) - ((x) * (x))) * (c));
	array186->arr[1] = (((x) * (y)) * ((1) - (c))) - ((z) * (s));
	array186->arr[2] = (((x) * (z)) * ((1) - (c))) + ((y) * (s));;
		array_number_t array187 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array187->length=3;
	array187->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array187->arr[0] = (((x) * (y)) * ((1) - (c))) + ((z) * (s));
	array187->arr[1] = ((y) * (y)) + (((1) - ((y) * (y))) * (c));
	array187->arr[2] = (((y) * (z)) * ((1) - (c))) - ((x) * (s));;
		array_number_t array188 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array188->length=3;
	array188->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array188->arr[0] = (((x) * (z)) * ((1) - (c))) - ((y) * (s));
	array188->arr[1] = (((z) * (y)) * ((1) - (c))) + ((x) * (s));
	array188->arr[2] = ((z) * (z)) + (((1) - ((z) * (z))) * (c));;
		array_array_number_t array185 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	array185->length=3;
	array185->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * 3);
	array185->arr[0] = array186;
	array185->arr[1] = array187;
	array185->arr[2] = array188;;
		ite180 = array185;;
	}
	return ite180;
}

array_array_array_number_t TOP_LEVEL_usecases_ht_relatives_to_absolutes(array_array_array_number_t relatives, array_number_t parents) {
	array_array_array_number_t init = relatives;
	card_t macroDef189 = relatives->length;
	array_array_array_number_t macroDef190 = init;
	for(int i = 0; i <= (macroDef189) - (1); i++){
		array_array_array_number_t ite191 = 0;
	if((parents->arr[i]) == (-1)) {
		array_array_array_number_t newMatrix = (array_array_array_number_t)storage_alloc(sizeof(int) * 2);
	newMatrix->length=1;
	newMatrix->arr = (array_array_number_t*)storage_alloc(sizeof(array_array_number_t) * 1);
	newMatrix->arr[0] = relatives->arr[i];;
		ite191 = TOP_LEVEL_usecases_ht_matrix3DUpdate(macroDef190, i, (i) + (1), newMatrix);;
	} else {
		array_array_array_number_t newMatrix = (array_array_array_number_t)storage_alloc(sizeof(int) * 2);
	newMatrix->length=1;
	newMatrix->arr = (array_array_number_t*)storage_alloc(sizeof(array_array_number_t) * 1);
	newMatrix->arr[0] = TOP_LEVEL_linalg_matrixMult(macroDef190->arr[(int)(parents->arr[i])], relatives->arr[i]);;
		ite191 = TOP_LEVEL_usecases_ht_matrix3DUpdate(macroDef190, i, (i) + (1), newMatrix);;
	}
		macroDef190 = ite191;;
	}
	return macroDef190;
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
	array_array_number_t array200 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	array200->length=1;
	array200->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * 1);
	array200->arr[0] = pose_params->arr[2];;
	array_array_number_t T = TOP_LEVEL_linalg_matrixConcatCol(R1, TOP_LEVEL_linalg_matrixTranspose(array200));
	env_t_203 env_t_203_value = make_empty_env(); closure_t closure198 = make_closure(lambda203, &env_t_203_value);
	card_t macroDef199 = positions->arr[0]->length;
	array_number_t ones = TOP_LEVEL_linalg_vectorMap(closure198, TOP_LEVEL_linalg_vectorRange(1, macroDef199));
	array_array_number_t array201 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	array201->length=1;
	array201->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * 1);
	array201->arr[0] = ones;;
	array_array_number_t positions_homog = TOP_LEVEL_linalg_matrixConcat(positions, array201);
	return TOP_LEVEL_linalg_matrixMult(T, positions_homog);
}
typedef empty_env_t env_t_214;


value_t lambda214(env_t_214* env204, array_array_number_t m1, array_array_number_t m2) {
	
	value_t res;
	res.array_array_number_t_value = TOP_LEVEL_linalg_matrixMult(m1, m2);
	return res;
}
array_array_number_t TOP_LEVEL_usecases_ht_get_skinned_vertex_positions(index_t is_mirrored, card_t n_bones, array_array_number_t pose_params, array_array_array_number_t base_relatives, array_number_t parents, array_array_array_number_t inverse_base_absolutes, array_array_number_t base_positions, array_array_number_t weights) {
	array_array_array_number_t relatives = TOP_LEVEL_usecases_ht_get_posed_relatives(n_bones, pose_params, base_relatives);
	array_array_array_number_t absolutes = TOP_LEVEL_usecases_ht_relatives_to_absolutes(relatives, parents);
	env_t_214 env_t_214_value = make_empty_env(); closure_t closure206 = make_closure(lambda214, &env_t_214_value);
	array_array_array_number_t transforms = TOP_LEVEL_linalg_matrix3DMap2(closure206, absolutes, inverse_base_absolutes);
	card_t macroDef207 = base_positions->arr[0]->length;
	card_t n_verts = macroDef207;
	array_array_number_t init_positions = TOP_LEVEL_linalg_matrixFill(3, n_verts, 0);
	card_t macroDef209 = transforms->length;
	array_array_number_t macroDef210 = init_positions;
	for(int i_transform = 0; i_transform <= (macroDef209) - (1); i_transform++){
		array_array_number_t curr_positions = TOP_LEVEL_linalg_matrixMult(matrix_slice(transforms->arr[i_transform], 0, 2), base_positions);
		card_t macroDef208 = base_positions->length;
		array_array_number_t w = TOP_LEVEL_linalg_matrixFillFromVector(macroDef208, weights->arr[i_transform]);
		macroDef210 = TOP_LEVEL_linalg_matrixAdd(macroDef210, TOP_LEVEL_linalg_matrixMultElementwise(curr_positions, w));;
	}
	array_array_number_t positions = macroDef210;
	array_array_number_t mirrored_positions = 0;
	if((is_mirrored) == (1)) {
		array_number_t array211 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array211->length=3;
	array211->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array211->arr[0] = -1;
	array211->arr[1] = 0;
	array211->arr[2] = 0;;
		array_number_t array212 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array212->length=3;
	array212->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array212->arr[0] = 0;
	array212->arr[1] = 1;
	array212->arr[2] = 0;;
		array_number_t array213 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array213->length=3;
	array213->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array213->arr[0] = 0;
	array213->arr[1] = 0;
	array213->arr[2] = 1;;
		array_array_number_t mirror_matrix = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	mirror_matrix->length=3;
	mirror_matrix->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * 3);
	mirror_matrix->arr[0] = array211;
	mirror_matrix->arr[1] = array212;
	mirror_matrix->arr[2] = array213;;
		mirrored_positions = TOP_LEVEL_linalg_matrixMult(mirror_matrix, positions);;
	} else {
		
		mirrored_positions = positions;;
	}
	return TOP_LEVEL_usecases_ht_apply_global_transform(pose_params, mirrored_positions);
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
array_number_t TOP_LEVEL_usecases_ht_hand_objective(index_t is_mirrored, array_number_t param, array_number_t correspondences, array_array_number_t points, card_t n_bones, array_array_array_number_t base_relatives, array_number_t parents, array_array_array_number_t inverse_base_absolutes, array_array_number_t base_positions, array_array_number_t weights) {
	array_array_number_t pose_params = TOP_LEVEL_usecases_ht_to_pose_params(param, n_bones);
	array_array_number_t vertex_positions = TOP_LEVEL_usecases_ht_get_skinned_vertex_positions(is_mirrored, n_bones, pose_params, base_relatives, parents, inverse_base_absolutes, base_positions, weights);
	card_t macroDef215 = correspondences->length;
	card_t n_corr_card = macroDef215;
	index_t n_corr = (n_corr_card);
	env_t_223 env_t_223_value = make_env_t_223(vertex_positions,points,n_corr,correspondences); closure_t closure222 = make_closure(lambda223, &env_t_223_value);
	array_number_t err = TOP_LEVEL_linalg_vectorMap(closure222, TOP_LEVEL_linalg_vectorRange(0, (((n_corr_card) + (n_corr_card)) + (n_corr_card)) - (1)));
	return err;
}

void TOP_LEVEL_usecases_ht_test_ht(int unitVar0) {
	array_number_t a = (array_number_t)storage_alloc(sizeof(int) * 2);
	a->length=3;
	a->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	a->arr[0] = 1;
	a->arr[1] = 2;
	a->arr[2] = 3;;
	array_print(a);
	array_number_t array227 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array227->length=3;
	array227->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array227->arr[0] = 1;
	array227->arr[1] = 2;
	array227->arr[2] = 3;;
	array_number_t array228 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array228->length=3;
	array228->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array228->arr[0] = 4;
	array228->arr[1] = 5;
	array228->arr[2] = 6;;
	array_number_t array229 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array229->length=3;
	array229->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array229->arr[0] = 7;
	array229->arr[1] = 8;
	array229->arr[2] = 9;;
	array_array_number_t mat1 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	mat1->length=3;
	mat1->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * 3);
	mat1->arr[0] = array227;
	mat1->arr[1] = array228;
	mat1->arr[2] = array229;;
	array_array_number_t macroDef225 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef225->length=4;
	macroDef225->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * 4);
		for(int i = 0; i < macroDef225->length; i++){
			array_number_t macroDef224 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef224->length=4;
	macroDef224->arr = (number_t*)storage_alloc(sizeof(number_t) * 4);
		for(int j = 0; j < macroDef224->length; j++){
			
			macroDef224->arr[j] = (double)((((i) + (1)) * (4)) + (j));;
		}
			macroDef225->arr[i] = macroDef224;;
		}
	array_array_number_t base_rel = macroDef225;
	array_array_number_t q = TOP_LEVEL_usecases_ht_make_relative(a, base_rel);
	matrix_print(q);
	array_array_number_t r = TOP_LEVEL_usecases_ht_angle_axis_to_rotation_matrix(a);
	matrix_print(r);
	array_array_number_t s = TOP_LEVEL_usecases_ht_apply_global_transform(mat1, mat1);
	matrix_print(s);
	return ;
}
#endif
