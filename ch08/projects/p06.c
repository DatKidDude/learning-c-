/* The prototypical Internet newbie is a fellow B1FF, who has a unique way of writing messages. Here's a typical B1FF communique:

    H3Y DUD3, C 15 R1LLY C00L!!!!!!!!!!

Write a "B1FF filter" that reads a message entered by the user and transaltes it into B1FF speak: 

    Enter message: Hey dude, C is rilly cool
    In B1FF-speak: H3Y DUD3, C 15 R1LLY C00L!!!!!!!!!!

Your program should convert the message to upper-case letter, substitute digits for certain letter (A->4, B->8, E->3, I->1, O->0, S->5), and then append 10 or so exclamation marks: 
Hint: Store the original message in an array of characters, then go back through the array, translating and printing characters one by one. 
*/

#include <stdio.h>
#include <ctype.h>

#define N 100

int main(void) {

    int count = 0;
    char c, letters[N] = {0};

    printf("Enter message: ");
    while ((c = getchar()) != '\n') {
        letters[count] = toupper(c);
        count++;
    }

    printf("In B1ff speak: ");
    for (int i = 0; i < count; i++) {
        switch (letters[i]) {
            case 'A':
                printf("4");
                break;
            case 'B':
                printf("8");
                break;
            case 'E':
                printf("3");
                break;
            case 'I':
                printf("1");
                break;
            case 'O':
                printf("0");
                break;
            case 'S':
                printf("5");
                break;
            default:
                printf("%c", letters[i]);
                break;
        }
    }

    printf("!!!!!!!!!!\n");

    return 0;
    
}
