/*
 * 13.11.c -- Write a program that takes two command-line arguments.
 * The first is a string; the second is the name of a file. The program
 * should then search the file, printing all lines containing the
 * string. Because this task is line oriented rather than character
 * oriented, use fgets() instead of getc() . Use the standard C library
 * function strstr() (briefly described in exercise 7 of Chapter 11) to
 * search each line for the string. Assume no lines are longer than 255
 * characters.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 256
const char *errmesg[] = {
	"Usage: %s string filename.\n",
	"Can't open file.\n"
};

int main(int argc, char **argv)
{
	FILE *fp;
	char line[SIZE];

	if (argc != 3) {
		fprintf(stderr, errmesg[0], argv[0]);
		exit(EXIT_FAILURE);
	}

	if ((fp = fopen(argv[2], "r")) == NULL) {
		fprintf(stdout,errmesg[1], argv[2]);
		exit(EXIT_FAILURE);
	}

	while (fgets(line, SIZE - 1, fp)) {
		if (strstr(line, argv[1]))
			fputs(line, stdout);
	}

	if (fclose(fp) != 0) {
		fprintf(stderr,"Error closing file.\n");
		exit(EXIT_FAILURE);
	}

	return 0;
}
