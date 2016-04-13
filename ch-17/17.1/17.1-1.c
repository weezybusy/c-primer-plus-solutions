/*
 * 17.1.1.c -- Modify Listing 17.2 so that it displays the movie list
 * both in the original order and in reverse order. One approach is
 * to modify the linked-list definition so that the list can be
 * traversed in both directions. Another approach is to use recursion.
 *
 * This is version with recursion
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 20

typedef struct node
{
	char title[SIZE];
	int rating;
	struct node *next;
} Node;

typedef Node *Film;

char *sgets(char *, int);
void show_rec(Film);

int main(void)
{
	Film head = NULL;
	Film prev, curr;
	char input[SIZE];

	printf("Enter first movie title: ");
	while (sgets(input, SIZE) != NULL && input[0] != '\0')
	{
		curr = malloc(sizeof(Node));
		if (curr == NULL)
		{
			fprintf(stderr, "Failed allocate memory!\n");
			exit(EXIT_FAILURE);
		}

		if (head == NULL)
			head = curr;
		else
			prev->next = curr;
		curr->next = NULL;

		strcpy(curr->title, input);
		printf("Enter your rating: ");
		scanf("%d", &curr->rating);
		while (getchar() != '\n')
			continue;
		prev = curr;
		printf("Enter next movie title (empty line to quit): ");
	}

	if (head == NULL)
	{
		printf("\nNo entries found.\n");
	}
	else
	{
		printf("\nHere's the movies list:\n");
		printf("-----------------------\n");
		curr = head;
		while (curr != NULL)
		{
			printf("Movie: %-19s Rating: %d\n",
					curr->title, curr->rating);
			curr = curr->next;
		}

		printf("\nHere's reversed list:\n");
		printf("---------------------\n");
		show_rec(head);
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

void show_rec(Film head)
{
	if (head->next != NULL)
		show_rec(head->next);
	printf("Movie: %-19s Rating: %d\n", head->title, head->rating);
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
