/*
 * 14.1.c -- Redo Review Question 5:
 *
 *	Write a function that, when given the month number, returns the
 *	total days in the year up to and including that month. Assume that
 *	the structure template of question 3 and an appropriate array of
 *	such structures are declared externally.
 *
 * but make the argument the spelled-out name of the month instead of the
 * month number. (Don’t forget about strcmp()) Test the function in a
 * simple program.
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 12

struct year {
	char name[10];
	char abbr[3];
	int days_num;
	int month_num;
};

struct year non_leap[SIZE] = {
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

char *sgets(char *, int);
int days(char *);

int main(void)
{
	char month[10];
	int total = 0;

	puts("Please, enter the name of a month (q to quit):");
	while (sgets(month, 10) != NULL && month[0] != 'q') {
		total = days(month);
		if (total > 0)
			printf("%d\n", total);
		else
			printf("%s is not a valid input.\n", month);
		puts("Enter next month (q to quit):");
	}
		
	return 0;
}

int days(char *m)
{
	int sum = 0;
	int month = 0;

		m[0] = toupper(m[0]);
		for (int i = 1; m[i] != '\0'; i++)
			m[i] = tolower(m[i]);
		while (month < SIZE &&
				strcmp(m, non_leap[month].name) != 0)
			month++;
		for (; month < SIZE; month++)
			sum += non_leap[month].days_num;
	return sum;
}

char *sgets(char *s, int n)
{
	char *value, *new_line;

	value = fgets(s, n, stdin);
	if (value) {
		new_line = strchr(s, '\n');
		if (new_line)
			*new_line = '\0';
		else
			while (getchar() != '\n')
				continue;
	}

	return value;
}
