/*
 *  10.10.c -- doubling values of elements of the array
 */

#include <stdio.h>
#define ROWS 3
#define COLS 5

void show_arr(int ar[][COLS], int rows);
void double_arr(int ar[][COLS], int rows);

int main(void)
{
	int nums[ROWS][COLS] =
	{
		{1, 3, 5, 7, 9},
		{2, 4, 6, 8, 10},
		{11, 13, 15, 17, 19}
	};

	printf("ORIGINAL VALUES:\n");
	show_arr(nums, ROWS);
	double_arr(nums, ROWS);
	printf("\nDOUBLED VALUES:\n");
	show_arr(nums, ROWS);

	return 0;
}

void show_arr(int ar[][COLS], int rows)
{
	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < COLS; c++)
		{
			printf("%-3d ", ar[r][c]);
		}
	}

	putchar('\n');
}

void double_arr(int ar[][COLS], int rows)
{
	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < COLS; c++)
		{
			ar[r][c] = ar[r][c] * 2;
		}
	}
}
