/* Write a program that prompts the user to enter a telephone number in the form (xxx) xxx-xxxx and then displays the number in the form xxx.xxx.xxxx*/

#include <stdio.h>

int main(void) {

    int area_code;
    int prefix;
    int line_no;
    
    printf("Enter phone number [(xxx) xxx-xxxx]: ");
    scanf("(%d) %d-%d", &area_code, &prefix, &line_no);
    
    printf("You entered %.3d.%.3d.%.4d", area_code, prefix, line_no);

    return 0;
}