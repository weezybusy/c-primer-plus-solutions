// 7.10.c -- choose a tax rate and count annual taxes
#include <stdio.h>
#include <stdbool.h>
#define RATE 0.15
#define EXCESS 0.28
#define TIER1 17850.0
#define TIER2 23900.0
#define TIER3 29750.0
#define TIER4 14875.0

int main(void) {

    int category;
    double tier;
    double income;
    double taxes;
    bool invalid_input;

    printf("\nPlease, choose a category:\n");
    printf("***************************************************************\n");
    printf("1) Single\t\t15%% of first $17 850 plus 28%% of excess\n");
    printf("2) Head of Household\t15%% of first $23 900 plus 28%% of excess\n");
    printf("3) Married, Joint\t15%% of first $29 750 plus 28%% of excess\n");
    printf("4) Married, Separate\t15%% of first $14 875 plus 28%% of excess\n");
    printf("5) EXIT\n");
    printf("***************************************************************\n");
    printf("Your choice: _\b");
    while (scanf("%d", &category) == 1 && category != 5) {
        invalid_input = false;
        switch (category) {
            case 1: {
                tier = TIER1;
                break;
            }
            case 2: {
                tier = TIER2;
                break;
            }
            case 3: {
                tier = TIER3;
                break;
            }
            case 4: {
                tier = TIER4;
                break;
            }
            default: {
                invalid_input = true;
            }
        }
        if (invalid_input) {
            printf("Invalid input! Try again: _\b");
            continue;
        }
        printf("Enter your annual income: $_____\b\b\b\b\b");
        scanf("%lf", &income);
        if (income <= tier) {
            taxes = RATE * tier;
        }
        else {
            taxes = (RATE * tier) + (EXCESS * (income - tier));
        }
        printf("\nThe amount of your tax rate = $%g\n", taxes);
        printf("\nPlease, choose a category:\n");
        printf("***************************************************************\n");
        printf("1) Single\t\t15%% of first $17 850 plus 28%% of excess\n");
        printf("2) Head of Household\t15%% of first $23 900 plus 28%% of excess\n");
        printf("3) Married, Joint\t15%% of first $29 750 plus 28%% of excess\n");
        printf("4) Married, Separate\t15%% of first $14 875 plus 28%% of axcess\n");
        printf("5) EXIT\n");
        printf("***************************************************************\n");
        printf("Your choice: _\b");
    }
    printf("\nHave a nice day!\n\n");
    return 0;
}
