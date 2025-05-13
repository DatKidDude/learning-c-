/* A Beaufort scale, is used to estimate wind force. Write a program that asks the user to enter a wind speed (in knots) */

#include <stdio.h>

int main(void) {
    
    int speed;

    printf("Enter wind speed (in knots): ");
    scanf("%d", &speed);
    
    if (speed < 1) {
        printf("Calm");
    } else if (speed <= 3) {
        printf("Light air");
    } else if (speed <= 27) {
        printf("Breeze");
    } else if (speed <= 47) {
        printf("Gale"); 
    } else if (speed <= 63) {
        printf("Storm");
    } else {
        printf("Hurricane");
    }

    return 0;
}