/*
 * 11.14.c --
 * Write a power-law program that works on a command-line basis.
 * The first command-line argument should be the type double number
 * to be raised to a certain power, and the second argument should
 * be the integer power.
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
	double num;
	int exp;
	double result;

	num = atof(argv[1]);
	exp = atoi(argv[2]);
	result = num;

	if (exp < 0)
	{
		for (int i = 1; i < -exp; i++)
			result *= num;
		printf("%.3lf\n", 1/result);
	}

	else if (exp == 0)
		printf("%.3lf\n", 1.);

	else
	{
		for (int i = 1; i < exp; i++)
			result *= num;
		printf("%.3lf\n", result);
	}

	return 0;
}
