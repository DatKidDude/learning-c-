/*
Modify Programming Project 9 from Chapter 5 so that each date entered by the user is stored in a date structure (see Exercise 5). Incorporate the compare_dates functions of Exercises 5 into your program.
*/

#include <stdio.h>
#include <stdbool.h>

#define EARLIER -1
#define LATER 1
#define EQUAL 0

struct date {
    int month;
    int day;
    int year;
};

int compare_dates(struct date d1, struct date d2);
int to_int(struct date d);

int main(void) {

    struct date d1, d2;
    int result;

    printf("Enter first date (mm/dd/yy): ");
    scanf("%d/%d/%d", &d1.month, &d1.day, &d1.year);

    printf("Enter second date (mm/dd/yy): ");
    scanf("%d/%d/%d", &d2.month, &d2.day, &d2.year);

    result = compare_dates(d1, d2);

    if (result == EARLIER) {
        printf("%d/%d/%.2d is earlier than %d/%d/%.2d\n",
            d1.month, d1.day, d1.year, d2.month, d2.day, d2.year);
        return 0;
    } 

    if (result == LATER) {
        printf("%d/%d/%.2d is earlier than %d/%d/%.2d\n",
            d2.month, d2.day, d2.year, d1.month, d1.day, d1.year);
        return 0;
    }

    printf("%d/%d/%.2d is equal to %d/%d/%.2d\n",
            d1.month, d1.day, d1.year, d2.month, d2.day, d2.year);

    return 0;
}

/*
* to_int: Converts yyyy/mm/dd to an integer 
*/
int to_int(struct date d) {
    return d.year * 1000 + d.month * 100 + d.day;
}

/*
* compare_dates: Returns -1 if d1 is an earlier date than d2.
*                +1 if d1 is a later date than d2, and 0 if 
*                d1 and d2 are the same.
*/
int compare_dates(struct date d1, struct date d2) {

    int i1 = to_int(d1);
    int i2 = to_int(d2);

    if (i1 < i2) return EARLIER;
    if (i1 > i2) return LATER;

    return EQUAL;
}