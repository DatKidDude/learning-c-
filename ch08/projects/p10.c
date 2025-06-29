/* Modify Programming Project 8 from Chapter 5 so that the departure times are stored in an array and the arrival times are stored in a second array. (The times are integers, representing the number of minutes since midnight.) The program will use a loop to search the array of departure times for the one closest to the time entered by the user.*/

#include <stdio.h>

int main(void) {

    int hour, min, user_time, dt, t1, t2, t3, t4, t5, t6, t7, t8, a1, a2, a3, a4, a5, a6, a7, a8, d_hour, d_min, a_hour, a_min;

    // Converting departure times to minutes
    t1 = 8 * 60;        // 8 am
    t2 = 9 * 60 + 43;   // 9:43 am
    t3 = 11 * 60 + 19;  // 11:19 am
    t4 = 12 * 60 + 47;  // 12:47 pm
    t5 = 14 * 60;       // 2:00 pm
    t6 = 15 * 60 + 45;  // 3:45 pm 945
    t7 = 19 * 60;       // 7:00 pm 1140
    t8 = 21 * 60 + 45;  // 9:45 pm 1305

    // Converting arrival times to minutes
    a1 = 10 * 60 + 16;  // 10:16 am
    a2 = 11 * 60 + 52;  // 11:52 am
    a3 = 1 * 60 + 31;   // 1:31 pm
    a4 = 15 * 60;       // 3:00 pm
    a5 = 16 * 60 + 8;   // 4:08 pm
    a6 = 17 * 60 + 55;  // 5:55 pm
    a7 = 21 * 60 + 20;  // 9:20 pm
    a8 = 23 * 60 + 58;  // 11:58 pm

    int departure_times[8] = {t1, t2, t3, t4, t5, t6, t7, t8};
    int arrival_times[8] = {a1, a2, a3, a4, a5, a6, a7, a8};

    printf("Enter time of departure (military time): ");
    scanf("%d :%d", &hour, &min);

    user_time = hour * 60 + min;

    for (int i = 0; i < 7; i++) {
        dt = departure_times[i] + ((departure_times[i + 1] - departure_times[i]) / 2);
        if (user_time <= dt) {
            d_hour = (departure_times[i] > 12) ? departure_times[i] / 60 - 12 : departure_times[i];
            d_min = departure_times[i] % 60;
            a_hour = (arrival_times[i] > 12) ? arrival_times[i] / 60 - 12 : arrival_times[i];
            a_min = arrival_times[i] % 60;

            printf("Closest departure time is %d:%.2d %c.m., arriving at %d:%.2d %c.m.",
            d_hour, d_min, departure_times[i] / 60 > 12 ? 'p' : 'a',
            a_hour, a_min, arrival_times[i] / 60 > 12 ? 'p' : 'a'
            );
        }
    }

    d_hour = (departure_times[7] > 12) ? departure_times[7] / 60 - 12 : departure_times[7];
    d_min = departure_times[7] % 60;
    a_hour = (arrival_times[7] > 12) ? arrival_times[7] / 60 - 12 : arrival_times[7];
    a_min = arrival_times[7] % 60;

    printf("Closest departure time is %d:%.2d %c.m., arriving at %d:%.2d %c.m.",
    d_hour, d_min, departure_times[7] / 60 > 12 ? 'p' : 'a',
    a_hour, a_min, arrival_times[7] / 60 > 12 ? 'p' : 'a'
    );

    return 0;
}