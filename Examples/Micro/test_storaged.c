#include "../../outputs/C/linalgtests_storaged.h"
#include "../../outputs/C/usecases_ba_storaged.h"

int main(int argc, char** argv)
{
	TOP_LEVEL_usecases_ba_test_ba_dps(0, 0, 0);
	printf("---linalg tests---\n");
	TOP_LEVEL_linalgtests_test1_dps(0, 0, 0);
	return 0;
}