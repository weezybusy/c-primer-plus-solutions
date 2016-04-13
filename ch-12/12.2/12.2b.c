/*
 * 12.2b.c
 */

#include <stdio.h>

static int mode;
static int distance;
static double fuel_consumed;

void set_mode(int val)
{
	if (val < 0 || val > 1) {
		printf("Invalid mode specified. Mode %d(%s) used.\n",
				mode, mode ? "US" : "metric");
	} else {
		mode = val;
	}
}

void get_info()
{
	printf("Enter distance traveled in %s: ",
			mode ? "miles" : "kilometers");
	scanf("%d", &distance);
	printf("Enter fuel consumed in %s: ",
			mode ? "gallons" : "liters");
	scanf("%lf", &fuel_consumed);
}

void show_info()
{
	double consumption;
	if (mode) {
		consumption = (double) distance / fuel_consumed;
		printf("Fuel consumption is %.1lf miles per gallon.\n",
				consumption);
	} else {
		consumption = fuel_consumed / (double) distance * 100.0;
		printf("Fuel consumption is %.2lf liters per 100 km.\n",
				consumption);
	}
}
