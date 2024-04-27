/*
Write C expressions to generate the bit patterns that follow, where a k represents
k repetitions of symbol a. Assume a w-bit data type. Your code may contain
references to parameters j and k, representing the values of j and k, but not a
parameter representing w.
A. 1^(w−k)0^k
B. 0^(w−k−j)1^k0^j
*/

#include <stdio.h>

/* computes part a */
int parta(int k);
/* computes part b */
int partb(int k, int j);

int main()
{
	/* for part a */
	printf("Bit string is: %x", parta(8));
	/* for part b */
	printf("\nBit string is: %x\n", partb(4, 8));

	return 0;
}

int parta(int k)
{
	/* get bit string that contains all 1's */
	int x = -1;

	/* shift by k to get the proper number of 0's */
	return (x << k);
}

int partb(int k, int j)
{
	/* get bit string that contains all 1's */
	int x = -1;

	/* get the proper bit string */
	int mask1 = x << j;
	int mask2 = (x << (j + k)) ^ x;
	
	return (mask1 & mask2);
}
