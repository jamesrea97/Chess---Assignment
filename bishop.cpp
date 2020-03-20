#include "bishop.h"
#include "ChessBoard.h"
#include "helper.h"

using namespace std;

/* DEFINITION OF "isValid" */
bool Bishop::isValid(int pos_in[], int pos_out[]) {
  
  /* calculating displacement of bishop */
  abs_x = abs(pos_out[0] - pos_in[0]);
  abs_y = abs(pos_out[1] - pos_in[1]);
  unit_pos[0] = unitDirectionCalc(pos_in[0], pos_out[0]);
  unit_pos[1] = unitDirectionCalc(pos_in[1], pos_out[1]);
  
  /* checking move */
  if (!checkMove()) {
    return false;
  }

  /* checking take a piece from own team */
  if (!ptr_board->sameColourCheck(pos_in, pos_out)) {
    return false;
  }
  
  /* checking jump */
  if (!checkJump(pos_in)) {
    return false;
  }
  
  return true;
}

/* DEFINITION OF "checkMove" */
bool Bishop::checkMove() {

  /* checking actually makes a move */
  if (abs_x == 0 && abs_y == 0) {
    return false;
  }
  /*checking legality of move */
  if (abs_x == abs_y) {
    return true;  
  }
  return false;
}

/* DEFINITION OF "checkJump" */
bool Bishop::checkJump (int pos_in[]) {
  for (int i = 1; i < abs_y; i++) {
    int temp[2];
    temp[0] = pos_in[0] + unit_pos[0] * i;
    temp[1] = pos_in[1] + unit_pos[1] * i;
    if (!ptr_board->isEmptyCheck(temp)) {
      return false;
    }
  }
  return true;
}
