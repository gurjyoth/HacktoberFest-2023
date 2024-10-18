/* Tic Tac Toe Game */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define SIZE 3 // Size of the Tic Tac Toe grid
#define PLAYERS 2 // Number of players

char players[PLAYERS] = {'X', 'O'};
char board[SIZE][SIZE] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

// Function to print the board
void printBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < SIZE - 1) printf("|");
        }
        printf("\n");
        if (i < SIZE - 1) printf("---|---|---\n");
    }
}

// Function to check if the current player has won
bool checkWin() {
    for (int i = 0; i < SIZE; i++) {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) || 
            (board[0][i] == board[1][i] && board[1][i] == board[2][i])) {
            return true;
        }
    }
    return (board[0][0] == board[1][1] && board[1][1] == board[2][2]) || 
           (board[0][2] == board[1][1] && board[1][1] == board[2][0]);
}

// Function to update the board
bool makeMove(int move, char player) {
    int row = (move - 1) / SIZE;
    int col = (move - 1) % SIZE;
    if (board[row][col] == 'X' || board[row][col] == 'O') {
        return false; // Spot already taken
    }
    board[row][col] = player;
    return true;
}

// Function to run the game
void playGame() {
    int round = 0;
    int move;
    char currentPlayer;
    srand(time(NULL));

    while (round < SIZE * SIZE) {
        currentPlayer = players[round % PLAYERS];
        printBoard();
        printf("Player %c, enter your move (1-9): ", currentPlayer);
        scanf("%d", &move);

        if (move >= 1 && move <= 9 && makeMove(move, currentPlayer)) {
            round++;
            if (checkWin()) {
                printBoard();
                printf("Player %c wins!\n", currentPlayer);
                return;
            }
        } else {
            printf("Invalid move, try again.\n");
        }
    }
    printf("It's a draw!\n");
}

int main() {
    playGame();
    return 0;
}
