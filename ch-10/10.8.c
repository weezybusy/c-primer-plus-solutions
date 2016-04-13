/*
 * 10.8.c -- copying of multidimensional array using VLA-based function
 */

#include <stdio.h>
#define ROWS 3
#define COLS 5


void copy_arr(int rows, int cols, const double from[rows][cols], double to[rows][cols]);
void show_arr(int rows, int cols, const double from[rows][cols], double to[rows][cols]);

int main(void)
{
	const double source[ROWS][COLS] =
	{
		{1.1, 2.1, 3.1, 4.1, 5.1},
		{1.2, 2.2, 3.2, 4.2, 5.2},
		{1.3, 2.3, 3.3, 4.3, 5.3}
	};

	double target[ROWS][COLS];

	copy_arr(ROWS, COLS, source, target);
	show_arr(ROWS, COLS, source, target);

	return 0;
}

void copy_arr(int rows, int cols, const double from[rows][cols], double to[rows][cols])
{
	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < cols; c++)
		{
			to[r][c] = from[r][c];
		}
	}
}

void show_arr(int rows, int cols, const double from[rows][cols], double to[rows][cols])
{
	printf("ROW  COL  AR1  AR2\n");
	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < cols; c++)
		{
			printf("%2d %4d %5.1f %4.1f\n", r, c, from[r][c], to[r][c]);
		}
	}
}
