/* 9.10.c -- iterative version of fibonacci function */
#include <stdio.h>

long fibonacci(int x);

int main(void)
{
    int number;
    printf("Enter an integer (q to quit): _\b");
    while (scanf("%d", &number) == 1) {
        printf("%ld\n", fibonacci(number));
        printf("Enter next value (q to quit): _\b");

    }
    printf("Done!\n");
    return 0;
}

long fibonacci(int x)
{
    long first = 0;
    long second = 1;
    long sum;

    if (x == 0) {
        sum = 0;
    }
    else if (x == 1) {
        sum = 1;
    } else {
        for (int i = 1; i < x; i++) {
            sum = first + second;
            first = second;
            second = sum;
        }
    }
    return sum;
}
