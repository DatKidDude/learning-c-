/* Write a program that find the largest and smallest of four integers entered by the user. Use as few if statements as possible. Hint: Four if statements are sufficient. */

#include <stdio.h>

int main(void) {
    // 21 43 10 35
    int n1, n2, n3, n4, smallest1, largest1, smallest2, largest2;

    printf("Enter four integers: ");
    scanf("%d %d %d %d", &n1, &n2, &n3, &n4);

    if (n1 <= n2) {
        smallest1 = n1;
        largest1 = n2;
    } else {
        smallest1 = n2;
        largest1 = n1;
    }
    
    if (n3 <= n4) {
        smallest2 = n3;
        largest2 = n4;
    } else {
        smallest2 = n4;
        largest2 = n3;
    }

    if (largest1 > largest2) {
        printf("Largest: %d\n", largest1);
    } else {
        printf("Largest: %d\n", largest2);
    }

    if (smallest1 < smallest2) {
        printf("Smallest: %d\n", smallest1);
    } else {
        printf("Smallest: %d\n", smallest2);
    }
    
    return 0;
}