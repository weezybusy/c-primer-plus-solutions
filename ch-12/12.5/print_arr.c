#include <stdio.h>

void print(const int arr[], int lim)
{
	int i;

	for (i = 0; i < lim; i++) {
		printf("%3d", arr[i]);
		if (i % 10 == 9) {
			putchar('\n');
		}
	}
	if (i % 10 != 0)
		putchar('\n');
}
