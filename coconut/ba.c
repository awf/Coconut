#include "usecases_ba.h"

int main(int argc, char** argv)
{
	if(argc != 2) {
		printf("You should use the following format for running this program: %s <folder containing the input data>\n", argv[0]);
		exit(1);
	}
	char* file = argv[1];
	TOP_LEVEL_usecases_ba_run_ba_from_file(file);
	float milliseconds = (float)(benchmarked_time) * 1000.0 / CLOCKS_PER_SEC;
	printf("Profiled Time: %d ms\n", (int)milliseconds);
	// printf("memory of closure: %d\n", closure_mem);
	return 0;
}