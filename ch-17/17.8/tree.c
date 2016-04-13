#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

typedef struct pair {
	Tree_Node *parent;
	Tree_Node *child;
} Pair;

static Tree_Node *make_node(const Tree_Item *);
static bool to_left(const Tree_Item *, const Tree_Item *);
static bool to_right(const Tree_Item *, const Tree_Item *);
static void add_node (Tree_Node *, Tree_Node *);
static void in_order(const Tree_Node *, void (*)(Tree_Item));
static Pair seek_item(const Tree *, const Tree_Item *);
static void delete_node(Tree_Node **);
static void delete_all_nodes(Tree_Node *);
static bool deal_duplicate(Tree_Item *, const Tree_Item *);

void Tree_Initialize(Tree *pt)
{
	pt->root = NULL;
	pt->size = 0;
}

bool Tree_IsEmpty(const Tree *pt)
{
	return pt->size == 0;
}

bool Tree_IsFull(const Tree *pt)
{
	return pt->size == MAXITEMS;
}

int Tree_ItemCount(const Tree *pt)
{
	return pt->size;
}

bool Tree_AddItem(Tree *pt, const Tree_Item *pi)
{
	if (Tree_IsFull(pt))
	{
		fprintf(stderr,"Tree is full\n");
		return false;
	}

	Pair duplicate = seek_item(pt, pi);
	if (duplicate.child != NULL)
	{
		bool tmp = deal_duplicate(&duplicate.child->item, pi);
		pt->size += tmp;
		return tmp;
	}

	Tree_Node *new_node = make_node(pi);

	if (new_node == NULL)
	{
		fprintf(stderr, "Couldn't create node\n");
		return false;
	}
	pt->size++;

	if (pt->root == NULL)
		pt->root = new_node;
	else
		add_node(pt->root, new_node);

	return true;
}

bool Tree_In(const Tree *pt, const Tree_Item *pi)
{
	return (seek_item(pt, pi).child == NULL) ? false : true;
}

Tree_Item *Tree_WhereIs(const Tree *pt, const Tree_Item *pi)
{
	Tree_Node *pn = seek_item(pt, pi).child;

	if (pn != NULL)
		return &(pn->item);

	return NULL;
}

bool Tree_DeleteItem(Tree *pt, const Tree_Item *pi)
 {
	Pair look;

	look = seek_item(pt, pi);
	if (look.child == NULL)
		return false;

	if (look.parent == NULL)
		delete_node(&pt->root);
	else if (look.parent->left == look.child)
		delete_node(&look.parent->left);
	else
		delete_node(&look.parent->right);
	pt->size--;

	return true;
}

void Tree_Traverse(const Tree *pt, void (*pfun)(Tree_Item item))
{
	if (pt != NULL)
		in_order(pt->root, pfun);
}

void Tree_DeleteAll(Tree *pt)
{
	if (pt != NULL)
		delete_all_nodes(pt->root);
	pt->root = NULL;
	pt->size = 0;
}


static void in_order(const Tree_Node *root, void (*pfun)(Tree_Item item))
{
	if (root != NULL)
	{
		in_order(root->left, pfun);
		(*pfun)(root->item);
		in_order(root->right, pfun);
	}
}

static void delete_all_nodes(Tree_Node *root)
{
	Tree_Node *pright;

	if (root != NULL)
	{
		pright = root->right;
		delete_all_nodes(root->left);
		List_Free(&root->item);
		free(root);
		delete_all_nodes(pright);
	}
}

static void add_node(Tree_Node *root, Tree_Node *new_node)
{
	if (to_left(&new_node->item, &root->item))
	{
		if (root->left == NULL)
			root->left = new_node;
		else
			add_node(root->left, new_node);
	}
	else if (to_right(&new_node->item, &root->item))
	{
		if (root->right == NULL)
			root->right = new_node;
		else
			add_node(root->right, new_node);
	}
	else
	{
		fprintf(stderr,"location error in add_node()\n");
		exit(EXIT_FAILURE);
	}
}

static bool deal_duplicate(Tree_Item *list, const Tree_Item *pi)
{
	List_Insert(list, (*pi)->item);
	free (*pi);

	return true;
}

static bool to_left(const Tree_Item *i1, const Tree_Item *i2)
{
	return strcmp((*i1)->item.name, (*i2)->item.name) < 0;
}

static bool to_right(const Tree_Item *i1, const Tree_Item *i2)
{
	return strcmp((*i1)->item.name, (*i2)->item.name) > 0;
}

static Tree_Node *make_node(const Tree_Item *pi)
{
	Tree_Node *new_node = malloc(sizeof(Tree_Node));

	if (new_node != NULL)
	{
		new_node->item = *pi;
		new_node->left = NULL;
		new_node->right = NULL;
	}

	return new_node;
}

static Pair seek_item(const Tree *pt, const Tree_Item *pi)
{
	Pair look;

	look.parent = NULL;
	look.child = pt->root;

	if (look.child == NULL)
		return look;

	while (look.child != NULL)
	{
		if (to_left(pi, &(look.child->item)))
		{
			look.parent = look.child;
			look.child = look.child->left;
		}
		else if (to_right(pi, &(look.child->item)))
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

static void delete_node(Tree_Node **p)
{
	Tree_Node *tmp;

	if ((*p)->left == NULL)
	{
		tmp = *p;
		*p = (*p)->right;
		List_Free(&tmp->item);
		free(tmp);
	}
	else if ((*p)->right == NULL)
	{
		tmp = *p;
		*p = (*p)->left;
		List_Free(&tmp->item);
		free(tmp);
	}
	else
	{
		for (tmp = (*p)->left; tmp->right != NULL; tmp = tmp->right)
			continue;

		tmp->right = (*p)->right;
		tmp = *p;
		*p =(*p)->left;
		List_Free(&tmp->item);
		free(tmp); 
	}
}
