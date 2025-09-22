/*
Completing exercise 5 to finish project 6 of chapter 16.

Write the following functions, assuming that the date structure contains three members: month, day and year (all of type int).

    (a) int day_of_year(struct date d);
    Returns the day of the year (an integer between 1 and 366) that corresponds to the date d.

    (b) int compare_dates(struct date d1, struct date d2);
    Returns -1 if d1 is an earlier date than d2. +1 if d1 is a later date than d2, and 0 if d1 and d2 are the same.

I validated the total days output at:
https://www.omnicalculator.com/everyday-life/day-of-the-year
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

int day_of_year(struct date d);
int compare_dates(struct date d1, struct date d2);
bool is_leap_year(struct date d);
int to_int(struct date d);

int main(void) {

    int d1_day, d2_day, result;

    struct date d1 = {.month = 9, .day = 21, .year = 2025};
    struct date d2 = {.month = 3, .day = 3, .year = 2024};

    // d1 total days should equal 264
    printf("d1: %d/%02d/%02d\nTotal days: %d\n\n", 
            d1.year, d1.month, d1.day, day_of_year(d1));
    // d2 total days should equal 63
    printf("d2: %d/%02d/%02d\nTotal days: %d\n\n", 
            d2.year, d2.month, d2.day, day_of_year(d2));

    printf("%d", compare_dates(d1, d2));

    return 0;
}


/*
* is_leap_year: Returns true if the year is a leap year
*               else returns false
*/
bool is_leap_year(struct date d) {
    return (d.year % 4 == 0 && d.year % 100 != 0) || (d.year % 400 == 0);
}

/*
* day_of_year: Returns the day of the year
*              (an integer between 1 and 366)
*              that corresponse to the date d.
*/
int day_of_year(struct date d) {

    int i, doy = 0;

    const int days_of_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (d.month > 1 && is_leap_year(d)) {
        doy++;
    }

    for (i = 0; i < d.month - 1; i++) {
        doy += days_of_month[i];
    }

    return doy + d.day;
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