// 7.7.c -- salary and taxes calculation
#include <stdio.h>
#define BASE_PAY   10      // $10 per hour
#define BASE_HRS   40      // hours at base pay
#define OVERTIME   1.5     // 1 hour over 40 hours = 1.5 hours
#define AMT1       300     // 1st rate tier (alternative minimum tax)
#define AMT2       150     // 2nd rate tier (alternative minimum tax)
#define RATE1      0.15    // rate for 1st tier
#define RATE2      0.20    // rate for 2nd tier
#define RATE3      0.25    // rate for 3rd tier

int main(void) {
    double hours;
    double gross;
    double net;
    double taxes;

    // getting number of hours
    printf("Enter a number of hours worked this week: ");
    scanf("%lf", &hours);

    // Gross settlement
    if (hours <= BASE_HRS) {
        gross = hours * BASE_PAY;
    }
    else {
        gross = (BASE_HRS * BASE_PAY) +
                 (((hours - BASE_HRS) * OVERTIME) * BASE_PAY);
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
    printf("gross: $%g\ntaxes: $%g\nnet: $%g\n", gross, taxes, net);
    return 0;
}
