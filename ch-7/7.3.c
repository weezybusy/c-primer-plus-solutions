// 7.3.c -- Counts evens and odds and their averages
#include <stdio.h>

int main(void) {
    int num;
    int even_count = 0;
    int even_sum = 0;
    double even_avg = 0.0;
    int odd_count = 0;
    int odd_sum = 0;
    double odd_avg = 0.0;

    printf("Enter a number:\n");
    while (scanf("%i", &num) == 1 && num != 0) {
        if (num % 2 == 0) {
            even_count++;
            even_sum += num;
        }
        else {
            odd_count++;
            odd_sum += num;
        }
    }
    even_avg = (double)even_sum / (double)even_count;
    odd_avg = (double)odd_sum / (double)odd_count;

    printf("Amount of evens = %i\n", even_count);
    if (even_avg > 0) {
        printf("Average of evens = %g\n", even_avg);
    }

    printf("Amount of odds = %i\n", odd_count);
    if (odd_avg > 0) {
        printf("Average of odds = %g\n", odd_avg);
    }
    return 0;
}
