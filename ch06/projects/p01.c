/* Write a program that finds the largest in a series of numbers entered by the user. The program must prompt the user to enter numbers one by one. When the user enters 0 or a negative number, the program must display the largest nonnegative number entered:

    Enter a number: 60
    Enter a number: 38.3
    Enter a number: 4.89
    Enter a number: 100.62
    Enter a number: 75.2295
    Enter a number: 0

    The largest number entered was 100.62

Notice the number aren't necessarily integers
*/

#include <stdio.h>

int main(void) {

    float number;
    float max = 0.0f;

    do {
        printf("Enter a number: ");
        scanf("%f", &number);
        if (number > max) {
            max = number;
        }
    } while (number > 0);

    printf("\nThe largest number entered was %g", max);

    return 0;
}