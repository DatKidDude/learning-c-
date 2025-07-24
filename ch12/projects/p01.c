/* 
(a) Write a program that reads a message, then prints the reversal of the message:

    Enter a message: Don't get mad, get even.
    Reversal is: .neve teg ,dam teg t'noD

Hint: Read the message one character at a time (using getchar) and store the characters in an array. Stop reading when the array is full or the character read is '\n'.

(b) Revise the program to use a pointer instead of an integer to keep track of the current position in the array
*/

#include <stdio.h>

#define MAX 100

int main(void) {

    char message[MAX];
    char ch, *p;

    printf("Enter a message: ");
    for (p = &message[0]; (ch = getchar()) != '\n' && p < &message[MAX]; p++) {
        *p = ch;
    }

    p--;

    printf("Reversal is: ");
    for (;  p >= &message[0]; p--) {
        printf("%c", *p);
    }

    return 0;
}