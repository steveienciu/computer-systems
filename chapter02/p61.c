/* Write C expressions that evaluate to 1 when the following conditions are true and
to 0 when they are false. Assume x is of type int.
	A. Any bit of x equals 1.
	B. Any bit of x equals 0.
	C. Any bit in the least significant byte of x equals 1.
	D. Any bit in the most significant byte of x equals 0.
*/

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

void answers(int32_t x);

int main()
{
	int32_t x;

	printf("\nEnter an integer: ");
	scanf("%d", &x);
	
	answers(x);

	return 0;
}

void answers(int32_t x)
{
	/* bit masks to use for the 4 results */
	uint32_t mask1 = 0xffffffff, mask2 = 0x000000ff, mask3 = 0xff000000;

	int32_t result1 = x & mask1;
	int32_t result2 = ~(x & mask1);
	int32_t result3 = x & mask2;
	int32_t result4 = (x | ~mask3) & mask3;

	bool final1 = (bool) result1;
	bool final2 = (bool) result2;
	bool final3 = (bool) result3;
	bool final4 = (bool) result4;

	printf("\nAny bit of %d equals 1? %d", x, final1);
	printf("\nAny bit of %d equals 0? %d", x, final2);
	printf("\nAny bit in the least significant byte of %d equals 1? %d", x, final3);
	printf("\nAny bit in the most significant byte of %d equals 0? %d\n", x, final4);
}
