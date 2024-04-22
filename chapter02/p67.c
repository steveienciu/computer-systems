/*
You are given the task of writing a procedure int_size_is_32() that yields 1
when run on a machine for which an int is 32 bits, and yields 0 otherwise. You are
not allowed to use the sizeof operator.
*/

#include <stdio.h>
#include <stdint.h>

/* see if machine is 32 bits. can change the bit size of the integer to test if it works properly */
int int_size_is_32();

int main()
{
	printf("\nIs the machine 32 bits? %d\n", int_size_is_32());

	return 0;
}

int int_size_is_32()
{
	/* set most significant bit of 32 bit number */
	uint64_t set_msb = 1 << 31;
	
	/* shift past msb of 32 bit word */
	uint64_t beyond_msb = set_msb << 1;

	return set_msb && !beyond_msb;
}
