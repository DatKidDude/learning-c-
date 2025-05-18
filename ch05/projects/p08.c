/* The following table shows the daily flights from 
   one city to another:

   Departure time   Arrival time
   -----------------------------
    8:00 am         10:15 am
    9:43 am         11:52 am
   11:19 am          1:31 pm
   12:47 pm          3:00 pm
    2:00 pm          4:08 pm
    3:45 pm          5:55 pm
    7:00 pm          9:20 pm
    9:45 pm         11:58 pm

   Write a program that asks user to enter a time
   (expressed in hours and minutes, using the 24-hour
   clock). The program then displays the departure and
   arrival times for the flight whose departure time is
   closest to that entered by the user:

       Enter a 24-hour time: 13:15
       Closest departure time is 12:47 pm, arriving at 3:00 pm

   Hint: Convert the input into a time expressed in minutes
   since midnight, and compare it to the departure times, also
   expressed in minutes since midnight. For example, 13:15 is
   13 x 60 + 15 = 795 minutes since midnight, which is closer to
   12:47 pm (767 minutes since midnight) than to any of the
   other departure times.

*/

#include <stdio.h>

int main(void) {

    int hour, min, user_time, t1, t2, t3, t4, t5, t6, t7, t8;

    // Converting departure times to minutes
    t1 = 8 * 60;        // 8 am
    t2 = 9 * 60 + 43;   // 9:43 am
    t3 = 11 * 60 + 19;  // 11:19 am
    t4 = 12 * 60 + 47;  // 12:47 pm
    t5 = 14 * 60;       // 2:00 pm
    t6 = 15 * 60 + 45;  // 3:45 pm
    t7 = 19 * 60;       // 7:00 pm
    t8 = 21 * 60 + 45;  // 9:45 pm

    printf("Enter time of departure (military time): ");
    scanf("%d :%d", &hour, &min);

    user_time = hour * 60 + min;

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