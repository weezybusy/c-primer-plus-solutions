/*
 * 12.3a.c --
 * Redesign the program described in Programming Exercise 2 so that
 * it uses only automatic variables. Have the program offer the same
 * user interface—that is, it should prompt the user to enter a mode,
 * and so on. You’ll have to come up with a different set of function
 * calls, however.
 */

#include <stdio.h>
#include "12.3.h"

int main(void)
{
	int mode;
	int prev_mode = 0;
	double distance, fuel_consumed;

	printf("Enter 0 for metric mode, 1 for US mode: ");
	scanf("%d", &mode);
	while (mode >= 0) {
		set_mode(&mode, prev_mode);
		prev_mode = mode;
		get_info(mode, &distance, &fuel_consumed);
		show_info(mode, &distance, &fuel_consumed);
		printf("Enter 0 for metric mode, 1 for US mode");
		printf(" (-1 to quit): ");
		scanf("%d", &mode);
	}
	printf("Done.\n");
	return 0;
}
