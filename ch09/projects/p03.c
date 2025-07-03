/* Modify Programming Project 9 from Chapter 8 so that it includes the following functions:

void generate_random_walk(char walk[10][10]);
void print_array(char walk[10][10]);

main first calls generate_random_walk, which initializes the array to contain '.' characters and then replaces some of these characters by the letters A through Z, as described in the original project. main then calls print_array to display the array on the screen.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

void generate_random_walk(char walk[N][N]);
void print_array(char walk[N][N]);

int main(void) {

    char walk[N][N];

    generate_random_walk(walk);

    print_array(walk);

    return 0;
}

void generate_random_walk(char walk[N][N]) {
    
    char letter = 'A';
    int row = 0,
        col = 0,
        up = 0,
        down = 0,
        left = 0,
        right = 0,
        move = 0;

    srand((unsigned) time(NULL));

    // Set the array to all '.'
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            walk[row][col] = '.';
        }
    }

    row = col = 0;
    walk[row][col] = letter++;

    while (letter <= 'Z') {
        up = down = left = right = 0;

        if (row - 1 >= 0 && walk[row - 1][col] == '.') {
            up = 1;
        }
        if (row + 1 < N && walk[row + 1][col] == '.') {
            down = 1;
        }
        if (col + 1 < N && walk[row][col + 1] == '.') {
            right = 1;
        }
        if (col - 1 >= 0 && walk[row][col - 1] == '.') {
            left = 1;
        }

        if (up + down + right + left == 0) {
            break;
        }

        move = rand() % 4;

        switch(move) {
            case 0:
                if (up) {
                    walk[--row][col] = letter++;
                    break;
                }
            case 1: 
                if (down) {
                    walk[++row][col] = letter++;
                    break;
                }
            case 2:
                if (right) {
                    walk[row][++col] = letter++;
                    break;
                }
            case 3: 
                if (left) {
                    walk[row][--col] = letter++;
                    break;
                }
            default:
                break;
        }
    }

}

void print_array(char walk[N][N]) {
    int row, col;

    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            printf("%c", walk[row][col]);
        }
        printf("\n");
    }
}