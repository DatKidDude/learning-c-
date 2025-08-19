/*
Modify Programming Project 10 from Chapter 7 so that it includes the following function: 

    int compute_vowel_count(const char *sentence);

The function returns the number of vowels in the string pointed to by the sentence parameter.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define LEN 100

char vowels[5] = {'A', 'E', 'I', 'O', 'U'};

int compute_vowel_count(const char *sentence);

int main(void) {
    
    char sentence[LEN + 1];
    int count;

    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);;

    printf("Your sentence contains %d vowels.", compute_vowel_count(sentence));

    return 0;
}

int compute_vowel_count(const char *sentence) {

    int count = 0;
    while (*sentence) {
        switch(toupper(*sentence)) {
            case 'A': case 'E': case 'I': case 'O': case 'U':
                count++;
                break;
            default:
                break;
        }
        sentence++;
    }

    return count;
}