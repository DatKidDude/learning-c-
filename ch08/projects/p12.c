/* Modify Programming Project 5 from Chapter 7 so that the SCRABBLE values of the letters are stored in an array. The array will have 26 elements, corresponding to the 26 letters of the alphabet. For example, element 0 of the array will store 1 (because the SCRABBLE value of the letter A is 1), element 1 of the array will store 3 (because the SCRABBLE value of the letter B is 3), and so forth. As each character of the input word is read, the program will use the array to determine the SCRABBLE value of that character. Use an array initializer to set up the array.*/

#include <stdio.h>
#include <ctype.h>

int main(void) {

    char ch;
    int score = 0;
    int points[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

    printf("Enter a word: ");
    while ((ch = getchar()) != '\n') {
        score = score + points[toupper(ch) - 'A'];
    }
    
    printf("Scrabble value: %d", score);

    return 0;
}