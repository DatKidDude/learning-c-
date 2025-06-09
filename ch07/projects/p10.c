/* Write a program that counts the number of vowels (a, e, i, o, u) in a sentence:

    Enter a sentence: And that's the way it is. 
    Your sentence contains 6 vowels. 
*/

#include <stdio.h>
#include <ctype.h>

int main(void) {

    int count;
    char ch;

    printf("Enter a sentence: ");

    while ((ch = getchar()) != '\n') {
        switch (toupper(ch)) {
            case 'A':
                count++;
                break;
            case 'E':
                count++;
                break;
            case 'I':
                count++;
                break;
            case 'O':
                count++;
                break;
            case 'U':
                count++;
                break;
            default:
                break;
                return 1;
        }
    }

    printf("Your sentence contains %d vowels.", count);

    return 0;
}