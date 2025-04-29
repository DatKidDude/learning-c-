/* Write a program that computes the volume of a sphere with a 10-meter
radius, using the formula v=4/3(pi)r^3. Write the fraction 4/3 as 4.0f/3.0f. (Try writing 4/3. What happens?) Hint: C doesn't have an exponentiantion operator, so you'll need to multiply r by itself twice to compute r^3.
*/

#include <stdio.h>

#define PI 3.14159265358979323846f

int main(void) {
    float radius = 10.0f;
    float r_cubed = radius * radius * radius;
    float volume = (4.0f / 3.0f) * PI * r_cubed;

    printf("Volume: %.4f", volume);

    return 0;
}