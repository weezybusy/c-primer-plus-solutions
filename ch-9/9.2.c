/* 9.2.c -- reads on char and two integers (i, j)
 * and prints the char in rows from i to j */
#include <stdio.h>

void chline(char ch, int i, int j);

int main(void)
{
    char ch;
    int i, j;

    printf("Enter a character and two integers: _\b");
    scanf("%c%d%d", &ch, &i, &j);
    chline(ch, i, j);
    return 0;
}

void chline(char ch, int i, int j)
{
    for (int spaces = 1; spaces < i; spaces++) {
        putchar('\x20');
    }
    for (; i <= j; i++) {
        putchar(ch);
    }
    putchar('\n');
}
