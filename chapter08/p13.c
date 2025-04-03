#include "csheader/csapp.h"

int main()
{
	int a = 5;

	if (Fork() != 0) {
		printf("a=%d\n", --a);
	}

	printf("a=%d\n", ++a);
	exit(0);
}

/* 
 * one possible output is:
 * a=4
 * a=5
 * a=6
 */
