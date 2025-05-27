/* The value of the mathematical constant e can be expressed as an infinite series:

    e = 1 + 1/1! + 1/2! + 1/3! +...

Write a program that approximates e by computing the value

    1 + 1/1! + 1/2! + 1/3! + ... + 1/n!

where n is an integer entered by the user.
*/

#include <stdio.h>

int main(void) {

    int i, n;
    float result = 1.0f;

    printf("Enter an integer: ");
    scanf("%d", &n);

    return 0;
}