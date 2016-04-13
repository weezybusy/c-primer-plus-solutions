/*
 * 12.1.c --
 * Rewrite the program so that it does not use global variables.
 *
 * #include <stdio.h>
 *
 * int units = 0;
 * void critic(void);
 *
 * int main(void)
 * {
 * 	extern int units;
 * 	printf("How many pounds to a firkin of butter?\n");
 * 	scanf("%d", &units);
 * 	while ( units != 56)
 * 		critic();
 * 	printf("You must have looked it up!\n");
 * 	return 0;
 * }
 *
 * void critic(void)
 * {
 * 	printf("No luck, my friend. Try again.\n");
 * 	scanf("%d", &units);
 * }
 *
 */

#include <stdio.h>

void critic(int *var);

int main(void)
{
	int units = 0;
	printf("How many pounds to a firkin of butter?\n");
	scanf("%d", &units);
	while (units != 56)
		critic(&units);
	printf("You must have looked it up!\n");
	return 0;
}

void critic(int *var)
{
	printf("No luck, my friend. Try again.\n");
	scanf("%d", var);
}
