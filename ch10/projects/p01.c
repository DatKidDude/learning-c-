/*
Modify the stack example of Section 10.2 so that it stores characters instead of
integers. Next, add a `main` function that asks the user to enter a series of
parentheses and/or braces, then indicates whether or not they're properly
nested:

```
Enter parentheses and/or braces: ((){}{()})
Parentheses/braces are nested properly
```

*Hint*: As the program reads characters, have it push each left parenthesis or
left brace. When it reads a right parenthesis or brace, have it pop the stack
and check that the item popped is a matching parenthesis or brace. (If not, the
parentheses/braces aren't nested properly.) When the program reads the new-line
character, have it check whether the stack is empty; if so, the
parentheses/braces are matched. If the stack *isn't* empty (or if
`stack_underflow` is ever called), the parentheses/braces aren't matched. If
`stack_overflow` is called, have the program print the message `Stack overflow`
and terminate immediately.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STACK_SIZE 100

/* external variables */
char contents[STACK_SIZE] = {0};
int top = 0;

/* prototypes */
void make_empty(void);
void stack_overflow(void);
void stack_underflow(void);
bool is_empty(void);
bool is_full(void);
void push(char symbol);
char pop(void);

int main(void) {

    char ch, symbol;

    printf("Enter parentheses and/or braces: ");
    while ((ch = getchar()) != '\n') {
        if (ch == ')' && pop() != '(') {
            printf("Parantheses/braces are not nested properly.\n");
            return 0;
        } else if (ch == '}' && pop() != '{') {
            printf("Parantheses/braces are not nested properly.\n");
            return 0;
        } else if (ch == '(' || ch == '{') {
            push(ch);
        }
    }

    if (!is_empty()) {
        printf("Parentheses/braces are not nested properly\n");
        return 0;
    }

    printf("Parentheses/braces are nested properly\n");

    return 0;
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

void push(char symbol) {
    if (is_full()) {
        stack_overflow();
    } else {
        contents[top++] = symbol;
    }
}

char pop(void) {
    if (is_empty()) {
        stack_underflow();
    } else {
        return contents[--top];
    }
}

void stack_underflow(void) {
    printf("Stack underflow");
    exit(EXIT_FAILURE);
}

void stack_overflow(void) {
    printf("Stack overflow");
    exit(EXIT_FAILURE);
}