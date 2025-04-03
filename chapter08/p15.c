/* How many “Example” lines does this program print? */

#include "csheader/csapp.h"

void try()
{
	if (Fork() == 0) {
		Fork(); Fork();
		printf("Example\n");
		return;
	}
	return;
}

int main()
{
	try();
	printf("Example\n");
	exit(0);
}

/*
 * this will output example 9 times
 */
