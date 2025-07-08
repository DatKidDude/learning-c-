/*
Modify Programming Project 17 from Chapter 8 so that it includes the following
functions:

    void create_magic_square(int n, char magic_square[n][n]);
    void print_magic_square(int n, char magic_square[n][n]);


After obtaining the number *n* from the user, `main` will call
`create_magic_square`, passing it an *n* x *n* array that is declared inside
`main`. `create_magic_square` will fill the array with the numbers 1, 2, ...,
*n*² as described in the original project. `main` will then call
`print_magic_square`, which will display the array in the format described in
the oroginal project. *Note*: If your compiler doesn't support variable-length
arrays, declare the array in `main` to be 99 x 99 instead of *n* x *n* and use
the following prototypes instead:

    void create_magic_square(int n, char magic_square[99][99]);
    void print_magic_square(int n, char magic_square[99][99]);
 
*/

#include <stdio.h>

void create_magic_square(int n, char magic_square[n][n]);
void print_magic_square(int n, char magic_square[n][n]);

int main(void) {

    int size;

    printf("This program creates a magic square of a specified size.\nThe size must be an odd number between 1 and 99.\nEnter size of magic square: ");
    scanf("%d", &size);

    char magic_square[size][size] = {};

    create_magic_square(size, magic_square);
    print_magic_square(size, magic_square);

    return 0;
}


void create_magic_square(int n, char magic_square[n][n]) {

    int row = 0, col = 0;

    // put number 1 in the middle of row 0
    col = n / 2;
    magic_square[0][col] = 1;

    for (int i = 2; i <= n * n; i++) {

        if (magic_square[((row - 1) + n) % n][(col + 1) % n]) {
            row = row + 1;
            magic_square[row][col] = i;
        } else {
            row = ((row - 1) + n) % n;
            col = (col + 1) % n; 
            magic_square[row][col] = i;
        }
        
    }
}

void print_magic_square(int n, char magic_square[n][n]) {

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            printf("%2d ", magic_square[row][col]);
        }
        printf("\n");
    }
}