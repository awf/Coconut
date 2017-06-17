#ifndef __USECASES_HT_H__ 
#define __USECASES_HT_H__ 
#include "../../Runtime/C/fsharp.h"
#include <stdio.h>
#include <math.h>
#include "linalg.h"

array_array_array_number_t TOP_LEVEL_usecases_ht_matrix3DUpdate(array_array_array_number_t m, index_t s, index_t e, array_array_array_number_t nm) {
	card_t macroDef152 = m->length;
	array_array_array_number_t macroDef153 = (array_array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef153->length=macroDef152;
	macroDef153->arr = (array_array_number_t*)storage_alloc(sizeof(array_array_number_t) * macroDef152);
		for(int i = 0; i < macroDef153->length; i++){
			bool_t isInRange = 0;
	if((i) >= (s)) {
		
		isInRange = (i) < (e);;
	} else {
		
		isInRange = false;;
	}
			array_array_number_t ite154 = 0;
	if(isInRange) {
		
		ite154 = nm->arr[(i) - (s)];;
	} else {
		
		ite154 = m->arr[i];;
	}
			macroDef153->arr[i] = ite154;;
		}
	return macroDef153;
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
	array_number_t array155 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array155->length=3;
	array155->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array155->arr[0] = theta->arr[i1];
	array155->arr[1] = theta->arr[(i1) + (1)];
	array155->arr[2] = 0;;
	array_number_t array156 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array156->length=3;
	array156->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array156->arr[0] = theta->arr[(i1) + (2)];
	array156->arr[1] = 0;
	array156->arr[2] = 0;;
	array_number_t array157 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array157->length=3;
	array157->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array157->arr[0] = theta->arr[(i1) + (3)];
	array157->arr[1] = 0;
	array157->arr[2] = 0;;
	array_number_t array158 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array158->length=3;
	array158->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array158->arr[0] = 0;
	array158->arr[1] = 0;
	array158->arr[2] = 0;;
	array_array_number_t finger1 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	finger1->length=4;
	finger1->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * 4);
	finger1->arr[0] = array155;
	finger1->arr[1] = array156;
	finger1->arr[2] = array157;
	finger1->arr[3] = array158;;
	index_t i2 = (i1) + (4);
	array_number_t array159 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array159->length=3;
	array159->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array159->arr[0] = theta->arr[i2];
	array159->arr[1] = theta->arr[(i2) + (1)];
	array159->arr[2] = 0;;
	array_number_t array160 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array160->length=3;
	array160->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array160->arr[0] = theta->arr[(i2) + (2)];
	array160->arr[1] = 0;
	array160->arr[2] = 0;;
	array_number_t array161 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array161->length=3;
	array161->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array161->arr[0] = theta->arr[(i2) + (3)];
	array161->arr[1] = 0;
	array161->arr[2] = 0;;
	array_number_t array162 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array162->length=3;
	array162->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array162->arr[0] = 0;
	array162->arr[1] = 0;
	array162->arr[2] = 0;;
	array_array_number_t finger2 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	finger2->length=4;
	finger2->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * 4);
	finger2->arr[0] = array159;
	finger2->arr[1] = array160;
	finger2->arr[2] = array161;
	finger2->arr[3] = array162;;
	index_t i3 = (i2) + (4);
	array_number_t array163 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array163->length=3;
	array163->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array163->arr[0] = theta->arr[i3];
	array163->arr[1] = theta->arr[(i3) + (1)];
	array163->arr[2] = 0;;
	array_number_t array164 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array164->length=3;
	array164->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array164->arr[0] = theta->arr[(i3) + (2)];
	array164->arr[1] = 0;
	array164->arr[2] = 0;;
	array_number_t array165 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array165->length=3;
	array165->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array165->arr[0] = theta->arr[(i3) + (3)];
	array165->arr[1] = 0;
	array165->arr[2] = 0;;
	array_number_t array166 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array166->length=3;
	array166->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array166->arr[0] = 0;
	array166->arr[1] = 0;
	array166->arr[2] = 0;;
	array_array_number_t finger3 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	finger3->length=4;
	finger3->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * 4);
	finger3->arr[0] = array163;
	finger3->arr[1] = array164;
	finger3->arr[2] = array165;
	finger3->arr[3] = array166;;
	index_t i4 = (i3) + (4);
	array_number_t array167 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array167->length=3;
	array167->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array167->arr[0] = theta->arr[i4];
	array167->arr[1] = theta->arr[(i4) + (1)];
	array167->arr[2] = 0;;
	array_number_t array168 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array168->length=3;
	array168->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array168->arr[0] = theta->arr[(i4) + (2)];
	array168->arr[1] = 0;
	array168->arr[2] = 0;;
	array_number_t array169 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array169->length=3;
	array169->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array169->arr[0] = theta->arr[(i4) + (3)];
	array169->arr[1] = 0;
	array169->arr[2] = 0;;
	array_number_t array170 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array170->length=3;
	array170->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array170->arr[0] = 0;
	array170->arr[1] = 0;
	array170->arr[2] = 0;;
	array_array_number_t finger4 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	finger4->length=4;
	finger4->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * 4);
	finger4->arr[0] = array167;
	finger4->arr[1] = array168;
	finger4->arr[2] = array169;
	finger4->arr[3] = array170;;
	index_t i5 = (i4) + (4);
	array_number_t array171 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array171->length=3;
	array171->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array171->arr[0] = theta->arr[i5];
	array171->arr[1] = theta->arr[(i5) + (1)];
	array171->arr[2] = 0;;
	array_number_t array172 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array172->length=3;
	array172->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array172->arr[0] = theta->arr[(i5) + (2)];
	array172->arr[1] = 0;
	array172->arr[2] = 0;;
	array_number_t array173 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array173->length=3;
	array173->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array173->arr[0] = theta->arr[(i5) + (3)];
	array173->arr[1] = 0;
	array173->arr[2] = 0;;
	array_number_t array174 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array174->length=3;
	array174->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array174->arr[0] = 0;
	array174->arr[1] = 0;
	array174->arr[2] = 0;;
	array_array_number_t finger5 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	finger5->length=4;
	finger5->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * 4);
	finger5->arr[0] = array171;
	finger5->arr[1] = array172;
	finger5->arr[2] = array173;
	finger5->arr[3] = array174;;
	return TOP_LEVEL_linalg_matrixConcat(pose_params, TOP_LEVEL_linalg_matrixConcat(finger1, TOP_LEVEL_linalg_matrixConcat(finger2, TOP_LEVEL_linalg_matrixConcat(finger3, TOP_LEVEL_linalg_matrixConcat(finger4, finger5)))));
}

