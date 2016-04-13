// 5.2 -- prints numbers from the entered to +10
#include <stdio.h>

int main(void)
{
    int num, sum;
    printf("Please, enter the number: ");
    scanf("%d", &num);
    sum = num + 10;
    while(num <= sum)
    {
        printf("%-4d", num);
        ++num;
    }
    printf("\n");
    return 0;
}
