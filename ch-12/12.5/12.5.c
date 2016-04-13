/*
 * 12.5.c --
 * Write a program that generates a list of 100 random numbers
 * in the range 1–10 in sorted decreasing order. (You can adapt
 * the sorting algorithm from Chapter 11 , “Character Strings
 * and String Functions,” to type int . In this case, just sort
 * the numbers themselves.)
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "12.5.h"
#define SIZE 100

int main(void)
{
	int num_arr[SIZE];

	get_rand_num(num_arr, SIZE);
	puts("\nInitial array:");
	print(num_arr, SIZE);
	sort_num_arr(num_arr, SIZE);
	puts("Sorted array:");
	print(num_arr, SIZE);

	return 0;
}
