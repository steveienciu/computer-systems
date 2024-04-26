/*
Write code for a function with the following prototype:
Divide by power of 2. Assume 0 <= k < w-1
int divide_power2(int x, int k);
The function should compute x/2^k with correct rounding
*/

#include <stdio.h>

/* Divide by power of 2. Assume 0 <= k < w-1 */
int divide_power2(int x, int k);

int main()
{
	int x, k;

	printf("Please enter an integer: ");
	scanf("%d", &x);

	printf("What power of 2 do you want to divide by: ");
	scanf("%d", &k);

	printf("\nThe answer is %d.\n", divide_power2(x, k));

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
