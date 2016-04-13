/*
 * 15.1.c -- Write a function that converts a binary string to a numeric value.
 * That is, if you have
 * 	char * pbin = "01001001";   
 * you can pass pbin as an argument to the function and have the function
 * return an int value of 25.    
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int b2i(char *, int);

int main(int argc, char *argv[])
{
	if (argc < 2)
		exit(EXIT_FAILURE);

	const size_t size = strlen(argv[1]);
	int digit;

	digit = b2i(argv[1], size - 1);
	printf("%s = %d\n", argv[1], digit);

	return 0;
}

int b2i(char *b, int n)
{
	int d = 0;
	for (int i = n; i >= 0; i--)
		if (b[i] - 48)
			d += 1 << (n - i);

	return d;
}
