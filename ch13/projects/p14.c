/*
Modify Programming Project 16 from Chapter 8 so that it includes the following function:

    bool are_anagrams(const char *word1, const char *word2);

The function returns true if the strings pointed to by word1 and word2 are anagrams.
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define LEN 20
#define LETTERS 26

bool are_anagrams(const char *word1, const char *word2);
void read_word(char *word);

int main(void) {

    char word1[LEN + 1],
         word2[LEN + 1];
    
    printf("Enter first word: ");
    read_word(word1);

    printf("Enter second word: ");
    read_word(word2);

    if (!are_anagrams(word1, word2)) {
        printf("The words are not anagrams.\n");
        return 0;
    }

    printf("The words are anagrams.\n");

    return 0;
}

void read_word(char *word) {
    char ch, *p;

    while ((ch = getchar()) != '\n' && p < word + LEN) {
        if (isalpha(ch)) {
            *word++ = ch;
        }
    }

    *word = '\0';
}

bool are_anagrams(const char *word1, const char *word2) {

    int letters[LETTERS] = {0},
        i;

    while (*word1) {
        letters[tolower(*word1) - 'a']++;
        word1++;
    }

    while (*word2) {
        letters[tolower(*word2) - 'a']--;
        word2++;
    }

    for (i = 0; i < LETTERS; i++) {
        if (letters[i] > 0) {
            return false;
        }
    }

    return true;
}