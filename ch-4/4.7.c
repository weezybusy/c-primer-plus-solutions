#include <stdio.h>
#define GAL 3.785 // к-во литров на галлон
#define MILE 1.609 // к-во км на милю

int main(void)
{
    float miles, gallons, km, liters;
    
    printf("Введите пройденное расстояние в милях:\n");
    scanf("%f", &miles);
    printf("а теперь объем затраченного топлива в галлонах:\n");
    scanf("%f", &gallons);
    printf("На одном галлоне топлива вы проезжаете %.1f миль.\n",
        miles/gallons);
    printf("Итого ваш расход топлива составляет %.1f галлонов на "
           "100 миль.\n", 100/(miles/gallons));
    printf("Переведем пройденный путь в километры:\n");
    km = miles*MILE;
    printf("%.1f миль = %.1f километров\n", miles, km);
    printf("Переведем затраченный объем топлива из галлонов в "
           "литры:\n");
    liters = GAL*gallons;
    printf("%.1f галлонов = %.1f литров.\n", gallons, liters);
    printf("На одном литре топлива вы проезжаете %.1f километров.\n",
        km/liters);
    printf("Итого ваш расход топлива составляет %.1f литров на 100 "
           "километров.\n", 100/(km/liters));

    return 0;
}
