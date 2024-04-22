/*
Write code for a function with the following prototype:
Do rotating left shift. Assume 0 <= n < w
Examples when x = 0x12345678 and w = 32:
n=4 -> 0x23456781, n=20 -> 0x67812345
unsigned rotate_left(unsigned x, int n);
*/

#include <stdio.h>
#include <stdint.h>

/*
Do rotating left shift. Assume 0 <= n < w
Examples when x = 0x12345678 and w = 32:
n=4 -> 0x23456781, n=20 -> 0x67812345
*/
uint32_t rotate_left(unsigned x, uint32_t n);

int main()
{
	uint32_t x, n;

	printf("\nEnter a hexadecimal number: ");
	scanf("%x", &x);

	printf("Enter a number to left rotate shift by: ");
	scanf("%d", &n);

	printf("\nThe left rotate shift of %x by %d is %x.\n", x, n, rotate_left(x, n));

	return 0;
}

uint32_t rotate_left(uint32_t x, uint32_t n)
{
	/* use to iso the bits that get shifted of */
	uint32_t right_shift = 31 - n;
	uint32_t right_result = x >> right_shift;
	right_result >>= 1;

	/* left shift the regular value */
	x <<= n;

	/* xor the left shift with the isoed part */
	uint32_t result = x ^ right_result;

	return result;
}
