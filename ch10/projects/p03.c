/*
Remove the num_in_rank, num_in_suit, and card_exists arays from the poker.c program of Section 10.5. Have the program store the cards in a 5x2 array instead. Each row of the array will represent a card. For example, if the array is named hand, then hand[0][0] will store the rank of the first card and hand[0][1] will store the suit of the first card.
*/

#include <stdbool.h>   /* C99 only */
#include <stdio.h>
#include <stdlib.h>

#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS 5

/* external variables */
int hand[5][2];
bool straight, flush, four, three;
int pairs;   /* can be 0, 1, or 2 */

/* prototypes */
void read_cards(void);
void analyze_hand(void);
void print_result(void);
void sort_hand(int hand[5][2]); 

/**********************************************************
 * main: Calls read_cards, analyze_hand, and print_result *
 *       repeatedly.                                      *
 **********************************************************/
int main(void) {
    for (;;) {
        read_cards();
        analyze_hand();
        print_result();
    }

    return 0;
}

/**********************************************************
 * read_cards: Reads the cards into the external          *
 *             variables num_in_rank and num_in_suit;     *
 *             checks for bad cards and duplicate cards.  *
 **********************************************************/
void read_cards() {
    char ch, rank_ch, suit_ch;
    int rank, suit;
    bool bad_card, rank_exists, suit_exists;
    int cards_read = 0;

    // set all values in hand to -1
    for (int row = 0; row < 5; row++) {
        for (int col = 0; col < 2; col++) {
            hand[row][col] = -1;
        }
    }

    while (cards_read < NUM_CARDS) {
        bad_card = false;

        printf("Enter a card: ");

        rank_ch = getchar();
        switch(rank_ch) {
            case '0':           exit(EXIT_SUCCESS);
            case '2':           rank = 0; break;
            case '3':           rank = 1; break;
            case '4':           rank = 2; break;
            case '5':           rank = 3; break;
            case '6':           rank = 4; break;
            case '7':           rank = 5; break;
            case '8':           rank = 6; break;
            case '9':           rank = 7; break;
            case 't': case 'T': rank = 8; break;
            case 'j': case 'J': rank = 9; break;
            case 'q': case 'Q': rank = 10; break;
            case 'k': case 'K': rank = 11; break;
            case 'a': case 'A': rank = 12; break;
            default:            bad_card = true;
        }

        suit_ch = getchar();
        switch(suit_ch) {
            case 'c': case 'C': suit = 0; break;
            case 'd': case 'D': suit = 1; break;
            case 'h': case 'H': suit = 2; break;
            case 's': case 'S': suit = 3; break;
            default:            bad_card = true;
        }

        while ((ch = getchar()) != '\n')
        if (ch != ' ') bad_card = true;

        if (bad_card) {
            printf("Bad card; ignored.\n");
        } else {
            // check if card exists
            for (int row = 0; row < 5; row++) {

                if (hand[row][0] == rank && hand[row][1] == suit) {
                        printf("Duplicate card; ignored.\n");
                        break;
                }

                if (hand[row][0] == -1 && hand[row][1] == -1) {
                        hand[row][0] = rank;
                        hand[row][1] = suit;
                        cards_read++;
                        break;
                } 

            }
        }

    }
}

/**********************************************************
 * sort_hand: Uses selection sort to sort a hand in       *
 *            increasing order.                           *
 **********************************************************/
void sort_hand(int hand[5][2]) {
    /* sort cards using selection sort*/
    int i, j, smallest, temp_rank, temp_suit;
    for (i = 0; i < NUM_CARDS; i++) {
        smallest = i;

        for (j = i + 1; j < NUM_CARDS; j++) {
            if (hand[j][0] < hand[smallest][0]) {
                smallest = j;
            }
        }

        temp_rank = hand[i][0];
        temp_suit = hand[i][1];
        hand[i][0] = hand[smallest][0];
        hand[i][1] = hand[smallest][1];
        hand[smallest][0] = temp_rank;
        hand[smallest][1] = temp_suit;
    }
}

/**********************************************************
 * analyze_hand: Determines whether the hand contains a   *
 *               straight, a flush, four-of-a-kind,       *
 *               and/or three-of-a-kind; determines the   *
 *               number of pairs; stores the results into *
 *               the external variables straight, flush,  *
 *               four, three, and pairs.                  *
 **********************************************************/
void analyze_hand(void) {
    int num_consec = 0;
    int rank, suit, card, run;

    straight = false;
    flush = false;
    four = false;
    three = false;
    pairs = 0;    

    sort_hand(hand);

    /* check for flush */
    for (card = 1; card < NUM_CARDS; card++) {
        if (hand[card][1] != hand[0][1]) {
            break;
        } 
        if (card == NUM_CARDS - 1) {
            flush = true;
        }
    }

    /* check for straight */
    for (card = 1; card < NUM_CARDS; card++) {
        if (hand[card][0] - hand[card - 1][0] != 1) {
            break;
        } 
        if (card == NUM_CARDS - 1) {
            straight = true;
        }
    }

    /* check for 4-of-a-kind, 3-of-a-kind, and pairs */
    card = 0;
    while (card < NUM_CARDS) {
        rank = hand[card][0];
        run = 0;
        do {
            run++;
            card++;
        } while (card < NUM_CARDS && hand[card][0] == rank);
        switch (run) {
        case 2: pairs++;      break;
        case 3: three = true; break;
        case 4: four = true;  break;
        }
    } 
    
}

/**********************************************************
 * print_result: Prints the classification of the hand,   *
 *               based on the values of the external      *
 *               variables straight, flush, four, three,  *
 *               and pairs.                               *
 **********************************************************/
void print_result(void) {
    if (straight && flush)  printf("Straight flush");
    else if (four)          printf("Four of a kind");
    else if (three &&
             pairs == 1)    printf("Full house");
    else if (flush)         printf("Flush");
    else if (straight)      printf("Straight");
    else if (three)         printf("Three of a kind");
    else if (pairs == 2)    printf("Two pairs");
    else if (pairs == 1)    printf("Pair");
    else                    printf("High card");

    printf("\n\n");
}