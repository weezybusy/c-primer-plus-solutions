/*
 * 14.11.c -- Write a function called transform() that takes four arguments:
 * the name of a source array containing type double data, the name of a
 * target array of type double, an int representing the number of array
 * elements, and the name of a function (or, equivalently, a pointer to a
 * function). The transform() function should apply the indicated function
 * to each element in the source array, placing the return value in the target
 * array. For example, the call
 *	
 * 	transform(source, target, 100, sin);
 *
 * would set target[0] to sin(source[0]), and so on, for 100 elements. Test the
 * function in a program that calls transform() four times, using two functions
 * from the math.h library and two suitable functions of your own devising as
 * arguments to successive calls of the transform() function.
 */

#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#define SIZE 100

void transform(double [], double [], int, double (*fp)(double));

int main(void)
{
	double source[SIZE];
	double target[SIZE];

	srand(time(NULL));
	for (int i = 0; i < SIZE; i++) {
		source[i] = rand() % 100 + 1;
		printf("original: %5.2f\n", source[i]);
	}

	transform(source, target, SIZE, sqrt);
	transform(source, target, SIZE, fabs);
	transform(source, target, SIZE, log10);
	transform(source, target, SIZE, cbrt);

	return 0;
}

void transform(double s[], double t[], int n, double (*fp)(double))
{
	for (int i = 0; i < n; i++) {
		t[i] = fp(s[i]);
		printf("%2d) %.2f\n", i + 1, t[i]);
	}
	putchar('\n');
}
