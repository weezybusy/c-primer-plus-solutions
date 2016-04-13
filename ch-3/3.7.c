/**
 * 3.7.c
 *
 * There are 2.54 centimeters to the inch. Write a program that asks you to
 * enter your height in inches and then displays your height in centimeters.
 * Or, if you prefer, ask for the height in centimeters and convert that to
 * inches.
 */

#include <stdio.h>

int main(void)
{
    float centimeter = 0.3937;   /* centimeter to inches */
    float height;
    float inches;

    printf("Enter your height in centimeters: ");
    scanf("%f", &height);
    inches = centimeter * height;
    printf("Your height is %.1f inches.\n", inches);

    return 0;
}
