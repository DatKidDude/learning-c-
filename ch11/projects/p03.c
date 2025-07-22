/*
Modify Programming Project 3 from Chapter 6 so that it includes the following function:

    void reduce(int numerator, int denominator,
                int *reduced_numerator,
                int *reduced_denominator);

numerator and denominator are the numerator and denominator of a fraction. reduced_numerator and reduced_denominator are pointers to variables in which the function will store the numerator and denominator of the fraction once it has been reduced to lowest terms.
*/

/* Write a program that asks the user to enter a fraction, then reduces the fraction to lowest terms:

    Enter a fraction: 6/12
    In lowest terms: 1/2

Hint: To reduce a fraction to lowest terms, first compute the GCD of the numerator and denominator. Then divide both the numerator and denominator by the GCD.
*/

#include <stdio.h>

void reduce(int numerator, int denominator,
            int *reduced_numerator,
            int *reduced_denominator);

int main(void) {

    int num, den, reduced_numerator, reduced_denominator;

    printf("Enter a fraction: ");
    scanf("%d/%d", &num, &den);

    reduce(num, den, &reduced_numerator, &reduced_denominator);

    printf("In lowest terms: %d/%d", num/reduced_numerator, den/reduced_numerator);

    return 0;
}

void reduce(int numerator, int denominator, int *reduced_numerator, int *reduced_denominator) {
    
    int r;
    *reduced_numerator = numerator;
    *reduced_denominator = denominator;

    while (*reduced_denominator != 0) {
        r = *reduced_numerator % *reduced_denominator;
        *reduced_numerator = *reduced_denominator;
        *reduced_denominator = r;
    }

}