/* Write a program that takes a first name and last name entered by the user and displays the last name, a comma, and the first initial, followed by a period:

    Enter a first and last name: Lloyd Fosdick
    Fosdick, L

The user's input may contain extra spaces before the first name, between the first and last names, and after the last name. 
*/

#include <stdio.h>
#include <ctype.h>

int main(void) {

    char ch, first_initial, last_name;

    printf("Enter a first and last name: ");
    scanf(" %c", &first_initial);

    while ((ch = getchar()) != ' ') {

    }

    while ((last_name = getchar()) != '\n') {
        if (last_name == ' ') {

        } else {
            printf("%c", last_name);
        }
    }

    printf(", %c.", first_initial);

    return 0;
}