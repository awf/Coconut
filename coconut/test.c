#include "linalg.h"
#include "programs.h"

int main(int argc, char** argv)
{
	linalg_test1(0);
	printf("---small tests---\n");
	programs_small_tests(0);
	return 0;
}