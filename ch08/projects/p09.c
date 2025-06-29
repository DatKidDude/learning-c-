/*
Write a program that generates a "random walk" across a 10 x 10 array. The array
will contain characters (all `'.'` initially). The program must randomly "walk"
from element to element, always going up, down, left or right by one element.
The elements visited by the program will be labeled with the letters `A` through
`Z`, in the order visited. Here's an example of the desired output:

```
A . . . . . . . . .
B C D . . . . . . .
. F E . . . . . . .
H G . . . . . . . .
I . . . . . . . . .
J . . . . . . . Z .
K . . R S T U V Y .
L M P Q . . . W X .
. N O . . . . . . .
. . . . . . . . . .
```

*Hint* Use the `srand` and `rand` functions (see `deal.c`) to generate random
numbers. After generating a number, look at its remainder when divided by 4.
There are four possible values for the remainder -- 0, 1, 2 and 3 -- indiciating
the direction of the next move. Before performing a move, check that (a) it
won't go outside the array, and (b) it doesn't take us to an element that
already has a letter assigned. If either condition is violated, try moving in
another direction. If all four directions are blocked, thr program must
terminate. Here's an example of premature termination:

```
A B G H I . . . . .
. C F . J K . . . .
. D E . M L . . . .
. . . . N O . . . .
. . W X Y P Q . . .
. . V U T S R . . .
. . . . . . . . . .
. . . . . . . . . .
. . . . . . . . . .
. . . . . . . . . .
```

`Y` is blocked on all four sides, so there's no place to put `Z`.

*/

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