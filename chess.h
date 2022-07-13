#ifndef CHESS_H
#define CHESS_H

#define BOARD_SIZE 64

typedef struct Board {
  int squares[BOARD_SIZE]; /* rank 1 to 8, file A to H. */
  int whitepieces[BOARD_SIZE];
  // TODO: Player turn.
} Board;

Board newBoard();
int loadFen(Board *board);
void printBoard(Board *board);

#endif
