/*
 * 13.14.c -- Digital images, particularly those radioed back from
 * spacecraft, may have glitches. Add a de-glitching function to
 * programming exercise 12. It should compare each value to its
 * immediate neighbors to the left and right, above and below.
 * If the value differs by more than 1 from each of its neighbors,
 * recompares the value with the average of the neighboring values.
 * You should round the average to the nearest integer value. Note
 * that the points along the boundaries have fewer than four
 * neighbors, so they require special handling.
 */

#include <stdio.h>
#include <stdlib.h>

#define ROWS 20
#define COLS 30
const char chars[] = " .':~*=&%#";
const char *errmesg[] = {
	"Can't open %s.\n",
	"Error getting data from %s.\n",
	"Can't close %s.\n"
};

void make_pic(int a[][COLS], char b[][COLS + 1]);
void unglitch(int a[][COLS]);
void print(int a[][COLS]);

int main(void)
{
	int row, col, line;
	FILE *source_fp;
	FILE *target_fp;
	char source[] = "file1";
	char target[] = "file2";
	int pic_in[ROWS][COLS];
	char pic_out[ROWS][COLS + 1];

	if ((source_fp = fopen(source, "r")) == NULL) {
		fprintf(stdout, errmesg[0], source);
		exit(EXIT_FAILURE);
	}

	for (row = 0; row < ROWS; row++)
		for (col = 0; col < COLS; col++)
			fscanf(source_fp, "%d", &pic_in[row][col]);

	if (ferror(source_fp)) {
		fprintf(stderr, errmesg[1], source);
		exit(EXIT_FAILURE);
	}

	if ((target_fp = fopen(target, "w")) == NULL) {
		fprintf(stderr, errmesg[0], target);
		exit(EXIT_FAILURE);
	}

	make_pic(pic_in, pic_out);
	puts("\nImage before correction:");
	puts("------------------------------");
	for (line = 0; line < ROWS; line++) {
		fprintf(target_fp, "%s\n", pic_out[line]);
		puts(pic_out[line]);
	}
	puts("------------------------------");

	unglitch(pic_in);

	make_pic(pic_in, pic_out);
	puts("\nImage after correction:");
	puts("------------------------------");
	for (line = 0; line < ROWS; line++) {
		fprintf(target_fp, "%s\n", pic_out[line]);
		puts(pic_out[line]);
	}
	puts("------------------------------");

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

void make_pic(int a[][COLS], char b[][COLS + 1])
{
	int row, col;
	for (row = 0; row < ROWS; row++) {
		for (col = 0; col < COLS; col++)
			b[row][col] = chars[a[row][col]];
		b[row][col] = '\0';
	}
}

void unglitch(int a[][COLS])
{
	float sum;
	int compares;
	int count;

	for (int row = 0; row < ROWS; row++) {
		for (int col = 0; col < COLS; col++) {
			sum = 0.0;
			count = 0;
			if (row == 0 && col == 0) {
				compares = 2;
				if (abs(a[row][col] - a[row][col+1]) > 1) {
					sum += a[row][col+1];
					count++;
				}
				if (abs(a[row][col] - a[row+1][col]) > 1) {
					sum += a[row+1][col];
					count++;
				}
			} else if (row == 0 && col == 29) {
				compares = 2;
				if (abs(a[row][col] - a[row][col-1]) > 1) {
					sum += a[row][col-1];
					count++;
				}
				if (abs(a[row][col] - a[row-1][col]) > 1) {
					sum += a[row-1][col];
					count++;
				}
			} else if ((row == 0 && col > 0) &&
					(row == 0 && col < 29)) {
				compares = 3;
				if (abs(a[row][col] - a[row+1][col]) > 1) {
					sum += a[row+1][col];
					count++;
				}
				if (abs(a[row][col] - a[row][col-1]) > 1) {
					sum += a[row][col-1];
					count++;
				}
				if (abs(a[row][col] - a[row][col+1]) > 1) {
					sum += a[row][col+1];
					count++;
				}
			} else if (row == 19 && col == 0) {
				compares = 2;
				if (abs(a[row][col] - a[row-1][col]) > 1) {
					sum += a[row-1][col];
					count++;
				}
				if (abs(a[row][col] - a[row][col+1]) > 1) {
					sum += a[row][col+1];
					count++;
				}
			} else if (row == 19 && col == 29) {
				compares = 2;
				if (abs(a[row][col] - a[row-1][col]) > 1) {
					sum += a[row-1][col];
					count++;
				}
				if (abs(a[row][col] - a[row][col-1]) > 1) {
					sum += a[row][col-1];
					count++;
				}
			} else if ((row == 19 && col > 0) &&
					(row == 19 && col < 29)) {
				compares = 3;
				if (abs(a[row][col] - a[row][col-1]) > 1) {
					sum += a[row][col-1];
					count++;
				}
				if (abs(a[row][col] - a[row][col+1]) > 1) {
					sum += a[row][col+1];
					count++;
				}
				if (abs(a[row][col] - a[row-1][col]) > 1) {
					sum += a[row-1][col];
					count++;
				}
			} else {
				compares = 4;
				if (abs(a[row][col] - a[row-1][col]) > 1) {
					sum += a[row-1][col];
					count++;
				}
				if (abs(a[row][col] - a[row+1][col]) > 1) {
					sum += a[row+1][col];
					count++;
				}
				if (abs(a[row][col] - a[row][col-1]) > 1) {
					sum += a[row][col-1];
					count++;
				}
				if (abs(a[row][col] - a[row][col+1]) > 1) {
					sum += a[row][col+1];
					count++;
				}
			}
			if (count == compares)
				a[row][col] = (int) (sum / compares + 0.5);
		}
	}
}
