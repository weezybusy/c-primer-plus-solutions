/* 11.2.c -- fetches characters from input
 * and stores the result in an array untill
 * reaches first iwhite-space character.
 */

#include <stdio.h>
#include <ctype.h>
#define LEN 10

char *fetch(char *st, int n);

int main(void)
{
	char st[LEN];
	char *chk;

	chk = fetch(st, LEN - 1);

	if (chk == NULL)
		puts("Input failed.");

	else
		puts(st);

	chk = fetch(st, LEN - 1);

	if (chk == NULL)
		puts("Input failed.");

	else
		puts(st);

	return 0;
}

char *fetch(char *st, int n)
{
	int count = 0;

	*st = getchar();
	while (*st != EOF && count < n && !isspace(*st))
	{
		st++;
		*st = getchar();
		count++;
	}
	if (*st == EOF)
		st = NULL;
	else
	{
		*st = '\0';
		while (getchar() != '\n')
		{
			continue;
		}
	}

	return st;
}
