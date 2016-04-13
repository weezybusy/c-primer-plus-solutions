/* 9.4.c -- calculates harmonic average of two floating-point numbers */
#include <stdio.h>

double harmonic(double a, double b);

int main(void)
{
    double x, y;
    double result;
    printf("Enter two floating-point numbers (q to quit): _\b");
    while (scanf("%lf %lf", &x, &y) == 2) {
        result = harmonic(x,y);
        printf("\nThe harmonic average value is %g\n", result);
        printf("\nEnter two floating-point numbers (q to quit): _\b");
    }
    return 0;
}

double harmonic(double a, double b)
{
    double avg;
    a = 1 / a;
    b = 1 / b;
    avg = (a + b) / 2;

    return 1 / avg;
}
