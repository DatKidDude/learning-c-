/* Modify the repdigit.c program of Section 8.1 so that the user can enter more than one number to be tested for repeated digits. The program should terminate when the user enters a number that's less than or equal to 0. */

#include <stdbool.h> /* C99 only */
#include <stdio.h>

int main(void) {

    int repeated[10] = {0};
    int digit, i;
    long n;

    printf("Enter a number: ");
    scanf("%ld", &n);

    while (n > 0) {

        while (n > 0) {
            digit = n % 10;
            repeated[digit]++;
            n /= 10;
        }

        printf("Digit:\t\t");
        for (i = 0; i < 10; i++) {
            printf("%2d", i);
        }

        printf("\nOccurrences:\t");
        for (i = 0; i < 10; i++) {
            printf("%2d", repeated[i]);
        }

        // reset the array 
        for (i = 0; i < sizeof(repeated) / sizeof(repeated[0]); i++) {
            repeated[i] = 0;
        }

        printf("\n\nEnter a number: ");
        scanf("%ld", &n);
        printf("\n");
    }

    return 0;
}