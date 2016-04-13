#include <stdio.h>

int main(void)
{
    double first, second;
    double result;

    printf("Please, enter two floating-point numbers: ");
    while(scanf("%lf%lf", &first, &second) == 2) {
        result = (first - second)/(first * second);
        printf("(%.3g - %.3g)/(%.3g * %.3g) = %.5g\n", first, second, first, second, result);
        printf("Enter next numbers or 'q' to exit: ");
    }

    return 0;
}
