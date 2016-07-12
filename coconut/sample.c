#include "linalg.h"

int main()
{
	// linalg_test1(NULL);
	timer_t t = tic();
	linalg_run_ba_from_file("../ba.txt");
	toc(t);
	return 0;
}