/* Write a program that asks the user to enter a dollars-and-cents amount, then displays the amount with 5% tax added*/

#include <stdio.h>

int main(void) {
    float amount;
    float tax = 0.05f;
    
    printf("Enter an amount: ");
    scanf("%f", &amount);

    printf("With tax added: $%.2f", (amount * tax) + amount);

    return 0;
}