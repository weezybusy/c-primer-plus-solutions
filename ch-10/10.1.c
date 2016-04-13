/* 10.1.c -- finds yearly totals, yearly average, and monthly
 * average for several years of rainfall data
 */

#include <stdio.h>
#define MONTHS 12	// number of months in a year
#define YEARS 5		// nimber of years of data

int main(void)
{
	// initializing rainfall data for 2011 - 2015
	const float rain[YEARS][MONTHS] =
	{
		{4.3,4.3,4.3,3.0,2.0,1.2,0.2,0.2,0.4,2.4,3.5,6.6},
		{8.5,8.2,1.2,1.6,2.4,0.0,5.2,0.9,0.3,0.9,1.4,7.3},
		{9.1,8.5,6.7,4.3,2.1,0.8,0.2,0.2,1.1,2.3,6.1,8.4},
		{7.2,9.9,8.4,3.3,1.2,0.8,0.4,0.0,0.6,1.7,4.3,6.2},
		{7.6,5.6,3.8,2.8,3.8,0.2,0.0,0.0,0.0,1.3,2.6,5.2}
	};

	int year, month;
	float subtotal, total;

	printf("\nYEAR:	RAINFALL (inches):\n");
	for (year = 0, total = 0; year < YEARS; year++)
	{	/* for each year, sum rainfall for each month */
		for (month = 0, subtotal = 0; month < MONTHS; month++)
		{
			subtotal += *(*(rain + year) + month);
		}
		printf("%4d %13.1f\n", 2011 + year, subtotal);
		total += subtotal;
	}

	printf("\nTHE YEARLY AVERAGE: %.1f inches\n", total/YEARS);
	printf("\nMONTHLY AVERAGES:\n");
	printf("Jan  Feb  Mar  Apr  May  Jun  Jul  Aug  Sep  Oct  Nov  Dec\n");

	for (month = 0; month < MONTHS; month++)
	{
		for (year = 0, subtotal = 0; year < YEARS; year++)
		{	/* for each month, sum rainfall over years */
			subtotal += *(*(rain + year) + month);
		}
		printf("%3.1f  ", subtotal/YEARS);
	}
	putchar('\n');
	putchar('\n');
	return 0;
}
