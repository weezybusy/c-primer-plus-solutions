/* 11.6.c -- Write a function called is_within() that takes
 * a character and a string pointer as its two function parameters.
 * Have the function return a nonzero value (true) if the character
 * is in the string and zero (false) otherwise. Test the function
 * in a complete program that uses a loop to provide input values
 * for feeding to the function.
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define SIZE 21

char *s_gets(char *st, int n);
bool is_within(char *st, char ch);

int main(void)
{
	char st[SIZE];
	char ch;
	bool result;

	puts("Enter a string:");
	while (s_gets(st, SIZE - 1) && st[0] != '\n')
	{
		puts("Enter a character:");
		ch = getchar();
		while (getchar() != '\n')
		{
			continue;
		}
		result = is_within(st, ch);
		if (result)
		{
			printf("%c is inside the string.\n\n", ch);
		}
		else
		{
			printf("%c is not inside the string.\n\n", ch);
		}
		puts("Enter next string:");
	}

	return 0;
}

char *s_gets(char *st, int n)
{
	char *var;

	var = fgets(st, n, stdin);
	if (var)
	{
		var = strchr(st, '\n');
		if (var)
		{
			*var = '\0';
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

bool is_within(char *st, char ch)
{
	bool value = false;
	while (*st)
	{
		if (*st == ch)
		{
			value = true;
		}
		st++;
	}

	return value;
}
