#include "../../outputs/C/linalg_d.h"
#include "../../outputs/C/usecases_gmm_opt_d.h"

int main(int argc, char** argv)
{
	array_number_t v1 = TOP_LEVEL_linalg_vec3(1, 2, 3);
	array_number_t v2 = TOP_LEVEL_linalg_vec3(3, 5, 6);
	array_number_t v1_d = TOP_LEVEL_linalg_vec3_d(1, 2, 3, 3, 0, 4);
	array_number_t v2_d = TOP_LEVEL_linalg_vec3_d(3, 5, 6, 7, 8, 10);
	array_print(v1_d);
	array_print(v2_d);
	array_number_t v3_d = TOP_LEVEL_linalg_vectorAdd_d(v1, v2, v1_d, v2_d);
	array_print(v3_d);
	return 0;
}