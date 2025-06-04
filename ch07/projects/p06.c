/* Write a program that prints the values of sizeof(int), sizeof(short), sizeof(long), sizeof(float), sizeof(double), and sizeof(long double).*/

#include <stdio.h>

int main(void) {

    // C89
    printf("C89\n");
    printf("int: %lu\n", (unsigned long) sizeof(int));
    printf("short: %lu\n", (unsigned long) sizeof(short));
    printf("long: %lu\n", (unsigned long) sizeof(long));
    printf("float: %lu\n", (unsigned long) sizeof(float));
    printf("double: %lu\n", (unsigned long) sizeof(double));
    printf("long double: %lu\n\n", (unsigned long) sizeof(long double));

    // C99
    printf("C99\n");
    printf("int: %zu\n",  sizeof(int));
    printf("short: %zu\n",  sizeof(short));
    printf("long: %zu\n",  sizeof(long));
    printf("float: %zu\n",  sizeof(float));
    printf("double: %zu\n",  sizeof(double));
    printf("long double: %zu\n",  sizeof(long double));

    return 0;
}