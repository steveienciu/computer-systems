/*
Write code for a function mul3div4 that, for integer argument x, computes 3*x/4
and you our code should replicate the fact that the computation 3*x can
cause overflow.
*/

#include <stdio.h>
#include <limits.h>

/* function created from previous section */
int divide_power2(int x, int k);
/* check for possible overflow */
int overflow_check(int x, int result, int w);
/* computes (3*x)/4 */
int mul3div4(int x);

int main()
{
	int x;

	printf("This code will find (3*x)/4. Enter an integer: ");
	scanf("%d", &x);

	printf("(3*%d)/4=%d\n", x, mul3div4(x));

	return 0;
}

int divide_power2(int x, int k)
{
	/* find size of integer in bits */
	int w = sizeof(int) << 3;
	/* find the sign of the integer */
	int sign_of_x = x >> (w - 1);
	/* bias the integer by some specific number */
	int mask = sign_of_x & ((1 << k) - 1);
	/* get the proper result */
	int result = (x + mask) >> k;

	return result;
}

int overflow_check(int x, int result, int w)
{
	/* check to see if there is overflow */
	int overflow = (x ^ result) >> (w - 1);
	/* decide whether overflow postive or negative; both will be zero if no overflow occured */
	int pos_overflow = ~(x >> (w - 1)) & (result >> (w - 1));
	int neg_overflow = (x >> (w - 1)) & ~(result >> (w - 1));

	/* find proper value */
	int sat_result = (INT_MIN & neg_overflow) | (INT_MAX & pos_overflow) | (result & ~overflow);

	return sat_result;
}

int mul3div4(int x)
{
	/* the power of two that we are dividing by */
	int k = 2;
	/* size of integer */
	int w = sizeof(int) << 3;

	/* perform the multiplication */
	int mult = x << 1;
	mult = overflow_check(x, mult, w);
	mult += x;
	mult = overflow_check(x, mult, w);
	/* perform the division */
	int div = divide_power2(mult, k);

	return div;
}
