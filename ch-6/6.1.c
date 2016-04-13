// 6.1 -- output of array (26 letters)
#include <stdio.h>
#define SIZE 26

int main(void) {
    char lcase[SIZE];
    int i, j;
    
    // variant 1
    for(i = 0; i < SIZE; i++)
        lcase[i] = 'a' + i;
    for(i = 0; i < SIZE; i++)
        printf("%c", lcase[i]);
    printf("\n");
    
    // variant 2
    for(i = 0; i < SIZE; i++)
    {
        lcase[i] = 'a' + i;
        printf("%c", lcase[i]);
    }
    printf("\n");
    
    // variant 3
    for(i = 0, j = 97; i < SIZE, j < 123; i++, j++)
    {
        lcase[i] = j;
        printf("%c", lcase[i]);
    }
    printf("\n");
    return 0;
}



