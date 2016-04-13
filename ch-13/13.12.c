/*
 * 13.12.c -- Create a text file consisting of 20 rows of 30 integers.
 * The integers should be in the range 0–9 and be separated by spaces.
 * The file is a digital representation of a picture, with the values
 * 0 through 9 representing increasing levels of darkness. Write a
 * program that reads the contents of the file into a 20-by-30 array
 * of ints. In a crude approach toward converting this digital
 * representation to a picture, have the program use the values in
 * this array to initialize a 20-by-31 array of chars, with a 0 value
 * corresponding to a space character, a 1 value to the period
 * character, and so on, with each larger number represented by a
 * character that occupies more space. For example, you might use #
 * to represent 9. The last character (the 31st) in each row should
 * be a null character, making it an array of 20 strings. Have the
 * program display the resulting picture (that is, print the strings)
 * and also store the result in a text file. For example, suppose you
 * start with this data:
 *
 * 0 0 9 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 2 0 0 0 0 0 0 0 0 0 0 0
 * 0 0 0 0 9 0 0 0 0 0 0 0 5 8 9 9 8 5 5 2 0 0 0 0 0 0 0 0 0 0
 * 0 0 0 0 0 0 0 0 0 0 0 0 5 8 1 9 8 5 4 5 2 0 0 0 0 0 0 0 0 0
 * 0 0 0 0 9 0 0 0 0 0 0 0 5 8 9 9 8 5 0 4 5 2 0 0 0 0 0 0 0 0
 * 0 0 9 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 0 0 4 5 2 0 0 0 0 0 0 0
 * 0 0 0 0 0 0 0 0 0 0 0 0 5 8 9 1 8 5 0 0 0 4 5 2 0 0 0 0 0 0
 * 0 0 0 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 0 0 0 0 4 5 2 0 0 0 0 0
 * 5 5 5 5 5 5 5 5 5 5 5 5 5 8 9 9 8 5 5 5 5 5 5 5 5 5 5 5 5 5
 * 8 8 8 8 8 8 8 8 8 8 8 8 5 8 9 9 8 5 8 8 8 8 8 8 8 8 8 8 8 8
 * 9 9 9 9 0 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 3 9 9 9 9 9 9 9
 * 8 8 8 8 8 8 8 8 8 8 8 8 5 8 9 9 8 5 8 8 8 8 8 8 8 8 8 8 8 8
 * 5 5 5 5 5 5 5 5 5 5 5 5 5 8 9 9 8 5 5 5 5 5 5 5 5 5 5 5 5 5
 * 0 0 0 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 0 0 0 0 0 0 0 0 0 0 0 0
 * 0 0 0 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 0 0 0 0 6 6 0 0 0 0 0 0
 * 0 0 0 0 2 2 0 0 0 0 0 0 5 8 9 9 8 5 0 0 5 6 0 0 6 5 0 0 0 0
 * 0 0 0 0 3 3 0 0 0 0 0 0 5 8 9 9 8 5 0 5 6 1 1 1 1 6 5 0 0 0
 * 0 0 0 0 4 4 0 0 0 0 0 0 5 8 9 9 8 5 0 0 5 6 0 0 6 5 0 0 0 0
 * 0 0 0 0 5 5 0 0 0 0 0 0 5 8 9 9 8 5 0 0 0 0 6 6 0 0 0 0 0 0
 * 0 0 0 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 0 0 0 0 0 0 0 0 0 0 0 0
 * 0 0 0 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 0 0 0 0 0 0 0 0 0 0 0 0
 *
 * Result example:
 *
 *   #         *%##%*'
 *     #       *%##%**'
 *             *%.#%*~*'
 *     #       *%##%* ~*'
 *   #         *%##%*  ~*'
 *             *%#.%*   ~*'
 *             *%##%*    ~*'
 * *************%##%*************
 * %%%%%%%%%%%%*%##%*%%%%%%%%%%%%
 * #### #################:#######
 * %%%%%%%%%%%%*%##%*%%%%%%%%%%%%
 * *************%##%*************
 *             *%##%*
 *             *%##%*    ==
 *     ''      *%##%*  *=  =*
 *     ::      *%##%* *=....=*
 *     ~~      *%##%*  *=  =*
 *     **      *%##%*    ==
 *             *%##%*
 *             *%##%*
 */

#include <stdio.h>
#include <stdlib.h>

#define ROWS 20
#define COLS 30
#define SIZE 10
const char chars[SIZE + 1] = " .':~*=&%#";
const char *errmesg[] = {
	"Can't open %s.\n",
	"Error getting data from %s.\n",
	"Can't close %s.\n"
};

void make_pic(int a[][COLS], char b[][COLS + 1], int rows);

int main(void)
{
	FILE *source_fp;
	FILE *target_fp;
	char source[] = "file1";
	char target[] = "file2";
	char pic_out[ROWS][COLS + 1];
	int pic_in[ROWS][COLS];
	int row, col, line;


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

	make_pic(pic_in, pic_out, ROWS);

	for (line = 0; line < ROWS; line++) {
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

void make_pic(int a[][COLS], char b[][COLS + 1], int rows)
{
	int row, col;

	for (row = 0; row < rows; row++) {
		for (col = 0; col < COLS; col++)
			b[row][col] = chars[a[row][col]];
		b[row][col] = '\0';
	}
}
