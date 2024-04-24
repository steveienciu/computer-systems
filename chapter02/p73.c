/*
Write code for a function with the following prototype:
Addition that saturates to TMin or TMax
int saturating_add(int x, int y);
*/

#include <stdio.h>
#include <limits.h>

/* Addition that saturates to TMin or TMax */
int saturating_add(int x, int y);

int main()
{
	int x, y;

	printf("\nEnter two integers to add: ");
	scanf("%d %d", &x, &y);

	printf("\n%d + %d = %d\n", x, y, saturating_add(x, y));

	return 0;
}

int saturating_add(int x, int y)
{
	/* find word size in bits; INT_MIN and INT_MAX are 32 bit words */
	int w = sizeof(int) << 3;

	/* get the sum which might overflow */
	int result = x + y;

	/* logic to find if there is an overflow */
	int overflow = ((x ^ result) & (y ^ result) & INT_MIN) >> (w - 1);

	/* decide whether overflow is positive or negative; both will be zero if no overflow occured */
	int pos_overflow = ~(x >> (w - 1)) & ~(y >> (w - 1)) & (result >> (w - 1));
	int neg_overflow = (x >> (w - 1)) & (y >> (w - 1)) & ~(result >> (w - 1));

	/* find the proper sum */
	int sat_result = (INT_MIN & neg_overflow) | (INT_MAX & pos_overflow) | (result & ~overflow);

	return sat_result;
}
