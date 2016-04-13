/*
 * 15.3.c -- Write a function that takes an int argument and returns the number
 * of “on” bits in the argument. Test the function in a program.
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int count_on_bits(int);

int main(int argc, char *argv[])
{
	if (argc < 2)
		exit(EXIT_FAILURE);
	
	int number = atoi(argv[1]);
	int number_of_on_bits = count_on_bits(number);

	printf("Number of \"on\" bits in number %d is %d.\n",
			number, number_of_on_bits);
	return 0;
}

int count_on_bits(int n)
{
	const int size = CHAR_BIT * sizeof(int);
	int bits_on = 0;

	for (int i = size - 1; i >= 0; i--) {
		if (n & 0x1)
			bits_on++;
		n >>= 1;
	}

	return bits_on;
}

