/*
 * 17.5 -- Write a program that lets you input a string. The program then
 * should Push the characters of the string onto a stack, one by one
 * (see review question 5), and then Pop the characters from the stack and
 * display them. This results in displaying the string in reverse order.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

char *sgets(char *, int);

int main(void)
{
	Stack chars;
	char input[MAX_STRING_SIZE];
	char ch;

	InitializeStack(&chars);

	printf("Enter a string: ");
	while (sgets(input, MAX_STRING_SIZE) && input[0] != '\0')
	{
		int size = strlen(input);
		for (int i = 0; i < size; i++)
			Push(&chars, &input[i]);

		while (chars.top)
		{
			Pop(&ch, &chars);
			putchar(ch);
		}
		printf("\nEnter a string: ");
	}

	return 0;
}

char *sgets(char *str, int n)
{
	char *value = fgets(str, n, stdin);
	if (value)
	{
		char *new_line = strchr(str, '\n');
		if (new_line)
			*new_line = '\0';
		else
			while (getchar() != '\0')
				continue;
	}

	return value;
}
