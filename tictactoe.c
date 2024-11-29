#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN (50)

bool game_play = true;
char *ptr;
char strplayer_moves[2][LEN];
char player[2] = "XY";
char pos[9] = {"         "};
int playerMove[2];
int winner = -1;
int i = 0;
int not_up = 0;
int occupied = -1;
int again = -1;

//prints the board.
int drawBoard() 
{

        printf("_____________\n");
        printf("| %c | %c | %c |\n", pos[0], pos[1], pos[2]);
        printf("_____________\n");
        printf("| %c | %c | %c |\n", pos[3], pos[4], pos[5]);
        printf("_____________\n");
        printf("| %c | %c | %c |", pos[6], pos[7], pos[8]);

        return 0;
}
//checks for winner.
int check_win() 
{
        int inc;

        for (int i = 0; i < 2; i++) {
                for (int a = 0; a <= 2; a++) {
                        inc = 3 * a;

                        if ((player[i] == pos[(inc)]) && (player[i] == pos[inc 
                        + 1]) &&
                            (player[i] == pos[inc + 2])) {
                                winner = i + 1;
                                break;
                        }
                }

                for (int a = 0; a < 3; a++) {
                        if ((player[i] == pos[a]) && (player[i] == pos[a + 
                        3]) && (player[i] == pos[a + 6])) {
                                winner = i + 1;
                                break;
                        }
                }

                if (winner == -1) {
                        if ((player[i] == pos[0]) && (player[i] == pos[4]) && 
                        (player[i] == pos[8])) {
                                winner = i + 1;
                                break;
                        }
                        if ((player[i] == pos[2]) && (player[i] == pos[4]) && 
                        (player[i] == pos[6])) {
                                winner = i + 1;
                                break;
                              
                        }
                }
        }

        return winner;
}

//checks for a tie
int check_tie()
{
         
                                if((pos[0]!=' ') && (pos[1]!=' ') && 
                                (pos[2]!=' ')&&(pos[3]!=' ') && 
                                (pos[4]!=' ') && 
                                (pos[5]!=' ')&&(pos[6]!=' ') && 
                                        (pos[7]!=' ') && (
                                        pos[8]!=' ')){
                                        winner=-2;
                                }
                                return 0;
}

//responsible for players' turns to move
int player_movement_handler() 
{
        if (i == 0) {

                printf("\nPlayer One to play.\nSelect a position.\n");
        } else {
                printf("\nPlayer Two to play.\nSelect a position.\n");
        }

        do {

                do {
                        do {
                                scanf("%s", strplayer_moves[i]);
                                not_up = 0;
                                if (!isdigit(strplayer_moves[i][0])) {
                                        printf("Please enter a numerical"
                                        "character "
                                               "from 1 to 9.\n");
                                }

                        } while (!isdigit(strplayer_moves[i][0]));

                        playerMove[i] = strtol(strplayer_moves[i],
                                               &ptr, 10);
                        if (playerMove[i] > 9 || playerMove[i] < 0) {
                                printf("Please enter a number"
                                       "in the range from 1 to 9.\n");
                                not_up = 1;
                        }
                } while (not_up == 1);

                if ((pos[playerMove[i] - 1]) == ' ') {
                        pos[playerMove[i] - 1] = player[i];
                        occupied = 1;
                } else {
                        occupied = -1;
                        printf("Not a free space. Try again\n");
                }
        } while (occupied == -1);
        check_win();
        check_tie();

        return 0;
}
int main() 
{
        drawBoard();
        while (game_play == true) {

                player_movement_handler();
                 if(winner==-2){
                        game_play=false;
                        printf("\nThe game is a tie\n");
                        break;
                }

                if (winner != -1) {
                        printf("Winner is player %d\n", winner);
                        game_play = false;
                        break;
                };
               
                i = abs(i - 1);
                drawBoard();
        }
        drawBoard();

        return 0;
}
