// 5.6 -- finds sum of first n integers
#include <stdio.h>

int main(void)
{
    int count, total;
    int n;
    
    printf("Enter number of days: ");
    scanf("%d", &n);
    count = 0;
    total = 0;
    while(count++ < n)
        total = count * count;
    printf("sum = %d\n", total);
    return 0;
}
