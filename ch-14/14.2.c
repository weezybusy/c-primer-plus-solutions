/*
 * 14.2.c -- Write a program that prompts the user to enter the day,
 * month, and year. The month can be a month number_of_daysber, a month name, or a
 * month abbreviation. The program then should return the total number_of_daysber of
 * days in the year up through the given day. (Do take leap years into
 * account.)
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define MONTHS 12

struct year_template {
	char name[10];
	char abbr[4];
	int number_of_days;
	int index;
};

struct year_template new_year [MONTHS] = {
	{ "January", "jan", 31, 1 },
	{ "February", "feb", 28, 2 },
	{ "March", "mar", 31, 3 },
	{ "April", "apr", 30, 4 },
	{ "May", "may", 31, 5 },
	{ "June", "jun", 30, 6 },
	{ "July", "jul", 31, 7 },
	{ "August", "aug", 31, 8 },
	{ "September", "sep", 30, 9 },
	{ "October", "oct", 31, 10 },
	{ "November", "nov", 30, 11 },
	{ "December", "dec", 31, 12 }
};

void getint(int *);
void eat_line(void);
void days_sum(int, int, int, int *);

int main(void)
{
	int month;
	int day;
	int year;
	int sum_of_days = 0;

	printf("Enter a month number: ");
	getint(&month);
	while (month < 1 || month > 12) {
		fputs("Invalid input. There are only 12 months.\n", stderr);
		printf("Try again: ");
		getint(&month);
	}
	month = month - 1;
	printf("Enter a day number: ");
	getint(&day);
	while (day < 1 || day > new_year[month].number_of_days) {
		fputs("Invalid input.\n", stderr);
		printf("There are only %d day(s) in %s.\n",
			new_year[month].number_of_days,
			new_year[month].name);
		printf("Try again: ");
		getint(&day);
	}
	printf("Enter a year: ");
	getint(&year);
	while (year < 0) {
		fputs("A year can't be a negative number.\n", stderr);
		printf("Try again: ");
		getint(&year);
	}

	days_sum(day, month, year, &sum_of_days);
	printf("There are %d day(s) in between the January 1 and %s %d.\n",
		sum_of_days, new_year[month].name, day);

	return 0;
}

void days_sum(int day, int month, int year, int *sum_of_days)
{
	for (int m = 0; m < month; m++)
		*sum_of_days += new_year[m].number_of_days;
	if ((year % 4 == 0 && year % 100 != 0) ||
			(year % 100 == 0 && year % 400 == 0))
		day++;
	*sum_of_days += day;
}

void getint(int *n)
{
	while (scanf("%d", n) != 1) {
		printf("Invalid input. Try again: ");
		eat_line();
	}
	eat_line();
}

void eat_line(void)
{
	while (getchar() != '\n')
		continue;
}
