/*
Modify Programming Project 15 from Chapter 8 so that it includes the following function:

    void encrypt(char *message, int shift);

The function expects message to point to a string containing the message to be encrypted; shift represents the amount by which each letter in the message is to be shifted.
*/

#include <stdio.h>
#include <string.h>

#define SIZE 100

void encrypt(char *message, int shift);

int main(void) {

    char ch,
        ciphertext[SIZE];
    int shift,
        i;

    printf("Enter message to be encrypted: ");
    for (i = 0; (ch = getchar()) != '\n' && i < SIZE; i++) {
        ciphertext[i] = ch;
    }
    ciphertext[i] = '\0';

    do {
        printf("Enter shift amount (1 - 25): ");
        scanf("%d", &shift);
    } while (!(shift > 0 && shift <= 25));

    encrypt(ciphertext, shift);

    printf("Encrypted message: %s", ciphertext);

    return 0;
}

void encrypt(char *message, int shift) {

    while (*message) {
        if ('A' <= *message && *message <= 'Z') {
            *message = ((*message - 'A') + shift) % 26 +'A';
        } else if ('a' <= *message && *message <= 'z') {
            *message = ((*message - 'a') + shift) % 26 +'a';
        } 
        message++;
    }
}