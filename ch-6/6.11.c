// 6.11 -- 
#include <stdio.h>
#define ONE 1.0

int power(int a); 

int main(void) {
    int limit, x;
    double i, j; 
    
    printf("Enter the number of sequences: ");
    scanf("%i", &limit);
    
    for(i = 0, j = 0, x = 1; x <= limit; x++) {
        i += ONE/x;
        j += (ONE/x)*power(x);
        printf("%lf + %lf = %lf\n", i, j, i + j);
    }
    return 0;
}

int power(int a) {
    int pow = -1;
    int i;
    
    for(i = 0; i < a; i++) {
        pow *= -1;   
    }
    return pow;
}
