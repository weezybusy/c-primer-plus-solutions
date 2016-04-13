#include <stdio.h>
#include <ctype.h>

void menu(void);
char get_choice(void);
double get_number(void);

int main(void)
{
    char choice;
    double first_number;
    double second_number;
    double result;

    menu();
    while ((choice = get_choice()) != 'q') {
        if (choice == '\n')
            continue;
        printf("Enter first number: _\b");
        first_number = get_number();
        printf("Enter second number: _\b");
        second_number = get_number();
        choice = tolower(choice);
        switch (choice) {
            case 'a':
                result = first_number + second_number;
                printf("\n%g + %g = %g\n",
                        first_number, second_number, result);
                break;
            case 's':
                result = first_number - second_number;
                printf("\n%g - %g = %g\n",
                        first_number, second_number, result);
                break;
            case 'm':
                result = first_number * second_number;
                printf("\n%g * %g = %g\n",
                        first_number, second_number, result);
                break;
            case 'd':
                if (second_number == 0) {
                    printf("Enter a number other than 0: _\b");
                    second_number = get_number();
                }
                result = first_number / second_number;
                printf("\n%g / %g = %g\n",
                        first_number, second_number, result);
                break;
            default : printf("Please, enter a, s, m, d or q.\n");
                       menu();
                       continue;
        }
        menu();
    }
    printf("Bye!\n");

    return 0;
}

void menu(void)
{
    printf("\nEnter the operation of your choice:\n");
    printf("===================================\n");
    printf("a. add\t\ts. subtract\n");
    printf("m. multiply\td. devide\n");
    printf("q. quit\n");
    printf("===================================\n");
    printf("_\b");
}

char get_choice(void)
{
    char ch;

    while (isspace(ch = getchar()))
        continue;
    while (getchar() != '\n')
        continue;

    return ch;
}

double get_number(void)
{
    double input;
    char ch;

    while (scanf("%lf", &input) != 1) {
        while((ch = getchar()) != '\n')
            putchar(ch);
        printf(" is not a number.\nPlease, enter a number, "
               "such as 2.5, -1.78E8, or 3: _\b");
    }

    return input;
}
