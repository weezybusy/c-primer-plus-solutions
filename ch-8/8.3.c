/* 8.3.c -- Counts uppercase and lowercase letters */
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char ch;
    int capital, lowercase;

    while ((ch = getchar()) != EOF) {
        if (isalpha(ch)) {
            if (isupper(ch)) {
                capital++;
            } else {
                lowercase++;
            }
        }
    }
    printf("capital letters = %d, lowercase letters = %d\n",
        capital, lowercase);
    return 0;
}
