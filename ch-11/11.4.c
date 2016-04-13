/* 11.4.c -- fetches n characters from input
 * (including spaces, new linws and tabs) and
 * stores the result in an array
 */

#include <stdio.h>
#include <ctype.h>
#define LEN 16

char *get_word(char *st, int n);

int main(void)
{
	char input[LEN];

	while (get_word(input, LEN - 1) != NULL)
	{
		puts(input);
	}
	puts("Done!");

	return 0;
}

char *get_word(char *st, int n)
{
	int ch;
	int count = 0;

	while ((ch = getchar()) != EOF && !isspace(ch) && count < n)
	{
		*st++ = ch;
		count++;
	}

	*st = '\0';

	if (ch == EOF)
	{
		st = NULL;
	}

	else
	{
		while (ch != '\n')
		{
			ch = getchar();
		}
	}

	return st;
}
