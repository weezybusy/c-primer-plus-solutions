/**
 * 3.5.c
 *
 * There are approximately 3.156 × 10^7 seconds in a year. Write a program that
 * requests your age in years and then displays the equivalent number of
 * seconds.
 */

#include <stdio.h>

int main(void)
{
    double years;
    double seconds_in_year = 3.156e7;

    printf("Enter age in years: ");
    scanf("%lf", &years);
    printf("Result: %.0lf seconds\n", years * seconds_in_year);

    return 0;
}
