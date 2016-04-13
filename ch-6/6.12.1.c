// 6.12 -- my variant #1
#include <stdio.h>
int power(int x, int y);

int main(void) {
    
    int i;
    int square[8];
    int val = 2;
    
    for(i = 0; i < 8; i++) {
        square[i] = power(val, i);
        do {
            printf("%i\n", square[i]);
        } while(square[0] < square[8]);
    }
    return 0;
}

int power(int x, int y) {
    
    int i;
    int pow = 1;
    for(i = 0; i < y; i++) {
        pow *= x;
    }
    return pow;
}


