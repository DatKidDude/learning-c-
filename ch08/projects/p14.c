/* Write a program that reverses the words in a sentence: 

    Enter a sentence: you can cage a swallow can't you?
    Reversal of sentence: you can't swallow a cage can you? 

Hint: Use a loop to read the characters one by one and store them in a one-dimensional char array. Have the loop stop at a period, question mark, or exclamation point (the "terminating character"), which is saved in a separate char variable. Then use a second loop to search backward through the array for the beginning of the last word. Print the last word, then search backward for the next-to-last word. Repeat until the beginning of the array is reached. Finally, print the terminating character.
*/

#include <stdio.h>

#define SIZE 100

int main(void) {

    int count = 0, pos = 0;
    char ch, terminating_char;
    char sentence[SIZE] = {0};

    printf("Enter a sentence: ");

    for (int i = 0; i < SIZE; i++) {
        ch = getchar();
        if (ch == '?' || ch == '.' || ch == '!') {
            terminating_char = ch;
            break;
        } else {
            sentence[i] = ch;
            count++;
        }
    }

    pos = count;
    printf("Reversal of sentence: ");
    for (int i = count; i > -2; i--) {
        if (sentence[i] == ' ') {
            for (int j = i; j < pos; j++) {
                printf("%c", sentence[j]);
            }
            pos = i;
        } else if (i == -1) {
            printf(" ");
            for (int j = 0; j < pos; j++) {
                printf("%c", sentence[j]);
            }
        }
    }


    printf("%c", terminating_char);

    return 0;
}