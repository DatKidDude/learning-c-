/* Write a program that asks the user to enter a fraction, then reduces the fraction to lowest terms:

    Enter a fraction: 6/12
    In lowest terms: 1/2

Hint: To reduce a fraction to lowest terms, first compute the GCD of the numerator and denominator. Then divide both the numerator and denominator by the GCD.
*/

#include <stdio.h>

int main(void) {

    int num, den, r, m, n;

    printf("Enter a fraction: ");
    scanf("%d/%d", &num, &den);

    m = num;
    n = den;
    while (n != 0) {
        r = m % n;
        m = n;
        n = r;
    }

    printf("In lowest terms: %d/%d", num/m, den/m);

    return 0;
}