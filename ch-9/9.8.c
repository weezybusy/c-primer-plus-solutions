/* 9.8.c -- rising a number to the power (including negative) */
#include <stdio.h>

double power(double x, int y);

int main(void)
{
    double x, xpow;
    int n;
    printf("Enter a number and the integer power\n"
           "to which the number will be raised (q to quit): _\b");
    while (scanf("%lf %d", &x, &n) == 2) {
        xpow = power(x,n);
        printf("%.3g in power of %d is %.5g\n", x, n, xpow);
        printf("Enter a number and the integer power\n"
               "to which the number will be raised (q to quit): _\b");
    }
    return 0;
}

double power(double x, int y)
{
    double pow = 1;
    if (y == 0) {
        if (x == 0) {
            printf("0 to the 0 undefined; using 1 as the value\n");
        }
    } else if (x == 0) {
        pow = 0.0;
    } else if (y > 0) {
        for (int i = 1; i <= y; i++ ) {
            pow *= x;
        }
    } else {
        pow = 1.0 / power(x, -y);
    }
    return pow;
}
