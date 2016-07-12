#include "linalg.h"

int main(int argc, char** argv)
{
	if(argc != 2) {
		printf("You should use the following format for running this program: %s <folder containing the input data>\n", argv[0]);
		exit(1);
	}
	char* file = argv[1];
	linalg_run_ba_from_file(file);
	// printf("memory of closure: %d\n", closure_mem);
	return 0;
}