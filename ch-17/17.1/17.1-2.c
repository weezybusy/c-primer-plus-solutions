/*
 * 17.1.1.c -- Modify Listing 17.2 so that it displays the movie list
 * both in the original order and in reverse order. One approach is
 * to modify the linked-list definition so that the list can be
 * traversed in both directions. Another approach is to use recursion.
 *
 * This is version with changed linked-list definition
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 20

typedef struct node
{
	char title[SIZE];
	int rating;
	struct node *prev;
	struct node *next;
} Node;

typedef Node *Film;

char *sgets(char *, int);

int main(void)
{
	Film head = NULL;
	Film prev, curr;
	char input[SIZE];

	printf("Enter first movie title: ");
	while (sgets(input, SIZE) != NULL && input[0] != '\0')
	{
		curr = malloc(sizeof(Node));
		if (head == NULL)
		{
			head = curr;
			head->prev = NULL;
		}
		else
		{
			prev->next = curr;
			curr->prev = prev;
		}
		curr->next = NULL;

		strcpy(curr->title, input);
		printf("Now enter your rating: ");
		scanf("%d", &curr->rating);
		while (getchar() != '\n')
			continue;
		prev = curr;
		printf("Enter next movie title: ");
	}

	if (head == NULL)
	{
		printf("\nNo entries found.\n");
	}
	else
	{
		printf("\nHere's the movie list:\n");
		printf("----------------------\n");
		for (curr = head; curr != NULL; curr = curr->next)
		{
			printf("Movie: %-19s Rating: %d\n",
					curr->title, curr->rating);
			prev = curr;
		}

		printf("\nHere's the list in reverse order:\n");
		printf("---------------------------------\n");
		for (curr = prev; curr != NULL; curr = curr->prev)
			printf("Movie: %-19s Rating: %d\n",
					curr->title, curr->rating);
	}
	putchar('\n');

	while (head != NULL)
	{
		curr = head->next;
		free(head);
		head = curr;
	}

	return 0;
}

char *sgets(char *str, int n)
{
	char *value = fgets(str, n, stdin);
	if (value != NULL)
	{
		char *new_line = strchr(str, '\n');
		if (new_line != NULL)
			*new_line = '\0';
		else
			while (getchar() != '\n')
				continue;
	}

	return value;
}
