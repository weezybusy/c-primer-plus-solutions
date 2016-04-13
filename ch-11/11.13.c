/*
 * 11.13.c --
 * Write a program that echoes the command-line arguments in reverse
 * word order. That is, if the command-line arguments are 'see' 'you' 'later',
 * the program should print later you see.
 */

#include <stdio.h>

int main(int argc, const char *argv[])
{
	for (int i = argc - 1; i > 0; i--)
		puts(argv[i]);

	return 0;
}
