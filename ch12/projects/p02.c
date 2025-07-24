/*
Write a program that reads a message, then checks whether it's a palindrome (the letters in the message are the same from left to right as from right to left):

    Enter a message: He lived as a devil, eh?
    Palindrome

    Enter a message: Mada, I am Adam.
    Not a palindrome

Ignore all characters that aren't letters. Use integer variables to keep track of positions in the array. 

(b) Revise the program to use pointers instead of integers to keep track of positions in the array.
*/

#include <stdio.h>
#include <ctype.h>

#define MAX 100

int main(void) {

    char message[MAX];
    char ch, *p = message, *j;

    while ((ch = tolower(getchar())) != '\n' && p < message + MAX) {
        if (isalpha(ch)) {
            *p++ = ch;
        }
    }

    p--;

    for (j = message; j < p; j++, p--) {
        if (*j != *p) {
            printf("Not a palindrome");
            return 0;
        }
    }

    printf("Palindrome");

    return 0;
}