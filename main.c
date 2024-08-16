#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


char board[3][3];

int x;
int y;

const char PLAYER = 'X';
const char COMPUTER = 'O';

char winner;
char again;

void newBoard();
void displayBoard();
void playAgain();

int emptySpaces();

void playerPlay();
void computerPlay();

void checkWinner();
void checkDraw();


//              notes:

//                   1. draw does not work 
//                     ^- now works

//                   2. winning before computer by one turn does not work
//                     ^- should be fixed   


int main()
{   

    srand(time(NULL));
    
    again = ' ';

    newBoard();
    displayBoard();


    while (winner == ' ') 
    {

        playerPlay();
        checkWinner();

        computerPlay();    
        checkWinner();

    }
}



// prompts the player to play again
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
            exit(0);
        }
        

    }
    
}


// initialises the variables for a new board 
void newBoard() {
    winner = ' ';
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {

            board[i][j] = ' ';
        }
    }

}


// Renders the board
void displayBoard() {

    printf("\n");
    printf("   1   2   3 \n");
    printf("1  %c | %c | %c \n", board[0][0], board[1][0], board[2][0]);
    printf("  ---+---+---\n");
    printf("2  %c | %c | %c \n", board[0][1], board[1][1], board[2][1]);
    printf("  ---+---+---\n");
    printf("3  %c | %c | %c \n", board[0][2], board[1][2], board[2][2]);
    printf("\n");
    
}

// returns how many empty spaces are on the board
int emptySpaces() {

    int empty_spaces = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {

            if (board[i][j] == ' ') {
                empty_spaces++;
            }
        }
    }
    //printf("\n%i\n", empty_spaces);

    return empty_spaces;

}

// prompts the player to play
void playerPlay() {
    
    if (emptySpaces() > 0) {
        
        do {
        printf("Enter column index (1-3): ");
        scanf("%d", &x);
        printf("\nEnter row index (1-3): ");
        scanf("%d", &y);
        x--;
        y--;

        if (board[x][y] != ' ' || 1 > (x + 1) || (x + 1) > 3  || 1 > (y + 1) || (y + 1) > 3) 
        {
            displayBoard();
            printf("Can't play here.\n");
            continue;
        }

        } while (board[x][y] != ' ' || 1 > (x + 1) || (x + 1) > 3  || 1 > (y + 1) || (y + 1) > 3);


        board[x][y] = PLAYER;
        //displayBoard();
    }

}


// lets the computer play
void computerPlay() {

    if (emptySpaces() > 0 && winner == ' ') {
    
        int cx;
        int cy;


        do {
            cx = rand() % 3;
            cy = rand() % 3;

        } while (board[cx][cy] != ' ');

        board[cx][cy] = COMPUTER;


        displayBoard();

    } 

}

// checks if a there is a win or a draw
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
        displayBoard();
        printf("\nThe winner is %c\n", winner);
        playAgain();
    }

    checkDraw();
    

}

void checkDraw() 
{
    if (emptySpaces() <= 0 && winner == ' ') {
        displayBoard();
        printf("\nIt is a draw\n");
        playAgain();
    }
}