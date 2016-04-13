#include <stdio.h>
#include <string.h>
int main(void)
{
    char name[21];
    printf("Пожалуйста, введите ваше имя:\n");
    scanf("%s", name );
    printf("\"%s\"\n", name);
    printf("\"%20s\"\n", name);
    printf("%7s\n", name);
    return 0;
}
