/*
Write code to implement the following function:
Return 1 when x contains an odd number of 1s; 0 otherwise. Assume w=32
int odd_ones(unsigned x);
*/

#include <stdio.h>
#include <stdint.h>

int odd_ones(uint32_t x);

int main()
{
	uint32_t x;

	printf("\nEnter a 32 bit number: ");
	scanf("%d", &x);

	printf("\nDoes %d have an odd number of toggled bits? %d\n", x, odd_ones(x));

	return 0;
}

/* Return 1 when x contains an odd number of 1s; 0 otherwise. Assume w=32 */
int odd_ones(uint32_t x)
{
	x ^= x >> 16;
	x ^= x >> 8;
	x ^= x >> 4;
	x ^= x >> 2;
	x ^= x >> 1;

	return x & 0x1;
}
