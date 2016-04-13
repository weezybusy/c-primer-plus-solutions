/*
 * 14.10.c -- Write a program that implements a menu by using an array of
 * pointers to functions. For instance, choosing a from the menu would activate
 * the function pointed to by the first element of the array.
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 3
#define STRING 30

void eat_line(void);
char get_letter(char *);
char *sgets(char *);
void upper(char *);
void lower(char *);
void transpose(char *);
void menu(char *s);

int main(void)
{
	char string[STRING];

	printf("\n Enter a string: _\b");
	sgets(string);
	menu(string);

	return 0;
}

void menu(char *s)
{
	void (*fp[SIZE])(char *) = { upper, lower, transpose };
	char choice;
	char copy[STRING];

	strcpy(copy, s);
	printf("\n a) upper\n b) lower\n c) transpose\n d) quit\n");
	printf("\n Your choice is _\b");
	choice = get_letter("abcd");
	while (choice != 'd') {
		(*fp[choice - 97])(copy);
		printf(" %s\n", copy);
		strcpy(copy, s);
		printf("\n Your next choice is _\b");
		choice = get_letter("abcd");
	}
	putchar('\n');
}

void upper(char *s)
{
	while (*s) {
		*s = toupper(*s);
		s++;
	}
}

void lower(char *s)
{
	while (*s) {
		*s = tolower(*s);
		s++;
	}
}

void transpose(char *s)
{
	while (*s) {
		if (islower(*s))
			*s = toupper(*s);
		else if (isupper(*s))
			*s = tolower(*s);
		s++;
	}
}

char *sgets(char *s)
{
	char *value, *new_line;
	value = fgets(s, STRING, stdin);
	if (value) {
		new_line = strchr(s, '\n');
		if (new_line)
			*new_line = '\0';
		else
			eat_line();
	}
	return value;
}

char get_letter(char *s)
{
	char letter;

	letter = getchar();
	eat_line();
	while (strchr(s, letter) == NULL) {
		letter = getchar();
		eat_line();
	}
	return letter;
}

void eat_line(void)
{
	while (getchar() != '\n')
		continue;
}
