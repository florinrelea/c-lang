#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

char board[3][3];
char PLAYER = 'X';
char OPPONENT = 'O';

char P1[] = "Player 1";
char P2[] = "Player 2";

void resetBoard() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      board[i][j] = ' ';
    }
  }
}

void printBoard() {
  for (int i = 0; i < 3; i++) {
    printf(" %c | %c | %c", board[i][0], board[i][1], board[i][2]);

    if (i < 2) {
      printf("\n---|---|---\n");
    } else if (i == 2) {
      printf("\n");
    }
  }
}

int checkFreeSpaces() {
  int freeSpaces = 9;

    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (board[i][j] != ' ') {
          freeSpaces--;
        }
      }
    }

  return freeSpaces;
}

void playerMove(int playerIndex) {
  char *playerName;
  char playerChar;

  if (playerIndex == 1) {
    playerName = P1;
    playerChar = PLAYER;
  } else {
    playerName = P2;
    playerChar = OPPONENT;
  }

  int x;
  int y;

  do {
    printf("%s:\n", playerName);
    printf("Enter row #(1-3): ");
    scanf("%d", &x);
    x--;

    printf("Enter column #(1-3): ");
    scanf("%d", &y);
    y--;

    if (board[x][y] != ' ') {
      printf("Invalid move \n");
    } else {
      board[x][y] = playerChar;
      break;
    }
  } while (board[x][y] != ' ');

  printf("\n");
}

char checkWinner() {
  // Check rows
  for (int i = 0; i < 3; i++) {
    if (board[i][0] == board[i][1] && board[i][0] == board[i][2]) {
      return board[i][0];
    }
  }

  // Check columns
  for (int i = 0; i < 3; i++) {
    if (board[0][i] == board[1][i] && board[0][i] == board[2][i]) {
      return board[0][i];
    }
  }

  // Check diagonal 1
  if (board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
    return board[0][0];
  }

  // Check diagonal 2
  if (board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
    return board[0][2];
  }

  return ' ';
}

void printWinner();

int main()
{
  char winner = ' ';

  resetBoard();

  while(winner == ' ' && checkFreeSpaces() != 0) {
    printBoard();

    playerMove(1);

    printBoard();

    playerMove(2);

    winner = checkWinner();

    if (winner != ' ' || checkFreeSpaces() == 0) {
      break;
    }
  }

  printf("finished");

  return 0;
}