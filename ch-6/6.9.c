#include <stdio.h>

int main(void) {
    int index, lower, upper;
    int sumSquare;
    
    printf("Enter upper and lower integer limits: ");
    scanf("%d%d", &lower, &upper);
    
    while (upper > lower) {
        for (index = lower; index <= upper; index++) {
            sumSquare += index*index;
        }
        printf("Sum of squares from %d to %d equals %d\n",
            lower*lower, upper*upper, sumSquare);
        printf("Enter upper and lower integer limits: ");
        scanf("%d%d", &lower, &upper);
    }
    printf("DONE!\n");
    return 0;   
}
