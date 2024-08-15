#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


char board[3][3];

int x;
int y;
int empty_spaces;

const char PLAYER = 'X';
const char COMPUTER = 'O';

char winner;
char again;

void newBoard();
void displayBoard();
void playAgain();

void checkEmptySpaces();

void playerPlay();
void computerPlay();

void checkWinner();

//                                notes:    1. draw does not work
//                                          2. winning before computer by one turn does not work   

int main()
{   

    srand(time(NULL));
    
    again = ' ';

    newBoard();
    displayBoard();


    while (winner == ' ') {
        playerPlay();

        computerPlay();

        checkWinner();

        if (empty_spaces <= 0) {
            displayBoard();
            printf("\nIt is a draw\n");
            playAgain();
    }
    

    }
    /*    if (checkEmptySpaces() == 0) {
        displayBoard();
        playAgain();
    } */


}


void playAgain() {

    printf("play again? (y/n) ");
    while (again != 'y' && again != 'n') {


        scanf("%c", &again);

        if (again == 'y') {
            printf("\n");
            main();
        }

        if (again == 'n') {
            printf("\n");
            break;
        }

    }
    
}


void newBoard() {
    empty_spaces = 9;
    winner = ' ';
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {

            board[i][j] = ' ';
        }
    }
}

void displayBoard() {

    printf("   1   2   3 \n");
    printf("1  %c | %c | %c \n", board[0][0], board[1][0], board[2][0]);
    printf("  ---|---|---\n");
    printf("2  %c | %c | %c \n", board[0][1], board[1][1], board[2][1]);
    printf("  ---|---|---\n");
    printf("3  %c | %c | %c \n", board[0][2], board[1][2], board[2][2]);
    
}

void checkEmptySpaces() {

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {

            if (board[i][j] != ' ') {
                if (empty_spaces != 0) {
                    empty_spaces--;
                }
            }
        }
    }

}


void playerPlay() {
    
    
    do {
    printf("Enter column index (1-3): ");
    scanf("%d", &x);
    printf("\nEnter row index (1-3): ");
    scanf("%d", &y);
    printf("\n");
    x--;
    y--;

    if (board[x][y] != ' ') {
        displayBoard();
        printf("Can't play here.\n");
        continue;
    }

    } while (board[x][y] != ' ');
    

    board[x][y] = PLAYER;
}



void computerPlay() {
    
    int cx;
    int cy;


    do {
        cx = rand() % 3;
        cy = rand() % 3;

    } while (board[cx][cy] != ' ');

    board[cx][cy] = COMPUTER;

    displayBoard();
}

void checkWinner() {

    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2]) {
            if (board[i][0] != ' ') {
                winner = board[i][0];

            }
        }

        if (board[0][i] == board[1][i] && board[0][i] == board[2][i]) {
            if (board[0][i] != ' ') {
                winner = board[0][i];

            }
        }

    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        if (board[0][0] != ' ') {
            winner = board[0][0];

        }
    }

    if (board[2][0] == board[1][1] && board[2][0] == board[0][2]) {
        if (board[2][0] != ' ') {
            winner = board[2][0];

        }
    }

    if (winner != ' ') {
        printf("\nThe winner is %c\n", winner);
        playAgain();
    }


    

}