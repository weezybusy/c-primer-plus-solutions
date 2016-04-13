/*
 * 10.6.c -- copying of multidimensional arrays
 */

#include <stdio.h>
#define ROWS 3
#define COLS 2

void copy_arr(const double from[][COLS], double to[][COLS], int rows);
void show_arr(double ar[][COLS], int rows);

int main(void)
{
	const double source[ROWS][COLS] =
	{
		{12.1, 3.0},
		{0.2, 13.1},
		{5.3, 0.01}
	};

	double target[ROWS][COLS];

	copy_arr(source, target, ROWS);
	show_arr(target, ROWS);

	return 0;
}

void copy_arr(const double from[][COLS], double to[][COLS], int rows)
{
	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < COLS; c++)
		{
			to[r][c] = from[r][c];
		}
	}
}

void show_arr(double ar[][COLS], int rows)
{
	for	(int r = 0; r < rows; r++)
	{
		for (int c = 0; c < COLS; c++)
		{
			printf("row: %d, col:%d, value: %.2f\n", r, c, ar[r][c]);
		}
	}
}
