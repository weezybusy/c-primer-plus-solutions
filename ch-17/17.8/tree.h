#ifndef _TREE_H_
#define _TREE_H_

#include "list.h"

#define MAXITEMS 10

typedef List Tree_Item;

typedef struct tree_node
{
	Tree_Item item;
	struct tree_node *left;
	struct tree_node *right;
} Tree_Node;

typedef struct tree
{
	Tree_Node *root;
	int size;
} Tree;

void Tree_Initialize(Tree *);
bool Tree_IsEmpty(const Tree *);
bool Tree_IsFull(const Tree *);
int Tree_ItemCount(const Tree *);
Tree_Item *Tree_WhereIs(const Tree *, const Tree_Item *);
bool Tree_AddItem(Tree *, const Tree_Item *);
bool Tree_In(const Tree *, const Tree_Item *);
bool Tree_DeleteItem(Tree *, const Tree_Item *);
void Tree_Traverse(const Tree *, void (*)(Tree_Item));
void Tree_DeleteAll(Tree *);

#endif
