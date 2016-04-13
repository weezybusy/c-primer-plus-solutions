// 6.15 -- Simple and complicated deposite percents
#include <stdio.h>

#define DEPOSIT 100.0
#define RATE_SIMP 0.10
#define RATE_COMP 0.05

int main(void) {

    double daphne = DEPOSIT;
    double deidre = DEPOSIT;
    int years = 0;
    
    while(daphne >= deidre) {
        daphne += RATE_SIMP * DEPOSIT;
        deidre += RATE_COMP * deidre;
        years++;
    }
    
    printf("Investment values after %d years:\n", years);
    printf("Daphne: $%.2f\n", daphne);
    printf("Deidre: $%.2f\n", deidre);
    
    return 0;
}
