/* 11.7.c - -The strncpy(s1,s2,n) function copies exactly n characters from s2 to s1,
 * truncating s2 or padding it with extra null characters as necessary. The target
 * string may not be null-terminated if the length of s2 is n or more. The function \
 * returns s1 . Write your own version of this function; call it mystrncpy() . Test
 * the function in a complete program that uses a loop to provide input values for
 * feeding to the function.
 */

#include <stdio.h>
#include <string.h>
#define LEN 81

char *get_str(char *st, int n);
char *str_cpy(char *st1, char *st2, int limit);

int main(void)
{
	char st1[11];
	char st2[LEN];
	int limit;
	char bad_input;

	puts("Enter a string:");
	while (get_str(st2, LEN - 1) && st2[0] != '\0')
	{
		puts("Enter number of characters you want to copy:");
		while (scanf("%d", &limit) != 1)
		{
			while ((bad_input = getchar()) != '\n')
			{
				putchar(bad_input);
				puts(" is invalid input. Enter a positive integer such as 5 or 7:");
			}
		}
		while (getchar() != '\n')
		{
			continue;
		}

		if (limit < sizeof(st1))
		{
			str_cpy(st1, st2, limit);
			puts(st1);
		}

		else
		{
			puts("Not enough space to copy your string!");
		}

		puts("Enter next string:");
	}

	return 0;
}

char *get_str(char *st, int n)
{
	char *status;

	status = fgets(st, n, stdin);
	if (status)
	{
		status = strchr(st, '\n');
		if (status)
		{
			*status = '\0';
		}
		else
		{
			while (getchar() != '\n')
			{
				continue;
			}
		}
	}

	return st;
}

char *str_cpy(char *st1, char *st2, int limit)
{
	while (limit--)
	{
		*st1++ = *st2++;
	}

	*st1 = '\0';

	return st1;
}
