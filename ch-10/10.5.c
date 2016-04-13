/*
 * 10.5.c -- finding of the range of min and max double
 */

#include <stdio.h>
#define SIZE 10

double range(const double ar[], int n);

int main(void)
{
	const double doubles[SIZE] =
			{78.3, 2.01, -1.3, 9.4, -3.3, -1.2, 1.99, -2.0, 0.0, 12.1};

	printf("The range of min and max doubles: %.2f\n", range(doubles, SIZE));

	return 0;
}

double range(const double ar[], int n)
{
	double max = ar[0];
	double min = ar[0];
	for (int i = 1; i < n; i++)
	{
		if (max - ar[i] < 0)
			max = ar[i];
		if (min - ar[i] > 0)
			min = ar[i];
	}

	return max - min;
}
