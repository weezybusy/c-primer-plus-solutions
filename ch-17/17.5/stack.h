/* stack.h -- interface for a stack type */

#ifndef _STACK_H_
#define _STACK_H_
#include <stdbool.h>

/* program specific declarations */
#define MAX_STRING_SIZE 40
#define MAX_STACK_SIZE 100

/* INSERT ITEM TYPE HERE. EXAMPLE: typedef int item; */
typedef char Item;

/* general type definitions */
typedef struct node
{
	Item item;
	struct node *next;
} Node;

typedef struct stack
{
	Node *top;
	int size;
} Stack;

/* function prototypes */

/* operation:		initialize stack				*/
/* preconditions:	Stack * argument points to a stack		*/
/* postconditions:	the stack is initialized to being empty		*/
void InitializeStack(Stack *);

/* operation:		determine if stack is empty			*/
/* preconditions:	Stack * argument points to previously		*/
/* 			initialized stack				*/
/* postconditions:	If stack is empty, function returns True;	*/
/* 			otherwise function returns false		*/
bool StackIsEmpty(const Stack *);

/* operation:		determine if stack is full			*/
/* preconditions:	Stack * argument points to previously		*/
/* 			initialized stack				*/
/* postconditions:	If stack is full, function returns True;	*/
/* 			otherwise function returns false		*/
bool StackIsFull(const Stack *);

/* operation:		determine number of items in stack		*/
/* preconditions:	Stack * argument points to previously		*/
/* 			initialized stack				*/
/* postconditions:	function returns number of items in stack	*/
unsigned int CountStackItems(const Stack *);

/* operation:		posh item onto top of stack			*/
/* preconditions:	Stack * argument points to previously		*/
/* 			initialized stack				*/
/* 			Item * argument is an item to be pushed		*/
/* postconditions:	if stack is not full, item is placed at top of	*/
/* 			the stack and function returns True; otherwise	*/
/*			function returns False				*/
bool Push(Stack *, Item *);

/* operation:		remove item from top of stack			*/
/* preconditions:	Stack * argument points to previously		*/
/* 			initialized stack				*/
/* postconditions:	if stack is not empty, item from stack is	*/
/*   			copied to Item * argument and deleted from	*/
/*			stack, function returns True; if the operation	*/
/*			empties the stack, the stack is reset to empty;	*/
/*			if the stack is empty to begin with, stack is	*/
/*			unchanged and function returns false		*/
bool Pop(Item *, Stack *);

/* operation:		empty stack					*/
/* preconditions:	Stack * argument is previously initialized	*/
/* postconditions:	memory occupied by stack is free		*/
void ResetStack(Stack *);

#endif
