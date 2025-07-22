/*
Modify Programming Project 8 from Chapter 5 so that it includes the following
function:

```c
void find_closest_flight(int desired_time, 
                         int *departure_time, 
                         int *arrival_time);
```

This function will find the flight whose departure time is closest to
`desired_time` (expressed in minutes sinces midnight). It will store the
departure and arrival times of this flight (also expressed in minutes since
midnight) in the variables pointed to by `departure_time` and `arrival_time`,
respectively.
*/

#include <stdio.h>

void find_closest_flight(int desired_time, int *departure_time, int *arrival_time);

int main(void) {

    int hour,
        min, 
        desired_time,
        depature_time,
        arrival_time;
    
    char *d_ampm, *a_ampm;

    printf("Enter time of departure (military time): ");
    scanf("%d :%d", &hour, &min);

    desired_time = hour * 60 + min;
    find_closest_flight(desired_time, &depature_time, &arrival_time);

    d_ampm = (depature_time / 60 >= 12) ? "P.M." : "A.M.";
    a_ampm = (arrival_time / 60 >= 12) ? "P.M." : "A.M.";

    printf("Closest departure time is %.2d:%.2d %s, arriving at %.2d:%.2d %s\n", 
            (depature_time / 60) > 12 ? (depature_time / 60) - 12 : depature_time, depature_time % 60, d_ampm,
            (arrival_time / 60) > 12 ? (arrival_time / 60) - 12 : arrival_time, arrival_time % 60, a_ampm);

    return 0;
}

/*
* find_closest_flight:
* --------------------
* Finds the flight whose departure time is closest to desired_time
*/
void find_closest_flight(int desired_time, int *departure_time, int *arrival_time) {

    int t1, t2, t3, t4, t5, t6, t7, t8, 
        a1, a2, a3, a4, a5, a6, a7, a8;

    // Converting departure and arrival times to minutes
    t1 = 8 * 60;        // 8     am      
    t2 = 9 * 60 + 43;   // 9:43  am
    t3 = 11 * 60 + 19;  // 11:19 am
    t4 = 12 * 60 + 47;  // 12:47 pm
    t5 = 14 * 60;       // 2:00  pm
    t6 = 15 * 60 + 45;  // 3:45  pm
    t7 = 19 * 60;       // 7:00  pm
    t8 = 21 * 60 + 45;  // 9:45  pm

    a1 = 10 * 60 + 16;  // 10:16 am
    a2 = 11 * 60 + 52;  // 11:52 am
    a3 = 13 * 60 + 31;  // 1:31  pm
    a4 = 15 * 60;       // 3:00  pm
    a5 = 16 * 60 + 8;   // 4:08  pm
    a6 = 17 * 60 + 55;  // 5:55  pm
    a7 = 21 * 60 + 20;  // 9:20  pm
    a8 = 23 * 60 + 58;  // 11:58 pm

    if (desired_time <= t1 + (t2 - t1) / 2) {
        // printf("Closest departure time is 8:00 a.m., arriving at 10:16 a.m.\n");
        *departure_time = t1;
        *arrival_time = a1;
    } else if (desired_time < t2 + (t3 - t2) / 2) {
        // printf("Closest departure time is 9:43 a.m., arriving at 11:52 a.m.\n");
        *departure_time = t2;
        *arrival_time = a2;
    } else if (desired_time < t3 + (t4 - t3) / 2) {
        // printf("Closest departure time is 11:19 a.m., arriving at 1:31 p.m.\n");
        *departure_time = t3;
        *arrival_time = a3;
    } else if (desired_time < t4 + (t5 - t4) / 2) {
        // printf("Closest departure time is 12:47 p.m., arriving at 3:00 p.m.\n");
        *departure_time = t4;
        *arrival_time = a4;
    } else if (desired_time < t5 + (t6 - t5) / 2) {
        // printf("Closest departure time is 2:00 p.m., arriving at 4:08 p.m.\n");
        *departure_time = t5;
        *arrival_time = a5;
    } else if (desired_time < t6 + (t7 - t6) / 2) {
        // printf("Closest departure time is 3:45 p.m., arriving at 5:55 p.m.\n");
        *departure_time = t6;
        *arrival_time = a6;
    } else if (desired_time < t7 + (t8 - t7) / 2) {
        // printf("Closest departure time is 7:00 p.m., arriving at 9:20 p.m.\n");
        *departure_time = t7;
        *arrival_time = a7;
    } else {
        // printf("Closest departure time is 9:45 p.m., arriving at 11:58 p.m.\n");
        *departure_time = t8;
        *arrival_time = a8;
    }
}