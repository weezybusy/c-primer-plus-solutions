/*
 * 16.6.c -- Modify  Listing 16.17 so that it uses an array of struct names
 * elements (as defined after the listing) instead of an array of double. Use
 * fewer elements, and initialize the array explicitly to a suitable selection
 * of names.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5
#define SIZE 20

typedef struct {
	char first[SIZE];
	char last[SIZE];
} Name;

void print(const Name [], int);
int comp(const void *, const void *);

int main(void)
{
	Name names[MAX] = {
		{ "John", "Johnson" },
		{ "Maria", "Lopez" },
		{ "George", "Washington" },
		{ "Barbara", "Tailor" },
		{ "Sarah", "Connor" }
	};

	puts("\nBEFORE SORT:");
	puts("------------");
	print(names, MAX);
	qsort(names, MAX, sizeof(Name), comp);
	puts("\nAFTER SORT:");
	puts("-----------");
	print(names, MAX);
	putchar('\n');

	return 0;
}

int comp(const void *p1, const void *p2)
{
	int value;
	const Name *n1 = (const Name *) p1;
	const Name *n2 = (const Name *) p2;

	value = strcmp(n1->last, n2->last);
	if (value != 0)
		return value;
	else
		return strcmp(n1->first, n2->first);
}

void print(const Name names[], int size)
{
	for (int i = 0; i < size; i++)
		printf("%s, %s\n", names[i].last, names[i].first);
}
