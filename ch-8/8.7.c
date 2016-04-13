// 8.7.c -- salary and taxes calculation (modified version of 7.8.c)
#include <stdio.h>
#include <ctype.h>
#define BASE_PAY1  8.75    // 1st wage rate
#define BASE_PAY2  9.33    // 2nd wage rate
#define BASE_PAY3  10.00   // 3rd wage rate
#define BASE_PAY4  11.20   // 4th wage rate
#define BASE_HRS   40      // hours at base pay
#define OVERTIME   1.5     // 1 hour over 40 hours = 1.5 hours
#define AMT1       300     // 1st rate tier (alternative minimum tax)
#define AMT2       150     // 2nd rate tier (alternative minimum tax)
#define RATE1      0.15    // rate for 1st tier
#define RATE2      0.20    // rate for 2nd tier
#define RATE3      0.25    // rate for 3rd tier

char get_choice(void);
void menu(void);

int main(void) {
    char choice;
    double pay;
    double hours;
    double gross;
    double net;
    double taxes;

    menu();
    while ((choice = get_choice()) != 'q') {
        if (choice == '\n') {       // skip over new lines
            continue;
        }
        choice = tolower(choice);   // change if letter is uppercase
        switch (choice) {
            case 'a': pay = BASE_PAY1; break;
            case 'b': pay = BASE_PAY2; break;
            case 'c': pay = BASE_PAY3; break;
            case 'd': pay = BASE_PAY4; break;
            default : printf("Please, enter a, b, c, d or q.\n");
                      menu();
                      continue; // go to beginning of loop
        }
        printf("Enter a number of hours worked this week: _\b");
        scanf("%lf", &hours);

       // Gross settlement
        if (hours <= BASE_HRS) {
            gross = hours * pay;
        }
        else {
            gross = (BASE_HRS * pay) +
                    (((hours - BASE_HRS) * OVERTIME) * pay);
        }
        // calculation of taxes
        if (gross <= AMT1) {
           taxes = gross * RATE1;
        }
        else if (gross <= (AMT1 + AMT2)) {
            taxes = (AMT1 * RATE1) +
                    ((gross - AMT1) * RATE2);
        }
        else {
            taxes = (AMT1 * RATE1) +
                    (AMT2 * RATE2) +
                    ((gross - (AMT1 + AMT2)) * RATE3);
        }
        // salary minus taxes
        net = gross - taxes;
        // printing results
        printf("\ngross: $%.2f\ttaxes: $%.2f\tnet: $%.2f\n",
                gross, taxes, net);
        // printing menu
        menu();
    }
    printf("Done!\n");
    return 0;
}

char get_choice(void)
{
    char ch;

    while (isspace(ch = getchar())) {
        continue;
    }
    while (getchar() != '\n') {
        continue;
    }
    return ch;
}

void menu(void)
{
    // getting prefered wage rate
    printf("\nEnter the letter corresponding to the desired pay rate "
           "or action:\n");
    printf("*********************************************************"
           "********\n");
    printf("a) $%.2f/hr\t\tb) $%.2f/hr\t\tq) quit\n", BASE_PAY1, BASE_PAY2);
    printf("c) $%.2f/hr\t\td) $%.2f/hr\n", BASE_PAY3, BASE_PAY4);
    printf("*********************************************************"
           "********\n");
    printf("Your choice: _\b");
}
