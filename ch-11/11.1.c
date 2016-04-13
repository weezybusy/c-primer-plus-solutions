/* 11.1.c -- fetches n characters from input
 * (including spaces, new linws and tabs) and
 * stores the result in an array
 */

#include <stdio.h>
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

	return 0;
}

char *fetch(char *st, int n)
{
	int count = 0;

	*st = getchar();
	while (*st != EOF && count < n)
	{
		st++;
		*st = getchar();
		count++;
	}
	if (*st == EOF)
		st = NULL;
	else
		*st = '\0';

	return st;
}
