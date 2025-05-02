/* Write a program that breaks down an ISBN entered by a user. 
Example ISBN: 978-0-393-97950-3
Self note: I'm assuming it's only ISBN 13 from the description.
*/

#include <stdio.h>

int main(void) {

    int prefix;
    int group;
    int publisher_code;
    int item_no;
    int check_digit;

    printf("Enter ISBN: ");
    scanf("%d-%d-%d-%d-%d", &prefix, &group, &publisher_code, &item_no, &check_digit);

    printf("GS1 prefix: %d\n", prefix);
    printf("Group Identifier: %d\n", group);
    printf("Publisher code: %d\n", publisher_code);
    printf("Item number: %d\n", item_no);
    printf("Check digit: %d\n", check_digit);

    return 0;
}