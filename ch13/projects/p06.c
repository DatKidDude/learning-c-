#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#define NUM_PLANETS 9

bool is_str_equal(const char *s1, const char *s2);

int main(int argc, char *argv[]) {

    char *planets[] = {"Mercury", "Venus", "Earth",
                       "Mars", "Jupiter", "Saturn",
                       "Uranus", "Neptune", "Pluto"};
    int i, j;

    for (i = 1; i < argc; i++) {
        for (j = 0; j < NUM_PLANETS; j++)
            if (is_str_equal(argv[i], planets[j])) {
                printf("%s is planet %d\n", argv[i], j + 1);
                break;
            }
        if (j == NUM_PLANETS)
            printf("%s is not a planet\n", argv[i]);
    }
    return 0;
}

/*
* Function: is_str_equal
* ----------------------
* Returns True if both strings are equal else False
*/
bool is_str_equal(const char *s1, const char *s2) {
    
    while (toupper(*s1) == toupper(*s2)) {
        if (!*s1) { // if null character is read
            return true;
        }
        s1++;
        s2++;
    }

    return false;
}
