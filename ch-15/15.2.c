/*
 * 15.2.c -- Write a program that reads two binary strings as command-line
 * arguments and prints the results of applying the ~ operator to each number
 * and the results of applying the &, |, and ^ operators to the pair. Show the
 * results as binary strings. (If you don’t have a command-line environment
 * available, have the program read the strings interactively.) 
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

int str2int(char *);
void show_binary(int, char *, int);

int main(int argc, char *argv[])
{
	if (argc < 3)
		exit(EXIT_FAILURE);

	const int size = CHAR_BIT + 1;
	char binary[size];
	int num1 = str2int(argv[1]);
	int num2 = str2int(argv[2]);
	int number;

	number = ~num1;
	show_binary(number, binary, size);
	number = ~num2;
	show_binary(number, binary, size);
	number = num1 & num2;
	show_binary(number, binary, size);
	number = num1 | num2;
	show_binary(number, binary, size);
	number = num1 ^ num2;
	show_binary(number, binary, size);

	return 0;
}

int str2int(char *s)
{
	int size = strlen(s) - 1;
	int n = 0;
	for (int i = size; i >= 0; i--)
		if (s[i] - 48)
			n += 1 << (size - i);
	return n;
}

void show_binary(int n, char *s, int k)
{
	for (int i = k - 2; i >= 0; i--) {
		s[i] = (n & 1) + '0';
		n >>= 1;
	}
	s[k - 1] = '\0';

	puts(s);
}
