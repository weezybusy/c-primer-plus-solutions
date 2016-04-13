/*
 * 14.4_b.c -- Write a program that creates a structure template with two
 * members according to the following criteria:
 * 	a. The first member is a social security number. The second member
 *	   is a structure with three members. Its first member contains a
 * 	   first name, its second member contains a middle name, and its
 * 	   final member contains a last name. Create and initialize an array
 * 	   of five such structures. Have the program print the data in this
 * 	   format:
 * 		Dribble, Flossie M. –– 302039823
 * Only the initial letter of the middle name is printed, and a period is
 * added. Neither the initial (of course) nor the period should be printed
 * if the middle name member is empty. Write a function to do the printing;
 * pass the structure array to the function.
 */

#include <stdio.h>
#include <string.h>

#define MAX 10
#define LEN 20
#define SIZE 5

struct person {
	char soc_sec_num[MAX];
	struct {
		char fname[LEN];
		char mname[LEN];
		char lname[LEN];
	};
};

void print_people(const struct person [], int);
char *getstr(char *s, int n);
		
int main(void)
{
	struct person people[SIZE];
	int count = 0;

	printf("Enter the first name (empty line to quit): ");
	while (getstr(people[count].fname, LEN) != NULL &&
			count < MAX && people[count].fname[0] != '\0') {
		printf("Enter the middle name: ");
		getstr(people[count].mname, LEN);
		printf("Enter the last name: ");
		getstr(people[count].lname, LEN);
		printf("Enter a social security number: ");
		getstr(people[count].soc_sec_num, MAX);

		if (count < MAX)
			printf("Enter the next first name: ");
		count++;
	}

	if (count > 0) {
		puts("Printing out all the people:");
		print_people(people, count);
	}

	return 0;
}

void print_people(const struct person p[], int n)
{
	puts("--------------------------------------------------------");
	for (int i = 0; i < n; i++)
		printf("%s, %s %c%s-- %s\n", p[i].lname, p[i].fname,
			p[i].mname[0],
			p[i].mname[0] != '\0' ? ". " : "",
			p[i].soc_sec_num);
	puts("--------------------------------------------------------");
}

char *getstr(char *s, int n)
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