array_array_number_t TOP_LEVEL_usecases_ht_euler_angles_to_rotation_matrix(array_number_t xzy) {
	number_t tx = xzy->arr[0];
	number_t ty = xzy->arr[2];
	number_t tz = xzy->arr[1];
	array_number_t array175 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array175->length=3;
	array175->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array175->arr[0] = 1;
	array175->arr[1] = 0;
	array175->arr[2] = 0;;
	array_number_t array176 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array176->length=3;
	array176->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array176->arr[0] = 0;
	array176->arr[1] = cos(tx);
	array176->arr[2] = -(sin(tx));;
	array_number_t array177 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array177->length=3;
	array177->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array177->arr[0] = 0;
	array177->arr[1] = sin(tx);
	array177->arr[2] = cos(tx);;
	array_array_number_t Rx = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	Rx->length=3;
	Rx->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * 3);
	Rx->arr[0] = array175;
	Rx->arr[1] = array176;
	Rx->arr[2] = array177;;
	array_number_t array178 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array178->length=3;
	array178->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array178->arr[0] = cos(ty);
	array178->arr[1] = 0;
	array178->arr[2] = sin(ty);;
	array_number_t array179 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array179->length=3;
	array179->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array179->arr[0] = 0;
	array179->arr[1] = 1;
	array179->arr[2] = 0;;
	array_number_t array180 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array180->length=3;
	array180->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array180->arr[0] = -(sin(ty));
	array180->arr[1] = 0;
	array180->arr[2] = cos(ty);;
	array_array_number_t Ry = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	Ry->length=3;
	Ry->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * 3);
	Ry->arr[0] = array178;
	Ry->arr[1] = array179;
	Ry->arr[2] = array180;;
	array_number_t array181 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array181->length=3;
	array181->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array181->arr[0] = cos(tz);
	array181->arr[1] = -(sin(tz));
	array181->arr[2] = 0;;
	array_number_t array182 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array182->length=3;
	array182->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array182->arr[0] = sin(tz);
	array182->arr[1] = cos(tz);
	array182->arr[2] = 0;;
	array_number_t array183 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array183->length=3;
	array183->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array183->arr[0] = 0;
	array183->arr[1] = 0;
	array183->arr[2] = 1;;
	array_array_number_t Rz = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	Rz->length=3;
	Rz->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * 3);
	Rz->arr[0] = array181;
	Rz->arr[1] = array182;
	Rz->arr[2] = array183;;
	return TOP_LEVEL_linalg_matrixMult(Rz, TOP_LEVEL_linalg_matrixMult(Ry, Rx));
}

