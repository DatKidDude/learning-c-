/*
Modify Programming Project 14 from Chapter 8 so that it stores the words in a two-dimensional char array as it reads the sentence, with each row of the array storing a single word. Assume that the sentence contains no more than 30 words and no word is more than 20 characters long. Be sure to store a null character at the end of each word so that it can be treated as a string.
*/

#include <stdio.h>
#include <string.h>

#define WORD_LEN 20
#define SENT_LEN 30

int main(void) {

    char sentence[SENT_LEN][WORD_LEN + 1],
         ch,
         terminator;
    int word_count = 0,
        letter_count = 0;

    printf("Enter a sentence: ");
    while ((ch = getchar()) != '\n' && word_count < SENT_LEN) {
        if (ch == '?' || ch == '.' || ch == '!') {
            terminator = ch;
            sentence[word_count][letter_count] = '\0';
            word_count++;
            break;
        }

        if (ch == ' ') {
            sentence[word_count][letter_count] = '\0';
            word_count++;
            letter_count = 0;
            continue;
        }

        sentence[word_count][letter_count++] = ch;

    }

    printf("Reversal of sentence\n");
    while (word_count > 0) {
        printf("%s ", sentence[word_count--]);
    }
    printf("%s%c", sentence[word_count], terminator);

    return 0;
}