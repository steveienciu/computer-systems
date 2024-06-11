/*

modify code from p47a where the test and swap portion uses no jumps and has at most three conditional moves

*/

#include <stdio.h>

void bubble_p(long *data, long count);

int main()
{
	long data[5] = { 3, 6, 2, 8, 1 };

	bubble_p(data, 5);

	for (int i = 0; i < 5; ++i) {
		printf("%ld ", data[i]);
	}
	printf("\n");

	return 0;
}

void bubble_p(long *data, long count) 
{
	long *i, last;

	for (last = count - 1; last > 0; --last) {
		for (i = data; i < (data + last); ++i) { 
			/* test and swap */
			int condition = (*(i + 1) < *i);
			long t = condition ? *(i + 1) : 0;
			*(i + 1) = condition ? *i : *(i + 1);
			*i = condition ? t : *i;
		}
	}
}	
