/* 11.3.c -- reads first word from a line of input
 * and discards the rest of the line
 */

#include <stdio.h>
#include <ctype.h>
#define LEN 81

char *get_word(char *st);

int main(void)
{
	char input[LEN];

	while (get_word(input) != NULL)
	{
		puts(input);
	}
	puts("Done!");

	return 0;
}

char *get_word(char *st)
{
	int ch;

	while ((ch = getchar()) != EOF && !isspace(ch))
	{
		*st++ = ch;
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
