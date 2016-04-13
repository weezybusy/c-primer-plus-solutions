// 7.11.c -- ABC Mail Order Grocery
#include <stdio.h>
#include <ctype.h>


int main(void) {

    const double price_artichokes = 1.25;
    const double price_beets = 0.65;
    const double price_carrots = 0.89;
    const double discount_rate = 0.5;

    char choice;
    double lb_artichokes;
    double lb_beets;
    double lb_carrots;
    double lb_total;

    double cost_artichokes;
    double cost_beets;
    double cost_carrots;
    double cost_total;
    double final_total;
    double discount;
    double shipping;

    printf("\nChoose a product or exit:\n");
    printf("*********************************\n");
    printf("a) Artichokes\t\tb) Beets\nc) Carrots\t\tq) QUIT\n");
    printf("*********************************\n");
    printf("\nYour choice: _\b");
    while ((choice = getchar()) != 'q' && choice != 'Q') {
        if (choice == '\n') {
            continue;
        }
        while (getchar() != '\n') {
            continue;
        }
        choice = tolower(choice);
        switch (choice) {
            case 'a': {
                printf("Enter pounds of artichokes: _\b");
                scanf("%lf", &lb_artichokes);
                break;
                }
            case 'b': {
                printf("Enter pounds of beets: _\b");
                scanf("%lf", &lb_beets);
                break;
            }
            case 'c': {
                printf("Enter pounds of carrots: _\b");
                scanf("%lf", &lb_carrots);
                break;
            }
            default: {
                printf("%c is not a valid choice.\n");
            }
        }
        printf("\nChoose a product or exit:\n");
        printf("*********************************\n");
        printf("a) Artichokes\t\tb) Beets\nc) Carrots\t\tq) QUIT\n");
        printf("*********************************\n");
        printf("\nYour choice: _\b");
    }
    cost_artichokes = price_artichokes * lb_artichokes;
    cost_beets = price_beets * lb_beets;
    cost_carrots = price_carrots * lb_carrots;
    cost_total = cost_artichokes + cost_beets + cost_carrots;
    lb_total = lb_artichokes + lb_beets + lb_carrots;

    if (lb_total <= 0) {
        shipping = 0.0;
    }
    else if (lb_total < 5) {
        shipping = 3.5;
    }
    else if (lb_total < 20) {
        shipping = 10.0;
    }
    else {
        shipping = 8.0 + (lb_total * 0.1);
    }
    if (cost_total > 100) {
        discount = discount_rate * cost_total;
    }
    else {
        discount = 0.0;
    }
    final_total = cost_total + shipping - discount;
    printf("\nYOUR ORDER:\n");
    printf("***************************************************\n");
    printf("%.2f lbs of artichokes at $%.2f per pound: $%.2f\n",
            lb_artichokes, price_artichokes, cost_artichokes);
    printf("%.2f lbs of beets at $%.2f per pound: $%.2f\n",
            lb_beets, price_beets, cost_beets);
    printf("%.2f lbs of carrots at $%.2f per pound: $%.2f\n",
            lb_carrots, price_carrots, cost_carrots);
    printf("Total cost of vegitables : $%.2f\n", cost_total);
    if (cost_total > 100) {
        printf("Volume discount: $%.2f\n", discount);
    }
    printf("Shipping: $%.2f\n", shipping);
    printf("***************************************************\n");
    printf("Total charges: $%.2f\n\n", final_total);

    return 0;
}
