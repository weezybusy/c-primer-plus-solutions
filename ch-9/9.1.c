/* 9.1.c -- function min() return the smalles number */
#include <stdio.h>

double min(double a, double b);

int main(void)
{
    double x, y;

    printf("Enter two numbers such as 2, 3.5 or 12.00 or q to quit:\n_\b");
    while (scanf("%lf %lf", &x, &y) == 2) {
        printf("The smaller number is %g.\n", x, y, min(x,y));
        printf("Next two values or q to quit: _\b");
    }
    return 0;
}

double min(double x, double y)
{
    return (x < y) ? x : y;
}
