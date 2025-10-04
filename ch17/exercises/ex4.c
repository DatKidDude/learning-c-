/*
Supposed that the following declarations are in effect:

    struct point { int x, y; };
    struct rectangle { struct point upper_left, lower_right; };
    struct rectangle *p;

Assume that we want p to point to a rectangle structure whose upper left corner is at (10,25) and whose lower right corner is at (20,15). Write a series of statements that allocate such a structure and initialize it as indicated.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{

    struct point { int x, y; };
    struct rectangle { struct point upper_left, lower_right; };
    struct rectangle *p;

    p = (struct rectangle *) malloc(sizeof(struct rectangle));
    if (p == NULL) {
        printf("Error: Malloc failed.\n");
        return EXIT_FAILURE;
    }

    p->upper_left.x = 10;
    p->upper_left.y = 25;

    p->lower_right.x = 20;
    p->lower_right.y = 15;

    /* Alternate solution */
    // p->upper_left = (struct point) {10, 25};
    // p->lower_right = (struct point) {20, 15};

    printf("Rectangle upper left: (%d, %d)\nRectangle upper right: (%d, %d)\n",
        p->upper_left.x, p->upper_left.y,
        p->lower_right.x, p->lower_right.y);

    return 0;
}