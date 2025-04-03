/* How many “Example” output lines does this program print? */

#include "csheader/csapp.h"

void try()
{
	Fork();
	printf("Example\n");
	Fork();
	return;
}

int main()
{
	try(); Fork();
	printf("Example\n");
	exit(0);
}

/*
 * example will be outputted 10 times
 */
