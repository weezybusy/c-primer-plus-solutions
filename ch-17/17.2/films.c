/* 17.2.c -- Suppose list.h (Listing 17.3) uses the following definition of a
 * list:
 *
 *	typedef struct list
 *	{
 *		Node * head;
 *		Node * end;
 *	} List;
 *
 * Rewrite the list.c (Listing 17.5) functions to fit this definition and test
 * the resulting code with the films3.c (Listing 17.4) program.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

void show_movies(Item);
char *sgets(char *, int);

int main(void)
{
    List movies;
    Item tmp;
    
    InitializeList(&movies);
    if (ListIsFull())
    {
        fprintf(stderr,"No memory available! Bye!\n");
        exit(1);
    }
    
    printf("Enter first movie title: ");
    while (sgets(tmp.title, TSIZE) != NULL && tmp.title[0] != '\0')
    {
        printf("Enter your rating <0-10>: ");
        scanf("%d", &tmp.rating);
        while(getchar() != '\n')
            continue;

        if (AddItem(tmp, &movies)==false)
        {
            fprintf(stderr,"Problem allocating memory!\n");
            break;
        }

        if (ListIsFull())
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
        printf("\nHere is the movie list:\n");
	printf("-------------------------\n");
	printf("MOVIE TITLE        RATING\n");
	printf("-------------------------\n");
        Traverse(&movies, show_movies);
    }
    printf("\nYou entered %d movies.\n\n", ListItemCount(&movies));
    
    EmptyTheList(&movies);
    
    return 0;
}

void show_movies(Item item)
{
    printf("%-19s%-2d\n", item.title, item.rating);
}

char *sgets(char *st, int n)
{
    char *value = fgets(st, n, stdin);
    if (value != NULL)
    {
        char *new_line = strchr(st, '\n');
        if (new_line != NULL)
            *new_line = '\0';
        else
            while (getchar() != '\n')
                continue;
    }

    return value;
}
