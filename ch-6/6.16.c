// 6.16 -- Deposit at 8% per annum with 100000 withdraw annual
#include <stdio.h>

#define DEPOSIT 1000000.0
#define RATE 0.08
#define CASH_PER_YEAR 100000.0

int main(void){
    
    int years;
    double sum = DEPOSIT;
    
    while(sum != 0){
        sum += RATE * DEPOSIT;
        sum -= CASH_PER_YEAR;
        years++;
        printf("%d %g\n", years, sum);
    }
    return 0;
}
