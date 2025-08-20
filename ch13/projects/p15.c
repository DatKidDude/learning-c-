/*
Modify Programming Project 6 from Chapter 10 so that it includes the following function: 

    int evaluate_RPN_expression(const char *expression);

The function returns the value of the RPN expression pointed to by expression.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define STACK_SIZE 100

/* external variables */
int contents[STACK_SIZE] = {0};
int top = 0;

/* prototypes */
void make_empty(void);
void stack_overflow(void);
void stack_underflow(void);
bool is_empty(void);
bool is_full(void);
void push(int operand);
int pop(void);
int evaluate_RPN_expression(const char *expression);

int main(void) {

    char ch,
         expr[STACK_SIZE],
         *p;

    while (true) {

        p = expr;
        printf("Enter an RPN expression: ");
        while ((ch = getchar()) != '\n' && p < expr + STACK_SIZE) {
            *p++ = ch;
        }

        printf("Value of expression: %d\n", evaluate_RPN_expression(expr));
        p = expr;// reset the pointer 
        while (*p) {
            *p++ = '\0';
        }

    }
    
    return 0;
}

int evaluate_RPN_expression(const char *expression) {

    int op1, op2;
    while (*expression) {
        if (isdigit(*expression)) {
            push(*expression - '0');
        } else {
            switch (*expression) {
                case '+':
                   push(pop() + pop());
                   break;
                case '-':
                    op2 = pop();
                    op1 = pop();
                    push(op1 - op2);
                    break;
                case '*':
                    push(pop() * pop());
                    break;
                case '/':
                    op2 = pop();
                    op1 = pop();
                    push(op2 / op1);
                    break;
                case '=':
                    return pop();
                    break;
                case ' ':
                    break;
                default:
                    exit(EXIT_FAILURE);
            }
        }
        expression++;
    }
    exit(EXIT_FAILURE);
}

void make_empty(void) {
    top = 0;
}

bool is_empty(void) {
    return top == 0;
}

bool is_full(void) {
    return top == STACK_SIZE;
}

void push(int operand) {
    if (is_full()) {
        stack_overflow();
    } else {
        contents[top++] = operand;
    }
}

int pop(void) {
    if (is_empty()) {
        stack_underflow();
    } else {
        return contents[--top];
    }
}

void stack_underflow(void) {
    printf("Not enough operands in expression\n");
    exit(EXIT_FAILURE);
}

void stack_overflow(void) {
    printf("Expression is too complex\n");
    exit(EXIT_FAILURE);
}

