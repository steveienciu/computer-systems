/* What is the output of the following program? */

#include "csheader/csapp.h"

int counter = 1;

int main()
{
	if (Fork() == 0) {
		counter++;
		exit(0);
	}
	else {
		Wait(NULL);
		counter++;
		printf("counter=%d\n", counter);
	}
	exit(0);
}

/* 
 * this will output 
 * counter=2
 */
