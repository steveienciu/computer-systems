/* 
Write code to implement the following function:
Generate mask indicating leftmost 1 in x. Assume w=32.
For example, 0xFF00 -> 0x8000, and 0x6600 --> 0x4000.
If x = 0, then return 0.
int leftmost_one(unsigned x);
*/

#include <stdio.h>
#include <stdint.h>

int leftmost_one(uint32_t x);

int main()
{

	uint32_t x;

	printf("\nEnter a 32 bit integer: ");
	scanf("%d", &x);
	
	/* print the hex version of the unsigned values */
	printf("\nThe answer for %x is %x\n", x, leftmost_one(x));

	return 0;
}

/*
* Generate mask indicating leftmost 1 in x. Assume w=32.
* For example, 0xFF00 -> 0x8000, and 0x6600 --> 0x4000.
* If x = 0, then return 0.
*/
int leftmost_one(uint32_t x)
{
	/* get the bit string in the form [0...011...1] */
	x |= x >> 1;
	x |= x >> 2;
	x |= x >> 4;
	x |= x >> 8;
	x |= x >> 16;

	/* shift the result by 1 so can iso the leftmost bit then xor */
	x ^= x >> 1;

	return x;
}
