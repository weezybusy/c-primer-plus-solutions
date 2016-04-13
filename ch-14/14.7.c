/*
 * 14.7.c -- Modify Listing 14.14 so that as each record is read from
 * the file and shown to you, you are given the chance to delete the
 * record or to modify its contents. If you delete the record, use the
 * vacated array position for the next record to be read. To allow
 * changing the existing contents, you’ll need to use the "r+b" mode
 * instead of the "a+b" mode, and you’ll have to pay more attention to
 * positioning the file pointer so that appended records don’t overwrite
 * existing records. It’s simplest to make all changes in the data
 * stored in program memory and then write the final set of information
 * to the file. One approach to keeping track is to add a member to
 * the book structure that indicates whether it is to be deleted.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAXTITL  40
#define MAXAUTL  40
#define MAXBKS   10

struct book {
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
	bool delete;
};

char *sgets(char *s, int n);
void clean(void);
char get_choice(void);
void exclude_records(struct book *s[], int n);
void menu(struct book *s[], int n, int c, int *r);

int main(void)
{
	struct book library[MAXBKS];
	struct book *library_ptr[MAXBKS];
	FILE *pbooks;
	int size = sizeof(struct book);
	int file_count;
	int count = 0;
	int records_to_delete = 0;
	char choice;

	if ((pbooks = fopen("book.dat", "r")) == NULL) {
		fputs(" Can't open book.dat file\n", stderr);
		exit(EXIT_FAILURE);
	}

	while (count < MAXBKS && fread(&library[count], size, 1, pbooks) == 1) {
		library_ptr[count] = &library[count];
		
		if (count == 0)
			puts("\n CURRENT CONTENT OF book.dat:");
		else
			puts("\n NEXT RECORD");
		puts(" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
		printf(" %d) %s by %s: $%.2f\n", count + 1,
				library[count].title,
				library[count].author,
				library[count].value);
		puts(" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");

		printf(" Do you wish to change or delete this record? "
				"<y/n>: _\b");
		choice = get_choice();
		if (choice == 'y')
			menu(library_ptr, MAXBKS, count, &records_to_delete);
		count++;
	}
	fclose(pbooks);

	if (count == MAXBKS) {
		fputs(" The book.dat file is full.", stderr);
		exit(EXIT_FAILURE);
	}

	exclude_records(library_ptr, count);
	file_count = count - records_to_delete;
	count = file_count;

	puts("\n Add new book title (empty line to quit):");
	printf(" _\b");
	while (count < MAXBKS &&
			sgets(library[count].title, MAXTITL) != NULL &&
			library[count].title[0] != '\0') {
		puts(" Now enter the author:");
		printf(" _\b");
		sgets(library[count].author, MAXAUTL);
		puts(" Now enter the value:");
		printf(" _\b");
		scanf("%f", &library[count].value);
		count++;
		clean();
		if (count < MAXBKS) {
			puts(" Enter the next title "
					"(empty line to quit):");
			printf(" _\b");
		}
	}

	if (count > 0) {
		puts("\n LIST OF YOUR BOOKS");
		puts(" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
		for (int index = 0; index < count; index++)
			printf(" %d) %s by %s: $%.2f\n", index + 1,
					library[index].title,
					library[index].author,
					library[index].value);
		puts(" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");

		if ((pbooks = fopen("book.dat", "w")) == NULL) {
			fputs("Can't open file.\n", stderr);
			exit(EXIT_FAILURE);
		}

		rewind(pbooks);
		fwrite(library, size, count, pbooks);
	} else {
		puts("No books? Too bad.\n");
	}

	if (fclose(pbooks) != 0) {
		fputs("Can't close file!\n", stderr);
		exit(EXIT_FAILURE);
	}

	return 0;
}

char *sgets(char *s, int n)
{
	char *value;
	char *new_line;

	value = fgets(s, n, stdin);
	if (value) {
		new_line = strchr(s, '\n');
		if (new_line) 
			*new_line = '\0'; 
		else
			clean();
	}

	return value;
}

void clean(void)
{
	while (getchar() != '\n')
		continue;
}

char get_choice(void)
{
	int c;

	c = getchar();
	clean();
	while (c != 'y' && c != 'n') {
		fputs(" Invalid input! choose y for yes or n for no: _\b",
				stderr);
		c = getchar();
		clean();
	}

	return c;
}

void menu(struct book *s[], int n,  int c, int *r)
{
	char choice;

	do {
		printf("\n d) delete record\t" "m) modify record\t"
				"c) cancel\n");
		printf("\n Your choice: _\b");
		choice = getchar();
		clean();
	} while (choice != 'd' && choice != 'm' &&
			choice != 'c');

	switch (choice) {
	case 'd':
		s[c]->delete = true;
		(*r)++;
		puts(" Record marked for deletion.");
		break;
	case 'm':
		printf("\n Modify title? <y/n>: _\b");
		choice = get_choice();
		if (choice == 'y') {
			printf(" _\b");
			sgets(s[c]->title, MAXTITL);
		}
		printf("\n Modify author? <y/n>: _\b");
		choice = get_choice();
		if (choice == 'y') {
			printf(" _\b");
			sgets(s[c]->author, MAXAUTL);
		}
		printf("\n Modify value? <y/n>: _\b");
		choice = get_choice();
		if (choice == 'y') {
			printf(" _\b");
			scanf("%f", &s[c]->value);
			clean();
		}
		break;
	}
}

void exclude_records(struct book *s[], int n)
{
	struct book tmp[n];
	int count = 0;

	for (int i = 0; i < n; i++)
		if (s[i]->delete == false)
			tmp[count++] = *s[i];
	for (int i = 0; i < count; i++)
		*s[i] = tmp[i];
}
