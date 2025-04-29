/* Modify the program of Programming Project 2 so that it prompts the user to enter the radius of the sphere */

#include <stdio.h>

#define PI 3.14159265358979323846f

int main(void) {
    float radius;
    printf("Enter the radius: ");
    scanf("%f", &radius);
    float r_cubed = radius * radius * radius;
    float volume = (4.0f / 3.0f) * PI * r_cubed;

    printf("Volume: %.4f", volume);

    return 0;
}