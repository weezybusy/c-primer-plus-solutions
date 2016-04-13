/*
 * 11.9.c
 * Write a function that replaces the contents of a string with the
 * string reversed. Test the function in a complete program that
 * uses a loop to provide input values for feeding to the function.
 */

#include <stdio.h>
#include <string.h>
#define LEN 21

char *reversed(char *str);

int main(void)
{
	char original[LEN] = "Hello world!";
	char * changed;

	changed = reversed(original);
	puts(changed);

	return 0;
}

char *reversed(char *str)
{
	int i = 0;
	int j = strlen(str) - 1;
	char tmp;

	while (i < j)
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		i++;
		j--;
	}

	return str;
}
