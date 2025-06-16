/* Modify the repdigit.c program of Section 8.1 so that it shows which digits (if any) were repeated:

    Enter a number: 939577
    Repeated digit(s): 7 9
*/

#include <stdbool.h> /* C99 only */
#include <stdio.h>

int main(void) {

    bool digit_seen[10] = {false};
    bool repeated[10] = {false};
    int digit, i;
    long n;

    printf("Enter a number: ");
    scanf("%ld", &n);

    while (n > 0) {
        digit = n % 10;
        if (digit_seen[digit]) {
            repeated[digit] = true;
        }
        digit_seen[digit] = true;
        n /= 10;
    }

    printf("Repeated digit(s):");
    for (i = 0; i < 10; i++) {
        if (repeated[i]) {
            printf(" %d", i);
        }
    }
    printf("\n");

    return 0;
}