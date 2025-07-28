/*
Modify Programming Project 14 from Chapter 8 so that it uses a pointer instead of an integer to keep track of the current position in the array that contains the sequence.
*/

#include <stdio.h>

#define SIZE 100

int main(void) {

    char ch, terminating_char, *p, *pos;
    char sentence[SIZE] = {0};

    printf("Enter a sentence: ");

    for (p = sentence; (ch = getchar()) != '\n' && p < sentence + SIZE;) {
        if (ch == '?' || ch == '.' || ch == '!') {
            terminating_char = ch;
            break;
        }
        *p++ = ch;
    }

    // a long sentence 6
    printf("Reversal of sentence: ");

    for (; p >= sentence; p--) {
        if (*p == ' ' || p == sentence) {
            pos = p == sentence ? sentence: p + 1;
            while (*pos != ' ' && *pos != '\0') {
                putchar(*pos++);
            }
            putchar(' ');
        }
    }

    printf("\b%c", terminating_char);

    return 0;
}