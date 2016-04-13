/**
 * 17.8.c -- Modify the Pet Club program so that all pets with the same name
 * are stored in a list in the same node. When the user chooses to find a pet,
 * the program should request the pet name and then list all pets (along with
 * their kinds) having that name.
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "tree.h"

char menu(void);
void add_pet(Tree *);
void show_pets(const Tree *);
void find_pet(const Tree *);
void drop_pet(Tree *);
void show_tree_item(Tree_Item);
List_Item new_list_item(void);
void show_list(List *);
void show_list_item(const List_Item);
void uppercase(char *);
char *sgets(char *, int);

int main(void)
{
	Tree pets;
	char choice;

	Tree_Initialize(&pets);

	while ((choice = menu()) != 'q')
	{
		putchar('\n');
		switch (choice)
		{
			case 'a':
				add_pet(&pets);
				break;
			case 'l':
				show_pets(&pets);
				break;
			case 'f':
				find_pet(&pets);
				break;
			case 'n':
				printf("\t%d pets in club\n",
						Tree_ItemCount(&pets));
				break;
			case 'd':
				drop_pet(&pets);
				break;
			default:
				puts("Switching error!");
		}
	}

	Tree_DeleteAll(&pets);

	return 0;
}

char menu(void)
{
	puts("\nNerfville Pet Club Membership Program");
	puts("-------------------------------------");
	puts("Enter the letter corresponding to your choice:");
	puts("a) add a pet          l) show list of pets");
	puts("n) number of pets     f) find pets");
	puts("d) delete a pet       q) quit\n");
	printf("Your choice: ");

	int ch;
	while ((ch = getchar()) != EOF)
	{
		if (ch != '\n')
			while (getchar() != '\n')
				continue;
		ch = tolower(ch);
		if (strchr("alrfndq", ch) == NULL)
			printf("Please enter an a, l, f, n, d, or q: ");
		else
			break;
	}

	if (ch == EOF)
		ch = 'q';

	return ch;
}

void add_pet(Tree *pt)
{

	if (Tree_IsFull(pt))
		puts("No room in the club!");
	else
	{
		List_Item pet = new_list_item();
		List tmp = List_New();
		List_Insert(&tmp, pet);
		Tree_AddItem(pt, &tmp);
	}
}

void show_pets(const Tree *pt)
{
	if (Tree_IsEmpty(pt))
		puts("\tNo entries!");
	else
		Tree_Traverse(pt, show_tree_item);
}

void show_tree_item(Tree_Item item)
{
	show_list(&item); 
}

void find_pet(const Tree *pt)
{
	if (Tree_IsEmpty(pt))
	{
		puts("No entries!");
		return;
	}

	List_Item pet;

	printf("Please enter name of pet: ");
	sgets(pet.name, SIZE);
	uppercase(pet.name);

	List tmp = List_New();
	List_Insert(&tmp, pet);
	Tree_Item *find = Tree_WhereIs(pt, &tmp);

	if (find)
	{
		putchar('\n');
		show_tree_item(*find);
	}
	else
	{
		printf("\n\t%s is not a member.\n", pet.name);
	}

	List_Free(&tmp);
}

void drop_pet(Tree *pt)
{
	if (Tree_IsEmpty(pt))
	{
		puts("No entries!");
		return;
	}

	List_Item pet = new_list_item();
	List tmp = List_New();
	List_Insert(&tmp, pet);

	Tree_Item *find = Tree_WhereIs(pt, &tmp);
	if (find)
	{
		if (List_Count(find) == 1)
		{
			Tree_DeleteItem(pt, find);
		}
		else
		{
			List_Node *del = List_WhereIs(find, tmp->item);
			List_Delete(find, del->item);
			pt->size--;
		}
	}
	else
	{
		printf("No such pet!\n");
	}

	List_Free(&tmp);
}

List_Item new_list_item(void)
{
	List_Item pet;

	printf("Please enter name of pet: ");
	sgets(pet.name, SIZE);
	uppercase(pet.name);

	printf("Please enter pet kind: ");
	sgets(pet.kind, SIZE);
	uppercase(pet.kind);

	return pet;
}

void show_list_item(const List_Item li)
{
	printf("\t%s the %s\n", li.name, li.kind);
}

void show_list(List *pl)
{
	if (!List_IsEmpty(pl))
		List_Traverse(pl, show_list_item);
}

void uppercase(char *str)
{
	while (*str)
	{
		*str = toupper(*str);
		str++;
	}
}

char *sgets(char *str, int n)
{
	char *value = fgets(str, n, stdin);
	if (value)
	{
		char *new_line = strchr(str, '\n');
		if (new_line)
			*new_line = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return value;
}
