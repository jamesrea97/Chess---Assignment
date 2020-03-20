#include "king.h"
#include "ChessBoard.h"

using namespace std;

/* DEFINITION OF "isValid" */
bool King::isValid(int pos_in[], int pos_out[]) {

  /* calculating displacement of rook */
  abs_x = abs(pos_out[0] - pos_in[0]);
  abs_y = abs(pos_out[1] - pos_in[1]);

  /* checking move */
  if (!checkMove()) {
    return false;
  }

  /* checking take a piece from own team */
  if (!ptr_board->sameColourCheck(pos_in, pos_out)) {
    return false;
  }
  
  return true;
}

/* DEFINITION OF "checkMove" */
bool King::checkMove() {
  /*checks actually makes a move */
  if (abs_x == 0 && abs_y == 0) {
    return false;
  }
  /*checks legality of move */
  if (abs_x > 1 || abs_y > 1) {
    return false;
  }
  return true;
}

