/* The value of the mathematical constant e can be expressed as an infinite series:

    e = 1 + 1/1! + 1/2! + 1/3! +...

Write a program that approximates e by computing the value

    1 + 1/1! + 1/2! + 1/3! + ... + 1/n!

where n is an integer entered by the user.
*/

#include <stdio.h>

int main(void) {

    int i, n;
    float total = 1.0f, fact = 1.0f;

    printf("Enter an integer: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        fact *= i;
        total += 1.0f / fact;
    }

    printf("%f", total);

    return 0;
}