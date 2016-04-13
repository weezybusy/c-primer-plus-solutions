/*
 * 12.6.c --
 * Write a program that generates 1000 random numbers in the
 * range 1–10. Don’t save or print the numbers, but do print
 * how many times each number was produced. Have the program
 * do this for 10 different seed values. Do the numbers appear
 * in equal amounts? You can use the functions from this chapter
 * or the ANSI C rand() and srand() functions, which follow the
 * same format that our functions do. This is one way to examine
 * the randomness of a particular random-number generator.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 1000
#define LIM 10

int main(void)
{
	int num_arr[SIZE];
	int ten_rand_num[LIM];

	srand(time(NULL));
	for (int i = 0; i < SIZE; i++) {
		num_arr[i] = rand() % 10 + 1;
		switch (num_arr[i]) {
			case 1:
				ten_rand_num[0] += 1;
				break;
			case 2:
				ten_rand_num[1] += 1;
				break;
			case 3:
				ten_rand_num[2] += 1;
				break;
			case 4:
				ten_rand_num[3] += 1;
				break;
			case 5:
				ten_rand_num[4] += 1;
				break;
			case 6:
				ten_rand_num[5] += 1;
				break;
			case 7:
				ten_rand_num[6] += 1;
				break;
			case 8:
				ten_rand_num[7] += 1;
				break;
			case 9:
				ten_rand_num[8] += 1;
				break;
			case 10:
				ten_rand_num[9] += 1;
				break;
			default:
				puts("Error!");
		}
	}

	for (int i = 0; i < LIM; i++) {
		printf("%d\n", ten_rand_num[i]);
	}

	return 0;
}
