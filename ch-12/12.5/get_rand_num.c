// function generates random number in the range 1-10
#include <stdlib.h>
#include <time.h>

void get_rand_num(int arr[], int lim)
{
	srand(time(NULL));
	for (int i = 0; i < lim; i++) {
		arr[i] = rand() % 10 + 1;
	}
}
