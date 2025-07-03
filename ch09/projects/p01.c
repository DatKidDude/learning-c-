/* Write a program that asks the user to enter a series of integers (which it stores in an array), then sorts the integers by calling the function selection_sort. When given an array with n elements, selection_sort must do the following:

1. Search the array to find the largest element, then move it to the last position in the array. 
2. Call itself recursively to sort the first n - 1 elements of the array.
*/

#include <stdio.h>

void selection_sort(int n, int a[n]);

int main(void) {

    int i, n;

    printf("Enter the amount of numbers to be sorted: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter numbers to be sorted: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    selection_sort(n, a);

    printf("In sorted order: ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}

void selection_sort(int n, int a[n]) {
    
    if (n == 0) return;

    int i, temp, largest = 0;

    for (i = 0; i < n; i++) {
        if (a[i] > a[largest]) {
            largest = i;
        }
    }

    temp = a[largest];   
    a[largest] = a[n - 1];
    a[n - 1] = temp;

    selection_sort(n - 1, a);
}
