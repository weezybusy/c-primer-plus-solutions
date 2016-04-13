// 5.7 -- finds cube of entered number
#include <stdio.h>

void showCube(double x);

int main(void)
{
    double val;
    
    printf("Enter a floating-point value: ");
    scanf("%lf", &val);
    showCube(val);
    
    return 0;
}

void showCube(double x)
{
    printf("The cube of %.1f is %.1f\n", x, x*x*x);
}

