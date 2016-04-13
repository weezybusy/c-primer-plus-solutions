/**
 * 17.6.c -- Write a function that takes three arguments: the name of an array
 * of sorted integers, the number of elements of the array, and an integer to
 * seek. The function returns the value 1 if the integer is in the array, and
 * 0 if it isn’t. Have the function use the binary search technique.
 */

#include <stdio.h>
#define SIZE 7

int search(const int [], int, int);

int main(void)
{
	int a[SIZE] = { 1, 3, 7, 12, 24, 33, 35 };
	int result;

	result = search(a, SIZE, 7);

	if (result)
		puts("Found!");
	else
		puts("Not found!");

	return 0;
}

int search(const int a[], int size, int target)
{
	int min = 0;
	int max = size - 1;

	while (min < max)
	{
		int mid = (min + max) / 2;
		if (target < a[mid])
			max = mid - 1;
		else if (target > a[mid])
			min = mid + 1;
		else
			return 1;
	}

	return a[min] == target ? 1 : 0;
}
