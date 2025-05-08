/* Write a program that calculates how many digits a number contains. You may assume that the number has no more than 4 digits. HINT: Use if statements to test the number. For example, if the number is between 0 and 9, it has one digit. If the number is between 10 and 99, it has two digits. */

#include <stdio.h>

int main(void) {

    int num;
    
    printf("Enter a number: ");
    scanf("%d", &num);

    if (0 <= num && num < 10) {
        printf("The number %d has 1 digit", num);
    } else if (10 <= num && num < 100) {
        printf("The number %d has 2 digits", num);
    } else if (100 <= num && num < 1000) {
        printf("The number %d has 3 digits", num);
    } else {
        printf("The number %d has 4 or more digits", num);
    }

    return 0;
}