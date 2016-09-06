#include "linalgtests_storaged.h"
// #include "usecases_ba_storaged.h"

int main(int argc, char** argv)
{
	vector_shape_t dum;
	dum.card = 0;
	TOP_LEVEL_linalgtests_test1_s(0, 0, dum);
	// TOP_LEVEL_usecases_ba_test_ba_s(0, 0, dum);
	return 0;
}