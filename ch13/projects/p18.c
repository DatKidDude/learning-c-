/*
Write a program that accepts a date from the user in the form mm/dd/yyyy and then displays it in the form month dd, yyyy. where month is the name of the month.

    Enter a date (mm/dd/yyyy): 2/17/2011
    You entered the date February 17, 2011

Store the month names in an array that constains pointers to strings.
*/

#include <stdio.h>
#include <string.h>

#define OFFSET 1

int main(void) {

    char *months[] = {"January", "February", "March", "April", "May", "June",
                      "July", "August", "September", "October", "November", "December"};
    int month,
        day,
        year;


    printf("Enter a date: ");
    scanf(" %2d /%2d /%4d", &month, &day, &year);
    
    printf("%s %.2d, %d", months[month - OFFSET], day, year);

    return 0;
}