/*
 * 10.12.c --
 * 1. store the information in a 3×5 array
 * 2. compute the average of each set of five values
 * 3. compute the average of all the values
 * 4. determine the largest value of the 15 values
 * 5. report the results
 */

#include <stdio.h>
#define ROWS 3
#define COLS 5

double set_avg(double ar[], int n);
double total_avg(double ar[][COLS], int rows);
double max(double ar[][COLS], int rows);
void show_results(double arg);

int main(void)
{
	double nums[ROWS][COLS];

	putchar('\n');
	for (int r = 0; r < ROWS; r++)
	{
		printf("SET #%d: ", r + 1);
		for (int c = 0; c < COLS; c++)
		{
			scanf("%lf", &nums[r][c]);
		}
	}
	putchar('\n');

	for (int i = 0; i < ROWS; i++)
	{
		printf("AVERAGE OF SET #%d: ", i + 1);
		show_results(set_avg(&nums[i][0], COLS));
	}
	putchar('\n');

	printf("TOTAL AVERAGE: ");
	show_results(total_avg(nums, ROWS));
	putchar('\n');
	printf("LARGEST NUMBER: ");
	show_results(max(nums, ROWS));
	putchar('\n');

	return 0;
}

double set_avg(double ar[0], int n)
{
	double subtot = 0;
	double total = 0;
	for (int i = 0; i < n; i++)
	{
		subtot += ar[i];
	}
	total = subtot / n;

	return total;

}

double total_avg(double ar[][COLS], int rows)
{
	double subtot = 0;
	double total = 0;
	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < COLS; c++)
		{
			subtot += ar[r][c];
		}
	}
	total = subtot / (ROWS * COLS);

	return total;
}

double max(double ar[][COLS], int rows)
{

	int max = ar[0][0];
	for (int r = 0; r < rows; r++)
	{
		for (int c = 1; c < COLS; c++)
		{
			if (max - ar[r][c] < 0)
			{
				max = ar[r][c];
			}
		}
	}

	return max;
}

void show_results(double arg)
{
	printf("%.2f\n", arg);
}
