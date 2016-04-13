/* 8.4.c -- counts the average of letters per word */
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char ch;
    char prev = 0x20;
    int words = 0;
    int letters = 0;
    double avg = 0.0;

    printf("Enter a text:\n_\b");
    while ((ch = getchar()) != EOF) {
        if (!isspace(ch) && isalpha(ch)) {
            letters++;
        } else if (isspace(ch) && !isspace(prev)) {
            words++;
        }
        prev = ch;
    }
    avg = (double) letters / (double) words;
    if (avg > 0) {
        printf("The average number of letters in one word is %.1f\n", avg);
    }
    return 0;
}
