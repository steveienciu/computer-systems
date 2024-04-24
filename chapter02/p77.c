/*
Suppose we are given the task of generating code to multiply integer variable x
by various different constant factors K. To be efficient, we want to use only the
operations +, -, and <<. For the following values of K, write C expressions to
perform the multiplication using at most three operations per expression.
A. K = 17
B. K = −7
C. K = 60
D. K = −112
*/

#include <stdio.h>

int main()
{
	int x = 10;
	int k1 = 17, k2 = -7, k3 = 60, k4 = -112;

	int shift1 = (x << 4) + x;
	int shift2 = x - (x << 3);
	int shift3 = (x << 6) - (x << 2);
	int shift4 = (x << 4) - (x << 7);

	printf("\nshift1=%d m1=%d", shift1, x * k1);
	printf("\nshift2=%d m2=%d", shift2, x * k2);
	printf("\nshift3=%d m3=%d", shift3, x * k3);
	printf("\nshift4=%d m4=%d\n", shift4, x * k4);

	return 0;
}
