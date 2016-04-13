/* 8.5.c -- Guessing number (binary search method) */
#include <stdio.h>

int main(void)
{
    int high = 100;
    int low  = 1;
    int guess = (high + low) / 2;
    char response;

    printf("============================================================\n");
    printf("Pick an integer from 1 to 100. I'll try to guess it.\n"
           "\nIf it's low, press:\t\t'l'\nIf it's high, press:\t\t'h'"
           "\nIf my guess is right, press:\t'y'\n");
    printf("============================================================\n");
    printf("Is your number %d?\n", guess);
    while ((response = getchar()) != 'y') {
        if (response == '\n') {
            continue;
        } else if (response == 'l') {
            low = guess;
        } else if (response == 'h') {
            high = guess;
        } else {
            printf("Sorry, I can read only 'l', 'h' or 'y'. Try again.\n");
        }
        while (getchar() != '\n') {
            continue;
        }
        guess = (high + low) / 2;
        printf("%d %d\n", low, high);
        printf("Is it %d?\n", guess);
    }
    printf("I knew I could do it!\n");
    return 0;
}
