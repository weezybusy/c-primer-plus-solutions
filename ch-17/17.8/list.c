#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list.h"

static void copy_to_node(List_Node *, List_Item);
static List_Node *make_node(List_Item);
static int compare_items(List_Item, List_Item);

List List_New(void)
{
	List new_list;
	List_Initialize(&new_list);

	return new_list;
}

void List_Initialize(List *pl)
{
	*pl = NULL;
}

bool List_IsEmpty(const List *pl)
{
	return *pl == NULL;
}

bool List_IsFull(void)
{
	List_Node *tmp;
	bool full;

	tmp = malloc(sizeof(List_Node));
	if (tmp == NULL)
		full = true;
	else
		full = false;
	free(tmp);

	return full;
}

unsigned int List_Count(const List *pl)
{
	unsigned int count = 0;

	while (*pl != NULL)
	{
		count++;
		pl = &(*pl)->next;
	}

	return count;
}

List_Node *List_WhereIs(const List *pl, List_Item item)
{
	while (*pl && compare_items((*pl)->item, item) != 0)
		pl = &(*pl)->next;

	return *pl;
}

bool List_Insert(List *pl, List_Item item)
{
	List_Node *new_node = make_node(item);

	if (new_node == NULL)
		return false; 

	copy_to_node(new_node, item);

	if (*pl == NULL)
	{
		*pl = new_node;
	}
	else
	{
		while (*pl && compare_items((*pl)->item, item) != 0)
			pl = &(*pl)->next;

		new_node->next = *pl;
		*pl = new_node;
	}

	return true;
}

void List_Delete(List *pl, List_Item item)
{
	for (List_Node *curr = *pl, *prev = NULL;
			curr != NULL;
			prev = curr, curr = curr->next)
	{
		if (compare_items(curr->item, item) == 0)
		{
			if (prev == NULL)
			{
				*pl = curr->next;
			}
			else
			{
				prev->next = curr->next;
			}
			free(curr);

			return;
		}
	}
}

void List_Traverse(List *pl, void (*func)(List_Item item))
{
	while (*pl)
	{
		(*func)((*pl)->item);
		pl = &(*pl)->next;
	}
}

void List_Free(List *pl)
{
	while (*pl != NULL)
	{
		List_Node *tmp = (*pl)->next;
		free(*pl);
		*pl = tmp;
	}
}


static List_Node *make_node(List_Item item)
{
	List_Node *new_node = malloc(sizeof(List_Node));

	if (new_node == NULL)
	{
		fprintf(stderr, "Failed allocate memory.\n");
		exit(EXIT_FAILURE);
	}
	
	copy_to_node(new_node, item);
	new_node->next = NULL;

	return new_node;
}

static int compare_items(List_Item li1, List_Item li2)
{
	return strcmp(li1.kind, li2.kind);
}

static void copy_to_node(List_Node *np, List_Item item)
{
	np->item = item;
}
