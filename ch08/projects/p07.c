/* Write a program that reads a 5 x 5 array of integers and then prints the row sums and the column sums:

    Enter row 1: 8 3 9 0 10
    Enter row 2: 3 5 17 1 1
    Enter row 3: 2 8 6 23 1
    Enter row 4: 15 7 3 2 9
    Enter row 5: 6 14 2 6 0

    Row totals: 30 27 40 36 28
    Column totals: 34 37 37 32 21
*/

#include <stdio.h>

#define N 5

int main(void) {

    int matrix[N][N], row, col, row_total = 0, col_total = 0;

    for (row = 0; row < N; row++) {
        printf("Enter row %d: ", row + 1);
        for (col = 0; col < N; col++) {
            scanf("%d", &matrix[row][col]);
        }
    }

    // Row totals
    printf("\nRow totals: ");
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            row_total += matrix[row][col];
        }
        printf("%d ", row_total);
        row_total = 0;
    }

    // Column totals 
    printf("\nColumn totals: ");
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            col_total += matrix[col][row];
        }
        printf("%d ", col_total);
        col_total = 0;
    }

    return 0;
}