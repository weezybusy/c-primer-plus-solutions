/* 11.5.c -- searches the string (first function argument)
 * for the first occurance of a character (second argument).
 * If succeed, return pointer to character, else, returns
 * NULL.
 */

#include <stdio.h>
#include <string.h>
#define SIZE 21

char *s_gets(char *st, int n);
char *find_char(char *st, char ch);


int main(void)
{
	char st[SIZE];
	char *found;
	char ch;

	puts("Enter a string:");
	while (s_gets(st, SIZE) && st[0] != '\n')
	{
		puts("Enter a character you want to find:");
		ch = getchar();
		while (getchar() != '\n')
		{
			continue;
		}
		found = find_char(st, ch);
		if (found != NULL)
		{
			puts(found);
		}
		else
		{
			printf("%c not found in string.\n", ch);
		}
		puts("Enter next string:");
	}

	puts("Done!");

	return 0;
}

char *s_gets(char *st, int n)
{
	char *ret_val;

	ret_val= fgets(st, n, stdin);

	if (ret_val)
	{
		while (*st != '\n' && *st != '\0')
		{
			st++;
		}
		if (*st == '\n')
		{
			*st = '\0';
		}

		else
		{
			while (getchar() != '\n')
			{
				continue;
			}
		}
	}

	return ret_val;
}

char *find_char(char *st, char ch)
{
	char *ret_val = NULL;

	while (*st)
	{
		if (*st == ch)
		{
			ret_val = st;
			break;
		}
		st++;
	}

	return ret_val;
}
