// 7.3.c -- changes '.' to '!' and '!' to '!!'
#include <stdio.h>

int main(void) {
    char ch;
    int changes = 0;

    while ((ch = getchar()) != '#') {
        if (ch == '.') {
            ch = '!';
            putchar(ch);
            changes++;
        }
        else if (ch == '!') {
            putchar(ch);
            putchar('!');
            changes++;
        }
    }
    printf("\nAmount of changes = %i\n", changes);
    return 0;
}
