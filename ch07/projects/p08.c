/* Modify Programming Project 8 from Chapter 5 so that the user enters a time using the 12-hour clock. The input will have the form hours:minutes followed by either A, P, AM, or PM (either lower-case or upper-case). White space is allowed (but not required) between the numerical time and the AM/PM indicator. Examples of valid input.

    1:15P
    1:15PM
    1:15p
    1:15pm
    1:15 P
    1:15 PM
    1:15 p 
    1:15 pm

You may assume the input has one of these forms; there is no need to test for errors.
*/

#include <stdio.h>
#include <ctype.h>

int main(void) {

    int hour, min, user_time, t1, t2, t3, t4, t5, t6, t7, t8;
    char meridiam;

    // Converting departure times to minutes
    t1 = 8 * 60;        // 8 am
    t2 = 9 * 60 + 43;   // 9:43 am
    t3 = 11 * 60 + 19;  // 11:19 am
    t4 = 12 * 60 + 47;  // 12:47 pm
    t5 = 14 * 60;       // 2:00 pm
    t6 = 15 * 60 + 45;  // 3:45 pm
    t7 = 19 * 60;       // 7:00 pm
    t8 = 21 * 60 + 45;  // 9:45 pm

    printf("Enter time of departure (standard time with AM/PM): ");
    scanf("%d :%d %c", &hour, &min, &meridiam);

    user_time = (((toupper(meridiam) == 'P' ? 12 : 0) + hour) * 60) + min;

    if (user_time <= t1 + (t2 - t1) / 2) {
        printf("Closest departure time is 8:00 a.m., arriving at 10:16 a.m.\n");
    } else if (user_time < t2 + (t3 - t2) / 2) {
        printf("Closest departure time is 9:43 a.m., arriving at 11:52 a.m.\n");
    } else if (user_time < t3 + (t4 - t3) / 2) {
        printf("Closest departure time is 11:19 a.m., arriving at 1:31 p.m.\n");
    } else if (user_time < t4 + (t5 - t4) / 2) {
        printf("Closest departure time is 12:47 p.m., arriving at 3:00 p.m.\n");
    } else if (user_time < t5 + (t6 - t5) / 2) {
        printf("Closest departure time is 2:00 p.m., arriving at 4:08 p.m.\n");
    } else if (user_time < t6 + (t7 - t6) / 2) {
        printf("Closest departure time is 3:45 p.m., arriving at 5:55 p.m.\n");
    } else if (user_time < t7 + (t8 - t7) / 2) {
        printf("Closest departure time is 7:00 p.m., arriving at 9:20 p.m.\n");
    } else {
        printf("Closest departure time is 9:45 p.m., arriving at 11:58 p.m.\n");
    }

    return 0;
}