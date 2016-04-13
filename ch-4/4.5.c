#include <stdio.h>
#include <string.h>

int main(void)
{
    char name[21], surname[21];
    printf("Пожалуйста, укажите ваше имя:\n");
    scanf("%s", name);
    printf("а теперь фамилию:\n");
    scanf("%s", surname);
    printf("%s %s\n%7d %5d\n",
        name, surname, strlen(name), strlen(surname));
    printf("%s %s\n%-7d %-5d\n",
        name, surname, strlen(name), strlen(surname));
    return 0;
}
