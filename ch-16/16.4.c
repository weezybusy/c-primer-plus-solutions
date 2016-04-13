/*
 * 16.4.c -- The ANSI library features a clock() function with this description: 
 *
 * 	#include <time.h>
 * 	clock_t clock (void);
 *
 * Here, clock_t is a type defined in time.h. The function returns the
 * processor time, which is given in some implementation-dependent units.
 * (If the processor time is unavailable or cannot be represented, the
 * function returns a value of -1). However, CLOCKS_PER_SEC, also defined in  
 * time.h, is the number of processor time units per second. Therefore,
 * dividing the difference between two return values of clock() by
 * CLOCKS_PER_SEC gives you the number of seconds elapsed between the two calls. 
 * Typecasting the values to double before division enables you to get
 * fractions of a second. Write a function that takes a double argument
 * representing a desired time delay and a loop until that amount of time has
 * passed. Write a simple program that tests the function.
 */

#include <stdio.h>
#include <time.h>

void execution_time(double);

int main(void)
{
	double period;

	printf("Enter a period in seconds: _\b");
	while (scanf("%lf", &period) != 1) {
		printf("Enter a period in seconds: _\b");
		while (getchar() != '\n')
			continue;
	}
	execution_time(period);

	return 0;
}

void execution_time(double p)
{
	clock_t start;
	double duration;

	start = clock();
	while (1) {
		duration = (double) (clock() - start) / CLOCKS_PER_SEC;
		printf("TIME: %.5f seconds\n", duration);
		if (duration >= p)
			break;
	}
	printf("TOTAL TIME: %.5f seconds\n", duration);
}
