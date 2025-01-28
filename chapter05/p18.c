#include <stdio.h>

#define N 20

double poly(double a[], double x, long degree);
double o_poly(double a[], double x, long degree);

int main()
{
	int limit = 100000000;
	double a[N];
	double x = 3;

	for (int i = 0; i < N; ++i) {
		a[i] = i + 1;
	}

	for (int i = 0; i < limit; ++i) {
		poly(a, x, N);
	}

	for (int i = 0; i < limit; ++i) {
		o_poly(a, x, N);
	}

	return 0;
}

double poly(double a[], double x, long degree)
{
	long i;
	double result = a[0];
	double xpwr = x;

	for (i = 1; i <= degree; ++i) {
		result += a[i] * xpwr;
		xpwr *= x;
	}

	return result;
}

double o_poly(double a[], double x, long degree)
{
	long i;
	long limit = degree - 3;
	double r1 = a[0];
	double r2 = 0;
	double r3 = 0;
	double x1 = x;
	double x2 = x * x;
	double x3 = x * x * x;
	double xpwr = x * x * x;

	for (i = 1; i <= limit; i+=3) {
		r1 += a[i] * x1;
		r2 += a[i+1] * x2;
		r3 += a[i+2] * x3;

		x1 *= xpwr;
		x2 *= xpwr;
		x3 *= xpwr; 
	}

	for ( ; i < degree; ++i) {
		r1 += a[i] * x1;
		x1 *= x;
	}

	return r1 + r2 + r3;
}
