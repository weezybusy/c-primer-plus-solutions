// 7.6.c -- Count encountered 'ei' chars in text
#include <stdio.h>

int main(void) {
    char ch;
    char prev_ch;
    int ei_count = 0;

    printf("Enter some text:\n");
    while ((ch = getchar()) != '#') {
        if (ch == 'i' && prev_ch == 'e') {
            ei_count++;
        }
        prev_ch = ch;
    }
    printf("%i\n", ei_count);
    return 0;
}
