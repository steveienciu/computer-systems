#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10000

void transpose(int *dst, int *src, int dim);
void o_transpose(int *dst, int *src, int dim);

int main()
{
	// using timer instead of gprof... takes too long sometimes 
	clock_t start, end;
	double time_taken;

	// check if memory allocated
	int *dst = malloc(N * N * sizeof(int));
	if (dst == NULL) {
		printf("Allocation for dst failed.\n");
		return 1;
	}

	// check if memory allocated
	int *src = malloc(N * N * sizeof(int));
	if (src == NULL) {
		free(dst);
		printf("Allocation for src failed.\n");
		return 1;
	}

	// fill up arrays with values
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			dst[i*N+j] = j+1;
			src[i*N+j] = j+2;
		}
	}

	start = clock();
	transpose(dst, src, N);
	end = clock();

	time_taken = ((double)(end-start))/CLOCKS_PER_SEC;

	printf("\nTime taken for unoptimized: %f seconds\n\n", time_taken);

	start = clock();
	o_transpose(dst, src, N);
	end = clock();

	time_taken = ((double)(end-start))/CLOCKS_PER_SEC;

	printf("Time taken for optimized: %f seconds\n\n", time_taken);

	free(dst);
	free(src);

	return 0;
}	

/*
 * time taken to run: 4.60s
 */
void transpose(int *dst, int *src, int dim)
{
	int i, j;

	for (i = 0; i < dim; ++i) {
		for (j = 0; j < dim; ++j) {
			dst[j*dim + i] = src[i*dim + j];
		}
	}
}

/*
 * time take to run: 0.48
 */
void o_transpose(int *dst, int *src, int dim)
{
	int i, j;
	int limit = dim-18;
	int addr0, addr1, addr2, addr3, addr4, addr5, addr6, addr7, addr8, addr9, addr10, addr11, addr12, addr13, addr14, addr15, addr16, addr17;
	int addrj;

	for (i = 0; i < limit; i+=18) {
		// this is done dim amount of times if kept in second loop
		// take out to first loop to improve efficiency 
		addr0 = i*dim;
		addr1 = (i+1)*dim;
		addr2 = (i+2)*dim;
		addr3 = (i+3)*dim;
		addr4 = (i+4)*dim;
		addr5 = (i+5)*dim;
		addr6 = (i+6)*dim;
		addr7 = (i+7)*dim;
		addr8 = (i+8)*dim;
		addr9 = (i+9)*dim;
		addr10 = (i+10)*dim;
		addr11 = (i+11)*dim;
		addr12 = (i+12)*dim;
		addr13 = (i+13)*dim;
		addr14 = (i+14)*dim;
		addr15 = (i+15)*dim;
		addr16 = (i+16)*dim;
		addr17 = (i+17)*dim;
		for (j = 0; j < dim; ++j) {
			addrj = j*dim; // do it once here instead of 18 times inside the arrays
			dst[addrj+i] = src[addr0+j];
			dst[addrj+i+1] = src[addr1+j];
			dst[addrj+i+2] = src[addr2+j];
			dst[addrj+i+3] = src[addr3+j];
			dst[addrj+i+4] = src[addr4+j];
			dst[addrj+i+5] = src[addr5+j];
			dst[addrj+i+6] = src[addr6+j];
			dst[addrj+i+7] = src[addr7+j];
			dst[addrj+i+8] = src[addr8+j];
			dst[addrj+i+9] = src[addr9+j];
			dst[addrj+i+10] = src[addr10+j];
			dst[addrj+i+11] = src[addr11+j];
			dst[addrj+i+12] = src[addr12+j];
			dst[addrj+i+13] = src[addr13+j];
			dst[addrj+i+14] = src[addr14+j];
			dst[addrj+i+15] = src[addr15+j];
			dst[addrj+i+16] = src[addr16+j];
			dst[addrj+i+17] = src[addr17+j];
		}
	}

	// complete the remaining transposes
	for ( ; i < dim; ++i) {
		for (j = 0; j < dim; ++j) {
			dst[j*dim+i] = src[i*dim+j];
		}
	}
}
