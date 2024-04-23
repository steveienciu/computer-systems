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
* Return 1 when x can be represented as an n-bit, 2’s-complement
* number; 0 otherwise
* Assume 1 <= n <= w
*/
int32_t fits_bits(int32_t x, int32_t n);

int main()
{
	int32_t x, n;

	printf("\nEnter a 32 bit integer: ");
	scanf("%d", &x);

	printf("Enter number of bits to see if that integer can fit: ");
	scanf("%d", &n);

	printf("\nThe answer is %d.\n", fits_bits(x, n));

	return 0;
}

int32_t fits_bits(int32_t x, int32_t n)
{
	/* will be used for positive numbers; checks to see if msb is 1 ignoring the sign bit */	
	int32_t result1 = x >> (n - 1);
	/* will be used for negative numbers; does the same thing as result1 */
	int32_t result2 = x >> (n - 1);

	return result1 == 0 || result2 == -1;
}
