/*
 * 15.4.c -- Write a function that takes two int arguments: a value and a bit
 * position. Have the function return 1 if that particular bit position is 1,
 * and have it return 0 otherwise. Test the function in a program. 
 */

#include <stdio.h>

int on_or_off(int, int);

int main(void)
{
	int value = 2;
	int bit_position = 0;
	int bit_status;

	bit_status = on_or_off(value, bit_position);
	printf("Bit status is %s.\n", bit_status ? "on" : "off");

	return 0;
}

int on_or_off(int v, int bp)
{
	return (v >> bp) & 0x1 ? 1 : 0;
}
