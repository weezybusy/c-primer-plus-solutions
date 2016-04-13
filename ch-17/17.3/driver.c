/* 
 * 17.3.c -- suppose list.h (Listing 17.3) uses the following definition of a
 * list:
 *
 *	#define MAXSIZE 100
 *	typedef struct list
 *	{
 *		Item entries[MAXSIZE];
 *		int items;
 *	} List;
 *
 * Rewrite the list.c (Listing 17.5) functions to fit this definition and test
 * the resulting code with the films3.c (Listing 17.4) program.
 */

#include <stdio.h>
#include <string.h>
#include "list.h"

void show_movies(Item);
char *sgets(char *, int);

int main(void)
{
	List movies;
	Item tmp;

	InitializeList(&movies);

	printf("\nEnter first movie title: ");
	while (sgets(tmp.title, TSIZE) != NULL && tmp.title[0] != '\0')
	{
		printf("Enter your rating <0-10>: ");
		scanf("%d", &tmp.rating);
		while(getchar() != '\n')
			continue;

		if (AddItem(tmp, &movies) == false)
		{
			fprintf(stderr,"Failed add item!\n");
			break;
		}

		if (ListIsFull(&movies))
		{
			printf("The list is now full.\n");
			break;
		}
		printf("Enter next movie title (empty line to stop): ");
	}

	if (ListIsEmpty(&movies))
	{
		printf("\nNo data entered.\n");
	}
	else
	{
		printf("\n%-20s%-6s\n", "MOVIES", "RATING");
		printf("--------------------------\n");
		Traverse(&movies, show_movies);
	}
	printf("\nYou've entered %d movies.\n\n", ListItemCount(&movies));

	EmptyTheList(&movies);

	return 0;
}

void show_movies(Item item)
{
	printf("%-20s%-2d\n", item.title, item.rating);
}

char *sgets(char *str, int n)
{
	char *value = fgets(str, n, stdin);
	if (value)
	{
		char *new_line = strchr(str, '\n');
		if (new_line)
			*new_line = '\0';
		else
			while (getchar() != '\n')
				continue;
	}

	return value;
}
