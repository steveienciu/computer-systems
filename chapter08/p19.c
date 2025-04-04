/* How many lines of output does the following function print if the value of n
entered by the user is 6? */

#include "csheader/csapp.h"

void foo(int n)
{
	int i;

	for (i = n - 1; i >= 0; i -= 2) {
		Fork();
	}
	printf("hello\n");

	exit(0);
}

int main()
{
	int n = 6;

	foo(n);

	exit(0);
}

/* this will print 8 lines onto stdout. it will loop 3 times and double the number of processes
 * each time
 */
