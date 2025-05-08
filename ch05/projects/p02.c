/* Write a program that asks the user for a 24-hour time, then displays the time in 12-hour form: Be careful not to display 12:00 as 0:00. */

#include <stdio.h>

int main(void) {
    int hour, min;

    printf("Enter a 24-hour time: ");
    scanf("%d :%d", &hour, &min);

    if (hour < 11) {
        printf("Equivalent 12-hour time: %d:%d AM",
            hour == 0 ? 12 : hour, min);
    } else {
        printf("Equivalent 12-hour time: %d:%d PM", 
            hour == 12 ? 12 : hour - 12, min);
    }
}