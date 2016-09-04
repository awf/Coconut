#include "usecases.h"
#include "programs.h"
#include "ccodegentests.h"

int main(int argc, char** argv)
{
	TOP_LEVEL_usecases_test1(0);
	printf("---small tests---\n");
	TOP_LEVEL_programs_small_tests(0);
	return 0;
}