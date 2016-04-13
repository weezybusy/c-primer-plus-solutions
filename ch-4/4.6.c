#include <stdio.h>
#include <float.h>

int main(void)
{
    float a = 1.0 / 3.0;
    double b = 1.0 / 3.0;
    
    printf("float значения:\n%.4f %.12f %.16f", a, a, a);
    printf("double значения:\n%.4f %.12f %.16f\n", b, b, b);
    printf("FLT_DIG: %f\n", FLT_DIG);
    printf("DBL_DIG: %f\n", DBL_DIG);
    return 0;
}
