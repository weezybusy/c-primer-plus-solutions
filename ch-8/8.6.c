/* 8.6.c -- rewritten get_first function.
 * Modification alows to skip all white-space characters
 * until the first non-white-space character encountered */
#include <stdio.h>
#include <ctype.h>

char get_first(void);

int main(void)
{
    char ch;

    printf("Enter some text:\n");
    ch = get_first();
    printf("%c\n", ch);
    return 0;
}

char get_first(void)
{
    char ch;

    while (isspace(ch = getchar())) {
        continue;
    }
    while (getchar() != '\n') {
        continue;
    }
    return ch;
}
