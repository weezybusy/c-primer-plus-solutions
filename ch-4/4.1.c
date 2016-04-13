#include <stdio.h>
int main(void)
{
    char name[20], surname[20];
    printf("Пожалуйста, введите ваше имя:\n");
    scanf("%s", name);
    printf("и фамилию:\n");
    scanf("%s", surname);
    printf("\"%s, %s\"\n", surname, name);
    return 0;
}
