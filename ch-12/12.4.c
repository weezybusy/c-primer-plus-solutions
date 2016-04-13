/*
 * 12.4.c --
 * Write and test in a loop a function that returns the number
 * of times it has been called.
 */

#include <stdio.h>

int func(void);

int main(void)
{
	int calls_num;
	for (int i = 0; i < 10; i++) {
		calls_num = func();
	}
	printf("The function was called %d times.\n", calls_num);
	return 0;
}

int func(void)
{
	static int call_count = 0;
	return ++call_count;
}
