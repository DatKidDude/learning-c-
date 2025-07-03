/* Modify Programming Project 5 from Chapter 5 so that it uses a function to compute the amount of income tax. When passed an amount of taxable income, the function will return the tax due.*/

#include <stdio.h>

float income_amount(float income);

int main(void) {

    float income, tax;

    printf("Enter taxable income amount: ");
    scanf("%f", &income);

    tax = income_amount(income);

    printf("Tax due: %.2f\n", tax);

    return 0;
}

float income_amount(float income) {
    float tax;

    if (income < 750.00f) {
        tax = income * .01f;
    } else if (income <= 2250.00f) {
        tax = 7.50f + (.02f * (income - 750.00f)); 
    } else if (income <= 3750.00f) {
        tax = 37.50f + (.03f * (income - 2250.00f));
    } else if (income <= 5250.00f) {
        tax = 82.50f + (.04f * (income - 3750.00f));
    } else if (income <= 7000.00f) {
        tax = 142.50f + (.05f * (income - 5250.00f));
    } else {
        tax = 230.00f + (.06f * (income - 7000.00f));
    }

    return tax;
}