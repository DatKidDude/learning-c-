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

   Modify Programming Project 8 from Chapter 5 so that the times are stored in a single array. The elements of the array will by structures, each containing a departure time and the corresponding arrival time. (Each time will be an integer, representing the number of minutes since midnight.) The program will use a loop to search the array for the departure time closest to the time entered by the user.

*/

#include <stdio.h>

struct time {
    int departure;
    int arrival;
};

int main(void) {

    int hour, min, user_time, dt, t1, t2, t3, t4, t5, t6, t7, t8,
        a1, a2, a3, a4, a5, a6, a7, a8;

    // Converting departure times to minutes
    t1 = 8 * 60;        // 8 am
    t2 = 9 * 60 + 43;   // 9:43 am
    t3 = 11 * 60 + 19;  // 11:19 am
    t4 = 12 * 60 + 47;  // 12:47 pm
    t5 = 14 * 60;       // 2:00 pm
    t6 = 15 * 60 + 45;  // 3:45 pm
    t7 = 19 * 60;       // 7:00 pm
    t8 = 21 * 60 + 45;  // 9:45 pm

    // Arrival times to minutes
    a1 = 10 * 60 + 16;  // 10:16 am
    a2 = 11 * 60 + 52;  // 11:52 am
    a3 = 13 * 60 + 31;  // 1:31 pm
    a4 = 15 * 60;       // 3:00 pm
    a5 = 16 * 60 + 8;   // 4:08 pm
    a6 = 17 * 60 + 55;  // 5:55 pm
    a7 = 21 * 60 + 20;  // 9:20 pm
    a8 = 23 * 60 + 58;  // 11:58 pm               

    const struct time times[] = {
        {t1, a1}, {t2, a2}, {t3, a3}, {t4, a4},
        {t5, a5}, {t6, a6}, {t7, a7}, {t8, a8}
    }; 

    printf("Enter time of departure (military time): ");
    scanf("%d :%d", &hour, &min);

    user_time = hour * 60 + min;

    size_t array_length = sizeof(times) / sizeof(times[0]);
    
    for (int i = 0; i < array_length; i++) {
        dt = times[i].departure + ((times[i + 1].departure - times[i].departure) / 2);
        if (user_time <= dt) {
            printf("Closest departure time is %d:%.2d %c.m., arriving at %d:%.2d %c.m.",
            times[i].departure / 60 > 12 ? times[i].departure / 60 - 12 : times[i].departure / 60,
            times[i].departure % 60,
            times[i].departure / 60 > 12 ? 'p' : 'a',
            times[i].arrival / 60 > 12 ? times[i].arrival / 60 - 12 : times[i].arrival / 60,
            times[i].arrival % 60,
            times[i].arrival / 60 > 12 ? 'p' : 'a');
            return 0;
        };
    }

    printf("Closest departure time is %d:%.2d %c.m., arriving at %d:%.2d %c.m.",
            times[array_length].departure / 60 > 12 ? times[array_length].departure / 60 - 12 : times[array_length].departure / 60,
            times[array_length].departure % 60,
            times[array_length].departure / 60 > 12 ? 'p' : 'a',
            times[array_length].arrival / 60 > 12 ? times[array_length].arrival / 60 - 12 : times[array_length].arrival / 60,
            times[array_length].arrival % 60,
            times[array_length].arrival / 60 > 12 ? 'p' : 'a');

    return 0;
}