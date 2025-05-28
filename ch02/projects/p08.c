/* Write a program that calculates the remaining balance on a loan after the first, second, and third monthly payments:
*/

#include <stdio.h>

int main(void) {

    float loan;
    float rate;
    float monthly_payment;
    float monthly_rate;

    printf("Enter amount of loan: ");
    scanf("%f", &loan);

    printf("Enter interest rate: ");
    scanf("%f", &rate);

    printf("Enter monthly payment: ");
    scanf("%f", &monthly_payment);

    monthly_rate = rate / 100 / 12;

    loan += (loan * monthly_rate);
    loan -= monthly_payment;
    printf("Balance remaining after first payment: %.2f\n", loan);

    loan += (loan * monthly_rate);
    loan -= monthly_payment;
    printf("Balance remaining after second payment: %.2f\n", loan);

    loan += (loan * monthly_rate);
    loan -= monthly_payment;
    printf("Balance remaining after third payment: %.2f\n", loan);

    return 0;
}