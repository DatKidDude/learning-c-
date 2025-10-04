/*
Write a function named duplicate that uses dynamic storage allocation to create a copy of a string. For example, the call

    p = duplicate(str);

would allocate space for a string of the same length as str. copy the contents of str into the new string, and return a pointer to it. Have duplicate return a null pointer if the memory allocation fails.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *duplicate(const char *str);

int main(void)
{   
    char *str = "copy";
    char *dupe;

    dupe = duplicate(str);

    if (dupe == NULL) {
        printf("Error: Duplicate failed.\n");
        return EXIT_FAILURE;
    }

    printf("Original string: %s\n", str);
    printf("Duplicated string: %s\n", dupe);

    free(dupe);
    dupe = NULL;

    if (dupe == NULL) {
        printf("Pointer is NULL\n");
    } else {
        printf("Pointer is not NULL\n");
    }

    return 0;
}

char *duplicate(const char *str)
{
    char *str2;

    str2 = (char *) malloc(strlen(str) + 1);
    if (str2 == NULL) {
        return NULL;
    }
    strcpy(str2, str);
    return str2;
}