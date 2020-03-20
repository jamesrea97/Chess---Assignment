#include <iostream>
#include "knight.h"
#include "ChessBoard.h"

using namespace std;

/* DEFINITION OF "isValid" */
bool Knight::isValid(int pos_in[], int pos_out[]) {

  /* calculating displacement of knight */
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
bool Knight::checkMove() {
  
  /* checking makes a move */
  if (abs_x == 0 && abs_y == 0 ) {
    return false;
  }
  
  /* checking legality of move */
  // exactly 3 displacement
  if (abs_x + abs_y != 3) {
    return false;
  }
  //must be 'L' shape
  if(abs_x == 0 || abs_y == 0) {
    return false;
  }
  
  return true;
}
