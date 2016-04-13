#ifndef _TREE_H_
#define _TREE_H_
#include <stdbool.h>

#define SIZE 20
#define MAX_ITEMS 40
#define PUNCT ".,!?:;\"({[]})"

typedef struct item
{
	char word[SIZE];
	unsigned int count;
} Item;

typedef struct node
{
	Item item;
	struct node *left;
	struct node *right;
} Node;

typedef struct tree
{
	Node *root;
	unsigned int size;
} Tree;

void InitializeTree(Tree *);
bool TreeIsEmpty(const Tree *);
bool TreeIsFull(const Tree *); 
unsigned int CountTreeItems(const Tree *);
bool AddItem(Tree *, const Item *);
bool InTree(const Item *, const Tree *);
const Node *WhereInTree(const Item *, const Tree *);
bool DeleteItem(const Item *, Tree *);
void Traverse(const Tree *, void (*)(Item));
void DeleteAll(Tree *);

#endif
