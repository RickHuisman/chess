#include <stdio.h>
#include <ctype.h>

#define BOARD_SIZE 64

#define EMPTY_SQUARE 0

#define ROOK 1
#define KNIGHT 2
#define BISHOP 3
#define PAWN 4
#define KING 5
#define QUEEN 6

typedef struct Board {
  int squares[BOARD_SIZE];
  int whitepieces[BOARD_SIZE];
} Board;

Board newBoard() {
  Board board;

  // White
  board.squares[0] = ROOK;
  board.squares[1] = KNIGHT;
  board.squares[2] = BISHOP;
  board.squares[3] = KING;
  board.squares[4] = QUEEN;
  board.squares[5] = BISHOP;
  board.squares[6] = KNIGHT;
  board.squares[7] = ROOK;

  for (int i = 8; i < 16; ++i) {
    board.squares[i] = PAWN;
  }

  // Initialize the white pieces.
  for (int i = 0; i < BOARD_SIZE; ++i) {
    board.whitepieces[i] = 0;
  }

  // Set white pieces.
  for (int i = 0; i < 16; ++i) {
    board.whitepieces[i] = 1;
  }

  // Empty squares.
  for (int i = 16; i < 48; ++i) {
    board.squares[i] = EMPTY_SQUARE;
  }

  // Black.
  for (int i = 48; i < 56; ++i) {
    board.squares[i] = PAWN;
  }

  board.squares[56] = ROOK;
  board.squares[57] = KNIGHT;
  board.squares[58] = BISHOP;
  board.squares[59] = KING;
  board.squares[60] = QUEEN;
  board.squares[61] = BISHOP;
  board.squares[62] = KNIGHT;
  board.squares[63] = ROOK;

  return board;
}

int isWhitePiece(Board board, int square) {
  return board.whitepieces[square];
}

void printPiece(char piece, int isWhitePiece, int square) {
  if (isWhitePiece) {
    printf("%c", piece);
    return;
  }

  printf("%c", toupper(piece));
}

void printBoard(Board board) {
  for (int i = 0; i < BOARD_SIZE; ++i) {
    int square = board.squares[i];
    int whitePiece = isWhitePiece(board, i);

    if ((i % 8) == 0 && i != 0) {
      printf("\n");
    }

    switch (square) {
      case EMPTY_SQUARE:
        printf("•");
        break;
      case ROOK:
        printPiece('r', whitePiece, square);
        break;
      case KNIGHT:
        printPiece('k', whitePiece, square);
        break;
      case BISHOP:
        printPiece('b', whitePiece, square);
        break;
      case KING:
        printPiece('k', whitePiece, square);
        break;
      case QUEEN:
        printPiece('q', whitePiece, square);
        break;
      case PAWN:
        printPiece('p', whitePiece, square);
        break;
      default:
        printf("ERROR: Unknown piece: %d", square);
    }
  }
}

int main() {
  Board board = newBoard();
  printBoard(board);
  return 0;
}
