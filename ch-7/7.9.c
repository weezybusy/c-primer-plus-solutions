// 7.9.c -- Shows prime numbers encountered before entered number
#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int limit;
    int num;
    int div;
    int count = 0;
    bool is_prime;

    printf("\nEnter a positive integer or 'q' to quit: _\b");
    while (scanf("%d", &limit) == 1) {
        if (limit == 0) {
            printf("An integer must be greater than 0.\n");
            printf("Try again or enter 'q' to quit: _\b");
            continue;
        } else if (limit > 1) {
            printf("\nHere are prime numbers up through %d:\n\n", limit);
        } else {
            printf("\nNo primes.\n");
        }
        
        for (num = 2; num <= limit; num++) {
            for (div = 2, is_prime = true; (div * div) <= num; div++) {
                if (num % div == 0) {
                    is_prime = false;
                }
            }
            if (is_prime) {
                count++;
                printf("%-5d\n\n", num);
            }
            if (count > 5)
        }
        printf("\nEnter a positive integer or 'q' to quit: _\b");
    }
    printf("\nDone!\n\n");
    return 0;
}
