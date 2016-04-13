#include <stdio.h>
#define SIZE 8

int main(void) {
    double a[SIZE];
    double b[SIZE];
    int i;
    
    for(i = 0; i < SIZE; i++) {
        scanf("%lf", &a[i]);
    }
    
    b[0] = a[0];
    for(i = 1; i < SIZE; i++) {   
        b[i] = a[i] + b[i-1];
    }
    
    for(i = 0; i < SIZE; i++) {
        printf("|%2g ", a[i]);
    }
    printf("|\n");
    
    for(i = 0; i < SIZE; i++) {
        printf("|%2g ", b[i]);
    }
    
    printf("|\n");
    return 0;
}
