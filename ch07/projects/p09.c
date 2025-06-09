/* Write a program that asks the user for a 12-hour time, then displays the time in 24-hour form:

    Enter a 12-hour time: 9:11 PM
    Equivalent 24-hour time: 21:11

See Programming Project 8 for a description of the input format. 
*/

#include <stdio.h>
#include <ctype.h>

int main(void) {

    int hour, min;
    char meridiam;

    printf("Enter a 12-hour time: ");
    scanf("%d :%d %c", &hour, &min, &meridiam);

    printf("%d:%d", (toupper(meridiam) == 'P' ? 12 : 0) + hour, min);

    return 0;
}