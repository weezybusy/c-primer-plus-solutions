/*
 * 15.5.c -- Write a function that rotates the bits of an unsigned int by a
 * specified number of bits to the left. For instance, rotate_l(x,4) would move
 * the bits in x four places to the left, and the bits lost from the left end
 * would reappear at the right end. That is, the bit moved out of the high-order
 * position is placed in the low-order position. Test the function in a program.    
 */

#include <stdio.h>
#include <limits.h>

unsigned int rotate(unsigned int, int);
char *int2bin_str(unsigned int, char *);

int main(void)
{
	unsigned int value;
	unsigned int rotated;
	char bin_str1[CHAR_BIT * sizeof(int) + 1];
	char bin_str2[CHAR_BIT * sizeof(int) + 1];
	unsigned int places = 3;

	printf("Enter an integer or 0 to quit: _\b");
	while (scanf("%ud", &value) && value > 0) {
		printf("Enter the number of bits to be rotated: _\b");
		scanf("%ud", &places);
		rotated = rotate(value, places);
		int2bin_str(value, bin_str1);
		int2bin_str(rotated, bin_str2);
		printf("%u after rotation is %u.\n", value, rotated);
		printf("%s after rotation is %s.\n", bin_str1, bin_str2);
		printf("Next value: _\b");
	}

	return 0;
}

unsigned int rotate(unsigned int n, int b)
{
	static const int size = CHAR_BIT * sizeof(unsigned int);
	unsigned int overflow = n >> (size - b);

	b %= size;
	return (n << b) | overflow;
}

char *int2bin_str(unsigned int n, char *s)
{
	static const int size = CHAR_BIT * sizeof(int);
	for (int i = size - 1; i >= 0; i--) {
		s[i] = (n & 0x1) + '0';
		n >>= 1;	
	}
	s[size] = '\0';

	return s;
}
