/*
 * 12.3b.c
 */

#include <stdio.h>
#include "12.3.h"

void set_mode(int *mode, int prev_mode)
{
	if (*mode < 0 || *mode > 1) {
		printf("Invalid mode specified. Mode %d(%s) used.\n",
				prev_mode, prev_mode ? "US" : "metric");
		*mode = prev_mode;
	}
}

void get_info(int mode, double *distance, double *fuel_consumed)
{
	printf("Enter distance traveled in %s: ",
			mode ? "miles" : "kilometers");
	scanf("%lf", distance);
	printf("Enter fuel consumed in %s: ",
			mode ? "gallons" : "liters");
	scanf("%lf", fuel_consumed);
}

void show_info(int mode, double *distance, double *fuel_consumed)
{
	double consumption;
	if (mode) {
		consumption = *distance / *fuel_consumed;
		printf("Fuel consumption is %.1lf miles per gallon.\n",
				consumption);
	} else {
		consumption = *fuel_consumed / *distance * 100.0;
		printf("Fuel consumption is %.2lf liters per 100 km.\n",
				consumption);
	}
}
