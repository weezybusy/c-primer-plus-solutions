/*
 * 10.11.c -- finds yearly totals, yearly average, and monthly
 * average for several years of rainfall data
 */

#include <stdio.h>
#define MONTHS 12
#define YEARS 5

float years_rainfall(const float ar[][MONTHS]);
void months_avg(const float ar[][MONTHS]);

int main(void)
{
	const float rain[YEARS][MONTHS] =
	{
		{4.3,4.3,4.3,3.0,2.0,1.2,0.2,0.2,0.4,2.4,3.5,6.6},
		{8.5,8.2,1.2,1.6,2.4,0.0,5.2,0.9,0.3,0.9,1.4,7.3},
		{9.1,8.5,6.7,4.3,2.1,0.8,0.2,0.2,1.1,2.3,6.1,8.4},
		{7.2,9.9,8.4,3.3,1.2,0.8,0.4,0.0,0.6,1.7,4.3,6.2},
		{7.6,5.6,3.8,2.8,3.8,0.2,0.0,0.0,0.0,1.3,2.6,5.2}
	};

	float total;

	printf("\nTOTAL RAINFALL FOR EACH YEAR:\n\n");
	total = years_rainfall(rain);
	printf("THE YEARLY AVERAGE IS:\n\n %.1f inches.\n", total/YEARS);
	printf("\nTHE MONTHLY AVERAGES ARE:\n");
	months_avg(rain);

	return 0;
}

float years_rainfall(const float ar[][MONTHS])
{
	int year, month;
	float subtotal, total;

	printf(" year   rainfall (inches)\n");
	for (year = 0, total = 0; year < YEARS; year++)
	{
		for (month = 0, subtotal = 0; month < MONTHS; month++)
		{
			subtotal += ar[year][month];
		}
		printf("%5d %12.1f\n", 2000 + year, subtotal);
		total += subtotal;
	}
	putchar('\n');

	return total;
}

void months_avg(const float ar[][MONTHS])
{
	int month, year;
	float subtotal;

	printf("\n Jan   Feb   Mar   Apr   May   Jun   Jul   Aug   Sep   Oct   Nov   Dec\n");
	for (month = 0; month < MONTHS; month++)
	{
		for (year = 0, subtotal = 0; year < YEARS; year++)
		{
			subtotal += ar[year][month];
		}
		printf(" %-4.1f ", subtotal);
	}
	printf("\n\n");
}
