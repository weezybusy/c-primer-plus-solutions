/**
 * 3.6.c
 *
 * The mass of a single molecule of water is about 3.0×10 -23 grams. A quart of
 * water is about 950 grams. Write a program that requests an amount of water,
 * in quarts, and displays the number of water molecules in that amount.
 */

#include <stdio.h>

int main(void)
{
    float mass_mol = 3.0e-23;   /* mass of water molecule in grams */
    float mass_qt = 950;        /* mass of quart of water in grams */
    float quarts;
    float molecules;
    
    printf("Enter the number of quarts of water: ");
    scanf("%f", &quarts);
    molecules = quarts * mass_qt / mass_mol;
    printf("%.2f quarts of water contain %e molecules.\n", quarts, molecules);

    return 0;
}
