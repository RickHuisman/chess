#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "chess.h"

int main() {
  Board board = newBoard();
  printBoard(board);
//
//  int *move = translateMove("A2D4");
//
//  validMove(board, WHITE_PLAYER, move);

  // Game loop.
//  for (;;) {
//    printBoard(board);
//
//    char buf[1];
//    printf("Enter move (white): ");
//    scanf("%s", buf);
//
//    int *move = translateMove(buf);
//    if (!validMove(board, move)) {
//      printf("Invalid move!\n");
//    }
//
//    // TODO: Move piece.
//  }

  return 0;
}
