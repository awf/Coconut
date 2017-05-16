#include "../../outputs/C/usecases_ba.h"
#include "../../outputs/C/programs.h"
#include "../../outputs/C/ccodegentests.h"

int main(int argc, char** argv)
{
	TOP_LEVEL_usecases_ba_test_ba(0);
	printf("---small tests---\n");
	TOP_LEVEL_programs_small_tests(0);
	printf("1+...+10=%d\n", (int)TOP_LEVEL_ccodegentests_numSum(10));
	return 0;
}