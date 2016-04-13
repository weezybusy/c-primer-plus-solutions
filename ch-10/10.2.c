/*
 * 10.2.c -- copying of arrays
 */

#include <stdio.h>

void copy_arr(double from[], double to[], int n);
void copy_ptr(double * from, double * to, int n);

int main(void)
{
	double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
	double target1[5];
	double target2[5];

	copy_arr(source, target1, 5);
	copy_ptr(source, target2, 5);

	for (int i = 0; i < 5; i++)
	{
		printf("%.1f ", target1[i]);
	}
	putchar('\n');

	for (int i = 0; i < 5; i++)
	{
		printf("%.1f ", target2[i]);
	}
	putchar('\n');


	return 0;
}

void copy_arr(double from[], double to[], int n)
{
	for (int i = 0; i < n; i++)
	{
		to[i] = from[i];
	}
}

void copy_ptr(double * from, double * to, int n)
{
	for (int i = 0; i < n; i++)
	{
		*(to + i) = *(from + i);
	}
}
