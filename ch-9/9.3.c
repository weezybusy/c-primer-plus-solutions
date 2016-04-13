/* 9.3.c -- asks for a character and number of columns
 *          and rows to print this character */
#include <stdio.h>

void chLineRow(char c, int a, int b);

int main(void)
{
    char ch;
    int col, row;

    printf("Enter a character (q to quit): _\b");
    while ((ch = getchar()) != 'q') {
        if (ch == '\n'){
            continue;
        }
        printf("Enter number of columns and number of rows: _\b");
        if (scanf("%d %d", &col, &row) != 2) {
            break;
        }
        chLineRow(ch, col, row);
        printf("\nEnter next character (q to quit): _\b");
    }
    return 0;
}

void chLineRow(char ch, int a, int b)
{
    for (int row = 0; row < b; row++) {
        for (int col = 0; col < a; col++) {
            putchar(ch);
        }
        putchar('\n');
    }
}
