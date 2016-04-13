/*
 * 10.3.c -- functions descriptions:
 * 	1. max_int -> finds max int value in the array
 * 	2. min_int -> finds min int value in the array
 */

#include <stdio.h>
#define SIZE 10

int max_int(const int ar[], int n);
int min_int(const int ar[], int n);


int main(void)
{
	const int ints[SIZE] = {-78, 2, -1, 9, -33, -12, 1, -2, 0, -12};

	printf("Max int: %d\n", max_int(ints, SIZE));
	printf("Min int: %d\n", min_int(ints, SIZE));

	return 0;
}

int max_int(const int ar[], int n)
{
	int max = ar[0];
	for (int i = 1; i < n; i++)
	{
		if (max - ar[i] < 0)
		{
			max = ar[i];
		}
	}

	return max;
}

int min_int(const int ar[], int n)
{
	int min = ar[0];
	for (int i = 1; i < n; i++)
	{
		if (min - ar[i] > 0)
		{
			min = ar[i];
		}
	}

	return min;
}
