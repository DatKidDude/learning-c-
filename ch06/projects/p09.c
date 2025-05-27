/* Programming Project 8 in Chapter 2 asked you to write a program that calculates the remaining balance on a loan after the first, second, and third monthly payments. Modify the program so that it also asks the user to enter the number of payments and then displays the balance remaining after each of these payments. */

#include <stdio.h>

int main(void) {

    float loan;
    float rate;
    float monthly_payment;
    float monthly_rate;
    int num_of_payments;
    int i;

    printf("Enter amount of loan: ");
    scanf("%f", &loan);

    printf("Enter interest rate: ");
    scanf("%f", &rate);

    printf("Enter monthly payment: ");
    scanf("%f", &monthly_payment);

    printf("Enter the number of payments: ");
    scanf("%d", &num_of_payments);

    for (i = 1; i <= num_of_payments; i++) {
        loan = loan - monthly_payment + (loan * rate / 100 / 12);
        printf("\nBalance remaining after %d payment(s): %.2f", i, loan);
    }

    return 0;
}