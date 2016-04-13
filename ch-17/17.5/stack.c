/* stack.c -- implementation of a stack interface */

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

/* local function prototypes */
static Node *create_node(Item *);
static void copy_to_node(Item *, Stack *);

/* interface function definitions */
void InitializeStack(Stack *ps)
{
	ps->top = NULL;
	ps->size = 0;
}

bool StackIsEmpty(const Stack *ps)
{
	return ps->size == 0;
}

bool StackIsFull(const Stack *ps)
{
	return ps->size == MAX_STACK_SIZE;
}

unsigned int CountStackItems(const Stack *ps)
{
	return ps->size;
}

bool Push(Stack *ps, Item *item)
{
	if (StackIsFull(ps))
		return false;

	Node *new_node = create_node(item);
	if (new_node == NULL)
		return false;

	new_node->next = ps->top;
	ps->top = new_node;
	ps->size++;

	return true;
}

bool Pop(Item *pi, Stack *ps)
{
	if (ps == NULL || ps->top == NULL)
		return false;

	copy_to_node(pi, ps);
	Node *obsolete = ps->top;
	ps->top = ps->top->next;
	ps->size--;
	free(obsolete);

	return true;
}

void ResetStack(Stack *ps)
{
	while (ps->top != NULL)
	{
		Node *next = ps->top->next;
		free(ps->top);
		ps->top = next;
	}
	ps->size = 0;
}

/* local function definitions */
static Node *create_node(Item *pi)
{
	Node *new_node = malloc(sizeof(Node));
	new_node->item = *pi;
	new_node->next = NULL;

	return new_node;
}

static void copy_to_node(Item *pi, Stack *ps)
{
	*pi = ps->top->item;
}
