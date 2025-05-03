/* Write a program that asks the user to enter a two-digit number, then prints the number with its digits reversed. Hint: If n is an integer, then n % 10 is the last digit in n and n /10 is n with the last digit removed. */

#include <stdio.h>

int main(void) {

    int num;

    printf("Enter a two-digit number: ");
    scanf("%d", &num);

    printf("%d%d", num % 10, num / 10);

    return 0;
}