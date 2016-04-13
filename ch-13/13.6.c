/*
 * 13.6.c -- Programs using command-line arguments rely on the
 * user’s memory of how to use them correctly. Rewrite the program
 * in Listing 13.2 so that, instead of using command-line arguments,
 * it prompts the user for the required information.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 81

char *sgets(char *st, int n);

int main(void)
{
    FILE *in;
    FILE *out;
    char file_name[SIZE];
    char name[SIZE];
    int ch;
    int count = 0;

    printf("Enter a name of a source file: ");
    sgets(file_name, SIZE);

    if ((in = fopen(file_name, "r")) == NULL) {
        fprintf(stderr, "I couldn't open the file \"%s\"\n", file_name);
        exit(EXIT_FAILURE);
    }

    strncpy(name, file_name, SIZE - 5);
    name[SIZE - 5] = '\0';
    strcat(name,".red");

    if ((out = fopen(name, "w")) == NULL) {
        fprintf(stderr,"Can't create output file.\n");
        exit(EXIT_FAILURE);
    }

    while ((ch = getc(in)) != EOF)
        if (count++ % 3 == 0)
            putc(ch, out);

    if (fclose(in) != 0) {
        fprintf(stderr,"Error in closing files\n");
	exit(EXIT_FAILURE);
    }

    if (fclose(out) != 0) {
        fprintf(stderr,"Error in closing files\n");
	exit(EXIT_FAILURE);
    }

    return 0;
}

char *sgets(char *st, int n)
{
	char * ret_val;
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
