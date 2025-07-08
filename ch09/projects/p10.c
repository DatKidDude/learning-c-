#include <stdbool.h> /* C99 only */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int roll_dice(void);
bool play_game(void);

int main(void) {

    int wins = 0, losses = 0;
    bool won;
    char response;

    srand((unsigned) time(NULL));

    printf("***** Craps Dice Game *****\n");

    while (1) {
        
        won = play_game();

        if (won) {
            wins++;
        } else {
            losses++;
        }

        printf("Play again? ");
        scanf(" %c", &response);

        if (tolower(response) == 'y') {
            continue;
        } else {
            break;
        }
    }

    printf("Wins: %d Losses: %d", wins, losses);

    return 0;
}

bool play_game(void) {
    int dice = roll_dice();
    int point;

    if (dice == 7 || dice == 11) {
        printf("You win!\n");
        return true;
    } 
    if (dice == 2 || dice == 3 || dice == 12) {
        printf("You lose!\n");
        return false;
    } 

    printf("Your point is %d\n", point = dice);

    while (dice = roll_dice()) {
        
        if (dice == point) {
            printf("You win!\n");
            return true;
        }

        if (dice == 7) {
            printf("You lose\n");
            return false;
        }
    }


}

int roll_dice(void) {

    int dice1, dice2;

    dice1 = (rand() % 6) + 1;
    dice2 = (rand() % 6) + 1;

    printf("You rolled: %d\n", dice1 + dice2);

    return dice1 + dice2;
}