#include <stdio.h>
#define SIZE 8

int main(void) {
    int num[SIZE];
    int i;
    
    printf("Enter %d numbers:\n", SIZE);
    for(i = 0; i < SIZE; i++) {
        scanf("%d", &num[i]);
    }
    printf("Backward numbers:\n");
    for(i = SIZE - 1; i >= 0; i--) {
        printf("%-3d", num[i]);
    }
    printf("\n");
    return 0;
}
