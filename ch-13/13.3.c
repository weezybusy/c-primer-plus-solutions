/*
 * Write a file copy program that prompts the user to enter the name of
 * a text file to act as the source file and the name of an output file.
 * The program should use the toupper() function from ctype.h to convert
 * all text to uppercase as it’s written to the output file. Use standard
 * I/O and the text mode.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define SIZE 81

char *sgets(char *st, int n);

int main(void)
{
	FILE *source;
	FILE *target;
	char sname[SIZE];
	char tname[SIZE];
	int ch;

	printf("Enter a name of a file to copy from: ");
	sgets(sname, SIZE);

	if ((source = fopen(sname, "r")) == NULL) {
		fprintf(stderr, "Can't open %s.", sname);
		exit(EXIT_FAILURE);
	}

	printf("Enter a name of a file to copy to: ");
	sgets(tname, SIZE);
	if ((target = fopen(tname, "w")) == NULL) {
		fprintf(stderr, "Can't open %s.", tname);
		exit(EXIT_FAILURE);
	}

	while ((ch = getc(source)) != EOF) {
		putc(toupper(ch), target);
	}

	if (fclose(source) != 0) {
		fprintf(stderr, "Can't close %s.\n", sname);
		exit(EXIT_FAILURE);
	}

	if (fclose(target) != 0) {
		fprintf(stderr, "Can't close %s.\n", tname);
		exit(EXIT_FAILURE);
	}

	return 0;
}

char *sgets(char *st, int n)
{
	char *ret_val;
	char *new_line;

	ret_val = fgets(st, n, stdin);
	if (ret_val) {
		new_line = strchr(st, '\n');
		if (new_line)
			*new_line ='\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}
