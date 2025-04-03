/* How many “Example” output lines does this program print? */

#include "csheader/csapp.h"

int main()
{
	int i;

	for (i = 3; i > 0; --i) {
		Fork();
	}
	printf("Example\n");

	exit(0);
}

/* 
 *
 * this prints example 8 times
 * everything single time we enter the loop, the number of processes doubles
 */
