/*

modify code from p47a where the test and swap portion uses no jumps and has just one conditional move

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
			/* find the larger number */
			int condition = (*(i + 1) < *i) ? *i : *(i + 1);
			/* find the smaller value */
			*i = *i ^ condition ^ *(i + 1);
			/* i + 1 will always be the larger value */
			*(i + 1) = condition;
		}
	}
}	
