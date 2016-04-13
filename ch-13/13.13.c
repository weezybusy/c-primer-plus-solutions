/*
 * 13.13.c -- Do Programming Exercise 12, but use variable-length arrays
 * (VLAs) instead of standard arrays.
 */

#include <stdio.h>
#include <stdlib.h>

const char chars[] = " .':~*=&%#";
const char *errmesg[] = {
	"Can't open %s.\n",
	"Error getting data from %s.\n",
	"Can't close %s.\n"
};

void make_pic(int rows, int cols, int a[rows][cols], char b[rows][cols]);

int main(void)
{
	int rows = 20;
	int cols = 30;
	int row, col, line;
	FILE *source_fp;
	FILE *target_fp;
	char source[] = "file1";
	char target[] = "file2";
	int pic_in[rows][cols];
	char pic_out[rows][cols + 1];

	if ((source_fp = fopen(source, "r")) == NULL) {
		fprintf(stdout, errmesg[0], source);
		exit(EXIT_FAILURE);
	}

	for (row = 0; row < rows; row++)
		for (col = 0; col < cols; col++)
			fscanf(source_fp, "%d", &pic_in[row][col]);

	if (ferror(source_fp)) {
		fprintf(stderr, errmesg[1], source);
		exit(EXIT_FAILURE);
	}

	if ((target_fp = fopen(target, "w")) == NULL) {
		fprintf(stderr, errmesg[0], target);
		exit(EXIT_FAILURE);
	}

	make_pic(rows, cols, pic_in, pic_out);

	for (line = 0; line < rows; line++) {
		fprintf(target_fp, "%s\n", pic_out[line]);
		puts(pic_out[line]);
	}

	if (fclose(source_fp) != 0) {
		fprintf(stderr, errmesg[2], source);
		exit(EXIT_FAILURE);
	}

	if (fclose(target_fp) != 0) {
		fprintf(stderr, errmesg[2], target);
		exit(EXIT_FAILURE);
	}

	return 0;
}

void make_pic(int rows, int cols, int a[rows][cols], char b[rows][cols + 1])
{
	int row, col;

	for (row = 0; row < rows; row++) {
		for (col = 0; col < cols; col++)
			b[row][col] = chars[a[row][col]];
		b[row][col] = '\0';
	}
}
