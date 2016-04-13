/* list.h -- header file for a simple list type */
#ifndef _LIST_H_
#define _LIST_H_
#include <stdbool.h>

#define TSIZE 40
struct film
{
    char title[TSIZE];
    int rating;
};

typedef struct film Item;

#define MAXSIZE 100
typedef struct list
{
	Item entries[MAXSIZE];
	int items;
} List;

void InitializeList(List *);
bool ListIsEmpty(const List *);
bool ListIsFull(const List *);
unsigned int ListItemCount(const List *);
bool AddItem(Item, List *);
void Traverse (const List *, void (*)(Item));
void EmptyTheList(List *);

#endif
