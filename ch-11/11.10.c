/*
 * 11.10.c --
 * Write a function that takes a string as an argument and removes
 * the spaces from the string. Test it in a program that uses a loop
 * to read lines until you enter an empty line. The program should
 * apply the function to each input string and display the result.
 */

#include <stdio.h>
#include <string.h>
#define LEN 20

char *fget(char *s, int n);
void del_spaces(char *s);

int main(void)
{
	char str[LEN];
	char *val;

	val = fget(str, LEN);
	while (val && str[0] != '\0')
	{
		del_spaces(str);
		puts(str);
		val = fget(str, LEN);
	}

	return 0;
}

char *fget(char *s, int n)
{
	char *ret_val;
	char *end_ch;

	ret_val = fgets(s, n, stdin);
	if (ret_val)
	{
		end_ch = strchr(s, '\n');
		if (end_ch)
			*end_ch = '\0';
		else
			while (getchar() != '\n')
				continue;
	}

	return ret_val;
}

void del_spaces(char *s)
{
	char *space;

	space = strchr(s, ' ');
	while (space)
	{
		*space = '\0';
		strcat(s, space + 1);
		space = strchr(s, ' ');
	}
}
