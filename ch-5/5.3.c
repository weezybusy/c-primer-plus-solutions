// 5.3 -- days --> weeks and days
#include <stdio.h>

int main(void)
{
    const int D_IN_W = 7; // 7 days in week
    int num, days, weeks;
    printf("Please, enter number of days:\n");
    scanf("%d", &num);
    weeks = num / D_IN_W;
    days = num % D_IN_W;
    printf("%d days is %d week(s) and %d day(s).\n", num, days, weeks);
    return 0;
}
