// 6.4 -- Nested loops to create pyramid
#include <stdio.h>
#define ROW 5
#define SPACES 4

int main(void) 
{
    char ch;
    char row;
    char spaces;
    char letters;
    char backward;
    
    printf("Please, insert an uppercase letter: ");
    scanf("%c", &ch);
    
    for(row = 0; row < ROW; row++)
    {
        for(spaces = SPACES; spaces > row; spaces--)
            printf("%c", ' ');
        
        for(letters = (ch - SPACES); letters <= (ch - SPACES) + row; letters++)
            printf("%c", letters);
        
        for(backward = letters; backward > letters - row; backward--)
            printf("%c", backward - 2);
                   
        printf("\n");
    }
    return 0;
}

// ****А               
// ***АВА
// **АВСВА
// *ABCDCBA
// ABCDEDCBA
