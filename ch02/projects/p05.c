/* Write a program that asks the user to enter a value for x and then displays the value of the following polynomial:
3x^5 + 2x^4 - 5x^3 -x^2 + 7x - 6
Hint: C doesn't have an exponentiation operator. 
*/

#include <stdio.h>

int main(void) {
    float x;

    printf("Enter a value for x: ");
    scanf("%f", &x);

    printf("%.1f", (3 * x * x * x * x * x) + (2 * x * x * x * x) - (5 * x * x * x) - (x * x) + (7 * x) - 6);

    return 0;
}