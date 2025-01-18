#include <stdio.h>
#include <stdlib.h>

void *o_memset(void *s, int c, size_t n);
void *basic_memset(void *s, int c, size_t n);

int main()
{
	int c = 0xff;
	size_t n = 999999;
	size_t arr_size = n * sizeof(int);
	int limit = 10000;
	int *s = malloc(arr_size);
	if (!s) {
		printf("malloc error");
		return 1;
	}

	for (int i = 0; i < limit; ++i) {
		o_memset(s, c, arr_size);
	}

	for (int i = 0; i < limit; ++i) {
		basic_memset(s, c, arr_size);
	}


	free(s);

	return 0;
}

/* optimizated version of basic_memset which took 1.04 ms to run */
void *o_memset(void *s, int c, size_t n)
{
	size_t cnt = 0;
	unsigned char *schar = s;
	size_t k = sizeof(unsigned long);
	size_t adr_val = (size_t) schar;

	// get address aligned 
	while ((cnt < n) && (adr_val % k != 0)) {
		*schar++ = (unsigned char) c;
		cnt++;
	}

	// translate c to a long
	unsigned long c_l = (unsigned char) c;
	for (size_t i = 1; i < k; i *= 2) {
		c_l += (c_l << (i * k));
	}

	// translate the array to long and add 8 bytes at a time into the array
	unsigned long *slong = (unsigned long*) schar;
	size_t limit = n - cnt - k;
	for ( ; cnt < limit; cnt += k) {
		*slong++ = c_l;
	}
	
	// finish remaining writes to array
	schar = (unsigned char *) slong;
	for ( ; cnt < n; ++cnt) {
		*schar++ = (unsigned char) c;
	}

	return s;
}

/* basic memset implementation with no optimization which took 3.43ms to run */
void *basic_memset(void *s, int c, size_t n)
{
	size_t cnt = 0;
	unsigned char *schar = s;

	while (cnt < n) {
		*schar++ = (unsigned char) c;
		cnt++;
	}

	return s;
}
