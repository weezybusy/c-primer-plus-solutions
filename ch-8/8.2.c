// 8.2.c -- Read char and print its symbol and int value
#include <stdio.h>

int main(void)
{
    char ch;
    int count = 0;

    while ((ch = getchar()) != EOF) {
        count++;
        if (count <= 10) {
            if (ch <= 32) {
                switch (ch) {
                    case '\n':
                        printf("'\\n': %-6d", ch);
                        break;
                    case '\t':
                        printf("'\\t': %-6d", ch);
                        break;
                    default:
                        printf("'^%c': %-6d", ch + 64, ch);
                }
            } else {
                printf("'%c': %-6d", ch, ch);
            }
        } else {
            putchar('\n');
            if (ch <= 32) {
                switch (ch) {
                    case '\n':
                        printf("'\\n': %-6d", ch);
                        break;
                    case '\t':
                        printf("'\\t': %-6d", ch);
                        break;
                    default:
                        printf("'^%c': %-6d", ch + 64, ch);
                }
            } else {
                printf("'%c': %-6d", ch, ch);
            }
            count = 1;
        }
    }
    return 0;
}
