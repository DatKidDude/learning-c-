/* Write a program that translates an alphabetic phone number into numeric form: 

    Enter phone number: CALLATT
    2255288

(In case you don't havea a telephone nearby, here are the letters on the keys: 2=ABC, 3=DEF, 4=GHI, 5=JKL, 6=MNO, 7=PRS, 8=TUV, 9=WXY). If the original phone number contains nonalphabetic characters (digits or punctuation, for example), leave them unchanged: 

    Enter phone number: 1-800-COL-LECT
    1-800-265-5328

You may assume that any letters entered by the user are upper case.
*/

#include <stdio.h>

int main(void) {

    char ch;

    printf("Enter phone number: ");
    while ((ch = getchar()) != '\n') {
        switch (ch) {
            case 65: case 66: case 67:
                printf("%d", 2);
                break;
            case 68: case 69: case 70:
                printf("%d", 3);
                break;
            case 71: case 72: case 73:
                printf("%d", 4);
                break;
            case 74: case 75: case 76:
                printf("%d", 5);
                break;
            case 77: case 78: case 79:
                printf("%d", 6);
                break;
            case 80: case 82: case 83:
                printf("%d", 7);
                break;
            case 84: case 85: case 86:
                printf("%d", 8);
                break;
            case 87: case 88: case 89:
                printf("%d", 8);
                break;
            default:
                printf("%c", ch);
                break;
        }
    }

    return 0;
}