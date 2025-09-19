#ifndef WORD_H
#define WORD_H

/*
* read_word: Read the next word from the input and stores in
*            in word. Makes word empty if no word could be 
*            read because of end-of-file. Truncates the word 
*            if its length exceeds len. Returns the number of 
*            characters stored.
*/
int read_word(char *word, int len);

#endif