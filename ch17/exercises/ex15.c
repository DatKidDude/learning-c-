/* Show the output of the following program and explain what it does.

Solution
--------
Output: 3
f1 is a function that contains a pointer to function f2. f1 calls f2
while incrementing n by 1. When n becomes 3, f2 calculates 
3 * 3 + 3 - 12 and returns 0. The while loop becomes false and f1 returns 3. 
*/

#include <stdio.h>

int f1(int (*f)(int));
int f2(int i);

int main(void)
{
    printf("Answer: %d\n", f1(f2));
    return 0;
}

int f1(int (*f)(int)) 
{
    int n = 0;

    while ((*f)(n)) n++;
    return n;
}

int f2(int i)   
{
    return i * i + i - 12;
}