array_array_number_t TOP_LEVEL_usecases_ht_make_relative(array_number_t pose_params, array_array_number_t base_relative) {
	array_array_number_t R = TOP_LEVEL_usecases_ht_euler_angles_to_rotation_matrix(pose_params);
	array_number_t array184 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array184->length=1;
	array184->arr = (number_t*)storage_alloc(sizeof(number_t) * 1);
	array184->arr[0] = 0;;
	array_number_t array185 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array185->length=1;
	array185->arr = (number_t*)storage_alloc(sizeof(number_t) * 1);
	array185->arr[0] = 0;;
	array_number_t array186 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array186->length=1;
	array186->arr = (number_t*)storage_alloc(sizeof(number_t) * 1);
	array186->arr[0] = 0;;
	array_array_number_t r1 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	r1->length=3;
	r1->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * 3);
	r1->arr[0] = array184;
	r1->arr[1] = array185;
	r1->arr[2] = array186;;
	array_number_t array187 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array187->length=4;
	array187->arr = (number_t*)storage_alloc(sizeof(number_t) * 4);
	array187->arr[0] = 0;
	array187->arr[1] = 0;
	array187->arr[2] = 0;
	array187->arr[3] = 1;;
	array_array_number_t r2 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	r2->length=1;
	r2->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * 1);
	r2->arr[0] = array187;;
	array_array_number_t T = TOP_LEVEL_linalg_matrixConcat(TOP_LEVEL_linalg_matrixConcatCol(R, r1), r2);
	return TOP_LEVEL_linalg_matrixMult(base_relative, T);
}
typedef struct env_t_194 {
	array_array_number_t pose_params;
	index_t offset;
	array_array_array_number_t base_relatives;
} env_t_194;
env_t_194 make_env_t_194(array_array_number_t pose_params,index_t offset,array_array_array_number_t base_relatives) {
	env_t_194 env;
	env.pose_params = pose_params;
	env.offset = offset;
	env.base_relatives = base_relatives;
	return env;
}

value_t lambda194(env_t_194* env191, number_t i_bone) {
	array_array_number_t pose_params190 = env191->pose_params;
	index_t offset189 = env191->offset;
	array_array_array_number_t base_relatives188 = env191->base_relatives;
	value_t res;
	res.array_array_number_t_value = TOP_LEVEL_usecases_ht_make_relative(pose_params190->arr[((int)(i_bone)) + (offset189)], base_relatives188->arr[(int)(i_bone)]);
	return res;
}
array_array_array_number_t TOP_LEVEL_usecases_ht_get_posed_relatives(card_t n_bones, array_array_number_t pose_params, array_array_array_number_t base_relatives) {
	index_t offset = 3;
	env_t_194 env_t_194_value = make_env_t_194(pose_params,offset,base_relatives); closure_t closure193 = make_closure(lambda194, &env_t_194_value);
	return TOP_LEVEL_linalg_vectorMapToMatrix3D(closure193, TOP_LEVEL_linalg_vectorRange(0, (n_bones) - (1)));
}

