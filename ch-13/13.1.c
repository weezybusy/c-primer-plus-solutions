/*
 * 13.1.c -- Modify Listing 13.1 so that it solicits the user to
 * enter the filename and reads the user’s response instead of
 * using command-line arguments.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 81

char *sgets(char *st, int n);

int main(void)
{
	int ch;
	FILE *fp;
	char file_name[SIZE];
	unsigned long count = 0;
	char *check;

	do {
		printf("Enter name of a file: ");
		check = sgets(file_name, SIZE);
	} while (!check && file_name[0] != '\0');


	if ((fp = fopen(file_name, "r")) == NULL) {
		printf("Can't open %s\n", file_name);
		exit(EXIT_FAILURE);
	}

	while ((ch = getc(fp)) != EOF) {
		putc(ch, stdout);
		count++;
	}

	fclose(fp);
	printf("File %s has %lu characters\n", file_name, count);

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
			*new_line = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}
