// 8.1.c -- count chars until encounters EOF
#include <stdio.h>

int main(void)
{
    char ch;
    int count = 0;

    while ((ch = getchar()) != EOF) {
        count++;
    }
    printf("%d\n", count);
    return 0;
}
