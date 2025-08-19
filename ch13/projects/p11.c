/*
Modify Programming Project 13 from Chapter 7 so that it includes the following function: 

    double compute_average_word_length(const char *sentence);

The function returns the average length of the words in the string pointed to by sentence.
*/

#include <stdio.h>
#include <string.h>

#define LEN 100

double compute_average_word_length(const char *sentence);

int main(void) {

    char sentence[LEN + 1];
    double average = 0.0;

    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    average = compute_average_word_length(sentence);

    printf("Average word length: %.1lf\n", average);

    return 0;
}

double compute_average_word_length(const char *sentence) {

    int words = 0, 
        letters = 0;
    
    while (*sentence != '\n') {
        sentence++;
        if (*sentence == ' ') {
            words++;
            continue;
        } else if (*sentence == '.') {
            words++;
            letters++;
        } else {
            letters++;
        }
    }

    return (double) letters / words;
}