/* 10.13 --
 * 1. Store the information in a 3×5 array
 * 2. Compute the average of each set of five values
 * 3. Compute the average of all the values
 * 4. Determine the largest value of the 15 values
 * 5. Report the results
 */

#include <stdio.h>
#define ROWS 3
#define COLS 5

void store(double ar[], int n);
double row_avg(double ar[], int n);
double total_avg(int rows, int cols, double ar[rows][cols]);
double max(int rows, int cols, double ar[rows][cols]);
void show_results(double arg);

int main(void)
{
	double stuff[ROWS][COLS];

	putchar('\n');
	printf("ENTER %d NUMBERS PER EACH ROW:\n", COLS);
	for (int r = 0; r < ROWS; r++)
	{
		printf("ROW #%d: ", r + 1);
		store(stuff[r], COLS);
	}
	putchar('\n');

	for (int i = 0; i < ROWS; i++)
	{
		printf("AVERAGE FOR ROW #%d: ", i + 1);
		show_results(row_avg(&stuff[i][0], COLS));
	}
	putchar('\n');

	printf("TOTAL AVERAGE: ");
	show_results(total_avg(ROWS, COLS, stuff));
	putchar('\n');
	printf("LARGEST VALUE: ");
	show_results(max(ROWS, COLS, stuff));
	putchar('\n');

	return 0;
}

void store(double ar[], int n)
{
		for (int i = 0; i < COLS; i++)
		{
			scanf("%lf", &ar[i]);
		}
}

double row_avg(double ar[], int n)
{
	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += ar[i];
	}

	return sum / n;

}

double total_avg(int rows, int cols, double ar[rows][cols])
{
	double sum = 0;
	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < cols; c++)
		{
			sum += ar[r][c];
		}
	}

	return sum / (rows * cols);
}

double max(int rows, int cols, double ar[rows][cols])
{

	int max = ar[0][0];
	for (int r = 0; r < rows; r++)
	{
		for (int c = 1; c < cols; c++)
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
