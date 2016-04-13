/* 9.5.c -- replaces both numbers values with the larger one */
#include <stdio.h>

void larger_of(double *px, double *py);

int main(void)
{
    double x, y;

    printf("Enter two numbers (q to quit): _\b");
    while (scanf("%lf %lf", &x, &y) == 2) {
        larger_of(&x, &y);
        printf("The modifies values are %.2f %.2f\n", x, y);
        printf("Next two values (q to quit): _\b");
    }
    return 0;
}

void larger_of(double *px, double *py)
{
    double temp = *px > *py ? *px : *py;
    *px = *py = temp;
}
