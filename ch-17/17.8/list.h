#ifndef _LIST_H_
#define _LIST_H_
#include <stdbool.h>
#define BOOL

#define SIZE 20

typedef struct list_item
{
	char name[SIZE];
	char kind[SIZE];
} List_Item;

typedef struct list_node
{
	List_Item item;
	struct list_node *next;
} List_Node;

typedef List_Node *List;

List List_New(void);
void List_Initialize(List *);
bool List_IsEmpty(const List *);
bool List_IsFull(void);
unsigned int List_Count(const List *);
List_Node *List_WhereIs(const List *, List_Item);
bool List_Insert(List *, List_Item);
void List_Delete(List *, List_Item);
void List_Traverse(List *, void (*)(List_Item));
void List_Free(List *);

#endif
