/* 9.6.c -- reads a character and if it's a letter
 *          returns its index in alphabet */
#include <stdio.h>
#include <ctype.h>

int alpha_index(char ch);

int main(void)
{
    char ch;

    printf("Enter a character: _\b");
    while ((ch = getchar()) != EOF) {
        if (ch == '\n') {
            printf("Enter a character: _\b");
            continue;
        }
        ch = tolower(ch);
        if (isalpha(ch)) {
            printf("%c = %d\n", ch, alpha_index(ch));
        } else {
            continue;
        }
    }
    return 0;
}

int alpha_index(char ch)
{
    int index = ch - 96;
    return index;
}
