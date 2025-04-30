/* Write a program that formats product information entered by the user */

#include <stdio.h>

int main(void) {

    int item_no;
    float price;
    int month, day, year;

    printf("Enter item number: ");
    scanf("%d", &item_no);

    printf("Enter unit price: ");
    scanf("%f", &price);

    printf("Enter purchase date (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &month, &day, &year);

    printf("Item\t\tUnit\t\tPurchase\n\t\tPrice\t\tDate\n");
    printf("%d\t\t$%7.2f\t%.2d/%.2d/%.4d",item_no, price, month, day, year);

    /* My original solution */
    // printf("Item\t\tUnit\t\tPurchase\n\t\tPrice\t\tDate\n%d\t\t$%7.2f\t%d/%d/%d", item_no, price, month, day, year);

    return 0;
}