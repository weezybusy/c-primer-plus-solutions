/*
 * 10.9.c -- initialize an array with sum of two
 * elements of the same index from the other to arrays
 */

#include <stdio.h>
#define SIZE 4

void init_arr(int ar1[], int ar2[], int ar3[], int n);
void show_arr(int ar1[], int ar2[], int ar3[], int n);

int main(void)
{
	int ar1[SIZE] = {1, 3, 5, 7};
	int ar2[SIZE] = {2, 4, 6, 8};
	int target[SIZE];

	init_arr(ar1, ar2, target, SIZE);
	show_arr(ar1, ar2, target, SIZE);

	return 0;
}


void init_arr(int ar1[], int ar2[], int ar3[], int n)
{
	for (int i = 0; i < n; i++)
	{
		ar3[i] = ar1[i] + ar2[i];
	}
}

void show_arr(int ar1[], int ar2[], int ar3[], int n)
{
		printf("ar1  ar2  taget\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d  +  %d  =  %d\n", ar1[i], ar2[i], ar3[i]);
	}
}
