// 5.8 -- Fahrenheit to Celsius and Kelvin
#include <stdio.h>
void temperatures(double x);

int main(void)
{
    double val;
    
    printf("Enter temperature in Fahrenheit: ");
    while(scanf("%lf", &val) == 1)
    {
        temperatures(val);
        printf("Try again or 'q' to quit: ");
    }
    printf("Good bye!\n");
    return 0;
}

void temperatures(double x)
{
    const double CELSIUS = (x - 32.0) / 1.8;
    const double KELVIN = CELSIUS + 273.16;
    
    printf("%.2f F is %.2f C and %.2f K.\n", x, CELSIUS, KELVIN);
}
