#include <stdio.h>
#include "chess.h"

#define assert(message, test) do { if (!(test)) return message; } while (0)
#define run_test(test) do { char *message = test(); \
                                if (message) return message; } while (0)

static char *testLoadFen() {
  Board board;
  loadFen(&board);
  printBoard(&board);
  return 0;
}

/**
 * Test pawn moves.
 *
 */
static char *testPawn() {
  assert("error, ", 5 == 5);
  return 0;
}

static char *runTests() {
  run_test(testPawn);
  run_test(testLoadFen);
  return 0;
}

int main() {
  printf("RUNNING TESTS.\n");
  char *result = runTests();
  if (result != 0) {
    printf("%s\n", result);
  } else {
    printf("ALL TESTS PASSED\n");
  }

  return result != 0;
}