/*
Modify Programming Project 11 from Chapter 7 so that it includes the following function:

    void reverse_name(char *name);

The function expects name to point to a string containing a first name followed by a last name. It modifies the string so that the last name comes first, followed by a comma, a space, the first initial, and a period. The original string may contain extra spaces before the first name, between the first and last names, and after the last name.
*/

#include <stdio.h>
#include <string.h>

#define LEN 50

void reverse_name(char *name);

void clear_whitespace(void);

int main(void) {

    char name[LEN + 1];

    printf("Enter first and last name: ");
    fgets(name, sizeof(name), stdin);
    reverse_name(name);

    return 0;
}

void reverse_name(char *name) {
    
    char *ptr_name = name, initial;

    while (*ptr_name == ' ') {
        *ptr_name++;
    }
    initial = *ptr_name++;

    while (*ptr_name && *ptr_name++ != ' ');

    while (*ptr_name && *ptr_name != '\n') {
        putchar(*ptr_name++);
    }

    printf(", %c.", initial);
}
