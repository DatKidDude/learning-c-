/* Modify the interest.c program of Section 8.1 so that it compounds interest monthly instead of annually. The form of the output shouldn't change: the balance should still be shown at annual intervals.*/

#include <stdio.h>

#define NUM_RATES ((int) (sizeof(value) / sizeof(value[0])))
#define INITIAL_BALANCE 100.00

int main(void) {

    int i, low_rate, num_years, year, month;
    double value[5], interest;

    printf("Enter interest rate: ");
    scanf("%d", &low_rate);
    printf("Enter number of years: ");
    scanf("%d", &num_years);

    printf("\nYears");
    for (i = 0; i < NUM_RATES; i++) {
        printf("%6d%%", low_rate + i);
        value[i] = INITIAL_BALANCE;
    }
    printf("\n");

    for (year = 1; year <= num_years; year++) {
        printf("%3d    ", year);
        for (i = 0; i < NUM_RATES; i++) {
            interest = (low_rate + i) / 100.0 / 12.0;
            for (int j = 0; j < 12; j++) {
                value[i] += (value[i] * interest);
            }
            printf("%7.2f", value[i]);
        }
        printf("\n");
    }

    return 0;
}
