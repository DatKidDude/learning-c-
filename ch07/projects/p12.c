/* Write a program that evaluates an expression:

    Enter an expression: 1+2.5*3
    Value of expression: 10.5

The operands in the expression are floating-point numbers; the operators are +,-,* and /. The expression is evaluated from left to right (no operator takes precedence over any other operator). 
*/


#include <stdio.h>

int main(void) {

    float num = 0.0f, total = 0.0f;
    char ch;

    printf("Enter an expression: ");
    scanf("%f", &total);

    while ((ch = getchar()) != '\n') {
        switch (ch) {
            case '+':
                scanf("%f", &num);
                total += num;
                break;
            case '-':
                scanf("%f", &num);
                total -= num;
                break;
            case '*':
                scanf("%f", &num);
                total *= num;
                break;
            case '/':
                scanf("%f", &num);
                total /= num;
                break;
            default:
                continue;
            }   
        }   

    printf("Value of expression: %f\n", total);

    return 0;
}