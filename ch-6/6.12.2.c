// 6.12 -- my variant #2
#include <stdio.h>
#define SIZE 8

int main(void) {
    
    int i;
    int square[SIZE];
    int value = 1;
    
    for(i = 0; i < SIZE; i++) {
        square[i] = value;
        value *= 2;
        do {
            printf("%i\n", square[i]);
        } while(square[i] < square[SIZE]);
    }
    return 0;
}
