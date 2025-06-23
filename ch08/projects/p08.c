/* Modify Programming Project 7 so that it prompts for five quiz grades for each of five student, then computes the total score and average score for each student, and the average scor, high score, and low score for each quiz.*/

#include <stdio.h>

#define N 5

int main(void) {

    int grades[N][N], row, col, total_score, high_score, low_score;

    // Get the quiz grades for each student
    for (row = 0; row < N; row++) {
        printf("Enter student %d's quiz grades: ", row + 1);
        for (col = 0; col < N; col++) {
            scanf("%d", &grades[row][col]);
        }
    }

    // Calculate total and avg score of each student
    for (row = 0; row < N; row++) {
        printf("\nTotal and average scores for student %d: ", row + 1);
        total_score = 0;
        for (col = 0; col < N; col++) {
            total_score += grades[row][col];
        }
        printf("%d %.1f", total_score, (float) total_score / N);
    }

    printf("\n");

    // Calculate total, high and low score for each quiz
    for (row = 0; row < N; row++) {
        printf("\nAverage, high, and low score for quiz %d: ", row + 1);
        total_score = 0;
        high_score = low_score = grades[0][row];
        for (col = 0; col < N; col++) {
            if (grades[col][row] > high_score ) {
                high_score = grades[col][row];
            }

            if (grades[col][row] < low_score) {
                low_score = grades[col][row];
            }

            total_score += grades[col][row];
        }
        printf("%.1f %d %d", (float) total_score / N, high_score, low_score);
    }

    return 0;
}