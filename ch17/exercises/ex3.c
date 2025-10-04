/*
Write the following function:
    
    int *create_array(int n, int initial_value);

The function should return a pointer to a dynamically allocated int array with n members, each of which is initialized to initial_value. The return value should be NULL if the array can't be allocated.
*/

#include <stdio.h>
#include <stdlib.h>

int *create_array(int n, int initial_value);

int main(void)
{
    int size = 5, value = 1, *array, *p;

    array = create_array(size, value);

    if (array == NULL) {
        printf("Error: *create_array failed.\n");
        return EXIT_FAILURE;
    }

    for (p = array; p < array + size; p++) {
        printf("%d\n", *p);
    }
    printf("\n");

    return 0;
}

int *create_array(int n, int initial_value)
{
    int *pArray = (int *) malloc(n * sizeof(int)),
    *p;

    if (pArray == NULL) {
        return NULL;
    }

    for (p = pArray; p < pArray + n; p++) {
        *p = initial_value;
    }

    return pArray;
}