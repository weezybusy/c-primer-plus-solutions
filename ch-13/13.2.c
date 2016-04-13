/*
 * 13.2.c -- Write a file-copy program that takes the original and the
 * copy file from the command line. Use standard I/O and the binary mode,
 * if possible.
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	FILE *source;
	FILE *target;
	int ch;

	if (argc < 3) {
		fprintf(stderr, "Usage: %s sourcefile targetfile\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if ((source = fopen(argv[1], "rb")) == NULL) {
		fprintf(stderr, "Can't open %s.\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	if ((target = fopen(argv[2], "wb")) == NULL) {
		fprintf(stderr, "Can't open %s.\n", argv[2]);
		exit(EXIT_FAILURE);
	}

	while ((ch = getc(source)) != EOF)
		putc(ch, target);

	if (fclose(source) != 0) {
		fprintf(stderr, "Can't close %s.\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	if (fclose(target) != 0) {
		fprintf(stderr, "Can'r close %s.\n", argv[2]);
		exit(EXIT_FAILURE);
	}

	return 0;
}
