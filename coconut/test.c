#include "usecases_ba.h"
#include "programs.h"
#include "ccodegentests.h"

int main(int argc, char** argv)
{
	TOP_LEVEL_usecases_ba_test_ba(0);
	printf("---small tests---\n");
	TOP_LEVEL_programs_small_tests(0);
	return 0;
}