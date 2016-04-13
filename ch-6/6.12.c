// 6.12
#include <stdio.h>
#define SIZE 8

int main( void )
{
    int twopows[SIZE];
    int i;
    int value = 1;    /* 2 to the 0 */
    
    for (i = 0; i < SIZE; i++)
    {
        twopows[i] = value;
        value *= 2;
    }
    
    i = 0;
    do
    {
        printf("%d ", twopows[i]);
        i++;
    } while (i < SIZE);
    printf("\n");
                    
    return 0;
}

