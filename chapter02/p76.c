/*
The library function calloc has the following declaration:
void *calloc(size_t nmemb, size_t size);
Write an implementation of calloc that performs the allocation by a call to
malloc and sets the memory to zero via memset. Your code should not have any
vulnerabilities due to arithmetic overflow, and it should work correctly regardless
of the number of bits used to represent data of type size_t
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

void *my_calloc(size_t nmemb, size_t size);

int main()
{
	/* test to see if things get initialized to 0 */
	int *array = my_calloc(8, sizeof(int));
	if (array == NULL) {
		fprintf(stderr, "Allocation failed.\n");
		return 1;
	}

	for (int i = 0; i < 8; ++i) {
		printf("%d ", array[i]);
	}
	printf("\n");

	return 0;
}

void *my_calloc(size_t nmemb, size_t size)
{
	if (nmemb == 0 || size == 0) {
		return NULL;
	}

	size_t bytes = nmemb * size;
	if ((bytes << 3) < UINT64_MAX) {
		void *ptr = malloc(bytes);
		if (ptr == NULL) {
			return NULL;
		}
		memset(ptr, 0, bytes);
		return ptr;
	}

	return NULL;
}
