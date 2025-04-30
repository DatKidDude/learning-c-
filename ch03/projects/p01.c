/* Write a program that accepts a date from the user in the form 
mm/dd/yyyy and then displays it in the form yyyymmdd */

#include <stdio.h>

int main(void) {

    int month;
    int day;
    int year;

    printf("Enter a date (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &month, &day, &year);

    printf("You entered the date %.4d%.2d%.2d", year, month, day);

    return 0;
}