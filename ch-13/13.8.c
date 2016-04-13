/*
 * 13.8.c -- Write a program that takes as command-line arguments:
 * a character and zero or more filenames. If no arguments follow
 * the character, have the program read the standard input. Otherwise,
 * have it open each file in turn and report how many times the
 * character appears in each file. The filename and the character
 * itself should be reported along with the count. Include error-
 * checking to see whether the number of arguments is correct and
 * whether the files can be opened. If a file can’t be opened, have
 * the program report that fact and go on to the next file.
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	FILE *fp;
	int in = argv[1][0];
	int ch;
	int count = 0;

	if (argc < 2) {
		fprintf(stderr, "Usage: %s character file1 ...\n", argv[0]);
		exit(EXIT_FAILURE);
	} else if (argc == 2) {
		puts("Enter a string:");
		while ((ch = getc(stdin)) != '\n')
			if (ch == in)
				count++;
		printf("There %s %d of '%c' in entered string.\n",
				count > 1 ? "are" : "is",
				count, in);
	} else {
		for (int i = 2; i < argc; i++) {
			if ((fp = fopen(argv[i], "r")) == NULL) {
				fprintf(stderr, "Can't open %s.\n", argv[i]);
				continue;
			}
			while ((ch = getc(fp)) != EOF)
				if (ch == in)
					count++;

			printf("There %s %d of '%c' in %s.\n",
					count > 1 ? "are" : "is",
					count, in, argv[i]);
			count = 0;
			if (fclose(fp) != 0)
				fprintf(stderr, "Can't close %s.\n", argv[i]);
		}
	}
	return 0;
}
