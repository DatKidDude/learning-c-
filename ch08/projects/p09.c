#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

int main(void) {

    int direction, v = 0, h = 0, terminate = 0;
    char grid[N][N] = {'.'};
    int visited[4] = {0};
    // 65-90

    srand((unsigned) time(NULL));

    // initialize grid to all '.' chars
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            grid[i][j] = '.';
        }
    }

    grid[0][0] = 'A';

    // iterate through B-Z chars
    for (int i = 66; i <= 90; i++) {

        // reset the visited array
        for (int pos = 0; pos < 4; pos++) {
            visited[pos] = 0;
        }

        while (!terminate) {
            direction = rand() % 4;

            if (visited[0] && visited[1] && visited[2] && visited[3]) {
                terminate = 1;
                break;
            }

            // move up
            if (direction == 0 && !visited[0]) {
                if (v > 0 && grid[v - 1][h] == '.') {
                    v -= 1;
                    grid[v][h] = i;
                    break;
                } else {
                    visited[0] = 1;
                }
                // move down
            } else if (direction == 1 && !visited[1]) {
                if (v < N && grid[v + 1][h] == '.') {
                    v += 1;
                    grid[v][h] = i;
                    break;
                } else {
                    visited[1] = 1;
                }
                // move left 
            } else if (direction == 2 && !visited[2]) {
                if (h > 0 && grid[v][h - 1] == '.') {
                    h -= 1;
                    grid[v][h] = i;
                    break;
                } else {
                    visited[2] = 1;
                }
                // move right
            } else if (direction == 3 && !visited[3]) {
                if (h < N && grid[v][h + 1] == '.') {
                    h += 1;
                    grid[v][h] = i;
                    break;
                } else {
                    visited[3] = 1;
                }
            }
        }

        if (terminate) {
            printf("Character %c blocked", i);
            break;
        }

    }

    if (!terminate) {
        // display the grid
        for (int row = 0; row < N; row++) {
            for (int col = 0; col < N; col++) {
                printf("%c", grid[row][col]);
            }
            printf("\n");
        }

    }
    
    
    return 0;
}