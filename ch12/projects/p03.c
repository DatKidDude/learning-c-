/*
Simplify Programming Project 1(b) by taking advantage of the fact that an array name can be used as a pointer
*/

#include <stdio.h>

#define MAX 100

int main(void) {

    char message[MAX];
    char ch, *p;

    printf("Enter a message: ");
    for (p = message; (ch = getchar()) != '\n' && p < message + MAX; p++) {
        *p = ch;
    }

    p--;

    printf("Reversal is: ");
    for (;  p >= message; p--) {
        printf("%c", *p);
    }

    return 0;
}