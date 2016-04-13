/*
 * 16.5.c -- Write a function that takes as arguments the name of an array of
 * type int elements, the size of an array, and a value representing the number
 * of picks. The function then should select the indicated number of items at
 * random from the array and prints them. No array element is to be picked more
 * than once. (This simulates picking lottery numbers or jury members.) Also,
 * if your implementation has time() (discussed in Chapter 12) or a similar
 * function available, use its output with srand() to initialize the rand()
 * random-number generator. Write a simple program that tests the function. 
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define BALLS 100
#define PICKS 100

void lottery(int [], int, int);

int main(void)
{
	int box[BALLS];

	for (int ball = 0; ball < BALLS; ball++)
		box[ball] = ball + 1;

	lottery(box, BALLS, PICKS);

	return 0;
}

void lottery(int box[], int balls, int picks)
{
	if (balls < picks) {
		fputs("Too many picks.\n", stderr);
		return;
	}

	int picked[balls], ball;
	int pick = 0;

	for (int ball = 0; ball < balls; ball++)
		picked[ball] = 0;

	srand(time(NULL));
	while (pick < picks) {
		ball = rand() % (balls);
		if (picked[ball])
			continue;
		picked[ball] = 1;
		printf("%d\n", box[ball]);
		pick++;
	}
}
