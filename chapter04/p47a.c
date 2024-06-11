/*

write bubble sort code that references the array elements with pointers

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
			if (*(i + 1) < *i) {
				/* swap adjacent elements */
				long t = *(i + 1);
				*(i + 1) = *i;
				*i = t;
			}
		}
	}
}	
