/*
 * 13.10.c -- Write a program that opens a text file whose name is
 * obtained interactively. Set up a loop that asks the user to enter
 * a file position. The program then should print the part of the file
 * starting at that position and proceed to the next newline character.
 * Let negative or nonnumeric input terminate the user-input loop.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 41

char *sgets(char *st, int n);

int main(void)
{
	FILE *fp;
	char file_name[SIZE];
	char ch;
	long pos;
	long limit;

	printf("Enter file name: ");
	if (!sgets(file_name, SIZE) || file_name[0] == '\0') {
		fprintf(stderr, "Invlaid input.\n");
		exit(EXIT_FAILURE);
	}

	if ((fp = fopen(file_name, "r")) == NULL) {
		fprintf(stdout,"Can't open \"%s\".\n", file_name);
		exit(EXIT_FAILURE);
	}

	fseek(fp, 0L, SEEK_END);
	limit = ftell(fp) - 2;
	rewind(fp);

	printf("Enter a number from 0 to %ld (q to quit): ", limit);
	while (scanf("%ld", &pos) == 1 && pos >= 0L) {
		if (pos > limit) {
			fprintf(stderr, "%ld is too big number.\n", pos);
			printf("Try something in between 0 and %ld: ", limit);
			continue;
		}

		fseek(fp, pos, SEEK_SET);
		while ((ch = getc(fp)) != EOF && ch != '\n')
			putc(ch, stdout);
		putc('\n', stdout);
	}

	if (fclose(fp) != 0) {
		fprintf(stderr,"Error closing file.\n");
		exit(EXIT_FAILURE);
	}

	return 0;
}

char *sgets(char *st, int n)
{
	char *value;
	char *new_line;

	value = fgets(st, n, stdin);
	if (value) {
		new_line = strchr(st, '\n');
		if (new_line)
			*new_line = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return value;
}
