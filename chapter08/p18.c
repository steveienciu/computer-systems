/*
 * Determine which of the following outputs are possible
 * A. 112002
 * B. 211020
 * C. 102120
 * D. 122001
 * E. 100212
 */

#include "csheader/csapp.h"

void end(void)
{
	printf("2"); fflush(stdout);
}

int main()
{
	if (Fork() == 0) {
		atexit(end);
	}
	if (Fork() == 0) {
		printf("0"); fflush(stdout);
	}
	else {
		printf("1"); fflush(stdout);
	}
	exit(0);
}

/*
 * the possible outcomes are:
 * A, C, and E
 * B not possible since the child process that gets created in the first fork will hit the else 
 * statement printing a 1 before it prints a 2. Same can be said for the child process the first 
 * child makes. It will print a 0 before it prints a 2
 * D is not possible for kind of the same reason as B. Cannot have back to back 2s printed since
 * the process will need to print a 1 or 0 before a 2
 */
