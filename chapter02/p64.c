/* Write code to implement the following function:
Return 1 when any odd bit of x equals 1; 0 otherwise. Assume w=32
int any_odd_one(unsigned x);
*/

#include <stdio.h>
#include <stdint.h>

int any_odd_one(uint32_t x);

int main()
{
	uint32_t x;
	int result;

	printf("\nPlease enter a 32 bit integer: ");
	scanf("%d", &x);

	result = any_odd_one(x);

	printf("\nDoes %d have any odd bits with a 1? %d\n", x, result);

	return 0;
}

int any_odd_one(uint32_t x)
{
	/* bit mask with 1's in all odd bit positions */
	uint32_t mask = 0x55555555;

	/* take and of the numbers */
	int32_t result = x & mask;

	return result;
}
