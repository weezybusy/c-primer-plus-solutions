/*
 * 13.4.c -- Write a program that sequentially displays onscreen all
 * the files listed in the command line. Use argc to control a loop.
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	FILE *fp;
	int ch;

	if (argc < 2) {
		fprintf(stderr, "Usage: %s file1 file2 ...\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	for (int i = 1; i <= argc; i++) {
		if ((fp = fopen(argv[i], "r")) == NULL) {
			fprintf(stderr, "Can't open %s.", argv[i]);
			exit(EXIT_FAILURE);
		}

		while ((ch = getc(fp)) != EOF)
			putc(ch, stdout);

		if (fclose(fp) != 0) {
			fprintf(stderr, "Can't close %s.\n", argv[i]);
			exit(EXIT_FAILURE);
		}

	}

	return 0;
}
