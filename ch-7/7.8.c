// 7.8.c -- salary and taxes calculation
#include <stdio.h>
#include <stdbool.h>
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

int main(void) {
    int choice;
    double wage_rate;
    double hours;
    double gross;
    double net;
    double taxes;
    double invalid_input;

    // getting prefered wage rate
    printf("\nEnter the number corresponding to the desired pay rate "
           "or action:\n");
    printf("*****************************************************************\n");
    printf("1) $8.75/hour\t\t2) $9.33/hour\t\t5) exit\n"
           "3) $10.00/hour\t\t4) $11.20/hour\n");
    printf("*****************************************************************\n");
    printf("Your choice: _\b");
    while (scanf("%d", &choice) == 1 && choice != 5) {
        invalid_input = false;
        switch (choice) {
            case 1: {
                wage_rate = BASE_PAY1;
                break;
            }
            case 2: {
                wage_rate = BASE_PAY2;
                break;
            }
            case 3: {
                wage_rate = BASE_PAY3;
                break;
            }
            case 4: {
                wage_rate = BASE_PAY4;
                break;
            }
            default: {
                printf("Invalid number! Try again: _\b");
                invalid_input = true;
            }
        }
        if (invalid_input) {
            continue;
        }
        printf("Enter a number of hours worked this week: _\b");
        scanf("%lf", &hours);

       // Gross settlement
        if (hours <= BASE_HRS) {
            gross = hours * wage_rate;
        }
        else {
            gross = (BASE_HRS * wage_rate) +
                    (((hours - BASE_HRS) * OVERTIME) * wage_rate);
        }
        // calculation of taxes
        if (gross <= AMT1) {
           taxes = gross * RATE1;
        }
        else if (gross <= (AMT1 + AMT2)) {
            taxes = (AMT1 * RATE1) + ((gross - AMT1) * RATE2);
        }
        else {
            taxes = (AMT1 * RATE1) + (AMT2 * RATE2) +
                    ((gross - (AMT1 + AMT2)) * RATE3);
        }
        // salary minus taxes
        net = gross - taxes;
        // printing results
        printf("\ngross: $%g\ttaxes: $%g\tnet: $%g\n", gross, taxes, net);
        printf("\nEnter the number corresponding to the desired pay rate "
               "or action:\n");
        printf("*****************************************************************\n");
        printf("1) $8.75/hr\t\t2) $9.33/hr\t\t5) exit\n"
               "3) $10.00/hr\t\t4) $11.20/hr\n");
        printf("*****************************************************************\n");
        printf("Your choice: _\b");
    }
    printf("\nHave a nice day!\n\n");
    return 0;
}
