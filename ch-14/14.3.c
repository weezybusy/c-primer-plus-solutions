/*
 * 14.3.c -- Revise the book-listing program in Listing 14.2 so that it
 * prints the book descriptions in the order entered, then alphabetized
 * by title, and then in order of increased value.
 */

#include <stdio.h>
#include <string.h>

#define TITL 40
#define AUTL 40
#define BKS 100

struct book {
	char title[TITL];
	char author[AUTL];
	float value;
};

char *getstr(char *, int);
void sort_by_titles(struct book s[], int n);
void sort_by_values(struct book s[], int n);
void print_library(const struct book s[], int n);

int main(void)
{
	struct book library[BKS];
	int count = 0;

	printf("Enter a book title or empty line to quit:\n");
	while (count < BKS && getstr(library[count].title, TITL) != NULL &&
		library[count].title[0] != '\0') {
		printf("Now enter the author:\n");
		getstr(library[count].author, AUTL);
		printf("Now enter a value:\n");
		scanf("%f", &library[count++].value);
		while (getchar() != '\n')
			continue;
		if (count < BKS)
			printf("Enter the next title:\n");
	}
	
	if (count > 0) {
		printf("The original list of your books:\n");
		print_library(library, count);
		sort_by_titles(library, count);
		printf("Sorted by title list of your books:\n");
		print_library(library, count);
		printf("Sorted by value list of your books:\n");
		sort_by_values(library, count);
		print_library(library, count);
	} else {
		printf("No books? Too bad.\n");
	}

	return 0;
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

void sort_by_titles(struct book s[], int n)
{
	struct book tmp;
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (strcmp(s[i].title, s[j].title) > 0) {
				tmp = s[i];
				s[i] = s[j];
				s[j] = tmp;
			}
}

void sort_by_values(struct book s[], int n)
{
	struct book tmp;
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (s[i].value >  s[j].value) {
				tmp = s[i];
				s[i] = s[j];
				s[j] = tmp;
			}
}

void print_library(const struct book s[], int n)
{
	printf("---------------------------------------------------\n");
	for (int i = 0; i < n; i++)
		printf("%d) %s by %s: $%.2f\n", i + 1, s[i].title,
			s[i].author, s[i].value);
	printf("---------------------------------------------------\n");
}
