/*
 * 16.2.c -- The harmonic mean of two numbers is obtained by taking the
 * inverses of the two numbers, averaging them, and taking the inverse of the
 * result. Use a #define directive to define a macro “function” that performs
 * this operation. Write a simple program that tests the macro. 
 */

#include <stdio.h>
#define HARMONIC(X, Y) (2.0 / ((1.0 / (X)) + (1.0 / (Y))))

int main(void)
{
	double result;
	result = HARMONIC(2, 3.5);
	printf("%g\n", result);
	result = HARMONIC(2 + 3, 3.5 + 12);
	printf("%g\n", result);

	return 0;
}
