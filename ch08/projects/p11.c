/* Modify Programming Project 4 from Chapter 7 so that the program labels its output:

    Enter phone number: 1-800-COL-LECT
    In numeric form: 1-800-265-5328

The program will need to store the phone number (either in its original form or in its numeric form) in an array of characters until it can be printed. You may assume that the phone number is no more than 15 characters long.
*/

#include <stdio.h>

int main(void) {

    int counter = 0;
    char ch;
    char phone_no[15] = {0};

    printf("Enter phone number: ");
    while ((ch = getchar()) != '\n') {
        phone_no[counter] = ch;
        counter++;
    }

    printf("In numerical form: ");
    for (int i = 0; i < counter; i++) {
        switch (phone_no[i]) {
            case 65: case 66: case 67:
                printf("%d", 2);
                break;
            case 68: case 69: case 70:
                printf("%d", 3);
                break;
            case 71: case 72: case 73:
                printf("%d", 4);
                break;
            case 74: case 75: case 76:
                printf("%d", 5);
                break;
            case 77: case 78: case 79:
                printf("%d", 6);
                break;
            case 80: case 82: case 83:
                printf("%d", 7);
                break;
            case 84: case 85: case 86:
                printf("%d", 8);
                break;
            case 87: case 88: case 89:
                printf("%d", 8);
                break;
            default:
                printf("%c", (char) phone_no[i]);
                break;
        }
    }

    return 0;
}