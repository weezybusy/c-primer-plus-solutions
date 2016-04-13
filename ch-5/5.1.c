// 5.1 -- turns minutes to hours and minutes
#include <stdio.h>
#define MIN_IN_H 60 // minutes per hour

int main(void)
{
    int time, hours, minutes;
    printf("Please, enter number of minutes:\n");
    scanf("%d", &time);
    while(time > 0)
    {
        hours = time / MIN_IN_H;
        minutes = time % MIN_IN_H;
        printf("%d minutes equals to %d hour(s) and %d minute(s)\n",
            time, hours, minutes);
        printf("Try again or enter '0' to quit:\n");
        scanf("%d", &time);
    }
    printf("Good bye!\n");
    return 0;
}
