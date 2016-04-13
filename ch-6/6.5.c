#include <stdio.h>

int main(void)
{
    int lower, upper, index;
    int square, cube;

    printf("Please, enter starting integer: ");
    scanf("%d", &lower);
    printf("and ending integer: ");
    scanf("%d", &upper);
    
    printf("%6s %10s %10s\n", "number", "square", "cube");
    for(index = lower; index <= upper; index++) {
        square = index * index;
        cube = index * square;
        printf("%6d %10d %10d\n", index, square, cube);
    }
    return 0;
}
