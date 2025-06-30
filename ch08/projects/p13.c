/* Modify Programming Project 11 from Chapter 7 so that the program labels its output:

    Enter a first and last name: Lloyd Fosdick
    You entered the name: Fosdick, L.

The program will need to store the last name (but not the first name) in an array of characters until it can be printed. You may assume that the last name is no more than 20 characters long.
*/

#include <stdio.h>

int main(void) {

    int i = 0;
    char ch, first_initial;
    char last_name[20] = {0};

    printf("Enter a first and last name: ");
    scanf(" %c", &first_initial);

    while ((ch = getchar()) != ' ') {
        ;
    }

    while ((ch = getchar()) != '\n') {
        if (ch == ' ') {
            ;
        } else {
            last_name[i++] = ch;
        }
    }

    for (int j = 0; j <= i; j++) {
        printf("%c", last_name[j]);
    }

    printf(", %c.", first_initial);

    return 0;
}