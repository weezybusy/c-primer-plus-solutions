/*
 * 10.4.c -- function finds an index of max value in the array
 */

#include <stdio.h>
#define SIZE 10

int id_max_double(const double ar[], int n);

int main(void)
{
	const double doubles[SIZE] =
			{-78.3, 2.01, -1.3, 9.4, -3.3, -1.2, 1.99, -2.0, 0.0, -12.1};

	printf("Index of max double: %d\n", id_max_double(doubles, SIZE));

	return 0;
}

int id_max_double(const double ar[], int n)
{
	double max = ar[0];
	int id;
	for (int i = 1; i < n; i++)
	{
		if (max - ar[i] < 0)
		{
			max = ar[i];
			id = i;
		}
	}

	return id;
}
