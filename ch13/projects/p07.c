/*
Modify Programming Project 11 from Chapter 5 so that it uses arrays containing pointers to strings instead of switch statements. For example, instead of using a switch statement to print the word for the first digit, use the digit as an index into an array that contains the strings "twenty", "thirty", and so forth.
*/

#include <stdio.h>
#include <string.h>

int main(void) {

    char *ones[] = {"", "-one", "-two", "-three", "-four", "-five", "-six", "-seven", "-eight", "-nine"};
    char *tens[] = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    char *teens[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    int number;

    printf("Enter a two-digit number: ");
    scanf("%d", &number);
    printf("You entered the number ");

    if (number / 10 == 1) {
        printf("%s", teens[number % 10]);
    } else {
        printf("%s%s\n", tens[number / 10 - 2], ones[number % 10]);
    }

    return 0;
}