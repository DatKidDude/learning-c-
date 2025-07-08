/* Write a function that computes the value of the following polynomial:

    3x^5 + 2x^4 - 5x^3 - x^2 + 7x - 6

Write a program that asks the user to enter a value for x, calls the function to compute the value of the polynomials, and then displays the value returned by the function.
*/


#include <stdio.h>

int polynomial(int number, int degree);

int main(void) {

    int x, power, answer = 0;
    int coefficients[6] = {-6, 7, -1, -5, 2, 3};

    printf("Enter a value for x: ");
    scanf("%d", &x);

    for (int i = 0; i <= 5; i++) {
        power = polynomial(x, i); 
        answer += coefficients[i] * power;
    }

    printf("%d", answer);

    return 0;
}

int polynomial(int number, int degree) {
    int value = 1;
    for (int i = 0; i < degree; i++) {
        value *= number; 
    } 
    return value;
}