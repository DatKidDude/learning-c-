/*
Modify Programming Project 5 from Chapter 7 so that it includes the following function:

    int compute_scrabble_value(const char *word);

The function returns the SCRABBLE value of the string pointed to by word.
*/

#include <stdio.h>
#include <ctype.h>

#define LEN 100

int points[26] = {
    // A  B  C  D  E  F  G  H  I  J  K  L  M
       1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3,
    // N  O  P  Q   R  S  T  U  V  W  X  Y  Z
       1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10
};

int compute_scrabble_value(const char *word);

int main(void) {

    char word[LEN + 1];
    int score = 0;

    printf("Enter a word: ");
    scanf("%100s", word);

    score = compute_scrabble_value(word);
    
    printf("Scrabble value: %d\n", score);

    return 0;
}

int compute_scrabble_value(const char *word) {

    int score = 0;

    while(*word) {
        score += points[toupper(*word++) - 'A'];
    }

    return score;
}