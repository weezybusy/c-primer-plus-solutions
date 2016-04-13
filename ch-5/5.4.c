// 5.4 -- height in centimeters to feet and inches
#include <stdio.h>
#define S_PER_I 2.54  // inch = 2.54 centimeters 
#define I_PER_F 12.0  // feet = 12 inches

int main(void)
{
    float centimeters, inches, feet, inches_sum;
    
    printf("Enter height in centimeters: ");
    scanf("%f", &centimeters);
    while(centimeters > 0)
    {
        inches_sum = centimeters / S_PER_I;
        feet = inches_sum / I_PER_F;
        inches = (int) inches_sum % (int) I_PER_F;
        printf("%.1f cm = %d feet and %.1f inches.\n",
            centimeters, feet, inches);
        printf("Enter height in centimeters or '0' to quit: ");
        scanf("%f", &centimeters);
    }
    printf("Done!\n");
    return 0;
}
