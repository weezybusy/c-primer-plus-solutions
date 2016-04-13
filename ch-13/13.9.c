/*
 * 13.9.c -- Modify the program in Listing 13.3 so that each word is
 * numbered according to the order in which it was added to the list,
 * starting with 1. Make sure that, when the program is run a second
 * time, new word numbering resumes where the previous numbering left
 * off.
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX 41

int main(void)
{
	FILE *fp;
	char words[MAX];
	int count = 0;

	if ((fp = fopen("wordy", "a+")) == NULL) {
		fprintf(stdout,"Can't open \"wordy\" file.\n");
		exit(EXIT_FAILURE);
	}

	rewind(fp);
	while (fgets(words, MAX, fp))
		count++;
	rewind(fp);

	puts("Enter words to add to the file; press the # to quit:");
	while ((fscanf(stdin,"%40s", words) == 1) && words[0] != '#')
		fprintf(fp, "%3d. %s\n", ++count, words);

	puts("File contents:");
	rewind(fp);
	while (fgets(words, MAX, fp))
		fputs(words, stdout);

	if (fclose(fp) != 0)
		fprintf(stderr,"Error closing file.\n");

	puts("Done!");

	return 0;
}
