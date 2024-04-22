/* 
Write code for a function with the following prototype:
Mask with least signficant n bits set to 1
Examples: n = 6 --> 0x3F, n = 17 --> 0x1FFFF
Assume 1 <= n <= w
int lower_one_mask(int n);
*/

#include <stdio.h>
#include <stdint.h>

/*
* Mask with least signficant n bits set to 1
* Examples: n = 6 --> 0x3F, n = 17 --> 0x1FFFF
* Assume 1 <= n <= w
*/
int lower_one_mask(int n);

int main()
{
	int n;

	printf("\nEnter an integer between 1 and 32: ");
	scanf("%d", &n);

	printf("The result is %x.\n", lower_one_mask(n));

	return 0;
}

int lower_one_mask(int n)
{
	uint32_t mask = 0xffffffff;

	/* shift by reverse of what user wants to the right */
	uint32_t result = mask >> (32 - n);

	return result;
}
