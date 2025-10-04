/*
Section 15.2 describes a file, stack.c, that provides functions for storing integers in a stack. In that section, the stack was implemented as an array. Modify stack.c so that a stack is now stored as a linked list. Replace the contents and top variables by a single variable that points to the first node in the list (the "top" of the stack). Write the functions in stack.c so that they use this pointer. Remove the is_full function, instead having push return either true (if memory was available to create a node) or false (if not).
*/

// 247 & 380

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int value;
    struct node *next;
};

struct node *top = NULL;

bool push(int n);
int pop(void);
bool is_empty(void);
void make_empty(void);

int main(void)
{

    int result;

    for (int i = 1; i <= 5; i++) {
        result = push(i);
        if (!result) {
            printf("No room on the stack.\n");
            return EXIT_FAILURE;
        }
    }

    make_empty();

    return 0;
}

void make_empty(void)
{   
    struct node *temp;
    while (!is_empty()) {
        temp = top;
        top = top->next;
        free(temp);
    }
}

bool is_empty(void) 
{
    return top == NULL;
}

bool push(int n)
{
    struct node *new_node;

    new_node = malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Error: Malloc failed.\n");
        return false;
    }
    new_node->value = n;
    new_node->next = top;
    top = new_node;

    return true;
}

int pop(void)
{   
    int result;
    struct node *temp;

    if (is_empty()) {
        printf("Error: Stack underflow\n");
        exit(EXIT_FAILURE);
    }

    result = top->value;
    temp = top;
    top = top->next;
    free(temp);
    
    return result;
}