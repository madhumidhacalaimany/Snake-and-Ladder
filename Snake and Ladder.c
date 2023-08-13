#include <stdio.h>
#include <stdlib.h>

int rd() {
    int rem;
    A: rem = rand() % 7;
    if (rem == 0)
        goto A;
    else
        return rem;
}

void displaychart(int curp1, int curp2) {
    int i, j, t, c, sft = 0, diceres, pos1, pos2;

    if (curp1 == 100 || curp2 == 100) {
        printf("***** Congratulations *****\n\n\n");
        if (curp1 == 100)
            printf("Player 1 wins\n");
        else
            printf("Player 2 wins\n");
        scanf("%*s");
        exit(0);
    }

    for (i = 10; i > 0; i--) {
        t = i - 1;

        if ((sft % 2) == 0) {
            c = 0;
            for (j = 10; j >= 1; j--) {
                diceres = (i * j) + (t * c++);

                if (curp1 == diceres)
                    printf("[P1]\t");  // Player 1 position is marked with [P1]
                else if (curp2 == diceres)
                    printf("[P2]\t");  // Player 2 position is marked with [P2]
                else
                    printf("%-4d\t", diceres);
            }
            sft++;
        } else {
            c = 9;
            for (j = 1; j <= 10; j++) {
                diceres = (i * j) + (t * c--);

                if (curp1 == diceres)
                    printf("[P1]\t");  // Player 1 position is marked with [P1]
                else if (curp2 == diceres)
                    printf("[P2]\t");  // Player 2 position is marked with [P2]
                else
                    printf("%-4d\t", diceres);
            }

            sft++;
        }
        printf("\n\n");
    }

    printf("--------------------------------------------------------------------------\n");
}

void main() {
    int i, dice, cur_pos1 = 0, cur_pos2 = 0;
    char ch;
    while (1) {
        printf(" ** SNAKE AND LADDER GAME** \n");
        printf("Snakes:- 25 to 9,\t 65 to 40,\t 99 to  1.\nLadder:- 13 to 42,\t 60 to 83,\t 70 to 93.\n");
        printf("Choose your option\n");
        printf("1. Player 1 plays\n");
        printf("2. Player 2 plays\n");
        printf("3. Exit\n");
        scanf("%s", &ch);

        switch (ch) {

        case '1':
            dice = rd();
            system("cls");
            printf("\t\t\t\tDice = %d\n\n", dice);
            if (dice == 6)
                printf("Dice=6: You have earned a chance to play one more time.\n");
            cur_pos1 = dice + cur_pos1;
            if (cur_pos1 < 101) {
                if (cur_pos1 == 99) {
                    displaychart(1, cur_pos2);  // snake
                }
                if (cur_pos1 == 65) {
                    displaychart(40, cur_pos2); // snake
                }
                if (cur_pos1 == 25) {
                    displaychart(9, cur_pos2);  // snake
                }
                if (cur_pos1 == 70) {
                    displaychart(93, cur_pos2); // ladder
                }
                if (cur_pos1 == 60) {
                    displaychart(83, cur_pos2); // ladder
                }
                if (cur_pos1 == 13) {
                    displaychart(42, cur_pos2); // ladder
                } else {
                    displaychart(cur_pos1, cur_pos2);
                }

            } else {
                cur_pos1 = cur_pos1 - dice;
                printf("Range exceeded of Player 1.\n");
                displaychart(cur_pos1, cur_pos2);
            }
            printf("Player 2 position is %d\n", cur_pos2);

            break;

        case '2':
            dice = rd();
            system("cls");
            printf("\t\t\t\tDice = %d\n\n", dice);
            cur_pos2 = dice + cur_pos2;
            if (cur_pos2 < 101) {
                if (cur_pos2 == 99) // snake
                {
                    displaychart(cur_pos1, 1);
                }
                if (cur_pos2 == 65) // snake
                {
                    displaychart(cur_pos1, 40);
                }
                if (cur_pos2 == 25) // snake
                {
                    displaychart(cur_pos1, 9);
                }
                if (cur_pos2 == 70) // ladder
                {
                    displaychart(cur_pos1, 93);
                }
                if (cur_pos2 == 60) // ladder
                {
                    displaychart(cur_pos1, 83);
                }
                if (cur_pos2 == 13) // ladder
                {
                    displaychart(cur_pos1, 42);
                } else {
                    displaychart(cur_pos1, cur_pos2);
                }
            } else {
                cur_pos2 = cur_pos2 - dice;
                printf("Range exceeded of Player 2.\n");
                displaychart(cur_pos1, cur_pos2);
            }
            printf("Player 1 position is %d\n", cur_pos1);
            break;

        case '3':
            exit(0);
            break;

        default:
            printf("Incorrect choice. Try Again\n");
        }
    }
}