#include <stdio.h>
int main(void)
{
    float x;
    printf("Пожалуйста, введите цифру:\n");
    scanf("%f", &x );
    printf("%.1f\n", x);
    printf("%.1e\n", x);
    printf("%+.3f\n", x);
    printf("%.3E\n", x);
    return 0;
}