array_array_number_t TOP_LEVEL_usecases_ht_angle_axis_to_rotation_matrix(array_number_t angle_axis) {
	number_t n = sqrt(TOP_LEVEL_linalg_sqnorm(angle_axis));
	array_array_number_t ite195 = 0;
	if((n) < (0.0001)) {
		array_number_t array197 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array197->length=3;
	array197->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array197->arr[0] = 1;
	array197->arr[1] = 0;
	array197->arr[2] = 0;;
		array_number_t array198 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array198->length=3;
	array198->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array198->arr[0] = 0;
	array198->arr[1] = 1;
	array198->arr[2] = 0;;
		array_number_t array199 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array199->length=3;
	array199->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array199->arr[0] = 0;
	array199->arr[1] = 0;
	array199->arr[2] = 1;;
		array_array_number_t array196 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	array196->length=3;
	array196->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * 3);
	array196->arr[0] = array197;
	array196->arr[1] = array198;
	array196->arr[2] = array199;;
		ite195 = array196;;
	} else {
		number_t x = (angle_axis->arr[0]) / (n);
		number_t y = (angle_axis->arr[1]) / (n);
		number_t z = (angle_axis->arr[2]) / (n);
		number_t s = sin(n);
		number_t c = cos(n);
		array_number_t array201 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array201->length=3;
	array201->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array201->arr[0] = ((x) * (x)) + (((1) - ((x) * (x))) * (c));
	array201->arr[1] = (((x) * (y)) * ((1) - (c))) - ((z) * (s));
	array201->arr[2] = (((x) * (z)) * ((1) - (c))) + ((y) * (s));;
		array_number_t array202 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array202->length=3;
	array202->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array202->arr[0] = (((x) * (y)) * ((1) - (c))) + ((z) * (s));
	array202->arr[1] = ((y) * (y)) + (((1) - ((y) * (y))) * (c));
	array202->arr[2] = (((y) * (z)) * ((1) - (c))) - ((x) * (s));;
		array_number_t array203 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array203->length=3;
	array203->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array203->arr[0] = (((x) * (z)) * ((1) - (c))) - ((y) * (s));
	array203->arr[1] = (((z) * (y)) * ((1) - (c))) + ((x) * (s));
	array203->arr[2] = ((z) * (z)) + (((1) - ((z) * (z))) * (c));;
		array_array_number_t array200 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	array200->length=3;
	array200->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * 3);
	array200->arr[0] = array201;
	array200->arr[1] = array202;
	array200->arr[2] = array203;;
		ite195 = array200;;
	}
	return ite195;
}

array_array_array_number_t TOP_LEVEL_usecases_ht_relatives_to_absolutes(array_array_array_number_t relatives, array_number_t parents) {
	array_array_array_number_t init = relatives;
	card_t macroDef204 = relatives->length;
	array_array_array_number_t macroDef205 = init;
	for(int i = 0; i < macroDef204; i++){
		array_array_array_number_t ite206 = 0;
	if((parents->arr[i]) == (-1)) {
		array_array_array_number_t newMatrix = (array_array_array_number_t)storage_alloc(sizeof(int) * 2);
	newMatrix->length=1;
	newMatrix->arr = (array_array_number_t*)storage_alloc(sizeof(array_array_number_t) * 1);
	newMatrix->arr[0] = relatives->arr[i];;
		ite206 = TOP_LEVEL_usecases_ht_matrix3DUpdate(macroDef205, i, (i) + (1), newMatrix);;
	} else {
		array_array_array_number_t newMatrix = (array_array_array_number_t)storage_alloc(sizeof(int) * 2);
	newMatrix->length=1;
	newMatrix->arr = (array_array_number_t*)storage_alloc(sizeof(array_array_number_t) * 1);
	newMatrix->arr[0] = TOP_LEVEL_linalg_matrixMult(macroDef205->arr[(int)(parents->arr[i])], relatives->arr[i]);;
		ite206 = TOP_LEVEL_usecases_ht_matrix3DUpdate(macroDef205, i, (i) + (1), newMatrix);;
	}
		macroDef205 = ite206;;
	}
	return macroDef205;
}
typedef struct env_t_217 {
	array_number_t scale;
} env_t_217;
env_t_217 make_env_t_217(array_number_t scale) {
	env_t_217 env;
	env.scale = scale;
	return env;
}

value_t lambda217(env_t_217* env208, array_number_t row) {
	array_number_t scale207 = env208->scale;
	value_t res;
	res.array_number_t_value = TOP_LEVEL_linalg_mult_vec_elementwise(row, scale207);
	return res;
}
typedef empty_env_t env_t_218;


