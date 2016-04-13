// 6.3 -- embedded loop
#include <stdio.h>
#define SIZE 6
int main(void) 
{
    // variant 1    
    char ch = 'F';
    char start;
    char end;
    
    for(end = ch; end >= 'A'; end--)
    {
        for(start = ch; start >= end; start--)
            printf("%c", start);
        printf("\n");
    }
    
    // variant 2
    int i, j, k;
    for(i = 0; i < SIZE; i++)
    {
        for(j = 0; j <= i; j++)
        {
            k = 70 - j;
            printf("%c", k);
        }
        printf("\n");
    }
    return 0;
}

// F
// FE
// FED
// FEDC
// FEDCB
// FEDCBA
