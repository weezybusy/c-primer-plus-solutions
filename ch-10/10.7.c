/*
 * 10.7.c -- copying certain elements from one
 * array to the other which has different size
 */
#include <stdio.h>
#define LEN1 7
#define LEN2 3

void copy_arr(const int * from, int * to, int n);
void show_arr(const int * ar, int n);

int main(void)
{
	const int source[LEN1] = {1, 2, 3, 4, 5, 6, 7};
	int target[LEN2];

	copy_arr(source + 2, target, 3);
	show_arr(target, 3);

	return 0;
}

void copy_arr(const int * from, int * to, int n)
{
	for (int i = 0; i < n; i++)
	{
		to[i] = from[i];
	}
}

void show_arr(const int * ar, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("element #: %d, value: %d\n", i, ar[i]);
	}
}
