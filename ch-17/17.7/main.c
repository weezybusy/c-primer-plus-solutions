/**
 * 17.7.c -- Write a program that opens and reads a text file and records how
 * many times each word occurs in the file. Use a binary search tree modified
 * to store both a word and the number of times it occurs. After the program
 * has read the file, it should offer a menu with three choices. The first is
 * to list all the words along with the number of occurrences. The second is
 * to let you enter a word, with the program reporting how many times the word
 * occurred in the file. The third choice is to quit.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tree.h"

/* local function declarations */
static char menu(void);
static void del_punct(char *);
static void show_words(const Tree *);
static void show_item(const Item);
static void find_word(const Tree *);
static char *sgets(char *, int);
static void clean(void);

/* main function */
int main(void)
{
	FILE *fp;
	fp = fopen("../file", "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Couldn't open file\n");
		exit(EXIT_FAILURE);
	}

	Tree words;
	InitializeTree(&words);

	Item tmp;
	unsigned int word_counter = 0;
	printf("\nReading file... ");
	while (fscanf(fp, "%s", tmp.word) == 1 && words.size != MAX_ITEMS)
	{
		word_counter++;
		del_punct(tmp.word);
		AddItem(&words, &tmp);
	}
	printf("Done!\n");

	char ch;
	while ((ch = menu()) != 'q')
		switch (ch)
		{
			case 's':
				show_words(&words);
				printf("%-20s %d\n", "TOTAL:", word_counter);
				break;
			case 'f':
				find_word(&words);
				break;
			default:
				fprintf(stderr, "Switch error!\n");
		}

	DeleteAll(&words);

	if (fclose(fp) != 0)
	{
		fprintf(stderr, "Fail to close file.\n");
		exit(EXIT_FAILURE);
	}

	return EXIT_SUCCESS;
}

/* local function definitions */
static char menu(void)
{
	printf("\nChoose an option:\n");
	printf("-----------------\n");
	printf("s) show word list\nf) find a word\nq) quit\n\n");
	printf("Your choice: ");

	char ch;
	while ((ch = getchar()) != EOF)
	{
		if (ch == '\n')
		{
			printf("Please, enter s, f, or q: ");
			continue;
		}
		else
		{
			clean();
			if (strchr("sfq", ch) == NULL)
				printf("Please, enter s, f, or q: ");
			else
				break;
		}
	}

	if (ch == EOF)
		ch = 'q';

	return ch;
}

static void del_punct(char *word)
{
	size_t size = strlen(word) - 1;
	if (strchr(PUNCT, word[0]))
		word = word + 1;
	if (strchr(PUNCT, word[size]))
		word[size] = '\0';
}

static void show_words(const Tree *pt)
{
	if (pt == NULL)
	{
		printf("No entries.\n");
	}
	else
	{
		printf("\n%-20s %s\n", "WORD", "COUNTER");
		printf("----------------------------\n");
		Traverse(pt, show_item);
		printf("----------------------------\n");
	}
}

static void show_item(const Item item)
{
	printf("%-20s %-3d\n", item.word, item.count);
}

static void find_word(const Tree *pt)
{

	printf("\nI want to find: ");
	char entry[SIZE];
	sgets(entry, SIZE);

	Item item;
	strcpy(item.word, entry);

	const Node *tmp = WhereInTree(&item, pt);
	if (tmp == NULL)
	{
		printf("\nThere's no such word in file.\n");
	}
	else
	{
		printf("\n%-20s %s\n", "WORD", "COUNTER");
		printf("----------------------------\n");
		show_item(tmp->item);
		printf("----------------------------\n");
	}
}

static char *sgets(char *str, int n)
{
	char *value = fgets(str, n, stdin);
	if (value != NULL)
	{
		char *new_line = strchr(str, '\n');
		if (new_line != NULL)
			*new_line = '\0';
		else
			clean();
	}

	return value;
}

static void clean(void)
{
	while (getchar() != '\n')
		continue;
}
