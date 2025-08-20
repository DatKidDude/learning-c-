/*
Modify Programming Project 2 from Chapter 12 so that it includes the following function:

    bool is_palindrome(const char *message);

The function returns true if the string pointed to by message is a palindrome.
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100

bool is_palindrome(const char *message);

int main(void) {

    char message[MAX + 1];
    char ch, *p = message;

    printf("Enter a message: ");
    while ((ch = tolower(getchar())) != '\n' && p < &message[MAX]) {
        if (isalpha(ch)) {
            *p++ = ch;
        }
    }

    *p = '\0';

    if (is_palindrome(message)) {
        printf("Palindrome\n");
        return 0;
    }

    printf("Not a palindrome\n");

    return 0;
}

bool is_palindrome(const char *message) {

    const char *p = message,
               *j;
 
    while (*p) {
        p++;
    }
    p--;

    for (j = message; j < p; j++, p--) {
        if (*j != *p) {
            return false;
        }
    }


    return true;
}