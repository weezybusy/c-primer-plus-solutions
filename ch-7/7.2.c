// 7.2.c -- Print chars and their decimal ascii codes 8 pairs per string
#include <stdio.h>
#define PAIRS 8

int main(void) {
    char ch;
    int ch_count = 0;

    while ((ch = getchar()) != '#') {
        if (ch_count < PAIRS) {
            printf("'%c' - %-6i", ch, ch);
            ch_count++;
        }
        else {
            putchar('\n');
            printf("'%c' - %-6i", ch, ch);
            ch_count = 0;
        }
    }
    putchar('\n');
    return 0;
}

