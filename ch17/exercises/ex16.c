/* Write the following function. The call sum(g, i, j) should return g(i)+...+g(j). 

    int sum(int (*f)(int), int start, int end);
*/

#include <stdio.h>

int sum(int (*f)(int), int start, int end);
int g(int n);

int main(void)
{
    int start = 1, end = 3;
    printf("%d\n", sum(g, start, end));

    return 0;
}

int sum(int (*f)(int), int start, int end)
{   
    int i, total = 0;

    for (i = start; i <= end; i++) {
        total += (*f)(i);
    }
    return total;
}

int g(int n)
{
    return n;
}