value_t lambda218(env_t_218* env211, number_t x) {
	
	value_t res;
	res.number_t_value = 1;
	return res;
}
array_array_number_t TOP_LEVEL_usecases_ht_apply_global_transform(array_array_number_t pose_params, array_array_number_t positions) {
	array_array_number_t R = TOP_LEVEL_usecases_ht_angle_axis_to_rotation_matrix(pose_params->arr[0]);
	array_number_t scale = pose_params->arr[1];
	env_t_217 env_t_217_value = make_env_t_217(scale); closure_t closure210 = make_closure(lambda217, &env_t_217_value);
	array_array_number_t R1 = TOP_LEVEL_linalg_matrixMap(closure210, R);
	array_array_number_t array215 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	array215->length=1;
	array215->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * 1);
	array215->arr[0] = pose_params->arr[2];;
	array_array_number_t T = TOP_LEVEL_linalg_matrixConcatCol(R1, TOP_LEVEL_linalg_matrixTranspose(array215));
	env_t_218 env_t_218_value = make_empty_env(); closure_t closure213 = make_closure(lambda218, &env_t_218_value);
	card_t macroDef214 = positions->arr[0]->length;
	array_number_t ones = TOP_LEVEL_linalg_vectorMap(closure213, TOP_LEVEL_linalg_vectorRange(1, macroDef214));
	array_array_number_t array216 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	array216->length=1;
	array216->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * 1);
	array216->arr[0] = ones;;
	array_array_number_t positions_homog = TOP_LEVEL_linalg_matrixConcat(positions, array216);
	return TOP_LEVEL_linalg_matrixMult(T, positions_homog);
}
typedef empty_env_t env_t_229;


