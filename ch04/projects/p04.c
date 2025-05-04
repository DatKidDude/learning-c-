/* Write a program that reads an integer entered by the user and displays it in octal (base 8): The output should be displayed using five digits, even if fewer digits are sufficient. Hint: To convert the number to octal, first divide it by 8; the remainder is the last digit of the octal number. Then divide the original number by 8 and repeat the process to arrive at the next-to-last digit. */

#include <stdio.h>

int main(void) {

    int n, d1, d2, d3, d4, d5;

    printf("Enter a number between 0 and 32767: ");
    scanf("%d", &n);

    d1 = n % 8; 
    n /= 8; 

    d2 = n % 8; 
    n /= 8; 

    d3 = n % 8; 
    n /= 8; 

    d4 = n % 8; 
    n /= 8; 

    d5 = n % 8; 

    printf("In octal, your number is: %d%d%d%d%d", d5, d4, d3, d2, d1);

    return 0;
}