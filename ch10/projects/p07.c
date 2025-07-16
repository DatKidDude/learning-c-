/*
### Project 10.07
Write a program that prompts the user for a number and then displays the number,
using characters to simulate the effect of a seven-segment display:

```
Enter a number: 491-9014
      _       _   _
|_|  |_|   | |_| | |   | |_|
  |   _|   |  _| |_|   |   |
```

Characters other than digits should be ignored. Write the program so that the
maximum number of digits is controlled by a macro named `MAX_DIGITS`, which has
the value 10. If the number contains more than this number of digits, the extra
digits are ignored. *Hints*: Use two external arrays. One is the `segments`
array (see Exercise 6 in Chapter 8), which stores data representing the
correspondence between digits and segments. The other array, `digits` will be an
array of characters with 4 rows (since each segmented digit is four characters
high) hand `MAX_DIGITS * 4` columns (digits are three characters wide, but a
space is needed between digits for readability). Write your program as four
functions: `main`, `clear_digits_array`, `process_digit`, and
`print_digits_array`. Here are the prototypes for the latter three functions:

```c
void clear_digits_array(void);
void process_digit(int digit, int position);
void print_digits_array(void);
```

`clear_digits_array` will store blank characters into all elements of the
`digits` array, `process_digit` will store the seven-segment representation of
`digit` into a specified position in the `digits` array (positions range from 0
to `MAX_DIGITS - 1`). `print_digits_array` will display the rows of the `digits`
array, each on a single line, producing output such as that shown in the
exmaple.

### Solution
See `7.c`.
*/

#include <stdio.h>
#include <ctype.h>

#define MAX_DIGITS 10

/* external variables */

/*
 *
 *    _0_
 * 5 |   | 1
 *   |_6_|
 * 4 |   | 2
 *   |_3_|
 */
const int segments[10][7] = {{1, 1, 1, 1, 1, 1, 0},
                             {0, 1, 1, 0, 0, 0, 0},
                             {1, 1, 0, 1, 1, 0, 1},
                             {1, 1, 1, 1, 0, 0, 1},
                             {0, 1, 1, 0, 0, 1, 1},
                             {1, 0, 1, 1, 0, 1, 1},
                             {1, 0, 1, 1, 1, 1, 1},
                             {1, 1, 1, 0, 0, 0, 0},
                             {1, 1, 1, 1, 1, 1, 1},
                             {1, 1, 1, 1, 0, 1, 1}};
char digits[4][MAX_DIGITS * 4];

/* {{0,_,0,0,0,-,0,0,0,0,0,0,0,0,0,0,0,0,0,0
     |,0,|,0,0,_,|,0,0,0,0,0,0,0,0,0,0,0,0,0
     |,_,|,0,|,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
     0,0,0,0,0,-,0,0,0,0,0,0,0,0,0,0,0,0,0,0}}

*/

void clear_digits_array(void);
void process_digit(int digit, int position);
void print_digits_array(void);

int main(void) {

    char ch;

    clear_digits_array();

    printf("Enter a number: ");
    for (int pos = 0; (ch = getchar()) != '\n' && pos < MAX_DIGITS * 4; pos += 4) {
        if (isdigit(ch)) {
            process_digit((ch - '0'), pos);
        } else {
            pos -= 4;
            continue;
        }
    } 

    print_digits_array();

    return 0;
}

/*
* Function: clear_digits_array
* ----------------------------
* stores blank characters into all elements of the digits array
*/

void clear_digits_array(void) {
    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < MAX_DIGITS * 4; col++) {
            digits[row][col] = ' ';
        }
    }
}

/*
* Function: process_digit
* ----------------------------
* stores the seven-segment representation of digit into a specified
* position in the digits array (positions range from 0 to MAX_DIGITS - 1)
*/
void process_digit(int digit, int position) {

    for (int idx = 0; idx < 7; idx++) {
        if (segments[digit][idx]) {
            switch (idx) {
                case 0:
                    digits[0][position + 1] = '_';
                    break;
                case 1:
                    digits[1][position + 2] = '|';
                    break;
                case 2:
                    digits[2][position + 2] = '|';
                    break;
                case 3:
                    digits[2][position + 1] = '_';
                    break;
                case 4:
                    digits[2][position] = '|';
                    break;
                case 5:
                    digits[1][position] = '|';
                    break;
                case 6:
                    digits[1][position + 1] = '_';
                    break;
                default:
                    printf("Default");
                    break;
            }
            
        }
        
    }
}

/*
* Function: print_digits_array 
* ----------------------------
* prints the 7-segments representation of the digits
*/
void print_digits_array(void) {
    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < MAX_DIGITS * 4; col++) {
            printf("%c", digits[row][col]);
        }
        printf("\n");
    }
}