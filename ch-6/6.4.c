#include <stdio.h>

int main(void) {
    char ch;
    char row;
    char spaces;
    char letter;
    
    printf("Please, insert an uppercase letter: ");
        ch = getchar();
    
    for(row = 'A'; row <= ch; row++) {
        for(spaces = ch; spaces > row; spaces--) {
            putchar(' ');
        }
        for(letter = 'A'; letter < row; letter++) {
            putchar(letter);    
        }
        for(; letter >= 'A'; letter--) {
            putchar(letter);        
        }
        printf("\n");
    }
    return 0;
}
