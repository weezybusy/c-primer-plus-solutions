/*
 * 13.7_b.c -- Write a program that opens two files. You can obtain
 * the filenames either by using command-line arguments or by
 * soliciting the user to enter them.
 *
 * 	a. Have the program print line 1 of the first file, line
 * 	   1 of the second file, line 2 of the first file, line 2
 * 	   of the second file, and so on, until the last line of
 * 	   the longer file (interms of lines) is printed.
 *
 * 	b. Modify the program so that lines with the same line number
 * 	   are printed on the same line.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 256

int main(int argc, char *argv[])
{
	FILE *one;
	FILE *two;
	char line[SIZE];
	char *new_line;

	if (argc != 3) {
		printf("Usage: %s file1 file2\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if ((one = fopen(argv[1], "r")) == NULL) {
		printf("Could not open file %s for input\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	if ((two = fopen(argv[2], "r")) == NULL) {
		printf("Could not open file %s for input\n", argv[2]);
		exit(EXIT_FAILURE);
	}

	while (fgets(line, SIZE, one)) {
		new_line = strchr(line, '\n');
		if (new_line)
			*new_line = '\0';
		fputs(line, stdout);
		putchar(' ');
		if (fgets(line, SIZE, two))
			fputs(line, stdout);
		else
			putchar('\n');
	}

	while (fgets(line, SIZE, two)) {
		fputs(line, stdout);
	}

	if (fclose(one) != 0)
		printf("Could not close file %s\n", argv[1]);

	if (fclose(two) != 0)
		printf("Could not close file %s\n", argv[2]);

	return 0;
}
