/* Write a program that calculates the average word length for a sentence:

    Enter a sentence: It was deja vu all over again.asm
    Average word length: 3.4

For simplicity, your program should consider a punctuation mark to be part of the word to which it is attached. Display the average word length to one decimal place. 
*/

#include <stdio.h>

int main(void) {

    int words, letters;
    char ch;

    printf("Enter a sentence: ");

    while ((ch = getchar()) != '\n') {
        if (ch == ' ') {
            words++;
            continue;
        } else if (ch == '.') {
            words++;
            letters++;
        } else {
            letters++;
        }
    }

    printf("Average word length: %.1f\n", (float) letters / words);
    printf("Words: %d\nLetters: %d", words, letters);

    return 0;
}