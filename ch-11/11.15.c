/*
 * 11.15.c --
 * Use the character classification functions to prepare an
 * implementation of atoi(); have this version return the
 * value of 0 if the input string is not a pure number.
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define LEN 20

int a_toi(char *s);
char *fget(char *s, int n);

int main(void)
{
	char str[LEN];
	char *stat;
	int result;

	stat = fget(str, LEN);
	if (stat && str[0] != '\0')
		result = a_toi(str);

	printf("%d\n", result);

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

int a_toi(char *s)
{
	int num = 0;
	int len = strlen(s);
	int i = 1;

	while (*s)
	{
		if (!isdigit(*s))
			return 0;
		else
		{
			if (len == 1)
				num = *s - 48;
			else
				num += (*s - 48) * pow(10, (double) (len - i));
		}

		i++;
		s++;
	}

	return num;
}
