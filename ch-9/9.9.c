/* 9.9.c -- converts decimals to 2-16 base */
#include <stdio.h>

void to_base_n(int number, int base);

int main(void)
{
    int number;
    int base;

    printf("Enter an integer (q to quit): _\b");
    while (scanf("%d", &number) == 1) {
        printf("Enter number base (2 - 16): _\b");
        scanf("%d", &base);
        printf("Base %d equivalent:\n", base);
        to_base_n(number, base);
        putchar('\n');
        printf("Enter an integer (q to quit): _\b");
    }
    return 0;
}

void to_base_n(int number, int base)
{
    int residue;

    residue = number % base;
    printf("%d\n", residue);
    if (number >= base) {
        printf("%d\n", number);
        to_base_n(number / base, base);
    }
    if (residue <= 9) {
        putchar('0' + residue);
    } else {
        putchar('@' + (residue - 9));
    }
}
