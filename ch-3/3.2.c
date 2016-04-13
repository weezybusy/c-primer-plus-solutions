/**
 * 3.2.c
 *
 * Write a program that asks you to enter an ASCII code value, such as 66, and
 * then prints the character having that ASCII code.
 */

#include <stdio.h>

int main(void)
{
    int ascii;

    scanf("%d", &ascii);
    printf("%d is ASCII code for %c\n", ascii, ascii);

    return 0;
}
