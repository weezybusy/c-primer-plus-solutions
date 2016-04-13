#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

/* local data type */
typedef struct pair
{
	Node *child;
	Node *parent;
} Pair;

/* local function declarations */
static bool ToLeft(const Item *, const Item *);
static bool ToRight(const Item *, const Item *);
static void AddNode(Node *, Node *);
static Node *MakeNode(const Item *);
static Pair SeekItem(const Item *, const Tree *);
static void InOrder(const Node *, void (*pfunc)(Item));
static void DeleteNode(Node **);
static void DeleteAllNodes(Node *);

/* interface function definitions */
void InitializeTree(Tree *pt)
{
	pt->root = NULL;
	pt->size = 0;
}

bool TreeIsEmpty(const Tree *pt)
{
	return pt->size == 0;
}

bool TreeIsFull(const Tree *pt)
{
	return pt->size == MAX_ITEMS;
}

unsigned int CountTreeItems(const Tree *pt)
{
	return pt->size;
}

bool AddItem(Tree *pt, const Item *pi)
{
	if (pt->size == MAX_ITEMS)
	{
		fprintf(stderr, "Tree is full.\n");
		return false;
	}

	Pair seek;
	if ((seek = SeekItem(pi, pt)).child != NULL)
	{
		seek.child->item.count++;
		return true;
	}

	Node *new_node = MakeNode(pi);
	if (new_node == NULL)
	{
		fprintf(stderr, "Faild allocate memory.\n");
		return false;
	}
	pt->size++;

	if (pt->root == NULL)
		pt->root = new_node;
	else
		AddNode(new_node, pt->root);

	return true;
}

bool InTree(const Item *pi, const Tree *pt)
{
	return SeekItem(pi, pt).child ? true : false;
}

const Node *WhereInTree(const Item *pi, const Tree *pt)
{
	return SeekItem(pi, pt).child;
}

bool DeleteItem(const Item *pi, Tree *pt)
{
	Pair look = SeekItem(pi, pt);

	if (look.child == NULL)
		return false;

	if (look.child->item.count > 0)
	{
		look.child->item.count--;
	}
	else
	{
		if (look.parent == NULL)
			DeleteNode(&pt->root);
		else if (look.parent->left == look.child)
			DeleteNode(&look.parent->left);
		else
			DeleteNode(&look.parent->right);
		pt->size--;
	}

	return true;
}

void Traverse(const Tree *pt, void (*pfunc)(Item))
{
	if (pt != NULL)
		InOrder(pt->root, pfunc);
}

void DeleteAll(Tree *pt)
{
	if (pt != NULL)
		DeleteAllNodes(pt->root);
	pt->root = NULL;
	pt->size = 0;
}

/* local function definitions */
static bool ToLeft(const Item *a, const Item *b)
{
	if (strcmp(a->word, b->word) < 0)
		return true;
	else
		return false;
}

static bool ToRight(const Item *a, const Item *b)
{
	if (strcmp(a->word, b->word) > 0)
		return true;
	else
		return false;
}

static void AddNode(Node *new_node, Node *root)
{
	if (ToLeft(&new_node->item, &root->item))
	{
		if (root->left == NULL)
			root->left = new_node;
		else
			AddNode(new_node, root->left);
	}
	else if (ToRight(&new_node->item, &root->item))
	{
		if (root->right == NULL)
			root->right = new_node;
		else
			AddNode(new_node, root->right);
	}
	else
	{
		fprintf(stderr, "Location error in AddNode().\n");
		exit(EXIT_FAILURE);
	}
}

static Node *MakeNode(const Item *pi)
{
	Node *new_node = malloc(sizeof(Node));
	if (new_node != NULL)
	{
		new_node->item = *pi;
		new_node->item.count = 1;
		new_node->left = NULL;
		new_node->right = NULL;
	}

	return new_node;
}

static Pair SeekItem(const Item *pi, const Tree *pt)
{
	Pair look;
	look.parent = NULL;
	look.child = pt->root;

	if (look.child == NULL)
		return look;

	while (look.child != NULL)
	{
		if (ToLeft(pi, &(look.child->item)))
		{
			look.parent = look.child;
			look.child = look.child->left;
		}
		else if (ToRight(pi, &(look.child->item)))
		{
			look.parent = look.child;
			look.child = look.child->right;
		}
		else
		{
			break;
		}
	}

	return look;
}

static void InOrder(const Node *root, void (*pfunc)(Item))
{
	if (root != NULL)
	{
		InOrder(root->left, pfunc);
		(*pfunc)(root->item);
		InOrder(root->right, pfunc);
	}
}

static void DeleteNode(Node **ptr)
{
	Node *tmp;
	if ((*ptr)->left == NULL)
	{
		tmp = *ptr;
		*ptr = (*ptr)->right;
		free(tmp);
	}
	else if ((*ptr)->right == NULL)
	{
		tmp = *ptr;
		*ptr = (*ptr)->left;
		free(tmp);
	}
	else
	{
		for (tmp = (*ptr)->left; tmp->right != NULL; tmp = tmp->right)
			continue;
		tmp->right = (*ptr)->right;
		tmp = *ptr;
		*ptr = (*ptr)->left;
		free(tmp);
	}
}

static void DeleteAllNodes(Node *root)
{
	Node *pright;
	if (root != NULL)
	{
		pright = root->right;
		DeleteAllNodes(root->left);
		free(root);
		DeleteAllNodes(pright);
	}
}

