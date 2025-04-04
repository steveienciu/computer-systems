/* What are the possible output sequences from the following program? */

#include "csheader/csapp.h"

int main()
{
	printf("p"); fflush(stdout);

	if (Fork() != 0) {
		printf("q"); fflush(stdout);
		return 0;
	}
	else {
		printf("r"); fflush(stdout);
		waitpid(-1, NULL, 0);
	}

	return 0;
}

/*
 * possible results are: pqr and prq
 */
