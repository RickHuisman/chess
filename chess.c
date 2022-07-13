#include "chess.h"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define EMPTY_SQUARE 0

#define ROOK 1
#define KNIGHT 2
#define BISHOP 3
#define PAWN 4
#define KING 5
#define QUEEN 6

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

struct abuf {
  char *b[10];
  unsigned len;
};

//static void abAppend(struct abuf *a, const char c) {
//  a->b[a->len] = c;
//  ++a->len;
//}

/*
 * Return: TODO.
 */
int loadFen(Board *board) {
  char example[50] = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR";

  char *splits[50];
  char *token = strtok(example, "/");
  size_t count = 0;
  while (token != NULL) {
    splits[count] = token;

    token = strtok(NULL, "/");
    ++count;
  }

  // Initialize board with empty squares.
  for (int i = 0; i < BOARD_SIZE; ++i) {
    board->squares[i] = EMPTY_SQUARE;
  }

  // Initialize white pieces board with zero's.
  for (int i = 0; i < BOARD_SIZE; ++i) {
    board->whitepieces[i] = 0;
  }

  // Fill board.
  for (int r = 0; r < count; ++r) {
     char *row = splits[r];

    // Loop over split.
    for (int i = 0; i < strlen(row); ++i) {
      char c = row[i];
      if (isalpha(c)) {
        size_t pos = (r * 8) + i;

        // Add piece.
        switch (c) {
          case 'r':
          case 'R':
            board->squares[pos] = ROOK;
            break;
          case 'n':
          case 'N':
            board->squares[pos] = KNIGHT;
            break;
          case 'b':
          case 'B':
            board->squares[pos] = BISHOP;
            break;
          case 'k':
          case 'K':
            board->squares[pos] = KING;
            break;
          case 'q':
          case 'Q':
            board->squares[pos] = QUEEN;
            break;
          case 'p':
          case 'P':
            board->squares[pos] = PAWN;
            break;
        }

        // Add positions of white pieces.
        if (isupper(c)) {
          board->whitepieces[pos] = 1;
        }
      }
    }
  }

  return 0;
}

/* Check if a square is occupied by a white piece. */
int isWhitePiece(Board *board, int square) {
  return board->whitepieces[square];
}

void printPiece(char piece, int isWhitePiece) {
  if (!isWhitePiece) piece = toupper(piece);
  printf("%c ", piece);
}

void printBoard(Board *board) {
  for (int i = BOARD_SIZE - 1; i >= 0; --i) {
    int square = board->squares[i];
    int whitePiece = isWhitePiece(board, i);

    if (((i + 1) % 8) == 0) {
      printf("\n");
    }

    switch (square) {
      case EMPTY_SQUARE:
        printf("• ");
        break;
      case ROOK:
        printPiece('r', whitePiece);
        break;
      case KNIGHT:
        printPiece('k', whitePiece);
        break;
      case BISHOP:
        printPiece('b', whitePiece);
        break;
      case KING:
        printPiece('k', whitePiece);
        break;
      case QUEEN:
        printPiece('q', whitePiece);
        break;
      case PAWN:
        printPiece('p', whitePiece);
        break;
      default:
        printf("ERROR: Unknown piece: %d", square);
        break;
    }
  }

  printf("\n\n");
}

int validMove(Board board, int player, const int *move) {
  int origin = move[0];
  int dest = move[1];

  // No piece selected.
  if (board.squares[origin] == 0) return 0;

  // Origin is the same as destination.
  if (origin == dest) return 0;

  // TODO: Check if player is moving his own piece.

  int piece = board.squares[origin];
  switch (piece) {
    case PAWN:
      // TODO: Promote piece.

      // TODO:

      printf("Pawn to %d", dest);
      break;
    default:
      printf("TODO\n");
  }

  return 0;
}

/* Returns an array of ints, containing: [origin, destination] */
int *translateMove(char *buf) {
  // Translate origin.
  int foobar = 8 - (buf[0] - 64);
  int foobar2 = (buf[1] - '0') * 8;
  int origin = foobar2 - foobar;

  // Translate destination.
  int foobar3 = 8 - (buf[2] - 64);
  int foobar4 = (buf[3] - '0') * 8;
  int dest = foobar4 - foobar3;

  int *move = malloc(2 * sizeof(int));
  move[0] = origin;
  move[1] = dest;
  return move;
}