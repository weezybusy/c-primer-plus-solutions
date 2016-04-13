#include <stdio.h>
int main(void)
{
    char name[20];
    float growth;
    printf("Пожалуйста, укажите ваш рост в сантиметрах:\n");
    scanf("%f", &growth_sm);
    printf("а теперь введте ваше имя:\n");
    scanf("%s", name);
    printf("%s, ваш рост составляет %.2f метра.\n", name, growth / 100);
    return 0;
}
