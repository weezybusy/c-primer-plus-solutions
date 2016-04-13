/*
 * 12.7.c --
 * Write a program that behaves like the modification of Listing 12.13,
 * which we discussed after showing the output of Listing 12.13. That is,
 * have the program produce output like the following:
 *
 * 	Enter the number of sets; enter q to stop : 18
 * 	How many sides and how many dice? 6 3
 * 	Here are 18 sets of 3 6-sided throws.
 * 	12 10 6 9 8 14 8 15 9 14 12 17 11 7 10 13 8 14
 * 	How many sets? Enter q to stop: q
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static int rollem(int sides);

int main(void)
{
	int roll,
		sides,
		dice,
		set,
		sets,
		count;

	srand(time(NULL));
	printf("Enter the number of sets or'q' to quit: ");
	while (scanf("%d", &sets) == 1 && sets > 0) {
		printf("How many sides and how many dice? ");
		if (scanf("%d %d", &sides, &dice) == 2) {
			printf("Here are %d sets of %d %d-sided dice throws.\n",
					sets, dice, sides);
			for (set = 0; set < sets; set++) {
				for (roll = 0, count = 0; count < dice; count++) {
					roll += rollem(sides);
				}
				printf("%4d", roll);
				if (set % 15 == 14)
					putchar('\n');
			}
			if (set % 15 != 0) {
				putchar('\n');
			}
		} else {
			printf("Invalid input. Try again.\n");
			printf("Enter the number of sets or 'q' to quit: ");
			while (getchar() != '\n')
				continue;
			continue;
		}
		printf("How many sets? Enter q to quit: ");
	}
	printf("Good luck!\n");
	return 0;
}

static int rollem(int sides)
{
	int roll;

	roll = rand() % sides + 1;
	return roll;
}
