/* Modify Programming Project 6 from Chapter 3 so that the user may add, subtract, multiply, or divide two fractions (by entering either +,-,*,/ between the fractions). */

#include <stdio.h>

int main(void) {

    int num1, denom1, num2, denom2, result_num, result_denom;
    char c;

    printf("Enter two fractions separated by a (+, -, * or /) sign: " ); 
    scanf("%d/%d %c %d/%d", &num1, &denom1, &c, &num2, &denom2); 

    switch (c) {
        case '+':
            result_num = num1 * denom2 + num2 * denom1;
            result_denom = denom1 * denom2;
            // printf("The sum is %d/%d", result_num, result_denom);
            break;
        case '-':
            result_num = num1 * denom2 - num2 * denom1;
            result_denom = denom1 * denom2;
            // printf("The difference is %d/%d", result_num, result_denom);
            break;
        case '*':
            result_num = num1 * num2;
            result_denom = denom1 * denom2;
            // printf("The product is %d/%d", result_num, result_denom);
            break;
        case '/':
            result_num = num1 * denom2;
            result_denom = denom1 * num2;
            // printf("The quotient is %d/%d", result_num, result_denom);
            break;
        default:
            printf("Operation %c not supported", c);
            break;
    }

    int temp, num_temp = result_num, gcd = result_denom;

    // find the GCD 
    while (num_temp != 0) {
        temp = gcd % num_temp;
        gcd = num_temp;
        num_temp = temp;
    } 

    if (result_num / gcd == result_denom / gcd) {
        printf("Result: %d\n", result_num / result_denom);
    } else if (result_num > result_denom) {
        printf("Result: %d %d/%d",
        result_num / result_denom, result_num % result_denom, result_denom);
    } else {
        printf("Result: %d/%d", result_num / gcd, result_denom / gcd);
    }

    return 0;
}