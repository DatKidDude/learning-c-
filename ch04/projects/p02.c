/* Extend the program in Programming Project 1 to handle three-digit numbers. */

#include <stdio.h>

int main(void) {

    int num;

    printf("Enter a three-digit number: ");
    scanf("%d", &num);

    printf("%d%d%d", num % 10, (num / 10) % 10, num / 100);

    return 0;
}