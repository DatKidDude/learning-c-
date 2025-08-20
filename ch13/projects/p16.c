/*
Modify Programming Project 1 from Chapter 12 so that it includes the following function:

    void reverse(char *message);

The function reverses the string pointed to by message. Hint: Use two pointers, one initially pointing to the first character of the string and the other initially pointing to the last character. Have the function reverse these characters and then move the pointers toward each other, repeating the process until the pointers meet.
*/

#include <stdio.h>

#define MAX 100

void reverse(char *message);

int main(void) {

    char message[MAX];
    char ch, *p;

    printf("Enter a message: ");
    for (p = &message[0]; (ch = getchar()) != '\n' && p < &message[MAX]; p++) {
        *p = ch;
    }
    *p = '\0';

    reverse(message);
    printf("Reversal is: %s", message);

    return 0;
}

void reverse(char *message) {
    char *ptr_msg_start = message,
         *ptr_msg_end = message,
          temp;

    while (*ptr_msg_end) {
        *ptr_msg_end++;
    }
    *ptr_msg_end--;

    while (ptr_msg_start < ptr_msg_end) {
        temp = *ptr_msg_start;
        *ptr_msg_start = *ptr_msg_end;
        *ptr_msg_end = temp;
        *ptr_msg_start++, *ptr_msg_end--;
    }

}