value_t lambda229(env_t_229* env219, array_array_number_t m1, array_array_number_t m2) {
	
	value_t res;
	res.array_array_number_t_value = TOP_LEVEL_linalg_matrixMult(m1, m2);
	return res;
}
array_array_number_t TOP_LEVEL_usecases_ht_get_skinned_vertex_positions(index_t is_mirrored, card_t n_bones, array_array_number_t pose_params, array_array_array_number_t base_relatives, array_number_t parents, array_array_array_number_t inverse_base_absolutes, array_array_number_t base_positions, array_array_number_t weights) {
	array_array_array_number_t relatives = TOP_LEVEL_usecases_ht_get_posed_relatives(n_bones, pose_params, base_relatives);
	array_array_array_number_t absolutes = TOP_LEVEL_usecases_ht_relatives_to_absolutes(relatives, parents);
	env_t_229 env_t_229_value = make_empty_env(); closure_t closure221 = make_closure(lambda229, &env_t_229_value);
	array_array_array_number_t transforms = TOP_LEVEL_linalg_matrix3DMap2(closure221, absolutes, inverse_base_absolutes);
	card_t macroDef222 = base_positions->arr[0]->length;
	card_t n_verts = macroDef222;
	array_array_number_t init_positions = TOP_LEVEL_linalg_matrixFill(3, n_verts, 0);
	card_t macroDef224 = transforms->length;
	array_array_number_t macroDef225 = init_positions;
	for(int i_transform = 0; i_transform < macroDef224; i_transform++){
		array_array_number_t curr_positions = TOP_LEVEL_linalg_matrixMult(matrix_slice(transforms->arr[i_transform], 0, 2), base_positions);
		card_t macroDef223 = base_positions->length;
		array_array_number_t w = TOP_LEVEL_linalg_matrixFillFromVector(macroDef223, weights->arr[i_transform]);
		macroDef225 = TOP_LEVEL_linalg_matrixAdd(macroDef225, TOP_LEVEL_linalg_matrixMultElementwise(curr_positions, w));;
	}
	array_array_number_t positions = macroDef225;
	array_array_number_t mirrored_positions = 0;
	if((is_mirrored) == (1)) {
		array_number_t array226 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array226->length=3;
	array226->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array226->arr[0] = -1;
	array226->arr[1] = 0;
	array226->arr[2] = 0;;
		array_number_t array227 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array227->length=3;
	array227->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array227->arr[0] = 0;
	array227->arr[1] = 1;
	array227->arr[2] = 0;;
		array_number_t array228 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array228->length=3;
	array228->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array228->arr[0] = 0;
	array228->arr[1] = 0;
	array228->arr[2] = 1;;
		array_array_number_t mirror_matrix = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	mirror_matrix->length=3;
	mirror_matrix->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * 3);
	mirror_matrix->arr[0] = array226;
	mirror_matrix->arr[1] = array227;
	mirror_matrix->arr[2] = array228;;
		mirrored_positions = TOP_LEVEL_linalg_matrixMult(mirror_matrix, positions);;
	} else {
		
		mirrored_positions = positions;;
	}
	return TOP_LEVEL_usecases_ht_apply_global_transform(pose_params, mirrored_positions);
}
typedef struct env_t_238 {
	array_array_number_t vertex_positions;
	array_array_number_t points;
	index_t n_corr;
	array_number_t correspondences;
} env_t_238;
env_t_238 make_env_t_238(array_array_number_t vertex_positions,array_array_number_t points,index_t n_corr,array_number_t correspondences) {
	env_t_238 env;
	env.vertex_positions = vertex_positions;
	env.points = points;
	env.n_corr = n_corr;
	env.correspondences = correspondences;
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
array_number_t TOP_LEVEL_usecases_ht_hand_objective(index_t is_mirrored, array_number_t param, array_number_t correspondences, array_array_number_t points, card_t n_bones, array_array_array_number_t base_relatives, array_number_t parents, array_array_array_number_t inverse_base_absolutes, array_array_number_t base_positions, array_array_number_t weights) {
	array_array_number_t pose_params = TOP_LEVEL_usecases_ht_to_pose_params(param, n_bones);
	array_array_number_t vertex_positions = TOP_LEVEL_usecases_ht_get_skinned_vertex_positions(is_mirrored, n_bones, pose_params, base_relatives, parents, inverse_base_absolutes, base_positions, weights);
	card_t macroDef230 = correspondences->length;
	card_t n_corr_card = macroDef230;
	index_t n_corr = (n_corr_card);
	env_t_238 env_t_238_value = make_env_t_238(vertex_positions,points,n_corr,correspondences); closure_t closure237 = make_closure(lambda238, &env_t_238_value);
	array_number_t err = TOP_LEVEL_linalg_vectorMap(closure237, TOP_LEVEL_linalg_vectorRange(0, (((n_corr_card) + (n_corr_card)) + (n_corr_card)) - (1)));
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
	array_number_t array242 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array242->length=3;
	array242->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array242->arr[0] = 1;
	array242->arr[1] = 2;
	array242->arr[2] = 3;;
	array_number_t array243 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array243->length=3;
	array243->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array243->arr[0] = 4;
	array243->arr[1] = 5;
	array243->arr[2] = 6;;
	array_number_t array244 = (array_number_t)storage_alloc(sizeof(int) * 2);
	array244->length=3;
	array244->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	array244->arr[0] = 7;
	array244->arr[1] = 8;
	array244->arr[2] = 9;;
	array_array_number_t mat1 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	mat1->length=3;
	mat1->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * 3);
	mat1->arr[0] = array242;
	mat1->arr[1] = array243;
	mat1->arr[2] = array244;;
	array_array_number_t macroDef240 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef240->length=4;
	macroDef240->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * 4);
		for(int i = 0; i < macroDef240->length; i++){
			array_number_t macroDef239 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef239->length=4;
	macroDef239->arr = (number_t*)storage_alloc(sizeof(number_t) * 4);
		for(int j = 0; j < macroDef239->length; j++){
			
			macroDef239->arr[j] = (double)((((i) + (1)) * (4)) + (j));;
		}
			macroDef240->arr[i] = macroDef239;;
		}
	array_array_number_t base_rel = macroDef240;
	array_array_number_t q = TOP_LEVEL_usecases_ht_make_relative(a, base_rel);
	matrix_print(q);
	array_array_number_t r = TOP_LEVEL_usecases_ht_angle_axis_to_rotation_matrix(a);
	matrix_print(r);
	array_array_number_t s = TOP_LEVEL_usecases_ht_apply_global_transform(mat1, mat1);
	matrix_print(s);
	return ;
}
#endif
